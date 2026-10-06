#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5AA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5BA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x3A900, 0x37D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x35;
    D_800990B4.music = 0x60D40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern BattleList D_800A4EB0;
extern BattleList D_800A4F34;
extern BattleList D_800A4FB8;
extern BattleList D_800A503C;
extern u16 D_800A512C[];
extern u16 D_800A5134[];
extern u16 D_800A5140[];
extern u16 D_800A5148[];
extern u16 D_800A5158[];
extern u16 D_800A5168[];
extern u16 D_800A5248[];
extern FieldTalk D_800A517C[];
extern u16 D_800A5254[];
extern FieldTalk D_800A5194[];
extern u16 D_800A5260[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A526C[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A5274[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5280[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A5288[];
extern FieldTalk D_800A520C[];
extern FieldActorEntry D_800A529C;
extern FieldActorEntry D_800A52B0;
extern FieldActorEntry D_800A52C4;
extern FieldActorEntry D_800A52D8;
extern FieldActorEntry D_800A52EC;
extern FieldActorEntry D_800A5300;
extern FieldActorEntry D_800A5314;

Battle D_800A4E50 = { 109, 8, 0x60080000 };
Battle D_800A4E5C = { 109, 8, 0x60080000 };
Battle D_800A4E68 = { 176, 8, 0x60080000 };
Battle D_800A4E74 = { 176, 8, 0x60080000 };
Battle D_800A4E80 = { 95, 8, 0x60080000 };
Battle D_800A4E8C = { 95, 8, 0x60080000 };
Battle D_800A4E98 = { 95, 8, 0x60080000 };
Battle D_800A4EA4 = { 95, 8, 0x60080000 };
BattleList D_800A4EB0 = {
    3,
    { &D_800A4E50, &D_800A4E5C, &D_800A4E68, &D_800A4E74,
      &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4 },
};
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
BattleList D_800A4F34 = {
    0,
    { &D_800A4ED4, &D_800A4EE0, &D_800A4EEC, &D_800A4EF8,
      &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28 },
};
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
BattleList D_800A4FB8 = {
    0,
    { &D_800A4F58, &D_800A4F64, &D_800A4F70, &D_800A4F7C,
      &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC },
};
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 331, 8, 0x60080000 };
Battle D_800A500C = { 332, 8, 0x60080000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 177, 8, 0x60080000 };
Battle D_800A5030 = { 106, 8, 0x60080000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 76, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1EC, 0x100, 0x2B0, 0, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1F4, 0x100, 0x2D0, 0, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1E2, 0x118, 0x288, 0x18, 0x170, 0x1FE },
    { 0x1C0, 0x100, 0x1EA, 0x128, 0x2A8, 0x28, 0x150, 0x1FD },
    { 0x1C0, 0x100, 0x1C8, 0x118, 0x220, 0x18, 0x160, 0x1FD },
};
u16 D_800A512C[] = { 0x8667, 1, 0xFFFF };
u16 D_800A5134[] = { 0x8667, 0, 0, 0, 0xFFFF };
u16 D_800A5140[] = { 0, 1, 0xFFFF };
u16 D_800A5148[] = { 0x8667, 0, 0, 1, 0x8463, 0, 0xFFFF };
u16 D_800A5158[] = { 0x8667, 0, 0, 1, 0x8463, 1, 0xFFFF };
u16 D_800A5168[] = { 0x8667, 1, 0x8666, 0, 0x8463, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A517C[] = {
    { NULL, NULL, 0x104 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5194[] = {
    { NULL, NULL, 0x107 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51AC[] = {
    { NULL, NULL, 0x106 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x108 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x103 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { D_800A512C, NULL, 0x2DE },
    { D_800A5134, D_800A5140, 0x2DF },
    { D_800A5148, NULL, 0x2E0 },
    { D_800A5158, D_800A5168, 0x2E1 },
    { NULL, NULL, 0 },
};
u16 D_800A5248[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5254[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5260[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A526C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5274[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5280[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5288[] = { 0x7042, 1, 0x704A, 1, 0x8666, 1, 0x8667, 0, 0xFFFF };
FieldActorEntry D_800A529C = { D_800A5248, D_800A517C, 0x2F, 4, 561, 458, 7 };
FieldActorEntry D_800A52B0 = { D_800A5254, D_800A5194, 0x37, 5, 1049, 365, 1 };
FieldActorEntry D_800A52C4 = { D_800A5260, D_800A51AC, 0x9D, 6, 1049, 365, 1 };
FieldActorEntry D_800A52D8 = { D_800A526C, D_800A51C4, 0x9D, 6, 1049, 365, 1 };
FieldActorEntry D_800A52EC = { D_800A5274, D_800A51DC, 0x9E, 7, 561, 458, 7 };
FieldActorEntry D_800A5300 = { D_800A5280, D_800A51F4, 0x9E, 7, 561, 458, 7 };
FieldActorEntry D_800A5314 = { D_800A5288, D_800A520C, 0xA6, 8, 449, 1034, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A529C,
    &D_800A52B0,
    &D_800A52C4,
    &D_800A52D8,
    &D_800A52EC,
    &D_800A5300,
    &D_800A5314,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x70, 2, 0xA, 0, 0, 0, 0, 0, 896, 548, 0, 0 },
    { 1, 0, 0x78, 2, 0xB, 0, 0, 0, 0, 0, 768, 265, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 323, 130, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 548, 651, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 1011, 794, 0, 0 },
    { 1, 0, 0x40, 6, 0x62, 2, 0, 0xD, 0xA, 0, 902, 118, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 324, 437, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 480, 1007, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 1091, 911, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 259, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 452, 984, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 1034, 904, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x43, 0xA, 0, 121, 863, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x4E, 0xA, 0, 231, 1080, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x4E, 0xA, 0, 643, 1068, 0, 0 },
    { 1, 0, 0x64, 6, 0x14, 0, 0, 0, 0, 0, 177, 889, 0, 0 },
    { 1, 0, 0x64, 6, 0x15, 0, 0, 0, 0, 0, 31, 789, 0, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 103, 696, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 287, 790, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 319, 634, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 331, 860, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 425, 935, 1152, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 566, 586, 673, 0 },
    { 1, 0, 0x50, 4, 1, 0, 0, 0, 0, 0, 1013, 384, 452, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 959, 427, 502, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 310, 860, 900, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 448, 513, 569, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 592, 744, 782, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 992, 151, 200, 0 },
    { 1, 0, 0x64, 4, 0x12, 0, 0, 0, 0, 0, 445, 977, 1021, 0 },
    { 1, 0, 0x64, 4, 0x13, 0, 0, 0, 0, 0, 896, 756, 810, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 80, 759, 759, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 191, 191, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 223, 223, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 247, 247, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 368, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 447, 647, 647, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 439, 439, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 615, 615, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 512, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 613, 879, 879, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 624, 839, 839, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 640, 447, 447, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 487, 487, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 887, 887, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 704, 543, 543, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 752, 935, 935, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 871, 871, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 816, 823, 823, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AA, 0x372, 0x272, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AF, 0x90, 0x128, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A8, 0xA0, 0x80, 7, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 4, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 8, 2 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xE, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x48, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xE, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
