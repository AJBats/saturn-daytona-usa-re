/* scene_post_render -- Scene grid rendering dispatch (post-render path)
 * Translation unit: 0x06006868 - 0x06006A9C
 *
 * Called from the main scene render body (FUN_0600C010) after the per-frame
 * update chain. Iterates over a 2D spatial grid of scene sectors visible
 * from the camera and dispatches each visible cell through a dual-pass
 * vertex transform pipeline (pass A then pass B).
 *
 * This is a sibling to scene_path_a (0x06006A9C) and scene_path_b
 * (0x06006CDC), sharing the same dispatch table layout and render function
 * selection logic. All three use the player/scene mode index
 * (*sym_0607EAD8) to select render variants.
 *
 * Grid construction:
 *   The camera orientation data (sym_06063DF8) provides yaw angle and
 *   field-of-view extent. These are quantised via >>21 to column indices
 *   (0..0x3F range). The start column (from yaw) and end column (from
 *   -FOV extent, rounded up) define the visible column range. Boundary
 *   clamping at 0x3F sets the outer loop limit to 0x40 and clears the
 *   inner loop step; at 0x00 the inner step is zeroed out.
 *
 * For each cell in the visible grid:
 *   1. Read vis_entry_a (halfword) from dispatch_table_b[mode*4+0]
 *   2. If positive: compute pipeline address from pipeline_state array
 *      + offset table, then call pass A render function
 *   3. Read vis_entry_b (halfword) from dispatch_table_b[mode*4+2]
 *   4. If positive: same pipeline address computation, call pass B
 *      render function
 *
 * Render function selection by mode (*sym_0607EAD8):
 *   Mode 0/1, pass A: sym_06029BF4 (vertex xform pipeline A)
 *   Mode 2,   pass A: sym_0602B328 (face projection, scene_proc_c entry)
 *   Mode 0/1, pass B: sym_0602A834 (vertex xform pipeline B)
 *   Mode 2,   pass B: sym_0602AF3C (frustum cull, scene_proc_b entry)
 *
 * After grid iteration, checks game state flags (*sym_0607EBC4). If
 * bits 28-29 (0x30000000) are clear, dispatches to a mode-specific
 * post-processing function:
 *   Mode 0: track_geometry_proc (track geometry animation)
 *   Mode 1: track_state_machine (track state transitions)
 *   Mode 2: geom_math_calc (geometry math processing)
 * Then tail-calls scene_process_stage (scene entity renderer).
 *
 * If bits 28-29 are set, returns immediately (skip post-processing).
 *
 * Register plan:
 *   r8  = pipeline_state addr (per-cell, computed from pool)
 *   r9  = grid cell index (row*column combined traversal)
 *   r10 = &render_param (sym_06089E96, halfword, persistent)
 *   r11 = inner cell index (for pipeline addr computation)
 *   r12 = inner loop counter (column within row)
 *   r13 = vis_entry_b value (from second halfword table read)
 *   r14 = &player_mode (sym_0607EAD8, persistent)
 *
 * Stack frame (0x2C = 44 bytes):
 *   sp+0x00 = outer_step (column step: 0x40, -0x40, or 0)
 *   sp+0x04 = pass_a_params (dispatch_table_a[mode*2])
 *   sp+0x08 = pass_b_params (dispatch_table_a[mode*2+1])
 *   sp+0x0C = inner_step (+1 or 0, direction flag)
 *   sp+0x10 = vis_array_a (dispatch_table_b[mode*4+0])
 *   sp+0x14 = vis_array_d (dispatch_table_b[mode*4+3])
 *   sp+0x18 = vis_array_c (dispatch_table_b[mode*4+2])
 *   sp+0x1C = offset_array (dispatch_table_b[mode*4+1])
 *   sp+0x20 = col_base_idx (end_col*64 + start_col)
 *   sp+0x24 = outer_limit (default 0x40, may be 0 at boundary)
 *   sp+0x28 = inner_limit (-1 default, may be 0)
 */

    .section .text.FUN_06006868


    .global scene_post_render
    .type scene_post_render, @function
