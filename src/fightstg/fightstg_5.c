/* The fifth object of FIGHTSTG.PRO (see fightstg.c), from the battle
   script: its rodata starts at 0x800825D0 (USA). */

#include "fightstg.h"

/* The model a script command names by TYPE: 0 the script's own side's, 1-3
   the partner's slots and 4-6 the enemy's */
s32 FIGHTSTG_getScriptModel(BattleScript *script, s32 type) {
    switch (type) {
    case 0:
    default:
        return script->unk50 != 0 ? 0x10 : 0;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 0x10;
    case 5:
        return 0x11;
    case 6:
        return 0x12;
    }
}

/* The battle script's hit command: 0 starts the other side's script for the
   last hit's result, 5 the one for the next hit's */
void FIGHTSTG_runScriptHits(BattleScript *script, BattleScriptChildren *children) {
    s32 hit;

    switch (*script->pc++) {
    case 0:
        if (children->script != NULL) {
            children->script->destroy(children->script);
        }
        children->script = FIGHTSTG_createBattleScript();
        children->script->unk50 = script->unk50 == 0;
        children->script->index = script->hits[3] + 1;
        break;
    /* the match depends on these cases, which do nothing */
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        if (children->script != NULL) {
            children->script->destroy(children->script);
        }
        children->script = FIGHTSTG_createBattleScript();
        children->script->unk50 = script->unk50 == 0;
        switch (script->scripts) {
        case 0:
        default:
            hit = script->hits[0];
            break;
        case 1:
            hit = script->hits[1];
            break;
        case 2:
            hit = script->hits[2];
            break;
        }
        children->script->index = hit + 1;
        script->scripts++;
        break;
    }
}

/* The battle script's model command, on the model given by FIGHTSTG_getScriptModel:
   0 plays a motion (0 waits for the one playing, 1 goes back to idle), 1
   and 2 turn unk34[0] on and off, 3 moves it to a position in the script
   (over a time, or at once when it is 0), 4 turns it, 5 makes it jump (0
   waits for the jump), 6 adds a model (waiting while its file loads in
   script 12), 7 moves it home, 8 0x2800 from home and 9 removes it.
   Returning 0 runs the command again. The match depends on each case's
   time being its own and on case 3's being read before the position. */
s32 FIGHTSTG_runScriptModel(BattleScript *script, BattleScriptChildren *children) {
    ShortVec3 pos;
    s32 arg = 0;
    ModelControl *control = NULL;
    s32 cmd = *script->pc++;
    s32 id = FIGHTSTG_getScriptModel(script, *script->pc++);
    Models *models;

    switch (cmd) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
        break;
    default:
        arg = *script->pc++;
        break;
    }
    if (cmd != 6 && cmd != 9) {
        control = script->models->get(script->models, id);
    }
    switch (cmd) {
    case 0:
        switch (arg) {
        case 0:
            if (control->motionDone == 0) {
                script->pc -= 4;
                return 0;
            }
            return 1;
        case 1:
            control->motionDone = 0;
            control->motion = control->idleMotion + 1;
            break;
        default:
            control->motion = arg + 1;
            control->restart = 1;
            control->motionDone = 0;
            break;
        }
        break;
    case 5:
        switch (arg) {
        case 0:
            if (children->unk4 == NULL) {
                return 1;
            }
            if (children->unk4->state < 2) {
                script->pc -= 4;
                return 0;
            }
            return 1;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            if (children->unk4 != NULL) {
                children->unk4->destroy(children->unk4);
            }
            children->unk4 = (Task *)FIGHTSTG_startJump(control, arg, 0);
            break;
        case 4: {
            s32 distance = *script->pc++;

            if (children->unk4 != NULL) {
                children->unk4->destroy(children->unk4);
            }
            children->unk4 = (Task *)FIGHTSTG_startJump(control, arg, distance);
            break;
        }
        }
        break;
    case 1:
        control->unk34[0].enabled = 1;
        return 1;
    case 2:
        control->unk34[0].enabled = 0;
        break;
    case 3: {
        s32 time = script->pc[3];

        pos.x = script->pc[0];
        pos.y = -script->pc[1];
        pos.z = -script->pc[2];
        script->pc += 4;
        if (time != 0) {
            children->unk8 = (Task *)FIGHTSTG_startMove(control, &pos, time);
        } else {
            control->pos.x = pos.x;
            control->pos.y = pos.y;
            control->pos.z = pos.z;
        }
        break;
    }
    case 4:
        control->rot.x = *script->pc++;
        control->rot.y = -*script->pc++;
        control->rot.z = -*script->pc++;
        script->pc++;
        break;
    case 6:
        if (script->index == 12 && FILE_CACHE.isLoading(FIGHTSTG_fighterCache.funcs.getInfo(arg)->model >> 16)) {
            script->pc -= 4;
            return 0;
        }
        models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
        models->add(models, id, arg, 0);
        return 1;
    case 7: {
        s32 time = *script->pc++;

        if (time != 0) {
            children->unk8 = (Task *)FIGHTSTG_startMove(control, &control->homePos, time);
        } else {
            control->pos.x = control->homePos.x;
            control->pos.y = control->homePos.y;
            control->pos.z = control->homePos.z;
        }
        break;
    }
    case 8: {
        s32 time = *script->pc++;

        pos.x = control->homePos.x;
        pos.y = control->homePos.y;
        if (id & 0xF0) {
            pos.z = control->homePos.z - 0x2800;
        } else {
            pos.z = control->homePos.z + 0x2800;
        }
        if (time != 0) {
            children->unk8 = (Task *)FIGHTSTG_startMove(control, &pos, time);
        } else {
            control->pos.x = pos.x;
            control->pos.y = pos.y;
            control->pos.z = pos.z;
        }
        break;
    }
    case 9:
        models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
        models->remove(models, id);
        break;
    }
    return 1;
}

