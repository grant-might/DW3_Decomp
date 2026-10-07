#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0xFD;
    FIELDSTG_state.mapFile = 0x1A0;
    FIELDSTG_state.sheetEntry = 0x8EB0000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x8EA;
    FIELDSTG_state.start = (Vec2){0xDE00, 0xDE00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 5;
    FIELDSTG_state.music = MUSIC(5, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, 0x8EB0001);
    FIELDSTG_map.setFile(7, 0x8EB0002);
    FIELDSTG_map.setFirstMap(0);
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
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
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

extern s16 script1606[];

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
u16 actor0Talk0Conditions[] = { SPECIAL(0x54), 0, CODES_END };
u16 actor0Talk1Conditions[] = { SPECIAL(0x54), 1, FLAG(0x10, 0xC), 0, CODES_END };
u16 actor0Talk1Actions[] = { START_EVENT(0x6F), 1, CODES_END };
u16 actor0Talk2Conditions[] = { SPECIAL(0x54), 1, FLAG(0x10, 0xC), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, NULL, 0x27 },
    { actor0Talk1Conditions, actor0Talk1Actions, 0x28 },
    { actor0Talk2Conditions, NULL, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x2A },
    { NULL, NULL, 0 },
};
FieldActorEntry actor0 = { NULL, actor0Talks, 0x20, 4, 272, 344, 7 };
FieldActorEntry actor1 = { NULL, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry actor2 = { NULL, actor2Talks, 0x175, 6, 203, 218, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
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
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x273, 0x200, 0x11C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1606, script1606, EVENT_TEXT(3), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s16 script1606[] = {
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
