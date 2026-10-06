#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x32E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x33D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11400, 0xC100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4EA0;
extern Battle D_800A4EAC;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A5080;
extern BattleList D_800A4F00;
extern BattleList D_800A4F84;
extern BattleList D_800A5008;
extern BattleList D_800A508C;
extern u16 D_800A514C[];
extern u16 D_800A515C[];
extern u16 D_800A519C[];
extern FieldTalk D_800A516C[];
extern u16 D_800A51A4[];
extern FieldTalk D_800A5184[];
extern FieldActorEntry D_800A51AC;
extern FieldActorEntry D_800A51C0;

Battle D_800A4EA0 = { 0, 0, 0x60040000 };
Battle D_800A4EAC = { 0, 0, 0x60040000 };
Battle D_800A4EB8 = { 0, 0, 0x60040000 };
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
BattleList D_800A4F00 = {
    0,
    { &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4,
      &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4 },
};
Battle D_800A4F24 = { 0, 0, 0x60040000 };
Battle D_800A4F30 = { 0, 0, 0x60040000 };
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
BattleList D_800A4F84 = {
    0,
    { &D_800A4F24, &D_800A4F30, &D_800A4F3C, &D_800A4F48,
      &D_800A4F54, &D_800A4F60, &D_800A4F6C, &D_800A4F78 },
};
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
Battle D_800A4FB4 = { 0, 0, 0x60040000 };
Battle D_800A4FC0 = { 0, 0, 0x60040000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
BattleList D_800A5008 = {
    0,
    { &D_800A4FA8, &D_800A4FB4, &D_800A4FC0, &D_800A4FCC,
      &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC },
};
Battle D_800A502C = { 188, 18, 0x60080000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 0, 0, 0x60040000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 0, 0, 0x60040000 };
Battle D_800A5080 = { 0, 0, 0x60040000 };
BattleList D_800A508C = {
    0,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
FieldBattles stageBattles[] = {
    { 133, 0, 0, { &D_800A4F00, &D_800A4F84, &D_800A5008, &D_800A508C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x158, 0xE0, 0x58, 0x170, 0x1FE },
    { 0x140, 0x100, 0x178, 0x1B0, 0xE0, 0xB0, 0x170, 0x1FD },
};
u16 D_800A514C[] = { 0x216, 1, 0x708E, 1, 0x7013, 1, 0xFFFF };
u16 D_800A515C[] = { 0x217, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A516C[] = {
    { NULL, D_800A514C, 0x48A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5184[] = {
    { NULL, D_800A515C, 0x2B6 },
    { NULL, NULL, 0 },
};
u16 D_800A519C[] = { 0x216, 0, 0xFFFF };
u16 D_800A51A4[] = { 0x217, 0, 0xFFFF };
FieldActorEntry D_800A51AC = { D_800A519C, D_800A516C, 0x21, 4, 809, 389, 1 };
FieldActorEntry D_800A51C0 = { D_800A51A4, D_800A5184, 0x4D, 5, 919, 300, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A51AC,
    &D_800A51C0,
    NULL,
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
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 821, 438, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 959, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 989, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 735, 352, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 928, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 929, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 813, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 876, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 944, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 985, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 799, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 777, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 667, 411, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 677, 414, 0, 0 },
    { 1, 0x65, 0x40, 6, 4, 0, 0, 0, 0, 0, 351, 103, 0, 0 },
    { 1, 0x64, 0x40, 6, 5, 0, 0, 0, 0, 0, 78, 169, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x216, 0x1E0, 0x118, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x217, 0x78, 0xFC, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x217, 0x508, 0x1CC, 3, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x215, 0x1A8, 0x1F4, 5, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
