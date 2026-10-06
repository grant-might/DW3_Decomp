/* The third object of FIELDSTG.PRO (see fieldstg.c): its rodata starts at
   0x80082598 (USA). */

#include "fieldstg.h"

Actor *FIELDSTG_findEventActor(EventTask *arg0, s32 id) {
    s32 i;

    if (id < 0x320) {
        for (i = 0; i < 30; i++) {
            if (arg0->entries[i].id == 0) {
                break;
            }
            if (arg0->entries[i].id == id) {
                return arg0->entries[i].actor;
            }
        }
    }
    return NULL;
}

s32 func_80084558(EventTask *task, s16 *op, EventChildren *children) {
    s32 id = op[1];
    s32 arg1 = op[2];
    s32 arg2 = op[3];
    Actor *actor;
    s32 target;
    s32 i;

    if (id < 0x320) {
        actor = FIELDSTG_findEventActor(task, id);
        if (actor != NULL) {
            actor->setPose(actor, arg1, arg2);
        }
    } else {
        target = (s32)TASK_REGISTRY.funcs.find(id, -1, -1);
        if (target == 0) {
            for (i = 0; i < 10; i++) {
                if (children->scripts[i] == 0) {
                    children->scripts[i] = func_80091730(id);
                    if (children->scripts[i] != 0) {
                        target = children->scripts[i];
                    }
                    break;
                }
            }
        }
        if (target != 0) {
            func_80091774(target, id, arg1, arg2);
        }
    }
    return 4;
}

/*
 * Runs an event: on state 0 it waits for the event's text file and the
 * field (task 7) and holds the characters; on state 1 it runs the script
 * until a command waits (kind 0 ends it, 1 moves or turns a character, 2
 * opens a message box, 3 waits, 6 runs FIELDSTG_followWithCamera or FIELDSTG_pointCamera), or
 * without a script runs start's task until it ends; state 3 releases the
 * characters and calls end. The match depends on next and actor being two
 * variables, and sub an s16.
 */
