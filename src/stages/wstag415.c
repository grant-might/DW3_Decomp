#include "common.h"
#include "stage.h"
extern StageFallParams D_800A620C[];
extern AnimFrame D_800A62AC[];
extern AnimFrame D_800A62D4[];
extern AnimFrame D_800A62E4[];

/* The files of the background, which the versions number differently */
#if VERSION_US
#define BG_ARCHIVE 0x74E
#define BG_FILE 0x759
#elif VERSION_EU
#define BG_ARCHIVE 0x75E
#define BG_FILE 0x769
#endif

/* Steps the looping animation of a StageFallBody, returning its frame */
s32 func_800A4CB8(StageFallBody *body, AnimFrame *frames, s32 depth) {
    AnimFrame *frame = &frames[body->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        body->anim.timer -= dt;
    }
    if (body->anim.timer <= 0) {
        frame++;
        body->anim.index++;
        body->anim.timer += frame->duration;
        if (frame->frame == 0xFF) {
            frame = frames;
            body->anim.index = 0;
            body->anim.timer += frame->duration;
        }
        func_800A4CB8(body, frames, depth + 1);
    }
    return frame->frame;
}

/* Draws a StageFaller (a layer callback) */
void func_800A4DAC(StageFaller *task, Layer *layer) {
    SpriteDrawer drawer;

    if (task->state == TASK_RUN) {
        initSpriteDrawer(&drawer);
        drawer.setTexture(0x140, 0x100);
        drawer.setLayer(layer, 4);
        drawer.setClutRow(0);
        drawer.setAltClut(0, 0x1F0);
        drawer.draw(FILE_CACHE.getEntry(FIELDSTG_state.sheetEntry), task->frame, task->x, task->y);
    }
}

