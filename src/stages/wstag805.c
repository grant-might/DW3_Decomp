#include "common.h"
#include "stage.h"
StageFloater *func_800A5854(s32 x, s32 y, s32 up);
extern StageFloaterSpot D_800A5F58[];
extern s16 D_800A609C[];
extern StageTileLoopFrame *D_800A6164[];
extern StageFloaterFrame D_800A6174[];
extern StageFloaterFrame D_800A61BC[];
extern StageFloaterFrame D_800A6204[];
extern StageFloaterFrame D_800A625C[];
extern StageTileLoopFrame D_800A610C[];
extern StageTileLoopFrame D_800A60D4[];
extern StageTileLoopFrame D_800A6128[];
extern StageTileLoopFrame D_800A6144[];

/* Creates the 27 floaters; in TASK_DONE sets them moving one after the other */
void func_800A4CA8(StageFloaterChain *task, StageFloaters *children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        for (i = 0; i < 27; i++) {
            children->floaters[i] = func_800A5854(D_800A5F58[i].x, D_800A5F58[i].y, D_800A5F58[i].up);
        }
        break;
    case TASK_RUN:
        break;
    case TASK_DONE:
        if (task->timer >= D_800A609C[task->next] && task->timer < D_800A609C[task->next + 1]) {
            children->floaters[task->next]->setState(children->floaters[task->next], TASK_DONE);
            task->next++;
            if (D_800A609C[task->next] == 0x1000) {
                task->setState(task, TASK_RUN);
            }
        }
        task->timer += GFX.funcs.getFrameTime();
        break;
    case TASK_KILL:
        break;
    }
}

/* Starts the chain when the event of map object 0x335 happens */
void func_800A4E28(StageFloaterChain *task, s32 id) {
    if (task != NULL && id == 0x335) {
        task->next = 0;
        task->timer = 0;
        task->setState(task, TASK_DONE);
    }
}

/* Creates the chain of floaters */
void *func_800A4E60(s32 arg) {
    return createTaskWithId(func_800A4CA8, sizeof(StageFloaterChain), sizeof(StageFloaters), arg);
}

/* Advances a looping animation, returns its frame */
s32 func_800A4E90(StageTileAnim *obj, StageTileLoopFrame *frames, s32 depth) {
    StageTileLoopFrame *frame = &frames[obj->anim.index];
    s32 dt = GFX.funcs.getFrameTime();
    s32 loop;

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
        if (frame->frame == 0xFF) {
            loop = frame->loop;
            frame = &frames[loop];
            obj->anim.index = loop;
            obj->anim.timer += frame->duration;
        }
        func_800A4E90(obj, frames, depth + 1);
    }
    return frame->frame;
}

