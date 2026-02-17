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
/* FUN_0601F8C0 -- original binary (64 bytes) */
__asm__(
    ".section .text.FUN_0601F8C0, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601F8C0\n"
    ".type _FUN_0601F8C0, @function\n"
    "_FUN_0601F8C0:\n"
    ".byte 0x4F, 0x22, 0xE3, 0x00, 0xD2, 0x0B, 0x22, 0x30, 0xBE, 0x8A, 0x00, 0x09, 0xD2, 0x09, 0x62, 0x20\n"  /* 0x0601F8C0 */
    ".byte 0x62, 0x2C, 0x22, 0x28, 0x8B, 0x02, 0x4F, 0x26, 0x00, 0x0B, 0xE0, 0x01, 0xD3, 0x06, 0x43, 0x0B\n"  /* 0x0601F8D0 */
    ".byte 0x00, 0x09, 0xB0, 0x73, 0x00, 0x09, 0xD3, 0x05, 0x43, 0x0B, 0x00, 0x09, 0xE0, 0x00, 0x4F, 0x26\n"  /* 0x0601F8E0 */
    ".byte 0x00, 0x0B, 0x00, 0x09, 0x06, 0x05, 0xE0, 0x5C, 0x06, 0x01, 0x49, 0xE0, 0x06, 0x01, 0x49, 0xCC\n"  /* 0x0601F8F0 */
);



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
/* FUN_0601F900 -- original binary (56 bytes) */
__asm__(
    ".section .text.FUN_0601F900, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601F900\n"
    ".type _FUN_0601F900, @function\n"
    "_FUN_0601F900:\n"
    ".byte 0x4F, 0x22, 0x7F, 0xFC, 0xD3, 0x18, 0x62, 0x31, 0x93, 0x2B, 0x62, 0x2D, 0x22, 0x39, 0x22, 0x28\n"  /* 0x0601F900 */
    ".byte 0x89, 0x0A, 0x93, 0x27, 0x66, 0xF3, 0x2F, 0x31, 0xD4, 0x14, 0xD3, 0x15, 0x43, 0x0B, 0xE5, 0x01\n"  /* 0x0601F910 */
    ".byte 0x7F, 0x04, 0x4F, 0x26, 0x00, 0x0B, 0xE0, 0x01, 0xB1, 0xFA, 0x00, 0x09, 0xE0, 0x00, 0x7F, 0x04\n"  /* 0x0601F920 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09, 0xE3, 0x00\n"  /* 0x0601F930 */
);

