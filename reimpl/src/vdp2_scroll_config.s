/* vdp2_scroll_config -- VDP2 scroll plane animation controller
 * Translation unit: 0x06018320 - 0x060185D8
 *
 * Manages animated transitions for VDP2 scroll plane parameters during
 * gameplay. Called each frame to interpolate scroll position values
 * using a multi-phase state machine with two speed modes (normal and
 * boosted). After computing the interpolated scroll position, dispatches
 * a transform chain (pre-transform, rotation, transform chains A/B)
 * that applies the result to the VDP2 hardware.
 *
 * State bytes at sym_0605BE30-0605BE35:
 *   +0 (BE30): scroll config register (16-bit, bit 6 = direction flag)
 *   +2 (BE32): anim phase counter (byte)
 *   +3 (BE33): scroll active flag (byte, written to/from BE34)
 *   +4 (BE34): scroll active shadow (byte)
 *   +5 (BE35): force-complete flag (byte, forces scroll to half)
 *
 * Fixed-point values stored at r14 target (sym_06085FC0):
 *   @(0, r14): integer part of scroll position (16.16 fp)
 *   @(4, r14): fractional accumulator (16.16 fp)
 *
 * The function validates the current game state via the car struct
 * (offset 0x1EC must be in range [0x86, 0x9F]) before running.
 * If out of range, all scroll state is cleared and execution exits.
 */

    .section .text.FUN_06018320


    .global vdp2_scroll_config
    .type vdp2_scroll_config, @function
vdp2_scroll_config:
    mov.l r14, @-r15                ! save r14
    mov.l r13, @-r15                ! save r13
    mov.l r12, @-r15                ! save r12
    mov.l r11, @-r15                ! save r11
    mov.l r10, @-r15                ! save r10
    mov.l r9, @-r15                 ! save r9
    mov.l r8, @-r15                 ! save r8
    sts.l pr, @-r15                 ! save return address
    add #-0x4, r15                  ! allocate 4 bytes local space
    mov.l   .L_force_complete_flag, r9  ! r9 = &force_complete (sym_0605BE35)
    mov.l   .L_car_struct_ptr, r10  ! r10 = &car_struct_ptr (sym_0607E940)
    mov.l   .L_fp_half, r11        ! r11 = 0x8000 (0.5 fixed-point)
    mov.l   .L_anim_phase_ptr, r13 ! r13 = &anim_phase (sym_0605BE32)
    mov.l   .L_scroll_pos_ptr, r14 ! r14 = &scroll_pos struct (sym_06085FC0)
    mov.l   .L_scroll_shadow_ptr, r6  ! r6 = &scroll_shadow (sym_0605BE34)
    mov.l   .L_scroll_active_flag, r4 ! r4 = &scroll_active (sym_0605BE33)
    mov.b @r4, r3                   ! r3 = current scroll_active value
    mov.b r3, @r6                   ! shadow = scroll_active (save previous)
    mov.l @r10, r5                  ! r5 = car struct base pointer
    mov.w   DAT_060183ec, r0       ! r0 = 0x1EC (game state field offset)
    mov.w   DAT_060183ee, r3       ! r3 = 0x86 (minimum valid state)
    mov.l @(r0, r5), r5            ! r5 = car_struct[0x1EC] (game state)
    cmp/ge r3, r5                   ! state >= 0x86?
    bf/s    .L_clear_all_state      ! if state < 0x86, clear and exit
    mov #0x0, r12                   ! r12 = 0 (zero constant, delay slot)
    mov.w   DAT_060183f0, r3       ! r3 = 0x9F (maximum valid state)
    cmp/gt r3, r5                   ! state > 0x9F?
    bf      .L_begin_scroll_setup   ! if state <= 0x9F, proceed with setup
.L_clear_all_state:
    mov.l r12, @r14                 ! scroll_pos.integer = 0
    mov.l r12, @(4, r14)           ! scroll_pos.fraction = 0
    mov.b r12, @r4                  ! scroll_active = 0
    mov.b r12, @r9                  ! force_complete = 0
    bra     .L_early_exit           ! skip to early return
    mov.b r12, @r13                 ! anim_phase = 0 (delay slot)
