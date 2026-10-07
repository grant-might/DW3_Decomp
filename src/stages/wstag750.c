#include "common.h"
#include "stage.h"
extern AnimFrame *D_800A6100[];
extern StageEffectSpot D_800A6118[];
extern s8 D_800A610C[];
extern s8 D_800A6110[];
extern s16 D_800A6114[][2];

#include "common/step_animation_once.inc.c"

void func_800A4D7C(StageTileEffect *task) {
    s32 i;

    for (i = 0; i < 3; i++) {
        task->anims[i].anim.index = 0;
        task->anims[i].anim.timer = D_800A6100[i][0].duration;
    }
}

/* Moves its records to (x, y) and animates them when the substate is set to 1 */
void func_800A4DB4(StageTileEffect *task) {
    StageTile *tile;
    StageTile *t;
    s32 i;
    s32 n;
    s32 j;
    s32 frame;
    s32 done;

    switch (task->state) {
    case TASK_INIT:
    default:
        func_800A4D7C(task);
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            break;
        case 1:
            switch (task->step) {
            case 0:
                n = 0;
                for (t = FIELDSTG_state.objects; t->unk2 != 0; t++) {
                    if (t->anim >= 1 && t->anim <= 3) {
                        task->anims[n].tile = t;
                        t->x = task->x;
                        t->y = task->y + D_800A6110[n];
                        t->unkE = task->y + D_800A610C[n];
                        n++;
                    }
                }
                SOUND.playSound(SOUND_ENTRY_02);
                task->nextStep(task);
            case 1:
                done = 0;
                for (i = 0; i < 3; i++) {
                    tile = task->anims[i].tile;
                    frame = stepAnimationOnce(&task->anims[i], D_800A6100[i], 0);
                    switch (frame) {
                    case 0xFF:
                        done++;
                        tile->visible = 0;
                        tile->frame = 0;
                        break;
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
                for (j = 0; j < 3; j++) {
                    task->anims[j].tile->visible = 0;
                }
                func_800A4D7C(task);
                task->setSubstate(task, 0);
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

/* Starts the effect at the place of map 0x335 */
void func_800A5034(StageTileEffect *task, s32 id) {
    s32 i;

    if (task != NULL) {
        i = 0;
        switch (id) {
        case 0x335:
            task->x = D_800A6114[i][0];
            task->y = D_800A6114[i][1];
            task->setSubstate(task, 1);
            break;
        }
    }
}

void *func_800A5084(s32 arg) {
    return createTaskWithId(func_800A4DB4, 0x70, 0, arg);
}

/* Creates the stage's effect, the event object of story progress 0x20 that applies, and another object */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (D_800A6118[0].kind == 0) {
            children[0] = createStageEffect(D_800A6118[0].x, D_800A6118[0].y, D_800A6118[0].frame);
        }
        if (GAME.progress == 0x20 && FLAGS_00.checkCondition(FLAG(0x40, 0x48), 0) && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 0) &&
            FLAGS_00.checkCondition(FLAG(0x40, 0x66), 0)) {
            children[2] = FIELDSTG_startEvent(0x35C);
        } else if (GAME.progress == 0x20 && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x48), 0) &&
                   FLAGS_00.checkCondition(FLAG(0x40, 0x47), 0) && FLAGS_00.checkCondition(FLAG(0x40, 0x66), 0)) {
            children[2] = FIELDSTG_startEvent(0x373);
        } else if (GAME.progress == 0x20 && FLAGS_00.checkCondition(FLAG(0x40, 0x48), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x46), 0) &&
                   FLAGS_00.checkCondition(FLAG(0x40, 0x62), 0) && FLAGS_00.checkCondition(FLAG(0x40, 0x66), 0)) {
            children[2] = FIELDSTG_startEvent(0x374);
        } else if (GAME.progress == 0x20 && FLAGS_00.checkCondition(FLAG(0x40, 0x66), 1)) {
            children[2] = FIELDSTG_startEvent(0x376);
        }
        children[1] = func_800A5084(0x34E);
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A58FC(void) {
    GAME.progress = 32;
}

void func_800A590C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x48), 1);
}

void func_800A5938(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x47), 1);
}

void func_800A5964(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x62), 1);
}

void func_800A5990(void) {
    GAME.progress = 33;
}

