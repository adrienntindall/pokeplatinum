    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0012
    ScriptEntry _0025
    ScriptEntry _0081
    ScriptEntry _0083
    .short 0xFD13

_0012:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0025:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 0x10A, _006C
    Message 1
    SetVar 0x8004, 3
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _0077
    ScrCmd_014 0x7FC
    SetFlag 0x10A
    GoTo _006C
    End

_006C:
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0077:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_0081:
    End

_0083:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
