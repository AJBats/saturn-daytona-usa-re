/* course_select_draw -- course selection screen display list draw
 * Translation unit: 0x0601950C - 0x060196A4
 *
 * Draws the course thumbnails on the course selection screen. Iterates
 * over all 4 course slots, loading each course's display list via the
 * dlist_loader (sym_06028400). Tracks which course was last drawn in
 * sym_06085FF1, so the highlight animation knows the previous state.
 *
 * After drawing the non-selected courses, handles the highlight for
 * the currently selected course:
 *   - If the blink timer (sym_0605D242) <= 15: draws the selected
 *     course with a 0x4000 texture offset (highlighted appearance)
 *   - If timer > 15 (blink phase): draws the selected course twice
 *     using vdp_number_text (sym_060284AE) to create a blink effect,
 *     once normal and once with color+2 offset. Resets timer after 30.
 *
 * Register plan (callee-saved):
 *   r8  = course slot LUT base (sym_06049AF4)
 *   r9  = dlist_loader function (sym_06028400)
 *   r10 = object table base (sym_06063750)
 *   r11 = 0 (used to reset last-drawn index and blink timer)
 *   r12 = &current course index (sym_0605D244)
 *   r13 = course slot param table (sym_06049AEC)
 *   r14 = loop counter / blink timer pointer
 *
 * Calls: sym_06028400 (dlist_loader), sym_060284AE (vdp_number_text)
 */

    .section .text.FUN_0601950C


    .global course_select_draw
    .type course_select_draw, @function
course_select_draw:
    mov.l r14, @-r15                         ! save r14
    mov.l r13, @-r15                         ! save r13
    mov.l r12, @-r15                         ! save r12
    mov.l r11, @-r15                         ! save r11
    mov.l r10, @-r15                         ! save r10
    mov.l r9, @-r15                          ! save r9
    mov.l r8, @-r15                          ! save r8
    sts.l pr, @-r15                          ! save return address
    add #-0xC, r15                           ! allocate 12-byte stack frame
    mov.l   _pool_course_slot_lut, r8        ! r8 -> course slot LUT base
    mov.l   _pool_dlist_loader, r9           ! r9 -> dlist_loader function
    mov.l   _pool_obj_table_base, r10        ! r10 -> object table base
    mov.l   _pool_course_index, r12          ! r12 -> &current selected course index (byte)
    mov.l   _pool_slot_param_table, r13      ! r13 -> course slot param table
    mov.l   _pool_last_drawn_course, r0      ! r0 -> &last-drawn course index (byte)
    mov.b @r0, r0                            ! r0 = last-drawn course index
    tst r0, r0                               ! is last-drawn == 0? (first frame / cleared)
    bt/s    .L_skip_loop                     ! yes -> skip the 4-course draw loop
    mov #0x0, r11                            ! r11 = 0 (constant: clear value)
    mov #0x14, r6                            ! r6 = 0x14 (display list offset for initial draw)
    mov.w   DAT_060195ac, r7                 ! r7 = 0x03B0 (object table byte offset)
    add r10, r7                              ! r7 -> obj_table + 0x03B0 (course 0 entry)
    mov.l r7, @r15                           ! [sp+0] = &course_entry
    mov.l @(4, r7), r7                       ! r7 = course_entry.texture_base (field +4)
    mov.w   DAT_060195ae, r3                 ! r3 = 0x1000 (texture offset for initial draw)
    mov.l @r15, r5                           ! r5 = &course_entry (reload from stack)
    add r3, r7                               ! r7 = texture_base + 0x1000
    mov.l @r5, r5                            ! r5 = course_entry.dlist_base (field +0)
    jsr @r9                                  ! dlist_loader(0xC, dlist_base, 0x14, tex+0x1000)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    exts.b r11, r14                          ! r14 = 0 (loop counter, sign-extended)
