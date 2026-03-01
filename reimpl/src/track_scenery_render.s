
    .section .text.FUN_0602FDB0


    .global track_scenery_render
    .type track_scenery_render, @function
track_scenery_render:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r9
    mov r0, r6
    mov #0x1, r5
    mov #0x0, r7
    mov.l   .L_scenery_obj_ptr, r0
    mov.l @r0, r0
    mov.l   .L_replay_mode_flag, r1
    mov.w @r1, r2
    tst r2, r2
    bt      .L_live_mode
    bra     .L_replay_mode
    nop
.L_scenery_obj_ptr:
    .4byte  sym_0607E944
.L_replay_mode_flag:
    .4byte  sym_0607ED8C
.L_live_mode:
    mov.l   .L_input_state_a, r2
    mov.w @r2, r1
    extu.w r1, r1
    mov.l   .L_btn_mask_zoom_in, r2
    mov.w @r2, r2
    cmp/pl r2
    mov.w   .L_off_detail_level, r3
    bf      .L_check_btn_detail_3
    tst r1, r2
    bt      .L_check_zoom_out
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_store_detail_level
    add #-0x1, r4
.L_store_detail_level:
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
.L_off_detail_level:
    .2byte  0x00DE
    .2byte  0x0000
.L_input_state_a:
    .4byte  sym_06063D9A
.L_btn_mask_zoom_in:
    .4byte  sym_0608188A
.L_check_zoom_out:
    mov.l   .L_btn_mask_zoom_out, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_detail_done
    mov.w @(r0, r3), r4
    mov #0x3, r2
    cmp/eq r4, r2
    bt      .L_zoom_out_clamped
    add #0x1, r4
.L_zoom_out_clamped:
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_zoom_out:
    .4byte  sym_06081888
.L_check_btn_detail_3:
    mov.l   .L_btn_mask_detail_3, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_btn_detail_2
    mov #0x3, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_3:
    .4byte  sym_06081896
.L_check_btn_detail_2:
    mov.l   .L_btn_mask_detail_2, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_btn_detail_1
    mov #0x2, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_2:
    .4byte  sym_06081894
.L_check_btn_detail_1:
    mov.l   .L_btn_mask_detail_1, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_btn_detail_0
    mov #0x1, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_1:
    .4byte  sym_06081892
.L_check_btn_detail_0:
    mov.l   .L_btn_mask_detail_0, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_detail_done
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_detail_done:
    mov.w @(r0, r3), r4
    mov r4, r9
    mov.l   .L_input_state_b, r3
    mov.w @r3, r1
    extu.w r1, r1
    mov #0x1, r5
    mov.l   .L_btn_mask_near_scroll, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_no_near_scroll
    mov #-0x80, r8
    extu.b r8, r8
    or r8, r9
    mov.w   .L_off_near_active, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.l @(r0, r2), r4
    mov.w   .L_near_scroll_max, r8
    cmp/gt r8, r4
    bt      .L_near_scroll_store
    add #0xA, r4
    mov.w   .L_near_scroll_limit, r3
    cmp/gt r4, r3
    bt      .L_near_scroll_store
    mov r8, r4
.L_near_scroll_store:
    bra     .L_check_far_scroll
    mov.l r4, @(r0, r2)
.L_off_near_active:
    .2byte  0x006C
.L_near_scroll_max:
    .2byte  0x00B8
.L_near_scroll_limit:
    .2byte  0x00A0
.L_btn_mask_detail_0:
    .4byte  sym_06081890
.L_input_state_b:
    .4byte  g_pad_state
.L_btn_mask_near_scroll:
    .4byte  sym_0608188C
.L_no_near_scroll:
    mov.w   .L_off_near_pos, r3
    mov #-0x50, r2
    mov.l @(r0, r3), r4
    extu.b r2, r2
    mov r4, r6
    cmp/gt r4, r2
    bt      .L_near_decay_fast
    bra     .L_near_decay_store
    add #-0x1, r4
.L_off_near_pos:
    .2byte  0x0074
.L_near_decay_fast:
    shlr2 r6
    shlr2 r6
    sub r6, r4
    mov #0x6F, r6
    cmp/ge r6, r4
    bt      .L_near_decay_store
    mov #0x38, r4
