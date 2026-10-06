#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A5AA4[];
void *func_800A4EB8(void);

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
                SOUND.playSound(0x800410BD);
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

/* Creates the flash task (id 0x18) */
void *func_800A4EB8(void) {
    return createTaskWithId(func_800A4CA4, sizeof(StageTask), 0, 0x18);
}

/* Turns the flash off (TASK_RUN) */
void *func_800A4EE8(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x18, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_RUN) {
            SOUND.playSound(0x800410BD);
        }
        task->setState(task, TASK_RUN);
        task->key1 = 0;
    }
    return NULL;
}

/* Turns the flash on (TASK_DONE) */
void *func_800A4F68(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x18, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_DONE) {
            SOUND.playSound(0x800410BD);
        }
        task->setState(task, TASK_DONE);
        task->key1 = 0;
    }
    return NULL;
}

/* Turns the flash off and starts its countdown (TASK_RUN, key1 = 1) */
void *func_800A4FE8(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x18, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_RUN) {
            SOUND.playSound(0x800410BD);
        }
        task->setState(task, TASK_RUN);
        task->key1 = 1;
    }
    return NULL;
}

/* Creates the stage's twenty effects, another object and the event object of flags 0x4041/0x4042 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[20] = func_800A4EB8();
        for (i = 0; i < 20; i++) {
            if (D_800A5AA4[i].kind == 0) {
                children[i] = createStageEffect(D_800A5AA4[i].x, D_800A5AA4[i].y, D_800A5AA4[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x4041, 1) && FLAGS_00.checkCondition(0x4042, 0)) {
            children[21] = FIELDSTG_startEvent(0x32B);
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
    FLAGS_00.applyAction(0x4041, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets flags 0x88A3 and 0x4042 */
