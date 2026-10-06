#include "common.h"
#include "stage.h"
void func_800A561C();
void func_800A5094();
extern AnimFrame D_800A711C[];
extern AnimFrame D_800A7140[];
extern AnimFrame D_800A7160[];
extern AnimFrame D_800A717C[];
extern AnimFrame D_800A73D8[];
extern AnimFrame D_800A73F0[];
extern StageEffectSpot D_800A73C0[];
void *func_800A5498(s32 id);
void *func_800A5A1C(s32 id);
StageEffect *func_800A6758(s32 x, s32 y, s32 frame);
extern AnimFrame D_800A7210[];
extern AnimFrame D_800A7280[];
extern AnimFrame D_800A7328[];
extern AnimFrame D_800A738C[];
extern AnimFrame D_800A719C[];
extern AnimFrame D_800A71D0[];
extern AnimFrame D_800A7204[];
extern AnimFrame D_800A72B4[];
extern AnimFrame D_800A72E8[];
extern AnimFrame D_800A731C[];

#include "common/step_looping_animation.inc.c"

/* Sets the frame of the map objects from four animations, which run once per record */
void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A711C[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A7140[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A7160[0].duration;
        task->anims[3].index = 0;
        task->anims[3].timer = D_800A717C[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A711C, 0);
                break;
            case 2:
                tile->frame = stepLoopingAnimation(&task->anims[1], D_800A7140, 0);
                break;
            case 3:
                tile->frame = stepLoopingAnimation(&task->anims[2], D_800A7160, 0);
                break;
            case 4:
                tile->frame = stepLoopingAnimation(&task->anims[3], D_800A717C, 0);
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x60, 0);
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

/* Animates the records with animations 5 to 10 by mode (0: hidden, 1 and 3: the first two once, then mode 2 or 0; 2, the first: the other four) */
void func_800A5094(StageTileSix *task) {
    StageTile *rec;
    StageTile *tile;
    s32 done;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim >= 5 && rec->anim <= 10) {
                switch (rec->anim) {
                case 5:
                    task->tiles[0].tile = rec;
                    task->tiles[0].anim.index = 0;
                    task->tiles[0].anim.timer = D_800A719C[0].duration;
                    break;
                case 6:
                    task->tiles[1].tile = rec;
                    task->tiles[1].anim.index = 0;
                    task->tiles[1].anim.timer = D_800A71D0[0].duration;
                    break;
                case 7:
                    task->tiles[2].tile = rec;
                    task->tiles[2].anim.index = 0;
                    task->tiles[2].anim.timer = D_800A7204[0].duration;
                    break;
                case 8:
                    task->tiles[3].tile = rec;
                    task->tiles[3].anim.index = 0;
                    task->tiles[3].anim.timer = D_800A7210[0].duration;
                    break;
                case 9:
                    task->tiles[4].tile = rec;
                    task->tiles[4].anim.index = 0;
                    task->tiles[4].anim.timer = 0;
                    break;
                case 10:
                    task->tiles[5].tile = rec;
                    task->tiles[5].anim.index = 0;
                    task->tiles[5].anim.timer = 0;
                    break;
                }
            }
        }
        task->mode = 2;
        task->nextState(task);
        break;
    case TASK_RUN:
        done = 0;
        for (i = 0; i < 6; i++) {
            tile = task->tiles[i].tile;
            switch (task->mode) {
            case 0:
                tile->visible = 0;
                break;
            case 1:
                switch (i) {
                case 0:
                    frame = stepTileAnimation(&task->tiles[0], D_800A719C, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 1:
                    frame = stepTileAnimation(&task->tiles[1], D_800A71D0, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    tile->visible = 0;
                    break;
                }
                break;
            case 2:
                switch (i) {
                case 0:
                case 1:
                    tile->visible = 0;
                    break;
                case 2:
                    tile->frame = 0x28;
                    tile->clutRow = stepTileAnimation(&task->tiles[i], D_800A7204, 0, 0);
                    tile->visible = 1;
                    break;
                case 3:
                    tile->frame = 2;
                    tile->clutRow = stepTileAnimation(&task->tiles[i], D_800A7210, 0, 0);
                    tile->visible = 1;
                    break;
                case 4:
                    tile->visible = 1;
                    tile->frame = 3;
                    tile->clutRow = 0;
                    break;
                case 5:
                    tile->visible = 1;
                    tile->frame = 4;
                    tile->clutRow = 0;
                    break;
                }
                break;
            case 3:
                switch (i) {
                case 0:
                    frame = stepTileAnimation(&task->tiles[0], D_800A7280, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 1:
                    frame = stepTileAnimation(&task->tiles[1], D_800A7280, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    tile->visible = 0;
                    break;
                }
                break;
            }
        }
        if (done >= 2) {
            switch (task->mode) {
            case 1:
                task->mode = 2;
                break;
            case 3:
                task->mode = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Plays the first two records backwards (mode 3) for map 0x359 */
void func_800A545C(StageTileSix *task, s32 id) {
    if (task != NULL && id == 0x359) {
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = D_800A7210[15].duration;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = D_800A7280[0].duration;
        task->mode = 3;
    }
}

/* Creates the task of the six records with id ID, in mode 2 */
void *func_800A5498(s32 id) {
    StageTileSix *task = createTaskWithId(func_800A5094, 0x84, 0, id);

    task->mode = 2;
    return task;
}

void *func_800A54D0(void) {
    return createTask(func_800A5094, 0x84, 0);
}

s32 stepTileAnimation2(StageTileAnimFlag *obj, AnimFrame *frames, s32 once, s32 depth) {
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

/* Animates the records with animations 11 to 16 by mode (0: hidden, 1 and 3: the first two once, then mode 2 or 0; 2, the first: the other four) */
void func_800A561C(StageTileSixW *task) {
    StageTile *rec;
    StageTile *tile;
    s32 done;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim >= 11 && rec->anim <= 16) {
                switch (rec->anim) {
                case 11:
                    task->tiles[0].tile = rec;
                    task->tiles[0].anim.index = 0;
                    task->tiles[0].anim.timer = D_800A72B4[0].duration;
                    break;
                case 12:
                    task->tiles[1].tile = rec;
                    task->tiles[1].anim.index = 0;
                    task->tiles[1].anim.timer = D_800A72E8[0].duration;
                    break;
                case 13:
                    task->tiles[2].tile = rec;
                    task->tiles[2].anim.index = 0;
                    task->tiles[2].anim.timer = D_800A731C[0].duration;
                    break;
                case 14:
                    task->tiles[3].tile = rec;
                    task->tiles[3].anim.index = 0;
                    task->tiles[3].anim.timer = D_800A7328[0].duration;
                    break;
                case 15:
                    task->tiles[4].tile = rec;
                    task->tiles[4].anim.index = 0;
                    task->tiles[4].anim.timer = 0;
                    break;
                case 16:
                    task->tiles[5].tile = rec;
                    task->tiles[5].anim.index = 0;
                    task->tiles[5].anim.timer = 0;
                    break;
                }
            }
        }
        task->mode = 2;
        task->nextState(task);
        break;
    case TASK_RUN:
        done = 0;
        for (i = 0; i < 6; i++) {
            tile = task->tiles[i].tile;
            switch (task->mode) {
            case 0:
                tile->visible = 0;
                break;
            case 1:
                switch (i) {
                case 0:
                    frame = stepTileAnimation2(&task->tiles[0], D_800A72B4, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 1:
                    frame = stepTileAnimation2(&task->tiles[1], D_800A72E8, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    tile->visible = 0;
                    break;
                }
                break;
            case 2:
                switch (i) {
                case 0:
                case 1:
                    tile->visible = 0;
                    break;
                case 2:
                    tile->frame = 0x29;
                    tile->clutRow = stepTileAnimation2(&task->tiles[i], D_800A731C, 0, 0);
                    tile->visible = 1;
                    break;
                case 3:
                    tile->frame = 0x11;
                    tile->clutRow = stepTileAnimation2(&task->tiles[i], D_800A7328, 0, 0);
                    tile->visible = 1;
                    break;
                case 4:
                    tile->visible = 1;
                    tile->frame = 0x12;
                    tile->clutRow = 0;
                    break;
                case 5:
                    tile->visible = 1;
                    tile->frame = 0x13;
                    tile->clutRow = 0;
                    break;
                }
                break;
            case 3:
                switch (i) {
                case 0:
                    frame = stepTileAnimation2(&task->tiles[0], D_800A738C, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 1:
                    frame = stepTileAnimation2(&task->tiles[1], D_800A738C, 1, 0);
                    if (frame != 0xFF) {
                        tile->frame = frame;
                        tile->visible = 1;
                    } else {
                        done++;
                        tile->frame = 0;
                        tile->visible = 0;
                    }
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    tile->visible = 0;
                    break;
                }
                break;
            }
        }
        if (done >= 2) {
            switch (task->mode) {
            case 1:
                task->mode = 2;
                break;
            case 3:
                task->mode = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Plays the first two records backwards (mode 3) for map 0x359 */
void func_800A59E0(StageTileSixW *task, s32 id) {
    if (task != NULL && id == 0x359) {
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = D_800A7328[12].duration;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = D_800A738C[0].duration;
        task->mode = 3;
    }
}

/* Creates the task of the six records with id ID, in mode 2 */
void *func_800A5A1C(s32 id) {
    StageTileSixW *task = createTaskWithId(func_800A561C, 0x9C, 0, id);

    task->mode = 2;
    return task;
}

void *func_800A5A54(void) {
    return createTask(func_800A561C, 0x9C, 0);
}

/* Creates the stage tasks, the sprite effects and the event object of the story so far */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        for (i = 0; i < 2; i++) {
            if (D_800A73C0[i].kind == 0) {
                children[3 + i] = func_800A6758(D_800A73C0[i].x, D_800A73C0[i].y, D_800A73C0[i].frame);
            }
        }
        do {
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(0x404E, 0)) {
                children[5] = FIELDSTG_startEvent(0x2A8);
                break;
            }
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(0x404E, 1) && FLAGS_00.checkCondition(0x404F, 0)) {
                children[5] = FIELDSTG_startEvent(0x2A9);
                children[1] = func_800A5498(0x33F);
                children[2] = func_800A5A1C(0x340);
                break;
            }
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(0x404F, 1)) {
                children[5] = FIELDSTG_startEvent(0x2AA);
                break;
            }
            if (GAME.progress == 0x26) {
                children[5] = FIELDSTG_startEvent(0x3C1);
                break;
            }
        } while (0);
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x18
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"

/* Draws sprite IDX of the effect while it plays (a draw callback) */
void func_800A5DBC(StageEffect *task, void *arg, s32 idx) {
    SpriteDrawer drawer;
    Layer *layer = arg;
    StageSprite *sprite;
    s32 y;
    s32 x;
    s32 depth;

    if (task->state == TASK_RUN) {
        sprite = &task->sprites[idx];
        y = task->y;
        x = task->x;
        if (idx == 1) {
            y -= 0x20;
            depth = 4;
        } else {
            depth = 6;
        }
        initSpriteDrawer(&drawer);
        drawer.setTexture(0x140, 0x100);
        drawer.setLayer(layer, depth);
        drawer.setClutRow(sprite->clutRow);
        drawer.draw(FILE_CACHE.getEntry(D_800990B4.sheetEntry), sprite->frame, x, y);
    }
}

#include "common/is_on_screen.inc.c"

/* An effect that plays its animation once and ends */
void func_800A5F70(StageEffect *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    s32 done;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->key1 = task->x;
        task->key2 = task->y;
        task->anim.index = 0;
        task->anim.timer = D_800A73F0[0].duration;
        task->clutAnim.index = 0;
        task->clutAnim.timer = D_800A73D8[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->substate == 0) {
            task->anim.index = 0;
            task->anim.timer = D_800A73F0[0].duration;
            task->clutAnim.index = 0;
            task->clutAnim.timer = D_800A73D8[0].duration;
            task->setSubstate(task, 1);
        }
        task->sprites[0].frame = task->frame;
        task->sprites[0].clutRow = stepAnimation(&task->clutAnim, D_800A73D8, 0, 0);
        done = 0;
        frame = stepAnimation(&task->anim, D_800A73F0, 1, 0);
        switch (frame) {
        case 0xFF:
            task->sprites[1].frame = 0;
            done = 1;
            break;
        case 0x12C:
            task->sprites[1].frame = 0;
            break;
        default:
            task->sprites[1].frame = task->frame + frame;
            break;
        }
        if (done) {
            task->setState(task, TASK_KILL);
        }
        if (task->sprites[0].frame != 0 && isOnScreen(task->x, task->y, 0x20, 0x20)) {
            layer->addSortedCallback(layer, func_800A5DBC, task, task->y, 0);
        }
        if (task->sprites[1].frame != 0 && isOnScreen(task->x, task->y - 0x20, 0x20, 0x40)) {
            layer->addSortedCallback(layer, func_800A5DBC, task, task->y + 0x12, 1);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

StageEffect *func_800A6190(s32 id) {
    StageEffect *task = createTaskWithId(func_800A5F70, sizeof(StageEffect), 0, id);

    task->x = 0x26C;
    task->y = 0xFC;
    SOUND.playSound(SOUND_TELEPORT);
    task->frame = 0x14;
    return task;
}

s32 stepAnimation2(AnimState *anim, AnimFrame *frames, s32 once, s32 depth) {
    AnimFrame *frame = &frames[anim->index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        anim->timer -= dt;
    }
    if (anim->timer <= 0) {
        frame++;
        anim->index++;
        anim->timer += frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            anim->index = 0;
            anim->timer += frame->duration;
        }
        stepAnimation2(anim, frames, once, depth + 1);
    }
    return frame->frame;
}

#include "common/draw_stage_effect.inc.c"

s32 isOnScreen2(s32 x, s32 y, s32 w, s32 h) {
    RECT rect;
    struct Layer *layer = GFX.funcs.getLayer(0x1002);

    layer->getViewRect(layer, &rect);
    if (x + w < rect.x) {
        return 0;
    }
    if (rect.x + rect.w < x) {
        return 0;
    }
    if (y + h < rect.y) {
        return 0;
    }
    return rect.y + rect.h >= y;
}

/* An effect that plays its animation each time it is set to TASK_DONE */
void updateStageEffect(StageEffect *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    s32 done;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->key1 = task->x;
        task->key2 = task->y;
        task->anim.index = 0;
        task->anim.timer = effectFrames[0].duration;
        task->clutAnim.index = 0;
        task->clutAnim.timer = effectClutFrames[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        task->sprites[0].frame = task->frame;
        task->sprites[0].clutRow = stepAnimation2(&task->clutAnim, effectClutFrames, 0, 0);
        if (task->sprites[0].frame != 0 && isOnScreen2(task->x, task->y, 0x20, 0x20)) {
            layer->addSortedCallback(layer, drawStageEffect, task, task->y, 0);
        }
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->anim.index = 0;
            task->anim.timer = effectFrames[0].duration;
            task->clutAnim.index = 0;
            task->clutAnim.timer = effectClutFrames[0].duration;
            task->setSubstate(task, 1);
        }
        task->sprites[0].frame = task->frame;
        task->sprites[0].clutRow = stepAnimation2(&task->clutAnim, effectClutFrames, 0, 0);
        done = 0;
        frame = stepAnimation2(&task->anim, effectFrames, 1, 0);
        switch (frame) {
        case 0xFF:
            task->sprites[1].frame = 0;
            done = 1;
            break;
        case 0x12C:
            task->sprites[1].frame = 0;
            break;
        default:
            task->sprites[1].frame = task->frame + frame;
            break;
        }
        if (done) {
            task->setState(task, TASK_RUN);
        }
        if (task->sprites[0].frame != 0 && isOnScreen2(task->x, task->y, 0x20, 0x20)) {
            layer->addSortedCallback(layer, drawStageEffect, task, task->y, 0);
        }
        if (task->sprites[1].frame != 0 && isOnScreen2(task->x, task->y - 0x20, 0x20, 0x40)) {
            layer->addSortedCallback(layer, drawStageEffect, task, task->y + 0x12, 1);
        }
        break;
    case TASK_KILL:
        break;
    }
}

StageEffect *func_800A6758(s32 x, s32 y, s32 frame) {
    StageEffect *task = createTask(updateStageEffect, sizeof(StageEffect), 0);

    task->x = x;
    task->y = y;
    task->frame = frame;
    return task;
}

/* Sets flags 0xC13, 0x7401 and 0x404E */
void func_800A67B0(void) {
    FLAGS_00.applyAction(0xC13, 1);
    FLAGS_00.applyAction(0x7401, 1);
    FLAGS_00.applyAction(0x404E, 1);
}

void func_800A6810(void) {
    FLAGS_00.applyAction(0x404F, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A685C(void) {
    FLAGS_00.applyAction(0x4050, 1);
}

void func_800A6888(void) {
    GAME.progress = 39;
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x334
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x343
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13E00, 0x19800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2A;
    D_800990B4.music = 0x60A80000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

void func_800A67B0();
extern Battle D_800A74B8;
extern Battle D_800A74C4;
extern Battle D_800A74D0;
extern Battle D_800A74DC;
extern Battle D_800A74E8;
extern Battle D_800A74F4;
extern Battle D_800A7500;
extern Battle D_800A750C;
extern Battle D_800A753C;
extern Battle D_800A7548;
extern Battle D_800A7554;
extern Battle D_800A7560;
extern Battle D_800A756C;
extern Battle D_800A7578;
extern Battle D_800A7584;
extern Battle D_800A7590;
extern Battle D_800A75C0;
extern Battle D_800A75CC;
extern Battle D_800A75D8;
extern Battle D_800A75E4;
extern Battle D_800A75F0;
extern Battle D_800A75FC;
extern Battle D_800A7608;
extern Battle D_800A7614;
extern Battle D_800A7644;
extern Battle D_800A7650;
extern Battle D_800A765C;
extern Battle D_800A7668;
extern Battle D_800A7674;
extern Battle D_800A7680;
extern Battle D_800A768C;
extern Battle D_800A7698;
extern BattleList D_800A7518;
extern BattleList D_800A759C;
extern BattleList D_800A7620;
extern BattleList D_800A76A4;
extern u16 D_800A77F4[];
extern u16 D_800A77FC[];
extern u16 D_800A7804[];
extern u16 D_800A780C[];
extern u16 D_800A7814[];
extern u16 D_800A781C[];
extern u16 D_800A7828[];
extern u16 D_800A7834[];
extern u16 D_800A7840[];
extern u16 D_800A784C[];
extern u16 D_800A7854[];
extern u16 D_800A785C[];
extern FieldActorEntry D_800A7864;
extern FieldActorEntry D_800A7878;
extern FieldActorEntry D_800A788C;
extern FieldActorEntry D_800A78A0;
extern FieldActorEntry D_800A78B4;
extern FieldActorEntry D_800A78C8;
extern FieldActorEntry D_800A78DC;
extern FieldActorEntry D_800A78F0;
extern FieldActorEntry D_800A7904;
extern FieldActorEntry D_800A7918;
extern FieldActorEntry D_800A792C;
extern FieldActorEntry D_800A7940;
extern s16 D_800A6994[];
extern s16 D_800A6B2C[];
extern s16 D_800A6CD0[];
extern s16 D_800A6EF8[];

s16 D_800A6994[] = {
    0x100, 2, 0x58, 0x20C,
    0x101, 2, 1, 5,
    0x100, 0x6C, 0x23B, 0xEB,
    0x101, 0x6C, 1, 1,
    0x100, 0x6D, 0xA1, 0x1B9,
    0x101, 0x6D, 1, 1,
    0x100, 0x6E, 0xFF, 0x1E9,
    0x101, 0x6E, 1, 1,
    0x100, 0x77, 0xEB, 0x1C4,
    0x101, 0x77, 1, 1,
    0x100, 0x110, 0x280, 0x109,
    0x101, 0x110, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x78, 0x1FC, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x301,
    0x300, 0x1E,
    0x600, 0, 0x6C,
    0x300, 0x78,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x78,
    0x200, 0, 3, 2, 2,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xB0, 0x1E0, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x6D,
    0x101, 0x324, 0x325, 0x6E,
    0x101, 0x325, 0x325, 0x77,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x6D,
    0x101, 0x324, 0x326, 0x6E,
    0x101, 0x325, 0x326, 0x77,
    0x300, 0x1E,
    0x102, 0x6D, 0xB8, 0x1C4, 0,
    0x102, 0x6E, 0xE7, 0x1DC, 2,
    0x102, 0x77, 0xD0, 0x1D0, 1,
    0x302, 0x77,
    0x200, 0, 4, 0x6D, 2,
    0x101, 0x6D, 1, 0,
    0x101, 0x6E, 1, 2,
    0x101, 0x77, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x6E, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x77, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A6B2C[] = {
    0x100, 2, 0xB0, 0x1E0,
    0x101, 2, 1, 5,
    0x100, 0x6C, 0x23B, 0xEB,
    0x101, 0x6C, 1, 1,
    0x100, 0x110, 0x280, 0x109,
    0x101, 0x110, 1, 1,
    0x300, 0x78,
    0x200, 0, 0xA, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x170, 0x180, 5,
    0x302, 2,
    0x102, 2, 0x1B0, 0x130, 5,
    0x101, 0x6C, 1, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x369, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x600, 0, 0x6C,
    0x300, 0x3C,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x6C, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x6C, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x354, 0x335, 2,
    0x300, 0x3C,
    0x100, 0x110, 0, 0,
    0x101, 0x110, 1, 0,
    0x300, 0x1E,
    0x300, 0x1E,
    0x600, 0, 2,
    0x102, 2, 0x20C, 0x102, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x301,
    0x101, 0x323, 0x325, 0x6C,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 0x33F, 0x359, 2,
    0x300, 0x12,
    0x101, 0x340, 0x359, 2,
    0x300, 0x48,
    0x200, 0, 7, 0x6C, 0,
    0x101, 0x6C, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 0x6C, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A6CD0[] = {
    0x601, 1, 0x20C, 0x108,
    0x100, 2, 0x20C, 0x102,
    0x101, 2, 1, 5,
    0x100, 0x65, 0x150, 0x190,
    0x101, 0x65, 1, 5,
    0x100, 0x6C, 0x23B, 0xEB,
    0x101, 0x6C, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x6C, 0,
    0x301,
    0x300, 0x1E,
    0x100, 0xC, 0x150, 0x190,
    0x101, 0xC, 1, 5,
    0x102, 0x65, 0x170, 0x180, 5,
    0x302, 0x65,
    0x102, 0xC, 0x170, 0x180, 5,
    0x102, 0x65, 0x182, 0x16A, 5,
    0x100, 0x67, 0x150, 0x190,
    0x101, 0x67, 1, 5,
    0x302, 0x65,
    0x102, 0xC, 0x19E, 0x146, 5,
    0x102, 0x65, 0x1B0, 0x130, 5,
    0x302, 0x65,
    0x102, 0xC, 0x1B0, 0x130, 5,
    0x102, 0x65, 0x1D0, 0x120, 5,
    0x302, 0xC,
    0x102, 0xC, 0x1D0, 0x120, 5,
    0x102, 0x65, 0x1F0, 0x110, 5,
    0x302, 0x65,
    0x102, 0xC, 0x1F0, 0x110, 5,
    0x102, 0x65, 0x200, 0x118, 5,
    0x302, 0xC,
    0x102, 0xC, 0x1E0, 0x108, 5,
    0x101, 0x65, 1, 5,
    0x302, 0xC,
    0x200, 0, 2, 0x65, 1,
    0x101, 0xC, 1, 5,
    0x101, 0x65, 1, 4,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 0xC, 2,
    0x101, 0xC, 1, 6,
    0x301,
    0x300, 0x1E,
    0x102, 0x67, 0x170, 0x180, 5,
    0x302, 0x67,
    0x102, 0x67, 0x1B0, 0x130, 5,
    0x302, 0x67,
    0x101, 0xC, 1, 1,
    0x101, 0x65, 1, 1,
    0x102, 0x67, 0x1D0, 0x120, 5,
    0x302, 0x67,
    0x200, 0, 4, 0x67, 3,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 5, 2, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x67, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 0x65, 3,
    0x101, 0x65, 1, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 0x65, 3,
    0x101, 2, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0x65, 1, 5,
    0x301,
    0x300, 0x1E,
    0x304, 0x218, 0x64, 0x64, 0,
    0,
};
s16 D_800A6EF8[] = {
    0x300, 0x1E,
    0x102, 1, 0x128, 0x1A5, 5,
    0x302, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 1, 0,
    0x101, 1, 7, 5,
    0x301,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x3A, 1,
    0x300, 0x78,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x100, 0x110, 0x40, 0x218,
    0x101, 0x110, 1, 5,
    0x100, 0x111, 0x28, 0x224,
    0x101, 0x111, 1, 5,
    0x100, 0x112, 1, 0x238,
    0x101, 0x112, 1, 5,
    0x101, 0x323, 0x325, 1,
    0x300, 0x1E,
    0x601, 1, 0x60, 0x208,
    0x300, 0x5A,
    0x102, 0x112, 0x10, 0x230, 5,
    0x101, 0x323, 0x326, 1,
    0x302, 0x112,
    0x101, 0x110, 1, 4,
    0x101, 0x111, 1, 6,
    0x101, 0x112, 1, 4,
    0x300, 0x1E,
    0x101, 0x110, 1, 5,
    0x101, 0x111, 1, 5,
    0x101, 0x112, 1, 5,
    0x300, 0x1E,
    0x101, 0x110, 1, 6,
    0x101, 0x111, 1, 4,
    0x101, 0x112, 1, 6,
    0x300, 0x1E,
    0x101, 0x110, 1, 5,
    0x101, 0x111, 1, 5,
    0x101, 0x112, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x110,
    0x101, 0x324, 0x325, 0x111,
    0x101, 0x325, 0x325, 0x112,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x110,
    0x101, 0x324, 0x326, 0x111,
    0x101, 0x325, 0x326, 0x112,
    0x300, 0x1E,
    0x101, 0x110, 1, 1,
    0x101, 0x111, 1, 1,
    0x101, 0x112, 1, 1,
    0x300, 0x12,
    0x102, 0x112, 1, 0x238, 1,
    0x302, 0x112,
    0x102, 0x111, 1, 0x238, 1,
    0x100, 0x112, 0, 0,
    0x101, 0x112, 1, 1,
    0x302, 0x111,
    0x102, 0x110, 1, 0x238, 1,
    0x100, 0x111, 0, 0,
    0x101, 0x111, 1, 1,
    0x302, 0x110,
    0x600, 1, 1,
    0x100, 0x110, 0, 0,
    0x101, 0x110, 1, 1,
    0x300, 0x5A,
    0x200, 0, 3, 1, 0,
    0x101, 1, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x102, 1, 0x70, 0x200, 1,
    0x300, 0x1E,
    0x304, 0x218, 0x178, 0xFC, 1,
    0,
};
AnimFrame D_800A711C[] = {
    { 51, 8 }, { 52, 8 }, { 53, 8 }, { 54, 8 },
    { 55, 8 }, { 56, 8 }, { 57, 8 }, { 75, 40 },
    { 255, 0 },
};
AnimFrame D_800A7140[] = {
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 61, 8 },
    { 62, 8 }, { 63, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A7160[] = {
    { 64, 8 }, { 65, 8 }, { 66, 8 }, { 67, 8 },
    { 68, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A717C[] = {
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 72, 8 },
    { 73, 8 }, { 74, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A719C[] = {
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 8, 4 },
    { 9, 4 }, { 10, 4 }, { 11, 4 }, { 12, 4 },
    { 13, 4 }, { 14, 4 }, { 15, 4 }, { 16, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A71D0[] = {
    { 28, 4 }, { 29, 4 }, { 30, 4 }, { 31, 4 },
    { 32, 4 }, { 33, 4 }, { 34, 4 }, { 35, 4 },
    { 36, 4 }, { 37, 4 }, { 38, 4 }, { 39, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A7204[] = {
    { 0, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A7210[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 3, 12 },
    { 4, 12 }, { 5, 12 }, { 6, 12 }, { 7, 12 },
    { 8, 12 }, { 9, 12 }, { 10, 12 }, { 11, 12 },
    { 12, 12 }, { 13, 12 }, { 255, 0 }, { 16, 4 },
    { 15, 4 }, { 14, 4 }, { 13, 4 }, { 12, 4 },
    { 11, 4 }, { 10, 4 }, { 9, 4 }, { 8, 4 },
    { 7, 4 }, { 6, 4 }, { 5, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A7280[] = {
    { 39, 4 }, { 38, 4 }, { 37, 4 }, { 36, 4 },
    { 35, 4 }, { 34, 4 }, { 33, 4 }, { 32, 4 },
    { 31, 4 }, { 30, 4 }, { 29, 4 }, { 28, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A72B4[] = {
    { 76, 4 }, { 77, 4 }, { 78, 4 }, { 79, 4 },
    { 80, 4 }, { 81, 4 }, { 82, 4 }, { 83, 4 },
    { 84, 4 }, { 85, 4 }, { 86, 4 }, { 87, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A72E8[] = {
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 91, 4 },
    { 92, 4 }, { 93, 4 }, { 94, 4 }, { 95, 4 },
    { 96, 4 }, { 97, 4 }, { 98, 4 }, { 99, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A731C[] = {
    { 0, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A7328[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 3, 12 },
    { 4, 12 }, { 5, 12 }, { 6, 12 }, { 7, 12 },
    { 8, 12 }, { 9, 12 }, { 10, 12 }, { 255, 0 },
    { 87, 4 }, { 86, 4 }, { 85, 4 }, { 84, 4 },
    { 83, 4 }, { 82, 4 }, { 81, 4 }, { 80, 4 },
    { 79, 4 }, { 78, 4 }, { 77, 4 }, { 76, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A738C[] = {
    { 99, 4 }, { 98, 4 }, { 97, 4 }, { 96, 4 },
    { 95, 4 }, { 94, 4 }, { 93, 4 }, { 92, 4 },
    { 91, 4 }, { 90, 4 }, { 89, 4 }, { 88, 4 },
    { 255, 0x3E7 },
};
StageEffectSpot D_800A73C0[] = {
    { 20, 0, 492, 188 },
    { 20, 0, 620, 252 },
};
AnimFrame D_800A73D8[] = {
    { 0, 6 }, { 1, 6 }, { 2, 68 }, { 1, 4 },
    { 0, 4 }, { 255, 0 },
};
AnimFrame D_800A73F0[] = {
    { 0x12C, 18 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 5, 4 },
    { 6, 4 }, { 7, 4 }, { 5, 4 }, { 6, 4 },
    { 7, 4 }, { 4, 4 }, { 3, 4 }, { 2, 4 },
    { 1, 4 }, { 255, 0x3E7 },
};
AnimFrame effectClutFrames[] = {
    { 0, 6 }, { 1, 6 }, { 2, 68 }, { 1, 4 },
    { 0, 4 }, { 255, 0 },
};
AnimFrame effectFrames[] = {
    { 0x12C, 18 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 5, 4 },
    { 6, 4 }, { 7, 4 }, { 5, 4 }, { 6, 4 },
    { 7, 4 }, { 4, 4 }, { 3, 4 }, { 2, 4 },
    { 1, 4 }, { 255, 0x3E7 },
};
Battle D_800A74B8 = { 0, 0, 0x60040000 };
Battle D_800A74C4 = { 0, 0, 0x60040000 };
Battle D_800A74D0 = { 0, 0, 0x60040000 };
Battle D_800A74DC = { 0, 0, 0x60040000 };
Battle D_800A74E8 = { 0, 0, 0x60040000 };
Battle D_800A74F4 = { 0, 0, 0x60040000 };
Battle D_800A7500 = { 0, 0, 0x60040000 };
Battle D_800A750C = { 0, 0, 0x60040000 };
BattleList D_800A7518 = {
    0,
    { &D_800A74B8, &D_800A74C4, &D_800A74D0, &D_800A74DC,
      &D_800A74E8, &D_800A74F4, &D_800A7500, &D_800A750C },
};
Battle D_800A753C = { 0, 0, 0x60040000 };
Battle D_800A7548 = { 0, 0, 0x60040000 };
Battle D_800A7554 = { 0, 0, 0x60040000 };
Battle D_800A7560 = { 0, 0, 0x60040000 };
Battle D_800A756C = { 0, 0, 0x60040000 };
Battle D_800A7578 = { 0, 0, 0x60040000 };
Battle D_800A7584 = { 0, 0, 0x60040000 };
Battle D_800A7590 = { 0, 0, 0x60040000 };
BattleList D_800A759C = {
    0,
    { &D_800A753C, &D_800A7548, &D_800A7554, &D_800A7560,
      &D_800A756C, &D_800A7578, &D_800A7584, &D_800A7590 },
};
Battle D_800A75C0 = { 0, 0, 0x60040000 };
Battle D_800A75CC = { 0, 0, 0x60040000 };
Battle D_800A75D8 = { 0, 0, 0x60040000 };
Battle D_800A75E4 = { 0, 0, 0x60040000 };
Battle D_800A75F0 = { 0, 0, 0x60040000 };
Battle D_800A75FC = { 0, 0, 0x60040000 };
Battle D_800A7608 = { 0, 0, 0x60040000 };
Battle D_800A7614 = { 0, 0, 0x60040000 };
BattleList D_800A7620 = {
    0,
    { &D_800A75C0, &D_800A75CC, &D_800A75D8, &D_800A75E4,
      &D_800A75F0, &D_800A75FC, &D_800A7608, &D_800A7614 },
};
Battle D_800A7644 = { 10, 18, 0x608C0000 };
Battle D_800A7650 = { 191, 18, 0x60080000 };
Battle D_800A765C = { 0, 0, 0x60040000 };
Battle D_800A7668 = { 0, 0, 0x60040000 };
Battle D_800A7674 = { 0, 0, 0x60040000 };
Battle D_800A7680 = { 0, 0, 0x60040000 };
Battle D_800A768C = { 0, 0, 0x60040000 };
Battle D_800A7698 = { 0, 0, 0x60040000 };
BattleList D_800A76A4 = {
    0,
    { &D_800A7644, &D_800A7650, &D_800A765C, &D_800A7668,
      &D_800A7674, &D_800A7680, &D_800A768C, &D_800A7698 },
};
FieldBattles stageBattles[] = {
    { 137, 0, 0, { &D_800A7518, &D_800A759C, &D_800A7620, &D_800A76A4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F6, 0x100, 0x2D8, 0, 0x160, 0x1F0 },
    { 0x1C0, 0x100, 0x1F6, 0x120, 0x2D8, 0x20, 0x140, 0x1EF },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x150, 0x1EF },
    { 0x140, 0x100, 0x176, 0x128, 0xD8, 0x28, 0x160, 0x1EF },
    { 0x1C0, 0x100, 0x1F6, 0x140, 0x2D8, 0x40, 0x170, 0x1EF },
    { 0x140, 0x100, 0x176, 0x150, 0xD8, 0x50, 0x140, 0x1EE },
    { 0x140, 0x100, 0x176, 0x178, 0xD8, 0x78, 0x150, 0x1EE },
    { 0x140, 0x100, 0x176, 0x1A0, 0xD8, 0xA0, 0x170, 0x1EE },
    { 0x1C0, 0x100, 0x1E2, 0x178, 0x288, 0x78, 0x140, 0x1ED },
    { 0x1C0, 0x100, 0x1EA, 0x178, 0x2A8, 0x78, 0x150, 0x1ED },
    { 0x1C0, 0x100, 0x1CA, 0x180, 0x228, 0x80, 0x160, 0x1ED },
};
u16 D_800A77F4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A77FC[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7804[] = { 0x6017, 1, 0xFFFF };
u16 D_800A780C[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7814[] = { 0x6017, 1, 0xFFFF };
u16 D_800A781C[] = { 0x404E, 0, 0x6017, 1, 0xFFFF };
u16 D_800A7828[] = { 0x404E, 0, 0x6017, 1, 0xFFFF };
u16 D_800A7834[] = { 0x404E, 0, 0x6017, 1, 0xFFFF };
u16 D_800A7840[] = { 0x404F, 0, 0x6017, 1, 0xFFFF };
u16 D_800A784C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7854[] = { 0x6026, 1, 0xFFFF };
u16 D_800A785C[] = { 0x6026, 1, 0xFFFF };
FieldActorEntry D_800A7864 = { D_800A77F4, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A7878 = { D_800A77FC, NULL, 0xC, 5, 0, 0, 1 };
FieldActorEntry D_800A788C = { D_800A7804, NULL, 0x65, 6, 0, 0, 1 };
FieldActorEntry D_800A78A0 = { D_800A780C, NULL, 0x67, 7, 0, 0, 1 };
FieldActorEntry D_800A78B4 = { D_800A7814, NULL, 0x6C, 8, 571, 235, 1 };
FieldActorEntry D_800A78C8 = { D_800A781C, NULL, 0x6D, 9, 161, 441, 1 };
FieldActorEntry D_800A78DC = { D_800A7828, NULL, 0x6E, 0xA, 255, 489, 1 };
FieldActorEntry D_800A78F0 = { D_800A7834, NULL, 0x77, 0xB, 235, 452, 1 };
FieldActorEntry D_800A7904 = { D_800A7840, NULL, 0x110, 0xC, 640, 265, 1 };
FieldActorEntry D_800A7918 = { D_800A784C, NULL, 0x110, 0xC, 0, 0, 1 };
FieldActorEntry D_800A792C = { D_800A7854, NULL, 0x111, 0xD, 0, 0, 1 };
FieldActorEntry D_800A7940 = { D_800A785C, NULL, 0x112, 0xE, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A7864,
    &D_800A7878,
    &D_800A788C,
    &D_800A78A0,
    &D_800A78B4,
    &D_800A78C8,
    &D_800A78DC,
    &D_800A78F0,
    &D_800A7904,
    &D_800A7918,
    &D_800A792C,
    &D_800A7940,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0x40, 2, 0x33, 0, 0, 0, 0, 0, 584, 125, 0, 0 },
    { 1, 2, 0x40, 2, 0x3A, 0, 0, 0, 0, 0, 592, 144, 0, 0 },
    { 1, 3, 0x40, 2, 0x40, 0, 0, 0, 0, 0, 609, 140, 0, 0 },
    { 1, 4, 0x40, 2, 0x45, 0, 0, 0, 0, 0, 610, 167, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 160, 509, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 392, 457, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 448, 339, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 545, 307, 0, 0 },
    { 0, 6, 0x80, 2, 0x1C, 0, 0, 0, 0, 0, 550, 116, 0, 0 },
    { 0, 0xC, 0xFF, 2, 0x58, 0, 0, 0, 0, 0, 430, 103, 0, 0 },
    { 0, 8, 0x80, 2, 2, 0, 0, 0, 0, 0, 550, 116, 0, 0 },
    { 0, 9, 0x80, 2, 3, 0, 0, 0, 0, 0, 550, 116, 0, 0 },
    { 0, 0xA, 0x80, 2, 4, 0, 0, 0, 0, 0, 550, 116, 0, 0 },
    { 0, 5, 0x80, 2, 5, 0, 0, 0, 0, 0, 550, 116, 0, 0 },
    { 0, 7, 0x80, 2, 0x28, 0, 0, 0, 0, 0, 546, 112, 0, 0 },
    { 0, 0xE, 0xFF, 2, 0x11, 0, 0, 0, 0, 0, 430, 103, 0, 0 },
    { 0, 0xF, 0xFF, 2, 0x12, 0, 0, 0, 0, 0, 430, 103, 0, 0 },
    { 0, 0x10, 0xFF, 2, 0x13, 0, 0, 0, 0, 0, 430, 103, 0, 0 },
    { 0, 0xB, 0xFF, 2, 0x4C, 0, 0, 0, 0, 0, 430, 103, 0, 0 },
    { 0, 0xD, 0xFF, 2, 0x29, 0, 0, 0, 0, 0, 426, 99, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 72, 464, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 178, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 303, 267, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 369, 219, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 392, 328, 386, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 545, 243, 266, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x218, 0x178, 0xFC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 680, D_800A6994, EVENT_TEXT(0xA), NULL, func_800A67B0 },
    { 681, D_800A6B2C, EVENT_TEXT(0xB), NULL, func_800A6810 },
    { 682, D_800A6CD0, EVENT_TEXT(0xC), NULL, func_800A685C },
    { 961, D_800A6EF8, EVENT_TEXT(0x14), NULL, func_800A6888 },
    { -1, NULL, 0, NULL, NULL },
};
