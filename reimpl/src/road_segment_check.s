
    .section .text.FUN_06040C98


    .global road_segment_check
    .type road_segment_check, @function
road_segment_check:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x1, r10
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l   .L_fn_ai_checkpoint_section, r11
    mov.w   DAT_06040d2c, r12
    mov.l   .L_game_state_ptr, r14
    mov.l r5, @r15
    mov.l   .L_fn_state_init, r3
    jsr @r3
    mov.l r4, @r14
    mov.l @r15, r0
    tst r0, r0
    bt      .L_flags_not_set
    mov.l @r14, r2
    add #0x17, r2
    mov.b r10, @r2
    mov.l @r14, r3
    add #0x2F, r3
    exts.b r10, r2
    mov.b r2, @r3
    bra     .L_flags_done
    nop
.L_flags_not_set:
    mov.l @r14, r3
    add #0x17, r3
    mov.b r13, @r3
    mov.l @r14, r2
    add #0x2F, r2
    exts.b r13, r3
    mov.b r3, @r2
.L_flags_done:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov r15, r0
    add #0x8, r0
    mov.b @r0, r0
    extu.b r0, r0
    bra     .L_check_surface_type
    and #0xF, r0
.L_err_wall_type6:
    bra     .L_return
    mov #-0xD, r0
.L_err_wall_type7:
    bra     .L_return
    mov #-0xE, r0
.L_err_barrier:
    bra     .L_return
    mov #-0xA, r0
.L_check_surface_type:
    cmp/eq #0x6, r0
    bt      .L_err_wall_type6
    cmp/eq #0x7, r0
    bt      .L_err_wall_type7
    cmp/eq #0x9, r0
    bt      .L_err_barrier
    cmp/eq #0xA, r0
    bt      .L_err_barrier
    mov r12, r7
    mov r12, r6
    mov.l   .L_mask_low16, r5
    mov.l   .L_fn_road_segment_query, r3
    jsr @r3
    mov r12, r4
    mov r0, r4
    tst r4, r4
    bt      .L_road_query_ok
    bra     .L_return
    mov #-0x2, r0
.L_road_query_ok:
    mov r13, r8
    bra     .L_main_loop_top
    mov r13, r9

    .global DAT_06040d2c
DAT_06040d2c:
    .2byte  0x00FF                      /* byte mask constant loaded into r12 */
    .2byte  0xFFFF                      /* alignment padding */
.L_fn_ai_checkpoint_section:
    .4byte  ai_checkpoint_section       /* checkpoint section reader */
.L_game_state_ptr:
    .4byte  sym_060A5400                /* pointer to game state base structure */
.L_fn_state_init:
    .4byte  sym_0604231E               /* state initializer (zeros arrays) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_fn_road_segment_query:
    .4byte  road_segment_query          /* road segment geometry query */
.L_poll_cd_status:
    mov.w   DAT_06040dc0, r2
    mov.l   .L_fn_smpc_status_read, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_cd_bit_not_set
    bra     .L_cd_bit_is_set
    mov #0x1, r5
.L_cd_bit_not_set:
    mov #0x0, r5
.L_cd_bit_is_set:
    tst r5, r5
    bf      .L_cd_ready
    bra     .L_main_loop_top
    nop
.L_cd_ready:
    mov.l   .L_cd_hirq_clear_mask, r4
    mov.l   .L_fn_smpc_cmd_helper_b, r3
    jsr @r3
    nop
    add #0x1, r8
    mov.w   DAT_06040dc2, r2
    cmp/gt r2, r8
    bf      .L_poll_not_exceeded
    bra     .L_return
    mov #-0x2, r0
.L_poll_not_exceeded:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov r15, r0
    add #0x8, r0
    mov.b @r0, r0
    extu.b r0, r0
    bra     .L_check_next_surface
    and #0xF, r0
.L_err_barrier_post_cd:
    bra     .L_return
    mov #-0xA, r0
.L_found_end_marker:
    bra     .L_main_loop_top
    mov r10, r9
.L_check_next_surface:
    cmp/eq #0x1, r0
    bt      .L_found_end_marker
    cmp/eq #0x2, r0
    bt      .L_found_end_marker
    cmp/eq #0x9, r0
    bt      .L_err_barrier_post_cd
    cmp/eq #0xA, r0
    bt      .L_err_barrier_post_cd
.L_main_loop_top:
    tst r9, r9
    bt      .L_poll_cd_status
    mov.l   .L_track_data_ptr, r9
    mov.w   .L_off_track_geom, r3
    mov.l @r9, r9
    add r3, r9
    mov.l   .L_fn_track_intersect_test, r3
    jsr @r3
    mov r9, r4
    mov r0, r4
    tst r4, r4
    bt      .L_intersect_ok
    bra     .L_return
    mov #-0x2, r0

    .global DAT_06040dc0
DAT_06040dc0:
    .2byte  0x0400                      /* CD status bit 10 mask */

    .global DAT_06040dc2
DAT_06040dc2:
    .2byte  0x0258                      /* 600 = max CD poll iterations */
.L_off_track_geom:
    .2byte  0x043C                      /* offset to track geometry block */
    .2byte  0xFFFF                      /* alignment padding */
.L_fn_smpc_status_read:
    .4byte  sym_06035C4E                /* SMPC status word reader */
.L_cd_hirq_clear_mask:
    .4byte  0x0000FBFF                  /* ~0x0400: clears CD HIRQ bit 10 */
