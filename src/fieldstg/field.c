/* The field's main task: it sets the field up, runs it, and closes it for a
   battle or another mode, and what the executable, the stages and the actors
   ask of it: an encounter, an event, the inn or a warp. It's one object
   because startEncounter's jump tables follow FIELDSTG_updateField's with a gap that
   only the same object's 8-byte alignment makes */

#include "fieldstg.h"

/*
 * The field's battle transition: the screen breaks into TRANSITION_COLUMNS by
 * TRANSITION_ROWS tiles that slide off in a spiral (FIELDSTG_tileMoves, one move per counter step), then it
 * requests the battle's mode. The match depends on the move being an early
 * exit, a do-while (0) that breaks while the buffer is busy, with move
 * declared in it: the block's note stops stmt.c from rolling the exit test
 * to the loop's end, and the loop notes make the GFX.buffer load wait for
 * the counter's in the second scheduler.
 */
void FIELDSTG_playBattleTransition(FieldTask *task, FieldChildren *fieldChildren) {
    Task **children = (Task **)fieldChildren;
    Layer *layer;
    u_long *ot;
    s32 speed;
    POLY_FT4 *poly;
    s32 i;
    s32 j;
    s32 k;
    s32 row;
    s32 col;
    s32 more;
    s16 x;
    s16 y;

    switch (task->substate) {
    case 0:
        FILE_CACHE.markCached();
        setRECT(&FIELDSTG_screenRect, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        MoveImage(&FIELDSTG_screenRect, TRANSITION_IMAGE_X, 0);
        layer = GFX.funcs.getLayer(FIELD_LAYER_BACK);
        layer->setBgColor(layer, 0, 0, 0);
        layer = GFX.funcs.getLayer(FIELD_LAYER_MAP);
        layer->setBgColor(layer, 0, 0, 0);
        GAME.fieldMode = GAME.funcs.getMode();
        GAME.fieldPos = fieldChildren->actors[0]->pos;
        GAME.fieldDir = fieldChildren->actors[0]->dir;
        for (row = 0; row < TRANSITION_ROWS; row++) {
            for (col = 0; col < TRANSITION_COLUMNS; col++) {
                FIELDSTG_tiles[col][row].x = col * TRANSITION_TILE_WIDTH;
                FIELDSTG_tiles[col][row].y = row * TRANSITION_TILE_HEIGHT;
            }
        }
        SOUND.stopAll();
        SOUND.playSound(SOUND_ENCOUNTS);
        for (k = 0; k < task->childCount; k++) {
            if (*children != NULL) {
                (*children)->setState(*children, TASK_KILL);
            }
            children++;
        }
        FIELDSTG_tileRequests = 0;
        task->nextSubstate(task);
    case 1:
        switch (FIELDSTG_tileRequests) {
        case 0:
            if (CD_READER.isBusy() == 0) {
                FIELDSTG_tileRequests++;
            }
            break;
        case 1:
            if (CD_READER.isBusy() == 0) {
#if VERSION_US
                FILE_CACHE.request(0x1BD);
                FILE_CACHE.request(0x1BE);
                FILE_CACHE.request(0xBE);
                FILE_CACHE.request(0x1FA);
                FILE_CACHE.request(0x159);
#elif VERSION_EU
                FILE_CACHE.request(0x1CB);
                FILE_CACHE.request(0x1CC);
                FILE_CACHE.request(0x1CF);
                FILE_CACHE.request(0x208);
                FILE_CACHE.request(0x167);
#endif
                FIELDSTG_tileRequests++;
            }
            break;
        }
        layer = GFX.funcs.getLayer(FIELD_LAYER_MAP);
        ot = (u_long *)layer->getOtEntry(layer, 0);
        speed = GFX.funcs.getFrameTime() * TRANSITION_SPEED;
        do {
            TileMove *move = &FIELDSTG_tileMoves[task->counter];

            if (GFX.buffer != 0) {
                break;
            }
            if (move->dir != 0) {
                *move->value += speed * move->dir;
                if (move->dir >= 0) {
                    more = move->limit > *move->value;
                } else {
                    more = *move->value > move->limit;
                }
                if (!more) {
                    *move->value = TRANSITION_GONE;
                    task->tickCounter(task);
                }
            } else {
                FIELDSTG_tiles[2][3].x = TRANSITION_GONE;
                if (++task->step >= TRANSITION_WAIT) {
                    if (task->step < TRANSITION_DONE) {
                        GAME.funcs.requestMode(task->nextMode, task->nextModeArg);
                    }
                    task->step = TRANSITION_DONE;
                }
            }
        } while (0);
        if (task->step != TRANSITION_DONE) {
            poly = GFX.funcs.getPrim();
            setRGB0((POLY_F4 *)poly, 0x10, 0x10, 0x10);
            setPolyF4((POLY_F4 *)poly);
            setSemiTrans((POLY_F4 *)poly, 1);
            ((POLY_F4 *)poly)->x0 = 0;
            ((POLY_F4 *)poly)->x1 = SCREEN_WIDTH;
            ((POLY_F4 *)poly)->x2 = 0;
            ((POLY_F4 *)poly)->x3 = SCREEN_WIDTH;
            ((POLY_F4 *)poly)->y0 = 0;
            ((POLY_F4 *)poly)->y1 = 0;
            ((POLY_F4 *)poly)->y2 = SCREEN_HEIGHT;
            ((POLY_F4 *)poly)->y3 = SCREEN_HEIGHT;
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((POLY_F4 *)poly + 1);
            setDrawTPage((DR_TPAGE *)poly, 0, 1, getTPage(0, 2, 320, 0));
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((DR_TPAGE *)poly + 1);
            for (i = 0; i < TRANSITION_ROWS; i++) {
                for (j = 0; j < TRANSITION_COLUMNS; j++) {
                    if (FIELDSTG_tiles[j][i].x != TRANSITION_GONE && FIELDSTG_tiles[j][i].y != TRANSITION_GONE) {
                        setPolyFT4(poly);
                        setSemiTrans(poly, 1);
                        setRGB0(poly, 0x80, 0x80, 0x80);
                        x = FIELDSTG_tiles[j][i].x;
                        poly->x0 = poly->x2 = x;
                        poly->x1 = poly->x3 = x + TRANSITION_TILE_WIDTH;
                        y = FIELDSTG_tiles[j][i].y;
                        poly->u0 = 0;
                        poly->u1 = TRANSITION_TILE_WIDTH;
                        poly->u2 = 0;
                        poly->u3 = TRANSITION_TILE_WIDTH;
                        poly->v0 = i * TRANSITION_TILE_HEIGHT;
                        poly->v1 = i * TRANSITION_TILE_HEIGHT;
                        poly->v2 = i * TRANSITION_TILE_HEIGHT + TRANSITION_TILE_HEIGHT;
                        poly->v3 = i * TRANSITION_TILE_HEIGHT + TRANSITION_TILE_HEIGHT;
                        poly->y0 = poly->y1 = y;
                        poly->y2 = poly->y3 = y + TRANSITION_TILE_HEIGHT;
                        poly->tpage = getTPage(2, 0, TRANSITION_IMAGE_X + j * TRANSITION_TILE_WIDTH, 0);
                        addPrim(ot, poly);
                        poly++;
                    }
                }
            }
            GFX.funcs.setPrim(poly);
        } else {
            task->nextSubstate(task);
        }
        break;
    case 2:
        break;
    }
}

/* Closes the field for the next mode: the view shrinks to nothing, the cover
   fades in, and the mode is requested with where the player stands */
void FIELDSTG_closeField(FieldTask *task, FieldChildren *children) {
    Vec2 clip;
    Layer *layer;
    Actor *actor;
    Actor *player;
    s32 width;
    s32 height;

    switch (task->substate) {
    default:
    case 0:
        FILE_CACHE.markCached();
        player = TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, -1, 0);
        if (player != NULL && player->tile.x != 0) {
            task->centerOnPlayer = 1;
        } else {
            task->centerOnPlayer = 0;
        }
        task->width = SCREEN_WIDTH;
        task->fade = 0;
        task->height = SCREEN_HEIGHT;
        task->nextSubstate(task);
    case 1:
        layer = GFX.funcs.getLayer(FIELD_LAYER_MAP);
        layer->setBgColor(layer, 1, 1, 1);
        task->width -= 10;
        task->height -= 7;
        if (task->width <= 0) {
            layer->setBgColor(layer, 0, 0, 0);
            task->width = 0;
            task->height = 0;
            task->nextSubstate(task);
        }
        actor = TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, -1, 0);
        layer->getScroll(layer, &clip);
        if (task->centerOnPlayer != 0) {
            clip.x = actor->tile.x - clip.x;
            clip.y = actor->tile.y - clip.y;
        } else {
            clip.x = SCREEN_WIDTH / 2;
            clip.y = SCREEN_HEIGHT / 2;
        }
        clip.x -= task->width / 2;
        if (clip.x < 0) {
            clip.x = 0;
        }
        clip.y -= task->height / 2;
        if (clip.y < 0) {
            clip.y = 0;
        }
        layer->setClipPos(layer, clip.x, clip.y);
        width = task->width;
        height = task->height;
        if (clip.x + width > SCREEN_WIDTH) {
            width = SCREEN_WIDTH - clip.x;
        }
        if (clip.y + height > SCREEN_HEIGHT) {
            height = SCREEN_HEIGHT - clip.y;
        }
        layer->setClipSize(layer, width, height);
        FIELDSTG_drawCover(FIELD_LAYER_COVER, task->fade);
        if (task->fade != 0x8000) {
            task->fade += 0x400;
        }
        break;
    case 2:
        layer = GFX.funcs.getLayer(FIELD_LAYER_COVER);
        switch (task->step) {
        default:
        case 0:
            task->width = 0;
            task->height = 0;
            task->step++;
        case 1:
            break;
        }
        task->width += 8;
        layer->setClipPos(layer, task->width, task->height);
        layer->setClipSize(layer, (SCREEN_WIDTH / 2 - task->width) * 2, (SCREEN_HEIGHT / 2 - task->height) * 2);
        if (task->width > SCREEN_WIDTH / 2) {
            GAME.funcs.requestMode(task->nextMode, task->nextModeArg);
            GAME.fieldMode = GAME.funcs.getMode();
            GAME.fieldPos = children->actors[0]->pos;
            GAME.fieldDir = children->actors[0]->dir;
            task->nextSubstate(task);
        }
        FIELDSTG_drawCover(FIELD_LAYER_COVER, 0x8000);
        break;
    case 3:
        break;
    }
}

