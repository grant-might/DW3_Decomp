#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x656
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x666
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1FA00, 0x2DE00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x17;
    D_800990B4.music = 0x605C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A5014[];
extern u16 D_800A501C[];
extern u16 D_800A5024[];
extern u16 D_800A502C[];
extern u16 D_800A5034[];
extern u16 D_800A503C[];
extern u16 D_800A5044[];
extern FieldTalk D_800A504C[];
extern FieldTalk D_800A5064[];
extern FieldTalk D_800A507C[];
extern FieldTalk D_800A5094[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A51C0[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A50DC[];
extern u16 D_800A51D4[];
extern FieldTalk D_800A50F4[];
extern u16 D_800A51E0[];
extern FieldTalk D_800A510C[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A5124[];
extern u16 D_800A51F4[];
extern FieldTalk D_800A513C[];
extern u16 D_800A5200[];
extern FieldTalk D_800A5154[];
extern u16 D_800A5208[];
extern FieldTalk D_800A516C[];
extern u16 D_800A5210[];
extern FieldTalk D_800A5190[];
extern u16 D_800A5218[];
extern FieldTalk D_800A51A8[];
extern FieldActorEntry D_800A5220;
extern FieldActorEntry D_800A5234;
extern FieldActorEntry D_800A5248;
extern FieldActorEntry D_800A525C;
extern FieldActorEntry D_800A5270;
extern FieldActorEntry D_800A5284;
extern FieldActorEntry D_800A5298;
extern FieldActorEntry D_800A52AC;
extern FieldActorEntry D_800A52C0;
extern FieldActorEntry D_800A52D4;
extern FieldActorEntry D_800A52E8;
extern FieldActorEntry D_800A52FC;
extern FieldActorEntry D_800A5310;
extern FieldActorEntry D_800A5324;
extern FieldActorEntry D_800A5338;
extern s16 D_800A4EA0[];

s16 D_800A4EA0[] = {
    0x102, 2, 0x43E, 0x204, 5,
    0x100, 0x15, 0x45F, 0x1F6,
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
    0x304, 0xC0F, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x2\n");
#endif
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F6, 0x160, 0x2D8, 0x60, 0x150, 0x1FB },
    { 0x180, 0x100, 0x194, 0x1A8, 0x150, 0xA8, 0x160, 0x1FB },
    { 0x1C0, 0x100, 0x1F4, 0x100, 0x2D0, 0, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A8, 0x1D8, 0x1A0, 0xD8, 0x150, 0x1FA },
    { 0x1C0, 0x100, 0x1CC, 0x100, 0x230, 0, 0x160, 0x1FA },
    { 0x1C0, 0x100, 0x1C0, 0x178, 0x200, 0x78, 0x170, 0x1FA },
    { 0x1C0, 0x100, 0x1C8, 0x178, 0x220, 0x78, 0x140, 0x1F9 },
    { 0x1C0, 0x100, 0x1D0, 0x178, 0x240, 0x78, 0x150, 0x1F9 },
    { 0x1C0, 0x100, 0x1D8, 0x180, 0x260, 0x80, 0x160, 0x1F9 },
    { 0x1C0, 0x100, 0x1EC, 0x180, 0x2B0, 0x80, 0x170, 0x1F9 },
};
u16 D_800A5014[] = { 0x7A2E, 1, 0xFFFF };
u16 D_800A501C[] = { 0x9013, 1, 0xFFFF };
u16 D_800A5024[] = { 0x7A1B, 1, 0xFFFF };
u16 D_800A502C[] = { 0x7A1A, 1, 0xFFFF };
u16 D_800A5034[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A503C[] = { 0x701F, 1, 0xFFFF };
u16 D_800A5044[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A504C[] = {
    { NULL, D_800A5014, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, D_800A501C, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, D_800A5024, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, D_800A502C, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, D_800A5034, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0x176 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0x178 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F4[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A510C[] = {
    { NULL, NULL, 0x175 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5124[] = {
    { NULL, NULL, 0x175 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A513C[] = {
    { NULL, NULL, 0x177 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5154[] = {
    { NULL, NULL, 0x177 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A516C[] = {
    { D_800A503C, NULL, 0x1D7 },
    { D_800A5044, NULL, 0x1D8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5190[] = {
    { NULL, NULL, 0x1D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A8[] = {
    { NULL, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
u16 D_800A51C0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x7021, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51EC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x7021, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5200[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5208[] = { 0x7021, 1, 0xFFFF };
u16 D_800A5210[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5218[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5220 = { NULL, D_800A504C, 0x14, 4, 908, 596, 7 };
FieldActorEntry D_800A5234 = { NULL, D_800A5064, 0x15, 5, 1119, 502, 1 };
FieldActorEntry D_800A5248 = { NULL, D_800A507C, 0x16, 6, 834, 470, 7 };
FieldActorEntry D_800A525C = { NULL, D_800A5094, 0x17, 7, 690, 493, 1 };
FieldActorEntry D_800A5270 = { NULL, D_800A50AC, 0x18, 8, 1329, 411, 1 };
FieldActorEntry D_800A5284 = { D_800A51C0, D_800A50C4, 0x2E, 9, 961, 368, 1 };
FieldActorEntry D_800A5298 = { D_800A51CC, D_800A50DC, 0x2E, 9, 767, 529, 3 };
FieldActorEntry D_800A52AC = { D_800A51D4, D_800A50F4, 0x39, 0xA, 993, 531, 7 };
FieldActorEntry D_800A52C0 = { D_800A51E0, D_800A510C, 0x9D, 0xB, 993, 531, 7 };
FieldActorEntry D_800A52D4 = { D_800A51EC, D_800A5124, 0x9D, 0xB, 993, 531, 7 };
FieldActorEntry D_800A52E8 = { D_800A51F4, D_800A513C, 0x9E, 0xC, 961, 368, 1 };
FieldActorEntry D_800A52FC = { D_800A5200, D_800A5154, 0x9E, 0xC, 961, 368, 1 };
FieldActorEntry D_800A5310 = { D_800A5208, D_800A516C, 0x175, 0xD, 897, 289, 1 };
FieldActorEntry D_800A5324 = { D_800A5210, D_800A5190, 0x175, 0xD, 897, 289, 1 };
FieldActorEntry D_800A5338 = { D_800A5218, D_800A51A8, 0x175, 0xD, 961, 368, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5220,
    &D_800A5234,
    &D_800A5248,
    &D_800A525C,
    &D_800A5270,
    &D_800A5284,
    &D_800A5298,
    &D_800A52AC,
    &D_800A52C0,
    &D_800A52D4,
    &D_800A52E8,
    &D_800A52FC,
    &D_800A5310,
    &D_800A5324,
    &D_800A5338,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 7, 0, 7, 0xC, 4, 0, 374, 313, 0, 0 },
    { 1, 0, 0x40, 2, 7, 0, 7, 0xC, 4, 0, 919, 586, 0, 0 },
    { 1, 0, 0xC8, 2, 0x5A, 1, 0x5A, 0x61, 0xA, 0, 1314, 270, 0, 0 },
    { 1, 0, 0x48, 2, 0, 0, 0, 0, 0, 0, 444, 419, 0, 0 },
    { 1, 0, 0x58, 2, 0xD, 0, 0, 0, 0, 0, 683, 345, 0, 0 },
    { 1, 0, 0x4C, 2, 0xE, 0, 0, 0, 0, 0, 947, 492, 0, 0 },
    { 1, 0, 0x60, 2, 0x10, 0, 0, 0, 0, 0, 640, 515, 0, 0 },
    { 1, 0, 0x74, 2, 0x11, 0, 0, 0, 0, 0, 624, 524, 0, 0 },
    { 1, 0, 0x44, 2, 0x12, 0, 0, 0, 0, 0, 304, 556, 0, 0 },
    { 1, 0, 0x62, 2, 0xF, 0, 0, 0, 0, 0, 932, 598, 0, 0 },
    { 1, 0, 0x41, 2, 3, 0, 0, 0, 0, 0, 960, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 1378, 348, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1391, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1250, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1263, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1217, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1417, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 6, 0, 1310, 259, 0, 0 },
    { 1, 0, 0xC8, 6, 0x57, 1, 0x57, 0x59, 6, 0, 1144, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 290, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 344, 408, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 851, 700, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 996, 725, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x51, 1, 0x51, 0x53, 6, 0, 799, 318, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x54, 1, 0x54, 0x56, 6, 0, 1052, 371, 0, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 944, 515, 569, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 582, 424, 454, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1056, 269, 327, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 369, 703, 751, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 449, 743, 791, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 914, 233, 303, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C7, 0x100, 0x220, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B2, 0x1F0, 0x68, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x170, 0x268, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x180, 0x2B0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1230, D_800A4EA0, EVENT_TEXT(6), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
