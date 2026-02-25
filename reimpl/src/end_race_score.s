/* end_race_score -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06013E7A - 0x06013FC4
 *
 * Full 3D object render loop body — processes one trackside object per
 * iteration through the 29-entry animation array at sym_0605AD5C.
 * Falls through from obj_render_loop_3d (the setup/prolog TU).
 *
 * Per-iteration pipeline:
 *   1. Compute environment scale: fpmul(wind_dir * 1.0, 0x051E)
 *   2. Transform dispatch with base angle 0x8000 + env_scale, scale=1.0
 *   3. Apply Z rotation from entry[+24]
 *   4. Scale entry fields [+4], [+8], [+12] by wind_dir * 1.0
 *   5. Transform dispatch with computed angle/position args
 *   6. Reverse Z rotation (-entry[+24])
 *   7. Apply transform_matrix from entry[+26] * wind_dir
 *   8. Apply Y rotation from entry[+28] * wind_dir
 *   9. Apply Z rotation from entry[+30] * wind_dir
 *  10. Compute uniform scale: fpmul(entry[+16], wind_dir*1.0) + 0x4CCC
 *  11. mat_scale_columns(scale, scale, scale)
 *  12. Dispatch transform chain A (sym_06031D8C) from obj_table
 *  13. Dispatch transform chain B (sym_06031A28) from disp_table
 *  14. Decrement global render budget counter by 0x30
 *  15. Advance entry pointer by 0x20; loop or exit
 *
 * Persistent registers (set by obj_render_loop_3d prolog):
 *   r8  = table index offset (increments by 0x4 each iteration)
 *   r9  = mat_rot_z function pointer
 *   r10 = current entry pointer (increments by 0x20 each iteration)
 *   r11 = fpmul function pointer
 *   r13 = &wind_dir_word (sym_06084AF6, 16-bit)
 *   r14 = 0x00010000 (1.0 in 16.16 fixed-point)
 * Stack frame:
 *   [0]  = display table pointer (sym_06089E4A)
 *   [4]  = end-of-array pointer (loop bound)
 */

    .section .text.FUN_06013E7A


    .global end_race_score
    .type end_race_score, @function
