
    .section .text.FUN_0602E220


    .global vdp2_reg_write_b
    .type vdp2_reg_write_b, @function
vdp2_reg_write_b:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x22    /* mov.l .L_pool_0602E2B4, r13 */
