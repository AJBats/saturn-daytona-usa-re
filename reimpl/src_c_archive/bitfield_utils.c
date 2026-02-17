#include "game.h"

/*
 * bitfield_utils.c -- Bitfield read/write utilities
 *
 * Hand-translated from DEFINITE-confidence annotated ASM
 * (asm/lap_counting.s lines 661-756) and verified
 * instruction-by-instruction against build/aprog.s at 0x06034F78.
 *
 * Functions:
 *   FUN_06034F78 (0x06034F78) -- Bitfield write utility
 *
 * NOTE: The original binary uses a non-standard calling convention
 * (r0=value, r1=param, r2=ptr). Our C implementation uses standard
 * SH-2 C convention (r4=value, r5=param, r6=ptr) since all callers
 * are hand-translated C code that already uses this convention.
 */


/* ================================================================
 * FUN_06034F78 -- Bitfield Write Utility (0x06034F78)
 *
 * CONFIDENCE: DEFINITE (lap_counting.s lines 685-756)
 * Every instruction verified. Loop-based mask construction,
 * position shifting, and read-modify-write all confirmed.
 *
 * General-purpose function for writing values into specific bit
 * fields of 32-bit words. Used extensively for car struct flags.
 *
 * Parameters:
 *   val   = value to write (truncated to bit_count bits)
 *   param = packed: high_byte = bit_position (from MSB),
 *                   low_byte  = bit_count
 *   ptr   = pointer to 32-bit word to modify
 *
 * The actual bit position in the word is:
 *   shift = 32 - bit_count - bit_position
 *
 * Examples (verified against binary call sites):
 *   param=0x1501 → bit_pos=21, count=1, shift=10 → sets/clears bit 10
 *   param=0x1C01 → bit_pos=28, count=1, shift=3  → sets/clears bit 3
 *   param=0x0301 → bit_pos=3,  count=1, shift=28 → sets/clears bit 28
 *   param=0x0201 → bit_pos=2,  count=1, shift=29 → sets/clears bit 29
 *   param=0x0101 → bit_pos=1,  count=1, shift=30 → sets/clears bit 30
 *   param=0x0001 → bit_pos=0,  count=1, shift=31 → sets/clears bit 31
 * ================================================================ */
void FUN_06034F78(int val, int param, int ptr)
{
    unsigned int bit_pos = (param >> 8) & 0xFF;
    unsigned int bit_count = param & 0xFF;
    unsigned int shift = 32 - bit_count - bit_pos;
    unsigned int field_mask;
    unsigned int current;

    /* Build a bit_count-wide mask, shift to target position */
    field_mask = ((1u << bit_count) - 1) << shift;

    /* Truncate value to bit_count bits, shift to position */
    val = val & (int)((1u << bit_count) - 1);

    /* Read-modify-write */
    current = *(volatile unsigned int *)ptr;
    current = (current & ~field_mask) | ((unsigned int)val << shift);
    *(volatile unsigned int *)ptr = current;
}
