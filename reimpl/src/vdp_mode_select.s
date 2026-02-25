/* vdp_mode_select -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06010D94 - 0x06010F04
 *
 * VDP Mode Selection — Multi-Channel 3D Transform Setup
 *
 * Called from graphics_mode_setup to configure 4 rendering channels for
 * the current VDP display mode. Each channel represents a 3D object
 * layer (car models, trackside objects, etc.) that needs position and
 * rotation transforms applied before VDP1/VDP2 rendering.
 *
 * Flow:
 *   1. Guard: if game_state_counter >= 0xA, skip (no rendering needed)
 *   2. Advance render budget by 0x30 (48 bytes per transform set)
 *   3. Push camera state, dispatch position transform from args
 *   4. Build Y-axis rotation matrix from current rotation angle
 *   5. Copy transform chain A (object transforms) into work area
 *   6. For each of 4 channels:
 *      a. Load position offset (X,Y,Z) — negated for camera-relative coords
 *      b. Dispatch position transform (sym_06026E2E)
 *      c. Copy transform chain A source into channel param table
 *      d. Dispatch transform chain B (sym_06031A28) with display index
 *      e. Decrement render budget by 0x30
 *   7. Final budget adjustment: subtract extra 0x30 + 0x30 for overhead
 *
 * Parameters (from caller):
 *   r4 = mode index (stored at sp+8)
 *   r5 = Y position (stored at sp+4)
 *   r6 = Z position (stored at sp+0)
 *   r7 = X position (stored at sp+12)
 *
 * Called by: graphics_mode_setup (BSR at 0x06010C90, 0x06010D24)
 */

    .section .text.FUN_06010D94


    .global vdp_mode_select
    .type vdp_mode_select, @function
vdp_mode_select:
    mov.l r14, @-r15                     ! save r14
    mov #0xA, r2                         ! r2 = 0xA (state threshold)
    mov.l r13, @-r15                     ! save r13
    mov.l r12, @-r15                     ! save r12
    mov.l r11, @-r15                     ! save r11
    mov.l r10, @-r15                     ! save r10
    mov.l r9, @-r15                      ! save r9
    mov.l r8, @-r15                      ! save r8
    sts.l pr, @-r15                      ! save return address
    add #-0x10, r15                      ! allocate 16 bytes locals
    mov.l r4, @(8, r15)                  ! sp[8] = mode_index (r4)
    mov.l r5, @(4, r15)                  ! sp[4] = y_pos (r5)
    mov.l r6, @r15                       ! sp[0] = z_pos (r6)
    mov.l r7, @(12, r15)                 ! sp[12] = x_pos (r7)
    mov.l   .L_game_state_counter, r3    ! r3 -> game state counter
    mov.l @r3, r3                        ! r3 = *game_state_counter
    cmp/hs r2, r3                        ! T = (state >= 0xA)?
    bf      .L_do_transform              ! if state < 0xA, do transforms
    bra     .L_epilogue                  ! else skip — no rendering needed
    nop                                  ! (delay slot)
.L_game_state_counter:
    .4byte  sym_060788A0                 ! game state counter (skip if >= 0xA)
