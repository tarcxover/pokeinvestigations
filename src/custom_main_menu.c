#include "global.h"
#include "assertf.h"
#include "bg.h"
#include "constants/characters.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/pokedex.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "custom_credits.h"
#include "data.h"
#include "decompress.h"
#include "even_sprite.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "evidence.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "gba/types.h"
#include "global.fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "intro.h"
#include "main.h"
#include "m4a.h"
#include "custom_main_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "random.h"
#include "region_map.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "util.h"
#include "window.h"

#define CMM_BUTTON_SPRITE_COUNT 3
#define MON_ICON_PAL_COUNT 6

enum CmmBgs {
    WIN_CMM_BG = 0,
    WIN_CMM_NO_SAVE = 0,
    WIN_CMM_NAME
};

enum {
    CMM_PALTAG_BUTTON = 0x1000,
    CMM_PALTAG_ACTIVE_BUTTON = 0x1001,
    CMM_PALTAG_PLAYER = 0x1002,
    CMM_PALTAG_BADGES1 = 0x1003,
    CMM_PALTAG_BADGES2 = 0x1004,
};

enum CmmTokens {
    BOTTLED_TOKEN,
    CARVED_TOKEN,
    SEWN_TOKEN,
    FORGED_TOKEN,
    CAPTURED_TOKEN,
    FOLDED_TOKEN,
    POLISHED_TOKEN,
    CHERISHED_TOKEN,
};

enum CmmTileTags {
    CMM_TILETAG_BUTTON1  = 0x2000,
    CMM_TILETAG_BUTTON2  = 0x2001,
    CMM_TILETAG_BUTTON3  = 0x2002,
    CMM_TILETAG_PLAYER   = 0x2003,
    CMM_TILETAG_BOTTLED  = 0x2004,
    CMM_TILETAG_CARVED   = 0x2005,
    CMM_TILETAG_SEWN     = 0x2006,
    CMM_TILETAG_FORGED   = 0x2007,
    CMM_TILETAG_CAPTURED = 0x2008,
    CMM_TILETAG_FOLDED   = 0x2009,
    CMM_TILETAG_POLISHED = 0x200A,
    CMM_TILETAG_FANG     = 0x200B,
};

enum CmmButtonIds {
    CMM_BUTTON_NEWGAME,
    CMM_BUTTON_OPTIONS,
    CMM_BUTTON_CREDITS,
    CMM_BUTTON_INFOBOX,
    CMM_BUTTON_COUNT,
};

enum CmmDirs {
    CMM_DIR_RIGHT,
    CMM_DIR_LEFT,
    CMM_DIR_UP,
    CMM_DIR_DOWN,
};

enum CmmMenuType {
    CMM_HAS_SAVE,
    CMM_NO_SAVE,
};

struct CmmState {
    MainCallback savedCallback;
    enum CmmMenuType menuType;
    u8 loadState;
    u8 partyIconId[PARTY_SIZE];
    u8 playerSpriteId;
    u8 buttonSpriteId[CMM_BUTTON_SPRITE_COUNT];
    enum CmmButtonIds activeButton;
    enum CmmButtonIds prevButton;
};

struct CmmMemory {
    struct CmmState state;
    u8 sBg1TilemapBuffer[2048];
    u8 sBg2TilemapBuffer[2048];
    ALIGNED(4) u16 sTempPaletteBuffer[PLTT_BUFFER_SIZE];
};

static EWRAM_DATA struct CmmMemory* sCmmMemory = NULL;

static const struct BgTemplate sCmmBgTemplates[] = {
    {.bg = 0, .charBaseIndex = 0, .mapBaseIndex = 30, .priority = 1},
    {.bg = 1, .charBaseIndex = 3, .mapBaseIndex = 31, .priority = 2},
    {.bg = 2, .charBaseIndex = 2, .mapBaseIndex = 29, .priority = 3},
};

static const struct WindowTemplate sCmmWindowTemplates[] = {
    [WIN_CMM_BG] =
        {.bg = 0, .tilemapLeft = 4, .tilemapTop = 12, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 1},

    [WIN_CMM_NAME] =
        {.bg = 0, .tilemapLeft = 1, .tilemapTop = 10, .width = 9, .height = 2, .paletteNum = 15, .baseBlock = 1 + 66},
    DUMMY_WIN_TEMPLATE};

