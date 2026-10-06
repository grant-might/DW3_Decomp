#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1B2;
    D_800990B4.sheetEntry = 0x9010000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x900;
    D_800990B4.start = (Vec2){0x1BB00, 0xF400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x9010001);
    D_8009A70C.setFile(7, 0x9010002);
    D_8009A70C.unk50(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

extern u16 D_800A613C[];
extern u16 D_800A6144[];
extern u16 D_800A614C[];
extern FieldTalk D_800A6154[];
extern FieldTalk D_800A616C[];
extern FieldTalk D_800A6184[];
extern FieldTalk D_800A619C[];
extern FieldTalk D_800A61B4[];
extern FieldTalk D_800A61CC[];
extern FieldActorEntry D_800A61F0;
extern FieldActorEntry D_800A6204;
extern FieldActorEntry D_800A6218;
extern FieldActorEntry D_800A622C;
extern FieldActorEntry D_800A6240;
extern FieldActorEntry D_800A6254;
extern FieldActorEntry D_800A6268;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x17A, 0xC0, 0x7A, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x182, 0, 0x82, 0x170, 0x1FF },
    { 0x140, 0x100, 0x148, 0x182, 0x20, 0x82, 0x160, 0x1FE },
    { 0x140, 0x100, 0x150, 0x182, 0x40, 0x82, 0x170, 0x1FE },
    { 0x140, 0x100, 0x158, 0x182, 0x60, 0x82, 0x140, 0x1FD },
    { 0x140, 0x100, 0x160, 0x189, 0x80, 0x89, 0x150, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A613C[] = { 0, 0, 0xFFFF };
u16 D_800A6144[] = { 0, 1, 0xFFFF };
u16 D_800A614C[] = { 0, 1, 0xFFFF };
FieldTalk D_800A6154[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A616C[] = {
    { NULL, NULL, 0x64 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6184[] = {
    { NULL, NULL, 0x66 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A619C[] = {
    { NULL, NULL, 0x62 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61B4[] = {
    { NULL, NULL, 0x63 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61CC[] = {
    { D_800A613C, D_800A6144, 0x59 },
    { D_800A614C, NULL, 0x88 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A61F0 = { NULL, D_800A6154, 0x30, 4, 264, 301, 3 };
FieldActorEntry D_800A6204 = { NULL, D_800A616C, 0x31, 5, 216, 277, 7 };
FieldActorEntry D_800A6218 = { NULL, D_800A6184, 0x32, 6, 352, 296, 5 };
FieldActorEntry D_800A622C = { NULL, D_800A619C, 0x34, 7, 368, 224, 1 };
FieldActorEntry D_800A6240 = { NULL, D_800A61B4, 0x35, 8, 471, 245, 3 };
FieldActorEntry D_800A6254 = { NULL, D_800A61CC, 0x10B, 9, 353, 160, 7 };
FieldActorEntry D_800A6268 = { NULL, NULL, 0x10C, 0xA, 360, 172, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A61F0,
    &D_800A6204,
    &D_800A6218,
    &D_800A622C,
    &D_800A6240,
    &D_800A6254,
    &D_800A6268,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 93, 125, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 0, 0, 0, 0, 0, 126, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 158, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 235, 67, 0, 0 },
    { 1, 0, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 282, 43, 0, 0 },
    { 1, 0, 0x40, 2, 0xF, 0, 0, 0, 0, 0, 379, 34, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 403, 46, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 427, 90, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 463, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 482, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x14, 0, 0, 0, 0, 0, 503, 123, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 84, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 116, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 148, 98, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 272, 44, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 368, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 417, 91, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 453, 113, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 473, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 493, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 497, 124, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 4, 0, 292, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 416, 59, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 224, 68, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 392, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 416, 60, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 208, 263, 288, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 384, 191, 217, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 320, 169, 184, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 304, 161, 174, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 336, 161, 174, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 288, 153, 166, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 352, 153, 166, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 272, 144, 158, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 368, 145, 158, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x271, 0x180, 0xD8, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x281, 0x92, 0x1A2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x110, 0xB8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
