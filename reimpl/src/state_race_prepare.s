
    .section .text.FUN_06008E00


    .global state_race_prepare
    .type state_race_prepare, @function
state_race_prepare:
    sts.l pr, @-r15
    .byte   0xD3, 0x20    /* mov.l .L_fn_race_resource_init, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1F    /* mov.l .L_fn_race_prep_init, r3 */
    jsr @r3
    nop
    mov #0xD, r2
    .byte   0xD3, 0x1E    /* mov.l .L_game_state, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x1E    /* mov.l .L_fn_car_physics_init, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1E    /* mov.l .L_fn_obj_render_update, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x1D    /* mov.l .L_display_flags, r4 */
    .byte   0xD2, 0x1E    /* mov.l .L_race_ready_bit, r2 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    .byte   0xD3, 0x1D    /* mov.l .L_fn_display_commit, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x1C    /* mov.l .L_results_flag, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x1B    /* mov.l .L_phase_flag, r3 */
    mov.w r2, @r3
    mov #0xF, r6
    mov #0x5, r5
    mov r5, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_handler_dispatch, r3 */
    jmp @r3
    lds.l @r15+, pr
