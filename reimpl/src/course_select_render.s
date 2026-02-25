/* course_select_render -- course selection screen input & display handler
 * Translation unit: 0x060196B0 - 0x060197F4
 *
 * Handles course selection screen rendering and input processing.
 * Called each frame during course select; processes directional input
 * to cycle through available courses and confirm selection.
 *
 * Flow:
 *   1. Finalize dual-screen scene (scene_dual_finalize)
 *   2. Read button status word at sym_06063D98+2
 *   3. If confirm bit (0x0100) pressed:
 *      - Load course slot, resolve display params from LUT + object table
 *      - Call display list loader (sym_06028400) with layer 0xC
 *      - Set confirm flags, clear animation state, write game state = 4
 *      - Return via rts
 *   4. If next-course bit (0x2000) pressed:
 *      - Increment course_slot_idx (wrap 4 -> 0)
 *      - Fall through to common exit
 *   5. If prev-course bit (0x1000) pressed:
 *      - Decrement course_slot_idx (wrap <0 -> 3)
 *      - Fall through to common exit
 *   6. Common exit: increment animation timer + display counter,
 *      look up dispatch table by course_slot_idx, tail-call via jmp
 *
 * Callee-saved register plan:
 *   r10 = &course_confirm_flag (sym_06085FF1, byte)
 *   r11 = (inherited from caller, used as 0)
 *   r12 = &display_active (sym_0605D242, byte)
 *   r13 = 1 (constant)
 *   r14 = &course_slot_idx (sym_0605D244, byte, 0-3)
 */

    .section .text.FUN_060196B0


    .global course_select_render
    .type course_select_render, @function
course_select_render:
    sts.l pr, @-r15                              ! save return address
    add #-0xC, r15                               ! allocate 12-byte stack frame
    mov.l   _pool_confirm_flag, r10              ! r10 -> &course_confirm_flag (sym_06085FF1)
    mov.l   _pool_display_active, r12            ! r12 -> &display_active (sym_0605D242)
    mov.l   _pool_course_slot_idx, r14           ! r14 -> &course_slot_idx (sym_0605D244)
    mov.l   _pool_fn_scene_finalize, r3          ! r3 -> scene_dual_finalize
    jsr @r3                                      ! call scene_dual_finalize()
    mov #0x1, r13                                ! (delay) r13 = 1 (constant for later)
    mov.l   _pool_input_struct, r4               ! r4 -> input/button struct (sym_06063D98)
    mov.w   _wpool_confirm_mask, r3              ! r3 = 0x0100 (confirm button mask)
    mov.w @(2, r4), r0                           ! r0 = button status word at +2
    mov r0, r2                                   ! r2 = copy of button word
    extu.w r2, r2                                ! zero-extend to 32-bit
    and r3, r2                                   ! isolate confirm bit
    tst r2, r2                                   ! confirm pressed?
    bt      .L_no_confirm                        ! no -> check directional input
    mov.b @r14, r7                               ! r7 = course_slot_idx (0-3)
    shll r7                                      ! r7 *= 2 (LUT stride is 2 bytes)
    mov.l r7, @(8, r15)                          ! [sp+8] = scaled slot index
    mov.l   _pool_course_slot_lut, r3            ! r3 -> course slot LUT base (sym_06049AF4)
    mov.l   _pool_course_obj_table, r2           ! r2 -> course object table base (sym_06063750)
    add r3, r7                                   ! r7 -> &course_slot_lut[slot]
    mov.w @r7, r7                                ! r7 = model entry (16-bit LUT value)
    extu.w r7, r7                                ! zero-extend to 32-bit
    shll2 r7                                     ! r7 *= 4
    shll r7                                      ! r7 *= 2 (total: *8, object table stride)
    add r2, r7                                   ! r7 -> &obj_table[model_entry]
    mov.l r7, @(4, r15)                          ! [sp+4] = &obj_table[model_entry]
    mov.l @(4, r7), r7                           ! r7 = obj[model].texture_base (field +4)
    mov.w   _wpool_texture_offset, r3            ! r3 = 0x2000 (texture data offset)
    mov.l @(8, r15), r6                          ! r6 = scaled slot index (from [sp+8])
    add r3, r7                                   ! r7 = texture_base + 0x2000
    mov.l   _pool_slot_params, r3                ! r3 -> slot param table (sym_06049AEC)
    add r3, r6                                   ! r6 -> &slot_params[slot]
    mov.l r6, @r15                               ! [sp+0] = &slot_params[slot]
    mov.b @(1, r6), r0                           ! r0 = color_index (param byte +1)
    mov.l @r15, r2                               ! r2 = &slot_params[slot] (reload)
    mov r0, r6                                   ! r6 = color_index
    mov.b @r2, r2                                ! r2 = model_variant (param byte +0)
    extu.b r6, r6                                ! zero-extend color to 32-bit
    extu.b r2, r2                                ! zero-extend variant to 32-bit
    shll2 r6                                     ! r6 *= 4
    shll2 r6                                     ! r6 *= 4
    shll2 r6                                     ! r6 *= 4 (total: *64, color block stride)
    add r2, r6                                   ! r6 = color_block + variant
    shll r6                                      ! r6 *= 2 (final display list index)
    mov.l @(4, r15), r5                          ! r5 = &obj_table[model_entry]
    mov.l @r5, r5                                ! r5 = obj[model].dlist_base (field +0)
    mov.l   _pool_fn_dlist_loader, r3            ! r3 -> display list loader (sym_06028400)
    jsr @r3                                      ! call dlist_loader(0xC, dlist_base, index, texture)
    mov #0xC, r4                                 ! (delay) r4 = 0xC (display layer count)
    mov.b @r14, r2                               ! r2 = course_slot_idx
    cmp/gt r13, r2                               ! slot_idx > 1?
    bf      .L_skip_slot_reset                   ! no -> skip reset
    exts.b r11, r2                               ! r2 = 0 (sign-extend r11)
    mov.b r2, @r14                               ! course_slot_idx = 0 (reset)