end_race_score:
    mov.l r14, @-r15                     ! push 1.0 FP onto stack (popped later as r6 arg)
    mov.w   DAT_06013f48, r5             ! r5 = 0x051E (env scale factor arg)
    mov.w @r13, r4                       ! r4 = wind_dir_word (16-bit from sym_06084AF6)
    extu.w r4, r4                        ! zero-extend wind_dir to 32-bit
    mul.l r14, r4                        ! MACL = wind_dir * 1.0 (16.16 FP multiply)
    jsr @r11                             ! call fpmul(wind_dir_fp, 0x051E)
    sts macl, r4                         ! r4 = wind_dir * 1.0 (delay slot: fpmul arg)
    mov.w   DAT_06013f4a, r5             ! r5 = 0x8000 (base angle for transform)
    mov #0x0, r4                         ! r4 = 0 (transform mode)
    .byte   0xD3, 0x38    /* mov.l _pool_fn_transform_dispatch, r3 */
    add r0, r5                           ! r5 = 0x8000 + env_scale (adjusted base angle)
    jsr @r3                              ! call transform_dispatch(mode=0, angle, scale=1.0)
    mov.l @r15+, r6                      ! r6 = pop 1.0 FP (delay slot: scale arg)
    mov.w @(24, r12), r0                 ! r0 = entry[+24] (per-object Z rotation angle)
    jsr @r9                              ! call mat_rot_z(z_angle)
    mov r0, r4                           ! r4 = Z rotation angle (delay slot)
    mov.w @r13, r5                       ! r5 = wind_dir_word
    extu.w r5, r5                        ! zero-extend wind_dir
    mul.l r14, r5                        ! MACL = wind_dir * 1.0
    sts macl, r5                         ! r5 = wind_dir_fp (scale factor for fpmul)
    jsr @r11                             ! call fpmul(entry[+4], wind_dir_fp)
    mov.l @(4, r12), r4                  ! r4 = entry[+4] (position X) (delay slot)
    mov.l r0, @(12, r15)                 ! stack[12] = scaled_pos_x
    mov.w @r13, r5                       ! r5 = wind_dir_word
    extu.w r5, r5                        ! zero-extend wind_dir
    mul.l r14, r5                        ! MACL = wind_dir * 1.0
    sts macl, r5                         ! r5 = wind_dir_fp
    jsr @r11                             ! call fpmul(entry[+8], wind_dir_fp)
    mov.l @(8, r12), r4                  ! r4 = entry[+8] (position Y) (delay slot)
    mov.l @r12, r3                       ! r3 = entry[+0] (base angle / offset)
    sub r0, r3                           ! r3 = entry[+0] - scaled_pos_y
    mov.l r3, @(8, r15)                  ! stack[8] = adjusted_base_angle
    mov.w @r13, r5                       ! r5 = wind_dir_word
    extu.w r5, r5                        ! zero-extend wind_dir
    mul.l r14, r5                        ! MACL = wind_dir * 1.0
    sts macl, r5                         ! r5 = wind_dir_fp
    jsr @r11                             ! call fpmul(entry[+12], wind_dir_fp)
    mov.l @(12, r12), r4                 ! r4 = entry[+12] (position Z) (delay slot)
    mov r0, r6                           ! r6 = scaled_pos_z (3rd arg)
    mov.l @(8, r15), r5                  ! r5 = adjusted_base_angle (2nd arg)
    .byte   0xD3, 0x29    /* mov.l _pool_fn_transform_dispatch, r3 */
    jsr @r3                              ! call transform_dispatch(scaled_x, adj_angle, scaled_z)
    mov.l @(12, r15), r4                 ! r4 = scaled_pos_x (1st arg) (delay slot)
    mov.w @(24, r12), r0                 ! r0 = entry[+24] (Z rotation angle again)
    mov r0, r4                           ! r4 = Z rotation angle
    jsr @r9                              ! call mat_rot_z(-z_angle) (reverse rotation)
    neg r4, r4                           ! r4 = -z_angle (delay slot: negate for reverse)
    mov.w @(26, r12), r0                 ! r0 = entry[+26] (transform matrix angle)
    mov.w @r13, r3                       ! r3 = wind_dir_word
    mov r0, r4                           ! r4 = transform_angle
    extu.w r3, r3                        ! zero-extend wind_dir
    mul.l r3, r4                         ! MACL = wind_dir * transform_angle
    .byte   0xD3, 0x24    /* mov.l _pool_fn_transform_matrix, r3 */
    jsr @r3                              ! call transform_matrix(wind_dir * transform_angle)
    sts macl, r4                         ! r4 = scaled transform angle (delay slot)
    mov.w @(28, r12), r0                 ! r0 = entry[+28] (Y rotation angle)
    mov.w @r13, r3                       ! r3 = wind_dir_word
    mov r0, r4                           ! r4 = y_rot_angle
    extu.w r3, r3                        ! zero-extend wind_dir
    mul.l r3, r4                         ! MACL = wind_dir * y_rot_angle
    .byte   0xD3, 0x21    /* mov.l _pool_fn_mat_rot_y, r3 */
    jsr @r3                              ! call mat_rot_y(wind_dir * y_rot_angle)
    sts macl, r4                         ! r4 = scaled Y rotation angle (delay slot)
    mov.w @(30, r12), r0                 ! r0 = entry[+30] (final Z rotation angle)
    mov.w @r13, r3                       ! r3 = wind_dir_word
    mov r0, r4                           ! r4 = final_z_angle
    extu.w r3, r3                        ! zero-extend wind_dir
    mul.l r3, r4                         ! MACL = wind_dir * final_z_angle
    jsr @r9                              ! call mat_rot_z(wind_dir * final_z_angle)
    sts macl, r4                         ! r4 = scaled Z rotation angle (delay slot)
    mov.w @r13, r5                       ! r5 = wind_dir_word
    extu.w r5, r5                        ! zero-extend wind_dir
    mul.l r14, r5                        ! MACL = wind_dir * 1.0
    sts macl, r5                         ! r5 = wind_dir_fp
    jsr @r11                             ! call fpmul(entry[+16], wind_dir_fp)
    mov.l @(16, r12), r4                 ! r4 = entry[+16] (base scale) (delay slot)
    mov.w   DAT_06013f4c, r12            ! r12 = 0x4CCC (scale offset in 16.16 FP)
    .byte   0xD3, 0x19    /* mov.l _pool_fn_mat_scale_columns, r3 */
    add r0, r12                          ! r12 = fpmul_result + 0x4CCC (uniform scale)
    mov r12, r6                          ! r6 = scale_z arg
    mov r12, r5                          ! r5 = scale_y arg
    jsr @r3                              ! call mat_scale_columns(scale, scale, scale)
    mov r12, r4                          ! r4 = scale_x arg (delay slot)
    mov #0x4, r5                         ! r5 = 4 (entry count / stride arg)
    mov r8, r12                          ! r12 = table index offset (restore from r8)
    .byte   0xD4, 0x16    /* mov.l _pool_obj_table, r4 */
    .byte   0xD3, 0x17    /* mov.l _pool_fn_chain_a, r3 */
    add r8, r4                           ! r4 = &obj_table[index]
    jsr @r3                              ! call chain_a_dispatch(obj_table[index], 4)
    mov.l @r4, r4                        ! r4 = obj_table[index] value (delay slot)
    mov #0x1, r6                         ! r6 = 1 (display mode flag)
    mov.l @r15, r5                       ! r5 = display table pointer (from stack[0])
    .byte   0xD4, 0x15    /* mov.l _pool_disp_table, r4 */
    .byte   0xD3, 0x15    /* mov.l _pool_fn_chain_b, r3 */
    mov.w @r5, r5                        ! r5 = display mode (16-bit word from table)
    add r12, r4                          ! r4 = &disp_table[index]
    jsr @r3                              ! call chain_b_dispatch(disp_table[index], mode, 1)
    mov.l @r4, r4                        ! r4 = disp_table[index] value (delay slot)
    .byte   0xD2, 0x14    /* mov.l _pool_global_counter, r2 */
    mov.l @r2, r2                        ! r2 = current global render budget counter
    bra     .L_loop_tail                 ! branch to loop tail (counter update + check)
    nop                                  ! delay slot (nop)

    .global DAT_06013f46
