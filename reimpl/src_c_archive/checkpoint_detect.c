#include "game.h"

/* Per-file car struct access macros */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))

/*
 * checkpoint_detect.c -- Checkpoint crossing angular detection
 *
 * Hand-translated from binary at 0x0600DA7C (73 instructions).
 *
 * Functions:
 *   FUN_0600DA7C (0x0600DA7C) -- Checkpoint crossing detection
 *
 * Determines whether the current car's heading angles fall within
 * the checkpoint's angular acceptance zone. Uses the checkpoint
 * entry's half-width (entry[0x0E]) * 4 as angular offset, then
 * checks if both CAR_HEADING2 and CAR_HEADING minus this offset
 * are within [90°, 270°] (the back-facing semicircle).
 *
 * On crossing detected: sets bit 3 of car flags, increments
 * counter, sets flag, tail-calls FUN_0600DBA0 (threshold=4).
 * On not detected: clears bit 3, clears counters, tail-calls
 * FUN_0600DC74.
 *
 * Called from physics_entry.c.
 */

/* External dependencies */
extern void FUN_06034F78(int val, int param, int ptr);  /* bitfield write */
extern void FUN_0600DBA0(int threshold);  /* checkpoint continuation (threshold check) */
extern void FUN_0600DC74(void);           /* checkpoint not-crossed path */

/* Detection state globals */
#define DETECT_FLAG_PTR    ((volatile unsigned short *)0x0607869A)
#define DETECT_COUNTER_PTR ((volatile unsigned short *)0x06078698)

/* Checkpoint entry size */
#define CHECKPOINT_ENTRY_SIZE  24

/* Angular thresholds */
#define ANGLE_90   0x4000   /* 90 degrees in 16-bit angle format */
#define ANGLE_270  0xC000   /* 270 degrees in 16-bit angle format */


/* ================================================================
 * FUN_0600DA7C -- Checkpoint Crossing Detection (0x0600DA7C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600DA7C-0x0600DB62)
 * Pool verified:
 *   0x0600DB48 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600DB4C = 0x0607869A (detection flag, short)
 *   0x0600DB50 = 0x06078698 (detection counter, short)
 *   0x0600DB54 = 0x06034F78 (bitfield write)
 *   0x0600DB58 = 0x0000C000 (270-degree threshold)
 * Word pool:
 *   0x0600DB40 = 0x00B8 (CAR_STEER_TIMER)
 *   0x0600DB42 = 0x1C01 (bitfield param: bit_pos=28, count=1 → bit 3)
 *   0x0600DB44 = 0x01E4 (CAR_CHECKPOINT_IDX)
 *   0x0600DB46 = 0x4000 (90-degree threshold)
 *
 * Algorithm:
 *   1. If steer_timer != 0:
 *      a. If detection flag == 0: return (no crossing during shift)
 *      b. Else: mark crossing (set bit 3), increment counter,
 *         tail-call FUN_0600DBA0 (with threshold r3=4)
 *   2. If steer_timer == 0:
 *      a. Compute checkpoint entry from idx and table base
 *      b. half_width = entry[0x0E], threshold = hw * 4
 *      c. diff1 = (heading2 - threshold) & 0xFFFF
 *      d. diff2 = (heading - threshold) & 0xFFFF
 *      e. PASS if 90° <= diff1 <= 270° AND 90° <= diff2 <= 270°
 *      f. PASS: set bit 3, increment counter, set flag, tail FUN_0600DBA0
 *      g. FAIL: clear bit 3, zero counters, tail FUN_0600DC74
 *
 * 73 instructions (0x0600DA7C-0x0600DB62). Saves r14, PR.
 * Uses 8 bytes of stack for local temps.
 * ================================================================ */
void FUN_0600DA7C(void)
{
    int car = CAR_PTR_CURRENT;

    if (CAR_INT(car, CAR_STEER_TIMER) != 0) {
        /* Gear shift active: maintain existing crossing state */
        if ((unsigned short)*DETECT_FLAG_PTR == 0)
            return;

        /* Already crossing — keep bit set and count */
        FUN_06034F78(1, 0x1C01, car);
        *DETECT_COUNTER_PTR = *DETECT_COUNTER_PTR + 1;
        FUN_0600DBA0(4);  /* tail-call: continuation with threshold=4 */
        return;
    }

    /* No gear shift: perform angular crossing detection */
    {
        int chk_idx = CAR_INT(car, CAR_CHECKPOINT_IDX);
        int table_base = CAR_INT(car, CAR_CHECKPOINT_BASE);
        int entry = table_base + chk_idx * CHECKPOINT_ENTRY_SIZE;

        /* Half-width from checkpoint entry, scaled by 4 */
        int half_width = (int)*(volatile short *)(entry + 0x0E);
        int threshold = half_width << 2;

        /* Angular differences (unsigned 16-bit wrap) */
        unsigned short diff1 = (unsigned short)(CAR_INT(car, CAR_HEADING2) - threshold);
        unsigned short diff2 = (unsigned short)(CAR_INT(car, CAR_HEADING) - threshold);

        /* Check if both angles are in back-facing semicircle [90°, 270°] */
        int pass = (diff1 >= ANGLE_90 && diff1 <= ANGLE_270 &&
                    diff2 >= ANGLE_90 && diff2 <= ANGLE_270);

        if (!pass) {
            /* Not crossing: clear state */
            FUN_06034F78(0, 0x1C01, car);
            *DETECT_COUNTER_PTR = 0;
            *DETECT_FLAG_PTR = 0;
            FUN_0600DC74();  /* tail-call: not-crossed continuation */
            return;
        }

        /* Crossing detected: set state */
        FUN_06034F78(1, 0x1C01, car);
        *DETECT_COUNTER_PTR = *DETECT_COUNTER_PTR + 1;
        *DETECT_FLAG_PTR = 1;
        FUN_0600DBA0(4);  /* tail-call: continuation with threshold=4 */
    }
}
