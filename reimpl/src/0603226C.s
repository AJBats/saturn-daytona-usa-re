	.text
    .global display_dispatch_0
display_dispatch_0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    .byte   0xD4, 0x15    /* mov.l .L_pool_060322D0, r4 */