.L_near_decay_store:
    mov.l r4, @(r0, r3)
    mov.l   .L_off_near_scroll_active, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_check_far_scroll:
    mov.l   .L_btn_mask_far_scroll, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_no_far_scroll
    mov #0x40, r8
    or r8, r9
    mov.w   .L_off_far_scroll_active, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_far_scroll_pos, r3
    mov.l @(r0, r3), r4
    mov.w   .L_off_far_scroll_prev, r6
    mov.l r4, @(r0, r6)
    mov.l   .L_far_scroll_max, r8
    cmp/gt r8, r4
    bt      .L_far_scroll_store
    add #0x28, r4
.L_far_scroll_store:
    bra     .L_check_anim_flag
    mov.l r4, @(r0, r3)
.L_off_far_scroll_active:
    .2byte  0x0088
.L_off_far_scroll_pos:
    .2byte  0x0090
.L_off_far_scroll_prev:
    .2byte  0x008C
.L_off_near_scroll_active:
    .4byte  0x0000006C
.L_btn_mask_far_scroll:
    .4byte  sym_0608188E
.L_far_scroll_max:
    .4byte  0x000000B8
.L_no_far_scroll:
    mov.l   .L_off_far_pos, r3
    mov.l @(r0, r3), r4
    mov.l   .L_off_far_prev, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    mov r4, r2
    shlr r2
    sub r2, r4
    cmp/ge r3, r4
    bt      .L_far_decay_clamped
    mov r3, r4
.L_far_decay_clamped:
    mov.l   .L_off_far_pos, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_off_far_active, r3
    mov.l r7, @(r0, r3)
.L_check_anim_flag:
    mov #0x0, r10
    mov.w   .L_off_anim_flag, r4
    mov.w @(r0, r4), r3
    tst r3, r3
    bt      .L_no_anim_active
    bra     .L_anim_active
    mov #0x1, r10
.L_off_anim_flag:
    .2byte  0x009E
    .2byte  0x0000
.L_off_far_pos:
    .4byte  0x00000090
.L_off_far_prev:
    .4byte  0x0000008C
.L_off_far_active:
    .4byte  0x00000088
.L_no_anim_active:
    mov.l   .L_btn_mask_left_anim, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_right_anim
    mov #0x20, r8
    or r8, r9
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_off_anim_dir_l_a, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_off_anim_dir_l_b, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_anim_pos_left, r3
    mov.l @(r0, r3), r8
    mov.w   .L_off_anim_delta_left, r6
    mov.l @(r0, r6), r4
    cmp/pl r8
    bf      .L_left_anim_interp
    mov #-0x32, r7
    shar r8
    cmp/gt r8, r7
    bt      .L_left_anim_store
    mov #0x0, r8
.L_left_anim_interp:
    mov #-0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_scene_interp, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_left_anim_store:
    bra     .L_write_ringbuf
    mov.l r8, @(r0, r3)
.L_off_anim_dir_l_a:
    .2byte  0x00A4
.L_off_anim_dir_l_b:
    .2byte  0x00A0
.L_off_anim_pos_left:
    .2byte  0x00AC
.L_off_anim_delta_left:
    .2byte  0x00A8
    .2byte  0x0000
.L_btn_mask_left_anim:
    .4byte  sym_06063F48
.L_fn_scene_interp:
    .4byte  sym_0602ECCC
.L_check_right_anim:
    mov.l   .L_btn_mask_right_anim, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r1, r2
    bt      .L_no_anim_pressed
    mov #0x10, r8
    or r8, r9
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_off_anim_dir_r_a, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_off_anim_dir_r_b, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_anim_pos_right, r3
    mov.l @(r0, r3), r8
    mov.w   .L_off_anim_delta_right, r6
    mov.l @(r0, r6), r4
    cmp/pz r8
    bt      .L_right_anim_interp
    mov #0x32, r7
    shar r8
    cmp/gt r7, r8
    bt      .L_right_anim_store
    mov #0x0, r8
