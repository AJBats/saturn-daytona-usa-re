/* obj_culling_pass -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06020814 - 0x06020946
 *
 * Object display setup for scene rendering pass. Initializes display layers,
 * loads a palette into VDP2 CRAM, copies display list segments from the
 * obj/replay struct into VDP1 command buffers, sets collision-update and
 * display-commit flags, and clears per-object animation state.
 *
 * Phase 1: Display layer init -- render_state_commit, gameover_channel_setup,
 *          memcpy_word_idx palette into VDP2 CRAM +0x200
 * Phase 2: Display list copy -- display_list_copy from struct[0x560]+0 (list B)
 * Phase 3: Flag set -- display_flags |= 0x04000000 (collision update, bit 26),
 *          display_timer = 1, frame_ready_flag = 0, display_update()
 * Phase 4: Flag set -- display_flags |= 0x04000000 again, display_timer = 3,
 *          frame_ready_flag = 0, display_update()
 * Phase 5: Display list copy -- 3 more calls from struct offsets 0x550, 0x368,
 *          0x378 with various size adjustments
 * Phase 6: Display layer config(0xC), clear obj_anim_mode_word, tail-jump to
 *          obj_anim_clear (0x06020DEE)
 */

    .section .text.FUN_06020814


    .global obj_culling_pass
    .type obj_culling_pass, @function
