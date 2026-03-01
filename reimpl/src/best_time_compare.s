

    .section .text.FUN_06013A74


    .global best_time_compare
    .type best_time_compare, @function
best_time_compare:
    sts.l pr, @-r15
    .byte   0xB4, 0x73    /* bsr 0x06014360 (external) */  ! call multi_obj_physics
    nop
    .byte   0xB3, 0x77    /* bsr 0x0601416C (external) */  ! call race_variant_setup_a
    nop
    .byte   0xB3, 0xE5    /* bsr 0x0601424C (external) */  ! call camera_angle_interp
    nop
    .byte   0xB3, 0x1F    /* bsr 0x060140C4 (external) */  ! call dyn_obj_physics
    nop
    .byte   0xB4, 0xE1    /* bsr 0x0601444C (external) */  ! call race_variant_setup_b
    nop
    mov.l   .L_pool_mode_word, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_mode_not_attract
    .byte   0xB4, 0xE7    /* bsr 0x06014466 (external) */  ! call race_variant_setup_c (attract path)
    nop
    bra     .L_after_mode_branch
    nop
.L_mode_not_attract:
    .byte   0xB5, 0x36    /* bsr 0x0601450C (external) */  ! call camera_track_update (non-attract path)
    nop
.L_after_mode_branch:
    .byte   0xB5, 0x8C    /* bsr 0x060145BC (external) */  ! call adv_collision_resp
    nop
    mov.l   .L_pool_btn_state, r2
    mov.w @r2, r3
    mov.w   .L_wpool_btn_mask, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_skip_wall_call
    .byte   0xB6, 0x0E    /* bsr 0x060146D2 (external) */  ! call track_wall_collision (button pressed)
    nop
.L_skip_wall_call:
    mov #0x4, r3
    mov.l   .L_pool_active_car_count, r2
    mov.l @r2, r2
    cmp/hs r3, r2
    bt      .L_tail_wall_call
    mov.l   .L_pool_countdown, r3
    mov.l   .L_pool_countdown, r2
    mov.w @r3, r3
    add #-0x1, r3
    mov.w r3, @r2
    exts.w r3, r3
    cmp/pl r3
    bt      .L_return_normal
.L_tail_wall_call:
    .byte   0xA5, 0xFF    /* bra 0x060146D2 (external) */  ! tail-call track_wall_collision (counter expired)
    lds.l @r15+, pr
.L_return_normal:
    lds.l @r15+, pr
    rts
    nop

    .global loc_06013ADA
loc_06013ADA:
    mov #0x5, r3
    mov.l   .L_pool_mode_byte_ptr, r2
    mov.b r3, @r2
    mov #0x0, r3
    mov.l   .L_pool_wait_counter_ptr, r2
    mov.w r3, @r2
    .byte   0xA0, 0x0D    /* bra 0x06013B04 (external) */  ! tail-call ranking_pts_calc
    nop
.L_wpool_btn_mask:
    .2byte  0x0800                        /* button mask: bit 11 (Start / action button) */
.L_pool_mode_word:
    .4byte  sym_06063D9E                  /* game mode word (0x10 = attract/demo mode) */
.L_pool_btn_state:
    .4byte  sym_06063D9A                  /* new button presses (edge-triggered, per-frame) */
.L_pool_active_car_count:
    .4byte  sym_06084B18                  /* active car count in race (32-bit) */
.L_pool_countdown:
    .4byte  sym_06084AF0                  /* post-race countdown timer (16-bit, counts down to 0) */
.L_pool_mode_byte_ptr:
    .4byte  sym_06084AF2                  /* post-race mode byte (set to 0x05 at loc_06013ADA) */
.L_pool_wait_counter_ptr:
    .4byte  sym_06084AF6                  /* post-race wait counter (reset to 0 at loc_06013ADA) */
