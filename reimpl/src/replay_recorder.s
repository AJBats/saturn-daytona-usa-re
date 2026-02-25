/* replay_recorder -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601BBDC - 0x0601BDEC
 *
 * Replay car model recorder — iterates over a range of cars and draws
 * their replay visualization elements (sprite models, position data,
 * and animation-transformed overlays) into VDP1 command slots.
 *
 * Arguments:
 *   r4 = mode (passed to data_copy as byte count)
 *   r5 = starting car index
 *   r6 = starting VDP1 slot index
 *
 * For each car in [start_car .. start_car+4]:
 *   1. Look up replay data entry from car table (12-byte stride)
 *   2. Draw car sprite model at computed VDP1 offset
 *   3. Copy position data to a second VDP1 offset
 *   4. If flag[0] set, draw additional position overlay for that car
 *   5. Call anim_frame_transform on model entry → get animation result
 *   6. Draw transformed animation at VDP1 position offset
 *   7. Compute anim index → look up model table entry → draw at VDP1 offset
 *   8. If flag[10] set, draw model A overlay (with table selector)
 *   9. If flag[9] set, draw model B overlay (offset by 0.5 fixed-point)
 *
 * VDP1 draw modes: 0x08 for position elements, 0x0C for model elements.
 * Model table entry stride: 8 bytes (base pointer at +0, data pointer at +4).
 * Replay car data stride: 12 bytes (indexed by car_idx * 12 via shll2+shll).
 */

    .section .text.FUN_0601BBDC


    .global replay_recorder
    .type replay_recorder, @function
replay_recorder:
    sts.l pr, @-r15                        ! save return address
    add #-0x24, r15                        ! allocate 36-byte stack frame
    mov.w   DAT_0601bcba, r8               ! r8 = 0x7000 (model data offset)
    mov r15, r1                            ! r1 = stack base (dest for copy)
    mov.l   _pool_replay_init_data_src, r2 ! r2 = &replay init data source
    mov.l   _pool_fn_sprite_draw, r11      ! r11 = sprite_draw function ptr
    mov.l   _pool_fn_vdp1_pos_draw, r12   ! r12 = vdp1_pos_draw function ptr
    mov.l   _pool_fn_data_copy, r3        ! r3 = data_copy function ptr
    add #0x20, r1                          ! r1 → stack+0x20 (copy dest)
    jsr @r3                                ! data_copy(src=r2, dst=r1, count=4)
    mov #0x4, r0                           ! (delay) r0 = 4 bytes to copy
    exts.b r5, r13                         ! r13 = car_index (sign-extended byte)
    exts.b r5, r5                          ! r5 = car_index (sign-extended)
    add #0x5, r5                           ! r5 = car_index + 5 (loop limit)
    mov.l r5, @(16, r15)                   ! stack[16] = loop_limit
    mov.l   _pool_model_table_a, r3        ! r3 = &model_table_a
    mov.l r3, @(4, r15)                    ! stack[4] = &model_table_a
    mov.l   _pool_model_table_b, r3        ! r3 = &model_table_b
    mov.l r3, @(8, r15)                    ! stack[8] = &model_table_b
    mov.l   _pool_model_table_c, r3        ! r3 = &model_table_c
    mov.l r3, @(12, r15)                   ! stack[12] = &model_table_c
    extu.w r13, r3                         ! r3 = car_index (zero-extended word)
    mov.l @(16, r15), r2                   ! r2 = loop_limit
    cmp/ge r2, r3                          ! if car_index >= loop_limit ...
    bf/s    .L_car_loop_top                ! ... no: enter main loop
    mov r6, r14                            ! (delay) r14 = slot_index
    bra     .L_epilogue                    ! ... yes: nothing to draw, exit
    nop                                    ! (delay)
