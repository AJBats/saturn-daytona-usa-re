/* scene_path_b -- Scene render path B: spatial grid dispatch (extended range)
 * Translation unit: 0x06006CDC - 0x06006F3C
 *
 * Second scene rendering path, sibling to scene_path_a. Iterates an 11x11
 * spatial partition grid of scene objects and dispatches each visible cell
 * through a dual-pass vertex transform pipeline (pass A then pass B).
 *
 * The grid is indexed by camera heading angle. The camera heading (from
 * sym_06063EF0) is quantised to a 4-bit column index (0..15), which selects
 * a 242-byte row in the visibility table. Within each row, 11 columns are
 * scanned. The camera orientation data (sym_06063DF8) further determines
 * the start/end column range, with wrapping at boundaries 0x3B and 0x05.
 *
 * For each non-zero cell in the vis table, the value is used as an offset
 * into four dispatch arrays (vis_array_a/b/c/d) from dispatch_table_b.
 * Pass A visibility (vis_array_a) and pass B visibility (vis_array_c) are
 * each checked independently -- if positive, a render function is called.
 *
 * The player_mode variable (*sym_0607EAD8) selects the render variant:
 *   mode 0 or 1: sym_0602ABB8 (scene_process_b -- depth sort + vertex xform)
 *   mode 2:      sym_0602B9E0 (scene_proc_d -- frustum cull variant)
 *
 * Each render call receives:
 *   r4 = pipeline_addr (base + offset from pipeline_state array)
 *   r5 = pass_params (from dispatch_table_a)
 *   r6 = render_param (16-bit, from sym_06089E96)
 *   r7 = vis_value (sign-extended, clamped to wrap limit 0x0640)
 *
 * Stack frame (0x3C = 60 bytes):
 *   sp+0x00: col_base_idx      (end_col*64 + start_col from orient data)
 *   sp+0x04: inner_counter     (current column within row)
 *   sp+0x08: outer_counter     (current row)
 *   sp+0x0C: pass_a_params     (dispatch_table_a[player_mode*2])
 *   sp+0x10: pass_b_params     (dispatch_table_a[player_mode*2+1])
 *   sp+0x14: pipeline_addr     (computed render pipeline base for cell)
 *   sp+0x18: vis_array_d       (dispatch_table_b[player_mode*4+3])
 *   sp+0x1C: inner_limit       (max columns per row, default 0xB)
 *   sp+0x20: row_base          (outer_counter * 0xB)
 *   sp+0x24: vis_table_ptr     (heading_col * 242 + base + offset)
 *   sp+0x28: vis_array_a       (dispatch_table_b[player_mode*4+0])
 *   sp+0x2C: vis_array_c       (dispatch_table_b[player_mode*4+2])
 *   sp+0x30: offset_array      (dispatch_table_b[player_mode*4+1])
 *   sp+0x34: col_start_offset  (default 0, clamped at boundary)
 *   sp+0x38: outer_limit       (max rows, default 0xB)
 *
 * Persistent registers:
 *   r8  = &render_param (sym_06089E96, halfword)
 *   r10 = &sort_buf_write_idx (sym_060620D4)
 *   r13 = &player_mode (sym_0607EAD8)
 *   r14 = 0x0640 (1600, vis entry wrap limit)
 */

    .section .text.FUN_06006CDC


    .global scene_path_b
    .type scene_path_b, @function
