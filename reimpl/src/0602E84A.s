	.text
    .global billboard_scale
billboard_scale:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x9B    /* bra 0x0602E78C (external) */
    nop
    .short  0x0000
    .long  0x00000000
    .long  0xAE110AFF
    .long  sound_cmd_dispatch
    .long  0xD3053833
    .long  0x8910D405
    .long  0xD505DD06