/* The battle script's effect command: 0 starts sprite effect EFFECT (9999 the
   script's own) at a position in the script, 1 loads its images and sheet,
   running again until they are in. Returning 0 runs the command again */
s32 FIGHTSTG_runScriptEffect(BattleScript *script, BattleScriptChildren *children) {
    SVECTOR pos;
    TimLoader loader;
    s32 mode = *script->pc++;
    s32 effect = *script->pc++;
    s32 i;

    if (effect == 9999) {
        effect = script->unk6C;
    }
    switch (mode) {
    case 0:
    default:
        pos.vx = *script->pc++;
        pos.vy = *script->pc++;
        pos.vz = *script->pc++;
        for (i = 0; i < 8; i++) {
            if (children->unk10[i] == NULL) {
                children->unk10[i] = (Task *)FIGHTSTG_startSpriteEffect(effect, &pos);
                break;
            }
        }
        break;
    case 1:
        switch (script->loadStep) {
        case 0:
        default:
            if (!FIGHTSTG_findEffectSheet(effect, &script->effectImages, &script->effectSheet, &script->effectTexPos)) {
                break;
            }
            script->loadStep++;
            /* fallthrough */
        case 1:
            if (script->effectImages == 0 || !FILE_CACHE.isLoading(script->effectImages >> 16)) {
                script->loadStep++;
            }
            script->pc -= 3;
            return 0;
        case 2:
            if (script->effectImages != 0) {
                initTimLoader(&loader);
                loader.setImagePos(script->effectTexPos.x, script->effectTexPos.y);
                loader.loadArchive(FILE_CACHE.getEntry(script->effectImages));
            }
            script->loadStep++;
            /* fallthrough */
        case 3:
            if (script->effectSheet != 0 && FILE_CACHE.isLoading(script->effectSheet >> 16)) {
                script->pc -= 3;
            } else {
                script->loadStep = 0;
            }
            return 0;
        }
    }
    return 1;
}

/* The battle script's effect model command: 0 starts effect model ID at a
   position and rotation in the script (their y and z negated), 1 waits while
   its file loads. Returning 0 runs the command again */
s32 FIGHTSTG_runScriptEffectModel(BattleScript *script, BattleScriptChildren *children) {
    SVECTOR pos;
    SVECTOR rot;
    s32 mode = *script->pc++;
    s32 id = *script->pc++;
    s32 file;
    s32 i;

    switch (mode) {
    case 0:
    default:
        pos.vx = *script->pc++;
        pos.vy = -*script->pc++;
        pos.vz = -*script->pc++;
        rot.vx = *script->pc++;
        rot.vy = -*script->pc++;
        rot.vz = -*script->pc++;
        for (i = 0; i < 3; i++) {
            if (children->effects[i] == NULL) {
                children->effects[i] = FIGHTSTG_startEffectModel(id, &pos, &rot);
                break;
            }
        }
        break;
    case 1:
        file = FIGHTSTG_getEffectModelFile(id);
        if (file != 0 && FILE_CACHE.isLoading(file)) {
            script->pc -= 3;
            return 0;
        }
        break;
    }
    return 1;
}

