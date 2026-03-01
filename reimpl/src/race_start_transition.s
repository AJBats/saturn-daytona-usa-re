
    .section .text.FUN_0601A578


    .global race_start_transition
    .type race_start_transition, @function
race_start_transition:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   _pool_anim_state, r3
    mov.l r14, @r3
    mov.l   _pool_render_mode_flags, r4
    mov.l   _pool_sign_bit, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   _pool_fn_camera_finalize, r3
    jsr @r3
    nop
    mov.l   _pool_fn_camera_finalize, r3
    jsr @r3
    nop
    mov #0x9, r7
    mov.l   _pool_tile_size_a, r5
    mov.l   _pool_vdp2_vram_tile_a, r4
    mov.l   _pool_fn_vram_tile_copy, r3
    jsr @r3
    mov r14, r6
    mov #0x8, r7
    mov.l   _pool_tile_size_b, r5
    mov.l   _pool_vdp2_vram_tile_b, r4
    mov.l   _pool_fn_vram_tile_copy, r3
    jsr @r3
    mov r14, r6
    mov r14, r6
    mov.l   _pool_display_layer_params, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   _pool_display_offset, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   _pool_fn_display_list_load, r3
    jsr @r3
    mov #0x4, r4
    mov #0x1, r2
    mov.l   _pool_light_active_flag, r3
    mov.b r2, @r3
    .byte   0xB9, 0xAC    /* bsr 0x06019928 (track_seg_phys_init) */
    nop
    .byte   0xB0, 0x45    /* bsr 0x0601A65E (car_init_handler) */
    nop
    .byte   0xB1, 0x1A    /* bsr 0x0601A80C (course_data_rom_load) */
    nop
    .byte   0xB1, 0xB2    /* bsr 0x0601A940 (course_init_pipeline) */
    nop
    mov.l   _pool_frame_counter_a, r3
    mov.b r14, @r3
    mov.l   _pool_frame_counter_b, r3
    mov.b r14, @r3
    mov.l   _pool_anim_reset_byte, r3
    mov.b r14, @r3
    mov.l   _pool_fn_race_data, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   _pool_fn_palette_commit, r3
    jmp @r3
    mov.l @r15+, r14

    .global sym_0601A5F8
sym_0601A5F8:
    mov.l   _pool_game_timer, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0601A658
    mov.w   _wpool_green_light_param, r0
    rts
    nop
_wpool_green_light_param:
    .2byte  0x00A8
    .2byte  0xFFFF                        /* padding to align pool */
_pool_anim_state:
    .4byte  sym_06059F44                  /* animation state (32-bit) */
_pool_render_mode_flags:
    .4byte  sym_0605B6D8                  /* render mode flags (32-bit bitmask) */
_pool_sign_bit:
    .4byte  0x80000000                    /* sign bit — enables race-start rendering */
_pool_fn_camera_finalize:
    .4byte  sym_06026CE0                  /* camera state finalization function */
_pool_tile_size_a:
    .4byte  0x00014000                    /* 0x14000 bytes — tile pattern block A */
_pool_vdp2_vram_tile_a:
    .4byte  0x25E76174                    /* VDP2 VRAM +0x76174 (tile dest A) */
_pool_fn_vram_tile_copy:
    .4byte  sym_0600511E                  /* VRAM tile/pattern upload function */
_pool_tile_size_b:
    .4byte  0x00017700                    /* 0x17700 bytes — tile pattern block B */
_pool_vdp2_vram_tile_b:
    .4byte  0x25E761FC                    /* VDP2 VRAM +0x761FC (tile dest B) */
_pool_display_layer_params:
    .4byte  sym_06063AF8                  /* display layer parameters struct */
_pool_display_offset:
    .4byte  0x0000A000                    /* display list base offset */
_pool_fn_display_list_load:
    .4byte  sym_06028400                  /* display list loader / DMA dispatch */
_pool_light_active_flag:
    .4byte  sym_06085FF1                  /* light active flag (byte, 1 = active) */
_pool_frame_counter_a:
    .4byte  sym_06085FF2                  /* animation frame counter A (byte) */
_pool_frame_counter_b:
    .4byte  sym_06085FF3                  /* animation frame counter B (byte) */
_pool_anim_reset_byte:
    .4byte  sym_0605D245                  /* animation reset byte */
_pool_fn_race_data:
    .4byte  race_data_handler             /* race state update function */
_pool_fn_palette_commit:
    .4byte  palette_frame_effects         /* per-frame palette commit to VDP2 CRAM */
_pool_game_timer:
    .4byte  sym_06063D9E                  /* game timer (16-bit) — 0x10 = green light */
.L_0601A658:
    .byte   0x90, 0x40    /* mov.w .L_wpool_0601A6DC, r0 (cross-TU word pool) */
    rts
    nop
