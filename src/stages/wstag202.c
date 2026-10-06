#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xCD
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x32A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xC5)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x339
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13500, 0x12500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern BattleList D_800A4FDC;
extern BattleList D_800A5060;
extern BattleList D_800A50E4;
extern BattleList D_800A5168;
extern u16 D_800A5308[];
extern u16 D_800A5310[];
extern u16 D_800A5318[];
extern u16 D_800A5320[];
extern u16 D_800A5328[];
extern u16 D_800A5330[];
extern u16 D_800A533C[];
extern u16 D_800A5344[];
extern u16 D_800A534C[];
extern u16 D_800A5354[];
extern u16 D_800A5C80[];
extern FieldTalk D_800A535C[];
extern u16 D_800A5C88[];
extern FieldTalk D_800A5374[];
extern u16 D_800A5C98[];
extern FieldTalk D_800A538C[];
extern u16 D_800A5CA0[];
extern FieldTalk D_800A53A4[];
extern u16 D_800A5CA8[];
extern FieldTalk D_800A53BC[];
extern u16 D_800A5CB0[];
extern FieldTalk D_800A53D4[];
extern u16 D_800A5CB8[];
extern FieldTalk D_800A53EC[];
extern u16 D_800A5CC0[];
extern FieldTalk D_800A5410[];
extern u16 D_800A5CC8[];
extern FieldTalk D_800A5428[];
extern u16 D_800A5CD0[];
extern FieldTalk D_800A5440[];
extern u16 D_800A5CD8[];
extern FieldTalk D_800A5458[];
extern u16 D_800A5CE0[];
extern FieldTalk D_800A5470[];
extern u16 D_800A5CE8[];
extern FieldTalk D_800A5488[];
extern u16 D_800A5CF8[];
extern FieldTalk D_800A54A0[];
extern u16 D_800A5D00[];
extern FieldTalk D_800A54B8[];
extern u16 D_800A5D08[];
extern FieldTalk D_800A54D0[];
extern u16 D_800A5D10[];
extern FieldTalk D_800A54E8[];
extern u16 D_800A5D18[];
extern FieldTalk D_800A5500[];
extern u16 D_800A5D20[];
extern FieldTalk D_800A5518[];
extern u16 D_800A5D28[];
extern FieldTalk D_800A5530[];
extern u16 D_800A5D30[];
extern FieldTalk D_800A5548[];
extern u16 D_800A5D38[];
extern FieldTalk D_800A5560[];
extern u16 D_800A5D40[];
extern FieldTalk D_800A5584[];
extern u16 D_800A5D48[];
extern FieldTalk D_800A559C[];
extern u16 D_800A5D50[];
extern FieldTalk D_800A55B4[];
extern u16 D_800A5D58[];
extern FieldTalk D_800A55CC[];
extern u16 D_800A5D64[];
extern FieldTalk D_800A55E4[];
extern u16 D_800A5D6C[];
extern FieldTalk D_800A55FC[];
extern u16 D_800A5D74[];
extern FieldTalk D_800A5614[];
extern u16 D_800A5D7C[];
extern FieldTalk D_800A562C[];
extern u16 D_800A5D84[];
extern FieldTalk D_800A5644[];
extern u16 D_800A5D8C[];
extern FieldTalk D_800A565C[];
extern u16 D_800A5D94[];
extern FieldTalk D_800A5674[];
extern u16 D_800A5D9C[];
extern FieldTalk D_800A568C[];
extern u16 D_800A5DA8[];
extern FieldTalk D_800A56A4[];
extern u16 D_800A5DB0[];
extern FieldTalk D_800A56BC[];
extern u16 D_800A5DB8[];
extern FieldTalk D_800A56D4[];
extern u16 D_800A5DC0[];
extern FieldTalk D_800A56EC[];
extern u16 D_800A5DC8[];
extern FieldTalk D_800A5704[];
extern u16 D_800A5DD0[];
extern FieldTalk D_800A571C[];
extern u16 D_800A5DD8[];
extern FieldTalk D_800A5734[];
extern u16 D_800A5DE0[];
extern FieldTalk D_800A574C[];
extern u16 D_800A5DE8[];
extern FieldTalk D_800A5764[];
extern u16 D_800A5DF4[];
extern FieldTalk D_800A577C[];
extern u16 D_800A5E00[];
extern FieldTalk D_800A5794[];
extern u16 D_800A5E08[];
extern FieldTalk D_800A57AC[];
extern u16 D_800A5E10[];
extern FieldTalk D_800A57C4[];
extern u16 D_800A5E18[];
extern FieldTalk D_800A57DC[];
extern u16 D_800A5E20[];
extern FieldTalk D_800A57F4[];
extern u16 D_800A5E28[];
extern FieldTalk D_800A580C[];
extern u16 D_800A5E30[];
extern FieldTalk D_800A5824[];
extern u16 D_800A5E38[];
extern FieldTalk D_800A583C[];
extern u16 D_800A5E40[];
extern FieldTalk D_800A5854[];
extern u16 D_800A5E48[];
extern FieldTalk D_800A586C[];
extern u16 D_800A5E50[];
extern FieldTalk D_800A5884[];
extern u16 D_800A5E58[];
extern FieldTalk D_800A589C[];
extern u16 D_800A5E60[];
extern FieldTalk D_800A58B4[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A58CC[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A58E4[];
extern u16 D_800A5E7C[];
extern FieldTalk D_800A58FC[];
extern u16 D_800A5E84[];
extern FieldTalk D_800A5914[];
extern u16 D_800A5E8C[];
extern FieldTalk D_800A592C[];
extern u16 D_800A5E94[];
extern FieldTalk D_800A5944[];
extern u16 D_800A5E9C[];
extern FieldTalk D_800A595C[];
extern u16 D_800A5EA4[];
extern FieldTalk D_800A5974[];
extern u16 D_800A5EAC[];
extern FieldTalk D_800A598C[];
extern u16 D_800A5EB4[];
extern FieldTalk D_800A59A4[];
extern u16 D_800A5EBC[];
extern FieldTalk D_800A59BC[];
extern u16 D_800A5EC4[];
extern FieldTalk D_800A59D4[];
extern u16 D_800A5ECC[];
extern FieldTalk D_800A59EC[];
extern u16 D_800A5ED4[];
extern FieldTalk D_800A5A04[];
extern u16 D_800A5EDC[];
extern FieldTalk D_800A5A1C[];
extern u16 D_800A5EE4[];
extern FieldTalk D_800A5A34[];
extern u16 D_800A5EEC[];
extern FieldTalk D_800A5A4C[];
extern u16 D_800A5EF4[];
extern FieldTalk D_800A5A64[];
extern u16 D_800A5EFC[];
extern FieldTalk D_800A5A7C[];
extern u16 D_800A5F04[];
extern FieldTalk D_800A5A94[];
extern u16 D_800A5F0C[];
extern FieldTalk D_800A5AAC[];
extern u16 D_800A5F14[];
extern FieldTalk D_800A5AC4[];
extern u16 D_800A5F1C[];
extern FieldTalk D_800A5ADC[];
extern u16 D_800A5F24[];
extern FieldTalk D_800A5AF4[];
extern u16 D_800A5F2C[];
extern FieldTalk D_800A5B0C[];
extern u16 D_800A5F38[];
extern FieldTalk D_800A5B24[];
extern u16 D_800A5F44[];
extern FieldTalk D_800A5B3C[];
extern u16 D_800A5F50[];
extern FieldTalk D_800A5B54[];
extern u16 D_800A5F58[];
extern FieldTalk D_800A5B6C[];
extern u16 D_800A5F6C[];
extern FieldTalk D_800A5B84[];
extern u16 D_800A5F74[];
extern FieldTalk D_800A5B9C[];
extern u16 D_800A5F7C[];
extern FieldTalk D_800A5BB4[];
extern u16 D_800A5F84[];
extern FieldTalk D_800A5BCC[];
extern u16 D_800A5F8C[];
extern FieldTalk D_800A5BE4[];
extern u16 D_800A5F94[];
extern FieldTalk D_800A5C08[];
extern u16 D_800A5F9C[];
extern FieldTalk D_800A5C20[];
extern u16 D_800A5FA4[];
extern FieldTalk D_800A5C38[];
extern u16 D_800A5FAC[];
extern FieldTalk D_800A5C50[];
extern u16 D_800A5FB4[];
extern FieldTalk D_800A5C68[];
extern FieldActorEntry D_800A5FBC;
extern FieldActorEntry D_800A5FD0;
extern FieldActorEntry D_800A5FE4;
extern FieldActorEntry D_800A5FF8;
extern FieldActorEntry D_800A600C;
extern FieldActorEntry D_800A6020;
extern FieldActorEntry D_800A6034;
extern FieldActorEntry D_800A6048;
extern FieldActorEntry D_800A605C;
extern FieldActorEntry D_800A6070;
extern FieldActorEntry D_800A6084;
extern FieldActorEntry D_800A6098;
extern FieldActorEntry D_800A60AC;
extern FieldActorEntry D_800A60C0;
extern FieldActorEntry D_800A60D4;
extern FieldActorEntry D_800A60E8;
extern FieldActorEntry D_800A60FC;
extern FieldActorEntry D_800A6110;
extern FieldActorEntry D_800A6124;
extern FieldActorEntry D_800A6138;
extern FieldActorEntry D_800A614C;
extern FieldActorEntry D_800A6160;
extern FieldActorEntry D_800A6174;
extern FieldActorEntry D_800A6188;
extern FieldActorEntry D_800A619C;
extern FieldActorEntry D_800A61B0;
extern FieldActorEntry D_800A61C4;
extern FieldActorEntry D_800A61D8;
extern FieldActorEntry D_800A61EC;
extern FieldActorEntry D_800A6200;
extern FieldActorEntry D_800A6214;
extern FieldActorEntry D_800A6228;
extern FieldActorEntry D_800A623C;
extern FieldActorEntry D_800A6250;
extern FieldActorEntry D_800A6264;
extern FieldActorEntry D_800A6278;
extern FieldActorEntry D_800A628C;
extern FieldActorEntry D_800A62A0;
extern FieldActorEntry D_800A62B4;
extern FieldActorEntry D_800A62C8;
extern FieldActorEntry D_800A62DC;
extern FieldActorEntry D_800A62F0;
extern FieldActorEntry D_800A6304;
extern FieldActorEntry D_800A6318;
extern FieldActorEntry D_800A632C;
extern FieldActorEntry D_800A6340;
extern FieldActorEntry D_800A6354;
extern FieldActorEntry D_800A6368;
extern FieldActorEntry D_800A637C;
extern FieldActorEntry D_800A6390;
extern FieldActorEntry D_800A63A4;
extern FieldActorEntry D_800A63B8;
extern FieldActorEntry D_800A63CC;
extern FieldActorEntry D_800A63E0;
extern FieldActorEntry D_800A63F4;
extern FieldActorEntry D_800A6408;
extern FieldActorEntry D_800A641C;
extern FieldActorEntry D_800A6430;
extern FieldActorEntry D_800A6444;
extern FieldActorEntry D_800A6458;
extern FieldActorEntry D_800A646C;
extern FieldActorEntry D_800A6480;
extern FieldActorEntry D_800A6494;
extern FieldActorEntry D_800A64A8;
extern FieldActorEntry D_800A64BC;
extern FieldActorEntry D_800A64D0;
extern FieldActorEntry D_800A64E4;
extern FieldActorEntry D_800A64F8;
extern FieldActorEntry D_800A650C;
extern FieldActorEntry D_800A6520;
extern FieldActorEntry D_800A6534;
extern FieldActorEntry D_800A6548;
extern FieldActorEntry D_800A655C;
extern FieldActorEntry D_800A6570;
extern FieldActorEntry D_800A6584;
extern FieldActorEntry D_800A6598;
extern FieldActorEntry D_800A65AC;
extern FieldActorEntry D_800A65C0;
extern FieldActorEntry D_800A65D4;
extern FieldActorEntry D_800A65E8;
extern FieldActorEntry D_800A65FC;
extern FieldActorEntry D_800A6610;
extern FieldActorEntry D_800A6624;
extern FieldActorEntry D_800A6638;
extern FieldActorEntry D_800A664C;
extern FieldActorEntry D_800A6660;
extern FieldActorEntry D_800A6674;
extern FieldActorEntry D_800A6688;
extern FieldActorEntry D_800A669C;
extern FieldActorEntry D_800A66B0;
extern FieldActorEntry D_800A66C4;
extern FieldActorEntry D_800A66D8;
extern FieldActorEntry D_800A66EC;
extern FieldActorEntry D_800A6700;
extern FieldActorEntry D_800A6714;
extern FieldActorEntry D_800A6728;
extern s16 D_800A4EB0[];

s16 D_800A4EB0[] = {
    0x102, 2, 0x220, 0x1B9, 3,
    0x100, 0x61, 0x200, 0x1A9,
    0x101, 0x61, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x61, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0x61, 0,
    0x301,
    0x101, 0x61, 1, 3,
    0x300, 0x1E,
    0x102, 0x61, 0x170, 0x165, 3,
    0x302, 0x61,
    0x200, 0, 5, 2, 3,
    0x100, 0x61, 0, 0,
    0x101, 0x61, 1, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x8FB1\n");
#endif
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
BattleList D_800A4FDC = {
    3,
    { &D_800A4F7C, &D_800A4F88, &D_800A4F94, &D_800A4FA0,
      &D_800A4FAC, &D_800A4FB8, &D_800A4FC4, &D_800A4FD0 },
};
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
BattleList D_800A5060 = {
    0,
    { &D_800A5000, &D_800A500C, &D_800A5018, &D_800A5024,
      &D_800A5030, &D_800A503C, &D_800A5048, &D_800A5054 },
};
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 0, 0, 0x60040000 };
BattleList D_800A50E4 = {
    0,
    { &D_800A5084, &D_800A5090, &D_800A509C, &D_800A50A8,
      &D_800A50B4, &D_800A50C0, &D_800A50CC, &D_800A50D8 },
};
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 328, 8, 0x60080000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
Battle D_800A515C = { 54, 8, 0x60080000 };
BattleList D_800A5168 = {
    0,
    { &D_800A5108, &D_800A5114, &D_800A5120, &D_800A512C,
      &D_800A5138, &D_800A5144, &D_800A5150, &D_800A515C },
};
FieldBattles stageBattles[] = {
    { 375, 0, 0, { &D_800A4FDC, &D_800A5060, &D_800A50E4, &D_800A5168 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B6, 0x128, 0x1D8, 0x28, 0x170, 0x1FD },
    { 0x180, 0x100, 0x18C, 0x171, 0x130, 0x71, 0x170, 0x1FC },
    { 0x180, 0x100, 0x180, 0x175, 0x100, 0x75, 0x140, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x150, 0x1C0, 0x50, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1B6, 0x178, 0x1D8, 0x78, 0x160, 0x1FB },
    { 0x180, 0x100, 0x194, 0x183, 0x150, 0x83, 0x170, 0x1FB },
    { 0x180, 0x100, 0x19C, 0x183, 0x170, 0x83, 0x140, 0x1FA },
    { 0x180, 0x100, 0x1A4, 0x18B, 0x190, 0x8B, 0x150, 0x1FA },
    { 0x180, 0x100, 0x188, 0x191, 0x120, 0x91, 0x160, 0x1FA },
    { 0x180, 0x100, 0x1A6, 0x163, 0x198, 0x63, 0x170, 0x1FA },
    { 0x180, 0x100, 0x180, 0x195, 0x100, 0x95, 0x140, 0x1F9 },
    { 0x180, 0x100, 0x1AC, 0x198, 0x1B0, 0x98, 0x150, 0x1F9 },
    { 0x180, 0x100, 0x1B4, 0x198, 0x1D0, 0x98, 0x160, 0x1F9 },
    { 0x180, 0x100, 0x190, 0x1A3, 0x140, 0xA3, 0x170, 0x1F9 },
    { 0x180, 0x100, 0x1AE, 0x178, 0x1B8, 0x78, 0x140, 0x1F8 },
};
u16 D_800A5308[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A5310[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A5318[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A5320[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A5328[] = { 0x1A1A, 1, 0xFFFF };
u16 D_800A5330[] = { 0x1A1B, 1, 0x905D, 1, 0xFFFF };
u16 D_800A533C[] = { 0x1A14, 1, 0xFFFF };
u16 D_800A5344[] = { 0x1A14, 1, 0xFFFF };
u16 D_800A534C[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A5354[] = { 0x1A18, 1, 0xFFFF };
FieldTalk D_800A535C[] = {
    { NULL, NULL, 0x12 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5374[] = {
    { NULL, NULL, 0x279 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A538C[] = {
    { NULL, NULL, 0x27A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53A4[] = {
    { NULL, NULL, 0x27B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53BC[] = {
    { NULL, NULL, 0x27C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53D4[] = {
    { NULL, NULL, 0x27D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53EC[] = {
    { D_800A5308, NULL, 0x279 },
    { D_800A5310, NULL, 0x4A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5410[] = {
    { NULL, NULL, 0x27E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5428[] = {
    { NULL, NULL, 0x27F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5440[] = {
    { NULL, NULL, 0x280 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5458[] = {
    { NULL, NULL, 0x4A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5470[] = {
    { NULL, NULL, 0xB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5488[] = {
    { NULL, NULL, 0x2C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A0[] = {
    { NULL, NULL, 0x2C8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B8[] = {
    { NULL, NULL, 0x2C9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D0[] = {
    { NULL, NULL, 0x2CA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E8[] = {
    { NULL, NULL, 0x2CB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5500[] = {
    { NULL, NULL, 0x4A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5518[] = {
    { NULL, NULL, 0x2CC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { NULL, NULL, 0x2CD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { NULL, NULL, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5560[] = {
    { D_800A5318, NULL, 0x2C7 },
    { D_800A5320, NULL, 0x4A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5584[] = {
    { NULL, NULL, 0x16 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A559C[] = {
    { NULL, NULL, 0x286 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B4[] = {
    { NULL, NULL, 0x282 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55CC[] = {
    { NULL, NULL, 0x283 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E4[] = {
    { NULL, NULL, 0x284 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55FC[] = {
    { NULL, NULL, 0x285 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5614[] = {
    { NULL, NULL, 0x28B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A562C[] = {
    { NULL, NULL, 0x287 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5644[] = {
    { NULL, NULL, 0x288 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A565C[] = {
    { NULL, NULL, 0x289 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5674[] = {
    { NULL, NULL, 0x28D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A568C[] = {
    { NULL, NULL, 0x28E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A4[] = {
    { NULL, NULL, 0x28F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56BC[] = {
    { NULL, NULL, 0x290 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D4[] = {
    { NULL, NULL, 0x17 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56EC[] = {
    { NULL, NULL, 0x291 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5704[] = {
    { NULL, NULL, 0x296 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A571C[] = {
    { NULL, NULL, 0x292 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5734[] = {
    { NULL, NULL, 0x293 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A574C[] = {
    { NULL, NULL, 0x294 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5764[] = {
    { NULL, D_800A5328, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A577C[] = {
    { NULL, D_800A5330, 0xBA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5794[] = {
    { NULL, NULL, 0x28A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57AC[] = {
    { NULL, NULL, 0x295 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C4[] = {
    { NULL, NULL, 0x281 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57DC[] = {
    { NULL, NULL, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57F4[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A580C[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5824[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A583C[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5854[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A586C[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5884[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A589C[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B4[] = {
    { NULL, NULL, 0x48B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58CC[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E4[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58FC[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5914[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A592C[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5944[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A595C[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5974[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A598C[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A4[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59BC[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D4[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59EC[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A04[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A1C[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A34[] = {
    { NULL, NULL, 0xBE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A4C[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A64[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A7C[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A94[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AAC[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC4[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ADC[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF4[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B0C[] = {
    { NULL, NULL, 0x48F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B24[] = {
    { NULL, D_800A533C, 0x427 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B3C[] = {
    { NULL, D_800A5344, 0x428 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B54[] = {
    { NULL, NULL, 0x18 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B6C[] = {
    { NULL, NULL, 0x2D1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B84[] = {
    { NULL, NULL, 0x2D2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B9C[] = {
    { NULL, NULL, 0x2D3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB4[] = {
    { NULL, NULL, 0x2D4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BCC[] = {
    { NULL, NULL, 0x2D5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE4[] = {
    { D_800A534C, NULL, 0x2D1 },
    { D_800A5354, NULL, 0x4A6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C08[] = {
    { NULL, NULL, 0x2D6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C20[] = {
    { NULL, NULL, 0x2D7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C38[] = {
    { NULL, NULL, 0x2D8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C50[] = {
    { NULL, NULL, 0x2D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C68[] = {
    { NULL, NULL, 0x4A6 },
    { NULL, NULL, 0 },
};
u16 D_800A5C80[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5C88[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5C98[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5CA0[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5CA8[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5CB0[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5CB8[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5CC0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5CC8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5CD0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5CD8[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5CE0[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5CE8[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5CF8[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5D00[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5D08[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5D10[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5D18[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5D20[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5D28[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5D30[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5D38[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5D40[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5D48[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5D50[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5D58[] = { 0x600C, 1, 0x1A0C, 0, 0xFFFF };
u16 D_800A5D64[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5D6C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5D74[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D7C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5D84[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5D8C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5D94[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5D9C[] = { 0x600C, 1, 0x1A0C, 0, 0xFFFF };
u16 D_800A5DA8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5DB0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5DB8[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5DC0[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5DC8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5DD0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5DD8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5DE0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5DE8[] = { 0x6008, 1, 0x1A19, 1, 0xFFFF };
u16 D_800A5DF4[] = { 0x6009, 1, 0x1A1B, 0, 0xFFFF };
u16 D_800A5E00[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E08[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E10[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E18[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E20[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5E28[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5E30[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5E38[] = { 0x601D, 1, 0xFFFF };
u16 D_800A5E40[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5E48[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5E50[] = { 0x6020, 1, 0xFFFF };
u16 D_800A5E58[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5E60[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5E6C[] = { 0x6005, 1, 0xFFFF };
u16 D_800A5E74[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5E7C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E84[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E8C[] = { 0x6010, 1, 0xFFFF };
u16 D_800A5E94[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5E9C[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5EA4[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5EAC[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5EB4[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5EBC[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5EC4[] = { 0x6022, 1, 0xFFFF };
u16 D_800A5ECC[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5ED4[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5EDC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5EE4[] = { 0x6027, 1, 0xFFFF };
u16 D_800A5EEC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5EF4[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5EFC[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5F04[] = { 0x601D, 1, 0xFFFF };
u16 D_800A5F0C[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5F14[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5F1C[] = { 0x6020, 1, 0xFFFF };
u16 D_800A5F24[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5F2C[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5F38[] = { 0x600C, 1, 0x1A0C, 1, 0xFFFF };
u16 D_800A5F44[] = { 0x1A0C, 1, 0x600C, 1, 0xFFFF };
u16 D_800A5F50[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5F58[] = { 0x7015, 1, 0x6006, 0, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5F6C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F74[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F7C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F84[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5F8C[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5F94[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F9C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5FA4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5FAC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FB4[] = { 0x6009, 1, 0xFFFF };
FieldActorEntry D_800A5FBC = { D_800A5C80, D_800A535C, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A5FD0 = { D_800A5C88, D_800A5374, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A5FE4 = { D_800A5C98, D_800A538C, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A5FF8 = { D_800A5CA0, D_800A53A4, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A600C = { D_800A5CA8, D_800A53BC, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6020 = { D_800A5CB0, D_800A53D4, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6034 = { D_800A5CB8, D_800A53EC, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6048 = { D_800A5CC0, D_800A5410, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A605C = { D_800A5CC8, D_800A5428, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6070 = { D_800A5CD0, D_800A5440, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6084 = { D_800A5CD8, D_800A5458, 0x2F, 4, 576, 160, 1 };
FieldActorEntry D_800A6098 = { D_800A5CE0, D_800A5470, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A60AC = { D_800A5CE8, D_800A5488, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A60C0 = { D_800A5CF8, D_800A54A0, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A60D4 = { D_800A5D00, D_800A54B8, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A60E8 = { D_800A5D08, D_800A54D0, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A60FC = { D_800A5D10, D_800A54E8, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A6110 = { D_800A5D18, D_800A5500, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A6124 = { D_800A5D20, D_800A5518, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A6138 = { D_800A5D28, D_800A5530, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A614C = { D_800A5D30, D_800A5548, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A6160 = { D_800A5D38, D_800A5560, 0x33, 5, 494, 187, 5 };
FieldActorEntry D_800A6174 = { D_800A5D40, D_800A5584, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A6188 = { D_800A5D48, D_800A559C, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A619C = { D_800A5D50, D_800A55B4, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A61B0 = { D_800A5D58, D_800A55CC, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A61C4 = { D_800A5D64, D_800A55E4, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A61D8 = { D_800A5D6C, D_800A55FC, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A61EC = { D_800A5D74, D_800A5614, 0x39, 6, 208, 344, 1 };
FieldActorEntry D_800A6200 = { D_800A5D7C, D_800A562C, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A6214 = { D_800A5D84, D_800A5644, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A6228 = { D_800A5D8C, D_800A565C, 0x39, 6, 680, 380, 1 };
FieldActorEntry D_800A623C = { D_800A5D94, D_800A5674, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A6250 = { D_800A5D9C, D_800A568C, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A6264 = { D_800A5DA8, D_800A56A4, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A6278 = { D_800A5DB0, D_800A56BC, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A628C = { D_800A5DB8, D_800A56D4, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A62A0 = { D_800A5DC0, D_800A56EC, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A62B4 = { D_800A5DC8, D_800A5704, 0x3A, 7, 494, 187, 1 };
FieldActorEntry D_800A62C8 = { D_800A5DD0, D_800A571C, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A62DC = { D_800A5DD8, D_800A5734, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A62F0 = { D_800A5DE0, D_800A574C, 0x3A, 7, 648, 396, 5 };
FieldActorEntry D_800A6304 = { D_800A5DE8, D_800A5764, 0x61, 8, 512, 425, 7 };
FieldActorEntry D_800A6318 = { D_800A5DF4, D_800A577C, 0x61, 8, 512, 425, 7 };
FieldActorEntry D_800A632C = { D_800A5E00, D_800A5794, 0x9D, 9, 680, 380, 1 };
FieldActorEntry D_800A6340 = { D_800A5E08, D_800A57AC, 0x9E, 0xA, 648, 396, 5 };
FieldActorEntry D_800A6354 = { D_800A5E10, D_800A57C4, 0x9F, 0xB, 576, 160, 1 };
FieldActorEntry D_800A6368 = { D_800A5E18, D_800A57DC, 0xA0, 0xC, 494, 187, 5 };
FieldActorEntry D_800A637C = { D_800A5E20, D_800A57F4, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A6390 = { D_800A5E28, D_800A580C, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A63A4 = { D_800A5E30, D_800A5824, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A63B8 = { D_800A5E38, D_800A583C, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A63CC = { D_800A5E40, D_800A5854, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A63E0 = { D_800A5E48, D_800A586C, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A63F4 = { D_800A5E50, D_800A5884, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A6408 = { D_800A5E58, D_800A589C, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A641C = { D_800A5E60, D_800A58B4, 0xB2, 0xD, 534, 435, 5 };
FieldActorEntry D_800A6430 = { D_800A5E6C, D_800A58CC, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6444 = { D_800A5E74, D_800A58E4, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6458 = { D_800A5E7C, D_800A58FC, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A646C = { D_800A5E84, D_800A5914, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6480 = { D_800A5E8C, D_800A592C, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6494 = { D_800A5E94, D_800A5944, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A64A8 = { D_800A5E9C, D_800A595C, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A64BC = { D_800A5EA4, D_800A5974, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A64D0 = { D_800A5EAC, D_800A598C, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A64E4 = { D_800A5EB4, D_800A59A4, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A64F8 = { D_800A5EBC, D_800A59BC, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A650C = { D_800A5EC4, D_800A59D4, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6520 = { D_800A5ECC, D_800A59EC, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6534 = { D_800A5ED4, D_800A5A04, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A6548 = { D_800A5EDC, D_800A5A1C, 0x118, 0xE, 864, 249, 1 };
FieldActorEntry D_800A655C = { D_800A5EE4, D_800A5A34, 0x119, 0xF, 864, 249, 1 };
FieldActorEntry D_800A6570 = { D_800A5EEC, D_800A5A4C, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A6584 = { D_800A5EF4, D_800A5A64, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A6598 = { D_800A5EFC, D_800A5A7C, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A65AC = { D_800A5F04, D_800A5A94, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A65C0 = { D_800A5F0C, D_800A5AAC, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A65D4 = { D_800A5F14, D_800A5AC4, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A65E8 = { D_800A5F1C, D_800A5ADC, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A65FC = { D_800A5F24, D_800A5AF4, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A6610 = { D_800A5F2C, D_800A5B0C, 0x13D, 0x10, 512, 424, 5 };
FieldActorEntry D_800A6624 = { D_800A5F38, D_800A5B24, 0x149, 0x11, 680, 380, 1 };
FieldActorEntry D_800A6638 = { D_800A5F44, D_800A5B3C, 0x14A, 0x12, 648, 396, 5 };
FieldActorEntry D_800A664C = { D_800A5F50, D_800A5B54, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6660 = { D_800A5F58, D_800A5B6C, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6674 = { D_800A5F6C, D_800A5B84, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6688 = { D_800A5F74, D_800A5B9C, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A669C = { D_800A5F7C, D_800A5BB4, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A66B0 = { D_800A5F84, D_800A5BCC, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A66C4 = { D_800A5F8C, D_800A5BE4, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A66D8 = { D_800A5F94, D_800A5C08, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A66EC = { D_800A5F9C, D_800A5C20, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6700 = { D_800A5FA4, D_800A5C38, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6714 = { D_800A5FAC, D_800A5C50, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry D_800A6728 = { D_800A5FB4, D_800A5C68, 0x171, 0x13, 208, 344, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5FBC,
    &D_800A5FD0,
    &D_800A5FE4,
    &D_800A5FF8,
    &D_800A600C,
    &D_800A6020,
    &D_800A6034,
    &D_800A6048,
    &D_800A605C,
    &D_800A6070,
    &D_800A6084,
    &D_800A6098,
    &D_800A60AC,
    &D_800A60C0,
    &D_800A60D4,
    &D_800A60E8,
    &D_800A60FC,
    &D_800A6110,
    &D_800A6124,
    &D_800A6138,
    &D_800A614C,
    &D_800A6160,
    &D_800A6174,
    &D_800A6188,
    &D_800A619C,
    &D_800A61B0,
    &D_800A61C4,
    &D_800A61D8,
    &D_800A61EC,
    &D_800A6200,
    &D_800A6214,
    &D_800A6228,
    &D_800A623C,
    &D_800A6250,
    &D_800A6264,
    &D_800A6278,
    &D_800A628C,
    &D_800A62A0,
    &D_800A62B4,
    &D_800A62C8,
    &D_800A62DC,
    &D_800A62F0,
    &D_800A6304,
    &D_800A6318,
    &D_800A632C,
    &D_800A6340,
    &D_800A6354,
    &D_800A6368,
    &D_800A637C,
    &D_800A6390,
    &D_800A63A4,
    &D_800A63B8,
    &D_800A63CC,
    &D_800A63E0,
    &D_800A63F4,
    &D_800A6408,
    &D_800A641C,
    &D_800A6430,
    &D_800A6444,
    &D_800A6458,
    &D_800A646C,
    &D_800A6480,
    &D_800A6494,
    &D_800A64A8,
    &D_800A64BC,
    &D_800A64D0,
    &D_800A64E4,
    &D_800A64F8,
    &D_800A650C,
    &D_800A6520,
    &D_800A6534,
    &D_800A6548,
    &D_800A655C,
    &D_800A6570,
    &D_800A6584,
    &D_800A6598,
    &D_800A65AC,
    &D_800A65C0,
    &D_800A65D4,
    &D_800A65E8,
    &D_800A65FC,
    &D_800A6610,
    &D_800A6624,
    &D_800A6638,
    &D_800A664C,
    &D_800A6660,
    &D_800A6674,
    &D_800A6688,
    &D_800A669C,
    &D_800A66B0,
    &D_800A66C4,
    &D_800A66D8,
    &D_800A66EC,
    &D_800A6700,
    &D_800A6714,
    &D_800A6728,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 174, 210, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 244, 175, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 840, 188, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 886, 211, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 341, 183, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 98, 114, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 168, 256, 0, 0 },
    { 1, 0, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 846, 150, 0, 0 },
    { 1, 0, 0x58, 2, 0xF, 0, 0, 0, 0, 0, 426, 256, 0, 0 },
    { 1, 0, 0x50, 2, 0x10, 0, 0, 0, 0, 0, 323, 384, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 640, 256, 0, 0 },
    { 1, 0, 0x60, 2, 0x12, 0, 0, 0, 0, 0, 548, 202, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 676, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 386, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 498, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 123, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 247, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 571, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 632, 171, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 654, 417, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 684, 140, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 719, 379, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 726, 101, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 772, 330, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 793, 216, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 994, 283, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 705, 485, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 706, 129, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 718, 471, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 741, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 757, 70, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 764, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 799, 58, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 855, 294, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 912, 279, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 119, 307, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 203, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 217, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 283, 332, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 598, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 647, 259, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 689, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 691, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 726, 257, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 742, 457, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 771, 233, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 798, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 810, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 819, 305, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 895, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 84, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 116, 353, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 277, 443, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 306, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 399, 464, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 610, 94, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 673, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 769, 210, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 776, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 802, 323, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 835, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 984, 292, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 199, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 416, 464, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 533, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 589, 85, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 659, 135, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 749, 190, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 790, 408, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 97, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 143, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 169, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 185, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 311, 450, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 465, 474, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 631, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 708, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 748, 169, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 758, 250, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 803, 312, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 820, 208, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 821, 53, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 822, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 961, 283, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 140, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 256, 443, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 360, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 400, 290, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 422, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 579, 126, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 594, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 594, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 596, 187, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 610, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 611, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 620, 136, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 633, 468, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 669, 271, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 699, 272, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 737, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 738, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 756, 153, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 771, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 782, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 784, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 819, 213, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 863, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 908, 242, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1023, 270, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 350, 152, 0, 0 },
    { 1, 0x65, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 463, 106, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 878, 199, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 268, 289, 0 },
    { 1, 0, 0x41, 4, 1, 0, 0, 0, 0, 0, 336, 159, 216, 0 },
    { 1, 0, 0x46, 4, 2, 0, 0, 0, 0, 0, 448, 103, 162, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 891, 200, 247, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20B, 0x68, 0x134, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x213, 0x218, 0xF4, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x211, 0x216, 0xE2, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x210, 0x98, 0x14A, 5, 0x66, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x20, 0x18, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x1C, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 220, D_800A4EB0, EVENT_TEXT(0x17), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
