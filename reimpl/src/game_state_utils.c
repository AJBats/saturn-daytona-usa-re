/*
 * game_state_utils.c -- Game state flag manipulation
 *
 * Key globals:
 *   0x060A3D88 (unsigned short) -- physics mode flags
 *     bit 15: physics paused flag
 *   0x060635AC (short) -- physics update counter/trigger
 *
 * Translated from production ASM / existing decomp src/*.c
 */

/* FUN_060149E0 -- Clear physics pause flag, trigger update */
void FUN_060149E0(void)
{
    *(volatile unsigned short *)0x060A3D88 &= 0x7FFF;
    *(volatile short *)0x060635AC = 1;
}

/* FUN_060149CC -- Set physics pause flag, trigger update */
void FUN_060149CC(void)
{
    *(volatile unsigned short *)0x060A3D88 |= 0x8000;
    *(volatile short *)0x060635AC = 1;
}

/* FUN_060054EA -- Set game subsystem pointer and clear counters */
void FUN_060054EA(int param)
{
    *(volatile int *)0x06063E04 = param;
    *(volatile short *)0x06063E08 = 0;
    *(volatile int *)0x06063F08 = 0;
    *(volatile int *)0x06063F04 = 0;
}

/* FUN_06026DF8 -- Decrement stack/buffer pointer by 0x30 */
void FUN_06026DF8(void)
{
    *(volatile int *)0x06089EDC -= 0x30;
}

/* FUN_0603C156 -- Read course/track ID from flags */
int FUN_0603C156(void)
{
    return (int)((unsigned int)*(volatile unsigned short *)0x060A3D96 & *(int *)0x0603C17A) >> 12;
}
