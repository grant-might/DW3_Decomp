#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x709
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x719
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x27100, 0x2F000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1A;
    D_800990B4.music = 0x60680000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A502C[];
extern u16 D_800A5034[];
extern u16 D_800A503C[];
extern u16 D_800A5044[];
extern u16 D_800A504C[];
extern u16 D_800A5054[];
extern u16 D_800A5064[];
extern FieldTalk D_800A506C[];
extern FieldTalk D_800A5084[];
extern FieldTalk D_800A509C[];
extern FieldTalk D_800A50B4[];
extern FieldTalk D_800A50CC[];
extern u16 D_800A54EC[];
extern FieldTalk D_800A50E4[];
extern u16 D_800A54F4[];
extern FieldTalk D_800A50FC[];
extern u16 D_800A54FC[];
extern FieldTalk D_800A5114[];
extern u16 D_800A5504[];
extern FieldTalk D_800A512C[];
extern u16 D_800A550C[];
extern FieldTalk D_800A5144[];
extern u16 D_800A5514[];
extern FieldTalk D_800A515C[];
extern u16 D_800A551C[];
extern FieldTalk D_800A5174[];
extern u16 D_800A5524[];
extern FieldTalk D_800A518C[];
extern u16 D_800A552C[];
extern FieldTalk D_800A51A4[];
extern u16 D_800A5534[];
extern FieldTalk D_800A51BC[];
extern u16 D_800A553C[];
extern FieldTalk D_800A51D4[];
extern u16 D_800A5544[];
extern FieldTalk D_800A51EC[];
extern u16 D_800A554C[];
extern FieldTalk D_800A5204[];
extern u16 D_800A5554[];
extern FieldTalk D_800A521C[];
extern u16 D_800A555C[];
extern FieldTalk D_800A5234[];
extern u16 D_800A5564[];
extern FieldTalk D_800A524C[];
extern u16 D_800A556C[];
extern FieldTalk D_800A5264[];
extern u16 D_800A5574[];
extern FieldTalk D_800A527C[];
extern u16 D_800A557C[];
extern FieldTalk D_800A5294[];
extern u16 D_800A5584[];
extern FieldTalk D_800A52AC[];
extern u16 D_800A558C[];
extern FieldTalk D_800A52C4[];
extern u16 D_800A5594[];
extern FieldTalk D_800A52DC[];
extern u16 D_800A559C[];
extern FieldTalk D_800A52F4[];
extern u16 D_800A55A4[];
extern FieldTalk D_800A530C[];
extern u16 D_800A55AC[];
extern FieldTalk D_800A5324[];
extern u16 D_800A55B4[];
extern FieldTalk D_800A533C[];
extern u16 D_800A55BC[];
extern FieldTalk D_800A5354[];
extern u16 D_800A55C4[];
extern FieldTalk D_800A536C[];
extern u16 D_800A55CC[];
extern FieldTalk D_800A5384[];
extern u16 D_800A55D4[];
extern FieldTalk D_800A539C[];
extern u16 D_800A55DC[];
extern FieldTalk D_800A53B4[];
extern u16 D_800A55E4[];
extern FieldTalk D_800A53CC[];
extern u16 D_800A55EC[];
extern FieldTalk D_800A53E4[];
extern u16 D_800A55F4[];
extern FieldTalk D_800A53FC[];
extern u16 D_800A55FC[];
extern FieldTalk D_800A5414[];
extern u16 D_800A5604[];
extern FieldTalk D_800A542C[];
extern u16 D_800A560C[];
extern FieldTalk D_800A5444[];
extern u16 D_800A5614[];
extern FieldTalk D_800A545C[];
extern u16 D_800A561C[];
extern FieldTalk D_800A5474[];
extern u16 D_800A5624[];
extern FieldTalk D_800A548C[];
extern u16 D_800A562C[];
extern FieldTalk D_800A54A4[];
extern u16 D_800A5634[];
extern FieldTalk D_800A54BC[];
extern u16 D_800A563C[];
extern FieldTalk D_800A54D4[];
extern FieldActorEntry D_800A5644;
extern FieldActorEntry D_800A5658;
extern FieldActorEntry D_800A566C;
extern FieldActorEntry D_800A5680;
extern FieldActorEntry D_800A5694;
extern FieldActorEntry D_800A56A8;
extern FieldActorEntry D_800A56BC;
extern FieldActorEntry D_800A56D0;
extern FieldActorEntry D_800A56E4;
extern FieldActorEntry D_800A56F8;
extern FieldActorEntry D_800A570C;
extern FieldActorEntry D_800A5720;
extern FieldActorEntry D_800A5734;
extern FieldActorEntry D_800A5748;
extern FieldActorEntry D_800A575C;
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
extern FieldActorEntry D_800A5914;
extern FieldActorEntry D_800A5928;
extern FieldActorEntry D_800A593C;
extern FieldActorEntry D_800A5950;
extern FieldActorEntry D_800A5964;
extern FieldActorEntry D_800A5978;
extern FieldActorEntry D_800A598C;
extern FieldActorEntry D_800A59A0;
extern FieldActorEntry D_800A59B4;
extern FieldActorEntry D_800A59C8;
extern FieldActorEntry D_800A59DC;
extern FieldActorEntry D_800A59F0;
extern s16 D_800A4E68[];

