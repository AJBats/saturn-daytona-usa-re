
    .section .text.FUN_06009508


    .global state_abort
    .type state_abort, @function
state_abort:
    sts.l pr, @-r15
    .byte   0xD4, 0x23    /* mov.l .L_p_race_event_bits, r4 */
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_no_abort
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    .byte   0xD2, 0x1F    /* mov.l .L_p_game_state, r2 */
    mov.l r3, @r2
    bra     .L_set_next_state
    nop
.L_no_abort:
    .byte   0xD0, 0x1E    /* mov.l .L_p_race_end_flag, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_set_next_state
    .byte   0xD4, 0x1D    /* mov.l .L_p_frame_counter, r4 */
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_set_next_state:
    mov #0x1D, r2
    .byte   0xD3, 0x19    /* mov.l .L_p_game_state, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x1B    /* mov.l .L_p_race_update_abort, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1A    /* mov.l .L_p_camera_system, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x1A    /* mov.l .L_p_camera_eye_pos, r6 */
    .byte   0xD5, 0x1A    /* mov.l .L_p_camera_target_vec, r5 */
    .byte   0xD4, 0x1B    /* mov.l .L_p_camera_up_vec, r4 */
    .byte   0xD3, 0x1B    /* mov.l .L_p_camera_orient_calc, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x1B    /* mov.l .L_p_scene_update, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1A    /* mov.l .L_p_frame_end_commit, r3 */
    jmp @r3
    lds.l @r15+, pr