void func_800A57DC(void) {
    FLAGS_00.applyAction(0x88A3, 1);
    FLAGS_00.applyAction(0x4042, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6DE
#define STAGE_FILE_8 0x700
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6EE
#define STAGE_FILE_8 0x710
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 4;
    D_800990B4.start = (Vec2){0x40000, 0x2C800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x19;
    D_800990B4.music = 0x60640000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.clearTempFlags != 0) {
        GAME.unk26E8 = 0;
    }
}

void func_800A57DC();
extern Battle D_800A5BF8;
extern Battle D_800A5C04;
extern Battle D_800A5C10;
extern Battle D_800A5C1C;
extern Battle D_800A5C28;
extern Battle D_800A5C34;
extern Battle D_800A5C40;
extern Battle D_800A5C4C;
extern Battle D_800A5C7C;
extern Battle D_800A5C88;
extern Battle D_800A5C94;
extern Battle D_800A5CA0;
extern Battle D_800A5CAC;
extern Battle D_800A5CB8;
extern Battle D_800A5CC4;
extern Battle D_800A5CD0;
extern Battle D_800A5D00;
extern Battle D_800A5D0C;
extern Battle D_800A5D18;
extern Battle D_800A5D24;
extern Battle D_800A5D30;
extern Battle D_800A5D3C;
extern Battle D_800A5D48;
extern Battle D_800A5D54;
extern Battle D_800A5D84;
extern Battle D_800A5D90;
extern Battle D_800A5D9C;
extern Battle D_800A5DA8;
extern Battle D_800A5DB4;
extern Battle D_800A5DC0;
extern Battle D_800A5DCC;
extern Battle D_800A5DD8;
extern BattleList D_800A5C58;
extern BattleList D_800A5CDC;
extern BattleList D_800A5D60;
extern BattleList D_800A5DE4;
extern u16 D_800A5EB4[];
extern u16 D_800A5F54[];
extern FieldTalk D_800A5EC4[];
extern u16 D_800A5F5C[];
extern FieldTalk D_800A5EDC[];
extern u16 D_800A5F64[];
extern FieldTalk D_800A5EF4[];
extern u16 D_800A5F6C[];
extern FieldTalk D_800A5F0C[];
extern u16 D_800A5F74[];
extern FieldTalk D_800A5F24[];
extern u16 D_800A5F80[];
extern FieldTalk D_800A5F3C[];
extern FieldActorEntry D_800A5F8C;
extern FieldActorEntry D_800A5FA0;
extern FieldActorEntry D_800A5FB4;
extern FieldActorEntry D_800A5FC8;
extern FieldActorEntry D_800A5FDC;
extern FieldActorEntry D_800A5FF0;
extern s16 D_800A5954[];
extern s16 D_800A59EC[];

s16 D_800A5954[] = {
    0x600, 1, 2,
    0x102, 2, 0x103, 0xDA, 3,
    0x100, 0xCA, 0xF0, 0xD1,
    0x101, 0xCA, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xCA, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCA, 2,
    0x301,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x4\n");
#endif
s16 D_800A59EC[] = {
    0x600, 1, 0xCA,
    0x100, 2, 0x103, 0xDA,
    0x101, 2, 1, 3,
    0x100, 0xCA, 0xF0, 0xD1,
    0x101, 0xCA, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xCA, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0xCA, 1, 5,
    0x300, 0x1E,
    0x102, 0xCA, 0x10F, 0xC1, 5,
    0x302, 0xCA,
    0x101, 0xCA, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0xF0, 0xD1, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0xCA, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
StageEffectSpot D_800A5AA4[] = {
    { 68, 0, 188, 0x1C4 },
    { 68, 0, 0x11C, 0x154 },
    { 68, 0, 0x11C, 0x254 },
    { 68, 0, 0x15C, 0x1F4 },
    { 68, 0, 0x1BC, 0x184 },
    { 68, 0, 0x1BC, 0x244 },
    { 68, 0, 0x1DC, 0x1B4 },
    { 68, 0, 0x1DC, 0x2B4 },
    { 68, 0, 0x1FC, 0x124 },
    { 68, 0, 0x1FC, 0x224 },
    { 68, 0, 0x25C, 0x174 },
    { 68, 0, 0x27C, 0x1E4 },
    { 68, 0, 0x27C, 0x224 },
    { 68, 0, 0x27C, 0x2E4 },
    { 68, 0, 0x29C, 0x254 },
    { 68, 0, 0x2DC, 0x174 },
    { 68, 0, 0x2FC, 0x2A4 },
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
Battle D_800A5BF8 = { 120, 26, 0x60080000 };
Battle D_800A5C04 = { 120, 26, 0x60080000 };
Battle D_800A5C10 = { 121, 26, 0x60080000 };
Battle D_800A5C1C = { 121, 26, 0x60080000 };
Battle D_800A5C28 = { 171, 26, 0x60080000 };
Battle D_800A5C34 = { 171, 26, 0x60080000 };
Battle D_800A5C40 = { 171, 26, 0x60080000 };
Battle D_800A5C4C = { 171, 26, 0x60080000 };
BattleList D_800A5C58 = {
    2,
    { &D_800A5BF8, &D_800A5C04, &D_800A5C10, &D_800A5C1C,
      &D_800A5C28, &D_800A5C34, &D_800A5C40, &D_800A5C4C },
};
Battle D_800A5C7C = { 0, 0, 0x60040000 };
Battle D_800A5C88 = { 0, 0, 0x60040000 };
Battle D_800A5C94 = { 0, 0, 0x60040000 };
Battle D_800A5CA0 = { 0, 0, 0x60040000 };
Battle D_800A5CAC = { 0, 0, 0x60040000 };
Battle D_800A5CB8 = { 0, 0, 0x60040000 };
Battle D_800A5CC4 = { 0, 0, 0x60040000 };
Battle D_800A5CD0 = { 0, 0, 0x60040000 };
BattleList D_800A5CDC = {
    0,
    { &D_800A5C7C, &D_800A5C88, &D_800A5C94, &D_800A5CA0,
      &D_800A5CAC, &D_800A5CB8, &D_800A5CC4, &D_800A5CD0 },
};
Battle D_800A5D00 = { 0, 0, 0x60040000 };
Battle D_800A5D0C = { 0, 0, 0x60040000 };
Battle D_800A5D18 = { 0, 0, 0x60040000 };
Battle D_800A5D24 = { 0, 0, 0x60040000 };
Battle D_800A5D30 = { 0, 0, 0x60040000 };
Battle D_800A5D3C = { 0, 0, 0x60040000 };
Battle D_800A5D48 = { 0, 0, 0x60040000 };
Battle D_800A5D54 = { 0, 0, 0x60040000 };
BattleList D_800A5D60 = {
    0,
    { &D_800A5D00, &D_800A5D0C, &D_800A5D18, &D_800A5D24,
      &D_800A5D30, &D_800A5D3C, &D_800A5D48, &D_800A5D54 },
};
Battle D_800A5D84 = { 21, 26, 0x608C0000 };
Battle D_800A5D90 = { 0, 0, 0x60040000 };
Battle D_800A5D9C = { 0, 0, 0x60040000 };
Battle D_800A5DA8 = { 0, 0, 0x60040000 };
Battle D_800A5DB4 = { 0, 0, 0x60040000 };
Battle D_800A5DC0 = { 0, 0, 0x60040000 };
Battle D_800A5DCC = { 0, 0, 0x60040000 };
Battle D_800A5DD8 = { 0, 0, 0x60040000 };
BattleList D_800A5DE4 = {
    0,
    { &D_800A5D84, &D_800A5D90, &D_800A5D9C, &D_800A5DA8,
      &D_800A5DB4, &D_800A5DC0, &D_800A5DCC, &D_800A5DD8 },
};
FieldBattles stageBattles[] = {
    { 89, 0, 0, { &D_800A5C58, &D_800A5CDC, &D_800A5D60, &D_800A5DE4 } },
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
u16 D_800A5EB4[] = { 0x7091, 1, 0x238, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5EC4[] = {
    { NULL, D_800A5EB4, 0x26F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EDC[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EF4[] = {
    { NULL, NULL, 0x20D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F0C[] = {
    { NULL, NULL, 0x20B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F24[] = {
    { NULL, NULL, 0x20A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F3C[] = {
    { NULL, NULL, 0x20A },
    { NULL, NULL, 0 },
};
u16 D_800A5F54[] = { 0x238, 0, 0xFFFF };
u16 D_800A5F5C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5F64[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5F6C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5F74[] = { 0x4042, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5F80[] = { 0x4042, 1, 0x7019, 1, 0xFFFF };
FieldActorEntry D_800A5F8C = { D_800A5F54, D_800A5EC4, 0x21, 4, 785, 233, 1 };
FieldActorEntry D_800A5FA0 = { D_800A5F5C, D_800A5EDC, 0x9D, 5, 271, 193, 1 };
FieldActorEntry D_800A5FB4 = { D_800A5F64, D_800A5EF4, 0xCA, 6, 271, 193, 1 };
FieldActorEntry D_800A5FC8 = { D_800A5F6C, D_800A5F0C, 0xCA, 6, 271, 193, 1 };
FieldActorEntry D_800A5FDC = { D_800A5F74, D_800A5F24, 0xCA, 6, 240, 209, 7 };
FieldActorEntry D_800A5FF0 = { D_800A5F80, D_800A5F3C, 0xCA, 6, 271, 193, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5F8C,
    &D_800A5FA0,
    &D_800A5FB4,
    &D_800A5FC8,
    &D_800A5FDC,
    &D_800A5FF0,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26B, 0xD0, 0x33C, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26D, 0x1E8, 0x254, 3, 0, 0, 0 },
    { { { 0x8011, 1 }, { 0x4041, 0 } }, 8, 0x32A, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F40, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F41, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F42, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26C, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 810, D_800A5954, EVENT_TEXT(0xE), NULL, func_800A5790 },
    { 811, D_800A59EC, EVENT_TEXT(0xF), NULL, func_800A57DC },
    { 8000, NULL, 0, func_800A4EE8, NULL },
    { 8001, NULL, 0, func_800A4F68, NULL },
    { 8002, NULL, 0, func_800A4FE8, NULL },
    { -1, NULL, 0, NULL, NULL },
};
