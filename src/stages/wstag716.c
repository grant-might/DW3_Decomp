#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x670
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x680
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10700, 0xAF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3E;
    D_800990B4.music = 0x60F80000;
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
extern u16 D_800A5278[];
extern FieldTalk D_800A5158[];
extern u16 D_800A5284[];
extern FieldTalk D_800A5170[];
extern u16 D_800A528C[];
extern FieldTalk D_800A5188[];
extern u16 D_800A5298[];
extern FieldTalk D_800A51A0[];
extern u16 D_800A52A4[];
extern FieldTalk D_800A51B8[];
extern u16 D_800A52AC[];
extern FieldTalk D_800A51D0[];
extern u16 D_800A52B8[];
extern FieldTalk D_800A51E8[];
extern u16 D_800A52C0[];
extern FieldTalk D_800A5200[];
extern u16 D_800A52CC[];
extern FieldTalk D_800A5218[];
extern u16 D_800A52D4[];
extern FieldTalk D_800A5230[];
extern u16 D_800A52E0[];
extern FieldTalk D_800A5248[];
extern u16 D_800A52E8[];
extern FieldTalk D_800A5260[];
extern FieldActorEntry D_800A52F0;
extern FieldActorEntry D_800A5304;
extern FieldActorEntry D_800A5318;
extern FieldActorEntry D_800A532C;
extern FieldActorEntry D_800A5340;
extern FieldActorEntry D_800A5354;
extern FieldActorEntry D_800A5368;
extern FieldActorEntry D_800A537C;
extern FieldActorEntry D_800A5390;
extern FieldActorEntry D_800A53A4;
extern FieldActorEntry D_800A53B8;
extern FieldActorEntry D_800A53CC;

Battle D_800A4E4C = { 160, 14, 0x60080000 };
Battle D_800A4E58 = { 160, 14, 0x60080000 };
Battle D_800A4E64 = { 160, 14, 0x60080000 };
Battle D_800A4E70 = { 160, 14, 0x60080000 };
Battle D_800A4E7C = { 160, 14, 0x60080000 };
Battle D_800A4E88 = { 160, 14, 0x60080000 };
Battle D_800A4E94 = { 160, 14, 0x60080000 };
Battle D_800A4EA0 = { 160, 14, 0x60080000 };
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
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 333, 14, 0x60080000 };
Battle D_800A5008 = { 334, 14, 0x60080000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 187, 14, 0x60080000 };
Battle D_800A502C = { 186, 14, 0x60080000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 118, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x177, 0, 0x77, 0x160, 0x1FF },
    { 0x140, 0x100, 0x164, 0x16C, 0x90, 0x6C, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x176, 0x50, 0x76, 0x150, 0x1FE },
    { 0x140, 0x100, 0x148, 0x177, 0x20, 0x77, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x177, 0xB0, 0x77, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x177, 0xD0, 0x77, 0x150, 0x1FD },
    { 0x140, 0x100, 0x161, 0x194, 0x84, 0x94, 0x160, 0x1FD },
    { 0x140, 0x100, 0x140, 0x197, 0, 0x97, 0x170, 0x1FD },
};
FieldTalk D_800A5158[] = {
    { NULL, NULL, 0x295 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5170[] = {
    { NULL, NULL, 0x297 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5188[] = {
    { NULL, NULL, 0x291 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A0[] = {
    { NULL, NULL, 0x293 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B8[] = {
    { NULL, NULL, 0x298 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D0[] = {
    { NULL, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E8[] = {
    { NULL, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5200[] = {
    { NULL, NULL, 0x296 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5218[] = {
    { NULL, NULL, 0x296 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5230[] = {
    { NULL, NULL, 0x294 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5248[] = {
    { NULL, NULL, 0x294 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5260[] = {
    { NULL, NULL, 0x299 },
    { NULL, NULL, 0 },
};
u16 D_800A5278[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5284[] = { 0x602B, 1, 0xFFFF };
u16 D_800A528C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5298[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52A4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A52AC[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A52B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52C0[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A52CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A52E0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52E8[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A52F0 = { D_800A5278, D_800A5158, 0x2E, 4, 272, 209, 7 };
FieldActorEntry D_800A5304 = { D_800A5284, D_800A5170, 0x2E, 4, 529, 392, 1 };
FieldActorEntry D_800A5318 = { D_800A528C, D_800A5188, 0x2F, 5, 432, 392, 3 };
FieldActorEntry D_800A532C = { D_800A5298, D_800A51A0, 0x33, 6, 257, 432, 5 };
FieldActorEntry D_800A5340 = { D_800A52A4, D_800A51B8, 0x41, 7, 432, 392, 7 };
FieldActorEntry D_800A5354 = { D_800A52AC, D_800A51D0, 0x9D, 8, 432, 392, 3 };
FieldActorEntry D_800A5368 = { D_800A52B8, D_800A51E8, 0x9D, 8, 432, 392, 3 };
FieldActorEntry D_800A537C = { D_800A52C0, D_800A5200, 0x9E, 9, 272, 209, 7 };
FieldActorEntry D_800A5390 = { D_800A52CC, D_800A5218, 0x9E, 9, 272, 209, 7 };
FieldActorEntry D_800A53A4 = { D_800A52D4, D_800A5230, 0x9F, 0xA, 257, 432, 5 };
FieldActorEntry D_800A53B8 = { D_800A52E0, D_800A5248, 0x9F, 0xA, 257, 432, 5 };
FieldActorEntry D_800A53CC = { D_800A52E8, D_800A5260, 0xEB, 0xB, 512, 520, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A52F0,
    &D_800A5304,
    &D_800A5318,
    &D_800A532C,
    &D_800A5340,
    &D_800A5354,
    &D_800A5368,
    &D_800A537C,
    &D_800A5390,
    &D_800A53A4,
    &D_800A53B8,
    &D_800A53CC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 49, 138, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 128, 512, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 222, 441, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 600, 352, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 615, 376, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 640, 368, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 5, 6, 0, 21, 133, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 800, 511, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x38, 4, 0, 243, 53, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x38, 4, 0, 270, 56, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 5, 6, 0, 234, 51, 0, 0 },
    { 1, 0, 0x40, 4, 0x46, 0, 0, 0, 0, 0, 381, 406, 458, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 665, 307, 322, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 235, 368, 374, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 128, 120, 175, 0 },
    { 1, 0, 0x4F, 4, 9, 0, 0, 0, 0, 0, 65, 377, 443, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 152, 152, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 352, 128, 128, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 592, 199, 199, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 183, 183, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 704, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 736, 239, 239, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 263, 263, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CD, 0xB4, 0x98, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CF, 0x298, 0x134, 3, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0x10, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0xF, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x170, 0x98, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x180, 0xE0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0xFFDC, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFC8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
