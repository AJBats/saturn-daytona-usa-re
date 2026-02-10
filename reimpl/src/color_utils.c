/* color_utils.c -- RGB555 color manipulation
 *
 * Saturn uses 15-bit RGB555 format: bits 14-10=Blue, 9-5=Green, 4-0=Red
 *
 * FUN_0601D0BC: Unpack RGB555 color into separate R, G, B components
 *
 * Original address: 0x0601D0BC
 */

void FUN_0601D0BC(unsigned short color, unsigned short *r, unsigned short *g, unsigned short *b)
{
    *r = color & 0x1f;
    *g = (unsigned short)((int)(unsigned int)color >> 5) & 0x1f;
    *b = (unsigned short)((int)(unsigned int)color >> 10) & 0x1f;
}
