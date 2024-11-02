#include "pokemon_summary_app.h"

#include <nitro.h>
#include <string.h>

#include "constants/flavor.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/string.h"
#include "consts/moves.h"
#include "consts/sdat.h"
#include "consts/species.h"

#include "struct_defs/struct_02099F80.h"

#include "bg_window.h"
#include "cell_actor.h"
#include "core_sys.h"
#include "font.h"
#include "game_options.h"
#include "graphics.h"
#include "gx_layers.h"
#include "heap.h"
#include "item.h"
#include "message.h"
#include "move_table.h"
#include "narc.h"
#include "overlay_manager.h"
#include "party.h"
#include "pokemon.h"
#include "pokemon_summary_app.h"
#include "render_window.h"
#include "savedata.h"
#include "strbuf.h"
#include "string_template.h"
#include "system_flags.h"
#include "trainer_info.h"
#include "unk_020041CC.h"
#include "unk_02005474.h"
#include "unk_02006224.h"
#include "unk_0200762C.h"
#include "unk_0200C440.h"
#include "unk_0200C6E4.h"
#include "unk_0200F174.h"
#include "unk_02015F84.h"
#include "unk_02017728.h"
#include "unk_0201DBEC.h"
#include "unk_0201E3D8.h"
#include "unk_020393C8.h"
#include "unk_0208C098.h"
#include "unk_0208EA44.h"
#include "unk_0208FCF8.h"
#include "unk_020916B4.h"
#include "unk_020920C0.h"
#include "unk_020923C0.h"
#include "unk_02094EDC.h"
#include "unk_020989DC.h"
#include "vars_flags.h"

#include "constdata/const_020F410C.h"

#define HEAP_ALLOCATION_SIZE 0x40000

static int PokemonSummaryScreen_Init(OverlayManager *ovyManager, int *state);
static int PokemonSummaryScreen_Main(OverlayManager *ovyManager, int *state);
static int PokemonSummaryScreen_Exit(OverlayManager *ovyManager, int *state);
static int WaitSummaryScreenTransition(PokemonSummaryScreen *summaryScreen);
static int HandleInput_Main(PokemonSummaryScreen *summaryScreen);
static int sub_0208CB38(PokemonSummaryScreen *summaryScreen);
static int sub_0208CB4C(PokemonSummaryScreen *summaryScreen);
static int sub_0208CB60(PokemonSummaryScreen *summaryScreen);
static int sub_0208CB74(PokemonSummaryScreen *summaryScreen);
static int HandleInput_MoveSelect(PokemonSummaryScreen *summaryScreen);
static int HandleInput_MoveSwap(PokemonSummaryScreen *summaryScreen);
static int HandleInput_LearnMove(PokemonSummaryScreen *summaryScreen);
static int WaitForHMMsgInput(PokemonSummaryScreen *summaryScreen);
static int sub_0208CE70(PokemonSummaryScreen *summaryScreen);
static int sub_0208CE84(PokemonSummaryScreen *summaryScreen);
static int sub_0208CE98(PokemonSummaryScreen *summaryScreen);
static int sub_0208CF0C(PokemonSummaryScreen *summaryScreen);
static int sub_0208CF78(PokemonSummaryScreen *summaryScreen);
static int sub_0208D114(PokemonSummaryScreen *summaryScreen);
static int sub_0208D164(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208D17C(PokemonSummaryScreen *summaryScreen);
static u8 ScreenTransitionIsDone(PokemonSummaryScreen *summaryScreen);
static void SetVRAMBanks(void);
static void SetupBgs(BgConfig *bgConfig);
static void TeardownBgs(BgConfig *bgConfig);
static void LoadBgGraphics(PokemonSummaryScreen *summaryScreen, NARC *narc);
static void SetAlphaBlending(void);
static void PokemonSummaryScreenVBlank(void *data);
static void InitializeStringsAndCopyOTName(PokemonSummaryScreen *summaryScreen);
static void FreeStrings(PokemonSummaryScreen *summaryScreen);
static void SetMonData(PokemonSummaryScreen *summaryScreen);
static void SetMonDataFromBoxMon(PokemonSummaryScreen *summaryScreen, BoxPokemon *boxMon, PokemonSummaryMonData *monData);
static void SetMonDataFromMon(PokemonSummaryScreen *summaryScreen, Pokemon *mon, PokemonSummaryMonData *monData);
static void sub_0208D678(PokemonSummaryScreen *summaryScreen);
static void PlayMonCry(PokemonSummaryScreen *summaryScreen);
static void sub_0208D7EC(PokemonSummaryScreen *summaryScreen, u8 page);
static void ChangePage(PokemonSummaryScreen *summaryScreen, s8 delta);
static u8 sub_0208D920(PokemonSummaryScreen *summaryScreen);
static void sub_0208D748(PokemonSummaryScreen *summaryScreen);
static void sub_0208D948(PokemonSummaryScreen *summaryScreen);
static void DrawHealthBar(PokemonSummaryScreen *summaryScreen);
static void DrawExperienceProgressBar(PokemonSummaryScreen *summaryScreen);
static void ChangeSummaryMon(PokemonSummaryScreen *summaryScreen, s8 delta);
static s8 TryAdvanceSummaryMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta);
static s8 TryAdvanceMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta);
static s8 TryAdvancePartyMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta);
static s8 TryAdvanceBoxMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta);
static u8 sub_0208DD8C(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208DEA4(PokemonSummaryScreen *summaryScreen);
static u8 TryChangeSelectedMove(PokemonSummaryScreen *summaryScreen, s8 delta);
static void UpdateMoveInfo(PokemonSummaryScreen *summaryScreen);
static void SwapSelectedMoves(PokemonSummaryScreen *summaryScreen);
static void sub_0208E190(PokemonSummaryScreen *summaryScreen);
static void UpdateBattleMoveInfo(PokemonSummaryScreen *summaryScreen, u32 move);
static void UpdateContestMoveInfo(PokemonSummaryScreen *summaryScreen, u32 move);
static void sub_0208E4EC(PokemonSummaryScreen *summaryScreen);
static void sub_0208E508(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208E208(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208E308(PokemonSummaryScreen *summaryScreen);
static void UpdateAppealHearts(PokemonSummaryScreen *summaryScreen, u32 move);
static void DrawEmptyHearts(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208E57C(PokemonSummaryScreen *summaryScreen);
static u8 sub_0208E6A8(PokemonSummaryScreen *summaryScreen);
static void sub_0208E794(PokemonSummaryScreen *summaryScreen, s8 delta);
u8 PokemonSummary_RibbonAt(PokemonSummaryScreen *summaryScreen, u8 param1);
static int sub_0208E958(PokemonSummaryScreen *summaryScreen);

const OverlayManagerTemplate Unk_020F410C = {
    PokemonSummaryScreen_Init,
    PokemonSummaryScreen_Main,
    PokemonSummaryScreen_Exit,
    FS_OVERLAY_ID_NONE
};

BOOL PokemonSummary_ShowContestData(SaveData *saveData)
{
    return SystemFlag_CheckContestHallVisited(SaveData_GetVarsFlags(saveData));
}

static int PokemonSummaryScreen_Init(OverlayManager *ovyManager, int *state)
{
    SetMainCallback(NULL, NULL);
    DisableHBlank();
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_BlendNone();
    G2S_BlendNone();

    SetAutorepeat(4, 8);
    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_POKEMON_SUMMARY_SCREEN, HEAP_ALLOCATION_SIZE);

    NARC *narc = NARC_ctor(NARC_INDEX_GRAPHIC__PL_PST_GRA, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    PokemonSummaryScreen *summaryScreen = OverlayManager_NewData(ovyManager, sizeof(PokemonSummaryScreen), HEAP_ID_POKEMON_SUMMARY_SCREEN);

    memset(summaryScreen, 0, sizeof(PokemonSummaryScreen));

    summaryScreen->data = OverlayManager_Args(ovyManager);
    summaryScreen->bgConfig = BgConfig_New(HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->monSpriteData.animationSys = sub_02015F84(HEAP_ID_POKEMON_SUMMARY_SCREEN, 1, 1);
    summaryScreen->narcPlPokeData = NARC_ctor(NARC_INDEX_POKETOOL__POKE_EDIT__PL_POKE_DATA, HEAP_ID_POKEMON_SUMMARY_SCREEN);

    Font_UseImmediateGlyphAccess(FONT_SYSTEM, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    sub_0201E3D8();
    sub_0201E450(4);
    sub_0208D748(summaryScreen);
    SetVRAMBanks();
    SetupBgs(summaryScreen->bgConfig);
    LoadBgGraphics(summaryScreen, narc);
    SetAlphaBlending();
    sub_020916B4(summaryScreen);
    InitializeStringsAndCopyOTName(summaryScreen);
    SetMonData(summaryScreen);
    sub_0208EA44(summaryScreen);
    sub_0208EB64(summaryScreen);
    sub_02091F8C(summaryScreen);
    sub_0208EE3C(summaryScreen);
    sub_0208EE9C(summaryScreen);
    sub_0208FCF8(summaryScreen);
    sub_0208D678(summaryScreen);
    sub_020920C0(summaryScreen);
    sub_020917E0(summaryScreen);
    SetMainCallback(PokemonSummaryScreenVBlank, summaryScreen);
    GXLayers_TurnBothDispOn();
    sub_02004550(61, 0, 0);
    DrawWifiConnectionIcon();
    NARC_dtor(narc);

    return TRUE;
}

static int PokemonSummaryScreen_Main(OverlayManager *ovyManager, int *state)
{
    PokemonSummaryScreen *summaryScreen = OverlayManager_Data(ovyManager);

    switch (*state) {
    case SUMMARY_STATE_TRANSITION_IN:
        sub_0208C120(0, 19);
        *state = SUMMARY_STATE_WAIT_TRANSITION;
        break;
    case SUMMARY_STATE_WAIT_TRANSITION:
        *state = WaitSummaryScreenTransition(summaryScreen);
        break;
    case SUMMARY_STATE_HANDLE_INPUT:
        *state = HandleInput_Main(summaryScreen);
        break;
    case 3:
        *state = sub_0208CB38(summaryScreen);
        break;
    case 4:
        *state = sub_0208CB4C(summaryScreen);
        break;
    case 5:
        *state = sub_0208CB60(summaryScreen);
        break;
    case 6:
        *state = sub_0208CB74(summaryScreen);
        break;
    case SUMMARY_STATE_MOVE_SELECT:
        *state = HandleInput_MoveSelect(summaryScreen);
        break;
    case SUMMARY_STATE_MOVE_SWAP:
        *state = HandleInput_MoveSwap(summaryScreen);
        break;
    case SUMMARY_STATE_LEARN_MOVE:
        *state = HandleInput_LearnMove(summaryScreen);
        break;
    case SUMMARY_STATE_WAIT_HM_MSG_INPUT:
        *state = WaitForHMMsgInput(summaryScreen);
        break;
    case 11:
        *state = sub_0208CE70(summaryScreen);
        break;
    case 12:
        *state = sub_0208CE84(summaryScreen);
        break;
    case 13:
        *state = sub_0208CE98(summaryScreen);
        break;
    case 14:
        *state = sub_0208CF0C(summaryScreen);
        break;
    case 15:
        *state = sub_0208CF78(summaryScreen);
        break;
    case 16:
        *state = sub_0208D114(summaryScreen);
        break;
    case 17:
        *state = sub_0208D164(summaryScreen);
        break;
    case SUMMARY_STATE_TRANSITION_OUT:
        *state = sub_0208D17C(summaryScreen);
        break;
    case SUMMARY_STATE_WAIT_EXIT:
        if (ScreenTransitionIsDone(summaryScreen) == TRUE) {
            return TRUE;
        }
        break;
    }

    sub_0208EB14(summaryScreen);
    sub_0208F3B0(summaryScreen);
    sub_0208FB30(summaryScreen);
    sub_0200C7EC(summaryScreen->gfxHandler);
    sub_02091750(summaryScreen);

    return FALSE;
}

static int PokemonSummaryScreen_Exit(OverlayManager *ovyManager, int *state)
{
    PokemonSummaryScreen *summaryScreen = OverlayManager_Data(ovyManager);

    SetMainCallback(NULL, NULL);
    sub_020917B0(summaryScreen);
    sub_0208EAF4(summaryScreen);
    sub_0208FE88(summaryScreen);
    TeardownBgs(summaryScreen->bgConfig);
    sub_0201E530();
    VRAMTransferManager_Destroy();
    FreeStrings(summaryScreen);
    NARC_dtor(summaryScreen->narcPlPokeData);
    Font_UseLazyGlyphAccess(FONT_SYSTEM);

    G2_BlendNone();

    OverlayManager_FreeData(ovyManager);
    Heap_Destroy(HEAP_ID_POKEMON_SUMMARY_SCREEN);

    return TRUE;
}

static void PokemonSummaryScreenVBlank(void *data)
{
    PokemonSummaryScreen *summaryScreen = data;

    Bg_RunScheduledUpdates(summaryScreen->bgConfig);
    sub_02008A94(summaryScreen->monSpriteData.spriteManager);
    sub_0201DCAC();
    OAMManager_ApplyAndResetBuffers();

    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void SetVRAMBanks(void)
{
    UnkStruct_02099F80 banks = {
        GX_VRAM_BG_128_A,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_128_C,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_64_E,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_TEX_0_B,
        GX_VRAM_TEXPLTT_01_FG
    };

    GXLayers_SetBanks(&banks);
}

static void SetupBgs(BgConfig *bgConfig)
{
    GraphicsModes graphicsModes = {
        GX_DISPMODE_GRAPHICS,
        GX_BGMODE_0,
        GX_BGMODE_0,
        GX_BG0_AS_3D,
    };

    SetAllGraphicsModes(&graphicsModes);

    BgTemplate bgMain1 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xf800,
        .charBase = GX_BG_CHARBASE_0x10000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 0,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = FALSE
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_1, &bgMain1, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_MAIN_1);

    BgTemplate bgMain2 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x2000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_512x512,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xd800,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 1,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = FALSE
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_2, &bgMain2, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_MAIN_2);
    Bg_ScheduleScroll(bgConfig, BG_LAYER_MAIN_2, 0, 136);

    BgTemplate bgMain3 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xd000,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 3,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = FALSE
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_3, &bgMain3, BG_TYPE_STATIC);

    BgTemplate bgSub0 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xf800,
        .charBase = GX_BG_CHARBASE_0x10000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 0,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = FALSE
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_SUB_0, &bgSub0, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_SUB_0);

    BgTemplate bgSub1 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xf000,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 1,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = FALSE
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_SUB_1, &bgSub1, BG_TYPE_STATIC);

    Bg_ClearTilesRange(BG_LAYER_MAIN_1, 32, 0, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Bg_ClearTilesRange(BG_LAYER_SUB_0, 32, 0, HEAP_ID_POKEMON_SUMMARY_SCREEN);
}

static void TeardownBgs(BgConfig *bgConfig)
{
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_SUB_1);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_SUB_0);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_3);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_2);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_1);

    Heap_FreeToHeapExplicit(HEAP_ID_POKEMON_SUMMARY_SCREEN, bgConfig);
}

