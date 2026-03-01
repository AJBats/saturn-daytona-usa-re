
    .section .text.FUN_0600F9C6


    .global transition_large_menu
    .type transition_large_menu, @function
transition_large_menu:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD5, 0x13    /* mov.l .L_snd_cmd_menu, r5 — 0xAE0003FF menu music */
    .byte   0xD3, 0x13    /* mov.l .L_fn_sound_dispatch_a, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x13    /* mov.l .L_fn_display_channel_config, r3 */
    jsr @r3
    mov #0xC, r4
    mov.w   .L_palette_size, r6
    .byte   0xD5, 0x12    /* mov.l .L_palette_src, r5 — menu palette data */
    .byte   0xD4, 0x12    /* mov.l .L_vdp2_cram_0x460, r4 — VDP2 CRAM dest */
    .byte   0xD3, 0x13    /* mov.l .L_fn_memcpy_word, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x12    /* mov.l .L_fn_scroll_setup, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x12    /* mov.l .L_status_word, r2 — game status array */
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_extended_layout
    mov #0x25, r14
    bra     .L_setup_display_layers
    mov #0x23, r13
.L_palette_size:
    .2byte  0x0080                          /* palette copy size (128 bytes) */
    .2byte  0xFFFF                          /* alignment padding */
    .4byte  sym_0607885C                    /* (cross-TU pool) display slot ptr */
    .4byte  0x00100000                      /* (cross-TU pool) scroll param */
    .4byte  display_channel_b               /* (cross-TU pool) */
    .4byte  sym_0607886E                    /* (cross-TU pool) display slot */
    .4byte  sprite_batch_renderer           /* (cross-TU pool) */
    .4byte  sym_0607887F                    /* (cross-TU pool) game mode byte */
.L_snd_cmd_menu:
    .4byte  0xAE0003FF                      /* sound command: menu music */
.L_fn_sound_dispatch_a:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher */
.L_fn_display_channel_config:
    .4byte  sym_0602853E                    /* display channel configure */
.L_palette_src:
    .4byte  sym_0605CA9C                    /* menu palette source data */
.L_vdp2_cram_0x460:
    .4byte  0x25F00460                      /* VDP2 color RAM +0x460 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                 /* word-indexed memory copy */
.L_fn_scroll_setup:
    .4byte  sym_0601209E                    /* scroll/display setup helper */
.L_status_word:
    .4byte  g_pad_state                    /* game status word (16-bit array) */
.L_extended_layout:
    mov #0x28, r14
    mov #0x27, r13
.L_setup_display_layers:
    .byte   0xDB, 0x35    /* mov.l .L_tile_table, r11 — tile table base */
    mov r14, r7
    .byte   0xDC, 0x35    /* mov.l .L_fn_tile_writer, r12 */
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x33    /* mov.l .L_tile_data_offset, r3 — 0x9000 */
    mov.w   .L_tile_size_a, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r13, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x2D    /* mov.l .L_tile_data_offset, r3 — 0x9000 */
    mov.w   .L_tile_size_b, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.w   .L_tile_index_c, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_tile_offset_c, r3
    mov.w   .L_tile_size_c, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    .byte   0xD5, 0x25    /* mov.l .L_snd_cmd_secondary, r5 — 0xAB1104FF */
    .byte   0xD3, 0x25    /* mov.l .L_fn_sound_dispatch_b, r3 */
    jsr @r3
    mov #0x0, r4
    mov #0x9, r2
    .byte   0xD3, 0x24    /* mov.l .L_game_mode_byte, r3 */
    mov #0x0, r4
    mov.b r2, @r3
    mov r4, r2
    .byte   0xD3, 0x23    /* mov.l .L_transition_state_a, r3 */
    mov.l r4, @r3
    .byte   0xD3, 0x23    /* mov.l .L_game_variant_flag, r3 */
    mov.l r4, @r3
    .byte   0xD3, 0x23    /* mov.l .L_display_slot_a, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x23    /* mov.l .L_display_slot_b, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x23    /* mov.l .L_transition_active, r3 */
    mov.l r2, @r3
    .byte   0xD0, 0x23    /* mov.l .L_two_player_flag, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_check_1p_setup
    .byte   0xD3, 0x22    /* mov.l .L_split_transition_state, r3 */
    mov.l r4, @r3
    .byte   0xD2, 0x22    /* mov.l .L_split_scroll_offset, r2 — 0x000C0000 */
    .byte   0xD3, 0x22    /* mov.l .L_split_scroll_ptr, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x22    /* mov.l .L_split_display_slot, r3 */
    mov.l r4, @r3
    extu.b r4, r4
    .byte   0xD3, 0x22    /* mov.l .L_split_active_byte, r3 */
    mov.b r4, @r3
    .byte   0xD7, 0x22    /* mov.l .L_split_tile_table, r7 — split tile data */
    mov.w   .L_split_tile_size, r6
    mov.w   .L_split_tile_data, r5
    .byte   0xD3, 0x21    /* mov.l .L_fn_split_tile_writer, r3 */
    jsr @r3
    mov #0xC, r4
