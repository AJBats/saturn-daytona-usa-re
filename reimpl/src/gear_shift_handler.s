/* VERIFIED: called every physics frame during racing (part of player_physics_main pipeline)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   117 calls during LEFT (baseline 39, +78) — same delta as player_physics_main
 * Date: 2026-02-28
 */

   .section .text.FUN_06008318


   .global gear_shift_handler
   .type gear_shift_handler, @function
gear_shift_handler:
    sts.l pr, @-r15
    mov.l   .L_06008370, r4
    mov.w   .L_06008358, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_06008378
    mov.l @r4, r3
    mov.w   .L_06008358, r0
    mov.l @(r0, r3), r2
    add #-0x1, r2
    mov.l r2, @(r0, r3)
    mov.l @r4, r5
    mov.l   .L_06008374, r3
    mov.l @r4, r2
    mov.l @(r0, r5), r5
    mov r2, r1
    shll r5
    mov.w   DAT_0600835a, r0
    add r3, r5
    mov.l @(r0, r1), r3
    cmp/pl r3
    bf/s    .L_0600834C
    mov.w @r5, r5
    bra     .L_06008350
    exts.w r5, r3
.L_0600834C:
    exts.w r5, r1
    neg r1, r3
.L_06008350:
    mov.w   .L_06008360, r0
    mov.l r3, @(r0, r2)
    bra     .L_060083DE
    nop
.L_06008358:
    .2byte  0x00B8

    .global DAT_0600835a
DAT_0600835a:
    .2byte  0x01DC
    .4byte  0x03010201
.L_06008360:
    .2byte  0x01D8
    .2byte  0xFFFF
    .4byte  0xAE111BFF
    .4byte  sound_cmd_dispatch
    .4byte  sym_06034F78
.L_06008370:
    .4byte  sym_0607E940
.L_06008374:
    .4byte  sym_060453CC
.L_06008378:
    mov.l   .L_06008408, r2
    mov.w   .L_060083FA, r3
    mov.l @r2, r2
    cmp/gt r3, r2
    bf      .L_060083DE
    mov.l   .L_0600840C, r3
    mov.w   DAT_060083fc, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_060083DE
    mov #0x28, r6
    mov.l @r4, r2
    mov.l   .L_06008410, r7
    mov r2, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt/s    .L_060083BA
    mov #0x20, r5
    mov.l @r4, r3
    mov.w   .L_060083FE, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #-0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    bra     .L_060083DE
    mov.w r6, @(r0, r2)
.L_060083BA:
    mov.l @r4, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_060083DE
    mov.l @r4, r3
    mov.w   .L_060083FE, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    mov.w r6, @(r0, r2)
.L_060083DE:
    mov #0x0, r5
    mov.l @r4, r2
    mov.w   .L_06008404, r1
    mov.l   .L_06008414, r3
    jsr @r3
    mov r5, r0
    mov.l @r4, r2
    mov.w   .L_06008406, r1
    mov.l   .L_06008414, r3
    jsr @r3
    mov r5, r0
    lds.l @r15+, pr
    rts
    nop
.L_060083FA:
    .2byte  0x0258

    .global DAT_060083fc
DAT_060083fc:
    .2byte  0x00BC
.L_060083FE:
    .2byte  0x00B8

    .global DAT_06008400
DAT_06008400:
    .2byte  0x01DC

    .global DAT_06008402
DAT_06008402:
    .2byte  0x00D4
.L_06008404:
    .2byte  0x0301
.L_06008406:
    .2byte  0x0201
.L_06008408:
    .4byte  sym_0607EBD0
.L_0600840C:
    .4byte  sym_0607E940
.L_06008410:
    .4byte  sym_0607EBE0
.L_06008414:
    .4byte  sym_06034F78
