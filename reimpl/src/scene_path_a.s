/* scene_path_a -- Scene grid rendering dispatch (path A)
 * Translation unit: 0x06006A9C - 0x06006CDC
 *
 * Called from the secondary SH-2 render callback (race_utility_calc) when
 * sym_06063E1C + sym_06063E20 == 8. Iterates over a 2D grid of scene
 * sectors visible from the camera, reading segment indices from lookup
 * tables and dispatching each visible segment to polygon render functions.
 *
 * The camera position (from sym_06063DF8) is converted to a grid sector
 * index via fixed-point >>21 shift. Visibility bounds are clamped to the
 * grid range (0x00..0x3F). For each cell in the visible grid:
 *   1. Read segment index A from table (sym_06062260[mode*4 + 0])
 *   2. If positive: look up VDP1 offset, clip distance to 0x0640 (1600),
 *      and dispatch to render function A (sym_0602A214 or vdp1_list_finalize)
 *   3. Read segment index B from table (sym_06062260[mode*4 + 2])
 *   4. If positive: same clip + dispatch to render function B
 *      (sym_0602ABB8 or sym_0602B9E0)
 *
 * Mode index (*sym_0607EAD8) selects which table entries and render
 * functions to use. Mode 2 uses VDP1 list finalize path.
 *
 * Register plan:
 *   r8  = sym_060620D4 (scene render state -- distance offset at [r8])
 *   r9  = sym_06089E44 (scene render params -- VDP1 attrib at offset 0x52)
 *   r10 = outer loop counter (row position, steps by 0x40)
 *   r11 = segment index B (from second halfword table read)
 *   r12 = inner loop counter (column position)
 *   r13 = segment index A (from first halfword table read) / scratch
 *   r14 = &sym_0607EAD8 (scene mode index pointer)
 *
 * Stack frame (0x30 = 48 bytes):
 *   sp+0x00 = grid cell linear index
 *   sp+0x04 = table_a entry[mode*2+1] (render target B)
 *   sp+0x08 = VDP1 polygon base address (computed)
 *   sp+0x0C = table_a entry[mode*2+0] (render target A)
 *   sp+0x10 = outer loop limit (row_end * 0x40)
 *   sp+0x14 = table_b entry[mode*4+2] (segment index lookup C)
 *   sp+0x18 = table_b entry[mode*4+3] (segment index lookup D)
 *   sp+0x1C = grid base offset (row_start * 0x40 + col_start)
 *   sp+0x20 = table_b entry[mode*4+0] (segment index lookup A)
 *   sp+0x24 = table_b entry[mode*4+1] (segment offset lookup B)
 *   sp+0x28 = inner loop limit (col_end)
 *   sp+0x2C = inner loop start (col_start, negated if near edge)
 */

    .section .text.FUN_06006A9C


    .global scene_path_a
    .type scene_path_a, @function
