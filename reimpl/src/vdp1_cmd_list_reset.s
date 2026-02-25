/* vdp1_cmd_list_reset -- VDP1 command list pipeline reset
 * Translation unit: 0x0602DB22 - 0x0602DC24
 *
 * Resets the VDP1 rendering pipeline state at the start of a new frame.
 * Called from the per-car rendering pipeline to reinitialize command list
 * state before building new display commands.
 *
 * Reset sequence:
 *   1. Call sub-function via r13 (display init / parameter refresh)
 *   2. Clear render state variables:
 *      - render_mode        (sym_06082A30) = 0
 *      - render_state_byte  (sym_06082A26) = 0
 *      - collision_state    (sym_060788FC) = 0
 *      - cmd_slot_counter   (sym_06082A38) = 0
 *   3. Dereference car struct pointer (sym_0607E940) into r0
 *   4. Write 0xC8 to pipeline scratch word (sym_0607EAC8)
 *   5. Zero-fill ~10 car struct fields at various offsets
 *      (animation state, physics scratch, collision data)
 *   6. Copy car[0x025C] to car[0x0030] and car[0x0028]
 *   7. Compute frame time: dmuls 0x00FA0000 * 0x038E, xtrct → 16.16 result
 *   8. If car[0x0008] > 0xFA, store frame time to car[0x000C]
 *   9. Always store frame time to car[0x0194]
 *  10. Write race_complete_flag = 2, copy camera_state_a to render_scratch,
 *      write game_state = 2
 *  11. Branch to next TU (VDP1 normal sprite pipeline at 0x0602DC26)
 *
 * Second entry: pipeline_reg_save (sym_0602DC18)
 *   Saves callee-saved registers r8-r13 onto the stack. Used as the
 *   prologue for car_update_racing's rendering sub-pipeline.
 */

    .section .text.FUN_0602DB22


    .global vdp1_cmd_list_reset
    .type vdp1_cmd_list_reset, @function
