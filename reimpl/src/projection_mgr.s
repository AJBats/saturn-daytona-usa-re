/* projection_mgr -- VDP1 sprite index table setup + per-channel rendering
 * Translation unit: 0x06023290 - 0x06023574 (740 bytes, 1 function)
 *
 * Initialises the VDP1 sprite index table (sym_06089E44) with sequential
 * word indices 0x03..0x37, then copies a block of VDP1 display data from
 * the display/scroll base table (sym_06063F5C) into VDP1 VRAM (0x002A8000).
 *
 * Iterates 0x15 render channels (r12 = 0x00..0x14). Each channel has:
 *   - A primary entry count at channel_base+8 (rendered via vdp1_sprite_render_alt)
 *   - A secondary pointer at channel_base+4 -> secondary entries at ptr+10
 *     (rendered via sym_06007590)
 *
 * Channel 0x13 is special: its primary sub-entries store projection
 * parameters into globals sym_06089E28..sym_06089E40 at specific indices
 * (0x15, 0x27, 0x40, 0x44, 0x82, 0x88, 0xA9).
 *
 * After channel 0x14, stores r11 (running sprite word index) to
 * sym_0607886C (sprite bank base halfword).
 *
 * Register usage:
 *   r9  = channel table base (sym_06056940, 12-byte stride per channel)
 *   r11 = running VDP1 sprite word index
 *   r12 = channel loop counter (0x00..0x14)
 *   r13 = projection param source pointer (sym_0606A4EC)
 *   r6  = VDP1 VRAM dest base (0x002A8000)
 */

    .section .text.FUN_06023290


    .global projection_mgr
    .type projection_mgr, @function
