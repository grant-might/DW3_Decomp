#include "common.h"
#include "stage.h"
extern AnimFrame *D_800A67B4[];
extern s8 D_800A67C0[];
extern s8 D_800A67C4[];

/* Creates the event object of flag 0x40CD while it is clear */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(FLAG(0x40, 0xCD), 0)) {
            children[0] = FIELDSTG_startEvent(0x640);
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

/* Applies flag actions 0x40CD and 0x7053 */
void func_800A5EC0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xCD), 1);
    FLAGS_00.applyAction(SPECIAL(0x53), 1);
}

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0xFD;
    FIELDSTG_state.mapFile = 0x19E;
    FIELDSTG_state.sheetEntry = 0x8E90000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x8E8;
    FIELDSTG_state.start = (Vec2){0xFD00, 0x17700};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x33;
    FIELDSTG_state.music = MUSIC(0x33, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, 0x8E90001);
    FIELDSTG_map.setFile(7, 0x8E90002);
    FIELDSTG_map.setFirstMap(0);
}

#include "common/step_animation_once.inc.c"

void func_800A60D8(StageTileEffect *task) {
    s32 i;

    for (i = 0; i < 3; i++) {
        task->anims[i].anim.index = 0;
        task->anims[i].anim.timer = D_800A67B4[i][0].duration;
    }
}

/* Moves the records with animations 1 to 3 to (x, y) and plays their animations once with a sound, then hides them and kills itself */
void func_800A6110(StageTileEffect *task) {
    StageTile *rec;
    StageTile *tile;
    s32 i;
    s32 j;
    s32 k;
    s32 done;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        func_800A60D8(task);
        task->nextState(task);
        task->setSubstate(task, 1);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            break;
        case 1:
            switch (task->step) {
            case 0:
                i = 0;
                for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
                    if (rec->anim >= 1 && rec->anim <= 3) {
                        task->anims[i].tile = rec;
                        rec->x = task->x;
                        rec->y = task->y + D_800A67C4[i];
                        rec->unkE = task->y + D_800A67C0[i];
                        i++;
                    }
                }
                SOUND.playSound(SOUND_LOGINEF);
                task->nextStep(task);
            case 1:
                done = 0;
                for (j = 0; j < 3; j++) {
                    tile = task->anims[j].tile;
                    frame = stepAnimationOnce(&task->anims[j], D_800A67B4[j], 0);
                    switch (frame) {
                    case 0xFF:
                        done++;
                    case 0x12C:
                        tile->visible = 0;
                        tile->frame = 0;
                        break;
                    default:
                        tile->visible = 1;
                        tile->frame = frame;
                        break;
                    }
                }
                if (done < 3) {
                    break;
                }
                task->nextStep(task);
            case 2:
                for (k = 0; k < 3; k++) {
                    task->anims[k].tile->visible = 0;
                }
                func_800A60D8(task);
                task->setState(task, TASK_KILL);
                break;
            }
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates the StageTileEffect of func_800A6110 at (0x150, 0x112) with the given id */
void *func_800A639C(s32 id) {
    StageTileEffect *task = createTaskWithId(func_800A6110, sizeof(StageTileEffect), 0, id);

    task->x = 0x150;
    task->y = 0x112;
    return task;
}

extern s16 script1600[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x1B8, 0x28, 0xB8, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x1B0, 0xC0, 0xB0, 0x160, 0x1FD },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x26 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(0x40, 0xCD), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0xD, 5, 265, 397, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x50, 6, 0x46, 0, 0, 0, 0, 0, 112, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 116, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 228, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 340, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 355, 346, 0, 0 },
    { 0, 2, 0x50, 4, 0x48, 0, 0, 0, 0, 0, 112, 227, 301, 0 },
    { 0, 3, 0x50, 4, 0x55, 0, 0, 0, 0, 0, 112, 227, 294, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 116, 274, 300, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 228, 298, 324, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 340, 274, 300, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 355, 362, 388, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x273, 0x2DA, 0x17E, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1600, script1600, EVENT_TEXT(0), NULL, func_800A5EC0 },
    { -1, NULL, 0, NULL, NULL },
};
s16 script1600[] = {
    0x601, 1, 0x11E, 0x127,
    0x100, 1, 0, 0,
    0x101, 1, 1, 0,
    0x100, 0xD, 0x10F, 0x191,
    0x101, 0xD, 1, 3,
    0x300, 0x78,
    0x300, 0x1E,
    0x101, 0x357, 0x335, 1,
    0x300, 0x5A,
    0x300, 0x5A,
    0x100, 1, 0x170, 0x11F,
    0x101, 1, 1, 1,
    0x300, 0xB4,
    0x300, 0x1E,
    0x102, 1, 0x150, 0x130, 1,
    0x302, 1,
    0x101, 1, 0x3A, 1,
    0x300, 0xB4,
    0x200, 0, 1, 1, 0,
    0x101, 1, 1, 1,
    0x301,
    0x300, 0x1E,
    0x102, 1, 0x130, 0x160, 1,
    0x302, 1,
    0x600, 0, 1,
    0x102, 1, 0xF0, 0x180, 1,
    0x302, 1,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0xD, 2,
    0x101, 0xD, 7, 3,
    0x301,
    0x101, 0xD, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 1, 1,
    0x101, 1, 7, 7,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x200, 0, 4, 1, 1,
    0x301,
    0x300, 0x1E,
    0x102, 1, 0x50, 0x1D0, 1,
    0x101, 0xD, 1, 1,
    0x300, 0x5A,
    0x304, 0x273, 0x2DA, 0x17E, 1,
    0,
};
AnimFrame D_800A6710[] = {
    { 70, 4 }, { 71, 4 }, { 70, 4 }, { 71, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A6724[] = {
    { 0x12C, 56 }, { 85, 6 }, { 86, 6 }, { 87, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 88, 4 },
    { 89, 4 }, { 90, 4 }, { 88, 4 }, { 89, 4 },
    { 90, 4 }, { 88, 4 }, { 89, 4 }, { 90, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A6774[] = {
    { 0x12C, 16 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 73, 4 }, { 75, 6 }, { 76, 6 }, { 77, 14 },
    { 78, 114 }, { 79, 6 }, { 80, 6 }, { 81, 6 },
    { 82, 6 }, { 83, 6 }, { 84, 8 }, { 255, 0x3E7 },
};
AnimFrame *D_800A67B4[] = {
    D_800A6710, D_800A6774, D_800A6724,
};
s8 D_800A67C0[] = {
    30, 30, 30, 0,
};
s8 D_800A67C4[] = {
    0, -47, -47,
};
