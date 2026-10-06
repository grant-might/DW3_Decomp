#include "stcrddek.h"

void STCRDDEK_drawDeckCards(DeckCards *task);
void STCRDDEK_loadNextCard(DeckCards *task);
void STCRDDEK_createEditorWindows(DeckEditor *task, DeckEditorChildren *children);
void STCRDDEK_buildCardList(DeckEditor *task);
void STCRDDEK_drawEditor(DeckEditor *task);
void STCRDDEK_stepEditor(DeckEditor *task, DeckEditorChildren *children);
void STCRDDEK_initIdle(DeckIdle *task, void *children);
void STCRDDEK_showNameWindows(NameEntry *task, NameEntryWindows *windows, s32 show);
void STCRDDEK_drawKeyboard(NameEntry *task);
void STCRDDEK_updateKeyboard(NameEntry *task, NameEntryWindows *windows);
void STCRDDEK_updateNameEntry(NameEntry *task, NameEntryWindows *windows);
void STCRDDEK_updateScrollBar(ScrollBar *bar);
ScrollBar *STCRDDEK_createScrollBar(void);
void STCRDDEK_createScreenWindows(DeckScreen *task, DeckScreenChildren *children);
void STCRDDEK_drawScreen(DeckScreen *task);
void STCRDDEK_countCardKinds(DeckScreen *task);
void STCRDDEK_stepScreen(DeckScreen *task, DeckScreenChildren *children);
void STCRDDEK_updateScreen(DeckScreen *task, DeckScreenChildren *children);
DeckScreen *STCRDDEK_createScreen(void);

void STCRDDEK_updateScene(Task *task, Task **children) {
    RECT rect;
    Layer *layer;

    switch (task->state) {
    case TASK_INIT:
    default:
        GFX.funcs.reset();
        GFX.funcs.allocPrimBuffers(0xF000);
        GFX.funcs.setDisplayMode(0x140, 0xF0, 0, 0);
        rect.x = 0;
        rect.y = 0;
        rect.w = 0x140;
        rect.h = 0xF0;
        layer = GFX.funcs.createLayer(&rect, 3, 0x1000);
        layer->setBgColor(layer, 0, 0, 0);
        children[0] = (Task *)STCRDDEK_createScreen();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

Task *STCRDDEK_start(void) {
    return createTask(STCRDDEK_updateScene, sizeof(Task), 4);
}

void STCRDDEK_startFader(ScreenFade *task, s32 fadeIn, s32 duration) {
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

void STCRDDEK_drawFader(ScreenFade *task) {
    Layer *layer = GFX.funcs.getLayer(task->layerId);
    u_long *ot = (u_long *)layer->getOtEntry(layer, task->depth);
    POLY_F4 *poly = GFX.funcs.getPrim();
    DR_TPAGE *mode;

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

void STCRDDEK_updateFader(ScreenFade *task) {
    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        break;
    case 1:
        if (task->substate == 0) {
            break;
        }
        task->level += task->levelStep;
        if (task->fadeIn == 0) {
            if (task->level > 0xFF00) {
                task->level = 0xFF00;
                task->state = 2;
            }
        } else if (task->level < 0) {
            task->level = 0;
            task->state = 2;
        }
        /* fallthrough */
    case 2:
        STCRDDEK_drawFader(task);
        break;
    case 3:
        break;
    }
}

ScreenFade *STCRDDEK_createFader(void) {
    ScreenFade *task = createTask(STCRDDEK_updateFader, sizeof(ScreenFade), 0);

    task->start = STCRDDEK_startFader;
    task->layerId = 0x1000;
    task->depth = 0;
    return task;
}

void STCRDDEK_drawDeckCards(DeckCards *task) {
    SpriteDrawer sprite;
    CardDrawer card;
    s32 i;
    s32 col;
    s32 row;
    s32 x;
    s32 y;
    s32 sheet;

    initSpriteDrawer(&sprite);
    sprite.setTexture(0x280, 0);
    sprite.setLayerId(task->layer, task->depth);
    initCardDrawer(&card);
    card.setImagePos(0x140, 0x100);
    card.setClutPos(0x300, 0x100);
    card.setLayer(task->layer, task->depth);
    for (i = 0; i < task->count; i++) {
        card.setCard(GAME.decks[task->editor->deck].cards[i]);
        /* the match depends on col holding the row first */
        col = i / 9;
        row = col;
        col = i - row * 9;
        sheet = FILE_CACHE.getEntry(STCRDDEK_SPRITES);
        x = col * 32 + 0x10;
        y = row * 32 + 0x3A;
        sprite.draw(sheet, card.card->color + 0x52, x, y);
        card.setCell(col, row);
        card.draw(x, y);
    }
}

void STCRDDEK_loadNextCard(DeckCards *task) {
    CardDrawer card;
    s32 i;

    if (++task->count > 40) {
        task->state = TASK_DONE;
        task->count = 40;
        return;
    }
    initCardDrawer(&card);
    card.setCard(GAME.decks[task->editor->deck].cards[task->count - 1]);
    card.setImagePos(0x140, 0x100);
    card.setClutPos(0x300, 0x100);
    i = task->count - 1;
    card.setCell(i % 9, i / 9);
    card.loadImage();
}

void STCRDDEK_updateDeckCards(DeckCards *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->count = 0;
        break;
    case TASK_RUN:
        STCRDDEK_loadNextCard(task);
    case TASK_DONE:
        STCRDDEK_drawDeckCards(task);
        break;
    case TASK_KILL:
        break;
    }
}

DeckCards *STCRDDEK_createDeckCards(DeckEditor *editor) {
    DeckCards *task = createTask(STCRDDEK_updateDeckCards, sizeof(DeckCards), 0);

    task->layer = 0x1000;
    task->depth = 5;
    task->editor = editor;
    return task;
}

void STCRDDEK_createEditorWindows(DeckEditor *task, DeckEditorChildren *children) {
    s32 i;

    children->title = createTextWindow(task->layer, 1, 0xC1, 0x17);
    children->title->setDepth(children->title, task->depth - 1);
    children->deckName = createTextWindow(task->layer, 1, 0x15, 0x18);
    children->deckName->setDepth(children->deckName, task->depth - 1);
    for (i = 0; i < 6; i++) {
        children->kinds[i] = createTextWindow(task->layer, 1, 0x34 + i * 0x23, 0x29);
        children->kinds[i]->setDepth(children->kinds[i], task->depth - 1);
    }
    children->hint = createTextWindow(task->layer, 1, 0x96, 0xCC);
    children->cardName = createTextWindow(task->layer, 1, 0x96, 0xBD);
    children->pointsLabel = createTextWindow(task->layer, 1, 0x115, 0x26);
    children->points = createTextWindow(task->layer, 1, 0x126, 0x26);
    children->effect = createTextWindow(task->layer, 1, 0x50, 0x17);
    children->apLabel = createTextWindow(task->layer, 1, 0xCE, 0x17);
    children->ap = createTextWindow(task->layer, 1, 0xF0, 0x17);
    children->hpLabel = createTextWindow(task->layer, 1, 0xCE, 0x24);
    children->hp = createTextWindow(task->layer, 1, 0xF0, 0x24);
    for (i = 0; i < 8; i++) {
        children->lines[i].name = createTextWindow(task->layer, 1, 0xA3, 0x27 + i * 0xE);
        children->lines[i].name->setDepth(children->lines[i].name, task->depth - 1);
        children->lines[i].label = createTextWindow(task->layer, 1, 0x111, 0x27 + i * 0xE);
        children->lines[i].label->setDepth(children->lines[i].label, task->depth - 1);
        children->lines[i].count = createTextWindow(task->layer, 1, 0x120, 0x27 + i * 0xE);
        children->lines[i].count->setDepth(children->lines[i].count, task->depth - 1);
    }
    children->cursor = createCursor(task->layer, task->depth - 1, 0x89, 0x27);
    children->cursor->setVisible(children->cursor, 0);
    children->listCardName = createTextWindow(task->layer, 1, 0x88, 0xA1);
    children->listPointsLabel = createTextWindow(task->layer, 1, 0x115, 0xA1);
    children->listPoints = createTextWindow(task->layer, 1, 0x126, 0xA1);
    children->listEffect = createTextWindow(task->layer, 1, 0x50, 0xB8);
    children->listApLabel = createTextWindow(task->layer, 1, 0xCE, 0xB8);
    children->listAp = createTextWindow(task->layer, 1, 0xF0, 0xB8);
    children->listHpLabel = createTextWindow(task->layer, 1, 0xCE, 0xC5);
    children->listHp = createTextWindow(task->layer, 1, 0xF0, 0xC5);
    children->message = createTextWindow(task->layer, 1, 0x3E, 0x6B);
    children->message->setLines(children->message, 2);
}

void STCRDDEK_showEditorWindows(DeckEditor *task, DeckEditorChildren *children, s32 show) {
    CardDrawer card;
    s32 i;
    s32 id;

    if (show != 0) {
        children->title->setString(children->title, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 4);
        children->deckName->setString(children->deckName, GAME.decks[task->deck].name, -1);
        for (i = 0; i < 6; i++) {
            children->kinds[i]->setNumber(children->kinds[i], 0, task->screen->kinds[task->deck][i]);
            children->kinds[i]->setRightAlign(children->kinds[i], 1);
        }
        id = task->blinkTime < 60 ? task->infoShown + 0x1C : 0x1F;
        children->hint->setString(children->hint, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), id);
        id = GAME.decks[task->deck].cards[task->column + task->row * 9];
        children->cardName->setString(children->cardName, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_NAMES)), id);
        if (task->infoShown) {
            initCardDrawer(&card);
            card.setCard(id);
            if (card.getKind()) {
                children->pointsLabel->setVisible(children->pointsLabel, 0);
                children->points->setVisible(children->points, 0);
                children->effect->setString(children->effect, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_EFFECTS)), id);
                children->apLabel->setVisible(children->apLabel, 0);
                children->ap->setVisible(children->ap, 0);
                children->hpLabel->setVisible(children->hpLabel, 0);
                children->hp->setVisible(children->hp, 0);
            } else {
                children->pointsLabel->setString(children->pointsLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 8);
                children->points->setNumber(children->points, 0, card.card->points);
                children->points->setRightAlign(children->points, 1);
                if (id == 0x45 || id == 0x70 || id == 0x9B || id == 0xC6 || id == 0xF1) {
                    children->effect->setString(children->effect, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_EFFECTS)), id);
                    children->apLabel->setVisible(children->apLabel, 0);
                    children->ap->setVisible(children->ap, 0);
                    children->hpLabel->setVisible(children->hpLabel, 0);
                    children->hp->setVisible(children->hp, 0);
                } else {
                    children->effect->setVisible(children->effect, 0);
                    children->apLabel->setString(children->apLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x11);
                    children->ap->setNumber(children->ap, 0, card.card->ap);
                    children->ap->setRightAlign(children->ap, 1);
                    children->hpLabel->setString(children->hpLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x12);
                    children->hp->setNumber(children->hp, 0, card.card->hp);
                    children->hp->setRightAlign(children->hp, 1);
                }
            }
        } else {
            children->pointsLabel->setVisible(children->pointsLabel, 0);
            children->points->setVisible(children->points, 0);
            children->effect->setVisible(children->effect, 0);
            children->apLabel->setVisible(children->apLabel, 0);
            children->ap->setVisible(children->ap, 0);
            children->hpLabel->setVisible(children->hpLabel, 0);
            children->hp->setVisible(children->hp, 0);
        }
    } else {
        children->title->setVisible(children->title, 0);
        children->deckName->setVisible(children->deckName, 0);
        for (i = 0; i < 6; i++) {
            children->kinds[i]->setVisible(children->kinds[i], 0);
        }
        children->hint->setVisible(children->hint, 0);
        children->cardName->setVisible(children->cardName, 0);
        children->pointsLabel->setVisible(children->pointsLabel, 0);
        children->points->setVisible(children->points, 0);
        children->effect->setVisible(children->effect, 0);
        children->apLabel->setVisible(children->apLabel, 0);
        children->ap->setVisible(children->ap, 0);
        children->hpLabel->setVisible(children->hpLabel, 0);
        children->hp->setVisible(children->hp, 0);
    }
}

