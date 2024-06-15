    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000A
    ScriptEntry _011C
    .short 0xFD13

_000A:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 151, _0109
    GoToIfSet 181, _0037
    SetFlag 181
    Message 0
    GoTo _0042
    End

_0037:
    Message 1
    GoTo _0042
    End

_0042:
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 0, _005B
    GoTo _00FE
    End

_005B:
    ScrCmd_177 0x800C
    GoToIfEq 0x800C, 6, _00F3
    Message 2
    ScrCmd_04E 0x486
    ScrCmd_0CD 0
    Message 3
    ScrCmd_04F
    ScrCmd_096 137, 25, 0, 0x800C
    SetFlag 151
    Message 4
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 0, _00AC
    GoToIfEq 0x800C, 1, _00ED
    End

_00AC:
    CloseMessage
    ScrCmd_177 0x4000
    SubVar 0x4000, 1
    FadeScreen 6, 1, 0, 0
    WaitFadeScreen
    ScrCmd_0BB 0x4000, 0x800C
    CallIfNe 0x800C, 1, _00E7
    FadeScreen 6, 1, 1, 0
    WaitFadeScreen
    ReleaseAll
    End

_00E7:
    ScrCmd_1E5 49
    Return

_00ED:
    CloseMessage
    ReleaseAll
    End

_00F3:
    Message 5
    GoTo _0114
    End

_00FE:
    Message 6
    GoTo _0114
    End

_0109:
    Message 7
    GoTo _0114
    End

_0114:
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_011C:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 8
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