/* Whether the mode is FIELD_MODE_WSTAG415 or FIELD_MODE_WSTAG815, whose field
   keeps the file cache and doesn't take the high buffer */
s32 FIELDSTG_keepsFileCache(void) {
    if (GAME.funcs.getMode() == FIELD_MODE_WSTAG415) {
        return 1;
    }
    return GAME.funcs.getMode() == FIELD_MODE_WSTAG815;
}

/*
 * The field's update: sets up the stage, creates the characters and the
 * NPCs, then runs the field and opens its menu. The match depends on two
 * early exits written as do-while (0)s with breaks: one around the leader's
 * search and the actors it creates, one around the menu's opening. flow
 * weighs the references inside a loop's notes one level more, which is
 * what ranks the list pointer above the entry it loads, the search's
 * hoisted 1 above task, and the menu's GAME base above the other saved
 * registers; written as plain ifs, task takes s3 for s4.
 */
void FIELDSTG_updateField(FieldTask *task, FieldChildren *children) {
    RECT rect;
    Layer *layer;
    FieldActorEntry **list;
    FieldActorEntry *entry;
    FieldActorEntry **npcList;
    FieldActorEntry *npc;
    s32 mode;
    s32 id;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        switch (task->substate) {
        case 0:
        default:
            if (FIELDSTG_keepsFileCache() == 0) {
                FILE_CACHE.freeFrom(0x8015C674);
            }
            GFX.funcs.reset();
            GFX.funcs.allocPrimBuffers(0x6400);
            GFX.funcs.setDisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
            rect.x = 0;
            rect.y = 0;
            rect.w = SCREEN_WIDTH;
            rect.h = SCREEN_HEIGHT;
            layer = GFX.funcs.createLayer(&rect, 1, FIELD_LAYER_BACK);
            layer->setBgColor(layer, 1, 1, 1);
            GFX.funcs.createLayer(&rect, 1, FIELD_LAYER_COVER);
            layer = GFX.funcs.createLayer(&rect, 4, FIELD_LAYER_MAP);
            layer->allocCallbacks(layer, 0x32);
            GFX.funcs.createLayer(&rect, 1, FIELD_LAYER_TEXT);
            layer = GFX.funcs.createLayer(&rect, 1, FIELD_LAYER_BANNER);
            layer->setBgColor(layer, 1, 1, 1);
            if (FIELDSTG_keepsFileCache() == 0) {
                task->highBuffer = HEAP.allocHigh(0x9615C, 2);
            }
            if (GAME.clearTempFlags == 0) {
                FILE_CACHE.touchMarked();
            }
            FIELDSTG_map.setFile(FIELD_MAP_AREAS, 0);
            FIELDSTG_state.init();
            if (FIELDSTG_state.stageFile != 0) {
                OVERLAY_LOADER.loadSubOverlay(FIELDSTG_state.stageFile);
            }
            if (FIELDSTG_state.stageInit != NULL) {
                children->stage = FIELDSTG_state.stageInit(task);
            }
            FLAGS_00.updateModeFlags();
            FLAGS_00.applyAction(FIELD_VISITED_FLAG(GAME.funcs.getMode()), 1);
            mode = GAME.funcs.getPrevMode();
            /* from other than a field (0x2xx, 0x3xx), STDWTITL,
               STPLNMET or STAGSLCT, the player comes back
               where the field was left */
            if ((mode & 0xFF00) != 0x200 && (mode & 0xFF00) != 0x300 && MODE_OVERLAY(mode) != MODE_TITLE &&
                mode != MODE_STAGE_SELECT && mode != MODE_PLAYER_NAME) {
                GAME.modeArg = -1;
                FIELDSTG_state.defaultStart = GAME.fieldPos;
                FIELDSTG_state.defaultStartDir = GAME.fieldDir;
            }
            children->banner = FIELDSTG_createBanner(1);
            task->nextSubstate(task);
        case 1:
            switch (task->step) {
            case 0:
            default:
                if (FIELDSTG_state.soundBank != 0) {
                    SOUND.loadBank(FIELDSTG_state.soundBank);
                }
                task->nextStep(task);
            case 1:
                if (SOUND.isLoading() == 0) {
                    if (FIELDSTG_state.music != 0) {
                        SOUND.playSound(FIELDSTG_state.music);
                    } else {
                        SOUND.stopSound(SOUND.music);
                    }
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 2:
            switch (task->step) {
            case 0:
            default:
                children->unk10 = FIELDSTG_createFileLoader(0);
                task->nextStep(task);
                break;
            case 1:
                if (children->unk10 == NULL) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 3:
            if (FIELDSTG_state.objects != NULL) {
                children->mapObjects = FIELDSTG_createMapObjects(FIELDSTG_state.sheetEntry, FIELDSTG_state.objects);
            }
            if (FIELDSTG_state.slots != NULL) {
                children->triggers = FIELDSTG_createTriggers(FIELDSTG_state.sheetEntry, FIELDSTG_state.slots);
            }
            do {
                list = FIELDSTG_state.actors;
                id = 0;
                if (list != NULL) {
                    while (*list != NULL) {
                        entry = *list;
                        switch (entry->id) {
                        case 1:
                        case 0x6A:
                        case 0x146:
                        case 0x147:
                            if (entry->conditions == NULL || FLAGS_00.checkConditions(entry->conditions) == 1) {
                                id = entry->id;
                            }
                            break;
                        }
                        if (id != 0) {
                            break;
                        }
                        list++;
                    }
                }
                if (id != 0) {
                    children->actors[0] = FIELDSTG_createActor(id, 0, 0, NULL);
                    break;
                }
                children->actors[0] = FIELDSTG_createActor(FIELD_CHARACTER_PLAYER, 0, 0, NULL);
                if (GAME.progress >= 3) {
                    if (GAME.funcs.getPartyPartner(0) >= 0) {
                        children->actors[1] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(0) + FIELD_CHARACTER_PARTNERS, 2, 1, NULL);
                    }
                    if (GAME.funcs.getPartyPartner(1) >= 0) {
                        children->actors[2] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(1) + FIELD_CHARACTER_PARTNERS, 4, 2, NULL);
                    }
                    if (GAME.funcs.getPartyPartner(2) >= 0) {
                        children->actors[3] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(2) + FIELD_CHARACTER_PARTNERS, 8, 3, NULL);
                    }
                }
            } while (0);
            npcList = FIELDSTG_state.actors;
            if (npcList != NULL) {
                i = 0;
                while (*npcList != NULL) {
                    npc = *npcList;
                    switch (npc->id) {
                    case 1:
                    case 0x6A:
                    case 0x146:
                    case 0x147:
                        break;
                    default:
                        if (npc->conditions == NULL || FLAGS_00.checkConditions(npc->conditions) != 0) {
                            children->npcs[i] = FIELDSTG_createActor(npc->id, 1, npc->unkA, npc);
                            children->npcs[i]->pos.x = npc->x << 8;
                            children->npcs[i]->pos.y = npc->y << 8;
                            children->npcs[i]->dir = npc->dir;
                            i++;
                        }
                        break;
                    }
                    npcList++;
                }
            }
            children->camera = FIELDSTG_createCamera();
            task->nextSubstate(task);
            break;
        case 4:
            if (FIELDSTG_keepsFileCache() == 0) {
                switch (task->step) {
                case 0:
                default:
                    if (CD_READER.isBusy() != 0) {
                        break;
                    }
                    if (task->highBuffer != NULL) {
                        HEAP.free(task->highBuffer);
                    }
                    children->mapStreamer = FIELDSTG_createMapStreamer(FIELDSTG_state.mapFile);
                    task->nextStep(task);
                case 1:
                    if (children->mapStreamer->state == TASK_RUN && children->banner->state == TASK_DONE) {
                        children->banner->setSubstate(children->banner, 1);
                        task->nextState(task);
                    }
                    break;
                }
            } else if (children->banner->state == TASK_DONE) {
                children->banner->setSubstate(children->banner, 1);
                task->nextState(task);
            }
            break;
        }
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (FIELDSTG_state.innOpen != 1 && FIELDSTG_state.busy == 0 && FIELDSTG_state.acting == 0) {
                do {
                    if (GAME.progress < 4 || !(PAD.getPressed(0) & (1 << PAD_START))) {
                        break;
                    }
                    FIELDSTG_state.innOpen = 1;
                    FIELDSTG_state.busy = 1;
                    children->menu = createFieldMenu(FIELD_LAYER_MAP, 0);
                    GAME.fieldMode = GAME.funcs.getMode();
                    GAME.fieldPos = children->actors[0]->pos;
                    GAME.fieldDir = children->actors[0]->dir;
                    children->actors[0]->setSubstate(children->actors[0], ACTOR_STAND);
                    FILE_CACHE.markCached();
                    task->nextSubstate(task);
                } while (0);
            }
            break;
        case 1:
            if (children->menu == NULL) {
                FIELDSTG_state.innOpen = 0;
                FIELDSTG_state.busy = 0;
                task->setSubstate(task, 0);
            }
            break;
        case 2:
            if (children->unk10 == NULL) {
                FIELDSTG_state.innOpen = 0;
                FIELDSTG_state.busy = 0;
                task->setSubstate(task, 0);
            }
            break;
        case 3:
            switch (task->step) {
            case 0:
            default:
                children->effect = FIELDSTG_createEffect(task->warpPos.x, task->warpPos.y, task->warpKind);
                SOUND.playSound(SOUND_DIGIMENT);
                task->nextStep(task);
            case 1:
                if (task->counter < 0x3C) {
                    task->counter += GFX.funcs.getFrameTime();
                    break;
                }
                children->fade = createScreenFade(FIELD_LAYER_MAP);
                children->fade->start(children->fade, 0, 0x14);
                task->nextStep(task);
            case 2:
                if (children->fade->state == TASK_DONE) {
                    for (i = 0; i < 4; i++) {
                        if (children->actors[i] != NULL) {
                            children->actors[i]->setState(children->actors[i], TASK_KILL);
                        }
                    }
                    for (i = 0; i < 15; i++) {
                        if (children->npcs[i] != NULL) {
                            children->npcs[i]->setState(children->npcs[i], TASK_KILL);
                        }
                    }
                    children->mapStreamer->setState(children->mapStreamer, TASK_KILL);
                    children->mapObjects->setState(children->mapObjects, TASK_KILL);
                    children->cutscene = FIELDSTG_createCutsceneAnim(task->warpKind);
                    children->fade->start(children->fade, 1, 0x14);
                    task->nextStep(task);
                }
                break;
            case 3:
                if (children->cutscene->state == TASK_DONE) {
                    GAME.place = task->warp->place;
                    GAME.placeArg = task->warp->unkC;
                    FIELDSTG_leaveField(task->warp->mode, -1, task->warp->x << 8, task->warp->y << 8, task->warp->dir);
                }
                break;
            }
            break;
        }
        break;
    case TASK_DONE:
        if (FIELDSTG_state.battleStarting != 0) {
            FIELDSTG_playBattleTransition(task, children);
            break;
        }
        if (task->leaveDelay <= 0) {
            FIELDSTG_state.bannerShown = 1;
            FIELDSTG_closeField(task, children);
            break;
        }
        task->leaveDelay -= GFX.funcs.getFrameTime();
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates the field's main task */
Task *FIELDSTG_createField(void) {
    return createTaskWithId(FIELDSTG_updateField, sizeof(FieldTask), sizeof(FieldChildren), FIELD_TASK_FIELD);
}

