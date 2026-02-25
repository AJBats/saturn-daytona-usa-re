/* vblank_frame_handler -- screen-space polygon vertex clipper
 * Translation unit: 0x06007E08 - 0x060081F4
 *
 * Called from the 3D rendering pipeline (scene_proc_d / scene_proc_e)
 * as a partial-clip combine handler when some but not all vertices of
 * a quad polygon lie outside the screen frustum.
 *
 * For each of the 4 vertices, the function first classifies whether it
 * lies within a screen-space rectangle (X in [-168, 168], Y in [-127, 81]).
 * A per-vertex "visible" flag is stored on the stack.
 *
 * Then for each edge of the quad, if both endpoints share the same
 * visibility state, it uses a Y-coordinate comparison to break the tie
 * and force one side to be the "blend target."
 *
 * Finally, an iterative interpolation loop blends off-screen vertices
 * toward their visible neighbors using: new = (3*current + neighbor) / 4.
 * The loop continues until coordinates converge within [-405, +405] (X)
 * and [-405, +305] (Y), or indefinitely if they do not.
 *
 * Arguments:
 *   R4 = vertex coordinate array (8 x int32: x0, y0, x1, y1, x2, y2, x3, y3)
 *   R5 = clip flags array (4 x word: flag0, flag1, flag2, flag3)
 *
 * Returns: modifies vertex coords in-place via R4
 *
 * Register allocation (main loop):
 *   R4  = &vtx[0].x (x0)         R8  = &vtx[2].x (x2)
 *   R12 = &vtx[0].y (y0)         R9  = &vtx[2].y (y2)
 *   R11 = &vtx[1].x (x1)         R14 = &vtx[3].x (x3)
 *   R10 = &vtx[1].y (y1)         R13 = &vtx[3].y (y3)
 *   R7  = -405 (lower screen bound)
 *   R6  = visibility flags array base (4 words on stack)
 *
 * Stack frame (0x24 = 36 bytes):
 *   sp+0   = temp scratch for bounds checks
 *   sp+4   = &vis_flags[0]
 *   sp+8   = &vis_flags[1]
 *   sp+12  = &vis_flags[3]
 *   sp+16  = &vis_flags[2]
 *   sp+20  = &clip_flags[2]
 *   sp+24  = &clip_flags[1]
 */

    .section .text.FUN_06007E08


    .global vblank_frame_handler
    .type vblank_frame_handler, @function
vblank_frame_handler:
    mov.l r14, @-r15                ! save callee-saved registers
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x24, r15                 ! allocate 36-byte stack frame
    mov.w   .L_coord_lower_bound, r7 ! r7 = -405 (0xFE6B signed), screen coord lower bound
    mov r15, r6                     ! r6 = stack pointer base
    add #0x1C, r6                   ! r6 = &vis_flags[0] (sp+28)
    mov #0x0, r14                   ! r14 = vertex loop counter (0,2,4,6)

! === Phase 1: Classify each vertex as visible (1) or clipped (0) ===
! Loops over 4 vertices testing if (x,y) lies within the visible rectangle.

.L_classify_loop:
    mov r14, r0                     ! r0 = vertex index * 2
    mov #0x0, r3                    ! r3 = 0
    cmp/gt r0, r3                   ! T = (0 > idx) -- always false, clears T
    mov r3, r2                      ! r2 = 0 (default: not visible)
    addc r3, r0                     ! r0 += T = idx (unchanged since T=0)
    shar r0                         ! r0 = idx / 2 (word index into vis_flags)
    shll r0                         ! r0 = word offset in bytes
    mov.w r2, @(r0, r6)            ! vis_flags[vertex] = 0 (default: clipped)
    mov r14, r0                     ! r0 = vertex index * 2
    mov.w   .L_vis_x_min, r3       ! r3 = -168 (X visibility lower bound)
    shll2 r0                        ! r0 = idx * 4 (byte offset into int32 array)
    mov.l @(r0, r4), r13           ! r13 = vtx[vertex].x
    cmp/gt r3, r13                  ! T = (x > -168)?
    bf      .L_next_vertex          ! x <= -168: off-screen left
    mov.w   .L_vis_x_max, r3       ! r3 = +168 (X visibility upper bound)
    cmp/ge r3, r13                  ! T = (x >= 168)?
    bt      .L_next_vertex          ! x >= 168: off-screen right
    mov r14, r0                     ! r0 = vertex index * 2
    mov #-0x7F, r3                  ! r3 = -127 (Y visibility lower bound)
    add #0x1, r0                    ! r0 = idx*2 + 1 (Y is next int32)
    shll2 r0                        ! r0 = byte offset for Y coordinate
    mov.l @(r0, r4), r13           ! r13 = vtx[vertex].y
    cmp/gt r3, r13                  ! T = (y > -127)?
    bf      .L_next_vertex          ! y <= -127: off-screen top
    mov #0x51, r3                   ! r3 = +81 (Y visibility upper bound)
    cmp/ge r3, r13                  ! T = (y >= 81)?
    bt      .L_next_vertex          ! y >= 81: off-screen bottom
    ! vertex is inside the visible rectangle -- mark as visible
    mov r14, r0                     ! r0 = vertex index * 2
    mov #0x0, r3                    ! r3 = 0
    cmp/gt r0, r3                   ! clears T (0 > idx is false)
    addc r3, r0                     ! r0 = idx (unchanged)
    shar r0                         ! r0 = word index
    shll r0                         ! r0 = byte offset for word
    mov #0x1, r2                    ! r2 = 1 (visible)
    mov.w r2, @(r0, r6)            ! vis_flags[vertex] = 1
