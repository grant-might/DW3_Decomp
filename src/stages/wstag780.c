#include "common.h"
#include "stage.h"
extern u8 D_800A726C[];
extern s32 D_800A7274[2][2][2][2];
extern StageAnimSpot D_800A72CC[];
extern AnimFrame *D_800A73C4[];
extern StageQuadTexture D_800A73CC[];
extern StageQuad D_800A78FC[];
extern u8 *D_800A7CC0[];

/* The file of the stage's sprites, which the versions number differently */
#if VERSION_US
#define SPRITES 0x1B7
#elif VERSION_EU
#define SPRITES 0x1C5
#endif

/* Draws the sprite at (x, y), flipped when it goes right */
void func_800A4CA4(StageFlyer *task) {
    SpriteDrawer drawer;
    s32 pos[2];

    initSpriteDrawer(&drawer);
    pos[0] = task->x >> 8;
    pos[1] = task->y >> 8;
    drawer.setLayerId(0x1002, 2);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.setPivot(pos[0], pos[1]);
    if (task->right) {
        drawer.setScale(-0x1000, 0x1000, 0x1000);
    }
    drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), task->frame, pos[0], pos[1]);
}

/* Moves the sprite diagonally unless it is still, animates it and ends it off screen */
void func_800A4D84(StageFlyer *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        if (!task->still) {
            if (task->right) {
                task->x += 0x500;
            } else {
                task->x -= 0x500;
            }
            if (task->up) {
                task->y -= 0x280;
            } else {
                task->y += 0x280;
            }
        }
        task->timer += GFX.funcs.getFrameTime();
        if (task->timer >= 8) {
            task->timer = 0;
        }
        if (task->anim != 0 && task->still) {
            task->frame = 0x3B;
        } else {
            task->frame = D_800A726C[(task->timer >> 2) + task->up * 2 + task->anim * 4];
        }
        if (task->right) {
            if (task->x >= 0x28000) {
                task->setState(task, TASK_KILL);
            }
        } else if (task->x <= 0) {
            task->setState(task, TASK_KILL);
        }
        func_800A4CA4(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates a flyer at the start the direction and stillness pick */
void *func_800A4F20(s32 up, s32 right, s32 still, s32 anim) {
    StageFlyer *task = createTask(func_800A4D84, 0x70, 0);

    task->up = up;
    task->right = right;
    task->still = still;
    task->anim = anim;
    task->x = D_800A7274[up][right][still][0] << 8;
    task->y = D_800A7274[up][right][still][1] << 8;
    if (still && anim) {
        task->x += 0x3200;
        task->y -= 0x1900;
    }
    return task;
}

/* Draws the picture of file SPRITES with the frame of the level */
void func_800A4FF4(StageGlow *task) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1002, 7);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), task->level >> 2, 0xDA, 0x47);
}

/* Raises the level with a sound, waits, lowers it and ends, drawing it */
void func_800A508C(StageGlow *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->level = 12;
        if (GAME.progress == 0x27) {
            SOUND.playSound(SOUND_DOOROPEN);
        } else {
            SOUND.playSound(SOUND_SE000000);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            task->level += GFX.funcs.getFrameTime();
            if (task->level >= 0x1C) {
                task->level = 0x1C;
                task->nextSubstate(task);
            }
            break;
        case 1:
            task->step += GFX.funcs.getFrameTime();
            if (task->step >= 0x8C) {
                task->nextSubstate(task);
            }
            break;
        case 2:
            task->level -= GFX.funcs.getFrameTime();
            if (task->level < 0xD) {
                task->level = 12;
                task->setState(task, TASK_KILL);
            }
            break;
        }
        func_800A4FF4(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5220(s32 arg) {
    return createTaskWithId(func_800A508C, 0x54, 0, arg);
}

#include "common/step_looping_animation.inc.c"

/* Draws the sprite of the effect at (x, y) at depth 4 of LAYER while it runs */
void func_800A5344(StageEffect *task, void *arg) {
    SpriteDrawer drawer;
    Layer *layer = arg;

    if (task->state == TASK_RUN) {
        initSpriteDrawer(&drawer);
        drawer.setTexture(0x140, 0x100);
        drawer.setLayer(layer, 4);
        drawer.setClutRow(0);
        drawer.draw(FILE_CACHE.getEntry(FIELDSTG_state.sheetEntry), task->frame, task->x, task->y);
    }
}

/* A looping sprite animation at the place key1 picks, started at a random point */
void func_800A53F0(StageEffect *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);

    switch (task->state) {
    case TASK_INIT:
    default:
        task->x = D_800A72CC[task->key1].x;
        task->y = D_800A72CC[task->key1].y;
        task->anim.index = RANDOM.next() & 1;
        task->anim.timer = RANDOM.next() % 3 + 2;
        task->frame = 0;
        task->nextState(task);
        break;
    case TASK_RUN:
        task->frame = stepLoopingAnimation(&task->anim, D_800A72CC[task->key1].frames, 0);
        if (task->frame != 0) {
            layer->addSortedCallback(layer, func_800A5344, task, task->y, 0);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Creates the task of func_800A53F0 with KEY as its key1 */
void *func_800A553C(s32 key) {
    Task *task = createTask(func_800A53F0, 0x60, 0);

    task->key1 = key;
    return task;
}

s32 func_800A5574(StageTileAnim *obj, AnimFrame *frames, s32 depth) {
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
            frame = frames;
            obj->anim.index = 0;
            obj->anim.timer += frame->duration;
        }
        func_800A5574(obj, frames, depth + 1);
    }
    return frame->frame;
}

/* Shows and loops the animations of the records with animations 1 and 2 */
void func_800A5668(StageTileLoop2 *task) {
    StageTile *t;
    StageTile *tile;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->tiles[0].anim.index = 0;
        task->tiles[0].anim.timer = D_800A73C4[0][0].duration;
        task->tiles[1].anim.index = 0;
        task->tiles[1].anim.timer = D_800A73C4[1][0].duration;
        for (t = FIELDSTG_state.objects; t->unk2 != 0; t++) {
            switch (t->anim) {
            case 1:
                task->tiles[0].tile = t;
                break;
            case 2:
                task->tiles[1].tile = t;
                break;
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            tile = task->tiles[i].tile;
            tile->visible = 1;
            tile->frame = func_800A5574(&task->tiles[i], D_800A73C4[i], 0);
            tile->clutRow = 0;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A57D8(void) {
    return createTask(func_800A5668, 0x60, 0);
}

/* Creates the six objects of func_800A53F0 (keys 0-5) and the object of func_800A5668 */
void func_800A5804(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 6; i++) {
            children[i] = func_800A553C(i);
        }
        children[6] = func_800A57D8();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A589C(void) {
    return createTask(func_800A5804, 0x50, 0x1C);
}

/* Lets out the flyers of the sets that are on, where their children are free */
void func_800A58C8(StageFlyerGate *task, void **children) {
    s32 animA;
    s32 animB;

    if (task->spawnA) {
        animA = RANDOM.next() & 1;
        if (children[0] == NULL) {
            children[0] = func_800A4F20(0, 0, 0, animA);
        }
        if (children[3] == NULL) {
            children[3] = func_800A4F20(1, 1, 0, 0);
        }
    }
    if (task->spawnB) {
        animB = RANDOM.next() & 1;
        if (children[0] == NULL) {
            children[0] = func_800A4F20(0, 0, 1, 0);
        }
        if (children[3] == NULL) {
            children[3] = func_800A4F20(0, 0, 1, 1);
        }
        if (children[1] == NULL) {
            children[1] = func_800A4F20(1, 0, 0, 0);
        }
        if (children[2] == NULL) {
            children[2] = func_800A4F20(0, 1, 0, animB);
        }
    }
}

/* Draws the three pictures of the gate */
void func_800A5A10(StageFlyerGate *task) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1002, 2);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0, 0x1F0);
    drawer.setClutRow((GFX.funcs.getTime() >> 1) & 1);
    switch (task->left) {
    case 0:
    default:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x44, 0xC6, 0xB3);
        break;
    case 1:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x45, 0xC6, 0xBC);
        break;
    case 2:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x46, 0xC6, 0xC4);
        break;
    }
    switch (task->left) {
    case 0:
    default:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x44, 0x156, 0xFB);
        break;
    case 1:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x45, 0x156, 0x104);
        break;
    case 2:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x46, 0x156, 0x10C);
        break;
    }
    switch (task->right) {
    case 0:
    default:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x41, 0xEA, 0xB3);
        break;
    case 1:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x42, 0xEA, 0xBC);
        break;
    case 2:
        drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0x43, 0xEA, 0xC4);
        break;
    }
}

