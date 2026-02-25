/* geom_output_main -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601F5D0 - 0x0601FD74
 *
 * Geometry output pipeline: buffer management, vertex dispatch, and
 * VDP2 scroll/tilemap DMA coordination. Double-buffered geometry
 * output with mode-dependent scroll configuration (modes 4/8/C).
 *
 * Functions:
 *   mem_pool_reset        -- select buffer 0, tail-call vertex process
 *   geom_render_util      -- full render pass: overlay, normals, output,
 *                            buffer swap, title string, rotation apply
 *   geom_output_finalize  -- copy geometry data by buffer index, pad
 *                            remaining buffer, clear dirty flag
 *   .L_select_buffer      -- internal: set active buffer (0 or 1),
 *                            configure base pointer and swap flag
 *   sym_0601F8BC           -- RTS stub (no-op)
 *   geom_output_ctrl      -- orchestrator: render_util + output_main
 *   geom_output_dispatch  -- check VDP2 status, DMA or display ctrl
 *   resource_validator    -- sync render: select buffer, vertex process,
 *                            display sync, wait for VDP2 vblank
 *   geom_output_main      -- main output: priority setup, mode dispatch
 *                            (single/multi scroll), channel config, DMA
 *   geom_display_ctrl_a   -- set display control bit 2, clear 5 counters
 */

    .section .text.FUN_0601F5D0


    .global mem_pool_reset
    .type mem_pool_reset, @function
mem_pool_reset:
    sts.l pr, @-r15
    bsr     .L_select_buffer          ! select buffer 0
    mov #0x0, r4                      ! r4 = 0 (buffer index 0)
    mov.l   .L_fn_geom_vertex_process, r3
    jmp @r3                           ! tail-call geom_vertex_process
    lds.l @r15+, pr
.L_fn_geom_vertex_process:
    .4byte  geom_vertex_process

    .global geom_render_util
    .type geom_render_util, @function
geom_render_util:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov #0x40, r11                    ! r11 = 0x40 (pad byte value)
    sts.l macl, @-r15
    mov r11, r12
    mov.w   DAT_0601f6ba, r13         ! r13 = 0x2710 (buffer capacity)
    mov.l   .L_geom_buf_base, r14     ! r14 = geometry buffer base
    add #0x40, r12                    ! r12 = 0x80 (pad byte 2)
    bsr     .L_select_buffer          ! select buffer 0
    mov #0x0, r4
    mov.l   .L_fn_hud_overlay_render_a, r3
    jsr @r3                           ! call hud_overlay_render
    nop
    mov.l   .L_fn_geom_normal_compute, r3
    jsr @r3                           ! call geom_normal_compute
    nop
    mov.l   .L_fn_geom_output_handler, r3
    jsr @r3                           ! call geom_output_handler
    nop
    mov.l   .L_render_active_flag, r0
    mov.b @r0, r0                     ! read render active flag
    extu.b r0, r0
    tst r0, r0
    bf      .L_render_active          ! if active, process geometry
    bra     .L_render_skip_epilog     ! else skip to return
    nop
.L_render_active:
    mov.l   .L_geom_cmd_buffer, r4   ! r4 = cmd buffer dest
    mov.b @(4, r14), r0               ! copy 4 bytes from buf[4..7]
    mov r0, r2
    mov.b r2, @r4                     ! write byte 0 to cmd buffer
    add #0x1, r4
    mov.b @(5, r14), r0
    mov r0, r2
    mov.b r2, @r4                     ! write byte 1
    add #0x1, r4
    mov.b @(6, r14), r0
    mov r0, r2
    mov.b r2, @r4                     ! write byte 2
    add #0x1, r4
    mov.b @(7, r14), r0
    mov r0, r3
    mov.b r3, @r4                     ! write byte 3
    mov.l   .L_geom_cmd_buffer, r4
    mov.l   .L_geom_cmd_src, r3
    mov.l @r4, r2                     ! r2 = cmd buffer value (as long)
    mov.l @r3, r3                     ! r3 = source reference value
    cmp/hs r2, r3                     ! if src >= cmd, skip
    bf      .L_cmd_buffer_valid
    mov.l @r4, r0
    tst r0, r0                        ! also skip if cmd == 0
    bt      .L_cmd_buffer_valid
    bra     .L_render_skip_epilog
    nop
