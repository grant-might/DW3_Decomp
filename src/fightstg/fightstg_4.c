/* The fourth object of FIGHTSTG.PRO (see fightstg.c), from the stage lights:
   its rodata starts at 0x800825B4 (USA), 4 bytes past a multiple of 8. */

#include "fightstg.h"

/* The stage lights' task: steps their fade, then sets the three flat lights
   and the ambient color for the layer each frame */
void FIGHTSTG_updateLights(Lights *task) {
    SVECTOR from;
    SVECTOR to;
    SVECTOR out;
    Layer *layer;
    s32 t;
    s32 i;
    s32 j;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->t = 0x1000;
        task->nextState(task);
        break;
    case TASK_DONE:
        task->setState(task, TASK_RUN);
        task->setSubstate(task, 1);
        /* fallthrough */
    case TASK_RUN:
        switch (task->substate) {
        case 1:
        case 2:
            if (task->t != 0x1000) {
                task->t += task->tStep * GFX.funcs.getFrameTime();
                if (task->t < 0x1000) {
                    t = task->t;
                    for (i = 0; i < 3; i++) {
                        from.vx = task->from.lights[i].vx;
                        from.vy = task->from.lights[i].vy;
                        from.vz = task->from.lights[i].vz;
                        to.vx = task->to.lights[i].vx;
                        to.vy = task->to.lights[i].vy;
                        to.vz = task->to.lights[i].vz;
                        FIGHTSTG_interp.lerp(&from, &to, t, &out);
                        task->current.lights[i].vx = out.vx;
                        task->current.lights[i].vy = out.vy;
                        task->current.lights[i].vz = out.vz;
                        from.vx = task->from.lights[i].r;
                        from.vy = task->from.lights[i].g;
                        from.vz = task->from.lights[i].b;
                        to.vx = task->to.lights[i].r;
                        to.vy = task->to.lights[i].g;
                        to.vz = task->to.lights[i].b;
                        FIGHTSTG_interp.lerp(&from, &to, t, &out);
                        task->current.lights[i].r = out.vx;
                        task->current.lights[i].g = out.vy;
                        task->current.lights[i].b = out.vz;
                    }
                    from.vx = task->from.ambient[0];
                    from.vy = task->from.ambient[1];
                    from.vz = task->from.ambient[2];
                    to.vx = task->to.ambient[0];
                    to.vy = task->to.ambient[1];
                    to.vz = task->to.ambient[2];
                    FIGHTSTG_interp.lerp(&from, &to, t, &out);
                    task->current.ambient[0] = out.vx;
                    task->current.ambient[1] = out.vy;
                    task->current.ambient[2] = out.vz;
                } else {
                    task->t = 0x1000;
                    task->current = task->to;
                }
            }
            GsSetLightMode(0);
            for (j = 0; j < 3; j++) {
                GsSetFlatLight(j, &task->current.lights[j]);
            }
            SetBackColor(task->current.ambient[0], task->current.ambient[1], task->current.ambient[2]);
            layer = GFX.funcs.getLayer(task->layerId);
            layer->setKeepLightMatrix(layer, 1);
            if (task->t == 0x1000) {
                task->nextSubstate(task);
            }
            break;
        }
        break;
    case TASK_KILL:
        layer = GFX.funcs.getLayer(task->layerId);
            layer->setKeepLightMatrix(layer, 0);
        break;
    }
}

/* Lights.set: switches to SET at once */
void FIGHTSTG_setLights(Lights *task, LightSet *set) {
    task->current = *set;
    task->setState(task, TASK_DONE);
}

/* Lights.fade: fades from FROM (NULL for the current lights) to TO over TIME */
void FIGHTSTG_fadeLights(Lights *task, LightSet *from, LightSet *to, s32 time) {
    if (from != NULL) {
        task->from = *from;
    } else {
        task->from = task->current;
    }
    task->to = *to;
    task->tStep = 0x1000 / time;
    task->t = task->tStep * GFX.funcs.getFrameTime();
    task->setState(task, TASK_DONE);
}

