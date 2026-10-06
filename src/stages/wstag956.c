#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x783;
    D_800990B4.sheetEntry = 0x9270000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x926;
    D_800990B4.start = (Vec2){0x1D100, 0x1F600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xC;
    D_800990B4.music = 0x60300000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9270001);
    D_8009A70C.setFile(7, 0x9270002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A604C[];
extern u16 D_800A6058[];
extern u16 D_800A6064[];
extern u16 D_800A6070[];
extern u16 D_800A6080[];
extern u16 D_800A608C[];
extern u16 D_800A6094[];
extern u16 D_800A60A0[];
extern u16 D_800A60A8[];
extern u16 D_800A60B0[];
extern u16 D_800A60BC[];
extern u16 D_800A60C8[];
extern u16 D_800A60D4[];
extern u16 D_800A60E0[];
extern u16 D_800A60EC[];
extern u16 D_800A60F8[];
extern u16 D_800A6108[];
extern u16 D_800A6114[];
extern u16 D_800A611C[];
extern u16 D_800A6128[];
extern u16 D_800A6268[];
extern FieldTalk D_800A6130[];
extern u16 D_800A6270[];
extern FieldTalk D_800A6148[];
extern FieldTalk D_800A6184[];
extern FieldTalk D_800A619C[];
extern FieldTalk D_800A61B4[];
extern FieldTalk D_800A61CC[];
extern u16 D_800A6278[];
extern FieldTalk D_800A61FC[];
extern u16 D_800A6280[];
extern FieldTalk D_800A6214[];
extern FieldTalk D_800A6250[];
extern FieldActorEntry D_800A6288;
extern FieldActorEntry D_800A629C;
extern FieldActorEntry D_800A62B0;
extern FieldActorEntry D_800A62C4;
extern FieldActorEntry D_800A62D8;
extern FieldActorEntry D_800A62EC;
extern FieldActorEntry D_800A6300;
extern FieldActorEntry D_800A6314;
extern FieldActorEntry D_800A6328;
extern Battle D_800A66A0;
extern Battle D_800A66AC;
extern Battle D_800A66B8;
extern Battle D_800A66C4;
extern Battle D_800A66D0;
extern Battle D_800A66DC;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6724;
extern Battle D_800A6730;
extern Battle D_800A673C;
extern Battle D_800A6748;
extern Battle D_800A6754;
extern Battle D_800A6760;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67CC;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6850;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern BattleList D_800A6700;
extern BattleList D_800A6784;
extern BattleList D_800A6808;
extern BattleList D_800A688C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x179, 0x1CE, 0xE4, 0xCE, 0x140, 0x1FF },
    { 0x140, 0x100, 0x14E, 0x1DC, 0x38, 0xDC, 0x150, 0x1FF },
    { 0x1C0, 0x100, 0x1D0, 0x100, 0x240, 0, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1B0, 0x1AE, 0x1C0, 0xAE, 0x170, 0x1FF },
    { 0x1C0, 0x100, 0x1D8, 0x100, 0x260, 0, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1A4, 0x140, 0x190, 0x40, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1F4, 0x100, 0x2D0, 0, 0x160, 0x1FE },
};
u16 D_800A604C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6058[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A6064[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6070[] = { 0x11, 0, 0x10, 0, 1, 0, 0xFFFF };
u16 D_800A6080[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A608C[] = { 1, 1, 0xFFFF };
u16 D_800A6094[] = { 0x11, 0, 1, 1, 0xFFFF };
u16 D_800A60A0[] = { 0x7845, 1, 0xFFFF };
u16 D_800A60A8[] = { 0x7096, 0, 0xFFFF };
u16 D_800A60B0[] = { 0x7096, 1, 0x100D, 0, 0xFFFF };
u16 D_800A60BC[] = { 0x100D, 1, 0x7400, 1, 0xFFFF };
u16 D_800A60C8[] = { 0x7096, 1, 0x100D, 1, 0xFFFF };
u16 D_800A60D4[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A60E0[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A60EC[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A60F8[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6108[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6114[] = { 0, 1, 0xFFFF };
u16 D_800A611C[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6128[] = { 0x784B, 1, 0xFFFF };
FieldTalk D_800A6130[] = {
    { NULL, NULL, 0x5E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6148[] = {
    { D_800A604C, D_800A6058, 0x60 },
    { D_800A6064, D_800A6070, 0x61 },
    { D_800A6080, D_800A608C, 0x5E },
    { D_800A6094, D_800A60A0, 0x5F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6184[] = {
    { NULL, NULL, 0x76 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A619C[] = {
    { NULL, NULL, 0x75 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61B4[] = {
    { NULL, NULL, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61CC[] = {
    { D_800A60A8, NULL, 0x72 },
    { D_800A60B0, D_800A60BC, 0x73 },
    { D_800A60C8, NULL, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61FC[] = {
    { NULL, NULL, 0x5A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6214[] = {
    { D_800A60D4, D_800A60E0, 0x5C },
    { D_800A60EC, D_800A60F8, 0x5D },
    { D_800A6108, D_800A6114, 0x5A },
    { D_800A611C, D_800A6128, 0x5B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6250[] = {
    { NULL, NULL, 0x78 },
    { NULL, NULL, 0 },
};
u16 D_800A6268[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6270[] = { 0x8192, 1, 0xFFFF };
u16 D_800A6278[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6280[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A6288 = { D_800A6268, D_800A6130, 0x2D, 4, 623, 408, 7 };
FieldActorEntry D_800A629C = { D_800A6270, D_800A6148, 0x2D, 4, 623, 408, 7 };
FieldActorEntry D_800A62B0 = { NULL, D_800A6184, 0x2E, 5, 592, 424, 5 };
FieldActorEntry D_800A62C4 = { NULL, D_800A619C, 0x31, 6, 449, 481, 1 };
FieldActorEntry D_800A62D8 = { NULL, D_800A61B4, 0x86, 7, 1088, 400, 7 };
FieldActorEntry D_800A62EC = { NULL, D_800A61CC, 0x8F, 8, 352, 234, 1 };
FieldActorEntry D_800A6300 = { D_800A6278, D_800A61FC, 0xB3, 9, 914, 344, 7 };
FieldActorEntry D_800A6314 = { D_800A6280, D_800A6214, 0xB3, 9, 914, 344, 7 };
FieldActorEntry D_800A6328 = { NULL, D_800A6250, 0x175, 0xA, 833, 257, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A6288,
    &D_800A629C,
    &D_800A62B0,
    &D_800A62C4,
    &D_800A62D8,
    &D_800A62EC,
    &D_800A6300,
    &D_800A6314,
    &D_800A6328,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 441, 290, 0, 0 },
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 817, 114, 0, 0 },
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 949, 528, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 366, 274, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 446, 241, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 1129, 333, 0, 0 },
    { 1, 0, 0x80, 2, 0x24, 0, 0, 0, 0, 0, 469, 191, 0, 0 },
    { 1, 0, 0x80, 2, 0x25, 0, 0, 0, 0, 0, 256, 161, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 411, 424, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 538, 379, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 568, 341, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 607, 347, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 976, 215, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 544, 363, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 579, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 884, 243, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 913, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 1020, 218, 0, 0 },
    { 1, 0, 0x40, 6, 0x10, 1, 0x10, 0x12, 4, 0, 906, 526, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x1B, 0, 0, 0, 0, 0, 721, 200, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x1C, 0, 0, 0, 0, 0, 451, 367, 0, 0 },
    { 1, 0, 0x40, 4, 8, 1, 8, 0xB, 4, 0, 448, 405, 445, 0 },
    { 1, 0, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 465, 438, 464, 0 },
    { 1, 0, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 737, 256, 281, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 898, 552, 576, 0 },
    { 1, 0, 0x40, 4, 0x19, 0, 0, 0, 0, 0, 727, 260, 280, 0 },
    { 1, 0, 0x40, 4, 0x1A, 0, 0, 0, 0, 0, 447, 417, 444, 0 },
    { 1, 0, 0x64, 4, 0x1D, 0, 0, 0, 0, 0, 784, 496, 560, 0 },
    { 1, 0, 0x64, 4, 0x1E, 0, 0, 0, 0, 0, 768, 488, 552, 0 },
    { 1, 0, 0x64, 4, 0x1F, 0, 0, 0, 0, 0, 752, 480, 544, 0 },
    { 1, 0, 0x64, 4, 0x20, 0, 0, 0, 0, 0, 736, 472, 536, 0 },
    { 1, 0, 0x64, 4, 0x21, 0, 0, 0, 0, 0, 720, 464, 528, 0 },
    { 1, 0, 0x64, 4, 0x22, 0, 0, 0, 0, 0, 704, 456, 520, 0 },
    { 1, 0, 0x64, 4, 0x23, 0, 0, 0, 0, 0, 672, 456, 496, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x298, 0x448, 0xF8, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29E, 0xC8, 0x1A4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29E, 0x1B8, 0x204, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29D, 0x208, 0x1AC, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29F, 0x1A7, 0x254, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x400, 0x120, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x410, 0x188, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A66A0 = { 0, 0, 0x60040000 };
Battle D_800A66AC = { 0, 0, 0x60040000 };
Battle D_800A66B8 = { 0, 0, 0x60040000 };
Battle D_800A66C4 = { 0, 0, 0x60040000 };
Battle D_800A66D0 = { 0, 0, 0x60040000 };
Battle D_800A66DC = { 0, 0, 0x60040000 };
Battle D_800A66E8 = { 0, 0, 0x60040000 };
Battle D_800A66F4 = { 0, 0, 0x60040000 };
BattleList D_800A6700 = {
    3,
    { &D_800A66A0, &D_800A66AC, &D_800A66B8, &D_800A66C4,
      &D_800A66D0, &D_800A66DC, &D_800A66E8, &D_800A66F4 },
};
Battle D_800A6724 = { 0, 0, 0x60040000 };
Battle D_800A6730 = { 0, 0, 0x60040000 };
Battle D_800A673C = { 0, 0, 0x60040000 };
Battle D_800A6748 = { 0, 0, 0x60040000 };
Battle D_800A6754 = { 0, 0, 0x60040000 };
Battle D_800A6760 = { 0, 0, 0x60040000 };
Battle D_800A676C = { 0, 0, 0x60040000 };
Battle D_800A6778 = { 0, 0, 0x60040000 };
BattleList D_800A6784 = {
    0,
    { &D_800A6724, &D_800A6730, &D_800A673C, &D_800A6748,
      &D_800A6754, &D_800A6760, &D_800A676C, &D_800A6778 },
};
Battle D_800A67A8 = { 0, 0, 0x60040000 };
Battle D_800A67B4 = { 0, 0, 0x60040000 };
Battle D_800A67C0 = { 0, 0, 0x60040000 };
Battle D_800A67CC = { 0, 0, 0x60040000 };
Battle D_800A67D8 = { 0, 0, 0x60040000 };
Battle D_800A67E4 = { 0, 0, 0x60040000 };
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
BattleList D_800A6808 = {
    0,
    { &D_800A67A8, &D_800A67B4, &D_800A67C0, &D_800A67CC,
      &D_800A67D8, &D_800A67E4, &D_800A67F0, &D_800A67FC },
};
Battle D_800A682C = { 305, 18, 0x608C0000 };
Battle D_800A6838 = { 0, 0, 0x60040000 };
Battle D_800A6844 = { 0, 0, 0x60040000 };
Battle D_800A6850 = { 0, 0, 0x60040000 };
Battle D_800A685C = { 0, 0, 0x60040000 };
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 0, 0, 0x60040000 };
BattleList D_800A688C = {
    0,
    { &D_800A682C, &D_800A6838, &D_800A6844, &D_800A6850,
      &D_800A685C, &D_800A6868, &D_800A6874, &D_800A6880 },
};
FieldBattles stageBattles[] = {
    { 393, 0, 0, { &D_800A6700, &D_800A6784, &D_800A6808, &D_800A688C } },
};
