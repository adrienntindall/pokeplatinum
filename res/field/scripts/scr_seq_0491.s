    .include "macros/scrcmd.inc"

    .data

    .long _007B-.-4
    .long _0092-.-4
    .long _0012-.-4
    .long _0047-.-4
    .short 0xFD13

_0012:
    ScrCmd_011 0x406B, 0x122
    ScrCmd_01D 5, _003F
    ScrCmd_32B 0x4001
    ScrCmd_011 0x4001, 0
    ScrCmd_01C 1, _0067
    ScrCmd_011 0x4001, 1
    ScrCmd_01C 1, _0071
    ScrCmd_002

_003F:
    ScrCmd_028 0x406B, 0
    ScrCmd_01B

_0047:
    ScrCmd_32B 0x4001
    ScrCmd_011 0x4001, 0
    ScrCmd_01C 1, _0067
    ScrCmd_011 0x4001, 1
    ScrCmd_01C 1, _0071
    ScrCmd_002

_0067:
    ScrCmd_18A 5, 0x30F, 0x153
    ScrCmd_002

_0071:
    ScrCmd_18A 4, 0x30F, 0x153
    ScrCmd_002

_007B:
    ScrCmd_036 0, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_0092:
    ScrCmd_036 1, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

    .byte 0
    .byte 0
    .byte 0
