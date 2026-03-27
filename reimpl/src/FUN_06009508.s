
    .section .text.FUN_06009508


    .global FUN_06009508
    .type FUN_06009508, @function
FUN_06009508:
    sts.l pr, @-r15
    mov.l   .L_06009598, r4
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_06009524
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l   .L_0600959C, r2
    mov.l r3, @r2
    bra     .L_06009534
    nop
.L_06009524:
    mov.l   .L_pool_060095A0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009534
    mov.l   .L_pool_060095A4, r4
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_06009534:
    mov #0x1D, r2
    mov.l   .L_0600959C, r3
    mov.l r2, @r3
    mov.l   .L_pool_060095A8, r3
    jsr @r3
    nop
    mov.l   .L_pool_060095AC, r3
    jsr @r3
    nop
    mov.l   .L_pool_060095B0, r6
    mov.l   .L_pool_060095B4, r5
    mov.l   .L_pool_060095B8, r4
    mov.l   .L_pool_060095BC, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_pool_060095C0, r3
    jsr @r3
    nop
    mov.l   .L_pool_060095C4, r3
    jmp @r3
    lds.l @r15+, pr


    .global FUN_0600955E
    .type FUN_0600955E, @function
FUN_0600955E:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600959C, r14
    mov.l   .L_060095C8, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_06009596, r3
    and r3, r2
    tst r2, r2
    bt      .L_0600957E
    mov #0x1D, r3
    mov.l   .L_060095CC, r2
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r14
.L_0600957E:
    mov.l   .L_06009598, r4
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_060095D0
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r14
    bra     .L_060095E0
    nop
.L_06009596:
    .2byte  0x0800
.L_06009598:
    .4byte  sym_0607EBF4
.L_0600959C:
    .4byte  FUN_0605ACC4
.L_pool_060095A0:
    .4byte  sym_0607EAD0
.L_pool_060095A4:
    .4byte  sym_0607EBD0
.L_pool_060095A8:
    .4byte  FUN_0600DFD0
.L_pool_060095AC:
    .4byte  FUN_0600BB94
.L_pool_060095B0:
    .4byte  sym_06063E24
.L_pool_060095B4:
    .4byte  sym_06063EEC
.L_pool_060095B8:
    .4byte  sym_06063EF8
.L_pool_060095BC:
    .4byte  FUN_060053AC
.L_pool_060095C0:
    .4byte  FUN_0600C218
.L_pool_060095C4:
    .4byte  FUN_060078DC
.L_060095C8:
    .4byte  sym_06063D9A
.L_060095CC:
    .4byte  sym_0607EACC
.L_060095D0:
    mov.l   .L_06009684, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_060095E0
    mov.l   .L_06009688, r4
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_060095E0:
    mov.l   .L_0600968C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060095EE
    mov.l   .L_06009690, r3
    jsr @r3
    mov #0x0, r4
.L_060095EE:
    mov.l   .L_06009694, r3
    jsr @r3
    nop
    mov.l   .L_06009698, r3
    jsr @r3
    nop
    mov.l   .L_0600969C, r6
    mov.l   .L_060096A0, r5
    mov.l   .L_060096A4, r4
    mov.l   .L_060096A8, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_060096AC, r3
    jsr @r3
    nop
    mov.l   .L_060096B0, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0600961C
    mov.l   .L_060096B4, r3
    jsr @r3
    nop
.L_0600961C:
    mov.l   .L_060096B8, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009632
    mov.l   .L_060096BC, r7
    mov.l   .L_060096C0, r6
    mov.w   .L_0600967C, r5
    mov.l   .L_060096C4, r3
    jsr @r3
    mov #0x8, r4
.L_06009632:
    mov.l   .L_060096C8, r2
    mov.w   .L_0600967E, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_06009642
    .reloc ., R_SH_IND12W, FUN_0600A084 - 4
    .2byte 0xB000    /* bsr FUN_0600A084 (linker-resolved) */
    nop
.L_06009642:
    mov.l   .L_060096CC, r3
    jsr @r3
    nop
    mov.l   .L_060096C8, r0
    mov.w   .L_06009680, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0xCC, r0
    bf      .L_06009668
    mov.l   .L_060096D0, r3
    mov.l r3, @r15
    mov r3, r7
    mov r3, r5
    mov.w   .L_06009682, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    mov.l   .L_060096D4, r3
    jsr @r3
    mov #0x4, r4
.L_06009668:
    mov.l   .L_060096D8, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009674
    mov #0x11, r3
    mov.l r3, @r14
.L_06009674:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0600967C:
    .2byte  0x0082
.L_0600967E:
    .2byte  0x00BC
.L_06009680:
    .2byte  0x0214
.L_06009682:
    .2byte  0x0900
.L_06009684:
    .4byte  sym_0607EAD0
.L_06009688:
    .4byte  sym_0607EBD0
.L_0600968C:
    .4byte  sym_0605AB18
.L_06009690:
    .4byte  FUN_060268B0
.L_06009694:
    .4byte  FUN_0600E060
.L_06009698:
    .4byte  FUN_0600BB94
.L_0600969C:
    .4byte  sym_06063E24
.L_060096A0:
    .4byte  sym_06063EEC
.L_060096A4:
    .4byte  sym_06063EF8
.L_060096A8:
    .4byte  FUN_060053AC
.L_060096AC:
    .4byte  FUN_0600C218
.L_060096B0:
    .4byte  sym_0607ED8C
.L_060096B4:
    .4byte  sym_060033E6
.L_060096B8:
    .4byte  sym_06086030
.L_060096BC:
    .4byte  sym_0605A1C8
.L_060096C0:
    .4byte  0x0000F000
.L_060096C4:
    .4byte  sym_060283E0
.L_060096C8:
    .4byte  sym_0607E944
.L_060096CC:
    .4byte  FUN_060078DC
.L_060096D0:
    .4byte  sym_06063798
.L_060096D4:
    .4byte  sym_06028400
.L_060096D8:
    .4byte  sym_0605A1C4
