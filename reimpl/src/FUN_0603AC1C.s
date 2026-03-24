
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
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603AD30, r3 */
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
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0603AD34, r3 */
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
    .reloc ., R_SH_IND12W, FUN_0603ADAC - 4
    .2byte 0xB000    /* bsr FUN_0603ADAC (linker-resolved) */
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
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0603AD3A, r13 */
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
    .byte   0xD3, 0x09    /* mov.l .L_pool_0603AD3E, r3 */
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
    .4byte  FUN_0603F22C
    .4byte  FUN_0603BC12
.L_pool_0603AD3A:
    .4byte  sym_060A4D14
.L_pool_0603AD3E:
    .4byte  FUN_0603F238

.L_0603AD40:
    mov.l @r13, r2
    .byte   0x90, 0x4A    /* mov.w .L_wpool_0603ADDA, r0 */
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_0603AD5A
    mov.l @r13, r5
    .byte   0x90, 0x46    /* mov.w .L_wpool_0603ADDC, r0 */
    .byte   0xD3, 0x24    /* mov.l .L_pool_0603ADE0, r3 */
    mov.l @(r0, r5), r5
    jsr @r3
    mov r12, r4
    bra     .L_0603AD66
    nop
.L_0603AD5A:
    mov.l @r13, r5
    .byte   0x90, 0x3E    /* mov.w .L_wpool_0603ADDC, r0 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_0603ADE4, r3 */
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
    .byte   0xD3, 0x16    /* mov.l .L_pool_0603ADE8, r3 */
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
    .byte   0x91, 0x1E    /* mov.w .L_wpool_0603ADDE, r1 */
    add r1, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
