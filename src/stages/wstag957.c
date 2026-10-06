#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x24C;
    D_800990B4.sheetEntry = 0x9290000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x928;
    D_800990B4.start = (Vec2){0x1A200, 0x17A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x9290001);
    D_8009A70C.setFile(7, 0x9290002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6030[];
extern u16 D_800A6038[];
extern u16 D_800A6040[];
extern u16 D_800A6048[];
extern FieldTalk D_800A6050[];
extern FieldTalk D_800A6068[];
extern FieldTalk D_800A6080[];
extern u16 D_800A60E0[];
extern FieldTalk D_800A6098[];
extern u16 D_800A60E8[];
extern FieldTalk D_800A60B0[];
extern FieldTalk D_800A60C8[];
extern FieldActorEntry D_800A60F0;
extern FieldActorEntry D_800A6104;
extern FieldActorEntry D_800A6118;
extern FieldActorEntry D_800A612C;
extern FieldActorEntry D_800A6140;
extern FieldActorEntry D_800A6154;
extern FieldActorEntry D_800A6168;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x1A7, 0x70, 0xA7, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x173, 0xD8, 0x73, 0x170, 0x1FE },
    { 0x140, 0x100, 0x160, 0x147, 0x80, 0x47, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x170, 0x1FC },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x180, 0x100, 0x190, 0x11A, 0x140, 0x1A, 0x170, 0x1FB },
};
u16 D_800A6030[] = { 0x7A2A, 1, 0xFFFF };
u16 D_800A6038[] = { 0x7A15, 1, 0xFFFF };
u16 D_800A6040[] = { 0x7A14, 1, 0xFFFF };
u16 D_800A6048[] = { 0x7A47, 1, 0xFFFF };
FieldTalk D_800A6050[] = {
    { NULL, D_800A6030, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6068[] = {
    { NULL, D_800A6038, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6080[] = {
    { NULL, D_800A6040, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6098[] = {
    { NULL, D_800A6048, 0x87 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60B0[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60C8[] = {
    { NULL, NULL, 0x7A },
    { NULL, NULL, 0 },
};
u16 D_800A60E0[] = { 0x8192, 1, 0xFFFF };
u16 D_800A60E8[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A60F0 = { NULL, D_800A6050, 0x14, 4, 345, 197, 7 };
FieldActorEntry D_800A6104 = { NULL, D_800A6068, 0x16, 5, 408, 341, 7 };
FieldActorEntry D_800A6118 = { NULL, D_800A6080, 0x17, 6, 330, 380, 7 };
FieldActorEntry D_800A612C = { D_800A60E0, D_800A6098, 0xCE, 7, 128, 201, 7 };
FieldActorEntry D_800A6140 = { D_800A60E8, D_800A60B0, 0xCE, 7, 128, 201, 7 };
FieldActorEntry D_800A6154 = { NULL, NULL, 0xDB, 8, 345, 213, 7 };
FieldActorEntry D_800A6168 = { NULL, D_800A60C8, 0x179, 9, 384, 418, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A60F0,
    &D_800A6104,
    &D_800A6118,
    &D_800A612C,
    &D_800A6140,
    &D_800A6154,
    &D_800A6168,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 304, 189, 222, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 290, 166, 222, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 328, 195, 215, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 336, 187, 207, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 352, 180, 199, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 367, 164, 199, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 472, 281, 331, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 496, 352, 399, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 271, 382, 399, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 289, 374, 391, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 336, 350, 367, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 353, 343, 358, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 366, 323, 351, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 416, 309, 326, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 435, 292, 319, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 176, 155, 211, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 160, 148, 199, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 144, 140, 191, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 128, 132, 184, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 118, 127, 179, 0 },
    { 1, 0, 0x64, 4, 0x14, 0, 0, 0, 0, 0, 448, 251, 310, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x1E8, 0x1AC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x100, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x10F, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xB0, 0xD8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xBF, 0x11E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
