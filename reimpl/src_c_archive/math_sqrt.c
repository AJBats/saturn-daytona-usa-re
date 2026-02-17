/* math_sqrt.c -- Integer square root (binary search)
 *
 * FUN_06027476: Compute integer square root using binary search.
 *   Input: unsigned 32-bit integer
 *   Output: sqrt(input) << 8 (8.8 fixed-point result for better precision)
 *   Algorithm: Bit-by-bit approximation, starting from bit 15 down to bit 0.
 *
 * Original address: 0x06027476
 */

int FUN_06027476(unsigned int param_1)
{
    int result;
    int bit;
    int sq;

    result = 0;
    if ((int)param_1 > 0) {
        bit = 0x8000;
        do {
            result = result + bit;
            sq = result * result;
            if ((unsigned int)sq == param_1) break;
            if ((unsigned int)sq > param_1) {
                result = result - bit;
            }
            bit = bit >> 1;
        } while (bit > 0);
    }
    return result << 8;
}
