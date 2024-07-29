#ifndef POKEPLATINUM_CONSTANTS_BATTLE_CONDITION_H
#define POKEPLATINUM_CONSTANTS_BATTLE_CONDITION_H

#include "constants/overworld_weather.h"

#define MON_CONDITION_NONE            0
#define MON_CONDITION_SLEEP_0         (1 << 0)
#define MON_CONDITION_SLEEP_1         (1 << 1)
#define MON_CONDITION_SLEEP_2         (1 << 2)
#define MON_CONDITION_POISON          (1 << 3)
#define MON_CONDITION_BURN            (1 << 4)
#define MON_CONDITION_FREEZE          (1 << 5)
#define MON_CONDITION_PARALYSIS       (1 << 6)
#define MON_CONDITION_TOXIC           (1 << 7)
#define MON_CONDITION_TOXIC_COUNTER_0 (1 << 8)
#define MON_CONDITION_TOXIC_COUNTER_1 (1 << 9)
#define MON_CONDITION_TOXIC_COUNTER_2 (1 << 10)
#define MON_CONDITION_TOXIC_COUNTER_3 (1 << 11)

#define MON_CONDITION_TOXIC_COUNT_INC MON_CONDITION_TOXIC_COUNTER_0

#define MON_CONDITION_SLEEP         (MON_CONDITION_SLEEP_0 | MON_CONDITION_SLEEP_1 | MON_CONDITION_SLEEP_2)
#define MON_CONDITION_TOXIC_COUNTER (MON_CONDITION_TOXIC_COUNTER_0 | MON_CONDITION_TOXIC_COUNTER_1 | MON_CONDITION_TOXIC_COUNTER_2 | MON_CONDITION_TOXIC_COUNTER_3)
#define MON_CONDITION_ANY_POISON    (MON_CONDITION_POISON | MON_CONDITION_TOXIC | MON_CONDITION_TOXIC_COUNTER)
#define MON_CONDITION_ANY           (MON_CONDITION_SLEEP | MON_CONDITION_POISON | MON_CONDITION_BURN | MON_CONDITION_FREEZE | MON_CONDITION_PARALYSIS | MON_CONDITION_TOXIC)

#define MON_CONDITION_NOT_SLEEP       ~MON_CONDITION_SLEEP
#define MON_CONDITION_CAN_SYNCHRONIZE (MON_CONDITION_POISON | MON_CONDITION_BURN | MON_CONDITION_PARALYSIS)
#define MON_CONDITION_FACADE_BOOST    (MON_CONDITION_TOXIC | MON_CONDITION_POISON | MON_CONDITION_BURN | MON_CONDITION_PARALYSIS)

#define VOLATILE_CONDITION_NONE        0
#define VOLATILE_CONDITION_CONFUSION_0 (1 << 0)
#define VOLATILE_CONDITION_CONFUSION_1 (1 << 1)
#define VOLATILE_CONDITION_CONFUSION_2 (1 << 2)
#define VOLATILE_CONDITION_FLINCH      (1 << 3)
#define VOLATILE_CONDITION_UPROAR_0    (1 << 4)
#define VOLATILE_CONDITION_UPROAR_1    (1 << 5)
#define VOLATILE_CONDITION_UPROAR_2    (1 << 6)
// unused flag: 1 << 7
#define VOLATILE_CONDITION_BIDE_0       (1 << 8)
#define VOLATILE_CONDITION_BIDE_1       (1 << 9)
#define VOLATILE_CONDITION_THRASH_0     (1 << 10)
#define VOLATILE_CONDITION_THRASH_1     (1 << 11)
#define VOLATILE_CONDITION_MOVE_LOCKED  (1 << 12)
#define VOLATILE_CONDITION_BIND_0       (1 << 13)
#define VOLATILE_CONDITION_BIND_1       (1 << 14)
#define VOLATILE_CONDITION_BIND_2       (1 << 15)
#define VOLATILE_CONDITION_ATTRACT_0    (1 << 16)
#define VOLATILE_CONDITION_ATTRACT_1    (1 << 17)
#define VOLATILE_CONDITION_ATTRACT_2    (1 << 18)
#define VOLATILE_CONDITION_ATTRACT_3    (1 << 19)
#define VOLATILE_CONDITION_FOCUS_ENERGY (1 << 20)
#define VOLATILE_CONDITION_TRANSFORM    (1 << 21)
#define VOLATILE_CONDITION_RECHARGING   (1 << 22)
#define VOLATILE_CONDITION_RAGE         (1 << 23)
#define VOLATILE_CONDITION_SUBSTITUTE   (1 << 24)
#define VOLATILE_CONDITION_DESTINY_BOND (1 << 25)
#define VOLATILE_CONDITION_MEAN_LOOK    (1 << 26)
#define VOLATILE_CONDITION_NIGHTMARE    (1 << 27)
#define VOLATILE_CONDITION_CURSE        (1 << 28)
#define VOLATILE_CONDITION_FORESIGHT    (1 << 29)
#define VOLATILE_CONDITION_DEFENSE_CURL (1 << 30)
#define VOLATILE_CONDITION_TORMENT      (1 << 31)

