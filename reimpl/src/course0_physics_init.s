
    .section .text.FUN_06019BC8


    .global course0_physics_init
    .type course0_physics_init, @function

course0_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x6, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov.l   .L_pool_06019C10, r8
    mov.l   .L_pool_06019C14, r9
    mov.l   .L_pool_06019C08, r12
    mov.l   .L_pool_06019C18, r3
    mov.b @r3, r3
    tst r3, r3
    bt/s    .L_06019C74
    mov #0x3, r14

    mov #0x0, r13
.L_06019BEE:
    extu.b r13, r3
    mov.l   .L_pool_06019C1C, r2
    mov.l @r2, r2
    cmp/eq r2, r3
    bf      .L_06019C20
    bra     .L_06019C22
    extu.b r11, r10

    .global DAT_06019bfc
DAT_06019bfc:
    mov.l r0, @(0, r0)
    .word 0xFFFF
    .4byte  sym_0605D4F0
    .4byte  sym_0605D243
.L_pool_06019C08:
    .4byte  sym_0605D242
    .4byte  sym_0605D260
.L_pool_06019C10:
    .4byte  sym_06049B12
.L_pool_06019C14:
    .4byte  sym_06028400
.L_pool_06019C18:
    .4byte  sym_06085FF0
.L_pool_06019C1C:
    .4byte  sym_0605AD00

.L_06019C20:
    mov #0x5, r10

.L_06019C22:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_06019D08, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   .L_pool_06019D0C, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019BEE
    bra     .L_06019CF2
    nop

.L_06019C74:
    mov #0x0, r13
.L_06019C76:
    extu.b r13, r2
    mov.l   .L_pool_06019D10, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_06019CA2

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_06019C8E
    bra     .L_06019CA4
    extu.b r11, r10

.L_06019C8E:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_06019C9E
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12
.L_06019C9E:
    bra     .L_06019CA4
    nop

.L_06019CA2:
    extu.b r14, r10

.L_06019CA4:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_06019D08, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    mov.l   .L_pool_06019D0C, r3
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov.l @(4, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019C76

.L_06019CF2:
    add #0xC, r15
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
.L_pool_06019D08:
    .4byte  sym_06063750
.L_pool_06019D0C:
    .4byte  sym_06049B0C
.L_pool_06019D10:
    .4byte  sym_0605AD00
