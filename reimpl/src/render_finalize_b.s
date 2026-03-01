
    .section .text.FUN_06024D24


    .global render_finalize_b
    .type render_finalize_b, @function
render_finalize_b:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_slot_counter, r10
    mov.w   .L_slot_limit_sentinel, r11
    mov.l   .L_render_phase, r13
    mov.l   .L_active_slot_idx, r14
    mov.b @r13, r3
    extu.b r3, r3
    tst r3, r3
    bf/s    .L_check_phase
    mov #0x0, r12
    mov #0x1, r3
    mov.b r3, @r13
    mov.l   .L_snd_cmd_param, r5
    mov.l   .L_fn_sound_cmd_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_fp_0x4000_0000, r2
    mov.l   .L_render_mode_flags, r3
    mov.l @r3, r3
    or r2, r3
    mov.l   .L_render_mode_flags, r2
    mov.l r3, @r2
    mov r2, r1
    mov.l @r1, r1
    or r9, r1
    mov.l r1, @r2
    mov.l   .L_fn_memcpy_word, r8
    mov.w   .L_pal_copy_count, r6
    mov.l   .L_pal_traffic_light, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x0C0, r4
    jsr @r8
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_pal_bg_base, r3
    mov.l r3, @(4, r15)
    mov.l   .L_vdp2_cram_0x000, r4
    jsr @r8
    mov r3, r5
    mov.w   .L_pal_copy_count, r6
    mov.l   .L_vdp2_cram_0x6C0, r4
    jsr @r8
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_vdp2_cram_0x600, r4
    jsr @r8
    mov.l @(4, r15), r5
    mov #0x8, r7
    mov.l   .L_tile_pattern_size, r5
    mov.l   .L_vdp2_vram_0x76EFC, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_fn_render_param_calc, r3
    jsr @r3
    nop
    mov.w r0, @r10
    mov.l   .L_slot_count_word, r3
    mov.w r12, @r3
    mov.l   .L_display_state_byte, r1
    mov.b @r1, r1
    .byte   0xB1, 0x66    /* bsr 0x06025070 (scene_finalize_a */
    mov.l r1, @r14
    .byte   0xB1, 0xD0    /* bsr 0x06025148 (scene_finalize_b */
    nop
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_init_call_process_b
    .byte   0xB2, 0x38    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_check_phase
    nop
.L_slot_limit_sentinel:
    .2byte  0x00A9
.L_pal_copy_count:
    .2byte  0x0080
.L_slot_counter:
    .4byte  sym_06089EC4
.L_render_phase:
    .4byte  sym_06061198
.L_active_slot_idx:
    .4byte  sym_06089EC8
.L_snd_cmd_param:
    .4byte  0xAE0003FF
.L_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_fp_0x4000_0000:
    .4byte  0x40000000                  /* bit 30: render active flag */
.L_render_mode_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit) */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_pal_traffic_light:
    .4byte  sym_0605CF9C                    /* traffic light palette src (RAM) */
.L_vdp2_cram_0x0C0:
    .4byte  0x25F000C0                  /* VDP2 color RAM +0x0C0 */
.L_pal_bg_base:
    .4byte  sym_0605CD9C                    /* background palette src (RAM) */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_vdp2_cram_0x6C0:
    .4byte  0x25F006C0                  /* VDP2 color RAM +0x6C0 */
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_tile_pattern_size:
    .4byte  0x00017700                      /* 0x17700 bytes tile pattern data */
.L_vdp2_vram_0x76EFC:
    .4byte  0x25E76EFC                  /* VDP2 VRAM +0x76EFC */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E                    /* VRAM tile/pattern upload fn */
.L_fn_render_param_calc:
    .4byte  sym_0601A5F8                    /* render parameter calculator fn */
.L_slot_count_word:
    .4byte  sym_06089EC6                    /* slot count (word) */
.L_display_state_byte:
    .4byte  sym_0605D240                    /* display state byte */
.L_init_call_process_b:
    .byte   0xB3, 0x34    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_check_phase:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_phase_1_input
    bra     .L_check_phase_4
    nop
.L_phase_1_input:
    mov.l   .L_slot_count_word_b, r4
    mov.l   .L_fn_mat_multiply, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_button_state_word, r8
    mov.w @r8, r8
    extu.w r8, r2
    tst r2, r2
    bf      .L_input_has_buttons
    bra     .L_check_phase_6
    nop
