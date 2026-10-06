#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x424
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x434
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x49D00, 0x20300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern BattleList D_800A4EE0;
extern BattleList D_800A4F64;
extern BattleList D_800A4FE8;
extern BattleList D_800A506C;
extern u16 D_800A51BC[];
extern u16 D_800A51C4[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern u16 D_800A5200[];
extern u16 D_800A5314[];
extern FieldTalk D_800A520C[];
extern u16 D_800A531C[];
extern FieldTalk D_800A5224[];
extern u16 D_800A5324[];
extern FieldTalk D_800A523C[];
extern u16 D_800A532C[];
extern FieldTalk D_800A5254[];
extern u16 D_800A5334[];
extern FieldTalk D_800A526C[];
extern u16 D_800A533C[];
extern FieldTalk D_800A5284[];
extern u16 D_800A5348[];
extern FieldTalk D_800A529C[];
extern u16 D_800A5354[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A5360[];
extern FieldTalk D_800A52CC[];
extern u16 D_800A536C[];
extern FieldTalk D_800A52E4[];
extern u16 D_800A5378[];
extern FieldTalk D_800A52FC[];
extern FieldActorEntry D_800A5384;
extern FieldActorEntry D_800A5398;
extern FieldActorEntry D_800A53AC;
extern FieldActorEntry D_800A53C0;
extern FieldActorEntry D_800A53D4;
extern FieldActorEntry D_800A53E8;
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;
extern FieldActorEntry D_800A5424;
extern FieldActorEntry D_800A5438;
extern FieldActorEntry D_800A544C;

Battle D_800A4E80 = { 0, 0, 0x60040000 };
Battle D_800A4E8C = { 0, 0, 0x60040000 };
Battle D_800A4E98 = { 0, 0, 0x60040000 };
Battle D_800A4EA4 = { 0, 0, 0x60040000 };
Battle D_800A4EB0 = { 0, 0, 0x60040000 };
Battle D_800A4EBC = { 0, 0, 0x60040000 };
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
BattleList D_800A4EE0 = {
    0,
    { &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4,
      &D_800A4EB0, &D_800A4EBC, &D_800A4EC8, &D_800A4ED4 },
};
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
BattleList D_800A4F64 = {
    0,
    { &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28,
      &D_800A4F34, &D_800A4F40, &D_800A4F4C, &D_800A4F58 },
};
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
BattleList D_800A4FE8 = {
    0,
    { &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC,
      &D_800A4FB8, &D_800A4FC4, &D_800A4FD0, &D_800A4FDC },
};
Battle D_800A500C = { 196, 15, 0x60080000 };
Battle D_800A5018 = { 197, 15, 0x60080000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
BattleList D_800A506C = {
    0,
    { &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030,
      &D_800A503C, &D_800A5048, &D_800A5054, &D_800A5060 },
};
FieldBattles stageBattles[] = {
    { 147, 0, 0, { &D_800A4EE0, &D_800A4F64, &D_800A4FE8, &D_800A506C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x100, 0x1E0, 0, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x172, 0x1B1, 0xC8, 0xB1, 0x170, 0x1F8 },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x170, 0x1F7 },
    { 0x180, 0x100, 0x180, 0x17F, 0x100, 0x7F, 0x170, 0x1F6 },
    { 0x180, 0x100, 0x188, 0x17F, 0x120, 0x7F, 0x150, 0x1F5 },
    { 0x180, 0x100, 0x1B0, 0x130, 0x1C0, 0x30, 0x160, 0x1F5 },
    { 0x180, 0x100, 0x1B0, 0x158, 0x1C0, 0x58, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x1A0, 0x167, 0x180, 0x67, 0x150, 0x1F4 },
    { 0x180, 0x100, 0x1A8, 0x167, 0x1A0, 0x67, 0x160, 0x1F4 },
    { 0x180, 0x100, 0x190, 0x174, 0x140, 0x74, 0x170, 0x1F4 },
    { 0x180, 0x100, 0x198, 0x174, 0x160, 0x74, 0x150, 0x1F3 },
};
u16 D_800A51BC[] = { 0x260, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x7400, 1, 0xC2B, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x7401, 1, 0xC30, 1, 0xFFFF };
u16 D_800A51DC[] = { 0x7401, 1, 0xC31, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x7400, 1, 0xC2C, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x7400, 1, 0xC2D, 1, 0xFFFF };
u16 D_800A5200[] = { 0x7400, 1, 0xC2E, 1, 0xFFFF };
FieldTalk D_800A520C[] = {
    { NULL, D_800A51BC, 0x16F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0xAD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0xAF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, NULL, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, D_800A51C4, 0x1C3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, D_800A51D0, 0x1C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, D_800A51DC, 0x1C8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, D_800A51E8, 0x1C4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E4[] = {
    { NULL, D_800A51F4, 0x1C5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52FC[] = {
    { NULL, D_800A5200, 0x1C6 },
    { NULL, NULL, 0 },
};
u16 D_800A5314[] = { 0x260, 0, 0xFFFF };
u16 D_800A531C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5324[] = { 0x6026, 1, 0xFFFF };
u16 D_800A532C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5334[] = { 0x701A, 1, 0xFFFF };
u16 D_800A533C[] = { 0x6025, 1, 0xC2B, 0, 0xFFFF };
u16 D_800A5348[] = { 0xC30, 0, 0x6025, 1, 0xFFFF };
u16 D_800A5354[] = { 0xC31, 0, 0x6025, 1, 0xFFFF };
u16 D_800A5360[] = { 0x6025, 1, 0xC2C, 0, 0xFFFF };
u16 D_800A536C[] = { 0x6025, 1, 0xC2D, 0, 0xFFFF };
u16 D_800A5378[] = { 0x6025, 1, 0xC2E, 0, 0xFFFF };
FieldActorEntry D_800A5384 = { D_800A5314, D_800A520C, 0x21, 4, 700, 283, 1 };
FieldActorEntry D_800A5398 = { D_800A531C, D_800A5224, 0x25, 5, 961, 217, 1 };
FieldActorEntry D_800A53AC = { D_800A5324, D_800A523C, 0x26, 6, 896, 185, 1 };
FieldActorEntry D_800A53C0 = { D_800A532C, D_800A5254, 0x9D, 7, 961, 217, 1 };
FieldActorEntry D_800A53D4 = { D_800A5334, D_800A526C, 0x9E, 8, 896, 185, 1 };
FieldActorEntry D_800A53E8 = { D_800A533C, D_800A5284, 0x12B, 9, 1120, 281, 1 };
FieldActorEntry D_800A53FC = { D_800A5348, D_800A529C, 0x12D, 0xA, 992, 282, 1 };
FieldActorEntry D_800A5410 = { D_800A5354, D_800A52B4, 0x12E, 0xB, 769, 169, 1 };
FieldActorEntry D_800A5424 = { D_800A5360, D_800A52CC, 0x12F, 0xC, 936, 477, 1 };
FieldActorEntry D_800A5438 = { D_800A536C, D_800A52E4, 0x130, 0xD, 1225, 429, 3 };
FieldActorEntry D_800A544C = { D_800A5378, D_800A52FC, 0x131, 0xE, 321, 201, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5384,
    &D_800A5398,
    &D_800A53AC,
    &D_800A53C0,
    &D_800A53D4,
    &D_800A53E8,
    &D_800A53FC,
    &D_800A5410,
    &D_800A5424,
    &D_800A5438,
    &D_800A544C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 9, 8, 0, 918, 96, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 9, 0xA, 0, 918, 96, 0, 0 },
    { 1, 0, 0xFF, 2, 0xB, 0, 0, 0, 0, 0, 992, 126, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 166, 118, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 541, 90, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 1115, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 332, 103, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1009, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1211, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1294, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 860, 89, 0, 0 },
    { 1, 0, 0x80, 6, 0x35, 3, 0, 0xF, 0xE, 0, 660, 434, 0, 0 },
    { 1, 0x64, 0x40, 6, 0, 0, 0, 0, 0, 0, 929, 148, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 768, 107, 151, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 992, 218, 264, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 1088, 218, 264, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1152, 186, 230, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 816, 333, 432, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 945, 441, 462, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 960, 190, 231, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 480, 321, 342, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 497, 256, 272, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 953, 144, 200, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x274, 0x158, 0xA4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x287, 0x56, 0x18A, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0xC8, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x283, 0x177, 0xBD, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x274, 0x372, 0x132, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
