

    .section .text.FUN_06013A74


    .global best_time_compare
    .type best_time_compare, @function
best_time_compare:
    sts.l pr, @-r15
    .byte   0xB4, 0x73    /* bsr 0x06014360 (external) */
    nop
    .byte   0xB3, 0x77    /* bsr 0x0601416C (external) */
    nop
    .byte   0xB3, 0xE5    /* bsr 0x0601424C (external) */
    nop
    .byte   0xB3, 0x1F    /* bsr 0x060140C4 (external) */
    nop
    .byte   0xB4, 0xE1    /* bsr 0x0601444C (external) */
    nop
    mov.l   .L_pool_06013AEC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_mode_not_attract
    .byte   0xB4, 0xE7    /* bsr 0x06014466 (external) */
    nop
    bra     .L_after_mode_branch
    nop
.L_mode_not_attract:
    .byte   0xB5, 0x36    /* bsr 0x0601450C (external) */
    nop
.L_after_mode_branch:
    .byte   0xB5, 0x8C    /* bsr 0x060145BC (external) */
    nop
    mov.l   .L_pool_06013AF0, r2
    mov.w @r2, r3
    mov.w   .L_wpool_06013AEA, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_skip_wall_call
    .byte   0xB6, 0x0E    /* bsr 0x060146D2 (external) */
    nop
.L_skip_wall_call:
    mov #0x4, r3
    mov.l   .L_pool_06013AF4, r2
    mov.l @r2, r2
    cmp/hs r3, r2
    bt      .L_tail_wall_call
    mov.l   .L_pool_06013AF8, r3
    mov.l   .L_pool_06013AF8, r2
    mov.w @r3, r3
    add #-0x1, r3
    mov.w r3, @r2
    exts.w r3, r3
    cmp/pl r3
    bt      .L_return_normal
.L_tail_wall_call:
    .byte   0xA5, 0xFF    /* bra 0x060146D2 (external) */
    lds.l @r15+, pr
.L_return_normal:
    lds.l @r15+, pr
    rts
    nop

    .global loc_06013ADA
loc_06013ADA:
    mov #0x5, r3
    mov.l   .L_pool_06013AFC, r2
    mov.b r3, @r2
    mov #0x0, r3
    mov.l   .L_pool_06013B00, r2
    mov.w r3, @r2
    .byte   0xA0, 0x0D    /* bra 0x06013B04 (external) */
    nop
.L_wpool_06013AEA:
    .2byte  0x0800                        /* button mask: bit 11 (Start / action button) */
.L_pool_06013AEC:
    .4byte  sym_06063D9E                  /* game mode word (0x10 = attract/demo mode) */
.L_pool_06013AF0:
    .4byte  sym_06063D9A                  /* new button presses (edge-triggered, per-frame) */
.L_pool_06013AF4:
    .4byte  sym_06084B18                  /* active car count in race (32-bit) */
.L_pool_06013AF8:
    .4byte  sym_06084AF0                  /* post-race countdown timer (16-bit, counts down to 0) */
.L_pool_06013AFC:
    .4byte  sym_06084AF2                  /* post-race mode byte (set to 0x05 at loc_06013ADA) */
.L_pool_06013B00:
    .4byte  sym_06084AF6                  /* post-race wait counter (reset to 0 at loc_06013ADA) */
