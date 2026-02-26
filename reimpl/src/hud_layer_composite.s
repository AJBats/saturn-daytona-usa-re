/* hud_layer_composite -- HUD layer position interpolation and rendering
 * Translation unit: 0x060114B8 - 0x0601155E
 *
 * Smoothly interpolates a HUD layer's current position toward a target
 * using exponential easing (halving the delta each frame), then renders
 * the layer by dispatching to sprite_3d_render and vertex_transform_rot.
 *
 * Called from anim_ui_transition, which saves r14/r13/r12/r11 and
 * passes the layer index in r13 (and r0 = extu.w of layer index).
 *
 * Inputs (set by caller anim_ui_transition):
 *   r0  = layer_index (16-bit, zero-extended)
 *   r13 = layer_index (original r4 from caller, preserved callee-saved)
 *   r14/r13/r12/r11 already pushed by anim_ui_transition
 *
 * Data references:
 *   sym_060447A8 = target position table (8 x 32-bit entries, indexed by
 *                  layer_index * 16 + frame_counter * 4)
 *   sym_06078860 = current interpolated position (32-bit dword)
 *   sym_0607EADC = frame counter (32-bit, used as secondary index)
 *   sym_0607887F = game state byte (0x3 = racing, 0xB = replay)
 *   sym_0607EBC8 = mode configuration flags (bit 0 = HUD suppress)
 *   sym_060447A4 = layer attribute data (read via cross-TU pool)
 *   sym_06044764 = layer X-offset table (8 x 32-bit signed values)
 *   sym_06044784 = layer Y-offset table (8 x 32-bit signed values)
 *
 * Cross-TU pool references (in sprite_batch_renderer data area):
 *   .L_pool_060115C8 = sym_060447A4 (layer attribute data)
 *   .L_pool_060115CC = 0x00010000 (fixed-point 1.0 or stride constant)
 *   .L_pool_060115D0 = sym_060447A8 (same as local pool, for second pass)
 *   .L_pool_060115D4 = sym_06044764 (layer X-offset table)
 *   .L_pool_060115D8 = sym_06044784 (layer Y-offset table)
 *   .L_wpool_060115C6 = 0x8000 (signed ceiling / half-screen constant)
 */

    .section .text.FUN_060114B8


    .global hud_layer_composite
    .type hud_layer_composite, @function

/* ============================================================
 * hud_layer_composite
 *
 * Interpolates the current HUD layer position halfway toward
 * its target each frame (exponential ease-out), then renders
 * the layer via sprite_3d_render + vertex_transform_rot.
 *
 * If the game state is racing (0x3) or replay (0xB) AND the
 * mode suppress flag (bit 0 of mode_config_flags) is set,
 * the function skips rendering and returns early.
 * ============================================================ */
hud_layer_composite:
    sts.l pr, @-r15                         ! save return address
    shll2 r0                                ! r0 = layer_index * 4
    mov.l   .L_ptr_current_pos, r14         ! r14 = &current_position (sym_06078860)
    mov.l   .L_ptr_target_table, r3         ! r3 = target_position_table (sym_060447A8)
    mov.l   .L_ptr_frame_counter, r2        ! r2 = &frame_counter (sym_0607EADC)
    shll2 r0                                ! r0 = layer_index * 16 (stride into target table)
    mov.l @r2, r2                           ! r2 = frame_counter value
    add r3, r0                              ! r0 = &target_table[layer_index * 16]
    shll2 r2                                ! r2 = frame_counter * 4 (dword offset)
    mov.l @(r0, r2), r1                     ! r1 = target_position = table[layer*16 + frame*4]
    mov.l @r14, r2                          ! r2 = current_position
    mov #0x0, r0                            ! r0 = 0 (for carry/rounding calculation)
    sub r2, r1                              ! r1 = delta = target - current
    cmp/gt r1, r0                           ! T = (0 > delta), i.e. T=1 if delta is negative
    addc r0, r1                             ! r1 = delta + T (rounds negative deltas toward zero)
    shar r1                                 ! r1 = delta / 2 (arithmetic shift, preserves sign)
    add r1, r2                              ! r2 = current + delta/2 (interpolated position)
    mov.l r2, @r14                          ! store updated current position
    mov.l   .L_ptr_game_state, r4           ! r4 = &game_state_byte (sym_0607887F)
    mov.b @r4, r4                           ! r4 = game_state_byte (signed load)
    extu.b r4, r4                           ! r4 = game_state (zero-extended)
    mov r4, r0                              ! r0 = game_state (for cmp/eq)
    cmp/eq #0x3, r0                         ! T = (game_state == 3, racing mode)
    bt      .L_check_suppress_flag          ! if racing, check suppress flag
    mov r4, r0                              ! r0 = game_state (retry for second compare)
    cmp/eq #0xB, r0                         ! T = (game_state == 0xB, replay mode)
    bf      .L_do_render                    ! if not racing or replay, always render
