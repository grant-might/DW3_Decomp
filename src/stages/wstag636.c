#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x627
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x637
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11F00, 0x2F100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A4F7C;
extern StagePoint D_800A4F8C;
extern StagePoint D_800A4F9C;
extern StagePoint D_800A4FAC;
extern StagePoint D_800A4FC4;
extern StagePoint D_800A4FD4;
extern StagePoint D_800A4FE4;
extern StagePoint D_800A4FF4;
extern StagePoint D_800A500C;
extern StagePoint D_800A501C;
extern StagePoint D_800A502C;
extern StagePoint D_800A503C;
extern StagePoint D_800A5054;
extern StagePoint D_800A5064;
extern StagePoint D_800A5074;
extern StagePoint D_800A5084;
extern StagePoint D_800A509C;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50BC;
extern StagePoint D_800A50CC;
extern StagePoint D_800A50E4;
extern StagePoint D_800A50F4;
extern StagePoint D_800A5104;
extern StagePoint D_800A5114;
extern StagePoint D_800A512C;
extern StagePoint D_800A513C;
extern StagePoint D_800A514C;
extern StagePoint D_800A515C;
extern StagePoint D_800A5174;
extern StagePoint D_800A5184;
extern StagePoint D_800A5194;
extern StagePoint D_800A51A4;
extern StagePoints D_800A4FBC;
extern StagePoints D_800A5004;
extern StagePoints D_800A504C;
extern StagePoints D_800A5094;
extern StagePoints D_800A50DC;
extern StagePoints D_800A5124;
extern StagePoints D_800A516C;
extern StagePoints D_800A51B4;
extern StagePoints D_800A51BC;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern Battle D_800A5348;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A5390;
extern Battle D_800A539C;
extern Battle D_800A53A8;
extern Battle D_800A53B4;
extern Battle D_800A53C0;
extern Battle D_800A53CC;
extern BattleList D_800A524C;
extern BattleList D_800A52D0;
extern BattleList D_800A5354;
extern BattleList D_800A53D8;
extern u16 D_800A54A8[];
extern u16 D_800A54B0[];
extern u16 D_800A54BC[];
extern u16 D_800A54C4[];
extern u16 D_800A54D4[];
extern u16 D_800A54E4[];
extern u16 D_800A5564[];
extern FieldTalk D_800A54F8[];
extern u16 D_800A5570[];
extern FieldTalk D_800A5510[];
extern u16 D_800A558C[];
extern FieldTalk D_800A554C[];
extern FieldActorEntry D_800A5598;
extern FieldActorEntry D_800A55AC;
extern FieldActorEntry D_800A55C0;