.L_next_vertex:
    add #0x2, r14                   ! advance to next vertex pair
    mov #0x8, r3                    ! r3 = 8 (loop end: 4 vertices * 2)
    cmp/ge r3, r14                  ! T = (counter >= 8)?
    bf      .L_classify_loop        ! loop until all 4 vertices classified

! === Phase 2: Edge direction resolution ===
! When both endpoints of a clipped edge share the same visibility,
! use Y-coordinate comparison to break the tie and force a blend direction.

    mov.w @r5, r0                   ! r0 = clip_flags[0] (edge 0: vtx1--vtx3)
    extu.w r0, r0                   ! zero-extend to 32-bit
    tst r0, r0                      ! clip_flags[0] == 0?
    bt      .L_check_edge1          ! not clipped: try edge 1
    mov.w @(2, r6), r0              ! r0 = vis_flags[1]
    mov r0, r3
    extu.w r3, r3                   ! r3 = vis_flags[1] (zero-extended)
    mov.w @(6, r6), r0              ! r0 = vis_flags[3]
    mov r0, r2
    extu.w r2, r2                   ! r2 = vis_flags[3] (zero-extended)
    cmp/eq r2, r3                   ! vis_flags[1] == vis_flags[3]?
    bf      .L_setup_interp         ! different: no tie-break needed
    mov.l @(12, r4), r2            ! r2 = vtx[1].y
    mov.l @(28, r4), r3            ! r3 = vtx[3].y
    cmp/ge r3, r2                   ! T = (y1 >= y3)?
    bt      .L_edge0_y_ge           ! y1 >= y3: prefer vtx3 direction
    mov #0x1, r0                    ! y1 < y3: vis_flags[1] = 1
    mov.w r0, @(2, r6)             ! mark vtx1 as blend target
    bra     .L_edge0_store
    mov #0x0, r0                    ! r0 = 0 (delay slot)
.L_edge0_y_ge:
    mov #0x0, r2                    ! y1 >= y3: vis_flags[1] = 0
    mov r2, r0
    mov.w r0, @(2, r6)             ! clear vtx1 target
    mov #0x1, r3
    mov r3, r0                      ! r0 = 1 for vtx3
.L_edge0_store:
    bra     .L_setup_interp
    mov.w r0, @(6, r6)             ! vis_flags[3] = r0 (delay slot)

.L_check_edge1:                     ! edge 1: vtx2--vtx0
    mov.w @(2, r5), r0              ! r0 = clip_flags[1]
    extu.w r0, r0
    tst r0, r0                      ! clip_flags[1] == 0?
    bt      .L_check_edge2          ! not clipped: try edge 2
    mov.w @(4, r6), r0              ! r0 = vis_flags[2]
    mov.w @r6, r2                   ! r2 = vis_flags[0]
    mov r0, r3
    extu.w r2, r2                   ! r2 = vis_flags[0] (zero-extended)
    extu.w r3, r3                   ! r3 = vis_flags[2] (zero-extended)
    cmp/eq r2, r3                   ! vis_flags[0] == vis_flags[2]?
    bf      .L_setup_interp         ! different: no tie-break needed
    mov.l @(20, r4), r2            ! r2 = vtx[2].y
    mov.l @(4, r4), r3             ! r3 = vtx[0].y
    cmp/ge r3, r2                   ! T = (y2 >= y0)?
    bt      .L_edge1_y_ge           ! y2 >= y0: prefer vtx0 direction
    mov #0x1, r0                    ! y2 < y0: vis_flags[2] = 1
    mov.w r0, @(4, r6)             ! mark vtx2 as blend target
    mov #0x0, r3
    mov.w r3, @r6                   ! vis_flags[0] = 0
    bra     .L_edge1_done
    nop