/*
 * Leaves the field for a mode after a delay: the field task
 * (FIELD_TASK_FIELD) goes to TASK_DONE, which closes the field (FIELDSTG_closeField) and requests the
 * mode with its argument. The player comes back to the field at (x, y),
 * facing dir.
 */
void FIELDSTG_leaveFieldAfter(s32 mode, s32 arg, s32 x, s32 y, s32 dir, s32 delay) {
    FieldTask *task = TASK_REGISTRY.funcs.find(FIELD_TASK_FIELD, -1, -1);

    if (task != NULL) {
        task->nextMode = mode;
        task->nextModeArg = arg;
        task->leaveDelay = delay;
        task->setState(task, TASK_DONE);
        FIELDSTG_state.defaultStart.x = x;
        FIELDSTG_state.defaultStart.y = y;
        FIELDSTG_state.defaultStartDir = dir;
    }
}

/* Leaves the field for a mode now (the executable calls it by this name) */
void FIELDSTG_leaveField(s32 mode, s32 arg, s32 x, s32 y, s32 dir) {
    FIELDSTG_leaveFieldAfter(mode, arg, x, y, dir, 0);
}

/* The prize of a battle, an item: the common one, or the rare one when the
   roll is 0 */
#define PICK_PRIZE(common, rare)                                              \
    if (roll != 0) {                                                          \
        BATTLE_SETUP.prize = common;                                          \
    } else {                                                                  \
        BATTLE_SETUP.prize = rare;                                            \
    }

