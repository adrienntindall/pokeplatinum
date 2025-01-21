#include "battle/battle_input.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/battle_system.h"
#include "struct_decls/font_oam.h"
#include "struct_decls/struct_0200C6E4_decl.h"
#include "struct_decls/struct_0200C704_decl.h"
#include "struct_decls/struct_02012744_decl.h"
#include "struct_decls/struct_02012B20_decl.h"
#include "struct_defs/sprite_manager_allocation.h"
#include "struct_defs/sprite_template.h"
#include "struct_defs/struct_0200D0F4.h"
#include "struct_defs/struct_020127E8.h"

#include "battle/battle_display.h"
#include "battle/move_display_info.h"
#include "battle/ov16_0223DF00.h"
#include "battle/ov16_0226DB7C.h"
#include "battle/ov16_0226DE44.h"
#include "battle/struct_ov16_02260C00.h"
#include "battle/struct_ov16_02260F14.h"
#include "battle/struct_ov16_022623F0.h"
#include "battle/struct_ov16_02269668.h"
#include "battle/struct_ov16_0226C378.h"
#include "battle/struct_ov16_0226DC24_decl.h"
#include "battle/struct_ov16_0226DEEC_decl.h"
#include "gmm/message_bank_battle_strings.h"
#include "overlay011/ov11_0221F800.h"

#include "assert.h"
#include "bg_window.h"
#include "cell_actor.h"
#include "core_sys.h"
#include "enums.h"
#include "font.h"
#include "graphics.h"
#include "heap.h"
#include "inlines.h"
#include "math.h"
#include "message.h"
#include "message_util.h"
#include "move_table.h"
#include "narc.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "render_text.h"
#include "render_window.h"
#include "strbuf.h"
#include "string_template.h"
#include "sys_task.h"
#include "sys_task_manager.h"
#include "text.h"
#include "touch_screen.h"
#include "unk_02005474.h"
#include "unk_0200C6E4.h"
#include "unk_02012744.h"
#include "unk_02017728.h"
#include "unk_0201E86C.h"
#include "unk_0207C908.h"
#include "unk_0208C098.h"

typedef struct {
    BattleInput *battleInput;
    SysTask *unk_04;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12;
    u8 unk_13;
} UnkStruct_ov16_0226B988;

typedef struct {
    s16 unk_00;
    s16 unk_02;
} UnkStruct_ov16_02270294;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_ov16_022702F4;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
} UnkStruct_ov16_0226A3F4;

typedef struct {
    SysTask *unk_00;
    u8 *unk_04;
    void *unk_08;
    u8 *unk_0C;
    UnkStruct_ov16_0226A3F4 unk_10;
    u16 unk_1C;
} UnkStruct_ov16_02268A14_sub3_sub1;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    union {
        struct {
            u8 unk_00;
        } unk_04_val1;
        struct {
            int unk_00;
        } unk_04_val2;
        struct {
            const s16 *unk_00;
            const UnkStruct_ov16_022702F4 *unk_04;
            int unk_08;
            u8 unk_0C;
            u8 unk_0D;
            u8 unk_0E;
            u8 unk_0F;
            u8 unk_10;
            UnkStruct_ov16_02270294 unk_11;
        } unk_04_val3;
        struct {
            UnkStruct_ov16_02268A14_sub3_sub1 *unk_00[4];
            UnkStruct_ov16_02268A14_sub3_sub1 *unk_10;
            NNSG2dCharacterData *unk_14;
            void *unk_18;
            int unk_1C;
        } unk_04_val4;
        s16 unk_04_val5[2];
    };
} UnkStruct_ov16_02268A14_sub3;

typedef struct {
    int unk_00;
    s16 unk_04;
    s16 unk_06;
    u8 unk_08;
    u8 unk_09;
} UnkStruct_ov16_02268A14_sub4;

typedef struct {
    const UnkStruct_ov16_022702F4 *unk_00;
    u8 unk_04;
    s8 unk_05;
} UnkStruct_ov16_02268A14_sub1;

typedef struct {
    FontOAM *fontOAM;
    SpriteManagerAllocation spriteManAlloc;
    u16 unk_10;
} BattleInputTextObject;

typedef struct {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
} UnkStruct_ov16_02268FCC;

typedef struct {
    u8 unk_00;
    s8 unk_01;
    s8 unk_02;
    u8 unk_03;
} BattleCursorMove;

typedef union {
    UnkStruct_ov16_02269668 val1;
    UnkStruct_ov16_02260C00 val2;
    UnkStruct_ov16_02260F14 val3;
    UnkStruct_ov16_022623F0 val4;
} UnkStruct_ov16_02268A14_sub2;

typedef struct {
    Window unk_00;
    u16 unk_10;
    u16 unk_12;
} BattleInputTextImage;

typedef struct {
    MoveDisplayInfo moveDisplay;
    u16 *typeIcon[LEARNED_MOVES_MAX];
    BattleInputTextImage moveNameText[LEARNED_MOVES_MAX];
    BattleInputTextImage curPPText[LEARNED_MOVES_MAX];
    BattleInputTextImage maxPPText[LEARNED_MOVES_MAX];
} MoveDisplayObject;

struct BattleInput_t {
    BattleSystem *battleSystem;
    u8 *unk_04;
    SysTask *unk_08;
    SysTask *unk_0C;
    SysTask *unk_10;
    UnkStruct_ov16_02268A14_sub1 unk_14;
    UnkStruct_ov16_02268A14_sub2 unk_1A;
    u16 *unk_3C[7];
    u16 *unk_58;
    u16 *unk_5C;
    u16 *unk_60;
    SysTask *unk_64;
    MoveDisplayObject unk_68[4];
    UnkStruct_02012744 *unk_4C8;
    BattleInputTextObject textObj[13];
    UnkStruct_02012B20 *unk_5B8;
    CellActorData *unk_5BC[6];
    CellActorData *unk_5D4[6];
    CellActorData *unk_5EC[4];
    CellActorData *unk_5FC[4];
    CellActorData *unk_60C[4];
    SysTask *unk_61C[4];
    UnkStruct_ov16_02268FCC unk_62C[6];
    SysTask *unk_664;
    u8 unk_668;
    u8 unk_669;
    u8 unk_66A;
    s8 unk_66B;
    u8 unk_66C;
    u8 unk_66D;
    u8 unk_66E;
    u8 unk_66F;
    u8 unk_670;
    s16 unk_672;
    u8 unk_674;
    s16 unk_676;
    SysTask *unk_678;
    UnkStruct_ov16_02268A14_sub3 unk_67C;
    UnkStruct_ov16_02268A14_sub4 unk_6A0;
    s32 unk_6AC;
    s32 unk_6B0;
    s32 unk_6B4;
    BattleCursor *cursor;
    BattleCursorMove unk_6BC;
    u8 unk_6C0;
    u8 unk_6C1;
    struct {
        CatchingTutorialFinger *finger;
        u8 unk_04;
        u8 state;
        u8 unk_06;
    } catchingTutorial;
};

typedef struct {
    u16 unk_00;
    u16 unk_02;
    union {
        struct {
            u16 unk_04_val1_unk_00;
            u16 unk_04_val1_unk_02;
            u16 unk_04_val1_unk_04;
            u16 unk_04_val1_unk_06;
        };
        u16 unk_04_val2[4];
    };
    union {
        struct {
            u16 unk_0C_val1_unk_00;
            u16 unk_0C_val1_unk_02;
            u16 unk_0C_val1_unk_04;
            u16 unk_0C_val1_unk_06;
        };
        u16 unk_0C_val2[4];
    };
    const TouchScreenRect *unk_14;
    const int *unk_18;
    const u8 *unk_1C;
    int (*unk_20)(BattleInput *battleInput, int param1);
    void (*funcSaveCursorPos)(BattleInput *battleInput, int param1);
    void (*unk_28)(BattleInput *battleInput, int param1, int param2);
    int (*unk_2C)(BattleInput *battleInput, int param1, int param2);
} UnkStruct_ov16_02270670;

enum {
    BITO_FIGHT = 0,
    BITO_BAG,
    BITO_POKEMON,
    BITO_RUN,

    BITO_MOVE_1 = 0,
    BITO_MOVE_2,
    BITO_MOVE_3,
    BITO_MOVE_4,
    BITO_UNK_5,
    BIT0_UNK_6,
    BIT0_UNK_7,
    BIT0_UNK_8,
    BIT0_UNK_9,
    BITO_PP_1,
    BITO_PP_2,
    BITO_PP_3,
    BITO_PP_4,
};

static void *BattleInput_New(void);
static void ov16_02269654(BattleInput *battleInput, int param1, int param2);
static void ov16_02269668(BattleInput *battleInput, int param1, int param2);
static void ov16_022698A8(BattleInput *battleInput, int param1, int param2);
static void ov16_022698BC(BattleInput *battleInput, int param1, int param2);
static void ov16_02269924(BattleInput *battleInput, int param1, int param2);
static void ov16_02269938(BattleInput *battleInput, int param1, int param2);
static void ov16_02269E94(BattleInput *battleInput, int param1, int param2);
static int ov16_0226A318(BattleInput *battleInput, int param1, int param2);
static int ov16_0226A3F4(BattleInput *battleInput, int param1, int param2);
static void ov16_022699AC(BattleInput *battleInput, int param1, int param2);
static void ov16_0226AF0C(BattleInput *battleInput);
static void ov16_0226AFF4(BattleInput *battleInput);
static void ov16_0226B028(BattleInput *battleInput);
static void ov16_0226B2BC(SysTaskFunc param0, BattleInput *battleInput);
static void ov16_0226B2F0(BattleInput *battleInput);
static int ov16_0226A4A4(BattleInput *battleInput, int param1, int param2);
static int ov16_0226A634(BattleInput *battleInput, int param1, int param2);
static int ov16_0226A528(BattleInput *battleInput, int param1, int param2);
static void BattleInput_CreateYesNoTextObjects(BattleInput *battleInput, int param1, int param2);
static void ov16_02269D14(BattleInput *battleInput, int param1, int param2);
static void ov16_02269DB0(BattleInput *battleInput, int param1, int param2);
static void ov16_02269F68(BattleInput *battleInput, int param1, int param2);
static void ov16_0226A04C(BattleInput *battleInput, int param1, int param2);
static void ov16_0226A12C(BattleInput *battleInput, int param1, int param2);
static void ov16_0226B06C(BattleInput *battleInput, int param1, int param2);
static void ov16_0226B088(BattleInput *battleInput, int param1);
static void ov16_0226B0DC(BattleInput *battleInput, int param1);
static int ov16_0226A934(u8 param0);
static void ov16_02268F00(BattleInput *battleInput);
void ov16_02269168(BattleInput *battleInput, u8 param1[], u8 param2[]);
void ov16_022691BC(BattleInput *battleInput);
void ov16_02269218(BattleInput *battleInput);
static void ov16_0226BC50(SysTask *param0, void *param1);
static void ov16_0226B198(void);
static void ov16_0226BCBC(SysTask *param0, void *param1);
static void ov16_0226B1C4(BattleInput *battleInput, int param1, int param2);
static void ov16_0226B1E8(BattleInput *battleInput);
static void ov16_0226B390(SysTask *param0, void *param1);
static void ov16_0226B4E0(SysTask *param0, void *param1);
static void ov16_0226B780(SysTask *param0, void *param1);
static void ov16_0226B264(BattleInput *battleInput, int param1, u8 *param2, int param3);
static void ov16_0226B20C(BattleInput *battleInput, u8 *param1, int param2);
static void ov16_0226B318(BattleInput *battleInput, int param1);
void ov16_0226947C(BattleInput *battleInput, int param1, int param2);
static void ov16_022694A8(SysTask *param0, void *param1);
static void ov16_0226B314(BattleInput *battleInput, int param1);
static void BattleInput_CreateTextObject(BattleInput *battleInput, BattleInputTextObject *param1, const Strbuf *param2, enum Font param3, TextColor param4, int param5, int param6, int param7, int param8, int param9, BattleInputTextImage *param10);
static void ov16_0226AAC0(BattleInput *battleInput);
static void ov16_0226A698(BattleInput *battleInput);
static void ov16_0226A718(BattleInput *battleInput);
static void ov16_0226A768(BattleInput *battleInput);
static CellActorData *ov16_0226A7A4(BattleInput *battleInput, Pokemon *param1, int param2, int param3, int param4, int param5);
static void ov16_0226A928(SysTask *param0, void *param1);
static void ov16_0226B988(SysTask *param0, void *param1);
static void ov16_0226BA88(SysTask *param0, void *param1);
static void ov16_0226BB94(void *param0);
static TextColor GetPPTextColor(int param0, int param1);
void ov16_0226BCCC(BattleInput *battleInput, int param1);
BOOL ov16_0226BCD0(BattleInput *battleInput);
static void ov16_0226BCE4(SysTask *param0, void *param1);
static void ov16_02268FCC(SysTask *param0, void *param1);
static int ov16_0226BE48(BattleInput *battleInput);
static int ov16_0226BEC0(BattleInput *battleInput, int param1);
static int ov16_0226C1F8(BattleInput *battleInput, int param1);
static int ov16_0226C3C8(BattleInput *battleInput, int param1);
static int ov16_0226CA14(BattleInput *battleInput, int param1);
static u32 ov16_0226CB10(BattleCursorMove *param0, int param1, int param2, const u8 *param3);
static void BattleInput_SaveBattlerCursorPosition(BattleInput *battleInput, int param1);
static void BattleInput_SaveBattlerMovePosition(BattleInput *battleInput, int param1);
static void ov16_0226C9B8(BattleInput *battleInput, int param1);
static void ov16_0226B31C(BattleInput *battleInput, const s16 *param1, const UnkStruct_ov16_022702F4 *param2, int param3, int param4);
static MoveDisplayObject *ov16_0226ABD4(BattleInput *battleInput, int param1);
static void ov16_0226ABE8(BattleInput *battleInput);
static void ov16_0226A95C(const Strbuf *param0, int param1, int *param2, int *param3);
static void ov16_0226AEA0(BattleInput *battleInput, const Strbuf *param1, enum Font param2, BattleInputTextImage *param3, TextColor param4);
static void ov16_0226AAF8(BattleInput *battleInput);
static int ov16_0226C100(BattleInput *battleInput, int param1);
static void ov16_0226BD74(SysTask *param0, void *param1);
static int BattleInput_CatchingTutorialMain(BattleInput *battleInput);
static int BattleInput_CatchingTutorialFight(BattleInput *battleInput);
static int BattleInput_CatchingTutorialMove(BattleInput *battleInput);
static int BattleInput_CatchingTutorialBag(BattleInput *battleInput);
static void inline_ov16_0226B314(SysTaskFunc param0, BattleInput *battleInput);
static void inline_ov16_0226B318_1(SysTask *param0, void *param1);
static void inline_ov16_0226B318_1_sub(BattleInput *battleInput);
static void inline_ov16_0226B314_1(SysTask *param0, void *param1);

__attribute__((aligned(4))) static const u16 Unk_ov16_02270264[] = {
    0x31,
    0x2A,
    0x2F,
    0x2B,
    0x2C,
    0x30,
    0x2D
};

__attribute__((aligned(4))) static const u16 Unk_ov16_022702B4[][2] = {
    { 0x20, 0x3E },
    { 0xA0, 0x3E },
    { 0x20, 0x7E },
    { 0xA0, 0x7E }
};

__attribute__((aligned(4))) static const u16 Unk_ov16_02270284[][2] = {
    { 0x3B, 0x3E },
    { 0xBB, 0x3E },
    { 0x3B, 0x7E },
    { 0xBB, 0x7E }
};

__attribute__((aligned(4))) static const u16 Unk_ov16_022702D4[][2] = {
    { 0x4C, 0x3E },
    { 0xCC, 0x3E },
    { 0x4C, 0x7E },
    { 0xCC, 0x7E }
};

__attribute__((aligned(4))) static const u16 Unk_ov16_02270328[][2] = {
    { 0x3C, 0x74 },
    { 0xC4, 0x20 },
    { 0xC4, 0x74 },
    { 0x3C, 0x20 },
    { 0x80, 0xB2 }
};

__attribute__((aligned(4))) static const u16 Unk_ov16_02270304[][2] = {
    { 0x3C, 0x74 },
    { 0xC4, 0x38 },
    { 0xC4, 0x74 },
    { 0x3C, 0x38 }
};

