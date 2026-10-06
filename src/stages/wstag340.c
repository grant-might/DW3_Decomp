#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x392
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x3A2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x30700, 0x9A00};
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
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress < 0xB) {
        D_800990B4.battles = &stageBattles[0];
    } else {
        D_800990B4.battles = &stageBattles[1];
    }
}

extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52D0;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern Battle D_800A5348;
extern Battle D_800A5354;
extern BattleList D_800A4FC4;
extern BattleList D_800A5048;
extern BattleList D_800A50CC;
extern BattleList D_800A5150;
extern BattleList D_800A51D4;
extern BattleList D_800A5258;
extern BattleList D_800A52DC;
extern BattleList D_800A5360;
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A544C[];
extern u16 D_800A5458[];
extern u16 D_800A5468[];
extern u16 D_800A5470[];
extern u16 D_800A5484[];
extern u16 D_800A5490[];
extern u16 D_800A54A4[];
extern u16 D_800A54AC[];
extern u16 D_800A54B4[];
extern u16 D_800A54C0[];
extern u16 D_800A54D0[];
extern u16 D_800A54D8[];
extern u16 D_800A54EC[];
extern u16 D_800A54F8[];
extern u16 D_800A55E4[];
extern FieldTalk D_800A550C[];
extern u16 D_800A55EC[];
extern FieldTalk D_800A5524[];
extern u16 D_800A55F8[];
extern FieldTalk D_800A553C[];
extern u16 D_800A5604[];
extern FieldTalk D_800A5584[];
extern u16 D_800A5610[];
extern FieldTalk D_800A55CC[];
extern FieldActorEntry D_800A561C;
extern FieldActorEntry D_800A5630;
extern FieldActorEntry D_800A5644;
extern FieldActorEntry D_800A5658;
extern FieldActorEntry D_800A566C;
extern s16 D_800A4EC8[];

