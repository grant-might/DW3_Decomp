#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6F0;
    D_800990B4.sheetEntry = 0x93B0004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x93A;
    D_800990B4.start = (Vec2){0x13300, 0x13B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x93B0006);
    D_8009A70C.setFile(7, 0x93B0007);
    D_8009A70C.setFile(4, 0x93B0005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A6100;
extern StagePoint D_800A6110;
extern StagePoint D_800A6128;
extern StagePoint D_800A6138;
extern StagePoint D_800A6150;
extern StagePoint D_800A6160;
extern StagePoint D_800A6178;
extern StagePoint D_800A6188;
extern StagePoint D_800A61A0;
extern StagePoint D_800A61B0;
extern StagePoint D_800A61C8;
extern StagePoint D_800A61D8;
extern StagePoints D_800A6120;
extern StagePoints D_800A6148;
extern StagePoints D_800A6170;
extern StagePoints D_800A6198;
extern StagePoints D_800A61C0;
extern StagePoints D_800A61E8;
extern FieldActorEntry D_800A627C;
extern Battle D_800A655C;
extern Battle D_800A6568;
extern Battle D_800A6574;
extern Battle D_800A6580;
extern Battle D_800A658C;
extern Battle D_800A6598;
extern Battle D_800A65A4;
extern Battle D_800A65B0;
extern Battle D_800A65E0;
extern Battle D_800A65EC;
extern Battle D_800A65F8;
extern Battle D_800A6604;
extern Battle D_800A6610;
extern Battle D_800A661C;
extern Battle D_800A6628;
extern Battle D_800A6634;
extern Battle D_800A6664;
extern Battle D_800A6670;
extern Battle D_800A667C;
extern Battle D_800A6688;
extern Battle D_800A6694;
extern Battle D_800A66A0;
extern Battle D_800A66AC;
extern Battle D_800A66B8;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6700;
extern Battle D_800A670C;
extern Battle D_800A6718;
extern Battle D_800A6724;
extern Battle D_800A6730;
extern Battle D_800A673C;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A6784;
extern Battle D_800A6790;
extern Battle D_800A679C;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A6808;
extern Battle D_800A6814;
extern Battle D_800A6820;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern Battle D_800A688C;
extern Battle D_800A6898;
extern Battle D_800A68A4;
extern Battle D_800A68B0;
extern Battle D_800A68BC;
extern Battle D_800A68C8;
extern Battle D_800A68F8;
extern Battle D_800A6904;
extern Battle D_800A6910;
extern Battle D_800A691C;
extern Battle D_800A6928;
extern Battle D_800A6934;
extern Battle D_800A6940;
extern Battle D_800A694C;
extern Battle D_800A697C;
extern Battle D_800A6988;
extern Battle D_800A6994;
extern Battle D_800A69A0;
extern Battle D_800A69AC;
extern Battle D_800A69B8;
extern Battle D_800A69C4;
extern Battle D_800A69D0;
extern Battle D_800A6A00;
extern Battle D_800A6A0C;
extern Battle D_800A6A18;
extern Battle D_800A6A24;
extern Battle D_800A6A30;
extern Battle D_800A6A3C;
extern Battle D_800A6A48;
extern Battle D_800A6A54;
extern Battle D_800A6A84;
extern Battle D_800A6A90;
extern Battle D_800A6A9C;
extern Battle D_800A6AA8;
extern Battle D_800A6AB4;
extern Battle D_800A6AC0;
extern Battle D_800A6ACC;
extern Battle D_800A6AD8;
extern Battle D_800A6B08;
extern Battle D_800A6B14;
extern Battle D_800A6B20;
extern Battle D_800A6B2C;
extern Battle D_800A6B38;
extern Battle D_800A6B44;
extern Battle D_800A6B50;
extern Battle D_800A6B5C;
extern Battle D_800A6B8C;
extern Battle D_800A6B98;
extern Battle D_800A6BA4;
extern Battle D_800A6BB0;
extern Battle D_800A6BBC;
extern Battle D_800A6BC8;
extern Battle D_800A6BD4;
extern Battle D_800A6BE0;
extern Battle D_800A6C10;
extern Battle D_800A6C1C;
extern Battle D_800A6C28;
extern Battle D_800A6C34;
extern Battle D_800A6C40;
extern Battle D_800A6C4C;
extern Battle D_800A6C58;
extern Battle D_800A6C64;
extern Battle D_800A6C94;
extern Battle D_800A6CA0;
extern Battle D_800A6CAC;
extern Battle D_800A6CB8;
extern Battle D_800A6CC4;
extern Battle D_800A6CD0;
extern Battle D_800A6CDC;
extern Battle D_800A6CE8;
extern Battle D_800A6D18;
extern Battle D_800A6D24;
extern Battle D_800A6D30;
extern Battle D_800A6D3C;
extern Battle D_800A6D48;
extern Battle D_800A6D54;
extern Battle D_800A6D60;
extern Battle D_800A6D6C;
extern BattleList D_800A65BC;
extern BattleList D_800A6640;
extern BattleList D_800A66C4;
extern BattleList D_800A6748;
extern BattleList D_800A67CC;
extern BattleList D_800A6850;
extern BattleList D_800A68D4;
extern BattleList D_800A6958;
extern BattleList D_800A69DC;
extern BattleList D_800A6A60;
extern BattleList D_800A6AE4;
extern BattleList D_800A6B68;
extern BattleList D_800A6BEC;
extern BattleList D_800A6C70;
extern BattleList D_800A6CF4;
extern BattleList D_800A6D78;

StagePoint D_800A6100 = { 0x2E4, 2, 1, 0x340, 160, 1, NULL };
StagePoint D_800A6110 = { 0x2E0, 2, 1, 176, 0x178, 5, &D_800A6100 };
StagePoints D_800A6120 = { 2, 1, &D_800A6110 };
StagePoint D_800A6128 = { 0x2E4, 2, 2, 0x340, 160, 1, NULL };
StagePoint D_800A6138 = { 0x2E4, 2, 1, 192, 0x180, 5, &D_800A6128 };
StagePoints D_800A6148 = { 2, 2, &D_800A6138 };
StagePoint D_800A6150 = { 0x2E4, 2, 4, 0x340, 160, 1, NULL };
StagePoint D_800A6160 = { 0x2E4, 2, 3, 192, 0x180, 5, &D_800A6150 };
StagePoints D_800A6170 = { 2, 3, &D_800A6160 };
StagePoint D_800A6178 = { 0x2E7, 3, 1, 0x250, 232, 1, NULL };
StagePoint D_800A6188 = { 0x2E5, 3, 1, 224, 0x120, 5, &D_800A6178 };
StagePoints D_800A6198 = { 3, 1, &D_800A6188 };
StagePoint D_800A61A0 = { 0x2E4, 4, 1, 0x340, 160, 1, NULL };
StagePoint D_800A61B0 = { 0x2E3, 4, 1, 160, 0x180, 5, &D_800A61A0 };
StagePoints D_800A61C0 = { 4, 1, &D_800A61B0 };
StagePoint D_800A61C8 = { 0x2E4, 5, 2, 0x340, 160, 1, NULL };
StagePoint D_800A61D8 = { 0x2E4, 5, 1, 192, 0x180, 5, &D_800A61C8 };
StagePoints D_800A61E8 = { 5, 1, &D_800A61D8 };
StagePoints *placePoints[] = {
    &D_800A6120, &D_800A6148, &D_800A6170, &D_800A6198,
    &D_800A61C0, &D_800A61E8, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1BC, 0xC0, 0xBC, 0x150, 0x1FF },
};
FieldActorEntry D_800A627C = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A627C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 155, 230, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 440, 261, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 797, 447, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 1127, 463, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 312, 203, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 657, 342, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 916, 467, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 768, 289, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 215, 158, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 591, 261, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 983, 460, 0, 0 },
    { 1, 0, 0x50, 4, 0, 0, 0, 0, 0, 0, 192, 257, 340, 0 },
    { 1, 0, 0x65, 4, 1, 0, 0, 0, 0, 0, 160, 241, 334, 0 },
    { 1, 0, 0x5E, 4, 2, 0, 0, 0, 0, 0, 144, 237, 324, 0 },
    { 1, 0, 0x91, 4, 3, 0, 0, 0, 0, 0, 368, 184, 306, 0 },
    { 1, 0, 0x77, 4, 4, 0, 0, 0, 0, 0, 336, 204, 322, 0 },
    { 1, 0, 0x89, 4, 5, 0, 0, 0, 0, 0, 304, 218, 347, 0 },
    { 1, 0, 0x82, 4, 6, 0, 0, 0, 0, 0, 272, 238, 354, 0 },
    { 1, 0, 0x5E, 4, 7, 0, 0, 0, 0, 0, 464, 278, 368, 0 },
    { 1, 0, 0x66, 4, 8, 0, 0, 0, 0, 0, 432, 283, 375, 0 },
    { 1, 0, 0x52, 4, 9, 0, 0, 0, 0, 0, 414, 298, 380, 0 },
    { 1, 0, 0x51, 4, 0xA, 0, 0, 0, 0, 0, 544, 316, 390, 0 },
    { 1, 0, 0x60, 4, 0xB, 0, 0, 0, 0, 0, 512, 320, 405, 0 },
    { 1, 0, 0x52, 4, 0xC, 0, 0, 0, 0, 0, 494, 336, 415, 0 },
    { 1, 0, 0x93, 4, 0xD, 0, 0, 0, 0, 0, 720, 311, 435, 0 },
    { 1, 0, 0x79, 4, 0xE, 0, 0, 0, 0, 0, 688, 331, 451, 0 },
    { 1, 0, 0x8B, 4, 0xF, 0, 0, 0, 0, 0, 656, 345, 476, 0 },
    { 1, 0, 0x89, 4, 0x10, 0, 0, 0, 0, 0, 624, 360, 483, 0 },
    { 1, 0, 0x5D, 4, 0x11, 0, 0, 0, 0, 0, 752, 421, 506, 0 },
    { 1, 0, 0x67, 4, 0x12, 0, 0, 0, 0, 0, 720, 424, 515, 0 },
    { 1, 0, 0x50, 4, 0x13, 0, 0, 0, 0, 0, 702, 441, 527, 0 },
    { 1, 0, 0x52, 4, 0x14, 0, 0, 0, 0, 0, 1104, 521, 606, 0 },
    { 1, 0, 0x65, 4, 0x15, 0, 0, 0, 0, 0, 1072, 505, 598, 0 },
    { 1, 0, 0x5D, 4, 0x16, 0, 0, 0, 0, 0, 1057, 501, 587, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E6, 0x450, 0x248, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E6, 0xA0, 0x150, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A655C = { 62, 11, 0x60080000 };
Battle D_800A6568 = { 62, 11, 0x60080000 };
Battle D_800A6574 = { 62, 11, 0x60080000 };
Battle D_800A6580 = { 62, 11, 0x60080000 };
Battle D_800A658C = { 106, 11, 0x60080000 };
Battle D_800A6598 = { 106, 11, 0x60080000 };
Battle D_800A65A4 = { 106, 11, 0x60080000 };
Battle D_800A65B0 = { 106, 11, 0x60080000 };
BattleList D_800A65BC = {
    3,
    { &D_800A655C, &D_800A6568, &D_800A6574, &D_800A6580,
      &D_800A658C, &D_800A6598, &D_800A65A4, &D_800A65B0 },
};
Battle D_800A65E0 = { 0, 0, 0x60040000 };
Battle D_800A65EC = { 0, 0, 0x60040000 };
Battle D_800A65F8 = { 0, 0, 0x60040000 };
Battle D_800A6604 = { 0, 0, 0x60040000 };
Battle D_800A6610 = { 0, 0, 0x60040000 };
Battle D_800A661C = { 0, 0, 0x60040000 };
Battle D_800A6628 = { 0, 0, 0x60040000 };
Battle D_800A6634 = { 0, 0, 0x60040000 };
BattleList D_800A6640 = {
    0,
    { &D_800A65E0, &D_800A65EC, &D_800A65F8, &D_800A6604,
      &D_800A6610, &D_800A661C, &D_800A6628, &D_800A6634 },
};
Battle D_800A6664 = { 0, 0, 0x60040000 };
Battle D_800A6670 = { 0, 0, 0x60040000 };
Battle D_800A667C = { 0, 0, 0x60040000 };
Battle D_800A6688 = { 0, 0, 0x60040000 };
Battle D_800A6694 = { 0, 0, 0x60040000 };
Battle D_800A66A0 = { 0, 0, 0x60040000 };
Battle D_800A66AC = { 0, 0, 0x60040000 };
Battle D_800A66B8 = { 0, 0, 0x60040000 };
BattleList D_800A66C4 = {
    0,
    { &D_800A6664, &D_800A6670, &D_800A667C, &D_800A6688,
      &D_800A6694, &D_800A66A0, &D_800A66AC, &D_800A66B8 },
};
Battle D_800A66E8 = { 0, 0, 0x60040000 };
Battle D_800A66F4 = { 0, 0, 0x60040000 };
Battle D_800A6700 = { 0, 0, 0x60040000 };
Battle D_800A670C = { 0, 0, 0x60040000 };
Battle D_800A6718 = { 0, 0, 0x60040000 };
Battle D_800A6724 = { 0, 0, 0x60040000 };
Battle D_800A6730 = { 0, 0, 0x60040000 };
Battle D_800A673C = { 0, 0, 0x60040000 };
BattleList D_800A6748 = {
    0,
    { &D_800A66E8, &D_800A66F4, &D_800A6700, &D_800A670C,
      &D_800A6718, &D_800A6724, &D_800A6730, &D_800A673C },
};
Battle D_800A676C = { 105, 11, 0x60080000 };
Battle D_800A6778 = { 105, 11, 0x60080000 };
Battle D_800A6784 = { 105, 11, 0x60080000 };
Battle D_800A6790 = { 105, 11, 0x60080000 };
Battle D_800A679C = { 105, 11, 0x60080000 };
Battle D_800A67A8 = { 105, 11, 0x60080000 };
Battle D_800A67B4 = { 105, 11, 0x60080000 };
Battle D_800A67C0 = { 105, 11, 0x60080000 };
BattleList D_800A67CC = {
    5,
    { &D_800A676C, &D_800A6778, &D_800A6784, &D_800A6790,
      &D_800A679C, &D_800A67A8, &D_800A67B4, &D_800A67C0 },
};
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
Battle D_800A6808 = { 0, 0, 0x60040000 };
Battle D_800A6814 = { 0, 0, 0x60040000 };
Battle D_800A6820 = { 0, 0, 0x60040000 };
Battle D_800A682C = { 0, 0, 0x60040000 };
Battle D_800A6838 = { 0, 0, 0x60040000 };
Battle D_800A6844 = { 0, 0, 0x60040000 };
BattleList D_800A6850 = {
    0,
    { &D_800A67F0, &D_800A67FC, &D_800A6808, &D_800A6814,
      &D_800A6820, &D_800A682C, &D_800A6838, &D_800A6844 },
};
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 0, 0, 0x60040000 };
Battle D_800A688C = { 0, 0, 0x60040000 };
Battle D_800A6898 = { 0, 0, 0x60040000 };
Battle D_800A68A4 = { 0, 0, 0x60040000 };
Battle D_800A68B0 = { 0, 0, 0x60040000 };
Battle D_800A68BC = { 0, 0, 0x60040000 };
Battle D_800A68C8 = { 0, 0, 0x60040000 };
BattleList D_800A68D4 = {
    0,
    { &D_800A6874, &D_800A6880, &D_800A688C, &D_800A6898,
      &D_800A68A4, &D_800A68B0, &D_800A68BC, &D_800A68C8 },
};
Battle D_800A68F8 = { 0, 0, 0x60040000 };
Battle D_800A6904 = { 0, 0, 0x60040000 };
Battle D_800A6910 = { 0, 0, 0x60040000 };
Battle D_800A691C = { 0, 0, 0x60040000 };
Battle D_800A6928 = { 0, 0, 0x60040000 };
Battle D_800A6934 = { 0, 0, 0x60040000 };
Battle D_800A6940 = { 0, 0, 0x60040000 };
Battle D_800A694C = { 0, 0, 0x60040000 };
BattleList D_800A6958 = {
    0,
    { &D_800A68F8, &D_800A6904, &D_800A6910, &D_800A691C,
      &D_800A6928, &D_800A6934, &D_800A6940, &D_800A694C },
};
Battle D_800A697C = { 61, 11, 0x60080000 };
Battle D_800A6988 = { 61, 11, 0x60080000 };
Battle D_800A6994 = { 159, 11, 0x60080000 };
Battle D_800A69A0 = { 159, 11, 0x60080000 };
Battle D_800A69AC = { 159, 11, 0x60080000 };
Battle D_800A69B8 = { 159, 11, 0x60080000 };
Battle D_800A69C4 = { 159, 11, 0x60080000 };
Battle D_800A69D0 = { 159, 11, 0x60080000 };
BattleList D_800A69DC = {
    5,
    { &D_800A697C, &D_800A6988, &D_800A6994, &D_800A69A0,
      &D_800A69AC, &D_800A69B8, &D_800A69C4, &D_800A69D0 },
};
Battle D_800A6A00 = { 0, 0, 0x60040000 };
Battle D_800A6A0C = { 0, 0, 0x60040000 };
Battle D_800A6A18 = { 0, 0, 0x60040000 };
Battle D_800A6A24 = { 0, 0, 0x60040000 };
Battle D_800A6A30 = { 0, 0, 0x60040000 };
Battle D_800A6A3C = { 0, 0, 0x60040000 };
Battle D_800A6A48 = { 0, 0, 0x60040000 };
Battle D_800A6A54 = { 0, 0, 0x60040000 };
BattleList D_800A6A60 = {
    0,
    { &D_800A6A00, &D_800A6A0C, &D_800A6A18, &D_800A6A24,
      &D_800A6A30, &D_800A6A3C, &D_800A6A48, &D_800A6A54 },
};
Battle D_800A6A84 = { 0, 0, 0x60040000 };
Battle D_800A6A90 = { 0, 0, 0x60040000 };
Battle D_800A6A9C = { 0, 0, 0x60040000 };
Battle D_800A6AA8 = { 0, 0, 0x60040000 };
Battle D_800A6AB4 = { 0, 0, 0x60040000 };
Battle D_800A6AC0 = { 0, 0, 0x60040000 };
Battle D_800A6ACC = { 0, 0, 0x60040000 };
Battle D_800A6AD8 = { 0, 0, 0x60040000 };
BattleList D_800A6AE4 = {
    0,
    { &D_800A6A84, &D_800A6A90, &D_800A6A9C, &D_800A6AA8,
      &D_800A6AB4, &D_800A6AC0, &D_800A6ACC, &D_800A6AD8 },
};
Battle D_800A6B08 = { 0, 0, 0x60040000 };
Battle D_800A6B14 = { 0, 0, 0x60040000 };
Battle D_800A6B20 = { 0, 0, 0x60040000 };
Battle D_800A6B2C = { 0, 0, 0x60040000 };
Battle D_800A6B38 = { 0, 0, 0x60040000 };
Battle D_800A6B44 = { 0, 0, 0x60040000 };
Battle D_800A6B50 = { 0, 0, 0x60040000 };
Battle D_800A6B5C = { 0, 0, 0x60040000 };
BattleList D_800A6B68 = {
    0,
    { &D_800A6B08, &D_800A6B14, &D_800A6B20, &D_800A6B2C,
      &D_800A6B38, &D_800A6B44, &D_800A6B50, &D_800A6B5C },
};
Battle D_800A6B8C = { 185, 11, 0x60080000 };
Battle D_800A6B98 = { 185, 11, 0x60080000 };
Battle D_800A6BA4 = { 185, 11, 0x60080000 };
Battle D_800A6BB0 = { 185, 11, 0x60080000 };
Battle D_800A6BBC = { 185, 11, 0x60080000 };
Battle D_800A6BC8 = { 178, 11, 0x60080000 };
Battle D_800A6BD4 = { 178, 11, 0x60080000 };
Battle D_800A6BE0 = { 178, 11, 0x60080000 };
BattleList D_800A6BEC = {
    4,
    { &D_800A6B8C, &D_800A6B98, &D_800A6BA4, &D_800A6BB0,
      &D_800A6BBC, &D_800A6BC8, &D_800A6BD4, &D_800A6BE0 },
};
Battle D_800A6C10 = { 0, 0, 0x60040000 };
Battle D_800A6C1C = { 0, 0, 0x60040000 };
Battle D_800A6C28 = { 0, 0, 0x60040000 };
Battle D_800A6C34 = { 0, 0, 0x60040000 };
Battle D_800A6C40 = { 0, 0, 0x60040000 };
Battle D_800A6C4C = { 0, 0, 0x60040000 };
Battle D_800A6C58 = { 0, 0, 0x60040000 };
Battle D_800A6C64 = { 0, 0, 0x60040000 };
BattleList D_800A6C70 = {
    0,
    { &D_800A6C10, &D_800A6C1C, &D_800A6C28, &D_800A6C34,
      &D_800A6C40, &D_800A6C4C, &D_800A6C58, &D_800A6C64 },
};
Battle D_800A6C94 = { 0, 0, 0x60040000 };
Battle D_800A6CA0 = { 0, 0, 0x60040000 };
Battle D_800A6CAC = { 0, 0, 0x60040000 };
Battle D_800A6CB8 = { 0, 0, 0x60040000 };
Battle D_800A6CC4 = { 0, 0, 0x60040000 };
Battle D_800A6CD0 = { 0, 0, 0x60040000 };
Battle D_800A6CDC = { 0, 0, 0x60040000 };
Battle D_800A6CE8 = { 0, 0, 0x60040000 };
BattleList D_800A6CF4 = {
    0,
    { &D_800A6C94, &D_800A6CA0, &D_800A6CAC, &D_800A6CB8,
      &D_800A6CC4, &D_800A6CD0, &D_800A6CDC, &D_800A6CE8 },
};
Battle D_800A6D18 = { 0, 0, 0x60040000 };
Battle D_800A6D24 = { 0, 0, 0x60040000 };
Battle D_800A6D30 = { 0, 0, 0x60040000 };
Battle D_800A6D3C = { 0, 0, 0x60040000 };
Battle D_800A6D48 = { 0, 0, 0x60040000 };
Battle D_800A6D54 = { 0, 0, 0x60040000 };
Battle D_800A6D60 = { 0, 0, 0x60040000 };
Battle D_800A6D6C = { 0, 0, 0x60040000 };
BattleList D_800A6D78 = {
    0,
    { &D_800A6D18, &D_800A6D24, &D_800A6D30, &D_800A6D3C,
      &D_800A6D48, &D_800A6D54, &D_800A6D60, &D_800A6D6C },
};
FieldBattles stageBattles[] = {
    { 400, 2, 0, { &D_800A65BC, &D_800A6640, &D_800A66C4, &D_800A6748 } },
    { 404, 3, 0, { &D_800A67CC, &D_800A6850, &D_800A68D4, &D_800A6958 } },
    { 408, 4, 0, { &D_800A69DC, &D_800A6A60, &D_800A6AE4, &D_800A6B68 } },
    { 412, 5, 0, { &D_800A6BEC, &D_800A6C70, &D_800A6CF4, &D_800A6D78 } },
};
