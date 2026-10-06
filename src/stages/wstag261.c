#include "common.h"
#include "stage.h"
void func_800A4CC0();
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
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
            SOUND.playSound(0x8004103C);
            task->nextSubstate(task);
            break;
        case 1:
            task->timer += GFX.funcs.getFrameTime();
            if (task->timer >= 0x1E) {
                task->shake = 0;
                task->nextSubstate(task);
                SOUND.playSound(0x1080001);
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

    if (FLAGS_00.checkCondition(0x1C3D, 1)) {
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

/* the color the setup copies to D_800990B4.spriteColor */
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10300, 0x18500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x42;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.music = 0x61080002;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 3);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A55E0[];
extern u16 D_800A55E8[];
extern u16 D_800A55F4[];
extern u16 D_800A55FC[];
extern u16 D_800A5608[];
extern u16 D_800A5610[];
extern u16 D_800A561C[];
extern u16 D_800A5624[];
extern u16 D_800A5678[];
extern FieldTalk D_800A5630[];
extern u16 D_800A5680[];
extern FieldTalk D_800A5654[];
extern FieldActorEntry D_800A5688;
extern FieldActorEntry D_800A569C;
extern s16 D_800A5394[];
extern s16 D_800A5478[];

s16 D_800A5394[] = {
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
s16 D_800A5478[] = {
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
u16 D_800A55E0[] = { 0x1C3D, 0, 0xFFFF };
u16 D_800A55E8[] = { 0x9062, 1, 0x1C3D, 1, 0xFFFF };
u16 D_800A55F4[] = { 0x1C3D, 1, 0xFFFF };
u16 D_800A55FC[] = { 0x9063, 1, 0x1C3D, 0, 0xFFFF };
u16 D_800A5608[] = { 0x1C3D, 0, 0xFFFF };
u16 D_800A5610[] = { 0x9062, 1, 0x1C3D, 1, 0xFFFF };
u16 D_800A561C[] = { 0x1C3D, 1, 0xFFFF };
u16 D_800A5624[] = { 0x9063, 1, 0x1C3D, 0, 0xFFFF };
FieldTalk D_800A5630[] = {
    { D_800A55E0, D_800A55E8, 0x203 },
    { D_800A55F4, D_800A55FC, 0x204 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5654[] = {
    { D_800A5608, D_800A5610, 0x203 },
    { D_800A561C, D_800A5624, 0x204 },
    { NULL, NULL, 0 },
};
u16 D_800A5678[] = { 0x1C3D, 0, 0xFFFF };
u16 D_800A5680[] = { 0x1C3D, 1, 0xFFFF };
FieldActorEntry D_800A5688 = { D_800A5678, D_800A5630, 0x3F, 4, 176, 392, 1 };
FieldActorEntry D_800A569C = { D_800A5680, D_800A5654, 0x3F, 4, 176, 265, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5688,
    &D_800A569C,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x271, 0x368, 0xF4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x281, 0x2FE, 0xA5, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 5, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1321, D_800A5394, EVENT_TEXT(0x2E), NULL, NULL },
    { 1326, D_800A5478, EVENT_TEXT(0x2F), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
