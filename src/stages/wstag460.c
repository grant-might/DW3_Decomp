#include "common.h"
#include "stage.h"
void func_800A5AF0();
void func_800A5368();
void func_800A4FDC();
extern AnimFrame D_800A6298[];
extern AnimFrame D_800A62C4[];
extern u16 D_800A62F4[];
extern u16 D_800A62FC[];
s32 func_800A5804(s32 x, s32 y);
extern AnimFrame *D_800A6284[];
extern AnimFrame *D_800A628C[];
extern u8 D_800A6294[2][2];
void *func_800A521C(void);
void *func_800A567C(void);
void func_800A5DCC();
extern AnimFrame D_800A6128[];
extern AnimFrame D_800A6168[];
void *func_800A4E8C(s32 id);
void func_800A51D0(StageTileSolo *task, s32 arg1, s32 arg2);
void func_800A5630(StageTileDuo *task, s32 arg1, s32 arg2);
StageWanderer *func_800A5E18(s32 tileAnim, s32 speedIndex, s32 start);

/* Creates the tiles and the seven wanderers; in TASK_DONE makes them all hide and goes back to TASK_RUN */
void func_800A4CA4(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A521C();
        children[1] = func_800A567C();
        children[2] = func_800A5E18(1, 0, 0);
        children[3] = func_800A5E18(2, 0, 0);
        children[4] = func_800A5E18(3, 0, 0);
        children[5] = func_800A5E18(4, 1, 0);
        children[6] = func_800A5E18(5, 1, 0);
        children[7] = func_800A5E18(6, 1, 0);
        children[8] = func_800A5E18(7, 1, 0);
        task->nextState(task);
        break;
    case TASK_RUN:
        break;
    case TASK_DONE:
        func_800A51D0(children[0], 0, 0);
        func_800A5630(children[1], 0, 0);
        func_800A5DCC(children[2], 0, 0);
        func_800A5DCC(children[3], 0, 0);
        func_800A5DCC(children[4], 0, 0);
        func_800A5DCC(children[5], 0, 0);
        func_800A5DCC(children[6], 0, 0);
        func_800A5DCC(children[7], 0, 0);
        func_800A5DCC(children[8], 0, 0);
        task->setState(task, TASK_RUN);
        break;
    case TASK_KILL:
        break;
    }
}

/* Sets the task to TASK_DONE when the id is 0x34C */
void func_800A4E54(Task *task, s32 id) {
    if (task != NULL && id == 0x34C) {
        task->setState(task, TASK_DONE);
    }
}

/* Creates the task of func_800A4CA4 with the given id */
void *func_800A4E8C(s32 id) {
    return createTaskWithId(func_800A4CA4, 0x50, 0x24, id);
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

/* Shows the record with animation 10 (animated) while mode isn't 0, and hides it by a one-shot animation wait frames after mode 2 */
void func_800A4FDC(StageTileSolo *task) {
    StageTile *rec;
    StageTile *tile;
    StageTile *fading;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tile.anim.index = 0;
        task->tile.anim.timer = D_800A6128[0].duration;
        task->tile.anim.index = 0;
        task->tile.anim.timer = D_800A6128[0].duration;
        task->mode = 1;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 10) {
                task->tile.tile = rec;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        tile = task->tile.tile;
        if (task->mode != 0) {
            tile->visible = 1;
            tile->frame = 0x3C;
            tile->clutRow = stepTileAnimation(&task->tile, D_800A6128, 0, 0);
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
            task->tile.anim.timer = D_800A6168[0].duration;
            task->setSubstate(task, 1);
        }
        fading = task->tile.tile;
        frame = stepTileAnimation(&task->tile, D_800A6168, 1, 0);
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
            fading->frame = 0x3D;
            fading->clutRow = frame;
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Makes the StageTileSolo hide in 20 frames */
void func_800A51D0(StageTileSolo *task, s32 arg1, s32 arg2) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x14;
    }
}

void *func_800A51EC(s32 arg) {
    return createTaskWithId(func_800A4FDC, 0x5C, 0, arg);
}

void *func_800A521C(void) {
    return createTask(func_800A4FDC, 0x5C, 0);
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

void func_800A5368(StageTileDuo *task) {
    StageTile *tile;
    StageTile *rec;
    StageTile *fading;
    s32 i;
    s32 j;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = D_800A6284[0]->duration;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = D_800A6284[1]->duration;
        task->mode = 1;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 8:
                task->tiles[0].tile = rec;
                break;
            case 9:
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
                tile->clutRow = stepTileAnimation2(&task->tiles[i], D_800A6284[i], 0, 0);
                tile->frame = D_800A6294[0][i];
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
            task->tiles[0].anim.timer = D_800A628C[0]->duration;
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A628C[1]->duration;
            task->setSubstate(task, 1);
        }
        for (j = 0; j < 2; j++) {
            fading = task->tiles[j].tile;
            frame = stepTileAnimation2(&task->tiles[j], D_800A628C[j], 1, 0);
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
                fading->frame = D_800A6294[1][j];
                fading->clutRow = frame;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Makes the StageTileDuo hide in 150 frames */
void func_800A5630(StageTileDuo *task, s32 arg1, s32 arg2) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x96;
    }
}

