#include "common.h"
#include <sys/types.h>
#include <libgte.h>

/*
 * Between pad/pad.c's data and text/text_window.c's, and read by nothing in the
 * executable: a zero vector, the identity (FIGHTSTG's root bone's parent)
 * and three scales that double x, y or both.
 */
VECTOR ZERO_VECTOR = { 0, 0, 0 };
MATRIX IDENTITY_MATRIX = { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } };
MATRIX DOUBLE_WIDTH_MATRIX = { { { 0x2000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } };
MATRIX DOUBLE_HEIGHT_MATRIX = { { { 0x1000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } };
MATRIX DOUBLE_SIZE_MATRIX = { { { 0x2000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } };
