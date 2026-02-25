/* render_obj_processor -- screen-space quad vertex clipper (variant C, 4-vertex)
 * Translation unit: 0x06022AE0 - 0x0602304C
 *
 * Called from the 3D rendering pipeline (scene_proc_d / scene_proc_e / mega_render_func)
 * as the 4-vertex partial-clip combine handler.  This is the third and final
 * clip-combine handler in the pipeline function table:
 *   entry 2: vblank_frame_handler  (2-vertex clip)
 *   entry 3: render_list_builder   (3-vertex clip)
 *   entry 4: render_obj_processor  (4-vertex clip -- this file)
 *
 * Algorithm:
 *   Finds the first on-screen vertex (anchor) among the 4 quad vertices
 *   by checking clip_flag[0..3] in order.  Once an anchor is found, all
 *   other vertices that are still off-screen are iteratively nudged toward
 *   the anchor using a weighted average:
 *     new_coord = (3 * off_screen_coord + anchor_coord) / 4
 *   This is computed as: shll (x2), add original (x3), add anchor, shar x2 (/4).
 *
 *   After each nudge, the result is range-checked against screen bounds:
 *     X in [-405, +405]  (0xFE6B .. 0x0195)
 *     Y in [-405, +305]  (0xFE6B .. 0x0131)
 *   If the nudged vertex passes bounds, its visibility flag is cleared (= 0).
 *
 *   The loop repeats until all 4 visibility flags reach zero (all vertices
 *   in-bounds) or no further progress is possible.
 *
 * Four anchor paths handle the combinations:
 *   Path A: vtx[0] on-screen => nudge vtx[1], vtx[2], vtx[3] toward vtx[0]
 *   Path B: vtx[1] on-screen => nudge vtx[0], vtx[2], vtx[3] toward vtx[1]
 *   Path C: vtx[2] on-screen => nudge vtx[0], vtx[1], vtx[3] toward vtx[2]
 *   Path D: vtx[3] on-screen => nudge vtx[0], vtx[1], vtx[2] toward vtx[3]
 *
 * Arguments:
 *   r4 = vertex coordinate array (8 x int32: x0, y0, x1, y1, x2, y2, x3, y3)
 *   r5 = clip flags array (4 x int16: flag0, flag1, flag2, flag3)
 *
 * Returns: modifies vertex coords in-place via r4; clears visibility flags
 *
 * Register map (after prologue):
 *   r4  = &vtx[0].x          (vertex 0 X coord ptr)
 *   r11 = &vtx[0].y          (r4 + 0x04)
 *   r14 = &vtx[1].x          (r4 + 0x08)
 *   r9  = &vtx[1].y          (r4 + 0x0C)
 *   r8  = &vtx[2].x          (r4 + 0x10)
 *   r10 = &vtx[2].y          (r4 + 0x14)
 *   r12 = &vtx[3].x          (r4 + 0x18)
 *   r13 = &vtx[3].y          (r4 + 0x1C)
 *   r5  = &clip_flag[0]
 *   r6  = -405 (screen coord lower bound)
 *   r7  = 0x0000 (visible flag constant)
 *
 * Stack frame (0x2C = 44 bytes):
 *   sp[0]  = scratch X intermediate
 *   sp[4]  = scratch Y intermediate
 *   sp[8]  = &vis[2] ptr
 *   sp[12] = &vis[1] ptr
 *   sp[16] = &vis[3] ptr
 *   sp[20] = &vis[0] ptr
 *   sp[24] = &clip_flag[2] ptr
 *   sp[28] = &clip_flag[1] ptr
 *   sp[32] = &clip_flag[3] ptr
 */

    .section .text.FUN_06022AE0


    .global render_obj_processor
    .type render_obj_processor, @function
render_obj_processor:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    mov.l r10, @-r15                    ! save r10
    mov.l r9, @-r15                     ! save r9
    mov.l r8, @-r15                     ! save r8
    add #-0x2C, r15                     ! allocate 0x2C (44) bytes of stack frame
    mov #0x0, r7                        ! r7 = 0 (visible flag = on-screen)
    mov.w   _wpool_coord_lower_bound, r6 ! r6 = -405 (0xFE6B) screen lower bound
    mov r15, r14                        ! r14 = sp (local vis array base)
    add #0x24, r14                      ! r14 = &vis[0] (sp + 0x24)
    mov r14, r3                         ! r3 = &vis[0]
    mov.l r3, @(20, r15)               ! sp[20] = &vis[0] ptr
    mov.w @r5, r2                       ! r2 = clip_flag[0]
    mov.w r2, @r3                       ! vis[0] = clip_flag[0] (init from input flags)
    add #0x2, r3                        ! r3 = &vis[1]
    mov.l r3, @(12, r15)               ! sp[12] = &vis[1] ptr
    mov r5, r2                          ! r2 = clip_flags base
    add #0x2, r2                        ! r2 = &clip_flag[1]
    mov.l r2, @(28, r15)               ! sp[28] = &clip_flag[1] ptr
    mov.w @r2, r1                       ! r1 = clip_flag[1]
    mov.w r1, @r3                       ! vis[1] = clip_flag[1]
    mov r14, r3                         ! r3 = &vis[0]
    add #0x4, r3                        ! r3 = &vis[2]
    mov.l r3, @(8, r15)                ! sp[8] = &vis[2] ptr
    mov r5, r2                          ! r2 = clip_flags base
    add #0x4, r2                        ! r2 = &clip_flag[2]
    mov.l r2, @(24, r15)               ! sp[24] = &clip_flag[2] ptr
    mov.w @r2, r1                       ! r1 = clip_flag[2]
    mov.w r1, @r3                       ! vis[2] = clip_flag[2]
    add #0x6, r14                       ! r14 = vis[0]+6 = &vis[3]
    mov.l r14, @(16, r15)              ! sp[16] = &vis[3] ptr
    mov r5, r3                          ! r3 = clip_flags base
    add #0x6, r3                        ! r3 = &clip_flag[3]
    mov.l r3, @(32, r15)               ! sp[32] = &clip_flag[3] ptr
    mov.w @r3, r2                       ! r2 = clip_flag[3]
    mov.w r2, @r14                      ! vis[3] = clip_flag[3]
    mov r4, r14                         ! r14 = vtx base
    add #0x8, r14                       ! r14 = &vtx[1].x (r4 + 0x08)
    mov r4, r9                          ! r9 = vtx base
    add #0xC, r9                        ! r9 = &vtx[1].y (r4 + 0x0C)
    mov r4, r11                         ! r11 = vtx base
    add #0x4, r11                       ! r11 = &vtx[0].y (r4 + 0x04)
    mov r4, r8                          ! r8 = vtx base
    add #0x10, r8                       ! r8 = &vtx[2].x (r4 + 0x10)
    mov r4, r10                         ! r10 = vtx base
    add #0x14, r10                      ! r10 = &vtx[2].y (r4 + 0x14)
    mov r4, r12                         ! r12 = vtx base
    add #0x18, r12                      ! r12 = &vtx[3].x (r4 + 0x18)
    mov r4, r13                         ! r13 = vtx base
    add #0x1C, r13                      ! r13 = &vtx[3].y (r4 + 0x1C)