/*
 * Starts encounter FIELDSTG_encounters[encounter]: the field task
 * (FIELD_TASK_FIELD) leaves for the battle (MODE_BATTLE, after a movie in the chapter
 * FIELD_PROGRESS_MOVIE_BATTLES), and BATTLE_SETUP takes the encounter's
 * enemies and bytes. A battle led by one of the prize fighters always gives
 * an item, which the field's stage (named in each case by the stage its mode
 * loads, FIELDSTG_stages) and a roll pick: the rare item comes 1 in 32
 * times for the odd fighters and 1 in 16 for the even ones. In the European
 * version's extra chapter some stages give other items.
 */
void FIELDSTG_startEncounter(s32 encounter) {
    FieldTask *task = TASK_REGISTRY.funcs.find(FIELD_TASK_FIELD, -1, -1);
    s32 i;
    s32 next;
    s32 mode;
    s32 roll;

    if (task != NULL) {
        FIELDSTG_state.busy = 1;
        FIELDSTG_state.battleStarting = 1;
        next = MODE_BATTLE_MOVIE;
        if (GAME.progress != FIELD_PROGRESS_MOVIE_BATTLES) {
            next = MODE_BATTLE;
        }
        task->nextMode = next;
        task->nextModeArg = 0;
        task->setState(task, TASK_DONE);
        BATTLE_SETUP.battle = encounter;
        BATTLE_SETUP.ambushChance = FIELDSTG_encounters[encounter].ambushChance;
        BATTLE_SETUP.unk3D = FIELDSTG_encounters[encounter].unkD;
        for (i = 0; i < 12; i++) {
            BATTLE_SETUP.unk3E[i] = FIELDSTG_encounters[encounter].unkE[i];
        }
        for (i = 0; i < 3; i++) {
            BATTLE_SETUP.enemies[i] = *FIELDSTG_encounters[encounter].enemies[i];
        }
        BATTLE_SETUP.hasPrize = 0;
        if ((u32)(BATTLE_SETUP.enemies[0].fighter - FIELD_PRIZE_FIGHTERS) < FIELD_PRIZE_FIGHTER_COUNT) {
            BATTLE_SETUP.hasPrize = 1;
            mode = GAME.funcs.getMode();
            if (BATTLE_SETUP.enemies[0].fighter & 1) {
                roll = RANDOM.next() & 0x1F;
                switch (mode) {
                case 0x21D: /* WSTAG330 */
                default:
                    PICK_PRIZE(0x177, 0x186);
                    break;
                case 0x22A: /* WSTAG400 */
                    PICK_PRIZE(0x179, 0x186);
                    break;
                case 0x233: /* WSTAG445 */
                case 0x235: /* WSTAG455 */
                case 0x237: /* WSTAG465 */
                case 0x23A: /* WSTAG480 */
                case 0x23B: /* WSTAG485 */
                case 0x23C: /* WSTAG490 */
                case 0x24A: /* WSTAG565 */
                case 0x24C: /* WSTAG575 */
                    PICK_PRIZE(0x17A, 0x187);
                    break;
#if VERSION_EU
                case 0x28C: /* WSTAG331 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG940 */
                        PICK_PRIZE(0x17F, 0x188);
                    }
                    break;
                case 0x28D: /* WSTAG336 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG941 */
                        PICK_PRIZE(0x179, 0x186);
                    }
                    break;
                case 0x28E: /* WSTAG341 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG942 */
                        PICK_PRIZE(0x178, 0x186);
                    }
                    break;
                case 0x28F: /* WSTAG346 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG943 */
                        PICK_PRIZE(0x17E, 0x188);
                    }
                    break;
                case 0x290: /* WSTAG351 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG944 */
                        PICK_PRIZE(0x180, 0x189);
                    }
                    break;
                case 0x291: /* WSTAG356 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG945 */
                        PICK_PRIZE(0x181, 0x189);
                    }
                    break;
                case 0x296: /* WSTAG381 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG950 */
                        PICK_PRIZE(0x182, 0x189);
                    }
                    break;
                case 0x298: /* WSTAG396 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17C, 0x187);
                    } else { /* WSTAG952 */
                        PICK_PRIZE(0x183, 0x18A);
                    }
                    break;
                case 0x299: /* WSTAG401 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17F, 0x188);
                    } else { /* WSTAG953 */
                        PICK_PRIZE(0x185, 0x18A);
                    }
                    break;
