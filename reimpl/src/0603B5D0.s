
    .section .text.FUN_0603B5D0


    .global menu_bg_color
    .type menu_bg_color, @function
menu_bg_color:
    sts.l pr, @-r15
    mov r4, r3
    add #-0x4, r15
    mov.l r4, @r15
    mov.l r5, @(12, r3)
    mov.l @r15, r4
    .byte   0xD3, 0x12    /* mov.l .L_pool_0603B628, r3 */
    jsr @r3
    mov.l @(8, r4), r4
    mov.l r0, @r15
    .byte   0xB1, 0xAA    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
