    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000E
    ScriptEntry _0021
    ScriptEntry _0034
    .short 0xFD13

_000E:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0021:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0034:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_07E 0x1B8, 1, 0x800C
    GoToIfEq 0x800C, 1, _005C
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_005C:
    Message 3
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 0, _007F
    GoToIfEq 0x800C, 1, _00B3
    End

_007F:
    ScrCmd_0CD 0
    Message 4
    WaitButtonPress
    ScrCmd_04B 0x5DC
    PlayFanfare 0x608
    ApplyMovement 6, _00BC
    ApplyMovement 7, _00C4
    WaitMovement
    SetFlag 0x227
    ScrCmd_065 6
    ScrCmd_065 7
    CloseMessage
    ReleaseAll
    End

_00B3:
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
_00BC:
    MoveAction_012
    EndMovement

    .balign 4, 0
_00C4:
    MoveAction_013
    EndMovement
