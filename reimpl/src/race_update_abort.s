
    .section .text.FUN_0600DFD0


    .global race_update_abort
    .type race_update_abort, @function
race_update_abort:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_car_array_base_ptr, r14
    mov.l   .L_pool_total_car_count, r3
    mov.l   .L_pool_car_visibility_state, r2
    mov.l @r14, r14
    mov.l @r3, r3
    shar r3
    mov.w r3, @r2
    mov.l   .L_pool_cur_car_ptr, r2
    mov.l r14, @r2
    mov.l   .L_pool_car_data_table, r1
    mov.l   .L_pool_car_data_slot, r2
    mov.l r1, @r2
    mov.l   .L_pool_fn_reg_save_prologue, r2
    jsr @r2
    nop
    mov.l @(0x18, r14), r5
    mov.l   .L_pool_fn_coord_grid_pack, r3
    jsr @r3
    mov.l @(0x10, r14), r4
    mov.l   .L_pool_car_state_flags, r3
    mov.l r0, @r3
    mov.l   .L_pool_fn_seg_pos_track, r3
    jsr @r3
    nop
    mov.l   .L_pool_fn_scene_3d_proc, r14
    mov.l   .L_pool_geom_channel_0, r4
    jsr @r14
    mov #0x0, r5
    mov.l   .L_pool_geom_channel_1, r4
    jsr @r14
    mov #0x1, r5
    mov.l   .L_pool_geom_channel_2, r4
    jsr @r14
    mov #0x2, r5
    mov.l   .L_pool_geom_channel_3, r4
    jsr @r14
    mov #0x3, r5
    lds.l @r15+, pr
    .byte   0xA0, 0x4E    /* bra 0x0600E0C0 (external) */  ! tail-branch to car_update_racing
    mov.l @r15+, r14
.L_pool_car_array_base_ptr:
    .4byte  sym_0607E944
.L_pool_total_car_count:
    .4byte  sym_0607EA98
.L_pool_car_visibility_state:
    .4byte  sym_060786CA
.L_pool_cur_car_ptr:
    .4byte  sym_0607E940
.L_pool_car_data_table:
    .4byte  sym_06078B68
.L_pool_car_data_slot:
    .4byte  sym_0607E948
.L_pool_fn_reg_save_prologue:
    .4byte  sym_0602DB00
.L_pool_fn_coord_grid_pack:
    .4byte  sym_06006838
.L_pool_car_state_flags:
    .4byte  sym_060786B8
.L_pool_fn_seg_pos_track:
    .4byte  segment_position_track
.L_pool_fn_scene_3d_proc:
    .4byte  scene_3d_processor
.L_pool_geom_channel_0:
    .4byte  sym_06063EB0
.L_pool_geom_channel_1:
    .4byte  sym_06063E9C
.L_pool_geom_channel_2:
    .4byte  sym_06063ED8
.L_pool_geom_channel_3:
    .4byte  sym_06063EC4
