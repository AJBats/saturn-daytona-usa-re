
    .section .text.FUN_06016CDC


    .global FUN_06016CDC
    .type FUN_06016CDC, @function
FUN_06016CDC:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov #0x0, r4
    extu.b r14, r3


    .global FUN_06016CE6
    .type FUN_06016CE6, @function
FUN_06016CE6:
    sts.l pr, @-r15
    extu.b r4, r1
    mov r3, r2
    add #-0x4, r15
    mov r1, r0
    shll2 r3
    shll2 r2
    mov.l   .L_pool_06016DC6, r13
    shll2 r2
    mov.b r5, @r15
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.b r0, @(1, r3)
    mov.l   .L_pool_06016DCA, r0
    mov.b @r0, r0
    tst r0, r0
    .word 0x0029
    mov.l   .L_pool_06016DCE, r3
    mov.l @r3, r3
    and r3, r0
    tst #0x1, r0
    bt/s    .L_06016D30
    extu.b r4, r7
    mov #0x28, r7
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l   .L_06016DCC, r1
    mov.l r1, @(44, r3)
.L_06016D30:
    mov.l   .L_pool_06016DD6, r5
    extu.b r14, r6
    mov.b @r15, r4
    extu.b r7, r2
    mov r6, r3
    extu.b r4, r4
    shll2 r6
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r6
    exts.w r6, r6
    mov r4, r3
    add r13, r6
    shll2 r4
    add r3, r4
    add r2, r4
    mov r4, r0
    shll r0
    mov.w @(r0, r5), r3
    mov r4, r0
    shll16 r3
    add #0x1, r0
    mov.l r3, @(4, r6)
    shll r0
    mov.w @(r0, r5), r3
    mov r4, r0
    shll16 r3
    add #0x2, r0
    mov.l r3, @(8, r6)
    shll r0
    mov.w @(r0, r5), r3
    mov r4, r0
    shll16 r3
    add #0x3, r0
    mov.l r3, @(12, r6)
    shll r0
    mov.w @(r0, r5), r3
    mov r4, r0
    shll16 r3
    add #0x4, r0
    mov.l r3, @(16, r6)
    shll r0
    mov.w @(r0, r5), r3
    shll16 r3
    mov.l r3, @(52, r6)
    .reloc ., R_SH_IND12W, FUN_06016DD8 - 4
    .2byte 0xB000    /* bsr FUN_06016DD8 (linker-resolved) */
    extu.b r14, r4
    extu.b r14, r4
    mov.l   .L_pool_06016DDA, r2
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.b @r15, r3
    add r2, r4
    extu.b r3, r3
    add #0x17, r3
    extu.w r3, r0
    mov.w r0, @(6, r4)
    mov #0x1, r0
    mov.b r0, @(4, r4)
    mov #0x3A, r0
    mov.b r0, @(5, r4)
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_06016DC6:
    .4byte  sym_06084FC8
.L_pool_06016DCA:
    .4byte  sym_06085F89
.L_pool_06016DCE:
    .4byte  sym_0607EBF4
.L_06016DCC:
    .4byte  0x00008000
.L_pool_06016DD6:
    .4byte  sym_0605BB74
.L_pool_06016DDA:
    .4byte  sym_06085490
