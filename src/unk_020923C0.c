#include "unk_020923C0.h"

#include <nitro.h>
#include <string.h>

typedef struct {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
} UnkStruct_020F51AC;

static const UnkStruct_020F51AC Unk_020F51AC[] = {
    { 0x62, 0x48, 0x0, 0x0, 0x50 },
    { 0x4E, 0x49, 0x0, 0x1, 0x51 },
    { 0x4F, 0x4A, 0x0, 0x2, 0x52 },
    { 0x50, 0x4B, 0x0, 0x3, 0x53 },
    { 0x51, 0x4C, 0x0, 0x4, 0x54 },
    { 0x52, 0x49, 0x1, 0x5, 0x55 },
    { 0x53, 0x4A, 0x1, 0x6, 0x56 },
    { 0x54, 0x4B, 0x1, 0x7, 0x57 },
    { 0x55, 0x4C, 0x1, 0x8, 0x58 },
    { 0x56, 0x49, 0x2, 0x9, 0x59 },
    { 0x57, 0x4A, 0x2, 0xA, 0x5A },
    { 0x58, 0x4B, 0x2, 0xB, 0x5B },
    { 0x59, 0x4C, 0x2, 0xC, 0x5C },
    { 0x5A, 0x49, 0x3, 0xD, 0x5D },
    { 0x5B, 0x4A, 0x3, 0xE, 0x5E },
    { 0x5C, 0x4B, 0x3, 0xF, 0x5F },
    { 0x5D, 0x4C, 0x3, 0x10, 0x60 },
    { 0x5E, 0x49, 0x4, 0x11, 0x61 },
    { 0x5F, 0x4A, 0x4, 0x12, 0x62 },
    { 0x60, 0x4B, 0x4, 0x13, 0x63 },
    { 0x61, 0x4C, 0x4, 0x14, 0x64 },
    { 0x63, 0x4E, 0x0, 0x15, 0x65 },
    { 0x64, 0x4D, 0x0, 0x16, 0x66 },
    { 0x65, 0x4F, 0x1, 0x17, 0x67 },
    { 0x66, 0x50, 0x2, 0x18, 0x68 },
    { 0x67, 0x51, 0x1, 0x19, 0x8000 },
    { 0x68, 0x51, 0x3, 0x1A, 0x8001 },
    { 0x69, 0x51, 0x4, 0x1B, 0x8002 },
    { 0x6A, 0x52, 0x3, 0x1C, 0xB2 },
    { 0x6B, 0x52, 0x4, 0x1D, 0xBE },
    { 0x6C, 0x53, 0x0, 0x1E, 0xBF },
    { 0x6D, 0x53, 0x1, 0x1F, 0xB2 },
    { 0x19, 0x58, 0x0, 0x20, 0x69 },
    { 0x7B, 0x59, 0x0, 0x21, 0x6A },
    { 0x7C, 0x5A, 0x0, 0x22, 0x6B },
    { 0x7D, 0x5B, 0x0, 0x23, 0x6C },
    { 0x7E, 0x5C, 0x0, 0x24, 0x6D },
    { 0x7F, 0x59, 0x1, 0x25, 0x6E },
    { 0x80, 0x5A, 0x1, 0x26, 0x6F },
    { 0x81, 0x5B, 0x1, 0x27, 0x70 },
    { 0x82, 0x5C, 0x1, 0x28, 0x71 },
    { 0x83, 0x59, 0x2, 0x29, 0x72 },
    { 0x84, 0x5A, 0x2, 0x2A, 0x73 },
    { 0x85, 0x5B, 0x2, 0x2B, 0x74 },
    { 0x86, 0x5C, 0x2, 0x2C, 0x75 },
    { 0x87, 0x59, 0x3, 0x2D, 0x76 },
    { 0x88, 0x5A, 0x3, 0x2E, 0x77 },
    { 0x89, 0x5B, 0x3, 0x2F, 0x78 },
    { 0x8A, 0x5C, 0x3, 0x30, 0x79 },
    { 0x8B, 0x59, 0x4, 0x31, 0x7A },
    { 0x8C, 0x5A, 0x4, 0x32, 0x7B },
    { 0x8D, 0x5B, 0x4, 0x33, 0x7C },
    { 0x8E, 0x5C, 0x4, 0x34, 0x7D },
    { 0x1A, 0x5D, 0x0, 0x35, 0x7E },
    { 0x1B, 0x5E, 0x0, 0x36, 0x7F },
    { 0x1C, 0x5F, 0x0, 0x37, 0x80 },
    { 0x1D, 0x60, 0x0, 0x38, 0x81 },
    { 0x1E, 0x61, 0x0, 0x39, 0x82 },
    { 0x1F, 0x62, 0x0, 0x3A, 0x83 },
    { 0x20, 0x63, 0x2, 0x3B, 0x84 },
    { 0x21, 0x64, 0x0, 0x3C, 0x85 },
    { 0x22, 0x65, 0x1, 0x3D, 0x86 },
    { 0x23, 0x66, 0x2, 0x3E, 0x87 },
    { 0x24, 0x67, 0x3, 0x3F, 0x88 },
    { 0x25, 0x68, 0x0, 0x40, 0x89 },
    { 0x26, 0x69, 0x2, 0x41, 0x8A },
    { 0x27, 0x6A, 0x1, 0x42, 0x8B },
    { 0x28, 0x6B, 0x3, 0x43, 0x8C },
    { 0x29, 0x6C, 0x0, 0x44, 0x8D },
    { 0x2A, 0x6D, 0x0, 0x45, 0x8E },
    { 0x2B, 0x6E, 0x1, 0x46, 0x8F },
    { 0x2C, 0x6F, 0x3, 0x47, 0x90 },
    { 0x2D, 0x70, 0x0, 0x48, 0x91 },
    { 0x2E, 0x71, 0x0, 0x49, 0x8007 },
    { 0x2F, 0x72, 0x3, 0x4A, 0x8008 },
    { 0x30, 0x73, 0x1, 0x4B, 0x8009 },
    { 0x31, 0x74, 0x1, 0x4C, 0x800A },
    { 0x32, 0x75, 0x0, 0x4D, 0x800B },
    { 0x33, 0x76, 0x1, 0x4E, 0x800C },
    { 0x34, 0x77, 0x0, 0x4F, 0x800D }
};

u32 sub_020923C0(u8 param0, u8 param1)
{
    switch (param1) {
    case 0:
        return Unk_020F51AC[param0].unk_00;
    case 1:
        return Unk_020F51AC[param0].unk_04;
    case 2:
        return Unk_020F51AC[param0].unk_06;
    case 3:
        return Unk_020F51AC[param0].unk_08;
    case 4:
        return Unk_020F51AC[param0].unk_0A;
    }

    return 0;
}

u32 sub_02092424(u8 *param0, u8 param1)
{
    if (Unk_020F51AC[param1].unk_0A & 0x8000) {
        return 146 + param0[Unk_020F51AC[param1].unk_0A & 0xff];
    }

    return Unk_020F51AC[param1].unk_0A;
}

u8 sub_02092444(u8 param0)
{
    if (Unk_020F51AC[param0].unk_0A & 0x8000) {
        return Unk_020F51AC[param0].unk_0A & 0xff;
    }

    return 0xff;
}

u16 sub_02092464(u32 param0)
{
    int v0;

    for (v0 = 0; v0 < NELEMS(Unk_020F51AC); v0++) {
        if (Unk_020F51AC[v0].unk_00 == param0) {
            return Unk_020F51AC[v0].unk_08;
        }
    }

    return 0xffff;
}
