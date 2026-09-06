#include "global.h"
#include "assertf.h"
#include "comfy_anim.h"
#include "constants/characters.h"
#include "constants/field_weather.h"
#include "even_sprite.h"
#include "field_weather.h"
#include "fpmath.h"
#include "gba/io_reg.h"
#include "gba/isagbprint.h"
#include "gba/types.h"
#include "gba/defines.h"
#include "international_string_util.h"
#include "intro.h"
#include "main.h"
#include "bg.h"
#include "main_menu.h"
#include "custom_main_menu.h"
#include "rtc.h"
#include "save.h"
#include "script.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "custom_title.h"
#include "subsprite.h"
#include "m4a.h"
#include <string.h>

struct CustomCreditsState
{
    MainCallback savedCallback;
    u8 loadState;
    u16 scrollOffset;
};

static EWRAM_DATA struct CustomCreditsState *sCustomCreditsState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sCustomCreditsBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

enum {
    WIN_CREDITS_MAIN,
    WIN_CREDITS_COUNT
};

static const struct WindowTemplate sCustomCreditsWinTemplates[] = {
    [WIN_CREDITS_MAIN] =
        {
            .tilemapLeft = 5,
            .tilemapTop = 0,
            .bg = 0,
            .height = 32,
            .width = 20,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    DUMMY_WIN_TEMPLATE,
};

static const u32 CmmScrollingBgTiles[] = INCGFX_U32("graphics/custom_main_menu/scrolling_bg/tiles.png", ".4bpp.smol");
static const u32 CmmScrollingBgTilemap[] = INCBIN_U32("graphics/custom_main_menu/scrolling_bg/map.bin.smolTM");
static const u16 CmmScrollingBgPalette[] = INCGFX_U16("graphics/custom_main_menu/scrolling_bg/palette_01.pal", ".gbapal");

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sCustomCreditsWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED,        TEXT_COLOR_RED},
};

// Callbacks for the Credits Screen
static void CustomCredits_SetupCB(void);
static void CustomCredits_MainCB(void);
static void CustomCredits_VBlankCB(void);

//Custom Credits tasks
static void Task_CustomCreditsWaitFadeIn(u8 taskId);
static void Task_CustomCreditsMainInput(u8 taskId);
static void Task_CustomCreditsWaitFadeAndBail(u8 taskId);
static void Task_CustomCreditsWaitFadeAndExitGracefully(u8 taskId);
static void Task_ScrollCredits(u8 taskId);

//Custom Credits helper functions
static void CustomCredits_Init(MainCallback callback);
static void CustomCredits_ResetGpuRegsAndBgs(void);
static bool8 CustomCredits_InitBgs(void);
static void CustomCredits_FadeAndBail(void);
static bool8 CustomCredits_LoadGraphics(void);
static void CustomCredits_FreeResources(void);
static void CustomCredits_InitWindows(void);
static void Task_CustomCreditsScrollBg(u8 taskId);

static void CB2_GoToMainMenu(void)
{
    MainCallback cb;

    bool8 isBatteryOk = !(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK);

    if ((gSaveFileStatus == SAVE_STATUS_OK ||
         gSaveFileStatus == SAVE_STATUS_EMPTY) &&
        isBatteryOk) {
        cb = CB2_InitCustomMainMenu;
    }
    else {
        cb = CB2_InitPrecheckScreen;
    }
    if (!UpdatePaletteFade())
        SetMainCallback2(cb);
}

void CB2_InitCustomCreditsScreen(void)
{
    FadeOutBGM(2);
    FadeScreen(FADE_TO_BLACK, 0);
    CustomCredits_Init(CB2_GoToMainMenu);
}

