
    .section .text.FUN_06042634


    .global div_result_read
    .type div_result_read, @function
div_result_read:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l mach, @-r15
    sts.l macl, @-r15
    mov r5, r10