void STCRDDEK_showCardList(DeckEditor *task, DeckEditorChildren *children, s32 show) {
    s32 i;
    s32 id;

    if (show != 0) {
        for (i = 0; i < 8; i++) {
            id = task->list[task->listTop + i];
            if (id != 0) {
                children->lines[i].name->setString(children->lines[i].name, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_NAMES)), id);
                children->lines[i].label->setString(children->lines[i].label, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 8);
                children->lines[i].count->setNumber(children->lines[i].count, 0, task->owned[id]);
                children->lines[i].count->setRightAlign(children->lines[i].count, 1);
            } else {
                children->lines[i].name->setVisible(children->lines[i].name, 0);
                children->lines[i].label->setVisible(children->lines[i].label, 0);
                children->lines[i].count->setVisible(children->lines[i].count, 0);
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            children->lines[i].name->setVisible(children->lines[i].name, 0);
            children->lines[i].label->setVisible(children->lines[i].label, 0);
            children->lines[i].count->setVisible(children->lines[i].count, 0);
        }
    }
}

void STCRDDEK_showListCard(DeckEditor *task, DeckEditorChildren *children, s32 show) {
    CardDrawer card;
    s32 id;

    if (show != 0) {
        id = task->list[task->listTop + task->listCursor];
        children->listCardName->setString(children->listCardName, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_NAMES)), id);
        initCardDrawer(&card);
        card.setCard(id);
        if (card.getKind()) {
            children->listPointsLabel->setVisible(children->listPointsLabel, 0);
            children->listPoints->setVisible(children->listPoints, 0);
            children->listEffect->setString(children->listEffect, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_EFFECTS)), id);
            children->listApLabel->setVisible(children->listApLabel, 0);
            children->listAp->setVisible(children->listAp, 0);
            children->listHpLabel->setVisible(children->listHpLabel, 0);
            children->listHp->setVisible(children->listHp, 0);
        } else {
            children->listPointsLabel->setString(children->listPointsLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 8);
            children->listPoints->setNumber(children->listPoints, 0, card.card->points);
            children->listPoints->setRightAlign(children->listPoints, 1);
            if (id == 0x45 || id == 0x70 || id == 0x9B || id == 0xC6 || id == 0xF1) {
                children->listEffect->setString(children->listEffect, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_EFFECTS)), id);
                children->listApLabel->setVisible(children->listApLabel, 0);
                children->listAp->setVisible(children->listAp, 0);
                children->listHpLabel->setVisible(children->listHpLabel, 0);
                children->listHp->setVisible(children->listHp, 0);
            } else {
                children->listEffect->setVisible(children->listEffect, 0);
                children->listApLabel->setString(children->listApLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x11);
                children->listAp->setNumber(children->listAp, 0, card.card->ap);
                children->listAp->setRightAlign(children->listAp, 1);
                children->listHpLabel->setString(children->listHpLabel, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x12);
                children->listHp->setNumber(children->listHp, 0, card.card->hp);
                children->listHp->setRightAlign(children->listHp, 1);
            }
        }
    } else {
        children->listCardName->setVisible(children->listCardName, 0);
        children->listPointsLabel->setVisible(children->listPointsLabel, 0);
        children->listPoints->setVisible(children->listPoints, 0);
        children->listEffect->setVisible(children->listEffect, 0);
        children->listApLabel->setVisible(children->listApLabel, 0);
        children->listAp->setVisible(children->listAp, 0);
        children->listHpLabel->setVisible(children->listHpLabel, 0);
        children->listHp->setVisible(children->listHp, 0);
    }
}

/* Lists the cards owned but not in the deck: owned holds each card's copies
   left over, list the cards that have some (listCount of them) */
void STCRDDEK_buildCardList(DeckEditor *task) {
    s32 i;
    s32 n;
    s16 *cards;

    for (i = 0; i < 315; i++) {
        task->list[i] = 0;
        task->owned[i] = GAME.cards[i];
    }
    cards = GAME.decks[task->deck].cards;
    for (n = 0; n < 40; n++, cards++) {
        task->owned[*cards]--;
    }
    task->listCount = 0;
    for (i = 0, n = 0; i < 315; i++) {
        if (task->owned[i] > 0) {
            task->list[n++] = i;
            task->listCount++;
        }
    }
}

void STCRDDEK_drawEditor(DeckEditor *task) {
    SpriteDrawer sprite;
    CardDrawer card;
    s32 i;
    s32 id;
    s32 kind;

    initSpriteDrawer(&sprite);
    sprite.setTexture(0x280, 0);
    sprite.setLayerId(task->layer, task->depth - 2);
    if (task->cursorShown) {
        if (GFX.funcs.getTime() - task->cursorTime >= 5) {
            task->cursorTime = GFX.funcs.getTime();
            if (++task->cursorFrame >= 6) {
                task->cursorFrame = 0;
            }
        }
        sprite.setClutRow(STCRDDEK_cursorCluts[task->cursorFrame]);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x43, (task->column << 5) | 0x10, (task->row << 5) + 0x3A);
        sprite.setClutRow(0);
    }
    if (task->panels[1].level != 0) {
        if (task->panels[1].level != 0x1000) {
            sprite.setScale(task->panels[1].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x25);
        }
        initCardDrawer(&card);
        id = GAME.decks[task->deck].cards[task->column + task->row * 9];
        card.setCard(id);
        kind = card.getKind();
        if (kind) {
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), kind + 0x11, 0x103, 0x24);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xD, 0xFC, 0x22);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xB, 0x4A, 0x12);
        } else {
            kind = card.card->color;
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), kind + 0x13, 0x103, 0x24);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xD, 0xFC, 0x22);
            if (id == 0x45 || id == 0x70 || id == 0x9B || id == 0xC6 || id == 0xF1) {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xB, 0x4A, 0x12);
            } else {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xC, 0xC7, 0x12);
            }
        }
    }
    if (task->panels[0].level != 0) {
        sprite.setScale(0x1000, task->panels[0].level, 0x1000);
        if (task->panels[0].level != 0x1000) {
            sprite.setPivot(0xA0, 0x74);
        }
        sprite.setLayerId(task->layer, task->depth);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x40, 0x10, 0x15);
    }
    initSpriteDrawer(&sprite);
    sprite.setTexture(0x280, 0);
    sprite.setLayerId(task->layer, task->depth);
    if (task->panels[2].level != 0) {
        if (task->panels[2].level != 0x1000) {
            sprite.setScale(task->panels[2].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x5C);
        } else {
            /* the match depends on i being set before initCardDrawer */
            i = 0;
            initCardDrawer(&card);
            for (; i < 8; i++) {
                id = task->list[task->listTop + i];
                if (id != 0) {
                    card.setCard(id);
                    if (card.getKind()) {
                        sprite.setClutRow(card.card->color - 1);
                        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x4B, 0x94, 0x27 + i * 14);
                    } else {
                        sprite.setClutRow(0);
                        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), card.card->color + 0x4B, 0x94, 0x27 + i * 14);
                    }
                    sprite.setClutRow(0);
                    sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x31, 0x94, 0x27 + i * 14);
                }
            }
            if (task->listCount >= 9) {
                if (GFX.funcs.getTime() - task->arrowTime >= 9) {
                    task->arrowTime = GFX.funcs.getTime();
                    task->arrowsShown = 1 - task->arrowsShown;
                }
                if (task->arrowsShown) {
                    if (task->listTop > 0) {
                        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x45, 0x126, 0x22);
                    }
                    if (task->listTop < task->listCount - 8) {
                        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x46, 0x126, 0x8F);
                    }
                }
            }
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x3F, 0x81, 0x1E);
    }
    if (task->panels[3].level != 0) {
        if (task->panels[3].level != 0x1000) {
            sprite.setScale(task->panels[3].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x25);
        }
        initCardDrawer(&card);
        id = task->list[task->listTop + task->listCursor];
        card.setCard(id);
        kind = card.getKind();
        if (kind) {
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), kind + 0x11, 0x103, 0x9F);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xD, 0xFC, 0x9D);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xB, 0x4A, 0xB3);
        } else {
            kind = card.card->color;
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), kind + 0x13, 0x103, 0x9F);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xD, 0xFC, 0x9D);
            if (id == 0x45 || id == 0x70 || id == 0x9B || id == 0xC6 || id == 0xF1) {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xB, 0x4A, 0xB3);
            } else {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xC, 0xC7, 0xB3);
            }
        }
        if (task->panels[3].level != 0x1000) {
            sprite.setPivot(0x140, 0xA8);
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0xA, 0x82, 0x9D);
    }
    if (task->panels[4].level != 0) {
        if (task->panels[4].level != 0x1000) {
            sprite.setScale(0x1000, task->panels[4].level, 0x1000);
            sprite.setPivot(0, 0x78);
        }
        sprite.setLayerId(task->layer, task->depth - 3);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x36, 0, 0x64);
    }
}

