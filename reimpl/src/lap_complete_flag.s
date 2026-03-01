
    .section .text.FUN_0600D9BC


    .global lap_complete_flag
    .type lap_complete_flag, @function
lap_complete_flag:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_completion_bitmask, r14
    mov.l   .L_pool_car_struct_ptr, r5
    tst r4, r4
    bf/s    .L_phase2_bitmask
    mov.l @r5, r5
    mov.l   .L_pool_section_id_snapshot, r3
    mov.l   .L_pool_completion_bitmask, r2
    mov.l @r3, r3
    mov.l @r2, r2
    cmp/eq r2, r3
    bf      .L_phase2_bitmask
    mov.w   .L_wpool_crossing_ctr_off, r0
    mov.l   .L_pool_crossing_snapshot, r3
    mov.l @(r0, r5), r2
    mov.l @r3, r3
    cmp/eq r3, r2
    bt      .L_phase2_bitmask
    mov.w   .L_wpool_crossing_ctr_off, r0
    mov.l   .L_pool_crossing_snapshot, r2
    mov.l @(r0, r5), r3
    add #-0xC, r0
    mov.l r3, @r2
    mov.l   .L_pool_lap_counter, r6
    mov.l @r6, r3
    add #0x1, r3
    mov.l r3, @r6
    mov.l r3, @(r0, r5)
    mov.l @r6, r3
    mov.l   .L_pool_max_laps, r2
    mov.l @r2, r2
    cmp/hs r2, r3
    bt      .L_phase2_bitmask
    mov #0x0, r2
    mov.l r2, @r14
.L_phase2_bitmask:
    mov #0x1, r7
    mov.l   .L_pool_fn_shift_left, r3
    mov r7, r0
    jsr @r3
    mov r4, r1
    mov r0, r6
    mov.l @r14, r2
    and r6, r2
    tst r2, r2
    bf      .L_exit
    mov r7, r0
    mov.l @r14, r3
    or r6, r3
    mov.l r3, @r14
    mov.w   .L_wpool_hud_flag_param, r1
    mov.l   .L_pool_fn_bitfield_insert, r3
    jsr @r3
    mov r5, r2
    mov.w   .L_wpool_lap_done_count_off, r0
    mov.l @(r0, r5), r2
    add #0x1, r2
    mov.l r2, @(r0, r5)
    mov.l   .L_pool_race_end_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_exit
    tst r4, r4
    bt      .L_exit
    mov r5, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_exit
    lds.l @r15+, pr
    .byte   0xA1, 0x9F    /* bra 0x0600DD88 (external) — tail-call audio_dist_calc */
    mov.l @r15+, r14
.L_exit:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_crossing_ctr_off:
    .2byte  0x0228
.L_wpool_hud_flag_param:
    .2byte  0x1501
.L_wpool_lap_done_count_off:
    .2byte  0x0230
    .2byte  0xFFFF
.L_pool_completion_bitmask:
    .4byte  sym_06063F1C
.L_pool_car_struct_ptr:
    .4byte  sym_0607E940
.L_pool_section_id_snapshot:
    .4byte  sym_06063F18
.L_pool_crossing_snapshot:
    .4byte  sym_06063F20
.L_pool_lap_counter:
    .4byte  sym_06063F24
.L_pool_max_laps:
    .4byte  sym_06063F28
.L_pool_fn_shift_left:
    .4byte  sym_06035280
.L_pool_fn_bitfield_insert:
    .4byte  sym_06034F78
.L_pool_race_end_flag:
    .4byte  sym_0607EAD8
