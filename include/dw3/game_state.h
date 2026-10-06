#ifndef DW3_GAME_STATE_H
#define DW3_GAME_STATE_H

/* The game state: modes, party, items, cards, flags (game3.c, game3_2.c, system.c) */

#include "common.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

union PartnerTotals;

/* The game state's methods (GAME.funcs) */
typedef struct GameFuncs {
    /* 0x00 */ void (*newGame)();
    /* 0x04 */ void (*commitMode)();
    /* 0x08 */ s32 (*getMode)(void);
    /* 0x0C */ s32 (*getModeArg)();
    /* 0x10 */ void (*requestMode)(s32 mode, s32 arg);
    /* 0x14 */ s32 (*isModeChangePending)();
    /* 0x18 */ s32 (*getPrevMode)();
    /* 0x1C */ s32 (*getPartyMember)(u32 index);
    /* 0x20 */ void (*setParty)();
    /* 0x24 */ void (*addCards)(s32 card, s32 count);
    /* 0x28 */ void (*giveStarterDeck)(void);
    /* 0x2C */ s32 (*getPartyPartner)();
    /* 0x30 */ void (*setStat)(s32 partner, u32 stat, s16 value);
    /* 0x34 */ void (*addStat)();
    /* 0x38 */ void (*computeStats)(s32 partner, union PartnerTotals *out);
    /* 0x3C */ s32 (*getPartnerSlots)(); /* (partner, s16 *out): the count */
    /* 0x40 */ void (*setPartnerSlots)();
    /* 0x44 */ s32 (*listPartnerEntries)(); /* (partner, s16 *out): the count */
    /* 0x48 */ s32 (*addPartnerEntry)(); /* (partner, id): 0 if it has it or has no room */
    /* 0x4C */ s32 (*getPartnerEntry)(); /* -1 if it hasn't the Digimon */
    /* 0x50 */ s32 (*setPartnerEntry)();
    /* 0x54 */ struct PartnerStats *(*getPartnerStats)(s32 partner);
    /* 0x58 */ void (*resetPlayTime)();
    /* 0x5C */ void (*updatePlayTime)();
} GameFuncs;

/*
 * FLAGS_00, the first flag bitset, followed by the event functions: FIELDSTG
 * and the stages call them through here (+0xC applies an action, +0x10 checks
 * a condition).
 */
typedef struct GameFlags {
    /* 0x00 */ u8 bits[4];
    /* 0x04 */ s32 pendingFlag10; /* PENDING_FLAG_10 */
    /* 0x08 */ s32 (*checkConditions)(u16 *list);
    /* 0x0C */ void (*applyAction)(s32 code, s32 value);
    /* 0x10 */ s32 (*checkCondition)(u16 code, u16 value);
    /* 0x14 */ void (*applyActions)(u16 *list);
    /* 0x18 */ void (*updateModeFlags)(void);
} GameFlags;

/* Digimon definition (DIGIMON_DATA, 52 of them; the first 8 are the partners) */
typedef struct DigimonData {
    /* 0x00 */ u16 id;
    /* 0x02 */ u16 battleStats[6];
    /* 0x0E */ u16 resistances[7];
    /* 0x1C */ u16 skills[7]; /* [1]-[6] are learnt at skillLevels */
    /* 0x2A */ u16 unk2A; /* a technique it has with the partner whose nameId is unk3D */
    /* 0x2C */ u8 unk2C[5];
    /* 0x31 */ u8 skillLevels[6];
    /* 0x37 */ u8 knownLevels[5]; /* the levels that mark an entry's skills[0]-[4] known */
    /* 0x3C */ u8 expLevel; /* the level after which its exp grows faster */
    /* 0x3D */ u8 unk3D;
    /* 0x3E */ u8 expRate; /* a partner's exp per level, in tenths */
    /* 0x3F */ u8 hp;
    /* 0x40 */ u8 mp;
    /* 0x41 */ u8 hpGrowth; /* what a partner's max HP grows by a level */
    /* 0x42 */ u8 mpGrowth;
    /* 0x43 */ u8 statGrowth[6]; /* columns of the growth tables */
    /* 0x49 */ u8 resistGrowth[7]; /* 1-5: how fast the gyms raise them */
    /* 0x50 */ u8 unk50[5];
    /* 0x55 */ u8 nameId; /* string in file 0x4F */
    /* 0x56 */ u8 unk56[2];
} DigimonData;

