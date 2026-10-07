#ifndef CARDGAME_H
#define CARDGAME_H

/* CARDGAME.PRO: the card battle (mode 0x700) */

#include "game.h"

/* CARDGAME's own pictures, a TIM archive */
#if VERSION_US
#define FILE_CARDGAME_TIMS 0x24E
#elif VERSION_EU
#define FILE_CARDGAME_TIMS 0x25D
#endif

/* The opponents of the card battles (CardOpponent) */
#if VERSION_US
#define FILE_CARDGAME_OPPONENTS 0x795
#elif VERSION_EU
#define FILE_CARDGAME_OPPONENTS 0x7A4
#endif

/* A card a player has out (CARDGAME_setSlot) */
typedef struct CardSlot {
    /* 0x0 */ s16 card; /* the index in the battle's card list */
    /* 0x2 */ s16 apBonus; /* what the effects added to its ap */
    /* 0x4 */ s16 hpBonus; /* and to its hp */
    /* 0x6 */ s16 ap; /* its attack points, 0 to 99 */
    /* 0x8 */ s16 hp; /* its hit points, 0 to 99: at 0 it is lost */
    /* 0xA */ u8 side;
    /* 0xB */ u8 owner;
    /* 0xC */ u8 order; /* CardBattle.slotCount when it was added */
} CardSlot;

/* A slot's card, sorted by id (CARDGAME_findCardSet) */
typedef struct CardSortEntry {
    /* 0x0 */ s16 slot;
    /* 0x2 */ s16 card; /* its id, minus one */
} CardSortEntry;

/* One of the two players of a card battle */
typedef struct CardPlayer {
    /* 0x00 */ u8 slotCount;
    /* 0x02 */ CardSlot slots[8];
} CardPlayer;

/* A card played in a round (CardRecord.plays), whose effect then runs */
typedef struct CardPlay {
    /* 0x0 */ s16 card; /* the index in the battle's card list */
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 side; /* who played it */
    /* 0x5 */ u8 targetKind; /* its effect's (CardEffect.target) */
    /* 0x6 */ u8 target; /* the slot's order, or the card, it was played on */
    /* 0x7 */ u8 unk7;
} CardPlay;

/* A card's effect (CARDGAME_cardEffects), read through
   CARDGAME_getEffectField */
typedef struct CardEffect {
    /* 0x0 */ u8 condition; /* for the computer (CARDGAME_checkComputerCondition) */
    /* 0x1 */ u8 playCondition; /* CARDGAME_checkPlayCondition's */
    /* 0x2 */ u8 message; /* what it shows when the play condition holds */
    /* 0x3 */ u8 target; /* the kind of target of its play (CardPlay.targetKind) */
    /* 0x4 */ u8 script[40]; /* the effect steps it runs one by one, up to a 0 */
} CardEffect;

/* How the computer plays a card of its deck (CardBattle.opponentPlans):
   kind first, then priority (CARDGAME_sortOpponentHand) */
typedef struct CardPlan {
    /* 0x0 */ u8 kind; /* 1-7 (CardDeckCard.kind) */
    /* 0x1 */ u8 flagged; /* bit 15 of the card in the opponent's deck */
    /* 0x2 */ s16 priority; /* by kind, then by place in the deck */
} CardPlan;

/* What CARDGAME_runBattle runs this frame (CardBattle.run) */
enum CardRun {
    CARD_RUN_PHASE,   /* the battle's phase (CARDGAME_runPhase) */
    CARD_RUN_STEP,    /* an effect step (CARDGAME_runEffectStep) */
    CARD_RUN_RESOLVE, /* the card just played (CARDGAME_resolveCard) */
    CARD_RUN_MENU     /* the battle menu (CARDGAME_runBattleMenu) */
};

/* The phases of a card battle (CardBattle.phase, CARDGAME_runPhase) */
enum CardPhase {
    CARD_PHASE_NONE, /* for nextPhase: no switch */
    CARD_PHASE_FADE_IN,
    CARD_PHASE_CHOOSE_DECK,
    CARD_PHASE_FIRST_PICK,   /* who starts */
    CARD_PHASE_DEAL,         /* six cards to each side */
    CARD_PHASE_PLAYS_BEFORE, /* plays before the cards are put out: kind 2 cards only */
    CARD_PHASE_PUT_OUT,
    CARD_PHASE_PLAYS_AFTER, /* plays after: any kind but 0 */
    CARD_PHASE_END_ROUND,
    CARD_PHASE_NEXT_ROUND,
    CARD_PHASE_MESSAGE /* the message of the phase that ended (CARDGAME_battleMessages) */
};

/* What a phase does once it is over (CARDGAME_battleMessages): the step
   that shows its message, and the phase after it */
typedef struct CardBattleMessage {
    /* 0x0 */ u16 step; /* for CardStep.next */
    /* 0x2 */ u16 phase; /* for CardBattle.nextPhase */
} CardBattleMessage;

/* A step of CARDGAME_windowSteps: once its time is past, CARDGAME_openStepWindows opens windows */
typedef struct CardBattleStep {
    /* 0x0 */ s16 time;
    /* 0x2 */ s16 kind;
} CardBattleStep;

/* Where a card of the opponent's deck is drawn (CardBattle.opponentDraws):
   the computer draws the cards of group round * 2 + 2 (CardBattle.round),
   and holds the cards of group 7 back */
typedef struct CardDraw {
    /* 0x0 */ u8 order; /* its place in the deck */
    /* 0x1 */ u8 group;
} CardDraw;

/* A player's cards in a card battle (CardSide.pile) */
typedef struct CardPile {
    /* 0x00 */ s16 apTotal; /* the sum of its slot cards' ap, which comes off the other side's hpTotal */
    /* 0x02 */ s16 hpTotal; /* the sum of its slot cards' hp: the higher one wins the round */
    /* 0x04 */ s16 deckTop; /* the index of the deck's top card */
    /* 0x06 */ s16 discardCount;
    /* 0x08 */ s16 deckCount; /* the cards left in the deck */
    /* 0x0A */ s16 handCount;
    /* 0x0C */ u8 points[5]; /* one per card colour */
    /* 0x11 */ u8 side; /* its panel */
    /* 0x12 */ u8 wins; /* rounds won: two win the battle */
    /* 0x13 */ u8 unk13;
    /* 0x14 */ s16 deck[40]; /* deckTop on are left */
    /* 0x64 */ s16 hand[10]; /* handCount in use */
    /* 0x78 */ s16 discards[10]; /* the cards played and lost from the slots, discardCount in use */
} CardPile;

/* The turns of a round, in which the sides play cards one after the other
   (CARDGAME_playRounds), and the battle menu (CardBattle.record) */
typedef struct CardRecord {
    /* 0x00 */ u8 menuState; /* CARDGAME_runBattleMenu's state */
    /* 0x01 */ u8 menuCursor; /* CARDGAME_runBattleMenu's cursor, 0-4 */
    /* 0x02 */ u8 unk2[0xA];
    /* 0x0C */ u8 turnState; /* CARDGAME_playRounds' state */
    /* 0x0D */ s8 playCount; /* the plays in use */
    /* 0x0E */ u8 turns; /* the turns of plays this round */
    /* 0x0F */ u8 passes; /* the turns with no card played: two end the plays */
    /* 0x10 */ u8 starter; /* the side that starts the round */
    /* 0x11 */ u8 turnSide; /* the side whose turn it is */
    /* 0x12 */ s8 answer; /* a step's result: -1 while waiting, then 0 or 1 */
    /* 0x13 */ u8 unk13;
    /* 0x14 */ s32 waitTime;
    /* 0x18 */ CardPlay plays[3]; /* the cards played this turn, up to three */
    /* 0x30 */ u8 unk30[4];
} CardRecord;

/* The effect step that runs (CARDGAME_runEffectStep) and its values, which
   CARDGAME_runBattleMenu keeps a copy of while the menu is open */
