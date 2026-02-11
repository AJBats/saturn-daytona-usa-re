#include "game.h"

/*
 * road_recovery.c -- Off-road detection and position recalibration
 *
 * Hand-translated from binary at 0x0600EA18 (~75 instructions).
 *
 * Functions:
 *   FUN_0600EA18 (0x0600EA18) -- Road recovery system
 *
 * Monitors 4 ground contact flags in the car struct. When all flags
 * are clear (car fully off-road) or after 160 frames of partial
 * off-road, looks up the nearest checkpoint position and computes
 * per-frame correction values to guide the car back on track.
 *
 * Called from physics_entry.c (E4F2 path).
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))

/* Collision/ground contact flags: 4 quadrants at car+0x120..0x12C */
#define CONTACT_FLAG_0  0x120
#define CONTACT_FLAG_1  0x124
#define CONTACT_FLAG_2  0x128
#define CONTACT_FLAG_3  0x12C

/* Car struct field for checkpoint segment index */
#define CAR_SEGMENT_BASE_IDX  0x01EC   /* different from CAR_SEGMENT_BASE_IDX (0x1E4) */

/* Off-road frame counter */
#define RECOVERY_COUNTER    (*(volatile int *)0x0605A228)

/* Checkpoint data table base pointer */
#define CHECKPOINT_TABLE    (*(volatile int *)0x0607EB88)

/* Correction output registers */
#define CORR_STRENGTH       (*(volatile int *)0x060786BC)
#define CORR_DELTA_X        (*(volatile int *)0x060786C0)
#define CORR_DELTA_Z        (*(volatile int *)0x060786C4)
#define CORR_HEADING        (*(volatile short *)0x060786C8)

/* Recovery threshold (frames off-road before recalibration) */
#define RECOVERY_THRESHOLD  160


/* ================================================================
 * FUN_0600EA18 -- Road Recovery / Position Recalibration (0x0600EA18)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600EA18-0x0600EAF8)
 * Pool verified:
 *   0x0600EA76 = 0x0120 (contact flag offset)
 *   0x0600EA78 = 0x00A0 (160 frame threshold)
 *   0x0600EA7C = 0x0605A228 (recovery counter)
 *   0x0600EB00 = 0x0607EB88 (checkpoint table pointer)
 *   0x0600EB04 = 0x060786BC (correction strength)
 *   0x0600EB08 = 0x060786C0 (X correction)
 *   0x0600EB0C = 0x060786C4 (Z correction)
 *   0x0600EB10 = 0x060786C8 (heading correction)
 * Word pool:
 *   0x0600EAFA = 0x01EC (checkpoint index offset)
 *   0x0600EAFC = 0x00E0 (velocity field offset)
 *
 * Algorithm:
 *   1. Read 4 contact flags at car+0x120..0x12C
 *   2. any_set = OR of all 4, all_set = AND of all 4
 *   3. If no flags set or all have bit 7: recalibrate immediately
 *   4. If specific collision bits (0x33 mask) set: clear counter, return
 *   5. Otherwise: count frames. After 160: recalibrate
 *   6. Recalibration: compute (checkpoint_pos - car_pos) >> 4 as
 *      per-frame correction, clear velocities, reset contact flags
 *
 * ~75 instructions. Leaf function (no PR save). 12 bytes stack.
 * ================================================================ */
void FUN_0600EA18(int car)
{
    /* Phase 1: Read ground contact flags from 4 quadrants */
    int f0 = CAR_INT(car, CONTACT_FLAG_0);
    int f1 = CAR_INT(car, CONTACT_FLAG_1);
    int f2 = CAR_INT(car, CONTACT_FLAG_2);
    int f3 = CAR_INT(car, CONTACT_FLAG_3);

    int any_set = f0 | f1 | f2 | f3;
    int all_set = f0 & f1 & f2 & f3;

    /* Phase 2: Classify collision state */
    if (any_set == 0) {
        /* No ground contact at all: recalibrate immediately */
        RECOVERY_COUNTER = 0;
        goto recalibrate;
    }

    if (all_set & 0x80) {
        /* All quadrants have bit 7 set: recalibrate */
        RECOVERY_COUNTER = 0;
        goto recalibrate;
    }

    if (any_set & 0x33) {
        /* Specific collision type detected: clear counter, return */
        RECOVERY_COUNTER = 0;
        return;
    }

    /* Partial off-road: increment counter */
    {
        int count = RECOVERY_COUNTER + 1;
        RECOVERY_COUNTER = count;
        if (count < RECOVERY_THRESHOLD)
            return;

        /* Threshold reached: recalibrate */
        RECOVERY_COUNTER = 0;
    }

recalibrate:
    /* Phase 3: Look up nearest checkpoint and compute corrections */
    {
        int checkpoint_idx = CAR_INT(car, CAR_SEGMENT_BASE_IDX);
        int checkpoint_base = CHECKPOINT_TABLE;

        /* Checkpoint entry offset: (index * 8 + 3) * 16 */
        int entry_addr = checkpoint_base + (checkpoint_idx * 8 + 3) * 16;

        int chk_x = *(volatile int *)entry_addr;
        int chk_z = *(volatile int *)(entry_addr + 4);
        int chk_heading = *(volatile short *)(entry_addr + 0xA);

        int car_x = CAR_INT(car, 0x10);
        int car_z = CAR_INT(car, 0x18);
        int car_hdg = CAR_INT(car, 0x30);

        /* Compute deltas and divide by 16 (>> 4) for per-frame correction */
        int delta_x = (chk_x - car_x) >> 4;
        int delta_z = (chk_z - car_z) >> 4;
        int delta_heading = (short)(((chk_heading << 2) - car_hdg) >> 4);

        /* Store correction values */
        CORR_STRENGTH = 16;
        CORR_DELTA_X = delta_x;
        CORR_DELTA_Z = delta_z;
        CORR_HEADING = delta_heading;

        /* Phase 4: Clear car velocity/state fields */
        CAR_INT(car, 0x0C) = 0;
        CAR_INT(car, 0x08) = 0;
        CAR_INT(car, 0xE0) = 0;
        CAR_INT(car, 0xE4) = 0;

        /* Reset contact flags to 1 (on-road) */
        CAR_INT(car, CONTACT_FLAG_0) = 1;
        CAR_INT(car, CONTACT_FLAG_1) = 1;
        CAR_INT(car, CONTACT_FLAG_2) = 1;
        CAR_INT(car, CONTACT_FLAG_3) = 1;
    }
}