void STCRDDEK_stepEditor(DeckEditor *task, DeckEditorChildren *children) {
    s32 prev;
#if VERSION_EU
    s32 prevTop;
#endif
    s32 i;
    s32 j;
    s32 id;
    s32 old;
    s32 tmp;

    switch (task->substate) {
    case 0:
    default:
        STCRDDEK_funcs.startFade(&task->panels[0], 1);
        task->substate++;
        break;
    case 1:
        if (STCRDDEK_funcs.updateFade(&task->panels[0])) {
            task->blinkTime = 0;
            STCRDDEK_showEditorWindows(task, children, 1);
            STCRDDEK_buildCardList(task);
            children->cards = STCRDDEK_createDeckCards(task);
            task->substate++;
        }
        break;
    case 2:
        if (children->cards->state == TASK_DONE) {
            task->cursorShown = 1;
            task->substate = 5;
        }
        break;
    case 5:
        prev = task->column + task->row * 9;
        if (PAD_PRESSED(PAD_LEFT) || PAD_REPEATED(PAD_LEFT)) {
            if (--task->column < 0) {
                task->column = 0;
            }
        } else if (PAD_PRESSED(PAD_RIGHT) || PAD_REPEATED(PAD_RIGHT)) {
            if (task->row == 4) {
                if (++task->column >= 4) {
                    task->column = 3;
                }
            } else {
                if (++task->column >= 9) {
                    task->column = 8;
                }
            }
        }
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            if (--task->row < 0) {
                task->row = 0;
            }
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            task->row++;
            if (task->column >= 4) {
                if (task->row >= 4) {
                    task->row = 3;
                }
            } else {
                if (task->row >= 5) {
                    task->row = 4;
                }
            }
        }
        STCRDDEK_showEditorWindows(task, children, 1);
        if (prev != task->column + task->row * 9) {
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (!PAD_HELD(PAD_L1) && PAD_PRESSED(PAD_R1)) {
            SOUND.playSound(SOUND_MENU_MOVE);
            task->substate = 10;
        } else if (PAD_PRESSED(PAD_CROSS)) {
            if (task->listCount != 0) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                task->substate = 20;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            task->substate = 50;
        } else if (PAD_PRESSED(PAD_CIRCLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            task->substate = 30;
        }
        break;
    case 10:
        task->cursorShown = 0;
        task->infoShown = 1 - task->infoShown;
        if (task->infoShown) {
            STCRDDEK_funcs.startFade(&task->panels[1], 1);
            task->substate = 11;
            task->step = 0;
        } else {
            STCRDDEK_showEditorWindows(task, children, 1);
            STCRDDEK_funcs.startFade(&task->panels[1], 0);
            task->substate = 11;
            task->step = 1;
        }
        break;
    case 11:
        if (STCRDDEK_funcs.updateFade(&task->panels[1])) {
            if (task->step == 0) {
                STCRDDEK_showEditorWindows(task, children, 1);
            }
            task->cursorShown = 1;
            task->setSubstate(task, 5);
        }
        break;
    case 20:
        children->cards->state = TASK_KILL;
        STCRDDEK_buildCardList(task);
        STCRDDEK_funcs.startFade(&task->panels[2], 1);
        while (task->list[task->listTop + task->listCursor] == 0) {
            if (--task->listTop < 0) {
                task->listTop = 0;
                if (--task->listCursor < 0) {
                    task->listCursor = 0;
                }
            }
        }
        task->cursorShown = 0;
        STCRDDEK_funcs.startFade(&task->panels[0], 0);
        if (task->infoShown) {
            task->panels[1].level = 0;
            task->infoShown = 0;
        }
        STCRDDEK_showEditorWindows(task, children, 0);
        task->substate++;
        break;
    case 21:
        if (STCRDDEK_funcs.updateFade(&task->panels[0])) {
            task->substate++;
        }
        break;
    case 22:
        if (STCRDDEK_funcs.updateFade(&task->panels[2])) {
            STCRDDEK_showCardList(task, children, 1);
            STCRDDEK_funcs.startFade(&task->panels[3], 1);
            task->substate++;
        }
        break;
    case 23:
        if (STCRDDEK_funcs.updateFade(&task->panels[3])) {
            if (task->listCount >= 9 && children->scrollBar == NULL) {
                children->scrollBar = STCRDDEK_createScrollBar();
                children->scrollBar->setX(children->scrollBar, 0x125, 0xC);
                children->scrollBar->setRange(children->scrollBar, 0x2A, 0x8F);
                children->scrollBar->setCount(children->scrollBar, 8, task->listCount);
                children->scrollBar->setPos(children->scrollBar, task->listCursor);
            }
            children->cursor->setPos(children->cursor, 0x89, task->listCursor * 14 + 0x27);
            children->cursor->setVisible(children->cursor, 1);
            STCRDDEK_showListCard(task, children, 1);
            task->substate++;
        }
        break;
    case 24:
        prev = task->listTop + task->listCursor;
#if VERSION_EU
        prevTop = task->listTop;
#endif
        if (task->listCount >= 9) {
            if ((!PAD_HELD(PAD_R1) && PAD_PRESSED(PAD_L1)) || (!PAD_HELD(PAD_R1) && PAD_REPEATED(PAD_L1))) {
                task->listTop -= 7;
                if (task->listTop < 0) {
                    task->listTop = 0;
                }
            } else if ((!PAD_HELD(PAD_L1) && PAD_PRESSED(PAD_R1)) || (!PAD_HELD(PAD_L1) && PAD_REPEATED(PAD_R1))) {
                s32 k;

                for (k = 0; k < 7; k++) {
                    if (++task->listTop > task->listCount - 8) {
                        task->listTop = task->listCount - 8;
                        break;
                    }
                }
            }
        }
        if (prev == task->listTop + task->listCursor) {
            if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
                if (--task->listCursor < 0) {
                    task->listCursor = 0;
                    if (--task->listTop < 0) {
                        task->listTop = 0;
                    }
                }
            } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
                if (task->listCount >= 9) {
                    if (++task->listCursor >= 8) {
                        task->listCursor = 7;
                        if (++task->listTop > task->listCount - 8) {
                            task->listTop = task->listCount - 8;
                        }
                    }
                } else {
                    if (++task->listCursor > task->listCount - 1) {
                        task->listCursor = task->listCount - 1;
                    }
                }
            }
        }
#if VERSION_EU
        if (children->scrollBar != NULL && prevTop != task->listTop) {
            children->scrollBar->setPos(children->scrollBar, task->listTop);
        }
#endif
        if (prev != task->listTop + task->listCursor) {
            SOUND.playSound(SOUND_CURSOR);
            children->cursor->setPos(children->cursor, 0x89, task->listCursor * 14 + 0x27);
            STCRDDEK_showCardList(task, children, 1);
            STCRDDEK_showListCard(task, children, 1);
#if VERSION_US
            if (children->scrollBar != NULL) {
                children->scrollBar->setPos(children->scrollBar, task->listTop + task->listCursor);
            }
#endif
        } else if (PAD_PRESSED(PAD_CROSS)) {
            id = task->list[task->listTop + task->listCursor];
            old = GAME.decks[task->deck].cards[task->column + task->row * 9];
            SOUND.playSound(SOUND_SELECT);
            if (id != old && GAME.cards[id] - task->owned[id] >= 4) {
                task->substate = 60;
            } else {
                GAME.decks[task->deck].cards[task->column + task->row * 9] = id;
                task->screen->countKinds(task->screen);
                task->substate++;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            task->substate++;
        }
        break;
    case 25:
        STCRDDEK_funcs.startFade(&task->panels[2], 0);
        STCRDDEK_showCardList(task, children, 0);
        STCRDDEK_funcs.startFade(&task->panels[3], 0);
        STCRDDEK_showListCard(task, children, 0);
        children->cursor->setVisible(children->cursor, 0);
        if (children->scrollBar != NULL) {
            children->scrollBar->state = TASK_KILL;
        }
        task->substate++;
        break;
    case 26:
        STCRDDEK_funcs.updateFade(&task->panels[2]);
        if (STCRDDEK_funcs.updateFade(&task->panels[3])) {
            task->listCursor = 0;
            task->listTop = 0;
            task->substate = 0;
        }
        break;
    case 30:
        children->cards->state = TASK_KILL;
        STCRDDEK_buildCardList(task);
        task->counter = 0;
        task->substate++;
        STCRDDEK_funcs.startFade(&task->panels[0], 0);
        task->cursorShown = 0;
        STCRDDEK_funcs.startFade(&task->panels[0], 0);
        task->panels[1].level = 0;
        task->infoShown = 0;
        STCRDDEK_showEditorWindows(task, children, 0);
        break;
    case 31:
        if (STCRDDEK_funcs.updateFade(&task->panels[3])) {
            task->substate++;
        }
        break;
    case 32:
        for (i = 0; i < 39; i++) {
            for (j = i + 1; j < 40; j++) {
                if (GAME.decks[task->deck].cards[i] > GAME.decks[task->deck].cards[j]) {
                    tmp = GAME.decks[task->deck].cards[i];
                    GAME.decks[task->deck].cards[i] = GAME.decks[task->deck].cards[j];
                    GAME.decks[task->deck].cards[j] = tmp;
                }
            }
        }
        task->substate = 0;
        break;
    case 50:
        children->cards->state = TASK_KILL;
        task->cursorShown = 0;
        STCRDDEK_funcs.startFade(&task->panels[0], 0);
        if (task->infoShown) {
            task->panels[1].level = 0;
            task->infoShown = 0;
        }
        STCRDDEK_showEditorWindows(task, children, 0);
        task->substate++;
        break;
    case 51:
        if (STCRDDEK_funcs.updateFade(&task->panels[0])) {
            task->state = TASK_KILL;
        }
        break;
    case 60:
        children->cursor->setPalette(children->cursor, 7);
        children->cursor->setStill(children->cursor, 1);
        STCRDDEK_funcs.startFade(&task->panels[4], 1);
        task->substate++;
        break;
    case 61:
        if (STCRDDEK_funcs.updateFade(&task->panels[4])) {
            children->message->setString(children->message, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x1E);
            task->substate++;
        }
        break;
    case 62:
        if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            children->message->setVisible(children->message, 0);
            STCRDDEK_funcs.startFade(&task->panels[4], 0);
            task->substate++;
        }
        break;
    case 63:
        if (STCRDDEK_funcs.updateFade(&task->panels[4])) {
            children->cursor->setPalette(children->cursor, 0);
            children->cursor->setStill(children->cursor, 0);
            task->substate = 23;
        }
        break;
    }
    task->blinkTime += GFX.funcs.getFrameTime();
    if (task->blinkTime > 120) {
        task->blinkTime -= 120;
    }
}

void STCRDDEK_updateEditor(DeckEditor *task, DeckEditorChildren *children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        STCRDDEK_createEditorWindows(task, children);
        task->panels[0].duration = 10;
        task->panels[1].duration = 10;
        task->panels[2].duration = 10;
        task->panels[3].duration = 10;
        task->panels[4].duration = 10;
        break;
    case TASK_RUN:
        STCRDDEK_stepEditor(task, children);
        STCRDDEK_drawEditor(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

DeckEditor *STCRDDEK_createEditor(DeckScreen *screen, s32 deck) {
    DeckEditor *task = createTask(STCRDDEK_updateEditor, sizeof(DeckEditor), sizeof(DeckEditorChildren));

    task->layer = 0x1000;
    task->depth = 6;
    task->screen = screen;
    task->deck = deck;
    return task;
}

void STCRDDEK_initIdle(DeckIdle *task, void *children) {
}

void STCRDDEK_drawIdle(DeckIdle *task) {
    SpriteDrawer drawer;

    initSpriteDrawer(&drawer);
    drawer.setLayerId(task->layer, task->depth);
}

void STCRDDEK_stepIdle(DeckIdle *task, void *children) {
    if (PAD_PRESSED(PAD_TRIANGLE)) {
        task->state = TASK_KILL;
    }
}

void STCRDDEK_updateIdle(DeckIdle *task, void *children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        STCRDDEK_initIdle(task, children);
        break;
    case TASK_RUN:
        STCRDDEK_stepIdle(task, children);
        STCRDDEK_drawIdle(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

DeckIdle *STCRDDEK_createIdle(void *parent) {
    DeckIdle *task = createTask(STCRDDEK_updateIdle, sizeof(DeckIdle), 0);

    task->layer = 0x1000;
    task->depth = 6;
    task->parent = parent;
    return task;
}

void STCRDDEK_startTween(NameTween *fade, s32 fadeIn) {
    fade->active = 1;
    if (fadeIn != 0) {
        SOUND.playSound(SOUND_MENU_OPEN);
        fade->value = 0;
        fade->step = 0x1000 / fade->duration;
    } else {
        SOUND.playSound(SOUND_MENU_CLOSE);
        fade->value = 0x1000;
        fade->step = -((0x1000 / fade->duration) * 2);
    }
}

s32 STCRDDEK_updateTween(NameTween *fade) {
    if (fade->active == 0) {
        return 1;
    }
    fade->value += fade->step;
    if (fade->step > 0) {
        if (fade->value > 0x1000) {
            fade->value = 0x1000;
            fade->active = 0;
            return 1;
        }
    } else if (fade->value < 0) {
        fade->value = 0;
        fade->active = 0;
        return 1;
    }
    return 0;
}

void STCRDDEK_createNameWindows(NameEntry *task, NameEntryWindows *windows) {
    s32 i;

    windows->title = createTextWindow(task->layer, 1, 0x20, 0x1A);
    windows->title->setPalette(windows->title, 4);
    windows->name = createTextWindow(task->layer, 1, 0x4B, 0x40);
    windows->name->setSpacing(windows->name, 0x13, 0);
    windows->name->style = (u8 *)&STCRDDEK_nameStyle;
    for (i = 0; i < 3; i++) {
        windows->tabs[i] = createTextWindow(task->layer, 1, 0x2F + i * 0x4E, 0x5B);
        windows->tabs[i]->setDepth(windows->tabs[i], task->depth - 1);
        windows->tabs[i]->setLines(windows->tabs[i], 7);
        windows->tabs[i]->setSpacing(windows->tabs[i], 0xE, 0x12);
        windows->tabs[i]->style = (u8 *)&STCRDDEK_nameStyle;
    }
    windows->leftLabel = createTextWindow(task->layer, 1, 0xCE, 0xC6);
    windows->rightLabel = createTextWindow(task->layer, 1, 0xE1, 0xC6);
    windows->l1Label = createTextWindow(task->layer, 1, 0x13, 0x62);
    windows->l1Label->setDepth(windows->l1Label, task->depth - 1);
    windows->r1Label = createTextWindow(task->layer, 1, 0x123, 0x62);
    windows->r1Label->setDepth(windows->r1Label, task->depth - 1);
    windows->message = createTextWindow(task->layer, 1, 0x3E, 0x72);
}

void STCRDDEK_showNameWindows(NameEntry *task, NameEntryWindows *windows, s32 show) {
    s32 i;

    if (show != 0) {
        windows->title->setString(windows->title, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 1);
        windows->name->setText(windows->name, task->text);
        windows->name->setPalette(windows->name, 1);
        for (i = 0; i < 3; i++) {
            windows->tabs[i]->setString(windows->tabs[i], FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)),
                                        STCRDDEK_keyboard.tabTexts[task->page].texts[i]);
            windows->tabs[i]->setPalette(windows->tabs[i], 1);
        }
        windows->leftLabel->setString(windows->leftLabel, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0xD);
        windows->leftLabel->setPalette(windows->leftLabel, 1);
        windows->rightLabel->setString(windows->rightLabel, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0xE);
        windows->rightLabel->setPalette(windows->rightLabel, 1);
        if (STCRDDEK_keyboard.pageCount >= 2) {
            windows->l1Label->setString(windows->l1Label, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0x10);
            windows->l1Label->setPalette(windows->l1Label, 1);
            windows->r1Label->setString(windows->r1Label, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0x11);
            windows->r1Label->setPalette(windows->r1Label, 1);
        }
    } else {
        windows->title->setVisible(windows->title, 0);
        windows->name->setVisible(windows->name, 0);
        for (i = 0; i < 3; i++) {
            windows->tabs[i]->setVisible(windows->tabs[i], 0);
        }
        windows->leftLabel->setVisible(windows->leftLabel, 0);
        windows->rightLabel->setVisible(windows->rightLabel, 0);
        windows->l1Label->setVisible(windows->l1Label, 0);
        windows->r1Label->setVisible(windows->r1Label, 0);
    }
}

void STCRDDEK_drawKeyboard(NameEntry *task) {
    SpriteDrawer sprite;
    s32 i;
    s32 key;

    initSpriteDrawer(&sprite);
    sprite.setTexture(task->imageX, task->imageY);
    sprite.setLayerId(task->layer, task->depth);
    if (task->keyboardScale.value != 0) {
        if (task->active) {
            if (GFX.funcs.getTime() - task->keyTime >= 5) {
                task->keyTime = GFX.funcs.getTime();
                if (++task->keyFrame >= 4) {
                    task->keyFrame = 0;
                }
            }
            sprite.setClutRow(task->keyFrame);
            if (task->column < 10 || task->row < 3) {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x27, task->column * 14 + 0x2F + task->column / 5 * 8,
                            task->row * 18 + 0x5A);
            } else {
                for (i = 0; STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column + i].kind != 1; i--) {
                }
                switch (task->column + i + task->row * 15) {
                case NAME_KEY_LEFT:
                default:
                    key = 0;
                    break;
                case NAME_KEY_RIGHT:
                    key = 1;
                    break;
                case NAME_KEY_DELETE:
                    key = 2;
                    STCRDDEK_bigKeys[2].sprite = NAME_ENTRY_TEXT_SPRITE(0x3C);
                    break;
                case NAME_KEY_SPACE:
                    key = 3;
                    STCRDDEK_bigKeys[3].sprite = NAME_ENTRY_TEXT_SPRITE(0x44);
                    break;
                case NAME_KEY_END:
                    key = 4;
                    STCRDDEK_bigKeys[4].sprite = NAME_ENTRY_TEXT_SPRITE(0x4C);
                    break;
                }
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), STCRDDEK_bigKeys[key].sprite, STCRDDEK_bigKeys[key].x,
                            STCRDDEK_bigKeys[key].y);
            }
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x28, task->cursor * 19 + 0x4B, 0x40);
            sprite.setClutRow(0);
        }
        if (task->keyboardScale.value != 0x1000) {
            sprite.setScale(task->keyboardScale.value, 0x1000, 0x1000);
        }
        if (task->keyboardScale.value != 0x1000) {
            sprite.setPivot(0x18, 0x20);
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x1D, 0x18, 0x15);
        if (task->mode != 2) {
            if (task->keyboardScale.value != 0x1000) {
                sprite.setPivot(0x20, 0x3F);
            }
            if (task->partner != -1) {
                if (GFX.funcs.getTime() - task->partnerTime >= 13) {
                    task->partnerTime = GFX.funcs.getTime();
                    if (++task->partnerFrame >= 7 || STCRDDEK_nameAnims[task->partner * 7 + task->partnerFrame] == -1) {
                        task->partnerFrame = 0;
                    }
                }
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), STCRDDEK_nameAnims[task->partner * 7 + task->partnerFrame],
                            0x22, 0x30);
            } else {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x36, 0x20, 0x2E);
            }
            if (GFX.funcs.getTime() - task->clutTime >= 5) {
                task->clutTime = GFX.funcs.getTime();
                if (++task->clutRow >= 14) {
                    task->clutRow = 0;
                }
            }
            sprite.setLayerId(task->layer, task->depth - 1);
            sprite.setClutRow(task->clutRow);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x1F, 0x20, 0x2E);
            sprite.setClutRow(0);
            sprite.setLayerId(task->layer, task->depth);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x1E, 0x20, 0x2E);
        }
        if (task->keyboardScale.value != 0x1000) {
            sprite.setPivot(0x20, 0x49);
        }
        if (task->mode != 2) {
            if (NAME_ENTRY_JAPANESE) {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x34, 0x4B, 0x40);
            } else {
                sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x37, 0x4B, 0x40);
            }
        } else {
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x35, 0x4B, 0x40);
        }
        if (task->keyboardScale.value != 0x1000) {
            sprite.setScale(0x1000, task->keyboardScale.value, 0x1000);
        }
        if (STCRDDEK_keyboard.pageCount >= 2) {
            if (GFX.funcs.getTime() - task->arrowTime >= 7) {
                task->arrowTime = GFX.funcs.getTime();
                if (++task->arrowFrame >= 6) {
                    task->arrowFrame = 0;
                }
            }
            sprite.setClutRow(STCRDDEK_keyArrowCluts[task->arrowFrame]);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x32, 0xA, 0x5E);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x33, 0x119, 0x5E);
            sprite.setClutRow(0);
        }
        sprite.setClutRow(4);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x2C, 0xCB, 0xC3);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x2D, 0xDE, 0xC3);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), NAME_ENTRY_TEXT_SPRITE(0x3C), 0xCB, 0x99);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), NAME_ENTRY_TEXT_SPRITE(0x44), 0xCB, 0xAE);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), NAME_ENTRY_TEXT_SPRITE(0x4C), 0xF6, 0xC3);
        sprite.setClutRow(0);
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x25, 0x1D, 0x54);
    }
    sprite.setLayerId(task->layer, task->depth - 1);
    if (task->messageScale.value != 0) {
        if (task->messageScale.value != 0x1000) {
            sprite.setScale(0x1000, task->messageScale.value, 0x1000);
            sprite.setPivot(0, 0x78);
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_KEY_SPRITES), 0x26, 0, 0x64);
    }
}