.L_input_has_buttons:
    mov.l r12, @r15
    extu.w r8, r3
    mov.w   .L_mask_start_btn, r2
    and r2, r3
    mov.l r3, @(4, r15)
.L_input_loop_top:
    mov.l @r14, r0
    cmp/eq #0x4, r0
    bf      .L_check_select
    mov.l @(4, r15), r0
    tst r0, r0
    bt      .L_check_select
    extu.b r9, r3
    mov #-0x1, r2
    mov.b r3, @r13
    mov.l   .L_slot_index_reset, r3
    mov.l r2, @r3
    mov.l   .L_course_id_a, r3
    mov.w r12, @r3
    mov.l   .L_course_id_b, r3
    mov.w r12, @r3
    mov.l   .L_fn_mat_multiply, r3
    jsr @r3
    extu.w r12, r4
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_start_call_process_b
    .byte   0xB1, 0xDC    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_input_done
    nop
.L_start_call_process_b:
    .byte   0xB3, 0x02    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
    bra     .L_input_done
    nop
.L_check_select:
    extu.w r8, r2
    mov.w   .L_mask_select_btn, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_confirm
    mov.l @r14, r3
    mov.l   .L_display_state_store, r2
    mov.b r3, @r2
    mov #0x2, r1
    bra     .L_input_done
    mov.b r1, @r13
.L_check_confirm:
    extu.w r8, r2
    mov.w   .L_mask_confirm_btn, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_dpad_up
    mov #0x2, r3
    mov.b r3, @r13
    bra     .L_input_done
    nop
.L_mask_start_btn:
    .2byte  0x0800                          /* start button bitmask */
.L_mask_select_btn:
    .2byte  0x0600                          /* select button bitmask */
.L_mask_confirm_btn:
    .2byte  0x0100                          /* confirm button bitmask */
    .2byte  0xFFFF                          /* alignment padding */
.L_slot_count_word_b:
    .4byte  sym_06089EC6                    /* slot count (word) */
.L_fn_mat_multiply:
    .4byte  mat_multiply_basic
.L_button_state_word:
    .4byte  sym_06063D9A                    /* button state word (16-bit) */
.L_slot_index_reset:
    .4byte  sym_06089ECC                    /* active slot index (dword) */
.L_course_id_a:
    .4byte  sym_06089ED6                    /* course identifier A (word) */
.L_course_id_b:
    .4byte  sym_06089ED4                    /* course identifier B (word) */
.L_display_state_store:
    .4byte  sym_0605D240                    /* display state byte */
.L_check_dpad_up:
    extu.w r8, r2
    mov.l   .L_fp_half, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_dpad_down
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov #0x5, r3
    cmp/ge r3, r2
    bf      .L_check_dpad_down
    mov.l r12, @r14
.L_check_dpad_down:
    extu.w r8, r3
    mov.w   .L_mask_dpad_down, r2
    and r2, r3
    tst r3, r3
    bt      .L_dispatch_scene_proc
    mov.l @r14, r3
    add #-0x1, r3
    mov r3, r2
    mov.l r3, @r14
    cmp/pz r2
    bt      .L_dispatch_scene_proc
    mov.l r9, @r14
.L_dispatch_scene_proc:
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_dispatch_process_b
    .byte   0xB1, 0x91    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_input_loop_iter
    nop
.L_dispatch_process_b:
    .byte   0xB2, 0xB7    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_input_loop_iter:
    mov #0x1, r3
    mov.l @r15, r2
    add #0x1, r2
    cmp/ge r3, r2
    bf/s    .L_input_loop_top
    mov.l r2, @r15
.L_input_done:
    bra     .L_check_phase_6
    nop
.L_check_phase_4:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_check_phase_5
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_phase4_variant
    .byte   0xB3, 0xCF    /* bsr 0x060256CC (scene_physics_integrate */
    nop
    bra     .L_check_phase_6
    nop
.L_phase4_variant:
    .byte   0xB6, 0x5F    /* bsr 0x06025BF4 (scene_physics_variant */
    nop
    bra     .L_check_phase_6
    nop
.L_check_phase_5:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_check_phase_6
    mov.l   .L_fn_sprite_anim_update, r3
    jsr @r3
    nop
