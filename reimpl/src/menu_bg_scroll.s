
    .section .text.FUN_0603B598


    .global menu_bg_scroll
    .type menu_bg_scroll, @function
menu_bg_scroll:
    sts.l pr, @-r15
    mov #0x1D, r1
    add #-0x8, r15
    mov.l r5, @r15
    mov.l @r4, r0
    mov.b @(r0, r1), r0
    extu.b r0, r0
    tst #0x60, r0
    bf      .L_commit_and_return
    bra     .L_apply_scroll
    nop
.L_apply_scroll:
    mov.l @r4, r2
    mov.l @r15, r5
    mov.l   .L_pool_0603B5CC, r3
    mov.l @(24, r2), r4
    jsr @r3
    extu.b r5, r5
    mov.l r0, @(4, r15)
.L_commit_and_return:
    .byte   0xB1, 0xBE    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @(4, r15), r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
.L_pool_0603B5CC:
    .4byte  sym_06040894
