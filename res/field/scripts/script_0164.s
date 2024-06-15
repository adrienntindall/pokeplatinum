    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _001A
    ScriptEntry _0096
    ScriptEntry _00A9
    ScriptEntry _0175
    ScriptEntry _0018
    ScriptEntry _01D4

_0018:
    End

_001A:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_247 0x8000
    ScrCmd_230 0x800C, 0x8000, 24
    GoToIfEq 0x800C, 1, _0086
    ScrCmd_0D0 0, 0x8000
    Message 0
    ScrCmd_233 0x800C, 0x8000
    GoToIfLt 0x800C, 0x1FE, _007B
    Message 1
    ScrCmd_231 0x8000, 24
    ScrCmd_04E 0x483
    ScrCmd_0CD 1
    Message 2
    ScrCmd_04F
    ScrCmd_0D0 0, 0x8000
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_007B:
    Message 4
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0086:
    ScrCmd_0D0 0, 0x8000
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0096:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 6
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00A9:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_07E 0x1B2, 1, 0x800C
    GoToIfEq 0x800C, 0, _00D9
    Message 7
    ScrCmd_014 0x7E3
    ScrCmd_035
    Call _00E4
    ReleaseAll
    End

_00D9:
    Message 8
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00E4:
    ScrCmd_234 0x800C
    SetVar 0x8008, 0x800C
    GoToIfEq 0x8008, 0, _016F
    GoToIfEq 0x8008, 1, _014B
    GoToIfEq 0x8008, 2, _0151
    GoToIfEq 0x8008, 3, _0157
    GoToIfEq 0x8008, 4, _015D
    GoToIfEq 0x8008, 5, _0163
    GoToIfEq 0x8008, 6, _0169
    End

_014B:
    ScrCmd_14A 0
    Return

_0151:
    ScrCmd_14A 1
    Return

_0157:
    ScrCmd_14A 2
    Return

_015D:
    ScrCmd_14A 3
    Return

_0163:
    ScrCmd_14A 4
    Return

_0169:
    ScrCmd_14A 5
    Return

_016F:
    ScrCmd_14A 6
    Return

_0175:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 9
    ScrCmd_234 0x4000
    GoToIfEq 0x4000, 0, _01BE
    GoToIfEq 0x4000, 1, _01BE
    GoToIfEq 0x4000, 2, _01BE
    GoToIfEq 0x4000, 3, _01BE
    GoTo _01C9

_01BE:
    Message 10
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_01C9:
    Message 11
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_01D4:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 12
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
