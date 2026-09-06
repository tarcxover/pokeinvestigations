#include "global.h"
#include "assertf.h"
#include "constants/characters.h"
#include "constants/evidence.h"
#include "constants/field_weather.h"
#include "constants/item.h"
#include "constants/items.h"
#include "event_data.h"
#include "evidence.h"
#include "field_weather.h"
#include "gba/io_reg.h"
#include "gba/isagbprint.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "line_break.h"
#include "list_menu.h"
#include "main.h"
#include "bg.h"
#include "metaprogram.h"
#include "pokemon_summary_screen.h"
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

#define MAX_SELECTIONS 2

#define TASK_DATA(...) struct { s16 __VA_ARGS__; } *tData = (void *)gTasks[taskId].data
#define TASK_DATA_N(n,...) struct { s16 __VA_ARGS__; } *tData = (void *)&gTasks[taskId].data[n]

#define LOGIC_MENU_BORDER_TILE 1
#define LOGIC_MENU_DIALOG_TILE 270

enum {

    LOGIC_TAG_P1 = 0x2000,
    LOGIC_TAG_P2,
    LOGIC_TAG_CON,
    LOGIC_TAG_SCROLL_ARROW,

};

struct LogicMenuState
{
    MainCallback savedCallback;
    struct WindowTemplate* winTempls;
    struct ListMenuItem* evidence;
    u8 spriteIds[MAX_SELECTIONS + 1];
    u8 scrollIndicatorTask;
    u8 loadState;
    u8 maxSelections;
    u8 remainingSelections;
    u8 helpWinId;
    u32 selected[MAX_SELECTIONS];
};

struct LogicMenuPrint {
    u8 window;
    u8 x;
    u8 y;
    const u8* text;
    union TextColor color;
    u8 font;
};

enum WindowIds
{
    WIN_LOGIC_LIST,
    WIN_LOGIC_MSG,
    WIN_LOGIC_DESC,
    WIN_LOGIC_NAME,
    WIN_LOGIC_HINTS,
    WIN_LOGIC_COUNT
};

static EWRAM_DATA struct LogicMenuState *sLogicMenuState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sLogicMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .priority = 2
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 14,
        .priority = 3
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .priority = 1
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 0,
    }
};

