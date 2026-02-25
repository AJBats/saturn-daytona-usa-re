/* race_cleanup_handler -- post-race teardown state machine
 * Translation unit: 0x060121A8 - 0x0601228A
 *
 * Called from state 16 (post-countdown) and state 17 (post-lap results)
 * to animate the car teardown sequence over ~40 frames.
 *
 * Maintains a frame counter at sym_060788AC (cleanup_frame_counter).
 * Three phases:
 *
 *   Phase 1 (frames 0-19): Draw the car model each frame via the display
 *     list loader (sym_06028400) using VDP1 sprite offset 0x0390 and
 *     data from the model table (sym_06063AF0 + 0xB000). Calls the lap
 *     display updater (0x060125D0) every frame.
 *
 *   Phase 2 (frame 20): Transition frame — sends a race-end sound command
 *     (0xAE110EFF) via sound_cmd_dispatch, then issues three VDP text
 *     render calls to clear HUD text layers (offsets 0x0090, 0x0490,
 *     0x0590) using string source sym_0605ACF0. Tail-calls VDP text
 *     renderer (sym_060283E0) with priority mask 0xE000.
 *
 *   Phase 3 (frames 21-40): Calls file_data_parse (0x06012344) then
 *     tail-branches to file_block_read (0x06012400).
 *
 *   Termination (frame >40): Clears a control flag and tail-calls
 *     sound_cmd_dispatch(r4=0) to silence the sound subsystem.
 *
 * Calls: sym_06028400 (display list loader), sym_060284AE (VDP number/text
 *   renderer), sym_060283E0 (VDP text renderer), sound_cmd_dispatch,
 *   file_data_parse (0x06012344), file_block_read (0x06012400)
 */

    .section .text.FUN_060121A8


    .global race_cleanup_handler
    .type race_cleanup_handler, @function
race_cleanup_handler:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    mov.l r13, @-r15                        ! save r13 (callee-saved)
    sts.l pr, @-r15                         ! save return address
    add #-0x4, r15                          ! allocate 4 bytes stack local
    mov.l   .L_pool_cleanup_frame_counter, r14 ! r14 = &cleanup_frame_counter (persists)
    mov.l @r14, r3                          ! r3 = current frame count
    add #0x1, r3                            ! r3 = frame_count + 1
    mov r3, r2                              ! r2 = new frame count (for compare)
    mov.l r3, @r14                          ! *cleanup_frame_counter = frame_count + 1
    mov #0x14, r3                           ! r3 = 0x14 (phase 1 end threshold = 20)
    cmp/ge r3, r2                           ! frame_count >= 20?
    bt      .L_check_transition             ! yes → skip phase 1 drawing
    mov.l   .L_pool_model_table_base, r3    ! r3 = &model_table (sym_06063AF0)
    mov.l r3, @r15                          ! stack[0] = &model_table (save for later)
    mov r3, r7                              ! r7 = &model_table
    mov.w   .L_wpool_vdp1_sprite_offset, r6 ! r6 = 0x0390 (VDP1 sprite cmd offset)
    mov.l @r15, r5                          ! r5 = &model_table (reload from stack)
    mov.l @(4, r7), r7                      ! r7 = model_table.data_ptr (+4)
    mov.l   .L_pool_model_data_offset, r3   ! r3 = 0xB000 (model data offset)
    mov.l @r5, r5                           ! r5 = model_table[0] (base addr)
    add r3, r7                              ! r7 = data_ptr + 0xB000 (actual model data)
    mov.l   .L_pool_fn_dlist_loader, r3     ! r3 = &display_list_loader (sym_06028400)
    jsr @r3                                 ! dlist_loader(r4=8, r5=base, r6=0x390, r7=data)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (DMA draw mode)
    .byte   0xB1, 0xFA    /* bsr 0x060125D0 (external) */  ! call lap_display_update
    nop                                     ! (delay slot)