s16 D_800A4E68[] = {
    0x102, 2, 0x4B0, 0x381, 5,
    0x100, 0x15, 0x4D1, 0x371,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC09, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x188, 0xA0, 0x88, 0x170, 0x1FB },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FA },
    { 0x140, 0x100, 0x170, 0x158, 0xC0, 0x58, 0x170, 0x1FA },
    { 0x140, 0x100, 0x148, 0x160, 0x20, 0x60, 0x150, 0x1F9 },
    { 0x140, 0x100, 0x16E, 0x130, 0xB8, 0x30, 0x160, 0x1F9 },
    { 0x140, 0x100, 0x168, 0x134, 0xA0, 0x34, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x160, 0x134, 0x80, 0x34, 0x150, 0x1F8 },
    { 0x140, 0x100, 0x140, 0x154, 0, 0x54, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x168, 0x158, 0xA0, 0x58, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x148, 0x1A0, 0x20, 0xA0, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x170, 0x1A0, 0xC0, 0xA0, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x1A4, 0, 0xA4, 0x170, 0x1F7 },
    { 0x140, 0x100, 0x150, 0x1A4, 0x40, 0xA4, 0x150, 0x1F6 },
    { 0x140, 0x100, 0x158, 0x1A4, 0x60, 0xA4, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x156, 0x134, 0x58, 0x34, 0x170, 0x1F6 },
};
u16 D_800A502C[] = { 0x7A26, 1, 0xFFFF };
u16 D_800A5034[] = { 0x9017, 1, 0xFFFF };
u16 D_800A503C[] = { 0x7A0E, 1, 0xFFFF };
u16 D_800A5044[] = { 0x7A0D, 1, 0xFFFF };
u16 D_800A504C[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A5054[] = { 0x8246, 1, 0x226, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5064[] = { 0x7A42, 1, 0xFFFF };
FieldTalk D_800A506C[] = {
    { NULL, D_800A502C, 5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5084[] = {
    { NULL, D_800A5034, 2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A509C[] = {
    { NULL, D_800A503C, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50B4[] = {
    { NULL, D_800A5044, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50CC[] = {
    { NULL, D_800A504C, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50E4[] = {
    { NULL, D_800A5054, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50FC[] = {
    { NULL, NULL, 0xF7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5114[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A512C[] = {
    { NULL, NULL, 0xFC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5144[] = {
    { NULL, NULL, 0xFA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A515C[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5174[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A518C[] = {
    { NULL, NULL, 0xF8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A4[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51BC[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D4[] = {
    { NULL, NULL, 0xFD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51EC[] = {
    { NULL, NULL, 0x102 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5204[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A521C[] = {
    { NULL, NULL, 0x100 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5234[] = {
    { NULL, NULL, 0xFE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A524C[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5264[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A527C[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5294[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52AC[] = {
    { NULL, NULL, 0x106 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C4[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52DC[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F4[] = {
    { NULL, NULL, 0x103 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A530C[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5324[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A533C[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5354[] = {
    { NULL, NULL, 0x104 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A536C[] = {
    { NULL, NULL, 0x108 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5384[] = {
    { NULL, NULL, 0x10E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A539C[] = {
    { NULL, NULL, 0x10C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B4[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53CC[] = {
    { NULL, NULL, 0x109 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E4[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53FC[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5414[] = {
    { NULL, NULL, 0x10A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A542C[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5444[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A545C[] = {
    { NULL, NULL, 0xFB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5474[] = {
    { NULL, NULL, 0x101 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A548C[] = {
    { NULL, NULL, 0x107 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A4[] = {
    { NULL, NULL, 0x10D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54BC[] = {
    { NULL, D_800A5064, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D4[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
u16 D_800A54EC[] = { 0x226, 0, 0xFFFF };
u16 D_800A54F4[] = { 0x601E, 1, 0xFFFF };
u16 D_800A54FC[] = { 0x6023, 1, 0xFFFF };
u16 D_800A5504[] = { 0x602B, 1, 0xFFFF };
u16 D_800A550C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5514[] = { 0x6025, 1, 0xFFFF };
u16 D_800A551C[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5524[] = { 0x601F, 1, 0xFFFF };
u16 D_800A552C[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5534[] = { 0x6022, 1, 0xFFFF };
u16 D_800A553C[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5544[] = { 0x602B, 1, 0xFFFF };
u16 D_800A554C[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5554[] = { 0x6026, 1, 0xFFFF };
u16 D_800A555C[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5564[] = { 0x6021, 1, 0xFFFF };
u16 D_800A556C[] = { 0x6022, 1, 0xFFFF };
u16 D_800A5574[] = { 0x6023, 1, 0xFFFF };
u16 D_800A557C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5584[] = { 0x6026, 1, 0xFFFF };
u16 D_800A558C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5594[] = { 0x6022, 1, 0xFFFF };
u16 D_800A559C[] = { 0x601E, 1, 0xFFFF };
u16 D_800A55A4[] = { 0x6024, 1, 0xFFFF };
u16 D_800A55AC[] = { 0x6023, 1, 0xFFFF };
u16 D_800A55B4[] = { 0x6021, 1, 0xFFFF };
u16 D_800A55BC[] = { 0x601F, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55D4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A55DC[] = { 0x6021, 1, 0xFFFF };
u16 D_800A55E4[] = { 0x601E, 1, 0xFFFF };
u16 D_800A55EC[] = { 0x6023, 1, 0xFFFF };
u16 D_800A55F4[] = { 0x6025, 1, 0xFFFF };
u16 D_800A55FC[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5604[] = { 0x6022, 1, 0xFFFF };
u16 D_800A560C[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5614[] = { 0x701A, 1, 0xFFFF };
u16 D_800A561C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5624[] = { 0x701A, 1, 0xFFFF };
u16 D_800A562C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5634[] = { 0x8192, 1, 0xFFFF };
u16 D_800A563C[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A5644 = { NULL, D_800A506C, 0x14, 4, 1073, 798, 1 };
FieldActorEntry D_800A5658 = { NULL, D_800A5084, 0x15, 5, 1233, 881, 1 };
FieldActorEntry D_800A566C = { NULL, D_800A509C, 0x16, 6, 705, 597, 1 };
FieldActorEntry D_800A5680 = { NULL, D_800A50B4, 0x17, 7, 626, 557, 1 };
FieldActorEntry D_800A5694 = { NULL, D_800A50CC, 0x18, 8, 1283, 541, 1 };
FieldActorEntry D_800A56A8 = { D_800A54EC, D_800A50E4, 0x21, 9, 1041, 881, 1 };
FieldActorEntry D_800A56BC = { D_800A54F4, D_800A50FC, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A56D0 = { D_800A54FC, D_800A5114, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A56E4 = { D_800A5504, D_800A512C, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A56F8 = { D_800A550C, D_800A5144, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A570C = { D_800A5514, D_800A515C, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A5720 = { D_800A551C, D_800A5174, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A5734 = { D_800A5524, D_800A518C, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A5748 = { D_800A552C, D_800A51A4, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A575C = { D_800A5534, D_800A51BC, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A5770 = { D_800A553C, D_800A51D4, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A5784 = { D_800A5544, D_800A51EC, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A5798 = { D_800A554C, D_800A5204, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A57AC = { D_800A5554, D_800A521C, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A57C0 = { D_800A555C, D_800A5234, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A57D4 = { D_800A5564, D_800A524C, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A57E8 = { D_800A556C, D_800A5264, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A57FC = { D_800A5574, D_800A527C, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A5810 = { D_800A557C, D_800A5294, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A5824 = { D_800A5584, D_800A52AC, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5838 = { D_800A558C, D_800A52C4, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A584C = { D_800A5594, D_800A52DC, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5860 = { D_800A559C, D_800A52F4, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5874 = { D_800A55A4, D_800A530C, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5888 = { D_800A55AC, D_800A5324, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A589C = { D_800A55B4, D_800A533C, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A58B0 = { D_800A55BC, D_800A5354, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A58C4 = { D_800A55C4, D_800A536C, 0x27, 0xC, 290, 490, 7 };
FieldActorEntry D_800A58D8 = { D_800A55CC, D_800A5384, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A58EC = { D_800A55D4, D_800A539C, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5900 = { D_800A55DC, D_800A53B4, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5914 = { D_800A55E4, D_800A53CC, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5928 = { D_800A55EC, D_800A53E4, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A593C = { D_800A55F4, D_800A53FC, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5950 = { D_800A55FC, D_800A5414, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5964 = { D_800A5604, D_800A542C, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5978 = { D_800A560C, D_800A5444, 0x39, 0xD, 721, 256, 7 };
FieldActorEntry D_800A598C = { D_800A5614, D_800A545C, 0x9D, 0xE, 593, 702, 1 };
FieldActorEntry D_800A59A0 = { D_800A561C, D_800A5474, 0x9E, 0xF, 745, 777, 1 };
FieldActorEntry D_800A59B4 = { D_800A5624, D_800A548C, 0x9F, 0x10, 290, 490, 7 };
FieldActorEntry D_800A59C8 = { D_800A562C, D_800A54A4, 0xA0, 0x11, 721, 256, 7 };
FieldActorEntry D_800A59DC = { D_800A5634, D_800A54BC, 0xCE, 0x12, 1041, 657, 3 };
FieldActorEntry D_800A59F0 = { D_800A563C, D_800A54D4, 0xCE, 0x12, 1041, 657, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5644,
    &D_800A5658,
    &D_800A566C,
    &D_800A5680,
    &D_800A5694,
    &D_800A56A8,
    &D_800A56BC,
    &D_800A56D0,
    &D_800A56E4,
    &D_800A56F8,
    &D_800A570C,
    &D_800A5720,
    &D_800A5734,
    &D_800A5748,
    &D_800A575C,
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
    &D_800A5914,
    &D_800A5928,
    &D_800A593C,
    &D_800A5950,
    &D_800A5964,
    &D_800A5978,
    &D_800A598C,
    &D_800A59A0,
    &D_800A59B4,
    &D_800A59C8,
    &D_800A59DC,
    &D_800A59F0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 1273, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xB, 6, 0, 1277, 496, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x3B, 6, 0, 1184, 497, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 3, 6, 0, 1180, 483, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 1272, 754, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1104, 797, 832, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 325, 419, 441, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 388, 386, 410, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26E, 0x344, 0x196, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26E, 0x318, 0x264, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26E, 0x404, 0x1F6, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x49E, 0x2F0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x48F, 0x348, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1240, D_800A4E68, EVENT_TEXT(6), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
