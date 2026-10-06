/* The second object of FIELDSTG.PRO (see fieldstg.c): its rodata starts at
   0x800824C4 (USA). */

#include "fieldstg.h"

/*
 * A lift made of the map objects 2 and 3: on state 2 it shakes, moves the
 * objects and the player 0x7F pixels up or down a pixel every other frame,
 * shakes again and flips raised.
 */
void FIELDSTG_updateLift(Lift *task) {
    StageTile *object;
    StageTile *left;
    StageTile *right;
    Actor *player;
    s32 offset;

    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        for (object = D_800990B4.objects; object->unk2 != 0; object++) {
            switch (object->anim) {
            case 2:
                task->right = object;
                task->rightBaseY = object->y;
                if (task->raised) {
                    object->y -= 0x7F;
                }
                object->visible = 0;
                break;
            case 3:
                task->left = object;
                task->leftBaseY = object->y;
                if (task->raised) {
                    object->y -= 0x7F;
                }
                object->visible = 1;
                break;
            }
        }
        task->raised = 0;
        break;
    case 1:
        break;
    case 2:
        left = task->left;
        right = task->right;
        player = TASK_REGISTRY.funcs.find(5, -1, 0);
        switch (task->substate) {
        case 0:
        default:
            right->visible = 1;
            task->time = 0;
            task->leftY = left->y;
            task->rightY = right->y;
            task->playerY = player->pos.y;
            SOUND.playSound(0x8004103C);
            task->nextSubstate(task);
            break;
        case 1:
            task->time += GFX.funcs.getFrameTime();
            if (task->time >= 30) {
                task->shake = 0;
                task->nextSubstate(task);
                SOUND.playSound(0x01080001);
            }
            break;
        case 2:
        case 4:
            offset = FIELDSTG_liftShake[task->shake];
            if (offset != 1000) {
                left->y = task->leftY + offset;
                right->y = task->rightY + offset;
                player->pos.y = task->playerY + offset;
                task->shake++;
            } else {
                task->nextSubstate(task);
                task->shake = 0;
            }
            break;
        case 3:
            task->shake++;
            if (task->shake >= 0xFE) {
                if (task->raised) {
                    left->y = task->leftBaseY;
                    right->y = task->rightBaseY;
                    player->pos.y = task->playerY + 0x7F00;
                } else {
                    left->y = task->leftBaseY - 0x7F;
                    right->y = task->rightBaseY - 0x7F;
                    player->pos.y = task->playerY - 0x7F00;
                }
                task->leftY = left->y;
                task->rightY = right->y;
                task->playerY = player->pos.y;
                task->nextSubstate(task);
                task->shake = 0;
            } else if (task->shake & 1) {
                if (task->raised) {
                    left->y++;
                    right->y++;
                    player->pos.y += 0x100;
                } else {
                    left->y--;
                    right->y--;
                    player->pos.y -= 0x100;
                }
            }
            break;
        case 5:
            right->visible = 0;
            task->setState(task, 1);
            task->raised ^= 1;
            break;
        }
        break;
    case 3:
        break;
    }
}

void FIELDSTG_moveLift(Lift *task, s32 arg1) {
    if (task != NULL) {
        switch (arg1) {
        case 0x348:
            task->setState(task, 2);
            task->raised = 0;
            break;
        case 0x349:
            task->setState(task, 2);
            task->raised = 1;
            break;
        }
    }
}

Lift *FIELDSTG_createLift(s32 id) {
    Lift *task = createTaskWithId(FIELDSTG_updateLift, sizeof(Lift), 0, id);

    if (FLAGS_00.checkCondition(0x1C3D, 1)) {
        task->raised = 1;
    } else {
        task->raised = 0;
    }
    return task;
}

/*
 * A yes/no question of the story (FIELDSTG_askChoice0 to FIELDSTG_askChoice15
 * make one per type): asks FIELDSTG_choices[type]'s question and starts the
 * event of the answer.
 */
