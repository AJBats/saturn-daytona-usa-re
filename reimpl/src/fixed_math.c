/* fixed_math.c -- Fixed-point multiply (16.16 format)
 *
 * FUN_06027552 = fixed-point multiply: (a * b) >> 16
 *   Takes two 16.16 fixed-point values, returns their product in 16.16.
 *   Uses 64-bit intermediate to avoid overflow.
 *
 * Original address: 0x06027552
 */

unsigned int FUN_06027552(int param_1, int param_2)
{
    return (int)((unsigned long long)((long long)param_2 * (long long)param_1) >> 0x20) << 0x10 |
           (unsigned int)((long long)param_2 * (long long)param_1) >> 0x10;
}