.L_begin_scroll_setup:
    mov #0x1, r7                    ! r7 = 1 (active/true constant)
    extu.b r7, r2                   ! r2 = 1 (zero-extended)
    mov.b r2, @r4                   ! scroll_active = 1
    mov.l   .L_vdp2_scroll_reg_src, r0 ! r0 = &vdp2_scroll_source (g_pad_state)
    mov.l   .L_scroll_config_reg, r3   ! r3 = &scroll_config (sym_0605BE30)
    mov.w @r0, r0                   ! r0 = vdp2 source register value
    mov.w @r3, r3                   ! r3 = current scroll config value
    extu.w r0, r0                   ! zero-extend source to 32-bit
    extu.w r3, r3                   ! zero-extend config to 32-bit
    and #0x40, r0                   ! r0 = source bit 6 (direction bit)
    extu.w r0, r8                   ! r8 = isolated direction bit
    xor r8, r3                      ! r3 = config XOR direction (detect change)
    and r8, r3                      ! r3 = changed bits masked by new direction
    extu.w r3, r5                   ! r5 = direction change flag (16-bit)
    mov.l   .L_scroll_config_reg, r3   ! r3 = &scroll_config
    mov.w r8, @r3                   ! scroll_config = new direction bit value
    mov.l   .L_direction_flag_ptr, r0  ! r0 = &transition_state (sym_0605DE3C)
    mov.b @r0, r0                   ! r0 = transition state value
    extu.b r0, r0                   ! zero-extend
    tst r0, r0                      ! transition active?
    bt      .L_check_direction_change  ! if not in transition, check direction
    extu.b r7, r7                   ! r7 = 1
    bra     .L_check_boost_mode     ! skip direction check (in transition)
    mov.b r7, @r9                   ! force_complete = 1 (delay slot)
.L_check_direction_change:
    mov.b @r4, r2                   ! r2 = scroll_active (current)
    mov.b @r6, r3                   ! r3 = scroll_shadow (previous)
    mov.l @r10, r1                  ! r1 = car struct base pointer
    extu.b r2, r2                   ! zero-extend current
    extu.b r3, r3                   ! zero-extend previous
    mov r1, r0                      ! r0 = car struct base
    xor r3, r2                      ! r2 = XOR of current vs previous (change detect)
    mov.b @(3, r0), r0             ! r0 = car_struct[3] (car state flags byte)
    tst #0x8, r0                    ! test bit 3 of car state
    .word 0x0329 /* UNKNOWN */      ! (undecoded: conditional adjustment)
    add #-0x1, r3                   ! r3 = previous - 1
    neg r3, r3                      ! r3 = -(previous - 1) = 1 - previous
    tst r3, r3                      ! was previous == 1?
    .word 0x0029 /* UNKNOWN */      ! (undecoded: conditional adjustment)
    and r0, r2                      ! r2 = change AND car_state_flags
    tst r2, r2                      ! any relevant change bits set?
    bt      .L_check_boost_mode     ! if no change, skip force-complete
    mov.l   .L_frame_counter_ptr, r0   ! r0 = &frame_counter (sym_0605A010)
    mov.l @r0, r0                   ! r0 = frame counter value
    tst #0x3F, r0                   ! test low 6 bits (frame % 64 == 0?)
    bf      .L_check_boost_mode     ! if not on 64-frame boundary, skip
    extu.b r7, r7                   ! r7 = 1
    mov.b r7, @r9                   ! force_complete = 1
.L_check_boost_mode:
    mov.l   .L_fp_one, r4           ! r4 = 0x10000 (1.0 fixed-point, threshold)
    mov.l   .L_boost_mode_flag, r0 ! r0 = &boost_mode (sym_06085FF4)
    mov.b @r0, r0                   ! r0 = boost mode flag
    extu.b r0, r0                   ! zero-extend
    tst r0, r0                      ! boost mode active?
    bf      .L_boost_path_entry     ! if boost, take fast animation path
    mov.l @r10, r3                  ! r3 = car struct base pointer
    mov.l @(8, r3), r0             ! r0 = car_struct[8] (animation lock flag)
    tst r0, r0                      ! is animation locked?
    bt      .L_normal_check_active  ! if not locked, check for active scroll
    bra     .L_apply_transforms     ! if locked, skip animation, go to transforms
    nop                             !
