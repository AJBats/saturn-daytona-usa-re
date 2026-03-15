
    .section .text.FUN_0603B290

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
