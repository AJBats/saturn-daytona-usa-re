/* render_stage_b -- VDP1 sprite index table setup + extended channel rendering
 * Translation unit: 0x06023584 - 0x0602382C (680 bytes, 1 function)
 *
 * Extended variant of projection_mgr that handles 0x21 render channels
 * (r14 = 0x00..0x20) instead of projection_mgr's 0x15. Each channel
 * descriptor is 12 bytes: {primary_data_ptr, secondary_data_ptr,
 * primary_count(w), secondary_count(w)}.
 *
 * Copies the channel descriptor table (sym_06060A48, 0x18C bytes) onto
 * the stack as a local working copy, then initializes the VDP1 sprite
 * index table (sym_06089E44) with sequential word indices 0x03..0x37.
 * Copies VDP1 display data from the scroll base table into VDP1 VRAM
 * (0x002A8000).
 *
 * Per-channel processing:
 *   - Primary entries: 12-byte stride, rendered via vdp1_sprite_render_alt
 *   - Secondary entries: 6-byte stride, rendered via sym_06007590
 *
 * Channel 0x1D is special: at primary sub-indices 0x17, 0x3A, and 0xD0
 * it stores projection parameters from *r10 into globals:
 *   0x17 -> sym_06089E30 (proj_param_a)
 *   0x3A -> sym_06089E2C (proj_param_b)
 *   0xD0 -> sym_06089E28 (proj_config)
 *
 * Channels >= r9 (threshold, typically 0x1D) get a per-channel sprite
 * index offset from the lookup table sym_06060A40 instead of the
 * default +0xA bump. Channel 0x1F adds an extra +0x2A. Channel 0x20
 * stores the final sprite word index to sym_0607886C (sprite bank base).
 *
 * Register usage:
 *   r8  = 0 (sub-index counter reset value)
 *   r9  = channel threshold (caller-provided, typically 0x1D)
 *   r10 = projection parameter source pointer (sym_0606A4EC)
 *   r12 = running VDP1 sprite word index (accumulator)
 *   r14 = channel loop counter (0x00..0x20)
 *   r13 = primary/secondary sub-index counter
 *   r11 = current entry data pointer
 */

    .section .text.FUN_06023584


    .global render_stage_b
    .type render_stage_b, @function
