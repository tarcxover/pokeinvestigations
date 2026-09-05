#include "global.h"
#include "comfy_anim.h"
#include "constants/field_weather.h"
#include "even_sprite.h"
#include "field_weather.h"
#include "fpmath.h"
#include "gba/io_reg.h"
#include "gba/isagbprint.h"
#include "gba/types.h"
#include "gba/defines.h"
#include "intro.h"
#include "main.h"
#include "bg.h"
#include "main_menu.h"
#include "custom_main_menu.h"
#include "rtc.h"
#include "save.h"
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

#define TITLE_TEXT_INITIAL_OFFSET 101
#define TITLE_SCREEN_DELAY 60
#define STEP_FRAME_DURATION 36

typedef struct
{
    u16 frameCounter;
    u16 spriteOffset;
} ShipBobState;

struct CustomTitleState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 shipId;
    ShipBobState shipBob;
    bool8 skipIntro;
};

static EWRAM_DATA struct CustomTitleState *sCustomTitleState = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;

static const struct BgTemplate sCustomTitleBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .priority = 0
    }
};

static const u32 sCustomTitleTiles[] = INCBIN_U32("graphics/custom_title/night/tiles.4bpp.smol");
static const u32 sCustomTitleTilemap[] = INCBIN_U32("graphics/custom_title/night/map.bin.smolTM");
static const u16 sCustomTitlePalette[] = INCBIN_U16("graphics/custom_title/night/palette_00.gbapal", "graphics/custom_title/night/palette_01.gbapal");

static const u32 sCustomTitleTextTiles[] = INCBIN_U32("graphics/custom_title/text/tiles.4bpp.smol");
static const u32 sCustomTitleTextTilemap[] = INCBIN_U32("graphics/custom_title/text/map.bin.smolTM");
static const u16 sCustomTitleTextPalette[] = INCBIN_U16("graphics/custom_title/text/palette_02.gbapal");

static const u32 sCustomTitleSubtitleTiles[] = INCBIN_U32("graphics/custom_title/text/subtitle/tiles.4bpp.smol");
static const u32 sCustomTitleSubtitleTilemap[] = INCBIN_U32("graphics/custom_title/text/subtitle/map.bin.smolTM");
static const u16 sCustomTitleSubtitlePalette[] = INCBIN_U16("graphics/custom_title/text/palette_02.gbapal");


static const u32 sCustomTitleShipGfx[] = INCGFX_U32("graphics/custom_title/ship.png", ".4bpp", "-mwidth 8 -mheight 4");
static const u16 sCustomTitleShipPal[] = INCGFX_U16("graphics/custom_title/ship.png", ".gbapal");

static struct SpriteFrameImage sCustomTitleShipFrames;

const struct Subsprite sCustomTitleShipSubsprites[] = {
    SUBSPRITE(-32, -16,   64x32, 0,   2),
    SUBSPRITE( 32, -16,   64x32, 32,  2),
    SUBSPRITE(-32,  16,   64x32, 64,  2),
    SUBSPRITE( 32,  16,   64x32, 96,  2),
};

const struct SubspriteTable sCustomTitleShipSubspriteTable[] = {
    SUBSPRITE_TABLE_ENTRY(sCustomTitleShipSubsprites),
};

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sCustomTitleWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the Title Screen
static void CustomTitle_SetupCB(void);
static void CustomTitle_MainCB(void);
static void CustomTitle_VBlankCB(void);

//Custom Title tasks
static void Task_CustomTitleWaitFadeIn(u8 taskId);
static void Task_CustomTitleMainInput(u8 taskId);
static void Task_CustomTitleScreenMoveText(u8 taskId);
static void Task_CustomTitleWaitFadeAndBail(u8 taskId);
static void Task_CustomTitleWaitFadeAndExitGracefully(u8 taskId);
static void Task_CustomTitleScreenFadeSubtitle(u8 taskId);
static void Task_CustomTitleCheckForSkip(u8 taskId);

//Custom Title helper functions
static void CustomTitle_Init(MainCallback callback);
static void CustomTitle_ResetGpuRegsAndBgs(void);
static bool8 CustomTitle_InitBgs(void);
static void CustomTitle_FadeAndBail(void);
static bool8 CustomTitle_LoadGraphics(void);
static void CustomTitle_FreeResources(void);
static u32 CustomTitle_CreateShipSprite();
static void SpriteCB_HandleShipBob(struct Sprite *sprite);

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

void CB2_InitCustomTitleScreen(void)
{
    FadeOutBGM(2);
    FadeScreen(FADE_TO_BLACK, 0);
    CustomTitle_Init(CB2_GoToMainMenu);
}

