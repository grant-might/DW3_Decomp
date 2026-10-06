#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x698
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6A8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x2F400, 0x9C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4EA0;
extern Battle D_800A4EAC;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A5080;
extern BattleList D_800A4F00;
extern BattleList D_800A4F84;
extern BattleList D_800A5008;
extern BattleList D_800A508C;
extern u16 D_800A514C[];
extern u16 D_800A5158[];
extern u16 D_800A5164[];
extern u16 D_800A5170[];
extern u16 D_800A5178[];
extern u16 D_800A5184[];
extern u16 D_800A518C[];
extern u16 D_800A519C[];
extern u16 D_800A51B0[];
extern u16 D_800A51B8[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51F8[];
extern u16 D_800A5218[];
extern u16 D_800A5238[];
extern u16 D_800A5240[];
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A525C[];
extern u16 D_800A526C[];
extern u16 D_800A5278[];
extern u16 D_800A528C[];
extern u16 D_800A52A0[];
extern u16 D_800A52A8[];
extern u16 D_800A52B0[];
extern u16 D_800A52B8[];
extern u16 D_800A52C0[];
extern u16 D_800A52C8[];
extern u16 D_800A52D4[];
extern u16 D_800A52E0[];
extern u16 D_800A52EC[];
extern u16 D_800A52F8[];
extern u16 D_800A5300[];
extern u16 D_800A530C[];
extern u16 D_800A5314[];
extern u16 D_800A5324[];
extern u16 D_800A5338[];
extern u16 D_800A5340[];
extern u16 D_800A5358[];
extern u16 D_800A5364[];
extern u16 D_800A5380[];
extern u16 D_800A53A0[];
extern u16 D_800A53C0[];
extern u16 D_800A53C8[];
extern u16 D_800A53D0[];
extern u16 D_800A53D8[];
extern u16 D_800A53E4[];
extern u16 D_800A53F4[];
extern u16 D_800A5400[];
extern u16 D_800A5414[];
extern u16 D_800A5428[];
extern u16 D_800A5430[];
extern u16 D_800A5438[];
extern u16 D_800A5440[];
extern u16 D_800A5448[];
extern u16 D_800A5450[];
extern u16 D_800A566C[];
extern FieldTalk D_800A545C[];
extern u16 D_800A5678[];
extern FieldTalk D_800A54D4[];
extern u16 D_800A5680[];
extern FieldTalk D_800A551C[];
extern u16 D_800A568C[];
extern FieldTalk D_800A5534[];
extern u16 D_800A5694[];
extern FieldTalk D_800A5564[];
extern u16 D_800A56A0[];
extern FieldTalk D_800A55DC[];
extern u16 D_800A56A8[];
extern FieldTalk D_800A5624[];
extern u16 D_800A56B4[];
extern FieldTalk D_800A563C[];
extern FieldActorEntry D_800A56BC;
extern FieldActorEntry D_800A56D0;
extern FieldActorEntry D_800A56E4;
extern FieldActorEntry D_800A56F8;
extern FieldActorEntry D_800A570C;
extern FieldActorEntry D_800A5720;
extern FieldActorEntry D_800A5734;
extern FieldActorEntry D_800A5748;

Battle D_800A4EA0 = { 93, 13, 0x60080000 };
Battle D_800A4EAC = { 93, 13, 0x60080000 };
Battle D_800A4EB8 = { 93, 13, 0x60080000 };
Battle D_800A4EC4 = { 93, 13, 0x60080000 };
Battle D_800A4ED0 = { 95, 13, 0x60080000 };
Battle D_800A4EDC = { 95, 13, 0x60080000 };
Battle D_800A4EE8 = { 95, 13, 0x60080000 };
Battle D_800A4EF4 = { 95, 13, 0x60080000 };
BattleList D_800A4F00 = {
    3,
    { &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4,
      &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4 },
};
Battle D_800A4F24 = { 0, 13, 0x60080000 };
Battle D_800A4F30 = { 0, 13, 0x60080000 };
Battle D_800A4F3C = { 0, 13, 0x60080000 };
Battle D_800A4F48 = { 0, 13, 0x60080000 };
Battle D_800A4F54 = { 0, 13, 0x60080000 };
Battle D_800A4F60 = { 0, 13, 0x60080000 };
Battle D_800A4F6C = { 0, 13, 0x60080000 };
Battle D_800A4F78 = { 0, 13, 0x60080000 };
BattleList D_800A4F84 = {
    0,
    { &D_800A4F24, &D_800A4F30, &D_800A4F3C, &D_800A4F48,
      &D_800A4F54, &D_800A4F60, &D_800A4F6C, &D_800A4F78 },
};
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
Battle D_800A4FB4 = { 0, 0, 0x60040000 };
Battle D_800A4FC0 = { 0, 0, 0x60040000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
BattleList D_800A5008 = {
    0,
    { &D_800A4FA8, &D_800A4FB4, &D_800A4FC0, &D_800A4FCC,
      &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC },
};
Battle D_800A502C = { 225, 13, 0x60080000 };
Battle D_800A5038 = { 226, 13, 0x60080000 };
Battle D_800A5044 = { 273, 13, 0x600C0000 };
Battle D_800A5050 = { 329, 13, 0x60080000 };
Battle D_800A505C = { 330, 8, 0x60080000 };
Battle D_800A5068 = { 93, 13, 0x60080000 };
Battle D_800A5074 = { 93, 13, 0x60080000 };
Battle D_800A5080 = { 180, 8, 0x60080000 };
BattleList D_800A508C = {
    0,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
FieldBattles stageBattles[] = {
    { 62, 0, 0, { &D_800A4F00, &D_800A4F84, &D_800A5008, &D_800A508C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x118, 0x98, 0x18, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x118, 0xB8, 0x18, 0x140, 0x1FE },
};
u16 D_800A514C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5158[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5164[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5170[] = { 0x11, 0, 0xFFFF };
u16 D_800A5178[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A5184[] = { 0, 1, 0xFFFF };
u16 D_800A518C[] = { 0x11, 0, 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A519C[] = { 0, 1, 0x7206, 1, 0x7208, 0, 0x11, 0, 0xFFFF };
u16 D_800A51B0[] = { 0x7623, 1, 0xFFFF };
u16 D_800A51B8[] = {
    0x11, 0, 0, 1, 0x7206, 1, 0x7208, 1,
    0xE1C, 0, 0xFFFF,
};
u16 D_800A51D0[] = { 0xE1C, 1, 0x7400, 1, 0xFFFF };
u16 D_800A51DC[] = {
    0x11, 0, 0, 1, 0x7206, 1, 0x7208, 1,
    0xE1C, 1, 0x8014, 0, 0xFFFF,
};
u16 D_800A51F8[] = {
    0x11, 0, 0, 1, 0x7206, 1, 0x7208, 1,
    0xE1C, 1, 0x8014, 1, 0x7209, 0, 0xFFFF,
};
u16 D_800A5218[] = {
    0x11, 0, 0, 1, 0x7206, 1, 0x7208, 1,
    0xE1C, 1, 0x8014, 1, 0x7209, 1, 0xFFFF,
};
u16 D_800A5238[] = { 0x7823, 1, 0xFFFF };
u16 D_800A5240[] = { 0, 0, 0xFFFF };
u16 D_800A5248[] = { 0, 1, 0xFFFF };
u16 D_800A5250[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A525C[] = { 0, 1, 0x7209, 1, 0xE3D, 0, 0xFFFF };
u16 D_800A526C[] = { 0x7400, 1, 0xE3D, 1, 0xFFFF };
u16 D_800A5278[] = { 0, 1, 0x7209, 1, 0x720B, 0, 0xE3D, 1, 0xFFFF };
u16 D_800A528C[] = { 0, 1, 0x7209, 1, 0x720B, 1, 0xE3D, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x7823, 1, 0xFFFF };
u16 D_800A52A8[] = { 0x11, 0, 0xFFFF };
u16 D_800A52B0[] = { 0x10, 0, 0xFFFF };
u16 D_800A52B8[] = { 0x11, 0, 0xFFFF };
u16 D_800A52C0[] = { 0x10, 1, 0xFFFF };
u16 D_800A52C8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52D4[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A52E0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52EC[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A52F8[] = { 0x11, 0, 0xFFFF };
u16 D_800A5300[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A530C[] = { 1, 1, 0xFFFF };
u16 D_800A5314[] = { 0x11, 0, 1, 1, 0x7206, 0, 0xFFFF };
u16 D_800A5324[] = { 0x11, 0, 1, 1, 0x7206, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5338[] = { 0x7624, 1, 0xFFFF };
u16 D_800A5340[] = {
    0x11, 0, 1, 1, 0x7206, 1, 0x7208, 1,
    0xE1D, 0, 0xFFFF,
};
u16 D_800A5358[] = { 0xE1D, 1, 0x7401, 1, 0xFFFF };
u16 D_800A5364[] = {
    0x11, 0, 1, 1, 0x7206, 1, 0x7208, 1,
    0xE1D, 1, 0x8014, 0, 0xFFFF,
};
u16 D_800A5380[] = {
    0x11, 0, 1, 1, 0x7206, 1, 0x7208, 1,
    0xE1D, 1, 0x8014, 1, 0x7209, 0, 0xFFFF,
};
u16 D_800A53A0[] = {
    0x11, 0, 1, 1, 0x7206, 1, 0x7208, 1,
    0xE1D, 1, 0x7209, 1, 0x8014, 1, 0xFFFF,
};
u16 D_800A53C0[] = { 0x7824, 1, 0xFFFF };
u16 D_800A53C8[] = { 1, 0, 0xFFFF };
u16 D_800A53D0[] = { 1, 1, 0xFFFF };
u16 D_800A53D8[] = { 1, 1, 0x7209, 0, 0xFFFF };
u16 D_800A53E4[] = { 1, 1, 0x7209, 1, 0xE3E, 0, 0xFFFF };
u16 D_800A53F4[] = { 0x7401, 1, 0xE3E, 1, 0xFFFF };
u16 D_800A5400[] = { 1, 1, 0x7209, 1, 0xE3E, 1, 0x720B, 0, 0xFFFF };
u16 D_800A5414[] = { 1, 1, 0x7209, 1, 0xE3E, 1, 0x720B, 1, 0xFFFF };
u16 D_800A5428[] = { 0x7824, 1, 0xFFFF };
u16 D_800A5430[] = { 0x11, 0, 0xFFFF };
u16 D_800A5438[] = { 0x10, 0, 0xFFFF };
u16 D_800A5440[] = { 0x11, 0, 0xFFFF };
u16 D_800A5448[] = { 0x10, 1, 0xFFFF };
u16 D_800A5450[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A545C[] = {
    { D_800A514C, D_800A5158, 0x24A },
    { D_800A5164, D_800A5170, 0x249 },
    { D_800A5178, D_800A5184, 0x24C },
    { D_800A518C, NULL, 0x24E },
    { D_800A519C, D_800A51B0, 0x246 },
    { D_800A51B8, D_800A51D0, 0x247 },
    { D_800A51DC, NULL, 0x228 },
    { D_800A51F8, NULL, 0x225 },
    { D_800A5218, D_800A5238, 0x246 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D4[] = {
    { D_800A5240, D_800A5248, 0x24C },
    { D_800A5250, NULL, 0x24E },
    { D_800A525C, D_800A526C, 0x24D },
    { D_800A5278, NULL, 0x248 },
    { D_800A528C, D_800A52A0, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A551C[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5534[] = {
    { D_800A52A8, NULL, 0x39B },
    { D_800A52B0, D_800A52B8, 0x249 },
    { D_800A52C0, D_800A52C8, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5564[] = {
    { D_800A52D4, D_800A52E0, 0x22A },
    { D_800A52EC, D_800A52F8, 0x229 },
    { D_800A5300, D_800A530C, 0x224 },
    { D_800A5314, NULL, 0x225 },
    { D_800A5324, D_800A5338, 0x226 },
    { D_800A5340, D_800A5358, 0x227 },
    { D_800A5364, NULL, 0x228 },
    { D_800A5380, NULL, 0x225 },
    { D_800A53A0, D_800A53C0, 0x226 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55DC[] = {
    { D_800A53C8, D_800A53D0, 0x22C },
    { D_800A53D8, NULL, 0x22E },
    { D_800A53E4, D_800A53F4, 0x22D },
    { D_800A5400, NULL, 0x228 },
    { D_800A5414, D_800A5428, 0x22F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5624[] = {
    { NULL, NULL, 0x22B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A563C[] = {
    { D_800A5430, NULL, 0x39D },
    { D_800A5438, D_800A5440, 0x229 },
    { D_800A5448, D_800A5450, 0x22A },
    { NULL, NULL, 0 },
};
u16 D_800A566C[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5678[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5680[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A568C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5694[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A56A0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A56A8[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A56B4[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A56BC = { D_800A566C, D_800A545C, 0x45, 4, 722, 161, 7 };
FieldActorEntry D_800A56D0 = { D_800A5678, D_800A54D4, 0x45, 4, 722, 161, 7 };
FieldActorEntry D_800A56E4 = { D_800A5680, D_800A551C, 0x45, 4, 722, 161, 7 };
FieldActorEntry D_800A56F8 = { D_800A568C, D_800A5534, 0x45, 4, 722, 161, 7 };
FieldActorEntry D_800A570C = { D_800A5694, D_800A5564, 0x46, 5, 786, 643, 3 };
FieldActorEntry D_800A5720 = { D_800A56A0, D_800A55DC, 0x46, 5, 786, 643, 3 };
FieldActorEntry D_800A5734 = { D_800A56A8, D_800A5624, 0x46, 5, 786, 643, 3 };
FieldActorEntry D_800A5748 = { D_800A56B4, D_800A563C, 0x46, 5, 786, 643, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A56BC,
    &D_800A56D0,
    &D_800A56E4,
    &D_800A56F8,
    &D_800A570C,
    &D_800A5720,
    &D_800A5734,
    &D_800A5748,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 311, 249, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 728, 359, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 930, 44, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 145, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 239, 425, 0, 0 },
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
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