render_stage_b:
    sts.l pr, @-r15                              ! save return address
    mov #0x0, r8                                 ! r8 = 0 (sub-index reset constant)
    mov.w   .L_frame_alloc_neg, r0               ! r0 = -0x194
    add r0, r15                                  ! allocate 0x194 bytes on stack
    mov.l   .L_proj_param_source, r10            ! r10 = &proj_param_source (sym_0606A4EC)
    mov r15, r1                                  ! r1 = stack base (dst for memcpy)
    mov.l   .L_channel_table_src, r2             ! r2 = channel table ROM source (sym_06060A48)
    mov.w   .L_memcpy_byte_count, r0             ! r0 = 0x018C (396 bytes to copy)
    mov.l   .L_fn_memcpy_long, r3                ! r3 = &memcpy_long
    jsr @r3                                      ! memcpy_long(r0=0x18C, r1=stack+8, r2=src)
    add #0x8, r1                                 ! r1 = stack+8 (delay slot, skip locals area)
    mov.l   .L_sprite_index_table, r4            ! r4 = sprite index table (sym_06089E44)
    ! --- Initialize sprite index table: table[2..15] = 0x03..0x10 ---
    mov #0x3, r0
    mov.w r0, @(4, r4)                          ! table[2] = 0x03
    mov #0x4, r0
    mov.w r0, @(6, r4)                          ! table[3] = 0x04
    mov #0x5, r0
    mov.w r0, @(8, r4)
    mov #0x6, r0
    mov.w r0, @(10, r4)
    mov #0x7, r0
    mov.w r0, @(12, r4)
    mov #0x8, r0
    mov.w r0, @(14, r4)
    mov #0x9, r0
    mov.w r0, @(16, r4)
    mov #0xA, r0
    mov.w r0, @(18, r4)
    mov #0xB, r0
    mov.w r0, @(20, r4)
    mov #0xC, r0
    mov.w r0, @(22, r4)
    mov #0xD, r0
    mov.w r0, @(24, r4)
    mov #0xE, r0
    mov.w r0, @(26, r4)
    mov #0xF, r0
    mov.w r0, @(28, r4)
    mov #0x10, r0
    mov.w r0, @(30, r4)                         ! table[15] = 0x10
    ! --- table[16..28]: indirect via r3 (offset > 30 requires add) ---
    mov r4, r3
    add #0x20, r3                                ! r3 = &table[16]
    mov #0x11, r2
    mov.w r2, @r3                                ! table[16] = 0x11
    mov r4, r3
    add #0x22, r3
    mov #0x12, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x24, r3
    mov #0x13, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x26, r3
    mov #0x14, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x28, r3
    mov #0x15, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2A, r3
    mov #0x16, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2C, r3
    mov #0x17, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2E, r3
    mov #0x18, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x30, r3
    mov #0x19, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x32, r3
    mov #0x1A, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x34, r3
    mov #0x1B, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x36, r3
    mov #0x1C, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x38, r3                                ! r3 = &table[28]
    mov.w r9, @r3                                ! table[28] = r9 (caller threshold, typically 0x1D)
    mov #0x1E, r5                                ! r5 = 0x1E (initial sprite word index)
    mov r4, r3
    add #0x3A, r3
    extu.w r5, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x3C, r3
    mov #0x1F, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x3E, r3
    mov #0x20, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x40, r3
    mov #0x21, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x42, r3
    mov #0x22, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x44, r3
    mov #0x23, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x46, r3
    mov #0x24, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x48, r3
    mov #0x25, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4A, r3
    mov #0x26, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4C, r3
    mov #0x27, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4E, r3
    mov #0x28, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x50, r3
    mov #0x29, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x52, r3
    mov #0x2A, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x54, r3
    bra     .L_finish_index_table                ! -> finish last two entries after pool
    nop
.L_frame_alloc_neg:
    .2byte  0xFE6C                               ! -0x194 (stack frame size)
.L_memcpy_byte_count:
    .2byte  0x018C                               ! 396 bytes (channel table copy size)
.L_proj_param_source:
    .4byte  sym_0606A4EC                         ! projection parameter source pointer
.L_channel_table_src:
    .4byte  sym_06060A48                         ! channel descriptor table (ROM source)
.L_fn_memcpy_long:
    .4byte  sym_06035168                         ! memcpy_long (jump-table unrolled)
.L_sprite_index_table:
    .4byte  sym_06089E44                         ! VDP1 sprite word index table (halfword array)
.L_finish_index_table:
    ! --- table[42..43] = 0x36..0x37 (gap: 0x2B-0x35 skipped) ---
    mov #0x36, r2
    add #0x56, r4                                ! r4 = &table[43]
    extu.w r5, r12                               ! r12 = 0x1E (initial sprite word index)
    mov.w r2, @r3                                ! table[42] = 0x36
    mov #0x37, r3
    mov.w r3, @r4                                ! table[43] = 0x37
    ! --- Copy VDP1 display data from scroll base table ---
    mov.l   .L_vdp1_vram_base, r2               ! r2 = 0x002A8000 (VDP1 VRAM dest)
    mov.l r2, @(4, r15)                          ! save VRAM base to stack[4] for later use
    mov r2, r5                                   ! r5 = VDP1 VRAM dest (arg for memcpy)
    mov.w   .L_vdp1_copy_count, r6              ! r6 = 0x5780 (word count for copy)
    mov.l   .L_game_state_idx_ptr, r4           ! r4 = &game_state_index (sym_06059FFC)
    mov.l   .L_scroll_base_table, r3            ! r3 = &scroll_base_table (sym_06063F5C)
    mov.w   .L_scroll_data_offset, r2           ! r2 = 0x03C0 (offset into scroll data)
    mov.l @r4, r4                                ! r4 = game_state_index
    mov.l @r3, r3                                ! r3 = scroll_base_table
    shll2 r4                                     ! r4 *= 4
    shll r4                                      ! r4 *= 2 (total *8 for 8-byte entries)
    add r3, r4                                   ! r4 = scroll_base + state_index * 8
    add r2, r4                                   ! r4 += 0x03C0 (src address for copy)
    mov.l   .L_fn_memcpy_word_idx, r2           ! r2 = &memcpy_word_idx
    jsr @r2                                      ! memcpy_word_idx(dst=r5, src=r4, count=r6)
    nop
    ! --- Enter channel loop ---
    bra     .L_channel_loop_test                 ! -> channel loop test (check r14 < 0x21)
    extu.w r8, r14                               ! r14 = 0 (channel counter, delay slot)
