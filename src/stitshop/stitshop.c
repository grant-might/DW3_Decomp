/* STITSHOP's scene: the mode's root task, and the screen fade */

#include "stitshop.h"

/* The mode's root task: sets up the 320x240 display and its black layer, then
   creates the item shop */
void STITSHOP_updateScene(Task *task, Task **children) {
    RECT rect;
    Layer *layer;

    switch (task->state) {
    case TASK_INIT:
    default:
        GFX.funcs.reset();
        GFX.funcs.allocPrimBuffers(0x14000);
        GFX.funcs.setDisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
        rect.x = 0;
        rect.y = 0;
        rect.w = 0x140;
        rect.h = 0xF0;
        layer = GFX.funcs.createLayer(&rect, 3, SCREEN_LAYER);
        layer->setBgColor(layer, 0, 0, 0);
        children[0] = (Task *)STITSHOP_createShop();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* The mode's entry point (MODE_ENTRY_POINTS): starts the root task */
Task *STITSHOP_start(void) {
    return createTask(STITSHOP_updateScene, sizeof(Task), 4);
}

#include "../menu_common/start_fader.inc.c"
#include "../menu_common/draw_fader.inc.c"
#include "../menu_common/update_fader.inc.c"
#define FADER_DEPTH 6
#include "../menu_common/create_fader.inc.c"
