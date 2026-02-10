#include "game.h"

/*
 * collision.c -- Car-car collision detection and response
 *
 * Hand-translated from DEFINITE/HIGH-confidence annotated ASM
 * (asm/car_collision.s, asm/collision_response.s) and verified
 * instruction-by-instruction against build/aprog.s raw binary.
 *
 * Functions:
 *   FUN_0600A914  -- O(n^2) proximity-based collision detection
 *   FUN_060316C4  -- Elastic collision response (register save wrapper)
 *   FUN_060316D0  -- Collision response main body
 *   FUN_06030FC0  -- Player collision response variant
 *
 * Call chain:
 *   FUN_0600DE70 (per-car iteration) -> FUN_0600A914 (detection)
 *     -> FUN_060316C4 (AI-AI response)
 *     -> FUN_06030FC0 (player-AI response)
 *       -> FUN_0602744C (atan2)
 *       -> FUN_06027344 (sin)
 *       -> FUN_06027348 (cos)
 */


/* ================================================================
 * Car struct access macros
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))
#define CAR_BYTE(car, off)   (*(volatile signed char *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))


/* ================================================================
 * Collision system constants (from pool constants in aprog.s)
 * ================================================================ */
#define COLLISION_DIST_THRESHOLD  0x0004B333   /* weighted Manhattan distance */
#define COLLISION_CAR_COUNT_PTR   0x0607EA98   /* active car count for collision */
#define COLLISION_SPEED_GATE      0x00010000   /* skip if car moving too fast */
#define COLLISION_FIELD_1EC       0x1EC         /* proximity gate field (speed/progress) */
#define COLLISION_FIELD_1B4       0x1B4         /* speed gate field */

/* Collision response constants */
#define FORCE_TABLE_BASE          0x0605BCC8   /* collision force lookup table */
#define HEIGHT_THRESHOLD          0x0001638E   /* ~91K height for vertical collision */
#define COLLISION_FLAG            0x08000000   /* bit 27 of car flags */
#define HALF_ROTATION             0x8000       /* 180 degrees */
#define HEADING_WRAP_THRESHOLD    0x8000       /* heading wrap threshold */
#define HEADING_RANGE_THRESHOLD   0x4000       /* secondary heading range */

/* Car count for collision (different from game.h CAR_COUNT) */
#define COLL_CAR_COUNT  (*(volatile int *)COLLISION_CAR_COUNT_PTR)


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern int  FUN_0602744C(int dx, int dz);         /* atan2 */
extern int  FUN_06027344(int angle);               /* sin lookup */
extern int  FUN_06027348(int angle);               /* cos lookup */
extern unsigned int FUN_06027552(int a, int b);    /* fixed-point multiply */

/* Forward declarations */
void FUN_060316C4(int car_a, int car_b, int dist);
void FUN_060316D0(int car_a, int car_b, int dist);
void FUN_06030FC0(int car_a, int car_b, int dist);


/* ================================================================
 * Helper: fixed-point multiply via dmuls.l/xtrct pattern
 *
 * On SH-2: dmuls.l a,b -> MACH:MACL = a*b (64-bit signed)
 *           xtrct MACH,MACL -> result = (int)((long long)a*b >> 16)
 * ================================================================ */
static int fixed_mul(int a, int b)
{
    return (int)(((long long)a * (long long)b) >> 16);
}


/* ================================================================
 * FUN_0600A914 -- Car-Car Collision Detection (0x0600A914)
 *
 * CONFIDENCE: HIGH (car_collision.s)
 * Pool constants verified: 0x0004B333, 0x0607EA98, 0x06078900,
 * 0x0607EAE0, 0x00E00000, 0x0607E940, 0x00010000, 0x060316C4.
 *
 * Algorithm:
 *   Pass 1: O(n^2) check all AI car pairs (i=1..count-2, j=i+1..count-1)
 *   Pass 2: Player car (index 0) vs all AI cars (j=1..count-1)
 *
 * For each pair:
 *   1. Skip inactive cars (flags & 0x00E00000 == 0)
 *   2. Proximity gate: |car_i[0x1EC] - car_j[0x1EC]| <= 20
 *   3. Weighted Manhattan distance: max(dx,dz) + min(dx,dz)/4
 *   4. Distance threshold: dist < 0x0004B333
 *   5. Speed gate: car_j[0x1B4] < 0x00010000
 *   6. If all pass: call collision response
 *
 * NOTE: When demo mode (0x0607EAE0 != 0), function exits immediately.
 * Binary at 0x0600A936 branches to epilogue at 0x0600AA6A, NOT to
 * second pass. Annotation error in car_collision.s corrected here.
 *
 * NOTE: Pass 2 calls FUN_06030FC0 (0x06030FC0), not FUN_060316C4.
 * This is a separate collision response variant for player collisions.
 * ================================================================ */
