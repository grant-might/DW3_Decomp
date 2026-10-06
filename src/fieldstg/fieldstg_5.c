/* The fifth object of FIELDSTG.PRO (see fieldstg.c): its rodata starts at
   0x800825E0 (USA). */

#include "fieldstg.h"
#include "stages.h"

s32 FIELDSTG_findTrigger(Triggers *task) {
    Actor *actor = task->actor;
    Point tile;
    u32 cell;
    s32 type;

    tile = actor->tile;
    cell = (u8)D_8009A70C.getCell(7, &tile);
    if (cell == 0) {
        return 0;
    }
    task->dir = cell >> 5;
    task->index = cell & 0x1F;
    task->entry = &task->entries[task->index];
    type = task->entry->type;
    switch (type) {
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 1;
    }
    return FIELDSTG_nearDirs[task->dir][actor->dir] != 0;
}

s32 FIELDSTG_offerTrigger(Triggers *task, TriggerChildren *children) {
#if VERSION_EU
    s32 arg;
#endif

    if (task->entry->conditions[0][0] != 0xFFFF
        && FLAGS_00.checkCondition(task->entry->conditions[0][0], task->entry->conditions[0][1]) == 0) {
        return 0;
    }
    if (task->entry->conditions[1][0] != 0xFFFF
        && FLAGS_00.checkCondition(task->entry->conditions[1][0], task->entry->conditions[1][1]) == 0) {
        return 0;
    }
    switch (task->entry->type) {
        case 5:
            task->actor->depth = task->entry->unkA;
            GAME.unk26E0 = task->entry->unkA;
            return 0;
        case 6:
            D_8009A70C.unk54(task->entry->unkA);
            return 0;
        case 8:
            if (children->script == NULL) {
                children->script = FIELDSTG_startEvent(task->entry->unkA);
            }
            return 0;
        case 11:
            task->actor->startSlide(task->actor, task->dir);
            return 0;
        case 12:
            task->actor->stopSlide(task->actor);
            return 0;
        case 13:
            task->actor->launch(task->actor, &task->entry->unkA);
            return 0;
    }
#if VERSION_US
    if (children->balloon != NULL) {
        children->balloon->setState(children->balloon, 1);
        return 1;
    }
    switch (task->entry->type) {
        default:
            children->balloon = FIELDSTG_createBalloon(0, 0, 6);
            break;
        case 2:
        case 3:
            children->balloon = FIELDSTG_createBalloon(0, 2, 6);
            break;
        case 4:
            children->balloon = FIELDSTG_createBalloon(0, 4, 6);
            break;
        case 7:
            children->balloon = FIELDSTG_createBalloon(0, 5, 6);
            break;
        case 1:
            if (task->dir == 4) {
                children->balloon = FIELDSTG_createBalloon(0, 10, 6);
            } else {
                children->balloon = FIELDSTG_createBalloon(0, (task->dir >> 1) + 6, 6);
            }
            break;
    }
#elif VERSION_EU
    /* the European version restarts a running animation on the new row */
    switch (task->entry->type) {
        default:
            arg = 0;
            break;
        case 2:
        case 3:
            arg = 2;
            break;
        case 4:
            arg = 4;
            break;
        case 7:
            arg = 5;
            break;
        case 1:
            if (task->dir == 4) {
                arg = 10;
            } else {
                arg = (task->dir >> 1) + 6;
            }
            break;
    }
    if (children->balloon != NULL) {
        children->balloon->setState(children->balloon, 1);
        children->balloon->key2 = arg;
        children->balloon->frame = 0;
        children->balloon->time = 0;
    } else {
        children->balloon = FIELDSTG_createBalloon(0, arg, 6);
    }
#endif
    return 1;
}

const Point D_80082624 = {0, 0};

void FIELDSTG_setOffTrigger(Triggers *task) {
    StageTile *object;
    s32 id;

    switch (task->entry->type) {
        case 1:
            task->actor->walkInDir(task->actor, task->dir);
            func_8008AEB4(task->entry->unkA, -1, task->entry->unkC << 8, task->entry->unkE << 8, task->entry->unk10);
            if (task->entry->unk12 != 0) {
                object = D_800990B4.objects;
                id = task->entry->unk12;
                for (; object->unk2 != 0; object++) {
                    if (object->anim == id) {
                        object->visible = 0;
                    }
                }
            }
            GAME.unk44 = task->entry->unk14;
            GAME.unk46 = task->entry->unk16;
            break;
        case 14:
            task->actor->launch(task->actor, &task->entry->unkA);
            FIELDSTG_leaveFieldAfter(task->entry->unkA, -1, task->entry->unkC << 8, task->entry->unkE << 8, task->entry->unk10,
                          0x3C);
            break;
        case 2:
            task->actor->climbUp(task->actor, task->dir, task->entry->unkC, task->entry->unkE,
                                (task->entry->unkA - 1) * 16);
            break;
        case 3:
            task->actor->climbDown(task->actor, task->dir == 1 ? 5 : 3, task->entry->unkC, task->entry->unkE,
                                (task->entry->unkA - 1) * 16);
            break;
        case 4:
            task->actor->dropDown(task->actor, task->dir, D_80082624, task->entry->unkA * 16);
            break;
        case 7:
            task->actor->playGauge(task->actor, task->dir, (Point){task->entry->unkA, task->entry->unkC});
            break;
        case 10:
            task->actor->warp(task->actor, &task->entry->unkA, 0);
            break;
        case 9:
            task->actor->warp(task->actor, &task->entry->unkA, 1);
            break;
    }
}

void FIELDSTG_updateTriggers(Triggers *task, TriggerChildren *children) {
    task->entries = D_800990B4.slots;
    switch (task->state) {
        default:
        case 0:
            task->actor = TASK_REGISTRY.funcs.find(5, -1, 0);
            if (task->actor != NULL) {
                task->nextState(task);
            }
            break;
        case 1:
            if (D_800990B4.busy != 0 || D_800990B4.bannerShown != 0) {
                break;
            }
            switch (task->substate) {
                default:
                case 0:
                    if (FIELDSTG_findTrigger(task) != 0 && FIELDSTG_offerTrigger(task, children) != 0) {
                        task->nextSubstate(task);
                    }
                    break;
                case 1:
                    if (FIELDSTG_findTrigger(task) == 0) {
                        task->setSubstate(task, 0);
                        children->balloon->setState(children->balloon, 2);
                    } else if ((PAD.getPressed(0) & 0x2000) && D_800990B4.bannerShown == 0) {
                        children->balloon->setState(children->balloon, 3);
                        FIELDSTG_setOffTrigger(task);
                        task->nextSubstate(task);
                    }
                    break;
                case 2:
                    if (task->actor->substate < 5) {
                        task->setSubstate(task, 0);
                    }
                    break;
            }
            break;
        case 2:
        case 3:
            break;
    }
}

Triggers *FIELDSTG_createTriggers(s32 arg0, void *entries) {
    Triggers *task = createTask(FIELDSTG_updateTriggers, sizeof(Triggers), 8);

    task->unk50 = arg0;
    return task;
}

void FIELDSTG_getSpeechPos(Speech *task, Point *out) {
    Point pos;

    pos.x = task->actor->tile.x;
    pos.y = task->actor->tile.y;
    if (task->actor->key1 == 0xD6) {
        pos.y -= 0x15;
    }
    FIELDSTG_scriptHelpers[0](&pos);
    if (task->type == 2 || task->type == 3) {
        pos.x -= 0xB;
    } else {
        pos.x += 0xB;
    }
    if (task->type == 0 || task->type == 2) {
        pos.y -= 0x13;
    } else {
        pos.y -= 7;
    }
    *out = pos;
}