.L_edge1_y_ge:
    mov #0x0, r2                    ! y2 >= y0: vis_flags[2] = 0
    mov r2, r0
    mov.w r0, @(4, r6)             ! clear vtx2 target
    mov #0x1, r3
    mov.w r3, @r6                   ! vis_flags[0] = 1
.L_edge1_done:
    bra     .L_setup_interp
    nop

.L_coord_lower_bound:
    .2byte  0xFE6B                  ! -405: screen coordinate lower bound
.L_vis_x_min:
    .2byte  0xFF58                  ! -168: X visibility threshold (min)
.L_vis_x_max:
    .2byte  0x00A8                  ! +168: X visibility threshold (max)

.L_check_edge2:                     ! edge 2: vtx3--vtx1
    mov.w @(4, r5), r0              ! r0 = clip_flags[2]
    extu.w r0, r0
    tst r0, r0                      ! clip_flags[2] == 0?
    bt      .L_check_edge3          ! not clipped: try edge 3
    mov.w @(6, r6), r0              ! r0 = vis_flags[3]
    mov r0, r3
    extu.w r3, r3                   ! r3 = vis_flags[3] (zero-extended)
    mov.w @(2, r6), r0              ! r0 = vis_flags[1]
    mov r0, r2
    extu.w r2, r2                   ! r2 = vis_flags[1] (zero-extended)
    cmp/eq r2, r3                   ! vis_flags[3] == vis_flags[1]?
    bf      .L_setup_interp         ! different: no tie-break needed
    mov.l @(28, r4), r2            ! r2 = vtx[3].y
    mov.l @(12, r4), r3            ! r3 = vtx[1].y
    cmp/ge r3, r2                   ! T = (y3 >= y1)?
    bt      .L_edge2_y_ge           ! y3 >= y1: prefer vtx1 direction
    mov #0x1, r0                    ! y3 < y1: vis_flags[3] = 1
    mov.w r0, @(6, r6)             ! mark vtx3 as blend target
    bra     .L_edge2_done
    mov #0x0, r0                    ! r0 = 0 (delay slot)
.L_edge2_y_ge:
    mov #0x0, r2                    ! y3 >= y1: vis_flags[3] = 0
    mov r2, r0
    mov.w r0, @(6, r6)             ! clear vtx3 target
    mov #0x1, r3
    mov r3, r0                      ! r0 = 1 for vtx1
.L_edge2_done:
    bra     .L_setup_interp
    mov.w r0, @(2, r6)             ! vis_flags[1] = r0 (delay slot)

.L_check_edge3:                     ! edge 3: vtx0--vtx2
    mov.w @r6, r2                   ! r2 = vis_flags[0]
    mov.w @(4, r6), r0              ! r0 = vis_flags[2]
    extu.w r2, r2                   ! zero-extend vis_flags[0]
    mov r0, r3
    extu.w r3, r3                   ! r3 = vis_flags[2] (zero-extended)
    cmp/eq r3, r2                   ! vis_flags[0] == vis_flags[2]?
    bf      .L_setup_interp         ! different: no tie-break needed
    mov.l @(4, r4), r2             ! r2 = vtx[0].y
    mov.l @(20, r4), r3            ! r3 = vtx[2].y
    cmp/ge r3, r2                   ! T = (y0 >= y2)?
    bt      .L_edge3_y_ge           ! y0 >= y2: prefer vtx2 direction
    mov #0x1, r3                    ! y0 < y2: vis_flags[0] = 1
    mov.w r3, @r6                   ! mark vtx0 as blend target
    mov #0x0, r2
    bra     .L_edge3_store
    mov r2, r0                      ! r0 = 0 (delay slot)
