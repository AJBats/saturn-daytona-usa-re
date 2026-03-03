	.text
    .global vdp2_scroll_pos_a
vdp2_scroll_pos_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x20    /* mov.l .L_pool_0602E2B8, r13 */
