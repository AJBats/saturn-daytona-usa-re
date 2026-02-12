/* mode_transition.c -- Mode/state transition checks
 *
 * Functions:
 *   FUN_0601F8C0 (0x0601F8C0) -- Check and execute mode transition
 *   FUN_0601F900 (0x0601F900) -- VDP2 flag check and VRAM write
 *
 * Original addresses: 0x0601F8C0, 0x0601F900
 */

/* Mode check function (sets flag at 0x0605E05C if transition needed) */
extern int FUN_0601f5e0(void);

/* VDP/rendering re-initialization */
extern void FUN_060149E0(void);

/* Mode-specific cleanup */
extern void FUN_0601f9cc(void);

/* Physics pause/trigger update (defined in game_state_utils.c) */
extern void FUN_060149CC(void);

/* VDP2 VRAM write helper: (dest_addr, count, src_data_ptr) */
extern void vdp2_bitmap_load(int addr, int count, void *data);

/* Mode reset/fallback */
extern void FUN_0601fd20(void);

/* Transition-needed flag (byte) */
#define TRANSITION_FLAG    (*(volatile unsigned char *)0x0605E05C)


/* ================================================================
 * FUN_0601F8C0 -- Mode Transition Check (0x0601F8C0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601F8C0-0x0601F8F2)
 * Pool verified:
 *   0x0601F8F4 = 0x0605E05C (transition flag byte)
 *   0x0601F8F8 = 0x060149E0 (VDP init function)
 *   0x0601F8FC = 0x060149CC (physics pause function)
 *   BSR target 0x0601F5E0 (mode check function)
 *   BSR target 0x0601F9CC (mode cleanup function)
 *
 * 24 instructions. Saves PR. Returns int.
 * ================================================================ */
int FUN_0601F8C0(void)
{
    /* Clear transition flag */
    TRANSITION_FLAG = 0;

    /* Run mode check (may set flag) */
    FUN_0601f5e0();

    /* If flag still clear, no transition needed */
    if (TRANSITION_FLAG == 0) {
        return 1;
    }

    /* Execute mode transition */
    FUN_060149E0();
    FUN_0601f9cc();
    FUN_060149CC();
    return 0;
}


/* ================================================================
 * FUN_0601F900 -- VDP2 Flag Check / VRAM Write (0x0601F900)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601F900-0x0601F934)
 * Pool verified:
 *   0x0601F968 = 0x06063D9A (input flag word)
 *   0x0601F960 = 0x0009 (bit mask, word constant)
 *   0x0601F962 = 0x0800 (VDP2 write value, word constant)
 *   0x0601F96C = 0x25E7FFFE (VDP2 VRAM destination)
 *   0x0601F970 = 0x06036E90 (VDP2 VRAM write helper)
 *   BSR target 0x0601FD20 (mode reset/fallback)
 *
 * Reads a 16-bit flag at 0x06063D9A, masks with 0x0009.
 * If any bits set: writes 0x0800 to VDP2 VRAM via helper, returns 1.
 * If clear: calls FUN_0601fd20 (mode reset), returns 0.
 *
 * 28 instructions. Saves PR. Returns int.
 * ================================================================ */
int FUN_0601F900(void)
{
    unsigned short val = *(volatile unsigned short *)0x06063D9A;

    if ((val & 0x0009) != 0) {
        /* Write 0x0800 to VDP2 VRAM at 0x25E7FFFE */
        short local_data = 0x0800;
        vdp2_bitmap_load(0x25E7FFFE, 1, &local_data);
        return 1;
    }

    /* No relevant flags set -- execute fallback */
    FUN_0601fd20();
    return 0;
}
