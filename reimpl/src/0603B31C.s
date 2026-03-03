	.text
    .global menu_state_handler
menu_state_handler:
    mov.l r14, @-r15
    mov #0x12, r0
    mov.l r8, @-r15
    mov r4, r14
