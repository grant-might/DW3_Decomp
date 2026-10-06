/* The second object of CARDGAME.PRO (see cardgame.c), from CARDGAME_sortOpponentCards
   (USA): its rodata starts at 0x80082A04, 4 bytes past a multiple of 8. */

#include "cardgame.h"

/* Sorts the opponent's cards by unk30A[].unk0, then swaps card unk440 to unk41C */
void CARDGAME_sortOpponentCards(CardBattle *battle) {
    CardBattle30A tmp;
    s16 *cards = battle->sides[1].pile.deck;
    s16 card;
    s32 i;
    s32 j;
    s32 target;

    for (i = battle->sides[1].pile.deckTop; i < 39; i++) {
        for (j = i + 1; j < 40; j++) {
            if (battle->unk30A[i].unk0 > battle->unk30A[j].unk0) {
                card = cards[i];
                cards[i] = cards[j];
                cards[j] = card;
                tmp = battle->unk30A[i];
                battle->unk30A[i] = battle->unk30A[j];
                battle->unk30A[j] = tmp;
            }
        }
    }
    target = battle->unk41C;
    tmp = battle->unk30A[battle->unk440];
    battle->unk30A[battle->unk440] = battle->unk30A[target];
    battle->unk30A[target] = tmp;
    card = cards[battle->unk440];
    cards[battle->unk440] = cards[target];
    cards[target] = card;
    battle->unk440 = target;
}

/* Whether card index can be played in this phase by its kind: phase 7 any
   kind but 0, phase 5 kind 2 */
s32 CARDGAME_canPlayCardKind(CardBattle *battle, s32 index) {
    CardDrawer drawer;
    s32 result = 0;
    s32 kind;

    initCardDrawer(&drawer);
    drawer.setCard(battle->cards[index] + 1);
    kind = drawer.getKind();
    if (kind != 0) {
        if (battle->unk2F8 == 7 || (battle->unk2F8 == 5 && kind == 2)) {
            result = 1;
        }
    }
    return result;
}

/* Whether a card can be played: in phase 6 a kind 0x10 card needs as many
   points of its colour (points), otherwise CARDGAME_canPlayCardKind */
s32 CARDGAME_canPlayCard(CardBattle *battle, u8 *arg1, s32 card) {
    CardDrawer drawer;
    s32 result = 0;

    if (battle->unk2F8 == 6) {
        initCardDrawer(&drawer);
        drawer.setCard(battle->cards[card] + 1);
        if (drawer.card->kind == 0x10) {
            result = arg1[drawer.card->color - 1] >= drawer.card->points;
        }
    } else {
        result = CARDGAME_canPlayCardKind(battle, card);
    }
    return result;
}

/* A position of CARDGAME_stepWindowPositions */
s16 CARDGAME_getStepWindowPos(s32 a, s32 b, s32 c) {
#if VERSION_US
    return CARDGAME_stepWindowPositions[0][a][b][c];
#elif VERSION_EU
    return CARDGAME_stepWindowPositions[SHIFT_PAL_SCREEN][a][b][c];
#endif
}

/* Opens the windows of the step CARDGAME_windowSteps[step] once its time is past; the next step */
s32 CARDGAME_openStepWindows(CardBattle *battle, CardScreen *screen, s32 layout, s32 text, s32 time, s32 step) {
    if (CARDGAME_windowSteps[step].time < time) {
        switch (CARDGAME_windowSteps[step].kind) {
        case 0:
            screen->openWindow(screen, 2, 1, 0, CARDGAME_getStepWindowPos(layout, 0, 0), CARDGAME_getStepWindowPos(layout, 0, 1));
            screen->openWindow(screen, 4, 2, 0, CARDGAME_getStepWindowPos(layout, 1, 0), CARDGAME_getStepWindowPos(layout, 1, 1));
            if (text != 0) {
                screen->openWindow(screen, 0, 0, text, 0, 0x42);
            }
            if (battle->unk420 == 0x9A) {
                screen->openWindow(screen, 5, 4, 0x24, 0, 0x14);
            }
            break;
        case 1:
            screen->openWindow(screen, 3, 1, 0, CARDGAME_getStepWindowPos(layout, 2, 0), CARDGAME_getStepWindowPos(layout, 2, 1));
            break;
        case 2:
            screen->openWindow(screen, 1, 3, 0, CARDGAME_getStepWindowPos(layout, 3, 0), CARDGAME_getStepWindowPos(layout, 3, 1));
            break;
        }
        if (step < 3) {
            step++;
        }
    }
    return step;
}

/* Opens the panels and asks message value; the European version starts on the
   second choice when none of the player's hand can be played */
void CARDGAME_startQuestion(CardBattle *battle, CardScreen *screen, s32 value) {
#if VERSION_EU
    s32 i;
    s32 found;
#endif

    battle->unk440 = 0;
    battle->stepState = 0;
    if (screen->panels[0].state == 0) {
        battle->unk498.unk5 = 1;
        battle->unk498.unk1 = 1;
        screen->openPanels(screen);
    }
    battle->unk424 = 0;
    screen->message.message = value;
#if VERSION_US
    screen->message.choice = 0;
    screen->message.place = 0;
#elif VERSION_EU
    screen->message.place = 0;
    found = 0;
    for (i = 0; i < battle->sides[0].pile.handCount; i++) {
        if (CARDGAME_canPlayCard(battle, battle->sides[0].pile.points, battle->sides[0].pile.hand[i])) {
            found = 1;
            break;
        }
    }
    if (found) {
        screen->message.choice = 0;
        battle->unk440 = 0;
        battle->unk438 = 2;
    } else {
        screen->message.choice = 1;
        battle->unk440 = 1;
        battle->unk438 = 3;
    }
#endif
}

/* Runs the yes/no window that CARDGAME_startQuestion sets up: 1 for the first choice, 2 for the second, 0 until then */
s32 CARDGAME_stepYesNo(CardBattle *battle, CardScreen *screen) {
    s32 result = 0;

    switch (battle->stepState) {
    case 0:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 36 && battle->unk498.unk0 == 0) {
#if VERSION_US
            battle->stepState = 1;
            battle->unk424 = 0;
            screen->openMessage(screen, screen->message.message, 1, screen->message.choice, screen->message.place);
#elif VERSION_EU
            battle->unk424 = 0;
            if (battle->record.entryCount != 0 && battle->unk438 == 3) {
                battle->stepState = 8;
            } else {
                battle->stepState = 1;
                screen->openMessage(screen, screen->message.message, battle->unk438, screen->message.choice, screen->message.place);
            }
#endif
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS)) {
            screen->confirmMessage(screen);
            battle->stepState = 7;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk440 = 1;
            screen->setMessageChoice(screen, 1);
            screen->confirmMessage(screen);
            battle->stepState = 7;
#if VERSION_US
        } else if (PAD_PRESSED(PAD_UP) || PAD_PRESSED(PAD_DOWN)) {
#elif VERSION_EU
        } else if ((PAD_PRESSED(PAD_UP) || PAD_PRESSED(PAD_DOWN)) && battle->unk438 == 2) {
#endif
            SOUND.playSound(SOUND_CURSOR);
            battle->unk440 ^= 1;
            screen->setMessageChoice(screen, battle->unk440);
        } else if ((!PAD_HELD(PAD_R1) && PAD_PRESSED(PAD_L1)) || (!PAD_HELD(PAD_L1) && PAD_PRESSED(PAD_R1))) {
            screen->closeMessage(screen);
            battle->stepState = 6;
        } else if (PAD_PRESSED(PAD_CIRCLE)) {
            screen->closeMessage(screen);
            battle->unk424 = 0;
            battle->stepState = 3;
        }
        break;
    case 6:
        if (screen->message.state == 0) {
            screen->message.place ^= 2;
#if VERSION_US
            screen->openMessage(screen, screen->message.message, 1, screen->message.choice, screen->message.place);
#elif VERSION_EU
            screen->openMessage(screen, screen->message.message, battle->unk438, screen->message.choice, screen->message.place);
#endif
            battle->stepState = 1;
        }
        break;
    case 7:
        if (screen->message.state == 0) {
            if (battle->unk440 == 0) {
                battle->stepState = 9;
                battle->unk498.unk1 = 2;
                screen->closePanels(screen);
            } else {
                battle->stepState = 8;
            }
        }
        break;
    case 3:
        switch (battle->unk424) {
        case 0:
            if (screen->message.state == 0) {
                battle->unk498.unk1 = 2;
                screen->closePanels(screen);
                battle->unk424 = 1;
            }
            break;
        case 1:
            if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
                battle->unk2F4 = 3;
                battle->record.unk0[8] = 0;
                battle->stepState = 4;
            }
            break;
        }
        break;
    case 4:
        battle->unk498.unk5 = 1;
        battle->unk498.unk1 = 1;
        screen->openPanels(screen);
        battle->stepState = 5;
        battle->unk424 = 0;
        break;
    case 5:
        switch (battle->unk424) {
        case 0:
            if (battle->unk498.unk0 == 0 && screen->panels[0].state == 2) {
#if VERSION_US
                screen->openMessage(screen, screen->message.message, 1, screen->message.choice, screen->message.place);
#elif VERSION_EU
                screen->openMessage(screen, screen->message.message, battle->unk438, screen->message.choice, screen->message.place);
#endif
                battle->unk424 = 1;
            }
            break;
        case 1:
            if (screen->message.state == 2) {
                battle->stepState = 2;
            }
            break;
        }
        break;
    case 1:
        if (screen->message.state == 2) {
            battle->stepState = 2;
        }
        break;
    case 9:
        if (screen->panels[0].state != 0 || battle->unk498.unk0 != 0) {
            break;
        }
    case 8:
        result = 2;
        if (battle->unk440 == 0) {
            result = 1;
        }
        break;
    }
    return result;
}

/* Empties the card information windows 1-4 */
void CARDGAME_clearCardInfo(CardBattle *battle, CardScreen *screen) {
    screen->windows[1].unkE = 0;
    screen->windows[1].unk10 = 0;
    screen->windows[2].unk10 = 0;
    screen->windows[3].unk10 = 0;
    screen->windows[4].unk10 = 0;
}

/* Fills the information windows with the card of sprite offset + unk43C (the
   highlighted one): its colour, name, picture or values, and kind */
void CARDGAME_showCardInfo(CardBattle *battle, CardScreen *screen, s32 offset) {
    CardDrawer drawer;
    s32 i;
    s32 found;
    s32 card;
    s32 id;

    CARDGAME_clearCardInfo(battle, screen);
    if (screen->sprites[offset + battle->unk43C].isKind16 != 0) {
        screen->windows[1].unk10 |= screen->sprites[offset + battle->unk43C].unk41;
        screen->windows[1].unk10 |= screen->sprites[offset + battle->unk43C].color << 4;
        screen->windows[1].unkE = 1;
    }
    found = 0;
    if (screen->sprites[offset + battle->unk43C].visible != 3) {
        card = battle->cards[screen->sprites[offset + battle->unk43C].index] + 1;
        screen->windows[2].unk10 = card;
        for (i = 0; i < 5; i++) {
            if (CARDGAME_countingCards[i] == battle->cards[screen->sprites[offset + battle->unk43C].index]) {
                found = 1;
            }
        }
        if (screen->sprites[offset + battle->unk43C].isKind16 != 0 && found == 0) {
            screen->windows[4].unk10 = 500;
            screen->windows[4].unk14[2] = 1;
            screen->windows[4].unk14[0] = screen->sprites[offset + battle->unk43C].unk43;
            screen->windows[4].unk14[1] = screen->sprites[offset + battle->unk43C].unk44;
        } else {
            screen->windows[4].unk14[2] = 0;
            screen->windows[4].unk10 = card;
        }
        id = battle->cards[screen->sprites[offset + battle->unk43C].index];
        initCardDrawer(&drawer);
        drawer.setCard(id + 1);
        switch (drawer.card->unk6) {
        case 0:
            screen->windows[3].unk10 = 0;
            break;
        case 1:
            screen->windows[3].unk10 = 0x25;
            break;
        case 2:
            screen->windows[3].unk10 = 0x26;
            break;
        case 3:
            screen->windows[3].unk10 = 0x27;
            break;
        case 4:
            screen->windows[3].unk10 = 0x28;
            break;
        case 5:
            screen->windows[3].unk10 = 0x29;
            break;
        }
    } else {
        screen->windows[4].unk14[2] = 0;
        screen->windows[4].unk10 = 500;
    }
}

/* CARDGAME_showCardInfo for the highlighted card of a row (kind 0, 1 or 2, as
   CARDGAME_moveTableHighlight) */
void CARDGAME_showTableCardInfo(CardBattle *battle, CardScreen *screen, s32 kind) {
    s32 offset = 0;

    switch (kind) {
    case 1:
        offset = 6;
        break;
    case 2:
        offset = 12;
        break;
    }
    CARDGAME_showCardInfo(battle, screen, offset);
}

/* Starts a pick from pile's hand: flags (unk446) the cards that can be
   played, and opens the player's panel */
void CARDGAME_startHandPick(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    s32 i;

    if (pile->handCount != 0) {
        for (i = 0; i < 40; i++) {
            battle->unk446[i] = 0;
            battle->unk46F[i] = 0;
            if (i < pile->handCount) {
                if (CARDGAME_canPlayCard(battle, pile->points, pile->hand[i])) {
                    battle->unk446[i] = 1;
                    battle->unk498.unk6[i] = 0;
                } else {
                    battle->unk498.unk6[i] = 1;
                }
            }
        }
    } else {
        battle->unk498.unk6[0] = 0;
    }
    screen->resetPanels(screen);
    if (pile->side == 0) {
        battle->unk498.unk1 = 5;
        screen->openPanel(screen, pile->side);
    } else {
        battle->unk498.unk1 = 11;
    }
    battle->unk423 = 1;
    CARDGAME_clearCardInfo(battle, screen);
    battle->unk43C = 0;
    battle->unk440 = -1;
}

/* Starts a pick of the cards (all when all > 0) in mode arg3 (unk498.unk1) */
void CARDGAME_startPick(CardBattle *battle, CardScreen *screen, s32 all, s32 arg3) {
    s32 i;

    if (all > 0) {
        for (i = 0; i < 40; i++) {
            battle->unk498.unk6[i] = 0;
        }
    } else {
        battle->unk498.unk6[0] = 0;
    }
    CARDGAME_clearCardInfo(battle, screen);
    battle->unk423 = 1;
    battle->unk498.unk1 = arg3;
    battle->unk43C = 0;
    battle->unk440 = -1;
}

/* Moves the selection by STEP among COUNT cards: the selected card is raised */
void CARDGAME_moveSelection(CardBattle *battle, CardScreen *screen, s32 count, s32 step) {
    SOUND.playSound(SOUND_MENU_MOVE);
    screen->startSlide(screen, battle->unk43C, 5, screen->getHandOffset(count, battle->unk43C) + 0x1800, 0x6100);
    screen->sprites[battle->unk43C].unk48 &= ~1;
    screen->sprites[battle->unk43C].moving = 0;
    battle->unk43C += step;
    screen->startSlide(screen, battle->unk43C, 1, screen->getHandOffset(count, battle->unk43C) + 0x1800, 0x5C00);
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
}

/* Moves the selection by STEP among the cards of PILE (unk64): the selected card is raised */
void CARDGAME_movePileSelection(CardBattle *battle, CardScreen *screen, CardPile *pile, s32 step) {
    SOUND.playSound(SOUND_MENU_MOVE);
    screen->startSlide(screen, battle->unk43C, 5, screen->getHandOffset(pile->handCount, battle->unk43C) + 0x1800, 0x6100);
    screen->sprites[battle->unk43C].unk48 &= ~1;
    screen->sprites[battle->unk43C].moving = 0;
    battle->unk43C += step;
    screen->startSlide(screen, battle->unk43C, 1, screen->getHandOffset(pile->handCount, battle->unk43C) + 0x1800, 0x5C00);
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
}

/* Flags (unk446) the cards of pile's hand that can be played and aren't
   picked (unk46F), and dims the others */
void CARDGAME_flagPlayableCards(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    s32 i;

    for (i = 0; i < pile->handCount; i++) {
        if (CARDGAME_canPlayCard(battle, pile->points, pile->hand[i]) && battle->unk46F[i] == 0) {
            battle->unk446[i] = 1;
            screen->sprites[i].dimmed = 0;
        } else {
            battle->unk446[i] = 0;
            if (battle->unk46F[i] == 0) {
                screen->sprites[i].dimmed = 1;
            } else {
                screen->sprites[i].dimmed = 0;
            }
        }
    }
}

/* Whether the pick is over: six cards picked (unk444), or none left that can
   be played */
s32 CARDGAME_isHandPickDone(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    s32 ok = 1;
    s32 i;

    if (battle->unk444 < 6) {
        for (i = 0; i < pile->handCount; i++) {
            if (battle->unk446[i] != 0) {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}

/* Adds a card's points to pile's points of its colour (takes them when add is
   0), on the panel */
void CARDGAME_addCardPoints(CardBattle *battle, CardScreen *screen, CardPile *pile, s32 add, s32 card) {
    CardDrawer drawer;

    initCardDrawer(&drawer);
    drawer.setCard(battle->cards[card] + 1);
    if (drawer.card->color < 6) {
        if (add) {
            pile->points[drawer.card->color - 1] += drawer.card->points;
        } else {
            pile->points[drawer.card->color - 1] -= drawer.card->points;
        }
        screen->setPanelValue(screen, pile->side, drawer.card->color - 1, pile->points[drawer.card->color - 1]);
    }
}

/* Picks or puts back the selected card of PILE (unk64): 1 picked, 2 put back, 0 neither */
s32 CARDGAME_togglePick(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    s32 result = 0;

    if (battle->unk446[battle->unk43C] != 0) {
        if (battle->unk444 < 6) {
            CARDGAME_addCardPoints(battle, screen, pile, 0, pile->hand[battle->unk43C]);
            battle->unk46F[battle->unk43C] = 1;
            screen->startBlink(screen, battle->unk43C);
            screen->sprites[battle->unk43C].unk48 |= 2;
            result = 1;
            battle->unk444++;
        }
    } else if (battle->unk46F[battle->unk43C] != 0) {
        CARDGAME_addCardPoints(battle, screen, pile, 1, pile->hand[battle->unk43C]);
        battle->unk46F[battle->unk43C] = 0;
        screen->sprites[battle->unk43C].unk48 &= ~2;
        result = 2;
        battle->unk444--;
    }
    return result;
}

/* Reads the pad while a card of PILE (unk64) is being chosen: Left/Right move, Cross picks, Triangle cancels */
void CARDGAME_readChooseInput(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
    if (PAD_PRESSED(PAD_TRIANGLE)) {
        SOUND.playSound(SOUND_MENU_CANCEL);
        battle->unk440 = -1;
        battle->unk423 = 14;
    }
    if (PAD_PRESSED(PAD_CIRCLE)) {
        battle->unk423 = 11;
    }
    if (pile->handCount != 0) {
        if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) |
            (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_movePileSelection(battle, screen, pile, -1);
            }
        } else if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) |
                   (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < pile->handCount - 1) {
                CARDGAME_movePileSelection(battle, screen, pile, 1);
            }
        } else if (PAD_PRESSED(PAD_CROSS) && battle->unk446[battle->unk43C] != 0) {
            battle->unk423 = 5;
            battle->unk440 = battle->unk43C;
            battle->unk46F[battle->unk440] = 1;
        }
    }
}

/* Reads the pad while cards of PILE (unk64) are being picked: Left/Right move, Cross picks or puts back, Square and Circle end */
void CARDGAME_readPickInput(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
    if (PAD_PRESSED(PAD_SQUARE)) {
        battle->unk423 = 6;
    }
    if (PAD_PRESSED(PAD_CIRCLE)) {
        battle->unk423 = 11;
    }
    if (pile->handCount != 0) {
        if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) |
            (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_movePileSelection(battle, screen, pile, -1);
            }
        } else if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) |
                   (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < pile->handCount - 1) {
                CARDGAME_movePileSelection(battle, screen, pile, 1);
            }
        } else if (PAD_PRESSED(PAD_CROSS) && CARDGAME_togglePick(battle, screen, pile)) {
            battle->unk423 = 4;
        }
    }
}