void FIELDSTG_runEvent(EventTask *task, EventChildren *children) {
    Actor *actor;
    Actor *next;
    s16 *pc;
    s32 running;
    s16 sub;
    s32 i;

    switch (task->state) {
    case 0:
    default:
        if ((D_800990B4.eventText == 0 || !FILE_CACHE.isLoading(D_800990B4.eventText >> 16)) &&
            ((Task *)TASK_REGISTRY.funcs.find(7, -1, -1))->state == 1) {
            next = TASK_REGISTRY.funcs.find(5, -1, -1);
            for (i = 0; next != NULL; next = TASK_REGISTRY.funcs.findNext()) {
                actor = next;
                task->entries[i].actor = actor;
                task->entries[i].id = actor->key1;
                i++;
                actor->startWalk(actor);
                if (i == 30) {
                    break;
                }
            }
            task->nextState(task);
        }
        break;
    case 1:
        if (task->pc != NULL) {
            pc = task->pc;
            running = 1;
            do {
                sub = *pc & 0xFF;
                switch (*pc >> 8) {
                case 0:
                default:
                    task->setState(task, 3);
                    running = 0;
                    break;
                case 1:
                    switch (sub) {
                    case 0:
                    default:
                        actor = FIELDSTG_findEventActor(task, pc[1]);
                        if (actor != NULL) {
                            actor->pos.x = pc[2] << 8;
                            actor->pos.y = pc[3] << 8;
                        }
                        pc += 4;
                        break;
                    case 1:
                        pc += func_80084558(task, pc, children);
                        break;
                    case 2:
                        actor = FIELDSTG_findEventActor(task, pc[1]);
                        if (actor != NULL) {
                            actor->setGoal(actor, pc[2], pc[3], pc[4]);
                        }
                        pc += 5;
                        break;
                    }
                    break;
                case 2: {
                    s32 box = pc[1];
                    s32 text = pc[2];
                    s32 kind = pc[4];
                    s32 id = pc[3];

                    actor = NULL;
                    if (kind != 4) {
                        actor = FIELDSTG_findEventActor(task, id);
                        if (actor != NULL) {
                            children->boxes[box] = FIELDSTG_createSpeech(actor, text, kind, 0);
                        }
                    } else {
                        children->boxes[box] = FIELDSTG_createSpeech(actor, text, 4, 1);
                    }
                    pc += 5;
                    break;
                }
                case 3:
                    switch (sub) {
                    case 0:
                    default:
                        if (task->wait == 0) {
                            task->wait = pc[1];
                        }
                        if (--task->wait != 0) {
                            running = 0;
                        } else {
                            pc += 2;
                        }
                        break;
                    case 1:
                        if (children->boxes[0] != NULL) {
                            running = 0;
                        } else {
                            pc += 1;
                        }
                        break;
                    case 2:
                        actor = FIELDSTG_findEventActor(task, pc[1]);
                        if (actor != NULL && actor->isWalking(actor)) {
                            running = 0;
                        } else {
                            pc += 2;
                        }
                        break;
                    case 3:
                        actor = FIELDSTG_findEventActor(task, pc[1]);
                        if (actor == NULL || actor->isAnimDone(actor)) {
                            pc += 2;
                        } else {
                            running = 0;
                        }
                        break;
                    case 4:
                        func_8008AEB4(pc[1], -1, pc[2] << 8, pc[3] << 8, pc[4]);
                        running = 0;
                        task->setState(task, 2);
                        break;
                    }
                    break;
                case 6:
                    switch (sub) {
                    case 0:
                    default:
                        FIELDSTG_followWithCamera(pc[1], pc[2]);
                        pc += 3;
                        break;
                    case 1:
                        FIELDSTG_pointCamera(pc[1], pc[2], pc[3]);
                        pc += 4;
                        break;
                    }
                    break;
                }
            } while (running);
            task->pc = pc;
            break;
        }
        switch (task->substate) {
        case 0:
        default:
            children->task = task->start();
            task->nextSubstate(task);
        case 1:
            if (children->task == NULL) {
                task->setState(task, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    case 3:
        for (i = 0; i < 30; i++) {
            if (task->entries[i].id == 0) {
                break;
            }
            task->entries[i].actor->resetControl(task->entries[i].actor);
        }
        D_800990B4.busy = 0;
        if (task->end != NULL) {
            task->end();
        }
        break;
    }
}

EventTask *FIELDSTG_startEvent(s32 id) {
    EventTask *task = createTask(FIELDSTG_runEvent, sizeof(EventTask), 0x38);
    FieldEvent *entry;
    Task *other;
    s32 text;

    for (entry = D_800990B4.events; entry->id != -1; entry++) {
        if (entry->id == id) {
            task->event = id;
            task->pc = entry->script;
            task->start = entry->start;
            task->end = entry->end;
            D_800990B4.eventText = text = entry->text;
            if (text != 0) {
                D_800990B4.eventText = text + (TEXT_FILE(1) << 16);
                FILE_CACHE.request(entry->text >> 16);
            }
            D_800990B4.busy = 1;
            if (id < 8000 || id >= 9000) {
                other = TASK_REGISTRY.funcs.find(5, -1, 0);
                if (other != NULL && other->state == 1) {
                    other->setSubstate(other, 1);
                }
            }
            break;
        }
    }
    if (D_800990B4.busy == 0) {
        task->setState(task, 3);
    }
    return task;
}

/* A cutscene's animation over the field (FIELDSTG_createCutsceneAnim): kind 0 plays once,
   kind 1 loops two animations until 160 ticks of frame time pass. The match
   depends on the if/else around the file calls (not a ?: in their argument)
   and on case 0 next to default. */
void FIELDSTG_playCutsceneAnim(CutsceneAnim *task) {
    TimLoader loader;
    SpriteDrawer drawer;
    s32 loading;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            if (task->kind) {
                FILE_CACHE.request(FIELD_ANIM_FILE + 1);
            } else {
                FILE_CACHE.request(FIELD_ANIM_FILE);
            }
            task->nextSubstate(task);
        case 1:
            if (task->kind) {
                loading = FILE_CACHE.isLoading(FIELD_ANIM_FILE + 1);
            } else {
                loading = FILE_CACHE.isLoading(FIELD_ANIM_FILE);
            }
            if (loading == 0) {
                initTimLoader(&loader);
                loader.setImagePos(0x280, 0);
                loader.setClutPos(0, 0xF0);
                if (task->kind) {
                    loader.loadArchive(FILE_CACHE.getEntry(((FIELD_ANIM_FILE + 1) << 16) | 1));
                    SOUND.playSound(0x40003);
                } else {
                    loader.loadArchive(FILE_CACHE.getEntry((FIELD_ANIM_FILE << 16) | 1));
                    SOUND.playSound(0x40018);
                }
                task->nextState(task);
            }
            break;
        }
        break;
    case 1:
        if (task->kind == 0) {
            if (task->timer <= 0) {
                task->index++;
                task->frame = FIELDSTG_cutsceneAnim[task->index].frame;
                task->timer = FIELDSTG_cutsceneAnim[task->index].duration;
            } else {
                task->timer -= GFX.funcs.getFrameTime();
            }
            if (task->frame == -1) {
                task->setState(task, 2);
            }
        }
        break;
    case 2:
    case 3:
        break;
    }

    if (task->state == 1 || task->state == 2) {
        if (task->kind) {
            while (1) {
                if (task->timer <= 0) {
                    task->index++;
                    task->frame = FIELDSTG_cutsceneLoopAnim[task->index].frame;
                    task->timer = FIELDSTG_cutsceneLoopAnim[task->index].duration;
                } else {
                    task->timer -= GFX.funcs.getFrameTime();
                }
                if (task->frame != -1) {
                    break;
                }
                task->index = task->timer;
                task->timer = -1;
            }
            while (1) {
                if (task->timer2 <= 0) {
                    task->index2++;
                    task->frame2 = FIELDSTG_cutsceneLoopAnim2[task->index2].frame;
                    task->timer2 = FIELDSTG_cutsceneLoopAnim2[task->index2].duration;
                } else {
                    task->timer2 -= GFX.funcs.getFrameTime();
                }
                if (task->frame2 != -1) {
                    break;
                }
                task->index2 = task->timer2;
                task->timer2 = -1;
            }
            task->counter += GFX.funcs.getFrameTime();
            if (task->counter > 0xA0) {
                task->setState(task, 2);
            }
        }
        initSpriteDrawer(&drawer);
        drawer.setFollowScroll(0);
        drawer.setLayerId(0x1002, 7);
        drawer.setTexture(0x280, 0);
        drawer.setAltClut(0, 0xF0);
        if (task->kind) {
            drawer.draw(FILE_CACHE.getEntry((FIELD_ANIM_FILE + 1) << 16), task->frame, 0, 0);
            if (task->frame2 != 0) {
                drawer.draw(FILE_CACHE.getEntry((FIELD_ANIM_FILE + 1) << 16), task->frame2, 0, 0);
            }
        } else if (task->state == 1) {
            drawer.draw(FILE_CACHE.getEntry(FIELD_ANIM_FILE << 16), task->frame, 0, 0);
        }
        if (task->kind) {
            drawer.draw(FILE_CACHE.getEntry((FIELD_ANIM_FILE + 1) << 16), 0, 0, 0);
        } else {
            drawer.draw(FILE_CACHE.getEntry(FIELD_ANIM_FILE << 16), 10, 0, 0);
        }
    }
}

CutsceneAnim *FIELDSTG_createCutsceneAnim(s32 kind) {
    CutsceneAnim *task = createTask(FIELDSTG_playCutsceneAnim, sizeof(CutsceneAnim), 0);

    task->kind = kind;
    return task;
}

s32 FIELDSTG_stepEffectAnim(EffectAnim *anim, AnimFrame *frames, s32 depth) {
    AnimFrame *frame = &frames[anim->anim.index];
    s32 elapsed = GFX.funcs.getFrameTime();

    if (elapsed > 4) {
        elapsed = 4;
    }
    if (depth == 0) {
        anim->anim.timer -= elapsed;
    }
    if (anim->anim.timer <= 0) {
        frame++;
        anim->anim.index++;
        anim->anim.timer += frame->duration;
        if (frame->frame == 0xFF) {
            return 0xFF;
        }
        FIELDSTG_stepEffectAnim(anim, frames, depth + 1);
    }
    return frame->frame;
}

void FIELDSTG_updateEffect(FieldEffect *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    SpriteDrawer sprite;
    s32 i;
    s32 j;
    s32 frame;

    switch (task->state) {
        default:
        case 0:
            for (i = 0; i < 4; i++) {
                task->anims[i].active = 1;
                task->anims[i].anim.index = 0;
                task->anims[i].anim.timer = FIELDSTG_effectAnims[task->set][i][0].duration;
            }
            task->nextState(task);
            break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (task->anims[j].active != 0) {
                    frame = FIELDSTG_stepEffectAnim(&task->anims[j], FIELDSTG_effectAnims[task->set][j], 0);
                    switch (frame) {
                        case 0x12C:
                            break;
                        case 0xFF:
                            task->anims[j].active = 0;
                            break;
                        default:
                            initSpriteDrawer(&sprite);
                            sprite.setTexture(0x240, 0x100);
                            sprite.setLayer(layer, 0);
                            sprite.setClutRow(0);
                            sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16 | 1), frame, task->x, task->y);
                            break;
                    }
                }
            }
            if (task->anims[0].active == 0 && task->anims[1].active == 0 && task->anims[2].active == 0
                && task->anims[3].active == 0) {
                task->setState(task, 3);
            }
            break;
        case 2:
        case 3:
            break;
    }
}

