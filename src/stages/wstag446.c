#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x596
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5A6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10300, 0x13800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x34;
    D_800990B4.music = 0x60D00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4EAC;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern BattleList D_800A4ED0;
extern BattleList D_800A4F54;
extern BattleList D_800A4FD8;
extern BattleList D_800A505C;
extern u16 D_800A514C[];
extern u16 D_800A5154[];
extern u16 D_800A515C[];
extern u16 D_800A5168[];
extern u16 D_800A5178[];
extern u16 D_800A5180[];
extern u16 D_800A5194[];
extern u16 D_800A51A0[];
extern u16 D_800A51B4[];
extern u16 D_800A51BC[];
extern u16 D_800A51C4[];
extern u16 D_800A51D0[];
extern u16 D_800A51E0[];
extern u16 D_800A51EC[];
extern u16 D_800A5200[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern u16 D_800A5224[];
extern u16 D_800A522C[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A5248[];
extern u16 D_800A53BC[];
extern FieldTalk D_800A5260[];
extern u16 D_800A53C8[];
extern FieldTalk D_800A5278[];
extern u16 D_800A53DC[];
extern FieldTalk D_800A52C0[];
extern u16 D_800A53F0[];
extern FieldTalk D_800A5308[];
extern u16 D_800A5400[];
extern FieldTalk D_800A5338[];
extern u16 D_800A540C[];
extern FieldTalk D_800A5350[];
extern u16 D_800A5418[];
extern FieldTalk D_800A5368[];
extern u16 D_800A5420[];
extern FieldTalk D_800A5380[];
extern u16 D_800A542C[];
extern FieldTalk D_800A5398[];
extern FieldActorEntry D_800A5434;
extern FieldActorEntry D_800A5448;
extern FieldActorEntry D_800A545C;
extern FieldActorEntry D_800A5470;
extern FieldActorEntry D_800A5484;
extern FieldActorEntry D_800A5498;
extern FieldActorEntry D_800A54AC;
extern FieldActorEntry D_800A54C0;
extern FieldActorEntry D_800A54D4;
extern FieldActorEntry D_800A54E8;

Battle D_800A4E70 = { 105, 8, 0x60080000 };
Battle D_800A4E7C = { 105, 8, 0x60080000 };
Battle D_800A4E88 = { 105, 8, 0x60080000 };
Battle D_800A4E94 = { 105, 8, 0x60080000 };
Battle D_800A4EA0 = { 105, 8, 0x60080000 };
Battle D_800A4EAC = { 105, 8, 0x60080000 };
Battle D_800A4EB8 = { 105, 8, 0x60080000 };
Battle D_800A4EC4 = { 105, 8, 0x60080000 };
BattleList D_800A4ED0 = {
    3,
    { &D_800A4E70, &D_800A4E7C, &D_800A4E88, &D_800A4E94,
      &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4 },
};
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
Battle D_800A4F30 = { 0, 0, 0x60040000 };
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
BattleList D_800A4F54 = {
    0,
    { &D_800A4EF4, &D_800A4F00, &D_800A4F0C, &D_800A4F18,
      &D_800A4F24, &D_800A4F30, &D_800A4F3C, &D_800A4F48 },
};
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
Battle D_800A4FB4 = { 0, 0, 0x60040000 };
Battle D_800A4FC0 = { 0, 0, 0x60040000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
BattleList D_800A4FD8 = {
    0,
    { &D_800A4F78, &D_800A4F84, &D_800A4F90, &D_800A4F9C,
      &D_800A4FA8, &D_800A4FB4, &D_800A4FC0, &D_800A4FCC },
};
Battle D_800A4FFC = { 229, 8, 0x60080000 };
Battle D_800A5008 = { 277, 8, 0x600C0000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 331, 8, 0x60080000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 177, 8, 0x60080000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
BattleList D_800A505C = {
    0,
    { &D_800A4FFC, &D_800A5008, &D_800A5014, &D_800A5020,
      &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050 },
};
FieldBattles stageBattles[] = {
    { 70, 0, 0, { &D_800A4ED0, &D_800A4F54, &D_800A4FD8, &D_800A505C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x170, 0xB8, 0x70, 0x150, 0x1FF },
    { 0x140, 0x100, 0x166, 0x13E, 0x98, 0x3E, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x148, 0xB8, 0x48, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x148, 0xD8, 0x48, 0x140, 0x1FE },
    { 0x140, 0x100, 0x166, 0x166, 0x98, 0x66, 0x150, 0x1FE },
};
u16 D_800A514C[] = { 0, 0, 0xFFFF };
u16 D_800A5154[] = { 0, 1, 0xFFFF };
u16 D_800A515C[] = { 0, 1, 0x7205, 0, 0xFFFF };
u16 D_800A5168[] = { 0, 1, 0x7205, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5178[] = { 0x762D, 1, 0xFFFF };
u16 D_800A5180[] = { 0, 1, 0x7205, 1, 0x7208, 1, 0xE20, 0, 0xFFFF };
u16 D_800A5194[] = { 0x7400, 1, 0xE20, 1, 0xFFFF };
u16 D_800A51A0[] = { 0, 1, 0x7205, 1, 0x7208, 1, 0xE20, 1, 0xFFFF };
u16 D_800A51B4[] = { 0, 0, 0xFFFF };
u16 D_800A51BC[] = { 0, 1, 0xFFFF };
u16 D_800A51C4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51D0[] = { 0, 1, 0x7209, 1, 0xE41, 0, 0xFFFF };
u16 D_800A51E0[] = { 0x7400, 1, 0xE41, 1, 0xFFFF };
u16 D_800A51EC[] = { 0, 1, 0x7209, 1, 0xE41, 1, 0x720B, 0, 0xFFFF };
u16 D_800A5200[] = { 0, 1, 0x7209, 1, 0xE41, 1, 0x720B, 1, 0xFFFF };
u16 D_800A5214[] = { 0x782D, 1, 0xFFFF };
u16 D_800A521C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5224[] = { 0x10, 0, 0xFFFF };
u16 D_800A522C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5234[] = { 0x10, 1, 0xFFFF };
u16 D_800A523C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5248[] = {
    { NULL, NULL, 0xCD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5260[] = {
    { NULL, NULL, 0xCA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5278[] = {
    { D_800A514C, D_800A5154, 0x244 },
    { D_800A515C, NULL, 0x245 },
    { D_800A5168, D_800A5178, 0x246 },
    { D_800A5180, D_800A5194, 0x247 },
    { D_800A51A0, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C0[] = {
    { D_800A51B4, D_800A51BC, 0x24C },
    { D_800A51C4, NULL, 0x24E },
    { D_800A51D0, D_800A51E0, 0x24D },
    { D_800A51EC, NULL, 0x248 },
    { D_800A5200, D_800A5214, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5308[] = {
    { D_800A521C, NULL, 0x39C },
    { D_800A5224, D_800A522C, 0x249 },
    { D_800A5234, D_800A523C, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5338[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5350[] = {
    { NULL, NULL, 0xCC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5368[] = {
    { NULL, NULL, 0xCE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5380[] = {
    { NULL, NULL, 0xC9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5398[] = {
    { NULL, NULL, 0xCB },
    { NULL, NULL, 0 },
};
u16 D_800A53B0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A53BC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A53C8[] = { 0x8192, 1, 0x7019, 1, 0x11, 0, 0x8014, 0, 0xFFFF };
u16 D_800A53DC[] = { 0x8192, 1, 0x7019, 1, 0x11, 0, 0x8014, 1, 0xFFFF };
u16 D_800A53F0[] = { 0x8192, 1, 0x11, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5400[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A540C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5418[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5420[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A542C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5434 = { D_800A53B0, D_800A5248, 0x2D, 4, 611, 171, 1 };
FieldActorEntry D_800A5448 = { D_800A53BC, D_800A5260, 0x33, 5, 595, 475, 1 };
FieldActorEntry D_800A545C = { D_800A53C8, D_800A5278, 0x45, 6, 232, 316, 7 };
FieldActorEntry D_800A5470 = { D_800A53DC, D_800A52C0, 0x45, 6, 232, 316, 7 };
FieldActorEntry D_800A5484 = { D_800A53F0, D_800A5308, 0x45, 6, 232, 316, 7 };
FieldActorEntry D_800A5498 = { D_800A5400, D_800A5338, 0x45, 6, 232, 316, 7 };
FieldActorEntry D_800A54AC = { D_800A540C, D_800A5350, 0x9D, 7, 611, 171, 1 };
FieldActorEntry D_800A54C0 = { D_800A5418, D_800A5368, 0x9D, 7, 611, 171, 1 };
FieldActorEntry D_800A54D4 = { D_800A5420, D_800A5380, 0x9E, 8, 595, 475, 1 };
FieldActorEntry D_800A54E8 = { D_800A542C, D_800A5398, 0x9E, 8, 595, 475, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5434,
    &D_800A5448,
    &D_800A545C,
    &D_800A5470,
    &D_800A5484,
    &D_800A5498,
    &D_800A54AC,
    &D_800A54C0,
    &D_800A54D4,
    &D_800A54E8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 89, 30, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 694, 46, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 185, 413, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 428, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 405, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 706, 428, 0, 0 },
    { 1, 0x64, 0x40, 6, 1, 0, 0, 0, 0, 0, 490, 108, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 464, 77, 161, 0 },
    { 1, 0, 0x80, 4, 0xD, 0, 0, 0, 0, 0, 358, 119, 155, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 223, 167, 167, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 248, 140, 140, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 295, 115, 115, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 151, 151, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 599, 123, 123, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 313, 313, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 690, 375, 375, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A2, 0x668, 0xB4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A0, 0x190, 0x218, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