/* An item (ITEMS, GET_ITEM) */
typedef struct ItemInfo {
    /* 0x0 */ u8 *data;
    /* 0x4 */ u16 price;
    /* 0x6 */ u16 sellPrice; /* 0: cannot be sold */
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 type; /* 2-14 weapons, 15-20 armour, 21-24 accessories */
    /* 0xA */ u8 unkA[2];
} ItemInfo;

/* A technique (TECHS, from 1: technique n is TECHS[n - 1]) */
typedef struct TechData {
    /* 0x00 */ u16 mp; /* its cost */
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u8 icon; /* a frame of the menu sprites, from 0x37 */
    /* 0x05 */ u8 kind; /* 3: heals the target */
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 power;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
} TechData;

/* What ItemInfo.data points to for a weapon (types 2-14, WEAPON_DATA) */
typedef struct WeaponData {
    /* 0x00 */ s16 unk0; /* computeStats adds it to the totals' [11] */
    /* 0x02 */ u8 kind; /* 7: held in both hands */
    /* 0x03 */ u8 group;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u16 amounts[2]; /* what it adds to stats[] */
    /* 0x0A */ s16 atk;
    /* 0x0C */ u8 stats[2];
    /* 0x0E */ u8 unkE[6];
} WeaponData;

/* An armour's (types 15-20, ARMOR_DATA) */
typedef struct ArmorData {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 kind;
    /* 0x03 */ u8 group;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u16 amounts[2];
    /* 0x0A */ u8 stats[2];
    /* 0x0C */ s16 def;
    /* 0x0E */ u8 unkE[6];
} ArmorData;

/* An accessory's (types 21-24, ACCESSORY_DATA) */
typedef struct AccessoryData {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 kind; /* 8: one of its group at a time */
    /* 0x3 */ u8 group;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u16 amount;
    /* 0x8 */ u8 stat;
    /* 0x9 */ u8 unk9[3];
} AccessoryData;

/* One of a partner's Digimon (getPartnerEntry, setPartnerEntry) */
typedef struct PartnerEntry {
    /* 0x00 */ s16 id; /* 0-2 unused */
    /* 0x02 */ s8 level; /* shown in the lab; 1 when added */
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s32 exp;
    /* 0x08 */ s16 skills[6]; /* SKILL_ID and the flags below, 0 for none */
} PartnerEntry;

/* PartnerEntry.skills */
#define SKILL_ID 0x1FFF /* the skill, from 1 (TECHS[id - 1]) */
#define SKILL_KNOWN 0x2000
#define SKILL_LAST 0x8000 /* the sixth skill */

/* A card deck */
typedef struct Deck {
    /* 0x00 */ char name[0x16];
    /* 0x16 */ s16 cards[40];
} Deck;

/* Indices of a partner's stats (PartnerStats.stats, computeStats, setStat) */
#define STAT_LEVEL 0
#define STAT_HP 2
#define STAT_MAX_HP 3
#define STAT_MP 4
#define STAT_MAX_MP 5

/*
 * A partner Digimon from its name on (Partner.info), as getPartnerStats gives
 * it. Stats (computeStats and setStat order): 0 level, 1 TP, 2 HP, 3 max HP,
 * 4 MP, 5 max MP, 6-11 battle stats (6 is raised by weapons, 7 by armour),
 * 12-18 seven resistances; the totals add 19-21, which are subtracted from 6,
 * 7 and 10.
 */
