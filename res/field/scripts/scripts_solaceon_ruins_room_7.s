#include "macros/scrcmd.inc"
#include "res/text/bank/solaceon_ruins_room_7.h"

    .data

    ScriptEntry _0006
    .short 0xFD13

_0006:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    ScrCmd_26D 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End