FieldEffect *FIELDSTG_createEffect(s32 x, s32 y, s32 set) {
    FieldEffect *task = createTask(FIELDSTG_updateEffect, sizeof(FieldEffect), 0);

    task->x = x;
    task->y = y;
    task->set = set;
    return task;
}

StreamTask *func_800855E0(StreamPool *pool) {
    s32 i;
    s32 oldest = GFX.funcs.getTime();
    StreamTask *found = pool->tasks[0];

    for (i = 0; i < 30; i++) {
        if (pool->tasks[i]->time <= oldest) {
            oldest = pool->tasks[i]->time;
            found = pool->tasks[i];
        }
    }
    return found;
}

/*
 * Streams the map's tiles while the CD reader is free: a tile of unk108
 * (0xFF for none) that a stream task has loaded is done, and each tile still
 * waiting goes to the oldest task (func_800855E0), until the reader is busy.
 * The match depends on each loop having a counter of its own.
 */
void func_80085650(MapStreamer *map, StreamPool *pool) {
    s32 i;
    s32 j;
    s32 k;
    s32 frame;
    s32 tile;
    StreamTask *task;

    if (CD_READER.isBusy() == 0) {
        for (i = 0; i < 30; i++) {
            task = pool->tasks[i];
            frame = task->getFrame(task);
            for (j = 0; j < 30; j++) {
                if (map->unk108[j] != 0xFF && map->unk108[j] == frame) {
                    map->unk108[j] = 0xFF;
                    task->updateTime(task);
                    break;
                }
            }
        }
        for (k = 0; k < 30; k++) {
            if (map->unk108[k] != 0xFF) {
                tile = map->unk108[k];
                if (map->unk104[tile].unk0 != 0) {
                    task = func_800855E0(pool);
                    if (task->isLoaded(task)) {
                        task->seek(task, tile, map->unk104[tile].unk4);
                    }
                }
                if (CD_READER.isBusy()) {
                    break;
                }
            }
        }
    }
}

