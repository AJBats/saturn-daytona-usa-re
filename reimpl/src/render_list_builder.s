/* render_list_builder -- screen-space polygon vertex clipper (variant B)
 * Translation unit: 0x06022820 - 0x06022AE0
 *
 * Called from the 3D rendering pipeline (scene_proc_d / scene_proc_e)
 * as a partial-clip combine handler when some but not all vertices of
 * a quad polygon lie outside the screen frustum.  This is the second
 * of three clip-combine handlers in the pipeline function table:
 *   [vblank_frame_handler, render_list_builder, render_obj_processor]
 *
 * For each of the 4 edges of the quad, if one endpoint is visible and
 * its neighbor is not, the off-screen vertex coordinate is nudged toward
 * the on-screen vertex using a weighted average:
 *   new = (2*old + neighbor) / 4
 * This is done by: shll (x2), add original (x3), add neighbor, shar x2 (/4).
 *
 * After nudging, the result is range-checked against the screen bounds:
 *   X in [-405, +405]  (0xFE6B .. 0x0195)
 *   Y in [-405, +305]  (0xFE6B .. 0x0131)
 * If the vertex passes bounds, a per-vertex visibility flag (word) is
 * set to 0 (= visible).  The loop repeats until all 4 visibility flags
 * are zero (all vertices in-bounds) or no further nudging is possible.
 *
 * Arguments:
 *   R4 = vertex coordinate array (8 x int32: x0, y0, x1, y1, x2, y2, x3, y3)
 *   R5 = clip flags array (4 x int16: flag0, flag1, flag2, flag3)
 *
 * Returns: modifies vertex coords in-place via R4; sets visibility flags
 *
 * Register map (after prologue):
 *   r4  = &vtx[0].x          (vertex 0 X coord ptr)
 *   r12 = &vtx[0].y          (vertex 0 Y coord ptr, r4+0x04)
 *   sp[0]  = &vtx[1].x ptr   (r4+0x08)
 *   sp[4]  = &vtx[1].y ptr   (r4+0x0C)
 *   r8  = &vtx[2].x          (r4+0x10)
 *   r9  = &vtx[2].y          (r4+0x14)
 *   r10 = &vtx[3].x          (r4+0x18)
 *   r11 = &vtx[3].y          (r4+0x1C)
 *   r5  = clip flags base ptr
 *   sp[20] = &clip_flag[1]    (r5+0x02)
 *   sp[8]  = &clip_flag[2]    (r5+0x04)
 *   sp[16] = &clip_flag[3]    (r5+0x06)
 *   r6  = -405 (coord_lower_bound)
 *   r7  = 0x0000 (visible flag constant)
 *   sp[28] = &vis[0] ptr      (local visibility word 0)
 *   sp[12] = &vis[1] ptr      (local visibility word 1)
 *   sp[24] = &vis[2] ptr      (local visibility word 2)
 *   sp[32] = &vis[3] ptr      (local visibility word 3)
 */

    .section .text.FUN_06022820


    .global render_list_builder
    .type render_list_builder, @function
