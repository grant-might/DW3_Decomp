/* The third object of FIGHTSTG.PRO (see fightstg.c): its rodata starts at
   0x80082480 (USA). */

#include "fightstg.h"

/* A fighter's entrance: loads its model and adds it, then shows it behind a fade
   (FIGHTSTG_startWhiteFlash) and turns the camera to it; fighter 0x1D2 changes the fight
   stage and 0x1D3 the music. The match depends on substate 7's own ModelControl
   pointer. */
void FIGHTSTG_updateEntrance(Entrance *task, WhiteFlash **children) {
    Models *models = task->models;
    BattleCamera *camera = task->camera;
    FightStage *stage = task->stage;
    s32 is1D2 = task->key1 == 0x1D2;
    s32 is1D3 = task->key1 == 0x1D3;
    ModelControl *control;
    ModelControl *entering;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            task->models = models;
            task->camera = TASK_REGISTRY.funcs.find(BATTLE_TASK_CAMERA, -1, -1);
            task->stage = TASK_REGISTRY.funcs.find(BATTLE_TASK_STAGE, -1, -1);
            task->file = FIGHTSTG_fighterCache.funcs.getInfo(task->key1)->model >> 16;
            FILE_CACHE.request(task->file);
            task->nextSubstate(task);
        case 1:
            if (FILE_CACHE.isLoading(task->file) != 0) {
                break;
            }
            models->add(models, task->key2 + 1, task->key1, 0);
            if (!is1D2 && !is1D3) {
                task->nextState(task);
                break;
            }
            task->nextSubstate(task);
        case 2:
            switch (task->step) {
            case 0:
            default:
                if (is1D2) {
                    FILE_CACHE.request(FILE_ENTRANCE_1D2);
                } else {
                    SOUND.fadeOut(0x60900000);
                    SOUND.loadBank(0x26);
                }
                task->nextStep(task);
                break;
            case 1:
                if (is1D2) {
                    if (FILE_CACHE.isLoading(FILE_ENTRANCE_1D2) == 0) {
                        task->nextState(task);
                    }
                } else if (SOUND.isLoading() == 0) {
                    task->nextState(task);
                }
                break;
            }
            break;
        }
        break;
    case 1:
        switch (task->substate) {
        case 0:
            camera->fade(camera, NULL, camera->getFighterView(camera, task->key2, task->key2 != 0 ? 2 : 10), 60);
            task->nextSubstate(task);
        case 1:
            task->counter += GFX.funcs.getFrameTime();
            switch (task->step) {
            case 0:
            default:
                if (task->counter < 30) {
                    break;
                }
                models->get(models, task->key2 == 0 ? 0x10 : 0)->unk34[0].enabled = 0;
                task->step++;
            case 1:
                if (task->counter >= 60) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 2:
            SOUND.playSound(0xA0045EC9);
            *children = FIGHTSTG_startWhiteFlash(60);
            task->nextSubstate(task);
        case 3:
            if ((*children)->substate == 0) {
                break;
            }
            task->nextSubstate(task);
            task->done = 1;
            models->setId(models, task->key2 + 1, task->key2);
            models->face(models, task->key2);
            control = models->get(models, task->key2);
            control->unk34[0].arg = 0x1004;
            control->unk34[0].enabled = 1;
            control->unk34[0].alt = 0;
            control->motion = 13;
            camera->set(camera, camera->getFighterView(camera, task->key2, task->key2 != 0 ? 2 : 10));
            if (is1D2) {
                BATTLE_SETUP.stage = 0x16;
                stage->setStage(stage, 0x16, 1, 1);
            }
            if (is1D3) {
                BATTLE_SETUP.music = 0x60980000;
                SOUND.playSound(0x60980000);
            }
            break;
        case 4:
            FIGHTSTG_endWhiteFlash(*children, 60);
            task->nextSubstate(task);
        case 5:
            if (*children != NULL) {
                break;
            }
            task->nextSubstate(task);
        case 6:
            task->step += GFX.funcs.getFrameTime();
            if (is1D2 ? task->step < 10 : task->step < 120) {
                break;
            }
            task->nextSubstate(task);
        case 7:
            camera->fade(camera, NULL, camera->getEnemyView(camera), task->key2 != 0 ? 1 : 60);
            entering = models->get(models, task->key2);
            if (task->unk64 != 0) {
                entering->motion = 2;
            } else {
                entering->motion = 1;
            }
            models->get(models, task->key2 == 0 ? 0x10 : 0)->unk34[0].enabled = 1;
            task->setState(task, 3);
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts a fighter's entrance: Digimon id on the player's side (side 0) or
   the enemy's */
Entrance *FIGHTSTG_startEntrance(s32 id, s32 side, s32 arg2) {
    Entrance *task = createTask(FIGHTSTG_updateEntrance, sizeof(Entrance), 0xC);

    task->key1 = id;
    if (side) {
        task->key2 = 0x10;
    } else {
        task->key2 = 0;
    }
    task->unk64 = arg2;
    return task;
}

/* The mode's root task: loads WFIGHTTS (the battle test, with the mode's
   argument) or WFIGHTMN and starts it, then runs the battle's update */
void FIGHTSTG_updateRoot(Task *task, Task **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.funcs.getModeArg()) {
            OVERLAY_LOADER.loadSubOverlay(FILE_WFIGHTTS);
            BATTLE_SETUP.stage = FIGHTSTG_randomStage();
            children[0] = WFIGHTTS_start();
        } else {
            OVERLAY_LOADER.loadSubOverlay(FILE_WFIGHTMN);
            children[0] = WFIGHTMN_start();
        }
        FIGHTSTG_battle.setSpeed(0);
        task->nextState(task);
        break;
    case TASK_RUN:
        FIGHTSTG_battle.unkE4();
        break;
    case 2:
    case TASK_KILL:
        break;
    }
}

/* The mode's entry point (MODE_ENTRY_POINTS): starts the root task */
Task *FIGHTSTG_start(void) {
    return createTask(FIGHTSTG_updateRoot, sizeof(Task), sizeof(Task *));
}

/* FIGHTSTG_updateShotCamera's shots: how long each lasts and the substate that makes it,
   in four lists that end with a time of -1 */
CameraShot FIGHTSTG_cameraShots[4][6] = {
    { { 1800, 1 }, { 480, 9 }, { 360, 3 }, { 300, 4 }, { 480, 9 }, { -1, 0 } },
    { { 360, 6 }, { 900, 1 }, { 300, 5 }, { 480, 9 }, { -1, 0 }, { 0, 0 } },
    { { 1920, 1 }, { 360, 6 }, { 180, 7 }, { 480, 9 }, { -1, 0 }, { 0, 0 } },
    { { 90, 10 }, { 90, 5 }, { -1, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};
/* the lists that can follow each one */
u8 FIGHTSTG_nextShotLists[8][3] = {
    { 1, 2, 1 }, { 0, 2, 2 }, { 0, 1, 0 }, { 0, 1, 2 },
};

/* A camera that plays lists of shots (FIGHTSTG_cameraShots): turns around the
   fighters, fixed views and views of one side with the other side's model
   hidden */
void FIGHTSTG_updateShotCamera(ShotCamera *task) {
    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        task->list = 3;
        task->shot = 0;
        task->time = FIGHTSTG_cameraShots[task->list][task->shot].time;
        task->setSubstate(task, FIGHTSTG_cameraShots[task->list][task->shot].substate);
        task->camera = TASK_REGISTRY.funcs.find(BATTLE_TASK_CAMERA, -1, -1);
        task->models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
        task->view = task->camera->getEnemyView(task->camera);
        task->ry = task->view->rot.vy;
        break;
    case 1:
        if (task->time <= 0) {
            task->models->get(task->models, 0)->unk34[0].enabled = 1;
            task->models->get(task->models, 0x10)->unk34[0].enabled = 1;
            if (FIGHTSTG_cameraShots[task->list][++task->shot].time == -1) {
                task->list = FIGHTSTG_nextShotLists[task->list][RANDOM.next() % 3];
                task->shot = 0;
            }
            task->time = FIGHTSTG_cameraShots[task->list][task->shot].time;
            task->setSubstate(task, FIGHTSTG_cameraShots[task->list][task->shot].substate);
        }
        switch (task->substate) {
        case 1:
        default:
            if (task->step == 0) {
                task->view = task->camera->getEnemyView(task->camera);
                task->turned = 0;
                task->step++;
                if ((BATTLE_SETUP.stage & 0xF) != 4) {
                    task->view->rot.vy = task->ry;
                }
            }
            task->view->rot.vy += GFX.funcs.getFrameTime() * 2;
            task->turned += GFX.funcs.getFrameTime() * 2;
            if (task->view->rot.vy >= 0x1000) {
                task->view->rot.vy -= 0x1000;
            }
            task->ry = task->view->rot.vy;
            if ((BATTLE_SETUP.stage & 0xF) == 4 && task->turned > 0x800) {
                task->time = 0;
            }
            break;
        case 2:
            if (task->step == 0) {
                task->view = task->camera->getEnemyView(task->camera);
                task->view->vpx = -0x1E80;
                task->view->vpy = -0x500;
                task->view->vpz = 0;
                task->view->vrx = 0;
                task->view->vry = 0x500;
                task->view->vrz = 0;
                task->view->proj = 0x98;
                task->step++;
            }
            break;
        case 3:
            if (task->step == 0) {
                task->models->get(task->models, 0x10)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0, 8);
                task->view->tz -= 0x1400;
                task->view->vpz += 0x1400;
                task->view->vrz += 0x1400;
                task->speed = 1;
                task->step++;
            }
            task->view->rot.vy += GFX.funcs.getFrameTime() * task->speed;
            if (task->view->rot.vy >= 0x1000) {
                task->view->rot.vy -= 0x1000;
            }
            break;
        case 4:
            if (task->step == 0) {
                task->models->get(task->models, 0)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0x10, 0);
                task->view->tz += 0x1400;
                task->view->vpz -= 0x1400;
                task->view->vrz -= 0x1400;
                task->speed = 1;
                task->step++;
            }
            task->view->rot.vy -= GFX.funcs.getFrameTime() * task->speed;
            if (task->view->rot.vy < 0) {
                task->view->rot.vy += 0x1000;
            }
            break;
        case 5:
            if (task->step == 0) {
                task->models->get(task->models, 0x10)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0, 8);
                task->view->tz -= 0x1400;
                task->view->vpz += 0x1400;
                task->view->vrz += 0x1400;
                task->speed = 1;
                task->step++;
                task->view->rot.vy += 0xE3;
            }
            task->view->rot.vy -= GFX.funcs.getFrameTime() * task->speed;
            if (task->view->rot.vy < 0) {
                task->view->rot.vy += 0x1000;
            }
            break;
        case 6:
            if (task->step == 0) {
                task->models->get(task->models, 0)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0x10, 0);
                task->view->tz += 0x1400;
                task->view->vpz -= 0x1400;
                task->view->vrz -= 0x1400;
                task->speed = 1;
                task->step++;
                task->view->rot.vy -= 0xE3;
            }
            task->view->rot.vy += GFX.funcs.getFrameTime() * task->speed;
            if (task->view->rot.vy >= 0x1000) {
                task->view->rot.vy -= 0x1000;
            }
            break;
        case 7:
            if (task->step == 0) {
                task->models->get(task->models, 0x10)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0, 10);
                task->step++;
            }
            break;
        case 8:
            if (task->step == 0) {
                task->models->get(task->models, 0x10)->unk34[0].enabled = 0;
                task->view = task->camera->getFighterView(task->camera, 0, 8);
                task->step++;
            }
            break;
        case 9:
            if (task->step == 0) {
                task->view = task->camera->getEnemyView(task->camera);
                task->view->vpx = -0x1400;
                task->view->vpy = -0x2800;
                task->view->vpz = 0;
                task->view->vrx = 0;
                task->view->vry = 0;
                task->view->vrz = 0;
                task->view->proj = 0xC8;
                task->speed = 1;
                task->view->rot.vy -= 0x155;
                task->step++;
            }
            task->view->rot.vy += GFX.funcs.getFrameTime() * task->speed;
            if (task->view->rot.vy >= 0x1000) {
                task->view->rot.vy -= 0x1000;
            }
            break;
        case 10:
            if (task->step == 0) {
                task->view = task->camera->getEnemyView(task->camera);
                task->step++;
            }
            break;
        }
        if (task->view != NULL) {
            task->camera->set(task->camera, task->view);
        }
        task->time -= GFX.funcs.getFrameTime();
        break;
    case 3:
        task->models->get(task->models, 0)->unk34[0].enabled = 1;
        task->models->get(task->models, 0x10)->unk34[0].enabled = 1;
        task->view = task->camera->getEnemyView(task->camera);
        task->camera->set(task->camera, task->view);
        break;
    case 2:
        break;
    }
}

