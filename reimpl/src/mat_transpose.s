
    .section .text.FUN_0601E770


    .global mat_transpose
    .type mat_transpose, @function
mat_transpose:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0601E7FC, r13
    mov.w r0, @(4, r15)
    mov.l r6, @r15
    mov.l   .L_0601E800, r3
    jsr @r3
    mov r12, r4
    mov #0xB, r2
    cmp/gt r2, r0
    bf      .L_0601E78C
    mov #0x0, r2
    mov r2, r0
    mov.b r0, @(11, r12)
.L_0601E78C:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E78C
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_0601E804, r2
    mov.b r3, @r2
.L_0601E7A0:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E7A0
    mov.l   .L_0601E808, r3
    mov r12, r5
    mov.w @(4, r15), r0
    mov.l @r15, r6
    mov.l @r3, r3
    mov r0, r4
    mov.l @(20, r3), r2
    extu.w r4, r4
    mov.l   .L_0601E80C, r3
    shll2 r4
    shll2 r4
    shll r4
    add r3, r4
    mov.w @(28, r4), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    mov r0, r4
.L_0601E7CE:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E7CE
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_0601E804, r2
    mov.b r3, @r2
.L_0601E7E2:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E7E2
    mov r4, r0
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601E7FC:
    .4byte  0x20100063
.L_0601E800:
    .4byte  sym_06035C1C
.L_0601E804:
    .4byte  0x2010001F
.L_0601E808:
    .4byte  sym_06000354
.L_0601E80C:
    .4byte  sym_06087094
