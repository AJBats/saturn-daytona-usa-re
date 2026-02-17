/*
 * vdp_utils.c -- VDP1/VDP2 utility functions
 *
 * Translated from production ASM / existing decomp src/*.c
 */

#include "saturn.h"

/* FUN_060394C2 -- Wait for VDP1 draw end */
void FUN_060394C2(void)
{
    do {
    } while ((VDP1_EDSR & 2) == 0);
}

/* FUN_0601164A -- Set VDP2 scroll screen parameters
 * Writes to VDP2 register area:
 *   0x25F800A4 (LSTA1L/LSTA1U region) = 0x12F2FC00
 *   0x25F8009A (line scroll control?) = 0x0200
 */
void FUN_0601164A(void)
{
    *(volatile int *)0x25F800A4 = 0x12F2FC00;
    *(volatile short *)0x25F8009A = 0x0200;
}
