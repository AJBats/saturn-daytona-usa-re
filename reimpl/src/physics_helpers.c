#include "game.h"

/*
 * physics_helpers.c -- Shared physics helper functions
 *
 * Hand-translated from DEFINITE/HIGH-confidence annotated ASM
 * (asm/collision.s, asm/ai_behavior.s) and verified
 * instruction-by-instruction against build/aprog.s raw binary.
 *
 * Functions:
 *   FUN_0600C928 (0x0600C928) -- Speed reduction (collision friction)
 *   FUN_0600C8CC (0x0600C8CC) -- Speed targeting (heading controller)
 *   FUN_0600C7D4 (0x0600C7D4) -- Heading/steering with speed-based damping
 *
 * These helpers are called from BOTH player_physics.c and ai_physics.c.
 * They operate on the current car struct via volatile pointer arithmetic.
 */


/* ================================================================
 * Car struct access macros (same as force_system.c)
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern int          FUN_0602744C(int x, int z);   /* atan2 */
extern void         FUN_06027358(int heading, int sin_out, int cos_out);  /* sin/cos lookup */
extern unsigned int FUN_06027552(int a, int b);    /* fixed-point multiply */


/* ================================================================
 * FUN_0600C928 -- Speed Reduction on Collision (0x0600C928)
 *
 * CONFIDENCE: DEFINITE (collision.s lines 1161-1206)
 * Every instruction verified. Pool word at 0x0600C966 = 0x2000.
 * Shift sequence (shlr8, shlr, extu.w, shll16, sub, 8x shar,
 * extu.w) confirmed. Offsets 0x48/0x50 confirmed.
 *
 * Computes a speed reduction factor from car[+0x0C], caps it,
 * and subtracts from car[+0x48] and car[+0x50].
 *
 * Formula: reduction = min(((speed >> 9) * 65535) >> 8, cap)
 * Approximately: min(speed / 2, 8192)
 * ================================================================ */
void FUN_0600C928(int car)
{
    unsigned int val;
    int product;
    int reduction, result, speed;
    int cap = 0x2000;   /* pool at 0x0600C966 */

    /* shlr8 + shlr + extu.w: unsigned right shift by 9, mask 16 bits */
    val = (unsigned int)CAR_INT(car, 0x0C);
    val >>= 8;     /* shlr8 */
    val >>= 1;     /* shlr */
    val &= 0xFFFF; /* extu.w */

    /* shll16, sub: val * 65535 */
    product = ((int)val << 16) - (int)val;

    /* 8x shar: arithmetic right shift by 8 */
    product >>= 1;
    product >>= 1;
    product >>= 1;
    product >>= 1;
    product >>= 1;
    product >>= 1;
    product >>= 1;
    product >>= 1;

    /* extu.w: mask to 16 bits */
    reduction = product & 0xFFFF;

    /* Clamp: if reduction >= cap, use cap; else use reduction */
    if (reduction >= cap) {
        result = cap;
    } else {
        result = reduction;
    }

    /* Subtract from car[+0x48], copy to car[+0x50] */
    speed = CAR_INT(car, 0x48);
    speed -= result;
    CAR_INT(car, 0x48) = speed;
    CAR_INT(car, 0x50) = speed;
}


/* ================================================================
 * FUN_0600C8CC -- Speed Targeting / Heading Controller (0x0600C8CC)
 *
 * CONFIDENCE: HIGH (ai_behavior.s lines 574-621)
 * All opcodes verified through atan2 call and heading adjustment.
 * Pool constants:
 *   0x0600C962: 0x0600 = 1536 (upper heading threshold)
 *   0x0600C964: 0xFA00 = -1536 signed (lower threshold)
 *   0x0600C968: 0x0602744C (atan2 function)
 *   0x0600C96C: 0x0000FA00 (subtract constant)
 *
 * Computes angle from car to next waypoint via atan2, then
 * adjusts the target heading (state[0x28]) with a clamped turn rate
 * of +/-1536 per frame. If within range, sets target to raw angle.
 *
 * FUN_0600C8CC is a trampoline: push r14, mov r4->r14, fall through
 * to FUN_0600C8D0. In C we implement it directly.
 * ================================================================ */
