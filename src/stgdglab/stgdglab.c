/* STGDGLAB's scene: the mode's root task, and the screen fade */

#include "stgdglab.h"

/* The mode's scene task: sets up the display and a black layer, then creates the
   mode's main task (STGDGLAB_createLab) */
void STGDGLAB_updateScene(Task *task, Task **children) {
    RECT rect;
    Layer *layer;

    switch (task->state) {
    case TASK_INIT:
    default:
        GFX.funcs.reset();
        GFX.funcs.allocPrimBuffers(0xF000);
        GFX.funcs.setDisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
        rect.x = 0;
        rect.y = 0;
        rect.w = 0x140;
        rect.h = 0xF0;
        layer = GFX.funcs.createLayer(&rect, 3, SCREEN_LAYER);
        layer->setBgColor(layer, 0, 0, 0);
        children[0] = (Task *)STGDGLAB_createLab();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* Starts the mode: creates its scene task */
Task *STGDGLAB_createScene(void) {
    return createTask(STGDGLAB_updateScene, sizeof(Task), 4);
}

#include "../menu_common/start_fader.inc.c"
#include "../menu_common/draw_fader.inc.c"
#include "../menu_common/update_fader.inc.c"
#define FADER_DEPTH 6
#include "../menu_common/create_fader.inc.c"
