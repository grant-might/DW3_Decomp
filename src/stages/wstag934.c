#include "common.h"
#include "stage.h"
extern s16 D_800A65B8[];

/* Moves the two records and the player 0x7F up or down when an event sets TASK_DONE */
void func_800A5DFC(StageTileLift *task) {
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
            d = D_800A65B8[task->shake];
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

void func_800A6218(StageTileLift *task, s32 id) {
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

StageTileLift *func_800A628C(s32 id) {
    StageTileLift *task = createTaskWithId(func_800A5DFC, sizeof(StageTileLift), 0, id);

    if (FLAGS_00.checkCondition(FLAG(0x1C, 0x3D), 1)) {
        task->down = 1;
    } else {
        task->down = 0;
    }
    return task;
}

#include "common/update_stage.inc.c"

/* Creates the stage task (updateStage) of the given owner */
StageTask *startStage(void *owner) {
    StageTask *task = createTask(updateStage, 0x58, 8);

    task->owner = owner;
    stageFuncs[0]();
    return task;
}

/* the color the setup copies to FIELDSTG_state.spriteColor */
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0 };

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0xFD;
    FIELDSTG_state.mapFile = 0x1AC;
    FIELDSTG_state.sheetEntry = 0x8FB0000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x8FA;
    FIELDSTG_state.start = (Vec2){0x6700, 0x12300};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x42;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.music = MUSIC(0x42, 2);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_map.setFile(0, 0x8FB0001);
    FIELDSTG_map.setFile(1, 0x8FB0002);
    FIELDSTG_map.setFile(7, 0x8FB0003);
    FIELDSTG_map.setFirstMap(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

s16 D_800A65B8[] = {
    1, 2, 1, 0, -1, -2, -1, 0,
    0x3E8, 5,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x18C, 0x1DD, 0x130, 0xDD, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1EA, 0x13C, 0x2A8, 0x3C, 0x170, 0x1FE },
};
u16 actor1Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0, 0), 1, ITEM(0, 0x192), 0, CODES_END };
u16 actor1Talk1Actions[] = { ITEM(0, 0x192), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor1Talk2Conditions[] = { FLAG(0, 0), 1, ITEM(0, 0x192), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x41 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x3E },
    { actor1Talk1Conditions, actor1Talk1Actions, 0x3F },
    { actor1Talk2Conditions, NULL, 0x40 },
    { NULL, NULL, 0 },
};
FieldActorEntry actor0 = { NULL, actor0Talks, 0x2D, 4, 271, 361, 5 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x67, 5, 191, 400, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0x44, 2, 0x52, 2, 0, 1, 4, 0, 312, 282, 0, 0 },
    { 1, 2, 0x40, 2, 0x4A, 1, 0x4A, 0x51, 4, 0, 135, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 4, 0, 357, 161, 0, 0 },
    { 1, 0, 0x40, 6, 1, 0, 0, 0, 0, 0, 192, 417, 0, 0 },
    { 1, 0, 0x40, 6, 2, 1, 2, 7, 4, 0, 357, 161, 0, 0 },
    { 1, 3, 0xCD, 6, 0, 0, 0, 0, 0, 0, 160, 338, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x44, 1, 0x44, 0x49, 4, 0, 357, 241, 0, 0 },
    { 1, 0, 0x40, 0xA, 8, 1, 8, 0xD, 4, 0, 357, 241, 0, 0 },
    { 1, 0, 0x40, 0xA, 0xF, 1, 0xF, 0x13, 4, 0, 62, 326, 0, 0 },
    { 1, 0, 0x48, 0xA, 0x14, 0, 0, 0, 0, 0, 128, 202, 0, 0 },
    { 1, 0, 0x49, 0xA, 0x15, 0, 0, 0, 0, 0, 200, 183, 0, 0 },
    { 1, 0, 0x40, 4, 0x32, 1, 0x32, 0x37, 4, 0, 357, 161, 200, 0 },
    { 1, 0, 0x40, 8, 0x38, 1, 0x38, 0x3D, 4, 0, 357, 241, 280, 0 },
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
s32 D_800A6874 = (s32)startTween;
s32 D_800A6878 = (s32)updateTween;
