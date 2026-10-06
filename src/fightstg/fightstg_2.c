/* The second object of FIGHTSTG.PRO (see fightstg.c), the fight stage: its
   rodata starts at 0x80082464 (USA), 4 bytes past a multiple of 8. */

#include "fightstg.h"

/* Sets the stage model's color and layer 0x1000's background to their fades'
   current values (a black background is drawn as 1, 1, 1) */
void FIGHTSTG_fadeStage(FightStage *task, Model **children) {
    u8 color[3];
    Model *model;
    Layer *layer;

    FIGHTSTG_interp.lerp(&task->colorFrom, &task->colorTo, task->fade, &task->color);
    color[0] = task->color.vx;
    color[1] = task->color.vy;
    color[2] = task->color.vz;
    model = children[0];
    model->setColor(model, 1, color);
    FIGHTSTG_interp.lerp(&task->bgFrom, &task->bgTo, task->fade, &task->bg);
    layer = GFX.funcs.getLayer(0x1000);
    if (task->bg.vx != 0 || task->bg.vy != 0 || task->bg.vz != 0) {
        layer->setBgColor(layer, (u8)task->bg.vx, (u8)task->bg.vy, (u8)task->bg.vz);
    } else {
        layer->setBgColor(layer, 1, 1, 1);
    }
}

const Vec2 FIGHTSTG_stageTexPos = { 0x280, 0 };

/* the fight stages' music (FightStageInfo.music), as sound ids */
s32 FIGHTSTG_stageMusic[8] = {
    0xA004E03C, 0xA004E0BD, 0xA004E13E, 0xA004E1BF,
    0xA004E240, 0xA004E2C1, 0xA004E342, 0xA004E3C3,
};

/* The fight stage's task: loads the stage's model, starts its music and fades
   in its lights, then fades the model's color and the background in from
   black; setStage fades them out, frees the old model and stops its music,
   and loads the new stage */
void FIGHTSTG_updateStage(FightStage *task, Model **children) {
    FightStageInfo *stages = (FightStageInfo *)FILE_CACHE.load(FILE_FIGHT_STAGES);
    Lights *lights;
    Model *model;
    Layer *layer;
    u8 color[3];
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        /* fallthrough */
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            task->control.unk34[0].enabled = 1;
            task->control.unk34[0].arg = 0x1002;
            task->control.fighter = 0;
            task->control.unk34[0].alt = 0;
            children[0] = FIGHTSTG_createPlainModel(stages[task->stage].model, stages[task->stage].motions, FIGHTSTG_stageTexPos, &task->control);
            if (stages[task->stage].music != -1) {
                task->voice = SOUND.playSound(FIGHTSTG_stageMusic[stages[task->stage].music]);
            }
            lights = TASK_REGISTRY.funcs.find(BATTLE_TASK_LIGHTS, -1, -1);
            if (lights != NULL) {
                lights->fade(lights, NULL, lights->getStageLights(lights, task->stage), task->fadeInTime);
            }
            task->nextSubstate(task);
            /* fallthrough */
        case 1:
            if (children[0]->state == TASK_RUN) {
                for (i = 0; i < 8; i++) {
                    if (stages[task->stage].unk10[i] == 0) {
                        break;
                    }
                    model = children[0];
                    model->setBoneNoBoundsCheck(model, stages[task->stage].unk10[i], 1);
                }
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
                model = children[0];
                model->setColor(model, 1, color);
                layer = GFX.funcs.getLayer(0x1000);
                layer->setBgColor(layer, 1, 1, 1);
                task->nextSubstate(task);
            }
            break;
        case 2:
            task->colorTo.vz = 0x80;
            task->colorTo.vy = 0x80;
            task->colorTo.vx = 0x80;
            task->colorFrom.vz = 0;
            task->colorFrom.vy = 0;
            task->colorFrom.vx = 0;
            task->bgTo.vx = stages[task->stage].bgColor[0];
            task->bgTo.vy = stages[task->stage].bgColor[1];
            task->bgTo.vz = stages[task->stage].bgColor[2];
            task->bgFrom.vz = 0;
            task->bgFrom.vy = 0;
            task->bgFrom.vx = 0;
            task->fade = 0;
            task->fadeStep = 0x1000 / task->fadeInTime;
            task->nextSubstate(task);
            /* fallthrough */
        case 3:
            task->fade += task->fadeStep * GFX.funcs.getFrameTime();
            if (task->fade > 0x1000) {
                task->fade = 0x1000;
            }
            FIGHTSTG_fadeStage(task, children);
            if (task->fade == 0x1000) {
                task->nextSubstate(task);
            }
            break;
        case 4:
            break;
        }
        break;
    case TASK_DONE:
        switch (task->substate) {
        case 0:
        default:
            FILE_CACHE.request((s16)(stages[task->stage].model >> 16));
            task->colorFrom.vz = 0x80;
            task->colorFrom.vy = 0x80;
            task->colorFrom.vx = 0x80;
            task->colorTo.vz = 0;
            task->colorTo.vy = 0;
            task->colorTo.vx = 0;
            task->bgTo.vz = 0;
            task->bgTo.vy = 0;
            task->bgTo.vx = 0;
            task->bgFrom.vx = stages[task->prevStage].bgColor[0];
            task->bgFrom.vy = stages[task->prevStage].bgColor[1];
            task->bgFrom.vz = stages[task->prevStage].bgColor[2];
            task->fade = 0;
            task->fadeStep = 0x1000 / task->fadeOutTime;
            task->nextSubstate(task);
            /* fallthrough */
        case 1:
            task->fade += task->fadeStep * GFX.funcs.getFrameTime();
            if (task->fade > 0x1000) {
                task->fade = 0x1000;
            }
            FIGHTSTG_fadeStage(task, children);
            if (task->fade == 0x1000) {
                children[0]->setState(children[0], TASK_KILL);
                task->setState(task, TASK_RUN);
                if (stages[task->prevStage].music != -1) {
                    SOUND.keyOff(FIGHTSTG_stageMusic[stages[task->prevStage].music], task->voice);
                }
            }
            break;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* FightStage.setStage: changes to stage ID, fading the old one out over
   FADEOUTTIME and the new one in over FADEINTIME */
void FIGHTSTG_setStage(FightStage *task, s32 id, s32 fadeOutTime, s32 fadeInTime) {
    if (task->stage != id) {
        task->prevStage = task->stage;
        task->stage = id;
        task->fadeOutTime = fadeOutTime;
        task->fadeInTime = fadeInTime;
        task->setState(task, TASK_DONE);
    }
}

/* A random fight stage, 1-27 */
s32 FIGHTSTG_randomStage(void) {
    return RANDOM.next() % 27 + 1;
}

/* The file of fight stage ID's motions */
s32 FIGHTSTG_getStageMotionsFile(s32 id) {
    return (s16)(((FightStageInfo *)FILE_CACHE.load(FILE_FIGHT_STAGES))[id].motions >> 16);
}

/* Creates the fight stage (id 0x15), which loads stage id and fades it in
   over fadeInTime */
FightStage *FIGHTSTG_createStage(s32 id, s32 fadeInTime) {
    FightStage *task = createTaskWithId(FIGHTSTG_updateStage, sizeof(FightStage), 4, BATTLE_TASK_STAGE);

    task->setStage = FIGHTSTG_setStage;
    task->stage = id;
    task->fadeInTime = fadeInTime;
    return task;
}