static const struct WindowTemplate sCmmErrorWindowTemplate[] = {
    [0] = {.bg = 0, .tilemapLeft = 4, .tilemapTop = 5, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 1},
    DUMMY_WIN_TEMPLATE};

static const u32 CmmBgTiles[] = INCGFX_U32("graphics/custom_main_menu/main_bg/tiles.png", ".4bpp.smol");
static const u32 CmmBgTilemap[] = INCBIN_U32("graphics/custom_main_menu/main_bg/map.bin.smolTM");
static const u16 CmmBgPalette[] = INCGFX_U16("graphics/custom_main_menu/main_bg/inactive.pal", ".gbapal");
static const u16 CmmBgActivePalette[] = INCGFX_U16("graphics/custom_main_menu/main_bg/palette_00.pal", ".gbapal");
static const u16 CmmMsgboxPal[] = INCGFX_U16("graphics/custom_main_menu/main_bg/msgbox.pal", ".gbapal");

static const u32 CmmScrollingBgTiles[] = INCGFX_U32("graphics/custom_main_menu/scrolling_bg/tiles.png", ".4bpp.smol");
static const u32 CmmScrollingBgTilemap[] = INCBIN_U32("graphics/custom_main_menu/scrolling_bg/map.bin.smolTM");
static const u16 CmmScrollingBgPalette[] = INCGFX_U16("graphics/custom_main_menu/scrolling_bg/palette_01.pal", ".gbapal");

static const u32 sMenuButtonGfx[] = INCGFX_U32("graphics/custom_main_menu/buttons/button.png", ".4bpp.smol");
static const u16 sMenuButtonPal[] = INCGFX_U16("graphics/custom_main_menu/buttons/button.png", ".gbapal");
static const u16 sMenuButtonActivePal[] = INCGFX_U16("graphics/custom_main_menu/buttons/button.png", ".gbapal");

static const u32 sMenuBottledTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/bottled.png", ".4bpp.smol");
static const u32 sMenuCarvedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/carved.png", ".4bpp.smol");
static const u32 sMenuSewnTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/sewn.png", ".4bpp.smol");
static const u32 sMenuForgedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/forged.png", ".4bpp.smol");
static const u32 sMenuCapturedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/captured.png", ".4bpp.smol");
static const u32 sMenuFoldedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/folded.png", ".4bpp.smol");
static const u32 sMenuPolishedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/polished.png", ".4bpp.smol");
static const u32 sMenuCherishedTokenGfx[] = INCGFX_U32("graphics/custom_main_menu/badges/cherished.png", ".4bpp.smol");
static const u16 sMenuBadgesPal1[] = INCGFX_U16("graphics/custom_main_menu/badges/badges1.pal", ".gbapal");
static const u16 sMenuBadgesPal2[] = INCGFX_U16("graphics/custom_main_menu/badges/badges2.pal", ".gbapal");

static const u32 sPlayerGirlGfx[] = INCGFX_U32("graphics/custom_main_menu/mugshots/edgeworth.png", ".4bpp.smol");
static const u16 sPlayerGirlPal[] = INCGFX_U16("graphics/custom_main_menu/mugshots/edgeworth.png", ".gbapal");
static const u32 sPlayerBoyGfx[] = INCGFX_U32("graphics/custom_main_menu/mugshots/edgeworth.png", ".4bpp.smol");
static const u16 sPlayerBoyPal[] = INCGFX_U16("graphics/custom_main_menu/mugshots/edgeworth.png", ".gbapal");

