#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5CE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5DE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x20000, 0xA600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E48;
extern Battle D_800A4E54;
extern Battle D_800A4E60;
extern Battle D_800A4E6C;
extern Battle D_800A4E78;
extern Battle D_800A4E84;
extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4ECC;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern BattleList D_800A4EA8;
extern BattleList D_800A4F2C;
extern BattleList D_800A4FB0;
extern BattleList D_800A5034;
extern u16 D_800A51A4[];
extern FieldTalk D_800A5114[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A512C[];
extern u16 D_800A51BC[];
extern FieldTalk D_800A5144[];
extern u16 D_800A51C8[];
extern FieldTalk D_800A515C[];
extern u16 D_800A51D0[];
extern FieldTalk D_800A5174[];
extern u16 D_800A51DC[];
extern FieldTalk D_800A518C[];
extern FieldActorEntry D_800A51E4;
extern FieldActorEntry D_800A51F8;
extern FieldActorEntry D_800A520C;
extern FieldActorEntry D_800A5220;
extern FieldActorEntry D_800A5234;
extern FieldActorEntry D_800A5248;

Battle D_800A4E48 = { 98, 3, 0x60080000 };
Battle D_800A4E54 = { 98, 3, 0x60080000 };
Battle D_800A4E60 = { 98, 3, 0x60080000 };
Battle D_800A4E6C = { 130, 3, 0x60080000 };
Battle D_800A4E78 = { 130, 3, 0x60080000 };
Battle D_800A4E84 = { 131, 3, 0x60080000 };
Battle D_800A4E90 = { 131, 3, 0x60080000 };
Battle D_800A4E9C = { 131, 3, 0x60080000 };
BattleList D_800A4EA8 = {
    3,
    { &D_800A4E48, &D_800A4E54, &D_800A4E60, &D_800A4E6C,
      &D_800A4E78, &D_800A4E84, &D_800A4E90, &D_800A4E9C },
};
Battle D_800A4ECC = { 0, 0, 0x60040000 };
Battle D_800A4ED8 = { 0, 0, 0x60040000 };
Battle D_800A4EE4 = { 0, 0, 0x60040000 };
Battle D_800A4EF0 = { 0, 0, 0x60040000 };
Battle D_800A4EFC = { 0, 0, 0x60040000 };
Battle D_800A4F08 = { 0, 0, 0x60040000 };
Battle D_800A4F14 = { 0, 0, 0x60040000 };
Battle D_800A4F20 = { 0, 0, 0x60040000 };
BattleList D_800A4F2C = {
    0,
    { &D_800A4ECC, &D_800A4ED8, &D_800A4EE4, &D_800A4EF0,
      &D_800A4EFC, &D_800A4F08, &D_800A4F14, &D_800A4F20 },
};
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
BattleList D_800A4FB0 = {
    0,
    { &D_800A4F50, &D_800A4F5C, &D_800A4F68, &D_800A4F74,
      &D_800A4F80, &D_800A4F8C, &D_800A4F98, &D_800A4FA4 },
};
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 333, 3, 0x60080000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 175, 3, 0x60080000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
BattleList D_800A5034 = {
    0,
    { &D_800A4FD4, &D_800A4FE0, &D_800A4FEC, &D_800A4FF8,
      &D_800A5004, &D_800A5010, &D_800A501C, &D_800A5028 },
};
FieldBattles stageBattles[] = {
    { 100, 0, 0, { &D_800A4EA8, &D_800A4F2C, &D_800A4FB0, &D_800A5034 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x118, 0xC8, 0x18, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x140, 0xC8, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x1A6, 0xD8, 0xA6, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x1B6, 0x70, 0xB6, 0x150, 0x1FE },
};
FieldTalk D_800A5114[] = {
    { NULL, NULL, 0x1C2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A512C[] = {
    { NULL, NULL, 0x1C4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5144[] = {
    { NULL, NULL, 0x1C3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A515C[] = {
    { NULL, NULL, 0x1C3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5174[] = {
    { NULL, NULL, 0x1C5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A518C[] = {
    { NULL, NULL, 0x1C5 },
    { NULL, NULL, 0 },
};
u16 D_800A51A4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51BC[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51C8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51DC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A51E4 = { D_800A51A4, D_800A5114, 0x2F, 4, 528, 801, 1 };
FieldActorEntry D_800A51F8 = { D_800A51B0, D_800A512C, 0x34, 5, 608, 967, 5 };
FieldActorEntry D_800A520C = { D_800A51BC, D_800A5144, 0x9D, 6, 528, 801, 1 };
FieldActorEntry D_800A5220 = { D_800A51C8, D_800A515C, 0x9D, 6, 528, 801, 1 };
FieldActorEntry D_800A5234 = { D_800A51D0, D_800A5174, 0x9E, 7, 608, 967, 5 };
FieldActorEntry D_800A5248 = { D_800A51DC, D_800A518C, 0x9E, 7, 608, 967, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A51E4,
    &D_800A51F8,
    &D_800A520C,
    &D_800A5220,
    &D_800A5234,
    &D_800A5248,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 166, 265, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 261, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 195, 287, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 207, 278, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 208, 273, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 217, 281, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 223, 291, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 237, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 244, 290, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 264, 305, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 532, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 551, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 553, 172, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 496, 200, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 520, 201, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 526, 192, 0, 0 },
    { 1, 0, 0x64, 2, 0xE, 0, 0, 0, 0, 0, 698, 491, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 490, 26, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 528, 45, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 567, 64, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 418, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 421, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 434, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 450, 120, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 384, 141, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 391, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 392, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 414, 137, 0, 0 },
    { 1, 0, 0x73, 4, 0, 0, 0, 0, 0, 0, 349, 733, 824, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 444, 766, 777, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 310, 576, 599, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 487, 596, 610, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 592, 118, 160, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 103, 411, 477, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 384, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 895, 895, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 636, 800, 800, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 673, 767, 767, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B4, 0x5D8, 0x104, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x88, 0x3F4, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x19, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
