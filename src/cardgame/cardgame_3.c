/* The third object of CARDGAME.PRO (see cardgame.c), from CARDGAME_startMessage
   (USA): its rodata starts at 0x80082E30, a multiple of 8. */

#include "cardgame.h"

/* Opens message text for a step */
void CARDGAME_startMessage(CardBattle *battle, CardScreen *screen, s32 text) {
    battle->unk424 = 0;
    screen->openMessage(screen, text, 0, 0, 1);
    battle->stepState = 1;
}

/* Waits for the message window to open, for cross or triangle, then for the window to close; 1 once it has */
s32 CARDGAME_waitMessage(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        if (screen->message.state == 2) {
            battle->stepState = 2;
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 3;
            screen->closeMessage(screen);
        }
        break;
    case 3:
        if (screen->message.state == 0) {
            battle->stepState = 4;
        }
        break;
    case 4:
        done = 1;
        break;
    }
    return done;
}

/* When the last card was the player's (or force): takes its record entry off
   for a while and closes the panels */
void CARDGAME_startClosePanels(CardBattle *battle, CardScreen *screen, s32 force) {
    if (battle->record.entries[battle->record.entryCount - 1].unk4 == 0 || force) {
        battle->record.entryCount--;
        screen->closePanels(screen);
        battle->unk498.unk1 = 2;
        battle->stepState = 1;
    } else {
        battle->stepState = 2;
    }
}

/* Waits for the panels to close and puts the record entry back; 1 once done */
s32 CARDGAME_stepClosePanels(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            battle->stepState = 2;
            battle->record.entryCount++;
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* When the last card was the player's (or force): takes its record entry off
   for a while and opens the panels */
void CARDGAME_startOpenPanels(CardBattle *battle, CardScreen *screen, s32 force) {
    if (battle->record.entries[battle->record.entryCount - 1].unk4 == 0 || force) {
        screen->openPanels(screen);
        battle->unk498.unk5 = 1;
        battle->unk498.unk1 = 1;
        battle->stepState = 1;
        battle->record.entryCount--;
    } else {
        battle->stepState = 2;
    }
}

/* Waits for the panels to open and puts the record entry back; 1 once done */
s32 CARDGAME_stepOpenPanels(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        if (battle->unk498.unk0 == 0 && screen->panels[0].state == 2) {
            battle->stepState = 2;
            battle->record.entryCount++;
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Steps each slot's shown values (its sprite's unk43 and unk44) one unit toward the slot's unk6 and unk8, with a sound; 1 once all are there, 2 if a slot's unk8 reached 0 (marked in unk46F) */
s32 CARDGAME_countSlotValues(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 changed = 0;
    s32 side;
    s32 i;
    CardSprite *sprites;

    switch (battle->stepState) {
    case 1:
    default:
        for (i = 0; i < 12; i++) {
            battle->unk46F[i] = 0;
        }
        battle->stepState = 2;
        battle->unk438 = 0;
        break;
    case 2:
        done = 1;
        for (side = 0; side < 2; side++) {
            if (side == 0) {
                sprites = &screen->sprites[0];
            } else {
                sprites = &screen->sprites[6];
            }
            for (i = 0; i < battle->players[side].slotCount; i++) {
                if (sprites[i].unk43 != battle->players[side].slots[i].unk6) {
                    if (sprites[i].unk43 > battle->players[side].slots[i].unk6) {
                        sprites[i].unk43--;
                    } else {
                        sprites[i].unk43++;
                    }
                    done = 0;
                    changed = 1;
                }
                if (sprites[i].unk44 != battle->players[side].slots[i].unk8) {
                    if (sprites[i].unk44 > battle->players[side].slots[i].unk8) {
                        sprites[i].unk44--;
                    } else {
                        sprites[i].unk44++;
                    }
                    done = 0;
                    if (battle->players[side].slots[i].unk8 == 0) {
                        battle->unk46F[i + side * 6] = 1;
                        battle->unk438 = 1;
                    }
                    changed = 1;
                }
            }
        }
        if (done && battle->unk438) {
            done = 2;
        }
        if (changed) {
            SOUND.playSound(SOUND_COUNT);
        }
        break;
    }
    return done;
}

/* Whether the condition kind (1-11) of the card being played holds for its side: 1 if it does */
s32 CARDGAME_checkPlayCondition(CardBattle *battle, CardScreen *screen, s32 kind) {
    CardDrawer drawer;
    CardDrawer drawer2;
    CardDrawer drawer3;
    CardDrawer drawer4;
    s32 ok = 0;
    s32 side = battle->record.entries[battle->record.entryCount - 1].unk4;
    s32 other = side ^ 1;
    s32 i;
    s32 slot;
    s32 j;
    CardSlot *p;
    s32 n;
    s32 k;
    s32 valid;

    switch (kind) {
    case 1:
        if (battle->sides[other].pile.handCount == 0) {
            ok = 1;
        }
        break;
    case 2:
        initCardDrawer(&drawer);
        ok = 1;
        for (i = 0; i < battle->sides[other].pile.handCount; i++) {
            drawer.setCard(battle->cards[battle->sides[other].pile.hand[i]] + 1);
            if (drawer.card->color == 6 && drawer.card->kind == 0x10) {
                ok = 0;
                break;
            }
        }
        break;
    case 3:
        initCardDrawer(&drawer2);
        ok = 1;
        for (i = 0; i < battle->sides[other].pile.handCount; i++) {
            drawer2.setCard(battle->cards[battle->sides[other].pile.hand[i]] + 1);
            if (drawer2.card->color != 5) {
                ok = 0;
                break;
            }
        }
        break;
    case 4:
        if (battle->sides[side].pile.discardCount == 0) {
            ok = 1;
        }
        break;
    case 5:
        if (battle->sides[side].pile.deckCount == 0) {
            ok = 1;
        }
        break;
    case 6:
        if (battle->sides[other].pile.deckCount == 0) {
            ok = 1;
        }
        break;
    case 7:
        initCardDrawer(&drawer3);
        ok = 1;
        for (i = battle->sides[side].pile.deckTop; i < 40; i++) {
            drawer3.setCard(battle->cards[battle->sides[side].pile.deck[i]] + 1);
            if (drawer3.card->kind == 0x10) {
                ok = 0;
                break;
            }
        }
        break;
    case 8:
        initCardDrawer(&drawer4);
        ok = 1;
        for (i = battle->sides[side].pile.deckTop; i < 40; i++) {
            drawer4.setCard(battle->cards[battle->sides[side].pile.deck[i]] + 1);
            if (drawer4.card->kind != 0x10) {
                ok = 0;
                break;
            }
        }
        break;
    case 9:
        ok = 1;
        n = battle->record.entryCount - 1;
        for (slot = 0; slot < 12; slot++) {
            battle->unk46F[slot] = 0;
            if (slot < 6) {
                if (slot >= battle->players[0].slotCount) {
                    continue;
                }
                p = &battle->players[0].slots[slot];
            } else {
                if (slot - 6 >= battle->players[1].slotCount) {
                    continue;
                }
                p = &battle->players[1].slots[slot - 6];
            }
            if (p->order == battle->record.entries[n].unk6) {
                ok = 0;
                break;
            }
        }
        break;
    case 10:
        ok = 1;
        for (i = 0; i < 12 && ok == 1; i++) {
            k = i - 6;
            if (i < 6) {
                valid = i < battle->players[0].slotCount;
            } else {
                valid = k < battle->players[1].slotCount;
            }
            if (valid) {
                switch (battle->record.entries[battle->record.entryCount - 1].unk5) {
                case 1:
                    if (side == 0) {
                        if (i < 6) {
                            ok = 0;
                        }
                    } else {
                        if (i >= 6) {
                            ok = 0;
                        }
                    }
                    break;
                case 2:
                    if (side == 0) {
                        if (i >= 6) {
                            ok = 0;
                        }
                    } else {
                        if (i < 6) {
                            ok = 0;
                        }
                    }
                    break;
                case 3:
                    ok = 0;
                    break;
                case 4:
                    if (screen->getCardColor(screen, i < 6 ? battle->players[0].slots[i].card : battle->players[1].slots[i - 6].card) != 1) {
                        ok = 0;
                    }
                    break;
                case 5:
                    if (screen->getCardColor(screen, i < 6 ? battle->players[0].slots[i].card : battle->players[1].slots[i - 6].card) != 2) {
                        ok = 0;
                    }
                    break;
                case 6:
                    if (screen->getCardColor(screen, i < 6 ? battle->players[0].slots[i].card : battle->players[1].slots[i - 6].card) == 3) {
                        ok = 0;
                    }
                    break;
                case 7:
                    if (screen->getCardColor(screen, i < 6 ? battle->players[0].slots[i].card : battle->players[1].slots[i - 6].card) != 4) {
                        ok = 0;
                    }
                    break;
                case 8:
                    if (screen->getCardColor(screen, i < 6 ? battle->players[0].slots[i].card : battle->players[1].slots[i - 6].card) == 6) {
                        ok = 0;
                    }
                    break;
                }
            }
        }
        break;
    case 11:
        ok = 1;
        for (j = 0; j < battle->sides[side].pile.handCount; j++) {
            if (battle->record.entries[battle->record.entryCount - 1].unk6 == battle->sides[side].pile.hand[j]) {
                ok = 0;
                break;
            }
        }
        break;
    }
    return ok;
}

/* The mode's task: sets up the display and starts the battle, then returns
   to the field once it is over (or to mode 0x1500 when the mode's low
   bits are set) */
void CARDGAME_updateScene(Task *task, CardBattle **items) {
    TimLoader tim;
    Layer *layer;

    switch (task->state) {
    case 0:
    default:
        GFX.funcs.reset();
        GFX.funcs.allocPrimBuffers(0xA000);
        GFX.funcs.setDisplayMode(0x140, 0xF0, 0, 0);
        initTimLoader(&tim);
        tim.setImagePos(0x280, 0);
        tim.loadArchive(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16));
        tim.setImagePos(0x340, 0);
        tim.loadArchive(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 1));
        layer = GFX.funcs.createLayer(&CARDGAME_screenRect, 3, 0x100);
        layer->setBgColor(layer, 0x1F, 0x1F, 0x1F);
        items[0] = CARDGAME_createBattle(GAME.funcs.getModeArg());
        task->nextState(task);
        break;
    case 1:
        if (items[0]->result == 2) {
            task->setState(task, 2);
            items[0]->setState(items[0], 3);
        }
        break;
    case 2:
        switch (task->substate) {
        case 0:
        default:
            GAME.funcs.requestMode((GAME.funcs.getMode() & 0xF) ? 0x1500 : GAME.fieldMode, 0);
            task->nextSubstate(task);
            break;
        case 1:
            break;
        }
        break;
    case 3:
        break;
    }
}

/* The mode's entry point (MODE_ENTRY_POINTS) */
Task *CARDGAME_start(void) {
    return createTask(CARDGAME_updateScene, sizeof(Task), 4);
}

void CARDGAME_drawMarker(CardMarker *marker) {
    SpriteDrawer drawer;
    s32 row;

    if (marker->scaleX != 0 && marker->scaleY != 0) {
        initSpriteDrawer(&drawer);
        drawer.setPivot(marker->x, marker->y + 19);
        drawer.setScale(marker->scaleX, marker->scaleY, 0x1000);
        if (marker->fast == 0) {
            drawer.setClutRow((marker->time >> 2) % 16);
        } else {
            row = marker->time >> 1;
            if (row >= 7) {
                row = 7;
            }
            drawer.setClutRow(row);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x47, marker->x, marker->y);
        marker->time += GFX.funcs.getFrameTime();
    }
}

void CARDGAME_updateMarker(CardMarker *marker) {
    switch (marker->state) {
    case 0:
    default:
        marker->nextState(marker);
        marker->scaleDuration = 10;
        marker->scaleTime = 10;
        marker->phase = 0;
        marker->scaleX = 0x1000;
        marker->scaleY = 0;
        break;
    case 1:
        switch (marker->phase) {
        case 0:
            marker->scaleY = 0x1000 - (marker->scaleTime << 12) / marker->scaleDuration;
            marker->scaleTime -= GFX.funcs.getFrameTime();
            if (marker->scaleTime <= 0) {
                marker->scaleY = 0x1000;
                marker->phase = 1;
            }
            break;
        case 1:
            break;
        case 2:
            marker->setState(marker, 2);
            break;
        }
        break;
    case 2:
        marker->scaleY = (marker->scaleTime << 12) / marker->scaleDuration;
        marker->scaleTime -= GFX.funcs.getFrameTime();
        if (marker->scaleTime <= 0) {
            marker->scaleY = 0;
            marker->setState(marker, 3);
        }
        break;
    case 3:
        break;
    }
    CARDGAME_drawMarker(marker);
}

void CARDGAME_setMarkerPos(CardMarker *marker, s16 x, s16 y) {
    marker->x = x;
    marker->y = y;
}

void CARDGAME_setMarkerFast(CardMarker *marker) {
    marker->fast = 1;
    marker->time = 0;
}

void CARDGAME_closeMarker(CardMarker *marker) {
    marker->scaleDuration = 5;
    marker->scaleTime = 5;
    marker->phase = 2;
    marker->scaleY = 0x1000;
}

CardMarker *CARDGAME_createMarker(s16 x, s16 y) {
    CardMarker *marker = createTask(CARDGAME_updateMarker, sizeof(CardMarker), 0);

    marker->setPos = CARDGAME_setMarkerPos;
    marker->close = CARDGAME_closeMarker;
    marker->setFast = CARDGAME_setMarkerFast;
    marker->x = x;
    marker->y = y;
    marker->fast = 0;
    return marker;
}

void CARDGAME_drawDeckWindow(CardDeckWindow *window) {
    s16 rows[8] = {0, 1, 2, 3, 2, 1, 0, 0};
    SpriteDrawer frame;
    SpriteDrawer icon;
    s32 i;

    if (window->scaleX != 0 && window->scaleY != 0) {
        initSpriteDrawer(&frame);
        frame.setPivot(window->x, window->y);
        frame.setScale(window->scaleX, window->scaleY, 0x1000);
        frame.setLayerId(0x100, 1);
        frame.setTexture(0x280, 0);
        frame.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x45, window->x, window->y);
        initSpriteDrawer(&icon);
        icon.setPivot(window->x, window->y);
        if (window->blink != 0) {
            i = window->time >> 1;
            if (i >= 7) {
                i = 7;
            }
            icon.setClutRow(rows[i]);
            window->time += GFX.funcs.getFrameTime();
        }
        icon.setScale(window->scaleX, window->scaleY, 0x1000);
        icon.setLayerId(0x100, 1);
        icon.setTexture(0x280, 0);
        icon.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x46, window->x, window->y);
    }
}

void CARDGAME_updateDeckWindow(CardDeckWindow *window, TextWindow **texts) {
    s32 i;

    switch (window->state) {
    case 0:
    default:
        window->nextState(window);
        window->scaleDuration = 12;
        window->scaleTime = 12;
        window->phase = 0;
        window->scaleY = 0x1000;
        window->scaleX = 0;
        texts[0] = createTextWindow(0x100, 1, 0, 0);
        texts[0]->setString(texts[0], GAME.decks[window->deck].name, -1);
        texts[0]->setPos(texts[0], window->x + 5, window->y + 3);
        for (i = 0; i < 6; i++) {
            texts[i + 1] = createTextWindow(0x100, 1, 0, 0);
            texts[i + 1]->setPos(texts[i + 1], window->x + CARDGAME_deckCountOffsets[i].x, window->y + CARDGAME_deckCountOffsets[i].y);
            texts[i + 1]->setNumber(texts[i + 1], 0, window->counts[i]);
            texts[i + 1]->setRightAlign(texts[i + 1], 1);
        }
        break;
    case 1:
        switch (window->phase) {
        case 0:
            window->scaleX = 0x1000 - (window->scaleTime << 12) / window->scaleDuration;
            window->scaleTime -= GFX.funcs.getFrameTime();
            if (window->scaleTime <= 0) {
                window->scaleX = 0x1000;
                window->phase = 1;
            }
            break;
        case 1:
            break;
        case 2:
            window->setState(window, 2);
            break;
        }
        break;
    case 2:
        window->scaleX = (window->scaleTime << 12) / window->scaleDuration;
        window->scaleTime -= GFX.funcs.getFrameTime();
        if (window->scaleTime <= 0) {
            window->scaleX = 0;
            window->setState(window, 3);
        }
        break;
    case 3:
        break;
    }
    if (window->phase == 1) {
        texts[0]->setPos(texts[0], window->x + 5, window->y + 3);
        texts[0]->setVisible(texts[0], 1);
        for (i = 0; i < 6; i++) {
            texts[i + 1]->setVisible(texts[i + 1], 1);
            texts[i + 1]->setPos(texts[i + 1], window->x + CARDGAME_deckCountOffsets[i].x, window->y + CARDGAME_deckCountOffsets[i].y);
        }
    } else {
        texts[0]->setVisible(texts[0], 0);
        for (i = 0; i < 6; i++) {
            texts[i + 1]->setVisible(texts[i + 1], 0);
        }
    }
    CARDGAME_drawDeckWindow(window);
}

void CARDGAME_setDeckWindowBlink(CardDeckWindow *window) {
    window->blink = 1;
    window->time = 0;
}

void CARDGAME_closeDeckWindow(CardDeckWindow *window) {
    window->scaleDuration = 6;
    window->scaleTime = 6;
    window->phase = 2;
    window->scaleX = 0x1000;
}

CardDeckWindow *CARDGAME_createDeckWindow(s32 deck, s32 x, s32 y) {
    CardDrawer drawer;
    CardDeckWindow *window;
    s32 i;

    initCardDrawer(&drawer);
    window = createTask(CARDGAME_updateDeckWindow, sizeof(CardDeckWindow), 7 * 4);
    for (i = 0; i < 6; i++) {
        window->counts[i] = 0;
    }
    for (i = 0; i < 40; i++) {
        drawer.setCard(GAME.decks[deck].cards[i]);
        window->counts[drawer.card->color - 1]++;
    }
    window->setBlink = CARDGAME_setDeckWindowBlink;
    window->deck = deck;
    window->x = x;
    window->y = y;
    window->blink = 0;
    window->close = CARDGAME_closeDeckWindow;
    return window;
}

/* Draws the scrolling background, which fades in through its palettes (unkE9E
   1) and then stays */
void CARDGAME_drawBackground(CardScreen *screen) {
    SpriteDrawer drawer;
    s32 row;
    s32 x;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 2);
    row = 0;
    drawer.setTexture(0x340, 0);
    switch (screen->unkE9E) {
    case 1:
        if (screen->unkE9D >= 4) {
            screen->unkE9D -= 4;
            if (++screen->unkE9C >= 11) {
                screen->unkE9C = 11;
                screen->unkE9E = 2;
            }
        }
        row = screen->unkE9C;
        screen->unkE9D += GFX.funcs.getFrameTime();
        break;
    case 2:
        row = 11;
        break;
    case 0:
        break;
    }
    drawer.setClutRow(row);
    x = (screen->time >> 1) & 0x3F;
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0, x, x);
}

void CARDGAME_drawNumber(CardNumber *number, s32 scaled) {
    SpriteDrawer drawer;
    s32 value;
    s32 digit;
    s32 i;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, number->depth);
    drawer.setTexture(0x340, 0);
    if (scaled != 0) {
        drawer.setPivot(number->pivotX, number->pivotY);
        drawer.setScale(number->scaleX, number->scaleY, 0x1000);
    }
    value = number->value;
    for (i = 0; i < number->digits; i++) {
        digit = value % 10;
        if (i == 0 || number->leadingZeros != 0 || digit != 0 || value / 10 != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), digit + 0x14,
                        number->x + (number->digits - 1 - i) * 7, number->y);
        }
        value /= 10;
    }
}

/* Draws a gauge at its place (CARDGAME_gaugePositions), at its scale */
void CARDGAME_drawGauge(CardScreen *screen, CardScreenItems *items, s32 index, CardGauge *p) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x340, 0);
    drawer.setPivot(CARDGAME_gaugePositions[index].x + 4, CARDGAME_gaugePositions[index].y + 23);
    drawer.setScale(0x1000, p->to, 0x1000);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), p->value + 6, CARDGAME_gaugePositions[index].x, CARDGAME_gaugePositions[index].y);
}

/* Grows (state 1), holds (2) or shrinks (3) a gauge, and draws it */
void CARDGAME_updateGauge(CardScreen *screen, CardScreenItems *items, s32 index, CardGauge *p) {
    if (p->state != 0) {
        switch (p->state) {
        case 1:
        default:
            p->to = 0x1000 - (p->time << 12) / p->duration;
            p->time -= GFX.funcs.getFrameTime();
            if (p->time <= 0) {
                p->state = 2;
            }
            break;
        case 2:
            p->to = 0x1000;
            break;
        case 3:
            p->time -= GFX.funcs.getFrameTime();
            if (p->time <= 0) {
                p->state = 0;
            }
            p->to = (p->time << 12) / p->duration;
            break;
        }
        CARDGAME_drawGauge(screen, items, index, p);
    }
}

/* Runs and draws the three gauges */
void CARDGAME_updateGauges(CardScreen *screen, CardScreenItems *items) {
    s32 i;

    for (i = 0; i < 3; i++) {
        CARDGAME_updateGauge(screen, items, i, &screen->gauges[i]);
    }
}

/* Draws the number in a type 3 window: its low four bits, and the sprite
   for its high bits */
static inline void drawWindowCount(CardWindow *window) {
    CardNumber number;
    SpriteDrawer digits;

    number.depth = 1;
    number.digits = 2;
    number.leadingZeros = 0;
    number.x = window->x + 0x18;
    number.y = window->y + 4;
    number.value = window->unk10 & 0xF;
    number.pivotX = window->x + CARDGAME_windowLayouts[window->unkC].x;
    number.pivotY = window->y + CARDGAME_windowLayouts[window->unkC].y;
    number.scaleX = window->from;
    number.scaleY = 0x1000;
    CARDGAME_drawNumber(&number, 1);
    initSpriteDrawer(&digits);
    digits.setLayerId(0x100, 1);
    digits.setTexture(0x280, 0);
    digits.setPivot(window->x + CARDGAME_windowLayouts[window->unkC].x,
                    window->y + CARDGAME_windowLayouts[window->unkC].y);
    digits.setScale(window->from, 0x1000, 0x1000);
    digits.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), (window->unk10 >> 4) * 3 + 0x1D,
                window->x + 6, window->y + 2);
}

/* Draws a window's frame (CARDGAME_windowLayouts), scaled while it opens, and
   its count */
void CARDGAME_drawWindowFrame(CardScreen *screen, CardScreenItems *items, CardWindow *window) {
    s32 offset = 0;

    if (window->unkC == 2 && window->unk14[2] == 1) {
        offset = 0x45;
    }
    if (window->state == 2 && window->unkC == 3 && window->unkE != 0) {
        drawWindowCount(window);
    }
    {
    SpriteDrawer frame;

    if (CARDGAME_windowLayouts[window->unkC].kind == 2) {
        initSpriteDrawer(&frame);
        frame.setLayerId(0x100, 1);
        frame.setTexture(0x340, 0);
        if (window->from != 0x1000) {
            frame.setPivot(window->x + CARDGAME_windowLayouts[window->unkC].x,
                           window->y + CARDGAME_windowLayouts[window->unkC].y);
            frame.setScale(window->from, 0x1000, 0x1000);
        }
        frame.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_windowLayouts[window->unkC].sprite,
                   window->x + offset, window->y);
    } else {
        initSpriteDrawer(&frame);
        frame.setLayerId(0x100, 1);
        frame.setTexture(0x280, 0);
        if (window->from != 0x1000) {
            frame.setPivot(window->x + CARDGAME_windowLayouts[window->unkC].x,
                           window->y + CARDGAME_windowLayouts[window->unkC].y);
            frame.setScale(window->from, 0x1000, 0x1000);
        }
        frame.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_windowLayouts[window->unkC].sprite,
                   window->x + offset, window->y);
    }
    }
}

