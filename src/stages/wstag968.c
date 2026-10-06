#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6AF;
    D_800990B4.sheetEntry = 0x93F0004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x93E;
    D_800990B4.start = (Vec2){0xF900, 0x14000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x93F0006);
    D_8009A70C.setFile(7, 0x93F0007);
    D_8009A70C.setFile(4, 0x93F0005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60D8;
extern StagePoint D_800A60E8;
extern StagePoint D_800A6100;
extern StagePoint D_800A6110;
extern StagePoint D_800A6128;
extern StagePoint D_800A6138;
extern StagePoint D_800A6150;
extern StagePoint D_800A6160;
extern StagePoint D_800A6178;
extern StagePoint D_800A6188;
extern StagePoints D_800A60F8;
extern StagePoints D_800A6120;
extern StagePoints D_800A6148;
extern StagePoints D_800A6170;
extern StagePoints D_800A6198;
extern u16 D_800A6248[];
extern u16 D_800A6254[];
extern u16 D_800A6260[];
extern FieldActorEntry D_800A626C;
extern FieldActorEntry D_800A6280;
extern FieldActorEntry D_800A6294;
extern FieldActorEntry D_800A62A8;
extern Battle D_800A6340;
extern Battle D_800A634C;
extern Battle D_800A6358;
extern Battle D_800A6364;
extern Battle D_800A6370;
extern Battle D_800A637C;
extern Battle D_800A6388;
extern Battle D_800A6394;
extern Battle D_800A63C4;
extern Battle D_800A63D0;
extern Battle D_800A63DC;
extern Battle D_800A63E8;
extern Battle D_800A63F4;
extern Battle D_800A6400;
extern Battle D_800A640C;
extern Battle D_800A6418;
extern Battle D_800A6448;
extern Battle D_800A6454;
extern Battle D_800A6460;
extern Battle D_800A646C;
extern Battle D_800A6478;
extern Battle D_800A6484;
extern Battle D_800A6490;
extern Battle D_800A649C;
extern Battle D_800A64CC;
extern Battle D_800A64D8;
extern Battle D_800A64E4;
extern Battle D_800A64F0;
extern Battle D_800A64FC;
extern Battle D_800A6508;
extern Battle D_800A6514;
extern Battle D_800A6520;
extern Battle D_800A6550;
extern Battle D_800A655C;
extern Battle D_800A6568;
extern Battle D_800A6574;
extern Battle D_800A6580;
extern Battle D_800A658C;
extern Battle D_800A6598;
extern Battle D_800A65A4;
extern Battle D_800A65D4;
extern Battle D_800A65E0;
extern Battle D_800A65EC;
extern Battle D_800A65F8;
extern Battle D_800A6604;
extern Battle D_800A6610;
extern Battle D_800A661C;
extern Battle D_800A6628;
extern Battle D_800A6658;
extern Battle D_800A6664;
extern Battle D_800A6670;
extern Battle D_800A667C;
extern Battle D_800A6688;
extern Battle D_800A6694;
extern Battle D_800A66A0;
extern Battle D_800A66AC;
extern Battle D_800A66DC;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6700;
extern Battle D_800A670C;
extern Battle D_800A6718;
extern Battle D_800A6724;
extern Battle D_800A6730;
extern Battle D_800A6760;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A6784;
extern Battle D_800A6790;
extern Battle D_800A679C;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A6808;
extern Battle D_800A6814;
extern Battle D_800A6820;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern Battle D_800A688C;
extern Battle D_800A6898;
extern Battle D_800A68A4;
extern Battle D_800A68B0;
extern Battle D_800A68BC;
extern Battle D_800A68EC;
extern Battle D_800A68F8;
extern Battle D_800A6904;
extern Battle D_800A6910;
extern Battle D_800A691C;
extern Battle D_800A6928;
extern Battle D_800A6934;
extern Battle D_800A6940;
extern Battle D_800A6970;
extern Battle D_800A697C;
extern Battle D_800A6988;
extern Battle D_800A6994;
extern Battle D_800A69A0;
extern Battle D_800A69AC;
extern Battle D_800A69B8;
extern Battle D_800A69C4;
extern Battle D_800A69F4;
extern Battle D_800A6A00;
extern Battle D_800A6A0C;
extern Battle D_800A6A18;
extern Battle D_800A6A24;
extern Battle D_800A6A30;
extern Battle D_800A6A3C;
extern Battle D_800A6A48;
extern Battle D_800A6A78;
extern Battle D_800A6A84;
extern Battle D_800A6A90;
extern Battle D_800A6A9C;
extern Battle D_800A6AA8;
extern Battle D_800A6AB4;
extern Battle D_800A6AC0;
extern Battle D_800A6ACC;
extern Battle D_800A6AFC;
extern Battle D_800A6B08;
extern Battle D_800A6B14;
extern Battle D_800A6B20;
extern Battle D_800A6B2C;
extern Battle D_800A6B38;
extern Battle D_800A6B44;
extern Battle D_800A6B50;
extern BattleList D_800A63A0;
extern BattleList D_800A6424;
extern BattleList D_800A64A8;
extern BattleList D_800A652C;
extern BattleList D_800A65B0;
extern BattleList D_800A6634;
extern BattleList D_800A66B8;
extern BattleList D_800A673C;
extern BattleList D_800A67C0;
extern BattleList D_800A6844;
extern BattleList D_800A68C8;
extern BattleList D_800A694C;
extern BattleList D_800A69D0;
extern BattleList D_800A6A54;
extern BattleList D_800A6AD8;
extern BattleList D_800A6B5C;

StagePoint D_800A60D8 = { 0x2EE, 1, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A60E8 = { 0x298, 0, 0, 0x1F0, 0x360, 0, &D_800A60D8 };
StagePoints D_800A60F8 = { 1, 1, &D_800A60E8 };
StagePoint D_800A6100 = { 0x2EC, 1, 8, 0x3B0, 120, 1, NULL };
StagePoint D_800A6110 = { 0x298, 0, 0, 0x560, 0x238, 0, &D_800A6100 };
StagePoints D_800A6120 = { 1, 2, &D_800A6110 };
StagePoint D_800A6128 = { 0x2EC, 3, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A6138 = { 0x28F, 0, 0, 0x398, 0x270, 0, &D_800A6128 };
StagePoints D_800A6148 = { 3, 1, &D_800A6138 };
StagePoint D_800A6150 = { 0x2EC, 4, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A6160 = { 0x28C, 0, 0, 0x290, 0x200, 0, &D_800A6150 };
StagePoints D_800A6170 = { 4, 1, &D_800A6160 };
StagePoint D_800A6178 = { 0x2ED, 5, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A6188 = { 0x28F, 0, 0, 0x450, 0x226, 0, &D_800A6178 };
StagePoints D_800A6198 = { 5, 1, &D_800A6188 };
StagePoints *placePoints[] = {
    &D_800A60F8, &D_800A6120, &D_800A6148, &D_800A6170,
    &D_800A6198, NULL,
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
u16 D_800A6248[] = { 0x7E00, 0, 8, 0, 0xFFFF };
u16 D_800A6254[] = { 0x7E04, 1, 9, 0, 0xFFFF };
u16 D_800A6260[] = { 0x7E02, 1, 9, 0, 0xFFFF };
FieldActorEntry D_800A626C = { NULL, NULL, 0x146, 4, 0, 0, 0 };
FieldActorEntry D_800A6280 = { D_800A6248, NULL, 0x148, 5, 368, 344, 1 };
FieldActorEntry D_800A6294 = { D_800A6254, NULL, 0x15F, 6, 528, 280, 1 };
FieldActorEntry D_800A62A8 = { D_800A6260, NULL, 0x15F, 6, 272, 312, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A626C,
    &D_800A6280,
    &D_800A6294,
    &D_800A62A8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x14, 0, 552, 100, 213, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E8, 0x240, 0xD0, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E8, 0xB0, 0x168, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6340 = { 38, 10, 0x60080000 };
Battle D_800A634C = { 38, 10, 0x60080000 };
Battle D_800A6358 = { 38, 10, 0x60080000 };
Battle D_800A6364 = { 38, 10, 0x60080000 };
Battle D_800A6370 = { 38, 10, 0x60080000 };
Battle D_800A637C = { 38, 10, 0x60080000 };
Battle D_800A6388 = { 38, 10, 0x60080000 };
Battle D_800A6394 = { 38, 10, 0x60080000 };
BattleList D_800A63A0 = {
    3,
    { &D_800A6340, &D_800A634C, &D_800A6358, &D_800A6364,
      &D_800A6370, &D_800A637C, &D_800A6388, &D_800A6394 },
};
Battle D_800A63C4 = { 0, 0, 0x60040000 };
Battle D_800A63D0 = { 0, 0, 0x60040000 };
Battle D_800A63DC = { 0, 0, 0x60040000 };
Battle D_800A63E8 = { 0, 0, 0x60040000 };
Battle D_800A63F4 = { 0, 0, 0x60040000 };
Battle D_800A6400 = { 0, 0, 0x60040000 };
Battle D_800A640C = { 0, 0, 0x60040000 };
Battle D_800A6418 = { 0, 0, 0x60040000 };
BattleList D_800A6424 = {
    0,
    { &D_800A63C4, &D_800A63D0, &D_800A63DC, &D_800A63E8,
      &D_800A63F4, &D_800A6400, &D_800A640C, &D_800A6418 },
};
Battle D_800A6448 = { 0, 0, 0x60040000 };
Battle D_800A6454 = { 0, 0, 0x60040000 };
Battle D_800A6460 = { 0, 0, 0x60040000 };
Battle D_800A646C = { 0, 0, 0x60040000 };
Battle D_800A6478 = { 0, 0, 0x60040000 };
Battle D_800A6484 = { 0, 0, 0x60040000 };
Battle D_800A6490 = { 0, 0, 0x60040000 };
Battle D_800A649C = { 0, 0, 0x60040000 };
BattleList D_800A64A8 = {
    0,
    { &D_800A6448, &D_800A6454, &D_800A6460, &D_800A646C,
      &D_800A6478, &D_800A6484, &D_800A6490, &D_800A649C },
};
Battle D_800A64CC = { 0, 0, 0x60040000 };
Battle D_800A64D8 = { 0, 0, 0x60040000 };
Battle D_800A64E4 = { 0, 0, 0x60040000 };
Battle D_800A64F0 = { 0, 0, 0x60040000 };
Battle D_800A64FC = { 0, 0, 0x60040000 };
Battle D_800A6508 = { 0, 0, 0x60040000 };
Battle D_800A6514 = { 0, 0, 0x60040000 };
Battle D_800A6520 = { 0, 0, 0x60040000 };
BattleList D_800A652C = {
    0,
    { &D_800A64CC, &D_800A64D8, &D_800A64E4, &D_800A64F0,
      &D_800A64FC, &D_800A6508, &D_800A6514, &D_800A6520 },
};
Battle D_800A6550 = { 111, 10, 0x60080000 };
Battle D_800A655C = { 111, 10, 0x60080000 };
Battle D_800A6568 = { 112, 10, 0x60080000 };
Battle D_800A6574 = { 112, 10, 0x60080000 };
Battle D_800A6580 = { 119, 10, 0x60080000 };
Battle D_800A658C = { 119, 10, 0x60080000 };
Battle D_800A6598 = { 168, 10, 0x60080000 };
Battle D_800A65A4 = { 168, 10, 0x60080000 };
BattleList D_800A65B0 = {
    3,
    { &D_800A6550, &D_800A655C, &D_800A6568, &D_800A6574,
      &D_800A6580, &D_800A658C, &D_800A6598, &D_800A65A4 },
};
Battle D_800A65D4 = { 0, 0, 0x60040000 };
Battle D_800A65E0 = { 0, 0, 0x60040000 };
Battle D_800A65EC = { 0, 0, 0x60040000 };
Battle D_800A65F8 = { 0, 0, 0x60040000 };
Battle D_800A6604 = { 0, 0, 0x60040000 };
Battle D_800A6610 = { 0, 0, 0x60040000 };
Battle D_800A661C = { 0, 0, 0x60040000 };
Battle D_800A6628 = { 0, 0, 0x60040000 };
BattleList D_800A6634 = {
    0,
    { &D_800A65D4, &D_800A65E0, &D_800A65EC, &D_800A65F8,
      &D_800A6604, &D_800A6610, &D_800A661C, &D_800A6628 },
};
Battle D_800A6658 = { 0, 0, 0x60040000 };
Battle D_800A6664 = { 0, 0, 0x60040000 };
Battle D_800A6670 = { 0, 0, 0x60040000 };
Battle D_800A667C = { 0, 0, 0x60040000 };
Battle D_800A6688 = { 0, 0, 0x60040000 };
Battle D_800A6694 = { 0, 0, 0x60040000 };
Battle D_800A66A0 = { 0, 0, 0x60040000 };
Battle D_800A66AC = { 0, 0, 0x60040000 };
BattleList D_800A66B8 = {
    0,
    { &D_800A6658, &D_800A6664, &D_800A6670, &D_800A667C,
      &D_800A6688, &D_800A6694, &D_800A66A0, &D_800A66AC },
};
Battle D_800A66DC = { 0, 0, 0x60040000 };
Battle D_800A66E8 = { 0, 0, 0x60040000 };
Battle D_800A66F4 = { 0, 0, 0x60040000 };
Battle D_800A6700 = { 0, 0, 0x60040000 };
Battle D_800A670C = { 0, 0, 0x60040000 };
Battle D_800A6718 = { 0, 0, 0x60040000 };
Battle D_800A6724 = { 0, 0, 0x60040000 };
Battle D_800A6730 = { 0, 0, 0x60040000 };
BattleList D_800A673C = {
    0,
    { &D_800A66DC, &D_800A66E8, &D_800A66F4, &D_800A6700,
      &D_800A670C, &D_800A6718, &D_800A6724, &D_800A6730 },
};
Battle D_800A6760 = { 113, 10, 0x60080000 };
Battle D_800A676C = { 113, 10, 0x60080000 };
Battle D_800A6778 = { 114, 10, 0x60080000 };
Battle D_800A6784 = { 114, 10, 0x60080000 };
Battle D_800A6790 = { 115, 10, 0x60080000 };
Battle D_800A679C = { 115, 10, 0x60080000 };
Battle D_800A67A8 = { 167, 10, 0x60080000 };
Battle D_800A67B4 = { 167, 10, 0x60080000 };
BattleList D_800A67C0 = {
    3,
    { &D_800A6760, &D_800A676C, &D_800A6778, &D_800A6784,
      &D_800A6790, &D_800A679C, &D_800A67A8, &D_800A67B4 },
};
Battle D_800A67E4 = { 0, 0, 0x60040000 };
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
Battle D_800A6808 = { 0, 0, 0x60040000 };
Battle D_800A6814 = { 0, 0, 0x60040000 };
Battle D_800A6820 = { 0, 0, 0x60040000 };
Battle D_800A682C = { 0, 0, 0x60040000 };
Battle D_800A6838 = { 0, 0, 0x60040000 };
BattleList D_800A6844 = {
    0,
    { &D_800A67E4, &D_800A67F0, &D_800A67FC, &D_800A6808,
      &D_800A6814, &D_800A6820, &D_800A682C, &D_800A6838 },
};
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 0, 0, 0x60040000 };
Battle D_800A688C = { 0, 0, 0x60040000 };
Battle D_800A6898 = { 0, 0, 0x60040000 };
Battle D_800A68A4 = { 0, 0, 0x60040000 };
Battle D_800A68B0 = { 0, 0, 0x60040000 };
Battle D_800A68BC = { 0, 0, 0x60040000 };
BattleList D_800A68C8 = {
    0,
    { &D_800A6868, &D_800A6874, &D_800A6880, &D_800A688C,
      &D_800A6898, &D_800A68A4, &D_800A68B0, &D_800A68BC },
};
Battle D_800A68EC = { 0, 0, 0x60040000 };
Battle D_800A68F8 = { 0, 0, 0x60040000 };
Battle D_800A6904 = { 0, 0, 0x60040000 };
Battle D_800A6910 = { 0, 0, 0x60040000 };
Battle D_800A691C = { 0, 0, 0x60040000 };
Battle D_800A6928 = { 0, 0, 0x60040000 };
Battle D_800A6934 = { 0, 0, 0x60040000 };
Battle D_800A6940 = { 0, 0, 0x60040000 };
BattleList D_800A694C = {
    0,
    { &D_800A68EC, &D_800A68F8, &D_800A6904, &D_800A6910,
      &D_800A691C, &D_800A6928, &D_800A6934, &D_800A6940 },
};
Battle D_800A6970 = { 74, 10, 0x60080000 };
Battle D_800A697C = { 77, 10, 0x60080000 };
Battle D_800A6988 = { 78, 10, 0x60080000 };
Battle D_800A6994 = { 79, 10, 0x60080000 };
Battle D_800A69A0 = { 80, 10, 0x60080000 };
Battle D_800A69AC = { 75, 10, 0x60080000 };
Battle D_800A69B8 = { 76, 10, 0x60080000 };
Battle D_800A69C4 = { 89, 10, 0x60080000 };
BattleList D_800A69D0 = {
    3,
    { &D_800A6970, &D_800A697C, &D_800A6988, &D_800A6994,
      &D_800A69A0, &D_800A69AC, &D_800A69B8, &D_800A69C4 },
};
Battle D_800A69F4 = { 0, 0, 0x60040000 };
Battle D_800A6A00 = { 0, 0, 0x60040000 };
Battle D_800A6A0C = { 0, 0, 0x60040000 };
Battle D_800A6A18 = { 0, 0, 0x60040000 };
Battle D_800A6A24 = { 0, 0, 0x60040000 };
Battle D_800A6A30 = { 0, 0, 0x60040000 };
Battle D_800A6A3C = { 0, 0, 0x60040000 };
Battle D_800A6A48 = { 0, 0, 0x60040000 };
BattleList D_800A6A54 = {
    0,
    { &D_800A69F4, &D_800A6A00, &D_800A6A0C, &D_800A6A18,
      &D_800A6A24, &D_800A6A30, &D_800A6A3C, &D_800A6A48 },
};
Battle D_800A6A78 = { 0, 0, 0x60040000 };
Battle D_800A6A84 = { 0, 0, 0x60040000 };
Battle D_800A6A90 = { 0, 0, 0x60040000 };
Battle D_800A6A9C = { 0, 0, 0x60040000 };
Battle D_800A6AA8 = { 0, 0, 0x60040000 };
Battle D_800A6AB4 = { 0, 0, 0x60040000 };
Battle D_800A6AC0 = { 0, 0, 0x60040000 };
Battle D_800A6ACC = { 0, 0, 0x60040000 };
BattleList D_800A6AD8 = {
    0,
    { &D_800A6A78, &D_800A6A84, &D_800A6A90, &D_800A6A9C,
      &D_800A6AA8, &D_800A6AB4, &D_800A6AC0, &D_800A6ACC },
};
Battle D_800A6AFC = { 0, 0, 0x60040000 };
Battle D_800A6B08 = { 0, 0, 0x60040000 };
Battle D_800A6B14 = { 0, 0, 0x60040000 };
Battle D_800A6B20 = { 0, 0, 0x60040000 };
Battle D_800A6B2C = { 0, 0, 0x60040000 };
Battle D_800A6B38 = { 0, 0, 0x60040000 };
Battle D_800A6B44 = { 0, 0, 0x60040000 };
Battle D_800A6B50 = { 0, 0, 0x60040000 };
BattleList D_800A6B5C = {
    0,
    { &D_800A6AFC, &D_800A6B08, &D_800A6B14, &D_800A6B20,
      &D_800A6B2C, &D_800A6B38, &D_800A6B44, &D_800A6B50 },
};
FieldBattles stageBattles[] = {
    { 414, 1, 0, { &D_800A63A0, &D_800A6424, &D_800A64A8, &D_800A652C } },
    { 425, 3, 0, { &D_800A65B0, &D_800A6634, &D_800A66B8, &D_800A673C } },
    { 431, 4, 0, { &D_800A67C0, &D_800A6844, &D_800A68C8, &D_800A694C } },
    { 437, 5, 0, { &D_800A69D0, &D_800A6A54, &D_800A6AD8, &D_800A6B5C } },
};