.L_channel_loop_body:
    ! --- Compute channel descriptor address: stack+8 + r14*12 ---
    mov r14, r4                                  ! r4 = channel index
    mov r14, r3                                  ! r3 = channel index
    mov r15, r2                                  ! r2 = stack base
    shll2 r4                                     ! r4 = index * 4
    shll2 r3                                     ! r3 = index * 4
    add #0x8, r2                                 ! r2 = stack + 8 (channel table base)
    shll r3                                      ! r3 = index * 8
    add r3, r4                                   ! r4 = index * 12
    exts.w r4, r4                                ! sign-extend offset
    add r2, r4                                   ! r4 = &channel_desc[index] on stack
    mov.l @r4, r11                               ! r11 = channel[+0] primary data pointer
    mov.w @(8, r4), r0                           ! r0 = channel[+8] primary entry count
    mov r0, r3
    mov.w r3, @r15                               ! save primary count to stack[0]
    mov.w @r15, r3                               ! reload primary count (memory barrier)
    extu.w r3, r3                                ! zero-extend
    cmp/pl r3                                    ! primary count > 0?
    bf/s    .L_primary_done                      ! if no primary entries -> skip to secondary
    extu.w r8, r13                               ! r13 = 0 (primary sub-index, delay slot)
.L_primary_entry_loop:
    tst r11, r11                                 ! primary data pointer == NULL?
    bf      .L_primary_data_valid                ! if non-NULL -> process entry
    bra     .L_primary_done                      ! NULL pointer -> done with primaries
    nop
.L_primary_data_valid:
    ! --- Channel 0x1D special: store projection params at specific sub-indices ---
    extu.w r14, r0                               ! r0 = channel index
    cmp/eq #0x1D, r0                             ! channel == 0x1D?
    bf      .L_render_primary_entry              ! if not -> render directly
    extu.w r13, r0                               ! r0 = primary sub-index
    cmp/eq #0x17, r0                             ! sub-index == 0x17?
    bf      .L_check_idx_3a                      ! if not -> check 0x3A
    mov.l @r10, r2                               ! r2 = *proj_param_source
    mov.l   .L_proj_param_a, r3                 ! r3 = &proj_param_a (sym_06089E30)
    mov.l r2, @r3                                ! proj_param_a = *proj_param_source
    bra     .L_render_primary_entry              ! -> render this entry
    nop
.L_check_idx_3a:
    extu.w r13, r0                               ! r0 = primary sub-index
    cmp/eq #0x3A, r0                             ! sub-index == 0x3A?
    bf      .L_check_idx_d0                      ! if not -> check 0xD0
    mov.l @r10, r2                               ! r2 = *proj_param_source
    mov.l   .L_proj_param_b, r3                 ! r3 = &proj_param_b (sym_06089E2C)
    mov.l r2, @r3                                ! proj_param_b = *proj_param_source
    bra     .L_render_primary_entry              ! -> render this entry
    nop
.L_vdp1_copy_count:
    .2byte  0x5780                               ! VDP1 display data word count
.L_scroll_data_offset:
    .2byte  0x03C0                               ! offset into scroll base per game state
.L_vdp1_vram_base:
    .4byte  0x002A8000                           ! VDP1 VRAM destination address
.L_game_state_idx_ptr:
    .4byte  sym_06059FFC                         ! game state index pointer
