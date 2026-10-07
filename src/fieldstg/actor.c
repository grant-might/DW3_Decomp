/* The actor task: the player, its partners and the other characters */

#include "fieldstg.h"

/* Makes the partners stop following: each walks out the rest of its trail
   (FIELDSTG_drainTrail) */
void FIELDSTG_haltPartners(void) {
    s32 i;
    Actor *actor;

    for (i = 0; i < 3; i++) {
        actor = TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, -1, FIELDSTG_haltedPartners[i]);
        if (actor != NULL) {
            actor->control = FIELDSTG_drainTrail;
        }
    }
}

/* Makes the partners follow the player again (FIELDSTG_followLeader) */
void FIELDSTG_resumePartners(void) {
    s32 i;
    Actor *actor;

    for (i = 0; i < 3; i++) {
        actor = TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, -1, FIELDSTG_followingPartners[i]);
        if (actor != NULL) {
            actor->control = FIELDSTG_followLeader;
        }
    }
}

/* The tile in front of an actor, one step in its direction */
void FIELDSTG_getFacingTile(Actor *actor, Point *out) {
    Point *delta = &FIELDSTG_dirSteps[actor->dir];

    out->x = actor->tile.x + delta->x;
    out->y = actor->tile.y + delta->y;
}

/* An actor's update: waits for its animation file (and gives the player its
   icon), then runs its control and its action, moves its tile and draws it
   sorted by y; in TASK_KILL, frees its trail */
void FIELDSTG_updateActor(Actor *actor, ActorChildren *children) {
    Layer *layer;

    switch (actor->state) {
        default:
        case TASK_INIT:
            if (actor->animFile == 0 || FILE_CACHE.isLoading(actor->animFile >> 16) == 0) {
                if (actor->key2 == 0) {
                    children->icon = FIELDSTG_createActorIcon(actor);
                }
                actor->nextState(actor);
            }
            break;
        case TASK_RUN:
            if ((actor->key2 & 0xE) || FIELDSTG_state.bannerShown == 0) {
                if (actor->control != NULL) {
                    actor->control(actor);
                }
            }
            FIELDSTG_runActorAction(actor, children);
            actor->tile.x = actor->pos.x >> 8;
            actor->tile.y = (actor->pos.y - actor->climbHeight) >> 8;
            if (actor->animFile != 0) {
                FIELDSTG_animateActor(actor);
                if (actor->tile.x + actor->tile.y != 0) {
                    layer = GFX.funcs.getLayer(FIELD_LAYER_MAP);
                    layer->addSortedCallback(layer, FIELDSTG_drawActor, actor, actor->tile.y, 0);
                }
            }
            break;
        case TASK_DONE:
            break;
        case TASK_KILL:
            GAME.flightZ = actor->z;
            if (actor->voice != -1) {
                SOUND.keyOff(SOUND_SUB_MOVE, actor->voice);
            }
            if (actor->trail != NULL) {
                HEAP.free(actor->trail);
            }
            break;
    }
}

/*
 * Creates a character (FIELD_TASK_ACTOR): key1 is the character, key2 its
 * kind (0 the player, 2 to 8 a follower, the others the map's characters).
 *
 * The match depends on kind holding getModeArg's result in the player's
 * branch, where kind is no longer needed: its second set keeps local-alloc
 * from doubling its live length, which puts it before the constant 1 in the
 * global allocator (the European version matches either way).
 */