.L_check_1p_setup:
    .byte   0xD0, 0x19    /* mov.l .L_two_player_flag, r0 */
    mov.b @r0, r0
    tst r0, r0
    bf      .L_finalize
    .byte   0xD3, 0x1F    /* mov.l .L_fn_ui_setup, r3 */
    jsr @r3
    mov #0x1, r4
    .byte   0xD3, 0x1E    /* mov.l .L_fn_anim_transition, r3 */
    jsr @r3
    mov #0x1, r4
.L_finalize:
    .byte   0xD3, 0x1E    /* mov.l .L_fn_graphics_mode, r3 */
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x1B    /* mov.l .L_fn_dual_hud_dispatch, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_tile_size_a:
    .2byte  0x0B04                          /* layer A tile size */
.L_tile_size_b:
    .2byte  0x0B38                          /* layer B tile size */
.L_tile_index_c:
    .2byte  0x0170                          /* layer C table offset (0x170 = entry 0x2E) */
.L_tile_offset_c:
    .2byte  0x4000                          /* layer C data offset */
.L_tile_size_c:
    .2byte  0x0C26                          /* layer C tile size */
.L_split_tile_size:
    .2byte  0x0090                          /* split-screen tile size */
.L_split_tile_data:
    .2byte  0x07A2                          /* split-screen tile data offset */
    .2byte  0xFFFF                          /* alignment padding */
.L_tile_table:
    .4byte  sym_06063750                    /* tile table base array */
.L_fn_tile_writer:
    .4byte  sym_06028400                    /* display layer tile writer */
.L_tile_data_offset:
    .4byte  0x00009000                      /* tile data offset (+0x9000) */
.L_snd_cmd_secondary:
    .4byte  0xAB1104FF                      /* sound command: secondary trigger */
.L_fn_sound_dispatch_b:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher */
.L_game_mode_byte:
    .4byte  sym_0607887F                    /* game mode byte (9 = menu) */
.L_transition_state_a:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_game_variant_flag:
    .4byte  sym_0607EAB8                    /* game variant flag */
.L_display_slot_a:
    .4byte  sym_06078868                    /* display slot A */
.L_display_slot_b:
    .4byte  sym_060788A0                    /* display slot B */
.L_transition_active:
    .4byte  sym_060788A4                    /* transition active flag */
.L_two_player_flag:
    .4byte  sym_06085FF4                    /* 2-player mode flag (byte) */
.L_split_transition_state:
    .4byte  sym_06078894                    /* split-screen transition state */
.L_split_scroll_offset:
    .4byte  0x000C0000                      /* split-screen scroll Y offset */
.L_split_scroll_ptr:
    .4byte  sym_06078898                    /* split-screen scroll position ptr */
.L_split_display_slot:
    .4byte  sym_0607889C                    /* split-screen display slot */
.L_split_active_byte:
    .4byte  sym_060788A8                    /* split-screen active byte */
.L_split_tile_table:
    .4byte  sym_0605ACE4                    /* split-screen tile data source */
.L_fn_split_tile_writer:
    .4byte  sym_060284AE                    /* split-screen tile writer */
.L_fn_ui_setup:
    .4byte  sym_06011494                    /* UI element setup */
.L_fn_anim_transition:
    .4byte  anim_ui_transition              /* animated UI transition */
.L_fn_graphics_mode:
    .4byte  graphics_mode_setup             /* graphics mode configuration */
.L_fn_dual_hud_dispatch:
    .4byte  sym_06011EB4                    /* dual HUD render dispatcher */
