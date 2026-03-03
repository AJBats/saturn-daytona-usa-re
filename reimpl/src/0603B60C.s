	.text
    .global menu_border_render
menu_border_render:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_0603B62C, r3
    jsr @r3
    mov.l @(8, r4), r4
    mov.l r0, @r15
    .byte   0xB1, 0x8F    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .long  attract_timer_tick
.L_0603B62C:
    .long  sym_0603F9FA
