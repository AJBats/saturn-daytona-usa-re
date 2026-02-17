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
/* FUN_0600FD54 -- original binary (54 bytes) */
__asm__(
    ".section .text.FUN_0600FD54, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600FD54\n"
    ".global _FUN_0600fd54\n"
    ".type _FUN_0600FD54, @function\n"
    "_FUN_0600FD54:\n"
    "_FUN_0600fd54:\n"
    ".byte 0x4F, 0x22, 0xD5, 0x1F, 0xD3, 0x1F, 0x43, 0x0B, 0xE4, 0x00, 0xE2, 0x78, 0xD3, 0x1E, 0x23, 0x21\n"  /* 0x0600FD54 */
    ".byte 0xE2, 0x0B, 0xD3, 0x1E, 0x23, 0x20, 0xB7, 0x2B, 0x00, 0x09, 0xD3, 0x1D, 0x43, 0x0B, 0x00, 0x09\n"  /* 0x0600FD64 */
    ".byte 0xD0, 0x1C, 0x60, 0x00, 0x20, 0x08, 0x8B, 0x03, 0xE4, 0x01, 0xD3, 0x1B, 0x43, 0x2B, 0x4F, 0x26\n"  /* 0x0600FD74 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0600FD84 */
);



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
#if 0 /* FUN_0600FD8A -- replaced by ASM import */
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
#endif

/* FUN_0600FD8A -- original binary (116 bytes) */
__asm__(
    ".section .text.FUN_0600FD8A, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600FD8A\n"
    ".global _FUN_0600fd8a\n"
    ".type _FUN_0600FD8A, @function\n"
    "_FUN_0600FD8A:\n"
    "_FUN_0600fd8a:\n"
    ".byte 0x4F, 0x22, 0xD4, 0x13, 0x63, 0x41, 0x73, 0xFF, 0x24, 0x31, 0x63, 0x3F, 0x43, 0x11, 0x89, 0x0E\n"  /* 0x0600FD8A */
    ".byte 0xE3, 0x0C, 0xD2, 0x10, 0x64, 0x33, 0x22, 0x30, 0xD3, 0x13, 0x43, 0x0B, 0x00, 0x09, 0xD3, 0x11\n"  /* 0x0600FD9A */
    ".byte 0x43, 0x0B, 0xE4, 0x04, 0xE2, 0x14, 0xD3, 0x10, 0x23, 0x22, 0xA0, 0x20, 0x00, 0x09, 0xB7, 0x04\n"  /* 0x0600FDAA */
    ".byte 0x00, 0x09, 0xD3, 0x09, 0x43, 0x0B, 0x00, 0x09, 0xD0, 0x09, 0x60, 0x00, 0x20, 0x08, 0x8B, 0x16\n"  /* 0x0600FDBA */
    ".byte 0xE4, 0x01, 0xD3, 0x07, 0x43, 0x2B, 0x4F, 0x26, 0xFF, 0xFF, 0xAB, 0x11, 0x01, 0xFF, 0x06, 0x01\n"  /* 0x0600FDCA */
    ".byte 0xD5, 0xF4, 0x06, 0x07, 0x88, 0x7A, 0x06, 0x07, 0x88, 0x7F, 0x06, 0x01, 0x1E, 0xB4, 0x06, 0x08\n"  /* 0x0600FDDA */
    ".byte 0x5F, 0xF4, 0x06, 0x01, 0x14, 0xAC, 0x06, 0x02, 0x85, 0x3E, 0x06, 0x07, 0xEB, 0xCC, 0x4F, 0x26\n"  /* 0x0600FDEA */
    ".byte 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0600FDFA */
);



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
/* FUN_0600FDFE -- original binary (58 bytes) */
__asm__(
    ".section .text.FUN_0600FDFE, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600FDFE\n"
    ".global _FUN_0600fdfe\n"
    ".type _FUN_0600FDFE, @function\n"
    "_FUN_0600FDFE:\n"
    "_FUN_0600fdfe:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0xDE, 0x09, 0x63, 0xE2, 0x73, 0xFF, 0x43, 0x11, 0x8D, 0x09, 0x2E, 0x32\n"  /* 0x0600FDFE */
    ".byte 0xD5, 0x07, 0xD3, 0x07, 0x43, 0x0B, 0xE4, 0x00, 0x92, 0x06, 0x2E, 0x22, 0xE3, 0x0F, 0xD2, 0x05\n"  /* 0x0600FE0E */
    ".byte 0x22, 0x30, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x00, 0xB4, 0x06, 0x07, 0xEB, 0xCC, 0xAB, 0x11\n"  /* 0x0600FE1E */
    ".byte 0x0D, 0xFF, 0x06, 0x01, 0xD5, 0xF4, 0x06, 0x07, 0x88, 0x7F\n"  /* 0x0600FE2E */
);