vdp1_cmd_list_reset:
    sts.l pr, @-r15                              ! save PR for sub-call
    jsr @r13                                     ! call display init (passed in r13)
    nop                                          ! (delay slot)
    lds.l @r15+, pr                              ! restore PR
    .byte   0xD4, 0x2A    /* mov.l _pool_render_mode, r4 */
    .byte   0xD1, 0x26    /* mov.l _pool_zero, r1 */
    mov.l r1, @r4                                ! render_mode = 0 (clear VDP1 state)
    .byte   0xD4, 0x29    /* mov.l _pool_render_state_byte, r4 */
    mov.b r1, @r4                                ! render_state_byte = 0
    .byte   0xD4, 0x29    /* mov.l _pool_collision_state, r4 */
    mov.l r1, @r4                                ! collision_state = 0
    .byte   0xD4, 0x29    /* mov.l _pool_cmd_slot_counter, r4 */
    mov.l r1, @r4                                ! cmd_slot_counter = 0
    .byte   0xD0, 0x29    /* mov.l _pool_car_struct_ptr, r0 */
    mov.l @r0, r0                                ! r0 = *car_struct_ptr (base addr of active car)
    .byte   0xD3, 0x29    /* mov.l _pool_scratch_init_val, r3 */
    .byte   0xD1, 0x2A    /* mov.l _pool_pipeline_scratch, r1 */
    mov.l r3, @r1                                ! pipeline_scratch = 0xC8 (init sentinel)
    .byte   0xD3, 0x20    /* mov.l _pool_zero, r3 */
    mov.w   DAT_0602dbac, r1                     ! r1 = 0x0114 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0114] = 0 (clear anim state A)
    mov.w   DAT_0602dbae, r1                     ! r1 = 0x00D0 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x00D0] = 0 (clear physics scratch)
    mov.w   DAT_0602dbb0, r1                     ! r1 = 0x0040 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0040] = 0 (clear velocity scratch)
    mov.w   DAT_0602dbb2, r1                     ! r1 = 0x0244 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0244] = 0 (clear collision scratch)
    .byte   0xD1, 0x25    /* mov.l _pool_rbg_coeff_ptr, r1 */
    mov.l r3, @r1                                ! rbg_coeff_ptr = 0 (clear RBG state)
    mov.w   DAT_0602dbb4, r1                     ! r1 = 0x0058 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0058] = 0 (clear render param A)
    mov.w   DAT_0602dbb6, r1                     ! r1 = 0x005C (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x005C] = 0 (clear render param B)
    mov.w   DAT_0602dbb8, r1                     ! r1 = 0x025C (car struct offset)
    mov.l @(r0, r1), r3                          ! r3 = car[0x025C] (read saved state field)
    mov.w   DAT_0602dbba, r1                     ! r1 = 0x0030 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0030] = car[0x025C] (copy saved state)
    mov.w   DAT_0602dbbc, r1                     ! r1 = 0x0028 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0028] = car[0x025C] (duplicate)
    .byte   0xD3, 0x15    /* mov.l _pool_zero, r3 */
    mov.w   DAT_0602dbbe, r1                     ! r1 = 0x0148 (car struct offset)
    mov.l r3, @(r0, r1)                          ! car[0x0148] = 0 (clear frame counter)
    .byte   0xD5, 0x1F    /* mov.l _pool_fixpt_250, r5 */
    .byte   0xD6, 0x1F    /* mov.l _pool_frame_divisor, r6 */
    dmuls.l r5, r6                               ! MACH:MACL = 0x00FA0000 * 0x038E (frame time calc)
    sts mach, r5                                 ! r5 = high 32 bits of product
    sts macl, r6                                 ! r6 = low 32 bits of product
    xtrct r5, r6                                 ! r6 = middle 32 bits (16.16 fixed-point result)
    mov.w   DAT_0602dbc0, r1                     ! r1 = 0x0008 (car struct offset)
    mov.l @(r0, r1), r3                          ! r3 = car[0x0008] (current frame counter)
    .byte   0xD4, 0x1D    /* mov.l _pool_frame_threshold, r4 */
    cmp/gt r3, r4                                ! 0xFA > car[0x0008]?
    bt      .L_skip_frametime_store              ! if threshold > counter, skip conditional store
    .byte   0xD1, 0x1C    /* mov.l _pool_off_frame_time, r1 */
    mov.l r6, @(r0, r1)                          ! car[0x000C] = frame_time (only if counter >= 0xFA)
.L_skip_frametime_store:
    .byte   0xD1, 0x1C    /* mov.l _pool_off_frame_time_b, r1 */
    mov.l r6, @(r0, r1)                          ! car[0x0194] = frame_time (always stored)
    .byte   0xD1, 0x1C    /* mov.l _pool_race_complete_flag, r1 */
    mov.w   DAT_0602dbc2, r2                     ! r2 = 0x0002 (state value 2)
    mov.l r2, @r1                                ! race_complete_flag = 2
    .byte   0xD1, 0x1C    /* mov.l _pool_camera_state_a, r1 */
    mov.l @r1, r2                                ! r2 = camera_state_a
    .byte   0xD1, 0x1C    /* mov.l _pool_render_scratch, r1 */
    mov.l r2, @r1                                ! render_scratch = camera_state_a (latch)
    .byte   0xD1, 0x1C    /* mov.l _pool_game_state, r1 */
    mov.w   DAT_0602dbc2, r2                     ! r2 = 0x0002 (state value 2)
    mov.l r2, @r1                                ! game_state = 2
    .byte   0xA0, 0x3D    /* bra 0x0602DC26 (external) */
    nop                                          ! (delay slot) branch to VDP1 normal sprite pipeline

    .global DAT_0602dbac
DAT_0602dbac:
    .2byte  0x0114                               ! car struct offset: anim state A

    .global DAT_0602dbae
DAT_0602dbae:
    .2byte  0x00D0                               ! car struct offset: physics scratch

    .global DAT_0602dbb0
DAT_0602dbb0:
    .2byte  0x0040                               ! car struct offset: velocity scratch

    .global DAT_0602dbb2