static void LoadBgGraphics(PokemonSummaryScreen *summaryScreen, NARC *narc)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(narc, 0, summaryScreen->bgConfig, BG_LAYER_MAIN_3, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(narc, 3, summaryScreen->bgConfig, BG_LAYER_MAIN_3, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Graphics_LoadPaletteFromOpenNARC(narc, 1, PAL_LOAD_MAIN_BG, 0, 0, HEAP_ID_POKEMON_SUMMARY_SCREEN);

    Graphics_LoadTilemapToBgLayerFromOpenNARC(narc, 11, summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);

    Graphics_LoadTilesToBgLayerFromOpenNARC(narc, 2, summaryScreen->bgConfig, BG_LAYER_SUB_0, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Graphics_LoadTilesToBgLayerFromOpenNARC(narc, 16, summaryScreen->bgConfig, BG_LAYER_SUB_1, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(narc, 15, summaryScreen->bgConfig, BG_LAYER_SUB_1, 0, 0, FALSE, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    Graphics_LoadPaletteFromOpenNARC(narc, 14, PAL_LOAD_SUB_BG, 0, 0, HEAP_ID_POKEMON_SUMMARY_SCREEN);
}

static void SetAlphaBlending(void)
{
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 23, 8);
}

// ravetodo review
static void InitializeStringsAndCopyOTName(PokemonSummaryScreen *summaryScreen)
{
    summaryScreen->msgLoader = MessageLoader_Init(MESSAGE_LOADER_BANK_HANDLE, NARC_INDEX_MSGDATA__PL_MSG, 455, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->ribbonLoader = MessageLoader_Init(MESSAGE_LOADER_NARC_HANDLE, NARC_INDEX_MSGDATA__PL_MSG, 535, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->unk_684 = sub_0200C440(1, 2, 0, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->strFormatter = StringTemplate_Default(HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->monData.speciesName = Strbuf_Init(12, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->monData.nickname = Strbuf_Init(12, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->monData.OTName = Strbuf_Init(TRAINER_NAME_LEN + 1, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->strbuf = Strbuf_Init(128, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->moveNameLoader = MessageLoader_Init(MESSAGE_LOADER_BANK_HANDLE, NARC_INDEX_MSGDATA__PL_MSG, 647, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    summaryScreen->playerName = Strbuf_Init(TRAINER_NAME_LEN + 1, HEAP_ID_POKEMON_SUMMARY_SCREEN);

    if (summaryScreen->data->OTName != NULL) {
        Strbuf_CopyChars(summaryScreen->playerName, summaryScreen->data->OTName);
    }
}

// ravetodo review
static void FreeStrings(PokemonSummaryScreen *summaryScreen)
{
    MessageLoader_Free(summaryScreen->moveNameLoader);
    MessageLoader_Free(summaryScreen->ribbonLoader);
    MessageLoader_Free(summaryScreen->msgLoader);
    sub_0200C560(summaryScreen->unk_684);
    StringTemplate_Free(summaryScreen->strFormatter);
    Strbuf_Free(summaryScreen->monData.speciesName);
    Strbuf_Free(summaryScreen->monData.nickname);
    Strbuf_Free(summaryScreen->monData.OTName);
    Strbuf_Free(summaryScreen->strbuf);
    Strbuf_Free(summaryScreen->playerName);
}

static int WaitSummaryScreenTransition(PokemonSummaryScreen *summaryScreen)
{
    if (IsScreenTransitionDone() == TRUE) {
        PokemonSummaryScreen_LoadMonAnimation(summaryScreen);
        PlayMonCry(summaryScreen);

        if (summaryScreen->data->mode == SUMMARY_MODE_SELECT_MOVE) {
            return SUMMARY_STATE_LEARN_MOVE;
        } else if (summaryScreen->data->mode == SUMMARY_MODE_CONDITION) {
            return 15;
        } else {
            return SUMMARY_STATE_HANDLE_INPUT;
        }
    }

    return SUMMARY_STATE_WAIT_TRANSITION;
}

static int HandleInput_Main(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->subscreenExit == TRUE) {
        summaryScreen->data->returnMode = 1;
        return SUMMARY_STATE_TRANSITION_OUT;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_LEFT) {
        ChangePage(summaryScreen, -1);
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_RIGHT) {
        ChangePage(summaryScreen, 1);
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_UP) {
        ChangeSummaryMon(summaryScreen, -1);
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_DOWN) {
        ChangeSummaryMon(summaryScreen, 1);
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_B) {
        Sound_PlayEffect(SEQ_SE_DP_DECIDE);
        summaryScreen->data->returnMode = 1;
        return SUMMARY_STATE_TRANSITION_OUT;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
        if (summaryScreen->data->mode == SUMMARY_MODE_POFFIN && summaryScreen->page == SUMMARY_MODE_CONDITION) {
            Sound_PlayEffect(SEQ_SE_DP_DECIDE);
            return sub_0208E958(summaryScreen);
        }

        if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
            Sound_PlayEffect(SEQ_SE_DP_SYU01);
            summaryScreen->subscreen = 0;
            return 3;
        } else if (summaryScreen->page == SUMMARY_PAGE_CONTEST_MOVES) {
            Sound_PlayEffect(SEQ_SE_DP_SYU01);
            summaryScreen->subscreen = 0;
            return 5;
        } else if (summaryScreen->page == SUMMARY_PAGE_RIBBONS) {
            if (summaryScreen->ribbonMax != 0) {
                Sound_PlayEffect(SEQ_SE_DP_DECIDE);
                summaryScreen->subscreen = 0;
                return 11;
            }
        } else if (summaryScreen->page == SUMMARY_PAGE_EXIT) {
            Sound_PlayEffect(SEQ_SE_DP_DECIDE);
            summaryScreen->data->returnMode = 1;
            return SUMMARY_STATE_TRANSITION_OUT;
        }
    }

    if (sub_0208D920(summaryScreen) == TRUE) {
        summaryScreen->subscreen = 2;
        return 14;
    }

    return SUMMARY_STATE_HANDLE_INPUT;
}

static int sub_0208CB38(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208DD8C(summaryScreen) == TRUE) {
        return SUMMARY_STATE_MOVE_SELECT;
    }

    return 3;
}

static int sub_0208CB4C(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208DEA4(summaryScreen) == TRUE) {
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    return 4;
}

static int sub_0208CB60(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208E208(summaryScreen) == TRUE) {
        return SUMMARY_STATE_MOVE_SELECT;
    }

    return 5;
}

static int sub_0208CB74(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208E308(summaryScreen) == TRUE) {
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    return 6;
}

static int HandleInput_MoveSelect(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & PAD_KEY_UP) {
        if (TryChangeSelectedMove(summaryScreen, -1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_MOVE_SELECT;
    }

    if (gCoreSys.pressedKeys & PAD_KEY_DOWN) {
        if (TryChangeSelectedMove(summaryScreen, 1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_MOVE_SELECT;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
        if (summaryScreen->cursor == 4) {
            Sound_PlayEffect(SEQ_SE_DP_SYU01);
            summaryScreen->subscreen = 0;

            if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
                return 4;
            } else {
                return 6;
            }
        } else if (summaryScreen->data->mode != SUMMARY_MODE_LOCK_MOVES) {
            Sound_PlayEffect(SEQ_SE_DP_DECIDE);
            sub_0208F310(summaryScreen);
            summaryScreen->cursorTmp = summaryScreen->cursor;
            return SUMMARY_STATE_MOVE_SWAP;
        }
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_B) {
        Sound_PlayEffect(SEQ_SE_DP_SYU01);
        summaryScreen->subscreen = 0;

        if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
            return 4;
        } else {
            return 6;
        }
    }

    return SUMMARY_STATE_MOVE_SELECT;
}

static int HandleInput_MoveSwap(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & PAD_KEY_UP) {
        if (TryChangeSelectedMove(summaryScreen, -1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_MOVE_SWAP;
    }

    if (gCoreSys.pressedKeys & PAD_KEY_DOWN) {
        if (TryChangeSelectedMove(summaryScreen, 1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_MOVE_SWAP;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
        CellActor_SetDrawFlag(summaryScreen->unk_41C[10], FALSE);

        if (summaryScreen->cursor != 4 && summaryScreen->cursor != summaryScreen->cursorTmp) {
            Sound_PlayEffect(SEQ_SE_DP_DECIDE);
            SwapSelectedMoves(summaryScreen);
            sub_0208F22C(summaryScreen, summaryScreen->cursor, summaryScreen->cursorTmp);
            sub_02091474(summaryScreen);
            UpdateMoveInfo(summaryScreen);
        } else {
            Sound_PlayEffect(SEQ_SE_DP_DECIDE);
        }

        return SUMMARY_STATE_MOVE_SELECT;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_B) {
        Sound_PlayEffect(SEQ_SE_DP_DECIDE);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[10], FALSE);
        return SUMMARY_STATE_MOVE_SELECT;
    }

    return SUMMARY_STATE_MOVE_SWAP;
}

static int HandleInput_LearnMove(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & PAD_KEY_LEFT) {
        ChangePage(summaryScreen, -1);
        return SUMMARY_STATE_LEARN_MOVE;
    }

    if (gCoreSys.pressedKeys & PAD_KEY_RIGHT) {
        ChangePage(summaryScreen, 1);
        return SUMMARY_STATE_LEARN_MOVE;
    }

    if (gCoreSys.pressedKeys & PAD_KEY_UP) {
        if (TryChangeSelectedMove(summaryScreen, -1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_LEARN_MOVE;
    }

    if (gCoreSys.pressedKeys & PAD_KEY_DOWN) {
        if (TryChangeSelectedMove(summaryScreen, 1) == TRUE) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            UpdateMoveInfo(summaryScreen);
        }

        return SUMMARY_STATE_LEARN_MOVE;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
        Sound_PlayEffect(SEQ_SE_DP_DECIDE);

        if (summaryScreen->cursor != 4) {
            if (Item_IsHMMove(summaryScreen->monData.moves[summaryScreen->cursor]) == TRUE && summaryScreen->data->move != MOVE_NONE) {
                SpriteActor_DrawSprite(summaryScreen->unk_41C[18], FALSE);
                DrawEmptyHearts(summaryScreen);
                PokemonSummaryScreen_PrintHMMovesCantBeForgotten(summaryScreen);
                return SUMMARY_STATE_WAIT_HM_MSG_INPUT;
            }
        }

        summaryScreen->data->selectedSlot = summaryScreen->cursor;
        summaryScreen->data->returnMode = 0;
        return SUMMARY_STATE_TRANSITION_OUT;
    }

    if (gCoreSys.pressedKeys & PAD_BUTTON_B) {
        Sound_PlayEffect(SEQ_SE_DP_DECIDE);
        summaryScreen->data->selectedSlot = 4;
        summaryScreen->data->returnMode = 1;
        return SUMMARY_STATE_TRANSITION_OUT;
    }

    return SUMMARY_STATE_LEARN_MOVE;
}

static int WaitForHMMsgInput(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        UpdateMoveInfo(summaryScreen);
        return SUMMARY_STATE_LEARN_MOVE;
    }

    return SUMMARY_STATE_WAIT_HM_MSG_INPUT;
}

static int sub_0208CE70(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208E57C(summaryScreen) == TRUE) {
        return 13;
    }

    return 11;
}

static int sub_0208CE84(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0208E6A8(summaryScreen) == TRUE) {
        return SUMMARY_STATE_HANDLE_INPUT;
    }

    return 12;
}
// ravetodo ribbon select handler?
static int sub_0208CE98(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_LEFT) {
        sub_0208E794(summaryScreen, -1);
        return 13;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_RIGHT) {
        sub_0208E794(summaryScreen, 1);
        return 13;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_UP) {
        sub_0208E794(summaryScreen, -4);
        return 13;
    }

    if (gCoreSys.pressedKeysRepeatable & PAD_KEY_DOWN) {
        sub_0208E794(summaryScreen, 4);
        return 13;
    }

    if (gCoreSys.pressedKeys & (PAD_BUTTON_B | PAD_BUTTON_A)) {
        Sound_PlayEffect(SEQ_SE_DP_DECIDE);
        summaryScreen->subscreen = 0;
        return 12;
    }

    return 13;
}
// ravetodo sub screen input handler?
static int sub_0208CF0C(PokemonSummaryScreen *summaryScreen)
{
    if (sub_0209228C(summaryScreen) == TRUE) {
        return summaryScreen->subscreen;
    }

    if (summaryScreen->buttonState == 1) {
        u8 page = sub_020923A4(summaryScreen, summaryScreen->buttonPos);

        if (page == SUMMARY_PAGE_EXIT) {
            summaryScreen->subscreenExit = TRUE;
        }

        if (summaryScreen->monData.isEgg == TRUE) {
            if (page == SUMMARY_PAGE_MEMO || page == SUMMARY_PAGE_EXIT) {
                sub_0208D7EC(summaryScreen, page);
            }
        } else {
            sub_0208D7EC(summaryScreen, page);
        }
    }

    return 14;
}
// ravetodo set contest data?
static int sub_0208CF78(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        BoxPokemon *boxMon;
        Pokemon *mon;

        if (summaryScreen->data->dataType == SUMMARY_DATA_BOX_MON) {
            boxMon = PokemonSummary_MonData(summaryScreen);
            mon = Pokemon_New(HEAP_ID_POKEMON_SUMMARY_SCREEN);
            Pokemon_FromBoxPokemon(boxMon, mon);
        } else {
            mon = PokemonSummary_MonData(summaryScreen);
        }

        sub_02098EF8(summaryScreen->data->poffin, mon);

        summaryScreen->subscreen = 0;

        u8 monValue = summaryScreen->monData.cool;
        summaryScreen->monData.cool = (u8)Pokemon_GetValue(mon, MON_DATA_COOL, NULL);

        if (monValue != summaryScreen->monData.cool) {
            summaryScreen->subscreen |= 1;
        }

        monValue = summaryScreen->monData.beauty;
        summaryScreen->monData.beauty = (u8)Pokemon_GetValue(mon, MON_DATA_BEAUTY, NULL);

        if (monValue != summaryScreen->monData.beauty) {
            summaryScreen->subscreen |= 2;
        }

        monValue = summaryScreen->monData.cute;
        summaryScreen->monData.cute = (u8)Pokemon_GetValue(mon, MON_DATA_CUTE, NULL);

        if (monValue != summaryScreen->monData.cute) {
            summaryScreen->subscreen |= 4;
        }

        monValue = summaryScreen->monData.smart;
        summaryScreen->monData.smart = (u8)Pokemon_GetValue(mon, MON_DATA_SMART, NULL);

        if (monValue != summaryScreen->monData.smart) {
            summaryScreen->subscreen |= 8;
        }

        monValue = summaryScreen->monData.tough;
        summaryScreen->monData.tough = (u8)Pokemon_GetValue(mon, MON_DATA_TOUGH, NULL);

        if (monValue != summaryScreen->monData.tough) {
            summaryScreen->subscreen |= 16;
        }

        summaryScreen->monData.sheen = (u8)Pokemon_GetValue(mon, MON_DATA_SHEEN, NULL);

        if (summaryScreen->data->dataType == SUMMARY_DATA_BOX_MON) {
            Heap_FreeToHeap(mon);
        }

        Font_LoadScreenIndicatorsPalette(0, 14 * 32, HEAP_ID_POKEMON_SUMMARY_SCREEN);
        LoadMessageBoxGraphics(summaryScreen->bgConfig, BG_LAYER_MAIN_1, (1024 - (18 + 12)), 13, Options_Frame(summaryScreen->data->options), HEAP_ID_POKEMON_SUMMARY_SCREEN);

        if (summaryScreen->subscreen == 0) {
            sub_02091610(summaryScreen, 0xfe);
            return 17;
        } else {
            sub_02091D50(summaryScreen);
            sub_0208F34C(summaryScreen);
            sub_0208F6A4(summaryScreen);
            return 16;
        }
    }

    return 15;
}

static int sub_0208D114(PokemonSummaryScreen *summaryScreen)
{
    if (gCoreSys.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        for (u8 i = 0; i < 5; i++) {
            if (summaryScreen->subscreen & (1 << i)) {
                sub_02091610(summaryScreen, i);
                summaryScreen->subscreen ^= (1 << i);

                if (summaryScreen->subscreen == 0) {
                    return 17;
                }
                break;
            }
        }
    }

    return 16;
}

static int sub_0208D164(PokemonSummaryScreen *dummy)
{
    if (gCoreSys.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        return SUMMARY_STATE_TRANSITION_OUT;
    }

    return 17;
}

static u8 sub_0208D17C(PokemonSummaryScreen *dummy)
{
    sub_0208C120(1, 19);
    return SUMMARY_STATE_WAIT_EXIT;
}

static u8 ScreenTransitionIsDone(PokemonSummaryScreen *dummy)
{
    return IsScreenTransitionDone() == TRUE;
}

static void SetMonData(PokemonSummaryScreen *summaryScreen)
{
    void *monData = PokemonSummary_MonData(summaryScreen);

    if (summaryScreen->data->dataType == SUMMARY_DATA_BOX_MON) {
        SetMonDataFromBoxMon(summaryScreen, monData, &summaryScreen->monData);
    } else {
        SetMonDataFromMon(summaryScreen, monData, &summaryScreen->monData);
    }
}

static void SetMonDataFromBoxMon(PokemonSummaryScreen *summaryScreen, BoxPokemon *boxMon, PokemonSummaryMonData *monData)
{
    Pokemon *mon = Pokemon_New(HEAP_ID_POKEMON_SUMMARY_SCREEN);

    Pokemon_FromBoxPokemon(boxMon, mon);
    SetMonDataFromMon(summaryScreen, mon, monData);
    Heap_FreeToHeap(mon);
}

// ravetodo entry IDs
static void SetMonDataFromMon(PokemonSummaryScreen *summaryScreen, Pokemon *mon, PokemonSummaryMonData *monData)
{
    BOOL reencrypt = Pokemon_EnterDecryptionContext(mon);
    monData->species = (u16)Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL);
    BoxPokemon *boxMon = Pokemon_GetBoxPokemon(mon);

    MessageLoader_GetStrbuf(summaryScreen->msgLoader, 11, summaryScreen->strbuf);
    StringTemplate_SetSpeciesName(summaryScreen->strFormatter, 0, boxMon);
    StringTemplate_Format(summaryScreen->strFormatter, summaryScreen->monData.speciesName, summaryScreen->strbuf);

    MessageLoader_GetStrbuf(summaryScreen->msgLoader, 0, summaryScreen->strbuf);
    StringTemplate_SetNickname(summaryScreen->strFormatter, 0, boxMon);
    StringTemplate_Format(summaryScreen->strFormatter, summaryScreen->monData.nickname, summaryScreen->strbuf);

    MessageLoader_GetStrbuf(summaryScreen->msgLoader, 14, summaryScreen->strbuf);
    StringTemplate_SetOTName(summaryScreen->strFormatter, 0, boxMon);
    StringTemplate_Format(summaryScreen->strFormatter, summaryScreen->monData.OTName, summaryScreen->strbuf);

    monData->heldItem = (u16)Pokemon_GetValue(mon, MON_DATA_HELD_ITEM, NULL);
    monData->level = (u8)Pokemon_GetValue(mon, MON_DATA_LEVEL, NULL);
    monData->isEgg = Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL);

    if (Pokemon_GetValue(mon, MON_DATA_NIDORAN_HAS_NICKNAME, NULL) == TRUE && monData->isEgg == FALSE) {
        monData->showGender = FALSE;
    } else {
        monData->showGender = TRUE;
    }

    monData->gender = Pokemon_GetGender(mon);
    monData->caughtBall = (u8)Pokemon_GetValue(mon, MON_DATA_POKEBALL, NULL);
    monData->type1 = (u8)Pokemon_GetValue(mon, MON_DATA_TYPE_1, NULL);
    monData->type2 = (u8)Pokemon_GetValue(mon, MON_DATA_TYPE_2, NULL);
    monData->OTID = Pokemon_GetValue(mon, MON_DATA_OT_ID, NULL);
    monData->curExp = Pokemon_GetValue(mon, MON_DATA_EXP, NULL);
    monData->OTGender = (u8)Pokemon_GetValue(mon, MON_DATA_OT_GENDER, NULL);
    monData->curLevelExp = Pokemon_GetSpeciesBaseExpAt(monData->species, monData->level);

    if (monData->level == MAX_POKEMON_LEVEL) {
        monData->nextLevelExp = monData->curLevelExp;
    } else {
        monData->nextLevelExp = Pokemon_GetSpeciesBaseExpAt(monData->species, monData->level + 1);
    }

    monData->curHP = (u16)Pokemon_GetValue(mon, MON_DATA_CURRENT_HP, NULL);
    monData->maxHP = (u16)Pokemon_GetValue(mon, MON_DATA_MAX_HP, NULL);
    monData->attack = (u16)Pokemon_GetValue(mon, MON_DATA_ATK, NULL);
    monData->defense = (u16)Pokemon_GetValue(mon, MON_DATA_DEF, NULL);
    monData->spAttack = (u16)Pokemon_GetValue(mon, MON_DATA_SP_ATK, NULL);
    monData->spDefense = (u16)Pokemon_GetValue(mon, MON_DATA_SP_DEF, NULL);
    monData->speed = (u16)Pokemon_GetValue(mon, MON_DATA_SPEED, NULL);
    monData->ability = (u8)Pokemon_GetValue(mon, MON_DATA_ABILITY, NULL);
    monData->nature = Pokemon_GetNature(mon);

    u16 i;
    u8 maxPP;
    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        monData->moves[i] = (u16)Pokemon_GetValue(mon, MON_DATA_MOVE1 + i, NULL);
        monData->curPP[i] = (u8)Pokemon_GetValue(mon, MON_DATA_MOVE1_CUR_PP + i, NULL);
        maxPP = (u8)Pokemon_GetValue(mon, MON_DATA_MOVE1_PP_UPS + i, NULL);
        monData->maxPP[i] = MoveTable_CalcMaxPP(monData->moves[i], maxPP);
    }

    monData->cool = (u8)Pokemon_GetValue(mon, MON_DATA_COOL, NULL);
    monData->beauty = (u8)Pokemon_GetValue(mon, MON_DATA_BEAUTY, NULL);
    monData->cute = (u8)Pokemon_GetValue(mon, MON_DATA_CUTE, NULL);
    monData->smart = (u8)Pokemon_GetValue(mon, MON_DATA_SMART, NULL);
    monData->tough = (u8)Pokemon_GetValue(mon, MON_DATA_TOUGH, NULL);
    monData->sheen = (u8)Pokemon_GetValue(mon, MON_DATA_SHEEN, NULL);
    monData->preferredFlavor = FLAVOR_MAX;

    for (i = 0; i < FLAVOR_MAX; i++) {
        if (Pokemon_GetFlavorAffinity(mon, i) == 1) {
            monData->preferredFlavor = i;
            break;
        }
    }

    monData->markings = Pokemon_GetValue(mon, MON_DATA_MARKS, NULL);
    monData->form = Pokemon_GetValue(mon, MON_DATA_FORM, NULL);
    monData->status = PokemonSummary_StatusIconAnimIdx(mon);

    if (Pokemon_CanSpreadPokerus(mon) == TRUE) {
        monData->pokerus = 2;
    } else if (Pokemon_InfectedWithPokerus(mon) == TRUE) {
        monData->pokerus = 1;

        if (monData->status == 7) {
            monData->status = 0;
        }
    } else {
        monData->pokerus = 0;
    }

    if (Pokemon_IsShiny(mon) == TRUE) {
        monData->isShiny = TRUE;
    } else {
        monData->isShiny = FALSE;
    }

    monData->ribbons[0] = 0;
    monData->ribbons[1] = 0;
    monData->ribbons[2] = 0;
    monData->ribbons[3] = 0;
    summaryScreen->ribbonMax = 0;

    for (i = 0; i < 80; i++) {
        if (Pokemon_GetValue(mon, sub_020923C0(i, 0), NULL) != 0) {
            monData->ribbons[i / 32] |= (1 << (i & 0x1f));
            summaryScreen->ribbonMax++;
        }
    }

    Pokemon_ExitDecryptionContext(mon, reencrypt);
}

static void PlayMonCry(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->monData.isEgg != FALSE) {
        return;
    }

    u8 cryDelay;
    PokeSprite_LoadCryDelay(summaryScreen->narcPlPokeData, &cryDelay, summaryScreen->monData.species, 1);

    if (summaryScreen->monData.species == SPECIES_CHATOT) {
        Sound_PlayDelayedChatotCry(summaryScreen->data->chatotCry, 0, 100, 0, cryDelay);
    } else {
        sub_0200590C(summaryScreen->monData.species, cryDelay, summaryScreen->monData.form);
    }
}

// ravetodo setinitialpage?
static void sub_0208D678(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->data->mode) {
    case SUMMARY_MODE_NORMAL:
    case SUMMARY_MODE_LOCK_MOVES:
        if (summaryScreen->monData.isEgg == FALSE) {
            summaryScreen->page = SUMMARY_PAGE_INFO;
        } else {
            summaryScreen->page = SUMMARY_PAGE_MEMO;
        }
        break;
    case SUMMARY_MODE_SELECT_MOVE:
        summaryScreen->page = SUMMARY_PAGE_BATTLE_MOVES;
        break;
    case SUMMARY_MODE_POFFIN:
    case SUMMARY_MODE_CONDITION:
        summaryScreen->page = SUMMARY_PAGE_CONDITION;
        break;
    }

    PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
    sub_0208ECF4(summaryScreen);
    sub_0208EF58(summaryScreen);
    sub_0208FA04(summaryScreen);
    sub_0208EDC4(summaryScreen);
    sub_0208F574(summaryScreen);
    sub_0208F34C(summaryScreen);
    sub_0208FD40(summaryScreen);
    sub_020904C4(summaryScreen);
    sub_0208D948(summaryScreen);
    sub_020919E8(summaryScreen);

    if (summaryScreen->data->mode == SUMMARY_MODE_SELECT_MOVE) {
        sub_0208E190(summaryScreen);
    }
}

void PokemonSummary_FlagVisiblePages(PokemonSummary *summary, const u8 *pages)
{
    summary->pageFlag = 0;

    for (u8 i = 0; i < SUMMARY_PAGE_MAX; i++) {
        if (pages[i] == SUMMARY_PAGE_MAX) {
            break;
        }

        summary->pageFlag |= (1 << pages[i]);
    }
}
// ravetodo set contest pages visible?
static void sub_0208D748(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->data->contest == 1) {
        return;
    }

    if (summaryScreen->data->pageFlag & (1 << SUMMARY_PAGE_CONDITION)) {
        summaryScreen->data->pageFlag ^= (1 << SUMMARY_PAGE_CONDITION);
    }

    if (summaryScreen->data->pageFlag & (1 << SUMMARY_PAGE_CONTEST_MOVES)) {
        summaryScreen->data->pageFlag ^= (1 << SUMMARY_PAGE_CONTEST_MOVES);
    }

    if (summaryScreen->data->pageFlag & (1 << SUMMARY_PAGE_RIBBONS)) {
        summaryScreen->data->pageFlag ^= (1 << SUMMARY_PAGE_RIBBONS);
    }
}

