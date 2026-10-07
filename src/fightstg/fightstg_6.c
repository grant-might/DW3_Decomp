/* The sixth object of FIGHTSTG.PRO (see fightstg.c): its rodata starts at
   0x8008267C (USA), 4 bytes past a multiple of 8. */

#include "fightstg.h"
#include "gte.h"

/* An item's script (FIGHTSTG_updateItem): step 0 sets it up and deals the damage,
   1 plays item 0x55's second part when the enemy is still standing, 2 waits.
   The match depends on item 0x55's damage being 20 percent, on the row
   pointer of item 0x5A, on the stage being written out in each case and on
   the table being walked by index. */
s32 FIGHTSTG_runItemScript(BattleItem *task, BattleScript **children) {
    BattleFighter *fighter;
    BattleFighter *enemy;
    BattleFighter *row;
    BattleStats *stats;
    TechData *tech;
    s32 atk;
    s32 def;
    s32 min;
    s32 i;

    switch (task->step) {
    case 0:
    default:
        children[0] = FIGHTSTG_createBattleScript();
        children[0]->unk50 = 0;
        switch (task->item) {
        case 0x4D:
        case 0x4E:
        case 0x4F:
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
            children[0]->index = 0xF;
            children[0]->stage = (task->item - 0x4D) * 3 + 0x22;
            children[0]->unk6C = 2;
            children[0]->sound = 0x39;
            break;
        case 0x54:
            task->element = RANDOM.next() % ELEMENT_COUNT + ELEMENT_FIRST;
            children[0]->index = 0xF;
            children[0]->stage = (task->element - ELEMENT_FIRST) * 3 + 0x22;
            children[0]->unk6C = 2;
            children[0]->sound = 0x39;
            break;
        case 0x56:
            children[0]->index = 0x11;
            children[0]->stage = -1;
            children[0]->unk6C = 0x15;
            children[0]->sound = 0x1B;
            break;
        case 0x57:
            children[0]->index = 0x11;
            children[0]->stage = -1;
            children[0]->unk6C = 0x27;
            children[0]->sound = 0x31;
            break;
        case 0x59:
            children[0]->index = 0x11;
            children[0]->stage = -1;
            children[0]->unk6C = 0x29;
            children[0]->sound = 0x31;
            break;
        case 0x58:
            fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
            stats = FIGHTSTG_battleFuncs.computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
            if (stats->stats[BATTLE_STAT_ATTACK] > stats->stats[BATTLE_STAT_DEFENSE]) {
                if (BATTLE_SETUP.unk3E[8] == 0) {
                    task->lowered = 1;
                    atk = stats->stats[BATTLE_STAT_ATTACK];
                    def = stats->stats[BATTLE_STAT_DEFENSE];
                    if (fighter->boosts[0] != 0) {
                        stats->stats[BATTLE_STAT_ATTACK] -= fighter->boosts[0];
                    }
                    min = -(stats->stats[BATTLE_STAT_ATTACK] / 2);
                    fighter->boosts[0] -= atk - def;
                    if (fighter->boosts[0] < min) {
                        fighter->boosts[0] = min;
                    }
                }
            } else if (stats->stats[BATTLE_STAT_ATTACK] < stats->stats[BATTLE_STAT_DEFENSE]) {
                if (BATTLE_SETUP.unk3E[9] == 0) {
                    task->lowered = 2;
                    atk = stats->stats[BATTLE_STAT_ATTACK];
                    def = stats->stats[BATTLE_STAT_DEFENSE];
                    if (fighter->boosts[1] != 0) {
                        stats->stats[BATTLE_STAT_DEFENSE] -= fighter->boosts[1];
                    }
                    min = -(stats->stats[BATTLE_STAT_DEFENSE] / 2);
#if VERSION_EU
                    fighter->boosts[1] -= def - atk;
#else
                    fighter->boosts[1] -= atk - def; /* raises it */
#endif
                    if (fighter->boosts[1] < min) {
                        fighter->boosts[1] = min;
                    }
                }
            }
            children[0]->index = 0x11;
            children[0]->stage = -1;
            if (task->lowered == 1) {
                children[0]->unk6C = 0x25;
                children[0]->sound = 0x31;
            } else if (task->lowered == 2) {
                children[0]->unk6C = 0x27;
                children[0]->sound = 0x31;
            } else {
                children[0]->unk6C = 0x2E;
                children[0]->sound = 0x1E;
            }
            break;
        case 0x55:
            children[0]->index = 0xE;
            children[0]->stage = -1;
            children[0]->unk6C = 0x1C;
            children[0]->sound = 0x27;
            if (BATTLE_SETUP.unk3E[5] == 0) {
                enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                task->damage = enemy->maxHp * 20 / 100;
                if (enemy->hp - task->damage <= 0) {
                    children[0]->hits[3] = 2;
                    task->counter = 1;
                } else {
                    children[0]->hits[3] = 1;
                    WFIGHTMN_setIdleMotion(0x10, task->damage);
                    WFIGHTMN_setIdleMotion(0, -task->damage);
                }
            } else {
                children[0]->hits[3] = 3;
            }
            break;
        case 0x5A:
            children[0]->index = 0xE;
            tech = &TECHS[0x88];
            children[0]->stage = tech->unkD;
            children[0]->unk6C = tech->unkE;
            children[0]->sound = tech->unkF;
            task->damage = WFIGHTMN_limitDamage(0, FIGHTSTG_battleFuncs.computeMagicDamage(0, 0x89), 0);
            row = FIGHTSTG_battle.fighters[1];
            if (task->damage > 0) {
                if (row[FIGHTSTG_battle.active[1]].hp - task->damage <= 0) {
                    children[0]->hits[3] = 2;
                } else {
                    children[0]->hits[3] = 1;
                    WFIGHTMN_setIdleMotion(0x10, task->damage);
                }
            } else {
                children[0]->hits[3] = 3;
            }
            break;
        default:
            children[0]->index = 0xA;
            children[0]->stage = -1;
            for (i = 0; FIGHTSTG_itemScripts[i].item != -1; i++) {
                if (FIGHTSTG_itemScripts[i].item == task->item) {
                    children[0]->unk6C = FIGHTSTG_itemScripts[i].unk6C;
                    children[0]->sound = FIGHTSTG_itemScripts[i].sound;
                    break;
                }
            }
            if (task->item >= 0x2B && task->item < 0x2F) {
                WFIGHTMN_setIdleMotion(0, -*(u16 *)&GET_ITEM[0](task->item)->data[2]);
            } else if (task->item == 0x47) {
                WFIGHTMN_setIdleMotion(0, -((FIGHTSTG_battle.fighters[0] + FIGHTSTG_battle.active[0])->maxHp >> 1));
            }
            break;
        }
        task->step++;
        if (FIGHTSTG_battle.kind == BATTLE_KIND_FINAL_LAST) {
            if (task->item == 0x5A) {
                WFIGHTMN_countHit(0, task->damage);
            } else {
                WFIGHTMN_endWeakness(0);
            }
        }
        break;
    case 1:
        if (children[0] == NULL) {
            if (task->item != 0x55 || task->counter != 0 || BATTLE_SETUP.unk3E[5] != 0) {
                return 1;
            }
            children[0] = FIGHTSTG_createBattleScript();
            children[0]->unk50 = 0;
            children[0]->index = 0xA;
            children[0]->unk6C = 0x21;
            children[0]->sound = 0x1F;
            task->step++;
        }
        break;
    case 2:
        if (children[0] == NULL) {
            return 1;
        }
        break;
    }
    return 0;
}

/* what items 0x42-0x45 cure (FIGHTSTG_updateItem, below) */
StatusCure FIGHTSTG_itemCures[4] = {
    { 0x28, 0x01, 190 },
    { 0x29, 0x02, 192 },
    { 0x2A, 0x04, 194 },
    { 0x2C, 0x3F, 196 },
};
/* the items' script settings (FIGHTSTG_runItemScript, above) */
ItemScript FIGHTSTG_itemScripts[] = {
    { 0x2B, 0x21, 0x1F },
    { 0x2C, 0x21, 0x1F },
    { 0x2D, 0x21, 0x1F },
    { 0x2E, 0x21, 0x1F },
    { 0x42, 0x22, 0x1F },
    { 0x43, 0x22, 0x1F },
    { 0x44, 0x22, 0x1F },
    { 0x45, 0x22, 0x1F },
    { 0x46, 0x23, 0x1F },
    { 0x47, 0x21, 0x1F },
    { 0x48, 0x28, 0x1F },
    { 0x49, 0x24, 0x1F },
    { 0x4A, 0x26, 0x1F },
    { 0x4B, 0x2E, 0x1E },
    { 0x4C, 0x2E, 0x1E },
    { -1, 0, 0 },
};

/* An item used in battle (FIGHTSTG_startItem): its message, FIGHTSTG_runItemScript's
   script, then substate 1 does what the item does and 2 takes it from the
   bag (item 0x55 attacks again in BATTLE_KIND_FINAL_LAST). The match depends on each
   case's variables being its own, on item 0x47's halves being declared in
   its `if`, on its MP test being written `maxMp <= mp + halfMp`, on item
   0x57's cap being read after the boosts change, on the pointer sum of item
   0x4B and on the cases that say the item does nothing ending on their own
   (item 0x2B's, 0x57's and 0x59's). */