.L_do_transform:
    mov.l   .L_render_budget_ptr, r14    ! r14 -> render budget pointer
    mov.l   .L_fn_camera_push, r3       ! r3 = camera_push fn addr
    mov.l @r14, r2                       ! r2 = current budget
    add #0x30, r2                        ! r2 += 0x30 (allocate 48 bytes)
    jsr @r3                              ! call camera_push()
    mov.l r2, @r14                       ! (delay) *budget = r2 (advance)
    mov.l   .L_fn_pos_transform, r8     ! r8 = pos_transform fn (kept in reg)
    mov.l @(12, r15), r6                 ! r6 = x_pos (arg3)
    mov.l @r15, r5                       ! r5 = z_pos (arg2)
    jsr @r8                              ! call pos_transform(y, z, x)
    mov.l @(4, r15), r4                  ! (delay) r4 = y_pos (arg1)
    mov.l   .L_rotation_angle, r4       ! r4 -> rotation angle word
    mov.l   .L_fn_mat_rot_y, r3         ! r3 = mat_rot_y fn addr
    jsr @r3                              ! call mat_rot_y(angle)
    mov.w @r4, r4                        ! (delay) r4 = rotation angle value
    mov.l   .L_chain_a_param_tbl, r13   ! r13 -> chain A param table base
    mov.l   .L_chain_a_src_tbl, r5      ! r5 -> chain A source table ptr
    mov.l   .L_fn_chain_a, r3           ! r3 = chain_a dispatch fn addr
    mov.l @r5, r5                        ! r5 = *chain_a_src (source data)
    jsr @r3                              ! call chain_a(param[0], src)
    mov.l @r13, r4                       ! (delay) r4 = chain_a_param[0]
    mov.l   .L_chain_b_param_tbl, r9    ! r9 -> chain B param table base
    mov.l   .L_fn_chain_b, r11          ! r11 = chain_b dispatch fn (kept)
    mov.l   .L_chain_b_src_tbl, r12     ! r12 -> chain B source table base
    mov.l @(8, r15), r10                 ! r10 = mode_index
    mov.l   .L_disp_index_table, r3     ! r3 -> display index lookup table
    mov.l @r12, r6                       ! r6 = chain_b_src[0] (ch1 src)
    shll r10                             ! r10 *= 2 (word index)
    add r3, r10                          ! r10 = &disp_index_table[mode]
    mov.w @r10, r5                       ! r5 = disp_index[mode] (display ID)
    jsr @r11                             ! call chain_b(param[0], disp, src)
    mov.l @r9, r4                        ! (delay) r4 = chain_b_param[0]
    mov.l   .L_fn_camera_init, r3       ! r3 = camera_init fn addr
    jsr @r3                              ! call camera_init() — reset state
    nop                                  ! (delay slot)
    ! --- Channel 1: position transform + chain dispatch ---
    mov.l   .L_ch1_pos_z, r6            ! r6 -> ch1 Z position ptr
    mov.l   .L_ch1_pos_y, r5            ! r5 -> ch1 Y position ptr
    mov.l   .L_ch1_pos_x, r4            ! r4 -> ch1 X position ptr
    mov.l @r6, r6                        ! r6 = ch1_Z value
    mov.l @r5, r5                        ! r5 = ch1_Y value
    neg r6, r6                           ! r6 = -Z (camera-relative)
    jsr @r8                              ! call pos_transform(X, Y, -Z)
    mov.l @r4, r4                        ! (delay) r4 = ch1_X value
    mov.l   .L_chain_a_src_ch2, r5      ! r5 -> chain A source for ch2
    mov.l   .L_fn_chain_a, r3           ! r3 = chain_a dispatch fn addr
    mov.l @r5, r5                        ! r5 = *chain_a_src_ch2
    jsr @r3                              ! call chain_a(param[1], src_ch2)
    mov.l @(4, r13), r4                  ! (delay) r4 = chain_a_param[1]
    mov.l @(4, r12), r6                  ! r6 = chain_b_src[1] (ch2 src)
    mov.w @r10, r5                       ! r5 = disp_index[mode]
    jsr @r11                             ! call chain_b(param[1], disp, src)
    mov.l @(4, r9), r4                   ! (delay) r4 = chain_b_param[1]
    mov.l @r14, r2                       ! r2 = current budget
    mov.l   .L_fn_camera_init, r3       ! r3 = camera_init fn addr
    add #-0x30, r2                       ! r2 -= 0x30 (release 48 bytes)
    jsr @r3                              ! call camera_init() — reset state
    mov.l r2, @r14                       ! (delay) *budget = r2
    ! --- Channel 2: position transform + chain dispatch ---
    mov.l   .L_ch2_pos_z, r6            ! r6 -> ch2 Z position ptr
    mov.l   .L_ch2_pos_y, r5            ! r5 -> ch2 Y position ptr
    mov.l   .L_ch2_pos_x, r4            ! r4 -> ch2 X position ptr
    mov.l @r6, r6                        ! r6 = ch2_Z value
    mov.l @r5, r5                        ! r5 = ch2_Y value
    neg r6, r6                           ! r6 = -Z (camera-relative)
    jsr @r8                              ! call pos_transform(X, Y, -Z)
    mov.l @r4, r4                        ! (delay) r4 = ch2_X value
    mov.l   .L_chain_a_src_ch3, r5      ! r5 -> chain A source for ch3
    mov.l   .L_fn_chain_a, r3           ! r3 = chain_a dispatch fn addr
    mov.l @r5, r5                        ! r5 = *chain_a_src_ch3
    jsr @r3                              ! call chain_a(param[2], src_ch3)
    mov.l @(8, r13), r4                  ! (delay) r4 = chain_a_param[2]
    mov.l @(8, r12), r6                  ! r6 = chain_b_src[2] (ch3 src)
    mov.w @r10, r5                       ! r5 = disp_index[mode]
    jsr @r11                             ! call chain_b(param[2], disp, src)
    mov.l @(8, r9), r4                   ! (delay) r4 = chain_b_param[2]
    mov.l @r14, r2                       ! r2 = current budget
    mov.l   .L_fn_camera_init, r3       ! r3 = camera_init fn addr
    add #-0x30, r2                       ! r2 -= 0x30 (release 48 bytes)
    jsr @r3                              ! call camera_init() — reset state
    mov.l r2, @r14                       ! (delay) *budget = r2
    ! --- Channel 3: position transform + chain dispatch ---
    mov.l   .L_ch3_pos_z, r6            ! r6 -> ch3 Z position ptr
    mov.l   .L_ch3_pos_y, r5            ! r5 -> ch3 Y position ptr
    mov.l   .L_ch3_pos_x, r4            ! r4 -> ch3 X position ptr
    mov.l @r6, r6                        ! r6 = ch3_Z value
    mov.l @r5, r5                        ! r5 = ch3_Y value
    neg r6, r6                           ! r6 = -Z (camera-relative)
    jsr @r8                              ! call pos_transform(X, Y, -Z)
    mov.l @r4, r4                        ! (delay) r4 = ch3_X value
    mov.l   .L_chain_a_src_ch4, r5      ! r5 -> chain A source for ch4
    mov.l   .L_fn_chain_a, r3           ! r3 = chain_a dispatch fn addr
    mov.l @r5, r5                        ! r5 = *chain_a_src_ch4
    jsr @r3                              ! call chain_a(param[3], src_ch4)
    mov.l @(12, r13), r4                 ! (delay) r4 = chain_a_param[3]
    mov.l @(12, r12), r6                 ! r6 = chain_b_src[3] (ch4 src)
    mov.w @r10, r5                       ! r5 = disp_index[mode]
    jsr @r11                             ! call chain_b(param[3], disp, src)
    mov.l @(12, r9), r4                  ! (delay) r4 = chain_b_param[3]
    mov.l @r14, r2                       ! r2 = current budget
    add #-0x30, r2                       ! r2 -= 0x30 (release ch3 budget)
    mov r2, r3                           ! r3 = r2
    add #-0x30, r3                       ! r3 -= 0x30 (release ch4 + overhead)
    mov.l r3, @r14                       ! *budget = r3 (final budget)
