#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x533
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x543
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15B00, 0xD500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1F;
    D_800990B4.music = 0x607C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4EE8[];
extern u16 D_800A4EF0[];
extern u16 D_800A4EF8[];
extern u16 D_800A4F00[];
extern u16 D_800A4F08[];
extern u16 D_800A4F10[];
extern FieldActorEntry D_800A4F18;
extern FieldActorEntry D_800A4F2C;
extern FieldActorEntry D_800A4F40;
extern FieldActorEntry D_800A4F54;
extern FieldActorEntry D_800A4F68;
extern FieldActorEntry D_800A4F7C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x148, 0x100, 0x20, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x150, 0x100, 0x40, 0, 0x170, 0x1FD },
    { 0x140, 0x100, 0x158, 0x100, 0x60, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x140, 0x1FB },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FB },
};
u16 D_800A4EE8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4EF0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4EF8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4F00[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4F08[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4F10[] = { 0x6026, 1, 0xFFFF };
FieldActorEntry D_800A4F18 = { D_800A4EE8, NULL, 0x45, 4, 210, 74, 5 };
FieldActorEntry D_800A4F2C = { D_800A4EF0, NULL, 0x46, 5, 178, 74, 7 };
FieldActorEntry D_800A4F40 = { D_800A4EF8, NULL, 0x9D, 6, 146, 97, 7 };
FieldActorEntry D_800A4F54 = { D_800A4F00, NULL, 0x9E, 7, 210, 74, 5 };
FieldActorEntry D_800A4F68 = { D_800A4F08, NULL, 0x9F, 8, 178, 74, 7 };
FieldActorEntry D_800A4F7C = { D_800A4F10, NULL, 0x102, 9, 146, 97, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A4F18,
    &D_800A4F2C,
    &D_800A4F40,
    &D_800A4F54,
    &D_800A4F68,
    &D_800A4F7C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 320, 53, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 384, 85, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 424, 104, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 455, 145, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 480, 180, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 528, 205, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 3, 4, 0, 104, 68, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 3, 4, 0, 140, 69, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 104, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 198, 84, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 4, 0, 382, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 403, 168, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x274, 0x70, 0xE4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
