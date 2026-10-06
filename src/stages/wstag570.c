#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x414
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x424
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 2;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 1;
    D_800990B4.start = (Vec2){0x29A00, 0xF400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x14;
    D_800990B4.music = 0x60500000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E9C;
extern Battle D_800A4EA8;
extern Battle D_800A4EB4;
extern Battle D_800A4EC0;
extern Battle D_800A4ECC;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern BattleList D_800A4EFC;
extern BattleList D_800A4F80;
extern BattleList D_800A5004;
extern BattleList D_800A5088;
extern u16 D_800A5148[];
extern u16 D_800A5158[];
extern u16 D_800A5164[];
extern u16 D_800A516C[];
extern u16 D_800A5178[];
extern u16 D_800A5180[];
extern u16 D_800A51DC[];
extern FieldTalk D_800A5188[];
extern u16 D_800A51E4[];
extern FieldTalk D_800A51A0[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A51C4[];
extern FieldActorEntry D_800A51F4;
extern FieldActorEntry D_800A5208;
extern FieldActorEntry D_800A521C;

Battle D_800A4E9C = { 69, 3, 0x60080000 };
Battle D_800A4EA8 = { 69, 3, 0x60080000 };
Battle D_800A4EB4 = { 69, 3, 0x60080000 };
Battle D_800A4EC0 = { 69, 3, 0x60080000 };
Battle D_800A4ECC = { 68, 3, 0x60080000 };
Battle D_800A4ED8 = { 68, 3, 0x60080000 };
Battle D_800A4EE4 = { 68, 3, 0x60080000 };
Battle D_800A4EF0 = { 68, 3, 0x60080000 };
BattleList D_800A4EFC = {
    3,
    { &D_800A4E9C, &D_800A4EA8, &D_800A4EB4, &D_800A4EC0,
      &D_800A4ECC, &D_800A4ED8, &D_800A4EE4, &D_800A4EF0 },
};
Battle D_800A4F20 = { 0, 0, 0x60040000 };
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
BattleList D_800A4F80 = {
    0,
    { &D_800A4F20, &D_800A4F2C, &D_800A4F38, &D_800A4F44,
      &D_800A4F50, &D_800A4F5C, &D_800A4F68, &D_800A4F74 },
};
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
BattleList D_800A5004 = {
    0,
    { &D_800A4FA4, &D_800A4FB0, &D_800A4FBC, &D_800A4FC8,
      &D_800A4FD4, &D_800A4FE0, &D_800A4FEC, &D_800A4FF8 },
};
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 330, 2, 0x60080000 };
Battle D_800A5064 = { 0, 0, 0x60040000 };
Battle D_800A5070 = { 0, 0, 0x60040000 };
Battle D_800A507C = { 61, 2, 0x60080000 };
BattleList D_800A5088 = {
    0,
    { &D_800A5028, &D_800A5034, &D_800A5040, &D_800A504C,
      &D_800A5058, &D_800A5064, &D_800A5070, &D_800A507C },
};
FieldBattles stageBattles[] = {
    { 40, 0, 0, { &D_800A4EFC, &D_800A4F80, &D_800A5004, &D_800A5088 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x100, 0x1E0, 0, 0x150, 0x1FF },
    { 0x180, 0x100, 0x1AC, 0x1B1, 0x1B0, 0xB1, 0x160, 0x1FF },
};
u16 D_800A5148[] = { 0x708D, 1, 0x20C, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5158[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A5164[] = { 0x9403, 1, 0xFFFF };
u16 D_800A516C[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A5178[] = { 0x9406, 1, 0xFFFF };
u16 D_800A5180[] = { 0x940D, 1, 0xFFFF };
FieldTalk D_800A5188[] = {
    { NULL, D_800A5148, 0x32C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A0[] = {
    { D_800A5158, D_800A5164, 0x24 },
    { D_800A516C, D_800A5178, 0x24 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, D_800A5180, 0x24 },
    { NULL, NULL, 0 },
};
u16 D_800A51DC[] = { 0x20C, 0, 0xFFFF };
u16 D_800A51E4[] = { 0x802A, 0, 0xFFFF };
u16 D_800A51EC[] = { 0x802A, 1, 0xFFFF };
FieldActorEntry D_800A51F4 = { D_800A51DC, D_800A5188, 0x21, 4, 335, 718, 1 };
FieldActorEntry D_800A5208 = { D_800A51E4, D_800A51A0, 0x87, 5, 730, 440, 7 };
FieldActorEntry D_800A521C = { D_800A51EC, D_800A51C4, 0x87, 5, 730, 440, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A51F4,
    &D_800A5208,
    &D_800A521C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 155, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 859, 479, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 394, 624, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 314, 811, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 343, 836, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 571, 789, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 713, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 754, 749, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 760, 813, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 862, 757, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 281, 838, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 424, 826, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 737, 824, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 741, 714, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 278, 818, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 418, 838, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 506, 825, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 588, 791, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 708, 743, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 785, 696, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 845, 683, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 214, 803, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 256, 795, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 365, 833, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 515, 794, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 661, 814, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 818, 774, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 847, 673, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 862, 812, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 232, 815, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 319, 837, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 441, 821, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 547, 792, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 600, 775, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 679, 824, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 769, 690, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 258, 843, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 401, 829, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 467, 829, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 626, 784, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 679, 743, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 706, 843, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 771, 759, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 795, 774, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 820, 672, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 277, 846, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 377, 840, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 388, 831, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 388, 881, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 434, 838, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 511, 810, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 553, 800, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 607, 789, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 621, 874, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 627, 879, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 654, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 669, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 730, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 754, 830, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 758, 821, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 777, 767, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 839, 677, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 853, 802, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 864, 765, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 869, 681, 0, 0 },
    { 1, 0, 0x40, 6, 7, 1, 7, 0xC, 4, 0, 541, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0xD, 1, 0xD, 0x12, 4, 0, 480, 468, 0, 0 },
    { 1, 0, 0x5D, 4, 0, 0, 0, 0, 0, 0, 621, 413, 490, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24A, 0x570, 0x3C0, 3, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0xA, 2 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 3, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1C0, 0x272, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1CF, 0x2D8, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE7, 0x46, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x19, 0x46, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 3, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