/* Starts the camera that plays lists of shots (FIGHTSTG_updateShotCamera) */
ShotCamera *FIGHTSTG_createShotCamera(void) {
    return createTask(FIGHTSTG_updateShotCamera, sizeof(ShotCamera), 0);
}

/* The fighters' models' task: nothing to do but start */
void FIGHTSTG_updateModels(Models *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* The slot of the fighter model registered as ID, or -1 */
s32 FIGHTSTG_findModelSlot(Models *task, s32 id) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (task->controls[i].active && task->controls[i].id == id) {
            return i;
        }
    }
    return -1;
}

/* A free fighter model slot, or -1 */
s32 FIGHTSTG_findFreeModelSlot(Models *task) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (!task->controls[i].active) {
            return i;
        }
    }
    return -1;
}

/* Models.remove: kills the model registered as ID and frees its slot */
void FIGHTSTG_removeFighterModel(Models *task, s32 id) {
    ModelsChildren *children = task->children;
    s32 i = FIGHTSTG_findModelSlot(task, id);

    if (i != -1) {
        children->dying[i] = children->models[i];
        children->models[i] = NULL;
        children->dying[i]->setState(children->dying[i], TASK_KILL);
        task->controls[i].active = 0;
    }
}

/* the fighters' models' texture places */
Vec2 FIGHTSTG_fighterTexPos[] = {
    { 832, 0 }, { 896, 0 }, { 960, 0 }, { 960, 256 },
};

/* Models.add: replaces the model registered as ID with FIGHTER's, in a free
   slot with that slot's textures, drawn on layer 0x1004 when VISIBLE */
void FIGHTSTG_addFighterModel(Models *task, s32 id, s32 fighter, s32 visible) {
    ModelsChildren *children = task->children;
    FighterInfo *info;
    ModelControl *control;
    s32 i;

    FIGHTSTG_removeFighterModel(task, id);
    i = FIGHTSTG_findFreeModelSlot(task);
    if (i != -1) {
        info = FIGHTSTG_fighterCache.funcs.getInfo(fighter);
        control = &task->controls[i];
        children->models[i] = FIGHTSTG_createIdlingModel(info->model, info->motions, FIGHTSTG_fighterTexPos[i], control);
        HEAP.zero(control, sizeof(ModelControl));
        task->controls[i].active = 1;
        task->controls[i].motion = 1;
        task->controls[i].fighter = fighter;
        task->controls[i].id = id;
        task->controls[i].unk34[0].enabled = visible;
        task->controls[i].unk34[0].alt = 0;
        task->controls[i].unk34[0].arg = 0x1004;
    }
}

/* Models.get: the control of the model registered as ID, or NULL */
ModelControl *FIGHTSTG_getModelControl(Models *task, s32 id) {
    s32 i = FIGHTSTG_findModelSlot(task, id);

    if (i != -1) {
        return &task->controls[i];
    }
    return NULL;
}

/* Models.setId: registers the model ID as NEWID instead, removing the one
   that had it */
void FIGHTSTG_setModelId(Models *task, s32 id, s32 newId) {
    FIGHTSTG_removeFighterModel(task, newId);
    task->controls[FIGHTSTG_findModelSlot(task, id)].id = newId;
}

/* Models.getFighter: the fighter of the model registered as ID, or 0 */
s32 FIGHTSTG_getModelFighter(Models *task, s32 id) {
    s32 i = FIGHTSTG_findModelSlot(task, id);

    if (i != -1) {
        return task->controls[i].fighter;
    }
    return 0;
}

/* Models.face: puts the model registered as ID at its side's place, facing
   the other side, as its home */
void FIGHTSTG_faceModel(Models *task, s32 id) {
    ModelControl *control = FIGHTSTG_getModelControl(task, id);
    FighterInfo *info;
    s16 z;

    if (control != NULL) {
        info = FIGHTSTG_fighterCache.funcs.getInfo(control->fighter);
        if (id < 0x10) {
            control->pos.x = 0;
            control->pos.y = -info->height;
            z = -0x1400 - info->unk10;
            control->rot.y = 0x800;
            control->rot.x = 0;
            control->rot.z = 0;
        } else {
            control->pos.x = 0;
            control->pos.y = -info->height;
            z = info->unk10 + 0x1400;
            control->rot.x = 0;
            control->rot.y = 0;
            control->rot.z = 0;
        }
        control->pos.z = z;
        control->homePos = control->pos;
        control->homeRot = control->rot;
    }
}

/* Models.setIdleMotion */
void FIGHTSTG_setModelIdleMotion(Models *task, s32 id, s32 motion) {
    ModelControl *control = FIGHTSTG_getModelControl(task, id);

    if (control != NULL) {
        control->idleMotion = motion;
    }
}

/* Creates the fighters' models (Models), with no fighters yet */
Models *FIGHTSTG_createModels(void) {
    Models *task = createTaskWithId(FIGHTSTG_updateModels, sizeof(Models), sizeof(ModelsChildren), BATTLE_TASK_MODELS);
    s32 i;

    for (i = 3; i >= 0; i--) {
        task->controls[i].active = 0;
    }
    task->add = FIGHTSTG_addFighterModel;
    task->getFighter = FIGHTSTG_getModelFighter;
    task->remove = FIGHTSTG_removeFighterModel;
    task->get = FIGHTSTG_getModelControl;
    task->setId = FIGHTSTG_setModelId;
    task->face = FIGHTSTG_faceModel;
    task->setIdleMotion = FIGHTSTG_setModelIdleMotion;
    return task;
}


const SVECTOR D_800824C8 = { 0, 120, 0x7FFF, 0 };

/* FIGHTSTG_updateHitEffect's children */
typedef struct HitEffectChildren {
    /* 0x0 */ SpriteEffect *effect;
    /* 0x4 */ BattleScript *script;
} HitEffectChildren;

/* Loads effect 0x33, then turns the camera to the enemy's view, plays the
   effect with a sound and, 10 frames on, the hit's or the knockout's script */