.L_normal_check_active:
    extu.w r5, r5                   ! r5 = direction change flag (16-bit clean)
    tst r5, r5                      ! did direction change?
    bf      .L_normal_begin_anim    ! if changed, start normal animation
    bra     .L_apply_transforms     ! if no change, skip to transforms
    nop                             !
.L_normal_begin_anim:
    mov.w   DAT_060183f2, r5       ! r5 = 0x1000 (normal frac step per frame)
    mov.b @r13, r0                  ! r0 = current anim phase
    bra     .L_normal_phase_dispatch ! dispatch on phase number
    extu.b r0, r0                   ! zero-extend phase (delay slot)

    .global DAT_060183ec
DAT_060183ec:
    .2byte  0x01EC                      /* car struct game state field offset */

    .global DAT_060183ee
DAT_060183ee:
    .2byte  0x0086                      /* minimum valid game state */

    .global DAT_060183f0
DAT_060183f0:
    .2byte  0x009F                      /* maximum valid game state */

    .global DAT_060183f2
DAT_060183f2:
    .2byte  0x1000                      /* normal animation fraction step */
.L_force_complete_flag:
    .4byte  sym_0605BE35                /* force-complete flag (byte) */
.L_car_struct_ptr:
    .4byte  sym_0607E940                /* current car struct pointer */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_anim_phase_ptr:
    .4byte  sym_0605BE32                /* animation phase counter (byte) */
.L_scroll_pos_ptr:
    .4byte  sym_06085FC0                /* scroll position struct (int+frac) */
.L_scroll_shadow_ptr:
    .4byte  sym_0605BE34                /* previous scroll_active shadow (byte) */
.L_scroll_active_flag:
    .4byte  sym_0605BE33                /* scroll active flag (byte) */
.L_vdp2_scroll_reg_src:
    .4byte  g_pad_state                /* VDP2 scroll direction source register */
.L_scroll_config_reg:
    .4byte  sym_0605BE30                /* scroll config register (16-bit) */
.L_direction_flag_ptr:
    .4byte  sym_0605DE3C                /* transition state flag (byte) */
.L_frame_counter_ptr:
    .4byte  sym_0605A010                /* global frame counter (32-bit) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_boost_mode_flag:
    .4byte  sym_06085FF4                /* boost/extended mode flag (byte) */
.L_normal_phase_0:
    mov.l r12, @r14                 ! scroll_pos.integer = 0 (rising from 0)
    mov.l @(4, r14), r2            ! r2 = scroll_pos.fraction
    add r5, r2                      ! r2 += frac_step (0x1000)
    mov r2, r3                      ! r3 = updated fraction (for compare)
    mov.l r2, @(4, r14)            ! scroll_pos.fraction = r2
    cmp/ge r4, r3                   ! fraction >= 1.0?
    bf      .L_normal_anim_done     ! if not reached threshold, done
    mov.l r11, @r14                 ! scroll_pos.integer = 0.5 (clamp)
    mov.l r11, @(4, r14)           ! scroll_pos.fraction = 0.5 (reset)
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to next phase
    mov.b r3, @r13                  ! store updated phase
    bra     .L_normal_anim_done     ! done with this frame
    nop                             !
.L_normal_phase_1:
    mov.l r11, @r14                 ! scroll_pos.integer = 0.5 (falling from 0.5)
    mov.l @(4, r14), r2            ! r2 = scroll_pos.fraction
    add r5, r2                      ! r2 += frac_step (0x1000)
    mov r2, r3                      ! r3 = updated fraction (for compare)
    mov.l r2, @(4, r14)            ! scroll_pos.fraction = r2
    mov.l   .L_fp_one_point_five, r2 ! r2 = 0x18000 (1.5 fixed-point)
    cmp/ge r2, r3                   ! fraction >= 1.5?
    bf      .L_normal_anim_done     ! if not reached threshold, done
    mov.l r12, @r14                 ! scroll_pos.integer = 0 (clamp to zero)
    mov.l r12, @(4, r14)           ! scroll_pos.fraction = 0 (reset)
    mov.b @r13, r2                  ! r2 = anim_phase
    add #0x1, r2                    ! advance to next phase
    bra     .L_normal_anim_done     ! done with this frame
    mov.b r2, @r13                  ! store updated phase (delay slot)
