#include "common.h"
#include "stage.h"
void func_800A4DB4();
extern AnimFrame *D_800A54E8[];
extern s8 D_800A54F4[];
extern s8 D_800A54F8[];
extern s16 D_800A54FC[][2];

s32 stepAnimationOnce(StageTileAnim *obj, AnimFrame *frames, s32 depth) {
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
        if (frame->frame == 0xFF) {
            return 0xFF;
        }
        stepAnimationOnce(obj, frames, depth + 1);
    }
    return frame->frame;
}

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
                for (t = D_800990B4.objects; t->unk2 != 0; t++) {
                    if (t->anim >= 1 && t->anim <= 3) {
                        task->anims[n].tile = t;
                        t->x = task->x;
                        t->y = task->y + D_800A54F8[n];
                        t->unkE = task->y + D_800A54F4[n];
                        n++;
                    }
                }
                SOUND.playSound(0xCC0001);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xFD00, 0x17700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x33;
    D_800990B4.music = 0x60CC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern AnimFrame D_800A5444[];
extern AnimFrame D_800A54A8[];
extern AnimFrame D_800A5458[];
extern u16 D_800A56EC[];
extern u16 D_800A56F4[];
extern u16 D_800A56FC[];
extern FieldTalk D_800A55B4[];
extern u16 D_800A5704[];
extern FieldTalk D_800A55CC[];
extern u16 D_800A570C[];
extern FieldTalk D_800A55E4[];
extern u16 D_800A5714[];
extern FieldTalk D_800A55FC[];
extern u16 D_800A571C[];
extern FieldTalk D_800A5614[];
extern u16 D_800A5724[];
extern FieldTalk D_800A562C[];
extern u16 D_800A572C[];
extern FieldTalk D_800A5644[];
extern u16 D_800A5734[];
extern FieldTalk D_800A565C[];
extern u16 D_800A573C[];
extern FieldTalk D_800A5674[];
extern u16 D_800A5744[];
extern FieldTalk D_800A568C[];
extern u16 D_800A574C[];
extern FieldTalk D_800A56A4[];
extern u16 D_800A5754[];
extern FieldTalk D_800A56BC[];
extern u16 D_800A575C[];
extern u16 D_800A5764[];
extern FieldTalk D_800A56D4[];
extern FieldActorEntry D_800A576C;
extern FieldActorEntry D_800A5780;
extern FieldActorEntry D_800A5794;
extern FieldActorEntry D_800A57A8;
extern FieldActorEntry D_800A57BC;
extern FieldActorEntry D_800A57D0;
extern FieldActorEntry D_800A57E4;
extern FieldActorEntry D_800A57F8;
extern FieldActorEntry D_800A580C;
extern FieldActorEntry D_800A5820;
extern FieldActorEntry D_800A5834;
extern FieldActorEntry D_800A5848;
extern FieldActorEntry D_800A585C;
extern FieldActorEntry D_800A5870;
extern FieldActorEntry D_800A5884;
extern FieldActorEntry D_800A5898;
extern s16 D_800A531C[];

s16 D_800A531C[] = {
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
FieldTalk D_800A55B4[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55CC[] = {
    { NULL, NULL, 0x19A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E4[] = {
    { NULL, NULL, 0x19B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55FC[] = {
    { NULL, NULL, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5614[] = {
    { NULL, NULL, 0x1A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A562C[] = {
    { NULL, NULL, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5644[] = {
    { NULL, NULL, 0x19C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A565C[] = {
    { NULL, NULL, 0x19E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5674[] = {
    { NULL, NULL, 0x19F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A568C[] = {
    { NULL, NULL, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A4[] = {
    { NULL, NULL, 0x1B1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56BC[] = {
    { NULL, NULL, 0x1A0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D4[] = {
    { NULL, NULL, 0x1B0 },
    { NULL, NULL, 0 },
};
u16 D_800A56EC[] = { 0x6001, 1, 0xFFFF };
u16 D_800A56F4[] = { 0x6001, 1, 0xFFFF };
u16 D_800A56FC[] = { 0x6002, 1, 0xFFFF };
u16 D_800A5704[] = { 0x6004, 1, 0xFFFF };
u16 D_800A570C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5714[] = { 0x600D, 1, 0xFFFF };
u16 D_800A571C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5724[] = { 0x7019, 1, 0xFFFF };
u16 D_800A572C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5734[] = { 0x600E, 1, 0xFFFF };
u16 D_800A573C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5744[] = { 0x6026, 1, 0xFFFF };
u16 D_800A574C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5754[] = { 0x6016, 1, 0xFFFF };
u16 D_800A575C[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5764[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A576C = { D_800A56EC, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A5780 = { D_800A56F4, NULL, 0xD, 5, 0, 0, 3 };
FieldActorEntry D_800A5794 = { D_800A56FC, D_800A55B4, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A57A8 = { D_800A5704, D_800A55CC, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A57BC = { D_800A570C, D_800A55E4, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A57D0 = { D_800A5714, D_800A55FC, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A57E4 = { D_800A571C, D_800A5614, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A57F8 = { D_800A5724, D_800A562C, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A580C = { D_800A572C, D_800A5644, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A5820 = { D_800A5734, D_800A565C, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A5834 = { D_800A573C, D_800A5674, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A5848 = { D_800A5744, D_800A568C, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A585C = { D_800A574C, D_800A56A4, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A5870 = { D_800A5754, D_800A56BC, 0x20, 6, 265, 397, 3 };
FieldActorEntry D_800A5884 = { D_800A575C, NULL, 0x6A, 7, 0, 0, 1 };
FieldActorEntry D_800A5898 = { D_800A5764, D_800A56D4, 0x9D, 8, 265, 397, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A576C,
    &D_800A5780,
    &D_800A5794,
    &D_800A57A8,
    &D_800A57BC,
    &D_800A57D0,
    &D_800A57E4,
    &D_800A57F8,
    &D_800A580C,
    &D_800A5820,
    &D_800A5834,
    &D_800A5848,
    &D_800A585C,
    &D_800A5870,
    &D_800A5884,
    &D_800A5898,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0x2DA, 0x17E, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 5, D_800A531C, EVENT_TEXT(0), NULL, func_800A51D4 },
    { -1, NULL, 0, NULL, NULL },
};
