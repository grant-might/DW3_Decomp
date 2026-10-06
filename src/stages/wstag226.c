#include "common.h"
#include "stage.h"
void func_800A4DB4();
extern AnimFrame *D_800A577C[];
extern s8 D_800A5788[];
extern s8 D_800A578C[];
extern s16 D_800A5790[][2];

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
        task->anims[i].anim.timer = D_800A577C[i][0].duration;
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
                for (t = D_800990B4.objects; t->unk2 != 0; t++) {
                    if (t->anim >= 1 && t->anim <= 3) {
                        task->anims[n].tile = t;
                        t->x = task->x;
                        t->y = task->y + D_800A578C[n];
                        t->unkE = task->y + D_800A5788[n];
                        n++;
                    }
                }
                func_800A4D7C(task);
                task->nextStep(task);
            case 1:
                done = 0;
                for (i = 0; i < 3; i++) {
                    tile = task->anims[i].tile;
                    frame = stepAnimationOnce(&task->anims[i], D_800A577C[i], 0);
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

/* Starts the effect at the place of map 0 or 1 */
void func_800A5028(StageTileEffect *task, s32 id) {
    s32 i;

    if (task != NULL) {
        i = 0;
        switch (id) {
        case 1:
            i = 1;
        case 0:
            task->x = D_800A5790[i][0];
            task->y = D_800A5790[i][1];
            task->setSubstate(task, 1);
            break;
        }
    }
}

void *func_800A5090(s32 arg) {
    return createTaskWithId(func_800A4DB4, 0x70, 0, arg);
}

void *func_800A50C0(void) {
    return createTask(func_800A4DB4, 0x70, 0);
}

/* Creates the stage helper task and the event object of progress 0x25 when flag 0x4060 is set */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[1] = func_800A50C0();
        do {
            if (GAME.progress == 0x25 && FLAGS_00.checkCondition(0x4060, 1)) {
                children[0] = FIELDSTG_startEvent(0x3A7);
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

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A51E8(void) {
    GAME.progress = 38;
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x4A8
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x4B8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10100, 0x16D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern AnimFrame D_800A56D8[];
extern AnimFrame D_800A573C[];
extern AnimFrame D_800A56EC[];
extern u16 D_800A5878[];
extern u16 D_800A5880[];
extern u16 D_800A5888[];
extern u16 D_800A5890[];
extern u16 D_800A5898[];
extern u16 D_800A58A0[];
extern u16 D_800A58A8[];
extern u16 D_800A5994[];
extern u16 D_800A59A0[];
extern u16 D_800A59AC[];
extern u16 D_800A59B8[];
extern FieldTalk D_800A58B0[];
extern u16 D_800A59C0[];
extern FieldTalk D_800A58D4[];
extern u16 D_800A59CC[];
extern FieldTalk D_800A58EC[];
extern u16 D_800A59D8[];
extern FieldTalk D_800A5904[];
extern u16 D_800A59E4[];
extern FieldTalk D_800A5928[];
extern u16 D_800A59F0[];
extern FieldTalk D_800A5940[];
extern u16 D_800A59F8[];
extern FieldTalk D_800A5958[];
extern u16 D_800A5A00[];
extern FieldTalk D_800A597C[];
extern u16 D_800A5A0C[];
extern FieldActorEntry D_800A5A18;
extern FieldActorEntry D_800A5A2C;
extern FieldActorEntry D_800A5A40;
extern FieldActorEntry D_800A5A54;
extern FieldActorEntry D_800A5A68;
extern FieldActorEntry D_800A5A7C;
extern FieldActorEntry D_800A5A90;
extern FieldActorEntry D_800A5AA4;
extern FieldActorEntry D_800A5AB8;
extern FieldActorEntry D_800A5ACC;
extern FieldActorEntry D_800A5AE0;
extern FieldActorEntry D_800A5AF4;
extern s16 D_800A5330[];

s16 D_800A5330[] = {
    0x100, 1, 0x58, 0x1CC,
    0x101, 1, 1, 5,
    0x100, 0x9D, 0x109, 0x18D,
    0x101, 0x9D, 1, 3,
    0x300, 0x1E,
    0x102, 1, 0x78, 0x1BC, 5,
    0x100, 0xC, 0x58, 0x1CC,
    0x101, 0xC, 1, 5,
    0x302, 1,
    0x102, 1, 0xA0, 0x1A8, 5,
    0x102, 0xC, 0x80, 0x1B8, 5,
    0x302, 1,
    0x101, 1, 1, 5,
    0x101, 0xC, 1, 5,
    0x101, 0x323, 0x325, 1,
    0x101, 0x324, 0x325, 0xC,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 1,
    0x101, 0x324, 0x326, 0xC,
    0x300, 0x1E,
    0x102, 1, 0xF0, 0x180, 5,
    0x102, 0xC, 0xD0, 0x190, 5,
    0x302, 0xC,
    0x101, 1, 0x3A, 7,
    0x102, 0xC, 0xD0, 0x178, 4,
    0x302, 0xC,
    0x101, 1, 0x2F, 7,
    0x102, 0xC, 0xFE, 0x161, 5,
    0x101, 0x323, 0x327, 1,
    0x300, 0x5A,
    0x101, 0xC, 0x3A, 3,
    0x101, 0x323, 0x326, 1,
    0x300, 0x3C,
    0x200, 0, 1, 1, 3,
    0x101, 0xC, 0x3A, 5,
    0x301,
    0x300, 0x1E,
    0x600, 0, 0xC,
    0x200, 0, 2, 0xC, 0,
    0x101, 1, 1, 4,
    0x101, 0xC, 7, 0,
    0x101, 0x9D, 1, 4,
    0x301,
    0x100, 0xB, 0x58, 0x1CC,
    0x101, 0xB, 1, 5,
    0x101, 0xC, 1, 0,
    0x300, 0x1E,
    0x102, 0xB, 0x78, 0x1BC, 5,
    0x100, 0x13D, 0x58, 0x1CC,
    0x101, 0x13D, 1, 5,
    0x302, 0xB,
    0x102, 0xB, 0xD0, 0x190, 5,
    0x101, 0x9D, 1, 2,
    0x102, 0x13D, 0xB0, 0x1A0, 5,
    0x302, 0xB,
    0x101, 0xB, 1, 5,
    0x101, 0x13D, 1, 5,
    0x300, 0x1E,
    0x600, 0, 0xB,
    0x200, 0, 0xB, 0xB, 1,
    0x101, 0xB, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x101, 0x323, 0x325, 1,
    0x101, 0x324, 0x325, 0xC,
    0x300, 0x3C,
    0x101, 1, 1, 1,
    0x101, 0xC, 1, 1,
    0x101, 0x9D, 1, 1,
    0x101, 0x323, 0x326, 1,
    0x101, 0x324, 0x326, 0xC,
    0x300, 0x1E,
    0x601, 0, 0xEA, 0x175,
    0x200, 1, 3, 1, 3,
    0x200, 0, 4, 0xC, 2,
    0x301,
    0x300, 0x1E,
    0x101, 1, 1, 3,
    0x102, 0xB, 0xD0, 0x162, 4,
    0x101, 0x9D, 1, 3,
    0x102, 0x13D, 0xD0, 0x190, 5,
    0x302, 0x13D,
    0x101, 0xB, 1, 7,
    0x102, 0x13D, 0xD0, 0x180, 6,
    0x302, 0x13D,
    0x200, 0, 5, 0xB, 0,
    0x101, 0xB, 7, 7,
    0x301,
    0x101, 0xB, 1, 7,
    0x300, 0x1E,
    0x200, 0, 0xC, 0xB, 0,
    0x101, 0xB, 7, 6,
    0x101, 0x9D, 1, 5,
    0x301,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x200, 0, 7, 0xB, 0,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x13D, 3,
    0x101, 0x13D, 1, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 0xC, 2,
    0x101, 1, 1, 4,
    0x101, 0xC, 7, 1,
    0x101, 0x9D, 1, 4,
    0x301,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x200, 0, 9, 0xC, 2,
    0x101, 0xC, 7, 0,
    0x301,
    0x101, 0xC, 1, 0,
    0x300, 0x1E,
    0x200, 0, 0xA, 1, 3,
    0x101, 1, 7, 3,
    0x101, 0xB, 1, 7,
    0x101, 0x9D, 1, 3,
    0x101, 0x13D, 1, 6,
    0x301,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x102, 1, 0x58, 0x1CC, 1,
    0x101, 0xB, 1, 1,
    0x101, 0xC, 1, 1,
    0x101, 0x9D, 1, 1,
    0x101, 0x13D, 1, 1,
    0x300, 0x78,
    0x304, 0x270, 0x3E8, 0xEC, 1,
    0,
};
AnimFrame D_800A56D8[] = {
    { 70, 4 }, { 71, 4 }, { 70, 4 }, { 71, 4 },
    { 255, 0x3E7 },
};
AnimFrame D_800A56EC[] = {
    { 0x12C, 56 }, { 85, 6 }, { 86, 6 }, { 87, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 88, 4 },
    { 89, 4 }, { 90, 4 }, { 88, 4 }, { 89, 4 },
    { 90, 4 }, { 88, 4 }, { 89, 4 }, { 90, 4 },
    { 88, 4 }, { 89, 4 }, { 90, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A573C[] = {
    { 0x12C, 16 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 73, 4 }, { 75, 6 }, { 76, 6 }, { 77, 14 },
    { 78, 114 }, { 79, 6 }, { 80, 6 }, { 81, 6 },
    { 82, 6 }, { 83, 6 }, { 84, 8 }, { 255, 0x3E7 },
};
AnimFrame *D_800A577C[] = {
    D_800A56D8, D_800A573C, D_800A56EC,
};
s8 D_800A5788[] = {
    30, 30, 30, 0,
};
s8 D_800A578C[] = {
    0, -0x2F, -0x2F, 0,
};
s16 D_800A5790[][2] = {
    { 0x150, 0x112 }, { 112, 0x112 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x180, 0x80, 0x80, 0x170, 0x1FE },
    { 0x140, 0x100, 0x168, 0x180, 0xA0, 0x80, 0x160, 0x1FD },
    { 0x140, 0x100, 0x160, 0x160, 0x80, 0x60, 0x170, 0x1FD },
    { 0x140, 0x100, 0x152, 0x198, 0x48, 0x98, 0x150, 0x1FC },
    { 0x140, 0x100, 0x15A, 0x198, 0x68, 0x98, 0x160, 0x1FC },
    { 0x140, 0x100, 0x168, 0x160, 0xA0, 0x60, 0x170, 0x1FC },
    { 0x140, 0x100, 0x14A, 0x190, 0x28, 0x90, 0x160, 0x1FB },
    { 0x140, 0x100, 0x14A, 0x170, 0x28, 0x70, 0x170, 0x1FB },
};
u16 D_800A5878[] = { 0x1A0A, 0, 0xFFFF };
u16 D_800A5880[] = { 0x1A0A, 1, 0xFFFF };
u16 D_800A5888[] = { 0, 0, 0xFFFF };
u16 D_800A5890[] = { 0, 1, 0xFFFF };
u16 D_800A5898[] = { 0, 1, 0xFFFF };
u16 D_800A58A0[] = { 0x1A0A, 0, 0xFFFF };
u16 D_800A58A8[] = { 0x1A0A, 1, 0xFFFF };
FieldTalk D_800A58B0[] = {
    { D_800A5878, NULL, 0x1B4 },
    { D_800A5880, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58D4[] = {
    { NULL, NULL, 0x5B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58EC[] = {
    { NULL, NULL, 0x5D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5904[] = {
    { D_800A5888, D_800A5890, 0x201 },
    { D_800A5898, NULL, 0x202 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5928[] = {
    { NULL, NULL, 0x5A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5940[] = {
    { NULL, NULL, 0x5C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5958[] = {
    { D_800A58A0, NULL, 0x1FA },
    { D_800A58A8, NULL, 0x208 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A597C[] = {
    { NULL, NULL, 0x1FB },
    { NULL, NULL, 0 },
};
u16 D_800A5994[] = { 0x6025, 1, 0x4060, 1, 0xFFFF };
u16 D_800A59A0[] = { 0x6025, 1, 0x4060, 1, 0xFFFF };
u16 D_800A59AC[] = { 0x6025, 1, 0x4060, 1, 0xFFFF };
u16 D_800A59B8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A59C0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A59CC[] = { 0x882B, 1, 0x602B, 1, 0xFFFF };
u16 D_800A59D8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A59E4[] = { 0x1A0A, 0, 0x701C, 1, 0xFFFF };
u16 D_800A59F0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A59F8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5A00[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5A0C[] = { 0x6025, 1, 0x4060, 1, 0xFFFF };
FieldActorEntry D_800A5A18 = { D_800A5994, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A5A2C = { D_800A59A0, NULL, 0xB, 5, 0, 0, 1 };
FieldActorEntry D_800A5A40 = { D_800A59AC, NULL, 0xC, 6, 0, 0, 1 };
FieldActorEntry D_800A5A54 = { D_800A59B8, D_800A58B0, 0xC, 6, 208, 376, 7 };
FieldActorEntry D_800A5A68 = { D_800A59C0, D_800A58D4, 0x20, 7, 265, 397, 3 };
FieldActorEntry D_800A5A7C = { D_800A59CC, D_800A58EC, 0x20, 7, 265, 397, 3 };
FieldActorEntry D_800A5A90 = { D_800A59D8, D_800A5904, 0x68, 8, 255, 352, 7 };
FieldActorEntry D_800A5AA4 = { D_800A59E4, D_800A5928, 0x9D, 9, 265, 397, 3 };
FieldActorEntry D_800A5AB8 = { D_800A59F0, D_800A5940, 0x9D, 9, 265, 397, 3 };
FieldActorEntry D_800A5ACC = { D_800A59F8, D_800A5958, 0xB2, 0xA, 277, 363, 3 };
FieldActorEntry D_800A5AE0 = { D_800A5A00, D_800A597C, 0x13D, 0xB, 255, 352, 7 };
FieldActorEntry D_800A5AF4 = { D_800A5A0C, NULL, 0x13D, 0xB, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5A18,
    &D_800A5A2C,
    &D_800A5A40,
    &D_800A5A54,
    &D_800A5A68,
    &D_800A5A7C,
    &D_800A5A90,
    &D_800A5AA4,
    &D_800A5AB8,
    &D_800A5ACC,
    &D_800A5AE0,
    &D_800A5AF4,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x50, 6, 0x46, 0, 0, 0, 0, 0, 336, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 116, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 228, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 340, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x42, 6, 0, 355, 346, 0, 0 },
    { 0, 2, 0x50, 4, 0x48, 0, 2, 0, 0, 0, 336, 227, 301, 0 },
    { 0, 3, 0x50, 4, 0x55, 0, 0, 0, 0, 0, 336, 227, 294, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 116, 274, 300, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 228, 298, 324, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 340, 274, 300, 0 },
    { 1, 0, 0x40, 4, 0x3B, 1, 0x3B, 0x3E, 6, 0, 355, 362, 388, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x2DA, 0x17E, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 935, D_800A5330, EVENT_TEXT(0x29), NULL, func_800A51E8 },
    { -1, NULL, 0, NULL, NULL },
};
