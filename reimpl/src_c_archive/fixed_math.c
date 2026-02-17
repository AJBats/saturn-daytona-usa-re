/* fixed_math.c -- Fixed-point arithmetic (16.16 format)
 *
 * FUN_06027552 = fixed-point multiply: (a * b) >> 16
 * FUN_0602755C = fixed-point divide: (a << 16) / b
 *
 * Both fundamental primitives used by all game subsystems.
 * 16.16 format: top 16 bits = integer, bottom 16 = fraction.
 *
 * Original addresses: 0x06027552, 0x0602755C
 */

/* ================================================================
 * FUN_06027552 -- Fixed-Point Multiply (0x06027552)
 *
 * Computes (a * b) >> 16 in 16.16 fixed-point format.
 *
 * On SH-2: dmuls.l Rm, Rn → 64-bit product in MACH:MACL
 *          xtrct MACH, MACL → extract middle 32 bits (= product >> 16)
 *
 * 4 instructions total. LEAF function.
 * ================================================================ */
unsigned int FUN_06027552(int a, int b)
{
    return (unsigned int)((long long)a * (long long)b >> 16);
}


/* ================================================================
 * FUN_0602755C -- Fixed-Point Divide (0x0602755C)
 *
 * CONFIDENCE: DEFINITE (math_helpers.s lines 456-496, binary verified)
 * Pool verified:
 *   0x06027570 = 0xFF00 (sign-extended to 0xFFFFFF00, SH-2 div unit base)
 *
 * Uses SH-2 hardware division unit for 64/32 division:
 *   DVSR = divisor
 *   DVDNTH:DVDNTL = dividend << 16 (as 64-bit signed)
 *   result = quotient
 *
 * This gives (dividend << 16) / divisor, which is the 16.16
 * fixed-point quotient of dividend / divisor.
 *
 * 8 instructions total. LEAF function.
 * ================================================================ */
int FUN_0602755C(int dividend, int divisor)
{
    long long big_dividend = (long long)dividend << 16;
    return (int)(big_dividend / divisor);
}