typedef struct PartnerStats {
    /* 0x000 */ char name[0x18];
    /* 0x018 */ s32 exp;
    /* 0x01C */ s16 stats[19];
    /* 0x042 */ s16 status[3];
    /* 0x048 */ s16 slots[4]; /* three entries picked from entries[] */
    /* 0x050 */ PartnerEntry entries[44];
    /* 0x3C0 */ s16 equip[6];
    /* 0x3CC */ u8 unk3CC[4];
} PartnerStats;

/* One of the eight partner Digimon */
typedef struct Partner {
    /* 0x000 */ u8 unk0[4];
    /* 0x004 */ s32 unlocked; /* partner id + 3, 0 while locked */
    /* 0x008 */ s32 battleDigivolve; /* an entry id, compared with the slots': the Digimon the battle starts it as, 0 for its own */
    /* 0x00C */ PartnerStats info;
} Partner;

/* An enemy of a battle (FIELDSTG's encounter table points to these) */
typedef struct BattleEnemy {
    /* 0x0 */ s32 fighter; /* 0 for none */
    /* 0x4 */ s16 level;
    /* 0x6 */ s16 hp;
    /* 0x8 */ s16 mp;
    /* 0xA */ s16 unkA;
} BattleEnemy;

/* The next battle: FIELDSTG_startEncounter fills it (the stage select its
   first words), FIGHTSTG and WFIGHTMN read it; the gauges carry over from
   battle to battle */
typedef struct BattleSetup {
    /* 0x00 */ s32 unk0; /* 0 or 1, toggled by the stage select (Select) */
    /* 0x04 */ s32 unk4; /* -1 to 3, set by the stage select (up/down) */
    /* 0x08 */ s32 unk8; /* -1 to 7, set by the stage select */
    /* 0x0C */ s32 stage; /* the battle's fight stage */
    /* 0x10 */ s32 battle; /* the battle (BattleResult.battle) */
    /* 0x14 */ s32 music; /* the battle's music */
    /* 0x18 */ BattleEnemy enemies[3];
    /* 0x3C */ u8 ambushChance; /* a chance that WFIGHTMN scales by level */
    /* 0x3D */ u8 unk3D;
    /* 0x3E */ u8 unk3E[12]; /* FIGHTSTG's func_800A0400 gives 0 for side 0 when [5] is set */
    /* 0x4C */ s32 hasPrize; /* 1: the battle always gives prize */
    /* 0x50 */ s32 prize; /* an item (BattleResult.item) */
    /* 0x54 */ void (*clearGauges)(void);
    /* 0x58 */ s16 gauges[8]; /* filled in battle, up to 1000 */
} BattleSetup;

/* What the battle left for the report (BATTLE_RESULT, cleared by WFIGHTMN) */
typedef struct BattleResult {
    /* 0x00 */ s16 battle; /* row of STFGTREP_rewards */
    /* 0x02 */ s16 item; /* the item won, 0 for none */
    /* 0x04 */ s16 member; /* the party member whose accessory adds money */
    /* 0x06 */ struct {
        u8 fought;
        u8 used[3]; /* the Digimon of each slot was used */
    } partners[3];
} BattleResult;

/* computeStats' result: the stats with the equipment added, by STAT_* or
   by name. computeStats fills the first 22 (0x2C bytes). */
typedef union PartnerTotals {
    s16 stats[24];
    struct {
        /* 0x00 */ s16 level;
        /* 0x02 */ s16 tp; /* what the training's intensities cost */
        /* 0x04 */ s16 hp;
        /* 0x06 */ s16 maxHp;
        /* 0x08 */ s16 mp;
        /* 0x0A */ s16 maxMp;
        /* 0x0C */ s16 battle[6]; /* [0] raised by weapons, [1] by armour */
        /* 0x18 */ s16 resist[7];
        /* 0x26 */ s16 lowered[3]; /* taken from battle[0], [1] and [4] */
        /* 0x2C */ s32 spare; /* not filled: STGTRAIN's result keeps its yes/no answer here, 0 yes */
    } fields;
} PartnerTotals;

