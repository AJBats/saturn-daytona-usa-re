
    .section .text.FUN_0603359E


    .global disp_course_thunk_2
    .type disp_course_thunk_2, @function
disp_course_thunk_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r13
    mov r2, r4
    mov r8, r5
    .byte   0xD0, 0x10    /* mov.l .L_pool_060335F0, r0 */