.L_cmd_buffer_valid:
    mov #0x1, r3
    mov.l   .L_render_dirty_flag, r2
    mov.b r3, @r2                     ! set dirty flag = 1
    mov.l   .L_buf_index, r3
    mov.l   .L_prev_buf_index, r2
    mov.l @r3, r3
    mov.b r3, @r2                     ! save current buf index as prev
    mov.l   .L_geom_cmd_src, r4
    mov.b @r4+, r0                    ! copy 4 bytes from source to buf[4..7]
    mov.b r0, @(4, r14)
    mov.b @r4+, r0
    mov.b r0, @(5, r14)
    mov.b @r4+, r2
    mov r2, r0
    mov.b r0, @(6, r14)
    mov.b @r4, r0
    mov.b r0, @(7, r14)
    mov.l   .L_buf_write_pos, r4
    mov.l @r4, r4                     ! r4 = current write position
    cmp/hs r13, r4                    ! if pos >= capacity, skip pad
    bt      .L_pad_complete
.L_pad_buffer_loop:                   ! fill remaining buffer with pad bytes
    mov r4, r0
    extu.b r12, r3
    add #0x1, r4
    mov.b r11, @(r0, r14)            ! write 0x40 pad byte
    mov r4, r0
    add #0x1, r4
    cmp/hs r13, r4
    bf/s    .L_pad_buffer_loop
    mov.b r3, @(r0, r14)             ! write 0x80 pad byte
.L_pad_complete:
    mov.l   .L_buf_index, r4
    mov.l @r4, r4
    add #0x1, r4                      ! advance to next buffer
    bsr     .L_select_buffer
    extu.b r4, r4                     ! wrap to byte range
    mov.l   .L_title_string_ptr_a, r5
    mov.l @r5, r0
    tst r0, r0
    bt/s    .L_check_title_ptr_b
    mov #0x0, r4
    mov.l @r5, r4
.L_check_title_ptr_b:
    mov.l   .L_title_string_ptr_b, r5
    mov.l @r5, r0
    tst r0, r0
    bt      .L_check_title_null
    mov.l @r5, r4
.L_check_title_null:
    mov.l   .L_obj_entry_table, r6
    mov.l   .L_active_buf_slot, r5
    tst r4, r4
    bt      .L_write_default_DAY
    mov.b @r5, r3
    bra     .L_copy_title_from_ptr
    nop

    .global DAT_0601f6ba
DAT_0601f6ba:
    .2byte  0x2710
.L_geom_buf_base:
    .4byte  sym_0607ED90
.L_fn_hud_overlay_render_a:
    .4byte  hud_overlay_render
.L_fn_geom_normal_compute:
    .4byte  geom_normal_compute
.L_fn_geom_output_handler:
    .4byte  geom_output_handler
.L_render_active_flag:
    .4byte  sym_06078635
.L_geom_cmd_buffer:
    .4byte  sym_060877F0
.L_geom_cmd_src:
    .4byte  sym_060786A4
.L_render_dirty_flag:
    .4byte  sym_0605E0A1
.L_buf_index:
    .4byte  sym_0607EAD8
.L_prev_buf_index:
    .4byte  sym_0605E0A0
.L_buf_write_pos:
    .4byte  sym_0607ED88
.L_title_string_ptr_a:
    .4byte  sym_06085FFC
.L_title_string_ptr_b:
    .4byte  sym_06086000
.L_obj_entry_table:
    .4byte  sym_0605E06C
.L_active_buf_slot:
    .4byte  sym_060877D8
