
    .section .text.FUN_06009A60


    .global state_race_complete
    .type state_race_complete, @function
state_race_complete:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov #0x1, r11
    mov.l r10, @-r15
    mov #0x4, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_race_result_byte, r9
    mov.l   .L_car_array_base, r12
    mov.l   .L_mode_flags, r14
    mov.l   .L_fn_vdp1_update, r3
    jsr @r3
    mov.l @r12, r8
    mov.l   .L_fn_obj_render, r3
    jsr @r3
    nop
    .byte   0xB2, 0xB7    /* bsr 0x06009FFC (external) — post-race per-frame update */
    nop
    mov r13, r6
    mov.l   .L_course_index, r5
    mov.b @r5, r5
    add #0xA, r5
    mov.l r5, @r15
    mov.l   .L_fn_handler_dispatch, r3
    jsr @r3
    mov r5, r4
    mov.l @r12, r2
    mov.w   .L_off_car_sound_id, r0
    mov.l @(r0, r2), r3
    add #0x1C, r0
    mov.b r3, @r9
    mov.l @r12, r3
    mov.l   .L_race_time_store, r1
    mov.l @(r0, r3), r2
    mov.l r2, @r1
    mov.l   .L_prev_lap_time, r3
    mov.l   .L_race_time_copy, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov.l   .L_terrain_mode, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_check_continue_eligible
    mov #0x1, r2
    mov.l   .L_race_phase, r3
    mov.l @r3, r3
    cmp/gt r2, r3
    bf      .L_check_continue_eligible
    mov.b @r9, r2
    tst r2, r2
    bf      .L_check_continue_eligible
    mov.l   .L_finish_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_check_continue_eligible
    mov.b @r14, r0
    or #0x8, r0
    exts.b r0, r0
    mov.b r0, @r14
.L_check_continue_eligible:
    mov.l   .L_continue_enabled, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_scoring_and_continue
    mov #0x1, r2
    mov.l   .L_race_phase_b, r3
    mov.l @r3, r3
    cmp/gt r2, r3
    bf      .L_scoring_and_continue
    mov.l   .L_finish_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_scoring_and_continue
    mov.b @r9, r3
    mov #0x3, r2
    cmp/ge r2, r3
    bt      .L_mode_flags_dispatch
    mov.l   .L_result_flags, r4
    mov.l   .L_race_end_state, r0
    bra     .L_result_state_dispatch
    mov.l @r0, r0
.L_result_state0_set_bit0:
    mov.b @r4, r2
    bra     .L_result_sign_extend_store
    or r11, r2
.L_off_car_sound_id:
    .2byte  0x0224                           /* car struct offset: sound ID / race result */
    .2byte  0xFFFF                           /* padding to 4-byte alignment */
.L_race_result_byte:
    .4byte  sym_06078637                     /* race result byte */
.L_car_array_base:
    .4byte  sym_0607E944                     /* car array base pointer variable */
.L_mode_flags:
    .4byte  sym_0605AB17                     /* post-race mode flags (byte) */
.L_fn_vdp1_update:
    .4byte  vdp1_cmd_update                  /* VDP1 command table update fn */
.L_fn_obj_render:
    .4byte  obj_render_update                /* object render update fn */
.L_course_index:
    .4byte  sym_06078648                     /* current course index (byte, 0-2) */
.L_fn_handler_dispatch:
    .4byte  handler_dispatch                 /* course-specific handler dispatch fn */
.L_race_time_store:
    .4byte  sym_06078638                     /* race time storage (32-bit) */
.L_prev_lap_time:
    .4byte  sym_060786A4                     /* previous lap time (32-bit) */
.L_race_time_copy:
    .4byte  sym_0607863C                     /* race time copy destination (32-bit) */
.L_terrain_mode:
    .4byte  sym_06083255                     /* terrain rendering mode flag (byte) */
.L_race_phase:
    .4byte  sym_0605AD00                     /* race phase counter A (32-bit) */
.L_finish_flag:
    .4byte  sym_0607EAE0                     /* race finish flag (32-bit, nonzero = done) */
.L_continue_enabled:
    .4byte  sym_06085FF4                     /* continue eligibility flag (byte) */
.L_race_phase_b:
    .4byte  sym_0605AD04                     /* race phase counter B (32-bit) */
.L_result_flags:
    .4byte  sym_0605AB16                     /* result flags byte */
.L_race_end_state:
    .4byte  sym_0607EAD8                     /* race end state (0/1/2 dispatch) */
