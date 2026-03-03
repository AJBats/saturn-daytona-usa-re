	.text
    .global digit_render_2
digit_render_2:
    sts.l pr, @-r15
    .byte   0xB4, 0xB7    /* bsr 0x06032EA4 (external) */
    nop
    lds.l @r15+, pr
    rts
    nop
    .long  0xD0026100
    .long  0x21188B03
    .long  0x000B0009
    .long  sym_06082A24
    .long  0xD00707ED
    .long  0xD607D208
    .long  0x27288900
    .long  0xD607D205
    .long  0x27288900
    .long  0xD606D007
    .long  0x01EE316C
    .long  0x000B0E16
    .long  0x0000000E
    .long  0x00000001
    .long  0x00000002
    .long  0xFFFFFFFF
    .long  0x00000000
    .long  0x000002C4
    .short  0xD010
