#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6B3;
    D_800990B4.sheetEntry = 0x9410004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x940;
    D_800990B4.start = (Vec2){0x17900, 0x17300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9410006);
    D_8009A70C.setFile(7, 0x9410007);
    D_8009A70C.setFile(4, 0x9410005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60DC;
extern StagePoint D_800A60EC;
extern StagePoint D_800A6104;
extern StagePoint D_800A6114;
extern StagePoint D_800A612C;
extern StagePoint D_800A613C;
extern StagePoint D_800A6154;
extern StagePoint D_800A6164;
extern StagePoints D_800A60FC;
extern StagePoints D_800A6124;
extern StagePoints D_800A614C;
extern StagePoints D_800A6174;
extern u16 D_800A6220[];
extern u16 D_800A622C[];
extern u16 D_800A6238[];
extern FieldActorEntry D_800A6244;
extern FieldActorEntry D_800A6258;
extern FieldActorEntry D_800A626C;
extern FieldActorEntry D_800A6280;
extern Battle D_800A6318;
extern Battle D_800A6324;
extern Battle D_800A6330;
extern Battle D_800A633C;
extern Battle D_800A6348;
extern Battle D_800A6354;
extern Battle D_800A6360;
extern Battle D_800A636C;
extern Battle D_800A639C;
extern Battle D_800A63A8;
extern Battle D_800A63B4;
extern Battle D_800A63C0;
extern Battle D_800A63CC;
extern Battle D_800A63D8;
extern Battle D_800A63E4;
extern Battle D_800A63F0;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A6438;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A6468;
extern Battle D_800A6474;
extern Battle D_800A64A4;
extern Battle D_800A64B0;
extern Battle D_800A64BC;
extern Battle D_800A64C8;
extern Battle D_800A64D4;
extern Battle D_800A64E0;
extern Battle D_800A64EC;
extern Battle D_800A64F8;
extern Battle D_800A6528;
extern Battle D_800A6534;
extern Battle D_800A6540;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6570;
extern Battle D_800A657C;
extern Battle D_800A65AC;
extern Battle D_800A65B8;
extern Battle D_800A65C4;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern Battle D_800A65F4;
extern Battle D_800A6600;
extern Battle D_800A6630;
extern Battle D_800A663C;
extern Battle D_800A6648;
extern Battle D_800A6654;
extern Battle D_800A6660;
extern Battle D_800A666C;
extern Battle D_800A6678;
extern Battle D_800A6684;
extern Battle D_800A66B4;
extern Battle D_800A66C0;
extern Battle D_800A66CC;
extern Battle D_800A66D8;
extern Battle D_800A66E4;
extern Battle D_800A66F0;
extern Battle D_800A66FC;
extern Battle D_800A6708;
extern Battle D_800A6738;
extern Battle D_800A6744;
extern Battle D_800A6750;
extern Battle D_800A675C;
extern Battle D_800A6768;
extern Battle D_800A6774;
extern Battle D_800A6780;
extern Battle D_800A678C;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67D4;
extern Battle D_800A67E0;
extern Battle D_800A67EC;
extern Battle D_800A67F8;
extern Battle D_800A6804;
extern Battle D_800A6810;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A6858;
extern Battle D_800A6864;
extern Battle D_800A6870;
extern Battle D_800A687C;
extern Battle D_800A6888;
extern Battle D_800A6894;
extern Battle D_800A68C4;
extern Battle D_800A68D0;
extern Battle D_800A68DC;
extern Battle D_800A68E8;
extern Battle D_800A68F4;
extern Battle D_800A6900;
extern Battle D_800A690C;
extern Battle D_800A6918;
extern Battle D_800A6948;
extern Battle D_800A6954;
extern Battle D_800A6960;
extern Battle D_800A696C;
extern Battle D_800A6978;
extern Battle D_800A6984;
extern Battle D_800A6990;
extern Battle D_800A699C;
extern Battle D_800A69CC;
extern Battle D_800A69D8;
extern Battle D_800A69E4;
extern Battle D_800A69F0;
extern Battle D_800A69FC;
extern Battle D_800A6A08;
extern Battle D_800A6A14;
extern Battle D_800A6A20;
extern Battle D_800A6A50;
extern Battle D_800A6A5C;
extern Battle D_800A6A68;
extern Battle D_800A6A74;
extern Battle D_800A6A80;
extern Battle D_800A6A8C;
extern Battle D_800A6A98;
extern Battle D_800A6AA4;
extern Battle D_800A6AD4;
extern Battle D_800A6AE0;
extern Battle D_800A6AEC;
extern Battle D_800A6AF8;
extern Battle D_800A6B04;
extern Battle D_800A6B10;
extern Battle D_800A6B1C;
extern Battle D_800A6B28;
extern BattleList D_800A6378;
extern BattleList D_800A63FC;
extern BattleList D_800A6480;
extern BattleList D_800A6504;
extern BattleList D_800A6588;
extern BattleList D_800A660C;
extern BattleList D_800A6690;
extern BattleList D_800A6714;
extern BattleList D_800A6798;
extern BattleList D_800A681C;
extern BattleList D_800A68A0;
extern BattleList D_800A6924;
extern BattleList D_800A69A8;
extern BattleList D_800A6A2C;
extern BattleList D_800A6AB0;
extern BattleList D_800A6B34;

StagePoint D_800A60DC = { 0x2EE, 2, 9, 224, 0x240, 5, NULL };
StagePoint D_800A60EC = { 0x28C, 0, 0, 0x410, 0x400, 0, &D_800A60DC };
StagePoints D_800A60FC = { 2, 1, &D_800A60EC };
StagePoint D_800A6104 = { 0x2EE, 3, 5, 224, 0x240, 5, NULL };
StagePoint D_800A6114 = { 0x28C, 0, 0, 0x110, 0x290, 0, &D_800A6104 };
StagePoints D_800A6124 = { 3, 1, &D_800A6114 };
StagePoint D_800A612C = { 0x2EE, 4, 3, 224, 0x240, 5, NULL };
StagePoint D_800A613C = { 0x299, 0, 0, 0x440, 0x2F8, 0, &D_800A612C };
StagePoints D_800A614C = { 4, 1, &D_800A613C };
StagePoint D_800A6154 = { 0x2EE, 6, 9, 224, 0x240, 5, NULL };
StagePoint D_800A6164 = { 0x299, 0, 0, 0x2D0, 0x590, 0, &D_800A6154 };
StagePoints D_800A6174 = { 6, 1, &D_800A6164 };
StagePoints *placePoints[] = {
    &D_800A60FC, &D_800A6124, &D_800A614C, &D_800A6174,
    NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x14C, 0x100, 0x30, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x170, 0x1FF },
};
u16 D_800A6220[] = { 0x7E01, 0, 8, 0, 0xFFFF };
u16 D_800A622C[] = { 0x7E02, 0, 9, 0, 0xFFFF };
u16 D_800A6238[] = { 0x7E02, 1, 9, 0, 0xFFFF };
FieldActorEntry D_800A6244 = { NULL, NULL, 0x146, 4, 0, 0, 0 };
FieldActorEntry D_800A6258 = { D_800A6220, NULL, 0x148, 5, 272, 344, 1 };
FieldActorEntry D_800A626C = { D_800A622C, NULL, 0x15F, 6, 432, 312, 1 };
FieldActorEntry D_800A6280 = { D_800A6238, NULL, 0x15F, 6, 224, 320, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6244,
    &D_800A6258,
    &D_800A626C,
    &D_800A6280,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x14, 0, 152, 140, 253, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E9, 0xB0, 0xF8, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E9, 0x240, 0xF0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6318 = { 55, 10, 0x60080000 };
Battle D_800A6324 = { 55, 10, 0x60080000 };
Battle D_800A6330 = { 55, 10, 0x60080000 };
Battle D_800A633C = { 55, 10, 0x60080000 };
Battle D_800A6348 = { 55, 10, 0x60080000 };
Battle D_800A6354 = { 55, 10, 0x60080000 };
Battle D_800A6360 = { 55, 10, 0x60080000 };
Battle D_800A636C = { 55, 10, 0x60080000 };
BattleList D_800A6378 = {
    3,
    { &D_800A6318, &D_800A6324, &D_800A6330, &D_800A633C,
      &D_800A6348, &D_800A6354, &D_800A6360, &D_800A636C },
};
Battle D_800A639C = { 0, 0, 0x60040000 };
Battle D_800A63A8 = { 0, 0, 0x60040000 };
Battle D_800A63B4 = { 0, 0, 0x60040000 };
Battle D_800A63C0 = { 0, 0, 0x60040000 };
Battle D_800A63CC = { 0, 0, 0x60040000 };
Battle D_800A63D8 = { 0, 0, 0x60040000 };
Battle D_800A63E4 = { 0, 0, 0x60040000 };
Battle D_800A63F0 = { 0, 0, 0x60040000 };
BattleList D_800A63FC = {
    0,
    { &D_800A639C, &D_800A63A8, &D_800A63B4, &D_800A63C0,
      &D_800A63CC, &D_800A63D8, &D_800A63E4, &D_800A63F0 },
};
Battle D_800A6420 = { 0, 0, 0x60040000 };
Battle D_800A642C = { 0, 0, 0x60040000 };
Battle D_800A6438 = { 0, 0, 0x60040000 };
Battle D_800A6444 = { 0, 0, 0x60040000 };
Battle D_800A6450 = { 0, 0, 0x60040000 };
Battle D_800A645C = { 0, 0, 0x60040000 };
Battle D_800A6468 = { 0, 0, 0x60040000 };
Battle D_800A6474 = { 0, 0, 0x60040000 };
BattleList D_800A6480 = {
    0,
    { &D_800A6420, &D_800A642C, &D_800A6438, &D_800A6444,
      &D_800A6450, &D_800A645C, &D_800A6468, &D_800A6474 },
};
Battle D_800A64A4 = { 0, 0, 0x60040000 };
Battle D_800A64B0 = { 0, 0, 0x60040000 };
Battle D_800A64BC = { 0, 0, 0x60040000 };
Battle D_800A64C8 = { 0, 0, 0x60040000 };
Battle D_800A64D4 = { 0, 0, 0x60040000 };
Battle D_800A64E0 = { 0, 0, 0x60040000 };
Battle D_800A64EC = { 0, 0, 0x60040000 };
Battle D_800A64F8 = { 0, 0, 0x60040000 };
BattleList D_800A6504 = {
    0,
    { &D_800A64A4, &D_800A64B0, &D_800A64BC, &D_800A64C8,
      &D_800A64D4, &D_800A64E0, &D_800A64EC, &D_800A64F8 },
};
Battle D_800A6528 = { 111, 10, 0x60080000 };
Battle D_800A6534 = { 111, 10, 0x60080000 };
Battle D_800A6540 = { 112, 10, 0x60080000 };
Battle D_800A654C = { 112, 10, 0x60080000 };
Battle D_800A6558 = { 119, 10, 0x60080000 };
Battle D_800A6564 = { 119, 10, 0x60080000 };
Battle D_800A6570 = { 168, 10, 0x60080000 };
Battle D_800A657C = { 168, 10, 0x60080000 };
BattleList D_800A6588 = {
    3,
    { &D_800A6528, &D_800A6534, &D_800A6540, &D_800A654C,
      &D_800A6558, &D_800A6564, &D_800A6570, &D_800A657C },
};
Battle D_800A65AC = { 0, 0, 0x60040000 };
Battle D_800A65B8 = { 0, 0, 0x60040000 };
Battle D_800A65C4 = { 0, 0, 0x60040000 };
Battle D_800A65D0 = { 0, 0, 0x60040000 };
Battle D_800A65DC = { 0, 0, 0x60040000 };
Battle D_800A65E8 = { 0, 0, 0x60040000 };
Battle D_800A65F4 = { 0, 0, 0x60040000 };
Battle D_800A6600 = { 0, 0, 0x60040000 };
BattleList D_800A660C = {
    0,
    { &D_800A65AC, &D_800A65B8, &D_800A65C4, &D_800A65D0,
      &D_800A65DC, &D_800A65E8, &D_800A65F4, &D_800A6600 },
};
Battle D_800A6630 = { 0, 0, 0x60040000 };
Battle D_800A663C = { 0, 0, 0x60040000 };
Battle D_800A6648 = { 0, 0, 0x60040000 };
Battle D_800A6654 = { 0, 0, 0x60040000 };
Battle D_800A6660 = { 0, 0, 0x60040000 };
Battle D_800A666C = { 0, 0, 0x60040000 };
Battle D_800A6678 = { 0, 0, 0x60040000 };
Battle D_800A6684 = { 0, 0, 0x60040000 };
BattleList D_800A6690 = {
    0,
    { &D_800A6630, &D_800A663C, &D_800A6648, &D_800A6654,
      &D_800A6660, &D_800A666C, &D_800A6678, &D_800A6684 },
};
Battle D_800A66B4 = { 0, 0, 0x60040000 };
Battle D_800A66C0 = { 0, 0, 0x60040000 };
Battle D_800A66CC = { 0, 0, 0x60040000 };
Battle D_800A66D8 = { 0, 0, 0x60040000 };
Battle D_800A66E4 = { 0, 0, 0x60040000 };
Battle D_800A66F0 = { 0, 0, 0x60040000 };
Battle D_800A66FC = { 0, 0, 0x60040000 };
Battle D_800A6708 = { 0, 0, 0x60040000 };
BattleList D_800A6714 = {
    0,
    { &D_800A66B4, &D_800A66C0, &D_800A66CC, &D_800A66D8,
      &D_800A66E4, &D_800A66F0, &D_800A66FC, &D_800A6708 },
};
Battle D_800A6738 = { 113, 10, 0x60080000 };
Battle D_800A6744 = { 113, 10, 0x60080000 };
Battle D_800A6750 = { 114, 10, 0x60080000 };
Battle D_800A675C = { 114, 10, 0x60080000 };
Battle D_800A6768 = { 115, 10, 0x60080000 };
Battle D_800A6774 = { 115, 10, 0x60080000 };
Battle D_800A6780 = { 167, 10, 0x60080000 };
Battle D_800A678C = { 167, 10, 0x60080000 };
BattleList D_800A6798 = {
    3,
    { &D_800A6738, &D_800A6744, &D_800A6750, &D_800A675C,
      &D_800A6768, &D_800A6774, &D_800A6780, &D_800A678C },
};
Battle D_800A67BC = { 0, 0, 0x60040000 };
Battle D_800A67C8 = { 0, 0, 0x60040000 };
Battle D_800A67D4 = { 0, 0, 0x60040000 };
Battle D_800A67E0 = { 0, 0, 0x60040000 };
Battle D_800A67EC = { 0, 0, 0x60040000 };
Battle D_800A67F8 = { 0, 0, 0x60040000 };
Battle D_800A6804 = { 0, 0, 0x60040000 };
Battle D_800A6810 = { 0, 0, 0x60040000 };
BattleList D_800A681C = {
    0,
    { &D_800A67BC, &D_800A67C8, &D_800A67D4, &D_800A67E0,
      &D_800A67EC, &D_800A67F8, &D_800A6804, &D_800A6810 },
};
Battle D_800A6840 = { 0, 0, 0x60040000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
Battle D_800A6858 = { 0, 0, 0x60040000 };
Battle D_800A6864 = { 0, 0, 0x60040000 };
Battle D_800A6870 = { 0, 0, 0x60040000 };
Battle D_800A687C = { 0, 0, 0x60040000 };
Battle D_800A6888 = { 0, 0, 0x60040000 };
Battle D_800A6894 = { 0, 0, 0x60040000 };
BattleList D_800A68A0 = {
    0,
    { &D_800A6840, &D_800A684C, &D_800A6858, &D_800A6864,
      &D_800A6870, &D_800A687C, &D_800A6888, &D_800A6894 },
};
Battle D_800A68C4 = { 0, 0, 0x60040000 };
Battle D_800A68D0 = { 0, 0, 0x60040000 };
Battle D_800A68DC = { 0, 0, 0x60040000 };
Battle D_800A68E8 = { 0, 0, 0x60040000 };
Battle D_800A68F4 = { 0, 0, 0x60040000 };
Battle D_800A6900 = { 0, 0, 0x60040000 };
Battle D_800A690C = { 0, 0, 0x60040000 };
Battle D_800A6918 = { 0, 0, 0x60040000 };
BattleList D_800A6924 = {
    0,
    { &D_800A68C4, &D_800A68D0, &D_800A68DC, &D_800A68E8,
      &D_800A68F4, &D_800A6900, &D_800A690C, &D_800A6918 },
};
Battle D_800A6948 = { 73, 10, 0x60080000 };
Battle D_800A6954 = { 73, 10, 0x60080000 };
Battle D_800A6960 = { 86, 10, 0x60080000 };
Battle D_800A696C = { 86, 10, 0x60080000 };
Battle D_800A6978 = { 85, 10, 0x60080000 };
Battle D_800A6984 = { 170, 10, 0x60080000 };
Battle D_800A6990 = { 92, 10, 0x60080000 };
Battle D_800A699C = { 174, 10, 0x60080000 };
BattleList D_800A69A8 = {
    3,
    { &D_800A6948, &D_800A6954, &D_800A6960, &D_800A696C,
      &D_800A6978, &D_800A6984, &D_800A6990, &D_800A699C },
};
Battle D_800A69CC = { 0, 0, 0x60040000 };
Battle D_800A69D8 = { 0, 0, 0x60040000 };
Battle D_800A69E4 = { 0, 0, 0x60040000 };
Battle D_800A69F0 = { 0, 0, 0x60040000 };
Battle D_800A69FC = { 0, 0, 0x60040000 };
Battle D_800A6A08 = { 0, 0, 0x60040000 };
Battle D_800A6A14 = { 0, 0, 0x60040000 };
Battle D_800A6A20 = { 0, 0, 0x60040000 };
BattleList D_800A6A2C = {
    0,
    { &D_800A69CC, &D_800A69D8, &D_800A69E4, &D_800A69F0,
      &D_800A69FC, &D_800A6A08, &D_800A6A14, &D_800A6A20 },
};
Battle D_800A6A50 = { 0, 0, 0x60040000 };
Battle D_800A6A5C = { 0, 0, 0x60040000 };
Battle D_800A6A68 = { 0, 0, 0x60040000 };
Battle D_800A6A74 = { 0, 0, 0x60040000 };
Battle D_800A6A80 = { 0, 0, 0x60040000 };
Battle D_800A6A8C = { 0, 0, 0x60040000 };
Battle D_800A6A98 = { 0, 0, 0x60040000 };
Battle D_800A6AA4 = { 0, 0, 0x60040000 };
BattleList D_800A6AB0 = {
    0,
    { &D_800A6A50, &D_800A6A5C, &D_800A6A68, &D_800A6A74,
      &D_800A6A80, &D_800A6A8C, &D_800A6A98, &D_800A6AA4 },
};
Battle D_800A6AD4 = { 0, 0, 0x60040000 };
Battle D_800A6AE0 = { 0, 0, 0x60040000 };
Battle D_800A6AEC = { 0, 0, 0x60040000 };
Battle D_800A6AF8 = { 0, 0, 0x60040000 };
Battle D_800A6B04 = { 0, 0, 0x60040000 };
Battle D_800A6B10 = { 0, 0, 0x60040000 };
Battle D_800A6B1C = { 0, 0, 0x60040000 };
Battle D_800A6B28 = { 0, 0, 0x60040000 };
BattleList D_800A6B34 = {
    0,
    { &D_800A6AD4, &D_800A6AE0, &D_800A6AEC, &D_800A6AF8,
      &D_800A6B04, &D_800A6B10, &D_800A6B1C, &D_800A6B28 },
};
FieldBattles stageBattles[] = {
    { 420, 2, 0, { &D_800A6378, &D_800A63FC, &D_800A6480, &D_800A6504 } },
    { 426, 3, 0, { &D_800A6588, &D_800A660C, &D_800A6690, &D_800A6714 } },
    { 432, 4, 0, { &D_800A6798, &D_800A681C, &D_800A68A0, &D_800A6924 } },
    { 443, 6, 0, { &D_800A69A8, &D_800A6A2C, &D_800A6AB0, &D_800A6B34 } },
};