scene_path_b:
    mov.l r14, @-r15              ! save callee-saved registers
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15               ! save return address
    sts.l macl, @-r15             ! save MAC low (used by mul.l)
    add #-0x3C, r15               ! allocate 60-byte stack frame
    ! --- Load persistent register values ---
    mov.l   .L_sort_buf_idx_ptr, r10  ! r10 = &sort_buf_write_idx (persist)
    mov.l   .L_player_mode_ptr, r13   ! r13 = &player_mode (persist)
    mov.w   DAT_06006da6, r14    ! r14 = 0x0640 (vis wrap limit, persist)
    ! --- Compute heading column index from camera heading ---
    mov.l   .L_cam_heading_ptr, r4    ! r4 = &cam_heading
    mov.w   .L_heading_bias, r3  ! r3 = 0x0800 (heading rounding bias)
    mov.l   .L_mask_low16, r2    ! r2 = 0x0000FFFF (16-bit mask)
    mov.l   .L_dispatch_table_a, r5   ! r5 = dispatch_table_a base
    mov.l @r13, r0                ! r0 = player_mode
    mov.l @r4, r4                 ! r4 = *cam_heading (raw angle value)
    shll2 r0                      ! r0 = player_mode * 4
    add r3, r4                    ! r4 = heading + 0x0800 (bias for rounding)
    shll r0                       ! r0 = player_mode * 8 (byte offset into table_a)
    and r2, r4                    ! r4 = (heading + bias) & 0xFFFF (low 16 bits)
    ! --- Load pass A params from dispatch_table_a ---
    mov.l @(r0, r5), r3          ! r3 = table_a[player_mode*2] (pass A params)
    shlr8 r4                      ! r4 >>= 8 (continue heading quantisation)
    mov.l r3, @(12, r15)         ! sp+0x0C = pass_a_params
    shlr2 r4                      ! r4 >>= 2
    ! --- Load pass B params from dispatch_table_a ---
    mov.l @r13, r0                ! r0 = player_mode (reload)
    shlr2 r4                      ! r4 >>= 2 (total >>12: heading_col = 0..15)
    shll r0                       ! r0 = player_mode * 2
    add #0x1, r0                  ! r0 = player_mode * 2 + 1
    shll2 r0                      ! r0 = (player_mode*2+1) * 4 (byte offset)
    mov.l @(r0, r5), r2          ! r2 = table_a[player_mode*2+1] (pass B params)
    mov.l r2, @(16, r15)         ! sp+0x10 = pass_b_params
    ! --- Compute vis table pointer from heading column ---
    mov.w   .L_row_stride, r1    ! r1 = 0x00F2 (242 bytes per heading row)
    mul.l r1, r4                  ! macl = heading_col * 242
    sts macl, r4                  ! r4 = heading_col * row_stride
    mov.l   .L_vis_table_base_offset, r0  ! r0 = 0x002F0000 (base addr offset)
    add r0, r4                    ! r4 += base offset
    mov.w   .L_vis_table_extra_offset, r1  ! r1 = 0x2000 (extra offset)
    add r1, r4                    ! r4 += extra offset
    mov.l r4, @(36, r15)         ! sp+0x24 = vis_table_ptr
    ! --- Load 4 dispatch arrays from dispatch_table_b ---
    mov.l   .L_dispatch_table_b, r4   ! r4 = dispatch_table_b base (16-byte stride)
    mov.l @r13, r0                ! r0 = player_mode
    shll2 r0                      ! r0 = player_mode * 4
    shll2 r0                      ! r0 = player_mode * 16 (byte offset)
    mov.l @(r0, r4), r1          ! r1 = table_b[player_mode*4+0] (vis_array_a)
    mov.l r1, @(40, r15)         ! sp+0x28 = vis_array_a
    mov.l @r13, r5                ! r5 = player_mode (reload)
    shll2 r5                      ! r5 = player_mode * 4
    mov r5, r0
    add #0x1, r0                  ! r0 = player_mode*4 + 1
    shll2 r0                      ! r0 = (player_mode*4+1) * 4
    mov.l @(r0, r4), r3          ! r3 = table_b[player_mode*4+1] (offset_array)
    mov.l r3, @(48, r15)         ! sp+0x30 = offset_array
    mov r5, r0
    add #0x2, r0                  ! r0 = player_mode*4 + 2
    shll2 r0                      ! r0 = (player_mode*4+2) * 4
    mov.l @(r0, r4), r2          ! r2 = table_b[player_mode*4+2] (vis_array_c)
    mov.l r2, @(44, r15)         ! sp+0x2C = vis_array_c
    mov r5, r0
    add #0x3, r0                  ! r0 = player_mode*4 + 3
    shll2 r0                      ! r0 = (player_mode*4+3) * 4
    mov.l @(r0, r4), r1          ! r1 = table_b[player_mode*4+3] (vis_array_d)
    mov.l r1, @(24, r15)         ! sp+0x18 = vis_array_d
    ! --- Compute column range from camera orientation ---
    mov.l   .L_cam_orient_data, r5    ! r5 = &orient_data (cam position XYZ)
    mov.l   .L_column_rounding, r3    ! r3 = 0x04000000 (rounding bias)
    mov.l @r5, r4                 ! r4 = orient[0] (camera yaw angle)
    mov.l @(8, r5), r2           ! r2 = orient[2] (FOV/extent)
    add r3, r4                    ! r4 = yaw + rounding bias
    neg r2, r2                    ! r2 = -extent
    shlr16 r4                     ! r4 >>= 16 (begin angle-to-column conversion)
    add #-0x1, r3                 ! r3 = 0x03FFFFFF (rounding mask)
    shlr2 r4                      ! r4 >>= 2
    add r3, r2                    ! r2 = -extent + 0x03FFFFFF (round up)
    shlr2 r4                      ! r4 >>= 2
    mov r2, r5                    ! r5 = rounded extent (for end_col calc)
    shlr r4                       ! r4 >>= 1 (total >>21: start_col)
    shlr16 r5                     ! r5 >>= 16 (begin extent-to-column)
    shlr2 r5                      ! r5 >>= 2
    shlr2 r5                      ! r5 >>= 2
    shlr r5                       ! r5 >>= 1 (total >>21: end_col)
    ! --- Combine into col_base_idx = end_col*64 + start_col ---
    mov r5, r2                    ! r2 = end_col
    shll2 r2                      ! r2 *= 4
    shll2 r2                      ! r2 *= 4
    shll2 r2                      ! r2 *= 4 (total: end_col * 64)
    add r4, r2                    ! r2 = end_col*64 + start_col
    mov.l r2, @r15                ! sp+0x00 = col_base_idx
    ! --- Initialize loop defaults ---
    mov #0x0, r3
    mov.l r3, @(52, r15)         ! sp+0x34 = col_start_offset = 0
    mov r3, r6                    ! r6 = 0 (initial outer skip count)
    mov #0xB, r3                  ! r3 = 11 (grid dimension)
    mov.l r3, @(28, r15)         ! sp+0x1C = inner_limit = 11
    mov.l r3, @(56, r15)         ! sp+0x38 = outer_limit = 11
    ! --- Clamp end_col (r5) at high boundary ---
    mov #0x3B, r3                 ! r3 = 59 (high boundary threshold)
    cmp/hs r3, r5                 ! end_col >= 59?
    bf      .L_check_end_col_low  ! if not, check low boundary
    mov #0x45, r3                 ! r3 = 69 (wrap total)
    sub r5, r3                    ! r3 = 69 - end_col (wrapped limit)
    bra     .L_clamp_start_col    ! skip low check
    mov.l r3, @(56, r15)         ! (delay) sp+0x38 = outer_limit = 69 - end_col

    .global DAT_06006da6
