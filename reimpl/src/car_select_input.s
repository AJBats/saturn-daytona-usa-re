/* VERIFIED: active during car select screen (called after mode select C press)
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on mode select
 *   12 calls during C (baseline 10, +2) — runs every frame during car select state
 * Date: 2026-02-28
 */
/* car_select_input -- car selection screen input handler
 * Translation unit: 0x06019A48 - 0x06019BC8
 *
 * Processes D-pad input on the car selection screen. Reads newly-pressed
 * button bits from the input state struct and handles three cases:
 *
 *   1. D-pad Up+Down (mask 0x0090): "confirm" — if current car index is 7
 *      (special slot), stores 7 into game_state_dispatch and exits. Otherwise
 *      sets car index to 7, marks input dirty, clears animation state, and
 *      calls camera_finalize.
 *
 *   2. D-pad Right (mask 0x2000): "next car" — increments the car index
 *      (wraps 8 -> 0), marks input dirty, and updates the car display via
 *      the display element renderer.
 *
 *   3. D-pad Left (mask from far pool): "prev car" — decrements the car
 *      index (wraps <0 -> 7), marks input dirty, and updates display.
 *
 * In all paths, the epilogue increments two frame counters, then uses
 * the current car index to look up a dispatch table and tail-calls the
 * resulting function pointer.
 *
 * Key data:
 *   sym_06085FF0 = current car index (byte, 0-7)
 *   sym_06085FF1 = input dirty flag (byte, 1 = changed)
 *   sym_06085FF3 = car select lock flag (byte, nonzero = locked)
 *   g_pad_state = input button state struct (+2 = newly pressed)
 *   sym_06049AFC = car slot param table (2 bytes/entry: variant, color)
 *   sym_0605D4F0 = car display data pointer (indirect)
 *   sym_060284AE = display element renderer (r4=layer, r5=dlist, r6=index, r7=tex)
 *   sym_0605AD10 = game state dispatch value (32-bit)
 *   sym_06059F44 = animation state (32-bit)
 *   sym_06026CE0 = camera state finalization
 *
 * Calls: sym_060284AE (display element renderer), sym_06026CE0 (camera finalize)
 */

    .section .text.FUN_06019A48


    .global car_select_input
    .type car_select_input, @function
car_select_input:
    mov.l r14, @-r15                             ! save r14 (car_index_ptr)
    mov.l r13, @-r15                             ! save r13
    mov.l r12, @-r15                             ! save r12
    mov.l r11, @-r15                             ! save r11
    mov.l r10, @-r15                             ! save r10
    mov.l r9, @-r15                              ! save r9
    mov.l r8, @-r15                              ! save r8
    sts.l pr, @-r15                              ! save return address
    add #-0x4, r15                               ! allocate 4 bytes stack frame
    mov.l   _pool_dirty_flag_ptr, r12            ! r12 -> &input_dirty_flag (sym_06085FF1)
    mov.l   _pool_car_index_ptr, r14             ! r14 -> &current_car_index (sym_06085FF0)
    mov.l   _pool_lock_flag_ptr, r3              ! r3 -> &car_select_lock (sym_06085FF3)
    mov.b @r3, r3                                ! r3 = car_select_lock value
    extu.b r3, r3                                ! zero-extend to 32-bit
    tst r3, r3                                   ! is car select locked?
    bt/s    .L_not_locked                        ! no -> process input
    mov #0x1, r10                                ! (delay) r10 = 1 (dirty flag value)
    bra     .L_epilogue                          ! locked -> skip to epilogue
    nop                                          ! (delay)
