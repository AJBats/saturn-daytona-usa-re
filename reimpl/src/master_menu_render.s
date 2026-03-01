
    .section .text.FUN_0603950C


    .global scene_state_process
    .type scene_state_process, @function
scene_state_process:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x10, r15
    mov.l   .L_elem_count_ptr, r8
    mov.l   .L_display_list_base, r9
    mov.l   .L_smpc_port_config, r10
    mov.l   .L_display_list_alt, r11
    mov #0x0, r12
    mov.l   .L_display_count, r13
    mov.l   .L_scene_param_ptr, r14
    mov r4, r0
    mov.b r0, @(12, r15)
    mov r5, r0
    mov.w r0, @(8, r15)
    mov.b r6, @r15
    mov r7, r0
    mov.b r0, @(4, r15)
    mov.l   .L_smpc_ddr1, r2
    mov.b r12, @r2
    add #0x2, r2
    mov.b r12, @r2
    add #0x4, r2
    mov.b r12, @r2
    extu.b r12, r3
    add #-0x2, r2
    mov.b r3, @r2
    mov.l   .L_fn_dispatch_ptr, r3
    mov.l   .L_fn_menu_render, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x47, r4
    mov.l   .L_fn_dispatch_ptr_2, r2
    mov.w   .L_mask_ff7f, r4
    mov.l @r2, r2
    jsr @r2
    mov r12, r5
    mov.l   .L_scene_state_byte, r6
    mov.b @(12, r15), r0
    mov r0, r3
    mov.b r3, @r6
    mov #0x8, r5
    mov #0x1, r4
    mov.b @r6, r0
    bra     .L_scene_state_dispatch
    extu.b r0, r0
.L_scene_case_0:
    extu.b r4, r4
    mov.b r4, @r10
    extu.b r12, r0
    mov.b r0, @(1, r10)
    mov.l   .L_smpc_done_flag, r2
    mov.b r12, @r2
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_smpc_send, r2
    jmp @r2
    mov.l @r15+, r14
.L_scene_case_1:
    mov.b r12, @r10
    extu.b r5, r5
    mov r5, r0
    bra     .L_store_params
    mov.b r0, @(1, r10)
.L_scene_case_2:
    extu.b r4, r4
    mov.b r4, @r10
    extu.b r5, r5
    mov r5, r0
    mov.b r0, @(1, r10)
    extu.b r12, r3
    mov.l   .L_state_clear_flag, r2
    mov.b r3, @r2
    bra     .L_store_params
    nop
.L_mask_ff7f:
    .2byte  0xFF7F
.L_elem_count_ptr:
    .4byte  sym_060A4CAE
.L_display_list_base:
    .4byte  sym_060A4CBC
.L_smpc_port_config:
    .4byte  sym_06063602
.L_display_list_alt:
    .4byte  sym_060A4CC0
.L_display_count:
    .4byte  sym_060A4CAC
.L_scene_param_ptr:
    .4byte  sym_060A4CB0
.L_smpc_ddr1:
    .4byte  0x20100079                  /* SMPC DDR1 — port direction 1 */
.L_fn_dispatch_ptr:
    .4byte  sym_06000300
.L_fn_menu_render:
    .4byte  master_menu_render
.L_fn_dispatch_ptr_2:
    .4byte  sym_06000344
.L_scene_state_byte:
    .4byte  sym_060A4CAA
.L_smpc_done_flag:
    .4byte  sym_060A4CA8
.L_fn_smpc_send:
    .4byte  smpc_intback_send
.L_state_clear_flag:
    .4byte  sym_060A4CD8
.L_scene_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_scene_case_0
    cmp/eq #0x1, r0
    bt      .L_scene_case_1
    cmp/eq #0x2, r0
    bt      .L_scene_case_2
.L_store_params:
    mov.b @(4, r15), r0
    mov r0, r3
    mov.b r3, @r8
    mov.w @(8, r15), r0
    mov r0, r3
    mov #0x3B, r0
    mov.w r3, @r13
    mov.b @(r0, r15), r3
    mov.l   .L_frame_count_byte, r2
    mov.b r3, @r2
    mov.b @r15, r3
    mov.l   .L_display_mode_byte, r2
    mov.b r3, @r2
    mov.l @(52, r15), r3
    mov.l r3, @r14
    mov.l   .L_frame_counter, r3
    mov.l r12, @r3
    mov #0xF, r3
    mov.b @r8, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bt      .L_set_overflow_bits
    bra     .L_setup_display_ptrs
    nop
.L_set_overflow_bits:
    mov.b @(1, r10), r0
    or #0x50, r0
    mov.b r0, @(1, r10)
.L_setup_display_ptrs:
    mov.l   .L_display_str_start, r4
    mov.l   .L_str_start_store, r3
    mov.l r4, @r3
    add #0x7, r4
    mov.l   .L_str_end_store, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l r2, @r9
    mov.l   .L_anim_data_ptr, r4
    mov.l   .L_display_mode_byte, r0
    mov.b @r0, r0
    bra     .L_mode_dispatch
    extu.b r0, r0
.L_stride_mode_ff:
    mov.b @r8, r5
    mov.w @r13, r3
    mov.l @r14, r2
    extu.b r5, r5
    extu.w r3, r3
    add #0x1, r5
    mul.l r3, r5
    sts macl, r5
    add r5, r2
    mov.l r2, @r11
    shll r5
    mov.l @r14, r3
    add r3, r5
    bra     .L_stride_done
    mov.l r5, @r4
.L_stride_mode_00:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_stride_mode_10:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_stride_mode_20:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_frame_count_byte:
    .4byte  sym_060A4CAB
.L_display_mode_byte:
    .4byte  sym_060A4CAF
.L_frame_counter:
    .4byte  sym_060A4CB8
.L_display_str_start:
    .4byte  sym_060A4CD9
.L_str_start_store:
    .4byte  sym_060A4CE8
.L_str_end_store:
    .4byte  sym_060A4C98
.L_anim_data_ptr:
    .4byte  sym_060A4CC8
.L_stride_mode_30:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_stride_mode_e1:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_stride_mode_e2:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_stride_done
    nop
.L_mode_dispatch:
    cmp/eq #0x0, r0
    bf      .L_check_mode_10
    bra     .L_stride_mode_00
    nop
.L_check_mode_10:
    cmp/eq #0x10, r0
    bf      .L_check_mode_20_plus
    bra     .L_stride_mode_10
    nop
.L_check_mode_20_plus:
    cmp/eq #0x20, r0
    bt      .L_stride_mode_20
    cmp/eq #0x30, r0
    bt      .L_stride_mode_30
    mov.w   DAT_060397f4, r1
    cmp/eq r1, r0
    bt      .L_stride_mode_e1
    mov.w   DAT_060397f6, r1
    cmp/eq r1, r0
    bt      .L_stride_mode_e2
    mov.w   DAT_060397f8, r1
    cmp/eq r1, r0
    bf      .L_stride_done
    bra     .L_stride_mode_ff
    nop
.L_stride_done:
    mov.l   .L_display_counter, r3
    mov.l r12, @r3
    mov.l   .L_fn_display_channel_iter, r3
    jsr @r3
    nop
    mov.l   .L_display_alt_ptr, r4
    mov.l @r11, r2
    mov.l r2, @r4
    mov.l @r9, r3
    mov.l r3, @r11
    mov.l @r4, r2
    mov.l r2, @r9
    mov.l   .L_display_counter, r3
    mov.l r12, @r3
    mov.l   .L_fn_display_channel_iter, r3
    jsr @r3
    nop
    bsr     .L_reset_all_state
    nop
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     smpc_intback_send
    mov.l @r15+, r14

    .global DAT_060397f4
DAT_060397f4:
    .2byte  0x00E1

    .global DAT_060397f6
DAT_060397f6:
    .2byte  0x00E2

    .global DAT_060397f8
DAT_060397f8:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_display_counter:
    .4byte  sym_060A4CB4
