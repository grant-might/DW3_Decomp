#include "common.h"
#include "stage.h"
void func_800A4E9C();
extern StageRiserFrame *D_800A564C[];

/* Steps a mover's looping animation, its last frame setting how far it moves */
s32 func_800A4DA0(StageRiser *obj, StageRiserFrame *frames, s32 depth) {
    StageRiserFrame *frame = &frames[obj->anim.index];
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
            obj->move = frame->move;
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        func_800A4DA0(obj, frames, depth + 1);
    }
    return frame->frame;
}

/* Animates and moves the records of the stage's table (lifts for animations 8-10) and pushes the player */
void func_800A4E9C(StageRisers *task) {
    StageTile *rec;
    StageTile *tile;
    StageActor *actor;
    s32 i;
    s32 j;

    switch (task->state) {
    case TASK_INIT:
    default:
        i = 0;
        j = 0;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 0:
                break;
            case 8:
            case 9:
            case 10:
                task->lifts[j].active = 0;
                task->lifts[j].speed = 0;
                task->lifts[j].tile = rec;
                j++;
                break;
            default:
                task->risers[i].tileAnim = rec->anim;
                task->risers[i].y = rec->y << 8;
                task->risers[i].active = 0;
                task->risers[i].anim.index = 0;
                task->risers[i].anim.timer = D_800A564C[i]->duration;
                task->risers[i].tile = rec;
                i++;
                break;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        for (i = 0; i < 11; i++) {
            if (task->risers[i].active) {
                tile = task->risers[i].tile;
                tile->frame = func_800A4DA0(&task->risers[i], D_800A564C[i], 0);
                tile->y += task->risers[i].move;
                task->risers[i].move = 0;
                if (tile->y > 0x190) {
                    task->risers[i].active = 0;
                }
            }
        }
        for (i = 0; i < 3; i++) {
            if (task->lifts[i].active) {
                tile = task->lifts[i].tile;
                task->lifts[i].speed += GFX.funcs.getFrameTime() << 7;
                tile->y += task->lifts[i].speed >> 8;
                if (tile->y > 0x190) {
                    task->lifts[i].active = 0;
                }
            }
        }
        if (task->pushing) {
            actor = TASK_REGISTRY.funcs.find(5, -1, 0);
            task->push += 0x40;
            actor->y += task->push;
            if (task->timer++ > 0x78) {
                task->pushing = 0;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Starts the records an event moves (the handler of the events the task gets) */
void func_800A5140(void *arg, s32 event) {
    StageRisers *task = arg;
    StageActor *player;
    s32 anim;
    s32 i;

    if (task != NULL) {
        player = TASK_REGISTRY.funcs.find(5, -1, 0);
        anim = 0;
        switch (event) {
        case 0x344:
            anim = 0;
            break;
        case 0x33D:
            anim = 1;
            break;
        case 0x33E:
            anim = 2;
            break;
        case 0x33F:
            task->lifts[0].active = 1;
            anim = 3;
            break;
        case 0x340:
            anim = 4;
            break;
        case 0x341:
            task->lifts[2].active = 1;
            anim = 5;
            break;
        case 0x342:
            anim = 6;
            break;
        case 0x343:
            anim = 7;
            task->lifts[1].active = 1;
            player->unk74 = 0;
            break;
        case 0x37B:
            task->pushing = 1;
            return;
        }
        if (anim != 0) {
            for (i = 0; i < 11; i++) {
                if (anim == task->risers[i].tileAnim) {
                    task->risers[i].active = 1;
                }
            }
            SOUND.playSound(0xEC0001);
        }
    }
}

void *func_800A5270(s32 arg) {
    return createTaskWithId(func_800A4E9C, 0x14C, 0, arg);
}

/* Creates the event object of story progress 15 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xF) {
            children[0] = FIELDSTG_startEvent(0x19C);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x62D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x63D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x9F00, 0x8500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3B;
    D_800990B4.music = 0x60EC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

extern StageRiserFrame D_800A5618[];
extern StageRiserFrame D_800A5628[];
extern StageRiserFrame D_800A5638[];
extern u16 D_800A56E8[];
extern FieldActorEntry D_800A56F4;
extern s16 D_800A5438[];

s16 D_800A5438[] = {
    0x601, 1, 0xA2, 0x7A,
    0x100, 1, 0x104, 0xBA,
    0x101, 1, 1, 3,
    0x101, 0x32E, 0x344, 1,
    0x300, 0x1E,
    0x102, 1, 0x90, 0x80, 1,
    0x302, 1,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x3A, 1,
    0x300, 0x3C,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 1, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x32E, 0x33D, 0x32E,
    0x303, 0x32E,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x101, 0x32D, 0x369, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x101, 1, 1, 7,
    0x300, 0x3C,
    0x101, 0x32E, 0x33E, 0x32E,
    0x303, 0x32E,
    0x300, 0x1E,
    0x200, 0, 2, 1, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x32E, 0x33F, 0x32E,
    0x303, 0x32E,
    0x300, 0x3C,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 1, 0xB0, 0x70, 1,
    0x302, 1,
    0x101, 0x32E, 0x340, 0x32E,
    0x303, 0x32E,
    0x101, 1, 1, 1,
    0x300, 0x3C,
    0x101, 0x32E, 0x341, 0x32E,
    0x303, 0x32E,
    0x101, 1, 0x33, 7,
    0x300, 0x1E,
    0x200, 0, 3, 1, 0,
    0x101, 1, 1, 7,
    0x301,
    0x300, 0x1E,
    0x101, 1, 1, 7,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 1, 0x90, 0x60, 7,
    0x302, 1,
    0x101, 0x32E, 0x342, 0x32E,
    0x303, 0x32E,
    0x300, 0x5A,
    0x101, 0x32E, 0x343, 0x32E,
    0x303, 0x32E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x101, 1, 0x25, 7,
    0x300, 0x1E,
    0x200, 0, 4, 1, 3,
    0x301,
    0x101, 0x32E, 0x37B, 1,
    0x300, 0x5A,
    0x304, 0x260, 0x330, 0x108, 0,
    0,
};
StageRiserFrame D_800A5618[] = {
    { 14, 6, 0 },
    { 15, 6, 0 },
    { 16, 6, 0 },
    { 255, 0, 72 },
};
StageRiserFrame D_800A5628[] = {
    { 10, 6, 0 },
    { 11, 6, 0 },
    { 12, 6, 0 },
    { 255, 0, 80 },
};
StageRiserFrame D_800A5638[] = {
    { 5, 6, 0 },
    { 6, 6, 0 },
    { 7, 6, 0 },
    { 8, 6, 0 },
    { 255, 0, 80 },
};
StageRiserFrame *D_800A564C[] = {
    D_800A5618,
    D_800A5628,
    D_800A5618,
    D_800A5628,
    D_800A5628,
    D_800A5618,
    D_800A5638,
    D_800A5618,
    D_800A5628,
    D_800A5638,
    D_800A5638,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x164, 0xD8, 0x64, 0x150, 0x1FF },
};
u16 D_800A56E8[] = { 0x600F, 1, 0x401C, 0, 0xFFFF };
FieldActorEntry D_800A56F4 = { D_800A56E8, NULL, 1, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A56F4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 56, 56, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 124, 22, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 240, 176, 0, 0 },
    { 1, 1, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 208, 160, 0, 0 },
    { 1, 2, 0x40, 6, 9, 0, 0, 0, 0, 0, 176, 144, 0, 0 },
    { 1, 3, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 112, 144, 0, 0 },
    { 1, 3, 0x40, 6, 9, 0, 0, 0, 0, 0, 80, 128, 0, 0 },
    { 1, 4, 0x40, 6, 9, 0, 0, 0, 0, 0, 144, 128, 0, 0 },
    { 1, 3, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 48, 112, 0, 0 },
    { 1, 4, 0x40, 6, 4, 0, 0, 0, 0, 0, 112, 112, 0, 0 },
    { 1, 5, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 176, 112, 0, 0 },
    { 1, 4, 0x40, 6, 9, 0, 0, 0, 0, 0, 80, 96, 0, 0 },
    { 1, 6, 0x40, 6, 4, 0, 0, 0, 0, 0, 144, 96, 0, 0 },
    { 1, 7, 0x40, 6, 4, 0, 0, 0, 0, 0, 112, 80, 0, 0 },
    { 1, 8, 0x40, 6, 0, 0, 0, 0, 0, 0, 55, 119, 0, 0 },
    { 1, 0xA, 0x40, 6, 1, 0, 0, 0, 0, 0, 122, 85, 0, 0 },
    { 1, 9, 0x40, 6, 2, 0, 0, 0, 0, 0, 216, 127, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 412, D_800A5438, EVENT_TEXT(2), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
