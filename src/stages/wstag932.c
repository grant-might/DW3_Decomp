#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1A8;
    D_800990B4.sheetEntry = 0x8F70000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8F6;
    D_800990B4.start = (Vec2){0x13D00, 0x16F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x8F70001);
    D_8009A70C.setFile(7, 0x8F70002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6010[];
extern u16 D_800A6018[];
extern FieldTalk D_800A6020[];
extern FieldTalk D_800A6038[];
extern FieldTalk D_800A6050[];
extern FieldTalk D_800A6068[];
extern FieldActorEntry D_800A6080;
extern FieldActorEntry D_800A6094;
extern FieldActorEntry D_800A60A8;
extern FieldActorEntry D_800A60BC;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x128, 0xD0, 0x28, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x150, 0x1FE },
    { 0x140, 0x100, 0x174, 0x170, 0xD0, 0x70, 0x160, 0x1FE },
};
u16 D_800A6010[] = { 0x7A13, 1, 0xFFFF };
u16 D_800A6018[] = { 0x7A12, 1, 0xFFFF };
FieldTalk D_800A6020[] = {
    { NULL, D_800A6010, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6038[] = {
    { NULL, D_800A6018, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6050[] = {
    { NULL, NULL, 0x37 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6068[] = {
    { NULL, NULL, 0x38 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A6080 = { NULL, D_800A6020, 0x16, 4, 451, 178, 7 };
FieldActorEntry D_800A6094 = { NULL, D_800A6038, 0x17, 5, 382, 331, 1 };
FieldActorEntry D_800A60A8 = { NULL, D_800A6050, 0x33, 6, 533, 171, 5 };
FieldActorEntry D_800A60BC = { NULL, D_800A6068, 0x36, 7, 195, 402, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6080,
    &D_800A6094,
    &D_800A60A8,
    &D_800A60BC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x3D, 4, 0, 224, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x53, 0xA, 0, 95, 248, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x53, 0xA, 0, 181, 470, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 1, 0x57, 0x59, 0xA, 0, 123, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 148, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 153, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 114, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 155, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 168, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 105, 333, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 126, 300, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 219, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 59, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 62, 328, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 63, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 95, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 126, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0x4D, 1, 0x4D, 0x50, 8, 0, 73, 439, 0, 0 },
    { 1, 0, 0x40, 6, 0, 1, 0, 5, 4, 0, 299, 241, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x150, 0x98, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x60, 0x150, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