#define VOLATILE_CONDITION_CONFUSION (VOLATILE_CONDITION_CONFUSION_0 | VOLATILE_CONDITION_CONFUSION_1 | VOLATILE_CONDITION_CONFUSION_2)
#define VOLATILE_CONDITION_UPROAR    (VOLATILE_CONDITION_UPROAR_0 | VOLATILE_CONDITION_UPROAR_1 | VOLATILE_CONDITION_UPROAR_2)
#define VOLATILE_CONDITION_BIDE      (VOLATILE_CONDITION_BIDE_0 | VOLATILE_CONDITION_BIDE_1)
#define VOLATILE_CONDITION_THRASH    (VOLATILE_CONDITION_THRASH_0 | VOLATILE_CONDITION_THRASH_1)
#define VOLATILE_CONDITION_BIND      (VOLATILE_CONDITION_BIND_0 | VOLATILE_CONDITION_BIND_1 | VOLATILE_CONDITION_BIND_2)
#define VOLATILE_CONDITION_ATTRACT   (VOLATILE_CONDITION_ATTRACT_0 | VOLATILE_CONDITION_ATTRACT_1 | VOLATILE_CONDITION_ATTRACT_2 | VOLATILE_CONDITION_ATTRACT_3)

#define VOLATILE_CONDITION_BATON_PASSED (VOLATILE_CONDITION_FOCUS_ENERGY \
    | VOLATILE_CONDITION_MEAN_LOOK                                       \
    | VOLATILE_CONDITION_CONFUSION                                       \
    | VOLATILE_CONDITION_CURSE                                           \
    | VOLATILE_CONDITION_SUBSTITUTE)
#define VOLATILE_CONDITION_TRAPPED (VOLATILE_CONDITION_BIND \
    | VOLATILE_CONDITION_MEAN_LOOK)

#define VOLATILE_CONDITION_CONFUSION_SHIFT 0
#define VOLATILE_CONDITION_UPROAR_SHIFT    4
#define VOLATILE_CONDITION_BIDE_SHIFT      8
#define VOLATILE_CONDITION_THRASH_SHIFT    10
#define VOLATILE_CONDITION_BIND_SHIFT      13
#define VOLATILE_CONDITION_ATTRACT_SHIFT   16

#define SIDE_CONDITION_NONE         0
#define SIDE_CONDITION_REFLECT      (1 << 0)
#define SIDE_CONDITION_LIGHT_SCREEN (1 << 1)
#define SIDE_CONDITION_SPIKES       (1 << 2)
#define SIDE_CONDITION_SAFEGUARD    (1 << 3)
#define SIDE_CONDITION_FUTURE_SIGHT (1 << 4)
#define SIDE_CONDITION_WISH         (1 << 5)
#define SIDE_CONDITION_MIST         (1 << 6)
#define SIDE_CONDITION_STEALTH_ROCK (1 << 7)
#define SIDE_CONDITION_TAILWIND_0   (1 << 8)
#define SIDE_CONDITION_TAILWIND_1   (1 << 9)
#define SIDE_CONDITION_TOXIC_SPIKES (1 << 10)
// unused flag: 1 << 11
#define SIDE_CONDITION_LUCKY_CHANT_0 (1 << 12)
#define SIDE_CONDITION_LUCKY_CHANT_1 (1 << 13)
#define SIDE_CONDITION_LUCKY_CHANT_2 (1 << 14)

