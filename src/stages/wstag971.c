#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x68F;
    D_800990B4.sheetEntry = 0x9450004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x944;
    D_800990B4.start = (Vec2){0xEB00, 0x1F500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9450006);
    D_8009A70C.setFile(7, 0x9450007);
    D_8009A70C.setFile(4, 0x9450005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60D8;
extern StagePoint D_800A60F0;
extern StagePoint D_800A6108;
extern StagePoint D_800A6120;
extern StagePoint D_800A6138;
extern StagePoint D_800A6150;
extern StagePoint D_800A6168;
extern StagePoint D_800A6180;
extern StagePoint D_800A6198;
extern StagePoint D_800A61B0;
extern StagePoints D_800A60E8;
extern StagePoints D_800A6100;
extern StagePoints D_800A6118;
extern StagePoints D_800A6130;
extern StagePoints D_800A6148;
extern StagePoints D_800A6160;
extern StagePoints D_800A6178;
extern StagePoints D_800A6190;
extern StagePoints D_800A61A8;
extern StagePoints D_800A61C0;
extern u16 D_800A62C4[];
extern u16 D_800A62CC[];
extern u16 D_800A62D4[];
extern u16 D_800A62E4[];
extern u16 D_800A62EC[];
extern u16 D_800A62FC[];
extern u16 D_800A6308[];
extern u16 D_800A6318[];
extern u16 D_800A6324[];
extern u16 D_800A6334[];
extern u16 D_800A6340[];
extern u16 D_800A6348[];
extern u16 D_800A6350[];
extern u16 D_800A6360[];
extern u16 D_800A6368[];
extern u16 D_800A6378[];
extern u16 D_800A6384[];
extern u16 D_800A6394[];
extern u16 D_800A63A0[];
extern u16 D_800A63B0[];
extern u16 D_800A63BC[];
extern u16 D_800A63C4[];
extern u16 D_800A63CC[];
extern u16 D_800A63DC[];
extern u16 D_800A63E4[];
extern u16 D_800A63F4[];
extern u16 D_800A6400[];
extern u16 D_800A6410[];
extern u16 D_800A641C[];
extern u16 D_800A642C[];
extern u16 D_800A6438[];
extern u16 D_800A6440[];
extern u16 D_800A6448[];
extern u16 D_800A6458[];
extern u16 D_800A6460[];
extern u16 D_800A6470[];
extern u16 D_800A647C[];
extern u16 D_800A648C[];
extern u16 D_800A6498[];
extern u16 D_800A64A8[];
extern u16 D_800A65D4[];
extern FieldTalk D_800A64B4[];
extern u16 D_800A65E8[];
extern FieldTalk D_800A64FC[];
extern u16 D_800A65FC[];
extern FieldTalk D_800A6544[];
extern u16 D_800A6610[];
extern FieldTalk D_800A658C[];
extern u16 D_800A6624[];
extern u16 D_800A6630[];
extern u16 D_800A663C[];
extern u16 D_800A6648[];
extern u16 D_800A6654[];
extern FieldActorEntry D_800A6660;
extern FieldActorEntry D_800A6674;
extern FieldActorEntry D_800A6688;
extern FieldActorEntry D_800A669C;
extern FieldActorEntry D_800A66B0;
extern FieldActorEntry D_800A66C4;
extern FieldActorEntry D_800A66D8;
extern FieldActorEntry D_800A66EC;
extern FieldActorEntry D_800A6700;
extern FieldActorEntry D_800A6714;
extern Battle D_800A679C;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67CC;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A6820;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6850;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A68A4;
extern Battle D_800A68B0;
extern Battle D_800A68BC;
extern Battle D_800A68C8;
extern Battle D_800A68D4;
extern Battle D_800A68E0;
extern Battle D_800A68EC;
extern Battle D_800A68F8;
extern Battle D_800A6928;
extern Battle D_800A6934;
extern Battle D_800A6940;
extern Battle D_800A694C;
extern Battle D_800A6958;
extern Battle D_800A6964;
extern Battle D_800A6970;
extern Battle D_800A697C;
extern Battle D_800A69AC;
extern Battle D_800A69B8;
extern Battle D_800A69C4;
extern Battle D_800A69D0;
extern Battle D_800A69DC;
extern Battle D_800A69E8;
extern Battle D_800A69F4;
extern Battle D_800A6A00;
extern Battle D_800A6A30;
extern Battle D_800A6A3C;
extern Battle D_800A6A48;
extern Battle D_800A6A54;
extern Battle D_800A6A60;
extern Battle D_800A6A6C;
extern Battle D_800A6A78;
extern Battle D_800A6A84;
extern Battle D_800A6AB4;
extern Battle D_800A6AC0;
extern Battle D_800A6ACC;
extern Battle D_800A6AD8;
extern Battle D_800A6AE4;
extern Battle D_800A6AF0;
extern Battle D_800A6AFC;
extern Battle D_800A6B08;
extern Battle D_800A6B38;
extern Battle D_800A6B44;
extern Battle D_800A6B50;
extern Battle D_800A6B5C;
extern Battle D_800A6B68;
extern Battle D_800A6B74;
extern Battle D_800A6B80;
extern Battle D_800A6B8C;
extern Battle D_800A6BBC;
extern Battle D_800A6BC8;
extern Battle D_800A6BD4;
extern Battle D_800A6BE0;
extern Battle D_800A6BEC;
extern Battle D_800A6BF8;
extern Battle D_800A6C04;
extern Battle D_800A6C10;
extern Battle D_800A6C40;
extern Battle D_800A6C4C;
extern Battle D_800A6C58;
extern Battle D_800A6C64;
extern Battle D_800A6C70;
extern Battle D_800A6C7C;
extern Battle D_800A6C88;
extern Battle D_800A6C94;
extern Battle D_800A6CC4;
extern Battle D_800A6CD0;
extern Battle D_800A6CDC;
extern Battle D_800A6CE8;
extern Battle D_800A6CF4;
extern Battle D_800A6D00;
extern Battle D_800A6D0C;
extern Battle D_800A6D18;
extern Battle D_800A6D48;
extern Battle D_800A6D54;
extern Battle D_800A6D60;
extern Battle D_800A6D6C;
extern Battle D_800A6D78;
extern Battle D_800A6D84;
extern Battle D_800A6D90;
extern Battle D_800A6D9C;
extern BattleList D_800A67FC;
extern BattleList D_800A6880;
extern BattleList D_800A6904;
extern BattleList D_800A6988;
extern BattleList D_800A6A0C;
extern BattleList D_800A6A90;
extern BattleList D_800A6B14;
extern BattleList D_800A6B98;
extern BattleList D_800A6C1C;
extern BattleList D_800A6CA0;
extern BattleList D_800A6D24;
extern BattleList D_800A6DA8;

StagePoint D_800A60D8 = { 0x2EE, 1, 1, 224, 0x240, 5, NULL };
StagePoints D_800A60E8 = { 1, 1, &D_800A60D8 };
StagePoint D_800A60F0 = { 0x2ED, 1, 1, 224, 192, 5, NULL };
StagePoints D_800A6100 = { 1, 2, &D_800A60F0 };
StagePoint D_800A6108 = { 0x2ED, 1, 2, 224, 192, 5, NULL };
StagePoints D_800A6118 = { 1, 3, &D_800A6108 };
StagePoint D_800A6120 = { 0x2EE, 1, 2, 224, 0x240, 5, NULL };
StagePoints D_800A6130 = { 1, 4, &D_800A6120 };
StagePoint D_800A6138 = { 0x2ED, 1, 5, 224, 192, 5, NULL };
StagePoints D_800A6148 = { 1, 5, &D_800A6138 };
StagePoint D_800A6150 = { 0x2EE, 1, 4, 224, 0x240, 5, NULL };
StagePoints D_800A6160 = { 1, 6, &D_800A6150 };
StagePoint D_800A6168 = { 0x2ED, 5, 4, 224, 192, 5, NULL };
StagePoints D_800A6178 = { 5, 1, &D_800A6168 };
StagePoint D_800A6180 = { 0x2ED, 5, 5, 224, 192, 5, NULL };
StagePoints D_800A6190 = { 5, 2, &D_800A6180 };
StagePoint D_800A6198 = { 0x2ED, 5, 6, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A61A8 = { 5, 3, &D_800A6198 };
StagePoint D_800A61B0 = { 0x2ED, 6, 4, 224, 192, 5, NULL };
StagePoints D_800A61C0 = { 6, 1, &D_800A61B0 };
StagePoints *placePoints[] = {
    &D_800A60E8, &D_800A6100, &D_800A6118, &D_800A6130,
    &D_800A6148, &D_800A6160, &D_800A6178, &D_800A6190,
    &D_800A61A8, &D_800A61C0, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x140, 0x78, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x152, 0x140, 0x48, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x140, 0xA8, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x160, 0x1FE },
};
u16 D_800A62C4[] = { 0x8168, 1, 0xFFFF };
u16 D_800A62CC[] = { 0x7038, 1, 0xFFFF };
u16 D_800A62D4[] = { 0x8168, 0, 0, 0, 0xA1A, 0, 0xFFFF };
u16 D_800A62E4[] = { 0, 1, 0xFFFF };
u16 D_800A62EC[] = { 0x8168, 0, 0, 1, 0xA1A, 0, 0xFFFF };
u16 D_800A62FC[] = { 0x7403, 1, 0xA1A, 1, 0xFFFF };
u16 D_800A6308[] = { 0x8168, 0, 0xA1A, 1, 0, 0, 0xFFFF };
u16 D_800A6318[] = { 0x8168, 1, 0x7038, 1, 0xFFFF };
u16 D_800A6324[] = { 0x8168, 0, 0, 1, 0xA1A, 1, 0xFFFF };
u16 D_800A6334[] = { 0x8168, 1, 0x7038, 1, 0xFFFF };
u16 D_800A6340[] = { 0x8006, 1, 0xFFFF };
u16 D_800A6348[] = { 0x7031, 1, 0xFFFF };
u16 D_800A6350[] = { 0x8006, 0, 0, 0, 0xA14, 0, 0xFFFF };
u16 D_800A6360[] = { 0, 1, 0xFFFF };
u16 D_800A6368[] = { 0x8006, 0, 0, 1, 0xA14, 0, 0xFFFF };
u16 D_800A6378[] = { 0x7400, 1, 0xA14, 1, 0xFFFF };
u16 D_800A6384[] = { 0, 0, 0xA14, 1, 0x8006, 0, 0xFFFF };
u16 D_800A6394[] = { 0x7031, 1, 0x8006, 1, 0xFFFF };
u16 D_800A63A0[] = { 0x8006, 0, 0, 1, 0xA14, 1, 0xFFFF };
u16 D_800A63B0[] = { 0x8006, 1, 0x7031, 1, 0xFFFF };
u16 D_800A63BC[] = { 0x8026, 1, 0xFFFF };
u16 D_800A63C4[] = { 0x7035, 1, 0xFFFF };
u16 D_800A63CC[] = { 0x8026, 0, 0, 0, 0xA17, 0, 0xFFFF };
u16 D_800A63DC[] = { 0, 1, 0xFFFF };
u16 D_800A63E4[] = { 0x8026, 0, 0, 1, 0xA17, 0, 0xFFFF };
u16 D_800A63F4[] = { 0x7402, 1, 0xA17, 1, 0xFFFF };
u16 D_800A6400[] = { 0, 0, 0xA17, 1, 0x8026, 0, 0xFFFF };
u16 D_800A6410[] = { 0x7035, 1, 0x8026, 1, 0xFFFF };
u16 D_800A641C[] = { 0x8026, 0, 0, 1, 0xA17, 1, 0xFFFF };
u16 D_800A642C[] = { 0x8026, 1, 0x7035, 1, 0xFFFF };
u16 D_800A6438[] = { 0x8022, 1, 0xFFFF };
u16 D_800A6440[] = { 0x7033, 1, 0xFFFF };
u16 D_800A6448[] = { 0x8022, 0, 0, 0, 0xA15, 0, 0xFFFF };
u16 D_800A6458[] = { 0, 1, 0xFFFF };
u16 D_800A6460[] = { 0x8022, 0, 0, 1, 0xA15, 0, 0xFFFF };
u16 D_800A6470[] = { 0x7401, 1, 0xA15, 1, 0xFFFF };
u16 D_800A647C[] = { 0, 0, 0xA15, 1, 0x8022, 0, 0xFFFF };
u16 D_800A648C[] = { 0x7033, 1, 0x8022, 1, 0xFFFF };
u16 D_800A6498[] = { 0x8022, 0, 0, 1, 0xA15, 1, 0xFFFF };
u16 D_800A64A8[] = { 0x8022, 1, 0x7033, 1, 0xFFFF };
FieldTalk D_800A64B4[] = {
    { D_800A62C4, D_800A62CC, 0xE9 },
    { D_800A62D4, D_800A62E4, 0xEA },
    { D_800A62EC, D_800A62FC, 0xEB },
    { D_800A6308, D_800A6318, 0xEC },
    { D_800A6324, D_800A6334, 0xEC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A64FC[] = {
    { D_800A6340, D_800A6348, 0xD1 },
    { D_800A6350, D_800A6360, 0xD2 },
    { D_800A6368, D_800A6378, 0xD3 },
    { D_800A6384, D_800A6394, 0xD4 },
    { D_800A63A0, D_800A63B0, 0xD4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6544[] = {
    { D_800A63BC, D_800A63C4, 0xDD },
    { D_800A63CC, D_800A63DC, 0xDE },
    { D_800A63E4, D_800A63F4, 0xDF },
    { D_800A6400, D_800A6410, 0xE0 },
    { D_800A641C, D_800A642C, 0xE0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A658C[] = {
    { D_800A6438, D_800A6440, 0xD5 },
    { D_800A6448, D_800A6458, 0xD6 },
    { D_800A6460, D_800A6470, 0xD7 },
    { D_800A647C, D_800A648C, 0xD8 },
    { D_800A6498, D_800A64A8, 0xD8 },
    { NULL, NULL, 0 },
};
u16 D_800A65D4[] = { 0x7E05, 1, 0x7E1E, 1, 0x7095, 1, 0x7011, 0, 0xFFFF };
u16 D_800A65E8[] = { 0x7095, 1, 0x700B, 0, 0x7E04, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A65FC[] = { 0x7E04, 1, 0x7E20, 1, 0x7095, 1, 0x700F, 0, 0xFFFF };
u16 D_800A6610[] = { 0x7E04, 1, 0x7E1E, 1, 0x7095, 1, 0x700C, 0, 0xFFFF };
u16 D_800A6624[] = { 0x7E00, 1, 8, 0, 0xFFFF };
u16 D_800A6630[] = { 0x7E04, 1, 8, 0, 0xFFFF };
u16 D_800A663C[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A6648[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A6654[] = { 9, 0, 0x7E20, 1, 0xFFFF };
FieldActorEntry D_800A6660 = { D_800A65D4, D_800A64B4, 0x64, 4, 240, 600, 1 };
FieldActorEntry D_800A6674 = { D_800A65E8, D_800A64FC, 0x7B, 5, 240, 600, 1 };
FieldActorEntry D_800A6688 = { D_800A65FC, D_800A6544, 0x7D, 6, 240, 600, 1 };
FieldActorEntry D_800A669C = { D_800A6610, D_800A658C, 0x7E, 7, 240, 600, 1 };
FieldActorEntry D_800A66B0 = { NULL, NULL, 0x146, 8, 0, 0, 0 };
FieldActorEntry D_800A66C4 = { D_800A6624, NULL, 0x148, 9, 480, 208, 1 };
FieldActorEntry D_800A66D8 = { D_800A6630, NULL, 0x148, 9, 400, 344, 1 };
FieldActorEntry D_800A66EC = { D_800A663C, NULL, 0x15F, 0xA, 288, 400, 1 };
FieldActorEntry D_800A6700 = { D_800A6648, NULL, 0x15F, 0xA, 240, 488, 1 };
FieldActorEntry D_800A6714 = { D_800A6654, NULL, 0x15F, 0xA, 352, 272, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6660,
    &D_800A6674,
    &D_800A6688,
    &D_800A669C,
    &D_800A66B0,
    &D_800A66C4,
    &D_800A66D8,
    &D_800A66EC,
    &D_800A6700,
    &D_800A6714,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EB, 0x240, 0xA0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A679C = { 140, 10, 0x60080000 };
Battle D_800A67A8 = { 140, 10, 0x60080000 };
Battle D_800A67B4 = { 140, 10, 0x60080000 };
Battle D_800A67C0 = { 140, 10, 0x60080000 };
Battle D_800A67CC = { 141, 10, 0x60080000 };
Battle D_800A67D8 = { 141, 10, 0x60080000 };
Battle D_800A67E4 = { 141, 10, 0x60080000 };
Battle D_800A67F0 = { 141, 10, 0x60080000 };
BattleList D_800A67FC = {
    3,
    { &D_800A679C, &D_800A67A8, &D_800A67B4, &D_800A67C0,
      &D_800A67CC, &D_800A67D8, &D_800A67E4, &D_800A67F0 },
};
Battle D_800A6820 = { 0, 0, 0x60040000 };
Battle D_800A682C = { 0, 0, 0x60040000 };
Battle D_800A6838 = { 0, 0, 0x60040000 };
Battle D_800A6844 = { 0, 0, 0x60040000 };
Battle D_800A6850 = { 0, 0, 0x60040000 };
Battle D_800A685C = { 0, 0, 0x60040000 };
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
BattleList D_800A6880 = {
    0,
    { &D_800A6820, &D_800A682C, &D_800A6838, &D_800A6844,
      &D_800A6850, &D_800A685C, &D_800A6868, &D_800A6874 },
};
Battle D_800A68A4 = { 0, 0, 0x60040000 };
Battle D_800A68B0 = { 0, 0, 0x60040000 };
Battle D_800A68BC = { 0, 0, 0x60040000 };
Battle D_800A68C8 = { 0, 0, 0x60040000 };
Battle D_800A68D4 = { 0, 0, 0x60040000 };
Battle D_800A68E0 = { 0, 0, 0x60040000 };
Battle D_800A68EC = { 0, 0, 0x60040000 };
Battle D_800A68F8 = { 0, 0, 0x60040000 };
BattleList D_800A6904 = {
    0,
    { &D_800A68A4, &D_800A68B0, &D_800A68BC, &D_800A68C8,
      &D_800A68D4, &D_800A68E0, &D_800A68EC, &D_800A68F8 },
};
Battle D_800A6928 = { 0, 0, 0x60040000 };
Battle D_800A6934 = { 0, 0, 0x60040000 };
Battle D_800A6940 = { 0, 0, 0x60040000 };
Battle D_800A694C = { 0, 0, 0x60040000 };
Battle D_800A6958 = { 0, 0, 0x60040000 };
Battle D_800A6964 = { 0, 0, 0x60040000 };
Battle D_800A6970 = { 0, 0, 0x60040000 };
Battle D_800A697C = { 0, 0, 0x60040000 };
BattleList D_800A6988 = {
    0,
    { &D_800A6928, &D_800A6934, &D_800A6940, &D_800A694C,
      &D_800A6958, &D_800A6964, &D_800A6970, &D_800A697C },
};
Battle D_800A69AC = { 116, 10, 0x60080000 };
Battle D_800A69B8 = { 116, 10, 0x60080000 };
Battle D_800A69C4 = { 164, 10, 0x60080000 };
Battle D_800A69D0 = { 164, 10, 0x60080000 };
Battle D_800A69DC = { 139, 10, 0x60080000 };
Battle D_800A69E8 = { 139, 10, 0x60080000 };
Battle D_800A69F4 = { 163, 10, 0x60080000 };
Battle D_800A6A00 = { 163, 10, 0x60080000 };
BattleList D_800A6A0C = {
    3,
    { &D_800A69AC, &D_800A69B8, &D_800A69C4, &D_800A69D0,
      &D_800A69DC, &D_800A69E8, &D_800A69F4, &D_800A6A00 },
};
Battle D_800A6A30 = { 0, 0, 0x60040000 };
Battle D_800A6A3C = { 0, 0, 0x60040000 };
Battle D_800A6A48 = { 0, 0, 0x60040000 };
Battle D_800A6A54 = { 0, 0, 0x60040000 };
Battle D_800A6A60 = { 0, 0, 0x60040000 };
Battle D_800A6A6C = { 0, 0, 0x60040000 };
Battle D_800A6A78 = { 0, 0, 0x60040000 };
Battle D_800A6A84 = { 0, 0, 0x60040000 };
BattleList D_800A6A90 = {
    0,
    { &D_800A6A30, &D_800A6A3C, &D_800A6A48, &D_800A6A54,
      &D_800A6A60, &D_800A6A6C, &D_800A6A78, &D_800A6A84 },
};
Battle D_800A6AB4 = { 0, 0, 0x60040000 };
Battle D_800A6AC0 = { 0, 0, 0x60040000 };
Battle D_800A6ACC = { 0, 0, 0x60040000 };
Battle D_800A6AD8 = { 0, 0, 0x60040000 };
Battle D_800A6AE4 = { 0, 0, 0x60040000 };
Battle D_800A6AF0 = { 0, 0, 0x60040000 };
Battle D_800A6AFC = { 0, 0, 0x60040000 };
Battle D_800A6B08 = { 0, 0, 0x60040000 };
BattleList D_800A6B14 = {
    0,
    { &D_800A6AB4, &D_800A6AC0, &D_800A6ACC, &D_800A6AD8,
      &D_800A6AE4, &D_800A6AF0, &D_800A6AFC, &D_800A6B08 },
};
Battle D_800A6B38 = { 301, 10, 0x60880000 };
Battle D_800A6B44 = { 302, 10, 0x60880000 };
Battle D_800A6B50 = { 304, 10, 0x60880000 };
Battle D_800A6B5C = { 311, 10, 0x60880000 };
Battle D_800A6B68 = { 0, 0, 0x60040000 };
Battle D_800A6B74 = { 0, 0, 0x60040000 };
Battle D_800A6B80 = { 0, 0, 0x60040000 };
Battle D_800A6B8C = { 0, 0, 0x60040000 };
BattleList D_800A6B98 = {
    0,
    { &D_800A6B38, &D_800A6B44, &D_800A6B50, &D_800A6B5C,
      &D_800A6B68, &D_800A6B74, &D_800A6B80, &D_800A6B8C },
};
Battle D_800A6BBC = { 162, 10, 0x60080000 };
Battle D_800A6BC8 = { 162, 10, 0x60080000 };
Battle D_800A6BD4 = { 162, 10, 0x60080000 };
Battle D_800A6BE0 = { 162, 10, 0x60080000 };
Battle D_800A6BEC = { 135, 10, 0x60080000 };
Battle D_800A6BF8 = { 135, 10, 0x60080000 };
Battle D_800A6C04 = { 135, 10, 0x60080000 };
Battle D_800A6C10 = { 135, 10, 0x60080000 };
BattleList D_800A6C1C = {
    3,
    { &D_800A6BBC, &D_800A6BC8, &D_800A6BD4, &D_800A6BE0,
      &D_800A6BEC, &D_800A6BF8, &D_800A6C04, &D_800A6C10 },
};
Battle D_800A6C40 = { 0, 0, 0x60040000 };
Battle D_800A6C4C = { 0, 0, 0x60040000 };
Battle D_800A6C58 = { 0, 0, 0x60040000 };
Battle D_800A6C64 = { 0, 0, 0x60040000 };
Battle D_800A6C70 = { 0, 0, 0x60040000 };
Battle D_800A6C7C = { 0, 0, 0x60040000 };
Battle D_800A6C88 = { 0, 0, 0x60040000 };
Battle D_800A6C94 = { 0, 0, 0x60040000 };
BattleList D_800A6CA0 = {
    0,
    { &D_800A6C40, &D_800A6C4C, &D_800A6C58, &D_800A6C64,
      &D_800A6C70, &D_800A6C7C, &D_800A6C88, &D_800A6C94 },
};
Battle D_800A6CC4 = { 0, 0, 0x60040000 };
Battle D_800A6CD0 = { 0, 0, 0x60040000 };
Battle D_800A6CDC = { 0, 0, 0x60040000 };
Battle D_800A6CE8 = { 0, 0, 0x60040000 };
Battle D_800A6CF4 = { 0, 0, 0x60040000 };
Battle D_800A6D00 = { 0, 0, 0x60040000 };
Battle D_800A6D0C = { 0, 0, 0x60040000 };
Battle D_800A6D18 = { 0, 0, 0x60040000 };
BattleList D_800A6D24 = {
    0,
    { &D_800A6CC4, &D_800A6CD0, &D_800A6CDC, &D_800A6CE8,
      &D_800A6CF4, &D_800A6D00, &D_800A6D0C, &D_800A6D18 },
};
Battle D_800A6D48 = { 311, 10, 0x60880000 };
Battle D_800A6D54 = { 311, 10, 0x60880000 };
Battle D_800A6D60 = { 311, 10, 0x60880000 };
Battle D_800A6D6C = { 311, 10, 0x60880000 };
Battle D_800A6D78 = { 311, 10, 0x60880000 };
Battle D_800A6D84 = { 311, 10, 0x60880000 };
Battle D_800A6D90 = { 311, 10, 0x60880000 };
Battle D_800A6D9C = { 311, 10, 0x60880000 };
BattleList D_800A6DA8 = {
    0,
    { &D_800A6D48, &D_800A6D54, &D_800A6D60, &D_800A6D6C,
      &D_800A6D78, &D_800A6D84, &D_800A6D90, &D_800A6D9C },
};
FieldBattles stageBattles[] = {
    { 416, 1, 0, { &D_800A67FC, &D_800A6880, &D_800A6904, &D_800A6988 } },
    { 439, 5, 0, { &D_800A6A0C, &D_800A6A90, &D_800A6B14, &D_800A6B98 } },
    { 445, 6, 0, { &D_800A6C1C, &D_800A6CA0, &D_800A6D24, &D_800A6DA8 } },
};
