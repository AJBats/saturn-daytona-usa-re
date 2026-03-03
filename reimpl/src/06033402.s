	.text
    .global attract_mode_stub
attract_mode_stub:
    sts.l pr, @-r15
    .byte   0xB1, 0x20    /* bsr 0x06033648 (external) */
    nop
    lds.l @r15+, pr