static void CustomCredits_Init(MainCallback callback)
{
    sCustomCreditsState = AllocZeroed(sizeof(struct CustomCreditsState));
    if (sCustomCreditsState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sCustomCreditsState->loadState = 0;
    sCustomCreditsState->savedCallback = callback;

    SetMainCallback2(CustomCredits_SetupCB);
}

void CB2_OpenCustomCredits(void)
{
    switch (gMain.state)
    {
    case 0:
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    case 1:
        CB2_InitCustomCreditsScreen();
        gMain.state++;
        break;
    default:
        break;
    }
}

static void CustomCredits_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    CpuFill16(0, (void*)VRAM, VRAM_SIZE);
    CpuFill32(0, (void*)OAM, OAM_SIZE);
}

static void CustomCredits_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        CustomCredits_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (CustomCredits_InitBgs())
        {
            sCustomCreditsState->loadState = 0;
            gMain.state++;
        }
        else
        {
            CustomCredits_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (CustomCredits_LoadGraphics())
        {
            gMain.state++;
        }
        break;
    case 4:
        CustomCredits_InitWindows();
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_BLACK);
        CreateTask(Task_CustomCreditsScrollBg, 0);
        gMain.state++;
        break;
    case 6:
        ShowBg(1);
        CreateTask(Task_CustomCreditsWaitFadeIn, 0);
        PlayNewMapMusic(MUS_CVAOS_DRACULASFATE);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(CustomCredits_VBlankCB);
        SetMainCallback2(CustomCredits_MainCB);
        break;
    }
}

static void CustomCredits_MainCB(void)
{
    RunTasks();
    AdvanceComfyAnimations();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void CustomCredits_VBlankCB(void)
{
    LoadOam();
    ScanlineEffect_InitHBlankDmaTransfer();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_CustomCreditsWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        TASK_DATA(scrollOffset, countDown);
        tData->countDown = -1;
        gTasks[taskId].func = Task_ScrollCredits;
        CreateTask(Task_CustomCreditsMainInput, 0);
    }
}

static void Task_CustomCreditsMainInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGM(2);
        FadeScreen(FADE_TO_BLACK, 0);
        DestroyTask(FindTaskIdByFunc(Task_ScrollCredits));
        gTasks[taskId].func = Task_CustomCreditsWaitFadeAndExitGracefully;
    }
}

static void Task_CustomCreditsWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomCreditsState->savedCallback);
        CustomCredits_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_CustomCreditsWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomCreditsState->savedCallback);
        CustomCredits_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 CustomCredits_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sCustomCreditsBgTemplates, NELEMS(sCustomCreditsBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void CustomCredits_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_CustomCreditsWaitFadeAndBail, 0);
    SetVBlankCallback(CustomCredits_VBlankCB);
    SetMainCallback2(CustomCredits_MainCB);
}

