#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x569
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x579
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xCA00, 0x8200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
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
extern u16 D_800A52BC[];
extern FieldTalk D_800A519C[];
extern u16 D_800A52C8[];
extern FieldTalk D_800A51B4[];
extern u16 D_800A52D0[];
extern FieldTalk D_800A51CC[];
extern u16 D_800A52DC[];
extern FieldTalk D_800A51E4[];
extern u16 D_800A52E4[];
extern FieldTalk D_800A51FC[];
extern u16 D_800A52EC[];
extern FieldTalk D_800A5214[];
extern u16 D_800A52F8[];
extern FieldTalk D_800A522C[];
extern u16 D_800A5304[];
extern FieldTalk D_800A5244[];
extern u16 D_800A530C[];
extern FieldTalk D_800A525C[];
extern u16 D_800A5318[];
extern FieldTalk D_800A5274[];
extern u16 D_800A5320[];
extern FieldTalk D_800A528C[];
extern u16 D_800A532C[];
extern FieldTalk D_800A52A4[];
extern FieldActorEntry D_800A5334;
extern FieldActorEntry D_800A5348;
extern FieldActorEntry D_800A535C;
extern FieldActorEntry D_800A5370;
extern FieldActorEntry D_800A5384;
extern FieldActorEntry D_800A5398;
extern FieldActorEntry D_800A53AC;
extern FieldActorEntry D_800A53C0;
extern FieldActorEntry D_800A53D4;
extern FieldActorEntry D_800A53E8;
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;

