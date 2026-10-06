#include "common.h"
#include "stage.h"
void func_800A4E08();
extern StageEffectSpot D_800A5BD0[];

/* The files of the background, which the versions number differently */
#if VERSION_US
#define BG_ARCHIVE 0x767
#define BG_FILE 0x766
#define BG_FILE2 0x887
#elif VERSION_EU
#define BG_ARCHIVE 0x776
#define BG_FILE 0x775
#define BG_FILE2 0x898
#endif

/* Draws the two background images (file BG_ARCHIVE) scrolled at 2/3 of the layer's scroll */
void func_800A4CA4(StageTask *task) {
    SpriteDrawer drawer;
    Vec2 scroll;
    Layer *layer = GFX.funcs.getLayer(0x1002);

    layer->getScroll(layer, &scroll);
    scroll.x = (scroll.x << 8) / 384;
    scroll.y = (scroll.y << 8) / 384;
    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1002, 7);
    drawer.setTexture(0x280, 0);
    drawer.setAltClut(0, 0xF0);
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 2), 0, scroll.x, scroll.y);
    drawer.setTexture(0x280, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.draw(FILE_CACHE.getEntry(BG_ARCHIVE << 16 | 3), 0, scroll.x, scroll.y + 0x100);
}

/* Loads the background images (files BG_FILE and BG_FILE2) to VRAM, then draws them every frame */
void func_800A4E08(StageTask *task) {
    TimLoader loader;

    switch (task->state) {
    case TASK_INIT:
    default:
        initTimLoader(&loader);
        loader.setImagePos(0x280, 0);
        loader.setClutPos(0, 0xF0);
        loader.loadArchive(FILE_CACHE.load(BG_FILE));
        loader.setImagePos(0x280, 0x100);
        loader.setClutPos(0, 0x1F0);
        loader.loadArchive(FILE_CACHE.load(BG_FILE2));
        task->nextState(task);
        break;
    case TASK_RUN:
        func_800A4CA4(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A4F10(void) {
    return createTask(func_800A4E08, 0x60, 0);
}

/* Creates an object, the stage's five effects and the event object of flags 0x4072/0x40A9 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A4F10();
        for (i = 0; i < 5; i++) {
            if (D_800A5BD0[i].kind == 0) {
                children[i + 1] = createStageEffect(D_800A5BD0[i].x, D_800A5BD0[i].y, D_800A5BD0[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x4072, 1) && FLAGS_00.checkCondition(0x40A9, 0)) {
            children[6] = FIELDSTG_startEvent(0x411);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates the stage task (id 0x17) and calls the first function of its table */
StageTask *startStage(void *owner) {
    StageTask *task = createTaskWithId(updateStage, sizeof(StageTask), 0x1C, 0x17);

    task->owner = owner;
    stageFuncs[0]();
    return task;
}

#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A5660(void) {
    FLAGS_00.applyAction(0x4070, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A56AC(void) {
    FLAGS_00.applyAction(0x4071, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A56F8(void) {
    FLAGS_00.applyAction(0x4072, 1);
}

void func_800A5724(void) {
    FLAGS_00.applyAction(0x40A9, 1);
}

void func_800A5750(void) {
    FLAGS_00.applyAction(0x4073, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x767
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x151
#define STAGE_FILE 0x776
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x3D400, 0x33B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1C;
    D_800990B4.music = 0x60700000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 4);
    D_8009A70C.unk50(0);
}

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
extern Battle D_800A5E08;
extern Battle D_800A5E14;
extern Battle D_800A5E20;
extern Battle D_800A5E2C;
extern Battle D_800A5E38;
extern Battle D_800A5E44;
extern Battle D_800A5E50;
extern Battle D_800A5E5C;
extern BattleList D_800A5CDC;
extern BattleList D_800A5D60;
extern BattleList D_800A5DE4;
extern BattleList D_800A5E68;
extern u16 D_800A5F28[];
extern u16 D_800A5F34[];
extern FieldActorEntry D_800A5F40;
extern FieldActorEntry D_800A5F54;
extern s16 D_800A5890[];
extern s16 D_800A590C[];
extern s16 D_800A5988[];
extern s16 D_800A5AB4[];
extern s16 D_800A5AF8[];

s16 D_800A5890[] = {
    0x102, 2, 0x160, 0x2CB, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xD0,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0xD0,
    0x300, 0x1E,
    0x200, 0, 1, 0xD0, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0x150, 0x2C4, 3,
    0x302, 2,
    0,
};
s16 D_800A590C[] = {
    0x102, 2, 0x3D0, 0x103, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0xD1,
    0x300, 0x1E,
    0x200, 0, 1, 0xD1, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0x3C0, 0xFB, 3,
    0x302, 2,
    0,
};
s16 D_800A5988[] = {
    0x102, 2, 0x27D, 0x1F9, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0xB4,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x101, 0x32D, 0x373, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x101, 0x32D, 0x373, 2,
#if VERSION_US
    0x304, 0xE08, 0x27D, 0x1F9, 1,
#elif VERSION_EU
    0x304, 0xE09, 0x27D, 0x1F9, 1,
#endif
    0,
};
s16 D_800A5AB4[] = {
    0x100, 2, 0x27D, 0x1F9,
    0x101, 2, 1, 0,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 0,
    0x301,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A5AF8[] = {
    0x102, 2, 0x17D, 0x119, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x101, 0x32D, 0x372, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0xB4,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 3,
    0x101, 0x32D, 0x373, 2,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
StageEffectSpot D_800A5BD0[] = {
    { 60, 0, 0x318, 166 },
    { 60, 0, 0x3F8, 0x116 },
    { 60, 0, 168, 0x26E },
    { 60, 0, 0x188, 0x2DE },
    { 44, 0, 0x3F8, 0x2C6 },
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
Battle D_800A5D84 = { 0, 0, 0x60040000 };
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
Battle D_800A5E08 = { 194, 17, 0x60080000 };
Battle D_800A5E14 = { 144, 17, 0x60080000 };
Battle D_800A5E20 = { 0, 0, 0x60040000 };
Battle D_800A5E2C = { 0, 0, 0x60040000 };
Battle D_800A5E38 = { 0, 0, 0x60040000 };
Battle D_800A5E44 = { 0, 0, 0x60040000 };
Battle D_800A5E50 = { 0, 0, 0x60040000 };
Battle D_800A5E5C = { 0, 0, 0x60040000 };
BattleList D_800A5E68 = {
    0,
    { &D_800A5E08, &D_800A5E14, &D_800A5E20, &D_800A5E2C,
      &D_800A5E38, &D_800A5E44, &D_800A5E50, &D_800A5E5C },
};
FieldBattles stageBattles[] = {
    { 125, 0, 0, { &D_800A5CDC, &D_800A5D60, &D_800A5DE4, &D_800A5E68 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1CD, 0x182, 0x234, 0x82, 0x160, 0x1FC },
    { 0x1C0, 0x100, 0x1CD, 0x15A, 0x234, 0x5A, 0x170, 0x1FC },
};
u16 D_800A5F28[] = { 0x4070, 0, 0x6028, 1, 0xFFFF };
u16 D_800A5F34[] = { 0x6028, 1, 0x4071, 0, 0xFFFF };
FieldActorEntry D_800A5F40 = { D_800A5F28, NULL, 0xD0, 4, 302, 691, 7 };
FieldActorEntry D_800A5F54 = { D_800A5F34, NULL, 0xD1, 5, 927, 235, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5F40,
    &D_800A5F54,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0xF9, 6, 3, 0, 0, 0, 0, 0, 853, 643, 643, 0 },
    { 1, 0, 0xFF, 6, 4, 0, 0, 0, 0, 0, 124, 99, 0, 0 },
    { 1, 0, 0xD6, 6, 1, 0, 0, 0, 0, 0, 341, 195, 0, 0 },
    { 1, 0, 0xD6, 6, 1, 0, 0, 0, 0, 0, 469, 307, 0, 0 },
    { 1, 0, 0xD6, 6, 1, 0, 0, 0, 0, 0, 597, 419, 0, 0 },
    { 1, 0, 0xD6, 6, 1, 0, 0, 0, 0, 0, 725, 531, 0, 0 },
    { 1, 0, 0xFF, 6, 2, 0, 0, 0, 0, 0, 156, 617, 617, 0 },
    { 1, 0, 0xFF, 6, 2, 0, 0, 0, 0, 0, 780, 161, 161, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DF, 0x310, 0x228, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DD, 0x504, 0x296, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DD, 0x344, 0xF6, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DD, 0x29C, 0x1AA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xE, 0x2DD, 0x3E4, 0x146, 5, 0, 0, 0 },
    { { { 0x4070, 0 }, { 0xFFFF, 0 } }, 8, 0x3FC, 0, 0, 0, 0, 0, 0 },
    { { { 0x4071, 0 }, { 0xFFFF, 0 } }, 8, 0x406, 0, 0, 0, 0, 0, 0 },
    { { { 0x4072, 0 }, { 0xFFFF, 0 } }, 8, 0x410, 0, 0, 0, 0, 0, 0 },
    { { { 0x4073, 0 }, { 0xFFFF, 0 } }, 8, 0x41A, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1020, D_800A5890, EVENT_TEXT(9), NULL, func_800A5660 },
    { 1030, D_800A590C, EVENT_TEXT(0xA), NULL, func_800A56AC },
    { 1040, D_800A5988, EVENT_TEXT(0xC), NULL, func_800A56F8 },
    { 1041, D_800A5AB4, EVENT_TEXT(0xD), NULL, func_800A5724 },
    { 1050, D_800A5AF8, EVENT_TEXT(0xE), NULL, func_800A5750 },
    { -1, NULL, 0, NULL, NULL },
};