void FIGHTSTG_updateItem(BattleItem *task, BattleChild *children) {
    s8 unused[0x90]; /* unused, but it is in the original stack frame */

    switch (task->state) {
    case TASK_INIT:
    default:
        switch (task->substate) {
        case 0:
        default:
            children[0].message = FIGHTSTG_createMessage();
            task->lines[0] = 0;
            task->lines[1] = task->item;
            children[0].message->show(children[0].message, 0xE, task->lines);
            task->substate++;
            break;
        case 1:
            if (children[0].task == NULL && FIGHTSTG_runItemScript(task, (BattleScript **)children)) {
                task->nextState(task);
            }
            break;
        }
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (children[0].task == NULL) {
                task->substate++;
            }
            break;
        case 1:
            switch (task->item) {
            case 0x2B ... 0x41:
            default: {
                BattleFighter *fighter;
                u8 *data;
                s32 heal;

                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                data = GET_ITEM[0](task->item)->data;
                if (fighter->maxHp == fighter->hp) {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x2F;
                    children[0].message->show(children[0].message, 1, task->lines);
                    task->nextSubstate(task);
                    break;
                }
                if (fighter->hp + *(u16 *)&data[2] <= fighter->maxHp) {
                    heal = *(u16 *)&data[2];
                    fighter->hp += heal;
                } else {
                    heal = fighter->maxHp - fighter->hp;
                    fighter->hp = fighter->maxHp;
                }
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0;
                task->lines[1] = heal;
                children[0].message->show(children[0].message, 8, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x42 ... 0x45: {
                BattleFighter *fighter;
                StatusCure *cure;

                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                switch (task->item) {
                case 0x42:
                default:
                    cure = &FIGHTSTG_itemCures[0];
                    break;
                case 0x43:
                    cure = &FIGHTSTG_itemCures[1];
                    break;
                case 0x44:
                    cure = &FIGHTSTG_itemCures[2];
                    break;
                case 0x45:
                    cure = &FIGHTSTG_itemCures[3];
                    break;
                }
                children[0].message = FIGHTSTG_createMessage();
                if (fighter->flags & cure->flag) {
                    fighter->flags &= ~cure->flag;
                    FIGHTSTG_events.funcs.useItem(0, FIGHTSTG_battle.active[0], cure->item);
                    task->lines[0] = cure->message;
                    task->lines[1] = 0;
                    children[0].message->show(children[0].message, 2, task->lines);
                } else {
                    task->lines[0] = 0x2F;
                    children[0].message->show(children[0].message, 1, task->lines);
                }
                task->nextSubstate(task);
                break;
            }
            case 0x46: {
                s32 i;

                switch (task->step) {
                case 0:
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0;
                    task->lines[1] = 5;
                    children[0].message->show(children[0].message, 9, task->lines);
                    task->nextStep(task);
                    break;
                case 1:
                    if (children[0].task == NULL) {
                        for (i = 0; i < 3; i++) {
                            if (FIGHTSTG_battle.fighters[0][i].hp == 0) {
                                FIGHTSTG_battle.fighters[0][i].hp = FIGHTSTG_battle.fighters[0][i].maxHp;
                                WFIGHTMN_checkEquip(i);
                            }
                        }
                        task->nextStep(task);
                    }
                    break;
                case 2:
                    if (children[0].task == NULL) {
                        GAME.items[task->item]--;
                        task->state = TASK_KILL;
                    }
                    break;
                }
                break;
            }
            case 0x47: {
                BattleFighter *fighter;

                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                children[0].message = FIGHTSTG_createMessage();
                if (fighter->hp != fighter->maxHp || fighter->mp != fighter->maxMp) {
                    s32 half;
                    s32 halfMp;

                    half = fighter->maxHp / 2;
                    halfMp = fighter->maxMp / 2;
                    if (fighter->hp + half >= fighter->maxHp) {
                        fighter->hp = fighter->maxHp;
                    } else {
                        fighter->hp += half;
                    }
                    if (fighter->maxMp <= fighter->mp + halfMp) {
                        fighter->mp = fighter->maxMp;
                    } else {
                        fighter->mp += halfMp;
                    }
                    task->lines[0] = 0x3B;
                    task->lines[1] = 0;
                    children[0].message->show(children[0].message, 2, task->lines);
                } else {
                    task->lines[0] = 0x2F;
                    children[0].message->show(children[0].message, 1, task->lines);
                }
                task->nextSubstate(task);
                break;
            }
            case 0x48: {
                BattleFighter *fighter;
                BattleStats *stats;
                u8 *data;
                s32 max;

                data = GET_ITEM[0](task->item)->data;
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                stats = FIGHTSTG_battleFuncs.computeStats(0, 1, FIGHTSTG_battle.active[0]);
                if (fighter->boosts[2] != 0) {
                    stats->stats[BATTLE_STAT_SPEED] -= fighter->boosts[2];
                }
                max = stats->stats[BATTLE_STAT_SPEED];
                fighter->boosts[2] += max * *(u16 *)&data[2] / 128;
                if (fighter->boosts[2] > max) {
                    fighter->boosts[2] = max;
                }
                FIGHTSTG_queueBoostEnd(0, FIGHTSTG_battle.active[0], 2, 0);
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x32;
                task->lines[1] = 0;
                task->lines[2] = FIGHTSTG_battle.active[0];
                children[0].message->show(children[0].message, 7, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x49: {
                BattleFighter *fighter;
                BattleStats *stats;
                u8 *data;
                s32 max;
                s32 min;

                data = GET_ITEM[0](task->item)->data;
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                stats = FIGHTSTG_battleFuncs.computeStats(0, 1, FIGHTSTG_battle.active[0]);
                if (fighter->boosts[0] != 0) {
                    stats->stats[BATTLE_STAT_ATTACK] -= fighter->boosts[0];
                }
                if (fighter->boosts[1] != 0) {
                    stats->stats[BATTLE_STAT_DEFENSE] -= fighter->boosts[1];
                }
                max = stats->stats[BATTLE_STAT_ATTACK];
                fighter->boosts[0] += max * *(u16 *)&data[2] / 128;
                if (fighter->boosts[0] > max) {
                    fighter->boosts[0] = max;
                }
                min = -(stats->stats[BATTLE_STAT_DEFENSE] / 2);
                fighter->boosts[1] -= stats->stats[BATTLE_STAT_DEFENSE] * *(u16 *)&data[2] / 512;
                if (fighter->boosts[1] < min) {
                    fighter->boosts[1] = min;
                }
                FIGHTSTG_queueBoostEnd(0, FIGHTSTG_battle.active[0], 0, 0);
                FIGHTSTG_queueBoostEnd(0, FIGHTSTG_battle.active[0], 1, 0);
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x3C;
                task->lines[1] = 0;
                children[0].message->show(children[0].message, 2, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x4A: {
                BattleFighter *fighter;
                BattleStats *stats;
                u8 *data;
                s32 max;
                s32 min;

                data = GET_ITEM[0](task->item)->data;
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                stats = FIGHTSTG_battleFuncs.computeStats(0, 1, FIGHTSTG_battle.active[0]);
                if (fighter->boosts[0] != 0) {
                    stats->stats[BATTLE_STAT_ATTACK] -= fighter->boosts[0];
                }
                if (fighter->boosts[1] != 0) {
                    stats->stats[BATTLE_STAT_DEFENSE] -= fighter->boosts[1];
                }
                max = stats->stats[BATTLE_STAT_DEFENSE];
                fighter->boosts[1] += max * *(u16 *)&data[2] / 128;
                if (fighter->boosts[1] > max) {
                    fighter->boosts[1] = max;
                }
                min = -(stats->stats[BATTLE_STAT_ATTACK] / 2);
                fighter->boosts[0] -= stats->stats[BATTLE_STAT_ATTACK] * *(u16 *)&data[2] / 512;
                if (fighter->boosts[0] < min) {
                    fighter->boosts[0] = min;
                }
                FIGHTSTG_queueBoostEnd(0, FIGHTSTG_battle.active[0], 0, 0);
                FIGHTSTG_queueBoostEnd(0, FIGHTSTG_battle.active[0], 1, 0);
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x3D;
                task->lines[1] = 0;
                children[0].message->show(children[0].message, 2, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x4B: {
                (FIGHTSTG_battle.fighters[0] + FIGHTSTG_battle.active[0])->special = 1;
    #if VERSION_US
                FIGHTSTG_queueSpecialEnd();
    #endif
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x3E;
                task->lines[1] = 0;
                children[0].message->show(children[0].message, 2, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x4C: {
                u8 *data;
                s32 i;

                data = GET_ITEM[0](task->item)->data;
                i = GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]);
                BATTLE_SETUP.gauges[i] += *(u16 *)&data[2];
                if (BATTLE_SETUP.gauges[i] >= 999) {
                    BATTLE_SETUP.gauges[i] = 999;
                }
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x3F;
                task->lines[1] = 0;
                children[0].message->show(children[0].message, 2, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x4D ... 0x53: {
                FIGHTSTG_queueClearField(FIGHTSTG_events.funcs.getDelay(0, 8));
                FIGHTSTG_battle.boostElement = task->item - 0x4B;
                FIGHTSTG_battle.boostAmount = 0x40;
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = task->item + 0x16;
                children[0].message->show(children[0].message, 1, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x54: {
                FIGHTSTG_queueClearField(FIGHTSTG_events.funcs.getDelay(0, 8));
                FIGHTSTG_battle.boostElement = task->element;
                FIGHTSTG_battle.boostAmount = 0x7F;
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = task->element + 0x61;
                children[0].message->show(children[0].message, 1, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x55: {
                BattleFighter *fighter;

                if (BATTLE_SETUP.unk3E[5] == 0) {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x10;
                    task->lines[1] = task->damage;
                    fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    if (fighter->hp - task->damage <= 0) {
                        children[0].message->show(children[0].message, 4, task->lines);
                        fighter->hp = 0;
                        FIGHTSTG_queueKnockOut(0x10);
                    } else {
                        children[0].message->show(children[0].message, 0x14, task->lines);
                        fighter->hp -= task->damage;
                        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                        fighter->hp += task->damage;
                        if (fighter->hp > fighter->maxHp) {
                            fighter->hp = fighter->maxHp;
                        }
                    }
                } else {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x2F;
                    children[0].message->show(children[0].message, 1, task->lines);
                }
                task->nextSubstate(task);
                break;
            }
            case 0x56: {
                BattleFighter *fighter;
                BattleFighter *enemy;
                u8 *data;

                data = GET_ITEM[0](task->item)->data;
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                switch (task->step) {
                case 0:
                default:
                    if ((RANDOM.next() & 1) && BATTLE_SETUP.unk3E[2] == 0) {
                        FIGHTSTG_inflictConfusion(0x10, 0, data[2]);
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x20;
                        task->lines[1] = 0x10;
                        children[0].message->show(children[0].message, 2, task->lines);
                        if ((RANDOM.next() & 3) == 0) {
                            task->nextStep(task);
                        } else {
                            task->nextSubstate(task);
                        }
                        enemy->flags |= FIGHTER_CONFUSED;
                    } else {
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x2F;
                        children[0].message->show(children[0].message, 1, task->lines);
                        task->nextSubstate(task);
                    }
                    break;
                case 1:
                    if (children[0].task == NULL) {
                        fighter->flags |= FIGHTER_CONFUSED;
                        FIGHTSTG_inflictConfusion(0, 0, data[2]);
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = 0x20;
                        task->lines[1] = 0;
                        children[0].message->show(children[0].message, 2, task->lines);
                        task->nextSubstate(task);
                    }
                    break;
                }
                break;
            }
            case 0x57: {
                BattleFighter *enemy;
                BattleStats *stats;
                s32 max;
                s32 atk;
                s32 def;

                if (BATTLE_SETUP.unk3E[9] == 0) {
                    enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    stats = FIGHTSTG_battleFuncs.computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
                    atk = stats->stats[BATTLE_STAT_ATTACK];
                    def = stats->stats[BATTLE_STAT_DEFENSE];
                    if (enemy->boosts[0] != 0) {
                        stats->stats[BATTLE_STAT_ATTACK] -= enemy->boosts[0];
                    }
                    if (enemy->boosts[1] != 0) {
                        stats->stats[BATTLE_STAT_DEFENSE] -= enemy->boosts[1];
                    }
                    enemy->boosts[0] += atk * 3 / 10;
                    enemy->boosts[1] -= def / 2;
                    max = stats->stats[BATTLE_STAT_ATTACK];
                    if (enemy->boosts[0] > max) {
                        enemy->boosts[0] = max;
                    }
                    if (enemy->boosts[1] < -stats->stats[BATTLE_STAT_DEFENSE] / 2) {
                        enemy->boosts[1] = -stats->stats[BATTLE_STAT_DEFENSE] / 2;
                    }
                    FIGHTSTG_queueBoostEnd(0x10, FIGHTSTG_battle.active[1], 0, 0);
                    FIGHTSTG_queueBoostEnd(0x10, FIGHTSTG_battle.active[1], 1, 0);
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x40;
                    task->lines[1] = 0x10;
                    children[0].message->show(children[0].message, 2, task->lines);
                    task->nextSubstate(task);
                    break;
                }
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x2F;
                children[0].message->show(children[0].message, 1, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x58: {
                switch (task->lowered) {
                case 1:
                    FIGHTSTG_queueBoostEnd(0x10, FIGHTSTG_battle.active[1], 0, 0);
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x33;
                    task->lines[1] = 0x10;
                    task->lines[2] = FIGHTSTG_battle.active[1];
                    children[0].message->show(children[0].message, 2, task->lines);
                    break;
                case 2:
                    FIGHTSTG_queueBoostEnd(0x10, FIGHTSTG_battle.active[1], 1, 0);
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x34;
                    task->lines[1] = 0x10;
                    task->lines[2] = FIGHTSTG_battle.active[1];
                    children[0].message->show(children[0].message, 2, task->lines);
                    break;
                default:
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x2F;
                    children[0].message->show(children[0].message, 1, task->lines);
                    break;
                }
                task->nextSubstate(task);
                break;
            }
            case 0x59: {
                BattleFighter *enemy;
                BattleStats *stats;
                u8 *data;
                s32 min;

                if (BATTLE_SETUP.unk3E[10] == 0) {
                    data = GET_ITEM[0](task->item)->data;
                    enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    stats = FIGHTSTG_battleFuncs.computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
                    if (enemy->boosts[2] != 0) {
                        stats->stats[BATTLE_STAT_SPEED] -= enemy->boosts[2];
                    }
                    min = -(stats->stats[BATTLE_STAT_SPEED] / 2);
                    enemy->boosts[2] -= stats->stats[BATTLE_STAT_SPEED] * *(u16 *)&data[2] / 128;
                    if (enemy->boosts[2] < min) {
                        enemy->boosts[2] = min;
                    }
                    FIGHTSTG_queueBoostEnd(0x10, FIGHTSTG_battle.active[1], 2, 0);
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x35;
                    task->lines[1] = 0x10;
                    task->lines[2] = FIGHTSTG_battle.active[1];
                    children[0].message->show(children[0].message, 2, task->lines);
                    task->nextSubstate(task);
                    break;
                }
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x2F;
                children[0].message->show(children[0].message, 1, task->lines);
                task->nextSubstate(task);
                break;
            }
            case 0x5A: {
                BattleFighter *enemy;

                if (task->damage > 0) {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x10;
                    task->lines[1] = task->damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                    enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    if (enemy->hp - task->damage <= 0) {
                        enemy->hp = 0;
                        FIGHTSTG_queueKnockOut(0x10);
                    } else {
                        enemy->hp -= task->damage;
                    }
                } else {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x1D;
                    task->lines[1] = 0x10;
                    children[0].message->show(children[0].message, 2, task->lines);
                }
                task->nextSubstate(task);
                break;
            }
            }
            break;
        case 2:
            if (children[0].task == NULL) {
                GAME.items[task->item]--;
                if (task->item == 0x55 && FIGHTSTG_battle.kind == BATTLE_KIND_FINAL_LAST) {
                    children[0].enemyAttack = FIGHTSTG_startEnemyAttack(1, 0);
                    task->nextSubstate(task);
                } else {
                    task->state = TASK_KILL;
                }
            }
            break;
        case 3:
            if (children[0].task == NULL) {
                task->setState(task, TASK_KILL);
            }
            break;
        }
        break;
    case 2:
    case TASK_KILL:
        break;
    }
}


/* Starts an item's script (FIGHTSTG_updateItem) */
BattleItem *FIGHTSTG_startItem(s32 item) {
    BattleItem *task = createTask(FIGHTSTG_updateItem, sizeof(BattleItem), sizeof(Task *));

    task->item = item;
    return task;
}

/* A counterattack (FIGHTSTG_startCounterattack): the player's from an event of type 8 or
   the partner's first technique, the enemy's from its table entry; substate
   0 plays the technique, 1 shows the damage and takes the HP, 2 hands
   received to WFIGHTMN_chargeGauge. The match depends on substate 0's technique and
   side being declared in its `if`, on the event index and the stats being
   variables of their own, on the stage being written element * 3 + 0x21 and
   one more, on the enemy's fighter being found as a pointer sum and on one
   row variable for both of substate 0's rows. */
void FIGHTSTG_updateCounterattack(Counterattack *task, BattleChild *children) {
    BattleFighter *fighter;
    BattleFighter *row;
    BattleTableEntry *entry;
    s32 other;
    s32 element;

    switch (task->state) {
    case TASK_INIT:
    default:
        if (task->received == 0) {
            task->state = TASK_DONE;
            break;
        }
        other = task->side != 0;
        fighter = &FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]];
        if ((fighter->flags & FIGHTER_PARALYZED) && FIGHTSTG_battleFuncs.testParalysis(task->side) != 0) {
            task->state = TASK_DONE;
            break;
        }
        if (task->side == 0) {
            s32 index = FIGHTSTG_events.funcs.find(EVENT_PARTNER_TECH, 0, FIGHTSTG_battle.active[0]);

            if (index >= 0) {
                task->tech = FIGHTSTG_events.events[index].args[2];
                task->substate = 0;
                FIGHTSTG_events.events[index].type = 0;
#if VERSION_US
            } else if (FIGHTSTG_battleFuncs.computeStats(0, 1, FIGHTSTG_battle.active[0])->counter != 0) {
#elif VERSION_EU
            } else if (FIGHTSTG_battleFuncs.computeStats(0, 1, FIGHTSTG_battle.active[0])->counter != 0
                       && FIGHTSTG_battleFuncs.rollCounter(0, task->received) != 0) {
#endif
                task->tech = GET_DIGIMON(fighter->id)->skills[0];
                task->substate = 1;
            } else {
                task->state = TASK_DONE;
                break;
            }
        } else {
            entry = FIGHTSTG_battleTableFunc(fighter->id);
            if (entry->counter.condition == 0) {
                task->state = TASK_DONE;
                break;
            }
            if (FIGHTSTG_testEnemyCondition(entry->counter.condition, entry->counter.conditionArg) == 0) {
                task->state = TASK_DONE;
                break;
            }
            task->tech = FIGHTSTG_getEnemyAction(entry->counter.target);
            if (task->tech == 1) {
                task->tech = FIGHTSTG_battleTableFunc((FIGHTSTG_battle.fighters[1] + FIGHTSTG_battle.active[1])->id)->unk8[0];
                task->substate = 1;
            }
        }
        children[0].message = FIGHTSTG_createMessage();
        task->lines[0] = task->side;
        task->lines[1] = task->tech;
        children[0].message->show(children[0].message, task->substate + 5, task->lines);
        task->hit = FIGHTSTG_battleFuncs.rollHit(task->side, task->tech);
        if (task->hit != 0) {
            task->damage = FIGHTSTG_battleFuncs.computeCounterDamage(task->side, task->tech, task->received);
            if (FIGHTSTG_battle.kind != BATTLE_KIND_NORMAL) {
                task->damage = WFIGHTMN_limitDamage(task->side, task->damage, 0);
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (children[0].message == NULL) {
                TechData *tech = &TECHS[task->tech - 1];
                s32 other = task->side != 0;
                children[0].script = FIGHTSTG_createBattleScript();
                children[0].script->unk50 = task->side;
                if (task->side == 0 && tech->unk10 == 5) {
                    children[0].script->index = 6;
                } else {
                    children[0].script->index = tech->unk10;
                }
                if (tech->unkF != 0) {
                    children[0].script->sound = tech->unkF;
                }
                {
                    BattleStats *stats = FIGHTSTG_battleFuncs.computeStats(task->side, 1, FIGHTSTG_battle.active[other]);

                    if (tech->element >= ELEMENT_FIRST || stats->element >= ELEMENT_FIRST) {
                        if (tech->element >= ELEMENT_FIRST) {
                            element = tech->element - ELEMENT_FIRST;
                        } else {
                            element = stats->element - ELEMENT_FIRST;
                        }
                        element = element * 3 + 0x21;
                        if (stats->elementPower >= 0x40) {
                            children[0].script->stage = element + 1;
                        } else {
                            children[0].script->stage = element;
                        }
                    } else {
                        children[0].script->stage = -1;
                    }
                }
                if (tech->unkE != 0) {
                    children[0].script->unk6C = tech->unkE;
                } else if (tech->unk10 == 5) {
                    children[0].script->unk6C = 0x2E;
                    children[0].script->sound = 0x1E;
                }
                row = FIGHTSTG_battle.fighters[1 - other];
                if (task->hit != 0) {
                    if (row[FIGHTSTG_battle.active[1 - other]].hp - task->damage <= 0) {
                        children[0].script->hits[3] = 2;
                    } else {
                        children[0].script->hits[3] = 1;
                        WFIGHTMN_countHit(task->side, task->damage);
                        WFIGHTMN_setIdleMotion(0x10 - task->side, task->damage);
                    }
                } else {
                    children[0].script->hits[3] = 3;
                }
                row = FIGHTSTG_battle.fighters[0];
                if (task->side != 0) {
                    row = FIGHTSTG_battle.fighters[1];
                }
                row[FIGHTSTG_battle.active[task->side != 0]].charge = 0;
                task->substate++;
            }
            break;
        case 1:
            if (children[0].script == NULL) {
                children[0].message = FIGHTSTG_createMessage();
                if (task->hit != 0) {
                    task->lines[0] = (task->side == 0) << 4;
                    task->lines[1] = task->damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                } else {
                    task->lines[0] = 0x1D;
                    task->lines[1] = (task->side == 0) << 4;
                    children[0].message->show(children[0].message, 2, task->lines);
                }
                if (task->damage != 0) {
                    s32 index = task->side == 0;
                    BattleFighter *fighter = &FIGHTSTG_battle.fighters[index][FIGHTSTG_battle.active[index]];
                    fighter->hp -= task->damage;
                    if (fighter->hp <= 0) {
                        fighter->hp = 0;
                        if (task->noKnockOutEvent == 0) {
                            FIGHTSTG_queueKnockOut(index << 4);
                        }
                    }
                }
                task->substate++;
            }
            break;
        case 2:
            if (children[0].message == NULL) {
                WFIGHTMN_chargeGauge(task->side, task->received);
                task->state = TASK_KILL;
            }
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Starts SIDE's counterattack (FIGHTSTG_updateCounterattack) to RECEIVED
   damage; NOKNOCKOUTEVENT keeps a knockout from queueing its event */
Counterattack *FIGHTSTG_startCounterattack(s32 side, s32 received, s32 noKnockOutEvent) {
    Counterattack *task = createTask(FIGHTSTG_updateCounterattack, sizeof(Counterattack), 4);

    task->side = side;
    task->received = received;
    task->noKnockOutEvent = noKnockOutEvent;
    return task;
}

#if VERSION_EU
/* Revives one of the player's fighters at full HP, clearing its status
   events, and passes tech's unkC to FIGHTSTG_battleFuncs.changeBoost */
void FIGHTSTG_reviveFighter(s32 tech, s32 fighter) {
    BattleFighter *fighters = FIGHTSTG_battle.fighters[0];
    TechData *entry = &TECHS[tech - 1];
    s32 index;
    s32 i;

    if (fighters[fighter].id == 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        index = FIGHTSTG_events.funcs.find(FIGHTSTG_clearIds[i], 0, fighter);
        if (index >= 0) {
            FIGHTSTG_events.events[index].type = 0;
        }
    }
    if (fighters[fighter].hp == 0) {
        WFIGHTMN_checkEquip(fighter);
    }
    fighters[fighter].flags = 0;
    fighters[fighter].hp = fighters[fighter].maxHp;
    FIGHTSTG_battleFuncs.changeBoost(0, fighter, 1, entry->effectPower);
    FIGHTSTG_queueBoostEnd(0, fighter, 1, tech);
}
#endif

/* the techniques that boost a stat of a fighter (FIGHTSTG_updateTechAction): the user's,
   or the enemy's for an amount below 0 */
TechBoost FIGHTSTG_techBoosts[] = {
    { 0xC6, 1, 0, 0x30 },
    { 0xC8, 1, 1, 0x31 },
    { 0xCA, 1, 2, 0x32 },
    { 0xCC, -1, 0, 0x33 },
    { 0xCD, -1, 1, 0x34 },
    { 0xCE, -1, 1, 0x34 },
    { 0xCF, -1, 2, 0x35 },
    { 0xD0, -1, 2, 0x35 },
    { -1, 0, 0, 0 },
};
/* and the ones that boost a stat of all the user's side */
TechBoost FIGHTSTG_sideBoosts[] = {
    { 0xC7, 1, 0, 0x30 },
    { 0xC9, 1, 1, 0x31 },
    { 0xCB, 1, 2, 0x32 },
    { -1, 0, 0, 0 },
};
/* techniques 0xBE-0xC5's four kinds of status (FIGHTSTG_updateTechAction): the flag of
   each in BattleFighter.flags, */
u8 FIGHTSTG_statusTechFlags[] = {
    FIGHTER_POISONED, FIGHTER_PARALYZED, FIGHTER_CONFUSED, 0x3F, /* all six */
};
/* the event types that the European version's FIGHTSTG_reviveFighter clears */
#if VERSION_EU
s32 FIGHTSTG_clearIds[] = {
    EVENT_STATUS_DAMAGE, EVENT_STATUS_END, EVENT_STATUS_END + 1, EVENT_STATUS_END + 2,
    EVENT_RESTRICTION_END, EVENT_RESTRICTION_END + 1,
};
#endif
/* the argument of message 9, which the odd techniques show, */
s32 FIGHTSTG_statusTechArgs[] = {
    1, 2, 3, 4,
};
/* and the message shown when the target has the status */
s32 FIGHTSTG_statusTechLines[] = {
    40, 41, 42, 44,
};

/* A side's technique or item (FIGHTSTG_startTechAction): state 0 shows its message,
   substate 1 does what it does by its kind (2 and 3 deal damage, 4 is an
   item's cure, revival or healing, 5 a boost, a drain or a heal of the
   enemy, 6 an attack timed by the fighter's third stat), then the wake-up
   when the other side's fighter is asleep (substate 4) and the motion of
   the damage (FIGHTSTG_startCounterattack). The match depends on the other side's
   fighter being found as its row's offset added as an int to its slot (as
   in FIGHTSTG_updateFirstTech), on each case's variables being its own, on substate
   1's cases advancing substate themselves (case 5 once, after its switch)
   and on the heal tests being written hp + unk5C > maxHp. */
void FIGHTSTG_updateTechAction(TechAction *task, BattleChild *children) {
    TechData *tech;

    switch (task->state) {
    case TASK_INIT:
    default: {
        TechData *tech = &TECHS[task->tech - 1];

        if (tech->icon == TECH_PHYSICAL || tech->icon == TECH_MAGIC) {
            FIGHTSTG_action.start(task->side, task->tech);
        } else {
            HEAP.zero(&FIGHTSTG_action, 0x68);
        }
        children[0].message = FIGHTSTG_createMessage();
        if (tech->unk10 == 0xC) {
            task->lines[0] = 0x3A;
            task->lines[1] = task->side;
            children[0].message->show(children[0].message, 2, task->lines);
        } else {
            task->lines[0] = task->side;
            task->lines[1] = task->tech;
            children[0].message->show(children[0].message, 3, task->lines);
        }
        {
            s32 other = 1 - (task->side >> 4);
            s32 row = other * 0x60;
            BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];
            BattleFighter *fighter = (BattleFighter *)(row + (s32)slot);

            if (fighter->flags & FIGHTER_ASLEEP) {
                task->asleep = 1;
            }
        }
        task->nextState(task);
        break;
    }
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (children[0].task == NULL) {
                if (FIGHTSTG_action.effects[TECH_EFFECT_ENEMY_ONLY] == 0) {
                    children[0].script = WFIGHTMN_startTech(task->side, task->tech);
                    {
                        BattleFighter *fighters = FIGHTSTG_battle.fighters[0];

                        if (task->side != 0) {
                            fighters = FIGHTSTG_battle.fighters[1];
                        }
                        fighters[FIGHTSTG_battle.active[task->side != 0]].charge = 0;
                    }
                } else {
                    WFIGHTMN_endWeakness(task->side);
                }
                task->substate++;
            }
            break;
        case 1:
            if (children[0].task != NULL) {
                break;
            }
            tech = &TECHS[task->tech - 1];
            switch (tech->icon) {
            default:
                return;
            case TECH_PHYSICAL:
            case TECH_MAGIC: {
                s32 other;

                children[0].message = FIGHTSTG_createMessage();
                other = task->side == 0;
                if (FIGHTSTG_action.effects[TECH_EFFECT_ENEMY_ONLY]) {
                    FIGHTSTG_queuePartnerTech(task->tech);
                    task->state = 3;
                    return;
                }
                if (FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT]) {
                    if (TECHS[task->tech - 1].effect == TECH_EFFECT_DOUBLE_MAGIC) {
                        task->damage = FIGHTSTG_action.hitDamage[0] + FIGHTSTG_action.hitDamage[1];
                        task->lines[0] = other << 4;
                        task->lines[1] = task->damage;
                        children[0].message->show(children[0].message, 4, task->lines);
                    } else {
#if VERSION_US
                        task->damage = FIGHTSTG_action.damage * FIGHTSTG_action.hitsLanded;
#endif
                        task->lines[0] = other << 4;
                        task->lines[1] = FIGHTSTG_action.damage;
                        task->lines[2] = FIGHTSTG_action.hitsLanded;
                        children[0].message->show(children[0].message, 0x10, task->lines);
#if VERSION_EU
                        task->damage = FIGHTSTG_action.damage * FIGHTSTG_action.hitsLanded;
                        if (task->damage >= 10000) {
                            task->damage = 9999;
                        }
#endif
                    }
                } else if (FIGHTSTG_action.effects[TECH_EFFECT_KNOCK_OUT]) {
                    s32 row = other * 0x60;
                    BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

                    ((BattleFighter *)(row + (s32)slot))->hp = 0;
                    FIGHTSTG_queueKnockOut(other << 4);
                    children[0].task->state = 3;
                } else if (FIGHTSTG_action.hits[0]) {
                    task->lines[0] = other << 4;
                    task->lines[1] = FIGHTSTG_action.damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                    task->damage = FIGHTSTG_action.damage;
                } else {
                    task->lines[0] = 0x1D;
                    task->lines[1] = other << 4;
                    children[0].message->show(children[0].message, 2, task->lines);
                }
                if (task->damage != 0) {
                    s32 row = other * 0x60;
                    BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];
                    BattleFighter *fighter = (BattleFighter *)(row + (s32)slot);

                    fighter->hp -= task->damage;
                    if (fighter->hp <= 0) {
                        fighter->hp = 0;
                        FIGHTSTG_queueKnockOut(other << 4);
                        task->step = 1;
                    }
                }
                task->substate++;
                return;
            }
            case 4:
                task->lines[0] = task->side;
                switch (task->tech) {
                case 0xBD:
                    FIGHTSTG_queueAutoRecoverEnd(task->side);
                    FIGHTSTG_queueRecovery(task->side, FIGHTSTG_battle.active[task->side != 0], task->tech);
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 0x27;
                    task->lines[1] = task->side;
                    children[0].message->show(children[0].message, 2, task->lines);
                    task->nextSubstate(task);
                    break;
                case 0xBE:
                case 0xBF:
                case 0xC0:
                case 0xC1:
                case 0xC2:
                case 0xC3:
                case 0xC4:
                case 0xC5: {
                    s32 other;
                    s32 kind;
                    BattleFighter *fighters;
                    s32 i;

                    other = task->side != 0;
                    switch (task->tech) {
                    case 0xBE:
                    case 0xBF:
                    default:
                        kind = 0;
                        break;
                    case 0xC0:
                    case 0xC1:
                        kind = 1;
                        break;
                    case 0xC2:
                    case 0xC3:
                        kind = 2;
                        break;
                    case 0xC4:
                    case 0xC5:
                        kind = 3;
                        break;
                    }
                    fighters = FIGHTSTG_battle.fighters[other];
                    switch (task->step) {
                    case 0:
                    default:
                        children[0].message = FIGHTSTG_createMessage();
                        if (task->tech & 1) {
                            task->lines[0] = task->side;
                            task->lines[1] = FIGHTSTG_statusTechArgs[kind];
                            children[0].message->show(children[0].message, 9, task->lines);
                            task->step = 1;
                            task->counter = 3;
                            return;
                        }
                        if (fighters[FIGHTSTG_battle.active[other]].flags & FIGHTSTG_statusTechFlags[kind]) {
                            task->lines[0] = FIGHTSTG_statusTechLines[kind];
                            task->lines[1] = task->side;
                            task->lines[2] = FIGHTSTG_battle.active[0];
                            children[0].message->show(children[0].message, 2, task->lines);
                            task->step = 1;
                            task->counter = 1;
                            return;
                        }
                        task->lines[0] = 0x2F;
                        children[0].message->show(children[0].message, 1, task->lines);
                        break;
                    case 1:
                        for (i = 0; i < task->counter; i++) {
                            FIGHTSTG_events.funcs.useItem(task->side, i, task->tech);
                        }
                        break;
                    }
                    task->nextSubstate(task);
                    break;
                }
                case 0x64: {
                    BattleFighter *fighter;
                    s32 i;

                    fighter = FIGHTSTG_battle.fighters[0];
                    switch (task->step) {
                    case 0:
                    default:
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = 0;
                        task->lines[1] = 5;
                        children[0].message->show(children[0].message, 9, task->lines);
                        task->step++;
                        return;
                    case 1:
                        for (i = 0; i < 3; i++) {
                            if (fighter[i].id != 0 && fighter[i].hp == 0) {
                                fighter[i].hp = fighter[i].maxHp;
                                WFIGHTMN_checkEquip(i);
                            }
                        }
                        break;
                    }
                    task->nextSubstate(task);
                    break;
                }
                case 0x177: {
#if VERSION_US
                    BattleFighter *fighter;
#endif
                    s32 i;

#if VERSION_US
                    fighter = FIGHTSTG_battle.fighters[0];
#endif
                    switch (task->step) {
                    case 0:
                    default:
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = 0;
                        task->lines[1] = 6;
                        children[0].message->show(children[0].message, 9, task->lines);
                        task->step++;
                        return;
                    case 1:
#if VERSION_US
                        for (i = 0; i < 3; i++) {
                            if (fighter[i].id != 0) {
                                if (fighter[i].hp == 0) {
                                    WFIGHTMN_checkEquip(i);
                                }
                                fighter[i].flags = 0;
                                fighter[i].hp = fighter[i].maxHp;
                                FIGHTSTG_queueBoostEnd(0, i, 1, task->tech);
                            }
                        }
#else
                        for (i = 0; i < 3; i++) {
                            FIGHTSTG_reviveFighter(0x177, i);
                        }
#endif
                        break;
                    }
                    task->nextSubstate(task);
                    break;
                }
                default: {
                    BattleFighter *fighters;
                    s32 kind;

                    fighters = FIGHTSTG_battle.fighters[0];
                    if (task->side != 0) {
                        fighters = FIGHTSTG_battle.fighters[1];
                    }
                    switch (task->step) {
                    case 0:
                    default: {
                        s32 i;
                        s32 most;

                        kind = -1;
                        task->heal = FIGHTSTG_battleFuncs.computeHeal(task->side, task->tech);
                        most = 0;
                        if (task->tech >= 0xBB) {
                            for (i = 0; i < 3; i++) {
                                if (fighters[i].id != 0 && fighters[i].hp != 0) {
                                    s32 lost = fighters[i].maxHp - fighters[i].hp;

                                    if (most < lost) {
                                        most = lost;
                                    }
                                }
                            }
                            if (most != 0) {
                                kind = 9;
                                if (task->heal < most) {
                                    most = task->heal;
                                }
                                task->lines[1] = 0;
                                task->lines[2] = most;
                            }
                        } else {
                            s32 lost;

                            i = FIGHTSTG_battle.active[task->side != 0];
                            lost = fighters[i].maxHp - fighters[i].hp;
                            if (most < lost) {
                                most = lost;
                            }
                            if (most != 0) {
                                kind = 8;
                                if (task->heal < most) {
                                    most = task->heal;
                                }
                                task->heal = most;
                                task->lines[1] = most;
                            }
                        }
                        children[0].message = FIGHTSTG_createMessage();
                        task->lines[0] = task->side;
                        if (kind != -1) {
                            s32 i;

                            children[0].message->show(children[0].message, kind, task->lines);
                            if (task->tech >= 0xBB) {
                                for (i = 0; i < 3; i++) {
                                    if (fighters[i].id != 0 && fighters[i].hp != 0) {
                                        if (fighters[i].hp + task->heal > fighters[i].maxHp) {
                                            fighters[i].hp = fighters[i].maxHp;
                                        } else {
                                            fighters[i].hp += task->heal;
                                        }
                                    }
                                }
                            } else {
                                i = FIGHTSTG_battle.active[task->side != 0];
                                if (fighters[i].hp + task->heal > fighters[i].maxHp) {
                                    fighters[i].hp = fighters[i].maxHp;
                                } else {
                                    fighters[i].hp += task->heal;
                                }
                            }
                            task->nextSubstate(task);
                        } else {
                            task->lines[0] = 0x2F;
                            task->lines[1] = task->side;
                            children[0].message->show(children[0].message, 2, task->lines);
                            task->nextSubstate(task);
                        }
                        break;
                    }
                    case 1:
                        return;
                    }
                    break;
                }
                }
                break;
            case 5:
                children[0].message = FIGHTSTG_createMessage();
                switch (task->tech) {
                case 0xC6:
                case 0xC8:
                case 0xCA:
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF:
                case 0xD0: {
                    TechBoost *boost;
                    s32 other;
                    s32 ok;

                    for (boost = FIGHTSTG_techBoosts; boost->tech != -1; boost++) {
                        if (boost->tech == task->tech) {
                            break;
                        }
                    }
                    ok = 1;
                    other = task->side >> 4;
                    if (boost->amount <= 0) {
                        other ^= 1;
                        if (task->side == 0 && BATTLE_SETUP.unk3E[boost->stat + 8]) {
                            task->lines[0] = 0x2F;
                            children[0].message->show(children[0].message, ok, task->lines);
                            ok = 0;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                    FIGHTSTG_battleFuncs.changeBoost((u8)(other << 4), FIGHTSTG_battle.active[other], boost->stat, boost->amount * tech->effectPower);
                    FIGHTSTG_queueBoostEnd(other << 4, FIGHTSTG_battle.active[other], boost->stat, task->tech);
                    task->lines[0] = boost->line;
                    task->lines[1] = other << 4;
                    task->lines[2] = FIGHTSTG_battle.active[other];
                    children[0].message->show(children[0].message, 2, task->lines);
                    break;
                }
                case 0xC7:
                case 0xC9:
                case 0xCB: {
                    TechBoost *boost;
                    s32 i;

                    for (boost = FIGHTSTG_sideBoosts; boost->tech != -1; boost++) {
                        if (boost->tech == task->tech) {
                            break;
                        }
                    }
                    for (i = 0; i < 3; i++) {
                        if (FIGHTSTG_battle.fighters[task->side >> 4][i].id != 0 && FIGHTSTG_battle.fighters[task->side >> 4][i].hp > 0) {
                            FIGHTSTG_battleFuncs.changeBoost(task->side, i, boost->stat, boost->amount * tech->effectPower);
                            FIGHTSTG_queueBoostEnd(task->side, i, boost->stat, task->tech);
                        }
                    }
                    task->lines[0] = task->side;
                    switch (boost->stat) {
                    case 0:
                        task->lines[1] = 7;
                        break;
                    case 1:
                        task->lines[1] = 8;
                        break;
                    case 2:
                        task->lines[1] = 9;
                        break;
                    }
                    children[0].message->show(children[0].message, 9, task->lines);
                    break;
                }
                case 0xD1:
                case 0xD2: {
                    s32 other = task->side >> 4;
                    s32 row = other * 0x60;
                    BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

                    ((BattleFighter *)(row + (s32)slot))->charge = tech->effectPower;
                    task->lines[0] = 0x36;
                    task->lines[1] = task->side;
                    children[0].message->show(children[0].message, 2, task->lines);
                    break;
                }
                case 0xD3:
                    if (FIGHTSTG_battleFuncs.rollNoSwitch(0x10, 0xD3)) {
                        FIGHTSTG_startRestriction(0xD3);
                        task->lines[0] = 0x44;
                        task->lines[1] = 0;
                        children[0].message->show(children[0].message, 2, task->lines);
                    } else {
                        task->lines[0] = 0x2F;
                        children[0].message->show(children[0].message, 1, task->lines);
                    }
                    break;
                case 0xD4:
                    if (FIGHTSTG_battleFuncs.rollNoDigivolve(0x10, 0xD4)) {
                        FIGHTSTG_startRestriction(0xD4);
                        task->lines[0] = 0x45;
                        task->lines[1] = 0;
                        children[0].message->show(children[0].message, 2, task->lines);
                    } else {
                        task->lines[0] = 0x2F;
                        children[0].message->show(children[0].message, 1, task->lines);
                    }
                    break;
                case 0x187:
                    if (FIGHTSTG_battleFuncs.rollDedigivolve(0x10, 0x187)) {
                        FIGHTSTG_queueDigidevolve();
                        children[0].task->state = 3;
                    } else {
                        task->lines[0] = 0x2F;
                        children[0].message->show(children[0].message, 1, task->lines);
                    }
                    break;
                case 0x188: {
                    BattleFighter *to = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                    BattleFighter *from = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                    s32 amount;

                    if (from->mp != 0) {
                        amount = from->maxMp * tech->effectPower / 128;
                        if (from->mp < amount) {
                            amount = from->mp;
                        }
                        to->mp += amount;
                        from->mp -= amount;
                        if (to->mp > to->maxMp) {
                            to->mp = to->maxMp;
                        }
                        if (from->mp < 0) {
                            from->mp = 0;
                        }
                        task->lines[0] = 0x10;
                        task->lines[1] = amount;
                        task->lines[2] = 1;
                        children[0].message->show(children[0].message, 0x12, task->lines);
                    } else {
                        task->lines[0] = 0x2F;
                        task->lines[1] = 0x10;
                        children[0].message->show(children[0].message, 2, task->lines);
                    }
                    break;
                }
                case 0x190: {
                    BattleFighter *fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];

                    task->heal = FIGHTSTG_battleFuncs.computeHeal(task->side, 0x190);
                    fighter->hp += task->heal;
                    if (fighter->hp > fighter->maxHp) {
                        fighter->hp = fighter->maxHp;
                    }
                    fighter->charge = 0x20;
                    task->lines[0] = 0x46;
                    task->lines[1] = 0x10;
                    children[0].message->show(children[0].message, 2, task->lines);
                    break;
                }
                }
                task->nextSubstate(task);
                break;
            case 6: {
                BattleStats *stats;
                s16 level;
                s32 element;

                children[0].message = FIGHTSTG_createMessage();
                stats = FIGHTSTG_battleFuncs.computeStats(task->side, 1, FIGHTSTG_battle.active[task->side == 0x10]);
                FIGHTSTG_battle.boostElement = tech->icon;
                level = stats->stats[BATTLE_STAT_SPIRIT] / 10;
                element = level + tech->effectPower;
                if (element >= 0x80) {
                    element = 0x7F;
                }
                FIGHTSTG_battle.boostAmount = element;
                FIGHTSTG_queueClearField(stats->stats[BATTLE_STAT_SPIRIT] * 12 + 1000);
                task->lines[0] = tech->element + 0x61;
                children[0].message->show(children[0].message, 1, task->lines);
                task->nextSubstate(task);
                return;
            }
            }
            break;
        case 2:
            if (children[0].task == NULL) {
                TechData *tech = &TECHS[task->tech - 1];

                if ((tech->icon == TECH_PHYSICAL || tech->icon == TECH_MAGIC) && task->step == 0) {
                    if (task->damage == 0) {
                        if (task->side == 0 && FIGHTSTG_battle.kind == BATTLE_KIND_FINAL_LAST) {
                            task->setSubstate(task, 7);
                            break;
                        }
                    } else {
                        children[0].events = FIGHTSTG_startActionEvents(task->side);
                        task->nextSubstate(task);
                        break;
                    }
                }
                task->state = 3;
            }
            break;
        case 3:
            if (children[0].task == NULL) {
                task->substate++;
            }
            break;
        case 4: {
            s32 other = task->side == 0;
            s32 row = other * 0x60;
            BattleFighter *slot = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[other]];

            BattleFighter *fighter = (BattleFighter *)(row + (s32)slot);
            TechData *tech;

            tech = &TECHS[task->tech - 1];
            if (fighter->flags & FIGHTER_ASLEEP) {
                if (task->asleep != 0 && FIGHTSTG_battleFuncs.testWakeUp(other << 4, task->damage) != 0) {
                    task->lines[0] = 0x2B;
                    task->lines[1] = 0x10 - task->side;
                    task->lines[2] = FIGHTSTG_battle.active[other];
                    children[0].message = FIGHTSTG_createMessage();
                    children[0].message->show(children[0].message, 7, task->lines);
                    fighter->flags &= ~FIGHTER_ASLEEP;
                    {
                        s32 event = FIGHTSTG_events.funcs.find(EVENT_STATUS_END + 2, 0x10 - task->side, FIGHTSTG_battle.active[other]);

                        if (event >= 0) {
                            FIGHTSTG_events.events[event].type = 0;
                        }
                    }
                    task->substate = 9;
                } else {
                    task->state = 3;
                }
            } else if (tech->icon == TECH_PHYSICAL) {
                children[0].counter = FIGHTSTG_startCounterattack((task->side == 0) << 4, task->damage, tech->unk10 == 0xC);
                task->substate = 6;
            } else {
                task->substate = 5;
            }
            break;
        }
        case 6:
            if (children[0].task != NULL) {
                if (children[0].task->state != 2) {
                    break;
                }
            case 5:
                WFIGHTMN_chargeGauge(task->side, task->damage);
            }
            task->state = 3;
            break;
        case 7:
            if (children[0].task == NULL) {
                TechData *tech = &TECHS[task->tech - 1];

                children[0].enemyAttack = FIGHTSTG_startEnemyAttack(1, tech->unk10 == 0xC);
                task->substate++;
            }
            break;
        case 8:
            if (children[0].task == NULL) {
                task->setState(task, 3);
            }
            break;
        case 9:
            if (children[0].task == NULL) {
                TechData *tech = &TECHS[task->tech - 1];

                if (tech->icon == TECH_PHYSICAL) {
                    children[0].counter = FIGHTSTG_startCounterattack((task->side == 0) << 4, task->damage, tech->unk10 == 0xC);
                    task->substate = 6;
                } else {
                    task->substate = 5;
                }
            }
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Starts side's (0 or 0x10) technique or item tech */
TechAction *FIGHTSTG_startTechAction(s32 side, s32 tech) {
    TechAction *task = createTask(FIGHTSTG_updateTechAction, sizeof(TechAction), sizeof(Task *));

    task->side = side;
    task->tech = tech;
    return task;
}


/* BATTLE_KIND_FINAL_SECOND's enemy turn: the enemy's message and its battle
   table entry's second technique, then the player's fighter is left at 1 HP
   with a message of the damage, and the battle goes on */
void FIGHTSTG_updateOneHpTurn(OneHpTurn *task, BattleChild *children) {
    BattleTableEntry *entry;
    BattleFighter *fighter;

    switch (task->state) {
    case TASK_INIT:
    default:
        entry = FIGHTSTG_battleTableFunc(FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]].id);
        children[0].message = FIGHTSTG_createMessage();
        task->lines[0] = 0x10;
        task->lines[1] = entry->unk8[1];
        children[0].message->show(children[0].message, 3, task->lines);
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            if (children[0].task == NULL) {
                children[0].script = WFIGHTMN_startTech(0x10, task->lines[1]);
                task->substate++;
            }
            break;
        case 1:
            if (children[0].task == NULL) {
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0;
                task->lines[1] = fighter->hp - 1;
                children[0].message->show(children[0].message, 4, task->lines);
                fighter->hp = 1;
                task->substate++;
            }
            break;
        case 2:
            if (children[0].task == NULL) {
                FIGHTSTG_queueEnemyTurn(FIGHTSTG_events.funcs.getDelay(0x10, 0));
                FIGHTSTG_queueLastEnemy();
                task->state = TASK_KILL;
            }
            break;
        }
        break;
    case 2:
    case TASK_KILL:
        break;
    }
}

/* Starts BATTLE_KIND_FINAL_SECOND's enemy turn */
OneHpTurn *FIGHTSTG_startOneHpTurn(void) {
    return createTask(FIGHTSTG_updateOneHpTurn, sizeof(OneHpTurn), sizeof(Task *));
}

/* An attack on the player's active fighter (FIGHTSTG_startEnemyAttack): state 1 is the
   enemy's technique, 2 another attack, each with its messages, motion and
   damage. The match depends on each case advancing substate itself, on a
   fighter variable of its own in each case and on the pointer sum of the
   FIGHTER_ASLEEP test. */
void FIGHTSTG_updateEnemyAttack(EnemyAttack *task, BattleChild *children) {
    BattleTableEntry *entry = FIGHTSTG_battleTableFunc(FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]].id);
    BattleFighter *fighter;
    BattleFighter *player;
    BattleFighter *target;
    BattleFighter *struck;
    s32 index;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->setState(task, task->kind + 1);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            FIGHTSTG_queueEnemyTurn(FIGHTSTG_events.funcs.getDelay(0x10, 0));
            if (FIGHTSTG_battle.weakened != 0) {
                if (FIGHTSTG_events.funcs.first(EVENT_WEAKNESS_END) >= 0) {
                    task->setState(task, 3);
                } else {
                    children[0].message = FIGHTSTG_createMessage();
                    task->lines[0] = 8;
                    task->lines[1] = 0x10;
                    task->tech = entry->unk8[2];
                    children[0].message->show(children[0].message, 2, task->lines);
                    FIGHTSTG_battle.weakened = 0;
                    FIGHTSTG_battle.hitCount = 0;
                    task->unk60 = 1;
                }
            } else {
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x10;
                task->lines[1] = FIGHTSTG_battle.tech != 0 ? FIGHTSTG_battle.tech : entry->unk8[0];
                children[0].message->show(children[0].message, 3, task->lines);
                task->tech = entry->unk8[0];
            }
            if ((FIGHTSTG_battle.fighters[0] + FIGHTSTG_battle.active[0])->flags & FIGHTER_ASLEEP) {
                task->asleep = 1;
            }
            task->substate++;
            break;
        case 1:
            if (children[0].task == NULL) {
                FIGHTSTG_action.start(0x10, task->tech);
                children[0].script = WFIGHTMN_startTech(0x10, task->tech);
                if (task->unk60 != 0) {
                    WFIGHTMN_setIdleMotion(0x10, 0);
                    task->unk60 = 0;
                }
                task->substate++;
            }
            break;
        case 2:
            if (children[0].task == NULL) {
                children[0].message = FIGHTSTG_createMessage();
                if (FIGHTSTG_action.hits[0]) {
#if VERSION_EU
                    player = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                    /* the European version's instant knockout */
                    if (FIGHTSTG_action.effects[TECH_EFFECT_KNOCK_OUT]) {
                        player->hp = 0;
                        children[0].task->state = 3;
                    } else {
                        task->lines[0] = 0;
                        task->lines[1] = FIGHTSTG_action.damage;
                        children[0].message->show(children[0].message, 4, task->lines);
                        player->hp -= FIGHTSTG_action.damage;
                        if (player->hp <= 0) {
                            player->hp = 0;
                        }
                    }
#else
                    task->lines[0] = 0;
                    task->lines[1] = FIGHTSTG_action.damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                    player = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                    player->hp -= FIGHTSTG_action.damage;
                    if (player->hp <= 0) {
                        player->hp = 0;
                    }
#endif
                    task->substate++;
                } else {
                    task->lines[0] = 0x1D;
                    task->lines[1] = 0;
                    children[0].message->show(children[0].message, 2, task->lines);
                    task->substate = 5;
                }
            }
            break;
        case 3:
            if (children[0].task == NULL) {
                target = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
#if VERSION_EU
                if (FIGHTSTG_action.effects[TECH_EFFECT_KNOCK_OUT]) {
                    target->hp = 0;
                    FIGHTSTG_queueKnockOut(0);
                    task->state = 3;
                } else
#endif
                if (target->hp <= 0) {
                    target->hp = 0;
                    FIGHTSTG_queueKnockOut(0);
                    task->state = 3;
                } else {
                    children[0].events = FIGHTSTG_startActionEvents(0x10);
                    task->substate++;
                }
            }
            break;
        case 4:
            if (children[0].task == NULL) {
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                if (fighter->flags & FIGHTER_ASLEEP) {
                    if (task->asleep != 0 && FIGHTSTG_battleFuncs.testWakeUp(0, FIGHTSTG_action.damage) != 0) {
                        task->lines[0] = 0x2B;
                        task->lines[1] = 0;
                        task->lines[2] = FIGHTSTG_battle.active[0];
                        children[0].message = FIGHTSTG_createMessage();
                        children[0].message->show(children[0].message, 7, task->lines);
                        fighter->flags &= ~FIGHTER_ASLEEP;
                        index = FIGHTSTG_events.funcs.find(EVENT_STATUS_END + 2, 0, FIGHTSTG_battle.active[0]);
                        if (index >= 0) {
                            FIGHTSTG_events.events[index].type = 0;
                        }
                        task->substate = 5;
                    } else {
                        task->state = 3;
                    }
                } else {
                    task->substate = 5;
                }
            }
            break;
        case 5:
            if (children[0].task == NULL) {
                WFIGHTMN_chargeGauge(0x10, FIGHTSTG_action.damage);
                task->state = 3;
            }
            break;
        }
        break;
    case 2:
        if (children[0].task == NULL) {
            switch (task->substate) {
            case 0:
            default:
                children[0].message = FIGHTSTG_createMessage();
                task->lines[0] = 0x10;
                children[0].message->show(children[0].message, 6, task->lines);
                task->substate++;
                break;
            case 1:
                FIGHTSTG_action.start(0x10, entry->unk8[1]);
                children[0].script = WFIGHTMN_startTech(0x10, entry->unk8[1]);
                task->substate++;
                break;
            case 2:
                children[0].message = FIGHTSTG_createMessage();
                if (FIGHTSTG_action.hits[0]) {
                    task->lines[0] = 0;
                    task->lines[1] = FIGHTSTG_action.damage;
                    children[0].message->show(children[0].message, 4, task->lines);
                    struck = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                    struck->hp -= FIGHTSTG_action.damage;
                    if (struck->hp <= 0) {
                        struck->hp = 0;
                        if (task->noKnockout == 0) {
                            FIGHTSTG_queueKnockOut(0);
                        }
                    } else {
                        WFIGHTMN_chargeGauge(0x10, FIGHTSTG_action.damage);
                    }
                } else {
                    task->lines[0] = 0x1D;
                    task->lines[1] = 0;
                    children[0].message->show(children[0].message, 2, task->lines);
                }
                task->substate++;
                break;
            case 3:
                FIGHTSTG_endEnemyWeakness();
                task->state = 3;
                break;
            }
        }
        break;
    case 3:
        break;
    }
}

/* Starts an attack on the player's active fighter (FIGHTSTG_updateEnemyAttack):
   kind 0 for the enemy's technique, 1 for another attack */
EnemyAttack *FIGHTSTG_startEnemyAttack(s32 kind, s32 noKnockout) {
    EnemyAttack *task = createTask(FIGHTSTG_updateEnemyAttack, sizeof(EnemyAttack), sizeof(Task *));

    task->kind = kind;
    task->noKnockout = noKnockout;
    return task;
}

/* Runs the queued battle events: the first flag set in FIGHTSTG_action.effects
   picks the step, which shows its message, applies its effect and clears
   the flag. The match depends on each event branch ending with its own flag
   clear and `break` (the copies are merged after reload, but they make the
   loop big enough that loop.c leaves 0x10 at each use), on `case 2` written
   next to `default` in the message switch (it sets the jump table's base)
   and on event 0x1D setting its fighter and enemy before args[0]. */
void FIGHTSTG_updateActionEvents(ActionEvents *task, BattleChild *children) {
    BattleFighter *fighter;
    BattleFighter *enemy;
    u32 side;
    s32 i;
    switch (task->state) {
    case 0:
    default:
        FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT] = 0;
        FIGHTSTG_action.effects[TECH_EFFECT_ENEMY_ONLY] = 0;
        FIGHTSTG_action.effects[TECH_EFFECT_CRITICAL] = 0;
        task->nextState(task);
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            for (i = 0; i < 0x25; i++) {
                if (FIGHTSTG_action.effects[i] != 0) {
                    task->step = i;
                    side = task->side >> 4;
                    task->substate++;
                    fighter = &FIGHTSTG_battle.fighters[1 - side][FIGHTSTG_battle.active[1 - side]];
                    if (i == TECH_EFFECT_SLEEP && (fighter->flags & FIGHTER_ASLEEP)) {
                        FIGHTSTG_inflictSleep(0x10 - task->side, FIGHTSTG_action.tech, FIGHTSTG_action.effects[TECH_EFFECT_SLEEP]);
                        FIGHTSTG_action.effects[task->step] = 0;
                        break;
                    } else {
                        children[0].message = FIGHTSTG_createMessage();
                        if (i == TECH_EFFECT_STEAL) {
                            enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                            task->args[0] = enemy->item;
                            children[0].message->show(children[0].message, 0x11, task->args);
                            GAME.items[enemy->item]++;
                            if (GAME.items[enemy->item] >= 100) {
                                GAME.items[enemy->item] = 99;
                            }
                            enemy->item = -1;
                            FIGHTSTG_action.effects[task->step] = 0;
                            break;
                        } else if (i == TECH_EFFECT_DRAIN) {
                            fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
                            task->args[0] = task->side;
                            if (fighter->maxHp < fighter->hp + FIGHTSTG_action.drain) {
                                task->args[1] = fighter->maxHp - fighter->hp;
                            } else {
                                task->args[1] = FIGHTSTG_action.drain;
                            }
                            task->args[2] = 0;
                            children[0].message->show(children[0].message, 0x12, task->args);
                            fighter->hp += task->args[1];
                            FIGHTSTG_action.effects[task->step] = 0;
                            break;
                        } else if (i == TECH_EFFECT_DRAIN_MP) {
                            fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                            enemy = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
                            task->args[0] = 0x10;
                            if (fighter->mp < FIGHTSTG_action.drain) {
                                task->args[1] = fighter->mp;
                            } else {
                                task->args[1] = FIGHTSTG_action.drain;
                            }
                            task->args[2] = 1;
                            children[0].message->show(children[0].message, 0x12, task->args);
                            enemy->mp += task->args[1];
                            if (enemy->maxMp < enemy->mp) {
                                enemy->mp = enemy->maxMp;
                            }
                            fighter->mp -= task->args[1];
                            FIGHTSTG_action.effects[task->step] = 0;
                            break;
                        } else if (i == TECH_EFFECT_RAISE_ONE_STATUS) {
                            task->args[0] = 0x10 - task->side;
                            if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_ONE_STATUS] & 1) {
                                task->args[1] = 0;
                            } else if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_ONE_STATUS] & 2) {
                                task->args[1] = 1;
                            } else if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_ONE_STATUS] & 4) {
                                task->args[1] = 2;
                            }
                            children[0].message->show(children[0].message, 0x13, task->args);
                            FIGHTSTG_action.effects[task->step] = 0;
                            break;
                        } else if (i == TECH_EFFECT_RAISE_EACH_STATUS) {
                            task->args[0] = 0x10 - task->side;
                            if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_EACH_STATUS] & 1) {
                                task->args[1] = 0;
                                FIGHTSTG_action.effects[task->step] &= ~1;
                            } else if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_EACH_STATUS] & 2) {
                                task->args[1] = 1;
                                FIGHTSTG_action.effects[task->step] &= ~2;
                            } else if (FIGHTSTG_action.effects[TECH_EFFECT_RAISE_EACH_STATUS] & 4) {
                                task->args[1] = 2;
                                FIGHTSTG_action.effects[task->step] &= ~4;
                            }
                            children[0].message->show(children[0].message, 0x13, task->args);
                            break;
                        } else {
                            s32 other = task->side != 0;

                            switch (i) {
                            case TECH_EFFECT_POISON:
                            default:
                                FIGHTSTG_inflictPoison(0x10 - task->side, FIGHTSTG_battle.active[1 - other], FIGHTSTG_action.effects[i]);
                                task->args[0] = 0x1E;
                                break;
                            case TECH_EFFECT_PARALYSIS:
                                FIGHTSTG_inflictParalysis(0x10 - task->side, FIGHTSTG_action.tech, FIGHTSTG_action.effects[i]);
                                task->args[0] = 0x1F;
                                break;
                            case TECH_EFFECT_CONFUSION:
                                FIGHTSTG_inflictConfusion(0x10 - task->side, FIGHTSTG_action.tech, FIGHTSTG_action.effects[i]);
                                task->args[0] = 0x20;
                                break;
                            case TECH_EFFECT_SLEEP:
                                FIGHTSTG_inflictSleep(0x10 - task->side, FIGHTSTG_action.tech, FIGHTSTG_action.effects[i]);
                                task->args[0] = 0x21;
                                break;
                            case TECH_EFFECT_NO_SWITCH:
                                FIGHTSTG_startRestriction(0xD3);
                                task->args[0] = 0x44;
                                break;
                            case TECH_EFFECT_LOWER_ATTACK:
                                task->args[0] = 0x33;
                                break;
                            case TECH_EFFECT_LOWER_DEFENSE:
                                task->args[0] = 0x34;
                                break;
                            case TECH_EFFECT_RAISE_ALL_STATUS:
                                task->args[0] = 0x4C;
                                break;
                            case TECH_EFFECT_END_BATTLE:
                                task->args[0] = 0x48;
                                FIGHTSTG_endBattle(BATTLE_FLED);
                                break;
                            }
                            task->args[1] = (task->side == 0) << 4;
                            children[0].message->show(children[0].message, 2, task->args);
                        }
                    }
                    FIGHTSTG_action.effects[task->step] = 0;
                    break;
                }
            }
            if (task->step == 0) {
                task->state = 3;
            }
            break;
        case 1:
            if (children[0].task == NULL) {
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

/* Starts running the current action's events for SIDE
   (FIGHTSTG_updateActionEvents) */
ActionEvents *FIGHTSTG_startActionEvents(s32 arg0) {
    ActionEvents *task = createTask(FIGHTSTG_updateActionEvents, sizeof(ActionEvents), sizeof(Task *));

    task->side = arg0;
    return task;
}

void FIGHTSTG_applyCamera(FighterCamera *task) {
    Layer *layer;

    RotMatrixYXZ_gte(&task->rot, &task->coord.coord);
    task->coord.flg = 0;
    task->view.super = &task->coord;
    task->coord.coord.t[0] = task->trans.vx;
    task->coord.coord.t[1] = task->trans.vy;
    task->coord.coord.t[2] = task->trans.vz;
    func_80029DB8(&task->view);
    layer = GFX.funcs.getLayer(0x1009);
    layer->setKeepView(layer, 1, task->proj);
    task->frames--;
}

void FIGHTSTG_loadCamera(FighterCamera *task) {
    FighterInfo *info = FIGHTSTG_fighterCache.funcs.getInfo(task->fighter);
    s32 i = 6;

    if (task->control->idleMotion != 0) {
        i = 7;
    }
    task->view.vpx = info->camPos[i].x;
    task->view.vpy = -info->camPos[i].y;
    task->view.vpz = -info->camPos[i].z;
    task->view.vrx = info->camRef[i].x;
    task->view.vry = -info->camRef[i].y;
    task->view.vrz = -info->camRef[i].z;
    task->proj = info->camProj[i];
    task->rot.vx = 0;
    task->rot.vy = 0;
    task->rot.vz = 0;
    task->trans.vx = 0;
    task->trans.vy = 0;
    task->trans.vz = 0;
}

void FIGHTSTG_updateCamera(FighterCamera *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
    case TASK_RUN:
        switch (task->step) {
        case 0:
        default:
            if (GFX.funcs.getLayer(0x1009) != NULL) {
                FIGHTSTG_loadCamera(task);
                task->frames = 2;
                task->nextStep(task);
            }
            break;
        case 1:
            break;
        }
        if (task->frames != 0) {
            FIGHTSTG_applyCamera(task);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

FighterCamera *FIGHTSTG_createCamera(s32 fighter, ModelControl *control) {
    FighterCamera *task = createTask(FIGHTSTG_updateCamera, sizeof(FighterCamera), 0);

    task->fighter = fighter;
    task->control = control;
    return task;
}

void FIGHTSTG_updateBattleCamera(BattleCamera *task) {
    SVECTOR from;
    SVECTOR to;
    SVECTOR out;
    GsCOORDINATE2 coord;
    GsRVIEW2 view;
    Layer *layer;
    s32 t;

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
                task->t += (task->tStep >> 8) * GFX.funcs.getFrameTime();
                t = task->t;
                if (t < 0x1000) {
                    from.vx = task->from.vpx;
                    from.vy = task->from.vpy;
                    from.vz = task->from.vpz;
                    to.vx = task->to.vpx;
                    to.vy = task->to.vpy;
                    to.vz = task->to.vpz;
                    FIGHTSTG_interp.lerp(&from, &to, t, &out);
                    task->current.vpx = out.vx;
                    task->current.vpy = out.vy;
                    task->current.vpz = out.vz;
                    from.vx = task->from.vrx;
                    from.vy = task->from.vry;
                    from.vz = task->from.vrz;
                    to.vx = task->to.vrx;
                    to.vy = task->to.vry;
                    to.vz = task->to.vrz;
                    FIGHTSTG_interp.lerp(&from, &to, t, &out);
                    task->current.vrx = out.vx;
                    task->current.vry = out.vy;
                    task->current.vrz = out.vz;
                    from.vx = task->from.tx;
                    from.vy = task->from.ty;
                    from.vz = task->from.tz;
                    to.vx = task->to.tx;
                    to.vy = task->to.ty;
                    to.vz = task->to.tz;
                    FIGHTSTG_interp.lerp(&from, &to, t, &out);
                    task->current.tx = out.vx;
                    task->current.ty = out.vy;
                    task->current.tz = out.vz;
                    FIGHTSTG_interp.lerp(&task->from.rot, &task->to.rot, t, &out);
                    task->current.rot.vx = out.vx;
                    task->current.rot.vy = out.vy;
                    task->current.rot.vz = out.vz;
                    from.vx = task->from.rz;
                    from.vy = task->from.proj;
                    from.vz = 0;
                    to.vx = task->to.rz;
                    to.vy = task->to.proj;
                    to.vz = 0;
                    FIGHTSTG_interp.lerp(&from, &to, t, &out);
                    task->current.rz = out.vx;
                    task->current.proj = out.vy;
                } else {
                    task->t = 0x1000;
                    task->current = task->to;
                }
            }
            RotMatrixYXZ_gte(&task->current.rot, &coord.coord);
            coord.coord.t[0] = task->current.tx;
            coord.coord.t[1] = task->current.ty;
            coord.coord.t[2] = task->current.tz;
            coord.flg = 0;
            coord.param = NULL;
            coord.super = NULL;
            coord.sub = NULL;
            view.vpx = task->current.vpx;
            view.vpy = task->current.vpy;
            view.vpz = task->current.vpz;
            view.vrx = task->current.vrx;
            view.vry = task->current.vry;
            view.vrz = task->current.vrz;
            view.rz = task->current.rz << 12;
            view.super = &coord;
            func_80029DB8(&view);
            layer = GFX.funcs.getLayer(task->layerId);
            layer->setKeepView(layer, 1, task->current.proj);
            if (task->t == 0x1000) {
                task->nextSubstate(task);
            }
            break;
        }
        break;
    case TASK_KILL:
        layer = GFX.funcs.getLayer(task->layerId);
        layer->setKeepView(layer, 0, 0);
        break;
    }
}