.L_right_anim_interp:
    mov #0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_scene_interp_b, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_right_anim_store:
    bra     .L_write_ringbuf
    mov.l r8, @(r0, r3)
.L_off_anim_dir_r_a:
    .2byte  0x00A0
.L_off_anim_dir_r_b:
    .2byte  0x00A4
.L_off_anim_pos_right:
    .2byte  0x00AC
.L_off_anim_delta_right:
    .2byte  0x00A8
.L_btn_mask_right_anim:
    .4byte  sym_06063F4A
.L_fn_scene_interp_b:
    .4byte  sym_0602ECCC
.L_no_anim_pressed:
    mov.w   .L_off_idle_delta, r6
    mov #0x0, r4
    mov.l r4, @(r0, r6)
    mov.w   .L_off_idle_pos, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_write_ringbuf
    cmp/pl r4
    bt/s    .L_idle_decay_positive
    mov r4, r6
    mov #-0x68, r8
    mov #-0x7, r7
    cmp/ge r8, r6
    bt      .L_idle_neg_clamped
.L_idle_neg_clamped:
    sub r6, r4
    bra     .L_idle_store_pos
    nop
.L_off_idle_delta:
    .2byte  0x00A8
.L_off_idle_pos:
    .2byte  0x00AC
.L_idle_decay_positive:
    mov #0x68, r8
    mov #0x7, r7
    cmp/ge r6, r8
    bt      .L_idle_pos_clamped
.L_idle_pos_clamped:
    sub r6, r4
.L_idle_store_pos:
    mov.l r4, @(r0, r3)
    mov.w   .L_off_idle_dir_a, r3
    mov #0x0, r7
    mov.l r7, @(r0, r3)
    mov.w   .L_off_idle_dir_b, r3
    mov.l r7, @(r0, r3)
    bra     .L_write_ringbuf
    nop
.L_off_idle_dir_a:
    .2byte  0x00A0
.L_off_idle_dir_b:
    .2byte  0x00A4
.L_anim_active:
    mov.l   .L_input_state_c, r3
    mov.w @r3, r1
    mov.l   .L_dir_flip_flag, r7
    mov.b @r7, r7
    tst r7, r7
    bf      .L_anim_no_flip
    not r1, r1
.L_anim_no_flip:
    extu.b r1, r1
    mov r1, r7
    mov #-0x80, r5
    add r5, r1
    mov.w   .L_off_anim_pos_out, r3
    mov.l @(r0, r3), r4
    mov.l r1, @(r0, r3)
.L_write_ringbuf:
    mov.l   .L_ringbuf_base, r2
    mov.l   .L_ringbuf_index, r4
    mov.l @r4, r6
    add r6, r2
    add #0x1, r6
    mov.b r9, @r2
    tst r10, r10
    add #0x1, r2
    add #0x1, r6
    bt      .L_skip_anim_byte
    mov.b r7, @r2
.L_skip_anim_byte:
    mov.w   .L_ringbuf_size, r3
    cmp/ge r6, r3
    bt      .L_ringbuf_wrap_done
    add #-0x2, r6
.L_ringbuf_wrap_done:
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_off_anim_pos_out:
    .2byte  0x00AC
.L_ringbuf_size:
    .2byte  0x2AF6
    .2byte  0x0000
.L_input_state_c:
    .4byte  sym_06063D9C
.L_dir_flip_flag:
    .4byte  sym_06078663
.L_ringbuf_base:
    .4byte  sym_0607ED90
.L_ringbuf_index:
    .4byte  sym_0607ED88
.L_replay_mode:
    mov.l   .L_ringbuf_base_r, r2
    mov.l   .L_ringbuf_index_r, r4
    mov.l @r4, r6
    add r6, r2
    add #0x1, r6
    mov.b @r2, r1
    mov.w   .L_off_detail_level_r, r3
    extu.b r1, r1
    mov r1, r5
    mov #0x3, r2
    and r2, r5
    mov.w r5, @(r0, r3)
    mov.l r6, @r4
    mov #0x1, r5
    mov #-0x80, r2
    extu.b r2, r2
    tst r1, r2
    bt      .L_replay_no_near
    mov.w   .L_off_near_active_wr, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.l @(r0, r2), r4
    mov.w   .L_near_scroll_max_r, r8
    cmp/gt r8, r4
    bt      .L_replay_near_store
    add #0xA, r4
    mov.w   .L_near_scroll_limit_r, r3
    cmp/gt r4, r3
    bt      .L_replay_near_store
    mov r8, r4
