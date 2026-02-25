/* vdp_mode_setup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600579C - 0x060058FA
 *
 * VDP graphics mode setup dispatcher.
 * Configures multiple rendering layers (palette, texture, sprite, effect,
 * background) by calling the display list loader and command writer with
 * layer-specific parameters. Handles up to 4 rendering phases:
 *
 *   Phase 1: Base palette/metadata load via display_list_loader.
 *            If 2-player mode, copies texture data in 0x80-byte strides
 *            (21 words per entry, 3 words per iteration) from DMA source
 *            to car object table, then submits a sprite layer via
 *            geom_dispatch_final.
 *
 *   Phase 2: Conditional overlay layer. If frame_output (odd/even selector)
 *            bit 0 is set, computes a VDP command offset based on course
 *            index (5 for 2P, 7 for 1P): (index * 0x40 + 0x19) * 2, and
 *            submits via display_list_loader.
 *
 *   Phase 3: Frame-count-gated layer. If max_frame_count < 10, submits a
 *            narrow layer (0x0110 size). Otherwise submits a wider layer
 *            (0x014E size) at offset 0x0C.
 *
 *   Phase 4: Extra layer + scale mode layers. If extra_layer_flag == 0,
 *            submits a 0x30-offset layer using total_car_count as texture
 *            base. If scale_mode_flag == 0, submits a final background
 *            layer with computed offset (index * 0x40 + 0x16) * 2, then
 *            tail-calls display_list_loader via jmp.
 *
 * Callee-saved register contract (set by bg_layer_init, falls through):
 *   r14 = 0x80 (texture entry stride)
 *   r11 = 0x15 (21 = words per texture block, decremented by 3 per iter)
 *   r8-r13 saved/restored by standard prologue/epilogue.
 *
 * Key symbols:
 *   sym_06085FF4 = 2p_mode_flag (byte, 0=1P, nonzero=2P)
 *   sym_06063750 = render_config_table (per-mode struct array, +0x20/+0x28/+0x30 = layer bases)
 *   sym_0606129C = dma_source_data (texture/palette source)
 *   sym_06028400 = display_list_loader (r4=mode, r5=dlist_base, r6=stride, r7=tex_ptr)
 *   sym_0605ACDF = sprite_layer_data (effect layer source address)
 *   sym_060284AE = geom_dispatch_final (r4=mode, r5=src, r6=size, r7=dest)
 *   sym_0607EAB8 = frame_output (odd/even frame selector, dword)
 *   sym_06063F28 = max_frame_count (dword)
 *   sym_06028430 = display_list_cmd_writer (r4=mode, r5=pos, r6=size, r7=texture)
 *   sym_0607EAE0 = extra_layer_flag (dword)
 *   sym_0607EA98 = total_car_count (dword)
 *   sym_06078644 = scale_mode_flag (dword)
 */

    .section .text.FUN_0600579C


    .global vdp_mode_setup
    .type vdp_mode_setup, @function
vdp_mode_setup:
    sts.l pr, @-r15                          ! save return address
    mov r14, r6                              ! r6 = r14 = 0x80 (texture entry stride, from caller)
    add #-0x4, r15                           ! allocate 4 bytes on stack (local var slot)
    mov.l   .L_pool_2p_mode_flag, r8         ! r8 -> &2p_mode_flag (sym_06085FF4)
    mov.l   .L_pool_render_config_table, r9  ! r9 -> render_config_table base (sym_06063750)
    mov.w   .L_wpool_total_copy_stride, r10  ! r10 = 0x0480 (total copy stride = 9 entries * 0x80)
    mov.l   .L_pool_dma_source_data, r13     ! r13 -> dma_source_data (sym_0606129C)
    mov r9, r7                               ! r7 = render_config_table base
    add #0x20, r7                            ! r7 = render_config_table + 0x20 (layer 0 base)
    mov.l r7, @r15                           ! [sp+0] = &layer_0_base (save for later)
    mov.l @(4, r7), r7                       ! r7 = layer_0_base[1] (texture pointer)
    mov.l @r15, r5                           ! r5 = &layer_0_base (reload from stack)
    mov.l   .L_pool_dlist_loader, r3         ! r3 -> display_list_loader (sym_06028400)
    mov.l @r5, r5                            ! r5 = layer_0_base[0] (display list base pointer)
    jsr @r3                                  ! call display_list_loader(r4=8, r5=dlist_base, r6=0x80, r7=tex_ptr)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
    mov.b @r8, r0                            ! r0 = 2p_mode_flag
    tst r0, r0                               ! test if single-player mode
    bt      .L_skip_texture_copy             ! if 1P mode, skip texture copy loop
    mov r14, r12                             ! r12 = 0x80 (destination offset accumulator)
    mov.w   .L_wpool_entry_stride, r7        ! r7 = 0x0180 (first source offset within DMA data)