u8 PokemonSummary_PageIsVisble(PokemonSummaryScreen *summaryScreen, u32 page)
{
    if (summaryScreen->monData.isEgg != FALSE && page != SUMMARY_PAGE_MEMO && page != SUMMARY_PAGE_EXIT) {
        return FALSE;
    }

    return summaryScreen->data->pageFlag & (1 << page);
}

u8 PokemonSummary_CountVisiblePages(PokemonSummaryScreen *summaryScreen)
{
    u8 page;
    u8 countVisible = 0;

    for (page = 0; page < SUMMARY_PAGE_MAX; page++) {
        if (summaryScreen->data->pageFlag & (1 << page)) {
            countVisible++;
        }
    }

    return countVisible;
}

// ravetodo switchpagegfx?
static void sub_0208D7EC(PokemonSummaryScreen *summaryScreen, u8 page)
{
    if (summaryScreen->page == page) {
        return;
    }

    if (summaryScreen->data->mode == SUMMARY_MODE_SELECT_MOVE) {
        sub_0208E4EC(summaryScreen);
    }

    sub_0208FE34(summaryScreen);
    summaryScreen->page = page;
    PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);

    sub_0208ECF4(summaryScreen);
    sub_0208EDC4(summaryScreen);
    sub_0208EF58(summaryScreen);
    sub_0208FA04(summaryScreen);
    sub_0208F34C(summaryScreen);
    sub_0208FD40(summaryScreen);
    sub_0208FB54(summaryScreen, 0);

    Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_1, 0, 14, 4, 19, 20, 0);
    Bg_CopyTilemapBufferToVRAM(summaryScreen->bgConfig, BG_LAYER_MAIN_1);
    sub_020904C4(summaryScreen);
    sub_0208D948(summaryScreen);
    sub_020919E8(summaryScreen);

    if (summaryScreen->data->mode == SUMMARY_MODE_SELECT_MOVE) {
        sub_0208E508(summaryScreen);
    }
}

