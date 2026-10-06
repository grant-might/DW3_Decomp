#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x239;
    D_800990B4.sheetEntry = 0x9140000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x915;
    D_800990B4.start = (Vec2){0xB700, 0xD300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x31;
    D_800990B4.music = 0x60C40000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x9140001);
    D_8009A70C.setFile(7, 0x9140002);
    D_8009A70C.unk50(0);
}

extern FieldTalk D_800A5FE8[];
extern FieldTalk D_800A6000[];
extern FieldActorEntry D_800A6018;
extern FieldActorEntry D_800A602C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x138, 0x78, 0x38, 0x160, 0x1FF },
    { 0x140, 0x100, 0x166, 0x14C, 0x98, 0x4C, 0x170, 0x1FF },
};
FieldTalk D_800A5FE8[] = {
    { NULL, NULL, 0x70 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6000[] = {
    { NULL, NULL, 0x71 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A6018 = { NULL, D_800A5FE8, 0x34, 4, 241, 201, 5 };
FieldActorEntry D_800A602C = { NULL, D_800A6000, 0x171, 5, 192, 633, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6018,
    &D_800A602C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x34, 2, 0, 7, 4, 0, 97, 134, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 7, 4, 0, 137, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 321, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 577, 313, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 497, 272, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 4, 0, 167, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 7, 4, 0, 187, 293, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 7, 4, 0, 307, 233, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 276, 208, 242, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 51, 156, 208, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 425, 290, 314, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 421, 428, 438, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 423, 392, 429, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x292, 0x156, 0x1B0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
