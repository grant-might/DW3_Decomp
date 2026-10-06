#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5DB
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5EB
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12C00, 0x15400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
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
extern u16 D_800A515C[];
extern u16 D_800A516C[];
extern u16 D_800A5180[];
extern u16 D_800A5198[];
extern u16 D_800A51B0[];
extern u16 D_800A51C8[];
extern u16 D_800A51E0[];
extern u16 D_800A52A8[];
extern FieldTalk D_800A51E8[];
extern u16 D_800A52B4[];
extern FieldTalk D_800A5200[];
extern u16 D_800A52BC[];
extern FieldTalk D_800A5218[];
extern u16 D_800A52C4[];
extern FieldTalk D_800A5230[];
extern u16 D_800A52CC[];
extern FieldTalk D_800A5248[];
extern u16 D_800A52D4[];
extern FieldTalk D_800A5260[];
extern u16 D_800A52DC[];
extern FieldTalk D_800A5278[];
extern u16 D_800A52E4[];
extern FieldTalk D_800A5290[];
extern FieldActorEntry D_800A52EC;
extern FieldActorEntry D_800A5300;
extern FieldActorEntry D_800A5314;
extern FieldActorEntry D_800A5328;
extern FieldActorEntry D_800A533C;
extern FieldActorEntry D_800A5350;
extern FieldActorEntry D_800A5364;
extern FieldActorEntry D_800A5378;

Battle D_800A4E50 = { 116, 12, 0x60080000 };
Battle D_800A4E5C = { 116, 12, 0x60080000 };
Battle D_800A4E68 = { 116, 12, 0x60080000 };
Battle D_800A4E74 = { 116, 12, 0x60080000 };
Battle D_800A4E80 = { 116, 12, 0x60080000 };
Battle D_800A4E8C = { 116, 12, 0x60080000 };
Battle D_800A4E98 = { 116, 12, 0x60080000 };
Battle D_800A4EA4 = { 116, 12, 0x60080000 };
BattleList D_800A4EB0 = {
    4,
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
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 107, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x158, 0x100, 0x60, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x120, 0, 0x20, 0x170, 0x1FE },
    { 0x140, 0x100, 0x148, 0x120, 0x20, 0x20, 0x150, 0x1FD },
    { 0x140, 0x100, 0x150, 0x120, 0x40, 0x20, 0x160, 0x1FD },
};
u16 D_800A515C[] = { 0x24C, 1, 0x8232, 1, 0x7013, 1, 0xFFFF };
u16 D_800A516C[] = { 0x8259, 1, 0x825A, 1, 0x84A7, 1, 0x8007, 1, 0xFFFF };
u16 D_800A5180[] = {
    0x8674, 1, 0x8680, 1, 0x868D, 1, 0x8666, 1,
    0x8699, 1, 0xFFFF,
};
u16 D_800A5198[] = {
    0x8463, 1, 0x8496, 1, 0x847D, 1, 0x848A, 1,
    0x8471, 1, 0xFFFF,
};
u16 D_800A51B0[] = {
    0x8497, 1, 0x847E, 1, 0x848B, 1, 0x8464, 1,
    0x8472, 1, 0xFFFF,
};
u16 D_800A51C8[] = {
    0x8498, 1, 0x847F, 1, 0x848C, 1, 0x8465, 1,
    0x8473, 1, 0xFFFF,
};
u16 D_800A51E0[] = { 0x7092, 1, 0xFFFF };
FieldTalk D_800A51E8[] = {
    { NULL, D_800A515C, 0x184 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5200[] = {
    { NULL, D_800A516C, 0x39F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5218[] = {
    { NULL, D_800A5180, 0x3A0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5230[] = {
    { NULL, D_800A5198, 0x3A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5248[] = {
    { NULL, D_800A51B0, 0x3A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5260[] = {
    { NULL, D_800A51C8, 0x3A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5278[] = {
    { NULL, NULL, 0x3A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5290[] = {
    { NULL, D_800A51E0, 0x39E },
    { NULL, NULL, 0 },
};
u16 D_800A52A8[] = { 0x24C, 0, 0x6000, 0, 0xFFFF };
u16 D_800A52B4[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52BC[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52C4[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52CC[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x6000, 1, 0xFFFF };
u16 D_800A52E4[] = { 0x6000, 1, 0xFFFF };
FieldActorEntry D_800A52EC = { D_800A52A8, D_800A51E8, 0x21, 4, 379, 318, 1 };
FieldActorEntry D_800A5300 = { D_800A52B4, D_800A5200, 0x45, 5, 209, 329, 7 };
FieldActorEntry D_800A5314 = { D_800A52BC, D_800A5218, 0x46, 6, 240, 313, 7 };
FieldActorEntry D_800A5328 = { D_800A52C4, D_800A5230, 0x47, 7, 272, 297, 7 };
FieldActorEntry D_800A533C = { D_800A52CC, D_800A5248, 0x48, 8, 354, 401, 3 };
FieldActorEntry D_800A5350 = { D_800A52D4, D_800A5260, 0x49, 9, 385, 385, 3 };
FieldActorEntry D_800A5364 = { D_800A52DC, D_800A5278, 0x4A, 0xA, 415, 369, 3 };
FieldActorEntry D_800A5378 = { D_800A52E4, D_800A5290, 0x98, 0xB, 379, 317, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A52EC,
    &D_800A5300,
    &D_800A5314,
    &D_800A5328,
    &D_800A533C,
    &D_800A5350,
    &D_800A5364,
    &D_800A5378,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 277, 252, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 405, 317, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x358, 0x37C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