/* Reads the pad while one of COUNT cards is being chosen: Left/Right move, Triangle cancels */
void CARDGAME_readCountInput(CardBattle *battle, CardScreen *screen, s32 count) {
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
    if (PAD_PRESSED(PAD_TRIANGLE)) {
        SOUND.playSound(SOUND_MENU_CANCEL);
        battle->unk440 = -1;
        battle->unk423 = 10;
    }
    if (count != 0) {
        if (((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) |
             (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) &&
            battle->unk43C > 0) {
            CARDGAME_moveSelection(battle, screen, count, -1);
        }
        if (((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) |
             (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) &&
            battle->unk43C < count - 1) {
            CARDGAME_moveSelection(battle, screen, count, 1);
        }
    }
}

/* Scales the highlighted sprite up to 1.25 and back, 5 frames each; 1 once
   done */
s32 CARDGAME_stepPulseCard(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->unk424) {
    case 0:
    default:
        screen->scaleSprite(screen, battle->unk43C, 5, 0x1400, 0x1400);
        battle->unk428 = 0;
        battle->unk424++;
        break;
    case 1:
        battle->unk428 += GFX.funcs.getFrameTime();
        if (battle->unk428 >= 5) {
            battle->unk424++;
        }
        break;
    case 2:
        screen->scaleSprite(screen, battle->unk43C, 5, 0x1000, 0x1000);
        battle->unk428 = 0;
        battle->unk424++;
        break;
    case 3:
        battle->unk428 += GFX.funcs.getFrameTime();
        if (battle->unk428 >= 5) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Choosing cards of PILE (unk64) to play: unk423 queues the next step. -1 while it runs, then 0 or 1 */
s32 CARDGAME_stepChooseCards(CardBattle *battle, CardScreen *screen, CardPile *pile) {
    s32 result = -1;
    /* the match depends on a loop variable of its own for most loops:
       sharing them gives GCC 2.8.1 other registers */
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 count;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
        case 2:
            switch (battle->unk420) {
            case 0x99:
                if (pile->side != 0) {
                    CARDGAME_promptText = 0x1C;
                } else {
                    CARDGAME_promptText = 0x19;
                }
                break;
            case 0x9D:
                CARDGAME_promptText = 0x1C;
                break;
            case 0x9C:
                CARDGAME_promptText = 0x1B;
                break;
            case 0x9A:
            case 0x9B:
                CARDGAME_promptText = 0x19;
                break;
            }
            battle->unk42C = 0;
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk440 = 0;
            battle->unk444 = 0;
            break;
        case 5:
            SOUND.playSound(SOUND_MENU_CONFIRM);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 4:
            SOUND.playSound(SOUND_MENU_CONFIRM);
            break;
        case 14:
            if (pile->side == 0) {
                battle->unk498.unk1 = 6;
                screen->closePanel(screen, 0);
            } else {
                battle->unk498.unk1 = 12;
            }
            battle->unk428 = 0;
            battle->unk424 = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 0);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            break;
        case 10:
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk498.unk1 = battle->unk498.unk3;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 0);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            break;
        case 6:
            battle->unk428 = 0;
            battle->unk424 = 0;
            CARDGAME_promptText = screen->windows[0].unk10;
            for (i = 0; i < pile->handCount; i++) {
                if (battle->unk46F[i] != 0) {
                    screen->sprites[i].dimmed = 0;
                    screen->sprites[i].unk48 |= 4;
                } else {
                    screen->sprites[i].dimmed = 1;
                }
            }
            break;
        case 7:
            battle->unk440 = 0;
            battle->unk424 = 0;
            break;
        case 3:
        case 8:
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 11:
            battle->unk498.unk1 = battle->unk498.unk3;
            CARDGAME_promptText = screen->windows[0].unk10;
            battle->unk424 = battle->unk498.unk3;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 0);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            if (battle->unk420 == 0x9A) {
                screen->closeWindow(screen, 5);
            }
            if (pile->side == 0) {
                screen->closePanel(screen, 0);
            }
            break;
        case 13:
            CARDGAME_promptText = 0x19;
            battle->unk428 = 0;
            battle->unk498.unk1 = battle->unk424 - 1;
            switch (battle->unk420) {
            case 0x99:
            case 0x9A:
            case 0x9D:
                for (j = 0; j < pile->handCount; j++) {
                    if (CARDGAME_canPlayCard(battle, pile->points, pile->hand[j])) {
                        battle->unk498.unk6[j] = 0;
                    } else {
                        battle->unk498.unk6[j] = 1;
                    }
                }
                break;
            }
            screen->openWindow(screen, 0, 0, CARDGAME_promptText, 0, 0x42);
            screen->openWindow(screen, 2, 1, 0, 0x82, 0xA5);
            screen->openWindow(screen, 4, 2, 0, 0x86, 0x31);
            screen->openWindow(screen, 3, 1, 0, 0x82, 0x90);
            screen->openWindow(screen, 1, 3, 0, 0xFD, 0x90);
            if (battle->unk420 == 0x9A) {
                screen->openWindow(screen, 5, 4, 0x24, 0, 0x14);
            }
            if (pile->side == 0) {
                screen->openPanel(screen, 0);
            }
            break;
        case 9:
            battle->unk428 = 0;
            battle->unk424 = 0;
            for (j = 0; j < pile->handCount; j++) {
                if (CARDGAME_canPlayCard(battle, pile->points, pile->hand[j])) {
                    screen->sprites[j].dimmed = 0;
                } else {
                    screen->sprites[j].dimmed = 1;
                }
                if (battle->unk46F[j] != 0) {
                    screen->sprites[j].dimmed = 0;
                    screen->sprites[j].unk48 &= ~4;
                }
            }
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }

    switch (battle->stepState) {
    case 1:
        battle->unk42C = CARDGAME_openStepWindows(battle, screen, 2, CARDGAME_promptText, battle->unk424, battle->unk42C);
        CARDGAME_showCardInfo(battle, screen, 0);
        if (battle->unk498.unk3C * 4 + 14 < battle->unk424) {
            battle->unk423 = 3;
            screen->startSlide(screen, 0, 5, 0x1800, 0x5C00);
            screen->sprites[battle->unk43C].unk48 |= 1;
            screen->sprites[battle->unk43C].moving = 1;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        break;
    case 2:
        screen->scaleSprite(screen, 0, 5, 0x1000, 0x1000);
        if (battle->unk424 > 10) {
            battle->unk423 = 3;
            screen->startSlide(screen, 0, 5, 0x1800, 0x5C00);
            screen->sprites[battle->unk43C].unk48 |= 1;
            screen->sprites[battle->unk43C].moving = 1;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        break;
    case 3:
        switch (battle->unk420) {
        case 0x99:
            CARDGAME_readChooseInput(battle, screen, pile);
            break;
        case 0x9A:
        case 0x9D:
            CARDGAME_readPickInput(battle, screen, pile);
            break;
        case 0x9B:
        case 0x9C:
            CARDGAME_readCountInput(battle, screen, battle->unk498.unk3C);
            break;
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    case 4:
        if (screen->sprites[battle->unk43C].state == 1) {
            CARDGAME_flagPlayableCards(battle, screen, pile);
            if (CARDGAME_isHandPickDone(battle, screen, pile)) {
                battle->unk423 = 6;
            } else {
                battle->unk423 = 3;
            }
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    case 5:
        if (CARDGAME_stepPulseCard(battle, screen)) {
            battle->unk423 = 14;
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    case 14:
        if (pile->handCount * 4 + 5 < battle->unk424) {
            battle->unk423 = 0;
            battle->unk421 = 0;
            battle->unk420 = 0;
            battle->unk421 = 0;
            result = battle->unk440 != -1;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        break;
    case 10:
        if (battle->unk498.unk3C * 4 + 14 < battle->unk424) {
            result = 0;
            battle->unk423 = 0;
            battle->unk421 = 0;
            battle->unk420 = 0;
            battle->unk421 = 0;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        break;
    case 6:
        switch (battle->unk424) {
        case 0:
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 0);
            screen->closeWindow(screen, 5);
            screen->startMove(screen, battle->unk43C, 5, screen->getHandOffset(pile->handCount, battle->unk43C) + 0x1800, 0x6100);
            screen->sprites[battle->unk43C].unk48 &= ~1;
            screen->sprites[battle->unk43C].moving = 0;
            break;
        case 6:
            screen->openMessage(screen, 15, 1, 0, 2);
            break;
        }
        if (++battle->unk424 > 18) {
            battle->unk423 = 7;
        }
        break;
    case 7:
        if (PAD_PRESSED(PAD_CROSS)) {
            screen->confirmMessage(screen);
            if (battle->unk440 == 0) {
                battle->unk423 = 8;
            } else {
                battle->unk423 = 9;
            }
        } else if (PAD_PRESSED(PAD_UP) || PAD_PRESSED(PAD_DOWN)) {
            battle->unk440 ^= 1;
            SOUND.playSound(SOUND_CURSOR);
            screen->setMessageChoice(screen, battle->unk440);
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk440 = 1;
            screen->setMessageChoice(screen, 1);
            screen->confirmMessage(screen);
            battle->unk423 = 9;
        }
        break;
    case 8:
        switch (battle->unk424) {
        case 20:
            count = 0;
            for (k = 0; k < pile->handCount; k++) {
                if (battle->unk46F[k] != 0) {
                    screen->scaleSprite(screen, k, 6, 0x1400, 0x1400);
                    count++;
                }
            }
            if (count != 0) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
            }
            break;
        case 25:
            for (m = 0; m < pile->handCount; m++) {
                if (battle->unk46F[m] != 0) {
                    screen->scaleSprite(screen, m, 6, 0x1000, 0x1000);
                }
            }
            break;
        case 35:
            if (pile->side == 0) {
                battle->unk498.unk1 = 6;
                screen->closePanel(screen, 0);
            } else {
                battle->unk498.unk1 = 12;
            }
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            break;
        }
        if (++battle->unk424 > 45 && battle->unk498.unk0 == 0) {
            result = 1;
        }
        break;
    case 9:
        switch (battle->unk424) {
        case 6:
            break;
        case 18:
            screen->openWindow(screen, 0, 0, CARDGAME_promptText, 0, 0x42);
            screen->openWindow(screen, 4, 2, 0, 0x86, 0x31);
            screen->openWindow(screen, 5, 4, 0x24, 0, 0x14);
            CARDGAME_showCardInfo(battle, screen, 0);
            break;
        }
        if (++battle->unk424 > 30) {
            battle->unk423 = 3;
            screen->startMove(screen, battle->unk43C, 5, screen->getHandOffset(pile->handCount, battle->unk43C) + 0x1800, 0x5C00);
            screen->sprites[battle->unk43C].unk48 |= 1;
            screen->sprites[battle->unk43C].moving = 1;
        }
        break;
    case 11:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            battle->unk423 = 12;
            battle->record.unk0[8] = 0;
            battle->unk2F4 = 3;
        }
        break;
    case 12:
        battle->unk423 = 13;
        break;
    case 13:
        if (((pile->side == 0 && screen->panels[0].state == 2) || (pile->side != 0 && ++battle->unk428 > 10)) &&
            battle->unk498.unk0 == 0) {
            battle->unk423 = 3;
            screen->startSlide(screen, battle->unk43C, 5, screen->getHandOffset(pile->handCount, battle->unk43C) + 0x1800, 0x5C00);
            screen->sprites[battle->unk43C].unk48 |= 1;
            screen->sprites[battle->unk43C].moving = 1;
            for (n = 0; n < pile->handCount; n++) {
                if (battle->unk46F[n] == 1) {
                    screen->sprites[n].dimmed = 0;
                    screen->sprites[n].unk48 |= 2;
                }
            }
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    }
    return result;
}

/* Opens the panels for a step */
void CARDGAME_startPanelsStep(CardBattle *battle, CardScreen *screen) {
    screen->resetPanels(screen);
    battle->unk440 = 0;
    battle->stepState = 1;
    screen->openPanels(screen);
    battle->unk498.unk5 = 1;
    battle->unk498.unk4 = 1;
    battle->unk498.unk1 = 1;
}

/* Turns the opponent's slot cards over, then counts the panels' values 8 and 9 up to each side's pile unk0 and unk2; 1 when done */
s32 CARDGAME_stepTally(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 counting = 0;
    s32 step;

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            if (battle->players[0].slotCount + battle->players[1].slotCount == 0) {
                battle->stepState = 3;
                battle->unk424 = 0;
                battle->unk428 = 0;
                battle->unk42C = 0;
                battle->unk430 = 0;
                battle->unk434 = 0;
            } else {
                battle->stepState = 2;
                battle->unk424 = 0;
                battle->unk428 = 0;
                battle->unk434 = 0;
                if (battle->players[0].slotCount > battle->players[1].slotCount) {
                    battle->unk42C = battle->players[0].slotCount;
                } else {
                    battle->unk42C = battle->players[1].slotCount;
                }
                battle->unk42C = battle->unk42C * 6 + 18;
            }
        }
        break;
    case 2:
        if (battle->unk434 >= 6) {
            if (battle->unk428 < battle->players[1].slotCount) {
                screen->startFlip(screen, battle->unk428 + 6);
            }
            battle->unk428++;
            battle->unk434 -= 6;
        }
        if (battle->unk424 > battle->unk42C) {
            battle->stepState = 3;
            battle->unk424 = 0;
            battle->unk428 = 0;
            battle->unk42C = 0;
            battle->unk430 = 0;
            battle->unk434 = 0;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        break;
    case 3:
        step = battle->sides[0].pile.unk0 / 60;
        battle->unk428 += step != 0 ? step : 1;
        if (battle->unk428 > battle->sides[0].pile.unk0) {
            battle->unk428 = battle->sides[0].pile.unk0;
        } else {
            counting = 1;
        }
        step = battle->sides[0].pile.unk2 / 60;
        battle->unk42C += step != 0 ? step : 1;
        if (battle->unk42C > battle->sides[0].pile.unk2) {
            battle->unk42C = battle->sides[0].pile.unk2;
        } else {
            counting = 1;
        }
        step = battle->sides[1].pile.unk0 / 60;
        battle->unk430 += step != 0 ? step : 1;
        if (battle->unk430 > battle->sides[1].pile.unk0) {
            battle->unk430 = battle->sides[1].pile.unk0;
        } else {
            counting = 1;
        }
        step = battle->sides[1].pile.unk2 / 60;
        battle->unk434 += step != 0 ? step : 1;
        if (battle->unk434 > battle->sides[1].pile.unk2) {
            battle->unk434 = battle->sides[1].pile.unk2;
        } else {
            counting = 1;
        }
        if (battle->unk424++ > 60) {
            battle->stepState = 4;
            battle->unk424 = 0;
            battle->unk428 = battle->sides[0].pile.unk0;
            battle->unk42C = battle->sides[0].pile.unk2;
            battle->unk430 = battle->sides[1].pile.unk0;
            battle->unk434 = battle->sides[1].pile.unk2;
        } else if (counting) {
            SOUND.playSound(SOUND_COUNT);
        }
        screen->setPanelValue(screen, 0, 8, battle->unk428);
        screen->setPanelValue(screen, 0, 9, battle->unk42C);
        screen->setPanelValue(screen, 1, 8, battle->unk430);
        screen->setPanelValue(screen, 1, 9, battle->unk434);
        break;
    case 4:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk424 = 90;
        }
        if (++battle->unk424 > 90) {
            screen->closePanels(screen);
            battle->stepState = 5;
            battle->unk498.unk1 = 2;
        }
        break;
    case 5:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Shows CARDGAME_stepMessages[index]: its message and window 5 */
void CARDGAME_startStepMessage(CardBattle *battle, CardScreen *screen, s32 index) {
    u8 *entry = CARDGAME_stepMessages[index];

    screen->openMessage(screen, entry[1], 0, 0, 1);
    screen->openWindow(screen, 5, 5, entry[0], 0, 0x42);
    battle->stepState = 1;
}

/* Waits for window 5 to open, then for Cross or Triangle to close it; 1 once it has closed */
s32 CARDGAME_stepMessage(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        if (screen->windows[5].state == 2) {
            battle->stepState = 2;
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 3;
            screen->closeWindow(screen, 5);
            screen->closeMessage(screen);
        }
        break;
    case 3:
        if (screen->windows[5].state == 0) {
            battle->stepState = 4;
        }
        break;
    case 4:
        done = 1;
        break;
    }
    return done;
}

/* Moves the selection to the other one of the two cards that CARDGAME_startFirstPick lays out */
void CARDGAME_switchCoinCard(CardBattle *battle, CardScreen *screen) {
    SOUND.playSound(SOUND_MENU_MOVE);
    screen->startSlide(screen, battle->unk43C, 5, CARDGAME_coinCardPositions[battle->unk43C][0], CARDGAME_coinCardPositions[battle->unk43C][1]);
    screen->sprites[battle->unk43C].unk48 &= ~1;
    screen->sprites[battle->unk43C].moving = 0;
    battle->unk43C ^= 1;
    screen->startSlide(screen, battle->unk43C, 1, CARDGAME_coinCardPositions[battle->unk43C][0], CARDGAME_coinCardPositions[battle->unk43C][1] - 0x500);
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
}

/* Who goes first: cards 0x57 and 0x58 face down, in a random order */
void CARDGAME_startFirstPick(CardBattle *battle, CardScreen *screen) {
    s32 first = RANDOM.next() & 1;

    battle->unk434 = first;
    battle->unk430 = 0;
    battle->unk42C = 0;
    battle->unk428 = 0;
    battle->unk424 = 0;
    screen->addSprite(screen, 0, 0x7400, 0x6100);
    screen->addSprite(screen, 1, 0xA400, 0x6100);
    if (first != 0) {
        screen->setSpriteCard(screen, 0, 0x57);
        screen->setSpriteCard(screen, 1, 0x58);
    } else {
        screen->setSpriteCard(screen, 1, 0x57);
        screen->setSpriteCard(screen, 0, 0x58);
    }
    screen->sprites[0].visible = 2;
    screen->sprites[1].visible = 2;
    screen->sprites[0].scaleX = 0;
    screen->sprites[0].dimmed = 0;
    screen->sprites[0].unk48 = 0;
    screen->sprites[1].scaleX = 0;
    screen->sprites[1].dimmed = 0;
    screen->sprites[1].unk48 = 0;
    battle->unk43C = 0;
    battle->unk440 = 0;
    battle->stepState = 1;
}

/* The draw for who goes first: the two face-down cards open, the player picks
   one with left/right and cross and both turn over; 1 once it is over, with
   unk440 1 if the player won the draw */
s32 CARDGAME_drawFirstPlayer(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        switch (battle->unk424) {
        case 0:
            screen->scaleSprite(screen, 0, 10, 0x1000, 0x1000);
            break;
        case 4:
            screen->scaleSprite(screen, 1, 10, 0x1000, 0x1000);
            break;
        }
        battle->unk424++;
        if (battle->unk424 >= 15) {
            battle->stepState = 2;
            screen->startSlide(screen, 0, 5, 0x7400, 0x5C00);
            screen->sprites[0].moving = 1;
            screen->sprites[0].unk48 |= 1;
        }
        break;
    case 2:
        screen->sprites[battle->unk43C].unk48 |= 1;
        screen->sprites[battle->unk43C].moving = 1;
        if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) ||
            (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            CARDGAME_switchCoinCard(battle, screen);
        } else if (PAD_PRESSED(PAD_CROSS)) {
            battle->stepState = 3;
            battle->unk440 = battle->unk43C;
            battle->unk46F[battle->unk440] = 1;
            battle->unk42C = 0;
            battle->unk428 = 0;
            battle->unk424 = 0;
            SOUND.playSound(SOUND_MENU_CONFIRM);
        }
        break;
    case 3:
        if (CARDGAME_stepPulseCard(battle, screen)) {
            battle->stepState = 4;
            battle->unk42C = 0;
            battle->unk428 = 0;
            battle->unk424 = 0;
            screen->startFlip(screen, battle->unk43C);
        }
        break;
    case 4:
        if (battle->unk424 == 20) {
            screen->startFlip(screen, battle->unk43C ^ 1);
#if VERSION_EU
            screen->openWindow(screen, 5, 5, battle->unk434 == battle->unk440 ? 0x44 : 0x43, 0, 0x42);
            SOUND.playSound(SOUND_MENU_OPEN);
#endif
        }
        /* the result stays up for a while; cross or triangle skips it */
        if (battle->unk424 >= 31 && (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE))) {
#if VERSION_US
            battle->unk424 = 60;
#elif VERSION_EU
            battle->unk424 = 90;
#endif
        }
#if VERSION_US
        battle->unk424++;
        if (battle->unk424 >= 61) {
#elif VERSION_EU
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 91) {
#endif
            battle->stepState = 5;
            battle->unk42C = 0;
            battle->unk428 = 0;
            battle->unk424 = 0;
#if VERSION_EU
            screen->closeWindow(screen, 5);
#endif
        }
        break;
    case 5:
        switch (battle->unk424) {
        case 0:
            screen->scaleSprite(screen, 0, 5, 0, 0x1000);
            break;
        case 4:
            screen->scaleSprite(screen, 1, 5, 0, 0x1000);
            break;
        }
        battle->unk424++;
        if (battle->unk424 >= 15) {
            battle->stepState = 6;
        }
        break;
    case 6:
        if (battle->unk434 == battle->unk440) {
            battle->unk440 = 1;
        } else {
            battle->unk440 = 0;
        }
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_viewTable */
void CARDGAME_startViewTable(CardBattle *battle, CardScreen *screen) {
    battle->unk423 = 1;
}

/* The table's height: 8 per card of the longer row of slots (at least 3), and
   14 */
s32 CARDGAME_getTableHeight(CardBattle *battle, CardScreen *screen) {
    s32 n;

    if (battle->players[0].slotCount > battle->players[1].slotCount) {
        n = battle->players[0].slotCount;
    } else {
        n = battle->players[1].slotCount;
    }
    if (n < 3) {
        n = 3;
    }
    return n * 8 + 14;
}

/* Moves the highlight of a row of cards (kind 0, 1 or 2) by delta */
void CARDGAME_moveTableHighlight(CardBattle *battle, CardScreen *screen, s32 kind, s32 delta) {
    s32 offset = 0;

    SOUND.playSound(SOUND_MENU_MOVE);
    switch (kind) {
    case 1:
        offset = 6;
        break;
    case 2:
        offset = 12;
        break;
    }
    screen->sprites[offset + battle->unk43C].unk48 &= ~1;
    screen->sprites[offset + battle->unk43C].moving = 0;
    battle->unk43C += delta;
    screen->sprites[offset + battle->unk43C].unk48 |= 1;
    screen->sprites[offset + battle->unk43C].moving = 1;
}

/* Lets the player look over the cards out on the table: the two players' rows
   and the row of the cards played (up and down change rows, left and right
   move along one, triangle leaves); 1 once it is over */
s32 CARDGAME_viewTable(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            CARDGAME_savedPanelScales[0] = screen->panels[0].scale.state;
            CARDGAME_savedPanelScales[1] = screen->panels[1].scale.state;
            screen->panels[0].scale.state = 0;
            screen->panels[1].scale.state = 0;
            battle->unk498.unk5 = 1;
            battle->unk498.unk1 = 1;
            battle->unk42C = CARDGAME_getTableHeight(battle, screen);
            battle->unk43C = 0;
            screen->resetPanels(screen);
            screen->openPanels(screen);
            CARDGAME_clearCardInfo(battle, screen);
            break;
        case 2:
            CARDGAME_clearCardInfo(battle, screen);
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk434 = 0;
            break;
        case 4:
            CARDGAME_clearCardInfo(battle, screen);
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk434 = 1;
            break;
        case 3:
            CARDGAME_clearCardInfo(battle, screen);
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk434 = 2;
            break;
        case 8:
            screen->sprites[battle->unk43C].unk48 &= ~1;
            screen->sprites[battle->unk43C].moving = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 9:
            screen->sprites[battle->unk43C + 12].unk48 &= ~1;
            screen->sprites[battle->unk43C + 12].moving = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 10:
            screen->sprites[battle->unk43C + 6].unk48 &= ~1;
            screen->sprites[battle->unk43C + 6].moving = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 11:
            screen->closePanels(screen);
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk498.unk1 = 2;
            break;
        case 12:
            screen->openMessage(screen, 0x17, 0, 0, 1);
            break;
        case 14:
            screen->closeMessage(screen);
            screen->closePanels(screen);
            break;
        case 15:
            /* nothing to set up: it ends */
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }
    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            if (battle->players[0].slotCount != 0) {
                battle->unk423 = 2;
                battle->unk434 = 0;
            } else if (battle->players[1].slotCount != 0) {
                battle->unk423 = 4;
                battle->unk434 = 1;
            } else if (battle->record.entryCount > 0) {
                battle->unk423 = 3;
                battle->unk434 = 2;
            } else {
                battle->unk423 = 12;
                battle->unk434 = 3;
            }
        }
        break;
    case 2:
    case 3:
    case 4:
        battle->unk428 = CARDGAME_openStepWindows(battle, screen, battle->unk434, 0, battle->unk424, battle->unk428);
        CARDGAME_showCardInfo(battle, screen, CARDGAME_rowSpriteOffsets[battle->unk434]);
        battle->unk424++;
        if (battle->unk424 >= 11) {
            CARDGAME_moveTableHighlight(battle, screen, battle->unk434, 0);
            battle->unk423 = CARDGAME_rowSteps[battle->unk434];
        }
        break;
    case 5:
        if (PAD_PRESSED(PAD_UP) && (battle->record.entryCount > 0 || battle->players[1].slotCount != 0)) {
            battle->unk423 = 8;
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < battle->players[0].slotCount - 1) {
                CARDGAME_moveTableHighlight(battle, screen, 0, 1);
            }
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_moveTableHighlight(battle, screen, 0, -1);
            }
        }
        CARDGAME_showTableCardInfo(battle, screen, 0);
        if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 11;
        }
        break;
    case 6:
        if (PAD_PRESSED(PAD_DOWN) && (battle->record.entryCount > 0 || battle->players[0].slotCount != 0)) {
            battle->unk423 = 10;
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < battle->players[1].slotCount - 1) {
                CARDGAME_moveTableHighlight(battle, screen, 1, 1);
            }
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_moveTableHighlight(battle, screen, 1, -1);
            }
        }
        CARDGAME_showTableCardInfo(battle, screen, 1);
        if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 11;
        }
        break;
    case 7:
        if (PAD_PRESSED(PAD_UP)) {
            if (battle->players[1].slotCount != 0) {
                battle->unk42C = 1;
                battle->unk423 = 9;
            }
        } else if (PAD_PRESSED(PAD_DOWN) && battle->players[0].slotCount != 0) {
            battle->unk42C = 0;
            battle->unk423 = 9;
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < battle->record.entryCount - 1) {
                CARDGAME_moveTableHighlight(battle, screen, 2, 1);
            }
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_moveTableHighlight(battle, screen, 2, -1);
            }
        }
        if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 11;
        }
        CARDGAME_showTableCardInfo(battle, screen, 2);
        break;
    case 8:
        battle->unk424++;
        if (battle->unk424 >= 11) {
            if (battle->record.entryCount > 0) {
                battle->unk423 = 3;
                battle->unk43C /= 2;
                if (battle->unk43C > battle->record.entryCount - 1) {
                    battle->unk43C = battle->record.entryCount - 1;
                }
            } else if (battle->players[1].slotCount != 0) {
                battle->unk423 = 4;
                if (battle->unk43C > battle->players[1].slotCount - 1) {
                    battle->unk43C = battle->players[1].slotCount - 1;
                }
            }
        }
        break;
    case 9:
        battle->unk424++;
        if (battle->unk424 >= 11) {
            battle->unk43C = battle->unk43C * 2 + 1;
            if (battle->unk42C != 0) {
                battle->unk423 = 4;
                if (battle->unk43C > battle->players[1].slotCount - 1) {
                    battle->unk43C = battle->players[1].slotCount - 1;
                }
            } else {
                battle->unk423 = 2;
                if (battle->unk43C > battle->players[0].slotCount - 1) {
                    battle->unk43C = battle->players[0].slotCount - 1;
                }
            }
        }
        break;
    case 10:
        battle->unk424++;
        if (battle->unk424 >= 11) {
            if (battle->record.entryCount > 0) {
                battle->unk423 = 3;
                battle->unk43C /= 2;
                if (battle->unk43C > battle->record.entryCount - 1) {
                    battle->unk43C = battle->record.entryCount - 1;
                }
            } else if (battle->players[0].slotCount != 0) {
                battle->unk423 = 2;
                if (battle->unk43C > battle->players[0].slotCount - 1) {
                    battle->unk43C = battle->players[0].slotCount - 1;
                }
            }
        }
        break;
    case 11:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            battle->unk423 = 15;
        }
        break;
    case 12:
        if (screen->message.state == 2) {
            battle->unk423 = 13;
        }
        break;
    case 13:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk423 = 14;
        }
        break;
    case 14:
        if (screen->message.state == 0) {
            battle->unk423 = 15;
        }
        break;
    case 15:
        screen->panels[0].scale.state = CARDGAME_savedPanelScales[0];
        screen->panels[1].scale.state = CARDGAME_savedPanelScales[1];
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_pickTableCard with unk438 */
void CARDGAME_startPickTableCard(CardBattle *battle, CardScreen *screen, s32 arg2) {
    battle->unk438 = arg2;
    battle->unk423 = 1;
}