static void ChangePage(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 page = summaryScreen->page;

    while (TRUE) {
        page += delta;

        if (page < SUMMARY_PAGE_INFO) {
            page = SUMMARY_PAGE_EXIT;
        } else if (page > SUMMARY_PAGE_EXIT) {
            page = SUMMARY_PAGE_INFO;
        }

        if (summaryScreen->monData.isEgg == FALSE) {
            if ((summaryScreen->data->pageFlag & (1 << page)) != 0) {
                break;
            }
        } else {
            if ((summaryScreen->data->pageFlag & (1 << page)) != 0
                && (page == SUMMARY_PAGE_MEMO || page == SUMMARY_PAGE_EXIT)) {
                break;
            }
        }
    }

    if (page == summaryScreen->page) {
        return;
    }

    Sound_PlayEffect(SEQ_SE_DP_SELECT5);
    sub_0209219C(summaryScreen);
    sub_0208FB54(summaryScreen, 0);
    sub_0208D7EC(summaryScreen, page);
}

static u8 sub_0208D920(PokemonSummaryScreen *summaryScreen)
{
    u8 v0 = sub_020921E4(summaryScreen);

    if (v0 == 0xff) {
        return FALSE;
    }

    summaryScreen->buttonCount = 0;
    summaryScreen->buttonPos = v0;
    summaryScreen->buttonState = 0;

    return TRUE;
}