.L_edge3_y_ge:
    mov #0x0, r2                    ! y0 >= y2: vis_flags[0] = 0
    mov.w r2, @r6                   ! clear vtx0 target
    mov #0x1, r3
    mov r3, r0                      ! r0 = 1 for vtx2
.L_edge3_store:
    mov.w r0, @(4, r6)             ! vis_flags[2] = r0

! === Phase 3: Set up register aliases for interpolation loop ===

.L_setup_interp:
    mov r6, r3
    add #0x2, r3                    ! r3 = &vis_flags[1]
    mov.l r3, @(8, r15)            ! sp+8 = &vis_flags[1]
    mov r4, r11
    add #0x8, r11                   ! r11 = &vtx[1].x
    mov r4, r12
    add #0x4, r12                   ! r12 = &vtx[0].y
    mov r4, r10
    add #0xC, r10                   ! r10 = &vtx[1].y
    mov r6, r2
    add #0x6, r2                    ! r2 = &vis_flags[3]
    mov.l r2, @(12, r15)           ! sp+12 = &vis_flags[3]
    mov r4, r14
    add #0x18, r14                  ! r14 = &vtx[3].x
    mov r4, r13
    add #0x1C, r13                  ! r13 = &vtx[3].y
    mov r5, r3
    add #0x2, r3                    ! r3 = &clip_flags[1]
    mov.l r3, @(24, r15)           ! sp+24 = &clip_flags[1]
    mov r6, r1
    add #0x4, r1                    ! r1 = &vis_flags[2]
    mov.l r1, @(16, r15)           ! sp+16 = &vis_flags[2]
    mov r4, r8
    add #0x10, r8                   ! r8 = &vtx[2].x
    mov r4, r9
    add #0x14, r9                   ! r9 = &vtx[2].y
    mov r6, r3
    mov.l r3, @(4, r15)            ! sp+4 = &vis_flags[0]
    mov r5, r2
    add #0x4, r2                    ! r2 = &clip_flags[2]
    mov.l r2, @(20, r15)           ! sp+20 = &clip_flags[2]

! === Phase 4: Iterative interpolation loop ===
! Blend formula: new = (3*current + neighbor) / 4  (weighted 3:1 toward current)
! Exits when both coords of the active edge fall within screen bounds.

.L_interp_loop:
    mov.w @r5, r0                   ! r0 = clip_flags[0]
    extu.w r0, r0
    tst r0, r0                      ! clip_flags[0] == 0?
    bt      .L_interp_dir1          ! edge 0 not active: try edge 1

    ! --- Edge 0: blend vtx0 toward vtx1 or vtx3 ---
    mov.l @(8, r15), r3            ! r3 = &vis_flags[1]
    mov.w @r3, r0                   ! r0 = vis_flags[1]
    extu.w r0, r0
    tst r0, r0                      ! vtx1 visible?
    bt      .L_blend_v0_toward_v3   ! no: try vtx3 instead
    ! blend x0 toward x1: x0 = (3*x0 + x1) >> 2
    mov.l @r4, r3                   ! r3 = x0
    mov.l @r11, r1                  ! r1 = x1 (neighbor)
    mov r3, r2                      ! r2 = x0 (copy)
    shll r3                         ! r3 = 2*x0
    add r2, r3                      ! r3 = 3*x0
    add r1, r3                      ! r3 = 3*x0 + x1
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x0 + x1) / 4
    mov.l r3, @r4                   ! store blended x0
    ! blend y0 toward y1: y0 = (3*y0 + y1) >> 2
    mov.l @r12, r3                  ! r3 = y0
    mov.l @r10, r1                  ! r1 = y1 (neighbor)
    mov r3, r2                      ! r2 = y0 (copy)
    shll r3                         ! r3 = 2*y0
    add r2, r3                      ! r3 = 3*y0
    add r1, r3                      ! r3 = 3*y0 + y1
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y0 + y1) / 4
    mov.l r3, @r12                  ! store blended y0
    bra     .L_bounds_check_v0
    nop
