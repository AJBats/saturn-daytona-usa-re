
    .section .text.FUN_0603AF94


    .global FUN_0603AF94
    .type FUN_0603AF94, @function
FUN_0603AF94:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603B878 - 4
    .2byte 0xB000    /* bsr FUN_0603B878 (linker-resolved) */
    mov r4, r14
    mov r0, r13
    tst r13, r13
    bf      .L_0603AFB2
    mov #-0xB, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603AFB2:
    mov r14, r12
    .reloc ., R_SH_IND12W, FUN_0603B8B4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8B4 (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8F4 (linker-resolved) */
    mov r12, r4
    mov r12, r5
    mov.l   .L_pool_0603B034, r3
    jsr @r3
    mov r13, r4
    mov #0x0, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14


    .global FUN_0603AFD0
    .type FUN_0603AFD0, @function
FUN_0603AFD0:
    mov.l r14, @-r15
    mov #0x10, r0
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov r4, r13

    .global FUN_0603AFDC
    .type FUN_0603AFDC, @function
FUN_0603AFDC:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0603B038, r12
    mov.b @(r0, r13), r3
    mov.l @r12, r12
    extu.b r3, r3
    mov r6, r0
    add #0x4, r12
    shll2 r3
    shll2 r3
    cmp/eq #0x1, r0
    bf/s    .L_0603B000
    add r3, r12
    mov.l @(12, r12), r3
    jsr @r3
    mov.l @r13, r4
    bra     .L_0603B020
    add r0, r14
.L_0603B000:
    mov r6, r0
    cmp/eq #0x2, r0
    bf      .L_0603B00E
    mov.l @r13, r3
    mov.l @(16, r3), r2
    bra     .L_0603B020
    add r2, r14
.L_0603B00E:
    tst r6, r6
    bt      .L_0603B020
    mov #-0xD, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B020:
    cmp/pz r14
    bt      .L_0603B03C
    mov #-0xF, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0603B034:
    .4byte  FUN_0603BF22
.L_pool_0603B038:
    .4byte  sym_060A4D14
.L_0603B03C:
    mov.l @(8, r12), r2
    mov r14, r5
    jsr @r2
    mov.l @r13, r4
    mov.l r0, @r15
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
