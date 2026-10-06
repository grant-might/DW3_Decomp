#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1C0;
    D_800990B4.sheetEntry = 0x92D0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x92C;
    D_800990B4.start = (Vec2){0x15100, 0x18800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x92D0001);
    D_8009A70C.setFile(7, 0x92D0002);
    D_8009A70C.unk50(0);
}

extern FieldTalk D_800A5FE0[];
extern FieldActorEntry D_800A5FF8;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x150, 0x1FF },
};
FieldTalk D_800A5FE0[] = {
    { NULL, NULL, 0x7F },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A5FF8 = { NULL, D_800A5FE0, 0x3E, 4, 256, 455, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5FF8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xD0, 2, 0x32, 0, 0, 0, 0, 0, 51, 95, 0, 0 },
    { 1, 0, 0xD0, 2, 0x32, 0, 0, 0, 0, 0, 300, 55, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x350, 0x230, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
