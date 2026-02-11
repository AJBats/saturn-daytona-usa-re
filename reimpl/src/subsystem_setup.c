/* subsystem_setup.c -- Subsystem initialization routines
 *
 * Functions:
 *   FUN_060198E0 (0x060198E0) -- Pre-race subsystem init with state byte config
 *
 * Calls configuration helpers, writes state bytes, then tail-calls
 * into the main subsystem handler chain.
 *
 * Original address: 0x060198E0
 */

extern void FUN_0602853E(int param);
extern int *FUN_06028560(void);
extern void FUN_06019928(void);
extern void FUN_0601a80c(void);
extern void FUN_0601a940(void);

/* State configuration bytes */
#define SUBSYS_STATE_A   (*(volatile unsigned char *)0x06085FF1)
#define SUBSYS_STATE_B   (*(volatile unsigned char *)0x06085FF6)
#define SUBSYS_STATE_C   (*(volatile unsigned char *)0x06085FF7)


/* ================================================================
 * FUN_060198E0 -- Pre-Race Subsystem Init (0x060198E0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060198E0-0x0601990C)
 * Pool verified:
 *   0x06019910 = 0x0602853E (config helper A)
 *   0x06019914 = 0x06028560 (config helper B)
 *   0x06019918 = 0x06085FF1 (state byte A)
 *   0x0601991C = 0x06085FF6 (state byte B)
 *   0x06019920 = 0x06085FF7 (state byte C)
 *   BSR target 0x06019928 (local helper)
 *   BSR target 0x0601A80C (secondary init)
 *   0x06019924 = 0x0601A940 (tail-call target)
 *
 * 22 instructions. Saves PR. Tail-calls FUN_0601a940.
 * ================================================================ */
void FUN_060198E0(void)
{
    FUN_0602853E(12);
    FUN_06028560();

    /* Configure state bytes */
    SUBSYS_STATE_A = 1;
    SUBSYS_STATE_B = 1;
    SUBSYS_STATE_C = 0xFF;

    /* Chain into subsystem handlers */
    FUN_06019928();
    FUN_0601a80c();
    FUN_0601a940();  /* original: tail-jump via jmp @r3 */
}
