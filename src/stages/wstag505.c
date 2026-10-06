#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x22D
#define STAGE_ARCHIVE 0x3CB
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x23C
#define STAGE_ARCHIVE 0x3DB
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x28500, 0x1A200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F4C[];
extern u16 D_800A4F54[];
extern FieldTalk D_800A4F5C[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A50AC[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A50B4[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A50BC[];
extern FieldTalk D_800A4FBC[];
extern u16 D_800A50C4[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A50CC[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A50D4[];
extern FieldTalk D_800A5004[];
extern u16 D_800A50DC[];
extern FieldTalk D_800A501C[];
extern u16 D_800A50E4[];
extern FieldTalk D_800A5034[];
extern u16 D_800A50EC[];
extern FieldTalk D_800A504C[];
extern u16 D_800A50F4[];
extern FieldTalk D_800A5064[];
extern u16 D_800A50FC[];
extern FieldTalk D_800A507C[];
extern u16 D_800A5104[];
extern FieldTalk D_800A5094[];
extern FieldActorEntry D_800A510C;
extern FieldActorEntry D_800A5120;
extern FieldActorEntry D_800A5134;
extern FieldActorEntry D_800A5148;
extern FieldActorEntry D_800A515C;
extern FieldActorEntry D_800A5170;
extern FieldActorEntry D_800A5184;
extern FieldActorEntry D_800A5198;
extern FieldActorEntry D_800A51AC;
extern FieldActorEntry D_800A51C0;
extern FieldActorEntry D_800A51D4;
extern FieldActorEntry D_800A51E8;
extern FieldActorEntry D_800A51FC;
extern FieldActorEntry D_800A5210;
extern s16 D_800A4E38[];

s16 D_800A4E38[] = {
    0x102, 2, 0x2D0, 0x1A0, 5,
    0x100, 0x15, 0x2F0, 0x191,
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
    0x304, 0xC04, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x125, 0xD8, 0x25, 0x140, 0x1FF },
    { 0x140, 0x100, 0x156, 0x143, 0x58, 0x43, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x16F, 0, 0x6F, 0x160, 0x1FF },
    { 0x140, 0x100, 0x148, 0x16F, 0x20, 0x6F, 0x170, 0x1FF },
};
u16 D_800A4F4C[] = { 0x7A22, 1, 0xFFFF };
u16 D_800A4F54[] = { 0x900F, 1, 0xFFFF };
FieldTalk D_800A4F5C[] = {
    { NULL, D_800A4F4C, 5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, D_800A4F54, 2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x8F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { NULL, NULL, 0x86 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FBC[] = {
    { NULL, NULL, 0x87 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x88 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0x8B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0x8B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0x8C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, NULL, 0x8D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, NULL, 0x6F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0x8E },
    { NULL, NULL, 0 },
};
u16 D_800A50AC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A50B4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A50BC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A50C4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A50CC[] = { 0x7017, 1, 0xFFFF };
u16 D_800A50D4[] = { 0x6018, 1, 0xFFFF };
u16 D_800A50DC[] = { 0x6019, 1, 0xFFFF };
u16 D_800A50E4[] = { 0x601A, 1, 0xFFFF };
u16 D_800A50EC[] = { 0x7019, 1, 0xFFFF };
u16 D_800A50F4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A50FC[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5104[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A510C = { NULL, D_800A4F5C, 0x14, 4, 673, 370, 1 };
FieldActorEntry D_800A5120 = { NULL, D_800A4F74, 0x15, 5, 752, 401, 1 };
FieldActorEntry D_800A5134 = { D_800A50AC, D_800A4F8C, 0x36, 6, 273, 217, 1 };
FieldActorEntry D_800A5148 = { D_800A50B4, D_800A4FA4, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A515C = { D_800A50BC, D_800A4FBC, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A5170 = { D_800A50C4, D_800A4FD4, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A5184 = { D_800A50CC, D_800A4FEC, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A5198 = { D_800A50D4, D_800A5004, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A51AC = { D_800A50DC, D_800A501C, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A51C0 = { D_800A50E4, D_800A5034, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A51D4 = { D_800A50EC, D_800A504C, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A51E8 = { D_800A50F4, D_800A5064, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A51FC = { D_800A50FC, D_800A507C, 0x36, 6, 550, 222, 5 };
FieldActorEntry D_800A5210 = { D_800A5104, D_800A5094, 0x9D, 7, 550, 222, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A510C,
    &D_800A5120,
    &D_800A5134,
    &D_800A5148,
    &D_800A515C,
    &D_800A5170,
    &D_800A5184,
    &D_800A5198,
    &D_800A51AC,
    &D_800A51C0,
    &D_800A51D4,
    &D_800A51E8,
    &D_800A51FC,
    &D_800A5210,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x50, 4, 0, 0, 0, 0, 0, 0, 510, 318, 407, 0 },
    { 1, 0, 0x80, 4, 1, 0, 0, 0, 0, 0, 671, 351, 374, 0 },
    { 1, 0, 0x80, 4, 2, 0, 0, 0, 0, 0, 676, 315, 367, 0 },
    { 1, 0, 0xE0, 4, 3, 0, 0, 0, 0, 0, 608, 315, 374, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 175, 201, 239, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 207, 185, 224, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 237, 176, 208, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 632, 227, 236, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 615, 191, 229, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 575, 174, 212, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23E, 0xE8, 0x17C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1220, D_800A4E38, EVENT_TEXT(8), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
