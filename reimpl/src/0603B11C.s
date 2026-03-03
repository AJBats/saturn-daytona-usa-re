
    .section .text.FUN_0603B11C


    .global menu_cursor_blink
    .type menu_cursor_blink, @function
menu_cursor_blink:
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r4, @(12, r15)
    mov r15, r3
    mov.l r5, @(4, r15)
    mov r14, r5
    mov.l r6, @(8, r15)
    mov r14, r6
    mov.l r7, @(16, r15)
    mov.l r3, @-r15
