
    .section .text.FUN_0600C218


    .global scene_update
    .type scene_update, @function
scene_update:
    mov.l r14, @-r15
    mov #0x30, r6
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    .byte   0x9C, 0x40    /* mov.w .L_ftcsr_addr, r12 -- r12 = 0xFFFFFE11 (FTCSR register) */
    .byte   0xDD, 0x21    /* mov.l .L_secondary_obj_state_ptr, r13 -- r13 = &sym_0608A52C */
    .byte   0x9E, 0x3F    /* mov.w .L_icf_mask, r14 -- r14 = 0x0080 (ICF bit mask) */
    mov.l @r13, r3
    add #0x30, r3
    mov.l r3, @r13
    mov r3, r4
    .byte   0xD5, 0x1F    /* mov.l .L_primary_obj_state_ptr, r5 -- r5 = &sym_06089EDC */
    .byte   0xD3, 0x20    /* mov.l .L_fn_memcpy_long_idx, r3 -- r3 = memcpy_long_idx (0x06027630) */
    jsr @r3
    mov.l @r5, r5
    .byte   0xD3, 0x1F    /* mov.l .L_fn_physics_calc_dispatch, r3 -- r3 = physics_calc_dispatch (0x0600D31C) */
    jsr @r3
    nop
    .byte   0xD2, 0x1F    /* mov.l .L_fn_race_utility_fn, r2 -- r2 = race_utility_fn (0x0600C286) */
    .byte   0xD3, 0x1F    /* mov.l .L_secondary_callback_ptr, r3 -- r3 = &sym_06063574 */
    mov.l r2, @r3
    .byte   0xD2, 0x1F    /* mov.l .L_pool_const_0xFFFF, r2 -- r2 = 0x0000FFFF */
    .byte   0xD3, 0x20    /* mov.l .L_minit_register, r3 -- r3 = 0x21000000 (MINIT register) */
    mov.w r2, @r3
    .byte   0xD3, 0x20    /* mov.l .L_fn_frame_dispatch, r3 -- r3 = frame_dispatch (0x060058FA) */
    jsr @r3
    nop
    .byte   0xD3, 0x1F    /* mov.l .L_fn_scene_post_render, r3 -- r3 = scene_post_render (0x06006868) */
    jsr @r3
    nop
    .byte   0xD3, 0x1F    /* mov.l .L_fn_replay_playback, r3 -- r3 = replay_playback_engine (0x0601BDEC) */
    jsr @r3
    nop
    .byte   0xD0, 0x1E    /* mov.l .L_timing_var, r0 -- r0 = &sym_06059FF8 */
    mov.l @r0, r0
    tst r0, r0
.L_0600C262:
    mov.b @r12, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_0600C262
    mov.b @r12, r0
    .byte   0xD3, 0x1B    /* mov.l .L_fn_render_finalize, r3 -- r3 = sym_0603C000 (render_finalize) */
    and #0xF, r0
    jsr @r3
    mov.b r0, @r12
    mov.l @r13, r2
    add #-0x30, r2
    mov.l r2, @r13
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
