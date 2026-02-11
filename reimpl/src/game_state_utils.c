/*
 * game_state_utils.c -- Game state flag manipulation
 *
 * Key globals:
 *   0x060A3D88 (unsigned short) -- physics mode flags
 *     bit 15: physics paused flag
 *   0x060635AC (short) -- physics update counter/trigger
 *
 * Translated from production ASM and existing decomp sources
 */

/* vdp_system_init_b -- Clear physics pause flag, trigger update */
void vdp_system_init_b(void)
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


/* ================================================================
 * FUN_0600A33C -- Mode-to-SubState Counter Mapper (0x0600A33C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A33C-0x0600A388)
 * Pool verified:
 *   0x0600A374 = 0x0605A016 (SUB_STATE_COUNTER)
 *   0x0600A378 = 0x06063E1C (course/mode selector)
 *
 * Maps the course/mode value at 0x06063E1C to a sub-state counter
 * value: 0->5, 1->6, 2->7, 3->8. If the mode is not 0-3, no
 * write occurs. Used during race state transitions.
 *
 * Leaf function (no PR save). 26 instructions + pool.
 * ================================================================ */
void FUN_0600A33C(void)
{
    int mode = *(volatile int *)0x06063E1C;

    if (mode == 0) {
        *(volatile short *)0x0605A016 = 5;
    } else if (mode == 1) {
        *(volatile short *)0x0605A016 = 6;
    } else if (mode == 2) {
        *(volatile short *)0x0605A016 = 7;
    } else if (mode == 3) {
        *(volatile short *)0x0605A016 = 8;
    }
}