.L_check_suppress_flag:
    mov.l   .L_ptr_mode_config_flags, r0    ! r0 = &mode_config_flags (sym_0607EBC8)
    mov.l @r0, r0                           ! r0 = mode_config_flags
    tst #0x1, r0                            ! T = !(flags & 1), test suppress bit
    bt      .L_do_render                    ! if suppress bit clear, proceed to render
    bra     .L_early_return                 ! suppress bit set: skip rendering
    nop                                     ! delay slot (no-op)
    .2byte  0xFFFF                          ! alignment padding
.L_ptr_target_table:
    .4byte  sym_060447A8                    /* target position table (8 dwords) */
.L_ptr_frame_counter:
    .4byte  sym_0607EADC                    /* frame counter (dword) */
.L_ptr_current_pos:
    .4byte  sym_06078860                    /* current interpolated position (dword) */
.L_ptr_game_state:
    .4byte  sym_0607887F                    /* game state byte (0x3=race, 0xB=replay) */
.L_ptr_mode_config_flags:
    .4byte  sym_0607EBC8                    /* mode config flags (bit 0 = suppress HUD) */

/* ============================================================
 * .L_do_render
 *
 * Computes layer rendering parameters from the layer index (r13)
 * and dispatches to sprite_3d_render for the first pass, then
 * vertex_transform_rot for two additional passes. The second
 * vertex_transform_rot call is a tail-call (bra, restoring
 * callee-saved regs before jump).
 *
 * Register usage:
 *   r13 = layer_index (from caller, callee-saved)
 *   r14 = &current_position (set above)
 *   r12 = &layer_attribute_data[layer_index * 2] (word array)
 *   r11 = &target_table[layer_index * 44 + 12] (dword within struct)
 * ============================================================ */
.L_do_render:
    extu.w r13, r12                         ! r12 = layer_index (16-bit clean)
    extu.w r13, r11                         ! r11 = layer_index (16-bit clean)
    .byte   0xD3, 0x2C    /* mov.l .L_pool_060115C8, r3 */  ! r3 = layer_attribute_data (sym_060447A4)
    shll r12                                ! r12 = layer_index * 2 (word stride)
    shll2 r11                               ! r11 = layer_index * 4
    add r3, r12                             ! r12 = &layer_attrib[layer_index] (word ptr)
    shll2 r11                               ! r11 = layer_index * 16
    mov.w @r12, r2                          ! r2 = layer_attribute word
    mov.l r2, @-r15                         ! push layer_attribute onto stack
    .byte   0xD7, 0x2A    /* mov.l .L_pool_060115CC, r7 */  ! r7 = 0x00010000 (stride / scale constant)
    .byte   0x96, 0x4F    /* mov.w .L_wpool_060115C6, r6 */ ! r6 = 0x8000 (half-screen constant)
    .byte   0xD2, 0x2A    /* mov.l .L_pool_060115D0, r2 */  ! r2 = target_table base (sym_060447A8)
    add r2, r11                             ! r11 = &target_table[layer_index * 16]
    add #0xC, r11                           ! r11 = &target_table[layer_index * 16 + 12]
    mov.l @r11, r5                          ! r5 = target_table entry (param for render call)
    .byte   0xB0, 0xBB    /* bsr 0x060116A8 (external) */   ! call sprite_3d_render(current_pos, param, ...)
    mov.l @r14, r4                          ! r4 = current_position [delay slot]
    add #0x4, r15                           ! pop layer_attribute from stack
    mov.w @r12, r7                          ! r7 = layer_attribute word (reload)
    mov.l @r11, r6                          ! r6 = target_table entry (reload)
    .byte   0xD4, 0x26    /* mov.l .L_pool_060115D4, r4 */  ! r4 = X-offset table (sym_06044764)
    .byte   0xB2, 0x1D    /* bsr 0x06011978 (external) */   ! call vertex_transform_rot(x_table, cur_pos, ...)
    mov.l @r14, r5                          ! r5 = current_position [delay slot]
    mov.w @r12, r7                          ! r7 = layer_attribute word (reload)
    mov.l @r11, r6                          ! r6 = target_table entry (reload)
    mov.l @r14, r5                          ! r5 = current_position (for tail call)
    .byte   0xD4, 0x24    /* mov.l .L_pool_060115D8, r4 */  ! r4 = Y-offset table (sym_06044784)
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    .byte   0xA2, 0x13    /* bra 0x06011978 (external) */   ! tail-call vertex_transform_rot(y_table, cur_pos, ...)
    mov.l @r15+, r14                        ! restore r14 [delay slot]

/* ============================================================
 * .L_early_return
 *
 * Early exit path: game state is racing/replay and the HUD
 * suppress flag is set. Restores callee-saved registers
 * (pushed by anim_ui_transition) and returns without rendering.
 * ============================================================ */
.L_early_return:
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! restore r14 [delay slot]