projection_mgr:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save pr (return address)
    mov.l   .L_channel_table_base, r9       ! r9 = channel table base (sym_06056940)
    mov.l   .L_proj_param_source, r13       ! r13 = projection param source (sym_0606A4EC)
    mov.l   .L_sprite_index_table, r4       ! r4 = sprite index table (sym_06089E44)
    mov #0x3, r0                            ! r0 = 0x03 (first index value)
    mov.w r0, @(4, r4)                      ! table[2] = 0x03
    mov #0x4, r0                            ! r0 = 0x04
    mov.w r0, @(6, r4)                      ! table[3] = 0x04
    mov #0x5, r0                            ! r0 = 0x05
    mov.w r0, @(8, r4)                      ! table[4] = 0x05
    mov #0x6, r0                            ! r0 = 0x06
    mov.w r0, @(10, r4)                     ! table[5] = 0x06
    mov #0x7, r0                            ! r0 = 0x07
    mov.w r0, @(12, r4)                     ! table[6] = 0x07
    mov #0x8, r0                            ! r0 = 0x08
    mov.w r0, @(14, r4)                     ! table[7] = 0x08
    mov #0x9, r0                            ! r0 = 0x09
    mov.w r0, @(16, r4)                     ! table[8] = 0x09
    mov #0xA, r0                            ! r0 = 0x0A
    mov.w r0, @(18, r4)                     ! table[9] = 0x0A
    mov #0xB, r0                            ! r0 = 0x0B
    mov.w r0, @(20, r4)                     ! table[10] = 0x0B
    mov #0xC, r0                            ! r0 = 0x0C
    mov.w r0, @(22, r4)                     ! table[11] = 0x0C
    mov #0xD, r0                            ! r0 = 0x0D
    mov.w r0, @(24, r4)                     ! table[12] = 0x0D
    mov #0xE, r0                            ! r0 = 0x0E
    mov.w r0, @(26, r4)                     ! table[13] = 0x0E
    mov #0xF, r0                            ! r0 = 0x0F
    mov.w r0, @(28, r4)                     ! table[14] = 0x0F
    mov #0x10, r0                           ! r0 = 0x10
    mov.w r0, @(30, r4)                     ! table[15] = 0x10
    mov r4, r3                              ! r3 = table base
    add #0x20, r3                            ! r3 = &table[16]
    mov #0x11, r2                            ! r2 = 0x11
    mov.w r2, @r3                            ! table[16] = 0x11
    mov r4, r3                              ! r3 = table base
    add #0x22, r3                            ! r3 = &table[17]
    mov #0x12, r2                            ! r2 = 0x12
    mov.w r2, @r3                            ! table[17] = 0x12
    mov r4, r3                              ! r3 = table base
    add #0x24, r3                            ! r3 = &table[18]
    mov #0x13, r2                            ! r2 = 0x13
    mov.w r2, @r3                            ! table[18] = 0x13
    mov r4, r3                              ! r3 = table base
    add #0x26, r3                            ! r3 = &table[19]
    mov #0x14, r2                            ! r2 = 0x14
    mov.w r2, @r3                            ! table[19] = 0x14
    mov r4, r3                              ! r3 = table base
    add #0x28, r3                            ! r3 = &table[20]
    mov #0x15, r2                            ! r2 = 0x15
    mov.w r2, @r3                            ! table[20] = 0x15
    mov r4, r3                              ! r3 = table base
    add #0x2A, r3                            ! r3 = &table[21]
    mov #0x16, r2                            ! r2 = 0x16
    mov.w r2, @r3                            ! table[21] = 0x16
    mov r4, r3                              ! r3 = table base
    add #0x2C, r3                            ! r3 = &table[22]
    mov #0x17, r2                            ! r2 = 0x17
    mov.w r2, @r3                            ! table[22] = 0x17
    mov r4, r3                              ! r3 = table base
    add #0x2E, r3                            ! r3 = &table[23]
    mov #0x18, r2                            ! r2 = 0x18
    mov.w r2, @r3                            ! table[23] = 0x18
    mov r4, r3                              ! r3 = table base
    add #0x30, r3                            ! r3 = &table[24]
    mov #0x19, r2                            ! r2 = 0x19
    mov.w r2, @r3                            ! table[24] = 0x19
    mov r4, r3                              ! r3 = table base
    add #0x32, r3                            ! r3 = &table[25]
    mov #0x1A, r2                            ! r2 = 0x1A
    mov.w r2, @r3                            ! table[25] = 0x1A
    mov r4, r3                              ! r3 = table base
    add #0x34, r3                            ! r3 = &table[26]
    mov #0x1B, r2                            ! r2 = 0x1B
    mov.w r2, @r3                            ! table[26] = 0x1B
    mov r4, r3                              ! r3 = table base
    add #0x36, r3                            ! r3 = &table[27]
    mov #0x1C, r2                            ! r2 = 0x1C
    mov.w r2, @r3                            ! table[27] = 0x1C
    mov r4, r3                              ! r3 = table base
    add #0x38, r3                            ! r3 = &table[28]
    mov #0x1D, r2                            ! r2 = 0x1D
    mov.w r2, @r3                            ! table[28] = 0x1D
    mov #0x1E, r5                           ! r5 = 0x1E (saved for r11 init later)
    mov r4, r3                              ! r3 = table base
    add #0x3A, r3                            ! r3 = &table[29]
    extu.w r5, r2                            ! r2 = 0x001E (zero-extend)
    mov.w r2, @r3                            ! table[29] = 0x1E
    mov r4, r3                              ! r3 = table base
    add #0x3C, r3                            ! r3 = &table[30]
    mov #0x1F, r2                            ! r2 = 0x1F
    mov.w r2, @r3                            ! table[30] = 0x1F
    mov r4, r3                              ! r3 = table base
    add #0x3E, r3                            ! r3 = &table[31]
    mov #0x20, r2                            ! r2 = 0x20
    mov.w r2, @r3                            ! table[31] = 0x20
    mov r4, r3                              ! r3 = table base
    add #0x40, r3                            ! r3 = &table[32]
    mov #0x21, r2                            ! r2 = 0x21
    mov.w r2, @r3                            ! table[32] = 0x21
    mov r4, r3                              ! r3 = table base
    add #0x42, r3                            ! r3 = &table[33]
    mov #0x22, r2                            ! r2 = 0x22
    mov.w r2, @r3                            ! table[33] = 0x22
    mov r4, r3                              ! r3 = table base
    add #0x44, r3                            ! r3 = &table[34]
    mov #0x23, r2                            ! r2 = 0x23
    mov.w r2, @r3                            ! table[34] = 0x23
    mov r4, r3                              ! r3 = table base
    add #0x46, r3                            ! r3 = &table[35]
    mov #0x24, r2                            ! r2 = 0x24
    mov.w r2, @r3                            ! table[35] = 0x24
    mov r4, r3                              ! r3 = table base
    add #0x48, r3                            ! r3 = &table[36]
    mov #0x25, r2                            ! r2 = 0x25
    mov.w r2, @r3                            ! table[36] = 0x25
    mov r4, r3                              ! r3 = table base
    add #0x4A, r3                            ! r3 = &table[37]
    mov #0x26, r2                            ! r2 = 0x26
    mov.w r2, @r3                            ! table[37] = 0x26
    mov r4, r3                              ! r3 = table base
    add #0x4C, r3                            ! r3 = &table[38]
    mov #0x27, r2                            ! r2 = 0x27
    mov.w r2, @r3                            ! table[38] = 0x27
    mov r4, r3                              ! r3 = table base
    add #0x4E, r3                            ! r3 = &table[39]
    mov #0x28, r2                            ! r2 = 0x28
    mov.w r2, @r3                            ! table[39] = 0x28
    mov r4, r3                              ! r3 = table base
    add #0x50, r3                            ! r3 = &table[40]
    mov #0x29, r2                            ! r2 = 0x29
    mov.w r2, @r3                            ! table[40] = 0x29
    mov r4, r3                              ! r3 = table base
    add #0x52, r3                            ! r3 = &table[41]
    mov #0x2A, r2                            ! r2 = 0x2A
    mov.w r2, @r3                            ! table[41] = 0x2A
    mov r4, r3                              ! r3 = table base
    add #0x54, r3                            ! r3 = &table[42] (skip to 0x36)
    mov #0x36, r2                            ! r2 = 0x36 (gap: indices 0x2B-0x35 skipped)
    mov.w r2, @r3                            ! table[42] = 0x36
    add #0x56, r4                            ! r4 = &table[43]
    mov #0x37, r3                            ! r3 = 0x37
    mov.w r3, @r4                            ! table[43] = 0x37
    extu.w r5, r11                           ! r11 = 0x1E (initial sprite word index)
    mov.w   .L_vdp1_vram_base_lo, r6        ! r6 = 0x4240 (VDP1 VRAM base low word)
    bra     .L_copy_vdp1_data               ! -> copy VDP1 display data
    nop                                      ! (delay slot)
