#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
void func_800A4D80();
extern AnimFrame D_800A5234[];

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

/* Plays the animation of the record with animation 1 once with a sound when the substate is 0, then kills itself */
void func_800A4D80(StageTileTask *task) {
    StageTile *rec;
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->obj.anim.index = 0;
        task->obj.anim.timer = D_800A5234[0].duration;
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
            if (rec->anim == 1) {
                task->obj.tile = rec;
            }
        }
        break;
    case TASK_RUN:
        if (task->substate == 0) {
            task->obj.anim.index = 0;
            task->obj.anim.timer = D_800A5234[0].duration;
            task->setSubstate(task, 1);
            SOUND.playSound(0x8004213E);
        }
        tile = task->obj.tile;
        frame = stepAnimationOnce(&task->obj, D_800A5234, 0);
        if (frame == 0xFF) {
            tile->visible = 0;
            task->setState(task, TASK_KILL);
        } else {
            tile->visible = 1;
            tile->frame = frame;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A4ED4(s32 arg) {
    return createTaskWithId(func_800A4D80, 0x58, 0, arg);
}

/* Creates the event object of story progress 14 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xE && FLAGS_00.checkCondition(0x800E, 1)) {
            children[0] = FIELDSTG_startEvent(0x168);
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

void func_800A4FF4(void) {
    FLAGS_00.applyAction(0x4007, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x381
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x391
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1FA00, 0x21F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x34;
    D_800990B4.music = 0x60D00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A529C;
extern Battle D_800A52A8;
extern Battle D_800A52B4;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A541C;
extern Battle D_800A5428;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern BattleList D_800A52D8;
extern BattleList D_800A535C;
extern BattleList D_800A53E0;
extern BattleList D_800A5464;
extern u16 D_800A5524[];
extern u16 D_800A552C[];
extern u16 D_800A5538[];
extern u16 D_800A5540[];
extern u16 D_800A557C[];
extern FieldTalk D_800A554C[];
extern FieldActorEntry D_800A558C;
extern FieldActorEntry D_800A55A0;
extern s16 D_800A5150[];

s16 D_800A5150[] = {
    0x100, 1, 0x458, 0xCC,
    0x101, 1, 1, 3,
    0x100, 1, 0x458, 0xCC,
    0x101, 1, 1, 3,
    0x300, 0x78,
    0x300, 0x1E,
    0x200, 0, 1, 1, 3,
    0x301,
    0x300, 0x1E,
    0x601, 0, 0x418, 0x94,
    0x300, 0x3C,
    0x102, 1, 0x428, 0xB4, 3,
    0x302, 1,
    0x300, 0x3C,
    0x101, 0x32D, 0x36C, 1,
    0x300, 0x3C,
    0x102, 1, 0x470, 0xD8, 7,
    0x302, 1,
    0x101, 1, 0x43, 7,
    0x300, 0x5A,
    0x101, 0x32D, 0x372, 1,
    0x101, 0x33C, 0x335, 1,
    0x300, 0x3C,
    0x101, 0x32D, 0x373, 1,
    0x300, 0x3C,
    0x101, 1, 1, 7,
    0x300, 0x3C,
    0x101, 1, 1, 3,
    0x300, 0x1E,
    0x600, 0, 1,
    0x200, 0, 2, 1, 1,
    0x301,
    0x300, 0x1E,
    0x102, 1, 0x428, 0xB4, 3,
    0x300, 6,
    0x304, 0x236, 0xD6, 0x84, 1,
    0,
};
AnimFrame D_800A5234[] = {
    { 11, 4 }, { 12, 4 }, { 13, 4 }, { 14, 4 },
    { 15, 4 }, { 16, 4 }, { 17, 4 }, { 18, 4 },
    { 19, 4 }, { 20, 4 }, { 21, 4 }, { 22, 4 },
    { 23, 4 }, { 23, 4 }, { 24, 4 }, { 25, 4 },
    { 255, 0x3E7 },
};
Battle D_800A5278 = { 54, 8, 0x60080000 };
Battle D_800A5284 = { 54, 8, 0x60080000 };
Battle D_800A5290 = { 66, 8, 0x60080000 };
Battle D_800A529C = { 66, 8, 0x60080000 };
Battle D_800A52A8 = { 66, 8, 0x60080000 };
Battle D_800A52B4 = { 66, 8, 0x60080000 };
Battle D_800A52C0 = { 66, 8, 0x60080000 };
Battle D_800A52CC = { 66, 8, 0x60080000 };
BattleList D_800A52D8 = {
    3,
    { &D_800A5278, &D_800A5284, &D_800A5290, &D_800A529C,
      &D_800A52A8, &D_800A52B4, &D_800A52C0, &D_800A52CC },
};
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
Battle D_800A5314 = { 0, 0, 0x60040000 };
Battle D_800A5320 = { 0, 0, 0x60040000 };
Battle D_800A532C = { 0, 0, 0x60040000 };
Battle D_800A5338 = { 0, 0, 0x60040000 };
Battle D_800A5344 = { 0, 0, 0x60040000 };
Battle D_800A5350 = { 0, 0, 0x60040000 };
BattleList D_800A535C = {
    0,
    { &D_800A52FC, &D_800A5308, &D_800A5314, &D_800A5320,
      &D_800A532C, &D_800A5338, &D_800A5344, &D_800A5350 },
};
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
BattleList D_800A53E0 = {
    0,
    { &D_800A5380, &D_800A538C, &D_800A5398, &D_800A53A4,
      &D_800A53B0, &D_800A53BC, &D_800A53C8, &D_800A53D4 },
};
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
Battle D_800A541C = { 0, 0, 0x60040000 };
Battle D_800A5428 = { 329, 8, 0x60080000 };
Battle D_800A5434 = { 328, 8, 0x60080000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 147, 8, 0x60080000 };
Battle D_800A5458 = { 66, 8, 0x60080000 };
BattleList D_800A5464 = {
    0,
    { &D_800A5404, &D_800A5410, &D_800A541C, &D_800A5428,
      &D_800A5434, &D_800A5440, &D_800A544C, &D_800A5458 },
};
FieldBattles stageBattles[] = {
    { 16, 0, 0, { &D_800A52D8, &D_800A535C, &D_800A53E0, &D_800A5464 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1AE, 0x120, 0x1B8, 0x20, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A5524[] = { 0x1A02, 0, 0xFFFF };
u16 D_800A552C[] = { 0x1A02, 1, 0x8010, 0, 0xFFFF };
u16 D_800A5538[] = { 0x1A2A, 1, 0xFFFF };
u16 D_800A5540[] = { 0x1A02, 1, 0x8010, 1, 0xFFFF };
FieldTalk D_800A554C[] = {
    { D_800A5524, NULL, 0x2EA },
    { D_800A552C, D_800A5538, 0x2EB },
    { D_800A5540, NULL, 0x2EC },
    { NULL, NULL, 0 },
};
u16 D_800A557C[] = { 0x600E, 1, 0x800E, 1, 0x4007, 0, 0xFFFF };
FieldActorEntry D_800A558C = { D_800A557C, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A55A0 = { NULL, D_800A554C, 0x3F, 5, 1051, 195, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A558C,
    &D_800A55A0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 250, 247, 0, 0 },
    { 0, 1, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 1038, 93, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 759, 577, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 869, 106, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 994, 307, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 246, 499, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 424, 419, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 614, 701, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 668, 634, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 195, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 572, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 658, 704, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1002, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 175, 158, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 234, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 254, 557, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 339, 312, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 420, 249, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 553, 243, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 724, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1182, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1216, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 466, 173, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 497, 669, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 568, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 601, 271, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 752, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 883, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1144, 314, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1162, 505, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 181, 167, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 496, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 667, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 679, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 794, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 969, 437, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 970, 588, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1087, 527, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 178, 286, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 225, 218, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 279, 323, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 285, 331, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 294, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 296, 531, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 299, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 321, 97, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 333, 157, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 338, 595, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 425, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 443, 339, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 489, 139, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 529, 228, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 567, 255, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 620, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 644, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 653, 273, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 655, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 681, 567, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 687, 716, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 726, 322, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 785, 99, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 793, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 825, 78, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 850, 452, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 879, 564, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 896, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 927, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 951, 92, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1040, 353, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1166, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1193, 278, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1200, 176, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 196, 394, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 233, 570, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 266, 262, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 280, 143, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 338, 500, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 440, 190, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 480, 610, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 484, 436, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 509, 342, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 620, 259, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 622, 389, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 628, 558, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 690, 250, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 718, 579, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 771, 678, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 780, 152, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 823, 557, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 916, 401, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 994, 524, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1047, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1055, 275, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1143, 443, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1162, 211, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 234, 174, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 235, 470, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 305, 395, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 307, 577, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 396, 324, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 418, 117, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 470, 418, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 521, 199, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 553, 384, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 561, 338, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 566, 185, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 569, 289, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 581, 678, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 587, 258, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 662, 523, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 666, 213, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 687, 469, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 690, 89, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 729, 413, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 765, 344, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 818, 233, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 868, 378, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 915, 101, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 927, 583, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 974, 343, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1019, 574, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1121, 179, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1124, 520, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1126, 309, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1178, 348, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1183, 153, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1202, 460, 0, 0 },
    { 1, 0, 0xDA, 4, 0, 0, 0, 0, 0, 0, 923, 72, 210, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 979, 425, 436, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 674, 460, 490, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 392, 185, 185, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 481, 549, 549, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 545, 613, 613, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 817, 189, 189, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 865, 165, 165, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x234, 0x570, 0x3B8, 3, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0xFFEC, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 360, D_800A5150, EVENT_TEXT(0x27), NULL, func_800A4FF4 },
    { -1, NULL, 0, NULL, NULL },
};
