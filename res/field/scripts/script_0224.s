    .include "macros/scrcmd.inc"

    .data

    .long _0012-.-4
    .long _0036-.-4
    .long _01A0-.-4
    .long _0023-.-4
    .short 0xFD13

_0012:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_02C 6
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End

_0023:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 7
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End

_0036:
    ScrCmd_060
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_028 0x40A9, 2
    ScrCmd_186 5, 20, 25
    ScrCmd_188 5, 16
    ScrCmd_189 5, 2
    ClearFlag 0x29F
    ScrCmd_064 5
    ScrCmd_05E 5, _0148
    ScrCmd_05F
    ScrCmd_014 0x807
    CompareVarToValue 0x8005, 24
    CallIf 1, _0109
    CompareVarToValue 0x8005, 25
    CallIf 1, _011D
    CompareVarToValue 0x8005, 26
    CallIf 1, _0131
    ScrCmd_02C 0
    ScrCmd_05E 5, _0184
    ScrCmd_05F
    ScrCmd_02C 1
    ScrCmd_05E 5, _018C
    ScrCmd_05F
    ScrCmd_02C 2
    ScrCmd_028 0x8004, 68
    ScrCmd_028 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    CompareVarToValue 0x800C, 0
    GoToIf 1, _00F2
    ScrCmd_014 0x7FC
    Call _00E5
    ScrCmd_014 0x808
    ScrCmd_061
    End

_00E5:
    SetFlag 0x160
    ScrCmd_02C 3
    ScrCmd_031
    ScrCmd_034
    Return

_00F2:
    Call _0100
    ScrCmd_014 0x808
    ScrCmd_061
    End

_0100:
    ScrCmd_02C 4
    ScrCmd_031
    ScrCmd_034
    Return

_0109:
    ScrCmd_05E 5, _015C
    ScrCmd_05E 0xFF, _0194
    ScrCmd_05F
    Return

_011D:
    ScrCmd_05E 5, _016C
    ScrCmd_05E 0xFF, _0194
    ScrCmd_05F
    Return

_0131:
    ScrCmd_05E 5, _0174
    ScrCmd_05E 0xFF, _0194
    ScrCmd_05F
    Return

    .balign 4, 0
_0148:
    MoveAction_012 4
    MoveAction_03F
    MoveAction_04B
    MoveAction_03F
    EndMovement

    .balign 4, 0
_015C:
    MoveAction_012 4
    MoveAction_010
    MoveAction_026
    EndMovement

    .balign 4, 0
_016C:
    MoveAction_012 4
    EndMovement

    .balign 4, 0
_0174:
    MoveAction_012 4
    MoveAction_011
    MoveAction_026
    EndMovement

    .balign 4, 0
_0184:
    MoveAction_021
    EndMovement

    .balign 4, 0
_018C:
    MoveAction_022
    EndMovement

    .balign 4, 0
_0194:
    MoveAction_03F 4
    MoveAction_023
    EndMovement

_01A0:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    CheckFlag 0x160
    GoToIf 0, _01BE
    ScrCmd_02C 3
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End

_01BE:
    ScrCmd_02C 5
    ScrCmd_028 0x8004, 68
    ScrCmd_028 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    CompareVarToValue 0x800C, 0
    GoToIf 1, _01F0
    ScrCmd_014 0x7FC
    Call _00E5
    ScrCmd_061
    End

_01F0:
    Call _0100
    ScrCmd_061
    End

    .byte 0
    .byte 0
