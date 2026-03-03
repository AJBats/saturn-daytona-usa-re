	.text
    .global vdp2_priority_a
vdp2_priority_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1D    /* mov.l .L_pool_0602E2C0, r13 */