static bool8 CustomCredits_LoadGraphics(void)
{
    switch (sCustomCreditsState->loadState)
    {
    case 0:
        DecompressAndLoadBgGfxUsingHeap(1, CmmScrollingBgTiles, 0, 0, 0);
        sCustomCreditsState->loadState++;
        break;
    case 1:
        DecompressAndCopyToBgTilemapBuffer(1, CmmScrollingBgTilemap, BG_SCREEN_SIZE, 0);
        sCustomCreditsState->loadState++;
        break;
    case 2:
        LoadPalette(CmmScrollingBgPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sCustomCreditsState->loadState++;
    default:
        sCustomCreditsState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void CustomCredits_InitWindows()
{
    InitWindows(sCustomCreditsWinTemplates);

    u32 windowId = 0;
    SetWindowAttribute(windowId, WINDOW_BASE_BLOCK, 1);
    while (GetWindowAttribute(windowId, WINDOW_BG) != 0xFF) { 
        u32 b = GetWindowAttribute(windowId, WINDOW_BASE_BLOCK);
        u32 w = GetWindowAttribute(windowId, WINDOW_WIDTH);
        u32 h = GetWindowAttribute(windowId, WINDOW_HEIGHT);
        SetWindowAttribute(++windowId, WINDOW_BASE_BLOCK, b+h*w);
    }
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WIN_CREDITS_MAIN, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    for (int i = 0; i < WIN_CREDITS_COUNT; i++)
    {
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

#define CREDIT_ENTRY_NUM 100

struct CreditEntry {
    const u8* creditText;
    bool32 isHeader;
};

#define CREDITS_ENTRY(a,...) {COMPOUND_STRING(a) __VA_OPT__(,__VA_ARGS__)}
#define CREDIT_NULL {0, 0}

#include "data/credits_list.h"

static void CustomCredits_PrintLine(struct CreditEntry entry)
{
    u32 winPixelWidth = GetWindowAttribute(WIN_CREDITS_MAIN, WINDOW_WIDTH) * 8;
    u32 y = Q_8_8_TO_INT(GetBgY(0)) % 512;
    u8 yMultiplier = 16;
    u32 yPos = (DISPLAY_HEIGHT + y + 1) % 256;

    FillWindowPixelRect(WIN_CREDITS_MAIN, PIXEL_FILL(TEXT_COLOR_TRANSPARENT), 0, yPos, winPixelWidth, yMultiplier);

    if (entry.creditText == 0)
    {
        CopyWindowToVram(WIN_CREDITS_MAIN, COPYWIN_GFX);
        return;
    }

    u32 fontId = entry.isHeader ? FONT_NORMAL : FONT_SMALL_NARROWER;
    const u8* color = entry.isHeader ? sCustomCreditsWindowFontColors[FONT_RED] : sCustomCreditsWindowFontColors[FONT_WHITE];
    u32 x = GetStringCenterAlignXOffset(fontId, entry.creditText, GetWindowAttribute(WIN_CREDITS_MAIN, WINDOW_WIDTH) * 8);
    AddTextPrinterParameterized4(WIN_CREDITS_MAIN, fontId, x, yPos, 0, 0, color, TEXT_SKIP_DRAW, entry.creditText);

    CopyWindowToVram(WIN_CREDITS_MAIN, COPYWIN_GFX);
    sCustomCreditsState->scrollOffset++;
}

static void Task_ScrollCredits(u8 taskId)
{
    TASK_DATA(scrollOffset, countDown);
    u32 yMultiplier = Q_8_8(16);

    bool32 isCreditsOver =
        !gCreditStrings[sCustomCreditsState->scrollOffset].creditText;

    bool32 isCountDownActive = tData->countDown > 0;

    tData->scrollOffset += Q_8_8(0.5);

    if (tData->scrollOffset >= yMultiplier)
    {
        if (isCreditsOver && !isCountDownActive)
        {
            tData->countDown = 16;
        }

        tData->scrollOffset -= yMultiplier;
        CustomCredits_PrintLine(gCreditStrings[sCustomCreditsState->scrollOffset]);

        if (tData->countDown > 0)
            tData->countDown--;

        if (tData->countDown == 0)
        {
            FadeScreen(FADE_TO_BLACK, 1);
            gTasks[taskId].func = Task_CustomCreditsWaitFadeAndExitGracefully;
        }
    }

    ChangeBgY(0, Q_8_8(0.5), BG_COORD_ADD);
}

static void Task_CustomCreditsScrollBg(u8 taskId)
{
    ChangeBgY(1, Q_8_8(0.4), BG_COORD_SUB);
}

static void CustomCredits_FreeResources(void)
{
    if (sCustomCreditsState != NULL)
    {
        Free(sCustomCreditsState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }

    FreeAllWindowBuffers();
    ResetSpriteData();
}

bool32 ScrCmd_showcredits(struct ScriptContext* ctx)
{
    MainCallback cb = (MainCallback)ScriptReadWord(ctx);
    FadeOutBGM(2);
    FadeScreen(FADE_TO_BLACK, 0);
    CustomCredits_Init(cb);
    return FALSE;
}