.L_car_loop_top:
    extu.w r13, r7                         ! r7 = car_index (zero-extended)
    mov #0x60, r6                          ! r6 = 0x60 (draw size param)
    extu.w r14, r5                         ! r5 = slot_index (zero-extended)
    mov.l   _pool_car_data_table, r3       ! r3 = &car_data_table
    shll2 r7                               ! r7 = car_index * 4 (table index)
    shll2 r5                               ! r5 = slot_index * 4
    add r3, r7                             ! r7 → car_data_table[car_index]
    shll2 r5                               ! r5 = slot_index * 16
    mov.l @r7, r7                          ! r7 = car data pointer
    shll2 r5                               ! r5 = slot_index * 64
    mov.l r5, @r15                         ! stack[0] = slot_base = slot_index * 64
    add #0x2, r5                           ! r5 = slot_base + 2
    shll r5                                ! r5 = (slot_base + 2) * 2 = VDP1 offset
    jsr @r12                               ! vdp1_pos_draw(r4=mode, r5=vdp1_off, r6=0x60, r7=car_data)
    mov #0x8, r4                           ! (delay) r4 = 0x8 (position draw mode)
    extu.w r13, r10                        ! r10 = car_index
    mov r15, r7                            ! r7 = stack base
    mov #0x60, r6                          ! r6 = 0x60 (draw size param)
    mov.l @r15, r5                         ! r5 = slot_base (from stack[0])
    mov r10, r3                            ! r3 = car_index
    add #0x20, r7                          ! r7 → stack+0x20 (init data on stack)
    add #0x9, r5                           ! r5 = slot_base + 9
    shll2 r10                              ! r10 = car_index * 4
    shll2 r3                               ! r3 = car_index * 4
    shll r5                                ! r5 = (slot_base + 9) * 2 = VDP1 offset
    shll r3                                ! r3 = car_index * 8
    add r3, r10                            ! r10 = car_index * 12 (12-byte stride)
    add r9, r10                            ! r10 → car_record[car_index] (base + offset)
    jsr @r12                               ! vdp1_pos_draw(r4=mode, r5=vdp1_off, r6=0x60, r7=init_data)
    mov #0x8, r4                           ! (delay) r4 = 0x8 (position draw mode)
    mov.b @r10, r3                         ! r3 = car_record[car_index].flag_byte_0
    extu.b r3, r3                          ! zero-extend flag byte
    tst r3, r3                             ! test if flag is zero
    bt      .L_skip_extra_pos_draw         ! if zero, skip extra position draw
    mov r10, r7                            ! r7 = &car_record (source data)
    mov #0x60, r6                          ! r6 = 0x60 (draw size param)
    extu.w r14, r5                         ! r5 = slot_index
    shll2 r5                               ! r5 = slot_index * 4
    shll2 r5                               ! r5 = slot_index * 16
    shll2 r5                               ! r5 = slot_index * 64
    add #0x9, r5                           ! r5 = slot_index * 64 + 9
    shll r5                                ! r5 = VDP1 offset for extra element
    jsr @r12                               ! vdp1_pos_draw(r4=mode, r5=vdp1_off, r6=0x60, r7=car_record)
    mov #0x8, r4                           ! (delay) r4 = 0x8 (position draw mode)
