#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A5A6C[];

/* The flash: a white screen drawn while in TASK_DONE (GAME.unk26E8 is set then) */
void func_800A4CA4(StageTask *task) {
    Layer *layer;
    u_long *ot;
    POLY_F4 *poly;
    DR_TPAGE *mode;

    if (task->state == TASK_INIT) {
        if (GAME.unk26E8 != 0) {
            task->setState(task, TASK_DONE);
        } else {
            task->setState(task, TASK_RUN);
        }
    }
    switch (task->state) {
    case TASK_RUN:
        if (task->key1 != 0) {
            if (task->substate != 5) {
                task->nextSubstate(task);
            } else {
                task->key1 = 0;
                task->setState(task, TASK_DONE);
                SOUND.playSound(SOUND_SWITCH02);
            }
        }
        GAME.unk26E8 = 0;
        break;
    case TASK_DONE:
        layer = GFX.funcs.getLayer(0x1002);
        ot = (u_long *)layer->getOtEntry(layer, 6);
        poly = GFX.funcs.getPrim();
        setlen(poly, 5);
        poly->code = 0x2A;
        poly->r0 = poly->g0 = poly->b0 = 0xFF;
        poly->x1 = poly->x3 = 320;
        poly->x0 = poly->x2 = 0;
        poly->y0 = poly->y1 = 0;
        poly->y2 = poly->y3 = 256;
        addPrim(ot, poly);
        mode = (DR_TPAGE *)(poly + 1);
        setlen(mode, 1);
        mode->code[0] = 0xE1000245;
        addPrim(ot, mode);
        GFX.funcs.setPrim(mode + 1);
        GAME.unk26E8 = 1;
        break;
    case TASK_INIT:
    case TASK_KILL:
        break;
    }
}

/* Creates the flash task (id 0x19) */
void *func_800A4EB8(void) {
    return createTaskWithId(func_800A4CA4, sizeof(StageTask), 0, 0x19);
}

/* Turns the flash off (TASK_RUN) */
void *func_800A4EE8(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_RUN) {
            SOUND.playSound(SOUND_SWITCH02);
        }
        task->setState(task, TASK_RUN);
        task->key1 = 0;
    }
    return NULL;
}

/* Turns the flash on (TASK_DONE) */
void *func_800A4F68(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_DONE) {
            SOUND.playSound(SOUND_SWITCH02);
        }
        task->setState(task, TASK_DONE);
        task->key1 = 0;
    }
    return NULL;
}

/* Turns the flash off and starts its countdown (TASK_RUN, key1 = 1) */
void *func_800A4FE8(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_RUN) {
            SOUND.playSound(SOUND_SWITCH02);
        }
        task->setState(task, TASK_RUN);
        task->key1 = 1;
    }
    return NULL;
}