// ravetodo loadpagetiles or something?
static void sub_0208D948(PokemonSummaryScreen *summaryScreen)
{
    u32 memberIndex;
    if (summaryScreen->data->mode == SUMMARY_MODE_SELECT_MOVE && summaryScreen->data->move != MOVE_NONE) {
        if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
            memberIndex = 12;
        } else {
            memberIndex = 13;
        }
    } else {
        memberIndex = 3 + summaryScreen->page;
    }

    void *memberBuffer = NARC_AllocAndReadWholeMemberByIndexPair(NARC_INDEX_GRAPHIC__PL_PST_GRA, memberIndex, HEAP_ID_POKEMON_SUMMARY_SCREEN);
    NNSG2dScreenData *tilemap;
    NNS_G2dGetUnpackedScreenData(memberBuffer, &tilemap);

    Bg_LoadToTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_3, tilemap->rawData, 0, 0, 32, 32);
    Bg_ScheduleTilemapTransfer(summaryScreen->bgConfig, BG_LAYER_MAIN_3);
    Heap_FreeToHeap(memberBuffer);

    if (summaryScreen->page == SUMMARY_PAGE_INFO) {
        DrawExperienceProgressBar(summaryScreen);
    } else if (summaryScreen->page == SUMMARY_PAGE_SKILLS) {
        DrawHealthBar(summaryScreen);
    }
}

