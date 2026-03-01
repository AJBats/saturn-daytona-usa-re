
    .section .text.FUN_06005788


    .global bg_layer_init
    .type bg_layer_init, @function
bg_layer_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x15, r11
    mov.l r9, @-r15
    mov r11, r14
    mov.l r8, @-r15
    add #0x6B, r14