.L_vdp1_vram_base_lo:
    .2byte  0x4240                           ! VDP1 VRAM base low 16 bits
.L_channel_table_base:
    .4byte  sym_06056940                     ! channel descriptor table (12 bytes/entry)
.L_proj_param_source:
    .4byte  sym_0606A4EC                     ! projection parameter source pointer
.L_sprite_index_table:
    .4byte  sym_06089E44                     ! sprite word index table (halfword array)
.L_copy_vdp1_data:
    mov.l   .L_vdp1_vram_dest, r5           ! r5 = 0x002A8000 (VDP1 VRAM dest)
    mov.l   .L_game_state_index_ptr, r4     ! r4 = &game_state_index
    mov.l   .L_scroll_base_table_ptr, r3    ! r3 = &scroll_base_table
    mov.w   .L_scroll_data_offset, r2       ! r2 = 0x03C0 (offset into scroll data)
    mov.l @r4, r4                            ! r4 = game_state_index
    mov.l @r3, r3                            ! r3 = scroll_base_table
    shll2 r4                                 ! r4 *= 4
    shll r4                                  ! r4 *= 2 (total *8 for 8-byte entries)
    add r3, r4                               ! r4 = scroll_base + state_index * 8
    add r2, r4                               ! r4 += 0x03C0 (src address for copy)
    mov.l   .L_memcpy_word_idx_fn, r2       ! r2 = &memcpy_word_idx
    jsr @r2                                  ! memcpy_word_idx(dst=r5, src=r4, count=r6)
    nop                                      ! (delay slot)
    bra     .L_channel_loop_test             ! -> enter channel loop at test
    mov #0x0, r12                            ! r12 = 0 (channel counter, delay slot)