DAT_0602dbb2:
    .2byte  0x0244                               ! car struct offset: collision scratch

    .global DAT_0602dbb4
DAT_0602dbb4:
    .2byte  0x0058                               ! car struct offset: render param A

    .global DAT_0602dbb6
DAT_0602dbb6:
    .2byte  0x005C                               ! car struct offset: render param B

    .global DAT_0602dbb8
DAT_0602dbb8:
    .2byte  0x025C                               ! car struct offset: saved state field (source)

    .global DAT_0602dbba
DAT_0602dbba:
    .2byte  0x0030                               ! car struct offset: saved state copy dest A

    .global DAT_0602dbbc
DAT_0602dbbc:
    .2byte  0x0028                               ! car struct offset: saved state copy dest B

    .global DAT_0602dbbe
DAT_0602dbbe:
    .2byte  0x0148                               ! car struct offset: frame counter

    .global DAT_0602dbc0
DAT_0602dbc0:
    .2byte  0x0008                               ! car struct offset: current frame counter

    .global DAT_0602dbc2
DAT_0602dbc2:
    .2byte  0x0002                               ! constant: state value 2
    .4byte  0x00000002                           ! pool: constant 0x2 (unreferenced alignment)
_pool_zero:
    .4byte  0x00000000                           ! pool: zero constant (used for clearing)
    .4byte  sound_cmd_dispatch                   ! pool: sound_cmd_dispatch (unreferenced by this TU)
    .4byte  0x00000003                           ! pool: constant 0x3 (unreferenced by this TU)
_pool_render_mode:
    .4byte  sym_06082A30                         ! pool: &render_mode (VDP1 render state flag)
_pool_render_state_byte:
    .4byte  sym_06082A26                         ! pool: &render_state_byte (sprite mode selector)
_pool_collision_state:
    .4byte  sym_060788FC                         ! pool: &collision_state (collision detection flag)
_pool_cmd_slot_counter:
    .4byte  sym_06082A38                         ! pool: &cmd_slot_counter (VDP1 command index)
_pool_car_struct_ptr:
    .4byte  sym_0607E940                         ! pool: &car_struct_ptr (active car base pointer)
_pool_scratch_init_val:
    .4byte  0x000000C8                           ! pool: 0xC8 (200 — pipeline scratch init value)
_pool_pipeline_scratch:
    .4byte  sym_0607EAC8                         ! pool: &pipeline_scratch (per-frame scratch word)
_pool_rbg_coeff_ptr:
    .4byte  sym_06082A2C                         ! pool: &rbg_coeff_ptr (RBG coefficient pointer)
_pool_fixpt_250:
    .4byte  0x00FA0000                           ! pool: 250.0 in 16.16 fixed-point
_pool_frame_divisor:
    .4byte  0x0000038E                           ! pool: 910 (frame period divisor)
_pool_frame_threshold:
    .4byte  0x000000FA                           ! pool: 250 (frame counter threshold)
_pool_off_frame_time:
    .4byte  0x0000000C                           ! pool: car struct offset 0x000C (frame time A)
_pool_off_frame_time_b:
    .4byte  0x00000194                           ! pool: car struct offset 0x0194 (frame time B)
_pool_race_complete_flag:
    .4byte  sym_0605A1C4                         ! pool: &race_complete_flag (32-bit)
_pool_camera_state_a:
    .4byte  sym_06063E1C                         ! pool: &camera_state_a (camera mode)
_pool_render_scratch:
    .4byte  sym_06082A34                         ! pool: &render_scratch (scene parameter)
_pool_game_state:
    .4byte  sym_06063E20                         ! pool: &game_state (1=active race, 2=reset)

    .global sym_0602DC18
sym_0602DC18:                                    ! pipeline_reg_save — callee-saved register prologue
    mov.l r8, @-r15                              ! save r8
    mov.l r9, @-r15                              ! save r9
    mov.l r10, @-r15                             ! save r10
    mov.l r11, @-r15                             ! save r11
    mov.l r12, @-r15                             ! save r12
    mov.l r13, @-r15                             ! save r13