static const BgTemplate Unk_ov16_02270540[] = {
    { 0x0, 0x0, 0x800, 0x0, 0x1, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01, 0x0, 0x0, 0x0, 0x0 },
    { 0x0, 0x0, 0x800, 0x0, 0x1, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01, 0x0, 0x0, 0x0, 0x0 },
    { 0x0, 0x0, 0x800, 0x0, 0x1, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01, 0x0, 0x0, 0x0, 0x0 },
    { 0x0, 0x0, 0x800, 0x0, 0x1, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01, 0x0, 0x0, 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov16_02270350[] = {
    { 0x18, 0x90, 0x0, 0xFF },
    { 0x90, 0xC0, 0x0, 0x50 },
    { 0x90, 0xC0, 0xB0, 0xFF },
    { 0x98, 0xC0, 0x58, 0xA8 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_022702A4[NELEMS(Unk_ov16_02270350) - 1] = {
    0x1,
    0x2,
    0x3,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_02270A08[NELEMS(Unk_ov16_02270350) - 1] = {
    0x1,
    0x2,
    0x3,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701EC[2][3] = {
    { 0x0, 0x0, 0x0 },
    { 0x1, 0x3, 0x2 }
};

static const TouchScreenRect Unk_ov16_02270214[] = {
    { 0x18, 0x90, 0x0, 0xFF },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov16_02270258[] = {
    { 0x28, 0x80, 0x18, 0xE8 },
    { 0x98, 0xC0, 0x58, 0xA8 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_022702E4[NELEMS(Unk_ov16_02270350) - 1] = {
    0x1,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_02270A04[NELEMS(Unk_ov16_02270350) - 1] = {
    0x1,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701CC[2][1] = {
    { 0x0 },
    { 0x1 }
};

static const TouchScreenRect Unk_ov16_0227038C[] = {
    { 0x98, 0xC0, 0x8, 0xF8 },
    { 0x18, 0x50, 0x0, 0x80 },
    { 0x18, 0x50, 0x80, 0xFF },
    { 0x58, 0x90, 0x0, 0x80 },
    { 0x58, 0x90, 0x80, 0xFF },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_02270364[NELEMS(Unk_ov16_0227038C) - 1] = {
    0xFF,
    0x1,
    0x2,
    0x3,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_02270A14[NELEMS(Unk_ov16_0227038C) - 1] = {
    0x4,
    0x8,
    0x9,
    0xA,
    0xB
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701E4[3][2] = {
    { 0x1, 0x2 },
    { 0x3, 0x4 },
    { 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov16_0227024C[] = {
    { 0x28, 0x60, 0x8, 0xF8 },
    { 0x70, 0xA8, 0x8, 0xF8 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_02270224[NELEMS(Unk_ov16_0227024C) - 1] = {
    0x1,
    0xFF
};

__attribute__((aligned(4))) static const u8 Unk_ov16_02270A00[NELEMS(Unk_ov16_0227024C) - 1] = {
    0x1,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701C8[2][1] = {
    { 0x0 },
    { 0x1 }
};

static const TouchScreenRect Unk_ov16_022703BC[] = {
    { 0x58, 0x90, 0x0, 0x78 },
    { 0x8, 0x50, 0x88, 0xFF },
    { 0x58, 0x90, 0x88, 0xFF },
    { 0x8, 0x50, 0x0, 0x78 },
    { 0x98, 0xC0, 0x8, 0xF8 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_02270314[NELEMS(Unk_ov16_022703BC) - 1] = {
    0x1,
    0x2,
    0x3,
    0x4,
    0xFF
};

__attribute__((aligned(4))) static const u8 Unk_ov16_02270A0C[NELEMS(Unk_ov16_022703BC) - 1] = {
    0x6,
    0xC,
    0xD,
    0x5,
    0x4
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701DC[3][2] = {
    { 0x3, 0x1 },
    { 0x0, 0x2 },
    { 0x4, 0x4 }
};

static const TouchScreenRect Unk_ov16_02270204[] = {
    { 0x98, 0xC0, 0x0, 0xFF },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const int Unk_ov16_022701D8[NELEMS(Unk_ov16_02270204) - 1] = {
    0x1
};

__attribute__((aligned(4))) static const u8 Unk_ov16_022701C4[NELEMS(Unk_ov16_02270204) - 1] = {
    0x4
};

static const UnkStruct_ov16_02270670 Unk_ov16_02270670[] = {
    {
        0x1C,
        0xF2,
        { 0xFFFF, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269654,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269654,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269668,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269668,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270214,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_022698A8,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0x2, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270214,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_022698BC,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269654,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_02270350,
        Unk_ov16_022702A4,
        Unk_ov16_02270A08,
        ov16_0226BEC0,
        BattleInput_SaveBattlerCursorPosition,
        ov16_02269668,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270258,
        Unk_ov16_022702E4,
        Unk_ov16_02270A04,
        ov16_0226C100,
        NULL,
        ov16_02269924,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x1, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270258,
        Unk_ov16_022702E4,
        Unk_ov16_02270A04,
        ov16_0226C100,
        NULL,
        ov16_02269938,
        ov16_0226A318,
    },
    {
        0x1C,
        0xF2,
        { 0x3, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227038C,
        Unk_ov16_02270364,
        Unk_ov16_02270A14,
        ov16_0226C1F8,
        BattleInput_SaveBattlerMovePosition,
        ov16_022699AC,
        ov16_0226A3F4,
    },
    {
        0x1C,
        0xF2,
        { 0x4, 0x5, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_022703BC,
        Unk_ov16_02270314,
        Unk_ov16_02270A0C,
        ov16_0226C3C8,
        ov16_0226C9B8,
        ov16_0226A12C,
        ov16_0226A528,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227024C,
        Unk_ov16_02270224,
        Unk_ov16_02270A00,
        ov16_0226CA14,
        NULL,
        BattleInput_CreateYesNoTextObjects,
        ov16_0226A4A4,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227024C,
        Unk_ov16_02270224,
        Unk_ov16_02270A00,
        ov16_0226CA14,
        NULL,
        ov16_02269D14,
        ov16_0226A4A4,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227024C,
        Unk_ov16_02270224,
        Unk_ov16_02270A00,
        ov16_0226CA14,
        NULL,
        ov16_02269DB0,
        ov16_0226A4A4,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227024C,
        Unk_ov16_02270224,
        Unk_ov16_02270A00,
        ov16_0226CA14,
        NULL,
        ov16_02269F68,
        ov16_0226A4A4,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0xFFFF, 0x0, 0xFFFF },
        { 0x2, 0x1, 0x3, 0x0 },
        Unk_ov16_0227024C,
        Unk_ov16_02270224,
        Unk_ov16_02270A00,
        ov16_0226CA14,
        NULL,
        ov16_0226A04C,
        ov16_0226A4A4,
    },
    {
        0x1C,
        0xF2,
        { 0x6, 0x4, 0x0, 0xFFFF },
        { 0x2, 0x3, 0x3, 0x0 },
        Unk_ov16_02270204,
        Unk_ov16_022701D8,
        Unk_ov16_022701C4,
        NULL,
        NULL,
        ov16_02269E94,
        ov16_0226A634,
    },
};

static const SpriteTemplate Unk_ov16_02270414 = {
    0xC,
    0xD,
    0x0,
    0x0,
    0xA,
    0x0,
    NNS_G2D_VRAM_TYPE_2DSUB,
    { 0x4E37, 0x4E37, 0x4E2F, 0x4E2F, 0xFFFFFFFF, 0xFFFFFFFF },
    0x1,
    0x0,
};

static const SpriteTemplate Unk_ov16_02270448 = {
    0xF6,
    0x9,
    0x0,
    0x0,
    0xB,
    0x1,
    NNS_G2D_VRAM_TYPE_2DSUB,
    { 0x4E38, 0x4E37, 0x4E30, 0x4E30, 0xFFFFFFFF, 0xFFFFFFFF },
    0x1,
    0x0,
};

static const SpriteTemplate Unk_ov16_0227047C = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x64,
    0x0,
    NNS_G2D_VRAM_TYPE_2DSUB,
    { 0x4E39, 0x4E34, 0x4E31, 0x4E31, 0xFFFFFFFF, 0xFFFFFFFF },
    0x1,
    0x0,
};

static const SpriteTemplate Unk_ov16_022704B0 = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x64,
    0x0,
    NNS_G2D_VRAM_TYPE_2DSUB,
    { 0x4E45, 0x4E36, 0x4E35, 0x4E35, 0xFFFFFFFF, 0xFFFFFFFF },
    0x1,
    0x0,
};

__attribute__((aligned(4))) static const s16 Unk_ov16_022703A4[][3] = {
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_022702F4[] = {
    { 0x4, 0xF, 0x2, 0x1D },
    { 0x11, 0x17, 0x0, 0x9 },
    { 0x11, 0x17, 0x16, 0x1F },
    { 0x12, 0x17, 0xB, 0x14 },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_022703F4[][3] = {
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_02270378[] = {
    { 0x2, 0x9, 0x0, 0xF },
    { 0x2, 0x9, 0x10, 0x1F },
    { 0xA, 0x11, 0x0, 0xF },
    { 0xA, 0x11, 0x10, 0x1F },
    { 0x12, 0x17, 0x1, 0x1E },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_0227022C[] = {
    0x22F,
    0x22C,
    0x229,
    0x226,
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_02270274[] = {
    { 0x3, 0x9, 0x0, 0xF },
    { 0x3, 0x9, 0x10, 0x1F },
    { 0xB, 0x11, 0x0, 0xF },
    { 0xB, 0x11, 0x10, 0x1F },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_022703D4[][3] = {
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
    { 0x0, 0xC0, 0x180 },
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_0227033C[] = {
    { 0xA, 0x11, 0x0, 0xE },
    { 0x0, 0x9, 0x11, 0x1F },
    { 0xA, 0x11, 0x11, 0x1F },
    { 0x0, 0x9, 0x0, 0xE },
    { 0x12, 0x17, 0x1, 0x1E },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_022701FC[] = {
    0x238,
    0x235,
    0x232,
    0x23B,
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_022702C4[] = {
    { 0xB, 0x11, 0x0, 0xE },
    { 0x1, 0x9, 0x11, 0x1F },
    { 0xB, 0x11, 0x11, 0x1F },
    { 0x1, 0x9, 0x0, 0xE },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_02270240[][3] = {
    { 0x0, 0x5, 0xA },
    { 0x0, 0xC0, 0x180 },
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_0227021C[] = {
    { 0xD, 0x14, 0x0, 0x1F },
    { 0x4, 0xB, 0x0, 0x1F },
};

__attribute__((aligned(4))) static const s16 Unk_ov16_022701F4[3] = {
    0x0,
    0xC0,
    0x180
};

__attribute__((aligned(4))) static const UnkStruct_ov16_022702F4 Unk_ov16_022701D0[] = {
    { 0x12, 0x17, 0x0, 0x1F }
};

static const UnkStruct_ov16_02270294 Unk_ov16_02270294[] = {
    { 0x80, 0x4C },
    { 0x28, 0xA4 },
    { 0xD8, 0xA4 },
    { 0x80, 0xA8 }
};

__attribute__((aligned(4))) static const int Unk_ov16_022705B0[][4] = {
    { 0x1, 0x1, 0x1, 0x1 },
    { 0x0, 0x1, 0x0, 0x1 },
    { 0x0, 0x1, 0x1, 0x1 },
    { 0x1, 0x1, 0x1, 0x1 },
    { 0x1, 0x0, 0x0, 0x0 },
    { 0x1, 0x0, 0x1, 0x0 },
    { 0x0, 0x0, 0x1, 0x0 },
    { 0x1, 0x1, 0x0, 0x1 },
    { 0x0, 0x1, 0x1, 0x1 },
    { 0x1, 0x1, 0x0, 0x1 },
    { 0x1, 0x0, 0x1, 0x0 },
    { 0x0, 0x1, 0x0, 0x1 },
};

static const struct {
    u16 unk_00;
    u16 unk_02;
} Unk_ov16_022704E4[] = {
    { 0xF3, 0x10B },
    { 0xF4, 0x10C },
    { 0xF5, 0x10D },
    { 0xF6, 0x10E },
    { 0xF7, 0x10F },
    { 0xF8, 0x110 },
    { 0xF9, 0x111 },
    { 0xFA, 0x112 },
    { 0xFB, 0x113 },
    { 0xFC, 0x114 },
    { 0xFD, 0x115 },
    { 0xFE, 0x116 },
    { 0xFF, 0x117 },
    { 0x100, 0x118 },
    { 0x101, 0x119 },
    { 0x102, 0x11A },
    { 0x103, 0x11B },
    { 0x11C, 0x11D },
    { 0xFFFF, 0xFFFF },
    { 0xFFFF, 0xFFFF },
    { 0xFFFF, 0xFFFF },
    { 0xFFFF, 0xFFFF },
    { 0xFFFF, 0xFFFF },
};

static void *BattleInput_New(void)
{
    BattleInput *battleInput = Heap_AllocFromHeap(HEAP_ID_BATTLE, sizeof(BattleInput));
    MI_CpuClear8(battleInput, sizeof(BattleInput));
    battleInput->unk_66B = -1;

    return battleInput;
}

void ov16_02268744(BgConfig *bgConfig)
{
    for (int i = 0; i < NELEMS(Unk_ov16_02270540); i++) {
        Bg_InitFromTemplate(bgConfig, 4 + i, &Unk_ov16_02270540[i], 0);
        Bg_FillTilemap(bgConfig, 4 + i, (0x6000 / 0x20 - 1));
        Bg_SetOffset(bgConfig, 4 + i, 0, 0);
        Bg_SetOffset(bgConfig, 4 + i, 3, 0);
    }
}

void ov16_022687A0(BgConfig *bgConfig)
{
    for (int i = 0; i < NELEMS(Unk_ov16_02270540); i++) {
        Bg_ToggleLayer(4 + i, 0);
        Bg_FreeTilemapBuffer(bgConfig, 4 + i);
    }
}

void *BattleInput_NewInit(NARC *param0, NARC *param1, BattleSystem *battleSystem, int gender, u8 *param4)
{
    BattleInput *battleInput;
    PaletteData *palette;
    int v2;

    battleInput = BattleInput_New();
    battleInput->battleSystem = battleSystem;
    battleInput->unk_66D = gender;
    battleInput->unk_04 = param4;

    if (battleInput->unk_04 != NULL) {
        battleInput->unk_6C0 = *param4;
    }

    palette = BattleSystem_GetPaletteData(battleSystem);
    v2 = ov16_0223E240(battleSystem);

    if (v2 >= NELEMS(Unk_ov16_022704E4)) {
        v2 = 0;
        GF_ASSERT(0);
    }

    battleInput->unk_4C8 = sub_02012744(13, 5);
    battleInput->unk_678 = SysTask_Start(ov16_0226BCE4, battleInput, 1310);

    NNSG2dScreenData *screenData;
    void *v4;
    int i;
    int v6;

    for (i = 0; i < 7; i++) {
        battleInput->unk_3C[i] = Heap_AllocFromHeap(HEAP_ID_BATTLE, 0x800);

        if ((BattleSystem_GetBattleType(battleSystem) & BATTLE_TYPE_FRONTIER) && (Unk_ov16_02270264[i] == 49)) {
            v6 = 170;
        } else {
            v6 = Unk_ov16_02270264[i];
        }

        v4 = Graphics_GetScrnData(7, v6, 1, &screenData, HEAP_ID_BATTLE);

        MI_CpuCopy32(screenData->rawData, battleInput->unk_3C[i], 0x800);
        Heap_FreeToHeap(v4);
    }

    u16 *v7;
    int v8;

    v8 = (BattleSystem_GetBattleType(battleSystem) & BATTLE_TYPE_FRONTIER) ? 340 : 242;
    battleInput->unk_58 = Heap_AllocFromHeap(HEAP_ID_BATTLE, 0x200);

    PaletteData_LoadBufferFromFileStart(palette, 7, v8, 5, 1, 0, 0);

    if (Unk_ov16_022704E4[v2].unk_00 != 0xffff) {
        PaletteData_LoadBufferFromFileStart(palette, 7, Unk_ov16_022704E4[v2].unk_00, 5, 1, 0x20, 0);
    }

    v7 = PaletteData_GetUnfadedBuffer(palette, 1);
    MI_CpuCopy16(v7, battleInput->unk_58, 0x200);

    for (int i = 0; i < 4; i++) {
        MI_CpuFill8(&battleInput->unk_68[i].moveDisplay, 0xff, sizeof(MoveDisplayInfo));
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            battleInput->unk_68[i].typeIcon[j] = Heap_AllocFromHeap(5, sub_0208C098(6));
        }
    }

    NNSG2dPaletteData *v13;
    void *v14;
    int v15;

    battleInput->unk_5C = Heap_AllocFromHeap(5, 0x40);
    battleInput->unk_60 = Heap_AllocFromHeap(5, 0x40);

    MI_CpuCopy16(battleInput->unk_58, battleInput->unk_5C, 0x20);
    MI_CpuCopy16(&battleInput->unk_58[7 * 16], &battleInput->unk_5C[16 * 1], 0x20);

    if (BattleSystem_GetBattleType(battleSystem) & BATTLE_TYPE_FRONTIER) {
        v15 = 341;
    } else if (Unk_ov16_022704E4[v2].unk_02 != 0xffff) {
        v15 = Unk_ov16_022704E4[v2].unk_02;
    } else {
        v15 = 267;
    }

    v14 = Graphics_GetPlttData(7, v15, &v13, 5);

    if (BattleSystem_GetBattleType(battleSystem) & BATTLE_TYPE_FRONTIER) {
        MI_CpuCopy16(v13->pRawData, battleInput->unk_60, 0x40);
    } else {
        MI_CpuCopy16(v13->pRawData, battleInput->unk_60, 0x20);
    }

    Heap_FreeToHeap(v14);
    RenderControlFlags_ZeroSpeedUpBattle();
    RenderControlFlags_ZeroWaitBattle();

    battleInput->unk_64 = SysTask_Start(ov16_0226BD74, battleInput, 55000);

    return battleInput;
}

void BattleInput_Free(BattleInput *battleInput)
{
    int i;

    if (battleInput->unk_04 != NULL) {
        *battleInput->unk_04 = battleInput->unk_6C0;
    }

    ov16_0226B1E8(battleInput);
    ov16_02268F00(battleInput);
    ov16_02268B8C(battleInput);

    sub_020127BC(battleInput->unk_4C8);
    SysTask_Done(battleInput->unk_678);

    for (i = 0; i < 7; i++) {
        Heap_FreeToHeap(battleInput->unk_3C[i]);
    }

    Heap_FreeToHeap(battleInput->unk_58);
    ov16_0226ABE8(battleInput);
    Heap_FreeToHeap(battleInput->unk_5C);
    Heap_FreeToHeap(battleInput->unk_60);
    SysTask_Done(battleInput->unk_64);
    Heap_FreeToHeap(battleInput);
}

void ov16_02268A88(BattleInput *battleInput)
{
    BgConfig *bgConfig;
    SpriteRenderer *spriteRenderer;
    SpriteGfxHandler *v2;
    PaletteData *v3;
    int i;

    spriteRenderer = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);
    bgConfig = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v3 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    int v5;

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_FRONTIER) {
        v5 = 169;
    } else {
        v5 = 28;
    }

    Graphics_LoadTilesToBgLayer(7, v5, bgConfig, 4, 0, 0x6000, 1, HEAP_ID_BATTLE);

    sub_0207C9EC(spriteRenderer, v2, 20017, 20017);
    MoveTypeIcon_LoadPalette(BattleSystem_GetPaletteData(battleInput->battleSystem), 3, spriteRenderer, v2, NNS_G2D_VRAM_TYPE_2DSUB, 20020);

    for (i = 0; i < 4; i++) {
        sub_0207C948(spriteRenderer, v2, NNS_G2D_VRAM_TYPE_2DSUB, TYPE_NORMAL, 20025 + i);
    }

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_CATCH_TUTORIAL) {
        CatchingTutorialFinger_LoadResources(spriteRenderer, v2, HEAP_ID_BATTLE, v3, 20412, 20036, 20406, 20395);
        battleInput->catchingTutorial.finger = CatchingTutorialFinger_Create(spriteRenderer, v2, HEAP_ID_BATTLE, 20412, 20036, 20406, 20395, 10, 0);
    }
}

void ov16_02268B8C(BattleInput *battleInput)
{
    int i;
    SpriteRenderer *v1;
    SpriteGfxHandler *v2;

    v1 = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);

    for (i = 0; i < 4; i++) {
        sub_0207CA34(v2, 20025 + i);
    }

    sub_0207CA3C(v2, 20020);
    sub_0207CA44(v2, 20017, 20017);

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_CATCH_TUTORIAL) {
        CatchingTutorialFinger_Free(battleInput->catchingTutorial.finger);
        CatchingTutorialFinger_FreeResources(v2, 20412, 20036, 20406, 20395);
    }
}

void ov16_02268C04(NARC *param0, NARC *param1, BattleInput *battleInput, int param3, int param4, void *param5)
{
    const UnkStruct_ov16_02270670 *v0, *v1;
    int i;
    BgConfig *v3;
    SpriteRenderer *v4;
    SpriteGfxHandler *v5;

    if (param5 != NULL) {
        MI_CpuCopy8(param5, &battleInput->unk_1A, sizeof(UnkStruct_ov16_02268A14_sub2));
    }

    battleInput->unk_66E = 0;

    v3 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v4 = ov16_0223E010(battleInput->battleSystem);
    v5 = ov16_0223E018(battleInput->battleSystem);

    if (battleInput->unk_66B == -1) {
        param4 = 1;
        v1 = NULL;
    } else {
        v1 = &Unk_ov16_02270670[battleInput->unk_66B];
    }

    v0 = &Unk_ov16_02270670[param3];

    PaletteData_LoadBuffer(BattleSystem_GetPaletteData(battleInput->battleSystem), battleInput->unk_58, 1, 0, 0x200);

    for (i = 0; i < 4; i++) {
        if ((v0->unk_04_val2[i] != 0xffff) && ((param4 == 1) || (v0->unk_04_val2[i] != v1->unk_04_val2[i]))) {
            Bg_LoadTilemapBuffer(v3, 4 + i, battleInput->unk_3C[v0->unk_04_val2[i]], 0x800);
            Bg_ScheduleTilemapTransfer(v3, 4 + i);
        }
    }

    SpriteRenderer_LoadPalette(BattleSystem_GetPaletteData(battleInput->battleSystem), 3, v4, v5, param1, 72, 0, 7, NNS_G2D_VRAM_TYPE_2DSUB, 20023);
    battleInput->unk_66B = param3;

    G2S_SetBlendAlpha((GX_BLEND_PLANEMASK_BG1), (GX_BLEND_BGALL), 8, 12);
    ov16_0226B1E8(battleInput);

    if (v0->unk_28 != NULL) {
        v0->unk_28(battleInput, param3, param4);
    }

    SysTask_ExecuteAfterVBlank(ov16_0226BC50, battleInput, 10);
}

void ov16_02268D40(NARC *param0, BattleInput *battleInput)
{
    int i;
    SpriteRenderer *spriteRenderer;
    SpriteGfxHandler *v2;

    GF_ASSERT(battleInput->unk_5BC[0] == NULL && battleInput->unk_5D4[0] == NULL);

    spriteRenderer = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);

    SpriteRenderer_LoadCharResObjFromOpenNarc(spriteRenderer, v2, param0, 208, 1, NNS_G2D_VRAM_TYPE_2DSUB, 20023);
    SpriteRenderer_LoadCellResObjFromOpenNarc(spriteRenderer, v2, param0, 207, 1, 20015);
    SpriteRenderer_LoadAnimResObjFromOpenNarc(spriteRenderer, v2, param0, 209, 1, 20015);

    SpriteRenderer_LoadCharResObjFromOpenNarc(spriteRenderer, v2, param0, 205, 1, NNS_G2D_VRAM_TYPE_2DSUB, 20024);
    SpriteRenderer_LoadCellResObjFromOpenNarc(spriteRenderer, v2, param0, 204, 1, 20016);
    SpriteRenderer_LoadAnimResObjFromOpenNarc(spriteRenderer, v2, param0, 206, 1, 20016);

    for (i = 0; i < 6; i++) {
        battleInput->unk_5BC[i] = SpriteActor_LoadResources(spriteRenderer, v2, &Unk_ov16_02270414);
        sub_0200D4D0(battleInput->unk_5BC[i]->unk_00, 12 + 19 * i, 13, ((192 + 80) << FX32_SHIFT));
        sub_0200D6A4(battleInput->unk_5BC[i], 1);

        battleInput->unk_5D4[i] = SpriteActor_LoadResources(spriteRenderer, v2, &Unk_ov16_02270448);
        sub_0200D4D0(battleInput->unk_5D4[i]->unk_00, 246 + -12 * i, 9, ((192 + 80) << FX32_SHIFT));
    }

    ov16_02269218(battleInput);

    GF_ASSERT(battleInput->unk_08 == NULL);
    battleInput->unk_08 = SysTask_Start(ov16_02268FCC, battleInput, 1300);

    PaletteData *v3;

    v3 = BattleSystem_GetPaletteData(battleInput->battleSystem);
    BattleCursor_LoadResources(spriteRenderer, v2, v3, 5, 20411, 20035, 20405, 20394);
    battleInput->cursor = BattleCursor_New(spriteRenderer, v2, 5, 20411, 20035, 20405, 20394, 5, 0);
}

static void ov16_02268F00(BattleInput *battleInput)
{
    int i;
    SpriteRenderer *spriteRenderer;
    SpriteGfxHandler *v2;

    GF_ASSERT(battleInput->unk_5BC[0] != NULL && battleInput->unk_5D4[0] != NULL);

    spriteRenderer = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);

    SpriteGfxHandler_UnloadCharObjById(v2, 20023);
    SpriteGfxHandler_UnloadCellObjById(v2, 20015);
    SpriteGfxHandler_UnloadAnimObjById(v2, 20015);
    SpriteGfxHandler_UnloadCharObjById(v2, 20024);
    SpriteGfxHandler_UnloadCellObjById(v2, 20016);
    SpriteGfxHandler_UnloadAnimObjById(v2, 20016);
    SpriteGfxHandler_UnloadPlttObjById(v2, 20023);

    for (i = 0; i < 6; i++) {
        sub_0200D0F4(battleInput->unk_5BC[i]);
        battleInput->unk_5BC[i] = NULL;

        sub_0200D0F4(battleInput->unk_5D4[i]);
        battleInput->unk_5D4[i] = NULL;
    }

    SysTask_Done(battleInput->unk_08);
    battleInput->unk_08 = NULL;

    BattleCursor_FreeResources(v2, 20411, 20035, 20405, 20394);
    BattleCursor_Free(battleInput->cursor);
}

static void ov16_02268FCC(SysTask *task, void *data)
{
    BattleInput *battleInput = data;
    int i;
    UnkStruct_ov16_02268FCC *v2;

    for (i = 0; i < 6; i++) {
        v2 = &battleInput->unk_62C[i];

        switch (v2->unk_03) {
        case 0:
        default:
            if (sub_0200D400(battleInput->unk_5BC[i]->unk_00) == 0) {
                break;
            }

            if (v2->unk_02 >= 87) {
                v2->unk_04 = 0;
                v2->unk_05 = 10;
            } else {
                break;
            }

            v2->unk_05 += LCRNG_Next() % 8;
            v2->unk_07 = 2;
            v2->unk_03++;
            break;
        case 1:
            if (v2->unk_05 > 0) {
                v2->unk_05--;
                break;
            }

            v2->unk_03++;
            break;
        case 2:
        case 4:
            sub_0200D7C0(battleInput->unk_5BC[i], 0x800);
            v2->unk_00 += 0x180;

            sub_0200D500(battleInput->unk_5BC[i], 12 + 19 * i + v2->unk_00 / 0x100, 13, ((192 + 80) << FX32_SHIFT));
            v2->unk_06++;

            if (v2->unk_06 >= v2->unk_07) {
                v2->unk_06 = 0;

                if (v2->unk_03 == 2) {
                    v2->unk_03++;
                } else {
                    sub_0200D79C(battleInput->unk_5BC[i], 0);
                    sub_0200D500(battleInput->unk_5BC[i], 12 + 19 * i, 13, ((192 + 80) << FX32_SHIFT));

                    v2->unk_00 = 0;

                    if (v2->unk_08 < 1) {
                        v2->unk_08++;

                        if (v2->unk_07 > 1) {
                            v2->unk_07--;
                        }

                        v2->unk_03 = 2;
                    } else {
                        v2->unk_08 = 0;
                        v2->unk_03 = 0;
                    }
                }
            }

            break;
        case 3:
            sub_0200D7C0(battleInput->unk_5BC[i], -0x800);
            v2->unk_00 -= 0x180;

            sub_0200D500(battleInput->unk_5BC[i], 12 + 19 * i + v2->unk_00 / 0x100, 13, ((192 + 80) << FX32_SHIFT));
            v2->unk_06++;

            if (v2->unk_06 >= v2->unk_07 * 2) {
                v2->unk_06 = 0;
                v2->unk_03++;
            }
            break;
        }
    }
}

void ov16_0226914C(BattleInput *battleInput, const u8 *param1)
{
    int i;

    for (i = 0; i < 6; i++) {
        battleInput->unk_62C[i].unk_02 = param1[i];
    }
}

void ov16_02269168(BattleInput *battleInput, u8 param1[], u8 param2[])
{
    int i, v1;

    for (i = 0; i < 6; i++) {
        v1 = ov16_0226A934(param1[i]);

        CellActor_SetAnim(battleInput->unk_5BC[i]->unk_00, v1);
        SpriteActor_UpdateObject(battleInput->unk_5BC[i]->unk_00);

        v1 = ov16_0226A934(param2[i]);

        CellActor_SetAnim(battleInput->unk_5D4[i]->unk_00, v1);
        SpriteActor_UpdateObject(battleInput->unk_5D4[i]->unk_00);
    }
}

void ov16_022691BC(BattleInput *battleInput)
{
    int i;

    GF_ASSERT(battleInput->unk_5BC[0] != NULL && battleInput->unk_5D4[0] != NULL);

    for (i = 0; i < 6; i++) {
        SpriteActor_DrawSprite(battleInput->unk_5BC[i]->unk_00, 1);
    }

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_TRAINER) {
        for (i = 0; i < 6; i++) {
            SpriteActor_DrawSprite(battleInput->unk_5D4[i]->unk_00, 1);
        }
    }
}

void ov16_02269218(BattleInput *battleInput)
{
    int i;

    GF_ASSERT(battleInput->unk_5BC[0] != NULL && battleInput->unk_5D4[0] != NULL);

    for (i = 0; i < 6; i++) {
        SpriteActor_DrawSprite(battleInput->unk_5BC[i]->unk_00, 0);
        SpriteActor_DrawSprite(battleInput->unk_5D4[i]->unk_00, 0);
    }
}

int BattleInput_CheckTouch(BattleInput *battleInput)
{
    int v0, v1, v2, v3;
    const UnkStruct_ov16_02270670 *v4;
    int v5 = 0;

    GF_ASSERT(battleInput->unk_66B != -1);

    v4 = &Unk_ov16_02270670[battleInput->unk_66B];

    if ((v4->unk_14 == NULL) || (battleInput->unk_66E == 1)) {
        return 0xffffffff;
    }

    GF_ASSERT(v4->unk_18 != NULL);

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_CATCH_TUTORIAL) {
        v1 = BattleInput_CatchingTutorialMain(battleInput);
    } else {
        v1 = sub_02022664(v4->unk_14);

        if (v1 == 0xffffffff) {
            v1 = ov16_0226BE48(battleInput);
            v5++;
        }
    }

    if (v1 == 0xffffffff) {
        v0 = 0xffffffff;
        v3 = 0xff;
    } else {
        v0 = v4->unk_18[v1];
        v3 = v4->unk_1C[v1];
    }

    if (v4->unk_2C != NULL) {
        v0 = v4->unk_2C(battleInput, v0, v3);

        if (v0 != 0xffffffff) {
            if (v4->funcSaveCursorPos != NULL) {
                v4->funcSaveCursorPos(battleInput, v1);
            }

            MI_CpuClear8(&battleInput->unk_6BC, sizeof(BattleCursorMove));
            ov16_0226DDE8(battleInput->cursor);

            if (v5 > 0) {
                battleInput->unk_6C0 = 1;
            } else {
                battleInput->unk_6C0 = 0;
            }
        }
    }

    return v0;
}

BOOL ov16_02269348(BattleInput *battleInput)
{
    if ((battleInput->unk_0C == NULL) && (battleInput->unk_10 == NULL) && (ov16_0226BCD0(battleInput) == 1)) {
        return 1;
    }

    return 0;
}

int ov16_02269368(int param0, int param1)
{
    switch (param0) {
    case 0x0:
        return (param1 == 4) ? 9 : 8;
    case 0x1:
    case 0x2:
    case 0x10:
        return (param1 == 4) ? 6 : 4;
    case 0x4:
    case 0x80:
        return 1;
    case 0x8:
        return (param1 == 4) ? 7 : 2;
    case 0x100:
        return (param1 == 4) ? 4 : 6;
    case 0x40:
        return 3;
    case 0x200:
        return 10;
    case 0x20:
        return 5;
    case 0x400:
        return 11;
    default:
        GF_ASSERT(0);
        return 0;
    }
}

void ov16_0226940C(BattleInput *battleInput)
{
    int v0;

    GXS_SetVisibleWnd(GX_WNDMASK_W0);
    G2S_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, 1);
    G2S_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, 1);

    v0 = 255 - (battleInput->unk_6AC / 0x100);

    if (v0 < 0) {
        v0 = 0;
    }

    G2S_SetWnd0Position(v0, 0, 255, 192);
}

void ov16_0226947C(BattleInput *battleInput, int param1, int param2)
{
    if (battleInput->unk_6AC == param2 * 0x100) {
        return;
    }

    battleInput->unk_6B0 = param1;
    battleInput->unk_6B4 = param2 << 8;

    SysTask_Start(ov16_022694A8, battleInput, 1200);
}

static void ov16_022694A8(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    int v1 = 0;
    BgConfig *v2;

    v2 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    battleInput->unk_6AC += battleInput->unk_6B0;

    if (((battleInput->unk_6B0 <= 0) && (battleInput->unk_6AC <= battleInput->unk_6B4)) || ((battleInput->unk_6B0 > 0) && (battleInput->unk_6AC >= battleInput->unk_6B4))) {
        battleInput->unk_6AC = battleInput->unk_6B4;
        v1 = 1;
    }

    Bg_SetOffset(v2, 6, 0, battleInput->unk_6AC / 0x100);
    ov16_0226940C(battleInput);

    if (v1 == 1) {
        Bg_FillTilemap(v2, 7, (0x6000 / 0x20 - 1));
        Bg_ToggleLayer(7, 0);
        Bg_SetPriority(7, 0);
        GXS_SetVisibleWnd(GX_WNDMASK_NONE);
        SysTask_Done(param0);
        return;
    }
}

static void ov16_02269550(BattleInput *battleInput, int param1)
{
    BOOL v0;
    UnkStruct_ov16_0226B988 *v1;

    battleInput->unk_66E = 1;

    G2S_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3, 1);
    G2S_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3, 1);
    G2S_SetWnd1InsidePlane(GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3, 1);
    G2S_SetWnd0Position(0, 0, 255, (18 * 8));
    G2S_SetWnd1Position(0, (18 * 8), 255, 192);
    GXS_SetVisibleWnd(GX_WNDMASK_W0 | GX_WNDMASK_W1);

    v1 = Heap_AllocFromHeap(5, sizeof(UnkStruct_ov16_0226B988));
    MI_CpuClear8(v1, sizeof(UnkStruct_ov16_0226B988));

    v1->battleInput = battleInput;
    v1->unk_12 = param1;
    v1->unk_08 = -(255 * 100);
    v1->unk_0A = (40 * 100);
    v1->unk_0C = ((255 * 100) - v1->unk_08) / 100;
    v1->unk_0E = ((40 * 100) - v1->unk_0A) / 100;

    Sound_PlayEffect(1806);
    SysTask_Start(ov16_0226B988, v1, 1210);

    v0 = SetHBlankCallback(ov16_0226BB94, v1);
    GF_ASSERT(v0 == 1);

    v1->unk_04 = SysTask_ExecuteOnVBlank(ov16_0226BA88, v1, 10);
}

static void ov16_02269654(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    v0 = battleInput->unk_1A.val1.unk_00;

    ov16_02269668(battleInput, param1, param2);
    ov16_02269550(battleInput, v0);
}

static void ov16_02269668(BattleInput *battleInput, int param1, int param2)
{
    Strbuf *v0, *v1, *v2, *v3;
    MessageLoader *v4;
    int v5;
    UnkStruct_ov16_02269668 *v6;

    v6 = &battleInput->unk_1A.val1;
    v5 = v6->unk_00;

    battleInput->unk_6C1 = v6->unk_08;

    v4 = BattleSystem_MessageLoader(battleInput->battleSystem);

    battleInput->unk_66A = v5;

    if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_SAFARI) {
        v0 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00931); // BALL
        v1 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00932); // BAIT
        v2 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00933); // MUD
    } else if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_PAL_PARK) {
        v0 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_01223); // BALL
        v1 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00932); // BAIT
        v2 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00933); // MUD
    } else {
        v0 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00924); // FIGHT
        v1 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00925); // BAG
        v2 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00926); // POKéMON
    }

    if (battleInput->unk_6C1 == 1) {
        v3 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00928); // CANCEL
        battleInput->unk_66F = 1;
    } else {
        v3 = MessageLoader_GetNewStrbuf(v4, pl_msg_00000368_00927); // RUN
        battleInput->unk_66F = 0;
    }

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v0, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 84, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], v1, FONT_SUBSCREEN, TEXT_COLOR(4, 5, 6), 2, 20023, 40, 170, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[2], v2, FONT_SUBSCREEN, TEXT_COLOR(7, 8, 9), 2, 20023, 216, 170, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[3], v3, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 178, 1, NULL);

    Strbuf_Free(v0);
    Strbuf_Free(v1);
    Strbuf_Free(v2);
    Strbuf_Free(v3);

    if ((BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_NO_MOVES) == 0) {
        Pokemon *v7;
        CellActorData *v8;
        int v9, v10;

        v7 = BattleSystem_PartyPokemon(battleInput->battleSystem, v6->unk_01, v6->unk_02);
        ov16_0226A698(battleInput);
        v8 = ov16_0226A7A4(battleInput, v7, v5, v6->unk_04, v6->unk_06, v6->unk_03);

        sub_020129A4(battleInput->textObj[0].fontOAM, &v9, &v10);

        if (v5 == 4) {
            v9 += battleInput->textObj[0].unk_10 + 32 / 2;
        } else {
            v9 -= 32 / 2;
        }

        sub_0200D500(v8, v9, v10 - (((192 + 80) << FX32_SHIFT) >> FX32_SHIFT), ((192 + 80) << FX32_SHIFT));
    }
}

static void ov16_022698A8(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    v0 = battleInput->unk_1A.val1.unk_00;

    ov16_022698BC(battleInput, param1, param2);
    ov16_02269550(battleInput, v0);
}

static void ov16_022698BC(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    v0 = battleInput->unk_1A.val1.unk_00;

    ov16_02269668(battleInput, param1, param2);

    {
        BgConfig *v1;

        v1 = BattleSystem_GetBgConfig(battleInput->battleSystem);

        Bg_FillTilemapRect(v1, 4, (0x6000 / 0x20 - 1), 0, 0x10, 32, 8, 17);
        Bg_ScheduleTilemapTransfer(v1, 5);
    }

    sub_020129D0(battleInput->textObj[1].fontOAM, 0);
    sub_020129D0(battleInput->textObj[2].fontOAM, 0);
    sub_020129D0(battleInput->textObj[3].fontOAM, 0);
}

static void ov16_02269924(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    v0 = battleInput->unk_1A.val1.unk_00;

    ov16_02269938(battleInput, param1, param2);
    ov16_02269550(battleInput, v0);
}

static void ov16_02269938(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    v0 = battleInput->unk_1A.val1.unk_00;

    ov16_02269668(battleInput, param1, param2);

    {
        BgConfig *v1;

        v1 = BattleSystem_GetBgConfig(battleInput->battleSystem);

        Bg_FillTilemapRect(v1, 4, (0x6000 / 0x20 - 1), 0, 0x10, 10, 8, 17);
        Bg_FillTilemapRect(v1, 4, (0x6000 / 0x20 - 1), 0x16, 0x10, 10, 8, 17);
        Bg_ScheduleTilemapTransfer(v1, 5);
    }

    sub_020129D0(battleInput->textObj[1].fontOAM, 0);
    sub_020129D0(battleInput->textObj[2].fontOAM, 0);
}

static void ov16_022699AC(BattleInput *battleInput, int param1, int param2)
{
    UnkStruct_ov16_02260C00 *v0;
    int i;
    MessageLoader *v2;
    MoveDisplayObject *moveDisplay;
    TextColor ppColor;

    v0 = &battleInput->unk_1A.val2;
    GF_ASSERT(v0 != NULL);

    battleInput->unk_66A = v0->unk_10;

    v2 = BattleSystem_MessageLoader(battleInput->battleSystem);
    moveDisplay = ov16_0226ABD4(battleInput, v0->unk_10);

    ov16_0226AF0C(battleInput);

    {
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], NULL, FONT_SUBSCREEN, TEXT_COLOR(7, 8, 9), 3, 20023, 64, 46, 1, &moveDisplay->moveNameText[0]);
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], NULL, FONT_SUBSCREEN, TEXT_COLOR(7, 8, 9), 3, 20023, 192, 46, 1, &moveDisplay->moveNameText[1]);
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[2], NULL, FONT_SUBSCREEN, TEXT_COLOR(7, 8, 9), 3, 20023, 64, 110, 1, &moveDisplay->moveNameText[2]);
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[3], NULL, FONT_SUBSCREEN, TEXT_COLOR(7, 8, 9), 3, 20023, 192, 110, 1, &moveDisplay->moveNameText[3]);
    }

    {
        for (i = 0; i < LEARNED_MOVES_MAX; i++) {
            ppColor = GetPPTextColor(v0->unk_08[i], v0->unk_0C[i]);
            BattleInput_CreateTextObject(battleInput, &battleInput->textObj[9 + i], NULL, FONT_SYSTEM, ppColor, 4, 20023, Unk_ov16_022702D4[i][0], Unk_ov16_022702D4[i][1], 0, &moveDisplay->curPPText[i]);
            BattleInput_CreateTextObject(battleInput, &battleInput->textObj[5 + i], NULL, FONT_SYSTEM, ppColor, 4, 20023, Unk_ov16_02270284[i][0], Unk_ov16_02270284[i][1], 0, &moveDisplay->maxPPText[i]);
        }
    }

    {
        Strbuf *v5;

        v5 = MessageLoader_GetNewStrbuf(v2, pl_msg_00000368_00929); // CANCEL
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[4], v5, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 178, 1, NULL);
        Strbuf_Free(v5);
    }

    {
        int moveType;

        for (i = 0; i < LEARNED_MOVES_MAX; i++) {
            if (v0->unk_00[i] != 0) {
                moveType = MoveTable_LoadParam(v0->unk_00[i], MOVEATTRIBUTE_TYPE);
                ov16_0226B06C(battleInput, moveType, i);
            } else {
                ov16_0226B088(battleInput, i);
                break;
            }
        }
    }

    {
        BgConfig *v7;

        v7 = BattleSystem_GetBgConfig(battleInput->battleSystem);

        if (v0->unk_00[0] == 0) {
            sub_020129D0(battleInput->textObj[0].fontOAM, 0);
            sub_020129D0(battleInput->textObj[5].fontOAM, 0);
            sub_020129D0(battleInput->textObj[9].fontOAM, 0);
        }

        if (v0->unk_00[1] == 0) {
            sub_020129D0(battleInput->textObj[1].fontOAM, 0);
            sub_020129D0(battleInput->textObj[6].fontOAM, 0);
            sub_020129D0(battleInput->textObj[10].fontOAM, 0);
        }

        if (v0->unk_00[2] == 0) {
            sub_020129D0(battleInput->textObj[2].fontOAM, 0);
            sub_020129D0(battleInput->textObj[7].fontOAM, 0);
            sub_020129D0(battleInput->textObj[11].fontOAM, 0);
        }

        if (v0->unk_00[3] == 0) {
            sub_020129D0(battleInput->textObj[3].fontOAM, 0);
            sub_020129D0(battleInput->textObj[8].fontOAM, 0);
            sub_020129D0(battleInput->textObj[12].fontOAM, 0);
        }
    }
}

