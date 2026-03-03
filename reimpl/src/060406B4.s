	.text
    .global timer_stub
timer_stub:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r8, @-r15
    mov r4, r13
