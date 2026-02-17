/* display_fade.c -- Display brightness fade-in/fade-out control
 *
 * Functions:
 *   FUN_0601D478 (0x0601D478) -- Brightness fade init: set params, start fade
 *   FUN_0601D4A8 (0x0601D4A8) -- Brightness fade step: per-frame fade update
 *
 * These functions control the screen brightness fade effect used
 * during state transitions (attract mode, post-race, etc.).
 *
 * Shared registers:
 *   0x0605AAA2: Fade mode flag (short, set to 2 during init)
 *   0x0607885C: Current brightness level (int, decremented by 0x100000)
 *   0x0607886E: Fade timer (short, decremented by 2 per frame)
 *   0x0607887F: Fade phase counter (byte, incremented when timer expires)
 *
 * Original addresses: 0x0601D478, 0x0601D4A8
 */

/* Render parameter setter (type, value, flags) */
extern void FUN_06014884(int type, int value, int flags);

/* Sound/display fade table lookup (lowercase: defined in batch_subsystem_1c.c) */
extern void FUN_0601d57c(int timer_value);


/* ================================================================
 * FUN_0601D478 -- Brightness Fade Init (0x0601D478)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601D478-0x0601D4A6)
 * Pool verified:
 *   0x0601D4F0 = 0x0605AAA2 (fade mode flag)
 *   0x0601D4F4 = 0x01500000 (initial brightness)
 *   0x0601D4F8 = 0x0607885C (brightness register)
 *   0x0601D4FC = 0x06014884 (render parameter setter)
 *   0x0601D500 = 0x0607886E (fade timer)
 *   0x0601D504 = 0x0607887F (fade phase counter)
 *
 * Sets fade mode=2, initial brightness=0x01500000, calls render param
 * setter with mesh attribute (32), sets timer to 42, calls fade table
 * lookup, increments phase counter.
 *
 * 24 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
/* FUN_0601D478 -- original binary (48 bytes) */
__asm__(
    ".section .text.FUN_0601D478, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601D478\n"
    ".type _FUN_0601D478, @function\n"
    "_FUN_0601D478:\n"
    ".byte 0x4F, 0x22, 0xE2, 0x02, 0xE6, 0x00, 0xD3, 0x1C, 0x23, 0x21, 0xD3, 0x1C, 0xD2, 0x1C, 0x22, 0x32\n"  /* 0x0601D478 */
    ".byte 0x65, 0x23, 0xD3, 0x1C, 0x65, 0x52, 0x43, 0x0B, 0xE4, 0x20, 0xE2, 0x2A, 0xD3, 0x1A, 0x23, 0x21\n"  /* 0x0601D488 */
    ".byte 0xB0, 0x70, 0x64, 0x23, 0xD4, 0x19, 0x4F, 0x26, 0x62, 0x40, 0x72, 0x01, 0x00, 0x0B, 0x24, 0x20\n"  /* 0x0601D498 */
);



/* ================================================================
 * FUN_0601D4A8 -- Brightness Fade Step (0x0601D4A8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601D4A8-0x0601D4EE)
 * Pool verified:
 *   0x0601D508 = 0x00100000 (fade step amount)
 *   0x0601D500 = 0x0607886E (fade timer)
 *   0x0601D4F8 = 0x0607885C (brightness register)
 *   0x0601D4FC = 0x06014884 (render parameter setter)
 *   0x0601D504 = 0x0607887F (fade phase counter)
 *
 * Per-frame fade update. If timer != 0: decreases brightness by
 * 0x100000, applies via render param setter, decreases timer by 2,
 * calls fade table lookup. If timer == 0: increments phase counter,
 * decreases brightness by 0x100000.
 *
 * 36 instructions (incl. delay slots + pool). Saves PR + r13 + r14.
 * ================================================================ */
void FUN_0601D4A8(void)
{
    unsigned short timer = *(volatile unsigned short *)0x0607886E;

    if (timer != 0) {
        /* Fade in progress: decrease brightness and update */
        *(volatile int *)0x0607885C -= 0x00100000;
        FUN_06014884(32, *(volatile int *)0x0607885C, 0);

        /* Decrease timer by 2 and update fade table */
        *(volatile short *)0x0607886E = (short)(timer - 2);
        FUN_0601d57c((int)(timer - 2));
    } else {
        /* Fade complete: increment phase counter, final brightness step */
        (*(volatile unsigned char *)0x0607887F)++;
        *(volatile int *)0x0607885C -= 0x00100000;
    }
}
