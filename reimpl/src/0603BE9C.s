
    .section .text.FUN_0603BE9C


    .global save_data_size
    .type save_data_size, @function
save_data_size:
    mov.l r14, @-r15
    mov #0x1D, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l @(20, r15), r11
    mov.l @(24, r15), r12
    mov.l @(28, r15), r13
    mov.l @(32, r15), r14
    mov.b @(r0, r4), r0
    extu.b r0, r0
    tst #0x60, r0
    .byte   0x8B, 0x07    /* bf 0x0603BEC8 (external) */