DAT_06006da6:
    .2byte  0x0640
.L_heading_bias:
    .2byte  0x0800
.L_row_stride:
    .2byte  0x00F2
.L_vis_table_extra_offset:
    .2byte  0x2000
    .2byte  0xFFFF
.L_sort_buf_idx_ptr:
    .4byte  sym_060620D4                ! sort buffer write index
.L_player_mode_ptr:
    .4byte  sym_0607EAD8                ! player mode (0=single, 2=attract)
.L_cam_heading_ptr:
    .4byte  sym_06063EF0                ! camera heading angle
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_dispatch_table_a:
    .4byte  sym_06062248                ! pass A/B param table (2 entries per mode)
.L_vis_table_base_offset:
    .4byte  0x002F0000                  /* vis table base address offset */
.L_dispatch_table_b:
    .4byte  sym_06062260                ! vis/offset arrays (4 entries per mode)
.L_cam_orient_data:
    .4byte  sym_06063DF8                ! camera orientation/position XYZ
.L_column_rounding:
    .4byte  0x04000000                  /* angle-to-column rounding bias */
    ! --- Clamp end_col at low boundary ---
.L_check_end_col_low:
    mov #0x5, r3                  ! r3 = 5 (low boundary threshold)
    cmp/hs r3, r5                 ! end_col >= 5?
    bt      .L_clamp_start_col    ! if so, no clamping needed
    mov #0x5, r6                  ! r6 = 5
    sub r5, r6                    ! r6 = 5 - end_col (outer skip count)
    ! --- Clamp start_col (r4) at high boundary ---
.L_clamp_start_col:
    mov #0x3B, r3                 ! r3 = 59 (high boundary)
    cmp/hs r3, r4                 ! start_col >= 59?
    bf      .L_check_start_col_low  ! if not, check low boundary
    mov #0x45, r3                 ! r3 = 69 (wrap total)
    sub r4, r3                    ! r3 = 69 - start_col (wrapped inner limit)
    bra     .L_ranges_ready       ! skip low check
    mov.l r3, @(28, r15)         ! (delay) sp+0x1C = inner_limit = 69 - start_col
    ! --- Clamp start_col at low boundary ---