static void CustomTitle_Init(MainCallback callback)
{
    sCustomTitleState = AllocZeroed(sizeof(struct CustomTitleState));
    if (sCustomTitleState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sCustomTitleState->loadState = 0;
    sCustomTitleState->savedCallback = callback;

    SetMainCallback2(CustomTitle_SetupCB);
}

static void CustomTitle_ResetGpuRegsAndBgs(void)
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
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT - 32, DISPLAY_HEIGHT));
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(71, 95));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL & ~WININ_WIN0_BG0);
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN1_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL & ~ WINOUT_WIN01_BG2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    CpuFill16(0, (void*)VRAM, VRAM_SIZE);
    CpuFill32(0, (void*)OAM, OAM_SIZE);
}

static u32 SkipComfyAnimEasing(struct ComfyAnim* anim)
{
    auto endVal = anim->config.data.easing.to;
    anim->completed = TRUE;
    return Q_24_8_TO_INT(endVal);
}

static u32 CheckSkipAndReadComfyAnim(struct ComfyAnim* anim, bool32 skip)
{
    if (skip)
        return SkipComfyAnimEasing(anim);
    else
        return ReadComfyAnimValueSmooth(anim);
}

static u32 CustomTitle_InitSubtitleFadeAnim()
{
    struct ComfyAnimEasingConfig config;
    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(0);
    config.to = Q_24_8(16);
    config.durationFrames = 75;
    config.easingFunc = ComfyAnimEasing_EaseInCubic;
    return CreateComfyAnim_Easing(&config);
}

static u32 CustomTitle_InitMoveTextAnim()
{
    struct ComfyAnimEasingConfig config;
    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(TITLE_TEXT_INITIAL_OFFSET);
    config.to = Q_24_8(0);
    config.durationFrames = 90;
    config.easingFunc = ComfyAnimEasing_EaseInOutBack;
    return CreateComfyAnim_Easing(&config);
}

static u32 CustomTitle_InitWindowAnim()
{
    struct ComfyAnimEasingConfig config;
    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(0);
    config.to = Q_24_8(57);
    config.durationFrames = 75;
    config.easingFunc = ComfyAnimEasing_EaseInCubic;
    return CreateComfyAnim_Easing(&config);
}

static void CustomTitle_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        CustomTitle_ResetGpuRegsAndBgs();
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
        if (CustomTitle_InitBgs())
        {
            sCustomTitleState->loadState = 0;
            gMain.state++;
        }
        else
        {
            CustomTitle_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (CustomTitle_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        ChangeBgY(0, Q_8_8(102), BG_COORD_SET);
        u32 shipId = CustomTitle_CreateShipSprite();
        struct Sprite* ship = &gSprites[shipId];
        sCustomTitleState->shipId = shipId;
        ship->x += 64;
        ship->y += 16;
        gMain.state++;
        break;
    case 5:
        ScanlineEffect_InitWave(0, 92, 2, 3, 0, SCANLINE_EFFECT_REG_BG1HOFS, FALSE);
        ScanlineEffect_InitScroll(92, DISPLAY_HEIGHT, 3, -1, 0, SCANLINE_EFFECT_REG_BG1HOFS, FALSE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_CustomTitleWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        m4aSongNumStartOrChange(MUS_CVAOS_DRACULASFATE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(CustomTitle_VBlankCB);
        SetMainCallback2(CustomTitle_MainCB);
        break;
    }
}

static void CustomTitle_MainCB(void)
{
    RunTasks();
    AdvanceComfyAnimations();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void CustomTitle_VBlankCB(void)
{
    LoadOam();
    ScanlineEffect_InitHBlankDmaTransfer();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_CustomTitleWaitFadeIn(u8 taskId)
{
    TASK_DATA(waitFrames);

    if (!gPaletteFade.active)
    {
        if (sCustomTitleState->skipIntro || ++tData->waitFrames == TITLE_SCREEN_DELAY)
        {
            TASK_DATA(animId);
            tData->animId = CustomTitle_InitMoveTextAnim();
            gTasks[taskId].func = Task_CustomTitleScreenMoveText;
        }
    }

    CreateTask(Task_CustomTitleCheckForSkip, 0);
}


static void Task_CustomTitleCheckForSkip(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | START_BUTTON))
    {
        sCustomTitleState->skipIntro = TRUE;
        DestroyTask(taskId);
    }
}

static void Task_CustomTitleScreenMoveText(u8 taskId)
{
    int animId = gTasks[taskId].data[0];
    int x = CheckSkipAndReadComfyAnim(&gComfyAnims[animId], sCustomTitleState->skipIntro);

    ChangeBgY(0, Q_8_8(x), BG_COORD_SET);

    if (gComfyAnims[animId].completed)
    {
        ReleaseComfyAnim(animId);
        gTasks[taskId].data[0] = CustomTitle_InitSubtitleFadeAnim();
        gTasks[taskId].data[1] = CustomTitle_InitWindowAnim();
        gTasks[taskId].func = Task_CustomTitleScreenFadeSubtitle;
    }
}

static void Task_CustomTitleScreenFadeSubtitle(u8 taskId)
{
    int animId = gTasks[taskId].data[0];
    int x = CheckSkipAndReadComfyAnim(&gComfyAnims[animId], sCustomTitleState->skipIntro);

    int winAnimId = gTasks[taskId].data[1];
    int v = CheckSkipAndReadComfyAnim(&gComfyAnims[winAnimId], sCustomTitleState->skipIntro);
    int x1 = 120 - v;
    int x2 = 120 + v;
    {
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(x1, x2));
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(x, 16-x));

    if (gComfyAnims[animId].completed && gComfyAnims[winAnimId].completed)
    {
        ReleaseComfyAnim(animId);
        ReleaseComfyAnim(winAnimId);
        PlaySE(SE_RG_SS_ANNE_HORN);
        struct Sprite* ship = &gSprites[sCustomTitleState->shipId];
        StartSpriteAnim(ship, 1);
        gTasks[taskId].data[0] = CustomTitle_InitWindowAnim();
        gTasks[taskId].func = Task_CustomTitleMainInput;
    }
}

static void Task_CustomTitleMainInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGM(2);
        PlaySE(SE_M_CUT);
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_CustomTitleWaitFadeAndExitGracefully;
    }
}