scene_path_a:
    mov.l r14, @-r15                ! save callee-saved registers
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15                 ! save return address
    add #-0x30, r15                 ! allocate 48-byte stack frame
    mov.l   .L_render_state_base, r8 ! r8 = &sym_060620D4 (render state, distance offset)
    mov.l   .L_render_params, r9    ! r9 = &sym_06089E44 (render params, VDP1 attrib)
    mov.l   .L_scene_mode_ptr, r14  ! r14 = &sym_0607EAD8 (scene mode index ptr)
    mov.l   .L_table_a_base, r4    ! r4 = &sym_06062248 (render target table A)
    mov.l @r14, r0                  ! r0 = mode = *sym_0607EAD8
    shll2 r0                        ! r0 = mode * 4
    shll r0                         ! r0 = mode * 8 (longword table stride)
    mov.l @(r0, r4), r3            ! r3 = table_a[mode*2+0] (render target A)
    mov.l r3, @(12, r15)           ! sp[0x0C] = render_target_a
    mov.l @r14, r0                  ! r0 = mode
    shll r0                         ! r0 = mode * 2
    add #0x1, r0                    ! r0 = mode * 2 + 1
    shll2 r0                        ! r0 = (mode*2+1) * 4 (byte offset)
    mov.l @(r0, r4), r2            ! r2 = table_a[mode*2+1] (render target B)
    mov.l r2, @(4, r15)            ! sp[0x04] = render_target_b
    mov.l   .L_table_b_base, r4    ! r4 = &sym_06062260 (segment index table B)
    mov.l @r14, r0                  ! r0 = mode
    shll2 r0                        ! r0 = mode * 4
    shll2 r0                        ! r0 = mode * 16 (4 longwords per mode)
    mov.l @(r0, r4), r1            ! r1 = table_b[mode*4+0] (seg index lookup A)
    mov.l r1, @(32, r15)           ! sp[0x20] = seg_lookup_a
    mov.l @r14, r5                  ! r5 = mode
    shll2 r5                        ! r5 = mode * 4 (base index)
    mov r5, r0                      ! r0 = mode * 4
    add #0x1, r0                    ! r0 = mode * 4 + 1
    shll2 r0                        ! r0 = (mode*4+1) * 4 (byte offset)
    mov.l @(r0, r4), r3            ! r3 = table_b[mode*4+1] (seg offset lookup)
    mov r5, r0                      ! r0 = mode * 4
    mov.l r3, @(36, r15)           ! sp[0x24] = seg_offset_lookup
    add #0x2, r0                    ! r0 = mode * 4 + 2
    shll2 r0                        ! r0 = (mode*4+2) * 4 (byte offset)
    mov.l @(r0, r4), r2            ! r2 = table_b[mode*4+2] (seg index lookup C)
    mov r5, r0                      ! r0 = mode * 4
    mov.l r2, @(20, r15)           ! sp[0x14] = seg_lookup_c
    add #0x3, r0                    ! r0 = mode * 4 + 3
    shll2 r0                        ! r0 = (mode*4+3) * 4 (byte offset)
    mov.l @(r0, r4), r1            ! r1 = table_b[mode*4+3] (seg index lookup D)
    mov.l r1, @(24, r15)           ! sp[0x18] = seg_lookup_d
    ! --- Compute grid sector indices from camera position ---
    mov.l   .L_camera_state, r5    ! r5 = &sym_06063DF8 (camera/position state)
    mov.l   .L_grid_bias, r3      ! r3 = 0x04000000 (fixed-point grid bias)
    mov.l @r5, r4                   ! r4 = camera_state[0] (camera pos field A)
    add r3, r4                      ! r4 = pos_a + bias (ensure positive for shift)
    shlr16 r4                       ! r4 >>= 16
    shlr2 r4                        ! r4 >>= 2
    shlr2 r4                        ! r4 >>= 2
    shlr r4                         ! r4 >>= 1 (total >>21: fixed-pt to grid col)
    mov.l @(8, r5), r2             ! r2 = camera_state[2] (camera pos field B)
    neg r2, r2                      ! r2 = -pos_b (negate for reverse direction)
    add #-0x1, r3                   ! r3 = 0x03FFFFFF (bias - 1)
    add r3, r2                      ! r2 = -pos_b + (bias - 1)
    mov r2, r5                      ! r5 = biased reverse position
    shlr16 r5                       ! r5 >>= 16
    shlr2 r5                        ! r5 >>= 2
    shlr2 r5                        ! r5 >>= 2
    shlr r5                         ! r5 >>= 1 (total >>21: fixed-pt to grid row)
    mov #-0x2, r6                   ! r6 = -2 (default inner loop start offset)
    mov r5, r2                      ! r2 = row_sector
    mov r6, r3                      ! r3 = -2 (saved col start)
    shll2 r2                        ! r2 = row * 4
    shll2 r2                        ! r2 = row * 16
    shll2 r2                        ! r2 = row * 64 (0x40 = grid row stride)
    add r4, r2                      ! r2 = row * 64 + col (linear grid base)
    mov.l r2, @(28, r15)           ! sp[0x1C] = grid_base_offset
    mov.l r3, @(44, r15)           ! sp[0x2C] = inner_start = -2
    mov #0x2, r3                    ! r3 = 2 (default loop extent)
    mov.l r3, @(16, r15)           ! sp[0x10] = outer_limit = 2
    mov.l r3, @(40, r15)           ! sp[0x28] = inner_limit = 2
    ! --- Clamp row visibility to grid bounds (0x00..0x3F) ---
    mov #0x3E, r3                   ! r3 = 0x3E (62, near far edge)
    cmp/hs r3, r5                   ! row_sector >= 62?
    bf      .L_check_row_near_edge  ! no: check near-edge clamping
    mov #0x3F, r3                   ! r3 = 0x3F (63, max grid index)
    sub r5, r3                      ! r3 = 63 - row (remaining rows to edge)
    mov.l r3, @(16, r15)           ! sp[0x10] = outer_limit = clamped
    bra     .L_check_col_far_edge   ! skip near-edge check for row
    nop