static void BattleInput_CreateYesNoTextObjects(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *strYes, *strNo;

    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    strYes = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_00940); // Yes
    strNo = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_00941); // No

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], strYes, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 68, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], strNo, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 140, 1, NULL);

    Strbuf_Free(strYes);
    Strbuf_Free(strNo);
}

static void ov16_02269D14(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *v1, *v2;

    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    v1 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01181); // Forget a move!
    v2 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01182); // Keep old moves!

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v1, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 68, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], v2, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 140, 1, NULL);

    Strbuf_Free(v1);
    Strbuf_Free(v2);
}

static void ov16_02269DB0(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *v1, *v2, *v3, *v4;
    StringTemplate *v5;
    UnkStruct_ov16_022623F0 *v6;

    v6 = &battleInput->unk_1A.val4;
    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    v5 = BattleSystem_StringTemplate(battleInput->battleSystem);
    v1 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01186); // Give up on {move}?
    v2 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01187); // Don't give up on {move}!
    v3 = Strbuf_Init(100, 5);
    v4 = Strbuf_Init(100, 5);

    StringTemplate_SetMoveName(v5, 0, v6->unk_00);
    StringTemplate_Format(v5, v3, v1);
    StringTemplate_Format(v5, v4, v2);

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v3, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 68, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], v4, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 140, 1, NULL);

    Strbuf_Free(v1);
    Strbuf_Free(v2);
    Strbuf_Free(v3);
    Strbuf_Free(v4);
}

