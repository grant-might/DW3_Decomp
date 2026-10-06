#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x3A5;
    D_800990B4.sheetEntry = 0x90D0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x90C;
    D_800990B4.start = (Vec2){0x6E00, 0xB600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x90D0002);
    D_8009A70C.setFile(7, 0x90D0003);
    D_8009A70C.setFile(4, 0x90D0001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A602C[];
extern u16 D_800A6038[];
extern u16 D_800A6044[];
extern u16 D_800A6050[];
extern u16 D_800A6060[];
extern u16 D_800A606C[];
extern u16 D_800A6074[];
extern u16 D_800A6080[];
extern u16 D_800A6088[];
extern u16 D_800A6090[];
extern u16 D_800A6098[];
extern u16 D_800A60A4[];
extern u16 D_800A60B4[];
extern u16 D_800A60C0[];
extern u16 D_800A6160[];
extern FieldTalk D_800A60D0[];
extern u16 D_800A6168[];
extern FieldTalk D_800A60E8[];
extern FieldTalk D_800A6124[];
extern FieldActorEntry D_800A6170;
extern FieldActorEntry D_800A6184;
extern FieldActorEntry D_800A6198;
extern Battle D_800A6684;
extern Battle D_800A6690;
extern Battle D_800A669C;
extern Battle D_800A66A8;
extern Battle D_800A66B4;
extern Battle D_800A66C0;
extern Battle D_800A66CC;
extern Battle D_800A66D8;
extern Battle D_800A6708;
extern Battle D_800A6714;
extern Battle D_800A6720;
extern Battle D_800A672C;
extern Battle D_800A6738;
extern Battle D_800A6744;
extern Battle D_800A6750;
extern Battle D_800A675C;
extern Battle D_800A678C;
extern Battle D_800A6798;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67D4;
extern Battle D_800A67E0;
extern Battle D_800A6810;
extern Battle D_800A681C;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A6858;
extern Battle D_800A6864;
extern BattleList D_800A66E4;
extern BattleList D_800A6768;
extern BattleList D_800A67EC;
extern BattleList D_800A6870;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x137, 0xD8, 0x37, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x177, 0xD8, 0x77, 0x160, 0x1FF },
};
u16 D_800A602C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6038[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6044[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6050[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6060[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A606C[] = { 0, 1, 0xFFFF };
u16 D_800A6074[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6080[] = { 0x782B, 1, 0xFFFF };
u16 D_800A6088[] = { 5, 0, 0xFFFF };
u16 D_800A6090[] = { 5, 1, 0xFFFF };
u16 D_800A6098[] = { 5, 1, 0x8192, 0, 0xFFFF };
u16 D_800A60A4[] = { 5, 1, 0x8004, 0, 0x8192, 1, 0xFFFF };
u16 D_800A60B4[] = { 0x8004, 1, 0x7013, 1, 0xFFFF };
u16 D_800A60C0[] = { 5, 1, 0x8004, 1, 0x8192, 1, 0xFFFF };
FieldTalk D_800A60D0[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60E8[] = {
    { D_800A602C, D_800A6038, 0x27 },
    { D_800A6044, D_800A6050, 0x28 },
    { D_800A6060, D_800A606C, 0x25 },
    { D_800A6074, D_800A6080, 0x26 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6124[] = {
    { D_800A6088, D_800A6090, 0x7A },
    { D_800A6098, NULL, 0x7C },
    { D_800A60A4, D_800A60B4, 0x7B },
    { D_800A60C0, NULL, 0x7C },
    { NULL, NULL, 0 },
};
u16 D_800A6160[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6168[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A6170 = { D_800A6160, D_800A60D0, 0x31, 4, 656, 648, 7 };
FieldActorEntry D_800A6184 = { D_800A6168, D_800A60E8, 0x31, 4, 656, 648, 7 };
FieldActorEntry D_800A6198 = { NULL, D_800A6124, 0x11B, 5, 967, 901, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6170,
    &D_800A6184,
    &D_800A6198,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 330, 524, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 922, 950, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 256, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 176, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 212, 597, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 534, 857, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 646, 785, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 820, 685, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 874, 498, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 139, 93, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 148, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 154, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 460, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 651, 773, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 750, 724, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 842, 515, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 185, 199, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 291, 768, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 398, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 480, 897, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 608, 960, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 693, 1010, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 213, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 422, 830, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 462, 898, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 569, 865, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 647, 985, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 680, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 165, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 170, 169, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 258, 270, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 323, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 434, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 595, 944, 0, 0 },
    { 1, 0, 0xFF, 6, 8, 0, 0, 0, 0, 0, 703, 232, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 593, 792, 804, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 623, 849, 864, 0 },
    { 1, 0, 0x80, 4, 9, 0, 0, 0, 0, 0, 631, 378, 433, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 333, 235, 235, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 381, 259, 259, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 429, 283, 283, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 481, 532, 532, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 486, 775, 775, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 557, 557, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 533, 751, 751, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 541, 699, 699, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 574, 580, 580, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1014, 879, 879, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x1D2, 0x92, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xC, 0x231, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xC, 0x221, 0x178, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 5, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 0, 0, 5, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 0, 0, 3, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFA2, 0x10, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x28, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0x29, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6684 = { 40, 13, 0x60080000 };
Battle D_800A6690 = { 40, 13, 0x60080000 };
Battle D_800A669C = { 40, 13, 0x60080000 };
Battle D_800A66A8 = { 40, 13, 0x60080000 };
Battle D_800A66B4 = { 45, 13, 0x60080000 };
Battle D_800A66C0 = { 45, 13, 0x60080000 };
Battle D_800A66CC = { 45, 13, 0x60080000 };
Battle D_800A66D8 = { 45, 13, 0x60080000 };
BattleList D_800A66E4 = {
    3,
    { &D_800A6684, &D_800A6690, &D_800A669C, &D_800A66A8,
      &D_800A66B4, &D_800A66C0, &D_800A66CC, &D_800A66D8 },
};
Battle D_800A6708 = { 51, 4, 0x60080000 };
Battle D_800A6714 = { 51, 4, 0x60080000 };
Battle D_800A6720 = { 51, 4, 0x60080000 };
Battle D_800A672C = { 51, 4, 0x60080000 };
Battle D_800A6738 = { 52, 4, 0x60080000 };
Battle D_800A6744 = { 52, 4, 0x60080000 };
Battle D_800A6750 = { 52, 4, 0x60080000 };
Battle D_800A675C = { 52, 4, 0x60080000 };
BattleList D_800A6768 = {
    3,
    { &D_800A6708, &D_800A6714, &D_800A6720, &D_800A672C,
      &D_800A6738, &D_800A6744, &D_800A6750, &D_800A675C },
};
Battle D_800A678C = { 65, 2, 0x60080000 };
Battle D_800A6798 = { 65, 2, 0x60080000 };
Battle D_800A67A4 = { 65, 2, 0x60080000 };
Battle D_800A67B0 = { 65, 2, 0x60080000 };
Battle D_800A67BC = { 60, 2, 0x60080000 };
Battle D_800A67C8 = { 60, 2, 0x60080000 };
Battle D_800A67D4 = { 60, 2, 0x60080000 };
Battle D_800A67E0 = { 60, 2, 0x60080000 };
BattleList D_800A67EC = {
    3,
    { &D_800A678C, &D_800A6798, &D_800A67A4, &D_800A67B0,
      &D_800A67BC, &D_800A67C8, &D_800A67D4, &D_800A67E0 },
};
Battle D_800A6810 = { 0, 0, 0x60040000 };
Battle D_800A681C = { 0, 0, 0x60040000 };
Battle D_800A6828 = { 0, 0, 0x60040000 };
Battle D_800A6834 = { 329, 13, 0x60080000 };
Battle D_800A6840 = { 332, 2, 0x60080000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
Battle D_800A6858 = { 156, 13, 0x60080000 };
Battle D_800A6864 = { 179, 2, 0x60080000 };
BattleList D_800A6870 = {
    0,
    { &D_800A6810, &D_800A681C, &D_800A6828, &D_800A6834,
      &D_800A6840, &D_800A684C, &D_800A6858, &D_800A6864 },
};
FieldBattles stageBattles[] = {
    { 382, 0, 0, { &D_800A66E4, &D_800A6768, &D_800A67EC, &D_800A6870 } },
};
