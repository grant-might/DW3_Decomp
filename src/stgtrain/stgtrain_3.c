/* The third object of STGTRAIN.PRO (see stgtrain.c), the training
   session (STGTRAIN_runSession), the partner's sprites and the menu: its rodata
   starts at 0x800825E8 (USA). */

#include "stgtrain.h"

/* Creates the training session's text windows and cursor */
void STGTRAIN_createSessionWindows(TrainSession *session, TrainSessionWindows *win) {
    win->text[0] = createTextWindow(session->layerId, 1, 0xA2, 0x49);
    win->text[1] = createTextWindow(session->layerId, 1, 0xBC, 0x14);
    win->text[2] = createTextWindow(session->layerId, 1, 0xC0, 0x29);
    win->intensities[0] = createTextWindow(session->layerId, 1, 0x98, 0x66);
    win->intensities[1] = createTextWindow(session->layerId, 1, 0xC0, 0x66);
    win->intensities[2] = createTextWindow(session->layerId, 1, 0xE6, 0x66);
    win->notice = createTextWindow(session->layerId, 1, 0x94, 0x87);
    win->answers[0] = createTextWindow(session->layerId, 1, 0xA2, 0x64);
    win->answers[1] = createTextWindow(session->layerId, 1, 0xA2, 0x74);
    win->cursor = createCursor(session->layerId, session->depth - 1, 0, 0);
    win->cursor->setVisible(win->cursor, 0);
}

/*
 * Draws a training session: the training's icon, its panels and the cursor
 * over the three columns.
 */
void STGTRAIN_drawSession(TrainSession *session) {
    SpriteDrawer sprite;
    s32 i;

    initSpriteDrawer(&sprite);
    sprite.setLayerId(session->layerId, session->depth);
    sprite.setTexture(0x240, 0x100);
    if (session->panels[2].level != 0) {
        if (session->panels[2].level != 0x1000) {
            sprite.setScale(session->panels[2].level, session->panels[2].level, 0x1000);
            sprite.setPivot(0xA6, 0x26);
        }
        if (GFX.funcs.getTime() - session->iconTime >= 0x10) {
            session->iconTime = GFX.funcs.getTime();
            session->iconFrame++;
            if (session->iconFrame >= 4) {
                session->iconFrame = 0;
            }
        }
        /* the match depends on i holding the icon too */
        i = STGTRAIN_state.trainings[session->screen->unk78].icons[session->iconFrame];
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_FILE_SPRITES << 16), i, 0x94, 0x14);
    }
    if (session->panels[3].level != 0) {
        if (session->panels[3].level != 0x1000) {
            sprite.setScale(session->panels[3].level, session->panels[3].level, 0x1000);
            sprite.setPivot(0xCE, 0x2F);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x2A, 0xBC, 0x26);
    }
    if (session->panels[1].level != 0) {
        sprite.setScale(session->panels[1].level, 0x1000, 0x1000);
        if (session->panels[1].level != 0x1000) {
            sprite.setPivot(0x140, 0x26);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x25, 0x8F, 0xF);
    }
    if (session->panels[0].level != 0) {
        if (session->panels[0].level != 0x1000) {
            sprite.setScale(session->panels[0].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x4E);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x26, 0x85, 0x43);
    }
    if (session->cursorShown != 0) {
        if (GFX.funcs.getTime() - session->cursorTime >= 0xB) {
            session->cursorTime = GFX.funcs.getTime();
            session->cursorClut++;
            if (session->cursorClut >= 4) {
                session->cursorClut = 0;
            }
        }
        sprite.setClutRow(session->cursorClut);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x29, session->intensity * 40 + 0x94, 0x63);
        sprite.setClutRow(0);
    }
    if (session->panels[6].level != 0) {
        if (session->panels[6].level != 0x1000) {
            sprite.setScale(session->panels[6].level, session->panels[6].level, 0x1000);
        }
        for (i = 0; i < 3; i++) {
            if (session->panels[6].level != 0x1000) {
                sprite.setPivot(i * 40 + 0xA6, 0x6C);
            }
            sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x2A, i * 40 + 0x94, 0x63);
        }
    }
    if (session->panels[5].level != 0) {
        sprite.setScale(session->panels[5].level, 0x1000, 0x1000);
        sprite.setPivot(0x140, 0x6C);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x27, 0x82, 0x5E);
    }
    if (session->panels[7].level != 0) {
        sprite.setScale(session->panels[7].level, 0x1000, 0x1000);
        sprite.setPivot(0x140, 0x8D);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x27, 0x82, 0x7F);
    }
    if (session->panels[4].level != 0) {
        sprite.setScale(session->panels[4].level, 0x1000, 0x1000);
        sprite.setPivot(0x140, 0x72);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x1D, 0x82, 0x5E);
    }
}

/*
 * Runs a training session: opens its panels, picks one of three
 * intensities (it costs STGTRAIN_intensityCosts's points of totals.fields.tp), asks to confirm
 * and closes, with the intensity in the screen's unk7C. The match depends on
 * each loop and each cursor's last value having a variable of its own:
 * shared, they take other registers.
 */