obj_culling_pass:
    mov.l r14, @-r15                        ! save r14
    mov r4, r0                              ! r0 = obj index arg
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    sts.l pr, @-r15                         ! save return address
    add #-0x8, r15                          ! allocate 0x8 bytes on stack
    mov.l   .L_fn_render_state_commit, r3   ! --- Phase 1: display layer init ---
    jsr @r3                                 ! render_state_commit()
    mov.b r0, @(4, r15)                     ! (delay) save obj index on stack[4]
    mov.l   .L_fn_gameover_channel, r3
    jsr @r3                                 ! gameover_channel_setup()
    nop
    mov.l   .L_pal_src_cram200, r5          ! r5 = palette source data ptr
    mov.l   .L_vdp2_cram_0x200, r4          ! r4 = VDP2 CRAM dest (0x25F00200)
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3                                 ! memcpy_word_idx(CRAM+0x200, pal_src, 0x20)
    mov #0x20, r6                           ! (delay) r6 = 0x20 words to copy
    mov.l   .L_obj_struct_base, r13         ! --- Phase 2: display list copy (list B) ---
    mov.l   .L_fn_display_list_copy, r14    ! r13 = obj struct base, r14 = copy fn (reused)
    mov.w   .L_off_struct_0x560, r7         ! r7 = 0x560 (struct offset for list B ptr)
    add r13, r7                             ! r7 = &struct[0x560]
    mov.l r7, @r15                          ! save struct field ptr on stack[0]
    mov.l @(4, r7), r7                      ! r7 = struct[0x564] (size/len)
    mov.w   .L_copy_len_0x294, r6           ! r6 = 0x294 (copy length)
    mov.l @r15, r5                          ! r5 = &struct[0x560]
    mov.l @r5, r5                           ! r5 = struct[0x560] (src ptr)
    jsr @r14                                ! display_list_copy(0, src, size, 0x294)
    mov #0x0, r4                            ! (delay) r4 = 0 (channel/mode)
    mov #0x0, r11                           ! r11 = 0 (zero constant, reused)
    mov.l   .L_display_flags, r12           ! --- Phase 3: set flags + display_update ---
    mov.l   .L_collision_update_bit, r3     ! r12 = &display_flags, r3 = 0x04000000
    mov.l @r12, r2                          ! r2 = *display_flags
    or r3, r2                               ! r2 |= bit 26 (collision update trigger)
    mov.l r2, @r12                          ! *display_flags = r2
    mov #0x1, r3                            ! r3 = 1
    mov.l   .L_display_timer, r2            ! r2 = &display_timer
    mov.w r3, @r2                           ! display_timer = 1
    mov.l   .L_frame_ready_flag, r3         ! r3 = &frame_ready_flag
    mov.l r11, @r3                          ! frame_ready_flag = 0
    mov.l   .L_fn_display_update, r3
    jsr @r3                                 ! display_update()
    nop
    mov.l   .L_collision_update_bit, r2     ! --- Phase 4: set flags again + display_update ---
    mov.l @r12, r3                          ! r2 = 0x04000000, r3 = *display_flags
    or r2, r3                               ! r3 |= bit 26 (collision update trigger)
    mov.l r3, @r12                          ! *display_flags = r3
    mov #0x3, r2                            ! r2 = 3
    mov.l   .L_display_timer, r3            ! r3 = &display_timer
    mov.w r2, @r3                           ! display_timer = 3
    mov.l   .L_frame_ready_flag, r3         ! r3 = &frame_ready_flag
    mov.l r11, @r3                          ! frame_ready_flag = 0
    mov.l   .L_fn_display_update, r3
    jsr @r3                                 ! display_update()
    nop
    mov.w   .L_off_struct_0x550, r7         ! --- Phase 5: display list copies (3 more) ---
    add r13, r7                             ! r7 = &struct[0x550] (list C ptr field)
    mov.l r7, @r15                          ! save struct field ptr on stack[0]
    mov.l @(4, r7), r7                      ! r7 = struct[0x554] (size/len)
    mov.w   .L_size_adj_0x6000, r3          ! r3 = 0x6000 (size adjustment)
    mov.w   .L_copy_len_0x82, r6            ! r6 = 0x82 (copy length)
    mov.l @r15, r5                          ! r5 = &struct[0x550]
    add r3, r7                              ! r7 += 0x6000 (adjust size)
    mov.l @r5, r5                           ! r5 = struct[0x550] (src ptr)
    jsr @r14                                ! display_list_copy(4, src, size+0x6000, 0x82)
    mov #0x4, r4                            ! (delay) r4 = 4 (channel/mode)
    mov.w   .L_display_list_addr_a, r7      ! r7 = 0x7C5A (fixed display list address)
    mov.w   .L_copy_len_0x61A, r6           ! r6 = 0x61A (copy length)
    mov.l   .L_display_list_src_fixed, r5   ! r5 = fixed display list source ptr
    jsr @r14                                ! display_list_copy(4, fixed_src, 0x7C5A, 0x61A)
    mov #0x4, r4                            ! (delay) r4 = 4 (channel/mode)
    mov.w   .L_off_struct_0x368, r7         ! r7 = 0x368 (struct offset for list D)
    add r13, r7                             ! r7 = &struct[0x368]
    mov.l r7, @r15                          ! save struct field ptr on stack[0]
    mov.l @(4, r7), r7                      ! r7 = struct[0x36C] (size/len)
    mov.w   .L_size_adj_0x3000, r3          ! r3 = 0x3000 (size adjustment)
    mov.w   .L_copy_len_0x898, r6           ! r6 = 0x898 (copy length)
    mov.l @r15, r5                          ! r5 = &struct[0x368]
    add r3, r7                              ! r7 += 0x3000 (adjust size)
    mov.l @r5, r5                           ! r5 = struct[0x368] (src ptr)
    jsr @r14                                ! display_list_copy(4, src, size+0x3000, 0x898)
    mov #0x4, r4                            ! (delay) r4 = 4 (channel/mode)
    mov.w   .L_off_struct_0x378, r7         ! r7 = 0x378 (struct offset for list E)
    add r13, r7                             ! r7 = &struct[0x378]
    mov.l r7, @r15                          ! save struct field ptr on stack[0]
    mov.l @(4, r7), r7                      ! r7 = struct[0x37C] (size/len)
    mov.w   .L_size_adj_0x4000, r3          ! r3 = 0x4000 (size adjustment)
    mov.w   .L_copy_len_0x8B0, r6           ! r6 = 0x8B0 (copy length)
    mov.l @r15, r5                          ! r5 = &struct[0x378]
    add r3, r7                              ! r7 += 0x4000 (adjust size)
    mov.l @r5, r5                           ! r5 = struct[0x378] (src ptr)
    jsr @r14                                ! display_list_copy(4, src, size+0x4000, 0x8B0)
    mov #0x4, r4                            ! (delay) r4 = 4 (channel/mode)
    mov.l   .L_fn_display_layer_cfg, r3     ! --- Phase 6: layer config + cleanup ---
    jsr @r3                                 ! display_layer_cfg(0xC)
    mov #0xC, r4                            ! (delay) r4 = 0xC (layer config mode)
    mov.l   .L_obj_anim_mode_word, r3       ! r3 = &obj_anim_mode_word
    mov.w r11, @r3                          ! obj_anim_mode_word = 0 (clear)
    mov.b @(4, r15), r0                     ! r0 = saved obj index from stack[4]
    mov r0, r4                              ! r4 = obj index
    extu.b r4, r4                           ! r4 = zero-extend to unsigned byte
    add #0x8, r15                           ! free stack frame
    lds.l @r15+, pr                         ! restore return address
    bra     .L_epilogue                     ! jump to epilogue (restore regs + tail-jump)
    nop
