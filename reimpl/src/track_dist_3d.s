
    .section .text.FUN_06036650


    .global track_dist_3d
    .type track_dist_3d, @function
track_dist_3d:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xD3, 0x26    /* mov.l .L_pool_060366F4, r3 — sym_06035C4E (state field reader) */
    jsr @r3
    mov r5, r13
    mov r0, r4
    extu.w r4, r0
    tst #0x40, r0
    bf      .L_field_valid
    bra     .L_epilogue
    mov #-0x1, r0
.L_field_valid:
    mov r13, r6
    mov r14, r5
    .byte   0xD3, 0x22    /* mov.l .L_pool_060366F8, r3 — input_proc_digital */
    jsr @r3
    mov #0x0, r4
    mov r0, r4
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
