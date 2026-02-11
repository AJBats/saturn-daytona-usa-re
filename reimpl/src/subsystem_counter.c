/* subsystem_counter.c -- Subsystem memory counter update
 *
 * Functions:
 *   FUN_0600F822 (0x0600F822) -- Subsystem init: sound cmd + timer setup
 *   FUN_0600F898 (0x0600F898) -- Subsystem reset: clear counters, increment state
 *   FUN_0600F98C (0x0600F98C) -- Prologue: set r6=0, call FUN_0600F990
 *   FUN_0600F990 (0x0600F990) -- Advance memory pointer, increment counter, flag check
 *
 * FUN_0600F990 advances a 32-bit memory pointer global by 0x100000 (1MB),
 * passes the new address to FUN_06014884 as a rendering parameter,
 * increments a 16-bit frame counter at 0x0607886E by 2,
 * calls FUN_0601155e for display refresh, then checks if the global
 * has wrapped to zero (flags subsystem state = 8 if so).
 *
 * FUN_0600F98C is a 2-instruction prologue that sets r6=0 (third param
 * for FUN_06014884) and falls through to FUN_0600F990.
 *
 * Globals:
 *   0x0607885C: 32-bit memory pointer (advanced by 0x100000 per call)
 *   0x0607886E: 16-bit frame counter (incremented by 2 per call)
 *   0x0607887F: 8-bit subsystem state flag (set to 8 when pointer wraps)
 *
 * Original addresses: 0x0600F98C, 0x0600F990
 */

/* Rendering parameter setter (r4=type, r5=value, r6=flags) */
extern void FUN_06014884(int type, int value, int flags);

/* Display refresh function (takes counter value) */
extern void FUN_0601155e(unsigned short counter);

/* Sound command dispatch (defined in asm_game_core.c) */
extern void FUN_0601D5F4(int cmd, int param);

/* Subsystem init helpers */
extern unsigned int FUN_060114ac(int param);
extern void FUN_06011094(void);

/* VDP command reset (returns pointer) */
extern int *FUN_06028560(void);

/* Memory pointer global */
#define MEM_PTR_GLOBAL     (*(volatile int *)0x0607885C)

/* Frame counter (16-bit) */
#define FRAME_COUNTER      (*(volatile short *)0x0607886E)

/* Subsystem state flag (8-bit) */
#define SUBSYS_STATE_FLAG  (*(volatile char *)0x0607887F)

/* Timer counter (16-bit at 0x0607887C) */
#define TIMER_COUNTER      (*(volatile short *)0x0607887C)

/* Rendering parameter cache (32-bit at 0x0607EBCC) */
#define RENDER_PARAM_CACHE (*(volatile int *)0x0607EBCC)


/* ================================================================
 * FUN_0600F822 -- Subsystem Init: Sound + Timer Setup (0x0600F822)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F822-0x0600F846)
 * Pool verified:
 *   0x0600F858 = 0xAB1101FF (sound command parameter)
 *   0x0600F85C = 0x0601D5F4 (sound_cmd_dispatch)
 *   0x0600F860 = 0x060114AC (subsystem init A)
 *   0x0600F864 = 0x06011094 (subsystem init B)
 *   0x0600F868 = 0x0607887C (timer counter)
 *   0x0600F86C = 0x0607887F (state flag)
 *
 * Sends a sound command, calls two init helpers, sets timer=120,
 * state flag=3.
 *
 * 20 instructions. Saves PR.
 * ================================================================ */
void FUN_0600F822(void)
{
    /* Sound command: stop all (cmd=0, param=0xAB1101FF) */
    FUN_0601D5F4(0, (int)0xAB1101FF);

    /* Initialize subsystems */
    FUN_060114ac(0);
    FUN_06011094();

    /* Set timer to 120 frames (2 seconds at 60fps) */
    TIMER_COUNTER = 120;

    /* Set subsystem state to 3 */
    SUBSYS_STATE_FLAG = 3;
}


/* ================================================================
 * FUN_0600F898 -- Subsystem Reset: Clear Counters (0x0600F898)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F898-0x0600F8BC)
 * Pool verified:
 *   0x0600F8E8 = 0x06028560 (VDP command reset)
 *   word pool at 0x0600F8D4 = 0x0708 (1800 = 30sec timer)
 *   0x0600F8EC = 0x0607EBCC (render param cache)
 *   0x0600F8E0 = 0x0607887C (timer counter)
 *   0x0600F8F0 = 0x0607886E (frame counter)
 *   0x0600F8E4 = 0x0607887F (state flag)
 *
 * Calls VDP reset, stores 1800 to render cache, sets timer=20,
 * clears frame counter, increments state flag.
 *
 * 20 instructions. Saves PR.
 * ================================================================ */
void FUN_0600F898(void)
{
    /* Reset VDP command state */
    FUN_06028560();

    /* Set render parameter cache to 1800 (30 seconds at 60fps) */
    RENDER_PARAM_CACHE = 0x0708;

    /* Set timer to 20 frames */
    TIMER_COUNTER = 20;

    /* Clear frame counter */
    FRAME_COUNTER = 0;

    /* Increment subsystem state flag */
    SUBSYS_STATE_FLAG = SUBSYS_STATE_FLAG + 1;
}


/* ================================================================
 * FUN_0600F990 -- Subsystem Counter Update (0x0600F990)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F990-0x0600F9C4)
 * Pool verified:
 *   0x0600FA08 = 0x0607885C (memory pointer global)
 *   0x0600FA0C = 0x00100000 (1MB increment)
 *   0x0600FA10 = 0x06014884 (rendering parameter setter)
 *   0x0600FA14 = 0x0607886E (frame counter)
 *   0x0600FA18 = 0x0601155E (display refresh)
 *   0x0600FA1C = 0x0607887F (subsystem state flag)
 *
 * 27 instructions. Saves PR, uses r14 for global pointer.
 * ================================================================ */
void FUN_0600F990(void)
{
    int val;
    short cnt;

    /* Advance memory pointer by 1MB */
    val = MEM_PTR_GLOBAL;
    val += 0x100000;
    MEM_PTR_GLOBAL = val;

    /* Set rendering parameter: type=16, value=new pointer, flags=0 */
    FUN_06014884(16, val, 0);

    /* Increment frame counter by 2 */
    cnt = FRAME_COUNTER;
    cnt += 2;
    FRAME_COUNTER = cnt;

    /* Call display refresh with current counter */
    FUN_0601155e((unsigned short)cnt);

    /* If memory pointer wrapped to zero, flag subsystem state */
    if (MEM_PTR_GLOBAL == 0) {
        SUBSYS_STATE_FLAG = 8;
    }
}


/* ================================================================
 * FUN_0600F98C -- Subsystem Counter Prologue (0x0600F98C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F98C-0x0600F98E)
 *
 * 2-instruction prologue: pushes r14, sets r6=0 (flags param for
 * FUN_06014884), falls through to FUN_0600F990.
 * In C, just calls FUN_0600F990 (r6=0 is hardcoded in body).
 * ================================================================ */
void FUN_0600F98C(void)
{
    FUN_0600F990();
}