static void DrawHealthBar(PokemonSummaryScreen *summaryScreen)
{
    u16 v0;

    switch (HealthBar_Color(summaryScreen->monData.curHP, summaryScreen->monData.maxHP, 48)) {
    case BARCOLOR_MAX:
    case BARCOLOR_GREEN:
    case BARCOLOR_EMPTY:
        v0 = 0xc0 | 0xa000;
        break;
    case BARCOLOR_YELLOW:
        v0 = 0xe0 | 0xa000;
        break;
    case BARCOLOR_RED:
        v0 = 0x100 | 0xa000;
        break;
    }

    u8 pixelCount = App_PixelCount(summaryScreen->monData.curHP, summaryScreen->monData.maxHP, 48);
    u16 v1;

    for (u8 i = 0; i < 6; i++) {
        if (pixelCount >= 8) {
            v1 = v0 + 8;
        } else {
            v1 = v0 + pixelCount;
        }

        Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_3, v1, 24 + i, 6, 1, 1, 17);

        if (pixelCount < 8) {
            pixelCount = 0;
        } else {
            pixelCount -= 8;
        }
    }

    Bg_ScheduleTilemapTransfer(summaryScreen->bgConfig, BG_LAYER_MAIN_3);
}

static void DrawExperienceProgressBar(PokemonSummaryScreen *summaryScreen)
{
    u32 v0;
    u32 v1;

    if (summaryScreen->monData.level < MAX_POKEMON_LEVEL) {
        v0 = summaryScreen->monData.nextLevelExp - summaryScreen->monData.curLevelExp;
        v1 = summaryScreen->monData.curExp - summaryScreen->monData.curLevelExp;
    } else {
        v0 = 0;
        v1 = 0;
    }

    u8 pixelCount = App_PixelCount(v1, v0, 56);
    u16 v2;

    for (u8 i = 0; i < 7; i++) {
        if (pixelCount >= 8) {
            v2 = 0xac + 8;
        } else {
            v2 = 0xac + pixelCount;
        }

        Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_3, v2, 23 + i, 23, 1, 1, 17);

        if (pixelCount < 8) {
            pixelCount = 0;
        } else {
            pixelCount -= 8;
        }
    }

    Bg_ScheduleTilemapTransfer(summaryScreen->bgConfig, BG_LAYER_MAIN_3);
}

static void ChangeSummaryMon(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 monIndex = TryAdvanceSummaryMonIndex(summaryScreen, delta);

    if (monIndex == -1) {
        return;
    }

    summaryScreen->data->pos = (u8)monIndex;

    SetMonData(summaryScreen);
    PlayMonCry(summaryScreen);
    sub_0208FEA4(summaryScreen);
    sub_0208FF3C(summaryScreen);
    sub_0208FFE0(summaryScreen);

    if (summaryScreen->page == SUMMARY_PAGE_INFO) {
        DrawExperienceProgressBar(summaryScreen);
    } else if (summaryScreen->page == SUMMARY_PAGE_SKILLS) {
        DrawHealthBar(summaryScreen);
    } else if (summaryScreen->page == SUMMARY_PAGE_CONDITION) {
        sub_02091D50(summaryScreen);
    }

    sub_02092098(summaryScreen);
    PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
    sub_0208ECF4(summaryScreen);
    sub_0208EDC4(summaryScreen);
    sub_0208F16C(summaryScreen);
    sub_0208EF58(summaryScreen);
    sub_0208FA04(summaryScreen);
    sub_0208F71C(summaryScreen);
    sub_0208EE3C(summaryScreen);
    sub_0208EE9C(summaryScreen);
    sub_0208F34C(summaryScreen);
    sub_0208F574(summaryScreen);
    sub_020904C4(summaryScreen);
}

static s8 TryAdvanceSummaryMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    switch (summaryScreen->data->dataType) {
    case SUMMARY_DATA_MON:
        return TryAdvanceMonIndex(summaryScreen, delta);
    case SUMMARY_DATA_PARTY_MON:
        return TryAdvancePartyMonIndex(summaryScreen, delta);
    case SUMMARY_DATA_BOX_MON:
        return TryAdvanceBoxMonIndex(summaryScreen, delta);
    }

    return -1;
}

static BOOL CanAdvanceToEgg(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->data->mode == SUMMARY_MODE_POFFIN) {
        return FALSE;
    }

    if (summaryScreen->page != SUMMARY_PAGE_MEMO && summaryScreen->page != SUMMARY_PAGE_EXIT) {
        return FALSE;
    }

    return TRUE;
}

static s8 TryAdvanceMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 monIndex = (s8)summaryScreen->data->pos;
    Pokemon *mon = (Pokemon *)summaryScreen->data->monData;

    while (TRUE) {
        monIndex += delta;

        if (monIndex < 0 || monIndex >= summaryScreen->data->max) {
            return -1;
        }

        mon = (Pokemon *)((u32)summaryScreen->data->monData + Pokemon_GetStructSize() * monIndex);

        if (Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL) != FALSE) {
                if (CanAdvanceToEgg(summaryScreen) == TRUE) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    return monIndex;
}

static s8 TryAdvancePartyMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 monIndex = (s8)summaryScreen->data->pos;

    while (TRUE) {
        monIndex += delta;

        if (monIndex < 0 || monIndex >= summaryScreen->data->max) {
            return -1;
        }

        Pokemon *mon = Party_GetPokemonBySlotIndex(summaryScreen->data->monData, monIndex);

        if (Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL) != FALSE) {
                if (CanAdvanceToEgg(summaryScreen) == TRUE) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    return monIndex;
}