.L_check_row_near_edge:
    mov #0x1, r2                    ! r2 = 1
    cmp/hi r2, r5                   ! row_sector > 1?
    bt      .L_check_col_far_edge   ! yes: no clamping needed
    neg r5, r6                      ! r6 = -row_sector (start from grid edge)
.L_check_col_far_edge:
    ! --- Clamp column visibility to grid bounds ---
    mov #0x3E, r2                   ! r2 = 0x3E (62)
    cmp/hs r2, r4                   ! col_sector >= 62?
    bf      .L_check_col_near_edge  ! no: check near-edge clamping
    mov #0x3F, r2                   ! r2 = 0x3F (63, max)
    sub r4, r2                      ! r2 = 63 - col (remaining cols to edge)
    bra     .L_scale_loop_bounds    ! store clamped inner limit
    mov.l r2, @(40, r15)           ! sp[0x28] = inner_limit = clamped (delay slot)
    .2byte  0xFFFF                      ! alignment padding
.L_render_state_base:
    .4byte  sym_060620D4                ! scene render state (distance offset at [0])
.L_render_params:
    .4byte  sym_06089E44                ! scene render params (VDP1 attrib at +0x52)
.L_scene_mode_ptr:
    .4byte  sym_0607EAD8                ! scene mode index (0, 1, or 2)
.L_table_a_base:
    .4byte  sym_06062248                ! render target table A (2 entries per mode)
.L_table_b_base:
    .4byte  sym_06062260                ! segment index table B (4 entries per mode)
.L_camera_state:
    .4byte  sym_06063DF8                ! camera position state (pos fields at +0, +8)
.L_grid_bias:
    .4byte  0x04000000                  ! fixed-point bias for grid sector conversion
.L_check_col_near_edge:
    mov #0x1, r2                    ! r2 = 1
    cmp/hi r2, r4                   ! col_sector > 1?
    bt      .L_scale_loop_bounds    ! yes: no clamping needed
    neg r4, r4                      ! r4 = -col_sector (start from grid edge)
    mov.l r4, @(44, r15)           ! sp[0x2C] = inner_start = -col_sector
.L_scale_loop_bounds:
    ! --- Scale loop bounds to row stride (multiply by 0x40) ---
    shll2 r6                        ! r6 *= 4
    shll2 r6                        ! r6 *= 4
    shll2 r6                        ! r6 *= 4 (total: *= 64 = row stride)
    mov.l @(16, r15), r3           ! r3 = outer_limit
    shll2 r3                        ! r3 *= 4
    shll2 r3                        ! r3 *= 4
    shll2 r3                        ! r3 *= 4 (total: *= 64)
    mov.l r3, @(16, r15)           ! sp[0x10] = outer_limit * 64
    bra     .L_outer_loop_test      ! enter outer loop
    mov r6, r10                     ! r10 = inner_start * 64 (outer counter init)
.L_outer_loop_body:
    bra     .L_inner_loop_test      ! enter inner loop test first
    mov.l @(44, r15), r12          ! r12 = inner_start (col offset, delay slot)