.L_blend_v0_toward_v3:
    ! vtx1 not visible -- try blending vtx0 toward vtx3
    mov.l @(12, r15), r2           ! r2 = &vis_flags[3]
    mov.w @r2, r0                   ! r0 = vis_flags[3]
    extu.w r0, r0
    tst r0, r0                      ! vtx3 visible?
    bt      .L_bounds_check_v0      ! no neighbor visible: skip blend
    ! blend x0 toward x3: x0 = (3*x0 + x3) >> 2
    mov.l @r4, r3                   ! r3 = x0
    mov.l @r14, r1                  ! r1 = x3 (neighbor)
    mov r3, r2                      ! r2 = x0 (copy)
    shll r3                         ! r3 = 2*x0
    add r2, r3                      ! r3 = 3*x0
    add r1, r3                      ! r3 = 3*x0 + x3
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x0 + x3) / 4
    mov.l r3, @r4                   ! store blended x0
    ! blend y0 toward y3: y0 = (3*y0 + y3) >> 2
    mov.l @r12, r3                  ! r3 = y0
    mov.l @r13, r1                  ! r1 = y3 (neighbor)
    mov r3, r2                      ! r2 = y0 (copy)
    shll r3                         ! r3 = 2*y0
    add r2, r3                      ! r3 = 3*y0
    add r1, r3                      ! r3 = 3*y0 + y3
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y0 + y3) / 4
    mov.l r3, @r12                  ! store blended y0
.L_bounds_check_v0:
    ! validate vtx0 is within screen bounds [-405, +405] x [-405, +305]
    mov.l @r4, r3                   ! r3 = x0
    mov.l r3, @r15                  ! sp+0 = x0 (scratch)
    cmp/ge r7, r3                   ! T = (x0 >= -405)?
    bt      .L_v0_x_above_min
    bra     .L_loop_continue         ! x0 < -405: not converged
    nop
.L_v0_x_above_min:
    mov.l @r15, r2                  ! r2 = x0
    mov.w   .L_x_upper_bound_a, r3 ! r3 = +405
    cmp/gt r3, r2                   ! T = (x0 > 405)?
    bf      .L_v0_check_y           ! x0 in range: check Y
    bra     .L_loop_continue         ! x0 > 405: not converged
    nop
.L_v0_check_y:
    mov.l @r12, r2                  ! r2 = y0
    mov r2, r3
    cmp/ge r7, r3                   ! T = (y0 >= -405)?
    bf/s    .L_v0_out_of_range      ! y0 < -405: not converged
    mov.l r2, @r15                  ! sp+0 = y0 (delay slot)
    mov.l @r15, r2                  ! r2 = y0
    mov.w   .L_y_upper_bound_a, r3 ! r3 = +305
    cmp/gt r3, r2                   ! T = (y0 > 305)?
    bt      .L_v0_out_of_range      ! y0 > 305: not converged
    bra     .L_converged             ! both x0, y0 in range -- done!
    nop
.L_v0_out_of_range:
    bra     .L_loop_continue         ! keep iterating
    nop

.L_interp_dir1:
    ! --- Edge 1: blend vtx1 toward vtx2 or vtx0 ---
    mov.l @(24, r15), r2           ! r2 = &clip_flags[1]
    mov.w @r2, r0                   ! r0 = clip_flags[1]
    extu.w r0, r0
    tst r0, r0                      ! clip_flags[1] == 0?
    bt      .L_interp_dir2          ! edge 1 not active: try edge 2
    mov.l @(16, r15), r3           ! r3 = &vis_flags[2]
    mov.w @r3, r0                   ! r0 = vis_flags[2]
    extu.w r0, r0
    tst r0, r0                      ! vtx2 visible?
    bt      .L_blend_v1_toward_v0   ! no: try vtx0 instead
    ! blend x1 toward x2: x1 = (3*x1 + x2) >> 2
    mov.l @r11, r3                  ! r3 = x1
    mov.l @r8, r1                   ! r1 = x2 (neighbor)
    mov r3, r2                      ! r2 = x1 (copy)
    shll r3                         ! r3 = 2*x1
    add r2, r3                      ! r3 = 3*x1
    add r1, r3                      ! r3 = 3*x1 + x2
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x1 + x2) / 4
    mov.l r3, @r11                  ! store blended x1
    ! blend y1 toward y2: y1 = (3*y1 + y2) >> 2
    mov.l @r10, r3                  ! r3 = y1
    mov.l @r9, r1                   ! r1 = y2 (neighbor)
    mov r3, r2                      ! r2 = y1 (copy)
    shll r3                         ! r3 = 2*y1
    add r2, r3                      ! r3 = 3*y1
    add r1, r3                      ! r3 = 3*y1 + y2
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y1 + y2) / 4
    mov.l r3, @r10                  ! store blended y1
    bra     .L_bounds_check_v1
    nop