.L_result_state1_set_bit1:
    mov.b @r4, r0
    or #0x2, r0
    exts.b r0, r0
    bra     .L_mode_flags_dispatch
    mov.b r0, @r4
.L_result_state2_set_bit2:
    mov.b @r4, r2
    or r10, r2
.L_result_sign_extend_store:
    exts.b r2, r2
    bra     .L_mode_flags_dispatch
    mov.b r2, @r4
.L_result_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_result_state0_set_bit0
    cmp/eq #0x1, r0
    bt      .L_result_state1_set_bit1
    cmp/eq #0x2, r0
    bt      .L_result_state2_set_bit2
.L_mode_flags_dispatch:
    mov.b @r9, r2
    tst r2, r2
    bf      .L_scoring_and_continue
    mov.l   .L_race_end_state_2, r0
    bra     .L_mode_state_dispatch
    mov.l @r0, r0
.L_mode_state0_set_bit0:
    mov.b @r14, r2
    bra     .L_mode_sign_extend_store
    or r11, r2
.L_mode_state1_set_bit1:
    mov.b @r14, r0
    or #0x2, r0
    exts.b r0, r0
    bra     .L_scoring_and_continue
    mov.b r0, @r14
.L_mode_state2_set_bit2:
    mov.b @r14, r2
    or r10, r2
.L_mode_sign_extend_store:
    exts.b r2, r2
    bra     .L_scoring_and_continue
    mov.b r2, @r14
.L_mode_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_mode_state0_set_bit0
    cmp/eq #0x1, r0
    bt      .L_mode_state1_set_bit1
    cmp/eq #0x2, r0
    bt      .L_mode_state2_set_bit2
.L_scoring_and_continue:
    .byte   0xB3, 0x05    /* bsr 0x0600A1B8 (external) — scoring / ranking calculation */
    nop
    mov r8, r0
    mov.l   .L_continue_byte, r4
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_force_continue
    mov.l   .L_race_end_state_2, r0
    bra     .L_continue_state_dispatch
    mov.l @r0, r0
.L_continue_check_z:
    mov.l @(24, r8), r2
    mov.l   .L_neg_z_threshold, r3
    cmp/ge r3, r2
    bf      .L_continue_deny_z
    bra     .L_continue_allow
    nop
.L_continue_deny_z:
    exts.b r13, r2
    bra     .L_set_postrace_state
    mov.b r2, @r4
.L_continue_check_x:
    mov.l @(16, r8), r2
    mov.l   .L_neg_x_threshold, r3
    cmp/gt r3, r2
    bt      .L_continue_deny_x
.L_continue_allow:
    bra     .L_set_postrace_state
    mov.b r11, @r4
.L_continue_deny_x:
    exts.b r13, r2
    bra     .L_set_postrace_state
    mov.b r2, @r4
.L_continue_deny_state2:
    bra     .L_write_continue_and_setup
    exts.b r13, r2
.L_continue_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_continue_check_z
    cmp/eq #0x1, r0
    bt      .L_continue_check_x
    cmp/eq #0x2, r0
    bt      .L_continue_deny_state2
    bra     .L_set_postrace_state
    nop
.L_force_continue:
    mov #0x2, r2
.L_write_continue_and_setup:
    mov.b r2, @r4
.L_set_postrace_state:
    mov #0x40, r0
    mov.l @r12, r3
    mov.l r13, @(r0, r3)
    mov #0x15, r3
    mov.l   .L_game_state, r2
    mov.l r3, @r2
    mov #0x56, r3
    mov.l   .L_countdown_timer, r2
    mov.l r3, @r2
    mov.l   .L_camera_mode, r2
    mov.b r10, @r2
    mov.l   .L_state_word, r2
    mov.w r10, @r2
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
.L_race_end_state_2:
    .4byte  sym_0607EAD8                     /* race end state — second pool entry for reach */
.L_continue_byte:
    .4byte  sym_06083261                     /* continue flag byte (0=no, 1=yes, 2=forced) */
.L_neg_z_threshold:
    .4byte  0xFFB80000                       /* -0x480000: Z position continue threshold */
.L_neg_x_threshold:
    .4byte  0xFEC60000                       /* -0x13A0000: X position continue threshold */
.L_game_state:
    .4byte  g_game_state                     /* game phase state (32-bit) */
.L_countdown_timer:
    .4byte  sym_0607EBCC                     /* race countdown timer (32-bit) */
.L_camera_mode:
    .4byte  sym_06078654                     /* camera mode (byte) */
.L_state_word:
    .4byte  sym_0605A016                     /* game state word (16-bit) */
