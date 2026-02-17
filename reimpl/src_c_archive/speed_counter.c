#include "game.h"

/*
 * speed_counter.c -- Engine sound frequency counter
 *
 * Hand-translated from binary at 0x0600A8BC (33 instructions).
 *
 * Functions:
 *   FUN_0600A8BC (0x0600A8BC) -- Speed-based audio timing counter
 *
 * Updates a 4-bit counter at 0x06063F46 based on car speed.
 * The counter increments by 1, 2, or 4 depending on speed threshold,
 * then wraps to 4 bits (0-15). This drives engine sound pitch.
 *
 * Called from car_iteration.c (post-loop audio update) and
 * physics_entry.c (physics pipeline audio step).
 */


/* ================================================================
 * FUN_0600A8BC -- Speed-Based Audio Counter (0x0600A8BC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A8BC-0x0600A8FE)
 * Pool verified:
 *   0x0600A90C = 0x06063F46 (counter address, word)
 *   0x0600A910 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600A900 = word 0x00C8 (200, high speed threshold)
 *
 * Algorithm:
 *   1. If car[0xC] (accel/distance) == 0: clear counter, return
 *   2. If speed < 100: increment counter by 1
 *   3. If 100 <= speed < 200: increment counter by 2
 *   4. If speed >= 200: increment counter by 4
 *   5. Mask counter to low 4 bits (0-15)
 *
 * 33 instructions. No callee-saved registers (leaf function).
 * ================================================================ */
void FUN_0600A8BC(void)
{
    volatile short *counter = (volatile short *)0x06063F46;
    int car = CAR_PTR_CURRENT;
    int accel = *(volatile int *)((char *)car + CAR_ACCEL);

    if (accel == 0) {
        *counter = 0;
        return;
    }

    {
        int speed = *(volatile int *)((char *)car + CAR_SPEED);

        if (speed < 100) {
            *counter = *counter + 1;
        } else if (speed < 200) {
            *counter = *counter + 2;
        } else {
            *counter = *counter + 4;
        }

        *counter = *counter & 0x0F;
    }
}