! ---- main clipping loop: process all 4 edges each iteration ----
.L_clip_loop:
    mov.w @r5, r2                       ! r2 = clip_flag[0]
    extu.w r2, r2                       ! zero-extend to 32-bit
    tst r2, r2                          ! test if flag[0] == 0
    bt      .L_pathA_vtx0_anchor        ! if vtx[0] on-screen, use as anchor
    bra     .L_pathB_check              ! else check vtx[1]
    nop                                 ! (delay slot)
! ==== Path A: vtx[0] is on-screen — nudge other vertices toward vtx[0] ====
.L_pathA_vtx0_anchor:
    mov.l @(12, r15), r3                ! r3 = &vis[1]
    mov.w @r3, r0                       ! r0 = vis[1]
    tst r0, r0                          ! test if vis[1] == 0
    bt      .L_pathA_edge01_done        ! skip edge 0→1 if vtx[1] already visible
    ! -- nudge vtx[1] toward vtx[0]: new = (3*vtx[1] + vtx[0]) / 4 --
    mov.l @r14, r3                      ! r3 = vtx[1].x
    mov.l @r4, r1                       ! r1 = vtx[0].x (anchor)
    mov r3, r2                          ! r2 = vtx[1].x (backup)
    shll r3                             ! r3 = vtx[1].x * 2
    add r2, r3                          ! r3 = vtx[1].x * 3
    add r1, r3                          ! r3 = vtx[1].x * 3 + vtx[0].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r9, r2                       ! r2 = vtx[1].y
    mov.l @r11, r0                      ! r0 = vtx[0].y (anchor)
    mov r2, r1                          ! r1 = vtx[1].y (backup)
    shll r2                             ! r2 = vtx[1].y * 2
    add r1, r2                          ! r2 = vtx[1].y * 3
    add r0, r2                          ! r2 = vtx[1].y * 3 + vtx[0].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x1 + x0) / 4
    mov.l r1, @r14                      ! vtx[1].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y1 + y0) / 4
    mov.l r3, @r9                       ! vtx[1].y = nudged Y
    ! -- bounds check nudged vtx[1] --
    mov.l @r14, r3                      ! r3 = nudged vtx[1].x
    mov.l r3, @r15                      ! sp[0] = vtx[1].x (for later)
    cmp/ge r6, r3                       ! test vtx[1].x >= -405
    bf      .L_pathA_edge01_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[1].x
    mov.w   _wpool_x_upper_A, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[1].x > +405
    bt      .L_pathA_edge01_done        ! fail upper X bound => skip
    mov.l @r9, r2                       ! r2 = nudged vtx[1].y
    mov r2, r3                          ! r3 = vtx[1].y
    cmp/ge r6, r3                       ! test vtx[1].y >= -405
    bf/s    .L_pathA_edge01_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[1].y
    mov.l @r15, r2                      ! r2 = vtx[1].y
    mov.w   _wpool_y_upper_A, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[1].y > +305
    bt      .L_pathA_edge01_done        ! fail upper Y bound => skip
    ! -- vtx[1] now in bounds: clear vis[1] --
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[1] = 0 (mark visible)
.L_pathA_edge01_done:
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    mov.w @r2, r0                       ! r0 = vis[2]
    tst r0, r0                          ! test if vis[2] == 0
    bra     .L_pathA_test_vis2          ! (delayed branch past word pool)
    nop                                 ! (delay slot)
_wpool_coord_lower_bound:
    .2byte  0xFE6B                      ! -405 signed: screen coordinate lower bound
_wpool_x_upper_A:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_A:
    .2byte  0x0131                      ! +305: screen Y upper bound
