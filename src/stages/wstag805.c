#include "common.h"
#include "stage.h"
void func_800A4F90();
void *func_800A4E60(s32 arg);
StageFloater *func_800A5854(s32 x, s32 y, s32 up);
extern StageFloaterSpot D_800A5F58[];
extern s16 D_800A609C[];
extern StageTileLoopFrame *D_800A6164[];
extern StageFloaterFrame D_800A6174[];
extern StageFloaterFrame D_800A61BC[];
extern StageFloaterFrame D_800A6204[];
extern StageFloaterFrame D_800A625C[];
StageFloater *func_800A5854(s32 x, s32 y, s32 up);
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        SOUND.playSound(0x340004);
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
    drawer.draw(FILE_CACHE.getEntry(D_800990B4.sheetEntry), part->sprite.frame, task->x, task->y);
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
            SOUND.playSound(0x800421BF);
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
            if (FLAGS_00.checkCondition(0x4048, 0) && FLAGS_00.checkCondition(0x4046, 0)) {
                children[2] = FIELDSTG_startEvent(0x370);
                break;
            }
            if (FLAGS_00.checkCondition(0x4048, 0) && FLAGS_00.checkCondition(0x4046, 1) &&
                FLAGS_00.checkCondition(0x4064, 0)) {
                children[2] = FIELDSTG_startEvent(0x371);
                break;
            }
            if (FLAGS_00.checkCondition(0x4048, 1) && FLAGS_00.checkCondition(0x4046, 0) &&
                FLAGS_00.checkCondition(0x4065, 0)) {
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
    FLAGS_00.applyAction(0x4046, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets flag 0x8AF0 */
void func_800A5AB0(void) {
    FLAGS_00.applyAction(0x8AF0, 1);
}

void func_800A5ADC(void) {
    FLAGS_00.applyAction(0x4065, 1);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x2A000, 0x18C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xD;
    D_800990B4.music = 0x60340000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

void func_800A5AB0();
extern Battle D_800A6294;
extern Battle D_800A62A0;
extern Battle D_800A62AC;
extern Battle D_800A62B8;
extern Battle D_800A62C4;
extern Battle D_800A62D0;
extern Battle D_800A62DC;
extern Battle D_800A62E8;
extern Battle D_800A6318;
extern Battle D_800A6324;
extern Battle D_800A6330;
extern Battle D_800A633C;
extern Battle D_800A6348;
extern Battle D_800A6354;
extern Battle D_800A6360;
extern Battle D_800A636C;
extern Battle D_800A639C;
extern Battle D_800A63A8;
extern Battle D_800A63B4;
extern Battle D_800A63C0;
extern Battle D_800A63CC;
extern Battle D_800A63D8;
extern Battle D_800A63E4;
extern Battle D_800A63F0;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A6438;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A6468;
extern Battle D_800A6474;
extern BattleList D_800A62F4;
extern BattleList D_800A6378;
extern BattleList D_800A63FC;
extern BattleList D_800A6480;
extern u16 D_800A6550[];
extern u16 D_800A6558[];
extern u16 D_800A6564[];
extern FieldActorEntry D_800A656C;
extern FieldActorEntry D_800A6580;
extern FieldActorEntry D_800A6594;
extern s16 D_800A5BFC[];
extern s16 D_800A5D10[];
extern s16 D_800A5E9C[];

s16 D_800A5BFC[] = {
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
s16 D_800A5D10[] = {
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
s16 D_800A5E9C[] = {
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
Battle D_800A6294 = { 0, 0, 0x60040000 };
Battle D_800A62A0 = { 0, 0, 0x60040000 };
Battle D_800A62AC = { 0, 0, 0x60040000 };
Battle D_800A62B8 = { 0, 0, 0x60040000 };
Battle D_800A62C4 = { 0, 0, 0x60040000 };
Battle D_800A62D0 = { 0, 0, 0x60040000 };
Battle D_800A62DC = { 0, 0, 0x60040000 };
Battle D_800A62E8 = { 0, 0, 0x60040000 };
BattleList D_800A62F4 = {
    0,
    { &D_800A6294, &D_800A62A0, &D_800A62AC, &D_800A62B8,
      &D_800A62C4, &D_800A62D0, &D_800A62DC, &D_800A62E8 },
};
Battle D_800A6318 = { 0, 0, 0x60040000 };
Battle D_800A6324 = { 0, 0, 0x60040000 };
Battle D_800A6330 = { 0, 0, 0x60040000 };
Battle D_800A633C = { 0, 0, 0x60040000 };
Battle D_800A6348 = { 0, 0, 0x60040000 };
Battle D_800A6354 = { 0, 0, 0x60040000 };
Battle D_800A6360 = { 0, 0, 0x60040000 };
Battle D_800A636C = { 0, 0, 0x60040000 };
BattleList D_800A6378 = {
    0,
    { &D_800A6318, &D_800A6324, &D_800A6330, &D_800A633C,
      &D_800A6348, &D_800A6354, &D_800A6360, &D_800A636C },
};
Battle D_800A639C = { 0, 0, 0x60040000 };
Battle D_800A63A8 = { 0, 0, 0x60040000 };
Battle D_800A63B4 = { 0, 0, 0x60040000 };
Battle D_800A63C0 = { 0, 0, 0x60040000 };
Battle D_800A63CC = { 0, 0, 0x60040000 };
Battle D_800A63D8 = { 0, 0, 0x60040000 };
Battle D_800A63E4 = { 0, 0, 0x60040000 };
Battle D_800A63F0 = { 0, 0, 0x60040000 };
BattleList D_800A63FC = {
    0,
    { &D_800A639C, &D_800A63A8, &D_800A63B4, &D_800A63C0,
      &D_800A63CC, &D_800A63D8, &D_800A63E4, &D_800A63F0 },
};
Battle D_800A6420 = { 22, 18, 0x608C0000 };
Battle D_800A642C = { 0, 0, 0x60040000 };
Battle D_800A6438 = { 0, 0, 0x60040000 };
Battle D_800A6444 = { 0, 0, 0x60040000 };
Battle D_800A6450 = { 0, 0, 0x60040000 };
Battle D_800A645C = { 0, 0, 0x60040000 };
Battle D_800A6468 = { 0, 0, 0x60040000 };
Battle D_800A6474 = { 0, 0, 0x60040000 };
BattleList D_800A6480 = {
    0,
    { &D_800A6420, &D_800A642C, &D_800A6438, &D_800A6444,
      &D_800A6450, &D_800A645C, &D_800A6468, &D_800A6474 },
};
FieldBattles stageBattles[] = {
    { 140, 0, 0, { &D_800A62F4, &D_800A6378, &D_800A63FC, &D_800A6480 } },
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
u16 D_800A6550[] = { 0x6020, 1, 0xFFFF };
u16 D_800A6558[] = { 0x6020, 1, 0x4046, 0, 0xFFFF };
u16 D_800A6564[] = { 0x6020, 1, 0xFFFF };
FieldActorEntry D_800A656C = { D_800A6550, NULL, 1, 4, 0, 0, 0 };
FieldActorEntry D_800A6580 = { D_800A6558, NULL, 0xD2, 5, 360, 197, 3 };
FieldActorEntry D_800A6594 = { D_800A6564, NULL, 0x13C, 6, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A656C,
    &D_800A6580,
    &D_800A6594,
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
    { 880, D_800A5BFC, EVENT_TEXT(3), NULL, func_800A5A64 },
    { 881, D_800A5D10, EVENT_TEXT(4), NULL, func_800A5AB0 },
    { 882, D_800A5E9C, EVENT_TEXT(5), NULL, func_800A5ADC },
    { -1, NULL, 0, NULL, NULL },
};
