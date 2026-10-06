#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x581
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x591
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xFE00, 0xA600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2E;
    D_800990B4.music = 0x60B80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E48;
extern Battle D_800A4E54;
extern Battle D_800A4E60;
extern Battle D_800A4E6C;
extern Battle D_800A4E78;
extern Battle D_800A4E84;
extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4ECC;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern BattleList D_800A4EA8;
extern BattleList D_800A4F2C;
extern BattleList D_800A4FB0;
extern BattleList D_800A5034;
extern u16 D_800A50F4[];
extern u16 D_800A5104[];
extern u16 D_800A510C[];
extern u16 D_800A5114[];
extern u16 D_800A5120[];
extern u16 D_800A5130[];
extern u16 D_800A5138[];
extern u16 D_800A514C[];
extern u16 D_800A5158[];
extern u16 D_800A516C[];
extern u16 D_800A5174[];
extern u16 D_800A517C[];
extern u16 D_800A5188[];
extern u16 D_800A5198[];
extern u16 D_800A51A4[];
extern u16 D_800A51B8[];
extern u16 D_800A51CC[];
extern u16 D_800A51D4[];
extern u16 D_800A51DC[];
extern u16 D_800A51E4[];
extern u16 D_800A51EC[];
extern u16 D_800A51F4[];
extern u16 D_800A52F0[];
extern FieldTalk D_800A5200[];
extern u16 D_800A52F8[];
extern FieldTalk D_800A5218[];
extern u16 D_800A530C[];
extern FieldTalk D_800A5260[];
extern u16 D_800A5320[];
extern FieldTalk D_800A52A8[];
extern u16 D_800A532C[];
extern FieldTalk D_800A52C0[];
extern FieldActorEntry D_800A533C;
extern FieldActorEntry D_800A5350;
extern FieldActorEntry D_800A5364;
extern FieldActorEntry D_800A5378;
extern FieldActorEntry D_800A538C;