void func_800A59A0(void) {
    FLAGS_00.applyAction(0x7C0A, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6B2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6C1
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x12A00, 0x1D200};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x40;
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.music = MUSIC(0x40, 1);
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script820[] = {
    0x102, 2, 0xA0, 0x128, 3,
    0x101, 0xD, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x78,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0xD, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0xD, 9, 7,
    0x303, 0xD,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x200, 0, 3, 0xD, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0xD, 1, 3,
    0x300, 0x1E,
    0x102, 0xD, 0x6F, 0x110, 3,
    0x302, 0xD,
    0x101, 0xD, 1, 3,
    0x300, 0x1E,
    0x101, 0xD, 2, 3,
    0x300, 0x78,
    0x101, 0xD, 1, 3,
    0x300, 0x5A,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x102, 0xD, 0x81, 0x119, 7,
    0x302, 0xD,
    0x101, 0xD, 1, 7,
    0x300, 0x1E,
    0x200, 0, 4, 0xD, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 6, 0xD, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0xD, 2,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x160, 0xC8, 5,
    0x302, 2,
    0x601, 1, 0x160, 0xC8,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0x101, 0x34E, 0x335, 2,
    0x300, 0x78,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0x300, 0x3C,
    0x304, 0x2DA, 0x45F, 0x37D, 1,
    0,
};
s16 script860[] = {
    0x601, 1, 0xF0, 0xE0,
    0x100, 2, 0, 0,
    0x101, 2, 1, 0,
    0x100, 0xD, 0x81, 0x119,
    0x101, 0xD, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 4,
    0x301,
    0x601, 0, 0xD0, 0xF0,
    0x101, 0x323, 0x325, 0xD,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xD,
    0x300, 0x1E,
    0x102, 0xD, 0x6F, 0x110, 3,
    0x302, 0xD,
    0x101, 0xD, 2, 3,
    0x300, 0x3C,
    0x601, 0, 0xF0, 0xE0,
    0x300, 0x3C,
    0x101, 0x34E, 0x335, 2,
    0x300, 0x78,
    0x100, 2, 0x15E, 0xCA,
    0x101, 2, 1, 1,
    0x300, 0x5A,
    0x601, 0, 0xD0, 0xF0,
    0x200, 0, 2, 0xD, 2,
    0x301,
    0x600, 0, 2,
    0x101, 0xD, 1, 7,
    0x300, 0x3C,
    0x102, 0xD, 0x81, 0x119, 7,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x3C,
    0x200, 0, 4, 2, 3,
    0x301,
    0x304, 0x2DC, 1, 1, 0,
    0,
};
s16 script883[] = {
    0x601, 1, 0xF0, 0xE0,
    0x100, 2, 0, 0,
    0x101, 2, 1, 0,
    0x100, 0xD, 0x81, 0x119,
    0x101, 0xD, 1, 7,
    0x300, 0x78,
    0x200, 0, 3, 2, 4,
    0x301,
    0x601, 0, 0xD0, 0xF0,
    0x101, 0x323, 0x325, 0xD,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xD,
    0x300, 0x1E,
    0x102, 0xD, 0x6F, 0x110, 3,
    0x302, 0xD,
    0x101, 0xD, 2, 3,
    0x300, 0x3C,
    0x601, 0, 0xF0, 0xE0,
    0x300, 0x3C,
    0x101, 0x34E, 0x335, 2,
    0x300, 0x78,
    0x100, 2, 0x15E, 0xCA,
    0x101, 2, 1, 1,
    0x300, 0x5A,
    0x601, 0, 0xD0, 0xF0,
    0x200, 0, 1, 0xD, 2,
    0x301,
    0x600, 0, 2,
    0x101, 0xD, 1, 7,
    0x300, 0x3C,
    0x102, 0xD, 0x81, 0x119, 7,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 2,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 1, 7,
    0x301,
    0x300, 0x1E,
    0x304, 0x2D7, 0, 0, 1,
    0,
};
s16 script884[] = {
    0x100, 2, 0x15E, 0xCA,
    0x101, 2, 1, 1,
    0x100, 0xD, 0x81, 0x119,
    0x101, 0xD, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 2,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 2, 1, 7,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x301,
    0x300, 0x1E,
    0x304, 0x2D7, 0x64, 0x64, 0,
    0,
};
s16 script886[] = {
    0x100, 2, 0x15E, 0xCA,
    0x101, 2, 1, 7,
    0x100, 0xD, 0x81, 0x119,
    0x101, 0xD, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 1, 1,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xA0, 0x128, 1,
    0x300, 0x3C,
    0x304, 0x26A, 0x3C0, 0x50, 7,
    0,
};
s16 script1245[] = {
    0x102, 2, 0x100, 0x1C8, 3,
    0x100, 0x15, 0xE0, 0x1B9,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC08, 0, 0, 0,
    0,
};
AnimFrame D_800A605C[] = {
    { 70, 4 }, { 71, 4 }, { 70, 4 }, { 71, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A6070[] = {
    { 0x12C, 56 }, { 85, 6 }, { 86, 6 }, { 87, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 88, 4 },
    { 89, 4 }, { 90, 4 }, { 88, 4 }, { 89, 4 },
    { 90, 4 }, { 88, 4 }, { 89, 4 }, { 90, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A60C0[] = {
    { 0x12C, 16 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 73, 4 }, { 75, 6 }, { 76, 6 }, { 77, 14 },
    { 78, 114 }, { 79, 6 }, { 80, 6 }, { 81, 6 },
    { 82, 6 }, { 83, 6 }, { 84, 8 }, { 255, 0x3E7 },
};
AnimFrame *D_800A6100[] = {
    D_800A605C, D_800A60C0, D_800A6070,
};
s8 D_800A610C[] = {
    30, 30, 30, 0,
};
s8 D_800A6110[] = {
    0, -0x2F, -0x2F, 0,
};
s16 D_800A6114[][2] = {
    { 0x140, 186 },
};
StageEffectSpot D_800A6118[] = {
    { 28, 0, 108, 0x144 },
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
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x1B0, 0xD8, 0xB0, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x164, 0x1C8, 0x90, 0xC8, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x14A, 0x1B0, 0x28, 0xB0, 0x150, 0x1F7 },
    { 0x180, 0x100, 0x194, 0x140, 0x150, 0x40, 0x160, 0x1F7 },
    { 0x180, 0x100, 0x19C, 0x148, 0x170, 0x48, 0x170, 0x1F7 },
};
u16 actor0Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor0Talk1Conditions[] = { ITEM(0, 0xC), 0, FLAG(0, 0), 1, CODES_END };
u16 actor0Talk2Conditions[] = { ITEM(0, 0xC), 1, FLAG(0x1C, 2), 0, FLAG(0, 0), 1, CODES_END };
u16 actor0Talk2Actions[] = { START_EVENT(0x45), 1, FLAG(0x1C, 2), 1, CODES_END };
u16 actor0Talk3Conditions[] = { ITEM(0, 0xC), 1, FLAG(0x1C, 2), 1, FLAG(0, 0), 1, CODES_END };
u16 actor1Talk0Actions[] = { 0x7A27, 1, CODES_END };
u16 actor2Talk0Actions[] = { START_EVENT(0x19), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x30B },
    { actor0Talk1Conditions, NULL, 0x30C },
    { actor0Talk2Conditions, actor0Talk2Actions, 0x30D },
    { actor0Talk3Conditions, NULL, 0x30E },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x210 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x211 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x20E },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x20E },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x312 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0xA), 1, SPECIAL(0x1A), 0, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x21), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x23), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x1F), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x1E), 1, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0xD, 4, 129, 281, 7 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x14, 5, 162, 473, 7 };
