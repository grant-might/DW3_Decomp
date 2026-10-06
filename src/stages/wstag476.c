#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x6FD
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x70D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xB100, 0x12B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xF;
    D_800990B4.music = 0x603C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern FieldTalk D_800A4E98[];
extern FieldActorEntry D_800A4EB0;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FF },
};
FieldTalk D_800A4E98[] = {
    { NULL, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A4EB0 = { NULL, D_800A4E98, 0x84, 4, 144, 257, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A4EB0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 0xA, 0, 216, 262, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 0xA, 0, 72, 170, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 348, 225, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 355, 229, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A4, 0x412, 0x1A4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