static void ov16_02269E94(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *v1;

    G2S_SetBlendAlpha((GX_BLEND_PLANEMASK_BG1), (GX_BLEND_BGALL), 31, 0);

    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    v1 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01260); // STOP

    {
        BgConfig *v2;
        NNSG2dScreenData *v3;
        void *v4;

        v4 = Graphics_GetScrnData(7, 46, 1, &v3, 5);
        MI_CpuCopy32(v3->rawData, battleInput->unk_3C[6], 0x800);
        Heap_FreeToHeap(v4);

        v2 = BattleSystem_GetBgConfig(battleInput->battleSystem);
        Bg_LoadTilemapBuffer(v2, 4, battleInput->unk_3C[6], 0x800);
        Bg_ScheduleTilemapTransfer(v2, 4);
    }

    {
        BgConfig *v5 = BattleSystem_GetBgConfig(battleInput->battleSystem);

        MI_CpuClear32(battleInput->unk_3C[4], 0x800);
        Bg_LoadTilemapBuffer(v5, 5, battleInput->unk_3C[4], 0x800);
        Bg_ScheduleTilemapTransfer(v5, 5);
    }

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v1, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 178, 1, NULL);
    Strbuf_Free(v1);
}

static void ov16_02269F68(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *v1, *v2, *v3, *v4;
    StringTemplate *v5;
    UnkStruct_ov16_022623F0 *v6;

    v6 = &battleInput->unk_1A.val4;
    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    v5 = BattleSystem_StringTemplate(battleInput->battleSystem);
    v1 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01217); // Use next Pokémon
    v2 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01218); // Flee
    v3 = Strbuf_Init(100, 5);
    v4 = Strbuf_Init(100, 5);

    StringTemplate_SetMoveName(v5, 0, v6->unk_00);
    StringTemplate_Format(v5, v3, v1);
    StringTemplate_Format(v5, v4, v2);

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v3, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 68, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], v4, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 140, 1, NULL);

    Strbuf_Free(v1);
    Strbuf_Free(v2);
    Strbuf_Free(v3);
    Strbuf_Free(v4);
}

static void ov16_0226A04C(BattleInput *battleInput, int param1, int param2)
{
    MessageLoader *msgLoader;
    Strbuf *v1, *v2, *v3, *v4;
    StringTemplate *v5;
    UnkStruct_ov16_022623F0 *v6;

    v6 = &battleInput->unk_1A.val4;
    msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    v5 = BattleSystem_StringTemplate(battleInput->battleSystem);
    v1 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01215); // Switch Pokémon
    v2 = MessageLoader_GetNewStrbuf(msgLoader, pl_msg_00000368_01216); // Keep battling
    v3 = Strbuf_Init(100, 5);
    v4 = Strbuf_Init(100, 5);

    StringTemplate_SetMoveName(v5, 0, v6->unk_00);
    StringTemplate_Format(v5, v3, v1);
    StringTemplate_Format(v5, v4, v2);

    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0], v3, FONT_SUBSCREEN, TEXT_COLOR(1, 2, 3), 2, 20023, 128, 68, 1, NULL);
    BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1], v4, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, 128, 140, 1, NULL);

    Strbuf_Free(v1);
    Strbuf_Free(v2);
    Strbuf_Free(v3);
    Strbuf_Free(v4);
}

static void ov16_0226A12C(BattleInput *battleInput, int param1, int param2)
{
    UnkStruct_ov16_02260F14 *v0;
    int i;
    MessageLoader *v2;
    u8 v3[4];
    Strbuf *v4, *genderMarker;
    Pokemon *v6;
    BoxPokemon *v7;
    StringTemplate *v8;
    TextColor v9;
    u8 v10[6];
    u8 v11[6];
    int v12;

    v0 = &battleInput->unk_1A.val3;

    battleInput->unk_66C = v0->unk_21;
    battleInput->unk_66A = v0->unk_20;

    v2 = BattleSystem_MessageLoader(battleInput->battleSystem);
    v8 = BattleSystem_StringTemplate(battleInput->battleSystem);

    ov16_0226B20C(battleInput, v3, 0);
    ov16_0226A698(battleInput);
    ov16_0226AAF8(battleInput);
    ov16_0223F87C(battleInput->battleSystem, v10);
    ov16_0223F858(battleInput->battleSystem, v11);

    v4 = Strbuf_Init((12 + 2 + (5 * 2)), 5);

    for (i = 0; i < 4; i++) {
        v12 = v11[2 + i];

        if ((v0->unk_00[v12].unk_01_2 == 1) && (v3[i] == 1)) {
            if (v0->unk_00[v12].unk_01_0 == 0) {
                genderMarker = MessageLoader_GetNewStrbuf(v2, pl_msg_00000368_00962); // ♂
            } else if (v0->unk_00[v12].unk_01_0 == 1) {
                genderMarker = MessageLoader_GetNewStrbuf(v2, pl_msg_00000368_00963); // ♀
            } else {
                genderMarker = MessageLoader_GetNewStrbuf(v2, pl_msg_00000368_00964); //(genderless)
            }

            v6 = BattleSystem_PartyPokemon(battleInput->battleSystem, v12, v0->unk_00[v12].unk_00);
            v7 = Pokemon_GetBoxPokemon(v6);

            StringTemplate_SetNickname(v8, 0, v7);
            StringTemplate_Format(v8, v4, genderMarker);

            if (i & 1) {
                v9 = TEXT_COLOR(1, 2, 3);
            } else {
                v9 = TEXT_COLOR(4, 5, 6);
            }

            BattleInput_CreateTextObject(battleInput, &battleInput->textObj[0 + i], v4, FONT_SUBSCREEN, v9, 6, 20023, Unk_ov16_02270328[i][0], Unk_ov16_02270328[i][1], 1, NULL);
            Strbuf_Free(genderMarker);

            {
                switch (i) {
                case 1:
                    ov16_0226A7A4(battleInput, v6, 3, v0->unk_00[v12].unk_04, v0->unk_00[v12].unk_06, v0->unk_00[v12].unk_02);
                    break;
                case 3:
                    ov16_0226A7A4(battleInput, v6, 5, v0->unk_00[v12].unk_04, v0->unk_00[v12].unk_06, v0->unk_00[v12].unk_02);
                    break;
                }
            }
        } else {
            if (v3[i] == 0) {
                ov16_0226B0DC(battleInput, i);
            }
        }
    }

    Strbuf_Free(v4);

    {
        Strbuf *v13;

        v13 = MessageLoader_GetNewStrbuf(v2, 930);
        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[4], v13, FONT_SUBSCREEN, TEXT_COLOR(10, 11, 12), 2, 20023, Unk_ov16_02270328[4][0], Unk_ov16_02270328[4][1], 1, NULL);
        Strbuf_Free(v13);
    }
}

static int ov16_0226A318(BattleInput *battleInput, int param1, int param2)
{
    int v0, v1, v2;

    v2 = 0xff;

    switch (param1) {
    case 0xffffffff:
    default:
        return param1;
    case 1:
        v0 = 0;
        v1 = 0;

        switch (battleInput->unk_66A) {
        case 0:
            v2 = battleInput->unk_66A;
            break;
        case 2:
        case 4:
            v2 = battleInput->unk_66A - 2;
            break;
        }
        break;
    case 2:
        v0 = 1;
        v1 = 1;
        break;
    case 3:
        v0 = 2;
        v1 = 1;
        break;
    case 4:
        v0 = 3;
        v1 = 1;
        break;
    }

    ov16_0226B318(battleInput, param2);
    ov16_0226B2BC(ov16_0226B390, battleInput);

    battleInput->unk_67C.unk_04_val3.unk_00 = Unk_ov16_022703A4[param1 - 1];
    battleInput->unk_67C.unk_04_val3.unk_04 = &Unk_ov16_022702F4[param1 - 1];
    battleInput->unk_67C.unk_04_val3.unk_0C = 1;
    battleInput->unk_67C.unk_04_val3.unk_08 = param1;
    battleInput->unk_67C.unk_04_val3.unk_0D = v0;
    battleInput->unk_67C.unk_04_val3.unk_0E = v2;
    battleInput->unk_67C.unk_04_val3.unk_0F = v1;
    battleInput->unk_67C.unk_04_val3.unk_11 = Unk_ov16_02270294[param1 - 1];
    battleInput->unk_67C.unk_04_val3.unk_10 = 1;

    return param1;
}

static int ov16_0226A3F4(BattleInput *battleInput, int param1, int param2)
{
    UnkStruct_ov16_02260C00 *v0;
    u32 v1[2];
    u32 v2;
    const UnkStruct_ov16_0226A3F4 *v3[2];
    const s16 *v4;
    const UnkStruct_ov16_022702F4 *v5;

    if (param1 == 0xffffffff) {
        return param1;
    }

    v0 = &battleInput->unk_1A.val2;

    if ((param1 >= 1) && (param1 <= 4)) {
        if (v0->unk_00[param1 - 1] == 0) {
            return 0xffffffff;
        }
    }

    v2 = param1 - 1;

    switch (param1) {
    case 0xffffffff:
    default:
        return 0xffffffff;
    case 1:
    case 2:
    case 3:
    case 4:
        v4 = Unk_ov16_022703F4[param1 - 1];
        v5 = &Unk_ov16_02270378[param1 - 1];
        break;
    case 0xff:
        v4 = Unk_ov16_022703F4[NELEMS(Unk_ov16_022703F4) - 1];
        v5 = &Unk_ov16_02270378[NELEMS(Unk_ov16_022703F4) - 1];
        break;
    }

    ov16_0226B318(battleInput, param2);
    ov16_0226B2BC(ov16_0226B4E0, battleInput);

    battleInput->unk_67C.unk_04_val3.unk_00 = v4;
    battleInput->unk_67C.unk_04_val3.unk_04 = v5;
    battleInput->unk_67C.unk_04_val3.unk_0C = 3;
    battleInput->unk_67C.unk_04_val3.unk_08 = param1;
    battleInput->unk_67C.unk_04_val3.unk_10 = 1;

    return param1;
}

static int ov16_0226A4A4(BattleInput *battleInput, int param1, int param2)
{
    int v0;

    switch (param1) {
    case 0xffffffff:
    default:
        return param1;
    case 1:
        v0 = 0;
        break;
    case 0xff:
        v0 = 1;
        break;
    }

    ov16_0226B318(battleInput, param2);
    ov16_0226B2BC(ov16_0226B390, battleInput);

    if (param1 == 1) {
        battleInput->unk_67C.unk_04_val3.unk_00 = Unk_ov16_02270240[1];
        battleInput->unk_67C.unk_04_val3.unk_04 = &Unk_ov16_0227021C[1];
    } else {
        battleInput->unk_67C.unk_04_val3.unk_00 = Unk_ov16_02270240[0];
        battleInput->unk_67C.unk_04_val3.unk_04 = &Unk_ov16_0227021C[0];
    }

    battleInput->unk_67C.unk_04_val3.unk_0C = 6;
    battleInput->unk_67C.unk_04_val3.unk_08 = param1;
    battleInput->unk_67C.unk_04_val3.unk_0D = v0;
    battleInput->unk_67C.unk_04_val3.unk_0F = 3;
    battleInput->unk_67C.unk_04_val3.unk_10 = 1;

    return param1;
}

static int ov16_0226A528(BattleInput *battleInput, int param1, int param2)
{
    UnkStruct_ov16_02260F14 *v0;
    u8 v1[4];

    v0 = &battleInput->unk_1A.val3;

    ov16_0226B20C(battleInput, v1, 1);

    switch (param1) {
    case 0xffffffff:
    default:
        return param1;
    case 1:
        if (v1[2 - 2] == 0) {
            return 0xffffffff;
        }
        break;
    case 2:
        if (v1[3 - 2] == 0) {
            return 0xffffffff;
        }
        break;
    case 3:
        if (v1[4 - 2] == 0) {
            return 0xffffffff;
        }
        break;
    case 4:
        if (v1[5 - 2] == 0) {
            return 0xffffffff;
        }
        break;
    case 0xff:
        ov16_0226B318(battleInput, NELEMS(Unk_ov16_02270A0C) - 1);
        ov16_0226B2BC(ov16_0226B390, battleInput);

        battleInput->unk_67C.unk_04_val3.unk_00 = Unk_ov16_022703D4[NELEMS(Unk_ov16_022703D4) - 1];
        battleInput->unk_67C.unk_04_val3.unk_04 = &Unk_ov16_0227033C[NELEMS(Unk_ov16_0227033C) - 1];
        battleInput->unk_67C.unk_04_val3.unk_0C = 4;
        battleInput->unk_67C.unk_04_val3.unk_08 = param1;
        battleInput->unk_67C.unk_04_val3.unk_0D = 4;
        battleInput->unk_67C.unk_04_val3.unk_0F = 3;
        battleInput->unk_67C.unk_04_val3.unk_10 = 1;

        return param1;
    }

    {
        BgConfig *v2;

        v2 = BattleSystem_GetBgConfig(battleInput->battleSystem);
        Bg_FillTilemap(v2, 5, (0x6000 / 0x20 - 1));
        Bg_ScheduleTilemapTransfer(v2, 5);
    }

    ov16_0226B314(battleInput, param1);
    ov16_0226B2BC(ov16_0226B780, battleInput);

    battleInput->unk_67C.unk_04_val4.unk_1C = param1;

    return param1;
}