.L_skip_extra_pos_draw:
    extu.w r13, r10                        ! r10 = car_index
    mov r10, r3                            ! r3 = car_index
    shll2 r10                              ! r10 = car_index * 4
    shll2 r3                               ! r3 = car_index * 4
    shll r3                                ! r3 = car_index * 8
    add r3, r10                            ! r10 = car_index * 12 (12-byte stride)
    add r9, r10                            ! r10 → car_record[car_index]
    mov.l   _pool_fn_anim_transform, r3    ! r3 = &anim_frame_transform
    jsr @r3                                ! r0 = anim_frame_transform(car_record[car_index].data_ptr)
    mov.l @(4, r10), r4                    ! (delay) r4 = car_record[car_index]+4 (data ptr)
    mov r0, r7                             ! r7 = animation transform result
    mov #0x78, r6                          ! r6 = 0x78 (draw size for anim result)
    extu.w r14, r5                         ! r5 = slot_index
    shll2 r5                               ! r5 = slot_index * 4
    shll2 r5                               ! r5 = slot_index * 16
    shll2 r5                               ! r5 = slot_index * 64
    add #0x10, r5                          ! r5 = slot_index * 64 + 16
    shll r5                                ! r5 = VDP1 offset for anim element
    jsr @r12                               ! vdp1_pos_draw(r4=mode, r5=vdp1_off, r6=0x78, r7=anim_result)
    mov #0x8, r4                           ! (delay) r4 = 0x8 (position draw mode)
    mov.b @(8, r10), r0                    ! r0 = car_record[car_index].anim_index (byte at +8)
    mov #0x0, r3                           ! r3 = 0 (clear value)
    mov #0xC, r2                           ! r2 = 12 (wrap threshold)
    mov r0, r10                            ! r10 = anim_index
    mov.b r3, @r15                         ! stack[0] = 0 (anim_base = 0)
    mov #0x1C, r0                          ! r0 = 0x1C (offset for wrap_flag)
    mov.b r3, @(r0, r15)                   ! stack[0x1C] = 0 (wrap_flag = 0)
    extu.b r10, r3                         ! r3 = anim_index (unsigned)
    cmp/ge r2, r3                          ! if anim_index >= 12 ...
    bf      .L_anim_idx_no_wrap            ! ... no: skip wrap adjustment
    add #-0xC, r10                         ! ... yes: anim_index -= 12 (wrap around)
    mov #0x1, r2                           ! r2 = 1
    mov #0x1C, r0                          ! r0 = 0x1C offset
    mov.b r2, @(r0, r15)                   ! stack[0x1C] = 1 (wrap_flag = set)
.L_anim_idx_no_wrap:
    extu.b r10, r3                         ! r3 = anim_index (unsigned, possibly wrapped)
    mov #0xA, r2                           ! r2 = 10 (high threshold)
    cmp/ge r2, r3                          ! if anim_index >= 10 ...
    bra     .L_check_anim_high             ! branch to check result (T bit carries)
    nop                                    ! (delay)

    .global DAT_0601bcba
DAT_0601bcba:
    .2byte  0x7000                         ! model data offset constant
_pool_fn_sprite_draw:
    .4byte  sym_06028400                   ! → sprite/model draw function
_pool_fn_vdp1_pos_draw:
    .4byte  sym_060284AE                   ! → VDP1 position element draw function
_pool_replay_init_data_src:
    .4byte  sym_0605DF3E                   ! → replay init data source address
_pool_fn_data_copy:
    .4byte  sym_06035228                   ! → byte/word data copy function
_pool_model_table_a:
    .4byte  sym_06063918                   ! → model table A (overlay selector == 1)
_pool_model_table_b:
    .4byte  sym_06063D08                   ! → model table B (overlay selector != 1)
_pool_model_table_c:
    .4byte  sym_06063920                   ! → model table C (overlay B with FP offset)
_pool_car_data_table:
    .4byte  sym_0605DE64                   ! → car data table (4-byte ptr entries)
_pool_fn_anim_transform:
    .4byte  anim_frame_transform           ! → animation frame transform function
.L_check_anim_high:
    bf      .L_anim_base_set               ! if anim_index < 10, skip base adjust
    mov #0x2, r2                           ! r2 = 2 (high anim base)
    mov.b r2, @r15                         ! stack[0] = 2 (anim_base = 2)