/* The battle script's camera command: the time of the fade (0 to cut),
   then the enemy's view, a fighter's or one given in the script */
void FIGHTSTG_runScriptCamera(BattleScript *script, BattleScriptChildren *children) {
    BattleCamera *camera = TASK_REGISTRY.funcs.find(BATTLE_TASK_CAMERA, -1, -1);
    s32 time = *script->pc++;
    /* the match depends on pc, which points at the mode, and on view */
    s16 *pc = script->pc;
    CameraView *view = &FIGHTSTG_fighterView;
    s32 id;

    switch (*script->pc++) {
    case 0:
    default:
        id = *script->pc++;
        switch (id) {
        case 0:
        default:
            camera->getEnemyView(camera);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            camera->getFighterView(camera, 0, id + 7);
            break;
        case 5:
        case 6:
        case 7:
            camera->getFighterView(camera, 0x10, id - 5);
            break;
        }
        break;
    case 1:
        view->vpx = pc[1];
        view->vpy = -pc[2];
        view->vpz = -pc[3];
        view->vrx = pc[4];
        view->vry = -pc[5];
        view->vrz = -pc[6];
        view->tx = pc[7];
        view->ty = -pc[8];
        view->tz = -pc[9];
        view->rot.vx = pc[10];
        view->rot.vy = -pc[11];
        view->rot.vz = -pc[12];
        view->rz = pc[13];
        view->proj = pc[14];
        script->pc = pc + 15;
        break;
    }
    if (time != 0) {
        camera->fade(camera, NULL, view, time);
    } else {
        camera->set(camera, view);
    }
}

/* The battle script's wait command: waits the time in the script, returning 0
   until it is over */
s32 FIGHTSTG_runScriptWait(BattleScript *script, BattleScriptChildren *children) {
    switch (script->waiting) {
    case 0:
    default:
        script->wait = *script->pc;
        script->waiting = 1;
        script->pc--;
        return 0;
    case 1:
        script->wait -= GFX.funcs.getFrameTime();
        script->pc--;
        if (script->wait > 0) {
            return 0;
        }
        script->waiting = 0;
        script->wait = 0;
        script->pc += 2;
        return 1;
    }
}

/* The battle script's stage command (0x38 the script's own stage, -1 none): 0
   changes the fight stage (0 the battle's) with the fade times in the script,
   keeping the partner's idle motion aside on stage 0x1D and bringing it back
   on 0x1E; 1 waits while the stage's motions load. Returning 0 runs the
   command again */
s32 FIGHTSTG_runScriptStage(BattleScript *script, BattleScriptChildren *children) {
    FightStage *stage = TASK_REGISTRY.funcs.find(BATTLE_TASK_STAGE, -1, -1);
    s32 mode = *script->pc++;
    s32 id = *script->pc++;
    s32 fadeOut;
    s32 fadeIn;
    s32 motions;
    ModelControl *control;

    if (id == 0x38) {
        id = script->stage;
    }
    if (id == -1) {
        return 1;
    }
    switch (mode) {
    case 0:
    default:
        fadeOut = *script->pc++;
        fadeIn = *script->pc++;
        if (id == 0) {
            id = BATTLE_SETUP.stage;
        }
        stage->setStage(stage, id, fadeOut, fadeIn);
        switch (id) {
        case 0x1D:
            control = script->models->get(script->models, 0);
            FIGHTSTG_partnerIdleMotion = control->idleMotion;
            control->idleMotion = 0;
            break;
        case 0x1E:
            if (FIGHTSTG_partnerIdleMotion != 0) {
                script->models->get(script->models, 0)->motion = 2;
            }
            break;
        }
        break;
    case 1:
        if (id == 0) {
            return 1;
        }
        motions = FIGHTSTG_getStageMotionsFile(id);
        if (motions != 0 && FILE_CACHE.isLoading(motions)) {
            script->pc -= 3;
            return 0;
        }
        break;
    }
    return 1;
}