scene_post_render:
    mov.l r14, @-r15              ! save r14
    mov.l r13, @-r15              ! save r13
    mov.l r12, @-r15              ! save r12
    mov.l r11, @-r15              ! save r11
    mov.l r10, @-r15              ! save r10
    mov.l r9, @-r15               ! save r9
    mov.l r8, @-r15               ! save r8
    sts.l pr, @-r15               ! save return address
    add #-0x2C, r15               ! allocate 44-byte stack frame
    mov.l   _pool_player_mode_ptr, r14  ! r14 = &player_mode (sym_0607EAD8, persistent)
    mov.l   _pool_car_state_ptr, r4     ! r4 = &car_state (sym_0607E944)
    mov.l   _pool_scene_depth_param, r2 ! r2 = &scene_depth_param (sym_06063F54)
    mov.l @r4, r4                 ! r4 = *car_state (dereference to car struct base)
    mov.l @(20, r4), r3           ! r3 = car_struct[5] (scene depth value at offset 0x14)
    mov.l r3, @r2                 ! *scene_depth_param = car_struct[5]
    ! --- Load pass A/B params from dispatch_table_a ---
    mov.l   _pool_dispatch_table_a, r4  ! r4 = dispatch_table_a base (sym_06062248)
    mov.l @r14, r0                ! r0 = player_mode
    shll2 r0                      ! r0 = mode * 4
    shll r0                       ! r0 = mode * 8 (byte offset, 2 longs per mode)
    mov.l @(r0, r4), r3           ! r3 = table_a[mode*2] (pass A params)
    mov.l r3, @(4, r15)           ! sp+0x04 = pass_a_params
    mov.l @r14, r0                ! r0 = player_mode (reload)
    shll r0                       ! r0 = mode * 2
    add #0x1, r0                  ! r0 = mode*2 + 1
    shll2 r0                      ! r0 = (mode*2+1) * 4 (byte offset)
    mov.l @(r0, r4), r2           ! r2 = table_a[mode*2+1] (pass B params)
    mov.l r2, @(8, r15)           ! sp+0x08 = pass_b_params
    ! --- Load 4 dispatch arrays from dispatch_table_b ---
    mov.l   _pool_dispatch_table_b, r4  ! r4 = dispatch_table_b base (sym_06062260)
    mov.l @r14, r0                ! r0 = player_mode
    shll2 r0                      ! r0 = mode * 4
    shll2 r0                      ! r0 = mode * 16 (byte offset, 4 longs per mode)
    mov.l @(r0, r4), r1           ! r1 = table_b[mode*4+0] (vis_array_a)
    mov.l r1, @(16, r15)          ! sp+0x10 = vis_array_a
    mov.l @r14, r5                ! r5 = player_mode (reload)
    shll2 r5                      ! r5 = mode * 4
    mov r5, r0                    ! r0 = mode * 4
    add #0x1, r0                  ! r0 = mode*4 + 1
    shll2 r0                      ! r0 = (mode*4+1) * 4 (byte offset)
    mov.l @(r0, r4), r3           ! r3 = table_b[mode*4+1] (offset_array)
    mov r5, r0                    ! r0 = mode * 4 (reload)
    mov.l r3, @(28, r15)          ! sp+0x1C = offset_array
    add #0x2, r0                  ! r0 = mode*4 + 2
    shll2 r0                      ! r0 = (mode*4+2) * 4 (byte offset)
    mov.l @(r0, r4), r2           ! r2 = table_b[mode*4+2] (vis_array_c)
    mov r5, r0                    ! r0 = mode * 4 (reload)
    mov.l r2, @(24, r15)          ! sp+0x18 = vis_array_c
    add #0x3, r0                  ! r0 = mode*4 + 3
    shll2 r0                      ! r0 = (mode*4+3) * 4 (byte offset)
    mov.l @(r0, r4), r1           ! r1 = table_b[mode*4+3] (vis_array_d)
    mov.l r1, @(20, r15)          ! sp+0x14 = vis_array_d
    ! --- Compute column range from camera orientation ---
    mov.l   _pool_cam_orient_data, r5   ! r5 = &orient_data (sym_06063DF8, cam XYZ)
    mov.l   _pool_column_rounding, r3   ! r3 = 0x04000000 (rounding bias for >>21)
    mov.l @r5, r4                 ! r4 = orient[0] (camera yaw angle)
    add r3, r4                    ! r4 = yaw + rounding bias
    shlr16 r4                     ! r4 >>= 16
    shlr2 r4                      ! r4 >>= 2
    shlr2 r4                      ! r4 >>= 2
    shlr r4                       ! r4 >>= 1 (total >>21: start_col, 0..0x3F)
    mov.l @(8, r5), r2            ! r2 = orient[2] (FOV / extent)
    neg r2, r2                    ! r2 = -extent
    add #-0x1, r3                 ! r3 = 0x03FFFFFF (round-up mask)
    add r3, r2                    ! r2 = -extent + 0x03FFFFFF (round up)
    mov r2, r5                    ! r5 = rounded extent
    shlr16 r5                     ! r5 >>= 16
    mov #0x40, r3                 ! r3 = 0x40 (default outer_limit: 64 steps)
    shlr2 r5                      ! r5 >>= 2
    shlr2 r5                      ! r5 >>= 2
    shlr r5                       ! r5 >>= 1 (total >>21: end_col, 0..0x3F)
    ! --- Combine into col_base_idx = end_col*64 + start_col ---
    mov r5, r2                    ! r2 = end_col
    mov r5, r0                    ! r0 = end_col (for boundary check)
    shll2 r2                      ! r2 *= 4
    shll2 r2                      ! r2 *= 4
    shll2 r2                      ! r2 *= 4 (total: end_col * 64)
    add r4, r2                    ! r2 = end_col*64 + start_col
    mov.l r2, @(32, r15)          ! sp+0x20 = col_base_idx
    mov.l r3, @(36, r15)          ! sp+0x24 = outer_limit = 0x40
    mov #-0x1, r3                 ! r3 = -1
    mov.l r3, @(40, r15)          ! sp+0x28 = inner_limit = -1
    mov #0x1, r3                  ! r3 = 1
    mov.l r3, @(12, r15)          ! sp+0x0C = inner_step = 1
    ! --- Clamp end_col at high boundary (0x3F) ---
    cmp/eq #0x3F, r0              ! end_col == 0x3F?
    bf/s    .L_check_end_col_zero ! if not, check if end_col is zero
    mov #-0x40, r6                ! (delay) r6 = -0x40 (default outer step = -64)
    mov #0x0, r2                  ! end_col at max: clear outer_limit
    bra     .L_check_start_col    ! skip to start_col check
    mov.l r2, @(36, r15)          ! (delay) sp+0x24 = outer_limit = 0 (no outer loop)