.L_inner_loop_body:
    ! --- Edge detection: only render cells at grid boundary rows/cols ---
    mov r10, r0                     ! r0 = outer counter (row offset)
    cmp/eq #-0x80, r0              ! row == -128 (= -2 * 64)?
    bt      .L_process_cell         ! yes: first visible row, process
    mov.w   DAT_06006c1e, r3       ! r3 = 0x0080 (+128 = +2 * 64)
    cmp/eq r3, r10                  ! row == +128?
    bt      .L_process_cell         ! yes: last visible row, process
    mov r12, r0                     ! r0 = inner counter (col offset)
    cmp/eq #-0x2, r0               ! col == -2?
    bt      .L_process_cell         ! yes: first visible col, process
    mov r12, r0                     ! r0 = inner counter
    cmp/eq #0x2, r0                ! col == +2?
    bf      .L_inner_loop_next      ! no: interior cell, skip rendering
    bra     .L_process_cell         ! yes: last visible col, process
    nop
.L_process_cell:
    ! --- Compute linear cell index and read segment indices ---
    mov r10, r2                     ! r2 = row_offset
    mov.l @(28, r15), r3           ! r3 = grid_base_offset
    add r12, r2                     ! r2 = row_offset + col_offset
    add r3, r2                      ! r2 = grid_base + row + col = cell_index
    mov r2, r4                      ! r4 = cell_index
    mov.l r2, @r15                  ! sp[0x00] = cell_index
    shll r4                         ! r4 = cell_index * 2 (halfword offset)
    mov.l @(32, r15), r13         ! r13 = seg_lookup_a base ptr
    mov.l @(20, r15), r3          ! r3 = seg_lookup_c base ptr
    add r4, r13                     ! r13 = &seg_lookup_a[cell_index]
    add r3, r4                      ! r4 = &seg_lookup_c[cell_index]
    mov.w @r13, r13                ! r13 = seg_index_a (signed halfword)
    exts.w r13, r2                  ! r2 = sign-extend seg_index_a
    cmp/pl r2                       ! seg_index_a > 0?
    bf/s    .L_check_seg_b          ! no: skip segment A rendering
    mov.w @r4, r11                 ! r11 = seg_index_b (delay slot, always read)
    ! --- Segment A: compute VDP1 polygon base address ---
    mov.l @r14, r3                  ! r3 = mode
    mov.l   .L_seg_offset_table, r2 ! r2 = &sym_06062230 (seg offset table)
    mov.l @r15, r0                  ! r0 = cell_index
    mov.l @(36, r15), r1          ! r1 = seg_offset_lookup base ptr
    shll2 r3                        ! r3 = mode * 4
    shll2 r0                        ! r0 = cell_index * 4 (longword offset)
    shll r3                         ! r3 = mode * 8 (offset table stride)
    mov.l @(r0, r1), r0           ! r0 = seg_offset[cell_index]
    add r2, r3                      ! r3 = &offset_table[mode*2]
    mov.l @r3, r3                  ! r3 = offset_table[mode*2] (base polygon addr)
    exts.w r13, r2                  ! r2 = seg_index_a (sign-extended)
    add r0, r3                      ! r3 = poly_base + seg_offset = VDP1 addr
    mov.l r3, @(8, r15)           ! sp[0x08] = vdp1_poly_addr
    ! --- Distance clipping for segment A ---
    mov.l @r8, r0                  ! r0 = render_state[0] (distance offset)
    add r0, r2                      ! r2 = seg_index_a + distance_offset
    mov.w   .L_max_distance, r0    ! r0 = 0x0640 (max render distance = 1600)
    cmp/hs r0, r2                   ! clipped_dist >= max?
    bf      .L_dispatch_render_a    ! no: use original seg_index_a
    mov.w   .L_max_distance, r13   ! r13 = 0x0640 (clamp to max)
    mov.l @r8, r3                  ! r3 = distance_offset
    sub r3, r13                     ! r13 = max - offset (clamped index)
    exts.w r13, r13                ! sign-extend clamped value