void STCRDDEK_updateKeyboard(NameEntry *task, NameEntryWindows *windows) {
    s32 page;
    s32 newPage;
    s32 i;
    s32 key;
    s32 j;
    u16 c;
    u32 glyph; /* the match depends on this u32 copy of c, which orders the loads of the key's glyph */

    switch (task->substate) {
    case 0:
    default:
        STCRDDEK_startTween(&task->keyboardScale, 1);
        task->substate++;
        break;
    case 1:
        if (STCRDDEK_updateTween(&task->keyboardScale)) {
            STCRDDEK_showNameWindows(task, windows, 1);
            task->active = 1;
            task->substate++;
        }
        break;
    case 2:
        if (PAD_PRESSED(PAD_START)) {
            SOUND.playSound(SOUND_MENU_MOVE);
            task->column = 13;
            task->row = 6;
            break;
        }
        if (STCRDDEK_keyboard.pageCount >= 2) {
            page = task->page;
            if (!PAD_HELD(PAD_R1) && PAD_PRESSED(PAD_L1)) {
                if (--task->page < 0) {
                    task->page = STCRDDEK_keyboard.pageCount - 1;
                }
            } else if (!PAD_HELD(PAD_L1) && PAD_PRESSED(PAD_R1)) {
                if (++task->page > STCRDDEK_keyboard.pageCount - 1) {
                    task->page = 0;
                }
            }
            if (page != task->page) {
                SOUND.playSound(SOUND_MENU_MOVE);
                STCRDDEK_showNameWindows(task, windows, 1);
                if (NAME_ENTRY_JAPANESE) {
                    newPage = task->page;
                    if (newPage == 0 || newPage == 1) {
                        while (STCRDDEK_keyboard.pages[newPage].cells[task->row][task->column].kind != 1) {
                            if (--task->column < 0) {
                                task->column = 14;
                            }
                        }
                    } else {
                        while (STCRDDEK_keyboard.pages[newPage].cells[task->row][task->column].kind == 0) {
                            if (--task->row < 0) {
                                task->row = 6;
                            }
                        }
                    }
                }
            }
        }
        if (PAD_PRESSED(PAD_LEFT) || PAD_REPEATED(PAD_LEFT)) {
            if (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind < 0) {
                task->column += STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind;
            }
            do {
                if (--task->column < 0) {
                    task->column = 14;
                }
            } while (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind != 1);
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (PAD_PRESSED(PAD_RIGHT) || PAD_REPEATED(PAD_RIGHT)) {
            if (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind < 0) {
                task->column += STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind;
            }
            do {
                if (++task->column >= 15) {
                    task->column = 0;
                }
            } while (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind != 1);
            SOUND.playSound(SOUND_MENU_MOVE);
        }
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            do {
                if (--task->row < 0) {
                    task->row = 6;
                }
            } while (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind == 0);
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            do {
                if (++task->row >= 7) {
                    task->row = 0;
                }
            } while (STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].kind == 0);
            SOUND.playSound(SOUND_MENU_MOVE);
        }
        if (PAD_PRESSED(PAD_CROSS)) {
            for (i = 0; STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column + i].kind != 1; i--) {
            }
            key = task->row * 15 + task->column + i;
            SOUND.playSound(SOUND_MENU_CONFIRM);
            switch (key) {
            case NAME_KEY_LEFT:
                if (--task->cursor < 0) {
                    task->cursor = 0;
                }
                break;
            case NAME_KEY_RIGHT:
                if (++task->cursor > task->maxLength - 1) {
                    task->cursor = task->maxLength - 1;
                }
                break;
            case NAME_KEY_DELETE:
                if (task->cursor <= task->maxLength - 1 && task->text[task->cursor] == SJIS_SPACE) {
                    if (--task->cursor < 0) {
                        task->cursor = 0;
                    }
                }
                c = ((TextStyle *)windows->name->style)->iconMap[1].code;
                task->text[task->cursor] = (c >> 8) | ((c & 0xFF) << 8);
                windows->name->setText(windows->name, task->text);
                break;
            case NAME_KEY_SPACE:
                c = ((TextStyle *)windows->name->style)->iconMap[1].code;
                task->text[task->cursor] = (c >> 8) | ((c & 0xFF) << 8);
                if (++task->cursor > task->maxLength - 1) {
                    task->cursor = task->maxLength - 1;
                }
                windows->name->setText(windows->name, task->text);
                break;
            case NAME_KEY_END:
                for (j = 0; j < task->maxLength; j++) {
                    if (task->text[j] != SJIS_SPACE && task->text[j] != 0) {
                        for (j = 19; j >= 0; j--) {
                            if (task->text[j] != SJIS_SPACE) {
                                task->substate = 100;
                                return;
                            }
                            task->text[j] = 0;
                        }
                    }
                }
                task->substate = 20;
                break;
            default:
                glyph = ((TextStyle *)windows->name->style)
                            ->sjisMap[STCRDDEK_keyboard.pages[task->page].cells[task->row][task->column].code]
                            .code;
                task->text[task->cursor] = (glyph >> 8) | ((glyph & 0xFF) << 8);
                windows->name->setText(windows->name, task->text);
                if (++task->cursor > task->maxLength - 1) {
                    task->cursor = task->maxLength - 1;
                    task->column = 13;
                    task->row = 6;
                }
                break;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            if (task->cursor <= task->maxLength - 1 && task->text[task->cursor] == SJIS_SPACE) {
                if (--task->cursor < 0) {
                    task->cursor = 0;
                }
            }
            c = ((TextStyle *)windows->name->style)->iconMap[1].code;
            task->text[task->cursor] = (c >> 8) | ((c & 0xFF) << 8);
            windows->name->setText(windows->name, task->text);
        }
        break;
    case 10:
        STCRDDEK_showNameWindows(task, windows, 0);
        STCRDDEK_startTween(&task->keyboardScale, 0);
        task->active = 0;
        task->substate++;
        break;
    case 11:
        if (STCRDDEK_updateTween(&task->keyboardScale)) {
            task->state = TASK_DONE;
        }
        break;
    case 20:
        task->active = 0;
        STCRDDEK_startTween(&task->messageScale, 1);
        task->substate++;
        break;
    case 21:
        if (STCRDDEK_updateTween(&task->messageScale)) {
            windows->message->setString(windows->message, FILE_CACHE.load(TEXT_FILE(TEXT_NAME_ENTRY)), 0x12);
            task->substate++;
        }
        break;
    case 22:
        if (PAD_PRESSED(PAD_CROSS)) {
            windows->message->setVisible(windows->message, 0);
            STCRDDEK_startTween(&task->messageScale, 0);
            task->substate++;
        }
        break;
    case 23:
        if (STCRDDEK_updateTween(&task->messageScale)) {
            task->active = 1;
            task->substate = 2;
        }
        break;
    case 100:
        break;
    }
}