void FIELDSTG_updateSpeech(Speech *task, void **box) {
    Point pos;
    Point newPos;
    TalkBox *talkBox;

    switch (task->state) {
    case 0:
    default:
        if (task->isMessage != 0) {
            *box = createMessageBox(0x1004, task->text, task->entry);
        } else {
            FIELDSTG_getSpeechPos(task, &pos);
            *box = createTalkBox(0x1004, pos.x, pos.y, task->text, task->entry, task->type);
        }
        task->nextState(task);
        break;
    case 1:
        if (*box == NULL) {
            task->setState(task, 3);
        } else if (task->isMessage == 0) {
            FIELDSTG_getSpeechPos(task, &newPos);
            talkBox = *box;
            talkBox->setPos(talkBox, newPos.x, newPos.y);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Speech *FIELDSTG_createSpeech(Actor *actor, s32 entry, s32 type, s32 isMessage) {
    Speech *task = createTask(FIELDSTG_updateSpeech, sizeof(Speech), 4);

    task->actor = actor;
    task->entry = entry;
    task->type = type;
    task->isMessage = isMessage;
    task->text = FILE_CACHE.getEntry(D_800990B4.eventText);
    return task;
}

Speech *FIELDSTG_createTalk(Actor *actor, s32 entry) {
    Speech *task = createTask(FIELDSTG_updateSpeech, sizeof(Speech), 4);
    Point pos;

    task->actor = actor;
    task->entry = entry;
    task->text = (s32)FILE_CACHE.load(D_800990B4.textFile);
    pos = actor->tile;
    FIELDSTG_scriptHelpers[0](&pos);
    switch (actor->dir) {
        case 0:
        case 1:
        case 2:
        case 6:
        case 7:
        default:
            if (pos.x >= 0xA0) {
                task->type = 0;
            } else {
                task->type = 2;
            }
            break;
        case 3:
        case 4:
        case 5:
            if (pos.x >= 0xA0) {
                task->type = 1;
            } else {
                task->type = 3;
            }
            break;
    }
    switch (task->type) {
        case 0:
            if (pos.y < 0x79) {
                task->type = 1;
            }
            break;
        case 2:
            if (pos.y < 0x79) {
                task->type = 3;
            }
            break;
        case 1:
            if (pos.y >= 0xAC) {
                task->type = 0;
            }
            break;
        case 3:
            if (pos.y >= 0xAC) {
                task->type = 2;
            }
            break;
    }
    task->isMessage = 0;
    return task;
}

void FIELDSTG_drawMapObject(MapObjects *task, Layer *layer, s32 index) {
    StageTile *object = &task->objects[index];
    SpriteDrawer sprite;

    if (task->state == 1) {
        initSpriteDrawer(&sprite);
        sprite.setAltClut(0, 0x1F0);
        sprite.setLayer(layer, object->depth);
        if (object->anim != 0xFF) {
            sprite.setTexture(0x140, 0x100);
            sprite.setClutRow(object->clutRow);
            if (D_800990B4.spriteColor.cd != 0) {
                sprite.setColor(&D_800990B4.spriteColor);
            }
            sprite.draw(FILE_CACHE.getEntry(task->sprites), object->frame, object->x, object->y);
        } else {
            sprite.setTexture(0x200, 0x100);
            sprite.setClutRow(object->clutRow);
            sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16), object->frame, object->x, object->y);
        }
    }
}

/* Animates and draws the map's objects that are in view */
void FIELDSTG_updateMapObjects(MapObjects *task, HiddenSpots **children) {
    StageTile *object;
    StageTile *entry;
    Layer *layer;
    SpriteDrawer sprite;
    RECT view;
    s32 count;
    s32 i;
    s32 x;
    s32 y;
    u8 margin;
    s32 back;

    switch (task->state) {
    case 0:
    default:
        count = 0;
        for (entry = task->objects; entry->y != 0; entry++) {
            if (entry->anim == 0xFF) {
                count++;
            }
        }
        if (count != 0) {
            *children = FIELDSTG_createHiddenSpots(count);
        }
        task->nextState(task);
        break;
    case 1:
        object = task->objects;
        layer = GFX.funcs.getLayer(0x1002);
        layer->getViewRect(layer, &view);
        initSpriteDrawer(&sprite);
        sprite.setTexture(0x140, 0x100);
        sprite.setAltClut(0, 0x1F0);
        for (i = 0; object->unk2 != 0; object++, i++) {
            if (object->visible == 0) {
                continue;
            }
            x = object->anim == 0xFF ? object->x - 50 : object->x;
            y = object->anim == 0xFF ? object->y - 100 : object->y;
            margin = object->unk2;
            if (x >= view.x - margin && view.x + view.w >= x && y >= view.y - margin && view.y + view.h >= y) {
                switch (object->cycle) {
                case 1:
                    if (object->cycleTime < 0x100) {
                        object->frame++;
                        if (object->frame > object->cycleLast) {
                            object->frame = object->cycleFirst;
                        }
                        object->cycleTime = object->cycleDelay << 8;
                    } else {
                        object->cycleTime -= 0x100;
                    }
                    break;
                case 2:
                    if (object->cycleTime < 0x100) {
                        object->clutRow++;
                        if (object->clutRow > object->cycleLast) {
                            object->clutRow = object->cycleFirst;
                        }
                        object->cycleTime = object->cycleDelay << 8;
                    } else {
                        object->cycleTime -= 0x100;
                    }
                    break;
                case 3:
                    if (object->cycleTime & 0x8000) {
                        back = 0x8000;
                        object->cycleTime &= 0x7FFF;
                        if (object->cycleTime < 0x100) {
                            object->clutRow--;
                            object->cycleTime = object->cycleDelay << 8;
                            if (object->clutRow == (u8)(object->cycleFirst - 1)) {
                                object->clutRow = object->cycleFirst + 1;
                                back = 0;
                            }
                        } else {
                            object->cycleTime -= 0x100;
                        }
                        object->cycleTime |= back;
                    } else if (object->cycleTime < 0x100) {
                        object->clutRow++;
                        object->cycleTime = object->cycleDelay << 8;
                        if (object->clutRow == object->cycleLast + 1) {
                            object->clutRow = object->cycleLast - 1;
                            object->cycleTime |= 0x8000;
                        }
                    } else {
                        object->cycleTime -= 0x100;
                    }
                    break;
                }
                if (object->unkE != 0) {
                    layer->addSortedCallback(layer, FIELDSTG_drawMapObject, task, object->unkE, i);
                } else {
                    sprite.setLayerId(0x1002, object->depth);
                    sprite.setClutRow(object->clutRow);
                    if (D_800990B4.spriteColor.cd != 0) {
                        sprite.setColor(&D_800990B4.spriteColor);
                    }
                    sprite.draw(FILE_CACHE.getEntry(task->sprites), object->frame, object->x, object->y);
                }
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

MapObjects *FIELDSTG_createMapObjects(s32 sprites, StageTile *objects) {
    MapObjects *task = createTask(FIELDSTG_updateMapObjects, sizeof(MapObjects), 4);

    task->objects = objects;
    task->sprites = sprites;
    return task;
}

StageTile *FIELDSTG_findNextObject(void) {
    StageTile *entry = FIELDSTG_objectCursor;
    s32 found = 0;

    for (; entry->unk2 != 0; entry++) {
        if (entry->anim == FIELDSTG_objectId) {
            found = 1;
            break;
        }
    }
    FIELDSTG_objectCursor = entry + 1;
    if (found) {
        return entry;
    }
    return NULL;
}

StageTile *FIELDSTG_findObject(s32 anim) {
    FIELDSTG_objectId = anim;
    FIELDSTG_objectCursor = D_800990B4.objects;
    return FIELDSTG_findNextObject();
}

/* The task (FIELDSTG_loadFieldFiles's) goes unused */
void FIELDSTG_requestInnNames(Task *task) {
    s32 mode = GAME.funcs.getMode();
    s32 found = 0;
    s32 i;

    for (i = 0; FIELDSTG_file5DModes[i] != 0; i++) {
        if (FIELDSTG_file5DModes[i] == (s16)mode) {
            found = 1;
            break;
        }
    }
    if (found) {
        FILE_CACHE.request(TEXT_FILE(TEXT_INN_NAMES));
    }
}

/* The task (FIELDSTG_loadFieldFiles's) goes unused */
void FIELDSTG_requestSlotFiles(Task *task) {
    StageSlot *entry = D_800990B4.slots;
    s32 loadFile3 = 0;
    s32 loadFile0 = 0;
    s32 loadFile1 = 0;

    for (; entry->type != 0; entry++) {
        switch (entry->type) {
        case 2:
        case 3:
            loadFile3 = 1;
            break;
        case 4:
            loadFile0 = 1;
            break;
        case 7:
            loadFile1 = 1;
            break;
        }
    }
    if (loadFile3) {
        FILE_CACHE.request(FIELD_EXIT_FILES + 3);
    }
    if (loadFile0) {
        FILE_CACHE.request(FIELD_EXIT_FILES);
    }
    if (loadFile1) {
        FILE_CACHE.request(FIELD_EXIT_FILES + 1);
    }
}

/* Loads the field's files, a step at a time: 1 once done */
s32 FIELDSTG_loadFieldFiles(Task *task) {
    TimLoader sprites;
    TimLoader loader;

    switch (task->step) {
    case 0:
        switch (task->counter) {
        case 0:
        default:
            FILE_CACHE.request(FIELD_SPRITES_FILE);
            task->tickCounter(task);
        case 1:
            if (FILE_CACHE.isLoading(FIELD_SPRITES_FILE) != 0) {
                return 0;
            }
            initTimLoader(&sprites);
            sprites.setImagePos(0x200, 0x100);
            sprites.loadArchive(FILE_CACHE.getEntry((FIELD_SPRITES_FILE << 16) | 2));
            sprites.setImagePos(0x240, 0x100);
            sprites.loadArchive(FILE_CACHE.getEntry((FIELD_SPRITES_FILE << 16) | 3));
            task->nextStep(task);
            break;
        }
        break;
    case 1:
        switch (task->counter) {
        case 0:
        default:
            if (D_800990B4.imageEntry == 0 && D_800990B4.imageFile == 0) {
                task->nextStep(task);
                break;
            }
            if (D_800990B4.imageEntry != 0) {
                FILE_CACHE.request(D_800990B4.imageEntry >> 16);
            }
            if (D_800990B4.sheetEntry != 0) {
                FILE_CACHE.request(D_800990B4.sheetEntry >> 16);
            }
            if (D_800990B4.imageFile != 0) {
                FILE_CACHE.request(D_800990B4.imageFile);
            }
            task->tickCounter(task);
        case 1:
            if (D_800990B4.imageEntry != 0) {
                if (FILE_CACHE.isLoading(D_800990B4.imageEntry >> 16) != 0) {
                    return 0;
                }
                initTimLoader(&loader);
                loader.setClutPos(0, 0x1F0);
                loader.setImagePos(0x140, 0x100);
                loader.loadArchive(FILE_CACHE.getEntry(D_800990B4.imageEntry));
            }
            task->tickCounter(task);
        case 2:
            if (D_800990B4.imageFile != 0) {
                if (FILE_CACHE.isLoading(D_800990B4.imageFile) != 0) {
                    return 0;
                }
                initTimLoader(&loader);
                loader.setClutPos(0, 0x1F0);
                loader.setImagePos(0x140, 0x100);
                loader.loadArchive(FILE_CACHE.load(D_800990B4.imageFile));
            }
            task->tickCounter(task);
        case 3:
            if (D_800990B4.sheetEntry != 0 && FILE_CACHE.isLoading(D_800990B4.sheetEntry >> 16) != 0) {
                return 0;
            }
            task->nextStep(task);
            break;
        }
        break;
    case 2:
        if (D_800990B4.imageFile != 0) {
            FILE_CACHE.free(D_800990B4.imageFile);
        }
        task->nextStep(task);
    case 3:
        FILE_CACHE.request(FILE_MENU_SPRITES);
        FILE_CACHE.request(D_800990B4.textFile);
        FILE_CACHE.request(TEXT_FILE(TEXT_STATUS));
        FIELDSTG_requestSlotFiles(task);
        FIELDSTG_requestInnNames(task);
        task->nextStep(task);
        return 1;
    default:
        return 1;
    }
    return 0;
}

void FIELDSTG_runFileLoader(Task *task) {
    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        task->substate = task->key2;
    case 1:
        if (FIELDSTG_loadFieldFiles(task) != 0) {
            task->setState(task, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Task *FIELDSTG_createFileLoader(s32 arg0) {
    Task *task = createTask(FIELDSTG_runFileLoader, 0x54, 0);

    task->key2 = arg0;
    return task;
}

void FIELDSTG_updateActorIcon(ActorIcon *task) {
    SpriteDrawer sprite;
    Point pos;
    u8 (*anim)[2];
    Actor *actor;
    s32 step;
    s32 time;

    switch (task->state) {
    default:
    case 0:
        task->nextState(task);
    case 1:
        if (task->step == 0) {
            task->anim = FIELDSTG_actorAnims[task->substate];
            task->animStep = 0;
            task->animTime = 0;
            switch (task->substate) {
            case 1:
            case 3:
                SOUND.playSound(0x40009);
                break;
            }
            task->nextStep(task);
        }
        if (task->actor != NULL && task->actor->state == 1) {
            step = task->animStep;
            time = task->animTime;
            time += GFX.funcs.getFrameTime();
            anim = task->anim;
            if (anim[step][1] < time) {
                time -= anim[step][1];
                step++;
                if (anim[step][0] == 0xFF) {
                    step = anim[step][1];
                }
                task->frame = anim[step][0];
                task->animStep = step;
            }
            task->animTime = time;
            actor = task->actor;
            switch (actor->substate) {
            case 0x45:
                if (actor->climbSide != 0) {
                    pos.x = actor->tile.x + FIELDSTG_actorPath[FIELDSTG_actorPathStep][0];
                } else {
                    pos.x = actor->tile.x - FIELDSTG_actorPath[FIELDSTG_actorPathStep][0];
                }
                pos.y = actor->tile.y + FIELDSTG_actorPath[FIELDSTG_actorPathStep][1];
                if (FIELDSTG_actorPath[FIELDSTG_actorPathStep + 1][0] != 0) {
                    FIELDSTG_actorPathStep++;
                }
                break;
            case 0x44:
                if (FIELDSTG_actorPathStep == 0) {
                    FIELDSTG_actorPathStep = 0xE;
                }
                if (actor->climbSide != 0) {
                    pos.x = actor->tile.x + FIELDSTG_actorPath[FIELDSTG_actorPathStep][0];
                } else {
                    pos.x = actor->tile.x - FIELDSTG_actorPath[FIELDSTG_actorPathStep][0];
                }
                pos.y = actor->tile.y + FIELDSTG_actorPath[FIELDSTG_actorPathStep][1];
                if (FIELDSTG_actorPathStep != 1) {
                    FIELDSTG_actorPathStep--;
                }
                break;
            default:
                pos.x = actor->tile.x;
                FIELDSTG_actorPathStep = 0;
                pos.y = actor->tile.y;
                break;
            }
            initSpriteDrawer(&sprite);
            sprite.setTexture(0x200, 0x100);
            sprite.setLayerId(0x1002, 2);
            sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16), task->frame, pos.x, pos.y);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

ActorIcon *FIELDSTG_createActorIcon(Actor *actor) {
    ActorIcon *task;

    if (GAME.funcs.getMode() < 0x2D7) {
        task = createTaskWithId(FIELDSTG_updateActorIcon, sizeof(ActorIcon), 0, 0x16);
        task->actor = actor;
        return task;
    }
    return NULL;
}

/*
 * The field's battle transition: the screen breaks into 30 tiles that slide
 * off in a spiral (FIELDSTG_tileMoves, one move per counter step), then it
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
        setRECT(&FIELDSTG_screenRect, 0, 0, 320, 240);
        MoveImage(&FIELDSTG_screenRect, 0x280, 0);
        layer = GFX.funcs.getLayer(0x1000);
        layer->setBgColor(layer, 0, 0, 0);
        layer = GFX.funcs.getLayer(0x1002);
        layer->setBgColor(layer, 0, 0, 0);
        GAME.fieldMode = GAME.funcs.getMode();
        GAME.fieldPos = ((Actor *)children[6])->pos;
        GAME.fieldDir = ((Actor *)children[6])->dir;
        for (row = 0; row < 6; row++) {
            for (col = 0; col < 5; col++) {
                FIELDSTG_tiles[col][row].x = col * 64;
                FIELDSTG_tiles[col][row].y = row * 40;
            }
        }
        SOUND.stopAll();
        SOUND.playSound(0x40005);
        for (k = 0; k < task->childCount; k++) {
            if (*children != NULL) {
                (*children)->setState(*children, 3);
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
        layer = GFX.funcs.getLayer(0x1002);
        ot = (u_long *)layer->getOtEntry(layer, 0);
        speed = GFX.funcs.getFrameTime() * 40;
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
                    *move->value = 0x200;
                    task->tickCounter(task);
                }
            } else {
                FIELDSTG_tiles[2][3].x = 0x200;
                if (++task->step >= 0x10) {
                    if (task->step < 0x1000) {
                        GAME.funcs.requestMode(task->nextMode, task->nextModeArg);
                    }
                    task->step = 0x1000;
                }
            }
        } while (0);
        if (task->step != 0x1000) {
            poly = GFX.funcs.getPrim();
            setRGB0((POLY_F4 *)poly, 0x10, 0x10, 0x10);
            setPolyF4((POLY_F4 *)poly);
            setSemiTrans((POLY_F4 *)poly, 1);
            ((POLY_F4 *)poly)->x0 = 0;
            ((POLY_F4 *)poly)->x1 = 320;
            ((POLY_F4 *)poly)->x2 = 0;
            ((POLY_F4 *)poly)->x3 = 320;
            ((POLY_F4 *)poly)->y0 = 0;
            ((POLY_F4 *)poly)->y1 = 0;
            ((POLY_F4 *)poly)->y2 = 240;
            ((POLY_F4 *)poly)->y3 = 240;
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((POLY_F4 *)poly + 1);
            setDrawTPage((DR_TPAGE *)poly, 0, 1, getTPage(0, 2, 320, 0));
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((DR_TPAGE *)poly + 1);
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 5; j++) {
                    if (FIELDSTG_tiles[j][i].x != 0x200 && FIELDSTG_tiles[j][i].y != 0x200) {
                        setPolyFT4(poly);
                        setSemiTrans(poly, 1);
                        setRGB0(poly, 0x80, 0x80, 0x80);
                        x = FIELDSTG_tiles[j][i].x;
                        poly->x0 = poly->x2 = x;
                        poly->x1 = poly->x3 = x + 64;
                        y = FIELDSTG_tiles[j][i].y;
                        poly->u0 = 0;
                        poly->u1 = 64;
                        poly->u2 = 0;
                        poly->u3 = 64;
                        poly->v0 = i * 40;
                        poly->v1 = i * 40;
                        poly->v2 = i * 40 + 40;
                        poly->v3 = i * 40 + 40;
                        poly->y0 = poly->y1 = y;
                        poly->y2 = poly->y3 = y + 40;
                        poly->tpage = getTPage(2, 0, 0x280 + j * 64, 0);
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
        player = TASK_REGISTRY.funcs.find(5, -1, 0);
        if (player != NULL && player->tile.x != 0) {
            task->unk6C = 1;
        } else {
            task->unk6C = 0;
        }
        task->width = 0x140;
        task->fade = 0;
        task->height = 0xF0;
        task->nextSubstate(task);
    case 1:
        layer = GFX.funcs.getLayer(0x1002);
        layer->setBgColor(layer, 1, 1, 1);
        task->width -= 10;
        task->height -= 7;
        if (task->width <= 0) {
            layer->setBgColor(layer, 0, 0, 0);
            task->width = 0;
            task->height = 0;
            task->nextSubstate(task);
        }
        actor = TASK_REGISTRY.funcs.find(5, -1, 0);
        layer->getScroll(layer, &clip);
        if (task->unk6C != 0) {
            clip.x = actor->tile.x - clip.x;
            clip.y = actor->tile.y - clip.y;
        } else {
            clip.x = 0xA0;
            clip.y = 0x78;
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
        if (clip.x + width > 0x140) {
            width = 0x140 - clip.x;
        }
        if (clip.y + height > 0xF0) {
            height = 0xF0 - clip.y;
        }
        layer->setClipSize(layer, width, height);
        func_80086460(0x1001, task->fade);
        if (task->fade != 0x8000) {
            task->fade += 0x400;
        }
        break;
    case 2:
        layer = GFX.funcs.getLayer(0x1001);
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
        layer->setClipSize(layer, (0xA0 - task->width) * 2, (0x78 - task->height) * 2);
        if (task->width > 0xA0) {
            GAME.funcs.requestMode(task->nextMode, task->nextModeArg);
            GAME.fieldMode = GAME.funcs.getMode();
            GAME.fieldPos = children->actors[0]->pos;
            GAME.fieldDir = children->actors[0]->dir;
            task->nextSubstate(task);
        }
        func_80086460(0x1001, 0x8000);
        break;
    case 3:
        break;
    }
}

s32 func_8008A0F4(void) {
    if (GAME.funcs.getMode() == 0x22D) {
        return 1;
    }
    return GAME.funcs.getMode() == 0x2DE;
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
void func_8008A154(FieldTask *task, FieldChildren *children) {
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
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            if (func_8008A0F4() == 0) {
                FILE_CACHE.freeFrom(0x8015C674);
            }
            GFX.funcs.reset();
            GFX.funcs.allocPrimBuffers(0x6400);
            GFX.funcs.setDisplayMode(0x140, 0xF0, 0, 0);
            rect.x = 0;
            rect.y = 0;
            rect.w = 0x140;
            rect.h = 0xF0;
            layer = GFX.funcs.createLayer(&rect, 1, 0x1000);
            layer->setBgColor(layer, 1, 1, 1);
            GFX.funcs.createLayer(&rect, 1, 0x1001);
            layer = GFX.funcs.createLayer(&rect, 4, 0x1002);
            layer->allocCallbacks(layer, 0x32);
            GFX.funcs.createLayer(&rect, 1, 0x1004);
            layer = GFX.funcs.createLayer(&rect, 1, 0x1003);
            layer->setBgColor(layer, 1, 1, 1);
            if (func_8008A0F4() == 0) {
                task->unk64 = HEAP.allocHigh(0x9615C, 2);
            }
            if (GAME.clearTempFlags == 0) {
                FILE_CACHE.touchMarked();
            }
            D_8009A70C.setFile(4, 0);
            D_800990B4.init();
            if (D_800990B4.stageFile != 0) {
                OVERLAY_LOADER.loadSubOverlay(D_800990B4.stageFile);
            }
            if (D_800990B4.stageInit != NULL) {
                children->stage = D_800990B4.stageInit(task);
            }
            FLAGS_00.updateModeFlags();
            FLAGS_00.applyAction(GAME.funcs.getMode() + 0x1E00, 1);
            mode = GAME.funcs.getPrevMode();
            if ((mode & 0xFF00) != 0x200 && (mode & 0xFF00) != 0x300 && (mode & 0xFF00) != 0xE00 &&
                mode != 0x1500 && mode != 0x500) {
                GAME.modeArg = -1;
                D_800990B4.defaultStart = GAME.fieldPos;
                D_800990B4.defaultStartDir = GAME.fieldDir;
            }
            children->banner = FIELDSTG_createBanner(1);
            task->nextSubstate(task);
        case 1:
            switch (task->step) {
            case 0:
            default:
                if (D_800990B4.soundBank != 0) {
                    SOUND.loadBank(D_800990B4.soundBank);
                }
                task->nextStep(task);
            case 1:
                if (SOUND.isLoading() == 0) {
                    if (D_800990B4.music != 0) {
                        SOUND.playSound(D_800990B4.music);
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
            if (D_800990B4.objects != NULL) {
                children->mapObjects = FIELDSTG_createMapObjects(D_800990B4.sheetEntry, D_800990B4.objects);
            }
            if (D_800990B4.slots != NULL) {
                children->triggers = FIELDSTG_createTriggers(D_800990B4.sheetEntry, D_800990B4.slots);
            }
            do {
                list = D_800990B4.actors;
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
                children->actors[0] = FIELDSTG_createActor(2, 0, 0, NULL);
                if (GAME.progress >= 3) {
                    if (GAME.funcs.getPartyPartner(0) >= 0) {
                        children->actors[1] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(0) + 3, 2, 1, NULL);
                    }
                    if (GAME.funcs.getPartyPartner(1) >= 0) {
                        children->actors[2] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(1) + 3, 4, 2, NULL);
                    }
                    if (GAME.funcs.getPartyPartner(2) >= 0) {
                        children->actors[3] = FIELDSTG_createActor(GAME.funcs.getPartyPartner(2) + 3, 8, 3, NULL);
                    }
                }
            } while (0);
            npcList = D_800990B4.actors;
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
            if (func_8008A0F4() == 0) {
                switch (task->step) {
                case 0:
                default:
                    if (CD_READER.isBusy() != 0) {
                        break;
                    }
                    if (task->unk64 != NULL) {
                        HEAP.free(task->unk64);
                    }
                    children->mapStreamer = FIELDSTG_createMapStreamer(D_800990B4.mapFile);
                    task->nextStep(task);
                case 1:
                    if (children->mapStreamer->state == 1 && children->banner->state == 2) {
                        children->banner->setSubstate(children->banner, 1);
                        task->nextState(task);
                    }
                    break;
                }
            } else if (children->banner->state == 2) {
                children->banner->setSubstate(children->banner, 1);
                task->nextState(task);
            }
            break;
        }
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            if (D_800990B4.innOpen != 1 && D_800990B4.busy == 0 && D_800990B4.acting == 0) {
                do {
                    if (GAME.progress < 4 || !(PAD.getPressed(0) & (1 << PAD_START))) {
                        break;
                    }
                    D_800990B4.innOpen = 1;
                    D_800990B4.busy = 1;
                    children->menu = createFieldMenu(0x1002, 0);
                    GAME.fieldMode = GAME.funcs.getMode();
                    GAME.fieldPos = children->actors[0]->pos;
                    GAME.fieldDir = children->actors[0]->dir;
                    children->actors[0]->setSubstate(children->actors[0], 1);
                    FILE_CACHE.markCached();
                    task->nextSubstate(task);
                } while (0);
            }
            break;
        case 1:
            if (children->menu == NULL) {
                D_800990B4.innOpen = 0;
                D_800990B4.busy = 0;
                task->setSubstate(task, 0);
            }
            break;
        case 2:
            if (children->unk10 == NULL) {
                D_800990B4.innOpen = 0;
                D_800990B4.busy = 0;
                task->setSubstate(task, 0);
            }
            break;
        case 3:
            switch (task->step) {
            case 0:
            default:
                children->effect = FIELDSTG_createEffect(task->unk74.x, task->unk74.y, task->unk70);
                SOUND.playSound(0x40004);
                task->nextStep(task);
            case 1:
                if (task->counter < 0x3C) {
                    task->counter += GFX.funcs.getFrameTime();
                    break;
                }
                children->fade = createScreenFade(0x1002);
                children->fade->start(children->fade, 0, 0x14);
                task->nextStep(task);
            case 2:
                if (children->fade->state == 2) {
                    for (i = 0; i < 4; i++) {
                        if (children->actors[i] != NULL) {
                            children->actors[i]->setState(children->actors[i], 3);
                        }
                    }
                    for (i = 0; i < 15; i++) {
                        if (children->npcs[i] != NULL) {
                            children->npcs[i]->setState(children->npcs[i], 3);
                        }
                    }
                    children->mapStreamer->setState(children->mapStreamer, 3);
                    children->mapObjects->setState(children->mapObjects, 3);
                    children->cutscene = FIELDSTG_createCutsceneAnim(task->unk70);
                    children->fade->start(children->fade, 1, 0x14);
                    task->nextStep(task);
                }
                break;
            case 3:
                if (children->cutscene->state == 2) {
                    GAME.unk44 = task->unk7C->unkA;
                    GAME.unk46 = task->unk7C->unkC;
                    func_8008AEB4(task->unk7C->mode, -1, task->unk7C->x << 8, task->unk7C->y << 8, task->unk7C->dir);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        if (D_800990B4.battleStarting != 0) {
            FIELDSTG_playBattleTransition(task, children);
            break;
        }
        if (task->unk68 <= 0) {
            D_800990B4.bannerShown = 1;
            FIELDSTG_closeField(task, children);
            break;
        }
        task->unk68 -= GFX.funcs.getFrameTime();
        break;
    case 3:
        break;
    }
}

Task *func_8008ADE8(void) {
    return createTaskWithId(func_8008A154, 0x80, 0x7C, 7);
}

/*
 * Leaves the field for a mode after a delay: the field task (id 7) goes to
 * state 2, which closes the field (FIELDSTG_closeField) and requests the
 * mode with its argument. The player comes back to the field at (x, y),
 * facing dir.
 */
void FIELDSTG_leaveFieldAfter(s32 mode, s32 arg, s32 x, s32 y, s32 dir, s32 delay) {
    FieldTask *task = TASK_REGISTRY.funcs.find(7, -1, -1);

    if (task != NULL) {
        task->nextMode = mode;
        task->nextModeArg = arg;
        task->unk68 = delay;
        task->setState(task, 2);
        D_800990B4.defaultStart.x = x;
        D_800990B4.defaultStart.y = y;
        D_800990B4.defaultStartDir = dir;
    }
}

/* Leaves the field for a mode now (the executable calls it by this name) */
void func_8008AEB4(s32 mode, s32 arg, s32 x, s32 y, s32 dir) {
    FIELDSTG_leaveFieldAfter(mode, arg, x, y, dir, 0);
}

/*
 * Starts encounter FIELDSTG_encounters[encounter]: the field task (id 7) goes to state 2
 * with mode 0x600, or 0xE0A (USA 0xE09) at GAME.progress 0x2B, and
 * BATTLE_SETUP takes the encounter's enemies and bytes. Enemies 0x1C9-0x1D0
 * always give an item (unk50), which the field mode and a roll pick: odd
 * ones (1 in 32 for the rarer item), even ones (1 in 16).
 */
void FIELDSTG_startEncounter(s32 encounter) {
    FieldTask *task = TASK_REGISTRY.funcs.find(7, -1, -1);
    s32 i;
    s32 next;
    s32 mode;
    s32 roll;

    if (task != NULL) {
        D_800990B4.busy = 1;
        D_800990B4.battleStarting = 1;
#if VERSION_EU
        next = 0xE0A;
#else
        next = 0xE09;
#endif
        if (GAME.progress != 0x2B) {
            next = 0x600;
        }
        task->nextMode = next;
        task->nextModeArg = 0;
        task->setState(task, 2);
        BATTLE_SETUP.battle = encounter;
        BATTLE_SETUP.ambushChance = FIELDSTG_encounters[encounter].unkC;
        BATTLE_SETUP.unk3D = FIELDSTG_encounters[encounter].unkD;
        for (i = 0; i < 12; i++) {
            BATTLE_SETUP.unk3E[i] = FIELDSTG_encounters[encounter].unkE[i];
        }
        for (i = 0; i < 3; i++) {
            BATTLE_SETUP.enemies[i] = *FIELDSTG_encounters[encounter].enemies[i];
        }
        BATTLE_SETUP.hasPrize = 0;
        if ((u32)(BATTLE_SETUP.enemies[0].fighter - 0x1C9) < 8) {
            BATTLE_SETUP.hasPrize = 1;
            mode = GAME.funcs.getMode();
            if (BATTLE_SETUP.enemies[0].fighter & 1) {
                roll = RANDOM.next() & 0x1F;
                switch (mode) {
                case 0x21D:
                default:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x177;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x22A:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x179;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x233:
                case 0x235:
                case 0x237:
                case 0x23A:
                case 0x23B:
                case 0x23C:
                case 0x24A:
                case 0x24C:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17A;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
#if VERSION_EU
                case 0x28C:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17F;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
                case 0x28D:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x179;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x28E:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x178;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x28F:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17E;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
                case 0x290:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x180;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x291:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x181;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x296:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x182;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x298:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17C;
                        } else {
                            BATTLE_SETUP.prize = 0x187;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x183;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
                case 0x299:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17F;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x185;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
#else
                case 0x28C:
                case 0x28D:
                case 0x28E:
                case 0x28F:
                case 0x290:
                case 0x291:
                case 0x296:
                case 0x298:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17C;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
                case 0x299:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17F;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
#endif
                case 0x2A1:
                case 0x2A3:
                case 0x2A4:
                case 0x2A7:
                case 0x2A8:
                case 0x2A9:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x180;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x261:
                case 0x262:
                case 0x265:
                case 0x266:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x181;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x2B4:
                case 0x2B6:
                case 0x2C9:
                case 0x2CA:
                case 0x2CD:
                case 0x2CE:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x184;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
                }
            } else {
                roll = RANDOM.next() & 0xF;
                switch (mode) {
                case 0x201:
                default:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x177;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x234:
                case 0x235:
                case 0x237:
                case 0x23A:
                case 0x23B:
                case 0x23C:
                case 0x23D:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x178;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x247:
                case 0x249:
                case 0x24B:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17B;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
#if VERSION_EU
                case 0x271:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x177;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x28C:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17A;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
                case 0x28D:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x179;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x28E:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x178;
                    } else {
                        BATTLE_SETUP.prize = 0x186;
                    }
                    break;
                case 0x28F:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17B;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
                case 0x290:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x184;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
                case 0x296:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17C;
                    } else {
                        BATTLE_SETUP.prize = 0x187;
                    }
                    break;
                case 0x299:
                    if (GAME.progress != 0x2D) {
                        if (roll != 0) {
                            BATTLE_SETUP.prize = 0x17D;
                        } else {
                            BATTLE_SETUP.prize = 0x188;
                        }
                    } else if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17D;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
#else
                case 0x271:
                case 0x28C:
                case 0x28D:
                case 0x28E:
                case 0x28F:
                case 0x290:
                case 0x296:
                case 0x299:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17D;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
#endif
                case 0x2A2:
                case 0x2A3:
                case 0x2A4:
                case 0x2A7:
                case 0x2A8:
                case 0x2A9:
                case 0x2AA:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x17E;
                    } else {
                        BATTLE_SETUP.prize = 0x188;
                    }
                    break;
                case 0x266:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x182;
                    } else {
                        BATTLE_SETUP.prize = 0x189;
                    }
                    break;
                case 0x2B1:
                case 0x2B3:
                case 0x2B5:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x183;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
                case 0x2CE:
                    if (roll != 0) {
                        BATTLE_SETUP.prize = 0x185;
                    } else {
                        BATTLE_SETUP.prize = 0x18A;
                    }
                    break;
                }
            }
        }
    }
}

void *func_8008B258(void) {
    Battle *battle = D_800990B4.battles->battles[3]->battles[5];

    BATTLE_SETUP.stage = battle->unk4;
    BATTLE_SETUP.music = battle->unk8;
    FIELDSTG_startEncounter(battle->unk0);
    FLAGS_00.applyAction(0xF, 1);
    return NULL;
}

void func_8008B2C4(s32 index) {
    FieldChildren *children = ((Task *)TASK_REGISTRY.funcs.find(7, -1, -1))->children;

    children->event = FIELDSTG_startEvent(FIELDSTG_eventIds[index]);
}

void func_8008B320(void) {
    FieldTask *task = TASK_REGISTRY.funcs.find(7, -1, -1);
    FieldChildren *children = task->children;

    D_800990B4.innOpen = 1;
    D_800990B4.busy = 1;
    children->unk10 = (Task *)createInn(0x1002);
    task->setSubstate(task, 2);
}

void func_8008B398(s32 arg0, Point *pos, FieldWarp *arg2) {
    FieldTask *task = TASK_REGISTRY.funcs.find(7, -1, -1);

    task->unk70 = arg0;
    task->unk74.x = pos->x;
    task->unk74.y = pos->y;
    task->unk7C = arg2;
    task->setSubstate(task, 3);
}

s32 FIELDSTG_scaleSin(s32 angle, s32 radius) {
    return rsin(angle >> 2) * radius / 4096;
}

/* Sends an actor from the nearest task with id 0x17 (y counts twice in the
 * distance) to its dest tile: the actor walks to the task, sets it to state 2,
 * waits for it to leave that state, then moves along a quarter sine, spinning,
 * until it lands; without such a task it ends at once. The match depends on
 * the distance written twice. */
void FIELDSTG_runLaunch(Launch *task) {
    Point pos;
    Point near;
    Task *t;
    Task *found;
    s32 best;
    s32 dx;
    s32 dy;
    s32 d;

    switch (task->state) {
    case 0:
    default:
        best = 0x8000;
        found = NULL;
        pos.x = task->actor->tile.x;
        pos.y = task->actor->tile.y;
        for (t = TASK_REGISTRY.funcs.find(0x17, -1, -1); t != NULL; t = TASK_REGISTRY.funcs.findNext()) {
            dx = pos.x - t->key1;
            if (dx < 0) {
                dx = -dx;
            }
            dy = pos.y - t->key2;
            if (dy < 0) {
                dy = -dy;
            }
            if (dx + dy * 2 < best) {
                found = t;
                near.x = t->key1;
                best = dx + dy * 2;
                near.y = found->key2;
            }
        }
        if (found == NULL) {
            task->setState(task, 3);
            break;
        }
        task->from = found;
        task->start.x = near.x + 0x14;
        task->start.y = near.y + 0xD;
        task->nextState(task);
    case 1:
        switch (task->substate) {
        case 0:
            switch (task->step) {
            case 0:
                task->actor->setGoal(task->actor, task->start.x, task->start.y, 0);
                FIELDSTG_haltPartners();
                task->nextStep(task);
            case 1:
                if (task->actor->isWalking(task->actor) == 0) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 1:
            switch (task->step) {
            case 0:
            default:
                task->from->setState(task->from, 2);
                SOUND.playSound(SOUND_TELEPORT);
                task->nextStep(task);
            case 1:
                if (task->from->state != 2) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 2:
            switch (task->step) {
            case 0:
            default:
                task->negX = 0;
                task->dist.x = task->dest[1] - task->start.x;
                if (task->dist.x < 0) {
                    task->dist.x = -task->dist.x;
                    task->negX = 1;
                }
                task->negY = 0;
                task->dist.y = task->dest[2] - task->start.y;
                if (task->dist.y < 0) {
                    task->dist.y = -task->dist.y;
                    task->negY = 1;
                }
                task->nextStep(task);
            case 1:
                task->counter += GFX.funcs.getFrameTime() * 24;
                if (task->counter > 0x1000) {
                    task->counter = 0x1000;
                    task->actor->tile.x = task->dest[1];
                    task->actor->pos.x = task->actor->tile.x << 8;
                    task->actor->tile.y = task->dest[2];
                    task->actor->pos.y = task->actor->tile.y << 8;
                    task->nextSubstate(task);
                    break;
                }
                d = FIELDSTG_scaleSin(task->counter, task->dist.x);
                if (task->negX) {
                    task->actor->tile.x = task->start.x - d;
                } else {
                    task->actor->tile.x = task->start.x + d;
                }
                task->actor->pos.x = task->actor->tile.x << 8;
                d = FIELDSTG_scaleSin(task->counter, task->dist.y);
                if (task->negY) {
                    task->actor->tile.y = task->start.y - d;
                } else {
                    task->actor->tile.y = task->start.y + d;
                }
                task->actor->pos.y = task->actor->tile.y << 8;
                task->actor->dir = (GFX.funcs.getTime() >> 1) & 7;
                task->actor->hasShadow = 0;
                break;
            }
            break;
        default:
            task->setState(task, 3);
            break;
        }
        break;
    case 2:
        break;
    case 3:
        task->actor->dir = 0;
        task->actor->hasShadow = 1;
        D_800990B4.busy = 0;
        task->actor->resetControl(task->actor);
        FIELDSTG_resumePartners();
        break;
    }
}

Launch *FIELDSTG_createLaunch(Actor *actor, s32 dest) {
    Launch *task = createTask(FIELDSTG_runLaunch, sizeof(Launch), 0);

    task->actor = actor;
    task->dest = (s16 *)dest;
    if (GAME.funcs.getMode() == 0x26C) {
        WSTAG745_func_800A4EE8();
    }
    if (GAME.funcs.getMode() == 0x2D4) {
        WSTAG746_func_800A4EE8();
    }
    return task;
}

void FIELDSTG_showSpotHint(SpotHint *task) {
    SpriteDrawer sprite;
    s32 dx;
    s32 dy;
    s32 sprites;

    switch (task->state) {
        default:
        case 0:
            dx = task->from.x - task->to.x;
            if (dx < 0) {
                dx = -dx;
            }
            dy = task->from.y - task->to.y;
            if (dy < 0) {
                dy = -dy;
            }
            if (dx < 0x80 && dy < 0x80) {
                task->speed = 3;
                task->frame = 0x52;
            } else if (dx < 0x100 && dy < 0x100) {
                task->speed = 6;
                task->frame = 0x51;
            } else {
                task->speed = 0xC;
                task->frame = 0x50;
            }
            task->nextState(task);
            /* fallthrough */
        case 1:
            sprites = FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16 | 1);
            initSpriteDrawer(&sprite);
            sprite.setLayerId(0x1002, 0);
            sprite.setTexture(0x240, 0x100);
            sprite.setFollowScroll(0);
            sprite.setClutRow(task->time / task->speed % 10);
            sprite.draw(sprites, task->frame, 0xF8, 0xA8);
            sprite.draw(sprites, 0x4F, 0xF8, 0xA8);
            task->time += GFX.funcs.getFrameTime();
            if (task->time >= 0x78) {
                task->setState(task, 3);
            }
            break;
        case 2:
        case 3:
            break;
    }
}

SpotHint *FIELDSTG_createSpotHint(Point from, Point to) {
    SpotHint *task = createTask(FIELDSTG_showSpotHint, sizeof(SpotHint), 0);

    task->from = from;
    task->to = to;
    return task;
}

void FIELDSTG_hidePrize(HiddenSpots *task) {
    s32 index = RANDOM.next() % task->count;

    GAME.unk26E4 = index;
    task->entries[index].hasPrize = 1;
    task->pos = task->entries[index].pos;
}

void FIELDSTG_updateHiddenSpots(HiddenSpots *task, HiddenSpotsChildren *children) {
    StageTile *objects;
    s32 step;
    s32 time;
    s32 i;

    switch (task->state) {
    default:
    case 0:
        FILE_CACHE.request(FIELD_EXIT_FILES + 2);
        task->nextState(task);
        break;
    case 1:
        break;
    case 2:
        if (task->substate == 0) {
            children->effect = FIELDSTG_createSpotEffect(task->unk5C);
            task->nextSubstate(task);
        } else if (task->substate != 0x80) {
            if (task->substate < 0x14) {
                task->substate = task->substate + GFX.funcs.getFrameTime() + 1;
            } else {
                if (task->unk5C == 0) {
                    if (task->entries[task->selected].hasPrize != 0) {
                        if ((RANDOM.next() & 0x7F) < 0x66) {
                            FIELDSTG_battleFuncs.startEventBattle(3);
                        } else {
                            FIELDSTG_battleFuncs.startEventBattle(6);
                        }
                        FIELDSTG_hidePrize(task);
                    } else {
                        if (children->hint != NULL) {
                            children->hint->destroy(children->hint);
                        }
                        children->hint = FIELDSTG_createSpotHint(task->pos, task->entries[task->selected].pos);
                    }
                }
                task->setSubstate(task, 0x80);
            }
        }
        step = task->step;
        time = task->counter;
        time += GFX.funcs.getFrameTime();
        if (FIELDSTG_spotAnim[step][1] < time) {
            time -= FIELDSTG_spotAnim[step][1];
            step++;
            if (FIELDSTG_spotAnim[step][0] == 0xFF) {
                task->setState(task, 1);
                return;
            }
            task->entries[task->selected].frame = FIELDSTG_spotAnim[step][0];
            task->step = step;
        }
        task->counter = time;
        objects = D_800990B4.objects;
        for (i = 0; i < task->count; i++) {
            if (task->entries[i].frame != 0) {
                if (task->selected == i) {
                    objects[task->entries[i].object].frame = task->entries[i].frame;
                } else {
                    objects[task->entries[i].object].frame = 0x38;
                }
            }
        }
        break;
    case 3:
        if (task->entries != NULL) {
            HEAP.free(task->entries);
        }
        break;
    }
}

HiddenSpots *FIELDSTG_createHiddenSpots(s32 count) {
    HiddenSpots *task = createTaskWithId(FIELDSTG_updateHiddenSpots, sizeof(HiddenSpots), 8, 0xB);
    StageTile *object;
    s32 i;
    s32 n;
    s32 index;

    task->count = count;
    object = D_800990B4.objects;
    task->entries = HEAP.alloc(count * sizeof(HiddenSpot), 2);
    i = 0;
    n = 0;
    for (; object->y != 0; object++, i++) {
        if (object->anim == 0xFF) {
            task->entries[n].pos.x = object->x;
            task->entries[n].pos.y = object->y;
            task->entries[n].object = i;
            task->entries[n].frame = 0x38;
            task->entries[n].hasPrize = 0;
            n++;
        }
    }
    if (n != 0) {
        if (GAME.clearTempFlags != 0) {
            FIELDSTG_hidePrize(task);
        } else {
            index = GAME.unk26E4;
            task->entries[index].hasPrize = 1;
            task->pos = task->entries[index].pos;
        }
    }
    return task;
}

HiddenSpots *FIELDSTG_findHiddenSpot(Point *pos, s32 select) {
    HiddenSpots *task = TASK_REGISTRY.funcs.find(0xB, -1, -1);
    s32 i;

    if (task != NULL) {
        for (i = 0; i < task->count; i++) {
            if (pos->x >= task->entries[i].pos.x - 10 && task->entries[i].pos.x + 10 >= pos->x
                && pos->y >= task->entries[i].pos.y - 10 && task->entries[i].pos.y + 10 >= pos->y) {
                if (select) {
                    task->selected = i;
                    task->unk5C = 0;
                }
                return task;
            }
        }
    }
    return NULL;
}

void func_8008C23C(void) {
    HiddenSpots *task = TASK_REGISTRY.funcs.find(0xB, -1, -1);
    s32 i;

    if (task != NULL) {
        for (i = 0; i < task->count; i++) {
            if (task->entries[i].pos.x >= 1000) {
                task->selected = i;
                task->unk5C = 1;
                task->setState(task, 2);
            }
        }
    }
}

void FIELDSTG_drawSpotEffect(SpotEffect *task, Layer *layer) {
    SpriteDrawer sprite;

    if (task->state == 1) {
        initSpriteDrawer(&sprite);
        sprite.setTexture(0x200, 0x100);
        sprite.setLayer(layer, 4);
        sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16), task->frame, task->x, task->y);
    }
}

void FIELDSTG_updateSpotEffect(SpotEffect *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    Actor *actor;
    s32 step;
    s32 time;
    u8 *anim;

    switch (task->state) {
        default:
        case 0:
            if (task->key1 != 0) {
                actor = TASK_REGISTRY.funcs.find(5, 0x11B, -1);
            } else {
                actor = TASK_REGISTRY.funcs.find(5, -1, 0);
            }
            if (actor == NULL) {
                break;
            }
            task->x = actor->tile.x;
            task->y = actor->tile.y;
            task->dir = actor->dir;
            task->anim = FIELDSTG_dirAnims[task->dir];
            task->nextState(task);
            SOUND.playSound(0x80045C44);
            /* fallthrough */
        case 1:
            step = task->step;
            time = task->counter;
            time += GFX.funcs.getFrameTime();
            anim = task->anim;
            if (anim[step * 2 + 1] < time) {
                time -= anim[step * 2 + 1];
                step++;
                if (anim[step * 2] == 0xFF) {
                    task->setState(task, 3);
                    break;
                }
                task->frame = anim[step * 2];
                task->step = step;
            }
            task->counter = time;
            if (task->frame != 0) {
                layer->addSortedCallback(layer, FIELDSTG_drawSpotEffect, task, task->y + FIELDSTG_dirDepths[task->dir], 0);
            }
            break;
        case 2:
        case 3:
            break;
    }
}

SpotEffect *FIELDSTG_createSpotEffect(s32 arg0) {
    SpotEffect *task = createTask(FIELDSTG_updateSpotEffect, sizeof(SpotEffect), 0);

    task->key1 = arg0;
    return task;
}

/* A gauge game: a cursor runs back and forth along one of the gauge rows until
 * cross is pressed, then slows down and stops; the cell it stops on (2 bits)
 * fails (0) or calls FIELDSTG_battleFuncs.startEventBattle with 4 (1) or 7 (2). In Europe the rows are
 * random only while GAME.unk26F8 lasts, then it is row 8, all zeros. The match
 * depends on the cell read and shifted as two statements. */
void FIELDSTG_runGauge(GaugeGame *task) {
    SpriteDrawer drawer;
    SpriteDrawer gauge;
    s32 sprites;
    s32 gaugeSprites;
    u8 cell;
    s32 index;
    s32 shift;

    switch (task->state) {
    case 0:
    default:
#if VERSION_EU
        if (GAME.unk26F8 > 0) {
            task->row = RANDOM.next() & 7;
            GAME.unk26F8--;
        } else {
            task->row = 8;
        }
#else
        task->row = RANDOM.next() & 7;
#endif
        task->speed = 0x100;
        task->nextState(task);
    case 1:
        switch (task->substate) {
        case 0:
        default:
            task->step += GFX.funcs.getFrameTime();
            if (task->step > 0x5A) {
                task->nextSubstate(task);
            }
            break;
        case 1:
            switch (task->step) {
            case 0:
            default:
                if (PAD.getPressed(0) & (1 << PAD_CROSS)) {
                    if (!(RANDOM.next() & 3)) {
                        task->setStep(task, 2);
                    } else {
                        task->setStep(task, 1);
                    }
                    SOUND.playSound(SOUND_MENU_MOVE);
                }
                break;
            case 1:
                task->speed -= 0x10;
                if (task->speed == 0) {
                    task->setStep(task, 3);
                }
                break;
            case 2:
                task->speed -= 4;
                if (task->speed == 0) {
                    task->setStep(task, 3);
                }
                break;
            case 3:
#if VERSION_EU
                index = task->cursor >> 10;
                shift = (task->cursor >> 7) & 6;
                cell = FIELDSTG_gaugeRows[task->row][index];
                cell = (cell >> shift) & 3;
                if (task->counter < 0x3C) {
                    if (task->counter == 0 && cell == 1) {
                        SOUND.playSound(0x80045341);
                    }
                    task->counter += GFX.funcs.getFrameTime();
                    break;
                }
#else
                task->counter += GFX.funcs.getFrameTime();
                if (task->counter < 0x3C) {
                    break;
                }
                index = task->cursor >> 10;
                shift = (task->cursor >> 7) & 6;
                cell = FIELDSTG_gaugeRows[task->row][index];
                cell = (cell >> shift) & 3;
#endif
                switch (cell) {
                case 0:
                default:
                    task->setState(task, 3);
                    break;
                case 1:
                    FIELDSTG_battleFuncs.startEventBattle(4);
                    task->setState(task, 2);
                    break;
                case 2:
                    FIELDSTG_battleFuncs.startEventBattle(7);
                    task->setState(task, 2);
                    break;
                }
                break;
            }
            if (task->back) {
                task->cursor -= task->speed;
                if (task->cursor <= 0) {
                    task->cursor = 0;
                    task->back = 0;
                }
            } else {
                task->cursor += task->speed;
                if (task->cursor >= 0x3000) {
                    task->cursor = 0x3000;
                    task->back = 1;
                }
            }
            sprites = FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16);
            initSpriteDrawer(&drawer);
            drawer.setLayerId(0x1002, 4);
            drawer.setTexture(0x200, 0x100);
            drawer.draw(sprites, GFX.funcs.getTime() % 48 / 12 + 0x60, task->pos.x, task->pos.y);
            gaugeSprites = FILE_CACHE.getEntry((FIELD_SPRITES_FILE << 16) | 1);
            initSpriteDrawer(&gauge);
            gauge.setLayerId(0x1002, 0);
            gauge.setTexture(0x240, 0x100);
            gauge.setFollowScroll(0);
            gauge.draw(gaugeSprites, 0x3D, (task->cursor >> 8) + 0x18, 0xC0);
            gauge.draw(gaugeSprites, task->row + 0x3E, 0x18, 0xC0);
            gauge.draw(gaugeSprites, 0x3C, 0x18, 0xC0);
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

GaugeGame *FIELDSTG_createGauge(Point pos) {
    GaugeGame *task = createTask(FIELDSTG_runGauge, sizeof(GaugeGame), 0);

    task->pos = pos;
    return task;
}

void FIELDSTG_scrollCamera(Camera *task) {
    Layer *layer = GFX.funcs.getLayer(0x1002);
    MapStreamer *map;
    Point *size;
    s32 x;
    s32 y;
    s32 shake;

    x = task->center.x - 0xA0;
    y = task->center.y - 0x8C;
    if (task->hasBounds == 0) {
        map = TASK_REGISTRY.funcs.find(4, -1, -1);
        if (map != NULL) {
            if (map->state == 1) {
                size = map->getSize(map);
                task->bounds = *size;
                task->hasBounds = 1;
            }
        } else if (GAME.funcs.getMode() != 0x2DE) {
            task->bounds.x = 0x7FFF;
            task->bounds.y = 0x7FFF;
        } else {
            task->bounds.x = 0x500;
            task->bounds.y = 0x400;
        }
    }
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (task->bounds.x - 0x140 < x) {
        x = task->bounds.x - 0x140;
    }
    if (task->bounds.y - 0xF0 < y) {
        y = task->bounds.y - 0xF0;
    }
    shake = 0;
    if (task->shaking != 0) {
        task->shake = (task->shake + 1) & 3;
        shake = task->shake + 1;
        if (task->voice == -1) {
            task->voice = SOUND.playSound(0xA00431BF);
        }
    } else if (task->voice != -1) {
        SOUND.keyOff(0xA00431BF, task->voice);
        task->voice = -1;
    }
    layer->setScroll(layer, (FIELDSTG_shakeOffsets[shake].x + x) << 8, (FIELDSTG_shakeOffsets[shake].y + y) << 8);
}

void FIELDSTG_updateCamera(Camera *task) {
    Point delta;
    Point sign;

    switch (task->state) {
        default:
        case 0:
            task->target = TASK_REGISTRY.funcs.find(5, -1, 0);
            task->snap = 1;
            if (task->target != NULL) {
                task->nextState(task);
            }
            break;
        case 1:
            switch (task->substate) {
                case 0:
                    task->center.x = task->target->tile.x;
                    task->center.y = task->target->tile.y - (task->target->z >> 8);
                    if ((task->step == 0) & (task->snap == 0)) {
                        task->nextStep(task);
                    }
                    break;
                case 1:
                    task->center.x = task->spotX;
                    task->center.y = task->spotY;
                    if ((task->step == 0) & (task->snap == 0)) {
                        task->nextStep(task);
                    }
                    break;
            }
            if (task->step == 1) {
                sign.x = 1;
                sign.y = 1;
                delta.x = task->center.x - task->pan.x;
                if (delta.x < 0) {
                    sign.x = -1;
                    delta.x = -delta.x;
                }
                delta.y = task->center.y - task->pan.y;
                if (delta.y < 0) {
                    sign.y = -1;
                    delta.y = -delta.y;
                }
                if (delta.x != 0 && delta.y != 0) {
                    if (delta.x > 4) {
                        delta.x /= 4;
                    } else if (delta.x > 2) {
                        delta.x /= 2;
                    } else {
                        delta.x = 1;
                    }
                    task->center.x = task->pan.x += delta.x * sign.x;
                    if (delta.y > 4) {
                        delta.y /= 4;
                    } else if (delta.y > 2) {
                        delta.y /= 2;
                    } else {
                        delta.y = 1;
                    }
                    task->center.y = task->pan.y += delta.y * sign.y;
                } else {
                    task->nextStep(task);
                }
            }
            FIELDSTG_scrollCamera(task);
            break;
        case 2:
            break;
        case 3:
            if (task->voice != -1) {
                SOUND.keyOff(0xA00431BF, task->voice);
                task->voice = -1;
            }
            break;
    }
}

Camera *FIELDSTG_createCamera(void) {
    Camera *task = createTaskWithId(FIELDSTG_updateCamera, sizeof(Camera), 0, 0x10);

    task->voice = -1;
    return task;
}

void FIELDSTG_followWithCamera(s32 snap, s32 id) {
    Camera *task = TASK_REGISTRY.funcs.find(0x10, -1, -1);

    if (task != NULL) {
        task->unk7C = 0;
        task->snap = snap;
        task->targetId = id;
        task->target = TASK_REGISTRY.funcs.find(5, id, -1);
        task->pan = task->center;
        task->setSubstate(task, 0);
    }
}

void FIELDSTG_pointCamera(s32 snap, s32 x, s32 y) {
    Camera *task = TASK_REGISTRY.funcs.find(0x10, -1, -1);

    if (task != NULL) {
        task->unk7C = 0;
        task->snap = snap;
        task->spotX = x;
        task->spotY = y;
        task->pan = task->center;
        task->setSubstate(task, 1);
    }
}

void FIELDSTG_shakeCamera(s32 shaking) {
    Camera *task = TASK_REGISTRY.funcs.find(0x10, -1, -1);

    if (task != NULL) {
        task->shaking = shaking;
    }
}

s32 func_8008D0C0(Actor *actor, s32 x, s32 y, Point offset) {
    s32 blocked = 0;
    Point pos;
    u8 cell;

    pos.x = (actor->pos.x >> 8) + x;
    pos.y = (actor->pos.y >> 8) + y;
    cell = D_8009A70C.unk58(&pos);
    if (cell != 0) {
        cell = D_8009A70C.getCell(GAME.unk26D8, &pos);
    }
    if (actor->z != 0 && cell != 1) {
        switch (cell) {
        case 2:
            if (actor->z < 0x2000) {
                cell = 0;
            }
            break;
        case 3:
            if (actor->z < 0x3000) {
                cell = 0;
            }
            break;
        case 4:
            if (actor->z < 0x4000) {
                cell = 0;
            }
            break;
        case 5:
            if (actor->z < 0x5000) {
                cell = 0;
            }
            break;
        case 6:
            if (actor->z < 0x6000) {
                cell = 0;
            }
            break;
        }
        switch (cell) {
        case 18:
            if (actor->z > 0x6000) {
                cell = 0;
            }
            break;
        case 19:
            if (actor->z > 0x5000) {
                cell = 0;
            }
            break;
        case 20:
            if (actor->z > 0x4000) {
                cell = 0;
            }
            break;
        case 21:
            if (actor->z > 0x3000) {
                cell = 0;
            }
            break;
        case 22:
            if (actor->z > 0x2000) {
                cell = 0;
            }
            break;
        }
        if (cell == 0) {
            blocked = 1;
        }
    }
    if (cell == 0) {
        actor->pos.x -= offset.x;
        actor->pos.y -= offset.y;
    }
    return blocked;
}

s32 func_8008D2A0(Actor *actor) {
    s32 blocked = 0;
    s32 i;
    u8 probe;
    u8 *sign;
    Point offset;

    for (i = 0; i < 5; i++) {
        probe = FIELDSTG_probes[actor->dir][i];
        sign = FIELDSTG_probeSteps[probe];
        offset.x = (sign[0] & 1) * actor->speed / 2;
        if (sign[0] & 0x80) {
            offset.x = -offset.x;
        }
        offset.y = (sign[1] & 1) * actor->speed / 4;
        if (sign[1] & 0x80) {
            offset.y = -offset.y;
        }
        if (func_8008D0C0(actor, FIELDSTG_probePos[probe].x, FIELDSTG_probePos[probe].y, offset)) {
            blocked = 1;
        }
    }
    return blocked;
}

void FIELDSTG_moveByPad(Actor *actor, s32 pad) {
    if (pad != 0 && D_800990B4.innOpen == 0) {
        actor->dir = FIELDSTG_padDirs[pad];
        if (actor->walks != 0) {
            if (actor->substate != 2) {
                actor->setSubstate(actor, 2);
            }
        } else if (actor->substate != 3) {
            actor->setSubstate(actor, 3);
        }
    } else {
        if (actor->substate == 2) {
            actor->setSubstate(actor, 1);
        }
        if (actor->substate == 3) {
            actor->setSubstate(actor, 4);
        }
    }
}

/*
 * The first actor (task id 5) whose box holds the tile pos: halfWidth to
 * each side of it, half that above and below. The match depends on the
 * registry being held in a variable.
 */
Actor *FIELDSTG_findActorAt(Point *pos) {
    TaskRegistry *registry = &TASK_REGISTRY;
    Actor *actor = registry->funcs.find(5, -1, 1);

    while (actor != NULL) {
        s32 size = actor->halfWidth;

        if (pos->x >= actor->tile.x - size && actor->tile.x + size >= pos->x) {
            size >>= 1;
            if (pos->y >= actor->tile.y - size && actor->tile.y + size >= pos->y) {
                return actor;
            }
        }
        actor = registry->funcs.findNext();
    }
    return NULL;
}

s32 func_8008D580(Actor *actor, Point *pos) {
    Actor *target;
    s32 i;
    s32 result;

    target = FIELDSTG_findActorAt(pos);
    result = 0;
    if (target != NULL && target->state == 1) {
        if (target->key1 != 0x180) {
            if (target->key1 != 0x181) {
                if (target->key1 != 0x182) {
                    for (i = 0; FIELDSTG_standIns[i][0] != 0; i++) {
                        if (target->key1 == FIELDSTG_standIns[i][0]) {
                            target = TASK_REGISTRY.funcs.find(5, FIELDSTG_standIns[i][1], -1);
                            break;
                        }
                    }
                    switch (target->key1) {
                        case 0x148:
                        case 0x15F:
                        case 0x160:
                            if (target->substate != 0x4E) {
                                target->setSubstate(target, 0x4E);
                                result = 1;
                                target->talkPartner = actor;
                                actor->setSubstate(actor, 0x4D);
                                actor->control = NULL;
                            }
                            break;
                        default:
                            target->setSubstate(target, 0x4A);
                            target->talkPartner = actor;
                            actor->setSubstate(actor, actor->flying != 0 ? 0x4C : 1);
                            actor->control = NULL;
                            result = D_800990B4.acting = 1;
                            break;
                    }
                }
            }
        }
    }
    return result;
}

/* The player's flight: it rises unless triangle is held (substate 0x4B),
   left and right turn, and cross, low enough, acts on what the player faces;
   the map's cells hold floors (2 to 6) and ceilings (18 to 22). The match
   depends on the button's shift and mask as two statements. */
void FIELDSTG_controlFlight(Actor *actor) {
    Point facing;
    Point pos;
    s32 held;
    s32 pressed;
    s32 cell;
    s32 stop;
    s32 height;

    held = PAD.getHeld(0);
    pressed = (u32)PAD.getPressed(0) >> PAD_CROSS;
    pressed &= 1;
    if (D_800990B4.innOpen != 0 || D_800990B4.busy != 0 || D_800990B4.battleStarting != 0) {
        return;
    }
    if (pressed && actor->z < 0x2000) {
        actor->getFacingTile(actor, &facing);
        if (func_8008D580(actor, &facing)) {
            actor->zSpeed = 0;
            actor->speed = 0;
            if (actor->voice != -1) {
                SOUND.keyOff(0xA0045F4A, actor->voice);
                actor->voice = -1;
            }
            return;
        }
    }
    if (held & (1 << PAD_TRIANGLE)) {
        if (actor->substate != 0x4B) {
            actor->setSubstate(actor, 0x4B);
        }
        if (actor->voice == -1) {
            actor->voice = SOUND.playSound(0xA0045F4A);
        }
    } else {
        if (actor->substate == 0x4B) {
            actor->setSubstate(actor, 0x4C);
        }
        if (actor->voice != -1) {
            SOUND.keyOff(0xA0045F4A, actor->voice);
            actor->voice = -1;
        }
    }
    if (!(GFX.funcs.getFrameCount() & 7)) {
        if (held & (1 << PAD_RIGHT)) {
            actor->reloadImage = 1;
            actor->dir = (actor->dir + 1) & 7;
        } else if (held & (1 << PAD_LEFT)) {
            actor->reloadImage = 1;
            actor->dir = (actor->dir - 1) & 7;
        }
    }
    if (actor->substate == 0x4B) {
        if (actor->zSpeed > -0xC0) {
            actor->zSpeed -= 4;
        } else {
            actor->zSpeed = -0xC0;
        }
    } else {
        if (actor->zSpeed < 0x80) {
            actor->zSpeed += 4;
        } else {
            actor->zSpeed = 0x80;
        }
    }
    stop = 0;
    height = 0;
    pos.x = actor->pos.x >> 8;
    pos.y = actor->pos.y >> 8;
    cell = D_8009A70C.getCell(GAME.unk26D8, &pos);
    actor->z += actor->zSpeed;
    if (actor->zSpeed > 4) {
        switch ((u8)cell) {
        case 18:
            if (actor->z > 0x6000) {
                stop = 1;
            }
            break;
        case 19:
            if (actor->z > 0x5000) {
                stop = 1;
            }
            break;
        case 20:
            if (actor->z > 0x4000) {
                stop = 1;
            }
            break;
        case 21:
            if (actor->z > 0x3000) {
                stop = 1;
            }
            break;
        case 22:
            if (actor->z > 0x2000) {
                stop = 1;
            }
            break;
        }
    } else {
        switch ((u8)cell) {
        case 2:
            if (actor->z < 0x2000) {
                stop = 1;
                height = 0x200C;
            }
            break;
        case 3:
            if (actor->z < 0x3000) {
                stop = 1;
                height = 0x300C;
            }
            break;
        case 4:
            if (actor->z < 0x4000) {
                stop = 1;
                height = 0x400C;
            }
            break;
        case 5:
            if (actor->z < 0x5000) {
                stop = 1;
                height = 0x500C;
            }
            break;
        case 6:
            if (actor->z < 0x6000) {
                stop = 1;
                height = 0x600C;
            }
            break;
        }
    }
    if (stop || actor->z > 0x7000 || actor->z < 0x1800) {
        if (height != 0) {
            actor->z = height;
        }
        actor->zSpeed = 0;
    }
    if (actor->z >= 0x7000) {
        actor->z = 0x7000;
    }
    if (actor->z <= 0x1800) {
        actor->z = 0x1800;
    }
}

/*
 * The player's update while it walks (Actor.control) when no menu, event or
 * transition is running: the action button or a forced action (condition
 * 0x12) checks the tile it faces, for an object to act on or, failing that,
 * an event; otherwise the pad moves it. The match depends on the object's
 * case being an early exit, a do-while (0) with a break, after which the
 * event's check is the rest of the block.
 */
void FIELDSTG_controlPlayer(Actor *actor) {
    Point pos;
    HiddenSpots *obj;
    s32 pad;
    s32 pressed;
    s32 forced;

    if (D_800990B4.innOpen == 0 && D_800990B4.busy == 0 && D_800990B4.battleStarting == 0) {
        pad = (PAD.getHeld(0) >> 4) & 0xF;
        pressed = (PAD.getPressed(0) & 0x2000) != 0;
        forced = FLAGS_00.checkCondition(0x12, 1);
        if (pressed || forced) {
            actor->getFacingTile(actor, &pos);
            do {
                if (FLAGS_00.checkCondition(0x8004, 1) && !forced && (obj = FIELDSTG_findHiddenSpot(&pos, 1)) != NULL) {
                    D_800990B4.acting = 1;
                    actor->setSubstate(actor, 0x49);
                    obj->setState(obj, 2);
                    break;
                }
                if (func_8008D580(actor, &pos) && forced) {
                    FLAGS_00.applyAction(0x12, 0);
                }
            } while (0);
        } else {
            FIELDSTG_moveByPad(actor, pad);
        }
    }
}

void FIELDSTG_controlClimb(Actor *actor) {
    s32 held = PAD.getHeld(0);

    if (held & (1 << PAD_UP)) {
        if (actor->substate != 0x41) {
            actor->setSubstate(actor, 0x41);
        }
    } else if (held & (1 << PAD_DOWN)) {
        if (actor->substate != 0x42) {
            actor->setSubstate(actor, 0x42);
        }
    } else if (actor->substate != 0x40) {
        actor->setSubstate(actor, 0x40);
    }
}

void FIELDSTG_followLeader(Actor *actor) {
    Trail *trail;
    Actor *leader;

    if (actor->trail->leader == NULL) {
        actor->trail->leader = TASK_REGISTRY.funcs.find(5, -1, 0);
    }
    leader = actor->trail->leader;
    if (leader != NULL) {
        trail = actor->trail;
        switch (leader->substate) {
            case 2:
            case 3:
            case 5:
            case 0x4F:
            case 0x50:
                trail->steps[trail->head].x = leader->pos.x;
                trail->steps[trail->head].y = leader->pos.y;
                trail->steps[trail->head].dir = leader->dir;
                trail->head = (trail->head + 1) & 0x3F;
                actor->pos.x = trail->steps[trail->tail].x;
                actor->pos.y = trail->steps[trail->tail].y;
                actor->dir = trail->steps[trail->tail].dir;
                trail->tail = (trail->tail + 1) & 0x3F;
                break;
        }
        switch (leader->substate) {
            case 2:
            case 3:
            case 5:
                if (actor->substate != 3) {
                    actor->setSubstate(actor, 3);
                }
                break;
            case 0x4F:
                if (actor->substate != 1) {
                    actor->setSubstate(actor, 1);
                }
                break;
            default:
                if (actor->substate == 3) {
                    actor->setSubstate(actor, 4);
                }
                break;
        }
        actor->depth = leader->depth;
    }
}

/* A follower's update while its trail runs out: it finds the leader (task
   5) if it has none, then each frame pushes two empty steps at the trail's
   head and walks two steps from its tail. At x 0 it clears the trail and
   drops this update. The match depends on the leader being read into a
   variable before `trail` is set, which makes `trail` a copy of the
   pointer the leader was loaded through. */
void FIELDSTG_drainTrail(Actor *actor) {
    Trail *trail;
    Actor *leader;
    s32 i;

    if (actor->trail->leader == NULL) {
        actor->trail->leader = TASK_REGISTRY.funcs.find(5, -1, 0);
    }
    leader = actor->trail->leader;
    trail = actor->trail;
    if (leader != NULL) {
        for (i = 0; i < 2; i++) {
            trail->steps[trail->head].x = 0;
            trail->steps[trail->head].y = 0;
            trail->steps[trail->head].dir = 0;
            trail->head = (trail->head + 1) & 0x3F;
            actor->pos.x = trail->steps[trail->tail].x;
            actor->pos.y = trail->steps[trail->tail].y;
            actor->dir = trail->steps[trail->tail].dir;
            trail->tail = (trail->tail + 1) & 0x3F;
        }
        if (actor->substate != 3) {
            actor->setSubstate(actor, 3);
        }
        if (actor->pos.x == 0) {
            for (i = 0; i < 64; i++) {
                trail->steps[i].dir = 0;
                trail->steps[i].x = 0;
                trail->steps[i].y = 0;
            }
            actor->control = NULL;
        }
    }
}

void FIELDSTG_walkToGoal(Actor *actor) {
    s32 x;
    s32 y;
    s32 tx;
    s32 ty;
    s32 pad;

    if (actor->walking != 0) {
        x = actor->pos.x >> 8;
        y = actor->pos.y >> 8;
        tx = actor->goalX;
        ty = actor->goalY;
        if (x >> 1 != tx >> 1 || y >> 1 != ty >> 1) {
            pad = 0;
            if (x < tx) {
                pad = 1 << PAD_RIGHT;
            } else if (x > tx) {
                pad = 1 << PAD_LEFT;
            }
            if (y < ty) {
                pad |= 1 << PAD_DOWN;
            } else if (y > ty) {
                pad |= 1 << PAD_UP;
            }
            actor->walks = 1;
            FIELDSTG_moveByPad(actor, pad >> 4);
        } else {
            actor->pos.x = actor->goalX << 8;
            actor->walking = 0;
            actor->pos.y = actor->goalY << 8;
            actor->dir = actor->goalDir;
            actor->setSubstate(actor, 1);
        }
    }
}

void FIELDSTG_setActorGoal(Actor *actor, s32 arg1, s32 arg2, s32 arg3) {
    actor->walking = 1;
    actor->goalX = arg1;
    actor->goalY = arg2;
    actor->goalDir = arg3;
}

s32 FIELDSTG_isActorWalking(Actor *actor) {
    return actor->walking;
}

void FIELDSTG_startActorWalk(Actor *actor) {
    actor->control = FIELDSTG_walkToGoal;
}

void FIELDSTG_resetActorControl(Actor *actor) {
    switch (actor->key2) {
    case 0:
        actor->control = FIELDSTG_controlPlayer;
        actor->walks = 0;
        break;
    case 1:
        actor->control = NULL;
        break;
    case 2:
    case 4:
    case 8:
        actor->control = FIELDSTG_followLeader;
        break;
    }
}

void FIELDSTG_walkActorInDir(Actor *actor, s32 dir) {
    actor->control = NULL;
    actor->setSubstate(actor, 5);
    actor->dir = dir;
}

void FIELDSTG_startActorSlide(Actor *actor, s32 dir) {
    if (actor->substate != 0x4F) {
        actor->control = NULL;
        actor->setSubstate(actor, 0x4F);
        actor->dir = dir;
    }
}

void FIELDSTG_stopActorSlide(Actor *actor) {
    if (actor->substate == 0x4F) {
        actor->setSubstate(actor, 0x50);
    }
}

/* The climbs (map slots 2 and 3) and the drop (4): the actor goes onto the
   wall at its foot (0x43) or its top (0x44), climbs it with the pad
   (FIELDSTG_controlClimb, 0x40 to 0x42) and leaves it at the top (0x45) or
   the foot (0x46); a drop (0x47) falls from height. */
void FIELDSTG_startClimbUp(Actor *actor, s32 dir, s32 x, s32 y, s32 height) {
    actor->control = NULL;
    actor->setSubstate(actor, 0x43);
    actor->dir = dir;
    actor->pos.x = x << 8;
    actor->pos.y = y << 8;
    actor->climbHeight = 0;
    actor->wallHeight = height << 8;
    if (dir != 5) {
        actor->climbSide = 1;
    } else {
        actor->climbSide = 0;
    }
    FIELDSTG_haltPartners();
    D_800990B4.acting = 1;
}

void FIELDSTG_startClimbDown(Actor *actor, s32 dir, s32 x, s32 y, s32 height) {
    actor->control = NULL;
    actor->setSubstate(actor, 0x44);
    actor->dir = dir;
    actor->pos.x = x << 8;
    actor->pos.y = y << 8;
    actor->climbHeight = actor->wallHeight = height << 8;
    if (dir != 5) {
        actor->climbSide = 1;
    } else {
        actor->climbSide = 0;
    }
    actor->hasShadow = 0;
    FIELDSTG_haltPartners();
    D_800990B4.acting = 1;
}

void FIELDSTG_startDrop(Actor *actor, s32 dir, Point pos, s32 height) {
    s32 value;

    actor->control = NULL;
    actor->setSubstate(actor, 0x47);
    actor->dir = dir;
    if (dir != 7) {
        actor->climbSide = 0;
    } else {
        actor->climbSide = 1;
    }
    value = height << 8;
    actor->wallHeight = value;
    actor->hasShadow = 0;
    actor->climbHeight = value;
    FIELDSTG_haltPartners();
    D_800990B4.acting = 1;
}

void FIELDSTG_startActorGauge(Actor *actor, s32 dir, Point offset) {
    void **children;
    Actor *other;
    Point pos;
    s32 i;

    D_800990B4.busy = 1;
    actor->control = NULL;
    actor->setSubstate(actor, 0x48);
    actor->dir = dir;
    for (i = 0; i < 3; i++) {
        other = TASK_REGISTRY.funcs.find(5, -1, FIELDSTG_turnedPartners[i]);
        if (other != NULL) {
            other->dir = dir;
        }
    }
    children = actor->children;
    pos.x = actor->tile.x + offset.x;
    pos.y = actor->tile.y + offset.y;
    children[2] = FIELDSTG_createGauge(pos);
}

void FIELDSTG_warpActor(Actor *actor, FieldWarp *arg1, s32 arg2) {
    actor->control = NULL;
    actor->setSubstate(actor, 1);
    actor->dir = 0;
    D_800990B4.busy = 1;
    func_8008B398(arg2, &actor->tile, arg1);
}

void FIELDSTG_launchActor(Actor *actor, s32 dest) {
    void **children;

    actor->control = FIELDSTG_walkToGoal;
    actor->setSubstate(actor, 1);
    actor->dir = 0;
    D_800990B4.busy = 1;
    children = actor->children;
    children[2] = FIELDSTG_createLaunch(actor, dest);
}

void FIELDSTG_setActorAnim(Actor *actor, s32 arg1) {
    actor->animSet = arg1;
    actor->animPos = 0;
    actor->animTime = 0;
    actor->animDone = 0;
}

void FIELDSTG_setActorPose(Actor *actor, s32 arg1, s32 dir) {
    actor->walking = 0;
    actor->setSubstate(actor, 0);
    actor->dir = dir;
    FIELDSTG_setActorAnim(actor, arg1);
}

s32 FIELDSTG_isActorAnimDone(Actor *actor) {
    return actor->animDone;
}

/* The layer's sorted callback that draws an actor: its frame from its image,
 * mirrored for the directions 5 and up, and, when it has one, its shadow, a
 * sprite with its own texture page. The match depends on the shadow's y offset
 * cast to s16. */
void FIELDSTG_drawActor(void *arg, void *arg2) {
    Actor *actor = arg;
    Layer *layer = arg2;
    ActorImage *image = actor->image;
    Point pos;
    Point scroll;
    u_long *ot;
    POLY_FT4 *poly;
    FieldImage *shadow;
    s32 x;

    if (actor->state == 1) {
        ot = (u_long *)layer->getOtEntry(layer, actor->depth);
        pos = actor->tile;
        layer->getScroll(layer, &scroll);
        pos.x -= scroll.x;
        pos.y -= scroll.y;
        poly = GFX.funcs.getPrim();
        pos.y -= actor->z >> 8;
        setPolyFT4(poly);
        setRGB0(poly, 0x80, 0x80, 0x80);
        x = actor->frame[2];
        if (actor->dir >= 5) {
            x = -(actor->frameWidth + x);
        }
        poly->x0 = pos.x + x;
        poly->x1 = actor->frameWidth + (pos.x + x);
        poly->x2 = pos.x + x;
        poly->x3 = actor->frameWidth + (pos.x + x);
        poly->y0 = actor->frame[3] + pos.y;
        poly->y1 = actor->frame[3] + pos.y;
        poly->y2 = actor->frameHeight + (actor->frame[3] + pos.y);
        poly->y3 = actor->frameHeight + (actor->frame[3] + pos.y);
        if (actor->dir < 5) {
            poly->u0 = image->u;
            poly->u1 = actor->frameWidth + image->u;
            poly->u2 = image->u;
            poly->u3 = actor->frameWidth + image->u;
        } else {
            poly->x1--;
            poly->x3--;
            poly->u0 = actor->frameWidth + image->u - 1;
            poly->u1 = image->u;
            poly->u2 = actor->frameWidth + image->u - 1;
            poly->u3 = image->u;
        }
        poly->v0 = image->v;
        poly->v1 = image->v;
        poly->v2 = actor->frameHeight + image->v;
        poly->v3 = actor->frameHeight + image->v;
        poly->clut = getClut(image->clutX, image->clutY);
        poly->tpage = getTPage(0, 0, image->x, image->y);
        addPrim(ot, poly);
        pos.y += actor->z >> 8;
        poly++;
        if (actor->hasShadow != 0) {
            ot = (u_long *)layer->getOtEntry(layer, actor->depth + 1);
            shadow = actor->fieldImage;
            setSprt((SPRT *)poly);
            setRGB0((SPRT *)poly, 0x80, 0x80, 0x80);
            ((SPRT *)poly)->x0 = pos.x - 16;
            ((SPRT *)poly)->y0 = pos.y + (s16)((actor->climbHeight >> 8) - 8);
            ((SPRT *)poly)->u0 = shadow->shadow.u;
            ((SPRT *)poly)->v0 = shadow->shadow.v;
            ((SPRT *)poly)->w = 0x20;
            ((SPRT *)poly)->h = 0x10;
            ((SPRT *)poly)->clut = getClut(shadow->shadow.clutX, shadow->shadow.clutY);
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((SPRT *)poly + 1);
            SetDrawTPage((DR_TPAGE *)poly, 0, 1, GetTPage(0, 0, shadow->shadow.x, shadow->shadow.y));
            addPrim(ot, poly);
            poly = (POLY_FT4 *)((DR_TPAGE *)poly + 1);
        }
        GFX.funcs.setPrim(poly);
    }
}

void FIELDSTG_setActorDir(Actor *actor, s32 arg1) {
    actor->dir = arg1;
}

#if VERSION_US
#define SET_FILE_0 0x01790070
#define SET_FILE_8 0x03BB001E
#define SET_FILE_16 0x03B9000B
#define SET_FILE_1A 0x03BC0017
#define SET_FILE_OTHER 0x03BA0064
#elif VERSION_EU
#define SET_FILE_0 0x01870070
#define SET_FILE_8 0x03CB001E
#define SET_FILE_16 0x03C9000B
#define SET_FILE_1A 0x03CC0017
#define SET_FILE_OTHER 0x03CA0064
#endif

/*
 * Plays an actor's animation: when its set (animSet) changes, it loads the
 * set's animations for the five directions (character 2 picks the file by
 * the set first), then steps the frames of the current direction's and
 * loads a new frame's image into VRAM. The match depends on two early
 * exits written as a do-while (0) with breaks, the pick of the file and
 * the step of the frames: loop.c moves the end of the animation (-1) out
 * of the second one, after the direction's barrier, and reorg fills the
 * first one's < 0x16 branch from its fallthrough, as only a branch out of
 * a loop is. It also depends on reloadImage being read twice, on the width cast
 * to s16 and on reloadImage being cleared last.
 */
void FIELDSTG_animateActor(Actor *actor) {
    TimLoader loader;
    s16 *entry;
    s32 *frames;
    s32 set;
    s32 file;
    s32 dir;
    s32 i;
    ActorImage *image;

    set = actor->animSet;
    file = actor->animFile & 0xFFFF0000;
    if (actor->loadedSet != set) {
        if (actor->key1 == 2) {
            do {
                if (set < 8) {
                    actor->animFile = SET_FILE_0;
                    break;
                }
                if (set == 8) {
                    actor->animFile = SET_FILE_8;
                    break;
                }
                if (set < 0x16) {
                    actor->animFile = SET_FILE_OTHER;
                    break;
                }
                if (set < 0x1A) {
                    actor->animFile = SET_FILE_16;
                    break;
                }
                if (set < 0x25) {
                    actor->animFile = SET_FILE_1A;
                    break;
                }
                actor->animFile = SET_FILE_OTHER;
            } while (0);
            file = actor->animFile & 0xFFFF0000;
        }
        for (entry = (s16 *)FILE_CACHE.getEntry(actor->animFile); entry[0] != 0; entry += 6) {
            if (entry[0] == set) {
                break;
            }
        }
        if (entry[0] == 0) {
            entry = (s16 *)FILE_CACHE.getEntry(actor->animFile);
        }
        for (i = 0; i < 5; i++) {
            actor->setAnims[i] = entry[i + 1] | file;
        }
        actor->loadedSet = set;
        actor->animDone = 0;
    }
    if (actor->dir < 5) {
        dir = actor->dir;
    } else {
        dir = 8 - actor->dir;
    }
    frames = (s32 *)FILE_CACHE.getEntry(actor->setAnims[dir]);
    do {
        if (actor->animTime > 0) {
            break;
        }
        if (frames[actor->animPos] == -1) {
            actor->animTime = 0x7FFFFF;
            actor->animDone = 1;
            break;
        }
        if (frames[actor->animPos] == 0) {
            actor->animPos = 0;
        }
        actor->animTime = frames[actor->animPos++];
        actor->frame[0] = frames[actor->animPos++] | file;
        actor->frame[2] = frames[actor->animPos++];
        actor->frame[3] = frames[actor->animPos++];
    } while (0);
    actor->animTime -= GFX.funcs.getFrameTime();
    if (actor->reloadImage) {
        actor->animTime = frames[actor->animPos - 4];
        actor->frame[0] = frames[actor->animPos - 3] | file;
        actor->frame[2] = frames[actor->animPos - 2];
        actor->frame[3] = frames[actor->animPos - 1];
    }
    if (actor->reloadImage || actor->frame[1] != actor->frame[0]) {
        image = actor->image;
        initTimLoader(&loader);
        loader.setImagePos(image->imageX, image->imageY);
        loader.setClutPos(image->clutX, image->clutY);
        loader.load(FILE_CACHE.getEntry(actor->frame[0]));
        actor->frame[1] = actor->frame[0];
        actor->frameWidth = (s16)loader.w * 4;
        actor->frameHeight = loader.h;
        actor->reloadImage = 0;
    }
}

void FIELDSTG_restorePlayerControl(Actor *actor) {
    actor->control = FIELDSTG_controlPlayer;
    actor->climbHeight = 0;
}

void FIELDSTG_playStepSounds(Task *task, s32 arg1, s32 arg2) {
    if (task->key2 == 0) {
        if (arg1 != 0) {
            if ((task->counter & 7) == 0) {
                if (task->key1 != 0x146) {
                    if (task->key1 != 0x147) {
                        SOUND.playSound(0x8004583C);
                    }
                } else if ((task->counter & 0x1F) == 0) {
                    SOUND.playSound(0x80045FCB);
                }
                if (arg2 != 0) {
                    FIELDSTG_checkBattle();
                }
            }
        } else if ((task->counter & 0x1F) == 0) {
            SOUND.playSound(0x8004583C);
        }
        task->counter++;
    }
}

void FIELDSTG_playClimbSounds(Task *task) {
    if (task->key2 == 0) {
        if ((task->counter & 0xF) == 0) {
            SOUND.playSound(0x800458BD);
        }
        task->counter++;
    }
}

/* The voice of the sound 0xA064683C (s16; its unit defines it as halfwords,
   for the European padding after it) */
extern s16 FIELDSTG_talkVoice;

/*
 * Runs an actor's action, its substate: the walks, the moves of 0x44 to 0x47
 * (which shift it by a tile, left or right by climbSide), the talk of 0x4A (the
 * first of the character's talks whose conditions hold) and the events up to
 * 0x50. The
 * match depends on the talks' loop testing both of its ends with a break at
 * its top, and on the moves of a tile adding a choice of two steps.
 */
void FIELDSTG_runActorAction(Actor *actor, ActorChildren *children) {
    Point move2;
    Point move3;
    Point move4;
    Point move5;
    Point move6;
    FieldTalk *talk;
    Actor *other;
    s32 isX;

    switch (actor->substate) {
    case 1:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 1);
            actor->nextStep(actor);
        case 1:
            break;
        }
        break;
    case 2:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 4);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (!(actor->key2 & 0xE)) {
            D_8009A70C.unk48(&actor->tile, actor->speed >> 2, actor->dir, &move2);
            actor->pos.x += move2.x;
            actor->pos.y += move2.y;
        }
        FIELDSTG_playStepSounds((Task *)actor, 0, 0);
        break;
    case 3:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 5);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (!(actor->key2 & 0xE)) {
            D_8009A70C.unk48(&actor->tile, actor->speed, actor->dir, &move3);
            actor->pos.x += move3.x;
            actor->pos.y += move3.y;
        }
        FIELDSTG_playStepSounds((Task *)actor, 1, 1);
        if (GAME.funcs.getMode() != 0x22D && actor->key2 == 0) {
            func_8008D2A0(actor);
        }
        break;
    case 0x4C:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 1);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->speed != 0) {
            actor->speed -= 8;
            if (actor->speed < 0) {
                actor->speed = 0;
            }
            D_8009A70C.unk4C(&actor->tile, actor->speed, actor->dir, &move4);
            actor->pos.x += move4.x;
            actor->pos.y += move4.y;
            func_8008D2A0(actor);
        }
        break;
    case 0x4B:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 4);
            actor->speed = 0;
            actor->nextStep(actor);
        case 1:
            break;
        }
        actor->speed += 8;
