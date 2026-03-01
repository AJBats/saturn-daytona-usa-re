
    .section .text.FUN_06013C58


    .global lap_time_display
    .type lap_time_display, @function
lap_time_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_dlist_loader, r13
    mov.l   .L_pool_car_obj_table, r14
    mov.l   .L_pool_car_data_base, r3
    mov.l r3, @(4, r15)
    mov.l   .L_pool_layer_config, r12
    jsr @r12
    mov #0x4, r4
    jsr @r12
    mov #0xC, r4
    mov.l   .L_pool_render_commit, r3
    jsr @r3
    nop
    mov.w   .L_dat_minutes_offset, r7
    mov #0x0, r6
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    jsr @r12
    mov #0x4, r4
    mov #0x18, r6
    mov.w   .L_dat_vram_offset, r12
    mov.w   .L_dat_sec_tens_offset, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.w   .L_dat_sec_ones_offset, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_wpool_hundredths_slot, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_pool_2p_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_use_2p_separator
    mov.w   .L_wpool_1p_sep_offset, r7
    bra     .L_render_separator
    nop

    .global DAT_06013cca
.L_dat_minutes_offset:
DAT_06013cca:
    .2byte  0x00F0                           /* minutes dlist entry offset in car obj table */

    .global DAT_06013ccc
.L_dat_vram_offset:
DAT_06013ccc:
    .2byte  0x7000                           /* VRAM destination offset for digit textures */

    .global DAT_06013cce
.L_dat_sec_tens_offset:
DAT_06013cce:
    .2byte  0x0228                           /* seconds tens dlist entry offset */

    .global DAT_06013cd0
.L_dat_sec_ones_offset:
DAT_06013cd0:
    .2byte  0x0230                           /* seconds ones dlist entry offset */
.L_wpool_hundredths_slot:
    .2byte  0x0CB0                           /* hundredths display slot value */
.L_wpool_1p_sep_offset:
    .2byte  0x0238                           /* 1P colon separator dlist offset */
    .2byte  0xFFFF                           /* alignment padding */
.L_pool_dlist_loader:
    .4byte  sym_06028400                     /* display_list_loader function */
.L_pool_car_obj_table:
    .4byte  sym_06063750                     /* car object table base (display list entries) */
.L_pool_car_data_base:
    .4byte  sym_06078900                     /* car data array base (stride 0x268) */
.L_pool_layer_config:
    .4byte  sym_0602853E                     /* display_layer_config function */
.L_pool_render_commit:
    .4byte  sym_06028560                     /* render_state_commit function */
.L_pool_2p_flag:
    .4byte  sym_06085FF4                     /* two_player_flag (byte, 0=1P) */
.L_use_2p_separator:
    mov.w   .L_dat_2p_sep_offset, r7
.L_render_separator:
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_dat_sep_slot, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_pool_display_chan_b, r12
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x20, r4
    mov.l   .L_pool_frame_transform, r12
    mov.l @(4, r15), r4
    mov.w   .L_dat_frame_field_offset, r0
    jsr @r12
    mov.l @(r0, r4), r4
    mov r0, r7
    mov.w   .L_dat_digit_slot_a, r6
    mov.w   .L_dat_digit_slot_b, r5
    mov.l   .L_pool_elem_renderer, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_pool_frame_counter, r2
    mov.l   .L_pool_max_frame, r3
    mov.l @r2, r2
    cmp/hi r3, r2
    bf      .L_frame_in_range
    mov.l   .L_pool_max_frame, r4
    bra     .L_convert_time
    nop
.L_frame_in_range:
    mov.l   .L_pool_frame_counter, r4
    mov.l @r4, r4