.L_not_locked:
    mov.l   _pool_input_state_ptr, r4            ! r4 -> input button state struct (g_pad_state)
    mov.l   _pool_display_renderer, r8           ! r8 -> display element renderer (sym_060284AE)
    mov.w   _wpool_dpad_updown_mask, r9          ! r9 = 0x0090 (D-pad up + down mask)
    mov.l   _pool_car_slot_params, r11           ! r11 -> car slot param table (sym_06049AFC)
    mov.w @(2, r4), r0                           ! r0 = newly pressed buttons (offset +2)
    mov r9, r2                                   ! r2 = 0x0090
    mov r0, r3                                   ! r3 = button state copy
    add #0x70, r2                                ! r2 = 0x0090 + 0x70 = 0x0100 (confirm mask)
    extu.w r3, r3                                ! zero-extend button state to 32-bit
    and r2, r3                                   ! isolate confirm bit(s)
    tst r3, r3                                   ! confirm pressed?
    bt/s    .L_no_confirm                        ! no -> check next/prev
    mov #0x7, r13                                ! (delay) r13 = 7 (max car index / special slot)
    mov.l   _pool_car_display_data, r7           ! r7 -> &car display data ptr (sym_0605D4F0)
    mov r9, r6                                   ! r6 = 0x0090 (used as texture param base)
    mov.b @r14, r5                               ! r5 = current car index
    mov.l @r7, r7                                ! r7 = car_display_data (indirect load)
    shll r5                                      ! r5 = car_index * 2 (param table stride)
    add r11, r5                                  ! r5 -> &car_slot_params[car_index]
    mov.l r5, @r15                               ! [sp+0] = param entry ptr (saved)
    mov.b @(1, r5), r0                           ! r0 = color_index (param byte +1)
    mov.l @r15, r3                               ! r3 = param entry ptr (reload)
    mov r0, r5                                   ! r5 = color_index
    mov.b @r3, r3                                ! r3 = model_variant (param byte +0)
    extu.b r5, r5                                ! zero-extend color_index
    extu.b r3, r3                                ! zero-extend model_variant
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4 (total: color_index * 64)
    add r3, r5                                   ! r5 = color_block + model_variant
    shll r5                                      ! r5 *= 2 (final display list index)
    jsr @r8                                      ! call display_renderer(0xC, dlist, index, tex)
    mov #0xC, r4                                 ! (delay) r4 = 0xC (display layer count)
    mov.b @r14, r0                               ! r0 = current car index
    cmp/eq #0x7, r0                              ! is it the special slot (7)?
    bf      .L_confirm_normal                    ! no -> normal confirm path
    mov.l   _pool_game_state_val, r3             ! r3 -> &game_state_dispatch (sym_0605AD10)
    mov.l r13, @r3                               ! game_state_dispatch = 7
    bra     .L_epilogue                          ! done -> epilogue
    nop                                          ! (delay)
.L_confirm_normal:
    exts.b r13, r13                              ! sign-extend 7 for byte store
    exts.b r10, r2                               ! sign-extend 1 (dirty flag) for byte store
    mov #0x0, r3                                 ! r3 = 0 (clear value)
    mov.b r13, @r14                              ! car_index = 7 (set to special slot)
    mov.b r2, @r12                               ! input_dirty_flag = 1
    mov.l   _pool_anim_state, r2                 ! r2 -> &animation_state (sym_06059F44)
    mov.l r3, @r2                                ! animation_state = 0 (clear)
    mov.l   _pool_camera_finalize, r3            ! r3 -> camera_finalize (sym_06026CE0)
    jsr @r3                                      ! call camera_finalize()
    nop                                          ! (delay)
    bra     .L_epilogue                          ! done -> epilogue
    nop                                          ! (delay)
.L_no_confirm:
    mov.w @(2, r4), r0                           ! r0 = newly pressed buttons (re-read)
    mov.w   _wpool_dpad_right_mask, r3           ! r3 = 0x2000 (D-pad right mask)
    mov r0, r2                                   ! r2 = button state copy
    extu.w r2, r2                                ! zero-extend to 32-bit
    and r3, r2                                   ! isolate D-pad right bit
    tst r2, r2                                   ! right pressed?
    bt      .L_no_right                          ! no -> check left
    mov r9, r6                                   ! r6 = 0x0090 (texture param base)
    mov.b @r14, r5                               ! r5 = current car index
    mov.l   _pool_car_display_data, r7           ! r7 -> &car display data ptr
    shll r5                                      ! r5 = car_index * 2
    mov.l @r7, r7                                ! r7 = car_display_data (indirect)
    add r11, r5                                  ! r5 -> &car_slot_params[car_index]
    mov.l r5, @r15                               ! [sp+0] = param entry ptr (saved)
    mov.b @(1, r5), r0                           ! r0 = color_index
    mov.l @r15, r3                               ! r3 = param entry ptr (reload)
    mov r0, r5                                   ! r5 = color_index
    mov.b @r3, r3                                ! r3 = model_variant
    extu.b r5, r5                                ! zero-extend color_index
    extu.b r3, r3                                ! zero-extend model_variant
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4 (total: * 64)
    add r3, r5                                   ! r5 = color_block + variant
    shll r5                                      ! r5 *= 2 (display index)
    jsr @r8                                      ! call display_renderer(0xC, dlist, index, tex)
    mov #0xC, r4                                 ! (delay) r4 = 0xC
    mov.b @r14, r2                               ! r2 = current car index
    add #0x1, r2                                 ! r2 = car_index + 1 (next car)
    mov.b r2, @r14                               ! car_index = next
    mov.b @r14, r3                               ! r3 = updated car index (re-read, sign-ext)
    mov #0x8, r2                                 ! r2 = 8 (total car count)
    cmp/ge r2, r3                                ! car_index >= 8?
    bf      .L_right_no_wrap                     ! no -> skip wrap
    mov #0x0, r2                                 ! r2 = 0 (wrap around)
    mov.b r2, @r14                               ! car_index = 0
.L_right_no_wrap:
    bra     .L_epilogue                          ! done -> epilogue
    mov.b r10, @r12                              ! (delay) input_dirty_flag = 1
_wpool_dpad_updown_mask:
    .2byte  0x0090
