/* vdp2_scroll.c -- VDP2 scroll screen initialization
 *
 * FUN_06011678: Set VDP2 scroll params and clear line scroll table
 *   First calls FUN_0601164A to configure scroll registers,
 *   then clears 256 ints (1KB) at VDP2 VRAM 0x25E5F800
 *   (this is likely a line scroll/color offset table).
 *
 * Original address: 0x06011678
 */

#if 0 /* FUN_06011678 -- replaced by ASM import */
extern void FUN_0601164A(void);

void FUN_06011678(void)
{
    int *p;
    int i;

    p = (int *)0x25E5F800;
    FUN_0601164A();
    i = 0;
    do {
        p[i] = 0;
        i = i + 1;
    } while (i < 0x0100);
}
#endif

/* FUN_06011678 -- original binary (48 bytes) */
__asm__(
    ".section .text.FUN_06011678, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06011678\n"
    ".type _FUN_06011678, @function\n"
    "_FUN_06011678:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x4F, 0x22, 0x9D, 0x0F, 0xDC, 0x08, 0xBF, 0xE1, 0xEE, 0x00\n"  /* 0x06011678 */
    ".byte 0x64, 0xED, 0x60, 0x4D, 0x40, 0x08, 0x74, 0x01, 0x63, 0x4D, 0x33, 0xD3, 0x8F, 0xF9, 0x0C, 0xE6\n"  /* 0x06011688 */
    ".byte 0x4F, 0x26, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x01, 0x00, 0x25, 0xE5, 0xF8, 0x00\n"  /* 0x06011698 */
);

