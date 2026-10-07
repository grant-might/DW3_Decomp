#include "common.h"
#include "stage.h"
extern s16 D_800A5938[];
#if VERSION_US
#define TIMER_SHEET 0x6E6
#elif VERSION_EU
#define TIMER_SHEET 0x6F6
#endif
extern AnimFrame D_800A58D8[];
extern AnimFrame D_800A58E4[];
extern AnimFrame D_800A5910[];
extern AnimFrame *D_800A592C[];

#include "common/step_tile_animation_u8.inc.c"

/* Shows the first record animated while running; when done, both */
void func_800A4DC4(StageTilePair *task) {
    StageTile *tile;
    StageTile *rec;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = FIELDSTG_state.objects; rec->unk2 != 0; rec++) {
            switch (rec->anim) {
            case 1:
                task->anims[0].anim.index = 0;
                task->anims[0].anim.timer = (u8)D_800A592C[0]->duration;
                task->anims[0].tile = rec;
                break;
            case 2:
                task->anims[1].anim.index = 0;
                task->anims[1].anim.timer = (u8)D_800A592C[2]->duration;
                task->anims[1].tile = rec;
                break;
            }
        }
        task->playing = 0;
        if (task->done == 0) {
            task->nextState(task);
        } else {
            task->anims[0].anim.index = 0;
            task->anims[0].anim.timer = (u8)D_800A58E4[0].duration;
            task->setState(task, TASK_DONE);
        }
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                tile->frame = 0x46;
                tile->clutRow = stepTileAnimation(&task->anims[0], D_800A58D8, 0, 0);
                break;
            case 1:
                tile->visible = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
        for (i = 0; i < 2; i++) {
            tile = task->anims[i].tile;
            switch (i) {
            case 0:
                tile->visible = 1;
                if (task->playing) {
                    frame = stepTileAnimation(&task->anims[0], D_800A58E4, 1, 0);
                    if (frame == 0xFF) {
                        tile->frame = 0x50;
                        task->playing = 0;
                    } else {
                        tile->frame = frame;
                    }
                } else {
                    tile->frame = 0x50;
                }
                tile->clutRow = 0;
                break;
            case 1:
                tile->visible = 1;
                tile->frame = 0x51;
                tile->clutRow = stepTileAnimation(&task->anims[1], D_800A5910, 0, 0);
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Plays the first record's one-shot animation when the event of map object 0x35B happens */
void func_800A5044(StageTilePair *task, s32 id) {
    if (task != NULL && id == 0x35B) {
        task->playing = 1;
        task->anims[0].anim.index = 0;
        task->anims[0].anim.timer = (u8)D_800A58E4[0].duration;
        task->setState(task, TASK_DONE);
    }
}

void *func_800A5094(s32 arg) {
    return createTaskWithId(func_800A4DC4, 0x68, 0, arg);
}

/* Creates the tile pair object, started in TASK_DONE */
void *func_800A50C4(void) {
    StageTilePair *task = createTask(func_800A4DC4, sizeof(StageTilePair), 0);

    task->done = 1;
    return task;
}

/* Draws the timer: its frame and the three digits of GAME.countdown */
void func_800A50F8(StageTask *task) {
    SpriteDrawer drawer;
    Vec2 scroll;
    s32 i;
    Layer *layer = GFX.funcs.getLayer(0x1002);

    layer->getScroll(layer, &scroll);
    initSpriteDrawer(&drawer);
    drawer.setLayer(layer, 0);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.draw(FILE_CACHE.getEntry(TIMER_SHEET << 16), 1, scroll.x + 0xE0, scroll.y + 0x16);
    scroll.y += 0x19;
    for (i = 0; i < 3; i++) {
        drawer.draw(FILE_CACHE.getEntry(TIMER_SHEET << 16), GAME.countdown[i] + 2, scroll.x + D_800A5938[i], scroll.y);
    }
}

/* The timer: counts GAME.countdown down while nothing stops it, then starts event 0x5E1 */
void func_800A5240(StageTask *task, void **children) {
    u8 *countdown;

    switch (task->state) {
    case TASK_RUN:
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x43), 0) || FIELDSTG_state.busy != 0 || FIELDSTG_state.battleStarting != 0 ||
            FIELDSTG_state.bannerShown != 0 || FIELDSTG_state.innOpen != 0 || FIELDSTG_state.acting != 0) {
            break;
        }
        func_800A50F8(task);
        countdown = GAME.countdown;
        if (countdown[0] != 0 || countdown[1] != 0 || countdown[2] != 0) {
            countdown[3] -= GFX.funcs.getFrameTime();
            if (countdown[3] > 60) {
                countdown[2]--;
                countdown[3] += 60;
                SOUND.playSound(SOUND_COUNT);
            }
            COUNTDOWN_BORROW(countdown);
            break;
        }
        children[0] = FIELDSTG_startEvent(0x5E1);
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5410(void) {
    return createTask(func_800A5240, 0x54, 0x4);
}

/* Creates the timer, one of two objects by flag 0x4063, and the event object of story progress 0x20 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A5410();
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x63), 0)) {
            children[1] = func_800A5094(0x344);
        } else {
            children[1] = func_800A50C4();
        }
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x43), 0) && GAME.progress == 0x20) {
            children[2] = FIELDSTG_startEvent(0x33E);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"

void func_800A5574(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x43), 1);
}

void func_800A55A0(void) {
    FLAGS_00.applyAction(FLAG(0x1C, 5), 1);
    FLAGS_00.applyAction(FLAG(0x40, 0x63), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6E6
#define STAGE_FILE_8 0x711
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6F6
#define STAGE_FILE_8 0x721
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE_8;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 4;
    FIELDSTG_state.start = (Vec2){0x4B200, 0x3AA00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0xD;
    FIELDSTG_state.music = MUSIC(0xD, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script830[] = {
    0x100, 2, 0x45F, 0x37D,
    0x101, 2, 1, 1,
    0x300, 0x78,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x31A8\n");
#endif
s16 script840[] = {
    0x102, 2, 0x1C1, 0x387, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x377, 2,
    0x300, 0x1E,
    0x101, 0x344, 0x35B, 2,
    0x300, 0x78,
    0x101, 2, 1, 5,
    0x300, 0x3C,
    0x101, 2, 1, 1,
    0x101, 0x32D, 0x37F, 2,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x1A0, 0x379, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x31A8\n");
#endif
s16 script1505[] = {
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 0,
    0x301,
    0x101, 2, 1, 0,
    0x300, 0x1E,
    0x304, 0x26D, 1, 1, 1,
    0,
};
AnimFrame D_800A58D8[] = {
    { 0, 8 }, { 1, 8 }, { 255, 0 },
};
AnimFrame D_800A58E4[] = {
    { 71, 4 }, { 72, 4 }, { 73, 4 }, { 74, 4 },
    { 75, 4 }, { 76, 4 }, { 77, 4 }, { 78, 4 },
    { 79, 4 }, { 80, 4 }, { 255, 0 },
};
AnimFrame D_800A5910[] = {
    { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 6 }, { 255, 0 },
};
AnimFrame *D_800A592C[] = {
    D_800A58D8, D_800A58E4, D_800A5910,
};
s16 D_800A5938[] = {
    226, 253, 0x118, 0,
};
Battle area0Battle0 = { 124, 16, MUSIC(2, 0) };
Battle area0Battle1 = { 124, 16, MUSIC(2, 0) };
Battle area0Battle2 = { 124, 16, MUSIC(2, 0) };
Battle area0Battle3 = { 125, 16, MUSIC(2, 0) };
Battle area0Battle4 = { 125, 16, MUSIC(2, 0) };
Battle area0Battle5 = { 125, 16, MUSIC(2, 0) };
Battle area0Battle6 = { 123, 16, MUSIC(2, 0) };
Battle area0Battle7 = { 123, 16, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle7 = { 0, 0, MUSIC(1, 0) };
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
Battle area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 90, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x19A, 0x30, 0x9A, 0x140, 0x1F9 },
    { 0x140, 0x100, 0x140, 0x1A2, 0, 0xA2, 0x150, 0x1F9 },
    { 0x140, 0x100, 0x152, 0x1B9, 0x48, 0xB9, 0x160, 0x1F9 },
    { 0x140, 0x100, 0x158, 0x1B9, 0x60, 0xB9, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x15E, 0x1B9, 0x78, 0xB9, 0x140, 0x1F8 },
    { 0x140, 0x100, 0x164, 0x1B9, 0x90, 0xB9, 0x150, 0x1F8 },
    { 0x140, 0x100, 0x146, 0x1BA, 0x18, 0xBA, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x14C, 0x1BA, 0x30, 0xBA, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x16A, 0x1C0, 0xA8, 0xC0, 0x140, 0x1F7 },
    { 0x140, 0x100, 0x170, 0x1C0, 0xC0, 0xC0, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x176, 0x1C0, 0xD8, 0xC0, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x1C2, 0, 0xC2, 0x170, 0x1F7 },
};
u16 actor0Talk0Actions[] = { FLAG(2, 0x39), 1, ITEM(2, 0xD5), 1, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(2, 0x3A), 1, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(2, 0x3B), 1, ITEM(1, 0x2B), 1, CODES_END };
u16 actor3Talk0Actions[] = { FLAG(2, 0x3C), 1, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(2, 0x3D), 1, CODES_END };
u16 actor5Talk0Actions[] = { FLAG(2, 0x3E), 1, ITEM(4, 0xA5), 1, CODES_END };
u16 actor6Talk0Actions[] = { FLAG(2, 0x3F), 1, ITEM(2, 0xAE), 1, CODES_END };
u16 actor7Talk0Actions[] = { FLAG(2, 0x40), 1, CODES_END };
u16 actor8Talk0Actions[] = { FLAG(2, 0x41), 1, ITEM(1, 0x2C), 1, CODES_END };
u16 actor9Talk0Actions[] = { FLAG(2, 0x42), 1, ITEM(2, 0x64), 1, CODES_END };
u16 actor10Talk0Actions[] = { FLAG(2, 0x43), 1, ITEM(2, 0x97), 1, CODES_END };
u16 actor11Talk0Actions[] = { FLAG(2, 0x44), 1, ITEM(5, 0x122), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x201 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x17E },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, actor3Talk0Actions, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, actor4Talk0Actions, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, actor5Talk0Actions, 0x1F2 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, actor6Talk0Actions, 0x1FF },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, actor7Talk0Actions, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, actor8Talk0Actions, 0x17D },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, actor9Talk0Actions, 0x1E9 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, actor10Talk0Actions, 0x1F1 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, actor11Talk0Actions, 0x18F },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 0x39), 0, CODES_END };
u16 actor1Conditions[] = { FLAG(2, 0x3A), 0, CODES_END };
u16 actor2Conditions[] = { FLAG(2, 0x3B), 0, CODES_END };
u16 actor3Conditions[] = { FLAG(2, 0x3C), 0, CODES_END };
u16 actor4Conditions[] = { FLAG(2, 0x3D), 0, CODES_END };
u16 actor5Conditions[] = { FLAG(2, 0x3E), 0, CODES_END };
u16 actor6Conditions[] = { FLAG(2, 0x3F), 0, CODES_END };
u16 actor7Conditions[] = { FLAG(2, 0x40), 0, CODES_END };
u16 actor8Conditions[] = { FLAG(2, 0x41), 0, CODES_END };
u16 actor9Conditions[] = { FLAG(2, 0x42), 0, CODES_END };
u16 actor10Conditions[] = { FLAG(2, 0x43), 0, CODES_END };
u16 actor11Conditions[] = { FLAG(2, 0x44), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 961, 678, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x4D, 5, 737, 855, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x4E, 6, 640, 903, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x4F, 7, 545, 950, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x50, 8, 768, 998, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x51, 9, 400, 558, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x52, 0xA, 784, 366, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x53, 0xB, 432, 478, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x54, 0xC, 672, 1047, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x55, 0xD, 335, 527, 1 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x56, 0xE, 160, 823, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x57, 0xF, 205, 526, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 153, 151, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 166, 158, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 185, 167, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 198, 174, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 217, 183, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 230, 190, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 249, 200, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 5, 4, 0, 262, 206, 0, 0 },
    { 1, 2, 0x64, 6, 0x51, 0, 0, 0, 0, 0, 414, 834, 0, 0 },
    { 1, 1, 0x64, 6, 0x46, 0, 0, 0, 0, 0, 414, 834, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 5, 6, 0, 1117, 845, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x36, 6, 0, 1121, 849, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 226, 115, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 239, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 258, 131, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 271, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 289, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 303, 154, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 322, 163, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 4, 0, 335, 170, 0, 0 },
    { 1, 0x64, 0x7A, 6, 0, 0, 0, 0, 0, 0, 142, 67, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2DB, 0x208, 0xCC, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2DB, 0x168, 0x11C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2DB, 0x128, 0x19C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2DB, 0x128, 0x35C, 7, 0, 0, 0 },
    { { { FLAG(0x1C, 0xA), 1 }, { CODES_END, 0 } }, 1, 0x2DC, 0x2B4, 0x198, 3, 0x64, 0, 0 },
    { { { PROGRESS(0x20), 1 }, { FLAG(0x40, 0x63), 0 } }, 8, 0x348, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 830, script830, EVENT_TEXT(0x1A), NULL, func_800A5574 },
    { 840, script840, EVENT_TEXT(0x1B), NULL, func_800A55A0 },
    { 1505, script1505, EVENT_TEXT(0x25), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
