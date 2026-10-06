#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6F4;
    D_800990B4.sheetEntry = 0x93D0004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x93C;
    D_800990B4.start = (Vec2){0xEC00, 0x14D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x93D0006);
    D_8009A70C.setFile(7, 0x93D0007);
    D_8009A70C.setFile(4, 0x93D0005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60FC;
extern StagePoint D_800A6114;
extern StagePoint D_800A612C;
extern StagePoints D_800A610C;
extern StagePoints D_800A6124;
extern StagePoints D_800A613C;
extern u16 D_800A61D4[];
extern u16 D_800A61E0[];
extern u16 D_800A61EC[];
extern u16 D_800A6240[];
extern FieldTalk D_800A61F8[];
extern u16 D_800A6250[];
extern FieldTalk D_800A6210[];
extern u16 D_800A6260[];
extern FieldTalk D_800A6228[];
extern FieldActorEntry D_800A6270;
extern FieldActorEntry D_800A6284;
extern FieldActorEntry D_800A6298;
extern FieldActorEntry D_800A62AC;
extern Battle D_800A63F4;
extern Battle D_800A6400;
extern Battle D_800A640C;
extern Battle D_800A6418;
extern Battle D_800A6424;
extern Battle D_800A6430;
extern Battle D_800A643C;
extern Battle D_800A6448;
extern Battle D_800A6478;
extern Battle D_800A6484;
extern Battle D_800A6490;
extern Battle D_800A649C;
extern Battle D_800A64A8;
extern Battle D_800A64B4;
extern Battle D_800A64C0;
extern Battle D_800A64CC;
extern Battle D_800A64FC;
extern Battle D_800A6508;
extern Battle D_800A6514;
extern Battle D_800A6520;
extern Battle D_800A652C;
extern Battle D_800A6538;
extern Battle D_800A6544;
extern Battle D_800A6550;
extern Battle D_800A6580;
extern Battle D_800A658C;
extern Battle D_800A6598;
extern Battle D_800A65A4;
extern Battle D_800A65B0;
extern Battle D_800A65BC;
extern Battle D_800A65C8;
extern Battle D_800A65D4;
extern Battle D_800A6604;
extern Battle D_800A6610;
extern Battle D_800A661C;
extern Battle D_800A6628;
extern Battle D_800A6634;
extern Battle D_800A6640;
extern Battle D_800A664C;
extern Battle D_800A6658;
extern Battle D_800A6688;
extern Battle D_800A6694;
extern Battle D_800A66A0;
extern Battle D_800A66AC;
extern Battle D_800A66B8;
extern Battle D_800A66C4;
extern Battle D_800A66D0;
extern Battle D_800A66DC;
extern Battle D_800A670C;
extern Battle D_800A6718;
extern Battle D_800A6724;
extern Battle D_800A6730;
extern Battle D_800A673C;
extern Battle D_800A6748;
extern Battle D_800A6754;
extern Battle D_800A6760;
extern Battle D_800A6790;
extern Battle D_800A679C;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67CC;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A6814;
extern Battle D_800A6820;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6850;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6898;
extern Battle D_800A68A4;
extern Battle D_800A68B0;
extern Battle D_800A68BC;
extern Battle D_800A68C8;
extern Battle D_800A68D4;
extern Battle D_800A68E0;
extern Battle D_800A68EC;
extern Battle D_800A691C;
extern Battle D_800A6928;
extern Battle D_800A6934;
extern Battle D_800A6940;
extern Battle D_800A694C;
extern Battle D_800A6958;
extern Battle D_800A6964;
extern Battle D_800A6970;
extern Battle D_800A69A0;
extern Battle D_800A69AC;
extern Battle D_800A69B8;
extern Battle D_800A69C4;
extern Battle D_800A69D0;
extern Battle D_800A69DC;
extern Battle D_800A69E8;
extern Battle D_800A69F4;
extern BattleList D_800A6454;
extern BattleList D_800A64D8;
extern BattleList D_800A655C;
extern BattleList D_800A65E0;
extern BattleList D_800A6664;
extern BattleList D_800A66E8;
extern BattleList D_800A676C;
extern BattleList D_800A67F0;
extern BattleList D_800A6874;
extern BattleList D_800A68F8;
extern BattleList D_800A697C;
extern BattleList D_800A6A00;

StagePoint D_800A60FC = { 0x2E6, 3, 1, 160, 0x150, 5, NULL };
StagePoints D_800A610C = { 3, 1, &D_800A60FC };
StagePoint D_800A6114 = { 0x2E4, 4, 1, 192, 0x180, 5, NULL };
StagePoints D_800A6124 = { 4, 1, &D_800A6114 };
StagePoint D_800A612C = { 0x2E4, 5, 3, 192, 0x180, 5, NULL };
StagePoints D_800A613C = { 5, 1, &D_800A612C };
StagePoints *placePoints[] = {
    &D_800A610C, &D_800A6124, &D_800A613C, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x15F, 0xB8, 0x5F, 0x150, 0x1FF },
    { 0x140, 0x100, 0x160, 0x160, 0x80, 0x60, 0x160, 0x1FF },
};
u16 D_800A61D4[] = { 0x26E, 1, 0x8496, 1, 0xFFFF };
u16 D_800A61E0[] = { 0x272, 1, 0x8471, 1, 0xFFFF };
u16 D_800A61EC[] = { 0x271, 1, 0x8463, 1, 0xFFFF };
FieldTalk D_800A61F8[] = {
    { NULL, D_800A61D4, 6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6210[] = {
    { NULL, D_800A61E0, 0xA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6228[] = {
    { NULL, D_800A61EC, 9 },
    { NULL, NULL, 0 },
};
u16 D_800A6240[] = { 0x7E02, 1, 0x7E1E, 1, 0x26E, 0, 0xFFFF };
u16 D_800A6250[] = { 0x7E03, 1, 0x7E1E, 1, 0x272, 0, 0xFFFF };
u16 D_800A6260[] = { 0x7E04, 1, 0x7E1E, 1, 0x271, 0, 0xFFFF };
FieldActorEntry D_800A6270 = { D_800A6240, D_800A61F8, 0x21, 4, 192, 280, 1 };
FieldActorEntry D_800A6284 = { D_800A6250, D_800A6210, 0x21, 4, 192, 280, 1 };
FieldActorEntry D_800A6298 = { D_800A6260, D_800A6228, 0x21, 4, 192, 280, 1 };
FieldActorEntry D_800A62AC = { NULL, NULL, 0x147, 5, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A6270,
    &D_800A6284,
    &D_800A6298,
    &D_800A62AC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 360, 185, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 589, 120, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 268, 192, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 512, 122, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 110, 120, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 412, 114, 0, 0 },
    { 1, 0, 0x4A, 4, 0, 0, 0, 0, 0, 0, 416, 215, 288, 0 },
    { 1, 0, 0x61, 4, 1, 0, 0, 0, 0, 0, 384, 198, 288, 0 },
    { 1, 0, 0x5F, 4, 2, 0, 0, 0, 0, 0, 365, 191, 281, 0 },
    { 1, 0, 0x4F, 4, 3, 0, 0, 0, 0, 0, 592, 173, 251, 0 },
    { 1, 0, 0x63, 4, 4, 0, 0, 0, 0, 0, 560, 157, 247, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 541, 150, 240, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E7, 0x250, 0xE8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A63F4 = { 105, 11, 0x60080000 };
Battle D_800A6400 = { 105, 11, 0x60080000 };
Battle D_800A640C = { 105, 11, 0x60080000 };
Battle D_800A6418 = { 105, 11, 0x60080000 };
Battle D_800A6424 = { 105, 11, 0x60080000 };
Battle D_800A6430 = { 275, 11, 0x60080000 };
Battle D_800A643C = { 275, 11, 0x60080000 };
Battle D_800A6448 = { 275, 11, 0x60080000 };
BattleList D_800A6454 = {
    5,
    { &D_800A63F4, &D_800A6400, &D_800A640C, &D_800A6418,
      &D_800A6424, &D_800A6430, &D_800A643C, &D_800A6448 },
};
Battle D_800A6478 = { 0, 0, 0x60040000 };
Battle D_800A6484 = { 0, 0, 0x60040000 };
Battle D_800A6490 = { 0, 0, 0x60040000 };
Battle D_800A649C = { 0, 0, 0x60040000 };
Battle D_800A64A8 = { 0, 0, 0x60040000 };
Battle D_800A64B4 = { 0, 0, 0x60040000 };
Battle D_800A64C0 = { 0, 0, 0x60040000 };
Battle D_800A64CC = { 0, 0, 0x60040000 };
BattleList D_800A64D8 = {
    0,
    { &D_800A6478, &D_800A6484, &D_800A6490, &D_800A649C,
      &D_800A64A8, &D_800A64B4, &D_800A64C0, &D_800A64CC },
};
Battle D_800A64FC = { 0, 0, 0x60040000 };
Battle D_800A6508 = { 0, 0, 0x60040000 };
Battle D_800A6514 = { 0, 0, 0x60040000 };
Battle D_800A6520 = { 0, 0, 0x60040000 };
Battle D_800A652C = { 0, 0, 0x60040000 };
Battle D_800A6538 = { 0, 0, 0x60040000 };
Battle D_800A6544 = { 0, 0, 0x60040000 };
Battle D_800A6550 = { 0, 0, 0x60040000 };
BattleList D_800A655C = {
    0,
    { &D_800A64FC, &D_800A6508, &D_800A6514, &D_800A6520,
      &D_800A652C, &D_800A6538, &D_800A6544, &D_800A6550 },
};
Battle D_800A6580 = { 0, 0, 0x60040000 };
Battle D_800A658C = { 0, 0, 0x60040000 };
Battle D_800A6598 = { 0, 0, 0x60040000 };
Battle D_800A65A4 = { 0, 0, 0x60040000 };
Battle D_800A65B0 = { 0, 0, 0x60040000 };
Battle D_800A65BC = { 0, 0, 0x60040000 };
Battle D_800A65C8 = { 0, 0, 0x60040000 };
Battle D_800A65D4 = { 0, 0, 0x60040000 };
BattleList D_800A65E0 = {
    0,
    { &D_800A6580, &D_800A658C, &D_800A6598, &D_800A65A4,
      &D_800A65B0, &D_800A65BC, &D_800A65C8, &D_800A65D4 },
};
Battle D_800A6604 = { 179, 11, 0x60080000 };
Battle D_800A6610 = { 179, 11, 0x60080000 };
Battle D_800A661C = { 179, 11, 0x60080000 };
Battle D_800A6628 = { 179, 11, 0x60080000 };
Battle D_800A6634 = { 179, 11, 0x60080000 };
Battle D_800A6640 = { 274, 11, 0x60080000 };
Battle D_800A664C = { 274, 11, 0x60080000 };
Battle D_800A6658 = { 274, 11, 0x60080000 };
BattleList D_800A6664 = {
    5,
    { &D_800A6604, &D_800A6610, &D_800A661C, &D_800A6628,
      &D_800A6634, &D_800A6640, &D_800A664C, &D_800A6658 },
};
Battle D_800A6688 = { 0, 0, 0x60040000 };
Battle D_800A6694 = { 0, 0, 0x60040000 };
Battle D_800A66A0 = { 0, 0, 0x60040000 };
Battle D_800A66AC = { 0, 0, 0x60040000 };
Battle D_800A66B8 = { 0, 0, 0x60040000 };
Battle D_800A66C4 = { 0, 0, 0x60040000 };
Battle D_800A66D0 = { 0, 0, 0x60040000 };
Battle D_800A66DC = { 0, 0, 0x60040000 };
BattleList D_800A66E8 = {
    0,
    { &D_800A6688, &D_800A6694, &D_800A66A0, &D_800A66AC,
      &D_800A66B8, &D_800A66C4, &D_800A66D0, &D_800A66DC },
};
Battle D_800A670C = { 0, 0, 0x60040000 };
Battle D_800A6718 = { 0, 0, 0x60040000 };
Battle D_800A6724 = { 0, 0, 0x60040000 };
Battle D_800A6730 = { 0, 0, 0x60040000 };
Battle D_800A673C = { 0, 0, 0x60040000 };
Battle D_800A6748 = { 0, 0, 0x60040000 };
Battle D_800A6754 = { 0, 0, 0x60040000 };
Battle D_800A6760 = { 0, 0, 0x60040000 };
BattleList D_800A676C = {
    0,
    { &D_800A670C, &D_800A6718, &D_800A6724, &D_800A6730,
      &D_800A673C, &D_800A6748, &D_800A6754, &D_800A6760 },
};
Battle D_800A6790 = { 0, 0, 0x60040000 };
Battle D_800A679C = { 0, 0, 0x60040000 };
Battle D_800A67A8 = { 0, 0, 0x60040000 };
Battle D_800A67B4 = { 0, 0, 0x60040000 };
Battle D_800A67C0 = { 0, 0, 0x60040000 };
Battle D_800A67CC = { 0, 0, 0x60040000 };
Battle D_800A67D8 = { 0, 0, 0x60040000 };
Battle D_800A67E4 = { 0, 0, 0x60040000 };
BattleList D_800A67F0 = {
    0,
    { &D_800A6790, &D_800A679C, &D_800A67A8, &D_800A67B4,
      &D_800A67C0, &D_800A67CC, &D_800A67D8, &D_800A67E4 },
};
Battle D_800A6814 = { 185, 11, 0x60080000 };
Battle D_800A6820 = { 185, 11, 0x60080000 };
Battle D_800A682C = { 185, 11, 0x60080000 };
Battle D_800A6838 = { 185, 11, 0x60080000 };
Battle D_800A6844 = { 185, 11, 0x60080000 };
Battle D_800A6850 = { 277, 11, 0x60080000 };
Battle D_800A685C = { 277, 11, 0x60080000 };
Battle D_800A6868 = { 277, 11, 0x60080000 };
BattleList D_800A6874 = {
    4,
    { &D_800A6814, &D_800A6820, &D_800A682C, &D_800A6838,
      &D_800A6844, &D_800A6850, &D_800A685C, &D_800A6868 },
};
Battle D_800A6898 = { 0, 0, 0x60040000 };
Battle D_800A68A4 = { 0, 0, 0x60040000 };
Battle D_800A68B0 = { 0, 0, 0x60040000 };
Battle D_800A68BC = { 0, 0, 0x60040000 };
Battle D_800A68C8 = { 0, 0, 0x60040000 };
Battle D_800A68D4 = { 0, 0, 0x60040000 };
Battle D_800A68E0 = { 0, 0, 0x60040000 };
Battle D_800A68EC = { 0, 0, 0x60040000 };
BattleList D_800A68F8 = {
    0,
    { &D_800A6898, &D_800A68A4, &D_800A68B0, &D_800A68BC,
      &D_800A68C8, &D_800A68D4, &D_800A68E0, &D_800A68EC },
};
Battle D_800A691C = { 0, 0, 0x60040000 };
Battle D_800A6928 = { 0, 0, 0x60040000 };
Battle D_800A6934 = { 0, 0, 0x60040000 };
Battle D_800A6940 = { 0, 0, 0x60040000 };
Battle D_800A694C = { 0, 0, 0x60040000 };
Battle D_800A6958 = { 0, 0, 0x60040000 };
Battle D_800A6964 = { 0, 0, 0x60040000 };
Battle D_800A6970 = { 0, 0, 0x60040000 };
BattleList D_800A697C = {
    0,
    { &D_800A691C, &D_800A6928, &D_800A6934, &D_800A6940,
      &D_800A694C, &D_800A6958, &D_800A6964, &D_800A6970 },
};
Battle D_800A69A0 = { 0, 0, 0x60040000 };
Battle D_800A69AC = { 0, 0, 0x60040000 };
Battle D_800A69B8 = { 0, 0, 0x60040000 };
Battle D_800A69C4 = { 0, 0, 0x60040000 };
Battle D_800A69D0 = { 0, 0, 0x60040000 };
Battle D_800A69DC = { 0, 0, 0x60040000 };
Battle D_800A69E8 = { 0, 0, 0x60040000 };
Battle D_800A69F4 = { 0, 0, 0x60040000 };
BattleList D_800A6A00 = {
    0,
    { &D_800A69A0, &D_800A69AC, &D_800A69B8, &D_800A69C4,
      &D_800A69D0, &D_800A69DC, &D_800A69E8, &D_800A69F4 },
};
FieldBattles stageBattles[] = {
    { 405, 3, 0, { &D_800A6454, &D_800A64D8, &D_800A655C, &D_800A65E0 } },
    { 409, 4, 0, { &D_800A6664, &D_800A66E8, &D_800A676C, &D_800A67F0 } },
    { 413, 5, 0, { &D_800A6874, &D_800A68F8, &D_800A697C, &D_800A6A00 } },
};
