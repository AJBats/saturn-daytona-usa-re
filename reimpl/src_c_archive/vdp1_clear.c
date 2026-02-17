/* vdp1_clear.c -- VDP1 VRAM and framebuffer clear
 *
 * Functions:
 *   FUN_0600A140 (0x0600A140) -- Clear VDP1 framebuffer (double-buffered)
 *
 * Writes end-of-command marker to VDP1 VRAM start (0x25C00000),
 * then clears 256KB of VDP1 framebuffer at 0x25C80000 twice
 * (double-buffer clear), calling FUN_06026CE0 and resetting
 * render state variables between each pass.
 *
 * VDP1 memory map:
 *   0x25C00000: VDP1 VRAM (command table)
 *   0x25C80000: VDP1 framebuffer
 *
 * Original address: 0x0600A140
 */

extern void FUN_06026CE0(void);

/* VDP1 VRAM command table start */
#define VDP1_VRAM_START    ((volatile int *)0x25C00000)

/* VDP1 framebuffer base */
#define VDP1_FB_BASE       ((volatile int *)0x25C80000)

/* Framebuffer size in dwords (256KB / 4 = 0x10000) */
#define VDP1_FB_DWORDS     0x10000

/* VDP1 end-of-command marker */
#define VDP1_CMD_END       ((int)0x80000000)

/* Render state variables */
#define RENDER_FLAG_A      (*(volatile int *)0x0605A00C)
#define RENDER_FLAG_B      (*(volatile int *)0x06059F44)


/* ================================================================
 * FUN_0600A140 -- VDP1 Framebuffer Double-Clear (0x0600A140)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A140-0x0600A198)
 * Pool verified:
 *   0x0600A19C = 0x80000000 (VDP1 end command)
 *   0x0600A1A0 = 0x25C00000 (VDP1 VRAM start)
 *   0x0600A1A4 = 0x25C80000 (VDP1 framebuffer)
 *   0x0600A1A8 = 0x00010000 (framebuffer size in dwords)
 *   0x0600A1AC = 0x0605A00C (render flag A)
 *   0x0600A1B0 = 0x06026CE0 (render state function)
 *   0x0600A1B4 = 0x06059F44 (render flag B)
 *
 * 44 instructions. Saves r14, PR. Two clear loops + state resets.
 * ================================================================ */
void FUN_0600A140(void)
{
    volatile int *p;
    int count;

    /* Write end-of-command marker to VDP1 VRAM start */
    *VDP1_VRAM_START = VDP1_CMD_END;

    /* Pass 1: Clear entire VDP1 framebuffer (256KB) */
    p = VDP1_FB_BASE;
    count = VDP1_FB_DWORDS;
    while (count) {
        *p++ = 0;
        *p++ = 0;
        count -= 2;
    }

    /* Reset render state, call display update */
    RENDER_FLAG_A = 0;
    FUN_06026CE0();
    RENDER_FLAG_B = 0;

    /* Pass 2: Clear framebuffer again (double-buffer) */
    p = VDP1_FB_BASE;
    count = VDP1_FB_DWORDS;
    while (count) {
        *p++ = 0;
        *p++ = 0;
        count -= 2;
    }

    /* Reset render state again */
    RENDER_FLAG_A = 0;
    FUN_06026CE0();
    RENDER_FLAG_B = 0;
}
