#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x571
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x581
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1A200, 0xA000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
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

extern Battle D_800A4EB4;
extern Battle D_800A4EC0;
extern Battle D_800A4ECC;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A5094;
extern BattleList D_800A4F14;
extern BattleList D_800A4F98;
extern BattleList D_800A501C;
extern BattleList D_800A50A0;
extern u16 D_800A5170[];
extern u16 D_800A5198[];
extern FieldTalk D_800A5180[];
extern FieldActorEntry D_800A51A0;
extern FieldActorEntry D_800A51B4;
extern FieldActorEntry D_800A51C8;

Battle D_800A4EB4 = { 106, 13, 0x60080000 };
Battle D_800A4EC0 = { 106, 13, 0x60080000 };
Battle D_800A4ECC = { 106, 13, 0x60080000 };
Battle D_800A4ED8 = { 106, 13, 0x60080000 };
Battle D_800A4EE4 = { 151, 13, 0x60080000 };
Battle D_800A4EF0 = { 151, 13, 0x60080000 };
Battle D_800A4EFC = { 151, 13, 0x60080000 };
Battle D_800A4F08 = { 151, 13, 0x60080000 };
BattleList D_800A4F14 = {
    3,
    { &D_800A4EB4, &D_800A4EC0, &D_800A4ECC, &D_800A4ED8,
      &D_800A4EE4, &D_800A4EF0, &D_800A4EFC, &D_800A4F08 },
};
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
BattleList D_800A4F98 = {
    0,
    { &D_800A4F38, &D_800A4F44, &D_800A4F50, &D_800A4F5C,
      &D_800A4F68, &D_800A4F74, &D_800A4F80, &D_800A4F8C },
};
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
BattleList D_800A501C = {
    0,
    { &D_800A4FBC, &D_800A4FC8, &D_800A4FD4, &D_800A4FE0,
      &D_800A4FEC, &D_800A4FF8, &D_800A5004, &D_800A5010 },
};
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 329, 13, 0x60080000 };
Battle D_800A5070 = { 330, 8, 0x60080000 };
Battle D_800A507C = { 0, 0, 0x60040000 };
Battle D_800A5088 = { 99, 13, 0x60080000 };
Battle D_800A5094 = { 64, 8, 0x60080000 };
BattleList D_800A50A0 = {
    0,
    { &D_800A5040, &D_800A504C, &D_800A5058, &D_800A5064,
      &D_800A5070, &D_800A507C, &D_800A5088, &D_800A5094 },
};
FieldBattles stageBattles[] = {
    { 64, 0, 0, { &D_800A4F14, &D_800A4F98, &D_800A501C, &D_800A50A0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x19C, 0xC8, 0x9C, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x1C2, 0, 0xC2, 0x170, 0x1FF },
};
u16 D_800A5170[] = { 0x21C, 1, 0x8B16, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5180[] = {
    { NULL, D_800A5170, 0x17C },
    { NULL, NULL, 0 },
};
u16 D_800A5198[] = { 0x21C, 0, 0xFFFF };
FieldActorEntry D_800A51A0 = { D_800A5198, D_800A5180, 0x21, 4, 129, 417, 1 };
FieldActorEntry D_800A51B4 = { NULL, NULL, 0x4B, 5, 760, 357, 7 };
FieldActorEntry D_800A51C8 = { NULL, NULL, 0x4C, 6, 670, 280, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A51A0,
    &D_800A51B4,
    &D_800A51C8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 4, 0, 4, 9, 8, 0, 39, 524, 0, 0 },
    { 1, 0, 0x40, 2, 4, 0, 4, 9, 8, 0, 423, -13, 0, 0 },
    { 1, 0, 0x40, 2, 4, 0, 4, 9, 8, 0, 759, 748, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 337, 409, 0, 0 },
    { 1, 0, 0x74, 2, 2, 0, 0, 0, 0, 0, 655, 662, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 420, 521, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 646, 239, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 727, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 42, 777, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 351, 449, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 549, 447, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 631, 642, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 852, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1012, 373, 0, 0 },
    { 1, 0, 0x74, 6, 3, 0, 0, 0, 0, 0, 768, 640, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 96, 687, 687, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 923, 923, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 144, 663, 663, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 703, 703, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 943, 943, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 639, 639, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 911, 911, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 208, 679, 679, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 952, 952, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 655, 655, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 272, 197, 197, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 274, 262, 262, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 623, 623, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 937, 937, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 305, 230, 230, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 599, 599, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 352, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 583, 583, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 480, 591, 591, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 127, 127, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 624, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 896, 831, 831, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 807, 807, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 992, 783, 783, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1115, 428, 428, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x291, 0x32A, 0x334, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x298, 0x9A, 0x74, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0x12, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x1A1, 0x140, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x1B0, 0x176, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0x58, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0x40, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFC0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB8, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFF90, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x18, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFF0, 0x10, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