.L_loop_top:
    exts.b r14, r3                           ! r3 = current loop index (signed)
    mov.b @r12, r2                           ! r2 = currently selected course index
    cmp/eq r2, r3                            ! is this the selected course?
    bt      .L_skip_selected                 ! yes -> skip (drawn separately with highlight)
    exts.b r14, r0                           ! r0 = loop index (signed)
    shll r0                                  ! r0 = loop_index * 2 (LUT stride)
    mov.l r0, @(4, r15)                      ! [sp+4] = scaled loop index
    mov.w @(r0, r8), r7                      ! r7 = course_slot_lut[loop_index] (16-bit)
    extu.w r7, r7                            ! zero-extend to 32-bit
    shll2 r7                                 ! r7 *= 4
    shll r7                                  ! r7 *= 2 (total: *8, object table stride)
    add r10, r7                              ! r7 -> &obj_table[slot_entry]
    mov.l r7, @r15                           ! [sp+0] = &obj_table[slot_entry]
    mov.l @(4, r7), r7                       ! r7 = obj[slot].texture_base (field +4)
    mov.w   _wpool_tex_offset_2000, r3       ! r3 = 0x2000 (texture offset for non-selected)
    mov.l @(4, r15), r6                      ! r6 = scaled loop index
    add r3, r7                               ! r7 = texture_base + 0x2000
    add r13, r6                              ! r6 -> &slot_params[loop_index]
    mov.l r6, @(8, r15)                      ! [sp+8] = &slot_params[loop_index]
    mov.b @(1, r6), r0                       ! r0 = color_index (param byte +1)
    mov.l @(8, r15), r3                      ! r3 = &slot_params[loop_index] (reload)
    mov.l @r15, r5                           ! r5 = &obj_table[slot_entry] (reload)
    mov r0, r6                               ! r6 = color_index
    mov.b @r3, r3                            ! r3 = model_variant (param byte +0)
    mov.l @r5, r5                            ! r5 = obj[slot].dlist_base (field +0)
    extu.b r6, r6                            ! zero-extend color to 32-bit
    extu.b r3, r3                            ! zero-extend variant to 32-bit
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4 (total: *64, color block stride)
    add r3, r6                               ! r6 = color_block + variant
    shll r6                                  ! r6 *= 2 (final display list index)
    jsr @r9                                  ! dlist_loader(0xC, dlist, index, tex+0x2000)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
.L_skip_selected:
    exts.b r11, r3                           ! r3 = 0 (clear value for last-drawn)
    mov.l   _pool_last_drawn_course, r2      ! r2 -> &last-drawn course index
    add #0x1, r14                            ! r14++ (next loop iteration)
    mov.b r3, @r2                            ! last_drawn_course = 0 (reset each iteration)
    exts.b r14, r1                           ! r1 = loop counter (signed)
    mov #0x4, r2                             ! r2 = 4 (total course count)
    cmp/ge r2, r1                            ! loop_counter >= 4?
    bf      .L_loop_top                      ! no -> continue loop
.L_skip_loop:
    mov.l   _pool_highlight_flag, r0         ! r0 -> &highlight active flag (byte)
    mov.b @r0, r0                            ! r0 = highlight_active
    extu.b r0, r0                            ! zero-extend to 32-bit
    tst r0, r0                               ! is highlight active?
    bt      .L_draw_highlight                ! no (0) -> draw highlight phase
    bra     .L_epilogue                      ! yes (nonzero) -> skip to return
    nop

    .global DAT_060195ac
DAT_060195ac:
    .2byte  0x03B0

    .global DAT_060195ae
DAT_060195ae:
    .2byte  0x1000
_wpool_tex_offset_2000:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_course_slot_lut:
    .4byte  sym_06049AF4
_pool_dlist_loader:
    .4byte  sym_06028400
_pool_obj_table_base:
    .4byte  sym_06063750
_pool_course_index:
    .4byte  sym_0605D244
_pool_slot_param_table:
    .4byte  sym_06049AEC
_pool_last_drawn_course:
    .4byte  sym_06085FF1
_pool_highlight_flag:
    .4byte  sym_06085FF5
.L_draw_highlight:
    mov.l   _pool_blink_timer, r14           ! r14 -> &blink animation timer (byte)
    mov #0xF, r2                             ! r2 = 15 (blink phase threshold)
    mov.b @r14, r3                           ! r3 = current blink timer value
    extu.b r3, r3                            ! zero-extend timer to 32-bit
    cmp/gt r2, r3                            ! timer > 15?
    bt      .L_blink_phase                   ! yes -> draw blink effect
    mov.b @r12, r0                           ! r0 = selected course index
    shll r0                                  ! r0 = course_index * 2 (LUT stride)
    mov.l r0, @(4, r15)                      ! [sp+4] = scaled course index
    mov.w @(r0, r8), r7                      ! r7 = course_slot_lut[selected] (16-bit)
    extu.w r7, r7                            ! zero-extend to 32-bit
    shll2 r7                                 ! r7 *= 4
    shll r7                                  ! r7 *= 2 (total: *8, object table stride)
    add r10, r7                              ! r7 -> &obj_table[selected_slot]
    mov.l r7, @r15                           ! [sp+0] = &obj_table[selected_slot]
    mov.l @(4, r7), r7                       ! r7 = obj[selected].texture_base (field +4)
    mov.w   DAT_06019694, r3                 ! r3 = 0x4000 (highlight texture offset)
    mov.l @(4, r15), r6                      ! r6 = scaled course index
    add r3, r7                               ! r7 = texture_base + 0x4000 (highlight)
    add r13, r6                              ! r6 -> &slot_params[selected]
    mov.l r6, @(8, r15)                      ! [sp+8] = &slot_params[selected]
    mov.b @(1, r6), r0                       ! r0 = color_index (param byte +1)
    mov.l @(8, r15), r3                      ! r3 = &slot_params[selected] (reload)
    mov.l @r15, r5                           ! r5 = &obj_table[selected_slot] (reload)
    mov r0, r6                               ! r6 = color_index
    mov.b @r3, r3                            ! r3 = model_variant (param byte +0)
    mov.l @r5, r5                            ! r5 = obj[selected].dlist_base (field +0)
    extu.b r6, r6                            ! zero-extend color to 32-bit
    extu.b r3, r3                            ! zero-extend variant to 32-bit
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4 (total: *64, color block stride)
    add r3, r6                               ! r6 = color_block + variant
    shll r6                                  ! r6 *= 2 (final display list index)
    jsr @r9                                  ! dlist_loader(0xC, dlist, index, tex+0x4000)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    bra     .L_epilogue                      ! done -> exit
    nop