void FIGHTSTG_setBattleCameraView(BattleCamera *task, CameraView *view) {
    task->current = *view;
    task->t = 0x1000;
    task->setState(task, TASK_DONE);
}

void FIGHTSTG_fadeBattleCamera(BattleCamera *task, CameraView *from, CameraView *to, s32 time) {
    if (from != NULL) {
        task->from = *from;
    } else {
        task->from = task->current;
    }
    task->to = *to;
    task->tStep = 0x100000 / time;
    task->t = 0;
    task->setState(task, TASK_DONE);
}

/* The view of a fighter's camera (id as Models.getFighter takes it), which ends
   the battle camera's fade */
CameraView *FIGHTSTG_getFighterView(BattleCamera *task, s32 id, s32 camera) {
    Models *models;
    s32 fighter;
    FighterInfo *info;
    FighterInfoEnemy *enemy;

    /* the match depends on the do-while and its breaks, the early exit that
       the stages' event code uses too */
    do {
        models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
        if (models == NULL) {
            break;
        }
        fighter = models->getFighter(models, id);
        if (fighter == 0) {
            break;
        }
        if (!(id & 0xF0)) {
            info = FIGHTSTG_fighterCache.funcs.getInfo(fighter);
            FIGHTSTG_fighterView.vpx = info->camPos[camera].x;
            FIGHTSTG_fighterView.vpy = -info->camPos[camera].y;
            FIGHTSTG_fighterView.vpz = -info->camPos[camera].z;
            FIGHTSTG_fighterView.vrx = info->camRef[camera].x;
            FIGHTSTG_fighterView.vry = -info->camRef[camera].y;
            FIGHTSTG_fighterView.vrz = -info->camRef[camera].z;
            FIGHTSTG_fighterView.proj = info->camProj[camera];
        } else {
            enemy = (FighterInfoEnemy *)FIGHTSTG_fighterCache.funcs.getInfo(fighter);
            FIGHTSTG_fighterView.vpx = enemy->camPos[camera].x;
            FIGHTSTG_fighterView.vpy = -enemy->camPos[camera].y;
            FIGHTSTG_fighterView.vpz = -enemy->camPos[camera].z;
            FIGHTSTG_fighterView.vrx = enemy->camRef[camera].x;
            FIGHTSTG_fighterView.vry = -enemy->camRef[camera].y;
            FIGHTSTG_fighterView.vrz = -enemy->camRef[camera].z;
            FIGHTSTG_fighterView.proj = enemy->camProj[camera];
        }
        FIGHTSTG_fighterView.rot.vx = 0;
        FIGHTSTG_fighterView.rot.vy = 0;
        FIGHTSTG_fighterView.rot.vz = 0;
        FIGHTSTG_fighterView.tx = 0;
        FIGHTSTG_fighterView.ty = 0;
        FIGHTSTG_fighterView.tz = 0;
        FIGHTSTG_fighterView.rz = 0;
        task->setState(task, TASK_DONE);
    } while (0);
    return &FIGHTSTG_fighterView;
}

/* The view of the enemy's last camera */
CameraView *FIGHTSTG_getEnemyView(BattleCamera *task) {
    Models *models;
    s32 fighter;

    /* the match depends on the do-while and its breaks, as FIGHTSTG_getFighterView's */
    do {
        models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
        if (models == NULL) {
            break;
        }
        fighter = models->getFighter(models, 0x10);
        if (fighter == 0) {
            break;
        }
        FIGHTSTG_fighterCache.funcs.getInfo(fighter);
        FIGHTSTG_getFighterView(task, 0, ((FighterInfoEnemy *)FIGHTSTG_fighterCache.enemyInfo)->cameraCount - 1);
    } while (0);
    return &FIGHTSTG_fighterView;
}

BattleCamera *FIGHTSTG_createBattleCamera(s32 layerId) {
    BattleCamera *task = createTaskWithId(FIGHTSTG_updateBattleCamera, sizeof(BattleCamera), 0, BATTLE_TASK_CAMERA);

    task->set = FIGHTSTG_setBattleCameraView;
    task->fade = FIGHTSTG_fadeBattleCamera;
    task->getEnemyView = FIGHTSTG_getEnemyView;
    task->layerId = layerId;
    task->getFighterView = FIGHTSTG_getFighterView;
    return task;
}

/* The player's turn: substate 2 opens the command menu
   (FIGHTSTG_createCommandMenu) and then the menu of its command, 3 the
   confused menu (FIGHTSTG_createConfusedMenu) and 4 the switch menu after a
   knockout (FIGHTSTG_createSwitchMenu); each sets action and goes back to
   substate 0, which closes the children. The match depends on the menus' results being switches with case
   -1 first and on each of the two endings of the command menu's last step
   being written out. The children are kept as Task pointers (hence the
   casts) because child 3 is whichever command menu is open, and substate 0
   closes them all in one loop. */
void FIGHTSTG_updatePlayerTurn(PlayerTurn *task, Task **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            switch (task->step) {
            case 0:
            default:
                task->command = BATTLE_COMMAND_ATTACK;
                for (i = 1; i < 7; i++) {
                    if (children[i] != NULL) {
                        children[i]->setState(children[i], 3);
                    }
                }
                task->nextStep(task);
                break;
            case 1:
                break;
            }
            break;
        case 1:
            if (children[0] == NULL) {
                children[0] = (Task *)FIGHTSTG_createHud();
            }
            task->setSubstate(task, 0);
            break;
        case 2:
            switch (task->step) {
            case 0:
            default:
                switch (task->counter) {
                case 0:
                default:
                    if (children[0] == NULL) {
                        children[0] = (Task *)FIGHTSTG_createHud();
                    }
                    if (children[1] == NULL) {
                        children[1] = (Task *)FIGHTSTG_createCommandMenu(task->command, &task->result);
                    }
                    if (children[2] == NULL) {
                        children[2] = (Task *)FIGHTSTG_createPartnerView();
                    }
                    if (children[6] == NULL) {
                        children[6] = (Task *)FIGHTSTG_createShotCamera();
                    }
                    task->result = -1;
                    task->tickCounter(task);
                case 1:
                    if (task->result != -1) {
                        task->command = task->result;
                        switch (task->result) {
                        case BATTLE_COMMAND_ATTACK:
                            task->action = 0;
                            task->setSubstate(task, 0);
                            break;
                        case BATTLE_COMMAND_TECH:
                            task->setStep(task, 3);
                            break;
                        case BATTLE_COMMAND_DIGIVOLVE:
                            task->setStep(task, 1);
                            break;
                        case BATTLE_COMMAND_SWITCH:
                            task->setStep(task, 4);
                            task->unk54 = 0;
                            break;
                        case BATTLE_COMMAND_ITEM:
                            task->setStep(task, 2);
                            break;
                        case BATTLE_COMMAND_RUN:
                            task->action = 1;
                            task->setSubstate(task, 0);
                            break;
                        }
                    }
                    break;
                }
                break;
            case 1:
                switch (task->counter) {
                case 0:
                default:
                    task->result = GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]);
                    children[3] = (Task *)FIGHTSTG_createDigivolveMenu(&task->result);
                    task->tickCounter(task);
                case 1:
                    switch (task->result) {
                    case -1:
                        break;
                    case -2:
                        task->setSubstate(task, 2);
                        break;
                    default:
                        task->action = 2;
                        task->unk60 = GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]);
                        task->digimon = task->result;
                        task->setSubstate(task, 0);
                        break;
                    }
                    break;
                }
                break;
            case 2:
                switch (task->counter) {
                case 0:
                default:
                    children[3] = (Task *)FIGHTSTG_createItemMenu(&task->result);
                    task->tickCounter(task);
                case 1:
                    switch (task->result) {
                    case -1:
                        break;
                    case -2:
                        task->setSubstate(task, 2);
                        break;
                    default:
                        task->action = 3;
                        task->unk60 = task->result;
                        task->setSubstate(task, 0);
                        break;
                    }
                    break;
                }
                break;
            case 3:
                switch (task->counter) {
                case 0:
                default:
                    children[3] = (Task *)FIGHTSTG_createTechMenu(&task->result);
                    task->tickCounter(task);
                case 1:
                    switch (task->result) {
                    case -1:
                        break;
                    case -2:
                        task->setSubstate(task, 2);
                        break;
                    default:
                        task->action = 4;
                        task->unk60 = task->result;
                        task->setSubstate(task, 0);
                        break;
                    }
                    break;
                }
                break;
            case 4:
                switch (task->counter) {
                case 0:
                default:
                    children[3] = (Task *)FIGHTSTG_createSwitchMenu(&task->result, &task->unk54, 1);
                    task->tickCounter(task);
                case 1:
                    switch (task->result) {
                    case -1:
                        break;
                    case -2:
                        task->setSubstate(task, 2);
                        break;
                    default:
                        task->unk60 = task->result;
                        children[4] = (Task *)FIGHTSTG_createPairSwitchMenu(&task->result, &task->unk68);
                        task->tickCounter(task);
                        break;
                    }
                    break;
                case 2:
                    switch (task->result) {
                    case -1:
                        break;
                    case -2:
                        task->setCounter(task, 0);
                        break;
                    default:
                        if ((task->result & 0xF) == 0) {
                            task->action = 5;
                            task->digimon = task->result >> 4;
                            task->setSubstate(task, 0);
                            task->unk54 = 0;
                        } else {
                            task->action = 6;
                            task->digimon = task->result >> 4;
                            task->setSubstate(task, 0);
                            task->unk54 = 0;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 3:
            switch (task->counter) {
            case 0:
            default:
                if (children[2] == NULL) {
                    children[2] = (Task *)FIGHTSTG_createPartnerView();
                }
                if (children[6] == NULL) {
                    children[6] = (Task *)FIGHTSTG_createShotCamera();
                }
                if (children[1] == NULL) {
                    children[1] = (Task *)FIGHTSTG_createConfusedMenu(&task->result, children[2], children[6]);
                }
                task->result = -1;
                task->tickCounter(task);
            case 1:
                switch (task->result) {
                case -1:
                    break;
                case 0:
                    task->action = 0;
                    task->setSubstate(task, 0);
                    break;
                default:
                    task->action = -1;
                    task->setSubstate(task, 0);
                    break;
                }
                break;
            }
            break;
        case 4:
            switch (task->counter) {
            case 0:
            default:
                if (children[6] == NULL) {
                    children[6] = (Task *)FIGHTSTG_createShotCamera();
                }
                if (children[3] == NULL) {
                    children[3] = (Task *)FIGHTSTG_createSwitchMenu(&task->result, &task->unk54, 0);
                }
                task->tickCounter(task);
            case 1:
                if (task->result != -1) {
                    task->unk60 = task->result;
                    children[4] = (Task *)FIGHTSTG_createSwitchInMenu(&task->result);
                    task->tickCounter(task);
                }
                break;
            case 2:
                switch (task->result) {
                case -1:
                    break;
                case -2:
                    task->setCounter(task, 0);
                    break;
                default:
                    if ((task->result & 0xF) == 0) {
                        task->action = 5;
                        task->digimon = task->result >> 4;
                        task->setSubstate(task, 0);
                        task->unk54 = 0;
                    }
                    break;
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

/* Starts the player's turn (FIGHTSTG_updatePlayerTurn, id 0xE) */
PlayerTurn *FIGHTSTG_startPlayerTurn(void) {
    return createTaskWithId(FIGHTSTG_updatePlayerTurn, sizeof(PlayerTurn), 7 * sizeof(Task *), BATTLE_TASK_PLAYER_TURN);
}

/* Sets the player's turn's substate, while it runs (4 picks the next fighter) */
void FIGHTSTG_setPlayerTurnStep(s32 substate) {
    Task *task = TASK_REGISTRY.funcs.find(BATTLE_TASK_PLAYER_TURN, -1, -1);

    if (task != NULL && task->state == TASK_RUN) {
        task->setSubstate(task, substate);
    }
}

/* Whether the player's turn has a menu open (its substate isn't 0) */
s32 FIGHTSTG_isPlayerChoosing(void) {
    return ((Task *)TASK_REGISTRY.funcs.find(BATTLE_TASK_PLAYER_TURN, -1, -1))->substate != 0;
}

/* Draws the white flash: a full-screen quad of the task's level, added to the
   screen on layer 0x1006 */
void FIGHTSTG_drawWhiteFlash(WhiteFlash *task) {
    Layer *layer = GFX.funcs.getLayer(0x1006);
    u_long *ot = (u_long *)layer->getOtEntry(layer, 0);
    POLY_F4 *poly = GFX.funcs.getPrim();
    DR_TPAGE *mode;

    poly->r0 = task->level;
    poly->g0 = task->level;
    poly->b0 = task->level;
    setlen(poly, 5);
    poly->code = 0x2A;
    /* the match depends on these chained stores, x3 before x1 */
    poly->x3 = poly->x1 = 320;
    poly->x2 = poly->x0 = 0;
    poly->y1 = poly->y0 = 0;
    poly->y3 = poly->y2 = 240;
    addPrim(ot, poly);
    mode = (DR_TPAGE *)(poly + 1);
    SetDrawTPage(mode, 0, 1, 0xA0);
    addPrim(ot, mode);
    /* the match depends on ++mode: with mode + 1, the OT and 0xFFFFFF
       outrank mode in the local allocator and take s2 and s3 */
    GFX.funcs.setPrim(++mode);
}

/* The white flash's task: brightens up to full white and holds it, then once
   ended (FIGHTSTG_endWhiteFlash) fades back and dies; draws itself each frame */
void FIGHTSTG_updateWhiteFlash(WhiteFlash *task) {
    switch (task->state) {
    case TASK_INIT: /* the match depends on this case, which default covers */
    default:
        task->nextState(task);
        task->level = 0;
    case TASK_RUN:
        if (task->substate == 0) {
            task->level += task->speed * GFX.funcs.getFrameTime();
            if (task->level >= 0xFF) {
                task->level = 0xFF;
                task->nextSubstate(task);
            }
        }
        break;
    case TASK_DONE:
        task->level -= task->speed * GFX.funcs.getFrameTime();
        if (task->level < 0) {
            task->level = 0;
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_KILL:
        break;
    }
    FIGHTSTG_drawWhiteFlash(task);
}

/* Fades the white flash back out over FRAMES */
void FIGHTSTG_endWhiteFlash(WhiteFlash *task, s32 frames) {
    task->speed = 0xFF / frames;
    task->setState(task, TASK_DONE);
}

/* Starts a white flash that whitens the screen over FRAMES */
WhiteFlash *FIGHTSTG_startWhiteFlash(s32 frames) {
    WhiteFlash *task = createTask(FIGHTSTG_updateWhiteFlash, sizeof(WhiteFlash), 0);

    task->speed = 0xFF / frames;
    return task;
}

/* Every frame: the hp tween of a side whose active fighter changed jumps to
 * that fighter's hp; every interval, a side's tween starts easing (30 frames)
 * to its fighter's hp, clamped to 0 and the max hp, when that changed. The
 * match depends on a counter for each loop and the side's row of fighters. */
void FIGHTSTG_updateHpTweens(HpDisplay *task, TextWindow **windows) {
    s32 hp;
    s32 i;
    s32 j;
    BattleFighter *row;

    task->timer += GFX.funcs.getFrameTime();
    for (i = 0; i < 2; i++) {
        row = FIGHTSTG_battle.fighters[i];
        if (task->hp[i].fighter != FIGHTSTG_battle.active[i]) {
            task->hp[i].from = row[FIGHTSTG_battle.active[i]].hp;
            task->hp[i].to = row[FIGHTSTG_battle.active[i]].hp;
            task->hp[i].value = row[FIGHTSTG_battle.active[i]].hp;
            task->hp[i].active = 0;
            task->hp[i].fighter = FIGHTSTG_battle.active[i];
        }
    }
    if (task->timer > task->interval) {
        task->timer -= task->interval;
        for (j = 0; j < 2; j++) {
            row = FIGHTSTG_battle.fighters[j];
            hp = row[FIGHTSTG_battle.active[j]].hp;
            if (hp <= 0) {
                hp = 0;
            }
            if (hp > row[FIGHTSTG_battle.active[j]].maxHp) {
                hp = row[FIGHTSTG_battle.active[j]].maxHp;
            }
            if (hp != task->hp[j].to) {
                task->hp[j].from = task->hp[j].value;
                task->hp[j].to = hp;
                task->hp[j].active = 1;
                task->hp[j].time = 0;
                task->hp[j].duration = 30;
            }
        }
    }
}

/* Eases an HP number towards its target over its duration, along a sine */
void FIGHTSTG_stepHpTween(HpTween *tween) {
    s32 t;

    if (tween->active != 0) {
        tween->time += GFX.funcs.getFrameTime();
        if (tween->time >= tween->duration) {
            tween->active = 0;
            tween->from = tween->value = tween->to;
        } else {
            t = rsin((tween->time << 10) / tween->duration) * tween->duration / 4096;
            tween->value = tween->from + (tween->to - tween->from) * t / tween->duration;
        }
    }
}

/* Shows the names of both sides' active fighters, when they changed */
void FIGHTSTG_showFighterNames(HpDisplay *task, TextWindow **windows) {
    BattleTableEntry *enemy;
    s32 i;

    if (FIGHTSTG_battle.active[0] != task->shown[0]) {
        if (windows[0] == NULL) {
            windows[0] = createTextWindow(0x1005, 1, 0xAE, 0x15);
        }
        windows[0]->setString(windows[0], GAME.partners[GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0])].info.name, -1);
    }
    if (FIGHTSTG_battle.active[1] != task->shown[1]) {
        enemy = FIGHTSTG_battleTableFunc(BATTLE_SETUP.enemies[FIGHTSTG_battle.active[1]].fighter);
        if (windows[1] == NULL) {
            windows[1] = createTextWindow(0x1005, 1, 0x11, 0x15);
        }
        if (enemy != NULL) {
            windows[1]->setString(windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), enemy->nameId);
        }
    }
    for (i = 0; i < 2; i++) {
        task->shown[i] = FIGHTSTG_battle.active[i];
    }
}

/* FIGHTSTG_drawHud's HP bars, one row per side; the European version swaps
   side 1's ends, so that its bar shrinks toward its right end */
#if VERSION_US
DVECTOR FIGHTSTG_hpBars[2][4] = {
    { { 0xAF, 0x25 }, { 0x12F, 0x25 }, { 0xAF, 0x2B }, { 0x12F, 0x2B } },
    { { 0x0F, 0x25 }, { 0x8F, 0x25 }, { 0x0F, 0x2B }, { 0x8F, 0x2B } },
};
#elif VERSION_EU
DVECTOR FIGHTSTG_hpBars[2][4] = {
    { { 0xAF, 0x25 }, { 0x12F, 0x25 }, { 0xAF, 0x2B }, { 0x12F, 0x2B } },
    { { 0x8F, 0x25 }, { 0x0F, 0x25 }, { 0x8F, 0x2B }, { 0x0F, 0x2B } },
};
#endif
/* the bars' colours: above and at a quarter of the HP */
CVECTOR FIGHTSTG_hpBarColors[4] = {
    { 0x00, 0x71, 0x28, 0x00 },
    { 0x00, 0xC8, 0x3E, 0x00 },
    { 0xB3, 0x37, 0x16, 0x00 },
    { 0xFF, 0x37, 0x0D, 0x00 },
};
/* the technique gauge, and its colours */
DVECTOR FIGHTSTG_techGauge[4] = {
    { 0x109, 0x3E }, { 0x131, 0x3E }, { 0x109, 0x46 }, { 0x131, 0x46 },
};
CVECTOR FIGHTSTG_techGaugeColors[4] = {
    { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
};
/* the fighter icons' x, for each side and slot */
s16 FIGHTSTG_iconX[2][3] = {
    { 0x010F, 0x011A, 0x0125 },
    { 0x0025, 0x001A, 0x000F },
};

/* Draws the battle HUD: both HP bars, the technique gauge (full at 1000) and
   the fighters' icons */
void FIGHTSTG_drawHud(HpDisplay *task, TextWindow **windows) {
    SpriteDrawer drawer;
    CVECTOR colors[4];
    BattleFighter *fighter;
    s32 sheet;
    s32 width;
    s32 blink;
    s32 member;
    s32 frame;
    s32 i;
    s32 side;
    s32 slot;

    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0, 8, 0xF);
    drawer.draw(sheet, 1, 0xA1, 0xF);
    FIGHTSTG_showFighterNames(task, windows);
    fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    if (windows[4] == NULL) {
        windows[4] = createTextWindow(0x1005, 3, 0x10B, 0x1A);
    }
    windows[4]->setNumber(windows[4], 0, task->hp[0].value);
    windows[4]->setRightAlign(windows[4], 1);
    if (windows[3] == NULL) {
        windows[3] = createTextWindow(0x1005, 3, 0x12E, 0x1A);
    }
    windows[3]->setNumber(windows[3], 0, fighter->maxHp);
    windows[3]->setRightAlign(windows[3], 1);
    for (i = 0; i < 2; i++) {
        fighter = &FIGHTSTG_battle.fighters[i][FIGHTSTG_battle.active[i]];
        width = (task->hp[i].value << 7) / fighter->maxHp;
        if (task->hp[i].value > 0 && width < 4) {
            width = 3;
        }
#if VERSION_EU
        /* the match depends on testing i == 0 first (i != 0 gives 13 diffs) */
        if (i == 0) {
            FIGHTSTG_hpBars[i][1].vx = FIGHTSTG_hpBars[i][0].vx + width;
            FIGHTSTG_hpBars[i][3].vx = FIGHTSTG_hpBars[i][2].vx + width;
        } else {
            FIGHTSTG_hpBars[i][1].vx = FIGHTSTG_hpBars[i][0].vx - width;
            FIGHTSTG_hpBars[i][3].vx = FIGHTSTG_hpBars[i][2].vx - width;
        }
#else
        FIGHTSTG_hpBars[i][1].vx = FIGHTSTG_hpBars[i][0].vx + width;
        FIGHTSTG_hpBars[i][3].vx = FIGHTSTG_hpBars[i][2].vx + width;
#endif
        if ((fighter->maxHp >> 2) < task->hp[i].value) {
            colors[0] = colors[2] = FIGHTSTG_hpBarColors[0];
            colors[1] = colors[3] = FIGHTSTG_hpBarColors[1];
        } else {
            colors[0] = colors[2] = FIGHTSTG_hpBarColors[2];
            colors[1] = colors[3] = FIGHTSTG_hpBarColors[3];
        }
        FIGHTSTG_battle.drawQuad(0x1005, 1, FIGHTSTG_hpBars[i], colors);
    }
    blink = (GFX.funcs.getTime() >> 2) & 3;
    member = GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]);
    drawer.draw(sheet, 0x1E, 0x104, 0x3D);
    if (BATTLE_SETUP.gauges[member] < 1000) {
        /* the match depends on storing [2] before [0] (the other order gives 2
           diffs) */
        FIGHTSTG_techGauge[2].vx = FIGHTSTG_techGauge[0].vx = BATTLE_SETUP.gauges[member] / 25 + 0x109;
        FIGHTSTG_battle.drawQuad(0x1005, 1, FIGHTSTG_techGauge, FIGHTSTG_techGaugeColors);
    }
    if (BATTLE_SETUP.gauges[member] < 1000) {
        drawer.draw(sheet, blink + 0x33, 0x109, 0x3E);
    } else {
        drawer.draw(sheet, blink + 0x37, 0x109, 0x3E);
    }
    drawer.draw(sheet, 0xB, 0x104, 0x3D);
    for (side = 0; side < 2; side++) {
        for (slot = 0; slot < 3; slot++) {
            if (FIGHTSTG_battle.kind >= BATTLE_KIND_FINAL && slot > 0 && side > 0) {
                return;
            }
            fighter = &FIGHTSTG_battle.fighters[side][slot];
            if (fighter->id != 0) {
                if (fighter->flags != 0) {
                    frame = 3;
                } else if (fighter->hp == 0) {
                    frame = 2;
                } else {
                    frame = fighter->hp != fighter->maxHp;
                }
                if (FIGHTSTG_battle.active[side] == slot) {
                    frame += 0xC;
                } else {
                    frame += 0x3C;
                }
                drawer.draw(sheet, frame, FIGHTSTG_iconX[side][slot], 0x30);
            }
        }
    }
}

/* The battle HUD's task: makes its windows and starts the HP numbers at the
   fighters' HP, then each frame eases them and draws the HUD
   (FIGHTSTG_drawHud) */
void FIGHTSTG_updateHud(HpDisplay *task, TextWindow **windows) {
    s32 i;
    BattleFighter (*fighters)[3];

    switch (task->state) {
    case TASK_INIT:
    default:
        task->shown[1] = -1;
        task->shown[0] = -1;
        FIGHTSTG_showFighterNames(task, windows);
        windows[2] = createTextWindow(0x1005, 3, 0x10C, 0x1A);
        windows[2]->setString(windows[2], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x10);
        fighters = FIGHTSTG_battle.fighters;
        windows[4] = createTextWindow(0x1005, 3, 0x10B, 0x1A);
        windows[4]->setNumber(windows[4], 0, fighters[0][FIGHTSTG_battle.active[0]].hp);
        windows[4]->setRightAlign(windows[4], 1);
        windows[3] = createTextWindow(0x1005, 3, 0x12E, 0x1A);
        windows[3]->setNumber(windows[3], 0, fighters[0][FIGHTSTG_battle.active[0]].maxHp);
        windows[3]->setRightAlign(windows[3], 1);
        for (i = 0; i < 2; i++) {
            task->hp[i].from = fighters[i][FIGHTSTG_battle.active[i]].hp;
            task->hp[i].to = fighters[i][FIGHTSTG_battle.active[i]].hp;
            task->hp[i].value = fighters[i][FIGHTSTG_battle.active[i]].hp;
            task->hp[i].active = 0;
            task->hp[i].fighter = FIGHTSTG_battle.active[i];
            task->hp[i].time = 0;
            task->hp[i].duration = 0;
        }
        task->timer = 0;
        task->interval = 8;
        task->nextState(task);
        break;
    case TASK_RUN:
        FIGHTSTG_updateHpTweens(task, windows);
        FIGHTSTG_stepHpTween(&task->hp[0]);
        FIGHTSTG_stepHpTween(&task->hp[1]);
        FIGHTSTG_drawHud(task, windows);
        break;
    case TASK_DONE:
        task->nextState(task);
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates the battle HUD (FIGHTSTG_updateHud) */
HpDisplay *FIGHTSTG_createHud(void) {
    return createTask(FIGHTSTG_updateHud, sizeof(HpDisplay), 5 * sizeof(TextWindow *));
}

/* Shows the six commands once, greying out attack, techniques and digivolve
   when the active fighter is asleep and digivolve when it has flag 0x20 (the
   first window's setPalette is called for each) */
void FIGHTSTG_showCommands(CommandMenu *task) {
    CommandMenuWindows *w = task->children;
    BattleFighter *fighter;
    char *text;
    s32 i;

    if (w->lines[0] == NULL) {
        text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
        for (i = 0; i < BATTLE_COMMAND_COUNT; i++) {
            w->lines[i] = createTextWindow(0x1005, 1, 0x24, 0x6D + i * 0x13);
            w->lines[i]->setString(w->lines[i], text, i + 1);
        }
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        if (fighter->flags & FIGHTER_ASLEEP) {
            for (i = 0; i < BATTLE_COMMAND_SWITCH; i++) {
                w->lines[0]->setPalette(w->lines[i], PALETTE_GREY);
            }
        }
        if (fighter->flags & FIGHTER_NO_DIGIVOLVE) {
            w->lines[0]->setPalette(w->lines[BATTLE_COMMAND_DIGIVOLVE], PALETTE_GREY);
        }
    }
}

/* the battle commands' cursor (FIGHTSTG_createCursor makes the menus' cursors from
   these layouts) */
CursorLayout FIGHTSTG_commandCursor = {
    6, 17, 110, 19, 34, 16, 109, 19,
};

/* The command menu's task: puts a cursor (FIGHTSTG_commandCursor) on the
 * lines, starting on start; cross picks the line into *result and locks the
 * cursor, but not the greyed-out ones (FIGHTSTG_showCommands).
 * The match depends on the early exits being breaks out of a do/while. */
void FIGHTSTG_updateCommandMenu(CommandMenu *task, CommandMenuWindows *w) {
    BattleFighter *fighter;

    switch (task->state) {
    case TASK_INIT:
    default:
        w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_commandCursor);
        w->cursor->sel = task->start;
        FIGHTSTG_showCommands(task);
        task->nextState(task);
        break;
    case TASK_RUN:
        do {
            if (!(PAD.getPressed(0) & (1 << PAD_CROSS))) {
                break;
            }
            SOUND.playSound(SOUND_MENU_CONFIRM);
            fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
            if ((fighter->flags & FIGHTER_ASLEEP) && w->cursor->sel < BATTLE_COMMAND_SWITCH) {
                break;
            }
            if ((fighter->flags & FIGHTER_NO_DIGIVOLVE) && w->cursor->sel == BATTLE_COMMAND_DIGIVOLVE) {
                break;
            }
            *task->result = w->cursor->sel;
            task->setState(task, 3);
            w->cursor->locked = 1;
        } while (0);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Opens the battle's command menu with the cursor on start; *result gets
   the command (PlayerTurn.command) */
CommandMenu *FIGHTSTG_createCommandMenu(s32 start, s32 *result) {
    CommandMenu *task = createTask(FIGHTSTG_updateCommandMenu, sizeof(CommandMenu), sizeof(CommandMenuWindows));

    task->result = result;
    *result = -1;
    task->start = start;
    return task;
}

/* Draws the frame around the partner view */
void FIGHTSTG_drawPartnerViewFrame(PartnerView *task, FighterCamera **cameras) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 0);
    drawer.setTexture(0x200, 0);
    drawer.draw(FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16), 10, 246, 74);
}

/* The partner view's task: makes layer 0x1009 beside the menus, then once the
   models are there shows the player's active model on it through a new
   FighterCamera (ending the other one) and draws the frame each frame; when
   killed, takes the model off the layer and destroys it */
void FIGHTSTG_updatePartnerView(PartnerView *task, FighterCamera **cameras) {
    Models *models;
    ModelControl *control;
    FighterCamera *other;
    s32 fighter;

    switch (task->state) {
    case TASK_INIT:
    default:
        FIGHTSTG_fighterCameraRect.x = 0xD0;
        FIGHTSTG_fighterCameraRect.y = 0x4C;
        FIGHTSTG_fighterCameraRect.w = 0x64;
        FIGHTSTG_fighterCameraRect.h = 0x3C;
        task->layer = GFX.funcs.createLayer(&FIGHTSTG_fighterCameraRect, 0xC, 0x1009);
        task->layer->setOffset(task->layer, 0x102, 0x6A);
        task->layer->allocCallbacks(task->layer, 0x32);
        task->nextState(task);
        break;
    case TASK_RUN:
        if (task->substate == 0) {
            models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            if (models != NULL) {
                control = models->get(models, 0);
                control->unk34[1].enabled = 1;
                control->unk34[1].alt = 0;
                control->unk34[1].arg = 0x1009;
                fighter = control->fighter;
                if (cameras[0] == NULL) {
                    cameras[0] = FIGHTSTG_createCamera(fighter, control);
                    other = cameras[1];
                } else {
                    cameras[1] = FIGHTSTG_createCamera(fighter, control);
                    other = cameras[0];
                }
                if (other != NULL) {
                    other->setState(other, 3);
                }
                task->nextSubstate(task);
            }
        }
        FIGHTSTG_drawPartnerViewFrame(task, cameras);
        break;
    case 2:
        task->nextState(task);
        break;
    case TASK_KILL:
        if (task->layer != NULL) {
            models = TASK_REGISTRY.funcs.find(BATTLE_TASK_MODELS, -1, -1);
            models->get(models, 0)->unk34[1].enabled = 0;
            GFX.funcs.destroyLayer(0x1009);
        }
        break;
    }
}

/* Creates the partner view (FIGHTSTG_updatePartnerView), whose children are
   its two cameras */
PartnerView *FIGHTSTG_createPartnerView(void) {
    return createTask(FIGHTSTG_updatePartnerView, sizeof(PartnerView), 2 * sizeof(Task *));
}

/* Shows the names of the Digimon the menu's partner can digivolve into, its
   current one in palette 7 */
void FIGHTSTG_showDigivolveNames(DigivolveMenu *task) {
    TextWindow **windows = task->children;
    BattleFighter *fighter;
    DigimonData *data;
    s32 index;
    s32 current;
    s32 i;

    /* the match depends on setting index in the loop's init */
    for (i = 0, index = -1; i < 3; i++) {
        if (task->partner == GAME.funcs.getPartyMember(i)) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    fighter = &FIGHTSTG_battle.fighters[0][index];
    if (fighter->temporary) {
        current = fighter->prevId;
    } else {
        current = fighter->id;
    }
    for (i = 0; i < task->count; i++) {
        if (windows[i + 1] == NULL) {
            windows[i + 1] = createTextWindow(0x1005, 1, 0xBB, 0x92 + i * 0x13);
        }
        data = GET_DIGIMON(task->ids[i]);
        if (data != NULL) {
            windows[i + 1]->setString(windows[i + 1], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data->nameId);
            if (current == task->ids[i]) {
                windows[i + 1]->setPalette(windows[i + 1], PALETTE_GREY);
            } else {
                windows[i + 1]->setPalette(windows[i + 1], PALETTE_WHITE);
            }
        }
    }
}

/* the cursor of the Digimon a partner can change into (FIGHTSTG_updateDigivolveMenu sets
   its count) */
CursorLayout FIGHTSTG_changeCursor = {
    0, 168, 147, 19, 36, 167, 146, 19,
};

/* The digivolve menu's task: L1 and R1 turn the PartnerInfo's page, cross
   picks one other than the fighter's current Digimon into *result,
   triangle gives -2. The match depends on taking the children as the
   update's void * and copying them: as a parameter of their own type they
   are equivalent to their argument slot, whose doubled live length gives
   their register to changed */
void FIGHTSTG_updateDigivolveMenu(DigivolveMenu *task, void *children) {
    DigivolveMenuWindows *w = children;
    BattleFighter *fighter;
    s32 pressed;
    s32 changed;
    s32 show;
    s32 current;
    s32 id;
    s32 count;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        id = task->partner;
        GAME.funcs.getPartnerSlots(id, task->slots);
        task->ids[0] = DIGIMON_DATA[id].id;
        count = 1;
        for (i = 0; i < 3; i++) {
            if (task->slots[i] >= 3) {
                task->ids[count] = task->slots[i];
                count++;
            }
        }
        task->count = count;
        FIGHTSTG_changeCursor.count = count;
        w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_changeCursor);
        w->info[0] = FIGHTSTG_createPartnerInfo(task->partner, task->page, w->cursor->sel);
        FIGHTSTG_showDigivolveNames(task);
        task->sel = -1;
        task->nextState(task);
        break;
    case TASK_RUN:
        changed = 0;
        show = 1; /* never cleared, but the original tests it */
        /* the match depends on the do-while and its breaks, the stages' early exit */
        do {
            pressed = PAD.getPressed(0);
            if (pressed & (1 << PAD_R1)) {
                if (++task->page == 3) {
                    task->page = 0;
                }
                changed = 1;
                SOUND.playSound(SOUND_MENU_MOVE);
                break;
            }
            if (pressed & (1 << PAD_L1)) {
                if (--task->page < 0) {
                    task->page = 2;
                }
                changed = 1;
                SOUND.playSound(SOUND_MENU_MOVE);
                break;
            }
            if (pressed & (1 << PAD_CROSS)) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                if (fighter->temporary) {
                    current = fighter->prevId;
                } else {
                    current = fighter->id;
                }
                if (current != task->ids[w->cursor->sel]) {
                    *task->result = task->ids[w->cursor->sel];
                    task->setState(task, 3);
                    w->cursor->locked = 1;
                    break;
                }
            }
            if (pressed & (1 << PAD_TRIANGLE)) {
                *task->result = -2;
                task->setState(task, 3);
                SOUND.playSound(SOUND_MENU_CANCEL);
            }
        } while (0);
        if (w->cursor->sel != task->sel) {
            task->sel = w->cursor->sel;
            changed = 1;
        }
        if (changed) {
            if (show) {
                if (w->info[0] != NULL) {
                    w->info[0]->setState(w->info[0], 2);
                    w->info[1] = FIGHTSTG_createPartnerInfo(task->partner, task->page, w->cursor->sel);
                } else {
                    if (w->info[1] != NULL) {
                        w->info[1]->setState(w->info[1], 2);
                    }
                    w->info[0] = FIGHTSTG_createPartnerInfo(task->partner, task->page, w->cursor->sel);
                }
            } else {
                if (w->info[0] != NULL) {
                    w->info[0]->setState(w->info[0], 2);
                }
                if (w->info[1] != NULL) {
                    w->info[1]->setState(w->info[1], 2);
                }
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Opens the menu of the Digimon the partner *result can digivolve into;
   *result gets the one picked, or -2 to go back */
DigivolveMenu *FIGHTSTG_createDigivolveMenu(s32 *result) {
    DigivolveMenu *task = createTask(FIGHTSTG_updateDigivolveMenu, sizeof(DigivolveMenu), sizeof(DigivolveMenuWindows));

    task->result = result;
    task->partner = *result;
    *result = -1;
    return task;
}

/* Draws the PartnerInfo's blinking page arrows */
void FIGHTSTG_drawPageArrows(PartnerInfo *task) {
    SpriteDrawer drawer;
    s32 sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x200, 0);
    if (GFX.funcs.getTime() & 0x10) {
        drawer.draw(sheet, 0x1F, 0x18, 0xAB);
        drawer.draw(sheet, 0x20, 0x48, 0xAB);
    }
}

/* Shows the PartnerInfo's page buttons (texts 0x11 and 0x12) */
void FIGHTSTG_showPageButtons(PartnerInfo *task, TextWindow **windows) {
    void *text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));

    windows[1] = createTextWindow(0x1005, 3, 0x22, 0xAB);
    windows[1]->setString(windows[1], text, 0x11);
    windows[1]->setPalette(windows[1], PALETTE_DARK_BLUE);
    windows[2] = createTextWindow(0x1005, 3, 0x38, 0xAB);
    windows[2]->setString(windows[2], text, 0x12);
    windows[2]->setPalette(windows[2], PALETTE_DARK_BLUE);
}

