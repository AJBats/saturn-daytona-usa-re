/* subsystem_counter.c -- Subsystem memory counter update
 *
 * Functions:
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

/* Memory pointer global */
#define MEM_PTR_GLOBAL     (*(volatile int *)0x0607885C)

/* Frame counter (16-bit) */
#define FRAME_COUNTER      (*(volatile short *)0x0607886E)

/* Subsystem state flag (8-bit) */
#define SUBSYS_STATE_FLAG  (*(volatile char *)0x0607887F)


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