void STCRDDEK_updateNameEntry(NameEntry *task, NameEntryWindows *windows) {
    TimLoader loader;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        initTimLoader(&loader);
        loader.setImagePos(task->imageX, task->imageY);
        loader.loadArchive(FILE_CACHE.getEntry(STCRDDEK_FILE_KEYBOARD << 16));
        if (NAME_ENTRY_JAPANESE) {
            STCRDDEK_keyboard.pageCount = 3;
            STCRDDEK_keyboard.tabTexts = STCRDDEK_keyPagesJp;
            STCRDDEK_keyboard.pages = STCRDDEK_keyCharsJp;
        } else {
            STCRDDEK_keyboard.pageCount = 1;
            STCRDDEK_keyboard.tabTexts = STCRDDEK_keyPages;
            STCRDDEK_keyboard.pages = STCRDDEK_keyChars;
        }
        task->unkBC.duration = 10;
        task->messageScale.duration = 10;
        task->keyboardScale.duration = 10;
        STCRDDEK_createNameWindows(task, windows);
        break;
    case TASK_RUN:
        STCRDDEK_updateKeyboard(task, windows);
        STCRDDEK_drawKeyboard(task);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void STCRDDEK_setNameVram(NameEntry *entry, s32 x, s32 y) {
    entry->imageX = x;
    entry->imageY = y;
}

void STCRDDEK_setName(NameEntry *entry, char *text) {
    TextTools tools;
    s32 i;

    initTextTools(&tools);
    tools.convert(entry->text, text, 0);
    for (i = strlen((char *)entry->text) >> 1; i < entry->maxLength; i++) {
        entry->text[i] = SJIS_SPACE;
    }
}

void STCRDDEK_getName(NameEntry *entry, char *dst) {
    TextTools tools;
    s32 i;

    for (i = 0; i < entry->maxLength * 2; i++) {
        dst[i] = 0;
    }
    for (i = entry->maxLength - 1; i >= 0; i--) {
        if (entry->text[i] != SJIS_SPACE) {
            break;
        }
        entry->text[i] = 0;
    }
    for (i = 0; i < entry->maxLength; i++) {
        if (entry->text[i] != SJIS_SPACE) {
            break;
        }
    }
    initTextTools(&tools);
    tools.convert(dst, &entry->text[i], 1);
}

void STCRDDEK_closeNameEntry(NameEntry *entry) {
    entry->substate = 10;
}

NameEntry *STCRDDEK_createNameEntry(char *text) {
    NameEntry *entry = createTask(STCRDDEK_updateNameEntry, sizeof(NameEntry), sizeof(NameEntryWindows));

    entry->getText = STCRDDEK_getName;
    entry->close = STCRDDEK_closeNameEntry;
    entry->layer = 0x1000;
    entry->depth = 3;
    entry->mode = 2;
    entry->maxLength = 10;
    entry->partner = -1;
    STCRDDEK_setName(entry, text);
    STCRDDEK_setNameVram(entry, 0x280, 0x100);
    return entry;
}

void STCRDDEK_setScrollBarX(ScrollBar *bar, s32 x, s32 width) {
    bar->x = x;
    bar->width = width;
}

void STCRDDEK_setScrollBarRange(ScrollBar *bar, s32 top, s32 bottom) {
    bar->top = top;
    bar->bottom = bottom;
    bar->hasRange = 1;
}

void STCRDDEK_setScrollBarCount(ScrollBar *bar, s32 pageSize, s32 count) {
    bar->pageSize = pageSize;
    bar->count = count;
    bar->hasCount = 1;
}

void STCRDDEK_setScrollBarPos(ScrollBar *bar, s32 pos) {
    bar->pos = pos;
}

void STCRDDEK_updateScrollBar(ScrollBar *bar) {
    Layer *layer;
    u_long *ot;
    POLY_F4 *poly;
    s32 range;
#if VERSION_US
    s32 pages;
#endif

    switch (bar->state) {
    case TASK_INIT:
    default:
        if (bar->hasRange != 0 && bar->hasCount != 0) {
#if VERSION_US
            bar->nextState(bar);
            pages = bar->count / bar->pageSize + (bar->count % bar->pageSize != 0);
            range = (bar->bottom - bar->top) << 8;
            bar->size = range / pages;
            bar->posStep = range / bar->count;
#elif VERSION_EU
            range = (bar->bottom - bar->top) << 8;
            bar->size = range / bar->count * bar->pageSize;
            bar->posStep = range / bar->count;
            bar->nextState(bar);
#endif
        }
        break;
    case TASK_RUN:
        layer = GFX.funcs.getLayer(bar->layer);
        ot = (u_long *)layer->getOtEntry(layer, bar->depth);
        poly = GFX.funcs.getPrim();
        if (bar->pos < bar->count - 1) {
            bar->y = bar->top + ((bar->pos * bar->posStep) >> 8);
            if (bar->bottom - (bar->size >> 8) < bar->y) {
                bar->y = bar->bottom - (bar->size >> 8);
            }
        } else {
            bar->y = bar->bottom - (bar->size >> 8);
        }
        setlen(poly, 5);
        poly->code = 0x28;
        poly->r0 = poly->g0 = poly->b0 = 0xFF;
        poly->x0 = poly->x2 = bar->x;
        poly->x1 = poly->x3 = bar->x + bar->width;
        poly->y0 = poly->y1 = bar->y;
        poly->y2 = poly->y3 = bar->y + (bar->size >> 8);
        addPrim(ot, poly);
        GFX.funcs.setPrim(poly + 1);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

ScrollBar *STCRDDEK_createScrollBar(void) {
    ScrollBar *bar = createTask(STCRDDEK_updateScrollBar, sizeof(ScrollBar), 0);

    bar->setX = STCRDDEK_setScrollBarX;
    bar->setRange = STCRDDEK_setScrollBarRange;
    bar->setCount = STCRDDEK_setScrollBarCount;
    bar->setPos = STCRDDEK_setScrollBarPos;
    bar->layer = 0x1000;
    bar->depth = 3;
    return bar;
}

/* The title, each deck's name and six counts, the two options and the
   cursor, then every window from the title on takes the cursor's depth */
void STCRDDEK_createScreenWindows(DeckScreen *task, DeckScreenChildren *children) {
    s32 i;
    s32 j;
    s32 y;
    TextWindow **windows;

    children->title = createTextWindow(task->layer, 1, 0x97, 0x22);
    for (i = 0; i < 3; i++) {
        /* the match depends on y: with i * 0x2D written in both calls, the
           options loop's counter takes s2 instead of the other loops' s3 */
        y = i * 0x2D;
        children->rows[i].name = createTextWindow(task->layer, 1, 0x1C, 0x53 + y);
        for (j = 0; j < 6; j++) {
            children->rows[i].counts[j] = createTextWindow(task->layer, 1, 0x3B + j * 0x23, 0x64 + y);
        }
    }
    for (i = 0; i < 2; i++) {
        children->options[i] = createTextWindow(task->layer, 1, 0xA7, 0x23 + i * 0xE);
    }
    children->cursor = createCursor(task->layer, task->depth - 2, 0x9A, 0x23);
    children->cursor->setVisible(children->cursor, 0);
    windows = &children->title;
    for (i = 0; i < task->childCount - 3; i++, windows++) {
        (*windows)->setDepth(*windows, task->depth - 2);
    }
}

void STCRDDEK_showDeckRow(DeckScreen *task, DeckScreenChildren *children, s32 deck, s32 show) {
    s32 i;

    if (show != 0) {
        children->rows[deck].name->setString(children->rows[deck].name, GAME.decks[deck].name, -1);
        for (i = 0; i < 6; i++) {
            children->rows[deck].counts[i]->setNumber(children->rows[deck].counts[i], 0, task->kinds[deck][i]);
            children->rows[deck].counts[i]->setRightAlign(children->rows[deck].counts[i], 1);
        }
    } else {
        children->rows[deck].name->setVisible(children->rows[deck].name, 0);
        for (i = 0; i < 6; i++) {
            children->rows[deck].counts[i]->setVisible(children->rows[deck].counts[i], 0);
        }
    }
}

void STCRDDEK_drawScreen(DeckScreen *task) {
    SpriteDrawer sprite;
    s32 i;

    initSpriteDrawer(&sprite);
    sprite.setLayerId(task->layer, task->depth);
    sprite.setTexture(0x280, 0);
    if (task->tick) {
        task->scroll = ++task->scroll < 96 ? task->scroll : 0;
        task->tick = 0;
    } else {
        task->tick = 1;
    }
    sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 8, task->scroll, task->scroll);
    sprite.setLayerId(task->layer, task->depth - 1);
    if (task->panels[0].level != 0) {
        if (task->panels[0].level != 0x1000) {
            sprite.setScale(task->panels[0].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x22);
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x30, 0x7B, 0x1C);
    }
    for (i = 0; i < 3; i++) {
        if (task->rowPanels[i].level != 0) {
            sprite.setScale(task->rowPanels[i].level, 0x1000, 0x1000);
            if (task->rowPanels[i].level != 0x1000) {
                sprite.setPivot(0x17, 0x63 + i * 0x2D);
            }
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x41, 0x17, 0x50 + i * 0x2D);
        }
    }
    if (task->panels[1].level != 0) {
        sprite.setScale(task->panels[1].level, 0x1000, 0x1000);
        if (task->panels[1].level != 0x1000) {
            sprite.setPivot(0x140, 0x37);
        }
        sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x2D, 0x92, 0x1C);
    }
    if (task->panels[2].level != 0) {
        sprite.setLayerId(task->layer, task->depth - 2);
        sprite.setScale(0x1000, task->panels[2].level, 0x1000);
        if (task->panels[2].level != 0x1000) {
            sprite.setPivot(0x17, task->deck * 0x2D + 0x63);
        }
        if (task->chosen == 0) {
            if (GFX.funcs.getTime() - task->cursorTime >= 5) {
                task->cursorTime = GFX.funcs.getTime();
                if (++task->cursorFrame >= 16) {
                    task->cursorFrame = 0;
                }
            }
            sprite.setClutRow(task->cursorFrame);
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x42, 0x17, task->deck * 0x2D + 0x50);
        } else {
            sprite.draw(FILE_CACHE.getEntry(STCRDDEK_SPRITES), 0x44, 0x17, task->deck * 0x2D + 0x50);
        }
    }
}

void STCRDDEK_countCardKinds(DeckScreen *task) {
    CardDrawer card;
    s32 d;
    s32 i;

    initCardDrawer(&card);
    for (d = 0; d < 3; d++) {
        for (i = 0; i < 6; i++) {
            task->kinds[d][i] = 0;
        }
        for (i = 0; i < 40; i++) {
            card.setCard(GAME.decks[d].cards[i]);
            task->kinds[d][card.card->color - 1]++;
        }
    }
}