.L_normal_phase_default:
    mov.l r12, @r14                 ! scroll_pos.integer = 0 (reset)
    bra     .L_normal_anim_done     ! done, go to transforms
    mov.l r12, @(4, r14)           ! scroll_pos.fraction = 0 (delay slot)
.L_normal_phase_dispatch:
    cmp/eq #0x0, r0                 ! phase == 0?
    bt      .L_normal_phase_0       ! ramp fraction 0 -> 1.0, int=0
    cmp/eq #0x1, r0                 ! phase == 1?
    bt      .L_normal_phase_1       ! ramp fraction 0.5 -> 1.5, int=0.5
    bra     .L_normal_phase_default ! unknown phase: reset to zero
    nop                             !
.L_normal_anim_done:
    bra     .L_apply_transforms     ! proceed to transform chain
    nop                             !
.L_boost_path_entry:
    mov.w   .L_fast_int_step, r7   ! r7 = 0x200 (fast integer step)
    mov.w   .L_fast_frac_step, r6  ! r6 = 0x100 (fast fractional step)
    mov.b @r13, r0                  ! r0 = current anim phase
    bra     .L_boost_phase_dispatch ! dispatch on phase number
    extu.b r0, r0                   ! zero-extend phase (delay slot)
.L_boost_phase_0:
    mov.l r12, @r14                 ! scroll_pos.integer = 0 (idle phase)
    mov.l r12, @(4, r14)           ! scroll_pos.fraction = 0
    mov.l @r10, r2                  ! r2 = car struct base pointer
    mov.l @(8, r2), r0             ! r0 = car_struct[8] (anim lock flag)
    tst r0, r0                      ! is animation locked?
    bf      .L_apply_transforms     ! if locked, skip (stay in phase 0)
    extu.w r5, r5                   ! r5 = direction change flag (16-bit clean)
    tst r5, r5                      ! did direction change?
    bt      .L_apply_transforms     ! if no change, stay in phase 0
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to phase 1
    mov.b r3, @r13                  ! store updated phase
    bra     .L_apply_transforms     ! done
    nop                             !
.L_boost_phase_1:
    mov.l @(4, r14), r2            ! r2 = scroll_pos.fraction
    add r6, r2                      ! r2 += fast_frac_step (0x100)
    mov.l r2, @(4, r14)            ! scroll_pos.fraction = r2
    mov r2, r3                      ! r3 = updated fraction (for compare)
    cmp/ge r4, r3                   ! fraction >= 1.0?
    bf      .L_apply_transforms     ! if not, keep accumulating
    mov.l r4, @(4, r14)            ! clamp fraction to 1.0
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to phase 2
    mov.b r3, @r13                  ! store updated phase
    bra     .L_apply_transforms     ! done
    nop                             !
.L_boost_phase_2:
    mov.l @r14, r2                  ! r2 = scroll_pos.integer
    add r7, r2                      ! r2 += fast_int_step (0x200)
    mov.l r2, @r14                  ! scroll_pos.integer = r2
    mov r2, r3                      ! r3 = updated integer (for compare)
    cmp/ge r11, r3                  ! integer >= 0.5?
    bf      .L_apply_transforms     ! if not, keep ramping
    mov.l r11, @r14                 ! clamp integer to 0.5
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to phase 3
    mov.b r3, @r13                  ! store updated phase
    bra     .L_apply_transforms     ! done
    nop                             !
