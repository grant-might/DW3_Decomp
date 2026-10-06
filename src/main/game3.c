#include "game.h"
#include "field_map.h"

s32 testBit(u8 *bits, s32 index, s32 set) {
    s32 byte = index >> 3;
    s32 mask = 1 << (index & 7);

    if (set != 0) {
        return (bits[byte] & mask) != 0;
    }
    return (bits[byte] & mask) == 0;
}

void setBit(u8 *bits, s32 index, s32 set) {
    s32 byte = index >> 3;
    s32 mask = 1 << (index & 7);

    if (set) {
        bits[byte] |= mask;
    } else {
        bits[byte] &= ~mask;
    }
}

/* Special condition 0x00: the player has every item of a set (the European
   version has a second set) */
s32 checkItemSet(s32 op, s32 arg) {
    s32 ret = 0;

#if VERSION_US
    if ((GAME.items[7] != 0 || GAME.equippedItems[7] != 0) &&
        (GAME.items[0x59] != 0 || GAME.equippedItems[0x59] != 0) &&
        (GAME.items[0xA7] != 0 || GAME.equippedItems[0xA7] != 0)) {
        ret = 1;
    }
#elif VERSION_EU
    switch (op) {
    case 0:
        if ((GAME.items[7] != 0 || GAME.equippedItems[7] != 0) &&
            (GAME.items[0x59] != 0 || GAME.equippedItems[0x59] != 0) &&
            (GAME.items[0xA7] != 0 || GAME.equippedItems[0xA7] != 0)) {
            ret = 1;
        }
        break;
    case 1:
        if ((GAME.items[0x69] != 0 || GAME.equippedItems[0x69] != 0) &&
            (GAME.items[0x77] != 0 || GAME.equippedItems[0x77] != 0) &&
            (GAME.items[0x83] != 0 || GAME.equippedItems[0x83] != 0) &&
            (GAME.items[0x90] != 0 || GAME.equippedItems[0x90] != 0) &&
            (GAME.items[0x9C] != 0 || GAME.equippedItems[0x9C] != 0)) {
            ret = 1;
        }
        break;
    }
#endif
    return ret;
}

s32 checkPartner(u32 op, s32 arg) {
    s32 result = 0;
    s32 i;
    s32 total;
    s32 id;
#if VERSION_EU
    s32 partner;
#endif

    switch (op) {
    case 0:
        if (GAME.partySet == arg) {
            result = 1;
        }
        break;
    case 1:
        if (GAME.partners[arg].unlocked != 0) {
            result = 1;
        }
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            if (GAME.funcs.getPartyMember(i) == arg) {
                result = 1;
                break;
            }
        }
        break;
    case 3:
        GAME.partners[arg].unlocked = arg + 3;
        result = 1;
        break;
    case 4:
        if (GAME.partners[arg].unlocked != 0 && GAME.partners[arg].info.stats[STAT_LEVEL] >= 0x2D) {
            result = 1;
        }
        break;
    case 5:
        total = 0;
        for (i = 0; i < 3; i++) {
            id = GAME.funcs.getPartyMember(i);
            if (id >= 0) {
                total += GAME.funcs.getPartnerStats(id)->stats[STAT_LEVEL];
            }
        }
        if (total >= arg * 15 + 30) {
            result = 1;
        }
        break;
    case 6:
        if (GAME.partners[arg].unlocked == 0) {
            result = 1;
        }
        break;
#if VERSION_EU
    case 7:
        result = 1;
        for (id = 0; id < 8; id++) {
            if (GAME.partners[id].unlocked != 0 && GAME.partners[id].info.stats[STAT_LEVEL] < 0x2D) {
                result = 0;
                break;
            }
        }
        break;
    case 8:
        for (i = 0; i < 3; i++) {
            partner = GAME.funcs.getPartyMember(i);
            if (partner >= 0) {
                GAME.partners[partner].info.stats[STAT_HP] = GAME.partners[partner].info.stats[STAT_MAX_HP];
                GAME.partners[partner].info.stats[STAT_MP] = GAME.partners[partner].info.stats[STAT_MAX_MP];
            }
        }
        result = 1;
        break;
    case 9:
        if (GAME.partners[0].unlocked != 0 && GAME.partners[1].unlocked != 0 && GAME.partners[2].unlocked != 0 &&
            GAME.partners[3].unlocked != 0 && GAME.partners[4].unlocked != 0 && GAME.partners[5].unlocked != 0 &&
            GAME.partners[6].unlocked != 0 && GAME.partners[7].unlocked != 0) {
            result = 1;
        }
        break;
#endif
    }
    return result;
}

s32 checkMoney(s32 op, s32 item) {
    s32 ret = 0;

    switch (op) {
    case 0:
        if (MONEY_REQUIRED[item] <= GAME.money) {
            ret = 1;
        }
        break;
    case 1:
        GAME.money += MONEY_GAINS[item];
        if (GAME.money > 9999999) {
            GAME.money = 9999999;
        }
        break;
    case 2:
        GAME.money -= MONEY_LOSSES[item];
        if (GAME.money < 0) {
            GAME.money = 0;
        }
        break;
    }
    return ret;
}

s32 checkProgressRange(s32 unused, s32 index) {
    s32 value = GAME.progress;
    s32 min = PROGRESS_RANGES[index][0];
    s32 max = PROGRESS_RANGES[index][1];
    s32 ret = 0;

    if (value >= min) {
        ret = max >= value;
    }
    return ret;
}