.L_fn_display_channel_iter:
    .4byte  display_channel_iter
.L_display_alt_ptr:
    .4byte  sym_060A4CC4

    .global smpc_data_manage
    .type smpc_data_manage, @function
smpc_data_manage:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_scene_state, r4
    mov.b @r4, r4
    extu.b r4, r4
    mov r4, r0
    cmp/eq #0x1, r0
    bt/s    .L_state_active
    mov #0x0, r13
    mov r4, r0
    cmp/eq #0x2, r0
    bt      .L_state_active
    mov.l @r15, r3
    mov.l r13, @r3
    bra     .L_return_early
    mov #0x1, r0
.L_state_active:
    mov #0x10, r6
    mov.l   .L_input_toggle_flag, r5
    mov.l   .L_input_counter, r4
    mov.l   .L_smpc_sr, r3
    mov.b @r3, r3
    extu.b r3, r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_input_not_pressed
    mov.l @r4, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r4
    mov #0x3, r3
    cmp/ge r3, r2
    bf      .L_check_frame_count
    mov #0x1, r3
    mov.b r3, @r5
    mov.l @r4, r2
    add #-0x1, r2
    bra     .L_check_frame_count
    mov.l r2, @r4
.L_input_not_pressed:
    extu.b r13, r2
    mov.b r2, @r5
    mov.l r13, @r4
.L_check_frame_count:
    mov.l   .L_frame_counter_2, r4
    mov.l   .L_frame_count_byte_2, r3
    mov.l @r4, r2
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r3, r2
    bt      .L_frame_limit_reached
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    bra     .L_return_early
    mov #0x0, r0
.L_frame_limit_reached:
    mov.l r13, @r4
    mov.l   .L_iter_count_byte, r14
    mov.l   .L_display_list_count, r3
    mov.l   .L_display_counter_2, r2
    mov.w @r3, r3
    mov.l @r2, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_reset_iter_byte
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    mov #0x3, r2
    mov.b @r14, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_do_ptr_swap
    bsr     display_channel_iter
    nop
    mov.b @r14, r2
    add #-0x1, r2
    bra     .L_do_ptr_swap
    mov.b r2, @r14
    .2byte  0xFFFF
.L_scene_state:
    .4byte  sym_060A4CAA
.L_input_toggle_flag:
    .4byte  sym_06063601
.L_input_counter:
    .4byte  sym_06063608
.L_smpc_sr:
    .4byte  0x20100061                  /* SMPC SR — status */
.L_frame_counter_2:
    .4byte  sym_060A4CB8
.L_frame_count_byte_2:
    .4byte  sym_060A4CAB
.L_iter_count_byte:
    .4byte  sym_06063600
.L_display_list_count:
    .4byte  sym_060A4CAC
.L_display_counter_2:
    .4byte  sym_060A4CB4
.L_reset_iter_byte:
    extu.b r13, r2
    mov.b r2, @r14
.L_do_ptr_swap:
    mov.l   .L_swap_ptr_a, r5
    mov.l   .L_swap_ptr_b, r4
    mov.l @r5, r3
    mov.l r3, @r4
    mov.l   .L_swap_ptr_c, r6
    mov.l @r6, r2
    mov.l r2, @r5
    mov.l @r4, r3
    mov.l r3, @r6
    mov.l   .L_swap_ptr_d, r6
    mov.l @r6, r2
    mov.l r2, @r4
    mov.l   .L_swap_ptr_e, r5
    mov.l @r5, r3
    mov.l r3, @r6
    mov.l @r4, r2
    mov.l r2, @r5
    mov.l @r15, r3
    mov.l r2, @r3
    bsr     .L_reset_all_state
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     smpc_intback_send
    mov.l @r15+, r14
.L_return_early:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global master_menu_render
    .type master_menu_render, @function
master_menu_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   .L_const_f0, r8
    mov #0x0, r9
    mov.l   .L_smpc_sr_06039964, r10
    mov.l   .L_flow_state_ptr, r11
    mov.l   .L_input_state_ptr, r12
    mov #0x1, r13
    mov.l   .L_src_read_cursor, r14
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.l r0, @r15
    stc sr, r0
    mov.w   .L_sr_mask_ff0f, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    mov.l   .L_scene_state_2, r0
    mov.b @r0, r0
    bra     .L_main_state_dispatch
    extu.b r0, r0
.L_const_f0:
    .2byte  0x00F0
.L_sr_mask_ff0f:
    .2byte  0xFF0F
    .2byte  0xFFFF
.L_swap_ptr_a:
    .4byte  sym_060A4CE8
.L_swap_ptr_b:
    .4byte  sym_060A4CC4
.L_swap_ptr_c:
    .4byte  sym_060A4C98
.L_swap_ptr_d:
    .4byte  sym_060A4CC0
.L_swap_ptr_e:
    .4byte  sym_060A4CBC
.L_smpc_sr_06039964:
    .4byte  0x20100061                  /* SMPC SR — status */
.L_flow_state_ptr:
    .4byte  sym_060A4CF4
.L_input_state_ptr:
    .4byte  sym_060A4D04
.L_src_read_cursor:
    .4byte  sym_060A4CEC
.L_scene_state_2:
    .4byte  sym_060A4CAA
.L_read_periph_data:
    mov.l   .L_periph_data_buf, r2
    mov.l   .L_smpc_reg_24, r3
    mov.b @r3, r3
    mov.b r3, @r2
    mov.l   .L_smpc_reg_25, r3
    mov.b @r3, r0
    mov.b r0, @(1, r2)
    mov.l   .L_periph_data_buf, r3
    mov.l   .L_smpc_reg_26, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll8 r2
    mov.l   .L_smpc_reg_27, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(2, r3)
    mov.l   .L_smpc_reg_28, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll16 r2
    shll8 r2
    mov.l   .L_smpc_reg_29, r1
    mov.b @r1, r1
    extu.b r1, r1
    shll16 r1
    or r1, r2
    mov.l   .L_smpc_reg_30, r0
    mov.b @r0, r0
    extu.b r0, r0
    shll8 r0
    or r0, r2
    mov.l   .L_smpc_reg_31, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    mov.l r2, @(4, r3)
    mov.l   .L_smpc_oreg0, r2
    mov.b @r2, r0
    mov.b r0, @(8, r3)
    mov.l   .L_smpc_done_flag_2, r2
    mov.b r13, @r2
    mov.l @r15, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r1
    mov.w   .L_sr_mask_ff0f_2, r2
    and r2, r1
    or r1, r0
    ldc r0, sr
    bra     .L_render_epilogue
    nop
.L_process_input_data:
    mov.l   .L_state_clear_flag_2, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_set_oreg_ptr
    mov r9, r4
.L_copy_oreg_loop:
    mov.l   .L_str_start_ptr, r3
    mov #0x7, r2
    mov.l   .L_smpc_oreg0, r0
    mov.l @r3, r3
    sub r4, r2
    add r4, r3
    shll r2
    add #0x1, r4
    mov.b @(r0, r2), r1
    mov.b r1, @r3
    mov #0x7, r3
    cmp/hs r3, r4
    bf      .L_copy_oreg_loop
    mov.l   .L_state_clear_flag_2, r2
    mov.b r13, @r2
    mov #0x2, r1
    bra     .L_post_process
    mov.b r1, @r11
.L_set_oreg_ptr:
    extu.b r9, r2
    mov.b r2, @r11
    mov.l   .L_smpc_oreg0, r3
    mov.l r3, @r14
    bra     .L_check_iteration_limit
    nop
.L_parse_display_list:
    mov.l   .L_remaining_count, r2
    mov.l @r2, r2
    cmp/pl r2
    bf      .L_read_cmd_byte
    bra     .L_check_more_remaining
    nop
