
    .section .text.FUN_06020CF4


    .global FUN_06020CF4
    .type FUN_06020CF4, @function
FUN_06020CF4:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.w   DAT_06020db2, r5
    mov.l   .L_pool_06020DB4, r4
    exts.w r5, r0
    mov.w r0, @(8, r4)
    exts.w r5, r0
    mov.w r0, @(10, r4)
    exts.w r5, r0
    mov.w r0, @(12, r4)
    exts.w r5, r0
    mov.w r0, @(14, r4)
    exts.w r5, r0
    mov.w r0, @(16, r4)
    exts.w r5, r0
    mov.w r0, @(18, r4)
    exts.w r5, r0
    mov.w r0, @(20, r4)
    exts.w r5, r0
    mov.w r0, @(22, r4)
    mov #0x17, r0
    mov.w r0, @(6, r4)
    mov #0x0, r0
    mov.b r0, @(4, r4)
    mov #0x3A, r0
    mov.b r0, @(5, r4)
    mov.l   .L_pool_06020DB8, r14
    mov.l   .L_pool_06020DBC, r3
    mov.l @r14, r5
    jsr @r3
    nop
    mov.l   .L_pool_06020DC0, r4
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06020D46
    .type FUN_06020D46, @function
FUN_06020D46:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x10, r11


    .global FUN_06020D50
    .type FUN_06020D50, @function
FUN_06020D50:
    sts.l pr, @-r15
    add #-0x24, r15
    mov r15, r12
    mov r15, r1
    mov.l   .L_pool_06020DC8, r2
    mov.l   .L_pool_06020DC4, r13
    mov.l   .L_pool_06020DCC, r3
    jsr @r3
    mov #0x24, r0
    mov #0x0, r14
.L_06020D64:
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_06020D9C
    extu.b r14, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r0
    exts.w r0, r0
    mov.b @(r0, r13), r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r12), r3
    jsr @r3
    mov r14, r4
.L_06020D9C:
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r11, r2
    bf      .L_06020D64
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06020db2
DAT_06020db2:
    mov.b @(r0, r2), r1
.L_pool_06020DB4:
    .4byte  sym_06087C6C
.L_pool_06020DB8:
    .4byte  sym_060785FC
.L_pool_06020DBC:
    .4byte  sym_060280F8
.L_pool_06020DC0:
    .4byte  sym_0605A008
.L_pool_06020DC4:
    .4byte  sym_0608782C
.L_pool_06020DC8:
    .4byte  sym_0605F5A8
.L_pool_06020DCC:
    .4byte  sym_06035168
