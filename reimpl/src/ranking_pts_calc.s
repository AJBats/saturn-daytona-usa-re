
    .section .text.FUN_06013B04


    .global ranking_pts_calc
    .type ranking_pts_calc, @function
ranking_pts_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   _pool_fn_sound_cmd, r11
    mov.l   _pool_car_count_ptr, r12
    mov.l   _pool_frame_timer_ptr, r14
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    .byte   0xB1, 0x8F    /* bsr obj_render_loop_3d */
    nop
    .byte   0xB3, 0x25    /* bsr race_variant_setup_a */
    nop
    mov.w @r14, r4
    extu.w r4, r4
    add #-0x1F, r4
    cmp/pz r4
    bt      .L_timer_ready
    mov #0x0, r4
.L_timer_ready:
    mov r4, r3
    mov #0x4, r2
    shlr2 r3
    shlr2 r3
    shlr r3
    cmp/hs r2, r3
    bt      .L_epilogue
    mov #0x1F, r0
    and r4, r0
    cmp/eq #0x1F, r0
    bf      .L_epilogue
    mov r4, r0
    shlr2 r0
    shlr2 r0
    shlr r0
    cmp/eq #0x3, r0
    bf      .L_section_0_2
    mov.l   _pool_final_reveal_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_section_0_2
    mov.l   _pool_fn_handler_init_reset, r3
    jsr @r3
    nop
    mov.l   _pool_sound_base_id, r13
    mov #0x25, r3
    mov.l @r12, r2
    cmp/hs r3, r2
    bt      .L_check_68_cars
    mov.l   _pool_fn_race_variant_b, r3
    jsr @r3
    nop
    bra     .L_lookup_score
    mov r13, r14
.L_check_68_cars:
    mov.l @r12, r2
    mov #0x44, r3
    cmp/hs r3, r2
    bt      .L_variant_d
    mov.l   _pool_fn_race_variant_c, r3
    jsr @r3
    nop
    bra     .L_set_sound_base
    nop
.L_variant_d:
    mov.l   _pool_fn_race_variant_d, r3
    jsr @r3
    nop
.L_set_sound_base:
    mov r13, r14
.L_lookup_score:
    mov.l @r12, r5
    mov.l   _pool_position_score_tbl, r3
    add #-0x1, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll8 r5
    add r14, r5
    jsr @r11
    mov #0x0, r4
    bra     .L_epilogue
    nop
    .2byte  0xFFFF
_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch
_pool_car_count_ptr:
    .4byte  sym_06084FB4
_pool_frame_timer_ptr:
    .4byte  sym_06084AF6
_pool_final_reveal_flag:
    .4byte  sym_06084FB8
_pool_fn_handler_init_reset:
    .4byte  handler_init_reset
_pool_sound_base_id:
    .4byte  0xAE1000FF
_pool_fn_race_variant_b:
    .4byte  race_variant_b
_pool_fn_race_variant_c:
    .4byte  race_variant_c
_pool_fn_race_variant_d:
    .4byte  race_variant_d
_pool_position_score_tbl:
    .4byte  sym_0605B294
.L_section_0_2:
    mov r4, r2
    mov #0x3, r3
    shlr2 r2
    shlr2 r2
    shlr r2
    cmp/hs r3, r2
    bt      .L_epilogue
    shlr2 r4
    .byte   0xDE, 0x18    /* mov.l _pool_variant_char_tbl, r14 */
    shlr2 r4
    shlr r4
    add r4, r14
    mov.b @r14, r14
    extu.b r14, r14
    add #-0x41, r14
    cmp/pz r14
    bf      .L_default_sound
    mov r14, r5
    shll2 r5
    .byte   0xD3, 0x14    /* mov.l _pool_score_tbl, r3 */
    add r3, r5
    bra     .L_play_sound
    mov.l @r5, r5
.L_default_sound:
    .byte   0xD5, 0x13    /* mov.l _pool_default_sound_id, r5 */
.L_play_sound:
    jsr @r11
    mov #0x0, r4
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_06013C10
loc_06013C10:
    mov #0x7, r3
    .byte   0xD2, 0x0F    /* mov.l _pool_phase_byte, r2 */
    mov.b r3, @r2
    mov #0x0, r3
    .byte   0xD2, 0x0E    /* mov.l _pool_frame_timer, r2 */
    mov.w r3, @r2
    .byte   0xA0, 0x00    /* bra bonus_multiplier (falls through) */
    nop
