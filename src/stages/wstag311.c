#include "common.h"
#include "stage.h"
void func_800A5644();
void func_800A5094();
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
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
            if (FLAGS_00.checkCondition(0x405E, 0)) {
                children[6] = FIELDSTG_startEvent(0x3A3);
            } else if (FLAGS_00.checkCondition(0x4067, 0)) {
                children[6] = FIELDSTG_startEvent(0x3A4);
            } else if (FLAGS_00.checkCondition(0x405F, 0)) {
                children[6] = FIELDSTG_startEvent(0x3A5);
            } else if (FLAGS_00.checkCondition(0x4060, 0)) {
                children[6] = FIELDSTG_startEvent(0x3A6);
            }
            break;
        case 0x27:
            children[6] = FIELDSTG_startEvent(FLAGS_00.checkCondition(0x406C, 0) ? 0x3D5 : 0x3D6);
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
    FLAGS_00.applyAction(0x405E, 1);
    FLAGS_00.applyAction(0xC33, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A6384(void) {
    FLAGS_00.applyAction(0x4067, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A63D0(void) {
    FLAGS_00.applyAction(0x405F, 1);
}

void func_800A63FC(void) {
    FLAGS_00.applyAction(0x4060, 1);
}

void func_800A6428(void) {
    FLAGS_00.applyAction(0x406C, 1);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13500, 0x19D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2A;
    D_800990B4.music = 0x60A80000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

void func_800A6324();
extern Battle D_800A7344;
extern Battle D_800A7350;
extern Battle D_800A735C;
extern Battle D_800A7368;
extern Battle D_800A7374;
extern Battle D_800A7380;
extern Battle D_800A738C;
extern Battle D_800A7398;
extern Battle D_800A73C8;
extern Battle D_800A73D4;
extern Battle D_800A73E0;
extern Battle D_800A73EC;
extern Battle D_800A73F8;
extern Battle D_800A7404;
extern Battle D_800A7410;
extern Battle D_800A741C;
extern Battle D_800A744C;
extern Battle D_800A7458;
extern Battle D_800A7464;
extern Battle D_800A7470;
extern Battle D_800A747C;
extern Battle D_800A7488;
extern Battle D_800A7494;
extern Battle D_800A74A0;
extern Battle D_800A74D0;
extern Battle D_800A74DC;
extern Battle D_800A74E8;
extern Battle D_800A74F4;
extern Battle D_800A7500;
extern Battle D_800A750C;
extern Battle D_800A7518;
extern Battle D_800A7524;
extern BattleList D_800A73A4;
extern BattleList D_800A7428;
extern BattleList D_800A74AC;
extern BattleList D_800A7530;
extern u16 D_800A7660[];
extern u16 D_800A7668[];
extern u16 D_800A7670[];
extern u16 D_800A7678[];
extern u16 D_800A7680[];
extern u16 D_800A768C[];
extern u16 D_800A7698[];
extern u16 D_800A76A4[];
extern u16 D_800A76AC[];
extern FieldActorEntry D_800A76B8;
extern FieldActorEntry D_800A76CC;
extern FieldActorEntry D_800A76E0;
extern FieldActorEntry D_800A76F4;
extern FieldActorEntry D_800A7708;
extern FieldActorEntry D_800A771C;
extern FieldActorEntry D_800A7730;
extern FieldActorEntry D_800A7744;
extern FieldActorEntry D_800A7758;
extern s16 D_800A6560[];
extern s16 D_800A664C[];
extern s16 D_800A6790[];
extern s16 D_800A6C20[];
extern s16 D_800A6E44[];
extern s16 D_800A6F44[];

s16 D_800A6560[] = {
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
s16 D_800A664C[] = {
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
s16 D_800A6790[] = {
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
s16 D_800A6C20[] = {
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
s16 D_800A6E44[] = {
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
s16 D_800A6F44[] = {
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
Battle D_800A7344 = { 0, 0, 0x60040000 };
Battle D_800A7350 = { 0, 0, 0x60040000 };
Battle D_800A735C = { 0, 0, 0x60040000 };
Battle D_800A7368 = { 0, 0, 0x60040000 };
Battle D_800A7374 = { 0, 0, 0x60040000 };
Battle D_800A7380 = { 0, 0, 0x60040000 };
Battle D_800A738C = { 0, 0, 0x60040000 };
Battle D_800A7398 = { 0, 0, 0x60040000 };
BattleList D_800A73A4 = {
    0,
    { &D_800A7344, &D_800A7350, &D_800A735C, &D_800A7368,
      &D_800A7374, &D_800A7380, &D_800A738C, &D_800A7398 },
};
Battle D_800A73C8 = { 0, 0, 0x60040000 };
Battle D_800A73D4 = { 0, 0, 0x60040000 };
Battle D_800A73E0 = { 0, 0, 0x60040000 };
Battle D_800A73EC = { 0, 0, 0x60040000 };
Battle D_800A73F8 = { 0, 0, 0x60040000 };
Battle D_800A7404 = { 0, 0, 0x60040000 };
Battle D_800A7410 = { 0, 0, 0x60040000 };
Battle D_800A741C = { 0, 0, 0x60040000 };
BattleList D_800A7428 = {
    0,
    { &D_800A73C8, &D_800A73D4, &D_800A73E0, &D_800A73EC,
      &D_800A73F8, &D_800A7404, &D_800A7410, &D_800A741C },
};
Battle D_800A744C = { 0, 0, 0x60040000 };
Battle D_800A7458 = { 0, 0, 0x60040000 };
Battle D_800A7464 = { 0, 0, 0x60040000 };
Battle D_800A7470 = { 0, 0, 0x60040000 };
Battle D_800A747C = { 0, 0, 0x60040000 };
Battle D_800A7488 = { 0, 0, 0x60040000 };
Battle D_800A7494 = { 0, 0, 0x60040000 };
Battle D_800A74A0 = { 0, 0, 0x60040000 };
BattleList D_800A74AC = {
    0,
    { &D_800A744C, &D_800A7458, &D_800A7464, &D_800A7470,
      &D_800A747C, &D_800A7488, &D_800A7494, &D_800A74A0 },
};
Battle D_800A74D0 = { 32, 18, 0x608C0000 };
Battle D_800A74DC = { 198, 18, 0x60080000 };
Battle D_800A74E8 = { 0, 0, 0x60040000 };
Battle D_800A74F4 = { 0, 0, 0x60040000 };
Battle D_800A7500 = { 0, 0, 0x60040000 };
Battle D_800A750C = { 0, 0, 0x60040000 };
Battle D_800A7518 = { 0, 0, 0x60040000 };
Battle D_800A7524 = { 0, 0, 0x60040000 };
BattleList D_800A7530 = {
    0,
    { &D_800A74D0, &D_800A74DC, &D_800A74E8, &D_800A74F4,
      &D_800A7500, &D_800A750C, &D_800A7518, &D_800A7524 },
};
FieldBattles stageBattles[] = {
    { 148, 0, 0, { &D_800A73A4, &D_800A7428, &D_800A74AC, &D_800A7530 } },
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
u16 D_800A7660[] = { 0x6027, 1, 0xFFFF };
u16 D_800A7668[] = { 0x6025, 1, 0xFFFF };
u16 D_800A7670[] = { 0x6025, 1, 0xFFFF };
u16 D_800A7678[] = { 0x6025, 1, 0xFFFF };
u16 D_800A7680[] = { 0x6025, 1, 0xC33, 0, 0xFFFF };
u16 D_800A768C[] = { 0x6025, 1, 0xC33, 0, 0xFFFF };
u16 D_800A7698[] = { 0x6025, 1, 0xC33, 0, 0xFFFF };
u16 D_800A76A4[] = { 0x6027, 1, 0xFFFF };
u16 D_800A76AC[] = { 0x6025, 1, 0x405F, 0, 0xFFFF };
FieldActorEntry D_800A76B8 = { D_800A7660, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A76CC = { D_800A7668, NULL, 0xC, 5, 0, 0, 1 };
FieldActorEntry D_800A76E0 = { D_800A7670, NULL, 0x65, 6, 0, 0, 1 };
FieldActorEntry D_800A76F4 = { D_800A7678, NULL, 0x67, 7, 0, 0, 1 };
FieldActorEntry D_800A7708 = { D_800A7680, NULL, 0xD2, 8, 161, 441, 1 };
FieldActorEntry D_800A771C = { D_800A768C, NULL, 0xD3, 9, 255, 489, 1 };
FieldActorEntry D_800A7730 = { D_800A7698, NULL, 0xD4, 0xA, 235, 452, 1 };
FieldActorEntry D_800A7744 = { D_800A76A4, NULL, 0xD5, 0xB, 0, 0, 1 };
FieldActorEntry D_800A7758 = { D_800A76AC, NULL, 0x102, 0xC, 464, 288, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A76B8,
    &D_800A76CC,
    &D_800A76E0,
    &D_800A76F4,
    &D_800A7708,
    &D_800A771C,
    &D_800A7730,
    &D_800A7744,
    &D_800A7758,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x287, 0x178, 0xFC, 1, 0, 0, 0 },
    { { { 0x6028, 1 }, { 0xFFFF, 0 } }, 0xE, 0x2DD, 0xE0, 0x418, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 931, D_800A6560, EVENT_TEXT(0x10), NULL, func_800A6324 },
    { 932, D_800A664C, EVENT_TEXT(0x11), NULL, func_800A6384 },
    { 933, D_800A6790, EVENT_TEXT(0x12), NULL, func_800A63D0 },
    { 934, D_800A6C20, EVENT_TEXT(0x13), NULL, func_800A63FC },
    { 981, D_800A6E44, EVENT_TEXT(0x18), NULL, func_800A6428 },
    { 982, D_800A6F44, EVENT_TEXT(0x19), NULL, func_800A6454 },
    { -1, NULL, 0, NULL, NULL },
};