Battle D_800A4E48 = { 151, 1, 0x60080000 };
Battle D_800A4E54 = { 151, 1, 0x60080000 };
Battle D_800A4E60 = { 151, 1, 0x60080000 };
Battle D_800A4E6C = { 151, 1, 0x60080000 };
Battle D_800A4E78 = { 94, 1, 0x60080000 };
Battle D_800A4E84 = { 94, 1, 0x60080000 };
Battle D_800A4E90 = { 94, 1, 0x60080000 };
Battle D_800A4E9C = { 94, 1, 0x60080000 };
BattleList D_800A4EA8 = {
    3,
    { &D_800A4E48, &D_800A4E54, &D_800A4E60, &D_800A4E6C,
      &D_800A4E78, &D_800A4E84, &D_800A4E90, &D_800A4E9C },
};
Battle D_800A4ECC = { 151, 1, 0x60080000 };
Battle D_800A4ED8 = { 151, 1, 0x60080000 };
Battle D_800A4EE4 = { 151, 1, 0x60080000 };
Battle D_800A4EF0 = { 151, 1, 0x60080000 };
Battle D_800A4EFC = { 94, 1, 0x60080000 };
Battle D_800A4F08 = { 94, 1, 0x60080000 };
Battle D_800A4F14 = { 94, 1, 0x60080000 };
Battle D_800A4F20 = { 94, 1, 0x60080000 };
BattleList D_800A4F2C = {
    1,
    { &D_800A4ECC, &D_800A4ED8, &D_800A4EE4, &D_800A4EF0,
      &D_800A4EFC, &D_800A4F08, &D_800A4F14, &D_800A4F20 },
};
Battle D_800A4F50 = { 100, 4, 0x60080000 };
Battle D_800A4F5C = { 100, 4, 0x60080000 };
Battle D_800A4F68 = { 100, 4, 0x60080000 };
Battle D_800A4F74 = { 100, 4, 0x60080000 };
Battle D_800A4F80 = { 100, 4, 0x60080000 };
Battle D_800A4F8C = { 100, 4, 0x60080000 };
Battle D_800A4F98 = { 100, 4, 0x60080000 };
Battle D_800A4FA4 = { 100, 4, 0x60080000 };
BattleList D_800A4FB0 = {
    3,
    { &D_800A4F50, &D_800A4F5C, &D_800A4F68, &D_800A4F74,
      &D_800A4F80, &D_800A4F8C, &D_800A4F98, &D_800A4FA4 },
};
Battle D_800A4FD4 = { 227, 1, 0x60080000 };
Battle D_800A4FE0 = { 275, 1, 0x600C0000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 329, 1, 0x60080000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 99, 1, 0x60080000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
BattleList D_800A5034 = {
    0,
    { &D_800A4FD4, &D_800A4FE0, &D_800A4FEC, &D_800A4FF8,
      &D_800A5004, &D_800A5010, &D_800A501C, &D_800A5028 },
};
FieldBattles stageBattles[] = {
    { 65, 0, 0, { &D_800A4EA8, &D_800A4F2C, &D_800A4FB0, &D_800A5034 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x140, 0x1FF },
    { 0x180, 0x100, 0x1A6, 0x100, 0x198, 0, 0x160, 0x1FF },
};
u16 D_800A50F4[] = { 0x708F, 1, 0x22A, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5104[] = { 0, 0, 0xFFFF };
u16 D_800A510C[] = { 0, 1, 0xFFFF };
u16 D_800A5114[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A5120[] = { 0, 1, 0x7206, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5130[] = { 0x762B, 1, 0xFFFF };
u16 D_800A5138[] = { 0, 1, 0x7206, 1, 0x7208, 1, 0xE1E, 0, 0xFFFF };
u16 D_800A514C[] = { 0x7400, 1, 0xE1E, 1, 0xFFFF };
u16 D_800A5158[] = { 0, 1, 0x7206, 1, 0x7208, 1, 0xE1E, 1, 0xFFFF };
u16 D_800A516C[] = { 0, 0, 0xFFFF };
u16 D_800A5174[] = { 0, 1, 0xFFFF };
u16 D_800A517C[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A5188[] = { 0, 1, 0x7209, 1, 0xE3F, 0, 0xFFFF };
u16 D_800A5198[] = { 0x7400, 1, 0xE3F, 1, 0xFFFF };
u16 D_800A51A4[] = { 0, 1, 0x7209, 1, 0xE3F, 1, 0x720B, 0, 0xFFFF };
u16 D_800A51B8[] = { 0, 1, 0x7209, 1, 0xE3F, 1, 0x720B, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x782B, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51DC[] = { 0x10, 0, 0xFFFF };
u16 D_800A51E4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51EC[] = { 0x10, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5200[] = {
    { NULL, D_800A50F4, 0x180 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5218[] = {
    { D_800A5104, D_800A510C, 0x244 },
    { D_800A5114, NULL, 0x245 },
    { D_800A5120, D_800A5130, 0x246 },
    { D_800A5138, D_800A514C, 0x247 },
    { D_800A5158, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5260[] = {
    { D_800A516C, D_800A5174, 0x24C },
    { D_800A517C, NULL, 0x24E },
    { D_800A5188, D_800A5198, 0x24D },
    { D_800A51A4, NULL, 0x248 },
    { D_800A51B8, D_800A51CC, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A8[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C0[] = {
    { D_800A51D4, NULL, 0x39C },
    { D_800A51DC, D_800A51E4, 0x249 },
    { D_800A51EC, D_800A51F4, 0x24A },
    { NULL, NULL, 0 },
};
u16 D_800A52F0[] = { 0x22A, 0, 0xFFFF };
u16 D_800A52F8[] = { 0x8192, 1, 0x11, 0, 0x7019, 1, 0x8014, 0, 0xFFFF };
u16 D_800A530C[] = { 0x8192, 1, 0x7019, 1, 0x11, 0, 0x8014, 1, 0xFFFF };
u16 D_800A5320[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A532C[] = { 0x8192, 1, 0x11, 1, 0x7019, 1, 0xFFFF };
FieldActorEntry D_800A533C = { D_800A52F0, D_800A5200, 0x21, 4, 1566, 529, 1 };
FieldActorEntry D_800A5350 = { D_800A52F8, D_800A5218, 0x45, 5, 1408, 936, 1 };
FieldActorEntry D_800A5364 = { D_800A530C, D_800A5260, 0x45, 5, 1408, 936, 1 };
FieldActorEntry D_800A5378 = { D_800A5320, D_800A52A8, 0x45, 5, 1408, 936, 1 };
FieldActorEntry D_800A538C = { D_800A532C, D_800A52C0, 0x45, 5, 1408, 936, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A533C,
    &D_800A5350,
    &D_800A5364,
    &D_800A5378,
    &D_800A538C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x78, 2, 0x12, 0, 0, 0, 0, 0, 1216, 594, 0, 0 },
    { 1, 0, 0x78, 2, 0x14, 0, 0, 0, 0, 0, 1172, 388, 0, 0 },
    { 1, 0, 0x78, 2, 0x16, 0, 0, 0, 0, 0, 998, 303, 0, 0 },
    { 1, 0, 0x78, 2, 0x17, 0, 0, 0, 0, 0, 953, 355, 0, 0 },
    { 1, 0, 0x40, 2, 8, 0, 0, 0, 0, 0, 84, 106, 0, 0 },
    { 1, 0, 0x40, 2, 8, 0, 0, 0, 0, 0, 619, 641, 0, 0 },
    { 1, 0, 0x40, 2, 8, 0, 0, 0, 0, 0, 1198, 301, 0, 0 },
    { 1, 0, 0x40, 2, 8, 0, 0, 0, 0, 0, 1556, 782, 0, 0 },
    { 1, 0, 0x78, 4, 0x13, 0, 0, 0, 0, 0, 1264, 489, 562, 0 },
    { 1, 0, 0x78, 4, 0x15, 0, 0, 0, 0, 0, 905, 338, 355, 0 },
    { 1, 0, 0x78, 4, 0x18, 0, 0, 0, 0, 0, 914, 450, 464, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1115, 218, 262, 0 },
    { 1, 0, 0x44, 4, 1, 0, 0, 0, 0, 0, 828, 359, 400, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 476, 268, 321, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 1216, 649, 682, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1169, 434, 465, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 545, 557, 583, 0 },
    { 1, 0, 0x44, 4, 6, 0, 0, 0, 0, 0, 925, 722, 766, 0 },
    { 1, 0, 0x73, 4, 7, 0, 0, 0, 0, 0, 634, 658, 767, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 133, 133, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 384, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 425, 155, 155, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 432, 311, 311, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 472, 179, 179, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 521, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 263, 263, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 391, 391, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 574, 368, 368, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 607, 214, 214, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 617, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 648, 235, 235, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 695, 259, 259, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 744, 283, 283, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 792, 307, 307, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 840, 331, 331, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 928, 799, 799, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1008, 791, 791, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1376, 751, 751, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1424, 775, 775, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1472, 799, 799, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1520, 967, 967, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x296, 0x4A2, 0x36A, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x299, 0xAA, 0xC3, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x150, 0x268, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 8, 3 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 7, 3 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