void FIGHTSTG_updateHitEffect(HitEffect *task, HitEffectChildren *children) {
    BattleCamera *camera = task->camera;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            task->models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            task->camera = TASK_REGISTRY.funcs.find(BATTLE_TASK_CAMERA, -1, -1);
            task->nextSubstate(task);
        case 1:
            switch (task->step) {
            case 0:
            default:
                FIGHTSTG_findEffectSheet(0x33, &task->effectImages, &task->sheet, &task->texPos);
                task->nextStep(task);
            case 1:
                if (FILE_CACHE.isLoading(task->sheet >> 16) == 0) {
                    task->nextState(task);
                }
                break;
            }
            break;
        }
        break;
    case 1:
        switch (task->substate) {
        case 0:
            camera->set(camera, camera->getEnemyView(camera));
            children->effect = FIGHTSTG_startSpriteEffect(0x33, (SVECTOR *)&D_800824C8);
            SOUND.playSound(0x800429BF);
            task->nextSubstate(task);
        case 1:
            task->counter += GFX.funcs.getFrameTime();
            if (task->counter < 10) {
                break;
            }
            children->script = FIGHTSTG_createBattleScript();
            children->script->unk50 = 0;
            children->script->index = task->result + 1;
            children->script->unk74 = task->unk5C;
            task->nextSubstate(task);
        case 2:
            if (children->script == NULL) {
                task->setState(task, 3);
            }
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts the effect of a hit on the player's fighter (result 1) or of its
   knockout (2) */
HitEffect *FIGHTSTG_startHitEffect(s32 result, s32 arg1) {
    HitEffect *task = createTask(FIGHTSTG_updateHitEffect, sizeof(HitEffect), sizeof(HitEffectChildren));

    task->result = result;
    task->unk5C = arg1;
    return task;
}

/* The enemy that the enemy's turn (FIGHTSTG_updateEnemyTurn) switches to:
   task->target's, or one of the others at random (not the active one), -1
   for none */
s32 FIGHTSTG_pickEnemySwitch(EnemyTurn *task) {
    BattleFighter *enemies = FIGHTSTG_battle.fighters[1];
    s32 found[2];
    s32 count;
    s32 active;
    s32 i;

    switch (task->target) {
    case -2:
        if (enemies[0].id == enemies[FIGHTSTG_battle.active[1]].id) {
            break;
        }
        if (enemies[0].hp != 0) {
            return 0;
        }
        break;
    case -3:
        if (enemies[1].id == enemies[FIGHTSTG_battle.active[1]].id) {
            break;
        }
        if (enemies[1].hp != 0) {
            return 1;
        }
        break;
    case -4:
        if (enemies[2].id == enemies[FIGHTSTG_battle.active[1]].id) {
            break;
        }
        if (enemies[2].hp != 0) {
            return 2;
        }
        break;
    default:
        count = 0;
        found[0] = -1;
        found[1] = -1;
        active = FIGHTSTG_battle.active[1];
        for (i = 0; i < 3; i++) {
            enemies = &FIGHTSTG_battle.fighters[1][i];
            if (active != i && enemies->id != 0 && enemies->hp != 0) {
                found[count++] = i;
            }
        }
        /* the match depends on case 0 and on reusing enemies */
        switch (count) {
        case 0:
            break;
        case 1:
            return found[0];
        case 2:
            return found[RANDOM.next() & 1];
        }
        break;
    }
    return -1;
}

/* The enemy's turn: a message when its HP is under a tenth, then one when it is asleep,
   paralyzed or confused, or else the first action of its battle table entry whose condition holds,
   and what its target makes it do: attack, a technique, a switch to another enemy
   (FIGHTSTG_pickEnemySwitch) or a message. The match depends on the goto into the confusion
   branch, the case -1 next to default, and the enemies pointers of substates 4 and 5. */
void FIGHTSTG_updateEnemyTurn(EnemyTurn *task, BattleChild *children) {
    BattleFighter *fighter;
    BattleTableEntry *entry;
    TechData *tech;
    s32 message;
    s32 index;
    s32 pick;
    s32 i;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            if (FIGHTSTG_battle.kind == BATTLE_KIND_ESCAPE) {
                BattleFighter *enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];

                if (enemy->hp < (s16)(enemy->maxHp / 10)) {
                    children->message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x5F;
                    task->lines[1] = 0x10;
                    children->message->show(children->message, 2, task->lines);
                    FIGHTSTG_endBattle(BATTLE_FLED);
                    task->substate++;
                } else {
                    task->nextState(task);
                }
            } else {
                task->nextState(task);
            }
            break;
        case 1:
            if (children->message == NULL) {
                task->state = 3;
            }
            break;
        }
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            switch (task->step) {
            case 0:
            default:
                index = FIGHTSTG_events.funcs.find(EVENT_RUN_AWAY, 0x10, FIGHTSTG_battle.active[1]);
                if (index >= 0) {
                    children->message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x60;
                    task->lines[1] = 0x10;
                    children->message->show(children->message, 2, task->lines);
                    FIGHTSTG_events.events[index].type = 0;
                    task->step++;
                } else {
                    task->nextSubstate(task);
                }
                break;
            case 1:
                if (children->message == NULL) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 1:
            fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
            if (fighter->flags & FIGHTER_ASLEEP) {
                children->message = FIGHTSTG_createMessage();
                message = 0x90;
                goto show;
            }
            if ((fighter->flags & FIGHTER_PARALYZED) && FIGHTSTG_battleFuncs.testParalysis(0x10) != 0) {
                children->message = FIGHTSTG_createMessage();
                message = 0x56;
                goto show;
            }
            if (fighter->flags & FIGHTER_CONFUSED) {
                children->message = FIGHTSTG_createMessage();
                message = RANDOM.next() % 8 + 0x83;
            show:
                task->lines[0] = message;
                task->lines[1] = 0x10;
                children->message->show(children->message, 2, task->lines);
                task->setSubstate(task, 3);
                break;
            }
            i = 0;
            entry = FIGHTSTG_battleTableFunc(fighter->id);
            for (; i < 3; i++) {
                if (FIGHTSTG_testEnemyCondition(entry->actions[i].condition, entry->actions[i].conditionArg) != 0) {
                    break;
                }
            }
            task->target = FIGHTSTG_getEnemyAction(entry->actions[i].target);
            task->substate++;
            break;
        case 2:
            if (task->target > 0) {
                if (task->target == 1) {
                    children->attack = FIGHTSTG_startFirstTech(0x10);
                } else {
                    fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    tech = &TECHS[task->target - 1];
                    if (fighter->mp >= tech->mp) {
                        children->tech = FIGHTSTG_startTechAction(0x10, task->target);
                        fighter->mp -= tech->mp;
                    } else {
                        children->message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x8D;
                        task->lines[1] = 0x10;
                        children->message->show(children->message, 2, task->lines);
                    }
                }
                task->substate = 3;
            } else if (task->target < 0) {
                switch (task->target) {
                case -1:
                default:
                    FIGHTSTG_queueRunAway(0x10);
                    children->message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x5E;
                    task->lines[1] = 0x10;
                    children->message->show(children->message, 2, task->lines);
                    task->substate = 3;
                    break;
                case -2:
                case -3:
                case -4:
                case -5:
                    pick = FIGHTSTG_pickEnemySwitch(task);
                    if (pick != -1) {
                        task->unk7C = pick;
                        children->message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x4D;
                        children->message->show(children->message, 1, task->lines);
                        task->substate = 5;
                    } else {
                        children->message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x8E;
                        task->lines[1] = 0x10;
                        children->message->show(children->message, 2, task->lines);
                        task->substate = 3;
                    }
                    break;
                }
            }
            break;
        case 3:
            if (children->message == NULL) {
                task->state = 3;
                FIGHTSTG_queueEnemyTurn(FIGHTSTG_events.funcs.getDelay(0x10, 0));
            }
            break;
        case 4:
            if (children->message == NULL) {
                BattleFighter *enemies = FIGHTSTG_battle.fighters[1];
                BattleTableEntry *enemy = FIGHTSTG_battleTableFunc(enemies[FIGHTSTG_battle.active[1]].id);

                children->message = FIGHTSTG_createMessage();
                task->lines[0] = enemy->nameId;
                children->message->show(children->message, 0xD, task->lines);
                task->substate = 3;
            }
            break;
        case 5:
            if (children->message == NULL) {
                BattleFighter *enemies = FIGHTSTG_battle.fighters[1];

                children->entrance = FIGHTSTG_startEntrance(enemies[task->unk7C].id, 1, 0);
                WFIGHTMN_setIdleMotion(0x10, 0);
                task->substate = 6;
            }
            break;
        case 6:
            if (children->entrance->done) {
                FIGHTSTG_battle.active[1] = task->unk7C;
                task->substate = 4;
            }
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts the enemy's turn (FIGHTSTG_updateEnemyTurn) */
EnemyTurn *FIGHTSTG_startEnemyTurn(void) {
    return createTask(FIGHTSTG_updateEnemyTurn, sizeof(EnemyTurn), 2 * sizeof(Task *));
}

/* Whether the condition of an enemy's action holds (BattleTableAction): always, a
   chance in 128, the enemy's or the partner's HP over or under a share, its MP, the
   partner's Digimon or flags, the other enemies, the battle and the enemy's boosts.
   The match depends on the one fighter pointer that the cases set as they need it,
   on case 1 keeping its roll in the same variable as the HP share, and on case 10's
   own loop counter. */
s32 FIGHTSTG_testEnemyCondition(u8 condition, s16 arg) {
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
    s32 result = 0;
    s32 percent;
    s32 j;
    DigimonData *digimon;
    s32 i;

    switch (condition) {
    case 0:
    default:
        result = 1;
        break;
    case 1:
        percent = RANDOM.next() % 128;
        if (percent < arg) {
            result = 1;
        }
        break;
    case 2:
        percent = arg * 100 / 128;
        if (fighter->hp < (s16)(fighter->maxHp / 100) * percent) {
            result = 1;
        }
        break;
    case 3:
        percent = arg * 100 / 128;
        if (fighter->hp >= (s16)(fighter->maxHp / 100) * percent) {
            result = 1;
        }
        break;
    case 4:
        if (fighter->mp < arg) {
            result = 1;
        }
        break;
    case 5:
        if (fighter->mp >= arg) {
            result = 1;
        }
        break;
    case 6:
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        percent = arg * 100 / 128;
        if (fighter->hp < (s16)(fighter->maxHp / 100) * percent) {
            result = 1;
        }
        break;
    case 7:
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        percent = arg * 100 / 128;
        if (fighter->hp >= (s16)(fighter->maxHp / 100) * percent) {
            result = 1;
        }
        break;
    case 8:
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        for (i = 0, digimon = DIGIMON_DATA; i < 8; i++, digimon++) {
            if (fighter->id == digimon->id) {
                result = 1;
                break;
            }
        }
        break;
    case 9:
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        if (fighter->flags & FIGHTER_ASLEEP) {
            result = 1;
        }
        break;
    case 10:
        fighter = FIGHTSTG_battle.fighters[1];
        if (arg == 0) {
            for (j = 0; j < 3; j++) {
                if (j != FIGHTSTG_battle.active[1] && fighter[j].id != 0 && fighter[j].hp != 0) {
                    result = 1;
                    break;
                }
            }
        } else {
            for (j = 0; j < 3; j++) {
                if (j != FIGHTSTG_battle.active[1] && fighter[j].id == arg && fighter[j].hp != 0) {
                    result = 1;
                    break;
                }
            }
        }
        break;
    case 11:
        if (FIGHTSTG_battle.boostElement == arg) {
            result = 1;
        }
        break;
    case 12:
        if (BATTLE_SETUP.battle == arg) {
            result = 1;
        }
        break;
    case 13:
        if (BATTLE_SETUP.unk3D == arg) {
            result = 1;
        }
        break;
    case 14:
        if (fighter->unkE != 0) {
            result = 1;
        }
        break;
    case 15:
        if (fighter->boosts[0] < 0) {
            result = 1;
        }
        break;
    case 16:
        if (fighter->boosts[1] < 0) {
            result = 1;
        }
        break;
    case 17:
        if (fighter->boosts[2] < 0) {
            result = 1;
        }
        break;
    case 18:
        if (fighter->unk4 % arg == 0) {
            result = 1;
        }
        break;
    }
    return result;
}

/* What an enemy's action target makes it do (EnemyTurn.target): 1 its first
   technique, its battle table entry's second or third technique, or -1 to -5
   for the other actions */
s32 FIGHTSTG_getEnemyAction(u8 kind) {
    BattleFighter *enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
    s32 value = 0;
    BattleTableEntry *entry = FIGHTSTG_battleTableFunc(enemy->id);

    switch (kind) {
    case 1:
        value = 1;
        break;
    case 2:
        value = entry->unk8[1];
        break;
    case 3:
        value = entry->unk8[2];
        break;
    case 4:
        value = -1;
        break;
    case 5:
        value = -2;
        break;
    case 6:
        value = -3;
        break;
    case 7:
        value = -4;
        break;
    case 8:
        value = -5;
        break;
    }
    return value;
}

void func_80088994(void) {
}

/* A layer callback that draws a sprite animation's frame: at its projected
   position, or at a screen position when its z is 0x7FFF or -1, with its
   scale, CLUT row and rotation. The match depends on taking the task as
   void * */
void FIGHTSTG_drawSpriteAnim(void *arg, Layer *layer) {
    SpriteAnim *task = arg;
    ShortVec3 screen;
    SpriteDrawer drawer;

    if (task->pos.vz != 0x7FFF && task->pos.vz != -1) {
        FIGHTSTG_battle.project(layer, &task->pos, &screen);
    } else {
        screen.x = task->pos.vx;
        screen.y = task->pos.vy;
        if (task->pos.vz != 0x7FFF) {
            screen.z = 0xFFF;
        } else {
            screen.z = 0;
        }
    }
    screen.x += task->x;
    screen.y += task->y;
    initSpriteDrawer(&drawer);
    drawer.setLayer(layer, screen.z);
    drawer.setTexture(task->texPos.x, task->texPos.y);
    if (task->scale.both != 0x10001000) {
        drawer.setScale(task->scale.v[0], task->scale.v[1], 0);
    }
    if (task->clutRow != 0) {
        drawer.setClutRow(task->clutRow);
    }
    if (task->rot.both != 0 || task->rotZ != 0) {
        drawer.setRotation(task->rot.v[0], task->rot.v[1], task->rotZ);
    }
    drawer.setPivot(screen.x, screen.y);
    drawer.draw(FILE_CACHE.getEntry(task->sheet), task->frame, screen.x, screen.y);
}

void FIGHTSTG_updateSpriteAnim(SpriteAnim *task) {
    s16 *data;
    s16 *values;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->flags = *task->data++;
        task->stride = *task->data++;
        task->duration = *task->data++;
        for (i = 0; i < 9; i++) {
            (&task->frame)[i] = *task->data++;
        }
        task->nextState(task);
        /* fallthrough */
    case TASK_RUN:
        data = task->data + task->time * task->stride;
        if (task->flags & 1) {
            task->frame = *data++;
        }
        if (task->flags & 2) {
            task->clutRow = *data++;
        }
        if (task->flags & 4) {
            task->x = *data++;
        }
        if (task->flags & 8) {
            task->y = *data++;
        }
        if (task->flags & 0x10) {
            task->scale.v[0] = *data++;
        }
        if (task->flags & 0x20) {
            task->scale.v[1] = *data++;
        }
        if (task->flags & 0x40) {
            task->rot.v[0] = *data++;
        }
        if (task->flags & 0x80) {
            task->rot.v[1] = *data++;
        }
        if (task->flags & 0x100) {
            task->rotZ = *data;
        }
        if (task->scale.v[0] != 0 && task->scale.v[1] != 0) {
            Layer *layer = GFX.funcs.getLayer(task->layerId);

            layer->addCallback(layer, FIGHTSTG_drawSpriteAnim, task);
        }
        task->time += FIGHTSTG_battle.frames;
        if (task->time >= task->duration) {
            task->setState(task, TASK_DONE);
        }
        break;
    case TASK_DONE:
        task->nextState(task);
        break;
    case TASK_KILL:
        break;
    }
}

