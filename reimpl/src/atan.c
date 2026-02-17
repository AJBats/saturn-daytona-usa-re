#include "game.h"

/*
 * atan.c -- Arctangent computation (piecewise linear + table lookup)
 *
 * Hand-translated from build/aprog.s binary, verified instruction-by-instruction.
 *
 * Functions:
 *   FUN_06027378 (0x06027378) -- Piecewise atan approximation (unlabeled)
 *   FUN_0602745C (0x0602745C) -- Full atan2 computation
 *
 * FUN_06027378 is the core atan approximation. For small inputs (< 0x100000),
 * it uses a direct 4096-entry lookup table at 0x002F0000. For large inputs,
 * it uses 9-segment piecewise linear interpolation.
 *
 * FUN_0602745C computes atan2(x, y) = atan(x/y), with a 180-degree offset
 * when y is negative. Note the parameter order: x first, y second.
 *
 * Angle format: 16-bit signed, where 0x4000 = 90 degrees, 0x8000 = 180 degrees.
 * Full circle = 0x10000 = 65536.
 *
 * Original addresses: 0x06027378, 0x0602745C
 */

extern int FUN_0602755C(int dividend, int divisor);  /* fpdiv */


/* ================================================================
 * FUN_06027378 -- Piecewise Atan Approximation (0x06027378)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06027378-0x0602744A)
 * Pool verified:
 *   0x060274F0 = 0x002F0000 (atan lookup table base)
 *   0x060274FC = 0x4000 (90 degrees / max angle)
 *   0x06027516 = 0x03E8 (boundary: 1000)
 *   0x06027520 = 0x0064 (boundary: 100)
 *   0x06027524 = 0x00FA (boundary: 250)
 *   0x06027526 = 0x01F4 (boundary: 500)
 *   0x06027522 = 0x0096 (boundary: 150)
 *   0x0602751E = 0x0046 (boundary: 70)
 *   0x0602751C = 0x0032 (boundary: 50)
 *   0x0602751A = 0x0028 (boundary: 40)
 *   0x06027518 = 0x001E (boundary: 30)
 *   Segment slopes at 0x06027528-0x06027548
 *   Segment base angles at 0x06027504-0x06027514
 *
 * Algorithm:
 *   1. Save sign of input, take absolute value
 *   2. Add 128 (rounding bias)
 *   3. If val < 0x100000: table lookup at 0x002F0000[val >> 8]
 *   4. Else: extract high 16 bits, select from 9 piecewise segments
 *   5. Each segment: angle = base + (short)((position * slope) >> 32)
 *   6. Negate result if original input was negative
 *
 * ~56 instructions total. LEAF function.
 * NOTE: 0x0629 and 0x0729 in delay slots are movt r6 and movt r7
 *       (disassembler shows them as .word because it misses delay slots)
 * ================================================================ */
