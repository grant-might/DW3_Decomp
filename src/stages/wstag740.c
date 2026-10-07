#include "common.h"
#include "stage.h"
extern s32 D_800A598C[];
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
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
                SOUND.playSound(SOUND_SWITCH02);
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
                    SOUND.playSound(SOUND_COMEX113);
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
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x3F), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x40), 0)) {
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
    drawer.draw(FILE_CACHE.getEntry(FIELDSTG_state.sheetEntry), sprite->frame, task->x, task->y);
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
    FLAGS_00.applyAction(FLAG(0x40, 0x3F), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Sets flags 0x8488 and 0x4040 */
void func_800A5414(void) {
    FLAGS_00.applyAction(ITEM(2, 0x88), 1);
    FLAGS_00.applyAction(FLAG(0x40, 0x40), 1);
}

void func_800A5460(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAA), 1);
}

void func_800A548C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAB), 1);
}

void func_800A54B8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAC), 1);
}

void func_800A54E4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAD), 1);
}

void func_800A5510(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAE), 1);
}

void func_800A553C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xAF), 1);
}

void func_800A5568(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB0), 1);
}

void func_800A5594(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB1), 1);
}

void func_800A55C0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB2), 1);
}

void func_800A55EC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB3), 1);
}

void func_800A5618(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB4), 1);
}

void func_800A5644(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB5), 1);
}

void func_800A5670(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB6), 1);
}

void func_800A569C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB7), 1);
}

void func_800A56C8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB8), 1);
}

void func_800A56F4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB9), 1);
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
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x12200, 0x2F400};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x19;
    FIELDSTG_state.music = MUSIC(0x19, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script800[] = {
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
s16 script801[] = {
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
Battle area0Battle0 = { 119, 24, MUSIC(2, 0) };
Battle area0Battle1 = { 119, 24, MUSIC(2, 0) };
Battle area0Battle2 = { 119, 24, MUSIC(2, 0) };
Battle area0Battle3 = { 168, 24, MUSIC(2, 0) };
Battle area0Battle4 = { 168, 24, MUSIC(2, 0) };
Battle area0Battle5 = { 168, 24, MUSIC(2, 0) };
Battle area0Battle6 = { 111, 24, MUSIC(2, 0) };
Battle area0Battle7 = { 111, 24, MUSIC(2, 0) };
BattleList area0Battles = {
    4,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle1 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle2 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle3 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle4 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle5 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle6 = { 0, 24, MUSIC(2, 0) };
Battle area1Battle7 = { 0, 24, MUSIC(2, 0) };
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
Battle area3Battle0 = { 20, 24, MUSIC(0x23, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 168, 24, MUSIC(2, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 88, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
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
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x208 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x207 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x206 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x206 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Conditions[] = { FLAG(0x40, 0x40), 0, SPECIAL(0x19), 1, CODES_END };
u16 actor4Conditions[] = { FLAG(0x40, 0x40), 1, SPECIAL(0x19), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x9D, 4, 464, 648, 7 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0xC9, 5, 464, 648, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0xC9, 5, 464, 648, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0xC9, 5, 512, 673, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0xC9, 5, 464, 648, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
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
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26A, 0x70, 0x2EC, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26C, 0x448, 0x288, 1, 0, 0, 0 },
    { { { FLAG(0x40, 0xAA), 0 }, { CODES_END, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xAB), 0 }, { CODES_END, 0 } }, 8, 0x2329, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xAC), 0 }, { CODES_END, 0 } }, 8, 0x232A, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xAD), 0 }, { CODES_END, 0 } }, 8, 0x232B, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xAE), 0 }, { CODES_END, 0 } }, 8, 0x232C, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xAF), 0 }, { CODES_END, 0 } }, 8, 0x232D, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB0), 0 }, { CODES_END, 0 } }, 8, 0x232E, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB1), 0 }, { CODES_END, 0 } }, 8, 0x232F, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB2), 0 }, { CODES_END, 0 } }, 8, 0x2330, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB3), 0 }, { CODES_END, 0 } }, 8, 0x2331, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB4), 0 }, { CODES_END, 0 } }, 8, 0x2332, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB5), 0 }, { CODES_END, 0 } }, 8, 0x2333, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB6), 0 }, { CODES_END, 0 } }, 8, 0x2334, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB7), 0 }, { CODES_END, 0 } }, 8, 0x2335, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB8), 0 }, { CODES_END, 0 } }, 8, 0x2336, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0x40, 0xB9), 0 }, { CODES_END, 0 } }, 8, 0x2337, 0, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 0x11), 1 }, { FLAG(0x40, 0x3F), 0 } }, 8, 0x320, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(0, 0xF), 0 }, { CODES_END, 0 } }, 8, 0x2338, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 800, script800, EVENT_TEXT(0xC), NULL, func_800A53C8 },
    { 801, script801, EVENT_TEXT(0xD), NULL, func_800A5414 },
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
    { 9016, NULL, 0, FIELDSTG_startEventBattle5, NULL },
    { -1, NULL, 0, NULL, NULL },
};
