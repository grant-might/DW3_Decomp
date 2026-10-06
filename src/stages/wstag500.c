#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x400A, 1);
    FLAGS_00.applyAction(0x1A32, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x3FE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x40E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11100, 0x35300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x12;
    D_800990B4.music = 0x60480000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern BattleList D_800A51BC;
extern BattleList D_800A5240;
extern BattleList D_800A52C4;
extern BattleList D_800A5348;
extern u16 D_800A54B8[];
extern u16 D_800A54C0[];
extern u16 D_800A54C8[];
extern u16 D_800A54D0[];
extern u16 D_800A54D8[];
extern u16 D_800A54E0[];
extern u16 D_800A54E8[];
extern u16 D_800A54F4[];
extern u16 D_800A54FC[];
extern u16 D_800A5508[];
extern u16 D_800A5514[];
extern u16 D_800A551C[];
extern u16 D_800A5524[];
extern u16 D_800A5530[];
extern u16 D_800A5540[];
extern u16 D_800A5548[];
extern u16 D_800A555C[];
extern u16 D_800A5568[];
extern u16 D_800A5580[];
extern u16 D_800A559C[];
extern u16 D_800A55B8[];
extern u16 D_800A55C0[];
extern u16 D_800A55C8[];
extern u16 D_800A55D0[];
extern u16 D_800A55DC[];
extern u16 D_800A55EC[];
extern u16 D_800A55F4[];
extern u16 D_800A5608[];
extern u16 D_800A5614[];
extern u16 D_800A562C[];
extern u16 D_800A5648[];
extern u16 D_800A5664[];
extern u16 D_800A566C[];
extern u16 D_800A5674[];
extern u16 D_800A567C[];
extern u16 D_800A5688[];
extern u16 D_800A5698[];
extern u16 D_800A56A0[];
extern u16 D_800A56B4[];
extern u16 D_800A56C0[];
extern u16 D_800A56D8[];
extern u16 D_800A56F4[];
extern u16 D_800A5710[];
extern u16 D_800A5718[];
extern u16 D_800A5720[];
extern u16 D_800A572C[];
extern u16 D_800A573C[];
extern u16 D_800A5744[];
extern u16 D_800A5758[];
extern u16 D_800A5760[];
extern u16 D_800A5778[];
extern u16 D_800A5794[];
extern u16 D_800A57B0[];
extern u16 D_800A57B8[];
extern u16 D_800A57C0[];
extern u16 D_800A57C8[];
extern u16 D_800A57D0[];
extern u16 D_800A57D8[];
extern u16 D_800A57E0[];
extern u16 D_800A57E8[];
extern u16 D_800A57F0[];
extern u16 D_800A57F8[];
extern u16 D_800A5800[];
extern u16 D_800A580C[];
extern u16 D_800A5814[];
extern u16 D_800A581C[];
extern u16 D_800A5824[];
extern u16 D_800A582C[];
extern u16 D_800A5834[];
extern u16 D_800A583C[];
extern u16 D_800A5D54[];
extern u16 D_800A5D5C[];
extern FieldTalk D_800A5844[];
extern u16 D_800A5D68[];
extern FieldTalk D_800A585C[];
extern u16 D_800A5D74[];
extern FieldTalk D_800A5874[];
extern u16 D_800A5D80[];
extern FieldTalk D_800A588C[];
extern u16 D_800A5D88[];
extern FieldTalk D_800A58A4[];
extern u16 D_800A5D90[];
extern FieldTalk D_800A58C8[];
extern u16 D_800A5D98[];
extern FieldTalk D_800A58E0[];
extern u16 D_800A5DA0[];
extern FieldTalk D_800A58F8[];
extern u16 D_800A5DA8[];
extern FieldTalk D_800A5910[];
extern u16 D_800A5DB4[];
extern FieldTalk D_800A5928[];
extern u16 D_800A5DBC[];
extern FieldTalk D_800A5940[];
extern u16 D_800A5DC4[];
extern FieldTalk D_800A5958[];
extern u16 D_800A5DCC[];
extern FieldTalk D_800A5970[];
extern u16 D_800A5DD4[];
extern FieldTalk D_800A5988[];
extern u16 D_800A5DDC[];
extern FieldTalk D_800A59A0[];
extern u16 D_800A5DEC[];
extern FieldTalk D_800A59D0[];
extern u16 D_800A5DFC[];
extern FieldTalk D_800A5A30[];
extern u16 D_800A5E0C[];
extern FieldTalk D_800A5A90[];
extern u16 D_800A5E1C[];
extern FieldTalk D_800A5AF0[];
extern u16 D_800A5E2C[];
extern FieldTalk D_800A5B08[];
extern u16 D_800A5E34[];
extern FieldTalk D_800A5B20[];
extern u16 D_800A5E3C[];
extern FieldTalk D_800A5B38[];
extern u16 D_800A5E44[];
extern FieldTalk D_800A5B50[];
extern u16 D_800A5E4C[];
extern FieldTalk D_800A5B68[];
extern u16 D_800A5E54[];
extern FieldTalk D_800A5B80[];
extern u16 D_800A5E5C[];
extern FieldTalk D_800A5B98[];
extern u16 D_800A5E64[];
extern FieldTalk D_800A5BB0[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A5BC8[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A5BE0[];
extern u16 D_800A5E7C[];
extern FieldTalk D_800A5BF8[];
extern u16 D_800A5E84[];
extern FieldTalk D_800A5C10[];
extern u16 D_800A5E8C[];
extern u16 D_800A5E98[];
extern FieldTalk D_800A5C28[];
extern u16 D_800A5EA0[];
extern FieldTalk D_800A5C40[];
extern u16 D_800A5EA8[];
extern FieldTalk D_800A5CA0[];
extern u16 D_800A5EB0[];
extern FieldTalk D_800A5CB8[];
extern u16 D_800A5EBC[];
extern FieldTalk D_800A5CD0[];
extern u16 D_800A5ECC[];
extern FieldTalk D_800A5D3C[];
extern FieldActorEntry D_800A5EDC;
extern FieldActorEntry D_800A5EF0;
extern FieldActorEntry D_800A5F04;
extern FieldActorEntry D_800A5F18;
extern FieldActorEntry D_800A5F2C;
extern FieldActorEntry D_800A5F40;
extern FieldActorEntry D_800A5F54;
extern FieldActorEntry D_800A5F68;
extern FieldActorEntry D_800A5F7C;
extern FieldActorEntry D_800A5F90;
extern FieldActorEntry D_800A5FA4;
extern FieldActorEntry D_800A5FB8;
extern FieldActorEntry D_800A5FCC;
extern FieldActorEntry D_800A5FE0;
extern FieldActorEntry D_800A5FF4;
extern FieldActorEntry D_800A6008;
extern FieldActorEntry D_800A601C;
extern FieldActorEntry D_800A6030;
extern FieldActorEntry D_800A6044;
extern FieldActorEntry D_800A6058;
extern FieldActorEntry D_800A606C;
extern FieldActorEntry D_800A6080;
extern FieldActorEntry D_800A6094;
extern FieldActorEntry D_800A60A8;
extern FieldActorEntry D_800A60BC;
extern FieldActorEntry D_800A60D0;
extern FieldActorEntry D_800A60E4;
extern FieldActorEntry D_800A60F8;
extern FieldActorEntry D_800A610C;
extern FieldActorEntry D_800A6120;
extern FieldActorEntry D_800A6134;
extern FieldActorEntry D_800A6148;
extern FieldActorEntry D_800A615C;
extern FieldActorEntry D_800A6170;
extern FieldActorEntry D_800A6184;
extern FieldActorEntry D_800A6198;
extern FieldActorEntry D_800A61AC;
extern FieldActorEntry D_800A61C0;
extern FieldActorEntry D_800A61D4;
extern s16 D_800A503C[];
extern s16 D_800A4EC0[];

s16 D_800A4EC0[] = {
    0x102, 2, 0x118, 0x194, 3,
    0x100, 0x65, 0xF8, 0x184,
    0x101, 0x65, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x65,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x65,
    0x300, 0x1E,
    0x200, 0, 1, 0x65, 2,
    0x301,
    0x300, 0x1E,
    0x302, 0x65,
    0x101, 0x65, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x65, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x65, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 0x65, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 0x65, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0x65, 0xE8, 0x18C, 1,
    0x302, 0x65,
    0x102, 0x65, 0x120, 0x1A8, 7,
    0x302, 0x65,
    0x101, 2, 1, 0,
    0x101, 0x65, 1, 4,
    0x300, 0x1E,
    0x200, 0, 0xB, 0x65, 1,
    0x301,
    0x101, 0x65, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x102, 0x65, 0x17E, 0x220, 7,
    0x302, 0x65,
    0x200, 0, 0xA, 2, 0,
    0x100, 0x65, 0, 0,
    0x101, 0x65, 1, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x6004\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x6008\n");
#endif
s16 D_800A503C[] = {
    0x600, 1, 2,
    0x102, 1, 0x202, 0x1B8, 1,
    0x102, 2, 0x178, 0x153, 1,
    0x100, 0xB, 0x126, 0x153,
    0x101, 0xB, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 6,
    0x101, 0x323, 0x325, 0xB,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xB,
    0x300, 0x1E,
    0x101, 1, 1, 2,
    0x101, 2, 1, 2,
    0x102, 0xB, 0x15E, 0x153, 6,
    0x302, 0xB,
    0x200, 0, 1, 0xB, 0,
    0x101, 0xB, 7, 6,
    0x301,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 1, 7, 2,
    0x101, 2, 7, 2,
    0x301,
    0x101, 1, 1, 2,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x200, 0, 3, 0xB, 0,
    0x101, 0xB, 7, 6,
    0x301,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x200, 0, 4, 2, 2,
    0x101, 1, 7, 2,
    0x101, 2, 7, 2,
    0x301,
    0x101, 1, 1, 2,
    0x101, 2, 1, 2,
    0x304, 0x204, 0x50, 0x198, 5,
    0,
};
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
BattleList D_800A51BC = {
    3,
    { &D_800A515C, &D_800A5168, &D_800A5174, &D_800A5180,
      &D_800A518C, &D_800A5198, &D_800A51A4, &D_800A51B0 },
};
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
Battle D_800A51F8 = { 0, 0, 0x60040000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
Battle D_800A521C = { 0, 0, 0x60040000 };
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
BattleList D_800A5240 = {
    0,
    { &D_800A51E0, &D_800A51EC, &D_800A51F8, &D_800A5204,
      &D_800A5210, &D_800A521C, &D_800A5228, &D_800A5234 },
};
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 0, 0, 0x60040000 };
Battle D_800A527C = { 0, 0, 0x60040000 };
Battle D_800A5288 = { 0, 0, 0x60040000 };
Battle D_800A5294 = { 0, 0, 0x60040000 };
Battle D_800A52A0 = { 0, 0, 0x60040000 };
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
BattleList D_800A52C4 = {
    0,
    { &D_800A5264, &D_800A5270, &D_800A527C, &D_800A5288,
      &D_800A5294, &D_800A52A0, &D_800A52AC, &D_800A52B8 },
};
Battle D_800A52E8 = { 215, 20, 0x600C0000 };
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
Battle D_800A530C = { 0, 0, 0x60040000 };
Battle D_800A5318 = { 0, 0, 0x60040000 };
Battle D_800A5324 = { 0, 0, 0x60040000 };
Battle D_800A5330 = { 0, 0, 0x60040000 };
Battle D_800A533C = { 0, 0, 0x60040000 };
BattleList D_800A5348 = {
    0,
    { &D_800A52E8, &D_800A52F4, &D_800A5300, &D_800A530C,
      &D_800A5318, &D_800A5324, &D_800A5330, &D_800A533C },
};
FieldBattles stageBattles[] = {
    { 157, 0, 0, { &D_800A51BC, &D_800A5240, &D_800A52C4, &D_800A5348 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x148, 0x19D, 0x20, 0x9D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x174, 0xB8, 0x74, 0x170, 0x1FF },
    { 0x140, 0x100, 0x156, 0x18C, 0x58, 0x8C, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x16D, 0, 0x6D, 0x160, 0x1FE },
    { 0x140, 0x100, 0x178, 0x19C, 0xE0, 0x9C, 0x170, 0x1FE },
    { 0x140, 0x100, 0x150, 0x1AC, 0x40, 0xAC, 0x150, 0x1FD },
    { 0x140, 0x100, 0x176, 0x174, 0xD8, 0x74, 0x160, 0x1FD },
    { 0x140, 0x100, 0x168, 0x19C, 0xA0, 0x9C, 0x160, 0x1FC },
    { 0x140, 0x100, 0x158, 0x1AC, 0x60, 0xAC, 0x170, 0x1FC },
    { 0x140, 0x100, 0x160, 0x1B9, 0x80, 0xB9, 0x140, 0x1FB },
    { 0x140, 0x100, 0x170, 0x1BC, 0xC0, 0xBC, 0x150, 0x1FB },
    { 0x140, 0x100, 0x140, 0x1BD, 0, 0xBD, 0x160, 0x1FB },
    { 0x140, 0x100, 0x14C, 0x16D, 0x30, 0x6D, 0x170, 0x1FB },
};
u16 D_800A54B8[] = { 0x7A09, 1, 0xFFFF };
u16 D_800A54C0[] = { 0x7A07, 1, 0xFFFF };
u16 D_800A54C8[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A54D8[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A54E0[] = { 0x11, 0, 0xFFFF };
u16 D_800A54E8[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A54F4[] = { 0x11, 0, 0xFFFF };
u16 D_800A54FC[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5508[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5514[] = { 0, 0, 0xFFFF };
u16 D_800A551C[] = { 0, 1, 0xFFFF };
u16 D_800A5524[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5530[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5540[] = { 0x7619, 1, 0xFFFF };
u16 D_800A5548[] = { 0, 1, 0x7204, 1, 0x7202, 1, 0xE0F, 0, 0xFFFF };
u16 D_800A555C[] = { 0x7400, 1, 0xE0F, 1, 0xFFFF };
u16 D_800A5568[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5580[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A559C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A55B8[] = { 0x7819, 1, 0xFFFF };
u16 D_800A55C0[] = { 0, 0, 0xFFFF };
u16 D_800A55C8[] = { 0, 1, 0xFFFF };
u16 D_800A55D0[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A55DC[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A55EC[] = { 0x7619, 1, 0xFFFF };
u16 D_800A55F4[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 0, 0xFFFF };
u16 D_800A5608[] = { 0x7400, 1, 0xE0F, 1, 0xFFFF };
u16 D_800A5614[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A562C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5648[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5664[] = { 0x7819, 1, 0xFFFF };
u16 D_800A566C[] = { 0, 0, 0xFFFF };
u16 D_800A5674[] = { 0, 1, 0xFFFF };
u16 D_800A567C[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5688[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5698[] = { 0x7619, 1, 0xFFFF };
u16 D_800A56A0[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 0, 0xFFFF };
u16 D_800A56B4[] = { 0x7400, 1, 0xE0F, 1, 0xFFFF };
u16 D_800A56C0[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A56D8[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A56F4[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5710[] = { 0x7819, 1, 0xFFFF };
u16 D_800A5718[] = { 0, 0, 0xFFFF };
u16 D_800A5720[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A572C[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A573C[] = { 0x7619, 1, 0xFFFF };
u16 D_800A5744[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 0, 0xFFFF };
u16 D_800A5758[] = { 0xE0F, 1, 0xFFFF };
u16 D_800A5760[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5778[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0F, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5794[] = {
    0xE0F, 1, 0, 1, 0x7202, 1, 0x7204, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A57B0[] = { 0x7819, 1, 0xFFFF };
u16 D_800A57B8[] = { 0x7A08, 1, 0xFFFF };
u16 D_800A57C0[] = { 0x7015, 1, 0xFFFF };
u16 D_800A57C8[] = { 0x7A3B, 1, 0xFFFF };
u16 D_800A57D0[] = { 0x703E, 1, 0xFFFF };
u16 D_800A57D8[] = { 0x7A3B, 1, 0xFFFF };
u16 D_800A57E0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A57E8[] = { 0x7A3C, 1, 0xFFFF };
u16 D_800A57F0[] = { 0x7020, 1, 0xFFFF };
u16 D_800A57F8[] = { 0x7A3C, 1, 0xFFFF };
u16 D_800A5800[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A580C[] = { 0x7A3D, 1, 0xFFFF };
u16 D_800A5814[] = { 0x6026, 1, 0xFFFF };
u16 D_800A581C[] = { 0x7A3E, 1, 0xFFFF };
u16 D_800A5824[] = { 0x701A, 1, 0xFFFF };
u16 D_800A582C[] = { 0x7A3E, 1, 0xFFFF };
u16 D_800A5834[] = { 0x602B, 1, 0xFFFF };
u16 D_800A583C[] = { 0x7A3E, 1, 0xFFFF };
FieldTalk D_800A5844[] = {
    { NULL, D_800A54B8, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A585C[] = {
    { NULL, D_800A54C0, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5874[] = {
    { NULL, D_800A54C8, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A588C[] = {
    { NULL, NULL, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58A4[] = {
    { D_800A54D0, NULL, 0x79 },
    { D_800A54D8, NULL, 0x3C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C8[] = {
    { NULL, NULL, 0x81 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E0[] = {
    { NULL, NULL, 0x7F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F8[] = {
    { NULL, NULL, 0x7B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5910[] = {
    { NULL, NULL, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5928[] = {
    { NULL, NULL, 0x77 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5940[] = {
    { NULL, NULL, 0x73 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5958[] = {
    { NULL, NULL, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5970[] = {
    { NULL, NULL, 0x7D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5988[] = {
    { NULL, NULL, 0x7D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A0[] = {
    { D_800A54E0, NULL, 0xE2 },
    { D_800A54E8, D_800A54F4, 0xED },
    { D_800A54FC, D_800A5508, 0xEE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D0[] = {
    { D_800A5514, D_800A551C, 0xE2 },
    { D_800A5524, NULL, 0xE7 },
    { D_800A5530, D_800A5540, 0xE8 },
    { D_800A5548, D_800A555C, 0xE9 },
    { D_800A5568, NULL, 0xEA },
    { D_800A5580, NULL, 0xEB },
    { D_800A559C, D_800A55B8, 0xEC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A30[] = {
    { D_800A55C0, D_800A55C8, 0xE4 },
    { D_800A55D0, NULL, 0xE7 },
    { D_800A55DC, D_800A55EC, 0xE8 },
    { D_800A55F4, D_800A5608, 0xE9 },
    { D_800A5614, NULL, 0xEA },
    { D_800A562C, NULL, 0xEB },
    { D_800A5648, D_800A5664, 0xEC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A90[] = {
    { D_800A566C, D_800A5674, 0xE3 },
    { D_800A567C, NULL, 0xE7 },
    { D_800A5688, D_800A5698, 0xE8 },
    { D_800A56A0, D_800A56B4, 0xE9 },
    { D_800A56C0, NULL, 0xEA },
    { D_800A56D8, NULL, 0xEB },
    { D_800A56F4, D_800A5710, 0xEC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF0[] = {
    { NULL, NULL, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B08[] = {
    { NULL, NULL, 0x70 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B20[] = {
    { NULL, NULL, 0x84 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B38[] = {
    { NULL, NULL, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B50[] = {
    { NULL, NULL, 0x7C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B68[] = {
    { NULL, NULL, 0x72 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B80[] = {
    { NULL, NULL, 0x75 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B98[] = {
    { NULL, NULL, 0x76 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB0[] = {
    { NULL, NULL, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC8[] = {
    { NULL, NULL, 0x80 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE0[] = {
    { NULL, NULL, 0x7A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF8[] = {
    { NULL, NULL, 0x7C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C10[] = {
    { NULL, NULL, 0x120 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C28[] = {
    { NULL, NULL, 0x82 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C40[] = {
    { D_800A5718, NULL, 0xE5 },
    { D_800A5720, NULL, 0xE5 },
    { D_800A572C, D_800A573C, 0xE5 },
    { D_800A5744, D_800A5758, 0xE5 },
    { D_800A5760, NULL, 0xE5 },
    { D_800A5778, NULL, 0xE5 },
    { D_800A5794, D_800A57B0, 0xE5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CA0[] = {
    { NULL, NULL, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB8[] = {
    { NULL, D_800A57B8, 0xF4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD0[] = {
    { D_800A57C0, D_800A57C8, 1 },
    { D_800A57D0, D_800A57D8, 1 },
    { D_800A57E0, D_800A57E8, 1 },
    { D_800A57F0, D_800A57F8, 1 },
    { D_800A5800, D_800A580C, 1 },
    { D_800A5814, D_800A581C, 1 },
    { D_800A5824, D_800A582C, 1 },
    { D_800A5834, D_800A583C, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D3C[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
u16 D_800A5D54[] = { 0x600B, 1, 0xFFFF };
u16 D_800A5D5C[] = { 0x7014, 1, 0x600B, 0, 0xFFFF };
u16 D_800A5D68[] = { 0x7014, 1, 0x600B, 0, 0xFFFF };
u16 D_800A5D74[] = { 0x7014, 1, 0x600B, 0, 0xFFFF };
u16 D_800A5D80[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5D88[] = { 0x6014, 1, 0xFFFF };
u16 D_800A5D90[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5D98[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5DA0[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5DA8[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A5DB4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5DBC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5DC4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5DCC[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5DD4[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5DDC[] = { 0x8192, 1, 0x11, 1, 0x7009, 1, 0xFFFF };
u16 D_800A5DEC[] = { 0x8192, 1, 0x11, 0, 0x7003, 1, 0xFFFF };
u16 D_800A5DFC[] = { 0x8192, 1, 0x6026, 1, 0x11, 0, 0xFFFF };
u16 D_800A5E0C[] = { 0x8192, 1, 0x11, 0, 0x7004, 1, 0xFFFF };
u16 D_800A5E1C[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5E2C[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5E34[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5E3C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5E44[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5E4C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E54[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E5C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5E64[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5E6C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5E74[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5E7C[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5E84[] = { 0x600B, 1, 0xFFFF };
u16 D_800A5E8C[] = { 0x600A, 1, 0x1A32, 0, 0xFFFF };
u16 D_800A5E98[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EA0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EA8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EB0[] = { 0x600B, 0, 0x7014, 1, 0xFFFF };
u16 D_800A5EBC[] = { 0x600B, 0, 0x7014, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5ECC[] = { 0x7014, 1, 0x600B, 0, 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A5EDC = { D_800A5D54, NULL, 0xB, 4, 294, 339, 7 };
FieldActorEntry D_800A5EF0 = { D_800A5D5C, D_800A5844, 0x16, 5, 923, 892, 3 };
FieldActorEntry D_800A5F04 = { D_800A5D68, D_800A585C, 0x17, 6, 816, 521, 1 };
FieldActorEntry D_800A5F18 = { D_800A5D74, D_800A5874, 0x18, 7, 1189, 666, 1 };
FieldActorEntry D_800A5F2C = { D_800A5D80, D_800A588C, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5F40 = { D_800A5D88, D_800A58A4, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5F54 = { D_800A5D90, D_800A58C8, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5F68 = { D_800A5D98, D_800A58E0, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5F7C = { D_800A5DA0, D_800A58F8, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5F90 = { D_800A5DA8, D_800A5910, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5FA4 = { D_800A5DB4, D_800A5928, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5FB8 = { D_800A5DBC, D_800A5940, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5FCC = { D_800A5DC4, D_800A5958, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5FE0 = { D_800A5DCC, D_800A5970, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A5FF4 = { D_800A5DD4, D_800A5988, 0x2D, 8, 751, 650, 1 };
FieldActorEntry D_800A6008 = { D_800A5DDC, D_800A59A0, 0x2E, 9, 405, 650, 1 };
FieldActorEntry D_800A601C = { D_800A5DEC, D_800A59D0, 0x2E, 9, 405, 650, 1 };
FieldActorEntry D_800A6030 = { D_800A5DFC, D_800A5A30, 0x2E, 9, 405, 650, 1 };
FieldActorEntry D_800A6044 = { D_800A5E0C, D_800A5A90, 0x2E, 9, 405, 650, 1 };
FieldActorEntry D_800A6058 = { D_800A5E1C, D_800A5AF0, 0x2E, 9, 405, 650, 1 };
FieldActorEntry D_800A606C = { D_800A5E2C, D_800A5B08, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A6080 = { D_800A5E34, D_800A5B20, 0x32, 0xA, 751, 650, 1 };
FieldActorEntry D_800A6094 = { D_800A5E3C, D_800A5B38, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A60A8 = { D_800A5E44, D_800A5B50, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A60BC = { D_800A5E4C, D_800A5B68, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A60D0 = { D_800A5E54, D_800A5B80, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A60E4 = { D_800A5E5C, D_800A5B98, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A60F8 = { D_800A5E64, D_800A5BB0, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A610C = { D_800A5E6C, D_800A5BC8, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A6120 = { D_800A5E74, D_800A5BE0, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A6134 = { D_800A5E7C, D_800A5BF8, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A6148 = { D_800A5E84, D_800A5C10, 0x32, 0xA, 677, 184, 1 };
FieldActorEntry D_800A615C = { D_800A5E8C, NULL, 0x65, 0xB, 248, 388, 7 };
FieldActorEntry D_800A6170 = { D_800A5E98, D_800A5C28, 0x9D, 0xC, 677, 184, 1 };
FieldActorEntry D_800A6184 = { D_800A5EA0, D_800A5C40, 0x9E, 0xD, 405, 650, 1 };
FieldActorEntry D_800A6198 = { D_800A5EA8, D_800A5CA0, 0x9F, 0xE, 751, 650, 1 };
FieldActorEntry D_800A61AC = { D_800A5EB0, D_800A5CB8, 0xB7, 0xF, 990, 767, 1 };
FieldActorEntry D_800A61C0 = { D_800A5EBC, D_800A5CD0, 0xCE, 0x10, 1216, 913, 3 };
FieldActorEntry D_800A61D4 = { D_800A5ECC, D_800A5D3C, 0xCE, 0x10, 1216, 913, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5EDC,
    &D_800A5EF0,
    &D_800A5F04,
    &D_800A5F18,
    &D_800A5F2C,
    &D_800A5F40,
    &D_800A5F54,
    &D_800A5F68,
    &D_800A5F7C,
    &D_800A5F90,
    &D_800A5FA4,
    &D_800A5FB8,
    &D_800A5FCC,
    &D_800A5FE0,
    &D_800A5FF4,
    &D_800A6008,
    &D_800A601C,
    &D_800A6030,
    &D_800A6044,
    &D_800A6058,
    &D_800A606C,
    &D_800A6080,
    &D_800A6094,
    &D_800A60A8,
    &D_800A60BC,
    &D_800A60D0,
    &D_800A60E4,
    &D_800A60F8,
    &D_800A610C,
    &D_800A6120,
    &D_800A6134,
    &D_800A6148,
    &D_800A615C,
    &D_800A6170,
    &D_800A6184,
    &D_800A6198,
    &D_800A61AC,
    &D_800A61C0,
    &D_800A61D4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 8, 0, 160, 342, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 8, 0, 234, 305, 0, 0 },
    { 1, 0, 0x78, 2, 0xC, 0, 0, 0, 0, 0, 542, 517, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 167, 863, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 352, 645, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 729, 598, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 856, 344, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 922, 739, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 922, 965, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 945, 639, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 968, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 986, 166, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1080, 774, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1104, 915, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1110, 241, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1229, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1241, 948, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1289, 877, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1307, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 313, 667, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 335, 942, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 481, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 275, 687, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 324, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 465, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 737, 837, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 989, 706, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1214, 965, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1328, 860, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 360, 862, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 790, 877, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 858, 672, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 958, 982, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 984, 514, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1038, 947, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1060, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1130, 343, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1134, 935, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1193, 519, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1200, 744, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 634, 800, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1050, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1155, 503, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 379, 735, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 570, 831, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 712, 838, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 831, 895, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1031, 534, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1157, 726, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1188, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1232, 539, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 246, 922, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 306, 894, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 390, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 451, 885, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 501, 842, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 606, 970, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 793, 728, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 885, 667, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 956, 726, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 995, 970, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1030, 448, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1046, 753, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1072, 526, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1076, 934, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1084, 919, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1107, 513, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1113, 506, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1156, 929, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1227, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1251, 754, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1304, 520, 0, 0 },
    { 1, 0x64, 0x40, 6, 9, 0, 0, 0, 0, 0, 769, 100, 0, 0 },
    { 1, 0x65, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 574, 93, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 186, 320, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 606, 118, 136, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 156, 353, 380, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 318, 390, 407, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 400, 341, 354, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 501, 625, 649, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 660, 626, 649, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 537, 158, 166, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 1206, 636, 682, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 1120, 656, 670, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23B, 0x630, 0x88, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23F, 0x2C0, 0x1B0, 3, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x240, 0xC8, 0x164, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x240, 0x258, 0x1C2, 3, 0x64, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 7, 1 },
    { { { 0x600A, 1 }, { 0x400A, 0 } }, 8, 0xFA, 0, 0, 0, 0, 0, 0 },
    { { { 0x600B, 1 }, { 0xFFFF, 0 } }, 8, 0x10E, 0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 7, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 270, D_800A503C, EVENT_TEXT(3), NULL, NULL },
    { 250, D_800A4EC0, EVENT_TEXT(0), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