void func_800857DC(Layer *layer, s32 x, s32 y, s32 level) {
    Point scroll;
    SPRT *prim;
    u_long *ot;
    s32 i;
    s32 shade;

    ot = (u_long *)layer->getOtEntry(layer, 0);
    shade = level >> 8;
    layer->getScroll(layer, &scroll);
    prim = GFX.funcs.getPrim();
    for (i = 0; i < 4; i++) {
        SetSprt(prim);
        if (shade != 0xFF) {
            SetSemiTrans(prim, 1);
        }
        prim->r0 = prim->g0 = prim->b0 = shade;
        prim->x0 = x - scroll.x + ((i & 1) << 6);
        prim->y0 = y - scroll.y + ((i << 5) & 0x40);
        prim->u0 = D_800990B4.images.field->u;
        prim->v0 = D_800990B4.images.field->v;
        prim->w = 0x40;
        prim->h = 0x40;
        prim->clut = GetClut(D_800990B4.images.field->clutX, D_800990B4.images.field->clutY);
        addPrim(ot, prim);
        prim++;
        SetDrawTPage((DR_TPAGE *)prim, 0, 1, GetTPage(0, 1, D_800990B4.images.field->x, D_800990B4.images.field->y));
        addPrim(ot, prim);
        prim = (SPRT *)((DR_TPAGE *)prim + 1);
    }
    GFX.funcs.setPrim(prim);
}

