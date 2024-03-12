    .include "macros/scrcmd.inc"

    .data

    .long _000A-.-4
    .long _001D-.-4
    .short 0xFD13

_000A:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 0
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_001D:
    ScrCmd_060
    ScrCmd_05E 1, _0264
    ScrCmd_05F
    ScrCmd_014 0x7FA
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8005, 5
    ScrCmd_01D 1, _014E
    ScrCmd_011 0x8005, 6
    ScrCmd_01D 1, _015A
    ScrCmd_011 0x8005, 7
    ScrCmd_01D 1, _0166
    ScrCmd_011 0x8005, 8
    ScrCmd_01D 1, _0172
    ScrCmd_011 0x8005, 9
    ScrCmd_01D 1, _017E
    ScrCmd_0CE 0
    ScrCmd_0CD 1
    ScrCmd_02C 1
    ScrCmd_034
    ScrCmd_0DE 0x800C
    ScrCmd_011 0x800C, 0x183
    ScrCmd_01C 1, _00B3
    ScrCmd_011 0x800C, 0x186
    ScrCmd_01C 1, _00C1
    ScrCmd_016 _00A5
    ScrCmd_002

_00A5:
    ScrCmd_0E5 0x1D6, 0
    ScrCmd_016 _00CF
    ScrCmd_002

_00B3:
    ScrCmd_0E5 0x1D7, 0
    ScrCmd_016 _00CF
    ScrCmd_002

_00C1:
    ScrCmd_0E5 0x1D8, 0
    ScrCmd_016 _00CF
    ScrCmd_002

_00CF:
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0148
    ScrCmd_0CE 0
    ScrCmd_0CD 1
    ScrCmd_02C 2
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8005, 5
    ScrCmd_01D 1, _018A
    ScrCmd_011 0x8005, 6
    ScrCmd_01D 1, _0196
    ScrCmd_011 0x8005, 7
    ScrCmd_01D 1, _01A2
    ScrCmd_011 0x8005, 8
    ScrCmd_01D 1, _01AE
    ScrCmd_011 0x8005, 9
    ScrCmd_01D 1, _01BA
    ScrCmd_049 0x603
    ScrCmd_065 1
    ScrCmd_04B 0x603
    ScrCmd_028 0x407B, 2
    ScrCmd_061
    ScrCmd_002

_0148:
    ScrCmd_0EB
    ScrCmd_061
    ScrCmd_002

_014E:
    ScrCmd_05E 1, _01D4
    ScrCmd_05F
    ScrCmd_01B

_015A:
    ScrCmd_05E 1, _01E4
    ScrCmd_05F
    ScrCmd_01B

_0166:
    ScrCmd_05E 1, _01F4
    ScrCmd_05F
    ScrCmd_01B

_0172:
    ScrCmd_05E 1, _01FC
    ScrCmd_05F
    ScrCmd_01B

_017E:
    ScrCmd_05E 1, _020C
    ScrCmd_05F
    ScrCmd_01B

_018A:
    ScrCmd_05E 1, _021C
    ScrCmd_05F
    ScrCmd_01B

_0196:
    ScrCmd_05E 1, _022C
    ScrCmd_05F
    ScrCmd_01B

_01A2:
    ScrCmd_05E 1, _023C
    ScrCmd_05F
    ScrCmd_01B

_01AE:
    ScrCmd_05E 1, _0244
    ScrCmd_05F
    ScrCmd_01B

_01BA:
    ScrCmd_05E 1, _0254
    ScrCmd_05F
    ScrCmd_01B

    .byte 0
    .byte 0
    .byte 18
    .byte 0
    .byte 4
    .byte 0
    .byte 75
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_01D4:
    .short 18, 2
    .short 16, 2
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01E4:
    .short 18, 2
    .short 16, 1
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01F4:
    .short 18, 2
    .short 0xFE, 0x00

    .balign 4, 0
_01FC:
    .short 18, 2
    .short 17, 1
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_020C:
    .short 18, 2
    .short 17, 2
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_021C:
    .short 19, 2
    .short 17, 2
    .short 19, 2
    .short 0xFE, 0x00

    .balign 4, 0
_022C:
    .short 19, 2
    .short 17, 1
    .short 19, 2
    .short 0xFE, 0x00

    .balign 4, 0
_023C:
    .short 19, 4
    .short 0xFE, 0x00

    .balign 4, 0
_0244:
    .short 19, 2
    .short 16, 1
    .short 19, 2
    .short 0xFE, 0x00

    .balign 4, 0
_0254:
    .short 19, 2
    .short 16, 2
    .short 19, 2
    .short 0xFE, 0x00

    .balign 4, 0
_0264:
    .short 63, 1
    .short 75, 1
    .short 63, 1
    .short 0xFE, 0x00