.L_dispatch_render_a:
    ! --- Dispatch render function A based on mode ---
    mov.l @r14, r0                  ! r0 = mode
    cmp/eq #0x2, r0                ! mode == 2?
    bt      .L_render_a_mode2       ! yes: use VDP1 list finalize
    exts.w r13, r7                  ! r7 = seg_index_a (render distance param)
    mov r9, r6                      ! r6 = render_params base
    mov.l @(12, r15), r5          ! r5 = render_target_a
    mov.l   .L_render_poly_a, r3   ! r3 = &sym_0602A214 (primary polygon render)
    add #0x52, r6                   ! r6 = &render_params[0x52] (VDP1 attrib)
    mov.w @r6, r6                  ! r6 = VDP1 attribute word
    extu.w r6, r6                   ! zero-extend to 32 bits
    jsr @r3                         ! call sym_0602A214(poly_addr, target, attrib, dist)
    mov.l @(8, r15), r4           ! r4 = vdp1_poly_addr (delay slot)
    bra     .L_check_seg_b          ! done with segment A
    nop

    .global DAT_06006c1e
DAT_06006c1e:
    .2byte  0x0080                      ! edge row threshold (+128 = +2 * 64)
.L_max_distance:
    .2byte  0x0640                      ! max render distance (1600)
    .2byte  0xFFFF                      ! alignment padding
.L_seg_offset_table:
    .4byte  sym_06062230                ! segment offset table (VDP1 polygon base)
.L_render_poly_a:
    .4byte  sym_0602A214                ! primary polygon render fn (modes 0,1)
.L_render_a_mode2:
    ! --- Mode 2: use VDP1 list finalize instead ---
    exts.w r13, r7                  ! r7 = seg_index_a (render distance param)
    mov r9, r6                      ! r6 = render_params base
    mov.l @(12, r15), r5          ! r5 = render_target_a
    mov.l   .L_vdp1_finalize_fn, r3 ! r3 = &vdp1_list_finalize
    add #0x52, r6                   ! r6 = &render_params[0x52] (VDP1 attrib)
    mov.w @r6, r6                  ! r6 = VDP1 attribute word
    extu.w r6, r6                   ! zero-extend to 32 bits
    jsr @r3                         ! call vdp1_list_finalize(poly_addr, target, attrib, dist)
    mov.l @(8, r15), r4           ! r4 = vdp1_poly_addr (delay slot)
.L_check_seg_b:
    ! --- Segment B: check if segment index is valid ---
    exts.w r11, r2                  ! r2 = sign-extend seg_index_b
    cmp/pl r2                       ! seg_index_b > 0?
    bf      .L_inner_loop_next      ! no: skip segment B rendering
    ! --- Segment B: compute VDP1 polygon base address ---
    exts.w r11, r1                  ! r1 = seg_index_b (sign-extended)
    mov.l @r14, r13                ! r13 = mode
    mov.l   .L_seg_offset_table_b, r3 ! r3 = &sym_06062230 (seg offset table)
    mov.l @r15, r0                  ! r0 = cell_index
    mov.l @(24, r15), r2          ! r2 = seg_lookup_d base ptr
    shll r13                        ! r13 = mode * 2
    shll2 r0                        ! r0 = cell_index * 4 (longword offset)
    add #0x1, r13                   ! r13 = mode * 2 + 1
    mov.l @(r0, r2), r0           ! r0 = seg_lookup_d[cell_index]
    shll2 r13                       ! r13 = (mode*2+1) * 4 (byte offset)
    add r3, r13                     ! r13 = &offset_table[mode*2+1]
    mov.l @r13, r13                ! r13 = offset_table[mode*2+1] (base polygon addr)
    add r0, r13                     ! r13 = poly_base + seg_offset = VDP1 addr B
    ! --- Distance clipping for segment B ---
    mov.l @r8, r0                  ! r0 = render_state[0] (distance offset)
    add r0, r1                      ! r1 = seg_index_b + distance_offset
    mov.w   DAT_06006cca, r0       ! r0 = 0x0640 (max render distance = 1600)
    cmp/hs r0, r1                   ! clipped_dist >= max?
    bf      .L_dispatch_render_b    ! no: use original seg_index_b
    mov.w   DAT_06006cca, r11      ! r11 = 0x0640 (clamp to max)
    mov.l @r8, r3                  ! r3 = distance_offset
    sub r3, r11                     ! r11 = max - offset (clamped index)
    exts.w r11, r11                ! sign-extend clamped value