/* Draws the frame of the stats page */
void FIGHTSTG_drawStatsFrame(PartnerInfo *task) {
    SpriteDrawer drawer;
    s32 sheet;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    sheet = FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16);
    drawer.setTexture(0x140, 0);
    drawer.draw(sheet, 0x23, 0x18, 0x51);
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0x25, 0x10, 0x4A);
}

/* the stat numbers of FIGHTSTG_showStats */
StatLine FIGHTSTG_statLines[13] = {
    { 60, 82, 6 },
    { 60, 96, 7 },
    { 60, 110, 8 },
    { 60, 124, 9 },
    { 60, 138, 10 },
    { 60, 152, 11 },
    { 126, 82, 12 },
    { 126, 96, 13 },
    { 126, 110, 14 },
    { 126, 124, 15 },
    { 126, 138, 16 },
    { 126, 152, 17 },
    { 126, 166, 18 },
};

/* Creates the thirteen stat numbers of FIGHTSTG_statLines (up to 999), right
 * aligned, in palette 6 for windows 5, 6 and 9 when stats 19, 20 and 21 are
 * set. The match depends on reading the stat through a pointer sum. */
void FIGHTSTG_showStats(PartnerInfo *task, TextWindow **windows) {
    s32 i;
    s32 value;

    for (i = 0; i < 13; i++) {
        windows[i + 5] = createTextWindow(0x1005, 1, FIGHTSTG_statLines[i].x, FIGHTSTG_statLines[i].y);
        value = *(task->stats + FIGHTSTG_statLines[i].stat);
        if (value >= 1000) {
            value = 999;
        }
        windows[i + 5]->setNumber(windows[i + 5], 0, value);
        windows[i + 5]->setRightAlign(windows[i + 5], 1);
    }
    if (task->stats[19]) {
        windows[5]->setPalette(windows[5], PALETTE_PURPLE);
    }
    if (task->stats[20]) {
        windows[6]->setPalette(windows[6], PALETTE_PURPLE);
    }
    if (task->stats[21]) {
        windows[9]->setPalette(windows[9], PALETTE_PURPLE);
    }
}

/* Draws the techniques page's icons and frame */
void FIGHTSTG_drawTechIcons(PartnerInfo *task) {
    SpriteDrawer drawer;
    s32 sheet;
    s32 i;
    s32 tech;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    sheet = FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16);
    drawer.setTexture(0x140, 0);
    for (i = 0; i < 6; i++) {
        tech = task->techs[i] & 0x1FFF;
        if (tech != 0) {
            drawer.draw(sheet, TECHS[tech - 1].icon + 0x37, 0x18, 0x51 + i * 0xE);
        }
    }
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0x26, 0x10, 0x4A);
}

/* Shows the techniques page: unk60 (text 0x1A when negative) and the six
   techniques' names, the partner's own in palette 3 and those it can pass on
   in palette 4 */
void FIGHTSTG_showTechs(PartnerInfo *task, TextWindow **windows) {
    void *text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
    s32 i;
    s32 tech;

    windows[3] = createTextWindow(0x1005, 1, 0x5A, 0xA9);
    windows[3]->setString(windows[3], text, 0x19);
    windows[4] = createTextWindow(0x1005, 1, 0x93, 0xA9);
    if (task->unk60 >= 0) {
        windows[4]->setNumber(windows[4], 0, task->unk60);
    } else {
        windows[4]->setString(windows[4], text, 0x1A);
    }
    windows[4]->setRightAlign(windows[4], 1);
    for (i = 0; i < 6; i++) {
        windows[i + 18] = createTextWindow(0x1005, 1, 0x26, 0x51 + i * 0xE);
        tech = task->techs[i];
        if (tech != 0) {
            windows[i + 18]->setString(windows[i + 18], FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)), tech & 0x1FFF);
            if (tech & 0x8000) {
                windows[i + 18]->setPalette(windows[i + 18], PALETTE_YELLOW);
            } else if (tech & 0x4000) {
                windows[i + 18]->setPalette(windows[i + 18], PALETTE_GREEN);
            }
        }
    }
}

/* The PartnerInfo's task: works out its page (the stats with the slot's
   Digimon's added, that Digimon's techniques, or those the partner's other
   Digimon can pass on) and makes its windows, then draws the page each frame */
void FIGHTSTG_updatePartnerInfo(PartnerInfo *task, TextWindow **windows) {
    s32 list[10];
    s32 partner;
    DigimonData *data;
    s32 count;
    s32 tech;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    s32 j;

    switch (task->state) {
    case 0:
    default:
        partner = task->partner;
        switch (task->page) {
        case 0:
            GAME.funcs.computeStats(partner, (PartnerTotals *)task->stats);
            if (task->slot != 0) {
                GAME.funcs.getPartnerSlots(partner, task->slots);
                data = GET_DIGIMON(task->slots[task->slot - 1]);
                /* the match depends on indexing from &task->stats[6] and [12] */
                for (j = 0; j < 6; j++) {
                    (&task->stats[6])[j] += data->battleStats[j];
                }
                for (j = 0; j < 7; j++) {
                    (&task->stats[12])[j] += data->resistances[j];
                }
            }
            break;
        case 1:
            if (task->slot == 0) {
                data = &DIGIMON_DATA[partner];
                task->techs[0] = data->skills[6] | 0x8000;
                task->unk60 = -1;
            } else {
                GAME.funcs.getPartnerSlots(partner, task->slots);
                GAME.funcs.getPartnerEntry(partner, task->slots[task->slot - 1], &task->entries[0]);
                task->unk60 = task->entries[0].unk2;
                for (j = 0, n = 0; j < 6; j++) {
                    if (task->entries[0].techs[j] != 0) {
                        task->techs[n++] = task->entries[0].techs[j];
                    }
                }
            }
            break;
        case 2:
            if (task->slot == 0) {
                task->unk60 = -1;
            } else {
                for (k = 0; k < 10; k++) {
                    list[k] = 0;
                }
                k = 0;
                count = GAME.funcs.getPartnerSlots(partner, task->slots);
                for (i = 0; i < count; i++) {
                    if (GAME.funcs.getPartnerEntry(partner, task->slots[i], &task->entries[i]) >= 0 &&
                        i != task->slot - 1) {
                        for (j = 0; j < 6; j++) {
                            tech = task->entries[i].techs[j];
                            if (tech != 0 && (tech & 0x4000)) {
                                list[k++] = tech & 0x1FFF;
                            }
                        }
                    }
                }
                n = 0;
                for (m = 0; m < 10; m++) {
                    tech = list[m];
                    for (k = 0; k < 6; k++) {
                        if (task->techs[k] == list[m]) {
                            tech = 0;
                            break;
                        }
                    }
                    if (tech != 0) {
                        task->techs[n++] = tech;
                    }
                }
                task->unk60 = task->entries[task->slot - 1].unk2;
            }
            break;
        }
        FIGHTSTG_showPageButtons(task, windows);
        switch (task->page) {
        case 0:
            FIGHTSTG_showStats(task, windows);
            break;
        case 1:
        case 2:
            FIGHTSTG_showTechs(task, windows);
            break;
        }
        task->nextState(task);
        break;
    case 1:
        FIGHTSTG_drawPageArrows(task);
        switch (task->page) {
        case 0:
            FIGHTSTG_drawStatsFrame(task);
            break;
        case 1:
        case 2:
            FIGHTSTG_drawTechIcons(task);
            break;
        }
        break;
    case 2:
        FIGHTSTG_drawPageArrows(task);
        switch (task->page) {
        case 0:
            FIGHTSTG_drawStatsFrame(task);
            break;
        case 1:
        case 2:
            FIGHTSTG_drawTechIcons(task);
            break;
        }
        task->nextState(task);
        break;
    case 3:
        break;
    }
}

/* Shows page page about the partner in slot (0 for itself) */
PartnerInfo *FIGHTSTG_createPartnerInfo(s32 partner, s32 page, s32 slot) {
    PartnerInfo *task = createTask(FIGHTSTG_updatePartnerInfo, sizeof(PartnerInfo), 24 * sizeof(TextWindow *));

    task->partner = partner;
    task->page = page;
    task->slot = slot;
    return task;
}

/* Draws the page's item icons, the page arrows (blinking) and the frame */
void FIGHTSTG_drawItemMenu(ItemMenu *task) {
    SpriteDrawer drawer;
    s32 sheet;
    s32 index;
    s32 i;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x140, 0);
    sheet = FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16);
    for (i = 0; i < ITEM_MENU_LINES; i++) {
        index = task->page * ITEM_MENU_LINES + i;
        if (index > task->count - 1) {
            break;
        }
        drawer.draw(sheet, ITEM_FUNCS->getCategory(task->usable[index]), 0x1D, 0x45 + i * 0xE);
    }
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    if (GFX.funcs.getTime() & 0x10) {
        if (task->page > 0) {
            drawer.draw(sheet, 0x1F, 0x10, 0xA9);
        }
        if (task->page < task->pageCount - 1) {
            drawer.draw(sheet, 0x20, 0x90, 0xA9);
        }
    }
    drawer.draw(sheet, 0x27, 8, 0x3E);
    drawer.draw(sheet, 0x28, 0xA6, 0xA0);
    drawer.draw(sheet, 0x31, 0xB, 0xBC);
}

/* Makes the item menu's windows: the page buttons, the count's label, the
   seven names, the description and the count */
void FIGHTSTG_createItemWindows(ItemMenu *task, ItemMenuWindows *w) {
    char *text;
    s32 i;

    text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
    w->prevButton = createTextWindow(0x1005, 3, 0x1A, 0xA9);
    w->prevButton->setString(w->prevButton, text, 0x11);
    w->prevButton->setPalette(w->prevButton, PALETTE_DARK_BLUE);
    w->nextButton = createTextWindow(0x1005, 3, 0x80, 0xA9);
    w->nextButton->setString(w->nextButton, text, 0x12);
    w->nextButton->setPalette(w->nextButton, PALETTE_DARK_BLUE);
    w->countLabel = createTextWindow(0x1005, 1, 0xAC, 0xA5);
    w->countLabel->setString(w->countLabel, text, 0xC);
    for (i = 0; i < ITEM_MENU_LINES; i++) {
        w->names[i] = createTextWindow(0x1005, 1, 0x2A, 0x45 + i * 0xE);
    }
    w->message = createTextWindow(0x1005, 1, 0x14, 0xC2);
    w->count = createTextWindow(0x1005, 1, 0xC6, 0xA5);
}

/* Shows the page's names and the description and count of the item under
   the cursor, or text 0x15 and 0x1A when there are none */
void FIGHTSTG_showItemPage(ItemMenu *task, ItemMenuWindows *w) {
    s32 index;
    s32 item;
    s32 i;

    if (task->count != 0) {
        for (i = 0; i < ITEM_MENU_LINES; i++) {
            index = task->page * ITEM_MENU_LINES + i;
            if (index > task->count - 1) {
                w->names[i]->setVisible(w->names[i], 0);
            } else {
                item = task->usable[index];
                if (item != 0) {
                    w->names[i]->setString(w->names[i], FILE_CACHE.load(TEXT_FILE(TEXT_ITEM_NAMES)), item);
                }
            }
        }
        item = task->usable[task->page * ITEM_MENU_LINES + w->cursor->sel];
        w->message->setString(w->message, FILE_CACHE.load(TEXT_FILE(TEXT_ITEM_INFO)), item);
        w->count->setNumber(w->count, 0, GAME.items[item]);
    } else {
        w->message->setString(w->message, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x15);
        w->count->setString(w->count, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x1A);
    }
    w->count->setRightAlign(w->count, 1);
}

/* the cursors of the items' (FIGHTSTG_updateItemMenu), the techniques'
   (FIGHTSTG_updateTechMenu) and the partner switch's (FIGHTSTG_updateSwitchMenu) menus */
CursorLayout FIGHTSTG_itemCursor = {
    1, 14, 69, 14, -1, 0, 0, 0,
};
CursorLayout FIGHTSTG_techCursor = {
    1, 14, 69, 14, -1, 0, 0, 0,
};
CursorLayout FIGHTSTG_switchCursor = {
    2, 17, 78, 32, 47, 16, 77, 32,
};

/* The item menu's task: lists the items usable in battle (flag 2), then L1
   and R1 turn the pages, cross picks the item under the cursor into *result
   and triangle gives -2; frees the list when killed */
void FIGHTSTG_updateItemMenu(ItemMenu *task, ItemMenuWindows *w) {
    s32 total;
    s32 pressed;
    s32 page;
    s32 rows;
    s32 n;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        total = ITEM_FUNCS->list(1, (u16 *)task->items);
        task->count = 0;
        for (i = 0; i < total; i++) {
            if (task->items[i] == 0) {
                break;
            }
            if (*GET_ITEM[0](task->items[i])->data & 2) {
                task->count++;
            }
        }
        if (task->count != 0) {
            task->usable = HEAP.alloc(task->count * 2, 2);
            n = 0;
            for (i = 0; i < total; i++) {
                if (task->items[i] == 0) {
                    break;
                }
                if (*GET_ITEM[0](task->items[i])->data & 2) {
                    task->usable[n++] = task->items[i];
                }
            }
            if (task->count % ITEM_MENU_LINES != 0) {
                task->pageCount = task->count / ITEM_MENU_LINES + 1;
            } else {
                task->pageCount = task->count / ITEM_MENU_LINES;
            }
            if (task->count != 0) {
                if (task->count > ITEM_MENU_LINES) {
                    FIGHTSTG_itemCursor.count = ITEM_MENU_LINES;
                } else {
                    FIGHTSTG_itemCursor.count = task->count;
                }
            }
        }
        w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_itemCursor);
        FIGHTSTG_createItemWindows(task, w);
        FIGHTSTG_showItemPage(task, w);
        task->nextState(task);
        break;
    case TASK_RUN:
        FIGHTSTG_drawItemMenu(task);
        pressed = PAD.getPressed(0);
        page = task->page;
        if (task->pageCount != 0) {
            if (pressed & (1 << PAD_L1)) {
                if (--task->page < 0) {
                    task->page = 0;
                }
            } else if (pressed & (1 << PAD_R1)) {
                if (++task->page > task->pageCount - 1) {
                    task->page = task->pageCount - 1;
                }
            }
        }
        if (page != task->page) {
            w->cursor->sel = 0;
            rows = task->count - task->page * ITEM_MENU_LINES;
            if (rows > ITEM_MENU_LINES) {
                rows = ITEM_MENU_LINES;
            }
            w->cursor->params.count = rows;
            FIGHTSTG_showItemPage(task, w);
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (task->sel != w->cursor->sel) {
            FIGHTSTG_showItemPage(task, w);
        } else if (pressed & (1 << PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            if (task->count != 0) {
                *task->result = task->usable[task->page * ITEM_MENU_LINES + w->cursor->sel];
                task->setState(task, 3);
                w->cursor->locked = 1;
                break;
            }
        } else if (pressed & (1 << PAD_TRIANGLE)) {
            /* the match depends on the goto, which puts the cancel after the
               cursor's line */
            goto cancel;
        }
        task->sel = w->cursor->sel;
        break;
    cancel:
        SOUND.playSound(SOUND_MENU_CANCEL);
        *task->result = -2;
        task->setState(task, 3);
        break;
    case 2:
        break;
    case 3:
        if (task->usable != NULL) {
            HEAP.free(task->usable);
        }
        break;
    }
}

/* Opens the battle's item menu; *result gets the item picked, or -2 to go
   back */
ItemMenu *FIGHTSTG_createItemMenu(s32 *result) {
    ItemMenu *task = createTask(FIGHTSTG_updateItemMenu, sizeof(ItemMenu), sizeof(ItemMenuWindows));

    task->result = result;
    *result = -1;
    return task;
}

/* Draws the page's technique icons, the page arrows (blinking) and the frame */
void FIGHTSTG_drawTechMenu(TechMenu *task) {
    SpriteDrawer drawer;
    s32 sheet;
    s32 index;
    s32 tech;
    s32 i;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x140, 0);
    sheet = FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16);
    for (i = 0; i < TECH_MENU_LINES; i++) {
        index = task->page * TECH_MENU_LINES + i;
        if (index < task->count) {
            tech = task->techs[index] & 0x1FFF;
            if (tech == 0) {
                break;
            }
            drawer.draw(sheet, TECHS[tech - 1].icon + 0x37, 0x1D, 0x45 + i * 0xE);
        }
    }
    drawer.setTexture(0x200, 0);
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    if (GFX.funcs.getTime() & 0x10) {
        if (task->page > 0) {
            drawer.draw(sheet, 0x1F, 0x10, 0x9F);
        }
        if (task->page < task->pageCount - 1) {
            drawer.draw(sheet, 0x20, 0x90, 0x9F);
        }
    }
    drawer.draw(sheet, 0x2A, 8, 0x3E);
    drawer.draw(sheet, 0x29, 0xA3, 0x21);
    drawer.draw(sheet, 0x31, 0xB, 0xBC);
}

/* Makes the technique menu's windows: the page buttons, the active fighter's
   MP over its max (or a text by its MP for a temporary Digimon), the six
   names, the description and the technique's MP cost */
void FIGHTSTG_createTechWindows(TechMenu *task, TechMenuChild *children) {
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    void *text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
    s32 i;

    children[1].window = createTextWindow(0x1005, 3, 0x1A, 0x9F);
    children[1].window->setString(children[1].window, text, 0x11);
    children[1].window->setPalette(children[1].window, PALETTE_DARK_BLUE);
    children[2].window = createTextWindow(0x1005, 3, 0x80, 0x9F);
    children[2].window->setString(children[2].window, text, 0x12);
    children[2].window->setPalette(children[2].window, PALETTE_DARK_BLUE);
    children[3].window = createTextWindow(0x1005, 3, 0xAC, 0x3A);
    children[3].window->setString(children[3].window, text, 0xD);
    children[6].window = createTextWindow(0x1005, 3, 0xD8, 0x3A);
    if (fighter->temporary) {
        if (fighter->mp < 100) {
            children[6].window->setString(children[6].window, text, 0x1A);
        } else if (fighter->mp < 1000) {
            children[6].window->setString(children[6].window, text, 0xF);
        } else {
            children[6].window->setString(children[6].window, text, 0x24);
        }
    } else {
        children[6].window->setNumber(children[6].window, 0, fighter->mp);
    }
    children[6].window->setRightAlign(children[6].window, 1);
    children[5].window = createTextWindow(0x1005, 3, 0xD9, 0x3A);
    children[5].window->setString(children[5].window, text, 0x10);
    children[4].window = createTextWindow(0x1005, 3, 0xFB, 0x3A);
    children[4].window->setNumber(children[4].window, 0, fighter->maxMp);
    children[4].window->setRightAlign(children[4].window, 1);
    for (i = 0; i < TECH_MENU_LINES; i++) {
        children[7 + i].window = createTextWindow(0x1005, 1, 0x2A, 0x45 + i * 0xE);
    }
    children[13].window = createTextWindow(0x1005, 1, 0x14, 0xC2);
    children[14].window = createTextWindow(0x1005, 1, 0x100, 0xD0);
    children[15].window = createTextWindow(0x1005, 1, 0x12B, 0xD0);
}

/* Shows the page's techniques (palette 7 for those the fighter lacks the MP
   for, 3 its signature one, 4 those passed on) and the description and MP
   cost of the one under the cursor, or text 0x13 when there are none */
void FIGHTSTG_showTechPage(TechMenu *task, TechMenuChild *children) {
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    s32 index;
    s32 tech;
    s32 mp;
    s32 i;

    if (task->count != 0) {
        for (i = 0; i < TECH_MENU_LINES; i++) {
            index = task->page * TECH_MENU_LINES + i;
            if (index > task->count - 1) {
                children[7 + i].window->setVisible(children[7 + i].window, 0);
            } else {
                tech = task->techs[index];
                children[7 + i].window->setString(children[7 + i].window, FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)), tech & 0x1FFF);
                mp = FIGHTSTG_battleFuncs.getTechCost(0, tech);
                if (fighter->temporary) {
                    if (tech & 0x8000) {
                        children[7 + i].window->setPalette(children[7 + i].window, PALETTE_YELLOW);
                    } else if (tech & 0x4000) {
                        children[7 + i].window->setPalette(children[7 + i].window, PALETTE_GREEN);
                    } else {
                        children[7 + i].window->setPalette(children[7 + i].window, PALETTE_WHITE);
                    }
                } else if (fighter->mp < mp) {
                    children[7 + i].window->setPalette(children[7 + i].window, PALETTE_GREY);
                } else if (tech & 0x8000) {
                    children[7 + i].window->setPalette(children[7 + i].window, PALETTE_YELLOW);
                } else if (tech & 0x4000) {
                    children[7 + i].window->setPalette(children[7 + i].window, PALETTE_GREEN);
                } else {
                    children[7 + i].window->setPalette(children[7 + i].window, PALETTE_WHITE);
                }
            }
        }
        mp = FIGHTSTG_battleFuncs.getTechCost(0, task->techs[task->page * TECH_MENU_LINES + children[0].cursor->sel]);
        tech = task->techs[task->page * TECH_MENU_LINES + children[0].cursor->sel];
        if (fighter->temporary == 0 && fighter->mp < mp) {
            children[13].window->setString(children[13].window, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x54);
            children[14].window->setString(children[14].window, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0xD);
            children[14].window->setPalette(children[14].window, PALETTE_GREY);
            children[15].window->setNumber(children[15].window, 0, mp);
            children[15].window->setRightAlign(children[15].window, 1);
            children[15].window->setPalette(children[15].window, PALETTE_GREY);
        } else {
            children[13].window->setString(children[13].window, FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_INFO)), tech & 0x1FFF);
            children[14].window->setString(children[14].window, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0xD);
            children[15].window->setNumber(children[15].window, 0, mp);
            children[15].window->setRightAlign(children[15].window, 1);
            if (tech & 0x4000) {
                children[14].window->setPalette(children[14].window, PALETTE_GREEN);
                children[15].window->setPalette(children[15].window, PALETTE_GREEN);
            } else {
                children[14].window->setPalette(children[14].window, PALETTE_WHITE);
                children[15].window->setPalette(children[15].window, PALETTE_WHITE);
            }
        }
    } else {
        children[13].window->setString(children[13].window, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x13);
    }
}

/* The battle's technique menu: the active fighter's techniques (a Digimon of
   a partner's slots has its entry's, its signature one and the ones the other
   entries can pass on), six a page. L1 and R1 turn the pages, cross picks
   the technique under the cursor into *result, spending its MP (a temporary
   Digimon spends none), and triangle gives -2 */
void FIGHTSTG_updateTechMenu(TechMenu *task, TechMenuChild *children) {
    s32 extra[10];
    BattleFighter *fighter;
    BattleFighter *active;
    DigimonData *data;
    s32 member;
    s32 id;
    s32 slots;
    s32 found;
    s32 count;
    s32 tech;
    s32 pressed;
    s32 page;
    s32 lines;
    s32 mp;
    s32 i;
    s32 j;

    switch (task->state) {
    case TASK_INIT:
    default:
        member = GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]);
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        id = fighter->id;
        if (id == DIGIMON_DATA[member].id) {
            task->techs[0] = DIGIMON_DATA[member].skills[6] | 0x8000;
            task->count = 1;
        } else {
            slots = GAME.funcs.getPartnerSlots(member, task->slots);
            task->count = 0;
            for (i = 0; i < slots; i++) {
                GAME.funcs.getPartnerEntry(member, task->slots[i], &task->entries[i]);
                if (id == task->entries[i].id) {
                    for (j = 0; j < 6; j++) {
                        if (task->entries[i].techs[j] != 0) {
                            task->techs[task->count++] = (s16)(task->entries[i].techs[j] & ~0x4000);
                        }
                    }
                }
            }
            if (fighter->temporary != 0) {
                data = GET_DIGIMON(fighter->id);
                found = 0;
                for (j = 0; j < task->count; j++) {
                    if ((task->techs[j] & 0x1FFF) == data->skills[6]) {
                        task->techs[j] = (task->techs[j] & 0x1FFF) | 0x8000;
                        found = -1;
                        break;
                    }
                }
                if (found != -1) {
                    task->techs[task->count++] = data->skills[6] | 0x8000;
                }
            }
            /* the techniques the other entries can pass on */
            for (j = 9; j >= 0; j--) {
                extra[j] = 0;
            }
            count = 0;
            for (i = 0; i < slots; i++) {
                if (id != task->entries[i].id) {
                    for (j = 0; j < 6; j++) {
                        if (task->entries[i].techs[j] & 0x4000) {
                            extra[count++] = task->entries[i].techs[j];
                        }
                    }
                }
            }
            for (j = 0; j < count; j++) {
                tech = extra[j] & 0x1FFF;
                for (i = 0; i < task->count; i++) {
                    if (tech == (task->techs[i] & 0x1FFF)) {
                        tech = 0;
                        break;
                    }
                }
                if (tech != 0) {
                    task->techs[task->count++] = extra[j];
                }
            }
        }
        if (task->count != 0) {
            if (task->count % TECH_MENU_LINES != 0) {
                task->pageCount = task->count / TECH_MENU_LINES + 1;
            } else {
                task->pageCount = task->count / TECH_MENU_LINES;
            }
        }
        if (task->count != 0) {
            if (task->count > TECH_MENU_LINES) {
                FIGHTSTG_techCursor.count = TECH_MENU_LINES;
            } else {
                FIGHTSTG_techCursor.count = task->count;
            }
        }
#if VERSION_EU
        else {
            FIGHTSTG_techCursor.count = 1;
        }
#endif
        children[0].cursor = FIGHTSTG_createCursor(&FIGHTSTG_techCursor);
        FIGHTSTG_createTechWindows(task, children);
        FIGHTSTG_showTechPage(task, children);
        task->nextState(task);
        break;
    case TASK_RUN:
        FIGHTSTG_drawTechMenu(task);
        /* the match depends on the do-while and its breaks, which skip the
           update of sel, the stages' early exit */
        do {
            pressed = PAD.getPressed(0);
            page = task->page;
            if (task->pageCount != 0) {
                if (pressed & (1 << PAD_L1)) {
                    if (--task->page < 0) {
                        task->page = 0;
                    }
                } else if (pressed & (1 << PAD_R1)) {
                    if (++task->page > task->pageCount - 1) {
                        task->page = task->pageCount - 1;
                    }
                }
            }
            if (page != task->page) {
                children[0].cursor->sel = 0;
                lines = task->count - task->page * TECH_MENU_LINES;
                if (lines > TECH_MENU_LINES) {
                    lines = TECH_MENU_LINES;
                }
                children[0].cursor->params.count = lines;
                FIGHTSTG_showTechPage(task, children);
                SOUND.playSound(SOUND_MENU_MOVE);
            } else if (task->sel != children[0].cursor->sel) {
                FIGHTSTG_showTechPage(task, children);
            } else if (pressed & (1 << PAD_CROSS)) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                if (task->count != 0) {
                    active = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                    /* the match depends on the choice written in both branches */
                    if (active->temporary != 0) {
                        *task->result = task->techs[task->page * TECH_MENU_LINES + children[0].cursor->sel] & 0x1FFF;
                        task->setState(task, 3);
                        children[0].cursor->locked = 1;
                        break;
                    }
                    mp = FIGHTSTG_battleFuncs.getTechCost(0, task->techs[task->page * TECH_MENU_LINES + children[0].cursor->sel]);
                    if (active->mp >= mp) {
                        active->mp -= mp;
                        *task->result = task->techs[task->page * TECH_MENU_LINES + children[0].cursor->sel] & 0x1FFF;
                        task->setState(task, 3);
                        children[0].cursor->locked = 1;
                        break;
                    }
                }
            } else if (pressed & (1 << PAD_TRIANGLE)) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                *task->result = -2;
                task->setState(task, 3);
                break;
            }
            task->sel = children[0].cursor->sel;
        } while (0);
        break;
    case 2:
    case 3:
        break;
    }
}

/* Opens the battle's technique menu; *result gets the technique picked, or
   -2 to go back */
TechMenu *FIGHTSTG_createTechMenu(s32 *result) {
    TechMenu *task = createTask(FIGHTSTG_updateTechMenu, sizeof(TechMenu), 16 * sizeof(TechMenuChild));

    task->result = result;
    *result = -1;
    return task;
}

/* Returns the Digimon fighter index has a pair technique with (its unk3D, a
   1-based DIGIMON_DATA entry) when party member member has it among its
   digivolutions, else 0 */
s32 FIGHTSTG_getPairDigimon(SwitchMenu *task, s32 index, s32 member) {
    BattleFighter *fighter;
    s32 partner;
    s32 next;
    s32 count;
    s32 i;

    GAME.funcs.getPartyMember(index);
    partner = GAME.funcs.getPartyMember(member);
    fighter = &FIGHTSTG_battle.fighters[0][index];
    next = GET_DIGIMON(fighter->id)->unk3D;
    count = GAME.funcs.getPartnerSlots(partner, task->slots);
    if (count <= 0 || next == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        if (task->slots[i] == DIGIMON_DATA[next - 1].id) {
            return next;
        }
    }
    return 0;
}