.L_read_cmd_byte:
    mov.l @r14, r0
    mov.l   .L_remaining_count, r3
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    tst r0, r0
    bf/s    .L_set_nibble_active
    mov.l r0, @r3
    mov.l @r14, r3
    mov.b @r3, r2
    extu.b r2, r2
    and r8, r2
    cmp/eq r8, r2
    bf      .L_store_char_masked
    mov.w   .L_const_ff, r4
    mov.l   .L_fn_char_store, r3
    jsr @r3
    nop
    bsr     vdp1_sprite_draw_main
    nop
    bra     .L_inc_display_ctr
    nop
.L_sr_mask_ff0f_2:
    .2byte  0xFF0F
.L_const_ff:
    .2byte  0x00FF
.L_periph_data_buf:
    .4byte  sym_060A4C9C
.L_smpc_reg_24:
    .4byte  0x20100031                  /* SMPC register #24 */
.L_smpc_reg_25:
    .4byte  0x20100033                  /* SMPC register #25 */
.L_smpc_reg_26:
    .4byte  0x20100035                  /* SMPC register #26 */
.L_smpc_reg_27:
    .4byte  0x20100037                  /* SMPC register #27 */
.L_smpc_reg_28:
    .4byte  0x20100039                  /* SMPC register #28 */
.L_smpc_reg_29:
    .4byte  0x2010003B                  /* SMPC register #29 */
.L_smpc_reg_30:
    .4byte  0x2010003D                  /* SMPC register #30 */
.L_smpc_reg_31:
    .4byte  0x2010003F                  /* SMPC register #31 */
.L_smpc_oreg0:
    .4byte  0x20100021                  /* SMPC OREG0 */
.L_smpc_done_flag_2:
    .4byte  sym_060A4CA8
.L_state_clear_flag_2:
    .4byte  sym_060A4CD8
.L_str_start_ptr:
    .4byte  sym_060A4CE8
.L_remaining_count:
    .4byte  sym_060A4CF8
.L_fn_char_store:
    .4byte  sym_0603AB46
.L_store_char_masked:
    mov.l   .L_fn_char_store_2, r3
    jsr @r3
    extu.b r8, r4
.L_inc_display_ctr:
    mov.l   .L_display_counter_3, r2
    mov.l   .L_display_counter_3, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_display_list_count_2, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_check_flow_state
    extu.b r13, r2
    mov.b r2, @r11
.L_check_flow_state:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_smpc_status
    bra     .L_post_process
    nop
.L_check_smpc_status:
    bsr     .L_smpc_status_check
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_advance_cursor
    bra     .L_post_process
    nop
.L_set_nibble_active:
    extu.b r13, r2
    mov.l   .L_phase_flag_a, r3
    mov.b r2, @r3
.L_advance_cursor:
    mov.l @r14, r2
    add #0x2, r2
    bra     .L_check_more_remaining
    mov.l r2, @r14
.L_process_ext_cmd:
    mov.l   .L_phase_flag_a, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_ext_cmd_active
    bra     .L_check_phase_b
    nop
.L_ext_cmd_active:
    extu.b r9, r2
    mov.l   .L_phase_flag_a, r3
    mov.b r2, @r3
    mov.w   .L_const_ff_2, r1
    mov.l   .L_current_char, r3
    mov.b r1, @r3
    mov.l @r14, r1
    mov.b @r1, r3
    extu.b r3, r3
    and r8, r3
    cmp/eq r8, r3
    bf      .L_check_e0_mask
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    cmp/eq #0xF, r0
    bf      .L_store_masked_char
    mov.w   .L_const_ff_2, r4
    mov.l   .L_fn_char_store_2, r3
    jsr @r3
    nop
    bra     .L_draw_sprite
    nop
.L_store_masked_char:
    mov.l   .L_fn_char_store_2, r3
    jsr @r3
    extu.b r8, r4
.L_draw_sprite:
    bsr     vdp1_sprite_draw_main
    nop
    mov.l   .L_display_counter_3, r2
    mov.l   .L_display_counter_3, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_display_list_count_2, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_check_ext_flow
    extu.b r13, r2
    mov.b r2, @r11
.L_check_ext_flow:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_dec_remaining
    bra     .L_check_flow_done
    nop
.L_dec_remaining:
    extu.b r13, r2
    mov.l   .L_phase_flag_a, r3
    mov.b r2, @r3
    mov.l   .L_remaining_count_2, r1
    mov.l @r1, r1
    add #-0x1, r1
    mov.l   .L_remaining_count_2, r3
    mov.l r1, @r3
    bra     .L_advance_and_check
    nop
.L_const_ff_2:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_fn_char_store_2:
    .4byte  sym_0603AB46
.L_display_counter_3:
    .4byte  sym_060A4CB4
.L_display_list_count_2:
    .4byte  sym_060A4CAC
.L_phase_flag_a:
    .4byte  sym_060A4D0C
.L_current_char:
    .4byte  sym_060A4CFC
.L_remaining_count_2:
    .4byte  sym_060A4CF8
.L_check_e0_mask:
    mov.l @r14, r2
    mov.b @r2, r3
    mov.w   .L_const_e0, r2
    extu.b r3, r3
    and r8, r3
    cmp/eq r2, r3
    bf      .L_store_high_nibble
    mov.l @r14, r2
    mov.b @r2, r3
    mov.w   .L_const_e3, r2
    extu.b r3, r3
    cmp/eq r2, r3
    bf      .L_store_raw_byte
    bsr     sym_0603AB46
    mov #0x20, r4
    mov #0x20, r2
    mov.l   .L_current_char_2, r3
    mov.b r2, @r3
    bra     .L_check_low_nibble
    nop
.L_store_raw_byte:
    mov.l @r14, r4
    bsr     sym_0603AB46
    mov.b @r4, r4
    bra     .L_check_low_nibble
    nop
.L_store_high_nibble:
    mov.l @r14, r4
    mov.b @r4, r4
    extu.b r4, r4
    and r8, r4
    bsr     sym_0603AB46
    extu.b r4, r4
    mov.l @r14, r2
    mov.b @r2, r3
    extu.b r3, r3
    and r8, r3
    extu.b r3, r3
    mov.l   .L_current_char_2, r2
    mov.b r3, @r2
.L_check_low_nibble:
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst #0xF, r0
    bf      .L_store_nibble_count
    extu.b r13, r3
    mov.l   .L_phase_flag_nibble, r2
    mov.b r3, @r2
    bra     .L_check_space_char
    nop
.L_store_nibble_count:
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    mov.l r0, @r12
.L_check_space_char:
    mov.l   .L_current_char_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_clear_phase_c
    mov.l   .L_elem_count_byte, r2
    mov.l   .L_row_copy_count, r3
    mov.b @r2, r2
    mov.b r2, @r3
    mov #0x5, r3
    mov.l   .L_elem_count_byte, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_adjust_elem_count
    mov #0x3, r3
    mov.l   .L_elem_count_byte, r2
    mov.b r3, @r2
    bra     .L_clear_phase_c
    nop
.L_adjust_elem_count:
    mov.l   .L_elem_count_byte, r2
    mov.b @r2, r2
    add #-0x2, r2
    mov.l   .L_elem_count_byte, r3
    mov.b r2, @r3
.L_clear_phase_c:
    extu.b r13, r2
    mov.l   .L_phase_flag_c, r3
    mov.b r2, @r3
.L_advance_and_check:
    mov.l @r14, r2
    add #0x2, r2
    bsr     .L_smpc_status_check
    mov.l r2, @r14
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_phase_b
    bra     .L_check_flow_done
    nop
.L_const_e0:
    .2byte  0x00E0
.L_const_e3:
    .2byte  0x00E3
    .2byte  0xFFFF
.L_current_char_2:
    .4byte  sym_060A4CFC
.L_phase_flag_nibble:
    .4byte  sym_060A4D0D
.L_elem_count_byte:
    .4byte  sym_060A4CAE
.L_row_copy_count:
    .4byte  sym_060A4D02