.L_channel_loop_body:
    extu.b r12, r4                           ! r4 = channel index (byte)
    mov #0x13, r2                            ! r2 = 0x13 (threshold for extra offset)
    mov r4, r3                               ! r3 = channel index
    shll2 r4                                 ! r4 *= 4
    shll2 r3                                 ! r3 *= 4
    shll r3                                  ! r3 *= 2 (total *8)
    add r3, r4                               ! r4 = index*4 + index*8 = index*12
    extu.b r4, r4                            ! r4 = (byte) channel offset
    extu.w r12, r3                           ! r3 = channel index (word)
    add r9, r4                               ! r4 = channel_table + offset (channel desc)
    mov.l @r4, r10                           ! r10 = channel[+0] primary data pointer
    mov.w @(8, r4), r0                       ! r0 = channel[+8] primary entry count
    cmp/gt r2, r3                            ! channel > 0x13?
    bf/s    .L_no_extra_offset               ! if channel <= 0x13 -> skip extra offset
    mov r0, r8                               ! r8 = primary entry count (delay slot)
    add #0x36, r11                           ! r11 += 0x36 (extra sprite index bump)
.L_no_extra_offset:
    extu.w r8, r2                            ! r2 = primary entry count (unsigned)
    cmp/pl r2                                ! count > 0?
    bf/s    .L_primary_done                  ! if no primary entries -> skip to secondary
    mov #0x0, r14                            ! r14 = 0 (primary sub-index, delay slot)
.L_primary_entry_loop:
    extu.w r12, r0                           ! r0 = channel index
    cmp/eq #0x13, r0                         ! channel == 0x13?
    bf      .L_render_primary_entry          ! if not channel 0x13 -> render directly
    extu.w r14, r0                           ! r0 = primary sub-index
    cmp/eq #0x15, r0                         ! sub-index == 0x15?
    bf      .L_check_idx_27                  ! if not -> check next
    mov.l @r13, r2                           ! r2 = *proj_param_source
    mov.l   .L_proj_param_a, r3             ! r3 = &proj_param_a (sym_06089E30)
    mov.l r2, @r3                            ! proj_param_a = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_check_idx_27:
    extu.w r14, r0                           ! r0 = primary sub-index
    cmp/eq #0x27, r0                         ! sub-index == 0x27?
    bf      .L_check_idx_40                  ! if not -> check next
    mov.l @r13, r2                           ! r2 = *proj_param_source
    mov.l   .L_proj_param_b, r3             ! r3 = &proj_param_b (sym_06089E2C)
    mov.l r2, @r3                            ! proj_param_b = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_check_idx_40:
    extu.w r14, r0                           ! r0 = primary sub-index
    cmp/eq #0x40, r0                         ! sub-index == 0x40?
    bf      .L_check_idx_44                  ! if not -> check next
    mov.l @r13, r2                           ! r2 = *proj_param_source
    mov.l   .L_proj_param_x, r3             ! r3 = &proj_param_x (sym_06089E34)
    mov.l r2, @r3                            ! proj_param_x = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_check_idx_44:
    extu.w r14, r0                           ! r0 = primary sub-index
    cmp/eq #0x44, r0                         ! sub-index == 0x44?
    bf      .L_check_idx_82                  ! if not -> check next
    mov.l @r13, r2                           ! r2 = *proj_param_source
    mov.l   .L_proj_param_y, r3             ! r3 = &proj_param_y (sym_06089E38)
    mov.l r2, @r3                            ! proj_param_y = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_check_idx_82:
    extu.w r14, r2                           ! r2 = primary sub-index
    mov.w   .L_proj_idx_82, r3              ! r3 = 0x0082
    cmp/eq r3, r2                            ! sub-index == 0x82?
    bf      .L_check_idx_88                  ! if not -> check next
    mov.l @r13, r3                           ! r3 = *proj_param_source
    mov.l   .L_proj_config_ptr, r2          ! r2 = &proj_config (sym_06089E28)
    mov.l r3, @r2                            ! proj_config = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_check_idx_88:
    extu.w r14, r2                           ! r2 = primary sub-index
    mov.w   .L_proj_idx_88, r3              ! r3 = 0x0088
    cmp/eq r3, r2                            ! sub-index == 0x88?
    bf      .L_check_idx_a9                  ! if not -> check next
    mov.l @r13, r3                           ! r3 = *proj_param_source
    mov.l   .L_proj_param_c, r2             ! r2 = &proj_param_c (sym_06089E3C)
    mov.l r3, @r2                            ! proj_param_c = *proj_param_source
    bra     .L_render_primary_entry          ! -> render this entry
    nop                                      ! (delay slot)
