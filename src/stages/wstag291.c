#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4ED
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4FD
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x17000, 0x19D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 6;
    D_800990B4.music = 0x60180000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E38;
extern Battle D_800A4E44;
extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern BattleList D_800A4E98;
extern BattleList D_800A4F1C;
extern BattleList D_800A4FA0;
extern BattleList D_800A5024;
extern u16 D_800A5154[];
extern u16 D_800A5160[];
extern u16 D_800A516C[];
extern u16 D_800A5250[];
extern FieldTalk D_800A5178[];
extern u16 D_800A5258[];
extern FieldTalk D_800A5190[];
extern u16 D_800A5260[];
extern FieldTalk D_800A51A8[];
extern u16 D_800A5268[];
extern FieldTalk D_800A51C0[];
extern u16 D_800A5270[];
extern FieldTalk D_800A51D8[];
extern u16 D_800A5278[];
extern FieldTalk D_800A51F0[];
extern u16 D_800A5280[];
extern FieldTalk D_800A5208[];
extern u16 D_800A528C[];
extern FieldTalk D_800A5220[];
extern u16 D_800A5298[];
extern FieldTalk D_800A5238[];
extern FieldActorEntry D_800A52A4;
extern FieldActorEntry D_800A52B8;
extern FieldActorEntry D_800A52CC;
extern FieldActorEntry D_800A52E0;
extern FieldActorEntry D_800A52F4;
extern FieldActorEntry D_800A5308;
extern FieldActorEntry D_800A531C;
extern FieldActorEntry D_800A5330;
extern FieldActorEntry D_800A5344;

