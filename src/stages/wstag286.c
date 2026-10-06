#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x50F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x51F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1F300, 0x27F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern BattleList D_800A4EE0;
extern BattleList D_800A4F64;
extern BattleList D_800A4FE8;
extern BattleList D_800A506C;
extern u16 D_800A519C[];
extern u16 D_800A51AC[];
extern u16 D_800A51B8[];
extern u16 D_800A51C4[];
extern u16 D_800A51D0[];
extern u16 D_800A52B4[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A52BC[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A52C4[];
extern FieldTalk D_800A520C[];
extern u16 D_800A52CC[];
extern FieldTalk D_800A5224[];
extern u16 D_800A52D4[];
extern FieldTalk D_800A523C[];
extern u16 D_800A52DC[];
extern FieldTalk D_800A5254[];
extern u16 D_800A52E8[];
extern FieldTalk D_800A526C[];
extern u16 D_800A52F4[];
extern FieldTalk D_800A5284[];
extern u16 D_800A5300[];
extern FieldTalk D_800A529C[];
extern FieldActorEntry D_800A530C;
extern FieldActorEntry D_800A5320;
extern FieldActorEntry D_800A5334;
extern FieldActorEntry D_800A5348;
extern FieldActorEntry D_800A535C;
extern FieldActorEntry D_800A5370;
extern FieldActorEntry D_800A5384;
extern FieldActorEntry D_800A5398;
extern FieldActorEntry D_800A53AC;

Battle D_800A4E80 = { 0, 0, 0x60040000 };
Battle D_800A4E8C = { 0, 0, 0x60040000 };
Battle D_800A4E98 = { 0, 0, 0x60040000 };
Battle D_800A4EA4 = { 0, 0, 0x60040000 };
Battle D_800A4EB0 = { 0, 0, 0x60040000 };
Battle D_800A4EBC = { 0, 0, 0x60040000 };
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
BattleList D_800A4EE0 = {
    0,
    { &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4,
      &D_800A4EB0, &D_800A4EBC, &D_800A4EC8, &D_800A4ED4 },
};
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
BattleList D_800A4F64 = {
    0,
    { &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28,
      &D_800A4F34, &D_800A4F40, &D_800A4F4C, &D_800A4F58 },
};
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
BattleList D_800A4FE8 = {
    0,
    { &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC,
      &D_800A4FB8, &D_800A4FC4, &D_800A4FD0, &D_800A4FDC },
};
Battle D_800A500C = { 196, 15, 0x60080000 };
Battle D_800A5018 = { 197, 15, 0x60080000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
BattleList D_800A506C = {
    0,
    { &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030,
      &D_800A503C, &D_800A5048, &D_800A5054, &D_800A5060 },
};
FieldBattles stageBattles[] = {
    { 145, 0, 0, { &D_800A4EE0, &D_800A4F64, &D_800A4FE8, &D_800A506C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x130, 0xC0, 0x30, 0x160, 0x1FE },
    { 0x140, 0x100, 0x172, 0x1D9, 0xC8, 0xD9, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B6, 0x178, 0x1D8, 0x78, 0x150, 0x1FD },
    { 0x140, 0x100, 0x172, 0x1B1, 0xC8, 0xB1, 0x160, 0x1FD },
    { 0x180, 0x100, 0x1B2, 0x100, 0x1C8, 0, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B2, 0x128, 0x1C8, 0x28, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1B6, 0x150, 0x1D8, 0x50, 0x160, 0x1FC },
};
u16 D_800A519C[] = { 0x25F, 1, 0x822D, 1, 0x7013, 1, 0xFFFF };
u16 D_800A51AC[] = { 0xC26, 1, 0x7400, 1, 0xFFFF };
u16 D_800A51B8[] = { 0xC27, 1, 0x7401, 1, 0xFFFF };
u16 D_800A51C4[] = { 0xC27, 1, 0x7401, 1, 0xFFFF };
u16 D_800A51D0[] = { 0xC25, 1, 0x7400, 1, 0xFFFF };
FieldTalk D_800A51DC[] = {
    { NULL, D_800A519C, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0xA5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0xA6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, D_800A51AC, 0x1BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, D_800A51B8, 0x1BE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, D_800A51C4, 0x1BF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, D_800A51D0, 0x1BD },
    { NULL, NULL, 0 },
};
u16 D_800A52B4[] = { 0x25F, 0, 0xFFFF };
u16 D_800A52BC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52C4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52DC[] = { 0xC26, 0, 0x6025, 1, 0xFFFF };
u16 D_800A52E8[] = { 0xC27, 0, 0x6025, 1, 0xFFFF };
u16 D_800A52F4[] = { 0xC27, 0, 0x6025, 1, 0xFFFF };
u16 D_800A5300[] = { 0xC25, 0, 0x6025, 1, 0xFFFF };
FieldActorEntry D_800A530C = { D_800A52B4, D_800A51DC, 0x21, 4, 825, 285, 1 };
FieldActorEntry D_800A5320 = { D_800A52BC, D_800A51F4, 0x25, 5, 560, 673, 1 };
FieldActorEntry D_800A5334 = { D_800A52C4, D_800A520C, 0x26, 6, 371, 574, 7 };
FieldActorEntry D_800A5348 = { D_800A52CC, D_800A5224, 0x9D, 7, 560, 673, 1 };
FieldActorEntry D_800A535C = { D_800A52D4, D_800A523C, 0x9E, 8, 296, 532, 7 };
FieldActorEntry D_800A5370 = { D_800A52DC, D_800A5254, 0x12B, 9, 823, 819, 3 };
FieldActorEntry D_800A5384 = { D_800A52E8, D_800A526C, 0x12D, 0xA, 371, 574, 3 };
FieldActorEntry D_800A5398 = { D_800A52F4, D_800A5284, 0x12E, 0xB, 349, 586, 7 };
FieldActorEntry D_800A53AC = { D_800A5300, D_800A529C, 0x12F, 0xC, 438, 244, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A530C,
    &D_800A5320,
    &D_800A5334,
    &D_800A5348,
    &D_800A535C,
    &D_800A5370,
    &D_800A5384,
    &D_800A5398,
    &D_800A53AC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 5, 8, 0, 437, 121, 0, 0 },
    { 1, 0, 0x78, 2, 0x32, 2, 0, 1, 4, 0, 121, 400, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 104, 383, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 212, 501, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 264, 240, 0, 0 },
    { 1, 0, 0x78, 6, 0x33, 2, 0, 1, 4, 0, 116, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 104, 334, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 212, 215, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 263, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 76, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 152, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 203, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 284, 121, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 748, 208, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 269, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 348, 461, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 429, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 509, 540, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 517, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 597, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 653, 613, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 733, 653, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 813, 693, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 837, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 893, 733, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 5, 8, 0, 554, 542, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 384, 133, 0, 0 },
    { 1, 0, 0x78, 4, 0x32, 2, 0, 1, 4, 0, 172, 373, 385, 0 },
    { 1, 0, 0x40, 4, 0x34, 2, 0, 1, 4, 0, 156, 358, 385, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 833, 737, 808, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 850, 744, 800, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 753, 706, 752, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 672, 666, 712, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 448, 554, 600, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 368, 514, 560, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 288, 474, 520, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 174, 336, 385, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 608, 250, 296, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 528, 210, 256, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 449, 161, 233, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 466, 168, 224, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 408, 135, 186, 0 },
    { 1, 0, 0x78, 4, 0x33, 2, 0, 1, 4, 0, 167, 255, 385, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x286, 0x318, 0x1DC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x14A, 0xC4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x284, 0xC8, 0x7C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
