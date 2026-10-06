#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x1B6;
    D_800990B4.sheetEntry = 0x9090000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x908;
    D_800990B4.start = (Vec2){0x13800, 0x27100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9090002);
    D_8009A70C.setFile(7, 0x9090003);
    D_8009A70C.setFile(4, 0x9090001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6024[];
extern u16 D_800A6030[];
extern u16 D_800A603C[];
extern u16 D_800A6048[];
extern u16 D_800A6058[];
extern u16 D_800A6064[];
extern u16 D_800A606C[];
extern u16 D_800A6078[];
extern FieldTalk D_800A6080[];
extern u16 D_800A6104[];
extern FieldTalk D_800A6098[];
extern u16 D_800A610C[];
extern FieldTalk D_800A60D4[];
extern FieldTalk D_800A60EC[];
extern FieldActorEntry D_800A6114;
extern FieldActorEntry D_800A6128;
extern FieldActorEntry D_800A613C;
extern FieldActorEntry D_800A6150;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern Battle D_800A6524;
extern Battle D_800A6530;
extern Battle D_800A653C;
extern Battle D_800A6548;
extern Battle D_800A6554;
extern Battle D_800A6560;
extern Battle D_800A6590;
extern Battle D_800A659C;
extern Battle D_800A65A8;
extern Battle D_800A65B4;
extern Battle D_800A65C0;
extern Battle D_800A65CC;
extern Battle D_800A65D8;
extern Battle D_800A65E4;
extern Battle D_800A6614;
extern Battle D_800A6620;
extern Battle D_800A662C;
extern Battle D_800A6638;
extern Battle D_800A6644;
extern Battle D_800A6650;
extern Battle D_800A665C;
extern Battle D_800A6668;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66BC;
extern Battle D_800A66C8;
extern Battle D_800A66D4;
extern Battle D_800A66E0;
extern Battle D_800A66EC;
extern BattleList D_800A656C;
extern BattleList D_800A65F0;
extern BattleList D_800A6674;
extern BattleList D_800A66F8;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x120, 0xD0, 0x20, 0x170, 0x1FF },
};
u16 D_800A6024[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6030[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A603C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6048[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6058[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6064[] = { 0, 1, 0xFFFF };
u16 D_800A606C[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6078[] = { 0x782C, 1, 0xFFFF };
FieldTalk D_800A6080[] = {
    { NULL, NULL, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6098[] = {
    { D_800A6024, D_800A6030, 0x1F },
    { D_800A603C, D_800A6048, 0x20 },
    { D_800A6058, D_800A6064, 0x1D },
    { D_800A606C, D_800A6078, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60D4[] = {
    { NULL, NULL, 0x1D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60EC[] = {
    { NULL, NULL, 0x73 },
    { NULL, NULL, 0 },
};
u16 D_800A6104[] = { 0x8192, 1, 0xFFFF };
u16 D_800A610C[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A6114 = { NULL, D_800A6080, 0x1B, 4, 361, 684, 5 };
FieldActorEntry D_800A6128 = { D_800A6104, D_800A6098, 0x3A, 5, 593, 289, 1 };
FieldActorEntry D_800A613C = { D_800A610C, D_800A60D4, 0x3A, 5, 593, 289, 1 };
FieldActorEntry D_800A6150 = { NULL, D_800A60EC, 0x16D, 6, 391, 309, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6114,
    &D_800A6128,
    &D_800A613C,
    &D_800A6150,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 199, 607, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 353, -16, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 513, 285, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 113, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 153, 554, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 167, 539, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 192, 494, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 225, 493, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 251, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 313, 468, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 86, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 169, 500, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 193, 527, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 216, 519, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 235, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 248, 454, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 253, 491, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 264, 469, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 58, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 130, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 214, 356, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 233, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 204, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 273, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 219, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 289, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 307, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 317, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 323, 421, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 226, 226, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 250, 250, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 243, 544, 544, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 267, 602, 602, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 271, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 277, 521, 521, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 159, 159, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 399, 167, 167, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 422, 187, 187, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 431, 568, 568, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 489, 501, 501, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 506, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 542, 228, 228, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 641, 286, 286, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x5F4, 0x39E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x290, 0x138, 0x7A, 7, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC8, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A650C = { 53, 1, 0x60080000 };
Battle D_800A6518 = { 53, 1, 0x60080000 };
Battle D_800A6524 = { 53, 1, 0x60080000 };
Battle D_800A6530 = { 53, 1, 0x60080000 };
Battle D_800A653C = { 57, 1, 0x60080000 };
Battle D_800A6548 = { 57, 1, 0x60080000 };
Battle D_800A6554 = { 57, 1, 0x60080000 };
Battle D_800A6560 = { 57, 1, 0x60080000 };
BattleList D_800A656C = {
    3,
    { &D_800A650C, &D_800A6518, &D_800A6524, &D_800A6530,
      &D_800A653C, &D_800A6548, &D_800A6554, &D_800A6560 },
};
Battle D_800A6590 = { 145, 13, 0x60080000 };
Battle D_800A659C = { 145, 13, 0x60080000 };
Battle D_800A65A8 = { 145, 13, 0x60080000 };
Battle D_800A65B4 = { 145, 13, 0x60080000 };
Battle D_800A65C0 = { 58, 13, 0x60080000 };
Battle D_800A65CC = { 58, 13, 0x60080000 };
Battle D_800A65D8 = { 58, 13, 0x60080000 };
Battle D_800A65E4 = { 58, 13, 0x60080000 };
BattleList D_800A65F0 = {
    3,
    { &D_800A6590, &D_800A659C, &D_800A65A8, &D_800A65B4,
      &D_800A65C0, &D_800A65CC, &D_800A65D8, &D_800A65E4 },
};
Battle D_800A6614 = { 0, 0, 0x60040000 };
Battle D_800A6620 = { 0, 0, 0x60040000 };
Battle D_800A662C = { 0, 0, 0x60040000 };
Battle D_800A6638 = { 0, 0, 0x60040000 };
Battle D_800A6644 = { 0, 0, 0x60040000 };
Battle D_800A6650 = { 0, 0, 0x60040000 };
Battle D_800A665C = { 0, 0, 0x60040000 };
Battle D_800A6668 = { 0, 0, 0x60040000 };
BattleList D_800A6674 = {
    0,
    { &D_800A6614, &D_800A6620, &D_800A662C, &D_800A6638,
      &D_800A6644, &D_800A6650, &D_800A665C, &D_800A6668 },
};
Battle D_800A6698 = { 0, 0, 0x60040000 };
Battle D_800A66A4 = { 0, 0, 0x60040000 };
Battle D_800A66B0 = { 0, 0, 0x60040000 };
Battle D_800A66BC = { 327, 13, 0x60080000 };
Battle D_800A66C8 = { 330, 8, 0x60080000 };
Battle D_800A66D4 = { 0, 0, 0x60040000 };
Battle D_800A66E0 = { 49, 13, 0x60080000 };
Battle D_800A66EC = { 61, 8, 0x60080000 };
BattleList D_800A66F8 = {
    0,
    { &D_800A6698, &D_800A66A4, &D_800A66B0, &D_800A66BC,
      &D_800A66C8, &D_800A66D4, &D_800A66E0, &D_800A66EC },
};
FieldBattles stageBattles[] = {
    { 383, 0, 0, { &D_800A656C, &D_800A65F0, &D_800A6674, &D_800A66F8 } },
};
