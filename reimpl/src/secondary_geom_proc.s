/* secondary_geom_proc -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600A76C - 0x0600A914
 *
 * Two unrelated functions sharing a constant pool:
 *
 * secondary_geom_proc (FUN_0600A76C):
 *   Paired 3D object renderer using Type B (absolute/scene) transforms.
 *   Structurally identical to camera_collision_avoid (FUN_0600A614) but uses
 *   scene-space matrix operations instead of additive push-matrix transforms.
 *   Draws up to 2 trackside objects (A and B) from separate position tables:
 *     Object A: config[+0] model index, config[+1] enable flag
 *     Object B: config[+3] model index, config[+4] enable flag (Z negated)
 *   Per-object pipeline:
 *     1. Scene matrix init (sym_06027080)
 *     2. Position transform with axis offsets (sym_060270F2)
 *     3. Half-scale 0.5 on all axes (mat_scale_b)
 *     4. Distance check + render submit (sym_06032158 / sym_06031DF4)
 *     5. Decrement render budget by 0x30
 *   Called from FUN_0600B340 (primary scene rendering coordinator).
 *
 * audio_phase_ticker (sym_0600A8BC):
 *   Speed-proportional audio phase counter. Increments a 4-bit counter
 *   at rate +1 (speed<100), +2 (100<=speed<200), or +4 (speed>=200).
 *   Resets to 0 when car is stopped. Wraps at 16 (mask 0x0F).
 *   Called from per-car iteration loop (FUN_0600DE70).
 */

    .section .text.FUN_0600A76C


    .global secondary_geom_proc
    .type secondary_geom_proc, @function
secondary_geom_proc:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    sts.l pr, @-r15                     ! save return address
    add #-0x4, r15                      ! allocate 4 bytes for local (index offset)
    mov.l   .L_render_budget_ptr, r12   ! r12 = &render_budget (sym_0608A52C)
    mov.l   .L_fp_half, r13            ! r13 = 0x8000 (0.5 in 16.16 fixed-point)
    mov.l   .L_config_ptr, r14         ! r14 = &config_ptr (sym_0607EB8C, indirect)
    mov.l @r14, r14                     ! r14 = config struct base
    mov.b @(1, r14), r0                 ! r0 = config[+1] (object A enable flag)
    mov r0, r3                          ! r3 = enable flag
    tst r3, r3                          ! test if object A is enabled
    bt      .L_skip_obj_a               ! disabled -> skip object A
    ! --- render object A ---
    mov.l   .L_fn_scene_matrix_init, r3 ! r3 = scene matrix init fn (sym_06027080)
    jsr @r3                             ! call scene_matrix_init()
    nop                                 ! (delay slot)
    mov.l   .L_position_vec_a, r11     ! r11 = &position_A (sym_06044640, XYZ triplet)
    mov.l   .L_pos_offset_z_a, r2     ! r2 = Z axis offset (0xFFFF0F5D, signed)
    mov.w   .L_off_adj_yz, r3         ! r3 = Y axis adjustment (0xCCCD, signed)
    mov.l @(8, r11), r6                 ! r6 = position_A.Z
    mov.l @(4, r11), r5                 ! r5 = position_A.Y
    mov.l @r11, r4                      ! r4 = position_A.X
    add r2, r6                          ! Z += z_offset_a
    add r3, r5                          ! Y += y_adjustment
    mov.w   DAT_0600a856, r2           ! r2 = X axis adjustment (0x8000, signed)
    mov.l   .L_fn_position_transform, r3 ! r3 = position transform fn (sym_060270F2)
    jsr @r3                             ! call position_transform(X, Y, Z)
    add r2, r4                          ! (delay) X += x_adjustment
    mov r13, r6                         ! r6 = 0.5 (Z scale)
    mov r13, r5                         ! r5 = 0.5 (Y scale)
    mov.l   .L_fn_scale, r3           ! r3 = mat_scale_b
    jsr @r3                             ! call mat_scale_b(0.5, 0.5, 0.5)
    mov r13, r4                         ! (delay) r4 = 0.5 (X scale)
    ! --- distance check for object A ---
    mov.b @r14, r5                      ! r5 = config[+0] (model index base)
    add #0xE, r5                        ! r5 = model_index + 14
    shll2 r5                            ! r5 = (model_index + 14) * 4 (byte offset)
    mov.l r5, @r15                      ! save index offset on stack
    mov.l   .L_dist_check_src_tbl, r3 ! r3 = dist check source table (sym_060621D8)
    mov.l @r15, r4                      ! r4 = index offset (copy)
    mov.l   .L_dist_check_param_tbl, r2 ! r2 = dist check param table (sym_0606212C)
    mov.l   .L_fn_dist_check, r1      ! r1 = distance check fn (sym_06032158)
    add r3, r5                          ! r5 = &src_tbl[index]
    add r2, r4                          ! r4 = &param_tbl[index]
    mov.l @r5, r5                       ! r5 = src_tbl[index]
    jsr @r1                             ! call dist_check(param_tbl[index], src_tbl[index])
    mov.l @r4, r4                       ! (delay) r4 = param_tbl[index]
    ! --- render submit for object A ---
    mov.b @r14, r6                      ! r6 = config[+0] (model index base)
    add #0xE, r6                        ! r6 = model_index + 14
    shll2 r6                            ! r6 = (model_index + 14) * 4 (byte offset)
    mov.l r6, @r15                      ! save index offset on stack
    mov.l   .L_render_src_tbl, r3     ! r3 = render source table (sym_06062180)
    mov.l   .L_disp_mode_word, r5     ! r5 = &display_mode (sym_06089E9C)
    mov.l @r15, r4                      ! r4 = index offset (copy)
    mov.l   .L_render_param_tbl, r2   ! r2 = render param table (sym_060620D8)
    mov.l   .L_fn_render_submit, r1   ! r1 = render submit fn (sym_06031DF4)
    add r3, r6                          ! r6 = &render_src[index]
    mov.w @r5, r5                       ! r5 = display_mode (16-bit)
    add r2, r4                          ! r4 = &render_param[index]
    mov.l @r6, r6                       ! r6 = render_src[index]
    extu.w r5, r5                       ! r5 = zero-extend display_mode
    jsr @r1                             ! call render_submit(param, mode, src)
    mov.l @r4, r4                       ! (delay) r4 = render_param[index]
    ! --- decrement render budget ---
    mov.l @r12, r3                      ! r3 = current render budget
    add #-0x30, r3                      ! r3 -= 0x30 (48 bytes per object)
    mov.l r3, @r12                      ! store updated budget