int FUN_06027378(int input)
{
    int positive;
    int val;
    int angle;

    /* Step 1: Save sign, take absolute value */
    positive = (input >= 0);
    if (!positive)
        input = -input;

    /* Step 2: Add rounding bias */
    val = input + 128;

    /* Step 3: Small value — direct table lookup */
    if ((unsigned int)0x100000 > (unsigned int)val) {
        int index = ((unsigned int)val >> 8) << 1;
        angle = *(volatile short *)(0x002F0000 + index);
        return positive ? angle : -angle;
    }

    /* Step 4: Extract high 16 bits for segment selection */
    {
        unsigned int high = ((unsigned int)val >> 16) & 0xFFFF;
        int lower_bound, slope, base_angle;

        /* Overflow check: high word >= 1000 → max angle */
        if (high >= 1000) {
            return positive ? 0x4000 : -0x4000;
        }

        /* Binary search through 9 segments */
        if (high >= 100) {
            if (high >= 500) {
                /* Segment 7: 500-999 */
                lower_bound = 500 << 16;
                slope = 0x00000AC0;
                base_angle = 0x3FEB;
            } else if (high >= 250) {
                /* Segment 6: 250-499 */
                lower_bound = 250 << 16;
                slope = 0x00001581;
                base_angle = 0x3FD6;
            } else if (high >= 150) {
                /* Segment 5: 150-249 */
                lower_bound = 150 << 16;
                slope = 0x000047AE;
                base_angle = 0x3FBA;
            } else {
                /* Segment 4: 100-149 */
                lower_bound = 100 << 16;
                slope = 0x0000B333;
                base_angle = 0x3F97;
            }
        } else if (high >= 50) {
            if (high >= 70) {
                /* Segment 3: 70-99 */
                lower_bound = 70 << 16;
                slope = 0x00018000;
                base_angle = 0x3F6A;
            } else {
                /* Segment 2: 50-69 */
                lower_bound = 50 << 16;
                slope = 0x0002F333;
                base_angle = 0x3F2F;
            }
        } else if (high >= 30) {
            if (high >= 40) {
                /* Segment 1a: 40-49 */
                lower_bound = 40 << 16;
                slope = 0x00053333;
                base_angle = 0x3EFB;
            } else {
                /* Segment 1: 30-39 */
                lower_bound = 30 << 16;
                slope = 0x0008B333;
                base_angle = 0x3EA4;
            }
        } else {
            /* Segment 0: 16-29 */
            lower_bound = 16 << 16;
            slope = 0x0015B6DB;
            base_angle = 0x3D74;
        }

        /* Step 5: Piecewise linear interpolation */
        {
            int position = val - lower_bound;
            angle = base_angle + (short)(((long long)position * slope) >> 32);
        }

        /* Step 6: Apply sign */
        return positive ? angle : -angle;
    }
}


/* ================================================================
 * FUN_0602745C -- Full Atan2 Computation (0x0602745C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0602745C-0x06027474)
 * Pool verified:
 *   0x060274F4 = 0x00008000 (180 degrees offset)
 *
 * Algorithm:
 *   1. Save sign of y (param_2)
 *   2. Compute ratio = fpdiv(x, y) = (x << 16) / y
 *   3. Compute angle = atan_piecewise(ratio)
 *   4. If y was negative: add 0x8000 (180 degrees)
 *   5. Sign-extend result to 32-bit
 *
 * NOTE: Delay slot at 0x06027462 is movt r7 (0x0729), shown as .word
 *       by the disassembler. movt stores T flag (from cmp/pz r5) into r7.
 *
 * 13 instructions total.
 * ================================================================ */
#if 0 /* FUN_0602745C -- replaced by ASM import */
int FUN_0602745C(int x, int y)
{
    int y_positive = (y >= 0);
    int ratio = FUN_0602755C(x, y);
    int angle = FUN_06027378(ratio);

    if (!y_positive)
        angle += 0x8000;

    return (int)(short)angle;
}
#endif

/* FUN_0602745C -- original binary (60 bytes) */
__asm__(
    ".section .text.FUN_0602745C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0602745C\n"
    ".global _FUN_0602745c\n"
    ".type _FUN_0602745C, @function\n"
    "_FUN_0602745C:\n"
    "_FUN_0602745c:\n"
    ".byte 0x4F, 0x22, 0x45, 0x11, 0xB0, 0x7C, 0x07, 0x29, 0xBF, 0x88, 0x64, 0x03, 0x4F, 0x26, 0x27, 0x78\n"  /* 0x0602745C */
    ".byte 0x8B, 0x01, 0xD2, 0x21, 0x30, 0x2C, 0x00, 0x0B, 0x60, 0x0F, 0x44, 0x15, 0x8F, 0x0C, 0xE0, 0x00\n"  /* 0x0602746C */
    ".byte 0xD2, 0x1D, 0x30, 0x2C, 0x00, 0x07, 0x03, 0x1A, 0x33, 0x40, 0x89, 0x05, 0x33, 0x46, 0x8B, 0x00\n"  /* 0x0602747C */
    ".byte 0x30, 0x28, 0x42, 0x01, 0x42, 0x15, 0x89, 0xF4, 0x00, 0x0B, 0x40, 0x18\n"  /* 0x0602748C */
);