enum FontColor { FONT_WHITE, FONT_GRAY, FONT_PLAYER };
static const u8 CmmWindowFontColors[][3] = {
    [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    [FONT_GRAY] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    [FONT_PLAYER] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
};

static const u16 sDynamicTextColor[] = {
    [TEXT_DYNAMIC_COLOR_1]   = 0x000035D2,
    [TEXT_DYNAMIC_COLOR_2]   = 0x35D2,
};

#define CMM_FONT_COLOR(_x) CmmWindowFontColors[_x]

// Callbacks
static void Cmm_SetupCB(void);
static void Cmm_MainCB(void);
static void Cmm_VBlankCB(void);

// Tasks
static void Task_CmmWaitFadeIn(u8 taskId);
static void Task_CmmInput(u8 taskId);
static void Task_CmmWaitFadeAndBail(u8 taskId);
static void Task_CmmWaitFadeAndExitGracefully(u8 taskId);
static void Task_CmmScrollBg(u8 taskId);

// Helper Functions
static inline void Cmm_ResetForInit(void);
static void Cmm_Init(MainCallback callback, enum CmmButtonIds activeButton);
static void Cmm_ResetGpuRegsAndBgs(void);
static bool8 Cmm_InitBgs(void);
static bool8 Cmm_LoadGraphics(void);
static void Cmm_InitWindows(void);
static void Cmm_StartFade(u32 color);
static void Cmm_FadeAndBail(void);
static void Cmm_FreeResources(void);
static enum CmmMenuType Cmm_GetMenuType(void);
static void Cmm_DrawContinueMenuItems(void);
static bool32 Cmm_IsContinueMenu(void);

static void Cmm_PrintInfoboxText(void);
static void Cmm_PrintContinueInfo(const u8 *color);
static void Cmm_PrintNoSaveInfo(const u8 *color);
static void Cmm_FormatSavegameTime(void);
static void Cmm_PrintPlayerName(void);
static const u8* Cmm_GetInfoboxFontColor(void);
static const u8* Cmm_GetPlayerNameFontColor(void);
static u32 Cmm_GetWindowWidth(u8 windowId);
static void Cmm_PrintText(u8 windowId, u8 font, u8 x, u8 y, const u8 *color, const u8 *str);
static inline void Cmm_PrintTextNormal(u8 windowId, u8 x, u8 y, const u8 *color, const u8 *str);
static inline void Cmm_PrintTextSmall(u8 windowId, u8 x, u8 y, const u8 *color, const u8 *str);

static void Cmm_CreatePlayerMugshot(s16 x, s16 y);
static void Cmm_DarkenPlayerMugshot(void);
static void Cmm_RestorePlayerMugshot(void);
static void Cmm_DrawPartyIcons(void);
static void Cmm_DarkenPartyIcons(void);

static u32 Cmm_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag);
static void Cmm_CreateAllMenuButtons();
static void Cmm_PrintButtonLabels(void);
static bool32 Cmm_IsSpriteButton(enum CmmButtonIds buttonId);

static void Cmm_SetInfoboxActive(bool32 active);
static void Cmm_SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag);
static void Cmm_ActivateButton(enum CmmButtonIds buttonId);
static void Cmm_DeactivateButton(enum CmmButtonIds buttonId);
static void Cmm_SetActiveButton(enum CmmButtonIds buttonId);
static void Cmm_MoveSelection(enum CmmDirs);

static void Cmm_HandleButtonPressA(void);
static void Cmm_HandleButtonPressB(void);
static void Cmm_ExitOnSelect(MainCallback callback);

void CB2_InitCustomMainMenu(void)
{
    Cmm_Init(CB2_InitTitleScreen, CMM_BUTTON_INFOBOX);
}

static void CB2_InitCustomMainMenuFromOptionsMenu(void)
{
    Cmm_Init(CB2_InitTitleScreen, CMM_BUTTON_OPTIONS);
}

static void Cmm_Init(MainCallback callback, enum CmmButtonIds activeButton)
{
    sCmmMemory = AllocZeroed(sizeof(struct CmmMemory));
    if (sCmmMemory == NULL) {
        SetMainCallback2(callback);
        return;
    }

    sCmmMemory->state.loadState = 0;
    sCmmMemory->state.savedCallback = callback;
    sCmmMemory->state.activeButton = activeButton;
    sCmmMemory->state.menuType = Cmm_GetMenuType();

    SetMainCallback2(Cmm_SetupCB);
}

static bool32 Cmm_IsContinueMenu(void)
{
    return sCmmMemory->state.menuType == CMM_HAS_SAVE;
}

static void Cmm_ResetGpuRegsAndBgs(void)
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

