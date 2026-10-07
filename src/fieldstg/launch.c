/* The launchers, which send an actor flying to a tile */

#include "fieldstg.h"
#include "stages.h"

/* radius times the sine of angle */
s32 FIELDSTG_scaleSin(s32 angle, s32 radius) {
    return rsin(angle >> 2) * radius / 4096;
}

/* Sends an actor from the nearest FIELD_TASK_LAUNCHER (y counts twice in the
 * distance) to its dest tile: the actor walks to the task, sets it to
 * TASK_DONE, waits for it to leave that state, then moves along a quarter
 * sine, spinning, until it lands; without such a task it ends at once. The
 * match depends on the distance written twice. */
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
    case TASK_INIT:
    default:
        best = 0x8000;
        found = NULL;
        pos.x = task->actor->tile.x;
        pos.y = task->actor->tile.y;
        for (t = TASK_REGISTRY.funcs.find(FIELD_TASK_LAUNCHER, -1, -1); t != NULL; t = TASK_REGISTRY.funcs.findNext()) {
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
            task->setState(task, TASK_KILL);
            break;
        }
        task->from = found;
        task->start.x = near.x + 0x14;
        task->start.y = near.y + 0xD;
        task->nextState(task);
    case TASK_RUN:
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
                task->from->setState(task->from, TASK_DONE);
                SOUND.playSound(SOUND_TELEPORT);
                task->nextStep(task);
            case 1:
                if (task->from->state != TASK_DONE) {
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
            task->setState(task, TASK_KILL);
            break;
        }
        break;
    case TASK_DONE:
        break;
    case TASK_KILL:
        task->actor->dir = 0;
        task->actor->hasShadow = 1;
        FIELDSTG_state.busy = 0;
        task->actor->resetControl(task->actor);
        FIELDSTG_resumePartners();
        break;
    }
}

/* Creates the flight of an actor to the tile at dest; two stages' modes
   (0x26C, 0x2D4) set theirs up */
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
