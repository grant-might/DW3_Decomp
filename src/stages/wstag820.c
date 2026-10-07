#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A6068[];
void *func_800A5638(s32 arg);
extern AnimFrame D_800A5FD8[];

#include "common/step_animation_once.inc.c"

/* Shows the record with animation 1, animated once, then hides it and kills itself */
void func_800A4D7C(StageTileTask *task) {
    StageTile *rec;
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->obj.tile = rec;
            }
        }
        task->obj.anim.index = 0;
        task->obj.anim.timer = D_800A5FD8[0].duration;
        break;
    case TASK_RUN:
        tile = task->obj.tile;
        tile->visible = 1;
        frame = stepAnimationOnce(&task->obj, D_800A5FD8, 0);
        if (frame != 0xFF) {
            tile->frame = frame;
        } else {
            tile->visible = 0;
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates the task of func_800A4D7C with the given id, with a sound */
void *func_800A4E78(s32 id) {
    void *task = createTaskWithId(func_800A4D7C, 0x58, 0, id);

    SOUND.playSound(SOUND_TELEPORT);
    return task;
}

/* Creates the stage's four objects and the event object of story progress 0x29 that applies */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 4; i++) {
            if (D_800A6068[i].kind == 0) {
                children[i + 1] = createStageEffect(D_800A6068[i].x, D_800A6068[i].y, D_800A6068[i].frame);
            } else if (D_800A6068[i].kind == 2) {
                children[i + 1] = func_800A5638(0x34D);
            }
        }
        do {
            if (GAME.progress == 0x29 && FLAGS_00.checkCondition(FLAG(0x40, 0x74), 0)) {
                children[0] = FIELDSTG_startEvent(0x424);
                break;
            }
            if (GAME.progress == 0x29 && FLAGS_00.checkCondition(FLAG(0x40, 0x74), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x75), 0)) {
                children[0] = FIELDSTG_startEvent(0x42E);
                break;
            }
        } while (0);
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x14
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

/* Creates the StageEffect of updateStageEffect at (0x1CC, 0x1B4) with frame 0x3C */
void *func_800A5638(s32 id) {
    StageEffect *task = createTaskWithId(updateStageEffect, sizeof(StageEffect), 0, id);

    task->x = 0x1CC;
    task->y = 0x1B4;
    task->frame = 0x3C;
    return task;
}

/* Sets the task to TASK_DONE when the id is 0x335 */
void func_800A5680(Task *task, s32 id) {
    if (task != NULL && id == 0x335) {
        task->setState(task, TASK_DONE);
    }
}

void func_800A56B8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x74), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A5704(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x75), 1);
}