static inline void Cmm_ResetForInit(void)
{
    Cmm_ResetGpuRegsAndBgs();
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
}

static void Cmm_SetupCB(void)
{
    switch (gMain.state) {
        case 0:
            Cmm_ResetForInit();
            gMain.state++;
            break;
        case 1:
            if (Cmm_InitBgs()) {
                sCmmMemory->state.loadState = 0;
                gMain.state++;
            }
            else {
                Cmm_FadeAndBail();
                return;
            }
            break;
        case 2:
            if (Cmm_LoadGraphics() == TRUE) {
                gMain.state++;
            }
            break;
        case 3:
            Cmm_InitWindows();
            gMain.state++;
            break;
        case 4:
            Cmm_DrawContinueMenuItems();
            gMain.state++;
            break;
        case 5:
            Cmm_CreateAllMenuButtons();
            gMain.state++;
            break;
        case 6:
            Cmm_PrintButtonLabels();
            if (!Cmm_IsContinueMenu() && sCmmMemory->state.activeButton == CMM_BUTTON_INFOBOX) {
                sCmmMemory->state.activeButton = CMM_BUTTON_NEWGAME;
            }
            Cmm_SetActiveButton(sCmmMemory->state.activeButton);
            gMain.state++;
            break;
        case 7:
                CpuFastCopy(gPlttBufferUnfaded, sCmmMemory->sTempPaletteBuffer, sizeof(gPlttBufferUnfaded));
                CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, sizeof(gPlttBufferFaded));
            BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_BLACK);
            CreateTask(Task_CmmWaitFadeIn, 0);
            gMain.state++;
            break;
        case 8:
            CreateTask(Task_CmmScrollBg, 0);
            SetVBlankCallback(Cmm_VBlankCB);
            SetMainCallback2(Cmm_MainCB);
            break;
    }
}


static enum CmmMenuType Cmm_GetMenuType(void)
{
    switch (gSaveFileStatus) {
        case SAVE_STATUS_OK:
        case SAVE_STATUS_ERROR:
            return CMM_HAS_SAVE;
        default:
            return CMM_NO_SAVE;
    }
}

static void Task_CmmScrollBg(u8 taskId)
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

static void Cmm_DrawContinueMenuItems(void)
{
    if (!Cmm_IsContinueMenu())
        return;
    Cmm_CreatePlayerMugshot(15, 12);
    FreeMonIconPalettes();
    LoadMonIconPalettes();
    Cmm_DrawPartyIcons();
}

static void Cmm_CreateAllMenuButtons()
{
    const s16 startX = 8 + 32;
    const s16 startY = 120 + 16;

    for (u32 i = 0; i < CMM_BUTTON_SPRITE_COUNT; i++) {
        s16 x;
        x = startX + (i * 64 + i*16);
        sCmmMemory->state.buttonSpriteId[i] =
            Cmm_CreateMenuButton(x, startY, CMM_TILETAG_BUTTON1 + i, CMM_PALTAG_BUTTON);
    }

    u32 palIndex = IndexOfSpritePaletteTag(CMM_PALTAG_BUTTON);
    BlendPalette(OBJ_PLTT_ID(palIndex),16, 8, RGB_BLACK);
}

static void Cmm_CreatePlayerMugshot(s16 x, s16 y)
{
    const u32* playerSprite = gSaveBlock2Ptr->playerGender == FEMALE ? sPlayerGirlGfx : sPlayerBoyGfx;
    const u16* playerPal = gSaveBlock2Ptr->playerGender == FEMALE ? sPlayerGirlPal : sPlayerBoyPal;
    x+=32;
    y+=32;
    Even_CreateSpriteParametrized(playerSprite, CMM_TILETAG_PLAYER, playerPal, CMM_PALTAG_PLAYER, SPRITE_SIZE(64x64), SPRITE_SHAPE(64x64), x, y, 0, SpriteCallbackDummy, TRUE);
}

static void Cmm_DarkenPlayerMugshot(void)
{
    u16 index = IndexOfSpritePaletteTag(CMM_PALTAG_PLAYER);
    BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
}

