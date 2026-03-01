
    .section .text.FUN_0600E060


    .global race_update_ending
    .type race_update_ending, @function
race_update_ending:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x21    /* mov.l .L_pool_car_array_base_ptr, r14 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_total_car_count, r3 */
    .byte   0xD2, 0x22    /* mov.l .L_pool_half_count_store, r2 */
    mov.l @r14, r14
    mov.l @r3, r3
    shar r3
    mov.w r3, @r2
    .byte   0xD2, 0x20    /* mov.l .L_pool_cur_car_ptr, r2 */
    mov.l r14, @r2
    .byte   0xD1, 0x20    /* mov.l .L_pool_car_data_table, r1 */
    .byte   0xD2, 0x21    /* mov.l .L_pool_car_data_slot, r2 */
    mov.l r1, @r2
    .byte   0xD2, 0x21    /* mov.l .L_pool_fn_reg_save_prologue, r2 */
    jsr @r2
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x20    /* mov.l .L_pool_fn_coord_grid_pack, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x1F    /* mov.l .L_pool_coord_xform_result, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x1F    /* mov.l .L_pool_fn_seg_pos_track, r3 */
    jsr @r3
    nop
    .byte   0xDD, 0x1F    /* mov.l .L_pool_fn_scene_3d_proc, r13 */
    .byte   0xD4, 0x1F    /* mov.l .L_pool_geom_channel_0, r4 */
    jsr @r13
    mov #0x0, r5
    .byte   0xD4, 0x1F    /* mov.l .L_pool_geom_channel_1, r4 */
    jsr @r13
    mov #0x1, r5
    .byte   0xD4, 0x1E    /* mov.l .L_pool_geom_channel_2, r4 */
    jsr @r13
    mov #0x2, r5
    .byte   0xD4, 0x1E    /* mov.l .L_pool_geom_channel_3, r4 */
    jsr @r13
    mov #0x3, r5
    mov r14, r4
    .byte   0xD3, 0x1D    /* mov.l .L_pool_fn_disp_scroll, r3 */
    jsr @r3
    add #0x14, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA0, 0x00    /* bra 0x0600E0C0 (external) */  ! tail-branch to car_update_racing
    mov.l @r15+, r14
