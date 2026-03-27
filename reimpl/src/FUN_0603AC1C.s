
    .section .text.FUN_0603AC1C


    .global FUN_0603AC1C
    .type FUN_0603AC1C, @function
FUN_0603AC1C:
    mov.l r14, @-r15
    mov #0x1, r3
    mov.l r13, @-r15
    sts.l pr, @-r15
    cmp/ge r3, r4
    bf/s    .L_0603AC30
    mov r6, r14
    mov #0x18, r3
    cmp/gt r3, r4
    bf      .L_0603AC34
.L_0603AC30:
    bra     .L_0603ACE2
    mov #-0x5, r0
.L_0603AC34:
    mov #0x3, r3
    and r5, r3
    tst r3, r3
    bt      .L_0603AC40
    bra     .L_0603ACE2
    mov #-0x15, r0
.L_0603AC40:
    tst r14, r14
    bt      .L_0603AC62
    mov.l @r14, r6
    tst r6, r6
    bt      .L_0603AC50
    mov r6, r0
    cmp/eq #0x1, r0
    bf      .L_0603AC5E
.L_0603AC50:
    mov.l @(4, r14), r2
    mov #0x2, r3
    cmp/ge r3, r2
    bf      .L_0603AC5E
    mov.l @(8, r14), r0
    tst r0, r0
    bf      .L_0603AC62
.L_0603AC5E:
    bra     .L_0603ACE2
    mov #-0x4, r0
.L_0603AC62:
    mov.l   .L_pool_0603ACA0, r3
    mov.l r5, @r3
    .reloc ., R_SH_IND12W, FUN_0603B74C - 4
    .2byte 0xB000    /* bsr FUN_0603B74C (linker-resolved) */
    nop
    tst r14, r14
    bf      .L_0603AC72
    bra     .L_0603AC74
    mov #0x1, r4
.L_0603AC72:
    mov #0x0, r4
.L_0603AC74:
    mov.l   .L_pool_0603ACA4, r3
    jsr @r3
    nop
    mov r0, r4
    tst r4, r4
    bt      .L_0603AC88
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603AC88:
    mov.l   .L_pool_0603ACA0, r0
    mov.w   DAT_0603ac9e, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0x1, r0
    bf      .L_0603ACA8
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14

    .global DAT_0603ac9e
DAT_0603ac9e:
    .2byte  0x00C4
.L_pool_0603ACA0:
    .4byte  sym_060A4D14
.L_pool_0603ACA4:
    .4byte  FUN_0604000C
.L_0603ACA8:
    tst r14, r14
    bf      .L_0603ACC2
    mov.l   .L_pool_0603AD30, r3
    jsr @r3
    nop
    mov r0, r13
    cmp/pz r13
    bt      .L_0603ACD8
    mov #-0x7, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603ACC2:
    mov.l   .L_pool_0603AD34, r3
    jsr @r3
    mov r14, r4
    mov r0, r13
    cmp/pl r13
    bt      .L_0603ACD8
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603ACD8:
    bsr     FUN_0603ADAC
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov r13, r0
.L_0603ACE2:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603ACEA
    .type FUN_0603ACEA, @function
FUN_0603ACEA:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_0603AD2E, r0
    add r0, r15
    mov r5, r0
    mov.l r5, @r15
    mov.l   .L_pool_0603AD3A, r13
    tst r0, r0
    bf/s    .L_0603AD40
    mov r4, r12

    mov.l @r13, r3
    mov.w   .L_wpool_0603AD30, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603AD14
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #-0x7, r4
    bra     .L_0603AD9E
    nop
.L_0603AD14:
    mov.l   .L_pool_0603AD3E, r3
    jsr @r3
    mov r12, r4
    mov r0, r4
    cmp/pz r4
    bt      .L_0603AD28
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #-0x1, r4
    bra     .L_0603AD9E
    nop
.L_0603AD28:
    bra     .L_0603AD9E
    mov r4, r0
.L_wpool_0603AD2E:
    .2byte  0xFF0C
.L_wpool_0603AD30:
    .2byte  0x00A0
.L_pool_0603AD30:
    .4byte  FUN_0603F22C
.L_pool_0603AD34:
    .4byte  FUN_0603BC12
.L_pool_0603AD3A:
    .4byte  sym_060A4D14
.L_pool_0603AD3E:
    .4byte  FUN_0603F238

