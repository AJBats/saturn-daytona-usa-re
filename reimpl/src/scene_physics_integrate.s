
    .section .text.FUN_060256CC


    .global scene_physics_integrate
    .type scene_physics_integrate, @function
scene_physics_integrate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x20, r15
    mov.l   .L_render_base_table, r8
    mov.w   DAT_06025746, r9
    mov.l   .L_slot_data_table, r10
    mov.l   .L_active_slot_ptr, r13
    mov.l   .L_anim_frame_ptr, r14
    mov.l   .L_variant_active_flag, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt/s    .L_variant_inactive
    mov #0xA, r12
    bra     .L_input_handler
    nop
.L_variant_inactive:
    mov.l   .L_slot_count_word, r1
    mov.l   .L_fn_slot_check, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_detailed_setup
    mov #0x0, r11
.L_simple_loop:
    extu.w r9, r5
    mov.l   .L_fn_car_physics, r3
    jsr @r3
    mov r11, r4
    add #0x1, r11
    extu.w r11, r2
    cmp/ge r12, r2
    bf      .L_simple_loop
    bra     .L_post_physics
    nop
.L_detailed_setup:
    mov #0x0, r11
.L_detailed_loop:
    extu.w r9, r5
    mov.l   .L_fn_car_physics, r3
    jsr @r3
    mov r11, r4
    extu.w r11, r3
    shll2 r3
    shll r3
    mov.l r3, @(20, r15)
    add r10, r3
    mov.l r3, @(16, r15)
    mov.w @(6, r3), r0
    mov.w   .L_render_type_b4, r2
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_use_type_9
    bra     .L_use_type_8
    mov #0x8, r2

    .global DAT_06025746
DAT_06025746:
    .2byte  0x00A9                       /* render parameter (physics mode) */
.L_render_type_b4:
    .2byte  0x00B4                       /* alternate render type ID */
    .2byte  0xFFFF
.L_render_base_table:
    .4byte  sym_06063750                /* render base data (8-byte stride) */
.L_slot_data_table:
    .4byte  sym_06060F2C                /* slot data array (8-byte per slot) */
.L_active_slot_ptr:
    .4byte  sym_06089ECC                /* &active_slot_index (dword) */
.L_anim_frame_ptr:
    .4byte  sym_06089ED0                /* &anim_frame_index (dword) */
.L_variant_active_flag:
    .4byte  sym_06061199                /* variant active flag (byte) */
.L_slot_count_word:
    .4byte  sym_06089EC6                /* slot count (word) */
.L_fn_slot_check:
    .4byte  sym_06035C2C                /* slot availability check */
.L_fn_car_physics:
    .4byte  car_physics_final           /* per-car physics final update */
.L_use_type_9:
    mov #0x9, r2