.L_copy_outer_loop:
    mov.l @r13, r5                           ! r5 = *dma_source_data (base pointer)
    add r7, r5                               ! r5 = dma_base + source_offset (src ptr)
    add #0x18, r5                            ! r5 += 0x18 (skip header, point to texture data)
    mov.l @r13, r6                           ! r6 = *dma_source_data (base pointer)
    add r12, r6                              ! r6 = dma_base + dest_offset
    add #0x18, r6                            ! r6 += 0x18 (skip header in destination)
    mov r11, r4                              ! r4 = word_count (21, decremented by 3 per iter)
.L_copy_inner_loop:
    mov.w @r5+, r1                           ! r1 = *src++ (read word 0)
    add #-0x3, r4                            ! word_count -= 3
    mov.w r1, @r6                            ! *dst = word 0
    add #0x2, r6                             ! dst += 2
    mov.w @r5+, r1                           ! r1 = *src++ (read word 1)
    mov.w r1, @r6                            ! *dst = word 1
    add #0x2, r6                             ! dst += 2
    mov.w @r5+, r1                           ! r1 = *src++ (read word 2)
    mov r6, r3                               ! r3 = dst (save for delayed write)
    add #0x2, r6                             ! dst += 2 (advance past word 2)
    tst r4, r4                               ! check if word_count == 0
    bf/s    .L_copy_inner_loop               ! if not done, loop (copy next 3 words)
    mov.w r1, @r3                            ! (delay slot) *saved_dst = word 2
    add r14, r7                              ! source_offset += 0x80 (next entry)
    cmp/ge r10, r7                           ! source_offset >= 0x0480? (all 9 entries done?)
    bf/s    .L_copy_outer_loop               ! if not, process next entry
    add r14, r12                             ! (delay slot) dest_offset += 0x80 (next entry)
    mov #0x60, r6                            ! r6 = 0x60 (sprite layer size)
    mov.w   .L_wpool_sprite_layer_offset, r5 ! r5 = 0x0318 (sprite layer data offset)
    mov.l   .L_pool_sprite_layer_data, r7    ! r7 -> sprite_layer_data (sym_0605ACDF)
    mov.l   .L_pool_geom_dispatch, r3        ! r3 -> geom_dispatch_final (sym_060284AE)
    jsr @r3                                  ! call geom_dispatch_final(r4=8, r5=0x0318, r6=0x60, r7=sprite_data)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
.L_skip_texture_copy:
    mov.b @r8, r0                            ! r0 = 2p_mode_flag
    tst r0, r0                               ! test if single-player mode
    bt      .L_set_1p_course_index           ! if 1P mode, use index 7
    bra     .L_course_index_ready            ! 2P mode — use index 5
    mov #0x5, r12                            ! (delay slot) r12 = 5 (2P course layer index)
.L_set_1p_course_index:
    mov #0x7, r12                            ! r12 = 7 (1P course layer index)
.L_course_index_ready:
    mov.l   .L_pool_frame_output, r0         ! r0 -> &frame_output (sym_0607EAB8)
    mov.l @r0, r0                            ! r0 = frame_output value (odd/even selector)
    tst #0x1, r0                             ! test bit 0 (frame parity)
    bf      .L_skip_overlay_layer            ! if bit 0 set, skip overlay layer submission
    mov r9, r7                               ! r7 = render_config_table base
    mov r12, r6                              ! r6 = course_index (5 or 7)
    add #0x28, r7                            ! r7 = render_config_table + 0x28 (layer 1 base)
    shll2 r6                                 ! r6 = course_index * 4
    mov.l r7, @r15                           ! [sp+0] = &layer_1_base
    shll2 r6                                 ! r6 = course_index * 16
    mov.l @(4, r7), r7                       ! r7 = layer_1_base[1] (texture pointer)
    mov.l @r15, r5                           ! r5 = &layer_1_base
    mov.l   .L_pool_dlist_loader, r3         ! r3 -> display_list_loader (sym_06028400)
    shll2 r6                                 ! r6 = course_index * 64 (= * 0x40)
    mov.l @r5, r5                            ! r5 = layer_1_base[0] (display list base)
    add #0x19, r6                            ! r6 = course_index * 0x40 + 0x19
    shll r6                                  ! r6 = (course_index * 0x40 + 0x19) * 2 (byte offset)
    jsr @r3                                  ! call display_list_loader(r4=8, r5=dlist, r6=offset, r7=tex)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