render_list_builder:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    mov.l r10, @-r15                    ! save r10
    mov.l r9, @-r15                     ! save r9
    mov.l r8, @-r15                     ! save r8
    add #-0x2C, r15                     ! allocate 0x2C bytes of stack frame
    mov #0x0, r7                        ! r7 = 0x0 (visible flag constant)
    mov.w   .L_coord_lower_bound, r6    ! r6 = -405 (0xFE6B) screen lower bound
    mov r15, r14                        ! r14 = sp (base of local vis array)
    add #0x24, r14                      ! r14 = &vis[0] (sp+0x24)
    mov r14, r3                         ! r3 = &vis[0]
    mov.l r3, @(28, r15)               ! sp[28] = &vis[0] ptr
    mov.w @r5, r2                       ! r2 = clip_flag[0]
    mov.w r2, @r3                       ! vis[0] = clip_flag[0] (init from clip flags)
    add #0x2, r3                        ! r3 = &vis[1]
    mov.l r3, @(12, r15)               ! sp[12] = &vis[1] ptr
    mov r5, r2                          ! r2 = clip_flags base
    add #0x2, r2                        ! r2 = &clip_flag[1]
    mov.l r2, @(20, r15)               ! sp[20] = &clip_flag[1] ptr
    mov.w @r2, r1                       ! r1 = clip_flag[1]
    mov.w r1, @r3                       ! vis[1] = clip_flag[1]
    mov r14, r3                         ! r3 = &vis[0]
    add #0x4, r3                        ! r3 = &vis[2]
    mov.l r3, @(24, r15)               ! sp[24] = &vis[2] ptr
    mov r5, r2                          ! r2 = clip_flags base
    add #0x4, r2                        ! r2 = &clip_flag[2]
    mov.l r2, @(8, r15)                ! sp[8] = &clip_flag[2] ptr
    mov.w @r2, r1                       ! r1 = clip_flag[2]
    mov.w r1, @r3                       ! vis[2] = clip_flag[2]
    add #0x6, r14                       ! r14 = &vis[3] (vis[0]+6)
    mov.l r14, @(32, r15)              ! sp[32] = &vis[3] ptr
    mov r5, r3                          ! r3 = clip_flags base
    add #0x6, r3                        ! r3 = &clip_flag[3]
    mov.l r3, @(16, r15)               ! sp[16] = &clip_flag[3] ptr
    mov.w @r3, r2                       ! r2 = clip_flag[3]
    mov.w r2, @r14                      ! vis[3] = clip_flag[3]
    mov r4, r12                         ! r12 = r4 (vtx base)
    add #0x4, r12                       ! r12 = &vtx[0].y (r4+0x04)
    mov r4, r3                          ! r3 = r4
    add #0x8, r3                        ! r3 = &vtx[1].x (r4+0x08)
    mov.l r3, @r15                      ! sp[0] = &vtx[1].x ptr
    mov r4, r2                          ! r2 = r4
    add #0xC, r2                        ! r2 = &vtx[1].y (r4+0x0C)
    mov r4, r10                         ! r10 = r4
    add #0x18, r10                      ! r10 = &vtx[3].x (r4+0x18)
    mov r4, r11                         ! r11 = r4
    add #0x1C, r11                      ! r11 = &vtx[3].y (r4+0x1C)
    mov r2, r13                         ! r13 = &vtx[1].y (temp)
    mov r4, r8                          ! r8 = r4
    add #0x10, r8                       ! r8 = &vtx[2].x (r4+0x10)
    mov r4, r9                          ! r9 = r4
    add #0x14, r9                       ! r9 = &vtx[2].y (r4+0x14)
    mov.l r13, @(4, r15)               ! sp[4] = &vtx[1].y ptr