#if VERSION_US
s32 checkFlagCount(s32 unused, s32 mode) {
    s32 ret = 0;
    s32 on = 0;
    s32 off = 0;
    s32 i;

    for (i = 0x27; i < 0x2E; i++) {
        if (testBit(GAME.flags1C, i, 1) != 0) {
            on++;
        } else {
            off++;
        }
    }
    switch (mode) {
    case 0:
        if (on != 0) {
            ret = 1;
        }
        break;
    case 1:
        if (off >= 2) {
            ret = 1;
        }
        break;
    case 2:
        if (off == 1) {
            ret = 1;
        }
        break;
    }
    return ret;
}
#elif VERSION_EU
s32 checkFlagCount(s32 group, s32 mode) {
    s32 ret = 0;
    s32 on = 0;
    s32 off = 0;
    s32 i;

    switch (group) {
    case 0:
        for (i = 0x27; i < 0x2E; i++) {
            if (testBit(GAME.flags1C, i, 1) != 0) {
                on++;
            } else {
                off++;
            }
        }
        switch (mode) {
        case 0:
            if (on != 0) {
                ret = 1;
            }
            break;
        case 1:
            if (off >= 2) {
                ret = 1;
            }
            break;
        case 2:
            if (off == 1) {
                ret = 1;
            }
            break;
        }
        break;
    case 1:
        if (testBit(GAME.flags10, 0xD, 1) && testBit(GAME.flags10, 0xE, 1) && testBit(GAME.flags10, 0xF, 1) &&
            testBit(GAME.flags10, 0x10, 1)) {
            ret = 1;
        }
        break;
    }
    return ret;
}
#endif

/* Special condition 0x50: the field actor's icon (FIELDSTG's task 0x16)
   plays its animation 3, as event command 0x34A does */
s32 showActorIcon(s32 op, s32 arg) {
    Task *obj = TASK_REGISTRY.funcs.find(0x16, -1, -1);

    obj->setSubstate(obj, 3);
    return 1;
}

s32 checkSpecialCondition(s32 id, s32 expected) {
    u8 *p;
    s32 result = 0;
    s32 op;
    s32 arg;

    for (p = SPECIAL_CONDITIONS; *p != 0xFF; p += 3) {
        if (*p == id) {
            op = p[1] & 0xF;
            arg = p[2];
            switch (p[1] & 0xF0) {
            case 0x00:
                result = checkItemSet(op, arg);
                break;
            case 0x10:
                result = checkPartner(op, arg);
                break;
            case 0x20:
                result = checkMoney(op, arg);
                break;
            case 0x30:
                result = checkProgressRange(op, arg);
                break;
            case 0x40:
                result = checkFlagCount(op, arg);
                break;
            case 0x50:
                result = showActorIcon(op, arg);
                break;
            }
            break;
        }
    }
    return expected == result;
}

s32 checkProgress(s32 value, s32 mode) {
    if (mode != 0) {
        if (GAME.progress == value) {
            return 1;
        }
    } else {
        if (GAME.progress != value) {
            return 1;
        }
    }
    return 0;
}

s32 checkItem(s32 index, s32 mode) {
    if (mode != 0) {
        if (GAME.items[index] != 0 || GAME.equippedItems[index] != 0) {
            return 1;
        }
    } else {
        if (GAME.items[index] == 0 && GAME.equippedItems[index] == 0) {
            return 1;
        }
    }
    return 0;
}

s32 checkCard(s32 item, s32 have) {
    if (have != 0) {
        if (GAME.cards[item] != 0) {
            return 1;
        }
    } else {
        if (GAME.cards[item] == 0) {
            return 1;
        }
    }
    return 0;
}

extern s32 PARTY_STAT_THRESHOLDS[];

s32 checkPartyStat(s32 index, s32 mode) {
    PartnerTotals buf;
    s32 total = 0;
    s32 i;
    s32 id;

    for (i = 0; i < 3; i++) {
        id = GAME.funcs.getPartyMember(i);
        if (id >= 0) {
            GAME.funcs.computeStats(id, &buf);
            total += buf.fields.battle[5];
        }
    }
    if (mode != 0) {
        if (total >= PARTY_STAT_THRESHOLDS[index]) {
            return 1;
        }
    } else {
        if (total < PARTY_STAT_THRESHOLDS[index]) {
            return 1;
        }
    }
    return 0;
}

/* Conditions 0x7E: the values a warp leaves for its stage (GAME.unk44 for
   ids under 30, GAME.unk46 above) */
s32 checkWarpArg(s32 id, s32 arg1) {
#if VERSION_US
    if (id < 30) {
        if (GAME.unk44 == id + 1) {
            return 1;
        }
    } else {
        if (GAME.unk46 == id - 29) {
            return 1;
        }
    }
#elif VERSION_EU
    /* arg1 zero: the opposite test */
    if (id < 30) {
        if (arg1 != 0) {
            if (GAME.unk44 == id + 1) {
                return 1;
            }
        } else {
            if (GAME.unk44 != id + 1) {
                return 1;
            }
        }
    } else {
        if (arg1 != 0) {
            if (GAME.unk46 == id - 29) {
                return 1;
            }
        } else {
            if (GAME.unk46 != id - 29) {
                return 1;
            }
        }
    }
#endif
    return 0;
}