/* Puts a window's two numbers (unk14) on its texts, right aligned */
void CARDGAME_drawWindowNumbers(CardScreen *screen, CardScreenItems *items, CardWindow *window) {
    s32 values[2];
    s32 i;

    values[0] = window->unk14[0];
    values[1] = window->unk14[1];
    for (i = 0; i < 2; i++) {
        items->texts[i]->setPos(items->texts[i], window->x + 0x67, window->y + 4 + i * 13);
        items->texts[i]->setNumber(items->texts[i], 0, values[i]);
        items->texts[i]->setRightAlign(items->texts[i], 1);
    }
}

/* Puts a window's string unk10 of file on text, or hides text when it has
   none */
void CARDGAME_drawWindowText(CardScreen *screen, CardWindow *window, TextWindow *text, s32 file, s32 index) {
    if (window->unk10 != 0) {
        text->setPos(text, window->x + CARDGAME_windowTextOffsets[index], window->y + 4);
        text->setString(text, FILE_CACHE.load(file), window->unk10);
    } else {
        text->setVisible(text, 0);
    }
}

/* Puts a window's string unk10 of file on text, centred on the screen (string
   0x1F in palette 3), or hides text */
void CARDGAME_drawCenteredText(CardScreen *screen, CardScreenItems *items, CardWindow *window, TextWindow *text, s32 file) {
    TextTools tools;
    s32 width;

    if (window->unk10 != 0) {
        text->setString(text, FILE_CACHE.load(file), window->unk10);
        initTextTools(&tools);
        width = tools.measure(text->text, text->style, text->spacingX);
        if (window->unk10 == 0x1F) {
            text->setPalette(text, 3);
        } else {
            text->setPalette(text, 0);
        }
        text->setVisible(text, 1);
        text->setPos(text, 0xA0 - width / 2, window->y + 4);
    } else {
        text->setVisible(text, 0);
    }
}

/* Opens (state 1), shows (2) or closes (3) window index, each its own way */
void CARDGAME_updateWindow(CardScreen *screen, CardScreenItems *items, CardWindow *window, s32 index) {
    if (window->state == 0) {
        return;
    }
    switch (window->state) {
    case 1:
    default:
        window->from = 0x1000 - (window->time << 12) / window->duration;
        window->time -= GFX.funcs.getFrameTime();
        if (window->time <= 0) {
            window->state = 2;
            switch (index) {
            case 0:
                CARDGAME_drawWindowText(screen, window, items->moreTexts[2], TEXT_FILE(TEXT_CARD_GAME), 1);
                break;
            case 2:
                CARDGAME_drawWindowText(screen, window, items->moreTexts[4], TEXT_FILE(TEXT_CARD_NAMES), 0);
                break;
            case 3:
                CARDGAME_drawWindowText(screen, window, items->moreTexts[3], TEXT_FILE(TEXT_CARD_GAME), 0);
                break;
            case 5:
                if (window->unkC == 5) {
                    CARDGAME_drawCenteredText(screen, items, window, items->moreTexts[0], TEXT_FILE(TEXT_CARD_GAME));
                } else {
                    CARDGAME_drawWindowText(screen, window, items->moreTexts[0], TEXT_FILE(TEXT_CARD_GAME), window->unk10 != 0x24);
                }
                break;
            case 1:
            case 4:
                break;
            }
        }
        break;
    case 2:
        window->from = 0x1000;
        switch (index) {
        case 2:
            CARDGAME_drawWindowText(screen, window, items->moreTexts[4], TEXT_FILE(TEXT_CARD_NAMES), 0);
            break;
        case 3:
            CARDGAME_drawWindowText(screen, window, items->moreTexts[3], TEXT_FILE(TEXT_CARD_GAME), 0);
            break;
        case 4:
            if (window->unk10 == 0x1F4) {
                if (window->unk14[2] == 0) {
                    window->unk10 = 0x2A;
                    CARDGAME_drawWindowText(screen, window, items->moreTexts[5], TEXT_FILE(TEXT_CARD_GAME), 1);
                } else {
                    window->unk10 = 0x40;
                    CARDGAME_drawWindowNumbers(screen, items, window);
                    CARDGAME_drawWindowText(screen, window, items->moreTexts[5], TEXT_FILE(TEXT_CARD_GAME), 2);
                }
            } else {
                items->texts[0]->setVisible(items->texts[0], 0);
                items->texts[1]->setVisible(items->texts[1], 0);
                CARDGAME_drawWindowText(screen, window, items->moreTexts[5], TEXT_FILE(TEXT_CARD_EFFECTS), 0);
            }
            break;
        }
        break;
    case 3:
        switch (index) {
        case 0:
            items->moreTexts[2]->setVisible(items->moreTexts[2], 0);
            break;
        case 2:
            items->moreTexts[4]->setVisible(items->moreTexts[4], 0);
            break;
        case 3:
            items->moreTexts[3]->setVisible(items->moreTexts[3], 0);
            break;
        case 4:
            items->texts[0]->setVisible(items->texts[0], 0);
            items->texts[1]->setVisible(items->texts[1], 0);
            items->moreTexts[5]->setVisible(items->moreTexts[5], 0);
            break;
        case 5:
            items->moreTexts[0]->setVisible(items->moreTexts[0], 0);
            break;
        case 1:
            break;
        }
        window->time -= GFX.funcs.getFrameTime();
        if (window->time <= 0) {
            window->state = 0;
        }
        window->from = (window->time << 12) / window->duration;
        break;
    }
    CARDGAME_drawWindowFrame(screen, items, window);
}

/* Runs and draws the six windows */
void CARDGAME_updateWindows(CardScreen *screen, CardScreenItems *items) {
    s32 i;

    for (i = 0; i < 6; i++) {
        CARDGAME_updateWindow(screen, items, &screen->windows[i], i);
    }
}

/* Draws the message window's frame at a scale */
void CARDGAME_drawMessageFrame(CardScreen *screen, CardScreenItems *items, s16 scale, s32 x, s32 y) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x280, 0);
    drawer.setPivot(0, 0x78);
    drawer.setScale(scale, 0x1000, 0x1000);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x1A, x, y);
}

/* Draws sprite 0x18 of the message window */
void CARDGAME_drawMessageMark(CardScreen *screen, CardScreenItems *items, s32 x, s32 y) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x280, 0);
    drawer.setScale(0x1000, 0x1000, 0x1000);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x18, x, y);
}

/* The message window: it opens at its place, shows its message with the cursor, then closes */
void CARDGAME_updateMessageWindow(CardScreen *screen, CardScreenItems *items) {
    TextTools tools;
    s16 scale;
    s32 t;
    s32 i;
    s32 x;

    if (screen->message.state == 0) {
        return;
    }
    switch (screen->message.state) {
    case 1:
    default:
        t = screen->message.time << 12;
        scale = 0x1000 - (screen->message.duration != 0 ? t / screen->message.duration : t);
        screen->message.time -= GFX.funcs.getFrameTime();
        if (screen->message.time <= 0) {
            screen->message.state = 2;
#if VERSION_US
            if (screen->message.prompt != 0) {
                items->cursor->setVisible(items->cursor, 1);
                items->cursor->setPos(items->cursor, 0x14, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x11 + screen->message.choice * 14);
                items->moreTexts[7]->setString(items->moreTexts[7], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x18);
                items->moreTexts[7]->setPos(items->moreTexts[7], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
            } else {
                items->moreTexts[7]->setVisible(items->moreTexts[7], 0);
                items->cursor->setVisible(items->cursor, 0);
            }
#elif VERSION_EU
            switch (screen->message.prompt) {
            case 0:
            default:
                items->moreTexts[7]->setVisible(items->moreTexts[7], 0);
                items->cursor->setVisible(items->cursor, 0);
                break;
            case 1:
                items->cursor->setVisible(items->cursor, 1);
                items->cursor->setPos(items->cursor, 0x14, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x11 + screen->message.choice * 14);
                items->moreTexts[7]->setString(items->moreTexts[7], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x18);
                items->moreTexts[7]->setPos(items->moreTexts[7], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
                break;
            case 2:
            case 3:
                items->cursor->setVisible(items->cursor, 1);
                items->cursor->setPos(items->cursor, 0x14, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x11 + screen->message.choice * 14);
                items->moreTexts[7]->setString(items->moreTexts[7], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x45);
                if (screen->message.prompt == 3) {
                    items->moreTexts[7]->setPalette(items->moreTexts[7], 7);
                }
                items->moreTexts[7]->setPos(items->moreTexts[7], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
                items->texts[0]->setString(items->texts[0], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x46);
                items->texts[0]->setRightAlign(items->texts[0], 0);
                items->texts[0]->setPos(items->texts[0], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x20);
                break;
            }
#endif
            if (screen->message.place == 3) {
                items->moreTexts[1]->setPos(items->moreTexts[1], CARDGAME_messageWindowPositions[3][0] + 0x40, CARDGAME_messageWindowPositions[3][1] + 4);
                items->moreTexts[1]->setString(items->moreTexts[1], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x42);
                items->moreTexts[7]->setString(items->moreTexts[7], FILE_CACHE.load(TEXT_FILE(TEXT_ITEM_NAMES)), screen->message.message);
                items->moreTexts[7]->setPos(items->moreTexts[7], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x40, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
            } else if (screen->message.message != 0) {
                items->moreTexts[1]->setPos(items->moreTexts[1], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 4);
                items->moreTexts[1]->setString(items->moreTexts[1], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), screen->message.message);
                if (screen->message.message == 0x13) {
                    items->moreTexts[7]->setString(items->moreTexts[7], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x2B);
                    items->moreTexts[7]->setPos(items->moreTexts[7], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
                    initTextTools(&tools);
                    x = tools.measure(items->moreTexts[7]->text, items->moreTexts[7]->style, items->moreTexts[7]->spacingX) + 0x1B;
                    for (i = 0; i < 2; i++) {
                        items->texts[i]->setPos(items->texts[i], CARDGAME_messageWindowPositions[screen->message.place][0] + x + 0xE, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12 + i * 14);
                        items->texts[i]->setNumber(items->texts[i], 0, screen->panels[i].unk44);
                        items->texts[i]->setRightAlign(items->texts[i], 0);
                    }
                } else if (screen->message.message == 0x3E) {
                    items->texts[0]->setPos(items->texts[0], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x3E, CARDGAME_messageWindowPositions[screen->message.place][1] + 4);
                    items->texts[0]->setNumber(items->texts[0], 0, screen->unk5E);
                    items->texts[0]->setRightAlign(items->texts[0], 1);
                    items->texts[1]->setString(items->texts[1], FILE_CACHE.load(TEXT_FILE(TEXT_DECK_EDITOR)), (screen->unk5C + 1) / 2);
                    items->texts[1]->setPos(items->texts[1], CARDGAME_messageWindowPositions[screen->message.place][0] + 0x1B, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x12);
                }
            } else {
                items->moreTexts[1]->setVisible(items->moreTexts[1], 0);
            }
        }
        break;
    case 2:
        scale = 0x1000;
        if (screen->message.place == 3) {
            CARDGAME_drawMessageMark(screen, items, 0x1C, 0x64);
        }
        if (screen->message.prompt != 0) {
            items->cursor->setPos(items->cursor, 0x14, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x11 + screen->message.choice * 14);
        }
        break;
    case 4:
        scale = 0x1000;
        items->cursor->setPos(items->cursor, 0x14 - rsin((screen->message.time << 12) / 20) / 512, CARDGAME_messageWindowPositions[screen->message.place][1] + 0x11 + screen->message.choice * 14);
        screen->message.time -= GFX.funcs.getFrameTime();
        if (screen->message.time <= 0) {
            items->cursor->setVisible(items->cursor, 0);
            screen->closeMessage(screen);
            items->cursor->setIdleDelay(items->cursor, 0x20);
            screen->message.state = 5;
        }
        break;
    case 5:
        items->cursor->setVisible(items->cursor, 0);
        items->moreTexts[1]->setVisible(items->moreTexts[1], 0);
#if VERSION_EU
        items->moreTexts[7]->setPalette(items->moreTexts[7], 0);
#endif
        items->moreTexts[7]->setVisible(items->moreTexts[7], 0);
        items->texts[0]->setVisible(items->texts[0], 0);
        items->texts[1]->setVisible(items->texts[1], 0);
        items->texts[2]->setVisible(items->texts[2], 0);
        screen->message.time -= GFX.funcs.getFrameTime();
        if (screen->message.time <= 0) {
            screen->message.state = 0;
        }
        scale = (screen->message.time << 12) / screen->message.duration;
        break;
    }
    CARDGAME_drawMessageFrame(screen, items, scale, CARDGAME_messageWindowPositions[screen->message.place][0], CARDGAME_messageWindowPositions[screen->message.place][1]);
}

/* Draws the menu window's frame at a scale */
void CARDGAME_drawMenuFrame(CardScreen *screen, CardScreenItems *items, s16 scale, s32 x, s32 y) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x340, 0);
    drawer.setPivot(0, 0x86);
    drawer.setScale(scale, 0x1000, 0x1000);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 1, x, y);
}

/* A menu window (CardScreen.menuState): it opens, shows text file 0x10 with
   the cursor on menuRow, then closes */
void CARDGAME_updateMenuWindow(CardScreen *screen, CardScreenItems *items) {
    s16 scale;
    s32 t;

    if (screen->menuState == 0) {
        return;
    }
    switch (screen->menuState) {
    case 1:
    default:
        t = screen->menuTime << 12;
        scale = 0x1000 - (screen->menuDuration != 0 ? t / screen->menuDuration : t);
        screen->menuTime -= GFX.funcs.getFrameTime();
        if (screen->menuTime <= 0) {
            screen->menuState = 2;
            items->cursor->setVisible(items->cursor, 1);
            items->cursor->setPos(items->cursor, 10, screen->menuRow * 14 + 0x65);
            items->moreTexts[6]->setString(items->moreTexts[6], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x20);
            items->moreTexts[6]->setPos(items->moreTexts[6], 0x18, 0x65);
        }
        break;
    case 2:
        scale = 0x1000;
        items->cursor->setPos(items->cursor, 10, screen->menuRow * 14 + 0x65);
        break;
    case 4:
        scale = 0x1000;
        items->cursor->setPos(items->cursor, 10 - rsin((screen->menuTime << 12) / 20) / 512, screen->menuRow * 14 + 0x65);
        screen->menuTime -= GFX.funcs.getFrameTime();
        if (screen->menuTime <= 0) {
            items->cursor->setVisible(items->cursor, 0);
            screen->closeMenu(screen);
            items->cursor->setIdleDelay(items->cursor, 0x20);
            screen->menuState = 5;
        }
        break;
    case 5:
        items->cursor->setVisible(items->cursor, 0);
        items->moreTexts[6]->setVisible(items->moreTexts[6], 0);
        screen->menuTime -= GFX.funcs.getFrameTime();
        if (screen->menuTime <= 0) {
            screen->menuState = 0;
        }
        scale = (screen->menuTime << 12) / screen->menuDuration;
        break;
    }
    CARDGAME_drawMenuFrame(screen, items, scale, 0, 0x60);
}

s32 CARDGAME_getHandOffset(s32 count, s32 index) {
    s32 step;

    if (count < 7) {
        step = 0x2900;
    } else {
        step = 0xF600 / count;
    }
    return step * index;
}

/* Draws a side's panel (CardScreen.panels): its lights, bars, numbers and parts, which blink by its flags */
void CARDGAME_drawPanel(CardPanel *panel, CardScreenItems *items, s32 side) {
    s32 y;
    s32 imageY;

    y = panel->y;
    imageY = panel->unk3E;
#if VERSION_EU
    if (SHIFT_PAL_SCREEN) {
        if (side == 0) {
            y += 12;
            imageY += 12;
        } else {
            y -= 12;
            imageY -= 12;
        }
    }
#endif
    /* the lights */
    {
        SpriteDrawer drawer;
        s32 t;
        s32 i;

        t = panel->unk8 % 36;
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x340, 0);
        drawer.setClutRow(CARDGAME_panelLightCluts[t / 6]);
        for (i = 0; i < 5; i++) {
            if (panel->flags[i] != 0) {
                drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xD, panel->x + CARDGAME_panelLayouts[side].flagLights.x + i * 0x2A, y + CARDGAME_panelLayouts[side].flagLights.y);
            }
        }
        if (panel->flags[8] != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xC, panel->x + CARDGAME_panelLayouts[side].unk44.x, y + CARDGAME_panelLayouts[side].unk44.y);
        }
        if (panel->flags[9] != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xC, panel->x + CARDGAME_panelLayouts[side].unk48.x, y + CARDGAME_panelLayouts[side].unk48.y);
        }
        if (panel->flags[6] != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xE, panel->x + CARDGAME_panelLayouts[side].unk38.x, y + CARDGAME_panelLayouts[side].unk38.y);
        }
        if (panel->flags[7] != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xE, panel->x + CARDGAME_panelLayouts[side].unk3C.x, y + CARDGAME_panelLayouts[side].unk3C.y);
        }
        if (panel->flags[5] != 0) {
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0xF, panel->unk20 + CARDGAME_panelLayouts[side].unk40.x, panel->unk22 + CARDGAME_panelLayouts[side].unk40.y);
        }
    }
    /* the bars and the numbers */
    {
        SpriteDrawer drawer;
        CardNumber number;
        s32 t;
        s32 i;

        t = panel->unk8 % 24;
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x340, 0);
        if (panel->flags[8] != 0) {
            drawer.setClutRow(t / 6 + 1);
        } else {
            drawer.setClutRow(0);
        }
#if VERSION_US
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_panelBarSprites[1][0], panel->x + CARDGAME_panelLayouts[side].unk18.x, y + CARDGAME_panelLayouts[side].unk18.y);
#elif VERSION_EU
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_panelBarSprites[LANGUAGE][0], panel->x + CARDGAME_panelLayouts[side].unk18.x, y + CARDGAME_panelLayouts[side].unk18.y);
#endif
        if (panel->flags[9] != 0) {
            drawer.setClutRow(t / 6 + 1);
        } else {
            drawer.setClutRow(0);
        }
#if VERSION_US
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_panelBarSprites[1][1], panel->x + CARDGAME_panelLayouts[side].unk20.x, y + CARDGAME_panelLayouts[side].unk20.y);
#elif VERSION_EU
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_panelBarSprites[LANGUAGE][1], panel->x + CARDGAME_panelLayouts[side].unk20.x, y + CARDGAME_panelLayouts[side].unk20.y);
#endif

        number.depth = 1;
        number.x = panel->x + CARDGAME_panelLayouts[side].unkC.x;
        number.y = CARDGAME_panelLayouts[side].unkC.y + y;
        number.digits = 2;
        number.leadingZeros = 1;
        number.value = panel->unk18[5];
        CARDGAME_drawNumber(&number, 0);
        number.x = panel->x + CARDGAME_panelLayouts[side].unk10.x;
        number.y = CARDGAME_panelLayouts[side].unk10.y + y;
        number.digits = 2;
        number.leadingZeros = 1;
        number.value = panel->unk18[6];
        CARDGAME_drawNumber(&number, 0);
        number.x = panel->x + CARDGAME_panelLayouts[side].unk1C.x;
        number.y = CARDGAME_panelLayouts[side].unk1C.y + y;
        number.digits = 3;
        number.leadingZeros = 0;
        number.value = panel->unk10;
        CARDGAME_drawNumber(&number, 0);
        number.x = panel->x + CARDGAME_panelLayouts[side].unk24.x;
        number.y = CARDGAME_panelLayouts[side].unk24.y + y;
        number.digits = 3;
        number.leadingZeros = 0;
        number.value = panel->unk12;
        CARDGAME_drawNumber(&number, 0);
        for (i = 0; i < 5; i++) {
            number.x = panel->x + CARDGAME_panelLayouts[side].flagNumbers.x + i * 0x2A;
            number.y = CARDGAME_panelLayouts[side].flagNumbers.y + y;
            number.digits = 2;
            number.leadingZeros = 1;
            number.value = panel->unk18[i];
            CARDGAME_drawNumber(&number, 0);
        }
        number.x = panel->unk20 + CARDGAME_panelLayouts[side].unk14.x;
        number.y = panel->unk22 + CARDGAME_panelLayouts[side].unk14.y;
        number.digits = 2;
        number.leadingZeros = 1;
        number.value = panel->unk28;
        CARDGAME_drawNumber(&number, 0);
    }
    /* the image, the blinking parts and the frame */
    {
        SpriteDrawer drawer;
        s32 t;
        s32 frame;
        s32 boxFrame;
        s32 iconT;
        s32 iconFrame;
        s32 i;

        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_panelLayouts[side].unk2 + panel->unk44, panel->unk3C, imageY);
        t = panel->unk8 % 30;
        if (panel->flags[7] != 0) {
            frame = t / 6;
        } else {
            frame = 0;
        }
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_flag7Frames[frame] + 9, panel->x + CARDGAME_panelLayouts[side].unk2C.x, y + CARDGAME_panelLayouts[side].unk2C.y);
        t = panel->unk8 % 30;
        if (panel->flags[6] != 0) {
            frame = t / 6;
        } else {
            frame = 0;
        }
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_flag6Frames[frame] + 6, panel->x + CARDGAME_panelLayouts[side].unk28.x, y + CARDGAME_panelLayouts[side].unk28.y);
        t = panel->unk8 % 30;
        if (panel->flags[5] != 0) {
            boxFrame = t / 6;
        } else {
            boxFrame = 0;
        }
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_boxFrames[boxFrame] + 0x31, panel->unk20, panel->unk22);
        iconT = panel->unk8 % 30;
        for (i = 0; i < 5; i++) {
            if (panel->flags[i] != 0) {
                iconFrame = iconT / 6;
            } else {
                iconFrame = 0;
            }
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_flagIconSprites[i] + CARDGAME_flagIconFrames[iconFrame], panel->x + CARDGAME_panelLayouts[side].flagIcons.x + i * 0x2A, y + CARDGAME_panelLayouts[side].flagIcons.y);
        }
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_panelLayouts[side].unk3, panel->unk20 + CARDGAME_panelLayouts[side].unk30.x, panel->unk22 + CARDGAME_panelLayouts[side].unk30.y);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), CARDGAME_panelLayouts[side].frame, panel->x, y);
    }
    panel->unk8 = (panel->unk8 + GFX.funcs.getFrameTime()) & 0xFFFF;
}

