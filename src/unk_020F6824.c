#include <nitro.h>
#include <string.h>

#include "constdata/const_020F6824.h"

FS_EXTERN_OVERLAY(overlay73);

int ov73_021D0D80(OverlayManager *param0, int *param1);
int ov73_021D0E20(OverlayManager *param0, int *param1);
int ov73_021D0F7C(OverlayManager *param0, int *param1);

const OverlayManagerTemplate Unk_020F6824 = {
    ov73_021D0D80,
    ov73_021D0E20,
    ov73_021D0F7C,
    FS_OVERLAY_ID(overlay73),
};