void *func_800A564C(s32 arg) {
    return createTaskWithId(func_800A5368, 0x64, 0, arg);
}

void *func_800A567C(void) {
    return createTask(func_800A5368, 0x64, 0);
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

/* Whether the wanderer is more than dist from home (in x + y) */
s32 func_800A57C8(StageWanderer *task, s32 dist) {
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

/* The angle of (x, y), 0x100 a turn, from the table of tangents D_800A62FC */
s32 func_800A5804(s32 x, s32 y) {
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
        if (D_800A62FC[i] <= ratio && ratio <= D_800A62FC[i + 1]) {
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

/* Moves the wanderer, turning it every period frames */
void func_800A5974(StageWanderer *task) {
    s32 dx;
    s32 dy;

    task->timer += GFX.funcs.getFrameTime();
    if (task->period < task->timer) {
        if (func_800A57C8(task, 0x1E)) {
            task->angle = ((func_800A5804(task->homeX - task->posX, task->homeY - task->posY) - 0x40) << 4) & 0xFFF;
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

/* Wanders; when done, plays the animation of D_800A62C4 once and hides */
void func_800A5AF0(StageWanderer *task) {
    StageTile *tile;
    StageTile *rec;
    StageTile *fading;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tile.anim.index = task->start;
        task->tile.anim.timer = D_800A6298[0].duration;
        task->mode = 1;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == task->tileAnim) {
                task->tile.tile = rec;
                task->homeX = rec->x;
                task->homeY = rec->y;
                task->x = rec->x << 8;
                task->y = rec->y << 8;
            }
        }
        task->period = 0x28;
        task->timer = task->start;
        task->speed = D_800A62F4[task->speedIndex];
        task->angle = (RANDOM.next() & 0xFF) << 4;
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->mode != 0) {
            func_800A5974(task);
        }
        tile = task->tile.tile;
        if (task->mode != 0) {
            tile->visible = 1;
            tile->clutRow = stepTileAnimation3(&task->tile, D_800A6298, 0, 0);
            tile->x = task->posX;
            tile->y = task->posY;
        } else {
            tile->visible = 0;
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
            task->tile.anim.index = 0;
            task->tile.anim.timer = D_800A62C4[0].duration;
            task->setSubstate(task, 1);
        }
        func_800A5974(task);
        fading = task->tile.tile;
        frame = stepTileAnimation3(&task->tile, D_800A62C4, 1, 0);
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
        break;
    case TASK_KILL:
        break;
    }
}

/* Makes the wanderer wait 60 frames, then slow down and finish */
void func_800A5DCC(StageWanderer *task) {
    if (task != NULL) {
        task->mode = 2;
        task->wait = 0x3C;
    }
}

void *func_800A5DE8(s32 arg) {
    return createTaskWithId(func_800A5AF0, 0x80, 0, arg);
}

/* Creates a wanderer of the record with the given animation */
StageWanderer *func_800A5E18(s32 tileAnim, s32 speedIndex, s32 start) {
    StageWanderer *task = createTask(func_800A5AF0, sizeof(StageWanderer), 0);

    task->start = start;
    task->speedIndex = speedIndex;
    task->tileAnim = tileAnim;
    return task;
}

/* Creates the task of func_800A4CA4 (id 0x33E) before progress 15 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress < 15) {
            children[0] = func_800A4E8C(0x33E);
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

/* Sets the progress to 15 and applies flag action 0x8010 */
void func_800A5F3C(void) {
    GAME.progress = 15;
    FLAGS_00.applyAction(0x8010, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x354
#define STAGE_ARCHIVE 0x44F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x363
#define STAGE_ARCHIVE 0x45F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xC200, 0x1A500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x10;
    D_800990B4.music = 0x60400000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

void func_800A5F3C();
extern AnimFrame D_800A619C[];
extern AnimFrame D_800A6210[];
extern AnimFrame D_800A61DC[];
extern AnimFrame D_800A6250[];
extern FieldTalk D_800A63C0[];
extern u16 D_800A63D8[];
extern FieldActorEntry D_800A63E0;
extern FieldActorEntry D_800A63F4;
extern s16 D_800A6060[];

s16 D_800A6060[] = {
    0x600, 0, 2,
    0x102, 2, 0x70, 0x188, 3,
    0x100, 0x82, 0x60, 0x16F,
    0x101, 0x82, 1, 7,
    0x101, 0x32D, 0x337, 2,
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
    0x100, 0x82, 0, 0,
    0x101, 0x82, 1, 7,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x101, 0x33E, 0x34C, 2,
    0x300, 0xD2,
    0x200, 0, 3, 2, 3,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0xB0, 0x1A8, 7,
    0x300, 0x3C,
    0x304, 0x235, 0x470, 0xE0, 7,
    0,
};
AnimFrame D_800A6128[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 11, 8 },
    { 12, 8 }, { 13, 8 }, { 14, 8 }, { 255, 0 },
};
AnimFrame D_800A6168[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 11, 8 },
    { 255, 0x3E7 },
};
AnimFrame D_800A619C[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 11, 8 },
    { 12, 8 }, { 13, 8 }, { 14, 8 }, { 255, 0 },
};
AnimFrame D_800A61DC[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 6, 6 }, { 7, 6 },
    { 8, 6 }, { 9, 6 }, { 10, 6 }, { 11, 6 },
    { 255, 0x3E7 },
};
AnimFrame D_800A6210[] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 3, 8 },
    { 4, 8 }, { 5, 8 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 11, 8 },
    { 12, 8 }, { 13, 8 }, { 14, 8 }, { 255, 0 },
};
AnimFrame D_800A6250[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 6, 6 }, { 7, 6 },
    { 8, 6 }, { 9, 6 }, { 10, 6 }, { 11, 6 },
    { 255, 0x3E7 },
};
AnimFrame *D_800A6284[] = {
    D_800A619C, D_800A6210,
};
AnimFrame *D_800A628C[] = {
    D_800A61DC, D_800A6250,
};
u8 D_800A6294[2][2] = {
    { 62, 63 },
    { 64, 65 },
};
AnimFrame D_800A6298[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 4, 4 }, { 3, 4 },
    { 2, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A62C4[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 8 }, { 7, 8 },
    { 8, 8 }, { 9, 8 }, { 10, 8 }, { 255, 0x3E7 },
};
u16 D_800A62F4[] = {
    96, 80, 72, 64,
};
u16 D_800A62FC[] = {
    0, 0x648, 0xC93, 0x12E2, 0x1936, 0x1F92, 0x259F, 0x2C6B,
    0x32EB, 0x39C7, 0x401F, 0x46D7, 0x4DA7, 0x5491, 0x5B98, 0x62BF,
    0x6A09, 0x7179, 0x7913, 0x80DB, 0x88B5, 0x9105, 0x9970, 0xA21B,
    0xAB0D, 0xB44A, 0xBDDC, 0xC7C8, 0xD217, 0xDCD2, 0xE805, 0xF3BA,
    0xFFFE, 0xFFFF,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x17A, 0x1D8, 0xE8, 0xD8, 0x170, 0x1F1 },
};
FieldTalk D_800A63C0[] = {
    { NULL, NULL, 0x33A },
    { NULL, NULL, 0 },
};
u16 D_800A63D8[] = { 0x600E, 1, 0xFFFF };
FieldActorEntry D_800A63E0 = { NULL, D_800A63C0, 0x3F, 4, 250, 109, 1 };
FieldActorEntry D_800A63F4 = { D_800A63D8, NULL, 0x82, 5, 96, 367, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A63E0,
    &D_800A63F4,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 8, 0xFF, 2, 0x3E, 0, 0, 0, 0, 0, 46, 288, 0, 0 },
    { 0, 3, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 52, 288, 0, 0 },
    { 0, 2, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 154, 262, 0, 0 },
    { 0, 1, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 174, 359, 0, 0 },
    { 0, 7, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 103, 297, 0, 0 },
    { 0, 5, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 117, 236, 0, 0 },
    { 0, 6, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 217, 300, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 0xC, 0, 48, 288, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 0xC, 0, 160, 280, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 0xC, 0, 104, 248, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 0xC, 0, 233, 263, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 0xC, 0, 233, 335, 0, 0 },
    { 0, 0xA, 0xFF, 6, 0x3C, 0, 0, 0, 0, 0, 50, 239, 0, 0 },
    { 0, 9, 0xFF, 6, 0x3F, 0, 0, 0, 0, 0, 46, 288, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 240, 72, 135, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0x600E, 1 }, { 0xFFFF, 0 } }, 8, 0x172, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xE, 0xEF, 0xA8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xE, 0xDF, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 370, D_800A6060, EVENT_TEXT(0x28), NULL, func_800A5F3C },
    { -1, NULL, 0, NULL, NULL },
};