Actor *FIELDSTG_createActor(s32 key1, s32 kind, s32 image, FieldActorEntry *entry) {
    Actor *actor = createTaskWithId(FIELDSTG_updateActor, sizeof(Actor), 0x10, FIELD_TASK_ACTOR);
    s32 isLarge;

    actor->walkInDir = FIELDSTG_walkActorInDir;
    actor->climbUp = FIELDSTG_startClimbUp;
    actor->climbDown = FIELDSTG_startClimbDown;
    actor->dropDown = FIELDSTG_startDrop;
    actor->playGauge = FIELDSTG_startActorGauge;
    actor->warp = FIELDSTG_warpActor;
    actor->startWalk = FIELDSTG_startActorWalk;
    actor->startSlide = FIELDSTG_startActorSlide;
    actor->stopSlide = FIELDSTG_stopActorSlide;
    actor->launch = FIELDSTG_launchActor;
    actor->resetControl = FIELDSTG_resetActorControl;
    actor->setDir = FIELDSTG_setActorDir;
    actor->isAnimDone = FIELDSTG_isActorAnimDone;
    actor->isWalking = FIELDSTG_isActorWalking;
    actor->setGoal = FIELDSTG_setActorGoal;
    actor->setAnim = FIELDSTG_setActorAnim;
    actor->setPose = FIELDSTG_setActorPose;
    actor->key1 = key1;
    actor->key2 = kind;
    actor->getFacingTile = FIELDSTG_getFacingTile;
    actor->animFile = FIELDSTG_state.getFileEntry(key1);
    actor->halfWidth = FIELDSTG_state.getActorWidth(key1) >> 1;
    actor->animSet = ACTOR_ANIM_STAND;
    actor->dir = 1;
    actor->image = &FIELDSTG_state.images.actors[image + 2];
    actor->fieldImage = FIELDSTG_state.images.field;
    FILE_CACHE.request(actor->animFile >> 16);
#if VERSION_EU
    if (NTSC_MODE) {
        actor->speed = 0x400;
    } else {
        actor->speed = 0x4CC;
    }
#else
    actor->speed = 0x400;
#endif
    if (key1 == 0x146) {
        actor->speed /= 2;
    }
    actor->voice = -1;
    actor->depth = 4;
    if (kind == 0) {
        if (key1 == 0x147) {
            actor->control = FIELDSTG_controlFlight;
            if (GAME.clearTempFlags) {
                actor->z = 0x3000;
            } else {
                actor->z = GAME.flightZ;
            }
            actor->flying = 1;
        } else {
            actor->control = FIELDSTG_controlPlayer;
        }
        kind = GAME.funcs.getModeArg();
        if (kind != -1) {
            actor->pos = FIELDSTG_state.start;
            actor->dir = FIELDSTG_state.startDir;
        } else {
            actor->pos = FIELDSTG_state.defaultStart;
            actor->dir = FIELDSTG_state.defaultStartDir;
        }
        actor->tile.x = actor->pos.x >> 8;
        actor->tile.y = actor->pos.y >> 8;
        if (GAME.clearTempFlags) {
            actor->depth = 4;
            GAME.playerDepth = 4;
        } else {
            actor->depth = GAME.playerDepth;
        }
    } else if (kind & 0xE) {
        actor->trail = HEAP.allocZeroed(sizeof(Trail), 2);
        actor->control = FIELDSTG_followLeader;
        if (kind == 2) {
            actor->trail->tail = 0x37;
        } else if (kind == 4) {
            actor->trail->tail = 0x2E;
        } else {
            actor->trail->tail = 0x25;
        }
        if (GAME.clearTempFlags) {
            actor->depth = 4;
            GAME.playerDepth = 4;
        } else {
            actor->depth = GAME.playerDepth;
        }
    } else {
        isLarge = key1 == 0x28;
        if (key1 == 0x29) {
            isLarge = 1;
        }
        if (key1 == 0x2A) {
            isLarge = 1;
        }
        if (key1 == 0x3E) {
            isLarge = 1;
        }
        if (key1 == 0x11A) {
            isLarge = 1;
        }
        actor->isLarge = isLarge;
        actor->hasShadow = 1;
        if (key1 == 0x82) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x83) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x11F) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x13C) {
            actor->hasShadow = 0;
        }
        if (key1 == 0x13F) {
            actor->hasShadow = 0;
        }
        if (key1 == 0xD5) {
            actor->hasShadow = 0;
        }
        actor->entry = entry;
    }
    return actor;
}