/* Draws the pair technique icon by the fighters that have one with the active
   fighter */
void FIGHTSTG_drawSwitchMenu(SwitchMenu *task) {
    SpriteDrawer drawer;
    s32 sheet;
    s32 i;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    for (i = 0; i < task->count; i++) {
        if (task->pairs[i] != 0) {
            drawer.draw(sheet, 0x30, 0x5A, 0x45 + i * 0x1F);
        }
    }
}

/* Makes the switch menu's windows, two lines a fighter: the name, HP over max
   HP and MP over max MP */
void FIGHTSTG_createSwitchWindows(SwitchMenu *task, SwitchMenuWindows *w) {
    char *text;
    s32 i;

    text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
    for (i = 0; i < task->count; i++) {
        w->hpLabel[i] = createTextWindow(0x1005, 3, 0x6C, 0x4E + i * 0x20);
        w->hpLabel[i]->setString(w->hpLabel[i], text, 14);
        w->hpSlash[i] = createTextWindow(0x1005, 3, 0x99, 0x4E + i * 0x20);
        w->hpSlash[i]->setString(w->hpSlash[i], text, 16);
        w->mpLabel[i] = createTextWindow(0x1005, 3, 0x6C, 0x5C + i * 0x20);
        w->mpLabel[i]->setString(w->mpLabel[i], text, 13);
        w->mpSlash[i] = createTextWindow(0x1005, 3, 0x99, 0x5C + i * 0x20);
        w->mpSlash[i]->setString(w->mpSlash[i], text, 16);
        w->hp[i] = createTextWindow(0x1005, 3, 0x98, 0x4E + i * 0x20);
        w->maxHp[i] = createTextWindow(0x1005, 3, 0xBB, 0x4E + i * 0x20);
        w->mp[i] = createTextWindow(0x1005, 3, 0x98, 0x5C + i * 0x20);
        w->maxMp[i] = createTextWindow(0x1005, 3, 0xBB, 0x5C + i * 0x20);
        w->name[i] = createTextWindow(0x1005, 1, 0x24, 0x4C + i * 0x20);
    }
}

/* Shows the switch menu's fighters' names, HP and MP, the knocked out ones'
   names in palette 7 */
void FIGHTSTG_showSwitchFighters(SwitchMenu *task, SwitchMenuWindows *w) {
    BattleFighter *fighter;
    s32 i;

    for (i = 0; i < task->count; i++) {
        fighter = &FIGHTSTG_battle.fighters[0][task->others[i]];
        w->hp[i]->setNumber(w->hp[i], 0, fighter->hp);
        w->hp[i]->setRightAlign(w->hp[i], 1);
        w->maxHp[i]->setNumber(w->maxHp[i], 0, fighter->maxHp);
        w->maxHp[i]->setRightAlign(w->maxHp[i], 1);
        w->mp[i]->setNumber(w->mp[i], 0, fighter->mp);
        w->mp[i]->setRightAlign(w->mp[i], 1);
        w->maxMp[i]->setNumber(w->maxMp[i], 0, fighter->maxMp);
        w->maxMp[i]->setRightAlign(w->maxMp[i], 1);
        w->name[i]->setString(w->name[i], GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(task->others[i])), -1);
        if (fighter->hp == 0) {
            w->name[i]->setPalette(w->name[i], PALETTE_GREY);
        } else {
            w->name[i]->setPalette(w->name[i], PALETTE_WHITE);
        }
    }
}

/* The switch menu's task: puts a cursor on the other fighters, starting on
   *line; cross picks one with HP into *result, triangle gives -2 when it
   can cancel. With none to pick it shows message 0x14 and its blinking
   arrow until cross gives -2 */
void FIGHTSTG_updateSwitchMenu(SwitchMenu *task, SwitchMenuWindows *w) {
    SpriteDrawer drawer;
    BattleFighter *fighters;
    BattleFighter *fighter;
    s32 pressed;
    s32 sel;
    s32 active;
    s32 temporary;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        active = FIGHTSTG_battle.active[0];
        fighters = FIGHTSTG_battle.fighters[0];
        temporary = fighters[active].temporary;
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && i != FIGHTSTG_battle.active[0]) {
                task->others[task->count] = i;
                if (task->canCancel != 0 && temporary == 0) {
                    task->pairs[task->count] = FIGHTSTG_getPairDigimon(task, FIGHTSTG_battle.active[0], i);
                }
                task->count++;
            }
        }
        if (task->count > 0) {
            FIGHTSTG_switchCursor.count = task->count;
            w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_switchCursor);
            w->cursor->sel = *task->line;
            FIGHTSTG_createSwitchWindows(task, w);
            FIGHTSTG_showSwitchFighters(task, w);
            task->nextState(task);
        } else {
            w->message = createTextWindow(0x1005, 1, 0x14, 0xC2);
            w->message->setVisible(w->message, 0);
            task->setState(task, 2);
        }
        break;
    case TASK_RUN:
        FIGHTSTG_drawSwitchMenu(task);
        /* the match depends on the do-while and its break, the stages' early exit */
        do {
            pressed = PAD.getPressed(0);
            if (task->canCancel != 0 && (pressed & (1 << PAD_TRIANGLE))) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                *task->result = -2;
                task->setState(task, 3);
                break;
            }
            if (pressed & (1 << PAD_CROSS)) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                sel = w->cursor->sel;
                fighter = &FIGHTSTG_battle.fighters[0][task->others[sel]];
                if (fighter->hp != 0) {
                    *task->line = sel;
                    *task->result = task->others[w->cursor->sel];
                    task->setState(task, 3);
                    w->cursor->locked = 1;
                }
            }
        } while (0);
        break;
    case 2:
        if (PAD.getPressed(0) & (1 << PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            *task->result = -2;
            task->setState(task, 3);
            w->message->setVisible(w->message, 0);
            break;
        }
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1005, 1);
        if (task->arrowShown != 0) {
            if (GFX.funcs.getTime() - task->arrowTime >= 4) {
                task->arrowTime = GFX.funcs.getTime();
                task->arrowPalette++;
                if (task->arrowPalette >= 5) {
                    task->arrowPalette = 0;
                }
            }
            drawer.setTexture(0x140, 0);
            drawer.setClutRow(task->arrowPalette);
            drawer.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 10, 0x123, 0xD0);
            drawer.setClutRow(0);
        } else {
            task->arrowShown = 1;
        }
        drawer.setTexture(0x200, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16), 0x31, 0xB, 0xBC);
        if (!w->message->isVisible(w->message)) {
            w->message->setString(w->message, FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x14);
        }
        break;
    case 3:
        break;
    }
}

/* Opens the switch menu; *result gets the fighter to bring in, or -2 */
SwitchMenu *FIGHTSTG_createSwitchMenu(s32 *result, s32 *line, s32 canCancel) {
    SwitchMenu *task = createTask(FIGHTSTG_updateSwitchMenu, sizeof(SwitchMenu), sizeof(SwitchMenuWindows));

    task->result = result;
    *result = -1;
    task->line = line;
    task->canCancel = canCancel;
    return task;
}

/* Draws the switch-in menu's frames, the second one with the pair technique */
void FIGHTSTG_drawSwitchInMenu(SwitchInMenu *task) {
    SpriteDrawer drawer;
    s32 sheet;

    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0x2B, 0xA7, 0x8F);
    if (task->tech != 0) {
        drawer.draw(sheet, 2, 0xA7, 0xB8);
        drawer.draw(sheet, 0x29, 0xA3, 0x21);
    }
}

/* Makes the switch-in menu's windows: the four names, the choices and the MP */
void FIGHTSTG_createSwitchInWindows(SwitchInMenu *task, SwitchInMenuWindows *w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        w->names[i] = createTextWindow(0x1005, 1, 0xBB, 0x92 + i * 0x13);
    }
    w->choices[4] = createTextWindow(0x1005, 1, 0xAB, 0x92);
    w->choices[0] = createTextWindow(0x1005, 1, 0xBB, 0xA5);
    w->choices[1] = createTextWindow(0x1005, 1, 0xBB, 0xB8);
    w->choices[2] = createTextWindow(0x1005, 3, 0x10E, 0xBA);
    w->choices[3] = createTextWindow(0x1005, 3, 0x133, 0xBA);
    for (i = 0; i < 4; i++) {
        w->mp[i] = createTextWindow(0x1005, 3, FIGHTSTG_mpWindowX[i], 0x39);
    }
}

/* Shows the names of the incoming partner's Digimon, or hides them */
void FIGHTSTG_showSwitchInNames(SwitchInMenu *task, SwitchInMenuWindows *w, s32 visible) {
    DigimonData *data;
    s32 i;

    if (visible) {
        for (i = 0; i < task->count; i++) {
            data = GET_DIGIMON(task->ids[i]);
            if (data != NULL) {
                w->names[i]->setString(w->names[i], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data->nameId);
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (w->names[i] != NULL) {
                w->names[i]->setVisible(w->names[i], visible);
            }
        }
    }
}

/* Shows the picked Digimon's name and the choices, switching in palette 7
   when flag 0x10 bars it and the pair technique in palette 7 when it can't be
   done, with its MP cost and the active fighter's MP; or hides them */
void FIGHTSTG_showSwitchInChoices(SwitchInMenu *task, SwitchInMenuWindows *w, s32 visible) {
    char *text;
    BattleFighter *active;
    BattleFighter *other;
    DigimonData *data;
    s32 i;

    text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
    if (visible) {
        active = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        other = &FIGHTSTG_battle.fighters[0][task->fighter];
        data = GET_DIGIMON(task->ids[task->digimon]);
        w->choices[4]->setString(w->choices[4], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data->nameId);
        w->choices[0]->setString(w->choices[0], text, 0x1B);
        if ((active->flags & FIGHTER_NO_SWITCH) || (other->flags & FIGHTER_NO_SWITCH)) {
            w->choices[0]->setPalette(w->choices[0], PALETTE_GREY);
        } else {
            w->choices[0]->setPalette(w->choices[0], PALETTE_WHITE);
        }
        if (task->tech != 0) {
            w->choices[1]->setString(w->choices[1], text, 0x1C);
            w->choices[2]->setString(w->choices[2], text, 0xD);
            w->choices[3]->setNumber(w->choices[3], 0, TECHS[task->tech - 1].mp);
            w->choices[3]->setRightAlign(w->choices[3], 1);
            if (active->mp < TECHS[task->tech - 1].mp || other->mp < TECHS[task->tech - 1].mp) {
                w->choices[1]->setPalette(w->choices[1], PALETTE_GREY);
            } else if ((active->flags & FIGHTER_NO_DIGIVOLVE) || (other->flags & FIGHTER_NO_DIGIVOLVE) || (active->flags & FIGHTER_ASLEEP)) {
                w->choices[1]->setPalette(w->choices[1], PALETTE_GREY);
            } else if (active->hp <= 0 || other->hp <= 0) {
                w->choices[1]->setPalette(w->choices[1], PALETTE_GREY);
            } else {
                w->choices[1]->setPalette(w->choices[1], PALETTE_WHITE);
            }
            w->mp[0]->setString(w->mp[0], text, 0xD);
            w->mp[1]->setNumber(w->mp[1], 0, active->mp);
            w->mp[1]->setRightAlign(w->mp[1], 1);
            w->mp[2]->setString(w->mp[2], text, 0x10);
            w->mp[3]->setNumber(w->mp[3], 0, active->maxMp);
            w->mp[3]->setRightAlign(w->mp[3], 1);
        }
    } else {
        for (i = 0; i < 5; i++) {
            if (w->choices[i] != NULL) {
                w->choices[i]->setVisible(w->choices[i], visible);
            }
        }
        for (i = 0; i < 4; i++) {
            if (w->mp[i] != NULL) {
                w->mp[i]->setVisible(w->mp[i], visible);
            }
        }
    }
}

/* the cursors of FIGHTSTG_updateSwitchInMenu's two steps */
CursorLayout FIGHTSTG_pairCursors[2] = {
    { 4, 168, 147, 19, 36, 167, 146, 19 },
    { 2, 168, 166, 19, 34, 167, 165, 19 },
};
/* the x of FIGHTSTG_createSwitchInWindows's MP windows */
s32 FIGHTSTG_mpWindowX[4] = {
    0xAC, 0xD8, 0xD9, 0xFB,
};

/* The switch-in menu's task: L1 and R1 turn the PartnerInfo's page, cross
   picks the Digimon, then switching (not with flag 0x10 on either fighter)
   or the pair technique (with the MP, HP and none of flag 0x20 or sleep),
   which spends both fighters' MP; triangle goes back a step */
void FIGHTSTG_updateSwitchInMenu(SwitchInMenu *task, SwitchInMenuWindows *w) {
    BattleFighter *active;
    BattleFighter *other;
    DigimonData *data;
    DigimonData *partner;
    s32 member;
    s32 pressed;
    s32 count;
    s32 changed;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        member = task->partner;
        GAME.funcs.getPartnerSlots(member, task->slots);
        count = 1;
        task->ids[0] = DIGIMON_DATA[member].id;
        for (i = 0; i < 3; i++) {
            if (task->slots[i] >= 3) {
                task->ids[count] = task->slots[i];
                count++;
            }
        }
        task->count = count;
        FIGHTSTG_pairCursors[0].count = count;
        FIGHTSTG_createSwitchInWindows(task, w);
        task->shownPage = -1;
        task->nextState(task);
        /* fallthrough */
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            switch (task->step) {
            case 0:
            default:
                w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_pairCursors[0]);
                w->cursor->sel = task->digimon;
                if (w->techCursor != NULL) {
                    w->techCursor->setState(w->techCursor, 3);
                }
                task->nextStep(task);
                break;
            case 1:
                /* the match depends on the do-while and its breaks, the stages' early
                   exit, here and in the technique menu below */
                do {
                    pressed = PAD.getPressed(0);
                    if (pressed & (1 << PAD_TRIANGLE)) {
                        SOUND.playSound(SOUND_MENU_CANCEL);
                        *task->result = -2;
                        task->setState(task, 3);
                        break;
                    }
                    if (pressed & (1 << PAD_CROSS)) {
                        SOUND.playSound(SOUND_MENU_CONFIRM);
                        task->nextSubstate(task);
                        FIGHTSTG_showSwitchInNames(task, w, 0);
                        w->cursor->locked = 1;
                        break;
                    }
                    if (pressed & (1 << PAD_R1)) {
                        if (++task->page == 3) {
                            task->page = 0;
                        }
                        SOUND.playSound(SOUND_MENU_MOVE);
                        break;
                    }
                    if (pressed & (1 << PAD_L1)) {
                        if (--task->page < 0) {
                            task->page = 2;
                        }
                        SOUND.playSound(SOUND_MENU_MOVE);
                        break;
                    }
                    FIGHTSTG_showSwitchInNames(task, w, 1);
                    FIGHTSTG_showSwitchInChoices(task, w, 0);
                } while (0);
                break;
            }
            break;
        case 1:
            switch (task->step) {
            case 0:
            default:
                if (FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]].temporary == 0) {
                    data = GET_DIGIMON(FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]].id);
                    partner = GET_DIGIMON(task->ids[task->digimon]);
                    if (data->unk3D != 0 && data->unk3D == partner->nameId) {
                        task->tech = data->unk2A;
                    } else {
                        task->tech = 0;
                    }
                }
                /* the match depends on the ?: */
                FIGHTSTG_pairCursors[1].count = task->tech != 0 ? 2 : 1;
                w->techCursor = FIGHTSTG_createCursor(&FIGHTSTG_pairCursors[1]);
                if (w->cursor != NULL) {
                    w->cursor->setState(w->cursor, 3);
                }
                task->nextStep(task);
                break;
            case 1:
                do {
                    pressed = PAD.getPressed(0);
                    if (pressed & (1 << PAD_CROSS)) {
                        active = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
                        other = &FIGHTSTG_battle.fighters[0][task->fighter];
                        SOUND.playSound(SOUND_MENU_CONFIRM);
                        if (w->techCursor->sel == 0) {
                            if (!(active->flags & FIGHTER_NO_SWITCH) && !(other->flags & FIGHTER_NO_SWITCH)) {
                                *task->result = 0;
                                *task->result |= task->ids[task->digimon] << 4;
                                task->setSubstate(task, 0);
                                FIGHTSTG_showSwitchInChoices(task, w, 0);
                                w->techCursor->locked = 1;
                            }
                        } else if (active->mp >= TECHS[task->tech - 1].mp && other->mp >= TECHS[task->tech - 1].mp &&
                                   !(active->flags & FIGHTER_NO_DIGIVOLVE) && !(other->flags & FIGHTER_NO_DIGIVOLVE) && !(active->flags & FIGHTER_ASLEEP) && active->hp > 0 &&
                                   other->hp > 0) {
                            active->mp -= TECHS[task->tech - 1].mp;
                            other->mp -= TECHS[task->tech - 1].mp;
                            *task->result = w->techCursor->sel;
                            *task->result |= task->ids[task->digimon] << 4;
                            *task->techResult = task->tech;
                            task->setSubstate(task, 0);
                            FIGHTSTG_showSwitchInChoices(task, w, 0);
                            w->techCursor->locked = 1;
                        }
                        break;
                    }
                    if (pressed & (1 << PAD_TRIANGLE)) {
                        SOUND.playSound(SOUND_MENU_CANCEL);
                        task->setSubstate(task, 0);
                        FIGHTSTG_showSwitchInChoices(task, w, 0);
                        break;
                    }
                    if (pressed & (1 << PAD_R1)) {
                        if (++task->page == 3) {
                            task->page = 0;
                        }
                        SOUND.playSound(SOUND_MENU_MOVE);
                        break;
                    }
                    if (pressed & (1 << PAD_L1)) {
                        if (--task->page < 0) {
                            task->page = 2;
                        }
                        SOUND.playSound(SOUND_MENU_MOVE);
                        break;
                    }
                    FIGHTSTG_showSwitchInNames(task, w, 0);
                    FIGHTSTG_showSwitchInChoices(task, w, 1);
                } while (0);
                break;
            }
            FIGHTSTG_drawSwitchInMenu(task);
            break;
        }
        if (task->shownPage != task->page) {
            changed = 1;
        } else if (w->cursor == NULL) {
            changed = 0;
        } else if (task->digimon != w->cursor->sel) {
            task->digimon = w->cursor->sel;
            changed = 1;
        } else {
            changed = 0;
        }
        if (changed) {
            task->shownPage = task->page;
            if (w->info[0] != NULL) {
                w->info[0]->setState(w->info[0], 2);
                w->info[1] = FIGHTSTG_createPartnerInfo(task->partner, task->page, task->digimon);
            } else {
                if (w->info[1] != NULL) {
                    w->info[1]->setState(w->info[1], 2);
                }
                w->info[0] = FIGHTSTG_createPartnerInfo(task->partner, task->page, task->digimon);
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Opens the switch-in menu for fighter *result, without the pair technique */
SwitchInMenu *FIGHTSTG_createSwitchInMenu(s32 *result) {
    SwitchInMenu *task = createTask(FIGHTSTG_updateSwitchInMenu, sizeof(SwitchInMenu), sizeof(SwitchInMenuWindows));

    task->result = result;
    task->fighter = *result;
    task->partner = GAME.funcs.getPartyMember(*result);
    *result = -1;
    return task;
}

/* Opens the switch-in menu for fighter *result, with the pair technique,
   which goes into *techResult */
SwitchInMenu *FIGHTSTG_createPairSwitchMenu(s32 *result, s32 *techResult) {
    SwitchInMenu *task = FIGHTSTG_createSwitchInMenu(result);

    task->techResult = techResult;
    return task;
}

/* Draws the message box and, once its lines are out, its blinking arrow */
void FIGHTSTG_drawMessageBox(BattleMessageBox *task) {
    SpriteDrawer drawer;
    s32 sheet;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    if (task->showArrow != 0) {
        if (GFX.funcs.getTime() - task->arrowTime >= 4) {
            task->arrowTime = GFX.funcs.getTime();
            task->arrowPalette++;
            if (task->arrowPalette >= 5) {
                task->arrowPalette = 0;
            }
        }
        drawer.setTexture(0x140, 0);
        drawer.setClutRow(task->arrowPalette);
        drawer.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 10, 0x123, 0xD0);
        drawer.setClutRow(0);
    }
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0x31, 0xB, 0xBC);
}

/* Shows the message's lines one by one, 3 frames apart, then on cross shows
   the queue's next message or ends; after finish (substate 4) it ends after
   0x14 frames or on cross */
void FIGHTSTG_stepMessage(BattleMessageBox *task, BattleMessageBoxWindows *windows) {
    switch (task->substate) {
    case 0:
    default:
        if (task->started != 0) {
            task->substate++;
        }
        break;
    case 1:
        task->shownTime = GFX.funcs.getTime();
        task->interval = 3;
        windows->lines[task->shown]->setVisible(windows->lines[task->shown], 1);
        task->substate++;
        break;
    case 2:
        if (task->interval < GFX.funcs.getTime() - task->shownTime) {
            if (++task->shown >= task->count) {
                task->showArrow = 1;
                task->substate++;
            } else {
                task->substate = 1;
            }
        }
        break;
    case 3:
        if (PAD.getPressed(0) & (1 << PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            if (task->queue[++task->next] == 0) {
                task->state = 3;
            } else {
                task->show(task, task->queue[task->next], 0);
                task->setSubstate(task, 0);
            }
            task->showArrow = 0;
        }
        break;
    case 4:
        if (GFX.funcs.getTime() - task->step > 0x14 || (PAD.getPressed(0) & (1 << PAD_CROSS))) {
            task->state = 3;
        }
        break;
    }
}

/* The battle message box's task: draws it and steps its message each frame */
void FIGHTSTG_updateMessage(BattleMessageBox *task, void *children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        FIGHTSTG_drawMessageBox(task);
        FIGHTSTG_stepMessage(task, children);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Puts the name of side's fighter index (a partner's own, an enemy's from the
   battle table) into the message's first line */
void FIGHTSTG_setMessageName(BattleMessageBox *task, BattleMessageBoxWindows *w, s32 side, s32 index) {
    BattleFighter *fighter;
    BattleTableEntry *entry;

    if (side == 0) {
        w->lines[0]->setSubString(w->lines[0], GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(index)), -1, 1);
    } else {
        fighter = &FIGHTSTG_battle.fighters[1][index];
        entry = FIGHTSTG_battleTableFunc(fighter->id);
        w->lines[0]->setSubString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), entry->nameId, 1);
    }
}

void FIGHTSTG_findFighters(BattleMessageBox *task, FighterFilter *filter) {
    s32 side = filter->side != 0;
    BattleFighter *fighters;
    s32 i;

    task->foundCount = 0;
    fighters = FIGHTSTG_battle.fighters[side];
    switch (filter->type) {
    case 0:
    default:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0 && fighters[i].hp < fighters[i].maxHp) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0 && (fighters[i].flags & FIGHTER_POISONED)) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0 && (fighters[i].flags & FIGHTER_PARALYZED)) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0 && (fighters[i].flags & FIGHTER_CONFUSED)) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0 && fighters[i].flags != 0) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 5:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp == 0) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 6:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    case 7:
    case 8:
    case 9:
        for (i = 0; i < 3; i++) {
            if (fighters[i].id != 0 && fighters[i].hp != 0) {
                task->found[task->foundCount++] = i;
            }
        }
        break;
    }
}

/* Sets up a message about the fighters FIGHTSTG_findFighters found: their
   names (text 0x15 plus their count) and what happened to them by msg's kind,
   or text 0x2F when there are none */
void FIGHTSTG_showFightersMessage(BattleMessageBox *task, BattleMessageBoxWindows *w, BattleMessage *msg) {
    BattleFighter *fighter;
    BattleTableEntry *entry;
    s32 member;
    u8 side;
    s32 kind;
    s32 i;

    if (task->foundCount != 0) {
        side = msg->side;
        kind = msg->kind;
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), task->foundCount + 0x15);
        if (side == 0) {
            for (i = 0; i < task->foundCount; i++) {
                member = GAME.funcs.getPartyMember(task->found[i]);
                if (member >= 0) {
                    w->lines[0]->setSubString(w->lines[0], GAME.funcs.getPartnerStats(member), -1, i + 1);
                }
            }
        } else {
            for (i = 0; i < task->foundCount; i++) {
                fighter = &FIGHTSTG_battle.fighters[1][task->found[i]];
                if (fighter->id != 0) {
                    entry = FIGHTSTG_battleTableFunc(fighter->id);
                    w->lines[0]->setSubString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), entry->nameId, i + 1);
                }
            }
        }
        switch (kind) {
        case 0:
        default:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x22);
            w->lines[1]->setNumber(w->lines[1], 1, msg->value);
            break;
        case 1:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x28);
            break;
        case 2:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x29);
            break;
        case 3:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x2A);
            break;
        case 4:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x2C);
            break;
        case 5:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x2D);
            break;
        case 6:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x2E);
            break;
        case 7:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x30);
            break;
        case 8:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x31);
            break;
        case 9:
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x32);
            break;
        }
        task->count = 2;
    } else {
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x2F);
        task->count = 1;
    }
}

/* The message box's show: sets up the lines of message type from data, mostly
   a fighter's name with a text, a technique or a number, and starts showing
   them */
void FIGHTSTG_showMessage(BattleMessageBox *task, s32 type, s32 *data) {
    BattleMessageBoxWindows *w = task->children;
    s32 total;
    s32 side;

    task->started = 1;
    if (w->lines[0] == NULL) {
        w->lines[0] = createTextWindow(0x1005, 1, 0x14, 0xC2);
    }
    if (w->lines[1] == NULL) {
        w->lines[1] = createTextWindow(0x1005, 1, 0x14, 0xD0);
    }
    task->shown = 0;
    switch (type) {
    case 1:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), data[0]);
        task->count = 1;
        break;
    case 2:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), data[0]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[1], FIGHTSTG_battle.active[data[1] != 0]);
        break;
    case 3:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 9);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)), data[1], 1);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 4:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0xB);
        w->lines[1]->setNumber(w->lines[1], 1, data[1]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 5:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0xA);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)), data[1], 1);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 6:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x25);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 7:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), data[0]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[1], data[2]);
        break;
    case 8:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x22);
        w->lines[1]->setNumber(w->lines[1], 1, data[1]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 9:
        FIGHTSTG_findFighters(task, (FighterFilter *)data);
        FIGHTSTG_showFightersMessage(task, w, (BattleMessage *)data);
        break;
    case 10:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x27);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], data[1]);
        task->queue[1] = 11;
        task->queue[2] = data[0];
        task->queue[3] = data[1];
        task->queue[4] = data[2];
        break;
    case 11:
        data = &task->queue[task->next + 1];
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x22);
        w->lines[1]->setNumber(w->lines[1], 1, data[2]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], data[1]);
        task->next += 3;
        break;
    case 12:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x37);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data[1], 1);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 13:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x4E);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x4F);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data[0], 1);
        task->count = 2;
        break;
    case 14:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 9);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_ITEM_NAMES)), data[1], 1);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 15:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x55);
        w->lines[1]->setNumber(w->lines[1], 1, data[2]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], data[1]);
        break;
    case 16:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x23);
        total = data[1] * data[2];
        w->lines[1]->setNumber(w->lines[1], 1, data[1]);
        w->lines[1]->setNumber(w->lines[1], 2, data[2]);
        w->lines[1]->setNumber(w->lines[1], 3, total);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 17:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x26);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 9);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_ITEM_NAMES)), data[0], 1);
        task->count = 2;
        break;
    case 18:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        if (data[2] == 0) {
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x22);
        } else {
            w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x8F);
        }
        w->lines[1]->setNumber(w->lines[1], 1, data[1]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 19:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), data[1] + 0x49);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, data[0], FIGHTSTG_battle.active[data[0] != 0]);
        break;
    case 20:
        FIGHTSTG_showMessage(task, 4, data);
        task->queue[1] = 21;
        task->queue[2] = (data[0] == 0) << 4;
        task->queue[3] = data[1];
        break;
    case 21:
        side = task->queue[task->next + 1];
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x22);
        w->lines[1]->setNumber(w->lines[1], 1, task->queue[task->next + 2]);
        task->count = 2;
        FIGHTSTG_setMessageName(task, w, side, FIGHTSTG_battle.active[side != 0]);
        task->next += 2;
        break;
    case 22:
        w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x8C);
        w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 9);
        w->lines[1]->setSubString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)), data[0], 1);
        task->count = 2;
        break;
    }
    w->lines[0]->setVisible(w->lines[0], 0);
    w->lines[1]->setVisible(w->lines[1], 0);
}

/* The message box's finish: closes it after 0x14 frames or on cross */
void FIGHTSTG_finishMessage(BattleMessageBox *task) {
    task->substate = 4;
    task->showArrow = 0;
    task->step = GFX.funcs.getTime();
}

/* Creates a battle message box (FIGHTSTG_updateMessage) */
BattleMessageBox *FIGHTSTG_createMessage(void) {
    BattleMessageBox *task = createTask(FIGHTSTG_updateMessage, sizeof(BattleMessageBox), 8);

    task->show = FIGHTSTG_showMessage;
    task->finish = FIGHTSTG_finishMessage;
    return task;
}

/* Shows the confused menu's six lines once, in FIGHTSTG_confusedLines's order */
void FIGHTSTG_showConfusedCommands(ConfusedMenu *task) {
    ConfusedMenuWindows *w = task->children;
    char *text;
    s32 i;

    if (w->lines[0] == NULL) {
        text = FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU));
        for (i = 0; i < 6; i++) {
            w->lines[i] = createTextWindow(0x1005, 1, 0x24, i * 0x13 + 0x6D);
            w->lines[i]->setString(w->lines[i], text, FIGHTSTG_confusedLines[i] + 0x6B);
        }
    }
}

/* Draws the confused menu's message box and, once its lines are out, its
   blinking arrow */
void FIGHTSTG_drawConfusedMessageBox(ConfusedMenu *task) {
    SpriteDrawer drawer;
    s32 sheet;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x1005, 1);
    if (task->showArrow != 0) {
        if (GFX.funcs.getTime() - task->arrowTime >= 4) {
            task->arrowTime = GFX.funcs.getTime();
            task->arrowPalette++;
            if (task->arrowPalette >= 5) {
                task->arrowPalette = 0;
            }
        }
        drawer.setTexture(0x140, 0);
        drawer.setClutRow(task->arrowPalette);
        drawer.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 10, 0x123, 0xD0);
        drawer.setClutRow(0);
    }
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    drawer.setTexture(0x200, 0);
    drawer.draw(sheet, 0x31, 0xB, 0xBC);
}

/* Shows the confused message's lines one by one, 3 frames apart, then ends on
   cross */
void FIGHTSTG_stepConfusedMessage(ConfusedMenu *task, ConfusedMenuWindows *w) {
    s32 pressed = PAD.getPressed(0);

    switch (task->substate) {
    case 0:
    default:
        if (task->started != 0) {
            task->substate++;
        }
        break;
    case 1:
        task->time = GFX.funcs.getTime();
        task->delay = 3;
        w->lines[task->line]->setVisible(w->lines[task->line], 1);
        task->substate++;
        break;
    case 2:
        if (task->delay < GFX.funcs.getTime() - task->time) {
            if (++task->line >= task->lineCount) {
                task->showArrow = 1;
                if (pressed & (1 << PAD_CROSS)) {
                    SOUND.playSound(SOUND_MENU_CONFIRM);
                    if (task->queue[++task->next] == 0) {
                        task->state = 3;
                    } else {
                        task->show(task, task->queue[task->next], 0);
                        task->setSubstate(task, 0);
                    }
                    task->showArrow = 0;
                }
            } else {
                task->substate = 1;
            }
        }
        break;
    }
}

/* Puts the active partner's name into the message's first line (side 0 only) */
void FIGHTSTG_setConfusedName(ConfusedMenu *task, ConfusedMenuWindows *windows, s32 arg2) {
    if (arg2 == 0) {
        windows->lines[0]->setSubString(windows->lines[0], GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0])), -1, 1);
    }
}

/* the confused menu's (FIGHTSTG_updateConfusedMenu) results, two per line,
   each a message (task->queue[0]) and its line of text 0x80 */
s16 FIGHTSTG_confusedMessages[16][2] = {
    { 1, 0x73 }, { 2, 0x74 }, { 3, 0x75 }, { 4, 0x76 },
    { 5, 0x77 }, { 6, 0x78 }, { 7, 0x79 }, { 8, 0x7A },
    { 9, 0x7B }, { 10, 0x7C }, { 11, 0x7D }, { 12, 0x7E },
    { 13, 0x7F }, { 14, 0x80 }, { 15, 0x81 }, { 16, 0x82 },
};
/* the confused menu's lines, which it shuffles */
s16 FIGHTSTG_confusedLines[8] = {
    7, 1, 0, 3, 2, 5, 4, 6,
};

/* Sets up confused message index (FIGHTSTG_confusedMessages) with the
   partner's name and starts showing it */
void FIGHTSTG_showConfusedMessage(ConfusedMenu *task, s32 index, s32 arg2) {
    ConfusedMenuWindows *w = task->children;

    task->started = 1;
    if (w->lines[0] == NULL) {
        w->lines[0] = createTextWindow(0x1005, 1, 0x14, 0xC2);
    }
    if (w->lines[1] == NULL) {
        w->lines[1] = createTextWindow(0x1005, 1, 0x14, 0xD0);
    }
    task->queue[0] = FIGHTSTG_confusedMessages[index][0];
    w->lines[0]->setString(w->lines[0], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), 0x16);
    w->lines[1]->setString(w->lines[1], FILE_CACHE.load(TEXT_FILE(TEXT_BATTLE_MENU)), FIGHTSTG_confusedMessages[index][1]);
    task->lineCount = 2;
    FIGHTSTG_setConfusedName(task, w, 0);
    w->lines[0]->setVisible(w->lines[0], 0);
    w->lines[1]->setVisible(w->lines[1], 0);
}

/* the confused menu's cursor */
CursorLayout FIGHTSTG_confusedCursor = {
    6, 17, 110, 19, 34, 16, 109, 19,
};

/* The confused menu's task: shuffles the lines, then on cross attacks
   (*result 0) when FIGHTSTG_battleFuncs.testConfusion fails; else closes the
   lines, the partner view and the camera and shows one of the picked line's
   two messages at random, giving 1 when it is done */
void FIGHTSTG_updateConfusedMenu(ConfusedMenu *task, ConfusedMenuWindows *w) {
    s32 i;
    s32 j;
    s16 tmp;

    switch (task->state) {
    case TASK_INIT:
    default:
        w->cursor = FIGHTSTG_createCursor(&FIGHTSTG_confusedCursor);
        w->cursor->sel = task->firstLine;
        for (i = 0; i < 8; i++) {
            j = RANDOM.next() % 8;
            tmp = FIGHTSTG_confusedLines[i];
            FIGHTSTG_confusedLines[i] = FIGHTSTG_confusedLines[j];
            FIGHTSTG_confusedLines[j] = tmp;
        }
        FIGHTSTG_showConfusedCommands(task);
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
            if (PAD.getPressed(0) & (1 << PAD_CROSS)) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                if (FIGHTSTG_battleFuncs.testConfusion(0) == 0) {
                    *task->result = 0;
                    task->setState(task, 3);
                } else {
                    task->picked = w->cursor->sel;
                    for (i = 0; i < 6; i++) {
                        w->lines[i]->setState(w->lines[i], 3);
                    }
                    w->cursor->setState(w->cursor, 3);
                    task->partnerView->state = 3;
                    task->shotCamera->state = 3;
                    task->nextSubstate(task);
                }
                w->cursor->locked = 1;
            }
            break;
        case 1:
            if (w->lines[0] == NULL && w->lines[1] == NULL) {
                FIGHTSTG_showConfusedMessage(task, (FIGHTSTG_confusedLines[task->picked] << 1) | (RANDOM.next() & 1), 0);
                task->setState(task, 2);
            }
            break;
        }
        break;
    case TASK_DONE:
        FIGHTSTG_drawConfusedMessageBox(task);
        FIGHTSTG_stepConfusedMessage(task, w);
        if (task->state == 3) {
            *task->result = 1;
        }
        break;
    case TASK_KILL:
        break;
    }
}

/* Opens a confused partner's command menu; *result gets 0 for an attack
   or 1 for a lost turn */
