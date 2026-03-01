
    .section .text.FUN_06021178


    .global obj_overlay_render
    .type obj_overlay_render, @function
obj_overlay_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov #0x1, r9
    mov.l   .L_overlay_state_flags, r14
    mov.l   .L_car_struct_ptr, r6
    mov.w   .L_car_struct_seg_offset, r0
    mov.l @r6, r4
    mov.l @r6, r5
    mov.l @r6, r3
    mov.l @(16, r4), r4
    mov.l @(r0, r3), r6
    mov.l   .L_pos_x_upper_thresh, r3
    cmp/gt r3, r4
    bf/s    .L_check_secondary_range
    mov.l @(24, r5), r5
    mov.l   .L_pos_x_lower_thresh, r3
    cmp/ge r3, r4
    bt      .L_check_secondary_range
    mov.l   .L_pos_y_upper_thresh, r3
    cmp/ge r3, r5
    bt      .L_check_secondary_range
    mov.l   .L_pos_y_lower_thresh, r3
    cmp/gt r3, r5
    bf      .L_check_secondary_range
    mov #0x57, r3
    cmp/gt r3, r6
    bf      .L_check_render_needed
    mov #0x7A, r3
    cmp/ge r3, r6
    bt      .L_check_render_needed
    mov.w @r14, r3
    extu.w r3, r3
    and r9, r3
    tst r3, r3
    bf      .L_skip_to_end_checks
    mov.w @r14, r0
    or #0x1, r0
    mov.w r0, @r14
    mov.w @r14, r0
    or #0x2, r0
    mov.w r0, @r14
.L_skip_to_end_checks:
    bra     .L_check_render_needed
    nop
.L_car_struct_seg_offset:
    .2byte  0x01EC
    .2byte  0xFFFF
.L_overlay_state_flags:
    .4byte  sym_0608959C
.L_car_struct_ptr:
    .4byte  sym_0607E940
.L_pos_x_upper_thresh:
    .4byte  0x00760000
.L_pos_x_lower_thresh:
    .4byte  0x014B0000
.L_pos_y_upper_thresh:
    .4byte  0x00D00000
.L_pos_y_lower_thresh:
    .4byte  0xFF3B0000
.L_check_secondary_range:
    mov.l   .L_sec_range_x_thresh, r2
    cmp/ge r2, r4
    bt      .L_range_tier2_check_x
    mov.l   .L_sec_range_y_thresh, r2
    cmp/ge r2, r5
    bf      .L_outside_inner_zone
.L_range_tier2_check_x:
    mov.l   .L_tier2_range_x_thresh, r2
    cmp/ge r2, r4
    bt      .L_range_tier3_check
    mov.l   .L_tier2_range_y_thresh, r2
    cmp/ge r2, r5
    bf      .L_outside_inner_zone
.L_range_tier3_check:
    mov.l   .L_tier3_range_x_thresh, r2
    cmp/ge r2, r4
    bt      .L_inside_inner_zone
    mov.l   .L_tier3_range_y_thresh, r2
    cmp/ge r2, r5
    bt      .L_inside_inner_zone
.L_outside_inner_zone:
    mov.w @r14, r2
    extu.w r2, r2
    and r9, r2
    tst r2, r2
    bf      .L_check_render_needed
    mov.w @r14, r0
    or #0x1, r0
    mov.w r0, @r14
    mov.w @r14, r0
    or #0x2, r0
    bra     .L_check_render_needed
    mov.w r0, @r14
.L_inside_inner_zone:
    mov.w @r14, r2
    extu.w r2, r2
    and r9, r2
    tst r2, r2
    bt      .L_check_render_needed
    mov #-0x2, r3
    mov.w @r14, r2
    and r3, r2
    mov.w r2, @r14
    mov.w @r14, r0
    or #0x2, r0
    mov.w r0, @r14
.L_check_render_needed:
    mov.w @r14, r0
    extu.w r0, r0
    shlr r0
    tst #0x1, r0
    bf      .L_begin_sprite_dma
    bra     .L_return
    nop
.L_begin_sprite_dma:
    mov.w   .L_dma_size_sprite_c0, r10
    mov.l   .L_display_table_base, r11
    mov.l   .L_tile_index_ptr, r12
    mov.l   .L_fn_dma_transfer, r13
    mov.w @r14, r3
    extu.w r3, r3
    and r9, r3
    tst r3, r3
    bt      .L_flagclear_path
    mov.l   .L_fn_dma_config_alt, r3
    jsr @r3
    nop
    mov.w   .L_dma_size_200, r6
    mov.l   .L_sprite_src_a, r5
    mov.l @r12, r4
    mov.l @r11, r3
    shll2 r4
    shll r4
    jsr @r13
    add r3, r4
    mov.w   DAT_060212d8, r6
    mov.l   .L_sprite_src_b, r5
    mov.l @r12, r4
    mov.l @r11, r3
    mov.w   .L_sprite_offset_3c0, r2
    shll2 r4
    shll r4
    add r3, r4
    jsr @r13
    add r2, r4
    mov.l   .L_terrain_mode_flag, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_flagset_terrain_mode
    mov r10, r6
    mov.l   .L_car_player_index, r5
    mov.l   .L_sprite_table_base_a, r3
    mov.l @r12, r4
    mov.l @r11, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    shll r4
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r13
    add #0x40, r4
    mov r10, r6
    mov.l   .L_hud_variant_index, r5
    mov.l   .L_sprite_table_base_a, r3
    mov.l @r12, r4
    mov.b @r5, r5
    shll2 r4
    extu.b r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r11, r2
    mov.w   .L_sprite_offset_100, r1
    bra     .L_flagset_final_dma
    add r2, r4
