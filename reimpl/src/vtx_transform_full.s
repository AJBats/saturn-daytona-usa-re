
    .section .text.FUN_0602D934


    .global vtx_transform_full
    .type vtx_transform_full, @function
vtx_transform_full:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov r14, r0
    mov.l @(0, r0), r10
    mov.l   .L_dir_flag_mask, r11
    tst r10, r11
    bt      .L_sub_direction
    add r1, r5
    bra     .L_store_position
    nop
    .2byte  0x024C
    .4byte  0x0000000F
    .4byte  sym_0602ECCC
.L_dir_flag_mask:
    .4byte  0x00000300
.L_sub_direction:
    sub r1, r5
.L_store_position:
    mov.l r5, @(48, r0)
    mov.l r5, @(32, r0)
    mov.w   .L_off_angular_vel, r1
    mov.l @(r0, r1), r4
    mov.l r4, @(40, r0)
    neg r4, r4
    mov.w   .L_off_scene_idx, r1
    mov.w @(r0, r1), r2
    mov.l   .L_scene_scale_tbl, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r5
    mov.l @(12, r0), r2
    dmuls.l r2, r5
    mov.l @(8, r0), r7
    sts mach, r2
    sts macl, r5
    xtrct r2, r5
    mov.l r5, @(12, r0)
    mov #0x28, r2
    cmp/gt r2, r7
    bt      .L_scale_ready
    mov.l   .L_default_scale, r5
.L_scale_ready:
    mov.l @(16, r0), r6
    mov.l @(24, r0), r7
    mov.l r6, @(56, r0)
    mov.l r7, @(60, r0)
    mov r4, r9
    mov r5, r1
    mov.l   .L_fn_cos, r0
    jsr @r0
    nop
    mov r0, r8
    mov r9, r4
    mov.l   .L_fn_sin, r0
    jsr @r0
    nop
    dmuls.l r0, r5
    mov r14, r0
    mov.l   .L_off_rot_x_delta, r10
    sts mach, r11
    sts macl, r5
    xtrct r11, r5
    mov.l r5, @(r0, r10)
    add r5, r6
    mov.l r6, @(16, r0)
    dmuls.l r8, r1
    mov.l   .L_off_rot_z_delta, r10
    sts mach, r8
    sts macl, r1
    xtrct r8, r1
    mov.l r1, @(r0, r10)
    add r1, r7
    mov.l r7, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
.L_off_angular_vel:
    .2byte  0x0248                  /* car struct +0x248: angular velocity */
.L_off_scene_idx:
    .2byte  0x0250                  /* car struct +0x250: scene table index */
.L_scene_scale_tbl:
    .4byte  sym_0602E8B8            /* scene scale lookup table (main_scene_render) */
.L_default_scale:
    .4byte  0x00006AAA              /* default scale when frame_count <= 0x28 */
.L_fn_cos:
    .4byte  cos_lookup              /* cosine lookup function */
.L_fn_sin:
    .4byte  sin_lookup              /* sine lookup function */
.L_off_rot_x_delta:
    .4byte  0x0000018C              /* car struct +0x18C: X rotation delta */
.L_off_rot_z_delta:
    .4byte  0x00000190              /* car struct +0x190: Z rotation delta */
    .4byte  0x000B0009              /* (padding / out-of-TU data) */

    .global sym_0602D9F0
sym_0602D9F0:
    mov.l   .L_car_array_ptr, r0
    mov.l @r0, r0
    mov.l   .L_max_lap_count, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.l   .L_off_lap_field, r4
    mov.l @(r0, r4), r4
    cmp/ge r3, r4
    bt      .L_exit_store_mode
    mov.l   .L_race_end_state, r3
    mov.l @r3, r3
    mov.l   .L_const_one, r4
    cmp/eq r4, r3
    bf      .L_check_terrain
    mov.l   .L_off_position_z, r1
    mov.l @(r0, r1), r3
    mov.l   .L_mask_byte3, r4
    cmp/ge r4, r3
    bt      .L_exit_store_mode
