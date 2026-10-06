#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x512
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x522
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE + 1;
    D_800990B4.start = (Vec2){0x16B00, 0x28500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
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
extern u16 D_800A52CC[];
extern u16 D_800A52D4[];
extern u16 D_800A52DC[];
extern u16 D_800A52E4[];
extern u16 D_800A52EC[];
extern u16 D_800A52F4[];
extern u16 D_800A52FC[];
extern u16 D_800A5304[];
extern u16 D_800A5314[];
extern u16 D_800A531C[];
extern u16 D_800A532C[];
extern u16 D_800A5338[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
extern u16 D_800A5360[];
extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A5700[];
extern FieldTalk D_800A537C[];
extern u16 D_800A5708[];
extern FieldTalk D_800A53A0[];
extern u16 D_800A5710[];
extern FieldTalk D_800A53C4[];
extern u16 D_800A5718[];
extern FieldTalk D_800A53E8[];
extern u16 D_800A5720[];
extern FieldTalk D_800A5400[];
extern u16 D_800A572C[];
extern FieldTalk D_800A5418[];
extern u16 D_800A5738[];
extern FieldTalk D_800A5430[];
extern u16 D_800A5740[];
extern FieldTalk D_800A5448[];
extern u16 D_800A574C[];
extern FieldTalk D_800A5460[];
extern u16 D_800A5754[];
extern FieldTalk D_800A5478[];
extern u16 D_800A575C[];
extern FieldTalk D_800A5490[];
extern u16 D_800A5768[];
extern FieldTalk D_800A54A8[];
extern u16 D_800A5774[];
extern FieldTalk D_800A54C0[];
extern u16 D_800A577C[];
extern FieldTalk D_800A54FC[];
extern u16 D_800A5784[];
extern FieldTalk D_800A5514[];
extern u16 D_800A578C[];
extern FieldTalk D_800A5544[];
extern u16 D_800A5794[];
extern FieldTalk D_800A5568[];
extern u16 D_800A57A0[];
extern FieldTalk D_800A5580[];
extern u16 D_800A57A8[];
extern FieldTalk D_800A5598[];
extern u16 D_800A57B4[];
extern FieldTalk D_800A55B0[];
extern u16 D_800A57BC[];
extern FieldTalk D_800A55C8[];
extern u16 D_800A57C4[];
extern FieldTalk D_800A55E0[];
extern u16 D_800A57D0[];
extern FieldTalk D_800A55F8[];
extern u16 D_800A57D8[];
extern FieldTalk D_800A5610[];
extern u16 D_800A57E4[];
extern FieldTalk D_800A5628[];
extern u16 D_800A57EC[];
extern FieldTalk D_800A5640[];
extern u16 D_800A57F8[];
extern FieldTalk D_800A5658[];
extern u16 D_800A5800[];
extern FieldTalk D_800A5670[];
extern u16 D_800A5808[];
extern FieldTalk D_800A5688[];
extern u16 D_800A5810[];
extern FieldTalk D_800A56A0[];
extern u16 D_800A5818[];
extern FieldTalk D_800A56B8[];
extern u16 D_800A5820[];
extern FieldTalk D_800A56D0[];
extern u16 D_800A5828[];
extern FieldTalk D_800A56E8[];
extern FieldActorEntry D_800A5830;
extern FieldActorEntry D_800A5844;
extern FieldActorEntry D_800A5858;
extern FieldActorEntry D_800A586C;
extern FieldActorEntry D_800A5880;
extern FieldActorEntry D_800A5894;
extern FieldActorEntry D_800A58A8;
extern FieldActorEntry D_800A58BC;
extern FieldActorEntry D_800A58D0;
extern FieldActorEntry D_800A58E4;
extern FieldActorEntry D_800A58F8;
extern FieldActorEntry D_800A590C;
extern FieldActorEntry D_800A5920;
extern FieldActorEntry D_800A5934;
extern FieldActorEntry D_800A5948;
extern FieldActorEntry D_800A595C;
extern FieldActorEntry D_800A5970;
extern FieldActorEntry D_800A5984;
extern FieldActorEntry D_800A5998;
extern FieldActorEntry D_800A59AC;
extern FieldActorEntry D_800A59C0;
extern FieldActorEntry D_800A59D4;
extern FieldActorEntry D_800A59E8;
extern FieldActorEntry D_800A59FC;
extern FieldActorEntry D_800A5A10;
extern FieldActorEntry D_800A5A24;
extern FieldActorEntry D_800A5A38;
extern FieldActorEntry D_800A5A4C;
extern FieldActorEntry D_800A5A60;
extern FieldActorEntry D_800A5A74;
extern FieldActorEntry D_800A5A88;
extern FieldActorEntry D_800A5A9C;
extern FieldActorEntry D_800A5AB0;

Battle D_800A4EA0 = { 0, 0, 0x60040000 };
Battle D_800A4EAC = { 0, 0, 0x60040000 };
Battle D_800A4EB8 = { 0, 0, 0x60040000 };
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
BattleList D_800A4F00 = {
    0,
    { &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4,
      &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4 },
};
Battle D_800A4F24 = { 0, 0, 0x60040000 };
Battle D_800A4F30 = { 0, 0, 0x60040000 };
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
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
Battle D_800A502C = { 195, 18, 0x60080000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 0, 0, 0x60040000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 0, 0, 0x60040000 };
Battle D_800A5080 = { 0, 0, 0x60040000 };
BattleList D_800A508C = {
    0,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
FieldBattles stageBattles[] = {
    { 142, 0, 0, { &D_800A4F00, &D_800A4F84, &D_800A5008, &D_800A508C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A2, 0x15A, 0x188, 0x5A, 0x170, 0x1FD },
    { 0x180, 0x100, 0x18E, 0x185, 0x138, 0x85, 0x170, 0x1FC },
    { 0x180, 0x100, 0x196, 0x186, 0x158, 0x86, 0x140, 0x1FB },
    { 0x1C0, 0x100, 0x1F8, 0x121, 0x2E0, 0x21, 0x150, 0x1FB },
    { 0x1C0, 0x100, 0x1DE, 0x130, 0x278, 0x30, 0x160, 0x1FB },
    { 0x1C0, 0x100, 0x1C0, 0x100, 0x200, 0, 0x170, 0x1FB },
    { 0x1C0, 0x100, 0x1C8, 0x100, 0x220, 0, 0x140, 0x1FA },
    { 0x1C0, 0x100, 0x1D0, 0x100, 0x240, 0, 0x150, 0x1FA },
    { 0x1C0, 0x100, 0x1CA, 0x140, 0x228, 0x40, 0x160, 0x1FA },
    { 0x1C0, 0x100, 0x1D2, 0x140, 0x248, 0x40, 0x170, 0x1FA },
    { 0x1C0, 0x100, 0x1D8, 0x100, 0x260, 0, 0x140, 0x1F9 },
    { 0x1C0, 0x100, 0x1E0, 0x100, 0x280, 0, 0x150, 0x1F9 },
    { 0x1C0, 0x100, 0x1E6, 0x100, 0x298, 0, 0x160, 0x1F9 },
    { 0x180, 0x100, 0x1AA, 0x188, 0x1A8, 0x88, 0x170, 0x1F9 },
    { 0x1C0, 0x100, 0x1E6, 0x148, 0x298, 0x48, 0x140, 0x1F8 },
    { 0x1C0, 0x100, 0x1DA, 0x150, 0x268, 0x50, 0x150, 0x1F8 },
    { 0x1C0, 0x100, 0x1EE, 0x154, 0x2B8, 0x54, 0x160, 0x1F8 },
    { 0x1C0, 0x100, 0x1F6, 0x154, 0x2D8, 0x54, 0x170, 0x1F8 },
    { 0x1C0, 0x100, 0x1C0, 0x158, 0x200, 0x58, 0x140, 0x1F7 },
    { 0x1C0, 0x100, 0x1C8, 0x160, 0x220, 0x60, 0x150, 0x1F7 },
    { 0x1C0, 0x100, 0x1D0, 0x160, 0x240, 0x60, 0x160, 0x1F7 },
    { 0x1C0, 0x100, 0x1E2, 0x168, 0x288, 0x68, 0x170, 0x1F7 },
    { 0x1C0, 0x100, 0x1D8, 0x170, 0x260, 0x70, 0x140, 0x1F6 },
    { 0x1C0, 0x100, 0x1F2, 0x174, 0x2C8, 0x74, 0x150, 0x1F6 },
    { 0x1C0, 0x100, 0x1C0, 0x178, 0x200, 0x78, 0x160, 0x1F6 },
    { 0x1C0, 0x100, 0x1C8, 0x180, 0x220, 0x80, 0x170, 0x1F6 },
};
u16 D_800A52CC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A52D4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A52E4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A52F4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5304[] = { 0x6026, 1, 0, 0, 0x1A0A, 0, 0xFFFF };
u16 D_800A5314[] = { 0, 1, 0xFFFF };
u16 D_800A531C[] = { 0x6026, 1, 0, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A532C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5338[] = { 0x6026, 1, 1, 0, 0x1A0A, 0, 0xFFFF };
u16 D_800A5348[] = { 1, 1, 0xFFFF };
u16 D_800A5350[] = { 0x6026, 1, 1, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5360[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A536C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5374[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A537C[] = {
    { D_800A52CC, NULL, 0xB5 },
    { D_800A52D4, NULL, 0xB6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53A0[] = {
    { D_800A52DC, NULL, 0xB8 },
    { D_800A52E4, NULL, 0xB9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C4[] = {
    { D_800A52EC, NULL, 0xBB },
    { D_800A52F4, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E8[] = {
    { NULL, NULL, 0xC4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5400[] = {
    { NULL, NULL, 0xC2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5418[] = {
    { NULL, NULL, 0xCA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5430[] = {
    { NULL, NULL, 0xC8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5448[] = {
    { NULL, NULL, 0xC6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5460[] = {
    { NULL, NULL, 0xD2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5478[] = {
    { NULL, NULL, 0xD3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5490[] = {
    { NULL, NULL, 0xCD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A8[] = {
    { NULL, NULL, 0xD0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C0[] = {
    { D_800A52FC, NULL, 0x1B6 },
    { D_800A5304, D_800A5314, 0x1FC },
    { D_800A531C, NULL, 0x1FD },
    { D_800A532C, NULL, 0x20A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54FC[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5514[] = {
    { D_800A5338, D_800A5348, 0x1FE },
    { D_800A5350, NULL, 0x1FF },
    { D_800A5360, NULL, 0x20B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5544[] = {
    { D_800A536C, NULL, 0xBE },
    { D_800A5374, NULL, 0xBF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5568[] = {
    { NULL, NULL, 0xCC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5580[] = {
    { NULL, NULL, 0xCE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5598[] = {
    { NULL, NULL, 0xCF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B0[] = {
    { NULL, NULL, 0xD1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C8[] = {
    { NULL, NULL, 0xC7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E0[] = {
    { NULL, NULL, 0xC5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F8[] = {
    { NULL, NULL, 0xCB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5610[] = {
    { NULL, NULL, 0xC9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5628[] = {
    { NULL, NULL, 0xC3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5640[] = {
    { NULL, NULL, 0xC1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5658[] = {
    { NULL, NULL, 0xB7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5670[] = {
    { NULL, NULL, 0xBA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5688[] = {
    { NULL, NULL, 0xBD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A0[] = {
    { NULL, NULL, 0xC0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B8[] = {
    { NULL, NULL, 0xD4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D0[] = {
    { NULL, NULL, 0xD5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E8[] = {
    { NULL, NULL, 0xD6 },
    { NULL, NULL, 0 },
};
u16 D_800A5700[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5708[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5710[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5718[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5720[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A572C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5738[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5740[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A574C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5754[] = { 0x602B, 1, 0xFFFF };
u16 D_800A575C[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5768[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5774[] = { 0x701C, 1, 0xFFFF };
u16 D_800A577C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5784[] = { 0x6026, 1, 0xFFFF };
u16 D_800A578C[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5794[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57A0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57A8[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57B4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57BC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57C4[] = { 0x1A0A, 0, 0x701C, 1, 0xFFFF };
u16 D_800A57D0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57D8[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57E4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57EC[] = { 0x1A0A, 0, 0x701C, 1, 0xFFFF };
u16 D_800A57F8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5800[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5808[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5810[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5818[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5820[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5828[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5830 = { D_800A5700, D_800A537C, 0x25, 4, 1088, 288, 3 };
FieldActorEntry D_800A5844 = { D_800A5708, D_800A53A0, 0x26, 5, 736, 392, 1 };
FieldActorEntry D_800A5858 = { D_800A5710, D_800A53C4, 0x27, 6, 555, 474, 1 };
FieldActorEntry D_800A586C = { D_800A5718, D_800A53E8, 0x2D, 7, 305, 616, 7 };
FieldActorEntry D_800A5880 = { D_800A5720, D_800A5400, 0x2D, 7, 268, 586, 7 };
FieldActorEntry D_800A5894 = { D_800A572C, D_800A5418, 0x2E, 8, 784, 264, 3 };
FieldActorEntry D_800A58A8 = { D_800A5738, D_800A5430, 0x30, 9, 944, 584, 1 };
FieldActorEntry D_800A58BC = { D_800A5740, D_800A5448, 0x30, 9, 944, 584, 1 };
FieldActorEntry D_800A58D0 = { D_800A574C, D_800A5460, 0x32, 0xA, 563, 559, 5 };
FieldActorEntry D_800A58E4 = { D_800A5754, D_800A5478, 0x38, 0xB, 905, 253, 5 };
FieldActorEntry D_800A58F8 = { D_800A575C, D_800A5490, 0x39, 0xC, 564, 558, 5 };
FieldActorEntry D_800A590C = { D_800A5768, D_800A54A8, 0x3A, 0xD, 595, 542, 1 };
FieldActorEntry D_800A5920 = { D_800A5774, D_800A54C0, 0x65, 0xE, 257, 704, 1 };
FieldActorEntry D_800A5934 = { D_800A577C, D_800A54FC, 0x66, 0xF, 905, 253, 5 };
FieldActorEntry D_800A5948 = { D_800A5784, D_800A5514, 0x67, 0x10, 225, 720, 5 };
FieldActorEntry D_800A595C = { D_800A578C, D_800A5544, 0x6F, 0x11, 464, 640, 5 };
FieldActorEntry D_800A5970 = { D_800A5794, D_800A5568, 0x9D, 0x12, 564, 558, 5 };
FieldActorEntry D_800A5984 = { D_800A57A0, D_800A5580, 0x9D, 0x12, 564, 558, 5 };
FieldActorEntry D_800A5998 = { D_800A57A8, D_800A5598, 0x9E, 0x13, 595, 542, 1 };
FieldActorEntry D_800A59AC = { D_800A57B4, D_800A55B0, 0x9E, 0x13, 595, 542, 1 };
FieldActorEntry D_800A59C0 = { D_800A57BC, D_800A55C8, 0x9F, 0x14, 944, 584, 1 };
FieldActorEntry D_800A59D4 = { D_800A57C4, D_800A55E0, 0x9F, 0x14, 944, 584, 1 };
FieldActorEntry D_800A59E8 = { D_800A57D0, D_800A55F8, 0xA0, 0x15, 784, 264, 3 };
FieldActorEntry D_800A59FC = { D_800A57D8, D_800A5610, 0xA0, 0x15, 784, 264, 3 };
FieldActorEntry D_800A5A10 = { D_800A57E4, D_800A5628, 0xA1, 0x16, 268, 586, 7 };
FieldActorEntry D_800A5A24 = { D_800A57EC, D_800A5640, 0xA1, 0x16, 268, 586, 7 };
FieldActorEntry D_800A5A38 = { D_800A57F8, D_800A5658, 0xA2, 0x17, 1088, 288, 3 };
FieldActorEntry D_800A5A4C = { D_800A5800, D_800A5670, 0xAE, 0x18, 736, 392, 1 };
FieldActorEntry D_800A5A60 = { D_800A5808, D_800A5688, 0xAF, 0x19, 555, 474, 1 };
FieldActorEntry D_800A5A74 = { D_800A5810, D_800A56A0, 0xB0, 0x1A, 464, 640, 1 };
FieldActorEntry D_800A5A88 = { D_800A5818, D_800A56B8, 0x177, 0x1B, 736, 393, 1 };
FieldActorEntry D_800A5A9C = { D_800A5820, D_800A56D0, 0x179, 0x1C, 464, 641, 5 };
FieldActorEntry D_800A5AB0 = { D_800A5828, D_800A56E8, 0x17B, 0x1D, 596, 543, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5830,
    &D_800A5844,
    &D_800A5858,
    &D_800A586C,
    &D_800A5880,
    &D_800A5894,
    &D_800A58A8,
    &D_800A58BC,
    &D_800A58D0,
    &D_800A58E4,
    &D_800A58F8,
    &D_800A590C,
    &D_800A5920,
    &D_800A5934,
    &D_800A5948,
    &D_800A595C,
    &D_800A5970,
    &D_800A5984,
    &D_800A5998,
    &D_800A59AC,
    &D_800A59C0,
    &D_800A59D4,
    &D_800A59E8,
    &D_800A59FC,
    &D_800A5A10,
    &D_800A5A24,
    &D_800A5A38,
    &D_800A5A4C,
    &D_800A5A60,
    &D_800A5A74,
    &D_800A5A88,
    &D_800A5A9C,
    &D_800A5AB0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 120, 520, 0, 0 },
    { 1, 0, 0x78, 2, 0x19, 0, 0, 0, 0, 0, 130, 528, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 1048, 211, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 437, 437, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 533, 389, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 3, 6, 0, 1231, 344, 0, 0 },
    { 1, 0, 0x40, 2, 0x4A, 2, 0, 3, 6, 0, 623, 331, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 352, 629, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 268, 384, 0, 0 },
    { 1, 0, 0x48, 2, 0x11, 0, 0, 0, 0, 0, 274, 440, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 1044, 416, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1088, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 430, 722, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 501, 687, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 945, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 1096, 700, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 1142, 723, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 483, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 597, 695, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 642, 672, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 754, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 3, 6, 0, 1023, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 669, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 145, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 290, 767, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 845, 621, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 903, 713, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 40, 693, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 191, 816, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 441, 795, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1030, 595, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1148, 406, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x14, 0, 0, 0, 0, 0, 277, 489, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 446, 416, 0, 0 },
    { 1, 0x66, 0x40, 6, 0x16, 0, 0, 0, 0, 0, 542, 367, 0, 0 },
    { 1, 0x67, 0x40, 6, 0x17, 0, 0, 0, 0, 0, 638, 321, 0, 0 },
    { 1, 0x68, 0x40, 6, 0x18, 0, 0, 0, 0, 0, 1045, 458, 0, 0 },
    { 1, 0, 0x68, 6, 6, 0, 0, 0, 0, 0, 879, 428, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 6, 0, 241, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 6, 0, 226, 450, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x53, 1, 0x53, 0x56, 6, 0, 1091, 316, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x57, 1, 0x57, 0x5A, 6, 0, 1103, 338, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 303, 495, 544, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 409, 416, 472, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 510, 375, 423, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 609, 327, 375, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1051, 192, 246, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 1073, 463, 512, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x272, 0x308, 0xE0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27E, 0xE0, 0x14E, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x178, 0x19C, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x218, 0x14C, 3, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x279, 0x116, 0xDA, 3, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x60, 0x190, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x275, 0xD8, 0x178, 5, 0x68, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