.L_skip_overlay_layer:
    mov.l   .L_pool_max_frame_count, r12     ! r12 -> &max_frame_count (sym_06063F28)
    mov #0xA, r3                             ! r3 = 10 (threshold)
    mov.l @r12, r2                           ! r2 = max_frame_count value
    cmp/hs r3, r2                            ! max_frame_count >= 10? (unsigned)
    bt      .L_wide_frame_layer              ! if >= 10, use wider layer
    mov.l @r12, r7                           ! r7 = max_frame_count (texture/layer param)
    mov #0x0, r6                             ! r6 = 0 (narrow layer offset)
    mov.w   .L_wpool_narrow_layer_size, r5   ! r5 = 0x0110 (narrow layer size)
    mov.l   .L_pool_dlist_cmd_writer, r3     ! r3 -> display_list_cmd_writer (sym_06028430)
    jsr @r3                                  ! call dlist_cmd_writer(r4=8, r5=0x0110, r6=0, r7=frame_count)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
    bra     .L_check_extra_layer             ! continue to extra layer check
    nop                                      ! (delay slot)
.L_wpool_total_copy_stride:
    .2byte  0x0480                           ! 0x0480 = 9 * 0x80 (total texture copy stride)
.L_wpool_entry_stride:
    .2byte  0x0180                           ! 0x0180 = initial source offset in DMA data
.L_wpool_sprite_layer_offset:
    .2byte  0x0318                           ! 0x0318 = sprite layer data offset
.L_wpool_narrow_layer_size:
    .2byte  0x0110                           ! 0x0110 = narrow frame layer size
    .2byte  0xFFFF                           ! padding (alignment)
.L_pool_2p_mode_flag:
    .4byte  sym_06085FF4                     ! -> 2p_mode_flag (byte, 0=1P, nonzero=2P)
.L_pool_render_config_table:
    .4byte  sym_06063750                     ! -> render_config_table (per-mode struct array)
.L_pool_dma_source_data:
    .4byte  sym_0606129C                     ! -> DMA source data (texture/palette source)
.L_pool_dlist_loader:
    .4byte  sym_06028400                     ! -> display_list_loader function
.L_pool_sprite_layer_data:
    .4byte  sym_0605ACDF                     ! -> sprite layer source data
.L_pool_geom_dispatch:
    .4byte  sym_060284AE                     ! -> geom_dispatch_final function
.L_pool_frame_output:
    .4byte  sym_0607EAB8                     ! -> frame_output (odd/even frame selector, dword)
.L_pool_max_frame_count:
    .4byte  sym_06063F28                     ! -> max_frame_count (dword)
.L_pool_dlist_cmd_writer:
    .4byte  sym_06028430                     ! -> display_list_cmd_writer function
.L_wide_frame_layer:
    mov.l @r12, r7                           ! r7 = max_frame_count (texture/layer param)
    mov #0xC, r6                             ! r6 = 0xC (wide layer offset)
    .byte   0x95, 0x44    /* mov.w .L_wpool_0600590C, r5 */  ! r5 = 0x0110 (wide layer size from shared pool in frame_dispatch)
    .byte   0xD3, 0x24    /* mov.l .L_pool_06005914, r3 */   ! r3 -> display_list_cmd_writer (sym_06028430, shared pool)
    jsr @r3                                  ! call dlist_cmd_writer(r4=8, r5=0x0110, r6=0xC, r7=frame_count)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