static void Cmm_RestorePlayerMugshot(void)
{
    FreeSpritePaletteByTag(CMM_PALTAG_PLAYER);
    LoadSpritePaletteWithTag(sPlayerGirlPal, CMM_PALTAG_PLAYER);
}

static u32 Cmm_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag)
{
    return Even_CreateSpriteParametrized(sMenuButtonGfx, tileTag, sMenuButtonPal, palTag, SPRITE_SIZE(64x32),
                                         SPRITE_SHAPE(64x32), x, y, 0, SpriteCallbackDummy, TRUE);
}

static void Cmm_SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag)
{
    struct SpritePalette sp;
    sp.data = pal;
    sp.tag = palTag;
    LoadSpritePalette(&sp);
    u8 palIndex = IndexOfSpritePaletteTag(palTag);
    gSprites[buttonId].oam.paletteNum = palIndex;
}

static void Cmm_ActivateButton(enum CmmButtonIds buttonId)
{
    if (!Cmm_IsSpriteButton(buttonId))
        return;

    u8 spriteId = sCmmMemory->state.buttonSpriteId[buttonId];
    Cmm_SetButtonPalette(spriteId, sMenuButtonActivePal, CMM_PALTAG_ACTIVE_BUTTON);
}

static void Cmm_DeactivateButton(enum CmmButtonIds buttonId)
{
    if (!Cmm_IsSpriteButton(buttonId))
        return;

    u8 spriteId = sCmmMemory->state.buttonSpriteId[buttonId];
    Cmm_SetButtonPalette(spriteId, sMenuButtonPal, CMM_PALTAG_BUTTON);
}

static void Cmm_SetActiveButton(enum CmmButtonIds buttonId)
{
    if (buttonId < 0)
        buttonId = CMM_BUTTON_COUNT - 1;
    else if (buttonId >= CMM_BUTTON_COUNT)
        buttonId = 0;

    sCmmMemory->state.prevButton = sCmmMemory->state.activeButton;
    sCmmMemory->state.activeButton = buttonId;

    Cmm_DeactivateButton(sCmmMemory->state.prevButton);

    if (buttonId == CMM_BUTTON_INFOBOX) {
        Cmm_SetInfoboxActive(TRUE);
    }
    else {
        Cmm_SetInfoboxActive(FALSE);
        Cmm_ActivateButton(buttonId);
    }
    Cmm_PrintButtonLabels();
}

static bool32 Cmm_IsSpriteButton(enum CmmButtonIds buttonId)
{
    return buttonId != CMM_BUTTON_INFOBOX && buttonId < CMM_BUTTON_COUNT;
}


static const union TextColor sButtonTextColorActive = {.background = 0, .foreground = 6, .shadow = 8, .accent = 0};
static const union TextColor sButtonTextColor = {.background = 0, .foreground = 6, .shadow = 8, .accent = 0};

static const u8* const sButtonTexts[3] = {
    [CMM_BUTTON_NEWGAME] = COMPOUND_STRING("New Game"),   [CMM_BUTTON_OPTIONS] = COMPOUND_STRING("Options"),
    [CMM_BUTTON_CREDITS] = COMPOUND_STRING("Credits"), };

static void Cmm_PrintButtonLabels(void)
{
    for (u32 i = 0; i < 3; i++) {

        u8 fontId = FONT_SMALL_NARROW;

        if (GetStringWidth(FONT_SMALL_NARROW, sButtonTexts[i], 0) > 50) {
            fontId = FONT_SMALL_NARROWER; 
        }
        u8 spriteId = sCmmMemory->state.buttonSpriteId[i];
        u32 left = GetStringCenterAlignXOffset(fontId, sButtonTexts[i], 64);
        const union TextColor* color = (sCmmMemory->state.activeButton == i) ? &sButtonTextColorActive : &sButtonTextColor;
        AddSpriteTextPrinterParameterized6(spriteId, fontId, left, 8, 0, 0, *color, 0, sButtonTexts[i]);
    }
}

