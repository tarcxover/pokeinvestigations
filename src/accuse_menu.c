#include "global.h"
#include "assertf.h"
#include "constants/characters.h"
#include "constants/evidence.h"
#include "constants/field_weather.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/script_menu.h"
#include "event_data.h"
#include "evidence.h"
#include "field_weather.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/isagbprint.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_use.h"
#include "line_break.h"
#include "list_menu.h"
#include "main.h"
#include "bg.h"
#include "metaprogram.h"
#include "pokemon_summary_screen.h"
#include "progress_bar.h"
#include "script.h"
#include "script_menu.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "logic_menu.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "m4a.h"
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
#include "util.h"
#include <string.h>
#include "random.h"

#define MAX_SELECTIONS 4
#define LIST_HEADER_COUNT 2

#define TASK_DATA(...) struct { s16 __VA_ARGS__; } *tData = (void *)gTasks[taskId].data
#define TASK_DATA_N(n,...) struct { s16 __VA_ARGS__; } *tData = (void *)&gTasks[taskId].data[n]

#define ACCUSE_MENU_BORDER_TILE 439
#define ACCUSE_MENU_DIALOG_TILE 0x1DD

enum {

    ACCUSE_TAG_P1 = 0x3000,
    ACCUSE_TAG_P2,
    ACCUSE_TAG_P3,
    ACCUSE_TAG_P4,
    ACCUSE_TAG_P5,
    ACCUSE_TAG_P6,
    ACCUSE_TAG_P7,
    ACCUSE_TAG_P8,
    ACCUSE_TAG_CON,
    ACCUSE_TAG_SCROLL_ARROW,

};

typedef struct AccuseMenuInit
{
    MainCallback cb;
    enum Questions question;
    enum Suspects suspect;
} AccuseMenuInit;

struct AccuseMenuState
{
    MainCallback savedCallback;
    struct WindowTemplate* winTempls;
    struct ListMenuItem* evidence;
    u8 spriteIds[MAX_SELECTIONS];
    u8 scrollIndicatorTask;
    u8 loadState;
    u8 maxSelections;
    u8 remainingSelections;
    u32 selected[MAX_SELECTIONS];
    enum Questions question;
    u8 msgWinId;
    u8 yesNoWinId;
    u8 progTaskId;
};

struct AccuseMenuPrint {
    u8 window;
    u8 x;
    u8 y;
    const u8* text;
    union TextColor color;
    u8 font;
};

enum WindowIds
{
    WIN_ACCUSE_LIST,
    WIN_ACCUSE_DESC,
    WIN_ACCUSE_NAME,
    WIN_ACCUSE_SUSPECT,
    WIN_ACCUSE_QUES,
    WIN_ACCUSE_HINTS,
    WIN_ACCUSE_COUNT
};

static EWRAM_DATA struct AccuseMenuState *sAccuseMenuState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;

EWRAM_DATA enum Evidence gAccuseEvidence[MAX_SELECTIONS];

static const struct BgTemplate sAccuseMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .priority = 2
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .priority = 3
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 22,
        .priority = 0
    }
};

