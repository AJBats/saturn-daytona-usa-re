	.text
    .global disp_split_stub
disp_split_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
