/*
 * math_utils.c -- Math and bitwise utility functions
 *
 * Translated from production ASM / existing decomp src/*.c
 */

/* FUN_06035438 -- Absolute value */
int abs_val(int x)
{
    if (x < 1)
        x = -x;
    return x;
}

/* FUN_0602754C -- Extract high 16 bits as signed short */
int hi16_signed(int x)
{
    return (int)(short)((unsigned int)x >> 16);
}
