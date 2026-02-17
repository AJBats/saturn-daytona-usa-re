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
#if 0 /* vdp_system_init_b -- redirected to ASM import via linker PROVIDE */
void vdp_system_init_b(void)
{
    *(volatile unsigned short *)0x060A3D88 &= 0x7FFF;
    *(volatile short *)0x060635AC = 1;
}
#endif /* vdp_system_init_b */
/* REMOVED: conflicting alias */ // void FUN_060149CC(void) __attribute__((alias("vdp_system_init_b")));

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


/* ================================================================
 * FUN_0600A1B8 -- Game Parameter Writer (0x0600A1B8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A1B8-0x0600A1F4)
 * Pool verified:
 *   0x0600A228 = 0x06078635 (game active flag byte)
 *   0x0600A22C = 0x0607ED8C (timer/counter short)
 *   0x0600A230 = 0x0605AD00 (state active flag int)
 *   0x0600A234 = 0x0607ED90 (destination param struct, 3 bytes)
 *   0x0600A238 = 0x06063F44 (course param short)
 *   0x0600A23C = 0x06078868 (game param A int)
 *   0x0600A240 = 0x0607EAB8 (game param B int)
 *
 * Writes 3 parameter bytes to 0x0607ED90:
 *   [0] = low byte of course param at 0x06063F44
 *   [1] = low byte of game param A at 0x06078868
 *   [2] = low byte of game param B at 0x0607EAB8
 *
 * Skips writing (returns early) if the game active flag is clear
 * AND either the timer at 0x0607ED8C or the state at 0x0605AD00
 * is nonzero.
 *
 * Leaf function (no PR save). 29 instructions + pool.
 * ================================================================ */
void FUN_0600A1B8(void)
{
    unsigned char flag = *(volatile unsigned char *)0x06078635;

    if (flag == 0) {
        unsigned short timer = *(volatile unsigned short *)0x0607ED8C;
        if (timer != 0) return;

        int state = *(volatile int *)0x0605AD00;
        if (state != 0) return;
    }

    /* Write 3 parameter bytes to destination struct */
    *(volatile unsigned char *)0x0607ED90 =
        (unsigned char)(*(volatile short *)0x06063F44);
    *((volatile unsigned char *)0x0607ED90 + 1) =
        (unsigned char)(*(volatile int *)0x06078868);
    *((volatile unsigned char *)0x0607ED90 + 2) =
        (unsigned char)(*(volatile int *)0x0607EAB8);
}