! ---- main clipping loop: process all 4 edges each iteration ----
.L_clip_loop:
    mov.w @r5, r0                       ! r0 = clip_flag[0]
    extu.w r0, r0                       ! zero-extend to 32-bit
    tst r0, r0                          ! test if flag[0] == 0
    bt      .L_edge0_done               ! skip edge 0 if clip_flag[0] clear
    mov.l @(28, r15), r3                ! r3 = &vis[0]
    mov.w @r3, r0                       ! r0 = vis[0]
    tst r0, r0                          ! test if vis[0] == 0
    bt      .L_edge0_done               ! skip if already visible
    mov.l @r4, r14                      ! r14 = vtx[0].x
    mov.l @r12, r13                     ! r13 = vtx[0].y
    mov r14, r3                         ! r3 = vtx[0].x (backup)
    mov r13, r2                         ! r2 = vtx[0].y (backup)
    shll r14                            ! r14 = vtx[0].x * 2
    shll r13                            ! r13 = vtx[0].y * 2
    add r3, r14                         ! r14 = vtx[0].x * 3
    mov.l @(20, r15), r3                ! r3 = &clip_flag[1]
    mov.w @r3, r3                       ! r3 = clip_flag[1]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[1] == 0
    bf/s    .L_edge0_try_vtx3           ! if flag[1] set, try vertex 3 instead
    add r2, r13                         ! (delay) r13 = vtx[0].y * 3
    ! -- neighbor = vtx[1]: nudge vtx[0] toward vtx[1] --
    mov.l @r15, r3                      ! r3 = &vtx[1].x ptr
    mov.l @(4, r15), r2                 ! r2 = &vtx[1].y ptr
    mov.l @r3, r3                       ! r3 = vtx[1].x
    add r3, r14                         ! r14 = vtx[0].x*3 + vtx[1].x
    mov.l @r2, r3                       ! r3 = vtx[1].y
    shar r14                            ! r14 /= 2
    add r3, r13                         ! r13 = vtx[0].y*3 + vtx[1].y
    shar r14                            ! r14 /= 2 => (3*x0 + x1) / 4
    shar r13                            ! r13 /= 2
    mov.l r14, @r4                      ! vtx[0].x = nudged X
    shar r13                            ! r13 /= 2 => (3*y0 + y1) / 4
    bra     .L_edge0_bounds_check       ! check if result is in bounds
    mov.l r13, @r12                     ! (delay) vtx[0].y = nudged Y
.L_coord_lower_bound:
    .2byte  0xFE6B                      ! -405 signed: screen coordinate lower bound
.L_edge0_try_vtx3:
    ! -- clip_flag[1] is set; try neighbor = vtx[3] instead --
    mov.l @(16, r15), r2                ! r2 = &clip_flag[3]
    mov.w @r2, r3                       ! r3 = clip_flag[3]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[3] == 0
    bf      .L_edge0_bounds_check       ! if flag[3] also set, skip nudge
    ! -- neighbor = vtx[3]: nudge vtx[0] toward vtx[3] --
    mov.l @r10, r3                      ! r3 = vtx[3].x
    mov.l @r11, r2                      ! r2 = vtx[3].y
    add r3, r14                         ! r14 = vtx[0].x*3 + vtx[3].x
    add r2, r13                         ! r13 = vtx[0].y*3 + vtx[3].y
    shar r14                            ! r14 /= 2
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2 => (3*x0 + x3) / 4
    mov.l r14, @r4                      ! vtx[0].x = nudged X
    shar r13                            ! r13 /= 2 => (3*y0 + y3) / 4
    mov.l r13, @r12                     ! vtx[0].y = nudged Y
.L_edge0_bounds_check:
    mov.l @r4, r14                      ! r14 = vtx[0].x (possibly nudged)
    cmp/ge r6, r14                      ! test vtx[0].x >= -405
    bf      .L_edge0_done               ! fail: X below lower bound
    mov.w   .L_x_upper_bound_0, r2      ! r2 = 405 (0x0195)
    cmp/gt r2, r14                      ! test vtx[0].x > 405
    bt      .L_edge0_done               ! fail: X above upper bound
    mov.l @r12, r14                     ! r14 = vtx[0].y
    cmp/ge r6, r14                      ! test vtx[0].y >= -405
    bf      .L_edge0_done               ! fail: Y below lower bound
    mov.w   .L_y_upper_bound_0, r3      ! r3 = 305 (0x0131)
    cmp/gt r3, r14                      ! test vtx[0].y > 305
    bt      .L_edge0_done               ! fail: Y above upper bound
    ! -- vertex 0 is now in bounds --
    mov.l @(28, r15), r3                ! r3 = &vis[0]
    exts.w r7, r2                       ! r2 = 0x0 (visible)
    mov.w r2, @r3                       ! vis[0] = 0 (mark visible)