_wpool_dpad_right_mask:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_dirty_flag_ptr:
    .4byte  sym_06085FF1
_pool_car_index_ptr:
    .4byte  sym_06085FF0
_pool_lock_flag_ptr:
    .4byte  sym_06085FF3
_pool_input_state_ptr:
    .4byte  g_pad_state
_pool_display_renderer:
    .4byte  sym_060284AE
_pool_car_slot_params:
    .4byte  sym_06049AFC
_pool_car_display_data:
    .4byte  sym_0605D4F0
_pool_game_state_val:
    .4byte  sym_0605AD10
_pool_anim_state:
    .4byte  sym_06059F44
_pool_camera_finalize:
    .4byte  sym_06026CE0
.L_no_right:
    mov.w @(2, r4), r0                           ! r0 = newly pressed buttons (re-read)
    .byte   0x93, 0x53    /* mov.w _wpool_dpad_left_mask, r3 — D-pad left mask */
    mov r0, r2                                   ! r2 = button state copy
    extu.w r2, r2                                ! zero-extend to 32-bit
    and r3, r2                                   ! isolate D-pad left bit
    tst r2, r2                                   ! left pressed?
    bt      .L_epilogue                          ! no -> epilogue (no input)
    .byte   0xD7, 0x28    /* mov.l _pool_car_display_data_far, r7 — car display data ptr */
    mov r9, r6                                   ! r6 = 0x0090 (texture param base)
    mov.b @r14, r5                               ! r5 = current car index
    mov.l @r7, r7                                ! r7 = car_display_data (indirect)
    shll r5                                      ! r5 = car_index * 2
    add r11, r5                                  ! r5 -> &car_slot_params[car_index]
    mov.l r5, @r15                               ! [sp+0] = param entry ptr (saved)
    mov.b @(1, r5), r0                           ! r0 = color_index
    mov.l @r15, r3                               ! r3 = param entry ptr (reload)
    mov r0, r5                                   ! r5 = color_index
    mov.b @r3, r3                                ! r3 = model_variant
    extu.b r5, r5                                ! zero-extend color_index
    extu.b r3, r3                                ! zero-extend model_variant
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4
    shll2 r5                                     ! r5 *= 4 (total: * 64)
    add r3, r5                                   ! r5 = color_block + variant
    shll r5                                      ! r5 *= 2 (display index)
    jsr @r8                                      ! call display_renderer(0xC, dlist, index, tex)
    mov #0xC, r4                                 ! (delay) r4 = 0xC
    mov.b @r14, r2                               ! r2 = current car index
    add #-0x1, r2                                ! r2 = car_index - 1 (prev car)
    mov.b r2, @r14                               ! car_index = prev
    mov.b @r14, r3                               ! r3 = updated car index (re-read, sign-ext)
    cmp/pz r3                                    ! car_index >= 0?
    bt      .L_left_no_wrap                      ! yes -> skip wrap
    exts.b r13, r13                              ! sign-extend 7 for byte store
    mov.b r13, @r14                              ! car_index = 7 (wrap to last)
.L_left_no_wrap:
    exts.b r10, r3                               ! sign-extend 1 (dirty flag) for byte store
    mov.b r3, @r12                               ! input_dirty_flag = 1
.L_epilogue:
    .byte   0xD4, 0x1A    /* mov.l _pool_frame_counter_a, r4 — frame counter A ptr */
    mov.b @r4, r2                                ! r2 = frame_counter_a value
    add #0x1, r2                                 ! r2 = frame_counter_a + 1
    mov.b r2, @r4                                ! frame_counter_a++
    .byte   0xD4, 0x19    /* mov.l _pool_frame_counter_b, r4 — frame counter B ptr */
    mov.b @r4, r3                                ! r3 = frame_counter_b value
    add #0x1, r3                                 ! r3 = frame_counter_b + 1
    mov.b r3, @r4                                ! frame_counter_b++
    mov.b @r14, r2                               ! r2 = current car index
    shll2 r2                                     ! r2 = car_index * 4 (dispatch table stride)
    .byte   0xD3, 0x17    /* mov.l _pool_dispatch_table, r3 — car dispatch table ptr */
    add r3, r2                                   ! r2 -> &dispatch_table[car_index]
    mov.l @r2, r2                                ! r2 = dispatch_table[car_index] (fn ptr)
    add #0x4, r15                                ! deallocate stack frame
    lds.l @r15+, pr                              ! restore return address
    mov.l @r15+, r8                              ! restore r8
    mov.l @r15+, r9                              ! restore r9
    mov.l @r15+, r10                             ! restore r10
    mov.l @r15+, r11                             ! restore r11
    mov.l @r15+, r12                             ! restore r12
    mov.l @r15+, r13                             ! restore r13
    jmp @r2                                      ! tail-call dispatch_table[car_index]
    mov.l @r15+, r14                             ! (delay) restore r14