static int ov16_0226A634(BattleInput *battleInput, int param1, int param2)
{
    switch (param1) {
    case 0xffffffff:
    default:
        return param1;
    case 1:
        break;
    }

    ov16_0226B318(battleInput, param2);
    ov16_0226B2BC(ov16_0226B390, battleInput);

    battleInput->unk_67C.unk_04_val3.unk_00 = Unk_ov16_022701F4;
    battleInput->unk_67C.unk_04_val3.unk_04 = &Unk_ov16_022701D0[0];
    battleInput->unk_67C.unk_04_val3.unk_0C = 6;
    battleInput->unk_67C.unk_04_val3.unk_08 = param1;
    battleInput->unk_67C.unk_04_val3.unk_0D = 0;
    battleInput->unk_67C.unk_04_val3.unk_0F = 3;
    battleInput->unk_67C.unk_04_val3.unk_10 = 0;

    return param1;
}

static void ov16_0226A698(BattleInput *battleInput)
{
    SpriteRenderer *v0;
    SpriteGfxHandler *v1;
    int v2, v3, v4;
    PaletteData *v5;

    v0 = ov16_0223E010(battleInput->battleSystem);
    v1 = ov16_0223E018(battleInput->battleSystem);
    v5 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    sub_0200CD7C(v5, 3, v0, v1, 19, PokeIconPalettesFileIndex(), 0, 3, NNS_G2D_VRAM_TYPE_2DSUB, 20022);
    sub_0200CE0C(v0, v1, 19, PokeIcon32KCellsFileIndex(), 0, 20021);
    sub_0200CE3C(v0, v1, 19, PokeIcon32KAnimationFileIndex(), 0, 20021);
}

static void ov16_0226A718(BattleInput *battleInput)
{
    SpriteGfxHandler *v0;

    v0 = ov16_0223E018(battleInput->battleSystem);

    SpriteGfxHandler_UnloadCharObjById(v0, 20036);
    SpriteGfxHandler_UnloadCharObjById(v0, 20037);
    SpriteGfxHandler_UnloadCharObjById(v0, 20038);
    SpriteGfxHandler_UnloadCellObjById(v0, 20021);
    SpriteGfxHandler_UnloadAnimObjById(v0, 20021);
    SpriteGfxHandler_UnloadPlttObjById(v0, 20022);
}

static void ov16_0226A768(BattleInput *battleInput)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (battleInput->unk_60C[i] != NULL) {
            sub_0200D0F4(battleInput->unk_60C[i]);
            battleInput->unk_60C[i] = NULL;
        }

        if (battleInput->unk_61C[i] != NULL) {
            SysTask_Done(battleInput->unk_61C[i]);
            battleInput->unk_61C[i] = NULL;
        }
    }
}

static CellActorData *ov16_0226A7A4(BattleInput *battleInput, Pokemon *param1, int param2, int param3, int param4, int param5)
{
    SpriteRenderer *v0;
    SpriteGfxHandler *v1;
    u32 v2;
    SpriteTemplate v3;
    CellActorData *v4;
    int v5;

    if (param2 >= 2) {
        v5 = param2 - 2;
    } else {
        v5 = param2;
    }

    GF_ASSERT(battleInput->unk_60C[v5] == NULL);
    GF_ASSERT(battleInput->unk_61C[v5] == NULL);

    switch (param2) {
    case 0:
    case 2:
    case 4:
        v2 = 20036;
        break;
    case 3:
        v2 = 20037;
        break;
    case 5:
        v2 = 20038;
        break;
    default:
        GF_ASSERT(0);
        return NULL;
    }

    v0 = ov16_0223E010(battleInput->battleSystem);
    v1 = ov16_0223E018(battleInput->battleSystem);

    sub_0200CBDC(v0, v1, 19, Pokemon_IconSpriteIndex(param1), 0, NNS_G2D_VRAM_TYPE_2DSUB, v2);

    v3 = Unk_ov16_022704B0;
    v3.resources[0] = v2;
    v3.x = Unk_ov16_02270304[v5][0];
    v3.y = Unk_ov16_02270304[v5][1];
    v4 = SpriteActor_LoadResources(v0, v1, &v3);

    sub_0200D500(v4, v3.x, v3.y, ((192 + 80) << FX32_SHIFT));
    CellActor_SetExplicitPaletteOffsetAutoAdjust(v4->unk_00, Pokemon_IconPaletteIndex(param1));

    {
        int v6 = 0;

        if ((param3 == 0) || (param5 == 2)) {
            v6 = 0;
        } else if (param5 == 3) {
            v6 = 5;
        } else {
            switch (HealthBar_Color(param3, param4, (8 * 6))) {
            case 4:
                v6 = 1;
                break;
            case 3:
                v6 = 2;
                break;
            case 2:
                v6 = 3;
                break;
            case 1:
                v6 = 4;
                break;
            }

            sub_0200D364(v4, v6);
        }
    }

    sub_0200D330(v4);

    battleInput->unk_60C[v5] = v4;
    battleInput->unk_61C[v5] = SysTask_Start(ov16_0226A928, v4, 1300);

    return v4;
}

static void ov16_0226A928(SysTask *param0, void *param1)
{
    CellActorData *v0 = param1;
    sub_0200D330(v0);
}

static int ov16_0226A934(u8 param0)
{
    int v0;

    switch (param0) {
    case 0:
    default:
        v0 = 0;
        break;
    case 1:
        v0 = 1;
        break;
    case 2:
        v0 = 3;
        break;
    case 3:
        v0 = 2;
        break;
    }

    return v0;
}

static void ov16_0226A95C(const Strbuf *param0, int param1, int *param2, int *param3)
{
    int v0, v1;

    v0 = Font_CalcStrbufWidth(param1, param0, 0);
    v1 = v0 / 8;

    if (FX_ModS32(v0, 8) != 0) {
        v1++;
    }

    *param2 = v0;
    *param3 = v1;
}

static void BattleInput_CreateTextObject(BattleInput *battleInput, BattleInputTextObject *textObj, const Strbuf *param2, enum Font param3, TextColor param4, int param5, int param6, int param7, int param8, int param9, BattleInputTextImage *param10)
{
    UnkStruct_020127E8 v0;
    Window v1;
    SpriteManagerAllocation spriteManAlloc;
    int v3;
    FontOAM *fontOAM;
    BgConfig *v5;
    SpriteGfxHandler *v6;
    int v7, v8;

    GF_ASSERT(textObj->fontOAM == NULL);

    v6 = ov16_0223E018(battleInput->battleSystem);
    v5 = BattleSystem_GetBgConfig(battleInput->battleSystem);

    if (param10 == NULL) {
        ov16_0226A95C(param2, param3, &v7, &v8);
    } else {
        v7 = param10->unk_12;
        v8 = param10->unk_10;
    }

    if (param10 == NULL) {
        Window_Init(&v1);
        Window_AddToTopLeftCorner(v5, &v1, v8, 16 / 8, 0, 0);
        Text_AddPrinterWithParamsColorAndSpacing(&v1, param3, param2, 0, 0, TEXT_SPEED_NO_TRANSFER, param4, 0, 0, NULL);
    } else {
        v1 = param10->unk_00;
    }

    v3 = sub_02012898(&v1, NNS_G2D_VRAM_TYPE_2DSUB, 5);
    sub_0201ED94(v3, 1, NNS_G2D_VRAM_TYPE_2DSUB, &spriteManAlloc);

    if (param9 == 1) {
        param7 -= v7 / 2;
    }

    param8 += (((192 + 80) << FX32_SHIFT) >> FX32_SHIFT) - 8;

    v0.unk_00 = battleInput->unk_4C8;
    v0.unk_04 = &v1;
    v0.unk_08 = sub_0200D9B0(v6);
    v0.unk_0C = sub_0200D04C(v6, param6);
    v0.unk_10 = NULL;
    v0.unk_14 = spriteManAlloc.unk_04;
    v0.unk_18 = param7;
    v0.unk_1C = param8;
    v0.unk_20 = 0;
    v0.unk_24 = 100;
    v0.unk_28 = NNS_G2D_VRAM_TYPE_2DSUB;
    v0.unk_2C = 5;

    fontOAM = sub_020127E8(&v0);

    sub_02012AC0(fontOAM, param5);
    sub_020128C4(fontOAM, param7, param8);

    if (param10 == NULL) {
        Window_Remove(&v1);
    }

    textObj->fontOAM = fontOAM;
    textObj->spriteManAlloc = spriteManAlloc;
    textObj->unk_10 = v7;
}

static void ov16_0226AAC0(BattleInput *battleInput)
{
    int i;

    for (i = 0; i < 13; i++) {
        if (battleInput->textObj[i].fontOAM != NULL) {
            sub_02012870(battleInput->textObj[i].fontOAM);
            sub_0201EE28(&battleInput->textObj[i].spriteManAlloc);
            battleInput->textObj[i].fontOAM = NULL;
        }
    }
}

static void ov16_0226AAF8(BattleInput *battleInput)
{
    u8 v0[4], v1[4];
    int j, i;
    u16 *v4, *v5;
    BgConfig *v6;

    v6 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v4 = Bg_GetTilemapBuffer(v6, 5);

    ov16_0226B20C(battleInput, v0, 0);

    if (v0[0] == 1) {
        ov16_0226B264(battleInput, 1, v1, 0);

        if (v1[3 - 1] == 1) {
            for (i = 12; i <= 16; i++) {
                v5 = &v4[i * 32];

                for (j = 0xf; j <= 0x10; j++) {
                    v5[j] = 0x2a4;
                }
            }
        }

        if (v1[4 - 1] == 1) {
            for (i = 10; i <= 10; i++) {
                v5 = &v4[i * 32];

                for (j = 2; j <= 12; j++) {
                    v5[j] = 0x2a4;
                }
            }
        }
    }

    if (v0[1] == 1) {
        ov16_0226B264(battleInput, 2, v1, 0);

        if (v1[3 - 1] == 1) {
            for (i = 10; i <= 10; i++) {
                v5 = &v4[i * 32];

                for (j = 0x13; j <= 0x1d; j++) {
                    v5[j] = 0x2a4;
                }
            }
        }

        if (v1[4 - 1] == 1) {
            for (i = 3; i <= 7; i++) {
                v5 = &v4[i * 32];

                for (j = 0xf; j <= 0x10; j++) {
                    v5[j] = 0x2a4;
                }
            }
        }
    }
}

static MoveDisplayObject *ov16_0226ABD4(BattleInput *battleInput, int param1)
{
    if (param1 >= 2) {
        param1 -= 2;
    }

    return &battleInput->unk_68[param1];
}

static void ov16_0226ABE8(BattleInput *battleInput)
{
    int j, i;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            Heap_FreeToHeap(battleInput->unk_68[i].typeIcon[j]);

            if (battleInput->unk_68[i].moveNameText[j].unk_00.pixels != NULL) {
                Window_Remove(&battleInput->unk_68[i].moveNameText[j].unk_00);
            }

            if (battleInput->unk_68[i].curPPText[j].unk_00.pixels != NULL) {
                Window_Remove(&battleInput->unk_68[i].curPPText[j].unk_00);
            }

            if (battleInput->unk_68[i].maxPPText[j].unk_00.pixels != NULL) {
                Window_Remove(&battleInput->unk_68[i].maxPPText[j].unk_00);
            }
        }
    }
}

void ov16_0226AC98(BattleInput *battleInput, int param1, const MoveDisplayInfo *moveDisplay)
{
    MoveDisplayObject *moveDisplayObj;
    void *v1;
    NNSG2dCharacterData *v2;
    int i, v3, moveType;
    Strbuf *moveName;
    Strbuf *v7;
    Strbuf *v8;
    Strbuf *v9;
    StringTemplate *v10;
    TextColor ppColor;
    MessageLoader *v12;

    v12 = BattleSystem_MessageLoader(battleInput->battleSystem);
    moveDisplayObj = ov16_0226ABD4(battleInput, param1);
    v3 = sub_0208C098(6);
    v9 = MessageLoader_GetNewStrbuf(v12, pl_msg_00000368_00938); // PP
    v10 = BattleSystem_StringTemplate(battleInput->battleSystem);
    v7 = Strbuf_Init(((2 + 2 + 1 + 2) * 2 + 2), 5);
    v8 = MessageLoader_GetNewStrbuf(v12, pl_msg_00000368_00937); // '/'

    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        if ((moveDisplay->move[i] != moveDisplayObj->moveDisplay.move[i]) && (moveDisplay->move[i] != 0)) {
            moveType = MoveTable_LoadParam(moveDisplay->move[i], MOVEATTRIBUTE_TYPE);
            v1 = Graphics_GetCharData(sub_0207C944(), sub_0207C908(moveType), 1, &v2, HEAP_ID_BATTLE);
            MI_CpuCopy32(v2->pRawData, moveDisplayObj->typeIcon[i], v3);
            Heap_FreeToHeap(v1);
        }

        if ((moveDisplayObj->moveNameText[i].unk_00.pixels == NULL) || ((moveDisplay->move[i] != moveDisplayObj->moveDisplay.move[i]) && (moveDisplay->move[i] != 0))) {
            moveName = MessageUtil_MoveName(moveDisplay->move[i], 5);
            ov16_0226AEA0(battleInput, moveName, FONT_SUBSCREEN, &moveDisplayObj->moveNameText[i], TEXT_COLOR(7, 8, 9));
            Strbuf_Free(moveName);
        }

        if ((moveDisplayObj->curPPText[i].unk_00.pixels == NULL) || (moveDisplayObj->maxPPText[i].unk_00.pixels == NULL) || (moveDisplay->move[i] != 0) || (moveDisplay->move[i] != moveDisplayObj->moveDisplay.move[i]) || (moveDisplay->curPP[i] != moveDisplayObj->moveDisplay.curPP[i]) || (moveDisplay->maxPP[i] != moveDisplayObj->moveDisplay.maxPP[i])) {
            StringTemplate_SetNumber(v10, 0, moveDisplay->curPP[i], 2, 1, 0);
            StringTemplate_SetNumber(v10, 1, moveDisplay->maxPP[i], 2, 1, 0);
            StringTemplate_Format(v10, v7, v8);

            ppColor = GetPPTextColor(moveDisplay->curPP[i], moveDisplay->maxPP[i]);

            if ((moveDisplayObj->curPPText[i].unk_00.pixels == NULL) || (moveDisplay->move[i] != moveDisplayObj->moveDisplay.move[i]) || (moveDisplay->curPP[i] != moveDisplayObj->moveDisplay.curPP[i])) {
                ov16_0226AEA0(battleInput, v7, FONT_SYSTEM, &moveDisplayObj->curPPText[i], ppColor);
            }

            if ((moveDisplayObj->maxPPText[i].unk_00.pixels == NULL) || (moveDisplay->move[i] != moveDisplayObj->moveDisplay.move[i]) || (moveDisplay->curPP[i] != moveDisplayObj->moveDisplay.curPP[i])) {
                ov16_0226AEA0(battleInput, v9, FONT_SYSTEM, &moveDisplayObj->maxPPText[i], ppColor);
            }
        }
    }

    Strbuf_Free(v9);
    Strbuf_Free(v8);
    Strbuf_Free(v7);

    moveDisplayObj->moveDisplay = *moveDisplay;
}

static void ov16_0226AEA0(BattleInput *battleInput, const Strbuf *param1, enum Font param2, BattleInputTextImage *param3, TextColor param4)
{
    int v0, v1;

    ov16_0226A95C(param1, param2, &v0, &v1);

    param3->unk_12 = v0;
    param3->unk_10 = v1;

    if (param3->unk_00.pixels != NULL) {
        Window_Remove(&param3->unk_00);
    }

    Window_Init(&param3->unk_00);
    Window_AddToTopLeftCorner(BattleSystem_GetBgConfig(battleInput->battleSystem), &param3->unk_00, v1, 16 / 8, 0, 0);
    Text_AddPrinterWithParamsColorAndSpacing(&param3->unk_00, param2, param1, 0, 0, TEXT_SPEED_NO_TRANSFER, param4, 0, 0, NULL);
}

static void ov16_0226AF0C(BattleInput *battleInput)
{
    int i;
    SpriteRenderer *v1;
    SpriteGfxHandler *v2;
    SpriteTemplate v3;
    UnkStruct_ov16_02260C00 *v4;
    int v5;
    int v6;
    MoveDisplayObject *moveDisplayObj;

    v4 = &battleInput->unk_1A.val2;
    v1 = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);
    moveDisplayObj = ov16_0226ABD4(battleInput, battleInput->unk_66A);
    v3 = Unk_ov16_0227047C;

    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        GF_ASSERT(battleInput->unk_5EC[i] == NULL);

        if (v4->unk_00[i] != 0) {
            v5 = MoveTable_LoadParam(v4->unk_00[i], MOVEATTRIBUTE_TYPE);
            v3.resources[0] = 20025 + i;
            v3.x = Unk_ov16_022702B4[i][0];
            v3.y = Unk_ov16_022702B4[i][1];

            battleInput->unk_5EC[i] = sub_0207CA58(v1, v2, v5, &v3);

            sub_0200D500(battleInput->unk_5EC[i], v3.x, v3.y, ((192 + 80) << FX32_SHIFT));

            {
                void *v8;
                NNSG2dImageProxy *v9;

                v8 = G2S_GetOBJCharPtr();
                v9 = SpriteActor_ImageProxy(battleInput->unk_5EC[i]->unk_00);

                MI_CpuCopy16(moveDisplayObj->typeIcon[i], (void *)((u32)v8 + v9->vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DSUB]), sub_0208C098(6));
            }
        }
    }
}

static void ov16_0226AFF4(BattleInput *battleInput)
{
    int i;
    SpriteRenderer *v1;
    SpriteGfxHandler *v2;

    v1 = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);

    for (i = 0; i < 4; i++) {
        if (battleInput->unk_5EC[i] != NULL) {
            sub_0207CA88(battleInput->unk_5EC[i]);
            battleInput->unk_5EC[i] = NULL;
        }
    }
}