void STCRDDEK_stepScreen(DeckScreen *task, DeckScreenChildren *children) {
    s32 prevDeck;
    s32 prevChoice;
    ScreenFade *fader;

    switch (task->substate) {
    case 0:
    default:
        STCRDDEK_countCardKinds(task);
        STCRDDEK_funcs.startFade(&task->panels[0], 1);
        STCRDDEK_funcs.startFade(&task->rowPanels[0], 1);
        task->chosen = 0;
        task->substate++;
        break;
    case 1:
        STCRDDEK_funcs.updateFade(&task->panels[0]);
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[0])) {
            children->title->setString(children->title, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x19);
            STCRDDEK_showDeckRow(task, children, 0, 1);
            STCRDDEK_funcs.startFade(&task->rowPanels[1], 1);
            task->substate++;
        }
        break;
    case 2:
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[1])) {
            STCRDDEK_showDeckRow(task, children, 1, 1);
            STCRDDEK_funcs.startFade(&task->rowPanels[2], 1);
            STCRDDEK_funcs.startFade(&task->panels[2], 1);
            task->substate++;
        }
        break;
    case 3:
        STCRDDEK_funcs.updateFade(&task->panels[2]);
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[2])) {
            STCRDDEK_showDeckRow(task, children, 2, 1);
            task->substate++;
        }
        break;
    case 4:
        prevDeck = task->deck;
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            if (--task->deck < 0) {
                task->deck = 0;
            }
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            if (++task->deck >= 3) {
                task->deck = 2;
            }
        }
        if (prevDeck != task->deck) {
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            task->substate = 10;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            task->setSubstate(task, 100);
        }
        break;
    case 10:
        task->chosen = 1;
        children->title->setVisible(children->title, 0);
        STCRDDEK_funcs.startFade(&task->panels[0], 0);
        task->substate++;
        break;
    case 11:
        if (STCRDDEK_funcs.updateFade(&task->panels[0])) {
            children->title->setVisible(children->title, 0);
            STCRDDEK_funcs.startFade(&task->panels[1], 1);
            task->substate++;
        }
        break;
    case 12:
        if (STCRDDEK_funcs.updateFade(&task->panels[1])) {
            task->renaming = 0;
            children->cursor->setPos(children->cursor, 0x9A, 0x23);
            children->cursor->setVisible(children->cursor, 1);
            children->options[0]->setString(children->options[0], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x1A);
            children->options[1]->setString(children->options[1], FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x1B);
            task->substate++;
        }
        break;
    case 13:
        prevChoice = task->renaming;
        if (PAD_PRESSED(PAD_UP)) {
            task->renaming = 0;
        } else if (PAD_PRESSED(PAD_DOWN)) {
            task->renaming = 1;
        }
        if (prevChoice != task->renaming) {
            SOUND.playSound(SOUND_CURSOR);
            children->cursor->setPos(children->cursor, 0x9A, task->renaming * 14 + 0x23);
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_SELECT);
            task->setSubstate(task, 50);
            task->step = 1;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            task->substate = 15;
        }
        break;
    case 15:
        children->cursor->setVisible(children->cursor, 0);
        children->options[0]->setVisible(children->options[0], 0);
        children->options[1]->setVisible(children->options[1], 0);
        STCRDDEK_funcs.startFade(&task->panels[1], 0);
        task->substate++;
        break;
    case 16:
        if (STCRDDEK_funcs.updateFade(&task->panels[1])) {
            STCRDDEK_funcs.startFade(&task->panels[0], 1);
            task->substate++;
        }
        break;
    case 17:
        if (STCRDDEK_funcs.updateFade(&task->panels[0])) {
            children->title->setString(children->title, FILE_CACHE.load(TEXT_FILE(TEXT_CARD_SHOP)), 0x19);
            task->chosen = 0;
            task->setSubstate(task, 4);
        }
        break;
    case 50:
        if (task->step) {
            children->cursor->setStill(children->cursor, 1);
            children->cursor->setPalette(children->cursor, 7);
        }
        STCRDDEK_funcs.startFade(&task->panels[2], 0);
        STCRDDEK_funcs.startFade(&task->rowPanels[2], 0);
        STCRDDEK_showDeckRow(task, children, 2, 0);
        task->substate++;
        break;
    case 51:
        STCRDDEK_funcs.updateFade(&task->panels[2]);
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[2])) {
            STCRDDEK_funcs.startFade(&task->rowPanels[1], 0);
            STCRDDEK_showDeckRow(task, children, 1, 0);
            task->substate++;
        }
        break;
    case 52:
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[1])) {
            if (task->step) {
                children->cursor->setStill(children->cursor, 0);
                children->cursor->setPalette(children->cursor, 0);
                children->cursor->setVisible(children->cursor, 0);
                children->options[0]->setVisible(children->options[0], 0);
                children->options[1]->setVisible(children->options[1], 0);
                STCRDDEK_funcs.startFade(&task->panels[1], 0);
            } else {
                children->title->setVisible(children->title, 0);
                STCRDDEK_funcs.startFade(&task->panels[0], 0);
            }
            STCRDDEK_funcs.startFade(&task->rowPanels[0], 0);
            STCRDDEK_showDeckRow(task, children, 0, 0);
            task->substate++;
        }
        break;
    case 53:
        if (task->step) {
            STCRDDEK_funcs.updateFade(&task->panels[1]);
        } else {
            STCRDDEK_funcs.updateFade(&task->panels[0]);
        }
        if (STCRDDEK_funcs.updateFade(&task->rowPanels[0])) {
            task->substate++;
        }
        break;
    case 54:
        if (task->step) {
            if (task->renaming == 0) {
                children->name = (NameEntry *)STCRDDEK_createEditor(task, task->deck);
            } else {
                children->name = STCRDDEK_createNameEntry(GAME.decks[task->deck].name);
            }
            task->setState(task, TASK_DONE);
        } else {
            task->state = TASK_KILL;
        }
        break;
    case 100:
        children->fader = fader = STCRDDEK_createFader();
        fader->start(fader, 0, 10);
        task->substate++;
        break;
    case 101:
        if (children->fader->state == 2) {
            task->substate = 54;
        }
        break;
    }
}

void STCRDDEK_updateScreen(DeckScreen *task, DeckScreenChildren *children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        switch (task->substate) {
        case 0:
        default:
            STCRDDEK_funcs.loadFiles();
            task->substate++;
            break;
        case 1:
            if (STCRDDEK_funcs.filesLoading() == 0) {
                STCRDDEK_createScreenWindows(task, children);
                task->panels[0].duration = 10;
                task->rowPanels[0].duration = 10;
                task->rowPanels[1].duration = 10;
                task->rowPanels[2].duration = 10;
                task->panels[1].duration = 10;
                task->panels[2].duration = 10;
                task->nextState(task);
            }
            break;
        }
        break;
    case TASK_RUN:
        STCRDDEK_stepScreen(task, children);
        STCRDDEK_drawScreen(task);
        break;
    case TASK_DONE:
        if (task->renaming != 0) {
            switch (task->substate) {
            case 0:
            default:
                if (children->name->substate == 100) {
                    children->name->getText(children->name, GAME.decks[task->deck].name);
                    children->name->close(children->name);
                    task->substate++;
                }
                break;
            case 1:
                if (children->name->state == TASK_DONE) {
                    children->name->state = TASK_KILL;
                    task->setState(task, TASK_RUN);
                }
                break;
            }
        } else if (children->name == NULL) {
            task->setState(task, TASK_RUN);
        }
        STCRDDEK_drawScreen(task);
        break;
    case TASK_KILL:
        GAME.funcs.requestMode(GAME.funcs.getPrevMode(), GAME.funcs.getModeArg());
        break;
    }
}

DeckScreen *STCRDDEK_createScreen(void) {
    DeckScreen *task = createTask(STCRDDEK_updateScreen, sizeof(DeckScreen), sizeof(DeckScreenChildren));

    task->countKinds = STCRDDEK_countCardKinds;
    task->layer = 0x1000;
    task->depth = 7;
    return task;
}

void STCRDDEK_loadFiles(void) {
    TimLoader loader;

    initTimLoader(&loader);
    loader.setImagePos(0x280, 0);
    loader.loadArchive(FILE_CACHE.getEntry(STCRDDEK_IMAGES));
    FILE_CACHE.request(STCRDDEK_FILE_CARDS);
    FILE_CACHE.request(STCRDDEK_FILE_CARDS + 1);
    FILE_CACHE.request(STCRDDEK_FILE_CARDS + 2);
    FILE_CACHE.request(STCRDDEK_FILE_CARDS + 3);
    FILE_CACHE.request(STCRDDEK_FILE_CARDS + 4);
    FILE_CACHE.request(TEXT_FILE(TEXT_CARD_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_CARD_EFFECTS));
    FILE_CACHE.request(TEXT_FILE(TEXT_CARD_SHOP));
    FILE_CACHE.request(TEXT_FILE(TEXT_NAME_ENTRY));
    FILE_CACHE.request(STCRDDEK_FILE_KEYBOARD);
}

s32 STCRDDEK_filesLoading(void) {
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_CARD_NAMES)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_CARD_EFFECTS)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_CARD_SHOP)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_NAME_ENTRY)) != 0) {
        return 1;
    }
    return FILE_CACHE.isLoading(STCRDDEK_FILE_KEYBOARD) != 0;
}

void STCRDDEK_startFade(PanelAnim *fade, s32 fadeIn) {
    fade->active = 1;
    if (fadeIn != 0) {
        SOUND.playSound(SOUND_MENU_OPEN);
        fade->level = 0;
        fade->step = 0x1000 / fade->duration;
    } else {
        SOUND.playSound(SOUND_MENU_CLOSE);
        fade->level = 0x1000;
        fade->step = -((0x1000 / fade->duration) * 2);
    }
}

s32 STCRDDEK_updateFade(PanelAnim *fade) {
    if (fade->active == 0) {
        return 1;
    }
    fade->level += fade->step;
    if (fade->step > 0) {
        if (fade->level > 0x1000) {
            fade->level = 0x1000;
            fade->active = 0;
            return 1;
        }
    } else if (fade->level < 0) {
        fade->level = 0;
        fade->active = 0;
        return 1;
    }
    return 0;
}

void STCRDDEK_startLerp(MenuLerp *lerp, s32 from, s32 to, s32 frames) {
    if (from != to) {
        lerp->duration = frames;
        lerp->fixed = from << 8;
        lerp->value = from;
        lerp->target = to;
        lerp->active = 1;
        lerp->step = ((to - from) << 8) / lerp->duration;
    }
}

s32 STCRDDEK_updateLerp(MenuLerp *lerp) {
    if (lerp->active == 0) {
        return 1;
    }
    lerp->fixed += lerp->step;
    lerp->value = lerp->fixed >> 8;
    if (lerp->step > 0) {
        if (lerp->target < lerp->value) {
            lerp->value = lerp->target;
            lerp->active = 0;
            return 1;
        }
    } else if (lerp->value < lerp->target) {
        lerp->value = lerp->target;
        lerp->active = 0;
        return 1;
    }
    return 0;
}

void STCRDDEK_loadFiles(void);
s32 STCRDDEK_filesLoading(void);
void STCRDDEK_startFade(PanelAnim *fade, s32 fadeIn);
s32 STCRDDEK_updateFade(PanelAnim *fade);
void STCRDDEK_startLerp(MenuLerp *lerp, s32 from, s32 to, s32 frames);
s32 STCRDDEK_updateLerp(MenuLerp *lerp);

/* The CLUT rows of the cursor's frames */
s32 STCRDDEK_cursorCluts[] = {
    0, 1, 2, 3,
    2, 1,
};
/* The name's font: its glyphs (230 of TextStyle.glyphCount's 234) and icons,
   which differ in the European version */