/* Game modes (GameState: mode >> 8 is the overlay) that more than their own
   overlay asks for */
#define MODE_NEW_GAME 0x2D7 /* FIELDSTG, where a new game starts */
#define MODE_CONTINUE 0xC00 /* STGMCARD, to load a game */
#define MODE_TITLE 0xE00 /* STDWTITL's title screen */
#define MODE_OPENING 0xE01 /* STDWTITL's first movie */
#if VERSION_US
#define MODE_ENDING 0xE0A /* STDWTITL's movie after the last battle */
#elif VERSION_EU
#define MODE_ENDING 0xE0B
#endif
#define MODE_BATTLE_REPORT 0x1400 /* STFGTREP */

/*
 * The game state (GAME): the first 0x26BC bytes are what newGame clears (the
 * save data), then the current game mode and the methods.
 * Game modes: mode >> 8 selects the overlay (MODE_OVERLAY_FILES); a mode
 * change is requested with requestMode and applied by commitMode when main
 * recreates the mode task.
 */
typedef struct GameState {
    /* 0x0000 */ u8 unk0[4];
    /* 0x0004 */ s8 digivolveDemo;
    /* 0x0005 */ u8 unk5[7];
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 unk10[0x18];
    /* 0x0028 */ s32 stageSelectTop; /* the debug stage select's first line */
    /* 0x002C */ s32 stageSelectCursor;
    /* 0x0030 */ s32 unk30;
    /* 0x0034 */ s32 fieldMode; /* where the menu returns to */
    /* 0x0038 */ Vec2 fieldPos; /* the player's, there */
    /* 0x0040 */ s32 fieldDir;
    /* 0x0044 */ u16 unk44;
    /* 0x0046 */ u16 unk46;
    /* 0x0048 */ s32 playFrames; /* 8.8, counted by the vsync callback */
    /* 0x004C */ s16 playHours;
    /* 0x004E */ s16 playMinutes;
    /* 0x0050 */ s16 playSeconds;
    /* 0x0052 */ s16 playTimeMaxed;
    /* 0x0054 */ char name[0x18]; /* the player's */
    /* 0x006C */ s32 money;
    /* 0x0070 */ s32 party[3]; /* partner indices */
    /* 0x007C */ s8 items[0x193]; /* counts, up to 99 */
    /* 0x020F */ s8 equippedItems[0x193];
    /* 0x03A2 */ s8 cards[0x13D]; /* counts, up to 9 */
    /* 0x04DF */ u8 cardsSeen[0x149];
    /* 0x0628 */ Deck decks[3];
    /* 0x075A */ u8 unk75A[2];
    /* 0x075C */ Partner partners[8];
    /* 0x263C */ s32 progress;
    /* 0x2640 */ s32 partySet; /* setParty's */
    /*
     * flags02-flags40: the event flag groups 0x02-0x40 (checkCondition,
     * applyAction), bitsets packed one after the other, so most start at an
     * odd byte
     */
#if VERSION_US
    /* 0x2644 */ u8 flags02[0xD];
    /* 0x2651 */ u8 flags04[0x2];
    /* 0x2653 */ u8 flags06[0x1];
    /* 0x2654 */ u8 flags08[0x1];
    /* 0x2655 */ u8 flags0A[0x2];
    /* 0x2657 */ u8 flags0C[0x8];
    /* 0x265F */ u8 flags0E[0xC];
    /* 0x266B */ u8 flags10[0x2];
    /* 0x266D */ u8 flags18[0x1];
    /* 0x266E */ u8 flags1A[0x9];
    /* 0x2677 */ u8 flags1C[0xB];
    /* 0x2682 */ u8 flags20[0x1E];
    /* 0x26A0 */ u8 flags40[0x1C];
    /* 0x26BC */ s32 mode;
    /* 0x26C0 */ s32 nextMode;
    /* 0x26C4 */ s32 prevMode;
    /* 0x26C8 */ s32 modeArg;
    /* 0x26CC */ u8 countdown[4]; /* three digits of seconds, then frames */
    /* 0x26D0 */ s32 clearTempFlags;
    /* 0x26D4 */ s32 unk26D4;
    /* 0x26D8 */ s32 unk26D8;
    /* 0x26DC */ s32 unk26DC;
    /* 0x26E0 */ s32 unk26E0;
    /* 0x26E4 */ s32 unk26E4;
    /* 0x26E8 */ s32 unk26E8;
    /* 0x26EC */ s32 unk26EC;
    /* 0x26F0 */ GameFuncs funcs;
#elif VERSION_EU
    /* 0x2644 */ u8 flags02[0x12];
    /* 0x2656 */ u8 flags04[0x2];
    /* 0x2658 */ u8 flags06[0x1];
    /* 0x2659 */ u8 flags08[0x1];
    /* 0x265A */ u8 flags0A[0x4];
    /* 0x265E */ u8 flags0C[0x8];
    /* 0x2666 */ u8 flags0E[0xC];
    /* 0x2672 */ u8 flags10[0x4];
    /* 0x2676 */ u8 flags18[0x2];
    /* 0x2678 */ u8 flags1A[0x9];
    /* 0x2681 */ u8 flags1C[0xB];
    /* 0x268C */ u8 flags20[0x1E];
    /* 0x26AA */ u8 flags40[0x1A];
    /* 0x26C4 */ s32 mode;
    /* 0x26C8 */ s32 nextMode;
    /* 0x26CC */ s32 prevMode;
    /* 0x26D0 */ s32 modeArg;
    /* 0x26D4 */ u8 countdown[4];
    /* 0x26D8 */ s32 clearTempFlags;
    /* 0x26DC */ s32 unk26D4;
    /* 0x26E0 */ s32 unk26D8;
    /* 0x26E4 */ s32 unk26DC;
    /* 0x26E8 */ s32 unk26E0;
    /* 0x26EC */ s32 unk26E4;
    /* 0x26F0 */ s32 unk26E8;
    /* 0x26F4 */ s32 unk26EC;
    /* 0x26F8 */ s32 unk26F8;
    /* 0x26FC */ GameFuncs funcs;
#endif
} GameState;