.L_phase_flag_c:
    .4byte  sym_060A4D0E
.L_check_phase_b:
    mov.l   .L_phase_flag_b, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_phase_c
    mov.l   .L_phase_flag_b, r3
    mov.b r9, @r3
    mov.l @r14, r1
    mov.b @r1, r3
    extu.b r3, r3
    mov.l r3, @r12
    mov.l @r14, r2
    add #0x2, r2
    bsr     .L_smpc_status_check
    mov.l r2, @r14
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_phase_c
    bra     .L_check_flow_done
    nop
.L_check_phase_c:
    mov.l   .L_phase_flag_c_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_phase_c_active
    bra     .L_check_phase_d
    nop
.L_phase_c_active:
    extu.b r9, r2
    mov.l   .L_phase_flag_c_2, r3
    mov.b r2, @r3
    mov.l   .L_elem_count_byte_2, r1
    mov.l @r12, r3
    mov.b @r1, r1
    extu.b r1, r1
    cmp/ge r1, r3
    bf      .L_check_end_overflow
    mov.l @r12, r3
    mov.l @r14, r2
    shll r3
    add r2, r3
    cmp/hi r10, r3
    bf      .L_check_space_copy
    extu.b r13, r2
    mov.l   .L_overflow_flag, r3
    mov.b r2, @r3
    mov.l   .L_elem_count_byte_2, r1
    mov.l @r14, r3
    mov.b @r1, r1
    extu.b r1, r1
    shll r1
    add r3, r1
    cmp/hi r10, r1
    bf      .L_no_full_overflow
    mov.l   .L_phase_flag_d, r2
    mov.b r13, @r2
    mov.l   .L_elem_count_byte_2, r4
    mov.l @r12, r1
    mov.l   .L_block_size, r2
    mov.b @r4, r4
    extu.b r4, r4
    sub r4, r1
    mov.l r1, @r2
    mov.l @r14, r0
    mov r10, r2
    sub r0, r2
    mov #0x0, r0
    cmp/gt r2, r0
    addc r0, r2
    shar r2
    sub r2, r4
    mov.l r4, @r12
    bsr     data_table_copy
    mov r10, r4
    bra     .L_set_done_state
    nop
.L_no_full_overflow:
    mov.l   .L_phase_flag_e, r3
    mov.b r13, @r3
    mov.l @r14, r1
    mov r10, r3
    mov.l @r12, r0
    sub r1, r3
    mov #0x0, r1
    cmp/gt r3, r1
    addc r1, r3
    shar r3
    sub r3, r0
    mov.l   .L_block_size, r3
    mov.l r0, @r3
    mov.l   .L_elem_count_byte_2, r4
    mov.l @r14, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    bra     .L_check_phase_d
    mov.l r10, @r14
.L_check_space_copy:
    mov.l   .L_current_char_3, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_set_copy_mode
    mov.l   .L_elem_count_byte_2, r4
    mov.l @r14, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    bra     .L_set_phase_e
    mov.l r9, @r12
.L_set_copy_mode:
    mov #0x2, r2
    mov.l   .L_copy_mode_flag, r3
    mov.b r2, @r3
    mov.l @r14, r2
    mov.l   .L_copy_dest_ptr, r3
    mov.l r2, @r3
    mov.l @r12, r2
    shll r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
.L_set_phase_e:
    extu.b r13, r2
    mov.l   .L_phase_flag_e, r3
    mov.b r2, @r3
    bra     .L_check_phase_d
    nop
.L_check_end_overflow:
    mov.l @r12, r2
    mov.l @r14, r3
    shll r2
    add r3, r2
    cmp/hi r10, r2
    bf      .L_copy_at_end
    mov.l   .L_phase_flag_d, r2
    mov.b r13, @r2
    mov r10, r2
    mov.l @r12, r0
    mov.l @r14, r1
    sub r1, r2
    mov #0x0, r1
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    sub r2, r0
    mov.l r0, @r12
    bsr     data_table_copy
    mov r10, r4
.L_set_done_state:
    mov #0x2, r2
    bra     .L_check_flow_done
    mov.b r2, @r11
.L_copy_at_end:
    mov.l   .L_phase_flag_e, r3
    mov.b r13, @r3
    mov.l @r12, r4
    mov.l @r14, r3
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    mov.l r9, @r12
.L_check_phase_d:
    mov.l   .L_phase_flag_d, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_phase_e
    extu.b r9, r2
    mov.l   .L_phase_flag_d, r3
    mov.b r2, @r3
    mov #0x20, r3
    mov.l @r12, r1
    cmp/ge r3, r1
    bf      .L_phase_d_small_block
    mov.l   .L_phase_flag_d, r2
    mov.b r13, @r2
    mov r10, r4
    mov.l @r12, r1
    add #-0x20, r1
    bra     .L_copy_loop_check
    mov.l r1, @r12
.L_phase_d_small_block:
    extu.b r13, r2
    mov.l   .L_phase_flag_e, r3
    mov.b r2, @r3
    mov.l @r12, r4
    shll r4
    mov.l   .L_smpc_oreg0_06039E58, r3
    add r3, r4
    bra     .L_copy_loop_check
    mov.l r9, @r12
.L_copy_byte_loop:
    mov.l   .L_write_cursor, r2
    mov.l @r2, r2
    mov.l @r14, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l   .L_write_cursor, r3
    mov.l @r3, r3
    add #0x1, r3
    mov.l   .L_write_cursor, r2
    mov.l r3, @r2
    mov.l @r14, r1
    add #0x2, r1
    mov.l r1, @r14
.L_copy_loop_check:
    mov.l @r14, r3
    cmp/hs r4, r3
    bf      .L_copy_byte_loop
    bsr     .L_smpc_status_check
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_phase_e
    bra     .L_check_flow_done
    nop
.L_check_phase_e:
    mov.l   .L_phase_flag_e, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_phase_f_active
    mov.l   .L_phase_flag_e, r3
    mov.b r9, @r3
    bsr     game_logic_main
    nop
    mov.l   .L_display_counter_4, r2
    mov.l   .L_display_counter_4, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_display_list_count_3, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_check_game_flow
    extu.b r13, r2
    mov.b r2, @r11
.L_check_game_flow:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_phase_f
    bra     .L_check_flow_done
    nop
    .2byte  0xFFFF
.L_phase_flag_b:
    .4byte  sym_060A4D0D
.L_phase_flag_c_2:
    .4byte  sym_060A4D0E
.L_elem_count_byte_2:
    .4byte  sym_060A4CAE
.L_overflow_flag:
    .4byte  sym_060A4D11
.L_phase_flag_d:
    .4byte  sym_060A4D0F
.L_block_size:
    .4byte  sym_060A4D08
.L_phase_flag_e:
    .4byte  sym_060A4D10
.L_current_char_3:
    .4byte  sym_060A4CFC
.L_copy_mode_flag:
    .4byte  sym_060A4CCC
.L_copy_dest_ptr:
    .4byte  sym_060A4CD0
.L_smpc_oreg0_06039E58:
    .4byte  0x20100021                  /* SMPC OREG0 */
.L_write_cursor:
    .4byte  sym_060A4CD4
.L_display_counter_4:
    .4byte  sym_060A4CB4
.L_display_list_count_3:
    .4byte  sym_060A4CAC
.L_check_phase_f:
    mov.l   .L_phase_flag_f, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_check_smpc_again
    mov.l   .L_remaining_count_3, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.l   .L_remaining_count_3, r2
    mov.l r3, @r2
    extu.b r13, r1
    mov.l   .L_phase_flag_a_2, r2
    mov.b r1, @r2
.L_check_smpc_again:
    bsr     .L_smpc_status_check
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_phase_f_active
    bra     .L_check_flow_done
    nop
