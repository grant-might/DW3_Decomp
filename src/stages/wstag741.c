#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
void func_800A4CA8();
extern s32 D_800A59A0[];
void *func_800A5380(s32 x, s32 y);
void func_800A51E8();
extern AnimFrame D_800A59AC[];
extern AnimFrame D_800A59C8[];
extern AnimFrame *D_800A5A00[];

void func_800A4CA8(StageTask *task, StagePartyChildren *children) {
    StageActor *player;
    StageActor *actor;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        switch (task->substate) {
        case 0:
        default:
            switch (task->step) {
            case 0:
            default:
                player = TASK_REGISTRY.funcs.find(5, -1, 0);
                player->setSubstate(player, 1);
                SOUND.playSound(0x800410BD);
                task->nextStep(task);
            case 1:
                task->counter += GFX.funcs.getFrameTime();
                if (task->counter >= 0x1E) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 1:
        case 2:
        case 3:
            switch (task->step) {
            case 0:
            default:
                i = task->substate - 1;
                actor = TASK_REGISTRY.funcs.find(5, -1, D_800A59A0[i]);
                if (actor != NULL) {
                    children->party[i] = func_800A5380(actor->tileX, actor->tileY);
                    SOUND.playSound(0x800446C9);
                    actor->setSubstate(actor, 4);
                    GAME.partners[GAME.party[i]].info.stats[STAT_HP] = 1;
                    task->nextStep(task);
                } else {
                    task->nextSubstate(task);
                }
                break;
            case 1:
                task->counter += GFX.funcs.getFrameTime();
                if (task->counter >= 0x1E) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 4:
            task->nextState(task);
            break;
        }
        break;
    case TASK_RUN:
        if (children->party[0] == NULL) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A4F30(void) {
    return createTask(func_800A4CA8, 0x54, 0xC);
}

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4084, 1) && FLAGS_00.checkCondition(0x4085, 0)) {
            children[1] = FIELDSTG_startEvent(0x510);
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

s32 stepAnimationOnce(AnimState *anim, AnimFrame *frames, s32 depth) {
    AnimFrame *frame = &frames[anim->index];
    s32 dt = GFX.funcs.getFrameTime();

    if (dt > 4) {
        dt = 4;
    }
    if (depth == 0) {
        anim->timer -= dt;
    }
    if (anim->timer <= 0) {
        frame++;
        anim->index++;
        anim->timer += frame->duration;
        if (frame->frame == 0xFF) {
            return 0xFF;
        }
        stepAnimationOnce(anim, frames, depth + 1);
    }
    return frame->frame;
}

void func_800A5130(StageSpritePair *task, void *arg, s32 idx) {
    SpriteDrawer drawer;
    Layer *layer = arg;
    StageSprite *sprite = &task->sprites[idx];

    initSpriteDrawer(&drawer);
    drawer.setTexture(0x140, 0x100);
    drawer.setLayer(layer, 4);
    drawer.setClutRow(sprite->clutRow);
    drawer.draw(FILE_CACHE.getEntry(D_800990B4.sheetEntry), sprite->frame, task->x, task->y);
}

void func_800A51E8(StageSpritePair *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    s32 done;
    s32 i;
    s32 frame;
    s32 y;
    void (*draw)();

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A59AC[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A59C8[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        done = 0;
        i = 0;
        draw = func_800A5130;
        for (; i < 2; i++) {
            frame = stepAnimationOnce(&task->anims[i], D_800A5A00[i], 0);
            switch (frame) {
            case 0xFF:
                task->sprites[i].frame = 0;
                done++;
                break;
            case 0x12C:
                task->sprites[i].frame = 0;
                break;
            default:
                task->sprites[i].frame = frame;
                break;
            }
            if (task->sprites[i].frame != 0) {
                y = task->y;
                if (i == 0) {
                    y -= 0xF0;
                } else {
                    y += 0x14;
                }
                layer->addSortedCallback(layer, draw, task, y, i);
            }
        }
        if (done == 2) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5380(s32 x, s32 y) {
    StageSpritePair *task = createTask(func_800A51E8, sizeof(StageSpritePair), 0);

    task->x = x;
    task->y = y;
    return task;
}

void func_800A53C8(void) {
    FLAGS_00.applyAction(0x4084, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A5414(void) {
    FLAGS_00.applyAction(0x4085, 1);
    FLAGS_00.applyAction(0x8233, 1);
}

void func_800A5460(void) {
    FLAGS_00.applyAction(0x40BA, 1);
}

void func_800A548C(void) {
    FLAGS_00.applyAction(0x40BB, 1);
}

void func_800A54B8(void) {
    FLAGS_00.applyAction(0x40BC, 1);
}

void func_800A54E4(void) {
    FLAGS_00.applyAction(0x40BD, 1);
}

void func_800A5510(void) {
    FLAGS_00.applyAction(0x40BE, 1);
}

void func_800A553C(void) {
    FLAGS_00.applyAction(0x40BF, 1);
}

void func_800A5568(void) {
    FLAGS_00.applyAction(0x40C0, 1);
}

void func_800A5594(void) {
    FLAGS_00.applyAction(0x40C1, 1);
}

void func_800A55C0(void) {
    FLAGS_00.applyAction(0x40C2, 1);
}

void func_800A55EC(void) {
    FLAGS_00.applyAction(0x40C3, 1);
}

void func_800A5618(void) {
    FLAGS_00.applyAction(0x40C4, 1);
}

void func_800A5644(void) {
    FLAGS_00.applyAction(0x40C5, 1);
}

void func_800A5670(void) {
    FLAGS_00.applyAction(0x40C6, 1);
}

void func_800A569C(void) {
    FLAGS_00.applyAction(0x40C7, 1);
}

void func_800A56C8(void) {
    FLAGS_00.applyAction(0x40C8, 1);
}

void func_800A56F4(void) {
    FLAGS_00.applyAction(0x40C9, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x741
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x751
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1CD00, 0x29A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x19;
    D_800990B4.music = 0x60640000;
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

extern Battle D_800A5A08;
extern Battle D_800A5A14;
extern Battle D_800A5A20;
extern Battle D_800A5A2C;
extern Battle D_800A5A38;
extern Battle D_800A5A44;
extern Battle D_800A5A50;
extern Battle D_800A5A5C;
extern Battle D_800A5A8C;
extern Battle D_800A5A98;
extern Battle D_800A5AA4;
extern Battle D_800A5AB0;
extern Battle D_800A5ABC;
extern Battle D_800A5AC8;
extern Battle D_800A5AD4;
extern Battle D_800A5AE0;
extern Battle D_800A5B10;
extern Battle D_800A5B1C;
extern Battle D_800A5B28;
extern Battle D_800A5B34;
extern Battle D_800A5B40;
extern Battle D_800A5B4C;
extern Battle D_800A5B58;
extern Battle D_800A5B64;
extern Battle D_800A5B94;
extern Battle D_800A5BA0;
extern Battle D_800A5BAC;
extern Battle D_800A5BB8;
extern Battle D_800A5BC4;
extern Battle D_800A5BD0;
extern Battle D_800A5BDC;
extern Battle D_800A5BE8;
extern BattleList D_800A5A68;
extern BattleList D_800A5AEC;
extern BattleList D_800A5B70;
extern BattleList D_800A5BF4;
extern u16 D_800A5CB4[];
extern u16 D_800A5CBC[];
extern u16 D_800A5CC4[];
extern u16 D_800A5CCC[];
extern u16 D_800A5CD4[];
extern u16 D_800A5CDC[];
extern u16 D_800A5CE4[];
extern u16 D_800A5CEC[];
extern u16 D_800A5D9C[];
extern FieldTalk D_800A5CF4[];
extern u16 D_800A5DA8[];
extern FieldTalk D_800A5D0C[];
extern u16 D_800A5DB4[];
extern FieldTalk D_800A5D24[];
extern u16 D_800A5DC4[];
extern FieldTalk D_800A5D60[];
extern FieldActorEntry D_800A5DD4;
extern FieldActorEntry D_800A5DE8;
extern FieldActorEntry D_800A5DFC;
extern FieldActorEntry D_800A5E10;
extern s16 D_800A5850[];
extern s16 D_800A58E8[];

s16 D_800A5850[] = {
    0x600, 1, 2,
    0x102, 2, 0x215, 0x2AC, 3,
    0x100, 0xCC, 0x200, 0x2A1,
    0x101, 0xCC, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xCC, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCC, 2,
    0x301,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A58E8[] = {
    0x600, 1, 0xCC,
    0x100, 2, 0x215, 0x2AC,
    0x101, 2, 1, 3,
    0x100, 0xCC, 0x200, 0x2A1,
    0x101, 0xCC, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xCC, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x101, 0xCC, 1, 3,
    0x300, 0x1E,
    0x102, 0xCC, 0x1D0, 0x288, 3,
    0x302, 0xCC,
    0x101, 0xCC, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x200, 0x2A1, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCC, 2,
    0x301,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
s32 D_800A59A0[] = {
    2, 4, 8,
};
AnimFrame D_800A59AC[] = {
    { 50, 4 }, { 51, 4 }, { 52, 4 }, { 53, 4 },
    { 54, 4 }, { 55, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A59C8[] = {
    { 0x12C, 4 }, { 56, 4 }, { 57, 4 }, { 58, 4 },
    { 59, 4 }, { 60, 4 }, { 61, 4 }, { 62, 4 },
    { 63, 4 }, { 64, 4 }, { 65, 4 }, { 66, 4 },
    { 67, 4 }, { 255, 0x3E7 },
};
AnimFrame *D_800A5A00[] = {
    D_800A59AC, D_800A59C8,
};
Battle D_800A5A08 = { 136, 24, 0x60080000 };
Battle D_800A5A14 = { 136, 24, 0x60080000 };
Battle D_800A5A20 = { 136, 24, 0x60080000 };
Battle D_800A5A2C = { 183, 24, 0x60080000 };
Battle D_800A5A38 = { 183, 24, 0x60080000 };
Battle D_800A5A44 = { 183, 24, 0x60080000 };
Battle D_800A5A50 = { 118, 24, 0x60080000 };
Battle D_800A5A5C = { 118, 24, 0x60080000 };
BattleList D_800A5A68 = {
    5,
    { &D_800A5A08, &D_800A5A14, &D_800A5A20, &D_800A5A2C,
      &D_800A5A38, &D_800A5A44, &D_800A5A50, &D_800A5A5C },
};
Battle D_800A5A8C = { 0, 0, 0x60040000 };
Battle D_800A5A98 = { 0, 0, 0x60040000 };
Battle D_800A5AA4 = { 0, 0, 0x60040000 };
Battle D_800A5AB0 = { 0, 0, 0x60040000 };
Battle D_800A5ABC = { 0, 0, 0x60040000 };
Battle D_800A5AC8 = { 0, 0, 0x60040000 };
Battle D_800A5AD4 = { 0, 0, 0x60040000 };
Battle D_800A5AE0 = { 0, 0, 0x60040000 };
BattleList D_800A5AEC = {
    0,
    { &D_800A5A8C, &D_800A5A98, &D_800A5AA4, &D_800A5AB0,
      &D_800A5ABC, &D_800A5AC8, &D_800A5AD4, &D_800A5AE0 },
};
Battle D_800A5B10 = { 0, 0, 0x60040000 };
Battle D_800A5B1C = { 0, 0, 0x60040000 };
Battle D_800A5B28 = { 0, 0, 0x60040000 };
Battle D_800A5B34 = { 0, 0, 0x60040000 };
Battle D_800A5B40 = { 0, 0, 0x60040000 };
Battle D_800A5B4C = { 0, 0, 0x60040000 };
Battle D_800A5B58 = { 0, 0, 0x60040000 };
Battle D_800A5B64 = { 0, 0, 0x60040000 };
BattleList D_800A5B70 = {
    0,
    { &D_800A5B10, &D_800A5B1C, &D_800A5B28, &D_800A5B34,
      &D_800A5B40, &D_800A5B4C, &D_800A5B58, &D_800A5B64 },
};
Battle D_800A5B94 = { 28, 24, 0x608C0000 };
Battle D_800A5BA0 = { 0, 0, 0x60040000 };
Battle D_800A5BAC = { 0, 0, 0x60040000 };
Battle D_800A5BB8 = { 0, 0, 0x60040000 };
Battle D_800A5BC4 = { 0, 0, 0x60040000 };
Battle D_800A5BD0 = { 0, 0, 0x60040000 };
Battle D_800A5BDC = { 0, 0, 0x60040000 };
Battle D_800A5BE8 = { 0, 0, 0x60040000 };
BattleList D_800A5BF4 = {
    0,
    { &D_800A5B94, &D_800A5BA0, &D_800A5BAC, &D_800A5BB8,
      &D_800A5BC4, &D_800A5BD0, &D_800A5BDC, &D_800A5BE8 },
};
FieldBattles stageBattles[] = {
    { 121, 0, 0, { &D_800A5A68, &D_800A5AEC, &D_800A5B70, &D_800A5BF4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x158, 0x100, 0x58, 0x140, 0x1FB },
    { 0x180, 0x100, 0x1A6, 0x158, 0x198, 0x58, 0x150, 0x1FB },
};
u16 D_800A5CB4[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5CBC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5CC4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5CCC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5CD4[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5CDC[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5CE4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5CEC[] = { 0x602B, 1, 0xFFFF };
FieldTalk D_800A5CF4[] = {
    { NULL, NULL, 0x214 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D0C[] = {
    { NULL, NULL, 0x214 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D24[] = {
    { D_800A5CB4, NULL, 0x211 },
    { D_800A5CBC, NULL, 0x212 },
    { D_800A5CC4, NULL, 0x213 },
    { D_800A5CCC, NULL, 0x206 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D60[] = {
    { D_800A5CD4, NULL, 0x211 },
    { D_800A5CDC, NULL, 0x212 },
    { D_800A5CE4, NULL, 0x213 },
    { D_800A5CEC, NULL, 0x215 },
    { NULL, NULL, 0 },
};
u16 D_800A5D9C[] = { 0x4085, 0, 0x701A, 1, 0xFFFF };
u16 D_800A5DA8[] = { 0x701A, 1, 0x4085, 1, 0xFFFF };
u16 D_800A5DB4[] = { 0x7008, 1, 0x4085, 0, 0x701A, 0, 0xFFFF };
u16 D_800A5DC4[] = { 0x7008, 1, 0x4085, 1, 0x701A, 0, 0xFFFF };
FieldActorEntry D_800A5DD4 = { D_800A5D9C, D_800A5CF4, 0x9D, 4, 512, 673, 7 };
FieldActorEntry D_800A5DE8 = { D_800A5DA8, D_800A5D0C, 0x9D, 4, 464, 648, 7 };
FieldActorEntry D_800A5DFC = { D_800A5DB4, D_800A5D24, 0xCC, 5, 512, 673, 7 };
FieldActorEntry D_800A5E10 = { D_800A5DC4, D_800A5D60, 0xCC, 5, 464, 648, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5DD4,
    &D_800A5DE8,
    &D_800A5DFC,
    &D_800A5E10,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 6, 0, 224, 601, 638, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 5, 0, 253, 334, 371, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 5, 0, 465, 242, 274, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 6, 0, 607, 402, 441, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 4, 0, 647, 343, 371, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 4, 0, 699, 740, 781, 0 },
    { 1, 0, 0x40, 4, 0x50, 1, 0x50, 0x63, 4, 0, 760, 579, 615, 0 },
    { 1, 0, 0x40, 4, 0xA, 1, 0xA, 0x1D, 5, 0, 213, 576, 638, 0 },
    { 1, 0, 0x40, 4, 0xA, 1, 0xA, 0x1D, 6, 0, 267, 297, 371, 0 },
    { 1, 0, 0x40, 4, 0xA, 1, 0xA, 0x1D, 4, 0, 472, 403, 466, 0 },
    { 1, 0, 0x40, 4, 0xA, 1, 0xA, 0x1D, 5, 0, 616, 385, 441, 0 },
    { 1, 0, 0x40, 4, 0xA, 1, 0xA, 0x1D, 6, 0, 855, 692, 756, 0 },
    { 1, 0, 0x40, 4, 0x1E, 1, 0x1E, 0x31, 5, 0, 331, 427, 493, 0 },
    { 1, 0, 0x40, 4, 0x1E, 1, 0x1E, 0x31, 6, 0, 465, 211, 274, 0 },
    { 1, 0, 0x40, 4, 0x1E, 1, 0x1E, 0x31, 4, 0, 698, 429, 493, 0 },
    { 1, 0, 0x40, 4, 0x1E, 1, 0x1E, 0x31, 5, 0, 699, 715, 781, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D2, 0x70, 0x2EC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D4, 0x448, 0x288, 1, 0, 0, 0 },
    { { { 0x40BA, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0x40BB, 0 }, { 0xFFFF, 0 } }, 8, 0x2329, 0, 0, 0, 0, 0, 0 },
    { { { 0x40BC, 0 }, { 0xFFFF, 0 } }, 8, 0x232A, 0, 0, 0, 0, 0, 0 },
    { { { 0x40BD, 0 }, { 0xFFFF, 0 } }, 8, 0x232B, 0, 0, 0, 0, 0, 0 },
    { { { 0x40BE, 0 }, { 0xFFFF, 0 } }, 8, 0x232C, 0, 0, 0, 0, 0, 0 },
    { { { 0x40BF, 0 }, { 0xFFFF, 0 } }, 8, 0x232D, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C0, 0 }, { 0xFFFF, 0 } }, 8, 0x232E, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C1, 0 }, { 0xFFFF, 0 } }, 8, 0x232F, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C2, 0 }, { 0xFFFF, 0 } }, 8, 0x2330, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C3, 0 }, { 0xFFFF, 0 } }, 8, 0x2331, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C4, 0 }, { 0xFFFF, 0 } }, 8, 0x2332, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C5, 0 }, { 0xFFFF, 0 } }, 8, 0x2333, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C6, 0 }, { 0xFFFF, 0 } }, 8, 0x2334, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C7, 0 }, { 0xFFFF, 0 } }, 8, 0x2335, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C8, 0 }, { 0xFFFF, 0 } }, 8, 0x2336, 0, 0, 0, 0, 0, 0 },
    { { { 0x40C9, 0 }, { 0xFFFF, 0 } }, 8, 0x2337, 0, 0, 0, 0, 0, 0 },
    { { { 0x4084, 0 }, { 0x701A, 0 } }, 8, 0x50F, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1295, D_800A5850, EVENT_TEXT(0x15), NULL, func_800A53C8 },
    { 1296, D_800A58E8, EVENT_TEXT(0x16), NULL, func_800A5414 },
    { 9000, NULL, 0, func_800A4F30, func_800A5460 },
    { 9001, NULL, 0, func_800A4F30, func_800A548C },
    { 9002, NULL, 0, func_800A4F30, func_800A54B8 },
    { 9003, NULL, 0, func_800A4F30, func_800A54E4 },
    { 9004, NULL, 0, func_800A4F30, func_800A5510 },
    { 9005, NULL, 0, func_800A4F30, func_800A553C },
    { 9006, NULL, 0, func_800A4F30, func_800A5568 },
    { 9007, NULL, 0, func_800A4F30, func_800A5594 },
    { 9008, NULL, 0, func_800A4F30, func_800A55C0 },
    { 9009, NULL, 0, func_800A4F30, func_800A55EC },
    { 9010, NULL, 0, func_800A4F30, func_800A5618 },
    { 9011, NULL, 0, func_800A4F30, func_800A5644 },
    { 9012, NULL, 0, func_800A4F30, func_800A5670 },
    { 9013, NULL, 0, func_800A4F30, func_800A569C },
    { 9014, NULL, 0, func_800A4F30, func_800A56C8 },
    { 9015, NULL, 0, func_800A4F30, func_800A56F4 },
    { -1, NULL, 0, NULL, NULL },
};
