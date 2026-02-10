#include "saturn.h"
#include "game.h"

/*
 * vdp_init_dispatcher -- FUN_06003274
 *
 * Sets up VDP rendering pipeline via BIOS function calls.
 * 6 calls through indirect function pointer at 0x06000310 with
 * different command codes and render buffer addresses.
 *
 * From disassembly (0x06003274-0x06003308):
 *   r14 = *(0x060032C0) = 0x06000310 (BIOS function table)
 *   Call 1: cmd=4,  dest=0x06028218
 *   Call 2: cmd=6,  dest=0x06028230
 *   Call 3: cmd=9,  dest=0x06028248
 *   Call 4: cmd=0xFE10 (sign-ext to 0xFFFFFE10), dest=0x06028218
 *   Call 5: cmd=0xFE11 (sign-ext to 0xFFFFFE11), dest=0x06028230
 *   Call 6: cmd=0xFE16 (sign-ext to 0xFFFFFE16), dest=0x06028248
 *           (last call is tail-call via jmp)
 *
 * The 0xFFFFFExx command codes correspond to SH-2 on-chip FRT register
 * addresses: TIER (0xFFFFFE10), FTCSR (0xFFFFFE11), FRC (0xFFFFFE16).
 * The BIOS function likely installs interrupt vectors pointing to the
 * render buffer addresses.
 */
void vdp_init_dispatcher(void)
{
    void (*bios_fn)(int, int) = BIOS_FUNC_0310;

    /* Set up VDP command handlers */
    bios_fn(4,  0x06028218);
    bios_fn(6,  0x06028230);
    bios_fn(9,  0x06028248);

    /* Set up FRT interrupt vectors for rendering pipeline */
    bios_fn((int)(short)0xFE10, 0x06028218);
    bios_fn((int)(short)0xFE11, 0x06028230);
    bios_fn((int)(short)0xFE16, 0x06028248);
}