.L_pathA_test_vis2:
    bt      .L_pathA_edge02_done        ! skip edge 0→2 if vtx[2] already visible
    ! -- nudge vtx[2] toward vtx[0]: new = (3*vtx[2] + vtx[0]) / 4 --
    mov.l @r8, r3                       ! r3 = vtx[2].x
    mov.l @r4, r1                       ! r1 = vtx[0].x (anchor)
    mov r3, r2                          ! r2 = vtx[2].x (backup)
    shll r3                             ! r3 = vtx[2].x * 2
    add r2, r3                          ! r3 = vtx[2].x * 3
    add r1, r3                          ! r3 = vtx[2].x * 3 + vtx[0].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r10, r2                      ! r2 = vtx[2].y
    mov.l @r11, r0                      ! r0 = vtx[0].y (anchor)
    mov r2, r1                          ! r1 = vtx[2].y (backup)
    shll r2                             ! r2 = vtx[2].y * 2
    add r1, r2                          ! r2 = vtx[2].y * 3
    add r0, r2                          ! r2 = vtx[2].y * 3 + vtx[0].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x2 + x0) / 4
    mov.l r1, @r8                       ! vtx[2].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y2 + y0) / 4
    mov.l r3, @r10                      ! vtx[2].y = nudged Y
    ! -- bounds check nudged vtx[2] --
    mov.l @r8, r3                       ! r3 = nudged vtx[2].x
    mov.l r3, @r15                      ! sp[0] = vtx[2].x
    cmp/ge r6, r3                       ! test vtx[2].x >= -405
    bf      .L_pathA_edge02_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[2].x
    mov.w   _wpool_x_upper_B, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[2].x > +405
    bt      .L_pathA_edge02_done        ! fail upper X bound => skip
    mov.l @r10, r2                      ! r2 = nudged vtx[2].y
    mov r2, r3                          ! r3 = vtx[2].y
    cmp/ge r6, r3                       ! test vtx[2].y >= -405
    bf/s    .L_pathA_edge02_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[2].y
    mov.l @r15, r2                      ! r2 = vtx[2].y
    mov.w   _wpool_y_upper_B, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[2].y > +305
    bt      .L_pathA_edge02_done        ! fail upper Y bound => skip
    ! -- vtx[2] now in bounds: clear vis[2] --
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[2] = 0 (mark visible)
.L_pathA_edge02_done:
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    mov.w @r2, r0                       ! r0 = vis[3]
    tst r0, r0                          ! test if vis[3] == 0
    bf      .L_pathA_nudge_vtx3         ! if vis[3] != 0, nudge vtx[3]
    bra     .L_check_convergence        ! else all done this iteration
    nop                                 ! (delay slot)
.L_pathA_nudge_vtx3:
    ! -- nudge vtx[3] toward vtx[0]: new = (3*vtx[3] + vtx[0]) / 4 --
    mov.l @r12, r3                      ! r3 = vtx[3].x
    mov.l @r4, r1                       ! r1 = vtx[0].x (anchor)
    mov r3, r2                          ! r2 = vtx[3].x (backup)
    shll r3                             ! r3 = vtx[3].x * 2
    add r2, r3                          ! r3 = vtx[3].x * 3
    add r1, r3                          ! r3 = vtx[3].x * 3 + vtx[0].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r13, r2                      ! r2 = vtx[3].y
    mov.l @r11, r0                      ! r0 = vtx[0].y (anchor)
    mov r2, r1                          ! r1 = vtx[3].y (backup)
    shll r2                             ! r2 = vtx[3].y * 2
    add r1, r2                          ! r2 = vtx[3].y * 3
    add r0, r2                          ! r2 = vtx[3].y * 3 + vtx[0].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x3 + x0) / 4
    mov.l r1, @r12                      ! vtx[3].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y3 + y0) / 4
    mov.l r3, @r13                      ! vtx[3].y = nudged Y
    ! -- bounds check nudged vtx[3] --
    mov.l @r12, r3                      ! r3 = nudged vtx[3].x
    mov.l r3, @r15                      ! sp[0] = vtx[3].x
    cmp/ge r6, r3                       ! test vtx[3].x >= -405
    bf      .L_pathA_edge03_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[3].x
    mov.w   _wpool_x_upper_B, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[3].x > +405
    bt      .L_pathA_edge03_done        ! fail upper X bound => skip
    mov.l @r13, r2                      ! r2 = nudged vtx[3].y
    mov r2, r3                          ! r3 = vtx[3].y
    cmp/ge r6, r3                       ! test vtx[3].y >= -405
    bf/s    .L_pathA_edge03_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[3].y
    mov.l @r15, r2                      ! r2 = vtx[3].y
    mov.w   _wpool_y_upper_B, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[3].y > +305
    bt      .L_pathA_edge03_done        ! fail upper Y bound => skip
    ! -- vtx[3] now in bounds: clear vis[3] --
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[3] = 0 (mark visible)
.L_pathA_edge03_done:
    bra     .L_check_convergence        ! done with Path A iteration
    nop                                 ! (delay slot)
_wpool_x_upper_B:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_B:
    .2byte  0x0131                      ! +305: screen Y upper bound
! ==== Path B: vtx[0] off-screen, check if vtx[1] is on-screen ====
.L_pathB_check:
    mov.l @(28, r15), r2                ! r2 = &clip_flag[1]
    mov.w @r2, r3                       ! r3 = clip_flag[1]
    extu.w r3, r3                       ! zero-extend to 32-bit
    tst r3, r3                          ! test if flag[1] == 0
    bt      .L_pathB_vtx1_anchor        ! if vtx[1] on-screen, use as anchor
    bra     .L_pathC_check              ! else check vtx[2]
    nop                                 ! (delay slot)
