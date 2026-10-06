#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5A2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5B2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x3A700, 0x1D400};
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
extern u16 D_800A512C[];
extern u16 D_800A5134[];
extern u16 D_800A513C[];
extern u16 D_800A5148[];
extern u16 D_800A5158[];
extern u16 D_800A5160[];
extern u16 D_800A5174[];
extern u16 D_800A5180[];
extern u16 D_800A5194[];
extern u16 D_800A519C[];
extern u16 D_800A51A4[];
extern u16 D_800A51B0[];
extern u16 D_800A51C0[];
extern u16 D_800A51CC[];
extern u16 D_800A51E0[];
extern u16 D_800A51F4[];
extern u16 D_800A51FC[];
extern u16 D_800A5204[];
extern u16 D_800A520C[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern u16 D_800A5348[];
extern FieldTalk D_800A5228[];
extern u16 D_800A5354[];
extern FieldTalk D_800A5240[];
extern u16 D_800A5368[];
extern FieldTalk D_800A5288[];
extern u16 D_800A537C[];
extern FieldTalk D_800A52D0[];
extern u16 D_800A538C[];
extern FieldTalk D_800A5300[];
extern u16 D_800A5398[];
extern FieldTalk D_800A5318[];
extern u16 D_800A53A4[];
extern FieldTalk D_800A5330[];
extern FieldActorEntry D_800A53AC;
extern FieldActorEntry D_800A53C0;
extern FieldActorEntry D_800A53D4;
extern FieldActorEntry D_800A53E8;
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;
extern FieldActorEntry D_800A5424;

Battle D_800A4E70 = { 159, 8, 0x60080000 };
Battle D_800A4E7C = { 159, 8, 0x60080000 };
Battle D_800A4E88 = { 159, 8, 0x60080000 };
Battle D_800A4E94 = { 159, 8, 0x60080000 };
Battle D_800A4EA0 = { 159, 8, 0x60080000 };
Battle D_800A4EAC = { 159, 8, 0x60080000 };
Battle D_800A4EB8 = { 159, 8, 0x60080000 };
Battle D_800A4EC4 = { 159, 8, 0x60080000 };
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
Battle D_800A4FFC = { 231, 8, 0x60080000 };
Battle D_800A5008 = { 279, 8, 0x600C0000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 331, 8, 0x60080000 };
Battle D_800A502C = { 332, 8, 0x60080000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 177, 8, 0x60080000 };
Battle D_800A5050 = { 106, 8, 0x60080000 };
BattleList D_800A505C = {
    0,
    { &D_800A4FFC, &D_800A5008, &D_800A5014, &D_800A5020,
      &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050 },
};
FieldBattles stageBattles[] = {
    { 72, 0, 0, { &D_800A4ED0, &D_800A4F54, &D_800A4FD8, &D_800A505C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x149, 0xD8, 0x49, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x171, 0xD8, 0x71, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x199, 0xD8, 0x99, 0x140, 0x1FE },
};
u16 D_800A512C[] = { 0, 0, 0xFFFF };
u16 D_800A5134[] = { 0, 1, 0xFFFF };
u16 D_800A513C[] = { 0, 1, 0x7205, 0, 0xFFFF };
u16 D_800A5148[] = { 0, 1, 0x7205, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5158[] = { 0x762F, 1, 0xFFFF };
u16 D_800A5160[] = { 0, 1, 0x7205, 1, 0x7208, 1, 0xE22, 0, 0xFFFF };
u16 D_800A5174[] = { 0x7400, 1, 0xE22, 1, 0xFFFF };
u16 D_800A5180[] = { 0, 1, 0x7205, 1, 0x7208, 1, 0xE22, 1, 0xFFFF };
u16 D_800A5194[] = { 0, 0, 0xFFFF };
u16 D_800A519C[] = { 0, 1, 0xFFFF };
u16 D_800A51A4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51B0[] = { 0, 1, 0x7209, 1, 0xE43, 0, 0xFFFF };
u16 D_800A51C0[] = { 0x7400, 1, 0xE43, 1, 0xFFFF };
u16 D_800A51CC[] = { 0, 1, 0x7209, 1, 0xE43, 1, 0x720B, 0, 0xFFFF };
u16 D_800A51E0[] = { 0, 1, 0x7209, 1, 0xE43, 1, 0x720B, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x782F, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A5204[] = { 0x10, 0, 0xFFFF };
u16 D_800A520C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5214[] = { 0x10, 1, 0xFFFF };
u16 D_800A521C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5228[] = {
    { NULL, NULL, 0xEA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5240[] = {
    { D_800A512C, D_800A5134, 0x244 },
    { D_800A513C, NULL, 0x245 },
    { D_800A5148, D_800A5158, 0x246 },
    { D_800A5160, D_800A5174, 0x247 },
    { D_800A5180, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5288[] = {
    { D_800A5194, D_800A519C, 0x24C },
    { D_800A51A4, NULL, 0x24E },
    { D_800A51B0, D_800A51C0, 0x24D },
    { D_800A51CC, NULL, 0x248 },
    { D_800A51E0, D_800A51F4, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D0[] = {
    { D_800A51FC, NULL, 0x39D },
    { D_800A5204, D_800A520C, 0x249 },
    { D_800A5214, D_800A521C, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5300[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5318[] = {
    { NULL, NULL, 0xE9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5330[] = {
    { NULL, NULL, 0xEB },
    { NULL, NULL, 0 },
};
u16 D_800A5348[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5354[] = { 0x8192, 1, 0x7019, 1, 0x11, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5368[] = { 0x8192, 1, 0x7019, 1, 0x11, 0, 0x8014, 1, 0xFFFF };
u16 D_800A537C[] = { 0x8192, 1, 0x11, 1, 0x7019, 1, 0xFFFF };
u16 D_800A538C[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5398[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53A4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A53AC = { D_800A5348, D_800A5228, 0x36, 4, 897, 514, 1 };
FieldActorEntry D_800A53C0 = { D_800A5354, D_800A5240, 0x45, 5, 690, 251, 7 };
FieldActorEntry D_800A53D4 = { D_800A5368, D_800A5288, 0x45, 5, 690, 251, 7 };
FieldActorEntry D_800A53E8 = { D_800A537C, D_800A52D0, 0x45, 5, 690, 251, 7 };
FieldActorEntry D_800A53FC = { D_800A538C, D_800A5300, 0x45, 5, 690, 251, 7 };
FieldActorEntry D_800A5410 = { D_800A5398, D_800A5318, 0x9D, 6, 897, 514, 1 };
FieldActorEntry D_800A5424 = { D_800A53A4, D_800A5330, 0x9D, 6, 897, 514, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A53AC,
    &D_800A53C0,
    &D_800A53D4,
    &D_800A53E8,
    &D_800A53FC,
    &D_800A5410,
    &D_800A5424,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 1100, 594, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 1107, 563, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1187, 603, 0, 0 },
    { 1, 0, 0x40, 2, 0x14, 0, 0, 0, 0, 0, 545, 152, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 273, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 799, 391, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1031, 584, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 101, 298, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 401, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 429, 522, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 534, 322, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 619, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 821, 283, 0, 0 },
    { 1, 0, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 185, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x16, 0, 0, 0, 0, 0, 233, 298, 0, 0 },
    { 1, 0, 0x40, 6, 0x17, 0, 0, 0, 0, 0, 281, 322, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 1072, 384, 422, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 1104, 368, 412, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 1120, 368, 404, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 1136, 368, 396, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 1152, 352, 389, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 1168, 352, 381, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 400, 144, 191, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 384, 160, 197, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 446, 290, 318, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 766, 258, 287, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 486, 160, 189, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 1099, 491, 511, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 207, 286, 286, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 255, 310, 310, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 303, 334, 334, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 735, 581, 581, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 799, 581, 581, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 864, 470, 470, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 912, 446, 446, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 960, 422, 422, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A2, 0x340, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A6, 0xA8, 0x132, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A5, 0x1F2, 0x164, 3, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x48, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
