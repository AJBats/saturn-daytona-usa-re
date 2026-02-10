#include "saturn.h"

void boot(void) __attribute__((noreturn));
void boot(void)
{
    volatile unsigned short *vram = VDP2_VRAM;
    volatile unsigned short *vdp2 = (volatile unsigned short *)0x25F80000;
    int i;

    VDP2_TVMD = 0x0000;

    for (i = 1; i < 0x90; i++)
        vdp2[i] = 0x0000;

    vram[0] = 0x7C00;

    VDP2_BKTAU = 0x0000;
    VDP2_BKTAL = 0x0000;

    while (!(VDP2_TVSTAT & 0x0008))
        ;

    VDP2_TVMD = 0x8000;

    for (;;)
        ;
}