void STGTRAIN_runSession(TrainSession *session, TrainSessionWindows *win) {
    PartnerTotals totals;
    PartnerStats *stats;
    s32 i;
    s32 j;
    s32 k;
    s32 last;
    s32 choice;
    s32 name;

    switch (session->substate) {
    case 0:
    default:
        STGTRAIN_state.startFade(&session->panels[1], 1);
        session->substate++;
        break;
    case 1:
        if (STGTRAIN_state.updateFade(&session->panels[1])) {
            name = STGTRAIN_state.trainings[session->screen->unk78].name;
            win->text[1]->setString(win->text[1], FILE_CACHE.load(STGTRAIN_TEXT), name);
            STGTRAIN_state.startFade(&session->panels[2], 1);
            session->substate++;
        }
        break;
    case 2:
        if (STGTRAIN_state.updateFade(&session->panels[2])) {
            STGTRAIN_state.startFade(&session->panels[0], 1);
            session->substate++;
        }
        break;
    case 3:
        if (STGTRAIN_state.updateFade(&session->panels[0])) {
            win->text[0]->setString(win->text[0], FILE_CACHE.load(STGTRAIN_TEXT), 8);
            STGTRAIN_state.startFade(&session->panels[5], 1);
            session->substate++;
        }
        break;
    case 4:
        if (STGTRAIN_state.updateFade(&session->panels[5])) {
            STGTRAIN_state.startFade(&session->panels[6], 1);
            session->substate++;
        }
        break;
    case 5:
        if (STGTRAIN_state.updateFade(&session->panels[6])) {
            for (i = 0; i < 3; i++) {
                win->intensities[i]->setString(win->intensities[i], FILE_CACHE.load(STGTRAIN_TEXT), i + 0xE);
            }
            session->cursorShown = 1;
            session->substate++;
        }
        break;
    case 6:
        last = session->intensity;
        if (PAD_PRESSED(PAD_LEFT) || PAD_REPEATED(PAD_LEFT)) {
            if (--session->intensity < 0) {
                session->intensity = 0;
            }
        } else if (PAD_PRESSED(PAD_RIGHT) || PAD_REPEATED(PAD_RIGHT)) {
            if (++session->intensity >= 3) {
                session->intensity = 2;
            }
        }
        if (last != session->intensity) {
            SOUND.playSound(SOUND_MENU_MOVE);
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            GAME.funcs.computeStats(GAME.funcs.getPartyMember(session->screen->partner), &totals);
            if (totals.fields.tp < STGTRAIN_intensityCosts[session->intensity]) {
                session->substate = 0xA;
            } else {
                session->substate = 0xF;
                session->screen->unk7C = session->intensity;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            session->substate = 0x32;
            session->step = 1;
        }
        break;
    case 0xA:
        session->cursorShown = 0;
        STGTRAIN_state.startFade(&session->panels[7], 1);
        session->substate++;
        break;
    case 0xB:
        if (STGTRAIN_state.updateFade(&session->panels[7])) {
            win->notice->setString(win->notice, FILE_CACHE.load(STGTRAIN_TEXT), 0x12);
            session->substate++;
        }
        break;
    case 0xC:
        if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            win->notice->setVisible(win->notice, 0);
            STGTRAIN_state.startFade(&session->panels[7], 0);
            session->substate++;
        }
        break;
    case 0xD:
        if (STGTRAIN_state.updateFade(&session->panels[7])) {
            session->cursorShown = 1;
            session->substate = 6;
        }
        break;
    case 0xF:
        session->cursorShown = 0;
        win->text[0]->setVisible(win->text[0], 0);
        for (j = 0; j < 3; j++) {
            win->intensities[j]->setVisible(win->intensities[j], 0);
        }
        session->panels[6].level = 0;
        STGTRAIN_state.startFade(&session->panels[5], 0);
        STGTRAIN_state.startFade(&session->panels[0], 0);
        session->substate++;
        break;
    case 0x10:
        STGTRAIN_state.updateFade(&session->panels[5]);
        if (STGTRAIN_state.updateFade(&session->panels[0])) {
            STGTRAIN_state.startFade(&session->panels[0], 1);
            STGTRAIN_state.startFade(&session->panels[4], 1);
            STGTRAIN_state.startFade(&session->panels[3], 1);
            session->substate++;
        }
        break;
    case 0x11:
        STGTRAIN_state.updateFade(&session->panels[3]);
        STGTRAIN_state.updateFade(&session->panels[0]);
        if (STGTRAIN_state.updateFade(&session->panels[4])) {
            win->text[2]->setString(win->text[2], FILE_CACHE.load(STGTRAIN_TEXT), session->intensity + 0xE);
            win->text[0]->setString(win->text[0], FILE_CACHE.load(STGTRAIN_TEXT), 9);
            win->answers[0]->setString(win->answers[0], FILE_CACHE.load(STGTRAIN_TEXT), 0xA);
            win->answers[1]->setString(win->answers[1], FILE_CACHE.load(STGTRAIN_TEXT), 0xB);
            session->unk6C = 0;
            win->cursor->setPos(win->cursor, 0x94, 0x64);
            win->cursor->setVisible(win->cursor, 1);
            session->substate++;
        }
        break;
    case 0x12:
        choice = session->unk6C;
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            session->unk6C = 0;
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            session->unk6C = 1;
        }
        if (choice != session->unk6C) {
            SOUND.playSound(SOUND_CURSOR);
            win->cursor->setPos(win->cursor, 0x94, session->unk6C * 16 + 0x64);
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_SELECT);
            if (session->unk6C == 0) {
                session->substate = 0x19;
                stats = GAME.funcs.getPartnerStats(GAME.funcs.getPartyMember(session->screen->partner));
                stats->stats[1] -= STGTRAIN_intensityCosts[session->intensity];
            } else {
                session->substate++;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            session->substate++;
        }
        break;
    case 0x13:
        STGTRAIN_state.startFade(&session->panels[0], 0);
        STGTRAIN_state.startFade(&session->panels[4], 0);
        STGTRAIN_state.startFade(&session->panels[3], 0);
        win->text[2]->setVisible(win->text[2], 0);
        win->text[0]->setVisible(win->text[0], 0);
        win->answers[0]->setVisible(win->answers[0], 0);
        win->answers[1]->setVisible(win->answers[1], 0);
        win->cursor->setVisible(win->cursor, 0);
        session->substate++;
        break;
    case 0x14:
        STGTRAIN_state.updateFade(&session->panels[3]);
        STGTRAIN_state.updateFade(&session->panels[0]);
        if (STGTRAIN_state.updateFade(&session->panels[4])) {
            STGTRAIN_state.startFade(&session->panels[0], 1);
            session->substate = 3;
        }
        break;
    case 0x19:
        STGTRAIN_state.startFade(&session->panels[0], 0);
        win->text[0]->setVisible(win->text[0], 0);
        STGTRAIN_state.startFade(&session->panels[4], 0);
        win->answers[0]->setVisible(win->answers[0], 0);
        win->answers[1]->setVisible(win->answers[1], 0);
        win->cursor->setVisible(win->cursor, 0);
        session->substate++;
        break;
    case 0x1A:
        STGTRAIN_state.updateFade(&session->panels[0]);
        if (STGTRAIN_state.updateFade(&session->panels[4])) {
            session->substate = 0x23;
        }
        break;
    case 0x1E:
        win->text[1]->setVisible(win->text[1], 0);
        win->text[2]->setVisible(win->text[2], 0);
        session->panels[2].level = 0;
        session->panels[3].level = 0;
        STGTRAIN_state.startFade(&session->panels[1], 0);
        session->substate++;
        break;
    case 0x1F:
        if (STGTRAIN_state.updateFade(&session->panels[1])) {
            session->state = TASK_KILL;
        }
        break;
    case 0x23: /* a step that does nothing: its table entry leaves the switch */
        break;
    case 0x32:
        session->cursorShown = 0;
        win->text[0]->setVisible(win->text[0], 0);
        for (k = 0; k < 3; k++) {
            win->intensities[k]->setVisible(win->intensities[k], 0);
        }
        win->text[1]->setVisible(win->text[1], 0);
        STGTRAIN_state.startFade(&session->panels[1], 0);
        STGTRAIN_state.startFade(&session->panels[2], 0);
        STGTRAIN_state.startFade(&session->panels[0], 0);
        STGTRAIN_state.startFade(&session->panels[6], 0);
        STGTRAIN_state.startFade(&session->panels[5], 0);
        session->substate++;
        break;
    case 0x33:
        STGTRAIN_state.updateFade(&session->panels[1]);
        STGTRAIN_state.updateFade(&session->panels[2]);
        STGTRAIN_state.updateFade(&session->panels[0]);
        STGTRAIN_state.updateFade(&session->panels[6]);
        if (STGTRAIN_state.updateFade(&session->panels[5]) && session->step != 0) {
            session->state = TASK_DONE;
        }
        break;
    }
}

