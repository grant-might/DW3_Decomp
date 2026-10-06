#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x523
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x533
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xE400, 0xD700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
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
extern BattleList D_800A4EEC;
extern BattleList D_800A4F70;
extern BattleList D_800A4FF4;
extern BattleList D_800A5078;

Battle D_800A4E8C = { 0, 0, 0x60040000 };
Battle D_800A4E98 = { 0, 0, 0x60040000 };
Battle D_800A4EA4 = { 0, 0, 0x60040000 };
Battle D_800A4EB0 = { 0, 0, 0x60040000 };
Battle D_800A4EBC = { 0, 0, 0x60040000 };
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
BattleList D_800A4EEC = {
    0,
    { &D_800A4E8C, &D_800A4E98, &D_800A4EA4, &D_800A4EB0,
      &D_800A4EBC, &D_800A4EC8, &D_800A4ED4, &D_800A4EE0 },
};
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
BattleList D_800A4F70 = {
    0,
    { &D_800A4F10, &D_800A4F1C, &D_800A4F28, &D_800A4F34,
      &D_800A4F40, &D_800A4F4C, &D_800A4F58, &D_800A4F64 },
};
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
BattleList D_800A4FF4 = {
    0,
    { &D_800A4F94, &D_800A4FA0, &D_800A4FAC, &D_800A4FB8,
      &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8 },
};
Battle D_800A5018 = { 195, 18, 0x60080000 };
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
FieldBattles stageBattles[] = {
    { 144, 0, 0, { &D_800A4EEC, &D_800A4F70, &D_800A4FF4, &D_800A5078 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 561, 160, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 664, 211, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 3, 6, 0, 903, 374, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 896, 256, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 896, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 53, 437, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 99, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 149, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 3, 6, 0, 639, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 3, 6, 0, 847, 344, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 239, 331, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 285, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 905, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 762, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 987, 453, 0, 0 },
    { 1, 0x64, 0x40, 6, 4, 0, 0, 0, 0, 0, 351, 103, 0, 0 },
    { 1, 0x65, 0x40, 6, 5, 0, 0, 0, 0, 0, 78, 169, 0, 0 },
    { 1, 0x66, 0x40, 6, 6, 0, 0, 0, 0, 0, 846, 246, 0, 0 },
    { 1, 0x67, 0x40, 6, 7, 0, 0, 0, 0, 0, 879, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 6, 0, 707, 316, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 6, 0, 719, 338, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 64, 196, 224, 0 },
    { 1, 0, 0x44, 4, 1, 0, 0, 0, 0, 0, 377, 108, 163, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 813, 256, 304, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 905, 344, 394, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x285, 0x1E0, 0x118, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x286, 0x78, 0xFC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x286, 0x508, 0x1CC, 3, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x284, 0x1A8, 0x1F4, 5, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