/* Swaps the pictures every 0x79 frames, letting out the flyers */
void func_800A5C88(StageFlyerGate *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            task->left = 2;
            task->right = 0;
            task->spawnA = 1;
            task->spawnB = 0;
            break;
        case 1:
            if (task->left == 2) {
                task->left = 1;
            }
            if (task->right == 2) {
                task->right = 1;
            }
            task->step += GFX.funcs.getFrameTime();
            if (task->step >= 0x79) {
                if (task->left == 0) {
                    task->left = 2;
                }
                if (task->left == 1) {
                    task->left = 0;
                }
                if (task->right == 0) {
                    task->right = 2;
                }
                if (task->right == 1) {
                    task->right = 0;
                }
                task->nextSubstate(task);
            }
            task->spawnA = 0;
            task->spawnB = 0;
            break;
        case 2:
            task->spawnA = 0;
            task->spawnB = 1;
            break;
        }
        func_800A5A10(task);
        func_800A58C8(task, children);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Stops the object (substate 0) for map 0x324, starts it (substate 1) for 0x320 */
void func_800A5E04(Task *task, s32 id) {
    if (task != NULL) {
        switch (id) {
        case 0x324:
            task->setSubstate(task, 0);
            break;
        case 0x320:
            task->setSubstate(task, 1);
            break;
        }
    }
}

/* Creates the task of func_800A5C88 with id ARG */
void *func_800A5E50(s32 arg) {
    return createTaskWithId(func_800A5C88, 0x60, 0x10, arg);
}

/* Draws the 40 quads, those of kind 0 and 1 with the frames of the animations */
void func_800A5E80(StageByteAnims *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    u_long *ot = (u_long *)layer->getOtEntry(layer, 2);
    s32 scroll[2];
    POLY_FT4 *poly;
    StageQuadTexture *tex;
    StageQuad *quad;
    s32 size;
    s32 i;

    layer->getScroll(layer, scroll);
    poly = GFX.funcs.getPrim();
    for (i = 0; i < 40; i++) {
        quad = &D_800A78FC[i];
        switch (quad->kind) {
        case 0:
        case 1:
            tex = &D_800A73CC[task->anims[quad->kind].frame];
            break;
        default:
            tex = &D_800A73CC[quad->kind];
            break;
        }
        size = 0x28;
        if (quad->kind == 1) {
            size = 0x14;
        }
        setPolyFT4(poly);
        if (quad->kind >= 9) {
            setSemiTrans(poly, 1);
        }
        setRGB0(poly, 0x80, 0x80, 0x80);
        poly->x0 = quad->x0 - scroll[0];
        poly->x1 = quad->x1 - scroll[0];
        poly->x2 = quad->x2 - scroll[0];
        poly->x3 = quad->x3 - scroll[0];
        poly->y0 = quad->y0 - scroll[1];
        poly->y1 = quad->y1 - scroll[1];
        poly->y2 = quad->y2 - scroll[1];
        poly->y3 = quad->y3 - scroll[1];
        poly->u0 = tex->u;
        poly->u1 = tex->u + size;
        poly->u2 = tex->u;
        poly->u3 = tex->u + size;
        poly->v0 = tex->v;
        poly->v1 = tex->v;
        poly->v2 = tex->v + size;
        poly->v3 = tex->v + size;
        poly->tpage = getTPage(0, 0, tex->tpageX, tex->tpageY);
        poly->clut = getClut(tex->clutX, tex->clutY);
        addPrim(ot, poly);
        poly++;
    }
    GFX.funcs.setPrim(poly);
}

