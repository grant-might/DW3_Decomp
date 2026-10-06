#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x51B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x52B
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12C00, 0x12100};
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
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
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
extern u16 D_800A536C[];
extern FieldTalk D_800A51EC[];
extern u16 D_800A5374[];
extern FieldTalk D_800A5204[];
extern u16 D_800A537C[];
extern FieldTalk D_800A521C[];
extern u16 D_800A5384[];
extern FieldTalk D_800A5234[];
extern u16 D_800A5390[];
extern FieldTalk D_800A524C[];
extern u16 D_800A5398[];
extern FieldTalk D_800A5264[];
extern u16 D_800A53A4[];
extern FieldTalk D_800A527C[];
extern u16 D_800A53AC[];
extern FieldTalk D_800A5294[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A52AC[];
extern u16 D_800A53C0[];
extern FieldTalk D_800A52C4[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A52DC[];
extern u16 D_800A53D4[];
extern FieldTalk D_800A52F4[];
extern u16 D_800A53E0[];
extern FieldTalk D_800A530C[];
extern u16 D_800A53E8[];
extern FieldTalk D_800A5324[];
extern u16 D_800A53F4[];
extern FieldTalk D_800A533C[];
extern u16 D_800A53FC[];
extern FieldTalk D_800A5354[];
extern FieldActorEntry D_800A5404;
extern FieldActorEntry D_800A5418;
extern FieldActorEntry D_800A542C;
extern FieldActorEntry D_800A5440;
extern FieldActorEntry D_800A5454;
extern FieldActorEntry D_800A5468;
extern FieldActorEntry D_800A547C;
extern FieldActorEntry D_800A5490;
extern FieldActorEntry D_800A54A4;
extern FieldActorEntry D_800A54B8;
extern FieldActorEntry D_800A54CC;
extern FieldActorEntry D_800A54E0;
extern FieldActorEntry D_800A54F4;
extern FieldActorEntry D_800A5508;
extern FieldActorEntry D_800A551C;
extern FieldActorEntry D_800A5530;

Battle D_800A4EA0 = { 0, 0, 0x60040000 };
Battle D_800A4EAC = { 0, 0, 0x60040000 };
Battle D_800A4EB8 = { 0, 0, 0x60040000 };
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
BattleList D_800A4F00 = {
    3,
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
Battle D_800A502C = { 0, 0, 0x60040000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 330, 8, 0x60080000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 0, 0, 0x60040000 };
Battle D_800A5080 = { 178, 8, 0x60080000 };
BattleList D_800A508C = {
    0,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
FieldBattles stageBattles[] = {
    { 376, 0, 0, { &D_800A4F00, &D_800A4F84, &D_800A5008, &D_800A508C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x141, 0x100, 0x41, 0x170, 0x1FE },
    { 0x180, 0x100, 0x19A, 0x165, 0x168, 0x65, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x170, 0x1FC },
    { 0x180, 0x100, 0x188, 0x151, 0x120, 0x51, 0x140, 0x1FB },
    { 0x180, 0x100, 0x1AE, 0x152, 0x1B8, 0x52, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1B6, 0x152, 0x1D8, 0x52, 0x160, 0x1FB },
    { 0x180, 0x100, 0x1A2, 0x163, 0x188, 0x63, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1B4, 0x17A, 0x1D0, 0x7A, 0x140, 0x1FA },
    { 0x180, 0x100, 0x18A, 0x17F, 0x128, 0x7F, 0x150, 0x1FA },
    { 0x180, 0x100, 0x192, 0x17F, 0x148, 0x7F, 0x160, 0x1FA },
    { 0x180, 0x100, 0x19A, 0x185, 0x168, 0x85, 0x170, 0x1FA },
    { 0x180, 0x100, 0x1A2, 0x18B, 0x188, 0x8B, 0x140, 0x1F9 },
};
FieldTalk D_800A51EC[] = {
    { NULL, NULL, 0xE3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5204[] = {
    { NULL, NULL, 0xE4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A521C[] = {
    { NULL, NULL, 0xE2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5234[] = {
    { NULL, NULL, 0xDC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A524C[] = {
    { NULL, NULL, 0xDA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5264[] = {
    { NULL, NULL, 0xD8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A527C[] = {
    { NULL, NULL, 0xE1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5294[] = {
    { NULL, NULL, 0xDF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52AC[] = {
    { NULL, NULL, 0xE0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C4[] = {
    { NULL, NULL, 0xDE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52DC[] = {
    { NULL, NULL, 0xDD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F4[] = {
    { NULL, NULL, 0xDB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A530C[] = {
    { NULL, NULL, 0xD9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5324[] = {
    { NULL, NULL, 0xD7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A533C[] = {
    { NULL, NULL, 0xE5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5354[] = {
    { NULL, NULL, 0xE6 },
    { NULL, NULL, 0 },
};
u16 D_800A536C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5374[] = { 0x602B, 1, 0xFFFF };
u16 D_800A537C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5384[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5390[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5398[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53AC[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53C0[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53D4[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53E0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53E8[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53F4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53FC[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5404 = { D_800A536C, D_800A51EC, 0x20, 4, 648, 396, 5 };
FieldActorEntry D_800A5418 = { D_800A5374, D_800A5204, 0x23, 5, 330, 398, 1 };
FieldActorEntry D_800A542C = { D_800A537C, D_800A521C, 0x25, 6, 680, 380, 1 };
FieldActorEntry D_800A5440 = { D_800A5384, D_800A5234, 0x2F, 7, 208, 344, 5 };
FieldActorEntry D_800A5454 = { D_800A5390, D_800A524C, 0x33, 8, 460, 203, 5 };
FieldActorEntry D_800A5468 = { D_800A5398, D_800A5264, 0x33, 8, 460, 203, 5 };
FieldActorEntry D_800A547C = { D_800A53A4, D_800A527C, 0x34, 9, 494, 186, 1 };
FieldActorEntry D_800A5490 = { D_800A53AC, D_800A5294, 0x35, 0xA, 513, 425, 7 };
FieldActorEntry D_800A54A4 = { D_800A53B8, D_800A52AC, 0x9D, 0xB, 513, 425, 7 };
FieldActorEntry D_800A54B8 = { D_800A53C0, D_800A52C4, 0x9D, 0xB, 513, 425, 7 };
FieldActorEntry D_800A54CC = { D_800A53CC, D_800A52DC, 0x9E, 0xC, 208, 344, 5 };
FieldActorEntry D_800A54E0 = { D_800A53D4, D_800A52F4, 0x9E, 0xC, 208, 344, 5 };
FieldActorEntry D_800A54F4 = { D_800A53E0, D_800A530C, 0x9F, 0xD, 460, 203, 5 };
FieldActorEntry D_800A5508 = { D_800A53E8, D_800A5324, 0x9F, 0xD, 460, 203, 5 };
FieldActorEntry D_800A551C = { D_800A53F4, D_800A533C, 0xE4, 0xE, 513, 425, 7 };
FieldActorEntry D_800A5530 = { D_800A53FC, D_800A5354, 0xE5, 0xF, 672, 304, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5404,
    &D_800A5418,
    &D_800A542C,
    &D_800A5440,
    &D_800A5454,
    &D_800A5468,
    &D_800A547C,
    &D_800A5490,
    &D_800A54A4,
    &D_800A54B8,
    &D_800A54CC,
    &D_800A54E0,
    &D_800A54F4,
    &D_800A5508,
    &D_800A551C,
    &D_800A5530,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 174, 210, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 244, 175, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 840, 188, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 886, 211, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 341, 183, 0, 0 },
    { 1, 0, 0x40, 2, 4, 0, 0, 0, 0, 0, 95, 116, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 168, 256, 0, 0 },
    { 1, 0, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 846, 150, 0, 0 },
    { 1, 0, 0x58, 2, 0xF, 0, 0, 0, 0, 0, 426, 256, 0, 0 },
    { 1, 0, 0x50, 2, 0x10, 0, 0, 0, 0, 0, 323, 384, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 640, 256, 0, 0 },
    { 1, 0, 0x60, 2, 0x12, 0, 0, 0, 0, 0, 548, 202, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 676, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 386, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 498, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 155, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 668, 159, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 847, 321, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 185, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 408, 477, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 686, 248, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 745, 469, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 350, 152, 0, 0 },
    { 1, 0x65, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 463, 106, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 878, 199, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 268, 289, 0 },
    { 1, 0, 0x41, 4, 1, 0, 0, 0, 0, 0, 336, 159, 216, 0 },
    { 1, 0, 0x46, 4, 2, 0, 0, 0, 0, 0, 448, 103, 162, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 891, 200, 247, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27A, 0x68, 0x134, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x282, 0x218, 0xF4, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x280, 0x216, 0xE2, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27F, 0x98, 0x14A, 5, 0x66, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x20, 0x18, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x1C, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
