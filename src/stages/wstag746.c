#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A5A6C[];
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

/* Creates the flash task (id 0x19) */
void *func_800A4EB8(void) {
    return createTaskWithId(func_800A4CA4, sizeof(StageTask), 0, 0x19);
}

/* Turns the flash off (TASK_RUN) */
void *func_800A4EE8(void) {
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

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
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

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
    StageTask *task = TASK_REGISTRY.funcs.find(0x19, -1, -1);

    if (task != NULL) {
        if (task->state != TASK_RUN) {
            SOUND.playSound(0x800410BD);
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
        if (FLAGS_00.checkCondition(0x4086, 1) && FLAGS_00.checkCondition(0x4087, 0)) {
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
    FLAGS_00.applyAction(0x4086, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A57DC(void) {
    FLAGS_00.applyAction(0x4087, 1);
    FLAGS_00.applyAction(0x8F41, 1);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
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

extern Battle D_800A5BCC;
extern Battle D_800A5BD8;
extern Battle D_800A5BE4;
extern Battle D_800A5BF0;
extern Battle D_800A5BFC;
extern Battle D_800A5C08;
extern Battle D_800A5C14;
extern Battle D_800A5C20;
extern Battle D_800A5C50;
extern Battle D_800A5C5C;
extern Battle D_800A5C68;
extern Battle D_800A5C74;
extern Battle D_800A5C80;
extern Battle D_800A5C8C;
extern Battle D_800A5C98;
extern Battle D_800A5CA4;
extern Battle D_800A5CD4;
extern Battle D_800A5CE0;
extern Battle D_800A5CEC;
extern Battle D_800A5CF8;
extern Battle D_800A5D04;
extern Battle D_800A5D10;
extern Battle D_800A5D1C;
extern Battle D_800A5D28;
extern Battle D_800A5D58;
extern Battle D_800A5D64;
extern Battle D_800A5D70;
extern Battle D_800A5D7C;
extern Battle D_800A5D88;
extern Battle D_800A5D94;
extern Battle D_800A5DA0;
extern Battle D_800A5DAC;
extern BattleList D_800A5C2C;
extern BattleList D_800A5CB0;
extern BattleList D_800A5D34;
extern BattleList D_800A5DB8;
extern u16 D_800A5E88[];
extern u16 D_800A5E98[];
extern u16 D_800A5EA0[];
extern u16 D_800A5EA8[];
extern u16 D_800A5EB0[];
extern u16 D_800A5EB8[];
extern u16 D_800A5EC0[];
extern u16 D_800A5EC8[];
extern u16 D_800A5ED0[];
extern u16 D_800A5F98[];
extern FieldTalk D_800A5ED8[];
extern u16 D_800A5FA0[];
extern FieldTalk D_800A5EF0[];
extern u16 D_800A5FAC[];
extern FieldTalk D_800A5F08[];
extern u16 D_800A5FB8[];
extern FieldTalk D_800A5F20[];
extern u16 D_800A5FC8[];
extern FieldTalk D_800A5F5C[];
extern FieldActorEntry D_800A5FD8;
extern FieldActorEntry D_800A5FEC;
extern FieldActorEntry D_800A6000;
extern FieldActorEntry D_800A6014;
extern FieldActorEntry D_800A6028;
extern s16 D_800A5954[];
extern s16 D_800A59EC[];

s16 D_800A5954[] = {
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
s16 D_800A59EC[] = {
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
Battle D_800A5BCC = { 181, 26, 0x60080000 };
Battle D_800A5BD8 = { 181, 26, 0x60080000 };
Battle D_800A5BE4 = { 181, 26, 0x60080000 };
Battle D_800A5BF0 = { 181, 26, 0x60080000 };
Battle D_800A5BFC = { 142, 26, 0x60080000 };
Battle D_800A5C08 = { 142, 26, 0x60080000 };
Battle D_800A5C14 = { 142, 26, 0x60080000 };
Battle D_800A5C20 = { 142, 26, 0x60080000 };
BattleList D_800A5C2C = {
    2,
    { &D_800A5BCC, &D_800A5BD8, &D_800A5BE4, &D_800A5BF0,
      &D_800A5BFC, &D_800A5C08, &D_800A5C14, &D_800A5C20 },
};
Battle D_800A5C50 = { 0, 0, 0x60040000 };
Battle D_800A5C5C = { 0, 0, 0x60040000 };
Battle D_800A5C68 = { 0, 0, 0x60040000 };
Battle D_800A5C74 = { 0, 0, 0x60040000 };
Battle D_800A5C80 = { 0, 0, 0x60040000 };
Battle D_800A5C8C = { 0, 0, 0x60040000 };
Battle D_800A5C98 = { 0, 0, 0x60040000 };
Battle D_800A5CA4 = { 0, 0, 0x60040000 };
BattleList D_800A5CB0 = {
    0,
    { &D_800A5C50, &D_800A5C5C, &D_800A5C68, &D_800A5C74,
      &D_800A5C80, &D_800A5C8C, &D_800A5C98, &D_800A5CA4 },
};
Battle D_800A5CD4 = { 0, 0, 0x60040000 };
Battle D_800A5CE0 = { 0, 0, 0x60040000 };
Battle D_800A5CEC = { 0, 0, 0x60040000 };
Battle D_800A5CF8 = { 0, 0, 0x60040000 };
Battle D_800A5D04 = { 0, 0, 0x60040000 };
Battle D_800A5D10 = { 0, 0, 0x60040000 };
Battle D_800A5D1C = { 0, 0, 0x60040000 };
Battle D_800A5D28 = { 0, 0, 0x60040000 };
BattleList D_800A5D34 = {
    0,
    { &D_800A5CD4, &D_800A5CE0, &D_800A5CEC, &D_800A5CF8,
      &D_800A5D04, &D_800A5D10, &D_800A5D1C, &D_800A5D28 },
};
Battle D_800A5D58 = { 29, 26, 0x608C0000 };
Battle D_800A5D64 = { 0, 0, 0x60040000 };
Battle D_800A5D70 = { 0, 0, 0x60040000 };
Battle D_800A5D7C = { 0, 0, 0x60040000 };
Battle D_800A5D88 = { 0, 0, 0x60040000 };
Battle D_800A5D94 = { 0, 0, 0x60040000 };
Battle D_800A5DA0 = { 0, 0, 0x60040000 };
Battle D_800A5DAC = { 0, 0, 0x60040000 };
BattleList D_800A5DB8 = {
    0,
    { &D_800A5D58, &D_800A5D64, &D_800A5D70, &D_800A5D7C,
      &D_800A5D88, &D_800A5D94, &D_800A5DA0, &D_800A5DAC },
};
FieldBattles stageBattles[] = {
    { 122, 0, 0, { &D_800A5C2C, &D_800A5CB0, &D_800A5D34, &D_800A5DB8 } },
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
u16 D_800A5E88[] = { 0x25D, 1, 0x8B0E, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5E98[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5EA0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5EA8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5EB0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5EB8[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5EC0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5EC8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5ED0[] = { 0x602B, 1, 0xFFFF };
FieldTalk D_800A5ED8[] = {
    { NULL, D_800A5E88, 0x18D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EF0[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F08[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F20[] = {
    { D_800A5E98, NULL, 0x216 },
    { D_800A5EA0, NULL, 0x217 },
    { D_800A5EA8, NULL, 0x218 },
    { D_800A5EB0, NULL, 0x21A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F5C[] = {
    { D_800A5EB8, NULL, 0x216 },
    { D_800A5EC0, NULL, 0x217 },
    { D_800A5EC8, NULL, 0x218 },
    { D_800A5ED0, NULL, 0x21A },
    { NULL, NULL, 0 },
};
u16 D_800A5F98[] = { 0x25D, 0, 0xFFFF };
u16 D_800A5FA0[] = { 0x4087, 0, 0x701A, 1, 0xFFFF };
u16 D_800A5FAC[] = { 0x701A, 1, 0x4087, 1, 0xFFFF };
u16 D_800A5FB8[] = { 0x701A, 0, 0x4087, 0, 0x7008, 1, 0xFFFF };
u16 D_800A5FC8[] = { 0x701A, 0, 0x4087, 1, 0x7008, 1, 0xFFFF };
FieldActorEntry D_800A5FD8 = { D_800A5F98, D_800A5ED8, 0x21, 4, 785, 233, 1 };
FieldActorEntry D_800A5FEC = { D_800A5FA0, D_800A5EF0, 0x9D, 5, 240, 209, 7 };
FieldActorEntry D_800A6000 = { D_800A5FAC, D_800A5F08, 0x9D, 5, 240, 209, 7 };
FieldActorEntry D_800A6014 = { D_800A5FB8, D_800A5F20, 0xCD, 6, 240, 209, 7 };
FieldActorEntry D_800A6028 = { D_800A5FC8, D_800A5F5C, 0xCD, 6, 240, 209, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5FD8,
    &D_800A5FEC,
    &D_800A6000,
    &D_800A6014,
    &D_800A6028,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D3, 0xD0, 0x33C, 5, 0, 0, 0 },
    { { { 0x4086, 0 }, { 0x701A, 0 } }, 8, 0x511, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F40, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F41, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 8, 0x1F42, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D4, 0x3C0, 0x2B0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1297, D_800A5954, EVENT_TEXT(0x17), NULL, func_800A5790 },
    { 1298, D_800A59EC, EVENT_TEXT(0x18), NULL, func_800A57DC },
    { 8000, NULL, 0, func_800A4EE8, NULL },
    { 8001, NULL, 0, func_800A4F68, NULL },
    { 8002, NULL, 0, func_800A4FE8, NULL },
    { -1, NULL, 0, NULL, NULL },
};
