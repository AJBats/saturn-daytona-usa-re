	.text
    .global disp_attract_cleanup
disp_attract_cleanup:
    sts.l pr, @-r15
    .byte   0xB1, 0x64    /* bsr 0x06033700 (external) */
    nop
    lds.l @r15+, pr
