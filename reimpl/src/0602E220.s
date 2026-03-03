	.text
    .global vdp2_reg_write_b
vdp2_reg_write_b:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x22    /* mov.l .L_pool_0602E2B4, r13 */
