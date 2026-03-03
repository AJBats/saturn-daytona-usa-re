/* VERIFIED (2026-03-01): circuit select confirm/back handler.
 * Called from transition_handler_a every frame on circuit select screen.
 * BACK path: checks button mask at .L_wpool_0601030C (B=0x0100), sets g_game_state=6.
 * CONFIRM path: checks mask at DAT_0601038c (C=0x0200), plays sound, advances dispatch to 2.
 * Evidence: RE_TEST #2 swapped B/C masks, confirmed working in-game.
 */
	.text
    .global circuit_confirm_handler
circuit_confirm_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06010320, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.w   .L_wpool_0601030C, r3
    and r3, r2
    tst r2, r2
    bt      .L_06010328
    mov #0x6, r3
    mov.l   .L_pool_06010324, r2
    mov.l r3, @r2
    bra     .L_06010386
    nop
    .short  0x4000
.L_wpool_0601030C:
    .short  0x0100
    .short  0xFFFF
    .long  sym_0607EADC
    .long  0x00008000
    .long  sym_0607887E
    .long  sym_0607EAD8
.L_pool_06010320:
    .long  sym_0607EBCC
.L_pool_06010324:
    .long  g_game_state
.L_06010328:
    mov.l @r14, r2
    cmp/pl r2
    bf      .L_06010338
    extu.w r4, r4
    mov.w   DAT_0601038c, r2
    and r2, r4
    tst r4, r4
    bt      .L_06010386
.L_06010338:
    mov.l   .L_pool_06010390, r5
    mov.l   .L_pool_06010394, r3
    mov.l   .L_pool_06010398, r2
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
    mov #0x0, r5
    mov #0x2, r3
    mov.l r5, @r14
    mov.l   .L_pool_0601039C, r2
    exts.b r5, r5
    mov.b r3, @r2
    mov.l   .L_pool_060103A0, r3
    mov.l   .L_pool_060103A4, r2
    mov.l @r3, r3
    exts.b r3, r3
    mov.b r3, @r2
    mov.l   .L_pool_060103A8, r4
    mov.b r5, @r4
    mov.l   .L_pool_060103AC, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_06010386
    mov.l   .L_pool_060103B0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06010386
    mov.l   .L_pool_060103B4, r3
    mov.w @r3, r2
    mov.w   DAT_0601038e, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06010386
    mov #0x1, r3
    mov.b r3, @r4
.L_06010386:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0601038c
DAT_0601038c:
    .short  0x0200

    .global DAT_0601038e
DAT_0601038e:
    .short  0x1000
.L_pool_06010390:
    .long  sym_0607EADC
.L_pool_06010394:
    .long  sym_0604481C                    /* sound command table base (4-byte entries) */
.L_pool_06010398:
    .long  sound_cmd_dispatch
.L_pool_0601039C:
    .long  sym_0607887F
.L_pool_060103A0:
    .long  sym_0607EAD8
.L_pool_060103A4:
    .long  sym_06078648
.L_pool_060103A8:
    .long  sym_0605AB18
.L_pool_060103AC:
    .long  sym_06085FF4
.L_pool_060103B0:
    .long  sym_0605AD00
.L_pool_060103B4:
    .long  g_pad_state
