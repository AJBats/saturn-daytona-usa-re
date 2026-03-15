

    .section .text.FUN_06013A74


    .global FUN_06013A74
    .type FUN_06013A74, @function
FUN_06013A74:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06014360 - 4
    .2byte 0xB000    /* bsr FUN_06014360 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601416C - 4
    .2byte 0xB000    /* bsr FUN_0601416C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601424C - 4
    .2byte 0xB000    /* bsr FUN_0601424C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_060140C4 - 4
    .2byte 0xB000    /* bsr FUN_060140C4 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601444C - 4
    .2byte 0xB000    /* bsr FUN_0601444C (linker-resolved) */
    nop
    mov.l   .L_pool_06013AEC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_06013A9C
    .reloc ., R_SH_IND12W, FUN_06014466 - 4
    .2byte 0xB000    /* bsr FUN_06014466 (linker-resolved) */
    nop
    bra     .L_06013AA0
    nop
.L_06013A9C:
    .reloc ., R_SH_IND12W, FUN_0601450C - 4
    .2byte 0xB000    /* bsr FUN_0601450C (linker-resolved) */
    nop
.L_06013AA0:
    .reloc ., R_SH_IND12W, FUN_060145BC - 4
    .2byte 0xB000    /* bsr FUN_060145BC (linker-resolved) */
    nop
    mov.l   .L_pool_06013AF0, r2
    mov.w @r2, r3
    mov.w   .L_wpool_06013AEA, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06013AB6
    .reloc ., R_SH_IND12W, FUN_060146D2 - 4
    .2byte 0xB000    /* bsr FUN_060146D2 (linker-resolved) */
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
    .reloc ., R_SH_IND12W, FUN_060146D2 - 4
    .2byte 0xA000    /* bra FUN_060146D2 (linker-resolved) */
    lds.l @r15+, pr
.L_06013AD4:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_06013ADA
FUN_06013ADA:
    mov #0x5, r3
    mov.l   .L_pool_06013AFC, r2
    mov.b r3, @r2
    mov #0x0, r3
    mov.l   .L_pool_06013B00, r2
    mov.w r3, @r2
    .reloc ., R_SH_IND12W, FUN_06013B04 - 4
    .2byte 0xA000    /* bra FUN_06013B04 (linker-resolved) */
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