/* CARDGAME_getTableHeight, for CARDGAME_pickTableCard */
s32 CARDGAME_getPickTableHeight(CardBattle *battle, CardScreen *screen) {
    return CARDGAME_getTableHeight(battle, screen);
}

/* CARDGAME_moveTableHighlight, for CARDGAME_pickTableCard */
void CARDGAME_movePickHighlight(CardBattle *battle, CardScreen *screen, s32 kind, s32 delta) {
    CARDGAME_moveTableHighlight(battle, screen, kind, delta);
}

/* Lets the player pick a card out on the table (unk445 bit 0: in their own
   row, bit 1: in the opponent's): 2 once one is picked (its sprite in
   unk440), 1 if there was none or the player backed out */
s32 CARDGAME_pickTableCard(CardBattle *battle, CardScreen *screen) {
    s32 result = 0;
    s32 i;
    /* the match depends on a second loop variable: GCC 2.8.1 gives the first
       two loops other registers than it gives i */
    s32 j;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            if (battle->unk438 != 0) {
                for (j = 0; j < 3; j++) {
                    battle->unk498.unk6[j + 12] = 1;
                }
                for (j = 0; j < 12; j++) {
                    if (battle->unk446[j] != 0) {
                        battle->unk498.unk6[j] = 0;
                    } else {
                        battle->unk498.unk6[j] = 1;
                    }
                }
                battle->unk498.unk1 = 1;
                battle->unk43C = 0;
                screen->resetPanels(screen);
                screen->openPanels(screen);
                screen->addSprite(screen, 15, 0xE500, 0x6100);
                screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
                screen->sprites[15].scaleX = 0;
                screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
            } else {
                for (i = 0; i < 3; i++) {
                    screen->sprites[i + 12].dimmed = 1;
                }
                for (i = 0; i < 12; i++) {
                    if (battle->unk446[i] != 0) {
                        screen->sprites[i].dimmed = 0;
                    } else {
                        screen->sprites[i].dimmed = 1;
                    }
                }
            }
            battle->unk42C = CARDGAME_getPickTableHeight(battle, screen);
            CARDGAME_clearCardInfo(battle, screen);
            break;
        case 2:
            CARDGAME_clearCardInfo(battle, screen);
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk434 = 0;
            break;
        case 3:
            CARDGAME_clearCardInfo(battle, screen);
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk434 = 1;
            break;
        case 7:
            screen->sprites[battle->unk43C].unk48 &= ~1;
            screen->sprites[battle->unk43C].moving = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 8:
            screen->sprites[battle->unk43C + 6].unk48 &= ~1;
            screen->sprites[battle->unk43C + 6].moving = 0;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 6:
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            screen->startBlink(screen, battle->unk440);
            SOUND.playSound(SOUND_MENU_CONFIRM);
            break;
        case 9:
            screen->closePanels(screen);
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            battle->unk498.unk1 = 2;
            screen->scaleSprite(screen, 15, 8, 0, 0x1000);
            break;
        case 10:
            screen->closePanels(screen);
            battle->unk498.unk1 = 2;
            screen->scaleSprite(screen, 15, 8, 0, 0x1000);
            break;
        case 14:
            /* nothing to set up */
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }
    switch (battle->stepState) {
    case 1:
        if (battle->unk438 == 0 || (screen->panels[0].state == 2 && battle->unk498.unk0 == 0)) {
            if (battle->unk445 & 1) {
                if (battle->players[0].slotCount != 0) {
                    battle->unk423 = 2;
                    battle->unk434 = 0;
                } else {
                    battle->unk445 &= ~1;
                }
            }
            if (battle->unk445 & 2) {
                if (battle->players[1].slotCount != 0) {
                    battle->unk423 = 3;
                    battle->unk434 = 1;
                } else {
                    battle->unk445 &= ~2;
                }
            }
            if (battle->unk445 == 0) {
                battle->unk423 = 12;
                battle->unk434 = 3;
            }
        }
        break;
    case 2:
    case 3:
        battle->unk428 = CARDGAME_openStepWindows(battle, screen, battle->unk434, 0, battle->unk424, battle->unk428);
        CARDGAME_showCardInfo(battle, screen, CARDGAME_rowSpriteOffsets[battle->unk434]);
        battle->unk424++;
        if (battle->unk424 >= 11) {
            switch (battle->unk434) {
            case 0:
                CARDGAME_movePickHighlight(battle, screen, 0, 0);
                battle->unk423 = 4;
                break;
            case 1:
                CARDGAME_movePickHighlight(battle, screen, 1, 0);
                battle->unk423 = 5;
                break;
            }
        }
        break;
    case 4:
        if ((battle->unk445 & 2) && PAD_PRESSED(PAD_UP) && battle->players[1].slotCount != 0) {
            battle->unk423 = 7;
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < battle->players[0].slotCount - 1) {
                CARDGAME_moveTableHighlight(battle, screen, 0, 1);
            }
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_moveTableHighlight(battle, screen, 0, -1);
            }
        }
        CARDGAME_showTableCardInfo(battle, screen, 0);
        if (battle->unk438 != 0 && PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 9;
        }
        if (PAD_PRESSED(PAD_CROSS) && battle->unk446[battle->unk43C] != 0) {
            battle->unk423 = 6;
            battle->unk440 = battle->unk43C;
        }
        break;
    case 5:
        if ((battle->unk445 & 1) && PAD_PRESSED(PAD_DOWN) && battle->players[0].slotCount != 0) {
            battle->unk423 = 8;
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
            if (battle->unk43C < battle->players[1].slotCount - 1) {
                CARDGAME_moveTableHighlight(battle, screen, 1, 1);
            }
        }
        if ((PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
            if (battle->unk43C > 0) {
                CARDGAME_moveTableHighlight(battle, screen, 1, -1);
            }
        }
        CARDGAME_showTableCardInfo(battle, screen, 1);
        if (battle->unk438 != 0 && PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 9;
        } else if (PAD_PRESSED(PAD_CROSS) && battle->unk446[battle->unk43C + 6] != 0) {
            battle->unk423 = 6;
            battle->unk440 = battle->unk43C + 6;
        }
        break;
    case 6:
        if (screen->sprites[battle->unk440].state == 1) {
            if (battle->unk438 == 0) {
                for (i = 0; i < 3; i++) {
                    screen->sprites[i + 12].dimmed = 0;
                }
                for (i = 0; i < 12; i++) {
                    screen->sprites[i].dimmed = 0;
                }
            }
            battle->unk423 = 14;
        }
        break;
    case 7:
        battle->unk424++;
        if (battle->unk424 >= 11) {
            battle->unk423 = 3;
            if (battle->unk43C > battle->players[1].slotCount - 1) {
                battle->unk43C = battle->players[1].slotCount - 1;
            }
        }
        break;
    case 8:
        battle->unk424++;
        if (battle->unk424 >= 11) {
            battle->unk423 = 2;
            if (battle->unk43C > battle->players[0].slotCount - 1) {
                battle->unk43C = battle->players[0].slotCount - 1;
            }
        }
        break;
    case 11:
        battle->unk423 = 14;
        break;
    case 9:
    case 10:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            battle->unk423 = 13;
        }
        break;
    case 12:
        if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk423 = 10;
        }
        break;
    case 13:
        result = 1;
        break;
    case 14:
        for (i = 0; i < 15; i++) {
            battle->unk46F[i] = 0;
        }
        result = 2;
        battle->unk46F[battle->unk440] = 1;
        break;
    }
    return result;
}

/* Sets up CARDGAME_chooseCard's choice of one of a side's cards: kind 0 among
   its hand, 1 and 2 among its deck, 3 among its discards */
void CARDGAME_setupCardChoice(CardBattle *battle, CardScreen *screen, s32 side, s32 kind) {
    s32 i;

    switch (kind) {
    case 0:
        battle->unk438 = side != 0 ? 11 : 5;
        battle->unk434 = battle->sides[side].pile.handCount;
        break;
    case 1:
    case 2:
        if (side == 0) {
            battle->unk438 = 7;
            battle->sortCards(battle, battle->sides[0].pile.deck, battle->sides[0].pile.deckTop | (40 << 16), 2);
        } else {
            battle->unk438 = 13;
            if (kind != 2) {
                battle->sortCards(battle, battle->sides[1].pile.deck, battle->sides[1].pile.deckTop | (40 << 16), 3);
            }
        }
        battle->unk434 = battle->sides[side].pile.deckCount;
        break;
    case 3:
        battle->unk438 = side != 0 ? 15 : 9;
        battle->unk434 = battle->sides[side].pile.discardCount;
        break;
    }
    for (i = 0; i < 40; i++) {
        if (i < battle->unk434) {
            battle->unk46F[i] = 0;
            if (battle->unk446[i] != 0) {
                battle->unk498.unk6[i] = 0;
            } else {
                battle->unk498.unk6[i] = 1;
            }
        }
    }
    battle->unk423 = 1;
    CARDGAME_clearCardInfo(battle, screen);
    battle->unk43C = 0;
    battle->unk440 = -1;
}

/* CARDGAME_setupCardChoice of side, kind 0 */
void CARDGAME_setupSideChoice(CardBattle *battle, CardScreen *screen, s32 side) {
    CARDGAME_setupCardChoice(battle, screen, side, 0);
}

/* Moves the highlight along the hand by delta, raising the highlighted card */
void CARDGAME_moveHandHighlight(CardBattle *battle, CardScreen *screen, s32 delta) {
    SOUND.playSound(SOUND_MENU_MOVE);
    screen->startSlide(screen, battle->unk43C, 5, screen->getHandOffset(battle->unk434, battle->unk43C) + 0x1800, 0x6100);
    screen->sprites[battle->unk43C].unk48 &= ~1;
    screen->sprites[battle->unk43C].moving = 0;
    battle->unk43C += delta;
    screen->startSlide(screen, battle->unk43C, 1, screen->getHandOffset(battle->unk434, battle->unk43C) + 0x1800, 0x5C00);
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
}

/* Moves the highlight along the hand with left and right; cross picks a playable card */
void CARDGAME_browseHand(CardBattle *battle, CardScreen *screen) {
    screen->sprites[battle->unk43C].unk48 |= 1;
    screen->sprites[battle->unk43C].moving = 1;
    if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_LEFT))) | (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_LEFT)))) {
        if (battle->unk43C > 0) {
            CARDGAME_moveHandHighlight(battle, screen, -1);
        }
    } else if ((PAD.getRepeated(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT))) | (PAD.getPressed(0) & (1 << PAD.getButtonBit(0, PAD_RIGHT)))) {
        if (battle->unk43C < battle->unk434 - 1) {
            CARDGAME_moveHandHighlight(battle, screen, 1);
        }
    } else if (PAD_PRESSED(PAD_CROSS) && battle->unk446[battle->unk43C] != 0) {
        battle->unk423 = 3;
    }
    battle->unk445 = 0;
}

/* Lets a player pick a card of a row (set up by CARDGAME_setupCardChoice): 2 once one is
   picked, 1 if the player backed out with triangle (mode 1), else 0 */
s32 CARDGAME_chooseCard(CardBattle *battle, CardScreen *screen, s32 mode) {
    s32 result = 0;
    s32 card;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            battle->unk498.unk1 = battle->unk438;
            switch (battle->unk438) {
            case 5:
                CARDGAME_selectionText = 0x19;
                break;
            case 7:
                CARDGAME_selectionText = 0x1A;
                break;
            case 13:
                CARDGAME_selectionText = 0x1D;
                break;
            case 9:
                CARDGAME_selectionText = 0x1B;
                break;
            case 11:
            case 15:
                CARDGAME_selectionText = 0x1C;
                break;
            }
            if (mode == 2) {
                screen->openPanel(screen, 0);
            }
            battle->unk42C = 0;
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk440 = 0;
            battle->unk444 = 0;
            break;
        case 3:
            SOUND.playSound(SOUND_MENU_CONFIRM);
            /* fallthrough */
        case 2:
            battle->unk428 = 0;
            battle->unk424 = 0;
            break;
        case 4:
            if (mode == 1) {
                screen->scaleSprite(screen, 15, 8, 0, 0x1000);
            }
            battle->unk428 = 0;
            battle->unk424 = 0;
            battle->unk498.unk1 = battle->unk498.unk3;
            screen->closeWindow(screen, 4);
            screen->closeWindow(screen, 0);
            screen->closeWindow(screen, 1);
            screen->closeWindow(screen, 2);
            screen->closeWindow(screen, 3);
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }
    switch (battle->stepState) {
    case 1:
        battle->unk42C = CARDGAME_openStepWindows(battle, screen, 2, CARDGAME_selectionText, battle->unk424, battle->unk42C);
        CARDGAME_showCardInfo(battle, screen, 0);
        if (battle->unk424 == 2 && mode == 1) {
#if VERSION_US
            screen->addSprite(screen, 15, 0x1800, 0x9000);
#elif VERSION_EU
            screen->addSprite(screen, 15, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0], CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1]);
