	.text
    .global error_code_stub
error_code_stub:
    mov.l r14, @-r15
    mov #-0x2, r2
