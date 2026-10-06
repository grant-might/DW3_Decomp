#include "common.h"
#include "stage.h"
void func_800A5048();
void func_800A4DE4();
void func_800A5350();
extern AnimFrame D_800A5BE0[];
extern AnimFrame D_800A5C18[];
extern AnimFrame *D_800A5CA4[3];
extern StageTileAtSpot D_800A5CB0[];

/* Steps an animation, holding its last frame, and returns the frame */
s32 func_800A4CDC(StageTileAnim *obj, AnimFrame *frames, s32 depth) {
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
        if (frame->frame == 0xFF) {
            obj->anim.index--;
            frame = &frames[obj->anim.index];
            obj->anim.timer += frame->duration;
        }
        func_800A4CDC(obj, frames, depth + 1);
    }
    return frame->frame;
}

/* Moves the record with the given animation to (x, y); hidden while running, shown and animated when done */
void func_800A4DE4(StageTileAt *task) {
    StageTile *rec;
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->obj.anim.index = 0;
        task->obj.anim.timer = D_800A5BE0[0].duration;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == task->anim) {
                task->obj.tile = rec;
                rec->x = task->x;
                rec->y = task->y;
            }
        }
        break;
    case TASK_RUN:
        task->obj.tile->visible = 0;
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->obj.anim.index = 0;
            task->obj.anim.timer = D_800A5BE0[0].duration;
            task->setSubstate(task, 1);
        }
        tile = task->obj.tile;
        tile->visible = 1;
        tile->frame = func_800A4CDC(&task->obj, D_800A5BE0, 0);
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates a StageTileAt for the record with the given animation */
StageTileAt *func_800A4F18(s32 anim, s32 x, s32 y) {
    StageTileAt *task = createTask(func_800A4DE4, sizeof(StageTileAt), 0);

    task->anim = anim;
    task->x = x;
    task->y = y;
    return task;
}

s32 stepAnimationOnce(StageTileAnim *obj, AnimFrame *frames, s32 depth) {
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
        if (frame->frame == 0xFF) {
            return 0xFF;
        }
        stepAnimationOnce(obj, frames, depth + 1);
    }
    return frame->frame;
}

/* Shows the record with animation 1 (frame 0x18); when done, animates it once with a sound and goes back to TASK_RUN */
void func_800A5048(StageTileTask *task) {
    StageTile *rec;
    StageTile *shown;
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->obj.anim.index = 0;
        task->obj.anim.timer = D_800A5C18[0].duration;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->obj.tile = rec;
            }
        }
        break;
    case TASK_RUN:
        shown = task->obj.tile;
        shown->visible = 1;
        shown->frame = 0x18;
        shown->clutRow = 9;
        break;
    case TASK_DONE:
        if (task->substate == 0) {
            task->obj.anim.index = 0;
            task->obj.anim.timer = D_800A5C18[0].duration;
            task->setSubstate(task, 1);
            SOUND.playSound(0x4C0002);
        }
        tile = task->obj.tile;
        frame = stepAnimationOnce(&task->obj, D_800A5C18, 0);
        if (frame == 0xFF) {
            task->setState(task, TASK_RUN);
            tile->clutRow = 9;
        } else {
            tile->clutRow = frame;
        }
        tile->visible = 1;
        tile->frame = 0x18;
        break;
    case TASK_KILL:
        break;
    }
}

void func_800A51C8(StageTask *task, s32 id) {
    if (task != NULL && id == 0x35A) {
        task->setState(task, TASK_DONE);
    }
}

