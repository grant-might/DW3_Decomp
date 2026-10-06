#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x57D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x58D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x32500, 0x36900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xA;
    D_800990B4.music = 0x60280000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5324[];
extern u16 D_800A5330[];
extern u16 D_800A533C[];
extern u16 D_800A5344[];
extern u16 D_800A5354[];
extern u16 D_800A535C[];
extern u16 D_800A536C[];
extern u16 D_800A5398[];
extern u16 D_800A53A4[];
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C8[];
extern u16 D_800A53D0[];
extern u16 D_800A53E0[];
extern u16 D_800A53F0[];
extern u16 D_800A53FC[];
extern u16 D_800A540C[];
extern u16 D_800A5418[];
extern u16 D_800A542C[];
extern u16 D_800A5438[];
extern u16 D_800A5450[];
extern u16 D_800A5458[];
extern u16 D_800A5470[];
extern u16 D_800A5478[];
extern u16 D_800A5490[];
extern u16 D_800A54A4[];
extern u16 D_800A54B0[];
extern u16 D_800A54BC[];
extern u16 D_800A54C4[];
extern u16 D_800A54D4[];
extern u16 D_800A54DC[];
extern u16 D_800A54EC[];
extern u16 D_800A5500[];
extern u16 D_800A550C[];
extern u16 D_800A5518[];
extern u16 D_800A5520[];
extern u16 D_800A5530[];
extern u16 D_800A5538[];
extern u16 D_800A5548[];
extern u16 D_800A555C[];
extern u16 D_800A5568[];
extern u16 D_800A5574[];
extern u16 D_800A557C[];
extern u16 D_800A558C[];
extern u16 D_800A5594[];
extern u16 D_800A55A4[];
extern u16 D_800A55B8[];
extern u16 D_800A55C4[];
extern u16 D_800A55D0[];
extern u16 D_800A55D8[];
extern u16 D_800A55E8[];
extern u16 D_800A55F0[];
extern u16 D_800A5600[];
extern u16 D_800A5614[];
extern u16 D_800A5620[];
extern u16 D_800A562C[];
extern u16 D_800A5634[];
extern u16 D_800A5644[];
extern u16 D_800A564C[];
extern u16 D_800A565C[];
extern u16 D_800A5670[];
extern u16 D_800A567C[];
extern u16 D_800A5688[];
extern u16 D_800A5690[];
extern u16 D_800A56A0[];
extern u16 D_800A56A8[];
extern u16 D_800A56B8[];
extern u16 D_800A56CC[];
extern u16 D_800A56D8[];
extern u16 D_800A56E4[];
extern u16 D_800A56EC[];
extern u16 D_800A56FC[];
extern u16 D_800A5704[];
extern u16 D_800A5714[];
extern u16 D_800A5728[];
extern u16 D_800A5734[];
extern u16 D_800A5740[];
extern u16 D_800A5748[];
extern u16 D_800A5758[];
extern u16 D_800A5760[];
extern u16 D_800A5770[];
extern u16 D_800A5784[];
extern u16 D_800A5790[];
extern u16 D_800A579C[];
extern u16 D_800A57A4[];
extern u16 D_800A57B4[];
extern u16 D_800A57BC[];
extern u16 D_800A57CC[];
extern u16 D_800A5BB8[];
extern u16 D_800A5BC0[];
extern FieldTalk D_800A57E0[];
extern u16 D_800A5BC8[];
extern FieldTalk D_800A57F8[];
extern u16 D_800A5BD0[];
extern FieldTalk D_800A5810[];
extern u16 D_800A5BD8[];
extern FieldTalk D_800A5828[];
extern u16 D_800A5BE0[];
extern FieldTalk D_800A5840[];
extern u16 D_800A5BE8[];
extern FieldTalk D_800A5858[];
extern u16 D_800A5BF0[];
extern FieldTalk D_800A5870[];
extern u16 D_800A5BF8[];
extern FieldTalk D_800A5888[];
extern u16 D_800A5C00[];
extern FieldTalk D_800A58C4[];
extern u16 D_800A5C08[];
extern FieldTalk D_800A5900[];
extern u16 D_800A5C10[];
extern FieldTalk D_800A5918[];
extern u16 D_800A5C1C[];
extern FieldTalk D_800A596C[];
extern u16 D_800A5C28[];
extern FieldTalk D_800A59A8[];
extern u16 D_800A5C34[];
extern FieldTalk D_800A59E4[];
extern u16 D_800A5C40[];
extern FieldTalk D_800A5A20[];
extern u16 D_800A5C4C[];
extern FieldTalk D_800A5A5C[];
extern u16 D_800A5C58[];
extern FieldTalk D_800A5A98[];
extern u16 D_800A5C64[];
extern FieldTalk D_800A5AD4[];
extern u16 D_800A5C70[];
extern FieldTalk D_800A5B10[];
extern u16 D_800A5C7C[];
extern FieldTalk D_800A5B4C[];
extern u16 D_800A5C88[];
extern FieldTalk D_800A5B88[];
extern u16 D_800A5C90[];
extern FieldTalk D_800A5BA0[];
extern FieldActorEntry D_800A5C98;
extern FieldActorEntry D_800A5CAC;
extern FieldActorEntry D_800A5CC0;
extern FieldActorEntry D_800A5CD4;
extern FieldActorEntry D_800A5CE8;
extern FieldActorEntry D_800A5CFC;
extern FieldActorEntry D_800A5D10;
extern FieldActorEntry D_800A5D24;
extern FieldActorEntry D_800A5D38;
extern FieldActorEntry D_800A5D4C;
extern FieldActorEntry D_800A5D60;
extern FieldActorEntry D_800A5D74;
extern FieldActorEntry D_800A5D88;
extern FieldActorEntry D_800A5D9C;
extern FieldActorEntry D_800A5DB0;
extern FieldActorEntry D_800A5DC4;
extern FieldActorEntry D_800A5DD8;
extern FieldActorEntry D_800A5DEC;
extern FieldActorEntry D_800A5E00;
extern FieldActorEntry D_800A5E14;
extern FieldActorEntry D_800A5E28;
extern FieldActorEntry D_800A5E3C;
extern FieldActorEntry D_800A5E50;
extern s16 D_800A4E38[];
extern s16 D_800A4ED4[];
extern s16 D_800A4F70[];
extern s16 D_800A4FE8[];
extern s16 D_800A5060[];
extern s16 D_800A50D8[];