#if VERSION_EU
        if (NTSC_MODE != 0) {
            if (actor->speed > 0x200) {
                actor->speed = 0x200;
            }
        } else if (actor->speed > 0x266) {
            actor->speed = 0x266;
        }
#else
        if (actor->speed > 0x200) {
            actor->speed = 0x200;
        }
#endif
        D_8009A70C.unk4C(&actor->tile, actor->speed, actor->dir, &move4);
        actor->pos.x += move4.x;
        actor->pos.y += move4.y;
        FIELDSTG_playStepSounds((Task *)actor, 1, 1);
        func_8008D2A0(actor);
        break;
    case 4:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 6);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 1);
        }
        break;
    case 5:
        switch (actor->step) {
        case 0:
        default:
            D_800990B4.acting = 1;
            if (actor->flying == 0) {
                FIELDSTG_setActorAnim(actor, 5);
            }
            actor->nextStep(actor);
        case 1:
            break;
        }
        D_8009A70C.unk48(&actor->tile, actor->speed, actor->dir, &move5);
        actor->pos.x += move5.x;
        actor->pos.y += move5.y;
        if (actor->flying == 0) {
            FIELDSTG_playStepSounds((Task *)actor, 1, 0);
        }
        break;
    case 0x4F:
        switch (actor->step) {
        case 0:
        default:
            D_800990B4.acting = 1;
            FIELDSTG_setActorAnim(actor, 1);
            FIELDSTG_talkVoice = SOUND.playSound(0xA064683C);
            actor->nextStep(actor);
        case 1:
            break;
        }
        D_8009A70C.unk48(&actor->tile, actor->speed, actor->dir, &move6);
        actor->pos.x += move6.x;
        actor->pos.y += move6.y;
        break;
    case 0x50:
        if (actor->step == 0) {
            SOUND.keyOff(0xA064683C, FIELDSTG_talkVoice);
        }
        actor->step += GFX.funcs.getFrameTime();
        if (actor->step >= 0x1E) {
            D_800990B4.acting = 0;
            actor->setSubstate(actor, 1);
            FIELDSTG_restorePlayerControl(actor);
        }
        break;
    case 0x40:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x20);
            actor->nextStep(actor);
        case 1:
            break;
        }
        break;
    case 0x41:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x1A);
            actor->nextStep(actor);
        case 1:
            break;
        }
        actor->climbHeight += 0x100;
        if (actor->climbHeight >= actor->wallHeight) {
            actor->climbHeight = actor->wallHeight;
            actor->setSubstate(actor, 0x45);
            actor->control = NULL;
        }
        FIELDSTG_playClimbSounds((Task *)actor);
        break;
    case 0x42:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x1B);
            actor->nextStep(actor);
        case 1:
            break;
        }
        actor->climbHeight -= 0x100;
        if (actor->climbHeight <= 0) {
            actor->climbHeight = 0;
            actor->setSubstate(actor, 0x46);
            actor->control = NULL;
        }
        FIELDSTG_playClimbSounds((Task *)actor);
        break;
    case 0x43:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x1C);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 0x40);
            actor->control = FIELDSTG_controlClimb;
        }
        break;
    case 0x44:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 0;
            FIELDSTG_setActorAnim(actor, 0x1E);
            actor->pos.x += actor->climbSide != 0 ? 0x1000 : -0x1000;
            actor->pos.y += 0x1800 + actor->wallHeight;
            FIELDSTG_followWithCamera(0, 2);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone == 0) {
            break;
        }
        actor->setSubstate(actor, 0x40);
        actor->control = FIELDSTG_controlClimb;
    case 0:
    default:
        actor->hasShadow = 1;
        break;
    case 0x46:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x1F);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 1);
            FIELDSTG_restorePlayerControl(actor);
            FIELDSTG_resumePartners();
            actor->dir = 0;
            D_800990B4.acting = 0;
        }
        break;
    case 0x45:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 0;
            FIELDSTG_setActorAnim(actor, 0x1D);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 1);
            actor->hasShadow = 1;
            FIELDSTG_setActorAnim(actor, 1);
            FIELDSTG_resumePartners();
            FIELDSTG_restorePlayerControl(actor);
            actor->pos.x += actor->climbSide != 0 ? -0x1000 : 0x1000;
            actor->pos.y -= 0x1800 + actor->wallHeight;
            FIELDSTG_followWithCamera(0, 2);
            D_800990B4.acting = 0;
        }
        break;
    case 0x47:
        switch (actor->step) {
        case 0:
        default:
            actor->hasShadow = 0;
            FIELDSTG_setActorAnim(actor, 0x16);
            actor->pos.y += actor->wallHeight;
            actor->pos.x += actor->climbSide != 0 ? 0x1000 : -0x1000;
            actor->nextStep(actor);
        case 1:
            if (actor->animDone == 0) {
                break;
            }
            FIELDSTG_setActorAnim(actor, 0x17);
            actor->nextStep(actor);
        case 2:
            actor->hasShadow = 1;
            actor->climbHeight -= 0x300;
            if (actor->animSet == 0x17 && actor->wallHeight - actor->climbHeight > 0x1800) {
                FIELDSTG_setActorAnim(actor, 0x18);
            }
            if (actor->climbHeight <= 0) {
                actor->climbHeight = 0;
                FIELDSTG_setActorAnim(actor, 0x19);
                SOUND.playSound(0x8004593E);
                actor->nextStep(actor);
            }
            break;
        case 3:
            if (actor->animDone != 0) {
                actor->setSubstate(actor, 1);
                FIELDSTG_setActorAnim(actor, 1);
                FIELDSTG_restorePlayerControl(actor);
                FIELDSTG_resumePartners();
                D_800990B4.acting = 0;
            }
            break;
        }
        break;
    case 0x48:
        switch (actor->step) {
        case 0:
        default:
            FIELDSTG_setActorAnim(actor, 0x11);
            actor->nextStep(actor);
        case 1:
            if (actor->animDone == 0) {
                break;
            }
            FIELDSTG_setActorAnim(actor, 0x13);
            SOUND.playSound(0x80045CC5);
            actor->nextStep(actor);
        case 2:
            if (actor->animDone == 0) {
                break;
            }
            FIELDSTG_setActorAnim(actor, 0x14);
            SOUND.playSound(0x80045D46);
            actor->nextStep(actor);
        case 3:
            if (children->action != NULL) {
                break;
            }
            children->balloon = FIELDSTG_createBalloon(0, 1, 6);
            FIELDSTG_setActorAnim(actor, 0x12);
            actor->nextStep(actor);
        case 4:
            actor->counter += GFX.funcs.getFrameTime();
            if (actor->counter < 0x3C) {
                break;
            }
            children->balloon->setState(children->balloon, 2);
            FIELDSTG_setActorAnim(actor, 0x15);
            actor->nextStep(actor);
        case 5:
            if (actor->animDone != 0) {
                actor->setSubstate(actor, 1);
                FIELDSTG_setActorAnim(actor, 1);
                FIELDSTG_restorePlayerControl(actor);
                D_800990B4.busy = 0;
            }
            break;
        }
        break;
    case 0x49:
        switch (actor->step) {
        case 0:
        default:
            actor->control = NULL;
            FIELDSTG_setActorAnim(actor, 8);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 1);
            FIELDSTG_setActorAnim(actor, 1);
            FIELDSTG_restorePlayerControl(actor);
            D_800990B4.acting = 0;
        }
        break;
    case 0x4A:
        isX = 0;
        if (actor->key1 == 0x21 || (actor->key1 >= 0x4D && actor->key1 < 0x58) ||
            (actor->key1 >= 0x154 && actor->key1 < 0x159) || actor->key1 == 0x15B) {
            isX = 1;
        }
        switch (actor->step) {
        case 0:
        default:
            talk = actor->entry->talks;
            while (1) {
                if (talk->conditions == NULL) {
                    break;
                }
                if (FLAGS_00.checkConditions(talk->conditions) == 1) {
                    break;
                }
                talk++;
            }
            actor->talkActions = (s32)talk->actions;
            if (!isX && actor->isLarge == 0) {
                actor->dir = (actor->talkPartner->dir + 4) & 7;
            }
            if (actor->animFile != 0 && !isX) {
                children->speech = FIELDSTG_createTalk(actor, talk->unk8);
            } else {
                children->speech = FIELDSTG_createTalk(actor->talkPartner, talk->unk8);
            }
            if (isX) {
                FIELDSTG_setActorAnim(actor, 0x41);
                SOUND.playSound(0x80045DC7);
            }
            actor->nextStep(actor);
            break;
        case 1:
            if (children->speech == NULL) {
                if (!isX) {
                    actor->setSubstate(actor, 1);
                } else {
                    actor->setState(actor, 3);
                }
                other = actor->talkPartner;
                if (other->flying == 0) {
                    FIELDSTG_restorePlayerControl(other);
                } else {
                    other->control = FIELDSTG_controlFlight;
                }
                if (actor->talkActions != 0) {
                    FLAGS_00.applyActions((u16 *)actor->talkActions);
                }
                D_800990B4.acting = 0;
            }
            break;
        }
        break;
    case 0x4D:
        switch (actor->step) {
        case 0:
        default:
#if VERSION_EU
            D_800990B4.acting = 1;
#endif
            actor->control = NULL;
            FIELDSTG_setActorAnim(actor, 0x45);
            actor->nextStep(actor);
        case 1:
            break;
        }
        if (actor->animDone != 0) {
            actor->setSubstate(actor, 1);
            FIELDSTG_setActorAnim(actor, 1);
            FIELDSTG_restorePlayerControl(actor);
#if VERSION_EU
            D_800990B4.acting = 0;
#endif
        }
        break;
    case 0x4E:
        switch (actor->step) {
        case 0:
        default:
            if (actor->counter < 0x14) {
                actor->counter += GFX.funcs.getFrameTime();
                break;
            }
            FIELDSTG_setActorAnim(actor, 0x54);
            SOUND.playSound(0x800446C9);
#if VERSION_EU
            switch (actor->key1) {
            case 0x148:
                FLAGS_00.applyAction(8, 1);
                break;
            case 0x15F:
                FLAGS_00.applyAction(9, 1);
                break;
            case 0x160:
                FLAGS_00.applyAction(0xA, 1);
                break;
            }
#endif
            actor->nextStep(actor);
        case 1:
            if (actor->animDone != 0) {
#if VERSION_US
                switch (actor->key1) {
                case 0x148:
                    FLAGS_00.applyAction(8, 1);
                    break;
                case 0x15F:
                    FLAGS_00.applyAction(9, 1);
                    break;
                case 0x160:
                    FLAGS_00.applyAction(0xA, 1);
                    break;
                }
#endif
                actor->setState(actor, 3);
            }
            break;
        }
        break;
    }
}

