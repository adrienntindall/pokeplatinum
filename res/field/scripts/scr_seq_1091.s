    .include "macros/scrcmd.inc"

    .data

    .long _001C-.-4
    .long _0056-.-4
    .long _00A1-.-4
    .long _00B4-.-4
    .long _001A-.-4
    .long _00C5-.-4
    .short 0xFD13

_001A:
    ScrCmd_002

_001C:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 0
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _0043
    ScrCmd_02C 1
    ScrCmd_016 _004E
    ScrCmd_002

_0043:
    ScrCmd_02C 2
    ScrCmd_016 _004E
    ScrCmd_002

_004E:
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0056:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_020 0x964
    ScrCmd_01C 1, _007F
    ScrCmd_020 0x9B8
    ScrCmd_01C 1, _008E
    ScrCmd_02C 3
    ScrCmd_016 _0099
    ScrCmd_002

_007F:
    ScrCmd_01E 0x145
    ScrCmd_02C 5
    ScrCmd_016 _0099
    ScrCmd_002

_008E:
    ScrCmd_02C 4
    ScrCmd_016 _0099
    ScrCmd_002

_0099:
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00A1:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 9
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00B4:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_02C 10
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00C5:
    ScrCmd_0CD 0
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 11
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

    .byte 0