.L_check_phase_6:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x6, r0
    bf      .L_check_phase_2
    mov.l   .L_pal_copy_pending, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_pal_copy_active
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_phase6_finalize_b
    .byte   0xB0, 0x85    /* bsr 0x06025070 (scene_finalize_a */
    nop
    bra     .L_phase6_dispatch
    nop
.L_phase6_finalize_b:
    .byte   0xB0, 0xED    /* bsr 0x06025148 (scene_finalize_b */
    nop
    bra     .L_phase6_dispatch
    nop
.L_mask_dpad_down:
    .2byte  0x4000                          /* D-pad down bitmask */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_sprite_anim_update:
    .4byte  sprite_anim_update
.L_pal_copy_pending:
    .4byte  sym_06089ED8                    /* palette copy pending flag (word) */
.L_pal_copy_active:
    mov.w @r10, r5
    mov.l @r14, r4
    mov.l   .L_fn_sprite_pair_render, r3
    jsr @r3
    exts.b r4, r4
    mov r12, r5
    mov.l   .L_slot_data_table_b, r2
    mov.l r2, @r15
    mov r2, r6
    mov.l   .L_slot_data_table_a, r7
    mov r2, r4
.L_pal_copy_loop:
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_pal_copy_alt_slot
    mov r5, r3
    shll2 r3
    shll r3
    mov.l   .L_slot_data_table_a, r2
    add r2, r3
    mov.l @r3, r3
    mov.l @(4, r4), r2
    mov.w @r2, r1
    mov.w r1, @r3
    bra     .L_pal_copy_next
    nop
.L_pal_copy_alt_slot:
    mov.l @(4, r7), r2
    mov.l @(4, r6), r3
    mov.w @r3, r1
    mov.w r1, @r2
.L_pal_copy_next:
    add #0x1, r5
    add #0xC, r6
    add #0x8, r7
    mov #0xE, r3
    cmp/ge r3, r5
    bf/s    .L_pal_copy_loop
    add #0xC, r4
.L_phase6_dispatch:
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_phase6_process_b
    .byte   0xB1, 0x27    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_phase6_reset_to_1
    nop
.L_phase6_process_b:
    .byte   0xB2, 0x4D    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_phase6_reset_to_1:
    mov #0x1, r2
    mov.b r2, @r13
.L_check_phase_2:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_epilogue
    extu.b r12, r2
    mov.b r2, @r13
    mov.l   .L_variant_active_flag, r2
    mov.b r12, @r2
    mov.l   .L_render_mode_flags_b, r1
    mov.l   .L_render_mode_flags_b, r2
    mov.l @r1, r1
    or r9, r1
    mov.l r1, @r2
    mov.l   .L_fn_display_layer_cfg, r2
    jsr @r2
    mov #0x8, r4
    mov.l   .L_fn_display_layer_cfg, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    nop
    mov.l   .L_frame_counter_byte, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
.L_epilogue:
    mov.l   .L_slot_count_word_c, r3
    mov.w @r3, r3
    add #0x1, r3
    mov.l   .L_slot_count_word_c, r2
    mov.w r3, @r2
    mov.l   .L_render_mode_flags_b, r1
    mov.l @r1, r1
    or r9, r1
    mov.l   .L_render_mode_flags_b, r2
    mov.l r1, @r2
    mov.l   .L_anim_state_clear, r2
    mov.l r12, @r2
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_display_update, r2
    jmp @r2
    mov.l @r15+, r14
.L_fn_sprite_pair_render:
    .4byte  sprite_pair_render
.L_slot_data_table_b:
    .4byte  sym_060610BC                    /* slot data table B (12-byte stride) */
.L_slot_data_table_a:
    .4byte  sym_06060D7C                    /* slot data table A (8-byte stride) */
.L_variant_active_flag:
    .4byte  sym_06061199                    /* variant active flag (byte) */
.L_render_mode_flags_b:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit) */
.L_fn_display_layer_cfg:
    .4byte  sym_0602853E                    /* display layer configuration fn */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit fn */
.L_frame_counter_byte:
    .4byte  sym_06085FF2                    /* frame counter (byte) */
.L_slot_count_word_c:
    .4byte  sym_06089EC6                    /* slot count (word) */
.L_anim_state_clear:
    .4byte  sym_06059F44                    /* animation state (32-bit) */
.L_fn_display_update:
    .4byte  sym_06026CE0                    /* display update fn (tail-call target) */