static void Cmm_MoveSelection(enum CmmDirs direction)
{
    enum CmmButtonIds cur = sCmmMemory->state.activeButton;

    switch (direction) {
        case CMM_DIR_UP:
            if (cur != CMM_BUTTON_INFOBOX && Cmm_IsContinueMenu())
                Cmm_SetActiveButton(CMM_BUTTON_INFOBOX);
            break;

        case CMM_DIR_DOWN:
            if (cur == CMM_BUTTON_INFOBOX) {
                    Cmm_SetActiveButton(CMM_BUTTON_NEWGAME);
            }
            break;

        case CMM_DIR_LEFT:
            if (cur == CMM_BUTTON_INFOBOX)
                break;
            if (cur == CMM_BUTTON_NEWGAME)
                Cmm_SetActiveButton(CMM_BUTTON_CREDITS);
            else
                Cmm_SetActiveButton(cur - 1);
            break;

        case CMM_DIR_RIGHT:
            if (cur == CMM_BUTTON_INFOBOX)
                break;
            if (cur == CMM_BUTTON_CREDITS)
                Cmm_SetActiveButton(CMM_BUTTON_NEWGAME);
            else
                Cmm_SetActiveButton(cur + 1);
            break;
    }
}

static void Cmm_DrawPartyIcons(void)
{
    const u16 startX = 100;
    const u16 startY = 44;

    for (u32 i = 0; i < PARTY_SIZE; i++) {
        u16 speciesId = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
        if (speciesId == SPECIES_NONE) {
            sCmmMemory->state.partyIconId[i] = SPRITE_NONE;
            continue;
        }

        u32 personality = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_PERSONALITY);

        u32 row = i / 3;
        u32 col = i % 3;

        u16 x = startX + col * 32 + 16;
        u16 y = startY + row * 32;

        if (row == 1) {
            x += 16;
            y -= 8;
        }

        sCmmMemory->state.partyIconId[i] = CreateMonIcon(speciesId, SpriteCB_MonIcon, x, y, 4, personality);

        gSprites[sCmmMemory->state.partyIconId[i]].oam.priority = 0;
    }
}

static void Cmm_DarkenPartyIcons(void)
{
    u16 palTag;
    u16 index;
    for (u32 i = 0; i < MON_ICON_PAL_COUNT; i++)
    {
        palTag = gMonIconPaletteTable[i].tag;
        index = IndexOfSpritePaletteTag(palTag);
        BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
    }
}

static void Cmm_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Cmm_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_CmmWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active) {
        CpuFastCopy(sCmmMemory->sTempPaletteBuffer, gPlttBufferUnfaded, sizeof(gPlttBufferUnfaded));
        PlayBGM(MUS_INVESTIGATION);
        gTasks[taskId].func = Task_CmmInput;
    }
}

static void Cmm_StartFade(u32 color)
{
    CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, sizeof(gPlttBufferFaded));
    FadeOutBGM(4);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, color);
}

static void Task_CmmInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON)) {
        Cmm_HandleButtonPressB();
    }
    if (JOY_NEW(A_BUTTON)) {
        Cmm_HandleButtonPressA();
    }
    if (JOY_NEW(DPAD_UP)) {
        PlaySE(SE_SELECT);
        Cmm_MoveSelection(CMM_DIR_UP);
    }
    if (JOY_NEW(DPAD_DOWN)) {
        PlaySE(SE_SELECT);
        Cmm_MoveSelection(CMM_DIR_DOWN);
    }
    if (JOY_NEW(DPAD_LEFT)) {
        PlaySE(SE_SELECT);
        Cmm_MoveSelection(CMM_DIR_LEFT);
    }
    if (JOY_NEW(DPAD_RIGHT)) {
        PlaySE(SE_SELECT);
        Cmm_MoveSelection(CMM_DIR_RIGHT);
    }
}

static void Cmm_HandleButtonPressA(void)
{
    switch (sCmmMemory->state.activeButton) {
        case CMM_BUTTON_INFOBOX:
            Cmm_ExitOnSelect(CB2_ContinueSavedGame);
            break;

        case CMM_BUTTON_NEWGAME:
            static const u8 sText_DefaultPlayerName[] = _("Miles");
            StringCopy_PlayerName(gSaveBlock2Ptr->playerName, sText_DefaultPlayerName);
            gSaveBlock2Ptr->playerGender = MALE;
            Cmm_ExitOnSelect(CB2_NewGame);
            break;

        case CMM_BUTTON_OPTIONS:
            gMain.savedCallback = CB2_InitCustomMainMenuFromOptionsMenu;
            Cmm_ExitOnSelect(CB2_InitOptionMenu);
            break;

        case CMM_BUTTON_CREDITS:
            Cmm_ExitOnSelect(CB2_OpenCustomCredits);
            break;

        default:
            PlaySE(SE_FAILURE);
            break;
    }
}