#if VERSION_US
Glyph STCRDDEK_glyphs[] = {
    { 0x01, 0x60, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x68, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x70, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x78, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x80, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x88, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x90, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x98, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xA0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xA8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xC0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xC8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xE0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xE8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x20, 0x3F, 0x30, 0xE8, 4, 12, 5, 3, 3, 12 },
    { 0x01, 0xF0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x00, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x08, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x10, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x18, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x20, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x28, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x30, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x38, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x40, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x48, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x50, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x58, 0x1E, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x60, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x68, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x70, 0x1E, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x78, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x80, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x88, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x90, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x98, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xA0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xA8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xB0, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x24, 0x3F, 0x30, 0xE8, 4, 12, 7, 3, 1, 12 },
    { 0x01, 0x28, 0x3F, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0xC0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x2C, 0x3F, 0x30, 0xE8, 4, 12, 6, 3, 3, 12 },
    { 0x01, 0xC8, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xD8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x30, 0x3F, 0x30, 0xE8, 4, 12, 6, 3, 4, 12 },
    { 0x01, 0xF0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x34, 0x3F, 0x30, 0xE8, 4, 12, 6, 3, 4, 12 },
    { 0x01, 0x00, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x08, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x10, 0x2A, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x18, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x20, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x28, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x00, 0xD8, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xE4, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xF0, 0x4A, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x00, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x0C, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 6, 12 },
    { 0x00, 0x18, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x30, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x4D, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x4D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x4E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x54, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x6C, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 6, 12 },
    { 0x00, 0x78, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x84, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xC0, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xCC, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xD8, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xE4, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xF0, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x00, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x0C, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x24, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x30, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x59, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x59, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x48, 0x5A, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x54, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0x60, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x6C, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x78, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xB4, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xC0, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xCC, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xD8, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xE4, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xF0, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x00, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x0C, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x24, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 11, 12 },
    { 0x00, 0x30, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x65, 0x30, 0xE8, 12, 12, 3, 3, 10, 9 },
    { 0x00, 0xA8, 0x65, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x66, 0x30, 0xE8, 12, 12, 2, 3, 10, 12 },
    { 0x00, 0x54, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xC0, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xCC, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xD8, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xE4, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xF0, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x00, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x0C, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x18, 0x70, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x3C, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x71, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x71, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x48, 0x72, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x6C, 0x78, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x78, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0xC0, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xCC, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xD8, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xE4, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xF0, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x00, 0x7C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x0C, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x18, 0x7C, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x24, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x7D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x7D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x7E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x84, 0x86, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x86, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x86, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x74, 0xB0, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x9C, 0xB0, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x80, 0xB3, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x8C, 0xB3, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xE8, 0x53, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x00, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x0C, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x24, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x30, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x89, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x89, 0x30, 0xE8, 12, 12, 3, 3, 7, 12 },
    { 0x00, 0x48, 0x8A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x30, 0x2A, 0x30, 0xE8, 8, 12, 4, 3, 5, 12 },
    { 0x01, 0x38, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x00, 0x78, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x92, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x92, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xB4, 0x92, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x01, 0x00, 0x54, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x01, 0x0C, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x01, 0xCC, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x40, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xD8, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x00, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x0C, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x24, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x95, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x95, 0x30, 0xE8, 12, 12, 2, 3, 10, 12 },
    { 0x00, 0x48, 0x96, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x9C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x84, 0x9E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x9E, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xB4, 0x9E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x58, 0x45, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x01, 0x64, 0x45, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x70, 0x47, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x01, 0x7C, 0x47, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x88, 0x47, 0x30, 0xE8, 12, 12, 4, 3, 6, 12 },
    { 0x00, 0x00, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x0C, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x3C, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x9C, 0xA1, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xA8, 0xA1, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x48, 0xA2, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x54, 0xA8, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0xA8, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x88, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0xA0, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x00, 0xF8, 0x38, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0xB0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x00, 0x60, 0x3C, 0x30, 0xE8, 12, 12, 4, 3, 9, 12 },
};
#elif VERSION_EU
Glyph STCRDDEK_glyphs[] = {
    { 0x01, 0x60, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x68, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x70, 0x12, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x78, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x80, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x88, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x90, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x98, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xA0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xA8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xC0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xC8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xE0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xE8, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x20, 0x3F, 0x30, 0xE8, 4, 12, 5, 3, 3, 12 },
    { 0x01, 0xF0, 0x15, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x00, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x08, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x10, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x18, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x20, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x28, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x30, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x38, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x40, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x48, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x50, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x58, 0x1E, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x60, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x68, 0x1E, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x70, 0x1E, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x78, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x80, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x88, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x90, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x98, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xA0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xA8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xB0, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xB8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x24, 0x3F, 0x30, 0xE8, 4, 12, 7, 3, 1, 12 },
    { 0x01, 0x7C, 0xB9, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0xC0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x00, 0xF8, 0x3E, 0x30, 0xE8, 4, 12, 6, 3, 3, 12 },
    { 0x01, 0xC8, 0x21, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0xD0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xD8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE8, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xD4, 0x78, 0x30, 0xE8, 4, 12, 6, 3, 4, 12 },
    { 0x01, 0xF0, 0x21, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xCC, 0x47, 0x30, 0xE8, 4, 12, 6, 3, 4, 12 },
    { 0x01, 0x00, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x01, 0x08, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x10, 0x2A, 0x30, 0xE8, 8, 12, 4, 3, 6, 12 },
    { 0x01, 0x18, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x20, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0x28, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x00, 0xD8, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xE4, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xF0, 0x4A, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x00, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x0C, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 6, 12 },
    { 0x00, 0x18, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0x4C, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x30, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x4C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x4D, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x4D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x4E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x54, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x6C, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 6, 12 },
    { 0x00, 0x78, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x84, 0x54, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xC0, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xCC, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xD8, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xE4, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xF0, 0x56, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x00, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x0C, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x24, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x30, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x58, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x59, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x59, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x48, 0x5A, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x54, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0x60, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x6C, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x78, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x60, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xB4, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xC0, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xCC, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xD8, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xE4, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xF0, 0x62, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x00, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x0C, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x24, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 11, 12 },
    { 0x00, 0x30, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x64, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x65, 0x30, 0xE8, 12, 12, 3, 3, 10, 9 },
    { 0x00, 0xA8, 0x65, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x66, 0x30, 0xE8, 12, 12, 2, 3, 10, 12 },
    { 0x00, 0x54, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x6C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xC0, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xCC, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xD8, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xE4, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xF0, 0x6E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x00, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x0C, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x18, 0x70, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x3C, 0x70, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x9C, 0x71, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xA8, 0x71, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x48, 0x72, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x6C, 0x78, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x78, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x78, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0xC0, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xCC, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xD8, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xE4, 0x7A, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xF0, 0x7A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x00, 0x7C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x0C, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x18, 0x7C, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x24, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x3C, 0x7C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x7D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x7D, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x48, 0x7E, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x84, 0x84, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x90, 0x86, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xB4, 0x86, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x58, 0xC9, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xB8, 0x53, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xDC, 0x53, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xD0, 0x53, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xE8, 0x53, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x00, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x0C, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x24, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x30, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x88, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x89, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x89, 0x30, 0xE8, 12, 12, 3, 3, 7, 12 },
    { 0x00, 0x48, 0x8A, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x30, 0x2A, 0x30, 0xE8, 8, 12, 4, 3, 5, 12 },
    { 0x01, 0x38, 0x2A, 0x30, 0xE8, 8, 12, 5, 3, 6, 12 },
    { 0x00, 0x78, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x84, 0x90, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x92, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xB4, 0x92, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x01, 0x00, 0x57, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x01, 0x0C, 0x57, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0xB4, 0xAA, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x58, 0xE6, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xD0, 0x47, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x00, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x0C, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x24, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x3C, 0x94, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x9C, 0x95, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0xA8, 0x95, 0x30, 0xE8, 12, 12, 2, 3, 10, 12 },
    { 0x00, 0x48, 0x96, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x54, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x60, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x78, 0x9C, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x84, 0x9C, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x9E, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0xB4, 0x9E, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xC4, 0x53, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x01, 0x58, 0xF2, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x18, 0xF3, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x24, 0xF3, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0xD4, 0xC1, 0x30, 0xE8, 12, 12, 4, 3, 6, 12 },
    { 0x00, 0x00, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x0C, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x18, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0x24, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x30, 0xA0, 0x30, 0xE8, 12, 12, 4, 3, 8, 12 },
    { 0x00, 0x3C, 0xA0, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x9C, 0xA1, 0x30, 0xE8, 12, 12, 4, 3, 7, 12 },
    { 0x00, 0xA8, 0xA1, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x48, 0xA2, 0x30, 0xE8, 12, 12, 3, 3, 8, 12 },
    { 0x00, 0x54, 0xA8, 0x30, 0xE8, 12, 12, 3, 3, 9, 12 },
    { 0x00, 0x60, 0xA8, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x01, 0x88, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0xA0, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0xC8, 0x9C, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0xB0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x00, 0x60, 0x3C, 0x30, 0xE8, 12, 12, 4, 3, 9, 12 },
};
#endif
#if VERSION_US
Glyph STCRDDEK_icons[] = {
    { 0x00, 0xF4, 0x14, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x00, 0xF4, 0x20, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x00, 0xF4, 0x2C, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x78, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0x80, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x88, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0x90, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x98, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0xA0, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x00, 0xF8, 0x38, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0xF8, 0x09, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xA8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0xB0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xB8, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xC0, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0xC8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x00, 0x60, 0x3C, 0x30, 0xE8, 12, 12, 4, 3, 9, 12 },
    { 0x00, 0x6C, 0x3C, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0xCC, 0x81, 0x30, 0xE8, 8, 12, 3, 3, 12, 12 },
    { 0x01, 0xD0, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 11, 12 },
    { 0x01, 0xF8, 0x15, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xF8, 0x21, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xF8, 0x2D, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xF8, 0x39, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xD8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0xE0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0xF0, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x00, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0x08, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0x10, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x18, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x20, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x28, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x00, 0x78, 0x3C, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xEC, 0x3E, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x90, 0x3E, 0x30, 0xA1, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xBC, 0x3E, 0x30, 0xA0, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xC8, 0x3E, 0x30, 0x9F, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xD4, 0x3E, 0x30, 0x9E, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xE0, 0x3E, 0x30, 0x9D, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0x30, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 12, 12 },
    { 0x01, 0x38, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x00, 0x9C, 0x41, 0x30, 0x9C, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xA8, 0x41, 0x30, 0x9B, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x54, 0x48, 0x30, 0x9A, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x60, 0x48, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x48, 0x30, 0x99, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x78, 0x48, 0x30, 0x98, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x84, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x4A, 0x30, 0x97, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xB4, 0x4A, 0x30, 0xE8, 12, 12, 3, 3, 11, 12 },
    { 0x00, 0xC0, 0x4A, 0x30, 0x96, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xCC, 0x4A, 0x30, 0x95, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0x40, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x48, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x50, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0x58, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x00, 0x8C, 0x3E, 0x30, 0xE8, 4, 12, 0, 0, 12, 12 },
    { 0x00, 0x84, 0x3C, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x6C, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x74, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x7C, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x84, 0xAA, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x8C, 0xAA, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x94, 0xAA, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0xB4, 0xAA, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x00, 0xAC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC0, 0x84, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xD4, 0x85, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xDC, 0x85, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xE4, 0x85, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xAC, 0x87, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xB4, 0x87, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x80, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x88, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x90, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x98, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA0, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC8, 0x8D, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x38, 0xA6, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x40, 0xAC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x48, 0xAF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xAF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xBB, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x98, 0xBC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA0, 0xBC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x88, 0xBF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x90, 0xBF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x68, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xCC, 0xC3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xD4, 0xC3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xDC, 0xC3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xE4, 0xC3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xEC, 0xC3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA8, 0xC5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xB0, 0xC5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xB8, 0xC5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC0, 0xC5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xF4, 0xC5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xC7, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x98, 0xC8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA0, 0xC8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x58, 0xC9, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x60, 0xC9, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x88, 0xCB, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x90, 0xCB, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x68, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC8, 0xCF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xD0, 0xCF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xD8, 0xCF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xE0, 0xCF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xE8, 0xCF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA8, 0xD1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
};
#elif VERSION_EU
Glyph STCRDDEK_icons[] = {
    { 0x00, 0x84, 0x3C, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x00, 0xF4, 0x20, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x00, 0xF4, 0x2C, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x78, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0x80, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x88, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0x90, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x98, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0xA0, 0x09, 0x30, 0xE8, 8, 12, 4, 3, 7, 12 },
    { 0x01, 0xC8, 0x9C, 0x30, 0xE8, 4, 12, 5, 3, 4, 12 },
    { 0x01, 0x3C, 0x54, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xA8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0xB0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xB8, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xC0, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0xC8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x00, 0x60, 0x3C, 0x30, 0xE8, 12, 12, 4, 3, 9, 12 },
    { 0x00, 0x6C, 0x3C, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0xA4, 0xCD, 0x30, 0xE8, 8, 12, 3, 3, 12, 12 },
    { 0x01, 0xD0, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 11, 12 },
    { 0x01, 0x78, 0x53, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xF8, 0xA8, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0x1C, 0x99, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0x1C, 0x8D, 0x30, 0xE8, 4, 12, 3, 3, 4, 12 },
    { 0x01, 0xD8, 0x09, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0xE0, 0x09, 0x30, 0xE8, 8, 12, 5, 3, 5, 12 },
    { 0x01, 0xE8, 0x09, 0x30, 0xE0, 12, 12, 3, 3, 7, 12 },
    { 0x01, 0x08, 0xF2, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x00, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0x08, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 6, 12 },
    { 0x01, 0x10, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x18, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x20, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x28, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x00, 0x78, 0x3C, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xEC, 0x3E, 0x30, 0xE8, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x90, 0x3E, 0x30, 0x99, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xBC, 0x3E, 0x30, 0x98, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xC8, 0x3E, 0x30, 0x97, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xD4, 0x3E, 0x30, 0x96, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xE0, 0x3E, 0x30, 0x95, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0x30, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 12, 12 },
    { 0x01, 0x38, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x00, 0x9C, 0x41, 0x30, 0x94, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xA8, 0x41, 0x30, 0x93, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x54, 0x48, 0x30, 0x92, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x60, 0x48, 0x30, 0xE0, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x6C, 0x48, 0x30, 0x91, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x78, 0x48, 0x30, 0x90, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0x84, 0x48, 0x30, 0xE0, 12, 12, 3, 3, 10, 12 },
    { 0x00, 0x90, 0x4A, 0x30, 0x8F, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xB4, 0x4A, 0x30, 0xE0, 12, 12, 3, 3, 11, 12 },
    { 0x00, 0xC0, 0x4A, 0x30, 0x8E, 12, 12, 3, 3, 12, 12 },
    { 0x00, 0xCC, 0x4A, 0x30, 0x8D, 12, 12, 3, 3, 12, 12 },
    { 0x01, 0x40, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x48, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 7, 12 },
    { 0x01, 0x50, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0x58, 0x12, 0x30, 0xE8, 8, 12, 3, 3, 8, 12 },
    { 0x01, 0xC8, 0x87, 0x30, 0xE8, 4, 12, 0, 0, 12, 12 },
    { 0x00, 0x38, 0xF3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x6C, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x74, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x7C, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0xF4, 0x14, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x28, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xBC, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xF4, 0x09, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x00, 0xAC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x9C, 0xC9, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x80, 0xB5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xAC, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC4, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x94, 0xC9, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC4, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x78, 0xF1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x10, 0xAC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x78, 0xD9, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC0, 0x9C, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x00, 0xF2, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x40, 0xF3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x38, 0xA6, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xB4, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x40, 0xAF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xA8, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xB4, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x38, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA4, 0x97, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x10, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x08, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x48, 0xAF, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x80, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA4, 0xA3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xCC, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xC0, 0x87, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA4, 0x8B, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x10, 0xF2, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xA4, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xB4, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x30, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x78, 0xE5, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xC0, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x78, 0xCD, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xCC, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xEA, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x50, 0xDE, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x00, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x08, 0xAC, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x18, 0x3F, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xAC, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xBC, 0xC1, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0x18, 0xF2, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xCC, 0x9C, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x01, 0xCC, 0x87, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
    { 0x00, 0x30, 0xF3, 0x30, 0xE8, 8, 12, 0, 0, 12, 12 },
};
#endif
/* the European version reads these two for language 0 */
KeyTabs STCRDDEK_keyPagesJp[] = {
    { { 2, 3, 4 } },
    { { 5, 6, 7 } },
    { { 8, 9, 10 } },
};
KeyPage STCRDDEK_keyCharsJp[] = {
    { {
        { { 1, 0x43 }, { 1, 0x45 }, { 1, 0x47 }, { 1, 0x49 }, { 1, 0x4B }, { 1, 0x85 }, { 0, 0x00 }, { 1, 0x87 }, { 0, 0x00 }, { 1, 0x89 }, { 1, 0x72 }, { 1, 0x75 }, { 1, 0x78 }, { 1, 0x7B }, { 1, 0x7E } },
        { { 1, 0x4C }, { 1, 0x4E }, { 1, 0x50 }, { 1, 0x52 }, { 1, 0x54 }, { 1, 0x8A }, { 1, 0x8B }, { 1, 0x8C }, { 1, 0x8D }, { 1, 0x8E }, { 1, 0x42 }, { 1, 0x44 }, { 1, 0x46 }, { 1, 0x48 }, { 1, 0x4A } },
        { { 1, 0x56 }, { 1, 0x58 }, { 1, 0x5A }, { 1, 0x5C }, { 1, 0x5E }, { 1, 0x90 }, { 0, 0x00 }, { 1, 0x91 }, { 0, 0x00 }, { 1, 0x92 }, { 1, 0x84 }, { 1, 0x86 }, { 1, 0x88 }, { 1, 0x64 }, { 0, 0x00 } },
        { { 1, 0x60 }, { 1, 0x62 }, { 1, 0x65 }, { 1, 0x67 }, { 1, 0x69 }, { 1, 0x4D }, { 1, 0x4F }, { 1, 0x51 }, { 1, 0x53 }, { 1, 0x55 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 } },
        { { 1, 0x6B }, { 1, 0x6C }, { 1, 0x6D }, { 1, 0x6E }, { 1, 0x6F }, { 1, 0x57 }, { 1, 0x59 }, { 1, 0x5B }, { 1, 0x5D }, { 1, 0x5F }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0x70 }, { 1, 0x73 }, { 1, 0x76 }, { 1, 0x79 }, { 1, 0x7C }, { 1, 0x61 }, { 1, 0x63 }, { 1, 0x66 }, { 1, 0x68 }, { 1, 0x6A }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0x7F }, { 1, 0x80 }, { 1, 0x81 }, { 1, 0x82 }, { 1, 0x83 }, { 1, 0x71 }, { 1, 0x74 }, { 1, 0x77 }, { 1, 0x7A }, { 1, 0x7D }, { 1, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { 1, 0x00 }, { -1, 0x00 } },
    } },
    { {
        { { 1, 0x94 }, { 1, 0x96 }, { 1, 0x98 }, { 1, 0x9A }, { 1, 0x9C }, { 1, 0xD6 }, { 0, 0x00 }, { 1, 0xD8 }, { 0, 0x00 }, { 1, 0xDA }, { 1, 0xC3 }, { 1, 0xC6 }, { 1, 0xC9 }, { 1, 0xCC }, { 1, 0xCF } },
        { { 1, 0x9D }, { 1, 0x9F }, { 1, 0xA1 }, { 1, 0xA3 }, { 1, 0xA5 }, { 1, 0xDB }, { 1, 0xDC }, { 1, 0xDD }, { 1, 0xDE }, { 1, 0xDF }, { 1, 0x93 }, { 1, 0x95 }, { 1, 0x97 }, { 1, 0x99 }, { 1, 0x9B } },
        { { 1, 0xA7 }, { 1, 0xA9 }, { 1, 0xAB }, { 1, 0xAD }, { 1, 0xAF }, { 1, 0xE1 }, { 0, 0x00 }, { 1, 0xE2 }, { 0, 0x00 }, { 1, 0xE3 }, { 1, 0xD5 }, { 1, 0xD7 }, { 1, 0xD9 }, { 1, 0xB5 }, { 1, 0xE4 } },
        { { 1, 0xB1 }, { 1, 0xB3 }, { 1, 0xB6 }, { 1, 0xB8 }, { 1, 0xBA }, { 1, 0x9E }, { 1, 0xA0 }, { 1, 0xA2 }, { 1, 0xA4 }, { 1, 0xA6 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 } },
        { { 1, 0xBC }, { 1, 0xBD }, { 1, 0xBE }, { 1, 0xBF }, { 1, 0xC0 }, { 1, 0xA8 }, { 1, 0xAA }, { 1, 0xAC }, { 1, 0xAE }, { 1, 0xB0 }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0xC1 }, { 1, 0xC4 }, { 1, 0xC7 }, { 1, 0xCA }, { 1, 0xCD }, { 1, 0xB2 }, { 1, 0xB4 }, { 1, 0xB7 }, { 1, 0xB9 }, { 1, 0xBB }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0xD0 }, { 1, 0xD1 }, { 1, 0xD2 }, { 1, 0xD3 }, { 1, 0xD4 }, { 1, 0xC2 }, { 1, 0xC5 }, { 1, 0xC8 }, { 1, 0xCB }, { 1, 0xCE }, { 1, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { 1, 0x00 }, { -1, 0x00 } },
    } },
    { {
        { { 1, 0x0E }, { 1, 0x0F }, { 1, 0x10 }, { 1, 0x11 }, { 1, 0x12 }, { 1, 0x28 }, { 1, 0x29 }, { 1, 0x2A }, { 1, 0x2B }, { 1, 0x2C }, { 1, 0x04 }, { 1, 0x05 }, { 1, 0x06 }, { 1, 0x07 }, { 1, 0x08 } },
        { { 1, 0x13 }, { 1, 0x14 }, { 1, 0x15 }, { 1, 0x16 }, { 1, 0x17 }, { 1, 0x2D }, { 1, 0x2E }, { 1, 0x2F }, { 1, 0x30 }, { 1, 0x31 }, { 1, 0x09 }, { 1, 0x0A }, { 1, 0x0B }, { 1, 0x0C }, { 1, 0x0D } },
        { { 1, 0x18 }, { 1, 0x19 }, { 1, 0x1A }, { 1, 0x1B }, { 1, 0x1C }, { 1, 0x32 }, { 1, 0x33 }, { 1, 0x34 }, { 1, 0x35 }, { 1, 0x36 }, { 1, 0xE8 }, { 1, 0xE9 }, { 1, 0xE5 }, { 1, 0xE6 }, { 1, 0xE7 } },
        { { 1, 0x1D }, { 1, 0x1E }, { 1, 0x1F }, { 1, 0x20 }, { 1, 0x21 }, { 1, 0x37 }, { 1, 0x38 }, { 1, 0x39 }, { 1, 0x3A }, { 1, 0x3B }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 } },
        { { 1, 0x22 }, { 1, 0x23 }, { 1, 0x24 }, { 1, 0x25 }, { 1, 0x26 }, { 1, 0x3C }, { 1, 0x3D }, { 1, 0x3E }, { 1, 0x3F }, { 1, 0x40 }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0x27 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x41 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { 1, 0x00 }, { -1, 0x00 } },
    } },
};
KeyTabs STCRDDEK_keyPages[] = {
    { { 8, 9, 10 } },
};
KeyPage STCRDDEK_keyChars[] = {
    { {
        { { 1, 0x0E }, { 1, 0x0F }, { 1, 0x10 }, { 1, 0x11 }, { 1, 0x12 }, { 1, 0x28 }, { 1, 0x29 }, { 1, 0x2A }, { 1, 0x2B }, { 1, 0x2C }, { 1, 0x04 }, { 1, 0x05 }, { 1, 0x06 }, { 1, 0x07 }, { 1, 0x08 } },
        { { 1, 0x13 }, { 1, 0x14 }, { 1, 0x15 }, { 1, 0x16 }, { 1, 0x17 }, { 1, 0x2D }, { 1, 0x2E }, { 1, 0x2F }, { 1, 0x30 }, { 1, 0x31 }, { 1, 0x09 }, { 1, 0x0A }, { 1, 0x0B }, { 1, 0x0C }, { 1, 0x0D } },
        { { 1, 0x18 }, { 1, 0x19 }, { 1, 0x1A }, { 1, 0x1B }, { 1, 0x1C }, { 1, 0x32 }, { 1, 0x33 }, { 1, 0x34 }, { 1, 0x35 }, { 1, 0x36 }, { 1, 0xE8 }, { 1, 0xE9 }, { 1, 0xE5 }, { 1, 0xE6 }, { 1, 0xE7 } },
        { { 1, 0x1D }, { 1, 0x1E }, { 1, 0x1F }, { 1, 0x20 }, { 1, 0x21 }, { 1, 0x37 }, { 1, 0x38 }, { 1, 0x39 }, { 1, 0x3A }, { 1, 0x3B }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 } },
        { { 1, 0x22 }, { 1, 0x23 }, { 1, 0x24 }, { 1, 0x25 }, { 1, 0x26 }, { 1, 0x3C }, { 1, 0x3D }, { 1, 0x3E }, { 1, 0x3F }, { 1, 0x40 }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 1, 0x27 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x41 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { -2, 0x00 }, { -3, 0x00 }, { -4, 0x00 } },
        { { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 0, 0x00 }, { 1, 0x00 }, { 1, 0x00 }, { -1, 0x00 }, { 1, 0x00 }, { -1, 0x00 } },
    } },
};
TextStyle STCRDDEK_nameStyle = {
    0xFF, 14, {0}, (s32)STCRDDEK_glyphs, (s32)STCRDDEK_icons,
    FONT_GLYPH_MAP, FONT_ICON_MAP,
    234, 114,
};
s32 STCRDDEK_nameAnims[] = {
    7, 8, 9, 10,
    9, 8, -1, 14,
    15, 16, 15, -1,
    -1, -1, 11, 12,
    13, 12, -1, -1,
    -1, 3, 4, 5,
    6, 5, 4, -1,
    25, 26, 27, 28,
    27, 26, -1, 0,
    1, 2, 1, -1,
    -1, -1, 17, 18,
    19, 20, 19, 18,
    -1, 21, 22, 23,
    24, 23, 22, -1,
};
BigKey STCRDDEK_bigKeys[] = {
    { 44, 203, 195 }, { 45, 222, 195 }, { 60, 203, 153 }, { 68, 203, 174 }, { 76, 246, 195 },
};
s32 STCRDDEK_keyArrowCluts[] = {
    0, 1, 2, 3,
    2, 1,
};
DeckFuncs STCRDDEK_funcs = {
    STCRDDEK_loadFiles, STCRDDEK_filesLoading, STCRDDEK_startFade,
    STCRDDEK_updateFade, STCRDDEK_startLerp, STCRDDEK_updateLerp,
};
NameKeyboard STCRDDEK_keyboard = {0};