.L_pathB_vtx1_anchor:
    ! -- nudge vtx[0] toward vtx[1] --
    mov.l @(20, r15), r3                ! r3 = &vis[0]
    mov.w @r3, r0                       ! r0 = vis[0]
    tst r0, r0                          ! test if vis[0] == 0
    bt      .L_pathB_edge10_done        ! skip if vtx[0] already visible
    ! -- nudge vtx[0] toward vtx[1]: new = (3*vtx[0] + vtx[1]) / 4 --
    mov.l @r4, r3                       ! r3 = vtx[0].x
    mov.l @r14, r1                      ! r1 = vtx[1].x (anchor)
    mov r3, r2                          ! r2 = vtx[0].x (backup)
    shll r3                             ! r3 = vtx[0].x * 2
    add r2, r3                          ! r3 = vtx[0].x * 3
    add r1, r3                          ! r3 = vtx[0].x * 3 + vtx[1].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r11, r2                      ! r2 = vtx[0].y
    mov.l @r9, r0                       ! r0 = vtx[1].y (anchor)
    mov r2, r1                          ! r1 = vtx[0].y (backup)
    shll r2                             ! r2 = vtx[0].y * 2
    add r1, r2                          ! r2 = vtx[0].y * 3
    add r0, r2                          ! r2 = vtx[0].y * 3 + vtx[1].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x0 + x1) / 4
    mov.l r1, @r4                       ! vtx[0].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y0 + y1) / 4
    mov.l r3, @r11                      ! vtx[0].y = nudged Y
    ! -- bounds check nudged vtx[0] --
    mov.l @r4, r3                       ! r3 = nudged vtx[0].x
    mov.l r3, @r15                      ! sp[0] = vtx[0].x
    cmp/ge r6, r3                       ! test vtx[0].x >= -405
    bf      .L_pathB_edge10_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[0].x
    mov.w   _wpool_x_upper_C, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[0].x > +405
    bt      .L_pathB_edge10_done        ! fail upper X bound => skip
    mov.l @r11, r2                      ! r2 = nudged vtx[0].y
    mov r2, r3                          ! r3 = vtx[0].y
    cmp/ge r6, r3                       ! test vtx[0].y >= -405
    bf/s    .L_pathB_edge10_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[0].y
    mov.l @r15, r2                      ! r2 = vtx[0].y
    mov.w   _wpool_y_upper_C, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[0].y > +305
    bt      .L_pathB_edge10_done        ! fail upper Y bound => skip
    ! -- vtx[0] now in bounds: clear vis[0] --
    mov.l @(20, r15), r2                ! r2 = &vis[0]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[0] = 0 (mark visible)
.L_pathB_edge10_done:
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    mov.w @r2, r0                       ! r0 = vis[2]
    tst r0, r0                          ! test if vis[2] == 0
    bt      .L_pathB_edge12_done        ! skip if vtx[2] already visible
    ! -- nudge vtx[2] toward vtx[1]: new = (3*vtx[2] + vtx[1]) / 4 --
    mov.l @r8, r3                       ! r3 = vtx[2].x
    mov.l @r14, r1                      ! r1 = vtx[1].x (anchor)
    mov r3, r2                          ! r2 = vtx[2].x (backup)
    shll r3                             ! r3 = vtx[2].x * 2
    add r2, r3                          ! r3 = vtx[2].x * 3
    add r1, r3                          ! r3 = vtx[2].x * 3 + vtx[1].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r10, r2                      ! r2 = vtx[2].y
    mov.l @r9, r0                       ! r0 = vtx[1].y (anchor)
    mov r2, r1                          ! r1 = vtx[2].y (backup)
    shll r2                             ! r2 = vtx[2].y * 2
    add r1, r2                          ! r2 = vtx[2].y * 3
    add r0, r2                          ! r2 = vtx[2].y * 3 + vtx[1].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x2 + x1) / 4
    mov.l r1, @r8                       ! vtx[2].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y2 + y1) / 4
    mov.l r3, @r10                      ! vtx[2].y = nudged Y
    ! -- bounds check nudged vtx[2] --
    mov.l @r8, r3                       ! r3 = nudged vtx[2].x
    mov.l r3, @r15                      ! sp[0] = vtx[2].x
    cmp/ge r6, r3                       ! test vtx[2].x >= -405
    bf      .L_pathB_edge12_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[2].x
    mov.w   _wpool_x_upper_C, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[2].x > +405
    bt      .L_pathB_edge12_done        ! fail upper X bound => skip
    mov.l @r10, r2                      ! r2 = nudged vtx[2].y
    mov r2, r3                          ! r3 = vtx[2].y
    cmp/ge r6, r3                       ! test vtx[2].y >= -405
    bf/s    .L_pathB_edge12_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[2].y
    mov.l @r15, r2                      ! r2 = vtx[2].y
    mov.w   _wpool_y_upper_C, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[2].y > +305
    bt      .L_pathB_edge12_done        ! fail upper Y bound => skip
    ! -- vtx[2] now in bounds: clear vis[2] --
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[2] = 0 (mark visible)
.L_pathB_edge12_done:
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    mov.w @r2, r0                       ! r0 = vis[3]
    tst r0, r0                          ! test if vis[3] == 0
    bra     .L_pathB_test_vis3          ! (delayed branch past word pool)
    nop                                 ! (delay slot)
_wpool_x_upper_C:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_C:
    .2byte  0x0131                      ! +305: screen Y upper bound
.L_pathB_test_vis3:
    bf      .L_pathB_nudge_vtx3         ! if vis[3] != 0, nudge vtx[3]
    bra     .L_check_convergence        ! else done with Path B
    nop                                 ! (delay slot)
