    .include "macros/scrcmd.inc"

    .data

    .long _0026-.-4
    .long _0061-.-4
    .long _009D-.-4
    .long _060C-.-4
    .long _0632-.-4
    .long _061F-.-4
    .long _06B8-.-4
    .long _06CF-.-4
    .long _06E2-.-4
    .short 0xFD13

_0026:
    ScrCmd_020 0x106
    ScrCmd_01D 1, _004B
    ScrCmd_020 0x15E
    ScrCmd_01C 0, _0079
    ScrCmd_020 0x15E
    ScrCmd_01C 1, _008B
    ScrCmd_002
    ScrCmd_002

_004B:
    ScrCmd_186 5, 0x2D3, 0x301
    ScrCmd_189 5, 0
    ScrCmd_188 5, 14
    ScrCmd_01B

_0061:
    ScrCmd_020 0x15E
    ScrCmd_01C 0, _0079
    ScrCmd_020 0x15E
    ScrCmd_01C 1, _008B
    ScrCmd_002

_0079:
    ScrCmd_18A 5, 0x2C9, 0x2F8
    ScrCmd_18A 6, 0x2C9, 0x2F9
    ScrCmd_002

_008B:
    ScrCmd_18A 3, 0x2C9, 0x2F8
    ScrCmd_18A 4, 0x2C9, 0x2F9
    ScrCmd_002

_009D:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_020 0x106
    ScrCmd_01C 1, _013A
    ScrCmd_02C 0
    ScrCmd_068
    ScrCmd_05E 5, _0214
    ScrCmd_05F
    ScrCmd_02C 1
    ScrCmd_034
    ScrCmd_1BD 0x8004
    ScrCmd_011 0x8004, 1
    ScrCmd_01C 1, _00E6
    ScrCmd_011 0x8004, 0
    ScrCmd_01C 1, _00FE
    ScrCmd_016 _010E

_00E6:
    ScrCmd_05E 5, _021C
    ScrCmd_05E 0xFF, _01E0
    ScrCmd_05F
    ScrCmd_016 _0126

_00FE:
    ScrCmd_05E 5, _0228
    ScrCmd_05F
    ScrCmd_016 _0126

_010E:
    ScrCmd_05E 5, _0228
    ScrCmd_05E 0xFF, _01EC
    ScrCmd_05F
    ScrCmd_016 _0126

_0126:
    ScrCmd_187 5, 0x2D3, 1, 0x301, 0
    ScrCmd_01E 0x106
    ScrCmd_061
    ScrCmd_002

_013A:
    ScrCmd_1BD 0x8000
    ScrCmd_068
    ScrCmd_02C 2
    ScrCmd_034
    ScrCmd_0E5 0x34F, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _01D9
    ScrCmd_02C 3
    ScrCmd_034
    ScrCmd_1BD 0x8004
    ScrCmd_011 0x8004, 1
    ScrCmd_01C 1, _0185
    ScrCmd_011 0x8004, 0
    ScrCmd_01C 1, _019D
    ScrCmd_016 _01AD

_0185:
    ScrCmd_05E 5, _0230
    ScrCmd_05E 0xFF, _01F4
    ScrCmd_05F
    ScrCmd_016 _01C5

_019D:
    ScrCmd_05E 5, _023C
    ScrCmd_05F
    ScrCmd_016 _01C5

_01AD:
    ScrCmd_05E 5, _023C
    ScrCmd_05E 0xFF, _0208
    ScrCmd_05F
    ScrCmd_016 _01C5

_01C5:
    ScrCmd_065 5
    ScrCmd_01E 0x211
    ScrCmd_01F 0x156
    ScrCmd_016 _0248
    ScrCmd_002

_01D9:
    ScrCmd_0EB
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_01E0:
    .short 35, 1
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01EC:
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01F4:
    .short 63, 1
    .short 35, 1
    .short 63, 1
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0208:
    .short 63, 1
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0214:
    .short 75, 1
    .short 0xFE, 0x00

    .balign 4, 0
_021C:
    .short 19, 1
    .short 16, 11
    .short 0xFE, 0x00

    .balign 4, 0
_0228:
    .short 16, 10
    .short 0xFE, 0x00

    .balign 4, 0
_0230:
    .short 15, 1
    .short 8, 9
    .short 0xFE, 0x00

    .balign 4, 0
_023C:
    .short 12, 1
    .short 8, 9
    .short 0xFE, 0x00