StreamTask *func_80085A00(StreamPool *pool, s32 frame) {
    s32 i;
    StreamTask *task;

    for (i = 0; i < 30; i++) {
        task = pool->tasks[i];
        if (task->getFrame(task) == frame) {
            return task;
        }
    }
    return NULL;
}

/* A tile of the map in view (func_80085A78) */
typedef struct MapSlot {
    /* 0x00 */ s16 loaded; /* a StreamTask has its frame */
    /* 0x02 */ s16 tile;
    /* 0x04 */ StreamTask *stream;
    /* 0x08 */ s32 entry; /* into MapStreamer.unk74, or -1 */
    /* 0x0C */ s32 frame;
    /* 0x10 */ s32 x;
    /* 0x14 */ s32 y;
} MapSlot;

/* Draws the map's tiles in view, under a cover that fades from the new ones,
   and while the decompressor is free, gives the first loaded tile without an
   entry the oldest of the 12 */
void func_80085A78(MapStreamer *task, StreamPool *pool) {
    Point tile;
    MapSlot slots[12];
    Layer *layer;
    StreamTask *stream;
    s32 count;
    s32 r;
    s32 c;
    s32 i;
    s32 j;
    s32 frame;
    s32 level;
    s32 oldest;
    s32 best;

    layer = GFX.funcs.getLayer(0x1002);
    count = 0;
    tile.x = task->scroll.x >= 0x20 ? (task->scroll.x - 0x20) / 128 : 0;
    tile.y = task->scroll.y >= 8 ? (task->scroll.y - 8) / 128 : 0;
    for (r = 0; r < 3; r++) {
        if (r + tile.y >= task->height) {
            break;
        }
        for (c = 0; c < 4; c++) {
            if (c + tile.x >= task->width) {
                break;
            }
            frame = c + tile.x + (r + tile.y) * task->width;
            stream = func_80085A00(pool, frame);
            slots[count].tile = task->unk104[frame].unk0;
            if (stream != NULL) {
                slots[count].stream = stream;
                slots[count].frame = frame;
                slots[count].entry = stream->unk248(stream);
                slots[count].loaded = 1;
            } else {
                slots[count].loaded = 0;
            }
            slots[count].x = (c + tile.x) * 128;
            slots[count].y = (r + tile.y) * 128;
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        if (slots[i].loaded && slots[i].entry != -1) {
            level = task->unk74[slots[i].entry].unk8;
            if (level != 0) {
                if (level == 0xFFFF && slots[i].stream->unk54 < GFX.funcs.getTime() - 10) {
                    task->unk74[slots[i].entry].unk8 = 0;
                } else {
                    func_800857DC(layer, slots[i].x, slots[i].y, level);
                    level -= 0x2AAA;
                    if (level <= 0) {
                        level = 0;
                    }
                    task->unk74[slots[i].entry].unk8 = level;
                }
            }
            slots[i].stream->draw(slots[i].stream, layer, slots[i].x, slots[i].y);
            task->unk74[slots[i].entry].unk4 = GFX.funcs.getTime();
        } else if (slots[i].tile != 0) {
            func_800857DC(layer, slots[i].x, slots[i].y, 0xFFFF);
        }
    }
    if (pool->decompressor->substate == 0) {
        for (i = 0; i < count; i++) {
                if (slots[i].loaded && slots[i].entry == -1 && slots[i].stream->isLoaded(slots[i].stream)) {
                best = 0;
                oldest = GFX.funcs.getTime();
                for (j = 0; j < 12; j++) {
                    if (task->unk74[j].unk4 < oldest) {
                        oldest = task->unk74[j].unk4;
                        best = j;
                    }
                }
                slots[i].stream->setSource(slots[i].stream, best, pool->decompressor);
                if (task->unk74[best].unk0 != -1) {
                    stream = func_80085A00(pool, task->unk74[best].unk0);
                    if (stream != NULL) {
                        stream->unk24C(stream);
                    }
                }
                task->unk74[best].unk0 = slots[i].frame;
                task->unk74[best].unk4 = GFX.funcs.getTime();
                task->unk74[best].unk8 = 0xFFFF;
                return;
            }
        }
    }
}

/*
 * Points the slots around the view at the map's tiles: unk108 gets, for each
 * of the 30 slots, the index of the tile it shows (0xFF off the map), and
 * unk128/unk12C the tile of the slots' top left corner. The slots come from
 * the layout for the leader's direction, flipped as that direction says, and
 * for the quadrant of its tile the view is in. The match depends on the y
 * offset being written as scrollY less its tile's start: its two reads of
 * scrollY rank that load ahead of the x test in local-alloc. It also depends
 * on x holding the horizontal flip before it becomes the tile column, and on
 * col counting the slots the first loop clears.
 */
void func_80085EEC(MapStreamer *task) {
    u8 slots[5][6];
    s32 quadrant;
    s32 set;
    u32 flip;
    s32 row;
    s32 col;
    s32 r;
    s32 c;
    s32 x;
    s32 y;
    s32 flipY;
    Actor *leader;
    s32 scrollY;
    s32 offset;

    leader = TASK_REGISTRY.funcs.find(5, -1, 0);
    offset = task->scroll.x & 0x7F;
    quadrant = offset > 0x40;
    set = FIELDSTG_dirLayouts[leader->dir][0];
    flip = FIELDSTG_dirLayouts[leader->dir][1];
    scrollY = task->scroll.y;
    offset = scrollY - (scrollY & ~0x7F);
    if (offset > 0x10) {
        quadrant |= 2;
    }
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 6; col++) {
            if (flip & 2) {
                c = 5 - col;
            } else {
                c = col;
            }
            if (flip & 1) {
                r = 4 - row;
            } else {
                r = row;
            }
            slots[row][col] = FIELDSTG_slotLayouts[set][quadrant][r][c];
        }
    }
    x = flip >> 1;
    x &= 1;
    flipY = flip & 1;
    task->unk128 = task->scroll.x / 128 - FIELDSTG_slotOffsets[quadrant][0][x];
    task->unk12C = task->scroll.y / 128 - FIELDSTG_slotOffsets[quadrant][1][flipY];
    for (col = 0; col < 30; col++) {
        task->unk108[col] = 0xFF;
    }
    for (row = 0; row < 5; row++) {
        y = row + task->unk12C;
        if (y >= 0 && y < task->height) {
            for (col = 0; col < 6; col++) {
                x = col + task->unk128;
                if (x >= 0 && x < task->width) {
                    task->unk108[slots[row][col]] = x + y * task->width;
                }
            }
        }
    }
}