static const struct WindowTemplate sAccuseMenuWindowTemplates[] = {
    [WIN_ACCUSE_LIST] =
        {
            .bg = 0,
            .tilemapLeft = 0,
            .tilemapTop = 2,
            .width = 11,
            .height = 15,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_ACCUSE_DESC] =
        {
            .bg = 0,
            .tilemapLeft = 12,
            .tilemapTop = 9,
            .width = 15,
            .height = 7,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_ACCUSE_NAME] =
        {
            .bg = 0,
            .tilemapLeft = 13,
            .tilemapTop = 6,
            .width = 15,
            .height = 3,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_ACCUSE_SUSPECT] =
        {
            .bg = 0,
            .tilemapLeft = 1,
            .tilemapTop = 0,
            .width = 8,
            .height = 3,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_ACCUSE_QUES] =
        {
            .bg = 0,
            .tilemapLeft = 12,
            .tilemapTop = 0,
            .width = 16,
            .height = 3,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_ACCUSE_HINTS] =
        {
            .bg = 0,
            .tilemapLeft = 13,
            .tilemapTop = 16,
            .width = 14,
            .height = 2,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sAccuseMsgWinTemplHelp = {
    .bg = 3,
    .tilemapLeft = 2,
    .tilemapTop = 3,
    .width = 26,
    .height = 14,
    .paletteNum = 14,
    .baseBlock = 1,
};

static const struct WindowTemplate sAccuseMsgWinTemplNotify = {
    .bg = 3,
    .tilemapLeft = 1,
    .tilemapTop = 12,
    .width = 28,
    .height = 7,
    .paletteNum = 14,
    .baseBlock = 1,
};

static const struct WindowTemplate sAccuseMsgWinTemplYesNo = {
    .bg = 3,
    .tilemapLeft = 1,
    .tilemapTop = 2,
    .width = 7,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 200,
};

static const u32 sAccuseMenuTiles[] = INCBIN_U32("graphics/accuse_menu/bg/tiles.4bpp.smol");
static const u32 sAccuseMenuTilemap[] = INCBIN_U32("graphics/accuse_menu/bg/map.bin.smolTM");
static const u16 sAccuseMenuPalette[] = INCBIN_U16("graphics/accuse_menu/bg/palette_00.gbapal");

static const u32 sAccuseMenuScrollingBgTiles[] = INCGFX_U32("graphics/accuse_menu/scroll/tiles.png", ".4bpp.smol");
static const u32 sAccuseMenuScrollingBgTilemap[] = INCBIN_U32("graphics/accuse_menu/scroll/map.bin.smolTM");
static const u16 sAccuseMenuScrollingBgPalette[] = INCGFX_U16("graphics/accuse_menu/scroll/palette_01.pal", ".gbapal");

static const u32 sAccuseMenuBorderTiles[] = INCGFX_U32("graphics/accuse_menu/border_tiles.png", ".4bpp");
static const u32 sAccuseMenuBorderPalette[] = INCGFX_U32("graphics/accuse_menu/border_tiles.png", ".gbapal");

static const u32 sAccuseMenuProgBarGfx[] = INCGFX_U32("graphics/accuse_menu/progbar/progbar.png", ".4bpp");
static const u16 sAccuseMenuProgBarPal[] = INCGFX_U16("graphics/accuse_menu/progbar/progbar.png", ".gbapal");

static const ProgBar_Template sAccuseProgBarTemplate = 
{
    .totalBarPixels = 130,
    .numStartTiles = 1,
    .numEndTiles = 1,
    .xOffset = 48,
    .yPos = 112,
    .tileTag = PROG_BAR_TAG,
    .palTag = PROG_BAR_TAG,
    .pal = sAccuseMenuProgBarPal,
    .barGfx = (const Tile4BPP*)sAccuseMenuProgBarGfx,
};

EWRAM_DATA u32 gAccuseScore;
EWRAM_DATA ProgBar_Tracker gAccuseMenuProgTracker;

enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_BLUE,
    FONT_GREEN,
    FONT_RED,
    FONT_GRAY,
};

static const struct ListMenuTemplate sAccuseMenuListTemplate =
{
    .item_X = 12,
    .header_X = 2,
    .cursor_X = 4,
    .upText_Y = 10,
    .cursorPal = TEXT_COLOR_DARK_GRAY,
    .fillValue = 0,
    .cursorShadowPal = TEXT_COLOR_LIGHT_GRAY,
    .lettersSpacing = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .itemVerticalPadding = 1,
    .fontId = FONT_SMALL,
    .maxShowed = 6,
};

static union TextColor sAccuseMenuWindowFontColors[] = {
    [FONT_BLACK] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_DARK_GRAY,
            .shadow     = TEXT_COLOR_LIGHT_GRAY,
        },
    [FONT_WHITE] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_WHITE,
            .shadow     = TEXT_COLOR_DARK_GRAY,
        },
    [FONT_BLUE] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_LIGHT_BLUE,
            .shadow     = TEXT_COLOR_BLUE,
        },
    [FONT_RED] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_LIGHT_RED,
            .shadow     = TEXT_COLOR_RED,
        },
    [FONT_GREEN] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_GREEN,
            .shadow     = TEXT_COLOR_LIGHT_GREEN,
        },
    [FONT_GRAY] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_LIGHT_GRAY,
            .shadow     = TEXT_COLOR_DARK_GRAY,
        },
};

enum {
    EVD_POS_LEFT,
    EVD_POS_RIGHT,
    EVD_POS_RESULT,
};

static const struct Coords16 sAccuseMenuIconPos = {111, 43};

static const u8 sText_DeductionSuccess[] = _("Deduction successful. Received new evidence:\n{STR_VAR_1}");

static void AccuseMenu_SetupCB(void);
static void AccuseMenu_MainCB(void);
static void AccuseMenu_VBlankCB(void);

static void Task_AccuseMenuWaitFadeIn(u8 taskId);
static void Task_AccuseMenuInitList(u8 taskId);
static void Task_AccuseMenuMainInput(u8 taskId);
static void Task_AccuseMenuHandleAccuse(u8 taskId);
static void Task_AccuseMenuWaitFadeAndExit(u8 taskId);
static void Task_AccuseMenuScrollBg(u8 taskId);
static void Task_MessagWinInput(u8 taskId);

