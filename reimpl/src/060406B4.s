
    .section .text.FUN_060406B4


    .global timer_stub
    .type timer_stub, @function
timer_stub:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r8, @-r15
    mov r4, r13
