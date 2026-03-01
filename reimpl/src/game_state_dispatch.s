
    .section .text.FUN_0600F424


    .global game_state_dispatch
    .type game_state_dispatch, @function
game_state_dispatch:
    mov.l r14, @-r15
    mov #0x4, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_ptr_game_state, r14
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r3, r4
    bf      .L_state_le_4
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_check_input_poll
.L_state_le_4:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_state_not_9
    mov.l   .L_ptr_attract_countdown, r1
    mov.l   .L_fn_model_data_lookup, r2
    mov.l @r1, r1
    jsr @r2
    mov #0x3C, r0
    mov r0, r7
    mov #0x18, r6
    mov.w   .L_const_palette_size, r5
    mov.l   .L_fn_display_layer_init, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_check_input_poll
    nop
.L_const_palette_size:
    .2byte  0x0148
    .4byte  0x25F00720
    .4byte  sym_060487CC
    .4byte  0x25F00680
    .4byte  0x25F00140
    .4byte  sym_060483EC
    .4byte  0x25F000C0
    .4byte  0x25F006C0
    .4byte  sym_0605AAA0
.L_ptr_game_state:
    .4byte  sym_0607887F
    .4byte  sym_0605B6D8
    .4byte  0x40000000
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
.L_ptr_attract_countdown:
    .4byte  sym_0607EBCC
.L_fn_model_data_lookup:
    .4byte  sym_06034FE0
.L_fn_display_layer_init:
    .4byte  sym_06028430
.L_state_not_9:
    mov.l   .L_ptr_attract_countdown_b, r1
    mov.l   .L_fn_model_data_lookup_b, r2
    mov.l @r1, r1
    jsr @r2
    mov #0x3C, r0
    mov r0, r7
    mov #0x18, r6
    mov.w   .L_const_palette_size_b, r5
    mov.l   .L_fn_display_layer_init_b, r3
    jsr @r3
    mov #0x8, r4
.L_check_input_poll:
    mov #0xA, r3
    mov.b @r14, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bf      .L_check_hud_tile_dma
    mov.l   .L_ptr_timer_half_word, r3
    mov.l   .L_fp_half, r2
    mov.w @r3, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bf      .L_check_hud_tile_dma
    mov.l   .L_ptr_input_lock_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_check_hud_tile_dma
    mov.l   .L_ptr_button_state, r4
    mov.l   .L_ptr_mode_select_result, r5
    mov.l   .L_ptr_btn_mask_a, r2
    mov.w @r4, r4
    mov.w @r2, r2
    exts.w r4, r3
    extu.w r2, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_btn_mask_b
    mov #0x0, r3
    mov.b r3, @r5
    bra     .L_check_hud_tile_dma
    nop
.L_check_btn_mask_b:
    exts.w r4, r2
    mov.l   .L_ptr_btn_mask_b, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_btn_mask_c
    mov #0x1, r3
    mov.b r3, @r5
    bra     .L_check_hud_tile_dma
    nop
.L_check_btn_mask_c:
    exts.w r4, r2
    mov.l   .L_ptr_btn_mask_c, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_btn_mask_d
    mov #0x2, r3
    mov.b r3, @r5
    bra     .L_check_hud_tile_dma
    nop
.L_const_palette_size_b:
    .2byte  0x0148
    .2byte  0xFFFF
.L_ptr_attract_countdown_b:
    .4byte  sym_0607EBCC
.L_fn_model_data_lookup_b:
    .4byte  sym_06034FE0
.L_fn_display_layer_init_b:
    .4byte  sym_06028430
.L_ptr_timer_half_word:
    .4byte  sym_0607865E
.L_fp_half:
    .4byte  0x00008000
.L_ptr_input_lock_flag:
    .4byte  sym_0605AB18
.L_ptr_button_state:
    .4byte  g_pad_state
.L_ptr_mode_select_result:
    .4byte  sym_06078648
.L_ptr_btn_mask_a:
    .4byte  sym_06078656
.L_ptr_btn_mask_b:
    .4byte  sym_06078658
.L_ptr_btn_mask_c:
    .4byte  sym_0607865A
.L_check_btn_mask_d:
    exts.w r4, r4
    mov.l   .L_ptr_btn_mask_d, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r2, r4
    tst r4, r4
    bt      .L_check_hud_tile_dma
    mov #0x3, r3
    mov.b r3, @r5
.L_check_hud_tile_dma:
    mov #0xC, r2
    mov.b @r14, r4
    extu.b r4, r4
    cmp/ge r2, r4
    bt      .L_dispatch_state_handler
    mov #0x8, r2
    cmp/gt r2, r4
    bf      .L_dispatch_state_handler
    mov.w   DAT_0600f612, r13
    mov.l   .L_ptr_attract_timer, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_tile_dma_split
    mov.l   .L_ptr_display_mode, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_tile_dma_mode_b
    mov.l   .L_ptr_tile_data_src_a, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600f614, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_fn_display_list_load, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_dispatch_state_handler
    nop
.L_tile_dma_mode_b:
    mov.l   .L_ptr_tile_data_src_b, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600f614, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_fn_display_list_load, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_dispatch_state_handler
    nop
.L_tile_dma_split:
    mov.l   .L_ptr_split_tile_data, r12
    mov r13, r5
    mov.l   .L_fn_geom_dispatch_final, r3
    mov.w   .L_const_tile_offset, r6
    mov r12, r7
    jsr @r3
    mov #0xC, r4
    mov r12, r7
    mov.w   .L_const_tile_offset, r6
    mov.w   DAT_0600f618, r5
    mov.l   .L_fn_geom_dispatch_final, r3
    jsr @r3
    mov #0xC, r4
    mov r12, r7
    mov #0x0, r6
    mov.w   DAT_0600f61a, r5
    mov.l   .L_fn_geom_render_dispatch, r3
    jsr @r3
    mov #0xC, r4
.L_dispatch_state_handler:
    mov.l   .L_fn_pre_transform_setup, r3
    jsr @r3
    nop
    mov.b @r14, r2
    mov.l   .L_ptr_state_handler_table, r3
    extu.b r2, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    .byte   0xB4, 0xEA                   /* bsr 0x0600FFD0 (external post-state helper) */
    nop
    mov.l   .L_ptr_frame_budget, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_frame_end_commit, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0600f612
DAT_0600f612:
    .2byte  0x08A4

    .global DAT_0600f614
DAT_0600f614:
    .2byte  0x5000
.L_const_tile_offset:
    .2byte  0x0090

    .global DAT_0600f618
DAT_0600f618:
    .2byte  0x09A4

    .global DAT_0600f61a
DAT_0600f61a:
    .2byte  0x0AA4
.L_ptr_btn_mask_d:
    .4byte  sym_0607865C
.L_ptr_attract_timer:
    .4byte  sym_0607EAE0
.L_ptr_display_mode:
    .4byte  sym_06078644
.L_ptr_tile_data_src_a:
    .4byte  sym_06063848
.L_fn_display_list_load:
    .4byte  sym_06028400
.L_ptr_tile_data_src_b:
    .4byte  sym_06063850
.L_ptr_split_tile_data:
    .4byte  sym_0605ACE4
.L_fn_geom_dispatch_final:
    .4byte  sym_060284AE
.L_fn_geom_render_dispatch:
    .4byte  sym_060283E0
.L_fn_pre_transform_setup:
    .4byte  sym_06026DBC
.L_ptr_state_handler_table:
    .4byte  sym_0605AC2C
.L_ptr_frame_budget:
    .4byte  sym_06089EDC
.L_fn_frame_end_commit:
    .4byte  frame_end_commit