#endif
            screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
            screen->sprites[15].scaleX = 0;
            screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
        }
        if (battle->unk498.unk3C * 4 + 14 < battle->unk424) {
            battle->unk423 = 2;
            screen->startSlide(screen, 0, 5, 0x1800, 0x5C00);
            screen->sprites[battle->unk43C].unk48 |= 1;
            screen->sprites[battle->unk43C].moving = 1;
        }
        battle->unk424++;
        break;
    case 2:
        CARDGAME_browseHand(battle, screen);
        if (mode == 1 && PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            battle->unk445 = 1;
            battle->unk423 = 4;
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    case 3:
        if (CARDGAME_stepPulseCard(battle, screen)) {
            battle->unk445 = 2;
            battle->unk423 = 4;
            if (mode == 2) {
                screen->closePanel(screen, 0);
            }
        }
        CARDGAME_showCardInfo(battle, screen, 0);
        break;
    case 4:
        if (battle->unk434 * 4 + 5 < battle->unk424++) {
            battle->unk440 = battle->unk43C;
            switch (battle->unk438) {
            case 7:
                /* the picked card goes to the top of the hand */
                card = battle->sides[0].pile.deck[battle->sides[0].pile.deckTop];

                battle->sides[0].pile.deck[battle->sides[0].pile.deckTop] = battle->sides[0].pile.deck[battle->sides[0].pile.deckTop + battle->unk440];
                battle->sides[0].pile.deck[battle->sides[0].pile.deckTop + battle->unk440] = card;
                battle->unk440 = battle->sides[0].pile.deckTop;
                battle->shufflePile(battle, battle->sides[0].pile.deckTop + 1, battle->sides[0].pile.deckCount - 1);
                break;
            case 13:
                battle->unk440 = battle->unk30A[battle->unk440 + battle->sides[1].pile.deckTop].unk0;
                CARDGAME_sortOpponentCards(battle);
                break;
            }
            battle->unk46F[battle->unk440] = 1;
            result = battle->unk445;
            battle->unk423 = 0;
            battle->unk421 = 0;
            battle->unk420 = 0;
            battle->unk421 = 0;
        }
        break;
    }
    return result;
}

/* The computer marks (unk46F) the cards of its hand it plays: up to six that
   can be played, but not its kind 5 ones, paying their points; 1 */
s32 CARDGAME_pickComputerCards(CardBattle *battle, CardScreen *screen) {
    s32 i;
    s32 card;

    for (i = 0; i < battle->sides[1].pile.handCount; i++) {
        battle->unk46F[i] = 0;
        if (battle->unk444 < 6 && CARDGAME_canPlayCard(battle, battle->sides[1].pile.points, battle->sides[1].pile.hand[i])) {
            card = battle->sides[1].pile.hand[i];
            if (battle->unk35C[card - 40].unk0 != 5) {
                CARDGAME_addCardPoints(battle, screen, &battle->sides[1].pile, 0, card);
                battle->unk46F[i] = 1;
                battle->unk444++;
            }
        }
    }
    return 1;
}

/* Sets unk440 to the unk446-marked card of the pile unk438 picks with the highest image unk8 (the lowest when lowest != 0), or -1 */
void CARDGAME_pickBestPileCard(CardBattle *battle, CardScreen *screen, s32 lowest) {
    CardDrawer drawer;
    CardImageHeader *header;
    CardImageHeader *current;
    s32 count = 0;
    s32 card;
    s32 best;
    s32 i;

    /* the match depends on cases 11 and 13 having bodies of their own in
       both switches */
    switch (battle->unk438) {
    case 5:
        count = battle->sides[0].pile.handCount;
        break;
    case 7:
        count = battle->sides[0].pile.deckCount;
        break;
    case 11:
        count = battle->sides[1].pile.handCount;
        break;
    case 13:
        count = battle->sides[1].pile.handCount;
        break;
    case 9:
        count = battle->sides[0].pile.discardCount;
        break;
    case 15:
        count = battle->sides[1].pile.discardCount;
        break;
    }
    header = NULL;
    card = 0;
    initCardDrawer(&drawer);
    best = -1;
    for (i = 0; i < count; i++) {
        if (battle->unk446[i] != 0) {
            switch (battle->unk438) {
            case 5:
                card = battle->sides[0].pile.hand[i];
                break;
            case 7:
                card = battle->sides[0].pile.deck[i];
                break;
            case 11:
                card = battle->sides[1].pile.hand[i];
                break;
            case 13:
                card = battle->sides[1].pile.hand[i];
                break;
            case 9:
                card = battle->sides[0].pile.discards[i];
                break;
            case 15:
                card = battle->sides[1].pile.discards[i];
                break;
            }
            drawer.setCard(battle->cards[card] + 1);
            current = drawer.card;
            if (best != -1) {
                if (lowest == 0) {
                    if (current->unk8 >= header->unk8) {
                        best = i;
                        header = current;
                    }
                } else if (current->unk8 < header->unk8) {
                    best = i;
                    header = current;
                }
            } else {
                best = i;
                header = current;
            }
        }
    }
    battle->unk440 = best;
}

/* The computer's pick from its deck: the first card flagged (unk446) from its
   top up to unk41B, or else the last one flagged */
void CARDGAME_pickComputerDeckCard(CardBattle *battle, CardScreen *screen) {
    s32 i;
    s32 found = 0;

    for (i = battle->sides[1].pile.deckTop; i < battle->unk41B; i++) {
        if (battle->unk446[i - battle->sides[1].pile.deckTop] != 0) {
            battle->unk440 = i;
            found = 1;
            break;
        }
    }
    if (!found) {
        for (i = 39; battle->sides[1].pile.deckTop < i; i--) {
            if (battle->unk446[i - battle->sides[1].pile.deckTop] != 0) {
                break;
            }
        }
        battle->unk440 = i;
    }
    battle->unk46F[battle->unk440] = 1;
}

/* Picks the player's card with the lowest header value unk8 */
void CARDGAME_pickLowestPlayerCard(CardBattle *battle, CardScreen *screen) {
    CardDrawer drawer;
    s32 best = battle->sides[0].pile.deckTop;
    s32 lowest;
    s32 i;

    initCardDrawer(&drawer);
    lowest = 400;
    for (i = battle->sides[0].pile.deckTop; i < 40; i++) {
        drawer.setCard(battle->cards[battle->sides[0].pile.deck[i]] + 1);
        if (drawer.card->unk8 < lowest) {
            lowest = drawer.card->unk8;
            best = i;
        }
    }
    battle->unk440 = best;
}

/* Shows the card being played as sprite 15 and the panels with flags, and
   starts CARDGAME_stepPileChoice's choice */
void CARDGAME_startPileChoice(CardBattle *battle, CardScreen *screen, s32 arg2) {
    s32 i;

    screen->resetPanels(screen);
    screen->setPanelFlags(screen, arg2);
    battle->unk440 = 0;
    battle->stepState = 1;
    battle->unk438 = arg2;
    screen->addSprite(screen, 15, 0xE500, 0x6100);
    screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
    screen->sprites[15].scaleX = 0;
    screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
    screen->openPanels(screen);
    battle->unk498.unk5 = 2;
    battle->unk498.unk6[15] = 0;
    for (i = 0; i < 15; i++) {
        battle->unk46F[i] = 0;
    }
    battle->unk498.unk1 = 1;
}

/* The steps of CARDGAME_startPileChoice: confirming is allowed when the pile the panel flags (unk438) pick has cards; 1 then, 0 on leaving with triangle, -1 until then */
s32 CARDGAME_stepPileChoice(CardBattle *battle, CardScreen *screen) {
    s32 result = -1;

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            battle->stepState = 2;
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS)) {
            switch (battle->unk438) {
            case 0x400:
            case 0x1400:
                if (battle->sides[0].pile.discardCount != 0) {
                    result = 1;
                }
                break;
            case 0x1000:
                if (battle->sides[0].pile.deckCount != 0) {
                    result = 1;
                }
                break;
            case 0x4000:
                if (battle->sides[0].pile.handCount != 0) {
                    result = 1;
                }
                break;
            case 0x2000:
                if (battle->sides[1].pile.deckCount != 0) {
                    result = 1;
                }
                break;
            case 0x8000:
                if (battle->sides[1].pile.handCount != 0) {
                    result = 1;
                }
                break;
            default:
                result = 1;
                break;
            }
            if (result == 1) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            screen->closePanels(screen);
            battle->unk440 = 1;
            battle->stepState = 3;
            screen->scaleSprite(screen, 15, 4, 0, 0x1000);
            battle->unk498.unk1 = 2;
        }
        break;
    case 3:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            screen->removeSprite(screen, 15);
            screen->clearPanelFlags(screen);
            result = 0;
        }
        break;
    }
    return result;
}

/* Shows the last card played as sprite 15; with mode 0, or mode 1 and a colour 6 card before it, the card before it can be picked too */
void CARDGAME_startPreviousCardChoice(CardBattle *battle, CardScreen *screen, s32 mode) {
    CardDrawer drawer;
    s32 i;
    s32 j;
    s32 ok;
    s32 card;
    s32 sprite;

    screen->resetPanels(screen);
    battle->unk440 = 0;
    battle->stepState = 1;
    battle->unk438 = 0;
    screen->addSprite(screen, 15, 0xE500, 0x6100);
    screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
    screen->sprites[15].scaleX = 0;
    screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
    screen->openPanels(screen);
    for (i = 0; i < 15; i++) {
        battle->unk498.unk6[i] = 1;
    }
    battle->unk498.unk6[15] = 0;
    for (j = 0; j < 15; j++) {
        battle->unk46F[j] = 0;
    }
    if (battle->record.entryCount != 0) {
        ok = 0;
        if (mode == 0) {
            ok = 1;
        } else if (mode == 1) {
            card = battle->record.entries[battle->record.entryCount - 1].unk0;
            initCardDrawer(&drawer);
            drawer.setCard(battle->cards[card] + 1);
            if (drawer.card->color == 6) {
                ok = 1;
            }
        }
        if (ok) {
            sprite = battle->record.entryCount + 11;
            screen->sprites[sprite].unk48 |= 1;
            battle->unk498.unk6[sprite] = 0;
            battle->unk438 = 1;
        }
    }
    battle->unk498.unk1 = 1;
}

/* The steps of CARDGAME_startPreviousCardChoice: confirming takes the card before the last one played, if it can be taken; 1 then, 0 on leaving with triangle, -1 until then */
s32 CARDGAME_stepPreviousCardChoice(CardBattle *battle, CardScreen *screen) {
    s32 result = -1;
    s32 sprite;

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            battle->stepState = 2;
            if (battle->record.entryCount != 0) {
                screen->sprites[battle->record.entryCount + 11].unk48 |= 1;
            }
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS)) {
            if (battle->unk438 == 1) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                sprite = battle->record.entryCount + 11;
                screen->sprites[sprite].unk48 &= ~1;
                battle->unk46F[sprite] = battle->record.entryCount + 1;
                result = 1;
                battle->record.entries[battle->record.entryCount - 1].unk2 = battle->record.entryCount;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            screen->closePanels(screen);
            battle->unk440 = 1;
            battle->stepState = 3;
            screen->scaleSprite(screen, 15, 4, 0, 0x1000);
            battle->unk498.unk1 = 2;
        }
        break;
    case 3:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            screen->removeSprite(screen, 15);
            screen->clearPanelFlags(screen);
            result = 0;
        }
        break;
    }
    return result;
}

/* Shows the card being played as sprite 15 and lets the slots out that its target picks (a side of owner's, both, or a card colour) be chosen: unk46F marks them, unk438 is 1 if there are any */
void CARDGAME_showTargetSlots(CardBattle *battle, CardScreen *screen, s32 owner, s32 target) {
    s32 i;
    s32 ok;
    s32 card;
    s32 j;

    screen->resetPanels(screen);
    battle->unk440 = 0;
    battle->stepState = 1;
    screen->addSprite(screen, 15, 0xE500, 0x6100);
    screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
    screen->sprites[15].scaleX = 0;
    screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
    screen->openPanels(screen);
    battle->unk438 = 0;
    for (i = 0, ok = 0; i < 12; i++, ok = 0) {
        battle->unk46F[i] = 0;
        battle->unk498.unk6[i] = 1;
        screen->sprites[i].unk48 &= ~1;
        if (i < 6) {
            if (i >= battle->players[0].slotCount) {
                continue;
            }
            card = battle->players[0].slots[i].card;
        } else {
            if (i - 6 >= battle->players[1].slotCount) {
                continue;
            }
            card = battle->players[1].slots[i - 6].card;
        }
        switch (target) {
        case 1:
            if (owner == 0) {
                if (i < 6) {
                    ok = 1;
                }
            } else if (i >= 6) {
                ok = 1;
            }
            break;
        case 2:
            if (owner == 0) {
                if (i >= 6) {
                    ok = 1;
                }
            } else if (i < 6) {
                ok = 1;
            }
            break;
        case 3:
            ok = 1;
            break;
        case 4:
            if (screen->getCardColor(screen, card) != 1) {
                ok = 1;
            }
            break;
        case 5:
            if (screen->getCardColor(screen, card) != 2) {
                ok = 1;
            }
            break;
        case 6:
            if (screen->getCardColor(screen, card) == 3) {
                ok = 1;
            }
            break;
        case 7:
            if (screen->getCardColor(screen, card) != 4) {
                ok = 1;
            }
            break;
        case 8:
            if (screen->getCardColor(screen, card) == 6) {
                ok = 1;
            }
            break;
        }
        if (ok) {
            battle->unk46F[i] = 1;
            battle->unk498.unk6[i] = 0;
            battle->unk438 = 1;
        }
    }
    for (j = 0; j < 3; j++) {
        battle->unk498.unk6[j + 12] = 1;
    }
    battle->unk498.unk6[15] = 0;
    battle->unk498.unk1 = 1;
}

/* The steps of CARDGAME_showTargetSlots: highlights the marked slots (unk46F); confirming needs one (unk438); 1 then, 0 on leaving with triangle, -1 until then */
s32 CARDGAME_stepTargetSlots(CardBattle *battle, CardScreen *screen) {
    s32 result = -1;
    s32 i;

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            battle->stepState = 2;
            for (i = 0; i < 12; i++) {
                if (battle->unk46F[i] != 0) {
                    screen->sprites[i].unk48 |= 1;
                }
            }
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_CROSS)) {
            if (battle->unk438 != 0) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                result = 1;
                for (i = 0; i < 12; i++) {
                    if (battle->unk46F[i] != 0) {
                        screen->sprites[i].unk48 &= ~1;
                    }
                }
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            screen->closePanels(screen);
            battle->unk440 = 1;
            battle->stepState = 3;
            screen->scaleSprite(screen, 15, 4, 0, 0x1000);
            battle->unk498.unk1 = 2;
        }
        break;
    case 3:
        if (screen->panels[0].state == 0 && battle->unk498.unk0 == 0) {
            screen->removeSprite(screen, 15);
            screen->clearPanelFlags(screen);
            result = 0;
            for (i = 0; i < 12; i++) {
                if (battle->unk46F[i] != 0) {
                    screen->sprites[i].unk48 &= ~1;
                }
            }
        }
        break;
    }
    return result;
}

/* Counts a card of the colour it has on a side's panel (at most 99); 1 if it has one */
s32 CARDGAME_addColorCount(CardBattle *battle, CardScreen *screen, s32 side, s32 card) {
    CardDrawer drawer;
    CardPile *pile = &battle->sides[side].pile;
    s32 color;
    s32 done = 0;

    initCardDrawer(&drawer);
    drawer.setCard(battle->cards[card] + 1);
    color = drawer.card->color - 1;
    if (color < 5) {
        if (pile->points[color] < 99) {
            pile->points[color]++;
        }
        screen->setPanelValue(screen, side, color, pile->points[color]);
        done = 1;
    }
    return done;
}

/* Shakes sprite index, then shrinks it to nothing; 1 once done */
s32 CARDGAME_stepShakeAway(CardBattle *battle, CardScreen *screen, s32 index) {
    s32 done = 0;

    switch (battle->unk424) {
    case 0:
    default:
        screen->startShake(screen, index);
        battle->unk424 = 1;
        break;
    case 1:
        if (screen->sprites[index].state == 1) {
            battle->unk424 = 2;
            screen->scaleSprite(screen, index, 5, 0, 0x1000);
        }
        break;
    case 2:
        if (screen->sprites[index].state == 1) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Puts the card of side's slot index on its owner's discards, on
   the panel */
void CARDGAME_discardSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index) {
    switch (battle->players[side].slots[index].side) {
    case 0:
        battle->sides[0].pile.discards[battle->sides[0].pile.discardCount] = battle->players[side].slots[index].card;
        battle->sides[0].pile.discardCount++;
        screen->setPanelValue(screen, 0, 7, battle->sides[0].pile.discardCount);
        break;
    case 1:
        battle->sides[1].pile.discards[battle->sides[1].pile.discardCount] = battle->players[side].slots[index].card;
        battle->sides[1].pile.discardCount++;
        screen->setPanelValue(screen, 1, 7, battle->sides[1].pile.discardCount);
        break;
    }
}

/* Shakes side's slot index away, then CARDGAME_discardSlotCard; 1 once done */
s32 CARDGAME_stepDiscardSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index) {
    s32 ok = 0;

    if (CARDGAME_stepShakeAway(battle, screen, side != 0 ? index + 6 : index)) {
        CARDGAME_discardSlotCard(battle, screen, side, index);
        ok = 1;
    }
    return ok;
}

/* Moves sprite index off the left of the screen; 1 once it is there */
s32 CARDGAME_stepSendOff(CardBattle *battle, CardScreen *screen, s32 index) {
    s32 done = 0;

    switch (battle->unk424) {
    case 0:
    default:
        battle->unk424 = 1;
        screen->sprites[index].moving = 1;
        screen->startMove(screen, index, 15, -0x5000, 0x6100);
        screen->setSpriteScale(screen, index, 0x1200, 0x1200);
        break;
    case 1:
        if (screen->sprites[index].state == 1) {
            screen->sprites[index].moving = 0;
            screen->sprites[index].scaleX = 0;
            done = 1;
        }
        break;
    }
    return done;
}

/* Puts the card of side's slot index back in its owner's hand, on the panel */
void CARDGAME_returnSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index) {
    switch (battle->players[side].slots[index].side) {
    case 0:
        battle->sides[0].pile.hand[battle->sides[0].pile.handCount] = battle->players[side].slots[index].card;
        battle->sides[0].pile.handCount++;
        screen->setPanelValue(screen, 0, 6, battle->sides[0].pile.handCount);
        break;
    case 1:
        battle->sides[1].pile.hand[battle->sides[1].pile.handCount] = battle->players[side].slots[index].card;
        battle->sides[1].pile.handCount++;
        screen->setPanelValue(screen, 1, 6, battle->sides[1].pile.handCount);
        break;
    }
}

/* Sends side's slot index off, then CARDGAME_returnSlotCard; 1 once done */
s32 CARDGAME_stepReturnSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index) {
    s32 ok = 0;

    if (CARDGAME_stepSendOff(battle, screen, side != 0 ? index + 6 : index)) {
        CARDGAME_returnSlotCard(battle, screen, side, index);
        ok = 1;
    }
    return ok;
}

/* Starts effect 3 (arg2 0) or 4 on the flagged cards in play, and plays a
   sound if there were any */
void CARDGAME_startSlotEffects(CardBattle *battle, CardScreen *screen, s32 arg2) {
    s32 found = 0;
    s32 i;

    for (i = 0; i < 12; i++) {
        if (battle->unk46F[i] != 0) {
            if (i < 6) {
                if (i < battle->players[0].slotCount) {
                    screen->startEffect(screen, i, arg2);
                    found = 1;
                }
            } else if (i - 6 < battle->players[1].slotCount) {
                screen->startEffect(screen, i, arg2);
                found = 1;
            }
        }
    }
    if (found) {
        switch (arg2) {
        case 0:
        default:
            SOUND.playSound(0x9C0001);
            break;
        case 1:
            SOUND.playSound(0x9C0000);
            break;
        }
    }
    battle->unk424 = 0;
}

/* Counts unk424 up by the frame time; whether it passed duration */
s32 CARDGAME_waitFor(CardBattle *battle, CardScreen *screen, s32 duration) {
    battle->unk424 += GFX.funcs.getFrameTime();
    return duration < battle->unk424;
}

/* Starts moving the marked slots (unk46F) by an offset packed as x << 16 | y */
void CARDGAME_moveMarkedSlots(CardBattle *battle, CardScreen *screen, s32 offset, s32 mode) {
    s16 dx = offset >> 16;
    s16 dy = offset;
    s32 i;

    battle->unk424 = 0;
    battle->unk428 = dx;
    battle->unk42C = dy;
    battle->unk430 = dx;
    if (dx < 0) {
        battle->unk430 = -dx;
    }
    battle->unk434 = dy;
    if (dy < 0) {
        battle->unk434 = -dy;
    }
    for (i = 0; i < 12; i++) {
        if (battle->unk46F[i] != 0) {
            if (i < 6) {
                if (i >= battle->players[0].slotCount) {
                    continue;
                }
                battle->players[0].slots[i].unk2 += dx;
                battle->players[0].slots[i].unk4 += dy;
                if (mode == 2) {
                    battle->players[0].slots[i].unk2 = battle->players[0].slots[i].unk6 * -1;
                }
            } else {
                if (i - 6 >= battle->players[1].slotCount) {
                    continue;
                }
                battle->players[1].slots[i - 6].unk2 += dx;
                battle->players[1].slots[i - 6].unk4 += dy;
                if (mode == 2) {
                    battle->players[1].slots[i - 6].unk2 = battle->players[1].slots[i - 6].unk6 * -1;
                }
            }
            if (mode == 0) {
                screen->startShake(screen, i);
            } else {
                screen->startRecovery(screen, i);
            }
        }
    }
}

