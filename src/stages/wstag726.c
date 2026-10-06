#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x678
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x688
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x37700, 0x10700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3F;
    D_800990B4.music = 0x60FC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern BattleList D_800A4EB0;
extern BattleList D_800A4F34;
extern BattleList D_800A4FB8;
extern BattleList D_800A503C;
extern u16 D_800A517C[];
extern u16 D_800A5184[];
extern u16 D_800A518C[];
extern u16 D_800A52E4[];
extern FieldTalk D_800A5194[];
extern u16 D_800A52EC[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A52F8[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5304[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A5310[];
extern FieldTalk D_800A520C[];
extern u16 D_800A5318[];
extern FieldTalk D_800A5224[];
extern u16 D_800A5320[];
extern FieldTalk D_800A523C[];
extern u16 D_800A532C[];
extern FieldTalk D_800A5254[];
extern u16 D_800A5334[];
extern FieldTalk D_800A526C[];
extern u16 D_800A5340[];
extern FieldTalk D_800A5284[];
extern u16 D_800A5348[];
extern FieldTalk D_800A529C[];
extern u16 D_800A5354[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A535C[];
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

Battle D_800A4E50 = { 163, 7, 0x60080000 };
Battle D_800A4E5C = { 163, 7, 0x60080000 };
Battle D_800A4E68 = { 163, 7, 0x60080000 };
Battle D_800A4E74 = { 163, 7, 0x60080000 };
Battle D_800A4E80 = { 137, 7, 0x60080000 };
Battle D_800A4E8C = { 137, 7, 0x60080000 };
Battle D_800A4E98 = { 137, 7, 0x60080000 };
Battle D_800A4EA4 = { 137, 7, 0x60080000 };
BattleList D_800A4EB0 = {
    3,
    { &D_800A4E50, &D_800A4E5C, &D_800A4E68, &D_800A4E74,
      &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4 },
};
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
BattleList D_800A4F34 = {
    0,
    { &D_800A4ED4, &D_800A4EE0, &D_800A4EEC, &D_800A4EF8,
      &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28 },
};
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
BattleList D_800A4FB8 = {
    0,
    { &D_800A4F58, &D_800A4F64, &D_800A4F70, &D_800A4F7C,
      &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC },
};
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 119, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x120, 0xC0, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x162, 0x142, 0x88, 0x42, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x148, 0xA8, 0x48, 0x160, 0x1FE },
    { 0x140, 0x100, 0x172, 0x148, 0xC8, 0x48, 0x170, 0x1FE },
    { 0x140, 0x100, 0x162, 0x16A, 0x88, 0x6A, 0x160, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x170, 0xA8, 0x70, 0x170, 0x1FD },
    { 0x140, 0x100, 0x172, 0x170, 0xC8, 0x70, 0x160, 0x1FC },
    { 0x140, 0x100, 0x16A, 0x190, 0xA8, 0x90, 0x170, 0x1FC },
    { 0x140, 0x100, 0x172, 0x190, 0xC8, 0x90, 0x150, 0x1FB },
    { 0x140, 0x100, 0x160, 0x192, 0x80, 0x92, 0x160, 0x1FB },
};
u16 D_800A517C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5184[] = { 0x6025, 1, 0xFFFF };
u16 D_800A518C[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A5194[] = {
    { D_800A517C, NULL, 0x1F3 },
    { D_800A5184, NULL, 0x1F4 },
    { D_800A518C, NULL, 0x1F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x1F9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x1FB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x1F7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x1FE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0x1FD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0x1F8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0x1F8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, NULL, 0x1FC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0x1FC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0x1FA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0x1FA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0x1F6 },
    { NULL, NULL, 0 },
};
u16 D_800A52E4[] = { 0x701E, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A52F8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5304[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5310[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5318[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5320[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A532C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5334[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5340[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5348[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5354[] = { 0x701A, 1, 0xFFFF };
u16 D_800A535C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5364 = { D_800A52E4, D_800A5194, 0x30, 4, 692, 265, 5 };
FieldActorEntry D_800A5378 = { D_800A52EC, D_800A51C4, 0x31, 5, 161, 321, 1 };
FieldActorEntry D_800A538C = { D_800A52F8, D_800A51DC, 0x32, 6, 737, 324, 7 };
FieldActorEntry D_800A53A0 = { D_800A5304, D_800A51F4, 0x34, 7, 423, 97, 7 };
FieldActorEntry D_800A53B4 = { D_800A5310, D_800A520C, 0x37, 8, 816, 209, 1 };
FieldActorEntry D_800A53C8 = { D_800A5318, D_800A5224, 0x39, 9, 161, 321, 1 };
FieldActorEntry D_800A53DC = { D_800A5320, D_800A523C, 0x9D, 0xA, 423, 97, 7 };
FieldActorEntry D_800A53F0 = { D_800A532C, D_800A5254, 0x9D, 0xA, 423, 97, 7 };
FieldActorEntry D_800A5404 = { D_800A5334, D_800A526C, 0x9E, 0xB, 737, 324, 7 };
FieldActorEntry D_800A5418 = { D_800A5340, D_800A5284, 0x9E, 0xB, 737, 324, 7 };
FieldActorEntry D_800A542C = { D_800A5348, D_800A529C, 0x9F, 0xC, 161, 321, 1 };
FieldActorEntry D_800A5440 = { D_800A5354, D_800A52B4, 0x9F, 0xC, 161, 321, 1 };
FieldActorEntry D_800A5454 = { D_800A535C, D_800A52CC, 0xA0, 0xD, 692, 265, 5 };
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
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 807, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 647, 322, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 714, 356, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 755, 312, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 773, 350, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 830, 322, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 831, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 289, 211, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 317, 214, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 4, 0, 762, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 287, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 482, 16, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 566, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 630, 94, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 243, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 435, 24, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 467, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 909, 158, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 330, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 339, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 658, 77, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 3, 0, 9, 8, 0, 105, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 3, 0, 9, 8, 0, 143, 271, 0, 0 },
    { 1, 0, 0x40, 4, 0x38, 3, 0, 9, 8, 0, 77, 305, 328, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 635, 206, 246, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 464, 183, 220, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 61, 264, 328, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 800, 104, 175, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D2, 0x508, 0x54, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D1, 0xA8, 0xF4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CD, 0x220, 0x2C0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x200, 0x60, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x210, 0xC8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x220, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x210, 0x198, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
