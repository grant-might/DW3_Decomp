#ifndef DW3_FILES_H
#define DW3_FILES_H

/* The disc file table, the CD reader and the file cache (system.c) */

#include "common.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

/* The disc's file table (FILE_TABLE): files are numbered, not named */
typedef struct FileTableFuncs {
    /* 0x0 */ s32 (*exists)(s32 file);
    /* 0x4 */ s32 (*getSectorCount)(s32 file);
    /* 0x8 */ s32 (*getSector)(s32 file);
    /* 0xC */ void (*getPos)(s32 file, s32 offset, void *loc);
} FileTableFuncs;

/* A file in the cache */
typedef struct FileSlot {
    /* 0x0 */ s16 state; /* 0 free, 1 queued, 2 being read, 3 loaded */
    /* 0x2 */ s16 marked;
    /* 0x4 */ s32 file;
    /* 0x8 */ s32 lastUsed; /* GFX time */
    /* 0xC */ void *data;
} FileSlot;

/* Reads whole sectors of a file with CdlReadN, from callbacks */
typedef struct CdReader {
    /* 0x00 */ s32 state; /* 0 idle, 1 seek, 2 set mode, 3 read, 4 done */
    /* 0x04 */ s32 file;
    /* 0x08 */ s32 offset; /* in sectors */
    /* 0x0C */ s32 sectorCount;
    /* 0x10 */ s32 buffer;
    /* 0x14 */ s32 *done; /* set to 1 when the read is complete */
    /* 0x18 */ u8 loc[4];
    /* 0x1C */ s32 sector;
    /* 0x20 */ s32 sectorsLeft;
    /* 0x24 */ s32 dst;
    /* 0x28 */ s32 nextSector;
    /* 0x2C */ s32 (*isBusy)(void);
    /* 0x30 */ void (*read)(s32 file, s32 offset, s32 size, void *buf, s32 *done);
} CdReader;

/*
 * The file cache (FILE_CACHE): up to 64 files loaded in the heap (tag 3),
 * read in the background one at a time and evicted least recently used
 * first when the heap is full.
 */
typedef struct FileCache {
    /* 0x000 */ s32 pending;
    /* 0x004 */ FileSlot slots[64];
    /* 0x404 */ s32 (*isLoading)(s32 file);
    /* 0x408 */ void (*evictOldest)(void);
    /* 0x40C */ void (*request)(s32 file);
    /* 0x410 */ void (*update)(void);
    /* 0x414 */ char *(*load)(s32 file);
    /* 0x418 */ void (*free)(s32 file);
    /* 0x41C */ void (*freeAll)(void);
    /* 0x420 */ void (*freeFrom)(u32 addr);
    /* 0x424 */ s32 (*getEntry)(s32 fileAndIndex);
    /* 0x428 */ u8 *(*getArchiveEntry)(s32 index, s32 archive);
    /* 0x42C */ void (*markCached)(void);
    /* 0x430 */ void (*touchMarked)(void);
} FileCache;

s32 isFileLoading(s32);
FileSlot *findFileSlot(s32 file);
FileSlot *findFreeFileSlot(void);
FileSlot *findOldestFile(void);
void evictOldestFile(void);
void requestFile(s32);
void updateFileCache(void);
s32 *loadFile(u32 id);
void freeFile(s32 file);
void freeAllFiles(void);
void freeFilesFrom(u32 addr);
s32 getFileEntry(u32 fileAndIndex);
s32 getArchiveEntry(u32 index, s32 *archive);
void markCachedFiles(void);
void touchMarkedFiles(void);
void cdSyncCallback();
s32 cdCheckSector(void);
s32 isCdReading(void);
void startCdRead(void);
void readFile(s32 file, s32 offset, s32 size, s32 buffer, s32 *done);
s32 fileExists(s32 file);
u16 getFileSectorCount(s32 file);
s32 getFileSector(s32 file);
void getFilePos(s32 file, s32 offset, void *pos);

extern FileTableFuncs FILE_TABLE;
extern CdReader CD_READER;
extern u8 CD_SECTOR_HEADER[];
extern FileCache FILE_CACHE;
extern s32 FILE_SECTORS[];
extern u16 FILE_SECTOR_COUNTS[];

