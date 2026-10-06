#ifndef WFIGHTMN_H
#define WFIGHTMN_H

/* WFIGHTMN.PRO: the battle's sub-overlay. FIGHTSTG loads it (file 0x1FA)
   at STAGE_VRAM for a normal battle, and WFIGHTTS in its place for the
   battle test. */

#include "fightstg.h"

/* The item a partner can equip that makes FIGHTSTG's FIGHTSTG_queueRecovery act on
   it at the start of the battle */
#define WFIGHTMN_ITEM 0x140

/* The battle menu (WFIGHTMN_start), registered as BATTLE_TASK_MENU */
typedef struct BattleMenu {
    TASK_HEADER(BattleMenu);
    /* 0x50 */ s32 args[8]; /* the message's arguments */
    /* 0x70 */ s32 confusionSound;
} BattleMenu;

/* The task that loads the battle menu's files (WFIGHTMN_createLoader) */
typedef struct BattleLoader {
    TASK_HEADER(BattleLoader);
    /* 0x50 */ s32 unk50; /* never used */
} BattleLoader;

/* The battle menu's children */
typedef struct BattleMenuChildren {
    /* 0x00 */ BattleLoader *loader;
    /* 0x04 */ PlayerTurn *commands; /* the player's turn (FIGHTSTG_startPlayerTurn) */
    /* 0x08 */ BattleCamera *camera; /* FIGHTSTG_createBattleCamera */
    /* 0x0C */ Lights *lights;
    /* 0x10 */ FightStage *stage;
    /* 0x14 */ Models *models;
    /* 0x18 */ BattleChild cameraMove; /* the European version's shots, or the turn when the player loses */
    /* 0x1C */ BattleChild task; /* what the state waits for, NULL when done */
} BattleMenuChildren;

/* The screen its layers cover */
extern RECT WFIGHTMN_screen;
/* A technique's effects by its kind and by its unk7, for WFIGHTMN_bringLastEnemy */
extern s32 WFIGHTMN_kindEffects[][3];
extern s32 WFIGHTMN_unk7Effects[][4];
/* WFIGHTMN_startTech's effects */
extern s32 WFIGHTMN_actionEffects[][2];
/* The battle menu's states, by its substate */
extern void (*WFIGHTMN_states[])(BattleMenu *task, BattleMenuChildren *children);

BattleLoader *WFIGHTMN_createLoader(void);
void WFIGHTMN_initFighters(s32 digimon);
void WFIGHTMN_markPicked(BattleMenu *task, BattleMenuChildren *children);
void WFIGHTMN_markFought(void);
void WFIGHTMN_cancelBlast(void);
void WFIGHTMN_runTurn(BattleMenu *task);

#endif /* WFIGHTMN_H */
