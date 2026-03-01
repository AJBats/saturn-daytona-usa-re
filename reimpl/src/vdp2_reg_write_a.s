
    .section .text.FUN_0602E214


    .global vdp2_reg_write_a
    .type vdp2_reg_write_a, @function
vdp2_reg_write_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x24    /* mov.l .L_pool_0602E2B0, r13 */
