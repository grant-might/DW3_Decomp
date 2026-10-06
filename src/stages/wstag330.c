#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x1A7
#define STAGE_ARCHIVE 0x319
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x1B5
#define STAGE_ARCHIVE 0x328
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x38400, 0x3E800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
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
extern u16 D_800A51EC[];
extern u16 D_800A51F4[];
extern u16 D_800A51FC[];
extern u16 D_800A5208[];
extern u16 D_800A5210[];
extern u16 D_800A521C[];
extern u16 D_800A5224[];
extern u16 D_800A522C[];
extern u16 D_800A523C[];
extern u16 D_800A5244[];
extern u16 D_800A524C[];
extern u16 D_800A5258[];
extern u16 D_800A5268[];
extern u16 D_800A527C[];
extern u16 D_800A5284[];
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52BC[];
extern u16 D_800A52C4[];
extern u16 D_800A52D0[];
extern u16 D_800A52E0[];
extern u16 D_800A52F4[];
extern u16 D_800A52FC[];
extern u16 D_800A5310[];
extern u16 D_800A5318[];
extern u16 D_800A5324[];
extern u16 D_800A532C[];
extern u16 D_800A5334[];
extern u16 D_800A533C[];
extern u16 D_800A5348[];
extern u16 D_800A5358[];
extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A5388[];
extern u16 D_800A5390[];
extern u16 D_800A539C[];
extern u16 D_800A53A4[];
extern u16 D_800A53AC[];
extern u16 D_800A53B4[];
extern u16 D_800A53C0[];
extern u16 D_800A53D0[];
extern u16 D_800A53E4[];
extern u16 D_800A53EC[];
extern u16 D_800A5400[];
extern u16 D_800A5408[];
extern u16 D_800A5414[];
extern u16 D_800A541C[];
extern u16 D_800A5424[];
extern u16 D_800A542C[];
extern u16 D_800A5438[];
extern u16 D_800A5448[];
extern u16 D_800A5450[];
extern u16 D_800A5464[];
extern u16 D_800A5470[];
extern u16 D_800A5488[];
extern u16 D_800A54A4[];
extern u16 D_800A54C0[];
extern u16 D_800A54C8[];
extern u16 D_800A54D0[];
extern u16 D_800A54DC[];
extern u16 D_800A54E4[];
extern u16 D_800A54F0[];
extern u16 D_800A54FC[];
extern u16 D_800A5504[];
extern u16 D_800A550C[];
extern u16 D_800A5518[];
extern u16 D_800A5528[];
extern u16 D_800A5530[];
extern u16 D_800A5544[];
extern u16 D_800A5550[];
extern u16 D_800A5568[];
extern u16 D_800A5584[];
extern u16 D_800A55A0[];
extern u16 D_800A55A8[];
extern u16 D_800A55B0[];
extern u16 D_800A55B8[];
extern u16 D_800A55C4[];
extern u16 D_800A55D4[];
extern u16 D_800A55DC[];
extern u16 D_800A55F0[];
extern u16 D_800A55FC[];
extern u16 D_800A5614[];
extern u16 D_800A5630[];
extern u16 D_800A564C[];
extern u16 D_800A5654[];
extern u16 D_800A565C[];
extern u16 D_800A5664[];
extern u16 D_800A566C[];
extern u16 D_800A5678[];
extern u16 D_800A5688[];
extern u16 D_800A5690[];
extern u16 D_800A56A4[];
extern u16 D_800A56AC[];
extern u16 D_800A56C4[];
extern u16 D_800A56E0[];
extern u16 D_800A56FC[];
extern u16 D_800A5D28[];
extern FieldTalk D_800A5704[];
extern u16 D_800A5D30[];
extern FieldTalk D_800A5734[];
extern u16 D_800A5D38[];
extern FieldTalk D_800A574C[];
extern u16 D_800A5D40[];
extern FieldTalk D_800A5764[];
extern u16 D_800A5D4C[];
extern FieldTalk D_800A57AC[];
extern u16 D_800A5D58[];
extern FieldTalk D_800A57D0[];
extern u16 D_800A5D64[];
extern FieldTalk D_800A5818[];
extern u16 D_800A5D70[];
extern FieldTalk D_800A583C[];
extern u16 D_800A5D7C[];
extern FieldTalk D_800A5884[];
extern u16 D_800A5D88[];
extern FieldTalk D_800A58A8[];
extern u16 D_800A5D94[];
extern FieldTalk D_800A58F0[];
extern u16 D_800A5DA0[];
extern FieldTalk D_800A5914[];
extern u16 D_800A5DB0[];
extern FieldTalk D_800A5974[];
extern u16 D_800A5DC0[];
extern FieldTalk D_800A59A4[];
extern u16 D_800A5DD0[];
extern FieldTalk D_800A5A04[];
extern u16 D_800A5DE0[];
extern FieldTalk D_800A5A64[];
extern u16 D_800A5DF0[];
extern FieldTalk D_800A5A7C[];
extern u16 D_800A5DF8[];
extern FieldTalk D_800A5A94[];
extern u16 D_800A5E00[];
extern FieldTalk D_800A5AAC[];
extern u16 D_800A5E08[];
extern FieldTalk D_800A5AC4[];
extern u16 D_800A5E10[];
extern FieldTalk D_800A5ADC[];
extern u16 D_800A5E18[];
extern FieldTalk D_800A5AF4[];
extern u16 D_800A5E24[];
extern FieldTalk D_800A5B0C[];
extern u16 D_800A5E2C[];
extern FieldTalk D_800A5B24[];
extern u16 D_800A5E34[];
extern FieldTalk D_800A5B3C[];
extern u16 D_800A5E40[];
extern FieldTalk D_800A5B54[];
extern u16 D_800A5E4C[];
extern FieldTalk D_800A5B6C[];
extern u16 D_800A5E54[];
extern FieldTalk D_800A5B84[];
extern FieldTalk D_800A5BA8[];
extern u16 D_800A5E5C[];
extern FieldTalk D_800A5BC0[];
extern u16 D_800A5E64[];
extern FieldTalk D_800A5BD8[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A5BF0[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A5C08[];
extern u16 D_800A5E7C[];
extern FieldTalk D_800A5C20[];
extern u16 D_800A5E84[];
extern FieldTalk D_800A5C38[];
extern u16 D_800A5E8C[];
extern FieldTalk D_800A5C50[];
extern u16 D_800A5E94[];
extern FieldTalk D_800A5C68[];
extern u16 D_800A5E9C[];
extern FieldTalk D_800A5C80[];
extern u16 D_800A5EA4[];
extern FieldTalk D_800A5CE0[];
extern u16 D_800A5EAC[];
extern FieldTalk D_800A5CF8[];
extern u16 D_800A5EB4[];
extern FieldTalk D_800A5D10[];
extern FieldActorEntry D_800A5EBC;
extern FieldActorEntry D_800A5ED0;
extern FieldActorEntry D_800A5EE4;
extern FieldActorEntry D_800A5EF8;
extern FieldActorEntry D_800A5F0C;
extern FieldActorEntry D_800A5F20;
extern FieldActorEntry D_800A5F34;
extern FieldActorEntry D_800A5F48;
extern FieldActorEntry D_800A5F5C;
extern FieldActorEntry D_800A5F70;
extern FieldActorEntry D_800A5F84;
extern FieldActorEntry D_800A5F98;
extern FieldActorEntry D_800A5FAC;
extern FieldActorEntry D_800A5FC0;
extern FieldActorEntry D_800A5FD4;
extern FieldActorEntry D_800A5FE8;
extern FieldActorEntry D_800A5FFC;
extern FieldActorEntry D_800A6010;
extern FieldActorEntry D_800A6024;
extern FieldActorEntry D_800A6038;
extern FieldActorEntry D_800A604C;
extern FieldActorEntry D_800A6060;
extern FieldActorEntry D_800A6074;
extern FieldActorEntry D_800A6088;
extern FieldActorEntry D_800A609C;
extern FieldActorEntry D_800A60B0;
extern FieldActorEntry D_800A60C4;
extern FieldActorEntry D_800A60D8;
extern FieldActorEntry D_800A60EC;
extern FieldActorEntry D_800A6100;
extern FieldActorEntry D_800A6114;
extern FieldActorEntry D_800A6128;
extern FieldActorEntry D_800A613C;
extern FieldActorEntry D_800A6150;
extern FieldActorEntry D_800A6164;
extern FieldActorEntry D_800A6178;
extern FieldActorEntry D_800A618C;
extern FieldActorEntry D_800A61A0;
extern FieldActorEntry D_800A61B4;
extern FieldActorEntry D_800A61C8;
extern FieldActorEntry D_800A61DC;

Battle D_800A4EA0 = { 34, 1, 0x60080000 };
Battle D_800A4EAC = { 34, 1, 0x60080000 };
Battle D_800A4EB8 = { 34, 1, 0x60080000 };
Battle D_800A4EC4 = { 34, 1, 0x60080000 };
Battle D_800A4ED0 = { 34, 1, 0x60080000 };
Battle D_800A4EDC = { 35, 1, 0x60080000 };
Battle D_800A4EE8 = { 35, 1, 0x60080000 };
Battle D_800A4EF4 = { 35, 1, 0x60080000 };
BattleList D_800A4F00 = {
    3,
    { &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4,
      &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4 },
};
Battle D_800A4F24 = { 34, 1, 0x60080000 };
Battle D_800A4F30 = { 34, 1, 0x60080000 };
Battle D_800A4F3C = { 34, 1, 0x60080000 };
Battle D_800A4F48 = { 34, 1, 0x60080000 };
Battle D_800A4F54 = { 34, 1, 0x60080000 };
Battle D_800A4F60 = { 35, 1, 0x60080000 };
Battle D_800A4F6C = { 35, 1, 0x60080000 };
Battle D_800A4F78 = { 35, 1, 0x60080000 };
BattleList D_800A4F84 = {
    1,
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
Battle D_800A502C = { 201, 1, 0x600C0000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 327, 1, 0x60080000 };
Battle D_800A505C = { 328, 8, 0x60080000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 49, 1, 0x60080000 };
Battle D_800A5080 = { 54, 8, 0x60080000 };
BattleList D_800A508C = {
    0,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
FieldBattles stageBattles[] = {
    { 1, 0, 0, { &D_800A4F00, &D_800A4F84, &D_800A5008, &D_800A508C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x1C4, 0xD8, 0xC4, 0x160, 0x1FF },
    { 0x140, 0x100, 0x178, 0x130, 0xE0, 0x30, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B6, 0x11B, 0x1D8, 0x1B, 0x140, 0x1FE },
    { 0x180, 0x100, 0x180, 0x11F, 0x100, 0x1F, 0x150, 0x1FE },
    { 0x180, 0x100, 0x188, 0x11F, 0x120, 0x1F, 0x160, 0x1FE },
    { 0x180, 0x100, 0x190, 0x11F, 0x140, 0x1F, 0x170, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x11F, 0x180, 0x1F, 0x160, 0x1FD },
    { 0x180, 0x100, 0x190, 0x13F, 0x140, 0x3F, 0x170, 0x1FD },
    { 0x180, 0x100, 0x198, 0x13F, 0x160, 0x3F, 0x140, 0x1FC },
    { 0x180, 0x100, 0x1A0, 0x13F, 0x180, 0x3F, 0x150, 0x1FC },
};
u16 D_800A51EC[] = { 0x8028, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x9400, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x8029, 0, 0x8028, 1, 0xFFFF };
u16 D_800A5208[] = { 0x9401, 1, 0xFFFF };
u16 D_800A5210[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A521C[] = { 0x9406, 1, 0xFFFF };
u16 D_800A5224[] = { 0x940D, 1, 0xFFFF };
u16 D_800A522C[] = { 0x201, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A523C[] = { 0x1A1F, 0, 0xFFFF };
u16 D_800A5244[] = { 0x1A1F, 1, 0xFFFF };
u16 D_800A524C[] = { 0x1A1F, 1, 0x702D, 0, 0xFFFF };
u16 D_800A5258[] = { 0x1A1F, 1, 0x702D, 1, 0x7026, 0, 0xFFFF };
u16 D_800A5268[] = { 0x7026, 1, 0x702D, 1, 0x1A1F, 1, 0x7028, 0, 0xFFFF };
u16 D_800A527C[] = { 0x602, 1, 0xFFFF };
u16 D_800A5284[] = { 0x1A1F, 1, 0x702D, 1, 0x7026, 1, 0x7028, 1, 0xFFFF };
u16 D_800A5298[] = { 0x700E, 0, 0xFFFF };
u16 D_800A52A0[] = { 0x7034, 1, 0x7013, 1, 0xFFFF };
u16 D_800A52AC[] = { 0x700E, 1, 0xFFFF };
u16 D_800A52B4[] = { 0x1A1F, 0, 0xFFFF };
u16 D_800A52BC[] = { 0x1A1F, 1, 0xFFFF };
u16 D_800A52C4[] = { 0x1A1F, 1, 0x702D, 0, 0xFFFF };
u16 D_800A52D0[] = { 0x1A1F, 1, 0x702D, 1, 0x7026, 0, 0xFFFF };
u16 D_800A52E0[] = { 0x1A1F, 1, 0x702D, 1, 0x7026, 1, 0x7028, 0, 0xFFFF };
u16 D_800A52F4[] = { 0x602, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x1A1F, 1, 0x702D, 1, 0x7026, 1, 0x7028, 1, 0xFFFF };
u16 D_800A5310[] = { 0x700E, 0, 0xFFFF };
u16 D_800A5318[] = { 0x7034, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5324[] = { 0x700E, 1, 0xFFFF };
u16 D_800A532C[] = { 0x1A20, 0, 0xFFFF };
u16 D_800A5334[] = { 0x1A20, 1, 0xFFFF };
u16 D_800A533C[] = { 0x1A20, 1, 0x7036, 0, 0xFFFF };
u16 D_800A5348[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 0, 0xFFFF };
u16 D_800A5358[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 1, 0x7028, 0, 0xFFFF };
u16 D_800A536C[] = { 0x603, 1, 0xFFFF };
u16 D_800A5374[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 1, 0x7028, 1, 0xFFFF };
u16 D_800A5388[] = { 0x700F, 0, 0xFFFF };
u16 D_800A5390[] = { 0x7035, 1, 0x7013, 1, 0xFFFF };
u16 D_800A539C[] = { 0x700F, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x1A20, 0, 0xFFFF };
u16 D_800A53AC[] = { 0x1A20, 1, 0xFFFF };
u16 D_800A53B4[] = { 0x1A20, 1, 0x7036, 0, 0xFFFF };
u16 D_800A53C0[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 0, 0xFFFF };
u16 D_800A53D0[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 1, 0x7028, 0, 0xFFFF };
u16 D_800A53E4[] = { 0x603, 1, 0xFFFF };
u16 D_800A53EC[] = { 0x1A20, 1, 0x7036, 1, 0x7026, 1, 0x7028, 1, 0xFFFF };
u16 D_800A5400[] = { 0x700F, 0, 0xFFFF };
u16 D_800A5408[] = { 0x7035, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5414[] = { 0x700F, 1, 0xFFFF };
u16 D_800A541C[] = { 0, 0, 0xFFFF };
u16 D_800A5424[] = { 0, 1, 0xFFFF };
u16 D_800A542C[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A5438[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5448[] = { 0x7605, 1, 0xFFFF };
u16 D_800A5450[] = { 0, 1, 0x7200, 1, 0x7202, 1, 0xE01, 0, 0xFFFF };
u16 D_800A5464[] = { 0xE01, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5470[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 0,
    0xE01, 1, 0xFFFF,
};
u16 D_800A5488[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 0, 0xE01, 1, 0xFFFF,
};
u16 D_800A54A4[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 1, 0xE01, 1, 0xFFFF,
};
u16 D_800A54C0[] = { 0x7805, 1, 0xFFFF };
u16 D_800A54C8[] = { 0x11, 0, 0xFFFF };
u16 D_800A54D0[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A54DC[] = { 0x11, 0, 0xFFFF };
u16 D_800A54E4[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A54F0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A54FC[] = { 0, 0, 0xFFFF };
u16 D_800A5504[] = { 0, 1, 0xFFFF };
u16 D_800A550C[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A5518[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5528[] = { 0x7605, 1, 0xFFFF };
u16 D_800A5530[] = { 0, 1, 0x7202, 1, 0x7200, 1, 0xE01, 0, 0xFFFF };
u16 D_800A5544[] = { 0x7400, 1, 0xE01, 1, 0xFFFF };
u16 D_800A5550[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 0,
    0xE01, 1, 0xFFFF,
};
u16 D_800A5568[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 0, 0xE01, 1, 0xFFFF,
};
u16 D_800A5584[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 1, 0xE01, 1, 0xFFFF,
};
u16 D_800A55A0[] = { 0x7805, 1, 0xFFFF };
u16 D_800A55A8[] = { 0, 0, 0xFFFF };
u16 D_800A55B0[] = { 0, 1, 0xFFFF };
u16 D_800A55B8[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A55C4[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A55D4[] = { 0x7605, 1, 0xFFFF };
u16 D_800A55DC[] = { 0, 1, 0x7202, 1, 0x7200, 1, 0xE01, 0, 0xFFFF };
u16 D_800A55F0[] = { 0x7400, 1, 0xE01, 1, 0xFFFF };
u16 D_800A55FC[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 0,
    0xE01, 1, 0xFFFF,
};
u16 D_800A5614[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 0, 0xE01, 1, 0xFFFF,
};
u16 D_800A5630[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 1, 0xE01, 1, 0xFFFF,
};
u16 D_800A564C[] = { 0x7805, 1, 0xFFFF };
u16 D_800A5654[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A565C[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A5664[] = { 0, 0, 0xFFFF };
u16 D_800A566C[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A5678[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5688[] = { 0x7605, 1, 0xFFFF };
u16 D_800A5690[] = { 0, 1, 0x7200, 1, 0x7202, 1, 0xE01, 0, 0xFFFF };
u16 D_800A56A4[] = { 0xE01, 1, 0xFFFF };
u16 D_800A56AC[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 0,
    0xE01, 1, 0xFFFF,
};
u16 D_800A56C4[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 0, 0xE01, 1, 0xFFFF,
};
u16 D_800A56E0[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0x8012, 1,
    0x7204, 1, 0xE01, 1, 0xFFFF,
};
u16 D_800A56FC[] = { 0x7805, 1, 0xFFFF };
FieldTalk D_800A5704[] = {
    { D_800A51EC, D_800A51F4, 0x1B },
    { D_800A51FC, D_800A5208, 0x1B },
    { D_800A5210, D_800A521C, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5734[] = {
    { NULL, D_800A5224, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A574C[] = {
    { NULL, D_800A522C, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5764[] = {
    { D_800A523C, D_800A5244, 0x277 },
    { D_800A524C, NULL, 0x282 },
    { D_800A5258, NULL, 0x278 },
    { D_800A5268, D_800A527C, 0x279 },
    { D_800A5284, NULL, 0x28C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57AC[] = {
    { D_800A5298, D_800A52A0, 0x27A },
    { D_800A52AC, NULL, 0x27C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D0[] = {
    { D_800A52B4, D_800A52BC, 0x277 },
    { D_800A52C4, NULL, 0x282 },
    { D_800A52D0, NULL, 0x278 },
    { D_800A52E0, D_800A52F4, 0x279 },
    { D_800A52FC, NULL, 0x28C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5818[] = {
    { D_800A5310, D_800A5318, 0x27A },
    { D_800A5324, NULL, 0x27C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A583C[] = {
    { D_800A532C, D_800A5334, 0x285 },
    { D_800A533C, NULL, 0x28B },
    { D_800A5348, NULL, 0x286 },
    { D_800A5358, D_800A536C, 0x287 },
    { D_800A5374, NULL, 0x28D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5884[] = {
    { D_800A5388, D_800A5390, 0x288 },
    { D_800A539C, NULL, 0x28A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58A8[] = {
    { D_800A53A4, D_800A53AC, 0x285 },
    { D_800A53B4, NULL, 0x28B },
    { D_800A53C0, NULL, 0x286 },
    { D_800A53D0, D_800A53E4, 0x287 },
    { D_800A53EC, NULL, 0x28D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F0[] = {
    { D_800A5400, D_800A5408, 0x288 },
    { D_800A5414, NULL, 0x28A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5914[] = {
    { D_800A541C, D_800A5424, 0x2E },
    { D_800A542C, NULL, 0x33 },
    { D_800A5438, D_800A5448, 0x34 },
    { D_800A5450, D_800A5464, 0x35 },
    { D_800A5470, NULL, 0x36 },
    { D_800A5488, NULL, 0x37 },
    { D_800A54A4, D_800A54C0, 0x6A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5974[] = {
    { D_800A54C8, NULL, 0x2E },
    { D_800A54D0, D_800A54DC, 0x38 },
    { D_800A54E4, D_800A54F0, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A4[] = {
    { D_800A54FC, D_800A5504, 0x32 },
    { D_800A550C, NULL, 0x33 },
    { D_800A5518, D_800A5528, 0x34 },
    { D_800A5530, D_800A5544, 0x35 },
    { D_800A5550, NULL, 0x36 },
    { D_800A5568, NULL, 0x37 },
    { D_800A5584, D_800A55A0, 0x6A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A04[] = {
    { D_800A55A8, D_800A55B0, 0x30 },
    { D_800A55B8, NULL, 0x33 },
    { D_800A55C4, D_800A55D4, 0x34 },
    { D_800A55DC, D_800A55F0, 0x35 },
    { D_800A55FC, NULL, 0x36 },
    { D_800A5614, NULL, 0x37 },
    { D_800A5630, D_800A564C, 0x6A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A64[] = {
    { NULL, NULL, 0x270 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A7C[] = {
    { NULL, NULL, 0xEA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A94[] = {
    { NULL, NULL, 0xFE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AAC[] = {
    { NULL, NULL, 0x1A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC4[] = {
    { NULL, NULL, 0xFD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ADC[] = {
    { NULL, NULL, 0x102 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF4[] = {
    { NULL, NULL, 0x102 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B0C[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B24[] = {
    { NULL, NULL, 0x103 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B3C[] = {
    { NULL, NULL, 0x102 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B54[] = {
    { NULL, NULL, 0x101 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B6C[] = {
    { NULL, NULL, 0x101 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B84[] = {
    { D_800A5654, NULL, 0x102 },
    { D_800A565C, NULL, 0x10 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA8[] = {
    { NULL, NULL, 0xE9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC0[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BD8[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF0[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C08[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C20[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C38[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C50[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C68[] = {
    { NULL, NULL, 0x334 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C80[] = {
    { D_800A5664, NULL, 0x31 },
    { D_800A566C, NULL, 0x31 },
    { D_800A5678, D_800A5688, 0x31 },
    { D_800A5690, D_800A56A4, 0x31 },
    { D_800A56AC, NULL, 0x31 },
    { D_800A56C4, NULL, 0x31 },
    { D_800A56E0, D_800A56FC, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE0[] = {
    { NULL, NULL, 0x104 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CF8[] = {
    { NULL, NULL, 0x27B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D10[] = {
    { NULL, NULL, 0x289 },
    { NULL, NULL, 0 },
};
u16 D_800A5D28[] = { 0x802A, 0, 0xFFFF };
u16 D_800A5D30[] = { 0x802A, 1, 0xFFFF };
u16 D_800A5D38[] = { 0x201, 0, 0xFFFF };
u16 D_800A5D40[] = { 0x8027, 0, 0x7024, 1, 0xFFFF };
u16 D_800A5D4C[] = { 0x8027, 1, 0x7024, 1, 0xFFFF };
u16 D_800A5D58[] = { 0x602B, 1, 0x8027, 0, 0xFFFF };
u16 D_800A5D64[] = { 0x602B, 1, 0x8027, 1, 0xFFFF };
u16 D_800A5D70[] = { 0x7024, 1, 0x8026, 0, 0xFFFF };
u16 D_800A5D7C[] = { 0x7024, 1, 0x8026, 1, 0xFFFF };
u16 D_800A5D88[] = { 0x8026, 0, 0x602B, 1, 0xFFFF };
u16 D_800A5D94[] = { 0x602B, 1, 0x8026, 1, 0xFFFF };
u16 D_800A5DA0[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5DB0[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5DC0[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5DD0[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5DE0[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5DF0[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5DF8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E00[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5E08[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E10[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5E18[] = { 0x7020, 1, 0x6021, 0, 0xFFFF };
u16 D_800A5E24[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5E2C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5E34[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A5E40[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5E4C[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5E54[] = { 0x6014, 1, 0xFFFF };
u16 D_800A5E5C[] = { 0x6007, 1, 0xFFFF };
u16 D_800A5E64[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5E6C[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5E74[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5E7C[] = { 0x600B, 1, 0xFFFF };
u16 D_800A5E84[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E8C[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5E94[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E9C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EA4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EAC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EB4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5EBC = { D_800A5D28, D_800A5704, 0x1B, 4, 923, 374, 7 };
FieldActorEntry D_800A5ED0 = { D_800A5D30, D_800A5734, 0x1B, 4, 923, 374, 7 };
FieldActorEntry D_800A5EE4 = { D_800A5D38, D_800A574C, 0x21, 5, 738, 394, 1 };
FieldActorEntry D_800A5EF8 = { D_800A5D40, D_800A5764, 0x2B, 6, 737, 954, 3 };
FieldActorEntry D_800A5F0C = { D_800A5D4C, D_800A57AC, 0x2B, 6, 737, 954, 3 };
FieldActorEntry D_800A5F20 = { D_800A5D58, D_800A57D0, 0x2B, 6, 737, 954, 3 };
FieldActorEntry D_800A5F34 = { D_800A5D64, D_800A5818, 0x2B, 6, 737, 954, 3 };
FieldActorEntry D_800A5F48 = { D_800A5D70, D_800A583C, 0x2C, 7, 913, 233, 1 };
FieldActorEntry D_800A5F5C = { D_800A5D7C, D_800A5884, 0x2C, 7, 913, 233, 1 };
FieldActorEntry D_800A5F70 = { D_800A5D88, D_800A58A8, 0x2C, 7, 913, 233, 1 };
FieldActorEntry D_800A5F84 = { D_800A5D94, D_800A58F0, 0x2C, 7, 913, 233, 1 };
FieldActorEntry D_800A5F98 = { D_800A5DA0, D_800A5914, 0x30, 8, 1152, 793, 1 };
FieldActorEntry D_800A5FAC = { D_800A5DB0, D_800A5974, 0x30, 8, 1152, 793, 1 };
FieldActorEntry D_800A5FC0 = { D_800A5DC0, D_800A59A4, 0x30, 8, 1152, 793, 1 };
FieldActorEntry D_800A5FD4 = { D_800A5DD0, D_800A5A04, 0x30, 8, 1152, 793, 1 };
FieldActorEntry D_800A5FE8 = { D_800A5DE0, D_800A5A64, 0x30, 8, 1152, 793, 1 };
FieldActorEntry D_800A5FFC = { D_800A5DF0, D_800A5A7C, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6010 = { D_800A5DF8, D_800A5A94, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6024 = { D_800A5E00, D_800A5AAC, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6038 = { D_800A5E08, D_800A5AC4, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A604C = { D_800A5E10, D_800A5ADC, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6060 = { D_800A5E18, D_800A5AF4, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6074 = { D_800A5E24, D_800A5B0C, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A6088 = { D_800A5E2C, D_800A5B24, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A609C = { D_800A5E34, D_800A5B3C, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A60B0 = { D_800A5E40, D_800A5B54, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A60C4 = { D_800A5E4C, D_800A5B6C, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A60D8 = { D_800A5E54, D_800A5B84, 0x3A, 9, 1065, 997, 1 };
FieldActorEntry D_800A60EC = { NULL, D_800A5BA8, 0x3F, 0xA, 961, 681, 1 };
FieldActorEntry D_800A6100 = { D_800A5E5C, D_800A5BC0, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A6114 = { D_800A5E64, D_800A5BD8, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A6128 = { D_800A5E6C, D_800A5BF0, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A613C = { D_800A5E74, D_800A5C08, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A6150 = { D_800A5E7C, D_800A5C20, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A6164 = { D_800A5E84, D_800A5C38, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A6178 = { D_800A5E8C, D_800A5C50, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A618C = { D_800A5E94, D_800A5C68, 0x66, 0xB, 400, 784, 7 };
FieldActorEntry D_800A61A0 = { D_800A5E9C, D_800A5C80, 0x9D, 0xC, 1152, 793, 1 };
FieldActorEntry D_800A61B4 = { D_800A5EA4, D_800A5CE0, 0x9E, 0xD, 1065, 997, 1 };
FieldActorEntry D_800A61C8 = { D_800A5EAC, D_800A5CF8, 0x9F, 0xE, 737, 954, 3 };
FieldActorEntry D_800A61DC = { D_800A5EB4, D_800A5D10, 0xA0, 0xF, 913, 233, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5EBC,
    &D_800A5ED0,
    &D_800A5EE4,
    &D_800A5EF8,
    &D_800A5F0C,
    &D_800A5F20,
    &D_800A5F34,
    &D_800A5F48,
    &D_800A5F5C,
    &D_800A5F70,
    &D_800A5F84,
    &D_800A5F98,
    &D_800A5FAC,
    &D_800A5FC0,
    &D_800A5FD4,
    &D_800A5FE8,
    &D_800A5FFC,
    &D_800A6010,
    &D_800A6024,
    &D_800A6038,
    &D_800A604C,
    &D_800A6060,
    &D_800A6074,
    &D_800A6088,
    &D_800A609C,
    &D_800A60B0,
    &D_800A60C4,
    &D_800A60D8,
    &D_800A60EC,
    &D_800A6100,
    &D_800A6114,
    &D_800A6128,
    &D_800A613C,
    &D_800A6150,
    &D_800A6164,
    &D_800A6178,
    &D_800A618C,
    &D_800A61A0,
    &D_800A61B4,
    &D_800A61C8,
    &D_800A61DC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 6, 1, 6, 8, 8, 0, 787, 422, 0, 0 },
    { 1, 0, 0x40, 2, 9, 1, 9, 0xE, 8, 0, 202, 246, 0, 0 },
    { 1, 0, 0x40, 2, 9, 1, 9, 0xE, 8, 0, 410, 878, 0, 0 },
    { 1, 0, 0x40, 2, 9, 1, 9, 0xE, 8, 0, 1322, 886, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 150, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 500, 1060, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 575, 940, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 681, 1030, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 715, 1004, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 870, 843, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 910, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1271, 1057, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1520, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 97, 735, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 195, 304, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 268, 562, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 584, 151, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 668, 1135, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 738, 892, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 742, 475, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 750, 999, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1053, 1074, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1331, 461, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 182, 792, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 645, 1050, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 867, 469, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 869, 1066, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1399, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1458, 398, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 97, 892, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 138, 930, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 145, 273, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 180, 706, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 184, 407, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 293, 496, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 386, 648, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 495, 624, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 527, 75, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 530, 1028, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 611, 1160, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 643, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 910, 1071, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1039, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1365, 429, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1565, 333, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 212, 806, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 232, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 250, 329, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 367, 607, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 673, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1070, 347, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1172, 1074, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1298, 459, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 208, 525, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 261, 826, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 317, 582, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 468, 997, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 579, 1121, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 786, 1012, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 990, 1080, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1076, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1417, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1513, 371, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 78, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 113, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 133, 615, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 249, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 277, 870, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 459, 1003, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 554, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 569, 1062, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 675, 1037, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 711, 518, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 727, 511, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 751, 903, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 878, 1051, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 939, 488, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1088, 1054, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1279, 482, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1391, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1410, 546, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1486, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1589, 336, 0, 0 },
    { 1, 0, 0x72, 4, 0, 0, 0, 0, 0, 0, 765, 572, 665, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 951, 632, 679, 0 },
    { 1, 0, 0x7D, 4, 2, 0, 0, 0, 0, 0, 816, 122, 245, 0 },
    { 1, 0, 0x7D, 4, 3, 0, 0, 0, 0, 0, 800, 114, 238, 0 },
    { 1, 0, 0x7D, 4, 4, 0, 0, 0, 0, 0, 784, 106, 230, 0 },
    { 1, 0, 0x7D, 4, 5, 0, 0, 0, 0, 0, 767, 99, 223, 0 },
    { 1, 0, 0x46, 4, 0xF, 0, 0, 0, 0, 0, 1224, 424, 484, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 243, 754, 754, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 266, 606, 606, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 275, 778, 778, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 314, 630, 630, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 338, 538, 538, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 363, 654, 654, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 410, 678, 678, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 483, 930, 930, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 531, 906, 906, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 547, 674, 674, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 579, 882, 882, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 595, 650, 650, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 626, 474, 474, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 627, 858, 858, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 643, 994, 994, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 667, 454, 454, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 691, 490, 490, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 723, 826, 826, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 771, 802, 802, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 787, 938, 938, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 819, 778, 778, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 835, 194, 194, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 835, 914, 914, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 883, 890, 890, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 883, 938, 938, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 931, 914, 914, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 979, 378, 378, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 979, 890, 890, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1027, 402, 402, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1075, 426, 426, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1314, 642, 642, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1315, 690, 690, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1315, 738, 738, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 570, 570, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 618, 618, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 666, 666, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 714, 714, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 762, 762, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x202, 0x100, 0x1E0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21E, 0x7C, 0x7E, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21F, 0x30A, 0x98, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x220, 0x4AC, 0x326, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x2CE, 0x124, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x2DF, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x324, 0x170, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x333, 0x11A, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 1, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x11, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 3, 3 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 1, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x60, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x40, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x10, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x14, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 1, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