.L_boost_phase_3:
    mov.l @(4, r14), r2            ! r2 = scroll_pos.fraction
    add r6, r2                      ! r2 += fast_frac_step (0x100)
    mov.l r2, @(4, r14)            ! scroll_pos.fraction = r2
    mov r2, r3                      ! r3 = updated fraction (for compare)
    mov.l   .L_fp_two, r4          ! r4 = 0x20000 (2.0 fixed-point)
    cmp/ge r4, r3                   ! fraction >= 2.0?
    bf      .L_apply_transforms     ! if not, keep accumulating
    mov.l r4, @(4, r14)            ! clamp fraction to 2.0
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to phase 4
    mov.b r3, @r13                  ! store updated phase
    bra     .L_apply_transforms     ! done
    nop                             !
.L_boost_phase_4:
    mov.l @r14, r2                  ! r2 = scroll_pos.integer
    add r7, r2                      ! r2 += fast_int_step (0x200)
    mov r2, r3                      ! r3 = updated integer (for compare)
    mov.l r2, @r14                  ! scroll_pos.integer = r2
    cmp/ge r4, r3                   ! integer >= 1.0? (r4 still 2.0 from phase 3)
    bf      .L_apply_transforms     ! if not, keep ramping
    mov.l r12, @r14                 ! clamp integer to 0 (wraparound)
    mov.b @r13, r3                  ! r3 = anim_phase
    add #0x1, r3                    ! advance to phase 5 (will hit default)
    mov.b r3, @r13                  ! store updated phase
    bra     .L_apply_transforms     ! done
    nop                             !
.L_boost_phase_default:
    mov.l r12, @r14                 ! scroll_pos.integer = 0 (reset)
    bra     .L_apply_transforms     ! done, go to transforms
    mov.l r12, @(4, r14)           ! scroll_pos.fraction = 0 (delay slot)
.L_fast_int_step:
    .2byte  0x0200                      /* boost mode integer step per frame */
.L_fast_frac_step:
    .2byte  0x0100                      /* boost mode fraction step per frame */
.L_fp_one_point_five:
    .4byte  0x00018000                  /* 1.5 (16.16 fixed-point) */
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_boost_phase_dispatch:
    cmp/eq #0x0, r0                 ! phase == 0? (idle, wait for trigger)
    bt      .L_boost_phase_0
    cmp/eq #0x1, r0                 ! phase == 1? (ramp fraction to 1.0)
    bt      .L_boost_phase_1
    cmp/eq #0x2, r0                 ! phase == 2? (ramp integer to 0.5)
    bt      .L_boost_phase_2
    cmp/eq #0x3, r0                 ! phase == 3? (ramp fraction to 2.0)
    bt      .L_boost_phase_3
    cmp/eq #0x4, r0                 ! phase == 4? (ramp integer to 1.0, wrap)
    bt      .L_boost_phase_4
    bra     .L_boost_phase_default  ! unknown phase: reset to zero
    nop                             !
.L_apply_transforms:
    mov.b @r9, r0                   ! r0 = force_complete flag
    extu.b r0, r0                   ! zero-extend
    tst r0, r0                      ! force complete active?
    bt      .L_begin_transform_chain ! if not forced, use computed values
    mov.l r11, @r14                 ! scroll_pos.integer = 0.5 (forced)
    mov.l r11, @(4, r14)           ! scroll_pos.fraction = 0.5 (forced)
