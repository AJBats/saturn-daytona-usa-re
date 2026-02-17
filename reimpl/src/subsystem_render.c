/* subsystem_render.c -- Subsystem rendering / graphics command dispatch
 *
 * Functions:
 *   FUN_06012AC4 (0x06012AC4) -- Triple graphics command: 3x FUN_060283e0
 *   FUN_06012AFA (0x06012AFA) -- Conditional render: flag check + dispatch
 *
 * These functions handle rendering command dispatch for the subsystem
 * display pipeline. FUN_06012AFA checks bit 2 of the render state flag
 * at 0x060788FC and either calls the single-draw path (FUN_06028400)
 * or falls back to the triple-draw default (FUN_06012AC4).
 *
 * Original addresses: 0x06012AC4, 0x06012AFA
 */

/* VDP command writer (defined in batch_vdp_cmd_28.c as FUN_060283e0) */
extern char *FUN_060283e0(int cmd, int offset, int size, char *data);

/* Graphics draw command (defined in batch_vdp_cmd_28.c) */
extern int FUN_06028400(int cmd, int src, int size, int dst);

/* Render state flags (32-bit at 0x060788FC) */
#define RENDER_STATE_FLAGS (*(volatile int *)0x060788FC)

/* Graphics data base pointer (32-bit at 0x06063800) */
#define GFX_DATA_BASE      0x06063800

/* Overlay data pointer */
#define OVERLAY_DATA_PTR   ((char *)0x0605ACDD)


/* ================================================================
 * FUN_06012AC4 -- Triple Graphics Command (0x06012AC4)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012AC4-0x06012AF8)
 * Pool verified:
 *   0x06012B40 = 0x0605ACDD (overlay data pointer)
 *   0x06012B44 = 0x060283E0 (VDP command writer)
 *   0x06012B48 = 0x0000F000 (size parameter)
 *   word pool at 0x06012B36 = 0x061C (offset 1)
 *   word pool at 0x06012B38 = 0x069C (offset 2)
 *   word pool at 0x06012B3A = 0x071C (offset 3)
 *
 * Calls FUN_060283e0 three times with different offset parameters
 * (0x061C, 0x069C, 0x071C) but same cmd=8, size=0xF000, data=0x0605ACDD.
 * The three offsets are 0x80 apart (128 bytes each).
 *
 * 18 instructions. Saves PR + r12-r14.
 * ================================================================ */
/* FUN_06012AC4 -- original binary (54 bytes) */
__asm__(
    ".section .text.FUN_06012AC4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012AC4\n"
    ".type _FUN_06012AC4, @function\n"
    "_FUN_06012AC4:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x4F, 0x22, 0xDC, 0x1C, 0xDD, 0x1D, 0xDE, 0x1D, 0x95, 0x30\n"  /* 0x06012AC4 */
    ".byte 0x67, 0xC3, 0x66, 0xE3, 0x4D, 0x0B, 0xE4, 0x08, 0x67, 0xC3, 0x66, 0xE3, 0x95, 0x2A, 0x4D, 0x0B\n"  /* 0x06012AD4 */
    ".byte 0xE4, 0x08, 0x67, 0xC3, 0x66, 0xE3, 0x95, 0x26, 0x4D, 0x0B, 0xE4, 0x08, 0x4F, 0x26, 0x6C, 0xF6\n"  /* 0x06012AE4 */
    ".byte 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06012AF4 */
);



/* ================================================================
 * FUN_06012AFA -- Conditional Render Dispatch (0x06012AFA)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012AFA-0x06012B34)
 * Pool verified:
 *   0x06012B4C = 0x060788FC (render state flags)
 *   0x06012B50 = 0x06063800 (graphics data base)
 *   word pool at 0x06012B36 = 0x061C (size parameter)
 *   word pool at 0x06012B3C = 0x4000 (destination offset)
 *   0x06012B54 = 0x06028400 (graphics draw command)
 *   BSR target 0x06012AC4 (triple command fallback)
 *
 * Tests bit 2 of render state flags. If set: reads graphics data
 * pointers from 0x06063800, calls FUN_06028400 for single draw.
 * If clear: calls FUN_06012AC4 for triple default draw.
 * Either way, increments render state flags counter.
 *
 * 28 instructions. Saves PR + r14.
 * ================================================================ */
void FUN_06012AFA(void)
{
    int flags = RENDER_STATE_FLAGS;

    if (flags & 0x04) {
        /* Bit 2 set: single graphics draw from data table */
        int src = *(volatile int *)GFX_DATA_BASE;
        int dst = *(volatile int *)(GFX_DATA_BASE + 4) + 0x4000;
        FUN_06028400(8, src, 0x061C, dst);
    } else {
        /* Bit 2 clear: triple overlay draw */
        FUN_06012AC4();
    }

    /* Increment render state counter */
    RENDER_STATE_FLAGS = RENDER_STATE_FLAGS + 1;
}