.L_check_start_col_low:
    mov #0x5, r3                  ! r3 = 5 (low boundary threshold)
    cmp/hs r3, r4                 ! start_col >= 5?
    bt      .L_ranges_ready       ! if so, no clamping needed
    mov #0x5, r3                  ! r3 = 5
    sub r4, r3                    ! r3 = 5 - start_col (column start offset)
    mov.l r3, @(52, r15)         ! sp+0x34 = col_start_offset = 5 - start_col
    ! --- All range parameters set, enter outer loop ---
.L_ranges_ready:
    mov.l   .L_render_param_ptr, r8   ! r8 = &render_param (persist)
    bra     .L_outer_loop_test    ! jump to outer loop condition check
    mov.l r6, @(8, r15)          ! (delay) sp+0x08 = outer_counter = initial skip
    ! === Outer loop: iterate rows ===
.L_outer_loop_body:
    mov.l @(52, r15), r2         ! r2 = col_start_offset
    mov.l r2, @(4, r15)          ! sp+0x04 = inner_counter = col_start_offset
    mov.l @(8, r15), r3          ! r3 = outer_counter (current row)
    mov #0xB, r2                  ! r2 = 11 (columns per row)
    mul.l r2, r3                  ! macl = outer_counter * 11
    sts macl, r3                  ! r3 = row_base
    bra     .L_inner_loop_test    ! jump to inner loop condition check
    mov.l r3, @(32, r15)         ! (delay) sp+0x20 = row_base
    ! === Inner loop: iterate columns within current row ===
.L_inner_loop_body:
    mov.l @(32, r15), r0         ! r0 = row_base
    mov.l @(4, r15), r3          ! r3 = inner_counter
    mov.l @(36, r15), r2         ! r2 = vis_table_ptr
    add r3, r0                    ! r0 = row_base + inner_counter (cell index)
    shll r0                       ! r0 *= 2 (halfword offset into vis table)
    mov.w @(r0, r2), r9          ! r9 = vis_table[cell_index] (visibility flag)
    tst r9, r9                    ! vis == 0?
    bf      .L_cell_visible       ! if nonzero, process this cell
    bra     .L_next_column        ! skip empty cell
    nop
    ! --- Cell has a nonzero visibility entry ---
.L_cell_visible:
    ! --- Compute pass A visibility from vis_array_a ---
    exts.w r9, r4                 ! r4 = sign-extend vis value
    mov.l @r15, r3                ! r3 = col_base_idx
    mov.l @(40, r15), r12        ! r12 = vis_array_a base
    mov.l @(44, r15), r2         ! r2 = vis_array_c base
    add r3, r4                    ! r4 = vis + col_base_idx (combined index)
    shll r4                       ! r4 *= 2 (halfword offset)
    add r4, r12                   ! r12 = &vis_array_a[vis + col_base_idx]
    mov.w @r12, r12              ! r12 = vis_a (pass A visibility value)
    add r2, r4                    ! r4 = &vis_array_c[vis + col_base_idx]
    exts.w r12, r1                ! r1 = sign-extend vis_a
    cmp/pl r1                     ! vis_a > 0?
    bf/s    .L_pass_a_done        ! if not visible, skip pass A
    mov.w @r4, r11               ! (delay) r11 = vis_b (pass B visibility value)
    ! --- Pass A: compute pipeline address and dispatch ---
    exts.w r9, r0                 ! r0 = sign-extend vis
    mov.l @r15, r3                ! r3 = col_base_idx
    mov.l @(48, r15), r2         ! r2 = offset_array base
    mov.l @r13, r1                ! r1 = player_mode
    add r3, r0                    ! r0 = vis + col_base_idx
    shll2 r1                      ! r1 = player_mode * 4
    shll2 r0                      ! r0 = (vis + col_base) * 4 (long offset)
    mov.l   .L_pipeline_state_arr, r3  ! r3 = pipeline_state array base
    shll r1                       ! r1 = player_mode * 8
    mov.l @(r0, r2), r0          ! r0 = offset_array[vis + col_base] (offset)
    add r3, r1                    ! r1 = &pipeline_state[player_mode*2]
    exts.w r12, r3                ! r3 = sign-extend vis_a (for clamp check)
    mov.l @r1, r1                 ! r1 = pipeline_state[player_mode*2] (pass A base)
    add r1, r0                    ! r0 = base + offset (pipeline address)
    mov.l r0, @(20, r15)         ! sp+0x14 = pipeline_addr
    ! --- Clamp vis_a to wrap limit (0x0640) ---
    mov.l @r10, r1                ! r1 = *sort_buf_write_idx
    add r1, r3                    ! r3 = vis_a + sort_buf_idx
    cmp/hs r14, r3               ! (vis_a + idx) >= 0x0640?
    bf      .L_pass_a_no_wrap     ! if not, no wrapping needed
    mov.l @r10, r2                ! r2 = *sort_buf_write_idx
    mov r14, r12                  ! r12 = 0x0640 (wrap limit)
    sub r2, r12                   ! r12 = 0x0640 - sort_buf_idx (clamped vis_a)
    exts.w r12, r12              ! sign-extend clamped value
    ! --- Dispatch pass A render function ---
