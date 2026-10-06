#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x69C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6AC
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF100, 0xD800};
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
extern u16 D_800A52E4[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A52F0[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A52FC[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5308[];
extern FieldTalk D_800A51F4[];
extern FieldTalk D_800A520C[];
extern u16 D_800A5314[];
extern FieldTalk D_800A5224[];
extern u16 D_800A5320[];
extern FieldTalk D_800A523C[];
extern u16 D_800A5328[];
extern FieldTalk D_800A5254[];
extern u16 D_800A5334[];
extern FieldTalk D_800A526C[];
extern u16 D_800A533C[];
extern FieldTalk D_800A5284[];
extern u16 D_800A5348[];
extern FieldTalk D_800A529C[];
extern u16 D_800A5350[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A5358[];
extern FieldTalk D_800A52CC[];
extern FieldActorEntry D_800A5364;
extern FieldActorEntry D_800A5378;
extern FieldActorEntry D_800A538C;
extern FieldActorEntry D_800A53A0;
extern FieldActorEntry D_800A53B4;
extern FieldActorEntry D_800A53C8;
extern FieldActorEntry D_800A53DC;
extern FieldActorEntry D_800A53F0;
extern FieldActorEntry D_800A5404;
extern FieldActorEntry D_800A5418;
extern FieldActorEntry D_800A542C;
extern FieldActorEntry D_800A5440;
extern FieldActorEntry D_800A5454;

Battle D_800A4E90 = { 151, 13, 0x60080000 };
Battle D_800A4E9C = { 151, 13, 0x60080000 };
Battle D_800A4EA8 = { 151, 13, 0x60080000 };
Battle D_800A4EB4 = { 151, 13, 0x60080000 };
Battle D_800A4EC0 = { 94, 13, 0x60080000 };
Battle D_800A4ECC = { 94, 13, 0x60080000 };
Battle D_800A4ED8 = { 94, 13, 0x60080000 };
Battle D_800A4EE4 = { 94, 13, 0x60080000 };
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
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 329, 13, 0x60080000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 99, 13, 0x60080000 };
Battle D_800A5070 = { 0, 0, 0x60040000 };
BattleList D_800A507C = {
    0,
    { &D_800A501C, &D_800A5028, &D_800A5034, &D_800A5040,
      &D_800A504C, &D_800A5058, &D_800A5064, &D_800A5070 },
};
FieldBattles stageBattles[] = {
    { 63, 0, 0, { &D_800A4EF0, &D_800A4F74, &D_800A4FF8, &D_800A507C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x158, 0xC0, 0x58, 0x150, 0x1FF },
    { 0x140, 0x100, 0x170, 0x180, 0xC0, 0x80, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1A8, 0xC0, 0xA8, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1C8, 0xC0, 0xC8, 0x150, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x140, 0x1D8, 0, 0xD8, 0x160, 0x1FE },
    { 0x140, 0x100, 0x148, 0x1D8, 0x20, 0xD8, 0x170, 0x1FE },
    { 0x140, 0x100, 0x150, 0x1D8, 0x40, 0xD8, 0x150, 0x1FD },
    { 0x180, 0x100, 0x196, 0x100, 0x158, 0, 0x160, 0x1FD },
};
FieldTalk D_800A51AC[] = {
    { NULL, NULL, 0x72 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x75 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x7B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x70 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0x73 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, NULL, 0x76 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0x77 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0x7C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0x7A },
    { NULL, NULL, 0 },
};
u16 D_800A52E4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52F0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5308[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5314[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5320[] = { 0x6027, 1, 0xFFFF };
u16 D_800A5328[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5334[] = { 0x6027, 1, 0xFFFF };
u16 D_800A533C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5348[] = { 0x6027, 1, 0xFFFF };
u16 D_800A5350[] = { 0x6027, 1, 0xFFFF };
u16 D_800A5358[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
FieldActorEntry D_800A5364 = { D_800A52E4, D_800A51AC, 0x2F, 4, 319, 313, 1 };
FieldActorEntry D_800A5378 = { D_800A52F0, D_800A51C4, 0x30, 5, 361, 749, 7 };
FieldActorEntry D_800A538C = { D_800A52FC, D_800A51DC, 0x39, 6, 768, 664, 1 };
FieldActorEntry D_800A53A0 = { D_800A5308, D_800A51F4, 0x3A, 7, 760, 260, 3 };
FieldActorEntry D_800A53B4 = { NULL, D_800A520C, 0x3F, 8, 319, 600, 1 };
FieldActorEntry D_800A53C8 = { D_800A5314, D_800A5224, 0x9D, 9, 319, 313, 1 };
FieldActorEntry D_800A53DC = { D_800A5320, D_800A523C, 0x9D, 9, 319, 313, 1 };
FieldActorEntry D_800A53F0 = { D_800A5328, D_800A5254, 0x9E, 0xA, 361, 749, 7 };
FieldActorEntry D_800A5404 = { D_800A5334, D_800A526C, 0x9E, 0xA, 361, 749, 7 };
FieldActorEntry D_800A5418 = { D_800A533C, D_800A5284, 0x9F, 0xB, 768, 664, 1 };
FieldActorEntry D_800A542C = { D_800A5348, D_800A529C, 0x9F, 0xB, 768, 664, 1 };
FieldActorEntry D_800A5440 = { D_800A5350, D_800A52B4, 0xA0, 0xC, 760, 260, 3 };
FieldActorEntry D_800A5454 = { D_800A5358, D_800A52CC, 0xA0, 0xC, 760, 260, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5364,
    &D_800A5378,
    &D_800A538C,
    &D_800A53A0,
    &D_800A53B4,
    &D_800A53C8,
    &D_800A53DC,
    &D_800A53F0,
    &D_800A5404,
    &D_800A5418,
    &D_800A542C,
    &D_800A5440,
    &D_800A5454,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 68, 778, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 159, 733, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 13, 758, 0, 0 },
    { 1, 0x64, 0x40, 6, 2, 0, 0, 0, 0, 0, 89, 730, 0, 0 },
    { 1, 0, 0x80, 4, 5, 0, 0, 0, 0, 0, 63, 783, 795, 0 },
    { 1, 0, 0x72, 4, 0, 0, 0, 0, 0, 0, 0, 657, 795, 0 },
    { 1, 0, 0x76, 4, 1, 0, 0, 0, 0, 0, 40, 677, 795, 0 },
    { 1, 0, 0x60, 4, 3, 0, 0, 0, 0, 0, 290, 502, 595, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 119, 387, 387, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 156, 539, 539, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 168, 339, 339, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 169, 579, 579, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 298, 298, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 185, 379, 379, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 206, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 356, 356, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 238, 215, 215, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 249, 635, 635, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 280, 667, 667, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 296, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 312, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 360, 198, 198, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 392, 323, 323, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 631, 631, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 423, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 424, 291, 291, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 440, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 472, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 487, 307, 307, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 552, 451, 451, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 595, 479, 479, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 595, 595, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 691, 691, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 600, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 608, 823, 823, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 623, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 625, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 642, 763, 763, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 648, 803, 803, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 680, 570, 570, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 728, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 760, 195, 195, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 833, 659, 659, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 840, 267, 267, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 845, 571, 571, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 871, 315, 315, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x290, 0x598, 0x260, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x296, 0x154, 0x6A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x294, 0x80, 0x31C, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x292, 0x1B2, 0x156, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