/*
 * Files the engine loads by number. The European disc numbers its files
 * differently, and has each text file once per language, in a row:
 * TEXT_FILE() gives the copy of the language the player picked (LANGUAGE,
 * set by CNTY_SEL), copy 1 being at the USA version's number.
 */
#if VERSION_US
#define FILE_MENU_SPRITES 0x277 /* the menu graphics, a sprite sheet */
#define FILE_FONT 0x278
#define TEXT_FILE(file) (file)
#elif VERSION_EU
#define FILE_MENU_SPRITES 0x286
#define FILE_FONT 0x287
#define TEXT_FILE(file) (LANGUAGE + (file) - 1)
extern s32 LANGUAGE; /* 2-5 */
#endif

/* The text files, by their USA disc names (US<name>.BIN), for TEXT_FILE() */
#define TEXT_AMATERASU_MAP 0x02 /* AMTMAP: the map screen's once isLateGame */
#define TEXT_ASUKA_MAP 0x09 /* ASKMAP: the map screen's before */
#define TEXT_CARD_GAME 0x10 /* CARDGM: the card battle's */
#define TEXT_CARD_NAMES 0x17 /* CARDNM */
#define TEXT_CARD_EFFECTS 0x1E /* CARDST */
#define TEXT_CARD_ALBUM 0x25 /* CRDABM: STCRDABM's */
#define TEXT_DECK_EDITOR 0x2C /* CRDDEK */
#define TEXT_CARD_SHOP 0x33 /* CRDSHP: STCRDSHP's, and STCRDDEK's */
#define TEXT_DIGI_LAB 0x3A /* DGLABO: STGDGLAB's */
#define TEXT_DIGIMON_NAMING 0x41 /* DGNMET: STDGNAME's */
#define TEXT_DIGIMON_INFO 0x48 /* DIGINF */
#define TEXT_DIGIMON_NAMES 0x4F /* DIGNAM */
#define TEXT_FIGHT_REPORT 0x56 /* FGTRPT: STFGTREP's */
#define TEXT_INN_NAMES 0x5D /* HTLNAM */
#define TEXT_ITEM_INFO 0x64 /* ITMINF */
#define TEXT_ITEM_NAMES 0x6B /* ITMNAM */
#define TEXT_ITEM_SHOP 0x72 /* ITSHOP: STITSHOP's */
#define TEXT_MEMORY_CARD 0x79 /* MEMCRD */
#define TEXT_BATTLE_MENU 0x80 /* MFIGHT: WFIGHTMN's */
#define TEXT_NAME_ENTRY 0x87 /* NAMEDT: the keyboard's */
#define TEXT_ONLINE 0x8E /* NAMEET: the Digimon Online registration */
#define TEXT_SHOP_NAMES 0x95 /* SHPNAM */
#define TEXT_SKILL_INFO 0x9C /* SKLINF */
#define TEXT_SKILL_NAMES 0xA3 /* SKLNAM */
#define TEXT_AREA_NAMES 0xAA /* STAREA */
#define TEXT_STATUS 0xB1 /* STATUS: the field menu's and STSTATUS's */
#define TEXT_STAGE_NAMES 0xB8 /* STNAME */

/* The battle menu's files (WFIGHTMN, WFIGHTTS): FILE_BATTLE_IMAGES is an
   archive whose entries go through FILE_CACHE.getEntry, the four after it
   are archives of images for VRAM */
#if VERSION_US
#define FILE_BATTLE_MENU 0x445
#define FILE_BATTLE_IMAGES 0x446
#define FILE_BATTLE_IMAGES_1 0x78F
#define FILE_BATTLE_IMAGES_2 0x79F
#define FILE_BATTLE_IMAGES_3 0x7D2
#define FILE_BATTLE_IMAGES_4 0x7D4
#elif VERSION_EU
#define FILE_BATTLE_MENU 0x455
#define FILE_BATTLE_IMAGES 0x456
#define FILE_BATTLE_IMAGES_1 0x79E
#define FILE_BATTLE_IMAGES_2 0x7AE
#define FILE_BATTLE_IMAGES_3 0x7E1
#define FILE_BATTLE_IMAGES_4 0x7E3
#endif

#endif /* DW3_FILES_H */
