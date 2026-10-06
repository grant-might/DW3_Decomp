#include "common.h"
#include "stage.h"
extern s32 D_800A598C[];
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
void func_800A4CA8();
void *func_800A5380(s32 x, s32 y);
extern AnimFrame D_800A5998[];
extern AnimFrame D_800A59B4[];
extern AnimFrame *D_800A59EC[];

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
                actor = TASK_REGISTRY.funcs.find(5, -1, D_800A598C[i]);
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
        if (FLAGS_00.checkCondition(0x403F, 1) && FLAGS_00.checkCondition(0x4040, 0)) {
            children[0] = FIELDSTG_startEvent(0x321);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
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

/* Draws sprite idx at (x, y) */
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
        task->anims[0].timer = D_800A5998[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A59B4[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        done = 0;
        i = 0;
        draw = func_800A5130;
        for (; i < 2; i++) {
            frame = stepAnimationOnce(&task->anims[i], D_800A59EC[i], 0);
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
    FLAGS_00.applyAction(0x403F, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets flags 0x8488 and 0x4040 */
void func_800A5414(void) {
    FLAGS_00.applyAction(0x8488, 1);
    FLAGS_00.applyAction(0x4040, 1);
}

void func_800A5460(void) {
    FLAGS_00.applyAction(0x40AA, 1);
}

void func_800A548C(void) {
    FLAGS_00.applyAction(0x40AB, 1);
}

void func_800A54B8(void) {
    FLAGS_00.applyAction(0x40AC, 1);
}

void func_800A54E4(void) {
    FLAGS_00.applyAction(0x40AD, 1);
}

void func_800A5510(void) {
    FLAGS_00.applyAction(0x40AE, 1);
}

void func_800A553C(void) {
    FLAGS_00.applyAction(0x40AF, 1);
}

void func_800A5568(void) {
    FLAGS_00.applyAction(0x40B0, 1);
}

void func_800A5594(void) {
    FLAGS_00.applyAction(0x40B1, 1);
}

void func_800A55C0(void) {
    FLAGS_00.applyAction(0x40B2, 1);
}

void func_800A55EC(void) {
    FLAGS_00.applyAction(0x40B3, 1);
}

void func_800A5618(void) {
    FLAGS_00.applyAction(0x40B4, 1);
}

void func_800A5644(void) {
    FLAGS_00.applyAction(0x40B5, 1);
}

void func_800A5670(void) {
    FLAGS_00.applyAction(0x40B6, 1);
}

void func_800A569C(void) {
    FLAGS_00.applyAction(0x40B7, 1);
}

void func_800A56C8(void) {
    FLAGS_00.applyAction(0x40B8, 1);
}

void func_800A56F4(void) {
    FLAGS_00.applyAction(0x40B9, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6CE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6DD
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12200, 0x2F400};
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

void func_800A5414();
extern Battle D_800A59F4;
extern Battle D_800A5A00;
extern Battle D_800A5A0C;
extern Battle D_800A5A18;
extern Battle D_800A5A24;
extern Battle D_800A5A30;
extern Battle D_800A5A3C;
extern Battle D_800A5A48;
extern Battle D_800A5A78;
extern Battle D_800A5A84;
extern Battle D_800A5A90;
extern Battle D_800A5A9C;
extern Battle D_800A5AA8;
extern Battle D_800A5AB4;
extern Battle D_800A5AC0;
extern Battle D_800A5ACC;
extern Battle D_800A5AFC;
extern Battle D_800A5B08;
extern Battle D_800A5B14;
extern Battle D_800A5B20;
extern Battle D_800A5B2C;
extern Battle D_800A5B38;
extern Battle D_800A5B44;
extern Battle D_800A5B50;
extern Battle D_800A5B80;
extern Battle D_800A5B8C;
extern Battle D_800A5B98;
extern Battle D_800A5BA4;
extern Battle D_800A5BB0;
extern Battle D_800A5BBC;
extern Battle D_800A5BC8;
extern Battle D_800A5BD4;
extern BattleList D_800A5A54;
extern BattleList D_800A5AD8;
extern BattleList D_800A5B5C;
extern BattleList D_800A5BE0;
extern u16 D_800A5D18[];
extern FieldTalk D_800A5CA0[];
extern u16 D_800A5D20[];
extern FieldTalk D_800A5CB8[];
extern u16 D_800A5D28[];
extern FieldTalk D_800A5CD0[];
extern u16 D_800A5D30[];
extern FieldTalk D_800A5CE8[];
extern u16 D_800A5D3C[];
extern FieldTalk D_800A5D00[];
extern FieldActorEntry D_800A5D48;
extern FieldActorEntry D_800A5D5C;
extern FieldActorEntry D_800A5D70;
extern FieldActorEntry D_800A5D84;
extern FieldActorEntry D_800A5D98;
extern s16 D_800A5850[];
extern s16 D_800A58F8[];

s16 D_800A5850[] = {
    0x600, 1, 2,
    0x102, 2, 0x215, 0x2AC, 3,
    0x100, 0xC9, 0x200, 0x2A1,
    0x101, 0xC9, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC9, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xC9, 2,
    0x301,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xC9, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A58F8[] = {
    0x600, 1, 0xC9,
    0x100, 2, 0x215, 0x2AC,
    0x101, 2, 1, 3,
    0x100, 0xC9, 0x200, 0x2A1,
    0x101, 0xC9, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xC9, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0xC9, 1, 3,
    0x300, 0x1E,
    0x102, 0xC9, 0x1D0, 0x288, 3,
    0x302, 0xC9,
    0x101, 0xC9, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x200, 0x2A1, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0xC9, 2,
    0x301,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
s32 D_800A598C[] = {
    2, 4, 8,
};
AnimFrame D_800A5998[] = {
    { 50, 4 }, { 51, 4 }, { 52, 4 }, { 53, 4 },
    { 54, 4 }, { 55, 4 }, { 255, 0x3E7 },
};
AnimFrame D_800A59B4[] = {
    { 0x12C, 4 }, { 56, 4 }, { 57, 4 }, { 58, 4 },
    { 59, 4 }, { 60, 4 }, { 61, 4 }, { 62, 4 },
    { 63, 4 }, { 64, 4 }, { 65, 4 }, { 66, 4 },
    { 67, 4 }, { 255, 0x3E7 },
};
AnimFrame *D_800A59EC[] = {
    D_800A5998, D_800A59B4,
};
Battle D_800A59F4 = { 119, 24, 0x60080000 };
Battle D_800A5A00 = { 119, 24, 0x60080000 };
Battle D_800A5A0C = { 119, 24, 0x60080000 };
Battle D_800A5A18 = { 168, 24, 0x60080000 };
Battle D_800A5A24 = { 168, 24, 0x60080000 };
Battle D_800A5A30 = { 168, 24, 0x60080000 };
Battle D_800A5A3C = { 111, 24, 0x60080000 };
Battle D_800A5A48 = { 111, 24, 0x60080000 };
BattleList D_800A5A54 = {
    4,
    { &D_800A59F4, &D_800A5A00, &D_800A5A0C, &D_800A5A18,
      &D_800A5A24, &D_800A5A30, &D_800A5A3C, &D_800A5A48 },
};
Battle D_800A5A78 = { 0, 24, 0x60080000 };
Battle D_800A5A84 = { 0, 24, 0x60080000 };
Battle D_800A5A90 = { 0, 24, 0x60080000 };
Battle D_800A5A9C = { 0, 24, 0x60080000 };
Battle D_800A5AA8 = { 0, 24, 0x60080000 };
Battle D_800A5AB4 = { 0, 24, 0x60080000 };
Battle D_800A5AC0 = { 0, 24, 0x60080000 };
Battle D_800A5ACC = { 0, 24, 0x60080000 };
BattleList D_800A5AD8 = {
    0,
    { &D_800A5A78, &D_800A5A84, &D_800A5A90, &D_800A5A9C,
      &D_800A5AA8, &D_800A5AB4, &D_800A5AC0, &D_800A5ACC },
};
Battle D_800A5AFC = { 0, 0, 0x60040000 };
Battle D_800A5B08 = { 0, 0, 0x60040000 };
Battle D_800A5B14 = { 0, 0, 0x60040000 };
Battle D_800A5B20 = { 0, 0, 0x60040000 };
Battle D_800A5B2C = { 0, 0, 0x60040000 };
Battle D_800A5B38 = { 0, 0, 0x60040000 };
Battle D_800A5B44 = { 0, 0, 0x60040000 };
Battle D_800A5B50 = { 0, 0, 0x60040000 };
BattleList D_800A5B5C = {
    0,
    { &D_800A5AFC, &D_800A5B08, &D_800A5B14, &D_800A5B20,
      &D_800A5B2C, &D_800A5B38, &D_800A5B44, &D_800A5B50 },
};
Battle D_800A5B80 = { 20, 24, 0x608C0000 };
Battle D_800A5B8C = { 0, 0, 0x60040000 };
Battle D_800A5B98 = { 0, 0, 0x60040000 };
Battle D_800A5BA4 = { 0, 0, 0x60040000 };
Battle D_800A5BB0 = { 0, 0, 0x60040000 };
Battle D_800A5BBC = { 168, 24, 0x60080000 };
Battle D_800A5BC8 = { 0, 0, 0x60040000 };
Battle D_800A5BD4 = { 0, 0, 0x60040000 };
BattleList D_800A5BE0 = {
    0,
    { &D_800A5B80, &D_800A5B8C, &D_800A5B98, &D_800A5BA4,
      &D_800A5BB0, &D_800A5BBC, &D_800A5BC8, &D_800A5BD4 },
};
FieldBattles stageBattles[] = {
    { 88, 0, 0, { &D_800A5A54, &D_800A5AD8, &D_800A5B5C, &D_800A5BE0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x158, 0x100, 0x58, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1A6, 0x158, 0x198, 0x58, 0x140, 0x1FB },
};
FieldTalk D_800A5CA0[] = {
    { NULL, NULL, 0x208 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB8[] = {
    { NULL, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD0[] = {
    { NULL, NULL, 0x207 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE8[] = {
    { NULL, NULL, 0x206 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D00[] = {
    { NULL, NULL, 0x206 },
    { NULL, NULL, 0 },
};
u16 D_800A5D18[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5D20[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D28[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5D30[] = { 0x4040, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5D3C[] = { 0x4040, 1, 0x7019, 1, 0xFFFF };
FieldActorEntry D_800A5D48 = { D_800A5D18, D_800A5CA0, 0x9D, 4, 464, 648, 7 };
FieldActorEntry D_800A5D5C = { D_800A5D20, D_800A5CB8, 0xC9, 5, 464, 648, 7 };
FieldActorEntry D_800A5D70 = { D_800A5D28, D_800A5CD0, 0xC9, 5, 464, 648, 7 };
FieldActorEntry D_800A5D84 = { D_800A5D30, D_800A5CE8, 0xC9, 5, 512, 673, 7 };
FieldActorEntry D_800A5D98 = { D_800A5D3C, D_800A5D00, 0xC9, 5, 464, 648, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5D48,
    &D_800A5D5C,
    &D_800A5D70,
    &D_800A5D84,
    &D_800A5D98,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26A, 0x70, 0x2EC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26C, 0x448, 0x288, 1, 0, 0, 0 },
    { { { 0x40AA, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0x40AB, 0 }, { 0xFFFF, 0 } }, 8, 0x2329, 0, 0, 0, 0, 0, 0 },
    { { { 0x40AC, 0 }, { 0xFFFF, 0 } }, 8, 0x232A, 0, 0, 0, 0, 0, 0 },
    { { { 0x40AD, 0 }, { 0xFFFF, 0 } }, 8, 0x232B, 0, 0, 0, 0, 0, 0 },
    { { { 0x40AE, 0 }, { 0xFFFF, 0 } }, 8, 0x232C, 0, 0, 0, 0, 0, 0 },
    { { { 0x40AF, 0 }, { 0xFFFF, 0 } }, 8, 0x232D, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B0, 0 }, { 0xFFFF, 0 } }, 8, 0x232E, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B1, 0 }, { 0xFFFF, 0 } }, 8, 0x232F, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B2, 0 }, { 0xFFFF, 0 } }, 8, 0x2330, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B3, 0 }, { 0xFFFF, 0 } }, 8, 0x2331, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B4, 0 }, { 0xFFFF, 0 } }, 8, 0x2332, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B5, 0 }, { 0xFFFF, 0 } }, 8, 0x2333, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B6, 0 }, { 0xFFFF, 0 } }, 8, 0x2334, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B7, 0 }, { 0xFFFF, 0 } }, 8, 0x2335, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B8, 0 }, { 0xFFFF, 0 } }, 8, 0x2336, 0, 0, 0, 0, 0, 0 },
    { { { 0x40B9, 0 }, { 0xFFFF, 0 } }, 8, 0x2337, 0, 0, 0, 0, 0, 0 },
    { { { 0x8011, 1 }, { 0x403F, 0 } }, 8, 0x320, 0, 0, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2338, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 800, D_800A5850, EVENT_TEXT(0xC), NULL, func_800A53C8 },
    { 801, D_800A58F8, EVENT_TEXT(0xD), NULL, func_800A5414 },
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
    { 9016, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
