#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x561
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x571
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xE400, 0xA600};
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
extern u16 D_800A51EC[];
extern FieldTalk D_800A515C[];
extern u16 D_800A51F8[];
extern FieldTalk D_800A5174[];
extern u16 D_800A5204[];
extern FieldTalk D_800A518C[];
extern u16 D_800A5210[];
extern FieldTalk D_800A51A4[];
extern u16 D_800A5218[];
extern FieldTalk D_800A51BC[];
extern u16 D_800A5224[];
extern FieldTalk D_800A51D4[];
extern FieldActorEntry D_800A522C;
extern FieldActorEntry D_800A5240;
extern FieldActorEntry D_800A5254;
extern FieldActorEntry D_800A5268;
extern FieldActorEntry D_800A527C;
extern FieldActorEntry D_800A5290;

Battle D_800A4E90 = { 93, 1, 0x60080000 };
Battle D_800A4E9C = { 93, 1, 0x60080000 };
Battle D_800A4EA8 = { 93, 1, 0x60080000 };
Battle D_800A4EB4 = { 93, 1, 0x60080000 };
Battle D_800A4EC0 = { 127, 1, 0x60080000 };
Battle D_800A4ECC = { 127, 1, 0x60080000 };
Battle D_800A4ED8 = { 127, 1, 0x60080000 };
Battle D_800A4EE4 = { 127, 1, 0x60080000 };
BattleList D_800A4EF0 = {
    3,
    { &D_800A4E90, &D_800A4E9C, &D_800A4EA8, &D_800A4EB4,
      &D_800A4EC0, &D_800A4ECC, &D_800A4ED8, &D_800A4EE4 },
};
Battle D_800A4F14 = { 93, 13, 0x60080000 };
Battle D_800A4F20 = { 93, 13, 0x60080000 };
Battle D_800A4F2C = { 93, 13, 0x60080000 };
Battle D_800A4F38 = { 93, 13, 0x60080000 };
Battle D_800A4F44 = { 127, 13, 0x60080000 };
Battle D_800A4F50 = { 127, 13, 0x60080000 };
Battle D_800A4F5C = { 127, 13, 0x60080000 };
Battle D_800A4F68 = { 127, 13, 0x60080000 };
BattleList D_800A4F74 = {
    3,
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
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 329, 13, 0x60080000 };
Battle D_800A504C = { 330, 8, 0x60080000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 93, 13, 0x60080000 };
Battle D_800A5070 = { 180, 8, 0x60080000 };
BattleList D_800A507C = {
    0,
    { &D_800A501C, &D_800A5028, &D_800A5034, &D_800A5040,
      &D_800A504C, &D_800A5058, &D_800A5064, &D_800A5070 },
};
FieldBattles stageBattles[] = {
    { 93, 0, 0, { &D_800A4EF0, &D_800A4F74, &D_800A4FF8, &D_800A507C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x118, 0x98, 0x18, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x118, 0xB8, 0x18, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x118, 0xD8, 0x18, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x130, 0x50, 0x30, 0x140, 0x1FE },
};
FieldTalk D_800A515C[] = {
    { NULL, NULL, 0x2F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5174[] = {
    { NULL, NULL, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A518C[] = {
    { NULL, NULL, 0x2E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A4[] = {
    { NULL, NULL, 0x30 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51BC[] = {
    { NULL, NULL, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D4[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
u16 D_800A51EC[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A51F8[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5204[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5210[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5218[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5224[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A522C = { D_800A51EC, D_800A515C, 0x30, 4, 391, 309, 7 };
FieldActorEntry D_800A5240 = { D_800A51F8, D_800A5174, 0x33, 5, 361, 684, 1 };
FieldActorEntry D_800A5254 = { D_800A5204, D_800A518C, 0x9D, 6, 391, 309, 7 };
FieldActorEntry D_800A5268 = { D_800A5210, D_800A51A4, 0x9D, 6, 391, 309, 7 };
FieldActorEntry D_800A527C = { D_800A5218, D_800A51BC, 0x9E, 7, 361, 684, 1 };
FieldActorEntry D_800A5290 = { D_800A5224, D_800A51D4, 0x9E, 7, 361, 684, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A522C,
    &D_800A5240,
    &D_800A5254,
    &D_800A5268,
    &D_800A527C,
    &D_800A5290,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 197, 606, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 351, -16, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 511, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 27, 509, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 255, 408, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 28, 586, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 160, 515, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 183, 378, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 226, 226, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 250, 250, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 243, 544, 544, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 267, 602, 602, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 271, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 277, 521, 521, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 159, 159, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 399, 167, 167, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 422, 187, 187, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 431, 568, 568, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 489, 501, 501, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 506, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 542, 228, 228, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 641, 286, 286, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x5F4, 0x39E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x290, 0x138, 0x7A, 7, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC8, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