/* Moves a side's panel between its shown and hidden places: in (state 1), out (3), or only x/y in or out (4, 5) */
void CARDGAME_slidePanel(CardPanel *panel, CardScreenItems *items, s32 side) {
    s32 shownX;
    s32 shownY;
    s32 hiddenX;
    s32 hiddenY;
    s32 shown20;
    s32 hidden20;
    s32 shown22;
    s32 hidden22;
    s32 shown3C;
    s32 hidden3C;
    s32 shown3E;
    s32 hidden3E;

    if (side == 0) {
        shownX = 0;
        shownY = 0x8D;
        hiddenX = 0;
        hiddenY = 0xF1;
        shown20 = 0x120;
        shown22 = 0x8F;
        hidden20 = 0x147;
        hidden22 = 0x8F;
        shown3C = 0x113;
        shown3E = 0xBD;
        hidden3E = 0xBD;
        /* the match depends on setting it in both branches, not once after them */
        hidden3C = 0x13A;
    } else {
        shownX = 0;
        shownY = 0;
        hiddenX = 0;
        hiddenY = -100;
        shown20 = 0x120;
        shown22 = 0x50;
        hidden20 = 0x147;
        hidden22 = 0x50;
        shown3C = 0x113;
        shown3E = 0x26;
        hidden3E = 0x26;
        hidden3C = 0x13A;
    }
    /* the match depends on the empty case 0 */
    switch (panel->unk6) {
    case 1:
        panel->unk6 = 0;
        break;
    case 2:
        panel->unk6 = 0;
        break;
    case 0:
        break;
    }
    switch (panel->state) {
    case 1:
        if ((panel->time -= GFX.funcs.getFrameTime()) > 0) {
            panel->x = shownX - (shownX - hiddenX) * panel->time / panel->duration;
            panel->y = shownY - (shownY - hiddenY) * panel->time / panel->duration;
            panel->unk20 = shown20 - (shown20 - hidden20) * panel->time / panel->duration;
            panel->unk22 = shown22 - (shown22 - hidden22) * panel->time / panel->duration;
            panel->unk3C = shown3C - (shown3C - hidden3C) * panel->time / panel->duration;
            panel->unk3E = shown3E - (shown3E - hidden3E) * panel->time / panel->duration;
        } else {
            panel->state = 2;
            panel->time = 0;
            panel->duration = 0;
            panel->x = shownX;
            panel->y = shownY;
            panel->unk20 = shown20;
            panel->unk22 = shown22;
            panel->unk3C = shown3C;
            panel->unk3E = shown3E;
        }
        break;
    case 3:
        if ((panel->time -= GFX.funcs.getFrameTime()) > 0) {
            panel->x = hiddenX - (hiddenX - shownX) * panel->time / panel->duration;
            panel->y = hiddenY - (hiddenY - shownY) * panel->time / panel->duration;
            panel->unk20 = hidden20 - (hidden20 - shown20) * panel->time / panel->duration;
            panel->unk22 = hidden22 - (hidden22 - shown22) * panel->time / panel->duration;
            panel->unk3C = hidden3C - (hidden3C - shown3C) * panel->time / panel->duration;
            panel->unk3E = hidden3E - (hidden3E - shown3E) * panel->time / panel->duration;
        } else {
            panel->state = 0;
            panel->unk6 = 1;
            panel->time = 0;
            panel->duration = 0;
            panel->x = hiddenX;
            panel->y = hiddenY;
            panel->unk20 = hidden20;
            panel->unk22 = hidden22;
            panel->unk3C = hidden3C;
            panel->unk3E = hidden3C; /* not hidden3E */
        }
        break;
    case 4:
        panel->unk20 = hidden20;
        panel->unk22 = hidden22;
        panel->unk3C = hidden3C;
        panel->unk3E = hidden3C;
        if ((panel->time -= GFX.funcs.getFrameTime()) > 0) {
            panel->x = shownX - (shownX - hiddenX) * panel->time / panel->duration;
            panel->y = shownY - (shownY - hiddenY) * panel->time / panel->duration;
        } else {
            panel->state = 2;
            panel->time = 0;
            panel->duration = 0;
            panel->x = shownX;
            panel->y = shownY;
        }
        break;
    case 5:
        panel->unk20 = hidden20;
        panel->unk22 = hidden22;
        panel->unk3C = hidden3C;
        panel->unk3E = hidden3C;
        if ((panel->time -= GFX.funcs.getFrameTime()) > 0) {
            panel->x = hiddenX - (hiddenX - shownX) * panel->time / panel->duration;
            panel->y = hiddenY - (hiddenY - shownY) * panel->time / panel->duration;
        } else {
            panel->state = 0;
            panel->unk6 = 1;
            panel->time = 0;
            panel->duration = 0;
            panel->x = hiddenX;
            panel->y = hiddenY;
        }
        break;
    case 0:
    case 2:
        break;
    }
}

/* Draws a side's panel icon at the panel's open or close scale, and once the
   panel is open (state 2) its label; the European version takes both
   positions from CARDGAME_panelIconPositions, by SHIFT_PAL_SCREEN */
void CARDGAME_drawPanelIcon(CardScreen *screen, CardScreenItems *items, s32 side, CardPanelScale *scale) {
    SpriteDrawer drawer;
    s32 iconX;
    s32 iconY;
    s32 textX;
    s32 textY;

#if VERSION_US
    if (side == 0) {
        iconX = 0x7C;
        iconY = 0x33;
        textX = 0x8A;
        textY = 0x34;
    } else {
        iconX = 0x7C;
        iconY = 0x23;
        textX = 0x8A;
        textY = 0x24;
    }
#elif VERSION_EU
    if (side == 0) {
        iconX = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][0][0].x;
        iconY = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][0][0].y;
        textX = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][1][0].x;
        textY = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][1][0].y;
    } else {
        iconX = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][0][1].x;
        iconY = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][0][1].y;
        textX = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][1][1].x;
        textY = CARDGAME_panelIconPositions[SHIFT_PAL_SCREEN][1][1].y;
    }
#endif
    if (scale->state != 0) {
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.setPivot(screen->panels[side].x + iconX, screen->panels[side].y + iconY);
        drawer.setScale(scale->value, 0x1000, 0x1000);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), side == 0 ? 0x44 : 0x43,
                    screen->panels[side].x + iconX, screen->panels[side].y + iconY);
    }
    if (scale->state == 2) {
        items->panelTexts[side]->setPos(items->panelTexts[side], screen->panels[side].x + textX,
                                        screen->panels[side].y + textY);
        items->panelTexts[side]->setString(items->panelTexts[side], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_GAME)), 0x3F);
    } else {
        items->panelTexts[side]->setVisible(items->panelTexts[side], 0);
    }
}

/* Grows (state 1) or shrinks (3) side's panel icon, and draws it */
void CARDGAME_updatePanelIcon(CardScreen *screen, CardScreenItems *items, s32 side, CardPanelScale *scale) {
    switch (scale->state) {
    case 1:
        scale->value = 0x1000 - (scale->time << 12) / scale->duration;
        scale->time -= GFX.funcs.getFrameTime();
        if (scale->time <= 0) {
            scale->state = 2;
        }
        break;
    case 3:
        scale->value = (scale->time << 12) / scale->duration;
        scale->time -= GFX.funcs.getFrameTime();
        if (scale->time <= 0) {
            scale->state = 0;
        }
        break;
    case 0:
        break;
    case 2:
        break;
    }
    CARDGAME_drawPanelIcon(screen, items, side, scale);
}

/* Moves a blinker towards its target; it stops there (state 1) */
void CARDGAME_moveBlinker(CardBlinker *blinker) {
    blinker->time -= GFX.funcs.getFrameTime();
    if (blinker->time != 0) {
        blinker->x = blinker->targetX - (blinker->targetX - blinker->startX) * blinker->time / blinker->duration;
        blinker->y = blinker->targetY - (blinker->targetY - blinker->startY) * blinker->time / blinker->duration;
    } else {
        blinker->state = 1;
        blinker->duration = 0;
        blinker->time = 0;
        blinker->x = blinker->targetX;
        blinker->y = blinker->targetY;
    }
}

/* Draws a blinker, its CLUT row changing every four frames */
void CARDGAME_drawBlinker(CardBlinker *blinker) {
    SpriteDrawer drawer;
    s32 row;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x340, 0);
    switch (++blinker->blinkTime >> 2) {
    default:
        blinker->blinkTime = 0;
    case 0:
        row = 0;
        break;
    case 1:
        row = 3;
        break;
    case 2:
        row = 1;
        break;
    }
    drawer.setClutRow(row);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 8, blinker->x, blinker->y);
}

/* Moves and draws the twelve blinkers */
void CARDGAME_updateBlinkers(CardScreen *screen, CardScreenItems *items) {
    u32 i;
    s32 two;

    i = 0;
    two = 2;
    for (; i < 12; i++) {
        if (screen->blinkers[i].state != 0) {
            if (screen->blinkers[i].state == two) {
                CARDGAME_moveBlinker(&screen->blinkers[i]);
            }
            CARDGAME_drawBlinker(&screen->blinkers[i]);
        }
    }
}

/* Runs and draws both panels and their icons */
void CARDGAME_updatePanels(CardScreen *screen, CardScreenItems *items) {
    CARDGAME_updatePanelIcon(screen, items, 0, &screen->panels[0].scale);
    CARDGAME_updatePanelIcon(screen, items, 1, &screen->panels[1].scale);
    CARDGAME_slidePanel(&screen->panels[0], items, 0);
    CARDGAME_slidePanel(&screen->panels[1], items, 1);
    CARDGAME_drawPanel(&screen->panels[0], items, 0);
    CARDGAME_drawPanel(&screen->panels[1], items, 1);
}

/* Moves and scales a sprite towards its targets; at the end it plays a sound (unless in state 3) and goes to state 1 */
void CARDGAME_moveSprite(CardScreen *screen, CardSprite *sprite) {
    sprite->time -= GFX.funcs.getFrameTime();
    if (sprite->time > 0) {
        if (sprite->x != sprite->targetX || sprite->y != sprite->targetY) {
            sprite->x = sprite->targetX - (sprite->targetX - sprite->startX) * sprite->time / sprite->duration;
            sprite->y = sprite->targetY - (sprite->targetY - sprite->startY) * sprite->time / sprite->duration;
        }
        /* both scales, read as one word */
        if (*(s32 *)&sprite->scaleX != *(s32 *)&sprite->targetScaleX) {
            sprite->scaleX = sprite->targetScaleX - (sprite->targetScaleX - sprite->startScaleX) * sprite->time / sprite->duration;
            sprite->scaleY = sprite->targetScaleY - (sprite->targetScaleY - sprite->startScaleY) * sprite->time / sprite->duration;
        }
    } else {
        if (sprite->state != 3) {
            SOUND.playSound(0x800460BD);
        }
        sprite->state = 1;
        sprite->time = 0;
        sprite->duration = 0;
        sprite->x = sprite->targetX;
        sprite->y = sprite->targetY;
        sprite->scaleX = sprite->targetScaleX;
        sprite->scaleY = sprite->targetScaleY;
        if (sprite->unk48 == 0) {
            sprite->moving = 0;
        }
    }
}

/* Flies a sprite from start to target along an arc while scaling it; at the end it swaps start and target, goes to state 2 with 2.5 times the time, and returns 1 */
s32 CARDGAME_flySprite(CardScreen *screen, CardSprite *sprite) {
    s32 done = 0;
    s32 dy;
    s32 offset;
    s32 startX;
    s32 startY;
    s32 scaledDy;
    s16 scaleX;
    s16 scaleY;

    if (sprite->unk30 > 0) {
        sprite->unk30 -= GFX.funcs.getFrameTime();
        sprite->scaleX = 0x1C00 - sprite->unk30 * 0xC0;
        sprite->scaleY = 0x1C00 - sprite->unk30 * 0xC0;
        if (sprite->unk30 <= 0) {
            sprite->unk48 |= 5;
            SOUND.playSound(0x8004603C);
            sprite->targetScaleX = 0x1200;
            sprite->targetScaleY = 0x1200;
            sprite->startScaleX = sprite->scaleX = 0x1C00;
            sprite->startScaleY = sprite->scaleY = 0x1C00;
            sprite->unk30 = 0;
        }
        return 0;
    }
    sprite->time -= GFX.funcs.getFrameTime();
    if (sprite->time > 0) {
        dy = sprite->targetY - sprite->startY;
        scaledDy = dy * sprite->time;
        sprite->x = sprite->targetX - (sprite->targetX - sprite->startX) * sprite->time / sprite->duration;
        sprite->y = sprite->targetY - scaledDy / sprite->duration;
        offset = rsin((sprite->time << 12) / (sprite->duration * 2)) * 0x1C00;
        sprite->y += (dy > 0 ? -offset : offset) / 0x1000;
        sprite->scaleX = sprite->targetScaleX - (sprite->targetScaleX - sprite->startScaleX) * sprite->time / sprite->duration;
        sprite->scaleY = sprite->targetScaleY - (sprite->targetScaleY - sprite->startScaleY) * sprite->time / sprite->duration;
    } else {
        startX = sprite->startX;
        startY = sprite->startY;
        sprite->x = sprite->startX = sprite->targetX;
        sprite->y = sprite->startY = sprite->targetY;
        sprite->targetX = startX;
        sprite->targetY = startY;
        scaleX = sprite->targetScaleX;
        scaleY = sprite->targetScaleY;
        sprite->state = 2;
        sprite->targetScaleX = 0x1000;
        sprite->targetScaleY = 0x1000;
        sprite->scaleX = scaleX;
        sprite->scaleY = scaleY;
        sprite->unk48 &= ~5;
        sprite->time = sprite->duration = sprite->duration * 2 + sprite->duration / 2;
        sprite->startScaleX = sprite->scaleX;
        sprite->startScaleY = sprite->scaleY;
        done = 1;
    }
    return done;
}

/* Shakes a sprite sideways and stretches it, for 12 frames: 1 at the end */
s32 CARDGAME_shakeSprite(CardScreen *screen, CardSprite *sprite) {
    s32 done = 0;

    sprite->x = sprite->startX + CARDGAME_shakeOffsets[sprite->time & 7];
    sprite->scaleY = rsin((sprite->time << 12) / 24) / 16 + 0x1000;
    sprite->time += GFX.funcs.getFrameTime();
    if (sprite->time >= 12) {
        sprite->state = 1;
        sprite->moving = 0;
        sprite->effect = 0;
        sprite->scaleY = 0x1000;
        sprite->x = sprite->startX;
        done = 1;
    }
    return done;
}

/* Ends a sprite's move and puts it in STATE */
static inline void resetSprite(CardSprite *sprite, s32 state) {
    sprite->state = state;
    sprite->duration = 0;
    sprite->time = 0;
    sprite->moving = 0;
    sprite->effect = 0;
}

/* Holds a sprite for 10 frames, then starts its blink: 1 at the end */
s32 CARDGAME_holdSpriteThenBlink(CardScreen *screen, CardSprite *sprite) {
    s32 done = 0;

    sprite->time += GFX.funcs.getFrameTime();
    if (sprite->time >= 10) {
        resetSprite(sprite, 11);
        done = 1;
    }
    return done;
}

/* Holds a sprite for duration frames, then ends its effect: 1 at the end */
s32 CARDGAME_holdSprite(CardScreen *screen, CardSprite *sprite, s32 duration) {
    s32 done = 0;

    sprite->time += GFX.funcs.getFrameTime();
    if (sprite->time >= duration) {
        resetSprite(sprite, 1);
        done = 1;
    }
    return done;
}

/* Jitters a sprite about where it started and squashes it, for 12 frames: 1
   at the end */
s32 CARDGAME_jitterSprite(CardScreen *screen, CardSprite *sprite) {
    s32 done;

    sprite->x = sprite->startX + CARDGAME_jitterOffsets[sprite->time & 7];
    sprite->y = sprite->startY + CARDGAME_jitterOffsets[RANDOM.next() & 7];
    done = 0;
    sprite->scaleY = 0x1000 - rsin((sprite->time << 12) / 24) / 8;
    sprite->time += GFX.funcs.getFrameTime();
    if (sprite->time >= 12) {
        sprite->state = 1;
        sprite->moving = 0;
        sprite->scaleY = 0x1000;
        sprite->effect = 0;
        sprite->x = sprite->startX;
        sprite->y = sprite->startY;
        done = 1;
    }
    return done;
}

/* The end of a sprite's flip (CARDGAME_flipSprite) */
static inline void endSpriteFlip(CardSprite *sprite, s32 state) {
    sprite->state = state;
    sprite->moving = 0;
    sprite->scaleX = 0x1000;
}

/* Turns a sprite over for 12 frames, its side swapped after 7: 1 at the end */
s32 CARDGAME_flipSprite(CardScreen *screen, CardSprite *sprite) {
    s32 done = 0;

    sprite->scaleX = 0x1000 - rsin((sprite->time << 12) / 24);
    sprite->time += GFX.funcs.getFrameTime();
    if (sprite->duration == 0 && sprite->time >= 7) {
        sprite->duration = 1;
        sprite->visible ^= 3;
    }
    if (sprite->time >= 12) {
        endSpriteFlip(sprite, 1);
        done = 1;
    }
    return done;
}

/* Draws a card's picture: a one-part sprite sheet (CARDGAME_pictureSheet) made on the fly,
   the 32x32 cell `index` of an 8-row grid with the card's own CLUT row */
void CARDGAME_drawCardPicture(CardSprite *sprite) {
    SpriteDrawer drawer;
    s16 *frame;
    SpritePart *part;
    s32 u;
    s32 v;
    s32 *sheet;

    u = sprite->index / 8 * 32;
    v = sprite->index % 8 * 32;
    sheet = CARDGAME_pictureSheet;
    frame = (s16 *)((u8 *)sheet + sheet[2]);
    frame[0] = 1;
    frame[2] = -1;
    frame[1] = sprite->index;
    frame[3] = 0;
    frame[4] = 4;
    frame[5] = 2;
    part = (SpritePart *)((u8 *)sheet + sheet[0]);
    part->u = u;
    part->v = v;
    part->w = 32;
    part->h = 32;
    part->clutX = 0;
    part->clutY = 0x100;
    part->mode = 1;
    initSpriteDrawer(&drawer);
    if (*(s32 *)&sprite->scaleX != 0x10001000) {
        drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
        drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
    }
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x140, 0x100);
    drawer.setAltClut(0x300, 0x100);
    drawer.draw(sheet, 0, sprite->x >> 8, sprite->y >> 8);
}

/* Draws a sprite's effect animation (1-4, frames 0x28-0x4C of the fourth TIM) and ends it when its time runs out */
void CARDGAME_drawSpriteEffect(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;

    if (sprite->visible != 0 && sprite->effect != 0) {
        initSpriteDrawer(&drawer);
        /* both scales at 0x1000, read as one word */
        if (*(s32 *)&sprite->scaleX != 0x10001000) {
            drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
            drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x340, 0);
        switch (sprite->effect) {
        case 1:
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_loopFrames[(screen->time >> 2) & 3] + 0x28,
                        sprite->x >> 8, sprite->y >> 8);
            break;
        case 2:
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), CARDGAME_onceFrames[(sprite->unk34 >> 2) % 4] + 0x2C,
                        sprite->x >> 8, sprite->y >> 8);
            if (sprite->unk34 >= 8) {
                sprite->effect = 0;
                sprite->unk34 = 0;
            }
            sprite->unk34 += GFX.funcs.getFrameTime();
            break;
        case 3:
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), (sprite->unk34 >> 1) % 9 + 0x3C,
                        sprite->x >> 8, sprite->y >> 8);
            if (sprite->unk34++ >= 36) {
                sprite->effect = 0;
                sprite->unk34 = 0;
            }
            sprite->unk34 += GFX.funcs.getFrameTime();
            break;
        case 4:
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), (sprite->unk34 >> 1) % 7 + 0x46,
                        sprite->x >> 8, sprite->y >> 8);
            if (sprite->unk34 >= 28) {
                sprite->effect = 0;
                sprite->unk34 = 0;
            }
            sprite->unk34 += GFX.funcs.getFrameTime();
            break;
        }
    }
}

/* Draws the highlights over a sprite (unk48 bits 0-2), with a cycling palette */
void CARDGAME_drawSpriteHighlights(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;

    if (sprite->visible != 0) {
        if (sprite->unk48 & 6) {
            initSpriteDrawer(&drawer);
            if (sprite->unk48 & 4) {
                drawer.setClutRow(CARDGAME_highlightCluts[(screen->time >> 2) % 6] + 5);
            } else {
                drawer.setClutRow(4);
            }
            /* both scales at 0x1000, read as one word */
            if (*(s32 *)&sprite->scaleX != 0x10001000) {
                drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
                drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
            }
            drawer.setLayerId(0x100, 1);
            drawer.setTexture(0x340, 0);
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 8, sprite->x >> 8, sprite->y >> 8);
        }
        if (sprite->unk48 & 1) {
            initSpriteDrawer(&drawer);
            drawer.setClutRow(CARDGAME_highlightCluts[(screen->time >> 2) % 6]);
            /* both scales at 0x1000, read as one word */
            if (*(s32 *)&sprite->scaleX != 0x10001000) {
                drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
                drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
            }
            drawer.setLayerId(0x100, 1);
            drawer.setTexture(0x340, 0);
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 8, sprite->x >> 8, sprite->y >> 8);
        }
    }
}

/* Draws a sprite's order number (unk46), the place of its card in the record */
void CARDGAME_drawSpriteOrder(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;

    if (sprite->visible != 0 && sprite->unk46 != 0) {
        initSpriteDrawer(&drawer);
        /* both scales at 0x1000, read as one word */
        if (*(s32 *)&sprite->scaleX != 0x10001000) {
            drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
            drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), sprite->unk46 + 0x33, (sprite->x >> 8) + 3, (sprite->y >> 8) + 2);
    }
}

/* Draws a card's marks that are set (unk3E[0..2]: sprites 0x37 to 0x39), in a row 8 pixels apart */
void CARDGAME_drawSpriteMarks(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;
    s32 i;
    s32 n;

    if (sprite->visible != 0) {
        for (i = 0, n = 0; i < 3; i++) {
            if (sprite->unk3E[i] != 0) {
                initSpriteDrawer(&drawer);
                /* both scales at 0x1000, read as one word */
                if (*(s32 *)&sprite->scaleX != 0x10001000) {
                    drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
                    drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
                }
                drawer.setLayerId(0x100, 1);
                drawer.setTexture(0x280, 0);
                drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), i + 0x37, (sprite->x >> 8) + 3 + n * 8, (sprite->y >> 8) + 0x15);
                n++;
            }
        }
    }
}

/* Draws a card's two numbers (unk43 and unk44) and the sprite between them */
static inline void drawCardNumbers(CardSprite *sprite) {
    CardNumber number;
    SpriteDrawer drawer;

    number.depth = 1;
    number.digits = 2;
    number.leadingZeros = 0;
    number.x = (sprite->x >> 8) + 4;
    number.y = (sprite->y >> 8) + 0x21;
    number.value = sprite->unk43;
    number.pivotX = (sprite->x >> 8) + 0x14;
    number.pivotY = (sprite->y >> 8) + 0x17;
    number.scaleX = sprite->scaleX;
    number.scaleY = sprite->scaleY;
    CARDGAME_drawNumber(&number, 1);
    number.x = (sprite->x >> 8) + 0x17;
    number.y = (sprite->y >> 8) + 0x21;
    number.value = sprite->unk44;
    number.pivotX = (sprite->x >> 8) + 0x14;
    number.pivotY = (sprite->y >> 8) + 0x17;
    number.scaleX = sprite->scaleX;
    number.scaleY = sprite->scaleY;
    CARDGAME_drawNumber(&number, 1);
    initSpriteDrawer(&drawer);
    /* both scales at 0x1000, read as one word */
    if (*(s32 *)&sprite->scaleX != 0x10001000) {
        drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
        drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
    }
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x340, 0);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0x1F, (sprite->x >> 8) + 0x12, (sprite->y >> 8) + 0x21);
}

/* Draws the mark (sprite 0x1E) of a card that is not of kind 16 */
static inline void drawCardMark(CardSprite *sprite) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    /* both scales at 0x1000, read as one word */
    if (*(s32 *)&sprite->scaleX != 0x10001000) {
        drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
        drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
    }
    drawer.setLayerId(0x100, 1);
    drawer.setTexture(0x340, 0);
    drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 0x1E, (sprite->x >> 8) + 4, (sprite->y >> 8) + 0x21);
}