.L_replay_near_store:
    bra     .L_replay_check_far
    mov.l r4, @(r0, r2)
.L_off_detail_level_r:
    .2byte  0x00DE
.L_off_near_active_wr:
    .2byte  0x006C
.L_near_scroll_max_r:
    .2byte  0x00B8
.L_near_scroll_limit_r:
    .2byte  0x00A0
.L_ringbuf_base_r:
    .4byte  sym_0607ED90
.L_ringbuf_index_r:
    .4byte  sym_0607ED88
.L_replay_no_near:
    mov.w   .L_off_near_pos_r, r3
    mov #-0x50, r2
    mov.l @(r0, r3), r4
    extu.b r2, r2
    mov r4, r6
    cmp/gt r4, r2
    bt      .L_replay_near_decay_fast
    bra     .L_replay_near_decay_store
    add #-0x1, r4
.L_off_near_pos_r:
    .2byte  0x0074
.L_replay_near_decay_fast:
    shlr2 r6
    shlr2 r6
    sub r6, r4
    mov #0x6F, r6
    cmp/ge r6, r4
    bt      .L_replay_near_decay_store
    mov #0x38, r4
.L_replay_near_decay_store:
    mov.l r4, @(r0, r3)
    mov.l   .L_off_near_active_r, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_replay_check_far:
    mov #0x40, r2
    tst r1, r2
    bt      .L_replay_no_far
    mov.w   .L_off_far_active_wr, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_far_pos_wr, r3
    mov.l @(r0, r3), r4
    mov.w   .L_off_far_prev_wr, r6
    mov.l r4, @(r0, r6)
    mov.l   .L_far_scroll_max_r, r8
    cmp/gt r8, r4
    bt      .L_replay_far_store
    add #0x28, r4
.L_replay_far_store:
    bra     .L_replay_check_anim
    mov.l r4, @(r0, r3)
.L_off_far_active_wr:
    .2byte  0x0088
.L_off_far_pos_wr:
    .2byte  0x0090
.L_off_far_prev_wr:
    .2byte  0x008C
    .2byte  0x0000
.L_off_near_active_r:
    .4byte  0x0000006C
.L_far_scroll_max_r:
    .4byte  0x000000B8
.L_replay_no_far:
    mov.l   .L_off_far_pos_r, r3
    mov.l @(r0, r3), r4
    mov.l   .L_off_far_prev_r, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    mov r4, r2
    shlr r2
    sub r2, r4
    cmp/ge r3, r4
    bt      .L_replay_far_decay_clamped
    mov r3, r4
.L_replay_far_decay_clamped:
    mov.l   .L_off_far_pos_r, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_off_far_active_r, r3
    mov.l r7, @(r0, r3)
.L_replay_check_anim:
    mov #0x0, r10
    mov.l   .L_ringbuf_anim_check, r4
    mov.b @r4, r3
    tst r3, r3
    bt      .L_replay_no_anim
    bra     .L_replay_anim_active
    mov #0x1, r10
.L_off_far_pos_r:
    .4byte  0x00000090
.L_off_far_prev_r:
    .4byte  0x0000008C
.L_off_far_active_r:
    .4byte  0x00000088
.L_ringbuf_anim_check:
    .4byte  sym_0607ED90
.L_replay_no_anim:
    mov #0x20, r2
    tst r1, r2
    bt      .L_replay_check_right
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_off_anim_dir_la_r, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_off_anim_dir_lb_r, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_anim_pos_l_r, r3
    mov.l @(r0, r3), r8
    mov.w   .L_off_anim_delta_l_r, r6
    mov.l @(r0, r6), r4
    cmp/pl r8
    bf      .L_replay_left_interp
    mov #-0x32, r7
    shar r8
    cmp/gt r8, r7
    bt      .L_replay_left_store
    mov #0x0, r8
