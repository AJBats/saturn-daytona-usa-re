
    .section .text.FUN_06040F1C


    .global FUN_06040F1C
    .type FUN_06040F1C, @function
FUN_06040F1C:
    sts.l pr, @-r15
    mov.l   .L_pool_06040F3C, r13
    cmp/pz r14
    bf      .L_06040F2A
    mov #0x18, r2
    cmp/ge r2, r14
    bf      .L_06040F2E
.L_06040F2A:
    bra     .L_06040F7A
    mov #-0x6, r0
.L_06040F2E:
    mov.l @r13, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x1, r0
    bt      .L_06040F40
    bra     .L_06040F7A
    mov #-0x7, r0
    .2byte  0xFFFF
.L_pool_06040F3C:
    .4byte  sym_060A5400
.L_06040F40:
    .byte   0xD6, 0x19    /* mov.l .L_pool_06040FA8, r6 */
    mov #0x0, r5
    .reloc ., R_SH_IND12W, FUN_060412B2 - 4
    .2byte 0xB000    /* bsr FUN_060412B2 (linker-resolved) */
    mov r14, r4
    .byte   0xD4, 0x18    /* mov.l .L_pool_06040FAC, r4 */
    mov.l @r13, r2
    mov.l r4, @(60, r2)
.L_06040F4E:
    .reloc ., R_SH_IND12W, FUN_06041698 - 4
    .2byte 0xB000    /* bsr FUN_06041698 (linker-resolved) */
    nop
    cmp/eq #0x3, r0
    bf/s    .L_06040F5C
    mov r0, r4
    bra     .L_06040F7A
    mov #-0xC, r0
.L_06040F5C:
    .reloc ., R_SH_IND12W, FUN_06041310 - 4
    .2byte 0xB000    /* bsr FUN_06041310 (linker-resolved) */
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .L_06040F68
    bra     .L_06040F6C
    nop
.L_06040F68:
    bra     .L_06040F4E
    nop
.L_06040F6C:
    mov #0x0, r4
    mov r4, r5
    mov.l @r13, r2
    mov.l r4, @(60, r2)
    mov.l @r13, r0
    mov.b r5, @(r0, r14)
    mov r5, r0
.L_06040F7A:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06040F82
    .type FUN_06040F82, @function
FUN_06040F82:
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r5
    mov.l   .L_06040FB0, r3
    jsr @r3
    mov #0x0, r4
    mov r15, r5
    mov r15, r4
    mov.l   .L_06040FB0, r3
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov r15, r0
    mov.l   .L_06040FB4, r3
    mov.l @r0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    and r3, r0
    .4byte  0x0000FFFF
    .4byte  0x00008000
.L_06040FB0:
    .4byte  FUN_06034B54
.L_06040FB4:
    .4byte  0x00FFFFFF

    .global sym_06040FB8
sym_06040FB8:
    mov.l   .L_06041010, r4
    mov.l @r4, r0
    mov.l @(48, r0), r0
    cmp/eq #0x1, r0
    bf      .L_06040FC6
    rts
    mov #-0x5, r0
.L_06040FC6:
    mov #0x1, r3
    mov.l @r4, r2
    mov.l r3, @(48, r2)
    mov.l @r4, r2
    mov.l @(56, r2), r3
    add #0x1, r3
    mov.l r3, @(56, r2)
    mov.l @r4, r2
    mov.l @(56, r2), r3
    cmp/pz r3
    bt      .L_06040FE2
    mov.l @r4, r3
    mov #0x0, r2
    mov.l r2, @(56, r3)
.L_06040FE2:
    mov.l @r4, r0
    mov.l @(56, r0), r0
    rts
    nop

    .global sym_06040FEA
sym_06040FEA:
    mov.l   .L_06041010, r5
    mov.l @r5, r3
    mov.l @(48, r3), r0
    tst r0, r0
    bf      .L_06040FF8
    rts
    mov #-0x7, r0
.L_06040FF8:
    mov.l @r5, r3
    mov.l @(56, r3), r2
    cmp/eq r4, r2
    bt      .L_06041004
    rts
    mov #-0x9, r0
.L_06041004:
    mov #0x0, r4
    mov.l @r5, r2
    mov.l r4, @(48, r2)
    mov r4, r0
    rts
    nop
.L_06041010:
    .4byte  sym_060A5400

    .global sym_06041014
sym_06041014:
    .byte   0xD5, 0x11    /* mov.l .L_06041010, r5 */
    mov.l @r5, r3
    mov.l @(48, r3), r0
    tst r0, r0
    bf      .L_06041022
    rts
    mov #0x0, r0
.L_06041022:
    mov.l @r5, r0
    mov.l @(56, r0), r3
    cmp/eq r4, r3
    bf      .L_0604102E
    bra     .L_06041030
    mov #0x1, r0
.L_0604102E:
    mov #0x0, r0
.L_06041030:
    rts
    nop