static s8 TryAdvanceBoxMonIndex(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 monIndex = (s8)summaryScreen->data->pos;
    BoxPokemon *boxMon = (BoxPokemon *)summaryScreen->data->monData;

    while (TRUE) {
        monIndex += delta;

        if (monIndex < 0 || monIndex >= summaryScreen->data->max) {
            return -1;
        }

        boxMon = (BoxPokemon *)((u32)summaryScreen->data->monData + BoxPokemon_GetStructSize() * monIndex);

        if (BoxPokemon_GetValue(boxMon, MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (BoxPokemon_GetValue(boxMon, MON_DATA_IS_EGG, NULL) != FALSE) {
                if (CanAdvanceToEgg(summaryScreen) == TRUE) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    return monIndex;
}

void *PokemonSummary_MonData(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->data->dataType) {
    case SUMMARY_DATA_MON:
        return (void *)((u32)summaryScreen->data->monData + (Pokemon_GetStructSize() * summaryScreen->data->pos));
    case SUMMARY_DATA_PARTY_MON:
        return (void *)Party_GetPokemonBySlotIndex(summaryScreen->data->monData, summaryScreen->data->pos);
    case SUMMARY_DATA_BOX_MON:
        return (void *)((u32)summaryScreen->data->monData + (BoxPokemon_GetStructSize() * summaryScreen->data->pos));
    }

    return NULL;
}
// ravetodo show move info?
static u8 sub_0208DD8C(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 136);
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 3, 0);
        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, FALSE);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[33]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);

        summaryScreen->cursor = 0;
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int v0 = Bg_GetXOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (v0 <= 64) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 0);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 2, 64);
        }
    } break;
    case 2:
        sub_02091420(summaryScreen);

        if (summaryScreen->data->mode != SUMMARY_MODE_LOCK_MOVES) {
            PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 152);
            PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);
        }

        UpdateMoveInfo(summaryScreen);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[11], TRUE);
        PokemonSummaryScreen_ShowMonIcon(summaryScreen);

        if (summaryScreen->monData.type1 != summaryScreen->monData.type2) {
            SpriteActor_DrawSprite(summaryScreen->unk_41C[12], 1);
        }

        CellActor_SetDrawFlag(summaryScreen->unk_41C[9], TRUE);
        return TRUE;
    }

    return FALSE;
}
// ravetodo hide move info?
static u8 sub_0208DEA4(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        SpriteActor_DrawSprite(summaryScreen->unk_41C[11], FALSE);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[12], FALSE);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[18], FALSE);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[19], FALSE);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[9], FALSE);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
        sub_0209145C(summaryScreen);
        PokemonSummaryScreen_ClearBattleInfoWindows(summaryScreen);
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int v0 = Bg_GetXOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (v0 >= 128) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 136);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 1, 64);
        }
    } break;
    case 2:
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[33]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 129);
        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, TRUE);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);
        return TRUE;
    }

    return FALSE;
}

static u8 TryChangeSelectedMove(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    s8 moveIndex = summaryScreen->cursor;

    while (TRUE) {
        moveIndex += delta;

        if (moveIndex < 0) {
            moveIndex = LEARNED_MOVES_MAX;
        } else if (moveIndex == LEARNED_MOVES_MAX + 1) {
            moveIndex = 0;
        }

        if (summaryScreen->monData.moves[moveIndex] != 0 || moveIndex == LEARNED_MOVES_MAX) {
            break;
        }
    }

    if (moveIndex != summaryScreen->cursor) {
        summaryScreen->cursor = moveIndex;
        return TRUE;
    }

    return FALSE;
}

static void UpdateMoveInfo(PokemonSummaryScreen *summaryScreen)
{
    PokemonSummaryScreen_UpdateMoveSelectorPos(summaryScreen);

    if (summaryScreen->cursor == 4) {
        if (summaryScreen->data->move != MOVE_NONE) {
            if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
                UpdateBattleMoveInfo(summaryScreen, summaryScreen->data->move);
            } else {
                UpdateContestMoveInfo(summaryScreen, summaryScreen->data->move);
            }
        } else {
            if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
                UpdateBattleMoveInfo(summaryScreen, SUMMARY_MOVE_NONE);
            } else {
                UpdateContestMoveInfo(summaryScreen, SUMMARY_MOVE_NONE);
            }
        }
    } else {
        if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
            UpdateBattleMoveInfo(summaryScreen, summaryScreen->monData.moves[summaryScreen->cursor]);
        } else {
            UpdateContestMoveInfo(summaryScreen, summaryScreen->monData.moves[summaryScreen->cursor]);
        }
    }
}

static void UpdateBattleMoveInfo(PokemonSummaryScreen *summaryScreen, u32 move)
{
    if (move == SUMMARY_MOVE_NONE) {
        PokemonSummaryScreen_ClearBattleInfoWindows(summaryScreen);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[18], FALSE);
    } else {
        PokemonSummaryScreen_PrintBattleMoveInfo(summaryScreen, move);
        PokemonSummaryScreen_UpdateMoveCategoryIcon(summaryScreen, move);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[18], TRUE);
    }
}

static void UpdateContestMoveInfo(PokemonSummaryScreen *summaryScreen, u32 move)
{
    UpdateAppealHearts(summaryScreen, move);

    if (move == SUMMARY_MOVE_NONE) {
        PokemonSummaryScreen_ClearContestInfoWindows(summaryScreen);
    } else {
        PokemonSummaryScreen_PrintContestMoveInfo(summaryScreen, move);
    }
}

static void SwapSelectedMoves(PokemonSummaryScreen *summaryScreen)
{
    void *monData = PokemonSummary_MonData(summaryScreen);

    if (summaryScreen->data->dataType == SUMMARY_DATA_BOX_MON) {
        BoxPokemon_SwapMoveSlots(monData, summaryScreen->cursor, summaryScreen->cursorTmp);
    } else {
        Pokemon_SwapMoveSlots(monData, summaryScreen->cursor, summaryScreen->cursorTmp);
    }

    u16 move = summaryScreen->monData.moves[summaryScreen->cursor];
    summaryScreen->monData.moves[summaryScreen->cursor] = summaryScreen->monData.moves[summaryScreen->cursorTmp];
    summaryScreen->monData.moves[summaryScreen->cursorTmp] = move;

    u8 curPP = summaryScreen->monData.curPP[summaryScreen->cursor];
    summaryScreen->monData.curPP[summaryScreen->cursor] = summaryScreen->monData.curPP[summaryScreen->cursorTmp];
    summaryScreen->monData.curPP[summaryScreen->cursorTmp] = curPP;

    u8 maxPP = summaryScreen->monData.maxPP[summaryScreen->cursor];
    summaryScreen->monData.maxPP[summaryScreen->cursor] = summaryScreen->monData.maxPP[summaryScreen->cursorTmp];
    summaryScreen->monData.maxPP[summaryScreen->cursorTmp] = maxPP;
}
// ravetodo switch move info?
static void sub_0208E190(PokemonSummaryScreen *summaryScreen)
{
    Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[33]);
    Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
    Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);

    Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 0);

    sub_02091420(summaryScreen);
    UpdateMoveInfo(summaryScreen);

    SpriteActor_DrawSprite(summaryScreen->unk_41C[11], TRUE);
    PokemonSummaryScreen_ShowMonIcon(summaryScreen);

    if (summaryScreen->monData.type1 != summaryScreen->monData.type2) {
        SpriteActor_DrawSprite(summaryScreen->unk_41C[12], TRUE);
    }

    CellActor_SetDrawFlag(summaryScreen->unk_41C[9], TRUE);
}

static u8 sub_0208E208(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 136);
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 3, 256);
        UpdateAppealHearts(summaryScreen, SUMMARY_MOVE_NONE);
        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, FALSE);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[33]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
        summaryScreen->cursor = 0;
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int v0 = Bg_GetXOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (v0 <= 64) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 0);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 2, 64);
        }
    } break;
    case 2:
        sub_02091420(summaryScreen);

        if (summaryScreen->data->mode != SUMMARY_MODE_LOCK_MOVES) {
            PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 152);
            PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);
        }

        UpdateMoveInfo(summaryScreen);
        PokemonSummaryScreen_ShowMonIcon(summaryScreen);
        sub_0208F844(summaryScreen);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[9], TRUE);

        return TRUE;
    }

    return FALSE;
}

static u8 sub_0208E308(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        sub_0208F964(summaryScreen);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[19], FALSE);
        UpdateAppealHearts(summaryScreen, SUMMARY_MOVE_NONE);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[9], FALSE);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
        sub_0209145C(summaryScreen);
        PokemonSummaryScreen_ClearContestInfoWindows(summaryScreen);
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int v0 = Bg_GetXOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (v0 >= 128) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 0, 136);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 1, 64);
        }
    } break;
    case 2:
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[33]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 158);
        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, TRUE);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);
        return TRUE;
    }

    return FALSE;
}
// ravetodo draw contest effect tiles or something?
static void DrawAppealHeart(PokemonSummaryScreen *summaryScreen, u16 param1, u8 param2)
{
    Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_2, param1, 2 + param2 * 2, (32 + 15), 1, 1, 16);
    Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_2, param1 + 1, 2 + param2 * 2 + 1, (32 + 15), 1, 1, 16);
    Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_2, param1 + 32, 2 + param2 * 2, (32 + 15) + 1, 1, 1, 16);
    Bg_FillTilemapRect(summaryScreen->bgConfig, BG_LAYER_MAIN_2, param1 + 33, 2 + param2 * 2 + 1, (32 + 15) + 1, 1, 1, 16);
}

static void DrawEmptyHearts(PokemonSummaryScreen *summaryScreen)
{
    for (u16 i = 0; i < MAX_APPEAL_HEARTS; i++) {
        DrawAppealHeart(summaryScreen, 0x12e, i); // ravetodo magic number
    }

    Bg_ScheduleTilemapTransfer(summaryScreen->bgConfig, BG_LAYER_MAIN_2);
}

static void UpdateAppealHearts(PokemonSummaryScreen *summaryScreen, u32 move)
{
    u32 effect;
    u16 i;
    s8 numHearts;

    DrawEmptyHearts(summaryScreen);

    if (move != SUMMARY_MOVE_NONE) {
        effect = MoveTable_LoadParam(move, MOVEATTRIBUTE_CONTEST_EFFECT);
        numHearts = sub_02095734(effect) / POINTS_PER_APPEAL_HEART;

        for (i = 0; i < numHearts; i++) {
            DrawAppealHeart(summaryScreen, 0x12c, i); // ravetodo magic number
        }
    }

    Bg_ScheduleTilemapTransfer(summaryScreen->bgConfig, BG_LAYER_MAIN_2);
}

