#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x60B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x61B
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xBD00, 0x25800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3A;
    D_800990B4.music = 0x60E80000;
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
extern u16 D_800A51A8[];
extern FieldTalk D_800A5118[];
extern u16 D_800A51B4[];
extern FieldTalk D_800A5130[];
extern u16 D_800A51C0[];
extern FieldTalk D_800A5148[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A5160[];
extern u16 D_800A51D4[];
extern FieldTalk D_800A5178[];
extern u16 D_800A51E0[];
extern FieldTalk D_800A5190[];
extern FieldActorEntry D_800A51E8;
extern FieldActorEntry D_800A51FC;
extern FieldActorEntry D_800A5210;
extern FieldActorEntry D_800A5224;
extern FieldActorEntry D_800A5238;
extern FieldActorEntry D_800A524C;

Battle D_800A4E4C = { 116, 12, 0x60080000 };
Battle D_800A4E58 = { 116, 12, 0x60080000 };
Battle D_800A4E64 = { 116, 12, 0x60080000 };
Battle D_800A4E70 = { 116, 12, 0x60080000 };
Battle D_800A4E7C = { 164, 12, 0x60080000 };
Battle D_800A4E88 = { 164, 12, 0x60080000 };
Battle D_800A4E94 = { 164, 12, 0x60080000 };
Battle D_800A4EA0 = { 164, 12, 0x60080000 };
BattleList D_800A4EAC = {
    2,
    { &D_800A4E4C, &D_800A4E58, &D_800A4E64, &D_800A4E70,
      &D_800A4E7C, &D_800A4E88, &D_800A4E94, &D_800A4EA0 },
};
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
BattleList D_800A4F30 = {
    0,
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
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 0, 0, 0x60040000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 112, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A2, 0x176, 0x188, 0x76, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B2, 0x146, 0x1C8, 0x46, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B2, 0x16E, 0x1C8, 0x6E, 0x160, 0x1FE },
    { 0x180, 0x100, 0x19A, 0x176, 0x168, 0x76, 0x170, 0x1FE },
};
FieldTalk D_800A5118[] = {
    { NULL, NULL, 0x118 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5130[] = {
    { NULL, NULL, 0x116 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5148[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5160[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5178[] = {
    { NULL, NULL, 0x115 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5190[] = {
    { NULL, NULL, 0x115 },
    { NULL, NULL, 0 },
};
u16 D_800A51A8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51B4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51C0[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51E0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A51E8 = { D_800A51A8, D_800A5118, 0x2D, 4, 625, 171, 1 };
FieldActorEntry D_800A51FC = { D_800A51B4, D_800A5130, 0x33, 5, 529, 567, 7 };
FieldActorEntry D_800A5210 = { D_800A51C0, D_800A5148, 0x9D, 6, 625, 171, 1 };
FieldActorEntry D_800A5224 = { D_800A51CC, D_800A5160, 0x9D, 6, 625, 171, 1 };
FieldActorEntry D_800A5238 = { D_800A51D4, D_800A5178, 0x9E, 7, 529, 567, 7 };
FieldActorEntry D_800A524C = { D_800A51E0, D_800A5190, 0x9E, 7, 529, 567, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A51E8,
    &D_800A51FC,
    &D_800A5210,
    &D_800A5224,
    &D_800A5238,
    &D_800A524C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 1, 0, 0, 0, 0, 0, 512, 0, 0, 0 },
    { 1, 0, 0x80, 2, 2, 0, 0, 0, 0, 0, 463, 0, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 4, 0, 180, 506, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 4, 0, 249, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 4, 0, 160, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 4, 0, 229, 368, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 388, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 429, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 441, 565, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 468, 435, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 482, 585, 0, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 460, 138, 584, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 492, 154, 584, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 586, 201, 584, 0 },
    { 1, 0, 0x65, 4, 0, 0, 0, 0, 0, 0, 84, 484, 584, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 489, 136, 190, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 509, 136, 198, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 525, 136, 207, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 541, 136, 215, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x88, 0x22C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BE, 0x3F0, 0x2F0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