.L_x_upper_bound_a:
    .2byte  0x0195                  ! +405: X upper screen bound
.L_y_upper_bound_a:
    .2byte  0x0131                  ! +305: Y upper screen bound
.L_blend_v1_toward_v0:
    ! vtx2 not visible -- try blending vtx1 toward vtx0
    mov.l @(4, r15), r2            ! r2 = &vis_flags[0]
    mov.w @r2, r0                   ! r0 = vis_flags[0]
    extu.w r0, r0
    tst r0, r0                      ! vtx0 visible?
    bt      .L_bounds_check_v1      ! no neighbor visible: skip blend
    ! blend x1 toward x0: x1 = (3*x1 + x0) >> 2
    mov.l @r11, r3                  ! r3 = x1
    mov.l @r4, r1                   ! r1 = x0 (neighbor)
    mov r3, r2                      ! r2 = x1 (copy)
    shll r3                         ! r3 = 2*x1
    add r2, r3                      ! r3 = 3*x1
    add r1, r3                      ! r3 = 3*x1 + x0
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x1 + x0) / 4
    mov.l r3, @r11                  ! store blended x1
    ! blend y1 toward y0: y1 = (3*y1 + y0) >> 2
    mov.l @r10, r3                  ! r3 = y1
    mov.l @r12, r1                  ! r1 = y0 (neighbor)
    mov r3, r2                      ! r2 = y1 (copy)
    shll r3                         ! r3 = 2*y1
    add r2, r3                      ! r3 = 3*y1
    add r1, r3                      ! r3 = 3*y1 + y0
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y1 + y0) / 4
    mov.l r3, @r10                  ! store blended y1
.L_bounds_check_v1:
    ! validate vtx1 is within screen bounds
    mov.l @r11, r3                  ! r3 = x1
    mov.l r3, @r15                  ! sp+0 = x1 (scratch)
    cmp/ge r7, r3                   ! T = (x1 >= -405)?
    bt      .L_v1_x_above_min
    bra     .L_loop_continue         ! x1 < -405: not converged
    nop
.L_v1_x_above_min:
    mov.l @r15, r2                  ! r2 = x1
    mov.w   .L_x_upper_bound_b, r3 ! r3 = +405
    cmp/gt r3, r2                   ! T = (x1 > 405)?
    bf      .L_v1_check_y           ! x1 in range: check Y
    bra     .L_loop_continue         ! x1 > 405: not converged
    nop
.L_v1_check_y:
    mov.l @r10, r2                  ! r2 = y1
    mov r2, r3
    cmp/ge r7, r3                   ! T = (y1 >= -405)?
    bf/s    .L_v1_out_of_range      ! y1 < -405: not converged
    mov.l r2, @r15                  ! sp+0 = y1 (delay slot)
    mov.l @r15, r2                  ! r2 = y1
    mov.w   .L_y_upper_bound_b, r3 ! r3 = +305
    cmp/gt r3, r2                   ! T = (y1 > 305)?
    bt      .L_v1_out_of_range      ! y1 > 305: not converged
    bra     .L_converged             ! both x1, y1 in range -- done!
    nop
.L_v1_out_of_range:
    bra     .L_loop_continue         ! keep iterating
    nop

.L_interp_dir2:
    ! --- Edge 2: blend vtx2 toward vtx3 or vtx1 ---
    mov.l @(20, r15), r2           ! r2 = &clip_flags[2]
    mov.w @r2, r0                   ! r0 = clip_flags[2]
    extu.w r0, r0
    tst r0, r0                      ! clip_flags[2] == 0?
    bt      .L_interp_dir3          ! edge 2 not active: try edge 3
    mov.l @(12, r15), r3           ! r3 = &vis_flags[3]
    mov.w @r3, r0                   ! r0 = vis_flags[3]
    extu.w r0, r0
    tst r0, r0                      ! vtx3 visible?
    bt      .L_blend_v2_toward_v1   ! no: try vtx1 instead
    ! blend x2 toward x3: x2 = (3*x2 + x3) >> 2
    mov.l @r8, r3                   ! r3 = x2
    mov.l @r14, r1                  ! r1 = x3 (neighbor)
    mov r3, r2                      ! r2 = x2 (copy)
    shll r3                         ! r3 = 2*x2
    add r2, r3                      ! r3 = 3*x2
    add r1, r3                      ! r3 = 3*x2 + x3
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x2 + x3) / 4
    mov.l r3, @r8                   ! store blended x2
    ! blend y2 toward y3: y2 = (3*y2 + y3) >> 2
    mov.l @r9, r3                   ! r3 = y2
    mov.l @r13, r1                  ! r1 = y3 (neighbor)
    mov r3, r2                      ! r2 = y2 (copy)
    shll r3                         ! r3 = 2*y2
    add r2, r3                      ! r3 = 3*y2
    add r1, r3                      ! r3 = 3*y2 + y3
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y2 + y3) / 4
    mov.l r3, @r9                   ! store blended y2
    bra     .L_bounds_check_v2
    nop
