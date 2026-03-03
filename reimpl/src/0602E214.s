	.text
    .global vdp2_reg_write_a
vdp2_reg_write_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x24    /* mov.l .L_pool_0602E2B0, r13 */
