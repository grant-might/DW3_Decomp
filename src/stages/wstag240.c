#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x197
#define STAGE_ARCHIVE 0x2B3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x1A5
#define STAGE_ARCHIVE 0x2C2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xB300, 0xFF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F14[];
extern u16 D_800A4F1C[];
extern u16 D_800A4F24[];
extern FieldTalk D_800A4F2C[];
extern FieldTalk D_800A4F44[];
extern FieldTalk D_800A4F5C[];
extern u16 D_800A50A0[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A50A8[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A50B0[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A50B8[];
extern FieldTalk D_800A4FBC[];
extern u16 D_800A50C0[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A50C8[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A50D0[];
extern FieldTalk D_800A5004[];
extern u16 D_800A50D8[];
extern FieldTalk D_800A501C[];
extern u16 D_800A50E0[];
extern FieldTalk D_800A5034[];
extern u16 D_800A50E8[];
extern FieldTalk D_800A504C[];
extern u16 D_800A50F0[];
extern FieldTalk D_800A5064[];
extern u16 D_800A50FC[];
extern FieldTalk D_800A5088[];
extern FieldActorEntry D_800A5104;
extern FieldActorEntry D_800A5118;
extern FieldActorEntry D_800A512C;
extern FieldActorEntry D_800A5140;
extern FieldActorEntry D_800A5154;
extern FieldActorEntry D_800A5168;
extern FieldActorEntry D_800A517C;
extern FieldActorEntry D_800A5190;
extern FieldActorEntry D_800A51A4;
extern FieldActorEntry D_800A51B8;
extern FieldActorEntry D_800A51CC;
extern FieldActorEntry D_800A51E0;
extern FieldActorEntry D_800A51F4;
extern FieldActorEntry D_800A5208;
extern FieldActorEntry D_800A521C;
extern FieldActorEntry D_800A5230;
extern FieldActorEntry D_800A5244;
extern FieldActorEntry D_800A5258;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x14A, 0x100, 0x28, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x140, 0x1FD },
    { 0x140, 0x100, 0x164, 0x100, 0x90, 0, 0x150, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4F14[] = { 0x1C44, 0, 0xFFFF };
u16 D_800A4F1C[] = { 0x1C44, 1, 0xFFFF };
u16 D_800A4F24[] = { 0x1C44, 1, 0xFFFF };
FieldTalk D_800A4F2C[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F44[] = {
    { NULL, NULL, 0x21 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F5C[] = {
    { NULL, NULL, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x42F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x431 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { NULL, NULL, 0x433 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FBC[] = {
    { NULL, NULL, 0x42C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x42D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, NULL, 0x42E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0x430 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0x432 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0x435 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { D_800A4F14, D_800A4F1C, 0xB9 },
    { D_800A4F24, NULL, 0xC6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5088[] = {
    { NULL, NULL, 0x434 },
    { NULL, NULL, 0 },
};
u16 D_800A50A0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A50A8[] = { 0x7018, 1, 0xFFFF };
u16 D_800A50B0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A50B8[] = { 0x7015, 1, 0xFFFF };
u16 D_800A50C0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A50C8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A50D0[] = { 0x6016, 1, 0xFFFF };
u16 D_800A50D8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A50E0[] = { 0x6004, 1, 0xFFFF };
u16 D_800A50E8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A50F0[] = { 0x818F, 0, 0x6006, 1, 0xFFFF };
u16 D_800A50FC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5104 = { NULL, D_800A4F2C, 0x28, 4, 135, 212, 7 };
FieldActorEntry D_800A5118 = { NULL, D_800A4F44, 0x29, 5, 173, 155, 7 };
FieldActorEntry D_800A512C = { NULL, D_800A4F5C, 0x2A, 6, 56, 193, 1 };
FieldActorEntry D_800A5140 = { D_800A50A0, D_800A4F74, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A5154 = { D_800A50A8, D_800A4F8C, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A5168 = { D_800A50B0, D_800A4FA4, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A517C = { D_800A50B8, D_800A4FBC, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A5190 = { D_800A50C0, D_800A4FD4, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A51A4 = { D_800A50C8, D_800A4FEC, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A51B8 = { D_800A50D0, D_800A5004, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A51CC = { D_800A50D8, D_800A501C, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A51E0 = { D_800A50E0, D_800A5034, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A51F4 = { D_800A50E8, D_800A504C, 0x2D, 7, 224, 169, 7 };
FieldActorEntry D_800A5208 = { D_800A50F0, D_800A5064, 0x40, 8, 344, 172, 5 };
FieldActorEntry D_800A521C = { D_800A50FC, D_800A5088, 0x9D, 9, 224, 169, 7 };
FieldActorEntry D_800A5230 = { NULL, NULL, 0xDD, 0xA, 184, 173, 7 };
FieldActorEntry D_800A5244 = { NULL, NULL, 0xDE, 0xB, 143, 240, 7 };
FieldActorEntry D_800A5258 = { NULL, NULL, 0xDF, 0xC, 64, 224, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5104,
    &D_800A5118,
    &D_800A512C,
    &D_800A5140,
    &D_800A5154,
    &D_800A5168,
    &D_800A517C,
    &D_800A5190,
    &D_800A51A4,
    &D_800A51B8,
    &D_800A51CC,
    &D_800A51E0,
    &D_800A51F4,
    &D_800A5208,
    &D_800A521C,
    &D_800A5230,
    &D_800A5244,
    &D_800A5258,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 62, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 124, 173, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 218, 227, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 242, 146, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 295, 210, 0, 0 },
    { 1, 0, 0x40, 2, 1, 2, 0, 1, 4, 0, 227, 130, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20A, 0xD8, 0x54, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0xF0, 0xBF, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x120, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x12F, 0xAE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