/* Counts the marked slots' unk6 and unk8 up or down by one a frame (sign of unk428/unk42C, for unk430/unk434 frames, clamped to 0..99) with their sprites; when both are over, marks the slots whose unk8 reached 0 */
s32 CARDGAME_stepSlotStats(CardBattle *battle, CardScreen *screen) {
    s32 done = 1;
    s32 i;

    if (battle->unk424 < battle->unk430) {
        for (i = 0; i < 12; i++) {
            if (battle->unk46F[i] != 0) {
                if (i < 6) {
                    if (i < battle->players[0].slotCount) {
                        if (battle->unk428 > 0) {
                            if (battle->players[0].slots[i].unk6 < 99) {
                                battle->players[0].slots[i].unk6++;
                                screen->sprites[i].unk43++;
                            }
                        } else if (battle->players[0].slots[i].unk6 > 0) {
                            battle->players[0].slots[i].unk6--;
                            screen->sprites[i].unk43--;
                        }
                    }
                } else if (i - 6 < battle->players[1].slotCount) {
                    if (battle->unk428 > 0) {
                        if (battle->players[1].slots[i - 6].unk6 < 99) {
                            battle->players[1].slots[i - 6].unk6++;
                            screen->sprites[i].unk43++;
                        }
                    } else if (battle->players[1].slots[i - 6].unk6 > 0) {
                        battle->players[1].slots[i - 6].unk6--;
                        screen->sprites[i].unk43--;
                    }
                }
            }
        }
        done = 0;
    }
    if (battle->unk424 < battle->unk434) {
        for (i = 0; i < 12; i++) {
            if (battle->unk46F[i] != 0) {
                if (i < 6) {
                    if (i < battle->players[0].slotCount) {
                        if (battle->unk42C > 0) {
                            if (battle->players[0].slots[i].unk8 < 99) {
                                battle->players[0].slots[i].unk8++;
                                screen->sprites[i].unk44++;
                            }
                        } else if (battle->players[0].slots[i].unk8 > 0) {
                            battle->players[0].slots[i].unk8--;
                            screen->sprites[i].unk44--;
                        }
                    }
                } else if (i - 6 < battle->players[1].slotCount) {
                    if (battle->unk42C > 0) {
                        if (battle->players[1].slots[i - 6].unk8 < 99) {
                            battle->players[1].slots[i - 6].unk8++;
                            screen->sprites[i].unk44++;
                        }
                    } else if (battle->players[1].slots[i - 6].unk8 > 0) {
                        battle->players[1].slots[i - 6].unk8--;
                        screen->sprites[i].unk44--;
                    }
                }
            }
        }
        done = 0;
    }
    battle->unk424++;
    if (done != 0) {
        for (i = 0; i < 12; i++) {
            battle->unk46F[i] = 0;
            if (i < 6) {
                if (i < battle->players[0].slotCount && battle->players[0].slots[i].unk8 <= 0) {
                    battle->unk46F[i] = 1;
                }
            } else if (i - 6 < battle->players[1].slotCount && battle->players[1].slots[i - 6].unk8 <= 0) {
                battle->unk46F[i] = 1;
            }
        }
    }
    return done;
}

/* Marks in unk46F the slots out that the last card played applies to, by its target (record.entries[].unk5): a side, both, or a card colour */
void CARDGAME_markTargetSlots(CardBattle *battle, CardScreen *screen) {
    s32 i;
    s32 n;
    s32 owner;
    s32 card;

    n = battle->record.entryCount - 1;
    owner = battle->record.entries[n].unk4;
    for (i = 0; i < 12; i++) {
        battle->unk46F[i] = 0;
        if (i < 6) {
            if (i >= battle->players[0].slotCount) {
                continue;
            }
            card = battle->players[0].slots[i].card;
        } else {
            if (i - 6 >= battle->players[1].slotCount) {
                continue;
            }
            card = battle->players[1].slots[i - 6].card;
        }
        switch (battle->record.entries[n].unk5) {
        case 1:
            if (owner == 0) {
                if (i < 6) {
                    battle->unk46F[i] = 1;
                }
            } else if (i >= 6) {
                battle->unk46F[i] = 1;
            }
            break;
        case 2:
            if (owner == 0) {
                if (i >= 6) {
                    battle->unk46F[i] = 1;
                }
            } else if (i < 6) {
                battle->unk46F[i] = 1;
            }
            break;
        case 3:
            battle->unk46F[i] = 1;
            break;
        case 4:
            if (screen->getCardColor(screen, card) != 1) {
                battle->unk46F[i] = 1;
            }
            break;
        case 5:
            if (screen->getCardColor(screen, card) != 2) {
                battle->unk46F[i] = 1;
            }
            break;
        case 6:
            if (screen->getCardColor(screen, card) == 3) {
                battle->unk46F[i] = 1;
            }
            break;
        case 7:
            if (screen->getCardColor(screen, card) != 4) {
                battle->unk46F[i] = 1;
            }
            break;
        case 8:
            if (screen->getCardColor(screen, card) == 6) {
                battle->unk46F[i] = 1;
            }
            break;
        }
    }
}

/* Starts a step's first state */
void CARDGAME_beginStep(CardBattle *battle, CardScreen *screen) {
    battle->stepState = 1;
}

/* Removes the slots marked in unk46F: slides the cards after them left on screen, then moves their slots and sprites down and shrinks slotCount; 1 when over */
s32 CARDGAME_removeMarkedSlots(CardBattle *battle, CardScreen *screen) {
    s32 result = 0;
    s32 side, i, j, count;
    /* the match depends on case 3 having variables of its own */
    s32 player, k;
    s32 from, to;
    s8 *marks;
    s8 mark;
    CardSprite sprite;

    switch (battle->stepState) {
    case 1:
        CARDGAME_markedCounts[0] = CARDGAME_markedCounts[1] = 0;
        CARDGAME_slotMoveCounts[0] = CARDGAME_slotMoveCounts[1] = 0;
        for (side = 0; side < 2; side++) {
            marks = &battle->unk46F[side * 6];
            for (i = 0; i < battle->players[side].slotCount; i++) {
                if (marks[i] == 1) {
                    CARDGAME_markedCounts[side]++;
                }
            }
            count = 0;
            for (i = 0; i < battle->players[side].slotCount - 1; i++) {
                if (marks[i] == 1) {
                    for (j = i + 1; j < battle->players[side].slotCount; j++) {
                        if (marks[j] == 0) {
                            mark = marks[i];
                            marks[i] = marks[j];
                            marks[j] = mark;
                            CARDGAME_slotMoves[side][count][0] = i;
                            CARDGAME_slotMoves[side][count][1] = j;
                            count++;
                            break;
                        }
                    }
                }
            }
            CARDGAME_slotMoveCounts[side] = count;
            if (side == 0) {
                for (i = 0; i < count; i++) {
#if VERSION_US
                    screen->startMove(screen, CARDGAME_slotMoves[0][i][1], 10, CARDGAME_slotMoves[0][i][0] * 0x2900 + 0x1800, 0x9000);
#elif VERSION_EU
                    screen->startMove(screen, CARDGAME_slotMoves[0][i][1], 10,
                                   CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + CARDGAME_slotMoves[0][i][0] * 0x2900,
                                   CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1]);
#endif
                }
            } else {
                for (i = 0; i < count; i++) {
#if VERSION_US
                    screen->startMove(screen, CARDGAME_slotMoves[1][i][1] + 6, 10, CARDGAME_slotMoves[1][i][0] * 0x2900 + 0x1800, 0x3200);
#elif VERSION_EU
                    screen->startMove(screen, CARDGAME_slotMoves[1][i][1] + 6, 10,
                                   CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + CARDGAME_slotMoves[1][i][0] * 0x2900,
                                   CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3]);
#endif
                }
            }
        }
        if (CARDGAME_markedCounts[0] + CARDGAME_markedCounts[1] != 0) {
            battle->stepState = 2;
            battle->unk424 = 20;
        } else {
            battle->stepState = 4;
        }
        break;
    case 2:
        battle->unk424 -= GFX.funcs.getFrameTime();
        if (battle->unk424 <= 0) {
            battle->stepState = 3;
        }
        break;
    case 3:
        for (player = 0; player < 2; player++) {
            for (k = 0; k < CARDGAME_slotMoveCounts[player]; k++) {
                from = CARDGAME_slotMoves[player][k][0];
                to = CARDGAME_slotMoves[player][k][1];
                battle->players[player].slots[from] = battle->players[player].slots[to];
                from += player * 6;
                to += player * 6;
                sprite = screen->sprites[from];
                screen->sprites[from] = screen->sprites[to];
                screen->sprites[to] = sprite;
            }
            battle->players[player].slotCount -= CARDGAME_markedCounts[player];
            for (k = 0; k < 6; k++) {
                if (k >= battle->players[player].slotCount) {
                    screen->removeSprite(screen, player * 6 + k);
                    screen->sprites[player * 6 + k].scaleX = 0;
                }
            }
        }
        battle->stepState = 4;
        break;
    case 4:
        result = 1;
        break;
    }
    return result;
}

/* Marks in unk446 the cards of a side's unk64 (kind 2), unk14 (3) or unk78 (4) whose colour has its bit (CARDGAME_colorFlags) in flags (kind 16 cards only with flags bit 0, the others with bit 1); 1 if any */
s32 CARDGAME_markPileCardsByColor(CardBattle *battle, CardScreen *screen, s32 side, s32 kind, s32 flags) {
    CardDrawer drawer;
    s32 found;
    s32 count = 0;
    s32 card;
    s32 i;
    s32 ok;
    s32 j;
    s32 id;

    found = 0;
    switch (kind) {
    case 2:
        count = battle->sides[side].pile.handCount;
        break;
    case 3:
        count = battle->sides[side].pile.deckCount;
        break;
    case 4:
        count = battle->sides[side].pile.discardCount;
        break;
    }
    card = 0;
    for (i = 0; i < count; i++) {
        battle->unk446[i] = 0;
        switch (kind) {
        case 2:
            card = battle->sides[side].pile.hand[i];
            break;
        case 3:
            card = battle->sides[side].pile.deck[i + battle->sides[side].pile.deckTop];
            break;
        case 4:
            card = battle->sides[side].pile.discards[i];
            break;
        }
        id = battle->cards[card];
        ok = 0;
        initCardDrawer(&drawer);
        drawer.setCard(id + 1);
        if (drawer.card->kind == 0x10) {
            ok = flags & 1;
        } else if (flags & 2) {
            ok = 1;
        }
        if (ok) {
            for (j = 0; j < 6; j++) {
                if ((flags & CARDGAME_colorFlags[j]) && drawer.card->color == j + 1) {
                    battle->unk446[i] = 1;
                    found = 1;
                    break;
                }
            }
        }
    }
    return found;
}

/* Marks in unk446 the slots of the sides flags picks (0x100 its own, 0x200 the other) whose card colour has its bit (CARDGAME_colorFlags) in flags; 1 if any */
s32 CARDGAME_markSlotsByColor(CardBattle *battle, CardScreen *screen, s32 arg2, s32 flags) {
    CardDrawer drawer;
    s32 found = 0;
    s32 card = 0;
    s32 i;
    s32 skip;
    s32 j;

    initCardDrawer(&drawer);
    battle->unk445 = 0;
    for (i = 0, skip = 0; i < 15; i++, skip = 0) {
        battle->unk446[i] = 0;
        if (i < 6) {
            if ((arg2 == 0 && (flags & 0x100)) || (arg2 != 0 && (flags & 0x200))) {
                battle->unk445 |= 1;
                if (i < battle->players[0].slotCount) {
                    card = battle->players[0].slots[i].card;
                } else {
                    skip = 1;
                }
            } else {
                skip = 1;
            }
        } else if (i < 12) {
            if ((arg2 == 0 && (flags & 0x200)) || (arg2 != 0 && (flags & 0x100))) {
                battle->unk445 |= 2;
                if (i - 6 < battle->players[1].slotCount) {
                    card = battle->players[1].slots[i - 6].card;
                } else {
                    skip = 1;
                }
            } else {
                skip = 1;
            }
        } else {
            skip = 1;
        }
        if (!skip) {
            drawer.setCard(battle->cards[card] + 1);
            for (j = 0; j < 6; j++) {
                if ((flags & CARDGAME_colorFlags[j]) && drawer.card->color == j + 1) {
                    battle->unk446[i] = 1;
                    found = 1;
                    break;
                }
            }
        }
    }
    return found;
}

/* Starts a count of side's hand and discards (unk428 and unk42C) */
void CARDGAME_startHandCount(CardBattle *battle, CardScreen *screen, s32 side) {
    battle->stepState = 1;
    battle->unk424 = 0;
    battle->unk428 = battle->sides[side].pile.handCount;
    battle->unk42C = battle->sides[side].pile.discardCount;
    battle->unk430 = 0;
}

