#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x60F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x61F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x16000, 0x23100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
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
extern u16 D_800A519C[];
extern u16 D_800A51A4[];
extern u16 D_800A51AC[];
extern u16 D_800A51B8[];
extern u16 D_800A51C8[];
extern u16 D_800A51D0[];
extern u16 D_800A51E4[];
extern u16 D_800A51F0[];
extern u16 D_800A5204[];
extern u16 D_800A520C[];
extern u16 D_800A5214[];
extern u16 D_800A5220[];
extern u16 D_800A5230[];
extern u16 D_800A523C[];
extern u16 D_800A5250[];
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A5274[];
extern u16 D_800A527C[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A5400[];
extern FieldTalk D_800A5298[];
extern u16 D_800A540C[];
extern FieldTalk D_800A52B0[];
extern u16 D_800A5420[];
extern FieldTalk D_800A52F8[];
extern u16 D_800A5434[];
extern FieldTalk D_800A5340[];
extern u16 D_800A5444[];
extern FieldTalk D_800A5370[];
extern u16 D_800A5450[];
extern u16 D_800A5460[];
extern u16 D_800A5470[];
extern u16 D_800A5480[];
extern u16 D_800A5490[];
extern u16 D_800A54A0[];
extern FieldTalk D_800A5388[];
extern u16 D_800A54AC[];
extern FieldTalk D_800A53A0[];
extern u16 D_800A54B4[];
extern u16 D_800A54C4[];
extern FieldTalk D_800A53B8[];
extern u16 D_800A54D4[];
extern FieldTalk D_800A53D0[];
extern u16 D_800A54E4[];
extern FieldTalk D_800A53E8[];
extern FieldActorEntry D_800A54F4;
extern FieldActorEntry D_800A5508;
extern FieldActorEntry D_800A551C;
extern FieldActorEntry D_800A5530;
extern FieldActorEntry D_800A5544;
extern FieldActorEntry D_800A5558;
extern FieldActorEntry D_800A556C;
extern FieldActorEntry D_800A5580;
extern FieldActorEntry D_800A5594;
extern FieldActorEntry D_800A55A8;
extern FieldActorEntry D_800A55BC;
extern FieldActorEntry D_800A55D0;
extern FieldActorEntry D_800A55E4;
extern FieldActorEntry D_800A55F8;
extern FieldActorEntry D_800A560C;
extern FieldActorEntry D_800A5620;

Battle D_800A4E50 = { 72, 5, 0x60080000 };
Battle D_800A4E5C = { 72, 5, 0x60080000 };
Battle D_800A4E68 = { 72, 5, 0x60080000 };
Battle D_800A4E74 = { 72, 5, 0x60080000 };
Battle D_800A4E80 = { 72, 5, 0x60080000 };
Battle D_800A4E8C = { 72, 5, 0x60080000 };
Battle D_800A4E98 = { 72, 5, 0x60080000 };
Battle D_800A4EA4 = { 72, 5, 0x60080000 };
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
Battle D_800A4FDC = { 238, 5, 0x60080000 };
Battle D_800A4FE8 = { 286, 5, 0x600C0000 };
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
    { 101, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x100, 0xC8, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x162, 0x128, 0x88, 0x28, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x128, 0xA8, 0x28, 0x140, 0x1FE },
    { 0x140, 0x100, 0x172, 0x128, 0xC8, 0x28, 0x150, 0x1FE },
    { 0x140, 0x100, 0x162, 0x150, 0x88, 0x50, 0x160, 0x1FE },
    { 0x140, 0x100, 0x172, 0x178, 0xC8, 0x78, 0x170, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x150, 0xA8, 0x50, 0x140, 0x1FD },
    { 0x140, 0x100, 0x172, 0x150, 0xC8, 0x50, 0x150, 0x1FD },
    { 0x140, 0x100, 0x162, 0x178, 0x88, 0x78, 0x160, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x178, 0xA8, 0x78, 0x170, 0x1FD },
};
u16 D_800A519C[] = { 0, 0, 0xFFFF };
u16 D_800A51A4[] = { 0, 1, 0xFFFF };
u16 D_800A51AC[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A51B8[] = { 0, 1, 0x7207, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51C8[] = { 0x7636, 1, 0xFFFF };
u16 D_800A51D0[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE29, 0, 0xFFFF };
u16 D_800A51E4[] = { 0x7400, 1, 0xE29, 1, 0xFFFF };
u16 D_800A51F0[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE29, 1, 0xFFFF };
u16 D_800A5204[] = { 0, 0, 0xFFFF };
u16 D_800A520C[] = { 0, 1, 0xFFFF };
u16 D_800A5214[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A5220[] = { 0, 1, 0x720A, 1, 0xE4A, 0, 0xFFFF };
u16 D_800A5230[] = { 0x7400, 1, 0xE4A, 1, 0xFFFF };
u16 D_800A523C[] = { 0, 1, 0x720A, 1, 0xE4A, 1, 0x720C, 0, 0xFFFF };
u16 D_800A5250[] = { 0, 1, 0x720A, 1, 0xE4A, 1, 0x720C, 1, 0xFFFF };
u16 D_800A5264[] = { 0x7836, 1, 0xFFFF };
u16 D_800A526C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5274[] = { 0x10, 0, 0xFFFF };
u16 D_800A527C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5284[] = { 0x10, 1, 0xFFFF };
u16 D_800A528C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5298[] = {
    { NULL, NULL, 0x1C6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B0[] = {
    { D_800A519C, D_800A51A4, 0x244 },
    { D_800A51AC, NULL, 0x245 },
    { D_800A51B8, D_800A51C8, 0x246 },
    { D_800A51D0, D_800A51E4, 0x247 },
    { D_800A51F0, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F8[] = {
    { D_800A5204, D_800A520C, 0x24C },
    { D_800A5214, NULL, 0x24E },
    { D_800A5220, D_800A5230, 0x24D },
    { D_800A523C, NULL, 0x248 },
    { D_800A5250, D_800A5264, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5340[] = {
    { D_800A526C, NULL, 0x39B },
    { D_800A5274, D_800A527C, 0x249 },
    { D_800A5284, D_800A528C, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5370[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5388[] = {
    { NULL, NULL, 0x1C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53A0[] = {
    { NULL, NULL, 0x1C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B8[] = {
    { NULL, NULL, 0x32B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53D0[] = {
    { NULL, NULL, 0x32C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E8[] = {
    { NULL, NULL, 0x32D },
    { NULL, NULL, 0 },
};
u16 D_800A5400[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A540C[] = { 0x8192, 1, 0x11, 0, 0x8014, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5420[] = { 0x7019, 1, 0x11, 0, 0x8192, 1, 0x8014, 1, 0xFFFF };
u16 D_800A5434[] = { 0x8192, 1, 0x11, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5444[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5450[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A5460[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A5470[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A5480[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A5490[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A54A0[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A54AC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A54B4[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A54C4[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A54D4[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
u16 D_800A54E4[] = { 0x7021, 1, 0x6025, 0, 0x6026, 0, 0xFFFF };
FieldActorEntry D_800A54F4 = { D_800A5400, D_800A5298, 0x32, 4, 752, 289, 1 };
FieldActorEntry D_800A5508 = { D_800A540C, D_800A52B0, 0x45, 5, 432, 273, 7 };
FieldActorEntry D_800A551C = { D_800A5420, D_800A52F8, 0x45, 5, 432, 273, 7 };
FieldActorEntry D_800A5530 = { D_800A5434, D_800A5340, 0x45, 5, 432, 273, 7 };
FieldActorEntry D_800A5544 = { D_800A5444, D_800A5370, 0x45, 5, 432, 273, 7 };
FieldActorEntry D_800A5558 = { D_800A5450, NULL, 0x46, 6, 143, 672, 1 };
FieldActorEntry D_800A556C = { D_800A5460, NULL, 0x47, 7, 177, 689, 1 };
FieldActorEntry D_800A5580 = { D_800A5470, NULL, 0x48, 8, 207, 657, 1 };
FieldActorEntry D_800A5594 = { D_800A5480, NULL, 0x49, 9, 232, 620, 1 };
FieldActorEntry D_800A55A8 = { D_800A5490, NULL, 0x4A, 0xA, 263, 628, 1 };
FieldActorEntry D_800A55BC = { D_800A54A0, D_800A5388, 0x9D, 0xB, 752, 289, 1 };
FieldActorEntry D_800A55D0 = { D_800A54AC, D_800A53A0, 0x9D, 0xB, 752, 289, 1 };
FieldActorEntry D_800A55E4 = { D_800A54B4, NULL, 0xA4, 0xC, 280, 645, 1 };
FieldActorEntry D_800A55F8 = { D_800A54C4, D_800A53B8, 0x132, 0xD, 272, 601, 1 };
FieldActorEntry D_800A560C = { D_800A54D4, D_800A53D0, 0x133, 0xE, 303, 607, 1 };
FieldActorEntry D_800A5620 = { D_800A54E4, D_800A53E8, 0x134, 0xF, 321, 624, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A54F4,
    &D_800A5508,
    &D_800A551C,
    &D_800A5530,
    &D_800A5544,
    &D_800A5558,
    &D_800A556C,
    &D_800A5580,
    &D_800A5594,
    &D_800A55A8,
    &D_800A55BC,
    &D_800A55D0,
    &D_800A55E4,
    &D_800A55F8,
    &D_800A560C,
    &D_800A5620,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 541, 275, 326, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 364, 459, 509, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B2, 0x90, 0x540, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x340, 0xF0, 1, 0, 1, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
