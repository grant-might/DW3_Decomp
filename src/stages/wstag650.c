#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C15, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x53E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x54E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xEF00, 0x25800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x16;
    D_800990B4.music = 0x60580000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0xF && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5100;
extern Battle D_800A510C;
extern BattleList D_800A4F8C;
extern BattleList D_800A5010;
extern BattleList D_800A5094;
extern BattleList D_800A5118;
extern u16 D_800A5228[];
extern u16 D_800A5230[];
extern u16 D_800A5238[];
extern u16 D_800A5240[];
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A525C[];
extern u16 D_800A5268[];
extern u16 D_800A5270[];
extern u16 D_800A5278[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A5298[];
extern u16 D_800A52A4[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52C0[];
extern u16 D_800A52CC[];
extern u16 D_800A52D4[];
extern u16 D_800A52DC[];
extern u16 D_800A52E4[];
extern u16 D_800A52F0[];
extern u16 D_800A52FC[];
extern u16 D_800A5304[];
extern u16 D_800A530C[];
extern u16 D_800A5314[];
extern u16 D_800A5320[];
extern u16 D_800A532C[];
extern u16 D_800A533C[];
extern u16 D_800A534C[];
extern u16 D_800A5354[];
extern u16 D_800A535C[];
extern u16 D_800A5368[];
extern u16 D_800A5370[];
extern u16 D_800A5380[];
extern u16 D_800A5394[];
extern u16 D_800A53A4[];
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C4[];
extern u16 D_800A53D0[];
extern FieldTalk D_800A53D8[];
extern FieldTalk D_800A53F0[];
extern FieldTalk D_800A5408[];
extern u16 D_800A5690[];
extern FieldTalk D_800A5420[];
extern u16 D_800A5698[];
extern FieldTalk D_800A5438[];
extern u16 D_800A56A0[];
extern FieldTalk D_800A5450[];
extern u16 D_800A56A8[];
extern FieldTalk D_800A5468[];
extern u16 D_800A56B0[];
extern FieldTalk D_800A5480[];
extern u16 D_800A56B8[];
extern FieldTalk D_800A5498[];
extern u16 D_800A56C0[];
extern FieldTalk D_800A54B0[];
extern u16 D_800A56C8[];
extern FieldTalk D_800A54C8[];
extern u16 D_800A56D0[];
extern FieldTalk D_800A54E0[];
extern u16 D_800A56D8[];
extern FieldTalk D_800A54F8[];
extern u16 D_800A56E0[];
extern FieldTalk D_800A5510[];
extern u16 D_800A56F4[];
extern FieldTalk D_800A5540[];
extern u16 D_800A5708[];
extern FieldTalk D_800A5570[];
extern u16 D_800A571C[];
extern FieldTalk D_800A55A0[];
extern u16 D_800A5730[];
extern FieldTalk D_800A55D0[];
extern u16 D_800A5744[];
extern FieldTalk D_800A560C[];
extern u16 D_800A5758[];
extern FieldTalk D_800A5648[];
extern u16 D_800A5768[];
extern FieldTalk D_800A5660[];
extern FieldActorEntry D_800A5770;
extern FieldActorEntry D_800A5784;
extern FieldActorEntry D_800A5798;
extern FieldActorEntry D_800A57AC;
extern FieldActorEntry D_800A57C0;
extern FieldActorEntry D_800A57D4;
extern FieldActorEntry D_800A57E8;
extern FieldActorEntry D_800A57FC;
extern FieldActorEntry D_800A5810;
extern FieldActorEntry D_800A5824;
extern FieldActorEntry D_800A5838;
extern FieldActorEntry D_800A584C;
extern FieldActorEntry D_800A5860;
extern FieldActorEntry D_800A5874;
extern FieldActorEntry D_800A5888;
extern FieldActorEntry D_800A589C;
extern FieldActorEntry D_800A58B0;
extern FieldActorEntry D_800A58C4;
extern FieldActorEntry D_800A58D8;
extern FieldActorEntry D_800A58EC;
extern FieldActorEntry D_800A5900;
extern s16 D_800A4EB8[];

s16 D_800A4EB8[] = {
    0x102, 2, 0xD7, 0x129, 3,
    0x100, 0x15, 0xB7, 0x119,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC13, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x3C04\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x323\n");
#endif
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
BattleList D_800A4F8C = {
    3,
    { &D_800A4F2C, &D_800A4F38, &D_800A4F44, &D_800A4F50,
      &D_800A4F5C, &D_800A4F68, &D_800A4F74, &D_800A4F80 },
};
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
BattleList D_800A5010 = {
    0,
    { &D_800A4FB0, &D_800A4FBC, &D_800A4FC8, &D_800A4FD4,
      &D_800A4FE0, &D_800A4FEC, &D_800A4FF8, &D_800A5004 },
};
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 0, 0, 0x60040000 };
Battle D_800A5070 = { 0, 0, 0x60040000 };
Battle D_800A507C = { 0, 0, 0x60040000 };
Battle D_800A5088 = { 0, 0, 0x60040000 };
BattleList D_800A5094 = {
    0,
    { &D_800A5034, &D_800A5040, &D_800A504C, &D_800A5058,
      &D_800A5064, &D_800A5070, &D_800A507C, &D_800A5088 },
};
Battle D_800A50B8 = { 216, 20, 0x600C0000 };
Battle D_800A50C4 = { 0, 0, 0x60040000 };
Battle D_800A50D0 = { 0, 0, 0x60040000 };
Battle D_800A50DC = { 0, 0, 0x60040000 };
Battle D_800A50E8 = { 0, 0, 0x60040000 };
Battle D_800A50F4 = { 0, 0, 0x60040000 };
Battle D_800A5100 = { 0, 0, 0x60040000 };
Battle D_800A510C = { 0, 0, 0x60040000 };
BattleList D_800A5118 = {
    0,
    { &D_800A50B8, &D_800A50C4, &D_800A50D0, &D_800A50DC,
      &D_800A50E8, &D_800A50F4, &D_800A5100, &D_800A510C },
};
FieldBattles stageBattles[] = {
    { 158, 0, 0, { &D_800A4F8C, &D_800A5010, &D_800A5094, &D_800A5118 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x164, 0x1A7, 0x90, 0xA7, 0x160, 0x1FF },
    { 0x140, 0x100, 0x150, 0x178, 0x40, 0x78, 0x170, 0x1FF },
    { 0x140, 0x100, 0x140, 0x18B, 0, 0x8B, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x1A5, 0xB0, 0xA5, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x1A5, 0xD0, 0xA5, 0x160, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x1A7, 0x70, 0xA7, 0x170, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x1A8, 0x28, 0xA8, 0x160, 0x1FC },
};
u16 D_800A5228[] = { 0x7A2D, 1, 0xFFFF };
u16 D_800A5230[] = { 0x9012, 1, 0xFFFF };
u16 D_800A5238[] = { 0x7A0A, 1, 0xFFFF };
u16 D_800A5240[] = { 0, 0, 0xFFFF };
u16 D_800A5248[] = { 0, 1, 0xFFFF };
u16 D_800A5250[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A525C[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A5268[] = { 0x761A, 1, 0xFFFF };
u16 D_800A5270[] = { 0x11, 0, 0xFFFF };
u16 D_800A5278[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5284[] = { 0x11, 0, 0xFFFF };
u16 D_800A528C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5298[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52A4[] = { 0, 0, 0xFFFF };
u16 D_800A52AC[] = { 0, 1, 0xFFFF };
u16 D_800A52B4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A52C0[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A52CC[] = { 0x761A, 1, 0xFFFF };
u16 D_800A52D4[] = { 0, 0, 0xFFFF };
u16 D_800A52DC[] = { 0, 1, 0xFFFF };
u16 D_800A52E4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A52F0[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x761A, 1, 0xFFFF };
u16 D_800A5304[] = { 0, 0, 0xFFFF };
u16 D_800A530C[] = { 0, 1, 0xFFFF };
u16 D_800A5314[] = { 0, 1, 0xE10, 0, 0xFFFF };
u16 D_800A5320[] = { 0x7400, 1, 0xE10, 1, 0xFFFF };
u16 D_800A532C[] = { 0, 1, 0xE10, 1, 0x720D, 0, 0xFFFF };
u16 D_800A533C[] = { 0, 1, 0xE10, 1, 0x720D, 1, 0xFFFF };
u16 D_800A534C[] = { 0x781A, 1, 0xFFFF };
u16 D_800A5354[] = { 0x11, 0, 0xFFFF };
u16 D_800A535C[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5368[] = { 0x11, 0, 0xFFFF };
u16 D_800A5370[] = { 0x10, 1, 0x9201, 0, 0x11, 1, 0xFFFF };
u16 D_800A5380[] = { 0x9201, 1, 0x11, 0, 0x7013, 1, 0x10, 0, 0xFFFF };
u16 D_800A5394[] = { 0x10, 1, 0x9201, 1, 0x11, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A53B0[] = { 0, 0, 0xFFFF };
u16 D_800A53B8[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A53C4[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A53D0[] = { 0x761A, 1, 0xFFFF };
FieldTalk D_800A53D8[] = {
    { NULL, D_800A5228, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F0[] = {
    { NULL, D_800A5230, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5408[] = {
    { NULL, D_800A5238, 0x2D7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5420[] = {
    { NULL, NULL, 0x27 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5438[] = {
    { NULL, NULL, 0x15F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5450[] = {
    { NULL, NULL, 0x160 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5468[] = {
    { NULL, NULL, 0x161 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5480[] = {
    { NULL, NULL, 0x160 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5498[] = {
    { NULL, NULL, 0x28 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B0[] = {
    { NULL, NULL, 0x15C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C8[] = {
    { NULL, NULL, 0x15D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E0[] = {
    { NULL, NULL, 0x15D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F8[] = {
    { NULL, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5510[] = {
    { D_800A5240, D_800A5248, 0xCD },
    { D_800A5250, NULL, 0xD1 },
    { D_800A525C, D_800A5268, 0xD2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5540[] = {
    { D_800A5270, NULL, 0xCD },
    { D_800A5278, D_800A5284, 0xD7 },
    { D_800A528C, D_800A5298, 0xD8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5570[] = {
    { D_800A52A4, D_800A52AC, 0xCE },
    { D_800A52B4, NULL, 0xD1 },
    { D_800A52C0, D_800A52CC, 0xD2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A0[] = {
    { D_800A52D4, D_800A52DC, 0xCF },
    { D_800A52E4, NULL, 0xD1 },
    { D_800A52F0, D_800A52FC, 0xD2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D0[] = {
    { D_800A5304, D_800A530C, 0xD3 },
    { D_800A5314, D_800A5320, 0xD4 },
    { D_800A532C, NULL, 0xD5 },
    { D_800A533C, D_800A534C, 0xD6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A560C[] = {
    { D_800A5354, NULL, 0xCD },
    { D_800A535C, D_800A5368, 0xD9 },
    { D_800A5370, D_800A5380, 0xDA },
    { D_800A5394, D_800A53A4, 0xDB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5648[] = {
    { NULL, NULL, 0x284 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5660[] = {
    { D_800A53B0, NULL, 0xD0 },
    { D_800A53B8, NULL, 0xD0 },
    { D_800A53C4, D_800A53D0, 0xD0 },
    { NULL, NULL, 0 },
};
u16 D_800A5690[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5698[] = { 0x6010, 1, 0xFFFF };
u16 D_800A56A0[] = { 0x6011, 1, 0xFFFF };
u16 D_800A56A8[] = { 0x7017, 1, 0xFFFF };
u16 D_800A56B0[] = { 0x6012, 1, 0xFFFF };
u16 D_800A56B8[] = { 0x600F, 1, 0xFFFF };
u16 D_800A56C0[] = { 0x6010, 1, 0xFFFF };
u16 D_800A56C8[] = { 0x6011, 1, 0xFFFF };
u16 D_800A56D0[] = { 0x6012, 1, 0xFFFF };
u16 D_800A56D8[] = { 0x7017, 1, 0xFFFF };
u16 D_800A56E0[] = { 0x11, 0, 0x7003, 1, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A56F4[] = { 0x8192, 1, 0x11, 1, 0x700A, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5708[] = { 0x8192, 1, 0x11, 0, 0x7004, 1, 0x8012, 0, 0xFFFF };
u16 D_800A571C[] = { 0x8192, 1, 0x11, 0, 0x6026, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5730[] = { 0x8192, 1, 0x11, 0, 0x8012, 1, 0x7022, 1, 0xFFFF };
u16 D_800A5744[] = { 0x8192, 1, 0x11, 1, 0x8012, 1, 0x7022, 1, 0xFFFF };
u16 D_800A5758[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5768[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5770 = { NULL, D_800A53D8, 0x14, 4, 321, 593, 1 };
FieldActorEntry D_800A5784 = { NULL, D_800A53F0, 0x15, 5, 183, 281, 7 };
FieldActorEntry D_800A5798 = { NULL, D_800A5408, 0x17, 6, 528, 305, 7 };
FieldActorEntry D_800A57AC = { D_800A5690, D_800A5420, 0x20, 7, 353, 442, 1 };
FieldActorEntry D_800A57C0 = { D_800A5698, D_800A5438, 0x20, 7, 353, 442, 1 };
FieldActorEntry D_800A57D4 = { D_800A56A0, D_800A5450, 0x20, 7, 353, 442, 1 };
FieldActorEntry D_800A57E8 = { D_800A56A8, D_800A5468, 0x20, 7, 353, 442, 1 };
FieldActorEntry D_800A57FC = { D_800A56B0, D_800A5480, 0x20, 7, 353, 442, 1 };
FieldActorEntry D_800A5810 = { D_800A56B8, D_800A5498, 0x30, 8, 537, 493, 7 };
FieldActorEntry D_800A5824 = { D_800A56C0, D_800A54B0, 0x30, 8, 537, 493, 7 };
FieldActorEntry D_800A5838 = { D_800A56C8, D_800A54C8, 0x30, 8, 537, 493, 7 };
FieldActorEntry D_800A584C = { D_800A56D0, D_800A54E0, 0x30, 8, 537, 493, 7 };
FieldActorEntry D_800A5860 = { D_800A56D8, D_800A54F8, 0x30, 8, 537, 493, 7 };
FieldActorEntry D_800A5874 = { D_800A56E0, D_800A5510, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A5888 = { D_800A56F4, D_800A5540, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A589C = { D_800A5708, D_800A5570, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A58B0 = { D_800A571C, D_800A55A0, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A58C4 = { D_800A5730, D_800A55D0, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A58D8 = { D_800A5744, D_800A560C, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A58EC = { D_800A5758, D_800A5648, 0x33, 9, 401, 529, 7 };
FieldActorEntry D_800A5900 = { D_800A5768, D_800A5660, 0x9D, 0xA, 401, 529, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5770,
    &D_800A5784,
    &D_800A5798,
    &D_800A57AC,
    &D_800A57C0,
    &D_800A57D4,
    &D_800A57E8,
    &D_800A57FC,
    &D_800A5810,
    &D_800A5824,
    &D_800A5838,
    &D_800A584C,
    &D_800A5860,
    &D_800A5874,
    &D_800A5888,
    &D_800A589C,
    &D_800A58B0,
    &D_800A58C4,
    &D_800A58D8,
    &D_800A58EC,
    &D_800A5900,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 0xE, 0, 252, 269, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 0xE, 0, 482, 625, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 195, 353, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 339, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 539, 364, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 7, 0xE, 0, 366, 485, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 7, 0xE, 0, 475, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 0xB, 0xA, 0, 164, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 0xA, 0, 164, 354, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 0xA, 0, 508, 337, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 0xB, 0xA, 0, 512, 364, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 0xB, 0xA, 0, 568, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 0xB, 0xA, 0, 481, 426, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 0xB, 0xA, 0, 453, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 0xB, 0xA, 0, 346, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 0xB, 0xA, 0, 342, 488, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 311, 96, 151, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 318, 579, 600, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 335, 572, 595, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25C, 0xA8, 0x1B4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25A, 0x298, 0x104, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xFD, 0xD0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xEC, 0x118, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x133, 0xC8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x142, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x192, 0x148, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1A2, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1C2, 0x1A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1D2, 0x1E8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x25C, 0x160, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x24C, 0x1A8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1AC, 0x228, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x19C, 0x270, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1458, D_800A4EB8, EVENT_TEXT(0x1E), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