SpriteAnim *FIGHTSTG_createSpriteAnim(s16 *data, SVECTOR *pos, s32 sheet, Vec2 *texPos, s32 layerId) {
    SpriteAnim *task = createTask(FIGHTSTG_updateSpriteAnim, sizeof(SpriteAnim), 0);

    task->data = data;
    task->pos = *pos;
    task->sheet = sheet;
    task->texPos = *texPos;
    task->layerId = layerId;
    return task;
}

void FIGHTSTG_updateEffectModel(EffectModel *task, Model **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->control.unk34[0].enabled = 1;
        task->control.unk34[0].arg = 0x1004;
        task->control.fighter = 0;
        task->control.unk34[0].alt = 0;
        task->control.pos.x = task->pos.vx;
        task->control.pos.y = task->pos.vy;
        task->control.pos.z = task->pos.vz;
        task->control.rot.x = task->rot.vx;
        task->control.rot.y = task->rot.vy;
        task->control.rot.z = task->rot.vz;
        children[0] = FIGHTSTG_createPlainModel(task->file, task->motionFile, task->texPos, &task->control);
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->control.motionDone) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* the effect models, ended by an id of 0; the European version's differ */
#if VERSION_US
EffectModelEntry FIGHTSTG_effectModels[] = {
    { 39, 0x7FE001A, 0x7FE0000 },
    { 65, 0x7600004, 0x7600000 },
    { 66, 0x8050004, 0x8050001 },
    { 85, 0x8290006, 0x8290000 },
    { 86, 0x82A0007, 0x82A0000 },
    { 87, 0x7C90016, 0x7C90000 },
    { 88, 0x76E0006, 0x76E0000 },
    { 89, 0x7EC0006, 0x7EC0000 },
    { 90, 0x7F8000A, 0x7F80000 },
    { 91, 0x7F90008, 0x7F90001 },
    { 92, 0x7FA0006, 0x7FA0000 },
    { 93, 0x74A001A, 0x74A0000 },
    { 94, 0x74C002C, 0x74C0000 },
    { 95, 0x763000A, 0x7630000 },
    { 96, 0x7D5001A, 0x7D50004 },
    { 97, 0x7F50003, 0x7F50000 },
    { 98, 0x7F70007, 0x7F70000 },
    { 99, 0x7FB0008, 0x7FB0001 },
    { 100, 0x7FC0005, 0x7FC0006 },
    { 101, 0x7ED0003, 0x7ED0001 },
    { 102, 0x7EE0006, 0x7EE0001 },
    { 103, 0x7EF0006, 0x7EF0001 },
    { 106, 0x7F0000E, 0x7F00002 },
    { 107, 0x7F1000A, 0x7F10001 },
    { 108, 0x7CA000C, 0x7CA0000 },
    { 109, 0x7CB001C, 0x7CB0005 },
    { 113, 0x7FD0005, 0x7FD0006 },
    { 114, 0x874000C, 0x8740002 },
    { 115, 0x87D0001, 0x87D0000 },
    { 116, 0x87E000A, 0x87E0000 },
    { 201, 0x80D0004, 0x80D0000 },
    { 202, 0x80E0004, 0x80E0000 },
    { 203, 0x80F0004, 0x80F0000 },
    { 204, 0x8100004, 0x8100000 },
    { 205, 0x8110004, 0x8110000 },
    { 206, 0x8120004, 0x8120000 },
    { 207, 0x8130004, 0x8130000 },
    { 208, 0x8140004, 0x8140000 },
    { 209, 0x8150004, 0x8150000 },
    { 210, 0x8160004, 0x8160000 },
    { 211, 0x8170004, 0x8170000 },
    { 212, 0x8180004, 0x8180000 },
    { 213, 0x8190004, 0x8190000 },
    { 214, 0x81A0004, 0x81A0000 },
    { 215, 0x81B0004, 0x81B0000 },
    { 216, 0x81C0004, 0x81C0000 },
    { 217, 0x81D0004, 0x81D0000 },
    { 218, 0x81E0004, 0x81E0000 },
    { 219, 0x81F0004, 0x81F0000 },
    { 220, 0x8200004, 0x8200000 },
    { 221, 0x7C00004, 0x7C00000 },
    { 222, 0x8210004, 0x8210000 },
    { 223, 0x8220004, 0x8220000 },
    { 224, 0x8230004, 0x8230000 },
    { 225, 0x8240004, 0x8240000 },
    { 226, 0x8250004, 0x8250000 },
    { 301, 0x82B000E, 0x82B0000 },
    { 302, 0x82D0015, 0x82D0016 },
    { 303, 0x82E0004, 0x82E0001 },
    { 306, 0x82F0004, 0x82F0000 },
    { 307, 0x8300006, 0x8300000 },
    { 308, 0x8310008, 0x8310000 },
    { 309, 0x8320004, 0x8320000 },
    { 310, 0x834000A, 0x8340000 },
    { 310, 0x834000A, 0x8340000 },
    { 311, 0x8350004, 0x8350000 },
    { 312, 0x8360004, 0x8360000 },
    { 313, 0x8370004, 0x8370000 },
    { 314, 0x8380004, 0x8380000 },
    { 315, 0x839000A, 0x8390000 },
    { 316, 0x83A0006, 0x83A0001 },
    { 317, 0x83B0001, 0x83B0000 },
    { 318, 0x83C0004, 0x83C0001 },
    { 319, 0x83D000A, 0x83D0006 },
    { 320, 0x83E000A, 0x83E0000 },
    { 321, 0x83F0004, 0x83F0000 },
    { 322, 0x8400004, 0x8400000 },
    { 323, 0x8410004, 0x8410000 },
    { 324, 0x8420004, 0x8420000 },
    { 325, 0x8430004, 0x8430000 },
    { 326, 0x8440006, 0x8440000 },
    { 327, 0x845000D, 0x845000E },
    { 328, 0x8460006, 0x8460000 },
    { 329, 0x8470006, 0x8470000 },
    { 330, 0x8480008, 0x8480000 },
    { 331, 0x8490008, 0x8490000 },
    { 332, 0x84A0008, 0x84A0000 },
    { 333, 0x84B000A, 0x84B0000 },
    { 334, 0x84C000A, 0x84C0000 },
    { 335, 0x84D0006, 0x84D0000 },
    { 336, 0x84E0005, 0x84E0006 },
    { 337, 0x84F000C, 0x84F0000 },
    { 338, 0x8500006, 0x8500000 },
    { 339, 0x8510007, 0x8510008 },
    { 340, 0x8520005, 0x8520006 },
    { 341, 0x853000C, 0x8530000 },
    { 342, 0x8540001, 0x8540000 },
    { 343, 0x8550001, 0x8550000 },
    { 344, 0x8560000, 0x8560008 },
    { 345, 0x8570000, 0x8570008 },
    { 346, 0x8580015, 0x8580016 },
    { 347, 0x8590004, 0x8590000 },
    { 348, 0x85A0001, 0x85A0000 },
    { 349, 0x85B000A, 0x85B0000 },
    { 350, 0x85C0019, 0x85C001A },
    { 351, 0x85D000A, 0x85D0000 },
    { 352, 0x85E0008, 0x85E0000 },
    { 353, 0x85F0008, 0x85F0000 },
    { 354, 0x8600009, 0x860000A },
    { 355, 0x8610001, 0x8610000 },
    { 356, 0x8620008, 0x8620000 },
    { 357, 0x8630001, 0x8630000 },
    { 358, 0x864000A, 0x8640000 },
    { 359, 0x8650008, 0x8650000 },
    { 360, 0x866000C, 0x8660002 },
    { 361, 0x8670011, 0x8670012 },
    { 362, 0x868000C, 0x8680000 },
    { 363, 0x8690011, 0x8690012 },
    { 364, 0x86A0031, 0x86A0032 },
    { 365, 0x86B001A, 0x86B0000 },
    { 366, 0x86C0006, 0x86C0000 },
    { 367, 0x86D0006, 0x86D0000 },
    { 368, 0x86E0004, 0x86E0001 },
    { 369, 0x86F0001, 0x86F0000 },
    { 370, 0x8700012, 0x8700000 },
    { 371, 0x8710008, 0x8710000 },
    { 372, 0x872000A, 0x8720000 },
    { 374, 0x8730012, 0x8730000 },
    { 375, 0x833000E, 0x8330003 },
    { 376, 0x8900012, 0x890000C },
    { 0, 0, 0 },
};
#elif VERSION_EU
EffectModelEntry FIGHTSTG_effectModels[] = {
    { 39, 0x80D001A, 0x80D0000 },
    { 65, 0x76F0004, 0x76F0000 },
    { 66, 0x8140004, 0x8140001 },
    { 85, 0x83A0006, 0x83A0000 },
    { 86, 0x83B0007, 0x83B0000 },
    { 87, 0x7D80016, 0x7D80000 },
    { 88, 0x77D0006, 0x77D0000 },
    { 89, 0x7FB0006, 0x7FB0000 },
    { 90, 0x807000A, 0x8070000 },
    { 91, 0x8080008, 0x8080001 },
    { 92, 0x8090006, 0x8090000 },
    { 93, 0x75A001A, 0x75A0000 },
    { 94, 0x75C002C, 0x75C0000 },
    { 95, 0x772000A, 0x7720000 },
    { 96, 0x7E4001A, 0x7E40004 },
    { 97, 0x8040003, 0x8040000 },
    { 98, 0x8060007, 0x8060000 },
    { 99, 0x80A0008, 0x80A0001 },
    { 100, 0x80B0005, 0x80B0006 },
    { 101, 0x7FC0003, 0x7FC0001 },
    { 102, 0x7FD0006, 0x7FD0001 },
    { 103, 0x7FE0006, 0x7FE0001 },
    { 106, 0x7FF000E, 0x7FF0002 },
    { 107, 0x800000A, 0x8000001 },
    { 108, 0x7D9000C, 0x7D90000 },
    { 109, 0x7DA001C, 0x7DA0005 },
    { 113, 0x80C0005, 0x80C0006 },
    { 114, 0x885000C, 0x8850002 },
    { 115, 0x88E0001, 0x88E0000 },
    { 116, 0x88F000A, 0x88F0000 },
    { 201, 0x81E0004, 0x81E0000 },
    { 202, 0x81F0004, 0x81F0000 },
    { 203, 0x8200004, 0x8200000 },
    { 204, 0x8210004, 0x8210000 },
    { 205, 0x8220004, 0x8220000 },
    { 206, 0x8230004, 0x8230000 },
    { 207, 0x8240004, 0x8240000 },
    { 208, 0x8250004, 0x8250000 },
    { 209, 0x8260004, 0x8260000 },
    { 210, 0x8270004, 0x8270000 },
    { 211, 0x8280004, 0x8280000 },
    { 212, 0x8290004, 0x8290000 },
    { 213, 0x82A0004, 0x82A0000 },
    { 214, 0x82B0004, 0x82B0000 },
    { 215, 0x82C0004, 0x82C0000 },
    { 216, 0x82D0004, 0x82D0000 },
    { 217, 0x82E0004, 0x82E0000 },
    { 218, 0x82F0004, 0x82F0000 },
    { 219, 0x8300004, 0x8300000 },
    { 220, 0x8310004, 0x8310000 },
    { 221, 0x7CF0004, 0x7CF0000 },
    { 222, 0x8320004, 0x8320000 },
    { 223, 0x8330004, 0x8330000 },
    { 224, 0x8340004, 0x8340000 },
    { 225, 0x8350004, 0x8350000 },
    { 226, 0x8360004, 0x8360000 },
    { 301, 0x83C000E, 0x83C0000 },
    { 302, 0x83E0015, 0x83E0016 },
    { 303, 0x83F0004, 0x83F0001 },
    { 306, 0x8400004, 0x8400000 },
    { 307, 0x8410006, 0x8410000 },
    { 308, 0x8420008, 0x8420000 },
    { 309, 0x8430004, 0x8430000 },
    { 310, 0x845000A, 0x8450000 },
    { 310, 0x845000A, 0x8450000 },
    { 311, 0x8460004, 0x8460000 },
    { 312, 0x8470004, 0x8470000 },
    { 313, 0x8480004, 0x8480000 },
    { 314, 0x8490004, 0x8490000 },
    { 315, 0x84A000A, 0x84A0000 },
    { 316, 0x84B0006, 0x84B0001 },
    { 317, 0x84C0001, 0x84C0000 },
    { 318, 0x84D0004, 0x84D0001 },
    { 319, 0x84E000A, 0x84E0006 },
    { 320, 0x84F000A, 0x84F0000 },
    { 321, 0x8500004, 0x8500000 },
    { 322, 0x8510004, 0x8510000 },
    { 323, 0x8520004, 0x8520000 },
    { 324, 0x8530004, 0x8530000 },
    { 325, 0x8540004, 0x8540000 },
    { 326, 0x8550006, 0x8550000 },
    { 327, 0x856000D, 0x856000E },
    { 328, 0x8570006, 0x8570000 },
    { 329, 0x8580006, 0x8580000 },
    { 330, 0x8590008, 0x8590000 },
    { 331, 0x85A0008, 0x85A0000 },
    { 332, 0x85B0008, 0x85B0000 },
    { 333, 0x85C000A, 0x85C0000 },
    { 334, 0x85D000A, 0x85D0000 },
    { 335, 0x85E0006, 0x85E0000 },
    { 336, 0x85F0005, 0x85F0006 },
    { 337, 0x860000C, 0x8600000 },
    { 338, 0x8610006, 0x8610000 },
    { 339, 0x8620007, 0x8620008 },
    { 340, 0x8630005, 0x8630006 },
    { 341, 0x864000C, 0x8640000 },
    { 342, 0x8650001, 0x8650000 },
    { 343, 0x8660001, 0x8660000 },
    { 344, 0x8670000, 0x8670008 },
    { 345, 0x8680000, 0x8680008 },
    { 346, 0x8690015, 0x8690016 },
    { 347, 0x86A0004, 0x86A0000 },
    { 348, 0x86B0001, 0x86B0000 },
    { 349, 0x86C000A, 0x86C0000 },
    { 350, 0x86D0019, 0x86D001A },
    { 351, 0x86E000A, 0x86E0000 },
    { 352, 0x86F0008, 0x86F0000 },
    { 353, 0x8700008, 0x8700000 },
    { 354, 0x8710009, 0x871000A },
    { 355, 0x8720001, 0x8720000 },
    { 356, 0x8730008, 0x8730000 },
    { 357, 0x8740001, 0x8740000 },
    { 358, 0x875000A, 0x8750000 },
    { 359, 0x8760008, 0x8760000 },
    { 360, 0x877000C, 0x8770002 },
    { 361, 0x8780011, 0x8780012 },
    { 362, 0x879000C, 0x8790000 },
    { 363, 0x87A0011, 0x87A0012 },
    { 364, 0x87B0031, 0x87B0032 },
    { 365, 0x87C001A, 0x87C0000 },
    { 366, 0x87D0006, 0x87D0000 },
    { 367, 0x87E0006, 0x87E0000 },
    { 368, 0x87F0004, 0x87F0001 },
    { 369, 0x8800001, 0x8800000 },
    { 370, 0x8810012, 0x8810000 },
    { 371, 0x8820008, 0x8820000 },
    { 372, 0x883000A, 0x8830000 },
    { 374, 0x8840012, 0x8840000 },
    { 375, 0x844000E, 0x8440003 },
    { 376, 0x8A10012, 0x8A1000C },
    { 0, 0, 0 },
};
#endif

