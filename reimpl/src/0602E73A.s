	.text
    .global gouraud_color_calc
gouraud_color_calc:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xA0, 0x15    /* bra 0x0602E770 (external) */
    shll r0
    .short  0x0000
    .long  DAT_06083264
    .long  0x0000023C
    .long  0x00000008
    .long  0x00000010
    .long  0x00000018
    .long  fpmul
    .long  isqrt
    .long  0x6473DD07