! ---- edge 1: process vtx[1] ----
.L_edge0_done:
    mov.l @(20, r15), r3                ! r3 = &clip_flag[1]
    mov.w @r3, r0                       ! r0 = clip_flag[1]
    extu.w r0, r0                       ! zero-extend
    tst r0, r0                          ! test if clip_flag[1] == 0
    bt      .L_edge1_done               ! skip edge 1 if flag clear
    mov.l @(12, r15), r3                ! r3 = &vis[1]
    mov.w @r3, r0                       ! r0 = vis[1]
    tst r0, r0                          ! test if vis[1] == 0
    bt      .L_edge1_done               ! skip if already visible
    mov.l @r15, r14                     ! r14 = &vtx[1].x ptr
    mov.l @(4, r15), r13                ! r13 = &vtx[1].y ptr
    mov.l @(8, r15), r2                 ! r2 = &clip_flag[2] ptr
    mov.l @r14, r14                     ! r14 = vtx[1].x
    mov.l @r13, r13                     ! r13 = vtx[1].y
    mov r14, r3                         ! r3 = vtx[1].x (backup)
    shll r14                            ! r14 = vtx[1].x * 2
    add r3, r14                         ! r14 = vtx[1].x * 3
    mov r13, r3                         ! r3 = vtx[1].y (backup)
    shll r13                            ! r13 = vtx[1].y * 2
    add r3, r13                         ! r13 = vtx[1].y * 3
    mov.w @r2, r3                       ! r3 = clip_flag[2]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[2] == 0
    bf      .L_edge1_try_vtx0           ! if flag[2] set, try vertex 0
    ! -- neighbor = vtx[2]: nudge vtx[1] toward vtx[2] --
    mov.l @r8, r3                       ! r3 = vtx[2].x
    mov.l @r9, r2                       ! r2 = vtx[2].y
    add r3, r14                         ! r14 = vtx[1].x*3 + vtx[2].x
    add r2, r13                         ! r13 = vtx[1].y*3 + vtx[2].y
    shar r14                            ! r14 /= 2
    mov.l @r15, r3                      ! r3 = &vtx[1].x ptr
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2 => (3*x1 + x2) / 4
    mov.l r14, @r3                      ! vtx[1].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = &vtx[1].y ptr
    shar r13                            ! r13 /= 2 => (3*y1 + y2) / 4
    mov.l r13, @r3                      ! vtx[1].y = nudged Y
    bra     .L_edge1_bounds_check       ! go to bounds check
    nop                                 ! (delay) no-op
.L_x_upper_bound_0:
    .2byte  0x0195                      ! 405: screen X upper bound
.L_y_upper_bound_0:
    .2byte  0x0131                      ! 305: screen Y upper bound
.L_edge1_try_vtx0:
    ! -- clip_flag[2] is set; try neighbor = vtx[0] instead --
    mov.w @r5, r2                       ! r2 = clip_flag[0]
    extu.w r2, r2                       ! zero-extend
    tst r2, r2                          ! test if clip_flag[0] == 0
    bf      .L_edge1_bounds_check       ! if flag[0] also set, skip nudge
    ! -- neighbor = vtx[0]: nudge vtx[1] toward vtx[0] --
    mov.l @r4, r3                       ! r3 = vtx[0].x
    mov.l @r12, r2                      ! r2 = vtx[0].y
    add r3, r14                         ! r14 = vtx[1].x*3 + vtx[0].x
    add r2, r13                         ! r13 = vtx[1].y*3 + vtx[0].y
    shar r14                            ! r14 /= 2
    mov.l @r15, r3                      ! r3 = &vtx[1].x ptr
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2 => (3*x1 + x0) / 4
    mov.l r14, @r3                      ! vtx[1].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = &vtx[1].y ptr
    shar r13                            ! r13 /= 2 => (3*y1 + y0) / 4
    mov.l r13, @r3                      ! vtx[1].y = nudged Y