static void AccuseMenu_Init(AccuseMenuInit* init);
static void AccuseMenu_ResetGpuRegsAndBgs(void);
static bool8 AccuseMenu_InitBgs(void);
static void AccuseMenu_FadeAndBail(void);
static bool8 AccuseMenu_LoadGraphics(void);
static void AccuseMenu_InitWindows(void);
static u32 CreateEvidenceListMenu(struct ListMenuTemplate* t);
static u32 DrawAccuseMenuMsgWin(const struct WindowTemplate* t, const u8* string, bool32 autoBreak);
static void AccuseMenuPrintMsg(struct AccuseMenuPrint *p);
static void AccuseMenuCenterText(struct AccuseMenuPrint *p);
static u32 CreateEvidenceIcon(u32 pos, u32 input);
static void DestroyEvidenceIcon(u32 pos);
static void DestroyAllEvidenceIcons(void);
static void RedrawEvidenceIcons(void);
static u32 GetListMaxShowable(struct ListMenuTemplate* t);
static void AccuseMenuList_PrintFunc(const struct ListMenu *list, u32 index, u8 y);
static void PrintDescription(enum Item id);
static void PrintAccuseMenuHints(u32 color);
static void PrintAccuseMenuItemName(enum Item item);
static void PrintAccuseMenuSuspect(enum Suspects suspect);
static void PrintAccuseMenuQuestion();
static u32 FillEvdGroup(struct ListMenuItem *items, u32 count, const u8 *header, bool32 deductions);
static u32 FillEvdList(struct ListMenuItem *items);
static u32 AddAccuseMenuScrollArrows(struct ListMenu *list);
static u32 CalculateScore(u32* evidence, u32 count);
static void UNUSED Accuse_CreateYesNoMenu(const struct WindowTemplate *window, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
static void HideAccuseMenuMsgWin(u8 winId);

static void Accuse_CreateProgBar();

static void AccuseMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void AccuseMenu_FreeResources(void);

static EWRAM_DATA AccuseMenuInit sAccuseMenuInit;

void ScrCmd_openaccusemenu(struct ScriptContext* ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    enum Questions q = ScriptReadByte(ctx);
    enum Suspects s = ScriptReadByte(ctx);
    sAccuseMenuInit.question = q;
    sAccuseMenuInit.suspect = s;
    CB2_InitAccuseMenu();
}

void CB2_InitAccuseMenu(void)
{
    FadeScreen(FADE_TO_BLACK, 0);
    sAccuseMenuInit.cb = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    CreateTask(Task_OpenAccuseMenu, 1);
}

void Task_OpenAccuseMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        AccuseMenu_Init(&sAccuseMenuInit);
        DestroyTask(taskId);
    }
}

static void AccuseMenu_Init(AccuseMenuInit* init)
{
    sAccuseMenuState = AllocZeroed(sizeof(struct AccuseMenuState));
    if (sAccuseMenuState == NULL)
    {
        SetMainCallback2(init->cb);
        return;
    }

    for (u32 i = 0; i < MAX_SELECTIONS; i++)
        sAccuseMenuState->spriteIds[i] = SPRITE_NONE;

    sAccuseMenuState->loadState = 0;
    sAccuseMenuState->savedCallback = init->cb;
    sAccuseMenuState->maxSelections = MAX_SELECTIONS;
    sAccuseMenuState->remainingSelections = sAccuseMenuState->maxSelections;
    sAccuseMenuState->question = sAccuseMenuInit.question;

    SetMainCallback2(AccuseMenu_SetupCB);
}

static void AccuseMenu_ResetGpuRegsAndBgs(void)
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
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    CpuFill16(0, (void*)VRAM, VRAM_SIZE);
    CpuFill32(0, (void*)OAM, OAM_SIZE);
}

static void AccuseMenu_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        FadeOutMapMusic(2);
        AccuseMenu_ResetGpuRegsAndBgs();
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
        if (AccuseMenu_InitBgs())
        {
            sAccuseMenuState->loadState = 0;
            gMain.state++;
        }
        else
        {
            AccuseMenu_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (AccuseMenu_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        AccuseMenu_InitWindows();
        gMain.state++;
        break;
    case 5:
        Accuse_CreateProgBar();
        PlayBGM(MUS_LOGIC);
        CreateTask(Task_AccuseMenuWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        PrintAccuseMenuQuestion();
        PrintAccuseMenuSuspect(sAccuseMenuInit.suspect);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 8:
        CreateTask(Task_AccuseMenuScrollBg, 0);
        SetVBlankCallback(AccuseMenu_VBlankCB);
        SetMainCallback2(AccuseMenu_MainCB);
        break;
    }
}

static void Task_AccuseMenuMainInput(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);

    if (JOY_NEW(SELECT_BUTTON))
    {
        sAccuseMenuState->msgWinId = DrawAccuseMenuMsgWin(&sAccuseMsgWinTemplHelp, COMPOUND_STRING(
            "Select up to 4 pieces of evidence that\n"
            "link the suspect to the question above.\n"
            "Relevant evidence will build a better case.\n"
            "Deductions are worth more than clues.\n"
            "\n"
            "{A_BUTTON} Toggle evidence on or off\n"
            "{B_BUTTON} Clear all selections\n"
            "{START_BUTTON} Submit your accusation\n"
            "{SELECT_BUTTON} Open or close help menu"
        ), FALSE);
        RemoveScrollIndicatorArrowPair(sAccuseMenuState->scrollIndicatorTask);
        gTasks[taskId].func = Task_MessagWinInput;
    }

    struct ListMenu* list = (void*) gTasks[tData->listTaskId].data;
    s32 input = ListMenu_ProcessInput(tData->listTaskId);
    switch (input)
    {
    case LIST_HEADER:
        break;
    case LIST_NOTHING_CHOSEN:
        if(JOY_NEW(START_BUTTON))
            {
                tData->state = 0;
                RemoveScrollIndicatorArrowPair(sAccuseMenuState->scrollIndicatorTask);
                gTasks[taskId].func = Task_AccuseMenuHandleAccuse;
            }
        break;
    case LIST_CANCEL:
        if (!gTasks[taskId].data[1])
        {
            u32 max = sAccuseMenuState->maxSelections;
            u32 *listptr = sAccuseMenuState->selected;
            memset(listptr, 0, max * sizeof(sAccuseMenuState->selected[0]));
            sAccuseMenuState->remainingSelections = max;
            RedrawListMenu(tData->listTaskId);
            goto finish;
        }
        break;
    default: {
        PlaySE(SE_SELECT);
        u32 max = sAccuseMenuState->maxSelections;
        u8 *count = &sAccuseMenuState->remainingSelections;
        u32 found = lsearch(&input, sAccuseMenuState->selected, max);
        if (found != UINT32_MAX)
        {
            size_t s = (sizeof(sAccuseMenuState->selected[0]) * (max - (found + 1)));
            u32 *listptr = &sAccuseMenuState->selected[found];
            memmove(listptr, listptr + 1, s);
            sAccuseMenuState->selected[max - 1] = 0xFF;
            (*count)++;
            goto finish;
        }

        if (*count == 0)
            break;
        u32 pos = max - *count;
        assertf(pos < MAX_SELECTIONS);
        sAccuseMenuState->selected[pos] = input;
        (*count)--;

    finish:
        RedrawEvidenceIcons();
        ListMenuRedrawRow(list, list->selectedRow);
        u32 color = 0;
        if (sAccuseMenuState->maxSelections - sAccuseMenuState->remainingSelections >= 2)
            color = sAccuseMenuWindowFontColors[FONT_GREEN].asU32;
        else
            color = sAccuseMenuWindowFontColors[FONT_RED].asU32;
        PrintAccuseMenuHints(color);
        break;
    }
    }
}