.L_check_end_col_zero:
    tst r5, r5                    ! end_col == 0?
    bf      .L_check_start_col    ! if nonzero, proceed to start_col check
    mov #0x0, r6                  ! end_col is zero: outer step = 0
.L_check_start_col:
    mov r4, r0                    ! r0 = start_col
    cmp/eq #0x3F, r0              ! start_col == 0x3F?
    bf      .L_check_start_zero   ! if not, check if start_col is zero
    mov #0x0, r2                  ! start_col at max: clear inner_step
    bra     .L_load_render_param  ! skip to render param load
    mov.l r2, @(12, r15)          ! (delay) sp+0x0C = inner_step = 0
    .2byte  0xFFFF                ! alignment padding
_pool_player_mode_ptr:
    .4byte  sym_0607EAD8          ! player/scene mode index (0=single, 2=attract)
_pool_car_state_ptr:
    .4byte  sym_0607E944          ! current car state pointer
_pool_scene_depth_param:
    .4byte  sym_06063F54          ! scene depth parameter (written each frame)
_pool_dispatch_table_a:
    .4byte  sym_06062248          ! render target table A (2 entries per mode)
_pool_dispatch_table_b:
    .4byte  sym_06062260          ! segment index table B (4 entries per mode)
_pool_cam_orient_data:
    .4byte  sym_06063DF8          ! camera orientation/position XYZ
_pool_column_rounding:
    .4byte  0x04000000            ! angle-to-column rounding bias (for >>21)
.L_check_start_zero:
    tst r4, r4                    ! start_col == 0?
    bf      .L_load_render_param  ! if nonzero, proceed normally
    mov #0x0, r3                  ! start_col is zero: clear inner_limit
    mov.l r3, @(40, r15)          ! sp+0x28 = inner_limit = 0
.L_load_render_param:
    mov.l   _pool_render_param_ptr, r10 ! r10 = &render_param (sym_06089E96, persistent)
    bra     .L_outer_loop_test    ! jump to outer loop condition check
    mov.l r6, @r15                ! (delay) sp+0x00 = outer_step
    ! === Outer loop: iterate rows (step by +/-64 or 0) ===