s32 unequipItem(s32 partner, s32 item) {
    PartnerStats *d = &GAME.partners[partner].info;
    u8 *info = GET_ITEM[0](item)->data;
    s16 *equip = d->equip;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (equip[i] == item) {
            if (info[2] == 7) {
                d->equip[2] = 0;
                d->equip[3] = 0;
            } else {
                equip[i] = 0;
            }
            return 1;
        }
    }
    return 0;
}

void changeItem(s32 item, s32 add) {
    s32 i;

    if (add != 0) {
        if (++GAME.items[item] >= 100) {
            GAME.items[item] = 99;
        }
    } else if (GAME.items[item] != 0) {
        if (--GAME.items[item] < 0) {
            GAME.items[item] = 0;
        }
    } else if (GAME.equippedItems[item] != 0) {
        for (i = 0; i < 3; i++) {
            if (unequipItem(GAME.funcs.getPartyMember(i), item) != 0) {
                goto found;
            }
        }
        for (i = 0; i < 8; i++) {
            if (GAME.partners[i].unlocked >= 3 && unequipItem(i, item) != 0) {
                break;
            }
        }
    found:
        GAME.equippedItems[item]--;
    }
}

void changeCard(s32 card, s32 add) {
    if (add != 0) {
        GAME.funcs.addCards(card, 1);
        return;
    }
    GAME.cards[card]--;
    if (GAME.cards[card] < 0) {
        GAME.cards[card] = 0;
    }
}

/* Actions 0x76 and 0x78: a card battle (mode 0x700) against an opponent */
void startCardBattle(s32 opponent, s32 kind) {
    func_8008AEB4(0x700, opponent * 2 + kind + 1, 0, 0, 0);
}

/*
 * Event scripts test conditions and run actions given as (code, value)
 * pairs. code >> 9 picks the kind, code & 0x1FF the flag or item:
 *   groups 0x00-0x40 (code >> 8 & ~1): the flag bitsets FLAGS_00 and
 *   GAME.flags02-flags40
 *   0x60 GAME.progress, 0x70 SPECIAL_CONDITIONS, 0x72 party stat totals,
 *   0x80-0x8E items, 0x92 cards. A condition holds when it equals value.
 */
s32 checkCondition(u16 code, u16 value) {
    u16 group = (code >> 8) & 0xFE;
    s32 id = code & 0x1FF;
    u16 arg = value;

    if (group == 0x00) {
        return testBit(FLAGS_00.bits, id, arg);
    } else if (group == 0x02) {
        return testBit(GAME.flags02, id, arg);
    } else if (group == 0x04) {
        return testBit(GAME.flags04, id, arg);
    } else if (group == 0x06) {
        return testBit(GAME.flags06, id, arg);
    } else if (group == 0x08) {
        return testBit(GAME.flags08, id, arg);
    } else if (group == 0x0A) {
        return testBit(GAME.flags0A, id, arg);
    } else if (group == 0x0C) {
        return testBit(GAME.flags0C, id, arg);
    } else if (group == 0x0E) {
        return testBit(GAME.flags0E, id, arg);
    } else if (group == 0x10) {
        return testBit(GAME.flags10, id, arg);
    } else if (group == 0x18) {
        return testBit(GAME.flags18, id, arg);
    } else if (group == 0x1A) {
        return testBit(GAME.flags1A, id, arg);
    } else if (group == 0x1C) {
        return testBit(GAME.flags1C, id, arg);
    } else if (group == 0x20) {
        return testBit(GAME.flags20, id, arg);
    } else if (group == 0x40) {
        return testBit(GAME.flags40, id, arg);
    } else if (group == 0x60) {
        return checkProgress(id, arg);
    } else if (group == 0x70) {
        return checkSpecialCondition(id, arg);
    } else if (group == 0x72) {
        return checkPartyStat(id, arg);
    } else if (group == 0x7E) {
        return checkWarpArg(id, arg);
    } else if (group >= 0x80 && group < 0x8F) {
        return checkItem(id, arg);
    } else if (group == 0x92) {
        return checkCard(id, arg);
    }
    return 1;
}

/*
 * Actions: the same flag groups (set to value), 0x70 special actions, 0x74
 * an overlay hook, 0x76/0x78, 0x7A, 0x7C, 0x94 mode changes through the
 * overlay (0x8008AEB4), 0x80-0x8E give/take an item, 0x92 a card.
 */
