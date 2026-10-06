#ifndef DW3_OVERLAY_H
#define DW3_OVERLAY_H

/* The game modes' overlays and the task that runs them (overlay.c) */

#include "common.h"
#include "dw3/task.h"

/* Loads the overlay of the current mode (OVERLAY_LOADER) */
typedef struct OverlayLoader {
    /* 0x0 */ s32 mode; /* whose overlay is loaded */
    /* 0x4 */ s32 subOverlay;
    /* 0x8 */ void (*loadModeOverlay)(void);
    /* 0xC */ void (*loadSubOverlay)(s32 file);
} OverlayLoader;

void *createModeTask(void);
void loadModeOverlay(void);
void loadSubOverlay(s32 id);

extern OverlayLoader OVERLAY_LOADER;
extern Task *(*MODE_ENTRY_POINTS[])(void);
extern s32 MODE_OVERLAY_FILES[];

/* The mode overlays' entry points, which MODE_ENTRY_POINTS holds: declared
   here, where the executable and every overlay see them, as the overlays'
   headers can't be included together */
Task *FIELDSTG_start(void);
Task *STCRDDEK_start(void);
Task *STPLNMET_start(void);
Task *FIGHTSTG_start(void);
Task *CARDGAME_start(void);
Task *SOUNDTST_start(void);
Task *SHOCKTST_start(void);
Task *STGTRAIN_start(void);
Task *STDGNAME_start(void);
Task *STGMCARD_start(void);
Task *STGDGLAB_createScene(void);
Task *STDWTITL_start(void);
Task *STITSHOP_start(void);
Task *STSTATUS_start(void);
Task *STCRDABM_start(void);
Task *STCRDSHP_start(void);
Task *STFGTREP_start(void);
Task *STAGSLCT_start(void);
Task *CNTY_SEL_start(void);

/* the memory map of mk/version/<version>.mk, which the Makefile gives the
   linker: where the overlays and the stages load */
extern u8 OVERLAY_VRAM[];
extern u8 STAGE_VRAM[];
/* the two areas the loader copies to, at those addresses (system.c) */
extern void *const OVERLAY_ADDRESS;
extern void *const SUB_OVERLAY_ADDRESS;

#endif /* DW3_OVERLAY_H */