.L_convert_time:
    jsr @r12
    nop
    mov r0, r7
    mov.w   .L_dat_digit_slot_a, r6
    mov.w   .L_wpool_digit_slot_c, r5
    mov.l   .L_pool_elem_renderer, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_pool_pause_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_show_fastest_lap
    mov.l   .L_pool_lap_index, r7
    mov #0x30, r6
    mov.w   .L_dat_lap_slot, r5
    mov.l   .L_pool_dlist_cmd_writer, r3
    mov.b @r7, r7
    extu.b r7, r7
    add #0x1, r7
    jsr @r3
    mov #0xC, r4
    mov #0x3, r11
    mov.l   .L_pool_lap_index, r12
    mov.b @r12, r12
    extu.b r12, r12
    cmp/ge r11, r12
    bt      .L_clamp_to_max_lap
    bra     .L_use_actual_lap
    mov r12, r7
.L_clamp_to_max_lap:
    mov r11, r7
.L_use_actual_lap:
    add #0x48, r7
    mov.w   .L_dat_lap_elem_slot, r6
    shll2 r7
    shll r7
    add r14, r7
    cmp/ge r11, r12
    bt/s    .L_clamp_second_param
    mov.l @(4, r7), r7
    bra     .L_use_actual_second
    mov r12, r5
.L_clamp_second_param:
    mov r11, r5
.L_use_actual_second:
    add #0x48, r5
    shll2 r5
    shll r5
    add r14, r5
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_epilogue
    nop
.L_show_fastest_lap:
    mov.l   .L_pool_fastest_lap_str, r7
    mov.l   .L_pool_nibble3_mask, r6
    mov.w   .L_dat_fastest_lap_slot, r5
    mov #0xC, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_geom_dispatch, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06013dc6
.L_dat_2p_sep_offset:
DAT_06013dc6:
    .2byte  0x0588                           /* 2P colon separator dlist offset in car obj table */

    .global DAT_06013dc8
.L_dat_sep_slot:
DAT_06013dc8:
    .2byte  0x0C84                           /* separator display slot */

    .global DAT_06013dca
.L_dat_frame_field_offset:
DAT_06013dca:
    .2byte  0x0240                           /* car struct offset: current frame field */

    .global DAT_06013dcc
.L_dat_digit_slot_a:
DAT_06013dcc:
    .2byte  0x009C                           /* time digit display slot A */

    .global DAT_06013dce
.L_dat_digit_slot_b:
DAT_06013dce:
    .2byte  0x0CC4                           /* time digit display slot B */
.L_wpool_digit_slot_c:
    .2byte  0x0C98                           /* time digit display slot C */

    .global DAT_06013dd2
.L_dat_lap_slot:
DAT_06013dd2:
    .2byte  0x0104                           /* lap number display slot */

    .global DAT_06013dd4
.L_dat_lap_elem_slot:
DAT_06013dd4:
    .2byte  0x010C                           /* lap element display slot */

    .global DAT_06013dd6
.L_dat_fastest_lap_slot:
DAT_06013dd6:
    .2byte  0x0102                           /* "FASTEST LAP" text display slot */
.L_pool_display_chan_b:
    .4byte  display_channel_b                /* display channel setup wrapper */
.L_pool_frame_transform:
    .4byte  anim_frame_transform             /* frame-to-time conversion function */
.L_pool_elem_renderer:
    .4byte  sym_060284AE                     /* display_element_renderer function */
.L_pool_frame_counter:
    .4byte  sym_060786A4                     /* frame_counter (32-bit race frame) */
.L_pool_max_frame:
    .4byte  0x000927BF                       /* 599,999 = max frame index (~10 min at 60fps) */
.L_pool_pause_flag:
    .4byte  sym_06085FF8                     /* pause_replay_flag (byte) */
.L_pool_lap_index:
    .4byte  sym_06086012                     /* current_lap_index (byte, 0-based) */
.L_pool_dlist_cmd_writer:
    .4byte  sym_06028430                     /* display_list_cmd_writer function */
.L_pool_fastest_lap_str:
    .4byte  sym_06044A58                     /* "FASTEST LAP" string (ROM data) */
.L_pool_nibble3_mask:
    .4byte  0x0000F000                       /* nibble 3 mask (palette/color selector) */
.L_pool_geom_dispatch:
    .4byte  sym_060283E0                     /* geom_render_dispatch (text renderer) */
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
