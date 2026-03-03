	.text
    .global vdp2_coeff_helper_c
vdp2_coeff_helper_c:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x13    /* mov.l .L_pool_0602E390, r4 */
    .byte   0xDD, 0x14    /* mov.l .L_pool_0602E394, r13 */