void FUN_0600C8CC(int car, int course_data)
{
    int waypoint_z, waypoint_x, delta_z, delta_x;
    int angle, neg_angle;
    int target, heading_diff;
    int threshold = 0x0600;  /* 1536, pool at 0x0600C962 */

    /* Compute direction to waypoint */
    waypoint_z = *(volatile int *)(course_data + 8);
    delta_z = waypoint_z - CAR_INT(car, 0x18);

    waypoint_x = *(volatile int *)course_data;
    delta_x = waypoint_x - CAR_INT(car, 0x10);

    /* atan2(delta_X, delta_Z) -> angle */
    angle = FUN_0602744C(delta_x, delta_z);

    /* Negate angle for heading reference */
    neg_angle = -angle;
    target = CAR_INT(car, 0x28);

    /* Heading difference: 16-bit modular subtraction */
    heading_diff = (short)(((unsigned short)neg_angle) - ((unsigned short)target));

    if (heading_diff > threshold) {
        /* Too far right: clamp turn rate to +1536 */
        int new_target = (short)((unsigned short)target + (unsigned short)threshold);
        CAR_INT(car, 0x28) = new_target;
    } else if (heading_diff >= (short)0xFA00) {
        /* Within range: direct pursuit */
        CAR_INT(car, 0x28) = neg_angle;
    } else {
        /* Too far left: clamp turn rate to -1536 */
        int new_target = (short)((unsigned short)target + 0xFA00u);
        CAR_INT(car, 0x28) = new_target;
    }
}

/* Alias for trampoline entry point (FUN_0600C8D0 is never called directly,
 * but it's a global label in the binary. Signature matches to avoid warnings.) */
void FUN_0600C8D0(int car, int course_data) __attribute__((alias("FUN_0600C8CC")));


/* ================================================================
 * FUN_0600C7D4 -- Heading / Steering Update (0x0600C7D4)
 *
 * CONFIDENCE: DEFINITE (ai_behavior.s lines 625-797)
 * Every opcode verified. Pool constants confirmed:
 *   0x0600C8B6: 0x01B0 (heading backup offset)
 *   0x0600C8B8: 0x0118 = 280 (speed threshold: heavy damping)
 *   0x0600C8BA: 0x00FA = 250 (speed threshold: medium damping)
 *   0x0600C8BC: 0x00DC = 220 (speed threshold: light damping)
 *   0x0600C8BE: 0x01D8 (track center heading offset)
 *   0x0600C8C0: 0x0190 (cos output offset in car struct)
 *   0x0600C8C2: 0x018C (sin output offset in car struct)
 *   0x0600C8C4: 0x06027358 (sin_cos_lookup)
 *   0x0600C8C8: 0x06027552 (fixed_mul)
 *
 * Updates the AI car's heading with SPEED-BASED DAMPING:
 *   > 280: shar x3 (heavy damping, sluggish steering)
 *   > 250: shar x2 (medium damping)
 *   > 220: shar x1 (light damping)
 *   <= 220: no damping (full steering response)
 *
 * After computing heading, also:
 *   - Computes lateral offset from track center
 *   - Blends course heading into car heading components
 *   - Backs up position
 *   - Converts heading to velocity via sin/cos lookup + fixed_mul
 *   - Updates X and Z positions
 *
 * FUN_0600C7D4 is a trampoline: push r14, mov r4->r14, fall through
 * to FUN_0600C7D8. In C we implement it directly.
 * ================================================================ */
