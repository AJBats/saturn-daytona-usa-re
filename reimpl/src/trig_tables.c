/* trig_tables.c -- Sine/cosine table lookups (fixed-point)
 *
 * The game stores a 4096-entry sine table at 0x002F2F20 in low work RAM.
 * Angles are in 16-bit fixed point where 0x10000 = 360 degrees.
 * Each entry is a 32-bit fixed-point value (16.16).
 *
 * FUN_06027344 = cos(angle)  -- sin(angle + 0x4000) = sin(angle + 90 degrees)
 * FUN_06027348 = sin(angle)  -- lookup in table
 * FUN_06027358 = sincos pair -- stores sin to *r5, cos to *r6
 *
 * Original addresses: 0x06027344, 0x06027348, 0x06027358
 */

int FUN_06027348(unsigned int angle)
{
    unsigned int mask = 0x3FFC;
    unsigned int offset = ((angle >> 2) + 2) & mask;
    return *(int *)(0x002F2F20 + offset);
}

int FUN_06027344(int angle)
{
    int tmp = angle + 0x4000;
    unsigned int mask = 0x3FFC;
    unsigned int offset = (((unsigned int)tmp >> 2) + 2) & mask;
    return *(int *)(0x002F2F20 + offset);
}


/* ================================================================
 * FUN_06027358 -- Sin/Cos Pair Lookup (0x06027358)
 *
 * CONFIDENCE: DEFINITE (math_transform.s lines 683-726, binary verified)
 * Pool verified:
 *   0x060274FC = 0x4000 (cos phase offset = 90 degrees)
 *   0x060274FE = 0x3FFC (index mask, 4096 entries x 4 bytes)
 *   0x060274EC = 0x002F2F20 (table base in low work RAM)
 *
 * Combined sin/cos lookup used by all matrix rotation functions
 * and the player/AI physics pipelines. Called from 20+ sites.
 *
 * Parameters:
 *   angle = input angle (16-bit angle in 32-bit int)
 *   sin_out = pointer to store sin result (32-bit fixed-point)
 *   cos_out = pointer to store cos result (32-bit fixed-point)
 *
 * Algorithm:
 *   1. angle += 8 (half-entry rounding)
 *   2. sin_idx = (angle >> 2) & 0x3FFC (byte offset into table)
 *   3. cos_idx = ((angle + 0x4000) >> 2) & 0x3FFC
 *   4. *sin_out = table[sin_idx], *cos_out = table[cos_idx]
 * ================================================================ */
void FUN_06027358(int angle, int *sin_out, int *cos_out)
{
    unsigned int sin_idx, cos_idx;

    angle += 8;
    sin_idx = ((unsigned int)angle >> 2) & 0x3FFC;
    cos_idx = ((unsigned int)(angle + 0x4000) >> 2) & 0x3FFC;

    *sin_out = *(volatile int *)(0x002F2F20 + sin_idx);
    *cos_out = *(volatile int *)(0x002F2F20 + cos_idx);
}