static void ov16_0226B028(BattleInput *battleInput)
{
    int i;
    SpriteRenderer *v1;
    SpriteGfxHandler *v2;

    v1 = ov16_0223E010(battleInput->battleSystem);
    v2 = ov16_0223E018(battleInput->battleSystem);

    for (i = 0; i < 4; i++) {
        if (battleInput->unk_5FC[i] != NULL) {
            sub_0207CB00(battleInput->unk_5FC[i]);
            sub_0207CAF8(v2, 20029 + i);
            battleInput->unk_5FC[i] = NULL;
        }
    }
}

static void ov16_0226B06C(BattleInput *battleInput, int param1, int param2)
{
    ov11_0221F81C(BattleSystem_GetPaletteData(battleInput->battleSystem), param1, 5, 1, 8 + param2);
}

static void ov16_0226B088(BattleInput *battleInput, int param1)
{
    PaletteData *v0;
    int i;

    v0 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    for (i = param1; i < 4; i++) {
        ov16_0226B31C(battleInput, &Unk_ov16_0227022C[i], &Unk_ov16_02270274[i], 3, 0);
        PaletteData_LoadBuffer(v0, &battleInput->unk_58[0xe * 16], 1, (8 + i) * 16, 0x20);
    }
}

static void ov16_0226B0DC(BattleInput *battleInput, int param1)
{
    PaletteData *v0;
    int v1;
    const u8 v2[] = { 6, 0xc, 0xd, 5 };
    BgConfig *v3;

    v3 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v0 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    ov16_0226B31C(battleInput, &Unk_ov16_022701FC[param1], &Unk_ov16_022702C4[param1], 4, 0);

    PaletteData_LoadBuffer(v0, &battleInput->unk_58[0xe * 16], 1, v2[param1] * 16, 0x20);
    Bg_ScheduleTilemapTransfer(v3, 4);
    Bg_FillTilemapRect(v3, 5, (0x6000 / 0x20 - 1), Unk_ov16_022702C4[param1].unk_02, Unk_ov16_022702C4[param1].unk_00, Unk_ov16_022702C4[param1].unk_03 - Unk_ov16_022702C4[param1].unk_02 + 1, Unk_ov16_022702C4[param1].unk_01 - Unk_ov16_022702C4[param1].unk_00 + 1, 17);
    Bg_ScheduleTilemapTransfer(v3, 5);
}

static void ov16_0226B198(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (4 + i != 6) {
            Bg_ToggleLayer(4 + i, 0);
        } else {
            Bg_ToggleLayer(4 + i, 1);
        }
    }
}

static void ov16_0226B1C4(BattleInput *battleInput, int param1, int param2)
{
    if (param1 == 1) {
        ov16_0226B1E8(battleInput);
    }

    if (param2 == 1) {
        SysTask_ExecuteAfterVBlank(ov16_0226BCBC, battleInput, 10);
    }
}

static void ov16_0226B1E8(BattleInput *battleInput)
{
    ov16_0226AFF4(battleInput);
    ov16_0226B028(battleInput);
    ov16_0226AAC0(battleInput);
    ov16_0226A718(battleInput);
    ov16_0226A768(battleInput);
}

static void ov16_0226B20C(BattleInput *battleInput, u8 *param1, int param2)
{
    UnkStruct_ov16_02260F14 *v0;
    int i;
    u8 v2[6];
    int v3;

    v0 = &battleInput->unk_1A.val3;
    ov16_0223F858(battleInput->battleSystem, v2);

    for (i = 0; i < 4; i++) {
        v3 = v2[2 + i];

        if ((param2 == 1) && (v0->unk_00[v3].unk_01_2 == 0)) {
            param1[i] = 0;
        } else {
            param1[i] = Unk_ov16_022705B0[battleInput->unk_66C][i];
        }
    }
}

static void ov16_0226B264(BattleInput *battleInput, int param1, u8 *param2, int param3)
{
    UnkStruct_ov16_02260F14 *v0;
    int i;

    v0 = &battleInput->unk_1A.val3;

    switch (battleInput->unk_66C) {
    case 0:
    case 8:
    case 9:
    case 10:
    case 11:
        for (i = 0; i < 4; i++) {
            if (i == param1 - 1) {
                param2[i] = 1;
            } else {
                param2[i] = 0;
            }
        }
        break;
    default:
        ov16_0226B20C(battleInput, param2, param3);
        break;
    }
}

static void ov16_0226B2BC(SysTaskFunc param0, BattleInput *battleInput)
{
    GF_ASSERT(battleInput->unk_0C == NULL);

    MI_CpuClear8(&battleInput->unk_67C, sizeof(UnkStruct_ov16_02268A14_sub3));
    battleInput->unk_0C = SysTask_Start(param0, battleInput, 1300);
}

static void ov16_0226B2F0(BattleInput *battleInput)
{
    if (battleInput->unk_0C != NULL) {
        SysTask_Done(battleInput->unk_0C);
        battleInput->unk_0C = NULL;
        MI_CpuClear8(&battleInput->unk_67C, sizeof(UnkStruct_ov16_02268A14_sub3));
    }
}

static void inline_ov16_0226B314(SysTaskFunc param0, BattleInput *battleInput)
{
    GF_ASSERT(battleInput->unk_10 == NULL);

    MI_CpuClear8(&battleInput->unk_6A0, sizeof(UnkStruct_ov16_02268A14_sub4));
    battleInput->unk_10 = SysTask_Start(param0, battleInput, 1320);
}

static void inline_ov16_0226B318_1_sub(BattleInput *battleInput)
{
    if (battleInput->unk_10 != NULL) {
        SysTask_Done(battleInput->unk_10);
        battleInput->unk_10 = NULL;
        MI_CpuClear8(&battleInput->unk_6A0, sizeof(UnkStruct_ov16_02268A14_sub4));
    }
}

static void ov16_0226B314(BattleInput *battleInput, int param1)
{
    return;

    inline_ov16_0226B314(inline_ov16_0226B314_1, battleInput);
    battleInput->unk_6A0.unk_00 = param1;
}

static void ov16_0226B318(BattleInput *battleInput, int param1)
{
    return;

    if (param1 == 0xff) {
        return;
    }

    inline_ov16_0226B314(inline_ov16_0226B318_1, battleInput);
    battleInput->unk_6A0.unk_09 = param1;
}

static void inline_ov16_0226B318_1(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    UnkStruct_ov16_02268A14_sub4 *v1;
    BgConfig *v2;
    PaletteData *v3;
    int v4, v5;

    v1 = &battleInput->unk_6A0;
    v3 = BattleSystem_GetPaletteData(battleInput->battleSystem);
    v5 = 0;

    switch (v1->unk_08) {
    case 0:
        v1->unk_04 = (10 << 8);
        v1->unk_06 = -((10 << 8) / 2);
        v1->unk_04 -= v1->unk_06;
        v1->unk_08++;
    case 1:
        v1->unk_04 += v1->unk_06;

        if ((v1->unk_06 >= 0) && (v1->unk_04 >= (16 << 8))) {
            v1->unk_04 = 16 << 8;
            v5 = 1;
        } else if ((v1->unk_06 < 0) && (v1->unk_04 <= 0)) {
            v1->unk_04 = 0;
            v5 = 1;
        }

        PaletteData_Blend(v3, 1, v1->unk_09 * 16, 16, (v1->unk_04 >> 8) / 2, 0x7fff);
        PaletteData_Blend(v3, 1, v1->unk_09 * 16 + 1, 1, v1->unk_04 >> 8, 0x7b1a);
        PaletteData_Blend(v3, 1, v1->unk_09 * 16 + 0xa, 1, v1->unk_04 >> 8, 0x4634);

        if (v5 == 1) {
            inline_ov16_0226B318_1_sub(battleInput);
            return;
        }

        break;
    }
}

static void inline_ov16_0226B314_1(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    UnkStruct_ov16_02268A14_sub4 *v1;
    BgConfig *v2;
    PaletteData *v3;
    int i, v5;
    u8 v6[4];

    v1 = &battleInput->unk_6A0;
    v3 = BattleSystem_GetPaletteData(battleInput->battleSystem);
    v5 = 0;

    switch (v1->unk_08) {
    case 0:
        v1->unk_04 = (10 << 8);
        v1->unk_06 = -((10 << 8) / 2);
        v1->unk_04 -= v1->unk_06;
        v1->unk_08++;
    case 1:
        v1->unk_04 += v1->unk_06;

        if ((v1->unk_06 >= 0) && (v1->unk_04 >= (16 << 8))) {
            v1->unk_04 = 16 << 8;
            v5 = 1;
        } else if ((v1->unk_06 < 0) && (v1->unk_04 <= 0)) {
            v1->unk_04 = 0;
            v5 = 1;
        }

        ov16_0226B264(battleInput, v1->unk_00, v6, 1);

        for (i = 0; i < 4; i++) {
            if (v6[i] == 1) {
                PaletteData_Blend(v3, 1, Unk_ov16_02270A0C[i] * 16, 16, (v1->unk_04 >> 8) / 2, 0x7fff);
                PaletteData_Blend(v3, 1, Unk_ov16_02270A0C[i] * 16 + 1, 1, v1->unk_04 >> 8, 0x7b1a);
                PaletteData_Blend(v3, 1, Unk_ov16_02270A0C[i] * 16 + 0xa, 1, v1->unk_04 >> 8, 0x4634);
            }
        }

        if (v5 == 1) {
            inline_ov16_0226B318_1_sub(battleInput);
            return;
        }
        break;
    }
}

static void ov16_0226B31C(BattleInput *battleInput, const s16 *param1, const UnkStruct_ov16_022702F4 *param2, int param3, int param4)
{
    int j, i;
    BgConfig *v2;
    u16 *v3, *v4;
    u16 *v5, *v6;
    int v7;

    v2 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v3 = Bg_GetTilemapBuffer(v2, 4);
    v5 = battleInput->unk_3C[param3];
    v7 = param1[param4];

    for (i = param2->unk_00; i <= param2->unk_01; i++) {
        v4 = &v3[i * 32];
        v6 = &v5[i * 32];

        for (j = param2->unk_02; j <= param2->unk_03; j++) {
            v4[j] = v6[j] + v7;
        }
    }

    Bg_ScheduleTilemapTransfer(v2, 4);
}

static void ov16_0226B390(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    BgConfig *v1;
    int v2, v3;

    v1 = BattleSystem_GetBgConfig(battleInput->battleSystem);

    switch (battleInput->unk_67C.unk_00) {
    case 0:
        ov16_0226B31C(battleInput, battleInput->unk_67C.unk_04_val3.unk_00, battleInput->unk_67C.unk_04_val3.unk_04, battleInput->unk_67C.unk_04_val3.unk_0C, 2);
        sub_020129A4(battleInput->textObj[battleInput->unk_67C.unk_04_val3.unk_0D].fontOAM, &v2, &v3);
        sub_020128C4(battleInput->textObj[battleInput->unk_67C.unk_04_val3.unk_0D].fontOAM, v2, v3 + -2);

        if ((battleInput->unk_67C.unk_04_val3.unk_0E != 0xff) && (battleInput->unk_60C[battleInput->unk_67C.unk_04_val3.unk_0E] != NULL)) {
            sub_0200D5DC(battleInput->unk_60C[battleInput->unk_67C.unk_04_val3.unk_0E], 0, -2);
        }

        battleInput->unk_67C.unk_00++;
        break;
    case 1:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 <= 0) {
            break;
        }

        battleInput->unk_67C.unk_02 = 0;
        battleInput->unk_67C.unk_00++;
    case 2:
        ov16_0226B31C(battleInput, battleInput->unk_67C.unk_04_val3.unk_00, battleInput->unk_67C.unk_04_val3.unk_04, battleInput->unk_67C.unk_04_val3.unk_0C, 1);
        sub_020129A4(battleInput->textObj[battleInput->unk_67C.unk_04_val3.unk_0D].fontOAM, &v2, &v3);
        sub_020128C4(battleInput->textObj[battleInput->unk_67C.unk_04_val3.unk_0D].fontOAM, v2, v3 + 1);

        if ((battleInput->unk_67C.unk_04_val3.unk_0E != 0xff) && (battleInput->unk_60C[battleInput->unk_67C.unk_04_val3.unk_0E] != NULL)) {
            sub_0200D5DC(battleInput->unk_60C[battleInput->unk_67C.unk_04_val3.unk_0E], 0, 1);
        }

        battleInput->unk_67C.unk_00++;
        break;
    default:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 > 0) {
            ov16_0226B1C4(battleInput, battleInput->unk_67C.unk_04_val3.unk_10, 0);
            ov16_0226B2F0(battleInput);
            return;
        }
        break;
    }
}

static void ov16_0226B4E0(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    BgConfig *v1;
    int v2, v3;
    int v4, v5, v6;
    int v7, v8, v9;
    UnkStruct_ov16_02260C00 *v10;

    v1 = BattleSystem_GetBgConfig(battleInput->battleSystem);
    v10 = &battleInput->unk_1A.val2;

    switch (battleInput->unk_67C.unk_04_val3.unk_08) {
    case 1:
        v4 = 0;
        v5 = 9;
        v6 = 5;
        v7 = 0;
        v8 = 0;
        v9 = v10->unk_00[0];
        break;
    case 2:
        v4 = 1;
        v5 = 10;
        v6 = 6;
        v7 = 1;
        v8 = 1;
        v9 = v10->unk_00[1];
        break;
    case 3:
        v4 = 2;
        v5 = 11;
        v6 = 7;
        v7 = 2;
        v8 = 2;
        v9 = v10->unk_00[2];
        break;
    case 4:
        v4 = 3;
        v5 = 12;
        v6 = 8;
        v7 = 3;
        v8 = 3;
        v9 = v10->unk_00[3];
        break;
    case 0xff:
    default:
        v4 = 0;
        v5 = 0;
        v6 = 0;
        v7 = 0;
        v8 = 0;
        v9 = 0;
        break;
    }

    switch (battleInput->unk_67C.unk_00) {
    case 0:
        ov16_0226B31C(battleInput, battleInput->unk_67C.unk_04_val3.unk_00, battleInput->unk_67C.unk_04_val3.unk_04, battleInput->unk_67C.unk_04_val3.unk_0C, 2);

        if (battleInput->unk_67C.unk_04_val3.unk_08 != 0xff) {
            sub_020129A4(battleInput->textObj[v4].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v4].fontOAM, v2, v3 + -2);
            sub_020129A4(battleInput->textObj[v5].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v5].fontOAM, v2, v3 + -2);
            sub_020129A4(battleInput->textObj[v6].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v6].fontOAM, v2, v3 + -2);

            if (v9 != 0) {
                sub_0200D5AC(battleInput->unk_5EC[v7]->unk_00, 0, -2);

                if (battleInput->unk_5FC[v7] != NULL) {
                    sub_0200D5AC(battleInput->unk_5FC[v7]->unk_00, 0, -2);
                }
            }
        } else {
            sub_020129A4(battleInput->textObj[4].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[4].fontOAM, v2, v3 + -2);
        }

        battleInput->unk_67C.unk_00++;
        break;
    case 1:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 <= 0) {
            break;
        }

        battleInput->unk_67C.unk_02 = 0;
        battleInput->unk_67C.unk_00++;
    case 2:
        ov16_0226B31C(battleInput, battleInput->unk_67C.unk_04_val3.unk_00, battleInput->unk_67C.unk_04_val3.unk_04, battleInput->unk_67C.unk_04_val3.unk_0C, 1);

        if (battleInput->unk_67C.unk_04_val3.unk_08 != 0xff) {
            sub_020129A4(battleInput->textObj[v4].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v4].fontOAM, v2, v3 + 1);
            sub_020129A4(battleInput->textObj[v5].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v5].fontOAM, v2, v3 + 1);
            sub_020129A4(battleInput->textObj[v6].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[v6].fontOAM, v2, v3 + 1);

            if (v9 != 0) {
                sub_0200D5AC(battleInput->unk_5EC[v7]->unk_00, 0, 1);

                if (battleInput->unk_5FC[v7] != NULL) {
                    sub_0200D5AC(battleInput->unk_5FC[v7]->unk_00, 0, 1);
                }
            }
        } else {
            sub_020129A4(battleInput->textObj[4].fontOAM, &v2, &v3);
            sub_020128C4(battleInput->textObj[4].fontOAM, v2, v3 + 1);
        }

        battleInput->unk_67C.unk_00++;
        break;
    default:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 > 0) {
            ov16_0226B1C4(battleInput, 1, 1);
            ov16_0226B2F0(battleInput);
            return;
        }
        break;
    }
}

static void ov16_0226B780(SysTask *param0, void *param1)
{
    BattleInput *battleInput = param1;
    BgConfig *v1;
    int i, v2, v3;
    u8 v4[4];

    v1 = BattleSystem_GetBgConfig(battleInput->battleSystem);

    switch (battleInput->unk_67C.unk_00) {
    case 0:
        ov16_0226B264(battleInput, battleInput->unk_67C.unk_04_val4.unk_1C, v4, 1);

        for (i = 0; i < 4; i++) {
            if (v4[i] == 1) {
                ov16_0226B31C(battleInput, Unk_ov16_022703D4[i], &Unk_ov16_0227033C[i], 4, 2);

                if (battleInput->textObj[0 + i].fontOAM != NULL) {
                    sub_020129A4(battleInput->textObj[0 + i].fontOAM, &v2, &v3);
                    sub_020128C4(battleInput->textObj[0 + i].fontOAM, v2, v3 + -2);
                }

                if (battleInput->unk_60C[i] != NULL) {
                    sub_0200D5DC(battleInput->unk_60C[i], 0, -2);
                }
            }
        }

        battleInput->unk_67C.unk_00++;
        break;
    case 1:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 <= 0) {
            break;
        }

        battleInput->unk_67C.unk_02 = 0;
        battleInput->unk_67C.unk_00++;
    case 2:
        ov16_0226B264(battleInput, battleInput->unk_67C.unk_04_val4.unk_1C, v4, 1);

        for (i = 0; i < 4; i++) {
            if (v4[i] == 1) {
                ov16_0226B31C(battleInput, Unk_ov16_022703D4[i], &Unk_ov16_0227033C[i], 4, 1);

                if (battleInput->textObj[0 + i].fontOAM != NULL) {
                    sub_020129A4(battleInput->textObj[0 + i].fontOAM, &v2, &v3);
                    sub_020128C4(battleInput->textObj[0 + i].fontOAM, v2, v3 + 1);
                }

                if (battleInput->unk_60C[i] != NULL) {
                    sub_0200D5DC(battleInput->unk_60C[i], 0, 1);
                }
            }
        }

        battleInput->unk_67C.unk_00++;
        break;
    case 3:
        battleInput->unk_67C.unk_02++;

        if (battleInput->unk_67C.unk_02 > 0) {
            battleInput->unk_67C.unk_02 = 0;
            battleInput->unk_67C.unk_00++;
        }
        break;
    default:
        ov16_0226B1C4(battleInput, 1, 1);
        ov16_0226B2F0(battleInput);
        return;
    }
}

