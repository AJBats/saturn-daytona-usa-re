

    .section .text.FUN_06013A74


    .global best_time_compare
    .type best_time_compare, @function
best_time_compare:
    sts.l pr, @-r15
    .byte   0xB4, 0x73    /* bsr 0x06014360 (external) */
    nop
    .byte   0xB3, 0x77    /* bsr 0x0601416C (external) */
    nop
    .byte   0xB3, 0xE5    /* bsr 0x0601424C (external) */
    nop
    .byte   0xB3, 0x1F    /* bsr 0x060140C4 (external) */
    nop
    .byte   0xB4, 0xE1    /* bsr 0x0601444C (external) */
    nop
    mov.l   .L_pool_06013AEC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_06013A9C
    .byte   0xB4, 0xE7    /* bsr 0x06014466 (external) */
    nop
    bra     .L_06013AA0
    nop
.L_06013A9C:
    .byte   0xB5, 0x36    /* bsr 0x0601450C (external) */
    nop
.L_06013AA0:
    .byte   0xB5, 0x8C    /* bsr 0x060145BC (external) */
    nop
    mov.l   .L_pool_06013AF0, r2
    mov.w @r2, r3
    mov.w   .L_wpool_06013AEA, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06013AB6
    .byte   0xB6, 0x0E    /* bsr 0x060146D2 (external) */
    nop
.L_06013AB6:
    mov #0x4, r3
    mov.l   .L_pool_06013AF4, r2
    mov.l @r2, r2
    cmp/hs r3, r2
    bt      .L_06013AD0
    mov.l   .L_pool_06013AF8, r3
    mov.l   .L_pool_06013AF8, r2
    mov.w @r3, r3
    add #-0x1, r3
    mov.w r3, @r2
    exts.w r3, r3
    cmp/pl r3
    bt      .L_06013AD4
.L_06013AD0:
    .byte   0xA5, 0xFF    /* bra 0x060146D2 (external) */
    lds.l @r15+, pr
.L_06013AD4:
    lds.l @r15+, pr
    rts
    nop

    .global loc_06013ADA
loc_06013ADA:
    mov #0x5, r3
    mov.l   .L_pool_06013AFC, r2
    mov.b r3, @r2
    mov #0x0, r3
    mov.l   .L_pool_06013B00, r2
    mov.w r3, @r2
    .byte   0xA0, 0x0D    /* bra 0x06013B04 (external) */
    nop
.L_wpool_06013AEA:
    .2byte  0x0800
.L_pool_06013AEC:
    .4byte  sym_06063D9E
.L_pool_06013AF0:
    .4byte  sym_06063D9A
.L_pool_06013AF4:
    .4byte  sym_06084B18
.L_pool_06013AF8:
    .4byte  sym_06084AF0
.L_pool_06013AFC:
    .4byte  sym_06084AF2
.L_pool_06013B00:
    .4byte  sym_06084AF6
