#include "common.h"
#include "stage.h"
extern s16 D_800A555C[];

/* Moves the two records and the player 0x7F up or down when an event sets TASK_DONE */
void func_800A4CC0(StageTileLift *task) {
    StageTile *rec;
    StageTile *tile0;
    StageTile *tile1;
    StageActor *player;
    s32 d;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 2:
                task->tiles[1] = rec;
                task->homeY[1] = rec->y;
                if (task->down) {
                    rec->y -= 0x7F;
                }
                rec->visible = 0;
                break;
            case 3:
                task->tiles[0] = rec;
                task->homeY[0] = rec->y;
                if (task->down) {
                    rec->y -= 0x7F;
                }
                rec->visible = 1;
                break;
            }
        }
        task->down = 0;
        break;
    case TASK_RUN:
        break;
    case TASK_DONE:
        tile0 = task->tiles[0];
        tile1 = task->tiles[1];
        player = TASK_REGISTRY.funcs.find(5, -1, 0);
        switch (task->substate) {
        case 0:
        default:
            tile1->visible = 1;
            task->timer = 0;
            task->y[0] = tile0->y;
            task->y[1] = tile1->y;
            task->playerY = player->y;
            SOUND.playSound(SOUND_SWITCH01);
            task->nextSubstate(task);
            break;
        case 1:
            task->timer += GFX.funcs.getFrameTime();
            if (task->timer >= 0x1E) {
                task->shake = 0;
                task->nextSubstate(task);
                SOUND.playSound(SOUND_ELEVATER);
            }
            break;
        case 2:
        case 4:
            d = D_800A555C[task->shake];
            if (d != 0x3E8) {
                tile0->y = task->y[0] + d;
                tile1->y = task->y[1] + d;
                player->y = task->playerY + d;
                task->shake++;
            } else {
                task->nextSubstate(task);
                task->shake = 0;
            }
            break;
        case 3:
            if (++task->shake >= 0xFE) {
                if (task->down) {
                    tile0->y = task->homeY[0];
                    tile1->y = task->homeY[1];
                    player->y = task->playerY + 0x7F00;
                } else {
                    tile0->y = task->homeY[0] - 0x7F;
                    tile1->y = task->homeY[1] - 0x7F;
                    player->y = task->playerY - 0x7F00;
                }
                task->y[0] = tile0->y;
                task->y[1] = tile1->y;
                task->playerY = player->y;
                task->nextSubstate(task);
                task->shake = 0;
            } else if (task->shake & 1) {
                if (task->down) {
                    tile0->y++;
                    tile1->y++;
                    player->y += 0x100;
                } else {
                    tile0->y--;
                    tile1->y--;
                    player->y -= 0x100;
                }
            }
            break;
        case 5:
            tile1->visible = 0;
            task->setState(task, TASK_RUN);
            task->down ^= 1;
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Ends the task when map object 0x348 (down = 0) or 0x349 (down = 1) is triggered */
void func_800A50DC(StageTileLift *task, s32 id) {
    if (task != NULL) {
        switch (id) {
        case 0x348:
            task->setState(task, TASK_DONE);
            task->down = 0;
            break;
        case 0x349:
            task->setState(task, TASK_DONE);
            task->down = 1;
            break;
        }
    }
}

/* Creates the task of func_800A4CC0, down set from flag 0x1C3D */
StageTileLift *func_800A5150(s32 id) {
    StageTileLift *task = createTaskWithId(func_800A4CC0, sizeof(StageTileLift), 0, id);

    if (FLAGS_00.checkCondition(FLAG(0x1C, 0x3D), 1)) {
        task->down = 1;
    } else {
        task->down = 0;
    }
    return task;
}

/* The stage task: creates the object of map object 0x33B */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        children[0] = func_800A5150(0x33B);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

/* the color the setup copies to FIELDSTG_state.spriteColor */
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0 };

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x517
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x527
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x10300, 0x18500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x42;
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.music = MUSIC(0x42, 2);
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(1, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1321[] = {
    0x102, 2, 0xBF, 0x190, 3,
    0x100, 0x3F, 0xB0, 0x188,
    0x101, 0x3F, 1, 0,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 0x32D, 0x36C, 2,
    0x300, 0x3C,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0xEC, 0x178, 5,
    0x302, 2,
    0x102, 2, 0x108, 0x184, 7,
    0x302, 2,
    0x200, 0, 1, 2, 0,
    0x101, 2, 1, 3,
    0x301,
    0x100, 0x3F, 0xB0, 0x109,
    0x101, 0x3F, 1, 0,
    0x101, 0x33B, 0x348, 2,
    0x300, 0x12C,
    0x300, 0x1E,
    0,
};
s16 script1326[] = {
    0x102, 2, 0xBF, 0x111, 3,
    0x100, 0x3F, 0xB0, 0x109,
    0x101, 0x3F, 1, 0,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 0x32D, 0x36C, 2,
    0x300, 0x3C,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0xEF, 0xF9, 5,
    0x302, 2,
    0x102, 2, 0x108, 0x105, 7,
    0x302, 2,
    0x200, 0, 1, 2, 0,
    0x101, 2, 1, 3,
    0x301,
    0x100, 0x3F, 0xB0, 0x188,
    0x101, 0x3F, 1, 0,
    0x101, 0x33B, 0x349, 2,
    0x300, 0x12C,
    0x300, 0x1E,
    0,
};
s16 D_800A555C[] = {
    1, 2, 1, 0, -1, -2, -1, 0,
    0x3E8, 0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 actor0Talk0Conditions[] = { FLAG(0x1C, 0x3D), 0, CODES_END };
u16 actor0Talk0Actions[] = { START_EVENT(0x62), 1, FLAG(0x1C, 0x3D), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0x1C, 0x3D), 1, CODES_END };
u16 actor0Talk1Actions[] = { START_EVENT(0x63), 1, FLAG(0x1C, 0x3D), 0, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0x1C, 0x3D), 0, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x62), 1, FLAG(0x1C, 0x3D), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0x1C, 0x3D), 1, CODES_END };
u16 actor1Talk1Actions[] = { START_EVENT(0x63), 1, FLAG(0x1C, 0x3D), 0, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x203 },
    { actor0Talk1Conditions, actor0Talk1Actions, 0x204 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x203 },
    { actor1Talk1Conditions, actor1Talk1Actions, 0x204 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(0x1C, 0x3D), 0, CODES_END };