.L_x_upper_bound_b:
    .2byte  0x0195                  ! +405: X upper screen bound
.L_y_upper_bound_b:
    .2byte  0x0131                  ! +305: Y upper screen bound
.L_blend_v2_toward_v1:
    ! vtx3 not visible -- try blending vtx2 toward vtx1
    mov.l @(8, r15), r2            ! r2 = &vis_flags[1]
    mov.w @r2, r0                   ! r0 = vis_flags[1]
    extu.w r0, r0
    tst r0, r0                      ! vtx1 visible?
    bt      .L_bounds_check_v2      ! no neighbor visible: skip blend
    ! blend x2 toward x1: x2 = (3*x2 + x1) >> 2
    mov.l @r8, r3                   ! r3 = x2
    mov.l @r11, r1                  ! r1 = x1 (neighbor)
    mov r3, r2                      ! r2 = x2 (copy)
    shll r3                         ! r3 = 2*x2
    add r2, r3                      ! r3 = 3*x2
    add r1, r3                      ! r3 = 3*x2 + x1
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x2 + x1) / 4
    mov.l r3, @r8                   ! store blended x2
    ! blend y2 toward y1: y2 = (3*y2 + y1) >> 2
    mov.l @r9, r3                   ! r3 = y2
    mov.l @r10, r1                  ! r1 = y1 (neighbor)
    mov r3, r2                      ! r2 = y2 (copy)
    shll r3                         ! r3 = 2*y2
    add r2, r3                      ! r3 = 3*y2
    add r1, r3                      ! r3 = 3*y2 + y1
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y2 + y1) / 4
    mov.l r3, @r9                   ! store blended y2
.L_bounds_check_v2:
    ! validate vtx2 is within screen bounds
    mov.l @r8, r3                   ! r3 = x2
    mov.l r3, @r15                  ! sp+0 = x2 (scratch)
    cmp/ge r7, r3                   ! T = (x2 >= -405)?
    bf      .L_loop_continue         ! x2 < -405: not converged
    mov.l @r15, r2                  ! r2 = x2
    mov.w   .L_x_upper_bound_c, r3 ! r3 = +405
    cmp/gt r3, r2                   ! T = (x2 > 405)?
    bt      .L_loop_continue         ! x2 > 405: not converged
    mov.l @r9, r2                   ! r2 = y2
    mov r2, r3
    cmp/ge r7, r3                   ! T = (y2 >= -405)?
    bf/s    .L_v2_out_of_range      ! y2 < -405: not converged
    mov.l r2, @r15                  ! sp+0 = y2 (delay slot)
    mov.l @r15, r2                  ! r2 = y2
    mov.w   .L_y_upper_bound_c, r3 ! r3 = +305
    cmp/gt r3, r2                   ! T = (y2 > 305)?
    bt      .L_v2_out_of_range      ! y2 > 305: not converged
    bra     .L_converged             ! both x2, y2 in range -- done!
    nop
.L_v2_out_of_range:
    bra     .L_loop_continue         ! keep iterating
    nop

