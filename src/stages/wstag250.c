#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x19B
#define STAGE_ARCHIVE 0x3BF
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x1A9
#define STAGE_ARCHIVE 0x3CF
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x13D00, 0x16F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4EEC[];
extern u16 D_800A4EF4[];
extern u16 D_800A4EFC[];
extern u16 D_800A4F04[];
extern u16 D_800A4F0C[];
extern u16 D_800A4F14[];
extern u16 D_800A4F1C[];
extern u16 D_800A4F24[];
extern FieldTalk D_800A4F2C[];
extern FieldTalk D_800A4F50[];
extern u16 D_800A5184[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A518C[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A5194[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A519C[];
extern FieldTalk D_800A4FBC[];
extern u16 D_800A51A4[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A51AC[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A51B4[];
extern FieldTalk D_800A5004[];
extern u16 D_800A51BC[];
extern FieldTalk D_800A501C[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A5034[];
extern u16 D_800A51CC[];
extern FieldTalk D_800A504C[];
extern u16 D_800A51D4[];
extern FieldTalk D_800A5064[];
extern u16 D_800A51DC[];
extern FieldTalk D_800A507C[];
extern u16 D_800A51E4[];
extern FieldTalk D_800A5094[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A51F4[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A51FC[];
extern FieldTalk D_800A50DC[];
extern u16 D_800A5204[];
extern FieldTalk D_800A50F4[];
extern u16 D_800A520C[];
extern FieldTalk D_800A510C[];
extern u16 D_800A5214[];
extern FieldTalk D_800A5124[];
extern u16 D_800A521C[];
extern FieldTalk D_800A513C[];
extern u16 D_800A5224[];
extern FieldTalk D_800A5154[];
extern u16 D_800A522C[];
extern FieldTalk D_800A516C[];
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
extern FieldActorEntry D_800A5360;
extern FieldActorEntry D_800A5374;
extern FieldActorEntry D_800A5388;
extern FieldActorEntry D_800A539C;
extern FieldActorEntry D_800A53B0;
extern FieldActorEntry D_800A53C4;
extern FieldActorEntry D_800A53D8;
extern FieldActorEntry D_800A53EC;
extern FieldActorEntry D_800A5400;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x128, 0xD0, 0x28, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x150, 0x1FE },
    { 0x140, 0x100, 0x174, 0x170, 0xD0, 0x70, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1B6, 0x158, 0x1D8, 0x58, 0x170, 0x1FE },
    { 0x180, 0x100, 0x180, 0x190, 0x100, 0x90, 0x140, 0x1FD },
};
u16 D_800A4EEC[] = { 0x1A13, 0, 0xFFFF };
u16 D_800A4EF4[] = { 0x1A13, 1, 0xFFFF };
u16 D_800A4EFC[] = { 0x1A13, 1, 0xFFFF };
u16 D_800A4F04[] = { 0x7A04, 1, 0xFFFF };
u16 D_800A4F0C[] = { 0x1A12, 0, 0xFFFF };
u16 D_800A4F14[] = { 0x1A12, 1, 0xFFFF };
u16 D_800A4F1C[] = { 0x1A12, 1, 0xFFFF };
u16 D_800A4F24[] = { 0x7A03, 1, 0xFFFF };
FieldTalk D_800A4F2C[] = {
    { D_800A4EEC, D_800A4EF4, 0x4A },
    { D_800A4EFC, D_800A4F04, 0x28 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F50[] = {
    { D_800A4F0C, D_800A4F14, 0x4B },
    { D_800A4F1C, D_800A4F24, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x44A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { NULL, NULL, 0x442 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FBC[] = {
    { NULL, NULL, 0x444 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x446 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, NULL, 0x448 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0x441 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0x443 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0x445 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0x447 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, NULL, 0x2A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, NULL, 0x440 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0x438 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, NULL, 0x43A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0x43C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0x43E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F4[] = {
    { NULL, NULL, 0x437 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A510C[] = {
    { NULL, NULL, 0x439 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5124[] = {
    { NULL, NULL, 0x43B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A513C[] = {
    { NULL, NULL, 0x43D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5154[] = {
    { NULL, NULL, 0x43F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A516C[] = {
    { NULL, NULL, 0x449 },
    { NULL, NULL, 0 },
};
u16 D_800A5184[] = { 0x6005, 1, 0xFFFF };
u16 D_800A518C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5194[] = { 0x600C, 1, 0xFFFF };
u16 D_800A519C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A51A4[] = { 0x601A, 1, 0xFFFF };
u16 D_800A51AC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A51B4[] = { 0x6008, 1, 0xFFFF };
u16 D_800A51BC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x6018, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A51DC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51E4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A51EC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x7018, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5204[] = { 0x7015, 1, 0xFFFF };
u16 D_800A520C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5214[] = { 0x6016, 1, 0xFFFF };
u16 D_800A521C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5224[] = { 0x701A, 1, 0xFFFF };
u16 D_800A522C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5234 = { NULL, D_800A4F2C, 0x16, 4, 451, 178, 7 };
FieldActorEntry D_800A5248 = { NULL, D_800A4F50, 0x17, 5, 382, 331, 1 };
FieldActorEntry D_800A525C = { D_800A5184, D_800A4F74, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A5270 = { D_800A518C, D_800A4F8C, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A5284 = { D_800A5194, D_800A4FA4, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A5298 = { D_800A519C, D_800A4FBC, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A52AC = { D_800A51A4, D_800A4FD4, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A52C0 = { D_800A51AC, D_800A4FEC, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A52D4 = { D_800A51B4, D_800A5004, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A52E8 = { D_800A51BC, D_800A501C, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A52FC = { D_800A51C4, D_800A5034, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A5310 = { D_800A51CC, D_800A504C, 0x35, 6, 533, 171, 5 };
FieldActorEntry D_800A5324 = { D_800A51D4, D_800A5064, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A5338 = { D_800A51DC, D_800A507C, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A534C = { D_800A51E4, D_800A5094, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A5360 = { D_800A51EC, D_800A50AC, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A5374 = { D_800A51F4, D_800A50C4, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A5388 = { D_800A51FC, D_800A50DC, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A539C = { D_800A5204, D_800A50F4, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A53B0 = { D_800A520C, D_800A510C, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A53C4 = { D_800A5214, D_800A5124, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A53D8 = { D_800A521C, D_800A513C, 0x36, 7, 195, 402, 1 };
FieldActorEntry D_800A53EC = { D_800A5224, D_800A5154, 0x9D, 8, 195, 402, 1 };
FieldActorEntry D_800A5400 = { D_800A522C, D_800A516C, 0x9E, 9, 533, 171, 5 };
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
    &D_800A5360,
    &D_800A5374,
    &D_800A5388,
    &D_800A539C,
    &D_800A53B0,
    &D_800A53C4,
    &D_800A53D8,
    &D_800A53EC,
    &D_800A5400,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x3D, 4, 0, 224, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x53, 0xA, 0, 95, 248, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x53, 0xA, 0, 181, 470, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 1, 0x57, 0x59, 0xA, 0, 123, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 148, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 153, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 114, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 155, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 168, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 105, 333, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 126, 300, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 0xA, 0, 219, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 59, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 62, 328, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 63, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 95, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 126, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0x4D, 1, 0x4D, 0x50, 8, 0, 73, 439, 0, 0 },
    { 1, 0, 0x40, 6, 0, 1, 0, 5, 4, 0, 299, 241, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20D, 0x150, 0x98, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20D, 0x60, 0x150, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
