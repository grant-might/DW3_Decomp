#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x565
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x575
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1F500, 0x10300};
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

extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern BattleList D_800A4EF8;
extern BattleList D_800A4F7C;
extern BattleList D_800A5000;
extern BattleList D_800A5084;
extern u16 D_800A51C4[];
extern u16 D_800A51CC[];
extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern u16 D_800A51F0[];
extern u16 D_800A5200[];
extern u16 D_800A5370[];
extern FieldTalk D_800A5214[];
extern u16 D_800A537C[];
extern FieldTalk D_800A522C[];
extern u16 D_800A5384[];
extern FieldTalk D_800A5244[];
extern u16 D_800A538C[];
extern FieldTalk D_800A525C[];
extern u16 D_800A5394[];
extern FieldTalk D_800A5274[];
extern u16 D_800A53A0[];
extern FieldTalk D_800A528C[];
extern u16 D_800A53AC[];
extern FieldTalk D_800A52A4[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A52BC[];
extern u16 D_800A53C0[];
extern FieldTalk D_800A52D4[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A52EC[];
extern u16 D_800A53D4[];
extern FieldTalk D_800A5304[];
extern u16 D_800A53E0[];
extern FieldTalk D_800A531C[];
extern u16 D_800A53E8[];
extern FieldTalk D_800A5334[];
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;
extern FieldActorEntry D_800A5424;
extern FieldActorEntry D_800A5438;
extern FieldActorEntry D_800A544C;
extern FieldActorEntry D_800A5460;
extern FieldActorEntry D_800A5474;
extern FieldActorEntry D_800A5488;
extern FieldActorEntry D_800A549C;
extern FieldActorEntry D_800A54B0;
extern FieldActorEntry D_800A54C4;
extern FieldActorEntry D_800A54D8;
extern FieldActorEntry D_800A54EC;

Battle D_800A4E98 = { 126, 1, 0x60080000 };
Battle D_800A4EA4 = { 126, 1, 0x60080000 };
Battle D_800A4EB0 = { 126, 1, 0x60080000 };
Battle D_800A4EBC = { 126, 1, 0x60080000 };
Battle D_800A4EC8 = { 126, 1, 0x60080000 };
Battle D_800A4ED4 = { 126, 1, 0x60080000 };
Battle D_800A4EE0 = { 126, 1, 0x60080000 };
Battle D_800A4EEC = { 126, 1, 0x60080000 };
BattleList D_800A4EF8 = {
    3,
    { &D_800A4E98, &D_800A4EA4, &D_800A4EB0, &D_800A4EBC,
      &D_800A4EC8, &D_800A4ED4, &D_800A4EE0, &D_800A4EEC },
};
Battle D_800A4F1C = { 179, 2, 0x60080000 };
Battle D_800A4F28 = { 179, 2, 0x60080000 };
Battle D_800A4F34 = { 179, 2, 0x60080000 };
Battle D_800A4F40 = { 179, 2, 0x60080000 };
Battle D_800A4F4C = { 179, 2, 0x60080000 };
Battle D_800A4F58 = { 179, 2, 0x60080000 };
Battle D_800A4F64 = { 179, 2, 0x60080000 };
Battle D_800A4F70 = { 179, 2, 0x60080000 };
BattleList D_800A4F7C = {
    3,
    { &D_800A4F1C, &D_800A4F28, &D_800A4F34, &D_800A4F40,
      &D_800A4F4C, &D_800A4F58, &D_800A4F64, &D_800A4F70 },
};
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
BattleList D_800A5000 = {
    0,
    { &D_800A4FA0, &D_800A4FAC, &D_800A4FB8, &D_800A4FC4,
      &D_800A4FD0, &D_800A4FDC, &D_800A4FE8, &D_800A4FF4 },
};
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 329, 13, 0x60080000 };
Battle D_800A5054 = { 330, 2, 0x60080000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 93, 13, 0x60080000 };
Battle D_800A5078 = { 180, 2, 0x60080000 };
BattleList D_800A5084 = {
    0,
    { &D_800A5024, &D_800A5030, &D_800A503C, &D_800A5048,
      &D_800A5054, &D_800A5060, &D_800A506C, &D_800A5078 },
};
FieldBattles stageBattles[] = {
    { 94, 0, 0, { &D_800A4EF8, &D_800A4F7C, &D_800A5000, &D_800A5084 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x19F, 0x70, 0x9F, 0x150, 0x1FF },
    { 0x140, 0x100, 0x164, 0x1A7, 0x90, 0xA7, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x1A7, 0xB0, 0xA7, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x1A7, 0xD0, 0xA7, 0x140, 0x1FE },
    { 0x140, 0x100, 0x176, 0x151, 0xD8, 0x51, 0x150, 0x1FE },
    { 0x180, 0x100, 0x18A, 0x100, 0x128, 0, 0x160, 0x1FE },
    { 0x180, 0x100, 0x192, 0x100, 0x148, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x19A, 0x100, 0x168, 0, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1A2, 0x100, 0x188, 0, 0x150, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x177, 0x70, 0x77, 0x160, 0x1FD },
};
u16 D_800A51C4[] = { 0x869A, 1, 0xFFFF };
u16 D_800A51CC[] = { 0, 0, 0x869A, 0, 0xFFFF };
u16 D_800A51D8[] = { 0, 1, 0xFFFF };
u16 D_800A51E0[] = { 0, 1, 0x869A, 0, 0x8496, 0, 0xFFFF };
u16 D_800A51F0[] = { 0, 1, 0x869A, 0, 0x8496, 1, 0xFFFF };
u16 D_800A5200[] = { 0x869A, 1, 0x8699, 0, 0x8496, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5214[] = {
    { NULL, NULL, 0x38 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A522C[] = {
    { NULL, NULL, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5244[] = {
    { NULL, NULL, 0x3C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A525C[] = {
    { NULL, NULL, 0x3B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5274[] = {
    { NULL, NULL, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A528C[] = {
    { NULL, NULL, 0x32 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A4[] = {
    { NULL, NULL, 0x37 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52BC[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D4[] = {
    { NULL, NULL, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52EC[] = {
    { NULL, NULL, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5304[] = {
    { NULL, NULL, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A531C[] = {
    { NULL, NULL, 0x33 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5334[] = {
    { D_800A51C4, NULL, 0x2EE },
    { D_800A51CC, D_800A51D8, 0x2EF },
    { D_800A51E0, NULL, 0x2F0 },
    { D_800A51F0, D_800A5200, 0x2F1 },
    { NULL, NULL, 0 },
};
u16 D_800A5370[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A537C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5384[] = { 0x602B, 1, 0xFFFF };
u16 D_800A538C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5394[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A53A0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A53AC[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53C0[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A53CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53D4[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53E0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53E8[] = { 0x7045, 1, 0x704D, 1, 0x8699, 1, 0x869A, 0, 0xFFFF };
FieldActorEntry D_800A53FC = { D_800A5370, D_800A5214, 0x32, 4, 299, 282, 3 };
FieldActorEntry D_800A5410 = { D_800A537C, D_800A522C, 0x34, 5, 299, 282, 3 };
FieldActorEntry D_800A5424 = { D_800A5384, D_800A5244, 0x36, 6, 288, 424, 1 };
FieldActorEntry D_800A5438 = { D_800A538C, D_800A525C, 0x38, 7, 481, 520, 1 };
FieldActorEntry D_800A544C = { D_800A5394, D_800A5274, 0x39, 8, 288, 424, 7 };
FieldActorEntry D_800A5460 = { D_800A53A0, D_800A528C, 0x3A, 9, 481, 520, 3 };
FieldActorEntry D_800A5474 = { D_800A53AC, D_800A52A4, 0x9D, 0xA, 299, 282, 3 };
FieldActorEntry D_800A5488 = { D_800A53B8, D_800A52BC, 0x9D, 0xA, 299, 282, 3 };
FieldActorEntry D_800A549C = { D_800A53C0, D_800A52D4, 0x9E, 0xB, 288, 424, 7 };
FieldActorEntry D_800A54B0 = { D_800A53CC, D_800A52EC, 0x9E, 0xB, 288, 424, 7 };
FieldActorEntry D_800A54C4 = { D_800A53D4, D_800A5304, 0x9F, 0xC, 481, 520, 3 };
FieldActorEntry D_800A54D8 = { D_800A53E0, D_800A531C, 0x9F, 0xC, 481, 520, 3 };
FieldActorEntry D_800A54EC = { D_800A53E8, D_800A5334, 0xA9, 0xD, 640, 593, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A53FC,
    &D_800A5410,
    &D_800A5424,
    &D_800A5438,
    &D_800A544C,
    &D_800A5460,
    &D_800A5474,
    &D_800A5488,
    &D_800A549C,
    &D_800A54B0,
    &D_800A54C4,
    &D_800A54D8,
    &D_800A54EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x50, 2, 5, 0, 0, 0, 0, 0, 392, 90, 0, 0 },
    { 1, 0, 0x50, 2, 5, 0, 0, 0, 0, 0, 696, 287, 0, 0 },
    { 1, 0, 0x50, 2, 0xB, 0, 0, 0, 0, 0, 688, 97, 0, 0 },
    { 1, 0, 0x72, 2, 0xC, 0, 0, 0, 0, 0, 784, 47, 0, 0 },
    { 1, 0, 0x80, 2, 0xD, 0, 0, 0, 0, 0, 640, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 98, 416, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 257, 640, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 642, 721, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 307, 524, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 457, 693, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 794, 50, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 496, 558, 575, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 509, 517, 543, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 514, 471, 489, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 276, 499, 511, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 676, 390, 407, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 271, 271, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 239, 239, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 255, 255, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 390, 243, 243, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 247, 247, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 592, 343, 343, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 375, 375, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x102, 0x3AC, 5, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0xE, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x3C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x40, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
