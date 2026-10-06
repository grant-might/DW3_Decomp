#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

/* Sets flag 0x7C0E */
void func_800A5E84(void) {
    FLAGS_00.applyAction(0x7C0E, 1);
}

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x221;
    D_800990B4.sheetEntry = 0x92B0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x92A;
    D_800990B4.start = (Vec2){0x18300, 0x1E600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x92B0001);
    D_8009A70C.setFile(7, 0x92B0002);
    D_8009A70C.unk50(0);
}

void func_800A5E84();
extern u16 D_800A6058[];
extern u16 D_800A6060[];
extern FieldTalk D_800A6068[];
extern FieldTalk D_800A6080[];
extern FieldTalk D_800A6098[];
extern FieldTalk D_800A60B0[];
extern FieldTalk D_800A60C8[];
extern FieldActorEntry D_800A60E0;
extern FieldActorEntry D_800A60F4;
extern FieldActorEntry D_800A6108;
extern FieldActorEntry D_800A611C;
extern FieldActorEntry D_800A6130;
extern s16 D_800A6304[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x16E, 0x98, 0x6E, 0x160, 0x1FD },
    { 0x140, 0x100, 0x172, 0x16E, 0xC8, 0x6E, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1A6, 0x100, 0x198, 0, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1AE, 0x100, 0x1B8, 0, 0x160, 0x1FC },
    { 0x140, 0x100, 0x176, 0x148, 0xD8, 0x48, 0x170, 0x1FC },
};
u16 D_800A6058[] = { 0x9079, 1, 0xFFFF };
u16 D_800A6060[] = { 0x7C00, 1, 0xFFFF };
FieldTalk D_800A6068[] = {
    { NULL, D_800A6058, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6080[] = {
    { NULL, D_800A6060, 0x7B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6098[] = {
    { NULL, NULL, 0x7D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60B0[] = {
    { NULL, NULL, 0x7C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60C8[] = {
    { NULL, NULL, 0x7E },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A60E0 = { NULL, D_800A6068, 0x15, 4, 408, 414, 1 };
FieldActorEntry D_800A60F4 = { NULL, D_800A6080, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A6108 = { NULL, D_800A6098, 0x30, 6, 171, 403, 7 };
FieldActorEntry D_800A611C = { NULL, D_800A60B0, 0x32, 7, 513, 241, 5 };
FieldActorEntry D_800A6130 = { NULL, D_800A60C8, 0x39, 8, 352, 488, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A60E0,
    &D_800A60F4,
    &D_800A6108,
    &D_800A611C,
    &D_800A6130,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 0xA, 0, 283, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 0xA, 0, 428, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 0xA, 0, 307, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 287, 459, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 297, 464, 0, 0 },
    { 1, 0, 0x40, 6, 4, 1, 4, 9, 4, 0, 350, 338, 0, 0 },
    { 1, 0, 0x40, 6, 0xA, 1, 0xA, 0xD, 4, 0, 293, 279, 0, 0 },
    { 1, 0, 0x40, 6, 0xE, 1, 0xE, 0x11, 4, 0, 298, 381, 0, 0 },
    { 1, 0, 0x40, 6, 0x12, 1, 0x12, 0x15, 4, 0, 293, 427, 0, 0 },
    { 1, 0, 0x40, 4, 0x35, 2, 0, 1, 0xA, 0, 333, 483, 503, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 501, 393, 406, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 451, 436, 456, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 436, 464, 482, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 320, 474, 503, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 438, 274, 292, 0 },
    { 1, 0, 0x40, 4, 0x17, 0, 0, 0, 0, 0, 464, 277, 302, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x2F8, 0x104, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x1E8, 0xA4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1646, D_800A6304, EVENT_TEXT(0xF), NULL, func_800A5E84 },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A6304[] = {
    0x102, 2, 0x178, 0x1AC, 5,
    0x100, 0x15, 0x198, 0x19E,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC0C, 0, 0, 0,
    0,
};
