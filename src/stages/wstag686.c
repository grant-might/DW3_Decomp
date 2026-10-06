#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x5EF
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x5FF
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x3D200, 0x13A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3C;
    D_800990B4.music = 0x60F00000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F2C[];
extern u16 D_800A4F34[];
extern u16 D_800A4F3C[];
extern u16 D_800A4F44[];
extern u16 D_800A4F4C[];
extern u16 D_800A4F54[];
extern u16 D_800A50F4[];
extern FieldTalk D_800A4F5C[];
extern u16 D_800A5100[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A510C[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A5118[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A5120[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A5128[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A5130[];
extern FieldTalk D_800A501C[];
extern u16 D_800A5138[];
extern FieldTalk D_800A5034[];
extern u16 D_800A5144[];
extern FieldTalk D_800A504C[];
extern u16 D_800A514C[];
extern FieldTalk D_800A5064[];
extern u16 D_800A5158[];
extern FieldTalk D_800A507C[];
extern u16 D_800A5160[];
extern FieldTalk D_800A5094[];
extern u16 D_800A516C[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A5174[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A517C[];
extern FieldTalk D_800A50DC[];
extern FieldActorEntry D_800A5184;
extern FieldActorEntry D_800A5198;
extern FieldActorEntry D_800A51AC;
extern FieldActorEntry D_800A51C0;
extern FieldActorEntry D_800A51D4;
extern FieldActorEntry D_800A51E8;
extern FieldActorEntry D_800A51FC;
extern FieldActorEntry D_800A5210;
extern FieldActorEntry D_800A5224;
extern FieldActorEntry D_800A5238;
extern FieldActorEntry D_800A524C;
extern FieldActorEntry D_800A5260;
extern FieldActorEntry D_800A5274;
extern FieldActorEntry D_800A5288;
extern FieldActorEntry D_800A529C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x158, 0xB8, 0x58, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x158, 0xD8, 0x58, 0x160, 0x1FF },
    { 0x140, 0x100, 0x164, 0x180, 0x90, 0x80, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x188, 0xB0, 0x88, 0x150, 0x1FE },
    { 0x140, 0x100, 0x174, 0x188, 0xD0, 0x88, 0x160, 0x1FE },
    { 0x140, 0x100, 0x14E, 0x18D, 0x38, 0x8D, 0x170, 0x1FE },
    { 0x140, 0x100, 0x156, 0x195, 0x58, 0x95, 0x140, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1A6, 0, 0xA6, 0x150, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x1A8, 0xB0, 0xA8, 0x160, 0x1FD },
    { 0x140, 0x100, 0x174, 0x1A8, 0xD0, 0xA8, 0x170, 0x1FD },
};
u16 D_800A4F2C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A4F34[] = { 0x6025, 1, 0xFFFF };
u16 D_800A4F3C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4F44[] = { 0x701D, 1, 0xFFFF };
u16 D_800A4F4C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A4F54[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A4F5C[] = {
    { NULL, NULL, 0x165 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x166 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x167 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { D_800A4F2C, NULL, 0x15B },
    { D_800A4F34, NULL, 0x15C },
    { D_800A4F3C, NULL, 0x15D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x15F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { D_800A4F44, NULL, 0x160 },
    { D_800A4F4C, NULL, 0x161 },
    { D_800A4F54, NULL, 0x162 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0x164 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, NULL, 0x169 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, NULL, 0x169 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0x16A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, NULL, 0x16A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0x163 },
    { NULL, NULL, 0 },
};
u16 D_800A50F4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5100[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A510C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5118[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5120[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5128[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5130[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5138[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5144[] = { 0x701A, 1, 0xFFFF };
u16 D_800A514C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5158[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5160[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A516C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5174[] = { 0x701A, 1, 0xFFFF };
u16 D_800A517C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5184 = { D_800A50F4, D_800A4F5C, 0x25, 4, 825, 269, 7 };
FieldActorEntry D_800A5198 = { D_800A5100, D_800A4F74, 0x26, 5, 560, 304, 7 };
FieldActorEntry D_800A51AC = { D_800A510C, D_800A4F8C, 0x27, 6, 376, 397, 1 };
FieldActorEntry D_800A51C0 = { D_800A5118, D_800A4FA4, 0x39, 7, 560, 448, 7 };
FieldActorEntry D_800A51D4 = { D_800A5120, D_800A4FD4, 0x39, 7, 560, 448, 7 };
FieldActorEntry D_800A51E8 = { D_800A5128, D_800A4FEC, 0x3A, 8, 1017, 309, 1 };
FieldActorEntry D_800A51FC = { D_800A5130, D_800A501C, 0x3A, 8, 584, 436, 7 };
FieldActorEntry D_800A5210 = { D_800A5138, D_800A5034, 0x9D, 9, 825, 269, 7 };
FieldActorEntry D_800A5224 = { D_800A5144, D_800A504C, 0x9D, 9, 825, 269, 7 };
FieldActorEntry D_800A5238 = { D_800A514C, D_800A5064, 0x9E, 0xA, 560, 304, 7 };
FieldActorEntry D_800A524C = { D_800A5158, D_800A507C, 0x9E, 0xA, 560, 304, 7 };
FieldActorEntry D_800A5260 = { D_800A5160, D_800A5094, 0x9F, 0xB, 376, 397, 1 };
FieldActorEntry D_800A5274 = { D_800A516C, D_800A50AC, 0x9F, 0xB, 376, 397, 1 };
FieldActorEntry D_800A5288 = { D_800A5174, D_800A50C4, 0xA0, 0xC, 560, 448, 7 };
FieldActorEntry D_800A529C = { D_800A517C, D_800A50DC, 0xA1, 0xD, 1017, 309, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5184,
    &D_800A5198,
    &D_800A51AC,
    &D_800A51C0,
    &D_800A51D4,
    &D_800A51E8,
    &D_800A51FC,
    &D_800A5210,
    &D_800A5224,
    &D_800A5238,
    &D_800A524C,
    &D_800A5260,
    &D_800A5274,
    &D_800A5288,
    &D_800A529C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 177, 76, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 244, 43, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 350, 54, 0, 0 },
    { 1, 0, 0x80, 6, 4, 0, 0, 0, 0, 0, 390, 289, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 1025, 223, 307, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 492, 452, 508, 0 },
    { 1, 0, 0x42, 4, 2, 0, 0, 0, 0, 0, 625, 443, 501, 0 },
    { 1, 0, 0x5B, 4, 3, 0, 0, 0, 0, 0, 639, 378, 454, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C7, 0x290, 0x1F0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x1C4, 0xA0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x1D5, 0x12C, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1BF, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1AF, 0x198, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
