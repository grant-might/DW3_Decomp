#include "common.h"
#include "stage.h"
#if VERSION_US
#define TIMER_SHEET 0x6EE
#elif VERSION_EU
#define TIMER_SHEET 0x6FE
#endif
void func_800A554C();
void func_800A5208();
void func_800A4DC4();
extern AnimFrame D_800A64C0[];
extern AnimFrame D_800A64CC[];
extern AnimFrame D_800A64F8[];
extern StageEffectSpot D_800A65BC[];
void *func_800A50B4(void);
extern AnimFrame *D_800A65AC[];
extern s16 D_800A65B4[];
extern AnimFrame D_800A6514[];
extern AnimFrame D_800A6560[];

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
        obj->anim.timer += (u8)frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += (u8)frame->duration;
        }
        stepTileAnimation(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

/* Shows the first record animated while running; when done, both */
void func_800A4DC4(StageTilePair16 *task) {
    StageTile *tile;
    StageTile *rec;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->anims[0].anim.index = 0;
                task->anims[0].anim.timer = (u8)D_800A64C0[0].duration;
                task->anims[0].tile = rec;
            }
            if (rec->anim == 2) {
                task->anims[1].anim.index = 0;
                task->anims[1].anim.timer = (u8)D_800A64F8[0].duration;
                task->anims[1].tile = rec;
            }
        }
        task->playing = 0;
        if (task->done == 0) {
            task->nextState(task);
        } else {
            task->anims[0].anim.index = 0;
            task->anims[0].anim.timer = (u8)D_800A64CC[0].duration;
            task->setState(task, TASK_DONE);
        }
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                tile->frame = 0x46;
                tile->clutRow = stepTileAnimation(&task->anims[0], D_800A64C0, 0, 0);
                break;
            case 1:
                tile->visible = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
        for (i = 0; i < 2; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                if (task->playing) {
                    frame = stepTileAnimation(&task->anims[0], D_800A64CC, 1, 0);
                    if (frame == 0xFF) {
                        tile->frame = 0x50;
                        task->playing = 0;
                    } else {
                        tile->frame = frame;
                    }
                } else {
                    tile->frame = 0x50;
                }
                tile->clutRow = 0;
                break;
            case 1:
                tile->visible = 1;
                tile->frame = 0x51;
                tile->clutRow = stepTileAnimation(&task->anims[1], D_800A64F8, 0, 0);
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Plays the first record's one-shot animation when the event of map object 0x35B happens */
void func_800A5038(StageTilePair16 *task, s32 id) {
    if (id == 0x35B) {
        task->playing = 1;
        task->anims[0].anim.index = 0;
        task->anims[0].anim.timer = (u8)D_800A64CC[0].duration;
        task->setState(task, TASK_DONE);
    }
}

void *func_800A5084(s32 arg) {
    return createTaskWithId(func_800A4DC4, 0x64, 0, arg);
}

/* Creates the tile pair object, started in TASK_DONE */
void *func_800A50B4(void) {
    StageTilePair16 *task = createTask(func_800A4DC4, sizeof(StageTilePair16), 0);

    task->done = 1;
    return task;
}

/* stepTileAnimation for a StageTileAnimFlag */
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
        obj->anim.timer += (u8)frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += (u8)frame->duration;
        }
        stepTileAnimation2(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

/* Plays the records with animations 3 and 4 once, then ends */
void func_800A5208(StageTileOnce *task) {
    StageTile *rec;
    StageTile *tile;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 3) {
                task->tiles[0].playing = 0;
                task->tiles[0].tile = rec;
            }
            if (rec->anim == 4) {
                task->tiles[1].playing = 0;
                task->tiles[1].tile = rec;
            }
        }
        task->tiles[0].playing = 1;
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = (u8)D_800A6514[0].duration;
        task->tiles[1].playing = 1;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = (u8)D_800A6560[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->tiles[i].tile;
            if (task->tiles[i].playing) {
                frame = stepTileAnimation2(&task->tiles[i], D_800A65AC[i], 1, 0);
                if (frame == 0xFF) {
                    task->tiles[i].playing = 0;
                    tile->visible = 0;
                } else {
                    tile->visible = 1;
                    if (i == 0) {
                        tile->frame = frame;
                        tile->clutRow = 0;
                    } else {
                        tile->frame = 0x33;
                        tile->clutRow = frame;
                    }
                }
            } else {
                tile->visible = 0;
            }
        }
        if (task->tiles[0].playing == 0 && task->tiles[1].playing == 0) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A53D4(s32 arg) {
    return createTaskWithId(func_800A5208, 0x6C, 0, arg);
}

