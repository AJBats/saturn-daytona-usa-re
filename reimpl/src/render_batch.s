
    .section .text.FUN_0600D31C


    .global physics_calc_dispatch
    .type physics_calc_dispatch, @function
physics_calc_dispatch:
    sts.l pr, @-r15
    mov.l   .L_wram_flag_ptr, r3
    mov.l   .L_wram_low, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bf      .L_skip_accel
    bsr     .L_sort_cars_by_dist
    nop
.L_skip_accel:
    bsr     .L_link_list_setup
    nop
    bra     render_batch
    lds.l @r15+, pr

    .global sym_0600D336
sym_0600D336:
    mov.l   .L_car_array_base, r5
    mov.w   .L_car_stride, r3
    mov.l   .L_wram_flag_ptr, r2
    mov r5, r4
    mov.l @r2, r2
    add r3, r5
    mov.l   .L_wram_low, r3
    and r3, r2
    tst r2, r2
    bf      .L_compare_done
    mov #0x1, r7
    mov.w   .L_dist_compare_off, r0
    mov.l @(r0, r4), r3
    mov.l @(r0, r5), r2
    cmp/ge r2, r3
    bf/s    .L_swap_rank
    mov #0x0, r6
    mov.w   .L_rank_offset, r0
    mov.l r6, @(r0, r4)
    bra     .L_compare_done
    mov.l r7, @(r0, r5)
.L_swap_rank:
    mov.w   .L_rank_offset, r0
    mov.l r7, @(r0, r4)
    mov.l r6, @(r0, r5)
.L_compare_done:
    rts
    nop
.L_car_stride:
    .2byte  0x0268
.L_dist_compare_off:
    .2byte  0x01F4
.L_rank_offset:
    .2byte  0x0224
.L_wram_flag_ptr:
    .4byte  sym_0607EBC4
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_car_array_base:
    .4byte  sym_06078900
.L_sort_cars_by_dist:
    mov.l r13, @-r15
    mov #0x1, r13
    mov.l r12, @-r15
    mov.l   .L_car_ptr_array, r4
    mov.w   DAT_0600d404, r0
    mov.l   .L_car_count, r5
    mov.l @r4, r1
    mov.l @r5, r5
    mov.l @(r0, r1), r1
    cmp/hi r13, r5
    bf/s    .L_sort_done_a
    mov #0x0, r12
.L_sort_loop_a:
    mov.l @(4, r4), r6
    mov.w   DAT_0600d404, r0
    mov.l @(r0, r6), r7
    cmp/gt r1, r7
    bf      .L_no_swap_a
    mov.l @r4, r7
    mov.l r6, @r4
    bra     .L_store_rank_a
    mov.l r7, @(4, r4)
.L_no_swap_a:
    mov r7, r1
.L_store_rank_a:
    mov.l @r4+, r3
    mov r12, r2
    mov.w   DAT_0600d406, r0
    add #-0x1, r5
    mov.l r2, @(r0, r3)
    cmp/hi r13, r5
    bt/s    .L_sort_loop_a
    add #0x1, r12
.L_sort_done_a:
    mov.l @r4, r2
    mov.w   DAT_0600d406, r0
    mov.l r12, @(r0, r2)
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13
.L_link_list_setup:
    mov.l r13, @-r15
    mov.l   .L_secondary_array, r4
    mov.w   .L_distance_offset, r0
    mov.l   .L_sort_pivot, r3
    mov.l @r4, r5
    mov.l @r3, r3
    mov.l @(r0, r5), r5
    cmp/hi r5, r3
    bf/s    .L_sort_secondary
    mov #0x1, r13
    bra     vehicle_state_update
    mov.l @r15+, r13
.L_sort_secondary:
    mov.l   .L_car_count, r6
    mov.l @r6, r6
    cmp/hi r13, r6
    bf      .L_finalize_list
.L_sort_loop_b:
    mov.l @(4, r4), r7
    mov.w   .L_distance_offset, r0
    mov.l @(r0, r7), r1
    cmp/hi r5, r1
    bf      .L_no_swap_b
    mov.l @r4, r1
    mov.l r7, @r4
    bra     .L_store_rank_b
    mov.l r1, @(4, r4)
.L_no_swap_b:
    mov r1, r5
.L_store_rank_b:
    add #-0x1, r6
    cmp/hi r13, r6
    bt/s    .L_sort_loop_b
    add #0x4, r4
.L_finalize_list:
    bra     .L_build_linked_list
    mov.l @r15+, r13

    .global DAT_0600d404
DAT_0600d404:
    .2byte  0x01F4

    .global DAT_0600d406
DAT_0600d406:
    .2byte  0x0224