.L_anim_base_set:
    extu.b r10, r7                         ! r7 = anim_index (0-11, possibly wrapped)
    mov.b @r15, r3                         ! r3 = anim_base (0 or 2)
    mov #0x1C, r0                          ! r0 = 0x1C offset
    extu.w r14, r6                         ! r6 = slot_index
    shll8 r7                               ! r7 = anim_index << 8 (shifted for table calc)
    extu.b r3, r3                          ! r3 = anim_base (unsigned)
    mov.b @(r0, r15), r2                   ! r2 = wrap_flag (0 or 1)
    shll2 r6                               ! r6 = slot_index * 4
    shll2 r7                               ! r7 = anim_index << 10
    extu.b r2, r2                          ! r2 = wrap_flag (unsigned)
    shll2 r6                               ! r6 = slot_index * 16
    shll2 r7                               ! r7 = anim_index << 12
    add r2, r3                             ! r3 = anim_base + wrap_flag (composite index)
    shll2 r6                               ! r6 = slot_index * 64
    mov r3, r2                             ! r2 = composite_index
    add #0x3C, r2                          ! r2 = composite_index + 0x3C (model entry offset)
    mov r2, r3                             ! r3 = model entry index
    shll2 r3                               ! r3 = entry_index * 4
    mov.l   _pool_model_geom_table, r2     ! r2 = &model_geom_table
    shll r3                                ! r3 = entry_index * 8 (8-byte stride)
    add r3, r2                             ! r2 → model_geom_table[entry_index]
    mov.l r2, @(20, r15)                   ! stack[20] = &model_geom_entry
    mov.l @(4, r2), r3                     ! r3 = model_geom_entry.data_ptr
    mov.l r6, @(24, r15)                   ! stack[24] = slot_index * 64
    add r3, r7                             ! r7 = data_ptr + (anim_index << 12) (texture offset)
    add #0x21, r6                          ! r6 = slot_index * 64 + 0x21
    mov.l @(20, r15), r5                   ! r5 = &model_geom_entry
    shll r6                                ! r6 = VDP1 offset for model draw
    mov.l @r5, r5                          ! r5 = model_geom_entry.base_ptr
    jsr @r11                               ! sprite_draw(r4=mode, r5=base, r6=vdp1_off, r7=data)
    mov #0x8, r4                           ! (delay) r4 = 0x8 (position draw mode)
    mov.l   _pool_overlay_data, r7          ! r7 = &overlay draw data
    mov #0x60, r6                          ! r6 = 0x60 (draw size param)
    mov.l @(24, r15), r5                   ! r5 = slot_index * 64
    add #0x25, r5                          ! r5 = slot_index * 64 + 0x25
    shll r5                                ! r5 = VDP1 offset for overlay position
    jsr @r12                               ! vdp1_pos_draw(r4=0xC, r5=vdp1_off, r6=0x60, r7=overlay)
    mov #0xC, r4                           ! (delay) r4 = 0xC (model draw mode)
    extu.w r13, r3                         ! r3 = car_index
    mov r3, r2                             ! r2 = car_index
    shll2 r3                               ! r3 = car_index * 4
    shll2 r2                               ! r2 = car_index * 4
    shll r2                                ! r2 = car_index * 8
    add r2, r3                             ! r3 = car_index * 12 (12-byte stride)
    add r9, r3                             ! r3 → car_record[car_index]
    mov.b @(10, r3), r0                    ! r0 = car_record[car_index].overlay_a_flag (byte +10)
    mov r0, r3                             ! r3 = overlay_a_flag
    extu.b r3, r3                          ! zero-extend flag
    tst r3, r3                             ! test if overlay A flag is zero
    bt      .L_skip_overlay_a              ! if zero, skip overlay A draw
    mov.l   _pool_table_selector, r0        ! r0 = &table_selector variable
    mov.l @r0, r0                          ! r0 = table_selector value
    cmp/eq #0x1, r0                        ! if table_selector == 1 ...
    bf      .L_use_table_b                 ! ... no: use model table B
    extu.w r14, r6                         ! r6 = slot_index (use table A path)
    mov.l @(4, r15), r7                    ! r7 = &model_table_a
    shll2 r6                               ! r6 = slot_index * 4
    mov.l @(4, r7), r7                     ! r7 = model_table_a.data_ptr
    shll2 r6                               ! r6 = slot_index * 16
    add r8, r7                             ! r7 = data_ptr + 0x7000 (model offset)
    shll2 r6                               ! r6 = slot_index * 64
    add #0x25, r6                          ! r6 = slot_index * 64 + 0x25
    shll r6                                ! r6 = VDP1 offset for overlay model
    bra     .L_draw_overlay_model          ! → common draw path
    mov.l @(4, r15), r5                    ! (delay) r5 = &model_table_a (base ptr)
_pool_model_geom_table:
    .4byte  sym_06063750                   ! → model geometry table (8-byte stride entries)
_pool_overlay_data:
    .4byte  sym_0604A4B8                   ! → overlay draw data block
