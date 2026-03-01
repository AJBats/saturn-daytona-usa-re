
    .section .text.FUN_0603B0C0


    .global menu_elem_alpha
    .type menu_elem_alpha, @function
menu_elem_alpha:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r4, @r15
    mov.l r5, @(4, r15)
    mov.l @r15, r14
    mov.l @r14, r14
    mov.b @(r0, r14), r14
    extu.b r14, r14
    .byte   0xB4, 0x33    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov #0x8, r2
    and r14, r2
    tst r2, r2
    bt      .L_calc_blend
    bra     .L_check_ready
    nop
.L_check_ready:
    mov #0x4, r2
    and r14, r2
    tst r2, r2
    bt      .L_calc_blend
    bra     .L_return_opaque
    nop
.L_return_opaque:
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_calc_blend:
    mov.l @r15, r4
    mov.l @(4, r15), r1
    mov.l @r4, r4
    mov.l @(12, r4), r3
    add r3, r1
    mov r3, r0
    mov.l   .L_pool_0603B114, r3
    jsr @r3
    add #-0x1, r1
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0603B114:
    .4byte  input_proc_complete
