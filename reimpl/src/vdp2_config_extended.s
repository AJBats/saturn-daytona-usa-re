
    .section .text.FUN_06018A3C


    .global vdp2_config_extended
    .type vdp2_config_extended, @function
vdp2_config_extended:
    mov.l r14, @-r15
    mov #0xA, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x1, r12
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x1C, r15
    mov.l   .L_course_id_ptr, r13
    mov.l   .L_loading_progress, r5
    mov.l   .L_progress_ready_flag, r4
    mov.l @r5, r3
    cmp/ge r2, r3
    bf/s    .L_progress_below_10
    mov #0x0, r14
    mov #0xC, r3
    mov.l @r5, r2
    cmp/ge r3, r2
    bf      .L_progress_not_ready
    bra     .L_set_render_enable
    mov.b r12, @r4
.L_progress_not_ready:
    extu.b r14, r2
    mov.b r2, @r4
.L_set_render_enable:
    exts.b r12, r3
    mov.l   .L_secondary_render_en, r2
    mov.b r3, @r2
    bra     .L_check_init_done
    nop
.L_progress_below_10:
    extu.b r14, r3
    mov.b r3, @r4
    exts.b r14, r2
    mov.l   .L_secondary_render_en, r3
    mov.b r2, @r3
.L_check_init_done:
    mov.l   .L_init_done_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_first_time_init
    bra     .L_replay_check
    nop
    .2byte  0xFFFF
.L_course_id_ptr:
    .4byte  sym_0607EAD8                        /* → course ID word */
.L_loading_progress:
    .4byte  sym_06078868                        /* loading progress counter */
.L_progress_ready_flag:
    .4byte  sym_0607867C                        /* 1 when progress >= 12 */
.L_secondary_render_en:
    .4byte  sym_06083255                        /* 1 enables secondary CPU rendering */
.L_init_done_flag:
    .4byte  sym_0605AD08                        /* nonzero = init already done */

.L_first_time_init:
    mov.l   .L_fn_render_obj_stub, r3
    jsr @r3
    nop
    mov.l   .L_fn_cd_texture_load, r3
    jsr @r3
    mov.l @r13, r4
    mov.l @r13, r2
    mov.l   .L_course_init_jtable, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    mov.l   .L_fn_cd_course_load, r3
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_demo_mode_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_check_replay_first
    mov.l   .L_fn_demo_setup, r3
    jsr @r3
    nop
.L_check_replay_first:
    mov.l   .L_replay_mode_word, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_replay_check
    mov.l   .L_fn_race_state_pair, r3
    jsr @r3
    nop

.L_replay_check:
    mov.l   .L_replay_mode_word, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_handler_dispatch_entry
    mov.l   .L_fn_race_state_pair, r3
    jsr @r3
    nop

.L_handler_dispatch_entry:
    mov.l   .L_fn_handler_dispatch, r10
    mov.l   .L_game_state_bits, r2
    mov.w   DAT_06018b8e, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_default_handler_mode
    mov.l   .L_course_sel_byte, r11
    mov.l   .L_menu_overlay_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_check_course_variant
    mov.b @r11, r3
    extu.b r3, r3
    mov.l   .L_handler_offset_tbl, r2
    add r2, r3
    mov.b @r3, r1
    mov.b r1, @r15
    mov #0xF, r6
    mov.b @r15, r5
    bra     .L_call_handler_dispatch
    mov.l r5, @(4, r15)
.L_check_course_variant:
    mov.l   .L_course_variant_id, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_standard_handler
    mov.b @r11, r4
    mov.l   .L_fn_local_helper, r3
    extu.b r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x2, r4
    mov r15, r2
    add #0x8, r2
    mov.l r4, @r2
    mov r15, r3
    add #0x8, r3
    mov #0x6, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    add #0x8, r3
    extu.b r12, r2
    mov r2, r0
    mov.b r0, @(5, r3)
    mov r15, r3
    add #0x8, r3
    mov.l r4, @(8, r3)
    mov r15, r2
    add #0x8, r2
    mov #0x9, r3
    mov r3, r0
    mov.b r0, @(12, r2)
    mov r15, r3
    add #0x8, r3
    mov #0x63, r2
    mov r2, r0
    mov.b r0, @(13, r3)
    mov r15, r3
    add #0x8, r3
    add #0x2C, r2
    mov #0x10, r0
    mov.b r2, @(r0, r3)
    mov r15, r4
    mov.l   .L_fn_ai_throttle_mod, r3
    jsr @r3
    add #0x8, r4
    bra     .L_handler_dispatch_done
    nop
