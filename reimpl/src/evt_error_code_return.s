
    .section .text.FUN_060401F8


    .global evt_error_code_return
    .type evt_error_code_return, @function
evt_error_code_return:
    mov.l r14, @-r15
    mov #0x0, r6
