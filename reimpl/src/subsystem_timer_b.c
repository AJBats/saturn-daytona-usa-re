/* subsystem_timer_b.c -- Secondary subsystem timer (address 0x0607887A)
 *
 * Functions:
 *   FUN_0600FD54 (0x0600FD54) -- Init: sound stop, timer=120, state=11
 *   FUN_0600FD8A (0x0600FD8A) -- Tick: decrement timer, dispatch or expire
 *   FUN_0600FDFE (0x0600FDFE) -- Countdown: decrement render cache, expire→sound+reset
 *
 * These use a different timer counter at 0x0607887A (vs 0x0607887C
 * used by subsystem_counter.c). Same state flag at 0x0607887F.
 *
 * Original addresses: 0x0600FD54, 0x0600FD8A, 0x0600FDFE
 */

/* Sound command dispatch */
extern void FUN_0601D5F4(int cmd, int param);

/* Subsystem processing helpers */
extern int FUN_06010bc4(void);
extern void FUN_06011eb4(void);

/* Config helper */
extern int *vdp_display_list_fill(int channel);

/* Subsystem init (returns unsigned int) */
extern unsigned int FUN_060114ac(int param);

/* Secondary timer counter (16-bit at 0x0607887A) */
#define TIMER_B_COUNTER    (*(volatile short *)0x0607887A)

/* Subsystem state flag (8-bit, shared with subsystem_counter.c) */
#define SUBSYS_STATE_FLAG  (*(volatile char *)0x0607887F)

/* Render parameter cache (shared with subsystem_counter.c) */
#define RENDER_PARAM_CACHE (*(volatile int *)0x0607EBCC)

/* Audio/control state flag */
#define CONTROL_FLAG_B     (*(volatile char *)0x06085FF4)


/* ================================================================
 * FUN_0600FD54 -- Secondary Timer Init (0x0600FD54)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600FD54-0x0600FD88)
 * Pool verified:
 *   0x0600FDD4 = 0xAB1101FF (sound stop parameter)
 *   0x0600FDD8 = 0x0601D5F4 (sound_cmd_dispatch)
 *   0x0600FDDC = 0x0607887A (timer B counter)
 *   0x0600FDE0 = 0x0607887F (state flag)
 *   BSR target 0x06010BC4 (subsystem helper)
 *   0x0600FDE4 = 0x06011EB4 (processing helper)
 *   0x0600FDE8 = 0x06085FF4 (control flag)
 *   0x0600FDEC = 0x060114AC (subsystem init)
 *
 * Sends sound stop command, sets timer=120 (2 sec), state=11,
 * calls two processing helpers, then conditionally tail-calls
 * FUN_060114ac(1) if control flag is clear.
 *
 * 26 instructions. Saves PR.
 * ================================================================ */
void FUN_0600FD54(void)
{
    /* Sound stop command */
    FUN_0601D5F4(0, (int)0xAB1101FF);

    /* Set secondary timer to 120 frames (2 seconds) */
    TIMER_B_COUNTER = 120;

    /* Set subsystem state to 11 */
    SUBSYS_STATE_FLAG = 11;

    /* Run subsystem processing */
    FUN_06010bc4();
    FUN_06011eb4();

    /* If control flag clear, initialize subsystem */
    if (CONTROL_FLAG_B == 0) {
        FUN_060114ac(1);  /* tail-call in original */
    }
}


/* ================================================================
 * FUN_0600FD8A -- Secondary Timer Tick (0x0600FD8A)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600FD8A-0x0600FDFA)
 * Pool verified:
 *   0x0600FDDC = 0x0607887A (timer B counter)
 *   0x0600FDE0 = 0x0607887F (state flag)
 *   0x0600FDF0 = 0x0602853E (config helper)
 *   0x0600FDF4 = 0x0607EBCC (render param cache)
 *   BSR target 0x06010BC4 (subsystem helper)
 *   0x0600FDE4 = 0x06011EB4 (processing helper)
 *   0x0600FDE8 = 0x06085FF4 (control flag)
 *   0x0600FDEC = 0x060114AC (subsystem init)
 *
 * Decrements secondary timer. If expired (< 0): sets state=12,
 * calls vdp_display_list_fill(12) and (4), stores 20 to render cache.
 * If still running (>= 0): runs processing helpers, conditionally
 * tail-calls FUN_060114ac(1).
 *
 * 38 instructions. Saves PR.
 * ================================================================ */
void FUN_0600FD8A(void)
{
    short counter = TIMER_B_COUNTER;
    counter--;
    TIMER_B_COUNTER = counter;

    if (counter < 0) {
        /* Timer expired -- transition to next state */
        SUBSYS_STATE_FLAG = 12;
        vdp_display_list_fill(12);
        vdp_display_list_fill(4);
        RENDER_PARAM_CACHE = 20;
        return;
    }

    /* Timer still running -- continue processing */
    FUN_06010bc4();
    FUN_06011eb4();

    /* If control flag clear, reinitialize subsystem */
    if (CONTROL_FLAG_B == 0) {
        FUN_060114ac(1);  /* tail-call in original */
    }
}


/* ================================================================
 * FUN_0600FDFE -- Render Cache Countdown (0x0600FDFE)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600FDFE-0x0600FE24)
 * Pool verified:
 *   0x0600FE28 = 0x0607EBCC (render param cache)
 *   0x0600FE2C = 0xAB110DFF (sound command parameter)
 *   0x0600FE30 = 0x0601D5F4 (sound_cmd_dispatch)
 *   word pool at 0x0600FE26 = 0x00B4 (180)
 *   0x0600FE34 = 0x0607887F (state flag)
 *
 * Decrements render cache counter. If still >= 0, returns.
 * If < 0 (expired): sends sound command 0xAB110DFF, resets
 * counter to 180 (3 seconds), sets state flag to 15.
 *
 * 20 instructions. Saves PR + r14.
 * ================================================================ */
void FUN_0600FDFE(void)
{
    int counter = RENDER_PARAM_CACHE;
    counter--;
    RENDER_PARAM_CACHE = counter;

    if (counter < 0) {
        /* Timer expired -- send sound command and reset */
        FUN_0601D5F4(0, (int)0xAB110DFF);
        RENDER_PARAM_CACHE = 180;
        SUBSYS_STATE_FLAG = 15;
    }
}