/* Counts a side's unk64 cards over to unk78 on its panel, one every 7 frames, then moves them; 1 when done */
s32 CARDGAME_discardHand(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    s32 more;
    s32 i;

    switch (battle->stepState) {
    case 1:
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk430 += GFX.funcs.getFrameTime();
        if (battle->unk430 >= 7) {
            more = 0;
            if (battle->unk428 > 0) {
                more = 1;
                battle->unk428--;
                battle->unk42C++;
            }
            if (!more) {
                battle->stepState = 2;
            }
            screen->setPanelValue(screen, side, 6, battle->unk428);
            screen->setPanelValue(screen, side, 7, battle->unk42C);
            battle->unk430 -= 7;
        }
        break;
    case 2:
        for (i = 0; i < battle->sides[side].pile.handCount; i++) {
            battle->sides[side].pile.discards[battle->sides[side].pile.discardCount] = battle->sides[side].pile.hand[i];
            battle->sides[side].pile.discardCount++;
        }
        battle->sides[side].pile.handCount = 0;
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_stepColorValue: amount (unk434, below 0 to take) one at a
   time, one each interval frames (unk430) */
void CARDGAME_startColorChange(CardBattle *battle, CardScreen *screen, s32 arg2, s32 arg3) {
    battle->unk430 = arg3;
    battle->unk434 = arg2;
    battle->unk423 = 1;
}

/* Moves a side's colour value (pile.points[color]) one step each unk430 frames towards using up unk434 (up to 99, down to 0), on its panel; 1 when done */
s32 CARDGAME_stepColorValue(CardBattle *battle, CardScreen *screen, s32 side, s32 color) {
    s32 done = 0;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            screen->setPanelFlags(screen, 1 << (color * 2) << side);
            battle->unk424 = 0;
            battle->unk428 = 0;
            break;
        case 2:
            screen->clearPanelFlags(screen);
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }
    switch (battle->stepState) {
    case 1:
        if (battle->unk424 == battle->unk430 / 2) {
            if (battle->unk434 > 0) {
                if (battle->sides[side].pile.points[color] < 99) {
                    battle->sides[side].pile.points[color]++;
                }
                battle->unk434--;
                SOUND.playSound(SOUND_COUNT);
            } else {
                if (battle->sides[side].pile.points[color] != 0) {
                    battle->sides[side].pile.points[color]--;
                }
                battle->unk434++;
                SOUND.playSound(SOUND_COUNT);
            }
            screen->setPanelValue(screen, side, color, battle->sides[side].pile.points[color]);
        }
        battle->unk424++;
        if (battle->unk424 > battle->unk430) {
            if (battle->unk434 == 0 || battle->sides[side].pile.points[color] == 0) {
                battle->unk423 = 2;
            } else {
                battle->unk423 = 1;
            }
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_drainColorValues */
void CARDGAME_startColorDrain(CardBattle *battle, CardScreen *screen) {
    CARDGAME_startColorChange(battle, screen, -0x80, 0x10);
    battle->unk438 = 0;
}

/* Counts both sides' colour values (pile.points) down by one each unk430 frames, on the panels, until they are all 0; 1 when done */
s32 CARDGAME_drainColorValues(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 side;
    s32 i;
    s32 any;
    s32 j;
    s32 k;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            screen->setPanelFlags(screen, 0x3FF);
            battle->unk424 = 0;
            battle->unk428 = 0;
            break;
        case 2:
            screen->clearPanelFlags(screen);
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }
    switch (battle->stepState) {
    case 1:
        if (battle->unk424 == battle->unk430 / 2) {
            for (side = 0; side < 2; side++) {
                for (i = 0; i < 5; i++) {
                    if (battle->sides[side].pile.points[i] != 0) {
                        battle->sides[side].pile.points[i]--;
                    }
                    screen->setPanelValue(screen, side, i, battle->sides[side].pile.points[i]);
                }
            }
        }
        battle->unk424++;
        if (battle->unk424 > battle->unk430) {
            any = 0;
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 5; k++) {
                    if (battle->sides[j].pile.points[k] != 0) {
                        any = 1;
                    }
                }
            }
            if (any) {
                battle->unk423 = 1;
            } else {
                battle->unk423 = 2;
            }
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Closes the gauge of the card before the last one */
void CARDGAME_startCloseGauge(CardBattle *battle, CardScreen *screen) {
    battle->unk424 = 0;
    battle->stepState = 1;
    screen->closeGauge(screen, battle->record.entryCount - 2);
}

/* Puts the card played before the last one (record.entries[entryCount - 2]) on its side's unk78 once its sprite has turned; 1 when done */
s32 CARDGAME_discardPrevCard(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 side;
    s32 n;
    s32 i;

    switch (battle->stepState) {
    case 1:
        if (CARDGAME_stepShakeAway(battle, screen, battle->record.entryCount + 10)) {
            battle->unk428 = 10;
            battle->stepState = 2;
            side = battle->record.entries[battle->record.entryCount - 2].unk4;
            battle->sides[side].pile.discards[battle->sides[side].pile.discardCount] = battle->record.entries[battle->record.entryCount - 2].unk0;
            battle->sides[side].pile.discardCount++;
            screen->setPanelValue(screen, 0, 7, battle->sides[0].pile.discardCount);
            screen->setPanelValue(screen, 1, 7, battle->sides[1].pile.discardCount);
        }
        break;
    case 2:
        battle->unk428 -= GFX.funcs.getFrameTime();
        if (battle->unk428 <= 0) {
            battle->stepState = 3;
            n = battle->record.entryCount - 1;
            if (n >= 2) {
                battle->record.entries[battle->record.entryCount - 3].unk2 = 0;
            }
            for (i = 0; i < 15; i++) {
                screen->sprites[i].unk3E[n - 1] = 0;
            }
        }
        break;
    case 3:
        done = 1;
        break;
    }
    return done;
}

/* Keeps the last card played in unk304 (as card + 1) and counts it (unk305);
   1 */
s32 CARDGAME_keepLastCard(CardBattle *battle, CardScreen *screen) {
    s32 card = battle->record.entries[battle->record.entryCount - 1].unk0;

    battle->unk305++;
    battle->unk304 = card + 1;
    return 1;
}

/* Shows side's card at unk440 as sprite 17: of its hand (which 0) or its deck
   (1) */
void CARDGAME_showPileCard(CardBattle *battle, CardScreen *screen, s32 side, s32 which) {
    s32 card;

    screen->addSprite(screen, 17, 0xE500, 0x6100);
    card = 0;
    screen->sprites[17].scaleX = 0;
    switch (which) {
    case 0:
        card = battle->sides[side].pile.hand[battle->unk440];
        battle->unk438 = card;
        break;
    case 1:
        card = battle->sides[side].pile.deck[battle->unk440];
        battle->unk438 = card;
        break;
    }
    screen->setSpriteCard(screen, 17, card);
    screen->scaleSprite(screen, 17, 8, 0x1000, 0x1000);
    battle->unk424 = 0;
    battle->stepState = 1;
}

/* Moves sprite 17 to the side's spot, then puts card unk438 on the side's unk78 pile and takes entry unk440 out of the pile it came from (from 0: unk64, from 1: unk14 after unk4); 1 when over */
s32 CARDGAME_discardPickedCard(CardBattle *battle, CardScreen *screen, s32 side, s32 from) {
    s32 done = 0;
    /* the match depends on the loops of from 1 having a variable of their own */
    s32 i, j;

    switch (battle->stepState) {
    case 1:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 21) {
            screen->startMove(screen, 17, 10, CARDGAME_discardPositions[side][0], CARDGAME_discardPositions[side][1]);
            screen->setSpriteScale(screen, 17, 0, 0);
            battle->stepState = 2;
        }
        break;
    case 2:
        if (screen->sprites[17].state == 1) {
            battle->stepState = 3;
            battle->unk424 = 0;
            battle->sides[side].pile.discards[battle->sides[side].pile.discardCount] = battle->unk438;
            battle->sides[side].pile.discardCount++;
            switch (from) {
            case 0:
                for (i = battle->unk440; i < battle->sides[side].pile.handCount - 1; i++) {
                    battle->sides[side].pile.hand[i] = battle->sides[side].pile.hand[i + 1];
                }
                screen->setPanelValue(screen, side, 6, --battle->sides[side].pile.handCount);
                break;
            case 1:
                if (side == 0) {
                    for (i = battle->unk440; i >= battle->sides[side].pile.deckTop + 1; i--) {
                        battle->sides[side].pile.deck[i] = battle->sides[side].pile.deck[i - 1];
                    }
                    battle->sides[side].pile.deckTop++;
                    battle->sides[side].pile.deckCount--;
                } else {
                    for (j = battle->unk440; j >= battle->sides[side].pile.deckTop + 1; j--) {
                        battle->sides[side].pile.deck[j] = battle->sides[side].pile.deck[j - 1];
                        battle->unk30A[j] = battle->unk30A[j - 1];
                    }
                    if (++battle->unk41B >= 40) {
                        battle->unk41B = 39;
                    }
                    if (++battle->unk41C >= 40) {
                        battle->unk41C = 39;
                    }
                    battle->sides[side].pile.deckTop++;
                    battle->sides[side].pile.deckCount--;
                    for (j = 39; j >= 0; j--) {
                        battle->unk30A[j].unk0 = j;
                    }
                }
                screen->setPanelValue(screen, side, 5, battle->sides[side].pile.deckCount);
                break;
            }
            screen->setPanelValue(screen, side, 7, battle->sides[side].pile.discardCount);
        }
        break;
    case 3:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 46) {
            battle->stepState = 4;
        }
        break;
    case 4:
        done = 1;
        break;
    }
    return done;
}

/* Adds card unk440 of a side's unk78 (which 4) or unk14 to its unk64 */
void CARDGAME_takeCardToHand(CardBattle *battle, CardScreen *screen, s32 side, s32 which) {
    s32 card;
    s32 i;

    battle->unk438 = battle->sides[side].pile.handCount;
    if (which == 4) {
        card = battle->sides[side].pile.discards[battle->unk440];
    } else {
        card = battle->sides[side].pile.deck[battle->unk440];
    }
    battle->sides[side].pile.hand[battle->sides[side].pile.handCount] = card;
    battle->sides[side].pile.handCount++;
    if (battle->unk438 != 0) {
        if (side == 0) {
            battle->unk498.unk1 = 5;
        } else {
            battle->unk498.unk1 = 11;
            battle->unk498.unk4 = 1;
        }
    } else if (side == 0) {
        battle->unk498.unk1 = 17;
    } else {
        battle->unk498.unk1 = 18;
        battle->unk498.unk4 = 1;
    }
    screen->openPanel(screen, side);
    for (i = 0; i < 40; i++) {
        battle->unk498.unk6[i] = 0;
    }
    battle->stepState = 1;
}

/* Moves the card just put in the hand into place, then takes card unk440 out of the deck (or out of the used pile when which is 4) */
s32 CARDGAME_drawFromDeck(CardBattle *battle, CardScreen *screen, s32 side, s32 which) {
    CardDrawer drawer;
    s32 done = 0;
    /* the match depends on a variable of its own for most loops and states */
    s32 ready;
    s32 closed;
    s32 index;
    s32 top;
    s32 last;
    s32 card;
    s32 drawn;
    s32 i;
    s32 j;
    s32 k;
    s32 swap;
    s32 x;

    switch (battle->stepState) {
    case 1:
        ready = 0;
        if (side == 0) {
            ready = screen->panels[0].state == 2;
        } else if (screen->panels[1].state == 2) {
            ready = 1;
        }
        last = battle->sides[side].pile.handCount - 1;
        screen->sprites[last].x = 0x14A00;
        if (ready && battle->unk498.unk0 == 0) {
            x = screen->getHandOffset(battle->sides[side].pile.handCount, last);
            screen->sprites[last].scaleX = 0x1000;
            screen->startMove(screen, last, 15, x + 0x1800, 0x6100);
            battle->stepState = 2;
        }
        break;
    case 2:
        index = battle->sides[side].pile.handCount - 1;
        if (screen->sprites[index].state == 1) {
            if (which == 4) {
                for (i = battle->unk440; i < battle->sides[side].pile.discardCount - 1; i++) {
                    battle->sides[side].pile.discards[i] = battle->sides[side].pile.discards[i + 1];
                }
                battle->sides[side].pile.discardCount--;
                battle->stepState = 4;
                battle->unk424 = 45;
            } else {
                if (side == 0) {
                    for (j = battle->unk440; j >= battle->sides[0].pile.deckTop + 1; j--) {
                        battle->sides[0].pile.deck[j] = battle->sides[0].pile.deck[j - 1];
                    }
                } else {
                    if (battle->unk440 < battle->unk41B) {
                        for (i = battle->unk440; i >= battle->sides[1].pile.deckTop + 1; i--) {
                            battle->sides[1].pile.deck[i] = battle->sides[1].pile.deck[i - 1];
                            battle->unk30A[i] = battle->unk30A[i - 1];
                        }
                    } else {
                        i = battle->unk440;
                        if (battle->unk30A[i].unk1 == 7) {
                            for (; i >= battle->sides[1].pile.deckTop + 1; i--) {
                                battle->sides[1].pile.deck[i] = battle->sides[1].pile.deck[i - 1];
                                battle->unk30A[i] = battle->unk30A[i - 1];
                            }
                            battle->unk41B++;
                            battle->unk41C++;
                        } else {
                            swap = battle->sides[1].pile.deck[i];
                            battle->sides[1].pile.deck[i] = battle->sides[1].pile.deck[39];
                            battle->sides[1].pile.deck[39] = swap;
                            for (i = 39; i >= battle->sides[1].pile.deckTop + 1; i--) {
                                battle->sides[1].pile.deck[i] = battle->sides[1].pile.deck[i - 1];
                                battle->unk30A[i] = battle->unk30A[i - 1];
                            }
                            battle->unk41B++;
                            battle->unk41C++;
                        }
                    }
                    for (k = 39; k >= 0; k--) {
                        battle->unk30A[k].unk0 = k;
                    }
                }
                battle->sides[side].pile.deckTop++;
                battle->sides[side].pile.deckCount--;
                card = battle->sides[side].pile.hand[index];
                initCardDrawer(&drawer);
                drawer.setCard(battle->cards[card] + 1);
                if (drawer.card->color < 6) {
                    battle->stepState = 3;
                    screen->startBlink(screen, index);
                } else {
                    battle->stepState = 4;
                    battle->unk424 = 45;
                }
            }
            screen->setPanelValue(screen, 0, 5, battle->sides[0].pile.deckCount);
            screen->setPanelValue(screen, 0, 6, battle->sides[0].pile.handCount);
            screen->setPanelValue(screen, 0, 7, battle->sides[0].pile.discardCount);
            screen->setPanelValue(screen, 1, 5, battle->sides[1].pile.deckCount);
            screen->setPanelValue(screen, 1, 6, battle->sides[1].pile.handCount);
            screen->setPanelValue(screen, 1, 7, battle->sides[1].pile.discardCount);
        }
        break;
    case 3:
        top = battle->sides[side].pile.handCount - 1;
        if (screen->sprites[top].state == 1) {
            battle->stepState = 4;
            battle->unk424 = 45;
            drawn = battle->sides[side].pile.hand[top];
            initCardDrawer(&drawer);
            drawer.setCard(battle->cards[drawn] + 1);
            if (drawer.card->color < 6) {
                if (battle->sides[side].pile.points[drawer.card->color - 1] < 99) {
                    battle->sides[side].pile.points[drawer.card->color - 1]++;
                }
                screen->setPanelValue(screen, side, drawer.card->color - 1, battle->sides[side].pile.points[drawer.card->color - 1]);
            }
        }
        break;
    case 4:
        battle->unk424 -= GFX.funcs.getFrameTime();
        if (battle->unk424 <= 0) {
            battle->stepState = 5;
            screen->closePanel(screen, side);
            battle->unk498.unk1 = battle->unk498.unk3;
        }
        break;
    case 5:
        closed = 0;
        if (side == 0) {
            closed = screen->panels[0].state == 0;
        } else if (screen->panels[1].state == 0) {
            closed = 1;
        }
        if (closed && battle->unk498.unk0 == 0) {
            battle->stepState = 6;
        }
        break;
    case 6:
        done = 1;
        break;
    }
    return done;
}

/* Starts a count of side's discards and deck (unk428 and unk42C) */
void CARDGAME_startDiscardCount(CardBattle *battle, CardScreen *screen, s32 side) {
    battle->unk424 = 0;
    battle->unk434 = 0;
    battle->unk428 = battle->sides[side].pile.discardCount;
    battle->unk42C = battle->sides[side].pile.deckCount;
    battle->stepState = 1;
}

/* Counts the panel values 7 down into 5, then puts the side's unk78 cards back
   into its deck (unk14); 1 once done */
s32 CARDGAME_returnUsedCards(CardBattle *battle, CardScreen *screen, s32 side) {
    CardPile *pile;
    s16 *deck;
    s16 *used;
    s32 done = 0;
    s32 more;
    s32 i;
    s32 j;

    switch (battle->stepState) {
    case 1:
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        if (battle->unk434 >= 7) {
            more = 0;
            if (battle->unk428 > 0) {
                more = 1;
                battle->unk428--;
                battle->unk42C++;
            }
            if (!more) {
                battle->stepState = 2;
            }
            screen->setPanelValue(screen, side, 7, battle->unk428);
            screen->setPanelValue(screen, side, 5, battle->unk42C);
            battle->unk434 -= 7;
        }
        break;
    case 2:
        pile = &battle->sides[side].pile;
        deck = pile->deck;
        used = pile->discards;
        if (side == 0) {
            j = pile->deckTop - 1;
            for (i = pile->discardCount - 1; i >= 0; i--) {
                deck[j--] = used[i];
                pile->deckTop--;
                pile->deckCount++;
            }
            pile->discardCount = 0;
            battle->shufflePile(battle, pile->deckTop, pile->deckCount);
        } else {
            for (i = pile->discardCount - 1; i >= 0; i--) {
                pile->deckTop--;
                pile->deckCount++;
                for (j = pile->deckTop; j < 40; j++) {
                    deck[j] = deck[j + 1];
                    battle->unk30A[j] = battle->unk30A[j + 1];
                }
                battle->unk41B--;
                battle->unk41C--;
                deck[39] = used[i];
                battle->unk30A[39].unk1 = 7;
            }
            for (i = 39; i >= 0; i--) {
                battle->unk30A[i].unk0 = i;
            }
            pile->discardCount = 0;
        }
        done = 1;
        break;
    }
    return done;
}

/* Starts drawing count cards (unk444) */
void CARDGAME_startDraw(CardBattle *battle, CardScreen *screen, s32 arg2) {
    s32 i;

    for (i = 0; i < 40; i++) {
        battle->unk46F[i] = 0;
    }
    battle->unk444 = arg2;
    battle->unk445 = 0;
}

/* Marks (unk46F) the cards side draws from its deck: from its top for the
   player, by the round's level (unk300) for the computer; unk445 when the
   deck runs out; 1 */
s32 CARDGAME_markDrawnCards(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 i;
    u8 n;
    s32 k;
    s32 m;

    if (battle->unk444 != 0) {
        if (side == 0) {
            n = 0;
            for (i = battle->sides[0].pile.deckTop; i < battle->sides[0].pile.deckTop + battle->unk444; i++) {
                if (i >= 40) {
                    battle->unk445 = 1;
                    battle->unk444 = n;
                    break;
                }
                battle->unk46F[i] = 1;
                n++;
            }
        } else {
            k = battle->sides[1].pile.deckTop;
            m = 39;
            if (battle->unk444 > battle->sides[1].pile.deckCount) {
                battle->unk445 = 1;
                battle->unk444 = battle->sides[1].pile.deckCount;
            }
            for (i = 0; i < battle->unk444; i++) {
                if (battle->unk30A[k].unk1 == battle->unk300 * 2 + 2) {
                    battle->unk46F[k] = 1;
                    k++;
                } else {
                    battle->unk46F[m] = 1;
                    m--;
                }
            }
        }
    }
    return 1;
}

/* Moves side's marked deck cards to its hand and opens its panel */
void CARDGAME_drawMarkedCards(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 i;
    s32 card;
    s32 j;

    battle->unk438 = battle->sides[side].pile.handCount;
#if VERSION_EU
    battle->unk42C = 0;
#endif
    for (i = battle->sides[side].pile.deckTop; i < 40; i++) {
        if (battle->unk46F[i] != 0) {
            card = battle->sides[side].pile.deck[i];
            battle->sides[side].pile.hand[battle->sides[side].pile.handCount] = card;
            battle->sides[side].pile.handCount++;
#if VERSION_EU
            battle->unk42C = 1;
#endif
        }
    }
    for (j = 0; j < 40; j++) {
        battle->unk498.unk6[j] = 0;
    }
    if (battle->unk438 != 0) {
        if (side == 0) {
            battle->unk498.unk1 = 5;
        } else {
            battle->unk498.unk1 = 11;
            battle->unk498.unk4 = 1;
        }
    } else {
        if (side == 0) {
            battle->unk498.unk1 = 17;
        } else {
            battle->unk498.unk1 = 18;
            battle->unk498.unk4 = 1;
        }
    }
    screen->openPanel(screen, side);
    battle->stepState = 1;
}

/* Moves the cards drawn into the hand (from unk438 on) into place one at a time, counting their colours and taking each flagged card (unk46F) out of the deck */
s32 CARDGAME_drawNewCards(CardBattle *battle, CardScreen *screen, s32 side) {
    CardDrawer drawer;
    s32 done = 0;
    s32 ready;
    s32 closed;
    s32 card;
    s32 found;
    /* the match depends on a loop variable of its own for most loops */
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 swap;
    s32 x;

    switch (battle->stepState) {
    case 1:
        ready = 0;
        if (side == 0) {
            ready = screen->panels[0].state == 2;
        } else if (screen->panels[1].state == 2) {
            ready = 1;
        }
        for (k = battle->unk438; k < battle->sides[side].pile.handCount; k++) {
            screen->sprites[k].x = 0x14A00;
        }
        if (ready && battle->unk498.unk0 == 0) {
#if VERSION_US
            battle->stepState = 2;
#elif VERSION_EU
            if (battle->unk42C == 0) {
                screen->openMessage(screen, 0x35, 0, 0, side == 0 ? 2 : 0);
                battle->stepState = 5;
            } else {
                battle->stepState = 2;
            }
#endif
            battle->unk424 = 0;
            battle->unk428 = battle->unk438;
        }
        break;
    case 2:
        x = screen->getHandOffset(battle->sides[side].pile.handCount, battle->unk428);
        screen->sprites[battle->unk428].scaleX = 0x1000;
        screen->startMove(screen, battle->unk428, 15, x + 0x1800, 0x6100);
        battle->stepState = 3;
        break;
    case 3:
        if (screen->sprites[battle->unk428].state == 1) {
            card = battle->sides[side].pile.hand[battle->unk428];
            initCardDrawer(&drawer);
            drawer.setCard(battle->cards[card] + 1);
            if (drawer.card->color < 6) {
                if (battle->sides[side].pile.points[drawer.card->color - 1] < 99) {
                    battle->sides[side].pile.points[drawer.card->color - 1]++;
                }
                screen->setPanelValue(screen, side, drawer.card->color - 1, battle->sides[side].pile.points[drawer.card->color - 1]);
                screen->startBlink(screen, battle->unk428);
                battle->stepState = 4;
            } else {
                battle->unk428++;
                if (battle->unk428 < battle->sides[side].pile.handCount) {
                    battle->stepState = 2;
                } else if (battle->unk445 != 0) {
                    screen->openMessage(screen, 0x35, 0, 0, side == 0 ? 2 : 0);
                    battle->stepState = 5;
                } else {
                    battle->unk424 = 45;
                    battle->stepState = 8;
                }
            }
            for (i = 39, found = 0; i >= 0; i--) {
                if (battle->unk46F[i] != 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                battle->unk46F[i] = 0;
                if (side == 0) {
                    for (m = i; m >= battle->sides[0].pile.deckTop + 1; m--) {
                        battle->sides[0].pile.deck[m] = battle->sides[0].pile.deck[m - 1];
                        battle->unk46F[m] = battle->unk46F[m - 1];
                    }
                } else {
                    if (i < battle->unk41B) {
                        for (j = i; j >= battle->sides[1].pile.deckTop + 1; j--) {
                            battle->sides[1].pile.deck[j] = battle->sides[1].pile.deck[j - 1];
                            battle->unk46F[j] = battle->unk46F[j - 1];
                            battle->unk30A[j] = battle->unk30A[j - 1];
                        }
                    } else {
                        if (battle->unk30A[i].unk1 == 7) {
                            for (j = i; j >= battle->sides[1].pile.deckTop + 1; j--) {
                                battle->sides[1].pile.deck[j] = battle->sides[1].pile.deck[j - 1];
                                battle->unk46F[j] = battle->unk46F[j - 1];
                                battle->unk30A[j] = battle->unk30A[j - 1];
                            }
                            battle->unk41B++;
                            battle->unk41C++;
                        } else {
                            swap = battle->sides[1].pile.deck[i];
                            battle->sides[1].pile.deck[i] = battle->sides[1].pile.deck[39];
                            battle->sides[1].pile.deck[39] = swap;
                            for (j = 39; j >= battle->sides[1].pile.deckTop + 1; j--) {
                                battle->sides[1].pile.deck[j] = battle->sides[1].pile.deck[j - 1];
                                battle->unk46F[j] = battle->unk46F[j - 1];
                                battle->unk30A[j] = battle->unk30A[j - 1];
                            }
                            battle->unk41B++;
                            battle->unk41C++;
                        }
                    }
                    for (n = 39; n >= 0; n--) {
                        battle->unk30A[n].unk0 = n;
                    }
                }
                battle->sides[side].pile.deckTop++;
                battle->sides[side].pile.deckCount--;
            }
        }
        break;
    case 4:
        if (screen->sprites[battle->unk428].state == 1) {
            battle->unk428++;
            if (battle->unk428 < battle->sides[side].pile.handCount) {
                battle->stepState = 2;
            } else if (battle->unk445 != 0) {
                screen->openMessage(screen, 0x35, 0, 0, side == 0 ? 2 : 0);
                battle->stepState = 5;
            } else {
                battle->unk424 = 45;
                battle->stepState = 8;
            }
        }
        break;
    case 5:
        if (screen->message.state == 2) {
            battle->stepState = 6;
        }
        break;
    case 6:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 7;
            screen->closeMessage(screen);
        }
        break;
    case 7:
        if (screen->message.state == 0) {
            battle->unk424 = 45;
            battle->stepState = 8;
        }
        break;
    case 8:
        screen->setPanelValue(screen, 0, 5, battle->sides[0].pile.deckCount);
        screen->setPanelValue(screen, 0, 6, battle->sides[0].pile.handCount);
        screen->setPanelValue(screen, 0, 7, battle->sides[0].pile.discardCount);
        screen->setPanelValue(screen, 1, 5, battle->sides[1].pile.deckCount);
        screen->setPanelValue(screen, 1, 6, battle->sides[1].pile.handCount);
        screen->setPanelValue(screen, 1, 7, battle->sides[1].pile.discardCount);
        battle->unk424 -= GFX.funcs.getFrameTime();
        if (battle->unk424 <= 0) {
            battle->stepState = 9;
            screen->closePanel(screen, side);
            battle->unk498.unk1 = battle->unk498.unk3;
        }
        break;
    case 9:
        closed = 0;
        if (side == 0) {
            closed = screen->panels[0].state == 0;
        } else if (screen->panels[1].state == 0) {
            closed = 1;
        }
        if (closed && battle->unk498.unk0 == 0) {
            battle->stepState = 10;
        }
        break;
    case 10:
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_stepSlotSweep */
void CARDGAME_startSlotSweep(CardBattle *battle, CardScreen *screen) {
    battle->unk428 = 0;
    battle->stepState = 1;
}

/* Goes over the marked slots one by one, discarding their cards (which 0) or
   returning them to the hand (1); 1 once done */
s32 CARDGAME_stepSlotSweep(CardBattle *battle, CardScreen *screen, s32 which) {
    s32 done = 0;
    s32 i;
    s32 ok;

    switch (battle->stepState) {
    case 1:
        for (i = battle->unk428; i < 12; i++) {
            if (battle->unk46F[i] != 0) {
                battle->stepState = 2;
                battle->unk424 = 0;
                battle->unk428 = i;
                battle->unk42C = i >= 6;
                battle->unk430 = i;
                if (i >= 6) {
                    battle->unk430 = i - 6;
                }
                break;
            }
        }
        if (i >= 12) {
            battle->stepState = 3;
        }
        break;
    case 2:
        if (which == 0) {
            ok = CARDGAME_stepDiscardSlotCard(battle, screen, battle->unk42C, battle->unk430);
        } else {
            ok = CARDGAME_stepReturnSlotCard(battle, screen, battle->unk42C, battle->unk430);
        }
        if (ok) {
            battle->stepState = 1;
            battle->unk428++;
        }
        break;
    case 3:
        done = 1;
        break;
    }
    return done;
}

/* Marks (unk3E) the record entries whose effect reaches sprite index, by
   their target (unk5): a side, both, or a colour */
void CARDGAME_markRecordHits(CardBattle *battle, CardScreen *screen, s32 arg2, s32 index) {
    s32 i;
    s32 color;
    s32 n;
    n = battle->record.entryCount - 1;
    color = screen->sprites[index].color + 1;
    for (i = 0; i < n; i++) {
        screen->sprites[index].unk3E[i] = 0;
        switch (battle->record.entries[i].unk5) {
        case 1:
            if (battle->record.entries[i].unk4 == 0) {
                if (index < 6) {
                    screen->sprites[index].unk3E[i] = 1;
                }
            } else if (index >= 6) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 2:
            if (battle->record.entries[i].unk4 == 0) {
                if (index >= 6) {
                    screen->sprites[index].unk3E[i] = 1;
                }
            } else if (index < 6) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 3:
            screen->sprites[index].unk3E[i] = 1;
            break;
        case 4:
            if (color != 1) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 5:
            if (color != 2) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 6:
            if (color == 3) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 7:
            if (color != 4) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        case 8:
            if (color == 6) {
                screen->sprites[index].unk3E[i] = 1;
            }
            break;
        }
    }
}

/* Puts a card in the side's next slot (owned by side 2) and shows it */
void CARDGAME_putSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 card) {
    CardDrawer drawer;
    CardPlayer *player = &battle->players[side];
    s32 index = player->slotCount;
    s32 slot = index;

    if (side != 0) {
        index += 6;
    }
    initCardDrawer(&drawer);
    drawer.setCard(battle->cards[card] + 1);
    player->slots[slot].unk6 = drawer.card->ap;
    player->slots[slot].unk8 = drawer.card->hp;
    player->slots[slot].unk2 = 0;
    player->slots[slot].unk4 = 0;
    player->slots[slot].card = card;
    player->slots[slot].owner = side;
    player->slots[slot].side = 2;
    player->slots[slot].order = battle->slotCount++;
    screen->addSprite(screen, index, 0xE500, 0x6100);
    screen->setSpriteCard(screen, index, card);
    screen->sprites[index].unk43 = player->slots[slot].unk6;
    screen->sprites[index].unk44 = player->slots[slot].unk8;
    screen->sprites[index].scaleX = 0;
    CARDGAME_markRecordHits(battle, screen, side, index);
    battle->stepState = 1;
    screen->scaleSprite(screen, index, 20, 0x1000, 0x1000);
}

/* Takes the card the last record names out of the side's hand into its next
   slot and shows it */
void CARDGAME_takeHandCard(CardBattle *battle, CardScreen *screen, s32 side) {
    CardPlayer *player = &battle->players[side];
    CardPile *pile = &battle->sides[side].pile;
    s32 index = player->slotCount;
    s32 slot = index;
    s32 i;
    s32 j;

    if (side != 0) {
        index += 6;
    }
    for (i = 0; i < pile->handCount; i++) {
        if (battle->record.entries[battle->record.entryCount - 1].unk6 == pile->hand[i]) {
            battle->addCard(battle, side, battle->record.entries[battle->record.entryCount - 1].unk6);
            break;
        }
    }
    for (j = i; j < pile->handCount - 1; j++) {
        pile->hand[j] = pile->hand[j + 1];
    }
    pile->handCount--;
    player->slotCount--;
    screen->addSprite(screen, index, 0xE500, 0x6100);
    screen->setSpriteCard(screen, index, player->slots[slot].card);
    for (i = 0; i < 5; i++) {
        CARDGAME_setCountingCardValues(battle, &player->slots[slot], side, i);
    }
    screen->sprites[index].unk43 = player->slots[slot].unk6;
    screen->sprites[index].unk44 = player->slots[slot].unk8;
    screen->sprites[index].scaleX = 0;
    CARDGAME_markRecordHits(battle, screen, side, index);
    battle->stepState = 1;
    screen->setPanelValue(screen, side, 6, pile->handCount);
    screen->scaleSprite(screen, index, 20, 0x1000, 0x1000);
}

/* Moves the side's next slot card into place; 1 once it is there */
s32 CARDGAME_moveSlotCard(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    CardPlayer *player = &battle->players[side];
    s32 index = player->slotCount;
    s32 x;
    s32 y;

    if (side != 0) {
        index += 6;
    }
#if VERSION_US
    x = player->slotCount * 0x2900 + 0x1800;
    y = 0x3200;
    if (side == 0) {
        y = 0x9000;
    }
#elif VERSION_EU
    if (side == 0) {
        x = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + player->slotCount * 0x2900;
    } else {
        x = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + player->slotCount * 0x2900;
    }
    if (side == 0) {
        y = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1];
    } else {
        y = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3];
    }
#endif
    switch (battle->stepState) {
    case 1:
        if (screen->sprites[index].state == 1) {
            screen->startBlink(screen, index);
            battle->stepState = 2;
        }
        break;
    case 2:
        if (screen->sprites[index].state == 1) {
            screen->startMove(screen, index, 20, x, y);
            screen->sprites[index].moving = 1;
            battle->stepState = 3;
        }
        break;
    case 3:
        if (screen->sprites[index].state == 1) {
            battle->stepState = 4;
            screen->sprites[index].moving = 0;
            player->slotCount++;
        }
        break;
    case 4:
        done = 1;
        break;
    }
    return done;
}

/* Copies the first marked slot card (unk46F) into the side's next slot */
void CARDGAME_copySlotCard(CardBattle *battle, CardScreen *screen, s32 side) {
    CardPlayer *player = &battle->players[side];
    s32 index = player->slotCount;
    s32 slot = index;
    CardSlot *src;
    s32 from;
    s32 i;

    if (side != 0) {
        index += 6;
    }
    from = 0;
    src = &player->slots[slot];
    for (i = 0; i < 12; i++) {
        if (i < 6) {
            if (i >= battle->players[0].slotCount) {
                continue;
            }
            src = &battle->players[0].slots[i];
        } else {
            if (i - 6 >= battle->players[1].slotCount) {
                continue;
            }
            src = &battle->players[1].slots[i - 6];
        }
        if (battle->unk46F[i] != 0) {
            from = i;
            break;
        }
    }
    player->slots[slot] = *src;
    screen->addSprite(screen, index, 0xE500, 0x6100);
    screen->setSpriteCard(screen, index, player->slots[slot].card);
    screen->sprites[index] = screen->sprites[from];
    screen->sprites[index].scaleX = 0;
    CARDGAME_markRecordHits(battle, screen, side, index);
    for (i = 0; i < battle->record.entryCount - 1; i++) {
        if (battle->record.entries[i].unk5 == 0 && screen->sprites[from].unk3E[i] != 0) {
            screen->sprites[index].unk3E[i] = 1;
        }
    }
    battle->stepState = 1;
    screen->scaleSprite(screen, from, 5, 0, 0x1000);
    battle->unk424 = 7;
}

/* Waits unk424 frames, then flips the side's next slot card over and moves it
   into place; 1 once it is there */
s32 CARDGAME_flipSlotCard(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    CardPlayer *player = &battle->players[side];
    s32 index = player->slotCount;
    s32 x;
    s32 y;

    if (side != 0) {
        index += 6;
    }
#if VERSION_US
    x = player->slotCount * 0x2900 + 0x1800;
    y = 0x3200;
    if (side == 0) {
        y = 0x9000;
    }
#elif VERSION_EU
    if (side == 0) {
        x = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + player->slotCount * 0x2900;
    } else {
        x = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + player->slotCount * 0x2900;
    }
    if (side == 0) {
        y = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1];
    } else {
        y = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3];
    }
