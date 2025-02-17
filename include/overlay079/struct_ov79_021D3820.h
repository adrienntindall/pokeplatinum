#ifndef POKEPLATINUM_STRUCT_OV79_021D3820_H
#define POKEPLATINUM_STRUCT_OV79_021D3820_H

#include "struct_defs/archived_sprite.h"
#include "struct_defs/pokemon_sprite.h"

#include "camera.h"

typedef struct {
    Camera *camera;
    void *unk_04;
    ArchivedSprite unk_08;
    PokemonSprite *unk_18;
} UnkStruct_ov79_021D3820;

#endif // POKEPLATINUM_STRUCT_OV79_021D3820_H
