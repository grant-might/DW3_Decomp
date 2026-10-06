#include "common.h"
#include "stage.h"
extern s16 D_800A5938[];
#if VERSION_US
#define TIMER_SHEET 0x6E6
#elif VERSION_EU
#define TIMER_SHEET 0x6F6
#endif
void func_800A5240();
extern AnimFrame D_800A58D8[];
extern AnimFrame D_800A58E4[];
extern AnimFrame D_800A5910[];
extern AnimFrame *D_800A592C[];
void func_800A4DC4();
void *func_800A50C4(void);

/* func_800A4F74 of WSTAG310 with durations read as bytes */
s32 stepTileAnimation(StageTileAnim *obj, AnimFrame *frames, s32 once, s32 depth) {
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
        obj->anim.timer += (u8)frame->duration;
        if (once) {
            if (frame->frame == 0xFF) {
                return 0xFF;
            }
        } else if (frame->frame == 0xFF) {
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += (u8)frame->duration;
        }
        stepTileAnimation(obj, frames, once, depth + 1);
    }
    return frame->frame;
}

/* Shows the first record animated while running; when done, both */
void func_800A4DC4(StageTilePair *task) {
    StageTile *tile;
    StageTile *rec;
    s32 i;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (rec = D_800990B4.objects; rec->unk2 != 0; rec++) {
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
        if (FLAGS_00.checkCondition(0x4043, 0) || D_800990B4.busy != 0 || D_800990B4.battleStarting != 0 ||
            D_800990B4.bannerShown != 0 || D_800990B4.innOpen != 0 || D_800990B4.acting != 0) {
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
        if (FLAGS_00.checkCondition(0x4063, 0)) {
            children[1] = func_800A5094(0x344);
        } else {
            children[1] = func_800A50C4();
        }
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4043, 0) && GAME.progress == 0x20) {
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
    FLAGS_00.applyAction(0x4043, 1);
}

void func_800A55A0(void) {
    FLAGS_00.applyAction(0x1C05, 1);
    FLAGS_00.applyAction(0x4063, 1);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 4;
    D_800990B4.start = (Vec2){0x4B200, 0x3AA00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xD;
    D_800990B4.music = 0x60340000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5940;
extern Battle D_800A594C;
extern Battle D_800A5958;
extern Battle D_800A5964;
extern Battle D_800A5970;
extern Battle D_800A597C;
extern Battle D_800A5988;
extern Battle D_800A5994;
extern Battle D_800A59C4;
extern Battle D_800A59D0;
extern Battle D_800A59DC;
extern Battle D_800A59E8;
extern Battle D_800A59F4;
extern Battle D_800A5A00;
extern Battle D_800A5A0C;
extern Battle D_800A5A18;
extern Battle D_800A5A48;
extern Battle D_800A5A54;
extern Battle D_800A5A60;
extern Battle D_800A5A6C;
extern Battle D_800A5A78;
extern Battle D_800A5A84;
extern Battle D_800A5A90;
extern Battle D_800A5A9C;
extern Battle D_800A5ACC;
extern Battle D_800A5AD8;
extern Battle D_800A5AE4;
extern Battle D_800A5AF0;
extern Battle D_800A5AFC;
extern Battle D_800A5B08;
extern Battle D_800A5B14;
extern Battle D_800A5B20;
extern BattleList D_800A59A0;
extern BattleList D_800A5A24;
extern BattleList D_800A5AA8;
extern BattleList D_800A5B2C;
extern u16 D_800A5C8C[];
extern u16 D_800A5C98[];
extern u16 D_800A5CA0[];
extern u16 D_800A5CAC[];
extern u16 D_800A5CB4[];
extern u16 D_800A5CBC[];
extern u16 D_800A5CC8[];
extern u16 D_800A5CD4[];
extern u16 D_800A5CDC[];
extern u16 D_800A5CE8[];
extern u16 D_800A5CF4[];
extern u16 D_800A5D00[];
extern u16 D_800A5E2C[];
extern FieldTalk D_800A5D0C[];
extern u16 D_800A5E34[];
extern FieldTalk D_800A5D24[];
extern u16 D_800A5E3C[];
extern FieldTalk D_800A5D3C[];
extern u16 D_800A5E44[];
extern FieldTalk D_800A5D54[];
extern u16 D_800A5E4C[];
extern FieldTalk D_800A5D6C[];
extern u16 D_800A5E54[];
extern FieldTalk D_800A5D84[];
extern u16 D_800A5E5C[];
extern FieldTalk D_800A5D9C[];
extern u16 D_800A5E64[];
extern FieldTalk D_800A5DB4[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A5DCC[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A5DE4[];
extern u16 D_800A5E7C[];
extern FieldTalk D_800A5DFC[];
extern u16 D_800A5E84[];
extern FieldTalk D_800A5E14[];
extern FieldActorEntry D_800A5E8C;
extern FieldActorEntry D_800A5EA0;
extern FieldActorEntry D_800A5EB4;
extern FieldActorEntry D_800A5EC8;
extern FieldActorEntry D_800A5EDC;
extern FieldActorEntry D_800A5EF0;
extern FieldActorEntry D_800A5F04;
extern FieldActorEntry D_800A5F18;
extern FieldActorEntry D_800A5F2C;
extern FieldActorEntry D_800A5F40;
extern FieldActorEntry D_800A5F54;
extern FieldActorEntry D_800A5F68;
extern s16 D_800A5700[];
extern s16 D_800A5780[];
extern s16 D_800A5884[];

s16 D_800A5700[] = {
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
s16 D_800A5780[] = {
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
s16 D_800A5884[] = {
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
Battle D_800A5940 = { 124, 16, 0x60080000 };
Battle D_800A594C = { 124, 16, 0x60080000 };
Battle D_800A5958 = { 124, 16, 0x60080000 };
Battle D_800A5964 = { 125, 16, 0x60080000 };
Battle D_800A5970 = { 125, 16, 0x60080000 };
Battle D_800A597C = { 125, 16, 0x60080000 };
Battle D_800A5988 = { 123, 16, 0x60080000 };
Battle D_800A5994 = { 123, 16, 0x60080000 };
BattleList D_800A59A0 = {
    3,
    { &D_800A5940, &D_800A594C, &D_800A5958, &D_800A5964,
      &D_800A5970, &D_800A597C, &D_800A5988, &D_800A5994 },
};
Battle D_800A59C4 = { 0, 0, 0x60040000 };
Battle D_800A59D0 = { 0, 0, 0x60040000 };
Battle D_800A59DC = { 0, 0, 0x60040000 };
Battle D_800A59E8 = { 0, 0, 0x60040000 };
Battle D_800A59F4 = { 0, 0, 0x60040000 };
Battle D_800A5A00 = { 0, 0, 0x60040000 };
Battle D_800A5A0C = { 0, 0, 0x60040000 };
Battle D_800A5A18 = { 0, 0, 0x60040000 };
BattleList D_800A5A24 = {
    0,
    { &D_800A59C4, &D_800A59D0, &D_800A59DC, &D_800A59E8,
      &D_800A59F4, &D_800A5A00, &D_800A5A0C, &D_800A5A18 },
};
Battle D_800A5A48 = { 0, 0, 0x60040000 };
Battle D_800A5A54 = { 0, 0, 0x60040000 };
Battle D_800A5A60 = { 0, 0, 0x60040000 };
Battle D_800A5A6C = { 0, 0, 0x60040000 };
Battle D_800A5A78 = { 0, 0, 0x60040000 };
Battle D_800A5A84 = { 0, 0, 0x60040000 };
Battle D_800A5A90 = { 0, 0, 0x60040000 };
Battle D_800A5A9C = { 0, 0, 0x60040000 };
BattleList D_800A5AA8 = {
    0,
    { &D_800A5A48, &D_800A5A54, &D_800A5A60, &D_800A5A6C,
      &D_800A5A78, &D_800A5A84, &D_800A5A90, &D_800A5A9C },
};
Battle D_800A5ACC = { 0, 0, 0x60040000 };
Battle D_800A5AD8 = { 0, 0, 0x60040000 };
Battle D_800A5AE4 = { 0, 0, 0x60040000 };
Battle D_800A5AF0 = { 0, 0, 0x60040000 };
Battle D_800A5AFC = { 0, 0, 0x60040000 };
Battle D_800A5B08 = { 0, 0, 0x60040000 };
Battle D_800A5B14 = { 0, 0, 0x60040000 };
Battle D_800A5B20 = { 0, 0, 0x60040000 };
BattleList D_800A5B2C = {
    0,
    { &D_800A5ACC, &D_800A5AD8, &D_800A5AE4, &D_800A5AF0,
      &D_800A5AFC, &D_800A5B08, &D_800A5B14, &D_800A5B20 },
};
FieldBattles stageBattles[] = {
    { 90, 0, 0, { &D_800A59A0, &D_800A5A24, &D_800A5AA8, &D_800A5B2C } },
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
u16 D_800A5C8C[] = { 0x239, 1, 0x84D5, 1, 0xFFFF };
u16 D_800A5C98[] = { 0x23A, 1, 0xFFFF };
u16 D_800A5CA0[] = { 0x23B, 1, 0x822B, 1, 0xFFFF };
u16 D_800A5CAC[] = { 0x23C, 1, 0xFFFF };
u16 D_800A5CB4[] = { 0x23D, 1, 0xFFFF };
u16 D_800A5CBC[] = { 0x23E, 1, 0x88A5, 1, 0xFFFF };
u16 D_800A5CC8[] = { 0x23F, 1, 0x84AE, 1, 0xFFFF };
u16 D_800A5CD4[] = { 0x240, 1, 0xFFFF };
u16 D_800A5CDC[] = { 0x241, 1, 0x822C, 1, 0xFFFF };
u16 D_800A5CE8[] = { 0x242, 1, 0x8464, 1, 0xFFFF };
u16 D_800A5CF4[] = { 0x243, 1, 0x8497, 1, 0xFFFF };
u16 D_800A5D00[] = { 0x244, 1, 0x8B22, 1, 0xFFFF };
FieldTalk D_800A5D0C[] = {
    { NULL, D_800A5C8C, 0x201 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D24[] = {
    { NULL, D_800A5C98, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D3C[] = {
    { NULL, D_800A5CA0, 0x17E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D54[] = {
    { NULL, D_800A5CAC, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D6C[] = {
    { NULL, D_800A5CB4, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D84[] = {
    { NULL, D_800A5CBC, 0x1F2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D9C[] = {
    { NULL, D_800A5CC8, 0x1FF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DB4[] = {
    { NULL, D_800A5CD4, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DCC[] = {
    { NULL, D_800A5CDC, 0x17D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DE4[] = {
    { NULL, D_800A5CE8, 0x1E9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DFC[] = {
    { NULL, D_800A5CF4, 0x1F1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E14[] = {
    { NULL, D_800A5D00, 0x18F },
    { NULL, NULL, 0 },
};
u16 D_800A5E2C[] = { 0x239, 0, 0xFFFF };
u16 D_800A5E34[] = { 0x23A, 0, 0xFFFF };
u16 D_800A5E3C[] = { 0x23B, 0, 0xFFFF };
u16 D_800A5E44[] = { 0x23C, 0, 0xFFFF };
u16 D_800A5E4C[] = { 0x23D, 0, 0xFFFF };
u16 D_800A5E54[] = { 0x23E, 0, 0xFFFF };
u16 D_800A5E5C[] = { 0x23F, 0, 0xFFFF };
u16 D_800A5E64[] = { 0x240, 0, 0xFFFF };
u16 D_800A5E6C[] = { 0x241, 0, 0xFFFF };
u16 D_800A5E74[] = { 0x242, 0, 0xFFFF };
u16 D_800A5E7C[] = { 0x243, 0, 0xFFFF };
u16 D_800A5E84[] = { 0x244, 0, 0xFFFF };
FieldActorEntry D_800A5E8C = { D_800A5E2C, D_800A5D0C, 0x21, 4, 961, 678, 1 };
FieldActorEntry D_800A5EA0 = { D_800A5E34, D_800A5D24, 0x4D, 5, 737, 855, 1 };
FieldActorEntry D_800A5EB4 = { D_800A5E3C, D_800A5D3C, 0x4E, 6, 640, 903, 1 };
FieldActorEntry D_800A5EC8 = { D_800A5E44, D_800A5D54, 0x4F, 7, 545, 950, 1 };
FieldActorEntry D_800A5EDC = { D_800A5E4C, D_800A5D6C, 0x50, 8, 768, 998, 1 };
FieldActorEntry D_800A5EF0 = { D_800A5E54, D_800A5D84, 0x51, 9, 400, 558, 1 };
FieldActorEntry D_800A5F04 = { D_800A5E5C, D_800A5D9C, 0x52, 0xA, 784, 366, 1 };
FieldActorEntry D_800A5F18 = { D_800A5E64, D_800A5DB4, 0x53, 0xB, 432, 478, 1 };
FieldActorEntry D_800A5F2C = { D_800A5E6C, D_800A5DCC, 0x54, 0xC, 672, 1047, 1 };
FieldActorEntry D_800A5F40 = { D_800A5E74, D_800A5DE4, 0x55, 0xD, 335, 527, 1 };
FieldActorEntry D_800A5F54 = { D_800A5E7C, D_800A5DFC, 0x56, 0xE, 160, 823, 1 };
FieldActorEntry D_800A5F68 = { D_800A5E84, D_800A5E14, 0x57, 0xF, 205, 526, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5E8C,
    &D_800A5EA0,
    &D_800A5EB4,
    &D_800A5EC8,
    &D_800A5EDC,
    &D_800A5EF0,
    &D_800A5F04,
    &D_800A5F18,
    &D_800A5F2C,
    &D_800A5F40,
    &D_800A5F54,
    &D_800A5F68,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DB, 0x208, 0xCC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DB, 0x168, 0x11C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DB, 0x128, 0x19C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2DB, 0x128, 0x35C, 7, 0, 0, 0 },
    { { { 0x1C0A, 1 }, { 0xFFFF, 0 } }, 1, 0x2DC, 0x2B4, 0x198, 3, 0x64, 0, 0 },
    { { { 0x6020, 1 }, { 0x4063, 0 } }, 8, 0x348, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 830, D_800A5700, EVENT_TEXT(0x1A), NULL, func_800A5574 },
    { 840, D_800A5780, EVENT_TEXT(0x1B), NULL, func_800A55A0 },
    { 1505, D_800A5884, EVENT_TEXT(0x25), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