#endif
    switch (battle->stepState) {
    case 1:
        battle->unk424 -= GFX.funcs.getFrameTime();
        if (battle->unk424 <= 0) {
            screen->scaleSprite(screen, index, 5, 0x1000, 0x1000);
            battle->stepState = 2;
        }
        break;
    case 2:
        if (screen->sprites[index].state == 1) {
            screen->startBlink(screen, index);
            battle->stepState = 3;
        }
        break;
    case 3:
        if (screen->sprites[index].state == 1) {
            screen->startMove(screen, index, 20, x, y);
            screen->sprites[index].moving = 1;
            battle->stepState = 4;
        }
        break;
    case 4:
        if (screen->sprites[index].state == 1) {
            battle->stepState = 5;
            screen->sprites[index].moving = 0;
            player->slotCount++;
        }
        break;
    case 5:
        done = 1;
        break;
    }
    return done;
}

/* Shows the card being played as sprite 15 (opening the panels for side 0)
   and starts moving it to its place in the record */
void CARDGAME_startPlayCard(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 i;
    s32 j;

    if (side == 0 || screen->panels[0].state == 0) {
        if (screen->panels[0].state == 0) {
            screen->resetPanels(screen);
            battle->unk440 = 0;
            screen->addSprite(screen, 15, 0xE500, 0x6100);
            screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
            screen->sprites[15].scaleX = 0;
            screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
            screen->openPanels(screen);
            battle->unk498.unk5 = 1;
            battle->unk498.unk6[15] = 0;
            if (side == 0) {
                for (j = 0; j < 15; j++) {
                    battle->unk46F[j] = 0;
                }
            }
            battle->unk498.unk1 = 1;
            battle->stepState = 1;
        } else {
            screen->startMove(screen, 15, 10, CARDGAME_recordCardPositions[battle->record.entryCount][0], CARDGAME_recordCardPositions[battle->record.entryCount][1]);
#if VERSION_US
            battle->stepState = 3;
#elif VERSION_EU
            battle->stepState = 5;
#endif
            battle->unk424 = 0;
        }
    } else {
        screen->addSprite(screen, 15, 0xE500, 0x6100);
        screen->setSpriteCard(screen, 15, battle->record.entries[battle->record.entryCount].unk0);
        screen->sprites[15].scaleX = 0;
        screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
        battle->stepState = 2;
        battle->unk424 = 0;
#if VERSION_EU
        battle->unk428 = 0;
#endif
    }
    screen->clearPanelFlags(screen);
    for (i = 0; i < 15; i++) {
        screen->sprites[i].dimmed = 0;
    }
}

/* Card 15 goes off and the marked slot cards turn over; it then lands in
   sprite 12 + CardBattle560.unk15. 1 once done */
s32 CARDGAME_stepPlayCard(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 i;
    s32 j;
#if VERSION_EU
    s32 card;
#endif

    switch (battle->stepState) {
#if VERSION_US
    case 2:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 21) {
            screen->startMove(screen, 15, 10, CARDGAME_recordCardPositions[battle->record.entryCount][0], CARDGAME_recordCardPositions[battle->record.entryCount][1]);
            battle->stepState = 3;
            battle->unk424 = 0;
        }
        break;
#elif VERSION_EU
    case 2:
        screen->windows[1].unkE = 0;
        screen->windows[1].unk10 = 0;
        screen->windows[2].unk10 = 0;
        screen->windows[3].unk10 = 0;
        screen->windows[4].unk10 = 0;
        battle->unk428 = CARDGAME_openStepWindows(battle, screen, 2, 0, battle->unk424, battle->unk428);
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 21) {
            battle->unk424 = 0;
            battle->unk428 = 0;
            battle->stepState = 3;
        }
        break;
    case 3:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 4;
        }
        card = battle->cards[battle->record.entries[battle->record.entryCount].unk0] + 1;
        screen->windows[4].unk14[2] = 0;
        screen->windows[2].unk10 = card;
        screen->windows[4].unk10 = card;
        break;
    case 4:
        screen->startMove(screen, 15, 10, CARDGAME_recordCardPositions[battle->record.entryCount][0], CARDGAME_recordCardPositions[battle->record.entryCount][1]);
        screen->closeWindow(screen, 4);
        screen->closeWindow(screen, 1);
        screen->closeWindow(screen, 2);
        screen->closeWindow(screen, 3);
        battle->stepState = 5;
        battle->unk424 = 0;
        battle->unk428 = 0;
        break;
#endif
    case 1:
        if (screen->panels[0].state == 2 && battle->unk498.unk0 == 0) {
            screen->startMove(screen, 15, 10, CARDGAME_recordCardPositions[battle->record.entryCount][0], CARDGAME_recordCardPositions[battle->record.entryCount][1]);
            battle->stepState = 3 + CARD_INFO_STEPS;
            battle->unk424 = 0;
        }
        break;
    case 3 + CARD_INFO_STEPS:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 12) {
            battle->unk424 = 0;
            battle->stepState = 4 + CARD_INFO_STEPS;
            screen->startBlink(screen, 15);
            for (i = 0; i < 15; i++) {
                if (battle->unk46F[i] != 0) {
                    screen->startBlink(screen, i);
                }
            }
        }
        break;
    case 4 + CARD_INFO_STEPS:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 21) {
            battle->stepState = 5 + CARD_INFO_STEPS;
            battle->unk424 = 0;
            screen->scaleSprite(screen, 15, 5, 0, 0x1000);
            for (j = 0; j < 15; j++) {
                if (battle->unk46F[j] != 0) {
                    screen->sprites[j].unk3E[battle->record.entryCount] = 1;
                }
            }
        }
        break;
    case 5 + CARD_INFO_STEPS:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 7) {
            battle->unk424 = 0;
            screen->sprites[15].unk46 = battle->record.entryCount + 1;
            screen->scaleSprite(screen, 15, 8, 0x1000, 0x1000);
            battle->stepState = 6 + CARD_INFO_STEPS;
            screen->openGauge(screen, battle->record.entryCount, battle->record.unk19);
        }
        break;
    case 6 + CARD_INFO_STEPS:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 11) {
            battle->unk424 = 0;
            battle->stepState = 7 + CARD_INFO_STEPS;
            screen->sprites[battle->record.entryCount + 12] = screen->sprites[15];
            screen->removeSprite(screen, 15);
            for (j = 0; j < 12; j++) {
                screen->sprites[j].unk48 &= ~1;
            }
        }
        break;
    case 7 + CARD_INFO_STEPS:
        done = 1;
        break;
    }
    return done;
}

/* Empties both hands, on the panels with the decks */
void CARDGAME_clearHands(CardBattle *battle, CardScreen *screen) {
    battle->sides[0].pile.handCount = 0;
    battle->sides[1].pile.handCount = 0;
    screen->setPanelValue(screen, 0, 6, battle->sides[0].pile.handCount);
    screen->setPanelValue(screen, 1, 6, battle->sides[1].pile.handCount);
    screen->setPanelValue(screen, 0, 5, battle->sides[0].pile.deckCount);
    screen->setPanelValue(screen, 1, 5, battle->sides[1].pile.deckCount);
    battle->unk440 = 0;
    battle->unk423 = 1;
}

/* Deals six cards from each side's deck into its hand and puts them on the
   table, face down */
void CARDGAME_dealHands(CardBattle *battle, CardScreen *screen) {
    s32 side;
    s32 i;
    s32 j;

    battle->unk424 = 0;
    battle->unk428 = 0;
    battle->unk434 = 0;
    battle->unk42C = battle->sides[0].pile.deckCount;
    battle->unk430 = battle->sides[1].pile.deckCount;
    for (side = 0; side < 2; side++) {
        for (j = 0; j < 6; j++) {
            battle->sides[side].pile.hand[j] = battle->sides[side].pile.deck[battle->sides[side].pile.deckTop];
            battle->sides[side].pile.handCount++;
            battle->sides[side].pile.deckTop++;
            battle->sides[side].pile.deckCount--;
        }
    }
    for (i = 0; i < 6; i++) {
#if VERSION_US
        screen->addSprite(screen, i, 0x16000, 0x9000);
#elif VERSION_EU
        screen->addSprite(screen, i, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + 0x14800, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1]);
#endif
        screen->setSpriteCard(screen, i, battle->sides[0].pile.hand[i]);
        screen->sprites[i].visible = 2;
        screen->sprites[i].scaleY = 0;
        screen->sprites[i].scaleX = 0;
    }
    for (i = 0; i < 6; i++) {
#if VERSION_US
        screen->addSprite(screen, i + 6, 0x16000, 0x3200);
#elif VERSION_EU
        screen->addSprite(screen, i + 6, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + 0x14800, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3]);
#endif
        screen->setSpriteCard(screen, i + 6, battle->sides[1].pile.hand[i]);
        screen->sprites[i + 6].visible = 2;
        screen->sprites[i + 6].scaleY = 0;
        screen->sprites[i + 6].scaleX = 0;
    }
}

/* The start of a card battle: deals six cards to each side, turns them over and counts their colours (a deck with fewer than six cards shows a message instead); 1 when it ends */
s32 CARDGAME_stepStart(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;

    if (battle->unk423 != 0) {
        switch (battle->unk423) {
        case 1:
            screen->openPanels(screen);
            break;
        case 2:
            CARDGAME_dealHands(battle, screen);
            break;
        case 3:
        case 4:
            battle->unk424 = 0;
            battle->unk428 = 0;
            battle->unk434 = 0;
            break;
        case 5:
            battle->unk424 = 0;
            battle->unk428 = 0;
            battle->unk434 = 0;
            screen->closePanels(screen);
            break;
        case 6:
            screen->setPanelFlags(screen, 0x1000);
            screen->openMessage(screen, 0x21, 0, 1, 1);
            battle->unk440 = 1;
            break;
        case 7:
            SOUND.playSound(SOUND_WIN_JINGLE);
            screen->setPanelFlags(screen, 0x2000);
            screen->openMessage(screen, 0x22, 0, 1, 1);
            battle->unk440 = 2;
            break;
        case 9:
            battle->unk424 = 0;
            battle->unk428 = 0;
            battle->unk434 = 0;
            screen->closePanels(screen);
            screen->closeMessage(screen);
            break;
        case 11:
            screen->openMessage(screen, battle->prize, 0, 0, 3);
            break;
        case 8:
        case 10:
        case 12:
            /* nothing to set up */
            break;
        }
        battle->stepState = battle->unk423;
        battle->unk423 = 0;
    }

    switch (battle->stepState) {
    case 1:
        if (screen->panels[0].state == 2) {
            if (battle->sides[0].pile.deckCount < 6) {
                battle->unk423 = 6;
            } else if (battle->sides[1].pile.deckCount < 6) {
                battle->unk423 = 7;
            } else {
                battle->unk423 = 2;
            }
        }
        break;
    case 2:
        if (battle->unk434 >= 7) {
            if (battle->unk428 < 6) {
#if VERSION_US
                screen->startMove(screen, battle->unk428, 20, battle->unk428 * 0x2900 + 0x1800, 0x9000);
#elif VERSION_EU
                screen->startMove(screen, battle->unk428, 20, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + battle->unk428 * 0x2900, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][1]);
#endif
                screen->setSpriteScale(screen, battle->unk428, 0x1000, 0x1000);
#if VERSION_US
                screen->startMove(screen, battle->unk428 + 6, 20, battle->unk428 * 0x2900 + 0x1800, 0x3200);
#elif VERSION_EU
                screen->startMove(screen, battle->unk428 + 6, 20, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][2] + battle->unk428 * 0x2900, CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][3]);
#endif
                screen->setSpriteScale(screen, battle->unk428 + 6, 0x1000, 0x1000);
                battle->unk428++;
                battle->unk42C--;
                battle->unk430--;
                screen->setPanelValue(screen, 0, 6, battle->unk428);
                screen->setPanelValue(screen, 1, 6, battle->unk428);
                screen->setPanelValue(screen, 0, 5, battle->unk42C);
                screen->setPanelValue(screen, 1, 5, battle->unk430);
            }
            battle->unk434 -= 7;
        }
        if (battle->unk424 > 60) {
            battle->unk423 = 3;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        break;
    case 3:
        if (battle->unk434 >= 7) {
            if (battle->unk428 < 6) {
                screen->startFlip(screen, battle->unk428);
                battle->unk428++;
            }
            battle->unk434 -= 7;
        }
        if (battle->unk424 > 65) {
            battle->unk423 = 4;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        break;
    case 4:
        if (battle->unk434 >= 7) {
            if (battle->unk428 < 6) {
                if (CARDGAME_addColorCount(battle, screen, 0, battle->sides[0].pile.hand[battle->unk428])) {
                    screen->startBlink(screen, battle->unk428);
                }
                if (CARDGAME_addColorCount(battle, screen, 1, battle->sides[1].pile.hand[battle->unk428])) {
                    screen->startBlink(screen, battle->unk428 + 6);
                }
                battle->unk428++;
            }
            battle->unk434 -= 7;
        }
        if (battle->unk424 > 80) {
            battle->unk423 = 5;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        break;
    case 5:
        if (battle->unk434 >= 3) {
            if (battle->unk428 < 6) {
                screen->scaleSprite(screen, battle->unk428, 5, 0, 0x1000);
                screen->scaleSprite(screen, battle->unk428 + 6, 5, 0, 0x1000);
                battle->unk428++;
            }
            battle->unk434 -= 3;
        }
        if (battle->unk424 > 40) {
            battle->unk423 = 10;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk434 += GFX.funcs.getFrameTime();
        break;
    case 6:
    case 7:
        if (screen->message.state == 2) {
            battle->unk423 = 8;
        }
        break;
    case 8:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->unk423 = 9;
        }
        break;
    case 9:
        if (screen->message.state == 0 && screen->panels[0].state == 0) {
            battle->unk423 = 10;
        }
        break;
    case 10:
        if (battle->unk440 == 2) {
            battle->unk423 = 11;
        } else {
            done = 1;
        }
        break;
    case 11:
        if (screen->message.state == 2) {
            battle->unk423 = 12;
        }
        break;
    case 12:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            done = 1;
        }
        break;
    }
    return done;
}

/* Starts CARDGAME_stepAttack: side's unk0 comes off the other side's unk2
   (down to 0), counted down over its cards out */