/* Draws the timer: its frame and the three digits of GAME.countdown */
void func_800A5404(StageTask *task) {
    SpriteDrawer drawer;
    Vec2 scroll;
    s32 i;
    Layer *layer = GFX.funcs.getLayer(0x1002);

    layer->getScroll(layer, &scroll);
    initSpriteDrawer(&drawer);
    drawer.setLayer(layer, 0);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.draw(FILE_CACHE.getEntry(TIMER_SHEET << 16), 1, scroll.x + 0xE0, scroll.y + 0x16);
    scroll.y += 0x19;
    for (i = 0; i < 3; i++) {
        drawer.draw(FILE_CACHE.getEntry(TIMER_SHEET << 16), GAME.countdown[i] + 2, scroll.x + D_800A65B4[i], scroll.y);
    }
}

/* The timer: counts GAME.countdown down while nothing stops it, then starts event 0x5E2 */
void func_800A554C(StageTask *task, void **children) {
    u8 *countdown;

    switch (task->state) {
    case TASK_RUN:
        if (FLAGS_00.checkCondition(0x4043, 0) || D_800990B4.busy != 0 || D_800990B4.battleStarting != 0 ||
            D_800990B4.bannerShown != 0 || D_800990B4.innOpen != 0 || D_800990B4.acting != 0) {
            break;
        }
        func_800A5404(task);
        countdown = GAME.countdown;
        if (countdown[0] != 0 || countdown[1] != 0 || countdown[2] != 0) {
            countdown[3] -= GFX.funcs.getFrameTime();
            if (countdown[3] > 60) {
                countdown[2]--;
                countdown[3] += 60;
                SOUND.playSound(SOUND_COUNT);
            }
            COUNTDOWN_BORROW(countdown);
            break;
        }
        children[0] = FIELDSTG_startEvent(0x5E2);
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A571C(void) {
    return createTask(func_800A554C, 0x54, 0x4);
}

/* Creates the timer, the stage's four effects, the event object of flags 0x4044/0x4045 and one of two objects by flag 0x4061 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A571C();
        for (i = 0; i < 4; i++) {
            if (D_800A65BC[i].kind == 0) {
                children[i + 1] = createStageEffect(D_800A65BC[i].x, D_800A65BC[i].y, D_800A65BC[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x4044, 1) && FLAGS_00.checkCondition(0x4045, 0)) {
            children[7] = FIELDSTG_startEvent(0x367);
        }
        if (FLAGS_00.checkCondition(0x4061, 0)) {
            children[5] = func_800A5084(0x345);
        } else {
            children[5] = func_800A50B4();
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x20
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A5EA4(void) {
    FLAGS_00.applyAction(0x1C0A, 1);
    FLAGS_00.applyAction(0x4061, 1);
}

void func_800A5EF0(void) {
    FLAGS_00.applyAction(0x4044, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A5F3C(void) {
    FLAGS_00.applyAction(0x4045, 1);
    FLAGS_00.applyAction(0x84CB, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6EE
#define STAGE_FILE_8 0x715
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x151
#define STAGE_FILE 0x6FE
#define STAGE_FILE_8 0x725
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 4;
    D_800990B4.start = (Vec2){0x1E500, 0x38700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xD;
    D_800990B4.music = 0x60340000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A665C;
extern Battle D_800A6668;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66E0;
extern Battle D_800A66EC;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6764;
extern Battle D_800A6770;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67E8;
extern Battle D_800A67F4;
extern Battle D_800A6800;
extern Battle D_800A680C;
extern Battle D_800A6818;
extern Battle D_800A6824;
extern Battle D_800A6830;
extern Battle D_800A683C;
extern BattleList D_800A66BC;
extern BattleList D_800A6740;
extern BattleList D_800A67C4;
extern BattleList D_800A6848;
extern u16 D_800A6958[];
extern u16 D_800A6964[];
extern u16 D_800A6970[];
extern u16 D_800A697C[];
extern u16 D_800A6984[];
extern u16 D_800A6A08[];
extern FieldTalk D_800A6990[];
extern u16 D_800A6A10[];
extern FieldTalk D_800A69A8[];
extern u16 D_800A6A18[];
extern FieldTalk D_800A69C0[];
extern u16 D_800A6A20[];
extern FieldTalk D_800A69D8[];
extern u16 D_800A6A28[];
extern FieldTalk D_800A69F0[];
extern u16 D_800A6A30[];
extern u16 D_800A6A3C[];
extern FieldActorEntry D_800A6A44;
extern FieldActorEntry D_800A6A58;
extern FieldActorEntry D_800A6A6C;
extern FieldActorEntry D_800A6A80;
extern FieldActorEntry D_800A6A94;
extern FieldActorEntry D_800A6AA8;
extern FieldActorEntry D_800A6ABC;
extern s16 D_800A609C[];
extern s16 D_800A6184[];
extern s16 D_800A620C[];
extern s16 D_800A646C[];

s16 D_800A609C[] = {
    0x102, 2, 0x3BC, 0x337, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 1, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x377, 2,
    0x300, 0x1E,
    0x101, 0x345, 0x35B, 2,
    0x300, 0x78,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x101, 0x32D, 0x37F, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x3E0, 0x348, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
s16 D_800A6184[] = {
    0x102, 2, 0x590, 0x1B0, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xD0,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0xD0,
    0x300, 0x1E,
    0x101, 0xD0, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 0xD0, 0,
    0x301,
    0x300, 0x1E,
    0x102, 0xD0, 0x5A8, 0x1A4, 1,
    0x302, 0xD0,
    0,
};
s16 D_800A620C[] = {
    0x100, 2, 0x590, 0x1B0,
    0x101, 2, 1, 5,
    0x100, 0x13C, 0x5A8, 0x1A4,
    0x101, 0x13C, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x598, 0x1AC, 5,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 0,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x5F7, 0x17C, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x3C,
    0x101, 2, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x607, 0x184, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x101, 0x32D, 0x377, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x101, 0x347, 0x35B, 2,
    0x300, 0xB4,
    0x200, 0, 5, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 2, 4,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x37D, 2,
    0x301,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x302, 2,
    0,
};
s16 D_800A646C[] = {
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 0,
    0x301,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x304, 0x26D, 1, 1, 1,
    0,
};
AnimFrame D_800A64C0[] = {
    { 0, 8 }, { 1, 8 }, { 255, 0 },
};
AnimFrame D_800A64CC[] = {
    { 71, 4 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 75, 4 }, { 76, 4 }, { 77, 4 }, { 78, 4 },
    { 79, 4 }, { 80, 4 }, { 255, 0 },
};
AnimFrame D_800A64F8[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 255, 0 },
};
AnimFrame D_800A6514[] = {
    { 52, 6 }, { 53, 6 }, { 54, 6 }, { 55, 6 },
    { 56, 6 }, { 57, 6 }, { 58, 6 }, { 59, 6 },
    { 60, 6 }, { 61, 6 }, { 62, 6 }, { 63, 6 },
    { 64, 6 }, { 65, 6 }, { 66, 6 }, { 67, 6 },
    { 68, 6 }, { 69, 6 }, { 255, 0 },
};
AnimFrame D_800A6560[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 0, 6 }, { 1, 6 },
    { 2, 6 }, { 3, 6 }, { 4, 6 }, { 5, 6 },
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 255, 0 },
};
AnimFrame *D_800A65AC[] = {
    D_800A6514, D_800A6560,
};
s16 D_800A65B4[] = {
    226, 253, 0x118, 0,
};
StageEffectSpot D_800A65BC[] = {
    { 28, 0, 0x4BC, 0x273 },
    { 28, 0, 0x39C, 0x373 },
    { 20, 0, 0x2BC, 211 },
    { 20, 0, 0x43C, 0x323 },
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
Battle D_800A665C = { 123, 16, 0x60080000 };
Battle D_800A6668 = { 123, 16, 0x60080000 };
Battle D_800A6674 = { 123, 16, 0x60080000 };
Battle D_800A6680 = { 122, 16, 0x60080000 };
Battle D_800A668C = { 122, 16, 0x60080000 };
Battle D_800A6698 = { 122, 16, 0x60080000 };
Battle D_800A66A4 = { 102, 16, 0x60080000 };
Battle D_800A66B0 = { 102, 16, 0x60080000 };
BattleList D_800A66BC = {
    3,
    { &D_800A665C, &D_800A6668, &D_800A6674, &D_800A6680,
      &D_800A668C, &D_800A6698, &D_800A66A4, &D_800A66B0 },
};
Battle D_800A66E0 = { 0, 0, 0x60040000 };
Battle D_800A66EC = { 0, 0, 0x60040000 };
Battle D_800A66F8 = { 0, 0, 0x60040000 };
Battle D_800A6704 = { 0, 0, 0x60040000 };
Battle D_800A6710 = { 0, 0, 0x60040000 };
Battle D_800A671C = { 0, 0, 0x60040000 };
Battle D_800A6728 = { 0, 0, 0x60040000 };
Battle D_800A6734 = { 0, 0, 0x60040000 };
BattleList D_800A6740 = {
    0,
    { &D_800A66E0, &D_800A66EC, &D_800A66F8, &D_800A6704,
      &D_800A6710, &D_800A671C, &D_800A6728, &D_800A6734 },
};
Battle D_800A6764 = { 0, 0, 0x60040000 };
Battle D_800A6770 = { 0, 0, 0x60040000 };
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
BattleList D_800A67C4 = {
    0,
    { &D_800A6764, &D_800A6770, &D_800A677C, &D_800A6788,
      &D_800A6794, &D_800A67A0, &D_800A67AC, &D_800A67B8 },
};
Battle D_800A67E8 = { 193, 16, 0x60080000 };
Battle D_800A67F4 = { 0, 0, 0x60040000 };
Battle D_800A6800 = { 0, 0, 0x60040000 };
Battle D_800A680C = { 0, 0, 0x60040000 };
Battle D_800A6818 = { 0, 0, 0x60040000 };
Battle D_800A6824 = { 0, 0, 0x60040000 };
Battle D_800A6830 = { 0, 0, 0x60040000 };
Battle D_800A683C = { 0, 0, 0x60040000 };
BattleList D_800A6848 = {
    0,
    { &D_800A67E8, &D_800A67F4, &D_800A6800, &D_800A680C,
      &D_800A6818, &D_800A6824, &D_800A6830, &D_800A683C },
};
FieldBattles stageBattles[] = {
    { 91, 0, 0, { &D_800A66BC, &D_800A6740, &D_800A67C4, &D_800A6848 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x158, 0x170, 0x58, 0x170, 0x1D9 },
    { 0x180, 0x100, 0x1A2, 0x158, 0x188, 0x58, 0x170, 0x1D8 },
    { 0x180, 0x100, 0x1A8, 0x158, 0x1A0, 0x58, 0x170, 0x1D7 },
    { 0x180, 0x100, 0x18C, 0x170, 0x130, 0x70, 0x170, 0x1D6 },
    { 0x180, 0x100, 0x192, 0x170, 0x148, 0x70, 0x170, 0x1D5 },
    { 0x140, 0x100, 0x16E, 0x1A8, 0xB8, 0xA8, 0x170, 0x1D4 },
    { 0x140, 0x100, 0x17A, 0x1B0, 0xE8, 0xB0, 0x170, 0x1D3 },
};
u16 D_800A6958[] = { 0x245, 1, 0x8AE0, 1, 0xFFFF };
u16 D_800A6964[] = { 0x246, 1, 0x8AEA, 1, 0xFFFF };
u16 D_800A6970[] = { 0x247, 1, 0x822C, 1, 0xFFFF };
u16 D_800A697C[] = { 0x248, 1, 0xFFFF };
u16 D_800A6984[] = { 0x249, 1, 0x8B11, 1, 0xFFFF };
FieldTalk D_800A6990[] = {
    { NULL, D_800A6958, 0x21B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69A8[] = {
    { NULL, D_800A6964, 0x21C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69C0[] = {
    { NULL, D_800A6970, 0x17D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69D8[] = {
    { NULL, D_800A697C, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69F0[] = {
    { NULL, D_800A6984, 0x21F },
    { NULL, NULL, 0 },
};
u16 D_800A6A08[] = { 0x245, 0, 0xFFFF };
u16 D_800A6A10[] = { 0x246, 0, 0xFFFF };
u16 D_800A6A18[] = { 0x247, 0, 0xFFFF };
u16 D_800A6A20[] = { 0x248, 0, 0xFFFF };
u16 D_800A6A28[] = { 0x249, 0, 0xFFFF };
u16 D_800A6A30[] = { 0x6020, 1, 0x4044, 0, 0xFFFF };
u16 D_800A6A3C[] = { 0x6020, 1, 0xFFFF };
FieldActorEntry D_800A6A44 = { D_800A6A08, D_800A6990, 0x21, 4, 1024, 168, 1 };
FieldActorEntry D_800A6A58 = { D_800A6A10, D_800A69A8, 0x4D, 5, 640, 938, 1 };
FieldActorEntry D_800A6A6C = { D_800A6A18, D_800A69C0, 0x4E, 6, 1217, 328, 1 };
FieldActorEntry D_800A6A80 = { D_800A6A20, D_800A69D8, 0x4F, 7, 1249, 281, 1 };
FieldActorEntry D_800A6A94 = { D_800A6A28, D_800A69F0, 0x50, 8, 352, 697, 1 };
FieldActorEntry D_800A6AA8 = { D_800A6A30, NULL, 0xD0, 9, 1473, 409, 5 };
FieldActorEntry D_800A6ABC = { D_800A6A3C, NULL, 0x13C, 0xA, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6A44,
    &D_800A6A58,
    &D_800A6A6C,
    &D_800A6A80,
    &D_800A6A94,
    &D_800A6AA8,
    &D_800A6ABC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 728, 212, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 760, 197, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 952, 884, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 984, 868, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 1112, 804, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 1144, 788, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 1240, 629, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 4, 0, 1272, 612, 0, 0 },
    { 1, 2, 0x64, 6, 0x51, 0, 0, 0, 0, 0, 898, 764, 0, 0 },
    { 1, 1, 0x64, 6, 0x46, 0, 0, 0, 0, 0, 898, 764, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 656, 176, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 688, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 880, 848, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 912, 832, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 1040, 768, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 1072, 752, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 1168, 592, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 4, 0, 1200, 576, 0, 0 },
    { 0, 4, 0x64, 6, 0x33, 0, 0, 0, 0, 0, 1550, 338, 0, 0 },
    { 0, 3, 0x64, 6, 0x34, 0, 0, 0, 0, 0, 1550, 338, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DA, 0x4F2, 0x150, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DA, 0x522, 0x1F6, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DA, 0x552, 0x28E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DA, 0x554, 0x400, 3, 0, 0, 0 },
    { { { 0x6020, 1 }, { 0x4044, 0 } }, 8, 0x366, 0, 0, 0, 0, 0, 0 },
    { { { 0x1C05, 1 }, { 0x4061, 0 } }, 8, 0x352, 0, 0, 0, 0, 0, 0 },
    { { { 0x1C05, 1 }, { 0xFFFF, 0 } }, 0xD, 0x2DB, 0x450, 0x330, 1, 0, 0, 0 },
    { { { 0x1C05, 1 }, { 0xFFFF, 0 } }, 0xD, 0x2DB, 0x2D0, 0xE0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 850, D_800A609C, EVENT_TEXT(0), NULL, func_800A5EA4 },
    { 870, D_800A6184, EVENT_TEXT(1), NULL, func_800A5EF0 },
    { 871, D_800A620C, EVENT_TEXT(2), NULL, func_800A5F3C },
    { 1506, D_800A646C, EVENT_TEXT(0x12), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