.L_copy_title_from_ptr:
    mov #0xB, r2
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @r4, r0
    mov.b r0, @(7, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @(1, r4), r0
    mov.b r0, @(8, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov.b @(2, r4), r0
    mov.b r0, @(9, r3)
    bra     .L_title_written
    mov r0, r1
.L_write_default_DAY:
    mov.b @r5, r2
    mov #0xB, r3
    muls.w r3, r2
    sts macl, r2
    exts.b r2, r2
    add r6, r2
    mov #0x44, r0                     ! 'D' (0x44)
    mov.b r0, @(7, r2)
    mov.b @r5, r3
    mov #0xB, r2
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov #0x41, r0                     ! 'A' (0x41)
    mov.b r0, @(8, r3)
    mov.b @r5, r3
    muls.w r2, r3
    sts macl, r3
    exts.b r3, r3
    add r6, r3
    mov #0x59, r1                     ! 'Y' (0x59) -- writes "DAY"
    mov r1, r0
    mov.b r0, @(9, r3)
.L_title_written:
    mov.l   .L_fn_hud_overlay_render_b, r3
    jsr @r3                           ! call hud_overlay_render (post)
    nop
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_geom_rotation_apply, r3
    jmp @r3                           ! tail-call geom_rotation_apply
    mov.l @r15+, r14
.L_render_skip_epilog:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_hud_overlay_render_b:
    .4byte  hud_overlay_render
.L_fn_geom_rotation_apply:
    .4byte  geom_rotation_apply

    .global geom_output_finalize
    .type geom_output_finalize, @function
geom_output_finalize:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x40, r11                    ! r11 = 0x40 (pad byte value)
    mov.l r9, @-r15
    mov r11, r12
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0601f804, r13         ! r13 = 0x2710 (buffer capacity)
    mov.l   .L_geom_buf_base_b, r14   ! r14 = geometry buffer base
    mov.l   .L_render_active_flag_b, r0
    mov.b @r0, r0                     ! check render active flag
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_finalize_epilog        ! if not active, skip
    add #0x40, r12                    ! r12 = 0x80 (pad byte 2)
    mov.l   .L_buf_index_b, r10
    mov.l @r10, r4
    add #0x1, r4                      ! advance buffer index
    bsr     .L_select_buffer
    extu.b r4, r4
    mov.l   .L_fn_hud_overlay_render_c, r3
    jsr @r3                           ! call hud_overlay_render
    nop
    mov.l   .L_fn_geom_coord_calc, r3
    jsr @r3                           ! call geom_coord_calc
    nop
    extu.b r0, r0                     ! r0 = return value
    tst r0, r0
    bf      .L_finalize_pad_buffer    ! if nonzero, go pad buffer
    mov.l   .L_render_dirty_flag_b, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_copy_by_buf_index
    mov.l   .L_prev_buf_index_b, r3
    mov.l   .L_buf_index_b, r2
    mov.b @r3, r3
    mov.l @r2, r2
    extu.b r3, r3
    cmp/eq r2, r3
    bt      .L_finalize_pad_buffer
.L_copy_by_buf_index:                 ! copy geometry data by buffer index
    mov.l   .L_copy_src_offset, r8    ! r8 = 0x002F8000 (src offset)
    mov.l   .L_fn_memcpy_long_idx, r9 ! r9 = memcpy function
    mov.l @r10, r0                    ! r0 = buffer index
    tst r0, r0
    bf      .L_try_buf_index_1
    mov.w   DAT_0601f806, r6          ! index 0: len = 0x1900
    mov r8, r5
    jsr @r9                           ! memcpy_long_idx(buf, src, len)
    mov r14, r4
    bra     .L_finalize_pad_buffer
    nop
.L_try_buf_index_1:
    mov.l @r10, r0
    cmp/eq #0x1, r0
    bf      .L_try_buf_index_2
    mov r8, r5
    mov.w   .L_copy_len_buf1, r6      ! index 1: len = 0x2328
    jsr @r9                           ! memcpy_long_idx(buf, src, len)
    mov r14, r4
    bra     .L_finalize_pad_buffer
    nop

    .global DAT_0601f804
DAT_0601f804:
    .2byte  0x2710

    .global DAT_0601f806
DAT_0601f806:
    .2byte  0x1900
.L_copy_len_buf1:
    .2byte  0x2328
    .2byte  0xFFFF
.L_geom_buf_base_b:
    .4byte  sym_0607ED90
.L_render_active_flag_b:
    .4byte  sym_06078635
.L_buf_index_b:
    .4byte  sym_0607EAD8
.L_fn_hud_overlay_render_c:
    .4byte  hud_overlay_render
.L_fn_geom_coord_calc:
    .4byte  geom_coord_calc
.L_render_dirty_flag_b:
    .4byte  sym_0605E0A1
.L_prev_buf_index_b:
    .4byte  sym_0605E0A0
.L_copy_src_offset:
    .4byte  0x002F8000
.L_fn_memcpy_long_idx:
    .4byte  memcpy_long_idx
.L_try_buf_index_2:
    mov.l @r10, r0
    cmp/eq #0x2, r0
    bf      .L_finalize_pad_buffer
    mov r13, r6                       ! index 2: len = 0x2710 (full capacity)
    mov r8, r5
    jsr @r9                           ! memcpy_long_idx(buf, src, len)
    mov r14, r4
.L_finalize_pad_buffer:
    mov.l   .L_active_buf_slot_b, r4
    mov.l   .L_buf_size_table, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    cmp/hs r13, r4
    bt      .L_finalize_clear_dirty
.L_finalize_pad_loop:
    mov r4, r0
    extu.b r12, r3
    add #0x1, r4
    mov.b r11, @(r0, r14)
    mov r4, r0
    add #0x1, r4
    cmp/hs r13, r4
    bf/s    .L_finalize_pad_loop
    mov.b r3, @(r0, r14)
.L_finalize_clear_dirty:
    mov #0x0, r3
    mov.l   .L_render_dirty_clear, r2
    mov.b r3, @r2                     ! clear render dirty flag
.L_finalize_epilog:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_select_buffer:                     ! select geometry buffer 0 or 1
    mov.l   .L_active_buf_slot_b, r3
    mov.b r4, @r3                     ! store active buffer slot
    extu.b r4, r4
    mov.l   .L_buf_swap_flag, r6
    mov.l   .L_buf_base_ptr, r5
    tst r4, r4
    bf      .L_set_buf1               ! if r4 != 0, use buffer 1
    mov.l   .L_buf0_base_addr, r3
    mov.l r3, @r5                     ! set base ptr to buffer 0
    mov #0x0, r2
    bra     .L_buf_select_done
    mov.b r2, @r6                     ! swap flag = 0
.L_set_buf1:
    mov.l   .L_buf1_base_addr, r2
    mov.l r2, @r5                     ! set base ptr to buffer 1
    mov #0x1, r3
    mov.b r3, @r6                     ! swap flag = 1
.L_buf_select_done:
    rts
    nop
    .2byte  0xFFFF
.L_active_buf_slot_b:
    .4byte  sym_060877D8
.L_buf_size_table:
    .4byte  sym_0604A5C0
.L_render_dirty_clear:
    .4byte  sym_0605E0A1
.L_buf_swap_flag:
    .4byte  sym_06087080
.L_buf_base_ptr:
    .4byte  sym_0605E098
.L_buf0_base_addr:
    .4byte  sym_060A0FA8
.L_buf1_base_addr:
    .4byte  sym_0607ED90

    .global sym_0601F8BC
sym_0601F8BC:
    rts
    nop

    .global geom_output_ctrl
    .type geom_output_ctrl, @function
geom_output_ctrl:
    sts.l pr, @-r15
    mov #0x0, r3
    mov.l   .L_output_dirty_flag, r2
    mov.b r3, @r2                     ! clear dirty flag
    bsr     geom_render_util          ! run render pass
    nop
    mov.l   .L_output_dirty_flag, r2
    mov.b @r2, r2                     ! check if render set dirty
    extu.b r2, r2
    tst r2, r2
    bf      .L_output_dirty_path      ! if dirty, do output pipeline
    lds.l @r15+, pr
    rts
    mov #0x1, r0                      ! return 1 (no output needed)
.L_output_dirty_path:
    mov.l   .L_fn_pre_output_setup, r3
    jsr @r3                           ! pre-output setup
    nop
    bsr     geom_output_main          ! main geometry output
    nop
    mov.l   .L_fn_post_output_cleanup, r3
    jsr @r3                           ! post-output cleanup
    nop
    mov #0x0, r0                      ! return 0 (output done)
    lds.l @r15+, pr
    rts
    nop
.L_output_dirty_flag:
    .4byte  sym_0605E05C
.L_fn_pre_output_setup:
    .4byte  sym_060149E0
.L_fn_post_output_cleanup:
    .4byte  sym_060149CC

    .global geom_output_dispatch
    .type geom_output_dispatch, @function
geom_output_dispatch:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_vdp2_status_reg, r3
    mov.w @r3, r2                     ! read VDP2 status register
    mov.w   DAT_0601f962, r3          ! r3 = 0x0800 (vblank bit mask)
    extu.w r2, r2
    and r3, r2                        ! isolate vblank bit
    tst r2, r2
    bt      .L_no_vdp2_pending        ! if not in vblank, skip DMA
    mov.w   DAT_0601f964, r3          ! r3 = 0x4210 (tilemap color value)
    mov r15, r6
    mov.w r3, @r15                    ! store on stack as DMA source
    mov.l   .L_vdp2_vram_0x7FFFE, r4  ! VDP2 VRAM dest
    mov.l   .L_fn_tilemap_dma_update_a, r3
    jsr @r3                           ! tilemap_dma_update
    mov #0x1, r5                      ! count = 1 word
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #0x1, r0                      ! return 1 (DMA dispatched)
.L_no_vdp2_pending:
    bsr     geom_display_ctrl_a       ! reset display control state
    nop
    mov #0x0, r0                      ! return 0 (no DMA)
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

    .global sym_0601F936
sym_0601F936:
    mov #0x0, r3

    .global resource_validator
    .type resource_validator, @function
resource_validator:
    mov.l r14, @-r15
    mov r3, r4                        ! r4 = buffer index from caller
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0601f962, r13         ! r13 = 0x0800 (vblank bit mask)
    mov.l   .L_display_ctrl_state, r14
    mov.l   .L_output_dirty_flag_b, r2
    mov.b r3, @r2                     ! store buffer index as dirty flag
    bsr     .L_select_buffer
    nop
    mov.l   .L_fn_geom_vertex_process_b, r3
    jsr @r3                           ! call geom_vertex_process
    nop
    mov.l   .L_output_dirty_flag_b, r2
    mov.b @r2, r2                     ! check dirty flag
    extu.b r2, r2
    tst r2, r2
    bf      .L_validator_active       ! if dirty, do sync render
    bra     .L_validator_epilog       ! else return
    nop

    .global DAT_0601f962
DAT_0601f962:
    .2byte  0x0800

    .global DAT_0601f964
DAT_0601f964:
    .2byte  0x4210
    .2byte  0xFFFF
.L_vdp2_status_reg:
    .4byte  sym_06063D9A
.L_vdp2_vram_0x7FFFE:
    .4byte  0x25E7FFFE                  /* VDP2 VRAM +0x7FFFE */
.L_fn_tilemap_dma_update_a:
    .4byte  tilemap_dma_update
.L_display_ctrl_state:
    .4byte  sym_0605B6D8
.L_output_dirty_flag_b:
    .4byte  sym_0605E05C
.L_fn_geom_vertex_process_b:
    .4byte  geom_vertex_process
.L_validator_active:
    mov.l   .L_fp_min, r3             ! 0x80000000 (sign bit)
    mov.l @r14, r2
    or r3, r2                         ! set bit 31 of display ctrl
    mov.l   .L_fn_display_sync, r3
    jsr @r3                           ! display_sync (with bit 31 set)
    mov.l r2, @r14
    mov.l   .L_fn_display_sync, r3
    jsr @r3                           ! display_sync again
    nop
    bsr     geom_output_main          ! main geometry output
    nop
    mov.l   .L_fp_0x4000_0000, r2     ! 0x40000000 (bit 30)
    mov.l @r14, r3
    or r2, r3                         ! set bit 30 of display ctrl
    mov.l r3, @r14
    mov.l   .L_vdp2_status_reg_b, r12 ! r12 = VDP2 status register ptr
.L_wait_vdp2_sync:                    ! poll loop: wait for VDP2 vblank
    bsr     geom_display_ctrl_a       ! reset display ctrl each iteration
    nop
    mov.w @r12, r2                    ! read VDP2 status
    extu.w r2, r2
    and r13, r2                       ! mask vblank bit (0x0800)
    tst r2, r2
    bt      .L_not_yet_synced         ! if not in vblank, keep waiting
    bra     .L_vdp2_synced
    nop
.L_not_yet_synced:
    bra     .L_wait_vdp2_sync         ! loop back
    nop
.L_vdp2_synced:
    bsr     geom_display_ctrl_a       ! final display ctrl reset
    nop
    mov.l   .L_fp_min, r2             ! 0x80000000
    mov.l @r14, r3
    or r2, r3                         ! set bit 31 again
    mov.l r3, @r14
.L_validator_epilog:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global geom_output_main
    .type geom_output_main, @function
geom_output_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15                    ! allocate 8 bytes stack space
    mov.w   DAT_0601fa26, r3          ! r3 = 0x7C00
    mov r3, r0
    mov.w r0, @(4, r15)              ! store on stack for DMA later
    mov.l   .L_fn_priority_setup, r3
    jsr @r3                           ! priority_setup(0xC)
    mov #0xC, r4
    mov.l   .L_fn_priority_commit, r3
    jsr @r3                           ! priority_commit()
    nop
    mov.l   .L_scroll_config_table, r11  ! r11 = scroll config table base
    mov.l   .L_fn_scroll_dispatch, r12   ! r12 = scroll dispatch function
    mov.l   .L_render_mode, r0
    mov.l @r0, r0                     ! read render mode
    cmp/eq #0x1, r0
    bf      .L_multi_mode_path        ! if mode != 1, multi-scroll path
    mov #0x8, r7                      ! mode 1: single-scroll path
    mov.l   .L_tilemap_data_size, r5  ! size = 0x17700
    mov.l   .L_vdp2_vram_0x72194, r4  ! VDP2 VRAM dest
    mov.l   .L_fn_dma_tilemap_copy, r3
    jsr @r3                           ! DMA tilemap data to VRAM
    mov #0x0, r6
    mov.l   .L_palette_src_data, r5   ! palette source
    mov.l   .L_vdp2_cram_0x600, r4    ! VDP2 CRAM dest
    mov.l   .L_fn_memcpy_word_idx, r3
    jsr @r3                           ! copy 0x20 words of palette
    mov #0x20, r6
    mov.l   .L_output_dirty_flag_c, r0
    mov.b @r0, r0                     ! read dirty flag for sub-mode
    bra     .L_mode1_dispatch
    extu.b r0, r0
.L_dispatch_mode4:
    mov.w   .L_scroll_offset_mode4, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    bra     .L_dispatch_scroll_single
    mov #0x0, r6

    .global DAT_0601fa26
DAT_0601fa26:
    .2byte  0x7C00
.L_scroll_offset_mode4:
    .2byte  0x02C0
    .2byte  0xFFFF
.L_fp_min:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_fn_display_sync:
    .4byte  sym_06026CE0
.L_fp_0x4000_0000:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_vdp2_status_reg_b:
    .4byte  sym_06063D9A
.L_fn_priority_setup:
    .4byte  sym_0602853E
.L_fn_priority_commit:
    .4byte  sym_06028560
.L_scroll_config_table:
    .4byte  sym_06063750
.L_fn_scroll_dispatch:
    .4byte  sym_06028400
.L_render_mode:
    .4byte  sym_06078644
.L_tilemap_data_size:
    .4byte  0x00017700
.L_vdp2_vram_0x72194:
    .4byte  0x25E72194                  /* VDP2 VRAM +0x72194 */
.L_fn_dma_tilemap_copy:
    .4byte  sym_0600511E
.L_palette_src_data:
    .4byte  sym_0604894C
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_fn_memcpy_word_idx:
    .4byte  memcpy_word_idx
.L_output_dirty_flag_c:
    .4byte  sym_0605E05C
.L_dispatch_mode8:
    mov.w   DAT_0601fac4, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_len_mode8, r6
.L_dispatch_scroll_single:
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_dispatch_modeC:
    mov.w   DAT_0601fac8, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_len_modeC, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_mode1_dispatch:                    ! dispatch by sub-mode (4/8/C)
    cmp/eq #0x4, r0
    bt      .L_dispatch_mode4         ! sub-mode 4
    cmp/eq #0x8, r0
    bt      .L_dispatch_mode8         ! sub-mode 8
    cmp/eq #0xC, r0
    bt      .L_dispatch_modeC         ! sub-mode C
    bra     .L_configure_channels     ! unknown: skip to channel config
    nop
.L_multi_mode_path:                   ! multi-scroll path (mode != 1)
    mov.l   .L_palette_src_data_b, r5
    mov.l   .L_vdp2_cram_0x600_b, r4  ! VDP2 CRAM dest
    mov.l   .L_fn_memcpy_word_idx_b, r3
    jsr @r3                           ! copy palette to CRAM
    mov #0x20, r6                     ! 0x20 words
    mov.w   .L_multi_scroll_offset_a, r8  ! r8 = 0x0590 (scroll table offset A)
    mov r8, r9
    add #0x8, r9                      ! r9 = 0x0598 (scroll table offset B)
    mov.l   .L_fn_scroll_dispatch_b, r13  ! r13 = scroll dispatch fn
    mov.w   .L_multi_scroll_step, r14     ! r14 = 0x0090 (step between entries)
    mov.l   .L_output_dirty_flag_d, r0
    mov.b @r0, r0                     ! read sub-mode for multi-scroll
    bra     .L_multi_mode_dispatch
    extu.b r0, r0

    .global DAT_0601fac4
DAT_0601fac4:
    .2byte  0x02C8
.L_scroll_len_mode8:
    .2byte  0x0380

    .global DAT_0601fac8
DAT_0601fac8:
    .2byte  0x02D0
.L_scroll_len_modeC:
    .2byte  0x0400
.L_multi_scroll_offset_a:
    .2byte  0x0590
.L_multi_scroll_step:
    .2byte  0x0090
.L_palette_src_data_b:
    .4byte  sym_0605CD9C
.L_vdp2_cram_0x600_b:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_fn_memcpy_word_idx_b:
    .4byte  memcpy_word_idx
.L_fn_scroll_dispatch_b:
    .4byte  sym_060284AE
.L_output_dirty_flag_d:
    .4byte  sym_0605E05C
.L_multi_scroll_mode4:
    mov.l   .L_scroll_data_set_a, r10
    mov r14, r6
    mov.w   .L_scroll_ofs_0080, r5
    mov.l @r10, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0098, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0180, r5
    mov.l @(4, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(8, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0280, r5
    jsr @r13
    mov #0xC, r4
    mov r11, r9
    mov.w   DAT_0601fbae, r6
    add r8, r9
    mov.l @(4, r9), r7
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov.l @(12, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0400, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0500, r5
    mov.l @(16, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbb4, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0600, r5
    mov.l @(20, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(24, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0700, r5
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   .L_scroll_ofs_0730, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov.l @(28, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0800, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0900, r5
    mov.l @(32, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(36, r10), r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0A00, r5
    jsr @r13
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0B00, r5
    mov.l @(40, r10), r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbc4, r6
    mov.l @r9, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0C80, r5
    mov.l   .L_scroll_data_extra, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r9), r7
    mov.w   DAT_0601fbc8, r6
    bra     .L_final_scroll_dispatch
    mov.l @r9, r5
.L_scroll_ofs_0080:
    .2byte  0x0080
.L_scroll_ofs_0098:
    .2byte  0x0098
.L_scroll_ofs_0180:
    .2byte  0x0180
.L_scroll_ofs_0280:
    .2byte  0x0280

    .global DAT_0601fbae
DAT_0601fbae:
    .2byte  0x0296
.L_scroll_ofs_0400:
    .2byte  0x0400
.L_scroll_ofs_0500:
    .2byte  0x0500

    .global DAT_0601fbb4
DAT_0601fbb4:
    .2byte  0x0536
.L_scroll_ofs_0600:
    .2byte  0x0600
.L_scroll_ofs_0700:
    .2byte  0x0700
.L_scroll_ofs_0730:
    .2byte  0x0730
.L_scroll_ofs_0800:
    .2byte  0x0800
.L_scroll_ofs_0900:
    .2byte  0x0900
.L_scroll_ofs_0A00:
    .2byte  0x0A00
.L_scroll_ofs_0B00:
    .2byte  0x0B00

    .global DAT_0601fbc4
DAT_0601fbc4:
    .2byte  0x0B0E
.L_scroll_ofs_0C80:
    .2byte  0x0C80

    .global DAT_0601fbc8
DAT_0601fbc8:
    .2byte  0x0CD2
    .2byte  0xFFFF
.L_scroll_data_set_a:
    .4byte  sym_0605E0A4
.L_scroll_data_extra:
    .4byte  sym_0605E0E4
.L_multi_scroll_mode8:
    mov.l   .L_scroll_data_set_b, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0380, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0398, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0500_b, r5
    mov.l   .L_scroll_data_set_b2, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r10
    mov.w   DAT_0601fc94, r6
    add r8, r10
    mov.l @(4, r10), r7
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov.l   .L_scroll_data_set_b3, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0680, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   .L_scroll_ofs_06B2, r6
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0880, r5
    mov.l   .L_scroll_data_final, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   DAT_0601fc9c, r6
    mov.l @r10, r5
.L_final_scroll_dispatch:
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_multi_scroll_modeC:
    mov.l   .L_scroll_data_set_c, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0480, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_scroll_ofs_0498, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r14, r6
    mov.w   .L_scroll_ofs_0600_b, r5
    mov.l   .L_scroll_data_set_c2, r7
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov r11, r10
    mov.w   .L_scroll_ofs_0620, r6
    add r8, r10
    mov.l @(4, r10), r7
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    mov.l   .L_scroll_data_final, r7
    mov r14, r6
    mov.w   .L_scroll_ofs_0800_b, r5
    mov.l @r7, r7
    jsr @r13
    mov #0xC, r4
    mov.l @(4, r10), r7
    mov.w   .L_scroll_ofs_0852, r6
    mov.l @r10, r5
    jsr @r12
    mov #0xC, r4
    bra     .L_configure_channels
    nop
.L_scroll_ofs_0380:
    .2byte  0x0380
.L_scroll_ofs_0398:
    .2byte  0x0398
.L_scroll_ofs_0500_b:
    .2byte  0x0500

    .global DAT_0601fc94
DAT_0601fc94:
    .2byte  0x051E
.L_scroll_ofs_0680:
    .2byte  0x0680
.L_scroll_ofs_06B2:
    .2byte  0x06B2
.L_scroll_ofs_0880:
    .2byte  0x0880

    .global DAT_0601fc9c
DAT_0601fc9c:
    .2byte  0x08D2
.L_scroll_ofs_0480:
    .2byte  0x0480
.L_scroll_ofs_0498:
    .2byte  0x0498
.L_scroll_ofs_0600_b:
    .2byte  0x0600
.L_scroll_ofs_0620:
    .2byte  0x0620
.L_scroll_ofs_0800_b:
    .2byte  0x0800
.L_scroll_ofs_0852:
    .2byte  0x0852
    .2byte  0xFFFF
.L_scroll_data_set_b:
    .4byte  sym_0605E0D0
.L_scroll_data_set_b2:
    .4byte  sym_0605E0D4
.L_scroll_data_set_b3:
    .4byte  sym_0605E0D8
.L_scroll_data_final:
    .4byte  sym_0605E0E4
.L_scroll_data_set_c:
    .4byte  sym_0605E0DC
.L_scroll_data_set_c2:
    .4byte  sym_0605E0E0
.L_multi_mode_dispatch:               ! dispatch multi-scroll by sub-mode
    cmp/eq #0x4, r0
    bf      .L_try_multi_mode8_C
    bra     .L_multi_scroll_mode4     ! multi sub-mode 4
    nop
.L_try_multi_mode8_C:
    cmp/eq #0x8, r0
    bt      .L_multi_scroll_mode8     ! multi sub-mode 8
    cmp/eq #0xC, r0
    bt      .L_multi_scroll_modeC     ! multi sub-mode C
.L_configure_channels:                ! configure VDP2 display channels
    mov.l   .L_fn_channel_nibble_config, r14
    mov.w   .L_channel_config_0x100, r4  ! channel 0x100, val 0
    jsr @r14
    mov #0x0, r5
    mov #0x0, r5                      ! channel 0x4, val 0
    jsr @r14
    mov #0x4, r4
    mov #0x0, r5                      ! channel 0x8, val 0
    jsr @r14
    mov #0x8, r4
    mov #0x0, r5                      ! channel 0x10, val 0
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5                      ! channel 0x20, val 7
    jsr @r14
    mov #0x20, r4
    mov #0x0, r5                      ! channel 0x1, val 0
    jsr @r14
    mov #0x1, r4
    mov r15, r6                       ! r6 = stack ptr (DMA source)
    mov.l   .L_vdp2_vram_0x7FFFE_b, r4
    mov.l   .L_fn_tilemap_dma_update_b, r3
    add #0x4, r6                      ! point to saved 0x7C00 on stack
    jsr @r3                           ! tilemap DMA: write 0x7C00 to VRAM
    mov #0x1, r5                      ! count = 1 word
    mov #0x7, r5                      ! channel 0x20, val 7 (restore)
    jsr @r14
    mov #0x20, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global geom_display_ctrl_a
    .type geom_display_ctrl_a, @function
geom_display_ctrl_a:
    sts.l pr, @-r15
    mov.l   .L_display_ctrl_state_b, r4
    mov.l   .L_fn_display_sync_b, r3
    mov.l @r4, r0
    or #0x4, r0                       ! set bit 2 of display ctrl
    jsr @r3                           ! display_sync
    mov.l r0, @r4
    mov #0x0, r4                      ! clear 5 geometry state vars
    mov.l   .L_geom_counter_a, r3
    mov.l r4, @r3                     ! counter A = 0
    mov.l   .L_geom_counter_b, r3
    mov.l r4, @r3                     ! counter B = 0
    mov.l   .L_geom_counter_c, r3
    mov.l r4, @r3                     ! counter C = 0
    mov.l   .L_geom_counter_d, r3
    mov.l r4, @r3                     ! counter D = 0
    mov.l   .L_geom_counter_e, r3
    lds.l @r15+, pr
    rts
    mov.l r4, @r3                     ! counter E = 0
.L_channel_config_0x100:
    .2byte  0x0100
    .2byte  0xFFFF
.L_fn_channel_nibble_config:
    .4byte  channel_nibble_config
.L_vdp2_vram_0x7FFFE_b:
    .4byte  0x25E7FFFE                  /* VDP2 VRAM +0x7FFFE */
.L_fn_tilemap_dma_update_b:
    .4byte  tilemap_dma_update
.L_display_ctrl_state_b:
    .4byte  sym_0605B6D8
.L_fn_display_sync_b:
    .4byte  sym_06026CE0
.L_geom_counter_a:
    .4byte  sym_060620D0
.L_geom_counter_b:
    .4byte  sym_0605A000
.L_geom_counter_c:
    .4byte  sym_0605A004
.L_geom_counter_d:
    .4byte  sym_0605A008
.L_geom_counter_e:
    .4byte  sym_06059F44
