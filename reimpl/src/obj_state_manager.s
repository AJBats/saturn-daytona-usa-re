
    .section .text.FUN_06020E74


    .global obj_state_manager
    .type obj_state_manager, @function
obj_state_manager:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov #0x15, r8