.L_edge1_bounds_check:
    mov.l @r15, r14                     ! r14 = &vtx[1].x ptr
    mov.l @r14, r14                     ! r14 = vtx[1].x
    cmp/ge r6, r14                      ! test vtx[1].x >= -405
    bf      .L_edge1_done               ! fail: X below lower bound
    mov.w   .L_x_upper_bound_1, r2      ! r2 = 405 (0x0195)
    cmp/gt r2, r14                      ! test vtx[1].x > 405
    bt      .L_edge1_done               ! fail: X above upper bound
    mov.l @(4, r15), r14                ! r14 = &vtx[1].y ptr
    mov.l @r14, r14                     ! r14 = vtx[1].y
    cmp/ge r6, r14                      ! test vtx[1].y >= -405
    bf      .L_edge1_done               ! fail: Y below lower bound
    mov.w   .L_y_upper_bound_1, r2      ! r2 = 305 (0x0131)
    cmp/gt r2, r14                      ! test vtx[1].y > 305
    bt      .L_edge1_done               ! fail: Y above upper bound
    ! -- vertex 1 is now in bounds --
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    exts.w r7, r3                       ! r3 = 0x0 (visible)
    mov.w r3, @r2                       ! vis[1] = 0 (mark visible)
! ---- edge 2: process vtx[2] ----
.L_edge1_done:
    mov.l @(8, r15), r2                 ! r2 = &clip_flag[2]
    mov.w @r2, r0                       ! r0 = clip_flag[2]
    extu.w r0, r0                       ! zero-extend
    tst r0, r0                          ! test if clip_flag[2] == 0
    bt      .L_edge2_done               ! skip edge 2 if flag clear
    mov.l @(24, r15), r3                ! r3 = &vis[2]
    mov.w @r3, r0                       ! r0 = vis[2]
    tst r0, r0                          ! test if vis[2] == 0
    bt      .L_edge2_done               ! skip if already visible
    mov.l @r8, r14                      ! r14 = vtx[2].x
    mov.l @r9, r13                      ! r13 = vtx[2].y
    mov r14, r3                         ! r3 = vtx[2].x (backup)
    mov r13, r2                         ! r2 = vtx[2].y (backup)
    shll r14                            ! r14 = vtx[2].x * 2
    shll r13                            ! r13 = vtx[2].y * 2
    add r3, r14                         ! r14 = vtx[2].x * 3
    mov.l @(16, r15), r3                ! r3 = &clip_flag[3]
    mov.w @r3, r3                       ! r3 = clip_flag[3]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[3] == 0
    bf/s    .L_edge2_try_vtx1           ! if flag[3] set, try vertex 1 instead
    add r2, r13                         ! (delay) r13 = vtx[2].y * 3
    ! -- neighbor = vtx[3]: nudge vtx[2] toward vtx[3] --
    mov.l @r10, r3                      ! r3 = vtx[3].x
    mov.l @r11, r2                      ! r2 = vtx[3].y
    add r3, r14                         ! r14 = vtx[2].x*3 + vtx[3].x
    add r2, r13                         ! r13 = vtx[2].y*3 + vtx[3].y
    shar r14                            ! r14 /= 2
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2 => (3*x2 + x3) / 4
    mov.l r14, @r8                      ! vtx[2].x = nudged X
    shar r13                            ! r13 /= 2 => (3*y2 + y3) / 4
    bra     .L_edge2_bounds_check       ! go to bounds check
    mov.l r13, @r9                      ! (delay) vtx[2].y = nudged Y
.L_x_upper_bound_1:
    .2byte  0x0195                      ! 405: screen X upper bound
.L_y_upper_bound_1:
    .2byte  0x0131                      ! 305: screen Y upper bound
.L_edge2_try_vtx1:
    ! -- clip_flag[3] is set; try neighbor = vtx[1] instead --
    mov.l @(20, r15), r2                ! r2 = &clip_flag[1]
    mov.w @r2, r3                       ! r3 = clip_flag[1]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[1] == 0
    bf      .L_edge2_bounds_check       ! if flag[1] also set, skip nudge
    ! -- neighbor = vtx[1]: nudge vtx[2] toward vtx[1] --
    mov.l @r15, r3                      ! r3 = &vtx[1].x ptr
    mov.l @(4, r15), r2                 ! r2 = &vtx[1].y ptr
    mov.l @r3, r3                       ! r3 = vtx[1].x
    add r3, r14                         ! r14 = vtx[2].x*3 + vtx[1].x
    mov.l @r2, r3                       ! r3 = vtx[1].y
    shar r14                            ! r14 /= 2
    add r3, r13                         ! r13 = vtx[2].y*3 + vtx[1].y
    shar r14                            ! r14 /= 2 => (3*x2 + x1) / 4
    shar r13                            ! r13 /= 2
    mov.l r14, @r8                      ! vtx[2].x = nudged X
    shar r13                            ! r13 /= 2 => (3*y2 + y1) / 4
    mov.l r13, @r9                      ! vtx[2].y = nudged Y