.L_check_extra_layer:
    .byte   0xD0, 0x23    /* mov.l .L_pool_06005918, r0 */   ! r0 -> &extra_layer_flag (sym_0607EAE0, shared pool)
    mov.l @r0, r0                            ! r0 = extra_layer_flag value
    tst r0, r0                               ! test if extra layer disabled
    bf      .L_skip_extra_layer              ! if nonzero, skip extra layer
    mov #0x30, r6                            ! r6 = 0x30 (extra layer size)
    .byte   0x95, 0x3C    /* mov.w .L_wpool_0600590E, r5 */  ! r5 = 0x014E (extra layer offset, from shared pool DAT_0600590e)
    .byte   0xD7, 0x21    /* mov.l .L_pool_0600591C, r7 */   ! r7 -> &total_car_count (sym_0607EA98, shared pool)
    .byte   0xD3, 0x1F    /* mov.l .L_pool_06005914, r3 */   ! r3 -> display_list_cmd_writer (sym_06028430, shared pool)
    mov.l @r7, r7                            ! r7 = total_car_count value
    jsr @r3                                  ! call dlist_cmd_writer(r4=8, r5=0x014E, r6=0x30, r7=car_count)
    mov #0x8, r4                             ! (delay slot) r4 = 0x8 (command mode)
.L_skip_extra_layer:
    .byte   0xD0, 0x20    /* mov.l .L_pool_06005920, r0 */   ! r0 -> &scale_mode_flag (sym_06078644, shared pool)
    mov.l @r0, r0                            ! r0 = scale_mode_flag value
    tst r0, r0                               ! test if scale mode disabled
    bf      .L_epilogue_rts                  ! if nonzero (scale mode on), skip final layer and return
    mov.b @r8, r0                            ! r0 = 2p_mode_flag
    tst r0, r0                               ! test if single-player
    bt      .L_set_1p_bg_index               ! if 1P, use index 6
    bra     .L_bg_index_ready                ! 2P mode — use index 4
    mov #0x4, r12                            ! (delay slot) r12 = 4 (2P background layer index)
.L_set_1p_bg_index:
    mov #0x6, r12                            ! r12 = 6 (1P background layer index)
.L_bg_index_ready:
    mov r9, r7                               ! r7 = render_config_table base
    mov r12, r6                              ! r6 = bg_layer_index (4 or 6)
    add #0x30, r7                            ! r7 = render_config_table + 0x30 (layer 2 base)
    shll2 r6                                 ! r6 = bg_index * 4
    mov.l r7, @r15                           ! [sp+0] = &layer_2_base
    shll2 r6                                 ! r6 = bg_index * 16
    mov.l @(4, r7), r7                       ! r7 = layer_2_base[1] (texture pointer)
    .byte   0x93, 0x26    /* mov.w .L_wpool_06005910, r3 */  ! r3 = 0x1000 (VRAM offset, from shared pool DAT_06005910)
    shll2 r6                                 ! r6 = bg_index * 64 (= * 0x40)
    add r3, r7                               ! r7 = texture_ptr + 0x1000 (VRAM destination)
    add #0x16, r6                            ! r6 = bg_index * 0x40 + 0x16
    shll r6                                  ! r6 = (bg_index * 0x40 + 0x16) * 2 (byte offset)
    mov.l @r15, r5                           ! r5 = &layer_2_base
    mov.l @r5, r5                            ! r5 = layer_2_base[0] (display list base)
    mov #0x8, r4                             ! r4 = 0x8 (command mode)
    add #0x4, r15                            ! deallocate local var slot
    lds.l @r15+, pr                          ! restore return address (but won't use — tail call)
    mov.l @r15+, r8                          ! restore r8
    mov.l @r15+, r9                          ! restore r9
    mov.l @r15+, r10                         ! restore r10
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    .byte   0xD3, 0x10    /* mov.l .L_pool_06005924, r3 */   ! r3 -> display_list_loader (sym_06028400, shared pool)
    jmp @r3                                  ! tail-call display_list_loader(r4=8, r5=dlist, r6=offset, r7=tex+0x1000)
    mov.l @r15+, r14                         ! (delay slot) restore r14
.L_epilogue_rts:
    add #0x4, r15                            ! deallocate local var slot
    lds.l @r15+, pr                          ! restore return address
    mov.l @r15+, r8                          ! restore r8
    mov.l @r15+, r9                          ! restore r9
    mov.l @r15+, r10                         ! restore r10
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return to caller
    mov.l @r15+, r14                         ! (delay slot) restore r14