ConfusedMenu *FIGHTSTG_createConfusedMenu(s32 *result, Task *partnerView, Task *shotCamera) {
    ConfusedMenu *task = createTask(FIGHTSTG_updateConfusedMenu, sizeof(ConfusedMenu), sizeof(ConfusedMenuWindows));

    task->result = result;
    *result = -1;
    task->firstLine = 0;
    task->partnerView = partnerView;
    task->shotCamera = shotCamera;
    return task;
}

/* where FIGHTSTG_drawCursorBar puts the cursor's bar in VRAM */
RECT FIGHTSTG_cursorBarRect = { 0, 0xF4, 12, 12 };

/* The vsync callback while the list is open: draws the picked line's bar,
   moving through its frames, and the bar off the line picked before when the
   pick has changed, over the frame being drawn. The match depends on the task
   coming as the callback's s32 argument, cast into a variable. */
void FIGHTSTG_drawCursorBar(s32 arg) {
    MenuCursor *task = (MenuCursor *)arg;
    u_long *saved;
    s32 i;
    s32 y;

    saved = (u_long *)BreakDraw();
    if (saved != (u_long *)-1) {
        if (++task->frame == 12) {
            task->frame = 0;
        }
        ClearOTag(FIGHTSTG_cursorBarOt, 2);
        for (i = 0; i < 4; i += 2) {
            if (i == 2 && task->prevSel == task->sel) {
                break;
            }
            if (i < 2) {
                FIGHTSTG_cursorBarRect.x = task->frame * 12;
                y = task->params.y + task->sel * task->params.step;
            } else {
                FIGHTSTG_cursorBarRect.x = 0x90;
                y = task->params.y + task->prevSel * task->params.step;
            }
            SetDrawMove(&FIGHTSTG_cursorBarMoves[i], &FIGHTSTG_cursorBarRect, task->params.x, y);
            addPrim(FIGHTSTG_cursorBarOt, &FIGHTSTG_cursorBarMoves[i]);
            SetDrawMove(&FIGHTSTG_cursorBarMoves[i + 1], &FIGHTSTG_cursorBarRect, task->params.x, y + 0x100);
            addPrim(FIGHTSTG_cursorBarOt, &FIGHTSTG_cursorBarMoves[i + 1]);
        }
        while (IsIdleGPU(0)) {
        }
        ContinueDraw(FIGHTSTG_cursorBarOt, saved);
    }
    task->prevSel = task->sel;
}

/* Draws each line's sprite of the cursor, the picked one blinking through the
   palettes and the one left fading out */
void FIGHTSTG_drawCursorSprites(MenuCursor *task) {
    SpriteDrawer drawer;
    s32 sheet;
    s32 i;
    s32 y;
    s32 row;

    initSpriteDrawer(&drawer);
    i = 0;
    drawer.setLayerId(0x1005, 1);
    drawer.setTexture(0x200, i);
    sheet = FILE_CACHE.getEntry(FILE_BATTLE_MENU << 16);
    y = task->params.spriteY;
    for (; i < task->params.count; i++) {
        if (task->blink[i] != 0 || task->sel == i) {
            task->blink[i] += GFX.funcs.getFrameTime();
            if (task->blink[i] >= 0x14) {
                if (task->sel != i) {
                    task->blink[i] = 0;
                } else {
                    task->blink[i] -= 0x14;
                }
            }
        }
        row = task->blink[i] >> 2;
        if ((u32)row < 5) {
            drawer.setClutRow(row);
        } else {
            drawer.setClutRow(0);
        }
        drawer.draw(sheet, task->params.sprite, task->params.spriteX, y);
        y += task->params.spriteStep;
    }
}

/* The menu cursor's task: sets FIGHTSTG_drawCursorBar as the vsync callback,
   draws the lines' sprites and moves with up and down until locked; when
   killed, takes the callback off */
void FIGHTSTG_updateCursor(MenuCursor *task) {
    s32 pressed;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 2:
        default:
            GFX.vsyncFunc = FIGHTSTG_drawCursorBar;
            GFX.vsyncArg = (s32)task;
        case 0:
        case 1:
            task->nextSubstate(task);
        case 3:
            if (task->params.sprite != -1) {
                FIGHTSTG_drawCursorSprites(task);
            }
            if (task->locked == 0) {
                pressed = PAD.getRepeated(0) | PAD.getPressed(0);
                if (pressed & (1 << PAD_UP)) {
                    if (task->sel != 0) {
                        task->sel--;
                        SOUND.playSound(SOUND_MENU_MOVE);
                    }
                } else if (pressed & (1 << PAD_DOWN)) {
                    if (task->sel != task->params.count - 1) {
                        task->sel++;
                        SOUND.playSound(SOUND_MENU_MOVE);
                    }
                }
            }
            break;
        }
        break;
    case TASK_DONE:
        break;
    case TASK_KILL:
        GFX.vsyncFunc = NULL;
        break;
    }
}

/* Creates a menu cursor laid out by layout */
MenuCursor *FIGHTSTG_createCursor(CursorLayout *layout) {
    MenuCursor *task = createTask(FIGHTSTG_updateCursor, sizeof(MenuCursor), 0);

    task->params = *layout;
    return task;
}

void FIGHTSTG_updateJump(Jump *task) {
    s32 y;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->dist = 0;
        switch (task->kind) {
        case 4:
            task->dist = task->distance + 0x2800;
            break;
        case 5:
            task->dist = task->control->pos.z - task->control->homePos.z;
            if (task->dist < 0) {
                task->dist = -task->dist;
            }
            break;
        }
        if (task->control->id == 0x10) {
            task->dist = -task->dist;
        }
        task->t = FIGHTSTG_battle.frames * task->speed;
        task->nextState(task);
        /* fallthrough */
    case TASK_RUN:
        switch (task->kind) {
        default:
            y = FIGHTSTG_interp.ease(2, task->t, task->height);
            task->control->pos.y = FIGHTSTG_interp.ease(1, task->t, task->y) - y;
            break;
        case 4:
        case 5:
            task->control->pos.y = task->control->homePos.y - FIGHTSTG_interp.ease(2, task->t, task->height);
            break;
        case 6:
            task->control->pos.y = FIGHTSTG_interp.ease(0, task->t, task->control->homePos.y);
            break;
        }
        if (task->kind == 4) {
            task->control->pos.z = task->control->homePos.z + FIGHTSTG_interp.ease(0, task->t, task->dist);
        }
        if (task->kind == 5) {
            task->control->pos.z = task->control->homePos.z + task->dist - FIGHTSTG_interp.ease(0, task->t, task->dist);
        }
        task->t += FIGHTSTG_battle.frames * task->speed;
        if (task->t < 0x1000) {
            break;
        }
        task->nextState(task);
        break;
    case TASK_DONE:
        switch (task->kind) {
        default:
            task->control->pos.y = 0;
            break;
        case 4:
        case 5:
        case 6:
            task->control->pos.y = task->control->homePos.y;
            break;
        }
        if (task->kind == 4) {
            task->control->pos.z = task->control->homePos.z + task->dist;
        }
        if (task->kind == 5) {
            task->control->pos.z = task->control->homePos.z;
        }
        task->nextState(task);
        break;
    case TASK_KILL:
        break;
    }
}

/* the jumps of FIGHTSTG_startJump, by kind from 1 */
JumpParams FIGHTSTG_jumps[] = {
    { 640, 136 }, { 1280, 102 }, { 1920, 81 }, { 2560, 64 }, { 1280, 64 }, { 0, 42 },
};

Jump *FIGHTSTG_startJump(ModelControl *control, s32 kind, s32 distance) {
    Jump *task = createTask(FIGHTSTG_updateJump, sizeof(Jump), 0);

    task->kind = kind;
    task->control = control;
    task->distance = distance;
    task->y = control->pos.y;
    task->height = FIGHTSTG_jumps[kind - 1].height;
    task->speed = FIGHTSTG_jumps[kind - 1].speed;
    return task;
}

/* The move's task: takes the model from from to to along tStep, a step each
   frame, and dies there */
void FIGHTSTG_updateMove(MoveTask *task) {
    SVECTOR from;
    SVECTOR to;
    SVECTOR out;
    s32 t;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->t = FIGHTSTG_battle.frames * task->tStep;
        task->nextState(task);
        /* fallthrough */
    case TASK_RUN:
        t = task->t;
        from.vx = task->from.x;
        from.vy = task->from.y;
        from.vz = task->from.z;
        to.vx = task->to.x;
        to.vy = task->to.y;
        to.vz = task->to.z;
        FIGHTSTG_interp.lerp(&from, &to, t, &out);
        task->control->pos.x = out.vx;
        task->control->pos.y = out.vy;
        task->control->pos.z = out.vz;
        task->t += FIGHTSTG_battle.frames * task->tStep;
        if (task->t >= 0x1000) {
            task->control->pos.x = task->to.x;
            task->control->pos.y = task->to.y;
            task->control->pos.z = task->to.z;
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Moves control's model from where it is to to over time frames */
MoveTask *FIGHTSTG_startMove(ModelControl *control, ShortVec3 *to, s32 time) {
    MoveTask *task = createTask(FIGHTSTG_updateMove, sizeof(MoveTask), 0);

    task->control = control;
    task->to = *to;
    task->from = control->pos;
    task->t = 0;
    task->tStep = 0x1000 / time;
    return task;
}

void FIGHTSTG_updateBattleSound(BattleSound *task) {
    switch (task->state) {
    case TASK_INIT:
    case TASK_RUN:
    default:
        task->time -= FIGHTSTG_battle.frames;
        if (task->time <= 0) {
            SOUND.keyOff(task->sound, task->voice);
            task->setState(task, TASK_KILL);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* the sound ids of FIGHTSTG_playBattleSound, by index */
s32 FIGHTSTG_battleSounds[] = {
    0x6004001E, 0x4001C, 0x40004, 0x4000A,
    0x4000B, 0x4000C, 0x4004000D, 0x40014,
    0x4001A, 0x40019, 0x40017, 0x40011,
    0x4000F, 0x4001F, 0x40016, 0x40010,
    0x4000E, 0x40012, 0x8004103C, 0x800410BD,
    0x8004213E, 0x800421BF, 0xA0042240, 0x80042342,
    0x80042444, 0x8004293E, 0x800429BF, 0x80042A40,
    0x40001, 0x80042B42, 0x80042C44, 0x80042CC5,
    0x80042D46, 0x80042DC7, 0x80042E48, 0xA0042F4A,
    0xA0042FCB, 0xA004303C, 0x800430BD, 0x8004313E,
    0xA00431BF, 0xA0043240, 0x800432C1, 0x80043342,
    0x800433C3, 0x800434C5, 0x80043546, 0xA00435C7,
    0x80043648, 0x8004374A, 0x800437CB, 0x8004383C,
    0x80043A40, 0xA0043BC3, 0xA0043C44, 0x800440BD,
    0x8004413E, 0x800441BF, 0x80044240, 0x800442C1,
    0x80044444, 0x800445C7, 0x80044648, 0x800446C9,
    0x8004474A, 0x8004483C, 0x41180000, 0x8004503C,
    0x800450BD, 0x8004513E, 0x800452C6, 0x80045341,
    0x4001B, 0x800454C4, 0x8004583C, 0x800458BD,
    0x8004593E, 0x800459BF, 0x80045A40, 0x80045AC1,
    0x80045B42, 0x80045BC3, 0x80045C44, 0x80045CC5,
    0x80045D46, 0x80045DC7, 0x8004603C, 0x800460BD,
    0x8004613E, 0x20040006, 0, 0,
};
/* how the fight stage and WFIGHTMN read the battle table */
BattleTableEntry *(*FIGHTSTG_battleTableFunc)(s32 id) = FIGHTSTG_getBattleTableEntry;

BattleSound *FIGHTSTG_playBattleSound(s32 index, s32 time) {
    s32 id;
    BattleSound *task;

    switch (index) {
    default:
        id = FIGHTSTG_battleSounds[index];
        break;
    case 0x5A:
        id = BATTLE_SETUP.music;
        break;
    case 0x5B:
        SOUND.stopSound(0x20040006);
        return NULL;
    }
    if (time == 0) {
        SOUND.playSound(id);
        return NULL;
    }
    task = createTask(FIGHTSTG_updateBattleSound, sizeof(BattleSound), 0);
    task->sound = id;
    task->voice = SOUND.playSound(id);
    task->time = time;
    return task;
}

s32 FIGHTSTG_findBattleTableIndex(s32 id) {
    BattleTableEntry *table = (BattleTableEntry *)FILE_CACHE.load(FILE_BATTLE_TABLE);
    s32 i;

    for (i = 0; table[i].id != 0; i++) {
        if (table[i].id == id) {
            return i;
        }
    }
    return -1;
}

BattleTableEntry *FIGHTSTG_getBattleTableEntry(s32 id) {
    BattleTableEntry *table = (BattleTableEntry *)FILE_CACHE.load(FILE_BATTLE_TABLE);
    s32 i = FIGHTSTG_findBattleTableIndex(id);

    if (i >= 0) {
        return &table[i];
    }
    return NULL;
}

void FIGHTSTG_pushEvent(BattleEvent *event) {
    s32 i = 0;
    s32 free = -1;

    for (; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type == 0) {
            free = i;
            break;
        }
    }
    if (free != -1) {
        FIGHTSTG_events.events[free].type = event->type;
        FIGHTSTG_events.events[free].time = event->delay;
        for (i = 0; i < 6; i++) {
            FIGHTSTG_events.events[free].args[i] = event->args[i];
        }
    }
}

/* per event type, whether FIGHTSTG_popEvent takes (1), peeks at (-1) or
   drops (0) it */
s32 FIGHTSTG_eventPopModes[] = {
    0, 1, 1, 1,
    -1, 1, -1, 1,
    1, -1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 0,
};

/* the battle's events and their functions */
EventQueue FIGHTSTG_events = {
    { { 0 } }, { 0 }, 0, 0, 0, 0,
    {
        0, 0, FIGHTSTG_pushEvent, FIGHTSTG_pushEventFirst, FIGHTSTG_popEvent,
        FIGHTSTG_findFirstEvent, FIGHTSTG_findNextEvent, FIGHTSTG_findEvent, FIGHTSTG_removeEvents,
        FIGHTSTG_getEventDelay, FIGHTSTG_cureStatus,
    },
};

void FIGHTSTG_pushEventFirst(BattleEvent *event) {
    s32 i;

#if VERSION_US
    if (event->delay <= 0) {
        event->delay = 1;
    }
#elif VERSION_EU
    if (event->delay < 2) {
        event->delay = 2;
    }
#endif
    for (i = 0; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type != 0) {
            FIGHTSTG_events.events[i].time += event->delay;
        }
    }
#if VERSION_US
    event->delay = 0;
#elif VERSION_EU
    event->delay = 1;
#endif
    FIGHTSTG_pushEvent(event);
}

/* Pops the next event: the one due soonest (in EU, events of types 2 and 3
   give way to any due no later), moving all the others' times on by its.
   Returns its type, or 0 when there's none or FIGHTSTG_eventPopModes says to
   drop it. */
s32 FIGHTSTG_popEvent(void) {
    s32 min = 0x7FFF;
    s32 best = -1;
    s32 i;
    s32 time;
#if VERSION_EU
    QueuedEvent *event;
#endif
    s32 type;

    for (i = 0; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type != 0) {
#if VERSION_EU
            if (best != -1 && FIGHTSTG_events.events[i].time <= FIGHTSTG_events.events[best].time &&
                (FIGHTSTG_events.events[best].type == EVENT_PLAYER_TURN || FIGHTSTG_events.events[best].type == EVENT_ENEMY_TURN)) {
                best = i;
                min = FIGHTSTG_events.events[i].time;
            }
#endif
            if (FIGHTSTG_events.events[i].time < min) {
                best = i;
                min = FIGHTSTG_events.events[i].time;
            }
        }
    }
    if (best == -1) {
        return 0;
    }
#if VERSION_US
    time = FIGHTSTG_events.events[best].time;
    for (i = 0; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type != 0) {
            FIGHTSTG_events.events[i].time -= time;
        }
    }
    FIGHTSTG_events.curType = FIGHTSTG_events.events[best].type;
    switch (FIGHTSTG_eventPopModes[FIGHTSTG_events.curType]) {
    case 0:
        return 0;
    case -1:
        type = FIGHTSTG_events.events[best].type;
        FIGHTSTG_events.curIndex = best;
        return type;
    default:
        type = FIGHTSTG_events.events[best].type;
        FIGHTSTG_events.curIndex = best;
        FIGHTSTG_events.events[best].type = 0;
        return type;
    }
#elif VERSION_EU
    event = &FIGHTSTG_events.events[best];
    time = event->time;
    for (i = 0; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type != 0) {
            FIGHTSTG_events.events[i].time -= time;
        }
    }
    FIGHTSTG_events.curType = event->type;
    switch (FIGHTSTG_eventPopModes[FIGHTSTG_events.curType]) {
    case 0:
        return 0;
    case -1:
        type = event->type;
        FIGHTSTG_events.curIndex = best;
        return type;
    default:
        type = event->type;
        event->type = 0;
        FIGHTSTG_events.curIndex = best;
        return type;
    }
#endif
}

s32 FIGHTSTG_findEventFrom(s32 start) {
    s32 type = FIGHTSTG_events.findType;
    s32 i;

    if ((u32)(type - 1) >= 24) {
        return -1;
    }
    for (i = start; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type == type) {
            return i;
        }
    }
    return -1;
}

s32 FIGHTSTG_findFirstEvent(s32 type) {
    FIGHTSTG_events.findType = type;
    return FIGHTSTG_events.found = FIGHTSTG_findEventFrom(0);
}

s32 FIGHTSTG_findNextEvent(void) {
    return FIGHTSTG_events.found = FIGHTSTG_findEventFrom(FIGHTSTG_events.found + 1);
}

s32 FIGHTSTG_findEvent(s32 type, u8 side, s32 fighter) {
    FIGHTSTG_events.findType = type;
    FIGHTSTG_events.found = FIGHTSTG_findEventFrom(0);
    while (FIGHTSTG_events.found >= 0) {
        if (FIGHTSTG_events.events[FIGHTSTG_events.found].args[0] == side && FIGHTSTG_events.events[FIGHTSTG_events.found].args[1] == fighter) {
            break;
        }
        FIGHTSTG_events.found = FIGHTSTG_findEventFrom(FIGHTSTG_events.found + 1);
    }
    return FIGHTSTG_events.found;
}

void FIGHTSTG_removeEvents(EventKey *key) {
    s32 i;
    s32 b = key->unk4;
    s32 a = key->unk0;

    for (i = 0; i < 99; i++) {
        if (FIGHTSTG_events.events[i].type != 0 && FIGHTSTG_events.events[i].args[0] == a && FIGHTSTG_events.events[i].args[1] == b) {
            FIGHTSTG_events.events[i].type = 0;
        }
    }
}

/* the delay ranges of FIGHTSTG_getEventDelay's kinds */
EventDelay FIGHTSTG_eventDelays[] = {
    { 1000, 707, 1414 }, { 250, 176, 353 }, { 2001, 1001, 0 }, { 2000, 0, 0 },
    { 2500, 0, 0 }, { 3000, 0, 0 }, { 3500, 0, 0 }, { 4000, 0, 0 },
    { 0, 2000, 6000 }, { 500, 1000, 0 }, { 500, 1000, 0 }, { 500, 500, 0 },
    { 2001, 0, 0 },
};

/* FIGHTSTG_events.funcs.getDelay: the time until side's next event of kind
   (FIGHTSTG_eventDelays): random, or from the active fighters' stats and
   the other side's resistances, within the kind's range */
s32 FIGHTSTG_getEventDelay(u8 side, s32 kind) {
    s32 delay;

    /* the match depends on each case having its own row and stats */
    switch (kind) {
    case 2: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);

        delay = RANDOM.next() % FIGHTSTG_eventDelays[kind].div + own->stats[BATTLE_STAT_SPIRIT] * 10;
        break;
    }
    case 8:
        delay = RANDOM.next() % 8001;
        break;
    case 9: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);
        BattleStats *other = FIGHTSTG_battleFuncs.computeStats((side == 0) << 4, 0, FIGHTSTG_battle.active[1 - row]);

        delay = RANDOM.next() % FIGHTSTG_eventDelays[kind].div + 3000 + (own->stats[BATTLE_STAT_SPIRIT] + FIGHTSTG_events.funcs.unk1) * 8
              - (other->resist[RESIST_PARALYSIS] + other->resist[4]) * 8;
        break;
    }
    case 10: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);
        BattleStats *other = FIGHTSTG_battleFuncs.computeStats((side == 0) << 4, 0, FIGHTSTG_battle.active[1 - row]);

        delay = RANDOM.next() % FIGHTSTG_eventDelays[kind].div + 3000 + (own->stats[BATTLE_STAT_SPIRIT] + FIGHTSTG_events.funcs.unk1) * 8
              - (other->resist[RESIST_CONFUSION] + other->resist[3]) * 8;
        break;
    }
    case 11: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);
        BattleStats *other = FIGHTSTG_battleFuncs.computeStats((side == 0) << 4, 0, FIGHTSTG_battle.active[1 - row]);

        delay = RANDOM.next() % FIGHTSTG_eventDelays[kind].div + 1000 + (own->stats[BATTLE_STAT_SPIRIT] + FIGHTSTG_events.funcs.unk1) * 8
              - (other->resist[RESIST_SLEEP] + other->resist[2]) * 8;
        break;
    }
    case 12: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);

        delay = RANDOM.next() % FIGHTSTG_eventDelays[kind].div + 2000 + own->stats[BATTLE_STAT_SPIRIT] * 10;
        break;
    }
    default: {
        s32 row = side != 0;
        BattleStats *own = FIGHTSTG_battleFuncs.computeStats(side, 1, FIGHTSTG_battle.active[row]);
        BattleStats *other = FIGHTSTG_battleFuncs.computeStats(0x10 - side, 0, FIGHTSTG_battle.active[1 - row]);
        s32 square = own->stats[BATTLE_STAT_SPEED] * other->stats[BATTLE_STAT_SPEED];
        s32 root = 999;
        s32 i;

        /* Newton's square root */
        for (i = 0; i < 10; i++) {
            root = (root + square / root) / 2;
        }
        delay = FIGHTSTG_eventDelays[kind].div * other->stats[BATTLE_STAT_SPEED] / root;
        break;
    }
    }
    if (FIGHTSTG_eventDelays[kind].min != 0 && delay < FIGHTSTG_eventDelays[kind].min) {
        delay = FIGHTSTG_eventDelays[kind].min;
    }
    if (FIGHTSTG_eventDelays[kind].max != 0 && delay > FIGHTSTG_eventDelays[kind].max) {
        delay = FIGHTSTG_eventDelays[kind].max;
    }
    return delay;
}

/* the status events FIGHTSTG_cureStatus clears, by kind of status, */
u8 FIGHTSTG_statusEvents[] = {
    EVENT_STATUS_DAMAGE, EVENT_STATUS_END, EVENT_STATUS_END + 1, EVENT_STATUS_END + 2,
    EVENT_RESTRICTION_END, EVENT_RESTRICTION_END + 1, 0, 0,
};
/* and the flags it clears with them (all six for kind 3) */
u8 FIGHTSTG_statusFlags[] = {
    FIGHTER_POISONED, FIGHTER_PARALYZED, FIGHTER_CONFUSED, 0x3F, /* all six */
};

/* An item's cure (FIGHTSTG_events.funcs.useItem): items 0xBE-0xC5 clear a
   status of the fighter and remove its events, 0xC4 and 0xC5 all of them */
void FIGHTSTG_cureStatus(u8 side, s32 fighter, s32 item) {
    s32 kind;
    s32 index;
    BattleFighter *fighters;
    s32 i;
    s32 row;

    switch (item) {
    case 0xBE:
    case 0xBF:
    default:
        kind = 0;
        break;
    case 0xC0:
    case 0xC1:
        kind = 1;
        break;
    case 0xC2:
    case 0xC3:
        kind = 2;
        break;
    case 0xC4:
    case 0xC5:
        kind = 3;
        break;
    }
    /* the match depends on the row local, and on kind becoming the event type */
    row = side != 0;
    fighters = FIGHTSTG_battle.fighters[row];
    if (fighters[fighter].id == 0) {
        return;
    }
    fighters[fighter].flags &= ~FIGHTSTG_statusFlags[kind];
    if (kind != 3) {
        kind = FIGHTSTG_statusEvents[kind];
        index = FIGHTSTG_events.funcs.find(kind, side, fighter);
        if (index >= 0) {
            FIGHTSTG_events.events[index].type = 0;
        }
    } else {
        for (i = 0; i < 6; i++) {
            index = FIGHTSTG_events.funcs.find(FIGHTSTG_statusEvents[i], side, fighter);
            if (index >= 0) {
                FIGHTSTG_events.events[index].type = 0;
            }
        }
    }
}