.L_standard_handler:
    mov #0xF, r6
    mov.b @r11, r5
    extu.b r5, r5
    add #0x6, r5
    mov.l r5, @r15
    jsr @r10
    mov r5, r4
.L_handler_dispatch_done:
    bra     .L_common_setup
    nop

    .global DAT_06018b8e
DAT_06018b8e:
    .2byte  0x4000                              /* game state bit 14 mask */
.L_fn_render_obj_stub:
    .4byte  render_obj_stub                     /* clear render object list */
.L_fn_cd_texture_load:
    .4byte  cd_texture_loader                   /* load course textures from CD */
.L_course_init_jtable:
    .4byte  sym_0605D1BC                        /* course-specific init jump table */
.L_fn_cd_course_load:
    .4byte  cd_course_loader                    /* load course data from CD */
.L_demo_mode_flag:
    .4byte  sym_06078635                        /* nonzero = demo/attract mode */
.L_fn_demo_setup:
    .4byte  sym_06012E7C                        /* normal (non-demo) race init */
.L_replay_mode_word:
    .4byte  sym_0607ED8C                        /* nonzero = replay playback mode */
.L_fn_race_state_pair:
    .4byte  race_state_pair_1                   /* race state setup */
.L_fn_handler_dispatch:
    .4byte  handler_dispatch                    /* handler mode dispatcher */
.L_game_state_bits:
    .4byte  sym_0607EBC4                        /* game state bitmask */
.L_course_sel_byte:
    .4byte  sym_06078648                        /* course selection index (byte) */
.L_menu_overlay_flag:
    .4byte  sym_0605AB18                        /* nonzero = menu overlay active */
.L_handler_offset_tbl:
    .4byte  sym_0605D23C                        /* handler offset lookup table */
.L_course_variant_id:
    .4byte  sym_0605AD00                        /* course variant (0/1/2) */
.L_fn_local_helper:
    .4byte  sym_06018E1E                        /* TU-local variant helper */
.L_fn_ai_throttle_mod:
    .4byte  ai_throttle_modulate                /* AI throttle config dispatch */

.L_default_handler_mode:
    mov #0x0, r6
    mov #0x3, r5
.L_call_handler_dispatch:
    jsr @r10
    mov r5, r4

