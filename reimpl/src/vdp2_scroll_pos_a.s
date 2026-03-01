
    .section .text.FUN_0602E22C


    .global vdp2_scroll_pos_a
    .type vdp2_scroll_pos_a, @function
vdp2_scroll_pos_a:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x20    /* mov.l .L_pool_0602E2B8, r13 */
