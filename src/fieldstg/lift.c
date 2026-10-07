/* The lift of the map objects 2 and 3. Its rodata, at 0x800824C4 (USA),
   starts FIELDSTG.PRO's second object (see data/fieldstg.c). */

#include "fieldstg.h"

/*
 * A lift made of the map objects 2 and 3: in TASK_DONE it shakes, moves the
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
    case TASK_INIT:
    default:
        task->nextState(task);
        for (object = FIELDSTG_state.objects; object->unk2 != 0; object++) {
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
    case TASK_RUN:
        break;
    case TASK_DONE:
        left = task->left;
        right = task->right;
        player = TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, -1, 0);
        switch (task->substate) {
        case 0:
        default:
            right->visible = 1;
            task->time = 0;
            task->leftY = left->y;
            task->rightY = right->y;
            task->playerY = player->pos.y;
            SOUND.playSound(SOUND_SWITCH01);
            task->nextSubstate(task);
            break;
        case 1:
            task->time += GFX.funcs.getFrameTime();
            if (task->time >= 30) {
                task->shake = 0;
                task->nextSubstate(task);
                SOUND.playSound(SOUND_ELEVATER);
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
            task->setState(task, TASK_RUN);
            task->raised ^= 1;
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Runs a script command of the lift's: lowers or raises it */
void FIELDSTG_moveLift(Lift *task, s32 command) {
    if (task != NULL) {
        switch (command) {
        case LIFT_LOWER:
            task->setState(task, TASK_DONE);
            task->raised = 0;
            break;
        case LIFT_RAISE:
            task->setState(task, TASK_DONE);
            task->raised = 1;
            break;
        }
    }
}

/* Creates the lift, raised when flag 0x1C3D is set */
Lift *FIELDSTG_createLift(s32 id) {
    Lift *task = createTaskWithId(FIELDSTG_updateLift, sizeof(Lift), 0, id);

    if (FLAGS_00.checkCondition(FLAG(0x1C, 0x3D), 1)) {
        task->raised = 1;
    } else {
        task->raised = 0;
    }
    return task;
}