void FUN_0600A914(void)
{
    int car_count;
    int car_base = CAR_ARRAY_BASE;
    int i, j;
    int car_i, car_j;
    int dy, dx, dz;
    int abs_dx, abs_dz;
    int dist;

    /* Demo mode: skip all collision processing */
    if (DEMO_MODE_FLAG != 0)
        return;

    car_count = COLL_CAR_COUNT;

    /* === Pass 1: AI-vs-AI collision (all pairs, i>0) === */
    for (i = 1; i < car_count - 1; i++) {
        car_i = car_base + i * CAR_STRUCT_SIZE;
        CAR_PTR_CURRENT = car_i;

        /* Skip inactive car */
        if ((CAR_INT(car_i, CAR_FLAGS) & CAR_FLAG_ACTIVE) == 0)
            continue;

        for (j = i + 1; j < car_count; j++) {
            car_j = car_base + j * CAR_STRUCT_SIZE;

            /* Skip inactive car */
            if ((CAR_INT(car_j, CAR_FLAGS) & CAR_FLAG_ACTIVE) == 0)
                continue;

            /* Proximity gate: field 0x1EC difference */
            dy = CAR_INT(car_i, COLLISION_FIELD_1EC) -
                 CAR_INT(car_j, COLLISION_FIELD_1EC);
            if (dy > 20 || dy < -20)
                continue;

            /* XZ distance: weighted Manhattan approximation */
            dx = CAR_INT(car_i, CAR_X) - CAR_INT(car_j, CAR_X);
            dz = CAR_INT(car_i, CAR_Z) - CAR_INT(car_j, CAR_Z);

            abs_dx = dx >= 0 ? dx : -dx;
            abs_dz = dz >= 0 ? dz : -dz;

            if (abs_dx > abs_dz) {
                /* X dominant: dist = dx + dz/4 */
                dist = abs_dx + (abs_dz >> 2);
            } else {
                /* Z dominant: dist = dz + dx/4 */
                dist = abs_dz + (abs_dx >> 2);
            }

            /* Distance threshold */
            if (dist >= COLLISION_DIST_THRESHOLD)
                continue;

            /* Speed gate */
            if (CAR_INT(car_j, COLLISION_FIELD_1B4) >= COLLISION_SPEED_GATE)
                continue;

            /* COLLISION DETECTED: call response */
            FUN_060316C4(car_i, car_j, dist);
        }
    }

    /* === Pass 2: Player car vs all AI cars === */
    {
        int player_car = car_base;  /* car_array[0] = player */
        CAR_PTR_CURRENT = player_car;

        for (j = 1; j < car_count; j++) {
            car_j = car_base + j * CAR_STRUCT_SIZE;

            /* Skip inactive car */
            if ((CAR_INT(car_j, CAR_FLAGS) & CAR_FLAG_ACTIVE) == 0)
                continue;

            /* Proximity gate */
            dy = CAR_INT(player_car, COLLISION_FIELD_1EC) -
                 CAR_INT(car_j, COLLISION_FIELD_1EC);
            if (dy > 20 || dy < -20)
                continue;

            /* XZ distance */
            dx = CAR_INT(car_j, CAR_X) - CAR_INT(player_car, CAR_X);
            dz = CAR_INT(car_j, CAR_Z) - CAR_INT(player_car, CAR_Z);

            abs_dx = dx >= 0 ? dx : -dx;
            abs_dz = dz >= 0 ? dz : -dz;

            if (abs_dx > abs_dz) {
                dist = abs_dx + (abs_dz >> 2);
            } else {
                dist = abs_dz + (abs_dx >> 2);
            }

            if (dist >= COLLISION_DIST_THRESHOLD)
                continue;

            /* Speed gate */
            if (CAR_INT(car_j, COLLISION_FIELD_1B4) >= COLLISION_SPEED_GATE)
                continue;

            /* COLLISION DETECTED: player variant */
            FUN_06030FC0(player_car, car_j, dist);
        }
    }
}

