/* vdp2_scroll.c -- VDP2 scroll screen initialization
 *
 * FUN_06011678: Set VDP2 scroll params and clear line scroll table
 *   First calls FUN_0601164A to configure scroll registers,
 *   then clears 256 ints (1KB) at VDP2 VRAM 0x25E5F800
 *   (this is likely a line scroll/color offset table).
 *
 * Original address: 0x06011678
 */

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
