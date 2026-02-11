#include "game.h"

/*
 * heading_rotation.c -- Apply heading rotation to display object transform
 *
 * Hand-translated from binary at 0x06026EDE (38 instructions).
 *
 * Functions:
 *   FUN_06026EDE (0x06026EDE) -- Heading rotation transform
 *
 * Computes a 2D rotation matrix from the car's heading angle
 * using FUN_06027358 (sin/cos lookup), then applies it to 3 rows
 * of the display object's transform matrix. Rotates X and Z
 * components while leaving Y unchanged (rotation around Y axis).
 *
 * Uses SH-2 MAC.L for fixed-point 32x32->64 multiply-accumulate
 * with xtrct for 16.16 result extraction.
 *
 * Called from car_position_update.c.
 */

/* External dependencies */
extern void FUN_06027358(int angle, int *sin_out, int *cos_out);

/* Rotation scratch buffer: [cos, sin, -sin, cos] */
#define ROTATION_BUF  ((volatile int *)0x0608A4E0)


/* ================================================================
 * FUN_06026EDE -- Heading Rotation Transform (0x06026EDE)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026EDE-0x06026F28)
 * Pool verified:
 *   0x06027070 = 0x0608A4E0 (rotation buffer)
 *   0x06027068 = 0x06089EDC (OBJ_STATE_PRIMARY)
 *
 * Algorithm:
 *   1. Call FUN_06027358(heading, &buf[1], &buf[0]) — sin/cos
 *   2. Build rotation matrix: buf[2] = -sin, buf[3] = cos
 *   3. Loop 3 rows of transform matrix:
 *      new_col0 = (cos * old_col0 + sin * old_col2) >> 16
 *      new_col2 = (-sin * old_col0 + cos * old_col2) >> 16
 *      col1 (Y) unchanged
 *
 * Uses MAC.L + xtrct pattern for fixed-point dot products.
 * 38 instructions. Saves PR only.
 * ================================================================ */
void FUN_06026EDE(int heading)
{
    volatile int *rot = ROTATION_BUF;

    /* Phase 1: Compute sin/cos from heading angle */
    FUN_06027358(heading, (int *)(rot + 1), (int *)rot);

    /* Phase 2: Build 2D rotation matrix */
    int sin_val = rot[1];
    int cos_val = rot[0];
    rot[2] = -sin_val;
    rot[3] = cos_val;

    /* Phase 3: Apply rotation to 3 transform matrix rows */
    volatile int *matrix = (volatile int *)(int)OBJ_STATE_PRIMARY;
    int i;

    for (i = 0; i < 3; i++) {
        int col0 = matrix[0];
        int col2 = matrix[2];

        /* MAC.L + xtrct: (a*b + c*d) >> 16 */
        long long acc_a = (long long)cos_val * (long long)col0
                        + (long long)sin_val * (long long)col2;
        int new_col0 = (int)(acc_a >> 16);

        long long acc_b = (long long)(-sin_val) * (long long)col0
                        + (long long)cos_val * (long long)col2;
        int new_col2 = (int)(acc_b >> 16);

        matrix[0] = new_col0;
        matrix[2] = new_col2;
        matrix += 3;  /* next row: 12 bytes */
    }
}