s32 FIGHTSTG_getEffectModelFile(s32 id) {
    EffectModelEntry *entry;

    for (entry = FIGHTSTG_effectModels; entry->id != 0; entry++) {
        if (entry->id == id) {
            return entry->file >> 16;
        }
    }
    return 0;
}

/* Starts the effect model id at pos and rot, its model in
   FIGHTSTG_effectModels and its textures at (0x280, 0x100); killed at once
   when id has no entry. The match depends on the entry pointer and on texPos
   set as one Vec2 (as two members, gcc stores them sooner). */
EffectModel *FIGHTSTG_startEffectModel(s32 id, SVECTOR *pos, SVECTOR *rot) {
    EffectModel *task = createTask(FIGHTSTG_updateEffectModel, sizeof(EffectModel), sizeof(Task *));
    EffectModelEntry *entry;

    task->effect = 0;
    for (entry = FIGHTSTG_effectModels; entry->id != 0; entry++) {
        if (entry->id == id) {
            task->effect = id;
            task->motionFile = entry->motionFile;
            task->file = entry->file;
            task->texPos = (Vec2){ 0x280, 0x100 };
            task->pos = *pos;
            task->rot = *rot;
            break;
        }
    }
    if (task->effect == 0) {
        task->setState(task, TASK_KILL);
    }
    return task;
}

