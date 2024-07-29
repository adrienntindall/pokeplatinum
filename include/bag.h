#ifndef POKEPLATINUM_BAG_H
#define POKEPLATINUM_BAG_H

#include "constants/heap.h"

#include "savedata.h"

#define ITEM_POCKET_SIZE        165
#define KEY_ITEM_POCKET_SIZE    50
#define TMHM_POCKET_SIZE        100
#define MAIL_POCKET_SIZE        12
#define MEDICINE_POCKET_SIZE    40
#define BERRY_POCKET_SIZE       64
#define POKEBALL_POCKET_SIZE    15
#define BATTLE_ITEM_POCKET_SIZE 30

typedef struct BagItem {
    u16 item;
    u16 quantity;
} BagItem;

typedef struct Bag {
    BagItem items[ITEM_POCKET_SIZE];
    BagItem keyItems[KEY_ITEM_POCKET_SIZE];
    BagItem tmHms[TMHM_POCKET_SIZE];
    BagItem mail[MAIL_POCKET_SIZE];
    BagItem medicine[MEDICINE_POCKET_SIZE];
    BagItem berries[BERRY_POCKET_SIZE];
    BagItem pokeballs[POKEBALL_POCKET_SIZE];
    BagItem battleItems[BATTLE_ITEM_POCKET_SIZE];
    u32 registeredItem;
} Bag;

typedef struct {
    u8 unk_00[8];
    u8 unk_08[8];
    u16 unk_10;
    u16 unk_12;
} UnkStruct_0207D99C_sub1;

typedef struct {
    u8 unk_00[5];
    u8 unk_05[5];
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
} UnkStruct_0207D99C_sub2;

typedef struct UnkStruct_0207D99C_t {
    UnkStruct_0207D99C_sub1 unk_00;
    UnkStruct_0207D99C_sub2 unk_14;
} UnkStruct_0207D99C;

int Bag_SaveSize(void);
Bag *Bag_New(enum HeapId heapID);
void Bag_Init(Bag *bag);
void Bag_Copy(const Bag *src, Bag *dst);
u32 Bag_GetRegisteredItem(const Bag *bag);
void Bag_RegisterItem(Bag *bag, u32 item);
BOOL Bag_CanFitItem(Bag *bag, u16 item, u16 count, enum HeapId heapID);
BOOL Bag_TryAddItem(Bag *bag, u16 item, u16 count, enum HeapId heapID);
BOOL Bag_TryRemoveItem(Bag *bag, u16 item, u16 count, enum HeapId heapID);
BOOL Pocket_TryRemoveItem(BagItem *pocket, u32 pocketSize, u16 item, u16 count, enum HeapId heapID);
BOOL Bag_CanRemoveItem(Bag *bag, u16 item, u16 count, enum HeapId heapID);
BOOL Bag_HasItemsInPocket(Bag *bag, u32 pocketID);
u16 Bag_GetItemQuantity(Bag *bag, u16 item, enum HeapId heapID);
u16 Pocket_GetItemQuantity(BagItem *pocket, u32 pocketSize, u16 item, enum HeapId heapID);
void Pocket_SortEmpty(BagItem *pocket, const u32 size); // Moves empty slots to the end of the pocket
void Pocket_Sort(BagItem *pocket, const u32 size); // Same as Pocket_SortEmpty, but also sorts by item ID
void *sub_0207D824(Bag *bag, const u8 *pockets, enum HeapId heapID);
BagItem *Bag_GetItemSlot(Bag *bag, u16 pocketID, u16 slot);
Bag *SaveData_GetBag(SaveData *saveData);
UnkStruct_0207D99C *sub_0207D99C(u32 param0);
void sub_0207D9B4(UnkStruct_0207D99C *param0, u32 param1, u8 *param2, u8 *param3);
u16 sub_0207D9C4(UnkStruct_0207D99C *param0);
void sub_0207D9C8(UnkStruct_0207D99C *param0, u32 param1, u8 param2, u8 param3);
void sub_0207D9D4(UnkStruct_0207D99C *param0, u16 param1);
void sub_0207D9D8(UnkStruct_0207D99C *param0, u32 param1, u8 *param2, u8 *param3);
u16 sub_0207D9E4(UnkStruct_0207D99C *param0);
u16 sub_0207D9E8(UnkStruct_0207D99C *param0);
u16 sub_0207D9EC(UnkStruct_0207D99C *param0);
void sub_0207D9F0(UnkStruct_0207D99C *param0, u32 param1, u8 param2, u8 param3);
void sub_0207D9F8(UnkStruct_0207D99C *param0);
void Bag_SetLastItemUsed(UnkStruct_0207D99C *param0, u16 param1, u16 param2);
void sub_0207DA24(UnkStruct_0207D99C *param0, u16 param1);

#endif // POKEPLATINUM_BAG_H
