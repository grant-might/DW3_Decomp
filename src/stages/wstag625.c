#include "common.h"
#include "stage.h"
extern StageSeqStep D_800A5690[4][4];

s32 stepTileAnimation(StageTileSeq *obj, AnimFrame *frames, s32 once, s32 depth) {
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

void func_800A4DC4(StageTileSeqs *task) {
    StageTile *rec;
    s32 n;
    StageTile *tile;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        n = 0;
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            if (rec->anim >= 1 && rec->anim <= 4) {
                task->entries[n].tile = rec;
                n++;
            }
        }
        task->entries[0].setFrame = 0;
        task->entries[1].setFrame = 0;
        task->entries[2].setFrame = 0;
        task->entries[3].setFrame = 1;
        task->entries[0].seq = 2;
        task->entries[1].seq = 2;
        task->entries[2].seq = 1;
        task->entries[3].seq = 1;
        task->entries[0].anim.index = 0;
        task->entries[0].anim.timer = D_800A5690[0][2].frames->duration;
        task->entries[1].anim.index = 0;
        task->entries[1].anim.timer = D_800A5690[1][2].frames->duration;
        task->entries[2].anim.index = 0;
        task->entries[2].anim.timer = D_800A5690[2][1].frames->duration;
        task->entries[3].anim.index = 0;
        task->entries[3].anim.timer = D_800A5690[3][1].frames->duration;
        break;
    case TASK_RUN:
        for (i = 0; i < 4; i++) {
            tile = task->entries[i].tile;
            if (task->entries[i].seq != 0) {
                frame = stepTileAnimation(&task->entries[i], D_800A5690[i][task->entries[i].seq].frames,
                                      D_800A5690[i][task->entries[i].seq].once, 0);
                switch (frame) {
                case 0xFF:
                    if (D_800A5690[i][task->entries[i].seq].next == 0) {
                        task->entries[i].seq = 0;
                        tile->visible = 0;
                    } else {
                        task->entries[i].seq = D_800A5690[i][task->entries[i].seq].next;
                        task->entries[i].anim.index = 0;
                        task->entries[i].anim.timer = D_800A5690[i][task->entries[i].seq].frames->duration;
                    }
                    break;
                case 0x12C:
                    tile->visible = 0;
                    break;
                default:
                    tile->visible = 1;
                    if (task->entries[i].setFrame == 0) {
                        tile->clutRow = frame;
                    } else {
                        tile->frame = frame;
                    }
                    break;
                }
            } else {
                tile->visible = 0;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5010(s32 arg) {
    return createTaskWithId(func_800A4DC4, 0x80, 0, arg);
}

/* Creates the event object of story progress 21 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x15 && FLAGS_00.checkCondition(FLAG(0x40, 0x3D), 0)) {
            children[1] = FIELDSTG_startEvent(0x228);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A5124(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x3D), 1);
    FLAGS_00.applyAction(ITEM(0, 0x191), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x47C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x48C
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x20200, 0x17600};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x15;
    FIELDSTG_state.music = MUSIC(0x15, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script552[] = {
    0x601, 1, 0x1AE, 0x141,
    0x100, 2, 0x228, 0x18C,
    0x101, 2, 1, 3,
    0x100, 0xB, 0x1D8, 0x17D,
    0x101, 0xB, 1, 4,
    0x100, 0x65, 0x1B0, 0x104,
    0x101, 0x65, 1, 7,
    0x100, 0x66, 0x1EE, 0xE8,
    0x101, 0x66, 1, 5,
    0x100, 0x67, 0x182, 0x1A0,
    0x101, 0x67, 1, 3,
    0x100, 0x13D, 0x1C1, 0x188,
    0x101, 0x13D, 1, 4,
    0x300, 0x78,
    0x200, 1, 1, 0x66, 1,
    0x200, 0, 2, 0x67, 2,
    0x101, 0x66, 1, 1,
    0x101, 0x67, 1, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x65, 3,
    0x101, 0x65, 1, 1,
    0x301,
    0x300, 0x3C,
    0x200, 0, 0x13, 0x65, 3,
    0x101, 0x65, 1, 5,
    0x301,
    0x300, 0x5A,
    0x200, 1, 0x12, 0x67, 2,
    0x200, 0, 4, 0x66, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x65, 1,
    0x101, 0x65, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x14, 0x65, 1,
    0x101, 0x65, 1, 5,
    0x301,
    0x101, 0x65, 1, 7,
    0x300, 0x1E,
    0x200, 1, 7, 0x67, 2,
    0x200, 0, 6, 0x66, 1,
    0x301,
    0x101, 0x66, 1, 5,
    0x101, 0x67, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0x65, 1,
    0x301,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 9, 0x67, 2,
    0x301,
    0x600, 0, 2,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x1E0, 0x1B0, 1,
    0x101, 0xB, 1, 0,
    0x101, 0x13D, 1, 0,
    0x302, 2,
    0x102, 2, 0x1A0, 0x190, 3,
    0x101, 0xB, 1, 1,
    0x101, 0x13D, 1, 1,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x67, 1,
    0x301,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 0xB, 0x67, 1,
    0x101, 0x67, 1, 5,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 0xC, 2, 2,
    0x301,
    0x601, 0, 0x1AE, 0x141,
    0x300, 0x1E,
    0x200, 0, 0xD, 0x65, 3,
    0x101, 0x65, 1, 1,
    0x101, 0x66, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xE, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xF, 2, 0,
    0x101, 2, 1, 5,
    0x101, 0x65, 1, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x10, 0x65, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x11, 0xB, 2,
    0x301,
    0x600, 0, 2,
    0x102, 2, 0x1C8, 0x1A4, 6,
    0x302, 2,
    0x102, 2, 0x1F4, 0x1A4, 6,
    0x300, 6,
    0x304, 0x254, 0x2D4, 0xC4, 7,
    0,
};
AnimFrame D_800A5538[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 1, 6 },
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 1, 6 },
    { 255, 0 },
};
AnimFrame D_800A555C[] = {
    { 0, 6 }, { 0, 6 }, { 0, 6 }, { 1, 6 },
    { 2, 6 }, { 3, 6 }, { 4, 6 }, { 5, 6 },
    { 6, 6 }, { 7, 6 }, { 6, 6 }, { 5, 6 },
    { 4, 6 }, { 3, 6 }, { 2, 6 }, { 1, 6 },
    { 0, 6 }, { 0, 6 }, { 255, 0x3E7 },
};
AnimFrame D_800A55A8[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 1, 6 },
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 1, 6 },
    { 255, 0 },
};
AnimFrame D_800A55CC[] = {
    { 0, 12 }, { 1, 12 }, { 2, 12 }, { 1, 12 },
    { 255, 0 },
};
AnimFrame D_800A55E0[] = {
    { 2, 12 }, { 3, 12 }, { 4, 12 }, { 5, 12 },
    { 6, 12 }, { 7, 12 }, { 8, 12 }, { 9, 12 },
    { 10, 12 }, { 255, 0x3E7 },
};
AnimFrame D_800A5608[] = {
    { 9, 12 }, { 10, 12 }, { 9, 12 }, { 8, 12 },
    { 255, 0 },
};
AnimFrame D_800A561C[] = {
    { 0x12C, 90 }, { 0, 6 }, { 1, 6 }, { 2, 6 },
    { 3, 6 }, { 4, 6 }, { 3, 6 }, { 4, 6 },
    { 3, 6 }, { 4, 6 }, { 3, 6 }, { 2, 6 },
    { 1, 6 }, { 2, 6 }, { 1, 6 }, { 2, 6 },
    { 1, 6 }, { 255, 0x3E7 },
};
AnimFrame D_800A5664[] = {
    { 0x12C, 108 }, { 50, 6 }, { 51, 6 }, { 52, 6 },
    { 53, 6 }, { 54, 6 }, { 56, 6 }, { 57, 6 },
    { 58, 6 }, { 59, 6 }, { 255, 0x3E7 },
};
StageSeqStep D_800A5690[4][4] = {
    { { NULL, 0, 0 }, { D_800A5538, 0, 0 }, { D_800A555C, 1, 3 }, { D_800A55A8, 0, 0 } },
    { { NULL, 0, 0 }, { D_800A55CC, 0, 0 }, { D_800A55E0, 1, 3 }, { D_800A5608, 0, 0 } },
    { { NULL, 0, 0 }, { D_800A561C, 1, 0 }, { NULL, 0, 0 }, { NULL, 0, 0 } },
    { { NULL, 0, 0 }, { D_800A5664, 1, 0 }, { NULL, 0, 0 }, { NULL, 0, 0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x190, 0x88, 0x90, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x174, 0x150, 0xD0, 0x50, 0x160, 0x1F5 },
    { 0x140, 0x100, 0x14C, 0x178, 0x30, 0x78, 0x170, 0x1F5 },
    { 0x140, 0x100, 0x152, 0x178, 0x48, 0x78, 0x140, 0x1F4 },
    { 0x140, 0x100, 0x16A, 0x190, 0xA8, 0x90, 0x160, 0x1F4 },
    { 0x140, 0x100, 0x140, 0x198, 0, 0x98, 0x170, 0x1F4 },
    { 0x140, 0x100, 0x15A, 0x198, 0x68, 0x98, 0x140, 0x1F3 },
    { 0x140, 0x100, 0x152, 0x1A0, 0x48, 0xA0, 0x160, 0x1F3 },
};
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x306 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x307 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x307 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x304 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x304 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x305 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x305 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x303 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(7), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x16), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x15), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x16), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x15), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x16), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x15), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(7), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0xB, 4, 472, 381, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x65, 5, 385, 416, 3 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x65, 5, 385, 416, 3 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x66, 6, 496, 232, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x66, 6, 496, 232, 7 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x67, 7, 400, 232, 3 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x67, 7, 400, 232, 3 };
FieldActorEntry actor7 = { NULL, NULL, 0x9A, 8, 641, 350, 0 };
FieldActorEntry actor8 = { NULL, NULL, 0x9B, 9, 593, 325, 1 };
FieldActorEntry actor9 = { NULL, NULL, 0x9C, 0xA, 545, 301, 2 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x13D, 0xB, 449, 392, 5 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x40, 2, 0x3D, 0, 0, 0, 0, 0, 335, 351, 0, 0 },
    { 0, 2, 0x40, 2, 0x3E, 0, 0, 0, 0, 0, 345, 372, 0, 0 },
    { 0, 3, 0x40, 2, 0x3C, 0, 0, 0, 0, 0, 477, 356, 0, 0 },
    { 0, 4, 0x40, 2, 0x32, 0, 0, 0, 0, 0, 489, 350, 0, 0 },
    { 1, 0, 0x40, 2, 0x5F, 2, 0, 3, 6, 0, 521, 212, 0, 0 },
    { 1, 0, 0x40, 2, 0x5F, 2, 0, 3, 6, 0, 569, 236, 0, 0 },
    { 1, 0, 0x40, 2, 0x60, 2, 0, 3, 6, 0, 617, 260, 0, 0 },
    { 1, 0, 0x40, 2, 0x62, 2, 0, 5, 6, 0, 392, 163, 0, 0 },
    { 1, 0, 0x40, 2, 0x63, 2, 0, 5, 6, 0, 369, 205, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 3, 6, 0, 360, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 5, 6, 0, 361, 186, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 377, 371, 399, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x254, 0x2D4, 0xC4, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x1D0, 0xF8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x1E0, 0x150, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 552, script552, EVENT_TEXT(0x18), NULL, func_800A5124 },
    { -1, NULL, 0, NULL, NULL },
};
