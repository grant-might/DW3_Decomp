#include "common.h"
#include "stage.h"
void func_800A4FFC();
void *func_800A4FCC(s32 arg);

/*
 * Once the substate is set to 1, moves the records of animations 2, 3, 4 and
 * 7 and shows those of 5 to 9 in turn
 */
void func_800A4CB8(StageTileGroup *task) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 8; i++) {
            task->tiles[i] = FIELDSTG_findObject(i + 2);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            break;
        case 1:
            switch (task->step) {
            case 0:
                SOUND.playSound(0x8100383C);
                task->nextStep(task);
            case 1:
                if (task->counter & 1) {
                    task->tiles[0]->y++;
                    task->tiles[1]->y++;
                    task->tiles[2]->y++;
                    task->tiles[5]->y++;
                }
                if (++task->counter != 8) {
                    break;
                }
                task->nextStep(task);
            case 2:
                if (task->counter & 1) {
                    task->tiles[1]->y++;
                    task->tiles[5]->y++;
                }
                if (++task->counter != 0x10) {
                    break;
                }
                task->nextStep(task);
            case 3:
                if (task->counter == 0) {
                    task->tiles[3]->visible = 1;
                    SOUND.playSound(0x1000002);
                    task->tickCounter(task);
                }
                if (task->tiles[3]->clutRow == 0xF) {
                    task->nextStep(task);
                }
                break;
            case 4:
                if (task->counter == 0) {
                    task->tiles[3]->visible = 0;
                    task->tiles[4]->visible = 1;
                    task->tiles[5]->visible = 0;
                    task->tiles[6]->visible = 1;
                    task->tickCounter(task);
                }
                if (task->tiles[6]->clutRow == 0xF) {
                    task->tiles[6]->visible = 0;
                    task->tiles[7]->visible = 1;
                    task->nextStep(task);
                }
                break;
            }
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Starts the task (substate 1) when map object 0x32C is triggered */
void func_800A4F94(StageTask *task, s32 id) {
    if (task != NULL && id == 0x32C) {
        task->setSubstate(task, 1);
    }
}

/* Creates the task of func_800A4CB8 with id 0x329 */
void *func_800A4FCC(s32 arg) {
    return createTaskWithId(func_800A4CB8, 0x70, 0, 0x329);
}

/* Once the substate is set to 1, animates the frame of the record of animation 1 for 20 frames, then plays a sound */
void func_800A4FFC(StageFrameTask *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            break;
        case 1:
            switch (task->step) {
            case 0:
                task->frame = (task->counter >> 2) + 5;
                if (++task->counter >= 0x14) {
                    SOUND.playSound(0x8100303C);
                    task->nextStep(task);
                } else {
                    tile = FIELDSTG_findObject(1);
                    if (tile != NULL) {
                        tile->frame = task->frame;
                    }
                }
                break;
            }
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Starts the task (substate 1) when map object 0x32E is triggered */
void func_800A50E8(StageTask *task, s32 id) {
    if (task != NULL && id == 0x32E) {
        task->setSubstate(task, 1);
    }
}

void *func_800A5120(s32 arg) {
    return createTaskWithId(func_800A4FFC, 0x5C, 0, arg);
}

/* Creates two objects and the event object of story progress 1 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[2] = func_800A4FCC(0x329);
        children[1] = func_800A5120(0x328);
        if (GAME.progress == 1) {
            children[0] = FIELDSTG_startEvent(4);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x1BB
#define STAGE_ARCHIVE 0x322
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x1C9
#define STAGE_ARCHIVE 0x331
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x15900, 0x11700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x40;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.music = 0x61000001;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5670[];
extern u16 D_800A5678[];
extern FieldActorEntry D_800A5680;
extern FieldActorEntry D_800A5694;
extern FieldActorEntry D_800A56A8;
extern FieldActorEntry D_800A56BC;
extern s16 D_800A5310[];

s16 D_800A5310[] = {
    0x601, 1, 0x157, 0x121,
    0x100, 1, 0, 0,
    0x101, 1, 1, 1,
    0x100, 0xB, 0, 0,
    0x101, 0xB, 1, 1,
    0x100, 0xC, 0, 0,
    0x101, 0xC, 1, 1,
    0x100, 0xD, 0x18A, 0xF6,
    0x101, 0xD, 1, 3,
    0x101, 0x328, 0x32D, 0x328,
    0x101, 0x329, 0x32D, 0x328,
    0x300, 0x3C,
    0x100, 1, 0xE5, 0x159,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0x157, 0x121, 0,
    0x302, 1,
    0x600, 1, 1,
    0x101, 1, 0x3A, 1,
    0x300, 0x78,
    0x200, 0, 1, 1, 3,
    0x101, 1, 7, 0,
    0x301,
    0x101, 1, 1, 0,
    0x300, 0x1E,
    0x102, 1, 0x19B, 0xFF, 5,
    0x302, 1,
    0x101, 1, 1, 3,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0xD, 0,
    0x101, 0xD, 7, 7,
    0x301,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x200, 0, 3, 1, 1,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x101, 1, 1, 7,
    0x101, 0xD, 2, 3,
    0x300, 0x3C,
    0x101, 1, 0x29, 7,
    0x300, 0x5A,
    0x101, 1, 0x2A, 7,
    0x101, 0xD, 1, 3,
    0x101, 0x323, 0x325, 0xD,
    0x300, 0x3C,
    0x101, 1, 1, 7,
    0x101, 0xD, 1, 7,
    0x101, 0x323, 0x326, 0xD,
    0x300, 0x1E,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0xD, 0,
    0x101, 0xD, 7, 7,
    0x101, 0x329, 0x32B, 1,
    0x301,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x200, 0, 5, 1, 1,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x601, 1, 0x19B, 0xFF,
    0x102, 1, 0x1D5, 0xE1, 5,
    0x101, 0xD, 1, 3,
    0x302, 1,
    0x100, 1, 0, 0,
    0x101, 1, 1, 0,
    0x101, 0xD, 2, 3,
    0x300, 0x3C,
    0x100, 0xB, 0xEB, 0x151,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x102, 0xB, 0xFE, 0x148, 5,
    0x100, 0xC, 0xEB, 0x151,
    0x101, 0xC, 1, 5,
    0x302, 0xB,
    0x102, 0xB, 0x171, 0x10F, 5,
    0x102, 0xC, 0x15A, 0x11B, 5,
    0x302, 0xC,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0x328, 0x32E, 1,
    0x300, 0x3C,
    0x101, 0xB, 0x33, 5,
    0x300, 0x3C,
    0x200, 0, 7, 0xB, 2,
    0x101, 0xB, 0xC, 5,
    0x301,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x200, 0, 8, 0xC, 2,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x101, 0x329, 0x32C, 1,
    0x300, 0x12C,
#if VERSION_US
    0x304, 0xE02, 0x170, 0x11F, 1,
#elif VERSION_EU
    0x304, 0xE03, 0x170, 0x11F, 1,
#endif
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x1D0, 0x98, 0xD0, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1B6, 0x130, 0x1D8, 0x30, 0x170, 0x1FA },
    { 0x180, 0x100, 0x1B4, 0x1A3, 0x1D0, 0xA3, 0x170, 0x1F9 },
    { 0x180, 0x100, 0x1A6, 0x130, 0x198, 0x30, 0x170, 0x1F8 },
};
u16 D_800A5670[] = { 0x6001, 1, 0xFFFF };
u16 D_800A5678[] = { 0x6001, 1, 0xFFFF };
FieldActorEntry D_800A5680 = { NULL, NULL, 1, 4, 0, 0, 0 };
FieldActorEntry D_800A5694 = { D_800A5670, NULL, 0xB, 5, 0, 0, 0 };
FieldActorEntry D_800A56A8 = { NULL, NULL, 0xC, 6, 0, 0, 0 };
FieldActorEntry D_800A56BC = { D_800A5678, NULL, 0xD, 7, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A5680,
    &D_800A5694,
    &D_800A56A8,
    &D_800A56BC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 4, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 479, 117, 0, 0 },
    { 1, 7, 0x40, 2, 0x39, 0, 0, 0, 0, 0, 407, 126, 0, 0 },
    { 0, 8, 0x40, 2, 0x34, 2, 0, 0xF, 5, 0, 407, 138, 0, 0 },
    { 0, 9, 0x40, 2, 0x38, 2, 0xE, 0xF, 4, 0xE, 407, 138, 0, 0 },
    { 1, 3, 0x90, 2, 0xB, 0, 0, 0, 0, 0, 415, 79, 0, 0 },
    { 1, 2, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 387, 76, 0, 0 },
    { 0, 5, 0x40, 2, 0x33, 2, 0, 0xF, 4, 0, 428, 172, 0, 0 },
    { 0, 6, 0x40, 2, 0x37, 2, 0xE, 0xF, 4, 0xE, 428, 172, 0, 0 },
    { 1, 1, 0x40, 2, 4, 0, 0, 0, 0, 0, 418, 191, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 2, 0, 254, 146, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 2, 0, 442, 241, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 2, 0, 538, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 0, 0, 7, 0xA, 0, 361, 205, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x35, 0, 0, 0, 0, 0, 150, 0, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 398, 279, 296, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 430, 247, 264, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 397, 263, 281, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 429, 232, 247, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 4, D_800A5310, EVENT_TEXT(3), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
