
    .section .text.FUN_0604000C


    .global error_code_stub
    .type error_code_stub, @function
error_code_stub:
    mov.l r14, @-r15
    mov #-0x2, r2