void applyAction(s32 code, s32 value) {
    u16 group = (code >> 8) & ~1;
    s32 id = code & 0x1FF;

    if (group == 0x00) {
        setBit(FLAGS_00.bits, id, value);
    }
    if (group == 0x02) {
        setBit(GAME.flags02, id, value);
    }
    if (group == 0x04) {
        setBit(GAME.flags04, id, value);
    }
    if (group == 0x06) {
        setBit(GAME.flags06, id, value);
    }
    if (group == 0x08) {
        setBit(GAME.flags08, id, value);
    }
    if (group == 0x0A) {
        setBit(GAME.flags0A, id, value);
    }
    if (group == 0x0C) {
        setBit(GAME.flags0C, id, value);
    }
    if (group == 0x0E) {
        setBit(GAME.flags0E, id, value);
    }
    if (group == 0x10) {
        setBit(GAME.flags10, id, value);
    }
    if (group == 0x18) {
        setBit(GAME.flags18, id, value);
    }
    if (group == 0x1A) {
        setBit(GAME.flags1A, id, value);
    }
    if (group == 0x1C) {
        setBit(GAME.flags1C, id, value);
    }
    if (group == 0x20) {
        setBit(GAME.flags20, id, value);
    }
    if (group == 0x40) {
        setBit(GAME.flags40, id, value);
    }
    if (group == 0x70) {
        checkSpecialCondition(id, 1);
    }
    if (group == 0x74) {
        FIELDSTG_battleFuncs.startEventBattle(id);
    }
    if (group == 0x76) {
        startCardBattle(id, 0);
    }
    if (group == 0x78) {
        startCardBattle(id, 1);
    }
    if (group >= 0x80 && group < 0x8F) {
        changeItem(id, value);
    }
    if (group == 0x90) {
        func_8008B2C4(id);
    }
    if (group == 0x92) {
        changeCard(id, value);
    }
    if (group == 0x94) {
        func_8008AEB4(0xA00, id, 0, 0, 0);
    }
    if (group == 0x7A) {
        if ((u16)id < 30) {
            func_8008AEB4(0xF00, (u16)id, 0, 0, 0);
        } else if ((u32)(id - 0x31) < 0x13 || (u32)(id - 0x46) < 5) {
            func_8008AEB4(0x1300, (u16)id, 0, 0, 0);
        } else {
            func_8008B320();
        }
    }
    if (group == 0x7C) {
        if ((u16)id == 0) {
            func_8008AEB4(0xD00, 0, 0, 0, 0);
        } else if ((u16)id == 1) {
            func_8008AEB4(0xB00, 0, 0, 0, 0);
        }
    }
}

/* All the (code, value) pairs until 0xFFFF must hold */
s32 checkConditions(u16 *list) {
    u16 a;

    for (a = *list; a != 0xFFFF; a = *list) {
        list++;
        if (!checkCondition(a, *list++)) {
            return 0;
        }
    }
    return 1;
}

void applyActions(u16 *list) {
    u16 a;

    for (a = *list; a != 0xFFFF; a = *list) {
        list++;
        applyAction(a, *list++);
    }
}

void updateModeFlags(void) {
    s32 i;
    u8 *p;

    if (GAME.clearTempFlags != 0) {
        for (i = 2, p = &FLAGS_00.bits[i]; i >= 0; i--) {
            *p-- = 0;
        }
        applyAction(0x12, 0);
    }
    if (GAME.funcs.getPrevMode() == 0x700) {
        applyAction(0x11, 1);
        applyAction(0x12, 1);
        if (FLAGS_00.pendingFlag10 != 0) {
            applyAction(0x10, 1);
        } else {
            applyAction(0x10, 0);
        }
        FLAGS_00.pendingFlag10 = 0;
    }
}

/* Clears the save data and sets up a new game */
void newGame(void) {
#if VERSION_US
    HEAP.zero(&GAME, 0x26BC);
    GAME.mode = 0xE01;
    GAME.nextMode = 0xE01;
#elif VERSION_EU
    HEAP.zero(&GAME, 0x26C4);
    GAME.mode = 0x1600;
    GAME.nextMode = 0x1600;
#endif
    GAME.digivolveDemo = 1;
    GAME.countdown[0] = 1;
    GAME.countdown[1] = 8;
    GAME.countdown[3] = 60;
    GAME.modeArg = 0;
    GAME.countdown[2] = 0;
    GAME.unkC = -1;
    initNewGameData();
    GAME.unk30 = (RANDOM.next() & 0x1FF) + 0x200;
}

/* Makes the requested mode current (main calls it before recreating the mode task) */
void commitMode(void) {
    s32 prev;

    if (GAME.nextMode != 0) {
        prev = GAME.mode;
        GAME.mode = GAME.nextMode;
        GAME.nextMode = 0;
        GAME.prevMode = prev;
    }
}

s32 getPrevMode(void) {
    return GAME.prevMode;
}

s32 getMode(void) {
    return GAME.mode;
}

s32 getModeArg(void) {
    return GAME.modeArg;
}

void requestMode(s32 mode, s32 arg) {
    GAME.nextMode = mode;
    GAME.modeArg = arg;
}

s32 isModeChangePending(void) {
    return GAME.nextMode != 0;
}

void initNewGameData(void) {
    TextTools cls;
    s32 i;
    s32 j;
    s16 *dst;
    u16 *src;
    DigimonData *e;

    initTextTools(&cls);
    strcpy(GAME.name, cls.getString(FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0xB));
    GAME.party[0] = -1;
    GAME.party[1] = -1;
    GAME.party[2] = -1;
    for (j = 0; j < 3; j++) {
        strcpy(GAME.decks[j].name, cls.getString(FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), j + 0x16));
    }
    GAME.funcs.giveStarterDeck();
    for (i = 0; i < 8; i++) {
        e = &DIGIMON_DATA[i];
        strcpy(GAME.partners[i].info.name, cls.getString(FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), e->nameId));
        GAME.partners[i].info.stats[STAT_LEVEL] = 1;
        GAME.partners[i].info.stats[STAT_HP] = GAME.partners[i].info.stats[STAT_MAX_HP] = e->hp;
        GAME.partners[i].info.stats[STAT_MP] = GAME.partners[i].info.stats[STAT_MAX_MP] = e->mp;
        /* the battle stats, then the resistances */
        dst = &GAME.partners[i].info.stats[6];
        src = e->battleStats;
        for (j = 0; j < 6; j++) {
            *dst++ = *src++;
        }
        src = e->resistances;
        for (j = 0; j < 7; j++) {
            *dst++ = *src++;
        }
    }
}

