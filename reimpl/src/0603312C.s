	.text
    .global color_anim_ctrl
color_anim_ctrl:
    sts.l pr, @-r15
    .byte   0xB0, 0x6D    /* bsr 0x0603320C (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    add r10, r0
    add #-0x1, r7
    cmp/pl r7
    .byte   0x89, 0xC0    /* bt 0x060330C0 (external) */
    rts
    nop
    .short  0x0000
    .long  sym_06033870
    .long  0x00000010
    .long  0x00000018
    .long  0x00000268
    .long  sym_0603386C
    .long  0x00220000
    .long  0x001A0000
    .long  sym_06033884
    .long  0x00000700
    .long  0x0000FFFF
    .long  0xD204042E
    .long  0xD204032E
    .long  0x343C343C
    .long  0x664B000B
    .long  0x00090000
    .long  0x00000020
    .long  0x000001D8
    .long  0x2F062F66
    .long  0x2F762F86
    .long  0x6463D019
    .long  0x2409D519
    .long  0xD619D01A