.L_blink_phase:
    mov.l   _pool_blink_geom_data, r7        ! r7 -> &blink geometry data pointer
    mov.w   _wpool_blink_param_offset, r6    ! r6 = 0x0090 (param table byte offset)
    mov.b @r12, r5                           ! r5 = selected course index
    mov.l @r7, r7                            ! r7 = blink geometry data (dereferenced)
    shll r5                                  ! r5 = course_index * 2 (param stride)
    add r13, r5                              ! r5 -> &slot_params[selected]
    mov.l r5, @r15                           ! [sp+0] = &slot_params[selected]
    mov.b @(1, r5), r0                       ! r0 = color_index (param byte +1)
    mov.l @r15, r3                           ! r3 = &slot_params[selected] (reload)
    mov r0, r5                               ! r5 = color_index
    mov.b @r3, r3                            ! r3 = model_variant (param byte +0)
    extu.b r5, r5                            ! zero-extend color to 32-bit
    extu.b r3, r3                            ! zero-extend variant to 32-bit
    shll2 r5                                 ! r5 *= 4
    shll2 r5                                 ! r5 *= 4
    shll2 r5                                 ! r5 *= 4 (total: *64, color block stride)
    add r3, r5                               ! r5 = color_block + variant
    shll r5                                  ! r5 *= 2 (final display list index)
    mov.l   _pool_vdp_num_text, r3           ! r3 -> vdp_number_text function
    jsr @r3                                  ! vdp_num_text(0xC, r5=index, r6=0x90, r7=geom)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    mov.l   _pool_blink_geom_data, r7        ! r7 -> &blink geometry data pointer (reload)
    mov.w   _wpool_blink_param_offset, r6    ! r6 = 0x0090 (param table byte offset)
    mov.b @r12, r5                           ! r5 = selected course index
    mov.l @r7, r7                            ! r7 = blink geometry data (dereferenced)
    shll r5                                  ! r5 = course_index * 2 (param stride)
    add r13, r5                              ! r5 -> &slot_params[selected]
    mov.l r5, @r15                           ! [sp+0] = &slot_params[selected]
    mov.b @(1, r5), r0                       ! r0 = color_index (param byte +1)
    mov.l @r15, r3                           ! r3 = &slot_params[selected] (reload)
    mov r0, r5                               ! r5 = color_index
    mov.b @r3, r3                            ! r3 = model_variant (param byte +0)
    extu.b r5, r5                            ! zero-extend color to 32-bit
    extu.b r3, r3                            ! zero-extend variant to 32-bit
    add #0x2, r5                             ! r5 += 2 (alternate color for blink)
    shll2 r5                                 ! r5 *= 4
    shll2 r5                                 ! r5 *= 4
    shll2 r5                                 ! r5 *= 4 (total: *64, color block stride)
    add r3, r5                               ! r5 = alt_color_block + variant
    shll r5                                  ! r5 *= 2 (final display list index)
    mov.l   _pool_vdp_num_text, r3           ! r3 -> vdp_number_text function
    jsr @r3                                  ! vdp_num_text(0xC, r5=alt_index, r6=0x90, r7=geom)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    mov #0x1E, r3                            ! r3 = 30 (blink cycle length)
    mov.b @r14, r2                           ! r2 = current blink timer value
    extu.b r2, r2                            ! zero-extend timer to 32-bit
    cmp/gt r3, r2                            ! timer > 30?
    bf      .L_epilogue                      ! no -> exit (still within blink cycle)
    extu.b r11, r3                           ! r3 = 0 (reset value)
    mov.b r3, @r14                           ! blink_timer = 0 (restart cycle)
.L_epilogue:
    add #0xC, r15                            ! deallocate stack frame
    lds.l @r15+, pr                          ! restore return address
    mov.l @r15+, r8                          ! restore r8
    mov.l @r15+, r9                          ! restore r9
    mov.l @r15+, r10                         ! restore r10
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return
    mov.l @r15+, r14                         ! (delay) restore r14

    .global DAT_06019694
DAT_06019694:
    .2byte  0x4000
_wpool_blink_param_offset:
    .2byte  0x0090
_pool_blink_timer:
    .4byte  sym_0605D242
_pool_blink_geom_data:
    .4byte  sym_0605D4EC
_pool_vdp_num_text:
    .4byte  sym_060284AE
