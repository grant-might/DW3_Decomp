#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5FD4[];
extern AnimFrame D_800A6010[];
extern AnimFrame D_800A6044[];
extern AnimFrame D_800A6060[];

/* The file of the marks, which the versions number differently */
#if VERSION_US
#define MARKS 0x1B9
#elif VERSION_EU
#define MARKS 0x1C7
#endif

#include "common/step_animation.inc.c"

/* Plays the animations of records 4/3 then 2 (with 1 looping); starts at 2 when done is set */
void func_800A4DC8(StageTileSet *task) {
    StageTile *rec;
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 1:
                task->tiles[3] = rec;
                break;
            case 2:
                task->tiles[2] = rec;
                break;
            case 3:
                task->tiles[1] = rec;
                break;
            case 4:
                task->tiles[0] = rec;
                break;
            }
        }
        task->anim2.index = 0;
        task->anim2.timer = D_800A6060[0].duration;
        if (task->done == 0) {
            task->anim.index = 0;
            task->anim.timer = D_800A5FD4[0].duration;
            task->nextState(task);
        } else {
            task->setState(task, TASK_DONE);
        }
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            tile = task->tiles[0];
            frame = stepAnimation(&task->anim, D_800A5FD4, 1, 0);
            if (frame == 0xFF) {
                task->setSubstate(task, 1);
                tile->visible = 0;
                task->anim.index = 0;
                task->anim.timer = D_800A6010[0].duration;
            } else {
                tile->clutRow = frame;
                tile->visible = 1;
            }
            break;
        case 1:
            tile = task->tiles[1];
            tile->clutRow = stepAnimation(&task->anim, D_800A6010, 0, 0);
            tile->visible = 1;
            break;
        case 2:
            break;
        }
        tile = task->tiles[3];
        tile->clutRow = stepAnimation(&task->anim2, D_800A6060, 0, 0);
        tile->visible = 1;
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->anim.index = 0;
            task->anim.timer = D_800A6044[0].duration;
            task->anim2.index = 0;
            task->anim2.timer = D_800A6060[0].duration;
            task->nextSubstate(task);
        }
        tile = task->tiles[2];
        tile->clutRow = stepAnimation(&task->anim, D_800A6044, 0, 0);
        tile->visible = 1;
        tile = task->tiles[3];
        tile->clutRow = stepAnimation(&task->anim2, D_800A6060, 0, 0);
        tile->visible = 1;
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates the task of func_800A4DC8 already done */
StageTileSet *func_800A5068(void) {
    StageTileSet *task = createTask(func_800A4DC8, sizeof(StageTileSet), 0);

    task->done = 1;
    return task;
}

void *func_800A509C(s32 arg) {
    return createTaskWithId(func_800A4DC8, 0x6C, 0, arg);
}

/* Draws frame FRAME of file MARKS over the character */
void func_800A50CC(StageActorMark *task, s32 frame) {
    SpriteDrawer drawer;
    s32 pos[2];

    pos[0] = task->actor->x >> 8;
    pos[1] = (task->actor->y >> 8) - 0x18;
    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1002, 2);
    drawer.setTexture(0x140, 0x100);
    drawer.draw(FILE_CACHE.getEntry(MARKS << 16 | 1), frame, pos[0], pos[1]);
}

/* Shows the mark over the character: opens (0x32-0x34), stays by kind, closes (0x36-0x37) */
void func_800A5178(StageActorMark *task) {
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            frame = 0x32;
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 4) {
                break;
            }
            task->nextSubstate(task);
        case 1:
            frame = 0x33;
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 4) {
                break;
            }
            task->nextSubstate(task);
        case 2:
            frame = 0x34;
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 4) {
                break;
            }
            task->nextSubstate(task);
        case 3:
            switch (task->kind) {
            case 0:
            default:
                frame = 0x35;
                break;
            case 1:
                frame = ((task->step >> 3) & 1) + 0x38;
                task->step += GFX.funcs.getFrameTime();
                break;
            case 2:
                frame = 0x3C;
                break;
            case 3:
                frame = 0x3D;
                break;
            }
            break;
        }
        func_800A50CC(task, frame);
        break;
    case TASK_DONE:
        switch (task->substate) {
        case 0:
        default:
            frame = 0x36;
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 4) {
                break;
            }
            task->nextSubstate(task);
        case 1:
            frame = 0x37;
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 4) {
                break;
            }
            task->nextState(task);
            break;
        }
        func_800A50CC(task, frame);
        break;
    case TASK_KILL:
        break;
    }
}

void *func_800A53D4(s32 arg) {
    return createTaskWithId(func_800A5178, 0x58, 0, arg);
}