.L_check_phase_f_active:
    mov.l   .L_phase_flag_f, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_more_remaining
    extu.b r9, r2
    mov.l   .L_phase_flag_f, r3
    mov.b r2, @r3
    mov.l   .L_block_size_2, r1
    mov #0x20, r3
    mov.l @r1, r1
    cmp/gt r3, r1
    bf      .L_phase_f_small_block
    extu.b r13, r3
    mov.l   .L_phase_flag_d_2, r2
    mov.b r3, @r2
    mov.l r10, @r14
    mov.l   .L_block_size_2, r3
    mov.l @r3, r3
    add #-0x20, r3
    mov.l   .L_block_size_2, r2
    mov.l r3, @r2
    bra     .L_check_smpc_final
    nop
.L_phase_f_small_block:
    mov.l   .L_block_size_2, r3
    mov.l @r3, r3
    shll r3
    mov.l @r14, r2
    add r3, r2
    mov.l r2, @r14
    extu.b r13, r3
    mov.l   .L_phase_flag_a_2, r2
    mov.b r3, @r2
    mov.l   .L_remaining_count_3, r1
    mov.l @r1, r1
    add #-0x1, r1
    mov.l   .L_remaining_count_3, r2
    mov.l r1, @r2
    mov.l   .L_block_size_2, r2
    mov.l r9, @r2
.L_check_smpc_final:
    bsr     .L_smpc_status_check
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_more_remaining
    bra     .L_check_flow_done
    nop
.L_check_more_remaining:
    mov.l   .L_remaining_count_3, r2
    mov.l @r2, r2
    cmp/pl r2
    bf      .L_check_flow_done
    bra     .L_process_ext_cmd
    nop
.L_check_flow_done:
    mov.b @r11, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_inc_iteration
    bra     .L_post_process
    nop
.L_inc_iteration:
    mov.l   .L_iteration_counter, r2
    mov.l @r2, r2
    add #0x1, r2
    mov.l   .L_iteration_counter, r3
    mov.l r2, @r3
.L_check_iteration_limit:
    mov.l   .L_iteration_counter, r2
    mov #0x2, r3
    mov.l @r2, r2
    cmp/ge r3, r2
    bt      .L_iteration_done
    bra     .L_parse_display_list
    nop
.L_iteration_done:
    bra     .L_post_process
    nop
.L_main_state_dispatch:
    cmp/eq #0x0, r0
    bf      .L_check_state_1
    bra     .L_read_periph_data
    nop
.L_check_state_1:
    cmp/eq #0x1, r0
    bf      .L_check_state_2
    bra     .L_set_oreg_ptr
    nop
.L_check_state_2:
    cmp/eq #0x2, r0
    bf      .L_post_process
    bra     .L_process_input_data
    nop
.L_post_process:
    mov.b @r11, r0
    bra     .L_post_dispatch
    extu.b r0, r0
.L_flush_display:
    bsr     display_channel_iter
    nop
.L_set_ireg_mode:
    mov.l   .L_ireg_config_byte, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    or #0x40, r0
    extu.b r0, r0
    mov.l   .L_smpc_ireg0_ct, r3
    mov.b r0, @r3
    bra     .L_restore_sr
    nop
.L_toggle_ireg:
    mov.l   .L_ireg_config_byte, r2
    mov.b @r2, r2
    extu.b r2, r2
    not r2, r2
    extu.b r2, r2
    mov.l   .L_ireg_config_byte, r3
    mov.b r2, @r3
    mov r3, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    extu.b r0, r0
    mov.l   .L_smpc_ireg0_ct, r3
    mov.b r0, @r3
    bra     .L_restore_sr
    nop
.L_post_dispatch:
    cmp/eq #0x0, r0
    bt      .L_flush_display
    cmp/eq #0x1, r0
    bt      .L_set_ireg_mode
    cmp/eq #0x2, r0
    bt      .L_toggle_ireg
.L_restore_sr:
    mov.l @r15, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r2
    mov.w   .L_sr_mask_ff0f_3, r3
    and r3, r2
    or r2, r0
    ldc r0, sr
.L_render_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_sr_mask_ff0f_3:
    .2byte  0xFF0F
.L_phase_flag_f:
    .4byte  sym_060A4D11
.L_remaining_count_3:
    .4byte  sym_060A4CF8
.L_phase_flag_a_2:
    .4byte  sym_060A4D0C
.L_block_size_2:
    .4byte  sym_060A4D08
.L_phase_flag_d_2:
    .4byte  sym_060A4D0F
.L_iteration_counter:
    .4byte  sym_060A4CF0
.L_ireg_config_byte:
    .4byte  sym_060A4CA9
.L_smpc_ireg0_ct:
    .4byte  0x20100001                  /* SMPC IREG0 (cache-through) */
    .4byte  0xD30DD20E
    .4byte  0x63316222
    .4byte  0x633D3233
    .4byte  0x8B02E201
    .4byte  0xD30B2320
    .4byte  0x000B0009
.L_smpc_status_check:
    mov.l   .L_smpc_sr_0603A014, r5
    mov.l   .L_src_cursor_check, r3
    mov.l @r3, r3
    cmp/hs r5, r3
    bf      .L_smpc_check_done
    mov #0x20, r4
    mov.b @r5, r3
    extu.b r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_smpc_check_done
    mov #0x2, r3
    mov.l   .L_flow_state_byte, r2
    mov.b r3, @r2
.L_smpc_check_done:
    rts
    nop
    .4byte  sym_060A4CAC
    .4byte  sym_060A4CB4
.L_flow_state_byte:
    .4byte  sym_060A4CF4
.L_smpc_sr_0603A014:
    .4byte  0x20100061                  /* SMPC SR — status */
.L_src_cursor_check:
    .4byte  sym_060A4CEC

    .global data_table_copy
    .type data_table_copy, @function
data_table_copy:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_src_read_cursor_2, r13
    mov.l   .L_write_cursor_2, r14
    bsr     menu_anim_system
    mov.l r4, @r15
    mov.l   .L_anim_data_ptr_2, r5
    mov.l   .L_copy_dest_ptr_2, r4
    mov.l @r5, r2
    mov.l r2, @r4
    mov.l @r5, r3
    mov #0x1, r2
    mov.l r3, @r14
    mov.l   .L_copy_mode_flag_2, r3
    mov.b r2, @r3
    mov.l   .L_current_char_4, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_copy_end_check
    mov #0x5, r3
    mov.l   .L_row_copy_count_2, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_advance_write_ptr
    mov.l   .L_default_src_start, r5
    mov r5, r3
    mov.l r5, @r4
    add #0x2, r5
    bra     .L_skip_to_copy_check
    mov.l r5, @r14
.L_advance_write_ptr:
    mov.l @r14, r2
    add #0x2, r2
    mov.l r2, @r14
.L_skip_to_copy_check:
    bra     .L_copy_end_check
    nop
.L_copy_data_byte:
    mov.l @r14, r2
    mov.l @r13, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.l @r13, r2
    add #0x2, r2
    mov.l r2, @r13
.L_copy_end_check:
    mov.l @r13, r3
    mov.l @r15, r2
    cmp/hs r2, r3
    bf      .L_copy_data_byte
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_src_read_cursor_2:
    .4byte  sym_060A4CEC
.L_write_cursor_2:
    .4byte  sym_060A4CD4
.L_anim_data_ptr_2:
    .4byte  sym_060A4CC8
.L_copy_dest_ptr_2:
    .4byte  sym_060A4CD0
.L_copy_mode_flag_2:
    .4byte  sym_060A4CCC
.L_current_char_4:
    .4byte  sym_060A4CFC
.L_row_copy_count_2:
    .4byte  sym_060A4D02
.L_default_src_start:
    .4byte  sym_060A4CFD

    .global game_logic_main
    .type game_logic_main, @function
game_logic_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l macl, @-r15
    mov #0x10, r11
    add #-0x8, r15
    mov.l   .L_elem_count_byte_3, r13
    mov.l   .L_display_counter_5, r7
    mov.l   .L_render_table_base, r6
    mov.l   .L_copy_mode_ptr, r5
    mov.l   .L_copy_dest_ptr_3, r4
    mov.l   .L_current_char_5, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bt/s    .L_space_char_active
    mov #0x20, r12
    bra     .L_render_dispatch
    nop
