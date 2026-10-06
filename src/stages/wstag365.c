#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x22B
#define STAGE_ARCHIVE 0x3C7
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x23A
#define STAGE_ARCHIVE 0x3D7
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xB700, 0xD300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x31;
    D_800990B4.music = 0x60C40000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4EB4[];
extern u16 D_800A4EBC[];
extern u16 D_800A4EC8[];
extern u16 D_800A4FFC[];
extern FieldTalk D_800A4ED0[];
extern u16 D_800A5004[];
extern FieldTalk D_800A4EE8[];
extern u16 D_800A500C[];
extern FieldTalk D_800A4F00[];
extern u16 D_800A5014[];
extern FieldTalk D_800A4F18[];
extern u16 D_800A501C[];
extern FieldTalk D_800A4F30[];
extern u16 D_800A5024[];
extern FieldTalk D_800A4F48[];
extern u16 D_800A502C[];
extern FieldTalk D_800A4F60[];
extern u16 D_800A5034[];
extern FieldTalk D_800A4F78[];
extern u16 D_800A503C[];
extern FieldTalk D_800A4F90[];
extern u16 D_800A5044[];
extern FieldTalk D_800A4FA8[];
extern u16 D_800A504C[];
extern FieldTalk D_800A4FC0[];
extern u16 D_800A5058[];
extern FieldTalk D_800A4FE4[];
extern FieldActorEntry D_800A5060;
extern FieldActorEntry D_800A5074;
extern FieldActorEntry D_800A5088;
extern FieldActorEntry D_800A509C;
extern FieldActorEntry D_800A50B0;
extern FieldActorEntry D_800A50C4;
extern FieldActorEntry D_800A50D8;
extern FieldActorEntry D_800A50EC;
extern FieldActorEntry D_800A5100;
extern FieldActorEntry D_800A5114;
extern FieldActorEntry D_800A5128;
extern FieldActorEntry D_800A513C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x150, 0xD8, 0x50, 0x160, 0x1FF },
    { 0x140, 0x100, 0x15E, 0x138, 0x78, 0x38, 0x170, 0x1FF },
    { 0x140, 0x100, 0x166, 0x14C, 0x98, 0x4C, 0x160, 0x1FE },
};
u16 D_800A4EB4[] = { 0x818E, 0, 0xFFFF };
u16 D_800A4EBC[] = { 0x818E, 1, 0x7013, 1, 0xFFFF };
u16 D_800A4EC8[] = { 0x818E, 1, 0xFFFF };
FieldTalk D_800A4ED0[] = {
    { NULL, NULL, 0x1D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4EE8[] = {
    { NULL, NULL, 0x10E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F00[] = {
    { NULL, NULL, 0x107 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F18[] = {
    { NULL, NULL, 0x10F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F30[] = {
    { NULL, NULL, 0x10A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F48[] = {
    { NULL, NULL, 0x10C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F60[] = {
    { NULL, NULL, 0x106 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F78[] = {
    { NULL, NULL, 0x108 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F90[] = {
    { NULL, NULL, 0x109 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA8[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC0[] = {
    { D_800A4EB4, D_800A4EBC, 0x2E7 },
    { D_800A4EC8, NULL, 0x328 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FE4[] = {
    { NULL, NULL, 0x10D },
    { NULL, NULL, 0 },
};
u16 D_800A4FFC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5004[] = { 0x602B, 1, 0xFFFF };
u16 D_800A500C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5014[] = { 0x7016, 1, 0xFFFF };
u16 D_800A501C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5024[] = { 0x6026, 1, 0xFFFF };
u16 D_800A502C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5034[] = { 0x600E, 1, 0xFFFF };
u16 D_800A503C[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5044[] = { 0x7019, 1, 0xFFFF };
u16 D_800A504C[] = { 0x6006, 1, 0x1C47, 1, 0xFFFF };
u16 D_800A5058[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5060 = { D_800A4FFC, D_800A4ED0, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A5074 = { D_800A5004, D_800A4EE8, 0x2D, 4, 241, 201, 3 };
FieldActorEntry D_800A5088 = { D_800A500C, D_800A4F00, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A509C = { D_800A5014, D_800A4F18, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A50B0 = { D_800A501C, D_800A4F30, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A50C4 = { D_800A5024, D_800A4F48, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A50D8 = { D_800A502C, D_800A4F60, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A50EC = { D_800A5034, D_800A4F78, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A5100 = { D_800A503C, D_800A4F90, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A5114 = { D_800A5044, D_800A4FA8, 0x2D, 4, 241, 201, 5 };
FieldActorEntry D_800A5128 = { D_800A504C, D_800A4FC0, 0x40, 5, 192, 633, 1 };
FieldActorEntry D_800A513C = { D_800A5058, D_800A4FE4, 0x9D, 6, 241, 201, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5060,
    &D_800A5074,
    &D_800A5088,
    &D_800A509C,
    &D_800A50B0,
    &D_800A50C4,
    &D_800A50D8,
    &D_800A50EC,
    &D_800A5100,
    &D_800A5114,
    &D_800A5128,
    &D_800A513C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x34, 2, 0, 7, 4, 0, 97, 134, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 7, 4, 0, 137, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 321, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 577, 313, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 497, 272, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 4, 0, 167, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 7, 4, 0, 187, 293, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 7, 4, 0, 307, 233, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 276, 208, 242, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 51, 156, 208, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 425, 290, 314, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 421, 428, 438, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 423, 392, 429, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x223, 0x156, 0x1B0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
