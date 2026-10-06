#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

/* Event: applies actions 0xC23, 0x40A4 and 0x7400 */
void func_800A4D4C(void) {
    FLAGS_00.applyAction(0xC23, 1);
    FLAGS_00.applyAction(0x40A4, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x494
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x4A4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x14B00, 0x13400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

void func_800A4D4C();
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern BattleList D_800A5024;
extern BattleList D_800A50A8;
extern BattleList D_800A512C;
extern BattleList D_800A51B0;
extern u16 D_800A5400[];
extern u16 D_800A540C[];
extern u16 D_800A5418[];
extern u16 D_800A56DC[];
extern FieldTalk D_800A5424[];
extern u16 D_800A56E8[];
extern FieldTalk D_800A543C[];
extern u16 D_800A56F0[];
extern FieldTalk D_800A5454[];
extern u16 D_800A56FC[];
extern FieldTalk D_800A546C[];
extern u16 D_800A5704[];
extern FieldTalk D_800A5484[];
extern u16 D_800A570C[];
extern FieldTalk D_800A549C[];
extern u16 D_800A5714[];
extern FieldTalk D_800A54B4[];
extern u16 D_800A571C[];
extern FieldTalk D_800A54CC[];
extern u16 D_800A5724[];
extern FieldTalk D_800A54E4[];
extern u16 D_800A572C[];
extern FieldTalk D_800A54FC[];
extern u16 D_800A5738[];
extern FieldTalk D_800A5514[];
extern u16 D_800A5744[];
extern FieldTalk D_800A552C[];
extern u16 D_800A574C[];
extern FieldTalk D_800A5544[];
extern u16 D_800A5754[];
extern FieldTalk D_800A555C[];
extern u16 D_800A575C[];
extern u16 D_800A5764[];
extern u16 D_800A5770[];
extern u16 D_800A5778[];
extern u16 D_800A5784[];
extern FieldTalk D_800A5574[];
extern u16 D_800A5790[];
extern FieldTalk D_800A558C[];
extern u16 D_800A5798[];
extern FieldTalk D_800A55A4[];
extern u16 D_800A57A4[];
extern FieldTalk D_800A55BC[];
extern u16 D_800A57AC[];
extern FieldTalk D_800A55D4[];
extern u16 D_800A57B8[];
extern FieldTalk D_800A55EC[];
extern u16 D_800A57C0[];
extern FieldTalk D_800A5604[];
extern u16 D_800A57CC[];
extern FieldTalk D_800A561C[];
extern u16 D_800A57D4[];
extern FieldTalk D_800A5634[];
extern u16 D_800A57DC[];
extern FieldTalk D_800A564C[];
extern u16 D_800A57E4[];
extern FieldTalk D_800A5664[];
extern u16 D_800A57EC[];
extern FieldTalk D_800A567C[];
extern u16 D_800A57F4[];
extern FieldTalk D_800A5694[];
extern u16 D_800A5800[];
extern FieldTalk D_800A56AC[];
extern u16 D_800A580C[];
extern FieldTalk D_800A56C4[];
extern u16 D_800A5818[];
extern u16 D_800A5824[];
extern u16 D_800A5830[];
extern u16 D_800A583C[];
extern FieldActorEntry D_800A5848;
extern FieldActorEntry D_800A585C;
extern FieldActorEntry D_800A5870;
extern FieldActorEntry D_800A5884;
extern FieldActorEntry D_800A5898;
extern FieldActorEntry D_800A58AC;
extern FieldActorEntry D_800A58C0;
extern FieldActorEntry D_800A58D4;
extern FieldActorEntry D_800A58E8;
extern FieldActorEntry D_800A58FC;
extern FieldActorEntry D_800A5910;
extern FieldActorEntry D_800A5924;
extern FieldActorEntry D_800A5938;
extern FieldActorEntry D_800A594C;
extern FieldActorEntry D_800A5960;
extern FieldActorEntry D_800A5974;
extern FieldActorEntry D_800A5988;
extern FieldActorEntry D_800A599C;
extern FieldActorEntry D_800A59B0;
extern FieldActorEntry D_800A59C4;
extern FieldActorEntry D_800A59D8;
extern FieldActorEntry D_800A59EC;
extern FieldActorEntry D_800A5A00;
extern FieldActorEntry D_800A5A14;
extern FieldActorEntry D_800A5A28;
extern FieldActorEntry D_800A5A3C;
extern FieldActorEntry D_800A5A50;
extern FieldActorEntry D_800A5A64;
extern FieldActorEntry D_800A5A78;
extern FieldActorEntry D_800A5A8C;
extern FieldActorEntry D_800A5AA0;
extern FieldActorEntry D_800A5AB4;
extern FieldActorEntry D_800A5AC8;
extern FieldActorEntry D_800A5ADC;
extern FieldActorEntry D_800A5AF0;
extern FieldActorEntry D_800A5B04;
extern FieldActorEntry D_800A5B18;
extern s16 D_800A4F0C[];

s16 D_800A4F0C[] = {
    0x102, 2, 0x120, 0xE1, 5,
    0x100, 0xC2, 0x149, 0xCD,
    0x101, 0xC2, 1, 1,
    0x100, 0xC3, 0x160, 0xD9,
    0x101, 0xC3, 1, 1,
    0x100, 0xC4, 0x130, 0xC0,
    0x101, 0xC4, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xC2,
    0x101, 0x324, 0x325, 0xC3,
    0x101, 0x325, 0x325, 0xC4,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0xC2,
    0x101, 0x324, 0x326, 0xC3,
    0x101, 0x325, 0x326, 0xC4,
    0x300, 0x1E,
    0x102, 0xC2, 0x141, 0xD1, 1,
    0x302, 0xC2,
    0x101, 0xC2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0xC2, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x6961\n");
#endif
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
BattleList D_800A5024 = {
    0,
    { &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8,
      &D_800A4FF4, &D_800A5000, &D_800A500C, &D_800A5018 },
};
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
Battle D_800A5078 = { 0, 0, 0x60040000 };
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
BattleList D_800A50A8 = {
    0,
    { &D_800A5048, &D_800A5054, &D_800A5060, &D_800A506C,
      &D_800A5078, &D_800A5084, &D_800A5090, &D_800A509C },
};
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 0, 0, 0x60040000 };
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
BattleList D_800A512C = {
    0,
    { &D_800A50CC, &D_800A50D8, &D_800A50E4, &D_800A50F0,
      &D_800A50FC, &D_800A5108, &D_800A5114, &D_800A5120 },
};
Battle D_800A5150 = { 195, 15, 0x60080000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
BattleList D_800A51B0 = {
    0,
    { &D_800A5150, &D_800A515C, &D_800A5168, &D_800A5174,
      &D_800A5180, &D_800A518C, &D_800A5198, &D_800A51A4 },
};
FieldBattles stageBattles[] = {
    { 143, 0, 0, { &D_800A5024, &D_800A50A8, &D_800A512C, &D_800A51B0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F0, 0x160, 0x2C0, 0x60, 0x170, 0x1F8 },
    { 0x1C0, 0x100, 0x1C0, 0x171, 0x200, 0x71, 0x140, 0x1F7 },
    { 0x180, 0x100, 0x198, 0x1B0, 0x160, 0xB0, 0x150, 0x1F7 },
    { 0x1C0, 0x100, 0x1F6, 0x100, 0x2D8, 0, 0x160, 0x1F7 },
    { 0x1C0, 0x100, 0x1F6, 0x130, 0x2D8, 0x30, 0x170, 0x1F7 },
    { 0x1C0, 0x100, 0x1F8, 0x160, 0x2E0, 0x60, 0x140, 0x1F6 },
    { 0x1C0, 0x100, 0x1C8, 0x171, 0x220, 0x71, 0x150, 0x1F6 },
    { 0x1C0, 0x100, 0x1D8, 0x174, 0x260, 0x74, 0x160, 0x1F6 },
    { 0x1C0, 0x100, 0x1E0, 0x174, 0x280, 0x74, 0x170, 0x1F6 },
    { 0x1C0, 0x100, 0x1E8, 0x174, 0x2A0, 0x74, 0x140, 0x1F5 },
    { 0x1C0, 0x100, 0x1C8, 0x199, 0x220, 0x99, 0x150, 0x1F5 },
    { 0x1C0, 0x100, 0x1D0, 0x154, 0x240, 0x54, 0x160, 0x1F5 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x1C0, 0x100, 0x1D0, 0x1AC, 0x240, 0xAC, 0x170, 0x1F5 },
    { 0x1C0, 0x100, 0x1EC, 0x1B0, 0x2B0, 0xB0, 0x140, 0x1F4 },
    { 0x1C0, 0x100, 0x1F4, 0x1B0, 0x2D0, 0xB0, 0x150, 0x1F4 },
    { 0x1C0, 0x100, 0x1D8, 0x1B4, 0x260, 0xB4, 0x160, 0x1F4 },
    { 0x1C0, 0x100, 0x1E0, 0x1B4, 0x280, 0xB4, 0x170, 0x1F4 },
    { 0x1C0, 0x100, 0x1C8, 0x1B9, 0x220, 0xB9, 0x140, 0x1F3 },
    { 0x1C0, 0x100, 0x1C0, 0x1C1, 0x200, 0xC1, 0x150, 0x1F3 },
    { 0x1C0, 0x100, 0x1D0, 0x1CC, 0x240, 0xCC, 0x160, 0x1F3 },
    { 0x1C0, 0x100, 0x1D0, 0x184, 0x240, 0x84, 0x170, 0x1F3 },
    { 0x1C0, 0x100, 0x1F0, 0x188, 0x2C0, 0x88, 0x140, 0x1F2 },
    { 0x1C0, 0x100, 0x1C0, 0x199, 0x200, 0x99, 0x150, 0x1F2 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A5400[] = { 0x7400, 1, 0xC23, 1, 0xFFFF };
u16 D_800A540C[] = { 0x7400, 1, 0xC23, 1, 0xFFFF };
u16 D_800A5418[] = { 0x7400, 1, 0xC23, 1, 0xFFFF };
FieldTalk D_800A5424[] = {
    { NULL, NULL, 0x33 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A543C[] = {
    { NULL, NULL, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5454[] = {
    { NULL, NULL, 0x37 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A546C[] = {
    { NULL, NULL, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5484[] = {
    { NULL, NULL, 0x43 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A549C[] = {
    { NULL, NULL, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B4[] = {
    { NULL, NULL, 0x47 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54CC[] = {
    { NULL, NULL, 0x42 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E4[] = {
    { NULL, NULL, 0x3E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54FC[] = {
    { NULL, NULL, 0x3F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5514[] = {
    { NULL, NULL, 0x3B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A552C[] = {
    { NULL, NULL, 0x4B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5544[] = {
    { NULL, NULL, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A555C[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5574[] = {
    { NULL, NULL, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A558C[] = {
    { NULL, NULL, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x38 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55BC[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D4[] = {
    { NULL, NULL, 0x3C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55EC[] = {
    { NULL, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5604[] = {
    { NULL, NULL, 0x40 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A561C[] = {
    { NULL, NULL, 0x41 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5634[] = {
    { NULL, NULL, 0x44 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A564C[] = {
    { NULL, NULL, 0x46 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5664[] = {
    { NULL, NULL, 0x48 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A567C[] = {
    { NULL, NULL, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5694[] = {
    { NULL, D_800A5400, 0x1B7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56AC[] = {
    { NULL, D_800A540C, 0x1B8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C4[] = {
    { NULL, D_800A5418, 0x1B9 },
    { NULL, NULL, 0 },
};
u16 D_800A56DC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A56E8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A56F0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A56FC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5704[] = { 0x6026, 1, 0xFFFF };
u16 D_800A570C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5714[] = { 0x6026, 1, 0xFFFF };
u16 D_800A571C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5724[] = { 0x602B, 1, 0xFFFF };
u16 D_800A572C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5738[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5744[] = { 0x602B, 1, 0xFFFF };
u16 D_800A574C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5754[] = { 0x6026, 1, 0xFFFF };
u16 D_800A575C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5764[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5770[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5778[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5784[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5790[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5798[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57A4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57AC[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57C0[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57D4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57DC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57E4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57EC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57F4[] = { 0xC23, 0, 0x6025, 1, 0xFFFF };
u16 D_800A5800[] = { 0x6025, 1, 0xC23, 0, 0xFFFF };
u16 D_800A580C[] = { 0xC23, 0, 0x6025, 1, 0xFFFF };
u16 D_800A5818[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5824[] = { 0x7094, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5830[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A583C[] = { 0x6026, 0, 0x7094, 1, 0xFFFF };
FieldActorEntry D_800A5848 = { D_800A56DC, D_800A5424, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A585C = { D_800A56E8, D_800A543C, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A5870 = { D_800A56F0, D_800A5454, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A5884 = { D_800A56FC, D_800A546C, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A5898 = { D_800A5704, D_800A5484, 0x25, 6, 304, 193, 7 };
FieldActorEntry D_800A58AC = { D_800A570C, D_800A549C, 0x26, 7, 305, 353, 1 };
FieldActorEntry D_800A58C0 = { D_800A5714, D_800A54B4, 0x27, 8, 193, 257, 7 };
FieldActorEntry D_800A58D4 = { D_800A571C, D_800A54CC, 0x2D, 9, 529, 505, 7 };
FieldActorEntry D_800A58E8 = { D_800A5724, D_800A54E4, 0x30, 0xA, 617, 501, 1 };
FieldActorEntry D_800A58FC = { D_800A572C, D_800A54FC, 0x31, 0xB, 328, 260, 5 };
FieldActorEntry D_800A5910 = { D_800A5738, D_800A5514, 0x32, 0xC, 617, 501, 1 };
FieldActorEntry D_800A5924 = { D_800A5744, D_800A552C, 0x37, 0xD, 391, 359, 1 };
FieldActorEntry D_800A5938 = { D_800A574C, D_800A5544, 0x39, 0xE, 684, 363, 7 };
FieldActorEntry D_800A594C = { D_800A5754, D_800A555C, 0x6F, 0xF, 529, 505, 7 };
FieldActorEntry D_800A5960 = { D_800A575C, NULL, 0x70, 0x10, 360, 268, 1 };
FieldActorEntry D_800A5974 = { D_800A5764, NULL, 0x70, 0x10, 360, 268, 1 };
FieldActorEntry D_800A5988 = { D_800A5770, NULL, 0x71, 0x11, 450, 254, 7 };
FieldActorEntry D_800A599C = { D_800A5778, NULL, 0x71, 0x11, 450, 254, 7 };
FieldActorEntry D_800A59B0 = { D_800A5784, D_800A5574, 0x9D, 0x12, 384, 255, 1 };
FieldActorEntry D_800A59C4 = { D_800A5790, D_800A558C, 0x9D, 0x12, 384, 255, 1 };
FieldActorEntry D_800A59D8 = { D_800A5798, D_800A55A4, 0x9E, 0x13, 434, 247, 7 };
FieldActorEntry D_800A59EC = { D_800A57A4, D_800A55BC, 0x9E, 0x13, 434, 247, 7 };
FieldActorEntry D_800A5A00 = { D_800A57AC, D_800A55D4, 0x9F, 0x14, 617, 501, 1 };
FieldActorEntry D_800A5A14 = { D_800A57B8, D_800A55EC, 0x9F, 0x14, 617, 501, 1 };
FieldActorEntry D_800A5A28 = { D_800A57C0, D_800A5604, 0xA0, 0x15, 328, 260, 5 };
FieldActorEntry D_800A5A3C = { D_800A57CC, D_800A561C, 0xA0, 0x15, 328, 260, 5 };
FieldActorEntry D_800A5A50 = { D_800A57D4, D_800A5634, 0xA1, 0x16, 304, 193, 7 };
FieldActorEntry D_800A5A64 = { D_800A57DC, D_800A564C, 0xA2, 0x17, 305, 303, 1 };
FieldActorEntry D_800A5A78 = { D_800A57E4, D_800A5664, 0xAE, 0x18, 193, 257, 5 };
FieldActorEntry D_800A5A8C = { D_800A57EC, D_800A567C, 0xAF, 0x19, 529, 505, 7 };
FieldActorEntry D_800A5AA0 = { D_800A57F4, D_800A5694, 0xC2, 0x1A, 329, 205, 1 };
FieldActorEntry D_800A5AB4 = { D_800A5800, D_800A56AC, 0xC3, 0x1B, 352, 217, 1 };
FieldActorEntry D_800A5AC8 = { D_800A580C, D_800A56C4, 0xC4, 0x1C, 304, 192, 1 };
FieldActorEntry D_800A5ADC = { D_800A5818, NULL, 0x10E, 0x1D, 360, 268, 1 };
FieldActorEntry D_800A5AF0 = { D_800A5824, NULL, 0x10E, 0x1D, 360, 268, 1 };
FieldActorEntry D_800A5B04 = { D_800A5830, NULL, 0x10F, 0x1E, 450, 254, 7 };
FieldActorEntry D_800A5B18 = { D_800A583C, NULL, 0x10F, 0x1E, 450, 254, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5848,
    &D_800A585C,
    &D_800A5870,
    &D_800A5884,
    &D_800A5898,
    &D_800A58AC,
    &D_800A58C0,
    &D_800A58D4,
    &D_800A58E8,
    &D_800A58FC,
    &D_800A5910,
    &D_800A5924,
    &D_800A5938,
    &D_800A594C,
    &D_800A5960,
    &D_800A5974,
    &D_800A5988,
    &D_800A599C,
    &D_800A59B0,
    &D_800A59C4,
    &D_800A59D8,
    &D_800A59EC,
    &D_800A5A00,
    &D_800A5A14,
    &D_800A5A28,
    &D_800A5A3C,
    &D_800A5A50,
    &D_800A5A64,
    &D_800A5A78,
    &D_800A5A8C,
    &D_800A5AA0,
    &D_800A5AB4,
    &D_800A5AC8,
    &D_800A5ADC,
    &D_800A5AF0,
    &D_800A5B04,
    &D_800A5B18,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 4, 0, 243, 69, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 4, 0, 802, 278, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 4, 0, 457, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 339, 212, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 372, 196, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 403, 244, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 435, 228, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 386, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 546, 197, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 674, 197, 0, 0 },
    { 1, 0, 0x40, 2, 0x56, 2, 0, 7, 0x12, 0, 573, 209, 0, 0 },
    { 1, 0, 0x40, 2, 0x56, 2, 0, 7, 0x12, 0, 613, 209, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 151, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 411, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 649, 200, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x47, 0xA, 0, 76, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x47, 0xA, 0, 561, 589, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x47, 0xA, 0, 710, 468, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x52, 0xA, 0, 225, 445, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x52, 0xA, 0, 422, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x52, 0xA, 0, 748, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 10, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 42, 121, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 74, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 290, 69, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 322, 85, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 354, 101, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 482, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 514, 181, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 706, 213, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 738, 229, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 770, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 7, 0x12, 0, 119, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 135, 232, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 155, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 175, 212, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 195, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 215, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 235, 182, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 255, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 275, 162, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 295, 152, 0, 0 },
    { 1, 0x64, 0x40, 6, 4, 0, 0, 0, 0, 0, 335, 141, 0, 0 },
    { 1, 0x65, 0x40, 6, 5, 0, 0, 0, 0, 0, 511, 229, 0, 0 },
    { 1, 0x66, 0x40, 6, 6, 0, 0, 0, 0, 0, 736, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 114, 179, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 264, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x59, 2, 0, 3, 4, 0, 429, 176, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 1, 0x5E, 0x61, 8, 0, 585, 335, 0, 0 },
    { 1, 0, 0x40, 6, 0x5A, 1, 0x5A, 0x5D, 8, 0, 585, 335, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 144, 110, 160, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 359, 148, 193, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 535, 236, 281, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 759, 332, 376, 0 },
    { 1, 0, 0x50, 4, 7, 0, 0, 0, 0, 0, 441, 345, 450, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 464, 444, 496, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 595, 442, 478, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 384, 259, 279, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 401, 250, 271, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 368, 251, 270, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 417, 243, 264, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 352, 242, 262, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 433, 233, 255, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 336, 229, 255, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 449, 227, 247, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 320, 227, 247, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 337, 219, 240, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 353, 208, 231, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 369, 203, 223, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 385, 192, 215, 0 },
    { 1, 0, 0x40, 4, 0x17, 0, 0, 0, 0, 0, 401, 187, 207, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 499, 317, 334, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x3E8, 0xEC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x275, 0x70, 0xF0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x276, 0x58, 0x1CC, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x277, 0x69, 0x134, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x283, 0x1F8, 0x2BC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x286, 0x1D8, 0x1D4, 3, 0, 0, 0 },
    { { { 0x6025, 1 }, { 0x40A4, 0 } }, 8, 0x39D, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 925, D_800A4F0C, EVENT_TEXT(0x28), NULL, func_800A4D4C },
    { -1, NULL, 0, NULL, NULL },
};
