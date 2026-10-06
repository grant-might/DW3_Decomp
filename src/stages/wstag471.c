#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C18, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x56D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x57D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1D400, 0x15400};
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

extern u16 D_800A4FC4[];
extern u16 D_800A4FCC[];
extern FieldTalk D_800A4FD4[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A510C[];
extern FieldTalk D_800A5004[];
extern u16 D_800A5118[];
extern FieldTalk D_800A501C[];
extern u16 D_800A5124[];
extern FieldTalk D_800A5034[];
extern u16 D_800A512C[];
extern FieldTalk D_800A504C[];
extern u16 D_800A5134[];
extern FieldTalk D_800A5064[];
extern u16 D_800A513C[];
extern FieldTalk D_800A507C[];
extern u16 D_800A5144[];
extern FieldTalk D_800A5094[];
extern u16 D_800A514C[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A5158[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A5160[];
extern FieldTalk D_800A50DC[];
extern u16 D_800A516C[];
extern FieldTalk D_800A50F4[];
extern FieldActorEntry D_800A5174;
extern FieldActorEntry D_800A5188;
extern FieldActorEntry D_800A519C;
extern FieldActorEntry D_800A51B0;
extern FieldActorEntry D_800A51C4;
extern FieldActorEntry D_800A51D8;
extern FieldActorEntry D_800A51EC;
extern FieldActorEntry D_800A5200;
extern FieldActorEntry D_800A5214;
extern FieldActorEntry D_800A5228;
extern FieldActorEntry D_800A523C;
extern FieldActorEntry D_800A5250;
extern FieldActorEntry D_800A5264;
extern FieldActorEntry D_800A5278;
extern FieldActorEntry D_800A528C;
extern s16 D_800A4E64[];

s16 D_800A4E64[] = {
    0x102, 2, 0xA0, 0x148, 3,
    0x100, 0x15, 0x80, 0x138,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC16, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x158, 0xC0, 0x58, 0x160, 0x1FF },
    { 0x140, 0x100, 0x172, 0x100, 0xC8, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x178, 0xC0, 0x78, 0x160, 0x1FE },
    { 0x140, 0x100, 0x172, 0x130, 0xC8, 0x30, 0x170, 0x1FE },
    { 0x140, 0x100, 0x150, 0x196, 0x40, 0x96, 0x160, 0x1FD },
    { 0x140, 0x100, 0x158, 0x196, 0x60, 0x96, 0x170, 0x1FD },
    { 0x140, 0x100, 0x170, 0x198, 0xC0, 0x98, 0x160, 0x1FC },
    { 0x140, 0x100, 0x160, 0x19C, 0x80, 0x9C, 0x170, 0x1FC },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4FC4[] = { 0x7A2B, 1, 0xFFFF };
u16 D_800A4FCC[] = { 0x9067, 1, 0xFFFF };
FieldTalk D_800A4FD4[] = {
    { NULL, D_800A4FC4, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, D_800A4FCC, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0xA7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, NULL, 0xAD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, NULL, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, NULL, 0xA6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0xA8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F4[] = {
    { NULL, NULL, 0xAF },
    { NULL, NULL, 0 },
};
u16 D_800A510C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5118[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5124[] = { 0x701D, 1, 0xFFFF };
u16 D_800A512C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5134[] = { 0x701A, 1, 0xFFFF };
u16 D_800A513C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5144[] = { 0x6025, 1, 0xFFFF };
u16 D_800A514C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5158[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5160[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A516C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5174 = { NULL, D_800A4FD4, 0x14, 4, 357, 278, 7 };
FieldActorEntry D_800A5188 = { NULL, D_800A4FEC, 0x15, 5, 128, 312, 7 };
FieldActorEntry D_800A519C = { D_800A510C, D_800A5004, 0x2E, 6, 496, 321, 1 };
FieldActorEntry D_800A51B0 = { D_800A5118, D_800A501C, 0x35, 7, 557, 151, 1 };
FieldActorEntry D_800A51C4 = { NULL, NULL, 0x78, 8, 368, 232, 5 };
FieldActorEntry D_800A51D8 = { D_800A5124, D_800A5034, 0x79, 9, 289, 338, 7 };
FieldActorEntry D_800A51EC = { D_800A512C, D_800A504C, 0x79, 9, 289, 338, 7 };
FieldActorEntry D_800A5200 = { D_800A5134, D_800A5064, 0x79, 9, 289, 338, 7 };
FieldActorEntry D_800A5214 = { D_800A513C, D_800A507C, 0x79, 9, 289, 338, 7 };
FieldActorEntry D_800A5228 = { D_800A5144, D_800A5094, 0x79, 9, 289, 338, 7 };
FieldActorEntry D_800A523C = { D_800A514C, D_800A50AC, 0x9D, 0xA, 557, 151, 1 };
FieldActorEntry D_800A5250 = { D_800A5158, D_800A50C4, 0x9D, 0xA, 557, 151, 1 };
FieldActorEntry D_800A5264 = { D_800A5160, D_800A50DC, 0x9E, 0xB, 496, 321, 1 };
FieldActorEntry D_800A5278 = { D_800A516C, D_800A50F4, 0x9E, 0xB, 496, 321, 1 };
FieldActorEntry D_800A528C = { NULL, NULL, 0xDB, 0xC, 368, 296, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5174,
    &D_800A5188,
    &D_800A519C,
    &D_800A51B0,
    &D_800A51C4,
    &D_800A51D8,
    &D_800A51EC,
    &D_800A5200,
    &D_800A5214,
    &D_800A5228,
    &D_800A523C,
    &D_800A5250,
    &D_800A5264,
    &D_800A5278,
    &D_800A528C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 249, 225, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 311, 194, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 472, 215, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 193, 297, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 257, 265, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 265, 384, 412, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 367, 333, 361, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 288, 299, 318, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 288, 305, 327, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 306, 299, 320, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 321, 290, 311, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 338, 282, 303, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 356, 275, 295, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 370, 266, 287, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 386, 258, 279, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 402, 250, 271, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 418, 242, 263, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 434, 235, 255, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A4, 0x1BE, 0xBA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x243, 0xC0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x252, 0x116, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0xB1, 0x149, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0xC0, 0x17E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1461, D_800A4E64, EVENT_TEXT(0x31), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
