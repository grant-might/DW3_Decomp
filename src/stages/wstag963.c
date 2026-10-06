#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x74A;
    D_800990B4.sheetEntry = 0x9350004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x934;
    D_800990B4.start = (Vec2){0x15300, 0x13900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9350006);
    D_8009A70C.setFile(7, 0x9350007);
    D_8009A70C.setFile(4, 0x9350005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A6100;
extern StagePoint D_800A6110;
extern StagePoint D_800A6128;
extern StagePoint D_800A6138;
extern StagePoints D_800A6120;
extern StagePoints D_800A6148;
extern FieldActorEntry D_800A61CC;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6410;
extern Battle D_800A641C;
extern Battle D_800A6428;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A6494;
extern Battle D_800A64A0;
extern Battle D_800A64AC;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern Battle D_800A6524;
extern Battle D_800A6530;
extern Battle D_800A6560;
extern Battle D_800A656C;
extern Battle D_800A6578;
extern Battle D_800A6584;
extern Battle D_800A6590;
extern Battle D_800A659C;
extern Battle D_800A65A8;
extern Battle D_800A65B4;
extern Battle D_800A65E4;
extern Battle D_800A65F0;
extern Battle D_800A65FC;
extern Battle D_800A6608;
extern Battle D_800A6614;
extern Battle D_800A6620;
extern Battle D_800A662C;
extern Battle D_800A6638;
extern Battle D_800A6668;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66BC;
extern Battle D_800A66EC;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6740;
extern Battle D_800A6770;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67C4;
extern BattleList D_800A6434;
extern BattleList D_800A64B8;
extern BattleList D_800A653C;
extern BattleList D_800A65C0;
extern BattleList D_800A6644;
extern BattleList D_800A66C8;
extern BattleList D_800A674C;
extern BattleList D_800A67D0;

StagePoint D_800A6100 = { 0x2E1, 1, 1, 0x390, 0x108, 1, NULL };
StagePoint D_800A6110 = { 0x28A, 0, 0, 128, 0x1E0, 0, &D_800A6100 };
StagePoints D_800A6120 = { 1, 1, &D_800A6110 };
StagePoint D_800A6128 = { 0x2E6, 4, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A6138 = { 0x28E, 0, 0, 224, 0x208, 0, &D_800A6128 };
StagePoints D_800A6148 = { 4, 1, &D_800A6138 };
StagePoints *placePoints[] = {
    &D_800A6120, &D_800A6148, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1A1, 0, 0xA1, 0x160, 0x1FF },
};
FieldActorEntry D_800A61CC = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A61CC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 948, 29, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 311, 207, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 636, 93, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 871, 27, 0, 0 },
    { 1, 0, 0x8B, 2, 0, 0, 0, 0, 0, 0, 720, 158, 0, 0 },
    { 1, 0, 0xA1, 2, 1, 0, 0, 0, 0, 0, 688, 136, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 262, 340, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 0, 0, 0, 0, 0, 320, 330, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 384, 299, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 448, 266, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 373, 118, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 490, 66, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 148, 233, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 753, 1, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 860, -124, 120, 0 },
    { 1, 0, 0x8B, 4, 2, 0, 0, 0, 0, 0, 656, 118, 250, 0 },
    { 1, 0, 0x8A, 4, 3, 0, 0, 0, 0, 0, 624, 104, 234, 0 },
    { 1, 0, 0x79, 4, 4, 0, 0, 0, 0, 0, 592, 89, 218, 0 },
    { 1, 0, 0x98, 4, 5, 0, 0, 0, 0, 0, 560, 70, 202, 0 },
    { 1, 0, 0x55, 4, 7, 0, 0, 0, 0, 0, 400, 249, 338, 0 },
    { 1, 0, 0x67, 4, 8, 0, 0, 0, 0, 0, 368, 233, 322, 0 },
    { 1, 0, 0x5E, 4, 9, 0, 0, 0, 0, 0, 352, 228, 314, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E3, 0x380, 0x70, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E3, 0xA0, 0x180, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A63D4 = { 62, 11, 0x60080000 };
Battle D_800A63E0 = { 62, 11, 0x60080000 };
Battle D_800A63EC = { 103, 11, 0x60080000 };
Battle D_800A63F8 = { 103, 11, 0x60080000 };
Battle D_800A6404 = { 103, 11, 0x60080000 };
Battle D_800A6410 = { 273, 11, 0x60080000 };
Battle D_800A641C = { 273, 11, 0x60080000 };
Battle D_800A6428 = { 273, 11, 0x60080000 };
BattleList D_800A6434 = {
    5,
    { &D_800A63D4, &D_800A63E0, &D_800A63EC, &D_800A63F8,
      &D_800A6404, &D_800A6410, &D_800A641C, &D_800A6428 },
};
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
Battle D_800A6494 = { 0, 0, 0x60040000 };
Battle D_800A64A0 = { 0, 0, 0x60040000 };
Battle D_800A64AC = { 0, 0, 0x60040000 };
BattleList D_800A64B8 = {
    0,
    { &D_800A6458, &D_800A6464, &D_800A6470, &D_800A647C,
      &D_800A6488, &D_800A6494, &D_800A64A0, &D_800A64AC },
};
Battle D_800A64DC = { 0, 0, 0x60040000 };
Battle D_800A64E8 = { 0, 0, 0x60040000 };
Battle D_800A64F4 = { 0, 0, 0x60040000 };
Battle D_800A6500 = { 0, 0, 0x60040000 };
Battle D_800A650C = { 0, 0, 0x60040000 };
Battle D_800A6518 = { 0, 0, 0x60040000 };
Battle D_800A6524 = { 0, 0, 0x60040000 };
Battle D_800A6530 = { 0, 0, 0x60040000 };
BattleList D_800A653C = {
    0,
    { &D_800A64DC, &D_800A64E8, &D_800A64F4, &D_800A6500,
      &D_800A650C, &D_800A6518, &D_800A6524, &D_800A6530 },
};
Battle D_800A6560 = { 0, 0, 0x60040000 };
Battle D_800A656C = { 0, 0, 0x60040000 };
Battle D_800A6578 = { 0, 0, 0x60040000 };
Battle D_800A6584 = { 0, 0, 0x60040000 };
Battle D_800A6590 = { 0, 0, 0x60040000 };
Battle D_800A659C = { 0, 0, 0x60040000 };
Battle D_800A65A8 = { 0, 0, 0x60040000 };
Battle D_800A65B4 = { 0, 0, 0x60040000 };
BattleList D_800A65C0 = {
    0,
    { &D_800A6560, &D_800A656C, &D_800A6578, &D_800A6584,
      &D_800A6590, &D_800A659C, &D_800A65A8, &D_800A65B4 },
};
Battle D_800A65E4 = { 61, 11, 0x60080000 };
Battle D_800A65F0 = { 61, 11, 0x60080000 };
Battle D_800A65FC = { 61, 11, 0x60080000 };
Battle D_800A6608 = { 61, 11, 0x60080000 };
Battle D_800A6614 = { 61, 11, 0x60080000 };
Battle D_800A6620 = { 61, 11, 0x60080000 };
Battle D_800A662C = { 159, 11, 0x60080000 };
Battle D_800A6638 = { 159, 11, 0x60080000 };
BattleList D_800A6644 = {
    5,
    { &D_800A65E4, &D_800A65F0, &D_800A65FC, &D_800A6608,
      &D_800A6614, &D_800A6620, &D_800A662C, &D_800A6638 },
};
Battle D_800A6668 = { 0, 0, 0x60040000 };
Battle D_800A6674 = { 0, 0, 0x60040000 };
Battle D_800A6680 = { 0, 0, 0x60040000 };
Battle D_800A668C = { 0, 0, 0x60040000 };
Battle D_800A6698 = { 0, 0, 0x60040000 };
Battle D_800A66A4 = { 0, 0, 0x60040000 };
Battle D_800A66B0 = { 0, 0, 0x60040000 };
Battle D_800A66BC = { 0, 0, 0x60040000 };
BattleList D_800A66C8 = {
    0,
    { &D_800A6668, &D_800A6674, &D_800A6680, &D_800A668C,
      &D_800A6698, &D_800A66A4, &D_800A66B0, &D_800A66BC },
};
Battle D_800A66EC = { 0, 0, 0x60040000 };
Battle D_800A66F8 = { 0, 0, 0x60040000 };
Battle D_800A6704 = { 0, 0, 0x60040000 };
Battle D_800A6710 = { 0, 0, 0x60040000 };
Battle D_800A671C = { 0, 0, 0x60040000 };
Battle D_800A6728 = { 0, 0, 0x60040000 };
Battle D_800A6734 = { 0, 0, 0x60040000 };
Battle D_800A6740 = { 0, 0, 0x60040000 };
BattleList D_800A674C = {
    0,
    { &D_800A66EC, &D_800A66F8, &D_800A6704, &D_800A6710,
      &D_800A671C, &D_800A6728, &D_800A6734, &D_800A6740 },
};
Battle D_800A6770 = { 0, 0, 0x60040000 };
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
Battle D_800A67C4 = { 0, 0, 0x60040000 };
BattleList D_800A67D0 = {
    0,
    { &D_800A6770, &D_800A677C, &D_800A6788, &D_800A6794,
      &D_800A67A0, &D_800A67AC, &D_800A67B8, &D_800A67C4 },
};
FieldBattles stageBattles[] = {
    { 396, 1, 0, { &D_800A6434, &D_800A64B8, &D_800A653C, &D_800A65C0 } },
    { 406, 4, 0, { &D_800A6644, &D_800A66C8, &D_800A674C, &D_800A67D0 } },
};