void FIELDSTG_runMapStreamer(MapStreamer *task, StreamPool *pool) {
    s32 *header;
    s32 count;
    s32 i;
    s32 j;
    Layer *layer;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            if (CD_READER.isBusy() == 0) {
                task->unk54 = HEAP.alloc(0x800, 2);
                CD_READER.read(task->file, 0, 1, task->unk54, NULL);
                task->nextSubstate(task);
            }
            break;
        case 1:
            if (CD_READER.isBusy() != 1) {
                header = task->unk54;
                task->width = header[1];
                task->height = header[2];
                task->unk70 = header[3] / 2048;
                count = task->width * task->height;
                task->unk104 = HEAP.alloc(count * sizeof(MapTile), 2);
                for (j = 0; j < count; j++) {
                    task->unk104[j].unk0 = ((u16 *)header)[j + 8];
                    task->unk104[j].unk4 = ((u16 *)header)[j + 8] >> 11;
                }
                HEAP.free(task->unk54);
                task->unk54 = NULL;
                for (i = 0; i < 30; i++) {
                    pool->tasks[i] = func_80086B54(task->unk70 << 11, task->file);
                }
                for (i = 0; i < 12; i++) {
                    task->unk74[i].unk0 = -1;
                    task->unk74[i].unk4 = 0;
                }
                pool->decompressor = createDecompressor();
                task->nextState(task);
            }
            break;
        }
        break;
    case 1:
        layer = GFX.funcs.getLayer(0x1002);
        layer->getScroll(layer, &task->scroll);
        func_80085EEC(task);
        func_80085A78(task, pool);
        func_80085650(task, pool);
        break;
    case 2:
        break;
    case 3:
        if (task->unk54 != NULL) {
            HEAP.free(task->unk54);
        }
        if (task->unk104 != NULL) {
            HEAP.free(task->unk104);
        }
        break;
    }
}

