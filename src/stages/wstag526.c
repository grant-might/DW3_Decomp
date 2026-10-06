#include "common.h"
#include "stage.h"
void func_800A5E78();
void func_800A5800();
void func_800A53C0();
void func_800A503C();
s32 func_800A5B8C(s32 x, s32 y);
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

s32 stepTileAnimation(StageTileAnim *obj, AnimFrame *frames, s32 once, s32 depth) {
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
        stepTileAnimation(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
    FLAGS_00.applyAction(0x8011, 1);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13D00, 0x38500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x37;
    D_800990B4.music = 0x60DC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

void func_800A6380();
extern AnimFrame D_800A65D4[];
extern AnimFrame D_800A6608[];
extern AnimFrame D_800A65F0[];
extern AnimFrame D_800A6624[];
extern AnimFrame D_800A6660[];
extern AnimFrame D_800A66BC[];
extern AnimFrame D_800A668C[];
extern AnimFrame D_800A66E8[];
extern Battle D_800A6774;
extern Battle D_800A6780;
extern Battle D_800A678C;
extern Battle D_800A6798;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67F8;
extern Battle D_800A6804;
extern Battle D_800A6810;
extern Battle D_800A681C;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A687C;
extern Battle D_800A6888;
extern Battle D_800A6894;
extern Battle D_800A68A0;
extern Battle D_800A68AC;
extern Battle D_800A68B8;
extern Battle D_800A68C4;
extern Battle D_800A68D0;
extern Battle D_800A6900;
extern Battle D_800A690C;
extern Battle D_800A6918;
extern Battle D_800A6924;
extern Battle D_800A6930;
extern Battle D_800A693C;
extern Battle D_800A6948;
extern Battle D_800A6954;
extern BattleList D_800A67D4;
extern BattleList D_800A6858;
extern BattleList D_800A68DC;
extern BattleList D_800A6960;
extern u16 D_800A6A30[];
extern u16 D_800A6A40[];
extern u16 D_800A6A48[];
extern u16 D_800A6A54[];
extern u16 D_800A6A5C[];
extern u16 D_800A6A6C[];
extern u16 D_800A6A7C[];
extern u16 D_800A6AE4[];
extern FieldTalk D_800A6A90[];
extern u16 D_800A6AEC[];
extern u16 D_800A6AF4[];
extern FieldTalk D_800A6AA8[];
extern FieldActorEntry D_800A6B08;
extern FieldActorEntry D_800A6B1C;
extern FieldActorEntry D_800A6B30;
extern s16 D_800A64CC[];

s16 D_800A64CC[] = {
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
Battle D_800A6774 = { 158, 27, 0x60080000 };
Battle D_800A6780 = { 158, 27, 0x60080000 };
Battle D_800A678C = { 158, 27, 0x60080000 };
Battle D_800A6798 = { 158, 27, 0x60080000 };
Battle D_800A67A4 = { 158, 27, 0x60080000 };
Battle D_800A67B0 = { 158, 27, 0x60080000 };
Battle D_800A67BC = { 158, 27, 0x60080000 };
Battle D_800A67C8 = { 158, 27, 0x60080000 };
BattleList D_800A67D4 = {
    3,
    { &D_800A6774, &D_800A6780, &D_800A678C, &D_800A6798,
      &D_800A67A4, &D_800A67B0, &D_800A67BC, &D_800A67C8 },
};
Battle D_800A67F8 = { 0, 0, 0x60040000 };
Battle D_800A6804 = { 0, 0, 0x60040000 };
Battle D_800A6810 = { 0, 0, 0x60040000 };
Battle D_800A681C = { 0, 0, 0x60040000 };
Battle D_800A6828 = { 0, 0, 0x60040000 };
Battle D_800A6834 = { 0, 0, 0x60040000 };
Battle D_800A6840 = { 0, 0, 0x60040000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
BattleList D_800A6858 = {
    0,
    { &D_800A67F8, &D_800A6804, &D_800A6810, &D_800A681C,
      &D_800A6828, &D_800A6834, &D_800A6840, &D_800A684C },
};
Battle D_800A687C = { 0, 0, 0x60040000 };
Battle D_800A6888 = { 0, 0, 0x60040000 };
Battle D_800A6894 = { 0, 0, 0x60040000 };
Battle D_800A68A0 = { 0, 0, 0x60040000 };
Battle D_800A68AC = { 0, 0, 0x60040000 };
Battle D_800A68B8 = { 0, 0, 0x60040000 };
Battle D_800A68C4 = { 0, 0, 0x60040000 };
Battle D_800A68D0 = { 0, 0, 0x60040000 };
BattleList D_800A68DC = {
    0,
    { &D_800A687C, &D_800A6888, &D_800A6894, &D_800A68A0,
      &D_800A68AC, &D_800A68B8, &D_800A68C4, &D_800A68D0 },
};
Battle D_800A6900 = { 0, 0, 0x60040000 };
Battle D_800A690C = { 0, 0, 0x60040000 };
Battle D_800A6918 = { 0, 0, 0x60040000 };
Battle D_800A6924 = { 0, 0, 0x60040000 };
Battle D_800A6930 = { 0, 0, 0x60040000 };
Battle D_800A693C = { 0, 0, 0x60040000 };
Battle D_800A6948 = { 0, 0, 0x60040000 };
Battle D_800A6954 = { 0, 0, 0x60040000 };
BattleList D_800A6960 = {
    0,
    { &D_800A6900, &D_800A690C, &D_800A6918, &D_800A6924,
      &D_800A6930, &D_800A693C, &D_800A6948, &D_800A6954 },
};
FieldBattles stageBattles[] = {
    { 78, 0, 0, { &D_800A67D4, &D_800A6858, &D_800A68DC, &D_800A6960 } },
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
u16 D_800A6A30[] = { 0x21F, 1, 0x8494, 1, 0x7013, 1, 0xFFFF };
u16 D_800A6A40[] = { 0x8681, 1, 0xFFFF };
u16 D_800A6A48[] = { 0x8681, 0, 0, 0, 0xFFFF };
u16 D_800A6A54[] = { 0, 1, 0xFFFF };
u16 D_800A6A5C[] = { 0x8681, 0, 0, 1, 0x847D, 0, 0xFFFF };
u16 D_800A6A6C[] = { 0x8681, 0, 0, 1, 0x847D, 1, 0xFFFF };
u16 D_800A6A7C[] = { 0x8681, 1, 0x8680, 0, 0x847D, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A6A90[] = {
    { NULL, D_800A6A30, 0x17F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6AA8[] = {
    { D_800A6A40, NULL, 0x2E2 },
    { D_800A6A48, D_800A6A54, 0x2E3 },
    { D_800A6A5C, NULL, 0x2E4 },
    { D_800A6A6C, D_800A6A7C, 0x2E5 },
    { NULL, NULL, 0 },
};
u16 D_800A6AE4[] = { 0x21F, 0, 0xFFFF };
u16 D_800A6AEC[] = { 0x601D, 1, 0xFFFF };
u16 D_800A6AF4[] = { 0x7043, 1, 0x704B, 1, 0x8680, 1, 0x8681, 0, 0xFFFF };
FieldActorEntry D_800A6B08 = { D_800A6AE4, D_800A6A90, 0x21, 4, 545, 177, 1 };
FieldActorEntry D_800A6B1C = { D_800A6AEC, NULL, 0x83, 5, 128, 178, 1 };
FieldActorEntry D_800A6B30 = { D_800A6AF4, D_800A6AA8, 0xAB, 6, 641, 291, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6B08,
    &D_800A6B1C,
    &D_800A6B30,
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
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x11, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x22F, 0x3C8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x220, 0x372, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x251, 0x2F7, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x260, 0x2A1, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xA, 0x1C0, 0x181, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xA, 0x1D0, 0xDA, 0, 0, 0, 0 },
    { { { 0x601D, 1 }, { 0xFFFF, 0 } }, 8, 0x2F8, 0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 0x11, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 760, D_800A64CC, EVENT_TEXT(0x23), NULL, func_800A6380 },
    { -1, NULL, 0, NULL, NULL },
};