.L_dispatch_render_b:
    ! --- Dispatch render function B based on mode ---
    mov.l @r14, r0                  ! r0 = mode
    cmp/eq #0x2, r0                ! mode == 2?
    bt      .L_render_b_mode2       ! yes: use scene_proc_d render
    exts.w r11, r7                  ! r7 = seg_index_b (render distance param)
    mov r9, r6                      ! r6 = render_params base
    mov.l @(4, r15), r5           ! r5 = render_target_b
    mov.l   .L_render_poly_b, r3   ! r3 = &sym_0602ABB8 (secondary polygon render)
    add #0x52, r6                   ! r6 = &render_params[0x52] (VDP1 attrib)
    mov.w @r6, r6                  ! r6 = VDP1 attribute word
    extu.w r6, r6                   ! zero-extend to 32 bits
    jsr @r3                         ! call sym_0602ABB8(poly_addr, target, attrib, dist)
    mov r13, r4                     ! r4 = vdp1_poly_addr_b (delay slot)
    bra     .L_inner_loop_next      ! done with segment B
    nop
.L_render_b_mode2:
    ! --- Mode 2: use scene_proc_d render instead ---
    exts.w r11, r7                  ! r7 = seg_index_b (render distance param)
    mov r9, r6                      ! r6 = render_params base
    mov.l @(4, r15), r5           ! r5 = render_target_b
    mov.l   .L_render_poly_b_alt, r3 ! r3 = &sym_0602B9E0 (scene_proc_d render)
    add #0x52, r6                   ! r6 = &render_params[0x52] (VDP1 attrib)
    mov.w @r6, r6                  ! r6 = VDP1 attribute word
    extu.w r6, r6                   ! zero-extend to 32 bits
    jsr @r3                         ! call sym_0602B9E0(poly_addr, target, attrib, dist)
    mov r13, r4                     ! r4 = vdp1_poly_addr_b (delay slot)
.L_inner_loop_next:
    add #0x1, r12                   ! r12++ (advance column)
.L_inner_loop_test:
    mov.l @(40, r15), r2           ! r2 = inner_limit
    cmp/ge r2, r12                  ! col >= inner_limit?
    bt      .L_outer_loop_next      ! yes: exit inner loop
    bra     .L_inner_loop_body      ! no: continue inner loop
    nop
.L_outer_loop_next:
    add #0x40, r10                  ! r10 += 64 (advance to next row)
.L_outer_loop_test:
    mov.l @(16, r15), r2           ! r2 = outer_limit * 64
    cmp/ge r2, r10                  ! row >= outer_limit?
    bt      .L_epilogue             ! yes: exit outer loop
    bra     .L_outer_loop_body      ! no: continue outer loop
    nop
.L_epilogue:
    add #0x30, r15                  ! deallocate 48-byte stack frame
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r8                ! restore callee-saved registers
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts                             ! return
    mov.l @r15+, r14               ! restore r14 (delay slot)

    .global DAT_06006cca
DAT_06006cca:
    .2byte  0x0640                      ! max render distance (1600) for seg B clip
.L_vdp1_finalize_fn:
    .4byte  vdp1_list_finalize          ! VDP1 list finalize fn (mode 2 render A)
.L_seg_offset_table_b:
    .4byte  sym_06062230                ! segment offset table (VDP1 polygon base)
.L_render_poly_b:
    .4byte  sym_0602ABB8                ! secondary polygon render fn (modes 0,1)
.L_render_poly_b_alt:
    .4byte  sym_0602B9E0                ! scene_proc_d render fn (mode 2 render B)
