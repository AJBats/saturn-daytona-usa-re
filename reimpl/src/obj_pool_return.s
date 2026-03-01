
    .section .text.FUN_06020D46


    .global obj_pool_return
    .type obj_pool_return, @function
obj_pool_return:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x10, r11
