	.text
    .global sound_channel_reset
sound_channel_reset:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06019304, r14
    jsr @r14
    mov #0x1, r4
    mov #0x0, r5
    jsr @r14
    mov #0x3, r4
    mov #0x0, r5
    jsr @r14
    mov #0x2, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .long  0xD107D708
    .long  0xD608E501
    .long  0xD4084410
    .long  0x8B10A013
    .long  0x2152FFFF
    .long  0x25A00000
    .long  0x0007FFFF
.L_pool_06019304:
    .long  sound_cmd_dispatch          /* [HIGH] sound command dispatch function */
    .long  sym_06086050
    .long  0x25A02DBE
    .long  0x0000FFFF
    .long  0x000186A0
    .long  0x6271622D
    .long  0x32608BE8
    .long  0x000B0009