s32 getPartyMember(u32 index) {
    if (index >= 3) {
        return -1;
    }
    return GAME.party[index];
}

void setParty(s32 set) {
    s32 i;
    u8 partner;

    for (i = 0; i < 3; i++) {
        partner = STARTER_PARTIES[set][i];
        GAME.party[i] = partner;
        GAME.partners[partner].unlocked = partner + 3;
    }
    GAME.partySet = set;
}

void addCards(s32 item, s32 count) {
    GAME.cardsSeen[item] = 1;
    GAME.cards[item] += count;
    if (GAME.cards[item] >= 10) {
        GAME.cards[item] = 9;
    }
}

void giveStarterDeck(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 40; i++) {
        addCards(STARTER_DECK[i], 1);
    }
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 40; i++) {
            GAME.decks[j].cards[i] = STARTER_DECK[i];
        }
    }
}

void resetPlayTime(void) {
    GAME.playTimeMaxed = 0;
    GAME.playSeconds = 0;
    GAME.playMinutes = 0;
    GAME.playHours = 0;
    GAME.playFrames = 0;
}

void updatePlayTime(void) {
    if ((GAME.playFrames >> 8) >= 60) {
        GAME.playFrames &= 0xFF;
        if (++GAME.playSeconds >= 60) {
            GAME.playSeconds = 0;
            if (++GAME.playMinutes >= 60) {
                GAME.playMinutes = 0;
                if (++GAME.playHours >= 1000) {
                    GAME.playHours = 999;
                    GAME.playMinutes = 59;
                    GAME.playSeconds = 59;
                    GAME.playTimeMaxed = 1;
                }
            }
        }
    }
}

s32 getPartyPartner(u32 index) {
    if (index >= 3) {
        return -1;
    }
    return GAME.partners[GAME.party[index]].unlocked - 3;
}

void setStat(s32 partner, u32 stat, s16 value) {
    PartnerStats *d = &GAME.partners[partner].info;
    s16 *p = d->stats;

    if (stat < 19) {
        p += stat;
        *p = value;
        if (value < 0) {
            *p = 0;
            return;
        }
        if (stat < 2) {
            if (value >= 100) {
                *p = 99;
            }
        } else if (stat - 2 < 4) {
            if (value >= 10000) {
                *p = 9999;
            }
        } else if (value >= 1000) {
            *p = 999;
        }
    }
}

void addStat(s32 partner, u32 stat, s32 delta) {
    PartnerStats *d = &GAME.partners[partner].info;
    s16 *stats = d->stats;
    s16 value;

    if (stat < 19) {
        stats += stat;
        value = *stats + delta;
        *stats = value;
        if (value < 0) {
            *stats = 0;
        } else if (stat < 2) {
            if (value >= 100) {
                *stats = 99;
            }
        } else if (stat - 2 < 4) {
            if (value >= 10000) {
                *stats = 9999;
            }
        } else if (value >= 1000) {
            *stats = 999;
        }
    }
}

typedef struct StatBlock {
    s16 v[22];
} StatBlock;

typedef union ItemData {
    struct {
        /* 0x0 */ s16 unk0;
        /* 0x2 */ s16 unk2[2];
        /* 0x6 */ u16 amounts[2];
        /* 0xA */ s16 atk;
        /* 0xC */ u8 stats[2];
    } weapon;
    struct {
        /* 0x0 */ s16 unk0;
        /* 0x2 */ s16 unk2[2];
        /* 0x6 */ u16 amounts[2];
        /* 0xA */ u8 stats[2];
        /* 0xC */ s16 def;
    } armor;
    struct {
        /* 0x0 */ s16 unk0;
        /* 0x2 */ s16 unk2[2];
        /* 0x6 */ u16 amount;
        /* 0x8 */ u8 stat;
    } acc;
} ItemData;

typedef struct Equip4 {
    s16 v[4];
} Equip4;
extern Equip4 EQUIP_SETS[];
extern s16 EQUIP_SET_BONUSES[][6];

void addStatBonus(s16 *p, s32 stat, s32 delta);

