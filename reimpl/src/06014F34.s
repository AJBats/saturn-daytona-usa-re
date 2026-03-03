
    .section .text.FUN_06014F34


    .global ai_position_ranking
    .type ai_position_ranking, @function
ai_position_ranking:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06015008, r12
    mov.l   .L_pool_0601500C, r14
    mov.l   .L_pool_06015010, r13
    mov.l   .L_pool_06015014, r5
    mov.l @r5, r0
    cmp/eq #0x19, r0
    .word 0x0029
    mov.l   .L_pool_06015018, r3
    mov.l @r3, r3
    and r3, r0
    tst #0x1, r0
    bt/s    .L_06014F5C
    mov #0x23, r4
    mov.l   .L_pool_0601501C, r13
    bra     .L_06014F66
    mov #0x28, r4
.L_06014F5C:
    mov.l @r5, r0
    cmp/eq #0x15, r0
    bf      .L_06014F66
    mov.l   .L_pool_06015020, r13
    mov #0x6, r4
.L_06014F66:
    extu.b r4, r4
    mov.w @r14, r5
    extu.w r5, r5
    cmp/gt r4, r5
    .word 0x0029
    xor #0x1, r0
    mov r0, r3
    mov r5, r0
    cmp/eq #0x64, r0
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r3
    tst r3, r3
    bt      .L_06015030
    mov.l   .L_pool_06015024, r3
    mov.w @r12, r2
    mov.l @r3, r3
    sub r3, r2
    mov.w r2, @r12
    mov.w @r12, r3
    cmp/pl r3
    bt      .L_06015030
.L_06014F94:
    mov.l   .L_pool_06015028, r3
    jsr @r3
    mov #0x0, r4
    extu.b r0, r5
    extu.b r5, r0
    cmp/eq #0x11, r0
    bt      .L_06015030
    extu.b r5, r4
    mov.l   .L_pool_0601502C, r2
    mov.w @r14, r0
    mov r4, r3
    extu.w r0, r0
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov r0, r3
    add r2, r4
    shll r0
    add r3, r0
    mov.b @(r0, r13), r2
    mov.b r2, @r4
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    add r13, r3
    mov.b @(2, r3), r0
    mov r0, r1
    mov #0x40, r0
    mov.b r1, @(r0, r4)
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    add r13, r3
    mov.b @(1, r3), r0
    mov r0, r3
    extu.b r3, r3
    mov.w r3, @r12
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x15, r0
    bf      .L_06014FFE
    mov #0x64, r2
    mov.w r2, @r14
.L_06014FFE:
    mov.w @r12, r3
    tst r3, r3
    bf      .L_06015030
    bra     .L_06014F94
    nop
.L_pool_06015008:
    .4byte  sym_06085F94
.L_pool_0601500C:
    .4byte  sym_06085F90
.L_pool_06015010:
    .4byte  sym_0605B73A
.L_pool_06015014:
    .4byte  g_game_state
.L_pool_06015018:
    .4byte  sym_0607EBF4
.L_pool_0601501C:
    .4byte  sym_0605B7A6
.L_pool_06015020:
    .4byte  sym_0605B821
.L_pool_06015024:
    .4byte  sym_0606BDF8
.L_pool_06015028:
    .4byte  vdp2_data_lookup
.L_pool_0601502C:
    .4byte  sym_06084FC8
.L_06015030:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
