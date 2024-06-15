    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0039
    ScriptEntry _0098
    ScriptEntry _0155
    ScriptEntry _0174
    ScriptEntry _0193
    ScriptEntry _001A
    .short 0xFD13

_001A:
    ScrCmd_238 4, 0x4000
    GoToIfEq 0x4000, 0, _0033
    ClearFlag 0x210
    End

_0033:
    SetFlag 0x210
    End

_0039:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 141, _0083
    Message 0
    SetVar 0x8004, 0x1C1
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _008E
    ScrCmd_014 0x7FC
    SetFlag 141
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0083:
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_008E:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_0098:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_247 0x8000
    ScrCmd_0D6 0, 0x8000
    Message 3
    ScrCmd_1B9 0x800C, 0x8000
    GoToIfGe 0x800C, 0xFF, _0108
    GoToIfGe 0x800C, 200, _0113
    GoToIfGe 0x800C, 150, _011E
    GoToIfGe 0x800C, 100, _0129
    GoToIfGe 0x800C, 50, _0134
    GoToIfGe 0x800C, 1, _013F
    GoTo _014A
    End

_0108:
    Message 4
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0113:
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_011E:
    Message 6
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0129:
    Message 7
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0134:
    Message 8
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_013F:
    Message 9
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_014A:
    Message 10
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0155:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04B 0x5DC
    ScrCmd_04C 54, 0
    Message 11
    ScrCmd_04D
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0174:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04B 0x5DC
    ScrCmd_04C 0x1AB, 0
    Message 12
    ScrCmd_04D
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0193:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04B 0x5DC
    ScrCmd_04C 35, 0
    Message 13
    ScrCmd_04D
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