StagePoint D_800A4F7C = { 0x2C2, 1, 2, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A4F8C = { 0x2C2, 1, 3, 0x358, 252, 1, &D_800A4F7C };
StagePoint D_800A4F9C = { 0x2C2, 1, 1, 0x120, 0x100, 7, &D_800A4F8C };
StagePoint D_800A4FAC = { 0x2C0, 0, 0, 0x100, 0x278, 5, &D_800A4F9C };
StagePoints D_800A4FBC = { 1, 1, &D_800A4FAC };
StagePoint D_800A4FC4 = { 0x2C2, 1, 1, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A4FD4 = { 0x2C2, 1, 4, 0x358, 252, 1, &D_800A4FC4 };
StagePoint D_800A4FE4 = { 0x2C2, 1, 2, 0x120, 0x100, 7, &D_800A4FD4 };
StagePoint D_800A4FF4 = { 0x2C0, 0, 0, 0x100, 0x278, 5, &D_800A4FE4 };
StagePoints D_800A5004 = { 1, 2, &D_800A4FF4 };
StagePoint D_800A500C = { 0x2C2, 1, 3, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A501C = { 0x2C2, 1, 5, 0x358, 252, 1, &D_800A500C };
StagePoint D_800A502C = { 0x2C2, 1, 4, 0x120, 0x100, 7, &D_800A501C };
StagePoint D_800A503C = { 0x2C2, 1, 1, 0x118, 0x2EC, 5, &D_800A502C };
StagePoints D_800A504C = { 1, 3, &D_800A503C };
StagePoint D_800A5054 = { 0x2C2, 1, 4, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A5064 = { 0x2C2, 1, 6, 0x358, 252, 1, &D_800A5054 };
StagePoint D_800A5074 = { 0x2C2, 1, 3, 0x120, 0x100, 7, &D_800A5064 };
StagePoint D_800A5084 = { 0x2C2, 1, 2, 0x118, 0x2EC, 5, &D_800A5074 };
StagePoints D_800A5094 = { 1, 4, &D_800A5084 };
StagePoint D_800A509C = { 0x2C2, 1, 6, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A50AC = { 0x2C2, 1, 7, 0x358, 252, 1, &D_800A509C };
StagePoint D_800A50BC = { 0x2C2, 1, 5, 0x120, 0x100, 7, &D_800A50AC };
StagePoint D_800A50CC = { 0x2C2, 1, 3, 0x118, 0x2EC, 5, &D_800A50BC };
StagePoints D_800A50DC = { 1, 5, &D_800A50CC };
StagePoint D_800A50E4 = { 0x2C3, 0, 0, 0x2F8, 0x244, 3, NULL };
StagePoint D_800A50F4 = { 0x2C2, 1, 8, 0x358, 252, 1, &D_800A50E4 };
StagePoint D_800A5104 = { 0x2C2, 1, 6, 0x120, 0x100, 7, &D_800A50F4 };
StagePoint D_800A5114 = { 0x2C2, 1, 4, 0x118, 0x2EC, 5, &D_800A5104 };
StagePoints D_800A5124 = { 1, 6, &D_800A5114 };
StagePoint D_800A512C = { 0x2C2, 1, 7, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A513C = { 0x2C2, 1, 1, 0x358, 252, 1, &D_800A512C };
StagePoint D_800A514C = { 0x2C2, 1, 8, 0x120, 0x100, 7, &D_800A513C };
StagePoint D_800A515C = { 0x2C2, 1, 5, 0x118, 0x2EC, 5, &D_800A514C };
StagePoints D_800A516C = { 1, 7, &D_800A515C };
StagePoint D_800A5174 = { 0x2C2, 1, 8, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A5184 = { 0x2C2, 1, 2, 0x358, 252, 1, &D_800A5174 };
StagePoint D_800A5194 = { 0x2C2, 1, 7, 0x120, 0x100, 7, &D_800A5184 };
StagePoint D_800A51A4 = { 0x2C2, 1, 6, 0x118, 0x2EC, 5, &D_800A5194 };
StagePoints D_800A51B4 = { 1, 8, &D_800A51A4 };
StagePoints D_800A51BC = { 0, 0, &D_800A4FAC };
StagePoints *placePoints[] = {
    &D_800A4FBC, &D_800A5004, &D_800A504C, &D_800A5094,
    &D_800A50DC, &D_800A5124, &D_800A516C, &D_800A51B4,
    &D_800A51BC, NULL,
};
Battle D_800A51EC = { 72, 5, 0x60080000 };
Battle D_800A51F8 = { 72, 5, 0x60080000 };
Battle D_800A5204 = { 72, 5, 0x60080000 };
Battle D_800A5210 = { 72, 5, 0x60080000 };
Battle D_800A521C = { 162, 5, 0x60080000 };
Battle D_800A5228 = { 162, 5, 0x60080000 };
Battle D_800A5234 = { 162, 5, 0x60080000 };
Battle D_800A5240 = { 162, 5, 0x60080000 };
BattleList D_800A524C = {
    3,
    { &D_800A51EC, &D_800A51F8, &D_800A5204, &D_800A5210,
      &D_800A521C, &D_800A5228, &D_800A5234, &D_800A5240 },
};
Battle D_800A5270 = { 0, 0, 0x60040000 };
Battle D_800A527C = { 0, 0, 0x60040000 };
Battle D_800A5288 = { 0, 0, 0x60040000 };
Battle D_800A5294 = { 0, 0, 0x60040000 };
Battle D_800A52A0 = { 0, 0, 0x60040000 };
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
Battle D_800A52C4 = { 0, 0, 0x60040000 };
BattleList D_800A52D0 = {
    0,
    { &D_800A5270, &D_800A527C, &D_800A5288, &D_800A5294,
      &D_800A52A0, &D_800A52AC, &D_800A52B8, &D_800A52C4 },
};
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
Battle D_800A530C = { 0, 0, 0x60040000 };
Battle D_800A5318 = { 0, 0, 0x60040000 };
Battle D_800A5324 = { 0, 0, 0x60040000 };
Battle D_800A5330 = { 0, 0, 0x60040000 };
Battle D_800A533C = { 0, 0, 0x60040000 };
Battle D_800A5348 = { 0, 0, 0x60040000 };
BattleList D_800A5354 = {
    0,
    { &D_800A52F4, &D_800A5300, &D_800A530C, &D_800A5318,
      &D_800A5324, &D_800A5330, &D_800A533C, &D_800A5348 },
};
Battle D_800A5378 = { 0, 0, 0x60040000 };
Battle D_800A5384 = { 0, 0, 0x60040000 };
Battle D_800A5390 = { 0, 0, 0x60040000 };
Battle D_800A539C = { 0, 0, 0x60040000 };
Battle D_800A53A8 = { 0, 0, 0x60040000 };
Battle D_800A53B4 = { 0, 0, 0x60040000 };
Battle D_800A53C0 = { 0, 0, 0x60040000 };
Battle D_800A53CC = { 0, 0, 0x60040000 };
BattleList D_800A53D8 = {
    0,
    { &D_800A5378, &D_800A5384, &D_800A5390, &D_800A539C,
      &D_800A53A8, &D_800A53B4, &D_800A53C0, &D_800A53CC },
};
FieldBattles stageBattles[] = {
    { 102, 0, 0, { &D_800A524C, &D_800A52D0, &D_800A5354, &D_800A53D8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x1A0, 0x88, 0xA0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x158, 0x1A0, 0x60, 0xA0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x162, 0x1C0, 0x88, 0xC0, 0x160, 0x1FF },
};
u16 D_800A54A8[] = { 0x8682, 1, 0xFFFF };
u16 D_800A54B0[] = { 0x8682, 0, 0, 0, 0xFFFF };
u16 D_800A54BC[] = { 0, 1, 0xFFFF };
u16 D_800A54C4[] = { 0x8682, 0, 0, 1, 0x847E, 0, 0xFFFF };
u16 D_800A54D4[] = { 0, 1, 0x847E, 1, 0x8682, 0, 0xFFFF };
u16 D_800A54E4[] = { 0x8682, 1, 0x8681, 0, 0x847E, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A54F8[] = {
    { NULL, NULL, 0x3C9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5510[] = {
    { D_800A54A8, NULL, 0x350 },
    { D_800A54B0, D_800A54BC, 0x351 },
    { D_800A54C4, NULL, 0x352 },
    { D_800A54D4, D_800A54E4, 0x353 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A554C[] = {
    { NULL, NULL, 0x3CA },
    { NULL, NULL, 0 },
};
u16 D_800A5564[] = { 0x7E00, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A5570[] = {
    0x7043, 1, 0x704B, 1, 0x8681, 1, 0x8682, 0,
    0x7E00, 1, 0x7E1F, 1, 0xFFFF,
};
u16 D_800A558C[] = { 0x7E00, 1, 0x7E23, 1, 0xFFFF };
FieldActorEntry D_800A5598 = { D_800A5564, D_800A54F8, 0x40, 4, 408, 364, 7 };
FieldActorEntry D_800A55AC = { D_800A5570, D_800A5510, 0xA7, 5, 480, 696, 7 };
FieldActorEntry D_800A55C0 = { D_800A558C, D_800A554C, 0xB5, 6, 480, 696, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5598,
    &D_800A55AC,
    &D_800A55C0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 7, 0, 0, 0, 0, 0, 568, 143, 0, 0 },
    { 1, 0, 0x40, 2, 7, 0, 0, 0, 0, 0, 904, 503, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 417, 278, 329, 0 },
    { 1, 0, 0x48, 4, 1, 0, 0, 0, 0, 0, 348, 278, 342, 0 },
    { 1, 0, 0x4A, 4, 2, 0, 0, 0, 0, 0, 529, 611, 680, 0 },
    { 1, 0, 0x5A, 4, 3, 0, 0, 0, 0, 0, 422, 570, 656, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 384, 635, 719, 0 },
    { 1, 0, 0x64, 4, 5, 0, 0, 0, 0, 0, 918, 517, 608, 0 },
    { 1, 0, 0x64, 4, 6, 0, 0, 0, 0, 0, 582, 156, 248, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x340, 0xF0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x368, 0x2EC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x128, 0x2F4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x110, 0x108, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