typedef struct CardStep {
    /* 0x00 */ u8 id; /* the step running */
    /* 0x01 */ u8 next; /* the step to start: CARDGAME_runEffectStep sets it up first */
    /* 0x02 */ u8 state; /* the step's own state */
    /* 0x03 */ u8 nextState; /* the state to set up first, if not 0 */
    /* 0x04 */ s32 time; /* a frame count, or the step's own sub-state */
    /* 0x08 */ s32 vars[5]; /* values each step uses its own way */
    /* 0x1C */ s32 cursor; /* the card or slot highlighted */
    /* 0x20 */ s32 choice; /* the card, slot or answer chosen; -1 for none */
    /* 0x24 */ u8 count; /* the cards picked, or to draw */
    /* 0x25 */ u8 flags; /* the step's own: the rows to pick from, the deck run out... */
    /* 0x26 */ s8 eligible[0x29]; /* the cards or slots that can be picked */
    /* 0x4F */ s8 marked[40]; /* the cards or slots picked */
} CardStep;

/* Each player's side of a card battle (CardBattle.sides) */
typedef struct CardSide {
    /* 0x00 */ CardPile pile;
    /* 0x8C */ u8 unk8C[0x3C];
} CardSide;

/* The animations of the cards on the table (CardBattle.anim): the slots,
   the plays or a pile laid out as sprites that scale in, then out */
enum CardAnimId {
    CARD_ANIM_NONE,
    CARD_ANIM_SHOW_SLOTS,
    CARD_ANIM_HIDE_SLOTS,
    CARD_ANIM_SHOW_PLAYS,
    CARD_ANIM_HIDE_PLAYS,
    CARD_ANIM_SHOW_HAND, /* the player's piles... */
    CARD_ANIM_HIDE_HAND,
    CARD_ANIM_SHOW_DECK,
    CARD_ANIM_HIDE_DECK,
    CARD_ANIM_SHOW_DISCARDS,
    CARD_ANIM_HIDE_DISCARDS,
    CARD_ANIM_SHOW_OPPONENT_HAND, /* ...and the opponent's */
    CARD_ANIM_HIDE_OPPONENT_HAND,
    CARD_ANIM_SHOW_OPPONENT_DECK,
    CARD_ANIM_HIDE_OPPONENT_DECK,
    CARD_ANIM_SHOW_OPPONENT_DISCARDS,
    CARD_ANIM_HIDE_OPPONENT_DISCARDS,
    CARD_ANIM_LAY_OUT_HAND, /* the hand laid out at once */
    CARD_ANIM_LAY_OUT_OPPONENT_HAND
};

/* CardAnim.dimAll */
#define CARD_ANIM_UNDIM_ALL 1
#define CARD_ANIM_DIM_ALL 2

/* The running animation of the cards on the table (CARDGAME_updateCardAnims) */
typedef struct CardAnim {
    /* 0x00 */ u8 current; /* a CardAnimId */
    /* 0x01 */ u8 next; /* the one to start */
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 hide; /* the one that hides what the last one showed */
    /* 0x04 */ u8 faceDown; /* the next pile or slots are laid out face down */
    /* 0x05 */ u8 dimAll; /* sets dimmed of the first 15 sprites once */
    /* 0x06 */ u8 dimmed[40]; /* by sprite */
    /* 0x30 */ s32 time;
    /* 0x34 */ s32 shown; /* the sprites scaled so far */
    /* 0x38 */ s32 stagger; /* one more sprite scales every 4 frames */
    /* 0x3C */ s32 count; /* the pile's cards */
    /* 0x40 */ s32 duration;
} CardAnim;

/* A card of an opponent's deck (CardOpponent.cards) */
typedef struct CardDeckCard {
    /* 0x0 */ s16 card; /* the id plus one in the low 12 bits; bit 15 a flag */
    /* 0x2 */ u8 group; /* when the computer draws it (CardDraw.group) */
    /* 0x3 */ u8 kind; /* how it plays it (CardPlan.kind) */
} CardDeckCard;

/* An opponent of the card battle: an entry of file FILE_CARDGAME_OPPONENTS, picked by
   CardBattle.arg (CARDGAME_loadOpponent) */
typedef struct CardOpponent {
    /* 0x00 */ CardDeckCard cards[40];
    /* 0xA0 */ s16 counterCards[20]; /* from 1, up to a 0: CardBattle.counterCards before the usual ones */
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9[3];
    /* 0xCC */ s32 unkCC;
} CardOpponent;

/* The card battle (CARDGAME_createBattle). Its seven task items: the battle
   screen is the last one (CardBattleItems). */
typedef struct CardBattle {
    TASK_HEADER(CardBattle);
    /* 0x050 */ s16 cards[250]; /* card ids, minus one (CARDGAME_loadCardImages) */
    /* 0x244 */ u8 cardCount; /* in cards */
    /* 0x245 */ u8 unk245[3];
    /* 0x248 */ s16 opponentDeck[40]; /* the opponent's deck */
    /* 0x298 */ s16 playerDeck[40]; /* the player's deck */
    /* 0x2E8 */ u8 arg; /* the mode argument: the opponent, from 1 */
    /* 0x2E9 */ u8 unk2E9;
    /* 0x2EA */ s16 deckChoice; /* the player's deck (GAME.decks) */
    /* 0x2EC */ s32 prize; /* the item the player wins (GAME.items) */
    /* 0x2F0 */ CardOpponent *opponents; /* file FILE_CARDGAME_OPPONENTS */
    /* 0x2F4 */ u8 run; /* what runs this frame (CARD_RUN_*) */
    /* 0x2F5 */ u8 firstStarter; /* the side that starts the first round */
    /* 0x2F6 */ u8 prevPhase;
    /* 0x2F7 */ u8 nextPhase; /* the phase to switch to, if not 0 */
    /* 0x2F8 */ u8 phase; /* a CARD_PHASE_* */
    /* 0x2F9 */ u8 phaseStep; /* the phase's own state */
    /* 0x2FA */ u8 unk2FA[2];
    /* 0x2FC */ s32 phaseTime; /* a frame count, or the phase's own counter */
    /* 0x300 */ u8 round; /* from 0 */
    /* 0x301 */ u8 roundWinner; /* the side that won the round */
    /* 0x302 */ u8 playerLost; /* 0 once the player has won the battle */
    /* 0x303 */ u8 result; /* 2 once the battle is over */
    /* 0x304 */ u8 keptCard; /* the card CARDGAME_keepLastCard kept, plus one */
    /* 0x305 */ u8 keptCount; /* and how many times */
    /* 0x306 */ u8 fade; /* the fade to start (CARDGAME_fadeColors), plus one */
    /* 0x307 */ u8 unk307;
    /* 0x308 */ u8 slotCount; /* the slots added so far */
    /* 0x309 */ u8 unk309;
    /* 0x30A */ CardDraw opponentDraws[40]; /* by the opponent's deck card */
    /* 0x35A */ u8 unk35A[2];
    /* 0x35C */ CardPlan opponentPlans[40]; /* one per card of side 1 (40-79) */
    /* 0x3FC */ u8 unk3FC[4];
    /* 0x400 */ u8 counterCards[0x1B]; /* the cards the computer answers with a kind 4 card, up to an 0xFF */
    /* 0x41B */ u8 drawEnd; /* the first card of the opponent's deck above the round's group */
    /* 0x41C */ u8 reserveStart; /* the first card of the opponent's deck held back (group 7) */
    /* 0x41D */ u8 unk41D[3];
    /* 0x420 */ CardStep effectStep;
    /* 0x498 */ CardAnim anim;
    /* 0x4DC */ u8 resolveState; /* CARDGAME_resolveCard's */
    /* 0x4DD */ u8 prevDiscarded; /* the card before the last one played went off too */
    /* 0x4DE */ u8 unk4DE;
    /* 0x4E0 */ s16 effectPos; /* the step of the card's effect script to run next */
    /* 0x4E2 */ s16 loopCount; /* the effect script's loop: the runs left */
    /* 0x4E4 */ s16 loopStart; /* and where it starts again */
    /* 0x4E8 */ s32 subState; /* the state of a phase's helpers (CARDGAME_showPlayedCard...) */
    /* 0x4EC */ s32 subTime; /* and their frame count */
    /* 0x4F0 */ CardStep savedStep; /* the step, while the battle menu is open */
    /* 0x568 */ CardRecord record;
    /* 0x59C */ CardSide sides[2];
    /* 0x72C */ CardPlayer players[2];
    /* 0x810 */ void (*shufflePile)(struct CardBattle *battle, s32 base, s32 n);
    /* 0x814 */ void (*sortCards)(struct CardBattle *battle, s16 *list, s32 range, s32 flags);
    /* 0x818 */ void (*putOutCards)(struct CardBattle *battle, s32 side);
    /* 0x81C */ void (*addCard)(struct CardBattle *battle, s32 side, s32 card);
    /* 0x820 */ s32 (*scoreHand)(struct CardBattle *battle, s32 side, s32 mask);
} CardBattle;