/* A training session */
void STGTRAIN_updateSession(TrainSession *session, TrainSessionWindows *win) {
    switch (session->state) {
    case TASK_INIT:
    default:
        session->nextState(session);
        STGTRAIN_createSessionWindows(session, win);
        session->panels[6].duration = 8;
        session->panels[5].duration = 10;
        session->panels[4].duration = 10;
        session->panels[0].duration = 10;
        session->panels[1].duration = 10;
        session->panels[3].duration = 6;
        session->panels[2].duration = 6;
        session->panels[7].duration = 10;
        session->intensity = session->screen->unk7C;
        break;
    case TASK_RUN:
        STGTRAIN_runSession(session, win);
    case TASK_DONE:
        STGTRAIN_drawSession(session);
    case TASK_KILL:
        break;
    }
}

/* Makes the session close (its substate 0x1E) */
void STGTRAIN_finishSession(TrainSession *session) {
    session->substate = 0x1E;
}

/* Creates a training session */
TrainSession *STGTRAIN_createSession(TrainScreen *screen) {
    TrainSession *session = createTask(STGTRAIN_updateSession, sizeof(TrainSession), sizeof(TrainSessionWindows));

    session->finish = STGTRAIN_finishSession;
    session->layerId = 0x1000;
    session->depth = 6;
    session->screen = screen;
    return session;
}

/*
 * A training's Digimon (TrainActor): once its file is loaded and its
 * positions set, makes its sprite (and the effect of set 8); then grows or
 * shrinks (mode 2), plays the training (mode 4: two animations, then the
 * chance decides between the worked and failed ones) or its end (mode 8).
 */