/* Draws a card sprite: its frame (visible 1, with the numbers or the mark and the image) or its back (visible 2 or 3) */
void CARDGAME_drawSpriteCard(CardScreen *screen, CardSprite *sprite) {
    /* the match depends on the early return together with the empty case 0 */
    if (sprite->visible == 0) {
        return;
    }
    switch (sprite->visible) {
    case 0:
        break;
    case 1:
        if (sprite->isKind16 != 0) {
            drawCardNumbers(sprite);
        } else {
            drawCardMark(sprite);
        }
        {
            SpriteDrawer drawer;

            initSpriteDrawer(&drawer);
            /* both scales at 0x1000, read as one word */
            if (*(s32 *)&sprite->scaleX != 0x10001000) {
                drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
                drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
            }
            drawer.setLayerId(0x100, 1);
            drawer.setTexture(0x280, 0);
            drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), sprite->dimmed == 1 ? sprite->color + 0x3C : sprite->color,
                        sprite->x >> 8, sprite->y >> 8);
        }
        CARDGAME_drawCardPicture(sprite);
        break;
    case 2: {
        SpriteDrawer drawer;

        initSpriteDrawer(&drawer);
        /* both scales at 0x1000, read as one word */
        if (*(s32 *)&sprite->scaleX != 0x10001000) {
            drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
            drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0x10, sprite->x >> 8, sprite->y >> 8);
        break;
    }
    case 3: {
        SpriteDrawer drawer;

        initSpriteDrawer(&drawer);
        /* both scales at 0x1000, read as one word */
        if (*(s32 *)&sprite->scaleX != 0x10001000) {
            drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
            drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x280, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 2), 0xC, sprite->x >> 8, sprite->y >> 8);
        break;
    }
    }
}

/* Draws the shade over a dimmed sprite */
void CARDGAME_drawSpriteDim(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;

    if (sprite->visible != 0 && sprite->dimmed != 0) {
        initSpriteDrawer(&drawer);
        /* both scales at 0x1000, read as one word */
        if (*(s32 *)&sprite->scaleX != 0x10001000) {
            drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
            drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        }
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x340, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 10, sprite->x >> 8, sprite->y >> 8);
    }
}

/* Draws a blinking sprite's flash (state 11), its CLUT row changing */
void CARDGAME_drawSpriteBlink(CardScreen *screen, CardSprite *sprite) {
    SpriteDrawer drawer;

    if (sprite->visible != 0 && sprite->state == 11) {
        initSpriteDrawer(&drawer);
        drawer.setClutRow((sprite->duration / 2) % 5);
        drawer.setPivot((sprite->x >> 8) + 0x14, (sprite->y >> 8) + 0x17);
        drawer.setScale(sprite->scaleX, sprite->scaleY, 0x1000);
        drawer.setLayerId(0x100, 1);
        drawer.setTexture(0x340, 0);
        drawer.draw(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16 | 3), 9, sprite->x >> 8, sprite->y >> 8);
    }
}

/* Runs a sprite's animation for its state; sets bit 0 of unk54 while one runs */
void CARDGAME_animateSprite(CardScreen *screen, CardScreenItems *items, CardSprite *sprite) {
    switch (sprite->state) {
    case 0:
        sprite->visible = 0;
        break;
    case 2:
    case 3:
        screen->unk54 |= 1;
        CARDGAME_moveSprite(screen, sprite);
        break;
    case 4:
        screen->unk54 |= 1;
        CARDGAME_flipSprite(screen, sprite);
        break;
    case 5:
        screen->unk54 |= 1;
        if (CARDGAME_flySprite(screen, sprite) != 0) {
            screen->unk54 |= 2;
        }
        break;
    case 6:
        screen->unk54 |= 1;
        CARDGAME_jitterSprite(screen, sprite);
        break;
    case 7:
        screen->unk54 |= 1;
        CARDGAME_shakeSprite(screen, sprite);
        break;
    case 8:
        screen->unk54 |= 1;
        CARDGAME_holdSpriteThenBlink(screen, sprite);
        break;
    case 11:
        screen->unk54 |= 1;
        sprite->duration += GFX.funcs.getFrameTime();
        if (sprite->duration >= 11) {
            sprite->state = 1;
        }
        break;
    case 9:
        CARDGAME_holdSprite(screen, sprite, 36);
        screen->unk54 |= 1;
        break;
    case 10:
        CARDGAME_holdSprite(screen, sprite, 28);
        screen->unk54 |= 1;
        break;
    case 1:
        break;
    }
}

/* Draws a sprite and its marks, unless it is scaled to nothing */
void CARDGAME_drawSprite(CardScreen *screen, CardSprite *sprite) {
    if (sprite->scaleX != 0 && sprite->scaleY != 0) {
        CARDGAME_drawSpriteHighlights(screen, sprite);
        CARDGAME_drawSpriteMarks(screen, sprite);
        CARDGAME_drawSpriteOrder(screen, sprite);
        CARDGAME_drawSpriteEffect(screen, sprite);
        CARDGAME_drawSpriteDim(screen, sprite);
        CARDGAME_drawSpriteCard(screen, sprite);
    }
}

/* Animates the sprites, then draws them: the moving ones first */
void CARDGAME_updateSprites(CardScreen *screen, CardScreenItems *items) {
    s32 i;
    s32 pass;

    for (i = 39; i >= 0; i--) {
        CARDGAME_animateSprite(screen, items, &screen->sprites[i]);
        CARDGAME_drawSpriteBlink(screen, &screen->sprites[i]);
    }
    for (pass = 0; pass < 2; pass++) {
        for (i = 39; i >= 0; i--) {
            if ((pass == 0 && screen->sprites[i].moving != 0) || (pass != 0 && screen->sprites[i].moving == 0)) {
                CARDGAME_drawSprite(screen, &screen->sprites[i]);
            }
        }
    }
}

void CARDGAME_updateScreen(CardScreen *screen, CardScreenItems *items) {
    switch (screen->state) {
    case 0:
    default:
        screen->nextState(screen);
        items->cursor = createCursor(0x100, 0, 0, 0);
        items->cursor->setVisible(items->cursor, 0);
        items->texts[0] = createTextWindow(0x100, 1, 0, 0);
        items->texts[1] = createTextWindow(0x100, 1, 0, 0);
        items->texts[2] = createTextWindow(0x100, 1, 0, 0);
        items->panelTexts[0] = createTextWindow(0x100, 1, 0, 0);
        items->panelTexts[1] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[0] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[1] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[1]->setLines(items->moreTexts[1], 3);
        items->moreTexts[2] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[3] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[4] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[5] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[5]->setLines(items->moreTexts[5], 3);
        items->moreTexts[6] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[6]->setLines(items->moreTexts[6], 5);
        items->moreTexts[7] = createTextWindow(0x100, 1, 0, 0);
        items->moreTexts[7]->setLines(items->moreTexts[7], 2);
        break;
    case 1:
        screen->time += GFX.funcs.getFrameTime();
        screen->unk54 = 0;
        CARDGAME_updateBlinkers(screen, items);
        CARDGAME_updateMenuWindow(screen, items);
        CARDGAME_updateMessageWindow(screen, items);
        CARDGAME_updateWindows(screen, items);
        CARDGAME_updateSprites(screen, items);
        CARDGAME_updateGauges(screen, items);
        CARDGAME_drawBackground(screen);
        CARDGAME_updatePanels(screen, items);
        break;
    case 3:
        break;
    }
}

/* Opens gauge index showing value, over 10 frames */
void CARDGAME_openGauge(CardScreen *screen, s32 index, s16 value) {
    screen->gauges[index].from = 0x1000;
    screen->gauges[index].state = 1;
    screen->gauges[index].to = 0;
    screen->gauges[index].value = value;
    screen->gauges[index].duration = 10;
    screen->gauges[index].time = 10;
}

/* Closes gauge index, over 5 frames */
void CARDGAME_closeGauge(CardScreen *screen, s32 index) {
    screen->gauges[index].from = 0x1000;
    screen->gauges[index].to = 0x1000;
    screen->gauges[index].state = 3;
    screen->gauges[index].duration = 5;
    screen->gauges[index].time = 5;
}

/* Opens window index (CardScreen.windows) at x, y, with its unkC and unk10 */
void CARDGAME_openWindow(CardScreen *screen, s32 index, s16 arg2, s32 arg3, s32 x, s32 y) {
    SOUND.playSound(SOUND_MENU_OPEN);
    screen->windows[index].x = x;
    screen->windows[index].y = y;
    screen->windows[index].from = 0;
    screen->windows[index].to = 0x1000;
    screen->windows[index].state = 1;
    screen->windows[index].unkC = arg2;
    screen->windows[index].unk10 = arg3;
    screen->windows[index].duration = 12;
    screen->windows[index].time = 12;
}

/* Closes window index */
void CARDGAME_closeWindow(CardScreen *screen, s32 index) {
    SOUND.playSound(SOUND_MENU_CLOSE);
    screen->windows[index].from = 0x1000;
    screen->windows[index].to = 0x1000;
    screen->windows[index].state = 3;
    screen->windows[index].duration = 6;
    screen->windows[index].time = 6;
}

/* Shows blinker index, still, at x, y. Nothing calls this method or
   CARDGAME_startBlinkerMove. */
s32 CARDGAME_showBlinker(CardScreen *screen, s32 index, s16 x, s16 y) {
    screen->blinkers[index].state = 1;
    screen->blinkers[index].x = x;
    screen->blinkers[index].y = y;
    screen->blinkers[index].targetY = 0;
    screen->blinkers[index].targetX = 0;
    screen->blinkers[index].startY = 0;
    screen->blinkers[index].startX = 0;
    screen->blinkers[index].duration = 0;
    screen->blinkers[index].time = 0;
    screen->blinkers[index].blinkTime = 0;
    return 0;
}

/* Starts moving blinker index to x, y over duration frames */
s32 CARDGAME_startBlinkerMove(CardScreen *screen, s32 index, u8 duration, s16 x, s32 y) {
    screen->blinkers[index].state = 2;
    screen->blinkers[index].targetX = x;
    screen->blinkers[index].duration = duration;
    screen->blinkers[index].time = duration;
    screen->blinkers[index].targetY = y;
    screen->blinkers[index].startX = screen->blinkers[index].x;
    screen->blinkers[index].startY = screen->blinkers[index].y;
    return 0;
}

/* Opens the message window at place with message, asking prompt with the
   cursor on choice */
void CARDGAME_openMessage(CardScreen *screen, s32 message, s32 prompt, s16 choice, s32 place) {
    SOUND.playSound(SOUND_MENU_OPEN);
    screen->message.duration = 12;
    screen->message.time = 12;
    screen->message.choice = choice;
    screen->message.message = message;
    screen->message.prompt = prompt;
    screen->message.place = place;
    screen->message.state = 1;
}

/* Closes the message window */
void CARDGAME_closeMessage(CardScreen *screen) {
    SOUND.playSound(SOUND_MENU_CLOSE);
    screen->message.duration = 6;
    screen->message.time = 6;
    screen->message.state = 5;
}

/* Confirms the message window's choice: the cursor nudges, then it closes */
void CARDGAME_confirmMessage(CardScreen *screen) {
    SOUND.playSound(SOUND_SELECT);
    screen->message.duration = 10;
    screen->message.time = 10;
    screen->message.state = 4;
}

/* Puts the message window's cursor on choice */
void CARDGAME_setMessageChoice(CardScreen *screen, s32 choice) {
    screen->message.choice = choice;
}

/* Opens the menu window with the cursor on row */
void CARDGAME_openMenuWindow(CardScreen *screen, s16 row) {
    SOUND.playSound(SOUND_MENU_OPEN);
    screen->menuDuration = 12;
    screen->menuTime = 12;
    screen->menuRow = row;
    screen->menuState = 1;
}

/* Closes the menu window */
void CARDGAME_closeMenuWindow(CardScreen *screen) {
    SOUND.playSound(SOUND_MENU_CLOSE);
    screen->menuDuration = 6;
    screen->menuTime = 6;
    screen->menuState = 5;
}

/* Confirms the menu window's row: the cursor nudges, then it closes */
void CARDGAME_confirmMenuWindow(CardScreen *screen) {
    SOUND.playSound(SOUND_SELECT);
    screen->menuDuration = 10;
    screen->menuTime = 10;
    screen->menuState = 4;
}

/* Puts the menu window's cursor on row */
void CARDGAME_setMenuWindowRow(CardScreen *screen, s16 row) {
    screen->menuRow = row;
}

/* Puts both panels away at once */
void CARDGAME_resetPanels(CardScreen *screen) {
    screen->panels[0].state = 0;
    screen->panels[0].duration = 0;
    screen->panels[0].time = 0;
    screen->panels[0].x = 0;
    screen->panels[0].y = 0xF1;
    screen->panels[0].unk20 = 0x147;
    screen->panels[0].unk22 = 0x8F;
    screen->panels[0].unk3C = 0x140;
    screen->panels[0].unk3E = 0xBD;
    screen->panels[1].state = 0;
    screen->panels[1].duration = 0;
    screen->panels[1].time = 0;
    screen->panels[1].x = 0;
    screen->panels[1].y = -100;
    screen->panels[1].unk20 = 0x147;
    screen->panels[1].unk22 = 0x50;
    screen->panels[1].unk3C = 0x140;
    screen->panels[1].unk3E = 0x26;
}

/* Slides both panels in, over 20 frames */
void CARDGAME_openPanels(CardScreen *screen) {
    screen->panels[0].state = 1;
    screen->panels[0].unk6 = 2;
    screen->panels[0].duration = 20;
    screen->panels[0].time = 20;
    screen->panels[0].x = 0;
    screen->panels[0].y = 0xF1;
    screen->panels[0].unk20 = 0x147;
    screen->panels[0].unk22 = 0x8F;
    screen->panels[0].unk3C = 0x140;
    screen->panels[0].unk3E = 0xBD;
    screen->panels[1].state = 1;
    screen->panels[1].duration = 20;
    screen->panels[1].time = 20;
    screen->panels[1].x = 0;
    screen->panels[1].y = -100;
    screen->panels[1].unk20 = 0xF9;
    screen->panels[1].unk22 = 0x50;
    screen->panels[1].unk3C = 0x140;
    screen->panels[1].unk3E = 0x26;
}

/* Slides both panels out, over 10 frames */
void CARDGAME_closePanels(CardScreen *screen) {
    screen->panels[0].state = 3;
    screen->panels[0].duration = 10;
    screen->panels[0].time = 10;
    screen->panels[0].x = 0;
    screen->panels[0].y = 0x8D;
    screen->panels[0].unk20 = 0x120;
    screen->panels[0].unk22 = 0x8F;
    screen->panels[0].unk3C = 0x113;
    screen->panels[0].unk3E = 0xBD;
    screen->panels[1].state = 3;
    screen->panels[1].duration = 10;
    screen->panels[1].time = 10;
    screen->panels[1].x = 0;
    screen->panels[1].y = 0;
    screen->panels[1].unk20 = 0x120;
    screen->panels[1].unk22 = 0x50;
    screen->panels[1].unk3C = 0x113;
    screen->panels[1].unk3E = 0x26;
}

/* Slides side's panel in over 10 frames, stopping the other's */
void CARDGAME_openPanel(CardScreen *screen, s32 side) {
    screen->panels[side].state = 4;
    screen->panels[side ^ 1].state = 0;
    screen->panels[side].unk6 = 2;
    screen->panels[side].duration = 10;
    screen->panels[side].time = 10;
    if (side == 0) {
        screen->panels[0].x = 0;
        screen->panels[0].y = 0xF1;
    } else {
        screen->panels[side].x = 0;
        screen->panels[side].y = -100;
    }
}

/* Slides side's panel out over 5 frames, stopping the other's */
void CARDGAME_closePanel(CardScreen *screen, s32 side) {
    screen->panels[side].state = 5;
    screen->panels[side ^ 1].state = 0;
    screen->panels[side].duration = 5;
    screen->panels[side].time = 5;
    if (side == 0) {
        screen->panels[0].x = 0;
        screen->panels[0].y = 0x8D;
    } else {
        screen->panels[side].x = 0;
        screen->panels[side].y = 0;
    }
}

/* Grows side's panel icon over 12 frames */
void CARDGAME_openPanelIcon(CardScreen *screen, s32 side) {
    screen->panels[side].scale.state = 1;
    screen->panels[side].scale.duration = 12;
    screen->panels[side].scale.time = 12;
    screen->panels[side].scale.value = 0;
}

/* Shrinks side's panel icon over 6 frames */
void CARDGAME_closePanelIcon(CardScreen *screen, s32 side) {
    screen->panels[side].scale.state = 3;
    screen->panels[side].scale.duration = 6;
    screen->panels[side].scale.time = 6;
    screen->panels[side].scale.value = 0x1000;
}

s32 CARDGAME_addSprite(CardScreen *screen, s32 index, s32 x, s32 y) {
    HEAP.zero(&screen->sprites[index], sizeof(CardSprite));
    screen->sprites[index].visible = 1;
    screen->sprites[index].state = 1;
    screen->sprites[index].x = x;
    screen->sprites[index].y = y;
    screen->sprites[index].targetScaleX = 0x1000;
    screen->sprites[index].scaleX = 0x1000;
    screen->sprites[index].targetScaleY = 0x1000;
    screen->sprites[index].scaleY = 0x1000;
    screen->sprites[index].index = 0;
    screen->sprites[index].color = 0;
    screen->sprites[index].slot = index;
    screen->sprites[index].unk43 = 0;
    screen->sprites[index].unk44 = 0;
    screen->sprites[index].effect = 0;
    screen->sprites[index].dimmed = 0;
    screen->sprites[index].moving = 0;
    return 0;
}

/* Starts turning a sprite over (state 4, CARDGAME_flipSprite) */
s32 CARDGAME_startSpriteFlip(CardScreen *screen, s32 index) {
    SOUND.playSound(0x8004613E);
    screen->sprites[index].state = 4;
    screen->sprites[index].time = 0;
    screen->sprites[index].duration = 0;
    screen->sprites[index].scaleX = 0x1000;
    screen->sprites[index].scaleY = 0x1000;
    screen->sprites[index].moving = 0;
    return 0;
}

/* Starts a sprite's jitter (state 6, CARDGAME_jitterSprite), with effect 1 */
s32 CARDGAME_startSpriteJitter(CardScreen *screen, s32 index) {
    SOUND.playSound(0x9C0003);
    screen->sprites[index].state = 6;
    screen->sprites[index].scaleX = 0x1000;
    screen->sprites[index].scaleY = 0x1000;
    screen->sprites[index].time = 0;
    screen->sprites[index].duration = 0;
    screen->sprites[index].effect = 1;
    screen->sprites[index].moving = 0;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
    return 0;
}

/* Starts a sprite's shake (state 7, CARDGAME_shakeSprite), with effect 1 */
s32 CARDGAME_startSpriteShake(CardScreen *screen, s32 index) {
    SOUND.playSound(0x9C0003);
    screen->sprites[index].state = 7;
    screen->sprites[index].time = 0;
    screen->sprites[index].duration = 0;
    screen->sprites[index].effect = 1;
    screen->sprites[index].moving = 0;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
    return 0;
}

/* Starts a sprite's effect 2 with the recovery sound (state 8), and then its
   blink */
s32 CARDGAME_startSpriteRecovery(CardScreen *screen, s32 index) {
    SOUND.playSound(SOUND_RECOVERY);
    screen->sprites[index].state = 8;
    screen->sprites[index].time = 0;
    screen->sprites[index].duration = 0;
    screen->sprites[index].effect = 2;
    screen->sprites[index].moving = 0;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
    return 0;
}

/* Starts a sprite's effect 3 (which 0) for 36 frames, or 4 for 28 */
s32 CARDGAME_startSpriteEffect(CardScreen *screen, s32 index, s32 which) {
    switch (which) {
    case 0:
    default:
        screen->sprites[index].state = 9;
        screen->sprites[index].effect = 3;
        break;
    case 1:
        screen->sprites[index].effect = 4;
        screen->sprites[index].state = 10;
        break;
    }
    screen->sprites[index].time = 0;
    screen->sprites[index].duration = 0;
    screen->sprites[index].moving = 0;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
    return 0;
}

s32 CARDGAME_setSpriteScaleTarget(CardScreen *screen, s32 index, s32 duration, s32 scaleX, s32 scaleY, s32 instant) {
    screen->sprites[index].targetScaleX = scaleX;
    screen->sprites[index].targetScaleY = scaleY;
    screen->sprites[index].startScaleX = screen->sprites[index].scaleX;
    screen->sprites[index].startScaleY = screen->sprites[index].scaleY;
    if (instant != 1) {
        screen->sprites[index].duration = duration;
        screen->sprites[index].time = duration;
        screen->sprites[index].state = 2;
        screen->sprites[index].moving = 1;
        screen->sprites[index].targetX = screen->sprites[index].x;
        screen->sprites[index].targetY = screen->sprites[index].y;
    }
    return 0;
}

void CARDGAME_setSpriteScale(CardScreen *screen, s32 index, s32 scaleX, s32 scaleY) {
    CARDGAME_setSpriteScaleTarget(screen, index, 0, scaleX, scaleY, 1);
}

void CARDGAME_scaleSprite(CardScreen *screen, s32 index, s32 duration, s32 scaleX, s32 scaleY) {
    CARDGAME_setSpriteScaleTarget(screen, index, duration, scaleX, scaleY, 0);
}

void CARDGAME_setSpriteMove(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y) {
    screen->sprites[index].targetX = x;
    screen->sprites[index].duration = duration;
    screen->sprites[index].time = duration;
    screen->sprites[index].targetY = y;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
}

/* Starts moving a sprite to x, y over duration (state 2), with a sound at
   the start and the end */
void CARDGAME_startSpriteMove(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y) {
    SOUND.playSound(0x8004603C);
    screen->sprites[index].state = 2;
    CARDGAME_setSpriteMove(screen, index, duration, x, y);
}

/* Starts moving a sprite to x, y over duration without sounds (state 3) */
void CARDGAME_startSpriteSlide(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y) {
    screen->sprites[index].state = 3;
    CARDGAME_setSpriteMove(screen, index, duration, x, y);
}

/* Starts a sprite's flight to x, y and back (state 5, CARDGAME_flySprite),
   after it grows for 16 frames */
s32 CARDGAME_startSpriteFly(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y) {
    screen->sprites[index].state = 5;
    screen->sprites[index].unk30 = 16;
    screen->sprites[index].scaleX = 0x1000;
    screen->sprites[index].scaleY = 0x1000;
    screen->sprites[index].targetX = x;
    screen->sprites[index].duration = duration;
    screen->sprites[index].time = duration;
    screen->sprites[index].targetY = y;
    screen->sprites[index].startX = screen->sprites[index].x;
    screen->sprites[index].startY = screen->sprites[index].y;
    return 0;
}

void CARDGAME_setPanelValue(CardScreen *screen, s32 side, u32 which, s32 value) {
    switch (which) {
    case 0:
        screen->panels[side].unk18[0] = value;
        break;
    case 1:
        screen->panels[side].unk18[1] = value;
        break;
    case 2:
        screen->panels[side].unk18[2] = value;
        break;
    case 3:
        screen->panels[side].unk18[3] = value;
        break;
    case 4:
        screen->panels[side].unk18[4] = value;
        break;
    case 5:
        screen->panels[side].unk18[5] = value;
        break;
    case 6:
        screen->panels[side].unk18[6] = value;
        break;
    case 7:
        screen->panels[side].unk28 = value;
        break;
    case 8:
        screen->panels[side].unk10 = value;
        break;
    case 9:
        screen->panels[side].unk12 = value;
        break;
    }
}

void CARDGAME_setPanelFlags(CardScreen *screen, s32 bits) {
    if (bits & 1) {
        screen->panels[0].flags[0] = 1;
    }
    if (bits & 4) {
        screen->panels[0].flags[1] = 1;
    }
    if (bits & 0x10) {
        screen->panels[0].flags[2] = 1;
    }
    if (bits & 0x40) {
        screen->panels[0].flags[3] = 1;
    }
    if (bits & 0x100) {
        screen->panels[0].flags[4] = 1;
    }
    if (bits & 0x400) {
        screen->panels[0].flags[5] = 1;
    }
    if (bits & 0x1000) {
        screen->panels[0].flags[6] = 1;
    }
    if (bits & 0x4000) {
        screen->panels[0].flags[7] = 1;
    }
    if (bits & 0x10000) {
        screen->panels[0].flags[8] = 1;
    }
    if (bits & 0x40000) {
        screen->panels[0].flags[9] = 1;
    }
    if (bits & 2) {
        screen->panels[1].flags[0] = 1;
    }
    if (bits & 8) {
        screen->panels[1].flags[1] = 1;
    }
    if (bits & 0x20) {
        screen->panels[1].flags[2] = 1;
    }
    if (bits & 0x80) {
        screen->panels[1].flags[3] = 1;
    }
    if (bits & 0x200) {
        screen->panels[1].flags[4] = 1;
    }
    if (bits & 0x800) {
        screen->panels[1].flags[5] = 1;
    }
    if (bits & 0x2000) {
        screen->panels[1].flags[6] = 1;
    }
    if (bits & 0x8000) {
        screen->panels[1].flags[7] = 1;
    }
    if (bits & 0x20000) {
        screen->panels[1].flags[8] = 1;
    }
    if (bits & 0x80000) {
        screen->panels[1].flags[9] = 1;
    }
}