void FIELDSTG_haltPartners(void) {
    s32 i;
    Actor *actor;

    for (i = 0; i < 3; i++) {
        actor = TASK_REGISTRY.funcs.find(5, -1, FIELDSTG_haltedPartners[i]);
        if (actor != NULL) {
            actor->control = FIELDSTG_drainTrail;
        }
    }
}

void FIELDSTG_resumePartners(void) {
    s32 i;
    Actor *actor;

    for (i = 0; i < 3; i++) {
        actor = TASK_REGISTRY.funcs.find(5, -1, FIELDSTG_followingPartners[i]);
        if (actor != NULL) {
            actor->control = FIELDSTG_followLeader;
        }
    }
}

void FIELDSTG_getFacingTile(Actor *actor, Point *out) {
    Point *delta = &FIELDSTG_dirSteps[actor->dir];

    out->x = actor->tile.x + delta->x;
    out->y = actor->tile.y + delta->y;
}

void FIELDSTG_updateActor(Actor *actor, ActorChildren *children) {
    Layer *layer;

    switch (actor->state) {
        default:
        case 0:
            if (actor->animFile == 0 || FILE_CACHE.isLoading(actor->animFile >> 16) == 0) {
                if (actor->key2 == 0) {
                    children->icon = FIELDSTG_createActorIcon(actor);
                }
                actor->nextState(actor);
            }
            break;
        case 1:
            if ((actor->key2 & 0xE) || D_800990B4.bannerShown == 0) {
                if (actor->control != NULL) {
                    actor->control(actor);
                }
            }
            FIELDSTG_runActorAction(actor, children);
            actor->tile.x = actor->pos.x >> 8;
            actor->tile.y = (actor->pos.y - actor->climbHeight) >> 8;
            if (actor->animFile != 0) {
                FIELDSTG_animateActor(actor);
                if (actor->tile.x + actor->tile.y != 0) {
                    layer = GFX.funcs.getLayer(0x1002);
                    layer->addSortedCallback(layer, FIELDSTG_drawActor, actor, actor->tile.y, 0);
                }
            }
            break;
        case 2:
            break;
        case 3:
            GAME.unk26EC = actor->z;
            if (actor->voice != -1) {
                SOUND.keyOff(0xA0045F4A, actor->voice);
            }
            if (actor->trail != NULL) {
                HEAP.free(actor->trail);
            }
            break;
    }
}

