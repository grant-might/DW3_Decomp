#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x3A1;
    D_800990B4.sheetEntry = 0x90B0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x90A;
    D_800990B4.start = (Vec2){0x30700, 0x9A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x90B0002);
    D_8009A70C.setFile(7, 0x90B0003);
    D_8009A70C.setFile(4, 0x90B0001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6050[];
extern u16 D_800A605C[];
extern u16 D_800A6068[];
extern u16 D_800A6074[];
extern u16 D_800A6084[];
extern u16 D_800A6090[];
extern u16 D_800A6098[];
extern u16 D_800A60A4[];
extern u16 D_800A60AC[];
extern u16 D_800A60B4[];
extern u16 D_800A60BC[];
extern u16 D_800A60C8[];
extern u16 D_800A60D8[];
extern u16 D_800A60E4[];
extern u16 D_800A61B4[];
extern FieldTalk D_800A60F4[];
extern u16 D_800A61BC[];
extern FieldTalk D_800A610C[];
extern FieldTalk D_800A6148[];
extern FieldTalk D_800A6160[];
extern FieldTalk D_800A619C[];
extern FieldActorEntry D_800A61C4;
extern FieldActorEntry D_800A61D8;
extern FieldActorEntry D_800A61EC;
extern FieldActorEntry D_800A6200;
extern FieldActorEntry D_800A6214;
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
extern BattleList D_800A6664;
extern BattleList D_800A66E8;
extern BattleList D_800A676C;
extern BattleList D_800A67F0;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x151, 0xC8, 0x51, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x179, 0xC8, 0x79, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1A8, 0x100, 0x1A0, 0, 0x140, 0x1FE },
};
u16 D_800A6050[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A605C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6068[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6074[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6084[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6090[] = { 0, 1, 0xFFFF };
u16 D_800A6098[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A60A4[] = { 0x7841, 1, 0xFFFF };
u16 D_800A60AC[] = { 5, 0, 0xFFFF };
u16 D_800A60B4[] = { 5, 1, 0xFFFF };
u16 D_800A60BC[] = { 5, 1, 0x8192, 0, 0xFFFF };
u16 D_800A60C8[] = { 5, 1, 0x8005, 0, 0x8192, 1, 0xFFFF };
u16 D_800A60D8[] = { 0x8005, 1, 0x7013, 1, 0xFFFF };
u16 D_800A60E4[] = { 5, 1, 0x8005, 1, 0x8192, 1, 0xFFFF };
FieldTalk D_800A60F4[] = {
    { NULL, NULL, 0x21 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A610C[] = {
    { D_800A6050, D_800A605C, 0x23 },
    { D_800A6068, D_800A6074, 0x24 },
    { D_800A6084, D_800A6090, 0x21 },
    { D_800A6098, D_800A60A4, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6148[] = {
    { NULL, NULL, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6160[] = {
    { D_800A60AC, D_800A60B4, 0x75 },
    { D_800A60BC, NULL, 0x77 },
    { D_800A60C8, D_800A60D8, 0x76 },
    { D_800A60E4, NULL, 0x77 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A619C[] = {
    { NULL, NULL, 0x79 },
    { NULL, NULL, 0 },
};
u16 D_800A61B4[] = { 0x8192, 0, 0xFFFF };
u16 D_800A61BC[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A61C4 = { D_800A61B4, D_800A60F4, 0x36, 4, 288, 424, 1 };
FieldActorEntry D_800A61D8 = { D_800A61BC, D_800A610C, 0x36, 4, 288, 424, 1 };
FieldActorEntry D_800A61EC = { NULL, D_800A6148, 0x8C, 5, 640, 593, 7 };
FieldActorEntry D_800A6200 = { NULL, D_800A6160, 0x11A, 6, 412, 642, 1 };
FieldActorEntry D_800A6214 = { NULL, D_800A619C, 0x171, 7, 299, 282, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A61C4,
    &D_800A61D8,
    &D_800A61EC,
    &D_800A6200,
    &D_800A6214,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 5, 1, 5, 0xA, 8, 0, 395, 85, 0, 0 },
    { 1, 0, 0x40, 2, 5, 1, 5, 0xA, 8, 0, 698, 285, 0, 0 },
    { 1, 0, 0x50, 2, 0xB, 0, 0, 0, 0, 0, 688, 97, 0, 0 },
    { 1, 0, 0x72, 2, 0xC, 0, 0, 0, 0, 0, 784, 47, 0, 0 },
    { 1, 0, 0x80, 2, 0xD, 0, 0, 0, 0, 0, 640, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 72, 562, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 271, 529, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 677, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 224, 557, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 309, 704, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 290, 716, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 698, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 83, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 47, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 146, 531, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 37, 375, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 90, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 218, 638, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 75, 550, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 96, 549, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 182, 545, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 288, 706, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 310, 714, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 321, 691, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 494, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 514, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 671, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 799, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 811, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 817, 43, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 496, 558, 575, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 509, 517, 543, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 514, 471, 489, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 676, 390, 407, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 276, 499, 511, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 271, 271, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 239, 239, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 255, 255, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 390, 243, 243, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 247, 247, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 592, 343, 343, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 375, 375, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x102, 0x3AC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 4, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x3C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x40, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6604 = { 42, 1, 0x60080000 };
Battle D_800A6610 = { 42, 1, 0x60080000 };
Battle D_800A661C = { 42, 1, 0x60080000 };
Battle D_800A6628 = { 42, 1, 0x60080000 };
Battle D_800A6634 = { 43, 1, 0x60080000 };
Battle D_800A6640 = { 43, 1, 0x60080000 };
Battle D_800A664C = { 43, 1, 0x60080000 };
Battle D_800A6658 = { 43, 1, 0x60080000 };
BattleList D_800A6664 = {
    3,
    { &D_800A6604, &D_800A6610, &D_800A661C, &D_800A6628,
      &D_800A6634, &D_800A6640, &D_800A664C, &D_800A6658 },
};
Battle D_800A6688 = { 36, 2, 0x60080000 };
Battle D_800A6694 = { 36, 2, 0x60080000 };
Battle D_800A66A0 = { 36, 2, 0x60080000 };
Battle D_800A66AC = { 36, 2, 0x60080000 };
Battle D_800A66B8 = { 37, 2, 0x60080000 };
Battle D_800A66C4 = { 37, 2, 0x60080000 };
Battle D_800A66D0 = { 37, 2, 0x60080000 };
Battle D_800A66DC = { 37, 2, 0x60080000 };
BattleList D_800A66E8 = {
    3,
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
Battle D_800A67B4 = { 327, 13, 0x60080000 };
Battle D_800A67C0 = { 328, 2, 0x60080000 };
Battle D_800A67CC = { 0, 0, 0x60040000 };
Battle D_800A67D8 = { 48, 13, 0x60080000 };
Battle D_800A67E4 = { 59, 2, 0x60080000 };
BattleList D_800A67F0 = {
    0,
    { &D_800A6790, &D_800A679C, &D_800A67A8, &D_800A67B4,
      &D_800A67C0, &D_800A67CC, &D_800A67D8, &D_800A67E4 },
};
FieldBattles stageBattles[] = {
    { 381, 0, 0, { &D_800A6664, &D_800A66E8, &D_800A676C, &D_800A67F0 } },
};