Battle D_800A4E38 = { 0, 0, 0x60040000 };
Battle D_800A4E44 = { 0, 0, 0x60040000 };
Battle D_800A4E50 = { 0, 0, 0x60040000 };
Battle D_800A4E5C = { 0, 0, 0x60040000 };
Battle D_800A4E68 = { 0, 0, 0x60040000 };
Battle D_800A4E74 = { 0, 0, 0x60040000 };
Battle D_800A4E80 = { 0, 0, 0x60040000 };
Battle D_800A4E8C = { 0, 0, 0x60040000 };
BattleList D_800A4E98 = {
    0,
    { &D_800A4E38, &D_800A4E44, &D_800A4E50, &D_800A4E5C,
      &D_800A4E68, &D_800A4E74, &D_800A4E80, &D_800A4E8C },
};
Battle D_800A4EBC = { 0, 0, 0x60040000 };
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
BattleList D_800A4F1C = {
    0,
    { &D_800A4EBC, &D_800A4EC8, &D_800A4ED4, &D_800A4EE0,
      &D_800A4EEC, &D_800A4EF8, &D_800A4F04, &D_800A4F10 },
};
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
BattleList D_800A4FA0 = {
    0,
    { &D_800A4F40, &D_800A4F4C, &D_800A4F58, &D_800A4F64,
      &D_800A4F70, &D_800A4F7C, &D_800A4F88, &D_800A4F94 },
};
Battle D_800A4FC4 = { 196, 15, 0x60080000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
BattleList D_800A5024 = {
    0,
    { &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8,
      &D_800A4FF4, &D_800A5000, &D_800A500C, &D_800A5018 },
};
FieldBattles stageBattles[] = {
    { 146, 0, 0, { &D_800A4E98, &D_800A4F1C, &D_800A4FA0, &D_800A5024 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x170, 0x1C5 },
    { 0x180, 0x100, 0x188, 0x100, 0x120, 0, 0x170, 0x1C4 },
    { 0x180, 0x100, 0x190, 0x100, 0x140, 0, 0x170, 0x1C3 },
    { 0x180, 0x100, 0x190, 0x130, 0x140, 0x30, 0x170, 0x1C0 },
    { 0x180, 0x100, 0x1A8, 0x148, 0x1A0, 0x48, 0x170, 0x1BF },
    { 0x180, 0x100, 0x1B0, 0x148, 0x1C0, 0x48, 0x170, 0x1BE },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x170, 0x1BC },
    { 0x180, 0x100, 0x198, 0x128, 0x160, 0x28, 0x170, 0x1BB },
    { 0x180, 0x100, 0x1A0, 0x128, 0x180, 0x28, 0x170, 0x1BA },
};
u16 D_800A5154[] = { 0x7400, 1, 0xC28, 1, 0xFFFF };
u16 D_800A5160[] = { 0x7400, 1, 0xC2A, 1, 0xFFFF };
u16 D_800A516C[] = { 0x7400, 1, 0xC29, 1, 0xFFFF };
FieldTalk D_800A5178[] = {
    { NULL, NULL, 0xA7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5190[] = {
    { NULL, NULL, 0xA8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A8[] = {
    { NULL, NULL, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C0[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D8[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F0[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5208[] = {
    { NULL, D_800A5154, 0x1C0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5220[] = {
    { NULL, D_800A5160, 0x1C2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5238[] = {
    { NULL, D_800A516C, 0x1C1 },
    { NULL, NULL, 0 },
};
u16 D_800A5250[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5258[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5260[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5268[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5270[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5278[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5280[] = { 0x6025, 1, 0xC28, 0, 0xFFFF };
u16 D_800A528C[] = { 0x6025, 1, 0xC2A, 0, 0xFFFF };
u16 D_800A5298[] = { 0x6025, 1, 0xC29, 0, 0xFFFF };
FieldActorEntry D_800A52A4 = { D_800A5250, D_800A5178, 0x25, 4, 273, 361, 1 };
FieldActorEntry D_800A52B8 = { D_800A5258, D_800A5190, 0x26, 5, 817, 377, 3 };
FieldActorEntry D_800A52CC = { D_800A5260, D_800A51A8, 0x27, 6, 479, 473, 1 };
FieldActorEntry D_800A52E0 = { D_800A5268, D_800A51C0, 0x9D, 7, 273, 361, 1 };
FieldActorEntry D_800A52F4 = { D_800A5270, D_800A51D8, 0x9E, 8, 817, 377, 3 };
FieldActorEntry D_800A5308 = { D_800A5278, D_800A51F0, 0x9F, 9, 479, 473, 1 };
FieldActorEntry D_800A531C = { D_800A5280, D_800A5208, 0x12B, 0xA, 419, 250, 1 };
FieldActorEntry D_800A5330 = { D_800A528C, D_800A5220, 0x12D, 0xB, 209, 353, 7 };
FieldActorEntry D_800A5344 = { D_800A5298, D_800A5238, 0x12F, 0xC, 544, 249, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A52A4,
    &D_800A52B8,
    &D_800A52CC,
    &D_800A52E0,
    &D_800A52F4,
    &D_800A5308,
    &D_800A531C,
    &D_800A5330,
    &D_800A5344,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x40, 2, 0, 5, 8, 0, 171, 28, 0, 0 },
    { 1, 0, 0x40, 2, 0x40, 2, 0, 5, 8, 0, 549, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 5, 8, 0, 264, 45, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 5, 8, 0, 361, 94, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 5, 8, 0, 614, 108, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 5, 8, 0, 699, 185, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 0xD, 0x10, 0, 467, 144, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 0xD, 0x10, 0, 467, 144, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 0xD, 0x10, 0, 676, 280, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 0xD, 0x10, 0, 676, 280, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 8, 0x10, 0, 81, 194, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 8, 0x10, 0, 81, 194, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 8, 0x10, 0, 789, 254, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 8, 0x10, 0, 789, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 166, 188, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 262, 236, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 294, 252, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 326, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 358, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 390, 300, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 6, 0, 421, 316, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 3, 6, 0, 197, 203, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 3, 6, 0, 229, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 6, 0, 451, 328, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 6, 0, 487, 328, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 3, 6, 0, 517, 321, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 3, 6, 0, 549, 305, 0, 0 },
    { 1, 0x64, 0x40, 6, 6, 0, 0, 0, 0, 0, 81, 237, 0, 0 },
    { 1, 0x65, 0x40, 6, 5, 0, 0, 0, 0, 0, 161, 70, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 114, 71, 123, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 59, 239, 290, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 572, 463, 490, 0 },
    { 1, 0, 0x68, 4, 3, 0, 0, 0, 0, 0, 656, 281, 368, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 209, 283, 336, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x283, 0x386, 0x34A, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x289, 0x3A8, 0x13C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x274, 0x368, 0x18C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
