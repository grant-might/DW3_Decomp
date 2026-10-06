#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1A4;
    D_800990B4.sheetEntry = 0x8F30000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8F2;
    D_800990B4.start = (Vec2){0xB300, 0xFF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x8F30001);
    D_8009A70C.setFile(7, 0x8F30002);
    D_8009A70C.unk50(0);
}

extern FieldTalk D_800A6028[];
extern FieldTalk D_800A6040[];
extern FieldTalk D_800A6058[];
extern FieldActorEntry D_800A6070;
extern FieldActorEntry D_800A6084;
extern FieldActorEntry D_800A6098;
extern FieldActorEntry D_800A60AC;
extern FieldActorEntry D_800A60C0;
extern FieldActorEntry D_800A60D4;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x14A, 0x100, 0x28, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x160, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
FieldTalk D_800A6028[] = {
    { NULL, NULL, 0x81 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6040[] = {
    { NULL, NULL, 0x82 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6058[] = {
    { NULL, NULL, 0x80 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A6070 = { NULL, D_800A6028, 0x28, 4, 135, 212, 1 };
FieldActorEntry D_800A6084 = { NULL, D_800A6040, 0x29, 5, 173, 155, 1 };
FieldActorEntry D_800A6098 = { NULL, D_800A6058, 0x2A, 6, 56, 193, 1 };
FieldActorEntry D_800A60AC = { NULL, NULL, 0xDD, 7, 184, 173, 7 };
FieldActorEntry D_800A60C0 = { NULL, NULL, 0xDE, 8, 143, 240, 7 };
FieldActorEntry D_800A60D4 = { NULL, NULL, 0xDF, 9, 64, 224, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A6070,
    &D_800A6084,
    &D_800A6098,
    &D_800A60AC,
    &D_800A60C0,
    &D_800A60D4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 62, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 124, 173, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 218, 227, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 242, 146, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 295, 210, 0, 0 },
    { 1, 0, 0x40, 2, 1, 2, 0, 1, 4, 0, 227, 130, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x279, 0xD8, 0x54, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0xF0, 0xBF, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x120, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x12F, 0xAE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
