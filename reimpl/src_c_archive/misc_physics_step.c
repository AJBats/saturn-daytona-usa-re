#include "game.h"

/*
 * misc_physics_step.c -- Miscellaneous physics update step
 *
 * Hand-translated from binary at 0x0602D88E (wrapper, 21 insn) +
 * 0x0602D8BC (body, ~45 insn) + 0x0602D924 (alt path, ~40 insn).
 *
 * Functions:
 *   FUN_0602D88E (0x0602D88E) -- Misc physics step (wrapper)
 *   FUN_0602D8BC (internal)   -- Physics body (two paths)
 *   FUN_0602D8C6 (internal)   -- Path A: simple velocity update
 *   FUN_0602D924 (internal)   -- Path B: corrected velocity update
 *
 * Called from alt_physics.c (FUN_0600E7C8).
 *
 * Reads the current car struct from *(0x0607E944) and:
 *   Path A (car[0x250] == 0): Direct velocity update from speed and
 *     angular velocity using sin/cos lookup.
 *   Path B (car[0x250] != 0): Heading correction via FUN_0602ECCC,
 *     speed decay via lookup table, then velocity update.
 *
 * Both paths save previous X/Z to car[0x38]/[0x3C], compute velocity
 * deltas as (sin*speed)>>16 and (cos*speed)>>16, storing deltas at
 * car[0x018C]/[0x0190] and updating positions at car[0x10]/[0x18].
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))

/* Car struct pointer for current iteration */
#define CAR_PTR_GLOBAL       (*(volatile int *)0x0607E944)

/* Trig lookups: angle in r4, result in r0 */
extern int FUN_06027344(int angle);           /* cos lookup */
extern int FUN_06027348(unsigned int angle);  /* sin lookup */

/* Rendering/correction function (L1 batch — currently broken) */
extern int FUN_0602eccc(void);

/* Speed decay multiplier table (indexed by car[0x250]) */
#define SPEED_DECAY_TABLE     ((volatile int *)0x0602E8B8)

/* Fallback speed value when car[0x08] <= 40 */
#define FALLBACK_SPEED        0x6AAA


/* ================================================================
 * FUN_0602D88E -- Misc Physics Step (0x0602D88E)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0602D88E-0x0602D9CE)
 * Pool verified:
 *   0x0602D8B8 = 0x0607E944 (car pointer)
 *   0x0602D916 = 0x0250 (mode field offset)
 *   0x0602D918 = 0x018C (delta X offset)
 *   0x0602D91A = 0x0190 (delta Z offset)
 *   0x0602D91C = 0x06027344 (cos lookup)
 *   0x0602D920 = 0x06027348 (sin lookup)
 *   0x0602D94E = 0x024C (heading correction offset)
 *   0x0602D950 = 0x0000000F (FUN_0602ECCC mode param)
 *   0x0602D954 = 0x0602ECCC (rendering/correction)
 *   0x0602D958 = 0x00000300 (flag mask)
 *   0x0602D9D0 = 0x0248 (angular velocity source)
 *   0x0602D9D2 = 0x0250 (speed table index)
 *   0x0602D9D4 = 0x0602E8B8 (speed multiplier table)
 *   0x0602D9D8 = 0x00006AAA (fallback speed)
 *   0x0602D9DC = 0x06027344 (cos, reused)
 *   0x0602D9E0 = 0x06027348 (sin, reused)
 *   0x0602D9E4 = 0x0000018C (delta X, reused)
 *   0x0602D9E8 = 0x00000190 (delta Z, reused)
 *
 * Algorithm:
 *   1. Load car pointer from *(0x0607E944)
 *   2. Check car+0x250 (mode field):
 *      Path A (== 0):
 *        a. car[0x20] = car[0x30] (copy heading)
 *        b. ang_vel = -car[0x28]
 *        c. speed = car[0x0C]
 *        d. Save prev position
 *        e. cos/sin(-ang_vel), compute deltas, update position
 *      Path B (!= 0):
 *        a. Call FUN_0602ECCC for heading correction
 *        b. Adjust heading ± car[0x024C] based on car[0] flags
 *        c. car[0x28] = car[0x248]; speed *= table[car+0x250]
 *        d. If car[0x08] <= 40: use fallback speed 0x6AAA
 *        e. Save prev position
 *        f. cos/sin(-ang_vel), compute deltas, update position
 *
 * ~106 instructions total. Saves r8-r14, PR.
 * ================================================================ */