/* Map objects 0x328/0x329 set the kind and the character (actor of key KEY), 0x32A ends it */
void func_800A5404(void *arg, s32 id, s32 key) {
    StageActorMark *task = arg;

    switch (id) {
    case 0x328:
        task->kind = 2;
        break;
    case 0x329:
        task->kind = 3;
        break;
    case 0x32A:
        task->setState(task, TASK_DONE);
        break;
    }
    switch (id) {
    case 0x328:
    case 0x329:
        task->actor = TASK_REGISTRY.funcs.find(5, key, -1);
        break;
    }
}

/* Creates the event object of story progress 0 or 1 (with an object for 1) */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        switch (GAME.progress) {
        case 0:
            children[0] = FIELDSTG_startEvent(1);
            break;
        case 1:
            children[1] = func_800A5068();
            children[0] = FIELDSTG_startEvent(3);
            break;
        }
        task->nextState(task);
        children[1] = NULL;
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A55D0(void) {
    GAME.progress = 1;
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x1B9
#define STAGE_ARCHIVE 0x3D2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x1C7
#define STAGE_ARCHIVE 0x3E2
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16 | 1;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x15000, 0x18300};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x1B;
    FIELDSTG_state.music = MUSIC(0x1B, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1[] = {
    0x601, 1, 0x1E0, 0x150,
    0x100, 1, 0x280, 0x100,
    0x101, 1, 1, 1,
    0x100, 0xB, 0x2A0, 0xF0,
    0x101, 0xB, 1, 1,
    0x100, 0xC, 0x2C0, 0xE0,
    0x101, 0xC, 1, 1,
    0x100, 0xD, 0x14A, 0x121,
    0x101, 0xD, 1, 1,
    0x100, 0xE, 0x185, 0x126,
    0x101, 0xE, 3, 7,
    0x100, 0xF, 0x136, 0xFC,
    0x101, 0xF, 3, 2,
    0x300, 0x1E,
    0x102, 1, 0x1E0, 0x150, 1,
    0x102, 0xB, 0x200, 0x140, 1,
    0x102, 0xC, 0x220, 0x130, 1,
    0x302, 1,
    0x600, 1, 1,
    0x102, 1, 0x1D0, 0x158, 1,
    0x102, 0xB, 0x1E0, 0x140, 1,
    0x102, 0xC, 0x210, 0x138, 1,
    0x302, 1,
    0x101, 1, 0x3A, 1,
    0x101, 0xB, 0x3A, 3,
    0x101, 0xC, 0x3A, 5,
    0x300, 0x3C,
    0x200, 0, 1, 1, 0,
    0x101, 1, 1, 1,
    0x301,
    0x101, 1, 0x3A, 1,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xC,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 0xC, 0x200, 0x130, 3,
    0x302, 0xC,
    0x600, 0, 0xC,
    0x200, 0, 2, 0xC, 0,
    0x101, 0xB, 0x3A, 3,
    0x101, 0xC, 7, 2,
    0x301,
    0x101, 0xB, 0x3B, 3,
    0x101, 0xC, 0x3B, 3,
    0x300, 0x3C,
    0x101, 1, 1, 5,
    0x300, 0x78,
    0x600, 0, 1,
    0x101, 1, 0x2A, 5,
    0x300, 0x78,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x600, 0, 1,
    0x200, 0, 3, 1, 0,
    0x101, 1, 7, 5,
    0x301,
    0x101, 1, 0x2A, 5,
    0x101, 0xB, 1, 1,
    0x101, 0xC, 1, 1,
    0x101, 0x323, 0x325, 0xC,
    0x101, 0x324, 0x325, 0xB,
    0x300, 0x5A,
    0x101, 1, 1, 5,
    0x101, 0x323, 0x326, 1,
    0x101, 0x324, 0x326, 1,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 1,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x101, 0xB, 9, 1,
    0x101, 0xC, 9, 1,
    0x303, 0xC,
    0x101, 0xB, 1, 1,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x102, 1, 0x170, 0x158, 3,
    0x102, 0xB, 0x170, 0x158, 3,
    0x102, 0xC, 0x170, 0x158, 3,
    0x302, 1,
    0x102, 1, 0x124, 0x12E, 5,
    0x302, 0xB,
    0x102, 0xB, 0x144, 0x13E, 5,
    0x302, 0xC,
    0x102, 0xC, 0x164, 0x14E, 5,
    0x302, 0xB,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x101, 0xD, 9, 1,
    0x303, 0xD,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x600, 0, 0xD,
    0x200, 0, 4, 0xD, 0,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x101, 1, 9, 5,
    0x101, 0xB, 9, 5,
    0x101, 0xC, 9, 5,
    0x303, 1,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x600, 0, 0xD,
    0x200, 0, 5, 0xD, 0,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x600, 0, 0xB,
    0x101, 0x323, 0x325, 1,
    0x101, 0x324, 0x325, 0xB,
    0x101, 0x325, 0x325, 0xC,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 1,
    0x101, 0x324, 0x326, 1,
    0x101, 0x325, 0x326, 1,
    0x300, 0x1E,
    0x600, 0, 0xD,
    0x200, 0, 6, 0xD, 0,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x101, 1, 9, 5,
    0x101, 0xB, 9, 5,
    0x101, 0xC, 9, 5,
    0x303, 1,
    0x200, 0, 7, 0xD, 0,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x600, 0, 1,
    0x101, 1, 0x29, 5,
    0x101, 0xB, 9, 5,
    0x101, 0xC, 9, 5,
    0x101, 0x323, 0x327, 1,
    0x303, 0xB,
    0x101, 1, 0x29, 1,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x300, 0x78,
    0x101, 0xB, 1, 3,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x600, 0, 0xB,
    0x101, 0xB, 0x39, 3,
    0x303, 0xB,
    0x101, 0xB, 1, 3,
    0x300, 0x1E,
    0x101, 1, 0x29, 1,
    0x102, 0xB, 0xF4, 0x166, 5,
    0x302, 0xB,
    0x101, 1, 1, 1,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 1,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 1, 0x104, 0x13E, 1,
    0x102, 0xC, 0x144, 0x15E, 1,
    0x302, 1,
    0x300, 0x1E,
    0x200, 0, 8, 0xB, 1,
    0x101, 0xB, 7, 5,
    0x301,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x600, 0, 1,
    0x200, 0, 9, 1, 0,
    0x101, 1, 7, 1,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 0x3B, 1,
    0x101, 0x327, 0x328, 0xC,
    0x301,
    0x101, 1, 1, 1,
    0x101, 0xB, 0x39, 5,
    0x101, 0xC, 1, 1,
    0x101, 0x327, 0x32A, 1,
    0x303, 0xB,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x600, 0, 0xB,
    0x200, 0, 0xA, 0xB, 1,
    0x101, 0xB, 7, 5,
    0x301,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x600, 0, 1,
    0x200, 0, 0xB, 1, 0,
    0x101, 1, 7, 1,
    0x101, 0x327, 0x329, 0xC,
    0x301,
    0x101, 1, 1, 1,
    0x101, 0x327, 0x32A, 1,
    0x300, 0x1E,
    0x600, 0, 0xB,
    0x101, 0xB, 1, 1,
    0x300, 0x1E,
    0x101, 0xB, 0x39, 1,
    0x303, 0xB,
    0x101, 0xB, 1, 1,
    0x300, 0x1E,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xC, 0xB, 1,
    0x101, 0xB, 7, 5,
    0x301,
    0x101, 0xB, 1, 5,
    0x300, 0x1E,
    0x101, 1, 0x29, 1,
    0x102, 0xB, 0x144, 0x13E, 5,
    0x102, 0xC, 0x164, 0x14E, 5,
    0x101, 0x323, 0x327, 1,
    0x302, 0xB,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x101, 0xB, 1, 1,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xB, 0,
    0x101, 0xB, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 0xB, 1, 1,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x102, 1, 0x124, 0x12E, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0x323, 0x326, 1,
    0x302, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xE, 0xD, 0,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 0xD, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x29, 5,
    0x101, 0xB, 9, 5,
    0x101, 0xC, 9, 5,
    0x101, 0x323, 0x327, 1,
    0x303, 0xB,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x300, 0x3C,
    0x101, 0xB, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0xF, 0xB, 0,
    0x101, 0xB, 7, 3,
    0x301,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 3,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x101, 1, 0x2E, 5,
    0x303, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 9, 5,
    0x303, 1,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0x10, 0xD, 0,
    0x101, 0xD, 7, 1,
    0x301,
    0x101, 1, 9, 5,
    0x101, 0xB, 9, 5,
    0x101, 0xC, 9, 5,
    0x101, 0xD, 1, 1,
    0x303, 1,
    0x101, 1, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0xD, 2, 1,
    0x101, 0x343, 0x335, 1,
    0x300, 0x96,
    0x304, 0x500, 0x64, 0x64, 0,
    0,
};
s16 script3[] = {
    0x600, 1, 0xB,
    0x100, 1, 0x124, 0x12E,
    0x101, 1, 1, 5,
    0x101, 2, 1, 1,
    0x100, 0xB, 0x144, 0x13E,
    0x101, 0xB, 1, 5,
    0x100, 0xC, 0x164, 0x14E,
    0x101, 0xC, 1, 5,
    0x100, 0xD, 0x14A, 0x121,
    0x101, 0xD, 1, 1,
    0x100, 0xE, 0x185, 0x126,
    0x101, 0xE, 1, 7,
    0x100, 0xF, 0x136, 0xFC,
    0x101, 0xF, 1, 2,
    0x300, 0x78,
    0x200, 0, 1, 0xD, 0,
    0x301,
    0x101, 1, 1, 7,
    0x101, 0xB, 1, 3,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 1, 0,
    0x101, 1, 7, 7,
    0x301,
    0x300, 0x1E,
    0x102, 1, 0xB3, 0xF5, 1,
    0x302, 1,
    0x101, 1, 1, 1,
    0x101, 0xB, 1, 3,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x200, 1, 4, 0xC, 1,
    0x200, 0, 3, 0xB, 2,
    0x102, 1, 0x3D, 0x12F, 1,
    0x101, 0xB, 7, 2,
    0x101, 0xC, 7, 2,
    0x301,
    0x304, 0x2D9, 0x64, 0x64, 0,
    0,
};
AnimFrame D_800A5FD4[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 8, 4 }, { 9, 4 }, { 10, 4 }, { 11, 4 },
    { 12, 4 }, { 13, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A6010[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 8, 4 }, { 9, 4 }, { 10, 4 }, { 11, 4 },
    { 255, 0 },
};
AnimFrame D_800A6044[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 255, 0 },
};
AnimFrame D_800A6060[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 255, 0 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x11F, 0x170, 0x1F, 0x140, 0x1F1 },
    { 0x180, 0x100, 0x1A4, 0x129, 0x190, 0x29, 0x160, 0x1F1 },
    { 0x180, 0x100, 0x1AC, 0x129, 0x1B0, 0x29, 0x170, 0x1F1 },
    { 0x140, 0x100, 0x176, 0x138, 0xD8, 0x38, 0x140, 0x1F0 },
    { 0x180, 0x100, 0x1B6, 0x110, 0x1D8, 0x10, 0x160, 0x1F0 },
    { 0x180, 0x100, 0x194, 0x11F, 0x150, 0x1F, 0x170, 0x1F0 },
};
u16 actor0Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(1), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0xB, 5, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0xB, 5, 0, 0, 1 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0xC, 6, 0, 0, 1 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0xC, 6, 0, 0, 1 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0xD, 7, 0, 0, 1 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0xD, 7, 0, 0, 1 };
FieldActorEntry actor8 = { actor8Conditions, NULL, 0xE, 8, 0, 0, 1 };
FieldActorEntry actor9 = { actor9Conditions, NULL, 0xE, 8, 0, 0, 1 };
FieldActorEntry actor10 = { actor10Conditions, NULL, 0xF, 9, 0, 0, 1 };
FieldActorEntry actor11 = { actor11Conditions, NULL, 0xF, 9, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x64, 2, 0x4A, 2, 0, 5, 8, 0, 299, 232, 0, 0 },
    { 1, 0, 0x40, 2, 0x51, 2, 0, 0xB, 0xA, 0, 156, 254, 0, 0 },
    { 1, 0, 0x40, 2, 0x51, 2, 0, 0xB, 0xA, 0, 236, 358, 0, 0 },
    { 1, 0, 0x40, 2, 0x51, 2, 0, 0xB, 0xA, 0, 398, 358, 0, 0 },
    { 1, 0, 0x64, 2, 0x4B, 2, 0, 5, 8, 0, 369, 246, 0, 0 },
    { 0, 4, 0x64, 2, 0x46, 2, 0, 0xD, 4, 0, 299, 232, 0, 0 },
    { 0, 3, 0x64, 2, 0x47, 2, 0, 0xB, 8, 0, 299, 232, 0, 0 },
    { 0, 2, 0x64, 2, 0x48, 2, 0, 5, 8, 0, 299, 232, 0, 0 },
    { 1, 0, 0x64, 2, 0x49, 2, 0, 5, 8, 0, 369, 246, 0, 0 },
    { 1, 0, 0x40, 2, 0x50, 0, 0, 0, 0, 0, 156, 254, 0, 0 },
    { 1, 0, 0x40, 2, 0x50, 0, 0, 0, 0, 0, 236, 358, 0, 0 },
    { 1, 0, 0x40, 2, 0x50, 0, 0, 0, 0, 0, 398, 358, 0, 0 },
    { 1, 0, 0x64, 2, 0x52, 2, 0, 3, 8, 0, 404, 239, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 402, 400, 408, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 241, 400, 407, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 160, 295, 303, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 289, 244, 265, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 289, 262, 292, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 305, 272, 300, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 321, 279, 308, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 337, 286, 316, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 353, 298, 324, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 369, 289, 316, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 385, 281, 308, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 399, 273, 300, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1, script1, EVENT_TEXT(1), NULL, func_800A55D0 },
    { 3, script3, EVENT_TEXT(2), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