s16 D_800A4EC8[] = {
    0x102, 2, 0x1C0, 0x270, 1,
    0x101, 0x11A, 7, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x11A, 1,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x78,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0x11A, 1,
    0x301,
    0x101, 0x11A, 7, 3,
    0x300, 0x1E,
    0x101, 0x11A, 1, 1,
    0x300, 0x1E,
    0,
};
Battle D_800A4F64 = { 39, 1, 0x60080000 };
Battle D_800A4F70 = { 39, 1, 0x60080000 };
Battle D_800A4F7C = { 39, 1, 0x60080000 };
Battle D_800A4F88 = { 39, 1, 0x60080000 };
Battle D_800A4F94 = { 40, 1, 0x60080000 };
Battle D_800A4FA0 = { 40, 1, 0x60080000 };
Battle D_800A4FAC = { 40, 1, 0x60080000 };
Battle D_800A4FB8 = { 40, 1, 0x60080000 };
BattleList D_800A4FC4 = {
    3,
    { &D_800A4F64, &D_800A4F70, &D_800A4F7C, &D_800A4F88,
      &D_800A4F94, &D_800A4FA0, &D_800A4FAC, &D_800A4FB8 },
};
Battle D_800A4FE8 = { 37, 2, 0x60080000 };
Battle D_800A4FF4 = { 37, 2, 0x60080000 };
Battle D_800A5000 = { 37, 2, 0x60080000 };
Battle D_800A500C = { 37, 2, 0x60080000 };
Battle D_800A5018 = { 37, 2, 0x60080000 };
Battle D_800A5024 = { 37, 2, 0x60080000 };
Battle D_800A5030 = { 37, 2, 0x60080000 };
Battle D_800A503C = { 37, 2, 0x60080000 };
BattleList D_800A5048 = {
    3,
    { &D_800A4FE8, &D_800A4FF4, &D_800A5000, &D_800A500C,
      &D_800A5018, &D_800A5024, &D_800A5030, &D_800A503C },
};
Battle D_800A506C = { 0, 0, 0x60040000 };
Battle D_800A5078 = { 0, 0, 0x60040000 };
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
BattleList D_800A50CC = {
    0,
    { &D_800A506C, &D_800A5078, &D_800A5084, &D_800A5090,
      &D_800A509C, &D_800A50A8, &D_800A50B4, &D_800A50C0 },
};
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 327, 13, 0x60080000 };
Battle D_800A5120 = { 328, 2, 0x60080000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 49, 13, 0x60080000 };
Battle D_800A5144 = { 54, 2, 0x60080000 };
BattleList D_800A5150 = {
    0,
    { &D_800A50F0, &D_800A50FC, &D_800A5108, &D_800A5114,
      &D_800A5120, &D_800A512C, &D_800A5138, &D_800A5144 },
};
Battle D_800A5174 = { 39, 1, 0x60080000 };
Battle D_800A5180 = { 39, 1, 0x60080000 };
Battle D_800A518C = { 39, 1, 0x60080000 };
Battle D_800A5198 = { 39, 1, 0x60080000 };
Battle D_800A51A4 = { 40, 1, 0x60080000 };
Battle D_800A51B0 = { 40, 1, 0x60080000 };
Battle D_800A51BC = { 40, 1, 0x60080000 };
Battle D_800A51C8 = { 40, 1, 0x60080000 };
BattleList D_800A51D4 = {
    3,
    { &D_800A5174, &D_800A5180, &D_800A518C, &D_800A5198,
      &D_800A51A4, &D_800A51B0, &D_800A51BC, &D_800A51C8 },
};
Battle D_800A51F8 = { 59, 2, 0x60080000 };
Battle D_800A5204 = { 59, 2, 0x60080000 };
Battle D_800A5210 = { 59, 2, 0x60080000 };
Battle D_800A521C = { 59, 2, 0x60080000 };
Battle D_800A5228 = { 59, 2, 0x60080000 };
Battle D_800A5234 = { 59, 2, 0x60080000 };
Battle D_800A5240 = { 59, 2, 0x60080000 };
Battle D_800A524C = { 59, 2, 0x60080000 };
BattleList D_800A5258 = {
    3,
    { &D_800A51F8, &D_800A5204, &D_800A5210, &D_800A521C,
      &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C },
};
Battle D_800A527C = { 0, 0, 0x60040000 };
Battle D_800A5288 = { 0, 0, 0x60040000 };
Battle D_800A5294 = { 0, 0, 0x60040000 };
Battle D_800A52A0 = { 0, 0, 0x60040000 };
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
Battle D_800A52C4 = { 0, 0, 0x60040000 };
Battle D_800A52D0 = { 0, 0, 0x60040000 };
BattleList D_800A52DC = {
    0,
    { &D_800A527C, &D_800A5288, &D_800A5294, &D_800A52A0,
      &D_800A52AC, &D_800A52B8, &D_800A52C4, &D_800A52D0 },
};
Battle D_800A5300 = { 0, 0, 0x60040000 };
Battle D_800A530C = { 0, 0, 0x60040000 };
Battle D_800A5318 = { 0, 0, 0x60040000 };
Battle D_800A5324 = { 327, 13, 0x60080000 };
Battle D_800A5330 = { 328, 2, 0x60080000 };
Battle D_800A533C = { 0, 0, 0x60040000 };
Battle D_800A5348 = { 49, 13, 0x60080000 };
Battle D_800A5354 = { 54, 2, 0x60080000 };
BattleList D_800A5360 = {
    0,
    { &D_800A5300, &D_800A530C, &D_800A5318, &D_800A5324,
      &D_800A5330, &D_800A533C, &D_800A5348, &D_800A5354 },
};
FieldBattles stageBattles[] = {
    { 3, 0, 0, { &D_800A4FC4, &D_800A5048, &D_800A50CC, &D_800A5150 } },
    { 26, 1, 0, { &D_800A51D4, &D_800A5258, &D_800A52DC, &D_800A5360 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x181, 0xC8, 0x81, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x1A1, 0xC8, 0xA1, 0x160, 0x1FF },
};
u16 D_800A543C[] = { 0x1A36, 0, 0xFFFF };
u16 D_800A5444[] = { 0x1A36, 1, 0xFFFF };
u16 D_800A544C[] = { 0x1A36, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5458[] = { 0x1A36, 1, 0x703A, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5468[] = { 0x1A21, 1, 0xFFFF };
u16 D_800A5470[] = { 0x1A36, 1, 0x703A, 1, 0x8005, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5484[] = { 0x8005, 1, 0x9047, 1, 0xFFFF };
u16 D_800A5490[] = { 0x1A36, 1, 0x703A, 1, 0x8005, 1, 0x8192, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x1A36, 0, 0xFFFF };
u16 D_800A54AC[] = { 0x1A36, 1, 0xFFFF };
u16 D_800A54B4[] = { 0x8192, 0, 0x1A36, 1, 0xFFFF };
u16 D_800A54C0[] = { 0x1A36, 1, 0x8192, 1, 0x703A, 0, 0xFFFF };
u16 D_800A54D0[] = { 0x1A21, 1, 0xFFFF };
u16 D_800A54D8[] = { 0x8192, 1, 0x703A, 1, 0x8005, 0, 0x1A36, 1, 0xFFFF };
u16 D_800A54EC[] = { 0x8005, 1, 0x9047, 1, 0xFFFF };
u16 D_800A54F8[] = { 0x1A36, 1, 0x8192, 1, 0x703A, 1, 0x8005, 1, 0xFFFF };
FieldTalk D_800A550C[] = {
    { NULL, NULL, 0x293 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5524[] = {
    { NULL, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A553C[] = {
    { D_800A543C, D_800A5444, 0x28E },
    { D_800A544C, NULL, 0x28F },
    { D_800A5458, D_800A5468, 0x290 },
    { D_800A5470, D_800A5484, 0x291 },
    { D_800A5490, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5584[] = {
    { D_800A54A4, D_800A54AC, 0x28E },
    { D_800A54B4, NULL, 0x28F },
    { D_800A54C0, D_800A54D0, 0x290 },
    { D_800A54D8, D_800A54EC, 0x291 },
    { D_800A54F8, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55CC[] = {
    { NULL, NULL, 0x292 },
    { NULL, NULL, 0 },
};
u16 D_800A55E4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A55EC[] = { 0x7022, 1, 0x8005, 1, 0xFFFF };
u16 D_800A55F8[] = { 0x7022, 1, 0x8005, 0, 0xFFFF };
u16 D_800A5604[] = { 0x602B, 1, 0x8005, 0, 0xFFFF };
u16 D_800A5610[] = { 0x602B, 1, 0x8005, 1, 0xFFFF };
FieldActorEntry D_800A561C = { D_800A55E4, D_800A550C, 0x9D, 4, 412, 642, 1 };
FieldActorEntry D_800A5630 = { D_800A55EC, D_800A5524, 0x11A, 5, 412, 642, 1 };
FieldActorEntry D_800A5644 = { D_800A55F8, D_800A553C, 0x11A, 5, 412, 642, 1 };
FieldActorEntry D_800A5658 = { D_800A5604, D_800A5584, 0x11A, 5, 412, 642, 1 };
FieldActorEntry D_800A566C = { D_800A5610, D_800A55CC, 0x11A, 5, 412, 642, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A561C,
    &D_800A5630,
    &D_800A5644,
    &D_800A5658,
    &D_800A566C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 5, 1, 5, 0xA, 8, 0, 395, 85, 0, 0 },
    { 1, 0, 0x40, 2, 5, 1, 5, 0xA, 8, 0, 698, 285, 0, 0 },
    { 1, 0, 0x50, 2, 0xB, 0, 0, 0, 0, 0, 688, 97, 0, 0 },
    { 1, 0, 0x72, 2, 0xC, 0, 0, 0, 0, 0, 784, 47, 0, 0 },
    { 1, 0, 0x80, 2, 0xD, 0, 0, 0, 0, 0, 640, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 72, 562, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 271, 529, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 677, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 224, 557, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 309, 704, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 290, 716, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 698, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 83, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 47, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 146, 531, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 37, 375, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 90, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 218, 638, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 75, 550, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 96, 549, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 182, 545, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 288, 706, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 310, 714, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 321, 691, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 494, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 514, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 671, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 799, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 811, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 817, 43, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 496, 558, 575, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 509, 517, 543, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 514, 471, 489, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 676, 390, 407, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 276, 499, 511, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 271, 271, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 239, 239, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 255, 255, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 390, 243, 243, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 247, 247, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 592, 343, 343, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 375, 375, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21D, 0x102, 0x3AC, 5, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 4, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x3C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x40, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1310, D_800A4EC8, EVENT_TEXT(0x26), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