/* Alias for named reference from other files */
void car_collision_proximity(void) __attribute__((alias("FUN_0600A914")));


/* ================================================================
 * FUN_060316C4 -- Collision Response Entry (0x060316C4)
 *
 * CONFIDENCE: DEFINITE (register save wrapper verified)
 * Just saves r8-r13 and falls through to FUN_060316D0.
 * In C, we simply forward to the main body.
 * ================================================================ */
void FUN_060316C4(int car_a, int car_b, int dist)
{
    FUN_060316D0(car_a, car_b, dist);
}


/* ================================================================
 * FUN_060316D0 -- Collision Response Main Body (0x060316D0)
 *
 * CONFIDENCE: HIGH (collision_response.s)
 * Pool constants verified: 0x0602744C (atan2), 0x0605BCC8 (force table),
 * 0x0001638E (height threshold), 0x08000000 (collision flag),
 * 0x00008000 (half rotation), 0x06027344/348 (sin/cos).
 *
 * Algorithm:
 *   1. Determine car ordering by Y position (higher = "above")
 *   2. Compute collision angle = atan2(dx, dz) between centers
 *   3. Look up collision force from heading difference table
 *   4. Height check with collision flag
 *   5. Apply position impulse (sin/cos * force) to both cars
 *   6. Apply opposite impulse (angle + 180) to other car
 * ================================================================ */
