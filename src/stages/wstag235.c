#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x195
#define STAGE_ARCHIVE 0x3BE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x1A3
#define STAGE_ARCHIVE 0x3CE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xBC00, 0xB600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F54[];
extern u16 D_800A4F5C[];
extern u16 D_800A4F64[];
extern u16 D_800A4F6C[];
extern u16 D_800A4F74[];
extern u16 D_800A4F7C[];
extern u16 D_800A4F84[];
extern u16 D_800A4F8C[];
extern u16 D_800A4F94[];
extern u16 D_800A4F9C[];
extern u16 D_800A4FAC[];
extern u16 D_800A4FB4[];
extern u16 D_800A4FBC[];
extern u16 D_800A4FC8[];
extern u16 D_800A4FD0[];
extern u16 D_800A4FE0[];
extern u16 D_800A4FE8[];
extern u16 D_800A4FFC[];
extern u16 D_800A5004[];
extern u16 D_800A501C[];
extern u16 D_800A5024[];
extern u16 D_800A5040[];
extern u16 D_800A5048[];
extern u16 D_800A5064[];
extern u16 D_800A5074[];
extern u16 D_800A507C[];
extern u16 D_800A5088[];
extern u16 D_800A5090[];
extern u16 D_800A50A0[];
extern u16 D_800A50A8[];
extern u16 D_800A50BC[];
extern u16 D_800A50C4[];
extern u16 D_800A50DC[];
extern u16 D_800A50E4[];
extern u16 D_800A5100[];
extern u16 D_800A5108[];
extern u16 D_800A5124[];
extern FieldTalk D_800A5134[];
extern FieldTalk D_800A5158[];
extern u16 D_800A5368[];
extern FieldTalk D_800A517C[];
extern u16 D_800A5370[];
extern FieldTalk D_800A5194[];
extern u16 D_800A5378[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A5380[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A5388[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5390[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A5398[];
extern FieldTalk D_800A520C[];
extern u16 D_800A53A0[];
extern FieldTalk D_800A5224[];
extern u16 D_800A53A8[];
extern FieldTalk D_800A523C[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A5254[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A526C[];
extern u16 D_800A53C4[];
extern FieldTalk D_800A5290[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A52F0[];
extern u16 D_800A53D8[];
extern FieldTalk D_800A5350[];
extern FieldActorEntry D_800A53E0;
extern FieldActorEntry D_800A53F4;
extern FieldActorEntry D_800A5408;
extern FieldActorEntry D_800A541C;
extern FieldActorEntry D_800A5430;
extern FieldActorEntry D_800A5444;
extern FieldActorEntry D_800A5458;
extern FieldActorEntry D_800A546C;
extern FieldActorEntry D_800A5480;
extern FieldActorEntry D_800A5494;
extern FieldActorEntry D_800A54A8;
extern FieldActorEntry D_800A54BC;
extern FieldActorEntry D_800A54D0;
extern FieldActorEntry D_800A54E4;
extern FieldActorEntry D_800A54F8;
extern FieldActorEntry D_800A550C;
extern s16 D_800A4E30[];

s16 D_800A4E30[] = {
    0x102, 2, 0xCF, 0xD0, 3,
    0x100, 0x15, 0xAF, 0xC0,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC01, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x168, 0x88, 0x68, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x169, 0, 0x69, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x168, 0x68, 0x68, 0x160, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x174, 0x16C, 0xD0, 0x6C, 0x170, 0x1FE },
};
u16 D_800A4F54[] = { 0x1A08, 0, 0xFFFF };
u16 D_800A4F5C[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F64[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F6C[] = { 0x7A1E, 1, 0xFFFF };
u16 D_800A4F74[] = { 0x1A09, 0, 0xFFFF };
u16 D_800A4F7C[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4F84[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4F8C[] = { 0x9001, 0, 0xFFFF };
u16 D_800A4F94[] = { 0x1A23, 0, 0xFFFF };
u16 D_800A4F9C[] = { 0x1A23, 1, 0x92B7, 1, 0x7013, 1, 0xFFFF };
u16 D_800A4FAC[] = { 0x1A23, 1, 0xFFFF };
u16 D_800A4FB4[] = { 0x1C34, 1, 0xFFFF };
u16 D_800A4FBC[] = { 0x1C34, 0, 0, 0, 0xFFFF };
u16 D_800A4FC8[] = { 0, 1, 0xFFFF };
u16 D_800A4FD0[] = { 0x1C34, 0, 0, 1, 1, 0, 0xFFFF };
u16 D_800A4FE0[] = { 1, 1, 0xFFFF };
u16 D_800A4FE8[] = { 0x1C34, 0, 0, 1, 1, 1, 2, 0, 0xFFFF };
u16 D_800A4FFC[] = { 2, 1, 0xFFFF };
u16 D_800A5004[] = {
    0x1C34, 0, 0, 1, 1, 1, 2, 1,
    3, 0, 0xFFFF,
};
u16 D_800A501C[] = { 3, 1, 0xFFFF };
u16 D_800A5024[] = {
    0x1C34, 0, 0, 1, 1, 1, 2, 1,
    3, 1, 4, 0, 0xFFFF,
};
u16 D_800A5040[] = { 4, 1, 0xFFFF };
u16 D_800A5048[] = {
    1, 1, 2, 1, 3, 1, 4, 1,
    0x1C34, 0, 0, 1, 0xFFFF,
};
u16 D_800A5064[] = { 0x708C, 1, 0x1C34, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5074[] = { 0x1C34, 1, 0xFFFF };
u16 D_800A507C[] = { 0x1C34, 0, 0, 0, 0xFFFF };
u16 D_800A5088[] = { 0, 1, 0xFFFF };
u16 D_800A5090[] = { 0x1C34, 0, 0, 1, 1, 0, 0xFFFF };
u16 D_800A50A0[] = { 1, 1, 0xFFFF };
u16 D_800A50A8[] = { 0x1C34, 0, 0, 1, 1, 1, 2, 0, 0xFFFF };
u16 D_800A50BC[] = { 2, 1, 0xFFFF };
u16 D_800A50C4[] = {
    0x1C34, 0, 0, 1, 1, 1, 2, 1,
    3, 0, 0xFFFF,
};
u16 D_800A50DC[] = { 3, 1, 0xFFFF };
u16 D_800A50E4[] = {
    0, 1, 1, 1, 2, 1, 3, 1,
    4, 0, 0x1C34, 0, 0xFFFF,
};
u16 D_800A5100[] = { 4, 1, 0xFFFF };
u16 D_800A5108[] = {
    0x1C34, 0, 0, 1, 1, 1, 2, 1,
    3, 1, 4, 1, 0xFFFF,
};
u16 D_800A5124[] = { 0x1C34, 1, 0x708C, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5134[] = {
    { D_800A4F54, D_800A4F5C, 0x18C },
    { D_800A4F64, D_800A4F6C, 0x18D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5158[] = {
    { D_800A4F74, D_800A4F7C, 0x18B },
    { D_800A4F84, D_800A4F8C, 0x18A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A517C[] = {
    { NULL, NULL, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5194[] = {
    { NULL, NULL, 0x207 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51AC[] = {
    { NULL, NULL, 0x200 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x201 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x202 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x203 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x204 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0x1FE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0x1FF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { D_800A4F94, D_800A4F9C, 0xB5 },
    { D_800A4FAC, NULL, 0xB6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5290[] = {
    { D_800A4FB4, NULL, 0xB6 },
    { D_800A4FBC, D_800A4FC8, 5 },
    { D_800A4FD0, D_800A4FE0, 7 },
    { D_800A4FE8, D_800A4FFC, 7 },
    { D_800A5004, D_800A501C, 7 },
    { D_800A5024, D_800A5040, 7 },
    { D_800A5048, D_800A5064, 6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F0[] = {
    { D_800A5074, NULL, 0xB6 },
    { D_800A507C, D_800A5088, 5 },
    { D_800A5090, D_800A50A0, 7 },
    { D_800A50A8, D_800A50BC, 7 },
    { D_800A50C4, D_800A50DC, 7 },
    { D_800A50E4, D_800A5100, 7 },
    { D_800A5108, D_800A5124, 6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5350[] = {
    { NULL, NULL, 0x206 },
    { NULL, NULL, 0 },
};
u16 D_800A5368[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5370[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5378[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5380[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5388[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5390[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5398[] = { 0x7019, 1, 0xFFFF };
u16 D_800A53A0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53A8[] = { 0x7015, 1, 0xFFFF };
u16 D_800A53B0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x1A22, 1, 0x1A23, 0, 0xFFFF };
u16 D_800A53C4[] = { 0x1A22, 0, 0xFFFF };
u16 D_800A53CC[] = { 0x1A22, 1, 0x1A23, 1, 0xFFFF };
u16 D_800A53D8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A53E0 = { NULL, D_800A5134, 0x14, 4, 188, 154, 7 };
FieldActorEntry D_800A53F4 = { NULL, D_800A5158, 0x15, 5, 175, 192, 7 };
FieldActorEntry D_800A5408 = { D_800A5368, D_800A517C, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A541C = { D_800A5370, D_800A5194, 0x38, 6, 88, 332, 7 };
FieldActorEntry D_800A5430 = { D_800A5378, D_800A51AC, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A5444 = { D_800A5380, D_800A51C4, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A5458 = { D_800A5388, D_800A51DC, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A546C = { D_800A5390, D_800A51F4, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A5480 = { D_800A5398, D_800A520C, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A5494 = { D_800A53A0, D_800A5224, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A54A8 = { D_800A53A8, D_800A523C, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A54BC = { D_800A53B0, D_800A5254, 0x38, 6, 88, 332, 3 };
FieldActorEntry D_800A54D0 = { D_800A53B8, D_800A526C, 0x3F, 7, 145, 289, 7 };
FieldActorEntry D_800A54E4 = { D_800A53C4, D_800A5290, 0x3F, 7, 145, 289, 7 };
FieldActorEntry D_800A54F8 = { D_800A53CC, D_800A52F0, 0x3F, 7, 145, 289, 7 };
FieldActorEntry D_800A550C = { D_800A53D8, D_800A5350, 0x9D, 8, 88, 332, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A53E0,
    &D_800A53F4,
    &D_800A5408,
    &D_800A541C,
    &D_800A5430,
    &D_800A5444,
    &D_800A5458,
    &D_800A546C,
    &D_800A5480,
    &D_800A5494,
    &D_800A54A8,
    &D_800A54BC,
    &D_800A54D0,
    &D_800A54E4,
    &D_800A54F8,
    &D_800A550C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 78, 77, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 97, 115, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 135, 231, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 141, 44, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 261, 63, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 326, 95, 0, 0 },
    { 1, 0, 0x40, 2, 7, 2, 0, 1, 4, 0, 165, 76, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 256, 151, 184, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 215, 20, 86, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 144, 185, 200, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 125, 175, 194, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 148, 127, 167, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 240, 127, 162, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20C, 0x96, 0x114, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x2A0, 0x17A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20F, 0x15A, 0xBA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20B, 0x146, 0xBA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xC8, 0xEC, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xB8, 0x132, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1200, D_800A4E30, EVENT_TEXT(0x2A), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