/* Queues the player's turn (event 2) in delay */
void FIGHTSTG_queuePlayerTurn(s32 delay) {
    FIGHTSTG_newEvent.type = EVENT_PLAYER_TURN;
    FIGHTSTG_newEvent.delay = delay;
    FIGHTSTG_newEvent.args[0] = -1;
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Queues the enemy's turn (event 3) in delay */
void FIGHTSTG_queueEnemyTurn(s32 delay) {
    FIGHTSTG_newEvent.type = EVENT_ENEMY_TURN;
    FIGHTSTG_newEvent.delay = delay;
    FIGHTSTG_newEvent.args[0] = -1;
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Ends the battle: queues event 1 ahead of the others, with how it ended
   (BATTLE_FLED, BATTLE_WON or BATTLE_LOST) for WFIGHTMN */
void FIGHTSTG_endBattle(s32 result) {
    FIGHTSTG_newEvent.type = EVENT_END_BATTLE;
    FIGHTSTG_newEvent.delay = 1;
    FIGHTSTG_newEvent.args[0] = -1;
    FIGHTSTG_events.funcs.result = result;
    FIGHTSTG_pushEventFirst(&FIGHTSTG_newEvent);
}

/* Queues side's attempt to run away (event 4) */
void FIGHTSTG_queueRunAway(u8 side) {
    FIGHTSTG_newEvent.type = EVENT_RUN_AWAY;
    FIGHTSTG_newEvent.delay = FIGHTSTG_getEventDelay(side, 1);
    FIGHTSTG_newEvent.args[0] = side;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[side != 0];
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Queues the end of side's automatic recovery (item 0xBD), or pushes back the
   one already queued */
void FIGHTSTG_queueAutoRecoverEnd(u8 side) {
    s32 other = side != 0;
    s32 i = FIGHTSTG_findEvent(EVENT_AUTO_RECOVER_END, side, other);
    s32 time = FIGHTSTG_getEventDelay(side, 2);

    if (i >= 0) {
        QueuedEvent *queued = &FIGHTSTG_events.events[i];

        queued->time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_AUTO_RECOVER_END;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[other];
        FIGHTSTG_newEvent.args[2] = 0xBD;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
}

/* Queues a fighter's recovery of HP (event 6, with what getHeal takes as
   big), or sets the one already queued to 0xBD */
void FIGHTSTG_queueRecovery(u8 side, s32 fighter, s32 big) {
    s32 i = FIGHTSTG_findEvent(EVENT_RECOVERY, side, fighter);

    if (i >= 0) {
        QueuedEvent *queued = &FIGHTSTG_events.events[i];

        queued->args[2] = 0xBD;
    } else {
        FIGHTSTG_newEvent.type = EVENT_RECOVERY;
        FIGHTSTG_newEvent.delay = 1000;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = fighter;
        FIGHTSTG_newEvent.args[2] = big;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
}

/* Queues the field's clearing in time (at most 0x7FFF), or moves the one
   already queued to it */
void FIGHTSTG_queueClearField(s32 time) {
    s32 i;

    FIGHTSTG_events.findType = EVENT_CLEAR_FIELD;
    i = FIGHTSTG_findEventFrom(0);
    if (time > 0x7FFF) {
        time = 0x7FFF;
    }
    if (i >= 0) {
        FIGHTSTG_events.events[i].time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_CLEAR_FIELD;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = -1;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
}

/* Poisons a fighter (FIGHTER_POISONED), and queues its damage or updates the
   one already queued */
void FIGHTSTG_inflictPoison(u8 side, s32 fighter, s32 damage) {
    s32 i = FIGHTSTG_findEvent(EVENT_STATUS_DAMAGE, side, fighter);
    s32 other;
    BattleFighter *entry;

    if (i >= 0) {
        QueuedEvent *queued = &FIGHTSTG_events.events[i];

        queued->args[2] = damage;
    } else {
        FIGHTSTG_newEvent.type = EVENT_STATUS_DAMAGE;
        FIGHTSTG_newEvent.delay = 1000;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = fighter;
        FIGHTSTG_newEvent.args[2] = damage;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
    other = side != 0;
    entry = &FIGHTSTG_battle.fighters[other][fighter];
    entry->flags |= FIGHTER_POISONED;
}

/* Paralyzes side's active fighter (FIGHTER_PARALYZED) with a strength, and
   queues its end, which the strength puts off, or pushes back the one
   already queued */
void FIGHTSTG_inflictParalysis(u8 side, s32 unused, u8 strength) {
    s32 other = side != 0;
    s32 i = FIGHTSTG_findEvent(EVENT_STATUS_END, side, FIGHTSTG_battle.active[other]);
    s32 time;
    BattleFighter *entry;

    FIGHTSTG_events.funcs.unk1 = strength;
    time = FIGHTSTG_getEventDelay(side, 9);
    if (i >= 0) {
        FIGHTSTG_events.events[i].time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_STATUS_END;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[other];
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
    entry = &FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]];
    entry->paralysis = strength;
    entry->flags |= FIGHTER_PARALYZED;
}

/* Confuses side's active fighter (FIGHTER_CONFUSED) with a strength, and
   queues its end (put off by the strength when a technique, fromTech,
   causes it) or pushes back the one already queued */
void FIGHTSTG_inflictConfusion(u8 side, s32 fromTech, u8 strength) {
    s32 other = side != 0;
    s32 i = FIGHTSTG_findEvent(EVENT_STATUS_END + 1, side, FIGHTSTG_battle.active[other]);
    s32 time;
    BattleFighter *entry;

    if (fromTech == 0) {
        time = FIGHTSTG_getEventDelay(side, 8);
    } else {
        FIGHTSTG_events.funcs.unk1 = strength;
        time = FIGHTSTG_getEventDelay(side, 10);
    }
    if (i >= 0) {
        FIGHTSTG_events.events[i].time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_STATUS_END + 1;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[other];
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
    entry = &FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]];
    entry->confusion = strength;
    entry->flags |= FIGHTER_CONFUSED;
}

/* Puts side's active fighter to sleep (FIGHTER_ASLEEP) with a strength, and
   queues its end, which the strength puts off, or pushes back the one
   already queued */
void FIGHTSTG_inflictSleep(u8 side, s32 unused, u8 strength) {
    s32 other = side != 0;
    s32 i = FIGHTSTG_findEvent(EVENT_STATUS_END + 2, side, FIGHTSTG_battle.active[other]);
    s32 time;
    BattleFighter *entry;

    FIGHTSTG_events.funcs.unk1 = strength;
    time = FIGHTSTG_getEventDelay(side, 11);
    if (i >= 0) {
        FIGHTSTG_events.events[i].time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_STATUS_END + 2;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[other];
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
    entry = &FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]];
    entry->sleep = strength;
    entry->flags |= FIGHTER_ASLEEP;
}

/* the event types of FIGHTSTG_queueBoostEnd, by the stat boosted */
s32 FIGHTSTG_boostEvents[] = {
    EVENT_BOOST_END, EVENT_BOOST_END + 1, EVENT_BOOST_END + 2,
};

/* Queues the end of a fighter's boost of stat kind (later when arg3 is
   set), or pushes back the one already queued */
void FIGHTSTG_queueBoostEnd(u8 side, s32 fighter, s32 kind, s32 arg3) {
    s32 i = FIGHTSTG_findEvent(FIGHTSTG_boostEvents[kind], side, fighter);
    s32 time;

    if (arg3 != 0) {
        time = FIGHTSTG_getEventDelay(side, 12);
    } else {
        time = FIGHTSTG_getEventDelay(side, 8);
    }
    if (i >= 0) {
        FIGHTSTG_events.events[i].time = time;
    } else {
        FIGHTSTG_newEvent.type = FIGHTSTG_boostEvents[kind];
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = side;
        FIGHTSTG_newEvent.args[1] = fighter;
        FIGHTSTG_newEvent.args[2] = kind;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
}

/* the event types of FIGHTSTG_startRestriction, by whether the technique's unkA is 14 */
s32 FIGHTSTG_techEvents[] = {
    EVENT_RESTRICTION_END, EVENT_RESTRICTION_END + 1,
};

/* the command being carried out */
BattleAction FIGHTSTG_action = {
    { 0 }, 0, { 0 }, 0, 0, 0, 0, { 0 }, 0, 0, { 0 }, { 0 }, FIGHTSTG_startAction,
};
/* the battle: its fighters, speed and drawing functions */
Battle FIGHTSTG_battle = {
    0, 0, { 0 }, { { { 0 } } }, 0, 0, 0, 0, 0, 0, 0, { 0, 0 },
    FIGHTSTG_countFrames, FIGHTSTG_setSpeed, FIGHTSTG_projectPoint, FIGHTSTG_drawQuad, FIGHTSTG_drawBlendedQuad,
};
/* the fighters' data, loaded one at a time */
FighterCache FIGHTSTG_fighterCache = {
    0, 0, 0, 0, NULL, NULL, { FIGHTSTG_getFighterInfo, FIGHTSTG_cacheFighter, FIGHTSTG_getFighterRange }, FIGHTSTG_getFighterFace,
};
/* the battle's stats and the functions that compute with them */
BattleFuncs FIGHTSTG_battleFuncs = {
    { { 0 }, { 0 } },
    FIGHTSTG_computeStats, FIGHTSTG_computeDamage, FIGHTSTG_computeMagicDamage, FIGHTSTG_getDamage,
    FIGHTSTG_computeCounterDamage, FIGHTSTG_computeHeal, FIGHTSTG_getHeal, FIGHTSTG_rollHit,
    FIGHTSTG_rollMagicHit, FIGHTSTG_rollPoison, FIGHTSTG_rollParalysis, FIGHTSTG_rollConfusion,
    FIGHTSTG_rollSleep, FIGHTSTG_rollKnockOut, FIGHTSTG_rollSteal, FIGHTSTG_rollDrain,
    FIGHTSTG_rollDedigivolve, FIGHTSTG_rollStatusRaise, FIGHTSTG_rollNoSwitch, FIGHTSTG_rollNoDigivolve,
#if VERSION_EU
    FIGHTSTG_rollCounter,
#endif
    FIGHTSTG_testRunAway, FIGHTSTG_testWakeUp, FIGHTSTG_testConfusion, FIGHTSTG_testParalysis,
    FIGHTSTG_changeBoost, FIGHTSTG_getGaugeGain, FIGHTSTG_getTechCost,
};

/* Restricts the partner with technique tech: sets its flag 0x10 or 0x20 by
   the technique's unkA, and queues the restriction's end (by the power) or
   pushes back the one already queued */
void FIGHTSTG_startRestriction(s32 tech) {
    TechData *entry = &TECHS[tech - 1];
    s32 kind;
    s32 fighter;
    s32 i;
    s32 time;
    BattleFighter *target;

    kind = 0;
    if (entry->effect != TECH_EFFECT_NO_SWITCH) {
        kind = entry->effect == TECH_EFFECT_NO_DIGIVOLVE;
    }
    fighter = FIGHTSTG_battle.active[0];
    i = FIGHTSTG_findEvent(FIGHTSTG_techEvents[kind], 0, fighter);
    time = (RANDOM.next() % 101 + 100) * entry->effectPower;

    if (i >= 0) {
        QueuedEvent *queued = &FIGHTSTG_events.events[i];

        queued->time = time;
    } else {
        FIGHTSTG_newEvent.type = FIGHTSTG_techEvents[kind];
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = 0;
        FIGHTSTG_newEvent.args[1] = fighter;
        FIGHTSTG_newEvent.args[2] = kind;
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
    target = &FIGHTSTG_battle.fighters[0][fighter];
    if (kind == 0) {
        target->flags |= FIGHTER_NO_SWITCH;
    } else {
        target->flags |= FIGHTER_NO_DIGIVOLVE;
    }
}

/* Queues the partner's technique tech, to run as its command */
void FIGHTSTG_queuePartnerTech(s32 tech) {
    FIGHTSTG_newEvent.type = EVENT_PARTNER_TECH;
    FIGHTSTG_newEvent.delay = 0x7FFF;
    FIGHTSTG_newEvent.args[0] = 0;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[0];
    FIGHTSTG_newEvent.args[2] = tech;
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Queues the partner's digivolution for the battle (event 18), now */
void FIGHTSTG_queueBlast(void) {
    FIGHTSTG_newEvent.type = EVENT_BLAST;
    FIGHTSTG_newEvent.delay = 0;
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Queues the end of the partner's digivolution for the battle (event 19),
   after delay kind + 3 */
void FIGHTSTG_queueBlastEnd(s32 kind) {
    FIGHTSTG_newEvent.type = EVENT_BLAST_END;
    FIGHTSTG_newEvent.delay = FIGHTSTG_getEventDelay(0, kind + 3);
    FIGHTSTG_newEvent.args[0] = 0;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[0];
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
}

/* Queues the fall of side's active fighter (event 20), first */
void FIGHTSTG_queueKnockOut(u8 side) {
    FIGHTSTG_newEvent.type = EVENT_KNOCK_OUT;
    FIGHTSTG_newEvent.delay = 1;
    FIGHTSTG_newEvent.args[0] = side;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[side != 0];
    FIGHTSTG_pushEventFirst(&FIGHTSTG_newEvent);
}

/* Queues the end of the partner's special state (event 21): the USA version
   pushes back the one already queued */
void FIGHTSTG_queueSpecialEnd(void) {
#if VERSION_US
    s32 i = FIGHTSTG_findEvent(EVENT_SPECIAL_END, 0, FIGHTSTG_battle.active[0]);
    s32 time = FIGHTSTG_getEventDelay(0, 8);

    if (i >= 0) {
        QueuedEvent *queued = &FIGHTSTG_events.events[i];

        queued->time = time;
    } else {
        FIGHTSTG_newEvent.type = EVENT_SPECIAL_END;
        FIGHTSTG_newEvent.delay = time;
        FIGHTSTG_newEvent.args[0] = 0;
        FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[0];
        FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    }
#elif VERSION_EU
    FIGHTSTG_newEvent.type = EVENT_SPECIAL_END;
    FIGHTSTG_newEvent.delay = 1;
    FIGHTSTG_newEvent.args[0] = 0;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[0];
    FIGHTSTG_pushEventFirst(&FIGHTSTG_newEvent);
#endif
}

/* Queues the partner's digidevolution, first */
void FIGHTSTG_queueDigidevolve(void) {
    FIGHTSTG_newEvent.type = EVENT_DIGIDEVOLVE;
    FIGHTSTG_newEvent.delay = 1;
    FIGHTSTG_newEvent.args[0] = 0;
    FIGHTSTG_newEvent.args[1] = FIGHTSTG_battle.active[0];
    FIGHTSTG_pushEventFirst(&FIGHTSTG_newEvent);
}

/* Queues the coming in of the last battle's third enemy, first */
void FIGHTSTG_queueLastEnemy(void) {
    FIGHTSTG_newEvent.type = EVENT_LAST_ENEMY;
    FIGHTSTG_newEvent.delay = 1;
    FIGHTSTG_pushEventFirst(&FIGHTSTG_newEvent);
}

/* Weakens the enemy in BATTLE_KIND_FINAL_LAST: halves its boosts of stats 1 and 2
   and queues the end (event 24) in 3000 */
void FIGHTSTG_weakenEnemy(void) {
    BattleTableEntry *entry;

    FIGHTSTG_newEvent.type = EVENT_WEAKNESS_END;
    FIGHTSTG_newEvent.delay = 3000;
    FIGHTSTG_pushEvent(&FIGHTSTG_newEvent);
    entry = FIGHTSTG_battleTableFunc(0x1D3);
    FIGHTSTG_battle.weakened = 1;
    FIGHTSTG_battle.fighters[1][0].boosts[1] = -entry->stats[1] >> 1;
    FIGHTSTG_battle.fighters[1][0].boosts[3] = -entry->stats[2] >> 1;
}

/* Ends the enemy's weakness now: its queued event 24 runs next */
void FIGHTSTG_endEnemyWeakness(void) {
    s32 i = FIGHTSTG_events.funcs.first(EVENT_WEAKNESS_END);

    if (i >= 0) {
        FIGHTSTG_events.events[i].time = 1;
    }
}

/* TECH_EFFECT_POISON: poisons the target when rollPoison lets it, twice as
   strongly when the acting fighter is special */
void FIGHTSTG_tryPoison(void) {
    s32 side = FIGHTSTG_action.side != 0;
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
    s32 value = FIGHTSTG_battleFuncs.rollPoison(FIGHTSTG_action.side, FIGHTSTG_action.tech);

    if (value != 0) {
        if (fighter->special) {
            value *= 2;
        }
        FIGHTSTG_action.effects[TECH_EFFECT_POISON] = value;
    }
}

/* TECH_EFFECT_PARALYSIS: paralyzes the target when rollParalysis lets it, with
   the technique's effectPower or the accessory's, twice as strongly when the acting
   fighter is special */
void FIGHTSTG_tryParalysis(void) {
    BattleAction *action = &FIGHTSTG_action;
    BattleFuncs *funcs = &FIGHTSTG_battleFuncs;
    s32 side = action->side != 0;
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
    TechData *entry;
    s32 value;

    if (funcs->rollParalysis(action->side, action->tech)) {
        entry = &TECHS[action->tech - 1];
        if (entry->effect < TECH_EFFECT_FIRST) {
            value = funcs->stats[0].paralysisPower;
        } else {
            value = entry->effectPower;
        }
        if (fighter->special) {
            value *= 2;
        }
        FIGHTSTG_action.effects[TECH_EFFECT_PARALYSIS] = value;
    }
}

/* TECH_EFFECT_CONFUSION: confuses the target when rollConfusion lets it, with
   the technique's effectPower or the accessory's, twice as strongly when the acting
   fighter is special */
void FIGHTSTG_tryConfusion(void) {
    BattleAction *action = &FIGHTSTG_action;
    BattleFuncs *funcs = &FIGHTSTG_battleFuncs;
    s32 side = action->side != 0;
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
    TechData *entry;
    s32 value;

    if (funcs->rollConfusion(action->side, action->tech)) {
        entry = &TECHS[action->tech - 1];
        if (entry->effect < TECH_EFFECT_FIRST) {
            value = funcs->stats[0].confusionPower;
        } else {
            value = entry->effectPower;
        }
        if (fighter->special) {
            value *= 2;
        }
        FIGHTSTG_action.effects[TECH_EFFECT_CONFUSION] = value;
    }
}

/* TECH_EFFECT_SLEEP: puts the target to sleep when rollSleep lets it, twice
   as strongly when the acting fighter is special */
void FIGHTSTG_trySleep(void) {
    s32 side = FIGHTSTG_action.side != 0;
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
    TechData *entry;
    s32 value;

    if (FIGHTSTG_battleFuncs.rollSleep(FIGHTSTG_action.side, FIGHTSTG_action.tech)) {
        entry = &TECHS[FIGHTSTG_action.tech - 1];
        value = entry->effectPower;
        if (fighter->special) {
            value *= 2;
        }
        FIGHTSTG_action.effects[entry->effect] = value;
    }
}

/* TECH_EFFECT_KNOCK_OUT: knocks the target out when rollKnockOut lets it */
void FIGHTSTG_tryKnockOut(void) {
    BattleAction *action = &FIGHTSTG_action;

    if (FIGHTSTG_battleFuncs.rollKnockOut(action->side, action->tech)) {
        action->effects[TECH_EFFECT_KNOCK_OUT] = 1;
    }
}

/* TECH_EFFECT_MULTI_HIT and the triple-hit accessory: rolls the other hits, 3
   or the technique's unk11 in all; in BATTLE_KIND_FINAL_LAST the player's
   missed first hit makes them all miss */
void FIGHTSTG_rollMultiHit(void) {
    s32 count = 3;
    BattleAction *action = &FIGHTSTG_action;
    Battle *battle = &FIGHTSTG_battle;
    TechData *entry = &TECHS[action->tech - 1];
    s32 i;
    s32 side;

    side = action->side;
    if (entry->effect >= TECH_EFFECT_FIRST) {
        count = entry->hitCount;
    }
#if VERSION_US
    action->hitsLanded = 0;
    action->hitCount = 0;
#elif VERSION_EU
    action->hitsLanded = action->hits[0];
    action->hitCount = 1;
#endif
    if (side == 0 && battle->kind == BATTLE_KIND_FINAL_LAST && action->hits[0] == 0) {
        action->hitCount = count;
    } else {
#if VERSION_US
        for (i = 0; i < count; i++) {
#elif VERSION_EU
        for (i = 1; i < count; i++) {
#endif
            if (FIGHTSTG_battleFuncs.rollHit(FIGHTSTG_action.side, FIGHTSTG_action.tech) != 0) {
                FIGHTSTG_action.hits[FIGHTSTG_action.hitCount++] = 1;
                FIGHTSTG_action.hitsLanded++;
            } else {
                FIGHTSTG_action.hits[FIGHTSTG_action.hitCount++] = 0;
            }
        }
    }
    FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT] = 1;
}

/* When rollDrain allows it, the action's drain becomes its damage times a 128th of
 * the technique's effectPower (effect 8) or the player's drainPower, doubled when the
 * acting fighter is special. The match depends on each branch doubling
 * and scaling its own value. */
void FIGHTSTG_tryDrain(void) {
    BattleAction *action = &FIGHTSTG_action;
    BattleFuncs *funcs = &FIGHTSTG_battleFuncs;
    s32 side = action->side != 0;
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[side][FIGHTSTG_battle.active[side]];
    TechData *entry;
    s32 value;

    if (funcs->rollDrain(action->side, action->tech)) {
        entry = &TECHS[action->tech - 1];
        if (entry->effect == TECH_EFFECT_DRAIN) {
            value = entry->effectPower;
            if (fighter->special) {
                value *= 2;
            }
            action->drain = action->damage * value / 128;
        } else {
            value = funcs->stats[0].drainPower;
            if (fighter->special) {
                value *= 2;
            }
            action->drain = action->damage * value / 128;
        }
        FIGHTSTG_action.effects[TECH_EFFECT_DRAIN] = 1;
    }
}

/* TECH_EFFECT_ENEMY_ONLY outside its own enemy's hands: marks the effect,
   which takes the place of the hit */
void FIGHTSTG_markEnemyOnly(void) {
    BattleAction *action = &FIGHTSTG_action;
    TechData *e = &TECHS[action->tech - 1];

    action->effects[e->effect] = e->effect;
}

/* TECH_EFFECT_CRITICAL: marks the effect, which rollCritical has used */
void FIGHTSTG_markCritical(void) {
    BattleAction *action = &FIGHTSTG_action;
    TechData *entry = &TECHS[action->tech - 1];

    action->effects[entry->effect] = entry->effect;
}

/* TECH_EFFECT_STEAL: when the enemy's active fighter holds an
 * item and rollSteal lets the player take it, marks the effect and loads the item
 * names. The match depends on funcs being a const pointer: the front end puts
 * its value in the call, so only the %hi of its own initialization is left
 * for CSE to share with the call's address. */
void FIGHTSTG_trySteal(void) {
    BattleFuncs *const funcs = &FIGHTSTG_battleFuncs;
    BattleFighter *enemies = FIGHTSTG_battle.fighters[1];
    TechData *entry;

    if (enemies[FIGHTSTG_battle.active[1]].item > 0) {
        if (funcs->rollSteal(0, FIGHTSTG_action.tech) != 0) {
            entry = &TECHS[FIGHTSTG_action.tech - 1];
            FIGHTSTG_action.effects[entry->effect] = 1;
            FILE_CACHE.request(TEXT_FILE(TEXT_ITEM_NAMES));
        }
    }
}

/* TECH_EFFECT_LOWER_ATTACK: lowers the attack of the other side's active
 * fighter by the technique's effectPower in 128ths and starts its event (not when
 * side 0 acts with BATTLE_SETUP.unk3E[8] set). The match depends on team
 * being a u8. */
void FIGHTSTG_lowerAttack(void) {
    u8 team = FIGHTSTG_action.side != 0;
    TechData *entry;

    if (team == 0 && BATTLE_SETUP.unk3E[8] != 0) {
        return;
    }
    entry = &TECHS[FIGHTSTG_action.tech - 1];
    FIGHTSTG_battleFuncs.changeBoost((u8)(0x10 - FIGHTSTG_action.side), FIGHTSTG_battle.active[1 - team], 0, -entry->effectPower);
    FIGHTSTG_queueBoostEnd((u8)(0x10 - FIGHTSTG_action.side), FIGHTSTG_battle.active[1 - team], 0, FIGHTSTG_action.tech);
    FIGHTSTG_action.effects[entry->effect] = entry->effectPower;
}

/* TECH_EFFECT_LOWER_DEFENSE: lowers the defense of the other side's active fighter
   by the technique's effectPower in 128ths and starts its event */
void FIGHTSTG_lowerDefense(void) {
    s32 other = 1 - (FIGHTSTG_action.side != 0);
    TechData *entry = &TECHS[FIGHTSTG_action.tech - 1];

    FIGHTSTG_battleFuncs.changeBoost((u8)(0x10 - FIGHTSTG_action.side), FIGHTSTG_battle.active[other], 1, -entry->effectPower);
    FIGHTSTG_queueBoostEnd((u8)(0x10 - FIGHTSTG_action.side), FIGHTSTG_battle.active[other], 1, FIGHTSTG_action.tech);
    FIGHTSTG_action.effects[entry->effect] = entry->effectPower;
}

/* TECH_EFFECT_DRAIN_MP: takes the technique's effectPower in 128ths of the player's
   fighter's max MP, at most what it has, as the action's drain */
void FIGHTSTG_drainMp(void) {
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    TechData *entry = &TECHS[FIGHTSTG_action.tech - 1];

    if (fighter->mp != 0) {
        FIGHTSTG_action.drain = fighter->maxMp * entry->effectPower / 128;
        if (fighter->mp < FIGHTSTG_action.drain) {
            FIGHTSTG_action.drain = fighter->mp;
        }
        FIGHTSTG_action.effects[entry->effect] = FIGHTSTG_action.drain;
    }
}

/* TECH_EFFECT_RAISE_ONE_STATUS: when rollStatusRaise lets it, raises one of
   the partner's status values at random by the technique's effectPower */
void FIGHTSTG_raiseOneStatus(void) {
    s32 i = RANDOM.next() % 2;
    TechData *entry;
    PartnerStats *stats;

    if (FIGHTSTG_battleFuncs.rollStatusRaise(FIGHTSTG_action.side, FIGHTSTG_action.tech)) {
        entry = &TECHS[FIGHTSTG_action.tech - 1];
        stats = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]));
        stats->status[i] += entry->effectPower;
        FIGHTSTG_action.effects[entry->effect] = 1 << i;
    }
}

/* TECH_EFFECT_RAISE_EACH_STATUS: raises each of the partner's status values
   that rollStatusRaise lets by the technique's effectPower */
void FIGHTSTG_raiseEachStatus(void) {
    TechData *entry = &TECHS[FIGHTSTG_action.tech - 1];
    PartnerStats *stats = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]));
    s32 i;

    for (i = 0; i < 3; i++) {
        if (FIGHTSTG_battleFuncs.rollStatusRaise(FIGHTSTG_action.side, FIGHTSTG_action.tech)) {
            stats->status[i] += entry->effectPower;
            FIGHTSTG_action.effects[entry->effect] |= 1 << i;
        }
    }
}

/* TECH_EFFECT_RAISE_ALL_STATUS: when rollStatusRaise lets it, raises all of
   the partner's status values by the technique's effectPower */
void FIGHTSTG_raiseAllStatus(void) {
    BattleAction *action = &FIGHTSTG_action;
    TechData *entry = &TECHS[action->tech - 1];
    PartnerStats *stats = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]));
    s32 i;

    if (FIGHTSTG_battleFuncs.rollStatusRaise(action->side, action->tech)) {
        for (i = 0; i < 3; i++) {
            stats->status[i] += entry->effectPower;
        }
        FIGHTSTG_action.effects[entry->effect] = 7;
    }
}

/* TECH_EFFECT_NO_SWITCH: marks the effect when rollNoSwitch lets it */
void FIGHTSTG_tryNoSwitch(void) {
    TechData *entry;

    if (FIGHTSTG_battleFuncs.rollNoSwitch(FIGHTSTG_action.side, FIGHTSTG_action.tech)) {
        entry = &TECHS[FIGHTSTG_action.tech - 1];
        FIGHTSTG_action.effects[entry->effect] = 1;
    }
}

/* Starts a TECH_EFFECT_DOUBLE_MAGIC technique: two magic hits, each with the
   damage of technique 0x1B9 or 0x1BA */
void FIGHTSTG_startDoubleMagic(void) {
#if VERSION_EU
    s32 files[2] = { 0x1B9, 0x1BA };
#endif
    s32 i;

    FIGHTSTG_action.hitsLanded = 0;
    FIGHTSTG_action.hitCount = 2;
    for (i = 0; i < 2; i++) {
        if (FIGHTSTG_battleFuncs.rollMagicHit(FIGHTSTG_action.side, FIGHTSTG_action.tech)) {
            FIGHTSTG_action.hits[i] = 1;
#if VERSION_EU
            FIGHTSTG_action.hitDamage[i] = FIGHTSTG_battleFuncs.computeMagicDamage(FIGHTSTG_action.side, files[i]);
#endif
            FIGHTSTG_action.hitsLanded++;
        }
    }
#if VERSION_US
    FIGHTSTG_action.hitDamage[0] = FIGHTSTG_battleFuncs.computeMagicDamage(FIGHTSTG_action.side, 0x1B9);
    FIGHTSTG_action.hitDamage[1] = FIGHTSTG_battleFuncs.computeMagicDamage(FIGHTSTG_action.side, 0x1BA);
#endif
    FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT] = 1;
}

/* Starts a TECH_EFFECT_END_BATTLE technique: in BATTLE_KIND_UNK2 its effect,
   elsewhere a plain physical hit */
void FIGHTSTG_startEndBattle(void) {
    TechData *entry;

    if (FIGHTSTG_battle.kind == BATTLE_KIND_UNK2) {
        entry = &TECHS[FIGHTSTG_action.tech - 1];
        FIGHTSTG_action.effects[entry->effect] = 1;
    } else {
        FIGHTSTG_action.hits[0] = FIGHTSTG_battleFuncs.rollHit(FIGHTSTG_action.side, FIGHTSTG_action.tech);
        FIGHTSTG_action.hitCount++;
        FIGHTSTG_action.damage = FIGHTSTG_battleFuncs.computeDamage(FIGHTSTG_action.side, FIGHTSTG_action.tech);
    }
}

/* Carries out the effect of a technique whose hit landed */
void FIGHTSTG_applyTechEffect(void) {
    TechData *entry = &TECHS[FIGHTSTG_action.tech - 1];

    switch (entry->effect) {
    case TECH_EFFECT_POISON:
        FIGHTSTG_tryPoison();
        break;
    case TECH_EFFECT_PARALYSIS:
        FIGHTSTG_tryParalysis();
        break;
    case TECH_EFFECT_CONFUSION:
        FIGHTSTG_tryConfusion();
        break;
    case TECH_EFFECT_SLEEP:
        FIGHTSTG_trySleep();
        break;
    case TECH_EFFECT_KNOCK_OUT:
        FIGHTSTG_tryKnockOut();
        break;
    case TECH_EFFECT_DRAIN:
        FIGHTSTG_tryDrain();
        break;
    case TECH_EFFECT_STEAL:
        FIGHTSTG_trySteal();
        break;
    case TECH_EFFECT_LOWER_ATTACK:
        FIGHTSTG_lowerAttack();
        break;
    case TECH_EFFECT_CRITICAL:
        FIGHTSTG_markCritical();
        break;
    case TECH_EFFECT_LOWER_DEFENSE:
        FIGHTSTG_lowerDefense();
        break;
    case TECH_EFFECT_DRAIN_MP:
        FIGHTSTG_drainMp();
        break;
    case TECH_EFFECT_RAISE_ONE_STATUS:
        FIGHTSTG_raiseOneStatus();
        break;
    case TECH_EFFECT_RAISE_EACH_STATUS:
        FIGHTSTG_raiseEachStatus();
        break;
    case TECH_EFFECT_RAISE_ALL_STATUS:
        FIGHTSTG_raiseAllStatus();
        break;
    case TECH_EFFECT_NO_SWITCH:
        FIGHTSTG_tryNoSwitch();
        break;
    }
}


/* Starts side's technique: rolls its hits and damage, then its effect or, for
   the player's plain techniques, the accessories' effects; outside normal
   battles WFIGHTMN_limitDamage caps the damage */
void FIGHTSTG_startAction(u8 side, s32 tech) {
    TechData *entry;

    HEAP.zero(&FIGHTSTG_action, 0x68);
    entry = &TECHS[tech - 1];
    FIGHTSTG_action.side = side;
    FIGHTSTG_action.tech = tech;
    if (entry->effect == TECH_EFFECT_DOUBLE_MAGIC) {
        FIGHTSTG_startDoubleMagic();
    } else if (entry->effect == TECH_EFFECT_END_BATTLE) {
        FIGHTSTG_startEndBattle();
    } else {
        /* the match depends on the fighter's pointer sum */
        if (entry->effect == TECH_EFFECT_ENEMY_ONLY &&
            (side == 0 || FIGHTSTG_battleTableFunc((FIGHTSTG_battle.fighters[1] + FIGHTSTG_battle.active[1])->id)->unk8[0] != tech)) {
            FIGHTSTG_markEnemyOnly();
            return;
        }
        switch (entry->icon) {
        case TECH_PHYSICAL:
            FIGHTSTG_action.hits[0] = FIGHTSTG_battleFuncs.rollHit(side, tech);
            FIGHTSTG_action.hitCount++;
            FIGHTSTG_action.damage = FIGHTSTG_battleFuncs.computeDamage(side, tech);
            /* the match depends on the second test of unkA 9, which the
               compiler merges with the first and with case 3's */
            if (side == 0) {
                if (entry->effect < TECH_EFFECT_FIRST) {
                    if (entry->unk10 == 11 || entry->unk10 == 12) {
                        break;
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].tripleHit) {
                        FIGHTSTG_rollMultiHit();
                        break;
                    }
                    if (FIGHTSTG_action.hits[0] == 0) {
                        break;
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].poisonChance) {
                        FIGHTSTG_tryPoison();
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].paralysisChance) {
                        FIGHTSTG_tryParalysis();
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].confusionChance) {
                        FIGHTSTG_tryConfusion();
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].knockOutChance) {
                        FIGHTSTG_tryKnockOut();
                    }
                    if (FIGHTSTG_battleFuncs.stats[0].drainChance) {
                        FIGHTSTG_tryDrain();
                    }
                } else if (entry->effect == TECH_EFFECT_MULTI_HIT) {
                    FIGHTSTG_rollMultiHit();
                } else if (FIGHTSTG_action.hits[0]) {
                    FIGHTSTG_applyTechEffect();
                }
            } else if (entry->effect >= TECH_EFFECT_FIRST) {
                if (entry->effect == TECH_EFFECT_MULTI_HIT) {
                    FIGHTSTG_rollMultiHit();
                } else if (FIGHTSTG_action.hits[0]) {
                    FIGHTSTG_applyTechEffect();
                }
            }
            break;
        case TECH_MAGIC:
            FIGHTSTG_action.hits[0] = FIGHTSTG_battleFuncs.rollMagicHit(side, tech);
            FIGHTSTG_action.hitCount++;
            FIGHTSTG_action.damage = FIGHTSTG_battleFuncs.computeMagicDamage(side, tech);
            if (entry->effect < TECH_EFFECT_FIRST) {
                break;
            }
            if (entry->effect == TECH_EFFECT_MULTI_HIT) {
                FIGHTSTG_rollMultiHit();
            } else if (FIGHTSTG_action.hits[0]) {
                FIGHTSTG_applyTechEffect();
            }
            break;
        }
    }
    if (FIGHTSTG_battle.kind != BATTLE_KIND_NORMAL) {
        FIGHTSTG_action.damage = WFIGHTMN_limitDamage(side, FIGHTSTG_action.damage, FIGHTSTG_action.effects[TECH_EFFECT_MULTI_HIT] ? FIGHTSTG_action.hitsLanded : 0);
    }
}

/* How many frames the battle moves on this frame by its speed mode: as many
   as went by, none, a quarter of them or twice as many */
void FIGHTSTG_countFrames(void) {
    BattleSpeed *speed = &FIGHTSTG_battle.speed;
    s32 time;

    switch (speed->mode) {
    case 0:
    default:
        FIGHTSTG_battle.frames = GFX.funcs.getFrameTime();
        break;
    case 1:
        FIGHTSTG_battle.frames = 0;
        break;
    case 2:
        time = GFX.funcs.getFrameTime();
        FIGHTSTG_battle.frames = 0;
        speed->rest += time;
        while (speed->rest > 4) {
            FIGHTSTG_battle.frames++;
            speed->rest -= 4;
        }
        break;
    case 3:
        FIGHTSTG_battle.frames = GFX.funcs.getFrameTime() * 2;
        break;
    }
}

/* Sets the battle's speed mode and counts this frame again */
void FIGHTSTG_setSpeed(s32 mode) {
    FIGHTSTG_battle.speed.mode = mode;
    FIGHTSTG_battle.speed.rest = 0;
    FIGHTSTG_countFrames();
}

void FIGHTSTG_projectPoint(Layer *layer, SVECTOR *pos, ShortVec3 *out) {
    s32 shift = 16 - layer->getOtShift(layer);
    DVECTOR screen;
    MATRIX matrix;
    s32 z;

    gte_CompMatrix(&GsWSMATRIX, &IDENTITY_MATRIX, &matrix);
    gte_SetRotMatrix(&matrix);
    gte_SetTransMatrix(&matrix);
    gte_ldv0_unaligned(pos);
    gte_rtps();
    gte_stsxy(&screen);
    gte_stszotz(&z);
    out->x = screen.vx;
    out->y = screen.vy;
    out->z = z >> shift;
}

/* A Gouraud-shaded quad on a layer, blended when semi is set; the match
   depends on setSemiTrans inside the if and on poly moving on past it */
void FIGHTSTG_drawShadedQuad(s32 layerId, s32 depth, DVECTOR *xy, CVECTOR *colors, s32 semi) {
    Layer *layer = GFX.funcs.getLayer(layerId);
    u_long *ot = (u_long *)layer->getOtEntry(layer, depth);
    POLY_G4 *poly = GFX.funcs.getPrim();
    DR_TPAGE *mode;

    *(CVECTOR *)&poly->r0 = colors[0];
    *(CVECTOR *)&poly->r1 = colors[1];
    *(CVECTOR *)&poly->r2 = colors[2];
    *(CVECTOR *)&poly->r3 = colors[3];
    setPolyG4(poly);
    if (semi) {
        setSemiTrans(poly, 1);
    }
    poly->x0 = xy[0].vx;
    poly->x1 = xy[1].vx;
    poly->x2 = xy[2].vx;
    poly->x3 = xy[3].vx;
    poly->y0 = xy[0].vy;
    poly->y1 = xy[1].vy;
    poly->y2 = xy[2].vy;
    poly->y3 = xy[3].vy;
    addPrim(ot, poly);
    poly++;
    if (semi) {
        mode = (DR_TPAGE *)poly;
        setlen(mode, 1);
        mode->code[0] = 0xE1000245;
        addPrim(ot, mode);
        poly = (POLY_G4 *)(mode + 1);
    }
    GFX.funcs.setPrim(poly);
}

/* A Gouraud-shaded quad on a layer */
void FIGHTSTG_drawQuad(s32 layerId, s32 depth, DVECTOR *xy, CVECTOR *colors) {
    FIGHTSTG_drawShadedQuad(layerId, depth, xy, colors, 0);
}

/* A Gouraud-shaded quad on a layer, blended */
void FIGHTSTG_drawBlendedQuad(s32 layerId, s32 depth, DVECTOR *xy, CVECTOR *colors) {
    FIGHTSTG_drawShadedQuad(layerId, depth, xy, colors, 1);
}

/* the match depends on reaching the cache through the symbol until a fighter
   is found, and on each branch storing and returning its own info */
FighterInfo *FIGHTSTG_getFighterInfo(s32 id) {
    FightersFile *file;
    FighterEntry *entry;
    u8 *partners;
    u8 *enemies;
    FighterCache *cache;
    FighterInfo *info;
    s32 i;

    if (id == FIGHTSTG_fighterCache.id) {
        if (FIGHTSTG_fighterCache.isEnemy) {
            return FIGHTSTG_fighterCache.enemyInfo;
        }
        return FIGHTSTG_fighterCache.partnerInfo;
    }
    file = (FightersFile *)FILE_CACHE.load(FILE_FIGHTERS);
    entry = (FighterEntry *)((u8 *)file + file->entries);
    partners = (u8 *)file + file->partners;
    enemies = (u8 *)file + file->enemies;
    while (entry->id != 0) {
        if (entry->id == id) {
            FIGHTSTG_fighterCache.id = id;
            cache = &FIGHTSTG_fighterCache;
            cache->index = i = entry->index;
            cache->kind = entry->kind;
            cache->isEnemy = entry->kind >= 0x3A;
            if (cache->isEnemy) {
                info = (FighterInfo *)(enemies + i * 0x48);
                cache->partnerInfo = info;
                cache->enemyInfo = info;
                return info;
            } else {
                info = (FighterInfo *)(partners + i * 0xC4);
                cache->partnerInfo = info;
                cache->enemyInfo = info;
                return info;
            }
        }
        entry++;
    }
    return NULL;
}

void FIGHTSTG_cacheFighter(s32 index) {
    FightersFile *file = (FightersFile *)FILE_CACHE.load(FILE_FIGHTERS);
    FighterEntry *entries = (FighterEntry *)((u8 *)file + file->entries);
    u8 *partners = (u8 *)file + file->partners;
    u8 *enemies = (u8 *)file + file->enemies;
    FighterEntry *entry = &entries[index];
    FighterInfo *info;
    s32 i;
    FighterCache *cache = &FIGHTSTG_fighterCache;

    cache->id = entry->id;
    cache->index = i = entry->index;
    cache->kind = entry->kind;
    cache->isEnemy = entry->kind >= 0x3A;
    if (cache->isEnemy == 0) {
        info = (FighterInfo *)(partners + i * 0xC4);
    } else {
        info = (FighterInfo *)(enemies + i * 0x48);
    }
    cache->partnerInfo = info;
    cache->enemyInfo = info;
}

FaceRect *FIGHTSTG_getFighterFace(s32 id) {
    s32 *file = (s32 *)FILE_CACHE.load(FILE_FIGHTERS);

    return (FaceRect *)(FIGHTSTG_getFighterInfo(id)->face - file[0] + (s32)file);
}

void FIGHTSTG_getFighterRange(u32 enemy, s32 *min, s32 *max) {
    FightersFile *file = (FightersFile *)FILE_CACHE.load(FILE_FIGHTERS);
    FighterEntry *entry = (FighterEntry *)((u8 *)file + file->entries);
    s32 lo = 0xFF;
    s32 hi = 0;
    s32 i = 0;

    while (entry->id != 0) {
        if ((entry->kind >= 0x3A) == enemy) {
            if (i < lo) {
                lo = i;
            }
            if (hi < i) {
                hi = i;
            }
        }
        entry++;
        i++;
    }
    *min = lo;
    *max = hi;
}

/* Works out a side's stats into its BattleStats: the partner's totals with
   the fighter's boosts, its resistances and what its equipment and
   accessories add, or the enemy's from its table entry. The match depends on
   one s16 pointer walking the totals, the accessories and the equipment
   alike: its extra sets give it the references that put it before found in
   the global allocator. */
