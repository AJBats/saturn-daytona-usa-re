
    .section .text.FUN_06020330


    .global FUN_06020330
    .type FUN_06020330, @function
FUN_06020330:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_060203C0, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0602035C
    mov #0x40, r0
    mov.b @r15, r4
    mov.l   .L_pool_060203C4, r2
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r2, r4
    bsr     FUN_06020366
    mov.b @(r0, r4), r4
.L_0602035C:
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_06020DEE - 4
    .2byte 0xA000    /* bra FUN_06020DEE (linker-resolved) */
    lds.l @r15+, pr


    .global FUN_06020366
    .type FUN_06020366, @function
FUN_06020366:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l   .L_pool_060203CF, r10
    mov #0x15, r11
    mov.w   DAT_060203be, r12
    extu.b r4, r14
    shll2 r14
    mov.l   .L_pool_060203D3, r3
    add r3, r14
    mov.l @r14, r14
    mov.b @(2, r14), r0
    mov r0, r7
    extu.b r7, r7
    shll2 r7
    mov.l   .L_pool_060203D7, r2
    add r2, r7
    mov.l @r7, r7
    mov.w @r7, r1
    mov r1, r0
    mov.w r0, @(8, r15)
    add #0x4, r7
    mov.b @r14, r1
    mov r1, r0
    mov.b r0, @(4, r15)
    mov.b @(1, r14), r0
    mov r0, r1
    mov.b r1, @r15
    mov.b @r15, r6
    mov.b @(4, r15), r0
    extu.b r6, r6
    mov r0, r5
    extu.b r5, r5
    mov.w @(8, r15), r0
    mov r0, r4
    .reloc ., R_SH_IND12W, FUN_06020414 - 4
    .2byte 0xB000    /* bsr FUN_06020414 (linker-resolved) */
    extu.w r4, r4
    bra     .L_060203F8
    nop

    .global DAT_060203be
DAT_060203be:
    .2byte  0x00FF
.L_pool_060203C0:
    .4byte  sym_0608780A
.L_pool_060203C4:
    .4byte  sym_0608782C
.L_pool_060203CF:
    .4byte  sym_0604BD72
.L_pool_060203D3:
    .4byte  sym_0605F458
.L_pool_060203D7:
    .4byte  sym_0605F478
.L_060203D4:
    mov.b @(2, r14), r0
    mov.b @r14, r5
    mov r0, r4
    extu.b r5, r5
    extu.b r4, r4
    mov.b @(1, r14), r0
    mul.l r11, r4
    mov r0, r6
    sts macl, r4
    extu.b r6, r6
    extu.w r4, r13
    shll r13
    add r10, r13
    mov r13, r7
    mov.w @r13, r4
    add #0x4, r7
    .reloc ., R_SH_IND12W, FUN_06020414 - 4
    .2byte 0xB000    /* bsr FUN_06020414 (linker-resolved) */
    extu.w r4, r4
.L_060203F8:
    add #0x3, r14
    mov.b @r14, r2
    extu.b r2, r2
    cmp/eq r12, r2
    bf      .L_060203D4
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
