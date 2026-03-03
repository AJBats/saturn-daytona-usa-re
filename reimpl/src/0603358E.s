
    .section .text.FUN_0603358E


    .global disp_course_thunk_1
    .type disp_course_thunk_1, @function
disp_course_thunk_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r14
    mov r3, r4
    mov r7, r5
    .byte   0xD0, 0x14    /* mov.l .L_pool_060335F0, r0 */