/* the 2D effects' sheets; the European version's differ */
#if VERSION_US
EffectSheet FIGHTSTG_effectSheets[] = {
    { 0, 0x78E0026, { 320, 256 } },
    { 0, 0x7940000, { 448, 256 } },
    { 0, 0x7D10000, { 512, 256 } },
    { 0, 0x7D30000, { 576, 256 } },
    { 0, 0, { 576, 256 } },
    { 0x7E60006, 0x7E60000, { 768, 256 } },
    { 0x8910005, 0x8910000, { 768, 256 } },
    { 0x8000002, 0x8000000, { 896, 256 } },
    { 0x77C0002, 0x77C0000, { 896, 256 } },
    { 0x7FF0003, 0x7FF0000, { 896, 256 } },
    { 0x77A0003, 0x77A0000, { 896, 256 } },
    { 0x80B0002, 0x80B0001, { 896, 256 } },
    { 0x7D60003, 0x7D60000, { 896, 256 } },
    { 0x6CA0002, 0x6CA0000, { 896, 256 } },
    { 0x7D70003, 0x7D70000, { 896, 256 } },
    { 0x8020002, 0x8020000, { 896, 256 } },
    { 0x80C0002, 0x80C0001, { 896, 256 } },
    { 0x77D0002, 0x77D0000, { 896, 256 } },
    { 0x7CC0002, 0x7CC0000, { 896, 256 } },
    { 0x7D80002, 0x7D80000, { 896, 256 } },
    { 0x8030002, 0x8030000, { 896, 256 } },
    { 0x7960002, 0x7960000, { 896, 256 } },
    { 0x8080002, 0x8080000, { 896, 256 } },
    { 0x77E0003, 0x77E0000, { 896, 256 } },
    { 0x77F0005, 0x77F0000, { 896, 256 } },
    { 0x88C0002, 0x88C0000, { 896, 256 } },
    { 0x7800004, 0x7800000, { 896, 256 } },
    { 0x7CD0002, 0x7CD0000, { 896, 256 } },
    { 0x8040003, 0x8040000, { 896, 256 } },
    { 0x8070002, 0x8070000, { 896, 256 } },
    { 0x80A0002, 0x80A0000, { 896, 256 } },
    { 0x77B0003, 0x77B0000, { 896, 256 } },
    { 0x7640002, 0x7640000, { 896, 256 } },
    { 0x82C0002, 0x82C0000, { 896, 256 } },
    { 0x7D90003, 0x7D90000, { 896, 256 } },
    { 0x7CE0003, 0x7CE0000, { 896, 256 } },
    { 0x7CF0002, 0x7CF0000, { 896, 256 } },
    { 0x7DA0004, 0x7DA0000, { 896, 256 } },
    { 0x7F20002, 0x7F20000, { 896, 256 } },
    { 0x7D00002, 0x7D00000, { 896, 256 } },
    { 0x7F40002, 0x7F40000, { 896, 256 } },
    { 0x7810001, 0x7810000, { 896, 256 } },
    { 0x7F60002, 0x7F60000, { 896, 256 } },
    { 0x7F30003, 0x7F30000, { 896, 256 } },
    { 0x87F0002, 0x87F0000, { 896, 256 } },
    { 0x8780002, 0x8780000, { 896, 256 } },
    { 0x8790004, 0x8790000, { 896, 256 } },
    { 0x8770002, 0x8770000, { 896, 256 } },
    { 0x87A0004, 0x87A0000, { 896, 256 } },
    { 0x8010002, 0x8010000, { 896, 256 } },
    { 0x8090002, 0x8090000, { 896, 256 } },
};
#elif VERSION_EU
EffectSheet FIGHTSTG_effectSheets[] = {
    { 0, 0x79D0026, { 320, 256 } },
    { 0, 0x7A30000, { 448, 256 } },
    { 0, 0x7E00000, { 512, 256 } },
    { 0, 0x7E20000, { 576, 256 } },
    { 0, 0, { 576, 256 } },
    { 0x7F50006, 0x7F50000, { 768, 256 } },
    { 0x8A20005, 0x8A20000, { 768, 256 } },
    { 0x80F0002, 0x80F0000, { 896, 256 } },
    { 0x78B0002, 0x78B0000, { 896, 256 } },
    { 0x80E0003, 0x80E0000, { 896, 256 } },
    { 0x7890003, 0x7890000, { 896, 256 } },
    { 0x81C0002, 0x81C0001, { 896, 256 } },
    { 0x7E50003, 0x7E50000, { 896, 256 } },
    { 0x6D90002, 0x6D90000, { 896, 256 } },
    { 0x7E60003, 0x7E60000, { 896, 256 } },
    { 0x8110002, 0x8110000, { 896, 256 } },
    { 0x81D0002, 0x81D0001, { 896, 256 } },
    { 0x78C0002, 0x78C0000, { 896, 256 } },
    { 0x7DB0002, 0x7DB0000, { 896, 256 } },
    { 0x7E70002, 0x7E70000, { 896, 256 } },
    { 0x8120002, 0x8120000, { 896, 256 } },
    { 0x7A50002, 0x7A50000, { 896, 256 } },
    { 0x8190002, 0x8190000, { 896, 256 } },
    { 0x78D0003, 0x78D0000, { 896, 256 } },
    { 0x78E0005, 0x78E0000, { 896, 256 } },
    { 0x89D0002, 0x89D0000, { 896, 256 } },
    { 0x78F0004, 0x78F0000, { 896, 256 } },
    { 0x7DC0002, 0x7DC0000, { 896, 256 } },
    { 0x8130003, 0x8130000, { 896, 256 } },
    { 0x8180002, 0x8180000, { 896, 256 } },
    { 0x81B0002, 0x81B0000, { 896, 256 } },
    { 0x78A0003, 0x78A0000, { 896, 256 } },
    { 0x7730002, 0x7730000, { 896, 256 } },
    { 0x83D0002, 0x83D0000, { 896, 256 } },
    { 0x7E80003, 0x7E80000, { 896, 256 } },
    { 0x7DD0003, 0x7DD0000, { 896, 256 } },
    { 0x7DE0002, 0x7DE0000, { 896, 256 } },
    { 0x7E90004, 0x7E90000, { 896, 256 } },
    { 0x8010002, 0x8010000, { 896, 256 } },
    { 0x7DF0002, 0x7DF0000, { 896, 256 } },
    { 0x8030002, 0x8030000, { 896, 256 } },
    { 0x7900001, 0x7900000, { 896, 256 } },
    { 0x8050002, 0x8050000, { 896, 256 } },
    { 0x8020003, 0x8020000, { 896, 256 } },
    { 0x8900002, 0x8900000, { 896, 256 } },
    { 0x8890002, 0x8890000, { 896, 256 } },
    { 0x88A0004, 0x88A0000, { 896, 256 } },
    { 0x8880002, 0x8880000, { 896, 256 } },
    { 0x88B0004, 0x88B0000, { 896, 256 } },
    { 0x8100002, 0x8100000, { 896, 256 } },
    { 0x81A0002, 0x81A0000, { 896, 256 } },
};
#endif
/* the 2D effects, ended by an id of -1; the European version's differ */
#if VERSION_US
SpriteEffectEntry FIGHTSTG_spriteEffects[] = {
    { 0, 0, 0x78E0000 },
    { 1, 0, 0x78E0001 },
    { 2, 0, 0x78E0002 },
    { 19, 0, 0x78E0003 },
    { 20, 0, 0x78E0028 },
    { 21, 0, 0x78E0004 },
    { 22, 0, 0x78E0005 },
    { 23, 0, 0x78E0006 },
    { 24, 0, 0x78E0007 },
    { 25, 0, 0x78E0027 },
    { 26, 0, 0x78E0008 },
    { 27, 0, 0x78E0009 },
    { 28, 0, 0x78E000A },
    { 29, 0, 0x78E000B },
    { 31, 0, 0x78E000C },
    { 32, 0, 0x78E000D },
    { 42, 0, 0x78E0017 },
    { 43, 0, 0x78E0018 },
    { 44, 0, 0x78E0019 },
    { 45, 0, 0x78E001A },
    { 46, 0, 0x78E001B },
    { 47, 0, 0x78E001C },
    { 57, 0, 0x78E0024 },
    { 58, 0, 0x78E0025 },
    { 33, 0, 0x78E000E },
    { 34, 0, 0x78E000F },
    { 35, 0, 0x78E0010 },
    { 36, 0, 0x78E0011 },
    { 37, 0, 0x78E0012 },
    { 38, 0, 0x78E0013 },
    { 39, 0, 0x78E0014 },
    { 40, 0, 0x78E0015 },
    { 41, 0, 0x78E0016 },
    { 50, 0, 0x78E001D },
    { 51, 0, 0x78E001E },
    { 52, 0, 0x78E001F },
    { 53, 0, 0x78E0020 },
    { 54, 0, 0x78E0021 },
    { 55, 0, 0x78E0022 },
    { 56, 0, 0x78E0023 },
    { 13, 1, 0x7940001 },
    { 14, 1, 0x7940002 },
    { 15, 1, 0x7940003 },
    { 16, 1, 0x7940004 },
    { 17, 1, 0x7940005 },
    { 18, 1, 0x7940006 },
    { 64, 1, 0x7940008 },
    { 65, 1, 0x7940009 },
    { 3, 2, 0x7D10001 },
    { 4, 2, 0x7D10002 },
    { 5, 2, 0x7D10003 },
    { 6, 2, 0x7D10004 },
    { 7, 2, 0x7D10005 },
    { 8, 2, 0x7D10006 },
    { 9, 2, 0x7D10007 },
    { 10, 2, 0x7D10008 },
    { 11, 2, 0x7D10009 },
    { 12, 2, 0x7D1000A },
    { 63, 2, 0x7D1000B },
    { 62, 3, 0x7D3000B },
    { 1009, 3, 0x7D30009 },
    { 1012, 3, 0x7D30003 },
    { 1013, 3, 0x7D30004 },
    { 1014, 3, 0x7D30005 },
    { 1017, 3, 0x7D30008 },
    { 1020, 3, 0x7D3000A },
    { 1004, 5, 0x7E60001 },
    { 1005, 5, 0x7E60002 },
    { 1006, 5, 0x7E60003 },
    { 1000, 6, 0x8910001 },
    { 1001, 6, 0x8910002 },
    { 1002, 6, 0x8910003 },
    { 1003, 6, 0x8910004 },
    { 1007, 6, 0x8910006 },
    { 1008, 6, 0x8910007 },
    { 1010, 7, 0x8000001 },
    { 59, 9, 0x7FF0001 },
    { 60, 9, 0x7FF0002 },
    { 1018, 9, 0x7FF0006 },
    { 1019, 9, 0x7FF0007 },
    { 2040, 8, 0x77C0001 },
    { 2036, 10, 0x77A0001 },
    { 2037, 10, 0x77A0002 },
    { 2058, 11, 0x80B0000 },
    { 1021, 12, 0x7D60004 },
    { 2027, 12, 0x7D60001 },
    { 2028, 12, 0x7D60002 },
    { 2043, 13, 0x6CA0001 },
    { 2011, 14, 0x7D70001 },
    { 2012, 14, 0x7D70002 },
    { 1015, 15, 0x8020001 },
    { 2059, 15, 0x8020003 },
    { 2060, 16, 0x80C0000 },
    { 2056, 17, 0x77D0003 },
    { 2031, 17, 0x77D0001 },
    { 2014, 18, 0x7CC0001 },
    { 2026, 19, 0x7D80001 },
    { 1016, 20, 0x8030001 },
    { 2044, 21, 0x7960001 },
    { 1022, 22, 0x8080001 },
    { 2019, 23, 0x77E0001 },
    { 2020, 23, 0x77E0002 },
    { 2008, 24, 0x77F0002 },
    { 2009, 24, 0x77F0003 },
    { 2010, 24, 0x77F0004 },
    { 2062, 25, 0x88C0001 },
    { 2000, 26, 0x7800001 },
    { 2001, 26, 0x7800002 },
    { 2002, 26, 0x7800003 },
    { 2004, 27, 0x7CD0001 },
    { 2046, 28, 0x8040001 },
    { 2047, 28, 0x8040002 },
    { 2061, 29, 0x8070001 },
    { 2057, 30, 0x80A0001 },
    { 2029, 31, 0x77B0001 },
    { 2030, 31, 0x77B0002 },
    { 2032, 32, 0x7640001 },
    { 2007, 33, 0x82C0001 },
    { 2041, 34, 0x7D90001 },
    { 2042, 34, 0x7D90002 },
    { 2024, 35, 0x7CE0001 },
    { 2025, 35, 0x7CE0002 },
    { 2005, 36, 0x7CF0001 },
    { 2006, 36, 0x7CF0003 },
    { 2016, 37, 0x7DA0001 },
    { 2017, 37, 0x7DA0002 },
    { 2018, 37, 0x7DA0003 },
    { 2038, 38, 0x7F20003 },
    { 2039, 38, 0x7F20004 },
    { 2003, 39, 0x7D00001 },
    { 2015, 40, 0x7F40001 },
    { 2021, 41, 0x7810002 },
    { 2022, 41, 0x7810003 },
    { 2023, 41, 0x7810004 },
    { 2013, 42, 0x7F60001 },
    { 2033, 43, 0x7F30001 },
    { 2034, 43, 0x7F30002 },
    { 2035, 44, 0x87F0001 },
    { 2049, 45, 0x8780001 },
    { 2050, 46, 0x8790001 },
    { 2051, 46, 0x8790002 },
    { 2052, 46, 0x8790003 },
    { 2048, 47, 0x8770001 },
    { 2053, 48, 0x87A0001 },
    { 2054, 48, 0x87A0002 },
    { 2055, 48, 0x87A0003 },
    { 1011, 49, 0x8010001 },
    { 2045, 50, 0x8090001 },
    { -1, 0, 0 },
};
#elif VERSION_EU
SpriteEffectEntry FIGHTSTG_spriteEffects[] = {
    { 0, 0, 0x79D0000 },
    { 1, 0, 0x79D0001 },
    { 2, 0, 0x79D0002 },
    { 19, 0, 0x79D0003 },
    { 20, 0, 0x79D0028 },
    { 21, 0, 0x79D0004 },
    { 22, 0, 0x79D0005 },
    { 23, 0, 0x79D0006 },
    { 24, 0, 0x79D0007 },
    { 25, 0, 0x79D0027 },
    { 26, 0, 0x79D0008 },
    { 27, 0, 0x79D0009 },
    { 28, 0, 0x79D000A },
    { 29, 0, 0x79D000B },
    { 31, 0, 0x79D000C },
    { 32, 0, 0x79D000D },
    { 42, 0, 0x79D0017 },
    { 43, 0, 0x79D0018 },
    { 44, 0, 0x79D0019 },
    { 45, 0, 0x79D001A },
    { 46, 0, 0x79D001B },
    { 47, 0, 0x79D001C },
    { 57, 0, 0x79D0024 },
    { 58, 0, 0x79D0025 },
    { 33, 0, 0x79D000E },
    { 34, 0, 0x79D000F },
    { 35, 0, 0x79D0010 },
    { 36, 0, 0x79D0011 },
    { 37, 0, 0x79D0012 },
    { 38, 0, 0x79D0013 },
    { 39, 0, 0x79D0014 },
    { 40, 0, 0x79D0015 },
    { 41, 0, 0x79D0016 },
    { 50, 0, 0x79D001D },
    { 51, 0, 0x79D001E },
    { 52, 0, 0x79D001F },
    { 53, 0, 0x79D0020 },
    { 54, 0, 0x79D0021 },
    { 55, 0, 0x79D0022 },
    { 56, 0, 0x79D0023 },
    { 13, 1, 0x7A30001 },
    { 14, 1, 0x7A30002 },
    { 15, 1, 0x7A30003 },
    { 16, 1, 0x7A30004 },
    { 17, 1, 0x7A30005 },
    { 18, 1, 0x7A30006 },
    { 64, 1, 0x7A30008 },
    { 65, 1, 0x7A30009 },
    { 3, 2, 0x7E00001 },
    { 4, 2, 0x7E00002 },
    { 5, 2, 0x7E00003 },
    { 6, 2, 0x7E00004 },
    { 7, 2, 0x7E00005 },
    { 8, 2, 0x7E00006 },
    { 9, 2, 0x7E00007 },
    { 10, 2, 0x7E00008 },
    { 11, 2, 0x7E00009 },
    { 12, 2, 0x7E0000A },
    { 63, 2, 0x7E0000B },
    { 62, 3, 0x7E2000B },
    { 1009, 3, 0x7E20009 },
    { 1012, 3, 0x7E20003 },
    { 1013, 3, 0x7E20004 },
    { 1014, 3, 0x7E20005 },
    { 1017, 3, 0x7E20008 },
    { 1020, 3, 0x7E2000A },
    { 1004, 5, 0x7F50001 },
    { 1005, 5, 0x7F50002 },
    { 1006, 5, 0x7F50003 },
    { 1000, 6, 0x8A20001 },
    { 1001, 6, 0x8A20002 },
    { 1002, 6, 0x8A20003 },
    { 1003, 6, 0x8A20004 },
    { 1007, 6, 0x8A20006 },
    { 1008, 6, 0x8A20007 },
    { 1010, 7, 0x80F0001 },
    { 59, 9, 0x80E0001 },
    { 60, 9, 0x80E0002 },
    { 1018, 9, 0x80E0006 },
    { 1019, 9, 0x80E0007 },
    { 2040, 8, 0x78B0001 },
    { 2036, 10, 0x7890001 },
    { 2037, 10, 0x7890002 },
    { 2058, 11, 0x81C0000 },
    { 1021, 12, 0x7E50004 },
    { 2027, 12, 0x7E50001 },
    { 2028, 12, 0x7E50002 },
    { 2043, 13, 0x6D90001 },
    { 2011, 14, 0x7E60001 },
    { 2012, 14, 0x7E60002 },
    { 1015, 15, 0x8110001 },
    { 2059, 15, 0x8110003 },
    { 2060, 16, 0x81D0000 },
    { 2056, 17, 0x78C0003 },
    { 2031, 17, 0x78C0001 },
    { 2014, 18, 0x7DB0001 },
    { 2026, 19, 0x7E70001 },
    { 1016, 20, 0x8120001 },
    { 2044, 21, 0x7A50001 },
    { 1022, 22, 0x8190001 },
    { 2019, 23, 0x78D0001 },
    { 2020, 23, 0x78D0002 },
    { 2008, 24, 0x78E0002 },
    { 2009, 24, 0x78E0003 },
    { 2010, 24, 0x78E0004 },
    { 2062, 25, 0x89D0001 },
    { 2000, 26, 0x78F0001 },
    { 2001, 26, 0x78F0002 },
    { 2002, 26, 0x78F0003 },
    { 2004, 27, 0x7DC0001 },
    { 2046, 28, 0x8130001 },
    { 2047, 28, 0x8130002 },
    { 2061, 29, 0x8180001 },
    { 2057, 30, 0x81B0001 },
    { 2029, 31, 0x78A0001 },
    { 2030, 31, 0x78A0002 },
    { 2032, 32, 0x7730001 },
    { 2007, 33, 0x83D0001 },
    { 2041, 34, 0x7E80001 },
    { 2042, 34, 0x7E80002 },
    { 2024, 35, 0x7DD0001 },
    { 2025, 35, 0x7DD0002 },
    { 2005, 36, 0x7DE0001 },
    { 2006, 36, 0x7DE0003 },
    { 2016, 37, 0x7E90001 },
    { 2017, 37, 0x7E90002 },
    { 2018, 37, 0x7E90003 },
    { 2038, 38, 0x8010003 },
    { 2039, 38, 0x8010004 },
    { 2003, 39, 0x7DF0001 },
    { 2015, 40, 0x8030001 },
    { 2021, 41, 0x7900002 },
    { 2022, 41, 0x7900003 },
    { 2023, 41, 0x7900004 },
    { 2013, 42, 0x8050001 },
    { 2033, 43, 0x8020001 },
    { 2034, 43, 0x8020002 },
    { 2035, 44, 0x8900001 },
    { 2049, 45, 0x8890001 },
    { 2050, 46, 0x88A0001 },
    { 2051, 46, 0x88A0002 },
    { 2052, 46, 0x88A0003 },
    { 2048, 47, 0x8880001 },
    { 2053, 48, 0x88B0001 },
    { 2054, 48, 0x88B0002 },
    { 2055, 48, 0x88B0003 },
    { 1011, 49, 0x8100001 },
    { 2045, 50, 0x81A0001 },
    { -1, 0, 0 },
};
#endif

