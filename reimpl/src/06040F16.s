
    .section .text.FUN_06040F16


    .global evt_reg_save
    .type evt_reg_save, @function
evt_reg_save:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
