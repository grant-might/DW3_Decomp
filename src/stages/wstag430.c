#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x213
#define STAGE_ARCHIVE 0x316
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x222
#define STAGE_ARCHIVE 0x325
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x18300, 0x1E600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F8C[];
extern u16 D_800A4F94[];
extern u16 D_800A4F9C[];
extern u16 D_800A4FA4[];
extern u16 D_800A4FAC[];
extern u16 D_800A4FB4[];
extern u16 D_800A4FBC[];
extern u16 D_800A4FC4[];
extern u16 D_800A4FCC[];
extern u16 D_800A4FD4[];
extern u16 D_800A4FDC[];
extern u16 D_800A4FE4[];
extern u16 D_800A4FEC[];
extern FieldTalk D_800A4FF4[];
extern FieldTalk D_800A5018[];
extern u16 D_800A536C[];
extern FieldTalk D_800A503C[];
extern u16 D_800A5374[];
extern FieldTalk D_800A5060[];
extern u16 D_800A537C[];
extern FieldTalk D_800A5078[];
extern u16 D_800A5384[];
extern FieldTalk D_800A5090[];
extern u16 D_800A538C[];
extern FieldTalk D_800A50A8[];
extern u16 D_800A5394[];
extern FieldTalk D_800A50C0[];
extern u16 D_800A539C[];
extern FieldTalk D_800A50D8[];
extern u16 D_800A53A4[];
extern FieldTalk D_800A50F0[];
extern u16 D_800A53AC[];
extern FieldTalk D_800A5108[];
extern u16 D_800A53B4[];
extern FieldTalk D_800A5120[];
extern u16 D_800A53BC[];
extern FieldTalk D_800A5138[];
extern u16 D_800A53C4[];
extern FieldTalk D_800A5150[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A5168[];
extern u16 D_800A53D4[];
extern FieldTalk D_800A5180[];
extern u16 D_800A53DC[];
extern FieldTalk D_800A5198[];
extern u16 D_800A53E4[];
extern FieldTalk D_800A51B0[];
extern u16 D_800A53EC[];
extern FieldTalk D_800A51C8[];
extern u16 D_800A53F4[];
extern FieldTalk D_800A51E0[];
extern u16 D_800A53FC[];
extern FieldTalk D_800A51F8[];
extern u16 D_800A5404[];
extern FieldTalk D_800A5210[];
extern u16 D_800A540C[];
extern FieldTalk D_800A5228[];
extern u16 D_800A5414[];
extern FieldTalk D_800A5240[];
extern u16 D_800A541C[];
extern FieldTalk D_800A5258[];
extern u16 D_800A5424[];
extern FieldTalk D_800A527C[];
extern u16 D_800A542C[];
extern FieldTalk D_800A5294[];
extern u16 D_800A5434[];
extern FieldTalk D_800A52AC[];
extern u16 D_800A543C[];
extern FieldTalk D_800A52C4[];
extern u16 D_800A5444[];
extern FieldTalk D_800A52DC[];
extern u16 D_800A544C[];
extern FieldTalk D_800A52F4[];
extern u16 D_800A5454[];
extern FieldTalk D_800A530C[];
extern u16 D_800A545C[];
extern FieldTalk D_800A5324[];
extern u16 D_800A5464[];
extern FieldTalk D_800A533C[];
extern u16 D_800A546C[];
extern FieldTalk D_800A5354[];
extern FieldActorEntry D_800A5474;
extern FieldActorEntry D_800A5488;
extern FieldActorEntry D_800A549C;
extern FieldActorEntry D_800A54B0;
extern FieldActorEntry D_800A54C4;
extern FieldActorEntry D_800A54D8;
extern FieldActorEntry D_800A54EC;
extern FieldActorEntry D_800A5500;
extern FieldActorEntry D_800A5514;
extern FieldActorEntry D_800A5528;
extern FieldActorEntry D_800A553C;
extern FieldActorEntry D_800A5550;
extern FieldActorEntry D_800A5564;
extern FieldActorEntry D_800A5578;
extern FieldActorEntry D_800A558C;
extern FieldActorEntry D_800A55A0;
extern FieldActorEntry D_800A55B4;
extern FieldActorEntry D_800A55C8;
extern FieldActorEntry D_800A55DC;
extern FieldActorEntry D_800A55F0;
extern FieldActorEntry D_800A5604;
extern FieldActorEntry D_800A5618;
extern FieldActorEntry D_800A562C;
extern FieldActorEntry D_800A5640;
extern FieldActorEntry D_800A5654;
extern FieldActorEntry D_800A5668;
extern FieldActorEntry D_800A567C;
extern FieldActorEntry D_800A5690;
extern FieldActorEntry D_800A56A4;
extern FieldActorEntry D_800A56B8;
extern FieldActorEntry D_800A56CC;
extern FieldActorEntry D_800A56E0;
extern FieldActorEntry D_800A56F4;
extern FieldActorEntry D_800A5708;
extern FieldActorEntry D_800A571C;
extern s16 D_800A4E38[];

s16 D_800A4E38[] = {
    0x102, 2, 0x178, 0x1AC, 5,
    0x100, 0x15, 0x198, 0x19E,
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
    0x304, 0xC02, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x16E, 0x98, 0x6E, 0x160, 0x1FD },
    { 0x140, 0x100, 0x172, 0x16E, 0xC8, 0x6E, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1AA, 0x175, 0x1A8, 0x75, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1A6, 0x100, 0x198, 0, 0x160, 0x1FC },
    { 0x180, 0x100, 0x1AE, 0x100, 0x1B8, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x176, 0x148, 0xD8, 0x48, 0x140, 0x1FB },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1B6, 0x120, 0x1D8, 0x20, 0x160, 0x1FB },
};
u16 D_800A4F8C[] = { 0x1A09, 0, 0xFFFF };
u16 D_800A4F94[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4F9C[] = { 0x1A09, 1, 0xFFFF };
u16 D_800A4FA4[] = { 0x900C, 1, 0xFFFF };
u16 D_800A4FAC[] = { 0x1A33, 0, 0xFFFF };
u16 D_800A4FB4[] = { 0x1A33, 1, 0xFFFF };
u16 D_800A4FBC[] = { 0x1A33, 1, 0xFFFF };
u16 D_800A4FC4[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A4FCC[] = { 0x1C11, 0, 0xFFFF };
u16 D_800A4FD4[] = { 0x1C0F, 1, 0xFFFF };
u16 D_800A4FDC[] = { 0x1C11, 1, 0xFFFF };
u16 D_800A4FE4[] = { 0x4011, 0, 0xFFFF };
u16 D_800A4FEC[] = { 0x4011, 1, 0xFFFF };
FieldTalk D_800A4FF4[] = {
    { D_800A4F8C, D_800A4F94, 3 },
    { D_800A4F9C, D_800A4FA4, 2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5018[] = {
    { D_800A4FAC, D_800A4FB4, 0x122 },
    { D_800A4FBC, D_800A4FC4, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A503C[] = {
    { D_800A4FCC, D_800A4FD4, 0x4F },
    { D_800A4FDC, NULL, 0x126 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5060[] = {
    { NULL, NULL, 0x5C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5078[] = {
    { NULL, NULL, 0x176 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5090[] = {
    { NULL, NULL, 0x5F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A8[] = {
    { NULL, NULL, 0x62 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C0[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D8[] = {
    { NULL, NULL, 0x6B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F0[] = {
    { NULL, NULL, 0x53 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5108[] = {
    { NULL, NULL, 0x50 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5120[] = {
    { NULL, NULL, 0x59 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5138[] = {
    { NULL, NULL, 0x4D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5150[] = {
    { NULL, NULL, 0x5D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5168[] = {
    { NULL, NULL, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5180[] = {
    { NULL, NULL, 0x6C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5198[] = {
    { NULL, NULL, 0x66 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B0[] = {
    { NULL, NULL, 0x63 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C8[] = {
    { NULL, NULL, 0x60 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E0[] = {
    { NULL, NULL, 0x54 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F8[] = {
    { NULL, NULL, 0x57 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5210[] = {
    { NULL, NULL, 0x5A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5228[] = {
    { NULL, NULL, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5240[] = {
    { NULL, NULL, 0x61 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5258[] = {
    { D_800A4FE4, NULL, 0x15D },
    { D_800A4FEC, NULL, 0x52 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A527C[] = {
    { NULL, NULL, 0x6D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5294[] = {
    { NULL, NULL, 0x67 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52AC[] = {
    { NULL, NULL, 0x64 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C4[] = {
    { NULL, NULL, 0x55 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52DC[] = {
    { NULL, NULL, 0x58 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F4[] = {
    { NULL, NULL, 0x5B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A530C[] = {
    { NULL, NULL, 0x5E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5324[] = {
    { NULL, NULL, 0x6A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A533C[] = {
    { NULL, NULL, 0x69 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5354[] = {
    { NULL, NULL, 0x68 },
    { NULL, NULL, 0 },
};
u16 D_800A536C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5374[] = { 0x6016, 1, 0xFFFF };
u16 D_800A537C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5384[] = { 0x7018, 1, 0xFFFF };
u16 D_800A538C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5394[] = { 0x6026, 1, 0xFFFF };
u16 D_800A539C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A53AC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A53B4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A53BC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A53C4[] = { 0x7017, 1, 0xFFFF };
u16 D_800A53CC[] = { 0x7015, 1, 0xFFFF };
u16 D_800A53D4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53DC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53E4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A53EC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A53F4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A53FC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5404[] = { 0x7016, 1, 0xFFFF };
u16 D_800A540C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5414[] = { 0x7018, 1, 0xFFFF };
u16 D_800A541C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5424[] = { 0x602B, 1, 0xFFFF };
u16 D_800A542C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5434[] = { 0x7019, 1, 0xFFFF };
u16 D_800A543C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5444[] = { 0x600E, 1, 0xFFFF };
u16 D_800A544C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5454[] = { 0x7017, 1, 0xFFFF };
u16 D_800A545C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5464[] = { 0x701A, 1, 0xFFFF };
u16 D_800A546C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5474 = { NULL, D_800A4FF4, 0x15, 4, 408, 414, 1 };
FieldActorEntry D_800A5488 = { NULL, D_800A5018, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A549C = { D_800A536C, D_800A503C, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A54B0 = { D_800A5374, D_800A5060, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A54C4 = { D_800A537C, D_800A5078, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A54D8 = { D_800A5384, D_800A5090, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A54EC = { D_800A538C, D_800A50A8, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A5500 = { D_800A5394, D_800A50C0, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A5514 = { D_800A539C, D_800A50D8, 0x2D, 6, 513, 241, 3 };
FieldActorEntry D_800A5528 = { D_800A53A4, D_800A50F0, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A553C = { D_800A53AC, D_800A5108, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A5550 = { D_800A53B4, D_800A5120, 0x2D, 6, 171, 403, 5 };
FieldActorEntry D_800A5564 = { D_800A53BC, D_800A5138, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A5578 = { D_800A53C4, D_800A5150, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A558C = { D_800A53CC, D_800A5168, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A55A0 = { D_800A53D4, D_800A5180, 0x35, 7, 256, 511, 3 };
FieldActorEntry D_800A55B4 = { D_800A53DC, D_800A5198, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A55C8 = { D_800A53E4, D_800A51B0, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A55DC = { D_800A53EC, D_800A51C8, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A55F0 = { D_800A53F4, D_800A51E0, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A5604 = { D_800A53FC, D_800A51F8, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A5618 = { D_800A5404, D_800A5210, 0x35, 7, 513, 241, 3 };
FieldActorEntry D_800A562C = { D_800A540C, D_800A5228, 0x36, 8, 481, 225, 7 };
FieldActorEntry D_800A5640 = { D_800A5414, D_800A5240, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A5654 = { D_800A541C, D_800A5258, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A5668 = { D_800A5424, D_800A527C, 0x36, 8, 481, 225, 7 };
FieldActorEntry D_800A567C = { D_800A542C, D_800A5294, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A5690 = { D_800A5434, D_800A52AC, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A56A4 = { D_800A543C, D_800A52C4, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A56B8 = { D_800A5444, D_800A52DC, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A56CC = { D_800A544C, D_800A52F4, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A56E0 = { D_800A5454, D_800A530C, 0x36, 8, 481, 225, 5 };
FieldActorEntry D_800A56F4 = { D_800A545C, D_800A5324, 0x9D, 9, 481, 225, 5 };
FieldActorEntry D_800A5708 = { D_800A5464, D_800A533C, 0x9E, 0xA, 513, 241, 3 };
FieldActorEntry D_800A571C = { D_800A546C, D_800A5354, 0x9F, 0xB, 171, 403, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5474,
    &D_800A5488,
    &D_800A549C,
    &D_800A54B0,
    &D_800A54C4,
    &D_800A54D8,
    &D_800A54EC,
    &D_800A5500,
    &D_800A5514,
    &D_800A5528,
    &D_800A553C,
    &D_800A5550,
    &D_800A5564,
    &D_800A5578,
    &D_800A558C,
    &D_800A55A0,
    &D_800A55B4,
    &D_800A55C8,
    &D_800A55DC,
    &D_800A55F0,
    &D_800A5604,
    &D_800A5618,
    &D_800A562C,
    &D_800A5640,
    &D_800A5654,
    &D_800A5668,
    &D_800A567C,
    &D_800A5690,
    &D_800A56A4,
    &D_800A56B8,
    &D_800A56CC,
    &D_800A56E0,
    &D_800A56F4,
    &D_800A5708,
    &D_800A571C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 0xA, 0, 283, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 0xA, 0, 428, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 0xA, 0, 307, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 287, 459, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 297, 464, 0, 0 },
    { 1, 0, 0x40, 6, 4, 1, 4, 9, 4, 0, 350, 338, 0, 0 },
    { 1, 0, 0x40, 6, 0xA, 1, 0xA, 0xD, 4, 0, 293, 279, 0, 0 },
    { 1, 0, 0x40, 6, 0xE, 1, 0xE, 0x11, 4, 0, 298, 381, 0, 0 },
    { 1, 0, 0x40, 6, 0x12, 1, 0x12, 0x15, 4, 0, 293, 427, 0, 0 },
    { 1, 0, 0x40, 4, 0x35, 2, 0, 1, 0xA, 0, 333, 483, 503, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 501, 393, 406, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 451, 436, 456, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 436, 464, 482, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 320, 474, 503, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 438, 274, 292, 0 },
    { 1, 0, 0x40, 4, 0x17, 0, 0, 0, 0, 0, 464, 277, 302, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22E, 0x2F8, 0x104, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22E, 0x1E8, 0xA4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1210, D_800A4E38, EVENT_TEXT(0x10), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