static const struct WindowTemplate sLogicMenuWindowTemplates[] = {
    [WIN_LOGIC_LIST] =
        {
            .bg = 0,
            .tilemapLeft = 2,
            .tilemapTop = 1,
            .width = 11,
            .height = 15,
            .paletteNum = 15,
            .baseBlock = 1,
        },

    [WIN_LOGIC_MSG] =
        {
            .bg = 2,
            .tilemapLeft = 2,
            .tilemapTop = 15,
            .width = 26,
            .height = 4,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_LOGIC_DESC] =
        {
            .bg = 0,
            .tilemapLeft = 16,
            .tilemapTop = 13,
            .width = 9,
            .height = 7,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_LOGIC_NAME] =
        {
            .bg = 0,
            .tilemapLeft = 0,
            .tilemapTop = 0,
            .width = 1,
            .height = 1,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    [WIN_LOGIC_HINTS] =
        {
            .bg = 0,
            .tilemapLeft = 1,
            .tilemapTop = 16,
            .width = 13,
            .height = 2,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sLogicMsgWinTemplHelp = {
    .bg = 3,
    .tilemapLeft = 2,
    .tilemapTop = 3,
    .width = 26,
    .height = 14,
    .paletteNum = 15,
    .baseBlock = 10,
};

static const u32 sLogicMenuTiles[] = INCBIN_U32("graphics/evidence_menu/wizbook/tiles.4bpp.smol");
static const u32 sLogicMenuTilemap[] = INCBIN_U32("graphics/evidence_menu/wizbook/map.bin.smolTM");
static const u16 sLogicMenuPalette[] = INCBIN_U16("graphics/evidence_menu/wizbook/palette_01.gbapal", "graphics/evidence_menu/wizbook/palette_02.gbapal");

enum FontColor
{
    FONT_BLACK,
    FONT_BLUE,
    FONT_GREEN,
    FONT_RED,
};

static const struct ListMenuTemplate sLogicMenuListTemplate =
{
    .item_X = 10,
    .cursor_X = 2,
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

static union TextColor sLogicMenuWindowFontColors[] = {
    [FONT_BLACK] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_DARK_GRAY,
            .shadow = TEXT_COLOR_LIGHT_GRAY,
        },
    [FONT_BLUE] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_BLUE,
            .shadow = TEXT_COLOR_LIGHT_BLUE,
        },
    [FONT_RED] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_RED,
            .shadow = TEXT_COLOR_LIGHT_RED,
        },
    [FONT_GREEN] =
        {
            .background = TEXT_COLOR_TRANSPARENT,
            .foreground = TEXT_COLOR_GREEN,
            .shadow = TEXT_COLOR_LIGHT_GREEN,
        },
};

enum {
    EVD_POS_LEFT,
    EVD_POS_RIGHT,
    EVD_POS_RESULT,
};

static const struct Coords16 sLogicMenuIconPos[3] = {
    [EVD_POS_LEFT] = {153, 44},
    [EVD_POS_RIGHT] = {186, 44},
    [EVD_POS_RESULT] = {169, 76},
};

static const u8 sText_DeductionSuccess[] = _("Deduction Successful. Recieved new evidence:\n{STR_VAR_1}");

static void LogicMenu_SetupCB(void);
static void LogicMenu_MainCB(void);
static void LogicMenu_VBlankCB(void);

static void Task_LogicMenuWaitFadeIn(u8 taskId);
static void Task_LogicMenuInitList(u8 taskId);
static void Task_LogicMenuMainInput(u8 taskId);
static void Task_LogicMenuHandleDeduction(u8 taskId);
static void Task_LogicMenuWaitFadeAndExit(u8 taskId);
static void Task_HelpWinInput(u8 taskId);

static void LogicMenu_Init(MainCallback callback);
static void LogicMenu_ResetGpuRegsAndBgs(void);
static bool8 LogicMenu_InitBgs(void);
static void LogicMenu_FadeAndBail(void);
static bool8 LogicMenu_LoadGraphics(void);
static void LogicMenu_InitWindows(void);
static u32 CreateEvidenceListMenu(struct ListMenuTemplate* t);
static void DrawLogicMenuMsgWin(u8 winId);
static void LogicMenuPrintMsg(struct LogicMenuPrint *p);
static u32 CreateEvidenceIcon(u32 pos, u32 input);
static void DestroyEvidenceIcon(u32 pos);
static void DestroyAllEvidenceIcons(void);
static void RedrawEvidenceIcons(void);
static u32 GetListMaxShowable(struct ListMenuTemplate* t);
static void LogicMenuList_PrintFunc(const struct ListMenu *list, u32 index, u8 y);
static void PrintDescription(enum Item id);
static void PrintDeductionMessage(struct EvidenceInfo e);
static void ClearLogicMenuWinMsg(u8 winId);
static void PrintLogicMenuHints(u32 color);
static void PrintLogicMenuItemName(enum Item item);
static u32 FillEvdList(struct ListMenuItem *items);
static u32 AddLogicMenuScrollArrows(struct ListMenu *list);
static u32 DrawLogicMenuHelpWindow(const struct WindowTemplate *t, const u8 *string, bool32 autoBreak);

static void LogicMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void LogicMenu_FreeResources(void);


void CB2_InitLogicMenu(void)
{
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_OpenLogicMenu, 1);
}