/* A file CARDGAME_tickPreloader reads; a text file is in each language */
typedef struct CardFileEntry {
    /* 0x0 */ s16 file; /* -2: the files before are enough to start, -1: the end */
    /* 0x2 */ s16 isText;
} CardFileEntry;

/* Reads CARDGAME's files into the file cache, one at a time */
typedef struct CardPreloader {
    TASK_HEADER(CardPreloader);
    /* 0x50 */ s32 ready; /* the files before the first -2 are in */
    /* 0x54 */ s16 index;
    /* 0x56 */ s16 file;
} CardPreloader;

/* Fades the screen to a colour: a POLY_F4 over it, blended (blend is the
   semi-transparency rate) */
typedef struct CardFader {
    TASK_HEADER(CardFader);
    /* 0x50 */ s32 mode; /* 0 idle, 1 fading, 2 done: the task ends */
    /* 0x54 */ s32 time; /* left */
    /* 0x58 */ s32 duration;
    /* 0x5C */ u8 blend;
    /* 0x5D */ u8 killWhenDone;
    /* 0x5E */ u8 target[3];
    /* 0x61 */ u8 from[3];
    /* 0x64 */ u8 color[3];
    /* 0x68 */ void (*setColor)(struct CardFader *fader, u8 r, u8 g, u8 b);
    /* 0x6C */ void (*start)(struct CardFader *fader, u8 r, u8 g, u8 b, s32 frames, s32 killWhenDone);
    /* 0x70 */ s32 (*isDone)(struct CardFader *fader);
    /* 0x74 */ void (*kill)(struct CardFader *fader);
} CardFader;

/* A fade colour and blend mode (CardBattle.fade - 1 picks one) */
typedef struct CardFadeColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 blend;
} CardFadeColor;

/* A blinking marker that opens and closes by scaling (CARDGAME_createMarker):
   frame 0x47 of the TIM archive's sprite sheet */
typedef struct CardMarker {
    TASK_HEADER(CardMarker);
    /* 0x50 */ s32 time; /* the blink */
    /* 0x54 */ s16 x;
    /* 0x56 */ s16 y;
    /* 0x58 */ s16 scaleX;
    /* 0x5A */ s16 scaleY;
    /* 0x5C */ u8 unk5C[6];
    /* 0x62 */ u8 phase; /* 0 opening, 1 open, 2 closing */
    /* 0x63 */ u8 fast; /* the blink's palette cycle */
    /* 0x64 */ s16 scaleTime;
    /* 0x66 */ s16 scaleDuration;
    /* 0x68 */ void (*setPos)(struct CardMarker *marker, s16 x, s16 y);
    /* 0x6C */ void (*close)(struct CardMarker *marker);
    /* 0x70 */ void (*setFast)(struct CardMarker *marker);
} CardMarker;

/* An offset from a window's corner */
typedef struct CardOffset {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} CardOffset;

/* How each of the six CardWindow windows is drawn */
typedef struct CardWindowLayout {
    /* 0x0 */ s16 x; /* its pivot, from the window's corner */
    /* 0x2 */ s16 y;
    /* 0x4 */ u8 sprite;
    /* 0x5 */ u8 kind; /* 2: a sprite of the fourth TIM, else of the third */
} CardWindowLayout;

/* A deck's window (CARDGAME_createDeckWindow): its name and how many cards
   of each of the six colours it has. It opens and closes by scaling. */
typedef struct CardDeckWindow {
    TASK_HEADER(CardDeckWindow);
    /* 0x50 */ s32 deck; /* in GAME.decks */
    /* 0x54 */ s32 time; /* the blink */
    /* 0x58 */ s16 x;
    /* 0x5A */ s16 y;
    /* 0x5C */ s16 scaleX;
    /* 0x5E */ s16 scaleY;
    /* 0x60 */ u8 counts[6];
    /* 0x66 */ u8 phase; /* 0 opening, 1 open, 2 closing */
    /* 0x67 */ u8 blink;
    /* 0x68 */ s16 scaleTime;
    /* 0x6A */ s16 scaleDuration;
    /* 0x6C */ void (*setBlink)(struct CardDeckWindow *window);
    /* 0x70 */ void (*close)(struct CardDeckWindow *window);
} CardDeckWindow;

/* A number drawn with the TIM archive's digits (CARDGAME_drawNumber) */
typedef struct CardNumber {
    /* 0x00 */ s16 value;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 scaleX;
    /* 0x08 */ s16 scaleY;
    /* 0x0A */ s16 pivotX;
    /* 0x0C */ s16 pivotY;
    /* 0x0E */ u8 digits;
    /* 0x0F */ u8 leadingZeros;
    /* 0x10 */ u8 depth;
} CardNumber;

/* The battle screen's task items */
typedef struct CardScreenItems {
    /* 0x00 */ Cursor *cursor;
    /* 0x04 */ TextWindow *texts[3];
    /* 0x10 */ TextWindow *panelTexts[2]; /* the label under each side's panel (CARDGAME_drawPanelIcon) */
    /* 0x18 */ TextWindow *moreTexts[8];
} CardScreenItems;

/* A panel's open (state 1) or close (state 3) scale, which goes over
   `duration` frames */
typedef struct CardPanelScale {
    /* 0x00 */ s16 value;
    /* 0x02 */ u8 unk2[2];
    /* 0x04 */ s16 time;
    /* 0x06 */ s16 duration;
    /* 0x08 */ u8 state;
    /* 0x09 */ u8 unk9[3];
} CardPanelScale;

/* Where CARDGAME_drawPanel draws the parts of a side's panel (CARDGAME_panelLayouts), relative to
   CardPanel.x and y (or the box's, boxX and boxY) */
typedef struct CardPanelLayout {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 frame; /* the panel's sprite */
    /* 0x02 */ u8 winsSprite; /* plus CardPanel.wins: the sprite at winsX, winsY */
    /* 0x03 */ u8 boxLabelSprite;
    /* 0x04 */ CardOffset flagIcons; /* five, 0x2A apart */
    /* 0x08 */ CardOffset flagNumbers; /* CardPanel.points, 0x2A apart */
    /* 0x0C */ CardOffset deckCount;
    /* 0x10 */ CardOffset handCount;
    /* 0x14 */ CardOffset discardCount; /* from the box */
    /* 0x18 */ CardOffset apBar;
    /* 0x1C */ CardOffset apTotal;
    /* 0x20 */ CardOffset hpBar;
    /* 0x24 */ CardOffset hpTotal;
    /* 0x28 */ CardOffset flag6Part;
    /* 0x2C */ CardOffset flag7Part;
    /* 0x30 */ CardOffset boxLabel; /* from the box */
    /* 0x34 */ CardOffset flagLights; /* five, 0x2A apart */
    /* 0x38 */ CardOffset flag6Light;
    /* 0x3C */ CardOffset flag7Light;
    /* 0x40 */ CardOffset boxLight; /* from the box */
    /* 0x44 */ CardOffset apLight;
    /* 0x48 */ CardOffset hpLight;
} CardPanelLayout;

/* One side's panel on the battle screen (CardScreen.panels): 0 is the
   player's, 1 the opponent's */
typedef struct CardPanel {
    /* 0x00 */ s16 time;
    /* 0x02 */ s16 duration;
    /* 0x04 */ s16 state;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s32 blinkTime; /* a frame counter for the blinking (CARDGAME_drawPanel) */
    /* 0x0C */ s16 x;
    /* 0x0E */ s16 y;
    /* 0x10 */ s16 apTotal; /* the values shown (CARDGAME_setPanelValue) */
    /* 0x12 */ s16 hpTotal;
    /* 0x14 */ u8 unk14[4];
    /* 0x18 */ u8 points[5]; /* one per card colour */
    /* 0x1D */ u8 deckCount;
    /* 0x1E */ u8 handCount;
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ s16 boxX; /* the discards' box, which slides on its own */
    /* 0x22 */ s16 boxY;
    /* 0x24 */ u8 unk24[4];
    /* 0x28 */ s32 discardCount;
    /* 0x2C */ u8 unk2C[4];
    /* 0x30 */ u8 flags[10];
    /* 0x3A */ u8 unk3A[2];
    /* 0x3C */ s16 winsX; /* where the rounds won are shown */
    /* 0x3E */ s16 winsY;
    /* 0x40 */ u8 unk40[4];
    /* 0x44 */ s32 wins; /* the rounds won shown */
    /* 0x48 */ CardPanelScale scale;
} CardPanel;