_pool_table_selector:
    .4byte  sym_06078644                   ! → table selector variable (1=table_a, else=table_b)
.L_use_table_b:
    mov.l @(8, r15), r7                    ! r7 = &model_table_b
    extu.w r14, r6                         ! r6 = slot_index
    mov.l @(4, r7), r7                     ! r7 = model_table_b.data_ptr
    shll2 r6                               ! r6 = slot_index * 4
    add r8, r7                             ! r7 = data_ptr + 0x7000 (model offset)
    shll2 r6                               ! r6 = slot_index * 16
    shll2 r6                               ! r6 = slot_index * 64
    add #0x25, r6                          ! r6 = slot_index * 64 + 0x25
    shll r6                                ! r6 = VDP1 offset for overlay model
    mov.l @(8, r15), r5                    ! r5 = &model_table_b (base ptr)
.L_draw_overlay_model:
    mov.l @r5, r5                          ! r5 = model_table.base_ptr (deref)
    jsr @r11                               ! sprite_draw(r4=0xC, r5=base, r6=vdp1_off, r7=data)
    mov #0xC, r4                           ! (delay) r4 = 0xC (model draw mode)
.L_skip_overlay_a:
    extu.w r13, r3                         ! r3 = car_index
    mov r3, r2                             ! r2 = car_index
    shll2 r3                               ! r3 = car_index * 4
    shll2 r2                               ! r2 = car_index * 4
    shll r2                                ! r2 = car_index * 8
    add r2, r3                             ! r3 = car_index * 12 (12-byte stride)
    add r9, r3                             ! r3 → car_record[car_index]
    mov.b @(9, r3), r0                     ! r0 = car_record[car_index].overlay_b_flag (byte +9)
    mov r0, r3                             ! r3 = overlay_b_flag
    extu.b r3, r3                          ! zero-extend flag
    tst r3, r3                             ! test if overlay B flag is zero
    bt      .L_skip_overlay_b              ! if zero, skip overlay B draw
    mov.l @(12, r15), r7                   ! r7 = &model_table_c
    extu.w r14, r6                         ! r6 = slot_index
    mov.l @(12, r15), r5                   ! r5 = &model_table_c (for base ptr)
    mov.l   .L_fp_half, r3                 ! r3 = 0x00008000 (0.5 in 16.16 fixed-point)
    mov.l @(4, r7), r7                     ! r7 = model_table_c.data_ptr
    shll2 r6                               ! r6 = slot_index * 4
    mov.l @r5, r5                          ! r5 = model_table_c.base_ptr
    add r3, r7                             ! r7 = data_ptr + 0.5 FP (half-pixel offset)
    shll2 r6                               ! r6 = slot_index * 16
    shll2 r6                               ! r6 = slot_index * 64
    add #0x28, r6                          ! r6 = slot_index * 64 + 0x28
    shll r6                                ! r6 = VDP1 offset for overlay B
    jsr @r11                               ! sprite_draw(r4=0xC, r5=base, r6=vdp1_off, r7=data+0.5)
    mov #0xC, r4                           ! (delay) r4 = 0xC (model draw mode)
.L_skip_overlay_b:
    add #0x1, r13                          ! car_index++
    mov.l @(16, r15), r2                   ! r2 = loop_limit
    extu.w r13, r3                         ! r3 = car_index (zero-extended)
    cmp/ge r2, r3                          ! if car_index >= loop_limit ...
    bt/s    .L_epilogue                    ! ... yes: done, exit loop
    add #0x3, r14                          ! (delay) slot_index += 3 (advance 3 VDP1 slots per car)
    bra     .L_car_loop_top                ! ... no: process next car
    nop                                    ! (delay)
.L_epilogue:
    add #0x24, r15                         ! deallocate 36-byte stack frame
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r8                        ! restore r8
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return to caller
    mov.l @r15+, r14                       ! (delay) restore r14
    .2byte  0xFFFF                         ! alignment padding
.L_fp_half:
    .4byte  0x00008000                     ! 0.5 in 16.16 fixed-point format
