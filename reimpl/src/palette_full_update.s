
    .section .text.FUN_0602E6C4


    .global palette_full_update
    .type palette_full_update, @function
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
    .2byte  0x0000
    .4byte  isqrt
.L_0602E6E4:
    .4byte  0x000F0000                  /* nibble 4 mask */
    .4byte  0xD3176332
    .4byte  0xD0170A9E
    .4byte  0x3A308B4B
    .4byte  0xD01608AE
    .4byte  0x38784811
    .4byte  0x8900688B
    .4byte  0xD014039E
    .4byte  0x05AED014
    .4byte  0x069E04AE
    .4byte  0x2F463538
    .4byte  0x6453DD12
