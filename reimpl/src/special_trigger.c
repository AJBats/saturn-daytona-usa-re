#include "game.h"

/*
 * special_trigger.c -- Race condition trigger check
 *
 * Hand-translated from binary at 0x0602D9F0 (~83 instructions).
 *
 * Functions:
 *   FUN_0602D9F0 (0x0602D9F0) -- Check special race trigger conditions
 *
 * Performs a multi-condition check on the car state. When all conditions
 * are met (checkpoint progress, Z position, contact flags, heading angle),
 * sets bit 17 in the car flags and a 60-frame timer.
 *
 * Conditions checked (all must pass):
 *   1. car[0x228] < *(0x06063F28) - 1 (checkpoint progress)
 *   2. If VS mode: car Z position < 0xFF000000 (altitude check)
 *   3. car[0x1BC] == 0 (state clear)
 *   4. car_short[0x150] | car_short[0x250] | car[0xB8] == 0
 *   5. All 4 contact flags (car[0x120..0x12C]) AND == 0x0041
 *   6. Heading diff within angular range [-0x17FE, 0x0800]
 *   7. car[0] bit 3 not set
 *   8. Byte flag at 0x06083260 == 0
 *
 * On success: car[0] |= 0x20000, timer=60, flag=1
 * On any failure: clears byte flag at 0x06083260
 * On early exit (bit3 set or flag nonzero): sets byte flag to 0xFF
 *
 * Called from physics_entry.c (E4F2 path).
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))

/* Car struct pointer */
#define CAR_PTR_SECONDARY    (*(volatile int *)0x0607E944)
#define CAR_PTR_PRIMARY      (*(volatile int *)0x0607E940)

/* Checkpoint/lap progress counter */
#define PROGRESS_COUNTER     (*(volatile int *)0x06063F28)

/* Course/mode flag */
#define COURSE_FLAG          (*(volatile int *)0x0607EAD8)

/* Car struct field offsets */
#define CAR_FLAGS            0x00
#define CAR_Z_POS            0x18
#define CAR_HEADING_A        0x28
#define CAR_FIELD_B8         0xB8
#define CAR_CONTACT_BASE     0x120
#define CAR_FIELD_150        0x150
#define CAR_STATE_1BC        0x1BC
#define CAR_PROGRESS         0x228
#define CAR_FIELD_250        0x250
#define CAR_HEADING_B        0x25C

/* Trigger outputs */
#define TRIGGER_FLAG_BIT     0x00020000
#define CAR_FLAG_BIT3        0x00000008
#define CONTACT_REQUIRED     0x0041
#define Z_THRESHOLD          ((int)0xFF000000)

/* Angular range for heading check (centered at 0x3FFF) */
#define ANGLE_CENTER         0x3FFF
#define ANGLE_LOWER          0x2800
#define ANGLE_UPPER          0x47FF

/* Timer/flag outputs */
#define TRIGGER_TIMER        (*(volatile int *)0x0607EAC8)
#define TRIGGER_FLAG         (*(volatile int *)0x0605A1C4)
#define TRIGGER_BYTE_FLAG    (*(volatile unsigned char *)0x06083260)