FieldActorEntry actor2 = { NULL, actor2Talks, 0x15, 6, 224, 441, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x23, 7, 306, 456, 7 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x9D, 8, 129, 281, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    &actor12,
    &actor13,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x50, 6, 0x46, 0, 0, 0, 0, 0, 320, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 1, 0x60, 0x63, 6, 0, 324, 169, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 78, 233, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 93, 214, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 109, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 0xB, 8, 0, 78, 221, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 0xB, 8, 0, 93, 225, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 0xB, 8, 0, 109, 205, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 82, 234, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 139, 230, 0, 0 },
    { 0, 3, 0x50, 4, 0x55, 0, 0, 0, 0, 0, 320, 139, 206, 0 },
    { 0, 2, 0x50, 4, 0x48, 0, 0, 0, 0, 0, 320, 139, 213, 0 },
    { 1, 0, 0x40, 4, 0x5C, 1, 0x5C, 0x5F, 6, 0, 324, 185, 209, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26C, 0xB8, 0xB4, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xE, 0x26A, 0x3C0, 0x50, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 820, script820, EVENT_TEXT(0x19), NULL, func_800A58FC },
    { 860, script860, EVENT_TEXT(0x1C), NULL, func_800A590C },
    { 883, script883, EVENT_TEXT(0x1D), NULL, func_800A5938 },
    { 884, script884, EVENT_TEXT(0x1E), NULL, func_800A5964 },
    { 886, script886, EVENT_TEXT(0x1F), NULL, func_800A5990 },
    { 1245, script1245, EVENT_TEXT(8), NULL, func_800A59A0 },
    { -1, NULL, 0, NULL, NULL },
};
