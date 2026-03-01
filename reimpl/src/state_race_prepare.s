
    .section .text.FUN_06008E00


    .global state_race_prepare
    .type state_race_prepare, @function
state_race_prepare:
    sts.l pr, @-r15
    .byte   0xD3, 0x20    /* mov.l .L_fn_race_resource_init, r3 — validate loaded resources [HIGH] */
    jsr @r3
    nop
    .byte   0xD3, 0x1F    /* mov.l .L_fn_race_prep_init, r3 — race subsystem initialization [HIGH] */
    jsr @r3
    nop
    mov #0xD, r2
    .byte   0xD3, 0x1E    /* mov.l .L_game_state, r3 — &game_state (g_game_state) [HIGH] */
    mov.l r2, @r3
    .byte   0xD3, 0x1E    /* mov.l .L_fn_car_physics_init, r3 — car/physics initialization [HIGH] */
    jsr @r3
    nop
    .byte   0xD3, 0x1E    /* mov.l .L_fn_obj_render_update, r3 — object render update [HIGH] */
    jsr @r3
    nop
    .byte   0xD4, 0x1D    /* mov.l .L_display_flags, r4 — &display_flags (sym_0605B6D8) [HIGH] */
    .byte   0xD2, 0x1E    /* mov.l .L_race_ready_bit, r2 — 0x40000000 (bit 30) [MEDIUM] */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    .byte   0xD3, 0x1D    /* mov.l .L_fn_display_commit, r3 — display/palette commit (sym_06026CE0) [MEDIUM] */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x1C    /* mov.l .L_results_flag, r3 — &results_flag (sym_06059F44) [HIGH] */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x1B    /* mov.l .L_phase_flag, r3 — &phase_flag (sym_0605A016) [HIGH] */
    mov.w r2, @r3
    mov #0xF, r6
    mov #0x5, r5
    mov r5, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_handler_dispatch, r3 — handler dispatcher (FUN_06018DDC) [HIGH] */
    jmp @r3
    lds.l @r15+, pr
