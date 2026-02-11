#include "game.h"

/*
 * matrix_transform.c -- 3x3 matrix-vector transform with translation
 *
 * Hand-translated from binary at 0x06026FFC (30 instructions).
 *
 * Functions:
 *   FUN_06026FFC (0x06026FFC) -- Transform 3D vector by rotation matrix
 *
 * Applies a 3x3 rotation matrix + translation to a 3D vector using
 * 16.16 fixed-point multiply-accumulate (mac.l + xtrct).
 *
 * Matrix layout at *(0x06089EDC):
 *   [0..8]  = 3x3 rotation matrix (row-major, 16.16 fixed-point)
 *   [9..11] = translation vector (16.16 fixed-point)
 *
 * For each output component:
 *   result[i] = (input[0]*M[i][0] + input[1]*M[i][1] + input[2]*M[i][2]) >> 16
 *               + translation[i]
 *
 * Uses intermediate buffer at 0x0608A520.
 * Called from car_position_update.c.
 */

/* Pointer to current transform matrix (12 ints: 3x3 rotation + 3 translation) */
#define TRANSFORM_MATRIX_PTR  (*(volatile int **)0x06089EDC)

/* Intermediate result buffer */
#define TRANSFORM_BUFFER      ((volatile int *)0x0608A520)


/* ================================================================
 * FUN_06026FFC -- 3D Matrix-Vector Transform (0x06026FFC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026FFC-0x06027036)
 * Pool verified:
 *   0x06027068 = 0x06089EDC (transform matrix pointer)
 *   0x06027078 = 0x0608A520 (intermediate buffer)
 *
 * Algorithm:
 *   For each of 3 rows:
 *     clrmac
 *     mac.l input[0]*row[0], input[1]*row[1], input[2]*row[2]
 *     result = xtrct(mach, macl) + translation[row]
 *   Copy 3 results to output
 *
 * 30 instructions. Saves r14 only. Uses MACH/MACL.
 * ================================================================ */
void FUN_06026FFC(int *input, int *output)
{
    int *matrix = (int *)TRANSFORM_MATRIX_PTR;
    int *translation = matrix + 9;
    int i;

    /* Compute rotated + translated coordinates */
    for (i = 0; i < 3; i++) {
        long long acc = 0;
        acc += (long long)input[0] * (long long)matrix[i * 3 + 0];
        acc += (long long)input[1] * (long long)matrix[i * 3 + 1];
        acc += (long long)input[2] * (long long)matrix[i * 3 + 2];

        /* xtrct mach,macl: extract middle 32 bits (16.16 result) */
        int result = (int)(acc >> 16) + translation[i];
        TRANSFORM_BUFFER[i] = result;
    }

    /* Copy from buffer to output */
    output[0] = TRANSFORM_BUFFER[0];
    output[1] = TRANSFORM_BUFFER[1];
    output[2] = TRANSFORM_BUFFER[2];
}
