#include "game.h"
#include <libgs.h>
#include <libetc.h>
#include <libsnd.h>

/* -G8 unit: small variables defined here are reached through $gp */
static RECT BOOT_IMAGE_RECT;
static void *ROOT_TASK;

/* Starts the hardware, the libraries and the engine, then runs a frame per iteration */
int main(void) {
    RECT rect;
    GsIMAGE tim;
    u_char param[8];

#if VERSION_US
    SetVideoMode(MODE_NTSC);
#elif VERSION_EU
    if (NTSC_MODE) {
        SetVideoMode(MODE_NTSC);
    } else {
        SetVideoMode(MODE_PAL);
    }
#endif
    ResetCallback();
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    GFX.funcs.reset();
    GFX.funcs.startVSync();
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x280;
    rect.h = 0x1FF;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, 1, 1, 0);
    GsInit3D();
    SsInit();
    InitGeom();
    GFX.funcs.setDisplayMode(320, 640, 1, 0);
    PutDispEnv(&GFX.disp[0]);
    VSync(0);
    GsGetTimInfo((u_long *)SUB_OVERLAY_ADDRESS + 1, &tim);
    VSync(0);
    LoadImage(&BOOT_IMAGE_RECT, tim.pixel);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    CdInit();
    CdSetDebug(0);
    SetGraphDebug(0);
    param[0] = CdlModeSpeed;
    while (CdControl(CdlSetmode, param, 0) == 0) {
    }
    VSync(3);
    CdControlB(CdlPause, 0, 0);
    HEAP.init();
    SOUND.init();
    RANDOM.seed(0);
    MEMCARD_FUNCS.init();
    PAD.init(0, 0x12);
    GAME.funcs.newGame();
    FONT.load();
    /*
     * One frame per iteration: when the mode task has died (a new mode was
     * requested), free everything the mode allocated and start the new one.
     */
    for (;;) {
        if (ROOT_TASK == NULL) {
            GFX.funcs.freePrimBuffers();
            GFX.funcs.reset();
            TASK_REGISTRY.funcs.clear();
            HEAP.freeByTag(MEM_MODE);
            GAME.funcs.commitMode();
            ROOT_TASK = createModeTask();
        }
        ROOT_TASK = TASK_REGISTRY.funcs.run(ROOT_TASK);
        GFX.funcs.drawFrame(ROOT_TASK);
        PAD.update();
        RANDOM.next();
        FILE_CACHE.update();
        SOUND.updateLoading();
    }
}

/* Where the modes' overlays (AAA/PRO/*.PRO) load, after the executable, and
 * the stages and other sub-overlays, after CARDGAME. */
void *const OVERLAY_ADDRESS = OVERLAY_VRAM;
void *const SUB_OVERLAY_ADDRESS = STAGE_VRAM;