.L_distance_offset:
    .2byte  0x01EC
    .2byte  0xFFFF
.L_car_ptr_array:
    .4byte  sym_0607E94C
.L_car_count:
    .4byte  sym_0607EA98
.L_secondary_array:
    .4byte  sym_0607E9EC
.L_sort_pivot:
    .4byte  sym_060786B4

    .global vehicle_state_update
    .type vehicle_state_update, @function
vehicle_state_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_sort_pivot_b, r12
    mov.l   .L_secondary_array_b, r13
    mov #0x1, r14
    bra     .L_find_pivot
    mov r14, r4
.L_next_candidate:
    add #0x1, r4
.L_find_pivot:
    mov r4, r0
    mov.l @r12, r2
    shll2 r0
    mov.l @(r0, r13), r3
    mov.w   DAT_0600d4a6, r0
    mov.l @(r0, r3), r3
    cmp/hi r3, r2
    bf      .L_pivot_found
    mov #0x3, r2
    cmp/hs r2, r4
    bf      .L_next_candidate
.L_pivot_found:
    mov.l   .L_swap_buffer, r7
    mov r4, r5
    mov #0x0, r2
    cmp/hi r2, r5
    bf/s    .L_copy_before_done
    mov r13, r6
.L_copy_before:
    mov.l @r6+, r1
    add #-0x1, r5
    mov #0x0, r3
    mov.l r1, @r7
    cmp/hi r3, r5
    bt/s    .L_copy_before
    add #0x4, r7
.L_copy_before_done:
    mov.l   .L_car_count_b, r5
    mov.l @r5, r5
    sub r4, r5
    cmp/hi r14, r5
    bf/s    .L_copy_after_done
    mov r13, r7
.L_copy_after:
    mov r7, r2
    mov.l @r6+, r1
    add #-0x1, r5
    add #0x4, r7
    cmp/hi r14, r5
    bt/s    .L_copy_after
    mov.l r1, @r2
.L_copy_after_done:
    mov.l   .L_swap_buffer, r5
    mov #0x0, r2
    cmp/hi r2, r4
    bf      .L_state_update_done
.L_copy_swap:
    mov.l @r5+, r1
    add #-0x1, r4
    mov #0x0, r3
    mov.l r1, @r7
    cmp/hi r3, r4
    bt/s    .L_copy_swap
    add #0x4, r7
.L_state_update_done:
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     .L_build_linked_list
    mov.l @r15+, r14
.L_build_linked_list:
    add #-0x4, r15
    mov.l   .L_car_count_b, r7
    mov.l   .L_secondary_array_b, r5
    mov r5, r4
    add #0x4, r4
    mov.l r4, @r15
    bra     .L_link_check
    mov #0x1, r6

    .global DAT_0600d4a6
DAT_0600d4a6:
    .2byte  0x01EC
.L_sort_pivot_b:
    .4byte  sym_060786B4
.L_secondary_array_b:
    .4byte  sym_0607E9EC
.L_swap_buffer:
    .4byte  sym_0607EA8C
.L_car_count_b:
    .4byte  sym_0607EA98
.L_link_loop:
    mov.l @r4, r2
    mov r4, r3
    add #-0x4, r3
    mov.l @r3, r1
    mov.w   .L_link_next_offset, r0
    mov.l r1, @(r0, r2)
    mov.l @r4, r3
    mov.l @(4, r4), r2
    add #0x4, r0
    mov.l r2, @(r0, r3)
    add #0x4, r4
    add #0x1, r6
.L_link_check:
    mov.l @r7, r3
    add #-0x1, r3
    cmp/hs r3, r6
    bf      .L_link_loop
    mov.l @r5, r3
    mov.l @r4, r2
    mov.w   .L_link_next_offset, r0
    mov.l r2, @(r0, r3)
    mov.l @r5, r3
    mov.l @r15, r2
    mov.w   DAT_0600d536, r0
    mov.l @r2, r1
    mov r4, r2
    mov.l r1, @(r0, r3)
    add #-0x4, r2
    mov.l @r4, r3
    add #-0x4, r0
    mov.l @r2, r1
    mov.l r1, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l @r5, r2
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    add #-0x50, r0
    mov.l   .L_sort_pivot_c, r1
    mov.l @(r0, r3), r2
    mov.l r2, @r1
    rts
    add #0x4, r15

    .global render_batch
    .type render_batch, @function
render_batch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_player_car_ptr, r9
    mov.l   .L_car_count_c, r11
    mov #0x1, r13
    mov #0x0, r14
    mov.l   .L_render_flag, r3
    mov.l r14, @r3
    mov.l r14, @(8, r15)
    mov r14, r8
    mov.l   .L_car_ptr_array_b, r6
    bra     .L_clear_check
    mov r14, r5