static void sub_0208E4EC(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
        PokemonSummaryScreen_ClearBattleInfoWindows(summaryScreen);
    } else {
        PokemonSummaryScreen_ClearContestInfoWindows(summaryScreen);
    }
}

static void sub_0208E508(PokemonSummaryScreen *summaryScreen)
{
    sub_02091420(summaryScreen);
    UpdateMoveInfo(summaryScreen);
    PokemonSummaryScreen_ShowMonIcon(summaryScreen);

    if (summaryScreen->page == SUMMARY_PAGE_BATTLE_MOVES) {
        sub_0208F964(summaryScreen);
        SpriteActor_DrawSprite(summaryScreen->unk_41C[11], TRUE);

        if (summaryScreen->monData.type1 != summaryScreen->monData.type2) {
            SpriteActor_DrawSprite(summaryScreen->unk_41C[12], TRUE);
        }

        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 3, 0);
    } else {
        sub_0208F844(summaryScreen);
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 3, 256);
    }
}

static u8 sub_0208E57C(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, BG_OFFSET_UPDATE_SET_X, 256);
        Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, BG_OFFSET_UPDATE_SET_Y, 0);

        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, FALSE);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[30]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->extraWindows[0]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);

        summaryScreen->ribbonPos = 0;
        summaryScreen->ribbonState = 0;
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int yOffset = Bg_GetYOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (yOffset >= 48) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, BG_OFFSET_UPDATE_SET_Y, 56);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, BG_OFFSET_UPDATE_ADD_Y, 16);
        }
    } break;
    case 2:
        PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 181);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[67], 1);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[70], 1);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[63], 0);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[64], 0);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[65], 0);
        CellActor_SetDrawFlag(summaryScreen->unk_41C[66], 0);
        sub_0208E794(summaryScreen, 0);

        return TRUE;
    }

    return FALSE;
}

static u8 sub_0208E6A8(PokemonSummaryScreen *summaryScreen)
{
    switch (summaryScreen->subscreen) {
    case 0:
        summaryScreen->ribbonPos = 0;
        summaryScreen->ribbonState = 0;
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->extraWindows[1]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->extraWindows[2]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->extraWindows[3]);
        Window_ClearAndScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, NULL);
        sub_0208FA04(summaryScreen);
        summaryScreen->subscreen = 1;
        break;
    case 1: {
        int v0 = Bg_GetYOffset(summaryScreen->bgConfig, BG_LAYER_MAIN_2);

        if (v0 <= 8) {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 3, 0);
            summaryScreen->subscreen = 2;
        } else {
            Bg_ScheduleScroll(summaryScreen->bgConfig, BG_LAYER_MAIN_2, 5, 16);
        }
    } break;
    case 2:
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[6]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[32]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[30]);
        Window_ScheduleCopyToVRAM(&summaryScreen->staticWindows[35]);
        Window_ScheduleCopyToVRAM(&summaryScreen->extraWindows[0]);
        PokemonSummaryScreen_ClearWindowAndPrintText(summaryScreen, 180);
        PokemonSummaryScreen_UpdatePageArrows(summaryScreen, TRUE);
        PokemonSummaryScreen_UpdateAButtonSprite(summaryScreen, &summaryScreen->staticWindows[35]);

        return TRUE;
    }

    return FALSE;
}
// ravetodo scroll ribbon pos/handle ribbon input or something
static void sub_0208E794(PokemonSummaryScreen *summaryScreen, s8 delta)
{
    u8 v0;
    u8 v1;

    v0 = summaryScreen->ribbonPos;
    v1 = summaryScreen->ribbonState;

    if (delta == 1) {
        if ((summaryScreen->ribbonPos & 3) == 3) {
            return;
        }

        if ((summaryScreen->ribbonState * 4 + summaryScreen->ribbonPos + 1) < summaryScreen->ribbonMax) {
            summaryScreen->ribbonPos += 1;
        }
    } else if (delta == -1) {
        if ((summaryScreen->ribbonPos & 3) == 0) {
            return;
        }

        summaryScreen->ribbonPos -= 1;
    } else if (delta == 4) { // ravetodo ribbons per row const
        if (summaryScreen->ribbonPos < 4) {
            if ((summaryScreen->ribbonState * 4 + summaryScreen->ribbonPos + 4) >= summaryScreen->ribbonMax) {
                if ((summaryScreen->ribbonMax > 4) && ((summaryScreen->ribbonMax % 4) != 0)) {
                    summaryScreen->ribbonPos = summaryScreen->ribbonMax % 4 + 3;
                }
            } else {
                summaryScreen->ribbonPos += 4;
            }
        } else {
            if ((summaryScreen->ribbonState * 4 + 8) < summaryScreen->ribbonMax) {
                summaryScreen->ribbonState++;

                if ((summaryScreen->ribbonState * 4 + summaryScreen->ribbonPos) >= summaryScreen->ribbonMax) {
                    summaryScreen->ribbonPos = summaryScreen->ribbonMax % 4 + 3;
                }
            }
        }
    } else if (delta == -4) {
        if (summaryScreen->ribbonPos >= 4) {
            summaryScreen->ribbonPos -= 4;
        } else if (summaryScreen->ribbonState != 0) {
            summaryScreen->ribbonState--;
        }
    }

    if (v0 != summaryScreen->ribbonPos || v1 != summaryScreen->ribbonState) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
    }

    summaryScreen->ribbonNum = PokemonSummary_RibbonAt(summaryScreen, summaryScreen->ribbonPos);

    sub_0208FB00(summaryScreen);

    if (v1 != summaryScreen->ribbonState) {
        sub_0208FAA4(summaryScreen);
    }

    sub_020910E4(summaryScreen);
    sub_02090F84(summaryScreen);

    if (summaryScreen->ribbonState != 0) {
        CellActor_SetDrawFlag(summaryScreen->unk_41C[68], TRUE);
    } else {
        CellActor_SetDrawFlag(summaryScreen->unk_41C[68], FALSE);
    }

    if ((summaryScreen->ribbonState * 4 + 8) < summaryScreen->ribbonMax) {
        CellActor_SetDrawFlag(summaryScreen->unk_41C[69], TRUE);
    } else {
        CellActor_SetDrawFlag(summaryScreen->unk_41C[69], FALSE);
    }
}

u8 PokemonSummary_RibbonAt(PokemonSummaryScreen *summaryScreen, u8 pos)
{
    u16 i;
    u8 v1 = pos + summaryScreen->ribbonState * 4;
    u8 v2 = 0;

    for (i = 0; i < 80; i++) {
        if ((summaryScreen->monData.ribbons[i / 32] & (1 << (i & 0x1f))) != 0) {
            if (v1 == v2) {
                return (u8)i;
            }

            v2++;
        }
    }

    return 0;
}

static int sub_0208E958(PokemonSummaryScreen *summaryScreen)
{
    if (summaryScreen->monData.sheen == 255) {
        Font_LoadScreenIndicatorsPalette(0, 14 * 32, HEAP_ID_POKEMON_SUMMARY_SCREEN);
        LoadMessageBoxGraphics(summaryScreen->bgConfig, BG_LAYER_MAIN_1, (1024 - (18 + 12)), 13, Options_Frame(summaryScreen->data->options), HEAP_ID_POKEMON_SUMMARY_SCREEN);
        sub_02091610(summaryScreen, 0xff);
        summaryScreen->data->returnMode = 1;

        return 17;
    }

    summaryScreen->data->returnMode = 0;
    return 18;
}

void PokemonSummary_SetPlayerProfile(PokemonSummary *summary, const TrainerInfo *trainerInfo)
{
    summary->OTName = TrainerInfo_Name(trainerInfo);
    summary->OTID = TrainerInfo_ID(trainerInfo);
    summary->OTGender = (u8)TrainerInfo_Gender(trainerInfo);
}
// ravetodo consts
u32 PokemonSummary_StatusIconChar(void)
{
    return 64;
}

u32 PokemonSummary_StatusIconPltt(void)
{
    return 65;
}

u32 PokemonSummary_StatusIconCell(void)
{
    return 63;
}

u32 PokemonSummary_StatusIconAnim(void)
{
    return 62;
}

u32 PokemonSummary_StatusIconAnimIdx(Pokemon *mon)
{
    u32 statusCondition = Pokemon_GetValue(mon, MON_DATA_STATUS_CONDITION, NULL);

    if (Pokemon_GetValue(mon, MON_DATA_CURRENT_HP, NULL) == 0) {
        return 6;
    } else if ((statusCondition & (0x8 | 0x80)) != 0) {
        return 4;
    } else if ((statusCondition & 0x7) != 0) {
        return 3;
    } else if ((statusCondition & 0x10) != 0) {
        return 5;
    } else if ((statusCondition & 0x20) != 0) {
        return 2;
    } else if ((statusCondition & 0x40) != 0) {
        return 1;
    }

    return 7;
}
