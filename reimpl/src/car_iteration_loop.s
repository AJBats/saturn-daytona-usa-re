/* car_iteration_loop -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600DE70 - 0x0600DF66
 *
 * Per-frame car iteration loop. Called from State 17 (race main) to process
 * every active car once per frame.
 *
 * Flow:
 *   1. Compute half-car-count via divisor function, store to sym_060786CA.
 *   2. Set up car[0] and car[1] pointers on the stack (stride = 0x268).
 *   3. Loop over all active cars (count from byte at sym_06078634):
 *      a. Special mode (sym_06078635 != 0):
 *         - Iteration 0: process car[1], set frame marker in sym_0607ED8C.
 *         - Iteration 1+: process car[0], clear marker, decrement countdown.
 *         - Restores camera yaw from saved value on car[0] path.
 *      b. Normal mode: set physics init flag (sym_0607EAE4) once on first pass.
 *      c. Call car_frame_update (FUN_0600E4F2) for each car.
 *   4. Post-loop: call audio phase ticker (FUN_0600A8BC).
 *   5. Branch on terrain rendering mode (sym_06083255):
 *      - If set: call terrain data lookup (FUN_06034900).
 *      - If clear: call sprite transform (FUN_0602F7EA).
 *   6. Call frame finalize (FUN_0602F99C), then tail-branch to common exit
 *      (FUN_0600E0C0).
 *
 * Persistent registers:
 *   r8  = &frame_marker (sym_0607ED8C, 16-bit)
 *   r9  = &physics_init_flag (sym_0607EAE4, 32-bit)
 *   r10 = &warmup_countdown (sym_0607ED88, 32-bit)
 *   r11 = &current_car_ptr (sym_0607E940)
 *   r12 = loop counter (car index)
 *   r13 = constant 1 (used as flag value)
 *   r14 = &car_base_ptr (sym_0607E944)
 *
 * Stack layout (12 bytes):
 *   sp+0x00 = car[0] base address
 *   sp+0x04 = car[1] base address
 *   sp+0x08 = saved camera yaw value
 */

    .section .text.FUN_0600DE70


    .global car_iteration_loop
    .type car_iteration_loop, @function
car_iteration_loop:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    mov.l r13, @-r15                       ! save r13 (callee-saved)
    mov.l r12, @-r15                       ! save r12 (callee-saved)
    mov #0x1, r13                          ! r13 = 1 (flag constant, used throughout)
    mov.l r11, @-r15                       ! save r11 (callee-saved)
    mov.l r10, @-r15                       ! save r10 (callee-saved)
    mov.l r9, @-r15                        ! save r9 (callee-saved)
    mov.l r8, @-r15                        ! save r8 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    add #-0xC, r15                         ! allocate 12 bytes of stack locals
    mov.l   _pool_frame_marker, r8         ! r8 = &frame_marker (sym_0607ED8C)
    mov.l   _pool_physics_init_flag, r9    ! r9 = &physics_init_flag (sym_0607EAE4)
    mov.l   _pool_warmup_countdown, r10    ! r10 = &warmup_countdown (sym_0607ED88)
    mov.l   _pool_current_car_ptr, r11     ! r11 = &current_car_ptr (sym_0607E940)
    mov.l   _pool_car_base_ptr, r14        ! r14 = &car_base_ptr (sym_0607E944)
    mov.l   _pool_total_car_count_ptr, r0  ! r0 = &total_car_count (sym_0607EA98)
    mov.l   _pool_fn_calc_divisor, r3      ! r3 = &calc_divisor (sym_06035340)
    mov.l @r0, r0                          ! r0 = total_car_count value
    jsr @r3                                ! call calc_divisor(r0=count, r1=-4)
    mov #-0x4, r1                          ! r1 = -4 (divisor parameter, delay slot)
    exts.w r0, r0                          ! sign-extend result to 32 bits
    mov.l   _pool_half_count_store, r3     ! r3 = &half_count_store (sym_060786CA)
    mov.w r0, @r3                          ! store half-car-count as 16-bit word
    mov.l   _pool_camera_yaw_ptr, r2       ! r2 = &camera_yaw (sym_06063EF0)
    mov.l @r2, r2                          ! r2 = current camera yaw value
    mov.l r2, @(8, r15)                    ! stack[8] = saved camera yaw
    mov #0x0, r12                          ! r12 = 0 (loop counter init)
    mov.l   _pool_car_array_base, r4       ! r4 = &car_array[0] (sym_06078900)
    mov.w   DAT_0600deb2, r3               ! r3 = 0x268 (car struct stride)
    add r4, r3                             ! r3 = car_array + 0x268 = &car[1]
    mov.l r3, @(4, r15)                    ! stack[4] = &car[1] base address
    bra     .L_loop_test                   ! jump to loop condition test
    mov.l r4, @r15                         ! stack[0] = &car[0] base address (delay slot)

    .global DAT_0600deb2
