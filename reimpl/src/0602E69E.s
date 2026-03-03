
    .section .text.FUN_0602E69E


    .global vdp2_color_offset_anim
    .type vdp2_color_offset_anim, @function
vdp2_color_offset_anim:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xA0, 0x11    /* bra 0x0602E6CC (external) */
    shll r0
    .2byte  0x0000
    .4byte  0x00000008
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  fpmul
    .4byte  isqrt
    .4byte  0x6473DD07
