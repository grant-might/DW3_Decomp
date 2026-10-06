#ifndef DW3_SOUND_H
#define DW3_SOUND_H

/* Sound banks (sound.c) */

#include "common.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

/*
 * Sound ids pack everything needed to play them:
 *   bit 31     a key-on of one VAB tone (sound effect), else a SEP sequence
 *   bit 30     exclusive (music): stops the previous exclusive sound
 *   bits 18-24 the sound bank id (see findSoundBank)
 *   key-on:    program bits 11-17, tone bits 7-10, note bits 0-6
 *   sequence:  SEQ bits 8-15, track (SEP) bits 0-7
 */

/* Sounds the overlays share, with SOUNDTST's names */
#define SOUND_SELECT 0x8004503C /* SYSTEM00: a choice is taken */
#define SOUND_MENU_CANCEL 0x800450BD /* SYSTEM01 */
#define SOUND_CURSOR 0x8004513E /* SYSTEM02: a cursor moves */
#define SOUND_MENU_OPEN 0x40019 /* SYSTEM03 */
#define SOUND_MENU_CLOSE 0x4001A /* SYSTEM04 */
#define SOUND_MENU_MOVE 0x4001B /* SYSTEM06 */
#define SOUND_MENU_CONFIRM 0x4001C /* SYSTEM07 */
#define SOUND_COUNT 0x800452C6 /* SYSTEM10: a number counts up or down */
#define SOUND_RECOVERY 0x40014 /* RECOVERY */
#define SOUND_TELEPORT 0x4001D /* TELEPORT */
#define SOUND_WIN_JINGLE 0x6004001E /* W_JINGLE: a battle won */

/* One of the three loaded sound banks: a VAB and its SEP sequences */
typedef struct SoundBank {
    /* 0x00 */ s32 id;
    /* 0x04 */ s16 vabId;
    /* 0x06 */ s16 numSeqs;
    /* 0x08 */ s16 seqs[4];
    /* 0x10 */ s32 headBuffer; /* VAB header and SEPs are copied here */
    /* 0x14 */ s32 spuAddr;
} SoundBank;

/* A bank's files (SOUND_BANK_FILES[id]) */
typedef struct SoundFiles {
    /* 0x00 */ s32 bodyFile; /* VAB body, sent to the SPU */
    /* 0x04 */ s32 headFile; /* archive: VAB header and SEPs */
    /* 0x08 */ s32 vhIndex; /* of the VAB header in headFile */
    /* 0x0C */ s32 bodyEntry; /* (file << 16) | slot */
    /* 0x10 */ s32 seps[0]; /* indices in headFile, 0-terminated */
} SoundFiles;

/* Loads a bank in the background (updateSoundLoading) */
typedef struct SoundLoader {
    /* 0x0 */ SoundFiles *files;
    /* 0x4 */ s16 state; /* 0 idle, 1 header, 2 body, 3 transfer */
    /* 0x6 */ s16 slot;
} SoundLoader;

/* The sound engine (SOUND) */
typedef struct SoundState {
    /* 0x0000 */ u8 seqTable[0x4200]; /* SsSetTableSize(6 SEQs, 16 SEPs) */
    /* 0x4200 */ SoundBank banks[3];
    /* 0x4248 */ s32 music; /* the exclusive sound playing */
    /* 0x424C */ s32 lastSlot;
    /* 0x4250 */ SoundLoader loader;
    /* 0x4258 */ void (*init)(void);
    /* 0x425C */ short (*playSound)(s32 id); /* returns the voice of a key-on */
    /* 0x4260 */ short (*keyOn)(s32 slot, short prog, short note);
    /* 0x4264 */ void (*keyOff)(s32 id, s16 voice);
    /* 0x4268 */ void (*loadBank)(s32 id);
    /* 0x426C */ void (*loadBankInto)(s32 slot, s32 id);
    /* 0x4270 */ void (*updateLoading)(void);
    /* 0x4274 */ s32 (*isLoading)(void);
    /* 0x4278 */ void (*stopAll)(void);
    /* 0x427C */ void (*stopSound)(s32 id);
    /* 0x4280 */ void (*fadeOut)(s32 id);
} SoundState;

s32 findSoundBank(s32 id);
s32 playSound(s32 packed);
void stopAllSounds(void);
void stopSound(s32 packed);
void fadeOutSound(s32 packed);
s32 isSoundLoading(void);
void loadSoundBankInto(s32 index, s32 id);
void loadSoundBank(s32 id);
void updateSoundLoading(void);
short soundKeyOn(s32 slot, short prog, short note);
void soundKeyOff(s32 packed, s16 voice);
void initSound(void);

extern SoundState SOUND;
extern SoundFiles *SOUND_BANK_FILES[];
extern s32 SOUND_SPU_ADDRS[];
extern s32 SOUND_HEAD_BUFFERS[];
extern s32 SOUND_HEAD_BUFFER_0[];
extern s32 SOUND_HEAD_BUFFER_1[];
extern s32 SOUND_HEAD_BUFFER_2[];

#endif /* DW3_SOUND_H */
