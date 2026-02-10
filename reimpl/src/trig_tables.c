/* trig_tables.c -- Sine/cosine table lookups (fixed-point)
 *
 * The game stores a 4096-entry sine table at 0x002F2F20 in CD-ROM space.
 * Angles are in 16-bit fixed point where 0x10000 = 360 degrees.
 * Each entry is a 32-bit fixed-point value (16.16).
 *
 * FUN_06027348 = sin(angle)  -- lookup in table
 * FUN_06027344 = cos(angle)  -- sin(angle + 0x4000) = sin(angle + 90 degrees)
 *
 * Original addresses: 0x06027344, 0x06027348
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