/* Plays its two byte-pair animations, restarting one when its animation changes, and draws */
void func_800A6174(StageByteAnims *task) {
    StageByteAnim *a;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].anim = 1;
        task->anims[0].cur = -1;
        task->anims[1].anim = 4;
        task->anims[1].cur = -1;
        break;
    case TASK_RUN:
        for (i = 0; i < 2; i++) {
            a = &task->anims[i];
            if (a->anim != a->cur) {
                a->cur = a->anim;
                a->index = 0;
                a->frame = 0;
                a->timer = 0;
            }
            a->timer -= GFX.funcs.getFrameTime();
            if (a->timer <= 0) {
                a->index++;
                if (D_800A7CC0[a->anim][a->index * 2 + 1] == 0) {
                    a->index = D_800A7CC0[a->anim][a->index * 2];
                }
                a->frame = D_800A7CC0[a->anim][a->index * 2];
                a->timer = D_800A7CC0[a->anim][a->index * 2 + 1];
            }
        }
        func_800A5E80(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Switches the animations to 2 and 5 with a sound for map 0x322 */
void func_800A6314(StageByteAnims *task, s32 id) {
    if (id == 0x322) {
        task->anims[0].anim = 2;
        task->anims[1].anim = 5;
        SOUND.playSound(SOUND_SE000002);
    }
}

void *func_800A6360(s32 arg) {
    return createTaskWithId(func_800A6174, 0x78, 0, arg);
}

/* Creates an object and the event object of the story progress */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[1] = func_800A6360(0x321);
        do {
            if (GAME.progress == 0) {
                children[0] = FIELDSTG_startEvent(0);
                break;
            }
            if (GAME.progress == 0x17) {
                children[0] = FIELDSTG_startEvent(0x2AC);
                break;
            }
            if (GAME.progress == 0x1B) {
                children[0] = FIELDSTG_startEvent(0x2E6);
                children[2] = func_800A589C();
                break;
            }
            if (GAME.progress == 0x20) {
                children[0] = FIELDSTG_startEvent(0x375);
                break;
            }
            if (GAME.progress == 0x27) {
                children[0] = FIELDSTG_startEvent(0x3CB);
                break;
            }
            if (GAME.progress == 0x2B) {
                children[0] = FIELDSTG_startEvent(0x5DC);
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

#define STAGE_CHILDREN_SIZE 0xC
#include "common/start_stage.inc.c"

/* Sets the story progress to 0 */
void func_800A64D0(void) {
    GAME.progress = 0;
}

void func_800A64DC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x66), 1);
}

#if VERSION_EU
void func_800A7644(void) {
    GAME.progress = 45;
}
#endif

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x1B7
#define STAGE_ARCHIVE 0x311
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x1C5
#define STAGE_ARCHIVE 0x320
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x1C700, 0x12C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.soundBank = 0x29;
    FIELDSTG_state.music = MUSIC(0x29, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFirstMap(0);
    switch (GAME.progress) {
    case 0x1B:
        FIELDSTG_state.soundBank = 0x29;
        FIELDSTG_state.music = MUSIC(0x29, 1);
        break;
    case 0x20:
        FIELDSTG_state.soundBank = 0x29;
        FIELDSTG_state.music = MUSIC(0x29, 2);
        break;
    case 0x27:
        FIELDSTG_state.soundBank = 0x29;
        FIELDSTG_state.music = MUSIC(0x29, 3);
        break;
    }
}

