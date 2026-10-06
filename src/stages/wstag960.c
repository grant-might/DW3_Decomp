#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x69F;
    D_800990B4.sheetEntry = 0x92F0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x92E;
    D_800990B4.start = (Vec2){0x9D00, 0x17F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x92F0002);
    D_8009A70C.setFile(7, 0x92F0003);
    D_8009A70C.setFile(4, 0x92F0001);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60F8;
extern StagePoint D_800A6108;
extern StagePoint D_800A6120;
extern StagePoint D_800A6130;
extern StagePoint D_800A6148;
extern StagePoint D_800A6158;
extern StagePoints D_800A6118;
extern StagePoints D_800A6140;
extern StagePoints D_800A6168;
extern FieldActorEntry D_800A61F0;
extern Battle D_800A63B0;
extern Battle D_800A63BC;
extern Battle D_800A63C8;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6434;
extern Battle D_800A6440;
extern Battle D_800A644C;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A64B8;
extern Battle D_800A64C4;
extern Battle D_800A64D0;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A653C;
extern Battle D_800A6548;
extern Battle D_800A6554;
extern Battle D_800A6560;
extern Battle D_800A656C;
extern Battle D_800A6578;
extern Battle D_800A6584;
extern Battle D_800A6590;
extern Battle D_800A65C0;
extern Battle D_800A65CC;
extern Battle D_800A65D8;
extern Battle D_800A65E4;
extern Battle D_800A65F0;
extern Battle D_800A65FC;
extern Battle D_800A6608;
extern Battle D_800A6614;
extern Battle D_800A6644;
extern Battle D_800A6650;
extern Battle D_800A665C;
extern Battle D_800A6668;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A6698;
extern Battle D_800A66C8;
extern Battle D_800A66D4;
extern Battle D_800A66E0;
extern Battle D_800A66EC;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A674C;
extern Battle D_800A6758;
extern Battle D_800A6764;
extern Battle D_800A6770;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67D0;
extern Battle D_800A67DC;
extern Battle D_800A67E8;
extern Battle D_800A67F4;
extern Battle D_800A6800;
extern Battle D_800A680C;
extern Battle D_800A6818;
extern Battle D_800A6824;
extern Battle D_800A6854;
extern Battle D_800A6860;
extern Battle D_800A686C;
extern Battle D_800A6878;
extern Battle D_800A6884;
extern Battle D_800A6890;
extern Battle D_800A689C;
extern Battle D_800A68A8;
extern Battle D_800A68D8;
extern Battle D_800A68E4;
extern Battle D_800A68F0;
extern Battle D_800A68FC;
extern Battle D_800A6908;
extern Battle D_800A6914;
extern Battle D_800A6920;
extern Battle D_800A692C;
extern Battle D_800A695C;
extern Battle D_800A6968;
extern Battle D_800A6974;
extern Battle D_800A6980;
extern Battle D_800A698C;
extern Battle D_800A6998;
extern Battle D_800A69A4;
extern Battle D_800A69B0;
extern BattleList D_800A6410;
extern BattleList D_800A6494;
extern BattleList D_800A6518;
extern BattleList D_800A659C;
extern BattleList D_800A6620;
extern BattleList D_800A66A4;
extern BattleList D_800A6728;
extern BattleList D_800A67AC;
extern BattleList D_800A6830;
extern BattleList D_800A68B4;
extern BattleList D_800A6938;
extern BattleList D_800A69BC;