.L_0603AD40:
    mov.l @r13, r2
    mov.w   .L_0603ADDA, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_0603AD5A
    mov.l @r13, r5
    mov.w   .L_0603ADDC, r0
    mov.l   .L_pool_0603ADE0, r3
    mov.l @(r0, r5), r5
    jsr @r3
    mov r12, r4
    bra     .L_0603AD66
    nop
.L_0603AD5A:
    mov.l @r13, r5
    mov.w   .L_0603ADDC, r0
    mov.l   .L_pool_0603ADE4, r3
    mov.l @(r0, r5), r5
    jsr @r3
    mov r12, r4
.L_0603AD66:
    mov r0, r14
    mov.b @(11, r14), r0
    extu.b r0, r0
    tst #0x10, r0
    bt      .L_0603AD74
    bra     .L_0603AD7C
    nop
.L_0603AD74:
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #-0x6, r4
    bra     .L_0603AD9E
    nop
.L_0603AD7C:
    mov r12, r6
    mov r14, r5
    mov r15, r4
    .reloc ., R_SH_IND12W, FUN_0603BA2C - 4
    .2byte 0xB000    /* bsr FUN_0603BA2C (linker-resolved) */
    add #0x4, r4
    mov r0, r13
    mov.l @(4, r14), r6
    mov.l @r15, r5
    mov.l   .L_pool_0603ADE8, r3
    jsr @r3
    mov r13, r4
    mov.l r0, @r15
    .reloc ., R_SH_IND12W, FUN_0603B9D6 - 4
    .2byte 0xB000    /* bsr FUN_0603B9D6 (linker-resolved) */
    mov r13, r4
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0

.L_0603AD9E:
    mov.w   .L_pool_0603ADDE, r1
    add r1, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603ADAC
    .type FUN_0603ADAC, @function
FUN_0603ADAC:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603ADEC, r5
    mov.w   .L_0603ADDA, r3
    mov.l @r5, r14
    tst r4, r4
    bf/s    .L_0603ADF0
    add r3, r14
    mov.l @r5, r3
    mov.w   .L_0603ADDC, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603ADCE
    mov #-0x7, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603ADCE:
    mov #0x0, r4
    mov.l r4, @(8, r14)
    mov.l r4, @(12, r14)
    mov r4, r2
    bra     .L_0603AE00
    mov.l r4, @(4, r14)
.L_0603ADDA:
    .2byte  0x0098
.L_0603ADDC:
    .2byte  0x00A0
.L_pool_0603ADDE:
    .2byte  0x00F4
.L_pool_0603ADE0:
    .4byte  sym_0603F1E0
.L_pool_0603ADE4:
    .4byte  sym_0603F1F0
.L_pool_0603ADE8:
    .4byte  FUN_0603F0FC
.L_pool_0603ADEC:
    .4byte  sym_060A4D14
.L_0603ADF0:
    mov r14, r1
    mov r4, r2
    mov.l   .L_pool_0603AE68, r3
    jsr @r3
    mov #0xC, r0
    .reloc ., R_SH_IND12W, FUN_0603B7C0 - 4
    .2byte 0xB000    /* bsr FUN_0603B7C0 (linker-resolved) */
    nop
    mov.l r0, @(12, r14)
.L_0603AE00:
    mov #0x0, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14

    .global FUN_0603AE08
    .type FUN_0603AE08, @function
FUN_0603AE08:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_pool_0603AE6C, r14
    mov.w   .L_0603AE60, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603AE26
    mov.l @r14, r0
    mov.w   .L_0603AE62, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bt      .L_0603AE30
.L_0603AE26:
    mov #-0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603AE30:
    mov.l @r14, r6
    mov.w   .L_0603AE64, r0
    mov.l @r15, r5
    mov.l @r14, r4
    mov.l   .L_pool_0603AE70, r3
    mov.l @(r0, r6), r6
    mov.w   .L_0603AE60, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r14
    cmp/pz r14
    bt      .L_0603AE52
    mov #-0x9, r4
    add #0x4, r15
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603AE52:
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603AE60:
    .2byte  0x00A0
.L_0603AE62:
    .2byte  0x0098
.L_0603AE64:
    .2byte  0x009C
    .2byte  0xFFFF
.L_pool_0603AE68:
    .4byte  sym_06035168
.L_pool_0603AE6C:
    .4byte  sym_060A4D14                    /* [HIGH] global command state struct pointer */
.L_pool_0603AE70:
    .4byte  FUN_0603F148
