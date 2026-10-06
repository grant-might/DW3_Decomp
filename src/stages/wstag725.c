#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x694
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x6A4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x37900, 0x10500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3F;
    D_800990B4.music = 0x60FC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern BattleList D_800A4EB0;
extern BattleList D_800A4F34;
extern BattleList D_800A4FB8;
extern BattleList D_800A503C;
extern u16 D_800A511C[];
extern u16 D_800A5124[];
extern u16 D_800A512C[];
extern u16 D_800A5138[];
extern u16 D_800A5144[];
extern u16 D_800A514C[];
extern u16 D_800A5154[];
extern u16 D_800A5160[];
extern u16 D_800A5168[];
extern u16 D_800A5174[];
extern u16 D_800A5180[];
extern u16 D_800A5188[];
extern u16 D_800A5194[];
extern u16 D_800A519C[];
extern u16 D_800A51AC[];
extern u16 D_800A51C0[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51E4[];
extern u16 D_800A51EC[];
extern u16 D_800A51F8[];
extern u16 D_800A5204[];
extern u16 D_800A520C[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern u16 D_800A5228[];
extern u16 D_800A5234[];
extern u16 D_800A5244[];
extern u16 D_800A5254[];
extern u16 D_800A525C[];
extern u16 D_800A5264[];
extern u16 D_800A5270[];
extern u16 D_800A527C[];
extern u16 D_800A5494[];
extern FieldTalk D_800A5284[];
extern u16 D_800A549C[];
extern FieldTalk D_800A529C[];
extern u16 D_800A54A4[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A54AC[];
extern FieldTalk D_800A52CC[];
extern u16 D_800A54B4[];
extern FieldTalk D_800A52E4[];
extern u16 D_800A54C8[];
extern FieldTalk D_800A5314[];
extern u16 D_800A54D8[];
extern FieldTalk D_800A532C[];
extern u16 D_800A54EC[];
extern FieldTalk D_800A535C[];
extern u16 D_800A5500[];
extern FieldTalk D_800A5398[];
extern u16 D_800A5514[];
extern FieldTalk D_800A53C8[];
extern u16 D_800A5528[];
extern FieldTalk D_800A5404[];
extern u16 D_800A5530[];
extern FieldTalk D_800A5434[];
extern u16 D_800A5538[];
extern FieldTalk D_800A544C[];
extern u16 D_800A5540[];
extern FieldTalk D_800A5464[];
extern u16 D_800A5548[];
extern FieldTalk D_800A547C[];
extern FieldActorEntry D_800A5550;
extern FieldActorEntry D_800A5564;
extern FieldActorEntry D_800A5578;
extern FieldActorEntry D_800A558C;
extern FieldActorEntry D_800A55A0;
extern FieldActorEntry D_800A55B4;
extern FieldActorEntry D_800A55C8;
extern FieldActorEntry D_800A55DC;
extern FieldActorEntry D_800A55F0;
extern FieldActorEntry D_800A5604;
extern FieldActorEntry D_800A5618;
extern FieldActorEntry D_800A562C;
extern FieldActorEntry D_800A5640;
extern FieldActorEntry D_800A5654;
extern FieldActorEntry D_800A5668;

Battle D_800A4E50 = { 161, 7, 0x60080000 };
Battle D_800A4E5C = { 161, 7, 0x60080000 };
Battle D_800A4E68 = { 161, 7, 0x60080000 };
Battle D_800A4E74 = { 161, 7, 0x60080000 };
Battle D_800A4E80 = { 110, 7, 0x60080000 };
Battle D_800A4E8C = { 110, 7, 0x60080000 };
Battle D_800A4E98 = { 110, 7, 0x60080000 };
Battle D_800A4EA4 = { 110, 7, 0x60080000 };
BattleList D_800A4EB0 = {
    3,
    { &D_800A4E50, &D_800A4E5C, &D_800A4E68, &D_800A4E74,
      &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4 },
};
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
BattleList D_800A4F34 = {
    0,
    { &D_800A4ED4, &D_800A4EE0, &D_800A4EEC, &D_800A4EF8,
      &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28 },
};
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
BattleList D_800A4FB8 = {
    0,
    { &D_800A4F58, &D_800A4F64, &D_800A4F70, &D_800A4F7C,
      &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC },
};
Battle D_800A4FDC = { 223, 7, 0x600C0000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 86, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x142, 0x88, 0x42, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x120, 0xC0, 0x20, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x148, 0xA8, 0x48, 0x160, 0x1FE },
    { 0x140, 0x100, 0x172, 0x148, 0xC8, 0x48, 0x170, 0x1FE },
};
u16 D_800A511C[] = { 0, 0, 0xFFFF };
u16 D_800A5124[] = { 0, 1, 0xFFFF };
u16 D_800A512C[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A5138[] = { 0, 1, 0x720A, 1, 0xFFFF };
u16 D_800A5144[] = { 0x7621, 1, 0xFFFF };
u16 D_800A514C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5154[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5160[] = { 0x11, 0, 0xFFFF };
u16 D_800A5168[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5174[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5180[] = { 0x11, 0, 0xFFFF };
u16 D_800A5188[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5194[] = { 0x11, 0, 0xFFFF };
u16 D_800A519C[] = { 0x10, 1, 0x9219, 0, 0x11, 1, 0xFFFF };
u16 D_800A51AC[] = { 0x9219, 1, 0x11, 0, 0x7013, 1, 0x10, 0, 0xFFFF };
u16 D_800A51C0[] = { 0x10, 1, 0x9219, 1, 0x11, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A51DC[] = { 0, 0, 0xFFFF };
u16 D_800A51E4[] = { 0, 1, 0xFFFF };
u16 D_800A51EC[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A51F8[] = { 0, 1, 0x720A, 1, 0xFFFF };
u16 D_800A5204[] = { 0x7621, 1, 0xFFFF };
u16 D_800A520C[] = { 0, 0, 0xFFFF };
u16 D_800A5214[] = { 0, 1, 0xFFFF };
u16 D_800A521C[] = { 0, 1, 0xE17, 0, 0xFFFF };
u16 D_800A5228[] = { 0xE17, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5234[] = { 0, 1, 0xE17, 1, 0x720E, 0, 0xFFFF };
u16 D_800A5244[] = { 0, 1, 0xE17, 1, 0x720E, 1, 0xFFFF };
u16 D_800A5254[] = { 0x7821, 1, 0xFFFF };
u16 D_800A525C[] = { 0, 0, 0xFFFF };
u16 D_800A5264[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A5270[] = { 0, 1, 0x720A, 1, 0xFFFF };
u16 D_800A527C[] = { 0x7621, 1, 0xFFFF };
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0x2CD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0x2D0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E4[] = {
    { D_800A511C, D_800A5124, 0x1A0 },
    { D_800A512C, NULL, 0x1A3 },
    { D_800A5138, D_800A5144, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5314[] = {
    { NULL, NULL, 0x29A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A532C[] = {
    { D_800A514C, NULL, 0x1A0 },
    { D_800A5154, D_800A5160, 0x1A9 },
    { D_800A5168, D_800A5174, 0x1AA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A535C[] = {
    { D_800A5180, NULL, 0x1A0 },
    { D_800A5188, D_800A5194, 0x1AB },
    { D_800A519C, D_800A51AC, 0x1AC },
    { D_800A51C0, D_800A51D0, 0x1AD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5398[] = {
    { D_800A51DC, D_800A51E4, 0x1A1 },
    { D_800A51EC, NULL, 0x1A3 },
    { D_800A51F8, D_800A5204, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C8[] = {
    { D_800A520C, D_800A5214, 0x1A5 },
    { D_800A521C, D_800A5228, 0x1A6 },
    { D_800A5234, NULL, 0x1A7 },
    { D_800A5244, D_800A5254, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5404[] = {
    { D_800A525C, NULL, 0x1A2 },
    { D_800A5264, NULL, 0x1A3 },
    { D_800A5270, D_800A527C, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5434[] = {
    { NULL, NULL, 0x2D1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A544C[] = {
    { NULL, NULL, 0x2D4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5464[] = {
    { NULL, NULL, 0x2D2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A547C[] = {
    { NULL, NULL, 0x2D3 },
    { NULL, NULL, 0 },
};
u16 D_800A5494[] = { 0x7019, 1, 0xFFFF };
u16 D_800A549C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A54AC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A54B4[] = { 0x8192, 1, 0x11, 0, 0x7004, 1, 0x8012, 0, 0xFFFF };
u16 D_800A54C8[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A54D8[] = { 0x11, 1, 0x700A, 1, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A54EC[] = { 0x11, 1, 0x8012, 1, 0x8192, 1, 0x7022, 1, 0xFFFF };
u16 D_800A5500[] = { 0x8192, 1, 0x11, 0, 0x6026, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5514[] = { 0x8012, 1, 0x8192, 1, 0x11, 0, 0x7022, 1, 0xFFFF };
u16 D_800A5528[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5530[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5538[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5540[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5548[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5550 = { D_800A5494, D_800A5284, 0x22, 4, 161, 321, 1 };
FieldActorEntry D_800A5564 = { D_800A549C, D_800A529C, 0x22, 4, 161, 321, 1 };
FieldActorEntry D_800A5578 = { D_800A54A4, D_800A52B4, 0x22, 4, 161, 321, 1 };
FieldActorEntry D_800A558C = { D_800A54AC, D_800A52CC, 0x22, 4, 161, 321, 1 };
FieldActorEntry D_800A55A0 = { D_800A54B4, D_800A52E4, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A55B4 = { D_800A54C8, D_800A5314, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A55C8 = { D_800A54D8, D_800A532C, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A55DC = { D_800A54EC, D_800A535C, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A55F0 = { D_800A5500, D_800A5398, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A5604 = { D_800A5514, D_800A53C8, 0x33, 5, 816, 209, 1 };
FieldActorEntry D_800A5618 = { D_800A5528, D_800A5404, 0x9D, 6, 816, 209, 1 };
FieldActorEntry D_800A562C = { D_800A5530, D_800A5434, 0xB5, 7, 692, 265, 3 };
FieldActorEntry D_800A5640 = { D_800A5538, D_800A544C, 0xB5, 7, 495, 75, 7 };
FieldActorEntry D_800A5654 = { D_800A5540, D_800A5464, 0xB5, 7, 692, 265, 3 };
FieldActorEntry D_800A5668 = { D_800A5548, D_800A547C, 0xB5, 7, 692, 265, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5550,
    &D_800A5564,
    &D_800A5578,
    &D_800A558C,
    &D_800A55A0,
    &D_800A55B4,
    &D_800A55C8,
    &D_800A55DC,
    &D_800A55F0,
    &D_800A5604,
    &D_800A5618,
    &D_800A562C,
    &D_800A5640,
    &D_800A5654,
    &D_800A5668,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 6, 0, 807, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 647, 322, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 714, 356, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 755, 312, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 773, 350, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 830, 322, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 6, 0, 831, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 289, 211, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 317, 214, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 4, 0, 762, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 287, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 482, 16, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 566, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 630, 94, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 243, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 435, 24, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 467, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 6, 0, 909, 158, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 330, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 339, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 6, 0, 658, 77, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 3, 0, 9, 8, 0, 105, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 3, 0, 9, 8, 0, 143, 271, 0, 0 },
    { 1, 0, 0x40, 4, 0x38, 3, 0, 9, 8, 0, 77, 305, 328, 0 },
    { 1, 0, 0x44, 4, 0, 0, 0, 0, 0, 0, 635, 206, 246, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 464, 183, 220, 0 },
    { 1, 0, 0x42, 4, 2, 0, 0, 0, 0, 0, 61, 264, 328, 0 },
    { 1, 0, 0x50, 4, 3, 0, 0, 0, 0, 0, 800, 104, 175, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26A, 0x508, 0x54, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x269, 0xA8, 0xF4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x265, 0x220, 0x2C0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x200, 0x60, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x210, 0xC8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x220, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x210, 0x198, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
