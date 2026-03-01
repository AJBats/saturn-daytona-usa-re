
    .section .text.FUN_060334D2


    .global disp_split_stub
    .type disp_split_stub, @function
disp_split_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