DAT_06013f46:
    .word 0x03A0 /* UNKNOWN */

    .global DAT_06013f48
DAT_06013f48:
    .2byte  0x051E

    .global DAT_06013f4a
DAT_06013f4a:
    .2byte  0x8000

    .global DAT_06013f4c
DAT_06013f4c:
    .2byte  0x4CCC
    .2byte  0xFFFF
    .4byte  mat_rot_z
    .4byte  fpmul
    .4byte  sym_06084AF6
    .4byte  0x00010000
    .4byte  sym_06026E0C
    .4byte  sym_0605AD5C
    .4byte  sym_06089E4A
    .4byte  sym_06026DBC
_pool_fn_transform_dispatch:
    .4byte  sym_06026E2E
_pool_fn_transform_matrix:
    .4byte  transform_matrix
_pool_fn_mat_rot_y:
    .4byte  mat_rot_y
_pool_fn_mat_scale_columns:
    .4byte  mat_scale_columns
_pool_obj_table:
    .4byte  sym_06062338
_pool_fn_chain_a:
    .4byte  sym_06031D8C
_pool_disp_table:
    .4byte  sym_060622C0
_pool_fn_chain_b:
    .4byte  sym_06031A28
_pool_global_counter:
    .4byte  sym_06089EDC
.L_loop_tail:
    add #-0x30, r2                       ! r2 -= 0x30 (decrement render budget by 48)
    add #0x20, r10                       ! r10 += 0x20 (advance to next 32-byte entry)
    .byte   0xD3, 0x09    /* mov.l _pool_counter_store, r3 */
    mov.l r2, @r3                        ! store updated counter back to global_counter
    mov.l @(4, r15), r1                  ! r1 = end-of-array pointer (loop bound)
    cmp/hs r1, r10                       ! T = (entry_ptr >= end) ? 1 : 0
    bt/s    .L_epilog                    ! if past end, exit loop
    add #0x4, r8                         ! r8 += 4 (advance table index) (delay slot)
    .byte   0xAF, 0x65    /* bra 0x06013E72 (external) */
    nop                                  ! delay slot (bra back to loop top in obj_render_loop_3d)
.L_epilog:
    add #0x10, r15                       ! deallocate 16 bytes of stack locals
    lds.l @r15+, macl                    ! restore MACL
    lds.l @r15+, pr                      ! restore return address
    mov.l @r15+, r8                      ! restore r8
    mov.l @r15+, r9                      ! restore r9
    mov.l @r15+, r10                     ! restore r10
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return to caller
    mov.l @r15+, r14                     ! restore r14 (delay slot)
    .2byte  0xFFFF
_pool_counter_store:
    .4byte  sym_06089EDC