.L_check_transition:                        ! === Phase 2 check: exact frame 20 ===
    mov.l @r14, r0                          ! r0 = cleanup_frame_counter
    cmp/eq #0x14, r0                        ! frame_count == 20?
    bf      .L_not_transition_frame         ! no → check phases 3/4
    mov.l   .L_pool_snd_cmd_race_end, r5   ! r5 = 0xAE110EFF (race end SFX cmd)
    mov.l   .L_pool_fn_sound_dispatch, r3  ! r3 = &sound_cmd_dispatch
    jsr @r3                                 ! sound_cmd_dispatch(r4=0, r5=race_end_sfx)
    mov #0x0, r4                            ! (delay) r4 = 0 (channel 0)
    mov.l   .L_pool_hud_text_source, r13   ! r13 = &hud_text_string (sym_0605ACF0, persists)
    mov.w   .L_wpool_text_offset_a, r6     ! r6 = 0x0090 (text layer A offset)
    mov.w   .L_wpool_vdp1_sprite_offset, r5 ! r5 = 0x0390 (source VDP1 offset)
    mov.l   .L_pool_fn_vdp_text_render, r3 ! r3 = &vdp_text_renderer (sym_060284AE)
    mov r13, r7                             ! r7 = &hud_text_string (data source)
    jsr @r3                                 ! vdp_text_render(8, 0x0390, 0x0090, text_src)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (render mode)
    mov r13, r7                             ! r7 = &hud_text_string (reuse)
    mov.w   .L_wpool_text_offset_a, r6     ! r6 = 0x0090 (text layer A offset)
    mov.w   .L_wpool_text_offset_b, r5     ! r5 = 0x0490 (text layer B offset)
    mov.l   .L_pool_fn_vdp_text_render, r3 ! r3 = &vdp_text_renderer
    jsr @r3                                 ! vdp_text_render(8, 0x0490, 0x0090, text_src)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (render mode)
    mov r13, r7                             ! r7 = &hud_text_string (reuse)
    mov.l   .L_mask_0xE000, r6             ! r6 = 0xE000 (priority bits mask)
    mov.w   .L_wpool_text_offset_c, r5     ! r5 = 0x0590 (text layer C offset)
    mov #0x8, r4                            ! r4 = 0x8 (render mode)
    add #0x4, r15                           ! free stack local
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    mov.l   .L_pool_fn_vdp_text_dispatch, r3 ! r3 = &vdp_text_dispatch (sym_060283E0)
    jmp @r3                                 ! tail-call vdp_text_dispatch(8, 0x0590, 0xE000, text_src)
    mov.l @r15+, r14                        ! (delay) restore r14
.L_wpool_vdp1_sprite_offset:
    .2byte  0x0390                          /* VDP1 sprite cmd list offset (car model) */
.L_wpool_text_offset_a:
    .2byte  0x0090                          /* VDP text layer A offset */
.L_wpool_text_offset_b:
    .2byte  0x0490                          /* VDP text layer B offset */
.L_wpool_text_offset_c:
    .2byte  0x0590                          /* VDP text layer C offset */
    .4byte  sym_0607EAD8                    /* race end state flag (read by adjacent TU) */
.L_pool_cleanup_frame_counter:
    .4byte  sym_060788AC                    /* cleanup frame counter (dword) */
.L_pool_model_table_base:
    .4byte  sym_06063AF0                    /* car model geometry table base */
.L_pool_model_data_offset:
    .4byte  0x0000B000                      /* offset into model data block */
.L_pool_fn_dlist_loader:
    .4byte  sym_06028400                    /* display list loader / DMA dispatch */
.L_pool_snd_cmd_race_end:
    .4byte  0xAE110EFF                      /* sound cmd: race end cleanup SFX */
.L_pool_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
.L_pool_hud_text_source:
    .4byte  sym_0605ACF0                    /* HUD text string source data */
.L_pool_fn_vdp_text_render:
    .4byte  sym_060284AE                    /* VDP number/text renderer */
.L_mask_0xE000:
    .4byte  0x0000E000                      /* priority bits mask (bits 15:13) */
.L_pool_fn_vdp_text_dispatch:
    .4byte  sym_060283E0                    /* VDP text dispatch (tail call target) */
.L_not_transition_frame:                    ! === Phase 4: termination (frame > 40) ===
    mov.l @r14, r2                          ! r2 = cleanup_frame_counter
    mov #0x28, r3                           ! r3 = 0x28 (40 = termination threshold)
    cmp/gt r3, r2                           ! frame_count > 40?
    bf      .L_check_phase3                 ! no → check if in phase 3 range
    mov #0x0, r3                            ! r3 = 0 (clear value)
    .byte   0xD2, 0x1D    /* mov.l .L_pool_060122CC, r2 */  ! r2 = &control_flag (in next TU pool)
    mov.b r3, @r2                           ! *control_flag = 0 (clear cleanup active)
    .byte   0xD5, 0x1D    /* mov.l .L_pool_060122D0, r5 */  ! r5 = sound param (in next TU pool)
    mov r3, r4                              ! r4 = 0 (silence channel)
    add #0x4, r15                           ! free stack local
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060122D4, r3 */  ! r3 = &sound_cmd_dispatch (next TU pool)
    jmp @r3                                 ! tail-call sound_cmd_dispatch(0, sound_param)
    mov.l @r15+, r14                        ! (delay) restore r14
.L_check_phase3:                            ! === Phase 3: frames 21-40 ===
    mov #0x14, r3                           ! r3 = 0x14 (20)
    mov.l @r14, r2                          ! r2 = cleanup_frame_counter
    cmp/gt r3, r2                           ! frame_count > 20?
    bf      .L_exit                         ! no → nothing to do, return
    .byte   0xB0, 0x67    /* bsr 0x06012344 (external) */  ! call file_data_parse
    nop                                     ! (delay slot)
    add #0x4, r15                           ! free stack local
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    .byte   0xA0, 0xC0    /* bra 0x06012400 (external) */  ! tail-branch to file_block_read
    mov.l @r15+, r14                        ! (delay) restore r14
.L_exit:                                    ! === Early exit: counter <= 20, not exact ===
    add #0x4, r15                           ! free stack local
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14
