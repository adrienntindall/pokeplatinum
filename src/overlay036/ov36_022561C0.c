#include <nitro.h>
#include <string.h>
#include <nitro/sinit.h>

#include "struct_decls/struct_02018340_decl.h"
#include "struct_decls/sys_task.h"
#include "overlay025/poketch_system.h"
#include "overlay025/poketch_button.h"
#include "overlay036/poketch_app_pedometer.h"

#include "touch_screen.h"

#include "unk_0200D9E8.h"
#include "heap.h"
#include "poketch_data.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    UnkStruct_ov36_02256404_1 unk_04;
    UnkStruct_ov36_02256404 * unk_0C;
    PoketchSystem * unk_10;
    PoketchButtonManager * unk_14;
    u32 unk_18;
    PoketchData * unk_1C;
} UnkStruct_ov36_0225621C;

static void NitroStaticInit(void);

static BOOL ov36_022561D4(void ** param0, PoketchSystem * param1, BGL * param2, u32 param3);
static BOOL ov36_0225621C(UnkStruct_ov36_0225621C * param0, PoketchSystem * param1, BGL * param2, u32 param3);
static void ov36_02256278(u32 param0, u32 param1, u32 param2, void * param3);
static void ov36_02256280(UnkStruct_ov36_0225621C * param0);
static void ov36_02256298(SysTask * param0, void * param1);
static void ov36_022562D4(void * param0);
static void ov36_022562DC(UnkStruct_ov36_0225621C * param0, u32 param1);
static BOOL ov36_022562F0(UnkStruct_ov36_0225621C * param0);
static BOOL ov36_02256330(UnkStruct_ov36_0225621C * param0);
static BOOL ov36_022563D0(UnkStruct_ov36_0225621C * param0);

static void NitroStaticInit (void)
{
    PoketchSystem_SetAppFunctions(ov36_022561D4, ov36_022562D4);
}

static BOOL ov36_022561D4 (void ** param0, PoketchSystem * param1, BGL * param2, u32 param3)
{
    UnkStruct_ov36_0225621C * v0 = (UnkStruct_ov36_0225621C *)Heap_AllocFromHeap(HEAP_ID_POKETCH_APP, sizeof(UnkStruct_ov36_0225621C));

    if (v0 != NULL) {
        if (ov36_0225621C(v0, param1, param2, param3)) {
            if (SysTask_Start(ov36_02256298, v0, 1) != NULL) {
                *param0 = v0;
                return 1;
            }
        }

        Heap_FreeToHeap(v0);
    }

    return 0;
}

static BOOL ov36_0225621C (UnkStruct_ov36_0225621C * param0, PoketchSystem * param1, BGL * param2, u32 param3)
{
    static const TouchScreenHitTable v0[] = {
        {
            128 - (56 / 2),
            128 + (56 / 2),
            114 - (64 / 2),
            114 + (64 / 2)
        },
    };

    param0->unk_10 = param1;
    param0->unk_1C = PoketchSystem_PoketchData(param1);
    param0->unk_04.unk_04 = 1;
    param0->unk_04.unk_00 = PoketchData_StepCount(param0->unk_1C);

    if (ov36_02256404(&(param0->unk_0C), &(param0->unk_04), param2)) {
        param0->unk_00 = 0;
        param0->unk_01 = 0;
        param0->unk_02 = 0;
        param0->unk_14 = PoketchButtonManager_New(v0, NELEMS(v0), ov36_02256278, param0, 8);
        param0->unk_18 = 0;

        return 1;
    }

    return 0;
}

static void ov36_02256278 (u32 param0, u32 param1, u32 param2, void * param3)
{
    UnkStruct_ov36_0225621C * v0 = (UnkStruct_ov36_0225621C *)param3;

    if (param0 == 0) {
        v0->unk_18 = param1;
    }
}

static void ov36_02256280 (UnkStruct_ov36_0225621C * param0)
{
    PoketchButtonManager_Free(param0->unk_14);
    ov36_02256440(param0->unk_0C);

    Heap_FreeToHeap(param0);
}

static void ov36_02256298 (SysTask * param0, void * param1)
{
    static BOOL(*const v0[])(UnkStruct_ov36_0225621C *) = {
        ov36_022562F0,
        ov36_02256330,
        ov36_022563D0
    };

    UnkStruct_ov36_0225621C * v1 = (UnkStruct_ov36_0225621C *)param1;

    if (v1->unk_00 < NELEMS(v0)) {
        ov25_02254518(v1->unk_10, v1->unk_14);

        if (v0[v1->unk_00](v1)) {
            ov36_02256280(v1);
            SysTask_Done(param0);
            PoketchSystem_NotifyAppUnloaded(v1->unk_10);
        }
    } else {
    }
}

static void ov36_022562D4 (void * param0)
{
    ((UnkStruct_ov36_0225621C *)param0)->unk_02 = 1;
}

static void ov36_022562DC (UnkStruct_ov36_0225621C * param0, u32 param1)
{
    if (param0->unk_02 == 0) {
        param0->unk_00 = param1;
    } else {
        param0->unk_00 = 2;
    }

    param0->unk_01 = 0;
}

static BOOL ov36_022562F0 (UnkStruct_ov36_0225621C * param0)
{
    switch (param0->unk_01) {
    case 0:
        ov36_0225653C(param0->unk_0C, 0);
        param0->unk_01++;
        break;
    case 1:
        if (ov36_02256560(param0->unk_0C, 0)) {
            PoketchSystem_NotifyAppLoaded(param0->unk_10);
            ov36_022562DC(param0, 1);
        }
        break;
    }

    return 0;
}

static BOOL ov36_02256330 (UnkStruct_ov36_0225621C * param0)
{
    UnkStruct_ov36_02256404_1 * v0 = &(param0->unk_04);

    if (param0->unk_02) {
        ov36_022562DC(param0, 2);
        return 0;
    }

    switch (param0->unk_01) {
    case 0:
        if (param0->unk_18 == 1) {
            v0->unk_04 = 0;
            ov36_0225653C(param0->unk_0C, 2);
            param0->unk_18 = 0;
            param0->unk_01++;
            break;
        }

        if (PoketchSystem_PedometerUpdated(param0->unk_10)) {
            v0->unk_00 = PoketchData_StepCount(param0->unk_1C);
            ov36_0225653C(param0->unk_0C, 3);
            break;
        }
        break;
    case 1:
        if (param0->unk_18 == 2) {
            v0->unk_04 = 1;

            ov36_0225653C(param0->unk_0C, 2);

            param0->unk_18 = 0;
            param0->unk_01 = 0;
            break;
        }

        if (param0->unk_18 == 3) {
            v0->unk_04 = 1;
            v0->unk_00 = 0;

            PoketchData_SetStepCount(param0->unk_1C, 0);

            ov36_0225653C(param0->unk_0C, 2);
            ov36_0225653C(param0->unk_0C, 3);

            param0->unk_18 = 0;
            param0->unk_01 = 0;
            break;
        }

        break;
    }

    return 0;
}

static BOOL ov36_022563D0 (UnkStruct_ov36_0225621C * param0)
{
    switch (param0->unk_01) {
    case 0:
        ov36_0225653C(param0->unk_0C, 1);
        param0->unk_01++;
        break;
    case 1:
        if (ov36_0225656C(param0->unk_0C)) {
            return 1;
        }
        break;
    }

    return 0;
}