_0248:
    ScrCmd_011 0x8000, 0
    ScrCmd_01D 1, _03EC
    ScrCmd_011 0x8000, 1
    ScrCmd_01D 1, _03F6
    ScrCmd_011 0x8000, 2
    ScrCmd_01D 1, _0400
    ScrCmd_011 0x8000, 3
    ScrCmd_01D 1, _040A
    ScrCmd_01F 0x1AD
    ScrCmd_189 0, 1
    ScrCmd_188 0, 15
    ScrCmd_064 0
    ScrCmd_05E 0, _0594
    ScrCmd_05F
    ScrCmd_02C 4
    ScrCmd_034
    ScrCmd_011 0x8000, 0
    ScrCmd_01D 1, _0444
    ScrCmd_011 0x8000, 1
    ScrCmd_01D 1, _044E
    ScrCmd_011 0x8000, 2
    ScrCmd_01D 1, _0458
    ScrCmd_011 0x8000, 3
    ScrCmd_01D 1, _0462
    ScrCmd_01F 0x1D5
    ScrCmd_189 10, 0
    ScrCmd_188 10, 14
    ScrCmd_064 10
    ScrCmd_014 0x7FA
    ScrCmd_011 0x8000, 0
    ScrCmd_01D 1, _046C
    ScrCmd_011 0x8000, 1
    ScrCmd_01D 1, _0480
    ScrCmd_011 0x8000, 2
    ScrCmd_01D 1, _0494
    ScrCmd_011 0x8000, 3
    ScrCmd_01D 1, _04A8
    ScrCmd_0CD 0
    ScrCmd_0CE 1
    ScrCmd_02C 5
    ScrCmd_05E 10, _0574
    ScrCmd_05F
    ScrCmd_02C 6
    ScrCmd_011 0x8000, 0
    ScrCmd_01D 1, _04BC
    ScrCmd_011 0x8000, 1
    ScrCmd_01D 1, _04C8
    ScrCmd_011 0x8000, 2
    ScrCmd_01D 1, _04D4
    ScrCmd_011 0x8000, 3
    ScrCmd_01D 1, _04E0
    ScrCmd_02C 7
    ScrCmd_034
    ScrCmd_05E 0, _05A8
    ScrCmd_05E 0xFF, _05E8
    ScrCmd_05E 10, _058C
    ScrCmd_05F
    ScrCmd_065 10
    ScrCmd_014 0x7FB
    ScrCmd_02C 8
    ScrCmd_034
    ScrCmd_011 0x8000, 0
    ScrCmd_01D 1, _0414
    ScrCmd_011 0x8000, 1
    ScrCmd_01D 1, _0420
    ScrCmd_011 0x8000, 2
    ScrCmd_01D 1, _042C
    ScrCmd_011 0x8000, 3
    ScrCmd_01D 1, _0438
    ScrCmd_02C 9
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _04EC
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _04F7
    ScrCmd_002

_03EC:
    ScrCmd_186 0, 0x2D3, 0x2F9
    ScrCmd_01B

_03F6:
    ScrCmd_186 0, 0x2D3, 0x2F7
    ScrCmd_01B

_0400:
    ScrCmd_186 0, 0x2D4, 0x2F8
    ScrCmd_01B

_040A:
    ScrCmd_186 0, 0x2D2, 0x2F8
    ScrCmd_01B

_0414:
    ScrCmd_05E 0, _05B4
    ScrCmd_05F
    ScrCmd_01B

_0420:
    ScrCmd_05E 0, _05B4
    ScrCmd_05F
    ScrCmd_01B

_042C:
    ScrCmd_05E 0, _05B4
    ScrCmd_05F
    ScrCmd_01B

_0438:
    ScrCmd_05E 0, _05B4
    ScrCmd_05F
    ScrCmd_01B

_0444:
    ScrCmd_186 10, 0x2D4, 0x30C
    ScrCmd_01B

_044E:
    ScrCmd_186 10, 0x2D4, 0x30A
    ScrCmd_01B

_0458:
    ScrCmd_186 10, 0x2D3, 0x30B
    ScrCmd_01B

_0462:
    ScrCmd_186 10, 0x2D3, 0x30B
    ScrCmd_01B

_046C:
    ScrCmd_05E 0xFF, _05D0
    ScrCmd_05E 10, _055C
    ScrCmd_05F
    ScrCmd_01B

_0480:
    ScrCmd_05E 0xFF, _05D0
    ScrCmd_05E 10, _055C
    ScrCmd_05F
    ScrCmd_01B

_0494:
    ScrCmd_05E 0xFF, _05DC
    ScrCmd_05E 10, _0568
    ScrCmd_05F
    ScrCmd_01B

_04A8:
    ScrCmd_05E 0xFF, _05D0
    ScrCmd_05E 10, _055C
    ScrCmd_05F
    ScrCmd_01B

_04BC:
    ScrCmd_05E 10, _057C
    ScrCmd_05F
    ScrCmd_01B

_04C8:
    ScrCmd_05E 10, _057C
    ScrCmd_05F
    ScrCmd_01B

_04D4:
    ScrCmd_05E 10, _0584
    ScrCmd_05F
    ScrCmd_01B

_04E0:
    ScrCmd_05E 10, _057C
    ScrCmd_05F
    ScrCmd_01B

_04EC:
    ScrCmd_02C 10
    ScrCmd_016 _0502
    ScrCmd_002

_04F7:
    ScrCmd_02C 11
    ScrCmd_016 _0502
    ScrCmd_002