.L_use_type_8:
    extu.w r2, r2
    extu.w r11, r6
    mov r2, r0
    mov.w r0, @(8, r15)
    mov.l @(20, r15), r7
    mov.l   .L_slot_offset_table, r3
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r8, r7
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7
    mov.l   .L_fp_half, r3
    add r3, r7
    shll r6
    mov.l r6, @(24, r15)
    mov.l   .L_direction_table_a, r3
    add r3, r6
    mov.l r6, @(28, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(28, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l @r5, r5
    add #0x4, r4
    mov.l r4, @(12, r15)
    mov.l @r4, r4
    mov.l   .L_fn_layer_setup, r3
    jsr @r3
    shll2 r4
    mov.w @(8, r15), r0
    mov r8, r2
    mov.l @(16, r15), r3
    mov r0, r7
    extu.w r7, r7
    mov.w @(6, r3), r0
    shll8 r7
    mov r0, r3
    shll2 r7
    extu.w r3, r3
    shll2 r7
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(24, r15), r6
    add r3, r7
    mov.l   .L_direction_table_b, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @(12, r15), r4
    mov.l   .L_fn_layer_setup, r3
    mov.l @r5, r5
    mov.l @r4, r4
    jsr @r3
    shll2 r4
    add #0x1, r11
    extu.w r11, r2
    cmp/ge r12, r2
    bf      .L_detailed_loop
.L_post_physics:
    mov.l   .L_input_buttons, r5
    mov.w @r5, r5
    extu.w r5, r4
    tst r4, r4
    bt      .L_input_handler
    mov.l   .L_btn_nav_only_mask, r3
    and r4, r3
    tst r3, r3
    bf      .L_input_handler
    mov #0x1, r3
    mov.l   .L_variant_active_flag_2, r2
    mov.b r3, @r2
.L_input_handler:
    mov.l   .L_variant_active_flag_2, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_variant_mode_active
    bra     .L_exit
    nop
.L_slot_offset_table:
    .4byte  sym_06058FBC                /* per-slot offset entries */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_direction_table_a:
    .4byte  sym_0605904C                /* direction pair table A (2-byte stride) */
.L_fn_layer_setup:
    .4byte  sym_06028400                /* layer setup / geometry dispatch */
.L_direction_table_b:
    .4byte  sym_06059060                /* direction pair table B (2-byte stride) */
.L_input_buttons:
    .4byte  sym_06063D9A                /* current input buttons (word) */
.L_btn_nav_only_mask:
    .4byte  0x0000C000                  /* navigation button mask (bits 15:14) */
.L_variant_active_flag_2:
    .4byte  sym_06061199                /* variant active flag (same as above) */
.L_variant_mode_active:
    mov.l   .L_input_buttons_3, r4
    mov.w @r4, r4
    extu.w r4, r3
    tst r3, r3
    bf      .L_has_input
    bra     .L_post_race_render
    nop
.L_has_input:
    extu.w r4, r3
    mov.l   .L_btn_action_mask, r2
    and r2, r3
    tst r3, r3
    bf      .L_has_action_buttons
    bra     .L_start_button_check
    nop
.L_has_action_buttons:
    extu.w r4, r3
    mov.l   .L_btn_advance_mask, r2
    and r2, r3
    tst r3, r3
    bt      .L_retreat_check
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov #0xE, r3
    cmp/gt r3, r2
    bf      .L_adv_course_a_check
    mov #0x0, r3
    mov.l r3, @r14
.L_adv_course_a_check:
    mov.l   .L_course_id_a, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_adv_course_a2_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x4, r0
    bf      .L_adv_course_a2_check
    mov #0x8, r3
    mov.l r3, @r14
.L_adv_course_a2_check:
    mov.l   .L_course_id_a, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_adv_course_b_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_adv_course_b_check
    mov #0x4, r3
    mov.l r3, @r14
.L_adv_course_b_check:
    mov.l   .L_course_id_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_adv_course_b2_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0xA, r0
    bf      .L_adv_course_b2_check
    mov #0xE, r3
    mov.l r3, @r14
.L_adv_course_b2_check:
    mov.l   .L_course_id_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bt      .L_adv_b2_frame_eq8
    bra     .L_commit_direction
    nop
.L_adv_b2_frame_eq8:
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x8, r0
    bt      .L_adv_skip_to_limit
    bra     .L_commit_direction
    nop
.L_adv_skip_to_limit:
    bra     .L_commit_direction
    mov.l r12, @r14
.L_retreat_check:
    extu.w r4, r4
    mov.w   DAT_0602596a, r2
    and r2, r4
    tst r4, r4
    bt      .L_no_input
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov r3, r2
    cmp/pz r2
    bt      .L_ret_course_b_check
    mov #0xE, r2
    mov.l r2, @r14
.L_ret_course_b_check:
    mov.l   .L_course_id_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_ret_course_b2_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bf      .L_ret_course_b2_check
    mov #0x9, r3
    mov.l r3, @r14
.L_ret_course_b2_check:
    mov.l   .L_course_id_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_ret_course_a_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x9, r0
    bf      .L_ret_course_a_check
    mov #0x7, r3
    mov.l r3, @r14
.L_ret_course_a_check:
    mov.l   .L_course_id_a, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_ret_course_a2_check
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x7, r0
    bf      .L_ret_course_a2_check
    mov #0x3, r3
    mov.l r3, @r14
.L_ret_course_a2_check:
    mov.l   .L_course_id_a, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_no_input
    mov.l   .L_anim_frame_check, r0
    mov.l @r0, r0
    cmp/eq #0x3, r0
    bf      .L_no_input
    mov #0x1, r3
    mov.l r3, @r14
.L_no_input:
    bra     .L_commit_direction
    nop

    .global DAT_0602596a
DAT_0602596a:
    .2byte  0x4000                       /* retreat button mask */
.L_input_buttons_3:
    .4byte  sym_06063D9A                /* current input buttons (word) */
.L_btn_action_mask:
    .4byte  0x0000C000                  /* action button mask (bits 15:14) */
.L_btn_advance_mask:
    .4byte  0x00008000                  /* advance button mask (bit 15) */
.L_course_id_a:
    .4byte  sym_06089ED6                /* course identifier A (word) */
.L_anim_frame_check:
    .4byte  sym_06089ED0                /* anim frame index (for course limit checks) */
.L_course_id_b:
    .4byte  sym_06089ED4                /* course identifier B (word) */
.L_start_button_check:
    extu.w r4, r2
    mov.w   DAT_06025a80, r3
    and r3, r2
    tst r2, r2
    bt      .L_button_search
    mov #0x5, r3
    mov.l   .L_game_state_byte, r2
    mov.b r3, @r2
    mov #0x12, r3
    mov.l   .L_game_mode_word, r2
    mov.w r3, @r2
    mov #0x0, r3
    mov.l   .L_variant_flag_exit, r2
    mov.b r3, @r2
    mov #0x4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xAC, 0x37    /* bra scene_process_a (external) */
    mov.l @r15+, r14
.L_button_search:
    mov #0x0, r5
.L_button_search_loop:
    extu.w r5, r2
    extu.w r4, r1
    mov.l   .L_button_mask_table, r3
    shll r2
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r1, r2
    tst r2, r2
    bt      .L_button_next
    bra     .L_button_found
    nop
.L_button_next:
    add #0x1, r5
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_button_search_loop
.L_button_found:
    extu.w r5, r5
    mov.l r5, @r13
    .byte   0xB4, 0x70    /* bsr transform_heading_apply (external) */
    mov r5, r4
    mov #0x0, r4
.L_anim_search_loop:
    extu.b r4, r2
    mov.l   .L_render_record_table, r1
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    extu.b r2, r2
    add r1, r2
    mov.w @(8, r2), r0
    mov r0, r3
    mov.l @r13, r2
    extu.w r3, r3
    shll2 r2
    shll r2
    add r10, r2
    mov.w @(6, r2), r0
    mov r0, r1
    extu.w r1, r1
    cmp/eq r1, r3
    bf      .L_anim_next
    bra     .L_anim_found
    nop
.L_anim_next:
    add #0x1, r4
    mov #0xE, r3
    extu.w r4, r2
    cmp/ge r3, r2
    bf      .L_anim_search_loop
.L_anim_found:
    extu.w r4, r4
    mov.l r4, @r14
.L_commit_direction:
    mov.l @r13, r3
    mov.l @r14, r2
    mov.l   .L_render_record_table, r0
    shll2 r3
    extu.b r2, r2
    shll r3
    mov r2, r1
    add r10, r3
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.l @(4, r2), r1
    mov.l r1, @r3
    mov.l @r13, r3
    mov.l @r13, r2
    mov.l   .L_button_mask_table, r1
    shll2 r3
    shll r2
    shll r3
    add r1, r2
    add r10, r3
    mov.w @r2, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.l @r14, r2
    extu.b r2, r2
    mov.l   .L_render_record_table, r0
    mov r2, r1
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.w @(8, r2), r0
    mov.w r0, @(6, r3)
    .byte   0xBB, 0xD7    /* bsr scene_process_a (external) */
    mov #0x4, r4
.L_post_race_render:
    mov.l @r13, r2
    cmp/pz r2
    bt      .L_post_race_physics
    bra     .L_exit
    nop

    .global DAT_06025a80
DAT_06025a80:
    .2byte  0x0800                       /* Start button mask */
    .2byte  0xFFFF
.L_game_state_byte:
    .4byte  sym_06061198                /* game state (byte) */
.L_game_mode_word:
    .4byte  sym_06089EDA                /* game mode (word) */
.L_variant_flag_exit:
    .4byte  sym_06061199                /* variant active flag (clear on exit) */
.L_button_mask_table:
    .4byte  sym_06059094                /* per-slot button mask table (2-byte stride) */
.L_render_record_table:
    .4byte  sym_060610BC                /* render record table (12-byte stride) */
.L_post_race_physics:
    mov.l   .L_slot_count_word_2, r1
    mov.l   .L_fn_slot_check_2, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_post_detailed
    extu.w r9, r5
    mov.l @r13, r4
    extu.w r4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_car_physics_2, r3
    jmp @r3
    mov.l @r15+, r14
.L_post_detailed:
    mov.l @r14, r3
    mov.l   .L_render_record_table_2, r1
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    extu.b r3, r3
    mov.w   .L_render_type_b4_2, r2
    add r1, r3
    mov.w @(8, r3), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_post_use_type_9
    bra     .L_post_use_type_8
    mov #0x8, r2
.L_post_use_type_9:
    mov #0x9, r2
.L_post_use_type_8:
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.l @r13, r7
    mov.l   .L_slot_offset_table_2, r3
    shll2 r7
    shll r7
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r8, r7
    mov.l r7, @(8, r15)
    mov.l @(4, r7), r7
    mov.l   .L_fp_half_2, r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_direction_table_a_2, r3
    add r3, r6
    mov.l r6, @(12, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(12, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    mov.l @(8, r15), r5
    mov.l @r15, r4
    mov.l   .L_fn_layer_setup_2, r3
    shll r6
    mov.l @r5, r5
    mov.l @(4, r4), r4
    jsr @r3
    shll2 r4
    mov.w @(4, r15), r0
    mov.l @r14, r3
    mov r0, r7
    extu.b r3, r3
    extu.w r7, r7
    mov r3, r2
    shll8 r7
    shll2 r2
    shll2 r3
    shll2 r7
    shll r3
    shll2 r7
    add r3, r2
    extu.b r2, r2
    mov.l   .L_render_record_table_2, r3
    add r2, r3
    mov.w @(8, r3), r0
    mov r0, r2
    extu.w r2, r3
    shll2 r3
    mov r8, r2
    shll r3
    add r3, r2
    mov.l r2, @r15
    mov.l @(4, r2), r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_direction_table_b_2, r3
    add r3, r6
    mov.l r6, @(8, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    mov.l @(8, r15), r2
    mov.l @r15, r5
    mov.l @r13, r4
    extu.b r6, r6
    mov.b @r2, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    shll r4
    mov.l   .L_slot_offset_table_2, r3
    add r3, r4
    mov.l @(4, r4), r4
    shll2 r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_layer_setup_2, r2
    jmp @r2
    mov.l @r15+, r14
.L_render_type_b4_2:
    .2byte  0x00B4                       /* alternate render type ID */
    .2byte  0xFFFF
.L_slot_count_word_2:
    .4byte  sym_06089EC6                /* slot count (word) */
.L_fn_slot_check_2:
    .4byte  sym_06035C2C                /* slot availability check */
.L_fn_car_physics_2:
    .4byte  car_physics_final           /* per-car physics final update */
.L_render_record_table_2:
    .4byte  sym_060610BC                /* render record table (12-byte stride) */
.L_slot_offset_table_2:
    .4byte  sym_06058FBC                /* per-slot offset entries */
.L_fp_half_2:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_direction_table_a_2:
    .4byte  sym_0605904C                /* direction pair table A (2-byte stride) */
.L_fn_layer_setup_2:
    .4byte  sym_06028400                /* layer setup / geometry dispatch */
.L_direction_table_b_2:
    .4byte  sym_06059060                /* direction pair table B (2-byte stride) */
.L_exit:
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
