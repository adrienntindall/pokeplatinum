    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000E
    ScriptEntry _001A
    ScriptEntry _002D
    .short 0xFD13

_000E:
    SetVar 0x8007, 0
    ScrCmd_014 0x7D2
    End

_001A:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_002D:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End
