#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5D3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5E3
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10000, 0x50300};
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

extern Battle D_800A4E4C;
extern Battle D_800A4E58;
extern Battle D_800A4E64;
extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern BattleList D_800A4EAC;
extern BattleList D_800A4F30;
extern BattleList D_800A4FB4;
extern BattleList D_800A5038;
extern u16 D_800A5188[];
extern u16 D_800A5190[];
extern u16 D_800A5198[];
extern u16 D_800A51A4[];
extern u16 D_800A51B4[];
extern u16 D_800A51BC[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51F0[];
extern u16 D_800A51F8[];
extern u16 D_800A5200[];
extern u16 D_800A5208[];
extern u16 D_800A5210[];
extern u16 D_800A521C[];
extern u16 D_800A5224[];
extern u16 D_800A522C[];
extern u16 D_800A5238[];
extern u16 D_800A5248[];
extern u16 D_800A5254[];
extern u16 D_800A5268[];
extern u16 D_800A527C[];
extern u16 D_800A54AC[];
extern FieldTalk D_800A5284[];
extern u16 D_800A54B8[];
extern FieldTalk D_800A529C[];
extern u16 D_800A54C4[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A54D0[];
extern FieldTalk D_800A52CC[];
extern u16 D_800A54DC[];
extern FieldTalk D_800A52E4[];
extern u16 D_800A54F0[];
extern FieldTalk D_800A532C[];
extern u16 D_800A5500[];
extern FieldTalk D_800A535C[];
extern u16 D_800A550C[];
extern FieldTalk D_800A5374[];
extern u16 D_800A5520[];
extern FieldTalk D_800A53BC[];
extern u16 D_800A552C[];
extern FieldTalk D_800A53D4[];
extern u16 D_800A5534[];
extern FieldTalk D_800A53EC[];
extern u16 D_800A5540[];
extern FieldTalk D_800A5404[];
extern u16 D_800A5548[];
extern FieldTalk D_800A541C[];
extern u16 D_800A5554[];
extern FieldTalk D_800A5434[];
extern u16 D_800A555C[];
extern FieldTalk D_800A544C[];
extern u16 D_800A5568[];
extern FieldTalk D_800A5464[];
extern u16 D_800A5570[];
extern FieldTalk D_800A547C[];
extern u16 D_800A5578[];
extern FieldTalk D_800A5494[];
extern FieldActorEntry D_800A5580;
extern FieldActorEntry D_800A5594;
extern FieldActorEntry D_800A55A8;
extern FieldActorEntry D_800A55BC;
extern FieldActorEntry D_800A55D0;
extern FieldActorEntry D_800A55E4;
extern FieldActorEntry D_800A55F8;
extern FieldActorEntry D_800A560C;
extern FieldActorEntry D_800A5620;
extern FieldActorEntry D_800A5634;
extern FieldActorEntry D_800A5648;
extern FieldActorEntry D_800A565C;
extern FieldActorEntry D_800A5670;
extern FieldActorEntry D_800A5684;
extern FieldActorEntry D_800A5698;
extern FieldActorEntry D_800A56AC;
extern FieldActorEntry D_800A56C0;
extern FieldActorEntry D_800A56D4;

Battle D_800A4E4C = { 134, 5, 0x60080000 };
Battle D_800A4E58 = { 134, 5, 0x60080000 };
Battle D_800A4E64 = { 134, 5, 0x60080000 };
Battle D_800A4E70 = { 134, 5, 0x60080000 };
Battle D_800A4E7C = { 172, 5, 0x60080000 };
Battle D_800A4E88 = { 172, 5, 0x60080000 };
Battle D_800A4E94 = { 172, 5, 0x60080000 };
Battle D_800A4EA0 = { 172, 5, 0x60080000 };
BattleList D_800A4EAC = {
    3,
    { &D_800A4E4C, &D_800A4E58, &D_800A4E64, &D_800A4E70,
      &D_800A4E7C, &D_800A4E88, &D_800A4E94, &D_800A4EA0 },
};
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
BattleList D_800A4F30 = {
    0,
    { &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4,
      &D_800A4F00, &D_800A4F0C, &D_800A4F18, &D_800A4F24 },
};
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
BattleList D_800A4FB4 = {
    0,
    { &D_800A4F54, &D_800A4F60, &D_800A4F6C, &D_800A4F78,
      &D_800A4F84, &D_800A4F90, &D_800A4F9C, &D_800A4FA8 },
};
Battle D_800A4FD8 = { 235, 5, 0x60080000 };
Battle D_800A4FE4 = { 283, 5, 0x600C0000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 0, 0, 0x60040000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 99, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x16A, 0x60, 0x6A, 0x140, 0x1FF },
    { 0x140, 0x100, 0x160, 0x16A, 0x80, 0x6A, 0x150, 0x1FF },
    { 0x180, 0x100, 0x190, 0x100, 0x140, 0, 0x160, 0x1FF },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x140, 0x1FE },
    { 0x180, 0x100, 0x190, 0x128, 0x140, 0x28, 0x150, 0x1FE },
    { 0x180, 0x100, 0x198, 0x128, 0x160, 0x28, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1A0, 0x128, 0x180, 0x28, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1A8, 0x128, 0x1A0, 0x28, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1A8, 0x100, 0x1A0, 0, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x160, 0x1FD },
};
u16 D_800A5188[] = { 0, 0, 0xFFFF };
u16 D_800A5190[] = { 0, 1, 0xFFFF };
u16 D_800A5198[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A51A4[] = { 0, 1, 0x7207, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51B4[] = { 0x7633, 1, 0xFFFF };
u16 D_800A51BC[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE26, 0, 0xFFFF };
u16 D_800A51D0[] = { 0x7400, 1, 0xE26, 1, 0xFFFF };
u16 D_800A51DC[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE26, 1, 0xFFFF };
u16 D_800A51F0[] = { 0x11, 0, 0xFFFF };
u16 D_800A51F8[] = { 0x10, 0, 0xFFFF };
u16 D_800A5200[] = { 0x11, 0, 0xFFFF };
u16 D_800A5208[] = { 0x10, 1, 0xFFFF };
u16 D_800A5210[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A521C[] = { 0, 0, 0xFFFF };
u16 D_800A5224[] = { 0, 1, 0xFFFF };
u16 D_800A522C[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A5238[] = { 0, 1, 0x720A, 1, 0xE48, 0, 0xFFFF };
u16 D_800A5248[] = { 0xE48, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5254[] = { 0, 1, 0x720A, 1, 0xE48, 1, 0x720C, 0, 0xFFFF };
u16 D_800A5268[] = { 0x720C, 1, 0, 1, 0x720A, 1, 0xE48, 1, 0xFFFF };
u16 D_800A527C[] = { 0x7833, 1, 0xFFFF };
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0x198 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0x196 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0x19C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0x19A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E4[] = {
    { D_800A5188, D_800A5190, 0x244 },
    { D_800A5198, NULL, 0x245 },
    { D_800A51A4, D_800A51B4, 0x246 },
    { D_800A51BC, D_800A51D0, 0x247 },
    { D_800A51DC, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A532C[] = {
    { D_800A51F0, NULL, 0x39B },
    { D_800A51F8, D_800A5200, 0x249 },
    { D_800A5208, D_800A5210, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A535C[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5374[] = {
    { D_800A521C, D_800A5224, 0x24C },
    { D_800A522C, NULL, 0x24E },
    { D_800A5238, D_800A5248, 0x24D },
    { D_800A5254, NULL, 0x248 },
    { D_800A5268, D_800A527C, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53BC[] = {
    { NULL, NULL, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53D4[] = {
    { NULL, NULL, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53EC[] = {
    { NULL, NULL, 0x19B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5404[] = {
    { NULL, NULL, 0x19B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A541C[] = {
    { NULL, NULL, 0x199 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5434[] = {
    { NULL, NULL, 0x199 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A544C[] = {
    { NULL, NULL, 0x197 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5464[] = {
    { NULL, NULL, 0x197 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A547C[] = {
    { NULL, NULL, 0x328 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5494[] = {
    { NULL, NULL, 0x329 },
    { NULL, NULL, 0 },
};
u16 D_800A54AC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A54B8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A54C4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A54DC[] = { 0x7019, 1, 0x8192, 1, 0x11, 0, 0x8014, 0, 0xFFFF };
u16 D_800A54F0[] = { 0x7019, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5500[] = { 0x7019, 1, 0x8192, 0, 0xFFFF };
u16 D_800A550C[] = { 0x8014, 1, 0x8192, 1, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5520[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A552C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5534[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5540[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5548[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5554[] = { 0x701A, 1, 0xFFFF };
u16 D_800A555C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5568[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5570[] = { 0x7020, 1, 0xFFFF };
u16 D_800A5578[] = { 0x7020, 1, 0xFFFF };
FieldActorEntry D_800A5580 = { D_800A54AC, D_800A5284, 0x2F, 4, 720, 777, 5 };
FieldActorEntry D_800A5594 = { D_800A54B8, D_800A529C, 0x31, 5, 992, 1209, 1 };
FieldActorEntry D_800A55A8 = { D_800A54C4, D_800A52B4, 0x36, 6, 1072, 433, 1 };
FieldActorEntry D_800A55BC = { D_800A54D0, D_800A52CC, 0x37, 7, 320, 769, 1 };
FieldActorEntry D_800A55D0 = { D_800A54DC, D_800A52E4, 0x45, 8, 401, 577, 7 };
FieldActorEntry D_800A55E4 = { D_800A54F0, D_800A532C, 0x45, 8, 401, 577, 7 };
FieldActorEntry D_800A55F8 = { D_800A5500, D_800A535C, 0x45, 8, 401, 577, 7 };
FieldActorEntry D_800A560C = { D_800A550C, D_800A5374, 0x45, 8, 401, 577, 7 };
FieldActorEntry D_800A5620 = { D_800A5520, D_800A53BC, 0x9D, 9, 1072, 433, 1 };
FieldActorEntry D_800A5634 = { D_800A552C, D_800A53D4, 0x9D, 9, 1072, 433, 1 };
FieldActorEntry D_800A5648 = { D_800A5534, D_800A53EC, 0x9E, 0xA, 320, 769, 1 };
FieldActorEntry D_800A565C = { D_800A5540, D_800A5404, 0x9E, 0xA, 320, 769, 1 };
FieldActorEntry D_800A5670 = { D_800A5548, D_800A541C, 0x9F, 0xB, 720, 777, 5 };
FieldActorEntry D_800A5684 = { D_800A5554, D_800A5434, 0x9F, 0xB, 720, 777, 5 };
FieldActorEntry D_800A5698 = { D_800A555C, D_800A544C, 0xA0, 0xC, 992, 1209, 1 };
FieldActorEntry D_800A56AC = { D_800A5568, D_800A5464, 0xA0, 0xC, 992, 1209, 1 };
FieldActorEntry D_800A56C0 = { D_800A5570, D_800A547C, 0x132, 0xD, 411, 158, 1 };
FieldActorEntry D_800A56D4 = { D_800A5578, D_800A5494, 0x133, 0xE, 389, 147, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5580,
    &D_800A5594,
    &D_800A55A8,
    &D_800A55BC,
    &D_800A55D0,
    &D_800A55E4,
    &D_800A55F8,
    &D_800A560C,
    &D_800A5620,
    &D_800A5634,
    &D_800A5648,
    &D_800A565C,
    &D_800A5670,
    &D_800A5684,
    &D_800A5698,
    &D_800A56AC,
    &D_800A56C0,
    &D_800A56D4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 6, 0, 0, 0, 0, 0, 874, 1273, 0, 0 },
    { 1, 0, 0x80, 6, 7, 0, 0, 0, 0, 0, 856, 1221, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 506, 475, 544, 0 },
    { 1, 0, 0x50, 4, 1, 0, 0, 0, 0, 0, 317, 423, 488, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 225, 615, 666, 0 },
    { 1, 0, 0x48, 4, 3, 0, 0, 0, 0, 0, 476, 647, 713, 0 },
    { 1, 0, 0x49, 4, 4, 0, 0, 0, 0, 0, 592, 815, 880, 0 },
    { 1, 0, 0x78, 4, 5, 0, 0, 0, 0, 0, 289, 127, 230, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C6, 0xC8, 0x3BC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B3, 0x7A, 0xEA, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B1, 0xB0, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C0, 0x320, 0x88, 1, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x1E, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 8, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
