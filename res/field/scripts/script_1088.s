    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0012
    ScriptEntry _001E
    ScriptEntry _0031
    ScriptEntry _0044
    .short 0xFD13

_0012:
    SetVar 0x8007, 0
    ScrCmd_014 0x7D2
    End

_001E:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0031:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0044:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 0xAA1, _00C0
    Message 2
    ScrCmd_247 0x8000
    ScrCmd_1B9 0x800C, 0x8000
    GoToIfGe 0x800C, 150, _0084
    GoToIfGe 0x800C, 50, _00CB
    GoTo _00D6

_0084:
    Message 3
    SetVar 0x8004, 3
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _00B6
    ScrCmd_014 0x7FC
    SetFlag 0xAA1
    GoTo _00C0

_00B6:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_00C0:
    Message 4
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00CB:
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00D6:
    Message 6
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
    .byte 0