void CARDGAME_clearPanelFlags(CardScreen *screen) {
    HEAP.zero(screen->panels[0].flags, sizeof(screen->panels[0].flags));
    HEAP.zero(screen->panels[1].flags, sizeof(screen->panels[1].flags));
}

s32 CARDGAME_removeSprite(CardScreen *screen, s32 index) {
    screen->sprites[index].state = 0;
    screen->sprites[index].visible = 0;
    screen->sprites[index].index = 0;
    return 0;
}

/* Starts a sprite's blink (state 11), with the confirm sound */
s32 CARDGAME_startSpriteBlink(CardScreen *screen, s32 index) {
    SOUND.playSound(SOUND_MENU_CONFIRM);
    screen->sprites[index].state = 11;
    screen->sprites[index].duration = 0;
    screen->sprites[index].time = 0;
    return 0;
}

void CARDGAME_dealSprites(CardScreen *screen, s16 duration, s16 count, s32 x, s32 y) {
    s32 i;
    s32 sx;

    for (i = 0; i < count; i++) {
        sx = x + CARDGAME_getHandOffset(count, i);
        if (duration == 0) {
            CARDGAME_addSprite(screen, i, sx, y);
        } else {
            CARDGAME_startSpriteMove(screen, i, duration, sx, y);
        }
    }
}

s32 CARDGAME_getCardColor(CardScreen *screen, s32 index) {
    CardDrawer drawer;

    initCardDrawer(&drawer);
    drawer.setCard(screen->cards[index] + 1);
    return drawer.card->color;
}

void CARDGAME_setSpriteCard(CardScreen *screen, s32 sprite, s32 index) {
    CardDrawer drawer;

    initCardDrawer(&drawer);
    drawer.setCard(screen->cards[index] + 1);
    screen->sprites[sprite].index = index;
    screen->sprites[sprite].unk43 = drawer.card->ap;
    screen->sprites[sprite].unk44 = drawer.card->hp;
    screen->sprites[sprite].unk41 = drawer.card->points;
    screen->sprites[sprite].color = drawer.card->color - 1;
    if (drawer.card->kind == 0x10) {
        screen->sprites[sprite].isKind16 = 1;
    } else {
        screen->sprites[sprite].isKind16 = 0;
    }
}

void CARDGAME_loadCardImage(TimLoader *loader, u8 *image, s32 slot) {
    loader->setImagePos(0x140 + slot / 8 * 16, 0x100 + slot % 8 * 32);
    loader->setClutPos(0x300, 0x100 + slot);
    loader->load(image);
}

/* Card index of CARDGAME_otherCards */
s32 CARDGAME_getOtherCard(s32 index) {
    return CARDGAME_otherCards[index];
}

s32 CARDGAME_loadCardImages(s16 *dst, s16 *player, s16 *opponent) {
    TimLoader loader;
    CardDrawer drawer;
    s32 i;
    s32 count = 0;

    initCardDrawer(&drawer);
    initTimLoader(&loader);
    for (i = 0; i < 40; i++) {
        count++;
        drawer.setCard(player[i] + 1);
        CARDGAME_loadCardImage(&loader, drawer.card->tim, i);
        dst[i] = player[i];
    }
    for (i = 0; i < 40; i++) {
        count++;
        drawer.setCard(opponent[i] + 1);
        CARDGAME_loadCardImage(&loader, drawer.card->tim, i + 40);
        dst[i + 40] = opponent[i];
    }
    for (i = 0; i < 9; i++) {
        count++;
        drawer.setCard(CARDGAME_commonCards[i] + 1);
        CARDGAME_loadCardImage(&loader, drawer.card->tim, i + 80);
        dst[i + 80] = CARDGAME_commonCards[i];
    }
    for (i = 0; i < 100; i++) {
        drawer.setCard(CARDGAME_getOtherCard(i) + 1);
        count++;
        CARDGAME_loadCardImage(&loader, drawer.card->tim, i + 89);
        dst[i + 89] = CARDGAME_getOtherCard(i);
    }
    return count;
}

CardScreen *CARDGAME_createScreen(s16 *cards) {
    CardScreen *screen = createTask(CARDGAME_updateScreen, sizeof(CardScreen), 14 * 4);

    screen->setPanelValue = CARDGAME_setPanelValue;
    screen->openGauge = CARDGAME_openGauge;
    screen->closeGauge = CARDGAME_closeGauge;
    screen->openWindow = CARDGAME_openWindow;
    screen->closeWindow = CARDGAME_closeWindow;
    screen->setPanelFlags = CARDGAME_setPanelFlags;
    screen->clearPanelFlags = CARDGAME_clearPanelFlags;
    screen->openMessage = CARDGAME_openMessage;
    screen->closeMessage = CARDGAME_closeMessage;
    screen->setMessageChoice = CARDGAME_setMessageChoice;
    screen->confirmMessage = CARDGAME_confirmMessage;
    screen->openMenu = CARDGAME_openMenuWindow;
    screen->closeMenu = CARDGAME_closeMenuWindow;
    screen->confirmMenu = CARDGAME_confirmMenuWindow;
    screen->setMenuRow = CARDGAME_setMenuWindowRow;
    screen->getHandOffset = CARDGAME_getHandOffset;
    screen->showBlinker = CARDGAME_showBlinker;
    screen->startBlinkerMove = CARDGAME_startBlinkerMove;
    screen->startMove = CARDGAME_startSpriteMove;
    screen->startSlide = CARDGAME_startSpriteSlide;
    screen->startFly = CARDGAME_startSpriteFly;
    screen->startJitter = CARDGAME_startSpriteJitter;
    screen->startShake = CARDGAME_startSpriteShake;
    screen->startRecovery = CARDGAME_startSpriteRecovery;
    screen->startEffect = CARDGAME_startSpriteEffect;
    screen->startFlip = CARDGAME_startSpriteFlip;
    screen->addSprite = CARDGAME_addSprite;
    screen->removeSprite = CARDGAME_removeSprite;
    screen->startBlink = CARDGAME_startSpriteBlink;
    screen->setSpriteScale = CARDGAME_setSpriteScale;
    screen->scaleSprite = CARDGAME_scaleSprite;
    screen->dealSprites = CARDGAME_dealSprites;
    screen->cards = cards;
    screen->closePanels = CARDGAME_closePanels;
    screen->openPanels = CARDGAME_openPanels;
    screen->closePanel = CARDGAME_closePanel;
    screen->openPanelIcon = CARDGAME_openPanelIcon;
    screen->closePanelIcon = CARDGAME_closePanelIcon;
    screen->openPanel = CARDGAME_openPanel;
    screen->resetPanels = CARDGAME_resetPanels;
    screen->setSpriteCard = CARDGAME_setSpriteCard;
    screen->getCardColor = CARDGAME_getCardColor;
    screen->loadCardImages = CARDGAME_loadCardImages;
    return screen;
}

/* Requests the files of CARDGAME_preloadFiles one after the other, and ends after the
   last */
void CARDGAME_tickPreloader(CardPreloader *task) {
    switch (task->state) {
    case 0:
    default:
        task->index = 0;
        task->setState(task, 1);
        task->ready = 0;
        break;
    case 1:
        switch (task->substate) {
        case 0:
        default:
            task->file = CARDGAME_preloadFiles[task->index].file;
            if (CARDGAME_preloadFiles[task->index].isText != 0) {
                task->file += TEXT_FILE(1);
            }
            FILE_CACHE.request(task->file);
            task->substate++;
        case 1:
            break;
        }
        if (FILE_CACHE.isLoading(task->file) == 0) {
            if (CARDGAME_preloadFiles[++task->index].file == -2) {
                task->index++;
                task->ready = 1;
            }
            if (CARDGAME_preloadFiles[task->index].file == -1) {
                task->setState(task, 3);
            }
            task->substate = 0;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

CardPreloader *CARDGAME_startPreloader(void) {
    return createTask(CARDGAME_tickPreloader, sizeof(CardPreloader), 0);
}

/* Loads the opponent's data (FILE_CARDGAME_OPPONENTS, entry arg - 1): its deck and its card order */
void CARDGAME_loadOpponent(CardBattle *battle, CardBattleItems *items) {
    CardOpponent *opponent;
    s32 i;

    battle->opponents = (CardOpponent *)FILE_CACHE.load(FILE_CARDGAME_OPPONENTS);
    opponent = &battle->opponents[battle->arg - 1];
    battle->unk2E9 = opponent->unkC8;
    battle->prize = CARDGAME_prizeItems[opponent->unkCC];
    for (i = 0; i < 40; i++) {
        battle->unk30A[i].unk0 = i;
        battle->unk30A[i].unk1 = opponent->cards[i].unk2;
        battle->unk35C[i].unk0 = opponent->cards[i].unk3;
        battle->unk35C[i].unk1 = (opponent->cards[i].card & 0x8000) != 0;
        switch (battle->unk35C[i].unk0) {
        case 1:
            battle->unk35C[i].unk2 = i + 400;
            break;
        case 2:
            battle->unk35C[i].unk2 = i + 300;
            break;
        case 3:
            battle->unk35C[i].unk2 = i + 500;
            break;
        case 4:
            battle->unk35C[i].unk2 = i + 200;
            break;
        case 5:
            battle->unk35C[i].unk2 = i + 600;
            break;
        case 6:
            battle->unk35C[i].unk2 = i + 100;
            break;
        case 7:
            battle->unk35C[i].unk2 = i + 700;
            break;
        }
    }
    for (i = 0; i < 27; i++) {
        if (opponent->unkA0[i] == 0) {
            battle->unk400[i] = 7;
            battle->unk400[i + 1] = 8;
            battle->unk400[i + 2] = 24;
            battle->unk400[i + 3] = 31;
            battle->unk400[i + 4] = 32;
            battle->unk400[i + 5] = 0;
            battle->unk400[i + 6] = 6;
            battle->unk400[i + 7] = 12;
            battle->unk400[i + 8] = 18;
            battle->unk400[i + 9] = 27;
            battle->unk400[i + 10] = 30;
            battle->unk400[i + 11] = 33;
            battle->unk400[i + 12] = 37;
            battle->unk400[i + 13] = 38;
            battle->unk400[i + 14] = 0xFF;
            break;
        }
        battle->unk400[i] = opponent->unkA0[i] - 1;
    }
    for (i = 0; i < 40; i++) {
        battle->opponentDeck[i] = (opponent->cards[i].card & 0xFFF) - 1;
    }
}

/* Sorts the opponent's hand by its cards' unk35C kind, then value */
void CARDGAME_sortOpponentHand(CardBattle *battle) {
    s32 i;
    s32 j;
    s32 swap;
    s32 tmp;
    s32 ka;
    s32 kb;
    s32 va;
    s32 vb;

    for (i = 0; i < battle->sides[1].pile.handCount - 1; i++) {
        swap = 0;
        for (j = i + 1; j < battle->sides[1].pile.handCount; j++, swap = 0) {
            ka = battle->unk35C[battle->sides[1].pile.hand[i] - 40].unk0;
            kb = battle->unk35C[battle->sides[1].pile.hand[j] - 40].unk0;
            va = battle->unk35C[battle->sides[1].pile.hand[i] - 40].unk2;
            vb = battle->unk35C[battle->sides[1].pile.hand[j] - 40].unk2;
            if (kb < ka || (ka == kb && vb < va)) {
                swap = 1;
            }
            if (swap) {
                tmp = battle->sides[1].pile.hand[i];
                battle->sides[1].pile.hand[i] = battle->sides[1].pile.hand[j];
                battle->sides[1].pile.hand[j] = tmp;
            }
        }
    }
}

/* unk41B: the first card of the opponent's deck above the round's level
   (unk300); unk41C: the end of its deck before the cards of kind 7 */
void CARDGAME_findOpponentDeckLimits(CardBattle *battle, CardBattleItems *items) {
    s32 i;

    for (i = battle->sides[1].pile.deckTop; i < 40; i++) {
        if (battle->unk300 * 2 + 2 < battle->unk30A[i].unk1) {
            break;
        }
    }
    battle->unk41B = i;
    for (i = 40; i > 0; i--) {
        if (battle->unk30A[i - 1].unk1 != 7) {
            break;
        }
    }
    battle->unk41C = i;
}

/* Puts side 1's hand (unk64) back on its pile and renumbers the pile's cards */
void CARDGAME_returnOpponentHand(CardBattle *battle, CardBattleItems *items) {
    CardPile *pile = &battle->sides[1].pile;
    s32 start = pile->deckTop;
    s32 i;
    s32 j;
    s16 card;

    while (pile->handCount > 0) {
        pile->deck[--pile->deckTop] = pile->hand[--pile->handCount];
        pile->deckCount++;
    }
    if (start != pile->deckTop) {
        for (i = pile->deckTop; i < start; i++) {
            battle->unk30A[i].unk1 = battle->unk300 * 2 + 1;
        }
    }
    for (i = 0; i < 40; i++) {
        j = pile->deckTop;
        if (battle->unk30A[j].unk1 > battle->unk300 * 2 + 2) {
            break;
        }
        card = pile->deck[j];
        while (j < battle->unk41C - 1) {
            pile->deck[j] = pile->deck[j + 1];
            battle->unk30A[j].unk1 = battle->unk30A[j + 1].unk1;
            j++;
        }
        pile->deck[battle->unk41C - 1] = card;
        battle->unk30A[battle->unk41C - 1].unk1 = 7;
    }
    for (i = 39; i >= 0; i--) {
        battle->unk30A[i].unk0 = i;
    }
}

/* Lays out the cards of one of a side's piles (which: 0 the hand, unk64; 1 unk78; 2 unk14 from unk4) as sprites in a row */
void CARDGAME_layOutPile(CardBattle *battle, CardBattleItems *items, s32 side, s32 which) {
    CardScreen *screen = items->screen;
    CardBattle498 *p = &battle->unk498;
    s32 i;

    switch (which) {
    case 0:
        p->unk3C = battle->sides[side].pile.handCount;
        break;
    case 1:
        p->unk3C = battle->sides[side].pile.discardCount;
        break;
    case 2:
        p->unk3C = battle->sides[side].pile.deckCount;
        break;
    }
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
    p->unk40 = p->unk3C * 4 + 10;
    if (p->unk3C != 0) {
        for (i = 0; i < 40; i++) {
            if (i < p->unk3C) {
                screen->addSprite(screen, i, screen->getHandOffset(p->unk3C, i) + 0x1800, 0x6100);
                switch (which) {
                case 0:
                    screen->setSpriteCard(screen, i, battle->sides[side].pile.hand[i]);
                    break;
                case 1:
                    screen->setSpriteCard(screen, i, battle->sides[side].pile.discards[i]);
                    break;
                case 2:
                    screen->setSpriteCard(screen, i, battle->sides[side].pile.deck[battle->sides[side].pile.deckTop + i]);
                    break;
                }
                if (p->unk4 != 0) {
                    screen->sprites[i].visible = 2;
                }
                screen->sprites[i].scaleX = 0;
                items->screen->sprites[i].dimmed = battle->unk498.unk6[i];
            } else {
                screen->removeSprite(screen, i);
            }
        }
        p->unk4 = 0;
    } else {
        p->unk4 = 0;
        screen->addSprite(screen, 0, screen->getHandOffset(p->unk3C, 0) + 0x1800, 0x6100);
        screen->sprites[0].visible = 3;
        screen->sprites[0].scaleX = 0;
        for (i = 1; i < 40; i++) {
            screen->removeSprite(screen, i);
        }
    }
}

/* Closes the panels once; 1 once they are closed */
s32 CARDGAME_stepHidePanels(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    if (battle->unk4E8 == 0) {
        battle->unk498.unk1 = 2;
        items->screen->closePanels(items->screen);
        battle->unk4E8++;
    }
    if (items->screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
        done = 1;
    }
    return done;
}

/* Starts the count of side's hand, discards or deck (which 0-2) */
void CARDGAME_startPileCount(CardBattle *battle, CardBattleItems *items, s32 side, s32 which) {
    CardBattle498 *p = &battle->unk498;

    switch (which) {
    case 0:
        p->unk3C = battle->sides[side].pile.handCount;
        break;
    case 1:
        p->unk3C = battle->sides[side].pile.discardCount;
        break;
    case 2:
        p->unk3C = battle->sides[side].pile.deckCount;
        break;
    }
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
    p->unk40 = p->unk3C * 4 + 10;
}

/* Lays out the slots as sprites (0-5 player 0's, 6-11 player 1's) and each record.entries entry (12 on), marking in unk3E[entry] the slot sprites it applies to (by unk5) */
void CARDGAME_layOutSlots(CardBattle *battle, CardBattleItems *items) {
    CardScreen *screen = items->screen;
    CardSlot *slot;
    CardSprite *sprite;
    s32 i;
    s32 j;
    s32 first;
    s32 index;
    s32 card;

    for (i = 0; i < 6; i++) {
        if (i >= battle->players[0].slotCount) {
            break;
        }
#if VERSION_US
        screen->addSprite(screen, i, 0x1800 + i * 0x2900, 0x9000);
#elif VERSION_EU
        screen->addSprite(screen, i, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + i * 0x2900, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1]);
#endif
        screen->setSpriteCard(screen, i, battle->players[0].slots[i].card);
        screen->sprites[i].unk43 = battle->players[0].slots[i].unk6;
        screen->sprites[i].unk44 = battle->players[0].slots[i].unk8;
        screen->sprites[i].scaleX = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i >= battle->players[1].slotCount) {
            break;
        }
#if VERSION_US
        screen->addSprite(screen, i + 6, 0x1800 + i * 0x2900, 0x3200);
#elif VERSION_EU
        screen->addSprite(screen, i + 6, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + i * 0x2900, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3]);
#endif
        screen->setSpriteCard(screen, i + 6, battle->players[1].slots[i].card);
        screen->sprites[i + 6].unk43 = battle->players[1].slots[i].unk6;
        screen->sprites[i + 6].unk44 = battle->players[1].slots[i].unk8;
        screen->sprites[i + 6].scaleX = 0;
        if (battle->unk498.unk4 != 0) {
            screen->sprites[i + 6].visible = 2;
        }
    }
    battle->unk498.unk4 = 0;
    for (i = 0; i < battle->record.entryCount; i++) {
        screen->addSprite(screen, i + 12, 0x5100 + i * 0x3200, 0x6100);
        screen->setSpriteCard(screen, i + 12, battle->record.entries[i].unk0);
        screen->sprites[i + 12].scaleX = 0;
        screen->sprites[i + 12].unk46 = i + 1;
        screen->sprites[i + 12].unk3E[0] = 0;
        screen->sprites[i + 12].unk3E[1] = 0;
        screen->sprites[i + 12].unk3E[2] = 0;
        screen->sprites[i + 12].moving = 0;
        if (battle->record.entries[i].unk2 != 0) {
            screen->sprites[i + 12].unk3E[battle->record.entries[i].unk2] = 1;
        }
        switch (battle->record.entries[i].unk5) {
        case 0:
            for (j = 0; j < 12; j++) {
                if (j < 6) {
                    if (j >= battle->players[0].slotCount) {
                        continue;
                    }
                    slot = &battle->players[0].slots[j];
                } else {
                    index = j - 6;
                    if (index >= battle->players[1].slotCount) {
                        continue;
                    }
                    slot = &battle->players[1].slots[index];
                }
                if (slot->order == battle->record.entries[i].unk6) {
                    screen->sprites[j].unk3E[i] = 1;
                }
            }
            break;
        case 1:
            first = 0;
            if (battle->record.entries[i].unk4 != 0) {
                first = 6;
            }
            sprite = &screen->sprites[first];
            for (j = 0; j < 6; j++) {
                sprite[j].unk3E[i] = 1;
            }
            break;
        case 2:
            first = 0;
            if (battle->record.entries[i].unk4 == 0) {
                first = 6;
            }
            sprite = &screen->sprites[first];
            for (j = 0; j < 6; j++) {
                sprite[j].unk3E[i] = 1;
            }
            break;
        case 3:
            for (j = 0; j < 12; j++) {
                screen->sprites[j].unk3E[i] = 1;
            }
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            for (j = 0; j < 12; j++) {
                if (j < 6) {
                    card = battle->players[0].slots[j].card;
                } else {
                    card = battle->players[1].slots[j - 6].card;
                }
                switch (battle->record.entries[i].unk5) {
                case 4:
                    if (screen->getCardColor(screen, card) != 1) {
                        screen->sprites[j].unk3E[i] = 1;
                    }
                    break;
                case 5:
                    if (screen->getCardColor(screen, card) != 2) {
                        screen->sprites[j].unk3E[i] = 1;
                    }
                    break;
                case 6:
                    if (screen->getCardColor(screen, card) == 3) {
                        screen->sprites[j].unk3E[i] = 1;
                    }
                    break;
                case 7:
                    if (screen->getCardColor(screen, card) != 4) {
                        screen->sprites[j].unk3E[i] = 1;
                    }
                    break;
                case 8:
                    if (screen->getCardColor(screen, card) == 6) {
                        screen->sprites[j].unk3E[i] = 1;
                    }
                    break;
                }
            }
            break;
        case 9:
            break;
        }
    }
}

/* Starts the fade that unk306 asks for (CARDGAME_fadeColors) */
void CARDGAME_startStepFade(CardBattle *battle, CardBattleItems *items) {
    s32 frames;
    CardFader *fader;
    s32 i;

    if (battle->unk306 != 0) {
        i = battle->unk306 - 1;
        frames = 10;
        fader = CARDGAME_createFader(CARDGAME_fadeColors[i].blend);
        items->unk0[1] = fader;
        fader->setColor(fader, CARDGAME_fadeColors[i].r, CARDGAME_fadeColors[i].g, CARDGAME_fadeColors[i].b);
        if (CARDGAME_fadeColors[i].blend == 2) {
            frames = 15;
        }
        ((CardFader *)items->unk0[1])->start(items->unk0[1], 0, 0, 0, frames, 1);
        battle->unk306 = 0;
    }
}

/* Sets the 15 sprites' unk498.unk6 to whether unk498.unk5 is 2, once it is
   set */
void CARDGAME_resetSpriteFlags(CardBattle *battle) {
    CardBattle498 *p = &battle->unk498;
    u8 state = p->unk5;
    s32 i;

    if (state != 0) {
        for (i = 0; i < 15; i++) {
            battle->unk498.unk6[i] = state == 2;
        }
        p->unk5 = 0;
    }
}

