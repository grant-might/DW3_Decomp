#include "common.h"
#include "stage.h"
void func_800A5F70();

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1A0;
    D_800990B4.sheetEntry = 0x8EB0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8EA;
    D_800990B4.start = (Vec2){0xDE00, 0xDE00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8EB0001);
    D_8009A70C.setFile(7, 0x8EB0002);
    D_8009A70C.unk50(0);
}

/* Shows the record with animation 1 and moves it and the player down a pixel a frame for 150 frames */
void func_800A5F70(StageTileTimer *task) {
    StageTile *rec;
    StageTile *tile;
    StageActor *player;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->tile = rec;
                rec->y--;
                rec->visible = 1;
            }
        }
        task->timer = 0;
        break;
    case TASK_RUN:
        tile = task->tile;
        player = TASK_REGISTRY.funcs.find(5, -1, 0);
        tile->y++;
        task->timer++;
        player->y += 0x100;
        if (task->timer >= 0x96) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A609C(s32 arg) {
    return createTaskWithId(func_800A5F70, 0x58, 0, arg);
}

extern u16 D_800A615C[];
extern u16 D_800A6164[];
extern u16 D_800A6170[];
extern u16 D_800A6178[];
extern FieldTalk D_800A6184[];
extern FieldTalk D_800A61B4[];
extern FieldActorEntry D_800A61CC;
extern FieldActorEntry D_800A61E0;
extern FieldActorEntry D_800A61F4;
extern s16 D_800A6424[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x161, 0x70, 0x61, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x161, 0xB0, 0x61, 0x170, 0x1FE },
};
u16 D_800A615C[] = { 0x7054, 0, 0xFFFF };
u16 D_800A6164[] = { 0x7054, 1, 0x100C, 0, 0xFFFF };
u16 D_800A6170[] = { 0x906F, 1, 0xFFFF };
u16 D_800A6178[] = { 0x7054, 1, 0x100C, 1, 0xFFFF };
FieldTalk D_800A6184[] = {
    { D_800A615C, NULL, 0x27 },
    { D_800A6164, D_800A6170, 0x28 },
    { D_800A6178, NULL, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61B4[] = {
    { NULL, NULL, 0x2A },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A61CC = { NULL, D_800A6184, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A61E0 = { NULL, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A61F4 = { NULL, D_800A61B4, 0x175, 6, 203, 218, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A61CC,
    &D_800A61E0,
    &D_800A61F4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 192, 256, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 144, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 168, 92, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 224, 64, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 127, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 127, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 159, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 159, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 191, 80, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 191, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 223, 64, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 223, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 0xB, 8, 0, 196, 289, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 0xB, 8, 0, 226, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 0xB, 8, 0, 212, 266, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 0xB, 8, 0, 212, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 0xB, 8, 0, 196, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 0xB, 8, 0, 226, 260, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x39, 0xA, 0, 200, 290, 0, 0 },
    { 1, 1, 0x40, 6, 2, 0, 0, 0, 0, 0, 256, 336, 0, 0 },
    { 1, 0, 0x40, 4, 0x3A, 1, 0x3A, 0x3C, 0xA, 0, 256, 286, 315, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 304, 312, 329, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 256, 280, 315, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x200, 0x11C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1606, D_800A6424, EVENT_TEXT(3), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A6424[] = {
    0x102, 2, 0x12F, 0x168, 3,
    0x101, 0x20, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x20, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x20, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 2,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x3C,
    0x101, 0x356, 0x349, 2,
    0x300, 0x30,
    0x304, 0x278, 0xC0, 0x158, 5,
    0,
};