.L_space_char_active:
    mov.l @r4, r2
    mov.w   DAT_0603a1a2, r3
    mov.b r3, @r2
    mov.b @r5, r0
    mov.l @r4, r3
    mov.w   DAT_0603a1a2, r2
    extu.b r0, r0
    add r3, r0
    mov.b r2, @r0
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    mov.w   .L_const_80, r3
    extu.b r0, r0
    and #0x80, r0
    cmp/eq r3, r0
    bf      .L_check_button_count
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf      .L_clear_bit_10
    mov.l @r4, r3
    mov #-0x21, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_40
    nop
.L_clear_bit_10:
    mov.l @r4, r3
    mov #-0x11, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_40
    nop
.L_check_button_count:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll2 r0
    add r3, r0
    mov.b @r0, r2
    mov #0xA, r3
    extu.b r2, r2
    cmp/gt r3, r2
    bf      .L_check_bit_40
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf      .L_clear_bit_10_2
    mov.l @r4, r3
    mov #-0x21, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_40
    nop
.L_clear_bit_10_2:
    mov.l @r4, r3
    mov #-0x11, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_check_bit_40:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x40, r0
    cmp/eq #0x40, r0
    bf      .L_check_triple_count
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r11, r2
    cmp/eq r11, r2
    bf      .L_clear_bit_40_alt
    mov.l @r4, r3
    mov #-0x41, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_1
    nop

    .global DAT_0603a1a2
DAT_0603a1a2:
    .2byte  0x00FF
.L_const_80:
    .2byte  0x0080
    .2byte  0xFFFF
.L_elem_count_byte_3:
    .4byte  sym_060A4CAE
.L_display_counter_5:
    .4byte  sym_060A4CB4
.L_render_table_base:
    .4byte  sym_060A4CC0
.L_copy_mode_ptr:
    .4byte  sym_060A4CCC
.L_copy_dest_ptr_3:
    .4byte  sym_060A4CD0
.L_current_char_5:
    .4byte  sym_060A4CFC
.L_clear_bit_40_alt:
    mov.l @r4, r3
    mov.w   DAT_0603a2ca, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_1
    nop
.L_check_triple_count:
    mov.b @r5, r0
    mov.l @r4, r2
    extu.b r0, r0
    mov r0, r3
    shll r0
    add r3, r0
    add r2, r0
    mov.b @r0, r3
    mov #0xA, r2
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_check_bit_1
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r11, r2
    cmp/eq r11, r2
    bf      .L_clear_bit_40_alt_2
    mov.l @r4, r3
    mov #-0x41, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_check_bit_1
    nop
.L_clear_bit_40_alt_2:
    mov.l @r4, r3
    mov.w   DAT_0603a2ca, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_check_bit_1:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x1, r0
    cmp/eq #0x1, r0
    bf      .L_check_bit_4
    mov.l @r4, r3
    mov #-0x5, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_check_bit_4:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x4, r0
    cmp/eq #0x4, r0
    bf      .L_check_bit_2
    mov.l @r4, r3
    mov #-0x2, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_check_bit_2:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x2, r0
    cmp/eq #0x2, r0
    bf      .L_check_bit_8
    mov.l @r4, r3
    mov #-0x3, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_check_bit_8:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x8, r0
    cmp/eq #0x8, r0
    bf      .L_store_row_count
    mov.l @r4, r3
    mov #-0x9, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_store_row_count:
    mov.l   .L_row_copy_count_3, r3
    mov.b @r3, r3
    mov.b r3, @r13
.L_render_dispatch:
    mov.l   .L_display_list_base_2, r14
    mov.l   .L_display_mode_byte_2, r0
    mov.b @r0, r0
    bra     .L_render_mode_switch
    extu.b r0, r0
.L_render_mode_ff:
    bra     .L_fill_row_check
    mov #0x0, r14
.L_fill_row_loop:
    mov.b @r13, r2
    extu.b r2, r2
    add #0x1, r2
    mov.l @r7, r3
    mul.l r3, r2
    sts macl, r2
    mov.l @r6, r1
    add r1, r2
    add r14, r2
    mov.b @r5, r0
    extu.b r0, r0
    mul.l r14, r0
    sts macl, r0
    mov.l @r4, r3
    add r3, r0
    mov.b @r0, r1
    mov #0x1, r3
    add r2, r3
    mov.b r1, @r3
    add #0x1, r14
.L_fill_row_check:
    mov.b @r13, r2
    extu.b r2, r2
    cmp/hs r2, r14
    bf      .L_fill_row_loop
    bra     .L_logic_epilogue
    nop

    .global DAT_0603a2ca
DAT_0603a2ca:
    .2byte  0xFF7F
.L_row_copy_count_3:
    .4byte  sym_060A4D02
.L_display_list_base_2:
    .4byte  sym_060A4CBC
.L_display_mode_byte_2:
    .4byte  sym_060A4CAF
