#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x58E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x59E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x19100, 0x1E700};
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

extern u16 D_800A503C[];
extern u16 D_800A5044[];
extern u16 D_800A504C[];
extern u16 D_800A5054[];
extern u16 D_800A505C[];
extern u16 D_800A5064[];
extern u16 D_800A506C[];
extern FieldTalk D_800A5074[];
extern u16 D_800A52E4[];
extern FieldTalk D_800A508C[];
extern u16 D_800A52EC[];
extern FieldTalk D_800A50A4[];
extern u16 D_800A52F8[];
extern FieldTalk D_800A50BC[];
extern u16 D_800A5304[];
extern FieldTalk D_800A50D4[];
extern u16 D_800A530C[];
extern FieldTalk D_800A50EC[];
extern u16 D_800A5314[];
extern FieldTalk D_800A5104[];
extern u16 D_800A5320[];
extern FieldTalk D_800A511C[];
extern u16 D_800A5328[];
extern FieldTalk D_800A5134[];
extern u16 D_800A5330[];
extern FieldTalk D_800A514C[];
extern u16 D_800A5338[];
extern FieldTalk D_800A5164[];
extern u16 D_800A5344[];
extern FieldTalk D_800A517C[];
extern u16 D_800A534C[];
extern FieldTalk D_800A5194[];
extern u16 D_800A5354[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A535C[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A5364[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A5370[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A5378[];
extern FieldTalk D_800A520C[];
extern u16 D_800A5380[];
extern FieldTalk D_800A5224[];
extern u16 D_800A538C[];
extern FieldTalk D_800A523C[];
extern u16 D_800A5394[];
extern FieldTalk D_800A5254[];
extern u16 D_800A53A0[];
extern FieldTalk D_800A526C[];
extern u16 D_800A53A8[];
extern FieldTalk D_800A5284[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A529C[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A53C0[];
extern FieldTalk D_800A52CC[];
extern FieldActorEntry D_800A53C8;
extern FieldActorEntry D_800A53DC;
extern FieldActorEntry D_800A53F0;
extern FieldActorEntry D_800A5404;
extern FieldActorEntry D_800A5418;
extern FieldActorEntry D_800A542C;
extern FieldActorEntry D_800A5440;
extern FieldActorEntry D_800A5454;
extern FieldActorEntry D_800A5468;
extern FieldActorEntry D_800A547C;
extern FieldActorEntry D_800A5490;
extern FieldActorEntry D_800A54A4;
extern FieldActorEntry D_800A54B8;
extern FieldActorEntry D_800A54CC;
extern FieldActorEntry D_800A54E0;
extern FieldActorEntry D_800A54F4;
extern FieldActorEntry D_800A5508;
extern FieldActorEntry D_800A551C;
extern FieldActorEntry D_800A5530;
extern FieldActorEntry D_800A5544;
extern FieldActorEntry D_800A5558;
extern FieldActorEntry D_800A556C;
extern FieldActorEntry D_800A5580;
extern FieldActorEntry D_800A5594;
extern FieldActorEntry D_800A55A8;
extern FieldActorEntry D_800A55BC;
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
    0x304, 0xC0C, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x150, 0x100, 0x40, 0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x170, 0x1FD },
    { 0x140, 0x100, 0x148, 0x126, 0x20, 0x26, 0x150, 0x1FC },
    { 0x140, 0x100, 0x15C, 0x128, 0x70, 0x28, 0x160, 0x1FC },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x140, 0x126, 0, 0x26, 0x140, 0x1FB },
    { 0x140, 0x100, 0x140, 0x156, 0, 0x56, 0x150, 0x1FB },
    { 0x140, 0x100, 0x150, 0x130, 0x40, 0x30, 0x160, 0x1FB },
    { 0x140, 0x100, 0x172, 0x130, 0xC8, 0x30, 0x170, 0x1FB },
    { 0x140, 0x100, 0x164, 0x142, 0x90, 0x42, 0x140, 0x1FA },
    { 0x140, 0x100, 0x16C, 0x142, 0xB0, 0x42, 0x150, 0x1FA },
    { 0x140, 0x100, 0x148, 0x14E, 0x20, 0x4E, 0x160, 0x1FA },
    { 0x140, 0x100, 0x158, 0x150, 0x60, 0x50, 0x170, 0x1FA },
    { 0x140, 0x100, 0x150, 0x158, 0x40, 0x58, 0x140, 0x1F9 },
    { 0x140, 0x100, 0x172, 0x158, 0xC8, 0x58, 0x150, 0x1F9 },
    { 0x140, 0x100, 0x160, 0x16A, 0x80, 0x6A, 0x160, 0x1F9 },
    { 0x140, 0x100, 0x168, 0x172, 0xA0, 0x72, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x140, 0x176, 0, 0x76, 0x140, 0x1F8 },
    { 0x140, 0x100, 0x148, 0x176, 0x20, 0x76, 0x150, 0x1F8 },
};
u16 D_800A503C[] = { 0x900D, 1, 0xFFFF };
u16 D_800A5044[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A504C[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A5054[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A505C[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A5064[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A506C[] = { 0x1A01, 1, 0xFFFF };
FieldTalk D_800A5074[] = {
    { NULL, D_800A503C, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A508C[] = {
    { NULL, D_800A5044, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A4[] = {
    { NULL, D_800A504C, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50BC[] = {
    { NULL, D_800A5054, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D4[] = {
    { NULL, D_800A505C, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50EC[] = {
    { NULL, D_800A5064, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5104[] = {
    { NULL, NULL, 0xF7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A511C[] = {
    { NULL, NULL, 0xFD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5134[] = {
    { NULL, NULL, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A514C[] = {
    { NULL, NULL, 0xF5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5164[] = {
    { NULL, NULL, 0xF0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A517C[] = {
    { NULL, NULL, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5194[] = {
    { NULL, NULL, 0x100 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51AC[] = {
    { NULL, NULL, 0xFB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0xFF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, D_800A506C, 0xFA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x1D2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x1D3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0xEF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0xF4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0xF6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0xF1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0xFC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0xF8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0xFE },
    { NULL, NULL, 0 },
};
u16 D_800A52E4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A52F8[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5304[] = { 0x701A, 1, 0xFFFF };
u16 D_800A530C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5314[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5320[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5328[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5330[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5338[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5344[] = { 0x602B, 1, 0xFFFF };
u16 D_800A534C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5354[] = { 0x6026, 1, 0xFFFF };
u16 D_800A535C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5364[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5370[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5378[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5380[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A538C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5394[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A53A0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53A8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53B0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53C0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A53C8 = { NULL, D_800A5074, 0x15, 4, 408, 414, 1 };
FieldActorEntry D_800A53DC = { D_800A52E4, D_800A508C, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A53F0 = { D_800A52EC, D_800A50A4, 0x18, 5, 352, 488, 7 };
FieldActorEntry D_800A5404 = { D_800A52F8, D_800A50BC, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A5418 = { D_800A5304, D_800A50D4, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A542C = { D_800A530C, D_800A50EC, 0x18, 5, 320, 515, 7 };
FieldActorEntry D_800A5440 = { D_800A5314, D_800A5104, 0x20, 6, 481, 225, 5 };
FieldActorEntry D_800A5454 = { D_800A5320, D_800A511C, 0x24, 7, 500, 294, 1 };
FieldActorEntry D_800A5468 = { D_800A5328, D_800A5134, 0x25, 8, 171, 403, 5 };
FieldActorEntry D_800A547C = { D_800A5330, D_800A514C, 0x26, 9, 257, 272, 7 };
FieldActorEntry D_800A5490 = { D_800A5338, D_800A5164, 0x2E, 0xA, 257, 513, 7 };
FieldActorEntry D_800A54A4 = { D_800A5344, D_800A517C, 0x2E, 0xA, 171, 403, 5 };
FieldActorEntry D_800A54B8 = { D_800A534C, D_800A5194, 0x31, 0xB, 500, 294, 1 };
FieldActorEntry D_800A54CC = { D_800A5354, D_800A51AC, 0x33, 0xC, 401, 233, 7 };
FieldActorEntry D_800A54E0 = { D_800A535C, D_800A51C4, 0x37, 0xD, 481, 225, 5 };
FieldActorEntry D_800A54F4 = { D_800A5364, D_800A51DC, 0x66, 0xE, 320, 515, 5 };
FieldActorEntry D_800A5508 = { D_800A5370, D_800A51F4, 0x73, 0xF, 171, 403, 5 };
FieldActorEntry D_800A551C = { D_800A5378, D_800A520C, 0x74, 0x10, 500, 294, 1 };
FieldActorEntry D_800A5530 = { D_800A5380, D_800A5224, 0x9D, 0x11, 513, 241, 1 };
FieldActorEntry D_800A5544 = { D_800A538C, D_800A523C, 0x9D, 0x11, 171, 403, 5 };
FieldActorEntry D_800A5558 = { D_800A5394, D_800A5254, 0x9E, 0x12, 481, 225, 5 };
FieldActorEntry D_800A556C = { D_800A53A0, D_800A526C, 0x9E, 0x12, 257, 272, 7 };
FieldActorEntry D_800A5580 = { D_800A53A8, D_800A5284, 0x9F, 0x13, 257, 513, 7 };
FieldActorEntry D_800A5594 = { D_800A53B0, D_800A529C, 0xA0, 0x14, 481, 225, 5 };
FieldActorEntry D_800A55A8 = { D_800A53B8, D_800A52B4, 0xA1, 0x15, 401, 233, 7 };
FieldActorEntry D_800A55BC = { D_800A53C0, D_800A52CC, 0xA2, 0x16, 500, 294, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A53C8,
    &D_800A53DC,
    &D_800A53F0,
    &D_800A5404,
    &D_800A5418,
    &D_800A542C,
    &D_800A5440,
    &D_800A5454,
    &D_800A5468,
    &D_800A547C,
    &D_800A5490,
    &D_800A54A4,
    &D_800A54B8,
    &D_800A54CC,
    &D_800A54E0,
    &D_800A54F4,
    &D_800A5508,
    &D_800A551C,
    &D_800A5530,
    &D_800A5544,
    &D_800A5558,
    &D_800A556C,
    &D_800A5580,
    &D_800A5594,
    &D_800A55A8,
    &D_800A55BC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 0xA, 0, 283, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 0xA, 0, 428, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 0xA, 0, 307, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 287, 459, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 1, 0xA, 0, 297, 464, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x2F8, 0x104, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x1E8, 0xA4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1211, D_800A4E38, EVENT_TEXT(0x11), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