.L_scroll_data_offset:
    .2byte  0x03C0                           ! offset into scroll base table per state
.L_proj_idx_82:
    .2byte  0x0082                           ! projection param index 0x82
.L_proj_idx_88:
    .2byte  0x0088                           ! projection param index 0x88
    .2byte  0xFFFF                           ! (alignment padding)
.L_vdp1_vram_dest:
    .4byte  0x002A8000                       ! VDP1 VRAM destination address
.L_game_state_index_ptr:
    .4byte  sym_06059FFC                     ! game state index pointer
.L_scroll_base_table_ptr:
    .4byte  sym_06063F5C                     ! display/scroll base table pointer
.L_memcpy_word_idx_fn:
    .4byte  memcpy_word_idx                  ! word copy function (index-based)
.L_proj_param_a:
    .4byte  sym_06089E30                     ! projection param A (at sub-index 0x15)
.L_proj_param_b:
    .4byte  sym_06089E2C                     ! projection param B (at sub-index 0x27)
.L_proj_param_x:
    .4byte  sym_06089E34                     ! projection param X (at sub-index 0x40)
.L_proj_param_y:
    .4byte  sym_06089E38                     ! projection param Y (at sub-index 0x44)
.L_proj_config_ptr:
    .4byte  sym_06089E28                     ! projection config ptr (at sub-index 0x82)
.L_proj_param_c:
    .4byte  sym_06089E3C                     ! projection param C (at sub-index 0x88)
.L_check_idx_a9:
    extu.w r14, r2                           ! r2 = primary sub-index
    mov.w   .L_proj_idx_a9, r3              ! r3 = 0x00A9
    cmp/eq r3, r2                            ! sub-index == 0xA9?
    bf      .L_render_primary_entry          ! if not -> render without storing param
    mov.l @r13, r3                           ! r3 = *proj_param_source
    mov.l   .L_proj_param_z, r2             ! r2 = &proj_param_z (sym_06089E40)
    mov.l r3, @r2                            ! proj_param_z = *proj_param_source
.L_render_primary_entry:
    extu.w r11, r5                           ! r5 = sprite word index (arg for render)
    mov.l   .L_sprite_render_fn, r3         ! r3 = &vdp1_sprite_render_alt
    mov.l   .L_vdp1_vram_base, r6          ! r6 = 0x002A8000 (VDP1 VRAM base)
    jsr @r3                                  ! vdp1_sprite_render_alt(r4=data, r5=idx, r6=vram)
    mov r10, r4                              ! r4 = primary data pointer (delay slot)
    add #0x1, r14                            ! r14++ (next sub-index)
    extu.w r8, r3                            ! r3 = primary entry count
    extu.w r14, r2                           ! r2 = current sub-index
    cmp/ge r3, r2                            ! sub-index >= count?
    bf/s    .L_primary_entry_loop            ! if more entries -> loop
    add #0xC, r10                            ! r10 += 0xC (next entry, delay slot)
.L_primary_done:
    extu.b r12, r14                          ! r14 = channel index (byte)
    mov r14, r3                              ! r3 = channel index
    shll2 r14                                ! r14 *= 4
    shll2 r3                                 ! r3 *= 4
    shll r3                                  ! r3 *= 2 (total *8)
    add r3, r14                              ! r14 = index*12 (channel stride)
    extu.b r14, r14                          ! r14 = (byte) channel offset
    add r9, r14                              ! r14 = &channel_table[index]
    mov.l @(4, r14), r14                     ! r14 = channel[+4] secondary data pointer
    tst r14, r14                             ! secondary pointer == NULL?
    bf      .L_has_secondary                 ! if non-NULL -> process secondary entries
    bra     .L_epilogue                      ! if NULL -> done, return
    nop                                      ! (delay slot)