u16 actor1Conditions[] = { FLAG(0x1C, 0x3D), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x3F, 4, 176, 392, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x3F, 4, 176, 265, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x44, 2, 0x3A, 2, 0, 1, 4, 0, 312, 282, 0, 0 },
    { 1, 2, 0x40, 2, 0x32, 1, 0x32, 0x39, 4, 0, 135, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 0, 0, 0, 0, 0, 328, 194, 0, 0 },
    { 1, 0, 0x40, 6, 1, 0, 0, 0, 0, 0, 192, 417, 0, 0 },
    { 1, 3, 0xCD, 6, 0, 0, 0, 0, 0, 0, 160, 338, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 0, 0, 0, 0, 0, 328, 272, 0, 0 },
    { 1, 0, 0x48, 0xA, 0x14, 0, 0, 0, 0, 0, 128, 202, 0, 0 },
    { 1, 0, 0x49, 0xA, 0x15, 0, 0, 0, 0, 0, 200, 183, 0, 0 },
    { 1, 0, 0x40, 4, 0x3D, 0, 0, 0, 0, 0, 336, 166, 193, 0 },
    { 1, 0, 0x40, 8, 0x3F, 0, 0, 0, 0, 0, 336, 244, 277, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x271, 0x368, 0xF4, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x281, 0x2FE, 0xA5, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 5, 8, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1321, script1321, EVENT_TEXT(0x2E), NULL, NULL },
    { 1326, script1326, EVENT_TEXT(0x2F), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
