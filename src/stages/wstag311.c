#include "common.h"
#include "stage.h"
extern AnimFrame D_800A700C[];
extern AnimFrame D_800A7030[];
extern AnimFrame D_800A7050[];
extern AnimFrame D_800A706C[];
extern StageEffectSpot D_800A72B0[];
extern AnimFrame D_800A708C[];
extern AnimFrame D_800A70C0[];
extern AnimFrame D_800A7100[];
extern AnimFrame D_800A7170[];
extern AnimFrame D_800A70F4[];
extern AnimFrame D_800A71A4[];
extern AnimFrame D_800A71D8[];
extern AnimFrame D_800A720C[];
extern AnimFrame D_800A7218[];
extern AnimFrame D_800A727C[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A700C[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A7030[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A7050[0].duration;
        task->anims[3].index = 0;
        task->anims[3].timer = D_800A706C[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A700C, 0);
                break;
            case 2:
                tile->frame = stepLoopingAnimation(&task->anims[1], D_800A7030, 0);
                break;
            case 3:
                tile->frame = stepLoopingAnimation(&task->anims[2], D_800A7050, 0);
                break;
            case 4:
                tile->frame = stepLoopingAnimation(&task->anims[3], D_800A706C, 0);
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

/* Animates the records with animations 5 to 10 by mode (0: hidden, 1 and 3: the first two once, then mode 2 or 0; 2: the other four) */
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
                    task->tiles[0].anim.timer = D_800A708C[0].duration;
                    break;
                case 6:
                    task->tiles[1].tile = rec;
                    task->tiles[1].anim.index = 0;
                    task->tiles[1].anim.timer = D_800A70C0[0].duration;
                    break;
                case 7:
                    task->tiles[2].tile = rec;
                    task->tiles[2].anim.index = 0;
                    task->tiles[2].anim.timer = D_800A70F4[0].duration;
                    break;
                case 8:
                    task->tiles[3].tile = rec;
                    task->tiles[3].anim.index = 0;
                    task->tiles[3].anim.timer = D_800A7100[0].duration;
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
        task->mode = 0;
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
                    frame = stepTileAnimation(&task->tiles[0], D_800A708C, 1, 0);
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
                    frame = stepTileAnimation(&task->tiles[1], D_800A70C0, 1, 0);
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
                    tile->clutRow = stepTileAnimation(&task->tiles[i], D_800A70F4, 0, 0);
                    tile->visible = 1;
                    break;
                case 3:
                    tile->frame = 2;
                    tile->clutRow = stepTileAnimation(&task->tiles[i], D_800A7100, 0, 0);
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
                    frame = stepTileAnimation(&task->tiles[0], D_800A7170, 1, 0);
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
                    frame = stepTileAnimation(&task->tiles[1], D_800A7170, 1, 0);
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

/* Restarts the first two records' animations for mode 1 (id 0) or 3 (id 1) */
void func_800A5458(StageTileSix *task, s32 id) {
    if (task != NULL) {
        switch (id) {
        case 0:
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A708C[0].duration;
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A70C0[0].duration;
            task->mode = 1;
            break;
        case 1:
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A7100[15].duration; /* the animation after D_800A7100's */
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A7170[0].duration;
            task->mode = 3;
            break;
        }
    }
}

void *func_800A54C8(s32 arg) {
    return createTaskWithId(func_800A5094, 0x84, 0, arg);
}

void *func_800A54F8(void) {
    return createTask(func_800A5094, 0x84, 0);
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

/* Animates the records with animations 11 to 16 by mode (0: hidden, 1 and 3: the first two once, then mode 2 or 0; 2: the other four) */
void func_800A5644(StageTileSix *task) {
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
                    task->tiles[0].anim.timer = D_800A71A4[0].duration;
                    break;
                case 12:
                    task->tiles[1].tile = rec;
                    task->tiles[1].anim.index = 0;
                    task->tiles[1].anim.timer = D_800A71D8[0].duration;
                    break;
                case 13:
                    task->tiles[2].tile = rec;
                    task->tiles[2].anim.index = 0;
                    task->tiles[2].anim.timer = D_800A720C[0].duration;
                    break;
                case 14:
                    task->tiles[3].tile = rec;
                    task->tiles[3].anim.index = 0;
                    task->tiles[3].anim.timer = D_800A7218[0].duration;
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
        task->mode = 0;
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
                    frame = stepTileAnimation2(&task->tiles[0], D_800A71A4, 1, 0);
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
                    frame = stepTileAnimation2(&task->tiles[1], D_800A71D8, 1, 0);
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
                    tile->clutRow = stepTileAnimation2(&task->tiles[i], D_800A720C, 0, 0);
                    tile->visible = 1;
                    break;
                case 3:
                    tile->frame = 0x11;
                    tile->clutRow = stepTileAnimation2(&task->tiles[i], D_800A7218, 0, 0);
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
                    frame = stepTileAnimation2(&task->tiles[0], D_800A727C, 1, 0);
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
                    frame = stepTileAnimation2(&task->tiles[1], D_800A727C, 1, 0);
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

/* Restarts the first two records' animations for mode 1 (id 0) or 3 (id 1) */
void func_800A5A08(StageTileSix *task, s32 id) {
    if (task != NULL) {
        switch (id) {
        case 0:
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A71A4[0].duration;
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A71D8[0].duration;
            task->mode = 1;
            break;
        case 1:
            task->tiles[0].anim.index = 0;
            task->tiles[0].anim.timer = D_800A7218[12].duration; /* the animation after D_800A7218's */
            task->tiles[1].anim.index = 0;
            task->tiles[1].anim.timer = D_800A727C[0].duration;
            task->mode = 3;
            break;
        }
    }
}

void *func_800A5A78(s32 arg) {
    return createTaskWithId(func_800A5644, 0x84, 0, arg);
}

void *func_800A5AA8(void) {
    return createTask(func_800A5644, 0x84, 0);
}

/* Creates the stage helper task, the sprite effects and the event object of the story so far */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        for (i = 0; i < 3; i++) {
            if (D_800A72B0[i].kind == 0 || (D_800A72B0[i].kind == 2 && GAME.progress >= 0x28)) {
                children[3 + i] = createStageEffect(D_800A72B0[i].x, D_800A72B0[i].y, D_800A72B0[i].frame);
            }
        }
        switch (GAME.progress) {
        case 0x25:
            if (FLAGS_00.checkCondition(FLAG(0x40, 0x5E), 0)) {
                children[6] = FIELDSTG_startEvent(0x3A3);
            } else if (FLAGS_00.checkCondition(FLAG(0x40, 0x67), 0)) {
                children[6] = FIELDSTG_startEvent(0x3A4);
            } else if (FLAGS_00.checkCondition(FLAG(0x40, 0x5F), 0)) {
                children[6] = FIELDSTG_startEvent(0x3A5);
            } else if (FLAGS_00.checkCondition(FLAG(0x40, 0x60), 0)) {
                children[6] = FIELDSTG_startEvent(0x3A6);
            }
            break;
        case 0x27:
            children[6] = FIELDSTG_startEvent(FLAGS_00.checkCondition(FLAG(0x40, 0x6C), 0) ? 0x3D5 : 0x3D6);
            break;
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x1C
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

/* Creates the effect of frame 0x2A at (0x10F, 0x19B), playing, with a sound */
StageEffect *func_800A62A8(s32 id) {
    StageEffect *task = createTaskWithId(updateStageEffect, sizeof(StageEffect), 0, id);

    task->x = 0x10F;
    task->y = 0x19B;
    SOUND.playSound(SOUND_TELEPORT);
    task->frame = 0x2A;
    task->setState(task, TASK_DONE);
    return task;
}

/* Sets flags 0x405E, 0xC33 and 0x7401 */
void func_800A6324(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x5E), 1);
    FLAGS_00.applyAction(FLAG(0xC, 0x33), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(1), 1);
}

void func_800A6384(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x67), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A63D0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x5F), 1);
}

void func_800A63FC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x60), 1);
}

