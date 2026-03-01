
    .section .text.FUN_0603B31C


    .global menu_state_handler
    .type menu_state_handler, @function
menu_state_handler:
    mov.l r14, @-r15
    mov #0x12, r0
    mov.l r8, @-r15
    mov r4, r14