/* A partner's stats with its equipment (and its equipment set bonus) added */
void computeStats(s32 partner, PartnerTotals *out) {
    s16 *equip;
    s32 i;
    s32 j;
    ItemInfo *info;
    ItemData *data;
    u8 type;
    u8 stat;
    s32 amount;

    GameState *save = &GAME;
    PartnerStats *d;

    *(StatBlock *)out = *(StatBlock *)save->partners[partner].info.stats;
    d = &GAME.partners[partner].info;
    equip = d->equip;
    for (i = 0; i < 6; i++) {
        if (equip[i] > 0) {
            info = GET_ITEM[0](equip[i]);
            type = info->type;
            data = (ItemData *)info->data;
            if ((u8)(type - 2) < 13) {
                out->fields.battle[0] += data->weapon.atk;
                if (out->fields.battle[0] >= 1000) {
                    out->fields.battle[0] = 999;
                }
                for (j = 0; j < 2; j++) {
                    stat = *(j + data->weapon.stats);
                    amount = data->weapon.amounts[j];
                    if (stat != 0) {
                        addStatBonus(out->stats, stat, (s16)amount);
                    }
                }
            } else if ((u8)(type - 15) < 6) {
                out->fields.battle[1] += data->armor.def;
                if (out->fields.battle[1] >= 1000) {
                    out->fields.battle[1] = 999;
                }
                for (j = 0; j < 2; j++) {
                    stat = *(j + data->armor.stats);
                    amount = data->armor.amounts[j];
                    if (stat != 0) {
                        addStatBonus(out->stats, stat, (s16)amount);
                    }
                }
            } else if ((u8)(type - 21) < 4) {
                stat = data->acc.stat;
                amount = data->acc.amount;
                if (stat != 0) {
                    addStatBonus(out->stats, stat, (s16)amount);
                }
            } else {
                continue;
            }
            out->fields.battle[5] += data->weapon.unk0;
            if (out->fields.battle[5] >= 1000) {
                out->fields.battle[5] = 999;
            }
        }
    }
    out->fields.battle[0] -= out->fields.lowered[0];
    if (out->fields.battle[0] < 0) {
        out->fields.battle[0] = 0;
    }
    out->fields.battle[1] -= out->fields.lowered[1];
    if (out->fields.battle[1] < 0) {
        out->fields.battle[1] = 0;
    }
    out->fields.battle[4] -= out->fields.lowered[2];
    if (out->fields.battle[4] < 0) {
        out->fields.battle[4] = 0;
    }
    if (equip[0] == EQUIP_SETS[partner].v[0] && equip[1] == EQUIP_SETS[partner].v[1] &&
        equip[2] == EQUIP_SETS[partner].v[2] && equip[3] == EQUIP_SETS[partner].v[3]) {
        for (i = 0; i < 6; i++) {
            out->fields.battle[i] += EQUIP_SET_BONUSES[partner][i];
        }
    }
}

void addStatBonus(s16 *p, s32 stat, s32 delta) {
    s32 i;
    s16 value;

    if (stat == 7) {
        for (i = 0; i < 6; i++) {
            value = p[i + 6] + delta;
            p[i + 6] = value;
            if (value >= 1000) {
                p[i + 6] = 999;
            }
        }
    } else if (stat - 1 < 6U) {
        value = p[stat + 5] + delta;
        p[stat + 5] = value;
        if (value >= 1000) {
            p[stat + 5] = 999;
        }
    } else if (stat - 8 < 7U) {
        value = p[stat + 4] + delta;
        p[stat + 4] = value;
        if (value >= 1000) {
            p[stat + 4] = 999;
        }
    }
}

/* The flag bitset FLAGS_00 and the event functions */
GameFlags FLAGS_00 = {
    { 0 }, 0, checkConditions, applyAction, checkCondition, applyActions, updateModeFlags,
};