.L_replay_left_interp:
    mov #-0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_interp_left_r, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_replay_left_store:
    bra     .L_replay_epilogue
    mov.l r8, @(r0, r3)
.L_off_anim_dir_la_r:
    .2byte  0x00A4
.L_off_anim_dir_lb_r:
    .2byte  0x00A0
.L_off_anim_pos_l_r:
    .2byte  0x00AC
.L_off_anim_delta_l_r:
    .2byte  0x00A8
.L_fn_interp_left_r:
    .4byte  sym_0602ECCC
.L_replay_check_right:
    mov #0x10, r2
    tst r1, r2
    bt      .L_replay_no_anim_btn
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_off_anim_dir_ra_r, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_off_anim_dir_rb_r, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_off_anim_pos_r_r, r3
    mov.l @(r0, r3), r8
    mov.w   .L_off_anim_delta_r_r, r6
    mov.l @(r0, r6), r4
    cmp/pz r8
    bt      .L_replay_right_interp
    mov #0x32, r7
    shar r8
    cmp/gt r7, r8
    bt      .L_replay_right_store
    mov #0x0, r8
.L_replay_right_interp:
    mov #0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_interp_right_r, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_replay_right_store:
    bra     .L_replay_epilogue
    mov.l r8, @(r0, r3)
.L_off_anim_dir_ra_r:
    .2byte  0x00A0
.L_off_anim_dir_rb_r:
    .2byte  0x00A4
.L_off_anim_pos_r_r:
    .2byte  0x00AC
.L_off_anim_delta_r_r:
    .2byte  0x00A8
.L_fn_interp_right_r:
    .4byte  sym_0602ECCC
.L_replay_no_anim_btn:
    mov.w   .L_off_idle_delta_r, r6
    mov #0x0, r4
    mov.l r4, @(r0, r6)
    mov.w   .L_off_idle_pos_r, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_replay_epilogue
    cmp/pl r4
    bt/s    .L_replay_idle_pos
    mov r4, r6
    mov #-0x68, r8
    mov #-0x7, r7
    cmp/ge r8, r6
    bt      .L_replay_idle_neg_clamp
.L_replay_idle_neg_clamp:
    sub r6, r4
    bra     .L_replay_idle_store
    nop
.L_off_idle_delta_r:
    .2byte  0x00A8
.L_off_idle_pos_r:
    .2byte  0x00AC
.L_replay_idle_pos:
    mov #0x68, r8
    mov #0x7, r7
    cmp/ge r6, r8
    bt      .L_replay_idle_pos_clamp
.L_replay_idle_pos_clamp:
    sub r6, r4
.L_replay_idle_store:
    mov.l r4, @(r0, r3)
    mov.w   .L_off_idle_dir_a_r, r3
    mov #0x0, r7
    mov.l r7, @(r0, r3)
    mov.w   .L_off_idle_dir_b_r, r3
    mov.l r7, @(r0, r3)
    bra     .L_replay_epilogue
    nop
.L_off_idle_dir_a_r:
    .2byte  0x00A0
.L_off_idle_dir_b_r:
    .2byte  0x00A4
.L_replay_anim_active:
    mov.l   .L_ringbuf_base_anim, r2
    mov.l   .L_ringbuf_index_anim, r4
    mov.l @r4, r6
    add r6, r2
    mov.b @r2, r1
    mov #-0x80, r5
    extu.b r1, r1
    add r5, r1
    mov.w   .L_off_anim_pos_out_r, r3
    mov.l @(r0, r3), r4
    mov.l r1, @(r0, r3)
.L_replay_epilogue:
    mov.l   .L_ringbuf_index_anim, r4
    mov.l @r4, r6
    add #0x1, r6
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_off_anim_pos_out_r:
    .2byte  0x00AC
    .2byte  0x0000
.L_ringbuf_base_anim:
    .4byte  sym_0607ED90
.L_ringbuf_index_anim:
    .4byte  sym_0607ED88
    .4byte  0x00090009
    .4byte  0x401589FB
    .2byte  0x0009

    .global sym_060302C6
sym_060302C6:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
