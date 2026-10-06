#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    FLAGS_00.applyAction(0x40A8, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x5AE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5BE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x19500, 0xD000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern BattleList D_800A4FF4;
extern BattleList D_800A5078;
extern BattleList D_800A50FC;
extern BattleList D_800A5180;
extern u16 D_800A52C0[];
extern u16 D_800A52C8[];
extern u16 D_800A52D4[];
extern u16 D_800A5450[];
extern FieldTalk D_800A52DC[];
extern u16 D_800A5458[];
extern FieldTalk D_800A52F4[];
extern u16 D_800A5464[];
extern FieldTalk D_800A530C[];
extern u16 D_800A546C[];
extern FieldTalk D_800A5324[];
extern FieldTalk D_800A533C[];
extern u16 D_800A5478[];
extern FieldTalk D_800A5354[];
extern u16 D_800A5484[];
extern FieldTalk D_800A536C[];
extern u16 D_800A5490[];
extern FieldTalk D_800A5384[];
extern u16 D_800A5498[];
extern FieldTalk D_800A539C[];
extern u16 D_800A54A0[];
extern FieldTalk D_800A53B4[];
extern u16 D_800A54AC[];
extern FieldTalk D_800A53CC[];
extern u16 D_800A54B4[];
extern FieldTalk D_800A53E4[];
extern u16 D_800A54C0[];
extern FieldTalk D_800A53FC[];
extern u16 D_800A54C8[];
extern FieldTalk D_800A5414[];
extern u16 D_800A54D0[];
extern FieldTalk D_800A542C[];
extern FieldActorEntry D_800A54DC;
extern FieldActorEntry D_800A54F0;
extern FieldActorEntry D_800A5504;
extern FieldActorEntry D_800A5518;
extern FieldActorEntry D_800A552C;
extern FieldActorEntry D_800A5540;
extern FieldActorEntry D_800A5554;
extern FieldActorEntry D_800A5568;
extern FieldActorEntry D_800A557C;
extern FieldActorEntry D_800A5590;
extern FieldActorEntry D_800A55A4;
extern FieldActorEntry D_800A55B8;
extern FieldActorEntry D_800A55CC;
extern FieldActorEntry D_800A55E0;
extern FieldActorEntry D_800A55F4;
extern s16 D_800A4EA4[];

