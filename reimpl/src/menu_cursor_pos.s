
    .section .text.FUN_0603B130


    .global menu_cursor_pos
    .type menu_cursor_pos, @function
menu_cursor_pos:
    mov.l r14, @-r15
    mov.l @(24, r15), r2
    mov.l r2, @-r15
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(20, r15), r7
    mov.l @(28, r15), r4
    .byte   0xB6, 0xAD    /* bsr 0x0603BE9C (external) */
    mov.l @r4, r4
    add #0x10, r15
    mov.l @r15, r0
    tst #0x8, r0
    bt      .L_done
    bra     .L_check_write
    nop
.L_check_write:
    mov.l @r15, r0
    tst #0x4, r0
    bt      .L_done
    bra     .L_store_pos
    nop
.L_store_pos:
    mov.l @(4, r15), r2
    mov.l r14, @r2
.L_done:
    .byte   0xB3, 0xEE    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
