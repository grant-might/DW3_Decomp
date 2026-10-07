#include "common.h"
#include "stage.h"
extern AnimFrame *D_800A54E8[];
extern s8 D_800A54F4[];
extern s8 D_800A54F8[];
extern s16 D_800A54FC[][2];

#include "common/step_animation_once.inc.c"

void func_800A4D7C(StageTileEffect *task) {
    s32 i;

    for (i = 0; i < 3; i++) {
        task->anims[i].anim.index = 0;
        task->anims[i].anim.timer = D_800A54E8[i][0].duration;
    }
}

/* Once the substate is set to 1, moves the records of animations 1-3 to (x, y), plays a sound and animates them once */
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
                        t->y = task->y + D_800A54F8[n];
                        t->unkE = task->y + D_800A54F4[n];
                        n++;
                    }
                }
                SOUND.playSound(SOUND_LOGINEF);
                task->nextStep(task);
            case 1:
                done = 0;
                for (i = 0; i < 3; i++) {
                    tile = task->anims[i].tile;
                    frame = stepAnimationOnce(&task->anims[i], D_800A54E8[i], 0);
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

/* Starts the effect at the place of map object 0x346 or 0x347 */
void func_800A5038(StageTileEffect *task, s32 id) {
    s32 i;

    if (task != NULL) {
        i = 0;
        switch (id) {
        case 0x347:
            i = 1;
        case 0x346:
            task->x = D_800A54FC[i][0];
            task->y = D_800A54FC[i][1];
            task->setSubstate(task, 1);
            break;
        }
    }
}

void *func_800A50A4(s32 arg) {
    return createTaskWithId(func_800A4DB4, 0x70, 0, arg);
}

void *func_800A50D4(void) {
    return createTask(func_800A4DB4, 0x70, 0);
}

/* Creates the event object of progress 1 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 1) {
            children[0] = FIELDSTG_startEvent(5);
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

void func_800A51D4(void) {
    GAME.progress = 2;
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x191
#define STAGE_ARCHIVE 0x3BD
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x19F
#define STAGE_ARCHIVE 0x3CD
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0xFD00, 0x17700};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x33;
    FIELDSTG_state.music = MUSIC(0x33, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script5[] = {
    0x601, 1, 0x11E, 0x127,
    0x100, 1, 0, 0,
    0x101, 1, 1, 0,
    0x100, 0xD, 0x10F, 0x191,
    0x101, 0xD, 1, 3,
    0x101, 0x32F, 0x345, 1,
    0x300, 0x78,
    0x300, 0x1E,
    0x101, 0x32F, 0x346, 1,
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
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x101, 0xD, 1, 1,
    0x302, 1,
    0x102, 1, 0x50, 0x1D0, 7,
    0x300, 6,
    0x304, 0x203, 0x2DA, 0x17E, 1,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x8FB0\n");
#endif
AnimFrame D_800A5444[] = {
    { 70, 4 }, { 71, 4 }, { 70, 4 }, { 71, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A5458[] = {
    { 0x12C, 56 }, { 85, 6 }, { 86, 6 }, { 87, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 88, 4 },
    { 89, 4 }, { 90, 4 }, { 88, 4 }, { 89, 4 },
    { 90, 4 }, { 88, 4 }, { 89, 4 }, { 90, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A54A8[] = {
    { 0x12C, 16 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 73, 4 }, { 75, 6 }, { 76, 6 }, { 77, 14 },
    { 78, 114 }, { 79, 6 }, { 80, 6 }, { 81, 6 },
    { 82, 6 }, { 83, 6 }, { 84, 8 }, { 255, 0x3E7 },
};
AnimFrame *D_800A54E8[] = {
    D_800A5444, D_800A54A8, D_800A5458,
};
s8 D_800A54F4[] = {
    30, 30, 30, 0,
};
s8 D_800A54F8[] = {
    0, -0x2F, -0x2F, 0,
};
s16 D_800A54FC[][2] = {
    { 0x150, 0x112 }, { 112, 0x112 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x152, 0x1D0, 0x48, 0xD0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x1B0, 0xC0, 0xB0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x1B8, 0x28, 0xB8, 0x170, 0x1FD },
    { 0x140, 0x100, 0x162, 0x1D0, 0x88, 0xD0, 0x150, 0x1FC },
    { 0x140, 0x100, 0x15A, 0x1D0, 0x68, 0xD0, 0x160, 0x1FC },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x19A },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x19B },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x1A1 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x19C },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x19E },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x19F },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x1B1 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x1A0 },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0x1B0 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(1), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(2), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(4), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x15), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0xD), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x18), 1, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x16), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0xD), 1, CODES_END };
u16 actor15Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0xD, 5, 0, 0, 3 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x20, 6, 265, 397, 3 };
FieldActorEntry actor14 = { actor14Conditions, NULL, 0x6A, 7, 0, 0, 1 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x9D, 8, 265, 397, 3 };
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
    &actor14,
    &actor15,
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
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x203, 0x2DA, 0x17E, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 5, script5, EVENT_TEXT(0), NULL, func_800A51D4 },
    { -1, NULL, 0, NULL, NULL },
};
