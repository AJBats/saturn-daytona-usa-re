#include "game.h"

/*
 * timer_update.c -- Per-car timer management (countdown + decrement)
 *
 * Hand-translated from build/aprog.s binary, verified instruction-by-instruction.
 * These are unlabeled functions (no symbol in aprog_syms.txt) called via pool
 * constants from the per-car iteration loop (FUN_0600E0C0).
 *
 * Functions:
 *   FUN_06030A06 (0x06030A06) -- Countdown timer trigger
 *   FUN_06030EE0 (0x06030EE0) -- Simple timer decrement
 *
 * Both read the car pointer from the global at 0x0607E940.
 * Called once per car per frame during racing.
 *
 * Original addresses: 0x06030A06, 0x06030EE0
 */


/* ================================================================
 * FUN_06030EE0 -- Timer Decrement (0x06030EE0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06030EE0-0x06030EF2)
 * Pool verified:
 *   0x06030EF4 = 0x0150 (timer offset, word pool)
 *   0x06030EF8 = 0x0607E940 (car pointer global)
 *
 * Reads word at car[0x150], decrements if positive, writes back.
 * 7 instructions total. LEAF function.
 * ================================================================ */
void FUN_06030EE0(void)
{
    int car = *(volatile int *)0x0607E940;
    short t = *(volatile short *)((char *)car + 0x150);

    if (t > 0)
        *(volatile short *)((char *)car + 0x150) = t - 1;
}


/* ================================================================
 * FUN_06030A06 -- Countdown Timer Trigger (0x06030A06)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06030A06-0x06030A3C)
 * Pool verified:
 *   0x06030A3E = 0x0250 (countdown offset, word pool)
 *   0x06030A40 = 0x0080 (flag store offset)
 *   0x06030A42 = 0x0160 (flags check offset)
 *   0x06030A44 = 0x01E4 (copy destination offset)
 *   0x06030A46 = 0x01EC (copy source offset)
 *   0x06030A48 = 0x0607E940 (car pointer global)
 *   0x06030A4C = 0xFFFF0000 (flag value)
 *   0x06030A50 = 0x00200000 (bit mask for flag check)
 *
 * Algorithm:
 *   1. Read countdown at car[0x250] (word)
 *   2. If zero: return (inactive)
 *   3. Decrement countdown, store back
 *   4. If still non-zero: return (not triggered yet)
 *   5. On trigger (countdown reaches 0):
 *      a. Write 0xFFFF0000 to car[0x80]
 *      b. Check bit 0x200000 in car[0x160]
 *      c. If set: copy car[0x1EC] → car[0x1E4]
 *      d. If set: copy car[0x30] → car[0x28]
 *
 * 27 instructions total. LEAF function.
 * ================================================================ */
void FUN_06030A06(void)
{
    int car = *(volatile int *)0x0607E940;
    short countdown = *(volatile short *)((char *)car + 0x250);

    if (countdown == 0)
        return;

    countdown--;
    *(volatile short *)((char *)car + 0x250) = countdown;

    if (countdown != 0)
        return;

    /* Countdown just reached zero: trigger state change */
    *(volatile int *)((char *)car + 0x80) = (int)0xFFFF0000;

    /* Check activation flag at car[0x160] */
    if (!(*(volatile int *)((char *)car + 0x160) & 0x00200000))
        return;

    /* Copy state: car[0x1EC] → car[0x1E4] */
    *(volatile int *)((char *)car + 0x1E4) =
        *(volatile int *)((char *)car + 0x1EC);

    /* Copy speed/heading: car[0x30] → car[0x28] */
    *(volatile int *)((char *)car + 0x28) =
        *(volatile int *)((char *)car + 0x30);
}