s16 D_800A4EA4[] = {
    0x102, 2, 0x501, 0xD9, 7,
    0x100, 0x132, 0x521, 0xE9,
    0x101, 0x132, 1, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 7,
    0x101, 0x323, 0x325, 0x132,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x132,
    0x300, 0x1E,
    0x200, 0, 1, 0x132, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x132, 1,
    0x301,
    0x101, 0x132, 1, 7,
    0x300, 0x1E,
    0x102, 0x132, 0x560, 0x109, 7,
    0x302, 0x132,
    0x101, 0x132, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x132, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x548, 0xFC, 7,
    0x302, 2,
    0x102, 2, 0x588, 0xDC, 5,
    0x302, 2,
    0x200, 0, 4, 2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
Battle D_800A4F94 = { 109, 8, 0x60080000 };
Battle D_800A4FA0 = { 109, 8, 0x60080000 };
Battle D_800A4FAC = { 109, 8, 0x60080000 };
Battle D_800A4FB8 = { 176, 8, 0x60080000 };
Battle D_800A4FC4 = { 176, 8, 0x60080000 };
Battle D_800A4FD0 = { 176, 8, 0x60080000 };
Battle D_800A4FDC = { 157, 8, 0x60080000 };
Battle D_800A4FE8 = { 157, 8, 0x60080000 };
BattleList D_800A4FF4 = {
    3,
    { &D_800A4F94, &D_800A4FA0, &D_800A4FAC, &D_800A4FB8,
      &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8 },
};
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
BattleList D_800A5078 = {
    0,
    { &D_800A5018, &D_800A5024, &D_800A5030, &D_800A503C,
      &D_800A5048, &D_800A5054, &D_800A5060, &D_800A506C },
};
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 0, 0, 0x60040000 };
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
BattleList D_800A50FC = {
    0,
    { &D_800A509C, &D_800A50A8, &D_800A50B4, &D_800A50C0,
      &D_800A50CC, &D_800A50D8, &D_800A50E4, &D_800A50F0 },
};
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 331, 8, 0x60080000 };
Battle D_800A5150 = { 332, 8, 0x60080000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 177, 8, 0x60080000 };
Battle D_800A5174 = { 106, 8, 0x60080000 };
BattleList D_800A5180 = {
    0,
    { &D_800A5120, &D_800A512C, &D_800A5138, &D_800A5144,
      &D_800A5150, &D_800A515C, &D_800A5168, &D_800A5174 },
};
FieldBattles stageBattles[] = {
    { 75, 0, 0, { &D_800A4FF4, &D_800A5078, &D_800A50FC, &D_800A5180 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x170, 0xE0, 0x70, 0x170, 0x1FF },
    { 0x140, 0x100, 0x164, 0x1B0, 0x90, 0xB0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x1B0, 0xB0, 0xB0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x1B0, 0xD0, 0xB0, 0x160, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x156, 0x1C0, 0x58, 0xC0, 0x170, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1CB, 0, 0xCB, 0x160, 0x1FC },
    { 0x140, 0x100, 0x176, 0x1D8, 0xD8, 0xD8, 0x170, 0x1FC },
    { 0x180, 0x100, 0x194, 0x100, 0x150, 0, 0x150, 0x1FB },
    { 0x140, 0x100, 0x148, 0x1CB, 0x20, 0xCB, 0x160, 0x1FB },
};
u16 D_800A52C0[] = { 0x1A35, 0, 0xFFFF };
u16 D_800A52C8[] = { 0x904A, 1, 0x1A35, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x1A35, 1, 0xFFFF };
FieldTalk D_800A52DC[] = {
    { NULL, NULL, 0x102 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F4[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A530C[] = {
    { NULL, NULL, 0x101 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5324[] = {
    { NULL, NULL, 0xFC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A533C[] = {
    { NULL, NULL, 0xFA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5354[] = {
    { NULL, NULL, 0x327 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A536C[] = {
    { NULL, NULL, 0x326 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5384[] = {
    { NULL, NULL, 0x324 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A539C[] = {
    { NULL, NULL, 0x32A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B4[] = {
    { NULL, NULL, 0xFB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53CC[] = {
    { NULL, NULL, 0xFD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E4[] = {
    { NULL, NULL, 0xFE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53FC[] = {
    { NULL, NULL, 0x100 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5414[] = {
    { NULL, NULL, 0x324 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A542C[] = {
    { D_800A52C0, D_800A52C8, 0x325 },
    { D_800A52D4, NULL, 0x326 },
    { NULL, NULL, 0 },
};
u16 D_800A5450[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5458[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5464[] = { 0x602B, 1, 0xFFFF };
u16 D_800A546C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5478[] = { 0x601C, 0, 0x701F, 1, 0xFFFF };
u16 D_800A5484[] = { 0x601C, 1, 0x1A35, 1, 0xFFFF };
u16 D_800A5490[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5498[] = { 0x701F, 1, 0xFFFF };
u16 D_800A54A0[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A54AC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A54B4[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A54C0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A54C8[] = { 0x601B, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x1A35, 0, 0x601C, 1, 0xFFFF };
FieldActorEntry D_800A54DC = { D_800A5450, D_800A52DC, 0x2D, 4, 944, 185, 1 };
FieldActorEntry D_800A54F0 = { D_800A5458, D_800A52F4, 0x31, 5, 1394, 778, 7 };
FieldActorEntry D_800A5504 = { D_800A5464, D_800A530C, 0x33, 6, 1394, 778, 7 };
FieldActorEntry D_800A5518 = { D_800A546C, D_800A5324, 0x34, 7, 944, 185, 1 };
FieldActorEntry D_800A552C = { NULL, D_800A533C, 0x3F, 8, 529, 249, 1 };
FieldActorEntry D_800A5540 = { D_800A5478, D_800A5354, 0x45, 9, 1376, 265, 7 };
FieldActorEntry D_800A5554 = { D_800A5484, D_800A536C, 0x45, 9, 1376, 265, 7 };
FieldActorEntry D_800A5568 = { D_800A5490, D_800A5384, 0x46, 0xA, 1344, 208, 3 };
FieldActorEntry D_800A557C = { D_800A5498, D_800A539C, 0x46, 0xA, 1344, 208, 5 };
FieldActorEntry D_800A5590 = { D_800A54A0, D_800A53B4, 0x9D, 0xB, 944, 185, 1 };
FieldActorEntry D_800A55A4 = { D_800A54AC, D_800A53CC, 0x9D, 0xB, 944, 185, 1 };
FieldActorEntry D_800A55B8 = { D_800A54B4, D_800A53E4, 0x9E, 0xC, 1394, 778, 7 };
FieldActorEntry D_800A55CC = { D_800A54C0, D_800A53FC, 0x9E, 0xC, 1394, 778, 7 };
FieldActorEntry D_800A55E0 = { D_800A54C8, D_800A5414, 0x132, 0xD, 1313, 233, 3 };
FieldActorEntry D_800A55F4 = { D_800A54D0, D_800A542C, 0x132, 0xD, 1313, 233, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A54DC,
    &D_800A54F0,
    &D_800A5504,
    &D_800A5518,
    &D_800A552C,
    &D_800A5540,
    &D_800A5554,
    &D_800A5568,
    &D_800A557C,
    &D_800A5590,
    &D_800A55A4,
    &D_800A55B8,
    &D_800A55CC,
    &D_800A55E0,
    &D_800A55F4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x4B, 2, 0, 3, 6, 0, 1729, 477, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1400, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1448, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1456, 145, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1496, 69, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1504, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1544, 45, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1552, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1592, 21, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1600, 73, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1640, -3, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1648, 49, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1688, -27, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1696, 25, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1744, 1, 0, 0 },
    { 1, 0, 0x40, 2, 0x4E, 2, 0, 5, 8, 0, 1792, -23, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 308, 158, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 924, 626, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 1732, 319, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 1620, 640, 0, 0 },
    { 1, 0, 0x4E, 2, 0xA, 0, 0, 0, 0, 0, 1664, 384, 0, 0 },
    { 1, 0, 0x50, 2, 2, 0, 0, 0, 0, 0, 1536, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 1083, 205, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 1107, 467, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 1648, 565, 0, 0 },
    { 1, 0, 0x40, 6, 0x4C, 2, 0, 3, 6, 0, 1800, 729, 0, 0 },
    { 1, 0, 0x40, 6, 0x4D, 2, 0, 3, 6, 0, 1255, 43, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 460, 369, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 914, 808, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 935, 499, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 962, 255, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1379, 661, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1508, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 661, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 683, 653, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 941, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1136, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1322, 331, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 516, 208, 247, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 326, 181, 289, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 448, 159, 159, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 183, 183, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 544, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 640, 191, 191, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 703, 183, 183, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 816, 159, 159, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 912, 151, 151, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 976, 599, 599, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1056, 143, 143, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1120, 143, 143, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1456, 711, 711, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1488, 743, 743, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1503, 687, 687, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1536, 719, 719, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A9, 0x48E, 0x3F8, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AB, 0xA0, 0x390, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A7, 0x3E8, 0x9C, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 0xE, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFD0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x20, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 0xE, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 745, D_800A4EA4, EVENT_TEXT(0x2C), NULL, func_800A4D4C },
    { -1, NULL, 0, NULL, NULL },
};