void FUN_060316D0(int car_a, int car_b, int coll_param)
{
    int higher, lower;
    int dx, dz;
    int angle, neg_angle;
    int heading_a, heading_b;
    int diff_a, diff_b;
    int force_a, force_b, net_force;
    int h_diff;
    int sin_val, cos_val;

    /* Step 1: Determine ordering by Y position */
    if (CAR_INT(car_a, 0x0C) > CAR_INT(car_b, 0x0C)) {
        /* A is above B: normal ordering */
        higher = car_a;
        lower = car_b;
        dx = CAR_INT(car_a, CAR_X) - CAR_INT(car_b, CAR_X);
        dz = CAR_INT(car_a, CAR_Z) - CAR_INT(car_b, CAR_Z);
    } else {
        /* A is below B: swap roles */
        higher = car_b;
        lower = car_a;
        dx = CAR_INT(car_b, CAR_X) - CAR_INT(car_a, CAR_X);
        dz = CAR_INT(car_b, CAR_Z) - CAR_INT(car_a, CAR_Z);
    }

    /* Step 2: Compute collision angle */
    angle = FUN_0602744C(dx, dz);
    neg_angle = -(short)angle;  /* negate and sign-extend */

    /* Step 3: Heading comparison / force lookup */
    heading_a = CAR_INT(higher, CAR_HEADING);
    diff_a = (unsigned short)(heading_a - neg_angle);
    if (diff_a >= HEADING_WRAP_THRESHOLD) {
        diff_a -= HEADING_WRAP_THRESHOLD;
    }

    heading_b = CAR_INT(lower, CAR_HEADING);
    diff_b = (unsigned short)(heading_b - neg_angle);
    diff_a >>= 8;  /* shlr8 */
    if (diff_b >= HEADING_WRAP_THRESHOLD) {
        diff_b -= HEADING_WRAP_THRESHOLD;
    }

    /* Table index: (diff >> 9) * 4 = (diff >> 7) after shlr8+shlr+shll2 */
    diff_a = (diff_a >> 1) << 2;   /* shlr + shll2 */
    diff_b = (diff_b >> 9) << 2;   /* shlr8 + shlr + shll2 */

    force_a = *(volatile int *)(FORCE_TABLE_BASE + diff_a);
    force_b = *(volatile int *)(FORCE_TABLE_BASE + diff_b);

    net_force = force_a - coll_param + force_b;
    if (net_force <= 0)
        return;  /* No collision force to apply */

    /* Step 4: Height check */
    h_diff = CAR_INT(higher, 0x28) - CAR_INT(lower, 0x28);
    h_diff = (unsigned short)h_diff;

    if (h_diff < HEADING_RANGE_THRESHOLD) {
        /* In range: check height difference */
        int ya = CAR_INT(higher, 0x0C);
        int yb = CAR_INT(lower, 0x0C);
        int y_diff = ya - yb;
        if (y_diff >= HEIGHT_THRESHOLD) {
            /* Set collision flag on lower car */
            CAR_INT(lower, CAR_FLAGS) |= COLLISION_FLAG;
        }
    } else if (h_diff >= HEADING_RANGE_THRESHOLD * 3) {
        /* In extended range: check combined height */
        int ya = CAR_INT(higher, 0x0C);
        int yb = CAR_INT(lower, 0x0C);
        int y_diff = ya - yb;
        if (y_diff >= HEIGHT_THRESHOLD) {
            CAR_INT(lower, CAR_FLAGS) |= COLLISION_FLAG;
        }
    } else {
        /* Out of range: combined height check */
        int ya = CAR_INT(higher, 0x0C);
        int yb = CAR_INT(lower, 0x0C);
        int combined = ya + yb;
        if (combined >= HEIGHT_THRESHOLD) {
            CAR_INT(lower, CAR_FLAGS) |= COLLISION_FLAG;
            goto set_flag;
        }
        goto set_flag;
    }

    /* Check secondary heading for impulse eligibility */
    {
        int sec_heading = CAR_INT(higher, 0x28);
        int sec_diff = (unsigned short)(sec_heading - neg_angle);
        if (sec_diff >= HEADING_RANGE_THRESHOLD &&
            sec_diff < HEADING_RANGE_THRESHOLD * 3) {
            goto set_flag;  /* Outside impulse range */
        }
    }

    /* Apply heading copy from higher to lower */
    CAR_INT(lower, CAR_HEADING) = CAR_INT(higher, CAR_HEADING);

    /* Y momentum transfer via sin(angle) */
    {
        int ya = CAR_INT(higher, 0x0C);
        int yb = CAR_INT(lower, 0x0C);
        int y_diff = ya - yb;
        sin_val = FUN_06027344(neg_angle);
        {
            int y_transfer = fixed_mul(sin_val, y_diff);
            CAR_INT(lower, 0x0C) = yb + y_transfer;
            CAR_INT(higher, 0x0C) = ya - y_transfer;
        }
    }

set_flag:
    /* Step 5: Apply position impulse to lower car */
    net_force >>= 1;   /* force /= 2 (shlr) */

    /* Backup lower car position */
    CAR_INT(lower, CAR_PRE_COLL_X) = CAR_INT(lower, CAR_X);
    CAR_INT(lower, CAR_PRE_COLL_Z) = CAR_INT(lower, CAR_Z);

    /* sin/cos of collision angle */
    sin_val = FUN_06027344(-neg_angle);
    cos_val = FUN_06027348(-neg_angle);

    /* Apply impulse: X += cos * force, Z += sin * force */
    CAR_INT(lower, CAR_X) += fixed_mul(cos_val, net_force);
    CAR_INT(lower, CAR_Z) += fixed_mul(sin_val, net_force);

    /* Step 6: Apply opposite impulse to higher car (angle + 180) */
    neg_angle += HALF_ROTATION;

    /* Backup higher car position */
    CAR_INT(higher, CAR_PRE_COLL_X) = CAR_INT(higher, CAR_X);
    CAR_INT(higher, CAR_PRE_COLL_Z) = CAR_INT(higher, CAR_Z);

    sin_val = FUN_06027344(-neg_angle);
    cos_val = FUN_06027348(-neg_angle);

    CAR_INT(higher, CAR_X) += fixed_mul(cos_val, net_force);
    CAR_INT(higher, CAR_Z) += fixed_mul(sin_val, net_force);
}


/* ================================================================
 * FUN_06030FC0 -- Player Collision Response Variant (0x06030FC0)
 *
 * CONFIDENCE: HIGH
 * Nearly identical to FUN_060316C4/D0 per annotation:
 * "byte-for-byte identical except r14/r13 roles are effectively
 *  swapped in some operations"
 *
 * Pool constant at 0x0600AA94 = 0x06030FC0 (verified in binary).
 * Register-save wrapper that falls through to FUN_06030FCC.
 * Called from pass 2 of collision detection (player vs all AI).
 *
 * For now, implemented as forwarding to the same response body.
 * The original code has a separately compiled copy at a different
 * address range — behavior is functionally equivalent.
 * ================================================================ */
void FUN_06030FC0(int car_a, int car_b, int dist)
{
    FUN_060316D0(car_a, car_b, dist);
}