void Task_OpenLogicMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        LogicMenu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void LogicMenu_Init(MainCallback callback)
{
    sLogicMenuState = AllocZeroed(sizeof(struct LogicMenuState));
    if (sLogicMenuState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    for (u32 i = 0; i < MAX_SELECTIONS; i++)
        sLogicMenuState->spriteIds[i] = SPRITE_NONE;

    sLogicMenuState->loadState = 0;
    sLogicMenuState->savedCallback = callback;
    sLogicMenuState->maxSelections = MAX_SELECTIONS;
    sLogicMenuState->remainingSelections = sLogicMenuState->maxSelections;

    SetMainCallback2(LogicMenu_SetupCB);
}

static void LogicMenu_ResetGpuRegsAndBgs(void)
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

static void LogicMenu_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        LogicMenu_ResetGpuRegsAndBgs();
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
        if (LogicMenu_InitBgs())
        {
            sLogicMenuState->loadState = 0;
            gMain.state++;
        }
        else
        {
            LogicMenu_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (LogicMenu_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        LogicMenu_InitWindows();
        gMain.state++;
        break;
    case 5:
        CreateTask(Task_LogicMenuWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(LogicMenu_VBlankCB);
        SetMainCallback2(LogicMenu_MainCB);
        break;
    }
}

static void Task_LogicMenuMainInput(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);

    struct ListMenu* list = (void*) gTasks[tData->listTaskId].data;

    if (JOY_NEW(SELECT_BUTTON))
    {
        PlaySE(SE_SUCCESS);
        sLogicMenuState->helpWinId = DrawLogicMenuHelpWindow(&sLogicMsgWinTemplHelp, COMPOUND_STRING(
            "Select 2 pieces of evidence that and connect\n"
            "them to deduce new evidence. Deductions\n"
            "reveal more information and help\n"
            "you solve the mystery\n"
            "\n"
            "{A_BUTTON} Toggle evidence on or off\n"
            "{START_BUTTON} Deduce new evidence\n"
            "{SELECT_BUTTON} Open or close help menu"
        ), FALSE);
        RemoveScrollIndicatorArrowPair(sLogicMenuState->scrollIndicatorTask);
        gTasks[taskId].func = Task_HelpWinInput;
    }


    s32 input = ListMenu_ProcessInput(tData->listTaskId);
    switch (input)
    {
    case LIST_HEADER:
        break;
    case LIST_NOTHING_CHOSEN:
        if(JOY_NEW(START_BUTTON))
            {
                tData->state = 0;
                tData->p1 = sLogicMenuState->selected[0];
                tData->p2 = sLogicMenuState->selected[1];
                if (sLogicMenuState->maxSelections - sLogicMenuState->remainingSelections < 2)
                {
                    PlaySE(SE_FAILURE);
                    break;
                }
                gTasks[taskId].func = Task_LogicMenuHandleDeduction;
            }
        break;
    case LIST_CANCEL:
        if (!gTasks[taskId].data[1])
        {
            gSpecialVar_Result = MULTI_B_PRESSED;
            FadeScreen(FADE_TO_BLACK, 0);
            gTasks[taskId].func = Task_LogicMenuWaitFadeAndExit;
        }
        break;
    default: {
        PlaySE(SE_SELECT);
        u32 max = sLogicMenuState->maxSelections;
        u8 *count = &sLogicMenuState->remainingSelections;
        u32 found = lsearch(&input, sLogicMenuState->selected, max);
        if (found != UINT32_MAX)
        {
            size_t s = (sizeof(sLogicMenuState->selected[0]) * (max - (found + 1)));
            u32 *listptr = &sLogicMenuState->selected[found];
            memmove(listptr, listptr + 1, s);
            sLogicMenuState->selected[max - 1] = 0xFF;
            (*count)++;
            goto finish;
        }

        if (*count == 0)
            break;
        u32 pos = max - *count;
        assertf(pos < 2);
        sLogicMenuState->selected[pos] = input;
        (*count)--;

    finish:
        RedrawEvidenceIcons();
        ListMenuRedrawRow(list, list->selectedRow);
        u32 color = 0;
        if (sLogicMenuState->maxSelections - sLogicMenuState->remainingSelections >= 2)
            color = sLogicMenuWindowFontColors[FONT_GREEN].asU32;
        else
            color = sLogicMenuWindowFontColors[FONT_RED].asU32;
        PrintLogicMenuHints(color);
        gSpecialVar_Result = input;
        break;
    }
    }
}

static void Task_LogicMenuHandleDeduction(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);
    struct ListMenu *list = (void *)gTasks[tData->listTaskId].data;

    switch (tData->state)
    {
    case 0: {

        enum Evidence e = GetDeduction(tData->p1 - ITEM_EVIDENCE_START,
                                       tData->p2 - ITEM_EVIDENCE_START);

        struct EvidenceInfo c = gEvidence[e];

        if (e == EVD_COUNT || CheckBagHasItem(c.itemId, 1))
        {
            PlaySE(SE_FAILURE);
            gTasks[taskId].func = Task_LogicMenuMainInput;
            return;
        }


        if (CheckBagHasSpace(c.itemId, 1))
            AddBagItem(c.itemId, 1);

        PlaySE(SE_SHINY);
        RemoveScrollIndicatorArrowPair(sLogicMenuState->scrollIndicatorTask);
        PrintDeductionMessage(c);
        sLogicMenuState->spriteIds[EVD_POS_RESULT] =
            CreateEvidenceIcon(EVD_POS_RESULT, c.itemId);
        ShowBg(2);
        tData->state++;
        break;
    }
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            sLogicMenuState->remainingSelections = sLogicMenuState->maxSelections;
            memset(sLogicMenuState->selected, 0xFF, sizeof(sLogicMenuState->selected));
            DestroyAllEvidenceIcons();
            DestroyEvidenceIcon(EVD_POS_RESULT);

            u32 evdCount = FillEvdList(sLogicMenuState->evidence);
            list->template.totalItems = evdCount;
            list->template.items = sLogicMenuState->evidence;

            u32 maxShowable = GetListMaxShowable(&list->template);
            if (list->template.totalItems > maxShowable)
            {
                if (list->selectedRow > maxShowable / 2)
                    list->selectedRow = maxShowable / 2;
                list->template.maxShowed = maxShowable;
            }
            else
            {
                list->template.maxShowed = list->template.totalItems;
            }
            tData->state++;
        }
        break;
    case 2:
        ClearLogicMenuWinMsg(WIN_LOGIC_MSG);
        HideBg(2);
        sLogicMenuState->scrollIndicatorTask = AddLogicMenuScrollArrows(list);
        PrintLogicMenuHints(sLogicMenuWindowFontColors[FONT_RED].asU32);
        RedrawListMenu(tData->listTaskId);
        gTasks[taskId].func = Task_LogicMenuMainInput;
    }
}