BattleStats *FIGHTSTG_computeStats(u8 side, s32 which, s32 index) {
    PartnerTotals totals;
    BattleStats *stats;
    BattleFighter *fighter;
    DigimonData *digimon;
    DigimonData *other;
    PartnerStats *partner;
    BattleTableEntry *entry;
    ItemInfo *info;
    u8 *data;
    s32 member;
    s16 *values;
    s32 count;
    s32 found;
    s32 i;
    s32 j;

    if (which) {
        stats = &FIGHTSTG_battleFuncs.stats[0];
    } else {
        stats = &FIGHTSTG_battleFuncs.stats[1];
    }
    HEAP.zero(stats, sizeof(BattleStats));
    if (side == 0) {
        fighter = &FIGHTSTG_battle.fighters[0][index];
        member = GAME.funcs.getPartyMember(index);
        digimon = &DIGIMON_DATA[member];
        GAME.funcs.computeStats(member, &totals);
        for (i = RESIST_POISON; i < RESIST_COUNT; i++) {
            stats->resist[i] = digimon->unk2C[i - RESIST_POISON];
        }
        if (digimon->id != fighter->id) {
            other = GET_DIGIMON(fighter->id);
            for (i = 0; i < 5; i++) {
                totals.fields.battle[i] += other->battleStats[i];
            }
            for (i = 0; i < 7; i++) {
                totals.fields.resist[i] += other->resistances[i];
            }
            for (i = RESIST_POISON; i < RESIST_COUNT; i++) {
                stats->resist[i] += other->unk2C[i - RESIST_POISON];
            }
        }
        if (fighter->boosts[0] != 0) {
            totals.fields.battle[0] += fighter->boosts[0];
        }
        if (fighter->boosts[1] != 0) {
            totals.fields.battle[1] += fighter->boosts[1];
        }
        if (fighter->boosts[2] != 0) {
            totals.fields.battle[4] += fighter->boosts[2];
        }
        stats->level = totals.fields.level;
        values = totals.fields.battle;
        for (i = 0; i < 5; i++) {
#if VERSION_EU
            if (values[i] > 0) {
                stats->stats[i] = values[i];
            } else {
                stats->stats[i] = 1;
            }
#else
            stats->stats[i] = values[i];
#endif
        }
        values = totals.fields.resist;
        for (i = 0; i < 7; i++) {
#if VERSION_EU
            if (values[i] > 0) {
                stats->resist[i] = values[i];
            } else {
                stats->resist[i] = 1;
            }
#else
            stats->resist[i] = values[i];
#endif
        }
        stats->flags = fighter->flags;
        partner = GAME.funcs.getPartnerStats(member);
        values = &partner->equip[4];
        for (i = 0; i < 2; i++) {
            if (values[i] != 0) {
                data = GET_ITEM[0](values[i])->data;
                if (data[8] == 17) {
                    stats->resist[RESIST_POISON] = *(u16 *)&data[6];
                } else if (data[8] == 18) {
                    stats->resist[RESIST_PARALYSIS] = *(u16 *)&data[6];
                } else if (data[8] == 19) {
                    stats->resist[RESIST_CONFUSION] = *(u16 *)&data[6];
                } else if (data[8] == 20) {
                    stats->resist[RESIST_SLEEP] = *(u16 *)&data[6];
                } else if (data[8] == 21) {
                    stats->resist[RESIST_KNOCK_OUT] = *(u16 *)&data[6];
                }
            }
        }
        values = partner->equip;
        stats->family = GET_DIGIMON(fighter->id)->unk56[0];
        stats->damageBonus = fighter->charge;
        count = 0;
        for (i = 0; i < 4; i++) {
            if (values[i] > 0) {
                info = GET_ITEM[0](values[i]);
                if (info->type >= 2 && info->type <= 14) {
                    data = info->data;
                    stats->accuracy += data[0xE];
                    if (data[0x12] >= FAMILY_FIRST) {
                        stats->weaponFamilies[count++] = data[0x12];
                    }
                } else {
                    data = info->data;
                    if (data[0x10] != 0) {
                        stats->evasion += data[0x10];
                    }
                }
            }
        }
        found = 0;
        for (i = 0; i < 4; i++) {
            if (i != 1 && values[i] > 0) {
                data = GET_ITEM[0](values[i])->data;
                if (values[i] == 0x97) {
                    stats->poisonChance = data[0x10];
                    stats->poisonPower = data[0x11];
                    found = 1;
                } else if (values[i] == 0xD2) {
                    stats->paralysisChance = data[0x10];
                    stats->paralysisPower = data[0x11];
                    found = 1;
                } else if (values[i] == 0xB4 || values[i] == 0xC2) {
                    stats->confusionChance = data[0x10];
                    stats->confusionPower = data[0x11];
                    found = 1;
                } else if (values[i] == 0x6D || values[i] == 0xBA) {
                    stats->knockOutChance = data[0x10];
                    stats->knockOutPower = data[0x11];
                    found = 1;
                } else if (values[i] == 0x5E || values[i] == 0x93 || values[i] == 0xAD) {
                    stats->drainChance = data[0x10];
                    stats->drainPower = data[0x11];
                    found = 1;
                } else if (values[i] == 0x96 || values[i] == 0xBF) {
                    stats->criticalBonus = data[0x11];
                    found = 1;
                }
            }
        }
        if (!found) {
            values = &partner->equip[4];
            for (i = 0; i < 2; i++) {
                if (values[i] == 0x13C) {
                    stats->tripleHit = 1;
                } else if (values[i] == 0x13D) {
                    data = GET_ITEM[0](0x13D)->data;
                    stats->criticalBonus = data[6];
                } else if (values[i] == 0x13E) {
                    data = GET_ITEM[0](0x13E)->data;
                    stats->counter = data[6];
                }
            }
        }
        values = &partner->equip[4];
        for (i = 0; i < 2; i++) {
            if (values[i] >= 0x153 && values[i] <= 0x167) {
                data = GET_ITEM[0](values[i])->data;
                if (values[i] < 0x156) {
                    stats->element = 2;
                } else if (values[i] < 0x159) {
                    stats->element = 3;
                } else if (values[i] < 0x15C) {
                    stats->element = 4;
                } else if (values[i] < 0x15F) {
                    stats->element = 5;
                } else if (values[i] < 0x162) {
                    stats->element = 6;
                } else if (values[i] < 0x165) {
                    stats->element = 7;
                } else if (values[i] < 0x168) {
                    stats->element = 8;
                }
                stats->elementPower = data[6];
            } else if (values[i] >= 0x145 && values[i] <= 0x146) {
                data = GET_ITEM[0](values[i])->data;
                stats->damageCut = data[6];
            } else if (values[i] >= 0x14B && values[i] <= 0x14C) {
                data = GET_ITEM[0](values[i])->data;
                stats->accuracy += data[6];
            } else if (values[i] >= 0x14D && values[i] <= 0x14E) {
                data = GET_ITEM[0](values[i])->data;
                stats->evasion += data[6];
            } else if (values[i] >= 0x14F && values[i] <= 0x150) {
                data = GET_ITEM[0](values[i])->data;
                stats->runAwayBonus = data[6];
            } else if (values[i] == 0x13F) {
                data = GET_ITEM[0](values[i])->data;
                stats->runAwayGuard = 1;
            } else if (values[i] >= 0x147 && values[i] <= 0x148) {
                data = GET_ITEM[0](values[i])->data;
                stats->stealBonus = data[6];
            }
        }
    } else {
        fighter = &FIGHTSTG_battle.fighters[1][index];
        entry = FIGHTSTG_battleTableFunc(fighter->id);
        stats->level = BATTLE_SETUP.enemies[index].level;
        for (j = 0; j < 5; j++) {
            stats->stats[j] = entry->stats[j] * BATTLE_SETUP.enemies[index].unkA / 16;
        }
        for (j = 0; j < 12; j++) {
            stats->resist[j] = entry->resist[j];
        }
        stats->flags = fighter->flags;
        if (fighter->boosts[0] != 0) {
            stats->stats[BATTLE_STAT_ATTACK] += fighter->boosts[0];
        }
        if (fighter->boosts[1] != 0) {
            stats->stats[BATTLE_STAT_DEFENSE] += fighter->boosts[1];
        }
        if (fighter->boosts[2] != 0) {
            stats->stats[BATTLE_STAT_SPEED] += fighter->boosts[2];
        }
        if (fighter->boosts[3] != 0) {
            stats->stats[BATTLE_STAT_SPIRIT] += fighter->boosts[3];
        }
        stats->family = entry->unk30;
        stats->damageBonus = fighter->charge;
    }
    if (which) {
        return &FIGHTSTG_battleFuncs.stats[0];
    }
    return &FIGHTSTG_battleFuncs.stats[1];
}

/* the element whose boost (FIGHTSTG_getElementBoost) weakens each one */
s32 FIGHTSTG_opposedElements[] = {
    0, 0, 4, 2,
    5, 3, 7, 8,
    6,
};

/* What the battle's element boost adds to value for a technique of element
   arg1: its power in 128ths of value for that element, half as much taken
   off for the element that element weakens, nothing otherwise */
s32 FIGHTSTG_getElementBoost(s32 value, s32 arg1) {
    s16 *effect = &FIGHTSTG_battle.boostElement;

    if (effect[0] < ELEMENT_FIRST) {
        return 0;
    }
    if (arg1 == effect[0]) {
        return value * effect[1] / 128;
    }
    if (FIGHTSTG_opposedElements[arg1] == effect[0]) {
        return -(value * effect[1] / 256);
    }
    return 0;
}

/* A hit's damage from its base value: the element boost, half again against
   the target's family, the user's damage bonus, the element against the
   target's resistance, the triple hit's 0.4, a critical hit and the target's
   damage cut; at most 5 times value */
s32 FIGHTSTG_adjustDamage(u8 side, s32 id, s32 value) {
    TechData *tech = &TECHS[id - 1];
    BattleStats *user = &FIGHTSTG_battleFuncs.stats[0];
    BattleStats *target = &FIGHTSTG_battleFuncs.stats[1];
    s32 result = value;
    s32 i;

    result += FIGHTSTG_getElementBoost(result, tech->element);
    if (tech->family >= FAMILY_FIRST) {
        if (tech->family == target->family) {
            result += result / 2;
        }
    } else {
        for (i = 0; i < 3; i++) {
            if (user->weaponFamilies[i] >= FAMILY_FIRST && user->weaponFamilies[i] == target->family) {
                result += result / 2;
                break;
            }
        }
    }
    if (user->damageBonus != 0) {
        result += result * user->damageBonus / 64;
    }
    if (tech->element >= ELEMENT_FIRST) {
        result += result * tech->elementPower * 2 / target->resist[tech->element - ELEMENT_FIRST];
    } else if ((tech->unk10 < 11 || tech->unk10 > 12) && user->element != 0) {
        result += result * user->elementPower * 2 / target->resist[user->element - ELEMENT_FIRST];
    }
    if (tech->effect < TECH_EFFECT_FIRST && user->tripleHit != 0 && (tech->unk10 < 11 || tech->unk10 > 12)) {
        result = result * 4 / 10;
    }
    if (FIGHTSTG_rollCritical(side, id) != 0) {
        result += result * ((RANDOM.next() & 0x3F) + 0x20) / 64;
    }
    if (target->damageCut != 0) {
        result -= target->damageCut;
        if (result <= 0) {
            result = 0;
        }
    }
    if (result > value * 5) {
        result = value * 5;
    }
#if VERSION_EU
    if (result >= 10000) {
        result = 9999;
    }
#endif
    return result;
}

/* A technique's power from the user's attack against the target's defense
 * (an enemy's scaled by its unkA / 16), passed on to FIGHTSTG_adjustDamage. The match
 * depends on the division in each branch. */
s32 FIGHTSTG_computeDamage(u8 side, s32 id) {
    TechData *tech;
    BattleStats *user;
    BattleStats *target;
    s32 value;
    s32 enemy;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    user = &FIGHTSTG_battleFuncs.stats[0];
    tech = &TECHS[id - 1];
    target = &FIGHTSTG_battleFuncs.stats[1];
    if (side == 0) {
        value = tech->power * user->stats[BATTLE_STAT_ATTACK] / target->stats[BATTLE_STAT_DEFENSE];
    } else {
        enemy = FIGHTSTG_battle.active[1]; /* the match depends on reading it first */
        value = tech->power * BATTLE_SETUP.enemies[enemy].unkA / 16 * user->stats[BATTLE_STAT_ATTACK] /
                target->stats[BATTLE_STAT_DEFENSE];
    }
    return FIGHTSTG_adjustDamage(side, id, value);
}

/* A magic technique's damage: its power by the user's spirit against the
   target's (half to twice as much), the element boost and resistance, half
   again against the target's family, a critical hit and the target's damage
   cut; at most 5 times the power */
s32 FIGHTSTG_computeMagicDamage(u8 side, s32 id) {
    TechData *tech;
    BattleStats *user;
    BattleStats *target;
    s32 base;
    s32 enemy;
    s32 power;
    s32 result;
    s16 resist;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    user = &FIGHTSTG_battleFuncs.stats[0];
    tech = &TECHS[id - 1];
    target = &FIGHTSTG_battleFuncs.stats[1];
    if (side == 0) {
        base = tech->power;
    } else {
        enemy = FIGHTSTG_battle.active[1]; /* the match depends on reading it first */
        base = tech->power * BATTLE_SETUP.enemies[enemy].unkA / 16;
    }
    power = base * (user->stats[BATTLE_STAT_SPIRIT] * 50 / target->stats[BATTLE_STAT_SPIRIT] + 50) / 100;
    if (power > base * 2) {
        power = base * 2;
    }
    if (power < base / 2) {
        power = base / 2;
    }
    result = power;
    result += FIGHTSTG_getElementBoost(result, tech->element);
    if (tech->element >= ELEMENT_FIRST) {
        resist = target->resist[tech->element - ELEMENT_FIRST];
        if (resist < 100) {
            result = result * (400 - resist * 3) / 100;
        } else if (resist >= 300) {
            result = result * (65 - resist / 20) / 100;
        } else {
            result = result * (125 - resist / 4) / 100;
        }
    }
    if (tech->family >= FAMILY_FIRST && tech->family == target->family) {
        result += result / 2;
    }
    if (FIGHTSTG_rollMagicCritical(side, id) != 0) {
        result += result * (RANDOM.next() % 65 + 0x20) / 64;
    }
    if (target->damageCut != 0) {
        result -= target->damageCut;
        if (result <= 0) {
            result = 0;
        }
    }
    if (result > power * 5) {
        result = power * 5;
    }
#if VERSION_EU
    if (result >= 10000) {
        result = 9999;
    }
#endif
    return result;
}

/* getDamage: the damage of an event (args: the side, the fighter and the
 * base damage) to the fighter if it is its side's active one, less a tenth of
 * its resist[1] and resist[RESIST_POISON], as a part of its max HP: at least 1, at most
 * half the max HP. The match depends on the fighter pointer. */
s32 FIGHTSTG_getDamage(s32 *args) {
    u8 side;
    u8 team; /* the match depends on a u8 */
    s32 index;
    s32 damage;
    BattleStats *stats;
    s16 maxHp;
    BattleFighter *fighter;
    s32 result;

    side = args[0];
    index = args[1];
    damage = args[2];
    team = side != 0;
    if (index != FIGHTSTG_battle.active[team]) {
        return 0;
    }
    FIGHTSTG_computeStats(side, 0, index);
    stats = &FIGHTSTG_battleFuncs.stats[1];
    fighter = &FIGHTSTG_battle.fighters[team][index];
    maxHp = fighter->maxHp;
    result = (damage / 2 - (stats->resist[RESIST_POISON] + stats->resist[1]) / 10) * maxHp / 100;
    if (result <= 0) {
        result = 1;
    }
    if (result > maxHp / 2) {
        result = maxHp / 2;
    }
    return result;
}

/* The damage of a counterattack on value: the partner's first skill deals
   it as one hit (the triple hit set aside), another technique its power in
   64ths of value (32nds when the fighter is special) */
s32 FIGHTSTG_computeCounterDamage(u8 side, s32 id, s32 value) {
    BattleFighter *fighter;
    s32 own;
    u8 saved;
    s32 result;
    TechData *entry;

    if (side == 0) {
        fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
        own = id == GET_DIGIMON(fighter->id)->skills[0];
    } else {
        fighter = &FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]];
        FIGHTSTG_battleTableFunc(fighter->id);
        own = 0;
    }
    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    if (own == 1) {
        saved = FIGHTSTG_battleFuncs.stats[0].tripleHit;
        FIGHTSTG_battleFuncs.stats[0].tripleHit = 0;
        result = FIGHTSTG_adjustDamage(side, id, value);
        FIGHTSTG_battleFuncs.stats[0].tripleHit = saved;
        return result;
    }
    entry = &TECHS[id - 1];
    if (fighter->special) {
        result = value * entry->effectPower / 32;
    } else {
        result = value * entry->effectPower / 64;
    }
    return FIGHTSTG_adjustDamage(side, id, result);
}

/* The HP a healing technique restores: 64 times its power, and an eighth of
   it per point of the user's wisdom */
s32 FIGHTSTG_computeHeal(u8 side, s32 id) {
    BattleStats *stats;
    TechData *entry;
    u16 value;
    s32 flag;
    s32 fighter;
#if VERSION_EU
    s32 result;
#endif

    if (side == 0) {
        fighter = FIGHTSTG_battle.active[0];
        flag = 0;
    } else {
        flag = 0x10;
        fighter = FIGHTSTG_battle.active[1];
    }
    FIGHTSTG_computeStats(flag, 1, fighter);
    stats = &FIGHTSTG_battleFuncs.stats[0];
    entry = &TECHS[id - 1];
    value = entry->power;
#if VERSION_US
    return (value << 6) + stats->stats[BATTLE_STAT_WISDOM] * value / 8;
#elif VERSION_EU
    result = (value << 6) + stats->stats[BATTLE_STAT_WISDOM] * value / 8;
    if (result > 9999) {
        result = 9999;
    }
    return result;
#endif
}

/* The HP a fighter regains: 8 to 16 128ths of its max HP when big, 4 to 8
   otherwise */
s32 FIGHTSTG_getHeal(u8 side, s32 index, s32 big) {
    BattleFighter *fighter;
    s32 value;

    if (side == 0) {
        fighter = &FIGHTSTG_battle.fighters[0][index];
    } else {
        fighter = &FIGHTSTG_battle.fighters[1][index];
    }
    if (big) {
        value = fighter->maxHp * (RANDOM.next() % 9 + 8) / 128;
    } else {
        value = fighter->maxHp * (RANDOM.next() % 5 + 4) / 128;
    }
#if VERSION_EU
    if (value > 9999) {
        value = 9999;
    }
#endif
    return value;
}

/* Whether a physical hit is critical: a chance of 4 in 128 with the
   technique's critical boost or the accessory's, more against the target's
   family and while the target is paralyzed, asleep or confused */
s32 FIGHTSTG_rollCritical(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    BattleFighter *fighter;
    s32 chance;
    s32 i;
    s32 j;
    s32 k;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    chance = 4;
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (entry->effect >= TECH_EFFECT_FIRST) {
        if (entry->effect == TECH_EFFECT_CRITICAL) {
            chance += entry->effectPower;
        }
    } else if (atk->criticalBonus != 0) {
        k = side != 0;
        fighter = &FIGHTSTG_battle.fighters[k][FIGHTSTG_battle.active[k]];
        if (fighter->special) {
            chance = atk->criticalBonus * 2 + 4;
        } else {
            chance = atk->criticalBonus + 4;
        }
    }
    if (entry->family >= FAMILY_FIRST) {
        if (entry->family == def->family) {
            chance += 0x3C;
        }
    } else {
        for (i = 0; i < 3; i++) {
            if (atk->weaponFamilies[i] >= FAMILY_FIRST && atk->weaponFamilies[i] == def->family) {
                chance += 0x10;
                break;
            }
        }
    }
    j = side == 0;
    fighter = &FIGHTSTG_battle.fighters[j][FIGHTSTG_battle.active[j]];
    if (fighter->flags & FIGHTER_PARALYZED) {
        chance += fighter->paralysis >> 3;
    }
    if (fighter->flags & FIGHTER_ASLEEP) {
        chance += fighter->sleep >> 3;
    }
    if (fighter->flags & FIGHTER_CONFUSED) {
        chance += fighter->confusion >> 1;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a magic hit is critical: a chance from the technique's element
   power against the target's resistance, more against the target's family
   and while the target is paralyzed, asleep or confused */
s32 FIGHTSTG_rollMagicCritical(u8 side, s32 id) {
    BattleStats *def;
    TechData *entry;
    BattleFighter *fighter;
    s32 value;
    s32 chance;
    s32 j;

#if VERSION_US
    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
#elif VERSION_EU
    if (side == 0) {
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
    }
#endif
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    value = entry->elementPower * 100 / def->resist[entry->element - ELEMENT_FIRST];
    if (value > 0x40) {
        value = 0x40;
    }
    chance = value + 4;
    if (entry->family >= FAMILY_FIRST && entry->family == def->family) {
        chance = value + 0x40;
    }
    j = side == 0;
    fighter = &FIGHTSTG_battle.fighters[j][FIGHTSTG_battle.active[j]];
    if (fighter->flags & FIGHTER_PARALYZED) {
        chance += fighter->paralysis >> 3;
    }
    if (fighter->flags & FIGHTER_ASLEEP) {
        chance += fighter->sleep >> 3;
    }
    if (fighter->flags & FIGHTER_CONFUSED) {
        chance += fighter->confusion >> 1;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a physical hit lands: the technique's accuracy with the speed and
   level differences and the accuracy and evasion accessories (the critical
   accessory costs the player some); the enemy hits at least 1 in 4, the
   player in BATTLE_KIND_FINAL_LAST 2 in 3 */
s32 FIGHTSTG_rollHit(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 level;
    s32 diff;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (side == 0) {
        if (FIGHTSTG_battle.kind == BATTLE_KIND_FINAL_LAST) {
            return (RANDOM.next() & 0x7F) >= 0x2B;
        }
        diff = atk->stats[BATTLE_STAT_SPEED] + atk->accuracy - def->stats[BATTLE_STAT_SPEED];
        level = atk->level - def->level;
        if (entry->effect < TECH_EFFECT_FIRST) {
            chance = entry->accuracy + entry->accuracy * (diff / 8 + (level - atk->criticalBonus)) / 128;
        } else {
            chance = entry->accuracy + entry->accuracy * (diff / 8 + level) / 128;
        }
    } else {
        level = atk->level - def->level;
        diff = atk->stats[BATTLE_STAT_SPEED] - def->stats[BATTLE_STAT_SPEED] - def->evasion;
        chance = entry->accuracy + entry->accuracy * (diff / 8 + level) / 128;
        if (chance < 0x20) {
            chance = 0x20;
        }
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a magic hit lands: the technique's accuracy with the wisdom and
   level differences; the player in BATTLE_KIND_FINAL_LAST hits 2 in 3 */
s32 FIGHTSTG_rollMagicHit(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 level;
    s32 diff;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (side == 0 && FIGHTSTG_battle.kind == BATTLE_KIND_FINAL_LAST) {
        return (RANDOM.next() & 0x7F) >= 0x2B;
    }
    diff = atk->stats[BATTLE_STAT_WISDOM] - def->stats[BATTLE_STAT_WISDOM];
    level = atk->level - def->level;
    chance = entry->accuracy + entry->accuracy * (diff / 8 + level) / 128;
    return (RANDOM.next() & 0x7F) < chance;
}

/* The poison a hit inflicts, or 0: the technique's or the accessory's chance
   and an eighth of the user's wisdom, less the target's resistances and
   wisdom (BATTLE_SETUP.unk3E[0] keeps the player from it) */
s32 FIGHTSTG_rollPoison(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 result;
    s32 base;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[0]) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (entry->effect < TECH_EFFECT_FIRST) {
        result = atk->poisonPower;
        base = atk->poisonChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    } else {
        result = entry->effectPower;
        base = entry->effectChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    }
    chance = base - (def->resist[RESIST_POISON] + def->resist[1] + def->stats[BATTLE_STAT_WISDOM] / 2) / 8;
    if (chance <= 0) {
        chance = 1;
    }
    if (chance >= 0x80) {
        chance = 0x7F;
    }
    if ((RANDOM.next() & 0x7F) < chance) {
        return result;
    }
    return 0;
}

/* Whether a hit paralyzes, like rollPoison (BATTLE_SETUP.unk3E[1] keeps the
   player from it) */
s32 FIGHTSTG_rollParalysis(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 base;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[1]) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (entry->effect < TECH_EFFECT_FIRST) {
        base = atk->paralysisChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    } else {
        base = entry->effectChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    }
    chance = base - (def->resist[RESIST_PARALYSIS] + def->resist[4] + def->stats[BATTLE_STAT_WISDOM] / 2) / 8;
    if (chance <= 0) {
        chance = 1;
    }
    if (chance >= 0x80) {
        chance = 0x7F;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a hit confuses, like rollPoison (BATTLE_SETUP.unk3E[2] keeps the
   player from it) */
s32 FIGHTSTG_rollConfusion(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 base;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[2]) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (entry->effect < TECH_EFFECT_FIRST) {
        base = atk->confusionChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    } else {
        base = entry->effectChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    }
    chance = base - (def->resist[RESIST_CONFUSION] + def->resist[3] + def->stats[BATTLE_STAT_WISDOM] / 2) / 8;
    if (chance <= 0) {
        chance = 1;
    }
    if (chance >= 0x80) {
        chance = 0x7F;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a hit puts the target to sleep, like rollPoison with the
   technique's chance (BATTLE_SETUP.unk3E[3] keeps the player from it) */
s32 FIGHTSTG_rollSleep(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[3]) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    chance = entry->effectChance + atk->stats[BATTLE_STAT_WISDOM] / 8 - (def->resist[RESIST_SLEEP] + def->resist[2] + def->stats[BATTLE_STAT_WISDOM] / 2) / 8;
    if (chance <= 0) {
        chance = 1;
    }
    if (chance >= 0x80) {
        chance = 0x7F;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a hit knocks the target out, like rollPoison
   (BATTLE_SETUP.unk3E[4] keeps the player from it) */
s32 FIGHTSTG_rollKnockOut(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 chance;
    s32 base;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[4]) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    entry = &TECHS[id - 1];
    if (entry->effect < TECH_EFFECT_FIRST) {
        base = atk->knockOutChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    } else {
        base = entry->effectChance + atk->stats[BATTLE_STAT_WISDOM] / 8;
    }
    chance = base - (def->resist[RESIST_KNOCK_OUT] + def->resist[6] + def->stats[BATTLE_STAT_WISDOM] / 2) / 8;
    if (chance <= 0) {
        chance = 1;
    }
    if (chance >= 0x80) {
        chance = 0x7F;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether the player steals the enemy's item: its itemChance in 1024 by the
   speed ratio (at most twice) and the technique's and the accessory's chance */
s32 FIGHTSTG_rollSteal(u8 side, s32 id) {
    BattleStats *atk;
    BattleStats *def;
    TechData *entry;
    s32 ratio;
    s32 chance;
    s32 power;
    s32 roll;

    if (side == 0) {
        if (BATTLE_SETUP.unk3E[7]) {
            return 0;
        }
        if (FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]].item <= 0) {
            return 0;
        }
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    if (side == 0) {
        atk = &FIGHTSTG_battleFuncs.stats[0];
        def = &FIGHTSTG_battleFuncs.stats[1];
        ratio = atk->stats[BATTLE_STAT_SPEED] * 100 / def->stats[BATTLE_STAT_SPEED];
        entry = &TECHS[id - 1];
        if (ratio > 200) {
            ratio = 200;
        }
        power = (entry->effectChance + atk->stealBonus) * 100 / 64;
        chance = FIGHTSTG_battleTableFunc(FIGHTSTG_battle.fighters[1][FIGHTSTG_battle.active[1]].id)->itemChance * ratio * power / 10000;
        roll = RANDOM.next() % 1024;
        if (roll < chance) {
            return 1;
        }
    }
    return 0;
}

/* Whether a hit drains HP: the technique's chance, or the accessory's for a
   technique without an effect */
s32 FIGHTSTG_rollDrain(u8 side, s32 id) {
    BattleStats *stats;
    TechData *entry;
    s32 chance;

    if (side == 0 && BATTLE_SETUP.unk3E[5] != 0) {
        return 0;
    }
#if VERSION_US
    stats = &FIGHTSTG_battleFuncs.stats[0];
#elif VERSION_EU
    stats = FIGHTSTG_computeStats(side, 1, FIGHTSTG_battle.active[side >> 4]);
#endif
    entry = &TECHS[id - 1];
    if (entry->effect < TECH_EFFECT_FIRST) {
        chance = stats->drainChance;
    } else {
        chance = entry->effectChance;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a technique turns the player's fighter back: never when it is one
   of the first 8 Digimon, otherwise the technique's chance */
s32 FIGHTSTG_rollDedigivolve(s32 actor, s32 id) {
    s32 i;
    TechData *entry;
    s32 chance;

    for (i = 0; i < 8; i++) {
        if (DIGIMON_DATA[i].id == FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]].id) {
            return 0;
        }
    }
    entry = &TECHS[id - 1];
    chance = entry->effectChance;
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether a status raise works: the technique's chance and an eighth of
   what the enemy's wisdom has over the partner's */
s32 FIGHTSTG_rollStatusRaise(s32 actor, s32 id) {
    TechData *entry;
    s32 chance;

    FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
    FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    entry = &TECHS[id - 1];
    chance = entry->effectChance + (FIGHTSTG_battleFuncs.stats[0].stats[BATTLE_STAT_WISDOM] - FIGHTSTG_battleFuncs.stats[1].stats[BATTLE_STAT_WISDOM]) / 8;
    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether TECH_EFFECT_NO_SWITCH works: the technique's chance */
s32 FIGHTSTG_rollNoSwitch(s32 actor, s32 id) {
    TechData *entry = &TECHS[id - 1];
    s32 chance = entry->effectChance;

    return (RANDOM.next() & 0x7F) < chance;
}

/* Whether TECH_EFFECT_NO_DIGIVOLVE works: the technique's chance */
s32 FIGHTSTG_rollNoDigivolve(s32 actor, s32 id) {
    TechData *entry = &TECHS[id - 1];
    s32 chance = entry->effectChance;

    return (RANDOM.next() & 0x7F) < chance;
}

#if VERSION_EU
/* FIGHTSTG_battleFuncs.rollCounter: a random test, likelier the bigger arg1 is next
   to the player's fighter's max HP */
s32 FIGHTSTG_rollCounter(s32 arg0, s32 arg1) {
    BattleFighter *fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    s32 chance = (arg1 << 6) / fighter->maxHp + 32;

    return (RANDOM.next() & 0x7F) < chance;
}
#endif

/* FIGHTSTG_battleFuncs.testRunAway: a random test for side running away, from
   both sides' stats; the player can't while BATTLE_SETUP.unk3E[11] is set, and
   in the European version neither can the enemy while its fighter is asleep. The match depends on the battle's unkD4 being read through a pointer to
   its active array, taken before side is tested again, and on the flags being
   tested with family as a halfword. */
s32 FIGHTSTG_testRunAway(u8 side) {
    BattleStats *atk;
    BattleStats *def;
    s32 chance;
    s32 *active;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 1, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    } else {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
        FIGHTSTG_computeStats(0x10, 1, FIGHTSTG_battle.active[1]);
    }
    active = FIGHTSTG_battle.active;
    atk = &FIGHTSTG_battleFuncs.stats[0];
    def = &FIGHTSTG_battleFuncs.stats[1];
    if (side == 0) {
        if (BATTLE_SETUP.unk3E[11]) {
            return 0;
        }
        if (*(u16 *)&atk->flags & 0x18) {
            return 0;
        }
        chance = (((Battle *)(active - 2))->unkD4 + 1) * 8;
        if (atk->flags & FIGHTER_PARALYZED) {
            chance >>= 1;
        }
        if (atk->level > def->level) {
            chance += atk->level - def->level;
        }
        if (atk->stats[BATTLE_STAT_SPEED] > def->stats[BATTLE_STAT_SPEED]) {
            chance += (atk->stats[BATTLE_STAT_SPEED] - def->stats[BATTLE_STAT_SPEED]) / 10;
        }
        chance += atk->runAwayBonus;
    } else {
#if VERSION_EU
        if (atk->flags & FIGHTER_ASLEEP) {
            return 0;
        }
#endif
        if (def->runAwayGuard) {
            chance = 0x20;
        } else {
            chance = 0x40;
        }
        if (atk->flags & FIGHTER_PARALYZED) {
            chance >>= 1;
        }
        chance += (atk->stats[BATTLE_STAT_SPEED] - def->stats[BATTLE_STAT_SPEED]) / 10;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* FIGHTSTG_battleFuncs.testWakeUp: whether a hit of value wakes side's
   fighter up, likelier the bigger value is next to the fighter's defense,
   less likely the stronger its sleep and the later its end (EVENT_STATUS_END
   + 2) is due. The match depends on the 64 being set apart from sleep's half and on the sum being
   written in one statement. */
s32 FIGHTSTG_testWakeUp(u8 side, s32 value) {
    s32 team;
    s32 index;
    s32 chance;
    s16 delay;
    s32 luck;
    BattleStats *def;

    if (side == 0) {
        FIGHTSTG_computeStats(0, 0, FIGHTSTG_battle.active[0]);
    } else {
        FIGHTSTG_computeStats(0x10, 0, FIGHTSTG_battle.active[1]);
    }
    team = side != 0;
    def = &FIGHTSTG_battleFuncs.stats[1];
    index = FIGHTSTG_events.funcs.find(EVENT_STATUS_END + 2, side, FIGHTSTG_battle.active[team]);
    chance = (value << 7) / def->stats[BATTLE_STAT_DEFENSE];
    delay = FIGHTSTG_events.events[index].time / 100;
    luck = 64;
    luck -= FIGHTSTG_battle.fighters[team][FIGHTSTG_battle.active[team]].sleep >> 1;
    chance = chance + luck - delay;
    return (RANDOM.next() & 0x7F) < chance;
}

/* FIGHTSTG_battleFuncs.testConfusion: a random test of side's confusion
   against its resists 9 and 3 */
s32 FIGHTSTG_testConfusion(u8 side) {
    BattleStats *stats;
    s32 other;
    BattleFighter *entry;
    s32 flag;
    s32 fighter;
    s32 chance;

    if (side == 0) {
        fighter = FIGHTSTG_battle.active[0];
        flag = 0;
    } else {
        flag = 0x10;
        fighter = FIGHTSTG_battle.active[1];
    }
    FIGHTSTG_computeStats(flag, 0, fighter);
    stats = &FIGHTSTG_battleFuncs.stats[1];
    other = side != 0;
    chance = FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]].confusion - (stats->resist[RESIST_CONFUSION] + stats->resist[3]) / 8;
    return (RANDOM.next() & 0x7F) < chance;
}

/* FIGHTSTG_battleFuncs.testParalysis: whether side's paralysis costs it the
   turn, a random test of its strength against resists 8 and 4 (at least a
   chance of 32 in 128) */
s32 FIGHTSTG_testParalysis(u8 side) {
    BattleStats *stats;
    s32 other;
    s32 flag;
    s32 fighter;
    s32 chance;

    if (side == 0) {
        fighter = FIGHTSTG_battle.active[0];
        flag = 0;
    } else {
        flag = 0x10;
        fighter = FIGHTSTG_battle.active[1];
    }
    FIGHTSTG_computeStats(flag, 0, fighter);
    stats = &FIGHTSTG_battleFuncs.stats[1];
    other = side != 0;
    chance = FIGHTSTG_battle.fighters[other][FIGHTSTG_battle.active[other]].paralysis - (stats->resist[RESIST_PARALYSIS] + stats->resist[4]) / 8;
    if (chance < 0x20) {
        chance = 0x20;
    }
    return (RANDOM.next() & 0x7F) < chance;
}

/* the stat of BattleStats.stats that each of BattleFighter.boosts adds to */
s16 FIGHTSTG_boostStats[] = {
    0x0000, 0x0001, 0x0004, 0x0000,
};

/* Changes a fighter's stat boost by percent 128ths of the stat without it,
   between minus half the stat and the stat; nothing for an empty or
   knocked-out fighter */
void FIGHTSTG_changeBoost(u8 side, s32 index, s32 stat, s32 percent) {
    BattleStats *stats;
    BattleFighter *fighter;
    s32 value;
    s32 min;

    if (side == 0) {
        stats = FIGHTSTG_computeStats(0, 0, index);
        fighter = &FIGHTSTG_battle.fighters[0][index];
    } else {
        stats = FIGHTSTG_computeStats(0x10, 0, index);
        fighter = &FIGHTSTG_battle.fighters[1][index];
    }
    if (fighter->id == 0 || fighter->hp == 0) {
        return;
    }
    if (fighter->boosts[stat] != 0) {
        stats->stats[FIGHTSTG_boostStats[stat]] -= fighter->boosts[stat];
    }
    value = stats->stats[FIGHTSTG_boostStats[stat]];
    min = -(value / 2);
    fighter->boosts[stat] += value * percent / 128;
    if (fighter->boosts[stat] < min) {
        fighter->boosts[stat] = min;
    }
    if (fighter->boosts[stat] > value) {
        fighter->boosts[stat] = value;
    }
}

/* What the partner's damage adds to the gauge: the square of its percent of
   the max HP over 20, more with accessories 0x149 and 0x14A, at most 1000 */
s32 FIGHTSTG_getGaugeGain(s32 damage) {
    PartnerStats *partner;
    s32 ratio;
    BattleFighter *fighter;
    s32 value;
    s32 i;
    s16 *acc;

    fighter = &FIGHTSTG_battle.fighters[0][FIGHTSTG_battle.active[0]];
    ratio = damage * 100 / fighter->maxHp;
    value = ratio * ratio / 20;
    partner = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]));
    acc = &partner->equip[4];
    for (i = 0; i < 2; i++) {
        if (acc[i] == 0x149) {
            value += value / 5;
        } else if (acc[i] == 0x14A) {
            value += value * 4 / 10;
        }
    }
    if (value > 1000) {
        value = 1000;
    }
    return value;
}

/* A technique's MP cost; accessories 0x143 and 0x144 cut the player's, to no
   less than 1 */
s32 FIGHTSTG_getTechCost(u8 side, s32 id) {
    PartnerStats *partner;
    s32 cost;
    s32 extra;
    s16 item;

    cost = TECHS[(id & 0x1FFF) - 1].mp;
    if (side != 0) {
        return cost;
    }
    partner = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(FIGHTSTG_battle.active[0]));
    item = 0;
    if (partner->equip[4] == 0x143 || partner->equip[4] == 0x144) {
        item = partner->equip[4];
    }
    if (partner->equip[5] == 0x143 || partner->equip[5] == 0x144) {
        item = partner->equip[5];
    }
    if (item != 0) {
        cost -= *(s16 *)&GET_ITEM[0](item)->data[6];
        if (cost <= 0) {
            cost = 1;
        }
    }
    if (id & 0x4000) {
        extra = cost / 5;
        if (extra != 0) {
            cost += extra;
        } else {
            cost++;
        }
    }
    return cost;
}

void func_800A0EEC(void) {
}

void FIGHTSTG_lerpVector(SVECTOR *from, SVECTOR *to, s32 t, SVECTOR *out) {
    SVECTOR diff;
    SVECTOR step;

    gte_lddp(t);
    diff.vx = to->vx - from->vx;
    diff.vy = to->vy - from->vy;
    diff.vz = to->vz - from->vz;
    gte_ldsv(&diff);
    gte_gpf12();
    *out = *from;
    gte_stsv(&step);
    out->vx += step.vx;
    out->vy += step.vy;
    out->vz += step.vz;
}

/* Returns value scaled by the sine of t (4096 is 1.0) on the given curve: 0 a
 * quarter of t, 1 the same as a cosine, 2 half of t. The match depends on a
 * return in each case; one shared return after the switch schedules the
 * epilogue differently. */
s32 FIGHTSTG_ease(s32 curve, s32 t, s32 value) {
    switch (curve) {
    case 0:
    default:
        return rsin(t >> 2) * value / 4096;
    case 1:
        return rsin((t >> 2) + 0x400) * value / 4096;
    case 2:
        return rsin(t >> 1) * value / 4096;
    }
}

/* the functions that go between values */
InterpFuncs FIGHTSTG_interp = { func_800A0EEC, FIGHTSTG_lerpVector, FIGHTSTG_ease };