.L_pass_a_no_wrap:
    mov.l @r13, r0                ! r0 = player_mode
    cmp/eq #0x2, r0              ! player_mode == 2 (attract)?
    bt      .L_pass_a_mode_2      ! if so, use frustum cull variant
    ! --- Mode 0/1: call scene_process_b (depth sort + vertex xform) ---
    exts.w r12, r7                ! r7 = vis_a (clamped, sign-extended)
    mov.w @r8, r6                 ! r6 = *render_param (halfword)
    mov.l @(12, r15), r5         ! r5 = pass_a_params
    mov.l   .L_fn_scene_process_b, r3  ! r3 = &scene_process_b
    extu.w r6, r6                 ! r6 = zero-extend render_param to 32 bits
    jsr @r3                       ! call scene_process_b(r4, r5, r6, r7)
    mov.l @(20, r15), r4         ! (delay) r4 = pipeline_addr
    bra     .L_pass_a_done        ! skip mode 2 path
    nop
    .2byte  0xFFFF
.L_render_param_ptr:
    .4byte  sym_06089E96                ! render parameter word (halfword)
.L_pipeline_state_arr:
    .4byte  sym_06062230                ! pipeline state array (base addrs per mode)
.L_fn_scene_process_b:
    .4byte  sym_0602ABB8                ! scene_process_b (depth sort + vertex xform)
    ! --- Mode 2: call scene_proc_d (frustum cull variant) ---
.L_pass_a_mode_2:
    exts.w r12, r7                ! r7 = vis_a (clamped, sign-extended)
    mov.w @r8, r6                 ! r6 = *render_param (halfword)
    mov.l @(12, r15), r5         ! r5 = pass_a_params
    mov.l   .L_fn_scene_proc_d, r3    ! r3 = &scene_proc_d
    extu.w r6, r6                 ! r6 = zero-extend render_param
    jsr @r3                       ! call scene_proc_d(r4, r5, r6, r7)
    mov.l @(20, r15), r4         ! (delay) r4 = pipeline_addr
    ! --- Pass A complete, check pass B visibility ---
.L_pass_a_done:
    exts.w r11, r2                ! r2 = sign-extend vis_b
    cmp/pl r2                     ! vis_b > 0?
    bf      .L_next_column        ! if not visible, skip pass B
    ! --- Pass B: compute pipeline address ---
    exts.w r9, r0                 ! r0 = sign-extend vis
    mov.l @r15, r2                ! r2 = col_base_idx
    mov.l @r13, r12              ! r12 = player_mode
    mov.l   .L_pipeline_state_arr_b, r3  ! r3 = pipeline_state array base
    mov.l @(24, r15), r1         ! r1 = vis_array_d base
    add r2, r0                    ! r0 = vis + col_base_idx
    shll r12                      ! r12 = player_mode * 2
    shll2 r0                      ! r0 = (vis + col_base) * 4 (long offset)
    add #0x1, r12                ! r12 = player_mode*2 + 1 (pass B slot)
    shll2 r12                     ! r12 = (player_mode*2+1) * 4
    add r3, r12                   ! r12 = &pipeline_state[player_mode*2+1]
    mov.l @r12, r12              ! r12 = pipeline_state[player_mode*2+1] (pass B base)
    mov.l @(r0, r1), r3          ! r3 = vis_array_d[vis + col_base] (pass B offset)
    exts.w r11, r0                ! r0 = sign-extend vis_b (for clamp check)
    add r3, r12                   ! r12 = base + offset (pass B pipeline addr)
    ! --- Clamp vis_b to wrap limit (0x0640) ---
    mov.l @r10, r3                ! r3 = *sort_buf_write_idx
    add r3, r0                    ! r0 = vis_b + sort_buf_idx
    cmp/hs r14, r0               ! (vis_b + idx) >= 0x0640?
    bf      .L_pass_b_no_wrap     ! if not, no wrapping needed
    mov.l @r10, r3                ! r3 = *sort_buf_write_idx
    mov r14, r11                  ! r11 = 0x0640 (wrap limit)
    sub r3, r11                   ! r11 = 0x0640 - sort_buf_idx (clamped vis_b)
    exts.w r11, r11              ! sign-extend clamped value
    ! --- Dispatch pass B render function ---