Battle D_800A4E90 = { 93, 13, 0x60080000 };
Battle D_800A4E9C = { 93, 13, 0x60080000 };
Battle D_800A4EA8 = { 93, 13, 0x60080000 };
Battle D_800A4EB4 = { 93, 13, 0x60080000 };
Battle D_800A4EC0 = { 93, 13, 0x60080000 };
Battle D_800A4ECC = { 93, 13, 0x60080000 };
Battle D_800A4ED8 = { 93, 13, 0x60080000 };
Battle D_800A4EE4 = { 93, 13, 0x60080000 };
BattleList D_800A4EF0 = {
    3,
    { &D_800A4E90, &D_800A4E9C, &D_800A4EA8, &D_800A4EB4,
      &D_800A4EC0, &D_800A4ECC, &D_800A4ED8, &D_800A4EE4 },
};
Battle D_800A4F14 = { 98, 4, 0x60080000 };
Battle D_800A4F20 = { 98, 4, 0x60080000 };
Battle D_800A4F2C = { 98, 4, 0x60080000 };
Battle D_800A4F38 = { 98, 4, 0x60080000 };
Battle D_800A4F44 = { 98, 4, 0x60080000 };
Battle D_800A4F50 = { 98, 4, 0x60080000 };
Battle D_800A4F5C = { 98, 4, 0x60080000 };
Battle D_800A4F68 = { 98, 4, 0x60080000 };
BattleList D_800A4F74 = {
    3,
    { &D_800A4F14, &D_800A4F20, &D_800A4F2C, &D_800A4F38,
      &D_800A4F44, &D_800A4F50, &D_800A4F5C, &D_800A4F68 },
};
Battle D_800A4F98 = { 179, 2, 0x60080000 };
Battle D_800A4FA4 = { 179, 2, 0x60080000 };
Battle D_800A4FB0 = { 179, 2, 0x60080000 };
Battle D_800A4FBC = { 179, 2, 0x60080000 };
Battle D_800A4FC8 = { 179, 2, 0x60080000 };
Battle D_800A4FD4 = { 179, 2, 0x60080000 };
Battle D_800A4FE0 = { 179, 2, 0x60080000 };
Battle D_800A4FEC = { 179, 2, 0x60080000 };
BattleList D_800A4FF8 = {
    3,
    { &D_800A4F98, &D_800A4FA4, &D_800A4FB0, &D_800A4FBC,
      &D_800A4FC8, &D_800A4FD4, &D_800A4FE0, &D_800A4FEC },
};
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 329, 13, 0x60080000 };
Battle D_800A504C = { 330, 2, 0x60080000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 93, 13, 0x60080000 };
Battle D_800A5070 = { 180, 2, 0x60080000 };
BattleList D_800A507C = {
    0,
    { &D_800A501C, &D_800A5028, &D_800A5034, &D_800A5040,
      &D_800A504C, &D_800A5058, &D_800A5064, &D_800A5070 },
};
FieldBattles stageBattles[] = {
    { 95, 0, 0, { &D_800A4EF0, &D_800A4F74, &D_800A4FF8, &D_800A507C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x173, 0x28, 0x73, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x167, 0xC8, 0x67, 0x160, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x16A, 0x68, 0x6A, 0x170, 0x1FF },
    { 0x140, 0x100, 0x152, 0x173, 0x48, 0x73, 0x140, 0x1FE },
    { 0x140, 0x100, 0x162, 0x182, 0x88, 0x82, 0x150, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x182, 0xA8, 0x82, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x18B, 0, 0x8B, 0x170, 0x1FE },
    { 0x140, 0x100, 0x172, 0x18F, 0xC8, 0x8F, 0x140, 0x1FD },
};
FieldTalk D_800A519C[] = {
    { NULL, NULL, 0x44 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B4[] = {
    { NULL, NULL, 0x48 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51CC[] = {
    { NULL, NULL, 0x3E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E4[] = {
    { NULL, NULL, 0x46 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51FC[] = {
    { NULL, NULL, 0x47 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5214[] = {
    { NULL, NULL, 0x41 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A522C[] = {
    { NULL, NULL, 0x40 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5244[] = {
    { NULL, NULL, 0x42 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A525C[] = {
    { NULL, NULL, 0x43 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5274[] = {
    { NULL, NULL, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A528C[] = {
    { NULL, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A4[] = {
    { NULL, NULL, 0x3F },
    { NULL, NULL, 0 },
};
u16 D_800A52BC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52C8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A52D0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A52E4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A52F8[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5304[] = { 0x701A, 1, 0xFFFF };
u16 D_800A530C[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5318[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5320[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A532C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5334 = { D_800A52BC, D_800A519C, 0x2E, 4, 657, 648, 3 };
FieldActorEntry D_800A5348 = { D_800A52C8, D_800A51B4, 0x2E, 4, 657, 648, 3 };
FieldActorEntry D_800A535C = { D_800A52D0, D_800A51CC, 0x33, 5, 316, 322, 1 };
FieldActorEntry D_800A5370 = { D_800A52DC, D_800A51E4, 0x35, 6, 316, 322, 1 };
FieldActorEntry D_800A5384 = { D_800A52E4, D_800A51FC, 0x39, 7, 677, 303, 1 };
FieldActorEntry D_800A5398 = { D_800A52EC, D_800A5214, 0x3A, 8, 641, 161, 3 };
FieldActorEntry D_800A53AC = { D_800A52F8, D_800A522C, 0x9D, 9, 641, 161, 3 };
FieldActorEntry D_800A53C0 = { D_800A5304, D_800A5244, 0x9D, 9, 641, 161, 3 };
FieldActorEntry D_800A53D4 = { D_800A530C, D_800A525C, 0x9E, 0xA, 657, 648, 3 };
FieldActorEntry D_800A53E8 = { D_800A5318, D_800A5274, 0x9E, 0xA, 657, 648, 3 };
FieldActorEntry D_800A53FC = { D_800A5320, D_800A528C, 0x9F, 0xB, 316, 322, 1 };
FieldActorEntry D_800A5410 = { D_800A532C, D_800A52A4, 0x9F, 0xB, 316, 322, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5334,
    &D_800A5348,
    &D_800A535C,
    &D_800A5370,
    &D_800A5384,
    &D_800A5398,
    &D_800A53AC,
    &D_800A53C0,
    &D_800A53D4,
    &D_800A53E8,
    &D_800A53FC,
    &D_800A5410,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 328, 528, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 920, 952, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 149, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 343, 123, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 413, 862, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 91, 124, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 228, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 592, 982, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 674, 776, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 865, 514, 0, 0 },
    { 1, 0, 0xFF, 6, 8, 0, 0, 0, 0, 0, 703, 232, 0, 0 },
    { 1, 0, 0x80, 4, 9, 0, 0, 0, 0, 0, 631, 378, 433, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 593, 792, 804, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 623, 849, 846, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 333, 235, 235, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 381, 259, 259, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 429, 283, 283, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 481, 532, 532, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 486, 775, 775, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 557, 557, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 533, 751, 751, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 541, 699, 699, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 574, 580, 580, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1014, 879, 879, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1054, 899, 899, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x1D2, 0x92, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xC, 0x231, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xC, 0x221, 0x178, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0xD, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 9, 3 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x1D, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFA2, 0x10, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x28, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0x29, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0xD, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