StagePoint D_800A60F8 = { 0x2E6, 2, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A6108 = { 0x299, 0, 0, 0x32C, 0x232, 0, &D_800A60F8 };
StagePoints D_800A6118 = { 2, 1, &D_800A6108 };
StagePoint D_800A6120 = { 0x2E4, 3, 1, 0x340, 160, 1, NULL };
StagePoint D_800A6130 = { 0x297, 0, 0, 0x210, 0x370, 0, &D_800A6120 };
StagePoints D_800A6140 = { 3, 1, &D_800A6130 };
StagePoint D_800A6148 = { 0x2E4, 5, 1, 0x340, 160, 1, NULL };
StagePoint D_800A6158 = { 0x28F, 0, 0, 112, 184, 0, &D_800A6148 };
StagePoints D_800A6168 = { 5, 1, &D_800A6158 };
StagePoints *placePoints[] = {
    &D_800A6118, &D_800A6140, &D_800A6168, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x15D, 0x1C0, 0x5D, 0x160, 0x1FF },
};
FieldActorEntry D_800A61F0 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A61F0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 346, 191, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 653, 112, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 179, 218, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 563, 120, 0, 0 },
    { 1, 0, 0xA0, 2, 0xB, 0, 0, 0, 0, 0, 448, 198, 0, 0 },
    { 1, 0, 0x95, 2, 0xC, 0, 0, 0, 0, 0, 480, 210, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 266, 189, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 540, -12, 244, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 240, 273, 351, 0 },
    { 1, 0, 0x68, 4, 1, 0, 0, 0, 0, 0, 208, 259, 345, 0 },
    { 1, 0, 0x58, 4, 2, 0, 0, 0, 0, 0, 196, 254, 332, 0 },
    { 1, 0, 0x58, 4, 3, 0, 0, 0, 0, 0, 416, 180, 305, 0 },
    { 1, 0, 0x93, 4, 4, 0, 0, 0, 0, 0, 384, 157, 299, 0 },
    { 1, 0, 0x79, 4, 5, 0, 0, 0, 0, 0, 352, 151, 270, 0 },
    { 1, 0, 0x94, 4, 6, 0, 0, 0, 0, 0, 320, 131, 277, 0 },
    { 1, 0, 0x5C, 4, 8, 0, 0, 0, 0, 0, 528, 180, 268, 0 },
    { 1, 0, 0x63, 4, 9, 0, 0, 0, 0, 0, 496, 164, 260, 0 },
    { 1, 0, 0x5D, 4, 0xA, 0, 0, 0, 0, 0, 485, 159, 250, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E0, 0x240, 0xD8, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E0, 0xB0, 0x178, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A63B0 = { 61, 11, 0x60080000 };
Battle D_800A63BC = { 61, 11, 0x60080000 };
Battle D_800A63C8 = { 61, 11, 0x60080000 };
Battle D_800A63D4 = { 61, 11, 0x60080000 };
Battle D_800A63E0 = { 61, 11, 0x60080000 };
Battle D_800A63EC = { 61, 11, 0x60080000 };
Battle D_800A63F8 = { 61, 11, 0x60080000 };
Battle D_800A6404 = { 61, 11, 0x60080000 };
BattleList D_800A6410 = {
    3,
    { &D_800A63B0, &D_800A63BC, &D_800A63C8, &D_800A63D4,
      &D_800A63E0, &D_800A63EC, &D_800A63F8, &D_800A6404 },
};
Battle D_800A6434 = { 0, 0, 0x60040000 };
Battle D_800A6440 = { 0, 0, 0x60040000 };
Battle D_800A644C = { 0, 0, 0x60040000 };
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
BattleList D_800A6494 = {
    0,
    { &D_800A6434, &D_800A6440, &D_800A644C, &D_800A6458,
      &D_800A6464, &D_800A6470, &D_800A647C, &D_800A6488 },
};
Battle D_800A64B8 = { 0, 0, 0x60040000 };
Battle D_800A64C4 = { 0, 0, 0x60040000 };
Battle D_800A64D0 = { 0, 0, 0x60040000 };
Battle D_800A64DC = { 0, 0, 0x60040000 };
Battle D_800A64E8 = { 0, 0, 0x60040000 };
Battle D_800A64F4 = { 0, 0, 0x60040000 };
Battle D_800A6500 = { 0, 0, 0x60040000 };
Battle D_800A650C = { 0, 0, 0x60040000 };
BattleList D_800A6518 = {
    0,
    { &D_800A64B8, &D_800A64C4, &D_800A64D0, &D_800A64DC,
      &D_800A64E8, &D_800A64F4, &D_800A6500, &D_800A650C },
};
Battle D_800A653C = { 0, 0, 0x60040000 };
Battle D_800A6548 = { 0, 0, 0x60040000 };
Battle D_800A6554 = { 0, 0, 0x60040000 };
Battle D_800A6560 = { 0, 0, 0x60040000 };
Battle D_800A656C = { 0, 0, 0x60040000 };
Battle D_800A6578 = { 0, 0, 0x60040000 };
Battle D_800A6584 = { 0, 0, 0x60040000 };
Battle D_800A6590 = { 0, 0, 0x60040000 };
BattleList D_800A659C = {
    0,
    { &D_800A653C, &D_800A6548, &D_800A6554, &D_800A6560,
      &D_800A656C, &D_800A6578, &D_800A6584, &D_800A6590 },
};
Battle D_800A65C0 = { 64, 11, 0x60080000 };
Battle D_800A65CC = { 64, 11, 0x60080000 };
Battle D_800A65D8 = { 64, 11, 0x60080000 };
Battle D_800A65E4 = { 64, 11, 0x60080000 };
Battle D_800A65F0 = { 64, 11, 0x60080000 };
Battle D_800A65FC = { 64, 11, 0x60080000 };
Battle D_800A6608 = { 64, 11, 0x60080000 };
Battle D_800A6614 = { 64, 11, 0x60080000 };
BattleList D_800A6620 = {
    3,
    { &D_800A65C0, &D_800A65CC, &D_800A65D8, &D_800A65E4,
      &D_800A65F0, &D_800A65FC, &D_800A6608, &D_800A6614 },
};
Battle D_800A6644 = { 0, 0, 0x60040000 };
Battle D_800A6650 = { 0, 0, 0x60040000 };
Battle D_800A665C = { 0, 0, 0x60040000 };
Battle D_800A6668 = { 0, 0, 0x60040000 };
Battle D_800A6674 = { 0, 0, 0x60040000 };
Battle D_800A6680 = { 0, 0, 0x60040000 };
Battle D_800A668C = { 0, 0, 0x60040000 };
Battle D_800A6698 = { 0, 0, 0x60040000 };
BattleList D_800A66A4 = {
    0,
    { &D_800A6644, &D_800A6650, &D_800A665C, &D_800A6668,
      &D_800A6674, &D_800A6680, &D_800A668C, &D_800A6698 },
};
Battle D_800A66C8 = { 0, 0, 0x60040000 };
Battle D_800A66D4 = { 0, 0, 0x60040000 };
Battle D_800A66E0 = { 0, 0, 0x60040000 };
Battle D_800A66EC = { 0, 0, 0x60040000 };
Battle D_800A66F8 = { 0, 0, 0x60040000 };
Battle D_800A6704 = { 0, 0, 0x60040000 };
Battle D_800A6710 = { 0, 0, 0x60040000 };
Battle D_800A671C = { 0, 0, 0x60040000 };
BattleList D_800A6728 = {
    0,
    { &D_800A66C8, &D_800A66D4, &D_800A66E0, &D_800A66EC,
      &D_800A66F8, &D_800A6704, &D_800A6710, &D_800A671C },
};
Battle D_800A674C = { 0, 0, 0x60040000 };
Battle D_800A6758 = { 0, 0, 0x60040000 };
Battle D_800A6764 = { 0, 0, 0x60040000 };
Battle D_800A6770 = { 0, 0, 0x60040000 };
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
BattleList D_800A67AC = {
    0,
    { &D_800A674C, &D_800A6758, &D_800A6764, &D_800A6770,
      &D_800A677C, &D_800A6788, &D_800A6794, &D_800A67A0 },
};
Battle D_800A67D0 = { 63, 11, 0x60080000 };
Battle D_800A67DC = { 63, 11, 0x60080000 };
Battle D_800A67E8 = { 63, 11, 0x60080000 };
Battle D_800A67F4 = { 63, 11, 0x60080000 };
Battle D_800A6800 = { 63, 11, 0x60080000 };
Battle D_800A680C = { 63, 11, 0x60080000 };
Battle D_800A6818 = { 63, 11, 0x60080000 };
Battle D_800A6824 = { 63, 11, 0x60080000 };
BattleList D_800A6830 = {
    4,
    { &D_800A67D0, &D_800A67DC, &D_800A67E8, &D_800A67F4,
      &D_800A6800, &D_800A680C, &D_800A6818, &D_800A6824 },
};
Battle D_800A6854 = { 0, 0, 0x60040000 };
Battle D_800A6860 = { 0, 0, 0x60040000 };
Battle D_800A686C = { 0, 0, 0x60040000 };
Battle D_800A6878 = { 0, 0, 0x60040000 };
Battle D_800A6884 = { 0, 0, 0x60040000 };
Battle D_800A6890 = { 0, 0, 0x60040000 };
Battle D_800A689C = { 0, 0, 0x60040000 };
Battle D_800A68A8 = { 0, 0, 0x60040000 };
BattleList D_800A68B4 = {
    0,
    { &D_800A6854, &D_800A6860, &D_800A686C, &D_800A6878,
      &D_800A6884, &D_800A6890, &D_800A689C, &D_800A68A8 },
};
Battle D_800A68D8 = { 0, 0, 0x60040000 };
Battle D_800A68E4 = { 0, 0, 0x60040000 };
Battle D_800A68F0 = { 0, 0, 0x60040000 };
Battle D_800A68FC = { 0, 0, 0x60040000 };
Battle D_800A6908 = { 0, 0, 0x60040000 };
Battle D_800A6914 = { 0, 0, 0x60040000 };
Battle D_800A6920 = { 0, 0, 0x60040000 };
Battle D_800A692C = { 0, 0, 0x60040000 };
BattleList D_800A6938 = {
    0,
    { &D_800A68D8, &D_800A68E4, &D_800A68F0, &D_800A68FC,
      &D_800A6908, &D_800A6914, &D_800A6920, &D_800A692C },
};
Battle D_800A695C = { 0, 0, 0x60040000 };
Battle D_800A6968 = { 0, 0, 0x60040000 };
Battle D_800A6974 = { 0, 0, 0x60040000 };
Battle D_800A6980 = { 0, 0, 0x60040000 };
Battle D_800A698C = { 0, 0, 0x60040000 };
Battle D_800A6998 = { 0, 0, 0x60040000 };
Battle D_800A69A4 = { 0, 0, 0x60040000 };
Battle D_800A69B0 = { 0, 0, 0x60040000 };
BattleList D_800A69BC = {
    0,
    { &D_800A695C, &D_800A6968, &D_800A6974, &D_800A6980,
      &D_800A698C, &D_800A6998, &D_800A69A4, &D_800A69B0 },
};
FieldBattles stageBattles[] = {
    { 397, 2, 0, { &D_800A6410, &D_800A6494, &D_800A6518, &D_800A659C } },
    { 401, 3, 0, { &D_800A6620, &D_800A66A4, &D_800A6728, &D_800A67AC } },
    { 410, 5, 0, { &D_800A6830, &D_800A68B4, &D_800A6938, &D_800A69BC } },
};
