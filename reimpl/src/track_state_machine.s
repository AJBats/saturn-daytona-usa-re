
    .section .text.FUN_06017CEC


    .global track_state_machine
    .type track_state_machine, @function
track_state_machine:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l   .L_wram_offset_base, r8
    mov.l   .L_proj_state_base, r9
    mov #0x1, r10
    mov.l   .L_track_data_base, r13
    mov.l   .L_slot_table_base, r14
    mov.l   .L_car_array_ptr, r5
    mov.l @r5, r5
    mov.l   .L_course_config_ptr, r4
    mov.l @r4, r4
    mov.l   .L_seg_frame_ctr, r3
    mov.w @r3, r3
    add #0x1, r3
    mov.l   .L_seg_frame_ctr, r2
    mov.w r3, @r2
    mov.l   .L_seg_step_ctr, r1
    mov.w @r1, r1
    add #0x1, r1
    mov.l   .L_seg_step_ctr, r2
    mov.w r1, @r2
    mov.l   .L_max_lap_count, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.w   DAT_06017d92, r0
    mov.l @(r0, r5), r2
    cmp/hs r3, r2
    bf/s    .L_not_at_seg_end
    mov #0x3, r12
    mov.l   .L_course_config_alt_ptr, r4
    mov.w   DAT_06017d94, r0
    mov.l @r4, r4
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    mov.w   DAT_06017d96, r0
    bra     .L_store_seg_status
    add r14, r2
.L_not_at_seg_end:
    mov.w   DAT_06017d94, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.w   DAT_06017d98, r3
    mov r3, r0
.L_store_seg_status:
    mov.w r0, @(6, r2)
    mov.w   DAT_06017d9a, r6
    mov #0x5, r2
    mov.l   .L_seg_frame_ctr, r3
    mov.w @r3, r3
    cmp/gt r2, r3
    bt      .L_seg_reset_ptrs
    add r13, r6
    mov.w   .L_seg_pos_increment, r4
    mov.w   DAT_06017d94, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    bra     .L_check_step_flags
    nop

    .global DAT_06017d92
DAT_06017d92:
    .2byte  0x021C                       /* car struct position field offset */

    .global DAT_06017d94
DAT_06017d94:
    .2byte  0x1692                       /* track_data offset: primary slot index */

    .global DAT_06017d96
DAT_06017d96:
    .2byte  0x03BC                       /* seg status: at segment end */

    .global DAT_06017d98
DAT_06017d98:
    .2byte  0x03A8                       /* seg status: normal */

    .global DAT_06017d9a
DAT_06017d9a:
    .2byte  0x16AA                       /* track_data offset: secondary slot index */
.L_seg_pos_increment:
    .2byte  0x0090                       /* per-frame position increment */
    .2byte  0xFFFF                       /* alignment pad */
.L_wram_offset_base:
    .4byte  0x00088734                   /* WRAM offset base for chain A */
.L_proj_state_base:
    .4byte  sym_0605BE10                 /* projection state base (8 bytes) */
.L_track_data_base:
    .4byte  sym_060684EC                 /* track data table base */
.L_slot_table_base:
    .4byte  sym_06063F64                 /* per-slot data table base */
.L_car_array_ptr:
    .4byte  sym_0607E944                 /* car array base pointer */
.L_course_config_ptr:
    .4byte  sym_06089E28                 /* course config pointer */
.L_seg_frame_ctr:
    .4byte  sym_0605BE2C                 /* segment frame counter (16-bit) */
.L_seg_step_ctr:
    .4byte  sym_0605BE2E                 /* segment step counter (16-bit) */
.L_max_lap_count:
    .4byte  sym_06063F28                 /* maximum lap count */
.L_course_config_alt_ptr:
    .4byte  sym_06089E2C                 /* alternate course config pointer */
.L_seg_reset_ptrs:
    mov.w   DAT_06017ea6, r0
    add r13, r6
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l r4, @r2
    mov.w @r6, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l   .L_seg_base_alt, r2
    mov.l @r2, r2
    mov.l r2, @r3
    mov #0x0, r3
    mov.l   .L_seg_frame_ctr_reset, r2
    mov.w r3, @r2
.L_check_step_flags:
    mov.w   DAT_06017ea8, r7
    mov.l   .L_seg_step_ctr_ptr, r3
    mov r7, r6
    mov.w @r3, r3
    and r12, r3
    tst r3, r3
    bf/s    .L_advance_proj_entries
    add #-0x8, r6
    mov.l   .L_proj_param_x, r4
    mov.w   DAT_06017eaa, r0
    mov.l @r4, r2
    mov.w @(r0, r13), r3
    add #0x18, r0
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x12, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x10, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    add #0x10, r0
    add r13, r6
    add r13, r7
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #-0x2A, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.l   .L_proj_param_y, r4
    mov.w @r6, r3
    mov.l @r4, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @r7, r3
    mov.l @r4, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    add #0x12, r0
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x10, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    mov.l r2, @r3
    bra     .L_scroll_mode_select
    nop

    .global DAT_06017ea6