/* The battle script's sound command: plays a battle sound for a time (0x62
   and 0x63 the hit's sound, or 0x38 for a hit of result 3) */
void FIGHTSTG_runScriptSound(BattleScript *script, BattleScriptChildren *children) {
    s32 sound = *script->pc++;
    s32 time = *script->pc++;

    if (sound == 0x62) {
        sound = script->hits[script->sounds] == 3 ? 0x38 : script->sound;
        script->sounds++;
    } else if (sound == 0x63) {
        sound = script->hits[3] == 3 ? 0x38 : script->sound;
        script->sounds++;
    }
    if (children->sound == NULL) {
        children->sound = FIGHTSTG_playBattleSound(sound, time);
    }
}

/* The battle script's fade command: 0 fades the screen out over the frames in
   the script, 1 back in */
void FIGHTSTG_runScriptFade(BattleScript *script, WhiteFlash **fade) {
    s32 op = *script->pc++;
    s32 frames = *script->pc++;

    switch (op) {
    case 0:
        *fade = FIGHTSTG_startWhiteFlash(frames);
        break;
    case 1:
        if (*fade != NULL) {
            FIGHTSTG_endWhiteFlash(*fade, frames);
        }
        break;
    }
}

/* The battle script's task: finds the fighter's effect archive and its script
   (loading sound bank 0x46 for script 12), then runs its commands until one
   waits, and ends once its children are done */
void FIGHTSTG_updateBattleScript(BattleScript *script, BattleScriptChildren *children) {
    s32 more;
    s32 busy;
    s32 i;

    switch (script->state) {
    case 0:
    default:
        switch (script->substate) {
        case 0:
        default:
            script->model = script->unk50 != 0 ? 0x10 : 0;
            script->models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            script->fighter = script->models->get(script->models, script->model)->fighter;
            FIGHTSTG_fighterCache.funcs.getInfo(script->fighter);
            script->archive = FIGHTSTG_fighterCache.partnerInfo->effects;
            script->pc = (s16 *)FILE_CACHE.getArchiveEntry(script->index, FILE_CACHE.getEntry(script->archive));
            if (script->index != 12) {
                script->nextState(script);
                break;
            }
            script->nextSubstate(script);
            /* fallthrough */
        case 1:
            switch (script->step) {
            case 0:
            default:
                SOUND.loadBank(0x46);
                script->nextStep(script);
                /* fallthrough */
            case 1:
                if (SOUND.isLoading()) {
                    return;
                }
            }
            script->nextState(script);
            break;
        }
        break;
    case 1:
        do {
            more = 1;
            switch (*script->pc++) {
            case 1:
                FIGHTSTG_runScriptHits(script, children);
                break;
            case 2:
                more = FIGHTSTG_runScriptModel(script, children);
                break;
            case 3:
                more = FIGHTSTG_runScriptEffect(script, children);
                break;
            case 4:
                more = FIGHTSTG_runScriptStage(script, children);
                break;
            case 5:
                FIGHTSTG_runScriptCamera(script, children);
                break;
            case 6:
                more = FIGHTSTG_runScriptEffectModel(script, children);
                break;
            case 7:
                FIGHTSTG_runScriptFade(script, &children->fade);
                break;
            /* the match depends on these cases, which do nothing, and on 2 and 3 */
            case 8:
            case 9:
                break;
            case 10:
                FIGHTSTG_runScriptSound(script, children);
                break;
            case 11:
                more = FIGHTSTG_runScriptWait(script, children);
                break;
            case 0:
            case 0xFF:
                busy = 0;
                if (children->unk4 != NULL) {
                    busy = children->unk4->state < 2;
                }
                if (children->script != NULL) {
                    busy = 1;
                }
                for (i = 0; i < 8; i++) {
                    if (children->unk10[i] != NULL) {
                        busy = 1;
                        break;
                    }
                }
                if (busy) {
                    script->pc--;
                } else {
                    script->setState(script, 3);
                }
                more = 0;
                break;
            }
        } while (more);
        break;
    case 2:
    case 3:
        break;
    }
}

