#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x704;
    D_800990B4.sheetEntry = 0x9370004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x936;
    D_800990B4.start = (Vec2){0xE500, 0x16900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9370006);
    D_8009A70C.setFile(7, 0x9370007);
    D_8009A70C.setFile(4, 0x9370005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60FC;
extern StagePoint D_800A610C;
extern StagePoint D_800A6124;
extern StagePoint D_800A6134;
extern StagePoint D_800A614C;
extern StagePoint D_800A615C;
extern StagePoint D_800A6174;
extern StagePoint D_800A6184;
extern StagePoint D_800A619C;
extern StagePoint D_800A61AC;
extern StagePoint D_800A61C4;
extern StagePoint D_800A61D4;
extern StagePoint D_800A61EC;
extern StagePoint D_800A61FC;
extern StagePoint D_800A6214;
extern StagePoint D_800A6224;
extern StagePoint D_800A623C;
extern StagePoint D_800A624C;
extern StagePoints D_800A611C;
extern StagePoints D_800A6144;
extern StagePoints D_800A616C;
extern StagePoints D_800A6194;
extern StagePoints D_800A61BC;
extern StagePoints D_800A61E4;
extern StagePoints D_800A620C;
extern StagePoints D_800A6234;
extern StagePoints D_800A625C;
extern u16 D_800A632C[];
extern u16 D_800A6338[];
extern u16 D_800A6344[];
extern u16 D_800A6350[];
extern u16 D_800A6358[];
extern u16 D_800A6364[];
extern u16 D_800A636C[];
extern u16 D_800A637C[];
extern u16 D_800A638C[];
extern u16 D_800A639C[];
extern u16 D_800A63A4[];
extern u16 D_800A63B0[];
extern u16 D_800A63B8[];
extern u16 D_800A63C8[];
extern u16 D_800A63D8[];
extern u16 D_800A64A8[];
extern FieldTalk D_800A63E8[];
extern u16 D_800A64B8[];
extern FieldTalk D_800A6400[];
extern u16 D_800A64C8[];
extern FieldTalk D_800A6418[];
extern u16 D_800A64D8[];
extern FieldTalk D_800A6430[];
extern u16 D_800A64F4[];
extern FieldTalk D_800A646C[];
extern FieldActorEntry D_800A6510;
extern FieldActorEntry D_800A6524;
extern FieldActorEntry D_800A6538;
extern FieldActorEntry D_800A654C;
extern FieldActorEntry D_800A6560;
extern FieldActorEntry D_800A6574;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6740;
extern Battle D_800A674C;
extern Battle D_800A6758;
extern Battle D_800A6764;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67C4;
extern Battle D_800A67D0;
extern Battle D_800A67DC;
extern Battle D_800A67E8;
extern Battle D_800A6818;
extern Battle D_800A6824;
extern Battle D_800A6830;
extern Battle D_800A683C;
extern Battle D_800A6848;
extern Battle D_800A6854;
extern Battle D_800A6860;
extern Battle D_800A686C;
extern Battle D_800A689C;
extern Battle D_800A68A8;
extern Battle D_800A68B4;
extern Battle D_800A68C0;
extern Battle D_800A68CC;
extern Battle D_800A68D8;
extern Battle D_800A68E4;
extern Battle D_800A68F0;
extern Battle D_800A6920;
extern Battle D_800A692C;
extern Battle D_800A6938;
extern Battle D_800A6944;
extern Battle D_800A6950;
extern Battle D_800A695C;
extern Battle D_800A6968;
extern Battle D_800A6974;
extern Battle D_800A69A4;
extern Battle D_800A69B0;
extern Battle D_800A69BC;
extern Battle D_800A69C8;
extern Battle D_800A69D4;
extern Battle D_800A69E0;
extern Battle D_800A69EC;
extern Battle D_800A69F8;
extern Battle D_800A6A28;
extern Battle D_800A6A34;
extern Battle D_800A6A40;
extern Battle D_800A6A4C;
extern Battle D_800A6A58;
extern Battle D_800A6A64;
extern Battle D_800A6A70;
extern Battle D_800A6A7C;
extern Battle D_800A6AAC;
extern Battle D_800A6AB8;
extern Battle D_800A6AC4;
extern Battle D_800A6AD0;
extern Battle D_800A6ADC;
extern Battle D_800A6AE8;
extern Battle D_800A6AF4;
extern Battle D_800A6B00;
extern Battle D_800A6B30;
extern Battle D_800A6B3C;
extern Battle D_800A6B48;
extern Battle D_800A6B54;
extern Battle D_800A6B60;
extern Battle D_800A6B6C;
extern Battle D_800A6B78;
extern Battle D_800A6B84;
extern Battle D_800A6BB4;
extern Battle D_800A6BC0;
extern Battle D_800A6BCC;
extern Battle D_800A6BD8;
extern Battle D_800A6BE4;
extern Battle D_800A6BF0;
extern Battle D_800A6BFC;
extern Battle D_800A6C08;
extern Battle D_800A6C38;
extern Battle D_800A6C44;
extern Battle D_800A6C50;
extern Battle D_800A6C5C;
extern Battle D_800A6C68;
extern Battle D_800A6C74;
extern Battle D_800A6C80;
extern Battle D_800A6C8C;
extern Battle D_800A6CBC;
extern Battle D_800A6CC8;
extern Battle D_800A6CD4;
extern Battle D_800A6CE0;
extern Battle D_800A6CEC;
extern Battle D_800A6CF8;
extern Battle D_800A6D04;
extern Battle D_800A6D10;
extern Battle D_800A6D40;
extern Battle D_800A6D4C;
extern Battle D_800A6D58;
extern Battle D_800A6D64;
extern Battle D_800A6D70;
extern Battle D_800A6D7C;
extern Battle D_800A6D88;
extern Battle D_800A6D94;
extern Battle D_800A6DC4;
extern Battle D_800A6DD0;
extern Battle D_800A6DDC;
extern Battle D_800A6DE8;
extern Battle D_800A6DF4;
extern Battle D_800A6E00;
extern Battle D_800A6E0C;
extern Battle D_800A6E18;
extern Battle D_800A6E48;
extern Battle D_800A6E54;
extern Battle D_800A6E60;
extern Battle D_800A6E6C;
extern Battle D_800A6E78;
extern Battle D_800A6E84;
extern Battle D_800A6E90;
extern Battle D_800A6E9C;
extern Battle D_800A6ECC;
extern Battle D_800A6ED8;
extern Battle D_800A6EE4;
extern Battle D_800A6EF0;
extern Battle D_800A6EFC;
extern Battle D_800A6F08;
extern Battle D_800A6F14;
extern Battle D_800A6F20;
extern BattleList D_800A6770;
extern BattleList D_800A67F4;
extern BattleList D_800A6878;
extern BattleList D_800A68FC;
extern BattleList D_800A6980;
extern BattleList D_800A6A04;
extern BattleList D_800A6A88;
extern BattleList D_800A6B0C;
extern BattleList D_800A6B90;
extern BattleList D_800A6C14;
extern BattleList D_800A6C98;
extern BattleList D_800A6D1C;
extern BattleList D_800A6DA0;
extern BattleList D_800A6E24;
extern BattleList D_800A6EA8;
extern BattleList D_800A6F2C;

StagePoint D_800A60FC = { 0x2E6, 2, 2, 0x450, 0x248, 1, NULL };
StagePoint D_800A610C = { 0x2E6, 2, 1, 160, 0x150, 5, &D_800A60FC };
StagePoints D_800A611C = { 2, 1, &D_800A610C };
StagePoint D_800A6124 = { 0x2E4, 2, 3, 0x340, 160, 1, NULL };
StagePoint D_800A6134 = { 0x2E6, 2, 2, 160, 0x150, 5, &D_800A6124 };
StagePoints D_800A6144 = { 2, 2, &D_800A6134 };
StagePoint D_800A614C = { 0x2E6, 2, 3, 0x450, 0x248, 1, NULL };
StagePoint D_800A615C = { 0x2E4, 2, 2, 192, 0x180, 5, &D_800A614C };
StagePoints D_800A616C = { 2, 3, &D_800A615C };
StagePoint D_800A6174 = { 0x2E2, 2, 1, 0x330, 248, 1, NULL };
StagePoint D_800A6184 = { 0x2E6, 2, 3, 160, 0x150, 5, &D_800A6174 };
StagePoints D_800A6194 = { 2, 4, &D_800A6184 };
StagePoint D_800A619C = { 0x2E5, 3, 1, 0x3B0, 216, 1, NULL };
StagePoint D_800A61AC = { 0x2E0, 3, 1, 176, 0x178, 5, &D_800A619C };
StagePoints D_800A61BC = { 3, 1, &D_800A61AC };
StagePoint D_800A61C4 = { 0x2E7, 4, 1, 0x250, 232, 1, NULL };
StagePoint D_800A61D4 = { 0x2E6, 4, 1, 160, 0x150, 5, &D_800A61C4 };
StagePoints D_800A61E4 = { 4, 1, &D_800A61D4 };
StagePoint D_800A61EC = { 0x2E6, 5, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A61FC = { 0x2E0, 5, 1, 176, 0x178, 5, &D_800A61EC };
StagePoints D_800A620C = { 5, 1, &D_800A61FC };
StagePoint D_800A6214 = { 0x2E4, 5, 3, 0x340, 160, 1, NULL };
StagePoint D_800A6224 = { 0x2E6, 5, 1, 160, 0x150, 5, &D_800A6214 };
StagePoints D_800A6234 = { 5, 2, &D_800A6224 };
StagePoint D_800A623C = { 0x2E7, 5, 1, 0x250, 232, 1, NULL };
StagePoint D_800A624C = { 0x2E4, 5, 2, 192, 0x180, 5, &D_800A623C };
StagePoints D_800A625C = { 5, 3, &D_800A624C };
StagePoints *placePoints[] = {
    &D_800A611C, &D_800A6144, &D_800A616C, &D_800A6194,
    &D_800A61BC, &D_800A61E4, &D_800A620C, &D_800A6234,
    &D_800A625C, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x1A0, 0x28, 0xA0, 0x150, 0x1FF },
    { 0x180, 0x100, 0x1B0, 0x178, 0x1C0, 0x78, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1D0, 0xC0, 0xD0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x140, 0x1FE },
};
u16 D_800A632C[] = { 0x273, 1, 0x8234, 1, 0xFFFF };
u16 D_800A6338[] = { 0x26F, 1, 0x847D, 1, 0xFFFF };
u16 D_800A6344[] = { 0x270, 1, 0x848A, 1, 0xFFFF };
u16 D_800A6350[] = { 0x8676, 1, 0xFFFF };
u16 D_800A6358[] = { 0x8676, 0, 0, 0, 0xFFFF };
u16 D_800A6364[] = { 0, 1, 0xFFFF };
u16 D_800A636C[] = { 0x8676, 0, 0, 1, 0x8472, 0, 0xFFFF };
u16 D_800A637C[] = { 0x8676, 0, 0, 1, 0x8472, 1, 0xFFFF };
u16 D_800A638C[] = { 0x8676, 1, 0x8675, 0, 0x8472, 0, 0xFFFF };
u16 D_800A639C[] = { 0x869B, 1, 0xFFFF };
u16 D_800A63A4[] = { 0x869B, 0, 0, 0, 0xFFFF };
u16 D_800A63B0[] = { 0, 1, 0xFFFF };
u16 D_800A63B8[] = { 0x869B, 0, 0, 1, 0x8497, 0, 0xFFFF };
u16 D_800A63C8[] = { 0x869B, 0, 0, 1, 0x8497, 1, 0xFFFF };
u16 D_800A63D8[] = { 0x869B, 1, 0x869A, 0, 0x8497, 0, 0xFFFF };
FieldTalk D_800A63E8[] = {
    { NULL, D_800A632C, 0xB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6400[] = {
    { NULL, D_800A6338, 7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6418[] = {
    { NULL, D_800A6344, 8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6430[] = {
    { D_800A6350, NULL, 0xB1 },
    { D_800A6358, D_800A6364, 0xB2 },
    { D_800A636C, NULL, 0xB3 },
    { D_800A637C, D_800A638C, 0xB4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A646C[] = {
    { D_800A639C, NULL, 0xB5 },
    { D_800A63A4, D_800A63B0, 0xB6 },
    { D_800A63B8, NULL, 0xB7 },
    { D_800A63C8, D_800A63D8, 0xB8 },
    { NULL, NULL, 0 },
};
u16 D_800A64A8[] = { 0x7E01, 1, 0x7E1E, 1, 0x273, 0, 0xFFFF };
u16 D_800A64B8[] = { 0x7E01, 1, 0x7E21, 1, 0x26F, 0, 0xFFFF };
u16 D_800A64C8[] = { 0x7E04, 1, 0x7E1E, 1, 0x270, 0, 0xFFFF };
u16 D_800A64D8[] = {
    0x7E01, 1, 0x7E1F, 1, 0x7055, 1, 0x7095, 1,
    0x8675, 1, 0x8676, 0, 0xFFFF,
};
u16 D_800A64F4[] = {
    0x7E03, 1, 0x7E1E, 1, 0x7055, 1, 0x7095, 1,
    0x869A, 1, 0x869B, 0, 0xFFFF,
};
FieldActorEntry D_800A6510 = { D_800A64A8, D_800A63E8, 0x21, 4, 544, 240, 1 };
FieldActorEntry D_800A6524 = { D_800A64B8, D_800A6400, 0x21, 4, 544, 240, 1 };
FieldActorEntry D_800A6538 = { D_800A64C8, D_800A6418, 0x21, 4, 544, 240, 1 };
FieldActorEntry D_800A654C = { D_800A64D8, D_800A6430, 0xA8, 5, 544, 240, 1 };
FieldActorEntry D_800A6560 = { D_800A64F4, D_800A646C, 0xAA, 6, 544, 240, 1 };
FieldActorEntry D_800A6574 = { NULL, NULL, 0x147, 7, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A6510,
    &D_800A6524,
    &D_800A6538,
    &D_800A654C,
    &D_800A6560,
    &D_800A6574,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 200, 265, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 560, 185, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 857, 33, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 395, 180, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 500, 39, 0, 0 },
    { 1, 0, 0xB6, 6, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 659, 0, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 176, 128, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 758, 41, 0, 0 },
    { 1, 0, 0x8A, 4, 3, 0, 0, 0, 0, 0, 416, 191, 327, 0 },
    { 1, 0, 0x52, 4, 4, 0, 0, 0, 0, 0, 384, 174, 311, 0 },
    { 1, 0, 0x83, 4, 5, 0, 0, 0, 0, 0, 352, 169, 295, 0 },
    { 1, 0, 0x8E, 4, 6, 0, 0, 0, 0, 0, 320, 154, 279, 0 },
    { 1, 0, 0x54, 4, 8, 0, 0, 0, 0, 0, 672, 177, 268, 0 },
    { 1, 0, 0x66, 4, 9, 0, 0, 0, 0, 0, 640, 162, 251, 0 },
    { 1, 0, 0x60, 4, 0xA, 0, 0, 0, 0, 0, 624, 156, 242, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E4, 0x340, 0xA0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E4, 0xC0, 0x180, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6710 = { 62, 11, 0x60080000 };
Battle D_800A671C = { 62, 11, 0x60080000 };
Battle D_800A6728 = { 62, 11, 0x60080000 };
Battle D_800A6734 = { 106, 11, 0x60080000 };
Battle D_800A6740 = { 106, 11, 0x60080000 };
Battle D_800A674C = { 106, 11, 0x60080000 };
Battle D_800A6758 = { 276, 11, 0x60080000 };
Battle D_800A6764 = { 276, 11, 0x60080000 };
BattleList D_800A6770 = {
    3,
    { &D_800A6710, &D_800A671C, &D_800A6728, &D_800A6734,
      &D_800A6740, &D_800A674C, &D_800A6758, &D_800A6764 },
};
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
Battle D_800A67C4 = { 0, 0, 0x60040000 };
Battle D_800A67D0 = { 0, 0, 0x60040000 };
Battle D_800A67DC = { 0, 0, 0x60040000 };
Battle D_800A67E8 = { 0, 0, 0x60040000 };
BattleList D_800A67F4 = {
    0,
    { &D_800A6794, &D_800A67A0, &D_800A67AC, &D_800A67B8,
      &D_800A67C4, &D_800A67D0, &D_800A67DC, &D_800A67E8 },
};
Battle D_800A6818 = { 0, 0, 0x60040000 };
Battle D_800A6824 = { 0, 0, 0x60040000 };
Battle D_800A6830 = { 0, 0, 0x60040000 };
Battle D_800A683C = { 0, 0, 0x60040000 };
Battle D_800A6848 = { 0, 0, 0x60040000 };
Battle D_800A6854 = { 0, 0, 0x60040000 };
Battle D_800A6860 = { 0, 0, 0x60040000 };
Battle D_800A686C = { 0, 0, 0x60040000 };
BattleList D_800A6878 = {
    0,
    { &D_800A6818, &D_800A6824, &D_800A6830, &D_800A683C,
      &D_800A6848, &D_800A6854, &D_800A6860, &D_800A686C },
};
Battle D_800A689C = { 0, 0, 0x60040000 };
Battle D_800A68A8 = { 0, 0, 0x60040000 };
Battle D_800A68B4 = { 0, 0, 0x60040000 };
Battle D_800A68C0 = { 0, 0, 0x60040000 };
Battle D_800A68CC = { 0, 0, 0x60040000 };
Battle D_800A68D8 = { 0, 0, 0x60040000 };
Battle D_800A68E4 = { 0, 0, 0x60040000 };
Battle D_800A68F0 = { 0, 0, 0x60040000 };
BattleList D_800A68FC = {
    0,
    { &D_800A689C, &D_800A68A8, &D_800A68B4, &D_800A68C0,
      &D_800A68CC, &D_800A68D8, &D_800A68E4, &D_800A68F0 },
};
Battle D_800A6920 = { 64, 11, 0x60080000 };
Battle D_800A692C = { 64, 11, 0x60080000 };
Battle D_800A6938 = { 64, 11, 0x60080000 };
Battle D_800A6944 = { 64, 11, 0x60080000 };
Battle D_800A6950 = { 64, 11, 0x60080000 };
Battle D_800A695C = { 64, 11, 0x60080000 };
Battle D_800A6968 = { 64, 11, 0x60080000 };
Battle D_800A6974 = { 64, 11, 0x60080000 };
BattleList D_800A6980 = {
    3,
    { &D_800A6920, &D_800A692C, &D_800A6938, &D_800A6944,
      &D_800A6950, &D_800A695C, &D_800A6968, &D_800A6974 },
};
Battle D_800A69A4 = { 0, 0, 0x60040000 };
Battle D_800A69B0 = { 0, 0, 0x60040000 };
Battle D_800A69BC = { 0, 0, 0x60040000 };
Battle D_800A69C8 = { 0, 0, 0x60040000 };
Battle D_800A69D4 = { 0, 0, 0x60040000 };
Battle D_800A69E0 = { 0, 0, 0x60040000 };
Battle D_800A69EC = { 0, 0, 0x60040000 };
Battle D_800A69F8 = { 0, 0, 0x60040000 };
BattleList D_800A6A04 = {
    0,
    { &D_800A69A4, &D_800A69B0, &D_800A69BC, &D_800A69C8,
      &D_800A69D4, &D_800A69E0, &D_800A69EC, &D_800A69F8 },
};
Battle D_800A6A28 = { 0, 0, 0x60040000 };
Battle D_800A6A34 = { 0, 0, 0x60040000 };
Battle D_800A6A40 = { 0, 0, 0x60040000 };
Battle D_800A6A4C = { 0, 0, 0x60040000 };
Battle D_800A6A58 = { 0, 0, 0x60040000 };
Battle D_800A6A64 = { 0, 0, 0x60040000 };
Battle D_800A6A70 = { 0, 0, 0x60040000 };
Battle D_800A6A7C = { 0, 0, 0x60040000 };
BattleList D_800A6A88 = {
    0,
    { &D_800A6A28, &D_800A6A34, &D_800A6A40, &D_800A6A4C,
      &D_800A6A58, &D_800A6A64, &D_800A6A70, &D_800A6A7C },
};
Battle D_800A6AAC = { 0, 0, 0x60040000 };
Battle D_800A6AB8 = { 0, 0, 0x60040000 };
Battle D_800A6AC4 = { 0, 0, 0x60040000 };
Battle D_800A6AD0 = { 0, 0, 0x60040000 };
Battle D_800A6ADC = { 0, 0, 0x60040000 };
Battle D_800A6AE8 = { 0, 0, 0x60040000 };
Battle D_800A6AF4 = { 0, 0, 0x60040000 };
Battle D_800A6B00 = { 0, 0, 0x60040000 };
BattleList D_800A6B0C = {
    0,
    { &D_800A6AAC, &D_800A6AB8, &D_800A6AC4, &D_800A6AD0,
      &D_800A6ADC, &D_800A6AE8, &D_800A6AF4, &D_800A6B00 },
};
Battle D_800A6B30 = { 159, 11, 0x60080000 };
Battle D_800A6B3C = { 159, 11, 0x60080000 };
Battle D_800A6B48 = { 159, 11, 0x60080000 };
Battle D_800A6B54 = { 159, 11, 0x60080000 };
Battle D_800A6B60 = { 159, 11, 0x60080000 };
Battle D_800A6B6C = { 159, 11, 0x60080000 };
Battle D_800A6B78 = { 159, 11, 0x60080000 };
Battle D_800A6B84 = { 159, 11, 0x60080000 };
BattleList D_800A6B90 = {
    5,
    { &D_800A6B30, &D_800A6B3C, &D_800A6B48, &D_800A6B54,
      &D_800A6B60, &D_800A6B6C, &D_800A6B78, &D_800A6B84 },
};
Battle D_800A6BB4 = { 0, 0, 0x60040000 };
Battle D_800A6BC0 = { 0, 0, 0x60040000 };
Battle D_800A6BCC = { 0, 0, 0x60040000 };
Battle D_800A6BD8 = { 0, 0, 0x60040000 };
Battle D_800A6BE4 = { 0, 0, 0x60040000 };
Battle D_800A6BF0 = { 0, 0, 0x60040000 };
Battle D_800A6BFC = { 0, 0, 0x60040000 };
Battle D_800A6C08 = { 0, 0, 0x60040000 };
BattleList D_800A6C14 = {
    0,
    { &D_800A6BB4, &D_800A6BC0, &D_800A6BCC, &D_800A6BD8,
      &D_800A6BE4, &D_800A6BF0, &D_800A6BFC, &D_800A6C08 },
};
Battle D_800A6C38 = { 0, 0, 0x60040000 };
Battle D_800A6C44 = { 0, 0, 0x60040000 };
Battle D_800A6C50 = { 0, 0, 0x60040000 };
Battle D_800A6C5C = { 0, 0, 0x60040000 };
Battle D_800A6C68 = { 0, 0, 0x60040000 };
Battle D_800A6C74 = { 0, 0, 0x60040000 };
Battle D_800A6C80 = { 0, 0, 0x60040000 };
Battle D_800A6C8C = { 0, 0, 0x60040000 };
BattleList D_800A6C98 = {
    0,
    { &D_800A6C38, &D_800A6C44, &D_800A6C50, &D_800A6C5C,
      &D_800A6C68, &D_800A6C74, &D_800A6C80, &D_800A6C8C },
};
Battle D_800A6CBC = { 0, 0, 0x60040000 };
Battle D_800A6CC8 = { 0, 0, 0x60040000 };
Battle D_800A6CD4 = { 0, 0, 0x60040000 };
Battle D_800A6CE0 = { 0, 0, 0x60040000 };
Battle D_800A6CEC = { 0, 0, 0x60040000 };
Battle D_800A6CF8 = { 0, 0, 0x60040000 };
Battle D_800A6D04 = { 0, 0, 0x60040000 };
Battle D_800A6D10 = { 0, 0, 0x60040000 };
BattleList D_800A6D1C = {
    0,
    { &D_800A6CBC, &D_800A6CC8, &D_800A6CD4, &D_800A6CE0,
      &D_800A6CEC, &D_800A6CF8, &D_800A6D04, &D_800A6D10 },
};
Battle D_800A6D40 = { 63, 11, 0x60080000 };
Battle D_800A6D4C = { 63, 11, 0x60080000 };
Battle D_800A6D58 = { 63, 11, 0x60080000 };
Battle D_800A6D64 = { 104, 11, 0x60080000 };
Battle D_800A6D70 = { 104, 11, 0x60080000 };
Battle D_800A6D7C = { 104, 11, 0x60080000 };
Battle D_800A6D88 = { 104, 11, 0x60080000 };
Battle D_800A6D94 = { 104, 11, 0x60080000 };
BattleList D_800A6DA0 = {
    4,
    { &D_800A6D40, &D_800A6D4C, &D_800A6D58, &D_800A6D64,
      &D_800A6D70, &D_800A6D7C, &D_800A6D88, &D_800A6D94 },
};
Battle D_800A6DC4 = { 0, 0, 0x60040000 };
Battle D_800A6DD0 = { 0, 0, 0x60040000 };
Battle D_800A6DDC = { 0, 0, 0x60040000 };
Battle D_800A6DE8 = { 0, 0, 0x60040000 };
Battle D_800A6DF4 = { 0, 0, 0x60040000 };
Battle D_800A6E00 = { 0, 0, 0x60040000 };
Battle D_800A6E0C = { 0, 0, 0x60040000 };
Battle D_800A6E18 = { 0, 0, 0x60040000 };
BattleList D_800A6E24 = {
    0,
    { &D_800A6DC4, &D_800A6DD0, &D_800A6DDC, &D_800A6DE8,
      &D_800A6DF4, &D_800A6E00, &D_800A6E0C, &D_800A6E18 },
};
Battle D_800A6E48 = { 0, 0, 0x60040000 };
Battle D_800A6E54 = { 0, 0, 0x60040000 };
Battle D_800A6E60 = { 0, 0, 0x60040000 };
Battle D_800A6E6C = { 0, 0, 0x60040000 };
Battle D_800A6E78 = { 0, 0, 0x60040000 };
Battle D_800A6E84 = { 0, 0, 0x60040000 };
Battle D_800A6E90 = { 0, 0, 0x60040000 };
Battle D_800A6E9C = { 0, 0, 0x60040000 };
BattleList D_800A6EA8 = {
    0,
    { &D_800A6E48, &D_800A6E54, &D_800A6E60, &D_800A6E6C,
      &D_800A6E78, &D_800A6E84, &D_800A6E90, &D_800A6E9C },
};
Battle D_800A6ECC = { 0, 0, 0x60040000 };
Battle D_800A6ED8 = { 0, 0, 0x60040000 };
Battle D_800A6EE4 = { 0, 0, 0x60040000 };
Battle D_800A6EF0 = { 0, 0, 0x60040000 };
Battle D_800A6EFC = { 0, 0, 0x60040000 };
Battle D_800A6F08 = { 0, 0, 0x60040000 };
Battle D_800A6F14 = { 0, 0, 0x60040000 };
Battle D_800A6F20 = { 0, 0, 0x60040000 };
BattleList D_800A6F2C = {
    0,
    { &D_800A6ECC, &D_800A6ED8, &D_800A6EE4, &D_800A6EF0,
      &D_800A6EFC, &D_800A6F08, &D_800A6F14, &D_800A6F20 },
};
FieldBattles stageBattles[] = {
    { 399, 2, 0, { &D_800A6770, &D_800A67F4, &D_800A6878, &D_800A68FC } },
    { 402, 3, 0, { &D_800A6980, &D_800A6A04, &D_800A6A88, &D_800A6B0C } },
    { 407, 4, 0, { &D_800A6B90, &D_800A6C14, &D_800A6C98, &D_800A6D1C } },
    { 411, 5, 0, { &D_800A6DA0, &D_800A6E24, &D_800A6EA8, &D_800A6F2C } },
};