/* Starts (unk498.unk1) and runs (unk498.unk0) the screen's card animations: the hands', the record's and a pile's sprites scaling in or out */
void CARDGAME_updateCardAnims(CardBattle *battle, CardBattleItems *items) {
    CardBattle498 *p = &battle->unk498;
    CardScreen *screen = items->screen;
    s32 index = 0;
    s32 count;
    s32 i;

    if (p->unk1 != 0) {
        switch (p->unk1) {
        case 1:
            CARDGAME_layOutSlots(battle, items);
            p->unk30 = 3;
            p->unk34 = 0;
            p->unk38 = 4;
            p->unk40 = (battle->players[0].slotCount > battle->players[1].slotCount ? battle->players[0].slotCount : battle->players[1].slotCount) * 8;
            for (i = 0; i < 40; i++) {
                items->screen->sprites[i].dimmed = battle->unk498.unk6[i];
            }
            break;
        case 3:
            p->unk30 = 3;
            p->unk34 = 0;
            p->unk38 = 4;
            p->unk40 = battle->record.entryCount * 10;
            break;
        case 2:
            p->unk30 = 3;
            p->unk34 = 0;
            p->unk38 = 4;
            p->unk40 = (battle->players[0].slotCount > battle->players[1].slotCount ? battle->players[0].slotCount : battle->players[1].slotCount) * 5;
            break;
        case 4:
            p->unk30 = 3;
            p->unk34 = 0;
            p->unk38 = 4;
            p->unk40 = battle->record.entryCount * 5 + 22;
            break;
        case 5:
        case 17:
            index++;
        case 7:
            index++;
        case 9:
            index++;
        case 11:
        case 18:
            index++;
        case 13:
            index++;
        case 15:
            index++;
            CARDGAME_layOutPile(battle, items, CARDGAME_animPiles[index][0], CARDGAME_animPiles[index][1]);
            break;
        case 6:
            CARDGAME_startPileCount(battle, items, 0, 0);
            break;
        case 10:
            CARDGAME_startPileCount(battle, items, 0, 1);
            break;
        case 8:
            CARDGAME_startPileCount(battle, items, 0, 2);
            break;
        case 16:
            CARDGAME_startPileCount(battle, items, 1, 1);
            break;
        case 14:
            CARDGAME_startPileCount(battle, items, 1, 2);
            break;
        case 12:
            CARDGAME_startPileCount(battle, items, 1, 0);
            break;
        }
        p->unk3 = p->unk1 + 1;
        p->unk0 = p->unk1;
        p->unk1 = 0;
    }
    switch (p->unk0) {
    case 1:
        if (p->unk38 >= 4) {
            if (p->unk34 < battle->players[0].slotCount) {
                items->screen->scaleSprite(items->screen, p->unk34, 10, 0x1000, 0x1000);
            }
            if (p->unk34 < battle->players[1].slotCount) {
                items->screen->scaleSprite(items->screen, p->unk34 + 6, 10, 0x1000, 0x1000);
            }
            p->unk34++;
            p->unk38 -= 4;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        if (p->unk40 < p->unk30) {
            p->unk1 = 3;
        }
        break;
    case 3:
        if (p->unk38 >= 4) {
            if (p->unk34 < battle->record.entryCount) {
                items->screen->scaleSprite(items->screen, p->unk34 + 12, 10, 0x1000, 0x1000);
            }
            if (p->unk34 - 1 < battle->record.entryCount && p->unk34 - 1 >= 0) {
                items->screen->openGauge(items->screen, p->unk34 - 1, battle->record.entries[p->unk34 - 1].unk4);
            }
            p->unk34++;
            p->unk38 -= 4;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        if (p->unk40 < p->unk30) {
            p->unk0 = 0;
        }
        break;
    case 2:
        if (p->unk38 >= 4) {
            if (p->unk34 < battle->players[0].slotCount) {
                items->screen->scaleSprite(items->screen, p->unk34, 5, 0, 0x1000);
            }
            if (p->unk34 < battle->players[1].slotCount) {
                items->screen->scaleSprite(items->screen, p->unk34 + 6, 5, 0, 0x1000);
            }
            p->unk34++;
            p->unk38 -= 4;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        if (p->unk40 < p->unk30) {
            p->unk1 = 4;
        }
        break;
    case 4:
        if (p->unk38 >= 4) {
            if (p->unk34 < battle->record.entryCount) {
                items->screen->scaleSprite(items->screen, p->unk34 + 12, 5, 0, 0x1000);
                items->screen->closeGauge(items->screen, p->unk34);
            }
            p->unk34++;
            p->unk38 -= 4;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        if (p->unk40 < p->unk30) {
            p->unk0 = 0;
        }
        break;
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
        count = p->unk3C;
        if (count == 0) {
            count = 1;
        }
        if (p->unk34 < count && p->unk38 >= 4) {
            screen->scaleSprite(screen, p->unk34, 10, 0x1000, 0x1000);
            p->unk34++;
            p->unk38 -= 4;
        }
        if (p->unk30 > p->unk40) {
            p->unk0 = 0;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        break;
    case 6:
    case 8:
    case 10:
    case 12:
    case 14:
    case 16:
        count = p->unk3C;
        if (count == 0) {
            count = 1;
        }
        if (p->unk34 < count && p->unk38 >= 4) {
            screen->scaleSprite(screen, p->unk34, 5, 0, 0x1000);
            p->unk34++;
            p->unk38 -= 4;
        }
        if (p->unk30 > p->unk40) {
            p->unk0 = 0;
        }
        p->unk30 += GFX.funcs.getFrameTime();
        p->unk38 += GFX.funcs.getFrameTime();
        break;
    case 17:
        p->unk0 = 0;
        p->unk3 = 6;
        break;
    case 18:
        p->unk0 = 0;
        p->unk3 = 12;
        break;
    }
}

/* Shows both sides' values on their panels: the points of each colour, the
   deck, hand and discards, unk0 and unk2 */
void CARDGAME_showPanelValues(CardBattle *battle, CardBattleItems *items) {
    s32 side;
    s32 i;

    for (side = 0; side < 2; side++) {
        for (i = 0; i < 5; i++) {
            items->screen->setPanelValue(items->screen, side, i, battle->sides[side].pile.points[i]);
        }
        items->screen->setPanelValue(items->screen, side, 5, battle->sides[side].pile.deckCount);
        items->screen->setPanelValue(items->screen, side, 6, battle->sides[side].pile.handCount);
        items->screen->setPanelValue(items->screen, side, 7, battle->sides[side].pile.discardCount);
        items->screen->setPanelValue(items->screen, side, 8, battle->sides[side].pile.unk0);
        items->screen->setPanelValue(items->screen, side, 9, battle->sides[side].pile.unk2);
    }
}

/* Sorts the cards list[from..to) (range: to << 16 | from) by their values,
   moving unk30A (flags bit 0) and unk446 (bit 1) with them */
void CARDGAME_sortCards(CardBattle *battle, s16 *list, s32 range, s32 flags) {
    CardBattle30A tmp30A;
    s16 tmp;
    s8 tmp446;
    s32 from;
    s32 to;
    s16 *ids;
    s32 i;
    s32 j;

    from = range & 0xFFFF;
    to = range >> 16;
    /* the match depends on this copy of list after from and to: list stays
       in $a1 until here, so from gets $s0 and leaves $a1 to flags & 1 */
    ids = list;
    for (i = from; i < to - 1; i++) {
        for (j = i + 1; j < to; j++) {
            if (battle->cards[ids[i]] > battle->cards[ids[j]]) {
                tmp = ids[i];
                ids[i] = ids[j];
                ids[j] = tmp;
                if (flags & 1) {
                    tmp30A = battle->unk30A[i];
                    battle->unk30A[i] = battle->unk30A[j];
                    battle->unk30A[j] = tmp30A;
                }
                if (flags & 2) {
                    tmp446 = battle->unk446[i - from];
                    battle->unk446[i - from] = battle->unk446[j - from];
                    battle->unk446[j - from] = tmp446;
                }
            }
        }
    }
}

/* Shuffles the player's pile's unk14[base..base + n) with 40 random swaps */
void CARDGAME_shufflePile(CardBattle *battle, s32 base, s32 n) {
    CardPile *pile = &battle->sides[0].pile;
    s32 i;
    s32 a;
    s32 b;
    s32 tmp;

    if (n >= 2) {
        for (i = 0; i < 40; i++) {
            a = RANDOM.next() % n + base;
            b = RANDOM.next() % n + base;
            tmp = pile->deck[a];
            pile->deck[a] = pile->deck[b];
            pile->deck[b] = tmp;
        }
    }
}

/* Chooses the player's deck: opens the three deck windows and a marker, Up/Down/Cross pick one, then loads both decks' cards; 1 once done */
s32 CARDGAME_chooseDeck(CardBattle *battle, CardBattleItems *items) {
    CardPreloader *preloader;
    CardPile *pile;
    s32 i;
    s32 done = 0;

    switch (battle->unk2F9) {
    case 0:
    default:
        preloader = items->unk0[0];
        if (preloader == NULL) {
            battle->unk2F9++;
        } else if (preloader->state == 1 && preloader->ready != 0) {
            battle->unk2F9++;
        }
        break;
    case 1:
        items->screen->openWindow(items->screen, 5, 5, 0x41, 0, 0x26);
        SOUND.playSound(SOUND_MENU_OPEN);
        items->deckWindows[0] = CARDGAME_createDeckWindow(0, CARDGAME_deckWindowPos[0].x, CARDGAME_deckWindowPos[0].y);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 2:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 11) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 3:
        SOUND.playSound(SOUND_MENU_OPEN);
        items->deckWindows[1] = CARDGAME_createDeckWindow(1, CARDGAME_deckWindowPos[1].x, CARDGAME_deckWindowPos[1].y);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 4:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 11) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 5:
        SOUND.playSound(SOUND_MENU_OPEN);
        items->deckWindows[2] = CARDGAME_createDeckWindow(2, CARDGAME_deckWindowPos[2].x, CARDGAME_deckWindowPos[2].y);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 6:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 11) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 7:
        items->marker = CARDGAME_createMarker(CARDGAME_deckWindowPos[0].x, CARDGAME_deckWindowPos[0].y);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 8:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 11) {
            battle->unk2FC = 0;
            battle->unk2EA = 0;
            battle->unk2F9++;
        }
        break;
    case 9:
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_UP))) |
            (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_UP)))) {
            if (battle->unk2EA > 0) {
                battle->unk2EA--;
                SOUND.playSound(SOUND_MENU_MOVE);
            }
        } else if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_DOWN))) |
                   (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_DOWN)))) {
            if (battle->unk2EA < 2) {
                battle->unk2EA++;
                SOUND.playSound(SOUND_MENU_MOVE);
            }
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            battle->unk2FC = 0;
            battle->unk2F9++;
            items->deckWindows[battle->unk2EA]->setBlink(items->deckWindows[battle->unk2EA]);
            items->marker->setFast(items->marker);
        }
        items->marker->setPos(items->marker, CARDGAME_deckWindowPos[battle->unk2EA].x, CARDGAME_deckWindowPos[battle->unk2EA].y);
        break;
    case 10:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 15) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 11:
        items->marker->close(items->marker);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 13:
        SOUND.playSound(SOUND_MENU_CLOSE);
        items->deckWindows[0]->close(items->deckWindows[0]);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 14:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 4) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 15:
        SOUND.playSound(SOUND_MENU_CLOSE);
        items->deckWindows[1]->close(items->deckWindows[1]);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 16:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 4) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 17:
        SOUND.playSound(SOUND_MENU_CLOSE);
        items->deckWindows[2]->close(items->deckWindows[2]);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 18:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 4) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 19:
        items->screen->closeWindow(items->screen, 5);
        battle->unk2FC = 0;
        battle->unk2F9++;
        break;
    case 12:
    case 20:
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 6) {
            battle->unk2FC = 0;
            battle->unk2F9++;
        }
        break;
    case 21:
        if (GAME.decks[battle->unk2EA].cards[0] != 0) {
            for (i = 0; i < 40; i++) {
                battle->playerDeck[i] = GAME.decks[battle->unk2EA].cards[i] - 1;
            }
        } else {
            for (i = 0; i < 40; i++) {
                battle->playerDeck[i] = CARDGAME_defaultDeck[i];
            }
        }
        battle->cardCount = items->screen->loadCardImages(battle->cards, battle->playerDeck, battle->opponentDeck);
        for (i = 0; i < 40; i++) {
            battle->sides[0].pile.deck[i] = i;
            battle->sides[1].pile.deck[i] = i + 40;
        }
        battle->unk300 = 0;
        CARDGAME_findOpponentDeckLimits(battle, items);
        battle->sides[1].pile.deckCount = 40;
        battle->sides[0].pile.deckCount = 40;
        battle->sides[1].pile.deckTop = 0;
        battle->sides[0].pile.deckTop = 0;
        CARDGAME_showPanelValues(battle, items);
        pile = &battle->sides[0].pile;
        battle->shufflePile(battle, pile->deckTop, pile->deckCount);
        done = 1;
        break;
    }
    return done;
}

/* Runs step 0xA7 (CARDGAME_startFirstPick) and then keeps who goes first
   (unk2F5); 1 once done */
s32 CARDGAME_runFirstPick(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    if (battle->unk2F9 == 0) {
        battle->unk421 = 0xA7;
        battle->unk2F4 = 1;
        battle->unk2F9 = 1;
    } else {
        if (battle->unk440 == 0) {
            battle->unk2F5 = 0;
        } else {
            battle->unk2F5 = 1;
        }
        done = 1;
    }
    return done;
}

/* Runs step 20 and then returns its choice + 1 */
s32 CARDGAME_runStartStep(CardBattle *battle, CardBattleItems *items) {
    s32 result = 0;

    if (battle->unk2F9 == 0) {
        battle->unk421 = 0x14;
        battle->unk2F4 = 1;
        battle->unk2F9++;
    } else {
        switch (battle->unk440) {
        case 0:
            result = 1;
            break;
        case 1:
            result = 2;
            break;
        case 2:
            result = 3;
            break;
        }
    }
    return result;
}

/* Takes the first flagged card out of the hand of side record.unk19 into the record entry record.entries[entryCount]; returns its condition id */
s32 CARDGAME_takeFlaggedCard(CardBattle *battle, CardBattleItems *items) {
    s32 i;
    s32 j;
    s32 side;
    s32 card;
    s16 index;

    for (i = 0; i < 10; i++) {
        if (battle->unk46F[i] != 0) {
            break;
        }
    }
    side = battle->record.unk19;
    card = battle->cards[battle->sides[side].pile.hand[i]];
    battle->record.entries[battle->record.entryCount].unk4 = side;
    index = battle->sides[side].pile.hand[i];
    battle->record.entries[battle->record.entryCount].unk0 = index;
    battle->record.entries[battle->record.entryCount].unk5 = CARDGAME_getEffectField(battle->cards[index], 3, 0);
    for (j = i; j < battle->sides[side].pile.handCount - 1; j++) {
        battle->sides[side].pile.hand[j] = battle->sides[side].pile.hand[j + 1];
    }
    battle->sides[side].pile.handCount--;
    return CARDGAME_getEffectField(card, 0, 0);
}

/* Flags (unk46F) the slots that the current record entry's target kind (record.entries[entryCount].unk5) picks */
void CARDGAME_flagTargetSlots(CardBattle *battle, CardScreen *screen) {
    CardSlot *slot;
    s32 card;
    s32 i;

    for (i = 0; i < 12; i++) {
        battle->unk46F[i] = 0;
        switch (battle->record.entries[battle->record.entryCount].unk5) {
        case 0:
            if (i < 6) {
                if (i >= battle->players[0].slotCount) {
                    break;
                }
                slot = &battle->players[0].slots[i];
            } else {
                if (i - 6 >= battle->players[1].slotCount) {
                    break;
                }
                slot = &battle->players[1].slots[i - 6];
            }
            if (slot->order == battle->record.entries[battle->record.entryCount].unk6) {
                battle->unk46F[i] = 1;
            }
            break;
        case 2:
            if (i < 6 && i < battle->players[0].slotCount) {
                battle->unk46F[i] = 1;
            }
            break;
        case 1:
            if (i >= 6 && i - 6 < battle->players[1].slotCount) {
                battle->unk46F[i] = 1;
            }
            break;
        case 3:
            battle->unk46F[i] = 1;
            break;
        case 4:
            if (i < 6) {
                card = battle->players[0].slots[i].card;
            } else {
                card = battle->players[1].slots[i - 6].card;
            }
            if (screen->getCardColor(screen, card) != 1) {
                battle->unk46F[i] = 1;
            }
            break;
        case 5:
            if (i < 6) {
                card = battle->players[0].slots[i].card;
            } else {
                card = battle->players[1].slots[i - 6].card;
            }
            if (screen->getCardColor(screen, card) != 2) {
                battle->unk46F[i] = 1;
            }
            break;
        case 6:
            if (i < 6) {
                card = battle->players[0].slots[i].card;
            } else {
                card = battle->players[1].slots[i - 6].card;
            }
            if (screen->getCardColor(screen, card) == 3) {
                battle->unk46F[i] = 1;
            }
            break;
        case 7:
            if (i < 6) {
                card = battle->players[0].slots[i].card;
            } else {
                card = battle->players[1].slots[i - 6].card;
            }
            if (screen->getCardColor(screen, card) != 4) {
                battle->unk46F[i] = 1;
            }
            break;
        case 8:
            if (i < 6) {
                card = battle->players[0].slots[i].card;
            } else {
                card = battle->players[1].slots[i - 6].card;
            }
            if (screen->getCardColor(screen, card) == 6) {
                battle->unk46F[i] = 1;
            }
            break;
        case 9:
            break;
        }
    }
}

/* Runs the rounds of plays (state record.unk14): each side in turn plays a card, the computer through CARDGAME_pickComputerCard; 1 once over */
s32 CARDGAME_playRounds(CardBattle *battle, CardBattleItems *items) {
    s32 condition;
    s32 side;
    s32 i;
    s32 done = 0;

    switch (battle->record.unk14) {
    case 0:
    default:
        battle->record.unk14 = 16;
        battle->record.entryCount = 0;
        battle->record.unk17 = 0;
        battle->record.entries[0].unk2 = 0;
        battle->record.entries[1].unk2 = 0;
        battle->record.entries[2].unk2 = 0;
        battle->unk498.unk5 = 1;
        battle->unk498.unk1 = 1;
        battle->record.starter = battle->record.unk19 = battle->unk2F5;
        items->screen->openPanels(items->screen);
        break;
    case 16:
        if (items->screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            battle->record.unk14 = 17;
            items->screen->openWindow(items->screen, 5, 5, battle->unk2F8 == 5 ? 0x3C : 0x3D, 0, 0x6E);
        }
        break;
    case 17:
        if (items->screen->windows[5].state == 2) {
            if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
                battle->record.unk14 = 18;
                items->screen->closeWindow(items->screen, 5);
            }
        }
        break;
    case 18:
        if (items->screen->windows[5].state == 0) {
            battle->record.unk14 = 1;
        }
        break;
    case 1:
        switch (battle->record.entryCount) {
        case 0:
        case 2:
            if (battle->record.starter != 0) {
                battle->record.unk14 = 3;
            } else {
                battle->record.unk14 = 2;
            }
            break;
        case 1:
            if (battle->record.starter != 0) {
                battle->record.unk14 = 2;
            } else {
                battle->record.unk14 = 3;
            }
            break;
        default:
            battle->record.unk14 = 12;
            break;
        }
        if (battle->record.entryCount != 0) {
            battle->record.unk17 = 0;
        }
        battle->record.unk1A = -1;
        items->screen->setPanelValue(items->screen, 0, 6, battle->sides[0].pile.handCount);
        items->screen->setPanelValue(items->screen, 1, 6, battle->sides[1].pile.handCount);
        break;
    case 3:
        CARDGAME_sortOpponentHand(battle);
        if (CARDGAME_pickComputerCard(battle, items->screen)) {
            condition = CARDGAME_takeFlaggedCard(battle, items);
            if (condition == 0x83 || condition == 0x84) {
                for (i = 0; i < 15; i++) {
                    battle->unk46F[i] = 0;
                }
                battle->unk46F[battle->record.entryCount + 11] = 1;
                battle->record.entries[battle->record.entryCount - 1].unk2 = 1;
            }
            if (battle->record.unk17 != 0) {
                SOUND.playSound(SOUND_MENU_OPEN);
                items->screen->closePanelIcon(items->screen, 0);
            }
            battle->record.unk14 = 9;
            CARDGAME_flagTargetSlots(battle, items->screen);
        } else if (battle->record.entryCount == 0) {
            battle->record.unk14 = 11;
            battle->record.unk1C = 20;
            battle->record.unk17++;
            SOUND.playSound(SOUND_MENU_OPEN);
            items->screen->openPanelIcon(items->screen, 1);
        } else {
            battle->record.unk14 = 12;
        }
        break;
    case 2:
        if (battle->record.unk1A == -1) {
            battle->unk2F4 = 1;
            battle->unk421 = 0x98;
            battle->sortCards(battle, battle->sides[0].pile.hand, battle->sides[0].pile.handCount << 16, 0);
        } else if (battle->record.unk1A != 0) {
            battle->record.unk14 = CARDGAME_turnStates[battle->record.unk19 + 2];
            battle->record.unk1A = -1;
            if (battle->record.unk17 != 0) {
                items->screen->panels[1].scale.state = 0;
            }
        } else if (battle->record.entryCount == 0) {
            battle->record.unk14 = 11;
            battle->record.unk1C = 20;
            battle->record.unk17++;
            SOUND.playSound(SOUND_MENU_OPEN);
            items->screen->openPanelIcon(items->screen, 0);
        } else {
            battle->record.unk14 = 12;
        }
        break;
    case 4:
    case 5:
        if (battle->record.unk1A == -1) {
            battle->unk2F4 = 1;
            battle->unk421 = 0x99;
        } else if (battle->record.unk1A != 0) {
            battle->record.unk14 = CARDGAME_turnStates[battle->record.unk19 + 4];
            battle->record.unk1A = -1;
        } else {
            battle->record.unk14 = CARDGAME_turnStates[battle->record.unk19];
            battle->record.unk1A = -1;
            if (battle->record.unk17 != 0) {
                items->screen->panels[1].scale.state = 2;
            }
        }
        break;
    case 6:
    case 7:
        if (battle->record.unk1A == -1) {
            battle->unk421 = CARDGAME_takeFlaggedCard(battle, items);
            battle->unk2F4 = 1;
        } else if (battle->record.unk1A != 0) {
            battle->record.unk14 = CARDGAME_turnStates[battle->record.unk19 + 6];
        } else {
            side = battle->record.unk19;
            battle->sides[side].pile.hand[battle->sides[side].pile.handCount] = battle->record.entries[battle->record.entryCount].unk0;
            battle->sides[side].pile.handCount++;
            battle->sortCards(battle, battle->sides[0].pile.hand, battle->sides[0].pile.handCount << 16, 0);
            battle->record.unk14 = CARDGAME_turnStates[battle->record.unk19 + 2];
            battle->record.unk1A = -1;
        }
        break;
    case 9:
        battle->unk421 = 0x13;
        battle->unk2F4 = 1;
        battle->record.unk14 = 10;
        break;
    case 8:
        battle->unk421 = 0x12;
        battle->unk2F4 = 1;
        battle->record.unk14 = 10;
        break;
    case 10:
        battle->record.unk14 = 1;
        battle->record.unk19 ^= 1;
        battle->record.entryCount++;
        break;
    case 11:
        if (--battle->record.unk1C <= 0) {
            battle->record.unk14 = 14;
        }
        break;
    case 12:
        if (battle->record.entryCount > 0) {
            battle->unk2F4 = 2;
            battle->record.unk14 = 13;
            battle->unk4DC = 0;
            battle->unk4EC = 0;
            battle->unk4E8 = 0;
            battle->unk4DE = battle->record.entryCount;
        } else {
            battle->record.unk14 = 14;
        }
        break;
    case 13:
        battle->record.unk14 = 12;
        break;
    case 14:
        battle->record.unk14 = 1;
        battle->record.entryCount = 0;
        battle->record.entries[0].unk2 = 0;
        battle->record.entries[1].unk2 = 0;
        battle->record.entries[2].unk2 = 0;
        battle->record.starter ^= 1;
        battle->record.unk19 = battle->record.starter;
        battle->record.rounds++;
        if (battle->record.unk17 >= 2) {
            battle->record.unk14 = 15;
            battle->unk4E8 = 0;
        }
        break;
    case 15:
        items->screen->closePanelIcon(items->screen, 0);
        items->screen->closePanelIcon(items->screen, 1);
        if (CARDGAME_stepHidePanels(battle, items)) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Clears record.unk14, shows the panel values and sorts the player's hand */
void CARDGAME_prepareTurn(CardBattle *battle, CardBattleItems *items) {
    battle->record.unk14 = 0;
    CARDGAME_showPanelValues(battle, items);
    battle->sortCards(battle, battle->sides[0].pile.hand, battle->sides[0].pile.handCount << 16, 0);
}

/* Takes the marked cards (unk46F) out of pile's hand */
void CARDGAME_removeMarkedHandCards(CardBattle *battle, CardPile *pile) {
    s32 i;
    s32 j;

    for (i = pile->handCount - 1; i >= 0; i--) {
        if (battle->unk46F[i] != 0) {
            for (j = i; j < pile->handCount - 1; j++) {
                pile->hand[j] = pile->hand[j + 1];
            }
            pile->handCount--;
        }
    }
}

void CARDGAME_setSlot(CardBattle *battle, s32 side, s32 card, s32 index) {
    CardDrawer drawer;
    CardPlayer *player = &battle->players[side];

    initCardDrawer(&drawer);
    drawer.setCard(battle->cards[card] + 1);
    player->slots[index].unk6 = drawer.card->ap;
    player->slots[index].unk8 = drawer.card->hp;
    player->slots[index].unk2 = 0;
    player->slots[index].unk4 = 0;
    player->slots[index].card = card;
    player->slots[index].owner = side;
    player->slots[index].side = side;
    player->slots[index].order = battle->slotCount++;
}

void CARDGAME_addCard(CardBattle *battle, s32 side, s32 card) {
    CardPlayer *player = &battle->players[side];

    CARDGAME_setSlot(battle, side, card, player->slotCount++);
}

/* Puts side's flagged cards of its pile into its slots, up to unk444 of them */
void CARDGAME_putOutCards(CardBattle *battle, s32 side) {
    CardPlayer *player = &battle->players[side];
    CardPile *pile = &battle->sides[side].pile;
    s32 i;

    player->slotCount = 0;
    for (i = 0; i < pile->handCount; i++) {
        if (player->slotCount < battle->unk444 && battle->unk46F[i] != 0) {
            CARDGAME_addCard(battle, side, pile->hand[i]);
        }
    }
    CARDGAME_removeMarkedHandCards(battle, pile);
}

/* Sets the values of a slot that holds the pass-th card of CARDGAME_countingCards from the battle's counts (0 to 99) */
void CARDGAME_setCountingCardValues(CardBattle *battle, CardSlot *slot, s32 side, s32 pass) {
    CardSide *cardSide = &battle->sides[side];
    CardPlayer *player = &battle->players[side];
    s32 values[2];
    s32 i;
    s32 base;

    if (battle->cards[slot->card] == CARDGAME_countingCards[pass]) {
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                base = slot->unk2;
            } else {
                base = slot->unk4;
            }
            switch (pass) {
            case 0:
                values[i] = player->slotCount * 20 + base;
                break;
            case 1:
                values[i] = cardSide->pile.handCount * 10 + 10 + base;
                break;
            case 2:
                values[i] = cardSide->pile.discardCount * 20 + 10 + base;
                break;
            case 3:
                values[i] = (battle->players[0].slotCount + battle->players[1].slotCount) * 10 + base;
                break;
            case 4:
                values[i] = (battle->sides[0].pile.discardCount + battle->sides[1].pile.discardCount) * 10 + 10 + base;
                break;
            }
            if (values[i] >= 99) {
                values[i] = 99;
            }
            if (values[i] <= 0) {
                values[i] = 0;
            }
        }
        slot->unk6 = values[0];
        slot->unk8 = values[1];
    }
}