.L_dma_size_sprite_c0:
    .2byte  0x00C0
.L_dma_size_200:
    .2byte  0x0200

    .global DAT_060212d8
DAT_060212d8:
    .2byte  0x17C0
.L_sprite_offset_3c0:
    .2byte  0x03C0
.L_sprite_offset_100:
    .2byte  0x0100
    .2byte  0xFFFF
.L_sec_range_x_thresh:
    .4byte  0xFE9A0000
.L_sec_range_y_thresh:
    .4byte  0xFDCD0000
.L_tier2_range_x_thresh:
    .4byte  0xFE950000
.L_tier2_range_y_thresh:
    .4byte  0xFDD30000
.L_tier3_range_x_thresh:
    .4byte  0xFE8F0000
.L_tier3_range_y_thresh:
    .4byte  0xFDD80000
.L_display_table_base:
    .4byte  sym_06063F5C
.L_tile_index_ptr:
    .4byte  sym_06059FFC
.L_fn_dma_transfer:
    .4byte  dma_transfer
.L_fn_dma_config_alt:
    .4byte  sym_060039F2
.L_sprite_src_a:
    .4byte  sym_0604D608
.L_sprite_src_b:
    .4byte  sym_0604EFC8
.L_terrain_mode_flag:
    .4byte  sym_06083255
.L_car_player_index:
    .4byte  sym_06078868
.L_sprite_table_base_a:
    .4byte  sym_0605D084
.L_hud_variant_index:
    .4byte  sym_0607ED91
.L_flagset_terrain_mode:
    mov #0x20, r6
    mov.l   .L_display_mode_flags, r5
    mov.l   .L_sprite_table_alt, r3
    mov.l   .L_race_end_state, r4
    mov.l   .L_sprite_bank_offset, r2
    mov.l   .L_sprite_bank_base, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r11, r1
.L_flagset_final_dma:
    jsr @r13
    add r1, r4
    bra     .L_clear_overlay_bits
    nop
.L_flagclear_path:
    mov.l   .L_fn_dma_config_dispatch, r3
    jsr @r3
    nop
    mov.w   .L_dma_size_200_2, r6
    mov.l   .L_sprite_src_a_2, r5
    mov.l @r12, r4
    mov.l @r11, r3
    shll2 r4
    shll r4
    jsr @r13
    add r3, r4
    mov.w   DAT_06021416, r6
    mov.l   .L_sprite_src_b_2, r5
    mov.l @r12, r4
    mov.l @r11, r3
    mov.w   .L_sprite_offset_3c0_2, r2
    shll2 r4
    shll r4
    add r3, r4
    jsr @r13
    add r2, r4
    mov.l   .L_terrain_mode_flag_2, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_flagclear_terrain_mode
    mov r10, r6
    mov.l   .L_car_player_index_2, r5
    mov.l   .L_sprite_table_base_b, r3
    mov.l @r12, r4
    mov.l @r11, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    shll r4
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r13
    add #0x40, r4
    mov r10, r6
    mov.l   .L_hud_variant_index_2, r5
    mov.l   .L_sprite_table_base_b, r3
    mov.l @r12, r4
    mov.b @r5, r5
    shll2 r4
    extu.b r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r11, r2
    mov.w   .L_sprite_offset_100_2, r1
    bra     .L_flagclear_final_dma
    add r2, r4
.L_flagclear_terrain_mode:
    mov #0x20, r6
    mov.l   .L_display_mode_flags, r5
    mov.l   .L_sprite_table_alt_2, r3
    mov.l   .L_race_end_state, r4
    mov.l   .L_sprite_bank_offset, r2
    mov.l   .L_sprite_bank_base, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r11, r1
.L_flagclear_final_dma:
    jsr @r13
    add r1, r4
.L_clear_overlay_bits:
    mov #-0x3, r3
    mov.w @r14, r2
    and r3, r2
    mov.w r2, @r14
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_dma_size_200_2:
    .2byte  0x0200

    .global DAT_06021416
DAT_06021416:
    .2byte  0x17C0
.L_sprite_offset_3c0_2:
    .2byte  0x03C0
.L_sprite_offset_100_2:
    .2byte  0x0100
.L_display_mode_flags:
    .4byte  sym_0607EAB8
.L_sprite_table_alt:
    .4byte  sym_0605D0B4
.L_race_end_state:
    .4byte  sym_0607EAD8
.L_sprite_bank_offset:
    .4byte  sym_060448B5
.L_sprite_bank_base:
    .4byte  sym_0607886C
.L_fn_dma_config_dispatch:
    .4byte  dma_config_dispatch
.L_sprite_src_a_2:
    .4byte  sym_0604D408
.L_sprite_src_b_2:
    .4byte  sym_0604D808
.L_terrain_mode_flag_2:
    .4byte  sym_06083255
.L_car_player_index_2:
    .4byte  sym_06078868
.L_sprite_table_base_b:
    .4byte  sym_0605D05C
.L_hud_variant_index_2:
    .4byte  sym_0607ED91
.L_sprite_table_alt_2:
    .4byte  sym_0605D0AC
