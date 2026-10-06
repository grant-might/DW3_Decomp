#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5A6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5B6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xEC00, 0x1AC00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E4C;
extern Battle D_800A4E58;
extern Battle D_800A4E64;
extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern BattleList D_800A4EAC;
extern BattleList D_800A4F30;
extern BattleList D_800A4FB4;
extern BattleList D_800A5038;
extern u16 D_800A5128[];
extern u16 D_800A5134[];
extern u16 D_800A513C[];
extern u16 D_800A5148[];
extern u16 D_800A5150[];
extern u16 D_800A5224[];
extern FieldTalk D_800A5158[];
extern u16 D_800A5230[];
extern FieldTalk D_800A5170[];
extern u16 D_800A523C[];
extern FieldTalk D_800A5188[];
extern u16 D_800A5244[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A524C[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A5258[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5260[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A526C[];
extern FieldTalk D_800A520C[];
extern FieldActorEntry D_800A5274;
extern FieldActorEntry D_800A5288;
extern FieldActorEntry D_800A529C;
extern FieldActorEntry D_800A52B0;
extern FieldActorEntry D_800A52C4;
extern FieldActorEntry D_800A52D8;
extern FieldActorEntry D_800A52EC;
extern FieldActorEntry D_800A5300;

Battle D_800A4E4C = { 157, 2, 0x60080000 };
Battle D_800A4E58 = { 157, 2, 0x60080000 };
Battle D_800A4E64 = { 157, 2, 0x60080000 };
Battle D_800A4E70 = { 157, 2, 0x60080000 };
Battle D_800A4E7C = { 157, 2, 0x60080000 };
Battle D_800A4E88 = { 157, 2, 0x60080000 };
Battle D_800A4E94 = { 157, 2, 0x60080000 };
Battle D_800A4EA0 = { 157, 2, 0x60080000 };
BattleList D_800A4EAC = {
    3,
    { &D_800A4E4C, &D_800A4E58, &D_800A4E64, &D_800A4E70,
      &D_800A4E7C, &D_800A4E88, &D_800A4E94, &D_800A4EA0 },
};
Battle D_800A4ED0 = { 95, 2, 0x60080000 };
Battle D_800A4EDC = { 95, 2, 0x60080000 };
Battle D_800A4EE8 = { 95, 2, 0x60080000 };
Battle D_800A4EF4 = { 95, 2, 0x60080000 };
Battle D_800A4F00 = { 95, 2, 0x60080000 };
Battle D_800A4F0C = { 95, 2, 0x60080000 };
Battle D_800A4F18 = { 95, 2, 0x60080000 };
Battle D_800A4F24 = { 95, 2, 0x60080000 };
BattleList D_800A4F30 = {
    3,
    { &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4,
      &D_800A4F00, &D_800A4F0C, &D_800A4F18, &D_800A4F24 },
};
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
BattleList D_800A4FB4 = {
    0,
    { &D_800A4F54, &D_800A4F60, &D_800A4F6C, &D_800A4F78,
      &D_800A4F84, &D_800A4F90, &D_800A4F9C, &D_800A4FA8 },
};
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
Battle D_800A5008 = { 332, 2, 0x60080000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 0, 0, 0x60040000 };
Battle D_800A502C = { 106, 2, 0x60080000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 77, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x130, 0x60, 0x30, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x130, 0xD0, 0x30, 0x160, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x100, 0x68, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x140, 0x13D, 0, 0x3D, 0x140, 0x1FE },
    { 0x140, 0x100, 0x148, 0x13D, 0x20, 0x3D, 0x150, 0x1FE },
};
u16 D_800A5128[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A5134[] = { 0x9404, 1, 0xFFFF };
u16 D_800A513C[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A5148[] = { 0x9406, 1, 0xFFFF };
u16 D_800A5150[] = { 0x940D, 1, 0xFFFF };
FieldTalk D_800A5158[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5170[] = {
    { NULL, NULL, 0x10E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5188[] = {
    { D_800A5128, D_800A5134, 0x2DA },
    { D_800A513C, D_800A5148, 0x2DA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51AC[] = {
    { NULL, D_800A5150, 0x2DA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x10A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x10C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x10D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x10F },
    { NULL, NULL, 0 },
};
u16 D_800A5224[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5230[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A523C[] = { 0x802A, 0, 0xFFFF };
u16 D_800A5244[] = { 0x802A, 1, 0xFFFF };
u16 D_800A524C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5258[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5260[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A526C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5274 = { D_800A5224, D_800A5158, 0x36, 4, 480, 480, 1 };
FieldActorEntry D_800A5288 = { D_800A5230, D_800A5170, 0x39, 5, 287, 536, 7 };
FieldActorEntry D_800A529C = { D_800A523C, D_800A5188, 0x8A, 6, 204, 412, 7 };
FieldActorEntry D_800A52B0 = { D_800A5244, D_800A51AC, 0x8A, 6, 204, 412, 7 };
FieldActorEntry D_800A52C4 = { D_800A524C, D_800A51C4, 0x9D, 7, 480, 480, 1 };
FieldActorEntry D_800A52D8 = { D_800A5258, D_800A51DC, 0x9D, 7, 480, 480, 1 };
FieldActorEntry D_800A52EC = { D_800A5260, D_800A51F4, 0x9E, 8, 287, 536, 7 };
FieldActorEntry D_800A5300 = { D_800A526C, D_800A520C, 0x9E, 8, 287, 536, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5274,
    &D_800A5288,
    &D_800A529C,
    &D_800A52B0,
    &D_800A52C4,
    &D_800A52D8,
    &D_800A52EC,
    &D_800A5300,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 424, 218, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 281, 604, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 520, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 621, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 347, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 382, 315, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 615, 560, 0, 0 },
    { 1, 0, 0x64, 4, 6, 0, 0, 0, 0, 0, 209, 351, 391, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A9, 0x88, 0x1BE, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 0x13, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
