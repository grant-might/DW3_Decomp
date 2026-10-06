#include "common.h"
#include "stage.h"
#if VERSION_US
#define STAGE_FILE 0x6DD
#elif VERSION_EU
#define STAGE_FILE 0x6ED
#endif
extern AnimFrame D_800A6048[];
extern AnimFrame D_800A6058[];
extern AnimFrame D_800A6094[];
extern StageEffectSpot D_800A60B0[];
extern StageSlot D_800A6968[];
extern StageSlot D_800A6C68[];

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
void func_800A4DC4(StageTilePairN *task) {
    StageTile *tile;
    StageTile *rec;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == task->anim) {
                task->anims[0].anim.index = 0;
                task->anims[0].anim.timer = (u8)D_800A6048[0].duration;
                task->anims[0].tile = rec;
            }
            if (rec->anim == task->anim + 1) {
                task->anims[1].anim.index = 0;
                task->anims[1].anim.timer = (u8)D_800A6094[0].duration;
                task->anims[1].tile = rec;
            }
        }
        task->playing = 0;
        if (task->done == 1) {
            task->playing = 1;
            task->anims[0].anim.index = 0;
            task->anims[0].anim.timer = (u8)D_800A6058[0].duration;
            task->setState(task, TASK_DONE);
        } else {
            task->nextState(task);
        }
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                tile->frame = 0x55;
                tile->clutRow = stepTileAnimation(&task->anims[0], D_800A6048, 0, 0);
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
                    frame = stepTileAnimation(&task->anims[0], D_800A6058, 1, 0);
                    if (frame == 0xFF) {
                        tile->frame = 0x54;
                        task->playing = 0;
                    } else {
                        tile->frame = frame;
                    }
                } else {
                    tile->frame = 0x54;
                }
                tile->clutRow = 0;
                break;
            case 1:
                tile->visible = 1;
                tile->frame = 0x46;
                tile->clutRow = stepTileAnimation(&task->anims[1], D_800A6094, 0, 0);
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Plays the first record's one-shot animation when the event of map object 0x35B happens */
void func_800A503C(StageTilePairN *task, s32 id) {
    if (id == 0x35B) {
        task->playing = 1;
        task->anims[0].anim.index = 0;
        task->anims[0].anim.timer = (u8)D_800A6058[0].duration;
        task->setState(task, TASK_DONE);
    }
}

/* Creates the tile pair object of animations 1 and 2 */
void *func_800A5088(s32 arg) {
    StageTilePairN *task = createTaskWithId(func_800A4DC4, 0x68, 0, arg);

    task->anim = 1;
    task->done = 0;
    return task;
}

/* Creates the tile pair object of animations 3 and 4 */
void *func_800A50C4(s32 arg) {
    StageTilePairN *task = createTaskWithId(func_800A4DC4, 0x68, 0, arg);

    task->anim = 3;
    task->done = 0;
    return task;
}

/* Creates the tile pair object of animations 5 and 6 */
void *func_800A5100(s32 arg) {
    StageTilePairN *task = createTaskWithId(func_800A4DC4, 0x68, 0, arg);

    task->anim = 5;
    task->done = 0;
    return task;
}

/* Creates the tile pair object of animations anim and anim + 1, started in TASK_DONE */
void *func_800A513C(s32 anim) {
    StageTilePairN *task = createTask(func_800A4DC4, 0x68, 0);

    task->anim = anim;
    task->done = 1;
    return task;
}