.L_has_secondary:
    extu.b r12, r8                           ! r8 = channel index (byte)
    mov r8, r3                               ! r3 = channel index
    shll2 r8                                 ! r8 *= 4
    shll2 r3                                 ! r3 *= 4
    shll r3                                  ! r3 *= 2 (total *8)
    add r3, r8                               ! r8 = index*12 (channel stride)
    extu.b r8, r8                            ! r8 = (byte) channel offset
    add r9, r8                               ! r8 = &channel_table[index]
    mov.w @(10, r8), r0                      ! r0 = channel[+10] secondary entry count
    mov r0, r8                               ! r8 = secondary entry count
    extu.w r12, r0                           ! r0 = channel index
    cmp/eq #0x13, r0                         ! channel == 0x13?
    bf      .L_no_secondary_offset           ! if not -> skip extra offset
    add #0x53, r11                           ! r11 += 0x53 (extra sprite index for ch 0x13)
.L_no_secondary_offset:
    extu.w r8, r2                            ! r2 = secondary entry count (unsigned)
    cmp/pl r2                                ! count > 0?
    bf/s    .L_secondary_done                ! if no secondary entries -> skip
    mov #0x0, r10                            ! r10 = 0 (secondary sub-index, delay slot)
.L_secondary_entry_loop:
    extu.w r11, r5                           ! r5 = sprite word index (arg for render)
    mov.l   .L_secondary_render_fn, r3     ! r3 = &secondary render fn (sym_06007590)
    jsr @r3                                  ! secondary_render(r4=data, r5=idx)
    mov r14, r4                              ! r4 = secondary data pointer (delay slot)
    add #0x1, r10                            ! r10++ (next sub-index)
    extu.w r8, r3                            ! r3 = secondary entry count
    extu.w r10, r2                           ! r2 = current sub-index
    cmp/ge r3, r2                            ! sub-index >= count?
    bf/s    .L_secondary_entry_loop          ! if more entries -> loop
    add #0x6, r14                            ! r14 += 0x6 (next entry, delay slot)
.L_secondary_done:
    extu.w r12, r0                           ! r0 = channel index
    cmp/eq #0x14, r0                         ! channel == 0x14 (last channel)?
    bf      .L_skip_bank_store               ! if not last -> skip bank store
    mov.l   .L_sprite_bank_base, r3         ! r3 = &sprite_bank_base (sym_0607886C)
    mov.w r11, @r3                           ! sprite_bank_base = r11 (final word index)
.L_skip_bank_store:
    extu.w r12, r2                           ! r2 = channel index
    mov #0x13, r3                            ! r3 = 0x13
    cmp/ge r3, r2                            ! channel >= 0x13?
    bt      .L_channel_next                  ! if >= 0x13 -> skip per-channel index bump
    add #0xA, r11                            ! r11 += 0xA (per-channel sprite index bump)
.L_channel_next:
    add #0x1, r12                            ! r12++ (next channel)
.L_channel_loop_test:
    extu.w r12, r3                           ! r3 = channel index
    mov #0x14, r2                            ! r2 = 0x14 (max channel)
    cmp/gt r2, r3                            ! channel > 0x14?
    bt      .L_epilogue                      ! if past last channel -> done
    bra     .L_channel_loop_body             ! -> process next channel
    nop                                      ! (delay slot)
.L_epilogue:
    lds.l @r15+, pr                          ! restore pr
    mov.l @r15+, r8                          ! restore r8
    mov.l @r15+, r9                          ! restore r9
    mov.l @r15+, r10                         ! restore r10
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return
    mov.l @r15+, r14                         ! restore r14 (delay slot)
.L_proj_idx_a9:
    .2byte  0x00A9                           ! projection param index 0xA9
.L_proj_param_z:
    .4byte  sym_06089E40                     ! projection param Z (at sub-index 0xA9)
.L_vdp1_vram_base:
    .4byte  0x002A8000                       ! VDP1 VRAM base address
.L_sprite_render_fn:
    .4byte  vdp1_sprite_render_alt           ! primary sprite render function
.L_secondary_render_fn:
    .4byte  sym_06007590                     ! secondary entry render function
.L_sprite_bank_base:
    .4byte  sym_0607886C                     ! sprite bank base halfword (written at ch 0x14)
