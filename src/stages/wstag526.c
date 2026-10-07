#include "common.h"
#include "stage.h"
extern u16 D_800A6730[];
extern AnimFrame *D_800A6718[];
extern AnimFrame *D_800A6720[];
extern u16 D_800A6728[];
void *func_800A5274(void);
void *func_800A56B4(void);
void *func_800A5A04(void);
StageWanderPair *func_800A625C(s32 tileAnim, s32 speedIndex, s32 start);
void func_800A5228();
void func_800A5668();
void func_800A59B8();
void func_800A6210();
extern AnimFrame D_800A65A4[];
extern AnimFrame D_800A65B8[];
extern AnimFrame *D_800A663C[];
extern AnimFrame *D_800A6644[];
extern AnimFrame D_800A664C[];

/* Creates the stage's objects (three records and nine wandering pairs); in TASK_DONE tells them all to go away */
void func_800A4CA4(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A5274();
        children[1] = func_800A56B4();
        children[2] = func_800A5A04();
        children[3] = func_800A625C(1, 0, 0);
        children[4] = func_800A625C(2, 0, 5);
        children[5] = func_800A625C(3, 1, 0);
        children[6] = func_800A625C(4, 1, 5);
        children[7] = func_800A625C(5, 1, 0);
        children[8] = func_800A625C(6, 2, 0);
        children[9] = func_800A625C(7, 2, 2);
        children[10] = func_800A625C(8, 3, 5);
        children[11] = func_800A625C(9, 3, 3);
        task->nextState(task);
        break;
    case TASK_RUN:
        break;
    case TASK_DONE:
        func_800A5228(children[0], 0, 0);
        func_800A5668(children[1], 0, 0);
        func_800A59B8(children[2], 0, 0);
        func_800A6210(children[3], 0, 0);
        func_800A6210(children[4], 0, 0);
        func_800A6210(children[5], 0, 0);
        func_800A6210(children[6], 0, 0);
        func_800A6210(children[7], 0, 0);
        func_800A6210(children[8], 0, 0);
        func_800A6210(children[9], 0, 0);
        func_800A6210(children[10], 0, 0);
        func_800A6210(children[11], 0, 0);
        task->setState(task, TASK_RUN);
        break;
    case TASK_KILL:
        break;
    }
}

/* Ends the task when map object 0x34B is triggered */
void func_800A4EB4(StageTask *task, s32 id) {
    if (task != NULL && id == 0x34B) {
        task->setState(task, TASK_DONE);
    }
}

/* Creates the task of func_800A4CA4 with an id */
void *func_800A4EEC(s32 arg) {
    return createTaskWithId(func_800A4CA4, 0x50, 0x30, arg);
}

#include "common/step_tile_animation.inc.c"

/* Animates the record of animation 0x15 (frame 2) while mode isn't 0; fades it out wait frames after mode 2 */
void func_800A503C(StageTileSolo *task) {
    StageTile *rec;
    StageTile *tile;
    StageTile *fading;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tile.anim.index = 0;
        task->tile.anim.timer = D_800A65A4[0].duration;
        task->mode = 1;
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 0x15) {
                task->tile.tile = rec;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        tile = task->tile.tile;
        if (task->mode != 0) {
            tile->visible = 1;
            tile->frame = 2;
            tile->clutRow = stepTileAnimation(&task->tile, D_800A65A4, 0, 0);
        } else {
            tile->visible = 0;
        }
        if (task->mode == 2) {
            if (--task->wait <= 0) {
                task->setState(task, TASK_DONE);
            }
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->tile.anim.index = 0;
            task->tile.anim.timer = D_800A65B8[0].duration;
            task->setSubstate(task, 1);
        }
        fading = task->tile.tile;
        frame = stepTileAnimation(&task->tile, D_800A65B8, 1, 0);
        switch (frame) {
        case 0x12C:
            fading->visible = 0;
            break;
        case 0xFF:
            fading->visible = 0;
            task->mode = 0;
            task->setState(task, TASK_RUN);
            break;
        default:
            fading->visible = 1;
            fading->frame = 2;
            fading->clutRow = frame;
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

void func_800A5228(StageTileDuo *task, s32 arg1, s32 arg2) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x96;
    }
}

