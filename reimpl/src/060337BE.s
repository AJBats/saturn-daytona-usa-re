	.text
    .global disp_course_stub
disp_course_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