/* Updates a StageFaller */
void func_800A4E6C(StageFaller *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    s32 dv;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->body.x = D_800A620C[task->key1].x << 8;
        task->body.y = D_800A620C[task->key1].y << 8;
        task->body.bounced = 0;
        task->body.vy = 0;
        task->body.vx = D_800A620C[task->key1].vx;
        task->nextState(task);
        break;
    case TASK_RUN:
        task->frame = func_800A4CB8(&task->body, D_800A620C[task->key1].frames, 0);
        dv = D_800A620C[task->key1].gravity * GFX.funcs.getFrameTime();
        task->body.x += task->body.vx;
        task->body.vy += dv;
        task->x = task->body.x >> 8;
        task->body.y += task->body.vy;
        task->y = task->body.y >> 8;
        if (D_800A620C[task->key1].bounce != 0 && task->body.bounced == 0 && task->y >= D_800A620C[task->key1].floorY) {
            task->body.y = D_800A620C[task->key1].floorY << 8;
            task->y = D_800A620C[task->key1].floorY;
            task->body.vy = -(task->body.vy / D_800A620C[task->key1].bounce);
            task->body.vx = D_800A620C[task->key1].vx * 3;
            task->body.bounced = 1;
            SOUND.playSound(SOUND_MTL_DOWN);
        }
        if (task->frame != 0) {
            layer->addSortedCallback(layer, func_800A4DAC, task, task->y, 0);
        }
        if (task->y > 0x244) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates the task of func_800A4E6C with the given id, kind 0 */
Task *func_800A50F4(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 0;
    return task;
}

Task *func_800A5128(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 1;
    return task;
}

Task *func_800A5160(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 2;
    return task;
}

Task *func_800A5198(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 3;
    return task;
}

Task *func_800A51D0(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 4;
    return task;
}

Task *func_800A5208(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 5;
    return task;
}

Task *func_800A5240(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 6;
    return task;
}

Task *func_800A5278(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 7;
    return task;
}

Task *func_800A52B0(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 8;
    return task;
}

Task *func_800A52E8(s32 id) {
    Task *task = createTaskWithId(func_800A4E6C, 0x74, 0, id);

    task->key1 = 9;
    return task;
}

/* Steps the animation of a StageMoverBody, holding its last frame, and returns the frame */
s32 func_800A5320(StageMoverBody *body, AnimFrame *frames, s32 depth) {
    AnimFrame *frame = &frames[body->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        body->anim.timer -= dt;
    }
    if (body->anim.timer <= 0) {
        frame++;
        body->anim.index++;
        body->anim.timer += frame->duration;
        if (frame->frame == 0xFF) {
            frame--;
            body->anim.index--;
            body->anim.timer += frame->duration;
        }
        func_800A5320(body, frames, depth + 1);
    }
    return frame->frame;
}

/* Updates a StageMover: falls in mode 1 and plays an animation in modes 2 to 4 */
void func_800A541C(StageMover *task) {
    StageTile *tile;
    StageTile *rec;

    switch (task->state) {
    case TASK_INIT:
    default:
        if (task->key1 == 0) {
            task->body.x = 0x9600;
            task->body.y = 0xE600;
            task->body.mode = 0;
            task->body.vy = 0;
            task->body.vx = 0;
            task->body.timer = 0;
        } else {
            task->body.x = 0x9600;
            task->body.y = 0x1AE00;
            task->body.timer = 0;
            task->body.mode = 0;
            task->x = task->body.x >> 8;
            task->y = task->body.y >> 8;
        }
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->tile = rec;
                rec->x = task->x;
                rec->x = task->y; /* unkA again */
                break;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->body.mode) {
        case 0:
            task->frame = 0x32;
            break;
        case 1:
            task->frame = 0x32;
            task->body.vy += GFX.funcs.getFrameTime() * 0x30;
            task->body.x += task->body.vx;
            task->body.y += task->body.vy;
            task->x = task->body.x >> 8;
            task->y = task->body.y >> 8;
            if (task->y >= 0x1AE) {
                task->body.y = 0x1AE00;
                task->y = 0x1AE;
                if (task->body.vy > 0x200) {
                    SOUND.playSound(SOUND_COMEX114);
                }
                task->body.vy = -(task->body.vy / 6);
            }
            task->body.timer++;
            break;
        case 2:
            task->frame = func_800A5320(&task->body, D_800A62AC, 0);
            if (task->frame == 0x35 && task->substate == 0) {
                SOUND.playSound(SOUND_COMEX112);
                task->substate++;
            }
            if (task->frame == 0x3B && task->substate == 1) {
                SOUND.playSound(SOUND_BULB_000);
                task->substate++;
            }
            break;
        case 3:
            task->frame = func_800A5320(&task->body, D_800A62D4, 0);
            break;
        case 4:
            task->frame = func_800A5320(&task->body, D_800A62E4, 0);
            if (task->frame == 2 && task->substate == 0) {
                SOUND.playSound(SOUND_BULB_001);
                task->substate++;
            }
            if (task->frame == 0x20 && task->substate == 1) {
                SOUND.playSound(SOUND_MTL_DOWN);
                task->substate++;
            }
            if (task->frame == 0x2A && task->substate == 2) {
                SOUND.playSound(SOUND_MTL_DOWN);
                task->step = 0;
                task->substate++;
            }
            if (task->substate == 3 || task->substate == 4) {
                if ((++task->step & 0x1F) == 0) {
                    SOUND.playSound(SOUND_MTL_DOWN);
                    task->step = 0;
                    task->substate++;
                }
            }
            break;
        }
        tile = task->tile;
        tile->frame = task->frame;
        tile->x = task->x;
        tile->y = task->y;
        tile->visible = 1;
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Handles the events 0x331 to 0x334 sent to a StageMover */
void func_800A5850(StageMover *task, s32 id) {
    if (task != NULL) {
        switch (id) {
        case 0x331:
            task->body.x = 0x9600;
            task->body.y = 0xE600;
            task->body.mode = 1;
            task->body.vy = 0;
            task->body.vx = 0;
            task->body.timer = 0;
            break;
        case 0x332:
            SOUND.playSound(SOUND_COMEX105);
            task->body.anim.index = 0;
            task->body.anim.timer = D_800A62AC[0].duration;
            task->body.mode = 2;
            task->substate = 0;
            break;
        case 0x333:
            SOUND.playSound(SOUND_COMEX112);
            task->body.anim.index = 0;
            task->body.anim.timer = D_800A62D4[0].duration;
            task->body.mode = 3;
            break;
        case 0x334:
            task->body.mode = 4;
            task->body.anim.index = 0;
            task->body.anim.timer = D_800A62E4[0].duration;
            task->substate = 0;
            break;
        }
    }
}

/* Creates the task of func_800A541C with the given id, kind 0 */
Task *func_800A595C(s32 id) {
    Task *task = createTaskWithId(func_800A541C, 0x78, 0, id);

    task->key1 = 0;
    return task;
}

Task *func_800A5990(s32 id) {
    Task *task = createTaskWithId(func_800A541C, 0x78, 0, id);

    task->key1 = 1;
    return task;
}

/* Draws a StageScroller: each image twice, the second 0x200 left and 0x100 down */
void func_800A59C8(StageScroller *task) {
    SpriteDrawer drawer;
    s32 pos[2];

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1002, 7);
    drawer.setTexture(0x280, 0);
    drawer.setAltClut(0, 0xF0);
    pos[0] = task->x >> 8;
    pos[1] = (task->y >> 8) + 0x100;
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 2), 0, pos[0], pos[1]);
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 2), 0, pos[0] - 0x200, pos[1] + 0x100);
    drawer.setTexture(0x280, 0x100);
    drawer.setAltClut(0, 0xF8);
    pos[0] = (task->x >> 8) + 0x100;
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 4), 0, pos[0], pos[1]);
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 4), 0, pos[0] - 0x200, pos[1] + 0x100);
}