/* Creates the stage's twenty effects, another object and the event object of flags 0x4086/0x4087 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[20] = func_800A4EB8();
        for (i = 0; i < 20; i++) {
            if (D_800A5A6C[i].kind == 0) {
                children[i] = createStageEffect(D_800A5A6C[i].x, D_800A5A6C[i].y, D_800A5A6C[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x86), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x87), 0)) {
            children[21] = FIELDSTG_startEvent(0x512);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x58
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A5790(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x86), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A57DC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x87), 1);
    FLAGS_00.applyAction(ITEM(7, 0x141), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6CF
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x40000, 0x2C800};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x19;
    FIELDSTG_state.music = MUSIC(0x19, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.clearTempFlags != 0) {
        GAME.unk26E8 = 0;
    }
}

s16 script1297[] = {
    0x600, 1, 2,
    0x102, 2, 0x103, 0xDA, 3,
    0x100, 0xCD, 0xF0, 0xD1,
    0x101, 0xCD, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xCD, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCD, 2,
    0x301,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 script1298[] = {
    0x600, 1, 0xCD,
    0x100, 2, 0x103, 0xDA,
    0x101, 2, 1, 3,
    0x100, 0xCD, 0xF0, 0xD1,
    0x101, 0xCD, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xCD, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCD, 0,
    0x301,
    0x300, 0x1E,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x2\n");
#endif
StageEffectSpot D_800A5A6C[] = {
    { 68, 0, 0x11B, 0x154 },
    { 68, 0, 0x13C, 0x1C4 },
    { 68, 0, 0x15C, 0x1F4 },
    { 68, 0, 0x15C, 0x234 },
    { 68, 0, 0x1BC, 0x104 },
    { 68, 0, 0x1BC, 0x184 },
    { 68, 0, 0x1DC, 0x1B4 },
    { 68, 0, 0x1DC, 0x2B4 },
    { 68, 0, 0x1FC, 0x224 },
    { 68, 0, 0x1FC, 0x264 },
    { 68, 0, 0x23C, 0x144 },
    { 68, 0, 0x25C, 0x1B4 },
    { 68, 0, 0x27C, 0x224 },
    { 68, 0, 0x29C, 0x294 },
    { 68, 0, 0x2BC, 0x2C4 },
    { 68, 0, 0x2DC, 0x234 },
    { 68, 0, 0x2FC, 0x1A4 },
    { 68, 0, 0x31C, 0x1D4 },
    { 68, 0, 0x31C, 0x214 },
    { 20, 0, 0x3AC, 0x2A4 },
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
Battle area0Battle0 = { 181, 26, MUSIC(2, 0) };
Battle area0Battle1 = { 181, 26, MUSIC(2, 0) };
Battle area0Battle2 = { 181, 26, MUSIC(2, 0) };
Battle area0Battle3 = { 181, 26, MUSIC(2, 0) };
Battle area0Battle4 = { 142, 26, MUSIC(2, 0) };
Battle area0Battle5 = { 142, 26, MUSIC(2, 0) };
Battle area0Battle6 = { 142, 26, MUSIC(2, 0) };
Battle area0Battle7 = { 142, 26, MUSIC(2, 0) };
BattleList area0Battles = {
    2,
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
Battle area3Battle0 = { 29, 26, MUSIC(0x23, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
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
    { 122, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x170, 0x1FB },
    { 0x140, 0x100, 0x170, 0x180, 0xC0, 0x80, 0x150, 0x1FA },
    { 0x140, 0x100, 0x140, 0x160, 0, 0x60, 0x160, 0x1FA },
};
u16 actor0Talk0Actions[] = { FLAG(2, 0x5D), 1, ITEM(5, 0x10E), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor3Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor3Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor3Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Talk3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor4Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor4Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor4Talk3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x18D },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, NULL, 0x216 },
    { actor3Talk1Conditions, NULL, 0x217 },
    { actor3Talk2Conditions, NULL, 0x218 },
    { actor3Talk3Conditions, NULL, 0x21A },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, NULL, 0x216 },
    { actor4Talk1Conditions, NULL, 0x217 },
    { actor4Talk2Conditions, NULL, 0x218 },
    { actor4Talk3Conditions, NULL, 0x21A },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 0x5D), 0, CODES_END };
u16 actor1Conditions[] = { FLAG(0x40, 0x87), 0, SPECIAL(0x1A), 1, CODES_END };
u16 actor2Conditions[] = { SPECIAL(0x1A), 1, FLAG(0x40, 0x87), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x1A), 0, FLAG(0x40, 0x87), 0, SPECIAL(8), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x1A), 0, FLAG(0x40, 0x87), 1, SPECIAL(8), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 785, 233, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x9D, 5, 240, 209, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x9D, 5, 240, 209, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0xCD, 6, 240, 209, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0xCD, 6, 240, 209, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 208, 361, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 240, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 368, 409, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 400, 521, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 432, 633, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 496, 345, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 528, 457, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 560, 569, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 592, 681, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 656, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 688, 505, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 720, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 752, 729, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xF, 4, 0, 848, 553, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D3, 0xD0, 0x33C, 5, 0, 0, 0 },
    { { { FLAG(0x40, 0x86), 0 }, { SPECIAL(0x1A), 0 } }, 8, 0x511, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 8, 0x1F40, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 8, 0x1F41, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 8, 0x1F42, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1297, script1297, EVENT_TEXT(0x17), NULL, func_800A5790 },
    { 1298, script1298, EVENT_TEXT(0x18), NULL, func_800A57DC },
    { 8000, NULL, 0, func_800A4EE8, NULL },
    { 8001, NULL, 0, func_800A4F68, NULL },
    { 8002, NULL, 0, func_800A4FE8, NULL },
    { -1, NULL, 0, NULL, NULL },
};