.L_outer_loop_body:
    mov.l @(40, r15), r12         ! r12 = inner_limit (initial column counter)
    mov.l @r15, r9                ! r9 = outer_step (row stride)
    mov.l @(32, r15), r3          ! r3 = col_base_idx
    mov.l @(12, r15), r2          ! r2 = inner_step (+1 or 0)
    add r12, r9                   ! r9 = outer_step + inner_limit (cell start)
    cmp/gt r2, r12                ! inner_limit > inner_step? (loop guard)
    bt/s    .L_advance_outer      ! if so, skip inner loop (no columns to process)
    add r3, r9                    ! (delay) r9 += col_base_idx (absolute cell index)
    ! === Inner loop: iterate columns within current row ===
.L_inner_loop_body:
    mov r9, r11                   ! r11 = current cell index (for pipeline addr)
    mov r9, r4                    ! r4 = cell index (for array lookups)
    mov.l @(16, r15), r7          ! r7 = vis_array_a base
    mov.l @(24, r15), r3          ! r3 = vis_array_c base
    shll r4                       ! r4 = cell_index * 2 (halfword offset)
    add r4, r7                    ! r7 = &vis_array_a[cell_index]
    add r3, r4                    ! r4 = &vis_array_c[cell_index]
    mov.w @r7, r7                 ! r7 = vis_entry_a (pass A visibility, signed)
    exts.w r7, r2                 ! r2 = sign-extend vis_entry_a
    cmp/pl r2                     ! vis_entry_a > 0? (cell visible for pass A?)
    bf/s    .L_check_pass_b       ! if not visible, skip pass A
    mov.w @r4, r13                ! (delay) r13 = vis_entry_b (pass B visibility)
    ! --- Pass A: compute pipeline address ---
    mov r11, r0                   ! r0 = cell index
    mov.l @(28, r15), r2          ! r2 = offset_array base
    mov.l @r14, r8                ! r8 = player_mode
    mov.l   _pool_pipeline_state, r3    ! r3 = pipeline_state array base (sym_06062230)
    shll2 r0                      ! r0 = cell_index * 4 (long offset into offset_array)
    shll2 r8                      ! r8 = mode * 4
    mov.l @(r0, r2), r0           ! r0 = offset_array[cell_index] (pipeline offset)
    shll r8                       ! r8 = mode * 8
    add r3, r8                    ! r8 = &pipeline_state[mode*2]
    mov.l @r8, r8                 ! r8 = pipeline_state[mode*2] (pass A base addr)
    add r0, r8                    ! r8 = base + offset (pass A pipeline address)
    ! --- Dispatch pass A render function by mode ---
    mov.l @r14, r0                ! r0 = player_mode
    cmp/eq #0x2, r0               ! mode == 2 (attract)?
    bt      .L_pass_a_mode_2      ! if so, use scene_proc_c entry
    ! --- Mode 0/1: call pass A vertex xform (sym_06029BF4) ---
    mov.w @r10, r6                ! r6 = *render_param (halfword)
    mov.l @(4, r15), r5           ! r5 = pass_a_params
    mov.l   _pool_fn_vtx_xform_a, r3   ! r3 = sym_06029BF4 (pass A vertex xform)
    jsr @r3                       ! call vertex transform pipeline A
    mov r8, r4                    ! (delay) r4 = pipeline address
    bra     .L_check_pass_b       ! skip mode 2 path
    nop                           ! delay slot (nop)
.L_pass_a_mode_2:
    ! --- Mode 2: call pass A face projection (sym_0602B328, scene_proc_c) ---
    mov.w @r10, r6                ! r6 = *render_param (halfword)
    mov.l @(4, r15), r5           ! r5 = pass_a_params
    mov.l   _pool_fn_face_proj_a, r3    ! r3 = sym_0602B328 (face projection A)
    jsr @r3                       ! call face projection pipeline A
    mov r8, r4                    ! (delay) r4 = pipeline address
