	.text
    .global billboard_facing
billboard_facing:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0xAD    /* bra 0x0602E78C (external) */
    nop
    .short  0x0000
    .long  0x00000050
    .long  0x00000000
    .long  0xAE1106FF
    .long  sound_cmd_dispatch
    .long  0xD404D505
    .short  0xDD05