/* Creates the stage's 62 effects and its three tile pairs, started by flags 0x406E, 0x406F and 0x406D */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        for (i = 0; i < 62; i++) {
            if (D_800A60B0[i].kind == 0) {
                children[i] = createStageEffect(D_800A60B0[i].x, D_800A60B0[i].y, D_800A60B0[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x406E, 0)) {
            children[62] = func_800A5088(0x34C);
        } else {
            children[62] = func_800A513C(1);
        }
        if (FLAGS_00.checkCondition(0x406F, 0)) {
            children[63] = func_800A50C4(0x34B);
        } else {
            children[63] = func_800A513C(3);
        }
        if (FLAGS_00.checkCondition(0x406D, 0)) {
            children[64] = func_800A5100(0x34A);
        } else {
            children[64] = func_800A513C(5);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x104
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

/* Puts back the first background when GAME.unk26DC is set, and clears it */
void *func_800A58F0(void) {
    if (GAME.unk26DC != 0) {
        D_8009A70C.setFile(7, STAGE_FILE << 16 | 3);
        D_800990B4.slots = D_800A6968;
        GAME.unk26DC = 0;
    }
    return NULL;
}

/* Switches to the second background when GAME.unk26DC is clear, and sets it */
void *func_800A5954(void) {
    if (GAME.unk26DC == 0) {
        D_8009A70C.setFile(7, STAGE_FILE << 16 | 4);
        D_800990B4.slots = D_800A6C68;
        GAME.unk26DC = 0x20;
    }
    return NULL;
}

void func_800A59BC(void) {
    FLAGS_00.applyAction(0x406D, 1);
    FLAGS_00.applyAction(0x1C3A, 1);
}

void func_800A5A08(void) {
    FLAGS_00.applyAction(0x406E, 1);
    FLAGS_00.applyAction(0x1C3B, 1);
}

void func_800A5A54(void) {
    FLAGS_00.applyAction(0x406F, 1);
    FLAGS_00.applyAction(0x1C3C, 1);
}

void func_800A5AA0(void) {
    GAME.progress = 41;
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x14A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x151
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x31000, 0x1F800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1C;
    D_800990B4.music = 0x60700000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.clearTempFlags != 0 || GAME.unk26DC == 0) {
        GAME.unk26DC = 1;
        func_800A58F0();
    } else {
        GAME.unk26DC = 0;
        func_800A5954();
    }
}

extern Battle D_800A6408;
extern Battle D_800A6414;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A6438;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A648C;
extern Battle D_800A6498;
extern Battle D_800A64A4;
extern Battle D_800A64B0;
extern Battle D_800A64BC;
extern Battle D_800A64C8;
extern Battle D_800A64D4;
extern Battle D_800A64E0;
extern Battle D_800A6510;
extern Battle D_800A651C;
extern Battle D_800A6528;
extern Battle D_800A6534;
extern Battle D_800A6540;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6594;
extern Battle D_800A65A0;
extern Battle D_800A65AC;
extern Battle D_800A65B8;
extern Battle D_800A65C4;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern BattleList D_800A6468;
extern BattleList D_800A64EC;
extern BattleList D_800A6570;
extern BattleList D_800A65F4;
extern u16 D_800A670C[];
extern FieldTalk D_800A66C4[];
extern u16 D_800A6714[];
extern FieldTalk D_800A66DC[];
extern u16 D_800A671C[];
extern FieldTalk D_800A66F4[];
extern FieldActorEntry D_800A6724;
extern FieldActorEntry D_800A6738;
extern FieldActorEntry D_800A674C;
extern s16 D_800A5BE0[];
extern s16 D_800A5D18[];
extern s16 D_800A5E50[];
extern s16 D_800A5F88[];

s16 D_800A5BE0[] = {
    0x102, 2, 0x530, 0x140, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x377, 2,
    0x101, 0x34A, 0x35B, 2,
    0x300, 0x5A,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x100, 0x180, 0, 0,
    0x101, 0x180, 1, 1,
    0x101, 0x32D, 0x374, 2,
    0x300, 0x5A,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x510, 0x151, 1,
    0x302, 2,
    0,
};
s16 D_800A5D18[] = {
    0x102, 2, 0x390, 0x90, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x377, 2,
    0x101, 0x34C, 0x35B, 2,
    0x300, 0x5A,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x100, 0x181, 0, 0,
    0x101, 0x181, 1, 1,
    0x101, 0x32D, 0x374, 2,
    0x300, 0x5A,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x370, 0xA0, 1,
    0x302, 2,
    0,
};
s16 D_800A5E50[] = {
    0x102, 2, 0x510, 0x90, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x377, 2,
    0x101, 0x34B, 0x35B, 2,
    0x300, 0x5A,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x100, 0x182, 0, 0,
    0x101, 0x182, 1, 1,
    0x101, 0x32D, 0x374, 2,
    0x300, 0x5A,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x50F, 0x91, 1,
    0x302, 2,
    0,
};
s16 D_800A5F88[] = {
    0x102, 2, 0xA0, 0x2D9, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 1, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0,
};
AnimFrame D_800A6048[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 255, 0 },
};
AnimFrame D_800A6058[] = {
    { 71, 4 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 75, 4 }, { 76, 4 }, { 77, 4 }, { 78, 4 },
    { 79, 4 }, { 80, 4 }, { 81, 4 }, { 82, 4 },
    { 83, 4 }, { 84, 4 }, { 255, 0 },
};
AnimFrame D_800A6094[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 255, 0 },
};
StageEffectSpot D_800A60B0[] = {
    { 60, 0, 92, 181 },
    { 60, 0, 92, 245 },
    { 60, 0, 92, 0x195 },
    { 52, 0, 92, 0x1D5 },
    { 60, 0, 156, 213 },
    { 52, 0, 220, 245 },
    { 60, 0, 220, 0x135 },
    { 44, 0, 236, 0x2EC },
    { 44, 0, 252, 0x395 },
    { 60, 0, 0x11C, 149 },
    { 60, 0, 0x11C, 0x1D5 },
    { 44, 0, 0x11C, 0x324 },
    { 60, 0, 0x12C, 0x2CC },
    { 60, 0, 0x13C, 0x3B5 },
    { 60, 0, 0x15C, 181 },
    { 60, 0, 0x15C, 0x344 },
    { 60, 0, 0x17C, 133 },
    { 52, 0, 0x19C, 0x1D5 },
    { 60, 0, 0x1BC, 0x1A5 },
    { 60, 0, 0x1DC, 0x115 },
    { 60, 0, 0x1FC, 0x225 },
    { 52, 0, 0x21C, 0x1D5 },
    { 60, 0, 0x23C, 133 },
    { 60, 0, 0x23C, 0x245 },
    { 60, 0, 0x27C, 0x265 },
    { 60, 0, 0x29C, 0x195 },
    { 60, 0, 0x2BC, 133 },
    { 60, 0, 0x2BC, 0x285 },
    { 60, 0, 0x2DC, 0x175 },
    { 60, 0, 0x2EC, 0x41D },
    { 60, 0, 0x2FC, 0x2A5 },
    { 60, 0, 0x31C, 245 },
    { 60, 0, 0x33C, 0x225 },
    { 52, 0, 0x35C, 0x1B5 },
    { 60, 0, 0x36C, 0x2BD },
    { 52, 0, 0x36C, 0x2FD },
    { 60, 0, 0x36C, 0x33D },
    { 60, 0, 0x3AC, 0x35D },
    { 60, 0, 0x3BC, 0x145 },
    { 60, 0, 0x3BC, 0x1A5 },
    { 60, 0, 0x3CC, 0x38D },
    { 52, 0, 0x3EC, 0x33D },
    { 60, 0, 0x3EC, 0x3BD },
    { 60, 0, 0x3FC, 0x2A5 },
    { 52, 0, 0x42C, 0x39D },
    { 52, 0, 0x43C, 133 },
    { 52, 0, 0x43C, 0x245 },
    { 60, 0, 0x44C, 0x40D },
    { 60, 0, 0x45C, 0x1F5 },
    { 60, 0, 0x48C, 0x34D },
    { 60, 0, 0x49C, 0x1B5 },
    { 52, 0, 0x4DC, 245 },
    { 52, 0, 0x4DC, 0x1F5 },
    { 60, 0, 0x4DC, 0x295 },
    { 60, 0, 0x4EC, 0x35D },
    { 60, 0, 0x4EC, 0x41D },
    { 52, 0, 0x51C, 0x1B5 },
    { 60, 0, 0x51C, 0x235 },
    { 60, 0, 0x51C, 0x2B5 },
    { 60, 0, 0x51C, 0x2F5 },
    { 52, 0, 108, 0x2DC },
    { 44, 0, 204, 0x40D },
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
Battle D_800A6408 = { 185, 17, 0x60080000 };
Battle D_800A6414 = { 185, 17, 0x60080000 };
Battle D_800A6420 = { 185, 17, 0x60080000 };
Battle D_800A642C = { 135, 17, 0x60080000 };
Battle D_800A6438 = { 135, 17, 0x60080000 };
Battle D_800A6444 = { 135, 17, 0x60080000 };
Battle D_800A6450 = { 140, 17, 0x60080000 };
Battle D_800A645C = { 140, 17, 0x60080000 };
BattleList D_800A6468 = {
    4,
    { &D_800A6408, &D_800A6414, &D_800A6420, &D_800A642C,
      &D_800A6438, &D_800A6444, &D_800A6450, &D_800A645C },
};
Battle D_800A648C = { 0, 0, 0x60040000 };
Battle D_800A6498 = { 0, 0, 0x60040000 };
Battle D_800A64A4 = { 0, 0, 0x60040000 };
Battle D_800A64B0 = { 0, 0, 0x60040000 };
Battle D_800A64BC = { 0, 0, 0x60040000 };
Battle D_800A64C8 = { 0, 0, 0x60040000 };
Battle D_800A64D4 = { 0, 0, 0x60040000 };
Battle D_800A64E0 = { 0, 0, 0x60040000 };
BattleList D_800A64EC = {
    0,
    { &D_800A648C, &D_800A6498, &D_800A64A4, &D_800A64B0,
      &D_800A64BC, &D_800A64C8, &D_800A64D4, &D_800A64E0 },
};
Battle D_800A6510 = { 0, 0, 0x60040000 };
Battle D_800A651C = { 0, 0, 0x60040000 };
Battle D_800A6528 = { 0, 0, 0x60040000 };
Battle D_800A6534 = { 0, 0, 0x60040000 };
Battle D_800A6540 = { 0, 0, 0x60040000 };
Battle D_800A654C = { 0, 0, 0x60040000 };
Battle D_800A6558 = { 0, 0, 0x60040000 };
Battle D_800A6564 = { 0, 0, 0x60040000 };
BattleList D_800A6570 = {
    0,
    { &D_800A6510, &D_800A651C, &D_800A6528, &D_800A6534,
      &D_800A6540, &D_800A654C, &D_800A6558, &D_800A6564 },
};
Battle D_800A6594 = { 0, 0, 0x60040000 };
Battle D_800A65A0 = { 0, 0, 0x60040000 };
Battle D_800A65AC = { 0, 0, 0x60040000 };
Battle D_800A65B8 = { 0, 0, 0x60040000 };
Battle D_800A65C4 = { 0, 0, 0x60040000 };
Battle D_800A65D0 = { 0, 0, 0x60040000 };
Battle D_800A65DC = { 0, 0, 0x60040000 };
Battle D_800A65E8 = { 0, 0, 0x60040000 };
BattleList D_800A65F4 = {
    0,
    { &D_800A6594, &D_800A65A0, &D_800A65AC, &D_800A65B8,
      &D_800A65C4, &D_800A65D0, &D_800A65DC, &D_800A65E8 },
};
FieldBattles stageBattles[] = {
    { 124, 0, 0, { &D_800A6468, &D_800A64EC, &D_800A6570, &D_800A65F4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x152, 0x1B1, 0x48, 0xB1, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x162, 0x1B1, 0x88, 0xB1, 0x140, 0x1F7 },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x150, 0x1F7 },
};
FieldTalk D_800A66C4[] = {
    { NULL, NULL, 0x348 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66DC[] = {
    { NULL, NULL, 0x348 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66F4[] = {
    { NULL, NULL, 0x348 },
    { NULL, NULL, 0 },
};
u16 D_800A670C[] = { 0x1C3A, 0, 0xFFFF };
u16 D_800A6714[] = { 0x1C3B, 0, 0xFFFF };
u16 D_800A671C[] = { 0x1C3C, 0, 0xFFFF };
FieldActorEntry D_800A6724 = { D_800A670C, D_800A66C4, 0x180, 4, 369, 912, 7 };
FieldActorEntry D_800A6738 = { D_800A6714, D_800A66DC, 0x181, 5, 400, 800, 7 };
FieldActorEntry D_800A674C = { D_800A671C, D_800A66F4, 0x182, 6, 208, 704, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A6724,
    &D_800A6738,
    &D_800A674C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 2, 0x64, 6, 0x46, 0, 0, 0, 0, 0, 910, 80, 0, 0 },
    { 1, 4, 0x64, 6, 0x46, 0, 0, 0, 0, 0, 1295, 80, 0, 0 },
    { 1, 6, 0x64, 6, 0x46, 0, 0, 0, 0, 0, 1327, 256, 0, 0 },
    { 1, 1, 0x64, 6, 0x47, 0, 0, 0, 0, 0, 910, 80, 0, 0 },
    { 1, 3, 0x64, 6, 0x47, 0, 0, 0, 0, 0, 1295, 80, 0, 0 },
    { 1, 5, 0x64, 6, 0x47, 0, 0, 0, 0, 0, 1327, 256, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 26, 975, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 47, 138, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 123, 576, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 125, 877, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 195, 656, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 231, 32, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 307, 580, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 431, 874, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 486, 102, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 532, 732, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 549, 1020, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 595, 820, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 615, 349, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 668, 33, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 713, 235, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 738, 837, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 890, 262, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 1037, 46, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 1054, 329, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 1108, 403, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0, 0, 0, 0, 0, 0, 1354, 1060, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot D_800A6968[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x314, 0x41E, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x13C, 0x3B6, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x84, 0x196, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x44C, 0x40E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x4C4, 0x1B6, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x84, 0x10A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x3CC, 0x3A2, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x15C, 0x346, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x33C, 0x23A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x3EC, 0x3D2, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x224, 0x226, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x3AC, 0x372, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x2E4, 0x286, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x264, 0x246, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x11C, 0x1D6, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x324, 0x2A6, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x51C, 0x24A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x2A4, 0x266, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DE, 0x189, 0x2DF, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DE, 0xCE, 0x283, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x394, 0x33E, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x12C, 0x2E2, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DE, 0x3F8, 0x117, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DE, 0x33E, 0xBA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x110, 0x3A0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x130, 0x330, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DE, 0x40C, 0x2D2, 1, 0, 0, 0 },
    { { { 0x406D, 0 }, { 0xFFFF, 0 } }, 8, 0x3DE, 0, 0, 0, 0, 0, 0 },
    { { { 0x406E, 0 }, { 0xFFFF, 0 } }, 8, 0x3E8, 0, 0, 0, 0, 0, 0 },
    { { { 0x406F, 0 }, { 0xFFFF, 0 } }, 8, 0x3F2, 0, 0, 0, 0, 0, 0 },
    { { { 0x6028, 1 }, { 0xFFFF, 0 } }, 8, 0x40B, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x2329, 0, 0, 0, 0, 0, 0 },
};
StageSlot D_800A6C68[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x11C, 0xAA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x394, 0x2D2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x48C, 0x34E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x45C, 0x20A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x3FC, 0x2A6, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x184, 0xCA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x204, 0x12A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x104, 0x14A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x51C, 0x2CA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x1BC, 0x1A6, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x51C, 0x30A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x84, 0xB6, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x23C, 0x9A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0xC4, 0xD6, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x3E4, 0x1BA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x2BC, 0x9A, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x4EC, 0x372, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x1A4, 0x9A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x4EC, 0x41E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x304, 0x18A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2DD, 0x100, 0x2F8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 990, D_800A5BE0, EVENT_TEXT(6), NULL, func_800A59BC },
    { 1000, D_800A5D18, EVENT_TEXT(7), NULL, func_800A5A08 },
    { 1010, D_800A5E50, EVENT_TEXT(8), NULL, func_800A5A54 },
    { 1035, D_800A5F88, EVENT_TEXT(0xB), NULL, func_800A5AA0 },
    { 9000, NULL, 0, func_800A58F0, NULL },
    { 9001, NULL, 0, func_800A5954, NULL },
    { -1, NULL, 0, NULL, NULL },
};
