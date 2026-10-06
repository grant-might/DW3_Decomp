#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x226
#define STAGE_ARCHIVE 0x2C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x235
#define STAGE_ARCHIVE 0x2D5
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 2;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1DB00, 0x13C00};
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

extern u16 D_800A4F5C[];
extern u16 D_800A4F64[];
extern u16 D_800A4F6C[];
extern u16 D_800A4F74[];
extern u16 D_800A4F7C[];
extern u16 D_800A4F84[];
extern u16 D_800A4F8C[];
extern u16 D_800A4F94[];
extern u16 D_800A4F9C[];
extern u16 D_800A4FA4[];
extern u16 D_800A4FAC[];
extern u16 D_800A4FB4[];
extern u16 D_800A4FC0[];
extern FieldTalk D_800A4FC8[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A5190[];
extern FieldTalk D_800A5010[];
extern u16 D_800A5198[];
extern FieldTalk D_800A5028[];
extern u16 D_800A51A0[];
extern FieldTalk D_800A5040[];
extern u16 D_800A51A8[];
extern FieldTalk D_800A5058[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A5070[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A5088[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A50A0[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A50B8[];
extern u16 D_800A51D4[];
extern FieldTalk D_800A50D0[];
extern u16 D_800A51DC[];
extern FieldTalk D_800A50E8[];
extern u16 D_800A51E4[];
extern FieldTalk D_800A5100[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A5118[];
extern u16 D_800A51F4[];
extern FieldTalk D_800A5130[];
extern u16 D_800A51FC[];
extern FieldTalk D_800A5148[];
extern u16 D_800A5204[];
extern FieldTalk D_800A516C[];
extern FieldActorEntry D_800A520C;
extern FieldActorEntry D_800A5220;
extern FieldActorEntry D_800A5234;
extern FieldActorEntry D_800A5248;
extern FieldActorEntry D_800A525C;
extern FieldActorEntry D_800A5270;
extern FieldActorEntry D_800A5284;
extern FieldActorEntry D_800A5298;
extern FieldActorEntry D_800A52AC;
extern FieldActorEntry D_800A52C0;
extern FieldActorEntry D_800A52D4;
extern FieldActorEntry D_800A52E8;
extern FieldActorEntry D_800A52FC;
extern FieldActorEntry D_800A5310;
extern FieldActorEntry D_800A5324;
extern FieldActorEntry D_800A5338;
extern FieldActorEntry D_800A534C;
extern FieldActorEntry D_800A5360;
extern FieldActorEntry D_800A5374;
extern s16 D_800A4E38[];

s16 D_800A4E38[] = {
    0x102, 2, 0xA0, 0x148, 3,
    0x100, 0x15, 0x80, 0x138,
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
    0x304, 0xC03, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x195, 0xD8, 0x95, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B2, 0x173, 0x1C8, 0x73, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B4, 0x147, 0x1D0, 0x47, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x1A3, 0x1C0, 0xA3, 0x170, 0x1FC },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4F5C[] = { 0x1A08, 0, 0xFFFF };
u16 D_800A4F64[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F6C[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F74[] = { 0x7A21, 1, 0xFFFF };
u16 D_800A4F7C[] = { 0x1A09, 0, 0xFFFF };
u16 D_800A4F84[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4F8C[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4F94[] = { 0x900E, 1, 0xFFFF };
u16 D_800A4F9C[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A4FA4[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A4FAC[] = { 0, 0, 0xFFFF };
u16 D_800A4FB4[] = { 0x1C43, 1, 0, 1, 0xFFFF };
u16 D_800A4FC0[] = { 0, 1, 0xFFFF };
FieldTalk D_800A4FC8[] = {
    { D_800A4F5C, D_800A4F64, 0x16A },
    { D_800A4F6C, D_800A4F74, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { D_800A4F7C, D_800A4F84, 0x169 },
    { D_800A4F8C, D_800A4F94, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5010[] = {
    { NULL, NULL, 0x21 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5028[] = {
    { NULL, NULL, 0x111 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5040[] = {
    { NULL, NULL, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5058[] = {
    { NULL, NULL, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5070[] = {
    { NULL, NULL, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5088[] = {
    { NULL, NULL, 0x115 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A0[] = {
    { NULL, NULL, 0x116 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50B8[] = {
    { NULL, NULL, 0x118 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D0[] = {
    { NULL, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50E8[] = {
    { NULL, NULL, 0x11A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5100[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5118[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5130[] = {
    { NULL, NULL, 0x21 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5148[] = {
    { D_800A4F9C, NULL, 0x115 },
    { D_800A4FA4, NULL, 0x55 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A516C[] = {
    { D_800A4FAC, D_800A4FB4, 0x326 },
    { D_800A4FC0, NULL, 0x329 },
    { NULL, NULL, 0 },
};
u16 D_800A5190[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5198[] = { 0x600A, 1, 0xFFFF };
u16 D_800A51A0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A51C4[] = { 0x6018, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x7019, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A51DC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51E4[] = { 0x6019, 1, 0xFFFF };
u16 D_800A51EC[] = { 0x601A, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x6007, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x6014, 1, 0xFFFF };
u16 D_800A5204[] = { 0x6008, 1, 0xFFFF };
FieldActorEntry D_800A520C = { NULL, D_800A4FC8, 0x14, 4, 357, 278, 7 };
FieldActorEntry D_800A5220 = { NULL, D_800A4FEC, 0x15, 5, 128, 312, 7 };
FieldActorEntry D_800A5234 = { NULL, NULL, 0x78, 6, 368, 232, 5 };
FieldActorEntry D_800A5248 = { D_800A5190, D_800A5010, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A525C = { D_800A5198, D_800A5028, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5270 = { D_800A51A0, D_800A5040, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5284 = { D_800A51A8, D_800A5058, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5298 = { D_800A51B0, D_800A5070, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A52AC = { D_800A51B8, D_800A5088, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A52C0 = { D_800A51C4, D_800A50A0, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A52D4 = { D_800A51CC, D_800A50B8, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A52E8 = { D_800A51D4, D_800A50D0, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A52FC = { D_800A51DC, D_800A50E8, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5310 = { D_800A51E4, D_800A5100, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5324 = { D_800A51EC, D_800A5118, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5338 = { D_800A51F4, D_800A5130, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A534C = { D_800A51FC, D_800A5148, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5360 = { D_800A5204, D_800A516C, 0x79, 7, 289, 338, 7 };
FieldActorEntry D_800A5374 = { NULL, NULL, 0xDB, 8, 368, 296, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A520C,
    &D_800A5220,
    &D_800A5234,
    &D_800A5248,
    &D_800A525C,
    &D_800A5270,
    &D_800A5284,
    &D_800A5298,
    &D_800A52AC,
    &D_800A52C0,
    &D_800A52D4,
    &D_800A52E8,
    &D_800A52FC,
    &D_800A5310,
    &D_800A5324,
    &D_800A5338,
    &D_800A534C,
    &D_800A5360,
    &D_800A5374,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 249, 225, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 311, 194, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 472, 215, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 193, 297, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 257, 265, 0, 0 },
    { 1, 0, 0xFF, 2, 0xD, 0, 0, 0, 0, 0, 133, 187, 0, 0 },
    { 1, 0, 0xFF, 2, 0xD, 0, 0, 0, 0, 0, 277, 116, 0, 0 },
    { 1, 0, 0xFF, 2, 0xE, 0, 0, 0, 0, 0, 421, 44, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x237, 0x1BE, 0xBA, 7, 0, 0, 0 },
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
    { 1215, D_800A4E38, EVENT_TEXT(0x12), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