.L_edge2_bounds_check:
    mov.l @r8, r14                      ! r14 = vtx[2].x (possibly nudged)
    cmp/ge r6, r14                      ! test vtx[2].x >= -405
    bf      .L_edge2_done               ! fail: X below lower bound
    mov.w   .L_x_upper_bound_2, r3      ! r3 = 405 (0x0195)
    cmp/gt r3, r14                      ! test vtx[2].x > 405
    bt      .L_edge2_done               ! fail: X above upper bound
    mov.l @r9, r14                      ! r14 = vtx[2].y
    cmp/ge r6, r14                      ! test vtx[2].y >= -405
    bf      .L_edge2_done               ! fail: Y below lower bound
    mov.w   .L_y_upper_bound_2, r2      ! r2 = 305 (0x0131)
    cmp/gt r2, r14                      ! test vtx[2].y > 305
    bt      .L_edge2_done               ! fail: Y above upper bound
    ! -- vertex 2 is now in bounds --
    mov.l @(24, r15), r2                ! r2 = &vis[2]
    exts.w r7, r3                       ! r3 = 0x0 (visible)
    mov.w r3, @r2                       ! vis[2] = 0 (mark visible)
! ---- edge 3: process vtx[3] ----
.L_edge2_done:
    mov.l @(16, r15), r2                ! r2 = &clip_flag[3]
    mov.w @r2, r0                       ! r0 = clip_flag[3]
    extu.w r0, r0                       ! zero-extend
    tst r0, r0                          ! test if clip_flag[3] == 0
    bt      .L_edge3_done               ! skip edge 3 if flag clear
    mov.l @(32, r15), r3                ! r3 = &vis[3]
    mov.w @r3, r0                       ! r0 = vis[3]
    tst r0, r0                          ! test if vis[3] == 0
    bt      .L_edge3_done               ! skip if already visible
    mov.l @r10, r13                     ! r13 = vtx[3].x
    mov.l @r11, r14                     ! r14 = vtx[3].y
    mov r13, r3                         ! r3 = vtx[3].x (backup)
    mov r14, r2                         ! r2 = vtx[3].y (backup)
    shll r13                            ! r13 = vtx[3].x * 2
    shll r14                            ! r14 = vtx[3].y * 2
    add r3, r13                         ! r13 = vtx[3].x * 3
    mov.w @r5, r3                       ! r3 = clip_flag[0]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[0] == 0
    bf/s    .L_edge3_try_vtx2           ! if flag[0] set, try vertex 2 instead
    add r2, r14                         ! (delay) r14 = vtx[3].y * 3
    ! -- neighbor = vtx[0]: nudge vtx[3] toward vtx[0] --
    mov.l @r4, r3                       ! r3 = vtx[0].x
    mov.l @r12, r2                      ! r2 = vtx[0].y
    add r3, r13                         ! r13 = vtx[3].x*3 + vtx[0].x
    add r2, r14                         ! r14 = vtx[3].y*3 + vtx[0].y
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2
    shar r13                            ! r13 /= 2 => (3*x3 + x0) / 4
    mov.l r13, @r10                     ! vtx[3].x = nudged X
    shar r14                            ! r14 /= 2 => (3*y3 + y0) / 4
    bra     .L_edge3_bounds_check       ! go to bounds check
    mov.l r14, @r11                     ! (delay) vtx[3].y = nudged Y
