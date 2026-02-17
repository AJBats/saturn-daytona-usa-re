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
/* FUN_06026EDE -- original binary (76 bytes) */
__asm__(
    ".section .text.FUN_06026EDE, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026EDE\n"
    ".type _FUN_06026EDE, @function\n"
    "_FUN_06026EDE:\n"
    ".byte 0x4F, 0x22, 0xD6, 0x63, 0xE5, 0x04, 0xB2, 0x38, 0x35, 0x6C, 0x4F, 0x26, 0x61, 0x52, 0x62, 0x62\n"  /* 0x06026EDE */
    ".byte 0x61, 0x1B, 0x16, 0x12, 0xD0, 0x5D, 0x16, 0x23, 0x64, 0x02, 0xE3, 0x03, 0x65, 0x43, 0x67, 0x63\n"  /* 0x06026EEE */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x75, 0x04, 0x05, 0x7F, 0x75, 0xF4, 0x00, 0x0A, 0x01, 0x1A, 0x21, 0x0D\n"  /* 0x06026EFE */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x75, 0x04, 0x05, 0x7F, 0x14, 0x10, 0x43, 0x10, 0x00, 0x0A, 0x02, 0x1A\n"  /* 0x06026F0E */
    ".byte 0x22, 0x0D, 0x14, 0x22, 0x8F, 0xEA, 0x74, 0x0C, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06026F1E */
);

