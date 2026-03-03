	.text
    .global cmd_error_return
cmd_error_return:
    mov.l r14, @-r15
    mov #0x10, r0
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov r4, r13
