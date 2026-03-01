
    .section .text.FUN_0602E32C


    .global vdp2_coeff_helper_b
    .type vdp2_coeff_helper_b, @function
vdp2_coeff_helper_b:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x15    /* mov.l .L_pool_0602E38C, r13 */