.L_check_terrain:
    mov.l   .L_off_terrain_type, r1
    mov.l @(r0, r1), r1
    mov.l   .L_const_zero, r3
    cmp/eq r3, r1
    bf      .L_exit_store_mode
    mov.w   .L_off_clip_flags_a, r1
    mov.w @(r0, r1), r3
    mov.w   .L_off_clip_flags_b, r1
    mov.w @(r0, r1), r4
    mov.w   .L_off_visibility, r1
    mov.l @(r0, r1), r5
    or r3, r4
    or r4, r5
    tst r5, r5
    bf      .L_exit_store_mode
    mov.w   .L_off_vtx_bounds, r1
    add r0, r1
    mov.l @(0, r1), r2
    mov.l @(4, r1), r3
    mov.l @(8, r1), r4
    mov.l @(12, r1), r5
    mov.w   .L_bounds_mask, r6
    and r2, r3
    and r4, r5
    and r3, r5
    cmp/eq r5, r6
    bf      .L_exit_store_mode
    mov.l   .L_cur_car_ptr, r0
    mov.l @r0, r0
    mov.w   .L_off_track_section, r1
    mov.l @(r0, r1), r4
    mov.l @(40, r0), r3
    sub r4, r3
    exts.w r3, r3
    mov.w   .L_z_half_range, r5
    add r5, r3
    mov.w   .L_z_dist_min, r5
    cmp/ge r3, r5
    bt      .L_exit_store_mode
    mov.w   .L_z_dist_max, r5
    cmp/ge r3, r5
    bf      .L_exit_store_mode
    mov.l @(0, r0), r2
    mov.l   .L_flag_bit3, r3
    tst r3, r2
    bf      .L_reject_store_neg
    mov.l   .L_race_mode_byte, r1
    mov.b @r1, r1
    tst r1, r1
    bf      .L_reject_store_neg
    mov.l @(0, r0), r2
    mov.l   .L_fp_two, r3
    or r3, r2
    mov.l r2, @(0, r0)
    mov.l   .L_checkpoint_ctr, r1
    mov.w   .L_checkpoint_val, r2
    mov.l r2, @r1
    mov.l   .L_race_complete_flag, r1
    mov.w   .L_one, r2
    mov.l r2, @r1
.L_exit_store_mode:
    mov.l   .L_race_mode_byte, r1
    mov.l   .L_const_zero, r2
    mov.b r2, @r1
    rts
    nop
.L_off_clip_flags_a:
    .2byte  0x0150                  /* car struct +0x150: clip flags A */
.L_off_clip_flags_b:
    .2byte  0x0250                  /* car struct +0x250: clip flags B */
.L_off_visibility:
    .2byte  0x00B8                  /* car struct +0xB8: visibility flags */
.L_off_vtx_bounds:
    .2byte  0x0120                  /* car struct +0x120: vertex bounding box */
.L_bounds_mask:
    .2byte  0x0041                  /* required AND result for all-in-view */
.L_off_track_section:
    .2byte  0x025C                  /* car struct +0x25C: track section Z */
.L_z_half_range:
    .2byte  0x3FFF                  /* bias to shift signed delta positive */
.L_z_dist_min:
    .2byte  0x2800                  /* minimum biased Z distance */
.L_z_dist_max:
    .2byte  0x47FF                  /* maximum biased Z distance */
.L_checkpoint_val:
    .2byte  0x003C                  /* 60 (checkpoint timer frames) */
.L_one:
    .2byte  0x0001                  /* 1 (race complete flag value) */
    .2byte  0x0000                  /* (alignment padding) */
.L_car_array_ptr:
    .4byte  sym_0607E944            /* car array base pointer */
.L_max_lap_count:
    .4byte  sym_06063F28            /* maximum lap count for current race */
.L_off_lap_field:
    .4byte  0x00000228              /* car struct +0x228: current lap */
.L_race_end_state:
    .4byte  sym_0607EAD8            /* race end state (0/1/2) */
.L_const_one:
    .4byte  0x00000001              /* constant 1 */
.L_off_position_z:
    .4byte  0x00000018              /* car struct +0x18: Z position */
.L_mask_byte3:
    .4byte  0xFF000000              /* upper byte mask (Z out-of-range guard) */
.L_off_terrain_type:
    .4byte  0x000001BC              /* car struct +0x1BC: terrain type */
.L_const_zero:
    .4byte  0x00000000              /* constant 0 */
.L_cur_car_ptr:
    .4byte  sym_0607E940            /* current car struct pointer */
.L_flag_bit3:
    .4byte  0x00000008              /* bit 3 flag mask */
.L_race_mode_byte:
    .4byte  sym_06083260            /* race mode byte */
.L_fp_two:
    .4byte  0x00020000              /* bit 17 flag (0x20000) */
.L_checkpoint_ctr:
    .4byte  sym_0607EAC8            /* checkpoint counter (32-bit) */
.L_race_complete_flag:
    .4byte  sym_0605A1C4            /* race complete flag (32-bit) */
.L_reject_store_neg:
    mov.l   .L_race_mode_byte_b, r1
    mov.l   .L_const_neg1, r2
    mov.b r2, @r1
    rts
    nop
    .2byte  0x0000                  /* (alignment padding) */
.L_race_mode_byte_b:
    .4byte  sym_06083260            /* race mode byte (duplicate ref) */
.L_const_neg1:
    .4byte  0xFFFFFFFF              /* -1 (byte-stored as 0xFF) */

    .global sym_0602DB00
sym_0602DB00:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
