/* The helpers of the stages' scripts and the script commands' table */

#include "fieldstg.h"

/* Stops the scripts' timer */
void FIELDSTG_resetScriptTimer(void) {
    HEAP.zero(&FIELDSTG_scriptTimer, 8);
}

/* The actor of a character (Actor.key1), or NULL */
Actor *FIELDSTG_findActor(s32 character) {
    return TASK_REGISTRY.funcs.find(FIELD_TASK_ACTOR, character, -1);
}

/* A script's wait: counts time down, then moves the script on */
void FIELDSTG_waitScriptTime(s32 time, s32 *pc) {
    if (time != 0 && FIELDSTG_scriptTimer.active == 0) {
        FIELDSTG_scriptTimer.active = 1;
        FIELDSTG_scriptTimer.time = time;
    }
    FIELDSTG_scriptTimer.time -= GFX.funcs.getFrameTime();
    if (FIELDSTG_scriptTimer.time <= 0) {
        FIELDSTG_scriptTimer.time = 0;
        FIELDSTG_scriptTimer.active = 0;
        (*pc)++;
    }
}

/* A script's wait for the animation of the actor id to end */
void FIELDSTG_waitAnimDone(s32 id, s32 *pc) {
    Actor *actor = FIELDSTG_findActor(id);

    if (actor->isAnimDone(actor) != 0) {
        (*pc)++;
    }
}

/* A script's wait for the actor id to reach its goal */
void FIELDSTG_waitWalkDone(s32 id, s32 *pc) {
    Actor *actor = FIELDSTG_findActor(id);

    if (actor->isWalking(actor) == 0) {
        (*pc)++;
    }
}

/* Turns a map position into a screen one */
void FIELDSTG_toScreenPos(Point *pos) {
    Point scroll;
    Layer *layer = GFX.funcs.getLayer(FIELD_LAYER_MAP);

    layer->getScroll(layer, &scroll);
    pos->x -= scroll.x;
    pos->y -= scroll.y;
}

/* A script helper: clears the script flag of character 1, or else of
   character 2 */
void FIELDSTG_clearScriptFlag(void) {
    Actor *actor = FIELDSTG_findActor(1);

    if (actor == NULL) {
        actor = FIELDSTG_findActor(2);
    }
    actor->scriptFlag = 0;
}

/* The script command id of FIELDSTG_scriptCommands, or NULL */
ScriptCommand *FIELDSTG_findScriptCommand(s32 id) {
    ScriptCommand *cmd;

    for (cmd = FIELDSTG_scriptCommands; cmd->id != 0; cmd++) {
        if (cmd->id == id) {
            return cmd;
        }
    }
    return NULL;
}

/* Creates the task of script command id, or returns 0 */
s32 FIELDSTG_createScriptCommand(s32 id) {
    ScriptCommand *cmd = FIELDSTG_findScriptCommand(id);
    s32 ret = 0;

    if (cmd != NULL) {
        ret = cmd->create(id);
    }
    return ret;
}

/* Hands a script command's task the command id's two arguments */
void FIELDSTG_handleScriptCommand(s32 arg0, s32 id, s32 arg2, s32 arg3) {
    ScriptCommand *cmd = FIELDSTG_findScriptCommand(id);

    if (cmd != NULL && cmd->handle != NULL) {
        cmd->handle(arg0, arg2, arg3);
    }
}