/* A card on the battle screen (CardScreen.sprites) */
typedef struct CardSprite {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 targetX;
    /* 0x0C */ s32 targetY;
    /* 0x10 */ s32 startX;
    /* 0x14 */ s32 startY;
    /* 0x18 */ s16 scaleX;
    /* 0x1A */ s16 scaleY;
    /* 0x1C */ s16 targetScaleX;
    /* 0x1E */ s16 targetScaleY;
    /* 0x20 */ s16 startScaleX;
    /* 0x22 */ s16 startScaleY;
    /* 0x24 */ s16 slot;
    /* 0x26 */ s16 moving;
    /* 0x28 */ s32 time;
    /* 0x2C */ s32 duration;
    /* 0x30 */ s32 growTime; /* the frames it grows for before it flies (CARDGAME_flySprite) */
    /* 0x34 */ s32 unk34; /* the effect's time */
    /* 0x38 */ s16 color; /* the card's colour, from 0 */
    /* 0x3A */ s16 index; /* in the battle's card list */
    /* 0x3C */ s16 isKind16;
    /* 0x3E */ u8 marks[3]; /* the plays that apply to the card, drawn as marks */
    /* 0x41 */ u8 points; /* the card's */
    /* 0x42 */ u8 state;
    /* 0x43 */ u8 ap; /* the values shown, which count towards the slot's */
    /* 0x44 */ u8 hp;
    /* 0x45 */ u8 visible;
    /* 0x46 */ u8 order; /* a played card's place in the record, from 1 */
    /* 0x47 */ u8 effect; /* 1-4, drawn by CARDGAME_drawSpriteEffect */
    /* 0x48 */ u8 highlight; /* bit 0 the cursor, bit 1 picked, bit 2 glowing */
    /* 0x49 */ u8 dimmed;
    /* 0x4A */ u8 unk4A[2];
} CardSprite;

/* What CARDGAME_setPanelValue sets: 0-4 a colour's points, then these */
enum CardPanelValue {
    CARD_PANEL_DECK = 5,
    CARD_PANEL_HAND,
    CARD_PANEL_DISCARDS,
    CARD_PANEL_AP,
    CARD_PANEL_HP
};

/* A blinking marker on the battle screen (CardScreen.blinkers), which can
   move to a target */
typedef struct CardBlinker {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 startX;
    /* 0x06 */ s16 startY;
    /* 0x08 */ s16 targetX;
    /* 0x0A */ s16 targetY;
    /* 0x0C */ s16 blinkTime;
    /* 0x0E */ u8 time;
    /* 0x0F */ u8 duration;
    /* 0x10 */ u8 state;
    /* 0x11 */ u8 unk11;
} CardBlinker;

/* A value that goes from `from` to `to` (0x1000 is 1) over `duration` frames */
typedef struct CardGauge {
    /* 0x00 */ s16 from;
    /* 0x02 */ s16 to;
    /* 0x04 */ s16 time;
    /* 0x06 */ s16 duration;
    /* 0x08 */ s16 state;
    /* 0x0A */ s16 value;
} CardGauge;

/* A window that opens (its scale goes from `from` to `to`) */
typedef struct CardWindow {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 from;
    /* 0x06 */ s16 to;
    /* 0x08 */ s16 time;
    /* 0x0A */ s16 duration;
    /* 0x0C */ s16 layout; /* in CARDGAME_windowLayouts */
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s32 value; /* by its layout: a string, a card, or points | colour << 4 */
    /* 0x14 */ u8 numbers[3]; /* two numbers, and whether they are shown */
    /* 0x17 */ u8 state;
} CardWindow;

/* The battle screen's message window (CardScreen.message), which
   CARDGAME_runBattleMenu keeps a copy of (CARDGAME_savedScreenState) */
typedef struct CardMessageWindow {
    /* 0x00 */ s32 place; /* in CARDGAME_messageWindowPositions */
    /* 0x04 */ s32 message;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s16 time;
    /* 0x0E */ s16 duration;
    /* 0x10 */ s16 choice; /* the cursor's row */
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 state; /* 1 opening, 2 open, 4 confirmed, 5 closing */
    /* 0x17 */ u8 prompt; /* what it asks: 0 nothing, else a choice with the cursor */
} CardMessageWindow;

/* The battle screen (created by CARDGAME_createScreen): the two panels, the cards on
   the table and the windows. Its 14 task items are a cursor and 13 text
   windows. */
