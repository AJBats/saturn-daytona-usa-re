	.text
    .global evt_reg_save
evt_reg_save:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