void *func_800A5244(s32 arg) {
    return createTaskWithId(func_800A503C, 0x5C, 0, arg);
}

void *func_800A5274(void) {
    return createTask(func_800A503C, 0x5C, 0);
}

s32 stepTileAnimation2(StageTileAnim *obj, AnimFrame *frames, s32 once, s32 depth) {
    AnimFrame *frame = &frames[obj->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        obj->anim.timer -= dt;
    }
    if (obj->anim.timer <= 0) {
        frame++;
        obj->anim.index++;
        obj->anim.timer += frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        stepTileAnimation2(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

/* Animates the records of animations 0x13 and 0x14 while mode isn't 0; fades them out wait frames after mode 2 */
void func_800A53C0(StageTileDuo *task) {
    StageTile *rec;
    StageTile *tile;
    StageTile *fading;
    s32 i;
    s32 j;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = D_800A663C[0]->duration;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = D_800A663C[1]->duration;
        task->mode = 1;
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 0x13:
                task->tiles[0].tile = rec;
                break;
            case 0x14:
                task->tiles[1].tile = rec;
                break;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->tiles[i].tile;
            if (task->mode != 0) {
                tile->visible = 1;
                tile->frame = stepTileAnimation2(&task->tiles[i], D_800A663C[i], 0, 0);
                tile->clutRow = 0;
            } else {
                tile->visible = 0;
            }
        }
        if (task->mode == 2) {
            if (--task->wait <= 0) {
                task->setState(task, TASK_DONE);
            }
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A6644[0]->duration;
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A6644[1]->duration;
            task->setSubstate(task, 1);
        }
        for (j = 0; j < 2; j++) {
            fading = task->tiles[j].tile;
            frame = stepTileAnimation2(&task->tiles[j], D_800A6644[j], 1, 0);
            switch (frame) {
            case 0x12C:
                fading->visible = 0;
                break;
            case 0xFF:
                fading->visible = 0;
                task->mode = 0;
                task->setState(task, TASK_RUN);
                break;
            default:
                fading->visible = 1;
                fading->frame = frame;
                fading->clutRow = 0;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Tells the task to go away after 90 frames (mode 2) */
void func_800A5668(StageTileDuo *task) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x5A;
    }
}

void *func_800A5684(s32 arg) {
    return createTaskWithId(func_800A53C0, 0x64, 0, arg);
}

void *func_800A56B4(void) {
    return createTask(func_800A53C0, 0x64, 0);
}

s32 stepTileAnimation3(StageTileAnim *obj, AnimFrame *frames, s32 once, s32 depth) {
    AnimFrame *frame = &frames[obj->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        obj->anim.timer -= dt;
    }
    if (obj->anim.timer <= 0) {
        frame++;
        obj->anim.index++;
        obj->anim.timer += frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        stepTileAnimation3(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

/* Shows the record of animation 0x16 (frame 0x21) while mode isn't 0; fades it out wait frames after mode 2 */
void func_800A5800(StageTileSolo *task) {
    StageTile *rec;
    StageTile *tile;
    StageTile *fading;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->mode = 1;
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 0x16) {
                task->tile.tile = rec;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        tile = task->tile.tile;
        if (task->mode != 0) {
            tile->visible = 1;
            tile->frame = 0x21;
        } else {
            tile->visible = 0;
        }
        if (task->mode == 2) {
            if (--task->wait <= 0) {
                task->setState(task, TASK_DONE);
            }
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->tile.anim.index = 0;
            task->tile.anim.timer = D_800A664C[0].duration;
            task->setSubstate(task, 1);
        }
        fading = task->tile.tile;
        frame = stepTileAnimation3(&task->tile, D_800A664C, 1, 0);
        switch (frame) {
        case 0x12C:
            fading->visible = 0;
            break;
        case 0xFF:
            fading->visible = 0;
            task->mode = 0;
            task->setState(task, TASK_RUN);
            break;
        default:
            fading->visible = 1;
            fading->frame = frame;
            fading->clutRow = 0;
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Tells the task to go away after 40 frames (mode 2) */
void func_800A59B8(StageTileDuo *task) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x28;
    }
}

void *func_800A59D4(s32 arg) {
    return createTaskWithId(func_800A5800, 0x5C, 0, arg);
}

void *func_800A5A04(void) {
    return createTask(func_800A5800, 0x5C, 0);
}

s32 stepTileAnimation4(StageTileAnim *obj, AnimFrame *frames, s32 once, s32 depth) {
    AnimFrame *frame = &frames[obj->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        obj->anim.timer -= dt;
    }
    if (obj->anim.timer <= 0) {
        frame++;
        obj->anim.index++;
        obj->anim.timer += frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        stepTileAnimation4(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

s32 func_800A5B50(StageWanderPair *task, s32 dist) {
    s32 dx = task->posX - task->homeX;
    s32 dy = task->posY - task->homeY;

    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return dist < dx + dy;
}

s32 func_800A5B8C(s32 x, s32 y) {
    s32 result = 0;
    s32 ratio = 0;
    s32 base;
    s32 i;

    if (x <= 0 && y >= 0) {
        base = 0;
    } else if (x >= 0 && y >= 0) {
        base = 0x40;
    } else if (x >= 0 && y <= 0) {
        base = 0x80;
    } else if (x <= 0 && y <= 0) {
        base = 0xC0;
    } else {
        base = 0;
    }
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    if (x == y) {
        return base | 0x20;
    }
    if (y < x) {
        ratio = y * 0xFFFF / x;
    } else if (x < y) {
        ratio = x * 0xFFFF / y;
    }
    for (i = 0; i <= 0x20; i++) {
        if (D_800A6730[i] <= ratio && ratio <= D_800A6730[i + 1]) {
            switch (base) {
            case 0:
            case 0x80:
                if (y < x) {
                    result = i;
                } else if (x < y) {
                    result = 0x40 - i;
                }
                return result + base;
            case 0x40:
            case 0xC0:
                if (y < x) {
                    result = 0x40 - i;
                } else if (x < y) {
                    result = i;
                }
                return result + base;
            }
        }
    }
    return 0xFF;
}

void func_800A5CFC(StageWanderPair *task) {
    s32 dx;
    s32 dy;

    task->timer += GFX.funcs.getFrameTime();
    if (task->period < task->timer) {
        if (func_800A5B50(task, 0x1E)) {
            task->angle = ((func_800A5B8C(task->homeX - task->posX, task->homeY - task->posY) - 0x40) << 4) & 0xFFF;
        } else {
            task->angle = (RANDOM.next() & 0xFF) << 4;
        }
        task->timer -= task->period;
        task->timer += (RANDOM.next() & 0xF) - 7;
    }
    dx = rsin(task->angle) * task->speed / 4096;
    dy = rcos(task->angle) * task->speed / 4096;
    task->x += dx;
    task->y += dy;
    task->posX = task->x >> 8;
    task->posY = task->y >> 8;
}

void func_800A5E78(StageWanderPair *task) {
    StageTile *tile;
    StageTile *rec;
    StageTile *fading;
    s32 i;
    s32 j;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tiles[0].anim.index = task->start;
        task->tiles[0].anim.timer = D_800A6718[0]->duration;
        task->tiles[1].anim.index = task->start;
        task->tiles[1].anim.timer = D_800A6718[1]->duration;
        task->mode = 1;
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == task->tileAnim) {
                task->tiles[0].tile = rec;
                task->homeX = rec->x;
                task->homeY = rec->y;
                task->x = rec->x << 8;
                task->y = rec->y << 8;
            }
            if (rec->anim == task->tileAnim + 9) {
                task->tiles[1].tile = rec;
            }
        }
        task->period = 0x28;
        task->timer = task->start;
        task->speed = D_800A6728[task->speedIndex];
        task->angle = (RANDOM.next() & 0xFF) << 4;
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->mode != 0) {
            func_800A5CFC(task);
        }
        for (i = 0; i < 2; i++) {
            tile = task->tiles[i].tile;
            if (task->mode != 0) {
                tile->visible = 1;
                tile->clutRow = stepTileAnimation4(&task->tiles[i], D_800A6718[i], 0, 0);
                tile->x = task->posX;
                tile->y = task->posY;
            } else {
                tile->visible = 0;
            }
        }
        if (task->mode == 3) {
            task->speed -= 4;
            if (task->speed <= 0x10) {
                task->setState(task, TASK_DONE);
            }
        }
        if (task->mode == 2) {
            if (--task->wait <= 0) {
                task->mode = 3;
            }
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A6720[0]->duration;
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A6720[1]->duration;
            task->setSubstate(task, 1);
        }
        func_800A5CFC(task);
        for (j = 0; j < 2; j++) {
            fading = task->tiles[j].tile;
            frame = stepTileAnimation4(&task->tiles[j], D_800A6720[j], 1, 0);
            switch (frame) {
            case 0x12C:
                fading->visible = 0;
                break;
            case 0xFF:
                fading->visible = 0;
                task->mode = 0;
                task->setState(task, TASK_RUN);
                break;
            default:
                fading->visible = 1;
                fading->clutRow = frame;
                fading->x = task->posX;
                fading->y = task->posY;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

void func_800A6210(StageWanderer *task) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x3C;
    }
}

void *func_800A622C(s32 arg) {
    return createTaskWithId(func_800A5E78, 0x88, 0, arg);
}

/* Creates a pair of wandering records: tileAnim and tileAnim + 9 */
StageWanderPair *func_800A625C(s32 tileAnim, s32 speedIndex, s32 start) {
    StageWanderPair *task = createTask(func_800A5E78, sizeof(StageWanderPair), 0);

    task->start = start;
    task->speedIndex = speedIndex;
    task->tileAnim = tileAnim;
    return task;
}

/* The stage task: creates the object of map object 0x33D before progress 30 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress < 0x1E) {
            children[0] = func_800A4EEC(0x33D);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

/* Event: sets the progress to 30 and applies action 0x8011 */
void func_800A6380(void) {
    GAME.progress = 0x1E;
    FLAGS_00.applyAction(ITEM(0, 0x11), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x6A8
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x6B8
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x13D00, 0x38500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x37;
    FIELDSTG_state.music = MUSIC(0x37, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script760[] = {
    0x102, 2, 0x98, 0xBE, 3,
    0x100, 0x83, 0x80, 0xB2,
    0x101, 0x83, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x102, 2, 0x90, 0xBA, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x100, 0x83, 0, 0,
    0x101, 0x83, 1, 7,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x101, 0x33D, 0x34B, 2,
    0x300, 0xD2,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x98, 0xBE, 7,
    0x302, 2,
    0x102, 2, 0xD0, 0x100, 7,
    0x304, 0x2AB, 0x41E, 0x1E8, 5,
    0,
};
AnimFrame D_800A65A4[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 1, 12 },
    { 255, 0 },
};
AnimFrame D_800A65B8[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 3, 12 },
    { 4, 12 }, { 5, 12 }, { 255, 0x3E7 },
};
AnimFrame D_800A65D4[] = {
    { 37, 12 }, { 38, 12 }, { 39, 12 }, { 40, 12 },
    { 41, 12 }, { 42, 12 }, { 255, 0 },
};
AnimFrame D_800A65F0[] = {
    { 3, 4 }, { 4, 4 }, { 5, 4 }, { 6, 4 },
    { 7, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A6608[] = {
    { 91, 12 }, { 92, 12 }, { 93, 12 }, { 94, 12 },
    { 95, 12 }, { 96, 12 }, { 255, 0 },
};
AnimFrame D_800A6624[] = {
    { 8, 4 }, { 9, 4 }, { 10, 4 }, { 11, 4 },
    { 12, 4 }, { 255, 0x3E7 },
};
AnimFrame *D_800A663C[] = {
    D_800A65D4, D_800A6608,
};
AnimFrame *D_800A6644[] = {
    D_800A65F0, D_800A6624,
};
AnimFrame D_800A664C[] = {
    { 33, 4 }, { 34, 4 }, { 35, 4 }, { 36, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A6660[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 4, 4 }, { 3, 4 },
    { 2, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A668C[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 255, 0x3E7 },
};
AnimFrame D_800A66BC[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 4, 4 }, { 3, 4 },
    { 2, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A66E8[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 255, 0x3E7 },
};
AnimFrame *D_800A6718[] = {
    D_800A6660, D_800A66BC,
};
AnimFrame *D_800A6720[] = {
    D_800A668C, D_800A66E8,
};
u16 D_800A6728[] = {
    96, 80, 72, 64,
};
u16 D_800A6730[] = {
    0, 0x648, 0xC93, 0x12E2, 0x1936, 0x1F92, 0x259F, 0x2C6B,
    0x32EB, 0x39C7, 0x401F, 0x46D7, 0x4DA7, 0x5491, 0x5B98, 0x62BF,
    0x6A09, 0x7179, 0x7913, 0x80DB, 0x88B5, 0x9105, 0x9970, 0xA21B,
    0xAB0D, 0xB44A, 0xBDDC, 0xC7C8, 0xD217, 0xDCD2, 0xE805, 0xF3BA,
    0xFFFE, 0xFFFF,
};
Battle area0Battle0 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle1 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle2 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle3 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle4 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle5 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle6 = { 158, 27, MUSIC(2, 0) };
Battle area0Battle7 = { 158, 27, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area1Battles = {
    0,
    { &area1Battle0, &area1Battle1, &area1Battle2, &area1Battle3,
      &area1Battle4, &area1Battle5, &area1Battle6, &area1Battle7 },
};
Battle area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area2Battles = {
    0,
    { &area2Battle0, &area2Battle1, &area2Battle2, &area2Battle3,
      &area2Battle4, &area2Battle5, &area2Battle6, &area2Battle7 },
};
Battle area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 78, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1AE, 0x118, 0x1B8, 0x18, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x180, 0x138, 0x100, 0x38, 0x140, 0x1F4 },
    { 0x140, 0x100, 0x175, 0x120, 0xD4, 0x20, 0x150, 0x1F4 },
};
u16 actor0Talk0Actions[] = { FLAG(2, 0x1F), 1, ITEM(2, 0x94), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor2Talk0Conditions[] = { ITEM(3, 0x81), 1, CODES_END };
u16 actor2Talk1Conditions[] = { ITEM(3, 0x81), 0, FLAG(0, 0), 0, CODES_END };
u16 actor2Talk1Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor2Talk2Conditions[] = { ITEM(3, 0x81), 0, FLAG(0, 0), 1, ITEM(2, 0x7D), 0, CODES_END };
u16 actor2Talk3Conditions[] = { ITEM(3, 0x81), 0, FLAG(0, 0), 1, ITEM(2, 0x7D), 1, CODES_END };
u16 actor2Talk3Actions[] = {
    ITEM(3, 0x81), 1,
    ITEM(3, 0x80), 0,
    ITEM(2, 0x7D), 0,
    SPECIAL(0x13), 1,
    CODES_END,
};
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x17F },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, NULL, 0x2E2 },
    { actor2Talk1Conditions, actor2Talk1Actions, 0x2E3 },
    { actor2Talk2Conditions, NULL, 0x2E4 },
    { actor2Talk3Conditions, actor2Talk3Actions, 0x2E5 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 0x1F), 0, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x1D), 1, CODES_END };
u16 actor2Conditions[] = {
    SPECIAL(0x43), 1,
    SPECIAL(0x4B), 1,
    ITEM(3, 0x80), 1,
    ITEM(3, 0x81), 0,
    CODES_END,
};
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 545, 177, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0x83, 5, 128, 178, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0xAB, 6, 641, 291, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0x15, 0xFF, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0x13, 0xFF, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0x14, 0xFF, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0xFF, 2, 0xD, 0, 0, 0, 0, 0, 80, 128, 0, 0 },
    { 0, 2, 0xFF, 2, 0xD, 0, 0, 0, 0, 0, 88, 48, 0, 0 },
    { 0, 3, 0xFF, 2, 0xD, 0, 0, 0, 0, 0, 176, 72, 0, 0 },
    { 0, 6, 0xFF, 2, 0xE, 0, 0, 0, 0, 0, 32, 104, 0, 0 },
    { 0, 4, 0xFF, 2, 0xE, 0, 0, 0, 0, 0, 152, 128, 0, 0 },
    { 0, 5, 0xFF, 2, 0xE, 0, 0, 0, 0, 0, 168, 48, 0, 0 },
    { 0, 7, 0xFF, 2, 0xF, 0, 0, 0, 0, 0, 56, 112, 0, 0 },
    { 0, 9, 0xFF, 2, 0xF, 0, 0, 0, 0, 0, 112, 144, 0, 0 },
    { 0, 8, 0xFF, 2, 0xF, 0, 0, 0, 0, 0, 208, 88, 0, 0 },
    { 0, 0xA, 0xFF, 2, 0x10, 0, 0, 0, 0, 0, 80, 128, 0, 0 },
    { 0, 0xC, 0xFF, 2, 0x10, 0, 0, 0, 0, 0, 88, 48, 0, 0 },
    { 0, 0xB, 0xFF, 2, 0x10, 0, 0, 0, 0, 0, 176, 72, 0, 0 },
    { 0, 0xF, 0xFF, 2, 0x11, 0, 0, 0, 0, 0, 32, 104, 0, 0 },
    { 0, 0xE, 0xFF, 2, 0x11, 0, 0, 0, 0, 0, 152, 128, 0, 0 },
    { 0, 0xD, 0xFF, 2, 0x11, 0, 0, 0, 0, 0, 168, 48, 0, 0 },
    { 0, 0x10, 0xFF, 2, 0x12, 0, 0, 0, 0, 0, 56, 112, 0, 0 },
    { 0, 0x11, 0xFF, 2, 0x12, 0, 0, 0, 0, 0, 112, 144, 0, 0 },
    { 0, 0x12, 0xFF, 2, 0x12, 0, 0, 0, 0, 0, 208, 88, 0, 0 },
    { 0, 0x16, 0xFF, 6, 0x21, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 128, 607, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 128, 907, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 675, 970, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 284, 1043, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 711, 813, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 339, 392, 409, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x11, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x22F, 0x3C8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x220, 0x372, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x251, 0x2F7, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x260, 0x2A1, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 0xA, 0x1C0, 0x181, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 0xA, 0x1D0, 0xDA, 0, 0, 0, 0 },
    { { { PROGRESS(0x1D), 1 }, { CODES_END, 0 } }, 8, 0x2F8, 0, 0, 0, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x11, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 760, script760, EVENT_TEXT(0x23), NULL, func_800A6380 },
    { -1, NULL, 0, NULL, NULL },
};