.L_link_next_offset:
    .2byte  0x0238

    .global DAT_0600d536
DAT_0600d536:
    .2byte  0x023C
.L_sort_pivot_c:
    .4byte  sym_060786B4
.L_player_car_ptr:
    .4byte  sym_0607E944
.L_car_count_c:
    .4byte  sym_0607EA98
.L_render_flag:
    .4byte  sym_0607EBDC
.L_car_ptr_array_b:
    .4byte  sym_0607E94C
.L_clear_car_loop:
    mov.l @r6+, r4
    mov.w   DAT_0600d5d6, r0
    mov.l r14, @(r0, r4)
    mov r14, r0
    mov.w   .L_bf_cmd_08, r1
    mov.l   .L_fn_bitfield_rw, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_bf_cmd_09, r1
    mov.l   .L_fn_bitfield_rw, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_bf_cmd_0A, r1
    mov.l   .L_fn_bitfield_rw, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_bf_cmd_07, r1
    mov.l   .L_fn_bitfield_rw, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_bf_cmd_06, r1
    mov.l   .L_fn_bitfield_rw, r3
    jsr @r3
    mov r4, r2
    add #0x1, r5
.L_clear_check:
    mov.l @r11, r2
    cmp/hs r2, r5
    bf      .L_clear_car_loop
    mov.l @r9, r4
    mov.l   .L_wram_flag_ptr_b, r2
    mov.l   .L_flag_mask, r3
    mov r4, r12
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bf/s    .L_use_car_heading
    mov r4, r10
    mov r15, r6
    mov r15, r5
    mov.l   .L_cam_heading_ptr, r4
    mov.l   .L_fn_sincos, r3
    add #0x4, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_fp_scale_7, r5
    mov.l @r15, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    neg r4, r4
    mov.l r0, @r15
    mov.l   .L_fp_scale_7, r5
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l r0, @(4, r15)
    mov.l   .L_cam_pos_base, r4
    mov.l @r4, r3
    mov.l @r15, r2
    add r3, r2
    mov.l r2, @r15
    mov.l @(8, r4), r3
    mov.l @(4, r15), r2
    add r3, r2
    bra     .L_store_cam_offset
    nop

    .global DAT_0600d5d6
DAT_0600d5d6:
    .2byte  0x0218
.L_bf_cmd_08:
    .2byte  0x0801
.L_bf_cmd_09:
    .2byte  0x0901
.L_bf_cmd_0A:
    .2byte  0x0A01
.L_bf_cmd_07:
    .2byte  0x0701
.L_bf_cmd_06:
    .2byte  0x0601
    .2byte  0xFFFF
.L_fn_bitfield_rw:
    .4byte  sym_06034F78
.L_wram_flag_ptr_b:
    .4byte  sym_0607EBC4
.L_flag_mask:
    .4byte  0x10060000
.L_cam_heading_ptr:
    .4byte  sym_06063EF0
.L_fn_sincos:
    .4byte  sincos_pair
.L_fp_scale_7:
    .4byte  0x00070000
.L_fn_fpmul:
    .4byte  fpmul
.L_cam_pos_base:
    .4byte  sym_06063DF8
.L_use_car_heading:
    mov r15, r6
    mov r15, r5
    mov.l @r9, r4
    mov.l   .L_fn_sincos_b, r3
    add #0x4, r6
    jsr @r3
    mov.l @(32, r4), r4
    mov.l   .L_fp_scale_5, r5
    mov.l @r15, r4
    mov.l   .L_fn_fpmul_b, r3
    jsr @r3
    neg r4, r4
    mov.l r0, @r15
    mov.l   .L_fp_scale_5, r5
    mov.l   .L_fn_fpmul_b, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l r0, @(4, r15)
    mov.l @r9, r3
    mov.l @(16, r3), r2
    mov.l @r15, r3
    add r2, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @(24, r2), r3
    mov.l @(4, r15), r2
    add r3, r2
.L_store_cam_offset:
    mov.l r2, @(4, r15)
    mov.l @r11, r4
    cmp/hi r13, r4
    bf      .L_per_car_done
.L_per_car_loop:
    mov.w   .L_link_next_off_b, r0
    mov.l @(r0, r12), r12
    add #0x4, r0
    mov.l @(r0, r10), r10
    add #-0x24, r0
    mov.l r4, @(r0, r12)
    mov.l r4, @(r0, r10)
    mov.l @(16, r12), r6
    mov.l @r15, r5
    sub r6, r5
    cmp/pz r5
    bt      .L_dx_positive
    mov.l @r15, r2
    mov r6, r3
    sub r2, r3
    bra     .L_dx_done
    nop