.L_pathB_nudge_vtx3:
    ! -- nudge vtx[3] toward vtx[1]: new = (3*vtx[3] + vtx[1]) / 4 --
    mov.l @r12, r3                      ! r3 = vtx[3].x
    mov.l @r14, r1                      ! r1 = vtx[1].x (anchor)
    mov r3, r2                          ! r2 = vtx[3].x (backup)
    shll r3                             ! r3 = vtx[3].x * 2
    add r2, r3                          ! r3 = vtx[3].x * 3
    add r1, r3                          ! r3 = vtx[3].x * 3 + vtx[1].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r13, r2                      ! r2 = vtx[3].y
    mov.l @r9, r0                       ! r0 = vtx[1].y (anchor)
    mov r2, r1                          ! r1 = vtx[3].y (backup)
    shll r2                             ! r2 = vtx[3].y * 2
    add r1, r2                          ! r2 = vtx[3].y * 3
    add r0, r2                          ! r2 = vtx[3].y * 3 + vtx[1].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x3 + x1) / 4
    mov.l r1, @r12                      ! vtx[3].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y3 + y1) / 4
    mov.l r3, @r13                      ! vtx[3].y = nudged Y
    ! -- bounds check nudged vtx[3] --
    mov.l @r12, r3                      ! r3 = nudged vtx[3].x
    mov.l r3, @r15                      ! sp[0] = vtx[3].x
    cmp/ge r6, r3                       ! test vtx[3].x >= -405
    bf      .L_pathB_edge13_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[3].x
    mov.w   _wpool_x_upper_D, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[3].x > +405
    bt      .L_pathB_edge13_done        ! fail upper X bound => skip
    mov.l @r13, r2                      ! r2 = nudged vtx[3].y
    mov r2, r3                          ! r3 = vtx[3].y
    cmp/ge r6, r3                       ! test vtx[3].y >= -405
    bf/s    .L_pathB_edge13_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[3].y
    mov.l @r15, r2                      ! r2 = vtx[3].y
    mov.w   _wpool_y_upper_D, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[3].y > +305
    bt      .L_pathB_edge13_done        ! fail upper Y bound => skip
    ! -- vtx[3] now in bounds: clear vis[3] --
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[3] = 0 (mark visible)
.L_pathB_edge13_done:
    bra     .L_check_convergence        ! done with Path B iteration
    nop                                 ! (delay slot)
_wpool_x_upper_D:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_D:
    .2byte  0x0131                      ! +305: screen Y upper bound
! ==== Path C: vtx[0,1] off-screen, check if vtx[2] is on-screen ====
.L_pathC_check:
    mov.l @(24, r15), r2                ! r2 = &clip_flag[2]
    mov.w @r2, r3                       ! r3 = clip_flag[2]
    extu.w r3, r3                       ! zero-extend to 32-bit
    tst r3, r3                          ! test if flag[2] == 0
    bt      .L_pathC_vtx2_anchor        ! if vtx[2] on-screen, use as anchor
    bra     .L_pathD_check              ! else check vtx[3]
    nop                                 ! (delay slot)
.L_pathC_vtx2_anchor:
    ! -- nudge vtx[0] toward vtx[2] --
    mov.l @(20, r15), r3                ! r3 = &vis[0]
    mov.w @r3, r0                       ! r0 = vis[0]
    tst r0, r0                          ! test if vis[0] == 0
    bt      .L_pathC_edge20_done        ! skip if vtx[0] already visible
    ! -- nudge vtx[0] toward vtx[2]: new = (3*vtx[0] + vtx[2]) / 4 --
    mov.l @r4, r3                       ! r3 = vtx[0].x
    mov.l @r8, r1                       ! r1 = vtx[2].x (anchor)
    mov r3, r2                          ! r2 = vtx[0].x (backup)
    shll r3                             ! r3 = vtx[0].x * 2
    add r2, r3                          ! r3 = vtx[0].x * 3
    add r1, r3                          ! r3 = vtx[0].x * 3 + vtx[2].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r11, r2                      ! r2 = vtx[0].y
    mov.l @r10, r0                      ! r0 = vtx[2].y (anchor)
    mov r2, r1                          ! r1 = vtx[0].y (backup)
    shll r2                             ! r2 = vtx[0].y * 2
    add r1, r2                          ! r2 = vtx[0].y * 3
    add r0, r2                          ! r2 = vtx[0].y * 3 + vtx[2].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x0 + x2) / 4
    mov.l r1, @r4                       ! vtx[0].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y0 + y2) / 4
    mov.l r3, @r11                      ! vtx[0].y = nudged Y
    ! -- bounds check nudged vtx[0] --
    mov.l @r4, r3                       ! r3 = nudged vtx[0].x
    mov.l r3, @r15                      ! sp[0] = vtx[0].x
    cmp/ge r6, r3                       ! test vtx[0].x >= -405
    bf      .L_pathC_edge20_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[0].x
    mov.w   _wpool_x_upper_E, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[0].x > +405
    bt      .L_pathC_edge20_done        ! fail upper X bound => skip
    mov.l @r11, r2                      ! r2 = nudged vtx[0].y
    mov r2, r3                          ! r3 = vtx[0].y
    cmp/ge r6, r3                       ! test vtx[0].y >= -405
    bf/s    .L_pathC_edge20_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[0].y
    mov.l @r15, r2                      ! r2 = vtx[0].y
    mov.w   _wpool_y_upper_E, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[0].y > +305
    bt      .L_pathC_edge20_done        ! fail upper Y bound => skip
    ! -- vtx[0] now in bounds: clear vis[0] --
    mov.l @(20, r15), r2                ! r2 = &vis[0]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[0] = 0 (mark visible)