.L_common_setup:
    mov.l   .L_render_active_flag, r3
    mov.l r14, @r3
    mov.l @r13, r4
    mov.l   .L_vdp1_sprite_counts, r2
    shll r4
    add r4, r2
    mov.w @r2, r3
    extu.w r3, r3
    mov.l   .L_sprite_count_store, r2
    mov.l r3, @r2
    mov.l   .L_texture_bank_a_addr, r1
    mov.l   .L_texture_bank_a_ptr, r2
    mov.l r1, @r2
    mov.l   .L_texture_bank_b_addr, r1
    mov.l   .L_texture_bank_b_ptr, r2
    mov.l r1, @r2
    mov.l   .L_course_data_ptr, r5
    mov.l @r13, r1
    mov.l   .L_course_entry_table, r2
    shll2 r1
    shll r1
    add r2, r1
    mov.l r1, @r5
    mov.l @r1, r1
    mov.l   .L_fn_segment_setup, r3
    add #0x1, r1
    jsr @r3
    mov r12, r0
    add #-0x1, r0
    mov #0x1, r2
    mov.l   .L_segment_count_store, r3
    mov.l r0, @r3
    mov.l   .L_physics_init_flag, r3
    mov.l r14, @r3
    mov.l   .L_segment_ready_flag, r3
    mov.l r2, @r3
    mov.l   .L_segment_index_a, r3
    mov.l r14, @r3
    mov.l   .L_segment_index_b, r3
    mov.l r14, @r3
    mov.l   .L_checkpoint_counter, r3
    mov.l r14, @r3

    mov.l   .L_track_width_store, r7
    mov.l   .L_course_variant_a, r6
    mov.l @r6, r6
    exts.b r6, r6
    mov r6, r3
    shll r6
    shll2 r3
    add r3, r6
    exts.b r6, r6
    mov.l   .L_width_table_a, r0
    add r6, r0
    mov.w @(r0, r4), r3
    extu.w r3, r3
    mov.l r3, @r7

    mov.l   .L_elev_table, r2
    add r4, r2
    mov.w @r2, r3
    extu.w r3, r3
    mov.l   .L_track_elev_store, r2
    mov.l r3, @r2

    mov.l   .L_segment_table, r1
    add r4, r1
    mov.w @r1, r2
    extu.w r2, r2
    mov.l   .L_seg_count_store, r1
    mov.l r2, @r1

    mov.l   .L_track_length_store, r5
    mov.l   .L_length_table, r0
    add r6, r0
    mov.w @(r0, r4), r1
    extu.w r1, r1
    mov.l r1, @r5

    mov.l   .L_course_variant_b, r0
    mov.l @r0, r0
    exts.b r0, r0
    mov r0, r3
    shll r0
    shll2 r3
    add r3, r0
    exts.b r0, r0
    mov.l   .L_width_table_b, r2
    add r2, r0
    mov.w @(r0, r4), r3
    extu.w r3, r3
    mov.l @r7, r1
    mul.l r1, r3
    sts macl, r3
    mov.l @r5, r0
    add r3, r0
    mov.l r0, @r5

    mov.w   .L_sprite_copy_count, r6
    mov.l   .L_vdp1_sprite_src, r5
    mov.l   .L_vdp1_sprite_bank_idx, r4
    mov.l   .L_vdp1_vram_0x00220, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    nop

    mov.l   .L_fn_display_hw_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_channels_clear, r3
    jsr @r3
    nop
    mov.l   .L_fn_render_update, r3
    jsr @r3
    nop
    mov.l   .L_fn_audio_enable_clr, r3
    mov.l r14, @r3
    mov.l   .L_fn_audio_init, r3
    jsr @r3
    nop
    bra     .L_post_init
    nop
.L_sprite_copy_count:
    .2byte  0x00A0                              /* 160 bytes to copy */
.L_render_active_flag:
    .4byte  sym_0607EBE4                        /* 0 = rendering disabled */
.L_vdp1_sprite_counts:
    .4byte  sym_0604806C                        /* word table: sprites per course */
.L_sprite_count_store:
    .4byte  sym_0607EA9C                        /* stored VDP1 sprite count */
.L_texture_bank_a_addr:
    .4byte  sym_060D5840                        /* texture bank A base address */
.L_texture_bank_a_ptr:
    .4byte  sym_0607EB84                        /* → texture bank A pointer */
.L_texture_bank_b_addr:
    .4byte  sym_060C6000                        /* texture bank B base address */
.L_texture_bank_b_ptr:
    .4byte  sym_0607EB88                        /* → texture bank B pointer */
.L_course_data_ptr:
    .4byte  sym_06063F3C                        /* → current course data entry */
.L_course_entry_table:
    .4byte  sym_0604800C                        /* course table, 8-byte stride */
.L_fn_segment_setup:
    .4byte  sym_06035280                        /* track segment initialization */
.L_segment_count_store:
    .4byte  sym_06063F18                        /* segment count (result - 1) */
.L_physics_init_flag:
    .4byte  sym_060786AC                        /* physics init state */
.L_segment_ready_flag:
    .4byte  sym_06063F1C                        /* 1 = segments ready */
.L_segment_index_a:
    .4byte  sym_06063F20                        /* current segment index A */
.L_segment_index_b:
    .4byte  sym_06063F24                        /* current segment index B */
