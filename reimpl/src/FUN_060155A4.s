
    .section .text.FUN_060155A4


    .global FUN_060155A4
    .type FUN_060155A4, @function
FUN_060155A4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06015668, r8
    mov #0x4, r9
    mov.l   .L_0601566C, r10
    mov.l   .L_pool_06015670, r11
    mov.l   .L_pool_06015674, r13
    mov #0x0, r14
.L_060155C0:
    extu.b r14, r4
    mov r4, r0
    cmp/eq #0x3, r0
    .word 0x0029
    tst r4, r4
    .word 0x0129
    or r1, r0
    tst r0, r0
    bt      .L_06015614
    extu.b r14, r12
    mov r8, r5
    mov r12, r3
    shll2 r12
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r12
    exts.w r12, r12
    add r13, r12
    jsr @r11
    mov.l @(28, r12), r4
    mov.l r0, @(16, r12)
    mov r10, r5
    jsr @r11
    mov.l @(28, r12), r4
    mov r0, r2
    cmp/pz r2
    bt/s    .L_0601562A
    mov.l r0, @(20, r12)
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(20, r4), r2
    neg r2, r2
    bra     .L_0601562A
    mov.l r2, @(20, r4)
.L_06015614:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(28, r4), r2
    mov.l r2, @(16, r4)
.L_0601562A:
    extu.b r14, r4
    mov r4, r3
    add #0x1, r14
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(36, r4), r2
    mov.l @(24, r4), r3
    add r2, r3
    mov.l r3, @(24, r4)
    mov.l @(32, r4), r2
    mov.l @(28, r4), r3
    add r2, r3
    mov.l r3, @(28, r4)
    extu.b r14, r2
    cmp/ge r9, r2
    bf      .L_060155C0
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06015668:
    .4byte  0x0000DDB2
.L_0601566C:
    .4byte  0x00008000
.L_pool_06015670:
    .4byte  FUN_06027552
.L_pool_06015674:
    .4byte  sym_06084FC8

    .global FUN_06015678
FUN_06015678:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_06015730, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x26    /* mov.l .L_pool_06015734, r2 */
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15


    .global FUN_060156A6
    .type FUN_060156A6, @function
FUN_060156A6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r13


    .global FUN_060156AC
    .type FUN_060156AC, @function
FUN_060156AC:
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r1
    mov.l   .L_pool_06015738, r2
    mov.l   .L_pool_0601573C, r3
    jsr @r3
    mov #0x4, r0
    extu.b r13, r14
    mov.l   .L_pool_06015730, r2
    extu.b r13, r4
    mov r14, r3
    shll2 r4
    shll2 r14
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r3
    add r3, r14
    exts.w r14, r14
    mov.l   .L_pool_06015740, r3
    add r2, r14
    add r3, r4
    mov.l @r4, r2
    mov.l r2, @(4, r14)
    mov.l @(4, r4), r3
    mov.l r3, @(8, r14)
    mov.l @(8, r4), r2
    mov.l r2, @(12, r14)
    mov.l @(12, r4), r3
    mov.l r3, @(52, r14)
    mov.l   .L_pool_06015744, r3
    jsr @r3
    extu.b r13, r4
    extu.b r13, r4
    mov.l   .L_pool_06015748, r2
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    extu.b r13, r3
    add r2, r4
    mov r15, r2
    add r2, r3
    mov.b @r3, r3
    extu.b r3, r0
    mov.w r0, @(6, r4)
    mov #0x3C, r3
    mov #0x1, r0
    mov.b r0, @(4, r4)
    mov #0x3A, r0
    mov.b r0, @(5, r4)
    mov #0x41, r0
    mov.b r3, @(r0, r14)
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_06015730:
    .4byte  sym_06084FC8
    .4byte  sym_0605B858
.L_pool_06015738:
    .4byte  sym_0605B8A0
.L_pool_0601573C:
    .4byte  sym_06035228
.L_pool_06015740:
    .4byte  sym_0605B860
.L_pool_06015744:
    .4byte  FUN_06016DD8
.L_pool_06015748:
    .4byte  sym_06085490