static void LogicMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void LogicMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_LogicMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ClearTaskData(taskId);
        PlayNewMapMusic(MUS_LOGIC);
        gTasks[taskId].func = Task_LogicMenuInitList;
    }
}

static void Task_LogicMenuInitList(u8 taskId)
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
        gTasks[taskId].func = Task_LogicMenuMainInput;
        struct ListMenu *list = (void *)gTasks[listTaskId].data;
        ListMenuChangeSelectionFull(list, TRUE, FALSE, 0, TRUE);
    }
    }
}

static void LogicMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    PrintDescription(itemIndex);
}

static const struct ScrollArrowsTemplate sEvidenceMenuScrollArrowTemplate =
{
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 64,
    .firstY = 16,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 64,
    .secondY = 126,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 0,
    .tileTag = LOGIC_TAG_SCROLL_ARROW,
    .palTag = LOGIC_TAG_SCROLL_ARROW,
    .palNum = 0,
};

static u32 CreateEvidenceListMenu(struct ListMenuTemplate* template)
{

    sLogicMenuState->evidence = AllocZeroed(sizeof(struct ListMenuItem) * gBagPockets[POCKET_EVIDENCE].capacity);

    if (sLogicMenuState->evidence == NULL) {
        LogicMenu_FadeAndBail(); 
        return 1;
    }
    struct ListMenuItem* items = sLogicMenuState->evidence;

    u32 evdCount = FillEvdList(items);

    struct ListMenuTemplate* t = &gMultiuseListMenuTemplate;
    *t = sLogicMenuListTemplate;
    t->items = items;
    t->windowId = WIN_LOGIC_LIST;
    t->totalItems = evdCount;
    t->maxShowed = GetListMaxShowable(t);
    t->moveCursorFunc = LogicMenu_MoveCursorFunc;
    t->itemPrintFunc  = LogicMenuList_PrintFunc;

    u32 listTaskId = ListMenuInit(template, 0, 0);
    struct ListMenu* list = (void*)gTasks[listTaskId].data;

    sLogicMenuState->scrollIndicatorTask = AddLogicMenuScrollArrows(list);

    return  listTaskId;
}