.L_interp_dir3:
    ! --- Edge 3: blend vtx3 toward vtx0 or vtx2 ---
    mov.l @(4, r15), r2            ! r2 = &vis_flags[0]
    mov.w @r2, r0                   ! r0 = vis_flags[0]
    extu.w r0, r0
    tst r0, r0                      ! vtx0 visible?
    bt      .L_blend_v3_toward_v2   ! no: try vtx2 instead
    ! blend x3 toward x0: x3 = (3*x3 + x0) >> 2
    mov.l @r14, r3                  ! r3 = x3
    mov.l @r4, r1                   ! r1 = x0 (neighbor)
    mov r3, r2                      ! r2 = x3 (copy)
    shll r3                         ! r3 = 2*x3
    add r2, r3                      ! r3 = 3*x3
    add r1, r3                      ! r3 = 3*x3 + x0
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x3 + x0) / 4
    mov.l r3, @r14                  ! store blended x3
    ! blend y3 toward y0: y3 = (3*y3 + y0) >> 2
    mov.l @r13, r3                  ! r3 = y3
    mov.l @r12, r1                  ! r1 = y0 (neighbor)
    mov r3, r2                      ! r2 = y3 (copy)
    shll r3                         ! r3 = 2*y3
    add r2, r3                      ! r3 = 3*y3
    add r1, r3                      ! r3 = 3*y3 + y0
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y3 + y0) / 4
    mov.l r3, @r13                  ! store blended y3
    bra     .L_bounds_check_v3
    nop
.L_blend_v3_toward_v2:
    ! vtx0 not visible -- try blending vtx3 toward vtx2
    mov.l @(16, r15), r2           ! r2 = &vis_flags[2]
    mov.w @r2, r0                   ! r0 = vis_flags[2]
    extu.w r0, r0
    tst r0, r0                      ! vtx2 visible?
    bt      .L_bounds_check_v3      ! no neighbor visible: skip blend
    ! blend x3 toward x2: x3 = (3*x3 + x2) >> 2
    mov.l @r14, r3                  ! r3 = x3
    mov.l @r8, r1                   ! r1 = x2 (neighbor)
    mov r3, r2                      ! r2 = x3 (copy)
    shll r3                         ! r3 = 2*x3
    add r2, r3                      ! r3 = 3*x3
    add r1, r3                      ! r3 = 3*x3 + x2
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*x3 + x2) / 4
    mov.l r3, @r14                  ! store blended x3
    ! blend y3 toward y2: y3 = (3*y3 + y2) >> 2
    mov.l @r13, r3                  ! r3 = y3
    mov.l @r9, r1                   ! r1 = y2 (neighbor)
    mov r3, r2                      ! r2 = y3 (copy)
    shll r3                         ! r3 = 2*y3
    add r2, r3                      ! r3 = 3*y3
    add r1, r3                      ! r3 = 3*y3 + y2
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 = (3*y3 + y2) / 4
    mov.l r3, @r13                  ! store blended y3
.L_bounds_check_v3:
    ! validate vtx3 is within screen bounds
    mov.l @r14, r3                  ! r3 = x3
    mov.l r3, @r15                  ! sp+0 = x3 (scratch)
    cmp/ge r7, r3                   ! T = (x3 >= -405)?
    bf      .L_loop_continue         ! x3 < -405: not converged
    mov.l @r15, r2                  ! r2 = x3
    mov.w   .L_x_upper_bound_c, r3 ! r3 = +405
    cmp/gt r3, r2                   ! T = (x3 > 405)?
    bt      .L_loop_continue         ! x3 > 405: not converged
    mov.l @r13, r2                  ! r2 = y3
    mov r2, r3
    cmp/ge r7, r3                   ! T = (y3 >= -405)?
    bf/s    .L_loop_continue        ! y3 < -405: not converged
    mov.l r2, @r15                  ! sp+0 = y3 (delay slot)
    mov.l @r15, r2                  ! r2 = y3
    mov.w   .L_y_upper_bound_c, r3 ! r3 = +305
    cmp/gt r3, r2                   ! T = (y3 > 305)?
    bt      .L_loop_continue         ! y3 > 305: not converged
    bra     .L_converged             ! both x3, y3 in range -- done!
    nop
.L_x_upper_bound_c:
    .2byte  0x0195                  ! +405: X upper screen bound
.L_y_upper_bound_c:
    .2byte  0x0131                  ! +305: Y upper screen bound
.L_loop_continue:
    bra     .L_interp_loop           ! loop back for another blend iteration
    nop

! === Epilogue ===
.L_converged:
    add #0x24, r15                  ! deallocate 36-byte stack frame
    mov.l @r15+, r8                 ! restore callee-saved registers
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts                             ! return to caller
    mov.l @r15+, r14                ! restore r14 (delay slot)
    .2byte  0x0000                  ! alignment padding
