    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0012
    ScriptEntry _0014
    ScriptEntry _004C
    ScriptEntry _005F
    .short 0xFD13

_0012:
    End

_0014:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    CloseMessage
    FadeScreen 6, 1, 0, 0
    WaitFadeScreen
    ScrCmd_04E 0x48E
    ScrCmd_04F
    ScrCmd_14E
    FadeScreen 6, 1, 1, 0
    WaitFadeScreen
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_004C:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_005F:
    PlayFanfare 0x5DC
    LockAll
    GoToIfSet 253, _0081
    SetFlag 253
    FacePlayer
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0081:
    ApplyMovement 2, _009C
    WaitMovement
    Message 4
    FacePlayer
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
_009C:
    MoveAction_003
    EndMovement