/*
 * Creates a character (id 5): key1 is the character, key2 its kind (0 the
 * player, 2 to 8 a follower, the others the map's characters).
 *
 * The match depends on kind holding getModeArg's result in the player's
 * branch, where kind is no longer needed: its second set keeps local-alloc
 * from doubling its live length, which puts it before the constant 1 in the
 * global allocator (the European version matches either way).
 */
Actor *FIELDSTG_createActor(s32 key1, s32 kind, s32 image, FieldActorEntry *entry) {
    Actor *actor = createTaskWithId(FIELDSTG_updateActor, sizeof(Actor), 0x10, 5);
    s32 isLarge;

    actor->walkInDir = FIELDSTG_walkActorInDir;
    actor->climbUp = FIELDSTG_startClimbUp;
    actor->climbDown = FIELDSTG_startClimbDown;
    actor->dropDown = FIELDSTG_startDrop;
    actor->playGauge = FIELDSTG_startActorGauge;
    actor->warp = FIELDSTG_warpActor;
    actor->startWalk = FIELDSTG_startActorWalk;
    actor->startSlide = FIELDSTG_startActorSlide;
    actor->stopSlide = FIELDSTG_stopActorSlide;
    actor->launch = FIELDSTG_launchActor;
    actor->resetControl = FIELDSTG_resetActorControl;
    actor->setDir = FIELDSTG_setActorDir;
    actor->isAnimDone = FIELDSTG_isActorAnimDone;
    actor->isWalking = FIELDSTG_isActorWalking;
    actor->setGoal = FIELDSTG_setActorGoal;
    actor->setAnim = FIELDSTG_setActorAnim;
    actor->setPose = FIELDSTG_setActorPose;
    actor->key1 = key1;
    actor->key2 = kind;
    actor->getFacingTile = FIELDSTG_getFacingTile;
    actor->animFile = D_800990B4.getFileEntry(key1);
    actor->halfWidth = D_800990B4.getActorWidth(key1) >> 1;
    actor->animSet = 1;
    actor->dir = 1;
    actor->image = &D_800990B4.images.actors[image + 2];
    actor->fieldImage = D_800990B4.images.field;
    FILE_CACHE.request(actor->animFile >> 16);
#if VERSION_EU
    if (NTSC_MODE) {
        actor->speed = 0x400;
    } else {
        actor->speed = 0x4CC;
    }
#else
    actor->speed = 0x400;
#endif
    if (key1 == 0x146) {
        actor->speed /= 2;
    }
    actor->voice = -1;
    actor->depth = 4;
    if (kind == 0) {
        if (key1 == 0x147) {
            actor->control = FIELDSTG_controlFlight;
            if (GAME.clearTempFlags) {
                actor->z = 0x3000;
            } else {
                actor->z = GAME.unk26EC;
            }
            actor->flying = 1;
        } else {
            actor->control = FIELDSTG_controlPlayer;
        }
        kind = GAME.funcs.getModeArg();
        if (kind != -1) {
            actor->pos = D_800990B4.start;
            actor->dir = D_800990B4.startDir;
        } else {
            actor->pos = D_800990B4.defaultStart;
            actor->dir = D_800990B4.defaultStartDir;
        }
        actor->tile.x = actor->pos.x >> 8;
        actor->tile.y = actor->pos.y >> 8;
        if (GAME.clearTempFlags) {
            actor->depth = 4;
            GAME.unk26E0 = 4;
        } else {
            actor->depth = GAME.unk26E0;
        }
    } else if (kind & 0xE) {
        actor->trail = HEAP.allocZeroed(sizeof(Trail), 2);
        actor->control = FIELDSTG_followLeader;
        if (kind == 2) {
            actor->trail->tail = 0x37;
        } else if (kind == 4) {
            actor->trail->tail = 0x2E;
        } else {
            actor->trail->tail = 0x25;
        }
        if (GAME.clearTempFlags) {
            actor->depth = 4;
            GAME.unk26E0 = 4;
        } else {
            actor->depth = GAME.unk26E0;
        }
    } else {
        isLarge = key1 == 0x28;
        if (key1 == 0x29) {
            isLarge = 1;
        }
        if (key1 == 0x2A) {
            isLarge = 1;
        }
        if (key1 == 0x3E) {
            isLarge = 1;
        }
        if (key1 == 0x11A) {
            isLarge = 1;
        }
        actor->isLarge = isLarge;
        actor->hasShadow = 1;
        if (key1 == 0x82) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x83) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x11F) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x13C) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x13F) {
            actor->hasShadow = 0;
        }
        if (key1 == 0xD5) {
            actor->hasShadow = 0;
        }
        actor->entry = entry;
    }
    return actor;
}

