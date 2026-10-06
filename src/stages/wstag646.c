#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x4049, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x61B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x62B
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x2C900, 0x23B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A5080;
extern Battle D_800A508C;
extern Battle D_800A5098;
extern Battle D_800A50A4;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5110;
extern Battle D_800A511C;
extern Battle D_800A5128;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A5194;
extern Battle D_800A51A0;
extern Battle D_800A51AC;
extern BattleList D_800A502C;
extern BattleList D_800A50B0;
extern BattleList D_800A5134;
extern BattleList D_800A51B8;
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52C4[];
extern u16 D_800A52D4[];
extern u16 D_800A52E8[];
extern u16 D_800A52F4[];
extern u16 D_800A5300[];
extern u16 D_800A530C[];
extern u16 D_800A5318[];
extern u16 D_800A5320[];
extern u16 D_800A532C[];
extern u16 D_800A5334[];
extern u16 D_800A5340[];
extern u16 D_800A534C[];
extern u16 D_800A5358[];
extern u16 D_800A5364[];
extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A5380[];
extern u16 D_800A5388[];
extern u16 D_800A5394[];
extern u16 D_800A539C[];
extern u16 D_800A53A8[];
extern u16 D_800A53B8[];
extern u16 D_800A53C0[];
extern u16 D_800A53D4[];
extern u16 D_800A53EC[];
extern u16 D_800A53F8[];
extern u16 D_800A5414[];
extern u16 D_800A5430[];
extern u16 D_800A5588[];
extern FieldTalk D_800A5438[];
extern u16 D_800A559C[];
extern FieldTalk D_800A5474[];
extern u16 D_800A55A8[];
extern FieldTalk D_800A548C[];
extern u16 D_800A55B8[];
extern FieldTalk D_800A54E0[];
extern u16 D_800A55C4[];
extern FieldTalk D_800A5504[];
extern u16 D_800A55D4[];
extern FieldTalk D_800A5570[];
extern FieldActorEntry D_800A55DC;
extern FieldActorEntry D_800A55F0;
extern FieldActorEntry D_800A5604;
extern FieldActorEntry D_800A5618;
extern FieldActorEntry D_800A562C;
extern FieldActorEntry D_800A5640;
extern s16 D_800A4E88[];

