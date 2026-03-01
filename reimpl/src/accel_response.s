/* VERIFIED: called every physics frame during racing (part of player_physics_main pipeline)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   117 calls during LEFT (baseline 39, +78) — same delta as player_physics_main
 * Date: 2026-02-28
 */

    .section .text.FUN_0600C4F8


    .global accel_response
    .type accel_response, @function
accel_response:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600C5A0, r13
    mov.l   .L_0600C5A4, r14
    mov.w   DAT_0600c590, r0
    mov.l @r14, r14
    mov.w @(r0, r14), r3
    cmp/pl r3
    bf      .L_0600C516
    mov.w   DAT_0600c590, r0
    mov.w @(r0, r14), r2
    add #-0x1, r2
    mov.w r2, @(r0, r14)
.L_0600C516:
    mov.l   .L_0600C5A8, r3
    mov.l   .L_0600C5AC, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bf      .L_0600C5CC
    mov.w   .L_0600C592, r12
    mov.w   DAT_0600c594, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_0600C534
    mov.w   DAT_0600c596, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bt      .L_0600C53A
.L_0600C534:
    mov.w   DAT_0600c598, r0
    bra     .L_0600C580
    mov.l r12, @(r0, r14)
.L_0600C53A:
    mov.l @(8, r14), r4
    mov.l   .L_0600C5B0, r2
    mov.l   .L_0600C5B4, r3
    shll2 r4
    add r4, r2
    add r4, r3
    mov.l @r2, r2
    mov.l @r3, r3
    mov.l   .L_0600C5B8, r4
    sub r3, r2
    add r2, r4
    jsr @r13
    mov #0x1, r5
    mov r0, r4
    mov.w   DAT_0600c59a, r0
    jsr @r13
    mov.l @(r0, r14), r5
    mov r0, r5
    mov.l @(12, r14), r3
    shar r5
    mov.w   .L_0600C59C, r0
    mov.l @(r0, r14), r4
    sub r3, r4
    cmp/ge r12, r4
    bt      .L_0600C572
    mov.w   DAT_0600c598, r0
    bra     .L_0600C580
    mov.l r12, @(r0, r14)
.L_0600C572:
    cmp/ge r4, r5
    bt      .L_0600C57C
    mov.w   DAT_0600c598, r0
    bra     .L_0600C580
    mov.l r5, @(r0, r14)
.L_0600C57C:
    mov.w   DAT_0600c598, r0
    mov.l r4, @(r0, r14)
.L_0600C580:
    mov.l @(12, r14), r4
    mov.w   DAT_0600c598, r0
    mov.l @(r0, r14), r3
    add r3, r4
    cmp/pl r4
    bf      .L_0600C5BC
    bra     .L_0600C5C0
    mov.l r4, @(12, r14)

    .global DAT_0600c590
DAT_0600c590:
    .2byte  0x00D4
.L_0600C592:
    .2byte  0xF052

    .global DAT_0600c594
DAT_0600c594:
    .2byte  0x00BC

    .global DAT_0600c596
DAT_0600c596:
    .2byte  0x00B8

    .global DAT_0600c598
DAT_0600c598:
    .2byte  0x00FC

    .global DAT_0600c59a
DAT_0600c59a:
    .2byte  0x0198
.L_0600C59C:
    .2byte  0x0194
    .2byte  0xFFFF
.L_0600C5A0:
    .4byte  fpmul
.L_0600C5A4:
    .4byte  sym_0607E940
.L_0600C5A8:
    .4byte  sym_0607EBC4
.L_0600C5AC:
    .4byte  0x00008000
.L_0600C5B0:
    .4byte  sym_060477EC
.L_0600C5B4:
    .4byte  sym_060454CC
.L_0600C5B8:
    .4byte  0xFEC00000
.L_0600C5BC:
    mov #0x0, r2
    mov.l r2, @(12, r14)
.L_0600C5C0:
    .byte   0xD5, 0x16    /* mov.l .L_pool_0600C61C, r5 */
    jsr @r13
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.l r0, @(8, r14)
.L_0600C5CC:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
