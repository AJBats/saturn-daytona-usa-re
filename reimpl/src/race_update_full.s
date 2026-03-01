
    .section .text.FUN_0600E47C


    .global race_update_full
    .type race_update_full, @function
race_update_full:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x28    /* mov.l .L_car_array_base, r14 — &sym_0607E944 */
    .byte   0xD3, 0x29    /* mov.l .L_car_struct_ptr, r3 — &sym_0607E940 */
    mov.l @r14, r14
    mov.l r14, @r3
    .byte   0xD3, 0x28    /* mov.l .L_fn_audio_phase, r3 — sym_0600A8BC */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_fn_gas_force, r3 — gas_force_apply */
    jsr @r3
    nop
    .byte   0xD3, 0x27    /* mov.l .L_fn_brake_force, r3 — brake_force_apply */
    jsr @r3
    nop
    .byte   0xD3, 0x27    /* mov.l .L_fn_timer_trigger, r3 — sym_06030A06 */
    jsr @r3
    nop
    .byte   0xD3, 0x26    /* mov.l .L_fn_timer_decrement, r3 — sym_06030EE0 */
    jsr @r3
    nop
    .byte   0xB1, 0x8F    /* bsr per_frame_race_update — demo physics pipeline */
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x24    /* mov.l .L_fn_grid_pack, r3 — sym_06006838 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x24    /* mov.l .L_grid_result_store, r3 — &sym_060786B8 */
    mov.l r0, @r3
    .byte   0xD3, 0x24    /* mov.l .L_fn_seg_track, r3 — segment_position_track */
    jsr @r3
    nop
    .byte   0xDE, 0x23    /* mov.l .L_fn_scene_3d, r14 — scene_3d_processor */
    .byte   0xD4, 0x24    /* mov.l .L_geom_channel_0, r4 — &sym_06063EB0 */
    jsr @r14
    mov #0x0, r5
    .byte   0xD4, 0x23    /* mov.l .L_geom_channel_1, r4 — &sym_06063E9C */
    jsr @r14
    mov #0x1, r5
    .byte   0xD4, 0x23    /* mov.l .L_geom_channel_2, r4 — &sym_06063ED8 */
    jsr @r14
    mov #0x2, r5
    .byte   0xD4, 0x22    /* mov.l .L_geom_channel_3, r4 — &sym_06063EC4 */
    jsr @r14
    mov #0x3, r5
    .byte   0xD3, 0x22    /* mov.l .L_fn_finish_prox, r3 — finish_proximity */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_fn_collision, r3 — collision_detect_main */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_fn_render_finalize, r3 — sym_0603053C */
    jsr @r3
    mov #0x0, r4
    mov #0x0, r4
    lds.l @r15+, pr
    .byte   0xD3, 0x1F    /* mov.l .L_fn_checkpoint, r3 — checkpoint_detect */
    jmp @r3
    mov.l @r15+, r14