.L_skip_slot_reset:
    mov.l   _pool_anim_state, r3                 ! r3 -> &animation state (sym_06059F44)
    mov.l r11, @r3                               ! animation_state = 0 (clear 32-bit)
    extu.b r11, r2                               ! r2 = 0 (zero-extend r11)
    mov.b r2, @r12                               ! display_active = 0 (clear)
    mov #0x4, r3                                 ! r3 = 4 (game state: course confirmed)
    mov.l   _pool_game_state_val, r2             ! r2 -> &game state dispatch (sym_0605AD10)
    mov.l r3, @r2                                ! game_state_dispatch = 4
    exts.b r13, r3                               ! r3 = 1 (sign-extend r13)
    mov.b r3, @r10                               ! course_confirm_flag = 1 (confirmed)
    mov.l   _pool_select_flag_f, r3              ! r3 -> &select_flag_f (sym_06085FF5)
    bra     .L_epilog_rts                        ! jump to rts epilog
    mov.b r13, @r3                               ! (delay) select_flag_f = 1
.L_no_confirm:
    mov.w @(2, r4), r0                           ! r0 = button status word at +2 (re-read)
    mov.w   _wpool_texture_offset, r3            ! r3 = 0x2000 (next-course button mask)
    mov r0, r2                                   ! r2 = copy of button word
    extu.w r2, r2                                ! zero-extend to 32-bit
    and r3, r2                                   ! isolate next-course bit
    tst r2, r2                                   ! next-course pressed?
    bt/s    .L_check_prev_course                 ! no -> check previous course
    mov #0x5, r5                                 ! (delay) r5 = 5 (display counter value)
    mov.b r13, @r10                              ! course_confirm_flag = 1 (direction active)
    extu.b r5, r5                                ! zero-extend r5
    mov.b r5, @r12                               ! display_active = 5
    mov.b @r14, r2                               ! r2 = course_slot_idx
    add #0x1, r2                                 ! r2++ (next course)
    mov.b r2, @r14                               ! course_slot_idx = r2
    mov.b @r14, r3                               ! r3 = updated slot index
    mov #0x4, r2                                 ! r2 = 4 (max courses)
    cmp/ge r2, r3                                ! slot_idx >= 4?
    bf      .L_common_exit                       ! no -> common exit
    exts.b r11, r2                               ! r2 = 0 (wrap around)
    bra     .L_common_exit                       ! jump to common exit
    mov.b r2, @r14                               ! (delay) course_slot_idx = 0

    .global DAT_06019762