#else
                case 0x28C: /* WSTAG331 */
                case 0x28D: /* WSTAG336 */
                case 0x28E: /* WSTAG341 */
                case 0x28F: /* WSTAG346 */
                case 0x290: /* WSTAG351 */
                case 0x291: /* WSTAG356 */
                case 0x296: /* WSTAG381 */
                case 0x298: /* WSTAG396 */
                    PICK_PRIZE(0x17C, 0x187);
                    break;
                case 0x299: /* WSTAG401 */
                    PICK_PRIZE(0x17F, 0x188);
                    break;
#endif
                case 0x2A1: /* WSTAG446 */
                case 0x2A3: /* WSTAG456 */
                case 0x2A4: /* WSTAG466 */
                case 0x2A7: /* WSTAG481 */
                case 0x2A8: /* WSTAG486 */
                case 0x2A9: /* WSTAG491 */
                    PICK_PRIZE(0x180, 0x189);
                    break;
                case 0x261: /* WSTAG690 */
                case 0x262: /* WSTAG695 */
                case 0x265: /* WSTAG710 */
                case 0x266: /* WSTAG715 */
                    PICK_PRIZE(0x181, 0x189);
                    break;
                case 0x2B4: /* WSTAG566 */
                case 0x2B6: /* WSTAG576 */
                case 0x2C9: /* WSTAG691 */
                case 0x2CA: /* WSTAG696 */
                case 0x2CD: /* WSTAG711 */
                case 0x2CE: /* WSTAG716 */
                    PICK_PRIZE(0x184, 0x18A);
                    break;
                }
            } else {
                roll = RANDOM.next() & 0xF;
                switch (mode) {
                case 0x201: /* WSTAG202 */
                default:
                    PICK_PRIZE(0x177, 0x186);
                    break;
                case 0x234: /* WSTAG450 */
                case 0x235: /* WSTAG455 */
                case 0x237: /* WSTAG465 */
                case 0x23A: /* WSTAG480 */
                case 0x23B: /* WSTAG485 */
                case 0x23C: /* WSTAG490 */
                case 0x23D: /* WSTAG495 */
                    PICK_PRIZE(0x178, 0x186);
                    break;
                case 0x247: /* WSTAG550 */
                case 0x249: /* WSTAG560 */
                case 0x24B: /* WSTAG570 */
                    PICK_PRIZE(0x17B, 0x187);
                    break;
#if VERSION_EU
                case 0x271: /* WSTAG203 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG921 */
                        PICK_PRIZE(0x177, 0x186);
                    }
                    break;
                case 0x28C: /* WSTAG331 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG940 */
                        PICK_PRIZE(0x17A, 0x187);
                    }
                    break;
                case 0x28D: /* WSTAG336 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG941 */
                        PICK_PRIZE(0x179, 0x186);
                    }
                    break;
                case 0x28E: /* WSTAG341 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG942 */
                        PICK_PRIZE(0x178, 0x186);
                    }
                    break;
                case 0x28F: /* WSTAG346 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG943 */
                        PICK_PRIZE(0x17B, 0x187);
                    }
                    break;
                case 0x290: /* WSTAG351 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG944 */
                        PICK_PRIZE(0x184, 0x18A);
                    }
                    break;
                case 0x296: /* WSTAG381 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG950 */
                        PICK_PRIZE(0x17C, 0x187);
                    }
                    break;
                case 0x299: /* WSTAG401 */
                    if (GAME.progress != FIELD_PROGRESS_EXTRA) {
                        PICK_PRIZE(0x17D, 0x188);
                    } else { /* WSTAG953 */
                        PICK_PRIZE(0x17D, 0x188);
                    }
                    break;