static TextColor GetPPTextColor(int pp, int maxPp)
{
    if (pp == 0) {
        return TEXT_COLOR(7, 8, 0);
    }

    if (maxPp == pp) {
        return TEXT_COLOR(1, 2, 0);
    }

    if (maxPp <= 2) {
        if (pp == 1) {
            return TEXT_COLOR(5, 6, 0);
        }
    } else if (maxPp <= 7) {
        switch (pp) {
        case 1:
            return TEXT_COLOR(5, 6, 0);
        case 2:
            return TEXT_COLOR(3, 4, 0);
        }
    } else {
        if (pp <= maxPp / 4) {
            return TEXT_COLOR(5, 6, 0);
        }

        if (pp <= maxPp / 2) {
            return TEXT_COLOR(3, 4, 0);
        }
    }

    return TEXT_COLOR(1, 2, 0);
}

static void ov16_0226B988(SysTask *task, void *param1)
{
    UnkStruct_ov16_0226B988 *v0 = param1;
    BgConfig *bgConfig = BattleSystem_GetBgConfig(v0->battleInput->battleSystem);

    switch (v0->unk_13) {
    case 0:
        v0->unk_08 += ((255 * 100) / 4);
        v0->unk_0A -= ((40 * 100) / 4);
        v0->unk_0C = ((255 * 100) - v0->unk_08) / 100;
        v0->unk_0E = -v0->unk_0A / 100;

        if ((v0->unk_08 >= 0) || (v0->unk_0A <= 0)) {
            v0->unk_08 = 0;
            v0->unk_0A = (18 * 8);
            v0->unk_0C = 0 / 100;
            v0->unk_0E = 0 / 100;
            v0->unk_13++;
        }
        break;
    case 1:
        v0->battleInput->unk_66E = 0;
        SysTask_Done(v0->unk_04);
        DisableHBlank();
        GXS_SetVisibleWnd(GX_WNDMASK_NONE);
        ov16_0226BCCC(v0->battleInput, 1);
        v0->unk_13++;
        break;
    default:
        if (ov16_0226BCD0(v0->battleInput) == 0) {
            break;
        }

        Bg_SetOffset(bgConfig, 4, 0, 0);
        Bg_SetOffset(bgConfig, 4, 3, 0);
        Bg_SetOffset(bgConfig, 5, 0, 0);
        Bg_SetOffset(bgConfig, 5, 3, 0);
        BattleSystem_SetCommandSelectionFlags(v0->battleInput->battleSystem, 1);
        Heap_FreeToHeap(param1);
        SysTask_Done(task);

        return;
    }
}

static void ov16_0226BA88(SysTask *param0, void *param1)
{
    UnkStruct_ov16_0226B988 *v0 = param1;
    s32 v2, v3, v4;

    BgConfig *bgConfig = BattleSystem_GetBgConfig(v0->battleInput->battleSystem);

    if (v0->unk_12 == 4) {
        v4 = 255 - v0->unk_0C;

        if (v4 > 0) {
            v4 = 0;
        }

        Bg_SetOffset(bgConfig, 4, 0, v4);
        Bg_SetOffset(bgConfig, 5, 0, 255 - v0->unk_0C);
        v2 = -v0->unk_08 / 100;
    } else {
        v4 = v0->unk_0C;

        if (v4 < 0) {
            v4 = 0;
        }

        Bg_SetOffset(bgConfig, 4, 0, v4);
        Bg_SetOffset(bgConfig, 5, 0, v0->unk_0C);

        v2 = 255 + v0->unk_08 / 100;
    }

    Bg_SetOffset(bgConfig, 4, 3, 0);
    Bg_SetOffset(bgConfig, 5, 3, 0);

    v3 = (18 * 8) + (v0->unk_0A) / 100;

    if (v2 < 0) {
        v2 = 0;
    } else if (v2 > 255) {
        v2 = 255;
    }

    if (v3 > 192) {
        v3 = 192;
    } else if (v3 < 0) {
        v3 = 0;
    }

    if (v0->unk_12 == 4) {
        G2S_SetWnd0Position(0, 0, v2, (18 * 8));
    } else {
        if (v2 == 0) {
            v2 = 1;
        }

        G2S_SetWnd0Position(v2, 0, 0, (18 * 8));
    }

    G2S_SetWnd1Position(0, (18 * 8), 255, v3);
    v0->unk_10 = v0->unk_0E;
}

static void ov16_0226BB94(void *param0)
{
    UnkStruct_ov16_0226B988 *v0 = param0;
    s32 v1, v2;

    v1 = GX_GetVCount();

    if (v1 == (18 * 8)) {
        BgConfig *v3 = BattleSystem_GetBgConfig(v0->battleInput->battleSystem);

        Bg_SetOffset(v3, 4, 0, 0);
        Bg_SetOffset(v3, 4, 3, v0->unk_10);
        Bg_SetOffset(v3, 5, 0, 0);
        Bg_SetOffset(v3, 5, 3, v0->unk_10);
    } else if (v1 > 192) {
        BgConfig *v4 = BattleSystem_GetBgConfig(v0->battleInput->battleSystem);

        if (v0->unk_12 == 4) {
            v2 = 255 - v0->unk_0C;

            if (v2 > 0) {
                v2 = 0;
            }

            Bg_SetOffset(v4, 4, 0, 255 - v0->unk_0C);
            Bg_SetOffset(v4, 5, 0, 255 - v0->unk_0C);
        } else {
            v2 = v0->unk_0C;

            if (v2 < 0) {
                v2 = 0;
            }

            Bg_SetOffset(v4, 4, 0, v0->unk_0C);
            Bg_SetOffset(v4, 5, 0, v0->unk_0C);
        }

        Bg_SetOffset(v4, 4, 3, 0);
        Bg_SetOffset(v4, 5, 3, 0);
    }
}

static void ov16_0226BC50(SysTask *task, void *param1)
{
    BattleInput *battleInput = param1;
    const UnkStruct_ov16_02270670 *v1;
    int i;

    v1 = &Unk_ov16_02270670[battleInput->unk_66B];

    for (i = 0; i < 4; i++) {
        if (v1->unk_04_val2[i] == 0xffff) {
            Bg_ToggleLayer(4 + i, 0);
        } else {
            Bg_ToggleLayer(4 + i, 1);
        }
    }

    for (i = 0; i < 4; i++) {
        Bg_SetPriority(4 + i, v1->unk_0C_val2[i]);
    }

    SysTask_Done(task);
}

static void ov16_0226BCBC(SysTask *task, void *param1)
{
    BattleInput *battleInput = param1;

    ov16_0226B198();
    SysTask_Done(task);
}

void ov16_0226BCCC(BattleInput *battleInput, int param1)
{
    return;
}

BOOL ov16_0226BCD0(BattleInput *battleInput)
{
    if (battleInput->unk_664 == NULL) {
        return 1;
    }

    return 0;
}

static void ov16_0226BCE4(SysTask *task, void *param1)
{
    BattleInput *battleInput = param1;
    int v1;
    u16 v2;
    PaletteData *v3;
    s16 v4;

    v3 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    if (PaletteData_GetSelectedBuffersMask(v3) != 0) {
        return;
    }

    {
        PaletteData_Blend(v3, 1, 16 * 0 + 1, 1, battleInput->unk_676 >> 8, 0x7e37);

        if (battleInput->unk_674 == 0) {
            battleInput->unk_676 += 0x200;
        } else {
            battleInput->unk_676 -= 0x200;
        }

        if (battleInput->unk_676 >= (16 + 1) << 8) {
            battleInput->unk_676 = (16 - 1) << 8;
            battleInput->unk_674 = 1;
        } else if (battleInput->unk_676 <= 0) {
            battleInput->unk_676 = 1 << 8;
            battleInput->unk_674 = 0;
        }
    }
}

static void ov16_0226BD74(SysTask *task, void *param1)
{
    BattleInput *battleInput = param1;
    PaletteData *v1;
    u16 *v2;
    int v3;
    int v4, v5;

    v4 = RenderControlFlags_GetSpeedUpBattle();
    v5 = RenderControlFlags_GetWaitBattle();

    RenderControlFlags_ZeroSpeedUpBattle();
    RenderControlFlags_ZeroWaitBattle();

    v1 = BattleSystem_GetPaletteData(battleInput->battleSystem);

    if (PaletteData_GetSelectedBuffersMask(v1) != 0) {
        return;
    }

    v2 = PaletteData_GetFadedBuffer(v1, 1);
    v3 = (16 - 8) * 2;

    if (gCoreSys.touchHeld && ((v4 == 1) || (v5 == 1))) {
        if (memcmp(&v2[8], &battleInput->unk_5C[8], v3) == 0) {
            if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_FRONTIER) {
                MI_CpuCopy16(&battleInput->unk_60[0], &v2[0], 0x20);
                MI_CpuCopy16(&battleInput->unk_60[16], &v2[7 * 16], 0x20);
            } else {
                MI_CpuCopy16(&battleInput->unk_60[8], &v2[8], v3);
            }
        }
    } else {
        if (memcmp(&v2[8], &battleInput->unk_60[8], v3) == 0) {
            if (BattleSystem_GetBattleType(battleInput->battleSystem) & BATTLE_TYPE_FRONTIER) {
                MI_CpuCopy16(&battleInput->unk_5C[0], &v2[0], 0x20);
                MI_CpuCopy16(&battleInput->unk_5C[16], &v2[7 * 16], 0x20);
            } else {
                MI_CpuCopy16(&battleInput->unk_5C[8], &v2[8], v3);
            }
        }
    }
}

static int ov16_0226BE48(BattleInput *battleInput)
{
    BattleCursorMove *v0;
    const UnkStruct_ov16_02270670 *v1;

    v0 = &battleInput->unk_6BC;
    v1 = &Unk_ov16_02270670[battleInput->unk_66B];

    if (v1->unk_20 == NULL) {
        return 0xffffffff;
    }

    if (v0->unk_00 == 0) {
        if ((battleInput->unk_6C0 == 1) || (gCoreSys.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_KEY_RIGHT | PAD_KEY_LEFT | PAD_KEY_UP | PAD_KEY_DOWN))) {
            if (battleInput->unk_6C0 == 0) {
                Sound_PlayEffect(1500);
            }

            v0->unk_00 = 1;
            battleInput->unk_6C0 = 0;
            v1->unk_20(battleInput, 1);
        }

        return 0xffffffff;
    }

    return v1->unk_20(battleInput, 0);
}

static int ov16_0226BEC0(BattleInput *battleInput, int param1)
{
    BattleCursorMove *v0;
    u32 v1;
    const UnkStruct_ov16_02270670 *v2;
    int i, v4, v5;
    BattleCursorPosition *v6;

    v0 = &battleInput->unk_6BC;
    v2 = &Unk_ov16_02270670[battleInput->unk_66B];
    v5 = BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A);
    v6 = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, v5));

    if (param1 == 1) {
        v0->unk_02 = v6->commandX;
        v0->unk_01 = v6->commandY;
        v4 = Unk_ov16_022701EC[v0->unk_01][v0->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        return 0xffffffff;
    }

    switch (battleInput->unk_66B) {
    case 6:
    case 5:
        v1 = ov16_0226CB10(v0, 1, 1, Unk_ov16_022701EC[0]);
        break;
    default:
        v4 = Unk_ov16_022701EC[v0->unk_01][v0->unk_02];

        if ((v4 == 3) && (gCoreSys.pressedKeys & PAD_KEY_UP)) {
            (void)0;
        } else {
            v1 = ov16_0226CB10(v0, 3, 2, Unk_ov16_022701EC[0]);

            if ((v1 == 0) && (v4 == 0)) {
                if (gCoreSys.pressedKeys & PAD_KEY_LEFT) {
                    v0->unk_02 = 0;
                    v0->unk_01 = 1;
                    Sound_PlayEffect(1500);
                    v1 = PAD_KEY_LEFT;
                } else if (gCoreSys.pressedKeys & PAD_KEY_RIGHT) {
                    v0->unk_02 = 2;
                    v0->unk_01 = 1;
                    Sound_PlayEffect(1500);
                    v1 = PAD_KEY_RIGHT;
                }
            }
        }
        break;
    }

    switch (v1) {
    case PAD_KEY_UP:
    case PAD_KEY_DOWN:
    case PAD_KEY_LEFT:
    case PAD_KEY_RIGHT:
        v4 = Unk_ov16_022701EC[v0->unk_01][v0->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        break;
    case PAD_BUTTON_A:
        return Unk_ov16_022701EC[v0->unk_01][v0->unk_02];
    case PAD_BUTTON_B:
        if (battleInput->unk_66F == 1) {
            for (i = 0; i < v2->unk_14[i].rect.top != 0xff; i++) {
                if (4 == v2->unk_18[i]) {
                    return i;
                }
            }
        }
        break;
    }

    return 0xffffffff;
}

static void BattleInput_SaveBattlerCursorPosition(BattleInput *battleInput, int param1)
{
    BattleCursorPosition *cursor;
    int v1, j, i;

    v1 = BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A);

    if ((param1 != 3) || (battleInput->unk_6C1 == 0)) {
        cursor = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, v1));

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                if (param1 == Unk_ov16_022701EC[i][j]) {
                    cursor->commandX = j;
                    cursor->commandY = i;

                    return;
                }
            }
        }
    }
}

static int ov16_0226C100(BattleInput *battleInput, int param1)
{
    BattleCursorMove *v0;
    u32 v1;
    const UnkStruct_ov16_02270670 *v2;
    int v3, v4;

    v0 = &battleInput->unk_6BC;
    v2 = &Unk_ov16_02270670[battleInput->unk_66B];

    if (param1 == 1) {
        v0->unk_02 = 0;
        v0->unk_01 = 0;
        v4 = Unk_ov16_022701CC[v0->unk_01][v0->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        return 0xffffffff;
    }

    v1 = ov16_0226CB10(v0, 1, 2, Unk_ov16_022701CC[0]);

    switch (v1) {
    case PAD_KEY_UP:
    case PAD_KEY_DOWN:
    case PAD_KEY_LEFT:
    case PAD_KEY_RIGHT:
        v4 = Unk_ov16_022701CC[v0->unk_01][v0->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        break;
    case PAD_BUTTON_A:
        return Unk_ov16_022701CC[v0->unk_01][v0->unk_02];
    case PAD_BUTTON_B:
        break;
    }

    return 0xffffffff;
}

static int ov16_0226C1F8(BattleInput *battleInput, int param1)
{
    BattleCursorMove *v0;
    u32 v1;
    const UnkStruct_ov16_02270670 *v2;
    int v3, i;
    u8 v5[3][2];
    UnkStruct_ov16_02260C00 *v6;
    BattleCursorPosition *cursorPos;

    cursorPos = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A)));
    v0 = &battleInput->unk_6BC;
    v2 = &Unk_ov16_02270670[battleInput->unk_66B];
    v6 = &battleInput->unk_1A.val2;

    if (param1 == 1) {
        v0->unk_02 = cursorPos->moveX;
        v0->unk_01 = cursorPos->moveY;
        v3 = Unk_ov16_022701E4[v0->unk_01][v0->unk_02];

        if ((v3 != 0) && (v6->unk_00[v3 - 1] == 0)) {
            cursorPos->moveX = 0;
            cursorPos->moveY = 0;
            v0->unk_02 = 0;
            v0->unk_01 = 0;
            v3 = Unk_ov16_022701E4[v0->unk_01][v0->unk_02];
        }

        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v3].rect.left + 8, v2->unk_14[v3].rect.right - 8, v2->unk_14[v3].rect.top + 8, v2->unk_14[v3].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        return 0xffffffff;
    }

    MI_CpuCopy8(Unk_ov16_022701E4, v5, 3 * 2);
    v1 = ov16_0226CB10(v0, 2, 3, v5[0]);

    switch (v1) {
    case PAD_KEY_UP:
    case PAD_KEY_DOWN:
    case PAD_KEY_LEFT:
    case PAD_KEY_RIGHT:
        v3 = Unk_ov16_022701E4[v0->unk_01][v0->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v3].rect.left + 8, v2->unk_14[v3].rect.right - 8, v2->unk_14[v3].rect.top + 8, v2->unk_14[v3].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        break;
    case PAD_BUTTON_A:
        return Unk_ov16_022701E4[v0->unk_01][v0->unk_02];
    case PAD_BUTTON_B:
        for (i = 0; i < v2->unk_14[i].rect.top != 0xff; i++) {
            if (0xff == v2->unk_18[i]) {
                return i;
            }
        }

        break;
    }

    return 0xffffffff;
}

static void BattleInput_SaveBattlerMovePosition(BattleInput *battleInput, int param1)
{
    BattleCursorPosition *cursorPos;
    int v1, j, i;

    if (param1 == 0) {
        return;
    }

    v1 = BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A);
    cursorPos = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, v1));

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (param1 == Unk_ov16_022701E4[i][j]) {
                cursorPos->moveX = j;
                cursorPos->moveY = i;
                return;
            }
        }
    }
}

