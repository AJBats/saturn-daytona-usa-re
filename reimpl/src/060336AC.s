	.text
    .global course_stats_display
course_stats_display:
    sts.l pr, @-r15
    .byte   0xBF, 0x4F    /* bsr 0x06033550 (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    rts
    nop
    .short  0x0000
    .long  sym_0603386C
    .long  0x00000224
    .long  0x00000268
    .long  0x2F06D071
    .long  0x60004015
    .long  0x8B0CD06D
    .long  0x6001C810
    .long  0x8908D06C
    .long  0x60004015
    .long  0x89044315
    .long  0x8B026033
    .long  0x70FF6403
    .long  0x60F6000B
    .long  0x00092F06
    .long  0xD0626000
    .long  0x401560F6
    .long  0x000B0009
    .long  0x2F062F66
    .long  0x6E666D66
    .long  0x6C666B65
    .long  0x6A65D159
    .long  0x61124108
    .long  0x4108D030
    .long  0x301C7008
    .long  0x68066502
    .long  0x2F1664D3
    .short  0xD12D
