
    .section .text.FUN_0602E344


    .global vdp2_coeff_helper_d
    .type vdp2_coeff_helper_d, @function
vdp2_coeff_helper_d:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x10    /* mov.l .L_pool_0602E390, r4 */
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E398, r13 */
