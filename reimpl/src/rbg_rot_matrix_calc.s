/* rbg_rot_matrix_calc -- RBG rotation scroll state update
 *
 * Part of the per-frame render pipeline dispatch chain (jsr @r13 pattern).
 * Two logical phases:
 *
 *   Phase 1: Copy car struct field from offset +0x30 to +0x20 (previous
 *            position snapshot), then read the value at offset +0x08 and
 *            compare against a threshold of 150.  The branch is always
 *            taken (bt to its own address, then unconditional bra).
 *
 *   Phase 2: Check the RBG coefficient pointer (sym_06082A2C) against 40.
 *            If above threshold, skip to the external continuation at
 *            0x0602E438.  Otherwise inspect display flags bit 2
 *            (sym_06082A25 & 0x04); if set, clear render_state_byte
 *            (sym_06082A26) and branch out.  If clear, load the next
 *            dispatch function pointer into r13 and fall through.
 *
 * The large opaque data block between the two phases (0x0602E39E-0x0602E3F3)
 * contains interleaved code belonging to draw_priority_resolve and its
 * continuation, plus pool constants used by that code path.  These bytes
 * are NOT referenced by rbg_rot_matrix_calc and must not be modified.
 *
 * Translation unit: 0x0602E350 - 0x0602E42E
 */

    .section .text.FUN_0602E350


    .global rbg_rot_matrix_calc
    .type rbg_rot_matrix_calc, @function
rbg_rot_matrix_calc:
    sts.l pr, @-r15                         ! save return address
    jsr @r13                                ! call chained dispatch function (set by prior TU)
    nop                                     ! (delay slot)
    lds.l @r15+, pr                         ! restore return address
    mov.l   _pool_car_struct_ptr, r0        ! r0 = &current_car_ptr (sym_0607E940)
    mov.l @r0, r0                           ! r0 = current car struct base address
    mov.w   _wpool_src_field_off, r1        ! r1 = 0x0030 (source field offset in car struct)
    mov.l @(r0, r1), r3                     ! r3 = car_struct[0x30] (source position field)
    mov.w   DAT_0602e376, r1                ! r1 = 0x0020 (dest field offset in car struct)
    mov.l r3, @(r0, r1)                     ! car_struct[0x20] = r3 (copy position snapshot)
    mov.w   _wpool_cmp_field_off, r1        ! r1 = 0x0008 (comparison field offset)
    mov.l @(r0, r1), r3                     ! r3 = car_struct[0x08] (state/counter field)
    mov.l   _pool_state_threshold, r4       ! r4 = 150 (threshold constant)
    cmp/gt r3, r4                           ! T = (150 > car_struct[0x08]) ?
    bt      .L_always_branch                ! branch if threshold not reached (always falls through)
.L_always_branch:
    bra     .L_phase2_rbg_check             ! unconditional jump to phase 2
    nop                                     ! (delay slot)

    .global DAT_0602e372
DAT_0602e372:
    clrmac                                  ! data: 0x0028 (also encodes clrmac opcode)
_wpool_src_field_off:
    .2byte  0x0030                          ! word pool: car struct source field offset (+0x30)

    .global DAT_0602e376
DAT_0602e376:
    .2byte  0x0020                          ! word pool: car struct dest field offset (+0x20)
_wpool_cmp_field_off:
    .2byte  0x0008                          ! word pool: car struct comparison field offset (+0x08)
    .2byte  0x0000                          ! padding
    .4byte  sound_cmd_dispatch              ! adjacent pool: sound_cmd_dispatch (used by nearby TU)
_pool_car_struct_ptr:
    .4byte  sym_0607E940                    ! pool: &current_car_ptr (active car struct pointer)
    .4byte  sym_0602E450                    ! adjacent pool: rot_scroll_commit sub-entry
    .4byte  sym_0602E4BC                    ! adjacent pool: rot_scroll_interp sub-entry
    .4byte  collision_detect_main           ! adjacent pool: collision_detect_main
    .4byte  0x00000000                      ! adjacent pool: null terminator / zero
    .4byte  sym_0603053C                    ! adjacent pool: engine_sound_body sub-entry
    .4byte  checkpoint_detect               ! adjacent pool: checkpoint_detect