void STGTRAIN_updateActor(TrainActor *actor, TrainActorSprites *sprites) {
    s32 *pos;
    s32 filePos;
    s32 x;
    s32 y;
    s32 done;
    s32 worked;
    TrainAnim *anim;

    switch (actor->state) {
    case TASK_INIT:
    default:
        if (FILE_CACHE.isLoading(STGTRAIN_state.getFileId(actor->file)) == 0 && actor->posSet != 0 &&
            actor->clutSet != 0) {
            actor->nextState(actor);
            filePos = STGTRAIN_state.getFilePos(actor->file);
            STGTRAIN_state.readSet(actor->set);
            /* the match depends on pos set here, after the two calls: set
               before them it lives too long, and x takes its register */
            pos = actor->pos;
            STGTRAIN_state.loadSet(actor->set, pos);
            if (sprites->sprite == NULL) {
                sprites->sprite = STGTRAIN_createSprite();
            }
            x = filePos & 0xFFFF;
            sprites->sprite->setBank(sprites->sprite, STGTRAIN_state.getBank(actor->set),
                                     STGTRAIN_state.getBankOffset(actor->set));
            y = (u32)filePos >> 16;
            sprites->sprite->setAnim(sprites->sprite, STGTRAIN_state.getAnim(actor->set, actor->anim));
            sprites->sprite->setPos(sprites->sprite, x, y);
            sprites->sprite->setImagePos(sprites->sprite, actor->pos[0], actor->pos[1]);
            sprites->sprite->setClutPos(sprites->sprite, actor->pos[2], actor->pos[3]);
            sprites->sprite->setLayer(sprites->sprite, actor->layerId, actor->depth);
            if (STGTRAIN_state.readSet(8) != 0) {
                actor->savedX = actor->pos[0];
                actor->pos[0] = actor->pos[0] + 0x80;
                STGTRAIN_state.loadSet(8, pos);
                actor->pos[0] = actor->savedX;
                if (sprites->effect == NULL) {
                    sprites->effect = STGTRAIN_createSprite();
                }
                sprites->effect->setBank(sprites->effect, STGTRAIN_state.getBank(8), STGTRAIN_state.getBankOffset(8));
                sprites->effect->setAnim(sprites->effect, STGTRAIN_state.getAnim(8, actor->anim));
                sprites->effect->setPos(sprites->effect, x, y);
                sprites->effect->setImagePos(sprites->effect, actor->pos[0], actor->pos[1]);
                sprites->effect->setClutPos(sprites->effect, actor->pos[2], actor->pos[3]);
                if (STGTRAIN_state.getFileUnkC(actor->file) == 0) {
                    sprites->effect->setLayer(sprites->effect, actor->layerId, actor->depth - 1);
                } else {
                    sprites->effect->setLayer(sprites->effect, actor->layerId, actor->depth);
                }
            } else if (sprites->effect != NULL) {
                sprites->effect->setState(sprites->effect, TASK_KILL);
            }
            actor->result = -1;
        }
        break;
    case TASK_RUN:
        if (actor->scaleChanged != 0) {
            if (sprites->sprite != NULL) {
                sprites->sprite->setScale(sprites->sprite, actor->scale, actor->scale, 0x1000);
            }
            if (sprites->effect != NULL) {
                sprites->effect->setScale(sprites->effect, actor->scale, actor->scale, 0x1000);
            }
            actor->scaleChanged = 0;
        }
        switch ((u32)actor->mode) {
        case 1:
            break;
        case 2:
            actor->scale += actor->scaleStep;
            if (actor->scaleStep > 0) {
                if (actor->scale > 0x1000) {
                    actor->scale = 0x1000;
                    actor->scaleStep = 0;
                    actor->mode = 1;
                }
            } else if (actor->scale < 0) {
                actor->scale = 0;
                actor->scaleStep = 0;
                actor->mode = 1;
            }
            if (sprites->sprite != NULL) {
                sprites->sprite->setScale(sprites->sprite, actor->scale, actor->scale, 0x1000);
                sprites->sprite->setPivot(sprites->sprite, 0xCF, 0x7F);
            }
            if (sprites->effect != NULL) {
                sprites->effect->setScale(sprites->effect, actor->scale, actor->scale, 0x1000);
                sprites->effect->setPivot(sprites->effect, 0xCF, 0x7F);
            }
            break;
        case 4:
            if (sprites->effect != NULL) {
                done = sprites->sprite->getFlags(sprites->sprite) & sprites->effect->getFlags(sprites->effect);
            } else {
                done = sprites->sprite->getFlags(sprites->sprite);
            }
            if (done) {
                if (actor->substate == 0) {
                    actor->anim++;
                    if (actor->anim >= 2) {
                        worked = actor->chance >= RANDOM.next() % 100;
                        if (worked == 1) {
                            if (sprites->sprite != NULL) {
                                sprites->sprite->setAnim(sprites->sprite, STGTRAIN_state.getAnim(actor->set, 2));
                            }
                            if (sprites->effect != NULL) {
                                sprites->effect->setAnim(sprites->effect, STGTRAIN_state.getAnim(8, 2));
                            }
                            /* and on a 1 here: CSE puts worked's register
                               in, while worked itself leaves it a copy */
                            actor->result = 1;
                        } else {
                            if (sprites->sprite != NULL) {
                                sprites->sprite->setAnim(sprites->sprite, STGTRAIN_state.getAnim(actor->set, 3));
                            }
                            if (sprites->effect != NULL) {
                                sprites->effect->setAnim(sprites->effect, STGTRAIN_state.getAnim(8, 3));
                            }
                            actor->result = 0;
                        }
                        actor->nextSubstate(actor);
                    } else {
                        if (sprites->sprite != NULL) {
                            sprites->sprite->setAnim(sprites->sprite, STGTRAIN_state.getAnim(actor->set, actor->anim));
                        }
                        if (sprites->effect != NULL) {
                            sprites->effect->setAnim(sprites->effect, STGTRAIN_state.getAnim(8, actor->anim));
                        }
                        actor->result = -1;
                    }
                } else {
                    if (sprites->sprite != NULL) {
                        sprites->sprite->setPaused(sprites->sprite, 1);
                    }
                    if (sprites->effect != NULL) {
                        sprites->effect->setPaused(sprites->effect, 1);
                    }
                    actor->anim = 0;
                    actor->setSubstate(actor, 0);
                    actor->mode = 1;
                }
            }
            break;
        case 8:
            if (actor->substate == 0) {
                if (actor->result != 0) {
                    actor->anim = 4;
                } else {
                    actor->anim = 5;
                }
                if (sprites->sprite != NULL) {
                    anim = STGTRAIN_state.getAnim(actor->set, actor->anim);
                    if (anim != NULL) {
                        sprites->sprite->setAnim(sprites->sprite, anim);
                    } else {
                        actor->mode = 1;
                    }
                }
                if (sprites->effect != NULL) {
                    anim = STGTRAIN_state.getAnim(8, actor->anim);
                    if (anim != NULL) {
                        sprites->effect->setAnim(sprites->effect, anim);
                    } else {
                        actor->mode = 1;
                    }
                }
                actor->substate++;
            } else {
                if (sprites->effect != NULL) {
                    done = sprites->sprite->getFlags(sprites->sprite) & sprites->effect->getFlags(sprites->effect);
                } else {
                    done = sprites->sprite->getFlags(sprites->sprite);
                }
                if (done) {
                    if (sprites->sprite != NULL) {
                        sprites->sprite->setPaused(sprites->sprite, 1);
                    }
                    if (sprites->effect != NULL) {
                        sprites->effect->setPaused(sprites->effect, 1);
                    }
                    actor->anim = 0;
                    actor->setSubstate(actor, 0);
                    actor->mode = 1;
                }
            }
            break;
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Pauses the Digimon's sprite and effect */
void STGTRAIN_pauseActor(TrainActor *actor) {
    TrainActorSprites *sprites = actor->children;

    if (sprites->sprite != NULL) {
        sprites->sprite->setPaused(sprites->sprite, 1);
    }
    if (sprites->effect != NULL) {
        sprites->effect->setPaused(sprites->effect, 1);
    }
}

/* Plays the training on (mode 4), unpausing the sprite and effect */
void STGTRAIN_playActor(TrainActor *actor) {
    TrainActorSprites *sprites = actor->children;

    if (sprites->sprite != NULL) {
        sprites->sprite->setPaused(sprites->sprite, 0);
    }
    if (sprites->effect != NULL) {
        sprites->effect->setPaused(sprites->effect, 0);
    }
    actor->mode = 4;
}

/* Sets where the Digimon's images go in VRAM */
void STGTRAIN_setActorPos(TrainActor *actor, s32 x, s32 y) {
    actor->pos[0] = x;
    actor->pos[1] = y;
    actor->posSet = 1;
}

/* Sets where the Digimon's CLUTs go in VRAM */
void STGTRAIN_setActorClutPos(TrainActor *actor, s32 x, s32 y) {
    actor->pos[2] = x;
    actor->pos[3] = y;
    actor->clutSet = 1;
}

/* Sets the chance that the training works */
void STGTRAIN_setActorChance(TrainActor *actor, s32 chance) {
    actor->chance = chance;
}

/* Makes the Digimon grow from nothing (mode 2) */
void STGTRAIN_growActor(TrainActor *actor) {
    actor->scaleStep = 0x199;
    actor->scale = 0;
    actor->mode = 2;
}

/* Makes the Digimon shrink to nothing (mode 2) */
void STGTRAIN_shrinkActor(TrainActor *actor) {
    actor->scale = 0x1000;
    actor->scaleStep = -0x333;
    actor->mode = 2;
}

/* Scales the Digimon (0x1000 is its size) */
void STGTRAIN_setActorScale(TrainActor *actor, s32 scale) {
    actor->scaleChanged = 1;
    actor->scale = scale;
}

/* Whether the training worked, once it is done (mode bit 0), else -1 */
s32 STGTRAIN_getActorResult(TrainActor *actor) {
    if (actor->mode & 1) {
        return actor->result;
    }
    return -1;
}

/* Plays the training's end (mode 8) */
void STGTRAIN_endActor(TrainActor *actor) {
    actor->mode = 8;
    actor->substate = 0;
}

/* Creates an animated sprite of an image set */
TrainActor *STGTRAIN_createActor(s32 set, s32 file, s32 layerId, s32 depth) {
    TrainActor *actor = createTask(STGTRAIN_updateActor, sizeof(TrainActor), sizeof(TrainActorSprites));

    actor->setPos = STGTRAIN_setActorPos;
    actor->setClutPos = STGTRAIN_setActorClutPos;
    actor->setChance = STGTRAIN_setActorChance;
    actor->grow = STGTRAIN_growActor;
    actor->shrink = STGTRAIN_shrinkActor;
    actor->play = STGTRAIN_playActor;
    actor->pause = STGTRAIN_pauseActor;
    actor->setScale = STGTRAIN_setActorScale;
    actor->getResult = STGTRAIN_getActorResult;
    actor->set = set;
    actor->file = file;
    actor->layerId = layerId;
    actor->depth = depth;
    actor->end = STGTRAIN_endActor;
    return actor;
}

/* Creates the training menu's text windows */
void STGTRAIN_createMenuWindows(TrainMenu *menu, TextWindow **win) {
    win[0] = createTextWindow(menu->layerId, 1, 0xAE, 0x49);
    win[1] = createTextWindow(menu->layerId, 1, 0xA3, 0xA0);
    win[2] = createTextWindow(menu->layerId, 1, 0x74, 0xC0);
    win[3] = createTextWindow(menu->layerId, 1, 0x74, 0xCE);
}

/* Shows the name and description of the selected training (show) or hides them */
void STGTRAIN_showTrainingInfo(TrainMenu *menu, TextWindow **win, s32 show) {
    s32 entry;

    if (show != 0) {
        entry = menu->trainings[menu->page][menu->col + menu->row * 4];
        if (entry > 0) {
            win[2]->setString(win[2], FILE_CACHE.load(STGTRAIN_TEXT), STGTRAIN_state.trainings[entry].name);
            win[3]->setString(win[3], FILE_CACHE.load(STGTRAIN_TEXT), STGTRAIN_state.trainings[entry].desc);
            return;
        }
    }
    win[2]->setVisible(win[2], 0);
    win[3]->setVisible(win[3], 0);
}

/* Draws the training menu: its panels, the trainings of the page and the cursor */
void STGTRAIN_drawMenu(TrainMenu *menu) {
    SpriteDrawer sprite;
    s32 i;
    s32 entry;
    s32 x;
    s32 y;

    initSpriteDrawer(&sprite);
    sprite.setLayerId(menu->layerId, menu->depth);
    sprite.setTexture(0x240, 0x100);
    if (menu->panels[0].level != 0) {
        if (menu->panels[0].level != 0x1000) {
            sprite.setScale(menu->panels[0].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x4E);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x22, 0x92, 0x43);
    }
    if (menu->cursorShown != 0) {
        if (GFX.funcs.getTime() - menu->cursorTime >= 0xB) {
            menu->cursorTime = GFX.funcs.getTime();
            menu->cursorClut++;
            if (menu->cursorClut >= 4) {
                menu->cursorClut = 0;
            }
        }
        sprite.setClutRow(menu->cursorClut);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x1E, menu->col * 40 + 0x94, menu->row * 40 + 0x64);
        sprite.setClutRow(0);
    }
    if (menu->panels[2].level != 0) {
        if (GFX.funcs.getTime() - menu->iconTime >= 0x10) {
            menu->iconTime = GFX.funcs.getTime();
            menu->iconFrame++;
            if (menu->iconFrame >= 4) {
                menu->iconFrame = 0;
            }
        }
        if (menu->panels[2].level != 0x1000) {
            sprite.setScale(menu->panels[2].level, menu->panels[2].level, 0x1000);
        }
        for (i = 0; i < 8; i++) {
            entry = menu->trainings[menu->page][i];
            if (entry != 0) {
                x = (i % 4) * 40;
                y = (i / 4) * 40;
                if (menu->panels[2].level != 0x1000) {
                    sprite.setPivot(x + 0xA8, y + 0x76);
                }
                if (entry == -1) {
                    sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x5F, x + 0x94, y + 0x64);
                } else if (i == menu->col + menu->row * 4) {
                    sprite.setClutRow(0);
                    sprite.draw(FILE_CACHE.getEntry(STGTRAIN_FILE_SPRITES << 16),
                                STGTRAIN_state.trainings[entry].icons[menu->iconFrame], x + 0x94, y + 0x64);
                } else {
                    sprite.setClutRow(1);
                    sprite.draw(FILE_CACHE.getEntry(STGTRAIN_FILE_SPRITES << 16), STGTRAIN_state.trainings[entry].icons[0],
                                x + 0x94, y + 0x64);
                }
            }
        }
    }
    if (menu->arrowShown != 0) {
        if (GFX.funcs.getTime() - menu->arrowTime >= 0xB) {
            menu->arrowTime = GFX.funcs.getTime();
            menu->arrowClut++;
            if (menu->arrowClut >= 4) {
                menu->arrowClut = 0;
            }
        }
        sprite.setClutRow(menu->arrowClut);
        if (menu->page == 0) {
            sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x2C, 0xE4, 0xA0);
        } else {
            sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x2B, 0x94, 0xA0);
        }
    }
    sprite.setClutRow(0);
    if (menu->panels[1].level != 0) {
        sprite.setScale(menu->panels[1].level, 0x1000, 0x1000);
        if (menu->panels[1].level != 0x1000) {
            sprite.setPivot(0x140, 0x8A);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x24, 0x8F, 0x5F);
    }
    if (menu->panels[3].level != 0) {
        if (menu->panels[3].level != 0x1000) {
            sprite.setScale(menu->panels[3].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0xCD);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x23, 0x46, 0xBA);
    }
}

