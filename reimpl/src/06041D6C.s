	.text
    .global large_func_prologue
large_func_prologue:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