static int ov16_0226C3C8(BattleInput *battleInput, int param1)
{
    BattleCursorMove *v0;
    u32 v1;
    const UnkStruct_ov16_02270670 *v2;
    int v3, v4;
    int v5 = 0;
    u8 v6[4], v7[4];
    u8 v8[3][2];
    int i, j, v11, v12;
    int v13, v14, v15, v16, v17, v18;
    int v19, v20, v21, v22;
    int v23, v24, v25, v26;
    int v27, v28;
    int v29;
    BattleCursorPosition *v30;

    v30 = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A)));
    v0 = &battleInput->unk_6BC;
    v2 = &Unk_ov16_02270670[battleInput->unk_66B];

    MI_CpuCopy8(Unk_ov16_022701DC, v8, 3 * 2);

    ov16_0226B20C(battleInput, v6, 1);
    ov16_0226B20C(battleInput, v7, 0);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (v7[v8[i][j]] == 0) {
                v8[i][j] = 0xff;
            }
        }
    }

    switch (battleInput->unk_66C) {
    default:
    case 0:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
        v11 = 2;
        v12 = 3;
        break;
    case 1:
    case 2:
    case 3:
    case 5:
    case 7:
        v5 = 1;
        v11 = 1;
        v12 = 2;

        if ((v7[5 - 2] == 1) && (v7[3 - 2] == 1)) {
            v21 = v2->unk_14[3].rect.left + 8;
            v22 = v2->unk_14[1].rect.right - 8;
            v19 = v2->unk_14[3].rect.top + 8;
            v20 = v2->unk_14[3].rect.bottom - 8;
        } else if ((v7[5 - 2] == 1) && (v7[3 - 2] == 0)) {
            v21 = v2->unk_14[3].rect.left + 8;
            v22 = v2->unk_14[3].rect.right - 8;
            v19 = v2->unk_14[3].rect.top + 8;
            v20 = v2->unk_14[3].rect.bottom - 8;
        } else if ((v7[5 - 2] == 0) && (v7[3 - 2] == 1)) {
            v21 = v2->unk_14[1].rect.left + 8;
            v22 = v2->unk_14[1].rect.right - 8;
            v19 = v2->unk_14[1].rect.top + 8;
            v20 = v2->unk_14[1].rect.bottom - 8;
        } else {
            v21 = -1;
            v22 = -1;
            v19 = -1;
            v20 = -1;
        }

        if ((v7[2 - 2] == 1) && (v7[4 - 2] == 1)) {
            v25 = v2->unk_14[0].rect.left + 8;
            v26 = v2->unk_14[2].rect.right - 8;
            v23 = v2->unk_14[0].rect.top + 8;
            v24 = v2->unk_14[0].rect.bottom - 8;
        } else if ((v7[2 - 2] == 1) && (v7[4 - 2] == 0)) {
            v25 = v2->unk_14[0].rect.left + 8;
            v26 = v2->unk_14[0].rect.right - 8;
            v23 = v2->unk_14[0].rect.top + 8;
            v24 = v2->unk_14[0].rect.bottom - 8;
        } else if ((v7[2 - 2] == 0) && (v7[4 - 2] == 1)) {
            v25 = v2->unk_14[2].rect.left + 8;
            v26 = v2->unk_14[2].rect.right - 8;
            v23 = v2->unk_14[2].rect.top + 8;
            v24 = v2->unk_14[2].rect.bottom - 8;
        } else {
            v25 = -1;
            v26 = -1;
            v23 = -1;
            v24 = -1;
        }

        v17 = -1;
        v18 = -1;
        v27 = -1;
        v28 = -1;

        if (v21 == v25) {
            v13 = v21;
        } else if ((v21 != -1) && (v25 == -1)) {
            v13 = v21;
        } else if ((v21 == -1) && (v25 != -1)) {
            v13 = v25;
        } else {
            v13 = v21;
            v17 = v25;
            v29 = 2;
        }

        if (v22 == v26) {
            v14 = v22;
        } else if ((v22 != -1) && (v26 == -1)) {
            v14 = v22;
        } else if ((v22 == -1) && (v26 != -1)) {
            v14 = v26;
        } else {
            v14 = v22;
            v17 = v26;
            v29 = 3;
        }

        if ((v19 != -1) && (v23 == -1)) {
            v15 = v19;
        } else if ((v19 == -1) && (v23 != -1)) {
            v15 = v23;
        } else {
            v15 = v19;
            v18 = v20;
        }

        if ((v20 != -1) && (v24 == -1)) {
            v16 = v20;
        } else if ((v20 == -1) && (v24 != -1)) {
            v16 = v24;
        } else {
            v16 = v24;
            v18 = v24;

            if (v29 == 2) {
                v28 = v20;
            } else {
                v27 = v20;
            }
        }

        break;
    }

    if (param1 == 1) {
        if (v5 == 0) {
            if (v30->unk_06 == battleInput->unk_66C) {
                v0->unk_02 = v30->unk_04;
                v0->unk_01 = v30->unk_05;
            } else if (v6[5 - 2] == 1) {
                v0->unk_02 = 0;
                v0->unk_01 = 0;
            } else if (v6[3 - 2] == 1) {
                v0->unk_02 = 1;
                v0->unk_01 = 0;
            } else if (v6[2 - 2] == 1) {
                v0->unk_02 = 0;
                v0->unk_01 = 1;
            } else {
                v0->unk_02 = 1;
                v0->unk_01 = 1;
            }

            v4 = Unk_ov16_022701DC[v0->unk_01][v0->unk_02];
            ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        } else {
            v0->unk_02 = 0;
            v0->unk_01 = 0;

            if (((v28 == -1) && (v27 == -1)) || (v17 == -1)) {
                ov16_0226DD9C(battleInput->cursor, v13, v14, v15, v16, ((192 + 80) << FX32_SHIFT));
            } else if ((v28 != -1) && (v27 == -1)) {
                ov16_0226DCCC(battleInput->cursor, v13, v15, v14, v15, v13, v28, v14, v16, ((192 + 80) << FX32_SHIFT));
            } else {
                ov16_0226DCCC(battleInput->cursor, v13, v15, v14, v15, v13, v16, v14, v27, ((192 + 80) << FX32_SHIFT));
            }

            if (v17 != -1) {
                ov16_0226DDC0(battleInput->cursor, v17, v18, v29, ((192 + 80) << FX32_SHIFT));
            }
        }

        return 0xffffffff;
    }

    if (v5 == 0) {
        v1 = ov16_0226CB10(v0, v11, v12, v8[0]);
    } else {
        v1 = ov16_0226CB10(v0, v11, v12, NULL);
    }

    switch (v1) {
    case PAD_KEY_UP:
    case PAD_KEY_DOWN:
    case PAD_KEY_LEFT:
    case PAD_KEY_RIGHT:
        if (v5 == 0) {
            v4 = Unk_ov16_022701DC[v0->unk_01][v0->unk_02];
            ov16_0226DD9C(battleInput->cursor, v2->unk_14[v4].rect.left + 8, v2->unk_14[v4].rect.right - 8, v2->unk_14[v4].rect.top + 8, v2->unk_14[v4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        } else {
            if (v0->unk_01 == 0) {
                if (((v27 == -1) && (v28 == -1)) || (v17 == -1)) {
                    ov16_0226DD9C(battleInput->cursor, v13, v14, v15, v16, ((192 + 80) << FX32_SHIFT));
                } else if ((v28 != -1) && (v27 == -1)) {
                    ov16_0226DCCC(battleInput->cursor, v13, v15, v14, v15, v13, v28, v14, v16, ((192 + 80) << FX32_SHIFT));
                } else {
                    ov16_0226DCCC(battleInput->cursor, v13, v15, v14, v15, v13, v16, v14, v27, ((192 + 80) << FX32_SHIFT));
                }

                if (v17 != -1) {
                    ov16_0226DDC0(battleInput->cursor, v17, v18, v29, ((192 + 80) << FX32_SHIFT));
                } else {
                    ov16_0226DE04(battleInput->cursor);
                }
            } else {
                ov16_0226DD9C(battleInput->cursor, v2->unk_14[4].rect.left + 8, v2->unk_14[4].rect.right - 8, v2->unk_14[4].rect.top + 8, v2->unk_14[4].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
                ov16_0226DE04(battleInput->cursor);
            }
        }
        break;
    case PAD_BUTTON_A:
        if (v5 == 1) {
            if (v0->unk_01 > 0) {
                return 4;
            } else {
                for (v3 = 0; v3 < 4; v3++) {
                    if (v6[v3] == 1) {
                        return 0 + v3;
                    }
                }
            }
        } else {
            v4 = Unk_ov16_022701DC[v0->unk_01][v0->unk_02];

            if ((v4 == 4) || (v6[v4 - 0] == 1)) {
                return v4;
            }
        }
        break;
    case PAD_BUTTON_B:
        return 4;
    }

    return 0xffffffff;
}

static void ov16_0226C9B8(BattleInput *battleInput, int param1)
{
    BattleCursorPosition *v0;
    int v1, j, i;

    if (param1 == 4) {
        return;
    }

    v1 = BattleSystem_BattlerOfType(battleInput->battleSystem, battleInput->unk_66A);
    v0 = Battler_GetCursorPosition(BattleSystem_BattlerData(battleInput->battleSystem, v1));

    v0->unk_06 = battleInput->unk_66C;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (param1 == Unk_ov16_022701DC[i][j]) {
                v0->unk_04 = j;
                v0->unk_05 = i;

                return;
            }
        }
    }
}

static int ov16_0226CA14(BattleInput *battleInput, int param1)
{
    BattleCursorMove *cursorMove;
    u32 v1;
    const UnkStruct_ov16_02270670 *v2;
    int v3, v4;

    cursorMove = &battleInput->unk_6BC;
    v2 = &Unk_ov16_02270670[battleInput->unk_66B];

    if (param1 == 1) {
        v3 = Unk_ov16_022701C8[cursorMove->unk_01][cursorMove->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v3].rect.left + 8, v2->unk_14[v3].rect.right - 8, v2->unk_14[v3].rect.top + 8, v2->unk_14[v3].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        return 0xffffffff;
    }

    v1 = ov16_0226CB10(cursorMove, 1, 2, Unk_ov16_022701C8[0]);

    switch (v1) {
    case PAD_KEY_UP:
    case PAD_KEY_DOWN:
    case PAD_KEY_LEFT:
    case PAD_KEY_RIGHT:
        v3 = Unk_ov16_022701C8[cursorMove->unk_01][cursorMove->unk_02];
        ov16_0226DD9C(battleInput->cursor, v2->unk_14[v3].rect.left + 8, v2->unk_14[v3].rect.right - 8, v2->unk_14[v3].rect.top + 8, v2->unk_14[v3].rect.bottom - 8, ((192 + 80) << FX32_SHIFT));
        break;
    case PAD_BUTTON_A:
        v3 = Unk_ov16_022701C8[cursorMove->unk_01][cursorMove->unk_02];
        return v3;
    case PAD_BUTTON_B:
        return 1;
    }

    return 0xffffffff;
}

static u32 ov16_0226CB10(BattleCursorMove *cursorMove, int param1, int param2, const u8 *param3)
{
    int v0, v1;
    u32 v2;

    if (cursorMove->unk_02 >= param1) {
        cursorMove->unk_02 = param1 - 1;
    }

    if (cursorMove->unk_01 >= param2) {
        cursorMove->unk_01 = param2 - 1;
    }

    v1 = cursorMove->unk_02;
    v0 = cursorMove->unk_01;

    if (gCoreSys.pressedKeys & PAD_KEY_UP) {
        cursorMove->unk_01--;

        if (cursorMove->unk_01 < 0) {
            cursorMove->unk_01 = 0;
        }

        if (param3 != NULL) {
            while (param3[param1 * cursorMove->unk_01 + cursorMove->unk_02] == 0xff) {
                cursorMove->unk_01--;

                if (cursorMove->unk_01 < 0) {
                    cursorMove->unk_01 = v0;
                    break;
                }
            }
        }

        v2 = PAD_KEY_UP;
    } else if (gCoreSys.pressedKeys & PAD_KEY_DOWN) {
        cursorMove->unk_01++;

        if (cursorMove->unk_01 >= param2) {
            cursorMove->unk_01 = param2 - 1;
        }

        if (param3 != NULL) {
            while (param3[param1 * cursorMove->unk_01 + cursorMove->unk_02] == 0xff) {
                cursorMove->unk_01++;

                if (cursorMove->unk_01 >= param2) {
                    cursorMove->unk_01 = v0;
                    break;
                }
            }
        }

        v2 = PAD_KEY_DOWN;
    } else if (gCoreSys.pressedKeys & PAD_KEY_LEFT) {
        cursorMove->unk_02--;

        if (cursorMove->unk_02 < 0) {
            cursorMove->unk_02 = 0;
        }

        if (param3 != NULL) {
            while (param3[param1 * cursorMove->unk_01 + cursorMove->unk_02] == 0xff) {
                cursorMove->unk_02--;

                if (cursorMove->unk_02 < 0) {
                    cursorMove->unk_02 = v1;
                    break;
                }
            }
        }

        v2 = PAD_KEY_LEFT;
    } else if (gCoreSys.pressedKeys & PAD_KEY_RIGHT) {
        cursorMove->unk_02++;

        if (cursorMove->unk_02 >= param1) {
            cursorMove->unk_02 = param1 - 1;
        }

        if (param3 != NULL) {
            while (param3[param1 * cursorMove->unk_01 + cursorMove->unk_02] == 0xff) {
                cursorMove->unk_02++;

                if (cursorMove->unk_02 >= param1) {
                    cursorMove->unk_02 = v1;
                    break;
                }
            }
        }

        v2 = PAD_KEY_RIGHT;
    } else if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
        v2 = PAD_BUTTON_A;
    } else if (gCoreSys.pressedKeys & PAD_BUTTON_B) {
        v2 = PAD_BUTTON_B;
    } else {
        return 0;
    }

    if (param3 != NULL) {
        int v3, v4;

        v3 = param3[param1 * v0 + v1];
        v4 = param3[param1 * cursorMove->unk_01 + cursorMove->unk_02];

        if (v3 == v4) {
            cursorMove->unk_02 = v1;
            cursorMove->unk_01 = v0;
        }
    }

    if ((cursorMove->unk_02 != v1) || (cursorMove->unk_01 != v0)) {
        Sound_PlayEffect(1500);
    } else {
        if (v2 & PAD_KEY) {
            return 0;
        }
    }

    return v2;
}

int ov16_0226CD08(BattleInput *battleInput)
{
    return battleInput->unk_6C0;
}

void ov16_0226CD10(BattleInput *battleInput, int param1)
{
    battleInput->unk_6C0 = param1;
}

static int (*const Unk_ov16_0227020C[])(BattleInput *) = {
    BattleInput_CatchingTutorialFight,
    BattleInput_CatchingTutorialMove
};

static int BattleInput_CatchingTutorialMain(BattleInput *battleInput)
{
    SpriteRenderer *v0;
    SpriteGfxHandler *v1;
    PaletteData *v2;
    int v3;

    v0 = ov16_0223E010(battleInput->battleSystem);
    v1 = ov16_0223E018(battleInput->battleSystem);
    v2 = BattleSystem_GetPaletteData(battleInput->battleSystem);
    v3 = 0xffffffff;

    if (ov16_0223F228(battleInput->battleSystem) == 0) {
        GF_ASSERT(battleInput->catchingTutorial.unk_04 < NELEMS(Unk_ov16_0227020C));
        v3 = Unk_ov16_0227020C[battleInput->catchingTutorial.unk_04](battleInput);
    } else {
        v3 = BattleInput_CatchingTutorialBag(battleInput);
    }

    if (v3 != 0xffffffff) {
        battleInput->catchingTutorial.state = 0;
        battleInput->catchingTutorial.unk_06 = 0;
        battleInput->catchingTutorial.unk_04++;
    }

    return v3;
}

static int BattleInput_CatchingTutorialFight(BattleInput *battleInput)
{
    switch (battleInput->catchingTutorial.state) {
    case 0:
        ov16_0226DF80(battleInput->catchingTutorial.finger, 128, 84 - 24, ((192 + 80) << FX32_SHIFT));
        ov16_0226DFD0(battleInput->catchingTutorial.finger, 60);
        battleInput->catchingTutorial.state++;
        break;
    default:
        if (ov16_0226DFD4(battleInput->catchingTutorial.finger) == 1) {
            battleInput->catchingTutorial.state++;
            return 0;
        }

        break;
    }

    return 0xffffffff;
}

static int BattleInput_CatchingTutorialMove(BattleInput *battleInput)
{
    switch (battleInput->catchingTutorial.state) {
    case 0:
        ov16_0226DF80(battleInput->catchingTutorial.finger, 64, 46 - 24, ((192 + 80) << FX32_SHIFT));
        ov16_0226DFD0(battleInput->catchingTutorial.finger, 60);
        battleInput->catchingTutorial.state++;
        break;
    default:
        if (ov16_0226DFD4(battleInput->catchingTutorial.finger) == 1) {
            battleInput->catchingTutorial.state++;
            return 1;
        }
        break;
    }

    return 0xffffffff;
}

static int BattleInput_CatchingTutorialBag(BattleInput *battleInput)
{
    switch (battleInput->catchingTutorial.state) {
    case 0:
        battleInput->catchingTutorial.unk_06++;

        if (battleInput->catchingTutorial.unk_06 > 60) {
            battleInput->catchingTutorial.unk_06 = 0;
            battleInput->catchingTutorial.state++;
        }
        break;
    case 1:
        ov16_0226DF80(battleInput->catchingTutorial.finger, 40, 170 - 24, ((192 + 80) << FX32_SHIFT));
        ov16_0226DFD0(battleInput->catchingTutorial.finger, 60);
        battleInput->catchingTutorial.state++;
        break;
    default:
        if (ov16_0226DFD4(battleInput->catchingTutorial.finger) == 1) {
            battleInput->catchingTutorial.state++;
            return 1;
        }
        break;
    }

    return 0xffffffff;
}

void BattleInput_PrintRecordingStopMessage(BattleInput *battleInput, int param1)
{
    BgConfig *bgConfig = BattleSystem_GetBgConfig(battleInput->battleSystem);
    PaletteData *palette = BattleSystem_GetPaletteData(battleInput->battleSystem);

    GF_ASSERT(battleInput->unk_66B == 18);

    LoadStandardWindowGraphics(bgConfig, 5, 0x20, 1, 0, HEAP_ID_BATTLE);
    PaletteData_LoadBufferFromHardware(palette, 1, 1 * 16, 0x20);

    int v2 = 0x20, v3 = 1;
    int v4, v5, v6, v7;

    v4 = 1;
    v5 = 6;
    v6 = 30;
    v7 = 6;

    Bg_FillTilemapRect(bgConfig, 5, v2, v4, v5, 1, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 1, v4 + 1, v5, v6 - 2, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 2, v4 + v6 - 1, v5, 1, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 3, v4, v5 + 1, 1, v7 - 2, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 5, v4 + v6 - 1, v5 + 1, 1, v7 - 2, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 6, v4, v5 + v7 - 1, 1, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 7, v4 + 1, v5 + v7 - 1, v6 - 2, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 8, v4 + v6 - 1, v5 + v7 - 1, 1, 1, v3);
    Bg_FillTilemapRect(bgConfig, 5, v2 + 4, v4 + 1, v5 + 1, v6 - 2, v7 - 2, v3);
    Bg_ScheduleTilemapTransfer(bgConfig, 5);

    Strbuf *src;
    MessageLoader *msgLoader = BattleSystem_MessageLoader(battleInput->battleSystem);
    int i;
    const u16 v11[][2] = {
        // Playback paused
        // Please wait
        { pl_msg_00000368_01261, pl_msg_00000368_01262 },
        // Data is corrupted
        // Playback canceled
        { pl_msg_00000368_01263, pl_msg_00000368_01264 },
        // Battle is too long
        // Playback canceled
        { pl_msg_00000368_01265, pl_msg_00000368_01266 },
    };

    for (i = 0; i < 2; i++) {
        if (battleInput->textObj[1 + i].fontOAM != NULL) {
            GF_ASSERT(0);
            return;
        }

        src = MessageLoader_GetNewStrbuf(msgLoader, v11[param1][i]);

        BattleInput_CreateTextObject(battleInput, &battleInput->textObj[1 + i], src, FONT_SYSTEM, TEXT_COLOR(1, 2, 0), 4, 20023, 1 * 8 + 8, 6 * 8 + 16 + 16 * i, 0, NULL);
        Strbuf_Free(src);
    }
}

u8 ov16_0226D088(BattleInput *battleInput)
{
    return battleInput->unk_6C1;
}