/* checkSpecialCondition's conditions: { id, kind << 4 | op, arg }, up to 0xFF */
u8 SPECIAL_CONDITIONS[] = {
#if VERSION_US
    0x3A, 0x00, 0x00,  0x00, 0x10, 0x00,  0x01, 0x10, 0x01,  0x02, 0x10, 0x02,  0x10, 0x11, 0x00,
    0x12, 0x11, 0x01,  0x11, 0x11, 0x02,  0x0B, 0x11, 0x03,  0x0D, 0x11, 0x04,  0x0C, 0x11, 0x05,
    0x0F, 0x11, 0x06,  0x0E, 0x11, 0x07,  0x42, 0x12, 0x00,  0x44, 0x12, 0x01,  0x43, 0x12, 0x02,
    0x47, 0x12, 0x03,  0x46, 0x12, 0x04,  0x45, 0x12, 0x05,  0x49, 0x12, 0x06,  0x48, 0x12, 0x07,
    0x37, 0x13, 0x00,  0x39, 0x13, 0x01,  0x38, 0x13, 0x02,  0x31, 0x13, 0x03,  0x32, 0x13, 0x04,
    0x33, 0x13, 0x05,  0x35, 0x13, 0x06,  0x34, 0x13, 0x07,  0x4A, 0x14, 0x00,  0x4C, 0x14, 0x01,
    0x4B, 0x14, 0x02,  0x4F, 0x14, 0x03,  0x4E, 0x14, 0x04,  0x4D, 0x14, 0x05,  0x51, 0x14, 0x06,
    0x50, 0x14, 0x07,  0x25, 0x15, 0x00,  0x26, 0x15, 0x01,  0x27, 0x15, 0x02,  0x28, 0x15, 0x03,
    0x29, 0x15, 0x04,  0x2E, 0x16, 0x00,  0x30, 0x16, 0x01,  0x2F, 0x16, 0x02,  0x2A, 0x16, 0x03,
    0x2B, 0x16, 0x04,  0x2C, 0x16, 0x05,  0x36, 0x16, 0x06,  0x2D, 0x16, 0x07,  0x74, 0x20, 0x00,
    0x75, 0x20, 0x01,  0x76, 0x20, 0x02,  0x77, 0x20, 0x03,  0x78, 0x20, 0x04,  0x79, 0x20, 0x05,
    0x7A, 0x20, 0x06,  0x7B, 0x20, 0x07,  0x7C, 0x20, 0x08,  0x7D, 0x20, 0x09,  0x8B, 0x21, 0x00,
    0x8C, 0x21, 0x01,  0x8D, 0x21, 0x02,  0x8E, 0x21, 0x03,  0x8F, 0x21, 0x04,  0x90, 0x21, 0x05,
    0x91, 0x21, 0x06,  0x92, 0x21, 0x07,  0x7E, 0x22, 0x00,  0x7F, 0x22, 0x01,  0x80, 0x22, 0x02,
    0x81, 0x22, 0x03,  0x82, 0x22, 0x04,  0x83, 0x22, 0x05,  0x84, 0x22, 0x06,  0x85, 0x22, 0x07,
    0x86, 0x22, 0x08,  0x87, 0x22, 0x09,  0x06, 0x30, 0x00,  0x03, 0x30, 0x01,  0x0A, 0x30, 0x02,
    0x07, 0x30, 0x03,  0x04, 0x30, 0x04,  0x05, 0x30, 0x05,  0x09, 0x30, 0x06,  0x14, 0x30, 0x07,
    0x08, 0x30, 0x08,  0x3F, 0x30, 0x09,  0x40, 0x30, 0x0A,  0x41, 0x30, 0x0B,  0x93, 0x30, 0x0C,
    0x94, 0x30, 0x0D,  0x15, 0x30, 0x0E,  0x16, 0x30, 0x0F,  0x17, 0x30, 0x10,  0x18, 0x30, 0x11,
    0x19, 0x30, 0x12,  0x1A, 0x30, 0x13,  0x1C, 0x30, 0x14,  0x1D, 0x30, 0x15,  0x21, 0x30, 0x16,
    0x1E, 0x30, 0x17,  0x1F, 0x30, 0x18,  0x20, 0x30, 0x19,  0x22, 0x30, 0x1A,  0x23, 0x30, 0x1B,
    0x24, 0x30, 0x1C,  0x3B, 0x30, 0x1D,  0x3C, 0x30, 0x1E,  0x3D, 0x30, 0x1F,  0x3E, 0x30, 0x20,
    0x71, 0x40, 0x00,  0x70, 0x40, 0x01,  0x73, 0x40, 0x02,  0x72, 0x40, 0x03,  0x13, 0x50, 0x00,
    0xFF,
#elif VERSION_EU
    0x3A, 0x00, 0x00,  0x96, 0x01, 0x00,  0x00, 0x10, 0x00,  0x01, 0x10, 0x01,  0x02, 0x10, 0x02,
    0x10, 0x11, 0x00,  0x12, 0x11, 0x01,  0x11, 0x11, 0x02,  0x0B, 0x11, 0x03,  0x0D, 0x11, 0x04,
    0x0C, 0x11, 0x05,  0x0F, 0x11, 0x06,  0x0E, 0x11, 0x07,  0x42, 0x12, 0x00,  0x44, 0x12, 0x01,
    0x43, 0x12, 0x02,  0x47, 0x12, 0x03,  0x46, 0x12, 0x04,  0x45, 0x12, 0x05,  0x49, 0x12, 0x06,
    0x48, 0x12, 0x07,  0x37, 0x13, 0x00,  0x39, 0x13, 0x01,  0x38, 0x13, 0x02,  0x31, 0x13, 0x03,
    0x32, 0x13, 0x04,  0x33, 0x13, 0x05,  0x35, 0x13, 0x06,  0x34, 0x13, 0x07,  0x4A, 0x14, 0x00,
    0x4C, 0x14, 0x01,  0x4B, 0x14, 0x02,  0x4F, 0x14, 0x03,  0x4E, 0x14, 0x04,  0x4D, 0x14, 0x05,
    0x51, 0x14, 0x06,  0x50, 0x14, 0x07,  0x25, 0x15, 0x00,  0x26, 0x15, 0x01,  0x27, 0x15, 0x02,
    0x28, 0x15, 0x03,  0x29, 0x15, 0x04,  0x2E, 0x16, 0x00,  0x30, 0x16, 0x01,  0x2F, 0x16, 0x02,
    0x2A, 0x16, 0x03,  0x2B, 0x16, 0x04,  0x2C, 0x16, 0x05,  0x36, 0x16, 0x06,  0x2D, 0x16, 0x07,
    0x95, 0x17, 0x00,  0x53, 0x18, 0x00,  0x55, 0x19, 0x00,  0x74, 0x20, 0x00,  0x75, 0x20, 0x01,
    0x76, 0x20, 0x02,  0x77, 0x20, 0x03,  0x78, 0x20, 0x04,  0x79, 0x20, 0x05,  0x7A, 0x20, 0x06,
    0x7B, 0x20, 0x07,  0x7C, 0x20, 0x08,  0x7D, 0x20, 0x09,  0x8B, 0x21, 0x00,  0x8C, 0x21, 0x01,
    0x8D, 0x21, 0x02,  0x8E, 0x21, 0x03,  0x8F, 0x21, 0x04,  0x90, 0x21, 0x05,  0x91, 0x21, 0x06,
    0x92, 0x21, 0x07,  0x7E, 0x22, 0x00,  0x7F, 0x22, 0x01,  0x80, 0x22, 0x02,  0x81, 0x22, 0x03,
    0x82, 0x22, 0x04,  0x83, 0x22, 0x05,  0x84, 0x22, 0x06,  0x85, 0x22, 0x07,  0x86, 0x22, 0x08,
    0x87, 0x22, 0x09,  0x06, 0x30, 0x00,  0x03, 0x30, 0x01,  0x0A, 0x30, 0x02,  0x07, 0x30, 0x03,
    0x04, 0x30, 0x04,  0x05, 0x30, 0x05,  0x09, 0x30, 0x06,  0x14, 0x30, 0x07,  0x08, 0x30, 0x08,
    0x3F, 0x30, 0x09,  0x40, 0x30, 0x0A,  0x41, 0x30, 0x0B,  0x93, 0x30, 0x0C,  0x94, 0x30, 0x0D,
    0x15, 0x30, 0x0E,  0x16, 0x30, 0x0F,  0x17, 0x30, 0x10,  0x18, 0x30, 0x11,  0x19, 0x30, 0x12,
    0x1A, 0x30, 0x13,  0x1C, 0x30, 0x14,  0x1D, 0x30, 0x15,  0x21, 0x30, 0x16,  0x1E, 0x30, 0x17,
    0x1F, 0x30, 0x18,  0x20, 0x30, 0x19,  0x22, 0x30, 0x1A,  0x23, 0x30, 0x1B,  0x24, 0x30, 0x1C,
    0x3B, 0x30, 0x1D,  0x3C, 0x30, 0x1E,  0x3D, 0x30, 0x1F,  0x3E, 0x30, 0x20,  0x71, 0x40, 0x00,
    0x70, 0x40, 0x01,  0x73, 0x40, 0x02,  0x72, 0x40, 0x03,  0x54, 0x41, 0x00,  0x13, 0x50, 0x00,
    0xFF,
#endif
};

