
    .section .text.FUN_060100A4


    .global sprite_anim_render
    .type sprite_anim_render, @function
sprite_anim_render:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r3
    extu.b r14, r4
    extu.b r14, r1
    mov.l r12, @-r15
    shll2 r4
    mov.l r11, @-r15
    shll2 r4
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l r3, @r15
    mov.w   DAT_060100f6, r2
    add r2, r3
    extu.w r3, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_p_sprite_param_tbl, r2
    mov.w   DAT_060100f8, r12
    mov.l   .L_fp_one, r13
    mov.l   .L_p_player_car_idx, r0
    add r2, r4
    mov.l @r0, r0
    mov.l @r4, r10
    cmp/eq r0, r1
    bt/s    .L_is_player_car
    mov.l @(4, r4), r11
    mov.l @r15, r5
    add #0x3, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_p_alt_sprite_data, r3
    add r3, r5
    bra     .L_do_dma_transfer
    mov #0x20, r6

    .global DAT_060100f2
DAT_060100f2:
    .word 0x06A2

    .global DAT_060100f4
DAT_060100f4:
    stc vbr, r11

    .global DAT_060100f6
DAT_060100f6:
    .2byte  0x0101
    .global DAT_060100f8
DAT_060100f8:
    .2byte  0x8000
    .2byte  0xFFFF
    .4byte  sym_0605AB19            /* "MIRROR MODE" string (adjacent data) */
.L_p_sprite_param_tbl:
    .4byte  sym_060447C8            /* sprite animation parameter table (16 bytes/car) */
.L_fp_one:
    .4byte  0x00010000              /* 1.0 (16.16 fixed-point) */
.L_p_player_car_idx:
    .4byte  sym_0607EAD8            /* player car index (dword) */
.L_p_alt_sprite_data:
    .4byte  sym_0605D0BC            /* alternate sprite palette/data (non-player) */
.L_is_player_car:
    mov #0x20, r6
    extu.b r14, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_p_sprite_palette, r3
    add r3, r5
.L_do_dma_transfer:
    extu.b r14, r4
    mov.l   .L_p_car_dma_ptrs, r2
    mov.l   .L_p_fn_dma_transfer, r1
    shll2 r4
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l   .L_p_game_state, r3
    mov #0x4, r2
    mov.b @r3, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_check_y_override
    extu.b r14, r2
    mov.l   .L_p_player_car_idx2, r3
    mov.l   .L_p_anim_counters, r5
    mov.l @r3, r3
    cmp/eq r3, r2
    bf/s    .L_check_other_car
    mov #0x1E, r4
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_inc_player_counter
    extu.b r14, r0
    shll r0
    mov #0x20, r3
    mov.w r3, @(r0, r5)
    mov r3, r4
    bra     .L_apply_player_anim
    nop
.L_inc_player_counter:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
.L_apply_player_anim:
    mov r14, r5
    mov r14, r3
    mov.l   .L_p_velocity_tbl, r2
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    exts.b r5, r5
    extu.w r4, r3
    add r2, r5
    mov.l @r5, r1
    mul.l r3, r1
    mov.l @(4, r5), r1
    sts macl, r3
    add r3, r10
    extu.w r4, r3
    mul.l r3, r1
    sts macl, r3
    add r3, r11
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   DAT_060101b2, r1
    bra     .L_apply_alpha_decay
    mul.l r1, r4
.L_check_other_car:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_inc_other_counter
    bra     .L_epilogue
    nop

    .global DAT_060101b2
DAT_060101b2:
    .2byte  0x020C                  /* player alpha decay rate per frame */
.L_p_sprite_palette:
    .4byte  sym_0605D0BC            /* sprite palette/data source */
.L_p_car_dma_ptrs:
    .4byte  sym_06078888            /* per-car DMA destination pointer table */
.L_p_fn_dma_transfer:
    .4byte  dma_transfer            /* DMA transfer function */
.L_p_game_state:
    .4byte  sym_0607887F            /* game state byte (>4 = racing) */
.L_p_anim_counters:
    .4byte  sym_06078870            /* per-car animation counters (16-bit each) */
.L_p_player_car_idx2:
    .4byte  sym_0607EAD8            /* player car index (dword) */
.L_p_velocity_tbl:
    .4byte  sym_060447F8            /* per-car XY velocity table (12 bytes/entry) */
.L_inc_other_counter:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   .L_w_alpha_decay_rate, r2
    mul.l r2, r4
.L_apply_alpha_decay:
    sts macl, r4
    sub r4, r13
.L_check_y_override:
    mov #0xC, r2
    mov.l   .L_p_game_state2, r3
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_build_transform
    mov.l   .L_p_fixed_y_offset, r11
.L_build_transform:
    mov.l   .L_p_display_mode_idx, r2
    mov r11, r5
    mov.l   .L_p_zdepth_tbl, r3
    mov.l @r2, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r1
    mov.l r1, @r15
    mov.w @(4, r15), r0
    mov r0, r2
    mov.l r2, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_wram_low, r7
    mov.l @(12, r15), r6
    mov.l   .L_p_fn_rigid_body_xform, r2
    shlr r6
    shll16 r6
    jsr @r2
    mov r10, r4
    add #0xC, r15
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  0xD416E200              /* following TU code (not part of this function) */
    .4byte  0xD016D317
    .4byte  0x6001600D
    .4byte  0x2422203A
    .4byte  0x9215C9FF
    .4byte  0x650D3527
    .4byte  0x8B026242
    .4byte  0x72012422
    .4byte  0x655D930D
    .4byte  0x35378B02
    .4byte  0x63427301
    .4byte  0x24326242
    .4byte  0xD30D2320
    .4byte  0x6142D30D
    .4byte  0x000B2312
.L_w_alpha_decay_rate:
    .2byte  0x072B                  /* non-player alpha decay rate per frame */
    .2byte  0x0080
    .4byte  0x00C0FFFF
.L_p_game_state2:
    .4byte  sym_0607887F            /* game state byte (>=0xC -> fixed Y override) */
.L_p_fixed_y_offset:
    .4byte  0x00960000              /* fixed Y offset for state >= 0xC (16.16) */
.L_p_display_mode_idx:
    .4byte  sym_0605AA98            /* display mode index (dword) */
.L_p_zdepth_tbl:
    .4byte  sym_06044844            /* Z-depth ordering table (dword per mode) */
.L_wram_low:
    .4byte  0x00200000              /* Work RAM Low base */
.L_p_fn_rigid_body_xform:
    .4byte  rigid_body_transform    /* rigid body transform function */
    .4byte  sym_0607EADC            /* frame counter (dword) */
    .4byte  sym_06063D9C            /* input state word */
    .4byte  0x0000FFFF
    .4byte  sym_0607887E            /* game sub-state byte */
    .4byte  sym_0607EAD8            /* player car index (dword) */
    .4byte  0xD519634D              /* following TU code (byte blob) */
    .4byte  0xD2192329
    .4byte  0x23388907
    .4byte  0xE202D316
    .4byte  0x63323323
    .4byte  0x89026252
    .4byte  0x72012522
    .4byte  0x644D9320
    .4byte  0x24392448
    .4byte  0x8906D310
    .4byte  0x63324315
    .4byte  0x8B026352
    .4byte  0x73FF2532
    .4byte  0x6252D30E
    .4byte  0x23206152
    .4byte  0xD30D000B
    .4byte  0x2312624D
