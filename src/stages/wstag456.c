#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x6D9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x6E9
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15E00, 0xD800};
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

extern Battle D_800A4E6C;
extern Battle D_800A4E78;
extern Battle D_800A4E84;
extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4EA8;
extern Battle D_800A4EB4;
extern Battle D_800A4EC0;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern BattleList D_800A4ECC;
extern BattleList D_800A4F50;
extern BattleList D_800A4FD4;
extern BattleList D_800A5058;
extern u16 D_800A5230[];
extern FieldTalk D_800A5158[];
extern u16 D_800A523C[];
extern FieldTalk D_800A5170[];
extern u16 D_800A5248[];
extern FieldTalk D_800A5188[];
extern u16 D_800A5254[];
extern FieldTalk D_800A51A0[];
extern u16 D_800A5260[];
extern FieldTalk D_800A51B8[];
extern u16 D_800A5268[];
extern FieldTalk D_800A51D0[];
extern u16 D_800A5274[];
extern FieldTalk D_800A51E8[];
extern u16 D_800A527C[];
extern FieldTalk D_800A5200[];
extern u16 D_800A5288[];
extern FieldTalk D_800A5218[];
extern FieldActorEntry D_800A5290;
extern FieldActorEntry D_800A52A4;
extern FieldActorEntry D_800A52B8;
extern FieldActorEntry D_800A52CC;
extern FieldActorEntry D_800A52E0;
extern FieldActorEntry D_800A52F4;
extern FieldActorEntry D_800A5308;
extern FieldActorEntry D_800A531C;
extern FieldActorEntry D_800A5330;

Battle D_800A4E6C = { 159, 8, 0x60080000 };
Battle D_800A4E78 = { 159, 8, 0x60080000 };
Battle D_800A4E84 = { 159, 8, 0x60080000 };
Battle D_800A4E90 = { 159, 8, 0x60080000 };
Battle D_800A4E9C = { 159, 8, 0x60080000 };
Battle D_800A4EA8 = { 159, 8, 0x60080000 };
Battle D_800A4EB4 = { 159, 8, 0x60080000 };
Battle D_800A4EC0 = { 159, 8, 0x60080000 };
BattleList D_800A4ECC = {
    3,
    { &D_800A4E6C, &D_800A4E78, &D_800A4E84, &D_800A4E90,
      &D_800A4E9C, &D_800A4EA8, &D_800A4EB4, &D_800A4EC0 },
};
Battle D_800A4EF0 = { 0, 0, 0x60040000 };
Battle D_800A4EFC = { 0, 0, 0x60040000 };
Battle D_800A4F08 = { 0, 0, 0x60040000 };
Battle D_800A4F14 = { 0, 0, 0x60040000 };
Battle D_800A4F20 = { 0, 0, 0x60040000 };
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
BattleList D_800A4F50 = {
    0,
    { &D_800A4EF0, &D_800A4EFC, &D_800A4F08, &D_800A4F14,
      &D_800A4F20, &D_800A4F2C, &D_800A4F38, &D_800A4F44 },
};
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
BattleList D_800A4FD4 = {
    0,
    { &D_800A4F74, &D_800A4F80, &D_800A4F8C, &D_800A4F98,
      &D_800A4FA4, &D_800A4FB0, &D_800A4FBC, &D_800A4FC8 },
};
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 331, 8, 0x60080000 };
Battle D_800A5028 = { 332, 8, 0x60080000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 177, 8, 0x60080000 };
Battle D_800A504C = { 106, 8, 0x60080000 };
BattleList D_800A5058 = {
    0,
    { &D_800A4FF8, &D_800A5004, &D_800A5010, &D_800A501C,
      &D_800A5028, &D_800A5034, &D_800A5040, &D_800A504C },
};
FieldBattles stageBattles[] = {
    { 73, 0, 0, { &D_800A4ECC, &D_800A4F50, &D_800A4FD4, &D_800A5058 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x164, 0x18D, 0x90, 0x8D, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x18D, 0xB0, 0x8D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x164, 0x1B5, 0x90, 0xB5, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x1B5, 0xB0, 0xB5, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x1BD, 0xD0, 0xBD, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x1C0, 0, 0xC0, 0x160, 0x1FE },
};
FieldTalk D_800A5158[] = {
    { NULL, NULL, 0xE1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5170[] = {
    { NULL, NULL, 0xE4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5188[] = {
    { NULL, NULL, 0xE7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A0[] = {
    { NULL, NULL, 0xE6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B8[] = {
    { NULL, NULL, 0xE8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D0[] = {
    { NULL, NULL, 0xE0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E8[] = {
    { NULL, NULL, 0xE2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5200[] = {
    { NULL, NULL, 0xE3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5218[] = {
    { NULL, NULL, 0xE5 },
    { NULL, NULL, 0 },
};
u16 D_800A5230[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A523C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5248[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5254[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5260[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5268[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5274[] = { 0x701A, 1, 0xFFFF };
u16 D_800A527C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5288[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5290 = { D_800A5230, D_800A5158, 0x2F, 4, 993, 520, 1 };
FieldActorEntry D_800A52A4 = { D_800A523C, D_800A5170, 0x33, 5, 881, 311, 7 };
FieldActorEntry D_800A52B8 = { D_800A5248, D_800A5188, 0x3A, 6, 337, 255, 7 };
FieldActorEntry D_800A52CC = { D_800A5254, D_800A51A0, 0x9D, 7, 337, 255, 7 };
FieldActorEntry D_800A52E0 = { D_800A5260, D_800A51B8, 0x9D, 7, 337, 255, 7 };
FieldActorEntry D_800A52F4 = { D_800A5268, D_800A51D0, 0x9E, 8, 993, 520, 1 };
FieldActorEntry D_800A5308 = { D_800A5274, D_800A51E8, 0x9E, 8, 993, 520, 1 };
FieldActorEntry D_800A531C = { D_800A527C, D_800A5200, 0x9F, 9, 881, 311, 7 };
FieldActorEntry D_800A5330 = { D_800A5288, D_800A5218, 0x9F, 9, 881, 311, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5290,
    &D_800A52A4,
    &D_800A52B8,
    &D_800A52CC,
    &D_800A52E0,
    &D_800A52F4,
    &D_800A5308,
    &D_800A531C,
    &D_800A5330,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 250, 247, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 267, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 506, 695, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 534, 116, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1103, 550, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1245, 347, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 147, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 515, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 593, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 705, 666, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 769, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 913, 605, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1003, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1089, 108, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 979, 425, 436, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 674, 460, 490, 0 },
    { 1, 0, 0xDA, 4, 0, 0, 0, 0, 0, 0, 923, 72, 210, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 392, 185, 185, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 481, 549, 549, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 545, 613, 613, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 817, 189, 189, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 865, 165, 165, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A2, 0x570, 0x3B8, 3, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0xFFEC, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