.L_check_pass_b:
    ! --- Check pass B visibility ---
    exts.w r13, r2                ! r2 = sign-extend vis_entry_b
    cmp/pl r2                     ! vis_entry_b > 0? (cell visible for pass B?)
    bf      .L_next_inner         ! if not visible, skip pass B
    ! --- Pass B: compute pipeline address ---
    mov r11, r0                   ! r0 = cell index
    mov.l @(20, r15), r1          ! r1 = vis_array_d base
    mov.l @r14, r2                ! r2 = player_mode
    mov.l   _pool_pipeline_state, r3    ! r3 = pipeline_state array base (sym_06062230)
    shll2 r0                      ! r0 = cell_index * 4 (long offset)
    shll r2                       ! r2 = mode * 2
    add #0x1, r2                  ! r2 = mode*2 + 1 (pass B slot)
    shll2 r2                      ! r2 = (mode*2+1) * 4 (byte offset)
    add r3, r2                    ! r2 = &pipeline_state[mode*2+1]
    mov.l @r2, r11                ! r11 = pipeline_state[mode*2+1] (pass B base)
    mov.l @(r0, r1), r2           ! r2 = vis_array_d[cell_index] (pass B offset)
    ! --- Dispatch pass B render function by mode ---
    mov.l @r14, r0                ! r0 = player_mode
    cmp/eq #0x2, r0               ! mode == 2?
    bt/s    .L_pass_b_mode_2      ! if so, use frustum cull variant
    add r2, r11                   ! (delay) r11 = base + offset (pass B pipeline addr)
    ! --- Mode 0/1: call pass B vertex xform (sym_0602A834) ---
    mov r13, r7                   ! r7 = vis_entry_b (pass B vis value)
    mov.w @r10, r6                ! r6 = *render_param (halfword)
    mov.l @(8, r15), r5           ! r5 = pass_b_params
    mov.l   _pool_fn_vtx_xform_b, r3   ! r3 = sym_0602A834 (pass B vertex xform)
    jsr @r3                       ! call vertex transform pipeline B
    mov r11, r4                   ! (delay) r4 = pipeline address
    bra     .L_next_inner         ! done with this cell
    nop                           ! delay slot (nop)
    .2byte  0xFFFF                ! alignment padding
_pool_render_param_ptr:
    .4byte  sym_06089E96          ! render parameter word (halfword)
_pool_pipeline_state:
    .4byte  sym_06062230          ! pipeline state array (base addrs per mode)
_pool_fn_vtx_xform_a:
    .4byte  sym_06029BF4          ! pass A vertex xform (mega_render_func entry)
_pool_fn_face_proj_a:
    .4byte  sym_0602B328          ! pass A face projection (scene_proc_c entry)
_pool_fn_vtx_xform_b:
    .4byte  sym_0602A834          ! pass B vertex xform (mega_render_func entry)
.L_pass_b_mode_2:
    ! --- Mode 2: call pass B frustum cull (sym_0602AF3C, scene_proc_b) ---
    mov r13, r7                   ! r7 = vis_entry_b (pass B vis value)
    mov.w @r10, r6                ! r6 = *render_param (halfword)
    mov.l @(8, r15), r5           ! r5 = pass_b_params
    mov.l   _pool_fn_frustum_cull_b, r3 ! r3 = sym_0602AF3C (frustum cull B)
    jsr @r3                       ! call frustum cull pipeline B
    mov r11, r4                   ! (delay) r4 = pipeline address
.L_next_inner:
    ! --- Advance inner loop counter ---
    add #0x1, r12                 ! r12++ (next column)
    mov.l @(12, r15), r2          ! r2 = inner_step
    cmp/gt r2, r12                ! inner_counter > inner_step? (done with row?)
    bf/s    .L_inner_loop_body    ! if not, continue inner loop
    add #0x1, r9                  ! (delay) r9++ (advance cell index)
.L_advance_outer:
    ! --- Advance outer loop ---
    mov.l @r15, r2                ! r2 = outer_step
    add #0x40, r2                 ! r2 += 0x40 (advance by 64: next row boundary)
    mov.l r2, @r15                ! sp+0x00 = updated outer_step
