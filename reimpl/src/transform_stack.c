#include "game.h"

/*
 * transform_stack.c -- Display object transform stack operations
 *
 * Hand-translated from binary at 0x06026DBC, 0x06026E02, 0x06026E0C.
 *
 * Functions:
 *   FUN_06026DBC (0x06026DBC) -- Push transform (copy + advance)
 *   FUN_06026E02 (0x06026E02) -- Reset stack + init identity
 *   FUN_06026E0C (0x06026E0C) -- Init identity matrix
 *
 * OBJ_STATE_PRIMARY is a pointer to a 48-byte transform block
 * (3x4 matrix: 3x3 rotation + 3 translation ints). These functions
 * manage a stack of such blocks by advancing/retreating the pointer.
 *
 * Called from car_position_update.c and race_init.c.
 */

/* Fixed-point 1.0 in 16.16 format */
#define FP_ONE  0x00010000

/* Initial/base value for the transform stack pointer */
#define TRANSFORM_STACK_BASE  0x06089EE0


/* ================================================================
 * FUN_06026DBC -- Push Transform Block (0x06026DBC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026DBC-0x06026DF6)
 * Pool verified:
 *   0x06027068 = 0x06089EDC (&OBJ_STATE_PRIMARY)
 *
 * Algorithm:
 *   1. src = OBJ_STATE_PRIMARY (current block)
 *   2. dst = src + 48
 *   3. OBJ_STATE_PRIMARY = dst (advance pointer)
 *   4. Copy 48 bytes (12 ints) from src to dst
 *
 * 29 instructions. Leaf function (no saves, no calls).
 * ================================================================ */
void FUN_06026DBC(void)
{
    volatile int *src = (volatile int *)(int)OBJ_STATE_PRIMARY;
    volatile int *dst = src + 12;  /* +48 bytes */
    OBJ_STATE_PRIMARY = (int)dst;

    dst[0]  = src[0];  dst[1]  = src[1];
    dst[2]  = src[2];  dst[3]  = src[3];
    dst[4]  = src[4];  dst[5]  = src[5];
    dst[6]  = src[6];  dst[7]  = src[7];
    dst[8]  = src[8];  dst[9]  = src[9];
    dst[10] = src[10]; dst[11] = src[11];
}


/* ================================================================
 * FUN_06026E0C -- Init Identity Matrix (0x06026E0C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026E0C-0x06026E2C)
 * Pool verified:
 *   0x06027068 = 0x06089EDC (&OBJ_STATE_PRIMARY)
 *   0x0602707C = 0x00010000 (fixed-point 1.0)
 *
 * Writes a 3x4 identity transform (48 bytes) at the current
 * OBJ_STATE_PRIMARY position:
 *   [1.0, 0, 0, 0,  0, 1.0, 0, 0,  0, 0, 1.0, 0]
 *
 * 17 instructions. Leaf function.
 * ================================================================ */
void FUN_06026E0C(void)
{
    volatile int *m = (volatile int *)(int)OBJ_STATE_PRIMARY;

    m[0]  = FP_ONE; m[1]  = 0; m[2]  = 0; m[3]  = 0;
    m[4]  = FP_ONE; m[5]  = 0; m[6]  = 0; m[7]  = 0;
    m[8]  = FP_ONE; m[9]  = 0; m[10] = 0; m[11] = 0;
}


/* ================================================================
 * FUN_06026E02 -- Reset Transform Stack + Init Identity (0x06026E02)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026E02-0x06026E2C)
 * Pool verified:
 *   0x0602706C = 0x06089EE0 (transform stack base)
 *   0x06027068 = 0x06089EDC (&OBJ_STATE_PRIMARY)
 *   0x0602707C = 0x00010000 (fixed-point 1.0)
 *
 * Alternate entry point: resets OBJ_STATE_PRIMARY to base address
 * (0x06089EE0) then falls through to FUN_06026E0C's identity init.
 * In C, implemented as: set pointer + write identity.
 *
 * ~8 unique instructions. Leaf function.
 * ================================================================ */
void FUN_06026E02(void)
{
    OBJ_STATE_PRIMARY = TRANSFORM_STACK_BASE;

    volatile int *m = (volatile int *)TRANSFORM_STACK_BASE;
    m[0]  = FP_ONE; m[1]  = 0; m[2]  = 0; m[3]  = 0;
    m[4]  = FP_ONE; m[5]  = 0; m[6]  = 0; m[7]  = 0;
    m[8]  = FP_ONE; m[9]  = 0; m[10] = 0; m[11] = 0;
}