/* Animates the records with animations 1 to 4: 2 and 3 hidden while running */
void func_800A4F90(StageTileQuad *task) {
    StageTile *rec;
    StageTile *tile;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 1:
                task->anims[0].anim.index = 0;
                task->anims[0].anim.timer = D_800A6164[0]->duration;
                task->anims[0].tile = rec;
                break;
            case 2:
                task->anims[1].anim.index = 0;
                task->anims[1].anim.timer = D_800A6164[1]->duration;
                task->anims[1].tile = rec;
                break;
            case 3:
                task->anims[2].anim.index = 0;
                task->anims[2].anim.timer = D_800A6164[2]->duration;
                task->anims[2].tile = rec;
                break;
            case 4:
                task->anims[3].anim.index = 0;
                task->anims[3].anim.timer = D_800A6164[3]->duration;
                task->anims[3].tile = rec;
                break;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        for (i = 0; i < 4; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                tile->frame = 0x24;
                tile->clutRow = 0;
                break;
            case 1:
                tile->visible = 0;
                break;
            case 2:
                tile->visible = 0;
                break;
            case 3:
                tile->visible = 1;
                tile->frame = 0x13;
                tile->clutRow = func_800A4E90(&task->anims[3], D_800A610C, 0);
                break;
            }
        }
        break;
    case TASK_DONE:
        for (i = 0; i < 4; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                tile->frame = func_800A4E90(&task->anims[0], D_800A60D4, 0);
                tile->clutRow = 0;
                break;
            case 1:
                tile->visible = 1;
                tile->frame = 0x15;
                tile->clutRow = func_800A4E90(&task->anims[1], D_800A6128, 0);
                break;
            case 2:
                tile->visible = 1;
                tile->frame = 0x16;
                frame = func_800A4E90(&task->anims[2], D_800A6144, 0);
                if (frame == 0x12C) {
                    tile->clutRow = 0;
                } else {
                    tile->clutRow = frame;
                }
                break;
            case 3:
                tile->visible = 0;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Plays a sound and starts the records' TASK_DONE animations when the event of map object 0x35B happens */
void func_800A5288(StageTileQuad *task, s32 id) {
    if (task != NULL && id == 0x35B) {
        SOUND.playSound(SOUND_GONDRA_S);
        task->setState(task, TASK_DONE);
    }
}

void *func_800A52E0(s32 arg) {
    return createTaskWithId(func_800A4F90, 0x70, 0, arg);
}

/* Advances a part's animation (adding up its deltas when once), returns its frame */
s32 func_800A5310(StageFloaterPart *obj, StageFloaterFrame *frames, s32 once, s32 depth) {
    StageFloaterFrame *frame = &frames[obj->anim.index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        obj->anim.timer -= dt;
    }
    if (once) {
        obj->value += frame->delta;
    }
    if (obj->anim.timer <= 0) {
        frame++;
        obj->anim.index++;
        obj->anim.timer += frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                obj->anim.index--;
                frame--;
                obj->anim.timer += frame->duration;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        func_800A5310(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

#include "common/is_on_screen.inc.c"

/* Draws a part of a floater */
void func_800A5528(StageFloater *task, Layer *layer, s32 idx) {
    SpriteDrawer drawer;
    StageFloaterPart *part = &task->parts[idx];

    initSpriteDrawer(&drawer);
    drawer.setTexture(0x140, 0x100);
    drawer.setLayer(layer, 10);
    drawer.setClutRow(part->sprite.clutRow);
    drawer.draw(FILE_CACHE.getEntry(FIELDSTG_state.sheetEntry), part->sprite.frame, task->x, task->y);
}

/* A floater: animated in place while running, moving up or down with a sound in TASK_DONE */
void func_800A55E8(StageFloater *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    s32 y8;
    s32 value;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->substate == 0) {
            task->parts[0].anim.index = 0;
            task->parts[0].anim.timer = D_800A6174[0].duration;
            task->parts[1].anim.index = 0;
            task->parts[1].anim.timer = D_800A625C[0].duration;
            task->parts[2].anim.index = 0;
            task->parts[2].anim.timer = D_800A61BC[0].duration;
            task->setSubstate(task, 1);
        }
        task->parts[0].sprite.frame = func_800A5310(&task->parts[0], D_800A6174, 0, 0);
        task->parts[0].sprite.clutRow = func_800A5310(&task->parts[2], D_800A61BC, 0, 0);
        task->parts[1].sprite.frame = 0x28;
        task->parts[1].sprite.clutRow = func_800A5310(&task->parts[1], D_800A625C, 0, 0);
        if (task->parts[0].sprite.frame != 0 && isOnScreen(task->x, task->y, 0x20, 0x64)) {
            func_800A5528(task, layer, 0);
        }
        if (task->parts[1].sprite.frame != 0 && isOnScreen(task->x, task->y, 0x20, 0x64)) {
            func_800A5528(task, layer, 1);
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->parts[0].anim.index = 0;
            task->parts[0].anim.timer = D_800A6204[0].duration;
            task->y8 = task->y << 8;
            task->setSubstate(task, 1);
            SOUND.playSound(SOUND_COMAT103);
        }
        task->parts[0].sprite.frame = func_800A5310(&task->parts[0], D_800A6204, 1, 0);
        task->parts[0].sprite.clutRow = 0;
        if (task->y >= -100 && task->y <= 1000) {
            value = task->parts[0].value;
            y8 = task->y8;
            task->y8 = task->up ? y8 - value : y8 + value;
            task->y = task->y8 >> 8;
        }
        if (task->parts[0].sprite.frame != 0 && isOnScreen(task->x, task->y, 0x20, 0x64)) {
            func_800A5528(task, layer, 0);
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates a floater at (x, y) */
StageFloater *func_800A5854(s32 x, s32 y, s32 up) {
    StageFloater *task = createTask(func_800A55E8, sizeof(StageFloater), 0);

    task->x = x;
    task->y = y;
    task->up = up;
    return task;
}

/* Creates two objects and the event object of flags 0x4046/0x4048 that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        children[0] = func_800A4E60(0x349);
        children[1] = func_800A52E0(0x348);
        do {
            if (FLAGS_00.checkCondition(FLAG(0x40, 0x48), 0) && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 0)) {
                children[2] = FIELDSTG_startEvent(0x370);
                break;
            }
            if (FLAGS_00.checkCondition(FLAG(0x40, 0x48), 0) && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 1) &&
                FLAGS_00.checkCondition(FLAG(0x40, 0x64), 0)) {
                children[2] = FIELDSTG_startEvent(0x371);
                break;
            }
            if (FLAGS_00.checkCondition(FLAG(0x40, 0x48), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 0) &&
                FLAGS_00.checkCondition(FLAG(0x40, 0x65), 0)) {
                children[2] = FIELDSTG_startEvent(0x372);
                break;
            }
        } while (0);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"

void func_800A5A64(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x46), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Sets flag 0x8AF0 */
void func_800A5AB0(void) {
    FLAGS_00.applyAction(ITEM(5, 0xF0), 1);
}

void func_800A5ADC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x65), 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x662
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x151
#define STAGE_FILE 0x672
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x2A000, 0x18C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0xD;
    FIELDSTG_state.music = MUSIC(0xD, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFirstMap(0);
}

s16 script880[] = {
    0x100, 1, 0x2B4, 0x198,
    0x101, 1, 1, 3,
    0x100, 0xD2, 0x168, 0xC5,
    0x101, 0xD2, 1, 3,
    0x300, 0x1E,
    0x102, 1, 0x288, 0x182, 3,
    0x302, 1,
    0x102, 1, 0x248, 0x136, 3,
    0x302, 1,
    0x102, 1, 0x1D8, 0xFE, 3,
    0x302, 1,
    0x200, 0, 5, 0xD2, 3,
    0x101, 1, 1, 3,
    0x301,
    0x101, 1, 0xC, 3,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 1, 1, 3,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 1, 0x188, 0xD6, 3,
    0x302, 1,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 1, 3,
    0x101, 1, 0xC, 3,
    0x301,
    0x101, 0x323, 0x325, 0xD2,
    0x300, 0x3C,
    0x101, 1, 1, 3,
    0x101, 0xD2, 1, 7,
    0x101, 0x323, 0x326, 0xD2,
    0x300, 0x1E,
    0x200, 0, 2, 0xD2, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 1, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0xD2, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script881[] = {
    0x100, 1, 0x188, 0xD6,
    0x101, 1, 1, 3,
    0x100, 0x13C, 0x173, 0xCA,
    0x101, 0x13C, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 1, 2,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x102, 1, 0x17A, 0xCF, 3,
    0x302, 1,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 1,
    0x300, 0x1E,
    0x200, 0, 7, 1, 2,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x3C,
    0x101, 0x348, 0x35B, 1,
    0x300, 0x3C,
    0x200, 0, 3, 1, 4,
    0x301,
    0x101, 0x323, 0x325, 1,
    0x101, 0x32D, 0x369, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 4, 1, 2,
    0x301,
    0x102, 1, 0x160, 0xC2, 3,
    0x302, 1,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x101, 1, 1, 3,
    0x101, 0x323, 0x327, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 6, 1, 3,
    0x301,
    0x300, 0x78,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 2, 1, 3,
    0x301,
    0x300, 0x1E,
    0x601, 0, 0xE0, 0xB2,
    0x101, 0x349, 0x335, 1,
    0x300, 0x12C,
    0x600, 0, 1,
    0x300, 0x1E,
    0x200, 0, 5, 1, 3,
    0x301,
    0x101, 0x32D, 0x372, 1,
    0x300, 0x96,
    0x101, 0x32D, 0x373, 1,
#if VERSION_US
    0x304, 0xE03, 1, 1, 1,
#elif VERSION_EU
    0x304, 0xE04, 1, 1, 1,
#endif
    0,
};
s16 script882[] = {
    0x600, 1, 0xD2,
    0x100, 2, 0, 0,
    0x101, 2, 1, 0,
    0x100, 0xD2, 0x168, 0xC5,
    0x101, 0xD2, 1, 3,
    0x300, 0x1E,
    0x300, 0xB4,
    0x200, 0, 4, 0xD2, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x348, 0x35B, 2,
    0x300, 0x3C,
    0x200, 0, 1, 0xD2, 4,
    0x301,
    0x101, 0x32D, 0x369, 2,
    0x300, 0x96,
    0x601, 0, 0xE0, 0xB2,
    0x101, 0x349, 0x335, 2,
    0x300, 0x12C,
    0x600, 0, 0xD2,
    0x300, 0x1E,
    0x200, 0, 2, 0xD2, 3,
    0x301,
    0x300, 0x5A,
    0x200, 0, 3, 0xD2, 3,
    0x301,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x96,
    0x101, 0x32D, 0x373, 2,
#if VERSION_US
    0x304, 0xE03, 0x15E, 0xCA, 1,
#elif VERSION_EU
    0x304, 0xE04, 0x15E, 0xCA, 1,
#endif
    0,
};
StageFloaterSpot D_800A5F58[] = {
    { 8, 140, 0 },
    { 28, 0x12C, 1 },
    { 48, 120, 0 },
    { 68, 0x118, 1 },
    { 88, 100, 0 },
    { 108, 0x104, 1 },
    { 128, 80, 0 },
    { 148, 240, 1 },
    { 168, 60, 0 },
    { 188, 220, 1 },
    { 208, 40, 1 },
    { 228, 200, 0 },
    { 248, 20, 1 },
    { 0x120, 0, 1 },
    { 0x148, -0x14, 1 },
    { 0x15C, 140, 1 },
    { 0x170, -0x28, 0 },
    { 0x184, 120, 1 },
    { 0x198, -0x3C, 0 },
    { 0x1AC, 100, 1 },
    { 0x1C0, -0x50, 0 },
    { 0x1D4, 80, 1 },
    { 0x1FC, 60, 1 },
    { 0x224, 40, 1 },
    { 0x24C, 20, 1 },
    { 0x274, 0, 1 },
    { 0x29C, -0x14, 1 },
};
s16 D_800A609C[] = {
    0, 4, 12, 16, 24, 28, 36, 40,
    48, 52, 60, 64, 72, 84, 96, 100,
    108, 112, 120, 124, 132, 136, 148, 160,
    172, 184, 196, 0x1000,
};
StageTileLoopFrame D_800A60D4[] = {
    { 23, 4, 0 },
    { 24, 4, 0 },
    { 25, 4, 0 },
    { 26, 4, 0 },
    { 27, 4, 0 },
    { 28, 4, 0 },
    { 29, 4, 0 },
    { 30, 4, 0 },
    { 31, 4, 0 },
    { 32, 4, 0 },
    { 33, 4, 0 },
    { 34, 8, 0 },
    { 35, 8, 0 },
    { 255, 0, 11 },
};
StageTileLoopFrame D_800A610C[] = {
    { 0, 8, 0 },
    { 1, 8, 0 },
    { 2, 8, 0 },
    { 3, 8, 0 },
    { 4, 8, 0 },
    { 5, 8, 0 },
    { 255, 0, 0 },
};
StageTileLoopFrame D_800A6128[] = {
    { 0, 8, 0 },
    { 1, 8, 0 },
    { 2, 8, 0 },
    { 3, 6, 0 },
    { 4, 6, 0 },
    { 5, 6, 0 },
    { 255, 0, 0 },
};
StageTileLoopFrame D_800A6144[] = {
    { 0x12C, 4, 0 },
    { 0, 8, 0 },
    { 1, 8, 0 },
    { 2, 8, 0 },
    { 3, 6, 0 },
    { 4, 6, 0 },
    { 5, 6, 0 },
    { 255, 0, 1 },
};
StageTileLoopFrame *D_800A6164[] = {
    D_800A60D4,
    D_800A6128,
    D_800A6144,
    D_800A610C,
};
StageFloaterFrame D_800A6174[] = {
    { 42, 4, 0 },
    { 42, 4, 0 },
    { 43, 4, 0 },
    { 43, 4, 0 },
    { 44, 4, 0 },
    { 44, 4, 0 },
    { 45, 4, 0 },
    { 45, 4, 0 },
    { 255, 0, 0 },
};
StageFloaterFrame D_800A61BC[] = {
    { 0, 4, 0 },
    { 1, 4, 0 },
    { 0, 4, 0 },
    { 1, 4, 0 },
    { 0, 4, 0 },
    { 1, 4, 0 },
    { 0, 4, 0 },
    { 1, 4, 0 },
    { 255, 0, 0 },
};
StageFloaterFrame D_800A6204[] = {
    { 11, 4, 0 },
    { 12, 4, 0 },
    { 13, 4, 0 },
    { 14, 4, 0 },
    { 15, 4, 0 },
    { 16, 4, 0 },
    { 17, 4, 0 },
    { 17, 4, 0 },
    { 18, 30, 64 },
    { 18, 30, 0 },
    { 255, 0x3E7, 0 },
};
StageFloaterFrame D_800A625C[] = {
    { 0, 8, 0 },
    { 1, 8, 0 },
    { 2, 8, 0 },
    { 3, 8, 0 },
    { 4, 8, 0 },
    { 5, 8, 0 },
    { 255, 0, 0 },
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
Battle area3Battle0 = { 22, 18, MUSIC(0x23, 0) };
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
    { 140, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x159, 0x120, 0x64, 0x20, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x147, 0x100, 0x1C, 0, 0x150, 0x1F5 },
    { 0x140, 0x100, 0x144, 0x1D8, 0x10, 0xD8, 0x160, 0x1F5 },
};
u16 actor0Conditions[] = { PROGRESS(0x20), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x20), 1, FLAG(0x40, 0x46), 0, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x20), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 0 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0xD2, 5, 360, 197, 3 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0x13C, 6, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xFF, 6, 0x13, 0, 0, 0, 0, 0, 235, 78, 0, 0 },
    { 1, 2, 0xFF, 6, 0x15, 0, 0, 0, 0, 0, 235, 78, 0, 0 },
    { 1, 3, 0xFF, 6, 0x16, 0, 0, 0, 0, 0, 235, 78, 0, 0 },
    { 1, 4, 0xFF, 6, 0x17, 0, 0, 0, 0, 0, 235, 78, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 880, script880, EVENT_TEXT(3), NULL, func_800A5A64 },
    { 881, script881, EVENT_TEXT(4), NULL, func_800A5AB0 },
    { 882, script882, EVENT_TEXT(5), NULL, func_800A5ADC },
    { -1, NULL, 0, NULL, NULL },
};