/* Lights.getStageLights: fight stage STAGE's lights */
LightSet *FIGHTSTG_getStageLights(Lights *task, s32 stage) {
    return &((FightStageInfo *)FILE_CACHE.load(FILE_FIGHT_STAGES))[stage].lights;
}

/* Creates the stage lights (id 0x13) for layer layerId */
Lights *FIGHTSTG_createLights(s32 layerId) {
    Lights *task = createTaskWithId(FIGHTSTG_updateLights, sizeof(Lights), 0, BATTLE_TASK_LIGHTS);
    task->set = FIGHTSTG_setLights;
    task->fade = FIGHTSTG_fadeLights;
    task->layerId = layerId;
    task->getStageLights = FIGHTSTG_getStageLights;
    return task;
}

s32 FIGHTSTG_getEyesFrame(Face *task) {
    switch (task->model->motion) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return 2;
    case 2:
        return 1;
    default:
        return 0;
    }
}

void FIGHTSTG_moveFacePart(Face *task, DR_MOVE *prim, s32 part, s32 frame) {
    RECT rect;
    Vec2 pos;

    rect.x = task->parts[part].rect.frames[frame][0] + task->texPos.x;
    rect.y = task->parts[part].rect.frames[frame][1] + task->texPos.y;
    rect.w = task->parts[part].rect.w;
    rect.h = task->parts[part].rect.h;
    pos.x = task->parts[part].rect.x + task->texPos.x;
    pos.y = task->parts[part].rect.y + task->texPos.y;
    SetDrawMove(prim, &rect, pos.x, pos.y);
}

void FIGHTSTG_updateFace(Face *task) {
    Layer *layer;
    u_long *ot;
    DR_MOVE *prim;
    s32 eyes;
    s32 frame;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        if (task->partCount == 0) {
            task->setState(task, TASK_KILL);
        } else {
            task->nextState(task);
        }
        break;
    case TASK_RUN:
        eyes = FIGHTSTG_getEyesFrame(task);
        if (eyes == 0) {
            switch (task->blinkTimer >> 1) {
            case 0:
                task->blinkTimer = (RANDOM.next() & 0x7F) + 60;
            default:
                eyes = 0;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                eyes = 1;
                break;
            case 3:
            case 4:
                eyes = 2;
                break;
            }
            task->blinkTimer -= FIGHTSTG_battle.frames;
            if (task->blinkTimer < 0) {
                task->blinkTimer = 0;
            }
        } else {
            task->blinkTimer = 0;
        }
        task->time += FIGHTSTG_battle.frames;
        frame = task->time % 18 / 6;
        layer = GFX.funcs.getLayer(SCREEN_LAYER);
        ot = (u_long *)layer->getOtEntry(layer, 0);
        prim = GFX.funcs.getPrim();
        for (i = 0; i < 2; i++) {
            if (task->parts[i].used && task->parts[i].frame != eyes) {
                task->parts[i].frame = eyes;
                FIGHTSTG_moveFacePart(task, prim, i, eyes);
                addPrim(ot, prim);
                prim++;
            }
        }
        for (i = 2; i < 16; i++) {
            if (task->parts[i].used && task->parts[i].frame != frame) {
                task->parts[i].frame = frame;
                FIGHTSTG_moveFacePart(task, prim, i, frame);
                addPrim(ot, prim);
                prim++;
            }
        }
        GFX.funcs.setPrim(prim);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

Face *FIGHTSTG_createFace(Model *model, s32 fighter) {
    Face *task;
    FaceRect *rects;
    s32 i;

    if (fighter == 0) {
        return NULL;
    }
    task = createTask(FIGHTSTG_updateFace, sizeof(Face), 0);
    task->model = model;
    task->texPos = model->texPos;
    rects = FIGHTSTG_fighterCache.getFace(fighter);
    for (i = 15; i >= 0; i--) {
        task->parts[i].used = 0;
    }
    for (i = 0; i < 16; i++) {
        if (rects[i].x == 0xFF) {
            return task;
        }
        if (rects[i].w != 0) {
            task->parts[i].rect = rects[i];
            task->parts[i].used = 1;
            task->partCount++;
        }
    }
    return task;
}