.L_scroll_base_table:
    .4byte  sym_06063F5C                         ! display/scroll base table pointer
.L_fn_memcpy_word_idx:
    .4byte  memcpy_word_idx                      ! word copy function (index-based)
.L_proj_param_a:
    .4byte  sym_06089E30                         ! projection param A (ch 0x1D sub 0x17)
.L_proj_param_b:
    .4byte  sym_06089E2C                         ! projection param B (ch 0x1D sub 0x3A)
.L_check_idx_d0:
    extu.w r13, r2                               ! r2 = primary sub-index
    mov.w   .L_proj_idx_d0, r3                  ! r3 = 0x00D0
    cmp/eq r3, r2                                ! sub-index == 0xD0?
    bf      .L_render_primary_entry              ! if not -> render without storing param
    mov.l @r10, r3                               ! r3 = *proj_param_source
    mov.l   .L_proj_config_ptr, r2              ! r2 = &proj_config (sym_06089E28)
    mov.l r3, @r2                                ! proj_config = *proj_param_source
.L_render_primary_entry:
    extu.w r12, r5                               ! r5 = sprite word index (render arg)
    mov.l   .L_fn_sprite_render, r3             ! r3 = &vdp1_sprite_render_alt
    mov.l @(4, r15), r6                          ! r6 = VDP1 VRAM base (from stack[4])
    jsr @r3                                      ! vdp1_sprite_render_alt(r4=data, r5=idx, r6=vram)
    mov r11, r4                                  ! r4 = primary data pointer (delay slot)
    add #0x1, r13                                ! r13++ (next sub-index)
    mov.w @r15, r3                               ! r3 = primary entry count (from stack[0])
    extu.w r13, r2                               ! r2 = current sub-index
    extu.w r3, r3                                ! zero-extend count
    cmp/ge r3, r2                                ! sub-index >= count?
    bf/s    .L_primary_entry_loop                ! if more entries -> loop
    add #0xC, r11                                ! r11 += 0xC (next 12-byte entry, delay slot)
.L_primary_done:
    ! --- Load secondary data from channel descriptor ---
    mov r14, r4                                  ! r4 = channel index
    mov r14, r3                                  ! r3 = channel index
    mov r15, r2                                  ! r2 = stack base
    shll2 r4                                     ! r4 = index * 4
    shll2 r3                                     ! r3 = index * 4
    add #0x8, r2                                 ! r2 = stack + 8 (channel table base)
    shll r3                                      ! r3 = index * 8
    add r3, r4                                   ! r4 = index * 12
    exts.w r4, r4                                ! sign-extend offset
    add r2, r4                                   ! r4 = &channel_desc[index] on stack
    mov.l @(4, r4), r11                          ! r11 = channel[+4] secondary data pointer
    mov.w @(10, r4), r0                          ! r0 = channel[+10] secondary entry count
    mov r0, r3
    mov.w r3, @r15                               ! save secondary count to stack[0]
    ! --- Channels >= r9: apply per-channel sprite index offset from table ---
    extu.w r14, r3                               ! r3 = channel index
    cmp/ge r9, r3                                ! channel >= threshold?
    bf      .L_no_channel_offset                 ! if below threshold -> skip offset
    extu.w r14, r3                               ! r3 = channel index
    add #-0x1D, r3                               ! r3 = channel - 0x1D (table index)
    shll r3                                      ! r3 *= 2 (halfword stride)
    mov.l   .L_channel_offset_table, r2         ! r2 = offset table base (sym_06060A40)
    add r2, r3                                   ! r3 = &offset_table[channel - 0x1D]
    mov.w @r3, r3                                ! r3 = sprite index offset for this channel
    add r3, r12                                  ! r12 += offset (adjust sprite word index)
.L_no_channel_offset:
    mov.w @r15, r2                               ! r2 = secondary entry count
    extu.w r2, r2                                ! zero-extend
    cmp/pl r2                                    ! secondary count > 0?
    bf/s    .L_secondary_done                    ! if no secondary entries -> skip
    extu.w r8, r13                               ! r13 = 0 (secondary sub-index, delay slot)