s32 unequipItem(s32 slot, s32 item);
s32 checkPartner(u32 op, s32 arg);
s32 findDigimon(s32 id);
ItemInfo *getItem(s32 id);
void initNewGameData(void);
void addCards(s32 item, s32 count);
s32 findPartnerEntry(s32 slot, s32 id);
void applyAction(s32 code, s32 value);
s32 checkCondition(u16, u16);
s32 testBit(u8 *bits, s32 index, s32 set);
s32 getPartnerSlots(s32 partner, s16 *out);
void setPartnerSlots(s32 partner, s16 *ids);
s32 listPartnerEntries(s32 partner, u16 *out);
s32 addPartnerEntry(s32 partner, s32 id);
s32 getPartnerEntry(s32 partner, s32 id, PartnerEntry *out);
s32 setPartnerEntry(s32 partner, s32 id, PartnerEntry *in);
PartnerStats *getPartnerStats(s32 partner);

extern DigimonData DIGIMON_DATA[];
extern DigimonData *(*GET_DIGIMON)(s32 id); /* getDigimon */
extern BattleSetup BATTLE_SETUP;
extern BattleResult BATTLE_RESULT;
extern ItemInfo ITEMS[];
/* What the usable items do (their ItemInfo.data), in src/main/data/game_3.c */
extern u8 ITEM_EFFECT_2B[], ITEM_EFFECT_2C[], ITEM_EFFECT_2D[], ITEM_EFFECT_2E[], ITEM_EFFECT_2F[],
    ITEM_EFFECT_30[], ITEM_EFFECT_31[], ITEM_EFFECT_32[], ITEM_EFFECT_33[], ITEM_EFFECT_34[],
    ITEM_EFFECT_35[], ITEM_EFFECT_36[], ITEM_EFFECT_37[], ITEM_EFFECT_38[], ITEM_EFFECT_39[],
    ITEM_EFFECT_3A[], ITEM_EFFECT_3B[], ITEM_EFFECT_3C[], ITEM_EFFECT_3D[], ITEM_EFFECT_3E[],
    ITEM_EFFECT_3F[], ITEM_EFFECT_40[], ITEM_EFFECT_41[], ITEM_EFFECT_42[], ITEM_EFFECT_43[],
    ITEM_EFFECT_44[], ITEM_EFFECT_45[], ITEM_EFFECT_46[], ITEM_EFFECT_47[], ITEM_EFFECT_48[],
    ITEM_EFFECT_49[], ITEM_EFFECT_4A[], ITEM_EFFECT_4B[], ITEM_EFFECT_4C[], ITEM_EFFECT_4D[],
    ITEM_EFFECT_4E[], ITEM_EFFECT_4F[], ITEM_EFFECT_50[], ITEM_EFFECT_51[], ITEM_EFFECT_52[],
    ITEM_EFFECT_53[], ITEM_EFFECT_54[], ITEM_EFFECT_55[], ITEM_EFFECT_56[], ITEM_EFFECT_57[],
    ITEM_EFFECT_58[], ITEM_EFFECT_59[], ITEM_EFFECT_5A[], ITEM_EFFECT_5B[], ITEM_EFFECT_169[],
    ITEM_EFFECT_16A[], ITEM_EFFECT_16B[], ITEM_EFFECT_16C[], ITEM_EFFECT_16D[], ITEM_EFFECT_16E[],
    ITEM_EFFECT_16F[], ITEM_EFFECT_170[], ITEM_EFFECT_171[], ITEM_EFFECT_172[], ITEM_EFFECT_173[],
    ITEM_EFFECT_174[], ITEM_EFFECT_175[], ITEM_EFFECT_176[], ITEM_EFFECT_177[], ITEM_EFFECT_178[],
    ITEM_EFFECT_179[], ITEM_EFFECT_17A[], ITEM_EFFECT_17B[], ITEM_EFFECT_17C[], ITEM_EFFECT_17D[],
    ITEM_EFFECT_17E[], ITEM_EFFECT_17F[], ITEM_EFFECT_180[], ITEM_EFFECT_181[], ITEM_EFFECT_182[],
    ITEM_EFFECT_183[], ITEM_EFFECT_184[], ITEM_EFFECT_185[], ITEM_EFFECT_186[], ITEM_EFFECT_187[],
    ITEM_EFFECT_188[], ITEM_EFFECT_189[], ITEM_EFFECT_18A[];
extern TechData TECHS[];
extern struct ItemInfo *(*GET_ITEM[])(s32 item);
/* GET_ITEM's entries, each with its own type */
typedef struct ItemFuncs {
    /* 0x0 */ struct ItemInfo *(*get)(s32 item); /* getItem */
    /* 0x4 */ s32 (*getCategory)(s32 item); /* getItemCategory (u8, but the menus read an int) */
    /* 0x8 */ s32 (*isKind)(s32 item, s32 kind); /* ItemInfo.unk8 == kind */
    /* 0xC */ s32 (*list)(s32 type, u16 *out); /* listItems */
} ItemFuncs;
#define ITEM_FUNCS ((ItemFuncs *)GET_ITEM)
extern u8 ITEM_TYPE_CATEGORIES[];
extern s32 MONEY_REQUIRED[];
extern u8 SPECIAL_CONDITIONS[];
extern s32 MONEY_GAINS[];
extern s32 MONEY_LOSSES[];
extern GameFlags FLAGS_00;
extern s32 STARTER_DECK[40];
extern u8 STARTER_PARTIES[][3];
extern u8 PROGRESS_RANGES[][2];
extern GameState GAME;

#endif /* DW3_GAME_STATE_H */