void CARDGAME_startAttack(CardBattle *battle, CardScreen *screen, s32 side) {
    battle->unk424 = 0;
    battle->unk428 = 0;
    battle->unk42C = battle->sides[side].pile.unk0;
    battle->unk430 = battle->sides[side ^ 1].pile.unk2 << 8;
    battle->sides[side ^ 1].pile.unk2 -= battle->sides[side].pile.unk0;
    if (battle->sides[side ^ 1].pile.unk2 < 0) {
        battle->sides[side ^ 1].pile.unk2 = 0;
    }
    if (battle->players[side].slotCount != 0) {
        battle->unk434 = (battle->unk430 - (battle->sides[side ^ 1].pile.unk2 << 8)) / (battle->players[side].slotCount * 28 - 16);
        if (battle->unk434 == 0) {
            battle->unk434 = 1;
        }
    } else {
        battle->unk434 = 1;
    }
    battle->stepState = 1;
}

/* The side's slot cards go over one by one (every 27 frames) while the panels
   count its attack (8) and the other side's unk2 (9) down; 1 once done */
s32 CARDGAME_stepAttack(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    s32 other = side ^ 1;
    s32 index;
    s32 value;
#if VERSION_EU
    s32 x;
#endif
    s32 i;

    switch (battle->stepState) {
    case 1:
        if (battle->unk424 % 27 == 0 && battle->unk428 < battle->players[side].slotCount) {
            index = battle->unk428;
            if (side != 0) {
                index += 6;
            }
#if VERSION_US
            screen->startFly(screen, index, 6, (battle->players[other].slotCount - 1) * 0x1480 + 0x1800, 0x6100);
#elif VERSION_EU
            x = CARDGAME_slotRowPositions[SHIFT_PAL_SCREEN][0] + (battle->players[other].slotCount - 1) * 0x1480;
            if (SHIFT_PAL_SCREEN) {
                screen->startFly(screen, index, 6, x, side != 0 ? 0x6D00 : 0x5500);
            } else {
                screen->startFly(screen, index, 6, x, 0x6100);
            }
#endif
            battle->unk428++;
            screen->sprites[index].moving = 1;
        }
        if (battle->unk424 >= 16) {
            value = 0;
            if (battle->unk424 < battle->players[side].slotCount * 28) {
                value = battle->unk42C - (battle->unk42C / (battle->players[side].slotCount * 56 + 1) + 1) * battle->unk424;
                if (value < 0) {
                    value = 0;
                }
            }
            screen->setPanelValue(screen, side, 8, value);
            if (battle->unk424 < battle->players[side].slotCount * 28) {
                battle->unk430 -= battle->unk434;
                if (battle->unk430 < battle->sides[other].pile.unk2 << 8) {
                    battle->unk430 = battle->sides[other].pile.unk2 << 8;
                }
            } else {
                battle->unk430 = battle->sides[other].pile.unk2 << 8;
            }
            screen->setPanelValue(screen, other, 9, battle->unk430 >> 8);
        }
        if (screen->unk54 & 2) {
            for (i = 0; i < battle->players[other].slotCount; i++) {
                screen->startJitter(screen, side == 0 ? i + 6 : i);
            }
        }
        battle->unk424++;
        if (battle->unk424 > battle->players[side].slotCount * 28 + 25) {
            battle->stepState = 2;
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_stepDiscardAllSlots from side's last slot */
void CARDGAME_startDiscardAllSlots(CardBattle *battle, CardScreen *screen, s32 side) {
    battle->unk424 = 0;
    battle->unk428 = battle->players[side].slotCount - 1;
    battle->stepState = 1;
}

/* Discards side's slot cards from the last to the first; 1 once done */
s32 CARDGAME_stepDiscardAllSlots(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;

    switch (battle->stepState) {
    case 1:
        if (CARDGAME_stepDiscardSlotCard(battle, screen, side, battle->unk428)) {
            battle->unk424 = 0;
            if (--battle->unk428 < 0) {
                battle->stepState = 2;
                battle->players[side].slotCount = 0;
            }
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* The value going from FROM to TO in DURATION, at TIME, never past TO */
s32 CARDGAME_interpolate(s32 to, s32 from, s32 duration, s32 time) {
    s32 delta = to - from;
    s32 inRange;

    if (time == duration || from == to) {
        return to;
    }
    from += delta * time / duration;
    if (delta > 0) {
        inRange = from < to;
    } else {
        inRange = from > to;
    }
    if (!inRange) {
        from = to;
    }
    return from;
}

/* Shows the kept card (unk304) as sprite 17 for CARDGAME_stepSwap */
void CARDGAME_startSwap(CardBattle *battle, CardScreen *screen) {
    screen->addSprite(screen, 0x11, 0x8300, 0x6100);
    screen->setSpriteCard(screen, 0x11, battle->unk304 - 1);
    screen->sprites[0x11].scaleX = 0;
    screen->scaleSprite(screen, 0x11, 10, 0x1000, 0x1000);
    battle->stepState = 1;
}

/* Swaps the two sides' pile unk0 and unk2, counting the panels' values 8 and 9 over to each other, then shows message 0x2D until cross or triangle; 1 once done */
s32 CARDGAME_stepSwap(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 unk0;
    s32 unk2;

    switch (battle->stepState) {
    case 1:
        if (screen->sprites[0x11].state == 1) {
            screen->startBlink(screen, 0x11);
            battle->stepState = 2;
        }
        break;
    case 2:
        if (screen->sprites[0x11].state == 1) {
            battle->stepState = 3;
            battle->unk424 = 0;
        }
        break;
    case 3:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 < 15) {
            screen->setPanelValue(screen, 0, 8, CARDGAME_interpolate(battle->sides[1].pile.unk0, battle->sides[0].pile.unk0, 15, battle->unk424));
            screen->setPanelValue(screen, 0, 9, CARDGAME_interpolate(battle->sides[1].pile.unk2, battle->sides[0].pile.unk2, 15, battle->unk424));
            screen->setPanelValue(screen, 1, 8, CARDGAME_interpolate(battle->sides[0].pile.unk0, battle->sides[1].pile.unk0, 15, battle->unk424));
            screen->setPanelValue(screen, 1, 9, CARDGAME_interpolate(battle->sides[0].pile.unk2, battle->sides[1].pile.unk2, 15, battle->unk424));
        } else {
            unk0 = battle->sides[0].pile.unk0;
            battle->sides[0].pile.unk0 = battle->sides[1].pile.unk0;
            battle->sides[1].pile.unk0 = unk0;
            unk2 = battle->sides[0].pile.unk2;
            battle->sides[0].pile.unk2 = battle->sides[1].pile.unk2;
            battle->sides[1].pile.unk2 = unk2;
            screen->setPanelValue(screen, 0, 8, battle->sides[0].pile.unk0);
            screen->setPanelValue(screen, 0, 9, battle->sides[0].pile.unk2);
            screen->setPanelValue(screen, 1, 8, battle->sides[1].pile.unk0);
            screen->setPanelValue(screen, 1, 9, battle->sides[1].pile.unk2);
            screen->scaleSprite(screen, 0x11, 10, 0, 0x1000);
            battle->stepState = 4;
        }
        break;
    case 4:
        if (screen->sprites[0x11].state == 1) {
            battle->stepState = 5;
            screen->openMessage(screen, 0x2D, 0, 0, 1);
        }
        break;
    case 5:
        if (screen->message.state == 2) {
            battle->stepState = 6;
        }
        break;
    case 6:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 7;
            screen->closeMessage(screen);
        }
        break;
    case 7:
        if (screen->message.state == 0) {
            battle->stepState = 8;
        }
        break;
    case 8:
        done = 1;
        break;
    }
    return done;
}

/* Adds up the marked slots' unk6 and unk8 (at most 99, 20 more for four or more slots) and shows them on sprite 0x11 with card unk438, looked for among the card list's last 100 cards */
void CARDGAME_showSlotTotal(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 i;
    s32 card;
    s32 slot;
    s32 count = 0;
    s32 index;
    s32 base;

    battle->unk42C = 0;
    battle->unk430 = 0;
    for (i = 0; i < battle->players[side].slotCount; i++) {
        if (battle->unk446[i] != 0) {
            battle->unk42C += battle->players[side].slots[i].unk6;
            if (battle->unk42C >= 100) {
                battle->unk42C = 99;
            }
            battle->unk430 += battle->players[side].slots[i].unk8;
            if (battle->unk430 >= 100) {
                battle->unk430 = 99;
            }
            count++;
        }
    }
    if (count >= 4) {
        battle->unk42C += 20;
        if (battle->unk42C >= 100) {
            battle->unk42C = 99;
        }
        battle->unk430 += 20;
        if (battle->unk430 >= 100) {
            battle->unk430 = 99;
        }
    }
    screen->addSprite(screen, 0x11, 0x8300, 0x6100);
    index = 0;
    for (card = 89; card < battle->cardCount; card++) {
        if (battle->cards[card] == battle->unk438 - 1) {
            index = card;
            break;
        }
    }
    if (index == 0) {
        index = 87;
        battle->unk438 = 0x13B;
    }
    screen->setSpriteCard(screen, 0x11, index);
    screen->sprites[0x11].color = 5;
    screen->sprites[0x11].unk43 = battle->unk42C;
    screen->sprites[0x11].unk44 = battle->unk430;
    base = 0;
    if (side != 0) {
        base = 6;
    }
    for (slot = 0; slot < battle->players[side].slotCount; slot++) {
        if (battle->unk446[slot] != 0) {
            screen->sprites[base + slot].unk48 |= 4;
        }
    }
    screen->sprites[0x11].scaleX = 0;
    battle->unk424 = 0;
    battle->stepState = 1;
}

/* Takes the marked slots' sprites away, shows card unk438 in window 2 for 90 frames (or until cross or triangle), then adds unk42C and unk430 to the side's pile unk0 and unk2, counting the panel values up; 1 once done */
s32 CARDGAME_stepSlotTotal(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    s32 base;
    s32 i;
    s32 first;
    s32 j;

    switch (battle->stepState) {
    case 1:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 21) {
            battle->stepState = 2;
            base = 0;
            if (side != 0) {
                base = 6;
            }
            for (i = 0; i < battle->players[side].slotCount; i++) {
                if (battle->unk446[i] != 0) {
                    screen->startBlink(screen, base + i);
                    battle->unk434 = base + i;
                }
            }
        }
        break;
    case 2:
        if (screen->sprites[battle->unk434].state == 1) {
            screen->scaleSprite(screen, 0x11, 10, 0x1000, 0x1000);
            battle->stepState = 3;
            first = 0;
            if (side != 0) {
                first = 6;
            }
            for (j = 0; j < battle->players[side].slotCount; j++) {
                if (battle->unk446[j] != 0) {
                    screen->sprites[first + j].unk48 &= ~4;
                }
            }
        }
        break;
    case 3:
        if (screen->sprites[0x11].state == 1) {
            battle->stepState = 4;
#if VERSION_US
            screen->openWindow(screen, 2, 1, battle->unk438, CARDGAME_cardWindowPositions[0][side][0], CARDGAME_cardWindowPositions[0][side][1]);
#elif VERSION_EU
            screen->openWindow(screen, 2, 1, battle->unk438, CARDGAME_cardWindowPositions[SHIFT_PAL_SCREEN][side][0], CARDGAME_cardWindowPositions[SHIFT_PAL_SCREEN][side][1]);
#endif
        }
        break;
    case 4:
        if (screen->windows[2].state == 2) {
            battle->stepState = 5;
            battle->unk424 = 90;
        }
        break;
    case 5:
        battle->unk424 -= GFX.funcs.getFrameTime();
        if (battle->unk424 <= 0 || PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 6;
            screen->closeWindow(screen, 2);
        }
        break;
    case 6:
        if (screen->windows[2].state == 0) {
            screen->startBlink(screen, 0x11);
            battle->stepState = 7;
        }
        break;
    case 7:
        if (screen->sprites[0x11].state == 1) {
            battle->stepState = 8;
            battle->unk424 = 0;
        }
        break;
    case 8:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 < 20) {
            screen->setPanelValue(screen, side, 8, CARDGAME_interpolate(battle->sides[side].pile.unk0 + battle->unk42C, battle->sides[side].pile.unk0, 20, battle->unk424));
            screen->setPanelValue(screen, side, 9, CARDGAME_interpolate(battle->sides[side].pile.unk2 + battle->unk430, battle->sides[side].pile.unk2, 20, battle->unk424));
        } else {
            battle->sides[side].pile.unk0 += battle->unk42C;
            battle->sides[side].pile.unk2 += battle->unk430;
            screen->setPanelValue(screen, side, 8, battle->sides[side].pile.unk0);
            screen->setPanelValue(screen, side, 9, battle->sides[side].pile.unk2);
            screen->scaleSprite(screen, 0x11, 10, 0, 0x1000);
            battle->stepState = 9;
        }
        break;
    case 9:
        if (screen->sprites[0x11].state == 1) {
            battle->stepState = 10;
        }
        break;
    case 10:
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_stepTotals */
void CARDGAME_startTotals(CardBattle *battle, CardScreen *screen) {
    battle->stepState = 1;
    battle->unk424 = 0;
    battle->unk428 = 0;
    battle->unk42C = 0;
    battle->unk430 = 0;
    battle->unk434 = 0;
}

/* Adds up both players' slots' unk6 and unk8 and counts the panels' values 8 and 9 over to the totals, which become the sides' pile unk0 and unk2; 1 once done */
s32 CARDGAME_stepTotals(CardBattle *battle, CardScreen *screen) {
    s32 done = 0;
    s32 i;

    switch (battle->stepState) {
    case 1:
        for (i = 0; i < battle->players[0].slotCount; i++) {
            battle->unk428 += battle->players[0].slots[i].unk6;
            battle->unk42C += battle->players[0].slots[i].unk8;
        }
        for (i = 0; i < battle->players[1].slotCount; i++) {
            battle->unk430 += battle->players[1].slots[i].unk6;
            battle->unk434 += battle->players[1].slots[i].unk8;
        }
        if (battle->sides[0].pile.unk0 == battle->unk428 && battle->sides[0].pile.unk2 == battle->unk42C &&
            battle->sides[1].pile.unk0 == battle->unk430 && battle->sides[1].pile.unk2 == battle->unk434) {
            battle->stepState = 4;
        } else {
            battle->unk424 = 0;
            battle->stepState = 2;
        }
        break;
    case 2:
        battle->unk424 += GFX.funcs.getFrameTime();
        if (battle->unk424 < 15) {
            SOUND.playSound(SOUND_COUNT);
            screen->setPanelValue(screen, 0, 8, CARDGAME_interpolate(battle->unk428, battle->sides[0].pile.unk0, 15, battle->unk424));
            screen->setPanelValue(screen, 0, 9, CARDGAME_interpolate(battle->unk42C, battle->sides[0].pile.unk2, 15, battle->unk424));
            screen->setPanelValue(screen, 1, 8, CARDGAME_interpolate(battle->unk430, battle->sides[1].pile.unk0, 15, battle->unk424));
            screen->setPanelValue(screen, 1, 9, CARDGAME_interpolate(battle->unk434, battle->sides[1].pile.unk2, 15, battle->unk424));
        } else {
            battle->sides[0].pile.unk0 = battle->unk428;
            battle->sides[0].pile.unk2 = battle->unk42C;
            battle->sides[1].pile.unk0 = battle->unk430;
            battle->sides[1].pile.unk2 = battle->unk434;
            screen->setPanelValue(screen, 0, 8, battle->sides[0].pile.unk0);
            screen->setPanelValue(screen, 0, 9, battle->sides[0].pile.unk2);
            screen->setPanelValue(screen, 1, 8, battle->sides[1].pile.unk0);
            screen->setPanelValue(screen, 1, 9, battle->sides[1].pile.unk2);
            battle->stepState = 3;
        }
        break;
    case 3:
        battle->stepState = 4;
        break;
    case 4:
        done = 1;
        break;
    }
    return done;
}

/* Starts CARDGAME_stepRoundEnd */
void CARDGAME_startRoundEnd(CardBattle *battle, CardScreen *screen) {
    battle->stepState = 1;
    battle->unk424 = 0;
    battle->unk428 = 0;
    battle->unk42C = 0;
    battle->unk430 = 0;
    battle->unk434 = 0;
    battle->unk438 = 0;
}

/* Takes the side's slots away one by one, then moves both sides' hands back into their decks one at a time (the panels' values 6 and 5) and shows window 5 until cross or triangle; 1 once done */
s32 CARDGAME_stepRoundEnd(CardBattle *battle, CardScreen *screen, s32 side) {
    s32 done = 0;
    s32 index;
    s32 counting;

    switch (battle->stepState) {
    case 1:
        if (battle->unk438 >= 3) {
            if (battle->unk428 < battle->players[side].slotCount) {
                index = battle->unk428;
                if (side != 0) {
                    index += 6;
                }
                screen->scaleSprite(screen, index, 4, 0, 0x1000);
                CARDGAME_discardSlotCard(battle, screen, side, battle->unk428);
                battle->unk428++;
            }
            battle->unk438 -= 3;
        }
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk438 += GFX.funcs.getFrameTime();
        if (battle->unk424 >= 61) {
            battle->players[side].slotCount = 0;
            battle->unk424 = 0;
            battle->stepState = 2;
            battle->unk438 = 0;
            battle->unk428 = battle->sides[0].pile.handCount;
            battle->unk42C = battle->sides[0].pile.deckCount;
            battle->unk430 = battle->sides[1].pile.handCount;
            battle->unk434 = battle->sides[1].pile.deckCount;
        }
        break;
    case 2:
        battle->unk424 += GFX.funcs.getFrameTime();
        battle->unk438 += GFX.funcs.getFrameTime();
        if (battle->unk438 >= 3) {
            counting = 0;
            if (battle->unk428 > 0) {
                counting = 1;
                battle->unk428--;
                battle->unk42C++;
            }
            if (battle->unk430 > 0) {
                counting = 1;
                battle->unk430--;
                battle->unk434++;
            }
            if (!counting) {
                battle->stepState = 4;
                screen->openWindow(screen, 5, 5, 20, 0, 110);
            } else {
                SOUND.playSound(SOUND_COUNT);
            }
            screen->setPanelValue(screen, 0, 6, battle->unk428);
            screen->setPanelValue(screen, 0, 5, battle->unk42C);
            screen->setPanelValue(screen, 1, 6, battle->unk430);
            screen->setPanelValue(screen, 1, 5, battle->unk434);
            battle->unk438 -= 3;
        }
        break;
    case 3:
        if (screen->windows[5].state == 2) {
            battle->stepState = 4;
        }
        break;
    case 4:
        if (PAD_PRESSED(PAD_CROSS) || PAD_PRESSED(PAD_TRIANGLE)) {
            battle->stepState = 5;
            screen->closeWindow(screen, 5);
        }
        break;
    case 5:
        if (screen->windows[5].state == 0) {
            battle->stepState = 6;
            screen->closePanels(screen);
        }
        break;
    case 6:
        if (screen->panels[0].state == 0) {
            battle->stepState = 7;
        }
        break;
    case 7:
        done = 1;
        break;
    }
    return done;
}

/* The data: this object's tables */
/* three sets of four positions, then the same moved for SHIFT_PAL_SCREEN */
s16 CARDGAME_stepWindowPositions[2][3][4][2] = {
    {
        {{0x82, 0xD4}, {0x82, 0x67}, {0x82, 0xBF}, {0xFD, 0xBF}},
        {{0x82, 0x1D}, {0x82, 0x61}, {0x82, 0x08}, {0xFD, 0x08}},
        {{0x82, 0xA5}, {0x86, 0x31}, {0x82, 0x90}, {0xFD, 0x90}},
    },
    {
        {{0x82, 0xE0}, {0x82, 0x73}, {0x82, 0xCB}, {0xFD, 0xCB}},
        {{0x82, 0x11}, {0x82, 0x55}, {0x82, -4}, {0xFD, -4}},
        {{0x82, 0xA5}, {0x86, 0x31}, {0x82, 0x90}, {0xFD, 0x90}},
    },
};
s32 CARDGAME_rowSpriteOffsets[] = {
    0, 6, 12, 0,
};
CardBattleStep CARDGAME_windowSteps[] = {{0, 0}, {4, 1}, {8, 2}, {-1, 3}};
u8 CARDGAME_stepMessages[][2] = {
    {0x01, 0x02}, {0x03, 0x04}, {0x05, 0x06}, {0x07, 0x08},
    {0x09, 0x0A}, {0x0B, 0x0C}, {0x1F, 0x3E}, {0x0B, 0x0C},
};
s32 CARDGAME_coinCardPositions[][2] = {{0x7400, 0x6100}, {0xA400, 0x6100}};
s32 CARDGAME_rowSteps[] = {5, 6, 7, 0};
s16 CARDGAME_colorFlags[] = {
    0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
};
s32 CARDGAME_discardPositions[][2] = {{0x11400, 28416}, {0x11400, 22016}};
s32 CARDGAME_recordCardPositions[][2] = {{20736, 24832}, {33536, 24832}, {46336, 24832}};
s16 CARDGAME_cardWindowPositions[2][2][2] = {{{0x82, 0xBF}, {0x82, 0x1D}}, {{0x82, 0xCB}, {0x82, 0x11}}};