void *func_800A5200(s32 arg) {
    return createTaskWithId(func_800A5048, 0x58, 0, arg);
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

/* Animates the record with animation 2 by substate and sets the child an event picked to TASK_DONE */
void func_800A5350(StageTileSwitch *task, StageTileAts *children) {
    StageTile *rec;
    StageTile *tile;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 2) {
                task->obj.anim.index = 0;
                task->obj.anim.timer = D_800A5CA4[0][0].duration;
                task->obj.tile = rec;
            }
        }
        for (i = 0; i < 5; i++) {
            children->tiles[i] = func_800A4F18(D_800A5CB0[i].anim, D_800A5CB0[i].x, D_800A5CB0[i].y);
        }
        task->silent = 0;
        task->spawn = 0;
        task->nextState(task);
        break;
    case TASK_RUN:
        tile = task->obj.tile;
        switch (task->substate) {
        case 0:
            tile->visible = 0;
            break;
        case 1:
            if (task->step == 0) {
                task->obj.anim.index = 0;
                task->obj.anim.timer = D_800A5CA4[0][0].duration;
                task->setStep(task, 1);
            }
            {
                s32 frame = stepTileAnimation(&task->obj, D_800A5CA4[0], 1, 0);

                tile->visible = 1;
                if (frame == 0xFF) {
                    tile->frame = 8;
                    task->setSubstate(task, 2);
                } else {
                    tile->frame = frame;
                }
            }
            break;
        case 3:
            if (task->step == 0) {
                task->obj.anim.index = 0;
                task->obj.anim.timer = D_800A5CA4[1][0].duration;
                task->setStep(task, 1);
            }
            {
                s32 frame = stepTileAnimation(&task->obj, D_800A5CA4[1], 1, 0);

                tile->visible = 1;
                if (frame == 0xFF) {
                    tile->frame = 9;
                    task->setSubstate(task, 4);
                } else {
                    tile->frame = frame;
                }
            }
            break;
        case 5:
            if (task->step == 0) {
                task->obj.anim.index = 0;
                task->obj.anim.timer = D_800A5CA4[2][0].duration;
                task->setStep(task, 1);
                SOUND.playSound(0x4C0001);
            }
            {
                s32 frame = stepTileAnimation(&task->obj, D_800A5CA4[2], 0, 0);

                tile->visible = 1;
                tile->frame = frame;
            }
            break;
        case 2:
        case 4:
            break;
        }
        if (task->spawn != 0) {
            children->tiles[task->spawn - 1]->setState(children->tiles[task->spawn - 1], TASK_DONE);
            task->spawn = 0;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Events 0x35D to 0x364: animate the record (substates 1, 3, 5) or pick a child to set to TASK_DONE */
void func_800A5644(void *arg, s32 id) {
    StageTileSwitch *task = arg;

    if (task != NULL) {
        if (task->silent == 0) {
            SOUND.playSound(0x8004474A);
        }
        switch (id) {
        case 0x35D:
            task->setSubstate(task, 1);
            break;
        case 0x35E:
            task->setSubstate(task, 3);
            break;
        case 0x35F:
            task->setSubstate(task, 5);
            break;
        case 0x360:
            task->spawn = 1;
            break;
        case 0x361:
            task->spawn = 2;
            break;
        case 0x362:
            task->spawn = 3;
            break;
        case 0x363:
            task->spawn = 4;
            break;
        case 0x364:
            task->spawn = 5;
            break;
        }
        task->setStep(task, 0);
    }
}

/* Creates the task of func_800A5350 with the given id */
void *func_800A5758(s32 id) {
    return createTaskWithId(func_800A5350, 0x60, 0x14, id);
}

/* Creates the stage object of flag 0x4051, and the event object of story progress 26 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4051, 0)) {
            children[0] = func_800A5200(0x34F);
        }
        if (GAME.progress == 0x1A && FLAGS_00.checkCondition(0x4051, 1)) {
            children[2] = FIELDSTG_startEvent(0x2C7);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"

void func_800A58A4(void) {
    FLAGS_00.applyAction(0x4051, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A58F0(void) {
    GAME.progress = 27;
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x267
#define STAGE_ARCHIVE 0x3CF
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x276
#define STAGE_ARCHIVE 0x3DF
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x18800, 0x24600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x13;
    D_800990B4.music = 0x604C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern AnimFrame D_800A5C64[];
extern AnimFrame D_800A5C8C[];
extern AnimFrame D_800A5C98[];
extern Battle D_800A5CEC;
extern Battle D_800A5CF8;
extern Battle D_800A5D04;
extern Battle D_800A5D10;
extern Battle D_800A5D1C;
extern Battle D_800A5D28;
extern Battle D_800A5D34;
extern Battle D_800A5D40;
extern Battle D_800A5D70;
extern Battle D_800A5D7C;
extern Battle D_800A5D88;
extern Battle D_800A5D94;
extern Battle D_800A5DA0;
extern Battle D_800A5DAC;
extern Battle D_800A5DB8;
extern Battle D_800A5DC4;
extern Battle D_800A5DF4;
extern Battle D_800A5E00;
extern Battle D_800A5E0C;
extern Battle D_800A5E18;
extern Battle D_800A5E24;
extern Battle D_800A5E30;
extern Battle D_800A5E3C;
extern Battle D_800A5E48;
extern Battle D_800A5E78;
extern Battle D_800A5E84;
extern Battle D_800A5E90;
extern Battle D_800A5E9C;
extern Battle D_800A5EA8;
extern Battle D_800A5EB4;
extern Battle D_800A5EC0;
extern Battle D_800A5ECC;
extern BattleList D_800A5D4C;
extern BattleList D_800A5DD0;
extern BattleList D_800A5E54;
extern BattleList D_800A5ED8;
extern u16 D_800A5F98[];
extern u16 D_800A6020[];
extern FieldTalk D_800A5FA8[];
extern u16 D_800A6028[];
extern FieldTalk D_800A5FC0[];
extern u16 D_800A6030[];
extern FieldTalk D_800A5FD8[];
extern u16 D_800A6038[];
extern FieldTalk D_800A5FF0[];
extern u16 D_800A6040[];
extern FieldTalk D_800A6008[];
extern FieldActorEntry D_800A6048;
extern FieldActorEntry D_800A605C;
extern FieldActorEntry D_800A6070;
extern FieldActorEntry D_800A6084;
extern FieldActorEntry D_800A6098;
extern s16 D_800A5A14[];
extern s16 D_800A5B64[];

s16 D_800A5A14[] = {
    0x102, 2, 0x218, 0x1C4, 5,
    0x101, 0x32D, 0x337, 2,
    0x101, 0x350, 0x35C, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x268, 0x19C, 5,
    0x302, 2,
    0x601, 0, 0x296, 0x184,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x369, 2,
    0x300, 0x3C,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 1, 1,
    0x301,
    0x101, 0x34F, 0x35A, 2,
    0x300, 0x1E,
    0x300, 0x5A,
    0x101, 2, 1, 5,
    0x101, 0x34F, 0x35A, 2,
    0x300, 0x5A,
    0x101, 0x350, 0x360, 2,
    0x300, 0x48,
    0x101, 0x350, 0x361, 2,
    0x300, 0x24,
    0x101, 0x350, 0x362, 2,
    0x300, 0x18,
    0x101, 0x350, 0x363, 2,
    0x300, 0x30,
    0x101, 0x350, 0x364, 2,
    0x300, 0x60,
    0x101, 0x350, 0x35D, 2,
    0x300, 0x96,
    0x101, 0x350, 0x35E, 2,
    0x300, 0x12,
    0x101, 0x32D, 0x373, 2,
    0x300, 0x2A,
    0x200, 0, 2, 2, 0,
    0x301,
    0x101, 0x350, 0x35F, 2,
    0x300, 0x3C,
    0x200, 0, 3, 2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5B64[] = {
    0x601, 1, 0x29A, 0x184,
    0x100, 2, 0x268, 0x19C,
    0x101, 2, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 2, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x268, 0x168, 5,
    0x302, 2,
    0x102, 2, 0x2A8, 0x148, 5,
    0x300, 6,
    0x304, 0x245, 0x708, 0x20C, 3,
    0,
};
AnimFrame D_800A5BE0[] = {
    { 11, 4 }, { 12, 4 }, { 13, 7 }, { 14, 9 },
    { 15, 10 }, { 16, 8 }, { 17, 4 }, { 18, 4 },
    { 19, 4 }, { 20, 4 }, { 21, 4 }, { 22, 4 },
    { 23, 100 }, { 255, 0 },
};
AnimFrame D_800A5C18[] = {
    { 9, 25 }, { 8, 4 }, { 7, 4 }, { 6, 4 },
    { 5, 4 }, { 4, 4 }, { 3, 6 }, { 2, 7 },
    { 1, 8 }, { 0, 8 }, { 1, 10 }, { 2, 10 },
    { 3, 10 }, { 4, 10 }, { 5, 10 }, { 6, 10 },
    { 7, 10 }, { 8, 10 }, { 255, 0x3E7 },
};
AnimFrame D_800A5C64[] = {
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 },
    { 4, 4 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 8, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A5C8C[] = {
    { 10, 4 }, { 9, 10 }, { 255, 0x3E7 },
};
AnimFrame D_800A5C98[] = {
    { 10, 4 }, { 9, 4 }, { 255, 0 },
};
AnimFrame *D_800A5CA4[3] = { D_800A5C64, D_800A5C8C, D_800A5C98 };
StageTileAtSpot D_800A5CB0[] = {
    { 0x288, 0x1D7, 3 },
    { 0x32F, 0x170, 4 },
    { 0x250, 0x11F, 5 },
    { 0x307, 0x1C9, 6 },
    { 0x234, 0x171, 7 },
};
Battle D_800A5CEC = { 165, 10, 0x60080000 };
Battle D_800A5CF8 = { 165, 10, 0x60080000 };
Battle D_800A5D04 = { 173, 10, 0x60080000 };
Battle D_800A5D10 = { 173, 10, 0x60080000 };
Battle D_800A5D1C = { 150, 10, 0x60080000 };
Battle D_800A5D28 = { 150, 10, 0x60080000 };
Battle D_800A5D34 = { 150, 10, 0x60080000 };
Battle D_800A5D40 = { 92, 10, 0x60080000 };
BattleList D_800A5D4C = {
    4,
    { &D_800A5CEC, &D_800A5CF8, &D_800A5D04, &D_800A5D10,
      &D_800A5D1C, &D_800A5D28, &D_800A5D34, &D_800A5D40 },
};
Battle D_800A5D70 = { 0, 0, 0x60040000 };
Battle D_800A5D7C = { 0, 0, 0x60040000 };
Battle D_800A5D88 = { 0, 0, 0x60040000 };
Battle D_800A5D94 = { 0, 0, 0x60040000 };
Battle D_800A5DA0 = { 0, 0, 0x60040000 };
Battle D_800A5DAC = { 0, 0, 0x60040000 };
Battle D_800A5DB8 = { 0, 0, 0x60040000 };
Battle D_800A5DC4 = { 0, 0, 0x60040000 };
BattleList D_800A5DD0 = {
    0,
    { &D_800A5D70, &D_800A5D7C, &D_800A5D88, &D_800A5D94,
      &D_800A5DA0, &D_800A5DAC, &D_800A5DB8, &D_800A5DC4 },
};
Battle D_800A5DF4 = { 0, 0, 0x60040000 };
Battle D_800A5E00 = { 0, 0, 0x60040000 };
Battle D_800A5E0C = { 0, 0, 0x60040000 };
Battle D_800A5E18 = { 0, 0, 0x60040000 };
Battle D_800A5E24 = { 0, 0, 0x60040000 };
Battle D_800A5E30 = { 0, 0, 0x60040000 };
Battle D_800A5E3C = { 0, 0, 0x60040000 };
Battle D_800A5E48 = { 0, 0, 0x60040000 };
BattleList D_800A5E54 = {
    0,
    { &D_800A5DF4, &D_800A5E00, &D_800A5E0C, &D_800A5E18,
      &D_800A5E24, &D_800A5E30, &D_800A5E3C, &D_800A5E48 },
};
Battle D_800A5E78 = { 12, 10, 0x60880000 };
Battle D_800A5E84 = { 315, 10, 0x60880000 };
Battle D_800A5E90 = { 0, 0, 0x60040000 };
Battle D_800A5E9C = { 0, 0, 0x60040000 };
Battle D_800A5EA8 = { 0, 0, 0x60040000 };
Battle D_800A5EB4 = { 0, 0, 0x60040000 };
Battle D_800A5EC0 = { 0, 0, 0x60040000 };
Battle D_800A5ECC = { 0, 0, 0x60040000 };
BattleList D_800A5ED8 = {
    0,
    { &D_800A5E78, &D_800A5E84, &D_800A5E90, &D_800A5E9C,
      &D_800A5EA8, &D_800A5EB4, &D_800A5EC0, &D_800A5ECC },
};
FieldBattles stageBattles[] = {
    { 61, 0, 0, { &D_800A5D4C, &D_800A5DD0, &D_800A5E54, &D_800A5ED8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A8, 0x1C8, 0x1A0, 0xC8, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1A0, 0x1C8, 0x180, 0xC8, 0x160, 0x1FC },
};
u16 D_800A5F98[] = { 0x21B, 1, 0x8B09, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5FA8[] = {
    { NULL, D_800A5F98, 0x264 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FC0[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FD8[] = {
    { NULL, NULL, 0x12C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FF0[] = {
    { NULL, NULL, 0x26 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6008[] = {
    { NULL, NULL, 0x110 },
    { NULL, NULL, 0 },
};
u16 D_800A6020[] = { 0x21B, 0, 0xFFFF };
u16 D_800A6028[] = { 0x601A, 1, 0xFFFF };
u16 D_800A6030[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6038[] = { 0x7019, 1, 0xFFFF };
u16 D_800A6040[] = { 0x6026, 1, 0xFFFF };
FieldActorEntry D_800A6048 = { D_800A6020, D_800A5FA8, 0x21, 4, 785, 697, 1 };
FieldActorEntry D_800A605C = { D_800A6028, D_800A5FC0, 0x45, 5, 559, 1145, 1 };
FieldActorEntry D_800A6070 = { D_800A6030, D_800A5FD8, 0x45, 5, 559, 1145, 1 };
FieldActorEntry D_800A6084 = { D_800A6038, D_800A5FF0, 0x45, 5, 559, 1145, 1 };
FieldActorEntry D_800A6098 = { D_800A6040, D_800A6008, 0x45, 5, 559, 1145, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6048,
    &D_800A605C,
    &D_800A6070,
    &D_800A6084,
    &D_800A6098,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x64, 2, 0x63, 0, 0, 0, 0, 0, 529, 465, 0, 0 },
    { 1, 0, 0x64, 2, 0x61, 0, 0, 0, 0, 0, 427, 1040, 0, 0 },
    { 1, 0, 0x64, 2, 0x61, 0, 0, 0, 0, 0, 546, 1044, 0, 0 },
    { 1, 0, 0x64, 2, 0x62, 0, 0, 0, 0, 0, 502, 1051, 0, 0 },
    { 0, 2, 0x80, 4, 0, 0, 0, 0, 0, 0, 701, 371, 371, 0 },
    { 0, 7, 0xF0, 4, 0xB, 0, 0, 0, 0, 0, 564, 369, 369, 0 },
    { 0, 5, 0xF0, 4, 0xB, 0, 0, 0, 0, 0, 592, 287, 287, 0 },
    { 0, 3, 0xF0, 4, 0xB, 0, 0, 0, 0, 0, 648, 471, 471, 0 },
    { 0, 6, 0xF0, 4, 0xB, 0, 0, 0, 0, 0, 775, 457, 457, 0 },
    { 0, 4, 0xF0, 4, 0xB, 0, 0, 0, 0, 0, 815, 368, 368, 0 },
    { 0, 1, 0x50, 4, 0x18, 0, 0, 0, 0, 0, 663, 340, 370, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x245, 0x708, 0x20C, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x245, 0x708, 0x2DC, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x245, 0x708, 0x3BC, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x245, 0x708, 0x50E, 3, 0, 0, 0 },
    { { { 0x601A, 1 }, { 0x4051, 0 } }, 8, 0x2C6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 710, D_800A5A14, EVENT_TEXT(0x21), NULL, func_800A58A4 },
    { 711, D_800A5B64, EVENT_TEXT(0x1F), NULL, func_800A58F0 },
    { -1, NULL, 0, NULL, NULL },
};