static void Cmm_HandleButtonPressB(void)
{
    u8 taskId = FindTaskIdByFunc(Task_CmmInput);
    PlaySE(SE_PC_OFF);
    Cmm_StartFade(RGB_BLACK);
    gTasks[taskId].func = Task_CmmWaitFadeAndExitGracefully;
}

static void Cmm_ExitOnSelect(MainCallback callback)
{
    u8 taskId = FindTaskIdByFunc(Task_CmmInput);
    PlaySE(SE_SELECT);
    Cmm_StartFade(RGB_BLACK);
    sCmmMemory->state.savedCallback = callback;
    gTasks[taskId].func = Task_CmmWaitFadeAndExitGracefully;
}

static void Cmm_SetInfoboxActive(bool32 active)
{
    if (active) {
        LoadPalette(CmmBgActivePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gSprites[sCmmMemory->state.playerSpriteId].animPaused = FALSE;
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        Cmm_RestorePlayerMugshot();
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sCmmMemory->state.partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCB_MonIcon;
            }
        }
    }
    else {
        LoadPalette(CmmBgActivePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        BlendPalette(BG_PLTT_ID(0), 16, 8, RGB_BLACK);
        gSprites[sCmmMemory->state.playerSpriteId].animPaused = TRUE;
        if (Cmm_IsContinueMenu())
        {
            Cmm_DarkenPartyIcons();
            Cmm_DarkenPlayerMugshot();
        }
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sCmmMemory->state.partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCallbackDummy;
            }
        }
    }
    Cmm_PrintInfoboxText();
}

static void Task_CmmWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active) {
        SetMainCallback2(sCmmMemory->state.savedCallback);
        Cmm_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_CmmWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active) {
        SetMainCallback2(sCmmMemory->state.savedCallback);
        Cmm_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 Cmm_InitBgs(void)
{
    ResetAllBgsCoordinates();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sCmmBgTemplates, NELEMS(sCmmBgTemplates));

    SetBgTilemapBuffer(1, sCmmMemory->sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sCmmMemory->sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void Cmm_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_CmmWaitFadeAndBail, 0);
    SetVBlankCallback(Cmm_VBlankCB);
    SetMainCallback2(Cmm_MainCB);
}