/* Sets the values of the counting cards out, pass by pass
   (CARDGAME_setCountingCardValues); whether any card is out */
s32 CARDGAME_setAllCountingValues(CardBattle *battle) {
    s32 found = 0;
    s32 pass;
    s32 side;
    s32 i;
    CardPlayer *player;

    for (pass = 0; pass < 5; pass++) {
        for (side = 0; side < 2; side++) {
            player = &battle->players[side];
            for (i = 0; i < player->slotCount; i++) {
                found = 1;
                CARDGAME_setCountingCardValues(battle, &player->slots[i], side, pass);
            }
        }
    }
    return found;
}

/* Side's unk0 and unk2 become the sums of its slot cards' unk6 and unk8 */
void CARDGAME_sumSlotValues(CardBattle *battle, s32 side) {
    s32 i;

    battle->sides[side].pile.unk0 = 0;
    battle->sides[side].pile.unk2 = 0;
    for (i = 0; i < battle->players[side].slotCount; i++) {
        battle->sides[side].pile.unk0 += battle->players[side].slots[i].unk6;
        battle->sides[side].pile.unk2 += battle->players[side].slots[i].unk8;
    }
}

/* A battle step: each side puts out its flagged cards (putOutCards) between messages 0x9A, 0x9D and 0x9E; 1 once done */
s32 CARDGAME_runPutOut(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    switch (battle->unk2F9) {
    case 0:
        battle->unk421 = 0x9A;
        battle->unk2F4 = 1;
        battle->unk2F9 = 1;
        break;
    case 1:
        battle->putOutCards(battle, 0);
        battle->unk2F9 = 2;
        items->screen->setPanelValue(items->screen, 0, 6, battle->sides[0].pile.handCount);
        break;
    case 2:
        CARDGAME_sortOpponentHand(battle);
        battle->unk421 = 0x9D;
        battle->unk2F4 = 1;
        battle->unk2F9 = 3;
        break;
    case 3:
        battle->putOutCards(battle, 1);
        battle->unk2F9 = 4;
        CARDGAME_setAllCountingValues(battle);
        CARDGAME_sumSlotValues(battle, 1);
        CARDGAME_sumSlotValues(battle, 0);
        items->screen->setPanelValue(items->screen, 1, 6, battle->sides[1].pile.handCount);
        break;
    case 4:
        battle->unk421 = 0x9E;
        battle->unk2F4 = 1;
        battle->unk2F9 = 5;
        break;
    case 5:
        done = 1;
        break;
    }
    return done;
}

/* Finds three or more of one card (with a header unkA) among a side's slots, by id from start: flags them in unk446; the index after them or -1 */
s32 CARDGAME_findCardSet(CardBattle *battle, s32 side, s32 start) {
    CardSortEntry entries[6];
    CardSortEntry tmp;
    CardDrawer drawer;
    s32 count;
    s32 value;
    s32 result;
    s32 i;
    s32 j;
    s32 k;

    result = -1;
    value = 0x51;
    count = battle->players[side].slotCount;
    initCardDrawer(&drawer);
    for (i = 0; i < count; i++) {
        entries[i].card = battle->cards[battle->players[side].slots[i].card];
        entries[i].slot = i;
    }
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (entries[i].card > entries[j].card) {
                tmp = entries[i];
                entries[i] = entries[j];
                entries[j] = tmp;
            }
        }
    }
    j = 0;
    for (i = start; i < count - 1; i++) {
        drawer.setCard(entries[i].card + 1);
        if (drawer.card->unkA != 0 && entries[i].card == entries[i + 1].card) {
            value = drawer.card->unkA;
            j++;
        } else if (j < 2) {
            j = 0;
        } else {
            break;
        }
    }
    if (j >= 2) {
        for (k = 0; k < count; k++) {
            battle->unk446[k] = 0;
        }
        for (; j >= 0; j--) {
            battle->unk446[entries[i - j].slot] = 1;
        }
        battle->unk438 = value;
        result = i + 1;
    }
    return result;
}

/* Opens the panels for a phase */
void CARDGAME_openPanelsPhase(CardBattle *battle, CardBattleItems *items) {
    items->screen->openPanels(items->screen);
    battle->unk498.unk5 = 1;
    battle->unk498.unk1 = 1;
    battle->unk2F9 = 0;
}

/* The end of a round: shows both sides' cards, gives the round to the higher total (pile.unk2) and the battle to the first side with two rounds; 1 for the next round, 2 once the battle is over */
s32 CARDGAME_endRound(CardBattle *battle, CardBattleItems *items) {
    CardScreen *screen = items->screen;
    s32 result = 0;
    CardFader *fader;
    s32 side;
    s32 done;

    switch (battle->unk2F9) {
    case 0:
        if (items->screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            battle->unk2F9 = 1;
            battle->unk2FC = 0;
        }
        break;
    case 1:
        battle->unk2FC = CARDGAME_findCardSet(battle, 0, battle->unk2FC);
        if (battle->unk2FC == -1) {
            battle->unk2F9 = 2;
            battle->unk2FC = 0;
        } else {
            battle->unk421 = 0x19;
            battle->unk2F4 = 1;
        }
        break;
    case 2:
        battle->unk2FC = CARDGAME_findCardSet(battle, 1, battle->unk2FC);
        if (battle->unk2FC == -1) {
            battle->unk2F9 = 8;
        } else {
            battle->unk421 = 0x1A;
            battle->unk2F4 = 1;
        }
        break;
    case 8:
        if (battle->unk304 != 0) {
            battle->unk421 = 0x1B;
            battle->unk2F4 = 1;
            battle->unk305--;
        }
        if (battle->unk305 == 0) {
            battle->unk2F9 = 9;
        } else {
            battle->unk2F9 = 8;
        }
        break;
    case 9:
        if (battle->players[0].slotCount == 0 || battle->players[1].slotCount == 0) {
            if (battle->sides[0].pile.unk2 > battle->sides[1].pile.unk2) {
                battle->roundWinner = 0;
            } else {
                battle->roundWinner = 1;
            }
            battle->unk2F9 = 11;
            if (battle->players[battle->roundWinner].slotCount == 0 && battle->players[battle->roundWinner ^ 1].slotCount != 0) {
                battle->unk2F9 = 10;
                battle->unk2FC = 0;
            }
        } else {
            battle->unk2F9 = 3;
            screen->openWindow(screen, 5, 5, 13, 0, 110);
        }
        break;
    case 3:
        if (screen->windows[5].state == 2) {
            battle->unk2F9 = 4;
        }
        break;
    case 4:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk2F9 = 5;
            screen->closeWindow(screen, 5);
        }
        break;
    case 5:
        if (screen->windows[5].state == 0) {
            battle->unk2F9 = 6;
        }
        break;
    case 6:
        battle->unk421 = 0x15;
        battle->unk2F4 = 1;
        battle->unk2F9 = 7;
        break;
    case 7:
        battle->unk421 = 0x16;
        battle->unk2F4 = 1;
        battle->unk2F9 = 10;
        battle->unk2FC = 0;
        break;
    case 10:
        if (battle->sides[0].pile.unk2 > battle->sides[1].pile.unk2) {
            battle->unk421 = 0x18;
            battle->roundWinner = 0;
        } else {
            battle->unk421 = 0x17;
            battle->roundWinner = 1;
        }
        battle->unk2F4 = 1;
        battle->unk2F9 = 11;
        battle->unk2FC = 0;
        break;
    case 11:
        side = battle->roundWinner;
        if (battle->unk2FC & 1) {
            items->screen->panels[side].unk44 = battle->sides[side].pile.unk12 + 1;
        } else {
            items->screen->panels[side].unk44 = battle->sides[side].pile.unk12;
        }
        if (battle->unk2FC == 0) {
            SOUND.playSound(0x9C0002);
            fader = CARDGAME_createFader(1);
            items->unk0[1] = fader;
            fader->setColor(fader, 0x80, 0x80, 0x80);
            ((CardFader *)items->unk0[1])->start(items->unk0[1], 0, 0, 0, 10, 1);
        }
        battle->unk2FC += GFX.funcs.getFrameTime();
        if (battle->unk2FC >= 51) {
            items->screen->panels[side].unk44 = battle->sides[side].pile.unk12 + 1;
            battle->sides[side].pile.unk12++;
            battle->unk2F9 = 12;
            if (battle->roundWinner == 0) {
                screen->openWindow(screen, 5, 5, 16, 0, 110);
            } else if (battle->sides[0].pile.unk2 != battle->sides[1].pile.unk2) {
                screen->openWindow(screen, 5, 5, 17, 0, 110);
            } else {
                screen->openMessage(screen, 18, 0, 0, 1);
            }
        }
        break;
    case 12:
        if (battle->sides[0].pile.unk2 != battle->sides[1].pile.unk2) {
            done = screen->windows[5].state == 2;
        } else {
            done = screen->message.state == 2;
        }
        if (done) {
            battle->unk2F9 = 13;
        }
        break;
    case 13:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            if (battle->sides[0].pile.unk2 != battle->sides[1].pile.unk2) {
                screen->closeWindow(screen, 5);
            } else {
                screen->closeMessage(screen);
            }
            battle->unk2F9 = 14;
        }
        break;
    case 14:
        if (battle->sides[0].pile.unk2 != battle->sides[1].pile.unk2) {
            done = screen->windows[5].state == 0;
        } else {
            done = screen->message.state == 0;
        }
        if (done) {
            battle->unk2F9 = 15;
            screen->openMessage(screen, 19, 0, 0, 1);
        }
        break;
    case 15:
        if (screen->message.state == 2) {
            battle->unk2F9 = 16;
        }
        break;
    case 16:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            screen->closeMessage(screen);
            battle->unk2F9 = 17;
        }
        break;
    case 17:
        if (screen->message.state == 0) {
            if (battle->sides[0].pile.unk12 >= 2) {
                SOUND.playSound(SOUND_WIN_JINGLE);
                screen->openWindow(screen, 5, 5, 21, 0, 110);
                battle->unk2F9 = 19;
                battle->unk302 = 0;
            } else if (battle->sides[1].pile.unk12 >= 2) {
                screen->openWindow(screen, 5, 5, 22, 0, 110);
                battle->unk2F9 = 19;
                battle->unk302 = 1;
            } else {
                battle->unk2F9 = 18;
            }
        }
        break;
    case 18:
        if (battle->roundWinner == 0) {
            battle->unk421 = 0x1C;
        } else {
            battle->unk421 = 0x1D;
        }
        battle->unk2F4 = 1;
        battle->unk2F9 = 26;
        break;
    case 19:
        if (screen->windows[5].state == 2) {
            battle->unk2F9 = 20;
        }
        break;
    case 20:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            if (battle->roundWinner == 0) {
                screen->closeWindow(screen, 5);
                battle->unk2F9 = 21;
                battle->unk4E8 = 0;
            } else {
                battle->unk2F9 = 25;
            }
        }
        break;
    case 21:
        if (screen->windows[5].state == 0 && CARDGAME_stepHidePanels(battle, items)) {
            battle->unk2F9 = 22;
            screen->openMessage(screen, battle->prize, 0, 0, 3);
        }
        break;
    case 22:
        if (screen->message.state == 2) {
            battle->unk2F9 = 23;
        }
        break;
    case 23:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk2F9 = 25;
        }
        break;
    case 25:
        result = 2;
        break;
    case 26:
        result = 1;
        break;
    }
    return result;
}

/* Puts pile's hand back on top of its deck */
void CARDGAME_returnHandToDeck(CardPile *pile) {
    while (pile->handCount > 0) {
        pile->deck[--pile->deckTop] = pile->hand[--pile->handCount];
        pile->deckCount++;
    }
}

/* Puts both hands back in the decks, shuffles the player's, clears the
   round's values and moves on to the next round (unk300) */
void CARDGAME_startNextRound(CardBattle *battle, CardBattleItems *items) {
    CardPile *pile = &battle->sides[0].pile;

    CARDGAME_returnHandToDeck(pile);
    CARDGAME_returnOpponentHand(battle, items);
#if VERSION_US
    CARDGAME_findOpponentDeckLimits(battle, items);
#endif
    battle->shufflePile(battle, pile->deckTop, pile->deckCount);
    battle->unk304 = 0;
    battle->unk305 = 0;
    battle->sides[0].pile.unk0 = 0;
    battle->sides[0].pile.unk2 = 0;
    battle->sides[1].pile.unk0 = 0;
    battle->sides[1].pile.unk2 = 0;
    CARDGAME_showPanelValues(battle, items);
    battle->unk300++;
#if VERSION_EU
    CARDGAME_findOpponentDeckLimits(battle, items);
#endif
}

/* Starts the step of battle message unk2F6 (CARDGAME_battleMessages) */
void CARDGAME_startBattleMessage(CardBattle *battle, CardBattleItems *items) {
    s32 i = battle->unk2F6;

    battle->unk2F4 = 1;
    battle->unk421 = CARDGAME_battleMessages[i].text;
    battle->unk2F7 = CARDGAME_battleMessages[i].unk2;
}

/* Sets up a card battle: the sides' panels, no result, phase 1 */
void CARDGAME_initBattle(CardBattle *battle, CardBattleItems *items) {
    battle->sides[0].pile.side = 0;
    battle->sides[1].pile.side = 1;
    battle->result = 0;
    battle->unk302 = 1;
    battle->unk2F8 = 1;
}

/* Runs the battle's current phase (unk2F8), after switching to the one asked for in unk2F7; 1 once the battle is over */
s32 CARDGAME_runPhase(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    if (battle->unk2F7 != 0) {
        switch (battle->unk2F7) {
        case 1:
        case 2:
            battle->unk2F9 = 0;
            battle->unk2FC = 0;
            break;
        case 3:
        case 4:
        case 6:
            battle->unk2F9 = 0;
            break;
        case 5:
        case 7:
            CARDGAME_prepareTurn(battle, items);
            break;
        case 8:
            CARDGAME_openPanelsPhase(battle, items);
            break;
        case 9:
            CARDGAME_startNextRound(battle, items);
            break;
        }
        battle->unk2F6 = battle->unk2F8;
        battle->unk2F8 = battle->unk2F7;
        battle->unk2F7 = 0;
    }
    switch (battle->unk2F8) {
    case 1:
        switch (battle->unk2F9) {
        case 0:
        default:
            items->screen->unkE9E = 1;
            battle->unk2F9 = 1;
            break;
        case 1:
            if (items->screen->unkE9E == 2) {
                battle->unk2F7 = 10;
            }
            break;
        }
        break;
    case 2:
        if (CARDGAME_chooseDeck(battle, items)) {
            battle->unk2F7 = 10;
        }
        break;
    case 3:
        if (CARDGAME_runFirstPick(battle, items)) {
            battle->unk2F7 = 10;
        }
        break;
    case 4:
        switch (CARDGAME_runStartStep(battle, items)) {
        case 1:
            battle->unk2F7 = 10;
            break;
        case 2:
            battle->unk302 = 1;
            done = 1;
            break;
        case 3:
            battle->unk302 = 0;
            done = 1;
            break;
        }
        break;
    case 5:
    case 7:
        if (CARDGAME_playRounds(battle, items)) {
            battle->unk2F7 = 10;
        }
        break;
    case 6:
        if (CARDGAME_runPutOut(battle, items)) {
            battle->unk2F7 = 10;
        }
        break;
    case 8:
        switch (CARDGAME_endRound(battle, items)) {
        case 1:
            battle->unk2F7 = 9;
            break;
        case 2:
            done = 1;
            break;
        }
        break;
    case 9:
        battle->unk2F7 = 10;
        break;
    case 10:
        CARDGAME_startBattleMessage(battle, items);
        break;
    }
    return done;
}

/* Opens the panels once; 1 once they are open */
s32 CARDGAME_stepShowPanels(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    if (battle->unk4E8 == 0) {
        battle->unk498.unk5 = 1;
        battle->unk498.unk1 = 1;
        items->screen->openPanels(items->screen);
        battle->unk4E8++;
    }
    if (items->screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
        done = 1;
    }
    return done;
}

