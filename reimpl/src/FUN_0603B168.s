
    .section .text.FUN_0603B168


    .global FUN_0603B168
    .type FUN_0603B168, @function
FUN_0603B168:
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r4, @(12, r15)
    mov.l r6, @(16, r15)
    mov.l r7, @(8, r15)
    mov #0x0, r7
    mov.l @(24, r15), r3
    mov r7, r6
    mov.l r3, @-r15
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov r15, r3
    add #0xC, r3
    mov.l r3, @-r15
    mov r15, r2
    add #0xC, r2
    mov.l r2, @-r15
    mov.l @(28, r15), r4
    .reloc ., R_SH_IND12W, FUN_0603BE9C - 4
    .2byte 0xB000    /* bsr FUN_0603BE9C (linker-resolved) */
    mov.l @r4, r4
    mov.l @(40, r15), r3
    mov.l @r3, r0
    and #0x9F, r0
    mov.l r0, @r3
    mov.l @(24, r15), r3
    mov.l @(16, r15), r2
    mov.l @(20, r15), r1
    add #-0x1, r2
    shll8 r2
    shll2 r2
    shll r2
    add r1, r2
    mov.l r2, @r3
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    add #0x24, r15
    lds.l @r15+, pr
    rts
    nop


    .global FUN_0603B1B6
    .type FUN_0603B1B6, @function
FUN_0603B1B6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    mov.l r6, @(4, r15)
    .reloc ., R_SH_IND12W, FUN_0603AEE8 - 4
    .2byte 0xB000    /* bsr FUN_0603AEE8 (linker-resolved) */
    mov r7, r13
    mov r0, r14
    tst r14, r14
    bf      .L_0603B1DC
    mov #-0x9, r4
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B1DC:
    mov #0x0, r6
    mov.l @r15, r5
    .reloc ., R_SH_IND12W, FUN_0603AFD0 - 4
    .2byte 0xB000    /* bsr FUN_0603AFD0 (linker-resolved) */
    mov r14, r4
    mov.l @r14, r5
    mov r13, r0
    mov.l @r15, r3
    mov.l @(16, r5), r5
    cmp/eq #-0x1, r0
    bf/s    .L_0603B1F8
    sub r3, r5
    .byte   0x9D, 0x3D    /* mov.w .L_wpool_0603B270, r13 */
    mul.l r13, r5
    sts macl, r13
.L_0603B1F8:
    mov r13, r7
    mov.l @(4, r15), r6
    bsr     FUN_0603B21C
    mov r14, r4
    mov r0, r13
    .reloc ., R_SH_IND12W, FUN_0603AF94 - 4
    .2byte 0xB000    /* bsr FUN_0603AF94 (linker-resolved) */
    mov r14, r4
    cmp/pz r13
    bf      .L_0603B20E
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
.L_0603B20E:
    mov r13, r0
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603B21C
    .type FUN_0603B21C, @function
FUN_0603B21C:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_0603B274, r3
    mov.l r3, @(8, r15)
    mov.l @r14, r4
    mov.l @(40, r4), r13
    mov.l r3, @(40, r4)
    bsr     .L_0603B28E
    mov r14, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0603B244
    mov.l @r14, r5
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov.l r13, @(40, r5)
    bra     .L_0603B284
    nop
.L_0603B244:
    .reloc ., R_SH_IND12W, FUN_0603B424 - 4
    .2byte 0xB000    /* bsr FUN_0603B424 (linker-resolved) */
    mov r14, r4
    mov r0, r4
    cmp/pz r4
    bt      .L_0603B258
    mov.l @r14, r5
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov.l r13, @(40, r5)
    bra     .L_0603B284
    nop
.L_0603B258:
    tst r4, r4
    bf      .L_0603B278
    mov r15, r6
    mov r15, r5
    add #0x4, r5
    .reloc ., R_SH_IND12W, FUN_0603B3FA - 4
    .2byte 0xB000    /* bsr FUN_0603B3FA (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r14, r4
    bra     .L_0603B282
    mov.l r13, @(40, r4)

    .global DAT_0603b270
DAT_0603b270:
    mov.b r1, @(r0, r9)
    .word 0xFFFF
.L_0603B274:
    .4byte  0x7FFFFFFF
.L_0603B278:
    .byte   0xD3, 0x24    /* mov.l .L_pool_0603B30C, r3 */
    jsr @r3
    nop
    bra     .L_0603B244
    nop
.L_0603B282:
    mov.l @r15, r0
.L_0603B284:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603B28E:
    mov #0x12, r0

    .global FUN_0603B290
    .type FUN_0603B290, @function
FUN_0603B290:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l r5, @r15
    mov.l r6, @(4, r15)
    mov.l r7, @(8, r15)
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0603B2B8
    mov #-0x10, r4
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B2B8:
    .reloc ., R_SH_IND12W, FUN_0603B9A4 - 4
    .2byte 0xB000    /* bsr FUN_0603B9A4 (linker-resolved) */
    mov r14, r4
    mov #0x1, r4
    mov #0x11, r0
    mov.b r4, @(r0, r14)
    mov #0x12, r0
    mov.b r4, @(r0, r14)
    mov.l @r14, r3
    mov.l @(16, r3), r8
    .reloc ., R_SH_IND12W, FUN_0603B058 - 4
    .2byte 0xB000    /* bsr FUN_0603B058 (linker-resolved) */
    mov r14, r4
    mov r8, r4
    mov.l @r15, r3
    sub r0, r4
    cmp/ge r4, r3
    bt      .L_0603B2DC
    bra     .L_0603B2DE
    mov.l @r15, r13
.L_0603B2DC:
    mov r4, r13
.L_0603B2DE:
    mov r13, r5
    .reloc ., R_SH_IND12W, FUN_0603BE7C - 4
    .2byte 0xB000    /* bsr FUN_0603BE7C (linker-resolved) */
    mov.l @r14, r4
    mov r13, r5
    mov.l   .L_pool_0603B311, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x1, r7
    mov.l @(8, r15), r6
    mov.l @(4, r15), r5
    mov.l   .L_pool_0603B315, r3
    jsr @r3
    mov.l @(4, r14), r4
    mov.l   .L_pool_0603B319, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x0, r4
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
    .4byte  FUN_06063644
.L_pool_0603B311:
    .4byte  sym_0603F9DA
.L_pool_0603B315:
    .4byte  sym_0603EF54
.L_pool_0603B319:
    .4byte  sym_0603FA00