.L_render_mode_00:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    extu.b r1, r1
    mov.b @r3, r0
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_10:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    extu.b r1, r1
    mov.b @r3, r0
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r0
    mov.w r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov r0, r2
    mov.l @r4, r1
    shll r0
    add r2, r0
    mov.b @(r0, r1), r2
    extu.b r2, r0
    mov.w r0, @(4, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r6, r1
    add r1, r3
    mov.b @r5, r0
    extu.b r0, r0
    shll2 r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r0
    mov.w r0, @(6, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov r3, r1
    mov.w @r2, r2
    mov.w @r1, r1
    extu.w r2, r2
    extu.w r1, r1
    not r2, r2
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(8, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(2, r2), r0
    mov r3, r1
    mov r0, r2
    mov.w @(2, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r0
    mov.w r0, @(10, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(4, r2), r0
    mov r0, r2
    mov r3, r1
    mov.w @(4, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r0
    mov.w r0, @(12, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(6, r2), r0
    mov r0, r2
    mov r3, r1
    mov.w @(6, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_20:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r1
    not r1, r1
    extu.w r1, r0
    mov.w r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.b @r5, r0
    mov.l @r4, r1
    extu.b r0, r0
    mov r0, r2
    shll r0
    add r2, r0
    mov.b @(r0, r1), r2
    mov r3, r0
    mov #0x2, r1
    mov.w @(r0, r1), r1
    extu.w r1, r1
    and r11, r1
    cmp/eq r11, r1
    bf/s    .L_negate_direction
    extu.b r2, r2
    bra     .L_apply_direction
    mov #0x1, r1
.L_negate_direction:
    mov #-0x1, r1
.L_apply_direction:
    mul.l r1, r2
    sts macl, r2
    exts.w r2, r0
    mov.w r0, @(4, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.b @r5, r0
    mov.l @r4, r2
    extu.b r0, r0
    shll2 r0
    mov.b @(r0, r2), r1
    mov r3, r0
    mov #0x2, r2
    mov.w @(r0, r2), r2
    extu.w r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf/s    .L_negate_vert_dir
    extu.b r1, r1
    bra     .L_apply_vert_dir
    mov #0x1, r2
.L_negate_vert_dir:
    mov #-0x1, r2
.L_apply_vert_dir:
    mul.l r2, r1
    sts macl, r1
    exts.w r1, r0
    mov.w r0, @(6, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(8, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_30:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r1
    not r1, r1
    extu.b r1, r0
    mov.b r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    mov r0, r2
    mov.l @r4, r1
    shll r0
    add r2, r0
    add r1, r0
    mov.b @r0, r2
    mov #0x3, r1
    add r3, r1
    mov.b r2, @r1
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_e1:
    mov.l @r7, r2
    mov.l @r6, r1
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.b @r2, r2
    extu.b r2, r2
    not r2, r2
    mov r3, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    extu.b r2, r2
    mov r2, r0
    mov.b r0, @(1, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_e2:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r3)
    bra     .L_logic_epilogue
    nop
.L_render_mode_switch:
    cmp/eq #0x0, r0
    bf      .L_rcheck_mode_10
    bra     .L_render_mode_00
    nop
.L_rcheck_mode_10:
    cmp/eq #0x10, r0
    bf      .L_rcheck_mode_20
    bra     .L_render_mode_10
    nop
.L_rcheck_mode_20:
    cmp/eq #0x20, r0
    bf      .L_rcheck_mode_30
    bra     .L_render_mode_20
    nop
.L_rcheck_mode_30:
    cmp/eq #0x30, r0
    bf      .L_rcheck_mode_ext
    bra     .L_render_mode_30
    nop
.L_rcheck_mode_ext:
    mov.w   .L_mode_e1, r1
    cmp/eq r1, r0
    bt      .L_render_mode_e1
    mov.w   .L_mode_e2, r1
    cmp/eq r1, r0
    bt      .L_render_mode_e2
    mov.w   DAT_0603a6fe, r1
    cmp/eq r1, r0
    bf      .L_logic_epilogue
    bra     .L_render_mode_ff
    nop
.L_logic_epilogue:
    add #0x8, r15
    lds.l @r15+, macl
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_reset_all_state:
    mov #0x1, r3
    mov #0x0, r4
    mov.l   .L_reset_phase_a, r2
    extu.b r4, r0
    mov.b r3, @r2
    extu.b r4, r3
    mov.l   .L_reset_phase_b, r2
    mov.b r3, @r2
    mov.l   .L_reset_phase_c, r2
    extu.b r4, r3
    mov.b r4, @r2
    mov.l   .L_reset_phase_d, r2
    mov.b r0, @r2
    extu.b r4, r0
    mov.l   .L_reset_phase_e, r2
    mov.b r3, @r2
    mov.l   .L_reset_phase_f, r2
    mov.b r4, @r2
    mov.l   .L_reset_state_clear, r2
    mov.b r0, @r2
    mov.l   .L_reset_display_ctr, r3
    mov.l r4, @r3
    mov.l   .L_reset_iter_counter, r3
    mov.l r4, @r3
    mov.l   .L_reset_remaining, r3
    mov.l r4, @r3
    mov.l   .L_reset_ireg_config, r3
    rts
    mov.b r4, @r3
.L_mode_e1:
    .2byte  0x00E1
.L_mode_e2:
    .2byte  0x00E2

    .global DAT_0603a6fe
DAT_0603a6fe:
    .2byte  0x00FF
.L_reset_phase_a:
    .4byte  sym_060A4D0C
.L_reset_phase_b:
    .4byte  sym_060A4D0D
.L_reset_phase_c:
    .4byte  sym_060A4D0E
.L_reset_phase_d:
    .4byte  sym_060A4D0F
.L_reset_phase_e:
    .4byte  sym_060A4D10
.L_reset_phase_f:
    .4byte  sym_060A4D11
.L_reset_state_clear:
    .4byte  sym_060A4CD8
.L_reset_display_ctr:
    .4byte  sym_060A4CB4
.L_reset_iter_counter:
    .4byte  sym_060A4CF0
.L_reset_remaining:
    .4byte  sym_060A4CF8
.L_reset_ireg_config:
    .4byte  sym_060A4CA9

    .global smpc_intback_send
smpc_intback_send:
    mov.l   .L_smpc_sf, r5
    mov #0x1, r4
    mov.b @r5, r3
    extu.b r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_send_smpc_cmd
    rts
    mov #0x1, r0
.L_send_smpc_cmd:
    extu.b r4, r4
    mov.b r4, @r5
    mov.l   .L_smpc_port_data, r4
    mov.b @r4, r3
    mov.l   .L_smpc_ireg0_ct_0603A7A4, r2
    mov.b r3, @r2
    mov.b @(1, r4), r0
    mov r0, r3
    add #0x2, r2
    mov.b r3, @r2
    mov.b @(2, r4), r0
    mov r0, r3
    add #0x2, r2
    mov.b r3, @r2
    mov #0x10, r3
    add #0x1A, r2
    mov.b r3, @r2
    mov #0x0, r0
    rts
    nop

    .global display_channel_iter
    .type display_channel_iter, @function
display_channel_iter:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_display_list_count_4, r12
    mov.w   .L_const_ff_3, r13
    mov.l   .L_display_counter_6, r14
    bra     .L_draw_iter_check
    nop
.L_draw_iter_body:
    bsr     sym_0603AB46
    extu.b r13, r4
    bsr     vdp1_sprite_draw_main
    nop
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_draw_iter_check:
    mov.w @r12, r3
    mov.l @r14, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bf      .L_draw_iter_body
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_const_ff_3:
    .2byte  0x00FF
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_smpc_port_data:
    .4byte  sym_06063602
.L_smpc_ireg0_ct_0603A7A4:
    .4byte  0x20100001                  /* SMPC IREG0 (cache-through) */
.L_display_list_count_4:
    .4byte  sym_060A4CAC
.L_display_counter_6:
    .4byte  sym_060A4CB4

    .global vdp1_sprite_draw_main
    .type vdp1_sprite_draw_main, @function
vdp1_sprite_draw_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l macl, @-r15
    mov.l   .L_elem_count_byte_4, r13
    mov.w   DAT_0603a8bc, r14
    mov.l   .L_display_counter_7, r5
    mov.l   .L_render_table_base_2, r4
    mov #0x0, r7
    mov.l   .L_mask_low16, r6
    mov.l   .L_display_mode_byte_3, r0
    mov.b @r0, r0
    bra     .L_sprite_mode_switch
    extu.b r0, r0
.L_sprite_mode_ff:
    bra     .L_sprite_fill_check
    mov r7, r6
.L_sprite_fill_loop:
    mov.b @r13, r2
    extu.b r2, r2
    add #0x1, r2
    mov.l @r5, r3
    mul.l r3, r2
    sts macl, r2
    mov.l @r4, r1
    add r1, r2
    add r6, r2
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r2)
    add #0x1, r6
.L_sprite_fill_check:
    mov.b @r13, r3
    extu.b r3, r3
    cmp/hs r3, r6
    bf      .L_sprite_fill_loop
    bra     .L_sprite_epilogue
    nop
.L_sprite_mode_00:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    bra     .L_sprite_store_word
    nop
.L_sprite_mode_10:
    mov.l @r5, r2
    exts.w r7, r0
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.w r0, @(2, r2)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    mov r3, r2
    mov.l @r4, r1
    exts.w r7, r0
    extu.w r6, r6
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(6, r3)
    mov r6, r0
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(8, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(10, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    mov.l @r4, r1
    exts.w r7, r0
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(12, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r7
    mov r7, r0
    mov.w r0, @(14, r3)
    bra     .L_sprite_epilogue
    nop

    .global DAT_0603a8bc
DAT_0603a8bc:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_elem_count_byte_4:
    .4byte  sym_060A4CAE
.L_display_counter_7:
    .4byte  sym_060A4CB4
.L_render_table_base_2:
    .4byte  sym_060A4CC0
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_display_mode_byte_3:
    .4byte  sym_060A4CAF
.L_sprite_mode_20:
    mov.l @r5, r2
    extu.w r6, r0
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.w r0, @(2, r2)
    mov.l @r5, r3
    exts.w r7, r0
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(6, r3)
    mov.l @r5, r3
    mov r3, r2
    mov.l @r4, r1
    extu.w r6, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r6, @r3
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(10, r3)
    exts.w r7, r0
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(12, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    exts.w r7, r7
    mov.l @r4, r1
    add r2, r3
    mov r7, r0
    add r1, r3
    mov.w r0, @(14, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.w r6, r6
    mov r6, r0
    mov.w r0, @(8, r3)
    bra     .L_sprite_epilogue
    nop
.L_sprite_mode_30:
    extu.b r14, r0
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.b r0, @(2, r2)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.b r14, r0
    mov.b r0, @(3, r3)
    mov.l @r5, r3
    mov r3, r2
    extu.w r6, r6
    mov.l @r4, r1
    shll r3
    shll2 r2
    mov r6, r0
    shll r2
    add r2, r3
    add r1, r3
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    extu.b r14, r0
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    mov.b r0, @(6, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.b r14, r2
    mov r2, r0
    mov.b r0, @(7, r3)
    bra     .L_sprite_epilogue
    nop
.L_sprite_mode_e1:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.b r14, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    add r3, r2
    mov.l @r4, r1
    add r1, r2
    extu.b r14, r0
    bra     .L_sprite_epilogue
    mov.b r0, @(1, r2)
.L_sprite_mode_e2:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
.L_sprite_store_word:
    mov.l @r4, r1
    add r1, r2
    extu.w r6, r6
    mov r6, r0
    bra     .L_sprite_epilogue
    mov.w r0, @(2, r2)
.L_sprite_mode_switch:
    cmp/eq #0x0, r0
    bf      .L_scheck_mode_10
    bra     .L_sprite_mode_00
    nop
.L_scheck_mode_10:
    cmp/eq #0x10, r0
    bf      .L_scheck_mode_20
    bra     .L_sprite_mode_10
    nop
.L_scheck_mode_20:
    cmp/eq #0x20, r0
    bf      .L_scheck_mode_30_ext
    bra     .L_sprite_mode_20
    nop
.L_scheck_mode_30_ext:
    cmp/eq #0x30, r0
    bt      .L_sprite_mode_30
    mov.w   .L_mode_e1_2, r1
    cmp/eq r1, r0
    bt      .L_sprite_mode_e1
    mov.w   .L_mode_e2_2, r1
    cmp/eq r1, r0
    bt      .L_sprite_mode_e2
    mov.w   .L_mode_ff, r1
    cmp/eq r1, r0
    bf      .L_sprite_epilogue
    bra     .L_sprite_mode_ff
    nop
.L_sprite_epilogue:
    lds.l @r15+, macl
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_mode_e1_2:
    .2byte  0x00E1
.L_mode_e2_2:
    .2byte  0x00E2
.L_mode_ff:
    .2byte  0x00FF

    .global menu_anim_system
    .type menu_anim_system, @function
menu_anim_system:
    mov.l r14, @-r15
    mov.l   .L_elem_count_byte_5, r14
    mov.w   .L_const_ff_4, r5
    mov.l   .L_anim_data_ptr_3, r4
    mov #0x0, r6
    mov.l   .L_display_mode_byte_4, r0
    mov.b @r0, r0
    bra     .L_anim_mode_switch
    extu.b r0, r0
.L_anim_mode_ff:
    bra     .L_anim_fill_check
    mov r6, r7
.L_anim_fill_loop:
    mov.l @r4, r2
    add r7, r2
    extu.b r5, r3
    mov.b r3, @r2
    add #0x1, r7
.L_anim_fill_check:
    mov.b @r14, r2
    extu.b r2, r2
    cmp/hs r2, r7
    bf      .L_anim_fill_loop
    bra     .L_anim_epilogue
    nop
.L_anim_mode_00:
    bra     .L_anim_mode_e2
    nop
.L_anim_mode_10:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x2, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x3, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    bra     .L_anim_store_zero
    add #0x4, r2
.L_anim_mode_20:
    mov.l @r4, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x1, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    bra     .L_anim_store_zero
    add #0x2, r2
.L_anim_mode_30:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x2, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x3, r2
.L_anim_store_zero:
    extu.b r6, r6
    bra     .L_anim_epilogue
    mov.b r6, @r2
.L_anim_mode_e1:
    bra     .L_anim_store_ff
    mov.l @r4, r2
.L_anim_mode_e2:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
.L_anim_store_ff:
    bra     .L_anim_epilogue
    mov.b r5, @r2
.L_const_ff_4:
    .2byte  0x00FF
.L_elem_count_byte_5:
    .4byte  sym_060A4CAE
.L_anim_data_ptr_3:
    .4byte  sym_060A4CC8
.L_display_mode_byte_4:
    .4byte  sym_060A4CAF
.L_anim_mode_switch:
    cmp/eq #0x0, r0
    bt      .L_anim_mode_00
    cmp/eq #0x10, r0
    bt      .L_anim_mode_10
    cmp/eq #0x20, r0
    bt      .L_anim_mode_20
    cmp/eq #0x30, r0
    bt      .L_anim_mode_30
    mov.w   .L_mode_e1_3, r1
    cmp/eq r1, r0
    bt      .L_anim_mode_e1
    mov.w   .L_mode_e2_3, r1
    cmp/eq r1, r0
    bt      .L_anim_mode_e2
    mov.w   .L_mode_ff_2, r1
    cmp/eq r1, r0
    bt      .L_anim_mode_ff
.L_anim_epilogue:
    rts
    mov.l @r15+, r14

    .global sym_0603AB46
sym_0603AB46:
    sts.l macl, @-r15
    mov.l   .L_display_counter_8, r6
    mov.l   .L_render_table_base_3, r5
    mov.l   .L_display_mode_byte_5, r0
    mov.b @r0, r0
    bra     .L_char_mode_switch
    extu.b r0, r0
.L_char_mode_ff:
    mov.l   .L_elem_count_byte_6, r0
    mov.b @r0, r0
    extu.b r0, r0
    add #0x1, r0
    mov.l @r6, r3
    mul.l r3, r0
    sts macl, r0
    mov.l @r5, r2
    add r2, r0
    bra     .L_char_epilogue
    mov.b r4, @r0
.L_char_mode_00:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    bra     .L_char_store_at_4
    nop
.L_char_mode_10:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    bra     .L_char_store_at_10
    nop
.L_char_mode_20:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
.L_char_store_at_10:
    mov.l @r5, r1
    add r1, r2
    mov #0x10, r0
    bra     .L_char_epilogue
    mov.b r4, @(r0, r2)
.L_char_mode_30:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_char_epilogue
    mov.b r0, @(8, r2)
.L_char_mode_e1:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    add r3, r2
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_char_epilogue
    mov.b r0, @(2, r2)
.L_mode_e1_3:
    .2byte  0x00E1
.L_mode_e2_3:
    .2byte  0x00E2
.L_mode_ff_2:
    .2byte  0x00FF
.L_display_counter_8:
    .4byte  sym_060A4CB4
.L_render_table_base_3:
    .4byte  sym_060A4CC0
.L_display_mode_byte_5:
    .4byte  sym_060A4CAF
.L_elem_count_byte_6:
    .4byte  sym_060A4CAE
.L_char_mode_e2:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
.L_char_store_at_4:
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_char_epilogue
    mov.b r0, @(4, r2)
.L_char_mode_switch:
    cmp/eq #0x0, r0
    bt      .L_char_mode_00
    cmp/eq #0x10, r0
    bt      .L_char_mode_10
    cmp/eq #0x20, r0
    bt      .L_char_mode_20
    cmp/eq #0x30, r0
    bt      .L_char_mode_30
    mov.w   DAT_0603ac16, r1
    cmp/eq r1, r0
    bt      .L_char_mode_e1
    mov.w   DAT_0603ac18, r1
    cmp/eq r1, r0
    bt      .L_char_mode_e2
    mov.w   DAT_0603ac1a, r1
    cmp/eq r1, r0
    bt      .L_char_mode_ff
.L_char_epilogue:
    rts
    lds.l @r15+, macl

    .global DAT_0603ac16
DAT_0603ac16:
    .2byte  0x00E1

    .global DAT_0603ac18
DAT_0603ac18:
    .2byte  0x00E2

    .global DAT_0603ac1a
DAT_0603ac1a:
    .2byte  0x00FF
