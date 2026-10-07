/* STCRDDEK's scene: the mode's root task, and the screen fade */

#include "stcrddek.h"

/* The mode's root task: sets up the 320x240 display and its black layer, then
   creates the deck screen */
void STCRDDEK_updateScene(Task *task, Task **children) {
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
        children[0] = (Task *)STCRDDEK_createScreen();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* The mode's entry point (MODE_ENTRY_POINTS): starts the root task */
Task *STCRDDEK_start(void) {
    return createTask(STCRDDEK_updateScene, sizeof(Task), 4);
}

#include "../menu_common/start_fader.inc.c"
#include "../menu_common/draw_fader.inc.c"
#include "../menu_common/update_fader.inc.c"
#define FADER_DEPTH 0
#include "../menu_common/create_fader.inc.c"