void func_80090864(void) {
    FLAGS_00.applyAction(0x707E, 1);
    FLAGS_00.applyAction(0x8B19, 1);
    FLAGS_00.applyAction(0x400, 1);
}

void func_800908C4(void) {
    FLAGS_00.applyAction(0x400, 1);
}

void func_800908F0(void) {
    FLAGS_00.applyAction(0x707E, 1);
    FLAGS_00.applyAction(0x8B1F, 1);
    FLAGS_00.applyAction(0x401, 1);
}

void func_80090950(void) {
    FLAGS_00.applyAction(0x401, 1);
}

void func_8009097C(void) {
    FLAGS_00.applyAction(0x707F, 1);
    FLAGS_00.applyAction(0x8B1A, 1);
    FLAGS_00.applyAction(0x402, 1);
}

void func_800909DC(void) {
    FLAGS_00.applyAction(0x402, 1);
}

void func_80090A08(void) {
    FLAGS_00.applyAction(0x707F, 1);
    FLAGS_00.applyAction(0x8B20, 1);
    FLAGS_00.applyAction(0x403, 1);
}

void func_80090A68(void) {
    FLAGS_00.applyAction(0x403, 1);
}

void func_80090A94(void) {
    FLAGS_00.applyAction(0x7080, 1);
    FLAGS_00.applyAction(0x8489, 1);
    FLAGS_00.applyAction(0x404, 1);
}