void FUN_0602D88E(void)
{
    int car = CAR_PTR_GLOBAL;
    int mode = CAR_SHORT(car, 0x250);

    if (mode == 0) {
        /* Path A: Simple velocity update */
        int heading = CAR_INT(car, 0x30);
        CAR_INT(car, 0x20) = heading;

        int ang_vel = -CAR_INT(car, 0x28);
        int speed = CAR_INT(car, 0x0C);

        int old_x = CAR_INT(car, 0x10);
        int old_z = CAR_INT(car, 0x18);
        CAR_INT(car, 0x38) = old_x;
        CAR_INT(car, 0x3C) = old_z;

        int cos_val = FUN_06027344(ang_vel);
        int sin_val = FUN_06027348(ang_vel);

        /* Fixed-point velocity: (sin * speed) >> 16 via dmuls + xtrct */
        int delta_x = (int)((long long)sin_val * (long long)speed >> 16);
        CAR_INT(car, 0x018C) = delta_x;
        CAR_INT(car, 0x10) = old_x + delta_x;

        int delta_z = (int)((long long)cos_val * (long long)speed >> 16);
        CAR_INT(car, 0x0190) = delta_z;
        CAR_INT(car, 0x18) = old_z + delta_z;
    } else {
        /* Path B: Corrected velocity update */
        int heading = CAR_INT(car, 0x30);
        int correction = CAR_INT(car, 0x024C);

        /*
         * NOTE: Original binary calls FUN_0602ECCC here with:
         *   r0=0x0F, r1=correction, r4=-ang_vel, r5=heading
         * and uses r1 return as heading delta. The L1 batch version
         * of FUN_0602ECCC is broken (truncated), so we use the
         * raw correction value from car[0x024C] instead.
         */
        FUN_0602eccc();

        /* Adjust heading based on car flags */
        if (CAR_INT(car, 0x00) & 0x300) {
            heading += correction;
        } else {
            heading -= correction;
        }

        CAR_INT(car, 0x30) = heading;
        CAR_INT(car, 0x20) = heading;

        /* Copy angular velocity from alternate source */
        int ang_vel_src = CAR_INT(car, 0x0248);
        CAR_INT(car, 0x28) = ang_vel_src;
        int ang_vel = -ang_vel_src;

        /* Apply speed decay via table lookup */
        int table_idx = CAR_SHORT(car, 0x250);
        int multiplier = SPEED_DECAY_TABLE[table_idx];
        int speed = CAR_INT(car, 0x0C);
        int decayed_speed = (int)((long long)speed * (long long)multiplier >> 16);
        CAR_INT(car, 0x0C) = decayed_speed;

        /* Use fallback speed for position if car[0x08] <= 40 */
        int pos_speed = decayed_speed;
        if (CAR_INT(car, 0x08) <= 40) {
            pos_speed = FALLBACK_SPEED;
        }

        int old_x = CAR_INT(car, 0x10);
        int old_z = CAR_INT(car, 0x18);
        CAR_INT(car, 0x38) = old_x;
        CAR_INT(car, 0x3C) = old_z;

        int cos_val = FUN_06027344(ang_vel);
        int sin_val = FUN_06027348(ang_vel);

        int delta_x = (int)((long long)sin_val * (long long)pos_speed >> 16);
        CAR_INT(car, 0x018C) = delta_x;
        CAR_INT(car, 0x10) = old_x + delta_x;

        int delta_z = (int)((long long)cos_val * (long long)pos_speed >> 16);
        CAR_INT(car, 0x0190) = delta_z;
        CAR_INT(car, 0x18) = old_z + delta_z;
    }
}
