#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5CA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5DA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xC900, 0xEB00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x14;
    D_800990B4.music = 0x60500000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4EA8;
extern Battle D_800A4EB4;
extern Battle D_800A4EC0;
extern Battle D_800A4ECC;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern BattleList D_800A4EF0;
extern BattleList D_800A4F74;
extern BattleList D_800A4FF8;
extern BattleList D_800A507C;
extern u16 D_800A517C[];
extern u16 D_800A5184[];
extern u16 D_800A518C[];
extern u16 D_800A5198[];
extern u16 D_800A51A8[];
extern u16 D_800A51B0[];
extern u16 D_800A51C4[];
extern u16 D_800A51D0[];
extern u16 D_800A51E4[];
extern u16 D_800A51EC[];
extern u16 D_800A51F4[];
extern u16 D_800A5200[];
extern u16 D_800A5210[];
extern u16 D_800A521C[];
extern u16 D_800A5230[];
extern u16 D_800A5244[];
extern u16 D_800A524C[];
extern u16 D_800A5254[];
extern u16 D_800A525C[];
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A5278[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A544C[];
extern FieldTalk D_800A52A8[];
extern u16 D_800A5458[];
extern FieldTalk D_800A52C0[];
extern u16 D_800A5464[];
extern FieldTalk D_800A52D8[];
extern u16 D_800A5478[];
extern FieldTalk D_800A5320[];
extern u16 D_800A548C[];
extern FieldTalk D_800A5368[];
extern u16 D_800A549C[];
extern FieldTalk D_800A5398[];
extern u16 D_800A54A8[];
extern FieldTalk D_800A53B0[];
extern u16 D_800A54B0[];
extern FieldTalk D_800A53D4[];
extern u16 D_800A54B8[];
extern FieldTalk D_800A53EC[];
extern u16 D_800A54C4[];
extern FieldTalk D_800A5404[];
extern u16 D_800A54CC[];
extern FieldTalk D_800A541C[];
extern u16 D_800A54D8[];
extern FieldTalk D_800A5434[];
extern FieldActorEntry D_800A54E0;
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

Battle D_800A4E90 = { 132, 3, 0x60080000 };
Battle D_800A4E9C = { 132, 3, 0x60080000 };
Battle D_800A4EA8 = { 132, 3, 0x60080000 };
Battle D_800A4EB4 = { 132, 3, 0x60080000 };
Battle D_800A4EC0 = { 133, 3, 0x60080000 };
Battle D_800A4ECC = { 133, 3, 0x60080000 };
Battle D_800A4ED8 = { 169, 3, 0x60080000 };
Battle D_800A4EE4 = { 169, 3, 0x60080000 };
BattleList D_800A4EF0 = {
    3,
    { &D_800A4E90, &D_800A4E9C, &D_800A4EA8, &D_800A4EB4,
      &D_800A4EC0, &D_800A4ECC, &D_800A4ED8, &D_800A4EE4 },
};
Battle D_800A4F14 = { 0, 0, 0x60040000 };
Battle D_800A4F20 = { 0, 0, 0x60040000 };
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
BattleList D_800A4F74 = {
    0,
    { &D_800A4F14, &D_800A4F20, &D_800A4F2C, &D_800A4F38,
      &D_800A4F44, &D_800A4F50, &D_800A4F5C, &D_800A4F68 },
};
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
BattleList D_800A4FF8 = {
    0,
    { &D_800A4F98, &D_800A4FA4, &D_800A4FB0, &D_800A4FBC,
      &D_800A4FC8, &D_800A4FD4, &D_800A4FE0, &D_800A4FEC },
};
Battle D_800A501C = { 237, 3, 0x60080000 };
Battle D_800A5028 = { 285, 3, 0x600C0000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 334, 2, 0x60080000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 0, 0, 0x60040000 };
Battle D_800A5070 = { 180, 2, 0x60080000 };
BattleList D_800A507C = {
    0,
    { &D_800A501C, &D_800A5028, &D_800A5034, &D_800A5040,
      &D_800A504C, &D_800A5058, &D_800A5064, &D_800A5070 },
};
FieldBattles stageBattles[] = {
    { 96, 0, 0, { &D_800A4EF0, &D_800A4F74, &D_800A4FF8, &D_800A507C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x190, 0x98, 0x90, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x190, 0xD8, 0x90, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x190, 0xB8, 0x90, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x178, 0x68, 0x78, 0x140, 0x1FE },
    { 0x140, 0x100, 0x154, 0x1A8, 0x50, 0xA8, 0x150, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x1A8, 0x70, 0xA8, 0x160, 0x1FE },
};
u16 D_800A517C[] = { 0, 0, 0xFFFF };
u16 D_800A5184[] = { 0, 1, 0xFFFF };
u16 D_800A518C[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A5198[] = { 0, 1, 0x7207, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51A8[] = { 0x7635, 1, 0xFFFF };
u16 D_800A51B0[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE28, 0, 0xFFFF };
u16 D_800A51C4[] = { 0xE28, 1, 0x7400, 1, 0xFFFF };
u16 D_800A51D0[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE28, 1, 0xFFFF };
u16 D_800A51E4[] = { 0, 0, 0xFFFF };
u16 D_800A51EC[] = { 0, 1, 0xFFFF };
u16 D_800A51F4[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A5200[] = { 0, 1, 0x720A, 1, 0xE49, 0, 0xFFFF };
u16 D_800A5210[] = { 0x7400, 1, 0xE49, 1, 0xFFFF };
u16 D_800A521C[] = { 0, 1, 0x720A, 1, 0xE49, 1, 0x720C, 0, 0xFFFF };
u16 D_800A5230[] = { 0, 1, 0x720A, 1, 0xE49, 1, 0x720C, 1, 0xFFFF };
u16 D_800A5244[] = { 0x7835, 1, 0xFFFF };
u16 D_800A524C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5254[] = { 0x10, 0, 0xFFFF };
u16 D_800A525C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5264[] = { 0x10, 1, 0xFFFF };
u16 D_800A526C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5278[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A5284[] = { 0x9409, 1, 0xFFFF };
u16 D_800A528C[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A5298[] = { 0x940A, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x940D, 1, 0xFFFF };
FieldTalk D_800A52A8[] = {
    { NULL, NULL, 0x1C0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C0[] = {
    { NULL, NULL, 0x1BE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D8[] = {
    { D_800A517C, D_800A5184, 0x244 },
    { D_800A518C, NULL, 0x245 },
    { D_800A5198, D_800A51A8, 0x246 },
    { D_800A51B0, D_800A51C4, 0x247 },
    { D_800A51D0, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5320[] = {
    { D_800A51E4, D_800A51EC, 0x24C },
    { D_800A51F4, NULL, 0x24E },
    { D_800A5200, D_800A5210, 0x24D },
    { D_800A521C, NULL, 0x248 },
    { D_800A5230, D_800A5244, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5368[] = {
    { D_800A524C, NULL, 0x39D },
    { D_800A5254, D_800A525C, 0x249 },
    { D_800A5264, D_800A526C, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5398[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B0[] = {
    { D_800A5278, D_800A5284, 0x2D9 },
    { D_800A528C, D_800A5298, 0x2D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53D4[] = {
    { NULL, D_800A52A0, 0x2D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53EC[] = {
    { NULL, NULL, 0x1BF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5404[] = {
    { NULL, NULL, 0x1BF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A541C[] = {
    { NULL, NULL, 0x1C1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5434[] = {
    { NULL, NULL, 0x1C1 },
    { NULL, NULL, 0 },
};
u16 D_800A544C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5458[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5464[] = { 0x8192, 1, 0x11, 0, 0x7019, 1, 0x8014, 0, 0xFFFF };
u16 D_800A5478[] = { 0x7019, 1, 0x8192, 1, 0x11, 0, 0x8014, 1, 0xFFFF };
u16 D_800A548C[] = { 0x8192, 1, 0x11, 1, 0x7019, 1, 0xFFFF };
u16 D_800A549C[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A54A8[] = { 0x802A, 0, 0xFFFF };
u16 D_800A54B0[] = { 0x802A, 1, 0xFFFF };
u16 D_800A54B8[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A54C4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A54CC[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A54D8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A54E0 = { D_800A544C, D_800A52A8, 0x32, 4, 748, 281, 7 };
FieldActorEntry D_800A54F4 = { D_800A5458, D_800A52C0, 0x3A, 5, 537, 413, 1 };
FieldActorEntry D_800A5508 = { D_800A5464, D_800A52D8, 0x45, 6, 333, 716, 1 };
FieldActorEntry D_800A551C = { D_800A5478, D_800A5320, 0x45, 6, 333, 716, 1 };
FieldActorEntry D_800A5530 = { D_800A548C, D_800A5368, 0x45, 6, 333, 716, 1 };
FieldActorEntry D_800A5544 = { D_800A549C, D_800A5398, 0x45, 6, 333, 716, 1 };
FieldActorEntry D_800A5558 = { D_800A54A8, D_800A53B0, 0x8B, 7, 730, 440, 7 };
FieldActorEntry D_800A556C = { D_800A54B0, D_800A53D4, 0x8B, 7, 730, 440, 7 };
FieldActorEntry D_800A5580 = { D_800A54B8, D_800A53EC, 0x9D, 8, 537, 413, 1 };
FieldActorEntry D_800A5594 = { D_800A54C4, D_800A5404, 0x9D, 8, 537, 413, 1 };
FieldActorEntry D_800A55A8 = { D_800A54CC, D_800A541C, 0x9E, 9, 748, 281, 7 };
FieldActorEntry D_800A55BC = { D_800A54D8, D_800A5434, 0x9E, 9, 748, 281, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A54E0,
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 153, 305, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 875, 481, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 391, 837, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 693, 860, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 826, 679, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 290, 854, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 602, 785, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 817, 793, 0, 0 },
    { 1, 0, 0x40, 6, 2, 0, 0, 0, 0, 0, 541, 351, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 480, 468, 0, 0 },
    { 1, 0, 0x5D, 4, 0, 0, 0, 0, 0, 0, 621, 413, 490, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B4, 0x570, 0x3C0, 3, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0xB, 2 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xD, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1C0, 0x272, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1CF, 0x2D8, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE7, 0x46, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x19, 0x46, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xD, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