.L_outer_loop_test:
    mov.l @r15, r3                ! r3 = outer_step (current row position)
    mov.l @(36, r15), r2          ! r2 = outer_limit
    cmp/gt r2, r3                 ! outer_step > outer_limit? (all rows done?)
    bf      .L_outer_loop_body    ! if not, process next row
    ! === Grid iteration complete -- post-processing ===
    mov.l   _pool_game_state_flags, r2  ! r2 = &game_state_flags (sym_0607EBC4)
    mov.l   _pool_state_check_mask, r3  ! r3 = 0x30000000 (bits 28-29 mask)
    mov.l @r2, r2                 ! r2 = *game_state_flags
    and r3, r2                    ! r2 = flags & 0x30000000
    tst r2, r2                    ! any of bits 28-29 set?
    bf      .L_epilogue_rts       ! if set, skip post-processing and return
    bra     .L_mode_dispatch      ! otherwise, dispatch by mode
    mov.l @r14, r0                ! (delay) r0 = player_mode
    ! --- Mode 0: call track_geometry_proc ---
.L_mode_0_dispatch:
    mov.l   _pool_fn_track_geom, r3     ! r3 = track_geometry_proc
    jsr @r3                       ! call track geometry animation processor
    nop                           ! delay slot (nop)
    bra     .L_epilogue_tailcall  ! proceed to tail call
    nop                           ! delay slot (nop)
    ! --- Mode 1: call track_state_machine ---
.L_mode_1_dispatch:
    mov.l   _pool_fn_track_state, r3    ! r3 = track_state_machine
    jsr @r3                       ! call track state transition handler
    nop                           ! delay slot (nop)
    bra     .L_epilogue_tailcall  ! proceed to tail call
    nop                           ! delay slot (nop)
    ! --- Mode 2: call geom_math_calc ---
.L_mode_2_dispatch:
    mov.l   _pool_fn_geom_math, r3     ! r3 = geom_math_calc
    jsr @r3                       ! call geometry math processor
    nop                           ! delay slot (nop)
    bra     .L_epilogue_tailcall  ! proceed to tail call
    nop                           ! delay slot (nop)
    ! --- Mode dispatch switch ---
.L_mode_dispatch:
    cmp/eq #0x0, r0               ! mode == 0?
    bt      .L_mode_0_dispatch    ! if so, dispatch to track_geometry_proc
    cmp/eq #0x1, r0               ! mode == 1?
    bt      .L_mode_1_dispatch    ! if so, dispatch to track_state_machine
    cmp/eq #0x2, r0               ! mode == 2?
    bt      .L_mode_2_dispatch    ! if so, dispatch to geom_math_calc
    ! --- Epilogue: tail-call to scene_process_stage ---
.L_epilogue_tailcall:
    add #0x2C, r15                ! deallocate 44-byte stack frame
    lds.l @r15+, pr               ! restore return address
    mov.l @r15+, r8               ! restore callee-saved registers
    mov.l @r15+, r9               ! restore r9
    mov.l @r15+, r10              ! restore r10
    mov.l @r15+, r11              ! restore r11
    mov.l @r15+, r12              ! restore r12
    mov.l @r15+, r13              ! restore r13
    mov.l   _pool_fn_scene_entity, r3   ! r3 = scene_process_stage
    jmp @r3                       ! tail-call scene entity renderer
    mov.l @r15+, r14              ! (delay) restore r14
    ! --- Epilogue: return directly (bits 28-29 set) ---
.L_epilogue_rts:
    add #0x2C, r15                ! deallocate 44-byte stack frame
    lds.l @r15+, pr               ! restore return address
    mov.l @r15+, r8               ! restore callee-saved registers
    mov.l @r15+, r9               ! restore r9
    mov.l @r15+, r10              ! restore r10
    mov.l @r15+, r11              ! restore r11
    mov.l @r15+, r12              ! restore r12
    mov.l @r15+, r13              ! restore r13
    rts                           ! return to caller
    mov.l @r15+, r14              ! (delay) restore r14
_pool_fn_frustum_cull_b:
    .4byte  sym_0602AF3C          ! pass B frustum cull (scene_proc_b entry)
_pool_game_state_flags:
    .4byte  sym_0607EBC4          ! game state bitmask (checked for bits 28-29)
_pool_state_check_mask:
    .4byte  0x30000000            ! mask: bits 28-29 (skip post-processing if set)
_pool_fn_track_geom:
    .4byte  track_geometry_proc   ! mode 0 post-processing: track geometry animation
_pool_fn_track_state:
    .4byte  track_state_machine   ! mode 1 post-processing: track state transitions
_pool_fn_geom_math:
    .4byte  geom_math_calc        ! mode 2 post-processing: geometry math calc
_pool_fn_scene_entity:
    .4byte  scene_process_stage   ! tail-call: scene entity renderer
