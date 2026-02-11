#include "game.h"

/*
 * road_segment_find.c -- Nearest road segment detection
 *
 * Hand-translated from binary at 0x0600C994 (119 instructions).
 *
 * Functions:
 *   FUN_0600C994 (0x0600C994) -- Find nearest road segment
 *
 * Computes angles from the car's position to 8 checkpoint sample
 * points (4 pairs spaced 16 bytes apart in the checkpoint table).
 * Subtracts the road heading (scaled by 4) from each angle, and
 * finds which sample has the smallest angular deviation. The result
 * index (in units of 0x100) is stored at car+0x01FC.
 *
 * Called from the E4F2 physics path.
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))

/* Car struct pointer */
#define CAR_PTR_GLOBAL       (*(volatile int *)0x0607E944)

/* Checkpoint data table base pointer */
#define CHECKPOINT_TABLE     (*(volatile int *)0x0607EB88)

/* Car struct offsets */
#define CAR_POS_X            0x10
#define CAR_POS_Z            0x18
#define CAR_SEGMENT_BASE_IDX 0x01EC   /* different from CAR_SEGMENT_BASE_IDX (0x1E4) */
#define CAR_ROAD_SEGMENT     0x01FC

/* Angular step between sample points (fractional segment index) */
#define ANGLE_STEP           0x0100

/* Number of sample points */
#define NUM_SAMPLES          8

/* atan2(dx, dz) -- returns 16-bit angle */
extern int FUN_0602744C(int dx, int dz);


/* ================================================================
 * FUN_0600C994 -- Find Nearest Road Segment (0x0600C994)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600C994-0x0600CA94)
 * Pool verified:
 *   0x0600C9E4 = 0x01EC (checkpoint index offset)
 *   0x0600C9E6 = 0x0100 (angular step)
 *   0x0600C9EC = 0x0602744C (atan2 function)
 *   0x0600C9F0 = 0x0607EB88 (checkpoint table pointer)
 *   0x0600C9F4 = 0x0607E944 (car struct pointer)
 *   0x0600CAC0 = 0x01FC (road segment result offset)
 *
 * Algorithm:
 *   1. Get next checkpoint index from car[0x01EC] + 1
 *   2. Read road heading from checkpoint entry at offset 0xA
 *   3. Sample 8 angles from car position to consecutive checkpoint
 *      points (pairs at 16-byte intervals, offset by idx * 0x80)
 *   4. For each angle: compute abs(angle - heading*4)
 *   5. Pick sample with smallest deviation; store index at car[0x01FC]
 *
 * 119 instructions. Saves r8-r14, PR. 28 bytes stack (8 shorts + ptrs).
 * ================================================================ */
void FUN_0600C994(void)
{
    int car = CAR_PTR_GLOBAL;
    int idx = CAR_INT(car, CAR_SEGMENT_BASE_IDX) + 1;

    /* Get road heading from checkpoint entry: (idx*8 + 3) * 16 */
    int checkpoint_base = CHECKPOINT_TABLE;
    int entry_addr = checkpoint_base + (idx * 8 + 3) * 16;
    short heading = *(volatile short *)(entry_addr + 0xA);

    /* Correction value: -(heading << 2), wraps in 16-bit domain */
    unsigned short correction = (unsigned short)(-(heading << 2));

    /* Compute data offset: idx * 0x80 */
    int offset = idx * 0x80;

    /* Phase 1: Sample angles from car to 8 checkpoint points */
    short angles[NUM_SAMPLES];
    int i;

    for (i = 0; i < NUM_SAMPLES; i += 2) {
        int pt_addr;
        int car_x, car_z;

        /* First point of pair */
        checkpoint_base = CHECKPOINT_TABLE;
        car_z = CAR_INT(car, CAR_POS_Z);
        car_x = CAR_INT(car, CAR_POS_X);
        pt_addr = checkpoint_base + offset;
        angles[i] = -(short)FUN_0602744C(
            *(volatile int *)pt_addr - car_x,
            *(volatile int *)(pt_addr + 4) - car_z);
        offset += 16;

        /* Second point of pair */
        checkpoint_base = CHECKPOINT_TABLE;
        car_z = CAR_INT(car, CAR_POS_Z);
        car_x = CAR_INT(car, CAR_POS_X);
        pt_addr = checkpoint_base + offset;
        angles[i + 1] = -(short)FUN_0602744C(
            *(volatile int *)pt_addr - car_x,
            *(volatile int *)(pt_addr + 4) - car_z);
        offset += 16;
    }

    /* Phase 2: Find sample with smallest angular deviation from heading */
    {
        int diff = (short)((unsigned short)angles[0] + correction);
        unsigned short best_dist;
        unsigned short best_idx;
        unsigned short step;

        if (diff < 0) diff = -diff;
        best_dist = (unsigned short)diff;
        best_idx = 0;
        step = ANGLE_STEP;

        for (i = 1; i < NUM_SAMPLES; i++) {
            int d = (short)((unsigned short)angles[i] + correction);
            if (d < 0) d = -d;
            if ((int)(unsigned short)d < (int)best_dist) {
                best_dist = (unsigned short)d;
                best_idx = step;
            }
            step += ANGLE_STEP;
        }

        /* Store result: best segment index (in units of 0x100) */
        CAR_INT(car, CAR_ROAD_SEGMENT) = (unsigned int)best_idx;
    }
}
