/* race_start_transition -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601A578 - 0x0601A65E
 *
 * Race start scene setup — initializes display layers, uploads tile
 * pattern data to VDP2 VRAM, configures the display list for the
 * pre-race grid view, then chains into subsystem init calls:
 *   track_seg_phys_init, car_init_handler, course_data_rom_load,
 *   course_init_pipeline.
 *
 * After init, clears animation/frame counters for the start light
 * sequence, calls race_data_handler, and tail-calls palette_frame_effects.
 *
 * Second function (render_param_query):
 *   Returns a render parameter word based on the game timer.
 *   If timer == 0x10 (green light moment) → return 0x00A8.
 *   Otherwise → return value from cross-TU word pool (alternate frame).
 */

    .section .text.FUN_0601A578


    .global race_start_transition
    .type race_start_transition, @function
race_start_transition:
    sts.l pr, @-r15                       ! save return address
    add #-0x4, r15                        ! allocate 4 bytes on stack
    mov.l   _pool_anim_state, r3          ! r3 = &anim_state
    mov.l r14, @r3                        ! anim_state = r14 (caller's context, 0 on first call)
    mov.l   _pool_render_mode_flags, r4   ! r4 = &render_mode_flags
    mov.l   _pool_sign_bit, r2            ! r2 = 0x80000000
    mov.l @r4, r3                         ! r3 = current render_mode_flags
    or r2, r3                             ! set sign bit (enable race-start rendering)
    mov.l r3, @r4                         ! write back render_mode_flags
    mov.l   _pool_fn_camera_finalize, r3  ! r3 = camera_state_finalization
    jsr @r3                               ! call camera_state_finalization (first pass)
    nop
    mov.l   _pool_fn_camera_finalize, r3  ! r3 = camera_state_finalization
    jsr @r3                               ! call camera_state_finalization (second pass)
    nop
    mov #0x9, r7                          ! r7 = 9 (DMA transfer mode / tile count)
    mov.l   _pool_tile_size_a, r5         ! r5 = 0x14000 (tile pattern size A)
    mov.l   _pool_vdp2_vram_tile_a, r4   ! r4 = 0x25E76174 (VDP2 VRAM dest A)
    mov.l   _pool_fn_vram_tile_copy, r3  ! r3 = vram_tile_copy
    jsr @r3                               ! upload tile pattern data A to VRAM
    mov r14, r6                           ! r6 = 0 (source offset / delay slot)
    mov #0x8, r7                          ! r7 = 8 (DMA transfer mode / tile count)
    mov.l   _pool_tile_size_b, r5         ! r5 = 0x17700 (tile pattern size B)
    mov.l   _pool_vdp2_vram_tile_b, r4   ! r4 = 0x25E761FC (VDP2 VRAM dest B)
    mov.l   _pool_fn_vram_tile_copy, r3  ! r3 = vram_tile_copy
    jsr @r3                               ! upload tile pattern data B to VRAM
    mov r14, r6                           ! r6 = 0 (source offset / delay slot)
    mov r14, r6                           ! r6 = 0 (clear for display list setup)
    mov.l   _pool_display_layer_params, r2 ! r2 = &display_layer_params struct
    mov.l r2, @r15                        ! save struct ptr on stack
    mov r2, r7                            ! r7 = &display_layer_params (for field access)
    mov r2, r5                            ! r5 = &display_layer_params (source ptr)
    mov.l   _pool_display_offset, r3      ! r3 = 0xA000 (display list base offset)
    mov.l @(4, r7), r7                    ! r7 = display_layer_params[+4] (layer height)
    mov.l @r5, r5                         ! r5 = display_layer_params[+0] (layer base)
    add r3, r7                            ! r7 += 0xA000 (apply display base offset)
    mov.l   _pool_fn_display_list_load, r3 ! r3 = display_list_loader
    jsr @r3                               ! load display list: mode=4, dest=r4, src=r5, end=r7
    mov #0x4, r4                          ! r4 = 4 (display list mode / delay slot)
    mov #0x1, r2                          ! r2 = 1
    mov.l   _pool_light_active_flag, r3   ! r3 = &light_active_flag (byte)
    mov.b r2, @r3                         ! light_active_flag = 1 (enable start lights)
    .byte   0xB9, 0xAC    /* bsr 0x06019928 (track_seg_phys_init) */
    nop
    .byte   0xB0, 0x45    /* bsr 0x0601A65E (car_init_handler) */
    nop
    .byte   0xB1, 0x1A    /* bsr 0x0601A80C (course_data_rom_load) */
    nop
    .byte   0xB1, 0xB2    /* bsr 0x0601A940 (course_init_pipeline) */
    nop
    mov.l   _pool_frame_counter_a, r3     ! r3 = &frame_counter_a (byte)
    mov.b r14, @r3                        ! frame_counter_a = 0 (reset)
    mov.l   _pool_frame_counter_b, r3     ! r3 = &frame_counter_b (byte)
    mov.b r14, @r3                        ! frame_counter_b = 0 (reset)
    mov.l   _pool_anim_reset_byte, r3     ! r3 = &anim_reset_byte
    mov.b r14, @r3                        ! anim_reset_byte = 0 (reset)
    mov.l   _pool_fn_race_data, r3        ! r3 = race_data_handler
    jsr @r3                               ! call race_data_handler to init race state
    nop
    add #0x4, r15                         ! free stack allocation
    lds.l @r15+, pr                       ! restore return address
    mov.l   _pool_fn_palette_commit, r3   ! r3 = palette_frame_effects
    jmp @r3                               ! tail-call palette_frame_effects
    mov.l @r15+, r14                      ! restore r14 (delay slot)

    .global sym_0601A5F8
sym_0601A5F8:                             /* render_param_query — returns render param based on game timer */
    mov.l   _pool_game_timer, r0          ! r0 = &game_timer (16-bit)
    mov.w @r0, r0                         ! r0 = game_timer value (signed)
    extu.w r0, r0                         ! zero-extend to 32-bit
    cmp/eq #0x10, r0                      ! is timer == 0x10 (green light moment)?
    bf      .L_not_green_light            ! branch if timer != 0x10
    mov.w   _wpool_green_light_param, r0  ! r0 = 0x00A8 (green light render param)
    rts                                   ! return 0x00A8
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
.L_not_green_light:
    .byte   0x90, 0x40    /* mov.w .L_wpool_0601A6DC, r0 (cross-TU word pool) */
    rts                                   ! return alternate render param
    nop