static void Task_CustomTitleWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomTitleState->savedCallback);
        CustomTitle_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_CustomTitleWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomTitleState->savedCallback);
        CustomTitle_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 CustomTitle_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg2TilemapBuffer == NULL) {
        return  FALSE; 
    }

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    sBg0TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg0TilemapBuffer == NULL) {
        return  FALSE; 
    }


    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sCustomTitleBgTemplates, NELEMS(sCustomTitleBgTemplates));

    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(0, sBg0TilemapBuffer);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(0);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void CustomTitle_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_CustomTitleWaitFadeAndBail, 0);
    SetVBlankCallback(CustomTitle_VBlankCB);
    SetMainCallback2(CustomTitle_MainCB);
}

static bool8 CustomTitle_LoadGraphics(void)
{
    switch (sCustomTitleState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndLoadBgGfxUsingHeap(1, sCustomTitleTiles, 0, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(0, sCustomTitleTextTiles, 0, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, sCustomTitleSubtitleTiles, 0, 0, 0);
        sCustomTitleState->loadState++;
        break;
    case 1:
        DecompressAndCopyToBgTilemapBuffer(1, sCustomTitleTilemap, BG_SCREEN_SIZE, 0);
        DecompressAndCopyToBgTilemapBuffer(0, sCustomTitleTextTilemap, BG_SCREEN_SIZE, 0);
        DecompressAndCopyToBgTilemapBuffer(2, sCustomTitleSubtitleTilemap, BG_SCREEN_SIZE, 0);
        sCustomTitleState->loadState++;
        break;
    case 2:
        LoadPalette(sCustomTitlePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP * 2);
        LoadPalette(sCustomTitleTextPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sCustomTitleState->loadState++;
    case 3:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    default:
        sCustomTitleState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static const union AnimCmd sSpriteAnim_Ship[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ShipPressStart[] = {
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Ship[] = {
    sSpriteAnim_Ship,
    sSpriteAnim_ShipPressStart,
};

static u32 CustomTitle_CreateShipSprite()
{
    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = sCustomTitleShipGfx;
    cs.spriteCompressed = FALSE;
    cs.tileTag = TAG_NONE;
    cs.palTag = 0x2000;
    cs.palette = sCustomTitleShipPal;
    cs.spriteSize = SPRITE_SIZE(64x32);
    cs.spriteShape = SPRITE_SHAPE(64x32);
    cs.posX = 24;
    cs.posY = 92;
    cs.subpriority = 0;
    cs.images = &sCustomTitleShipFrames;
    cs.numFrames = 2;
    cs.subspriteTable = sCustomTitleShipSubspriteTable;
    cs.anims = sSpriteAnimTable_Ship;
    cs.callback = SpriteCB_HandleShipBob;
    u32 id = Even_CreateSprite(&cs);
    return id;
}

static void SpriteCB_HandleShipBob(struct Sprite *sprite)
{
    if (sCustomTitleState->shipBob.frameCounter == 0)
        sCustomTitleState->shipBob.spriteOffset = Q_4_12(1.0);

    if (sCustomTitleState->shipBob.frameCounter == STEP_FRAME_DURATION)
        sCustomTitleState->shipBob.spriteOffset -= Q_4_12(0.5);

    if (sCustomTitleState->shipBob.frameCounter == STEP_FRAME_DURATION * 2)
    {
        sCustomTitleState->shipBob.spriteOffset += Q_4_12(0.5);
        sCustomTitleState->shipBob.frameCounter = 0;
        return;
    }

    sprite->y2 = Q_4_12_TO_INT(sCustomTitleState->shipBob.spriteOffset);
    sCustomTitleState->shipBob.frameCounter++;
}

static void CustomTitle_FreeResources(void)
{
    if (sCustomTitleState != NULL)
    {
        Free(sCustomTitleState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }

    if (sBg0TilemapBuffer != NULL)
    {
        Free(sBg0TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}