/* Sets the progress to 43 and applies flag action 0x7401 */
void func_800A5730(void) {
    GAME.progress = 43;
    FLAGS_00.applyAction(EVENT_BATTLE(1), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x705
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x151
#define STAGE_FILE 0x715
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x24700, 0x18C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x44;
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.music = MUSIC(0x44, 1);
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1060[] = {
    0x100, 1, 0x310, 0x228,
    0x101, 1, 1, 3,
    0x100, 0x188, 0x242, 0x191,
    0x101, 0x188, 1, 3,
    0x300, 0x1E,
    0x102, 1, 0x2C8, 0x204, 3,
    0x302, 1,
    0x102, 1, 0x2A8, 0x1DD, 3,
    0x302, 1,
    0x101, 1, 1, 3,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x102, 1, 0x288, 0x1B6, 3,
    0x302, 1,
    0x102, 1, 0x278, 0x1AE, 3,
    0x302, 1,
    0x101, 1, 1, 3,
    0x101, 0x188, 1, 7,
    0x300, 0x3C,
    0x200, 0, 1, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 1, 3,
    0x301,
    0x300, 0x3C,
    0x200, 0, 3, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 1, 3,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x3C,
    0x200, 0, 5, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 6, 1, 3,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x3C,
    0x200, 0, 7, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 1, 3,
    0x101, 1, 7, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x200, 0, 9, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 1, 3,
    0x101, 1, 0xC, 3,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x3C,
    0x200, 0, 0xB, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xC, 1, 3,
    0x101, 1, 0xC, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script1070[] = {
    0x100, 2, 0x278, 0x1AE,
    0x101, 2, 1, 3,
    0x100, 0x188, 0x242, 0x191,
    0x101, 0x188, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0x200, 0, 2, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x188, 1, 1,
    0x300, 0x1E,
    0x601, 0, 0x242, 0x1AA,
    0x101, 2, 1, 2,
    0x102, 0x188, 0x1DF, 0x1C0, 1,
    0x302, 0x188,
    0x101, 0x188, 1, 7,
    0x300, 0x1E,
    0x101, 0x32D, 0x37A, 2,
    0x101, 0x34D, 0x335, 2,
    0x300, 0x48,
    0x100, 0x188, 0, 0,
    0x101, 0x188, 1, 1,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 1, 2,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0,
};
s16 script1080[] = {
    0x601, 1, 0x180, 0x100,
    0x102, 2, 0x180, 0x100, 3,
    0x100, 0xD5, 0x150, 0xE8,
    0x101, 0xD5, 1, 3,
    0x100, 0xD7, 0xF9, 0xB1,
    0x101, 0xD7, 1, 7,
    0x100, 0xD8, 0x119, 0x76,
    0x101, 0xD8, 1, 7,
    0x100, 0xD9, 0x78, 0xC5,
    0x101, 0xD9, 1, 7,
    0x100, 0xDA, 0x79, 0x75,
    0x101, 0xDA, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0xF8, 0xBC,
    0x300, 0x5A,
    0x200, 0, 0x17, 0xD5, 4,
    0x301,
    0x101, 0x32D, 0x369, 2,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 0xD7, 0x50, 7,
    0x101, 0xD8, 0x50, 7,
    0x101, 0xD9, 0x50, 7,
    0x101, 0xDA, 0x50, 7,
    0x101, 0x32D, 0x36E, 2,
    0x303, 0xD7,
    0x100, 0xD7, 0, 0,
    0x101, 0xD7, 1, 0,
    0x100, 0xD8, 0, 0,
    0x101, 0xD8, 1, 0,
    0x100, 0xD9, 0, 0,
    0x101, 0xD9, 1, 0,
    0x100, 0xDA, 0, 0,
    0x101, 0xDA, 1, 0,
    0x300, 0x3C,
    0x601, 0, 0x120, 0xCE,
    0x300, 0x3C,
    0x100, 0xD6, 0x120, 0xCE,
    0x101, 0xD6, 0x4F, 7,
    0x101, 0x32D, 0x378, 2,
    0x303, 0xD6,
    0x101, 0xD6, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0xD6, 2,
    0x301,
    0x101, 0xD5, 1, 7,
    0x300, 0x1E,
    0x600, 0, 0xD5,
    0x200, 0, 2, 0xD5, 4,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x601, 0, 0x120, 0xCE,
    0x300, 0x3C,
    0x200, 0, 4, 0xD6, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0xD5, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0xD6, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 7, 0xD5, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 0xD6, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 0xD5, 4,
    0x301,
    0x601, 0, 0x150, 0xE8,
    0x300, 0x3C,
    0x200, 0, 0xA, 0xD5, 4,
    0x101, 0xD5, 0x52, 1,
    0x101, 0xD6, 0x51, 7,
    0x101, 0x32D, 0x36F, 2,
    0x303, 0xD5,
    0x100, 0xD5, 0, 0,
    0x101, 0xD5, 1, 0,
    0x101, 0xD6, 1, 7,
    0x300, 0x5A,
    0x200, 0, 0xB, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0xC, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0xD6, 0x57, 7,
    0x101, 0x32D, 0x379, 2,
    0x303, 0xD6,
    0x100, 0xD6, 0, 0,
    0x101, 0xD6, 1, 0,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0xE0, 0x86,
    0x102, 2, 0x120, 0xD0, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x100, 0xD6, 0xC2, 0x74,
    0x101, 0xD6, 0x4F, 7,
    0x101, 0x32D, 0x378, 2,
    0x303, 0xD6,
    0x101, 0xD6, 1, 7,
    0x300, 0x3C,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x101, 0x32D, 0x373, 0x32D,
    0x300, 0x1E,
    0x200, 0, 0xD, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xE, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xF, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x10, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0x11, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0x12, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x13, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0x14, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x15, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0x16, 0xD6, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x372, 0x32D,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x355, 0x335, 2,
    0x300, 0x1E,
    0x101, 0x32D, 0x370, 2,
    0x300, 0x3C,
    0x100, 2, 0, 0,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0x101, 0x32D, 0x371, 2,
    0x300, 6,
    0x101, 0x32D, 0x373, 2,
    0x300, 0x1E,
    0,
};
AnimFrame D_800A5FD8[] = {
    { 61, 6 }, { 62, 6 }, { 63, 6 }, { 64, 6 },
    { 65, 4 }, { 66, 4 }, { 67, 4 }, { 65, 4 },
    { 66, 4 }, { 67, 4 }, { 65, 4 }, { 66, 4 },
    { 67, 4 }, { 65, 4 }, { 66, 4 }, { 67, 4 },
    { 65, 4 }, { 66, 4 }, { 67, 4 }, { 65, 4 },
    { 66, 4 }, { 67, 4 }, { 65, 4 }, { 66, 4 },
    { 67, 4 }, { 65, 4 }, { 66, 4 }, { 67, 4 },
    { 65, 4 }, { 66, 4 }, { 67, 4 }, { 64, 6 },
    { 63, 6 }, { 62, 6 }, { 61, 6 }, { 255, 0x3E7 },
};
StageEffectSpot D_800A6068[] = {
    { 60, 2, 0x1CC, 0x1B4 },
    { 60, 0, 0x1CC, 0x1B4 },
    { 60, 0, 0x28C, 0x155 },
    { 44, 0, 0x16C, 242 },
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
Battle area3Battle0 = { 33, 17, MUSIC(0x23, 0) };
Battle area3Battle1 = { 324, 21, MUSIC(0x24, 0) };
Battle area3Battle2 = { 325, 22, MUSIC(0x26, 0) };
Battle area3Battle3 = { 326, 22, MUSIC(0x26, 0) };
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
    { 141, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x178, 0x28, 0x78, 0x160, 0x1FC },
    { 0x140, 0x100, 0x152, 0x100, 0x48, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x140, 0x1FB },
    { 0x140, 0x100, 0x14A, 0x158, 0x28, 0x58, 0x150, 0x1FB },
    { 0x140, 0x100, 0x15A, 0x1C0, 0x68, 0xC0, 0x160, 0x1FB },
    { 0x140, 0x100, 0x170, 0x198, 0xC0, 0x98, 0x170, 0x1FB },
    { 0x140, 0x100, 0x16A, 0x1C0, 0xA8, 0xC0, 0x140, 0x1FA },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x150, 0x1F9 },
};
u16 actor0Conditions[] = { PROGRESS(0x29), 1, FLAG(0x40, 0x74), 0, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x29), 1, CODES_END };
u16 actor7Conditions[] = { FLAG(0x40, 0x75), 0, PROGRESS(0x29), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0xD5, 5, 336, 232, 3 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0xD6, 6, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0xD7, 7, 249, 177, 7 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0xD8, 8, 281, 118, 7 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0xD9, 9, 120, 197, 7 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0xDA, 0xA, 121, 117, 7 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0x188, 0xB, 578, 401, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x40, 2, 0x3D, 0, 0, 0, 0, 0, 268, 164, 208, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2DE, 0xA0, 0x7C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2DF, 0x180, 0xFE, 3, 0, 0, 0 },
    { { { FLAG(0x40, 0xA5), 0 }, { CODES_END, 0 } }, 8, 0x438, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1060, script1060, EVENT_TEXT(0xF), NULL, func_800A56B8 },
    { 1070, script1070, EVENT_TEXT(0x10), NULL, func_800A5704 },
    { 1080, script1080, EVENT_TEXT(0x11), NULL, func_800A5730 },
    { -1, NULL, 0, NULL, NULL },
};