.L_skip_obj_a:
    mov.b @(4, r14), r0                 ! r0 = config[+4] (object B enable flag)
    mov r0, r2                          ! r2 = enable flag
    tst r2, r2                          ! test if object B is enabled
    bt      .L_epilogue                 ! disabled -> skip to epilogue
    ! --- render object B ---
    mov.l   .L_fn_scene_matrix_init, r3 ! r3 = scene matrix init fn (sym_06027080)
    jsr @r3                             ! call scene_matrix_init()
    nop                                 ! (delay slot)
    mov.l   .L_position_vec_b, r11     ! r11 = &position_B (sym_06044670, XYZ triplet)
    mov.l   .L_pos_offset_z_b, r3     ! r3 = Z axis offset (0xFFFDB334, signed)
    mov.w   .L_off_adj_yz, r2         ! r2 = Y axis adjustment (0xCCCD, signed)
    mov.l @(8, r11), r6                 ! r6 = position_B.Z
    mov.l @(4, r11), r5                 ! r5 = position_B.Y
    neg r6, r6                          ! Z = -Z (mirrored placement for object B)
    add r2, r5                          ! Y += y_adjustment
    add r3, r6                          ! Z += z_offset_b
    mov.l   .L_fn_position_transform, r3 ! r3 = position transform fn (sym_060270F2)
    jsr @r3                             ! call position_transform(X, Y, Z)
    mov.l @r11, r4                      ! (delay) r4 = position_B.X (no offset)
    mov r13, r6                         ! r6 = 0.5 (Z scale)
    mov r13, r5                         ! r5 = 0.5 (Y scale)
    mov.l   .L_fn_scale, r3           ! r3 = mat_scale_b
    jsr @r3                             ! call mat_scale_b(0.5, 0.5, 0.5)
    mov r13, r4                         ! (delay) r4 = 0.5 (X scale)
    ! --- distance check for object B ---
    mov.b @(3, r14), r0                 ! r0 = config[+3] (model index base)
    mov r0, r5                          ! r5 = model_index
    add #0xE, r5                        ! r5 = model_index + 14
    shll2 r5                            ! r5 = (model_index + 14) * 4 (byte offset)
    mov.l r5, @r15                      ! save index offset on stack
    mov.l   .L_dist_check_src_tbl, r3 ! r3 = dist check source table (sym_060621D8)
    mov.l @r15, r4                      ! r4 = index offset (copy)
    mov.l   .L_dist_check_param_tbl, r2 ! r2 = dist check param table (sym_0606212C)
    mov.l   .L_fn_dist_check, r1      ! r1 = distance check fn (sym_06032158)
    add r3, r5                          ! r5 = &src_tbl[index]
    add r2, r4                          ! r4 = &param_tbl[index]
    mov.l @r5, r5                       ! r5 = src_tbl[index]
    jsr @r1                             ! call dist_check(param_tbl[index], src_tbl[index])
    mov.l @r4, r4                       ! (delay) r4 = param_tbl[index]
    ! --- render submit for object B ---
    mov.b @(3, r14), r0                 ! r0 = config[+3] (model index base)
    mov r0, r6                          ! r6 = model_index
    add #0xE, r6                        ! r6 = model_index + 14
    shll2 r6                            ! r6 = (model_index + 14) * 4 (byte offset)
    mov.l r6, @r15                      ! save index offset on stack
    mov.l   .L_render_src_tbl, r3     ! r3 = render source table (sym_06062180)
    add r3, r6                          ! r6 = &render_src[index]
    mov.l @r6, r6                       ! r6 = render_src[index]
    mov.l   .L_disp_mode_word, r5     ! r5 = &display_mode (sym_06089E9C)
    mov.w @r5, r5                       ! r5 = display_mode (16-bit)
    extu.w r5, r5                       ! r5 = zero-extend display_mode
    bra     .L_submit_render_b          ! -> shared render submit + budget decrement
    nop                                 ! (delay slot)