/*
 * Runs the training menu: opens its panels, moves the cursor over the
 * trainings of a page (L1 and R1 turn the pages when the gym has more than
 * five), and closes with a training picked (cross) or none (triangle).
 */
void STGTRAIN_runMenu(TrainMenu *menu, TextWindow **win) {
    s32 col;
    s32 row;

    switch (menu->substate) {
    case 0:
    default:
        STGTRAIN_state.startFade(&menu->panels[0], 1);
        menu->substate++;
        break;
    case 1:
        if (STGTRAIN_state.updateFade(&menu->panels[0])) {
            win[0]->setString(win[0], FILE_CACHE.load(STGTRAIN_TEXT), 7);
            STGTRAIN_state.startFade(&menu->panels[1], 1);
            menu->substate++;
        }
        break;
    case 2:
        if (STGTRAIN_state.updateFade(&menu->panels[1])) {
            STGTRAIN_state.startFade(&menu->panels[2], 1);
            menu->substate++;
        }
        break;
    case 3:
        if (STGTRAIN_state.updateFade(&menu->panels[2])) {
            if (STGTRAIN_state.tableCount >= 6) {
                menu->arrowShown = 1;
                if (menu->page == 0) {
                    win[1]->setString(win[1], FILE_CACHE.load(STGTRAIN_TEXT), 0x45);
                    win[1]->setPos(win[1], 0xE4, 0xA0);
                } else {
                    win[1]->setString(win[1], FILE_CACHE.load(STGTRAIN_TEXT), 0x44);
                    win[1]->setPos(win[1], 0xA3, 0xA0);
                }
            }
            STGTRAIN_state.startFade(&menu->panels[3], 1);
            menu->substate++;
        }
        break;
    case 4:
        if (STGTRAIN_state.updateFade(&menu->panels[3])) {
            STGTRAIN_showTrainingInfo(menu, win, 1);
            menu->cursorShown = 1;
            menu->substate = 10;
        }
        break;
    case 10:
        col = menu->page;
        if (STGTRAIN_state.tableCount >= 6) {
            if (!PAD_HELD(PAD_R1) && PAD_PRESSED(PAD_L1)) {
                menu->page = 0;
            } else if (!PAD_HELD(PAD_L1) && PAD_PRESSED(PAD_R1)) {
                menu->page = 1;
            }
        }
        if (col != menu->page) {
            SOUND.playSound(SOUND_MENU_MOVE);
            if (menu->page == 0) {
                win[1]->setString(win[1], FILE_CACHE.load(STGTRAIN_TEXT), 0x45);
                win[1]->setPos(win[1], 0xE4, 0xA0);
            } else {
                win[1]->setString(win[1], FILE_CACHE.load(STGTRAIN_TEXT), 0x44);
                win[1]->setPos(win[1], 0xA3, 0xA0);
            }
            for (col = 0; col < 8; col++) {
                if (menu->trainings[menu->page][col] > 0) {
                    menu->col = col % 4;
                    menu->row = col / 4;
                    break;
                }
            }
            STGTRAIN_showTrainingInfo(menu, win, 1);
            menu->iconFrame = 0;
            break;
        }
        col = menu->col;
        row = menu->row;
        if (PAD_PRESSED(PAD_LEFT) || PAD_REPEATED(PAD_LEFT)) {
            for (;;) {
                if (--menu->col < 0) {
                    menu->col = 0;
                    break;
                }
                if (menu->trainings[menu->page][menu->col + menu->row * 4] > 0) {
                    break;
                }
            }
        } else if (PAD_PRESSED(PAD_RIGHT) || PAD_REPEATED(PAD_RIGHT)) {
            for (;;) {
                if (++menu->col >= 4) {
                    menu->col = 3;
                    break;
                }
                if (menu->trainings[menu->page][menu->col + menu->row * 4] > 0) {
                    break;
                }
            }
        }
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            for (;;) {
                if (--menu->row < 0) {
                    menu->row = 0;
                    break;
                }
                if (menu->trainings[menu->page][menu->col + menu->row * 4] > 0) {
                    break;
                }
            }
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            for (;;) {
                if (++menu->row >= 2) {
                    menu->row = 1;
                    break;
                }
                if (menu->trainings[menu->page][menu->col + menu->row * 4] > 0) {
                    break;
                }
            }
        }
        if (col != menu->col || row != menu->row) {
            if (menu->trainings[menu->page][menu->col + menu->row * 4] > 0) {
                SOUND.playSound(SOUND_MENU_MOVE);
                STGTRAIN_showTrainingInfo(menu, win, 1);
            } else {
                menu->col = col;
                menu->row = row;
            }
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_MOVE);
            menu->screen->unk78 = menu->trainings[menu->page][menu->col + menu->row * 4];
            if (menu->screen->unk78 > 0) {
                menu->substate = 0x32;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            menu->substate = 0x32;
            menu->step = 1;
        }
        break;
    case 0x32:
        menu->cursorShown = 0;
        menu->arrowShown = 0;
        win[1]->setVisible(win[1], 0);
        STGTRAIN_state.startFade(&menu->panels[2], 0);
        menu->substate++;
        break;
    case 0x33:
        if (STGTRAIN_state.updateFade(&menu->panels[2])) {
            STGTRAIN_showTrainingInfo(menu, win, 0);
            win[0]->setVisible(win[0], 0);
            STGTRAIN_state.startFade(&menu->panels[0], 0);
            STGTRAIN_state.startFade(&menu->panels[1], 0);
            STGTRAIN_state.startFade(&menu->panels[3], 0);
            menu->substate++;
        }
        break;
    case 0x34:
        STGTRAIN_state.updateFade(&menu->panels[0]);
        STGTRAIN_state.updateFade(&menu->panels[1]);
        if (STGTRAIN_state.updateFade(&menu->panels[3])) {
            if (menu->step != 0) {
                menu->setState(menu, TASK_DONE);
            } else {
                menu->state = TASK_KILL;
            }
        }
        break;
    }
}