.L_off_struct_0x560:
    .2byte  0x0560                          /* struct offset: display list B ptr */
.L_copy_len_0x294:
    .2byte  0x0294                          /* copy length for list B */
.L_off_struct_0x550:
    .2byte  0x0550                          /* struct offset: display list C ptr */
.L_size_adj_0x6000:
    .2byte  0x6000                          /* size adjustment for list C */
.L_copy_len_0x82:
    .2byte  0x0082                          /* copy length for list C */
.L_display_list_addr_a:
    .2byte  0x7C5A                          /* fixed display list address */
.L_copy_len_0x61A:
    .2byte  0x061A                          /* copy length for fixed list */
.L_off_struct_0x368:
    .2byte  0x0368                          /* struct offset: display list D ptr */
.L_size_adj_0x3000:
    .2byte  0x3000                          /* size adjustment for list D */
.L_copy_len_0x898:
    .2byte  0x0898                          /* copy length for list D */
.L_off_struct_0x378:
    .2byte  0x0378                          /* struct offset: display list E ptr */
.L_size_adj_0x4000:
    .2byte  0x4000                          /* size adjustment for list E */
.L_copy_len_0x8B0:
    .2byte  0x08B0                          /* copy length for list E */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit / clear */
.L_fn_gameover_channel:
    .4byte  gameover_channel_setup          /* game-over display channel setup */
.L_pal_src_cram200:
    .4byte  sym_060489CC                    /* palette source for CRAM +0x200 */
.L_vdp2_cram_0x200:
    .4byte  0x25F00200                      /* VDP2 color RAM +0x200 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                 /* word-indexed memcpy */
.L_obj_struct_base:
    .4byte  sym_06063750                    /* obj/replay struct base ptr */
.L_fn_display_list_copy:
    .4byte  sym_06028400                    /* display list copy function */
.L_display_flags:
    .4byte  sym_0605B6D8                    /* display/event flags (32-bit) */
.L_collision_update_bit:
    .4byte  0x04000000                      /* bit 26 mask — collision update trigger */
.L_display_timer:
    .4byte  sym_0608780C                    /* display timer (16-bit word) */
.L_frame_ready_flag:
    .4byte  sym_0605A00C                    /* frame-ready flag (0 = not ready) */
.L_fn_display_update:
    .4byte  sym_06026CE0                    /* display update / render commit */
.L_display_list_src_fixed:
    .4byte  sym_0604BBCC                    /* fixed display list source data */
.L_fn_display_layer_cfg:
    .4byte  sym_0602853E                    /* display layer fill config */
.L_obj_anim_mode_word:
    .4byte  sym_06087828                    /* obj animation mode (16-bit word) */
.L_epilogue:
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    .byte   0xA2, 0x54    /* bra 0x06020DEE (external) — tail-jump to obj_anim_clear */
    mov.l @r15+, r14                        ! (delay) restore r14
