
    .section .text.FUN_06007658


    .global vdp1_sprite_render
    .type vdp1_sprite_render, @function
vdp1_sprite_render:
    mov.l r14, @-r15
    extu.w r4, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x10, r15
    mov.l   .L_pool_060076E4, r12
    mov.l   .L_pool_060076E8, r13
    mov.l   .L_pool_060076EC, r14
    mov.l r7, @(4, r15)
    cmp/eq #0xA, r0
    bf      .L_06007682
    mov.l @r13, r2
    shll2 r2
    shll r2
    mov.l   .L_pool_060076F0, r3
    mov.l @r3, r3
    add r3, r2
    mov.l   .L_pool_060076F4, r1
    mov.l r2, @r1
.L_06007682:
    extu.w r5, r0
    extu.w r4, r2
    mov.l r0, @r15
    shll r2
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    and #0x3F, r0
    extu.w r0, r0
    mov.w r0, @(8, r15)
    mov.w   .L_wpool_060076E2, r7
    mov.l @r15, r3
    and r7, r3
    extu.w r3, r3
    mov r3, r0
    mov.w r0, @(12, r15)
    mov.l   .L_pool_060076F8, r1
    mov.l @r14, r0
    add r1, r2
    mov.w r0, @r2
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov.l @r13, r2
    mov.l r2, @r3
    extu.w r4, r1
    mov r1, r0
    cmp/eq #0xD, r0
    bt      .L_060076FC
    mov r1, r0
    cmp/eq #0xE, r0
    bt      .L_060076FC
    mov r1, r0
    cmp/eq #0xF, r0
    bt      .L_060076FC
    mov.l @r14, r2
    shll2 r2
    shll r2
    add r12, r2
    mov r5, r0
    bra     .L_06007732
    mov.w r0, @(4, r2)

    .global DAT_060076e2
.L_wpool_060076E2:
DAT_060076e2:
    .2byte  0x00FF
.L_pool_060076E4:
    .4byte  sym_06063F64
.L_pool_060076E8:
    .4byte  sym_0606A4EC
.L_pool_060076EC:
    .4byte  sym_0606A4F4
.L_pool_060076F0:
    .4byte  sym_06063F5C
.L_pool_060076F4:
    .4byte  sym_06063F60
.L_pool_060076F8:
    .4byte  sym_060684EC
.L_060076FC:
    extu.w r5, r4
    mov #0x3, r0
    mov.w   .L_wpool_0600777E, r2
    mov r4, r5
    and r4, r2
    and r7, r5
    extu.w r2, r2
    extu.w r5, r1
    mov.w r2, @r15
    mov.l   .L_pool_06007780, r3
    jsr @r3
    extu.w r1, r1
    mov r0, r5
    mov.w @r15, r3
    extu.w r5, r1
    extu.w r3, r3
    or r3, r1
    extu.w r1, r5
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov r5, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    mov.l   .L_pool_06007784, r2
    mov.l r3, @r2
.L_06007732:
    mov r6, r0
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov.w r0, @(6, r3)
    mov.l @r13, r5
    mov.l   .L_pool_06007788, r3
    mov.l   .L_pool_0600778C, r2
    shll2 r5
    mov.l @r3, r3
    shll r5
    add r3, r5
    jsr @r2
    mov.l @(4, r15), r4
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.w @(8, r15), r0
    mov.l @r13, r2
    mov r0, r4
    mov.w @(12, r15), r0
    mov r0, r3
    mulu.w r3, r4
    mov #0x0, r3
    sts macl, r4
    cmp/gt r4, r3
    addc r3, r4
    shar r4
    add r4, r2
    mov.l r2, @r13
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600777e
.L_wpool_0600777E:
DAT_0600777e:
    .2byte  0x3F00
.L_pool_06007780:
    .4byte  sym_06034FE0
.L_pool_06007784:
    .4byte  sym_0606A4F0
.L_pool_06007788:
    .4byte  sym_06063F5C
.L_pool_0600778C:
    .4byte  dma_memory_transfer
