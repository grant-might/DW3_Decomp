#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x1B3
#define STAGE_ARCHIVE 0x3D0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x1C1
#define STAGE_ARCHIVE 0x3E0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x15100, 0x18800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x30;
    D_800990B4.music = 0x60C00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5038[];
extern u16 D_800A5040[];
extern u16 D_800A5048[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A5054[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A506C[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A5090[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A50A8[];
extern u16 D_800A51D8[];
extern FieldTalk D_800A50C0[];
extern u16 D_800A51E0[];
extern FieldTalk D_800A50D8[];
extern u16 D_800A51E8[];
extern FieldTalk D_800A50F0[];
extern u16 D_800A51F0[];
extern FieldTalk D_800A5108[];
extern u16 D_800A51F8[];
extern FieldTalk D_800A5120[];
extern u16 D_800A5200[];
extern FieldTalk D_800A5138[];
extern u16 D_800A5208[];
extern FieldTalk D_800A5150[];
extern u16 D_800A5210[];
extern FieldTalk D_800A5168[];
extern u16 D_800A5218[];
extern FieldTalk D_800A5180[];
extern u16 D_800A5220[];
extern FieldTalk D_800A5198[];
extern u16 D_800A5228[];
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
extern FieldActorEntry D_800A534C;
extern s16 D_800A4E38[];

s16 D_800A4E38[] = {
    0x102, 2, 0x131, 0x1B0, 1,
    0x100, 0x3E, 0x100, 0x1C7,
    0x101, 0x3E, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x5A,
    0x200, 0, 3, 0x3E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x5A,
    0x200, 0, 5, 0x3E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0xCF, 0x181, 3,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0xC8, 0x184, 1,
    0x302, 2,
    0x102, 2, 0x98, 0x1BC, 1,
    0x302, 2,
    0x102, 2, 0x91, 0x1C0, 1,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0x51, 0x1A0, 3,
    0x302, 2,
    0x600, 1, 0x3E,
    0x101, 2, 1, 5,
    0x101, 0x3E, 2, 1,
    0x300, 0x1E,
    0x100, 0x185, 0x100, 0x1C8,
    0x101, 0x185, 0x56, 1,
    0x300, 0x3C,
    0x102, 2, 0x100, 0x149, 5,
    0x101, 0x185, 0x56, 1,
    0x303, 0x185,
    0x300, 0x1E,
    0x304, 0x22E, 0x350, 0x230, 7,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x100, 0xC8, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x17A, 0x100, 0xE8, 0, 0x170, 0x1FF },
};
u16 D_800A5038[] = { 0x1A01, 0, 0xFFFF };
u16 D_800A5040[] = { 0x1A01, 1, 0xFFFF };
u16 D_800A5048[] = { 0x9037, 1, 0x1A0A, 1, 0xFFFF };
FieldTalk D_800A5054[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A506C[] = {
    { D_800A5038, NULL, 0x6E },
    { D_800A5040, D_800A5048, 0x10F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5090[] = {
    { NULL, NULL, 0x111 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A8[] = {
    { NULL, NULL, 0x110 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C0[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D8[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F0[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5108[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5120[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5138[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5150[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5168[] = {
    { NULL, NULL, 0x16F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5180[] = {
    { NULL, NULL, 0x16F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5198[] = {
    { NULL, NULL, 0x16F },
    { NULL, NULL, 0 },
};
u16 D_800A51B0[] = { 0x6004, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51C4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x701A, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51D8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x7017, 1, 0xFFFF };
u16 D_800A51F0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A51F8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5200[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5208[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5210[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5218[] = { 0x703C, 1, 0xFFFF };
u16 D_800A5220[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5228[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
FieldActorEntry D_800A5234 = { D_800A51B0, D_800A5054, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A5248 = { D_800A51B8, D_800A506C, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A525C = { D_800A51C4, D_800A5090, 0x3E, 4, 255, 456, 1 };
FieldActorEntry D_800A5270 = { D_800A51CC, D_800A50A8, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A5284 = { D_800A51D8, D_800A50C0, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A5298 = { D_800A51E0, D_800A50D8, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A52AC = { D_800A51E8, D_800A50F0, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A52C0 = { D_800A51F0, D_800A5108, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A52D4 = { D_800A51F8, D_800A5120, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A52E8 = { D_800A5200, D_800A5138, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A52FC = { D_800A5208, D_800A5150, 0x3E, 4, 256, 455, 1 };
FieldActorEntry D_800A5310 = { D_800A5210, D_800A5168, 0x67, 5, 288, 408, 1 };
FieldActorEntry D_800A5324 = { D_800A5218, D_800A5180, 0x67, 5, 288, 408, 1 };
FieldActorEntry D_800A5338 = { D_800A5220, D_800A5198, 0x67, 5, 288, 408, 1 };
FieldActorEntry D_800A534C = { D_800A5228, NULL, 0x185, 6, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
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
    &D_800A534C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xD0, 2, 0x32, 0, 0, 0, 0, 0, 51, 95, 0, 0 },
    { 1, 0, 0xD0, 2, 0x32, 0, 0, 0, 0, 0, 300, 55, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22E, 0x350, 0x230, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 950, D_800A4E38, EVENT_TEXT(0x2D), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