Point *FIELDSTG_getMapSize(MapStreamer *task) {
    FIELDSTG_mapSize.x = task->width << 7;
    FIELDSTG_mapSize.y = task->height << 7;
    return &FIELDSTG_mapSize;
}

MapStreamer *FIELDSTG_createMapStreamer(s32 file) {
    MapStreamer *task = createTaskWithId(FIELDSTG_runMapStreamer, sizeof(MapStreamer), 0x7C, 4);

    task->file = file;
    task->getSize = FIELDSTG_getMapSize;
    return task;
}

void func_80086460(s32 id, s32 level) {
    Layer *layer = GFX.funcs.getLayer(id);
    s32 x;
    s32 y;

    if (layer != NULL) {
        for (y = 0; y < 0xF0; y += 0x80) {
            for (x = 0; x < 0x140; x += 0x80) {
                func_800857DC(layer, x, y, level);
            }
        }
    }
}

void func_800864E8(StreamTask *task) {
    task->time = GFX.funcs.getTime();
}

void func_80086518(StreamTask *task, s32 frame, s32 size) {
    if (task->frame != frame) {
        task->frame = frame;
        task->loaded = 0;
        task->unk70 = -1;
        task->sector = frame * task->frameSectors + 1;
        CD_READER.read(task->file, task->sector, size, task->buffer, &task->loaded);
        task->unk54 = 0;
    }
    func_800864E8(task);
}

s32 func_800865A0(StreamTask *task) {
    return task->loaded;
}

void func_800865AC(StreamTask *task, Layer *layer, s32 x, s32 y) {
    Point scroll;
    SPRT *prim;
    u_long *ot;
    s32 i;
    s32 j;

    layer->getScroll(layer, &scroll);
    prim = GFX.funcs.getPrim();
    for (i = 0; i < 3; i++) {
        ot = (u_long *)layer->getOtEntry(layer, FIELDSTG_spriteDepths[i]);
        for (j = 0; j < 5; j++) {
            if (task->sprites[i][j].visible) {
                SetSprt(prim);
                if (i == 2 || D_800990B4.spriteColor.cd != 0) {
                    prim->r0 = D_800990B4.spriteColor.r;
                    prim->g0 = D_800990B4.spriteColor.g;
                    prim->b0 = D_800990B4.spriteColor.b;
                } else {
                    prim->r0 = 0x80;
                    prim->g0 = 0x80;
                    prim->b0 = 0x80;
                }
                prim->x0 = task->sprites[i][j].x + x - scroll.x;
                prim->y0 = task->sprites[i][j].y + y - scroll.y;
                prim->w = task->sprites[i][j].w;
                prim->h = task->sprites[i][j].h;
                prim->clut = getClut(task->clutX, task->clutY);
                prim->u0 = task->sprites[i][j].u;
                prim->v0 = task->imageY + task->sprites[i][j].v;
                addPrim(ot, prim);
                prim++;
            }
        }
        SetDrawTPage((DR_TPAGE *)prim, 0, 1, GetTPage(1, 0, task->imageX, task->imageY));
        addPrim(ot, prim);
        prim = (SPRT *)((DR_TPAGE *)prim + 1);
    }
    GFX.funcs.setPrim(prim);
    func_800864E8(task);
}

void func_80086858(StreamTask *task, s32 slot, Decompressor *source) {
    task->slot = slot;
    task->source = source;
    source->start(source, task->buffer, 0x2800);
    task->setSubstate(task, 1);
}