.L_off_adj_yz:
    .2byte  0xCCCD                      /* Y axis position adjustment (signed: -0x3333) */

    .global DAT_0600a856
DAT_0600a856:
    .2byte  0x8000                      /* X axis position adjustment (signed: -0x8000) */
.L_render_budget_ptr:
    .4byte  sym_0608A52C                /* render budget counter B */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_config_ptr:
    .4byte  sym_0607EB8C                /* config struct pointer (indirect) */
.L_fn_scene_matrix_init:
    .4byte  sym_06027080                /* Type B: scene matrix setup */
.L_position_vec_a:
    .4byte  sym_06044640                /* object A position vector (XYZ triplet) */
.L_pos_offset_z_a:
    .4byte  0xFFFF0F5D                  /* object A Z offset (signed: -0xF0A3) */
.L_fn_position_transform:
    .4byte  sym_060270F2                /* Type B: set position transform */
.L_fn_scale:
    .4byte  mat_scale_b                 /* Type B: matrix scale function */
.L_dist_check_src_tbl:
    .4byte  sym_060621D8                /* distance check source table */
.L_dist_check_param_tbl:
    .4byte  sym_0606212C                /* distance check parameter table */
.L_fn_dist_check:
    .4byte  sym_06032158                /* Type B: distance check function */
.L_render_src_tbl:
    .4byte  sym_06062180                /* render submit source table */
.L_disp_mode_word:
    .4byte  sym_06089E9C                /* display mode selector (16-bit) */
.L_render_param_tbl:
    .4byte  sym_060620D8                /* render submit parameter table */
.L_fn_render_submit:
    .4byte  sym_06031DF4                /* Type B: render submit function */
.L_position_vec_b:
    .4byte  sym_06044670                /* object B position vector (XYZ triplet) */
