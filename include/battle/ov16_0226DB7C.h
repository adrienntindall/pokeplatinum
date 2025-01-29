#ifndef POKEPLATINUM_OV16_0226DB7C_H
#define POKEPLATINUM_OV16_0226DB7C_H

#include "struct_decls/struct_0200C6E4_decl.h"
#include "struct_decls/struct_0200C704_decl.h"

#include "battle/struct_ov16_0226DC24_decl.h"

#include "palette.h"

void BattleCursor_LoadResources(SpriteRenderer *param0, SpriteGfxHandler *param1, PaletteData *param2, int param3, u32 param4, u32 param5, u32 param6, u32 param7);
void BattleCursor_FreeResources(SpriteGfxHandler *param0, u32 param1, u32 param2, u32 param3, u32 param4);
BattleCursor *BattleCursor_New(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7, u32 param8);
void BattleCursor_Free(BattleCursor *param0);
void ov16_0226DCCC(BattleCursor *param0, int param1, int param2, int param3, int param4, int param5, int param6, int param7, int param8, fx32 param9);
void ov16_0226DD54(BattleCursor *param0, int param1, int param2, int param3, int param4, int param5, int param6, int param7, int param8);
void ov16_0226DD7C(BattleCursor *param0, int param1, int param2, int param3, int param4);
void ov16_0226DD9C(BattleCursor *param0, int param1, int param2, int param3, int param4, fx32 param5);
void ov16_0226DDC0(BattleCursor *param0, int param1, int param2, int param3, fx32 param4);
void BattleCursor_Disable(BattleCursor *param0);
void ov16_0226DE04(BattleCursor *param0);

#endif // POKEPLATINUM_OV16_0226DB7C_H
