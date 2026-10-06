#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x1BA;
    D_800990B4.sheetEntry = 0x9110000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x910;
    D_800990B4.start = (Vec2){0x13800, 0x27100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2D;
    D_800990B4.music = 0x60B40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9110002);
    D_8009A70C.setFile(7, 0x9110003);
    D_8009A70C.setFile(4, 0x9110001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6044[];
extern u16 D_800A6050[];
extern u16 D_800A605C[];
extern u16 D_800A6068[];
extern u16 D_800A6078[];
extern u16 D_800A6084[];
extern u16 D_800A608C[];
extern u16 D_800A6098[];
extern u16 D_800A60A0[];
extern u16 D_800A60AC[];
extern u16 D_800A60B8[];
extern u16 D_800A60C4[];
extern u16 D_800A60D4[];
extern u16 D_800A60E0[];
extern u16 D_800A60E8[];
extern u16 D_800A60F4[];
extern u16 D_800A61EC[];
extern FieldTalk D_800A60FC[];
extern u16 D_800A61F4[];
extern FieldTalk D_800A6114[];
extern FieldTalk D_800A6150[];
extern u16 D_800A61FC[];
extern FieldTalk D_800A6168[];
extern u16 D_800A6204[];
extern FieldTalk D_800A6180[];
extern FieldTalk D_800A61BC[];
extern FieldTalk D_800A61D4[];
extern FieldActorEntry D_800A620C;
extern FieldActorEntry D_800A6220;
extern FieldActorEntry D_800A6234;
extern FieldActorEntry D_800A6248;
extern FieldActorEntry D_800A625C;
extern FieldActorEntry D_800A6270;
extern FieldActorEntry D_800A6284;
extern Battle D_800A66AC;
extern Battle D_800A66B8;
extern Battle D_800A66C4;
extern Battle D_800A66D0;
extern Battle D_800A66DC;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6700;
extern Battle D_800A6730;
extern Battle D_800A673C;
extern Battle D_800A6748;
extern Battle D_800A6754;
extern Battle D_800A6760;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A6784;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67CC;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A6808;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6850;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern Battle D_800A688C;
extern BattleList D_800A670C;
extern BattleList D_800A6790;
extern BattleList D_800A6814;
extern BattleList D_800A6898;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x176, 0xC0, 0x76, 0x150, 0x1FF },
    { 0x140, 0x100, 0x170, 0x19E, 0xC0, 0x9E, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1C6, 0xC0, 0xC6, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x150, 0x1FE },
};
u16 D_800A6044[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6050[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A605C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6068[] = { 0x11, 0, 0x10, 0, 1, 0, 0xFFFF };
u16 D_800A6078[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A6084[] = { 1, 1, 0xFFFF };
u16 D_800A608C[] = { 0x11, 0, 1, 1, 0xFFFF };
u16 D_800A6098[] = { 0x783C, 1, 0xFFFF };
u16 D_800A60A0[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A60AC[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A60B8[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A60C4[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A60D4[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A60E0[] = { 0, 1, 0xFFFF };
u16 D_800A60E8[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A60F4[] = { 0x7835, 1, 0xFFFF };
FieldTalk D_800A60FC[] = {
    { NULL, NULL, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6114[] = {
    { D_800A6044, D_800A6050, 0x33 },
    { D_800A605C, D_800A6068, 0x34 },
    { D_800A6078, D_800A6084, 0x31 },
    { D_800A608C, D_800A6098, 0x32 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6150[] = {
    { NULL, NULL, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6168[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6180[] = {
    { D_800A60A0, D_800A60AC, 0x2F },
    { D_800A60B8, D_800A60C4, 0x30 },
    { D_800A60D4, D_800A60E0, 0x2D },
    { D_800A60E8, D_800A60F4, 0x2E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61BC[] = {
    { NULL, NULL, 0x7F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61D4[] = {
    { NULL, NULL, 0x80 },
    { NULL, NULL, 0 },
};
u16 D_800A61EC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A61F4[] = { 0x8192, 1, 0xFFFF };
u16 D_800A61FC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6204[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A620C = { D_800A61EC, D_800A60FC, 0x30, 4, 361, 749, 7 };
FieldActorEntry D_800A6220 = { D_800A61F4, D_800A6114, 0x30, 4, 361, 749, 7 };
FieldActorEntry D_800A6234 = { NULL, D_800A6150, 0x33, 5, 768, 664, 3 };
FieldActorEntry D_800A6248 = { D_800A61FC, D_800A6168, 0x35, 6, 319, 313, 1 };
FieldActorEntry D_800A625C = { D_800A6204, D_800A6180, 0x35, 6, 319, 313, 1 };
FieldActorEntry D_800A6270 = { NULL, D_800A61BC, 0x3F, 7, 319, 600, 1 };
FieldActorEntry D_800A6284 = { NULL, D_800A61D4, 0x8B, 8, 731, 350, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A620C,
    &D_800A6220,
    &D_800A6234,
    &D_800A6248,
    &D_800A625C,
    &D_800A6270,
    &D_800A6284,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 68, 778, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 159, 733, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 13, 758, 0, 0 },
    { 1, 0x64, 0x40, 6, 2, 0, 0, 0, 0, 0, 89, 730, 0, 0 },
    { 1, 0, 0x72, 4, 0, 0, 0, 0, 0, 0, 0, 657, 795, 0 },
    { 1, 0, 0x76, 4, 1, 0, 0, 0, 0, 0, 40, 677, 795, 0 },
    { 1, 0, 0x60, 4, 3, 0, 0, 0, 0, 0, 290, 502, 595, 0 },
    { 1, 0, 0x80, 4, 5, 0, 0, 0, 0, 0, 63, 783, 795, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 119, 387, 387, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 156, 539, 539, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 168, 339, 339, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 169, 579, 579, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 298, 298, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 185, 379, 379, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 206, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 356, 356, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 238, 215, 215, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 249, 635, 635, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 280, 667, 667, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 296, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 312, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 360, 198, 198, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 392, 323, 323, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 631, 631, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 423, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 424, 291, 291, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 440, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 472, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 487, 307, 307, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 552, 451, 451, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 595, 479, 479, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 595, 595, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 691, 691, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 600, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 608, 823, 823, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 623, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 625, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 642, 763, 763, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 648, 803, 803, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 680, 570, 570, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 728, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 760, 195, 195, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 833, 659, 659, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 840, 267, 267, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 845, 571, 571, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 871, 315, 315, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x290, 0x598, 0x260, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x296, 0x154, 0x6A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x294, 0x80, 0x31C, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x292, 0x1B2, 0x156, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A66AC = { 146, 13, 0x60080000 };
Battle D_800A66B8 = { 146, 13, 0x60080000 };
Battle D_800A66C4 = { 151, 13, 0x60080000 };
Battle D_800A66D0 = { 151, 13, 0x60080000 };
Battle D_800A66DC = { 94, 13, 0x60080000 };
Battle D_800A66E8 = { 94, 13, 0x60080000 };
Battle D_800A66F4 = { 101, 13, 0x60080000 };
Battle D_800A6700 = { 101, 13, 0x60080000 };
BattleList D_800A670C = {
    3,
    { &D_800A66AC, &D_800A66B8, &D_800A66C4, &D_800A66D0,
      &D_800A66DC, &D_800A66E8, &D_800A66F4, &D_800A6700 },
};
Battle D_800A6730 = { 0, 0, 0x60040000 };
Battle D_800A673C = { 0, 0, 0x60040000 };
Battle D_800A6748 = { 0, 0, 0x60040000 };
Battle D_800A6754 = { 0, 0, 0x60040000 };
Battle D_800A6760 = { 0, 0, 0x60040000 };
Battle D_800A676C = { 0, 0, 0x60040000 };
Battle D_800A6778 = { 0, 0, 0x60040000 };
Battle D_800A6784 = { 0, 0, 0x60040000 };
BattleList D_800A6790 = {
    0,
    { &D_800A6730, &D_800A673C, &D_800A6748, &D_800A6754,
      &D_800A6760, &D_800A676C, &D_800A6778, &D_800A6784 },
};
Battle D_800A67B4 = { 0, 0, 0x60040000 };
Battle D_800A67C0 = { 0, 0, 0x60040000 };
Battle D_800A67CC = { 0, 0, 0x60040000 };
Battle D_800A67D8 = { 0, 0, 0x60040000 };
Battle D_800A67E4 = { 0, 0, 0x60040000 };
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
Battle D_800A6808 = { 0, 0, 0x60040000 };
BattleList D_800A6814 = {
    0,
    { &D_800A67B4, &D_800A67C0, &D_800A67CC, &D_800A67D8,
      &D_800A67E4, &D_800A67F0, &D_800A67FC, &D_800A6808 },
};
Battle D_800A6838 = { 0, 0, 0x60040000 };
Battle D_800A6844 = { 0, 0, 0x60040000 };
Battle D_800A6850 = { 0, 0, 0x60040000 };
Battle D_800A685C = { 331, 13, 0x60080000 };
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 99, 13, 0x60080000 };
Battle D_800A688C = { 0, 0, 0x60040000 };
BattleList D_800A6898 = {
    0,
    { &D_800A6838, &D_800A6844, &D_800A6850, &D_800A685C,
      &D_800A6868, &D_800A6874, &D_800A6880, &D_800A688C },
};
FieldBattles stageBattles[] = {
    { 385, 0, 0, { &D_800A670C, &D_800A6790, &D_800A6814, &D_800A6898 } },
};