#else
                case 0x271: /* WSTAG203 */
                case 0x28C: /* WSTAG331 */
                case 0x28D: /* WSTAG336 */
                case 0x28E: /* WSTAG341 */
                case 0x28F: /* WSTAG346 */
                case 0x290: /* WSTAG351 */
                case 0x296: /* WSTAG381 */
                case 0x299: /* WSTAG401 */
                    PICK_PRIZE(0x17D, 0x188);
                    break;
#endif
                case 0x2A2: /* WSTAG451 */
                case 0x2A3: /* WSTAG456 */
                case 0x2A4: /* WSTAG466 */
                case 0x2A7: /* WSTAG481 */
                case 0x2A8: /* WSTAG486 */
                case 0x2A9: /* WSTAG491 */
                case 0x2AA: /* WSTAG496 */
                    PICK_PRIZE(0x17E, 0x188);
                    break;
                case 0x266: /* WSTAG715 */
                    PICK_PRIZE(0x182, 0x189);
                    break;
                case 0x2B1: /* WSTAG551 */
                case 0x2B3: /* WSTAG561 */
                case 0x2B5: /* WSTAG571 */
                    PICK_PRIZE(0x183, 0x18A);
                    break;
                case 0x2CE: /* WSTAG716 */
                    PICK_PRIZE(0x185, 0x18A);
                    break;
                }
            }
        }
    }
}

