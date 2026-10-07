#include "common.h"
#include "stage.h"
extern AnimFrame D_800A711C[];
extern AnimFrame D_800A7140[];
extern AnimFrame D_800A7160[];
extern AnimFrame D_800A717C[];
extern AnimFrame D_800A73D8[];
extern AnimFrame D_800A73F0[];
extern StageEffectSpot D_800A73C0[];
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
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
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

#include "common/step_tile_animation.inc.c"

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
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
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
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
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
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(FLAG(0x40, 0x4E), 0)) {
                children[5] = FIELDSTG_startEvent(0x2A8);
                break;
            }
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(FLAG(0x40, 0x4E), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x4F), 0)) {
                children[5] = FIELDSTG_startEvent(0x2A9);
                children[1] = func_800A5498(0x33F);
                children[2] = func_800A5A1C(0x340);
                break;
            }
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(FLAG(0x40, 0x4F), 1)) {
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
        drawer.draw(FILE_CACHE.getEntry(FIELDSTG_state.sheetEntry), sprite->frame, x, y);
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
    FLAGS_00.applyAction(FLAG(0xC, 0x13), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(1), 1);
    FLAGS_00.applyAction(FLAG(0x40, 0x4E), 1);
}

void func_800A6810(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x4F), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A685C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x50), 1);
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
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x13E00, 0x19800};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2A;
    FIELDSTG_state.music = MUSIC(0x2A, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script680[] = {
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
s16 script681[] = {
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
s16 script682[] = {
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
s16 script961[] = {
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
Battle area3Battle0 = { 10, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 191, 18, MUSIC(2, 0) };
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
    { 137, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
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
u16 actor0Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x17), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x17), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x17), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x17), 1, CODES_END };
u16 actor5Conditions[] = { FLAG(0x40, 0x4E), 0, PROGRESS(0x17), 1, CODES_END };
u16 actor6Conditions[] = { FLAG(0x40, 0x4E), 0, PROGRESS(0x17), 1, CODES_END };
u16 actor7Conditions[] = { FLAG(0x40, 0x4E), 0, PROGRESS(0x17), 1, CODES_END };
u16 actor8Conditions[] = { FLAG(0x40, 0x4F), 0, PROGRESS(0x17), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x26), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0xC, 5, 0, 0, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0x65, 6, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0x67, 7, 0, 0, 1 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0x6C, 8, 571, 235, 1 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0x6D, 9, 161, 441, 1 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0x6E, 0xA, 255, 489, 1 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0x77, 0xB, 235, 452, 1 };
FieldActorEntry actor8 = { actor8Conditions, NULL, 0x110, 0xC, 640, 265, 1 };
FieldActorEntry actor9 = { actor9Conditions, NULL, 0x110, 0xC, 0, 0, 1 };
FieldActorEntry actor10 = { actor10Conditions, NULL, 0x111, 0xD, 0, 0, 1 };
FieldActorEntry actor11 = { actor11Conditions, NULL, 0x112, 0xE, 0, 0, 1 };
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
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x218, 0x178, 0xFC, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 680, script680, EVENT_TEXT(0xA), NULL, func_800A67B0 },
    { 681, script681, EVENT_TEXT(0xB), NULL, func_800A6810 },
    { 682, script682, EVENT_TEXT(0xC), NULL, func_800A685C },
    { 961, script961, EVENT_TEXT(0x14), NULL, func_800A6888 },
    { -1, NULL, 0, NULL, NULL },
};