_0502:
    ScrCmd_02C 12
    ScrCmd_028 0x8004, 0x1D0
    ScrCmd_028 0x8005, 1
    ScrCmd_014 0x7FC
    ScrCmd_02C 13
    ScrCmd_034
    ScrCmd_016 _0522
    ScrCmd_002

_0522:
    ScrCmd_05E 0, _05BC
    ScrCmd_05E 0xFF, _0600
    ScrCmd_05F
    ScrCmd_016 _053A

_053A:
    ScrCmd_065 0
    ScrCmd_028 0x4083, 2
    ScrCmd_01E 183
    ScrCmd_01E 0x1A9
    ScrCmd_01F 0x20F
    ScrCmd_028 0x407C, 6
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_055C:
    .short 16, 10
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0568:
    .short 16, 10
    .short 39, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0574:
    .short 36, 1
    .short 0xFE, 0x00

    .balign 4, 0
_057C:
    .short 38, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0584:
    .short 39, 1
    .short 0xFE, 0x00

    .balign 4, 0
_058C:
    .short 16, 8
    .short 0xFE, 0x00

    .balign 4, 0
_0594:
    .short 13, 4
    .short 32, 1
    .short 63, 2
    .short 13, 4
    .short 0xFE, 0x00

    .balign 4, 0
_05A8:
    .short 63, 1
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_05B4:
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_05BC:
    .short 12, 9
    .short 0xFE, 0x00

    .byte 63
    .byte 0
    .byte 1
    .byte 0
    .byte 35
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_05D0:
    .short 63, 4
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_05DC:
    .short 63, 4
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_05E8:
    .short 63, 2
    .short 32, 1
    .short 0xFE, 0x00

    .byte 63
    .byte 0
    .byte 3
    .byte 0
    .byte 32
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_0600:
    .short 63, 1
    .short 0, 1
    .short 0xFE, 0x00

_060C:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 14
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_061F:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 15
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0632:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_07E 0x1C3, 1, 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _065A
    ScrCmd_02C 18
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_065A:
    ScrCmd_02C 19
    ScrCmd_034
    ScrCmd_07C 0x1C3, 1, 0x800C
    ScrCmd_05E 8, _06A8
    ScrCmd_05F
    ScrCmd_168 22, 24, 11, 13, 77
    ScrCmd_16B 77
    ScrCmd_169 77
    ScrCmd_05E 8, _06B0
    ScrCmd_05F
    ScrCmd_065 8
    ScrCmd_16C 77
    ScrCmd_169 77
    ScrCmd_16A 77
    ScrCmd_01F 0x25E
    ScrCmd_01E 0x25D
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_06A8:
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_06B0:
    .short 12, 1
    .short 0xFE, 0x00

_06B8:
    ScrCmd_036 20, 2, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_06CF:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 17
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_06E2:
    ScrCmd_060
    ScrCmd_05E 9, _07A8
    ScrCmd_05F
    ScrCmd_069 0x8000, 0x8001
    ScrCmd_011 0x8001, 0x315
    ScrCmd_01D 1, _075D
    ScrCmd_011 0x8001, 0x316
    ScrCmd_01D 1, _0769
    ScrCmd_011 0x8001, 0x317
    ScrCmd_01D 1, _0775
    ScrCmd_05E 9, _07FC
    ScrCmd_05E 0xFF, _0804
    ScrCmd_05F
    ScrCmd_02C 16
    ScrCmd_034
    ScrCmd_011 0x8001, 0x315
    ScrCmd_01D 1, _0781
    ScrCmd_011 0x8001, 0x316
    ScrCmd_01D 1, _078D
    ScrCmd_011 0x8001, 0x317
    ScrCmd_01D 1, _0799
    ScrCmd_061
    ScrCmd_002

_075D:
    ScrCmd_05E 9, _07B4
    ScrCmd_05F
    ScrCmd_01B

_0769:
    ScrCmd_05E 9, _07C0
    ScrCmd_05F
    ScrCmd_01B

_0775:
    ScrCmd_05E 9, _07CC
    ScrCmd_05F
    ScrCmd_01B

_0781:
    ScrCmd_05E 9, _07D8
    ScrCmd_05F
    ScrCmd_01B

_078D:
    ScrCmd_05E 9, _07E4
    ScrCmd_05F
    ScrCmd_01B

_0799:
    ScrCmd_05E 9, _07F0
    ScrCmd_05F
    ScrCmd_01B

    .balign 4, 0
_07A8:
    .short 75, 1
    .short 65, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07B4:
    .short 15, 1
    .short 13, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07C0:
    .short 15, 1
    .short 13, 2
    .short 0xFE, 0x00

    .balign 4, 0
_07CC:
    .short 15, 1
    .short 13, 3
    .short 0xFE, 0x00

    .balign 4, 0
_07D8:
    .short 12, 1
    .short 1, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07E4:
    .short 12, 2
    .short 1, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07F0:
    .short 12, 3
    .short 1, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07FC:
    .short 14, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0804:
    .short 71, 1
    .short 14, 1
    .short 72, 1
    .short 0xFE, 0x00
