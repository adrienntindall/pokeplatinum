#include "macros/btlcmd.inc"

    .data

_000:
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_SLEEP, _009
    Call BATTLE_SUBSCRIPT_FALL_ASLEEP
    GoTo _041

_009:
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_POISON, _019
    Call BATTLE_SUBSCRIPT_POISON
    GoTo _041

_019:
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_BURN, _029
    Call BATTLE_SUBSCRIPT_BURN
    GoTo _041

_029:
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_PARALYSIS, _039
    Call BATTLE_SUBSCRIPT_PARALYZE
    GoTo _041

_039:
    Call BATTLE_SUBSCRIPT_BADLY_POISON

_041:
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_DEFENDER, BATTLEMON_STATUS, MON_CONDITION_ANY, _055
    SetHealthbarStatus BTLSCR_ATTACKER, BATTLE_ANIMATION_NONE
    UpdateMonData OPCODE_SET, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_NONE

_055:
    End 
