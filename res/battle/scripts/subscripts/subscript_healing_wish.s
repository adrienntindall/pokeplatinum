#include "macros/btlcmd.inc"

    .data

_000:
    UpdateMonData OPCODE_SET, BTLSCR_ATTACKER, BATTLEMON_CUR_HP, 0
    UpdateVar OPCODE_SET, BTLVAR_HP_CALC_TEMP, 32767
    UpdateHealthBar BTLSCR_ATTACKER
    Call BATTLE_SUBSCRIPT_ATTACK_MESSAGE_AND_ANIMATION
    TryFaintMon BTLSCR_ATTACKER
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_MON_FAINTED
    Call BATTLE_SUBSCRIPT_FAINT_MON
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_BATTLE_CTX_STATUS_2, SYSCTL_PAYOUT_EXP
    Call BATTLE_SUBSCRIPT_GRANT_EXP

_026:
    TryReplaceFaintedMon BTLSCR_ATTACKER, TRUE, _087
    ShowParty 
    WaitMonSelection 
    SwitchAndUpdateMon BTLSCR_SWITCHED_MON
    PrintSendOutMessage BTLSCR_SWITCHED_MON
    Wait 
    PokemonSendOut BTLSCR_SWITCHED_MON
    WaitTime 72
    HealthbarSlideIn BTLSCR_SWITCHED_MON
    Wait 
    Call BATTLE_SUBSCRIPT_HAZARDS_CHECK
    CompareVarToValue OPCODE_FLAG_NOT, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_MON_FAINTED, _065
    Call BATTLE_SUBSCRIPT_FAINT_MON
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_BATTLE_CTX_STATUS_2, SYSCTL_PAYOUT_EXP
    Call BATTLE_SUBSCRIPT_GRANT_EXP
    TryReplaceFaintedMon BTLSCR_ATTACKER, TRUE, _087
    GoTo _026

_065:
    UpdateMonData OPCODE_SET, BTLSCR_ATTACKER, BATTLEMON_STATUS, MON_CONDITION_NONE
    SetHealthbarStatus BTLSCR_ATTACKER, BATTLE_ANIMATION_NONE
    UpdateMonDataFromVar OPCODE_GET, BTLSCR_ATTACKER, BATTLEMON_MAX_HP, BTLVAR_HP_CALC_TEMP
    UpdateVarFromVar OPCODE_SET, BTLVAR_MSG_BATTLER_TEMP, BTLVAR_ATTACKER
    // The healing wish came true!
    BufferMessage pl_msg_00000368_01005, TAG_NONE
    Call BATTLE_SUBSCRIPT_WISH_HEAL

_087:
    End 
