#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x29D
#define STAGE_ARCHIVE 0x31F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x2AC
#define STAGE_ARCHIVE 0x32E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1E000, 0x1D400};
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
extern u16 D_800A50F4[];
extern u16 D_800A5100[];
extern u16 D_800A510C[];
extern u16 D_800A5160[];
extern FieldTalk D_800A5118[];
extern u16 D_800A516C[];
extern FieldTalk D_800A5130[];
extern u16 D_800A5178[];
extern FieldTalk D_800A5148[];
extern FieldActorEntry D_800A5184;
extern FieldActorEntry D_800A5198;
extern FieldActorEntry D_800A51AC;

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
Battle D_800A4FC4 = { 189, 15, 0x60080000 };
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
    { 135, 0, 0, { &D_800A4E98, &D_800A4F1C, &D_800A4FA0, &D_800A5024 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x1B9, 0xD0, 0xB9, 0x140, 0x1F1 },
    { 0x180, 0x100, 0x18C, 0x100, 0x130, 0, 0x150, 0x1F1 },
    { 0x180, 0x100, 0x194, 0x100, 0x150, 0, 0x170, 0x1F1 },
};
u16 D_800A50F4[] = { 0x7400, 1, 0xC08, 1, 0xFFFF };
u16 D_800A5100[] = { 0x7400, 1, 0xC09, 1, 0xFFFF };
u16 D_800A510C[] = { 0x7400, 1, 0xC0A, 1, 0xFFFF };
FieldTalk D_800A5118[] = {
    { NULL, D_800A50F4, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5130[] = {
    { NULL, D_800A5100, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5148[] = {
    { NULL, D_800A510C, 0xA9 },
    { NULL, NULL, 0 },
};
u16 D_800A5160[] = { 0x6016, 1, 0xC08, 0, 0xFFFF };
u16 D_800A516C[] = { 0x6016, 1, 0xC09, 0, 0xFFFF };
u16 D_800A5178[] = { 0x6016, 1, 0xC0A, 0, 0xFFFF };
FieldActorEntry D_800A5184 = { D_800A5160, D_800A5118, 0x132, 4, 209, 353, 7 };
FieldActorEntry D_800A5198 = { D_800A516C, D_800A5130, 0x133, 5, 419, 250, 1 };
FieldActorEntry D_800A51AC = { D_800A5178, D_800A5148, 0x134, 6, 544, 249, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5184,
    &D_800A5198,
    &D_800A51AC,
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
    { 1, 0x64, 0x40, 6, 5, 0, 0, 0, 0, 0, 81, 237, 0, 0 },
    { 1, 0x65, 0x40, 6, 6, 0, 0, 0, 0, 0, 161, 70, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 114, 71, 123, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 59, 239, 290, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 572, 463, 490, 0 },
    { 1, 0, 0x68, 4, 3, 0, 0, 0, 0, 0, 656, 281, 368, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 209, 283, 336, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x214, 0x386, 0x34A, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21A, 0x3A8, 0x13C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x205, 0x368, 0x18C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