static void Task_AccuseMenuHandleAccuse(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);
    struct ListMenu *list = (void *)gTasks[tData->listTaskId].data;

    switch (tData->state)
    {
    case 0:
        sAccuseMenuState->msgWinId = DrawAccuseMenuMsgWin(&sAccuseMsgWinTemplNotify, COMPOUND_STRING("Are you sure?"), TRUE);
        CreateYesNoMenu(&sAccuseMsgWinTemplYesNo, ACCUSE_MENU_BORDER_TILE, 14, 0);
        tData->state++;
        break;
    case 1:
        s8 input = Menu_ProcessInputNoWrapClearOnChoose();
            if (input == 0)
            {
                tData->state++;
            }
            else if (input != MENU_NOTHING_CHOSEN) {
                HideAccuseMenuMsgWin(sAccuseMenuState->msgWinId);
                sAccuseMenuState->scrollIndicatorTask = AddAccuseMenuScrollArrows(list);
                gTasks[taskId].func = Task_AccuseMenuMainInput;
            }
        break;
    case 2:
        u32 count = sAccuseMenuState->maxSelections -
                    sAccuseMenuState->remainingSelections;
        u32 score = CalculateScore(sAccuseMenuState->selected, count);
        gSpecialVar_Result = score;
        gAccuseScore += score;

        for (u32 i = 0; i < MAX_SELECTIONS; i++)
        {
            enum Evidence e =
                sAccuseMenuState->selected[i] - ITEM_EVIDENCE_START;
            gAccuseEvidence[i] = i < count ? e : EVD_COUNT;
        }

        HideAccuseMenuMsgWin(sAccuseMenuState->msgWinId);
        tData->state++;
        break;
    case 3:
        gAccuseMenuProgTracker.target = gAccuseScore;
        ProgBar_State* progState = (void*)gTasks[sAccuseMenuState->progTaskId].data;
        if (!progState->animating)
            tData->state++;
        break;
    case 4:
        PlaySE(SE_SUCCESS);
        tData->state++;
    case 5 ... 30:
        tData->state++;
        break;
    case 31:
        if (IsSEPlaying())
            break;
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_AccuseMenuWaitFadeAndExit;
        break;
    }
}

static void AccuseMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void AccuseMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_AccuseMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ClearTaskData(taskId);
        gTasks[taskId].func = Task_AccuseMenuInitList;
    }
}

static void Task_AccuseMenuInitList(u8 taskId)
{
    TASK_DATA(state, listTaskId);

    switch (tData->state)
    {
    case 0:
        tData->listTaskId = CreateEvidenceListMenu(&gMultiuseListMenuTemplate);
        tData->state++;
        break;
    case 1: {
        u8 listTaskId = tData->listTaskId;
        struct ListMenu *list = (void *)gTasks[listTaskId].data;
        ListMenuChangeSelectionFull(list, TRUE, FALSE, 0, TRUE);

        if (!FlagGet(FLAG_TARC3_ACCUSE_SEEN_HELP))
        {
            FlagSet(FLAG_TARC3_ACCUSE_SEEN_HELP);
            sAccuseMenuState->msgWinId = DrawAccuseMenuMsgWin(&sAccuseMsgWinTemplHelp, COMPOUND_STRING(
                "Select up to 4 pieces of evidence that\n"
                "link the suspect to the question above.\n"
                "Relevant evidence will build a better case.\n"
                "Deductions are worth more than clues.\n"
                "\n"
                "{A_BUTTON} Toggle evidence on or off\n"
                "{B_BUTTON} Clear all selections\n"
                "{START_BUTTON} Submit your accusation\n"
                "{SELECT_BUTTON} Open or close help menu"
            ), FALSE);
            RemoveScrollIndicatorArrowPair(sAccuseMenuState->scrollIndicatorTask);
            gTasks[taskId].func = Task_MessagWinInput;
        }
        else
        {
            gTasks[taskId].func = Task_AccuseMenuMainInput;
        }
    }
    }
}