.L_pos_offset_z_b:
    .4byte  0xFFFDB334                  /* object B Z offset (signed: -0x24CCC) */
.L_submit_render_b:                     ! --- shared render submit path (object B) ---
    mov.l @r15, r4                      ! r4 = index offset from stack
    mov.l   .L_render_param_tbl_2, r2 ! r2 = render param table (dup for pool reach)
    mov.l   .L_fn_render_submit_2, r1 ! r1 = render submit fn (dup for pool reach)
    add r2, r4                          ! r4 = &render_param[index]
    jsr @r1                             ! call render_submit(param, mode, src)
    mov.l @r4, r4                       ! (delay) r4 = render_param[index]
    ! --- decrement render budget ---
    mov.l @r12, r3                      ! r3 = current render budget
    add #-0x30, r3                      ! r3 -= 0x30 (48 bytes per object)
    mov.l r3, @r12                      ! store updated budget
.L_epilogue:
    add #0x4, r15                       ! free local stack variable
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14

    .global sym_0600A8BC
sym_0600A8BC:                           ! --- audio phase ticker ---
    mov.l   .L_phase_counter_ptr, r4   ! r4 = &phase_counter (sym_06063F46)
    mov.l   .L_car_state_ptr, r5      ! r5 = &car_ptr (sym_0607E940)
    mov.l @r5, r5                       ! r5 = car state base
    mov.l @(12, r5), r0                 ! r0 = car->active_flag (offset 0xC: 0=stopped)
    tst r0, r0                          ! test if car is active
    bt      .L_phase_reset              ! car stopped -> reset counter to 0
    mov #0x64, r2                       ! r2 = 100 (speed threshold)
    mov.l @(8, r5), r3                  ! r3 = car->speed (offset 0x8)
    cmp/ge r2, r3                       ! speed >= 100?
    bt      .L_speed_ge_100             ! yes -> check higher threshold
    ! speed < 100: increment by 1
    mov.w @r4, r2                       ! r2 = current phase counter
    add #0x1, r2                        ! r2 += 1
    bra     .L_phase_store              ! -> mask and store
    mov.w r2, @r4                       ! (delay) store counter
.L_speed_ge_100:
    mov.l @(8, r5), r2                  ! r2 = car->speed (offset 0x8)
    mov.w   .L_speed_threshold_200, r3 ! r3 = 200 (0x00C8)
    cmp/ge r3, r2                       ! speed >= 200?
    bt      .L_speed_ge_200             ! yes -> fastest increment
    ! 100 <= speed < 200: increment by 2
    mov.w @r4, r3                       ! r3 = current phase counter
    add #0x2, r3                        ! r3 += 2
    mov.w r3, @r4                       ! store counter
    bra     .L_phase_store              ! -> mask and store
    nop                                 ! (delay slot)
.L_speed_ge_200:
    ! speed >= 200: increment by 4
    mov.w @r4, r2                       ! r2 = current phase counter
    add #0x4, r2                        ! r2 += 4
    mov.w r2, @r4                       ! store counter
.L_phase_store:
    mov.w @r4, r0                       ! r0 = phase counter
    and #0xF, r0                        ! r0 &= 0x0F (wrap at 16 phases)
    bra     .L_phase_exit               ! -> exit
    mov.w r0, @r4                       ! (delay) store masked counter
.L_phase_reset:
    mov #0x0, r2                        ! r2 = 0
    mov.w r2, @r4                       ! phase_counter = 0 (car stopped)
.L_phase_exit:
    rts                                 ! return
    nop                                 ! (delay slot)
.L_speed_threshold_200:
    .2byte  0x00C8                      /* 200 (speed threshold for +4 increment) */
    .2byte  0xFFFF                      /* padding */
.L_render_param_tbl_2:
    .4byte  sym_060620D8                /* render param table (dup for pool reach) */
.L_fn_render_submit_2:
    .4byte  sym_06031DF4                /* render submit fn (dup for pool reach) */
.L_phase_counter_ptr:
    .4byte  sym_06063F46                /* audio phase counter (16-bit word) */
.L_car_state_ptr:
    .4byte  sym_0607E940                /* current car state pointer (indirect) */
