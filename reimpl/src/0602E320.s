	.text
    .global vdp2_coeff_helper_a
vdp2_coeff_helper_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x17    /* mov.l .L_pool_0602E388, r13 */