static void AccuseMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (itemIndex == LIST_HEADER)
        return;

    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    PrintDescription(itemIndex);
    PrintAccuseMenuItemName(itemIndex);
}

static const struct ScrollArrowsTemplate sEvidenceMenuScrollArrowTemplate =
{
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 40,
    .firstY = 26,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 40,
    .secondY = 134,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 0,
    .tileTag = ACCUSE_TAG_SCROLL_ARROW,
    .palTag = ACCUSE_TAG_SCROLL_ARROW,
    .palNum = 0,
};

static u32 CreateEvidenceListMenu(struct ListMenuTemplate* template)
{

    sAccuseMenuState->evidence = AllocZeroed(sizeof(struct ListMenuItem) * (gBagPockets[POCKET_EVIDENCE].capacity + LIST_HEADER_COUNT));

    if (sAccuseMenuState->evidence == NULL) {
        AccuseMenu_FadeAndBail(); 
        return 1;
    }
    struct ListMenuItem* items = sAccuseMenuState->evidence;

    u32 evdCount = FillEvdList(items);

    struct ListMenuTemplate* t = &gMultiuseListMenuTemplate;
    *t = sAccuseMenuListTemplate;
    t->items = items;
    t->windowId = WIN_ACCUSE_LIST;
    t->totalItems = evdCount;
    t->maxShowed = GetListMaxShowable(t);
    t->moveCursorFunc = AccuseMenu_MoveCursorFunc;
    t->itemPrintFunc  = AccuseMenuList_PrintFunc;

    u32 initialRow = (evdCount != 0 && items[0].id == LIST_HEADER);
    u32 listTaskId = ListMenuInit(template, 0, initialRow);
    struct ListMenu* list = (void*)gTasks[listTaskId].data;

    sAccuseMenuState->scrollIndicatorTask = AddAccuseMenuScrollArrows(list);

    return  listTaskId;
}

static u32 AddAccuseMenuScrollArrows(struct ListMenu *list)
{
    gTempScrollArrowTemplate = sEvidenceMenuScrollArrowTemplate;
    gTempScrollArrowTemplate.fullyUpThreshold = 0;
    gTempScrollArrowTemplate.fullyDownThreshold =
        list->template.totalItems - list->template.maxShowed;

     return AddScrollIndicatorArrowPair(
        &gTempScrollArrowTemplate, &list->scrollOffset);
}

static u32 FillEvdGroup(struct ListMenuItem *items, u32 count, const u8 *header, bool32 deductions)
{
    u32 slots = BagPocket_CountUsedItemSlots(&gBagPockets[POCKET_EVIDENCE]);
    enum Questions question = sAccuseMenuState->question;
    u32 headerPos = count++;

    for (u32 i = 0; i < slots; i++)
    {
        enum Evidence e = GetBagItemId(POCKET_EVIDENCE, i) - ITEM_EVIDENCE_START;

        bool32 isDeduction = gEvidence[e].score > EVD_SCORE_CLUE;

        if (question != QUESTION_NONE && !EvidenceAnswersQuestion(e, question))
            continue;
        if (isDeduction != deductions)
            continue;

        items[count++] = (struct ListMenuItem){gEvidence[e].name, gEvidence[e].itemId};
    }

    if (count == headerPos + 1)
        return headerPos;

    items[headerPos] = (struct ListMenuItem){header, LIST_HEADER};
    return count;
}

static u32 FillEvdList(struct ListMenuItem *items)
{
    u32 count = FillEvdGroup(items, 0, COMPOUND_STRING("Deductions"), TRUE);
    count = FillEvdGroup(items, count, COMPOUND_STRING("Clues"), FALSE);

    if (count != 0)
        return count;

    u32 slots = BagPocket_CountUsedItemSlots(&gBagPockets[POCKET_EVIDENCE]);

    for (u32 i = 0; i < slots; i++)
    {
        struct EvidenceInfo e =
            gEvidence[GetBagItemId(POCKET_EVIDENCE, i) - ITEM_EVIDENCE_START];

        items[i] = (struct ListMenuItem){e.name, e.itemId};
    }

    return slots;
}

static u32 CreateEvidenceIcon(u32 pos, u32 itemId)
{
    u32 id = AddItemIconSprite(ACCUSE_TAG_P1 + pos, ACCUSE_TAG_P1 + pos, itemId);
    struct Sprite* sprite = &gSprites[id];
    sprite->x = sAccuseMenuIconPos.x + (pos % (MAX_SELECTIONS)) * 36;
    sprite->y = sAccuseMenuIconPos.y + (pos / (MAX_SELECTIONS)) * 40;
    return id;
}

static void DestroyEvidenceIcon(u32 pos)
{
    FreeSpriteTilesByTag(ACCUSE_TAG_P1 + pos);
    FreeSpritePaletteByTag(ACCUSE_TAG_P1 + pos);
    DestroySprite(&gSprites[sAccuseMenuState->spriteIds[pos]]);
    sAccuseMenuState->spriteIds[pos] = SPRITE_NONE;
}

static void DestroyAllEvidenceIcons(void)
{
    for (int i = 0; i < MAX_SELECTIONS; i++) {
        if (sAccuseMenuState->spriteIds[i] != SPRITE_NONE)
            DestroyEvidenceIcon(i);
    }
}

