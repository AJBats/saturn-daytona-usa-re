
    .section .text.FUN_06012BDC


    .global cd_error_recover
    .type cd_error_recover, @function
cd_error_recover:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0xF, r13
