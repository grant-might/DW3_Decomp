#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5C2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5D2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xCA00, 0x9800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x14;
    D_800990B4.music = 0x60500000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
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

extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern BattleList D_800A4F70;
extern BattleList D_800A4FF4;
extern BattleList D_800A5078;
extern BattleList D_800A50FC;
extern u16 D_800A51BC[];
extern u16 D_800A51C4[];
extern u16 D_800A51CC[];
extern u16 D_800A51D4[];
extern u16 D_800A51E0[];
extern u16 D_800A51F0[];
extern u16 D_800A51F8[];
extern u16 D_800A520C[];
extern u16 D_800A5218[];
extern u16 D_800A522C[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A5248[];
extern u16 D_800A5258[];
extern u16 D_800A5264[];
extern u16 D_800A5278[];
extern u16 D_800A528C[];
extern u16 D_800A5294[];
extern u16 D_800A529C[];
extern u16 D_800A52A4[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A52C0[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A52D8[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A5320[];
extern u16 D_800A53E0[];
extern FieldTalk D_800A5368[];
extern u16 D_800A53F0[];
extern FieldTalk D_800A5398[];
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;
extern FieldActorEntry D_800A5424;
extern FieldActorEntry D_800A5438;
extern FieldActorEntry D_800A544C;
extern s16 D_800A4E9C[];

s16 D_800A4E9C[] = {
    0x102, 2, 0x190, 0xE0, 3,
    0x100, 0x15, 0x171, 0xD1,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC0E, 0, 0, 0,
    0,
};
Battle D_800A4F10 = { 132, 3, 0x60080000 };
Battle D_800A4F1C = { 132, 3, 0x60080000 };
Battle D_800A4F28 = { 132, 3, 0x60080000 };
Battle D_800A4F34 = { 132, 3, 0x60080000 };
Battle D_800A4F40 = { 133, 3, 0x60080000 };
Battle D_800A4F4C = { 133, 3, 0x60080000 };
Battle D_800A4F58 = { 169, 3, 0x60080000 };
Battle D_800A4F64 = { 169, 3, 0x60080000 };
BattleList D_800A4F70 = {
    3,
    { &D_800A4F10, &D_800A4F1C, &D_800A4F28, &D_800A4F34,
      &D_800A4F40, &D_800A4F4C, &D_800A4F58, &D_800A4F64 },
};
Battle D_800A4F94 = { 0, 3, 0x60080000 };
Battle D_800A4FA0 = { 0, 3, 0x60080000 };
Battle D_800A4FAC = { 0, 3, 0x60080000 };
Battle D_800A4FB8 = { 0, 3, 0x60080000 };
Battle D_800A4FC4 = { 0, 3, 0x60080000 };
Battle D_800A4FD0 = { 0, 3, 0x60080000 };
Battle D_800A4FDC = { 0, 3, 0x60080000 };
Battle D_800A4FE8 = { 0, 3, 0x60080000 };
BattleList D_800A4FF4 = {
    0,
    { &D_800A4F94, &D_800A4FA0, &D_800A4FAC, &D_800A4FB8,
      &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8 },
};
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
BattleList D_800A5078 = {
    0,
    { &D_800A5018, &D_800A5024, &D_800A5030, &D_800A503C,
      &D_800A5048, &D_800A5054, &D_800A5060, &D_800A506C },
};
Battle D_800A509C = { 234, 3, 0x60080000 };
Battle D_800A50A8 = { 282, 3, 0x600C0000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 334, 2, 0x60080000 };
Battle D_800A50D8 = { 169, 3, 0x60080000 };
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 180, 2, 0x60080000 };
BattleList D_800A50FC = {
    0,
    { &D_800A509C, &D_800A50A8, &D_800A50B4, &D_800A50C0,
      &D_800A50CC, &D_800A50D8, &D_800A50E4, &D_800A50F0 },
};
FieldBattles stageBattles[] = {
    { 105, 0, 0, { &D_800A4F70, &D_800A4FF4, &D_800A5078, &D_800A50FC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x145, 0x80, 0x45, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x18D, 0xB8, 0x8D, 0x160, 0x1FF },
};
u16 D_800A51BC[] = { 0x9012, 1, 0xFFFF };
u16 D_800A51C4[] = { 0, 0, 0xFFFF };
u16 D_800A51CC[] = { 0, 1, 0xFFFF };
u16 D_800A51D4[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A51E0[] = { 0x7207, 1, 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51F0[] = { 0x7632, 1, 0xFFFF };
u16 D_800A51F8[] = { 0, 1, 0x7209, 1, 0xE25, 0, 0x7207, 1, 0xFFFF };
u16 D_800A520C[] = { 0x7400, 1, 0xE25, 1, 0xFFFF };
u16 D_800A5218[] = { 0x7207, 1, 0, 1, 0x7209, 1, 0xE25, 1, 0xFFFF };
u16 D_800A522C[] = { 0, 0, 0xFFFF };
u16 D_800A5234[] = { 0, 1, 0xFFFF };
u16 D_800A523C[] = { 0x720A, 0, 0, 1, 0xFFFF };
u16 D_800A5248[] = { 0, 1, 0xE46, 0, 0x720A, 1, 0xFFFF };
u16 D_800A5258[] = { 0x7400, 1, 0xE46, 1, 0xFFFF };
u16 D_800A5264[] = { 0x720A, 1, 0, 1, 0xE46, 1, 0x720C, 0, 0xFFFF };
u16 D_800A5278[] = { 0, 1, 0xE46, 1, 0x720C, 1, 0x720A, 1, 0xFFFF };
u16 D_800A528C[] = { 0x7832, 1, 0xFFFF };
u16 D_800A5294[] = { 0x11, 0, 0xFFFF };
u16 D_800A529C[] = { 0x10, 0, 0xFFFF };
u16 D_800A52A4[] = { 0x11, 0, 0xFFFF };
u16 D_800A52AC[] = { 0x10, 1, 0xFFFF };
u16 D_800A52B4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A52C0[] = {
    { NULL, D_800A51BC, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D8[] = {
    { D_800A51C4, D_800A51CC, 0x244 },
    { D_800A51D4, NULL, 0x245 },
    { D_800A51E0, D_800A51F0, 0x246 },
    { D_800A51F8, D_800A520C, 0x247 },
    { D_800A5218, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5320[] = {
    { D_800A522C, D_800A5234, 0x24C },
    { D_800A523C, NULL, 0x24E },
    { D_800A5248, D_800A5258, 0x24D },
    { D_800A5264, NULL, 0x248 },
    { D_800A5278, D_800A528C, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5368[] = {
    { D_800A5294, NULL, 0x39D },
    { D_800A529C, D_800A52A4, 0x249 },
    { D_800A52AC, D_800A52B4, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5398[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
u16 D_800A53B0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x7019, 1, 0x11, 0, 0x8192, 1, 0x8014, 0, 0xFFFF };
u16 D_800A53CC[] = { 0x7019, 1, 0x11, 0, 0x8192, 1, 0x8014, 1, 0xFFFF };
u16 D_800A53E0[] = { 0x8192, 1, 0x7019, 1, 0x11, 1, 0xFFFF };
u16 D_800A53F0[] = { 0x7019, 1, 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A53FC = { D_800A53B0, D_800A52C0, 0x15, 4, 369, 209, 7 };
FieldActorEntry D_800A5410 = { D_800A53B8, D_800A52D8, 0x45, 5, 752, 690, 5 };
FieldActorEntry D_800A5424 = { D_800A53CC, D_800A5320, 0x45, 5, 752, 690, 5 };
FieldActorEntry D_800A5438 = { D_800A53E0, D_800A5368, 0x45, 5, 752, 690, 5 };
FieldActorEntry D_800A544C = { D_800A53F0, D_800A5398, 0x45, 5, 752, 690, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A53FC,
    &D_800A5410,
    &D_800A5424,
    &D_800A5438,
    &D_800A544C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 40, 512, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 472, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 362, 998, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 634, 946, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 964, 182, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1102, 947, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1169, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 202, 926, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 495, 1034, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 986, 1028, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1213, 654, 0, 0 },
    { 1, 0, 0x40, 6, 0, 0, 0, 0, 0, 0, 678, 464, 0, 0 },
    { 1, 0, 0x4A, 6, 2, 0, 0, 0, 0, 0, 1178, 782, 0, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 697, 464, 478, 0 },
    { 1, 0, 0x4B, 4, 1, 0, 0, 0, 0, 0, 160, 219, 243, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B2, 0x610, 0x540, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 3, 5 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 6, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0xB, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x479, 0x2B0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x469, 0x318, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0x13, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x2C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x20, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xC, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFEC, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFE0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0x13, 1 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1226, D_800A4E9C, EVENT_TEXT(0xB), NULL, NULL },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