static void RedrawEvidenceIcons(void)
{
    u32 numSelected =
        sAccuseMenuState->maxSelections - sAccuseMenuState->remainingSelections;

    DestroyAllEvidenceIcons();

    for (u32 i = 0; i < numSelected; i++)
    {
        sAccuseMenuState->spriteIds[i] =
            CreateEvidenceIcon(i, sAccuseMenuState->selected[i]);
    }
}

static u32 GetListMaxShowable(struct ListMenuTemplate* t)
{
    u32 rowHeight = GetFontAttribute(t->fontId, FONTATTR_MAX_LETTER_HEIGHT)
                    + t->itemVerticalPadding;

    u32 availableHeight = GetWindowAttribute(t->windowId, WINDOW_HEIGHT) * 8
                         - t->upText_Y;

     return (availableHeight / rowHeight);
}

static void AccuseMenuList_PrintFunc(const struct ListMenu *list, u32 index, u8 y)
{
    const struct ListMenuTemplate *templ = &list->template;
    const struct ListMenuItem *item = &templ->items[index];
    u32 windowId = templ->windowId;
    u32 id = item->id;

    bool32 selected = lsearch(&id, sAccuseMenuState->selected, sAccuseMenuState->maxSelections) != UINT32_MAX;

    u32 colorId = FONT_WHITE;
    if (id == LIST_HEADER)
        colorId = FONT_GRAY;
    else if (selected)
        colorId = FONT_BLUE;

    const u32 color = sAccuseMenuWindowFontColors[colorId].asU32;

    const u8 *name = item->name;

    u8 fontId =
        GetFontIdToFit(name, FONT_SMALL_NARROW, 0, templ->textNarrowWidth);
    u32 x = (id == LIST_HEADER) ? templ->header_X : templ->item_X;

    struct AccuseMenuPrint p = {
        .font = fontId,
        .text = name,
        .window = windowId,
        .x = x,
        .y = y,
        .color.asU32 = color,
    };

    AccuseMenuPrintMsg(&p);
}

static void Task_AccuseMenuWaitFadeAndExit(u8 taskId)
{
    FadeOutBGM(2);
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sAccuseMenuState->savedCallback);
        AccuseMenu_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 AccuseMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }


    sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg2TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sAccuseMenuBgTemplates, NELEMS(sAccuseMenuBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void AccuseMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_AccuseMenuWaitFadeAndExit, 0);
    SetVBlankCallback(AccuseMenu_VBlankCB);
    SetMainCallback2(AccuseMenu_MainCB);
}

