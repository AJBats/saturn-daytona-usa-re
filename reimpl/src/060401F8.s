	.text
    .global evt_error_code_return
evt_error_code_return:
    mov.l r14, @-r15
    mov #0x0, r6
