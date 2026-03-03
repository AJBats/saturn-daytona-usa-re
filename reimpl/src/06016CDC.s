
    .section .text.FUN_06016CDC


    .global track_seg_init
    .type track_seg_init, @function
track_seg_init:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov #0x0, r4
    extu.b r14, r3