.L_pathC_edge20_done:
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    mov.w @r2, r0                       ! r0 = vis[1]
    tst r0, r0                          ! test if vis[1] == 0
    bt      .L_pathC_edge21_done        ! skip if vtx[1] already visible
    ! -- nudge vtx[1] toward vtx[2]: new = (3*vtx[1] + vtx[2]) / 4 --
    mov.l @r14, r3                      ! r3 = vtx[1].x
    mov.l @r8, r1                       ! r1 = vtx[2].x (anchor)
    mov r3, r2                          ! r2 = vtx[1].x (backup)
    shll r3                             ! r3 = vtx[1].x * 2
    add r2, r3                          ! r3 = vtx[1].x * 3
    add r1, r3                          ! r3 = vtx[1].x * 3 + vtx[2].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r9, r2                       ! r2 = vtx[1].y
    mov.l @r10, r0                      ! r0 = vtx[2].y (anchor)
    mov r2, r1                          ! r1 = vtx[1].y (backup)
    shll r2                             ! r2 = vtx[1].y * 2
    add r1, r2                          ! r2 = vtx[1].y * 3
    add r0, r2                          ! r2 = vtx[1].y * 3 + vtx[2].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x1 + x2) / 4
    mov.l r1, @r14                      ! vtx[1].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y1 + y2) / 4
    mov.l r3, @r9                       ! vtx[1].y = nudged Y
    ! -- bounds check nudged vtx[1] --
    mov.l @r14, r3                      ! r3 = nudged vtx[1].x
    mov.l r3, @r15                      ! sp[0] = vtx[1].x
    cmp/ge r6, r3                       ! test vtx[1].x >= -405
    bf      .L_pathC_edge21_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[1].x
    mov.w   _wpool_x_upper_E, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[1].x > +405
    bt      .L_pathC_edge21_done        ! fail upper X bound => skip
    mov.l @r9, r2                       ! r2 = nudged vtx[1].y
    mov r2, r3                          ! r3 = vtx[1].y
    cmp/ge r6, r3                       ! test vtx[1].y >= -405
    bf/s    .L_pathC_edge21_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[1].y
    mov.l @r15, r2                      ! r2 = vtx[1].y
    mov.w   _wpool_y_upper_E, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[1].y > +305
    bt      .L_pathC_edge21_done        ! fail upper Y bound => skip
    ! -- vtx[1] now in bounds: clear vis[1] --
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[1] = 0 (mark visible)
.L_pathC_edge21_done:
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    mov.w @r2, r0                       ! r0 = vis[3]
    tst r0, r0                          ! test if vis[3] == 0
    bra     .L_pathC_test_vis3          ! (delayed branch past word pool)
    nop                                 ! (delay slot)
_wpool_x_upper_E:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_E:
    .2byte  0x0131                      ! +305: screen Y upper bound
.L_pathC_test_vis3:
    bf      .L_pathC_nudge_vtx3         ! if vis[3] != 0, nudge vtx[3]
    bra     .L_check_convergence        ! else done with Path C
    nop                                 ! (delay slot)
.L_pathC_nudge_vtx3:
    ! -- nudge vtx[3] toward vtx[2]: new = (3*vtx[3] + vtx[2]) / 4 --
    mov.l @r12, r3                      ! r3 = vtx[3].x
    mov.l @r8, r1                       ! r1 = vtx[2].x (anchor)
    mov r3, r2                          ! r2 = vtx[3].x (backup)
    shll r3                             ! r3 = vtx[3].x * 2
    add r2, r3                          ! r3 = vtx[3].x * 3
    add r1, r3                          ! r3 = vtx[3].x * 3 + vtx[2].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r13, r2                      ! r2 = vtx[3].y
    mov.l @r10, r0                      ! r0 = vtx[2].y (anchor)
    mov r2, r1                          ! r1 = vtx[3].y (backup)
    shll r2                             ! r2 = vtx[3].y * 2
    add r1, r2                          ! r2 = vtx[3].y * 3
    add r0, r2                          ! r2 = vtx[3].y * 3 + vtx[2].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x3 + x2) / 4
    mov.l r1, @r12                      ! vtx[3].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y3 + y2) / 4
    mov.l r3, @r13                      ! vtx[3].y = nudged Y
    ! -- bounds check nudged vtx[3] --
    mov.l @r12, r3                      ! r3 = nudged vtx[3].x
    mov.l r3, @r15                      ! sp[0] = vtx[3].x
    cmp/ge r6, r3                       ! test vtx[3].x >= -405
    bf      .L_pathC_edge23_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[3].x
    mov.w   _wpool_x_upper_F, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[3].x > +405
    bt      .L_pathC_edge23_done        ! fail upper X bound => skip
    mov.l @r13, r2                      ! r2 = nudged vtx[3].y
    mov r2, r3                          ! r3 = vtx[3].y
    cmp/ge r6, r3                       ! test vtx[3].y >= -405
    bf/s    .L_pathC_edge23_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[3].y
    mov.l @r15, r2                      ! r2 = vtx[3].y
    mov.w   _wpool_y_upper_F, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[3].y > +305
    bt      .L_pathC_edge23_done        ! fail upper Y bound => skip
    ! -- vtx[3] now in bounds: clear vis[3] --
    mov.l @(16, r15), r2                ! r2 = &vis[3]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[3] = 0 (mark visible)
.L_pathC_edge23_done:
    bra     .L_check_convergence        ! done with Path C iteration
    nop                                 ! (delay slot)
_wpool_x_upper_F:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_F:
    .2byte  0x0131                      ! +305: screen Y upper bound
