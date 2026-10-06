#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1AA;
    D_800990B4.sheetEntry = 0x8F90000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8F8;
    D_800990B4.start = (Vec2){0x10B00, 0x12C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x8F90001);
    D_8009A70C.setFile(7, 0x8F90002);
    D_8009A70C.unk50(0);
}

extern FieldTalk D_800A6040[];
extern FieldTalk D_800A6058[];
extern FieldTalk D_800A6070[];
extern FieldTalk D_800A6088[];
extern FieldTalk D_800A60A0[];
extern FieldActorEntry D_800A60B8;
extern FieldActorEntry D_800A60CC;
extern FieldActorEntry D_800A60E0;
extern FieldActorEntry D_800A60F4;
extern FieldActorEntry D_800A6108;
extern FieldActorEntry D_800A611C;
extern FieldActorEntry D_800A6130;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x17A, 0x28, 0x7A, 0x150, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x162, 0x68, 0x62, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x188, 0, 0x88, 0x170, 0x1FF },
    { 0x140, 0x100, 0x164, 0x162, 0x90, 0x62, 0x150, 0x1FE },
    { 0x140, 0x100, 0x170, 0x148, 0xC0, 0x48, 0x160, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x15A, 0x18A, 0x68, 0x8A, 0x170, 0x1FE },
};
FieldTalk D_800A6040[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6058[] = {
    { NULL, NULL, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6070[] = {
    { NULL, NULL, 0x3B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6088[] = {
    { NULL, NULL, 0x3C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60A0[] = {
    { NULL, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A60B8 = { NULL, D_800A6040, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A60CC = { NULL, D_800A6058, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A60E0 = { NULL, D_800A6070, 0x39, 6, 133, 187, 1 };
FieldActorEntry D_800A60F4 = { NULL, NULL, 0x44, 7, 307, 240, 5 };
FieldActorEntry D_800A6108 = { NULL, D_800A6088, 0x84, 8, 217, 257, 5 };
FieldActorEntry D_800A611C = { NULL, NULL, 0xE0, 9, 267, 266, 7 };
FieldActorEntry D_800A6130 = { NULL, D_800A60A0, 0x16F, 0xA, 101, 203, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A60B8,
    &D_800A60CC,
    &D_800A60E0,
    &D_800A60F4,
    &D_800A6108,
    &D_800A611C,
    &D_800A6130,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 115, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 163, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 227, 75, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 280, 73, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 328, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 376, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 117, 147, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 165, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 229, 92, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 259, 90, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 307, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 355, 139, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xF, 0, 0, 0, 0, 0, 350, 125, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 192, 271, 301, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 184, 263, 288, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 152, 216, 233, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 178, 254, 277, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 280, 256, 280, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 264, 248, 271, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 248, 240, 264, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 232, 232, 256, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 217, 222, 248, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 312, 231, 263, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 332, 222, 253, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x112, 0x220, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x279, 0x68, 0x15A, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
