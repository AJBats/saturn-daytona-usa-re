#include "game.h"

/*
 * callback_dispatch.c -- Event notification callback dispatch
 *
 * Hand-translated from binary at 0x0603B93C (23 instructions).
 *
 * Functions:
 *   FUN_0603b93c (0x0603B93C) -- Dispatch event callback
 *
 * Loads a callback descriptor from a global data block at
 * *(0x060A4D14) + 0xB8. The descriptor has three fields:
 *   [0] = callback function pointer
 *   [4] = context parameter
 *   [8] = event argument (written by this function)
 *
 * If arg is non-zero and callback is non-NULL, calls
 * callback(context, arg). Always stores arg and returns it.
 *
 * Called extensively from the object system (batch_obj_system_3a.c)
 * with negative event IDs (-1, -2, -7, -8, etc.) and 0 for reset.
 */

/* Indirect pointer to data block */
#define DATA_BLOCK_PTR    (*(volatile int *)0x060A4D14)
#define CALLBACK_OFFSET   0xB8


/* ================================================================
 * FUN_0603b93c -- Event Callback Dispatch (0x0603B93C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0603B93C-0x0603B968)
 * Pool verified:
 *   0x0603B988 = 0x060A4D14 (data block pointer)
 *   0x0603B986 = 0x00B8 (callback struct offset)
 *
 * Algorithm:
 *   1. cb = *(0x060A4D14) + 0xB8
 *   2. cb[2] = arg (store event arg)
 *   3. If arg != 0 and cb[0] != 0:
 *      call cb[0](cb[1], arg)
 *   4. Return arg
 *
 * 23 instructions. Saves PR, r13, r14.
 * ================================================================ */
int FUN_0603b93c(int arg)
{
    volatile int *cb = (volatile int *)(DATA_BLOCK_PTR + CALLBACK_OFFSET);

    /* Always store event argument at cb+8 */
    cb[2] = arg;

    if (arg != 0 && cb[0] != 0) {
        /* Call callback(context, arg) */
        ((void (*)(int, int))cb[0])(cb[1], arg);
    }

    return arg;
}