/* checkMoney's amounts, by its argument */
s32 MONEY_REQUIRED[] = {
    800, 1600, 2700, 4000, 6000, 8700, 11500, 17500, 24000, 32000,
};
s32 MONEY_GAINS[] = {
    100, 300, 600, 1000, 1600, 3000, 5000, 8500,
};
s32 MONEY_LOSSES[] = {
    800, 1600, 2700, 4000, 6000, 8700, 11500, 17500, 24000, 32000,
};

/* checkProgressRange's ranges of GAME.progress: { min, max } */
u8 PROGRESS_RANGES[][2] = {
    { 0x02, 0x12 }, { 0x04, 0x17 }, { 0x04, 0x2C }, { 0x14, 0x17 }, { 0x18, 0x25 }, { 0x27, 0x2A },
    { 0x04, 0x63 }, { 0x07, 0x63 }, { 0x18, 0x63 }, { 0x16, 0x2A }, { 0x12, 0x63 }, { 0x14, 0x63 },
    { 0x0F, 0x63 }, { 0x1E, 0x63 }, { 0x05, 0x0A }, { 0x0F, 0x12 }, { 0x14, 0x16 }, { 0x18, 0x1A },
    { 0x1B, 0x25 }, { 0x27, 0x28 }, { 0x25, 0x26 }, { 0x1B, 0x24 }, { 0x22, 0x26 }, { 0x1B, 0x26 },
    { 0x1C, 0x25 }, { 0x1B, 0x21 }, { 0x04, 0x26 }, { 0x04, 0x15 }, { 0x0E, 0x26 }, { 0x11, 0x26 },
    { 0x0A, 0x0D }, { 0x1D, 0x26 }, { 0x0C, 0x16 }, { 0x00, 0x00 },
};

/* checkPartyStat's thresholds */
s32 PARTY_STAT_THRESHOLDS[] = {
    60, 150, 210, 285, 378, 492, 630, 795, 990, 1218, 1482, 1785, 2049, 2277, 2472,
};

/* The save data, the game mode and the methods */
GameState GAME = {
    .funcs = {
        newGame, commitMode, getMode, getModeArg, requestMode, isModeChangePending, getPrevMode,
        getPartyMember, setParty, addCards, giveStarterDeck, getPartyPartner, setStat, addStat,
        computeStats, getPartnerSlots, setPartnerSlots, listPartnerEntries,
        addPartnerEntry, getPartnerEntry, setPartnerEntry, getPartnerStats,
        resetPlayTime, updatePlayTime,
    },
};

/* setParty's partners, by party set */
u8 STARTER_PARTIES[][3] = {
    { 0x00, 0x06, 0x07 }, { 0x02, 0x03, 0x06 }, { 0x01, 0x05, 0x07 },
};

/* The cards of giveStarterDeck's deck */
s32 STARTER_DECK[40] = {
    24, 24, 24, 45, 45, 50, 59, 60, 95, 99,
    100, 100, 102, 122, 138, 141, 141, 143, 145, 181,
    184, 185, 185, 188, 221, 224, 228, 230, 230, 230,
    267, 268, 268, 270, 274, 303, 313, 314, 314, 314,
};

/* Each partner's equipment set and what wearing it whole adds (computeStats) */
Equip4 EQUIP_SETS[] = {
    { { 0x00F3, 0x010D, 0x0062, 0x011C } }, { { 0x00F2, 0x0102, 0x0070, 0x011D } },
    { { 0x00DE, 0x0100, 0x007C, 0x011A } }, { { 0x00F4, 0x010F, 0x00A3, 0x011E } },
    { { 0x00D3, 0x010C, 0x00CB, 0x0120 } }, { { 0x00F5, 0x010E, 0x0095, 0x011F } },
    { { 0x00DD, 0x0101, 0x0089, 0x011B } }, { { 0x00E8, 0x00FF, 0x0088, 0x0119 } },
};
s16 EQUIP_SET_BONUSES[][6] = {
    { 4, 4, 4, 4, 4, 20 }, { 10, 10, 0, 0, 0, 20 }, { 10, 0, 0, 0, 10, 20 }, { 0, 10, 10, 0, 0, 20 },
    { 10, 0, 0, 10, 0, 20 }, { 0, 0, 0, 10, 10, 20 }, { 10, 0, 10, 0, 0, 20 }, { 0, 10, 0, 10, 0, 20 },
};