.L_epilogue:
    add #0x10, r15                       ! deallocate 16 bytes locals
    lds.l @r15+, pr                      ! restore return address
    mov.l @r15+, r8                      ! restore r8
    mov.l @r15+, r9                      ! restore r9
    mov.l @r15+, r10                     ! restore r10
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return
    mov.l @r15+, r14                     ! (delay) restore r14
    .2byte  0xFFFF                       ! alignment padding
.L_render_budget_ptr:
    .4byte  sym_06089EDC                 ! render budget counter (32-bit)
.L_fn_camera_push:
    .4byte  sym_06026E0C                 ! camera state push/save function
.L_fn_pos_transform:
    .4byte  sym_06026E2E                 ! position transform dispatch function
.L_rotation_angle:
    .4byte  sym_06078878                 ! current Y rotation angle (16-bit)
.L_fn_mat_rot_y:
    .4byte  mat_rot_y                    ! Y-axis rotation matrix builder
.L_chain_a_param_tbl:
    .4byte  sym_0606212C                 ! chain A parameter table (4 entries)
.L_chain_a_src_tbl:
    .4byte  sym_060621D8                 ! chain A source table (obj transforms)
.L_fn_chain_a:
    .4byte  sym_06031D8C                 ! transform chain A dispatch (vec copy)
.L_chain_b_param_tbl:
    .4byte  sym_060620D8                 ! chain B parameter table (4 entries)
.L_fn_chain_b:
    .4byte  sym_06031A28                 ! transform chain B dispatch (scaled)
.L_chain_b_src_tbl:
    .4byte  sym_06062180                 ! chain B source table (disp transforms)
.L_disp_index_table:
    .4byte  sym_06089E44                 ! display index lookup table (by mode)
.L_fn_camera_init:
    .4byte  sym_06026DBC                 ! camera state init/reset function
.L_ch1_pos_z:
    .4byte  sym_06044648                 ! channel 1 Z position (ptr)
.L_ch1_pos_y:
    .4byte  sym_06044644                 ! channel 1 Y position (ptr)
.L_ch1_pos_x:
    .4byte  sym_06044640                 ! channel 1 X position (ptr)
.L_chain_a_src_ch2:
    .4byte  sym_060621DC                 ! chain A source for channel 2
.L_ch2_pos_z:
    .4byte  sym_06044654                 ! channel 2 Z position (ptr)
.L_ch2_pos_y:
    .4byte  sym_06044650                 ! channel 2 Y position (ptr)
.L_ch2_pos_x:
    .4byte  sym_0604464C                 ! channel 2 X position (ptr)
.L_chain_a_src_ch3:
    .4byte  sym_060621E0                 ! chain A source for channel 3
.L_ch3_pos_z:
    .4byte  sym_06044678                 ! channel 3 Z position (ptr)
.L_ch3_pos_y:
    .4byte  sym_06044674                 ! channel 3 Y position (ptr)
.L_ch3_pos_x:
    .4byte  sym_06044670                 ! channel 3 X position (ptr)
.L_chain_a_src_ch4:
    .4byte  sym_060621E4                 ! chain A source for channel 4
