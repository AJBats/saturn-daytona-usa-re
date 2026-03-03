	.text
    .global disp_course_thunk_3
disp_course_thunk_3:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r12
    mov r2, r4
    mov r7, r5
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060335F0, r0 */
