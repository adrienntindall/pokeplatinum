#include "macros/scrcmd.inc"
#include "res/text/bank/old_chateau_side_rooms.h"

    .data

    ScriptEntry _0006
    ScriptEntryEnd

_0006:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    Message 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