! ==== Path D: vtx[0,1,2] off-screen, check if vtx[3] is on-screen ====
.L_pathD_check:
    mov.l @(32, r15), r2                ! r2 = &clip_flag[3]
    mov.w @r2, r3                       ! r3 = clip_flag[3]
    extu.w r3, r3                       ! zero-extend to 32-bit
    tst r3, r3                          ! test if flag[3] == 0
    bt      .L_pathD_vtx3_anchor        ! if vtx[3] on-screen, use as anchor
    bra     .L_check_convergence        ! else no anchor found, end iteration
    nop                                 ! (delay slot)
.L_pathD_vtx3_anchor:
    ! -- nudge vtx[0] toward vtx[3] --
    mov.l @(20, r15), r3                ! r3 = &vis[0]
    mov.w @r3, r0                       ! r0 = vis[0]
    tst r0, r0                          ! test if vis[0] == 0
    bt      .L_pathD_edge30_done        ! skip if vtx[0] already visible
    ! -- nudge vtx[0] toward vtx[3]: new = (3*vtx[0] + vtx[3]) / 4 --
    mov.l @r4, r3                       ! r3 = vtx[0].x
    mov.l @r12, r1                      ! r1 = vtx[3].x (anchor)
    mov r3, r2                          ! r2 = vtx[0].x (backup)
    shll r3                             ! r3 = vtx[0].x * 2
    add r2, r3                          ! r3 = vtx[0].x * 3
    add r1, r3                          ! r3 = vtx[0].x * 3 + vtx[3].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r11, r2                      ! r2 = vtx[0].y
    mov.l @r13, r0                      ! r0 = vtx[3].y (anchor)
    mov r2, r1                          ! r1 = vtx[0].y (backup)
    shll r2                             ! r2 = vtx[0].y * 2
    add r1, r2                          ! r2 = vtx[0].y * 3
    add r0, r2                          ! r2 = vtx[0].y * 3 + vtx[3].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x0 + x3) / 4
    mov.l r1, @r4                       ! vtx[0].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y0 + y3) / 4
    mov.l r3, @r11                      ! vtx[0].y = nudged Y
    ! -- bounds check nudged vtx[0] --
    mov.l @r4, r3                       ! r3 = nudged vtx[0].x
    mov.l r3, @r15                      ! sp[0] = vtx[0].x
    cmp/ge r6, r3                       ! test vtx[0].x >= -405
    bf      .L_pathD_edge30_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[0].x
    mov.w   _wpool_x_upper_G, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[0].x > +405
    bt      .L_pathD_edge30_done        ! fail upper X bound => skip
    mov.l @r11, r2                      ! r2 = nudged vtx[0].y
    mov r2, r3                          ! r3 = vtx[0].y
    cmp/ge r6, r3                       ! test vtx[0].y >= -405
    bf/s    .L_pathD_edge30_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[0].y
    mov.l @r15, r2                      ! r2 = vtx[0].y
    mov.w   _wpool_y_upper_G, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[0].y > +305
    bt      .L_pathD_edge30_done        ! fail upper Y bound => skip
    ! -- vtx[0] now in bounds: clear vis[0] --
    mov.l @(20, r15), r2                ! r2 = &vis[0]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[0] = 0 (mark visible)
.L_pathD_edge30_done:
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    mov.w @r2, r0                       ! r0 = vis[1]
    tst r0, r0                          ! test if vis[1] == 0
    bt      .L_pathD_edge31_done        ! skip if vtx[1] already visible
    ! -- nudge vtx[1] toward vtx[3]: new = (3*vtx[1] + vtx[3]) / 4 --
    mov.l @r14, r3                      ! r3 = vtx[1].x
    mov.l @r12, r1                      ! r1 = vtx[3].x (anchor)
    mov r3, r2                          ! r2 = vtx[1].x (backup)
    shll r3                             ! r3 = vtx[1].x * 2
    add r2, r3                          ! r3 = vtx[1].x * 3
    add r1, r3                          ! r3 = vtx[1].x * 3 + vtx[3].x
    mov.l r3, @r15                      ! sp[0] = intermediate X
    mov.l @r9, r2                       ! r2 = vtx[1].y
    mov.l @r13, r0                      ! r0 = vtx[3].y (anchor)
    mov r2, r1                          ! r1 = vtx[1].y (backup)
    shll r2                             ! r2 = vtx[1].y * 2
    add r1, r2                          ! r2 = vtx[1].y * 3
    add r0, r2                          ! r2 = vtx[1].y * 3 + vtx[3].y
    mov.l r2, @(4, r15)                ! sp[4] = intermediate Y
    mov.l @r15, r1                      ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x1 + x3) / 4
    mov.l r1, @r14                      ! vtx[1].x = nudged X
    mov.l @(4, r15), r3                 ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y1 + y3) / 4
    mov.l r3, @r9                       ! vtx[1].y = nudged Y
    ! -- bounds check nudged vtx[1] --
    mov.l @r14, r3                      ! r3 = nudged vtx[1].x
    mov.l r3, @r15                      ! sp[0] = vtx[1].x
    cmp/ge r6, r3                       ! test vtx[1].x >= -405
    bf      .L_pathD_edge31_done        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[1].x
    mov.w   _wpool_x_upper_G, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[1].x > +405
    bt      .L_pathD_edge31_done        ! fail upper X bound => skip
    mov.l @r9, r2                       ! r2 = nudged vtx[1].y
    mov r2, r3                          ! r3 = vtx[1].y
    cmp/ge r6, r3                       ! test vtx[1].y >= -405
    bf/s    .L_pathD_edge31_done        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[1].y
    mov.l @r15, r2                      ! r2 = vtx[1].y
    mov.w   _wpool_y_upper_G, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[1].y > +305
    bt      .L_pathD_edge31_done        ! fail upper Y bound => skip
    ! -- vtx[1] now in bounds: clear vis[1] --
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[1] = 0 (mark visible)
.L_pathD_edge31_done:
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    mov.w @r2, r0                       ! r0 = vis[2]
    tst r0, r0                          ! test if vis[2] == 0
    bra     .L_pathD_test_vis2          ! (delayed branch past word pool)
    nop                                 ! (delay slot)
