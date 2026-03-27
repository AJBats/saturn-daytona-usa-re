
    .section .text.FUN_0603B424


    .global FUN_0603B424
    .type FUN_0603B424, @function
FUN_0603B424:
    mov.l r14, @-r15
    mov #0x12, r0
    mov.l r13, @-r15
    mov r4, r14
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0603B43C
    bra     .L_0603B526
    nop
.L_0603B43C:
    .reloc ., R_SH_IND12W, FUN_0603BD1C - 4
    .2byte 0xB000    /* bsr FUN_0603BD1C (linker-resolved) */
    mov r14, r4
    bra     .L_0603B4D0
    mov r0, r13
.L_0603B444:
    mov.w   DAT_0603b4c6, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B456:
    mov.w   DAT_0603b4c8, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x17, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B468:
    mov.w   DAT_0603b4ca, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B47A:
    mov.w   DAT_0603b4cc, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x14, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B48C:
    .reloc ., R_SH_IND12W, FUN_0603BF5A - 4
    .2byte 0xB000    /* bsr FUN_0603BF5A (linker-resolved) */
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .L_0603B4E8
    mov.w   DAT_0603b4ce, r3
    mov #0x12, r0
    mov.b r3, @(r0, r14)
    mov #-0x18, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B4A6:
    mov #0x11, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_0603B4E8
    mov #0x0, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    .reloc ., R_SH_IND12W, FUN_0603B9D6 - 4
    .2byte 0xB000    /* bsr FUN_0603B9D6 (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    bra     .L_0603B530
    extu.b r0, r0

    .global DAT_0603b4c6
DAT_0603b4c6:
    .2byte  0x00FF

    .global DAT_0603b4c8
DAT_0603b4c8:
    .2byte  0x00E9

    .global DAT_0603b4ca
DAT_0603b4ca:
    .2byte  0x00FE

    .global DAT_0603b4cc
DAT_0603b4cc:
    .2byte  0x00EC

    .global DAT_0603b4ce
DAT_0603b4ce:
    .2byte  0x00E8
.L_0603B4D0:
    cmp/eq #0x0, r0
    bt      .L_0603B4A6
    cmp/eq #0x1, r0
    bt      .L_0603B48C
    cmp/eq #0x3, r0
    bt      .L_0603B456
    cmp/eq #0x4, r0
    bt      .L_0603B468
    cmp/eq #0x5, r0
    bt      .L_0603B47A
    cmp/eq #0x6, r0
    bt      .L_0603B444
.L_0603B4E8:
    .reloc ., R_SH_IND12W, FUN_0603BDAC - 4
    .2byte 0xB000    /* bsr FUN_0603BDAC (linker-resolved) */
    mov r14, r4
    mov r0, r4
    mov r13, r0
    cmp/eq #0x2, r0
    bf      .L_0603B526
    mov r4, r0
    cmp/eq #0x5, r0
    bf      .L_0603B526
    mov.l   .L_pool_0603B55C, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov r0, r8
    mov.l   .L_pool_0603B560, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov r8, r5
    mov r14, r4
    sub r0, r5
    .reloc ., R_SH_IND12W, FUN_0603AFD0 - 4
    .2byte 0xB000    /* bsr FUN_0603AFD0 (linker-resolved) */
    mov #0x1, r6
    mov #0x0, r2
    mov #0x12, r0
    mov r14, r13
    mov.b r2, @(r0, r14)
    .reloc ., R_SH_IND12W, FUN_0603B8B4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8B4 (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8F4 (linker-resolved) */
    mov r13, r4
    .reloc ., R_SH_IND12W, FUN_0603B9D6 - 4
    .2byte 0xB000    /* bsr FUN_0603B9D6 (linker-resolved) */
    mov r13, r4
.L_0603B526:
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
.L_0603B530:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE060


    .global FUN_0603B53C
    .type FUN_0603B53C, @function
FUN_0603B53C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r4, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603B564, r13
    mov.l @r13, r13
    add #0x34, r13
    mov.l @(r0, r13), r0
    tst r0, r0
    bf/s    .L_0603B568
    mov #0x0, r11
    mov.l r11, @r12
    bra     .L_0603B586
    mov r11, r14
.L_pool_0603B55C:
    .4byte  sym_0603F9F2
.L_pool_0603B560:
    .4byte  sym_0603F9F6
.L_pool_0603B564:
    .4byte  sym_060A4D14
.L_0603B568:
    mov.l @r13, r2
    mov.l r2, @r12
    bsr     FUN_0603B424
    mov r2, r4
    mov r0, r14
    tst r14, r14
    bf      .L_0603B586
    mov #0x60, r0
    mov.l @(r0, r13), r0
    tst r0, r0
    bf      .L_0603B584
    mov.l r11, @r12
    bra     .L_0603B586
    mov r11, r14
.L_0603B584:
    mov #0x1, r14
.L_0603B586:
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov r14, r0
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
