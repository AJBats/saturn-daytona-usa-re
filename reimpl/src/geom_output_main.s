
    .section .text.FUN_0601F5D0


    .global mem_pool_reset
    .type mem_pool_reset, @function
mem_pool_reset:
    sts.l pr, @-r15
    bsr     .L_select_buffer
    mov #0x0, r4
    mov.l   .L_fn_geom_vertex_process, r3
    jmp @r3
    lds.l @r15+, pr
.L_fn_geom_vertex_process:
    .4byte  geom_vertex_process

    .global geom_render_util
    .type geom_render_util, @function
geom_render_util:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov #0x40, r11
    sts.l macl, @-r15
    mov r11, r12
    mov.w   DAT_0601f6ba, r13
    mov.l   .L_geom_buf_base, r14
    add #0x40, r12
    bsr     .L_select_buffer
    mov #0x0, r4
    mov.l   .L_fn_hud_overlay_render_a, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_normal_compute, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_output_handler, r3
    jsr @r3
    nop
    mov.l   .L_render_active_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_render_active
    bra     .L_render_skip_epilog
    nop
.L_render_active:
    mov.l   .L_geom_cmd_buffer, r4
    mov.b @(4, r14), r0
    mov r0, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.b @(5, r14), r0
    mov r0, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.b @(6, r14), r0
    mov r0, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.b @(7, r14), r0
    mov r0, r3
    mov.b r3, @r4
    mov.l   .L_geom_cmd_buffer, r4
    mov.l   .L_geom_cmd_src, r3
    mov.l @r4, r2
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_cmd_buffer_valid
    mov.l @r4, r0
    tst r0, r0
    bt      .L_cmd_buffer_valid
    bra     .L_render_skip_epilog
    nop
.L_cmd_buffer_valid:
    mov #0x1, r3
    mov.l   .L_render_dirty_flag, r2
    mov.b r3, @r2
    mov.l   .L_buf_index, r3
    mov.l   .L_prev_buf_index, r2
    mov.l @r3, r3
    mov.b r3, @r2
    mov.l   .L_geom_cmd_src, r4
    mov.b @r4+, r0
    mov.b r0, @(4, r14)
    mov.b @r4+, r0
    mov.b r0, @(5, r14)
    mov.b @r4+, r2
    mov r2, r0
    mov.b r0, @(6, r14)
    mov.b @r4, r0
    mov.b r0, @(7, r14)
    mov.l   .L_buf_write_pos, r4
    mov.l @r4, r4
    cmp/hs r13, r4
    bt      .L_pad_complete
.L_pad_buffer_loop:
    mov r4, r0
    extu.b r12, r3
    add #0x1, r4
    mov.b r11, @(r0, r14)
    mov r4, r0
    add #0x1, r4
    cmp/hs r13, r4
    bf/s    .L_pad_buffer_loop
    mov.b r3, @(r0, r14)
.L_pad_complete:
    mov.l   .L_buf_index, r4
    mov.l @r4, r4
    add #0x1, r4
    bsr     .L_select_buffer
    extu.b r4, r4
    mov.l   .L_title_string_ptr_a, r5
    mov.l @r5, r0
    tst r0, r0
    bt/s    .L_check_title_ptr_b
    mov #0x0, r4
    mov.l @r5, r4
.L_check_title_ptr_b:
    mov.l   .L_title_string_ptr_b, r5
    mov.l @r5, r0
    tst r0, r0
    bt      .L_check_title_null
    mov.l @r5, r4
.L_check_title_null:
    mov.l   .L_obj_entry_table, r6
    mov.l   .L_active_buf_slot, r5
    tst r4, r4
    bt      .L_write_default_DAY
    mov.b @r5, r3
    bra     .L_copy_title_from_ptr
    nop

    .global DAT_0601f6ba
DAT_0601f6ba:
    .2byte  0x2710
.L_geom_buf_base:
    .4byte  sym_0607ED90
.L_fn_hud_overlay_render_a:
    .4byte  hud_overlay_render
.L_fn_geom_normal_compute:
    .4byte  geom_normal_compute
.L_fn_geom_output_handler:
    .4byte  geom_output_handler
.L_render_active_flag:
    .4byte  sym_06078635
.L_geom_cmd_buffer:
    .4byte  sym_060877F0
.L_geom_cmd_src:
    .4byte  sym_060786A4
.L_render_dirty_flag:
    .4byte  sym_0605E0A1
