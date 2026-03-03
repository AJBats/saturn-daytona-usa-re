
    .section .text.FUN_060365D0


    .global course_data_access_g
    .type course_data_access_g, @function
course_data_access_g:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06036644, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x52, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    .byte   0xD3, 0x13    /* mov.l .L_pool_06036648, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
