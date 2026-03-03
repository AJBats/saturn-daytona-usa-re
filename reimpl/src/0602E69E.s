	.text
    .global vdp2_color_offset_anim
vdp2_color_offset_anim:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xA0, 0x11    /* bra 0x0602E6CC (external) */
    shll r0
    .short  0x0000
    .long  0x00000008
    .long  0x00000010
    .long  0x00000018
    .long  fpmul
    .long  isqrt
    .long  0x6473DD07