static u32 AddLogicMenuScrollArrows(struct ListMenu *list)
{
    gTempScrollArrowTemplate = sEvidenceMenuScrollArrowTemplate;
    gTempScrollArrowTemplate.fullyUpThreshold = 0;
    gTempScrollArrowTemplate.fullyDownThreshold =
        list->template.totalItems - list->template.maxShowed;

     return AddScrollIndicatorArrowPair(
        &gTempScrollArrowTemplate, &list->scrollOffset);
}

static u32 FillEvdList(struct ListMenuItem *items)
{
    u32 evdCount = BagPocket_CountUsedItemSlots(&gBagPockets[POCKET_EVIDENCE]);

    for (int i = 0; i < evdCount; i++)
    {
        struct EvidenceInfo e =
            gEvidence[GetBagItemId(POCKET_EVIDENCE, i) - ITEM_EVIDENCE_START];

        items[i] = (struct ListMenuItem){e.name, e.itemId};
    }

    return evdCount;
}

static u32 CreateEvidenceIcon(u32 pos, u32 itemId)
{
    u32 id = AddItemIconSprite(LOGIC_TAG_P1 + pos, LOGIC_TAG_P1 + pos, itemId);
    struct Sprite* sprite = &gSprites[id];
    sprite->x = sLogicMenuIconPos[pos].x;
    sprite->y = sLogicMenuIconPos[pos].y;
    return id;
}

static void DestroyEvidenceIcon(u32 pos)
{
    FreeSpriteTilesByTag(LOGIC_TAG_P1 + pos);
    FreeSpritePaletteByTag(LOGIC_TAG_P1 + pos);
    DestroySprite(&gSprites[sLogicMenuState->spriteIds[pos]]);
    sLogicMenuState->spriteIds[pos] = SPRITE_NONE;
}

static void DestroyAllEvidenceIcons(void)
{
    for (int i = 0; i < MAX_SELECTIONS; i++) {
        if (sLogicMenuState->spriteIds[i] != SPRITE_NONE)
            DestroyEvidenceIcon(i);
    }
}

static void RedrawEvidenceIcons(void)
{
    u32 numSelected =
        sLogicMenuState->maxSelections - sLogicMenuState->remainingSelections;

    DestroyAllEvidenceIcons();

    for (u32 i = 0; i < numSelected; i++)
    {
        sLogicMenuState->spriteIds[i] =
            CreateEvidenceIcon(i, sLogicMenuState->selected[i]);
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

static void LogicMenuList_PrintFunc(const struct ListMenu *list, u32 index,
                                    u8 y)
{
    const struct ListMenuTemplate *templ = &list->template;
    const struct ListMenuItem *item = &templ->items[index];
    u32 windowId = templ->windowId;
    u32 id = item->id;

    bool32 selected = lsearch(&id,
                              sLogicMenuState->selected,
                              sLogicMenuState->maxSelections) != UINT32_MAX;

    const u32 color = selected ? sLogicMenuWindowFontColors[FONT_BLUE].asU32
                               : sLogicMenuWindowFontColors[FONT_BLACK].asU32;

    const u8 *name = item->name;

    u8 fontId =
        GetFontIdToFit(name, FONT_SMALL_NARROW, 0, templ->textNarrowWidth);
    u32 x = (id == LIST_HEADER) ? templ->header_X : templ->item_X;

    struct LogicMenuPrint p = {
        .font = fontId,
        .text = name,
        .window = windowId,
        .x = x,
        .y = y,
        .color.asU32 = color,
    };

    LogicMenuPrintMsg(&p);

    if (!selected || id == MULTISELECT_CONFIRM)
        return;

    u8 symBuffer[16];
    StringExpandPlaceholders(symBuffer, gText_CircleDot);

    u32 circleX = GetStringWidth(fontId, name, 0) +
                  GetStringWidth(fontId, symBuffer, 0) + 4;

    p.x = circleX;
    p.text = symBuffer;
    LogicMenuPrintMsg(&p);
}

static void Task_LogicMenuWaitFadeAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sLogicMenuState->savedCallback);
        LogicMenu_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 LogicMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sLogicMenuBgTemplates, NELEMS(sLogicMenuBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void LogicMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_LogicMenuWaitFadeAndExit, 0);
    SetVBlankCallback(LogicMenu_VBlankCB);
    SetMainCallback2(LogicMenu_MainCB);
}

