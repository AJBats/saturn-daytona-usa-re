	.text
    .global menu_text_position
menu_text_position:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov r4, r5
    mov.l r11, @-r15
    mov #0x2, r12
    mov.l r10, @-r15
    mov r6, r11
