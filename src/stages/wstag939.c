#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x764;
    D_800990B4.sheetEntry = 0x9050000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x904;
    D_800990B4.start = (Vec2){0xF500, 0x17A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2B;
    D_800990B4.music = 0x60AC0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, 0x9050001);
    D_8009A70C.setFile(7, 0x9050002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5FFC[];
extern u16 D_800A6004[];
extern u16 D_800A6010[];
extern FieldTalk D_800A601C[];
extern FieldTalk D_800A6034[];
extern FieldTalk D_800A604C[];
extern FieldActorEntry D_800A607C;
extern FieldActorEntry D_800A6090;
extern FieldActorEntry D_800A60A4;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x140, 0x1EE },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x140, 0x1ED },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x140, 0x1EC },
};
u16 D_800A5FFC[] = { 0x7054, 0, 0xFFFF };
u16 D_800A6004[] = { 0x7054, 1, 0x100C, 0, 0xFFFF };
u16 D_800A6010[] = { 0x7054, 1, 0x100C, 1, 0xFFFF };
FieldTalk D_800A601C[] = {
    { NULL, NULL, 0x6D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6034[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A604C[] = {
    { D_800A5FFC, NULL, 0x6A },
    { D_800A6004, NULL, 0x6B },
    { D_800A6010, NULL, 0x6C },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A607C = { NULL, D_800A601C, 0x20, 4, 368, 264, 5 };
FieldActorEntry D_800A6090 = { NULL, D_800A6034, 0x24, 5, 440, 253, 5 };
FieldActorEntry D_800A60A4 = { NULL, D_800A604C, 0x68, 6, 407, 269, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A607C,
    &D_800A6090,
    &D_800A60A4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 374, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 390, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 406, 285, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 422, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 458, 262, 0, 0 },
    { 1, 0, 0x49, 6, 0, 1, 0, 3, 4, 0, 84, 193, 0, 0 },
    { 1, 0, 0x5D, 6, 4, 1, 4, 7, 4, 0, 68, 252, 0, 0 },
    { 1, 0, 0x5D, 6, 5, 1, 5, 8, 4, 0, 131, 227, 0, 0 },
    { 1, 0, 0x5D, 6, 0xB, 1, 0xB, 0xE, 4, 0, 182, 153, 0, 0 },
    { 1, 0, 0x49, 6, 0, 1, 0, 3, 4, 0, 227, 178, 0, 0 },
    { 1, 0, 0x5D, 6, 7, 1, 7, 0xA, 4, 0, 272, 108, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 2, 0, 2, 0x10, 0, 438, 220, 0, 0 },
    { 1, 3, 0x40, 6, 0x33, 2, 0, 1, 0x10, 0, 438, 220, 0, 0 },
    { 1, 2, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 4, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 294, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 310, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 326, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 342, 237, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 374, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0xF, 0, 0, 0, 0, 0, 448, 207, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28A, 0x3F8, 0x2DC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