DAT_0600deb2:
    .2byte  0x0268                         ! car struct stride (616 bytes)
_pool_total_car_count_ptr:
    .4byte  sym_0607EA98                   ! &total_car_count (long)
_pool_half_count_store:
    .4byte  sym_060786CA                   ! &half_count (word, divisor result)
_pool_car_base_ptr:
    .4byte  sym_0607E944                   ! &car_base_ptr (iteration scratch)
_pool_current_car_ptr:
    .4byte  sym_0607E940                   ! &current_car_ptr (active car)
_pool_frame_marker:
    .4byte  sym_0607ED8C                   ! &frame_marker (16-bit, special mode)
_pool_physics_init_flag:
    .4byte  sym_0607EAE4                   ! &physics_init_flag (32-bit)
_pool_warmup_countdown:
    .4byte  sym_0607ED88                   ! &warmup_countdown (32-bit)
_pool_fn_calc_divisor:
    .4byte  sym_06035340                   ! &calc_divisor function
_pool_camera_yaw_ptr:
    .4byte  sym_06063EF0                   ! &camera_yaw (global angle storage)
_pool_car_array_base:
    .4byte  sym_06078900                   ! &car_array[0] (car struct base)
.L_loop_body:
    .byte   0xD0, 0x2D    /* mov.l .L_pool_0600DF94, r0 */  ! r0 = &special_mode_flag (sym_06078635)
    mov.b @r0, r0                          ! r0 = special_mode_flag byte
    extu.b r0, r0                          ! zero-extend to 32 bits
    tst r0, r0                             ! test if special mode is active
    bt      .L_normal_mode                 ! if special_mode == 0, normal path
    extu.w r12, r12                        ! zero-extend loop counter to 32 bits
    tst r12, r12                           ! test if this is iteration 0
    bf      .L_setup_car0                  ! if counter != 0, set up car[0]
    ! --- Special mode, iteration 0: process car[1] first ---
    mov.w r13, @r8                         ! frame_marker = 1 (signal car[1] active)
    mov.l @(4, r15), r2                    ! r2 = &car[1] from stack
    mov.l r2, @r14                         ! car_base_ptr = &car[1]
    mov r2, r3                             ! r3 = &car[1] (unused, consumed by delay)
    bra     .L_call_car_update             ! proceed to per-car update
    mov.l r2, @r11                         ! current_car_ptr = &car[1] (delay slot)
.L_setup_car0:
    mov #0x0, r2
    mov.w r2, @r8
    mov.l @r10, r3
    add #-0x2, r3
    mov.l r3, @r10
    mov.l @r15, r2
    mov.l r2, @r14
    mov.l @(8, r15), r3
    .byte   0xD2, 0x23    /* mov.l .L_pool_0600DF98, r2 */
    mov.l r3, @r2
    mov.l @r14, r3
    mov.l r3, @r11
    bra     .L_call_car_update
    nop
.L_normal_mode:
    mov.l @r9, r0
    tst r0, r0
    bf      .L_call_car_update
    mov.l r13, @r9
.L_call_car_update:
    .byte   0xB2, 0xE9    /* bsr 0x0600E4F2 (external) */
    nop
    add #0x1, r12
.L_loop_test:
    extu.w r12, r2
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0600DF9C, r3 */
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r3, r2
    bf      .L_loop_body
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600DFA0, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1B    /* mov.l .L_pool_0600DFA4, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_standard_render
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600DFA8, r3 */
    jsr @r3
    nop
    bra     .L_frame_finalize
    nop
.L_standard_render:
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600DFAC, r3 */
    jsr @r3
    nop
.L_frame_finalize:
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600DFB0, r3 */
    jsr @r3
    nop
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0xAD    /* bra 0x0600E0C0 (external) */
    mov.l @r15+, r14