_wpool_x_upper_G:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_G:
    .2byte  0x0131                      ! +305: screen Y upper bound
.L_pathD_test_vis2:
    bt      .L_check_convergence        ! skip if vtx[2] already visible
    ! -- nudge vtx[2] toward vtx[3]: new = (3*vtx[2] + vtx[3]) / 4 --
    mov.l @r8, r3                       ! r3 = vtx[2].x
    mov.l @r12, r1                      ! r1 = vtx[3].x (anchor)
    mov r3, r2                          ! r2 = vtx[2].x (backup)
    shll r3                             ! r3 = vtx[2].x * 2
    add r2, r3                          ! r3 = vtx[2].x * 3
    add r1, r3                          ! r3 = vtx[2].x * 3 + vtx[3].x
    mov.l r3, @(4, r15)                ! sp[4] = intermediate X
    mov.l @r10, r2                      ! r2 = vtx[2].y
    mov.l @r13, r0                      ! r0 = vtx[3].y (anchor)
    mov r2, r1                          ! r1 = vtx[2].y (backup)
    shll r2                             ! r2 = vtx[2].y * 2
    add r1, r2                          ! r2 = vtx[2].y * 3
    add r0, r2                          ! r2 = vtx[2].y * 3 + vtx[3].y
    mov.l r2, @r15                      ! sp[0] = intermediate Y
    mov.l @(4, r15), r1                 ! r1 = intermediate X
    shar r1                             ! r1 /= 2
    shar r1                             ! r1 /= 4 => (3*x2 + x3) / 4
    mov.l r1, @r8                       ! vtx[2].x = nudged X
    mov.l @r15, r3                      ! r3 = intermediate Y
    shar r3                             ! r3 /= 2
    shar r3                             ! r3 /= 4 => (3*y2 + y3) / 4
    mov.l r3, @r10                      ! vtx[2].y = nudged Y
    ! -- bounds check nudged vtx[2] --
    mov.l @r8, r3                       ! r3 = nudged vtx[2].x
    mov.l r3, @r15                      ! sp[0] = vtx[2].x
    cmp/ge r6, r3                       ! test vtx[2].x >= -405
    bf      .L_check_convergence        ! fail lower X bound => skip
    mov.l @r15, r2                      ! r2 = vtx[2].x
    mov.w   _wpool_x_upper_H, r3       ! r3 = +405 (X upper bound)
    cmp/gt r3, r2                       ! test vtx[2].x > +405
    bt      .L_check_convergence        ! fail upper X bound => skip
    mov.l @r10, r2                      ! r2 = nudged vtx[2].y
    mov r2, r3                          ! r3 = vtx[2].y
    cmp/ge r6, r3                       ! test vtx[2].y >= -405
    bf/s    .L_check_convergence        ! fail lower Y bound => skip
    mov.l r2, @r15                      ! (delay) sp[0] = vtx[2].y
    mov.l @r15, r2                      ! r2 = vtx[2].y
    mov.w   _wpool_y_upper_H, r3       ! r3 = +305 (Y upper bound)
    cmp/gt r3, r2                       ! test vtx[2].y > +305
    bt      .L_check_convergence        ! fail upper Y bound => skip
    ! -- vtx[2] now in bounds: clear vis[2] --
    mov.l @(8, r15), r2                 ! r2 = &vis[2]
    exts.w r7, r3                       ! r3 = 0 (visible flag)
    mov.w r3, @r2                       ! vis[2] = 0 (mark visible)
! ---- convergence check: are all 4 vis flags zero? ----
.L_check_convergence:
    mov.l @(20, r15), r2                ! r2 = &vis[0]
    mov.l @(8, r15), r1                 ! r1 = &vis[2]
    mov.w @r2, r3                       ! r3 = vis[0]
    mov.l @(12, r15), r2                ! r2 = &vis[1]
    mov.w @r2, r2                       ! r2 = vis[1]
    or r2, r3                           ! r3 |= vis[1]
    mov.w @r1, r2                       ! r2 = vis[2]
    or r2, r3                           ! r3 |= vis[2]
    mov.l @(16, r15), r1                ! r1 = &vis[3]
    mov.w @r1, r2                       ! r2 = vis[3]
    or r2, r3                           ! r3 |= vis[3]
    tst r3, r3                          ! test if all vis flags == 0
    bf      .L_not_converged            ! if any flag still set, loop again
    bra     .L_epilogue                 ! all vertices visible, exit
    nop                                 ! (delay slot)
.L_not_converged:
    bra     .L_clip_loop                ! loop back for another iteration
    nop                                 ! (delay slot)
.L_epilogue:
    add #0x2C, r15                      ! deallocate stack frame
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return to caller
    mov.l @r15+, r14                    ! (delay) restore r14
_wpool_x_upper_H:
    .2byte  0x0195                      ! +405: screen X upper bound
_wpool_y_upper_H:
    .2byte  0x0131                      ! +305: screen Y upper bound
