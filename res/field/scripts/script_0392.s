    .include "macros/scrcmd.inc"

    .data

    .long _0026-.-4
    .long _003D-.-4
    .long _012D-.-4
    .long _0148-.-4
    .long _0163-.-4
    .long _017E-.-4
    .long _0199-.-4
    .long _01B4-.-4
    .long _01CF-.-4
    .short 0xFD13

_0026:
    GoToIfLt 0x4069, 0x118, _0035
    End

_0035:
    SetVar 0x4069, 0
    End

_003D:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    GoToIfEq 0x4069, 0x122, _00ED
    GoToIfEq 0x4069, 0x118, _00F8
    GoToIfUnset 0x964, _010F
    ScrCmd_32B 0x800C
    GoToIfEq 0x800C, 0, _011A
    GoToIfEq 0x4069, 0x10E, _00AE
    GoToIfLt 0x4069, 0x104, _011A
    ScrCmd_04B 0x5DC
    ScrCmd_29F 1
    SetVar 0x4069, 0x10E
    ScrCmd_02C 1
    GoTo _0125
    End

_00AE:
    ScrCmd_04C 0x17B, 0
    ScrCmd_02C 2
    ScrCmd_04D
    ScrCmd_034
    ScrCmd_2BD 0x17B, 30
    ScrCmd_0EC 0x800C
    GoToIfEq 0x800C, 0, _0109
    ScrCmd_2BC 0x800C
    GoToIfEq 0x800C, 1, _00F8
    SetVar 0x4069, 0x122
    ScrCmd_061
    End

_00ED:
    ScrCmd_02C 3
    GoTo _0125
    End

_00F8:
    SetVar 0x4069, 0x118
    ScrCmd_02C 3
    GoTo _0125
    End

_0109:
    ScrCmd_0EB
    ScrCmd_061
    End

_010F:
    ScrCmd_02C 4
    GoTo _0125
    End

_011A:
    ScrCmd_02C 0
    GoTo _0125
    End

_0125:
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End

_012D:
    SetVar 0x4001, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_0148:
    SetVar 0x4002, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_0163:
    SetVar 0x4003, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_017E:
    SetVar 0x4004, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_0199:
    SetVar 0x4005, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_01B4:
    SetVar 0x4006, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_01CF:
    SetVar 0x4007, 1
    GoToIfGe 0x4069, 0x104, _020D
    GoTo _01EA
    End

_01EA:
    ScrCmd_060
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_32C 0x4069, 0x24C, 0x8004, 0x8005
    GoToIfGe 0x4069, 0x104, _020F
    ScrCmd_061
    End

_020D:
    End

_020F:
    GoToIfUnset 0x964, _020D
    ScrCmd_04B 0x5DC
    ScrCmd_29F 1
    SetVar 0x4069, 0x10E
    ScrCmd_02C 1
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End

    .byte 0
