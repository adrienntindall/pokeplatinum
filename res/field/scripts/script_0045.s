    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000A
    ScriptEntry _0066
    .short 0xFD13

_000A:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 201, _0051
    Message 0
    SetVar 0x8004, 0x177
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _005C
    ScrCmd_014 0x7FC
    SetFlag 201
    GoTo _0051
    End

_0051:
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_005C:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_0066:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
    .byte 0