.L_dx_positive:
    mov r5, r3
.L_dx_done:
    mov.l @(24, r12), r2
    mov.l r2, @(12, r15)
    mov.l @(4, r15), r7
    sub r2, r7
    cmp/pz r7
    bt      .L_dz_positive
    mov.l @(12, r15), r1
    mov.l @(4, r15), r0
    bra     .L_dz_done
    sub r0, r1
.L_dz_positive:
    mov r7, r1
.L_dz_done:
    mov r3, r5
    add r1, r5
    mov.l   .L_lod_close, r3
    cmp/ge r3, r5
    bt      .L_not_close
    mov.l @(8, r15), r3
    mov #0x3, r2
    cmp/ge r2, r3
    bt      .L_not_close
    mov r13, r0
    mov.w   .L_bf_cmd_08_b, r1
    mov.l   .L_fn_bitfield_rw_b, r3
    jsr @r3
    mov r12, r2
    mov.l @(8, r15), r2
    add #0x1, r2
    bra     .L_lod_done
    mov.l r2, @(8, r15)
.L_not_close:
    mov.l   .L_lod_medium, r2
    cmp/ge r2, r5
    bt      .L_not_medium
    mov #0x7, r2
    cmp/ge r2, r8
    bt      .L_not_medium
    mov r13, r0
    mov.w   .L_bf_cmd_09_b, r1
    mov.l   .L_fn_bitfield_rw_b, r3
    jsr @r3
    mov r12, r2
    bra     .L_lod_done
    add #0x1, r8
.L_link_next_off_b:
    .2byte  0x0238
.L_bf_cmd_08_b:
    .2byte  0x0801
.L_bf_cmd_09_b:
    .2byte  0x0901
.L_fn_sincos_b:
    .4byte  sincos_pair
.L_fp_scale_5:
    .4byte  0x00050000
.L_fn_fpmul_b:
    .4byte  fpmul
.L_lod_close:
    .4byte  0x000C0000
.L_fn_bitfield_rw_b:
    .4byte  sym_06034F78
.L_lod_medium:
    .4byte  0x00230000
.L_not_medium:
    mov.l   .L_lod_far, r2
    cmp/ge r2, r5
    bt      .L_lod_done
    mov r13, r0
    mov.w   .L_bf_cmd_0A_b, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    jsr @r3
    mov r12, r2
.L_lod_done:
    add #-0x1, r4
    cmp/hi r13, r4
    bt      .L_per_car_loop
.L_per_car_done:
    mov.l @r9, r2
    mov.w   .L_bf_cmd_08_c, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    jsr @r3
    mov r13, r0
    mov.l @r9, r7
    mov.w   DAT_0600d76a, r0
    mov.l @(r0, r7), r7
    mov.l   .L_render_obj_base, r4
    bra     .L_final_check
    mov r13, r6
.L_final_pass:
    mov.w   DAT_0600d76a, r0
    mov.w   .L_bf_cmd_07_b, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    mov.l @(r0, r4), r5
    mov r14, r0
    sub r7, r5
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_bf_cmd_06_b, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    jsr @r3
    mov r4, r2
    mov #0x3, r2
    cmp/ge r2, r5
    bt      .L_check_negative
    cmp/pl r5
    bf      .L_check_negative
    mov r13, r0
    mov.w   .L_bf_cmd_07_b, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    jsr @r3
    mov r4, r2
.L_check_negative:
    cmp/pl r5
    bt      .L_final_next
    mov #-0x2, r3
    cmp/gt r3, r5
    bf      .L_final_next
    mov r13, r0
    mov.w   .L_bf_cmd_06_b, r1
    mov.l   .L_fn_bitfield_rw_c, r3
    jsr @r3
    mov r4, r2
.L_final_next:
    add #0x1, r6
    mov.w   .L_car_stride_b, r2
    add r2, r4
.L_final_check:
    mov.l @r11, r3
    cmp/hs r3, r6
    bf      .L_final_pass
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_bf_cmd_0A_b:
    .2byte  0x0A01
.L_bf_cmd_08_c:
    .2byte  0x0801

    .global DAT_0600d76a
DAT_0600d76a:
    .2byte  0x01EC
.L_bf_cmd_07_b:
    .2byte  0x0701
.L_bf_cmd_06_b:
    .2byte  0x0601
.L_car_stride_b:
    .2byte  0x0268
    .2byte  0xFFFF
.L_lod_far:
    .4byte  0x00780000
.L_fn_bitfield_rw_c:
    .4byte  sym_06034F78
.L_render_obj_base:
    .4byte  sym_06078B68