.L_buf_index:
    .4byte  sym_0607EAD8
.L_prev_buf_index:
    .4byte  sym_0605E0A0
.L_buf_write_pos:
    .4byte  sym_0607ED88
.L_title_string_ptr_a:
    .4byte  sym_06085FFC
.L_title_string_ptr_b:
    .4byte  sym_06086000
.L_obj_entry_table:
    .4byte  sym_0605E06C
.L_active_buf_slot:
    .4byte  sym_060877D8
.L_copy_title_from_ptr:
    mov #0xB, r2
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @r4, r0
    mov.b r0, @(7, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @(1, r4), r0
    mov.b r0, @(8, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @(2, r4), r0
    mov.b r0, @(9, r3)
    bra     .L_title_written
    mov r0, r1
.L_write_default_DAY:
    mov.b @r5, r2
    mov #0xB, r3
    muls.w r3, r2
    sts macl, r2
    exts.b r2, r2
    add r6, r2
    mov #0x44, r0
    mov.b r0, @(7, r2)
    mov.b @r5, r3
    mov #0xB, r2
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov #0x41, r0
    mov.b r0, @(8, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov #0x59, r1
    mov r1, r0
    mov.b r0, @(9, r3)
.L_title_written:
    mov.l   .L_fn_hud_overlay_render_b, r3
    jsr @r3
    nop
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_geom_rotation_apply, r3
    jmp @r3
    mov.l @r15+, r14
.L_render_skip_epilog:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_hud_overlay_render_b:
    .4byte  hud_overlay_render
.L_fn_geom_rotation_apply:
    .4byte  geom_rotation_apply

    .global geom_output_finalize
    .type geom_output_finalize, @function
geom_output_finalize:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x40, r11
    mov.l r9, @-r15
    mov r11, r12
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0601f804, r13
    mov.l   .L_geom_buf_base_b, r14
    mov.l   .L_render_active_flag_b, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_finalize_epilog
    add #0x40, r12
    mov.l   .L_buf_index_b, r10
    mov.l @r10, r4
    add #0x1, r4
    bsr     .L_select_buffer
    extu.b r4, r4
    mov.l   .L_fn_hud_overlay_render_c, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_coord_calc, r3
    jsr @r3
    nop
    extu.b r0, r0
    tst r0, r0
    bf      .L_finalize_pad_buffer
    mov.l   .L_render_dirty_flag_b, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_copy_by_buf_index
    mov.l   .L_prev_buf_index_b, r3
    mov.l   .L_buf_index_b, r2
    mov.b @r3, r3
    mov.l @r2, r2
    extu.b r3, r3
    cmp/eq r2, r3
    bt      .L_finalize_pad_buffer
.L_copy_by_buf_index:
    mov.l   .L_copy_src_offset, r8
    mov.l   .L_fn_memcpy_long_idx, r9
    mov.l @r10, r0
    tst r0, r0
    bf      .L_try_buf_index_1
    mov.w   DAT_0601f806, r6
    mov r8, r5
    jsr @r9
    mov r14, r4
    bra     .L_finalize_pad_buffer
    nop
.L_try_buf_index_1:
    mov.l @r10, r0
    cmp/eq #0x1, r0
    bf      .L_try_buf_index_2
    mov r8, r5
    mov.w   .L_copy_len_buf1, r6
    jsr @r9
    mov r14, r4
    bra     .L_finalize_pad_buffer
    nop

    .global DAT_0601f804
DAT_0601f804:
    .2byte  0x2710

    .global DAT_0601f806
DAT_0601f806:
    .2byte  0x1900
.L_copy_len_buf1:
    .2byte  0x2328
    .2byte  0xFFFF
.L_geom_buf_base_b:
    .4byte  sym_0607ED90
.L_render_active_flag_b:
    .4byte  sym_06078635
.L_buf_index_b:
    .4byte  sym_0607EAD8
.L_fn_hud_overlay_render_c:
    .4byte  hud_overlay_render
.L_fn_geom_coord_calc:
    .4byte  geom_coord_calc
.L_render_dirty_flag_b:
    .4byte  sym_0605E0A1
.L_prev_buf_index_b:
    .4byte  sym_0605E0A0
.L_copy_src_offset:
    .4byte  0x002F8000
.L_fn_memcpy_long_idx:
    .4byte  memcpy_long_idx
.L_try_buf_index_2:
    mov.l @r10, r0
    cmp/eq #0x2, r0
    bf      .L_finalize_pad_buffer
    mov r13, r6
    mov r8, r5
    jsr @r9
    mov r14, r4
.L_finalize_pad_buffer:
    mov.l   .L_active_buf_slot_b, r4
    mov.l   .L_buf_size_table, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    cmp/hs r13, r4
    bt      .L_finalize_clear_dirty
.L_finalize_pad_loop:
    mov r4, r0
    extu.b r12, r3
    add #0x1, r4
    mov.b r11, @(r0, r14)
    mov r4, r0
    add #0x1, r4
    cmp/hs r13, r4
    bf/s    .L_finalize_pad_loop
    mov.b r3, @(r0, r14)
.L_finalize_clear_dirty:
    mov #0x0, r3
    mov.l   .L_render_dirty_clear, r2
    mov.b r3, @r2
.L_finalize_epilog:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_select_buffer:
    mov.l   .L_active_buf_slot_b, r3
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_buf_swap_flag, r6
    mov.l   .L_buf_base_ptr, r5
    tst r4, r4
    bf      .L_set_buf1
    mov.l   .L_buf0_base_addr, r3
    mov.l r3, @r5
    mov #0x0, r2
    bra     .L_buf_select_done
    mov.b r2, @r6
.L_set_buf1:
    mov.l   .L_buf1_base_addr, r2
    mov.l r2, @r5
    mov #0x1, r3
    mov.b r3, @r6
.L_buf_select_done:
    rts
    nop
    .2byte  0xFFFF
.L_active_buf_slot_b:
    .4byte  sym_060877D8
.L_buf_size_table:
    .4byte  sym_0604A5C0
.L_render_dirty_clear:
    .4byte  sym_0605E0A1
.L_buf_swap_flag:
    .4byte  sym_06087080
.L_buf_base_ptr:
    .4byte  sym_0605E098
.L_buf0_base_addr:
    .4byte  sym_060A0FA8
.L_buf1_base_addr:
    .4byte  sym_0607ED90

    .global sym_0601F8BC
sym_0601F8BC:
    rts
    nop

    .global geom_output_ctrl
    .type geom_output_ctrl, @function
geom_output_ctrl:
    sts.l pr, @-r15
    mov #0x0, r3
    mov.l   .L_output_dirty_flag, r2
    mov.b r3, @r2
    bsr     geom_render_util
    nop
    mov.l   .L_output_dirty_flag, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_output_dirty_path
    lds.l @r15+, pr
    rts
    mov #0x1, r0
.L_output_dirty_path:
    mov.l   .L_fn_pre_output_setup, r3
    jsr @r3
    nop
    bsr     geom_output_main
    nop
    mov.l   .L_fn_post_output_cleanup, r3
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
.L_output_dirty_flag:
    .4byte  sym_0605E05C
.L_fn_pre_output_setup:
    .4byte  sym_060149E0
.L_fn_post_output_cleanup:
    .4byte  sym_060149CC

    .global geom_output_dispatch
    .type geom_output_dispatch, @function
geom_output_dispatch:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_vdp2_status_reg, r3
    mov.w @r3, r2
    mov.w   DAT_0601f962, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_no_vdp2_pending
    mov.w   DAT_0601f964, r3
    mov r15, r6
    mov.w r3, @r15
    mov.l   .L_vdp2_vram_0x7FFFE, r4
    mov.l   .L_fn_tilemap_dma_update_a, r3
    jsr @r3
    mov #0x1, r5
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #0x1, r0
.L_no_vdp2_pending:
    bsr     geom_display_ctrl_a
    nop
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

    .global sym_0601F936
sym_0601F936:
    mov #0x0, r3

    .global resource_validator
    .type resource_validator, @function
resource_validator:
    mov.l r14, @-r15
    mov r3, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0601f962, r13
    mov.l   .L_display_ctrl_state, r14
    mov.l   .L_output_dirty_flag_b, r2
    mov.b r3, @r2
    bsr     .L_select_buffer
    nop
    mov.l   .L_fn_geom_vertex_process_b, r3
    jsr @r3
    nop
    mov.l   .L_output_dirty_flag_b, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_validator_active
    bra     .L_validator_epilog
    nop

    .global DAT_0601f962
DAT_0601f962:
    .2byte  0x0800

    .global DAT_0601f964
DAT_0601f964:
    .2byte  0x4210
    .2byte  0xFFFF
.L_vdp2_status_reg:
    .4byte  sym_06063D9A
.L_vdp2_vram_0x7FFFE:
    .4byte  0x25E7FFFE                  /* VDP2 VRAM +0x7FFFE */
.L_fn_tilemap_dma_update_a:
    .4byte  tilemap_dma_update
.L_display_ctrl_state:
    .4byte  sym_0605B6D8
.L_output_dirty_flag_b:
    .4byte  sym_0605E05C
.L_fn_geom_vertex_process_b:
    .4byte  geom_vertex_process
.L_validator_active:
    mov.l   .L_fp_min, r3
    mov.l @r14, r2
    or r3, r2
    mov.l   .L_fn_display_sync, r3
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_fn_display_sync, r3
    jsr @r3
    nop
    bsr     geom_output_main
    nop
    mov.l   .L_fp_0x4000_0000, r2
    mov.l @r14, r3
    or r2, r3
    mov.l r3, @r14
    mov.l   .L_vdp2_status_reg_b, r12
.L_wait_vdp2_sync:
    bsr     geom_display_ctrl_a
    nop
    mov.w @r12, r2
    extu.w r2, r2
    and r13, r2
    tst r2, r2
    bt      .L_not_yet_synced
    bra     .L_vdp2_synced
    nop
.L_not_yet_synced:
    bra     .L_wait_vdp2_sync
    nop
.L_vdp2_synced:
    bsr     geom_display_ctrl_a
    nop
    mov.l   .L_fp_min, r2
    mov.l @r14, r3
    or r2, r3
    mov.l r3, @r14
.L_validator_epilog:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global geom_output_main
    .type geom_output_main, @function
geom_output_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.w   DAT_0601fa26, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_fn_priority_setup, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_fn_priority_commit, r3
    jsr @r3
    nop
    mov.l   .L_scroll_config_table, r11
    mov.l   .L_fn_scroll_dispatch, r12
    mov.l   .L_render_mode, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_multi_mode_path
    mov #0x8, r7
    mov.l   .L_tilemap_data_size, r5
    mov.l   .L_vdp2_vram_0x72194, r4
    mov.l   .L_fn_dma_tilemap_copy, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_palette_src_data, r5
    mov.l   .L_vdp2_cram_0x600, r4
    mov.l   .L_fn_memcpy_word_idx, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_output_dirty_flag_c, r0
    mov.b @r0, r0
    bra     .L_mode1_dispatch
    extu.b r0, r0
.L_dispatch_mode4:
    mov.w   .L_scroll_offset_mode4, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    bra     .L_dispatch_scroll_single
    mov #0x0, r6

    .global DAT_0601fa26
DAT_0601fa26:
    .2byte  0x7C00
.L_scroll_offset_mode4:
    .2byte  0x02C0
    .2byte  0xFFFF
.L_fp_min:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_fn_display_sync:
    .4byte  sym_06026CE0
.L_fp_0x4000_0000:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_vdp2_status_reg_b:
    .4byte  sym_06063D9A
.L_fn_priority_setup:
    .4byte  sym_0602853E
.L_fn_priority_commit:
    .4byte  sym_06028560
.L_scroll_config_table:
    .4byte  sym_06063750
.L_fn_scroll_dispatch:
    .4byte  sym_06028400
.L_render_mode:
    .4byte  sym_06078644
.L_tilemap_data_size:
    .4byte  0x00017700
.L_vdp2_vram_0x72194:
    .4byte  0x25E72194                  /* VDP2 VRAM +0x72194 */
.L_fn_dma_tilemap_copy:
    .4byte  sym_0600511E
.L_palette_src_data:
    .4byte  sym_0604894C
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_fn_memcpy_word_idx:
    .4byte  memcpy_word_idx
.L_output_dirty_flag_c:
    .4byte  sym_0605E05C
.L_dispatch_mode8:
    mov.w   DAT_0601fac4, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_len_mode8, r6
.L_dispatch_scroll_single:
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_dispatch_modeC:
    mov.w   DAT_0601fac8, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_len_modeC, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_mode1_dispatch:
    cmp/eq #0x4, r0
    bt      .L_dispatch_mode4
    cmp/eq #0x8, r0
    bt      .L_dispatch_mode8
    cmp/eq #0xC, r0
    bt      .L_dispatch_modeC
    bra     .L_configure_channels
    nop
.L_multi_mode_path:
    mov.l   .L_palette_src_data_b, r5
    mov.l   .L_vdp2_cram_0x600_b, r4
    mov.l   .L_fn_memcpy_word_idx_b, r3
    jsr @r3
    mov #0x20, r6
    mov.w   .L_multi_scroll_offset_a, r8
    mov r8, r9
    add #0x8, r9
    mov.l   .L_fn_scroll_dispatch_b, r13
    mov.w   .L_multi_scroll_step, r14
    mov.l   .L_output_dirty_flag_d, r0
    mov.b @r0, r0
    bra     .L_multi_mode_dispatch
    extu.b r0, r0

    .global DAT_0601fac4
DAT_0601fac4:
    .2byte  0x02C8
.L_scroll_len_mode8:
    .2byte  0x0380

    .global DAT_0601fac8
DAT_0601fac8:
    .2byte  0x02D0
.L_scroll_len_modeC:
    .2byte  0x0400
.L_multi_scroll_offset_a:
    .2byte  0x0590
.L_multi_scroll_step:
    .2byte  0x0090
.L_palette_src_data_b:
    .4byte  sym_0605CD9C
.L_vdp2_cram_0x600_b:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_fn_memcpy_word_idx_b:
    .4byte  memcpy_word_idx
.L_fn_scroll_dispatch_b:
    .4byte  sym_060284AE
.L_output_dirty_flag_d:
    .4byte  sym_0605E05C
.L_multi_scroll_mode4:
    mov.l   .L_scroll_data_set_a, r10
    mov r14, r6
    mov.w   .L_scroll_ofs_0080, r5
    mov.l @r10, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0098, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0180, r5
    mov.l @(4, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(8, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0280, r5
    jsr @r13
    mov #0xC, r4
    mov r11, r9
    mov.w   DAT_0601fbae, r6
    add r8, r9
    mov.l @(4, r9), r7
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov.l @(12, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0400, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0500, r5
    mov.l @(16, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbb4, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0600, r5
    mov.l @(20, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(24, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0700, r5
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   .L_scroll_ofs_0730, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov.l @(28, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0800, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0900, r5
    mov.l @(32, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(36, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0A00, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0B00, r5
    mov.l @(40, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbc4, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0C80, r5
    mov.l   .L_scroll_data_extra, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbc8, r6
    bra     .L_final_scroll_dispatch
    mov.l @r9, r5
.L_scroll_ofs_0080:
    .2byte  0x0080
.L_scroll_ofs_0098:
    .2byte  0x0098
.L_scroll_ofs_0180:
    .2byte  0x0180
.L_scroll_ofs_0280:
    .2byte  0x0280

    .global DAT_0601fbae
DAT_0601fbae:
    .2byte  0x0296
.L_scroll_ofs_0400:
    .2byte  0x0400
.L_scroll_ofs_0500:
    .2byte  0x0500

    .global DAT_0601fbb4
DAT_0601fbb4:
    .2byte  0x0536
.L_scroll_ofs_0600:
    .2byte  0x0600
.L_scroll_ofs_0700:
    .2byte  0x0700
.L_scroll_ofs_0730:
    .2byte  0x0730
.L_scroll_ofs_0800:
    .2byte  0x0800
.L_scroll_ofs_0900:
    .2byte  0x0900
.L_scroll_ofs_0A00:
    .2byte  0x0A00
.L_scroll_ofs_0B00:
    .2byte  0x0B00

    .global DAT_0601fbc4
DAT_0601fbc4:
    .2byte  0x0B0E
.L_scroll_ofs_0C80:
    .2byte  0x0C80

    .global DAT_0601fbc8
DAT_0601fbc8:
    .2byte  0x0CD2
    .2byte  0xFFFF
.L_scroll_data_set_a:
    .4byte  sym_0605E0A4
.L_scroll_data_extra:
    .4byte  sym_0605E0E4
.L_multi_scroll_mode8:
    mov.l   .L_scroll_data_set_b, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0380, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0398, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0500_b, r5
    mov.l   .L_scroll_data_set_b2, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r10
    mov.w   DAT_0601fc94, r6
    add r8, r10
    mov.l @(4, r10), r7
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov.l   .L_scroll_data_set_b3, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0680, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   .L_scroll_ofs_06B2, r6
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0880, r5
    mov.l   .L_scroll_data_final, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   DAT_0601fc9c, r6
    mov.l @r10, r5
.L_final_scroll_dispatch:
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_multi_scroll_modeC:
    mov.l   .L_scroll_data_set_c, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0480, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0498, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0600_b, r5
    mov.l   .L_scroll_data_set_c2, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r10
    mov.w   .L_scroll_ofs_0620, r6
    add r8, r10
    mov.l @(4, r10), r7
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov.l   .L_scroll_data_final, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0800_b, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   .L_scroll_ofs_0852, r6
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_scroll_ofs_0380:
    .2byte  0x0380
.L_scroll_ofs_0398:
    .2byte  0x0398
.L_scroll_ofs_0500_b:
    .2byte  0x0500

    .global DAT_0601fc94
DAT_0601fc94:
    .2byte  0x051E
.L_scroll_ofs_0680:
    .2byte  0x0680
.L_scroll_ofs_06B2:
    .2byte  0x06B2
.L_scroll_ofs_0880:
    .2byte  0x0880

    .global DAT_0601fc9c
DAT_0601fc9c:
    .2byte  0x08D2
.L_scroll_ofs_0480:
    .2byte  0x0480
.L_scroll_ofs_0498:
    .2byte  0x0498
.L_scroll_ofs_0600_b:
    .2byte  0x0600
.L_scroll_ofs_0620:
    .2byte  0x0620
.L_scroll_ofs_0800_b:
    .2byte  0x0800
.L_scroll_ofs_0852:
    .2byte  0x0852
    .2byte  0xFFFF
.L_scroll_data_set_b:
    .4byte  sym_0605E0D0
.L_scroll_data_set_b2:
    .4byte  sym_0605E0D4
.L_scroll_data_set_b3:
    .4byte  sym_0605E0D8
.L_scroll_data_final:
    .4byte  sym_0605E0E4
.L_scroll_data_set_c:
    .4byte  sym_0605E0DC
.L_scroll_data_set_c2:
    .4byte  sym_0605E0E0
.L_multi_mode_dispatch:
    cmp/eq #0x4, r0
    bf      .L_try_multi_mode8_C
    bra     .L_multi_scroll_mode4
    nop
.L_try_multi_mode8_C:
    cmp/eq #0x8, r0
    bt      .L_multi_scroll_mode8
    cmp/eq #0xC, r0
    bt      .L_multi_scroll_modeC
.L_configure_channels:
    mov.l   .L_fn_channel_nibble_config, r14
    mov.w   .L_channel_config_0x100, r4
    jsr @r14
    mov #0x0, r5
    mov #0x0, r5
    jsr @r14
    mov #0x4, r4
    mov #0x0, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r5
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r5
    jsr @r14
    mov #0x1, r4
    mov r15, r6
    mov.l   .L_vdp2_vram_0x7FFFE_b, r4
    mov.l   .L_fn_tilemap_dma_update_b, r3
    add #0x4, r6
    jsr @r3
    mov #0x1, r5
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global geom_display_ctrl_a
    .type geom_display_ctrl_a, @function
geom_display_ctrl_a:
    sts.l pr, @-r15
    mov.l   .L_display_ctrl_state_b, r4
    mov.l   .L_fn_display_sync_b, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov #0x0, r4
    mov.l   .L_geom_counter_a, r3
    mov.l r4, @r3
    mov.l   .L_geom_counter_b, r3
    mov.l r4, @r3
    mov.l   .L_geom_counter_c, r3
    mov.l r4, @r3
    mov.l   .L_geom_counter_d, r3
    mov.l r4, @r3
    mov.l   .L_geom_counter_e, r3
    lds.l @r15+, pr
    rts
    mov.l r4, @r3
.L_channel_config_0x100:
    .2byte  0x0100
    .2byte  0xFFFF
.L_fn_channel_nibble_config:
    .4byte  channel_nibble_config
.L_vdp2_vram_0x7FFFE_b:
    .4byte  0x25E7FFFE                  /* VDP2 VRAM +0x7FFFE */
.L_fn_tilemap_dma_update_b:
    .4byte  tilemap_dma_update
.L_display_ctrl_state_b:
    .4byte  sym_0605B6D8
.L_fn_display_sync_b:
    .4byte  sym_06026CE0
.L_geom_counter_a:
    .4byte  sym_060620D0
.L_geom_counter_b:
    .4byte  sym_0605A000
.L_geom_counter_c:
    .4byte  sym_0605A004
.L_geom_counter_d:
    .4byte  sym_0605A008
.L_geom_counter_e:
    .4byte  sym_06059F44