void func_800A6428(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x6C), 1);
}

void func_800A6454(void) {
    GAME.progress = 40;
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x52D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x53D
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x13500, 0x19D00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2A;
    FIELDSTG_state.music = MUSIC(0x2A, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script931[] = {
    0x100, 2, 0x58, 0x20C,
    0x101, 2, 1, 5,
    0x300, 0x78,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0xD0, 0x1D0, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0xD2, 1, 7,
    0x101, 0xD3, 1, 3,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0xD4, 2,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xD3, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0xD2, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script932[] = {
    0x100, 2, 0xD0, 0x1D0,
    0x101, 2, 1, 5,
    0x100, 0x102, 0x1D0, 0x120,
    0x101, 0x102, 1, 1,
    0x300, 0x78,
    0x200, 0, 8, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x150, 0x190, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x369, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x170, 0x160,
    0x200, 0, 1, 0x102, 1,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x102, 0x102, 0x1B0, 0x130, 1,
    0x302, 0x102,
    0x102, 0x102, 0x170, 0x180, 1,
    0x302, 0x102,
    0x101, 0x102, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x102, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x102, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x102, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script933[] = {
    0x601, 1, 0x150, 0x1A0,
    0x100, 2, 0x150, 0x190,
    0x101, 2, 1, 5,
    0x100, 0x102, 0x170, 0x180,
    0x101, 0x102, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x102, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x100, 0x67, 0xA0, 0x1E8,
    0x101, 0x67, 1, 5,
    0x300, 0x1E,
    0x100, 0xC, 0xA0, 0x1E8,
    0x101, 0xC, 1, 5,
    0x102, 0x67, 0xC0, 0x1D8, 5,
    0x302, 0x67,
    0x102, 0xC, 0xC0, 0x1D8, 5,
    0x100, 0x65, 0xA0, 0x1E8,
    0x101, 0x65, 1, 5,
    0x102, 0x67, 0xE0, 0x1C8, 5,
    0x302, 0x67,
    0x101, 0xC, 1, 5,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 3, 0x67, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0xF, 2, 3,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x102, 0xC, 0x110, 0x1B0, 5,
    0x102, 0x65, 0xF0, 0x1C0, 5,
    0x102, 0x67, 0x130, 0x1A0, 5,
    0x302, 0x67,
    0x102, 0xC, 0x130, 0x1A0, 5,
    0x102, 0x65, 0x110, 0x1B0, 5,
    0x102, 0x67, 0x110, 0x190, 3,
    0x302, 0x67,
    0x102, 0xC, 0x150, 0x1B0, 7,
    0x102, 0x65, 0x130, 0x1A0, 5,
    0x101, 0x67, 1, 5,
    0x302, 0x65,
    0x101, 2, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0x65, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0x11, 0x65, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x102, 0,
    0x101, 2, 1, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x65, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x102, 0,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0x65,
    0x101, 0x325, 0x325, 0xC,
    0x101, 0x326, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0x65,
    0x101, 0x325, 0x326, 0xC,
    0x101, 0x326, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 7, 0x65, 1,
    0x101, 2, 1, 1,
    0x101, 0xC, 1, 3,
    0x101, 0x67, 1, 7,
    0x301,
    0x300, 0x1E,
    0x200, 1, 0x12, 0xC, 3,
    0x200, 0, 9, 0x67, 0,
    0x101, 0xC, 7, 3,
    0x301,
    0x102, 2, 0x130, 0x184, 3,
    0x101, 0xC, 1, 3,
    0x302, 2,
    0x101, 2, 1, 7,
    0x102, 0x102, 0x150, 0x190, 1,
    0x302, 0x102,
    0x101, 0x102, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x101, 0xC, 1, 1,
    0x102, 0x65, 0x40, 0x21A, 1,
    0x101, 0x67, 1, 1,
    0x102, 0x102, 0x40, 0x21A, 1,
    0x300, 0x5A,
    0x600, 0, 2,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 2, 1, 0,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 0xC, 0x67, 2,
    0x101, 0x67, 1, 7,
    0x301,
    0x100, 0x65, 0, 0,
    0x101, 0x65, 1, 0,
    0x100, 0x102, 0, 0,
    0x101, 0x102, 1, 0,
    0x300, 0x1E,
    0x200, 0, 8, 0xC, 2,
    0x101, 0xC, 1, 3,
    0x301,
    0x102, 0x67, 0x130, 0x1A0, 7,
    0x302, 0x67,
    0x102, 0xC, 0x130, 0x1A0, 3,
    0x102, 0x67, 0x150, 0x190, 5,
    0x302, 0xC,
    0x101, 2, 1, 7,
    0x102, 0xC, 0x150, 0x190, 5,
    0x102, 0x67, 0x170, 0x180, 5,
    0x302, 0xC,
    0x102, 2, 0x150, 0x190, 5,
    0x102, 0xC, 0x170, 0x180, 5,
    0x102, 0x67, 0x1B0, 0x130, 5,
    0x302, 2,
    0x200, 0, 0xA, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xB, 0xC, 0,
    0x101, 0xC, 7, 1,
    0x301,
    0x101, 0xC, 1, 1,
    0x101, 0x67, 1, 1,
    0x300, 0x1E,
    0x600, 0, 0xC,
    0x200, 0, 0x10, 0x67, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0xC,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0xC,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xC, 0,
    0x101, 0xC, 1, 5,
    0x301,
    0x600, 0, 2,
    0x300, 0x1E,
    0x102, 0xC, 0x1B0, 0x130, 5,
    0x102, 0x67, 0x218, 0xFC, 5,
    0x302, 0xC,
    0x200, 0, 0xE, 2, 2,
    0x102, 0xC, 0x21A, 0xFC, 5,
    0x301,
    0x300, 0x1E,
#if VERSION_US
    0x304, 0xE06, 0x150, 0x190, 5,
#elif VERSION_EU
    0x304, 0xE07, 0x150, 0x190, 5,
#endif
    0,
};
s16 script934[] = {
    0x601, 1, 0x140, 0x188,
    0x100, 2, 0x150, 0x190,
    0x101, 2, 1, 5,
    0x100, 0xC, 0x1EE, 0x114,
    0x101, 0xC, 1, 1,
    0x100, 0x67, 0x1EE, 0x114,
    0x101, 0x67, 1, 1,
    0x300, 0x78,
    0x102, 0xC, 0x1B0, 0x130, 1,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0xC, 1,
    0x101, 0xC, 7, 1,
    0x301,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x102, 0xC, 0x170, 0x180, 1,
    0x302, 0xC,
    0x200, 0, 8, 0xC, 0,
    0x101, 0xC, 7, 1,
    0x301,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x102, 0x67, 0x1B0, 0x130, 1,
    0x302, 0x67,
    0x102, 2, 0x140, 0x188, 5,
    0x102, 0xC, 0x150, 0x190, 1,
    0x102, 0x67, 0x170, 0x180, 1,
    0x302, 0xC,
    0x102, 0xC, 0x160, 0x198, 5,
    0x302, 0xC,
    0x200, 0, 3, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x101, 0xC, 1, 3,
    0x102, 0x67, 0x150, 0x190, 1,
    0x302, 0x67,
    0x101, 2, 1, 1,
    0x101, 0xC, 1, 1,
    0x102, 0x67, 0x70, 0x200, 1,
    0x300, 0x5A,
    0x200, 0, 4, 0xC, 1,
    0x101, 2, 1, 7,
    0x101, 0xC, 7, 3,
    0x301,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 2, 2,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 6, 0xC, 1,
    0x101, 0xC, 7, 3,
    0x301,
    0x101, 0xC, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 2, 2,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x150, 0x190, 1,
    0x302, 2,
    0x102, 2, 0x130, 0x1A0, 1,
    0x102, 0xC, 0x150, 0x190, 1,
    0x302, 2,
    0x102, 2, 0x80, 0x1F8, 1,
    0x102, 0xC, 0x80, 0x1F8, 1,
    0x300, 0x3C,
    0x304, 0x276, 0x58, 0x1CC, 5,
    0,
};
s16 script981[] = {
    0x100, 1, 0x58, 0x20C,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0xEA, 0x1C3, 5,
    0x302, 1,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 0x3A, 7,
    0x300, 0x3C,
    0x200, 0, 1, 1, 1,
    0x101, 1, 1, 7,
    0x301,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x101, 0x346, 0x335, 0x346,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 5, 1, 3,
    0x101, 1, 7, 5,
    0x100, 0xD5, 0x122, 0x1A7,
    0x101, 0xD5, 1, 1,
    0x301,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x300, 0x3C,
    0x200, 0, 2, 0xD5, 4,
    0x301,
    0x200, 0, 3, 1, 1,
    0x101, 1, 0xC, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0xD5, 4,
    0x301,
    0x300, 0x1E,
#if VERSION_US
    0x304, 0xE07, 0xEA, 0x1C3, 5,
#elif VERSION_EU
    0x304, 0xE08, 0xEA, 0x1C3, 5,
#endif
    0,
};
s16 script982[] = {
    0x100, 1, 0xEA, 0x1C3,
    0x101, 1, 1, 5,
    0x100, 0xD5, 0x122, 0x1A7,
    0x101, 0xD5, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 1, 1,
    0x101, 1, 0xC, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x346, 0x335, 1,
    0x300, 0x3C,
    0x100, 0xD5, 0, 0,
    0x101, 0xD5, 1, 1,
    0x300, 0x3C,
    0x300, 0x3C,
    0x200, 0, 6, 1, 1,
    0x301,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x300, 0x1E,
    0x304, 0x288, 0xEA, 0x1C3, 5,
    0,
};
AnimFrame D_800A700C[] = {
    { 51, 8 }, { 52, 8 }, { 53, 8 }, { 54, 8 },
    { 55, 8 }, { 56, 8 }, { 57, 8 }, { 75, 40 },
    { 255, 0 },
};
AnimFrame D_800A7030[] = {
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 61, 8 },
    { 62, 8 }, { 63, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A7050[] = {
    { 64, 8 }, { 65, 8 }, { 66, 8 }, { 67, 8 },
    { 68, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A706C[] = {
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 72, 8 },
    { 73, 8 }, { 74, 8 }, { 75, 40 }, { 255, 0 },
};
AnimFrame D_800A708C[] = {
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 8, 4 },
    { 9, 4 }, { 10, 4 }, { 11, 4 }, { 12, 4 },
    { 13, 4 }, { 14, 4 }, { 15, 4 }, { 16, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A70C0[] = {
    { 28, 4 }, { 29, 4 }, { 30, 4 }, { 31, 4 },
    { 32, 4 }, { 33, 4 }, { 34, 4 }, { 35, 4 },
    { 36, 4 }, { 37, 4 }, { 38, 4 }, { 39, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A70F4[] = {
    { 0, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A7100[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 3, 12 },
    { 4, 12 }, { 5, 12 }, { 6, 12 }, { 7, 12 },
    { 8, 12 }, { 9, 12 }, { 10, 12 }, { 11, 12 },
    { 12, 12 }, { 13, 12 }, { 255, 0 }, { 16, 4 },
    { 15, 4 }, { 14, 4 }, { 13, 4 }, { 12, 4 },
    { 11, 4 }, { 10, 4 }, { 9, 4 }, { 8, 4 },
    { 7, 4 }, { 6, 4 }, { 5, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A7170[] = {
    { 39, 4 }, { 38, 4 }, { 37, 4 }, { 36, 4 },
    { 35, 4 }, { 34, 4 }, { 33, 4 }, { 32, 4 },
    { 31, 4 }, { 30, 4 }, { 29, 4 }, { 28, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A71A4[] = {
    { 76, 4 }, { 77, 4 }, { 78, 4 }, { 79, 4 },
    { 80, 4 }, { 81, 4 }, { 82, 4 }, { 83, 4 },
    { 84, 4 }, { 85, 4 }, { 86, 4 }, { 87, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A71D8[] = {
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 91, 4 },
    { 92, 4 }, { 93, 4 }, { 94, 4 }, { 95, 4 },
    { 96, 4 }, { 97, 4 }, { 98, 4 }, { 99, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A720C[] = {
    { 0, 4 }, { 1, 4 }, { 255, 0 },
};
AnimFrame D_800A7218[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 3, 12 },
    { 4, 12 }, { 5, 12 }, { 6, 12 }, { 7, 12 },
    { 8, 12 }, { 9, 12 }, { 10, 12 }, { 255, 0 },
    { 87, 4 }, { 86, 4 }, { 85, 4 }, { 84, 4 },
    { 83, 4 }, { 82, 4 }, { 81, 4 }, { 80, 4 },
    { 79, 4 }, { 78, 4 }, { 77, 4 }, { 76, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A727C[] = {
    { 99, 4 }, { 98, 4 }, { 97, 4 }, { 96, 4 },
    { 95, 4 }, { 94, 4 }, { 93, 4 }, { 92, 4 },
    { 91, 4 }, { 90, 4 }, { 89, 4 }, { 88, 4 },
    { 255, 0x3E7 },
};
StageEffectSpot D_800A72B0[] = {
    { 20, 0, 492, 188 },
    { 20, 0, 620, 252 },
    { 42, 2, 271, 411 },
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
Battle area3Battle0 = { 32, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 198, 18, MUSIC(2, 0) };
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
    { 148, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1D2, 0x1D8, 0x248, 0xD8, 0x160, 0x1EE },
    { 0x1C0, 0x100, 0x1DA, 0x1D8, 0x268, 0xD8, 0x170, 0x1EE },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x140, 0x1ED },
    { 0x140, 0x100, 0x176, 0x128, 0xD8, 0x28, 0x150, 0x1ED },
    { 0x1C0, 0x100, 0x1DE, 0x1A8, 0x278, 0xA8, 0x160, 0x1ED },
    { 0x1C0, 0x100, 0x1E8, 0x1A8, 0x2A0, 0xA8, 0x170, 0x1ED },
    { 0x1C0, 0x100, 0x1F2, 0x1A8, 0x2C8, 0xA8, 0x140, 0x1EC },
    { 0x180, 0x100, 0x19C, 0x198, 0x170, 0x98, 0x150, 0x1EC },
    { 0x180, 0x100, 0x1A6, 0x1D0, 0x198, 0xD0, 0x160, 0x1EC },
};
u16 actor0Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x25), 1, FLAG(0xC, 0x33), 0, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x25), 1, FLAG(0xC, 0x33), 0, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x25), 1, FLAG(0xC, 0x33), 0, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x25), 1, FLAG(0x40, 0x5F), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0xC, 5, 0, 0, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0x65, 6, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0x67, 7, 0, 0, 1 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0xD2, 8, 161, 441, 1 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0xD3, 9, 255, 489, 1 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0xD4, 0xA, 235, 452, 1 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0xD5, 0xB, 0, 0, 1 };
FieldActorEntry actor8 = { actor8Conditions, NULL, 0x102, 0xC, 464, 288, 1 };
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
    { 0, 0, 0x40, 6, 0x2A, 0, 0, 0, 0, 0, 271, 411, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 72, 464, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 178, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 303, 267, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 369, 219, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 392, 328, 386, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 545, 243, 266, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x287, 0x178, 0xFC, 1, 0, 0, 0 },
    { { { PROGRESS(0x28), 1 }, { CODES_END, 0 } }, 0xE, 0x2DD, 0xE0, 0x418, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 931, script931, EVENT_TEXT(0x10), NULL, func_800A6324 },
    { 932, script932, EVENT_TEXT(0x11), NULL, func_800A6384 },
    { 933, script933, EVENT_TEXT(0x12), NULL, func_800A63D0 },
    { 934, script934, EVENT_TEXT(0x13), NULL, func_800A63FC },
    { 981, script981, EVENT_TEXT(0x18), NULL, func_800A6428 },
    { 982, script982, EVENT_TEXT(0x19), NULL, func_800A6454 },
    { -1, NULL, 0, NULL, NULL },
};