/* Shows the last card played (record.entries) in window 2 for 35 frames (Cross cuts it short), then scales its sprite away; 1 once done */
s32 CARDGAME_showPlayedCard(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;
    s32 place;
    s32 i;

    switch (battle->unk4E8) {
    case 0:
        battle->unk4E8 = 1;
        battle->unk4EC = 0;
        place = battle->record.entries[battle->record.entryCount - 1].unk4;
#if VERSION_US
        items->screen->openWindow(items->screen, 2, 1, battle->cards[battle->record.entries[battle->record.entryCount - 1].unk0] + 1,
                              CARDGAME_playedCardPos[0][place].x, CARDGAME_playedCardPos[0][place].y);
#elif VERSION_EU
        items->screen->openWindow(items->screen, 2, 1, battle->cards[battle->record.entries[battle->record.entryCount - 1].unk0] + 1,
                              CARDGAME_playedCardPos[SHIFT_PAL_SCREEN][place].x, CARDGAME_playedCardPos[SHIFT_PAL_SCREEN][place].y);
#endif
        for (i = 0; i < 15; i++) {
            items->screen->sprites[i].moving = 0;
        }
        break;
    case 1:
        if (battle->unk4EC >= 20 && PAD_HELD(PAD_CROSS)) {
            battle->unk4EC = 35;
        }
        battle->unk4EC += GFX.funcs.getFrameTime();
        if (battle->unk4EC >= 35) {
            items->screen->closeWindow(items->screen, 2);
            items->screen->scaleSprite(items->screen, battle->record.entryCount + 11, 8, 0x1400, 0x1400);
            items->screen->closeGauge(items->screen, battle->record.entryCount - 1);
            battle->unk4E8 = 2;
            battle->unk4EC = 0;
            SOUND.playSound(0x8004603C);
        }
        break;
    case 2:
        battle->unk4EC += GFX.funcs.getFrameTime();
        if (battle->unk4EC >= 8) {
            items->screen->startBlink(items->screen, battle->record.entryCount + 11);
            battle->unk4E8 = 3;
            battle->unk4EC = 0;
        }
        break;
    case 3:
        battle->unk4EC += GFX.funcs.getFrameTime();
        if (battle->unk4EC >= 15) {
            items->screen->scaleSprite(items->screen, battle->record.entryCount + 11, 4, 0, 0);
            battle->unk4E8 = 5;
            battle->unk4EC = 0;
            SOUND.playSound(0x8004603C);
        }
        break;
    case 5:
        battle->unk4EC += GFX.funcs.getFrameTime();
        if (battle->unk4EC >= 15) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Plays out the last card played (record.entries): its effect and its messages, then puts it in its side's discards (pile.discards); 1 once done */
u8 CARDGAME_resolveCard(CardBattle *battle, CardBattleItems *items) {
    u8 done = 0;
    s16 card;
    s32 i;
    s32 text;
    s32 index;
    s32 side;
    s8 count;

    switch (battle->unk4DC) {
    case 0:
    default:
        if (CARDGAME_setAllCountingValues(battle)) {
            battle->unk421 = 0x5D;
            battle->unk2F4 = 1;
            battle->unk4DC = 1;
            break;
        }
        battle->unk4DC = 3;
    case 3:
        if (items->screen->panels[0].state == 0) {
            battle->unk4DC = 4;
        } else {
            battle->unk4DC = 5;
            battle->unk4EC = 0;
            battle->unk4E8 = 0;
            battle->unk4DD = 0;
        }
        break;
    case 1:
        battle->unk421 = 0x4C;
        battle->unk2F4 = 1;
        battle->unk4DC = 2;
        break;
    case 2:
        battle->unk421 = 0x5A;
        battle->unk2F4 = 1;
        battle->unk4DC = 3;
        break;
    case 4:
        if (CARDGAME_stepShowPanels(battle, items)) {
            battle->unk4DC = 5;
            battle->unk4EC = 0;
            battle->unk4E8 = 0;
            battle->unk4DD = 0;
        }
        break;
    case 5:
        if (CARDGAME_showPlayedCard(battle, items)) {
            battle->unk4DC = 6;
            battle->unk4EC = 0;
            battle->unk4E8 = 0;
        }
        break;
    case 6:
        card = battle->cards[battle->record.entries[battle->record.entryCount - 1].unk0];
        if (CARDGAME_checkPlayCondition(battle, items->screen, CARDGAME_getEffectField(card, 1, 0))) {
            items->screen->openMessage(items->screen, CARDGAME_getEffectField(card, 2, 0), 0, 1, 1);
            battle->unk4DC = 8;
        } else {
            battle->aiScore = 0;
            battle->unk4DC = 7;
        }
        break;
    case 7:
        text = CARDGAME_getEffectField(battle->cards[battle->record.entries[battle->record.entryCount - 1].unk0], 4, battle->aiScore);
        if (text != 0) {
            battle->unk421 = text;
            battle->unk2F4 = 1;
            battle->aiScore++;
        } else {
            if (battle->record.entryCount >= 2) {
                battle->record.entries[battle->record.entryCount - 2].unk2 = 0;
            }
            for (i = 0; i < 12; i++) {
                items->screen->sprites[i].unk3E[battle->record.entryCount - 1] = 0;
            }
            battle->unk4DC = 10;
        }
        break;
    case 8:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            items->screen->closeMessage(items->screen);
            battle->unk4DC = 9;
        }
        break;
    case 9:
        if (items->screen->message.state == 0) {
            battle->unk4DC = 12;
        }
        break;
    case 10:
        battle->unk421 = 0x5A;
        battle->unk2F4 = 1;
        battle->unk4DC = 11;
        break;
    case 11:
        battle->unk4DC = 12;
        break;
    case 12:
        index = battle->record.entries[battle->record.entryCount - 1].unk0;
        side = battle->record.entries[battle->record.entryCount - 1].unk4;
        if (battle->cards[index] != 13) {
            battle->sides[side].pile.discards[battle->sides[side].pile.discardCount] = index;
            battle->sides[side].pile.discardCount++;
        }
        count = battle->record.entryCount;
        battle->record.entryCount = count - 1;
        if (battle->unk4DD != 0) {
            battle->record.entryCount = count - 2;
        }
        battle->unk4DC = 13;
        battle->unk4EC = 0;
        battle->unk4E8 = 0;
        break;
    case 13:
        CARDGAME_showPanelValues(battle, items);
        battle->unk4DC = 14;
        break;
    case 14:
        if (CARDGAME_setAllCountingValues(battle)) {
            battle->unk421 = 0x5D;
            battle->unk2F4 = 1;
            battle->unk4DC = 15;
        } else {
            done = 1;
        }
        break;
    case 15:
        battle->unk421 = 0x4C;
        battle->unk2F4 = 1;
        battle->unk4DC = 16;
        break;
    case 16:
        battle->unk421 = 0x5A;
        battle->unk2F4 = 1;
        battle->unk4DC = 17;
        break;
    case 17:
        done = 1;
        break;
    }
    return done;
}

/* The battle menu (record.menuState its state): three help messages, back, and quitting after a yes/no question; 1 when closed, 2 to quit */
s32 CARDGAME_runBattleMenu(CardBattle *battle, CardBattleItems *items) {
    s32 result = 0;
    s32 cursor;

    switch (battle->record.menuState) {
    case 1:
    default:
        /* save the battle state and the screen's, restored in case 15 */
        *(CardBattleSave *)battle->unk4F0 = *(CardBattleSave *)&battle->unk420;
        battle->record.menuCursor = 0;
        CARDGAME_savedScreenState = items->screen->message;
        items->screen->openMenu(items->screen, 0);
        battle->record.menuState = 2;
        break;
    case 2:
        if (items->screen->menuState == 2) {
            battle->record.menuState = 3;
        }
        break;
    case 3:
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_UP))) |
            (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_UP)))) {
            cursor = battle->record.menuCursor - 1;
            if (cursor < 0) {
                cursor = 4;
            }
            battle->record.menuCursor = cursor;
            SOUND.playSound(SOUND_CURSOR);
        } else if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_DOWN))) |
                   (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_DOWN)))) {
            battle->record.menuCursor = (u8)(battle->record.menuCursor + 1) % 5;
            SOUND.playSound(SOUND_CURSOR);
        }
        if (PAD_PRESSED(PAD_CROSS)) {
            items->screen->confirmMenu(items->screen);
            battle->record.menuState = 4;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            items->screen->closeMenu(items->screen);
            battle->record.menuState = 4;
            battle->record.menuCursor = 3;
        }
        items->screen->setMenuRow(items->screen, battle->record.menuCursor);
        break;
    case 4:
        if (items->screen->menuState == 0) {
            switch (battle->record.menuCursor) {
            case 0:
                battle->record.menuState = 5;
                break;
            case 1:
                battle->record.menuState = 6;
                break;
            case 2:
                battle->record.menuState = 7;
                break;
            case 3:
                battle->record.menuState = 15;
                break;
            case 4:
                items->screen->openMessage(items->screen, 0x2C, 1, 0, 1);
                battle->record.menuState = 8;
                break;
            }
        }
        break;
    case 5:
        battle->unk421 = 0x9B;
        battle->unk2F4 = 1;
        battle->record.menuState = 11;
        break;
    case 6:
        battle->unk421 = 0xA8;
        battle->unk2F4 = 1;
        battle->record.menuState = 12;
        break;
    case 7:
        battle->unk421 = 0x9C;
        battle->unk2F4 = 1;
        battle->record.menuState = 13;
        break;
    case 8:
        if (items->screen->message.state == 2) {
            battle->record.menuState = 9;
        }
        break;
    case 9:
        if (PAD_PRESSED(PAD_CROSS)) {
            items->screen->confirmMessage(items->screen);
            battle->record.menuState = 10;
        } else if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_UP))) |
                   (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_UP)))) {
            if (items->screen->message.choice != 0) {
                SOUND.playSound(SOUND_CURSOR);
            }
            items->screen->message.choice = 0;
        } else if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_DOWN))) |
                   (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_DOWN)))) {
            if (items->screen->message.choice != 1) {
                SOUND.playSound(SOUND_CURSOR);
            }
            items->screen->message.choice = 1;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            items->screen->message.choice = 1;
            items->screen->confirmMessage(items->screen);
            items->screen->message.choice = 1;
            battle->record.menuState = 10;
        }
        break;
    case 10:
        if (items->screen->message.state == 0) {
            if (items->screen->message.choice == 0) {
                result = 2;
            } else {
                battle->record.menuState = 14;
            }
        }
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        items->screen->openMenu(items->screen, battle->record.menuCursor);
        battle->record.menuState = 2;
        break;
    case 15:
        *(CardBattleSave *)&battle->unk420 = *(CardBattleSave *)battle->unk4F0;
        result = 1;
        items->screen->message = CARDGAME_savedScreenState;
        battle->record.menuState = 0;
        break;
    }
    return result;
}

/* A frame of the card battle: the sprites' flags, the card animations, the
   fades, then the phase, the effect step, the card's resolution or the battle
   menu; 1 once it is over */
s32 CARDGAME_runBattle(CardBattle *battle, CardBattleItems *items) {
    s32 done = 0;

    CARDGAME_resetSpriteFlags(battle);
    CARDGAME_updateCardAnims(battle, items);
    CARDGAME_startStepFade(battle, items);
    switch (battle->unk2F4) {
    case 0:
    default:
        if (CARDGAME_runPhase(battle, items)) {
            done = 1;
        }
        break;
    case 1:
        CARDGAME_runEffectStep(battle, items->screen);
        break;
    case 2:
        if (CARDGAME_resolveCard(battle, items)) {
            battle->unk2F4 = 0;
        }
        break;
    case 3:
        switch (CARDGAME_runBattleMenu(battle, items)) {
        case 1:
            battle->unk2F4 = 1;
            break;
        case 2:
            done = 1;
            break;
        }
        break;
    }
    return done;
}

/* The card battle task: sets up the battle and fades in, runs it (CARDGAME_runBattle), then fades out and gives the player the prize item for a win; result 2 once over */
void CARDGAME_updateBattle(CardBattle *battle, CardBattleItems *items) {
    TimLoader tim;
    CardFader *fader;

    switch (battle->state) {
    case 0:
    default:
        if (SOUND.isLoading() == 0) {
            FILE_CACHE.load(FILE_CARDGAME_TIMS);
            CARDGAME_initBattle(battle, items);
            CARDGAME_loadOpponent(battle, items);
            items->screen = CARDGAME_createScreen(battle->cards);
            items->unk0[0] = CARDGAME_startPreloader();
            items->screen->resetPanels(items->screen);
            items->screen->unk5E = battle->unk2E9;
            items->screen->unk5C = battle->arg;
            initTimLoader(&tim);
            tim.setImagePos(0x280, 0);
            tim.loadArchive(FILE_CACHE.getEntry(FILE_CARDGAME_TIMS << 16));
            fader = CARDGAME_createFader(2);
            items->unk0[1] = fader;
            fader->setColor(fader, 0xFF, 0xFF, 0xFF);
            ((CardFader *)items->unk0[1])->start(items->unk0[1], 0, 0, 0, 100, 0);
            battle->setState(battle, 2);
            SOUND.playSound(0x609C0004);
        }
        break;
    case 1:
        if (CARDGAME_runBattle(battle, items)) {
            fader = CARDGAME_createFader(2);
            items->unk0[1] = fader;
            fader->setColor(fader, 0, 0, 0);
            ((CardFader *)items->unk0[1])->start(items->unk0[1], 0xFF, 0xFF, 0xFF, 100, 0);
            battle->setState(battle, 2);
            battle->result = 1;
        }
        break;
    case 2:
        if (battle->substate == 0 && ((CardFader *)items->unk0[1])->isDone(items->unk0[1])) {
            ((CardFader *)items->unk0[1])->kill(items->unk0[1]);
            if (battle->result != 0) {
                if (battle->result != 2) {
                    if (battle->unk302 == 0) {
                        if (GAME.items[battle->prize] < 99) {
                            GAME.items[battle->prize]++;
                        }
                        FLAGS_00.pendingFlag10 = 1;
                    } else {
                        FLAGS_00.pendingFlag10 = 0;
                    }
                }
                battle->result = 2;
            } else {
                battle->setState(battle, 1);
            }
            battle->substate = 1;
        }
        break;
    case 3:
        if (battle->unk302 == 0) {
            SOUND.stopSound(SOUND_WIN_JINGLE);
        } else {
            SOUND.stopSound(0x609C0004);
        }
        break;
    }
}

CardBattle *CARDGAME_createBattle(s32 arg) {
    CardBattle *battle = createTask(CARDGAME_updateBattle, sizeof(CardBattle), 7 * 4);

    battle->shufflePile = CARDGAME_shufflePile;
    battle->sortCards = CARDGAME_sortCards;
    battle->putOutCards = CARDGAME_putOutCards;
    battle->addCard = CARDGAME_addCard;
    battle->unk820 = CARDGAME_scoreHand;
    battle->arg = arg;
    SOUND.loadBank(0x27);
    return battle;
}

/* Draws the fader over RECT, in layer 0x100 */
void CARDGAME_drawFader(CardFader *fader, RECT rect) {
    Layer *layer = GFX.funcs.getLayer(0x100);
    u_long *ot = (u_long *)layer->getOtEntry(layer, 0);
    POLY_F4 *poly = GFX.funcs.getPrim();
    DR_TPAGE *mode;

    poly->r0 = fader->color[0];
    poly->g0 = fader->color[1];
    poly->b0 = fader->color[2];
    setlen(poly, 5);
    poly->code = 0x2A;
    poly->x0 = rect.x;
    poly->x1 = rect.x + rect.w;
    poly->x2 = rect.x;
    poly->x3 = rect.x + rect.w;
    poly->y0 = rect.y;
    poly->y1 = rect.y;
    poly->y2 = rect.y + rect.h;
    poly->y3 = rect.y + rect.h;
    addPrim(ot, poly);
    mode = (DR_TPAGE *)(poly + 1);
    setlen(mode, 1);
    mode->code[0] = ((fader->blend & 3) << 5) | 0xE1000205;
    addPrim(ot, mode);
    GFX.funcs.setPrim(mode + 1);
}

/* Moves the colour towards the target as the time runs out */
void CARDGAME_stepFader(CardFader *fader) {
    s32 i;

    fader->time -= GFX.funcs.getFrameTime();
    if (fader->time > 0) {
        for (i = 0; i < 3; i++) {
            fader->color[i] = fader->target[i] - (fader->target[i] - fader->from[i]) * fader->time / fader->duration;
        }
        return;
    }
    if (fader->killWhenDone != 0) {
        fader->mode = 2;
        return;
    }
    fader->mode = 0;
    fader->color[0] = fader->target[0];
    fader->color[1] = fader->target[1];
    fader->color[2] = fader->target[2];
}

/* Sets the colour at once */
void CARDGAME_setFaderColor(CardFader *fader, u8 r, u8 g, u8 b) {
    fader->color[0] = r;
    fader->color[1] = g;
    fader->color[2] = b;
}

/* Fades from the current colour to r, g, b in FRAMES vsyncs; the task
   ends at the end when KILLWHENDONE is set */
void CARDGAME_startFade(CardFader *fader, u8 r, u8 g, u8 b, s32 frames, s32 killWhenDone) {
    s32 i;

    for (i = 0; i < 3; i++) {
        fader->from[i] = fader->color[i];
    }
    fader->target[0] = r;
    fader->target[1] = g;
    fader->target[2] = b;
    fader->time = frames;
    fader->duration = frames;
    fader->mode = 1;
    fader->killWhenDone = killWhenDone;
}

/* 1 once the fade has reached its colour */
s32 CARDGAME_isFadeDone(CardFader *fader) {
    return fader->mode == 0;
}

/* Ends the task */
void CARDGAME_killFader(CardFader *fader) {
    fader->mode = 2;
}

void CARDGAME_tickFader(CardFader *fader) {
    switch (fader->state) {
    case 0:
    default:
        fader->nextState(fader);
        break;
    case 1:
        if (fader->mode == 1) {
            CARDGAME_stepFader(fader);
        }
        CARDGAME_drawFader(fader, CARDGAME_fadeRect);
        if (fader->mode == 2) {
            fader->setState(fader, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/* Creates a fader, with the semi-transparency rate BLEND */
CardFader *CARDGAME_createFader(u8 blend) {
    CardFader *fader = createTask(CARDGAME_tickFader, sizeof(CardFader), 4);

    fader->setColor = CARDGAME_setFaderColor;
    fader->start = CARDGAME_startFade;
    fader->isDone = CARDGAME_isFadeDone;
    fader->blend = blend;
    fader->kill = CARDGAME_killFader;
    return fader;
}

/* The data: the rest of the overlay's, this object's tables and the
   variables, which cardgame_2.c shares */
RECT CARDGAME_screenRect = {0, 0, 320, 240};
/* where the deck window's six counts are */
CardOffset CARDGAME_deckCountOffsets[] = {
    {0x24, 0x14}, {0x47, 0x14}, {0x6A, 0x14}, {0x8D, 0x14}, {0xB0, 0x14}, {0xD3, 0x14},
};
#if VERSION_EU
s32 CARDGAME_slotRowPositions[2][4] = {
    {0x1800, 0x9000, 0x1800, 0x3200},
    {0x1800, 0x9C00, 0x1800, 0x2600},
};
#endif
/* where the three CardGauge gauges are */
CardOffset CARDGAME_gaugePositions[] = {
    {0x49, 0x61}, {0x7B, 0x61}, {0xAD, 0x61},
};
CardWindowLayout CARDGAME_windowLayouts[] = {
    {0x00, 0x0A, 0x02, 2}, {0xBE, 0x0A, 0x03, 2}, {0xBE, 0x18, 0x04, 2},
    {0x43, 0x18, 0x05, 2}, {0x00, 0x1E, 0x37, 2}, {0x140, 0x0A, 0x19, 1},
};
u16 CARDGAME_windowTextOffsets[] = {
    0x0004, 0x0018, 0x0049, 0x0000,
};
s32 CARDGAME_messageWindowPositions[][2] = {{0, 138}, {0, 96}, {0, 50}, {0, 96}};
CardPanelLayout CARDGAME_panelLayouts[2] = {
    {0x1, 0xE, 0x11, 0x2F, {17, 69}, {38, 71}, {249, 71}, {291, 71}, {1, -15}, {30, 52}, {46, 52},
     {78, 52}, {94, 52}, {228, 69}, {270, 69}, {-7, -22}, {11, 67}, {222, 64}, {264, 64}, {-6, -20},
     {23, 48}, {71, 48}},
    {0x1, 0xF, 0x14, 0x30, {17, 14}, {38, 16}, {249, 16}, {291, 16}, {1, 21}, {30, 35}, {46, 35},
     {78, 35}, {94, 35}, {228, 14}, {270, 14}, {-7, -6}, {11, 12}, {222, 9}, {264, 9}, {-6, -5},
     {23, 31}, {71, 31}},
};
u8 CARDGAME_panelLightCluts[8] = {0, 1, 2, 3, 2, 1, 0, 0};
u8 CARDGAME_panelBarSprites[8][2] = {
    {0x4D, 0x56}, {0x4E, 0x57}, {0x4F, 0x58}, {0x50, 0x59},
    {0x52, 0x5B}, {0x51, 0x5A}, {0x53, 0x5C}, {0, 0},
};
u8 CARDGAME_flag7Frames[] = {
    0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
};
u8 CARDGAME_flag6Frames[] = {
    0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
};
u8 CARDGAME_boxFrames[] = {
    0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
};
u8 CARDGAME_flagIconSprites[] = {
    0x1D, 0x20, 0x23, 0x26, 0x29, 0x00, 0x00, 0x00,
};
u8 CARDGAME_flagIconFrames[] = {
    0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
};
#if VERSION_EU
CardOffset CARDGAME_panelIconPositions[2][2][2] = {
    {{{0x7C, 0x33}, {0x7C, 0x23}}, {{0x8A, 0x34}, {0x8A, 0x24}}},
    {{{0x7C, 0x3F}, {0x7C, 0x17}}, {{0x8A, 0x40}, {0x8A, 0x18}}},
};
#endif
s16 CARDGAME_shakeOffsets[] = {
    -0x100, 0x300, -0x300, 0x100,
};
s16 CARDGAME_jitterOffsets[] = {
    -0x400, 0x200, -0x200, 0x400,
};
s32 CARDGAME_pictureSheet[] = {
    12, 28, 32, 0x7C00A0,
    0x2E0028, 0xFC0020, 0, 65280,
    1, 65535, 0,
};
u8 CARDGAME_loopFrames[] = {
    0x00, 0x01, 0x02, 0x03,
};
u8 CARDGAME_onceFrames[] = {
    0x00, 0x01, 0x02, 0x03,
};
u8 CARDGAME_highlightCluts[] = {
    0x00, 0x01, 0x02, 0x03, 0x02, 0x01, 0x00, 0x00,
};
s16 CARDGAME_otherCards[] = {
    0x003C, 0x003D, 0x003E, 0x0040, 0x0041, 0x0042, 0x0043, 0x0046,
    0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x0067, 0x0068,
    0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x0070, 0x0071,
    0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079,
    0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x009A, 0x009B,
    0x009C, 0x009D, 0x009E, 0x009F, 0x00A0, 0x00A1, 0x00A2, 0x00A3,
    0x00A4, 0x00BD, 0x00BE, 0x00BF, 0x00C0, 0x00C2, 0x00C3, 0x00C4,
    0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CD,
    0x00CE, 0x00CF, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00ED, 0x00EE,
    0x00EF, 0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6,
    0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x0113, 0x0114, 0x0118, 0x0119,
    0x011A, 0x011B, 0x011C, 0x011D, 0x011E, 0x011F, 0x0120, 0x0121,
    0x0122, 0x0124, 0x0125, 0x013A,
};
/* the cards everyone has, after the two decks in the card list */
s16 CARDGAME_commonCards[] = {
    0x050, 0x063, 0x08C, 0x0B8, 0x0E5, 0x0FB, 0x139, 0x13A, 0x13B,
#if VERSION_US
    0x2D2D,
#elif VERSION_EU
    0x0A0D,
#endif
};
CardFileEntry CARDGAME_preloadFiles[] = {
    { 0x2B, 1 },
    { 0x0F, 1 },
#if VERSION_US
    { 2023, 0 },
    { 2024, 0 },
    { 2025, 0 },
    { 2026, 0 },
    { 2027, 0 },
#elif VERSION_EU
    { 2038, 0 },
    { 2039, 0 },
    { 2040, 0 },
    { 2041, 0 },
    { 2042, 0 },
#endif
    { -2, 0 },
    { 0x1D, 1 },
    { 0x16, 1 },
    { 0x6A, 1 },
    { -1, 0 },
};
s16 CARDGAME_countingCards[] = {
    0x0044, 0x006F, 0x009A, 0x00C5, 0x00F0, 0x0000,
};
s16 CARDGAME_prizeItems[] = {
    0x005B, 0x005B, 0x0169, 0x016A, 0x016B, 0x016C, 0x016D, 0x016E,
    0x016F, 0x0170, 0x0171, 0x0172, 0x0173, 0x0174, 0x0175, 0x0176,
    0x0177, 0x0178, 0x0179, 0x017A, 0x017B, 0x017C, 0x017D, 0x017E,
    0x017F, 0x0180, 0x0181, 0x0182, 0x0183, 0x0184, 0x0185, 0x0186,
    0x0187, 0x0188, 0x0189, 0x018A,
};
u16 CARDGAME_defaultDeck[] = {
    0x0138, 0x002A, 0x002B, 0x0136, 0x0136, 0x0136, 0x0021, 0x0021,
    0x0050, 0x0029, 0x0031, 0x0031, 0x0031, 0x0031, 0x0031, 0x0031,
    0x0031, 0x0031, 0x0031, 0x0031, 0x0009, 0x0009, 0x0009, 0x0009,
    0x0009, 0x0009, 0x0009, 0x0009, 0x0009, 0x0009, 0x0006, 0x0006,
    0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006,
    0x0029, 0x0029, 0x0050, 0x0015, 0x0007, 0x001A, 0x0008, 0x0029,
    0x0002, 0x0008, 0x002E, 0x000D, 0x000D, 0x000D, 0x0036, 0x0050,
    0x000B, 0x000B, 0x0024, 0x000B, 0x0019, 0x000B, 0x0019, 0x001F,
    0x0050, 0x0028, 0x0014, 0x0050, 0x0050, 0x0050, 0x0050, 0x0001,
    0x0001, 0x0139, 0x0023, 0x0018, 0x0018, 0x0050, 0x003B, 0x003A,
};
CardFadeColor CARDGAME_fadeColors[] = {
    { 0x80, 0x80, 0x80, 1 }, { 0x00, 0x00, 0x80, 1 }, { 0x00, 0x80, 0x00, 1 },
    { 0x80, 0x00, 0x00, 1 }, { 0x80, 0x80, 0x80, 2 }, { 0x80, 0x80, 0x00, 1 },
};
s16 CARDGAME_animPiles[7][2] = {{0, 0}, {1, 1}, {1, 2}, {1, 0}, {0, 1}, {0, 2}, {0, 0}};
CardOffset CARDGAME_deckWindowPos[3] = {{0x17, 0x50}, {0x17, 0x7D}, {0x17, 0xAA}};
u8 CARDGAME_turnStates[] = {
    0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
};
CardBattleMessage CARDGAME_battleMessages[] = {
    {0x00, 0}, {0xA6, 2}, {0xA0, 3}, {0xA1, 4}, {0xA2, 5},
    {0xA3, 6}, {0xA4, 7}, {0xA5, 8}, {0xA0, 3}, {0xA0, 3},
};
CardOffset CARDGAME_playedCardPos[2][2] = {{{0x82, 0xBF}, {0x82, 0x1D}}, {{0x82, 0xCB}, {0x82, 0x11}}};
RECT CARDGAME_fadeRect = {0, -15, 320, 260};
s32 CARDGAME_promptText = 0;
s16 CARDGAME_savedPanelScales[2] = {0, 0};
s32 CARDGAME_selectionText = 0;
u8 CARDGAME_slotMoves[2][6][2] = {{{0}}};
/* per side, the entries of CARDGAME_slotMoves, then (CARDGAME_markedCounts,
   a symbol of its own) the marked slots; the rest is not used */
u8 CARDGAME_slotMoveCounts[8] = {0};
CardMessageWindow CARDGAME_savedScreenState = {0};