#define SIDE_CONDITION_TAILWIND    (SIDE_CONDITION_TAILWIND_0 | SIDE_CONDITION_TAILWIND_1)
#define SIDE_CONDITION_LUCKY_CHANT (SIDE_CONDITION_LUCKY_CHANT_0 | SIDE_CONDITION_LUCKY_CHANT_1 | SIDE_CONDITION_LUCKY_CHANT_2)

#define SIDE_CONDITION_TAILWIND_SHIFT    SIDE_CONDITION_TAILWIND_0
#define SIDE_CONDITION_LUCKY_CHANT_SHIFT SIDE_CONDITION_LUCKY_CHANT_0

#define FIELD_CONDITION_RAINING_TEMP   (1 << 0)
#define FIELD_CONDITION_RAINING_PERM   (1 << 1)
#define FIELD_CONDITION_SANDSTORM_TEMP (1 << 2)
#define FIELD_CONDITION_SANDSTORM_PERM (1 << 3)
#define FIELD_CONDITION_SUNNY_TEMP     (1 << 4)
#define FIELD_CONDITION_SUNNY_PERM     (1 << 5)
#define FIELD_CONDITION_HAILING_TEMP   (1 << 6)
#define FIELD_CONDITION_HAILING_PERM   (1 << 7)
#define FIELD_CONDITION_UPROAR         ((1 << 8) | (1 << 9) | (1 << 10) | (1 << 11)) // mask for which clients are in an Uproar
#define FIELD_CONDITION_GRAVITY_0      (1 << 12)
#define FIELD_CONDITION_GRAVITY_1      (1 << 13)
#define FIELD_CONDITION_GRAVITY_2      (1 << 14)
#define FIELD_CONDITION_DEEP_FOG       (1 << 15)
#define FIELD_CONDITION_TRICK_ROOM_0   (1 << 16)
#define FIELD_CONDITION_TRICK_ROOM_1   (1 << 17)
#define FIELD_CONDITION_TRICK_ROOM_2   (1 << 18)

#define FIELD_CONDITION_RAINING   (FIELD_CONDITION_RAINING_TEMP | FIELD_CONDITION_RAINING_PERM)
#define FIELD_CONDITION_SANDSTORM (FIELD_CONDITION_SANDSTORM_TEMP | FIELD_CONDITION_SANDSTORM_PERM)
#define FIELD_CONDITION_SUNNY     (FIELD_CONDITION_SUNNY_TEMP | FIELD_CONDITION_SUNNY_PERM)
#define FIELD_CONDITION_HAILING   (FIELD_CONDITION_HAILING_TEMP | FIELD_CONDITION_HAILING_PERM)
#define FIELD_CONDITION_WEATHER   (FIELD_CONDITION_RAINING \
    | FIELD_CONDITION_SANDSTORM                            \
    | FIELD_CONDITION_SUNNY                                \
    | FIELD_CONDITION_HAILING                              \
    | FIELD_CONDITION_DEEP_FOG)
#define FIELD_CONDITION_SOLAR_DOWN (FIELD_CONDITION_RAINING \
    | FIELD_CONDITION_SANDSTORM                             \
    | FIELD_CONDITION_HAILING                               \
    | FIELD_CONDITION_DEEP_FOG)
#define FIELD_CONDITION_CASTFORM (FIELD_CONDITION_RAINING | FIELD_CONDITION_SUNNY | FIELD_CONDITION_HAILING)

#define FIELD_CONDITION_GRAVITY         (FIELD_CONDITION_GRAVITY_0 | FIELD_CONDITION_GRAVITY_1 | FIELD_CONDITION_GRAVITY_2)
#define FIELD_CONDITION_GRAVITY_INIT    (FIELD_CONDITION_GRAVITY_0 | FIELD_CONDITION_GRAVITY_2)
#define FIELD_CONDITION_TRICK_ROOM      (FIELD_CONDITION_TRICK_ROOM_0 | FIELD_CONDITION_TRICK_ROOM_1 | FIELD_CONDITION_TRICK_ROOM_2)
#define FIELD_CONDITION_TRICK_ROOM_INIT (FIELD_CONDITION_TRICK_ROOM_0 | FIELD_CONDITION_TRICK_ROOM_2)

#define FIELD_CONDITION_UPROAR_SHIFT     8
#define FIELD_CONDITION_GRAVITY_SHIFT    12
#define FIELD_CONDITION_TRICK_ROOM_SHIFT 16

#endif // POKEPLATINUM_CONSTANTS_BATTLE_CONDITION_H
