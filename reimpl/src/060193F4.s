
    .section .text.FUN_060193F4


    .global track_poly_start
    .type track_poly_start, @function
track_poly_start:
    mov.l r14, @-r15
    mov #0x0, r4
    mov #0x1, r0
    mov.l r13, @-r15
    exts.b r4, r3
