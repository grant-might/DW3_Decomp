#include "common.h"
#include "stage.h"
void func_800A4D7C();
extern AnimFrame D_800A55F4[];

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

void func_800A4D7C(StageSoundTile *task) {
    StageTile *rec;
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->obj.anim.index = 0;
                task->obj.anim.timer = D_800A55F4[0].duration;
                task->obj.tile = rec;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        tile = task->obj.tile;
        switch (task->substate) {
        case 0:
        default:
            tile->frame = 5;
            tile->visible = 1;
            break;
        case 1:
            tile->visible = 1;
            frame = stepAnimationOnce(&task->obj, D_800A55F4, 0);
            if (frame != 0xFF) {
                tile->frame = frame;
            } else {
                tile->frame = 10;
                task->nextSubstate(task);
                SOUND.keyOff(0xA0042FCB, task->voice);
            }
            break;
        case 2:
            tile->visible = 1;
            tile->frame = 10;
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void func_800A4EDC(StageSoundTile *task, s32 id) {
    if (task != NULL && id == 0x335) {
        task->voice = SOUND.playSound(0xA0042FCB);
        task->obj.anim.index = 0;
        task->obj.anim.timer = D_800A55F4[0].duration;
        task->setSubstate(task, 1);
    }
}

void *func_800A4F48(s32 arg) {
    return createTaskWithId(func_800A4D7C, 0x5C, 0, arg);
}

/* Creates the event object of progress 0x25 or 0x27, and the stage helper task before progress 0x27 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        switch (GAME.progress) {
        case 0x25:
            children[1] = FIELDSTG_startEvent(0x3A2);
            break;
        case 0x27:
            children[1] = FIELDSTG_startEvent(0x3D4);
            break;
        }
        if (GAME.progress < 0x27) {
            children[0] = func_800A4F48(0x353);
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

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x536
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x546
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13900, 0x11B00};
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

extern u16 D_800A5834[];
extern u16 D_800A583C[];
extern u16 D_800A5844[];
extern FieldTalk D_800A572C[];
extern u16 D_800A584C[];
extern FieldTalk D_800A5744[];
extern u16 D_800A5854[];
extern FieldTalk D_800A575C[];
extern u16 D_800A585C[];
extern FieldTalk D_800A5774[];
extern u16 D_800A5864[];
extern FieldTalk D_800A578C[];
extern u16 D_800A586C[];
extern FieldTalk D_800A57A4[];
extern u16 D_800A5874[];
extern FieldTalk D_800A57BC[];
extern u16 D_800A587C[];
extern FieldTalk D_800A57D4[];
extern u16 D_800A5884[];
extern FieldTalk D_800A57EC[];
extern u16 D_800A588C[];
extern FieldTalk D_800A5804[];
extern u16 D_800A5894[];
extern FieldTalk D_800A581C[];
extern FieldActorEntry D_800A589C;
extern FieldActorEntry D_800A58B0;
extern FieldActorEntry D_800A58C4;
extern FieldActorEntry D_800A58D8;
extern FieldActorEntry D_800A58EC;
extern FieldActorEntry D_800A5900;
extern FieldActorEntry D_800A5914;
extern FieldActorEntry D_800A5928;
extern FieldActorEntry D_800A593C;
extern FieldActorEntry D_800A5950;
extern FieldActorEntry D_800A5964;
extern FieldActorEntry D_800A5978;
extern FieldActorEntry D_800A598C;
extern s16 D_800A51B8[];
extern s16 D_800A52F8[];
extern s16 D_800A5348[];

s16 D_800A51B8[] = {
    0x100, 1, 0x4F, 0x191,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0x148, 0x115, 5,
    0x302, 1,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x3A, 1,
    0x300, 0xB4,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 1, 0,
    0x101, 1, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x3A, 1,
    0x300, 0xB4,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 2, 1, 0,
    0x101, 1, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 0x29, 1,
    0x300, 0x3C,
    0x101, 1, 0x2A, 1,
    0x300, 0x78,
    0x101, 1, 0x29, 1,
    0x300, 0x1E,
    0x101, 0x353, 0x335, 1,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 1,
    0x300, 0x3C,
    0x101, 1, 1, 5,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x200, 0, 3, 1, 0,
    0x101, 1, 7, 5,
    0x301,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0x190, 0xF0, 5,
    0x300, 0x3C,
    0x304, 0x288, 0x58, 0x20C, 5,
    0,
};
s16 D_800A52F8[] = {
    0x102, 2, 0x188, 0xF5, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x304, 0x288, 0x58, 0x20C, 5,
    0,
};
s16 D_800A5348[] = {
    0x100, 1, 0x4F, 0x190,
    0x101, 1, 1, 5,
    0x100, 0x9D, 0x168, 0x115,
    0x101, 0x9D, 1, 5,
    0x100, 0x9E, 0x148, 0x104,
    0x101, 0x9E, 1, 5,
    0x100, 0x119, 0x14F, 0x128,
    0x101, 0x119, 1, 5,
    0x100, 0x13A, 0x120, 0x110,
    0x101, 0x13A, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0xD0, 0x150, 5,
    0x302, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 1,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 1,
    0x300, 0x1E,
    0x101, 0x9D, 1, 1,
    0x101, 0x9E, 1, 1,
    0x101, 0x119, 1, 1,
    0x101, 0x13A, 1, 1,
    0x300, 0x1E,
    0x102, 1, 0x117, 0x12C, 5,
    0x302, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x601, 0, 0x136, 0x11B,
    0x101, 0x119, 1, 2,
    0x101, 0x13A, 1, 0,
    0x300, 0x1E,
    0x200, 1, 2, 0x13A, 0,
    0x200, 0, 1, 0x119, 2,
    0x301,
    0x300, 0x1E,
    0x200, 1, 4, 0x9E, 0,
    0x200, 0, 3, 0x9D, 2,
    0x301,
    0x300, 0x1E,
    0x101, 1, 1, 4,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 6,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 1, 0,
    0x101, 1, 7, 5,
    0x301,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 6,
    0x300, 0x1E,
    0x200, 0, 6, 0x119, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 1, 0,
    0x101, 1, 7, 6,
    0x301,
    0x101, 1, 1, 6,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x600, 0, 1,
    0x102, 1, 0x13F, 0x118, 5,
    0x302, 1,
    0x102, 1, 0x171, 0xFF, 5,
    0x302, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 0x9D, 1, 5,
    0x101, 0x9E, 1, 5,
    0x101, 0x119, 1, 5,
    0x101, 0x13A, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x200, 0, 8, 1, 0,
    0x101, 1, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x601, 0, 0x13F, 0x118,
    0x200, 1, 0xA, 0x13A, 0,
    0x200, 0, 9, 0x119, 2,
    0x301,
    0x300, 0x1E,
    0x200, 1, 0xC, 0x9E, 0,
    0x200, 0, 0xB, 0x9D, 2,
    0x301,
    0x300, 0x1E,
    0x600, 0, 1,
    0x101, 1, 9, 1,
    0x303, 1,
    0x101, 1, 1, 1,
    0x300, 0x1E,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x102, 1, 0x1A0, 0xE8, 5,
    0x300, 6,
    0x304, 0x288, 0x60, 0x208, 5,
    0,
};
AnimFrame D_800A55F4[] = {
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 8, 4 },
    { 9, 4 }, { 255, 0x3E7 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x18C, 0xD8, 0x8C, 0x140, 0x1FB },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x180, 0x100, 0x19A, 0x100, 0x168, 0, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1A2, 0x100, 0x188, 0, 0x160, 0x1FB },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x180, 0x100, 0x180, 0x114, 0x100, 0x14, 0x150, 0x1FA },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x180, 0x100, 0x188, 0x116, 0x120, 0x16, 0x160, 0x1FA },
};
FieldTalk D_800A572C[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5744[] = {
    { NULL, NULL, 6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A575C[] = {
    { NULL, NULL, 0x1F9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5774[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A578C[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A4[] = {
    { NULL, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57BC[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D4[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57EC[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A581C[] = {
    { NULL, NULL, 5 },
    { NULL, NULL, 0 },
};
u16 D_800A5834[] = { 0x6025, 1, 0xFFFF };
u16 D_800A583C[] = { 0x6027, 1, 0xFFFF };
u16 D_800A5844[] = { 0x7094, 1, 0xFFFF };
u16 D_800A584C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5854[] = { 0x701A, 1, 0xFFFF };
u16 D_800A585C[] = { 0x7094, 1, 0xFFFF };
u16 D_800A5864[] = { 0x7094, 1, 0xFFFF };
u16 D_800A586C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5874[] = { 0x7094, 1, 0xFFFF };
u16 D_800A587C[] = { 0x7094, 1, 0xFFFF };
u16 D_800A5884[] = { 0x7094, 1, 0xFFFF };
u16 D_800A588C[] = { 0x7094, 1, 0xFFFF };
u16 D_800A5894[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A589C = { D_800A5834, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A58B0 = { D_800A583C, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A58C4 = { D_800A5844, D_800A572C, 0x3F, 5, 121, 260, 7 };
FieldActorEntry D_800A58D8 = { D_800A584C, D_800A5744, 0x9D, 6, 463, 264, 1 };
FieldActorEntry D_800A58EC = { D_800A5854, D_800A575C, 0x9E, 7, 367, 312, 5 };
FieldActorEntry D_800A5900 = { D_800A585C, D_800A5774, 0xC6, 8, 185, 229, 7 };
FieldActorEntry D_800A5914 = { D_800A5864, D_800A578C, 0xC7, 9, 249, 197, 7 };
FieldActorEntry D_800A5928 = { D_800A586C, D_800A57A4, 0x119, 0xA, 428, 278, 1 };
FieldActorEntry D_800A593C = { D_800A5874, D_800A57BC, 0x121, 0xB, 376, 188, 1 };
FieldActorEntry D_800A5950 = { D_800A587C, D_800A57D4, 0x122, 0xC, 360, 380, 3 };
FieldActorEntry D_800A5964 = { D_800A5884, D_800A57EC, 0x123, 0xD, 424, 348, 3 };
FieldActorEntry D_800A5978 = { D_800A588C, D_800A5804, 0x124, 0xE, 488, 316, 3 };
FieldActorEntry D_800A598C = { D_800A5894, D_800A581C, 0x13A, 0xF, 451, 290, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A589C,
    &D_800A58B0,
    &D_800A58C4,
    &D_800A58D8,
    &D_800A58EC,
    &D_800A5900,
    &D_800A5914,
    &D_800A5928,
    &D_800A593C,
    &D_800A5950,
    &D_800A5964,
    &D_800A5978,
    &D_800A598C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x3B, 6, 0, 374, 136, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x45, 8, 0, 408, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x46, 1, 0x46, 0x57, 8, 0, 418, 102, 0, 0 },
    { 0, 1, 0x40, 6, 5, 0, 5, 0xA, 4, 0, 382, 196, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 453, 185, 199, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 449, 190, 204, 0 },
    { 1, 0, 0x58, 4, 2, 0, 0, 0, 0, 0, 351, 136, 218, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 215, 302, 353, 0 },
    { 1, 0, 0x48, 4, 4, 0, 0, 0, 0, 0, 144, 262, 322, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x286, 0x398, 0xCC, 1, 0, 0, 0 },
    { { { 0x701A, 1 }, { 0xFFFF, 0 } }, 8, 0x3C6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 930, D_800A51B8, EVENT_TEXT(0xF), NULL, NULL },
    { 966, D_800A52F8, EVENT_TEXT(0x15), NULL, NULL },
    { 980, D_800A5348, EVENT_TEXT(0x17), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
