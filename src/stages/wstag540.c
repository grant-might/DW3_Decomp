#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x6E9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x6F9
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15200, 0x1C000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x13;
    D_800990B4.music = 0x604C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 3);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 4);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern BattleList D_800A4EC8;
extern BattleList D_800A4F4C;
extern BattleList D_800A4FD0;
extern BattleList D_800A5054;
extern u16 D_800A5124[];
extern u16 D_800A5134[];
extern u16 D_800A5144[];
extern u16 D_800A519C[];
extern FieldTalk D_800A5154[];
extern u16 D_800A51A4[];
extern FieldTalk D_800A516C[];
extern u16 D_800A51AC[];
extern FieldTalk D_800A5184[];
extern FieldActorEntry D_800A51B4;
extern FieldActorEntry D_800A51C8;
extern FieldActorEntry D_800A51DC;

Battle D_800A4E68 = { 165, 10, 0x60080000 };
Battle D_800A4E74 = { 165, 10, 0x60080000 };
Battle D_800A4E80 = { 173, 10, 0x60080000 };
Battle D_800A4E8C = { 173, 10, 0x60080000 };
Battle D_800A4E98 = { 150, 10, 0x60080000 };
Battle D_800A4EA4 = { 150, 10, 0x60080000 };
Battle D_800A4EB0 = { 150, 10, 0x60080000 };
Battle D_800A4EBC = { 92, 10, 0x60080000 };
BattleList D_800A4EC8 = {
    4,
    { &D_800A4E68, &D_800A4E74, &D_800A4E80, &D_800A4E8C,
      &D_800A4E98, &D_800A4EA4, &D_800A4EB0, &D_800A4EBC },
};
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
BattleList D_800A4F4C = {
    0,
    { &D_800A4EEC, &D_800A4EF8, &D_800A4F04, &D_800A4F10,
      &D_800A4F1C, &D_800A4F28, &D_800A4F34, &D_800A4F40 },
};
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
BattleList D_800A4FD0 = {
    0,
    { &D_800A4F70, &D_800A4F7C, &D_800A4F88, &D_800A4F94,
      &D_800A4FA0, &D_800A4FAC, &D_800A4FB8, &D_800A4FC4 },
};
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
BattleList D_800A5054 = {
    0,
    { &D_800A4FF4, &D_800A5000, &D_800A500C, &D_800A5018,
      &D_800A5024, &D_800A5030, &D_800A503C, &D_800A5048 },
};
FieldBattles stageBattles[] = {
    { 60, 0, 0, { &D_800A4EC8, &D_800A4F4C, &D_800A4FD0, &D_800A5054 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x1D8, 0xD0, 0xD8, 0x140, 0x1FA },
    { 0x180, 0x100, 0x1A0, 0x168, 0x180, 0x68, 0x150, 0x1FA },
    { 0x180, 0x100, 0x1A6, 0x168, 0x198, 0x68, 0x160, 0x1FA },
};
u16 D_800A5124[] = { 0x218, 1, 0x8AFC, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5134[] = { 0x219, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5144[] = { 0x708F, 1, 0x21A, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5154[] = {
    { NULL, D_800A5124, 0x261 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A516C[] = {
    { NULL, D_800A5134, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5184[] = {
    { NULL, D_800A5144, 0x32D },
    { NULL, NULL, 0 },
};
u16 D_800A519C[] = { 0x218, 0, 0xFFFF };
u16 D_800A51A4[] = { 0x219, 0, 0xFFFF };
u16 D_800A51AC[] = { 0x21A, 0, 0xFFFF };
FieldActorEntry D_800A51B4 = { D_800A519C, D_800A5154, 0x21, 4, 369, 1218, 1 };
FieldActorEntry D_800A51C8 = { D_800A51A4, D_800A516C, 0x4D, 5, 1072, 601, 1 };
FieldActorEntry D_800A51DC = { D_800A51AC, D_800A5184, 0x4E, 6, 1313, 1138, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A51B4,
    &D_800A51C8,
    &D_800A51DC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x64, 2, 0xD, 0, 0, 0, 0, 0, 358, 319, 0, 0 },
    { 1, 0, 0x64, 2, 0xE, 0, 0, 0, 0, 0, 508, 332, 0, 0 },
    { 1, 0, 0x64, 2, 0xF, 0, 0, 0, 0, 0, 887, 399, 0, 0 },
    { 1, 0, 0x64, 2, 0xF, 0, 0, 0, 0, 0, 1007, 403, 0, 0 },
    { 1, 0, 0x64, 2, 0x10, 0, 0, 0, 0, 0, 800, 411, 0, 0 },
    { 1, 0, 0x64, 2, 0x10, 0, 0, 0, 0, 0, 1159, 424, 0, 0 },
    { 1, 0, 0x64, 2, 0x11, 0, 0, 0, 0, 0, 1126, 413, 0, 0 },
    { 1, 0, 0x50, 2, 0x12, 0, 0, 0, 0, 0, 1266, 453, 0, 0 },
    { 1, 0, 0xDC, 2, 0x13, 0, 0, 0, 0, 0, 1360, 483, 0, 0 },
    { 1, 0, 0x64, 2, 0, 0, 0, 0, 0, 0, 502, 965, 0, 0 },
    { 1, 0, 0x64, 2, 0, 0, 0, 0, 0, 0, 619, 747, 0, 0 },
    { 1, 0, 0x64, 2, 0, 0, 0, 0, 0, 0, 668, 882, 0, 0 },
    { 1, 0, 0x64, 2, 1, 0, 0, 0, 0, 0, 368, 1064, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 514, 921, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 538, 877, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 561, 834, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 631, 702, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 680, 838, 0, 0 },
    { 1, 0, 0x64, 2, 2, 0, 0, 0, 0, 0, 704, 794, 0, 0 },
    { 1, 0, 0x64, 2, 3, 0, 0, 0, 0, 0, 624, 866, 0, 0 },
    { 1, 0, 0x64, 2, 3, 0, 0, 0, 0, 0, 647, 822, 0, 0 },
    { 1, 0, 0x64, 2, 3, 0, 0, 0, 0, 0, 671, 779, 0, 0 },
    { 1, 0, 0x64, 2, 4, 0, 0, 0, 0, 0, 593, 850, 0, 0 },
    { 1, 0, 0x64, 2, 4, 0, 0, 0, 0, 0, 617, 806, 0, 0 },
    { 1, 0, 0x64, 2, 4, 0, 0, 0, 0, 0, 640, 762, 0, 0 },
    { 1, 0, 0x64, 2, 4, 0, 0, 0, 0, 0, 663, 719, 0, 0 },
    { 1, 0, 0xA0, 2, 5, 0, 0, 0, 0, 0, 687, 683, 0, 0 },
    { 1, 0, 0x8C, 2, 6, 0, 0, 0, 0, 0, 847, 715, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 939, 866, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 1035, 914, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 1155, 918, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 1297, 879, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 1394, 927, 0, 0 },
    { 1, 0, 0x64, 2, 7, 0, 0, 0, 0, 0, 1513, 931, 0, 0 },
    { 1, 0, 0x64, 2, 8, 0, 0, 0, 0, 0, 932, 807, 0, 0 },
    { 1, 0, 0x64, 2, 8, 0, 0, 0, 0, 0, 1004, 899, 0, 0 },
    { 1, 0, 0x64, 2, 8, 0, 0, 0, 0, 0, 1362, 912, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 920, 828, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 1111, 924, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 1255, 885, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 1351, 933, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 1470, 937, 0, 0 },
    { 1, 0, 0x64, 2, 0xA, 0, 0, 0, 0, 0, 1199, 891, 0, 0 },
    { 1, 0, 0x64, 2, 0xB, 0, 0, 0, 0, 0, 1226, 864, 0, 0 },
    { 1, 0, 0x64, 2, 0xC, 0, 0, 0, 0, 0, 521, 415, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x244, 0x40C, 0x1E4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x246, 0x98, 0xF4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x246, 0x98, 0x1E4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x246, 0x98, 0x2C4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x246, 0x98, 0x414, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x220, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x210, 0x1F8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x293, 0x98, 0x264, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
