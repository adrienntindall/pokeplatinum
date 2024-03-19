#ifndef POKEPLATINUM_CONSTANTS_HEAP_H
#define POKEPLATINUM_CONSTANTS_HEAP_H

enum {
    HEAP_BASE_ID_SYSTEM,
    HEAP_BASE_ID_SAVE,
    HEAP_BASE_ID_DEBUG,
    HEAP_BASE_ID_APPLICATION,
    HEAP_BASE_ID_COUNT,
};

enum HeapId {
    HEAP_ID_SYSTEM = 0,
    
    HEAP_ID_BATTLE = 5,
};

#endif // POKEPLATINUM_CONSTANTS_HEAP_H