.L_begin_transform_chain:
    mov.l   .L_fn_pre_transform_setup, r3 ! r3 = &pre_transform_setup (sym_06026DBC)
    jsr @r3                         ! call pre_transform_setup()
    nop                             !
    mov.l   .L_camera_pos_params, r8 ! r8 = &camera_pos_params (sym_06048140)
    mov.l   .L_fn_transform_dispatch, r3 ! r3 = &transform_dispatch (sym_06026E2E)
    mov.l @(8, r8), r6             ! r6 = camera_params.z
    mov.l @(4, r8), r5             ! r5 = camera_params.y
    jsr @r3                         ! call transform_dispatch(x, y, z)
    mov.l @r8, r4                   ! r4 = camera_params.x (delay slot)
    mov.l @(4, r14), r4            ! r4 = scroll_pos.fraction
    mov.w   DAT_060185a0, r2       ! r2 = 0x38E3 (Y rotation bias)
    mov.l   .L_fn_mat_rot_y, r3    ! r3 = &mat_rot_y
    jsr @r3                         ! call mat_rot_y(fraction + bias)
    add r2, r4                      ! r4 = fraction + 0x38E3 (delay slot)
    mov.l   .L_fn_mat_rot_x, r3 ! r3 = &mat_rot_x
    jsr @r3                         ! call mat_rot_x(scroll_int)
    mov.l @r14, r4                  ! r4 = scroll_pos.integer (delay slot)
    mov.w   .L_rotation_angle, r5  ! r5 = 0x178 (rotation angle param)
    mov.l   .L_wram_low, r2        ! r2 = 0x200000 (Work RAM Low base)
    mov.l   .L_wram_obj_offset, r3 ! r3 = 0xBABE0 (object data offset)
    mov r2, r4                      ! r4 = WRAM Low base
    add r3, r4                      ! r4 = WRAM_Low + 0xBABE0 (object addr)
    mov.l   .L_fn_transform_chain_a, r3 ! r3 = &transform_chain_a (sym_06031D8C)
    jsr @r3                         ! call transform_chain_a(obj_addr, angle)
    mov.l r2, @r15                  ! save WRAM_Low base on stack (delay slot)
    mov.w   .L_display_scale, r6   ! r6 = 0x145 (display scale param)
    mov.l   .L_scale_factor_table, r5 ! r5 = &scale_factors (sym_06089E98)
    mov.l @r15, r4                  ! r4 = WRAM_Low base (restore from stack)
    mov.l   .L_wram_display_offset, r2 ! r2 = 0xBBD80 (display data offset)
    mov.l   .L_fn_transform_chain_b, r3 ! r3 = &transform_chain_b (sym_06031A28)
    mov.w @r5, r5                   ! r5 = scale_factors[0] (16-bit value)
    jsr @r3                         ! call transform_chain_b(disp_addr, scale, param)
    add r2, r4                      ! r4 = WRAM_Low + 0xBBD80 (delay slot)
    add #0x4, r15                   ! free local stack space
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r8                 ! restore r8
    mov.l @r15+, r9                 ! restore r9
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    mov.l   .L_fn_post_transform, r3 ! r3 = &post_transform (sym_06026DF8)
    jmp @r3                         ! tail-call post_transform()
    mov.l @r15+, r14                ! restore r14 (delay slot)
.L_early_exit:
    add #0x4, r15                   ! free local stack space
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r8                 ! restore r8
    mov.l @r15+, r9                 ! restore r9
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    rts                             ! return to caller
    mov.l @r15+, r14                ! restore r14 (delay slot)

    .global DAT_060185a0
DAT_060185a0:
    .2byte  0x38E3                      /* Y rotation bias (added to fraction) */
.L_rotation_angle:
    .2byte  0x0178                      /* rotation angle parameter (376 deg units) */
.L_display_scale:
    .2byte  0x0145                      /* display scale parameter (325) */
    .2byte  0xFFFF                      /* padding / alignment */
.L_fn_pre_transform_setup:
    .4byte  sym_06026DBC                /* pre-transform setup function */
.L_camera_pos_params:
    .4byte  sym_06048140                /* camera position parameters (X/Y/Z) */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                /* transform dispatch function */
.L_fn_mat_rot_y:
    .4byte  mat_rot_y                   /* Y-axis rotation matrix builder */
.L_fn_mat_rot_x:
    .4byte  mat_rot_x            /* matrix transform function */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_wram_obj_offset:
    .4byte  0x000BABE0                  /* object data offset in WRAM Low */
.L_fn_transform_chain_a:
    .4byte  sym_06031D8C                /* transform chain A dispatch */
.L_scale_factor_table:
    .4byte  sym_06089E98                /* per-mode scale factor table (16-bit) */
.L_wram_display_offset:
    .4byte  0x000BBD80                  /* display data offset in WRAM Low */
.L_fn_transform_chain_b:
    .4byte  sym_06031A28                /* transform chain B dispatch */
.L_fn_post_transform:
    .4byte  sym_06026DF8                /* post-transform cleanup function */
