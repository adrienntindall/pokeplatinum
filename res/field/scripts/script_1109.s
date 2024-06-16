    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _00C0
    ScriptEntry _00D6
    ScriptEntry _0269
    ScriptEntry _027C
    ScriptEntry _02BA
    ScriptEntry _02D9
    ScriptEntry _003F
    ScriptEntry _0022
    .short 0xFD13

_0022:
    GoToIfSet 250, _002F
    End

_002F:
    ScrCmd_186 0, 16, 14
    ScrCmd_189 0, 1
    End

_003F:
    LockAll
    WaitTime 20, 0x800C
    ScrCmd_22F 0x8004
    GoToIfLt 0x8004, 10, _0078
    SetVar 0x40A7, 1
    SetFlag 250
    ScrCmd_0CD 0
    Message 1
    CloseMessage
    ApplyMovement 0, _00AC
    WaitMovement
    ReleaseAll
    End

_0078:
    Message 0
    CloseMessage
    WaitTime 20, 0x800C
    FadeScreen 6, 1, 0, 0
    WaitFadeScreen
    ScrCmd_0BE 0x1C9, 0, 0x338, 0x1C6, 1
    FadeScreen 6, 1, 1, 0
    WaitFadeScreen
    ReleaseAll
    End

    .balign 4, 0
_00AC:
    MoveAction_002
    MoveAction_047
    MoveAction_00F
    MoveAction_048
    EndMovement

_00C0:
    ScrCmd_0CD 0
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00D6:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_247 0x8000
    ScrCmd_0CD 0
    ScrCmd_0D0 2, 0x8000
    ScrCmd_230 0x800C, 0x8000, 68
    GoToIfEq 0x800C, 1, _0244
    ScrCmd_230 0x800C, 0x8000, 67
    GoToIfEq 0x800C, 1, _01E7
    ScrCmd_230 0x800C, 0x8000, 66
    GoToIfEq 0x800C, 1, _018A
    GoTo _012F

_012F:
    ScrCmd_072 20, 2
    Message 3
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 1, _025C
    ScrCmd_071 0x800C, 0x2710
    GoToIfEq 0x800C, 0, _024F
    ScrCmd_334 35, 0x2710
    ScrCmd_070 0x2710
    ScrCmd_074
    PlayFanfare 0x644
    ScrCmd_04B 0x644
    Message 7
    Message 8
    WaitButtonPress
    ScrCmd_231 0x8000, 66
    CloseMessage
    ScrCmd_073
    ReleaseAll
    End

_018A:
    ScrCmd_072 20, 2
    Message 4
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 1, _025C
    ScrCmd_071 0x800C, 0x186A0
    GoToIfEq 0x800C, 0, _024F
    ScrCmd_335 35, 0x186A0
    ScrCmd_070 0x186A0
    ScrCmd_074
    PlayFanfare 0x644
    ScrCmd_04B 0x644
    Message 9
    Message 10
    WaitButtonPress
    ScrCmd_231 0x8000, 67
    CloseMessage
    ScrCmd_073
    ReleaseAll
    End

_01E7:
    ScrCmd_072 20, 2
    Message 5
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 1, _025C
    ScrCmd_071 0x800C, 0xF423F
    GoToIfEq 0x800C, 0, _024F
    ScrCmd_335 35, 0xF423F
    ScrCmd_070 0xF423F
    ScrCmd_074
    PlayFanfare 0x644
    ScrCmd_04B 0x644
    Message 11
    Message 12
    WaitButtonPress
    ScrCmd_231 0x8000, 68
    CloseMessage
    ScrCmd_073
    ReleaseAll
    End

_0244:
    Message 6
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_024F:
    Message 13
    WaitButtonPress
    CloseMessage
    ScrCmd_073
    ReleaseAll
    End

_025C:
    Message 14
    WaitButtonPress
    CloseMessage
    ScrCmd_073
    ReleaseAll
    End

_0269:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 15
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_027C:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_14D 0x800C
    GoToIfEq 0x800C, 0, _02A4
    GoToIfEq 0x800C, 1, _02AF
    End

_02A4:
    Message 16
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_02AF:
    Message 17
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_02BA:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04B 0x5DC
    ScrCmd_04C 0x12C, 0
    Message 18
    ScrCmd_04D
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_02D9:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04B 0x5DC
    ScrCmd_04C 54, 0
    Message 19
    ScrCmd_04D
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End
