#ifndef GAME_H
#define GAME_H

#include "common.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libcd.h>

#include "dw3/task.h"
#include "dw3/heap.h"
#include "dw3/gfx.h"
#include "dw3/file.h"
#include "dw3/pad.h"
#include "dw3/random.h"
#include "dw3/sound.h"
#include "dw3/overlay.h"
#include "dw3/text.h"
#include "dw3/game_state.h"
#include "dw3/memcard.h"
#include "dw3/menu.h"

/* SDK functions declared here rather than from their PsyQ headers:
   strings.h and memory.h declare these without prototypes, strlen as
   unsigned */
int strlen(const char *);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, s32 n);
void *memcpy(void *dst, const void *src, int size);

/* The kernel's file functions (libapi.h); the sim: device is the PC's */
long open(char *name, unsigned long mode);
long read(long fd, void *buf, long n);
long write(long fd, void *buf, long n);
long close(long fd);

#endif /* GAME_H */