DAT_06017ea6:
    .2byte  0x1692                       /* track_data offset: primary slot index (dup) */

    .global DAT_06017ea8
DAT_06017ea8:
    .2byte  0x1718                       /* track_data offset C (proj entry group) */

    .global DAT_06017eaa
DAT_06017eaa:
    .2byte  0x1708                       /* track_data offset A (proj init group) */
.L_seg_base_alt:
    .4byte  sym_06089E30                 /* alternate segment base pointer */
.L_seg_frame_ctr_reset:
    .4byte  sym_0605BE2C                 /* segment frame counter (for reset) */
.L_seg_step_ctr_ptr:
    .4byte  sym_0605BE2E                 /* segment step counter (for flag test) */
.L_proj_param_x:
    .4byte  sym_06089E34                 /* projection param X */
.L_proj_param_y:
    .4byte  sym_06089E38                 /* projection param Y */
.L_advance_proj_entries:
    mov.w   DAT_06017fdc, r0
    add r13, r6
    add r13, r7
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @r7, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    add #0x18, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add #0x8, r0
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0xA, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    add #0x8, r0
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
.L_scroll_mode_select:
    mov.w   DAT_06017fde, r6
    mov.l   .L_proj_param_z, r4
    mov.l   .L_seg_step_flags, r0
    mov.w @r0, r0
    tst #0x10, r0
    bt      .L_scroll_no_offset
    add r13, r6
    mov.w @r6, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    mov.w   .L_scroll_mode_offset, r1
    add r1, r2
    mov.l r2, @r3
    bra     .L_check_section_zones
    nop
.L_scroll_no_offset:
    add r13, r6
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r4, r3
    mov.l r3, @r2
.L_check_section_zones:
    mov.w   DAT_06017fe2, r0
    mov.w   DAT_06017fe4, r3
    mov.l @(r0, r5), r4
    mov.l   .L_near_surface_flag, r5
    cmp/ge r3, r4
    bf      .L_clear_near_surface
    mov.w   DAT_06017fe6, r3
    cmp/gt r3, r4
    bt      .L_clear_near_surface
    extu.w r10, r3
    mov.w r3, @r5
    bra     .L_check_pit_lane
    nop
.L_clear_near_surface:
    mov #0x0, r2
    mov.w r2, @r5
.L_check_pit_lane:
    mov #0x4B, r3
    mov.l   .L_pit_lane_flag, r5
    cmp/ge r3, r4
    bf      .L_clear_pit_lane
    mov #0x57, r3
    cmp/gt r3, r4
    bt      .L_clear_pit_lane
    mov #0x4, r3
    mov.w r3, @r5
    bra     .L_check_obj_section
    nop

    .global DAT_06017fdc
DAT_06017fdc:
    .2byte  0x1708                       /* track_data offset A (dup for proj advance) */

    .global DAT_06017fde
DAT_06017fde:
    .2byte  0x16B8                       /* track_data offset: Z slot index */
.L_scroll_mode_offset:
    .2byte  0x0100                       /* scroll mode Z offset (+256) */

    .global DAT_06017fe2
DAT_06017fe2:
    .2byte  0x01EC                       /* car struct offset: road section index */

    .global DAT_06017fe4
DAT_06017fe4:
    .2byte  0x00A8                       /* near-surface zone minimum section */

    .global DAT_06017fe6
DAT_06017fe6:
    .2byte  0x00C1                       /* near-surface zone maximum section */
.L_proj_param_z:
    .4byte  sym_06089E40                 /* projection param Z */
.L_seg_step_flags:
    .4byte  sym_0605BE2E                 /* segment step counter (for scroll mode) */
.L_near_surface_flag:
    .4byte  sym_0605BE36                 /* near-surface zone flag (16-bit) */
.L_pit_lane_flag:
    .4byte  sym_0605BE38                 /* pit lane zone flag (16-bit) */
.L_clear_pit_lane:
    mov #0x0, r2
    mov.w r2, @r5
.L_check_obj_section:
    mov.w   DAT_060180fc, r3
    cmp/ge r3, r4
    bt      .L_above_min_section
    bra     .L_epilogue
    nop
.L_above_min_section:
    mov.w   DAT_060180fe, r3
    cmp/gt r3, r4
    bf      .L_in_obj_section_range
    bra     .L_epilogue
    nop
.L_in_obj_section_range:
    mov.w   .L_proj_delta_x, r3
    mov.l @r9, r2
    add r3, r2
    mov.l r2, @r9
    mov.w   DAT_06018102, r3
    mov.l @(4, r9), r2
    add r3, r2
    mov.l r2, @(4, r9)
    mov #0x0, r11
    mov.l   .L_mode_scale_tbl, r3
    mov.l r3, @(4, r15)