s32 FIGHTSTG_findEffectSheet(s32 effect, s32 *unk0, s32 *sheet, Vec2 *texPos) {
    SpriteEffectEntry *entry;

    for (entry = FIGHTSTG_spriteEffects; entry->id != -1; entry++) {
        if (entry->id == effect) {
            *unk0 = FIGHTSTG_effectSheets[entry->sheet].unk0;
            *sheet = FIGHTSTG_effectSheets[entry->sheet].sheet;
            *texPos = FIGHTSTG_effectSheets[entry->sheet].texPos;
            return 1;
        }
    }
    return 0;
}

void FIGHTSTG_updateSpriteEffect(SpriteEffect *task, SpriteAnim **children) {
    s32 *archive;
    s32 layerId;
    s32 count;
    s32 i;
    s32 j;
    s32 done;

    switch (task->state) {
    case TASK_INIT:
    default:
        archive = (s32 *)FILE_CACHE.getEntry(task->file);
        layerId = 0x1004;
        if (task->effect >= 1000 && task->effect < 1003) {
            layerId = 0x1006;
        }
        if (task->effect == 1007) {
            layerId = 0x1006;
        }
        for (count = 0; count < 30; count++) {
            if (archive[count] == 0) {
                break;
            }
        }
        for (i = 0; i < count; i++) {
            children[i] = FIGHTSTG_createSpriteAnim((s16 *)FILE_CACHE.getArchiveEntry(i, (s32)archive), &task->pos,
                                        FIGHTSTG_effectSheets[task->sheet].sheet, &FIGHTSTG_effectSheets[task->sheet].texPos, layerId);
        }
        task->count = count;
        task->nextState(task);
        break;
    case TASK_RUN:
        done = 1;
        for (j = 0; j < task->count; j++) {
            if (children[j] != NULL) {
                done = 0;
                break;
            }
        }
        if (done) {
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

SpriteEffect *FIGHTSTG_startSpriteEffect(s32 effect, SVECTOR *pos) {
    SpriteEffect *task = createTask(FIGHTSTG_updateSpriteEffect, sizeof(SpriteEffect), 30 * sizeof(Task *));
    SpriteEffectEntry *entry;

    task->effect = -1;
    for (entry = FIGHTSTG_spriteEffects; entry->id != -1; entry++) {
        if (entry->id == effect) {
            task->effect = effect;
            task->sheet = entry->sheet;
            task->file = entry->file;
            task->pos = *pos;
        }
    }
    if (task->effect == -1) {
        task->setState(task, TASK_KILL);
    }
    return task;
}

/* where FIGHTSTG_updateDigimonChange's effects are */
const SVECTOR D_80082560 = { 0, 0, 0x7FFF, 0 };
const SVECTOR D_80082568 = { 160, 120, 0x7FFF, 0 };
const SVECTOR D_80082570 = { -160, -120, -1, 0 };

/* A partner Digimon's change: a stage of its own, the new Digimon's model in
   front of a sprite effect, the old one wiped away by the clips of layers 0x1004
   and 0x1003, and a fade back to the battle. The match depends on the block
   of its own for substate 2's control, on z read and then negated, on the
   if/else of the motion, on clip1.h written before clip1.y in substate 3 and on
   the layers kept in blocks of their own */
void FIGHTSTG_updateDigimonChange(DigimonChange *task, DigimonChangeChildren *children) {
    Models *models = task->models;
    BattleCamera *camera = task->camera;
    FightStage *stage = task->stage;
    TimLoader loader;
    ModelControl *control;
    s32 z;
    s32 t;
    s16 y;

    switch (task->state) {
    case 0:
    default:
        switch (task->substate) {
        case 0:
        default:
            switch (task->step) {
            case 0:
            default:
                SOUND.loadBank(0x45);
                task->nextStep(task);
            case 1:
                if (SOUND.isLoading() == 0) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 1:
            models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            task->models = models;
            task->camera = TASK_REGISTRY.funcs.find(BATTLE_TASK_CAMERA, -1, -1);
            task->stage = TASK_REGISTRY.funcs.find(BATTLE_TASK_STAGE, -1, -1);
            task->file = FIGHTSTG_fighterCache.funcs.getInfo(task->key1)->model >> 16;
            FILE_CACHE.request(task->file);
            task->idleMotion = models->get(models, 0)->idleMotion;
            task->nextSubstate(task);
        case 2:
            if (FILE_CACHE.isLoading(task->file) != 0) {
                break;
            }
            FILE_CACHE.request(FILE_CHANGE);
            task->nextSubstate(task);
        case 3:
            if (FILE_CACHE.isLoading(FILE_CHANGE) != 0) {
                break;
            }
            initTimLoader(&loader);
            loader.setImagePos(0x300, 0x100);
            loader.loadArchive(FILE_CACHE.getEntry((FILE_CHANGE << 16) | 5));
            task->nextState(task);
            break;
        }
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            stage->setStage(stage, task->key2 != 0 ? 0x1F : 0x1C, 0x20, 0x20);
            task->nextSubstate(task);
        case 1:
            switch (task->step) {
            case 0:
            default:
                if (stage->state == 2) {
                    break;
                }
                SOUND.playSound(0x41140000);
                models->add(models, 1, task->key1, 0);
                task->nextStep(task);
            case 1:
                task->counter += GFX.funcs.getFrameTime();
                if (task->counter >= 180) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 2:
            {
                ModelControl *control;

                task->clip0.x = 0;
                task->clip0.y = 0;
                task->clip0.w = 320;
                task->clip0.h = 240;
                task->clip1.x = 0;
                task->clip1.y = 240;
                task->clip1.w = 320;
                task->clip1.h = 0;
                control = models->get(models, 0);
                camera->getFighterView(camera, 0, 9);
                z = control->homePos.z;
                z = -z;
                FIGHTSTG_fighterView.vpz += z;
                FIGHTSTG_fighterView.vrz += z;
                camera->set(camera, &FIGHTSTG_fighterView);
                control->unk34[1].enabled = 1;
                control->unk34[1].alt = 1;
                control->unk34[1].arg = 0x1003;
                control->pos.x = 0;
                control->pos.z = 0;
                control->rot.x = 0;
                control->rot.y = 0x800;
                control->rot.z = 0;
                control->pos.y = control->homePos.y;
                if (task->key2 != 0) {
                    control->motion = 14;
                } else {
                    control->motion = 13;
                }
                models->get(models, 0x10)->unk34[0].enabled = 0;
                if (task->key2 == 0) {
                    children->effects[0] = FIGHTSTG_startSpriteEffect(1000, (SVECTOR *)&D_80082560);
                    children->effects[1] = FIGHTSTG_startSpriteEffect(1001, (SVECTOR *)&D_80082560);
                } else {
                    children->effects[0] = FIGHTSTG_startSpriteEffect(1007, (SVECTOR *)&D_80082560);
                }
            }
            task->nextSubstate(task);
        case 3:
            t = GFX.funcs.getFrameTime();
            task->clip0.h -= t * 2;
            task->clip1.h += t * 2;
            task->clip1.y -= t * 2;
            if (task->clip1.y <= 0) {
                task->clip0.h = 0;
                task->clip1.h = 240;
                task->clip1.y = 0;
                models->get(models, 0)->unk34[0].enabled = 0;
                children->effects[2] = FIGHTSTG_startSpriteEffect(1002, (SVECTOR *)&D_80082568);
                task->nextSubstate(task);
            }
            {
                Layer *layer = GFX.funcs.getLayer(0x1004);

                layer->setClipPos(layer, task->clip0.x, task->clip0.y);
                layer->setClipSize(layer, task->clip0.w, task->clip0.h);
                layer = GFX.funcs.getLayer(0x1003);
                layer->setClipPos(layer, task->clip1.x, task->clip1.y);
                layer->setClipSize(layer, task->clip1.w, task->clip1.h);
            }
            break;
        case 4:
            task->counter += GFX.funcs.getFrameTime();
            if (task->counter >= 120) {
                task->nextSubstate(task);
            }
            break;
        case 5:
            switch (task->step) {
            case 0:
            default:
                children->fade = FIGHTSTG_startWhiteFlash(32);
                task->nextStep(task);
                break;
            case 1:
                if (children->fade->substate != 0) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 6:
            models->setId(models, 1, 0);
            control = models->get(models, 0);
            control->unk34[0].enabled = 1;
            control->unk34[0].arg = 0x1004;
            control->unk34[0].alt = 0;
            control->unk34[1].enabled = 1;
            control->unk34[1].alt = 1;
            control->unk34[1].arg = 0x1003;
            models->face(models, 0);
            camera->getFighterView(camera, 0, 9);
            z = control->homePos.z;
            z = -z;
            FIGHTSTG_fighterView.vpz += z;
            FIGHTSTG_fighterView.vrz += z;
            camera->set(camera, &FIGHTSTG_fighterView);
            control->pos.x = 0;
            control->pos.z = 0;
            control->rot.x = 0;
            control->rot.y = 0x800;
            control->rot.z = 0;
            control->pos.y = control->homePos.y;
            task->clip0.x = 0;
            task->clip0.y = 0;
            task->clip0.w = 320;
            task->clip0.h = 0;
            task->clip1.x = 0;
            task->clip1.y = 0;
            task->clip1.w = 320;
            task->clip1.h = 240;
            task->nextSubstate(task);
        case 7:
            switch (task->step) {
            case 0:
            default:
                children->fade->setState(children->fade, 2);
                task->nextStep(task);
                break;
            case 1:
                if (children->fade == NULL) {
                    task->nextSubstate(task);
                }
                break;
            }
            break;
        case 8:
            t = GFX.funcs.getFrameTime();
            task->clip0.h += t * 2;
            task->clip1.y += t * 2;
            task->clip1.h -= t * 2;
            if (task->clip0.h >= 240) {
                task->clip0.h = 240;
                task->clip1.y = 240;
                task->clip1.h = 0;
                models->get(models, 0)->unk34[1].enabled = 0;
                children->effects[3] = FIGHTSTG_startSpriteEffect(task->key2 == 0 ? 1003 : 1008, (SVECTOR *)&D_80082570);
                task->nextSubstate(task);
            }
            {
                Layer *layer = GFX.funcs.getLayer(0x1004);

                layer->setClipPos(layer, task->clip0.x, task->clip0.y);
                layer->setClipSize(layer, task->clip0.w, task->clip0.h);
                layer = GFX.funcs.getLayer(0x1003);
                layer->setClipPos(layer, task->clip1.x, task->clip1.y);
                layer->setClipSize(layer, task->clip1.w, task->clip1.h);
            }
            break;
        case 9:
            models->get(models, 0)->motion = 13;
            task->nextSubstate(task);
        case 10:
            task->counter += GFX.funcs.getFrameTime();
            if (task->counter >= 180) {
                task->nextSubstate(task);
            }
            break;
        case 11:
            stage->setStage(stage, BATTLE_SETUP.stage, 0x20, 0x20);
            task->nextSubstate(task);
        case 12:
            if (stage->state != 2) {
                models->face(models, 0);
                camera->set(camera, camera->getFighterView(camera, 0, 9));
                task->nextSubstate(task);
            }
            break;
        case 13:
            task->nextSubstate(task);
            break;
        case 14:
            switch (task->step) {
            case 0:
            default:
                models->get(models, 0x10)->unk34[0].enabled = 1;
                models->get(models, 0)->motion = task->key2 != 0 || task->idleMotion == 0 ? 1 : 2;
                camera->fade(camera, NULL, camera->getEnemyView(camera), 60);
                SOUND.playSound(BATTLE_SETUP.music);
                task->nextStep(task);
                break;
            case 1:
                task->counter += GFX.funcs.getFrameTime();
                if (task->counter >= 60) {
                    task->setState(task, 3);
                }
                break;
            }
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts a partner's Digimon change (FIGHTSTG_updateDigimonChange) */
DigimonChange *FIGHTSTG_startDigimonChange(s32 key1, s32 key2) {
    DigimonChange *task = createTask(FIGHTSTG_updateDigimonChange, sizeof(DigimonChange), 6 * sizeof(Task *));

    task->key1 = key1;
    task->key2 = key2;
    return task;
}

void FIGHTSTG_startScreenFade(ScreenFade *task, s32 fadeIn, s32 duration) {
    task->setState(task, TASK_RUN);
    task->substate = 1;
    task->fadeIn = fadeIn;
    if (fadeIn == 0) {
        task->level = 0;
        task->levelStep = 0xFF00 / duration;
    } else {
        task->level = 0xFF00;
        task->levelStep = -(0xFF00 / duration);
    }
}

/* A full-screen rectangle that subtracts the level from the screen */
void FIGHTSTG_drawScreenFade(ScreenFade *task) {
    Layer *layer;
    u_long *ot;
    POLY_F4 *poly;
    DR_TPAGE *mode;

    layer = GFX.funcs.getLayer(task->layerId);
    ot = (u_long *)layer->getOtEntry(layer, task->depth);
    poly = GFX.funcs.getPrim();
    setlen(poly, 5);
    poly->code = 0x2A;
    poly->r0 = poly->g0 = poly->b0 = task->level >> 8;
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 0;
    poly->y2 = poly->y3 = 256;
    addPrim(ot, poly);
    mode = (DR_TPAGE *)(poly + 1);
    setlen(mode, 1);
    mode->code[0] = 0xE1000245;
    addPrim(ot, mode);
    GFX.funcs.setPrim(mode + 1);
}

void FIGHTSTG_updateScreenFade(ScreenFade *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->state = TASK_RUN;
        break;
    case TASK_RUN:
        if (task->substate == 0) {
            break;
        }
        task->level += task->levelStep;
        if (task->fadeIn == 0) {
            if (task->level > 0xFF00) {
                task->level = 0xFF00;
                task->state = TASK_DONE;
            }
        } else if (task->level < 0) {
            task->level = 0;
            task->state = TASK_DONE;
        }
        FIGHTSTG_drawScreenFade(task);
        break;
    case TASK_DONE:
        FIGHTSTG_drawScreenFade(task);
        break;
    case TASK_KILL:
        break;
    }
}

ScreenFade *FIGHTSTG_createScreenFade(void) {
    ScreenFade *task = createTask(FIGHTSTG_updateScreenFade, sizeof(ScreenFade), 0);

    task->start = FIGHTSTG_startScreenFade;
    task->layerId = 0x1006;
    task->depth = 0;
    return task;
}
