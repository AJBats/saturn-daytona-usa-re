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
#if 0 /* FUN_0603B93C -- replaced by ASM import */
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
#endif

/* FUN_0603B93C -- original binary (104 bytes) */
__asm__(
    ".section .text.FUN_0603B93C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603B93C\n"
    ".global _FUN_0603b93c\n"
    ".type _FUN_0603B93C, @function\n"
    "_FUN_0603B93C:\n"
    "_FUN_0603b93c:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0x6D, 0x43, 0xDE, 0x10, 0x93, 0x1E, 0x6E, 0xE2, 0x3E, 0x3C\n"  /* 0x0603B93C */
    ".byte 0x2D, 0xD8, 0x8D, 0x07, 0x1E, 0x42, 0x60, 0xE2, 0x20, 0x08, 0x89, 0x03, 0x65, 0xD3, 0x63, 0xE2\n"  /* 0x0603B94C */
    ".byte 0x43, 0x0B, 0x54, 0xE1, 0x60, 0xD3, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0xD6, 0x07\n"  /* 0x0603B95C */
    ".byte 0x66, 0x62, 0x76, 0x34, 0xA0, 0x0D, 0xE5, 0x00, 0x62, 0x53, 0x63, 0x63, 0x42, 0x08, 0x32, 0x3C\n"  /* 0x0603B96C */
    ".byte 0x62, 0x22, 0x34, 0x20, 0x8B, 0x04, 0xA0, 0x08, 0x00, 0x09, 0x00, 0xB8, 0x06, 0x0A, 0x4D, 0x14\n"  /* 0x0603B97C */
    ".byte 0x75, 0x01, 0xE0, 0x60, 0x02, 0x6E, 0x35, 0x23, 0x8B, 0xEE, 0xE0, 0x60, 0x02, 0x6E, 0x35, 0x20\n"  /* 0x0603B98C */
    ".byte 0x8B, 0x00, 0xE5, 0xFF, 0x00, 0x0B, 0x60, 0x53\n"  /* 0x0603B99C */
);

