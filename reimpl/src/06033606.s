	.text
    .global disp_course_separator
disp_course_separator:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    .byte   0xD0, 0x06    /* mov.l .L_pool_0603362C, r0 */