static bool8 AccuseMenu_LoadGraphics(void)
{
    switch (sAccuseMenuState->loadState)
    {
    case 0:
        DecompressAndLoadBgGfxUsingHeap(1, sAccuseMenuTiles, 0, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, sAccuseMenuScrollingBgTiles, 0, 0, 0);
        sAccuseMenuState->loadState++;
        break;
    case 1:
        DecompressDataWithHeaderWram(sAccuseMenuTilemap, sBg1TilemapBuffer);
        DecompressDataWithHeaderWram(sAccuseMenuScrollingBgTilemap, sBg2TilemapBuffer);
        sAccuseMenuState->loadState++;
        break;
    case 2:
        LoadBgTiles(3, sAccuseMenuBorderTiles, 0x120, ACCUSE_MENU_BORDER_TILE);
        LoadPalette(sAccuseMenuBorderPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        LoadPalette(sAccuseMenuPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(sAccuseMenuScrollingBgPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        LoadPalette(sAccuseMenuBorderPalette, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
        sAccuseMenuState->loadState++;
    default:
        sAccuseMenuState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

enum WindowTilePosition
{
    TILE_TOP_LEFT = 0,
    TILE_TOP,
    TILE_TOP_RIGHT,
    TILE_LEFT,
    TILE_CENTER,
    TILE_RIGHT,
    TILE_BOTTOM_LEFT,
    TILE_BOTTOM,
    TILE_BOTTOM_RIGHT,
    TILE_COUNT,
};

static void DrawAccuseMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u32 topLeft     = baseTileNum + TILE_TOP_LEFT;
    u32 top         = baseTileNum + TILE_TOP;
    u32 topRight    = baseTileNum + TILE_TOP_RIGHT;
    u32 left        = baseTileNum + TILE_LEFT;
    u32 right       = baseTileNum + TILE_RIGHT;
    u32 bottomLeft  = baseTileNum + TILE_BOTTOM_LEFT;
    u32 bottom      = baseTileNum + TILE_BOTTOM;
    u32 bottomRight = baseTileNum + TILE_BOTTOM_RIGHT;

    const u8 bg = template->bg;
    const s16 winLeft = template->tilemapLeft;
    const s16 winTop = template->tilemapTop;
    const s16 width = template->width;
    const s16 height = template->height;

    FillBgTilemapBufferRect(bg, topLeft, winLeft - 1, winTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(bg, top, winLeft, winTop - 1, width, 1, 2);
    FillBgTilemapBufferRect(bg, topRight, winLeft + width, winTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(bg, left, winLeft - 1, winTop, 1, height, 2);
    FillBgTilemapBufferRect(bg, right, winLeft + width, winTop, 1, height, 2);
    FillBgTilemapBufferRect(bg, bottomLeft, winLeft - 1, winTop + height, 1, 1, 2);
    FillBgTilemapBufferRect(bg, bottom, winLeft, winTop + height, width, 1, 2);
    FillBgTilemapBufferRect(bg, bottomRight, winLeft + width, winTop + height, 1, 1, 2);

    CopyBgTilemapBufferToVram(bg);
}

static void AccuseMenu_InitWindows(void)
{
    InitWindows(sAccuseMenuWindowTemplates);

    u32 windowId = 0;
    SetWindowAttribute(windowId, WINDOW_BASE_BLOCK, 1);
    while (GetWindowAttribute(windowId, WINDOW_BG) != 0xFF) { 
        u32 b = GetWindowAttribute(windowId, WINDOW_BASE_BLOCK);
        u32 w = GetWindowAttribute(windowId, WINDOW_WIDTH);
        u32 h = GetWindowAttribute(windowId, WINDOW_HEIGHT);
        SetWindowAttribute(++windowId, WINDOW_BASE_BLOCK, b+h*w);
    }
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WIN_ACCUSE_LIST, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PrintAccuseMenuHints(sAccuseMenuWindowFontColors[FONT_RED].asU32);
    for (int i = 0; i < WIN_ACCUSE_COUNT; i++)
    {
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static u32 DrawAccuseMenuMsgWin(const struct WindowTemplate *t, const u8 *string, bool32 autoBreak)
{
    u32 msgWin = AddWindow(t);
    FillWindowPixelBuffer(msgWin, PIXEL_FILL(1));
    DrawAccuseMenuWindowBorder(t, ACCUSE_MENU_BORDER_TILE);
    PutWindowTilemap(msgWin);

    union TextColor c = {{
        .background = 0,
        .foreground = 2,
        .shadow = 3,
    }};

    struct AccuseMenuPrint p = {
        .font = FONT_SMALL,
        .x = 2,
        .window = msgWin,
        .text = gStringVar4,
        .color = c,
    };

    StringCopy(gStringVar4, string);
    if (autoBreak)
    {
        StripLineBreaks(gStringVar4);
        u32 w = GetWindowAttribute(p.window, WINDOW_WIDTH) * 8;
        BreakStringAutomatic(gStringVar4, w, 8, p.font, HIDE_SCROLL_PROMPT);
    }

    AccuseMenuPrintMsg(&p);
    CopyWindowToVram(msgWin, COPYWIN_FULL);
    SetGpuReg(REG_OFFSET_BLDCNT,
              (BLDCNT_TGT1_ALL & ~BLDCNT_TGT1_BG3) | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 10);
    ShowBg(3);
    return msgWin;
}

static void HideAccuseMenuMsgWin(u8 winId)
{
    FillWindowPixelBuffer(winId, PIXEL_FILL(0));
    ClearStdWindowAndFrame(winId, 0);
    CopyWindowToVram(winId, COPYWIN_FULL);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    HideBg(3);
    RemoveWindow(winId);
}

static void Task_MessagWinInput(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);

    if (JOY_NEW(A_BUTTON | SELECT_BUTTON))
    {
        struct ListMenu *list = (void *)gTasks[tData->listTaskId].data;
        HideAccuseMenuMsgWin(sAccuseMenuState->msgWinId);
        HideBg(3);
        sAccuseMenuState->scrollIndicatorTask = AddAccuseMenuScrollArrows(list);
        PrintAccuseMenuHints(sAccuseMenuWindowFontColors[FONT_RED].asU32);
        /* RedrawListMenu(tData->listTaskId); */
        gTasks[taskId].func = Task_AccuseMenuMainInput;
    }
}

static void PrintDescription(enum Item id)
{
    FillWindowPixelBuffer(WIN_ACCUSE_DESC, PIXEL_FILL(0));
    struct AccuseMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_ACCUSE_DESC,
        .x = 4,
        .y = 0,
        .text = gStringVar4,
        .color = {{
            TEXT_COLOR_TRANSPARENT,
            TEXT_COLOR_WHITE,
            TEXT_COLOR_DARK_GRAY,
        }},
    };
    StringCopy(gStringVar4, GetItemDescription(id));
    StripLineBreaks(gStringVar4);
    u32 w = GetWindowAttribute(p.window, WINDOW_WIDTH) * 8;
    BreakStringAutomatic(gStringVar4, w, 8, p.font, HIDE_SCROLL_PROMPT);
    AccuseMenuPrintMsg(&p);
}

static void PrintAccuseMenuHints(u32 color)
{
    const u8 fontId = FONT_SMALL_NARROWER;
    const u8* text = COMPOUND_STRING("{START_BUTTON} Accuse! {COLOR WHITE}{SHADOW DARK_GRAY}{SELECT_BUTTON} Info{COLOR WHITE}{SHADOW DARK_GRAY}");
    s16 x = GetStringCenterAlignXOffset(fontId, text, GetWindowAttribute(WIN_ACCUSE_HINTS, WINDOW_WIDTH) * 8);
    FillWindowPixelBuffer(WIN_ACCUSE_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct AccuseMenuPrint p = {
        .font = fontId,
        .window = WIN_ACCUSE_HINTS,
        .x = x,
        .y = 0,
        .text = text,
        .color = sAccuseMenuWindowFontColors[FONT_RED],
    };
    AccuseMenuPrintMsg(&p);
    CopyWindowToVram(WIN_ACCUSE_HINTS, COPYWIN_GFX);
}

static void PrintAccuseMenuItemName(enum Item item)
{
    FillWindowPixelBuffer(WIN_ACCUSE_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct AccuseMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_ACCUSE_NAME,
        .x = 0,
        .y = 6,
        .text = GetItemName(item),
        .color = sAccuseMenuWindowFontColors[FONT_WHITE],
    };

    AccuseMenuCenterText(&p);
    AccuseMenuPrintMsg(&p);
    CopyWindowToVram(WIN_ACCUSE_NAME, COPYWIN_GFX);
}

static void PrintAccuseMenuSuspect(enum Suspects suspect)
{
    FillWindowPixelBuffer(WIN_ACCUSE_SUSPECT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct AccuseMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_ACCUSE_SUSPECT,
        .x = 0,
        .y = 6,
        .text = GetSuspectText(suspect),
        .color = sAccuseMenuWindowFontColors[FONT_WHITE],
    };

    AccuseMenuCenterText(&p);
    AccuseMenuPrintMsg(&p);
    CopyWindowToVram(WIN_ACCUSE_SUSPECT, COPYWIN_GFX);
}

static void PrintAccuseMenuQuestion()
{
    FillWindowPixelBuffer(WIN_ACCUSE_QUES, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct AccuseMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_ACCUSE_QUES,
        .x = 6,
        .y = 6,
        .text = GetQuestionText(sAccuseMenuState->question),
        .color = sAccuseMenuWindowFontColors[FONT_WHITE],
    };

    AccuseMenuPrintMsg(&p);
    CopyWindowToVram(WIN_ACCUSE_QUES, COPYWIN_GFX);
}

static void AccuseMenuPrintMsg(struct AccuseMenuPrint *p)
{
    const u8 colors[3] = {
        (p->color.asU32 & 0xFF),
        ((p->color.asU32 >> 8) & 0xFF),
        ((p->color.asU32 >> 16) & 0xFF),
    };
    AddTextPrinterParameterized4(p->window, p->font, p->x, p->y, 0, 0, colors, 0, p->text);
}

static void AccuseMenuCenterText(struct AccuseMenuPrint *p)
{
    u8 pixelWidth = GetWindowAttribute(p->window, WINDOW_WIDTH) * 8;
    u32 xOffset = GetStringCenterAlignXOffset(p->font, p->text, pixelWidth);
    p->x = xOffset;
}

static void Task_AccuseMenuScrollBg(u8 taskId)
{
    s16* tAccumulator = &gTasks[taskId].data[0];

    *tAccumulator += 104;

    s16 pixels = *tAccumulator >> 8;
    *tAccumulator &= 0xFF;

    if (pixels != 0) {
        ChangeBgX(2, pixels << 8, BG_COORD_ADD);
        ChangeBgY(2, pixels << 8, BG_COORD_ADD);
    }
}

static bool32 _ImplicatesSuspect(enum Suspects suspect, enum Evidence evidence)
{
    auto suspectPtr = gEvidence[evidence].suspects;

    while (TRUE)
    {
        if (*suspectPtr == suspect)
        {

            return TRUE;
        }
        else if (*suspectPtr == SUSPECT_COUNT)
        {
            return FALSE;
        }
        else
        {
            suspectPtr++;
        }
    }
}

static u32 CalculateScore(u32* evidence, u32 count)
{
    u32 score = 0;
    for (u32 i = 0; i < count; i++)
    {
        enum Evidence e = evidence[i] - ITEM_EVIDENCE_START;
        if (_ImplicatesSuspect(sAccuseMenuInit.suspect, e))
        {
            score += gEvidence[e].score;
        }
    }
    return score;
}

static void Accuse_CreateYesNoMenu(const struct WindowTemplate *window, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate printer;

    sAccuseMenuState->yesNoWinId = AddWindow(window);
    DrawStdFrameWithCustomTileAndPalette(sAccuseMenuState->yesNoWinId, TRUE, baseTileNum, paletteNum);

    printer.currentChar = gText_YesNo;
    printer.type = WINDOW_TEXT_PRINTER;
    printer.windowId = sAccuseMenuState->yesNoWinId;
    printer.fontId = FONT_NORMAL;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.color.foreground = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_FOREGROUND);
    printer.color.background = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    printer.color.shadow = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_SHADOW);
    printer.color.accent = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_ACCENT);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    AddTextPrinter(&printer, TEXT_SKIP_DRAW, NULL);
    InitMenuInUpperLeftCornerNormal(sAccuseMenuState->yesNoWinId, 2, initialCursorPos);
}

static void Accuse_CreateProgBar()
{
    gAccuseMenuProgTracker.max = 80;
    gAccuseMenuProgTracker.curr = gAccuseScore;
    gAccuseMenuProgTracker.target = gAccuseMenuProgTracker.curr;
    u32 progTaskId = ProgBar_CreateBar(&sAccuseProgBarTemplate,&gAccuseMenuProgTracker);
    sAccuseMenuState->progTaskId = progTaskId;
}

static void AccuseMenu_FreeResources(void)
{
    TRY_FREE_AND_SET_NULL(sAccuseMenuState->evidence);
    TRY_FREE_AND_SET_NULL(sAccuseMenuState);
    TRY_FREE_AND_SET_NULL(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
    ResetSpriteData();
}
