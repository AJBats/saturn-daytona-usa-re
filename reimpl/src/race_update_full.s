
    .section .text.FUN_0600E47C


    .global race_update_full
    .type race_update_full, @function
race_update_full:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x28    /* mov.l .L_car_array_base, r14 */
    .byte   0xD3, 0x29    /* mov.l .L_car_struct_ptr, r3 */
    mov.l @r14, r14
    mov.l r14, @r3
    .byte   0xD3, 0x28    /* mov.l .L_fn_audio_phase, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_fn_gas_force, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x27    /* mov.l .L_fn_brake_force, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x27    /* mov.l .L_fn_timer_trigger, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x26    /* mov.l .L_fn_timer_decrement, r3 */
    jsr @r3
    nop
    .byte   0xB1, 0x8F    /* bsr per_frame_race_update */
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x24    /* mov.l .L_fn_grid_pack, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x24    /* mov.l .L_grid_result_store, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x24    /* mov.l .L_fn_seg_track, r3 */
    jsr @r3
    nop
    .byte   0xDE, 0x23    /* mov.l .L_fn_scene_3d, r14 */
    .byte   0xD4, 0x24    /* mov.l .L_geom_channel_0, r4 */
    jsr @r14
    mov #0x0, r5
    .byte   0xD4, 0x23    /* mov.l .L_geom_channel_1, r4 */
    jsr @r14
    mov #0x1, r5
    .byte   0xD4, 0x23    /* mov.l .L_geom_channel_2, r4 */
    jsr @r14
    mov #0x2, r5
    .byte   0xD4, 0x22    /* mov.l .L_geom_channel_3, r4 */
    jsr @r14
    mov #0x3, r5
    .byte   0xD3, 0x22    /* mov.l .L_fn_finish_prox, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_fn_collision, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_fn_render_finalize, r3 */
    jsr @r3
    mov #0x0, r4
    mov #0x0, r4
    lds.l @r15+, pr
    .byte   0xD3, 0x1F    /* mov.l .L_fn_checkpoint, r3 */
    jmp @r3
    mov.l @r15+, r14
