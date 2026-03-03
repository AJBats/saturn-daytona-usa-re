	.text
    .global menu_stub_nop
menu_stub_nop:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