/*
 * The training menu's task: a grid of trainings on two pages, filled from
 * the gym's table (the trainings it has), with the cursor on the last one.
 */
void STGTRAIN_updateMenu(TrainMenu *menu, TextWindow **win) {
    s32 *table;
    s32 i;
    s32 page;
    s32 row;
    s32 col;

    switch (menu->state) {
    case TASK_INIT:
    default:
        menu->nextState(menu);
        STGTRAIN_createMenuWindows(menu, win);
        menu->panels[0].duration = 10;
        menu->panels[1].duration = 10;
        menu->panels[2].duration = 10;
        menu->panels[3].duration = 10;
        table = STGTRAIN_state.getTable(GAME.funcs.getModeArg());
        for (row = 0; row < 2; row++) {
            for (col = 0; col < 3; col++) {
                if (row == 1 && col == 2) {
                    break;
                }
                menu->trainings[0][col + row * 4] = -1;
            }
        }
        for (row = 0; row < 2; row++) {
            for (col = 0; col < 4; col++) {
                if (row != 1 || col != 0) {
                    menu->trainings[1][col + row * 4] = -1;
                }
            }
        }
        for (i = 0; i < 16; i++) {
            switch (table[i * 2]) {
            case 1:
            case 13:
                menu->trainings[0][0] = table[i * 2];
                break;
            case 2:
            case 14:
                menu->trainings[0][1] = table[i * 2];
                break;
            case 3:
            case 15:
                menu->trainings[0][2] = table[i * 2];
                break;
            case 4:
            case 16:
                menu->trainings[0][4] = table[i * 2];
                break;
            case 5:
            case 17:
                menu->trainings[0][5] = table[i * 2];
                break;
            case 6:
            case 18:
                menu->trainings[1][0] = table[i * 2];
                break;
            case 7:
            case 19:
                menu->trainings[1][1] = table[i * 2];
                break;
            case 8:
            case 20:
                menu->trainings[1][2] = table[i * 2];
                break;
            case 9:
            case 21:
                menu->trainings[1][3] = table[i * 2];
                break;
            case 10:
            case 22:
                menu->trainings[1][5] = table[i * 2];
                break;
            case 11:
            case 23:
                menu->trainings[1][6] = table[i * 2];
                break;
            case 12:
            case 24:
                menu->trainings[1][7] = table[i * 2];
                break;
            }
        }
        if (menu->screen->unk78 > 0) {
            for (page = 0; page < 2; page++) {
                for (row = 0; row < 2; row++) {
                    for (col = 0; col < 4; col++) {
                        if (menu->trainings[page][col + row * 4] == menu->screen->unk78) {
                            menu->page = page;
                            menu->col = col;
                            menu->row = row;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case TASK_RUN:
        STGTRAIN_runMenu(menu, win);
        STGTRAIN_drawMenu(menu);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Opens the training menu (its substate 0) */
void STGTRAIN_openMenu(TrainMenu *menu) {
    menu->state = TASK_RUN;
    menu->substate = 0;
}

/* Closes the training menu (its substate 0x32) */
void STGTRAIN_closeMenu(TrainMenu *menu) {
    menu->state = TASK_RUN;
    menu->substate = 0x32;
}

/* Shows the selected training's name and description */
void STGTRAIN_showMenuInfo(TrainMenu *menu) {
    STGTRAIN_showTrainingInfo(menu, menu->children, 1);
}

/* Creates the training menu */
TrainMenu *STGTRAIN_createMenu(TrainScreen *screen) {
    TrainMenu *menu = createTask(STGTRAIN_updateMenu, sizeof(TrainMenu), 0x10);

    menu->open = STGTRAIN_openMenu;
    menu->close = STGTRAIN_closeMenu;
    menu->showInfo = STGTRAIN_showMenuInfo;
    menu->layerId = 0x1000;
    menu->depth = 6;
    menu->screen = screen;
    return menu;
}

/* Loads the overlay's TIM archive into VRAM */
void STGTRAIN_loadImages(void) {
    TimLoader loader;

    initTimLoader(&loader);
    loader.setImagePos(0x240, 0x100);
    loader.loadArchive(FILE_CACHE.getEntry(STGTRAIN_FILE_IMAGES << 16));
}

/* Starts opening (fadeIn) or closing a panel, with its sound; closing is
   twice as fast */
void STGTRAIN_startFade(PanelAnim *fade, s32 fadeIn) {
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

/* Moves a panel's opening or closing on: 1 once it is done */
s32 STGTRAIN_updateFade(PanelAnim *fade) {
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

/* Starts moving a value from from to to over frames */
void STGTRAIN_startLerp(MenuLerp *lerp, s32 from, s32 to, s32 frames) {
    if (from != to) {
        lerp->duration = frames;
        lerp->fixed = from << 8;
        lerp->value = from;
        lerp->target = to;
        lerp->active = 1;
        lerp->step = ((to - from) << 8) / lerp->duration;
    }
}

/* Moves the value on: 1 once it reaches the target */
s32 STGTRAIN_updateLerp(MenuLerp *lerp) {
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

/* Starts loading a file of STGTRAIN_files, unless it is the one loaded */
s32 STGTRAIN_requestFile(s32 index) {
    if (index < 0) {
        return 0;
    }
    if (index != STGTRAIN_state.fileIndex) {
        HEAP.zero(&STGTRAIN_state.data, 0x2D8);
        STGTRAIN_state.fileIndex = index;
        FILE_CACHE.request(STGTRAIN_files[index].file);
        STGTRAIN_state.data = NULL;
    }
    return 1;
}

/* The requested file, or NULL while it loads */
u8 *STGTRAIN_getFile(void) {
    if (FILE_CACHE.isLoading(STGTRAIN_files[STGTRAIN_state.fileIndex].file) == 0) {
        STGTRAIN_state.data = FILE_CACHE.load(STGTRAIN_files[STGTRAIN_state.fileIndex].file);
    }
    return STGTRAIN_state.data;
}

/* Frees the loaded file of STGTRAIN_files */
void STGTRAIN_freeFile(void) {
    if (STGTRAIN_state.fileIndex != -1) {
        FILE_CACHE.free(STGTRAIN_files[STGTRAIN_state.fileIndex].file);
    }
}

/* The set's sprite bank, and the two values after its offsets */
s32 STGTRAIN_readSetBank(TrainSetHeader *header, s32 set) {
    STGTRAIN_bankCursor.set = header;
    STGTRAIN_state.sets[set].bank = (TrainSpriteBank *)(STGTRAIN_state.data + header->bank);
    STGTRAIN_bankCursor.w += *STGTRAIN_bankCursor.w + 1;
    STGTRAIN_state.sets[set].bankOffset = *STGTRAIN_bankCursor.w++;
    STGTRAIN_state.sets[set].unkC = *STGTRAIN_bankCursor.w;
    return 1;
}

/* The set's animations */
s32 STGTRAIN_readSetAnims(TrainSetHeader *header, s32 set) {
    s32 i;

    STGTRAIN_animCursor.set = header;
    for (i = 0; i < 6; i++) {
        if (STGTRAIN_animCursor.set->anims[i] != 0) {
            STGTRAIN_state.sets[set].anims[i] = (TrainAnim *)(STGTRAIN_state.data + STGTRAIN_animCursor.set->anims[i]);
        } else {
            STGTRAIN_state.sets[set].anims[i] = NULL;
        }
    }
    return 1;
}

/* The images of a set: the rest of its offsets */
s32 STGTRAIN_readSetImages(TrainSetHeader *header, s32 set) {
    s32 i;

    STGTRAIN_imageCursor.set = header;
    STGTRAIN_state.sets[set].imageCount = header->count - 7;
    for (i = 0; i < STGTRAIN_state.sets[set].imageCount; i++) {
        STGTRAIN_state.sets[set].images[i] = STGTRAIN_state.data + STGTRAIN_imageCursor.set->images[i];
    }
    return 1;
}

/* Reads an image set of the loaded file */
s32 STGTRAIN_readSet(s32 set) {
    if (STGTRAIN_state.data != NULL && set < 9) {
        STGTRAIN_state.sets[set].id = set;
        STGTRAIN_setCursor.w = (s32 *)(STGTRAIN_state.data + set * 4);
        STGTRAIN_setCursor.w = (s32 *)(STGTRAIN_state.data + *STGTRAIN_setCursor.w);
        if (STGTRAIN_setCursor.set->count == 0) {
            return 0;
        }
        if (STGTRAIN_readSetBank(STGTRAIN_setCursor.set, set) == 0) {
            return 0;
        }
        if (STGTRAIN_readSetAnims(STGTRAIN_setCursor.set, set) != 0) {
            return STGTRAIN_readSetImages(STGTRAIN_setCursor.set, set) != 0;
        }
    }
    return 0;
}

/* Loads the images of a set into VRAM side by side, unpacking the
   run-length encoded ones ("RLEN") first */
s32 STGTRAIN_loadSet(s32 set, s32 *pos) {
    TimLoader loader;
    s32 x;
    s32 y;
    s32 clutX;
    s32 clutY;
    u8 *buf;
    u8 *src;
    u8 *image;
    s32 i;
    s32 j;
    s32 n;
    u8 c;
    s32 magic;

    if (set != STGTRAIN_state.sets[set].id) {
        return 0;
    }
    x = pos[0];
    y = pos[1];
    clutX = pos[2];
    clutY = pos[3];
    initTimLoader(&loader);
    STGTRAIN_state.sets[set].imageY = y;
    buf = HEAP.alloc(0xA800, 2);
    for (i = 0; i < STGTRAIN_state.sets[set].imageCount; i++) {
        STGTRAIN_state.sets[set].imageX[i] = x + i * 0x40;
        loader.setImagePos(x + i * 0x40, y);
        src = STGTRAIN_state.sets[set].images[i];
        /* the match depends on the magic read before image is set: with
           the copy right after the load, cse puts the load in image */
        magic = *(s32 *)src;
        image = src;
        if (magic == 0x4E454C52) {
            /* and on image set before src moves on, or src + 8 is taken
               from image */
            image = buf;
            src += 8;
            while ((c = *src) != 0) {
                if (c & 0x80) {
                    n = c & 0x7F;
                    src++;
                    for (j = 0; j < n; j++) {
                        *image++ = *src;
                    }
                    src++;
                } else {
                    n = *src++;
                    for (j = 0; j < n; j++) {
                        *image++ = *src++;
                    }
                }
            }
            image = buf;
        }
        loader.setClutPos(clutX + *(s16 *)(image + 0xC), clutY);
        loader.load(image);
    }
    HEAP.free(buf);
    return 1;
}

/* The file of an entry of STGTRAIN_files */
s32 STGTRAIN_getFileId(s32 index) {
    return STGTRAIN_files[index].file;
}

/* Where the image of an entry of STGTRAIN_files goes (y << 16 | x) */
s32 STGTRAIN_getFilePos(s32 index) {
    return STGTRAIN_files[index].y << 16 | STGTRAIN_files[index].x;
}

/* An entry of STGTRAIN_files's unkC */
s32 STGTRAIN_getFileUnkC(s32 index) {
    return STGTRAIN_files[index].unkC;
}

/* The sprite bank of an image set */
TrainSpriteBank *STGTRAIN_getBank(s32 set) {
    return STGTRAIN_state.sets[set].bank;
}

/* Where an image set's sprites start in its bank */
s32 STGTRAIN_getBankOffset(s32 set) {
    return STGTRAIN_state.sets[set].bankOffset;
}

/* An image set's unkC */
s32 STGTRAIN_getSetUnkC(s32 set) {
    return STGTRAIN_state.sets[set].unkC;
}

/* An animation of an image set */
TrainAnim *STGTRAIN_getAnim(s32 set, s32 i) {
    return STGTRAIN_state.sets[set].anims[i];
}

/* The trainings of a gym level, counting them */
s32 *STGTRAIN_getGymTrainings(s32 index) {
    s32 i;

    if (index < 1 || index > 14) {
        index = 0;
    }
    STGTRAIN_state.tableCount = 0;
    for (i = 0; i < 16; i++) {
        if (STGTRAIN_gymTrainings[index][i][0] != 0) {
            STGTRAIN_state.tableCount++;
        }
    }
    return STGTRAIN_gymTrainings[index][0];
}

/* A training of a gym level, by its id */
s32 *STGTRAIN_findGymTraining(s32 index, s32 id) {
    s32 i;

    if (index < 1 || index > 14) {
        index = 0;
    }
    for (i = 0; i < 16; i++) {
        if (STGTRAIN_gymTrainings[index][i][0] == id) {
            return STGTRAIN_gymTrainings[index][i];
        }
    }
    return NULL;
}

/* The data: the rest of the overlay's, with the state all three objects
   share */
/* the points each intensity of a training costs */
s32 STGTRAIN_intensityCosts[] = {
    1, 5, 10,
};
/* The trainings of each gym level, by STGTRAIN_findGymTraining: {id, ?}, 0 ends */
s32 STGTRAIN_gymTrainings[14][16][2] = {
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {0, 0}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {12, 0x3000E}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {19, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {22, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {22, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {21, 0x1000B},
        {10, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {10, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {8, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {24, 0x3000E}, {0, 0},
    },
};
/* The trainings: their name and description in the text file, and the
   frames of their icon */
TrainInfo STGTRAIN_trainings[] = {
    {0, 0, {0, 0, 0, 0}},
    {19, 43, {0, 1, 2, 3}},
    {20, 44, {4, 5, 6, 7}},
    {21, 45, {8, 9, 10, 11}},
    {22, 46, {12, 13, 14, 15}},
    {23, 47, {16, 17, 18, 19}},
    {29, 53, {20, 21, 22, 23}},
    {30, 54, {24, 25, 26, 27}},
    {31, 55, {28, 29, 30, 31}},
    {32, 56, {32, 33, 34, 35}},
    {33, 57, {36, 37, 38, 39}},
    {34, 58, {40, 41, 42, 43}},
    {35, 59, {95, 96, 97, 98}},
    {24, 48, {45, 46, 47, 48}},
    {25, 49, {49, 50, 51, 52}},
    {26, 50, {53, 54, 55, 56}},
    {27, 51, {57, 58, 59, 60}},
    {28, 52, {61, 62, 63, 64}},
    {36, 60, {65, 66, 67, 68}},
    {37, 61, {71, 72, 73, 74}},
    {38, 62, {75, 76, 77, 78}},
    {39, 63, {79, 80, 81, 82}},
    {40, 64, {83, 84, 85, 86}},
    {41, 65, {87, 88, 89, 90}},
    {42, 66, {91, 92, 93, 94}},
};
/* the discs number their files differently */
#if VERSION_US
TrainFile STGTRAIN_files[] = {
    {591, 82, 31, 0},
    {591, 82, 31, 0},
    {1070, 79, 31, 0},
    {625, 78, 27, 0},
    {626, 79, 24, 1},
    {627, 79, 31, 0},
    {628, 79, 31, 0},
    {755, 79, 31, 0},
    {756, 81, 31, 1},
    {1071, 79, 31, 0},
    {629, 47, 35, 1},
    {630, 79, 31, 0},
    {757, 79, 31, 1},
    {591, 82, 31, 0},
    {1070, 79, 31, 0},
    {625, 78, 27, 0},
    {626, 79, 24, 1},
    {627, 79, 31, 0},
    {628, 79, 31, 0},
    {755, 79, 31, 0},
    {756, 81, 31, 1},
    {1071, 79, 31, 0},
    {629, 47, 35, 1},
    {630, 79, 31, 0},
    {757, 79, 31, 1},
};
#elif VERSION_EU
TrainFile STGTRAIN_files[] = {
    {606, 82, 31, 0},
    {606, 82, 31, 0},
    {1086, 79, 31, 0},
    {640, 78, 27, 0},
    {641, 79, 24, 1},
    {642, 79, 31, 0},
    {643, 79, 31, 0},
    {770, 79, 31, 0},
    {771, 81, 31, 1},
    {1087, 79, 31, 0},
    {644, 47, 35, 1},
    {645, 79, 31, 0},
    {772, 79, 31, 1},
    {606, 82, 31, 0},
    {1086, 79, 31, 0},
    {640, 78, 27, 0},
    {641, 79, 24, 1},
    {642, 79, 31, 0},
    {643, 79, 31, 0},
    {770, 79, 31, 0},
    {771, 81, 31, 1},
    {1087, 79, 31, 0},
    {644, 47, 35, 1},
    {645, 79, 31, 0},
    {772, 79, 31, 1},
};
#endif
TrainState STGTRAIN_state = {
    0, NULL, 0, {{0}}, STGTRAIN_trainings,
    STGTRAIN_loadImages, STGTRAIN_startFade, STGTRAIN_updateFade, STGTRAIN_startLerp,
    STGTRAIN_updateLerp, STGTRAIN_requestFile, STGTRAIN_getFile, STGTRAIN_freeFile,
    STGTRAIN_readSet, STGTRAIN_loadSet, STGTRAIN_getFileId, STGTRAIN_getFilePos,
    STGTRAIN_getFileUnkC, STGTRAIN_getBank, STGTRAIN_getBankOffset, STGTRAIN_getSetUnkC,
    STGTRAIN_getAnim, STGTRAIN_getGymTrainings, STGTRAIN_findGymTraining,
};
TrainCursor STGTRAIN_bankCursor = {NULL};
TrainCursor STGTRAIN_animCursor = {NULL};
TrainCursor STGTRAIN_imageCursor = {NULL};
TrainCursor STGTRAIN_setCursor = {NULL};
