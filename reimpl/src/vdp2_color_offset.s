
    .section .text.FUN_0602E25A


    .global vdp2_color_offset
    .type vdp2_color_offset, @function
vdp2_color_offset:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1A    /* mov.l .L_pool_0602E2CC, r13 */