#undef PICK_PRIZE

/* Starts battle 5 of the fourth area: the end of the stages' events 9000 */
void *FIELDSTG_startEventBattle5(void) {
    Battle *battle = FIELDSTG_state.battles->battles[3]->battles[5];

    FIELDSTG_startBattle(battle);
    FLAGS_00.applyAction(FIELD_FLAG_ENCOUNTERED, 1);
    return NULL;
}

/* Starts the event FIELDSTG_eventIds[index] (the executable calls it) */
void FIELDSTG_startListedEvent(s32 index) {
    FieldChildren *children = ((Task *)TASK_REGISTRY.funcs.find(FIELD_TASK_FIELD, -1, -1))->children;

    children->event = FIELDSTG_startEvent(FIELDSTG_eventIds[index]);
}

/* Opens the inn: the field task waits for it (the executable calls it) */
void FIELDSTG_openInn(void) {
    FieldTask *task = TASK_REGISTRY.funcs.find(FIELD_TASK_FIELD, -1, -1);
    FieldChildren *children = task->children;

    FIELDSTG_state.innOpen = 1;
    FIELDSTG_state.busy = 1;
    children->unk10 = (Task *)createInn(FIELD_LAYER_MAP);
    task->setSubstate(task, 2);
}

/* Starts a warp from pos: the field task plays the effect and the cutscene
   of kind, then leaves for the warp's mode */
void FIELDSTG_startWarp(s32 kind, Point *pos, FieldWarp *warp) {
    FieldTask *task = TASK_REGISTRY.funcs.find(FIELD_TASK_FIELD, -1, -1);

    task->warpKind = kind;
    task->warpPos.x = pos->x;
    task->warpPos.y = pos->y;
    task->warp = warp;
    task->setSubstate(task, 3);
}