void FIELDSTG_runChoice(ChoiceTask *task, ChoiceChildren *children) {
    SpriteDrawer drawer;
    s32 prev;
    s32 i;
    s32 j;
    s32 k;

    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        task->tween.duration = 10;
        for (i = 0; i < 2; i++) {
            children->options[i] = createTextWindow(0x1002, 1, 0x1C, 0xBE + i * 14);
            children->options[i]->setDepth(children->options[i], 1);
        }
        children->cursor = createCursor(0x1002, 1, 0x12, 0xBE);
        children->cursor->setVisible(children->cursor, 0);
        children->title = createTextWindow(0x1002, 1, 0x12, 0xB0);
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            FIELDSTG_tweenStart(&task->tween, 1);
            task->substate++;
            break;
        case 1:
            if (FIELDSTG_tweenUpdate(&task->tween)) {
                for (j = 0; j < 2; j++) {
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(FIELDSTG_choices[task->type].text + (TEXT_FILE(1) << 16)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(FIELDSTG_choices[task->type].text + (TEXT_FILE(1) << 16)), 1);
                task->substate++;
            }
            break;
        case 2:
            prev = task->selection;
            if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
                if (--task->selection < 0) {
                    task->selection = 0;
                }
            } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
                task->selection++;
                if (task->selection > 1) {
                    task->selection = 1;
                }
            }
            if (prev != task->selection) {
                SOUND.playSound(SOUND_CURSOR);
                children->cursor->setPos(children->cursor, 0x12, task->selection * 14 + 0xBE);
                break;
            }
            if (PAD_PRESSED(PAD_CROSS)) {
                SOUND.playSound(SOUND_SELECT);
                task->substate = 10;
            }
            break;
        case 3:
            children->event = FIELDSTG_startEvent(task->selection == 0 ? FIELDSTG_choices[task->type].events[0] : FIELDSTG_choices[task->type].events[1]);
            task->substate++;
            break;
        case 4:
            if (children->event == NULL) {
                task->state = 3;
            }
            break;
        case 10:
            for (k = 0; k < 2; k++) {
                children->options[k]->setVisible(children->options[k], 0);
            }
            children->cursor->setVisible(children->cursor, 0);
            children->title->setVisible(children->title, 0);
            FIELDSTG_tweenStart(&task->tween, 0);
            task->substate++;
            break;
        case 11:
            if (FIELDSTG_tweenUpdate(&task->tween)) {
                task->substate = 3;
            }
            break;
        }
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 2);
        drawer.setTexture(0x140, 0);
        drawer.setFollowScroll(0);
        if (task->tween.value != 0) {
            if (task->tween.value != 0x1000) {
                drawer.setScale(task->tween.value, 0x1000, 0x1000);
                drawer.setPivot(0, 0xC3);
            }
            drawer.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0x45, 0, 0xAC);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

void FIELDSTG_askChoice0(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 0;
}

void FIELDSTG_askChoice1(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 1;
}

void FIELDSTG_askChoice2(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 2;
}

void FIELDSTG_askChoice3(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 3;
}

void FIELDSTG_askChoice4(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 4;
}

void FIELDSTG_askChoice5(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 5;
}

void FIELDSTG_askChoice6(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 6;
}

void FIELDSTG_askChoice7(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 7;
}

void FIELDSTG_askChoice8(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 8;
}

void FIELDSTG_askChoice9(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 9;
}

void FIELDSTG_askChoice10(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 10;
}

void FIELDSTG_askChoice11(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 11;
}

void FIELDSTG_askChoice12(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 12;
}

void FIELDSTG_askChoice13(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 13;
}

void FIELDSTG_askChoice14(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 14;
}

void FIELDSTG_askChoice15(void) {
    ChoiceTask *task = createTask(FIELDSTG_runChoice, sizeof(ChoiceTask), 0x14);
    task->type = 15;
}

/*
 * Runs the story events: marks the map object 1 for the progresses that have
 * one, then starts the first event of FIELDSTG_progressEvents whose progress, flag and
 * condition hold, and its next script once the first one ends.
 */
void FIELDSTG_runStoryEvents(StoryEvents *task, StoryEventsChildren *children) {
    StageTile *object;
    ProgressEvent *event;
    s32 i;

    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        task->script = 0;
        for (object = D_800990B4.objects; object->unk2 != 0; object++) {
            if (object->anim == 1) {
                break;
            }
        }
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
            object->visible = 1;
            break;
        default:
            object->visible = 0;
            break;
        }
        children->lift = FIELDSTG_createLift(0x33A);
        for (i = 0; FIELDSTG_progressEvents[i].progress != -1; i++) {
            event = &FIELDSTG_progressEvents[i];
            if (GAME.progress == event->progress && FLAGS_00.checkCondition(event->flag, 0) &&
                FLAGS_00.checkCondition(event->condition, 1)) {
                children->script = FIELDSTG_startEvent(event->script);
                task->script = event->nextScript;
                break;
            }
        }
        break;
    case 1:
        if (children->script == NULL && task->script != 0) {
            children->script = FIELDSTG_startEvent(task->script);
            task->script = 0;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

StoryEvents *FIELDSTG_createStoryEvents(s32 arg0) {
    StoryEvents *task = createTask(FIELDSTG_runStoryEvents, sizeof(StoryEvents), 8);

    task->unk50 = arg0;
    FIELDSTG_initFuncs[0]();
    return task;
}