static bool8 Cmm_LoadGraphics(void)
{
    switch (sCmmMemory->state.loadState) {
        case 0:
            ResetTempTileDataBuffers();
            DecompressAndCopyTileDataToVram(1, CmmBgTiles, 0, 0, 0);
            DecompressAndCopyTileDataToVram(2, CmmScrollingBgTiles, 0, 0, 0);
            sCmmMemory->state.loadState++;
            break;
        case 1:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(CmmBgTilemap, sCmmMemory->sBg1TilemapBuffer);
                sCmmMemory->state.loadState++;
            }
            break;
        case 2:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(CmmScrollingBgTilemap, sCmmMemory->sBg2TilemapBuffer);
                sCmmMemory->state.loadState++;
            }
            break;
        case 3:
            LoadPalette(CmmBgPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadPalette(CmmScrollingBgPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadPalette(CmmMsgboxPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            sCmmMemory->state.loadState++;
        default:
            sCmmMemory->state.loadState = 0;
            return TRUE;
    }
    return FALSE;
}

static void Cmm_InitWindows(void)
{
    if (!Cmm_IsContinueMenu()) {
        InitWindows(sCmmErrorWindowTemplate);
        return;
    }

    InitWindows(sCmmWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    for (u32 i = 0; i <= NELEMS(sCmmWindowTemplates); i++) {
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
    }
}

static void Cmm_PrintText(u8 windowId, u8 font, u8 x, u8 y, const u8* color, const u8* str)
{
    AddTextPrinterParameterized4(windowId, font, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static inline void Cmm_PrintTextSmall(u8 windowId, u8 x, u8 y, const u8* color, const u8* str)
{
    Cmm_PrintText(windowId, FONT_SMALL, x, y, color, str);
}

static inline void Cmm_PrintTextNormal(u8 windowId, u8 x, u8 y, const u8* color, const u8* str)
{
    Cmm_PrintText(windowId, FONT_NORMAL, x, y, color, str);
}

static const u8 sText_EvidenceCount[] = _("Evd  {STR_VAR_2}");
static const u8 sText_NoSaveData[] = _("No Save Data Found");
static void Cmm_PrintContinueInfo(const u8 *color)
{
    u8 windowId = WIN_CMM_BG;
    u16 widthPx = Cmm_GetWindowWidth(windowId) * 8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    Cmm_FormatSavegameTime();
    Cmm_PrintTextSmall(windowId, 0, 0, color, gStringVar1);

    GetMapName(gStringVar1, GetCurrentRegionMapSectionId(), 0);
    u8 fontId = GetFontIdToFit(gStringVar1, FONT_SMALL, 0, widthPx/3);
    u8 xName = GetStringCenterAlignXOffset(fontId, gStringVar1, widthPx);
    Cmm_PrintText(windowId, fontId, xName, 0, color, gStringVar1);

    ConvertIntToDecimalStringN(gStringVar2, GetHeldEvidenceCount(), STR_CONV_MODE_LEFT_ALIGN, 4);

    StringExpandPlaceholders(gStringVar1, sText_EvidenceCount);
    u8 xTokens = GetStringRightAlignXOffset(FONT_SMALL, gStringVar1, widthPx);
    Cmm_PrintTextSmall(windowId, xTokens, 0, color, gStringVar1);

    Cmm_PrintPlayerName();

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void Cmm_PrintNoSaveInfo(const u8 *color)
{
    u8 windowId = WIN_CMM_NO_SAVE;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);

    u16 widthPx = GetWindowAttribute(windowId, WINDOW_WIDTH) * 8;
    u8 x = GetStringCenterAlignXOffset(FONT_NORMAL, sText_NoSaveData, widthPx);

    Cmm_PrintTextNormal(windowId, x, 0, color, sText_NoSaveData);

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Cmm_PrintInfoboxText(void)
{
    const u8 *color = Cmm_GetInfoboxFontColor();
    if (Cmm_IsContinueMenu())
        Cmm_PrintContinueInfo(color);
    else
        Cmm_PrintNoSaveInfo(color);
}

static void Cmm_FormatSavegameTime(void)
{
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Time  {STR_VAR_2}:{STR_VAR_3}"));
}

static void Cmm_PrintPlayerName(void)
{
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("{PLAYER}"));
    FillWindowPixelBuffer(WIN_CMM_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    u8 xName = GetStringCenterAlignXOffset(FONT_SMALL, gStringVar1, Cmm_GetWindowWidth(WIN_CMM_NAME)*8);
    Cmm_PrintTextSmall(WIN_CMM_NAME, xName, 0, Cmm_GetPlayerNameFontColor(), gStringVar1);
    CopyWindowToVram(WIN_CMM_NAME, COPYWIN_GFX);

}

static const u8* Cmm_GetInfoboxFontColor(void)
{
    if (sCmmMemory->state.activeButton == CMM_BUTTON_INFOBOX) {
        return CMM_FONT_COLOR(FONT_WHITE);
    }
    else {
        return CMM_FONT_COLOR(FONT_GRAY);
    }
}

static const u8 *Cmm_GetPlayerNameFontColor(void)
{
    return CMM_FONT_COLOR(FONT_PLAYER);
}
static u32 Cmm_GetWindowWidth(u8 windowId)
{
    return GetWindowAttribute(windowId, WINDOW_WIDTH);
}

static void Cmm_FreeResources(void)
{
    TRY_FREE_AND_SET_NULL(sCmmMemory);
    FreeAllWindowBuffers();
    FreeAllSpritePalettes();
    ResetSpriteData();
    ResetTasks();
}