s16 script0[] = {
    0x600, 1, 1,
    0x100, 1, 0xB0, 0x98,
    0x101, 1, 1, 5,
    0x100, 0x10, 0x130, 0xB0,
    0x101, 0x10, 1, 7,
    0x101, 0x320, 0x324, 1,
    0x101, 0x321, 0x321, 1,
    0x300, 0x78,
    0x101, 1, 0x2A, 5,
    0x300, 0x3C,
    0x101, 1, 0x2B, 5,
    0x303, 1,
    0x101, 1, 0x2A, 5,
    0x300, 0x3C,
    0x200, 0, 1, 1, 2,
    0x101, 1, 0x2A, 5,
    0x301,
    0x102, 1, 0xC0, 0x90, 1,
    0x302, 1,
    0x101, 1, 0x2A, 1,
    0x300, 0x78,
    0x200, 0, 2, 1, 0,
    0x301,
    0x101, 1, 0x39, 1,
    0x101, 0x320, 0x320, 1,
    0x303, 1,
    0x101, 1, 0x2A, 1,
    0x300, 0x78,
    0x101, 1, 0x2A, 1,
    0x102, 0x10, 0x280, 0x1E0, 7,
    0x300, 0x168,
    0x102, 1, 0xD0, 0x88, 5,
    0x100, 0x10, 0, 0,
    0x101, 0x10, 1, 1,
    0x302, 1,
    0x101, 1, 0x2E, 5,
    0x101, 0x321, 0x322, 1,
    0x303, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 6,
    0x300, 0x1E,
    0x102, 1, 0x100, 0x98, 5,
    0x302, 1,
    0x200, 0, 3, 1, 4,
    0x101, 1, 1, 5,
    0x301,
    0x101, 1, 0x29, 1,
    0x101, 0x321, 0x321, 1,
    0x300, 0x3C,
    0x101, 1, 0x30, 1,
    0x303, 1,
    0x101, 1, 0x29, 1,
    0x300, 0x3C,
    0x200, 0, 4, 1, 2,
    0x101, 1, 0x29, 1,
    0x301,
    0x101, 1, 0x30, 1,
    0x101, 0x322, 0x323, 1,
    0x300, 0x3C,
    0x101, 1, 0x29, 1,
    0x100, 0xB, 0xF0, 0x78,
    0x102, 0xB, 0xC0, 0x90, 1,
    0x302, 0xB,
    0x101, 0xB, 1, 6,
    0x100, 0xC, 0xF0, 0x78,
    0x102, 0xC, 0xDA, 0x84, 7,
    0x302, 0xC,
    0x101, 1, 0x30, 1,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x200, 1, 6, 0xC, 2,
    0x200, 0, 5, 0xB, 3,
    0x101, 1, 1, 1,
    0x101, 0xB, 7, 6,
    0x101, 0xC, 7, 7,
    0x301,
    0x101, 1, 1, 3,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x101, 1, 0xC, 3,
    0x300, 0x3C,
    0x200, 0, 7, 1, 2,
    0x101, 1, 0xC, 3,
    0x301,
    0x101, 1, 0x31, 3,
    0x303, 1,
    0x101, 1, 0xC, 3,
    0x300, 0x3C,
    0x200, 0, 8, 1, 2,
    0x101, 1, 0xC, 2,
    0x301,
    0x101, 1, 1, 2,
    0x102, 0xB, 0xE0, 0x98, 6,
    0x302, 0xB,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x200, 0, 9, 0xB, 2,
    0x101, 0xB, 7, 6,
    0x301,
    0x101, 1, 0xC, 2,
    0x101, 0xB, 0xC, 6,
    0x101, 0xC, 0x34, 0,
    0x300, 0x78,
    0x101, 0xC, 0x35, 0,
    0x300, 0x78,
    0x101, 0xC, 1, 0,
    0x300, 0x3C,
    0x101, 0xC, 9, 0,
    0x303, 0xC,
    0x101, 0xC, 1, 0,
    0x300, 0x1E,
    0x102, 0xC, 0xB0, 0x98, 6,
    0x302, 0xC,
    0x101, 0xC, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xA, 0xC, 2,
    0x101, 0xC, 7, 6,
    0x301,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 6,
    0x300, 0x3C,
    0x101, 1, 9, 2,
    0x101, 0xB, 9, 6,
    0x303, 0xB,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x102, 1, 0x250, 0x138, 7,
    0x101, 0xB, 1, 7,
    0x300, 0x1E,
    0x102, 0xB, 0x250, 0x138, 7,
    0x102, 0xC, 0x250, 0x138, 7,
    0x300, 0x3C,
    0x304, 0x2D8, 0x280, 0x100, 1,
    0,
};
s16 script684[] = {
    0x601, 1, 0xC0, 0x90,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
#if VERSION_US
    0x100, 0x10, 0x90, 0xC0,
    0x101, 0x10, 1, 1,
#elif VERSION_EU
    0x100, 0x10, 0x12F, 0xC1,
    0x101, 0x10, 1, 7,
#endif
    0x100, 0x2D, 0xD0, 0x80,
    0x101, 0x2D, 1, 3,
    0x100, 0x2F, 0xA0, 0x98,
    0x101, 0x2F, 1, 4,
    0x100, 0x31, 0x100, 0x99,
    0x101, 0x31, 1, 5,
    0x100, 0x35, 0xD8, 0x94,
    0x101, 0x35, 1, 3,
#if VERSION_US
    0x100, 0x38, 0x70, 0xB0,
    0x101, 0x38, 1, 1,
    0x101, 0x320, 0x320, 2,
#elif VERSION_EU
    0x100, 0x38, 0x150, 0xB0,
    0x101, 0x38, 1, 7,
    0x101, 0x320, 0x324, 2,
#endif
    0x101, 0x321, 0x321, 0x321,
    0x300, 0x78,
    0x101, 0x321, 0x322, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x5A,
    0x101, 0x321, 0x321, 0x321,
    0x101, 0x323, 0x325, 0x35,
    0x101, 0x324, 0x325, 0x2F,
    0x101, 0x325, 0x325, 0x2D,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x2D,
    0x101, 0x324, 0x326, 0x2F,
    0x101, 0x325, 0x326, 0x35,
    0x300, 0x1E,
    0x200, 0, 2, 0x2D, 2,
    0x301,
    0x300, 0x12,
    0x200, 0, 3, 0x2F, 0,
    0x301,
    0x300, 0x12,
    0x200, 0, 4, 0x35, 2,
    0x301,
    0x300, 0x12,
    0x300, 0x12,
    0x304, 0x203, 0x14A, 0xC4, 1,
    0,
};
s16 script742[] = {
    0x601, 1, 0xE0, 0xB0,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x100, 0x10, 0xF0, 0xA0,
    0x101, 0x10, 1, 7,
    0x100, 0x2D, 0xB0, 0xC8,
    0x101, 0x2D, 1, 0,
    0x100, 0x2F, 0x89, 0xAC,
    0x101, 0x2F, 1, 1,
    0x100, 0x35, 0xBF, 0x88,
    0x101, 0x35, 1, 0,
    0x100, 0x38, 0x10F, 0xC0,
    0x101, 0x38, 1, 7,
    0x101, 0x321, 0x321, 2,
    0x300, 0x78,
    0x101, 0x323, 0x325, 0x2D,
    0x101, 0x324, 0x325, 0x10,
    0x101, 0x325, 0x325, 0x38,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x2D,
    0x101, 0x324, 0x326, 0x10,
    0x101, 0x325, 0x326, 0x38,
    0x300, 0x1E,
    0x200, 0, 1, 0x2D, 2,
    0x301,
    0x300, 0x12,
    0x200, 0, 2, 0x10, 0,
    0x301,
    0x300, 0x12,
    0x200, 0, 3, 0x38, 0,
    0x301,
    0x300, 0x12,
    0x101, 0x38, 1, 7,
    0x300, 0x18,
    0x101, 0x38, 1, 0,
    0x300, 0x18,
    0x101, 0x38, 1, 7,
    0x300, 0x18,
    0x101, 0x38, 1, 6,
    0x300, 0x18,
    0x101, 0x38, 1, 7,
    0x300, 0x18,
    0x200, 0, 4, 0x38, 0,
    0x301,
    0x300, 0xC,
    0x300, 6,
    0x304, 0x29C, 0x180, 0xDA, 1,
    0,
};
s16 script885[] = {
    0x601, 1, 0xE0, 0xA0,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x101, 0x321, 0x321, 0x321,
    0x300, 0x78,
    0x300, 0x1E,
    0x101, 0x321, 0x322, 0x321,
    0x300, 0x5A,
    0x300, 0x12,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x12,
    0x300, 0x12,
    0x304, 0x26D, 0x15E, 0xCA, 7,
    0,
};
s16 script971[] = {
    0x601, 1, 0xE0, 0xB0,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x100, 0x110, 0x10, 0x100,
    0x101, 0x110, 1, 5,
    0x100, 0x111, 0x10, 0x80,
    0x101, 0x111, 1, 7,
    0x100, 0x112, 0x1D0, 0x100,
    0x101, 0x112, 1, 3,
    0x101, 0x321, 0x321, 0x321,
    0x300, 0x78,
    0x102, 0x110, 0xC0, 0xA8, 5,
    0x302, 0x110,
    0x101, 0x110, 1, 0,
    0x102, 0x111, 0xB0, 0xD0, 1,
    0x102, 0x112, 0x100, 0x98, 3,
    0x302, 0x112,
    0x300, 0x12,
    0x101, 0x110, 1, 0,
    0x101, 0x111, 1, 1,
    0x101, 0x112, 1, 7,
    0x300, 0x12,
    0x101, 0x110, 1, 1,
    0x101, 0x111, 1, 0,
    0x101, 0x112, 1, 0,
    0x300, 0x12,
    0x101, 0x110, 1, 0,
    0x101, 0x111, 1, 1,
    0x101, 0x112, 1, 7,
    0x300, 0x12,
    0x101, 0x110, 1, 7,
    0x101, 0x111, 1, 2,
    0x101, 0x112, 1, 6,
    0x300, 0x12,
    0x101, 0x110, 1, 0,
    0x101, 0x111, 1, 1,
    0x101, 0x112, 1, 7,
    0x300, 0x12,
    0x101, 0x322, 0x323, 1,
    0x300, 0x3C,
    0x100, 0x9D, 0xF0, 0x78,
    0x101, 0x9D, 1, 1,
    0x300, 0xC,
    0x102, 0x9D, 0xE7, 0x7C, 1,
    0x300, 0xC,
    0x101, 0x323, 0x325, 0x9D,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x9D,
    0x300, 0x12,
    0x200, 0, 1, 0x9D, 1,
    0x301,
    0x101, 0x9D, 1, 5,
    0x300, 0x12,
    0x102, 0x9D, 0xF0, 0x78, 5,
    0x101, 0x322, 0x323, 2,
    0x302, 0x9D,
    0x100, 0x9D, 0, 0,
    0x101, 0x9D, 1, 1,
    0x101, 0x323, 0x325, 0x110,
    0x101, 0x324, 0x325, 0x111,
    0x101, 0x325, 0x325, 0x112,
    0x300, 0x5A,
    0x101, 0x110, 1, 1,
    0x101, 0x111, 1, 1,
    0x101, 0x112, 1, 1,
    0x101, 0x323, 0x326, 0x110,
    0x101, 0x324, 0x326, 0x111,
    0x101, 0x325, 0x326, 0x112,
    0x300, 0x12,
    0x101, 0x110, 1, 5,
    0x101, 0x111, 1, 5,
    0x101, 0x112, 1, 3,
    0x300, 0x12,
    0x304, 0x272, 0x100, 0x1E0, 5,
    0,
};
s16 script1500[] = {
    0x600, 1, 1,
    0x100, 1, 0xB0, 0x98,
    0x101, 1, 1, 5,
    0x100, 0x10, 0x130, 0xB0,
    0x101, 0x10, 1, 7,
    0x101, 0x320, 0x324, 1,
    0x101, 0x321, 0x321, 1,
    0x300, 0x78,
    0x101, 1, 0x2A, 5,
    0x300, 0x3C,
    0x101, 1, 0x2B, 5,
    0x303, 1,
    0x101, 1, 0x2A, 5,
    0x300, 0x3C,
    0x200, 0, 1, 1, 2,
    0x101, 1, 0x2A, 5,
    0x301,
    0x102, 1, 0xC0, 0x90, 1,
    0x302, 1,
    0x101, 1, 0x2A, 1,
    0x300, 0x78,
    0x200, 0, 2, 1, 0,
    0x301,
    0x101, 1, 0x39, 1,
    0x101, 0x320, 0x320, 1,
    0x303, 1,
    0x101, 1, 0x29, 1,
    0x300, 0x78,
    0x101, 1, 0x2A, 1,
    0x102, 0x10, 0x280, 0x1E0, 0,
    0x300, 0x168,
    0x102, 1, 0xD0, 0x88, 5,
    0x101, 0x10, 1, 1,
    0x302, 1,
    0x101, 1, 0x2E, 5,
    0x101, 0x321, 0x322, 1,
    0x303, 1,
    0x101, 1, 1, 5,
    0x300, 0x1E,
    0x101, 1, 1, 6,
    0x300, 0x1E,
    0x102, 1, 0x100, 0x98, 5,
    0x302, 1,
    0x200, 0, 3, 1, 4,
    0x101, 1, 1, 5,
    0x301,
    0x101, 1, 0x29, 1,
    0x101, 0x321, 0x321, 1,
    0x300, 0x3C,
    0x101, 1, 0x30, 1,
    0x303, 1,
    0x101, 1, 0x29, 1,
    0x300, 0x3C,
    0x200, 0, 4, 1, 2,
    0x101, 1, 0x29, 1,
    0x301,
    0x101, 1, 0x30, 1,
    0x101, 0x322, 0x323, 1,
    0x300, 0x3C,
    0x101, 1, 0x29, 1,
    0x100, 0xB, 0xF0, 0x78,
    0x102, 0xB, 0xC0, 0x90, 1,
    0x302, 0xB,
    0x101, 0xB, 1, 6,
    0x100, 0xC, 0xF0, 0x78,
    0x102, 0xC, 0xDA, 0x84, 7,
    0x302, 0xC,
    0x101, 1, 0x30, 1,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x200, 1, 6, 0xC, 2,
    0x200, 0, 5, 0xB, 3,
    0x101, 1, 1, 1,
    0x101, 0xB, 7, 6,
    0x101, 0xC, 7, 7,
    0x301,
    0x101, 1, 1, 3,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x101, 1, 0xC, 3,
    0x300, 0x3C,
    0x200, 0, 7, 1, 2,
    0x101, 1, 0xC, 3,
    0x301,
    0x101, 1, 0x31, 3,
    0x303, 1,
    0x101, 1, 0xC, 3,
    0x300, 0x3C,
    0x200, 0, 8, 1, 2,
    0x101, 1, 0xC, 2,
    0x301,
    0x101, 1, 1, 2,
    0x102, 0xB, 0xE0, 0x98, 6,
    0x302, 0xB,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x200, 0, 9, 0xB, 2,
    0x101, 0xB, 7, 6,
    0x301,
    0x101, 1, 0xC, 2,
    0x101, 0xB, 0xC, 6,
    0x101, 0xC, 0x34, 0,
    0x300, 0x78,
    0x101, 0xC, 0x35, 0,
    0x300, 0x78,
    0x101, 0xC, 1, 0,
    0x300, 0x3C,
    0x101, 0xC, 9, 0,
    0x303, 0xC,
    0x101, 0xC, 1, 0,
    0x300, 0x1E,
    0x102, 0xC, 0xB0, 0x98, 6,
    0x302, 0xC,
    0x101, 0xC, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xA, 0xC, 2,
    0x101, 0xC, 7, 6,
    0x301,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x101, 0xC, 1, 6,
    0x300, 0x3C,
    0x101, 1, 9, 2,
    0x101, 0xB, 9, 6,
    0x303, 0xB,
    0x101, 1, 1, 2,
    0x101, 0xB, 1, 6,
    0x300, 0x1E,
    0x102, 1, 0x250, 0x138, 7,
    0x101, 0xB, 1, 7,
    0x300, 0x1E,
    0x102, 0xB, 0x250, 0x138, 7,
    0x102, 0xC, 0x250, 0x138, 7,
    0x300, 0x3C,
#if VERSION_US
    0x304, 0xE0C, 0, 0, 0,
#elif VERSION_EU
    0x304, 0xE03, 0, 0, 1,
#endif
    0,
};
u8 D_800A726C[] = {
    50, 52, 53, 55, 56, 57, 56, 57,
};
s32 D_800A7274[2][2][2][2] = {
    { { { 640, 72 }, { 432, 176 } }, { { 0, 224 }, { 0, 0 } } },
    { { { 448, 392 }, { 0, 0 } }, { { 112, 392 }, { 0, 0 } } },
};
AnimFrame D_800A72B4[] = {
    { 50, 4 }, { 51, 4 }, { 255, 0 },
};
AnimFrame D_800A72C0[] = {
    { 53, 4 }, { 54, 4 }, { 255, 0 },
};
StageAnimSpot D_800A72CC[] = {
    { D_800A72C0, 20, 130 },
    { D_800A72C0, 80, 180 },
    { D_800A72C0, 120, 230 },
    { D_800A72C0, 170, 0x118 },
    { D_800A72B4, 0x15E, 210 },
    { D_800A72B4, 0x12C, 240 },
    { NULL, 0, 0 },
    { NULL, 0, 0 },
    { NULL, 0, 0 },
    { NULL, 0, 0 },
};
AnimFrame D_800A731C[] = {
    { 10, 12 }, { 11, 12 }, { 12, 12 }, { 13, 12 },
    { 14, 12 }, { 15, 20 }, { 16, 4 }, { 17, 4 },
    { 15, 4 }, { 13, 4 }, { 18, 4 }, { 11, 4 },
    { 13, 4 }, { 15, 4 }, { 13, 4 }, { 16, 4 },
    { 16, 4 }, { 15, 4 }, { 18, 4 }, { 17, 4 },
    { 11, 4 }, { 255, 0 },
};
AnimFrame D_800A7374[] = {
    { 18, 12 }, { 19, 12 }, { 20, 12 }, { 21, 12 },
    { 22, 12 }, { 23, 20 }, { 24, 4 }, { 25, 4 },
    { 22, 4 }, { 19, 4 }, { 21, 4 }, { 18, 4 },
    { 23, 4 }, { 20, 4 }, { 19, 4 }, { 25, 4 },
    { 22, 4 }, { 19, 4 }, { 18, 4 }, { 255, 0 },
};
AnimFrame *D_800A73C4[] = {
    D_800A731C, D_800A7374,
};
StageQuadTexture D_800A73CC[] = {
    { 0x180, 0x100, 0x1B2, 0x130, 0x1C8, 48, 0x170, 0x1DE },
    { 0x180, 0x100, 0x180, 0x14C, 0x100, 76, 0x170, 0x1DE },
    { 0x180, 0x100, 0x18A, 0x14C, 0x128, 76, 0x170, 0x1DE },
    { 0x180, 0x100, 0x194, 0x158, 0x150, 88, 0x170, 0x1DE },
    { 0x180, 0x100, 0x19E, 0x158, 0x178, 88, 0x170, 0x1DE },
    { 0x180, 0x100, 0x1A8, 0x158, 0x1A0, 88, 0x170, 0x1DE },
    { 0x180, 0x100, 0x1B2, 0x158, 0x1C8, 88, 0x170, 0x1DE },
    { 0x180, 0x100, 0x180, 0x174, 0x100, 116, 0x170, 0x1DE },
    { 0x180, 0x100, 0x18A, 0x174, 0x128, 116, 0x170, 0x1DE },
    { 0x180, 0x100, 0x194, 0x180, 0x150, 128, 0x170, 0x1DE },
    { 0x180, 0x100, 0x19E, 0x180, 0x178, 128, 0x170, 0x1DE },
    { 0x180, 0x100, 0x1A8, 0x180, 0x1A0, 128, 0x170, 0x1DE },
    { 0x180, 0x100, 0x1B2, 0x180, 0x1C8, 128, 0x170, 0x1DD },
    { 0x180, 0x100, 0x180, 0x19C, 0x100, 156, 0x170, 0x1DD },
    { 0x180, 0x100, 0x18A, 0x19C, 0x128, 156, 0x170, 0x1DD },
    { 0x180, 0x100, 0x194, 0x1A8, 0x150, 168, 0x170, 0x1DD },
    { 0x180, 0x100, 0x19E, 0x1A8, 0x178, 168, 0x170, 0x1DD },
    { 0x180, 0x100, 0x1A8, 0x1A8, 0x1A0, 168, 0x170, 0x1DD },
    { 0x180, 0x100, 0x1B2, 0x1A8, 0x1C8, 168, 0x170, 0x1DD },
    { 0x180, 0x100, 0x180, 0x1C4, 0x100, 196, 0x170, 0x1DD },
    { 0x180, 0x100, 0x18A, 0x1C4, 0x128, 196, 0x170, 0x1DD },
    { 0x180, 0x100, 0x194, 0x1D0, 0x150, 208, 0x170, 0x1DD },
    { 0x180, 0x100, 0x19E, 0x1D0, 0x178, 208, 0x170, 0x1DD },
    { 0x180, 0x100, 0x1A8, 0x1D0, 0x1A0, 208, 0x170, 0x1DD },
    { 0x180, 0x100, 0x1B2, 0x1D0, 0x1C8, 208, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1C0, 0x100, 0x200, 0, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1CA, 0x100, 0x228, 0, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1D4, 0x100, 0x250, 0, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1DE, 0x100, 0x278, 0, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1E8, 0x100, 0x2A0, 0, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1F2, 0x100, 0x2C8, 0, 0x170, 0x1DB },
    { 0x1C0, 0x100, 0x1C0, 0x128, 0x200, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1CA, 0x128, 0x228, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1D4, 0x128, 0x250, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1DE, 0x128, 0x278, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1E8, 0x128, 0x2A0, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1F2, 0x128, 0x2C8, 40, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1C0, 0x150, 0x200, 80, 0x170, 0x1DA },
    { 0x140, 0x100, 0x16A, 0x1D8, 168, 216, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1FA, 0x150, 0x2E8, 80, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1FA, 0x164, 0x2E8, 100, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1DE, 0x178, 0x278, 120, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1E3, 0x178, 0x28C, 120, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1FA, 0x178, 0x2E8, 120, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1DE, 0x18C, 0x278, 140, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1E3, 0x18C, 0x28C, 140, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1FA, 0x18C, 0x2E8, 140, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1E8, 0x190, 0x2A0, 144, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1ED, 0x190, 0x2B4, 144, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1F2, 0x190, 0x2C8, 144, 0x170, 0x1DE },
    { 0x1C0, 0x100, 0x1D0, 0x194, 0x240, 148, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1D5, 0x194, 0x254, 148, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1C0, 0x198, 0x200, 152, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1C5, 0x198, 0x214, 152, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1CA, 0x198, 0x228, 152, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1DA, 0x1A0, 0x268, 160, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1DF, 0x1A0, 0x27C, 160, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1F7, 0x1A0, 0x2DC, 160, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1E4, 0x1A4, 0x290, 164, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1E9, 0x1A4, 0x2A4, 164, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1EE, 0x1A4, 0x2B8, 164, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1CF, 0x1A8, 0x23C, 168, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1D4, 0x1A8, 0x250, 168, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1C0, 0x1AC, 0x200, 172, 0x170, 0x1DD },
    { 0x1C0, 0x100, 0x1C5, 0x1AC, 0x214, 172, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1CA, 0x1AC, 0x228, 172, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1D9, 0x1B4, 0x264, 180, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1DE, 0x1B4, 0x278, 180, 0x170, 0x1DC },
    { 0x1C0, 0x100, 0x1F3, 0x1B4, 0x2CC, 180, 0x170, 0x1DB },
    { 0x1C0, 0x100, 0x1F8, 0x1B4, 0x2E0, 180, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1E3, 0x1B8, 0x28C, 184, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1E8, 0x1B8, 0x2A0, 184, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1ED, 0x1B8, 0x2B4, 184, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1CF, 0x1BC, 0x23C, 188, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1D4, 0x1BC, 0x250, 188, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1C0, 0x1C0, 0x200, 192, 0x170, 0x1DA },
    { 0x1C0, 0x100, 0x1C5, 0x1C0, 0x214, 192, 0x170, 0x1D9 },
    { 0x1C0, 0x100, 0x1CA, 0x1C0, 0x228, 192, 0x170, 0x1D9 },
    { 0x1C0, 0x100, 0x1D9, 0x1C8, 0x264, 200, 0x170, 0x1D9 },
    { 0x1C0, 0x100, 0x1DE, 0x1C8, 0x278, 200, 0x170, 0x1D9 },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x170, 0x1F6 },
    { 0x180, 0x100, 0x194, 0x100, 0x150, 0, 0x170, 0x1F6 },
    { 0x1C0, 0x100, 0x1D7, 0x178, 0x25C, 120, 0x170, 0x1F4 },
};
StageQuad D_800A78FC[] = {
    { 121, 76, 168, 53, 121, 123, 168, 100, 80 },
    { 121, 77, 160, 58, 121, 116, 160, 97, 0 },
#if VERSION_US
    { 0x111, 94, 0x130, 109, 0x111, 125, 0x130, 140, 81 },
#elif VERSION_EU
    { 0x110, 92, 0x131, 108, 0x110, 123, 0x131, 139, 81 },
#endif
    { 0x115, 96, 0x130, 109, 0x115, 122, 0x130, 135, 0 },
#if VERSION_US
    { 27, 56, 54, 69, 27, 83, 54, 96, 81 },
#elif VERSION_EU
    { 29, 53, 56, 66, 29, 81, 56, 94, 81 },
#endif
    { 33, 59, 54, 69, 33, 81, 54, 91, 0 },
#if VERSION_US
    { 58, 72, 85, 85, 58, 99, 85, 112, 81 },
#elif VERSION_EU
    { 60, 68, 87, 81, 60, 97, 87, 110, 81 },
#endif
    { 64, 74, 85, 84, 64, 96, 85, 106, 0 },
#if VERSION_US
    { 58, 103, 85, 116, 58, 130, 85, 143, 81 },
#elif VERSION_EU
    { 60, 99, 87, 112, 60, 128, 87, 141, 81 },
#endif
    { 64, 105, 85, 115, 64, 127, 85, 137, 0 },
#if VERSION_US
    { 27, 87, 54, 100, 27, 114, 54, 127, 81 },
#elif VERSION_EU
    { 29, 84, 56, 97, 29, 112, 56, 125, 81 },
#endif
    { 33, 90, 54, 100, 33, 112, 54, 122, 0 },
    { 0x14F, 109, 0x15F, 101, 0x14F, 123, 0x15F, 115, 82 },
    { 0x14F, 109, 0x15B, 103, 0x14F, 119, 0x15B, 113, 1 },
    { 0x15F, 101, 0x16F, 93, 0x15F, 115, 0x16F, 107, 82 },
    { 0x15F, 101, 0x16B, 95, 0x15F, 111, 0x16B, 105, 1 },
    { 0x16F, 93, 0x17F, 85, 0x16F, 107, 0x17F, 99, 82 },
    { 0x16F, 93, 0x17B, 87, 0x16F, 103, 0x17B, 97, 1 },
    { 0x17F, 85, 0x18F, 77, 0x17F, 99, 0x18F, 91, 82 },
    { 0x17F, 85, 0x18B, 79, 0x17F, 95, 0x18B, 89, 1 },
    { 0x14F, 125, 0x15F, 117, 0x14F, 139, 0x15F, 131, 82 },
    { 0x14F, 125, 0x15B, 119, 0x14F, 135, 0x15B, 129, 1 },
    { 0x15F, 117, 0x16F, 109, 0x15F, 131, 0x16F, 123, 82 },
    { 0x15F, 117, 0x16B, 111, 0x15F, 127, 0x16B, 121, 1 },
    { 0x16F, 109, 0x17F, 101, 0x16F, 123, 0x17F, 115, 82 },
    { 0x16F, 109, 0x17B, 103, 0x16F, 119, 0x17B, 113, 1 },
    { 0x17F, 101, 0x18F, 93, 0x17F, 115, 0x18F, 107, 82 },
    { 0x17F, 101, 0x18B, 95, 0x17F, 111, 0x18B, 105, 1 },
    { 148, 91, 164, 83, 148, 105, 164, 97, 82 },
    { 148, 91, 160, 85, 148, 101, 160, 95, 1 },
    { 164, 83, 180, 75, 164, 97, 180, 89, 82 },
    { 164, 83, 176, 77, 164, 93, 176, 87, 1 },
    { 180, 75, 196, 67, 180, 89, 196, 81, 82 },
    { 180, 75, 192, 69, 180, 85, 192, 79, 1 },
    { 148, 107, 164, 99, 148, 121, 164, 113, 82 },
    { 148, 107, 160, 101, 148, 117, 160, 111, 1 },
    { 164, 99, 180, 91, 164, 113, 180, 105, 82 },
    { 164, 99, 176, 93, 164, 109, 176, 103, 1 },
    { 180, 91, 196, 83, 180, 105, 196, 97, 82 },
    { 180, 91, 192, 85, 180, 101, 192, 95, 1 },
};
u8 D_800A7BCC[] = {
    0, 4, 1, 4, 2, 4, 3, 4,
    4, 4, 5, 4, 6, 4, 7, 4,
    8, 4, 9, 4, 10, 4, 11, 4,
    0, 0, 0, 0,
};
u8 D_800A7BE8[] = {
    31, 8, 32, 8, 33, 8, 34, 8,
    35, 8, 36, 8, 37, 8, 0, 0,
};
u8 D_800A7BF8[] = {
    12, 10, 13, 4, 14, 4, 15, 4,
    16, 4, 17, 4, 18, 4, 19, 8,
    20, 8, 19, 8, 20, 8, 19, 8,
    20, 8, 19, 4, 21, 8, 22, 4,
    23, 4, 24, 4, 25, 4, 26, 26,
    26, 26, 27, 26, 26, 12, 28, 12,
    29, 12, 29, 12, 30, 12, 29, 12,
    28, 12, 26, 12, 19, 0, 0, 0,
};
u8 D_800A7C38[] = {
    38, 4, 39, 4, 40, 4, 41, 4,
    42, 4, 43, 4, 44, 4, 45, 4,
    46, 4, 47, 4, 48, 4, 49, 4,
    0, 0, 0, 0,
};
u8 D_800A7C54[] = {
    69, 4, 70, 4, 71, 4, 72, 4,
    73, 4, 74, 4, 75, 4, 0, 0,
};
u8 D_800A7C64[] = {
    50, 10, 51, 4, 52, 4, 53, 4,
    54, 4, 55, 4, 56, 4, 57, 8,
    58, 8, 57, 8, 58, 8, 57, 8,
    58, 8, 57, 4, 59, 8, 60, 4,
    61, 4, 62, 4, 63, 4, 64, 26,
    64, 26, 65, 26, 64, 12, 66, 12,
    67, 12, 67, 12, 68, 12, 67, 12,
    66, 12, 64, 12, 76, 120, 77, 120,
    64, 26, 64, 26, 65, 26, 64, 12,
    66, 12, 67, 12, 67, 12, 68, 12,
    67, 12, 66, 12, 64, 12, 78, 120,
    79, 120, 19, 0,
};
u8 *D_800A7CC0[] = {
    D_800A7BCC,
    D_800A7BE8,
    D_800A7BF8,
    D_800A7C38,
    D_800A7C54,
    D_800A7C64,
    NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x1B4, 0xD8, 0xB4, 0x170, 0x1EC },
    { 0x140, 0x100, 0x162, 0x1D8, 0x88, 0xD8, 0x170, 0x1EB },
    { 0x1C0, 0x100, 0x1EA, 0x150, 0x2A8, 0x50, 0x170, 0x1EA },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x170, 0x1E9 },
    { 0x140, 0x100, 0x14E, 0x18A, 0x38, 0x8A, 0x170, 0x1E8 },
    { 0x1C0, 0x100, 0x1CA, 0x150, 0x228, 0x50, 0x170, 0x1E7 },
    { 0x1C0, 0x100, 0x1D2, 0x150, 0x248, 0x50, 0x170, 0x1E6 },
    { 0x1C0, 0x100, 0x1DA, 0x150, 0x268, 0x50, 0x170, 0x1E5 },
    { 0x1C0, 0x100, 0x1E2, 0x150, 0x288, 0x50, 0x170, 0x1E4 },
    { 0x1C0, 0x100, 0x1F2, 0x150, 0x2C8, 0x50, 0x170, 0x1E3 },
    { 0x1C0, 0x100, 0x1EA, 0x170, 0x2A8, 0x70, 0x170, 0x1E2 },
    { 0x1C0, 0x100, 0x1F2, 0x170, 0x2C8, 0x70, 0x170, 0x1E1 },
    { 0x1C0, 0x100, 0x1C0, 0x178, 0x200, 0x78, 0x170, 0x1E0 },
    { 0x1C0, 0x100, 0x1C8, 0x178, 0x220, 0x78, 0x170, 0x1DF },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 1 },
    { NULL, NULL, 1 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor15Conditions[] = { PROGRESS(0x27), 1, CODES_END };
u16 actor16Conditions[] = { PROGRESS(0x27), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0xB, 5, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0xB, 5, 0, 0, 1 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0xC, 6, 0, 0, 1 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0xC, 6, 0, 0, 1 };
FieldActorEntry actor6 = { NULL, actor6Talks, 0x10, 7, 0, 0, 1 };
FieldActorEntry actor7 = { NULL, NULL, 0x2D, 8, 0, 0, 1 };
FieldActorEntry actor8 = { NULL, NULL, 0x2F, 9, 0, 0, 1 };
FieldActorEntry actor9 = { NULL, NULL, 0x31, 0xA, 0, 0, 1 };
FieldActorEntry actor10 = { NULL, NULL, 0x35, 0xB, 0, 0, 1 };
FieldActorEntry actor11 = { NULL, NULL, 0x38, 0xC, 0, 0, 1 };
FieldActorEntry actor12 = { actor12Conditions, NULL, 0x9D, 0xD, 0, 0, 1 };
FieldActorEntry actor13 = { actor13Conditions, NULL, 0x9E, 0xE, 0, 0, 1 };
FieldActorEntry actor14 = { actor14Conditions, NULL, 0x110, 0xF, 0, 0, 1 };
FieldActorEntry actor15 = { actor15Conditions, NULL, 0x111, 0x10, 0, 0, 1 };
FieldActorEntry actor16 = { actor16Conditions, NULL, 0x112, 0x11, 0, 0, 1 };
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
    &actor12,
    &actor13,
    &actor14,
    &actor15,
    &actor16,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 1, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 198, 179, 0, 0 },
    { 0, 2, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 342, 251, 0, 0 },
    { 0, 0, 0x80, 6, 0x32, 0, 0, 0, 0, 0, 363, 206, 0, 0 },
    { 0, 0, 0x80, 6, 0x35, 0, 0, 0, 0, 0, 136, 235, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 190, 156, 231, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 346, 229, 303, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 0, script0, EVENT_TEXT(0), NULL, func_800A64D0 },
    { 684, script684, EVENT_TEXT(0x20), NULL, NULL },
    { 742, script742, EVENT_TEXT(0x21), NULL, NULL },
    { 885, script885, EVENT_TEXT(0x22), NULL, func_800A64DC },
    { 971, script971, EVENT_TEXT(0x23), NULL, NULL },
#if VERSION_US
    { 1500, script1500, EVENT_TEXT(0x24), NULL, NULL },
#elif VERSION_EU
    { 1500, script1500, EVENT_TEXT(0x24), NULL, func_800A7644 },
#endif
    { -1, NULL, 0, NULL, NULL },
};