/* Creates a battle script, which plays a technique (FIGHTSTG_updateBattleScript) */
BattleScript *FIGHTSTG_createBattleScript(void) {
    return createTask(FIGHTSTG_updateBattleScript, sizeof(BattleScript), 16 * sizeof(Task *));
}

#if VERSION_EU
/* the European version has the task of FIGHTSTG_updateCameraTurn here */
#include "camera_turn.h"
#endif

/* A side's first technique (FIGHTSTG_startFirstTech): the partner's skills[0] or the
   enemy's battle table unk8[0], its message and WFIGHTMN's WFIGHTMN_startTech,
   then the damage to the other side's active fighter (TECH_EFFECT_KNOCK_OUT knocks it
   out, TECH_EFFECT_END_BATTLE takes 70 percent of the partner's HP), its waking up
   when that fighter is asleep (substate 4) and FIGHTSTG_startEnemyAttack when the partner
   misses in BATTLE_KIND_FINAL_LAST. The match depends on the other side's fighter being found
   as its row's offset, other * 0x60, added as an int to its slot in the
   first row, each in a variable of its own in a block of its own (as an
   index, gcc folds the row into (other * 3 + active) * 32); on the blocks
   of their own of substate 0's row and of the event that substate 4 finds;
   on the MP test being written tech->mp > fighter->mp; on TECH_EFFECT_END_BATTLE's
   damage being stored before lines[0] and on the pointer sum of its HP. */