void FUN_0600C7D4(int car, int course_data)
{
    int heading, target, speed;
    int delta;
    int vel;

    /* --- Backup current heading to state[0x01B0] --- */
    heading = CAR_INT(car, 0x20);
    CAR_INT(car, 0x1B0) = heading;

    /* --- Compute heading delta (target - current, 16-bit modular) --- */
    target = CAR_INT(car, 0x28);
    heading = CAR_INT(car, 0x20);
    speed = CAR_INT(car, 0x08);

    delta = (unsigned short)target;
    delta = delta + (unsigned short)(-(unsigned short)heading);
    /* (same as: extu.w(target) + extu.w(-heading) ) */

    /* --- Speed-based damping --- */
    if (speed > 280) {
        /* Heavy damping: >> 3 */
        delta = (short)delta;
        delta >>= 1;
        delta >>= 1;
        delta >>= 1;
    } else if (speed > 250) {
        /* Medium damping: >> 2 */
        delta = (short)delta;
        delta >>= 1;
        delta >>= 1;
    } else if (speed > 220) {
        /* Light damping: >> 1 */
        delta = (short)delta;
        delta >>= 1;
    } else {
        /* No damping */
        delta = (short)delta;
    }

    /* --- Apply damped delta to heading --- */
    {
        int new_heading;
        new_heading = (unsigned short)delta + (unsigned short)CAR_INT(car, 0x20);
        new_heading = (short)new_heading;
        CAR_INT(car, 0x20) = new_heading;

        /* --- Compute lateral offset from track center --- */
        {
            int lateral;
            int track_center = CAR_INT(car, 0x1D8);
            int course_heading = *(volatile short *)(course_data + 0x12);

            lateral = (unsigned short)new_heading;
            lateral += (unsigned short)(-track_center);
            lateral += (unsigned short)(-course_heading);
            lateral = (short)lateral;
            CAR_INT(car, 0x30) = lateral;
        }

        /* --- Blend course heading X component --- */
        {
            int course_x = *(volatile short *)(course_data + 0x0C);
            int current_x = CAR_INT(car, 0x1C);
            int blended = (unsigned short)current_x + (unsigned short)course_x;
            blended = (short)blended;
            blended >>= 1;   /* average */
            CAR_INT(car, 0x1C) = blended;
        }

        /* --- Blend course heading Z component --- */
        {
            int course_z = *(volatile short *)(course_data + 0x10);
            int current_z = CAR_INT(car, 0x24);
            int blended = (unsigned short)current_z + (unsigned short)course_z;
            blended = (short)blended;
            blended >>= 1;   /* average */
            CAR_INT(car, 0x24) = blended;
        }

        /* --- Store position copies --- */
        CAR_INT(car, 0x38) = CAR_INT(car, 0x10);   /* X backup */
        CAR_INT(car, 0x3C) = CAR_INT(car, 0x18);   /* Z backup */

        /* --- Heading correction from course data --- */
        {
            int adj_heading = (unsigned short)CAR_INT(car, 0x20);
            int course_corr = *(volatile short *)(course_data + 0x12);
            course_corr = -course_corr;
            course_corr >>= 1;   /* -course/2 */
            course_corr >>= 1;   /* -course/4 */
            adj_heading += (unsigned short)course_corr;
            adj_heading = (short)adj_heading;
            CAR_INT(car, 0x20) = adj_heading;
        }

        /* --- Convert heading to velocity components via sin/cos --- */
        {
            int sin_off = 0x018C;   /* pool at 0x0600C8C2 */
            int cos_off = 0x0190;   /* pool at 0x0600C8C0 */
            int tgt_heading = CAR_INT(car, 0x28);

            /* sin_cos_lookup(-heading, &sin, &cos) */
            FUN_06027358(-tgt_heading, car + sin_off, car + cos_off);

            /* X velocity: sin * speed -> add to X position */
            vel = (int)FUN_06027552(CAR_INT(car, 0x0C),
                                     CAR_INT(car, sin_off));
            CAR_INT(car, 0x10) = CAR_INT(car, 0x10) + vel;

            /* Z velocity: cos * speed -> add to Z position */
            vel = (int)FUN_06027552(CAR_INT(car, 0x0C),
                                     CAR_INT(car, cos_off));
            CAR_INT(car, 0x18) = CAR_INT(car, 0x18) + vel;
        }
    }
}

/* Alias for trampoline entry point (FUN_0600C7D8 is never called directly,
 * but it's a global label in the binary. Signature matches to avoid warnings.) */
void FUN_0600C7D8(int car, int course_data) __attribute__((alias("FUN_0600C7D4")));
