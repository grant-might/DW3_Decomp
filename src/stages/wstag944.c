#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x1B8;
    D_800990B4.sheetEntry = 0x90F0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x90E;
    D_800990B4.start = (Vec2){0x2D600, 0x8000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2D;
    D_800990B4.music = 0x60B40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x90F0002);
    D_8009A70C.setFile(7, 0x90F0003);
    D_8009A70C.setFile(4, 0x90F0001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6020[];
extern u16 D_800A6030[];
extern u16 D_800A603C[];
extern u16 D_800A6048[];
extern u16 D_800A6054[];
extern u16 D_800A6064[];
extern u16 D_800A6070[];
extern u16 D_800A6078[];
extern u16 D_800A6084[];
extern u16 D_800A6110[];
extern FieldTalk D_800A608C[];
extern u16 D_800A6118[];
extern FieldTalk D_800A60A4[];
extern u16 D_800A6120[];
extern FieldTalk D_800A60BC[];
extern FieldTalk D_800A60F8[];
extern FieldActorEntry D_800A6128;
extern FieldActorEntry D_800A613C;
extern FieldActorEntry D_800A6150;
extern FieldActorEntry D_800A6164;
extern Battle D_800A6534;
extern Battle D_800A6540;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6570;
extern Battle D_800A657C;
extern Battle D_800A6588;
extern Battle D_800A65B8;
extern Battle D_800A65C4;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern Battle D_800A65F4;
extern Battle D_800A6600;
extern Battle D_800A660C;
extern Battle D_800A663C;
extern Battle D_800A6648;
extern Battle D_800A6654;
extern Battle D_800A6660;
extern Battle D_800A666C;
extern Battle D_800A6678;
extern Battle D_800A6684;
extern Battle D_800A6690;
extern Battle D_800A66C0;
extern Battle D_800A66CC;
extern Battle D_800A66D8;
extern Battle D_800A66E4;
extern Battle D_800A66F0;
extern Battle D_800A66FC;
extern Battle D_800A6708;
extern Battle D_800A6714;
extern BattleList D_800A6594;
extern BattleList D_800A6618;
extern BattleList D_800A669C;
extern BattleList D_800A6720;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x128, 0xD8, 0x28, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x170, 0x1FF },
};
u16 D_800A6020[] = { 0x26A, 1, 0x8239, 1, 0x7013, 1, 0xFFFF };
u16 D_800A6030[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A603C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6048[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6054[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6064[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6070[] = { 0, 1, 0xFFFF };
u16 D_800A6078[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6084[] = { 0x7833, 1, 0xFFFF };
FieldTalk D_800A608C[] = {
    { NULL, D_800A6020, 2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60A4[] = {
    { NULL, NULL, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60BC[] = {
    { D_800A6030, D_800A603C, 0x2B },
    { D_800A6048, D_800A6054, 0x2C },
    { D_800A6064, D_800A6070, 0x29 },
    { D_800A6078, D_800A6084, 0x2A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60F8[] = {
    { NULL, NULL, 0x7D },
    { NULL, NULL, 0 },
};
u16 D_800A6110[] = { 0x26A, 0, 0xFFFF };
u16 D_800A6118[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6120[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A6128 = { D_800A6110, D_800A608C, 0x21, 4, 1353, 405, 1 };
FieldActorEntry D_800A613C = { D_800A6118, D_800A60A4, 0x2F, 5, 722, 161, 7 };
FieldActorEntry D_800A6150 = { D_800A6120, D_800A60BC, 0x2F, 5, 722, 161, 7 };
FieldActorEntry D_800A6164 = { NULL, D_800A60F8, 0x8A, 6, 241, 297, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6128,
    &D_800A613C,
    &D_800A6150,
    &D_800A6164,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 313, 257, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 730, 365, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 932, 55, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 161, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 83, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 50, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 182, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 196, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 208, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 188, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 230, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 273, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 129, 383, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x44, 0x46, 0xA, 0, 196, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 248, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 272, 461, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 441, 339, 339, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 488, 363, 363, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 527, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 230, 230, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 584, 131, 131, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 632, 107, 107, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 679, 83, 83, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 687, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 760, 83, 83, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 808, 107, 107, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 856, 131, 131, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 880, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 896, 151, 151, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 463, 463, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 991, 440, 440, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1037, 410, 410, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1079, 395, 395, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1144, 387, 387, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1192, 410, 410, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1240, 435, 435, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1280, 455, 455, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1304, 499, 499, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1328, 335, 335, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1336, 531, 531, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1368, 355, 355, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1380, 553, 553, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1411, 376, 376, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28D, 0x28C, 0x33C, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x291, 0x8C, 0xCE, 7, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x50, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6534 = { 69, 13, 0x60080000 };
Battle D_800A6540 = { 69, 13, 0x60080000 };
Battle D_800A654C = { 154, 13, 0x60080000 };
Battle D_800A6558 = { 154, 13, 0x60080000 };
Battle D_800A6564 = { 70, 13, 0x60080000 };
Battle D_800A6570 = { 70, 13, 0x60080000 };
Battle D_800A657C = { 67, 13, 0x60080000 };
Battle D_800A6588 = { 67, 13, 0x60080000 };
BattleList D_800A6594 = {
    3,
    { &D_800A6534, &D_800A6540, &D_800A654C, &D_800A6558,
      &D_800A6564, &D_800A6570, &D_800A657C, &D_800A6588 },
};
Battle D_800A65B8 = { 0, 0, 0x60040000 };
Battle D_800A65C4 = { 0, 0, 0x60040000 };
Battle D_800A65D0 = { 0, 0, 0x60040000 };
Battle D_800A65DC = { 0, 0, 0x60040000 };
Battle D_800A65E8 = { 0, 0, 0x60040000 };
Battle D_800A65F4 = { 0, 0, 0x60040000 };
Battle D_800A6600 = { 0, 0, 0x60040000 };
Battle D_800A660C = { 0, 0, 0x60040000 };
BattleList D_800A6618 = {
    0,
    { &D_800A65B8, &D_800A65C4, &D_800A65D0, &D_800A65DC,
      &D_800A65E8, &D_800A65F4, &D_800A6600, &D_800A660C },
};
Battle D_800A663C = { 0, 0, 0x60040000 };
Battle D_800A6648 = { 0, 0, 0x60040000 };
Battle D_800A6654 = { 0, 0, 0x60040000 };
Battle D_800A6660 = { 0, 0, 0x60040000 };
Battle D_800A666C = { 0, 0, 0x60040000 };
Battle D_800A6678 = { 0, 0, 0x60040000 };
Battle D_800A6684 = { 0, 0, 0x60040000 };
Battle D_800A6690 = { 0, 0, 0x60040000 };
BattleList D_800A669C = {
    0,
    { &D_800A663C, &D_800A6648, &D_800A6654, &D_800A6660,
      &D_800A666C, &D_800A6678, &D_800A6684, &D_800A6690 },
};
Battle D_800A66C0 = { 0, 0, 0x60040000 };
Battle D_800A66CC = { 0, 0, 0x60040000 };
Battle D_800A66D8 = { 0, 0, 0x60040000 };
Battle D_800A66E4 = { 331, 13, 0x60080000 };
Battle D_800A66F0 = { 334, 8, 0x60080000 };
Battle D_800A66FC = { 0, 0, 0x60040000 };
Battle D_800A6708 = { 152, 13, 0x60080000 };
Battle D_800A6714 = { 186, 8, 0x60080000 };
BattleList D_800A6720 = {
    0,
    { &D_800A66C0, &D_800A66CC, &D_800A66D8, &D_800A66E4,
      &D_800A66F0, &D_800A66FC, &D_800A6708, &D_800A6714 },
};
FieldBattles stageBattles[] = {
    { 384, 0, 0, { &D_800A6594, &D_800A6618, &D_800A669C, &D_800A6720 } },
};
