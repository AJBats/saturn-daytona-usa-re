/* vec3_math.c -- 3D vector operations (fixed-point 16.16)
 *
 * Hand-translated from annotated ASM (asm/math_helpers.s)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_060274DA (0x060274DA) -- vec3_dot: dot product of two 3-element vectors
 *   FUN_06027498 (0x06027498) -- vec3_normalize: normalize vector to unit length
 *
 * Both operate on 3-element int arrays (X, Y, Z) in 16.16 fixed-point.
 * The dot product uses the SH-2 MAC unit for 64-bit accumulation.
 * Normalize uses dot(self), isqrt, fpdiv(1.0/mag), then scales each component.
 *
 * Original addresses: 0x060274DA, 0x06027498
 */

/* External math primitives */
extern unsigned int FUN_06027552(int a, int b);  /* fpmul: (a*b)>>16 */
extern int FUN_0602755C(int dividend, int divisor); /* fpdiv: (a<<16)/b */
extern int FUN_06027476(int value);              /* isqrt: floor(sqrt(x))<<8 */


/* ================================================================
 * FUN_060274DA -- Vec3 Dot Product (0x060274DA)
 *
 * CONFIDENCE: DEFINITE (math_helpers.s lines 402-429, binary verified)
 * Verified byte-for-byte at 0x060274DA. 7 instructions total.
 *
 * Uses SH-2 MAC (Multiply-Accumulate) unit:
 *   clrmac
 *   mac.l @r4+,@r5+ (x3)
 *   sts mach,r1 / sts macl,r0 / xtrct r1,r0
 *
 * The xtrct extracts middle 32 bits of the 64-bit accumulator,
 * giving (accumulator >> 16) -- the 16.16 fixed-point dot product.
 *
 * LEAF function. Not in aprog_syms.txt (unlabeled helper).
 * ================================================================ */
int FUN_060274DA(int *a, int *b)
{
    long long acc = 0;
    acc += (long long)a[0] * (long long)b[0];
    acc += (long long)a[1] * (long long)b[1];
    acc += (long long)a[2] * (long long)b[2];
    return (int)(acc >> 16);
}


/* ================================================================
 * FUN_06027498 -- Vec3 Normalize (0x06027498)
 *
 * CONFIDENCE: DEFINITE (math_helpers.s lines 342-399, binary verified)
 * Pool verified:
 *   0x060274F8 = 0x00010000 (1.0 in 16.16 fixed-point)
 *
 * Algorithm:
 *   1. mag_sq = vec3_dot(vec, vec)     (bsr 060274DA)
 *   2. mag = isqrt(mag_sq)            (bsr 06027476)
 *   3. if mag <= 0: return             (zero vector, skip)
 *   4. inv_mag = fpdiv(1.0, mag)       (bsr 0602755C)
 *   5. vec[0] = fpmul(vec[0], inv_mag) (dmuls.l + xtrct, x3)
 *   6. vec[1] = fpmul(vec[1], inv_mag)
 *   7. vec[2] = fpmul(vec[2], inv_mag)
 *
 * Normalizes vector in-place to unit length.
 * Uses callee-saved r14 to preserve vector pointer across calls.
 * ================================================================ */
void FUN_06027498(int *vec)
{
    int mag_sq, mag, inv_mag;

    mag_sq = FUN_060274DA(vec, vec);
    mag = FUN_06027476(mag_sq);

    if (mag <= 0)
        return;

    inv_mag = FUN_0602755C(0x00010000, mag);

    vec[0] = (int)FUN_06027552(vec[0], inv_mag);
    vec[1] = (int)FUN_06027552(vec[1], inv_mag);
    vec[2] = (int)FUN_06027552(vec[2], inv_mag);
}