.L_secondary_entry_loop:
    extu.w r12, r5                               ! r5 = sprite word index (render arg)
    mov.l   .L_fn_secondary_render, r3          ! r3 = &secondary render fn (sym_06007590)
    jsr @r3                                      ! secondary_render(r4=data, r5=idx)
    mov r11, r4                                  ! r4 = secondary data pointer (delay slot)
    add #0x1, r13                                ! r13++ (next sub-index)
    mov.w @r15, r3                               ! r3 = secondary entry count
    extu.w r13, r2                               ! r2 = current sub-index
    extu.w r3, r3                                ! zero-extend count
    cmp/ge r3, r2                                ! sub-index >= count?
    bf/s    .L_secondary_entry_loop              ! if more entries -> loop
    add #0x6, r11                                ! r11 += 0x6 (next 6-byte entry, delay slot)
.L_secondary_done:
    ! --- Channel 0x20: store final sprite word index to bank base ---
    extu.w r14, r0                               ! r0 = channel index
    cmp/eq #0x20, r0                             ! channel == 0x20 (last)?
    bf      .L_skip_bank_store                   ! if not -> skip
    mov.l   .L_sprite_bank_base, r3             ! r3 = &sprite_bank_base (sym_0607886C)
    mov.w r12, @r3                               ! sprite_bank_base = r12 (final word index)
.L_skip_bank_store:
    ! --- Channel 0x1F: extra +0x2A sprite index bump ---
    extu.w r14, r0                               ! r0 = channel index
    cmp/eq #0x1F, r0                             ! channel == 0x1F?
    bf      .L_skip_extra_offset                 ! if not -> skip
    add #0x2A, r12                               ! r12 += 0x2A (extra offset for channel 0x1F)
.L_skip_extra_offset:
    ! --- Channels below threshold: default +0xA per-channel bump ---
    extu.w r14, r2                               ! r2 = channel index
    cmp/ge r9, r2                                ! channel >= threshold?
    bt      .L_no_per_channel_bump               ! if >= threshold -> skip default bump
    add #0xA, r12                                ! r12 += 0xA (default per-channel sprite bump)
.L_no_per_channel_bump:
    add #0x1, r14                                ! r14++ (next channel)
.L_channel_loop_test:
    extu.w r14, r2                               ! r2 = channel index
    mov #0x21, r3                                ! r3 = 0x21 (total channels)
    cmp/ge r3, r2                                ! channel >= 0x21?
    bt      .L_epilogue                          ! if all channels done -> exit
    bra     .L_channel_loop_body                 ! -> process next channel
    nop
.L_epilogue:
    mov.w   .L_frame_dealloc, r1                ! r1 = 0x194 (frame deallocation)
    add r1, r15                                  ! deallocate stack frame
    lds.l @r15+, pr                              ! restore return address
    mov.l @r15+, r8                              ! restore r8
    mov.l @r15+, r9                              ! restore r9
    mov.l @r15+, r10                             ! restore r10
    mov.l @r15+, r11                             ! restore r11
    mov.l @r15+, r12                             ! restore r12
    mov.l @r15+, r13                             ! restore r13
    rts                                          ! return
    mov.l @r15+, r14                             ! restore r14 (delay slot)
.L_proj_idx_d0:
    .2byte  0x00D0                               ! projection param index 0xD0
.L_frame_dealloc:
    .2byte  0x0194                               ! frame deallocation size (matches alloc)
.L_proj_config_ptr:
    .4byte  sym_06089E28                         ! projection config (ch 0x1D sub 0xD0)
.L_fn_sprite_render:
    .4byte  vdp1_sprite_render_alt               ! primary sprite render function
.L_channel_offset_table:
    .4byte  sym_06060A40                         ! per-channel sprite index offset table (halfwords)
.L_fn_secondary_render:
    .4byte  sym_06007590                         ! secondary entry render function
.L_sprite_bank_base:
    .4byte  sym_0607886C                         ! sprite bank base halfword (written at ch 0x20)