void FIGHTSTG_updateFirstTech(FirstTech *task, BattleChild *children) {
    BattleFighter *fighter;
    BattleFighter *struck;
    BattleFighter *countered;
    TechData *tech;
    s32 index;

    switch (task->state) {
    case TASK_INIT:
    default:
        if (task->side == 0) {
            task->tech = GET_DIGIMON(FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]].id)->skills[0];
        } else {
            task->tech = FIGHTSTG_battleTableFunc(FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]].id)->unk8[0];
        }
        fighter = (FIGHTSTG_battle.fighters[1] + FIGHTSTG_battle.active[1]);
        tech = &TECHS[task->tech - 1];
        if (task->side != 0 && tech->mp > fighter->mp) {
            children[0].message = FIGHTSTG_createMessage();
            task->lines[0] = 0x8D;
            task->lines[1] = task->side;
            children[0].message->show(children[0].message, 2, task->lines);
            task->substate = 2;
        } else {
            children[0].message = FIGHTSTG_createMessage();
            task->lines[0] = 8;
            task->lines[1] = task->side;
            children[0].message->show(children[0].message, 2, task->lines);
            FIGHTSTG_action.start(task->side, task->tech);
        }
        {
            s32 other = 1 - (task->side >> 4);
            s32 row = other * 0x60;
            BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

            fighter = (BattleFighter *)(row + (s32)slot);
        }
        if (fighter->flags & FIGHTER_ASLEEP) {
            task->asleep = 1;
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (children[0].task == NULL) {
                children[0].script = WFIGHTMN_startTech(task->side, task->tech);
                {
                    BattleFighter *fighters = FIGHTSTG_battle.fighters[0];

                    if (task->side != 0) {
                        fighters = FIGHTSTG_battle.fighters[1];
                    }
                    fighters[FIGHTSTG_battle.active[task->side != 0]].charge = 0;
                }
                task->substate++;
            }
            break;
        case 1:
            if (children[0].task == NULL) {
                children[0].message = FIGHTSTG_createMessage();
                if (FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT]) {
                    task->lines[0] = 0x10 - task->side;
                    task->lines[1] = FIGHTSTG_action.damage;
                    task->lines[2] = FIGHTSTG_action.hitsLanded;
                    children[0].message->show(children[0].message, 0x10, task->lines);
                    task->damage = FIGHTSTG_action.hitsLanded * FIGHTSTG_action.damage;
#if VERSION_EU
                    if (task->damage >= 10000) {
                        task->damage = 9999;
                    }
#endif
                } else if (FIGHTSTG_action.effects[TECH_EFFECT_KNOCK_OUT]) {
                    s32 other = task->side == 0;
                    s32 row = other * 0x60;
                    BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

                    ((BattleFighter *)(row + (s32)slot))->hp = 0;
                    FIGHTSTG_queueKnockOut(other << 4);
                    children[0].task->state = 3;
                } else if (FIGHTSTG_action.effects[TECH_EFFECT_END_BATTLE]) {
                    task->damage = (FIGHTSTG_battle.fighters[0] + FIGHTSTG_battle.active[0])->hp * 7 / 10;
                    task->lines[0] = 0;
                    task->lines[1] = task->damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                } else if (FIGHTSTG_action.hits[0]) {
                    task->lines[0] = (task->side == 0) << 4;
                    task->lines[1] = FIGHTSTG_action.damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                    task->damage = FIGHTSTG_action.damage;
                } else {
                    task->lines[0] = 0x1D;
                    task->lines[1] = (task->side == 0) << 4;
                    children[0].message->show(children[0].message, 2, task->lines);
                }
                if (task->damage != 0) {
                    s32 other = task->side == 0;
                    s32 row = other * 0x60;
                    BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

                    struck = (BattleFighter *)(row + (s32)slot);
                    struck->hp -= task->damage;
                    if (struck->hp <= 0) {
                        struck->hp = 0;
                        FIGHTSTG_queueKnockOut((task->side == 0) << 4);
                        task->step = 1;
                    }
                }
                task->substate++;
            }
            break;
        case 2:
            if (children[0].task == NULL) {
                if (FIGHTSTG_action.effects[TECH_EFFECT_END_BATTLE]) {
                    children[0].events = FIGHTSTG_startActionEvents(task->side);
                    task->nextSubstate(task);
                } else if (task->step != 0) {
                    task->state = 3;
                } else if (task->damage == 0) {
                    if (task->side != 0 || FIGHTSTG_battle.kind != BATTLE_KIND_FINAL_LAST) {
                        task->state = 3;
                    } else {
                        task->setSubstate(task, 6);
                    }
                } else {
                    children[0].events = FIGHTSTG_startActionEvents(task->side);
                    task->nextSubstate(task);
                }
            }
            break;
        case 3:
            if (children[0].task == NULL) {
                task->nextSubstate(task);
            }
            break;
        case 4:
            index = task->side == 0;
            countered = (FIGHTSTG_battle.fighters[index] + FIGHTSTG_battle.active[index]);
            if (countered->flags & FIGHTER_ASLEEP) {
                if (task->asleep != 0 && FIGHTSTG_battleFuncs.testWakeUp((u8)(0x10 - task->side), task->damage) != 0) {
                    task->lines[0] = 0x2B;
                    task->lines[1] = 0x10 - task->side;
                    task->lines[2] = FIGHTSTG_battle.active[index];
                    children[0].message = FIGHTSTG_createMessage();
                    children[0].message->show(children[0].message, 7, task->lines);
                    countered->flags &= ~FIGHTER_ASLEEP;
                    {
                        s32 event = FIGHTSTG_events.funcs.find(0xC, 0x10 - task->side, FIGHTSTG_battle.active[index]);

                        if (event >= 0) {
                            FIGHTSTG_events.events[event].type = 0;
                        }
                    }
                    task->substate = 8;
                } else {
                    task->state = 3;
                }
            } else {
                children[0].counter = FIGHTSTG_startCounterattack(index << 4, task->damage, 0);
                task->substate++;
            }
            break;
        case 5:
            if (children[0].task != NULL) {
                if (children[0].task->state != 2) {
                    break;
                }
                WFIGHTMN_chargeGauge(task->side, task->damage);
            }
            task->state = 3;
            break;
        case 6:
            if (children[0].task == NULL) {
                children[0].enemyAttack = FIGHTSTG_startEnemyAttack(1, 0);
                task->nextSubstate(task);
            }
            break;
        case 7:
            if (children[0].task == NULL) {
                task->setState(task, 3);
            }
            break;
        case 8:
            if (children[0].task == NULL) {
                children[0].counter = FIGHTSTG_startCounterattack((task->side == 0) << 4, task->damage, 0);
                task->substate = 5;
            }
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts side's first technique (FIGHTSTG_updateFirstTech) */
FirstTech *FIGHTSTG_startFirstTech(s32 side) {
    FirstTech *task = createTask(FIGHTSTG_updateFirstTech, sizeof(FirstTech), sizeof(Task *));

    task->side = side;
    return task;
}