/* Loads the images of a StageScroller and scrolls it, slowing down to a stop in substate 1 */
void func_800A5B50(StageScroller *task) {
    TimLoader loader;

    switch (task->state) {
    case TASK_INIT:
    default:
        initTimLoader(&loader);
        loader.setImagePos(0x280, 0);
        loader.setClutPos(0, 0xF0);
        loader.loadArchive(FILE_CACHE.load(BG_FILE));
        loader.setImagePos(0x280, 0x100);
        loader.setClutPos(0, 0xF8);
        loader.loadArchive(FILE_CACHE.load(BG_FILE + 1));
        task->nextState(task);
        if (task->key1 != 0) {
            task->nextSubstate(task);
        }
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            task->vx = 0x800;
            task->vy = 0x400;
            break;
        case 1:
            if (task->vx == 0x800) {
                SOUND.playSound(SOUND_GONDRA_B);
            }
            if (task->vx != 0) {
                task->vx -= 0x10;
                task->vy = task->vx / 2;
                if (task->vx < 0) {
                    task->vx = 0;
                    task->vy = 0;
                }
            }
            break;
        }
        task->x += task->vx;
        task->y -= task->vy;
        if (task->x > 0x1FFFF) {
            task->x -= 0x20000;
            task->y += 0x10000;
        }
        func_800A59C8(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Sets the substate of the task to 1 when the id is 0x336 */
void func_800A5D4C(Task *task, s32 id) {
    if (task != NULL && id == 0x336) {
        task->setSubstate(task, 1);
    }
}

/* Creates the task of func_800A5B50 (id 0x32C) of the given kind */
Task *func_800A5D84(s32 kind) {
    Task *task = createTaskWithId(func_800A5B50, 0x60, 0, 0x32C);

    task->key1 = kind;
    return task;
}

/* Creates the event objects of progress 6, which depend on flag 0x4018 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 6) {
            if (FLAGS_00.checkCondition(FLAG(0x40, 0x18), 0)) {
                children[0] = func_800A5D84(0);
                children[1] = FIELDSTG_startEvent(0x96);
            } else {
                children[0] = func_800A5D84(1);
                children[2] = func_800A5990(0x32B);
                children[1] = FIELDSTG_startEvent(0x97);
            }
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

void func_800A5EE0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x18), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x74E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x75E
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.imageFile = STAGE_FILE + 1;
    FIELDSTG_state.start = (Vec2){0x11500, 0x15500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0xD;
    FIELDSTG_state.music = MUSIC(0xD, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_map.setFirstMap(0);
}

s16 script150[] = {
    0x600, 1, 1,
    0x100, 1, 0x114, 0x157,
    0x101, 1, 1, 1,
    0x101, 0x32B, 0x330, 1,
    0x300, 0xB4,
    0x101, 0x32C, 0x336, 0x32C,
    0x303, 0x32C,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 1, 0x3A, 1,
    0x300, 0x3C,
    0x200, 0, 1, 1, 0,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 1, 4,
    0x101, 0x32D, 0x37D, 1,
    0x301,
    0x101, 0x32D, 0x372, 1,
    0x300, 0x3C,
    0x200, 0, 3, 1, 0,
    0x101, 1, 0x33, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x3C,
    0x601, 0, 0xD8, 0x175,
    0x300, 0x3C,
    0x101, 0x330, 0x335, 0x330,
    0x300, 0x5A,
    0x101, 0x331, 0x335, 0x331,
    0x101, 0x337, 0x335, 0x337,
    0x300, 0x3C,
    0x101, 0x332, 0x335, 0x332,
    0x101, 0x334, 0x335, 0x334,
    0x101, 0x336, 0x335, 0x336,
    0x300, 0x3C,
    0x101, 0x333, 0x335, 0x333,
    0x101, 0x339, 0x335, 0x339,
    0x300, 0x3C,
    0x101, 0x335, 0x335, 0x335,
    0x101, 0x338, 0x335, 0x333,
    0x300, 0x3C,
    0x101, 0x32B, 0x331, 0x32B,
    0x300, 0x78,
    0x300, 0x1E,
    0x101, 0x32D, 0x373, 1,
    0x300, 0xC,
    0x200, 0, 4, 1, 0,
    0x101, 1, 0x33, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 0x32B, 0x332, 0x32B,
    0x300, 0x78,
    0x300, 0x78,
    0x101, 0x32B, 0x333, 0x32B,
    0x300, 0xC,
    0,
};
s16 script151[] = {
    0x601, 1, 0xD8, 0x175,
    0x100, 1, 0x114, 0x157,
    0x101, 1, 1, 1,
    0x101, 0x32C, 0x336, 1,
    0x300, 6,
    0x300, 0x54,
    0x101, 0x32B, 0x334, 1,
    0x300, 0x9C,
    0x600, 0, 1,
    0x300, 0x1E,
    0x200, 0, 2, 1, 2,
    0x301,
    0x300, 0x78,
    0x200, 0, 1, 1, 4,
    0x101, 0x32D, 0x37D, 1,
    0x301,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x3C,
    0x304, 0x232, 0x1EF, 0xB9, 1,
    0,
};
AnimFrame D_800A61E4[] = {
    { 70, 8 }, { 71, 8 }, { 72, 8 }, { 73, 8 },
    { 255, 0 },
};
AnimFrame D_800A61F8[] = {
    { 74, 8 }, { 75, 8 }, { 76, 8 }, { 77, 8 },
    { 255, 0 },
};
StageFallParams D_800A620C[] = {
    { D_800A61E4, -0x20, 230, 0, 0x180, 88, 0 },
    { D_800A61F8, 0, 230, 0x1C2, 0x200, 72, 4 },
    { D_800A61E4, 32, 230, 0x19A, 0x180, 88, 8 },
    { D_800A61F8, 64, 230, 0, 0x200, 72, 0 },
    { D_800A61F8, 80, 230, 0, 0x200, 72, 0 },
    { D_800A61E4, 16, 230, 0, 96, 88, 0 },
    { D_800A61F8, 48, 230, 0x1CC, 128, 72, 4 },
    { D_800A61E4, 80, 230, 0x1A4, 96, 88, 8 },
    { D_800A61F8, 112, 230, 0, 128, 72, 0 },
    { D_800A61F8, 140, 230, 0, 128, 72, 0 },
};
AnimFrame D_800A62AC[] = {
    { 50, 5 }, { 52, 5 }, { 53, 5 }, { 54, 40 },
    { 55, 8 }, { 56, 8 }, { 57, 10 }, { 58, 12 },
    { 59, 180 }, { 255, 0 },
};
AnimFrame D_800A62D4[] = {
    { 60, 4 }, { 61, 4 }, { 62, 0x3E7 }, { 255, 0 },
};
AnimFrame D_800A62E4[] = {
    { 1, 4 }, { 2, 4 }, { 3, 4 }, { 4, 4 },
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 8, 4 },
    { 9, 4 }, { 10, 4 }, { 11, 4 }, { 12, 4 },
    { 13, 4 }, { 14, 4 }, { 15, 4 }, { 16, 4 },
    { 17, 4 }, { 18, 4 }, { 19, 4 }, { 20, 4 },
    { 21, 4 }, { 22, 4 }, { 23, 4 }, { 24, 4 },
    { 25, 4 }, { 26, 4 }, { 27, 4 }, { 28, 4 },
    { 29, 4 }, { 30, 4 }, { 31, 4 }, { 32, 4 },
    { 33, 4 }, { 34, 4 }, { 35, 4 }, { 36, 4 },
    { 37, 4 }, { 38, 4 }, { 39, 4 }, { 40, 4 },
    { 41, 4 }, { 42, 4 }, { 43, 4 }, { 44, 4 },
    { 45, 4 }, { 46, 4 }, { 47, 4 }, { 255, 0x3E7 },
};
Battle area0Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area0Battles = {
    0,
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
Battle area3Battle0 = { 323, 10, MUSIC(0x22, 0) };
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
    { 128, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1CC, 0x150, 0x230, 0x50, 0x160, 0x1FF },
};
FieldActorEntry actor0 = { NULL, NULL, 1, 4, 0, 0, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x6E, 6, 0, 0, 0, 0, 0, 0, 225, 318, 0, 0 },
    { 1, 1, 0x94, 4, 0x32, 0, 0, 0, 0, 0, 0, -50, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 150, script150, EVENT_TEXT(4), NULL, func_800A5EE0 },
    { 151, script151, EVENT_TEXT(5), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