/* ================================================================
 * FUN_0602D9F0 -- Race Condition Trigger Check (0x0602D9F0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0602D9F0-0x0602DAF4)
 * Pool verified:
 *   0x0602DAB0 = 0x0607E944 (car ptr secondary)
 *   0x0602DAB4 = 0x06063F28 (progress counter)
 *   0x0602DAB8 = 0x00000228 (progress offset)
 *   0x0602DABC = 0x0607EAD8 (course flag)
 *   0x0602DAC4 = 0x00000018 (Z offset)
 *   0x0602DAC8 = 0xFF000000 (Z threshold)
 *   0x0602DACC = 0x000001BC (state offset)
 *   0x0602DAD4 = 0x0607E940 (car ptr primary)
 *   0x0602DAD8 = 0x00000008 (bit 3)
 *   0x0602DADC = 0x06083260 (byte flag)
 *   0x0602DAE0 = 0x00020000 (trigger bit)
 *   0x0602DAE4 = 0x0607EAC8 (timer)
 *   0x0602DAE8 = 0x0605A1C4 (flag)
 * Word pool:
 *   0x0602DA98 = 0x0150 (car field)
 *   0x0602DA9A = 0x0250 (car field)
 *   0x0602DA9C = 0x00B8 (car field)
 *   0x0602DA9E = 0x0120 (contact base)
 *   0x0602DAA0 = 0x0041 (required contact bits)
 *   0x0602DAA2 = 0x025C (heading B offset)
 *   0x0602DAA4 = 0x3FFF (angle center)
 *   0x0602DAA6 = 0x2800 (angle lower bound)
 *   0x0602DAA8 = 0x47FF (angle upper bound)
 *   0x0602DAAA = 0x003C (timer value = 60)
 *   0x0602DAAC = 0x0001 (flag value)
 *
 * ~83 instructions. Leaf function (no PR save).
 * ================================================================ */
void FUN_0602D9F0(void)
{
    int car = CAR_PTR_SECONDARY;

    /* Check 1: Checkpoint progress */
    int progress_limit = PROGRESS_COUNTER - 1;
    int car_progress = CAR_INT(car, CAR_PROGRESS);
    if (car_progress >= progress_limit)
        goto cleanup;

    /* Check 2: VS mode Z position check */
    if (COURSE_FLAG == 1) {
        int car_z = CAR_INT(car, CAR_Z_POS);
        if (car_z >= Z_THRESHOLD)
            goto cleanup;
    }

    /* Check 3: State field must be zero */
    if (CAR_INT(car, CAR_STATE_1BC) != 0)
        goto cleanup;

    /* Check 4: Three fields must all be zero */
    {
        int v150 = (int)CAR_SHORT(car, CAR_FIELD_150);
        int v250 = (int)CAR_SHORT(car, CAR_FIELD_250);
        int vB8  = CAR_INT(car, CAR_FIELD_B8);
        if ((v150 | v250 | vB8) != 0)
            goto cleanup;
    }

    /* Check 5: All 4 contact flags must have bits 0x0041 set */
    {
        int c0 = CAR_INT(car, CAR_CONTACT_BASE + 0x00);
        int c1 = CAR_INT(car, CAR_CONTACT_BASE + 0x04);
        int c2 = CAR_INT(car, CAR_CONTACT_BASE + 0x08);
        int c3 = CAR_INT(car, CAR_CONTACT_BASE + 0x0C);
        int all_and = c0 & c1 & c2 & c3;
        if (all_and != CONTACT_REQUIRED)
            goto cleanup;
    }

    /* Check 6: Heading difference within angular range */
    {
        int car_primary = CAR_PTR_PRIMARY;
        int heading_a = CAR_INT(car_primary, CAR_HEADING_A);
        int heading_b = CAR_INT(car_primary, CAR_HEADING_B);
        int diff = (short)(heading_a - heading_b);
        int centered = diff + ANGLE_CENTER;

        if (ANGLE_LOWER >= centered)
            goto cleanup;
        if (centered > ANGLE_UPPER)
            goto cleanup;
    }

    /* Check 7: Car flags bit 3 not set */
    {
        int car_primary = CAR_PTR_PRIMARY;
        int flags = CAR_INT(car_primary, CAR_FLAGS);
        if (flags & CAR_FLAG_BIT3)
            goto end_skip;

        /* Check 8: Byte flag must be zero */
        if (TRIGGER_BYTE_FLAG != 0)
            goto end_skip;

        /* All checks passed: trigger the event */
        CAR_INT(car_primary, CAR_FLAGS) = flags | TRIGGER_FLAG_BIT;
        TRIGGER_TIMER = 60;
        TRIGGER_FLAG = 1;
    }

cleanup:
    /* Normal exit: clear byte flag */
    TRIGGER_BYTE_FLAG = 0;
    return;

end_skip:
    /* Early exit: set byte flag to 0xFF */
    TRIGGER_BYTE_FLAG = 0xFF;
    return;
}
