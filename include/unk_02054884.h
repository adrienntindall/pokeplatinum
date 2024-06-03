#ifndef POKEPLATINUM_UNK_02054884_H
#define POKEPLATINUM_UNK_02054884_H

#include "pokemon.h"
#include "struct_decls/struct_party_decl.h"
#include "savedata.h"

BOOL sub_02054884(Pokemon * param0);
BOOL sub_020548B0(int param0, SaveData * param1, u16 param2, u8 param3, u16 param4, int param5, int param6);
BOOL sub_02054930(int param0, SaveData * param1, u16 param2, u8 param3, int param4, int param5);
void sub_02054988(Party * param0, int param1, int param2, u16 param3);
int sub_020549A0(Party * param0, u16 param1);
int sub_02054A10(const Party * param0);
Pokemon * Party_FirstBattler(const Party * param0);
Pokemon * sub_02054A74(const Party * param0);
BOOL Party_HasTwoAliveMons(const Party *party);
void sub_02054AC4(Party * param0);
int sub_02054B04(Party * param0, u16 param1);
BOOL sub_02054B94(Pokemon * param0);

#endif // POKEPLATINUM_UNK_02054884_H