void func_80090AF4(void) {
    FLAGS_00.applyAction(0x404, 1);
}

void func_80090B20(void) {
    FLAGS_00.applyAction(0x7080, 1);
    FLAGS_00.applyAction(0x8495, 1);
    FLAGS_00.applyAction(0x405, 1);
}

void func_80090B80(void) {
    FLAGS_00.applyAction(0x405, 1);
}

void func_80090BAC(void) {
    FLAGS_00.applyAction(0x7081, 1);
    FLAGS_00.applyAction(0x847C, 1);
    FLAGS_00.applyAction(0x406, 1);
}

void func_80090C0C(void) {
    FLAGS_00.applyAction(0x406, 1);
}

void func_80090C38(void) {
    FLAGS_00.applyAction(0x7081, 1);
    FLAGS_00.applyAction(0x8462, 1);
    FLAGS_00.applyAction(0x407, 1);
}

void func_80090C98(void) {
    FLAGS_00.applyAction(0x407, 1);
}

void func_80090CC4(void) {
    FLAGS_00.applyAction(0x7082, 1);
    FLAGS_00.applyAction(0x8ADE, 1);
    FLAGS_00.applyAction(0x408, 1);
}

void func_80090D24(void) {
    FLAGS_00.applyAction(0x408, 1);
}