.L_fn_smpc_cmd_helper_b:
    .4byte  smpc_cmd_helper_b           /* CD HIRQ acknowledge helper */
.L_track_data_ptr:
    .4byte  sym_060A4D14                /* pointer to track data base */
.L_fn_track_intersect_test:
    .4byte  track_intersect_test        /* track intersection geometry test */
.L_intersect_ok:
    mov r15, r5
    mov.l   .L_fn_mesh_boundary_check, r3
    add #0x4, r5
    jsr @r3
    mov #0x0, r4
    mov r15, r5
    mov r15, r4
    mov.l   .L_fn_mesh_boundary_check, r3
    add #0x4, r5
    add #0x4, r4
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov r15, r0
    mov.l   .L_fp_surface_flag_bit, r2
    add #0x4, r0
    mov.b @r0, r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r9), r3
    and r2, r3
    tst r3, r3
    bf      .L_surface_flag_ok
    bra     .L_return
    mov #-0xF, r0
.L_surface_flag_ok:
    mov.w   DAT_06040e72, r4
    mov.l   .L_fn_track_surface_type_a, r3
    jsr @r3
    mov r12, r5
    mov.l @r14, r2
    mov.l   .L_fp_half, r3
    mov.l r3, @(60, r2)
    bra     .L_poll_smpc_status
    nop
.L_countdown_decrement:
    mov.l @r14, r2
    mov.l @(60, r2), r3
    add #-0x1, r3
    tst r3, r3
    bf/s    .L_poll_smpc_status
    mov.l r3, @(60, r2)
    bra     .L_return
    mov #-0x2, r0
.L_poll_smpc_status:
    mov #0x40, r3
    mov.l r3, @r15
    mov.l   .L_fn_smpc_status_read_2, r3
    jsr @r3
    nop
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_smpc_bit_not_set
    bra     .L_smpc_bit_is_set
    mov #0x1, r4
.L_smpc_bit_not_set:
    mov #0x0, r4
.L_smpc_bit_is_set:
    tst r4, r4
    bt      .L_countdown_decrement
    mov.l @r14, r3
    mov.l r13, @(60, r3)
    mov.l @r14, r4
    jsr @r11
    add #0x40, r4
    mov r13, r0
.L_return:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06040e72
DAT_06040e72:
    .2byte  0x00FC                      /* surface type query param (0xFC) */
.L_fn_mesh_boundary_check:
    .4byte  mesh_boundary_check         /* mesh boundary validator */
.L_fp_surface_flag_bit:
    .4byte  0x40000000                  /* surface validity flag bit (bit 30) */
.L_fn_track_surface_type_a:
    .4byte  track_surface_type_a        /* surface type classification */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) -- SMPC countdown init */
.L_fn_smpc_status_read_2:
    .4byte  sym_06035C4E                /* SMPC status word reader (same as above) */

    .global sym_06040E88
sym_06040E88:
    mov #0x1, r1
    mov #0x18, r7
    mov.l   .L_game_state_ptr_2, r6
    mov #0x0, r5
.L_zone_scan_loop:
    mov.l @r6, r3
    add #0x18, r3
    add r5, r3
    mov.b @r3, r2
    tst r2, r2
    bf      .L_zone_slot_occupied
    mov.l @r6, r3
    add #0x18, r3
    add r5, r3
    mov.b r1, @r3
    mov.l r5, @r4
    rts
    mov #0x0, r0
.L_zone_slot_occupied:
    add #0x1, r5
    cmp/ge r7, r5
    bf      .L_zone_scan_loop
    mov #-0x1, r2
    mov.l r2, @r4
    mov #-0x3, r0
    rts
    nop

    .global sym_06040EBA
sym_06040EBA:
    cmp/pz r4
    bf      .L_free_out_of_range
    mov #0x18, r2
    cmp/ge r2, r4
    bf      .L_free_index_valid
.L_free_out_of_range:
    rts
    mov #-0x6, r0
.L_free_index_valid:
    mov.l   .L_game_state_ptr_2, r5
    mov.l @r5, r0
    add #0x18, r0
    mov.b @(r0, r4), r0
    cmp/eq #0x1, r0
    bt      .L_free_slot_active
    rts
    mov #-0x7, r0
.L_free_slot_active:
    mov.l @r5, r3
    add #0x18, r3
    add r3, r4
    mov #0x0, r2
    mov.b r2, @r4
    mov r2, r0
    rts
    nop
.L_game_state_ptr_2:
    .4byte  sym_060A5400                /* pointer to game state base structure */

    .global sym_06040EEC
sym_06040EEC:
    mov #0x1, r1
    mov #0x18, r7
    .byte   0xD6, 0x12    /* mov.l .L_pool_06040F3C, r6 */
    mov #0x0, r5
.L_direct_scan_loop:
    mov.l @r6, r0
    mov.b @(r0, r5), r3
    tst r3, r3
    bf      .L_direct_slot_occupied
    mov.l @r6, r0
    mov.b r1, @(r0, r5)
    mov.l r5, @r4
    rts
    mov #0x0, r0
.L_direct_slot_occupied:
    add #0x1, r5
    cmp/ge r7, r5
    bf      .L_direct_scan_loop
    mov #-0x1, r3
    mov.l r3, @r4
    mov #-0x4, r0
    rts
    nop
