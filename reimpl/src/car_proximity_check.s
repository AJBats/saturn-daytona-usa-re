
    .section .text.FUN_0600A914


    .global car_proximity_check
    .type car_proximity_check, @function
car_proximity_check:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_proximity_threshold, r8
    mov.l   .L_car_count, r10
    mov.l   .L_car_array_base, r12
    mov.w   .L_car_struct_stride, r13
    mov.l   .L_skip_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_phase1_begin
    bra     .L_epilogue
    nop
.L_phase1_begin:
    bra     .L_outer_loop_cond
    mov #0x1, r9
.L_outer_loop_body:
    mul.l r13, r9
    mov.l   .L_car_struct_ptr, r3
    sts macl, r14
    add r12, r14
    mov.l r14, @r3
    mov.l @r14, r2
    mov.l   .L_active_flag_mask, r3
    and r3, r2
    tst r2, r2
    bf      .L_inner_loop_entry
    bra     .L_outer_loop_incr
    nop
.L_inner_loop_entry:
    bra     .L_inner_loop_cond
    mov r9, r11
.L_inner_loop_body:
    mul.l r13, r11
    mov.w   .L_off_track_position, r0
    sts macl, r5
    mov.l @(r0, r14), r4
    add r12, r5
    mov.l @(r0, r5), r3
    sub r3, r4
    mov #0x14, r3
    cmp/gt r3, r4
    bt      .L_inner_loop_cond
    mov #-0x14, r3
    cmp/ge r3, r4
    bt      .L_p1_calc_3d_dist
    bra     .L_inner_loop_cond
    nop
.L_p1_calc_3d_dist:
    mov.l @(16, r5), r6
    mov.l @(16, r14), r2
    mov.l @(24, r5), r4
    mov.l @(24, r14), r3
    sub r2, r6
    cmp/pz r6
    bt/s    .L_p1_dx_positive
    sub r3, r4
    neg r6, r6
.L_p1_dx_positive:
    cmp/pz r4
    bt      .L_p1_dz_positive
    neg r4, r4
.L_p1_dz_positive:
    cmp/gt r4, r6
    bf      .L_p1_dz_dominant
    shar r4
    bra     .L_p1_combine_dist
    shar r4
.L_car_struct_stride:
    .2byte  0x0268                        /* car struct size (616 bytes) */
.L_off_track_position:
    .2byte  0x01EC                        /* car offset: track segment index */
    .2byte  0xFFFF
.L_proximity_threshold:
    .4byte  0x0004B333                  /* distance threshold (~4.7 in 16.16) */
.L_car_count:
    .4byte  sym_0607EA98               /* total car count */
.L_car_array_base:
    .4byte  sym_06078900               /* car array start address */
.L_skip_flag:
    .4byte  sym_0607EAE0               /* proximity check skip flag */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* current car struct pointer */
.L_active_flag_mask:
    .4byte  0x00E00000                  /* bits 23:21: car active flags */
.L_p1_dz_dominant:
    mov r6, r2
    shar r2
    shar r2
    mov r2, r6
.L_p1_combine_dist:
    add r4, r6
    cmp/ge r8, r6
    bt      .L_inner_loop_cond
    mov.w   DAT_0600aa7e, r0
    mov.l   .L_fp_one, r3
    mov.l @(r0, r5), r2
    cmp/ge r3, r2
    bt      .L_inner_loop_cond
    mov.l   .L_fn_collision_pair, r3
    jsr @r3
    mov r14, r4
.L_inner_loop_cond:
    add #0x1, r11
    mov.l @r10, r2
    cmp/hs r2, r11
    bf      .L_inner_loop_body
.L_outer_loop_incr:
    add #0x1, r9
.L_outer_loop_cond:
    mov.l @r10, r2
    add #-0x1, r2
    cmp/hs r2, r9
    bf      .L_outer_loop_body
    mov.l   .L_car_struct_ptr_2, r3
    mov.l r12, @r3
    mov r3, r11
    mov.l @r11, r11
    bra     .L_p2_loop_cond
    mov #0x1, r9
.L_p2_loop_body:
    mul.l r13, r9
    mov.l   .L_active_flag_mask_2, r2
    sts macl, r14
    add r12, r14
    mov.l @r14, r3
    and r2, r3
    tst r3, r3
    bf      .L_p2_check_track_pos
    bra     .L_p2_loop_incr
    nop
.L_p2_check_track_pos:
    mov.w   .L_off_track_position_2, r0
    mov #0x14, r3
    mov.l @(r0, r11), r4
    mov.l @(r0, r14), r2
    sub r2, r4
    cmp/gt r3, r4
    bt      .L_p2_loop_incr
    mov #-0x14, r3
    cmp/ge r3, r4
    bt      .L_p2_calc_3d_dist
    bra     .L_p2_loop_incr
    nop
.L_p2_calc_3d_dist:
    mov.l @(16, r14), r6
    mov.l @(16, r11), r2
    mov.l @(24, r14), r4
    mov.l @(24, r11), r3
    sub r2, r6
    cmp/pz r6
    bt/s    .L_p2_dx_positive
    sub r3, r4
    neg r6, r6
.L_p2_dx_positive:
    cmp/pz r4
    bt      .L_p2_dz_positive
    neg r4, r4
.L_p2_dz_positive:
    cmp/gt r4, r6
    bf      .L_p2_dz_dominant
    shar r4
    bra     .L_p2_combine_dist
    shar r4
.L_p2_dz_dominant:
    mov r6, r2
    shar r2
    shar r2
    mov r2, r6
.L_p2_combine_dist:
    add r4, r6
    cmp/ge r8, r6
    bt      .L_p2_loop_incr
    mov.w   DAT_0600aa7e, r0
    mov.l   .L_fp_one, r3
    mov.l @(r0, r14), r2
    cmp/ge r3, r2
    bt      .L_p2_loop_incr
    mov r14, r5
    mov.l   .L_fn_player_proximity, r3
    jsr @r3
    mov r11, r4
.L_p2_loop_incr:
    add #0x1, r9
.L_p2_loop_cond:
    mov.l @r10, r2
    cmp/hs r2, r9
    bf      .L_p2_loop_body
.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600aa7e
DAT_0600aa7e:
    .2byte  0x01B4                        /* car offset: collision cooldown timer */
.L_off_track_position_2:
    .2byte  0x01EC                        /* car offset: track segment index (dup) */
    .2byte  0xFFFF
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fn_collision_pair:
    .4byte  sym_060316C4               /* car-to-car collision response wrapper */
.L_car_struct_ptr_2:
    .4byte  sym_0607E940               /* car struct pointer (dup for phase 2) */
.L_active_flag_mask_2:
    .4byte  0x00E00000                  /* active flag mask (dup for phase 2) */
.L_fn_player_proximity:
    .4byte  sym_06030FC0               /* player proximity collision wrapper */
