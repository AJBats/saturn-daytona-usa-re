/* VERIFIED: called every physics frame during racing (3x more during steering)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   120 calls during LEFT (baseline 40, +80) — same proportional increase as
 *   player_physics_main pipeline (called for all cars, not just player)
 * Date: 2026-02-28
 */

    .section .text.FUN_0600CD40


    .global track_pos_query
    .type track_pos_query, @function
track_pos_query:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600CDC4, r14
    mov.w   DAT_0600cdbe, r0
    mov.l @r14, r14
    mov.l @(r0, r14), r13
    add #-0x4, r0
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r13
    shll2 r3
    add r3, r13
    mov.l @(r0, r14), r3
    add r3, r13
    mov.w @(22, r13), r0
    mov r0, r3
    extu.w r3, r3
    mov.w   DAT_0600cdc0, r0
    mov.l r3, @(r0, r14)
    mov.l @(4, r13), r5
    mov.l @(24, r14), r3
    mov.l @(16, r14), r4
    mov.l @r13, r2
    sub r3, r5
    mov.l   .L_pool_0600CDC8, r3
    jsr @r3
    sub r2, r4
    exts.w r0, r4
    exts.w r4, r6
    mov.w @(14, r13), r0
    mov r6, r7
    mov r0, r5
    shll2 r5
    sub r5, r7
    cmp/pz r7
    bt      .L_dist_positive
    mov r5, r2
    bra     .L_have_angular_dist
    sub r6, r2
.L_dist_positive:
    mov r7, r2
.L_have_angular_dist:
    mov.w   DAT_0600cdc2, r3
    cmp/gt r3, r2
    bf      .L_return
    mov.w   DAT_0600cdbe, r0
    mov.l @(r0, r14), r3
    add #0x1, r3
    mov.l r3, @(r0, r14)
    mov.l @(r0, r14), r3
    mov.l   .L_pool_0600CDCC, r2
    mov.l @r2, r2
    cmp/gt r2, r3
    bf      .L_return
    mov #0x0, r2
    mov.w   DAT_0600cdbe, r0
    mov.l r2, @(r0, r14)
.L_return:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600cdbc
DAT_0600cdbc:
    mov.b @(r0, r14), r1

    .global DAT_0600cdbe
DAT_0600cdbe:
    .2byte  0x01E4
    .global DAT_0600cdc0
DAT_0600cdc0:
    .2byte  0x0184
    .global DAT_0600cdc2
DAT_0600cdc2:
    .2byte  0x4000
.L_pool_0600CDC4:
    .4byte  sym_0607E940
.L_pool_0600CDC8:
    .4byte  atan2
.L_pool_0600CDCC:
    .4byte  sym_0607EA9C
