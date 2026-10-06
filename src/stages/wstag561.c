#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C1A, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5D6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x26F00, 0x1DF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x41;
    D_800990B4.music = 0x61040000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern BattleList D_800A4F58;
extern BattleList D_800A4FDC;
extern BattleList D_800A5060;
extern BattleList D_800A50E4;
extern u16 D_800A51B4[];
extern u16 D_800A51BC[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A51D4[];
extern FieldTalk D_800A51EC[];
extern u16 D_800A521C[];
extern FieldTalk D_800A5204[];
extern FieldActorEntry D_800A5224;
extern FieldActorEntry D_800A5238;
extern FieldActorEntry D_800A524C;
extern s16 D_800A4E88[];

s16 D_800A4E88[] = {
    0x102, 2, 0x117, 0x133, 3,
    0x100, 0x15, 0xF7, 0x123,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC18, 0, 0, 0,
    0,
};
Battle D_800A4EF8 = { 134, 3, 0x60080000 };
Battle D_800A4F04 = { 134, 3, 0x60080000 };
Battle D_800A4F10 = { 134, 3, 0x60080000 };
Battle D_800A4F1C = { 134, 3, 0x60080000 };
Battle D_800A4F28 = { 172, 3, 0x60080000 };
Battle D_800A4F34 = { 172, 3, 0x60080000 };
Battle D_800A4F40 = { 172, 3, 0x60080000 };
Battle D_800A4F4C = { 172, 3, 0x60080000 };
BattleList D_800A4F58 = {
    3,
    { &D_800A4EF8, &D_800A4F04, &D_800A4F10, &D_800A4F1C,
      &D_800A4F28, &D_800A4F34, &D_800A4F40, &D_800A4F4C },
};
Battle D_800A4F7C = { 134, 8, 0x60080000 };
Battle D_800A4F88 = { 134, 8, 0x60080000 };
Battle D_800A4F94 = { 134, 8, 0x60080000 };
Battle D_800A4FA0 = { 134, 8, 0x60080000 };
Battle D_800A4FAC = { 172, 8, 0x60080000 };
Battle D_800A4FB8 = { 172, 8, 0x60080000 };
Battle D_800A4FC4 = { 172, 8, 0x60080000 };
Battle D_800A4FD0 = { 172, 8, 0x60080000 };
BattleList D_800A4FDC = {
    3,
    { &D_800A4F7C, &D_800A4F88, &D_800A4F94, &D_800A4FA0,
      &D_800A4FAC, &D_800A4FB8, &D_800A4FC4, &D_800A4FD0 },
};
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
BattleList D_800A5060 = {
    0,
    { &D_800A5000, &D_800A500C, &D_800A5018, &D_800A5024,
      &D_800A5030, &D_800A503C, &D_800A5048, &D_800A5054 },
};
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 334, 8, 0x60080000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 180, 8, 0x60080000 };
BattleList D_800A50E4 = {
    0,
    { &D_800A5084, &D_800A5090, &D_800A509C, &D_800A50A8,
      &D_800A50B4, &D_800A50C0, &D_800A50CC, &D_800A50D8 },
};
FieldBattles stageBattles[] = {
    { 98, 0, 0, { &D_800A4F58, &D_800A4FDC, &D_800A5060, &D_800A50E4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x175, 0xD8, 0x75, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x1BA, 0x180, 0xBA, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x195, 0xD8, 0x95, 0x150, 0x1FE },
};
u16 D_800A51B4[] = { 0x7A45, 1, 0xFFFF };
u16 D_800A51BC[] = { 0x9069, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x254, 1, 0x8236, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A51D4[] = {
    { NULL, D_800A51B4, 0x2D7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51EC[] = {
    { NULL, D_800A51BC, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5204[] = {
    { NULL, D_800A51C4, 0x187 },
    { NULL, NULL, 0 },
};
u16 D_800A521C[] = { 0x254, 0, 0xFFFF };
FieldActorEntry D_800A5224 = { NULL, D_800A51D4, 0x14, 4, 450, 368, 1 };
FieldActorEntry D_800A5238 = { NULL, D_800A51EC, 0x15, 5, 247, 291, 7 };
FieldActorEntry D_800A524C = { D_800A521C, D_800A5204, 0x21, 6, 502, 546, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5224,
    &D_800A5238,
    &D_800A524C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 407, 226, 0, 0 },
    { 1, 0, 0x64, 2, 1, 0, 0, 0, 0, 0, 551, 516, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 211, 335, 0, 0 },
    { 1, 0, 0x80, 2, 2, 0, 0, 0, 0, 0, 0, 384, 0, 0 },
    { 1, 0, 0x80, 2, 3, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x70, 2, 4, 0, 0, 0, 0, 0, 20, 512, 0, 0 },
    { 1, 0, 0x78, 2, 5, 0, 0, 0, 0, 0, 264, 523, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 6, 0, 204, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4D, 6, 0, 213, 360, 0, 0 },
    { 1, 0, 0x68, 6, 0x4E, 2, 0, 2, 6, 0, 181, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 153, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 277, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 322, 397, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 584, 137, 169, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B2, 0x610, 0x240, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B4, 0x80, 0x178, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xF, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC8, 0x3C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xF, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1463, D_800A4E88, EVENT_TEXT(0x27), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
