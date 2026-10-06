#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C1B, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x65A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x66A
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x14400, 0xF700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F90[];
extern u16 D_800A4F98[];
extern FieldTalk D_800A4FA0[];
extern FieldTalk D_800A4FB8[];
extern u16 D_800A5060[];
extern FieldTalk D_800A4FD0[];
extern u16 D_800A506C[];
extern FieldTalk D_800A4FE8[];
extern u16 D_800A5078[];
extern FieldTalk D_800A5000[];
extern u16 D_800A5084[];
extern FieldTalk D_800A5018[];
extern u16 D_800A508C[];
extern FieldTalk D_800A5030[];
extern u16 D_800A5098[];
extern FieldTalk D_800A5048[];
extern FieldActorEntry D_800A50A0;
extern FieldActorEntry D_800A50B4;
extern FieldActorEntry D_800A50C8;
extern FieldActorEntry D_800A50DC;
extern FieldActorEntry D_800A50F0;
extern FieldActorEntry D_800A5104;
extern FieldActorEntry D_800A5118;
extern FieldActorEntry D_800A512C;
extern s16 D_800A4E60[];

s16 D_800A4E60[] = {
    0x102, 2, 0x13B, 0x10B, 3,
    0x100, 0x15, 0x11B, 0xFB,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC19, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x12B, 0, 0x2B, 0x150, 0x1FF },
    { 0x140, 0x100, 0x160, 0x123, 0x80, 0x23, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x123, 0xB0, 0x23, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x123, 0xD0, 0x23, 0x150, 0x1FE },
    { 0x140, 0x100, 0x148, 0x12B, 0x20, 0x2B, 0x160, 0x1FE },
    { 0x140, 0x100, 0x150, 0x12B, 0x40, 0x2B, 0x170, 0x1FE },
};
u16 D_800A4F90[] = { 0x7A2F, 1, 0xFFFF };
u16 D_800A4F98[] = { 0x906A, 1, 0xFFFF };
FieldTalk D_800A4FA0[] = {
    { NULL, D_800A4F90, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FB8[] = {
    { NULL, D_800A4F98, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD0[] = {
    { NULL, NULL, 0x1ED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FE8[] = {
    { NULL, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5000[] = {
    { NULL, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5018[] = {
    { NULL, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5030[] = {
    { NULL, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5048[] = {
    { NULL, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
u16 D_800A5060[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A506C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5078[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5084[] = { 0x701A, 1, 0xFFFF };
u16 D_800A508C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5098[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A50A0 = { NULL, D_800A4FA0, 0x14, 4, 225, 289, 7 };
FieldActorEntry D_800A50B4 = { NULL, D_800A4FB8, 0x15, 5, 283, 251, 7 };
FieldActorEntry D_800A50C8 = { D_800A5060, D_800A4FD0, 0x33, 6, 145, 297, 7 };
FieldActorEntry D_800A50DC = { D_800A506C, D_800A4FE8, 0x38, 7, 288, 209, 3 };
FieldActorEntry D_800A50F0 = { D_800A5078, D_800A5000, 0x9D, 8, 288, 209, 3 };
FieldActorEntry D_800A5104 = { D_800A5084, D_800A5018, 0x9D, 8, 288, 209, 3 };
FieldActorEntry D_800A5118 = { D_800A508C, D_800A5030, 0x9E, 9, 145, 297, 7 };
FieldActorEntry D_800A512C = { D_800A5098, D_800A5048, 0x9E, 9, 145, 297, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A50A0,
    &D_800A50B4,
    &D_800A50C8,
    &D_800A50DC,
    &D_800A50F0,
    &D_800A5104,
    &D_800A5118,
    &D_800A512C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 318, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 383, 142, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 235, 262, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 172, 267, 294, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CA, 0x248, 0x18C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1464, D_800A4E60, EVENT_TEXT(0x27), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