_wpool_confirm_mask:
DAT_06019762:
    .2byte  0x0100
_wpool_texture_offset:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_confirm_flag:
    .4byte  sym_06085FF1
_pool_display_active:
    .4byte  sym_0605D242
_pool_course_slot_idx:
    .4byte  sym_0605D244
_pool_fn_scene_finalize:
    .4byte  scene_dual_finalize
_pool_input_struct:
    .4byte  sym_06063D98
_pool_course_slot_lut:
    .4byte  sym_06049AF4
_pool_course_obj_table:
    .4byte  sym_06063750
_pool_slot_params:
    .4byte  sym_06049AEC
_pool_fn_dlist_loader:
    .4byte  sym_06028400
_pool_anim_state:
    .4byte  sym_06059F44
_pool_game_state_val:
    .4byte  sym_0605AD10
_pool_select_flag_f:
    .4byte  sym_06085FF5
.L_check_prev_course:
    mov.w @(2, r4), r0                           ! r0 = button status word at +2 (re-read)
    .byte   0x93, 0x63    /* mov.w .L_wpool_06019864, r3 — loads 0x1000 (prev-course mask) */
    mov r0, r2                                   ! r2 = copy of button word
    extu.w r2, r2                                ! zero-extend to 32-bit
    and r3, r2                                   ! isolate prev-course bit
    tst r2, r2                                   ! prev-course pressed?
    bt      .L_common_exit                       ! no -> common exit (no input)
    mov.b r13, @r10                              ! course_confirm_flag = 1 (direction active)
    extu.b r5, r5                                ! r5 = 5 (zero-extend, display counter)
    mov.b r5, @r12                               ! display_active = 5
    mov.b @r14, r2                               ! r2 = course_slot_idx
    add #-0x1, r2                                ! r2-- (previous course)
    mov.b r2, @r14                               ! course_slot_idx = r2
    mov.b @r14, r3                               ! r3 = updated slot index
    cmp/pz r3                                    ! slot_idx >= 0?
    bt      .L_common_exit                       ! yes -> common exit
    mov #0x3, r3                                 ! r3 = 3 (wrap to last course)
    mov.b r3, @r14                               ! course_slot_idx = 3
.L_common_exit:
    .byte   0xD4, 0x2B    /* mov.l .L_pool_0601986C, r4 — &anim_timer (sym_0605D243) */
    mov.b @r4, r2                                ! r2 = anim_timer value
    add #0x1, r2                                 ! r2++ (advance animation)
    mov.b r2, @r4                                ! anim_timer = r2
    mov.b @r12, r3                               ! r3 = display_active counter
    add #0x1, r3                                 ! r3++ (advance display counter)
    mov.b r3, @r12                               ! display_active = r3
    mov.b @r14, r2                               ! r2 = course_slot_idx (0-3)
    shll2 r2                                     ! r2 *= 4 (dispatch table stride)
    .byte   0xD3, 0x28    /* mov.l .L_pool_06019870, r3 — &dispatch_table (sym_0605D250) */
    add r3, r2                                   ! r2 -> &dispatch_table[slot_idx]
    mov.l @r2, r2                                ! r2 = dispatch_table[slot_idx] (fn pointer)
    add #0xC, r15                                ! deallocate stack frame
    lds.l @r15+, pr                              ! restore PR
    mov.l @r15+, r10                             ! restore r10
    mov.l @r15+, r11                             ! restore r11
    mov.l @r15+, r12                             ! restore r12
    mov.l @r15+, r13                             ! restore r13
    jmp @r2                                      ! tail-call dispatch_table[slot_idx]()
    mov.l @r15+, r14                             ! (delay) restore r14
.L_epilog_rts:
    add #0xC, r15                                ! deallocate stack frame
    lds.l @r15+, pr                              ! restore PR
    mov.l @r15+, r10                             ! restore r10
    mov.l @r15+, r11                             ! restore r11
    mov.l @r15+, r12                             ! restore r12
    mov.l @r15+, r13                             ! restore r13
    rts                                          ! return (confirm path)
    mov.l @r15+, r14                             ! (delay) restore r14
