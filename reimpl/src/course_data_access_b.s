
    .section .text.FUN_06036424


    .global course_data_access_b
    .type course_data_access_b, @function
course_data_access_b:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x27    /* mov.l .L_pool_060364C8, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x46, r3
    extu.b r14, r14
    extu.b r11, r11
    extu.b r13, r13
    extu.b r12, r12
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r11, r0
    mov.b r0, @(2, r3)
    mov r15, r3
    mov r13, r0
    mov.b r0, @(3, r3)
    mov r15, r3
    mov r12, r0
    mov.b r0, @(4, r3)
    .byte   0xD3, 0x1D    /* mov.l .L_pool_060364CC, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
