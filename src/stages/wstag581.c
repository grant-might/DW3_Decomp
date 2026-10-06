#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x76B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x77A
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10400, 0x3AD00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E44;
extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern BattleList D_800A4EA4;
extern BattleList D_800A4F28;
extern BattleList D_800A4FAC;
extern BattleList D_800A5030;

Battle D_800A4E44 = { 87, 12, 0x60080000 };
Battle D_800A4E50 = { 87, 12, 0x60080000 };
Battle D_800A4E5C = { 87, 12, 0x60080000 };
Battle D_800A4E68 = { 139, 12, 0x60080000 };
Battle D_800A4E74 = { 139, 12, 0x60080000 };
Battle D_800A4E80 = { 164, 12, 0x60080000 };
Battle D_800A4E8C = { 164, 12, 0x60080000 };
Battle D_800A4E98 = { 164, 12, 0x60080000 };
BattleList D_800A4EA4 = {
    2,
    { &D_800A4E44, &D_800A4E50, &D_800A4E5C, &D_800A4E68,
      &D_800A4E74, &D_800A4E80, &D_800A4E8C, &D_800A4E98 },
};
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
BattleList D_800A4F28 = {
    0,
    { &D_800A4EC8, &D_800A4ED4, &D_800A4EE0, &D_800A4EEC,
      &D_800A4EF8, &D_800A4F04, &D_800A4F10, &D_800A4F1C },
};
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
BattleList D_800A4FAC = {
    0,
    { &D_800A4F4C, &D_800A4F58, &D_800A4F64, &D_800A4F70,
      &D_800A4F7C, &D_800A4F88, &D_800A4F94, &D_800A4FA0 },
};
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
BattleList D_800A5030 = {
    0,
    { &D_800A4FD0, &D_800A4FDC, &D_800A4FE8, &D_800A4FF4,
      &D_800A5000, &D_800A500C, &D_800A5018, &D_800A5024 },
};
FieldBattles stageBattles[] = {
    { 106, 0, 0, { &D_800A4EA4, &D_800A4F28, &D_800A4FAC, &D_800A5030 } },
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
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 249, 482, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 273, 494, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 720, 847, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 745, 378, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 769, 390, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 891, 346, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 913, 750, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 984, 754, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 1269, 276, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 889, 739, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 960, 766, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 1234, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 1, 6, 0, 946, 161, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 787, 181, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 867, 829, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1043, 353, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1268, 657, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 236, 78, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 1092, 186, 0, 0 },
    { 1, 0, 0x47, 2, 0xE, 0, 0, 0, 0, 0, 799, 790, 0, 0 },
    { 1, 0, 0x41, 2, 0xF, 0, 0, 0, 0, 0, 727, 809, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 9, 4, 0, 696, 835, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 241, 879, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 305, 559, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 1025, 775, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 217, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 281, 571, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 1001, 787, 0, 0 },
    { 1, 0x6B, 0x40, 6, 7, 0, 0, 0, 0, 0, 93, 496, 0, 0 },
    { 1, 0x6A, 0x40, 6, 8, 0, 0, 0, 0, 0, 1260, 665, 0, 0 },
    { 1, 0x69, 0x40, 6, 9, 0, 0, 0, 0, 0, 1036, 355, 0, 0 },
    { 1, 0x68, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 1086, 196, 0, 0 },
    { 1, 0x67, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 943, 171, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 783, 191, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x11, 0, 0, 0, 0, 0, 859, 837, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 230, 86, 0, 0 },
    { 1, 0, 0x80, 6, 0x19, 0, 0, 0, 0, 0, 876, 192, 0, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 9, 4, 0, 401, 463, 491, 0 },
    { 1, 0, 0x40, 4, 0x34, 2, 0, 9, 4, 0, 377, 475, 497, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 397, 464, 491, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 381, 476, 497, 0 },
    { 1, 0, 0x80, 4, 0x16, 0, 0, 0, 0, 0, 891, 116, 221, 0 },
    { 1, 0, 0x80, 4, 0x17, 0, 0, 0, 0, 0, 899, 112, 207, 0 },
    { 1, 0, 0x80, 4, 0x18, 0, 0, 0, 0, 0, 907, 108, 203, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 64, 512, 552, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1071, 379, 415, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 1049, 211, 247, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 975, 187, 224, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 815, 207, 239, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 894, 347, 370, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 896, 855, 888, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 208, 103, 138, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B6, 0x228, 0x94, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B8, 0x108, 0x174, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B9, 0x108, 0x174, 5, 0x6A, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BC, 0x2F8, 0x264, 3, 0x68, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BA, 0x108, 0x174, 5, 0x69, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BC, 0x258, 0x24C, 5, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BB, 0x108, 0x174, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BC, 0x68, 0x20C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BD, 0x278, 0xD4, 3, 0x6B, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x160, 0x80, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x170, 0xE8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xC, 0xDF, 0x142, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xC, 0xD2, 0x208, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x2D0, 0x29A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x2C1, 0x322, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x33E, 0x2D2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x330, 0x35A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x42E, 0x34A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x420, 0x3D2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x4B0, 0x25A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x4BE, 0x2AE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