typedef struct CardScreen {
    TASK_HEADER(CardScreen);
    /* 0x050 */ s16 *cards; /* the battle's card list */
    /* 0x054 */ s32 spriteFlags; /* this frame: bit 0 a sprite is animated, bit 1 a flying one landed */
    /* 0x058 */ u32 time;
    /* 0x05C */ s16 unk5C; /* CardBattle.arg */
    /* 0x05E */ s16 unk5E; /* CardBattle.unk2E9 */
    /* 0x060 */ CardPanel panels[2];
    /* 0x108 */ CardSprite sprites[40];
    /* 0xCE8 */ CardBlinker blinkers[12];
    /* 0xDC0 */ CardGauge gauges[3];
    /* 0xDE4 */ CardMessageWindow message;
    /* 0xDFC */ u8 unkDFC[4];
    /* 0xE00 */ s16 menuTime;
    /* 0xE02 */ s16 menuDuration;
    /* 0xE04 */ s16 menuRow;
    /* 0xE06 */ u8 unkE06[4];
    /* 0xE0A */ s16 menuState;
    /* 0xE0C */ CardWindow windows[6];
    /* 0xE9C */ u8 fadeRow; /* the background's palette row, 0 to 11 */
    /* 0xE9D */ u8 fadeTime; /* four frames a row */
    /* 0xE9E */ u8 fadeState; /* 0 dark, 1 fading in, 2 shown */
    /* 0xE9F */ u8 unkE9F;
    /* 0xEA0 */ void (*setPanelValue)(struct CardScreen *screen, s32 side, u32 which, s32 value);
    /* 0xEA4 */ void (*openGauge)(struct CardScreen *screen, s32 index, s16 value);
    /* 0xEA8 */ void (*closeGauge)(struct CardScreen *screen, s32 index);
    /* 0xEAC */ void (*openWindow)(struct CardScreen *screen, s32 index, s16 layout, s32 value, s32 x, s32 y);
    /* 0xEB0 */ void (*closeWindow)(struct CardScreen *screen, s32 index);
    /* 0xEB4 */ void (*clearPanelFlags)(struct CardScreen *screen);
    /* 0xEB8 */ void (*setPanelFlags)(struct CardScreen *screen, s32 bits);
    /* 0xEBC */ void (*closePanel)(struct CardScreen *screen, s32 side);
    /* 0xEC0 */ void (*openPanel)(struct CardScreen *screen, s32 side);
    /* 0xEC4 */ void (*closePanels)(struct CardScreen *screen);
    /* 0xEC8 */ void (*openPanels)(struct CardScreen *screen);
    /* 0xECC */ void (*resetPanels)(struct CardScreen *screen);
    /* 0xED0 */ void (*openPanelIcon)(struct CardScreen *screen, s32 side);
    /* 0xED4 */ void (*closePanelIcon)(struct CardScreen *screen, s32 side);
    /* 0xED8 */ s32 (*getHandOffset)(s32 count, s32 index);
    /* 0xEDC */ s32 (*showBlinker)(struct CardScreen *screen, s32 index, s16 x, s16 y);
    /* 0xEE0 */ s32 (*startBlinkerMove)(struct CardScreen *screen, s32 index, u8 duration, s16 x, s32 y);
    /* 0xEE4 */ void (*openMessage)(struct CardScreen *screen, s32 message, s32 prompt, s16 choice, s32 place);
    /* 0xEE8 */ void (*closeMessage)(struct CardScreen *screen);
    /* 0xEEC */ void (*confirmMessage)(struct CardScreen *screen);
    /* 0xEF0 */ void (*setMessageChoice)(struct CardScreen *screen, s32 choice);
    /* 0xEF4 */ void (*openMenu)(struct CardScreen *screen, s16 row);
    /* 0xEF8 */ void (*closeMenu)(struct CardScreen *screen);
    /* 0xEFC */ void (*confirmMenu)(struct CardScreen *screen);
    /* 0xF00 */ void (*setMenuRow)(struct CardScreen *screen, s16 row);
    /* 0xF04 */ void (*dealSprites)(struct CardScreen *screen, s16 duration, s16 count, s32 x, s32 y);
    /* 0xF08 */ void (*startMove)(struct CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
    /* 0xF0C */ void (*startSlide)(struct CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
    /* 0xF10 */ s32 (*startFly)(struct CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
    /* 0xF14 */ s32 (*addSprite)(struct CardScreen *screen, s32 index, s32 x, s32 y);
    /* 0xF18 */ s32 (*removeSprite)(struct CardScreen *screen, s32 index);
    /* 0xF1C */ s32 (*startBlink)(struct CardScreen *screen, s32 index);
    /* 0xF20 */ void (*setSpriteScale)(struct CardScreen *screen, s32 index, s32 scaleX, s32 scaleY);
    /* 0xF24 */ void (*scaleSprite)(struct CardScreen *screen, s32 index, s32 duration, s32 scaleX, s32 scaleY);
    /* 0xF28 */ s32 (*startFlip)(struct CardScreen *screen, s32 index);
    /* 0xF2C */ s32 (*startJitter)(struct CardScreen *screen, s32 index);
    /* 0xF30 */ s32 (*startShake)(struct CardScreen *screen, s32 index);
    /* 0xF34 */ s32 (*startRecovery)(struct CardScreen *screen, s32 index);
    /* 0xF38 */ s32 (*startEffect)(struct CardScreen *screen, s32 index, s32 which);
    /* 0xF3C */ void (*setSpriteCard)(struct CardScreen *screen, s32 sprite, s32 index);
    /* 0xF40 */ s32 (*getCardColor)(struct CardScreen *screen, s32 index);
    /* 0xF44 */ s32 (*loadCardImages)(s16 *dst, s16 *player, s16 *opponent);
} CardScreen;

/* The card battle's task items */
typedef struct CardBattleItems {
    /* 0x00 */ void *unk0[2];
    /* 0x08 */ CardMarker *marker; /* the deck choice's */
    /* 0x0C */ CardDeckWindow *deckWindows[3];
    /* 0x18 */ CardScreen *screen;
} CardBattleItems;

/* The functions and data the overlay's files share */
extern RECT CARDGAME_screenRect;
extern CardEffect CARDGAME_cardEffects[]; /* the effects of the first 60 cards, by card id minus one: conditions, target and messages */
extern RECT CARDGAME_fadeRect;
extern CardFileEntry CARDGAME_preloadFiles[];
CardBattle *CARDGAME_createBattle(s32 arg);
extern s16 CARDGAME_otherCards[]; /* the 100 cards whose images CARDGAME_loadCardImages loads after the decks (CARDGAME_getOtherCard) */
extern CardOffset CARDGAME_deckCountOffsets[];
extern s16 CARDGAME_commonCards[]; /* the cards everyone has, loaded after the two decks */
extern CardOffset CARDGAME_gaugePositions[]; /* where the three CardGauge gauges are */
extern u16 CARDGAME_windowTextOffsets[]; /* a window's text x, by CARDGAME_drawWindowText's index */
extern CardWindowLayout CARDGAME_windowLayouts[];
void CARDGAME_drawBackground(CardScreen *screen);
void CARDGAME_updateMessageWindow(CardScreen *screen, CardScreenItems *items);
void CARDGAME_updateWindow(CardScreen *screen, CardScreenItems *items, CardWindow *window, s32 index);
void CARDGAME_updateMenuWindow(CardScreen *screen, CardScreenItems *items);
void CARDGAME_updateBlinkers(CardScreen *screen, CardScreenItems *items);
void CARDGAME_updatePanels(CardScreen *screen, CardScreenItems *items);
void CARDGAME_updateSprites(CardScreen *screen, CardScreenItems *items);
void CARDGAME_moveBlinker(CardBlinker *blinker);
void CARDGAME_drawBlinker(CardBlinker *blinker);
void CARDGAME_drawPanelIcon(CardScreen *screen, CardScreenItems *items, s32 side, CardPanelScale *scale);
void CARDGAME_updatePanelIcon(CardScreen *screen, CardScreenItems *items, s32 side, CardPanelScale *scale);
void CARDGAME_slidePanel(CardPanel *panel, CardScreenItems *items, s32 side);
void CARDGAME_drawPanel(CardPanel *panel, CardScreenItems *items, s32 side);
void CARDGAME_drawSpriteHighlights(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteMarks(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteOrder(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteEffect(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteDim(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteCard(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSpriteBlink(CardScreen *screen, CardSprite *sprite);
void CARDGAME_animateSprite(CardScreen *screen, CardScreenItems *items, CardSprite *sprite);
void CARDGAME_showPanelValues(CardBattle *battle, CardBattleItems *items);
extern s16 CARDGAME_animPiles[7][2]; /* the side and pile CARDGAME_updateCardAnims passes to CARDGAME_layOutPile */
extern u16 CARDGAME_defaultDeck[]; /* the deck used when the chosen one is empty */
extern CardOffset CARDGAME_deckWindowPos[3]; /* the three deck windows */
extern u8 CARDGAME_turnStates[]; /* the next record.turnState state, by step and side */
extern CardBattleMessage CARDGAME_battleMessages[]; /* the step and nextPhase of CARDGAME_startBattleMessage, by prevPhase */
extern s32 CARDGAME_rowSpriteOffsets[]; /* the sprite offset of each row of CARDGAME_viewTable */
extern s32 CARDGAME_rowSteps[]; /* the step of each row of CARDGAME_viewTable */
extern s16 CARDGAME_savedPanelScales[2]; /* the panels' scale states, kept by CARDGAME_viewTable */
extern s32 CARDGAME_selectionText; /* the message of CARDGAME_chooseCard's selection */
#if VERSION_EU
extern s32 CARDGAME_slotRowPositions[2][4]; /* sprite positions, by SHIFT_PAL_SCREEN */
extern CardOffset CARDGAME_panelIconPositions[2][2][2]; /* CARDGAME_drawPanelIcon's icon and label positions, by SHIFT_PAL_SCREEN and side (EU) */
#endif
extern s16 CARDGAME_stepWindowPositions[2][3][4][2]; /* CARDGAME_openStepWindows's window positions, by layout and window, then the same moved for SHIFT_PAL_SCREEN */
s32 CARDGAME_getTableHeight(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_viewTable(CardBattle *battle, CardScreen *screen);
void CARDGAME_moveTableHighlight(CardBattle *battle, CardScreen *screen, s32 kind, s32 delta);
void CARDGAME_setupCardChoice(CardBattle *battle, CardScreen *screen, s32 side, s32 kind);
void CARDGAME_startColorChange(CardBattle *battle, CardScreen *screen, s32 arg2, s32 arg3);
extern s16 CARDGAME_cardWindowPositions[2][2][2]; /* two positions, then the same moved for SHIFT_PAL_SCREEN */
extern u8 CARDGAME_stepMessages[][2]; /* CARDGAME_startStepMessage's text for window 5 and what screen->unkEE4 shows, by message */
extern CardBattleStep CARDGAME_windowSteps[];
extern s32 CARDGAME_coinCardPositions[][2]; /* the two cards' x, y (CARDGAME_startFirstPick) */
extern s32 CARDGAME_promptText; /* the text of window 0 */
extern s16 CARDGAME_colorFlags[]; /* a flag bit per card colour */
extern s32 CARDGAME_discardPositions[][2]; /* x, y per side */
extern u8 CARDGAME_slotMoves[2][6][2]; /* per side, the slot moves (from, to) of CARDGAME_removeMarkedSlots */
extern u8 CARDGAME_slotMoveCounts[]; /* per side, the entries of CARDGAME_slotMoves */
extern u8 CARDGAME_markedCounts[2]; /* per side, the marked slots */
void CARDGAME_returnOpponentHand(CardBattle *battle, CardBattleItems *items);
void CARDGAME_showCardInfo(CardBattle *battle, CardScreen *screen, s32 offset);
s32 CARDGAME_canPlayCard(CardBattle *battle, u8 *arg1, s32 card);
void CARDGAME_addCardPoints(CardBattle *battle, CardScreen *screen, CardPile *pile, s32 arg3, s32 card);
s32 CARDGAME_stepColorValue(CardBattle *battle, CardScreen *screen, s32 side, s32 color);
extern s16 CARDGAME_shakeOffsets[]; /* CARDGAME_shakeSprite's x offsets, by time */
extern s16 CARDGAME_jitterOffsets[]; /* CARDGAME_jitterSprite's x and y offsets */
s32 CARDGAME_stepShakeAway(CardBattle *battle, CardScreen *screen, s32 index);
void CARDGAME_discardSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index);
s32 CARDGAME_stepDiscardSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index);
s32 CARDGAME_stepSendOff(CardBattle *battle, CardScreen *screen, s32 index);
void CARDGAME_returnSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index);
void CARDGAME_sortCards(CardBattle *battle, s16 *list, s32 range, s32 flags);
void CARDGAME_shufflePile(CardBattle *battle, s32 base, s32 n);
void CARDGAME_setCountingCardValues(CardBattle *battle, CardSlot *slot, s32 side, s32 pass);
extern CardFadeColor CARDGAME_fadeColors[]; /* CARDGAME_startStepFade's fade colours and blends, by fade - 1 */
extern s32 CARDGAME_recordCardPositions[][2]; /* where card 15 goes, by CardRecord.playCount */
extern s16 CARDGAME_countingCards[]; /* five card ids, minus one */
extern CardOffset CARDGAME_playedCardPos[2][2]; /* then the same moved for SHIFT_PAL_SCREEN */
extern CardMessageWindow CARDGAME_savedScreenState;
void CARDGAME_setSlot(CardBattle *battle, s32 side, s32 card, s32 index);
void CARDGAME_addCard(CardBattle *battle, s32 side, s32 card);
void CARDGAME_putOutCards(CardBattle *battle, s32 side);
void CARDGAME_updateCardAnims(CardBattle *battle, CardBattleItems *items);
void CARDGAME_runEffectStep(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_runPhase(CardBattle *battle, CardBattleItems *items);
u8 CARDGAME_resolveCard(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_runBattleMenu(CardBattle *battle, CardBattleItems *items);
void CARDGAME_updateBattle(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_scoreHand(CardBattle *battle, s32 side, s32 mask);
s32 CARDGAME_unflagSlotsOver(CardBattle *battle, s32 side, s32 value, s32 keep);
s32 CARDGAME_pickLowestOpponentCard(CardBattle *battle);
s32 CARDGAME_getEffectField(s32 index, u32 field, s32 offset);
void CARDGAME_jumpIfLastSide(CardBattle *battle, CardScreen *screen, s32 value, s32 offset);
void CARDGAME_jumpIfFewInHand(CardBattle *battle, s32 side, s32 value, s32 offset);
void CARDGAME_jumpIfManyInHand(CardBattle *battle, s32 side, s32 value, s32 offset);
void CARDGAME_jumpIfDeckLeft(CardBattle *battle, s32 side, s32 offset);
void CARDGAME_jumpIfSlotFree(CardBattle *battle, s32 side, s32 offset);
s32 CARDGAME_countDown(CardBattle *battle, CardScreen *screen);
void CARDGAME_chooseNextDraw(CardBattle *battle, CardScreen *screen, s32 which);
void CARDGAME_markSlotsOfOrder(CardBattle *battle, CardScreen *screen);
void CARDGAME_markBestOpponentSlot(CardBattle *battle);
s32 CARDGAME_stepEffectColorValue(CardBattle *battle, CardScreen *screen);
void CARDGAME_sortOpponentCards(CardBattle *battle);
s32 CARDGAME_canPlayCardKind(CardBattle *battle, s32 index);
s16 CARDGAME_getStepWindowPos(s32 a, s32 b, s32 c);
s32 CARDGAME_openStepWindows(CardBattle *battle, CardScreen *screen, s32 layout, s32 text, s32 time, s32 step);
void CARDGAME_startQuestion(CardBattle *battle, CardScreen *screen, s32 value);
s32 CARDGAME_stepYesNo(CardBattle *battle, CardScreen *screen);
void CARDGAME_clearCardInfo(CardBattle *battle, CardScreen *screen);
void CARDGAME_showTableCardInfo(CardBattle *battle, CardScreen *screen, s32 kind);
void CARDGAME_startHandPick(CardBattle *battle, CardScreen *screen, CardPile *pile);
void CARDGAME_startPick(CardBattle *battle, CardScreen *screen, s32 all, s32 arg3);
void CARDGAME_moveSelection(CardBattle *battle, CardScreen *screen, s32 count, s32 step);
void CARDGAME_movePileSelection(CardBattle *battle, CardScreen *screen, CardPile *pile, s32 step);
void CARDGAME_flagPlayableCards(CardBattle *battle, CardScreen *screen, CardPile *pile);
s32 CARDGAME_isHandPickDone(CardBattle *battle, CardScreen *screen, CardPile *pile);
s32 CARDGAME_togglePick(CardBattle *battle, CardScreen *screen, CardPile *pile);
void CARDGAME_readChooseInput(CardBattle *battle, CardScreen *screen, CardPile *pile);
void CARDGAME_readPickInput(CardBattle *battle, CardScreen *screen, CardPile *pile);
void CARDGAME_readCountInput(CardBattle *battle, CardScreen *screen, s32 count);
s32 CARDGAME_stepPulseCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_startPanelsStep(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_stepMessage(CardBattle *battle, CardScreen *screen);
void CARDGAME_startStepMessage(CardBattle *battle, CardScreen *screen, s32 index);
void CARDGAME_switchCoinCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_startFirstPick(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_drawFirstPlayer(CardBattle *battle, CardScreen *screen);
void CARDGAME_startViewTable(CardBattle *battle, CardScreen *screen);
void CARDGAME_startPickTableCard(CardBattle *battle, CardScreen *screen, s32 arg2);
s32 CARDGAME_getPickTableHeight(CardBattle *battle, CardScreen *screen);
void CARDGAME_movePickHighlight(CardBattle *battle, CardScreen *screen, s32 kind, s32 delta);
s32 CARDGAME_pickTableCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_setupSideChoice(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_moveHandHighlight(CardBattle *battle, CardScreen *screen, s32 delta);
void CARDGAME_browseHand(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_chooseCard(CardBattle *battle, CardScreen *screen, s32 mode);
s32 CARDGAME_pickComputerCards(CardBattle *battle, CardScreen *screen);
void CARDGAME_pickComputerDeckCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_startPileChoice(CardBattle *battle, CardScreen *screen, s32 arg2);
s32 CARDGAME_addColorCount(CardBattle *battle, CardScreen *screen, s32 side, s32 card);
s32 CARDGAME_stepReturnSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 index);
s32 CARDGAME_waitFor(CardBattle *battle, CardScreen *screen, s32 duration);
void CARDGAME_beginStep(CardBattle *battle, CardScreen *screen);
void CARDGAME_startHandCount(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_startColorDrain(CardBattle *battle, CardScreen *screen);
void CARDGAME_startCloseGauge(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_keepLastCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_showPileCard(CardBattle *battle, CardScreen *screen, s32 side, s32 which);
s32 CARDGAME_drawFromDeck(CardBattle *battle, CardScreen *screen, s32 side, s32 which);
void CARDGAME_startDiscardCount(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_returnUsedCards(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_startDraw(CardBattle *battle, CardScreen *screen, s32 arg2);
s32 CARDGAME_markDrawnCards(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_drawMarkedCards(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_drawNewCards(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_startSlotSweep(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_stepSlotSweep(CardBattle *battle, CardScreen *screen, s32 which);
void CARDGAME_markRecordHits(CardBattle *battle, CardScreen *screen, s32 arg2, s32 index);
void CARDGAME_putSlotCard(CardBattle *battle, CardScreen *screen, s32 side, s32 card);
void CARDGAME_takeHandCard(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_moveSlotCard(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_copySlotCard(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_flipSlotCard(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_startPlayCard(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_stepPlayCard(CardBattle *battle, CardScreen *screen);
void CARDGAME_clearHands(CardBattle *battle, CardScreen *screen);
/* The steps CARDGAME_stepPlayCard has before its card goes off: the European version
   shows the card's information first, and waits for a button */
#if VERSION_US
#define CARD_INFO_STEPS 0
#elif VERSION_EU
#define CARD_INFO_STEPS 2
#endif
void CARDGAME_dealHands(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_stepStart(CardBattle *battle, CardScreen *screen);
void CARDGAME_startAttack(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_stepAttack(CardBattle *battle, CardScreen *screen, s32 side);
void CARDGAME_startDiscardAllSlots(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_stepDiscardAllSlots(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_interpolate(s32 to, s32 from, s32 duration, s32 time);
void CARDGAME_startSwap(CardBattle *battle, CardScreen *screen);
void CARDGAME_startTotals(CardBattle *battle, CardScreen *screen);
void CARDGAME_startRoundEnd(CardBattle *battle, CardScreen *screen);
void CARDGAME_startMessage(CardBattle *battle, CardScreen *screen, s32 text);
void CARDGAME_startClosePanels(CardBattle *battle, CardScreen *screen, s32 force);
s32 CARDGAME_stepClosePanels(CardBattle *battle, CardScreen *screen);
void CARDGAME_startOpenPanels(CardBattle *battle, CardScreen *screen, s32 force);
s32 CARDGAME_stepOpenPanels(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_checkPlayCondition(CardBattle *battle, CardScreen *screen, s32 kind);
/* The steps CARDGAME_runEffectStep starts (CardBattle.effectStep.next) and runs (effectStep.id) */
s32 CARDGAME_stepChooseCards(CardBattle *battle, CardScreen *screen, CardPile *pile);
s32 CARDGAME_stepTally(CardBattle *battle, CardScreen *screen);
void CARDGAME_pickBestPileCard(CardBattle *battle, CardScreen *screen, s32 arg2);
void CARDGAME_pickLowestPlayerCard(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_stepPileChoice(CardBattle *battle, CardScreen *screen);
void CARDGAME_startPreviousCardChoice(CardBattle *battle, CardScreen *screen, s32 arg2);
s32 CARDGAME_stepPreviousCardChoice(CardBattle *battle, CardScreen *screen);
void CARDGAME_showTargetSlots(CardBattle *battle, CardScreen *screen, s32 side, s32 arg3);
s32 CARDGAME_stepTargetSlots(CardBattle *battle, CardScreen *screen);
void CARDGAME_startSlotEffects(CardBattle *battle, CardScreen *screen, s32 arg2);
void CARDGAME_moveMarkedSlots(CardBattle *battle, CardScreen *screen, s32 arg2, s32 arg3);
s32 CARDGAME_stepSlotStats(CardBattle *battle, CardScreen *screen);
void CARDGAME_markTargetSlots(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_removeMarkedSlots(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_markPileCardsByColor(CardBattle *battle, CardScreen *screen, s32 side, s32 kind, s32 flags);
s32 CARDGAME_markSlotsByColor(CardBattle *battle, CardScreen *screen, s32 arg2, s32 flags);
s32 CARDGAME_discardHand(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_drainColorValues(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_discardPrevCard(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_discardPickedCard(CardBattle *battle, CardScreen *screen, s32 side, s32 arg3);
void CARDGAME_takeCardToHand(CardBattle *battle, CardScreen *screen, s32 side, s32 arg3);
s32 CARDGAME_stepSwap(CardBattle *battle, CardScreen *screen);
void CARDGAME_showSlotTotal(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_stepSlotTotal(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_stepTotals(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_stepRoundEnd(CardBattle *battle, CardScreen *screen, s32 side);
s32 CARDGAME_waitMessage(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_countSlotValues(CardBattle *battle, CardScreen *screen);
void CARDGAME_updateScene(Task *task, CardBattle **items);
void CARDGAME_drawMarker(CardMarker *marker);
void CARDGAME_updateMarker(CardMarker *marker);
void CARDGAME_setMarkerPos(CardMarker *marker, s16 x, s16 y);
void CARDGAME_setMarkerFast(CardMarker *marker);
void CARDGAME_closeMarker(CardMarker *marker);
CardMarker *CARDGAME_createMarker(s16 x, s16 y);
void CARDGAME_drawDeckWindow(CardDeckWindow *window);
void CARDGAME_updateDeckWindow(CardDeckWindow *window, TextWindow **texts);
void CARDGAME_setDeckWindowBlink(CardDeckWindow *window);
void CARDGAME_closeDeckWindow(CardDeckWindow *window);
CardDeckWindow *CARDGAME_createDeckWindow(s32 deck, s32 x, s32 y);
void CARDGAME_drawNumber(CardNumber *number, s32 scaled);
void CARDGAME_drawGauge(CardScreen *screen, CardScreenItems *items, s32 index, CardGauge *p);
void CARDGAME_updateGauge(CardScreen *screen, CardScreenItems *items, s32 index, CardGauge *p);
void CARDGAME_updateGauges(CardScreen *screen, CardScreenItems *items);
void CARDGAME_drawWindowFrame(CardScreen *screen, CardScreenItems *items, CardWindow *window);
void CARDGAME_drawWindowNumbers(CardScreen *screen, CardScreenItems *items, CardWindow *window);
void CARDGAME_drawWindowText(CardScreen *screen, CardWindow *window, TextWindow *text, s32 file, s32 index);
void CARDGAME_drawCenteredText(CardScreen *screen, CardScreenItems *items, CardWindow *window, TextWindow *text, s32 file);
void CARDGAME_updateWindows(CardScreen *screen, CardScreenItems *items);
void CARDGAME_drawMessageFrame(CardScreen *screen, CardScreenItems *items, s16 scale, s32 x, s32 y);
void CARDGAME_drawMessageMark(CardScreen *screen, CardScreenItems *items, s32 x, s32 y);
void CARDGAME_drawMenuFrame(CardScreen *screen, CardScreenItems *items, s16 scale, s32 x, s32 y);
s32 CARDGAME_getHandOffset(s32 count, s32 index);
s32 CARDGAME_shakeSprite(CardScreen *screen, CardSprite *sprite);
s32 CARDGAME_holdSpriteThenBlink(CardScreen *screen, CardSprite *sprite);
s32 CARDGAME_holdSprite(CardScreen *screen, CardSprite *sprite, s32 duration);
s32 CARDGAME_jitterSprite(CardScreen *screen, CardSprite *sprite);
s32 CARDGAME_flipSprite(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawSprite(CardScreen *screen, CardSprite *sprite);
void CARDGAME_updateScreen(CardScreen *screen, CardScreenItems *items);
void CARDGAME_openGauge(CardScreen *screen, s32 index, s16 value);
void CARDGAME_closeGauge(CardScreen *screen, s32 index);
void CARDGAME_openWindow(CardScreen *screen, s32 index, s16 layout, s32 value, s32 x, s32 y);
void CARDGAME_closeWindow(CardScreen *screen, s32 index);
s32 CARDGAME_showBlinker(CardScreen *screen, s32 index, s16 x, s16 y);
s32 CARDGAME_startBlinkerMove(CardScreen *screen, s32 index, u8 duration, s16 x, s32 y);
void CARDGAME_openMessage(CardScreen *screen, s32 arg1, s32 arg2, s16 arg3, s32 arg4);
void CARDGAME_closeMessage(CardScreen *screen);
void CARDGAME_confirmMessage(CardScreen *screen);
void CARDGAME_setMessageChoice(CardScreen *screen, s32 value);
void CARDGAME_openMenuWindow(CardScreen *screen, s16 value);
void CARDGAME_closeMenuWindow(CardScreen *screen);
void CARDGAME_confirmMenuWindow(CardScreen *screen);
void CARDGAME_setMenuWindowRow(CardScreen *screen, s16 value);
void CARDGAME_resetPanels(CardScreen *screen);
void CARDGAME_openPanels(CardScreen *screen);
void CARDGAME_closePanels(CardScreen *screen);
void CARDGAME_openPanel(CardScreen *screen, s32 side);
void CARDGAME_closePanel(CardScreen *screen, s32 side);
void CARDGAME_openPanelIcon(CardScreen *screen, s32 side);
void CARDGAME_closePanelIcon(CardScreen *screen, s32 side);
s32 CARDGAME_addSprite(CardScreen *screen, s32 index, s32 x, s32 y);
s32 CARDGAME_startSpriteFlip(CardScreen *screen, s32 index);
s32 CARDGAME_startSpriteJitter(CardScreen *screen, s32 index);
s32 CARDGAME_startSpriteShake(CardScreen *screen, s32 index);
s32 CARDGAME_startSpriteRecovery(CardScreen *screen, s32 index);
s32 CARDGAME_startSpriteEffect(CardScreen *screen, s32 index, s32 which);
s32 CARDGAME_setSpriteScaleTarget(CardScreen *screen, s32 index, s32 duration, s32 scaleX, s32 scaleY, s32 instant);
void CARDGAME_setSpriteScale(CardScreen *screen, s32 index, s32 scaleX, s32 scaleY);
void CARDGAME_scaleSprite(CardScreen *screen, s32 index, s32 duration, s32 scaleX, s32 scaleY);
void CARDGAME_setSpriteMove(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
void CARDGAME_startSpriteMove(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
void CARDGAME_startSpriteSlide(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
s32 CARDGAME_startSpriteFly(CardScreen *screen, s32 index, s32 duration, s32 x, s32 y);
void CARDGAME_setPanelValue(CardScreen *screen, s32 side, u32 which, s32 value);
void CARDGAME_setPanelFlags(CardScreen *screen, s32 bits);
void CARDGAME_clearPanelFlags(CardScreen *screen);
s32 CARDGAME_removeSprite(CardScreen *screen, s32 index);
s32 CARDGAME_startSpriteBlink(CardScreen *screen, s32 index);
void CARDGAME_dealSprites(CardScreen *screen, s16 duration, s16 count, s32 x, s32 y);
s32 CARDGAME_getCardColor(CardScreen *screen, s32 index);
void CARDGAME_setSpriteCard(CardScreen *screen, s32 sprite, s32 index);
void CARDGAME_loadCardImage(TimLoader *loader, u8 *image, s32 slot);
s32 CARDGAME_getOtherCard(s32 index);
s32 CARDGAME_loadCardImages(s16 *dst, s16 *player, s16 *opponent);
CardScreen *CARDGAME_createScreen(s16 *cards);
void CARDGAME_tickPreloader(CardPreloader *task);
CardPreloader *CARDGAME_startPreloader(void);
void CARDGAME_loadOpponent(CardBattle *battle, CardBattleItems *items);
void CARDGAME_moveSprite(CardScreen *screen, CardSprite *sprite);
s32 CARDGAME_flySprite(CardScreen *screen, CardSprite *sprite);
void CARDGAME_drawCardPicture(CardSprite *sprite);
extern s16 CARDGAME_prizeItems[]; /* the item an opponent gives for a win (CardBattle.prize), by its unkCC */
extern s32 CARDGAME_pictureSheet[]; /* the sprite sheet CARDGAME_drawCardPicture draws a card's picture with */
extern u8 CARDGAME_loopFrames[]; /* the frames of a sprite's effect 1, which loops */
extern u8 CARDGAME_onceFrames[]; /* the frames of its effect 2, which plays once */
extern u8 CARDGAME_highlightCluts[]; /* a palette cycle: 0, 1, 2, 3, 2, 1 */
extern s32 CARDGAME_messageWindowPositions[][2]; /* the message window's places (x, y), by CardScreen.message.place */
extern CardPanelLayout CARDGAME_panelLayouts[2]; /* the panels' layouts, by side */
extern u8 CARDGAME_panelLightCluts[8]; /* the clut rows of the panel's blinking lights: 0, 1, 2, 3, 2, 1 */
extern u8 CARDGAME_panelBarSprites[8][2]; /* the sprites of the panel's two bars, by LANGUAGE (USA: 1) */
extern u8 CARDGAME_flag7Frames[]; /* the frames of the panel's sprites for flags 7, 6 and 5 and its five flag icons (CARDGAME_flagIconSprites), when the flag is set: 0, 1, 2, 1, 0 */
extern u8 CARDGAME_flag6Frames[];
extern u8 CARDGAME_boxFrames[];
extern u8 CARDGAME_flagIconSprites[]; /* the sprites of the panel's five flag icons */
extern u8 CARDGAME_flagIconFrames[];
void CARDGAME_sortOpponentHand(CardBattle *battle);
void CARDGAME_findOpponentDeckLimits(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_stepHidePanels(CardBattle *battle, CardBattleItems *items);
void CARDGAME_startPileCount(CardBattle *battle, CardBattleItems *items, s32 side, s32 which);
void CARDGAME_layOutPile(CardBattle *battle, CardBattleItems *items, s32 side, s32 which);
void CARDGAME_layOutSlots(CardBattle *battle, CardBattleItems *items);
void CARDGAME_startStepFade(CardBattle *battle, CardBattleItems *items);
void CARDGAME_resetSpriteFlags(CardBattle *battle);
s32 CARDGAME_runFirstPick(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_runStartStep(CardBattle *battle, CardBattleItems *items);
void CARDGAME_prepareTurn(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_chooseDeck(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_playRounds(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_runPutOut(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_endRound(CardBattle *battle, CardBattleItems *items);
void CARDGAME_removeMarkedHandCards(CardBattle *battle, CardPile *pile);
s32 CARDGAME_setAllCountingValues(CardBattle *battle);
void CARDGAME_sumSlotValues(CardBattle *battle, s32 side);
s32 CARDGAME_findCardSet(CardBattle *battle, s32 side, s32 index);
void CARDGAME_openPanelsPhase(CardBattle *battle, CardBattleItems *items);
void CARDGAME_returnHandToDeck(CardPile *pile);
void CARDGAME_startNextRound(CardBattle *battle, CardBattleItems *items);
void CARDGAME_startBattleMessage(CardBattle *battle, CardBattleItems *items);
void CARDGAME_initBattle(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_stepShowPanels(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_showPlayedCard(CardBattle *battle, CardBattleItems *items);
s32 CARDGAME_runBattle(CardBattle *battle, CardBattleItems *items);
void CARDGAME_drawFader(CardFader *fader, RECT rect);
void CARDGAME_stepFader(CardFader *fader);
void CARDGAME_setFaderColor(CardFader *fader, u8 r, u8 g, u8 b);
void CARDGAME_startFade(CardFader *fader, u8 r, u8 g, u8 b, s32 frames, s32 killWhenDone);
s32 CARDGAME_isFadeDone(CardFader *fader);
void CARDGAME_killFader(CardFader *fader);
void CARDGAME_tickFader(CardFader *fader);
CardFader *CARDGAME_createFader(u8 blend);
void CARDGAME_keepLowestSlot(CardBattle *battle, s32 side);
s32 CARDGAME_targetFlaggedSlot(CardBattle *battle, s32 side);
s32 CARDGAME_targetColor3Slot(CardBattle *battle, s32 side);
s32 CARDGAME_targetColor4Slot(CardBattle *battle, s32 side);
s32 CARDGAME_isSlotWithin(CardBattle *battle, s32 side, s32 index, s32 value);
s32 CARDGAME_getCardLimit(CardBattle *battle, s32 id);
s32 CARDGAME_getCardBonus(CardBattle *battle, s32 id);
s32 CARDGAME_pickComputerTarget(CardBattle *battle, CardScreen *screen, s32 id);
s32 CARDGAME_findOpponentHandKind(CardBattle *battle, s32 kind);
s32 CARDGAME_checkComputerCondition(CardBattle *battle, CardScreen *screen, s32 id);
s32 CARDGAME_compareCards(CardBattle *battle, s32 id1, s32 id2, s32 flip);
s32 CARDGAME_pickComputerCard(CardBattle *battle, CardScreen *screen);
s32 CARDGAME_takeFlaggedCard(CardBattle *battle, CardBattleItems *items);
void CARDGAME_flagTargetSlots(CardBattle *battle, CardScreen *screen);

#endif /* CARDGAME_H */
