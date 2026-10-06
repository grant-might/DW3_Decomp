#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x507
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x517
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12000, 0x13400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5174[];
extern FieldTalk D_800A4F7C[];
extern u16 D_800A5180[];
extern FieldTalk D_800A4F94[];
extern u16 D_800A5188[];
extern FieldTalk D_800A4FAC[];
extern u16 D_800A5194[];
extern FieldTalk D_800A4FC4[];
extern u16 D_800A519C[];
extern FieldTalk D_800A4FDC[];
extern u16 D_800A51A4[];
extern FieldTalk D_800A4FF4[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A500C[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A5024[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A503C[];
extern u16 D_800A51D0[];
extern FieldTalk D_800A5054[];
extern u16 D_800A51D8[];
extern FieldTalk D_800A506C[];
extern u16 D_800A51E4[];
extern FieldTalk D_800A5084[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A509C[];
extern u16 D_800A51F8[];
extern FieldTalk D_800A50B4[];
extern u16 D_800A5200[];
extern FieldTalk D_800A50CC[];
extern u16 D_800A520C[];
extern FieldTalk D_800A50E4[];
extern FieldTalk D_800A50FC[];
extern u16 D_800A5214[];
extern FieldTalk D_800A5114[];
extern u16 D_800A5220[];
extern FieldTalk D_800A512C[];
extern u16 D_800A5228[];
extern FieldTalk D_800A5144[];
extern u16 D_800A5234[];
extern FieldTalk D_800A515C[];
extern FieldActorEntry D_800A523C;
extern FieldActorEntry D_800A5250;
extern FieldActorEntry D_800A5264;
extern FieldActorEntry D_800A5278;
extern FieldActorEntry D_800A528C;
extern FieldActorEntry D_800A52A0;
extern FieldActorEntry D_800A52B4;
extern FieldActorEntry D_800A52C8;
extern FieldActorEntry D_800A52DC;
extern FieldActorEntry D_800A52F0;
extern FieldActorEntry D_800A5304;
extern FieldActorEntry D_800A5318;
extern FieldActorEntry D_800A532C;
extern FieldActorEntry D_800A5340;
extern FieldActorEntry D_800A5354;
extern FieldActorEntry D_800A5368;
extern FieldActorEntry D_800A537C;
extern FieldActorEntry D_800A5390;
extern FieldActorEntry D_800A53A4;
extern FieldActorEntry D_800A53B8;
extern FieldActorEntry D_800A53CC;
extern FieldActorEntry D_800A53E0;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x1AA, 0x80, 0xAA, 0x170, 0x1FF },
    { 0x140, 0x100, 0x166, 0x182, 0x98, 0x82, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16E, 0x182, 0xB8, 0x82, 0x170, 0x1FE },
    { 0x140, 0x100, 0x176, 0x182, 0xD8, 0x82, 0x140, 0x1FD },
    { 0x140, 0x100, 0x150, 0x189, 0x40, 0x89, 0x160, 0x1FD },
    { 0x140, 0x100, 0x168, 0x1AA, 0xA0, 0xAA, 0x170, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1AA, 0xC0, 0xAA, 0x140, 0x1FC },
    { 0x140, 0x100, 0x148, 0x1B1, 0x20, 0xB1, 0x150, 0x1FC },
    { 0x140, 0x100, 0x150, 0x1B1, 0x40, 0xB1, 0x160, 0x1FC },
    { 0x140, 0x100, 0x158, 0x1CA, 0x60, 0xCA, 0x170, 0x1FC },
    { 0x140, 0x100, 0x160, 0x1CA, 0x80, 0xCA, 0x140, 0x1FB },
    { 0x140, 0x100, 0x158, 0x1A2, 0x60, 0xA2, 0x160, 0x1FB },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x170, 0x1CA, 0xC0, 0xCA, 0x170, 0x1FB },
    { 0x140, 0x100, 0x140, 0x1A9, 0, 0xA9, 0x140, 0x1FA },
};
FieldTalk D_800A4F7C[] = {
    { NULL, NULL, 0x8F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F94[] = {
    { NULL, NULL, 0x91 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FAC[] = {
    { NULL, NULL, 0x93 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC4[] = {
    { NULL, NULL, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FDC[] = {
    { NULL, NULL, 0xA0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF4[] = {
    { NULL, NULL, 0x97 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A500C[] = {
    { NULL, NULL, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5024[] = {
    { NULL, NULL, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A503C[] = {
    { NULL, NULL, 0x8E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5054[] = {
    { NULL, NULL, 0x90 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A506C[] = {
    { NULL, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5084[] = {
    { NULL, NULL, 0x9B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A509C[] = {
    { NULL, NULL, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50B4[] = {
    { NULL, NULL, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50CC[] = {
    { NULL, NULL, 0x96 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50E4[] = {
    { NULL, NULL, 0x98 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50FC[] = {
    { NULL, NULL, 0x1F6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5114[] = {
    { NULL, NULL, 0x9C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A512C[] = {
    { NULL, NULL, 0x9E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5144[] = {
    { NULL, NULL, 0x9D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A515C[] = {
    { NULL, NULL, 0x95 },
    { NULL, NULL, 0 },
};
u16 D_800A5174[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5180[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5188[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5194[] = { 0x602B, 1, 0xFFFF };
u16 D_800A519C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51A4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51D0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51D8[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51E4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51EC[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51F8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5200[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A520C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5214[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5220[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5228[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5234[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A523C = { D_800A5174, D_800A4F7C, 0x2E, 4, 471, 245, 5 };
FieldActorEntry D_800A5250 = { D_800A5180, D_800A4F94, 0x2E, 4, 471, 245, 5 };
FieldActorEntry D_800A5264 = { D_800A5188, D_800A4FAC, 0x2F, 5, 216, 277, 7 };
FieldActorEntry D_800A5278 = { D_800A5194, D_800A4FC4, 0x30, 6, 216, 277, 7 };
FieldActorEntry D_800A528C = { D_800A519C, D_800A4FDC, 0x35, 7, 264, 301, 3 };
FieldActorEntry D_800A52A0 = { D_800A51A4, D_800A4FF4, 0x38, 8, 264, 301, 3 };
FieldActorEntry D_800A52B4 = { D_800A51B0, D_800A500C, 0x39, 9, 352, 296, 5 };
FieldActorEntry D_800A52C8 = { D_800A51B8, D_800A5024, 0x3A, 0xA, 352, 296, 5 };
FieldActorEntry D_800A52DC = { D_800A51C4, D_800A503C, 0x9D, 0xB, 471, 245, 5 };
FieldActorEntry D_800A52F0 = { D_800A51D0, D_800A5054, 0x9D, 0xB, 471, 245, 5 };
FieldActorEntry D_800A5304 = { D_800A51D8, D_800A506C, 0x9E, 0xC, 352, 296, 5 };
FieldActorEntry D_800A5318 = { D_800A51E4, D_800A5084, 0x9E, 0xC, 352, 296, 5 };
FieldActorEntry D_800A532C = { D_800A51EC, D_800A509C, 0x9F, 0xD, 216, 277, 7 };
FieldActorEntry D_800A5340 = { D_800A51F8, D_800A50B4, 0x9F, 0xD, 216, 277, 7 };
FieldActorEntry D_800A5354 = { D_800A5200, D_800A50CC, 0xA0, 0xE, 264, 301, 3 };
FieldActorEntry D_800A5368 = { D_800A520C, D_800A50E4, 0xA0, 0xE, 264, 301, 3 };
FieldActorEntry D_800A537C = { NULL, D_800A50FC, 0x10B, 0xF, 353, 160, 7 };
FieldActorEntry D_800A5390 = { NULL, NULL, 0x10C, 0x10, 360, 172, 7 };
FieldActorEntry D_800A53A4 = { D_800A5214, D_800A5114, 0x119, 0x11, 305, 193, 7 };
FieldActorEntry D_800A53B8 = { D_800A5220, D_800A512C, 0x119, 0x11, 305, 193, 7 };
FieldActorEntry D_800A53CC = { D_800A5228, D_800A5144, 0x125, 0x12, 368, 224, 3 };
FieldActorEntry D_800A53E0 = { D_800A5234, D_800A515C, 0x125, 0x12, 305, 193, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A523C,
    &D_800A5250,
    &D_800A5264,
    &D_800A5278,
    &D_800A528C,
    &D_800A52A0,
    &D_800A52B4,
    &D_800A52C8,
    &D_800A52DC,
    &D_800A52F0,
    &D_800A5304,
    &D_800A5318,
    &D_800A532C,
    &D_800A5340,
    &D_800A5354,
    &D_800A5368,
    &D_800A537C,
    &D_800A5390,
    &D_800A53A4,
    &D_800A53B8,
    &D_800A53CC,
    &D_800A53E0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 427, 90, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 84, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 116, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 148, 98, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 272, 44, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 368, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 417, 91, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 453, 113, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 473, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 493, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 497, 124, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 4, 0, 292, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 400, 59, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 224, 68, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 392, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 416, 60, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 208, 263, 288, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 384, 191, 217, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 320, 169, 184, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 304, 161, 174, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 336, 161, 174, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 288, 153, 166, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 352, 153, 166, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 272, 144, 158, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 368, 145, 158, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x271, 0x180, 0xD8, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x281, 0x92, 0x1A2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x110, 0xB8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