static bool8 LogicMenu_LoadGraphics(void)
{
    switch (sLogicMenuState->loadState)
    {
    case 0:
        DecompressAndLoadBgGfxUsingHeap(1, sLogicMenuTiles, 0, 0, 0);
        sLogicMenuState->loadState++;
        break;
    case 1:
        DecompressDataWithHeaderWram(sLogicMenuTilemap, sBg1TilemapBuffer);
        sLogicMenuState->loadState++;
        break;
    case 2:
        LoadBgTiles(3, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, LOGIC_MENU_BORDER_TILE);
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(sLogicMenuPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP * 2);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sLogicMenuState->loadState++;
    default:
        sLogicMenuState->loadState = 0;
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

static void UNUSED DrawLogicMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
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

    FillBgTilemapBufferRect(bg, topLeft,     winLeft - 1,     winTop - 1,      1,     1,      0);
    FillBgTilemapBufferRect(bg, top,         winLeft,         winTop - 1,      width, 1,      0);
    FillBgTilemapBufferRect(bg, topRight,    winLeft + width, winTop - 1,      1,     1,      0);
    FillBgTilemapBufferRect(bg, left,        winLeft - 1,     winTop,          1,     height, 0);
    FillBgTilemapBufferRect(bg, right,       winLeft + width, winTop,          1,     height, 0);
    FillBgTilemapBufferRect(bg, bottomLeft,  winLeft - 1,     winTop + height, 1,     1,      0);
    FillBgTilemapBufferRect(bg, bottom,      winLeft,         winTop + height, width, 1,      0);
    FillBgTilemapBufferRect(bg, bottomRight, winLeft + width, winTop + height, 1,     1,      0);

    CopyBgTilemapBufferToVram(bg);
}

static void LogicMenu_InitWindows(void)
{
    InitWindows(sLogicMenuWindowTemplates);

    u32 windowId = 0;
    SetWindowAttribute(windowId, WINDOW_BASE_BLOCK, 1);
    while (GetWindowAttribute(windowId, WINDOW_BG) != 0xFF) { 
        u32 b = GetWindowAttribute(windowId, WINDOW_BASE_BLOCK);
        u32 w = GetWindowAttribute(windowId, WINDOW_WIDTH);
        u32 h = GetWindowAttribute(windowId, WINDOW_HEIGHT);
        SetWindowAttribute(++windowId, WINDOW_BASE_BLOCK, b+h*w);
    }
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WIN_LOGIC_LIST, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    DrawLogicMenuMsgWin(WIN_LOGIC_MSG);
    PrintLogicMenuHints(sLogicMenuWindowFontColors[FONT_RED].asU32);
    for (int i = 0; i < WIN_LOGIC_COUNT; i++)
    {
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static void DrawLogicMenuMsgWin(u8 winId)
{
    LoadMessageBoxGfx(winId, LOGIC_MENU_DIALOG_TILE, BG_PLTT_ID(15));
    DrawDialogFrameWithCustomTile(winId, TRUE, LOGIC_MENU_DIALOG_TILE);
    CopyWindowToVram(winId, COPYWIN_FULL);
}

static void ClearLogicMenuWinMsg(u8 winId)
{
    LoadMessageBoxGfx(winId, LOGIC_MENU_DIALOG_TILE, BG_PLTT_ID(15));
    DrawDialogFrameWithCustomTile(winId, TRUE, LOGIC_MENU_DIALOG_TILE);
    CopyWindowToVram(winId, COPYWIN_GFX);
}

static void PrintDeductionMessage(struct EvidenceInfo e)
{
    gTextFlags.canABSpeedUpPrint = TRUE;
    struct LogicMenuPrint p = {
        .font = FONT_SMALL,
        .window = WIN_LOGIC_MSG,
        .text = gStringVar4,
        .color = sLogicMenuWindowFontColors[FONT_BLACK],
    };
    StringCopy(gStringVar1, GetItemName(e.itemId));
    StringExpandPlaceholders(gStringVar4, sText_DeductionSuccess);
    LogicMenuPrintMsg(&p);
}

static void PrintDescription(enum Item id)
{
    FillWindowPixelBuffer(WIN_LOGIC_DESC, PIXEL_FILL(0));
    struct LogicMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_LOGIC_DESC,
        .x = 0,
        .y = 0,
        .text = gStringVar4,
        .color = {{
            TEXT_COLOR_TRANSPARENT,
            TEXT_COLOR_DARK_GRAY,
            TEXT_COLOR_LIGHT_GRAY,
        }},
    };
    StringCopy(gStringVar4, GetItemDescription(id));
    StripLineBreaks(gStringVar4);
    u32 w = GetWindowAttribute(p.window, WINDOW_WIDTH)*8;
    BreakStringAutomatic(gStringVar4, w, 8, p.font, HIDE_SCROLL_PROMPT);
    LogicMenuPrintMsg(&p);
}

static void PrintLogicMenuHints(u32 color)
{
    const u8 fontId = FONT_SMALL_NARROWER;
    const u8* text = COMPOUND_STRING("{START_BUTTON} Deduce! {SELECT_BUTTON} Info");
    s16 x = GetStringRightAlignXOffset(fontId, text, GetWindowAttribute(WIN_LOGIC_HINTS, WINDOW_WIDTH) * 8);
    FillWindowPixelBuffer(WIN_LOGIC_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct LogicMenuPrint p = {
        .font = fontId,
        .window = WIN_LOGIC_HINTS,
        .x = x,
        .y = 3,
        .text = text,
        .color.asU32 = color,
    };
    LogicMenuPrintMsg(&p);



    CopyWindowToVram(WIN_LOGIC_HINTS, COPYWIN_GFX);
}

static void UNUSED PrintLogicMenuItemName(enum Item item)
{
    FillWindowPixelBuffer(WIN_LOGIC_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    struct LogicMenuPrint p = {
        .font = FONT_SMALL_NARROWER,
        .window = WIN_LOGIC_NAME,
        .x = 0,
        .y = 0,
        .text = GetItemName(item),
        .color = sLogicMenuWindowFontColors[FONT_BLACK],
    };
    LogicMenuPrintMsg(&p);
    CopyWindowToVram(WIN_LOGIC_NAME, COPYWIN_GFX);
}

static void LogicMenuPrintMsg(struct LogicMenuPrint *p)
{
    const u8 colors[3] = {
        (p->color.asU32 & 0xFF),
        ((p->color.asU32 >> 8) & 0xFF),
        ((p->color.asU32 >> 16) & 0xFF),
    };
    AddTextPrinterParameterized4(p->window, p->font, p->x, p->y, 0, 0, colors, 0, p->text);
}

static u32 DrawLogicMenuHelpWindow(const struct WindowTemplate *t, const u8 *string, bool32 autoBreak)
{
    u32 msgWin = AddWindow(t);
    FillWindowPixelBuffer(msgWin, PIXEL_FILL(1));
    DrawLogicMenuWindowBorder(t, LOGIC_MENU_BORDER_TILE);
    PutWindowTilemap(msgWin);

    union TextColor c = {{
        .background = 0,
        .foreground = 2,
        .shadow = 3,
    }};

    struct LogicMenuPrint p = {
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

    LogicMenuPrintMsg(&p);
    CopyWindowToVram(msgWin, COPYWIN_FULL);
    SetGpuReg(REG_OFFSET_BLDCNT,
              (BLDCNT_TGT1_ALL & ~BLDCNT_TGT1_BG3) | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 10);
    ShowBg(3);
    return msgWin;
}

static void Task_HelpWinInput(u8 taskId)
{
    TASK_DATA(state, listTaskId, p1, p2);

    if (JOY_NEW(A_BUTTON | SELECT_BUTTON))
    {
        struct ListMenu *list = (void *)gTasks[tData->listTaskId].data;
        HideBg(3);
        sLogicMenuState->scrollIndicatorTask = AddLogicMenuScrollArrows(list);
        RedrawListMenu(tData->listTaskId);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        gTasks[taskId].func = Task_LogicMenuMainInput;
    }
}

static void LogicMenu_FreeResources(void)
{
    TRY_FREE_AND_SET_NULL(sLogicMenuState->evidence);
    TRY_FREE_AND_SET_NULL(sLogicMenuState);
    TRY_FREE_AND_SET_NULL(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
    ResetSpriteData();
}