s16 D_800A4E38[] = {
    0x102, 2, 0x1F7, 0x214, 3,
    0x100, 0x145, 0x1E0, 0x209,
    0x101, 0x145, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x145, 1, 3,
    0x300, 0x1E,
    0x102, 0x145, 0x1D5, 0x202, 3,
    0x302, 0x145,
    0x101, 0x145, 1, 3,
    0x300, 0x1E,
    0x101, 0x145, 1, 5,
    0x300, 0x1E,
    0x102, 0x145, 0x1F8, 0x1F0, 5,
    0x302, 0x145,
    0x101, 0x145, 1, 5,
    0x300, 0x1E,
    0x101, 0x145, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x145, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4ED4[] = {
    0x102, 2, 0x191, 0x1E1, 1,
    0x100, 0x144, 0x177, 0x1ED,
    0x101, 0x144, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 0x144, 1, 1,
    0x300, 0x1E,
    0x102, 0x144, 0x165, 0x1F5, 1,
    0x302, 0x144,
    0x101, 0x144, 1, 1,
    0x300, 0x1E,
    0x101, 0x144, 1, 3,
    0x300, 0x1E,
    0x102, 0x144, 0x141, 0x1E5, 3,
    0x302, 0x144,
    0x101, 0x144, 1, 3,
    0x300, 0x1E,
    0x101, 0x144, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x144, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4F70[] = {
    0x102, 2, 0x128, 0x1FC, 3,
    0x100, 0x143, 0x110, 0x1F1,
    0x101, 0x143, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x143, 1, 3,
    0x300, 0x1E,
    0x102, 0x143, 0xCC, 0x1CE, 3,
    0x302, 0x143,
    0x101, 0x143, 1, 3,
    0x300, 0x1E,
    0x101, 0x143, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x143, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4FE8[] = {
    0x102, 2, 0x140, 0x180, 3,
    0x100, 0x129, 0x129, 0x175,
    0x101, 0x129, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x129, 1, 5,
    0x300, 0x1E,
    0x102, 0x129, 0x155, 0x15D, 5,
    0x302, 0x129,
    0x101, 0x129, 1, 5,
    0x300, 0x1E,
    0x101, 0x129, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x129, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5060[] = {
    0x102, 2, 0xF0, 0x118, 3,
    0x100, 0x12A, 0xD8, 0x10D,
    0x101, 0x12A, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x12A, 1, 5,
    0x300, 0x1E,
    0x102, 0x12A, 0x104, 0xF7, 5,
    0x302, 0x12A,
    0x101, 0x12A, 1, 5,
    0x300, 0x1E,
    0x101, 0x12A, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x12A, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A50D8[] = {
    0x102, 2, 0xB7, 0xBD, 3,
    0x100, 0xC0, 0x9F, 0xB1,
    0x101, 0xC0, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0xC0, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xC0, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xC0, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0xBF, 0xC1, 7,
    0x302, 2,
    0x304, 0x297, 0x250, 0x278, 7,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x1B3, 0xC8, 0xB3, 0x170, 0x1F8 },
    { 0x180, 0x100, 0x1AC, 0x100, 0x1B0, 0, 0x140, 0x1F7 },
    { 0x140, 0x100, 0x16A, 0x1C5, 0xA8, 0xC5, 0x150, 0x1F7 },
    { 0x180, 0x100, 0x180, 0x178, 0x100, 0x78, 0x170, 0x1F7 },
    { 0x180, 0x100, 0x188, 0x178, 0x120, 0x78, 0x140, 0x1F6 },
    { 0x180, 0x100, 0x190, 0x178, 0x140, 0x78, 0x150, 0x1F6 },
    { 0x180, 0x100, 0x198, 0x178, 0x160, 0x78, 0x170, 0x1F6 },
    { 0x180, 0x100, 0x1A0, 0x178, 0x180, 0x78, 0x140, 0x1F5 },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x150, 0x1F5 },
    { 0x180, 0x100, 0x1A8, 0x178, 0x1A0, 0x78, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x1B0, 0x178, 0x1C0, 0x78, 0x140, 0x1F4 },
    { 0x180, 0x100, 0x180, 0x1A0, 0x100, 0xA0, 0x150, 0x1F4 },
    { 0x180, 0x100, 0x188, 0x1A0, 0x120, 0xA0, 0x170, 0x1F4 },
    { 0x180, 0x100, 0x190, 0x1A0, 0x140, 0xA0, 0x140, 0x1F3 },
    { 0x180, 0x100, 0x198, 0x1A0, 0x160, 0xA0, 0x150, 0x1F3 },
    { 0x180, 0x100, 0x1A0, 0x1A0, 0x180, 0xA0, 0x160, 0x1F3 },
    { 0x180, 0x100, 0x1A8, 0x1A0, 0x1A0, 0xA0, 0x170, 0x1F3 },
};
u16 D_800A5324[] = { 0x11, 0, 0x1C54, 1, 0xFFFF };
u16 D_800A5330[] = { 0x11, 0, 0x1C54, 0, 0xFFFF };
u16 D_800A533C[] = { 0x7625, 1, 0xFFFF };
u16 D_800A5344[] = { 0x11, 1, 0x10, 0, 0x1C54, 0, 0xFFFF };
u16 D_800A5354[] = { 0x11, 0, 0xFFFF };
u16 D_800A535C[] = { 0x1C54, 0, 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A536C[] = {
    0x11, 0, 0x10, 0, 0x8014, 1, 0x1C54, 1,
    0x1A40, 0, 0x1A3F, 0, 0x1A3E, 0, 0x1A3D, 0,
    0x1A3C, 0, 0x906C, 1, 0xFFFF,
};
u16 D_800A5398[] = { 0x11, 0, 0x1C56, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x11, 0, 0x1C56, 0, 0xFFFF };
u16 D_800A53B0[] = { 0x7825, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x11, 1, 0x10, 0, 0x1C56, 0, 0xFFFF };
u16 D_800A53C8[] = { 0x11, 0, 0xFFFF };
u16 D_800A53D0[] = { 0x11, 1, 0x10, 1, 0x1C56, 0, 0xFFFF };
u16 D_800A53E0[] = { 0x11, 0, 0x10, 0, 0x1C56, 1, 0xFFFF };
u16 D_800A53F0[] = { 0x1A3F, 1, 0x11, 0, 0xFFFF };
u16 D_800A53FC[] = { 0x11, 0, 0x1A3F, 0, 0x818D, 0, 0xFFFF };
u16 D_800A540C[] = { 0x1C49, 1, 0x1C42, 1, 0xFFFF };
u16 D_800A5418[] = { 0x11, 0, 0x818D, 1, 0x1A3F, 0, 0x1C4A, 0, 0xFFFF };
u16 D_800A542C[] = { 0x7627, 1, 0x1C4A, 1, 0xFFFF };
u16 D_800A5438[] = {
    0x11, 0, 0x818D, 1, 0x1C4A, 1, 0x10, 0,
    0x1A3F, 0, 0xFFFF,
};
u16 D_800A5450[] = { 0x7627, 1, 0xFFFF };
u16 D_800A5458[] = {
    0x11, 1, 0x818D, 1, 0x1C4A, 1, 0x10, 0,
    0x1A3F, 0, 0xFFFF,
};
u16 D_800A5470[] = { 0x11, 0, 0xFFFF };
u16 D_800A5478[] = {
    0x11, 1, 0x818D, 1, 0x1C4A, 1, 0x10, 1,
    0x1A3F, 0, 0xFFFF,
};
u16 D_800A5490[] = { 0x11, 0, 0x10, 0, 0x1A3F, 1, 0x9059, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x1A3F, 1, 0x11, 0, 0xFFFF };
u16 D_800A54B0[] = { 0x11, 0, 0x1A3F, 0, 0xFFFF };
u16 D_800A54BC[] = { 0x7827, 1, 0xFFFF };
u16 D_800A54C4[] = { 0x11, 1, 0x10, 0, 0x1A3F, 0, 0xFFFF };
u16 D_800A54D4[] = { 0x11, 0, 0xFFFF };
u16 D_800A54DC[] = { 0x11, 1, 0x10, 1, 0x1A3F, 0, 0xFFFF };
u16 D_800A54EC[] = { 0x11, 0, 0x10, 0, 0x9059, 1, 0x1A3F, 1, 0xFFFF };
u16 D_800A5500[] = { 0x11, 0, 0x1A40, 1, 0xFFFF };
u16 D_800A550C[] = { 0x11, 0, 0x1A40, 0, 0xFFFF };
u16 D_800A5518[] = { 0x7626, 1, 0xFFFF };
u16 D_800A5520[] = { 0x11, 1, 0x10, 0, 0x1A40, 0, 0xFFFF };
u16 D_800A5530[] = { 0x11, 0, 0xFFFF };
u16 D_800A5538[] = { 0x10, 1, 0x11, 1, 0x1A40, 0, 0xFFFF };
u16 D_800A5548[] = { 0x11, 0, 0x10, 0, 0x905A, 1, 0x1A40, 1, 0xFFFF };
u16 D_800A555C[] = { 0x11, 0, 0x1A40, 1, 0xFFFF };
u16 D_800A5568[] = { 0x11, 0, 0x1A40, 0, 0xFFFF };
u16 D_800A5574[] = { 0x7826, 1, 0xFFFF };
u16 D_800A557C[] = { 0x11, 1, 0x10, 0, 0x1A40, 0, 0xFFFF };
u16 D_800A558C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5594[] = { 0x11, 1, 0x10, 1, 0x1A40, 0, 0xFFFF };
u16 D_800A55A4[] = { 0x11, 0, 0x10, 0, 0x905A, 1, 0x1A40, 1, 0xFFFF };
u16 D_800A55B8[] = { 0x11, 0, 0x1A3E, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x11, 0, 0x1A3E, 0, 0xFFFF };
u16 D_800A55D0[] = { 0x7628, 1, 0xFFFF };
u16 D_800A55D8[] = { 0x11, 1, 0x10, 0, 0x1A3E, 0, 0xFFFF };
u16 D_800A55E8[] = { 0x11, 0, 0xFFFF };
u16 D_800A55F0[] = { 0x11, 1, 0x10, 1, 0x1A3E, 0, 0xFFFF };
u16 D_800A5600[] = { 0x11, 0, 0x10, 0, 0x9058, 1, 0x1A3E, 1, 0xFFFF };
u16 D_800A5614[] = { 0x11, 0, 0x1A3E, 1, 0xFFFF };
u16 D_800A5620[] = { 0x11, 0, 0x1A3E, 0, 0xFFFF };
u16 D_800A562C[] = { 0x7828, 1, 0xFFFF };
u16 D_800A5634[] = { 0x11, 1, 0x10, 0, 0x1A3E, 0, 0xFFFF };
u16 D_800A5644[] = { 0x11, 0, 0xFFFF };
u16 D_800A564C[] = { 0x11, 1, 0x10, 1, 0x1A3E, 0, 0xFFFF };
u16 D_800A565C[] = { 0x11, 0, 0x10, 0, 0x9058, 1, 0x1A3E, 1, 0xFFFF };
u16 D_800A5670[] = { 0x11, 0, 0x1A3D, 1, 0xFFFF };
u16 D_800A567C[] = { 0x11, 0, 0x1A3D, 0, 0xFFFF };
u16 D_800A5688[] = { 0x7629, 1, 0xFFFF };
u16 D_800A5690[] = { 0x11, 1, 0x10, 0, 0x1A3D, 0, 0xFFFF };
u16 D_800A56A0[] = { 0x11, 0, 0xFFFF };
u16 D_800A56A8[] = { 0x11, 1, 0x10, 1, 0x1A3D, 0, 0xFFFF };
u16 D_800A56B8[] = { 0x11, 0, 0x10, 0, 0x9057, 1, 0x1A3D, 1, 0xFFFF };
u16 D_800A56CC[] = { 0x11, 0, 0x1A3D, 1, 0xFFFF };
u16 D_800A56D8[] = { 0x11, 0, 0x1A3D, 0, 0xFFFF };
u16 D_800A56E4[] = { 0x7829, 1, 0xFFFF };
u16 D_800A56EC[] = { 0x11, 1, 0x10, 0, 0x1A3D, 0, 0xFFFF };
u16 D_800A56FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A5704[] = { 0x11, 1, 0x10, 1, 0x1A3D, 0, 0xFFFF };
u16 D_800A5714[] = { 0x11, 0, 0x10, 0, 0x9057, 1, 0x1A3D, 1, 0xFFFF };
u16 D_800A5728[] = { 0x11, 0, 0x1A3C, 1, 0xFFFF };
u16 D_800A5734[] = { 0x11, 0, 0x1A3C, 0, 0xFFFF };
u16 D_800A5740[] = { 0x762A, 1, 0xFFFF };
u16 D_800A5748[] = { 0x11, 1, 0x10, 0, 0x1A3C, 0, 0xFFFF };
u16 D_800A5758[] = { 0x11, 0, 0xFFFF };
u16 D_800A5760[] = { 0x11, 1, 0x10, 1, 0x1A3C, 0, 0xFFFF };
u16 D_800A5770[] = { 0x11, 0, 0x10, 0, 0x9056, 1, 0x1A3C, 1, 0xFFFF };
u16 D_800A5784[] = { 0x11, 0, 0x1A3C, 1, 0xFFFF };
u16 D_800A5790[] = { 0x1A3C, 0, 0x11, 0, 0xFFFF };
u16 D_800A579C[] = { 0x782A, 1, 0xFFFF };
u16 D_800A57A4[] = { 0x11, 1, 0x10, 0, 0x1A3C, 0, 0xFFFF };
u16 D_800A57B4[] = { 0x11, 0, 0xFFFF };
u16 D_800A57BC[] = { 0x11, 1, 0x10, 1, 0x1A3C, 0, 0xFFFF };
u16 D_800A57CC[] = { 0x11, 0, 0x10, 0, 0x9056, 1, 0x1A3C, 1, 0xFFFF };
FieldTalk D_800A57E0[] = {
    { NULL, NULL, 0x34B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57F8[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5810[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5828[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5840[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5858[] = {
    { NULL, NULL, 0x349 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5870[] = {
    { NULL, NULL, 0x34A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5888[] = {
    { D_800A5324, NULL, 0x339 },
    { D_800A5330, D_800A533C, 0x336 },
    { D_800A5344, D_800A5354, 0x337 },
    { D_800A535C, D_800A536C, 0x338 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { D_800A5398, NULL, 0x33D },
    { D_800A53A4, D_800A53B0, 0x33A },
    { D_800A53B8, D_800A53C8, 0x33B },
    { D_800A53D0, D_800A53E0, 0x33C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5900[] = {
    { NULL, NULL, 0x341 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5918[] = {
    { D_800A53F0, NULL, 0x330 },
    { D_800A53FC, D_800A540C, 0x332 },
    { D_800A5418, D_800A542C, 0x333 },
    { D_800A5438, D_800A5450, 0x334 },
    { D_800A5458, D_800A5470, 0x32E },
    { D_800A5478, D_800A5490, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A596C[] = {
    { D_800A54A4, NULL, 0x330 },
    { D_800A54B0, D_800A54BC, 0x32F },
    { D_800A54C4, D_800A54D4, 0x32E },
    { D_800A54DC, D_800A54EC, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A8[] = {
    { D_800A5500, NULL, 0x341 },
    { D_800A550C, D_800A5518, 0x33E },
    { D_800A5520, D_800A5530, 0x33F },
    { D_800A5538, D_800A5548, 0x340 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E4[] = {
    { D_800A555C, NULL, 0x341 },
    { D_800A5568, D_800A5574, 0x33E },
    { D_800A557C, D_800A558C, 0x33F },
    { D_800A5594, D_800A55A4, 0x340 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A20[] = {
    { D_800A55B8, NULL, 0x330 },
    { D_800A55C4, D_800A55D0, 0x32F },
    { D_800A55D8, D_800A55E8, 0x32E },
    { D_800A55F0, D_800A5600, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A5C[] = {
    { D_800A5614, NULL, 0x330 },
    { D_800A5620, D_800A562C, 0x32F },
    { D_800A5634, D_800A5644, 0x32E },
    { D_800A564C, D_800A565C, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A98[] = {
    { D_800A5670, NULL, 0x330 },
    { D_800A567C, D_800A5688, 0x32F },
    { D_800A5690, D_800A56A0, 0x32E },
    { D_800A56A8, D_800A56B8, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AD4[] = {
    { D_800A56CC, NULL, 0x330 },
    { D_800A56D8, D_800A56E4, 0x32F },
    { D_800A56EC, D_800A56FC, 0x32E },
    { D_800A5704, D_800A5714, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B10[] = {
    { D_800A5728, NULL, 0x330 },
    { D_800A5734, D_800A5740, 0x32F },
    { D_800A5748, D_800A5758, 0x32E },
    { D_800A5760, D_800A5770, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B4C[] = {
    { D_800A5784, NULL, 0x330 },
    { D_800A5790, D_800A579C, 0x32F },
    { D_800A57A4, D_800A57B4, 0x32E },
    { D_800A57BC, D_800A57CC, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B88[] = {
    { NULL, NULL, 0x34C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA0[] = {
    { NULL, NULL, 0x34C },
    { NULL, NULL, 0 },
};
u16 D_800A5BB8[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5BC0[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5BC8[] = { 0x1A3F, 1, 0xFFFF };
u16 D_800A5BD0[] = { 0x1A3E, 1, 0xFFFF };
u16 D_800A5BD8[] = { 0x1A3D, 1, 0xFFFF };
u16 D_800A5BE0[] = { 0x1A3C, 1, 0xFFFF };
u16 D_800A5BE8[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5BF0[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5BF8[] = { 0x8014, 0, 0xFFFF };
u16 D_800A5C00[] = { 0x8014, 1, 0xFFFF };
u16 D_800A5C08[] = { 0x1A40, 1, 0xFFFF };
u16 D_800A5C10[] = { 0x1A3F, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5C1C[] = { 0x1A3F, 0, 0x8014, 1, 0xFFFF };
u16 D_800A5C28[] = { 0x1A40, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5C34[] = { 0x1A40, 0, 0x8014, 1, 0xFFFF };
u16 D_800A5C40[] = { 0x1A3E, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5C4C[] = { 0x8014, 1, 0x1A3E, 0, 0xFFFF };
u16 D_800A5C58[] = { 0x1A3D, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5C64[] = { 0x1A3D, 0, 0x8014, 1, 0xFFFF };
u16 D_800A5C70[] = { 0x1A3C, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5C7C[] = { 0x1A3C, 0, 0x8014, 1, 0xFFFF };
u16 D_800A5C88[] = { 0x8192, 0, 0xFFFF };
u16 D_800A5C90[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A5C98 = { D_800A5BB8, NULL, 0x4B, 4, 588, 1083, 1 };
FieldActorEntry D_800A5CAC = { D_800A5BC0, D_800A57E0, 0x5B, 5, 993, 913, 1 };
FieldActorEntry D_800A5CC0 = { D_800A5BC8, D_800A57F8, 0x61, 6, 341, 349, 1 };
FieldActorEntry D_800A5CD4 = { D_800A5BD0, D_800A5810, 0x62, 7, 204, 462, 7 };
FieldActorEntry D_800A5CE8 = { D_800A5BD8, D_800A5828, 0xB8, 8, 321, 485, 7 };
FieldActorEntry D_800A5CFC = { D_800A5BE0, D_800A5840, 0xB9, 9, 504, 496, 1 };
FieldActorEntry D_800A5D10 = { D_800A5BE8, D_800A5858, 0xBA, 0xA, 769, 209, 1 };
FieldActorEntry D_800A5D24 = { D_800A5BF0, D_800A5870, 0xBB, 0xB, 929, 417, 1 };
FieldActorEntry D_800A5D38 = { D_800A5BF8, D_800A5888, 0xC0, 0xC, 159, 177, 7 };
FieldActorEntry D_800A5D4C = { D_800A5C00, D_800A58C4, 0xC0, 0xC, 159, 177, 7 };
FieldActorEntry D_800A5D60 = { D_800A5C08, D_800A5900, 0xC1, 0xD, 260, 247, 1 };
FieldActorEntry D_800A5D74 = { D_800A5C10, D_800A5918, 0x129, 0xE, 297, 373, 7 };
FieldActorEntry D_800A5D88 = { D_800A5C1C, D_800A596C, 0x129, 0xE, 297, 373, 7 };
FieldActorEntry D_800A5D9C = { D_800A5C28, D_800A59A8, 0x12A, 0xF, 216, 269, 7 };
FieldActorEntry D_800A5DB0 = { D_800A5C34, D_800A59E4, 0x12A, 0xF, 216, 269, 7 };
FieldActorEntry D_800A5DC4 = { D_800A5C40, D_800A5A20, 0x143, 0x10, 272, 497, 7 };
FieldActorEntry D_800A5DD8 = { D_800A5C4C, D_800A5A5C, 0x143, 0x10, 272, 497, 7 };
FieldActorEntry D_800A5DEC = { D_800A5C58, D_800A5A98, 0x144, 0x11, 375, 493, 7 };
FieldActorEntry D_800A5E00 = { D_800A5C64, D_800A5AD4, 0x144, 0x11, 375, 493, 7 };
FieldActorEntry D_800A5E14 = { D_800A5C70, D_800A5B10, 0x145, 0x12, 480, 521, 7 };
FieldActorEntry D_800A5E28 = { D_800A5C7C, D_800A5B4C, 0x145, 0x12, 480, 521, 7 };
FieldActorEntry D_800A5E3C = { D_800A5C88, D_800A5B88, 0x16B, 0x13, 501, 549, 7 };
FieldActorEntry D_800A5E50 = { D_800A5C90, D_800A5BA0, 0x16C, 0x14, 522, 538, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5C98,
    &D_800A5CAC,
    &D_800A5CC0,
    &D_800A5CD4,
    &D_800A5CE8,
    &D_800A5CFC,
    &D_800A5D10,
    &D_800A5D24,
    &D_800A5D38,
    &D_800A5D4C,
    &D_800A5D60,
    &D_800A5D74,
    &D_800A5D88,
    &D_800A5D9C,
    &D_800A5DB0,
    &D_800A5DC4,
    &D_800A5DD8,
    &D_800A5DEC,
    &D_800A5E00,
    &D_800A5E14,
    &D_800A5E28,
    &D_800A5E3C,
    &D_800A5E50,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 5, 8, 0, 85, 81, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 83, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 83, 135, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 91, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 91, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 99, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 99, 127, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 107, 105, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 107, 123, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 115, 101, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 115, 119, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 123, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 123, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 131, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 131, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 139, 89, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 139, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 147, 85, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 147, 103, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 155, 81, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 155, 99, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 163, 77, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 163, 95, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 87, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 87, 133, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 95, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 95, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 103, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 103, 125, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 111, 103, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 111, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 119, 99, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 119, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 127, 95, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 127, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 135, 91, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 135, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 143, 87, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 143, 105, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 151, 83, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 151, 101, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 159, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 159, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 167, 75, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 167, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0x4A, 2, 0, 7, 4, 0, 103, 201, 0, 0 },
    { 1, 0, 0x40, 2, 0x4B, 2, 0, 7, 4, 0, 105, 205, 0, 0 },
    { 1, 0, 0x80, 2, 1, 0, 0, 0, 0, 0, 768, 128, 0, 0 },
    { 1, 0, 0x78, 2, 3, 0, 0, 0, 0, 0, 896, 256, 0, 0 },
    { 1, 0, 0x55, 2, 4, 0, 0, 0, 0, 0, 984, 299, 0, 0 },
    { 1, 0, 0x33, 2, 5, 0, 0, 0, 0, 0, 278, 813, 0, 0 },
    { 1, 0, 0x1E, 2, 6, 0, 0, 0, 0, 0, 323, 829, 0, 0 },
    { 1, 0, 0x45, 2, 2, 0, 0, 0, 0, 0, 880, 156, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 220, 180, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 232, 138, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 297, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 300, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 168, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 220, 184, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 234, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 235, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 280, 241, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 300, 270, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 318, 861, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 427, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 543, 989, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 766, 529, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 903, 778, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 81, 1002, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 449, 833, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 518, 250, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 885, 1060, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1056, 440, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1108, 931, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 477, 577, 626, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xC0, 0xC2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xCF, 0x106, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x110, 0x12B, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x11F, 0x16E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x100, 0x192, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xF1, 0x1D6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x330, 0xEA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x33F, 0x12E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x2DE, 0x141, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x2CE, 0x186, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x12, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x12, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1436, D_800A4E38, EVENT_TEXT(0x2C), NULL, NULL },
    { 1438, D_800A4ED4, EVENT_TEXT(0x2D), NULL, NULL },
    { 1440, D_800A4F70, EVENT_TEXT(0x2E), NULL, NULL },
    { 1442, D_800A4FE8, EVENT_TEXT(0x2F), NULL, NULL },
    { 1444, D_800A5060, EVENT_TEXT(0x30), NULL, NULL },
    { 1446, D_800A50D8, EVENT_TEXT(0x32), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
