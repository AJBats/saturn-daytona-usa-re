	.text
    .global palette_full_update
palette_full_update:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    cmp/pz r7
    bt      .L_0602E6D4
    neg r7, r7
.L_0602E6D4:
    mov.l   .L_0602E6E4, r11
    cmp/ge r11, r7
    .byte   0x89, 0x58    /* bt 0x0602E78C (external) */
    .byte   0xA0, 0x71    /* bra 0x0602E7C0 (external) */
    nop
    .short  0x0000
    .long  isqrt
.L_0602E6E4:
    .long  0x000F0000
    .long  0xD3176332
    .long  0xD0170A9E
    .long  0x3A308B4B
    .long  0xD01608AE
    .long  0x38784811
    .long  0x8900688B
    .long  0xD014039E
    .long  0x05AED014
    .long  0x069E04AE
    .long  0x2F463538
    .long  0x6453DD12