.L_x_upper_bound_2:
    .2byte  0x0195                      ! 405: screen X upper bound
.L_y_upper_bound_2:
    .2byte  0x0131                      ! 305: screen Y upper bound
.L_edge3_try_vtx2:
    ! -- clip_flag[0] is set; try neighbor = vtx[2] instead --
    mov.l @(8, r15), r2                 ! r2 = &clip_flag[2]
    mov.w @r2, r3                       ! r3 = clip_flag[2]
    extu.w r3, r3                       ! zero-extend
    tst r3, r3                          ! test if clip_flag[2] == 0
    bf      .L_edge3_bounds_check       ! if flag[2] also set, skip nudge
    ! -- neighbor = vtx[2]: nudge vtx[3] toward vtx[2] --
    mov.l @r8, r3                       ! r3 = vtx[2].x
    mov.l @r9, r2                       ! r2 = vtx[2].y
    add r3, r13                         ! r13 = vtx[3].x*3 + vtx[2].x
    add r2, r14                         ! r14 = vtx[3].y*3 + vtx[2].y
    shar r13                            ! r13 /= 2
    shar r14                            ! r14 /= 2
    shar r13                            ! r13 /= 2 => (3*x3 + x2) / 4
    mov.l r13, @r10                     ! vtx[3].x = nudged X
    shar r14                            ! r14 /= 2 => (3*y3 + y2) / 4
    mov.l r14, @r11                     ! vtx[3].y = nudged Y
.L_edge3_bounds_check:
    mov.l @r10, r14                     ! r14 = vtx[3].x (possibly nudged)
    cmp/ge r6, r14                      ! test vtx[3].x >= -405
    bf      .L_edge3_done               ! fail: X below lower bound
    mov.w   .L_x_upper_bound_3, r2      ! r2 = 405 (0x0195)
    cmp/gt r2, r14                      ! test vtx[3].x > 405
    bt      .L_edge3_done               ! fail: X above upper bound
    mov.l @r11, r14                     ! r14 = vtx[3].y
    cmp/ge r6, r14                      ! test vtx[3].y >= -405
    bf      .L_edge3_done               ! fail: Y below lower bound
    mov.w   .L_y_upper_bound_3, r3      ! r3 = 305 (0x0131)
    cmp/gt r3, r14                      ! test vtx[3].y > 305
    bt      .L_edge3_done               ! fail: Y above upper bound
    ! -- vertex 3 is now in bounds --
    mov.l @(32, r15), r3                ! r3 = &vis[3]
    exts.w r7, r2                       ! r2 = 0x0 (visible)
    mov.w r2, @r3                       ! vis[3] = 0 (mark visible)
! ---- convergence check: any vertex still out of bounds? ----
.L_edge3_done:
    mov.l @(28, r15), r3                ! r3 = &vis[0]
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    mov.l @(24, r15), r1                ! r1 = &vis[2]
    mov.w @r3, r3                       ! r3 = vis[0]
    mov.w @r2, r2                       ! r2 = vis[1]
    or r2, r3                           ! r3 = vis[0] | vis[1]
    mov.w @r1, r2                       ! r2 = vis[2]
    or r2, r3                           ! r3 |= vis[2]
    mov.l @(32, r15), r1                ! r1 = &vis[3]
    mov.w @r1, r2                       ! r2 = vis[3]
    or r2, r3                           ! r3 |= vis[3]
    tst r3, r3                          ! test if all vis flags == 0
    bf      .L_not_converged            ! if any nonzero, keep iterating
    bra     .L_epilogue                 ! all vertices in bounds -- done
    nop                                 ! (delay) no-op
.L_not_converged:
    bra     .L_clip_loop                ! iterate again
    nop                                 ! (delay) no-op
.L_epilogue:
    add #0x2C, r15                      ! deallocate stack frame
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14
.L_x_upper_bound_3:
    .2byte  0x0195                      ! 405: screen X upper bound
.L_y_upper_bound_3:
    .2byte  0x0131                      ! 305: screen Y upper bound
