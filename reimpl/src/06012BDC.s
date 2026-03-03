	.text
    .global cd_error_recover
cd_error_recover:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0xF, r13