.L_pass_b_no_wrap:
    mov.l @r13, r0                ! r0 = player_mode
    cmp/eq #0x2, r0              ! player_mode == 2 (attract)?
    bt      .L_pass_b_mode_2      ! if so, use frustum cull variant
    ! --- Mode 0/1: call scene_process_b for pass B ---
    exts.w r11, r7                ! r7 = vis_b (clamped, sign-extended)
    mov.w @r8, r6                 ! r6 = *render_param (halfword)
    mov.l @(16, r15), r5         ! r5 = pass_b_params
    mov.l   .L_fn_scene_process_b_2, r3  ! r3 = &scene_process_b
    extu.w r6, r6                 ! r6 = zero-extend render_param
    jsr @r3                       ! call scene_process_b(r4, r5, r6, r7)
    mov r12, r4                   ! (delay) r4 = pass B pipeline addr
    bra     .L_next_column        ! done with this cell
    nop
    ! --- Mode 2: call scene_proc_d for pass B ---
.L_pass_b_mode_2:
    exts.w r11, r7                ! r7 = vis_b (clamped, sign-extended)
    mov.w @r8, r6                 ! r6 = *render_param (halfword)
    mov.l @(16, r15), r5         ! r5 = pass_b_params
    mov.l   .L_fn_scene_proc_d, r3    ! r3 = &scene_proc_d
    extu.w r6, r6                 ! r6 = zero-extend render_param
    jsr @r3                       ! call scene_proc_d(r4, r5, r6, r7)
    mov r12, r4                   ! (delay) r4 = pass B pipeline addr
    ! --- Advance inner loop (next column) ---
.L_next_column:
    mov.l @(4, r15), r2          ! r2 = inner_counter
    add #0x1, r2                  ! r2++ (next column)
    mov.l r2, @(4, r15)          ! sp+0x04 = inner_counter
    ! --- Inner loop condition check ---
.L_inner_loop_test:
    mov.l @(4, r15), r3          ! r3 = inner_counter
    mov.l @(28, r15), r2         ! r2 = inner_limit
    cmp/hs r2, r3                ! inner_counter >= inner_limit?
    bf      .L_inner_loop_body    ! if not, continue inner loop
    ! --- Advance outer loop (next row) ---
    mov.l @(8, r15), r2          ! r2 = outer_counter
    add #0x1, r2                  ! r2++ (next row)
    mov.l r2, @(8, r15)          ! sp+0x08 = outer_counter
    ! --- Outer loop condition check ---
.L_outer_loop_test:
    mov.l @(8, r15), r3          ! r3 = outer_counter
    mov.l @(56, r15), r2         ! r2 = outer_limit
    cmp/hs r2, r3                ! outer_counter >= outer_limit?
    bt      .L_epilogue           ! if so, all rows processed
    bra     .L_outer_loop_body    ! continue outer loop
    nop
    ! --- Function epilogue: restore registers and return ---
.L_epilogue:
    add #0x3C, r15                ! deallocate 60-byte stack frame
    lds.l @r15+, macl             ! restore MAC low
    lds.l @r15+, pr               ! restore return address
    mov.l @r15+, r8               ! restore callee-saved registers
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts                           ! return to caller
    mov.l @r15+, r14             ! (delay) restore r14
    .2byte  0xFFFF
.L_fn_scene_proc_d:
    .4byte  sym_0602B9E0                ! scene_proc_d (frustum cull variant)
.L_pipeline_state_arr_b:
    .4byte  sym_06062230                ! pipeline state array (same as pass A)
.L_fn_scene_process_b_2:
    .4byte  sym_0602ABB8                ! scene_process_b (same fn, pass B pool ref)