void func_80090D50(void) {
    FLAGS_00.applyAction(0x7082, 1);
    FLAGS_00.applyAction(0x8AE8, 1);
    FLAGS_00.applyAction(0x409, 1);
}

void func_80090DB0(void) {
    FLAGS_00.applyAction(0x409, 1);
}

void func_80090DDC(void) {
    FLAGS_00.applyAction(0x7083, 1);
    FLAGS_00.applyAction(0x8AF4, 1);
    FLAGS_00.applyAction(0x40A, 1);
}

void func_80090E3C(void) {
    FLAGS_00.applyAction(0x40A, 1);
}

void func_80090E68(void) {
    FLAGS_00.applyAction(0x7083, 1);
    FLAGS_00.applyAction(0x8AF3, 1);
    FLAGS_00.applyAction(0x40B, 1);
}

void func_80090EC8(void) {
    FLAGS_00.applyAction(0x40B, 1);
}

void func_80090EF4(void) {
    FLAGS_00.applyAction(0x7084, 1);
    FLAGS_00.applyAction(0x8B01, 1);
    FLAGS_00.applyAction(0x40C, 1);
}

void func_80090F54(void) {
    FLAGS_00.applyAction(0x40C, 1);
}

void func_80090F80(void) {
    FLAGS_00.applyAction(0x7085, 1);
    FLAGS_00.applyAction(0x8B0D, 1);
    FLAGS_00.applyAction(0x40D, 1);
}

void func_80090FE0(void) {
    FLAGS_00.applyAction(0x40D, 1);
}

void func_8009100C(void) {
    FLAGS_00.applyAction(0x7086, 1);
    FLAGS_00.applyAction(0x8B02, 1);
    FLAGS_00.applyAction(0x40E, 1);
}

void func_8009106C(void) {
    FLAGS_00.applyAction(0x40E, 1);
}

void func_80091098(void) {
    FLAGS_00.applyAction(0x7087, 1);
    FLAGS_00.applyAction(0x8B0F, 1);
    FLAGS_00.applyAction(0x40F, 1);
}

void func_800910F8(void) {
    FLAGS_00.applyAction(0x40F, 1);
}

/* The color the field's stage starts with (FieldState.spriteColor) */
const CVECTOR D_80082E88 = {0x80, 0x80, 0x80, 0};

#if VERSION_US
#define FIELD_FILE 0x19F
#elif VERSION_EU
#define FIELD_FILE 0x1AD
#endif

/*
 * The setup of the field's own stage (FIELDSTG_initFuncs), which fills
 * D_800990B4 as the stage overlays' setup functions do; some points of the
 * story change its soundBank and music. As theirs, the match depends on the
 * start position being set with a constructor, (Vec2){x, y}.
 */
void FIELDSTG_setupField(void) {
#if VERSION_US
    D_800990B4.textFile = 0xF0;
#endif
    D_800990B4.mapFile = FIELD_FILE - 1;
    D_800990B4.sheetEntry = FIELD_FILE << 16;
    D_800990B4.objects = FIELDSTG_mapObjects;
    D_800990B4.slots = FIELDSTG_slots;
#if VERSION_US
    D_800990B4.imageFile = 0x31D;
#elif VERSION_EU
    D_800990B4.imageFile = 0x32C;
    D_800990B4.textFile = LANGUAGE + 0xE8;
#endif
    D_800990B4.start = (Vec2){0x6700, 0x12300};
    D_800990B4.images.field = &FIELDSTG_images.field;
    D_800990B4.soundBank = 0x42;
    D_800990B4.actors = FIELDSTG_actorList;
    D_800990B4.startDir = 0;
    D_800990B4.music = 0x61080002;
    D_800990B4.spriteColor = D_80082E88;
    D_800990B4.events = FIELDSTG_events;
    D_8009A70C.setFile(0, FIELD_FILE << 16 | 2);
    D_8009A70C.setFile(1, FIELD_FILE << 16 | 3);
    D_8009A70C.setFile(7, FIELD_FILE << 16 | 1);
    D_8009A70C.unk50(0);
    switch (GAME.progress) {
    case 5:
    case 8:
    case 12:
    case 14:
    case 16:
    case 22:
    case 24:
    case 26:
    case 28:
    case 30:
    case 31:
    case 34:
    case 36:
    case 37:
    case 38:
    case 39:
        D_800990B4.soundBank = 0x42;
        D_800990B4.music = 0x61080000;
        break;
    }
}

void func_80091298(Tween *tween, s32 in) {
    tween->active = 1;
    if (in) {
        SOUND.playSound(SOUND_MENU_OPEN);
        tween->value = 0;
        tween->step = 0x1000 / tween->duration;
    } else {
        SOUND.playSound(SOUND_MENU_CLOSE);
        tween->value = 0x1000;
        tween->step = -(0x1000 / tween->duration * 2);
    }
}

s32 func_8009132C(Tween *tween) {
    if (tween->active == 0) {
        return 1;
    }
    tween->value += tween->step;
    if (tween->step > 0) {
        if (tween->value > 0x1000) {
            tween->value = 0x1000;
            tween->active = 0;
            return 1;
        }
    } else if (tween->value < 0) {
        tween->value = 0;
        tween->active = 0;
        return 1;
    }
    return 0;
}

s32 FIELDSTG_getFileEntry(s32 index) {
    return FIELDSTG_fileEntries[index];
}

s32 FIELDSTG_getActorWidth(s32 index) {
    return FIELDSTG_actorWidths[index];
}

void FIELDSTG_pickStage(void) {
    StageEntry *entry;
    s32 mode;

#if VERSION_US
    entry = FIELDSTG_stages;
#elif VERSION_EU
    if (GAME.progress != 0x2D) {
        entry = FIELDSTG_euStages;
    } else {
        entry = FIELDSTG_stages;
    }
#endif
    mode = GAME.funcs.getMode();
    HEAP.zero(&D_800990B4, 100);
    while (1) {
        if (entry->mode == mode) {
            D_800990B4.stageFile = entry->file;
            D_800990B4.stageInit = entry->init;
            break;
        }
        if ((++entry)->mode == 0) {
            break;
        }
    }
    if (entry->mode == 0) {
        while (1) {
        }
    }
}

FieldBattles *FIELDSTG_findBattles(FieldBattles *list, s32 id) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (list->id == id) {
            return list;
        }
        list++;
    }
    return NULL;
}

void func_800914C0(void) {
    HEAP.zero(&FIELDSTG_scriptTimer, 8);
}

Actor *FIELDSTG_findActor(s32 arg0) {
    return TASK_REGISTRY.funcs.find(5, arg0, -1);
}

void func_80091520(s32 time, s32 *pc) {
    if (time != 0 && FIELDSTG_scriptTimer.active == 0) {
        FIELDSTG_scriptTimer.active = 1;
        FIELDSTG_scriptTimer.time = time;
    }
    FIELDSTG_scriptTimer.time -= GFX.funcs.getFrameTime();
    if (FIELDSTG_scriptTimer.time <= 0) {
        FIELDSTG_scriptTimer.time = 0;
        FIELDSTG_scriptTimer.active = 0;
        (*pc)++;
    }
}

void func_800915B0(s32 id, s32 *pc) {
    Actor *actor = FIELDSTG_findActor(id);

    if (actor->isAnimDone(actor) != 0) {
        (*pc)++;
    }
}

void func_800915FC(s32 id, s32 *pc) {
    Actor *actor = FIELDSTG_findActor(id);

    if (actor->isWalking(actor) == 0) {
        (*pc)++;
    }
}

void func_80091648(Point *pos) {
    Point scroll;
    Layer *layer = GFX.funcs.getLayer(0x1002);

    layer->getScroll(layer, &scroll);
    pos->x -= scroll.x;
    pos->y -= scroll.y;
}

void func_800916B4(void) {
    Actor *actor = FIELDSTG_findActor(1);

    if (actor == NULL) {
        actor = FIELDSTG_findActor(2);
    }
    actor->unk10C = 0;
}

ScriptCommand *func_800916E8(s32 id) {
    ScriptCommand *cmd;

    for (cmd = FIELDSTG_scriptCommands; cmd->id != 0; cmd++) {
        if (cmd->id == id) {
            return cmd;
        }
    }
    return NULL;
}

s32 func_80091730(s32 id) {
    ScriptCommand *cmd = func_800916E8(id);
    s32 ret = 0;

    if (cmd != NULL) {
        ret = cmd->create(id);
    }
    return ret;
}

void func_80091774(s32 arg0, s32 id, s32 arg2, s32 arg3) {
    ScriptCommand *cmd = func_800916E8(id);

    if (cmd != NULL && cmd->handle != NULL) {
        cmd->handle(arg0, arg2, arg3);
    }
}

void func_800917D8(void) {
    s32 value = RANDOM.next() % 2304;

    if (value < 0x100) {
        GAME.unk30 = value;
    } else {
        GAME.unk30 = (value + 0x100) / 2;
    }
}

void FIELDSTG_startAreaBattle(void) {
    Actor *actor = TASK_REGISTRY.funcs.find(5, -1, 0);
    Point tile;
    s32 area;
    s32 index;
    Battle *battle;

    tile = actor->tile;
    area = (u8)D_8009A70C.getCell(4, &tile) - 1;
    index = RANDOM.next() & 7;
    battle = D_800990B4.battles->battles[area]->battles[index];
    BATTLE_SETUP.stage = battle->unk4;
    BATTLE_SETUP.music = battle->unk8;
    FIELDSTG_startEncounter(battle->unk0);
}

void func_80091910(void) {
    Actor *actor;
    Point tile;
    s32 area;
    s32 rate;

    if (D_8009A70C.files[4] != 0 && D_800990B4.battles != NULL && D_800990B4.battleStarting == 0 &&
        D_800990B4.busy == 0 && D_800990B4.acting == 0 && D_800990B4.bannerShown == 0) {
        actor = TASK_REGISTRY.funcs.find(5, -1, 0);
        tile = actor->tile;
        area = (u8)D_8009A70C.getCell(4, &tile);
        if (area != 0) {
            area--;
            rate = FIELDSTG_battleRates[D_800990B4.battles->battles[area]->count];
            GAME.unk30 -= rate;
            if (GAME.unk30 <= 0) {
                if (BATTLE_SETUP.unk0 != 0) {
                    FIELDSTG_startAreaBattle();
                }
                func_800917D8();
            }
        }
    }
}

void FIELDSTG_startEventBattle(s32 index) {
    Battle *battle;

    if (D_800990B4.battles != NULL) {
        battle = D_800990B4.battles->battles[3]->battles[index];
        BATTLE_SETUP.stage = battle->unk4;
        BATTLE_SETUP.music = battle->unk8;
        FIELDSTG_startEncounter(battle->unk0);
    }
}

/*
 * Points the map at the file of map index: the grid, whose first two bytes
 * are its width and height, the levels of cells and the pixels, at the
 * offsets the file's entry starts with. Returns 0 when no file is set. The
 * match depends on the file's check being an early exit, a do-while (0)
 * that breaks once the file is set, with file declared in it: the block's
 * note stops stmt.c from rolling the exit test to the loop's end, and the
 * loop notes keep the prologue's stores of ra and s0 ahead of the load in
 * the second scheduler.
 */
s32 func_80091AA8(s32 index) {
    s32 *entry;
    u8 *grid;

    do {
        s32 file = D_8009A70C.files[index];

        if (file != 0) {
            break;
        }
        return 0;
    } while (0);
    entry = (s32 *)FILE_CACHE.getEntry(D_8009A70C.files[index]);
    D_8009A70C.grid = (u8 *)(entry[0] + (s32)entry);
    D_8009A70C.cells64 = (u8 *)(entry[1] + (s32)entry);
    D_8009A70C.cells32 = (s16 *)(entry[2] + (s32)entry);
    D_8009A70C.cells16 = (s16 *)(entry[3] + (s32)entry);
    D_8009A70C.cells8 = (s16 *)(entry[4] + (s32)entry);
    D_8009A70C.pixels = (u8 *)(entry[5] + (s32)entry);
    grid = D_8009A70C.grid;
    D_8009A70C.width = grid[0];
    D_8009A70C.height = grid[1];
    D_8009A70C.grid = grid + 2;
    return 1;
}

void func_80091B78(s32 index, s32 value) {
    D_8009A70C.files[index] = value;
}

void func_80091B90(s32 arg0) {
    if (GAME.clearTempFlags != 0) {
        GAME.unk26D8 = arg0;
    }
}

void func_80091BB4(s32 arg0) {
    GAME.unk26D8 = arg0;
}

s32 func_80091BC0(s32 index, Point *pos) {
    s32 x;
    s32 y;
    s32 i;

    if (func_80091AA8(index) == 0) {
        return 1;
    }
    y = pos->y;
    x = pos->x;
    /* the match depends on the * 4 being a statement of its own */
    i = D_8009A70C.grid[y / 128 * D_8009A70C.width + x / 128];
    i *= 4;
    if (y & 0x40) {
        i += 2;
    }
    i = D_8009A70C.cells64[(x & 0x40) ? i + 1 : i];
    i *= 4;
    if (y & 0x20) {
        i += 2;
    }
    i = D_8009A70C.cells32[(x & 0x20) ? i + 1 : i];
    i *= 4;
    if (y & 0x10) {
        i += 2;
    }
    i = D_8009A70C.cells16[(x & 0x10) ? i + 1 : i];
    i *= 4;
    if (y & 8) {
        i += 2;
    }
    i = D_8009A70C.cells8[(x & 8) ? i + 1 : i];
    return D_8009A70C.pixels[i * 64 + (y & 7) * 8 + (x & 7)];
}

/* Whether nothing stands at pos: no character's box (gathered once a frame)
   and no object. The match depends on the boxes' variables being local to
   their blocks. */
s32 FIELDSTG_isTileFree(Point *pos) {
    s32 frame = GFX.funcs.getFrameCount();
    Actor *actor;
    s32 i;

    if (frame != FIELDSTG_boxFrame) {
        actor = TASK_REGISTRY.funcs.find(5, -1, 1);
        for (i = 0; actor != NULL; i++) {
            s32 width = actor->halfWidth;

            FIELDSTG_boxes[i].left = actor->tile.x - width;
            FIELDSTG_boxes[i].right = actor->tile.x + width;
            width /= 2;
            FIELDSTG_boxes[i].top = actor->tile.y - width;
            FIELDSTG_boxes[i].bottom = actor->tile.y + width;
            actor = TASK_REGISTRY.funcs.findNext();
        }
        FIELDSTG_boxCount = i;
        FIELDSTG_boxFrame = frame;
    }
    for (i = 0; i < FIELDSTG_boxCount; i++) {
        if (pos->x >= FIELDSTG_boxes[i].left && FIELDSTG_boxes[i].right >= pos->x && pos->y >= FIELDSTG_boxes[i].top
            && FIELDSTG_boxes[i].bottom >= pos->y) {
            s32 dx = pos->x - FIELDSTG_boxes[i].left;
            s32 dy = pos->y - FIELDSTG_boxes[i].top;
            s32 width = FIELDSTG_boxes[i].right - FIELDSTG_boxes[i].left;
            s32 height = FIELDSTG_boxes[i].bottom - FIELDSTG_boxes[i].top;
            s32 halfWidth = width / 2;
            s32 halfHeight = height / 2;
            s32 ratio = width / height;

            if (halfWidth < dx) {
                dx = halfWidth - (dx - halfWidth);
            }
            if (halfHeight < dy) {
                dy = halfHeight - (dy - halfHeight);
            }
            if (dx >= halfWidth - dy * ratio) {
                return 0;
            }
        }
    }
    return FIELDSTG_findHiddenSpot(pos, 0) == NULL;
}

void func_80091F4C(Point *pos, s32 scale, s32 index, Point *out) {
    s32 cell = (u8)func_80091BC0(GAME.unk26D8, pos);
    s32 row = cell & 0xF;
    s32 dir;
    s32 sign;

    row -= row != 0;
    dir = (cell & 0x10) ? FIELDSTG_mirrorDirs[index] : index;
    sign = (cell & 0x10) ? -1 : 1;
    out->x = FIELDSTG_dirVectors[row][dir].x * scale * sign / 4096;
    out->y = FIELDSTG_dirVectors[row][dir].y * scale / 4096;
}

void func_8009204C(Point *pos, s32 scale, s32 index, Point *out) {
    out->x = FIELDSTG_dirVectors[0][index].x * scale / 4096;
    out->y = FIELDSTG_dirVectors[0][index].y * scale / 4096;
}
