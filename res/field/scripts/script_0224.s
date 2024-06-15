    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0012
    ScriptEntry _0036
    ScriptEntry _01A0
    ScriptEntry _0023
    .short 0xFD13

_0012:
    PlayFanfare 0x5DC
    LockAll
    Message 6
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0023:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 7
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0036:
    LockAll
    ScrCmd_069 0x8004, 0x8005
    SetVar 0x40A9, 2
    ScrCmd_186 5, 20, 25
    ScrCmd_188 5, 16
    ScrCmd_189 5, 2
    ClearFlag 0x29F
    ScrCmd_064 5
    ApplyMovement 5, _0148
    WaitMovement
    ScrCmd_014 0x807
    CallIfEq 0x8005, 24, _0109
    CallIfEq 0x8005, 25, _011D
    CallIfEq 0x8005, 26, _0131
    Message 0
    ApplyMovement 5, _0184
    WaitMovement
    Message 1
    ApplyMovement 5, _018C
    WaitMovement
    Message 2
    SetVar 0x8004, 68
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _00F2
    ScrCmd_014 0x7FC
    Call _00E5
    ScrCmd_014 0x808
    ReleaseAll
    End

_00E5:
    SetFlag 0x160
    Message 3
    WaitButtonPress
    CloseMessage
    Return

_00F2:
    Call _0100
    ScrCmd_014 0x808
    ReleaseAll
    End

_0100:
    Message 4
    WaitButtonPress
    CloseMessage
    Return

_0109:
    ApplyMovement 5, _015C
    ApplyMovement 0xFF, _0194
    WaitMovement
    Return

_011D:
    ApplyMovement 5, _016C
    ApplyMovement 0xFF, _0194
    WaitMovement
    Return

_0131:
    ApplyMovement 5, _0174
    ApplyMovement 0xFF, _0194
    WaitMovement
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
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfUnset 0x160, _01BE
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_01BE:
    Message 5
    SetVar 0x8004, 68
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _01F0
    ScrCmd_014 0x7FC
    Call _00E5
    ReleaseAll
    End

_01F0:
    Call _0100
    ReleaseAll
    End

    .byte 0
    .byte 0
