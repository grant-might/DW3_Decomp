#include "common.h"

/*
 * 2MBYTE.OBJ's .bss, where its startup code, crt0, keeps $ra across InitHeap;
 * the second word is unused. Defined here, at the start of the .bss, so its
 * bytes stay in a report unit.
 */
s32 CRT0_SAVED_RA[2];
s32 FIELD_MENU_CHOICE[2]; /* FieldMenuChoice */
u8 CD_MODE[8];
s32 FLIP_PENDING[2];
s32 CARD_DRAWER[2];
s32 SPRITE_DRAWER[2];
s32 TEXT_TOOLS[2];
s32 TIM_LOADER[2];
s32 CD_SECTOR_HEADER[4];
s32 SOUND_HEAD_BUFFER_0[14336];
s32 SOUND_HEAD_BUFFER_1[10240];
s32 SOUND_HEAD_BUFFER_2[10240];