.L_checkpoint_counter:
    .4byte  sym_06086034                        /* checkpoint counter */
.L_track_width_store:
    .4byte  sym_06063F28                        /* track width result */
.L_course_variant_a:
    .4byte  sym_0605AD00                        /* course variant A (byte) */
.L_width_table_a:
    .4byte  sym_0604805A                        /* width table A [variant×6+course×2] */
.L_elev_table:
    .4byte  sym_06048072                        /* elevation table [course×2] */
.L_track_elev_store:
    .4byte  sym_0607EA98                        /* track elevation result */
.L_segment_table:
    .4byte  sym_06048024                        /* segment count table [course×2] */
.L_seg_count_store:
    .4byte  sym_0607EAA0                        /* segment count B result */
.L_track_length_store:
    .4byte  sym_0607EAAC                        /* track length result */
.L_length_table:
    .4byte  sym_0604802A                        /* length table [variant×6+course×2] */
.L_course_variant_b:
    .4byte  sym_0605AD0C                        /* course variant B (byte) */
.L_width_table_b:
    .4byte  sym_0604803C                        /* width table B [variant×6+course×2] */
.L_vdp1_sprite_src:
    .4byte  sym_0605CDDC                        /* VDP1 sprite source data */
.L_vdp1_sprite_bank_idx:
    .4byte  sym_06059FFC                        /* sprite bank index */
.L_vdp1_vram_0x00220:
    .4byte  0x25C00220                          /* VDP1 VRAM +0x00220 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                     /* word-indexed memcpy */
.L_fn_display_hw_init:
    .4byte  sym_060149E0                        /* display hardware init */
.L_fn_channels_clear:
    .4byte  display_channels_clear              /* clear all display channels */
.L_fn_render_update:
    .4byte  sym_06026CE0                        /* render/display update */
.L_fn_audio_enable_clr:
    .4byte  sym_06059F44                        /* audio enable flag (cleared) */
.L_fn_audio_init:
    .4byte  audio_display_init                  /* audio subsystem init */

.L_post_init:
    mov.l   .L_init_done_clear, r3
    mov.l r14, @r3
    mov.l   .L_car_array_base, r2
    mov.l   .L_player_car_ptr, r3
    add r14, r2
    mov.l r2, @r3
    mov.l   .L_fn_hud_coord_calc, r3
    jsr @r3
    nop
    mov.l   .L_fn_dma_vram_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_dma_config, r3
    jsr @r3
    nop
    mov.l @r13, r2
    mov.l   .L_course_post_jtable, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    mov.l   .L_fn_gameover_chan, r3
    jsr @r3
    nop
    mov.l   .L_fn_system_cleanup, r3
    jsr @r3
    nop
    mov.l   .L_fn_channel_config, r3
    jsr @r3
    nop
    mov.l   .L_fn_obj_cleanup, r3
    jsr @r3
    nop
    add #0x1C, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_init_done_clear:
    .4byte  sym_0605AD08                        /* init_done flag (cleared on exit) */
.L_car_array_base:
    .4byte  sym_06078900                        /* car struct array base */
.L_player_car_ptr:
    .4byte  sym_0607E944                        /* → active player car pointer */
.L_fn_hud_coord_calc:
    .4byte  hud_coord_calc                      /* HUD coordinate calculation */
.L_fn_dma_vram_init:
    .4byte  dma_vram_init                       /* DMA VRAM initialization */
.L_fn_dma_config:
    .4byte  dma_config_dispatch                 /* DMA configuration dispatch */
.L_course_post_jtable:
    .4byte  sym_0605D1CC                        /* course post-init jump table */
.L_fn_gameover_chan:
    .4byte  gameover_channel_setup              /* game-over display channel */
.L_fn_system_cleanup:
    .4byte  sym_06003430                        /* system cleanup / finalize */
.L_fn_channel_config:
    .4byte  channel_config_b                    /* display channel config */
.L_fn_obj_cleanup:
    .4byte  obj_render_cleanup                  /* object render cleanup */