_pool_state_threshold:
    .4byte  0x00000096                      ! pool: threshold 150 for state comparison
    /* --- opaque interleaved code block (0x0602E3A0-0x0602E3F3) ---
     * Used by draw_priority_resolve continuation.  Do NOT modify.
     */
    .4byte  0xD10BD30C                      ! interleaved code (draw_priority_resolve path)
    .4byte  0x2132D10C                      ! interleaved code
    .4byte  0x6212D10C                      ! interleaved code
    .4byte  0x2122D10C                      ! interleaved code
    .4byte  0xD20C2122                      ! interleaved code
    .4byte  0xD10C9308                      ! interleaved code
    .4byte  0x2132D30C                      ! interleaved code
    .4byte  0xD10C0136                      ! interleaved code
    .4byte  0x93039103                      ! interleaved code
    .4byte  0x0136AF19                      ! interleaved code
    .4byte  0x00090000                      ! interleaved code/data
    .4byte  0x01B40000                      ! interleaved code/data
    .4byte  sym_0605A1D0                    ! interleaved pool: depth scale factor (16.16)
    .4byte  0x00010000                      ! interleaved pool: fixed-point 1.0 (16.16)
    .4byte  sym_06082A34                    ! interleaved pool: &render_scratch (scene param)
    .4byte  sym_06063E20                    ! interleaved pool: &game_state_flag (1 = active race)
    .4byte  sym_06082A30                    ! interleaved pool: &render_mode (VDP1 state)
    .4byte  0x00000000                      ! interleaved pool: zero constant
    .4byte  sym_0605A1C4                    ! interleaved pool: &race_complete_flag (32-bit)
    .4byte  0x00000001                      ! interleaved pool: constant 1
    .4byte  sym_0607EAC8                    ! interleaved pool: &pipeline_scratch (per-frame)
.L_phase2_rbg_check:
    mov.l   _pool_rbg_coeff_ptr, r1         ! r1 = &rbg_coeff_ptr (sym_06082A2C)
    mov.l @r1, r3                           ! r3 = current RBG coefficient pointer value
    mov.l   _pool_rbg_threshold, r4         ! r4 = 40 (0x28) threshold for coeff ptr
    cmp/gt r3, r4                           ! T = (40 > rbg_coeff_ptr) ?
    .byte   0x89, 0x1C    /* bt 0x0602E438 (external) */  ! if under threshold, skip to continuation
    mov.l   _pool_display_flags_ptr, r2     ! r2 = &display_flags (sym_06082A25)
    mov.b @r2, r2                           ! r2 = display_flags byte value
    mov.l   _pool_flag_bit2_mask, r1        ! r1 = 0x04 (bit 2 mask)
    and r1, r2                              ! r2 = display_flags & 0x04
    tst r2, r2                              ! T = (bit 2 is clear) ?
    bt      .L_load_next_dispatch           ! if bit 2 clear, load next function pointer
    mov.l   _pool_render_state_ptr, r0      ! r0 = &render_state_byte (sym_06082A26)
    mov.l   _pool_zero_value, r1            ! r1 = 0 (clear value)
    mov.b r1, @r0                           ! render_state_byte = 0 (reset render state)
    .byte   0xA0, 0x12    /* bra 0x0602E438 (external) */  ! branch to external continuation
    nop                                     ! (delay slot)
_pool_rbg_coeff_ptr:
    .4byte  sym_06082A2C                    ! pool: &rbg_coeff_ptr (RBG coefficient pointer)
_pool_rbg_threshold:
    .4byte  0x00000028                      ! pool: threshold 40 for RBG coeff comparison
_pool_display_flags_ptr:
    .4byte  sym_06082A25                    ! pool: &display_flags (byte — camera/display flags)
_pool_flag_bit2_mask:
    .4byte  0x00000004                      ! pool: bit 2 mask (display flag check)
_pool_render_state_ptr:
    .4byte  sym_06082A26                    ! pool: &render_state_byte (sprite mode selector)
_pool_zero_value:
    .4byte  0x00000000                      ! pool: zero constant (clear value)
.L_load_next_dispatch:
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E44C, r13 */  ! r13 = next dispatch function ptr