.L_obj_loop_top:
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    nop
    extu.b r11, r6
    mov.l   .L_track_obj_array, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    extu.b r6, r6
    add r2, r6
    mov.l r6, @r15
    mov.l @(8, r6), r6
    mov.l @r15, r5
    mov.l @r15, r4
    mov.l   .L_fn_transform_dispatch, r3
    neg r6, r6
    mov.l @(4, r5), r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_mask_0xC000, r4
    mov.l   .L_fn_rot_y, r3
    jsr @r3
    nop
    mov r11, r0
    mov r11, r3
    mov.w   DAT_06018104, r2
    and r10, r0
    and r12, r3
    shll2 r0
    mul.l r2, r3
    mov.l @(r0, r9), r4
    sts macl, r2
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    add r2, r4
    mov #0xC, r5
    mov.l   .L_wram_low, r2
    mov.l r2, @r15
    mov r2, r4
    mov.l   .L_fn_chain_a, r3
    jsr @r3
    add r8, r4
    mov r12, r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_chain_b_offset, r3
    add r3, r4
    mov.l   .L_fn_chain_b, r3
    jsr @r3
    mov.w @r5, r5
    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    nop
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    add #0x1, r11
    extu.b r11, r6
    mov.l   .L_track_obj_array, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    extu.b r6, r6
    add r2, r6
    mov.l r6, @(8, r15)
    mov.l @(8, r6), r6
    mov.l @(8, r15), r5
    mov.l @(8, r15), r4
    mov.l   .L_fn_transform_dispatch, r3
    neg r6, r6
    mov.l @(4, r5), r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_mask_0xC000, r4
    mov.l   .L_fn_rot_y, r3
    jsr @r3
    nop
    mov r11, r0
    mov r11, r3
    mov.w   DAT_06018104, r2
    and r10, r0
    and r12, r3
    shll2 r0
    mul.l r2, r3
    mov.l @(r0, r9), r4
    sts macl, r2
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    add r2, r4
    mov #0xC, r5
    mov.l @r15, r4
    mov.l   .L_fn_chain_a, r3
    jsr @r3
    add r8, r4
    mov r12, r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_chain_b_offset, r3
    add r3, r4
    mov.l   .L_fn_chain_b, r3
    jsr @r3
    mov.w @r5, r5
    bra     .L_obj_loop_finalize
    nop

    .global DAT_060180fc
DAT_060180fc:
    .2byte  0x0089                       /* obj section range minimum */

    .global DAT_060180fe
DAT_060180fe:
    .2byte  0x00B6                       /* obj section range maximum */
.L_proj_delta_x:
    .2byte  0x0333                       /* per-frame proj X delta */

    .global DAT_06018102
DAT_06018102:
    .2byte  0x0666                       /* per-frame proj Y delta */

    .global DAT_06018104
DAT_06018104:
    .2byte  0x1555                       /* Z rotation stride multiplier */
    .2byte  0xFFFF                       /* alignment pad */
.L_mode_scale_tbl:
    .4byte  sym_06089E98                 /* per-mode scale factor table (16-bit) */
.L_fn_pre_transform:
    .4byte  sym_06026DBC                 /* pre-transform setup function */
.L_track_obj_array:
    .4byte  sym_06048078                 /* track object array (12 bytes/entry) */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                 /* transform dispatch function */
.L_mask_0xC000:
    .4byte  0x0000C000                   /* bits 15:14 mask (Y rotation) */
.L_fn_rot_y:
    .4byte  mat_rot_y                    /* Y-axis matrix rotation */
.L_fn_rot_z:
    .4byte  mat_rot_z                    /* Z-axis matrix rotation */
.L_wram_low:
    .4byte  0x00200000                   /* Work RAM Low base */
.L_fn_chain_a:
    .4byte  sym_06031D8C                 /* transform chain A (vector copy) */
.L_chain_b_offset:
    .4byte  0x000887C4                   /* WRAM offset for chain B source */
.L_fn_chain_b:
    .4byte  sym_06031A28                 /* transform chain B (scaled copy) */
.L_fn_camera_finalize:
    .4byte  sym_06026DF8                 /* camera state finalization */
.L_obj_loop_finalize:
    .byte   0xD3, 0x38    /* mov.l .L_pool_0601821C, r3 */
    jsr @r3
    nop
    add #0x1, r11
    mov #0xD, r2
    cmp/gt r2, r11
    bt      .L_epilogue
    bra     .L_obj_loop_top
    nop
.L_epilogue:
    .byte   0xD3, 0x35    /* mov.l .L_pool_06018220, r3 */
    jsr @r3
    nop
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x89    /* bra 0x06018278 (external tail call) */
    mov.l @r15+, r14