void func_800868AC(StreamTask *task) {
    TimLoader loader;
    s32 i;
    s32 j;
    s32 count;
    s32 *data = task->unk230;
    s32 slot = task->slot;
    s16 *p = (s16 *)(data + 1);

    for (i = 0; i < 3; i++) {
        count = *(s32 *)p;
        p += 2;
        for (j = 0; j < count; j++) {
            task->sprites[i][j].visible = 1;
            task->sprites[i][j].x = *p++;
            task->sprites[i][j].y = *p++;
            task->sprites[i][j].u = *p++;
            task->sprites[i][j].v = *p++;
            task->sprites[i][j].w = *p++;
            task->sprites[i][j].h = *p++;
        }
        for (; j < 5; j++) {
            task->sprites[i][j].visible = 0;
        }
    }
    task->unk70 = slot;
    task->imageX = FIELDSTG_slotImages[slot].x;
    task->imageY = FIELDSTG_slotImages[slot].y;
    task->clutX = 0;
    task->clutY = slot + 0xF0;
    initTimLoader(&loader);
    loader.setImagePos(task->imageX, task->imageY);
    loader.setClutPos(task->clutX, task->clutY);
    loader.load(FILE_CACHE.getArchiveEntry(0, (s32)data));
    func_800864E8(task);
}

void func_80086A3C(StreamTask *task) {
    task->unk70 = -1;
}

s32 func_80086A48(StreamTask *task) {
    return task->unk70;
}

s32 func_80086A54(StreamTask *task) {
    return task->frame;
}

void func_80086A60(StreamTask *task) {
    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        break;
    case 1:
        switch (task->substate) {
        case 0:
            break;
        case 1:
            task->unk230 = task->source->getData(task->source);
            if (task->unk230 != NULL) {
                func_800868AC(task);
                task->setSubstate(task, 0);
            }
            break;
        }
        if (task->unk54 == 0 && task->loaded != 0) {
            task->unk54 = GFX.funcs.getTime();
        }
        break;
    case 2:
        break;
    case 3:
        HEAP.free(task->buffer);
        break;
    }
}

StreamTask *func_80086B54(s32 size, s32 file) {
    StreamTask *task = createTask(func_80086A60, sizeof(StreamTask), 0);

    task->seek = func_80086518;
    task->draw = func_800865AC;
    task->setSource = func_80086858;
    task->getFrame = func_80086A54;
    task->isLoaded = func_800865A0;
    task->unk248 = func_80086A48;
    task->unk24C = func_80086A3C;
    task->updateTime = func_800864E8;
    task->file = file;
    task->frameSectors = size / 2048;
    task->buffer = HEAP.allocHigh(size, 2);
    task->frame = -1;
    task->unk70 = -1;
    task->loaded = 1;
    return task;
}

void func_80086C4C(Task *task, Task **children) {
    s32 mode;

    switch (task->state) {
        default:
        case 0:
            mode = GAME.funcs.getMode();
            if (GAME.unk26D4 != mode) {
                GAME.unk26D4 = mode;
                GAME.clearTempFlags = 1;
#if VERSION_EU
                GAME.unk26F8 = 0x10;
#endif
            } else {
                GAME.clearTempFlags = 0;
            }
            children[0] = func_8008ADE8();
            task->nextState(task);
            break;
        case 1:
        case 2:
        case 3:
            break;
    }
}

Task *FIELDSTG_start(void) {
    return createTask(func_80086C4C, sizeof(Task), 0xC);
}

void func_80086D20(Task *task, AreaNameWindows *windows) {
    s16 mode = GAME.funcs.getMode();
    s32 i;

    for (i = 0; FIELDSTG_areaNames[i].mode != 0; i++) {
        if (FIELDSTG_areaNames[i].mode == mode) {
            windows->area = createTextWindow(0x1003, 1, 0x80, 0x1A);
            windows->area->setString(windows->area, FILE_CACHE.load(TEXT_FILE(TEXT_AREA_NAMES)), FIELDSTG_areaNames[i].area);
            windows->area->setTypeDelay(windows->area, 5);
            windows->place = createTextWindow(0x1003, 1, 0x28, 0x44);
            windows->place->setString(windows->place, FILE_CACHE.load(TEXT_FILE(TEXT_STAGE_NAMES)), FIELDSTG_areaNames[i].place);
            windows->place->setTypeDelay(windows->place, 5);
            break;
        }
    }
}