s16 D_800A4E88[] = {
    0x102, 2, 0x248, 0x11C, 5,
    0x100, 0x2D, 0x270, 0x108,
    0x101, 0x2D, 1, 1,
    0x100, 0x31, 0x288, 0x115,
    0x101, 0x31, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x102, 2, 0x258, 0x114, 5,
    0x302, 2,
    0x101, 0x323, 0x325, 0x2D,
    0x101, 0x324, 0x325, 0x31,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x2D,
    0x101, 0x324, 0x326, 0x31,
    0x300, 0x1E,
    0x200, 0, 1, 0x31, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x2D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 0x2D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x2D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x2D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 0x2D, 0,
    0x301,
    0x101, 0x2D, 1, 3,
    0x300, 0x1E,
    0x102, 0x2D, 0x250, 0xF8, 3,
    0x302, 0x2D,
    0x100, 0x2D, 0, 0,
    0x101, 0x2D, 1, 0,
    0x300, 0x1E,
    0,
};
Battle D_800A4FCC = { 72, 5, 0x60080000 };
Battle D_800A4FD8 = { 72, 5, 0x60080000 };
Battle D_800A4FE4 = { 72, 5, 0x60080000 };
Battle D_800A4FF0 = { 72, 5, 0x60080000 };
Battle D_800A4FFC = { 72, 5, 0x60080000 };
Battle D_800A5008 = { 72, 5, 0x60080000 };
Battle D_800A5014 = { 72, 5, 0x60080000 };
Battle D_800A5020 = { 72, 5, 0x60080000 };
BattleList D_800A502C = {
    3,
    { &D_800A4FCC, &D_800A4FD8, &D_800A4FE4, &D_800A4FF0,
      &D_800A4FFC, &D_800A5008, &D_800A5014, &D_800A5020 },
};
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 0, 0, 0x60040000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 0, 0, 0x60040000 };
Battle D_800A5080 = { 0, 0, 0x60040000 };
Battle D_800A508C = { 0, 0, 0x60040000 };
Battle D_800A5098 = { 0, 0, 0x60040000 };
Battle D_800A50A4 = { 0, 0, 0x60040000 };
BattleList D_800A50B0 = {
    0,
    { &D_800A5050, &D_800A505C, &D_800A5068, &D_800A5074,
      &D_800A5080, &D_800A508C, &D_800A5098, &D_800A50A4 },
};
Battle D_800A50D4 = { 0, 0, 0x60040000 };
Battle D_800A50E0 = { 0, 0, 0x60040000 };
Battle D_800A50EC = { 0, 0, 0x60040000 };
Battle D_800A50F8 = { 0, 0, 0x60040000 };
Battle D_800A5104 = { 0, 0, 0x60040000 };
Battle D_800A5110 = { 0, 0, 0x60040000 };
Battle D_800A511C = { 0, 0, 0x60040000 };
Battle D_800A5128 = { 0, 0, 0x60040000 };
BattleList D_800A5134 = {
    0,
    { &D_800A50D4, &D_800A50E0, &D_800A50EC, &D_800A50F8,
      &D_800A5104, &D_800A5110, &D_800A511C, &D_800A5128 },
};
Battle D_800A5158 = { 239, 5, 0x600C0000 };
Battle D_800A5164 = { 287, 5, 0x600C0000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
Battle D_800A5194 = { 0, 0, 0x60040000 };
Battle D_800A51A0 = { 0, 0, 0x60040000 };
Battle D_800A51AC = { 0, 0, 0x60040000 };
BattleList D_800A51B8 = {
    0,
    { &D_800A5158, &D_800A5164, &D_800A5170, &D_800A517C,
      &D_800A5188, &D_800A5194, &D_800A51A0, &D_800A51AC },
};
FieldBattles stageBattles[] = {
    { 104, 0, 0, { &D_800A502C, &D_800A50B0, &D_800A5134, &D_800A51B8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x13D, 0, 0x3D, 0x150, 0x1FF },
    { 0x140, 0x100, 0x150, 0x15D, 0x40, 0x5D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x148, 0x13D, 0x20, 0x3D, 0x170, 0x1FF },
    { 0x140, 0x100, 0x150, 0x13D, 0x40, 0x3D, 0x150, 0x1FE },
};
u16 D_800A5298[] = { 0x868E, 1, 0xFFFF };
u16 D_800A52A0[] = { 1, 0, 0x868E, 0, 0xFFFF };
u16 D_800A52AC[] = { 1, 1, 0xFFFF };
u16 D_800A52B4[] = { 1, 1, 0x868E, 0, 0x848A, 0, 0xFFFF };
u16 D_800A52C4[] = { 1, 1, 0x868E, 0, 0x848A, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x868E, 1, 0x868D, 0, 0x848A, 0, 0x7013, 1, 0xFFFF };
u16 D_800A52E8[] = { 0x1A0B, 1, 0x9046, 1, 0xFFFF };
u16 D_800A52F4[] = { 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5300[] = { 0x11, 0, 0x6026, 1, 0xFFFF };
u16 D_800A530C[] = { 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5318[] = { 0x11, 0, 0xFFFF };
u16 D_800A5320[] = { 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A532C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5334[] = { 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5340[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A534C[] = { 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5358[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5364[] = { 0x7019, 1, 0xFFFF };
u16 D_800A536C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5374[] = { 0, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5380[] = { 0, 1, 0xFFFF };
u16 D_800A5388[] = { 0, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5394[] = { 0, 1, 0xFFFF };
u16 D_800A539C[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A53A8[] = { 0, 1, 0x7207, 1, 0x8014, 0, 0xFFFF };
u16 D_800A53B8[] = { 0x7637, 1, 0xFFFF };
u16 D_800A53C0[] = { 0, 1, 0x7207, 1, 0x8014, 1, 0x7209, 0, 0xFFFF };
u16 D_800A53D4[] = {
    0, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2A, 0, 0xFFFF,
};
u16 D_800A53EC[] = { 0x7400, 1, 0xE2A, 1, 0xFFFF };
u16 D_800A53F8[] = {
    0, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2A, 1, 0x720B, 0, 0xFFFF,
};
u16 D_800A5414[] = {
    0, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2A, 1, 0x720B, 1, 0xFFFF,
};
u16 D_800A5430[] = { 0x7837, 1, 0xFFFF };
FieldTalk D_800A5438[] = {
    { D_800A5298, NULL, 0x2FA },
    { D_800A52A0, D_800A52AC, 0x2FB },
    { D_800A52B4, NULL, 0x2FC },
    { D_800A52C4, D_800A52D4, 0x2FD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5474[] = {
    { NULL, D_800A52E8, 0x1D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A548C[] = {
    { D_800A52F4, NULL, 0x1E8 },
    { D_800A5300, NULL, 0x13 },
    { D_800A530C, D_800A5318, 0x1E6 },
    { D_800A5320, D_800A532C, 0x14 },
    { D_800A5334, D_800A5340, 0x1E7 },
    { D_800A534C, D_800A5358, 0x15 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E0[] = {
    { D_800A5364, NULL, 0x1E8 },
    { D_800A536C, NULL, 0x13 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5504[] = {
    { D_800A5374, D_800A5380, 0x1DE },
    { D_800A5388, D_800A5394, 0x13 },
    { D_800A539C, NULL, 0x16 },
    { D_800A53A8, D_800A53B8, 0x1E1 },
    { D_800A53C0, NULL, 0x1E2 },
    { D_800A53D4, D_800A53EC, 0x1E3 },
    { D_800A53F8, NULL, 0x1E4 },
    { D_800A5414, D_800A5430, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5570[] = {
    { NULL, NULL, 0x1DD },
    { NULL, NULL, 0 },
};
u16 D_800A5588[] = { 0x7049, 1, 0x7051, 1, 0x868D, 1, 0x868E, 0, 0xFFFF };
u16 D_800A559C[] = { 0x701E, 1, 0x4049, 0, 0xFFFF };
u16 D_800A55A8[] = { 0x8192, 1, 0x11, 1, 0x701E, 1, 0xFFFF };
u16 D_800A55B8[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x11, 0, 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A55D4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A55DC = { D_800A5588, D_800A5438, 0x1C, 4, 720, 393, 1 };
FieldActorEntry D_800A55F0 = { D_800A559C, D_800A5474, 0x2D, 5, 624, 264, 1 };
FieldActorEntry D_800A5604 = { D_800A55A8, D_800A548C, 0x31, 6, 648, 277, 1 };
FieldActorEntry D_800A5618 = { D_800A55B8, D_800A54E0, 0x31, 6, 648, 277, 1 };
FieldActorEntry D_800A562C = { D_800A55C4, D_800A5504, 0x31, 6, 648, 277, 1 };
FieldActorEntry D_800A5640 = { D_800A55D4, D_800A5570, 0x9D, 7, 648, 277, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A55DC,
    &D_800A55F0,
    &D_800A5604,
    &D_800A5618,
    &D_800A562C,
    &D_800A5640,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 4, 0, 0, 0, 0, 0, 562, 254, 0, 0 },
    { 1, 0, 0x40, 4, 0x53, 2, 0, 0xF, 8, 0, 604, 194, 256, 0 },
    { 1, 0, 0x40, 4, 0x54, 2, 0, 0xF, 8, 0, 604, 194, 252, 0 },
    { 1, 0, 0x40, 4, 0x55, 2, 0, 0xF, 8, 0, 604, 194, 248, 0 },
    { 1, 0, 0x40, 4, 0x56, 2, 0, 0xF, 8, 0, 604, 194, 244, 0 },
    { 1, 0, 0x40, 4, 0x57, 2, 0, 0xF, 8, 0, 604, 194, 240, 0 },
    { 1, 0, 0x40, 4, 0x58, 2, 0, 0xF, 8, 0, 604, 194, 236, 0 },
    { 1, 0, 0x40, 4, 0x59, 2, 0, 0xF, 8, 0, 604, 194, 232, 0 },
    { 1, 0, 0x40, 4, 0x5A, 2, 0, 0xF, 8, 0, 604, 194, 228, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 566, 208, 264, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C4, 0x27A, 0x256, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C1, 0x110, 0x108, 7, 0, 1, 6 },
    { { { 0x4049, 0 }, { 0xFFFF, 0 } }, 8, 0x2DF, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 735, D_800A4E88, EVENT_TEXT(0x1D), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
