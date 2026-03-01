
    .section .text.FUN_060337BE


    .global disp_course_stub
    .type disp_course_stub, @function
disp_course_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
