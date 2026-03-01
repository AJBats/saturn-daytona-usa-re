
    .section .text.FUN_0602E236


    .global vdp2_scroll_pos_b
    .type vdp2_scroll_pos_b, @function
vdp2_scroll_pos_b:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1F    /* mov.l .L_pool_0602E2BC, r13 */
