#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C14, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x210
#define STAGE_ARCHIVE 0x3C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x21F
#define STAGE_ARCHIVE 0x3D6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x19300, 0x14800};
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

extern u16 D_800A4FA8[];
extern u16 D_800A4FB0[];
extern u16 D_800A4FB8[];
extern u16 D_800A4FC0[];
extern u16 D_800A4FC8[];
extern u16 D_800A4FD0[];
extern u16 D_800A4FD8[];
extern u16 D_800A4FE0[];
extern u16 D_800A4FE8[];
extern u16 D_800A4FF0[];
extern u16 D_800A4FF8[];
extern u16 D_800A5000[];
extern u16 D_800A5008[];
extern FieldTalk D_800A5010[];
extern FieldTalk D_800A5034[];
extern u16 D_800A5190[];
extern FieldTalk D_800A5058[];
extern u16 D_800A5198[];
extern FieldTalk D_800A5070[];
extern u16 D_800A51A0[];
extern FieldTalk D_800A5094[];
extern u16 D_800A51A8[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A50DC[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A50F4[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A510C[];
extern u16 D_800A51D4[];
extern FieldTalk D_800A5124[];
extern u16 D_800A51E0[];
extern FieldTalk D_800A513C[];
extern u16 D_800A51E8[];
extern FieldTalk D_800A5154[];
extern u16 D_800A51F8[];
extern FieldTalk D_800A5178[];
extern FieldActorEntry D_800A5200;
extern FieldActorEntry D_800A5214;
extern FieldActorEntry D_800A5228;
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
extern s16 D_800A4E64[];

s16 D_800A4E64[] = {
    0x102, 2, 0x99, 0xB5, 3,
    0x100, 0x15, 0x79, 0xA5,
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
    0x304, 0xC12, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x166, 0, 0x66, 0x150, 0x1FB },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FB },
    { 0x140, 0x100, 0x168, 0x169, 0xA0, 0x69, 0x170, 0x1FB },
    { 0x140, 0x100, 0x15A, 0x16C, 0x68, 0x6C, 0x140, 0x1FA },
    { 0x140, 0x100, 0x148, 0x16D, 0x20, 0x6D, 0x150, 0x1FA },
    { 0x140, 0x100, 0x150, 0x16D, 0x40, 0x6D, 0x160, 0x1FA },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4FA8[] = { 0x1A08, 0, 0xFFFF };
u16 D_800A4FB0[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4FB8[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4FC0[] = { 0x7A1F, 1, 0xFFFF };
u16 D_800A4FC8[] = { 0x1A09, 0, 0xFFFF };
u16 D_800A4FD0[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4FD8[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4FE0[] = { 0x9011, 1, 0xFFFF };
u16 D_800A4FE8[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A4FF0[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A4FF8[] = { 0x1C45, 0, 0xFFFF };
u16 D_800A5000[] = { 0x1C45, 1, 0xFFFF };
u16 D_800A5008[] = { 0x1C45, 1, 0xFFFF };
FieldTalk D_800A5010[] = {
    { D_800A4FA8, D_800A4FB0, 0x16A },
    { D_800A4FB8, D_800A4FC0, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { D_800A4FC8, D_800A4FD0, 0x169 },
    { D_800A4FD8, D_800A4FE0, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5058[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5070[] = {
    { D_800A4FE8, NULL, 0x23F },
    { D_800A4FF0, NULL, 0x2F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0x242 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, NULL, 0x241 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0x240 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0x23F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F4[] = {
    { NULL, NULL, 0x23E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A510C[] = {
    { NULL, NULL, 0x23D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5124[] = {
    { NULL, NULL, 0x23C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A513C[] = {
    { NULL, NULL, 0x23B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5154[] = {
    { D_800A4FF8, D_800A5000, 0x2E6 },
    { D_800A5008, NULL, 0x327 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5178[] = {
    { NULL, NULL, 0x243 },
    { NULL, NULL, 0 },
};
u16 D_800A5190[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5198[] = { 0x6014, 1, 0xFFFF };
u16 D_800A51A0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A51C4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x7015, 1, 0x6006, 0, 0xFFFF };
u16 D_800A51E0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x818F, 0, 0x1C44, 1, 0x6006, 1, 0xFFFF };
u16 D_800A51F8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5200 = { NULL, D_800A5010, 0x14, 4, 345, 308, 7 };
FieldActorEntry D_800A5214 = { NULL, D_800A5034, 0x15, 5, 121, 165, 7 };
FieldActorEntry D_800A5228 = { D_800A5190, D_800A5058, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A523C = { D_800A5198, D_800A5070, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A5250 = { D_800A51A0, D_800A5094, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A5264 = { D_800A51A8, D_800A50AC, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A5278 = { D_800A51B0, D_800A50C4, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A528C = { D_800A51B8, D_800A50DC, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A52A0 = { D_800A51C4, D_800A50F4, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A52B4 = { D_800A51CC, D_800A510C, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A52C8 = { D_800A51D4, D_800A5124, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A52DC = { D_800A51E0, D_800A513C, 0x2E, 6, 177, 153, 3 };
FieldActorEntry D_800A52F0 = { D_800A51E8, D_800A5154, 0x40, 7, 177, 153, 3 };
FieldActorEntry D_800A5304 = { NULL, NULL, 0x78, 8, 374, 268, 5 };
FieldActorEntry D_800A5318 = { D_800A51F8, D_800A5178, 0x9D, 9, 177, 153, 3 };
FieldActorEntry D_800A532C = { NULL, NULL, 0xDB, 0xA, 346, 325, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5200,
    &D_800A5214,
    &D_800A5228,
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 484, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 57, 39, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 89, 23, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 203, 224, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 272, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 292, 139, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 305, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 337, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 467, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 344, 109, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 321, 107, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 370, 108, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 289, 326, 340, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 294, 310, 332, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 322, 310, 325, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 337, 303, 317, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 351, 282, 309, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 375, 277, 301, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 383, 270, 293, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 400, 271, 285, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 415, 270, 282, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 77, 127, 175, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 109, 113, 158, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 141, 97, 142, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 174, 81, 127, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 257, 176, 209, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 255, 245, 263, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 239, 252, 272, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 420, 237, 278, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x222, 0x80, 0x31C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x224, 0x8C, 0xC2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0xFA, 0x126, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x10B, 0x188, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1457, D_800A4E64, EVENT_TEXT(0x33), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
