
    .section .text.FUN_0603B3D0


    .global menu_separator
    .type menu_separator, @function
menu_separator:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r3, @(r0, r14)
    .byte   0xB2, 0xFE    /* bsr 0x0603B9D6 (external) */
    mov r14, r4
    mov r14, r13
    .byte   0xB2, 0x6A    /* bsr 0x0603B8B4 (external) */
    mov r14, r4
    .byte   0xB2, 0x88    /* bsr 0x0603B8F4 (external) */
    mov r13, r4
    .byte   0xBE, 0x38    /* bsr 0x0603B058 (external) */
    mov r13, r4
    mov.l r0, @r15
    .byte   0xB2, 0xA7    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x6343
    .2byte  0xE011
