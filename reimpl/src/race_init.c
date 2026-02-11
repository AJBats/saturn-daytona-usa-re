#include "game.h"

/*
 * race_init.c -- Race initialization master function
 *
 * Hand-translated from annotated ASM (asm/object_management.s lines 143-202)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Function:
 *   FUN_0600EB14 (0x0600EB14) -- Race initialization master
 *
 * Called from 3 state handlers (0x06008956, 0x06008FAC, 0x06009EB2)
 * when transitioning into a race. This is the master setup function
 * that prepares all race-related systems before the race begins.
 *
 * Steps:
 *   1. Zeroes the entire car array (40 cars * 616 bytes = 24640 bytes)
 *   2. Calls 3 subsystem initializers (matrix init A, B; car loop init)
 *   3. Sets player car (car[0]) activation flags at +0x120..+0x12C
 *   4. Zeroes ~30 global race state variables (byte/word/long as appropriate)
 *   5. Sets initial difficulty to 5
 *   6. Zeroes 5 halfwords at 0x0602FD98
 *   7. Calls FUN_06021450 (unknown init)
 *   8. Tail-calls FUN_06018634 (track geometry accessor)
 *
 * NOTE: The Ghidra L1 lift (batch_game_logic_c.c, lowercase name) has
 * 8 incorrect access sizes -- many byte/word writes rendered as int writes.
 * This hand translation uses correct sizes verified from binary opcodes.
 */

/* Forward declarations for external dependencies */
extern void FUN_06026E02(void);    /* matrix identity init A (0x06089EE0) */
extern void FUN_060270C6(void);    /* matrix identity init B (0x0608A530) */
extern void FUN_0600629C(void);    /* car array iteration init loop */
extern void FUN_06021450(void);    /* extended init function */
extern int FUN_06018634(void);     /* track geometry data accessor */


/* ================================================================
 * FUN_0600EB14 -- Race Initialization Master (0x0600EB14)
 *
 * CONFIDENCE: DEFINITE (object_management.s lines 143-202, binary verified)
 * Pool verified:
 *   0x0600EBDC = 0x06078900 (car array base)
 *   0x0600EBD8 = 0x1810 (zero loop count: 6160 * 4 = 24640 bytes)
 *   0x0600EBDA = 0x0120 (activation flag offset in car struct)
 *   0x0600EBE0 = 0x06026E02 (matrix init A)
 *   0x0600EBE4 = 0x060270C6 (matrix init B)
 *   0x0600EBE8 = 0x0600629C (car iteration init)
 *   0x0600EBEC = 0x06063F46 (first global to zero)
 *   ... (30+ pool entries for global variable addresses)
 *   0x0600EC54 = 0x0602FD98 (halfword block base)
 *   0x0600EC70 = 0x06021450 (extended init)
 *   0x0600EC74 = 0x06018634 (track geometry, tail-call)
 * ================================================================ */
void FUN_0600EB14(void)
{
    volatile int *ptr;
    unsigned int i;

    /* Step 1: Zero the entire car array (40 cars * 0x268 bytes each) */
    ptr = (volatile int *)CAR_ARRAY_BASE;
    for (i = 0; i < 0x1810; i++)
        *ptr++ = 0;

    /* Step 2: Call subsystem initializers */
    FUN_06026E02();     /* matrix identity init for stack A */
    FUN_060270C6();     /* matrix identity init for stack B */
    FUN_0600629C();     /* car array iteration + per-car type init */

    /* Step 3: Set car[0] activation flags (4 consecutive ints at +0x120) */
    *(volatile int *)(CAR_ARRAY_BASE + CAR_ACTIVATE_1) = 1;
    *(volatile int *)(CAR_ARRAY_BASE + CAR_ACTIVATE_2) = 1;
    *(volatile int *)(CAR_ARRAY_BASE + CAR_ACTIVATE_3) = 1;
    *(volatile int *)(CAR_ARRAY_BASE + CAR_ACTIVATE_4) = 1;

    /* Step 4: Zero global race state variables
     * Access sizes match binary opcodes exactly (byte/word/long) */
    *(volatile short *)0x06063F46 = 0;
    *(volatile int *)0x0607EAE4 = 0;
    *(volatile int *)0x0607EAE8 = 0;
    *(volatile int *)0x0607EAEC = 0;
    GAME_STATE_VAR = 0;                        /* 0x0607EBD0 */
    *(volatile int *)0x0607EBF4 = 0;

    /* Step 5: Set initial difficulty to 5 (byte write) */
    *(volatile char *)0x06078654 = 5;

    /* Continue zeroing globals */
    *(volatile int *)0x0605A1C4 = 0;
    *(volatile int *)0x06082A30 = 0;
    *(volatile int *)0x0607EABC = 0;
    *(volatile int *)0x0607EAC0 = 0;
    *(volatile char *)0x06083260 = 0;          /* byte */
    *(volatile char *)0x06082A26 = 0;          /* byte */
    *(volatile int *)0x060788FC = 0;
    *(volatile int *)0x06082A38 = 0;
    *(volatile char *)0x06083261 = 0;          /* byte: update mode = 0 */
    *(volatile int *)0x0608325C = 0;
    *(volatile int *)0x06083258 = 0;
    *(volatile int *)0x0605A21C = 0;
    *(volatile short *)0x06086058 = 0;         /* word */
    *(volatile char *)0x0608605A = 0;          /* byte */
    *(volatile char *)0x0605DE3C = 0;          /* byte */
    *(volatile int *)0x060786A8 = 0;
    *(volatile int *)0x060786BC = 0;
    *(volatile char *)0x06085FCC = 0;          /* byte */
    *(volatile char *)0x06087060 = 0;          /* byte */

    /* Step 6: Zero 5 halfwords at 0x0602FD98 */
    *(volatile short *)0x0602FD98 = 0;
    *(volatile short *)0x0602FD9A = 0;
    *(volatile short *)0x0602FD9C = 0;
    *(volatile short *)0x0602FD9E = 0;
    *(volatile short *)0x0602FDA0 = 0;

    /* Step 7: Call extended init */
    FUN_06021450();

    /* Step 8: Tail-call track geometry accessor */
    FUN_06018634();
}
