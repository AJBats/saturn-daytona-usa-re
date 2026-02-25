/* scene_proc_e -- Per-quad vertex transform, screen clip, frustum cull, and Z-sort
 * Translation unit: 0x0602BDD8 - 0x0602C690
 *
 * For each polygon (quad) in the input face list, this function:
 *   1. Transforms all 4 vertex positions from model space to camera space
 *      using 3x3 rotation matrix multiply (MAC.L 32x32->64, 16.16 fixed-point)
 *      plus translation vector addition.
 *   2. Clamps each vertex Z to the far-plane clip threshold.
 *   3. Optionally performs backface culling: transforms the face normal through
 *      the camera matrix and checks the dot product against the view direction.
 *      Faces pointing away from the camera (dot > 0) are skipped.
 *   4. Projects each transformed vertex to screen coordinates via perspective
 *      divide (dmuls.l by reciprocal Z), then bounds-checks the result against
 *      the screen clip rectangle (+/-0x190 X, +/-0x12C Y, with guard band at
 *      0xFE70 = -0x190).
 *   5. Performs 4-plane frustum culling: if all 4 vertices fall outside any
 *      single frustum edge (left/right/top/bottom), the polygon is discarded.
 *   6. For partially-clipped polygons, dispatches to a clip handler function
 *      via the pipeline B function table (sym_0602C460).
 *   7. Writes final screen-space X/Y for all 4 vertices into a sprite data
 *      entry, extracts the face's depth sort mode (3-bit field), and jumps
 *      to one of 5 depth strategies (average, min, max, max+bias, max+far).
 *   8. Converts the chosen depth into a Z-sort key and stores it into the
 *      sprite index table for back-to-front draw ordering.
 *
 * Functions:
 *   scene_proc_e   (0x0602BDD8) -- Quad vertex transform, clip, cull, Z-sort dispatch
 *   sym_0602C494   (0x0602C494) -- 3-pass radix sort (LSB first) with 32 buckets
 *                    per pass (5-bit key). Sorts polygon indices by 15-bit depth key
 *                    extracted from the Z-sort buffer. Used for back-to-front rendering.
 *
 * Z-sort dispatch targets (jumped to via table at sym_0602C470):
 *   loc_0602C380 -- Average of 4 vertex depths (sum >> 2)
 *   loc_0602C38C -- Minimum (nearest) of 4 vertex depths
 *   loc_0602C3A2 -- Maximum (farthest) of 4 vertex depths
 *   loc_0602C3B8 -- Maximum depth + 0x000B8000 bias (11.5 in 16.16 fp)
 *   loc_0602C3D4 -- Maximum depth + 0x00010000 bias (1.0 in 16.16 fp)
 *
 * Data tables:
 *   sym_0602C450 -- Pipeline A fn ptrs: clip dispatch (skip, skip, spring_damper,
 *                    transform_pipeline, mega_render_func)
 *   sym_0602C460 -- Pipeline B fn ptrs: partial clip handlers (skip, skip,
 *                    vblank_frame_handler, render_list_builder, render_obj_processor)
 *   sym_0602C470 -- Z-sort dispatch: 5 depth strategy fn ptrs + sort buffer pointers
 */

    .section .text.FUN_0602BDD8


    .global scene_proc_e
    .type scene_proc_e, @function
scene_proc_e:
    mov.l r14, @-r15                    ! save callee-saved regs
    sts.l pr, @-r15                     ! save return address
    mov r4, r8                          ! r8 = face data array base
    mov.l   .L_clip_threshold_ptr, r10
    mov.l @r10, r10                     ! r10 = far-plane clip threshold
    mov #0x18, r0                       ! 0x18 = sizeof(face_entry)
    mul.l r7, r0                        ! r7 = face count
    mov r5, r3                          ! r3 = vertex table ptr
    mov r6, r13                         ! r13 = polygon group index
    mov r3, r14                         ! r14 = vertex table ptr (preserved)
    sts macl, r0                        ! r0 = face_count * sizeof(face_entry)
    add r0, r8                          ! r8 -> past last face (iterate backwards)
.L_vertex_loop:
    mov.l r7, @-r15                     ! push remaining face count
    add #-0x18, r8                      ! step back to previous face entry
    ! ---- Transform vertex A (face.vtx_idx[0]) ----
    mov.w @(16, r8), r0                 ! face.vtx_idx[0] -- vertex A index
    extu.w r0, r4                       ! zero-extend index
    mov #0x6, r1                        ! 0x6 = sizeof(vertex_xyz) -- 3 int16 coords
    mul.l r1, r4                        ! byte offset = index * 6
    sts macl, r4
    add r14, r4                         ! r4 -> vertex A position in table
    mov.w @r4+, r0                      ! load vtx A X (int16)
    mov.w @r4+, r1                      ! load vtx A Y (int16)
    mov.w @r4+, r2                      ! load vtx A Z (int16)
    mov.l   .L_vertex_output_a, r4      ! r4 -> temp vertex output buffer
    shll8 r0                            ! X << 11 = convert int16 to 16.16 fp
    shll2 r0
    shll r0
    mov.l r0, @r4                       ! store X as 16.16 fp
    shll8 r1                            ! Y << 11
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)                  ! store Y as 16.16 fp
    shll8 r2                            ! Z << 11
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)                  ! store Z as 16.16 fp
    mov.l   .L_vertex_scratch, r5       ! r5 -> scratch for transformed result
    mov.l   .L_render_budget, r0
    mov #0x24, r7                       ! 0x24 = offset to translation vector
    mov.l @r0, r6                       ! r6 -> camera rotation matrix (3x3)
    add r6, r7                          ! r7 -> camera translation vector
    clrmac                              ! --- row 0: dot(vertex, matrix_row0) + translate.x ---
    mac.l @r4+, @r6+                    ! MAC += vtx.X * mat[0][0]
    mac.l @r4+, @r6+                    ! MAC += vtx.Y * mat[0][1]
    mov.l @r7+, r2                      ! r2 = translation.X
    mac.l @r4+, @r6+                    ! MAC += vtx.Z * mat[0][2]
    add #-0xC, r4                       ! rewind vertex ptr for next row
    sts mach, r0                        ! 64-bit result high
    sts macl, r1                        ! 64-bit result low
    clrmac                              ! --- row 1: dot(vertex, matrix_row1) + translate.y ---
    mac.l @r4+, @r6+                    ! MAC += vtx.X * mat[1][0]
    xtrct r0, r1                        ! merge high:low -> 16.16 result
    add r2, r1                          ! add translation.X
    mac.l @r4+, @r6+                    ! MAC += vtx.Y * mat[1][1]
    mov.l r1, @r5                       ! store transformed X
    mac.l @r4+, @r6+                    ! MAC += vtx.Z * mat[1][2]
    mov.l @r7+, r2                      ! r2 = translation.Y
    add #-0xC, r4                       ! rewind vertex ptr for next row
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 2: dot(vertex, matrix_row2) + translate.z ---
    mac.l @r4+, @r6+                    ! MAC += vtx.X * mat[2][0]
    xtrct r0, r1                        ! merge high:low -> 16.16 result
    add r2, r1                          ! add translation.Y
    mac.l @r4+, @r6+                    ! MAC += vtx.Y * mat[2][1]
    mov.l r1, @(4, r5)                  ! store transformed Y
    mac.l @r4+, @r6+                    ! MAC += vtx.Z * mat[2][2]
    mov.l @r7+, r2                      ! r2 = translation.Z
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                        ! merge high:low -> 16.16 result
    add r2, r1                          ! add translation.Z
    mov.l r1, @(8, r5)                  ! store transformed Z
    mov.l @(8, r5), r0                  ! reload transformed Z
    cmp/ge r0, r10                      ! Z >= far clip threshold?
    mov.l   .L_vertex_output_y, r11     ! r11 -> depth clamp output array
    .word 0x0029 /* movt r9 -- store T bit (1 if clipped, 0 if not) */
    mov.w r0, @r11                      ! store vtx A clamped depth
    mov.w @(12, r8), r0                 ! face.flags byte
    tst #0x8, r0                        ! test backface cull enable flag (bit 3)
    bf      .L_vertex_2                 ! if set, skip backface test
    ! ---- Backface cull: transform face normal through camera matrix ----
    mov.l   .L_vertex_accum_a, r5       ! r5 -> normal transform output
    mov r8, r4                          ! r4 -> face normal (stored in face data)
    mov.l   .L_render_budget, r0
    clrmac                              ! --- transform row 0 of normal ---
    mov.l @r0, r2                       ! r2 -> camera rotation matrix
    mac.l @r4+, @r2+                    ! MAC += normal.X * mat[0][0]
    mac.l @r4+, @r2+                    ! MAC += normal.Y * mat[0][1]
    mac.l @r4+, @r2+                    ! MAC += normal.Z * mat[0][2]
    add #-0xC, r4                       ! rewind normal ptr
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- transform row 1 of normal ---
    mac.l @r4+, @r2+                    ! MAC += normal.X * mat[1][0]
    xtrct r0, r1                        ! transformed normal.X
    mov.l r1, @r5                       ! store
    mac.l @r4+, @r2+                    ! MAC += normal.Y * mat[1][1]
    mac.l @r4+, @r2+                    ! MAC += normal.Z * mat[1][2]
    add #-0xC, r4                       ! rewind
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- transform row 2 of normal ---
    mac.l @r4+, @r2+                    ! MAC += normal.X * mat[2][0]
    xtrct r0, r1                        ! transformed normal.Y
    mov.l r1, @(4, r5)                  ! store
    mac.l @r4+, @r2+                    ! MAC += normal.Y * mat[2][1]
    mac.l @r4+, @r2+                    ! MAC += normal.Z * mat[2][2]
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                        ! transformed normal.Z
    mov.l r1, @(8, r5)                  ! store
    mov.l   .L_vertex_scratch, r4       ! r4 -> transformed vertex A position
    clrmac                              ! --- dot(view_dir, normal) for backface test ---
    mac.l @r4+, @r5+                    ! MAC += pos.X * normal.X
    mac.l @r4+, @r5+                    ! MAC += pos.Y * normal.Y
    mac.l @r4+, @r5+                    ! MAC += pos.Z * normal.Z
    sts mach, r1
    sts macl, r0
    xtrct r1, r0                        ! dot product result (16.16 fp)
    cmp/pl r0                           ! facing camera? (dot > 0 = back-facing)
    bt      .L_vertex_2                 ! if NOT back-facing, continue to vtx B
    bra     .L_next_poly                ! back-facing: skip this polygon
    nop
    .2byte  0x0000                      ! alignment padding
.L_clip_threshold_ptr:
    .4byte  sym_06063F08                ! -> far-plane clip distance
.L_vertex_output_a:
    .4byte  sym_06094F74                ! -> temp vertex position buffer (12 bytes)
.L_vertex_scratch:
    .4byte  sym_06094EF4                ! -> transformed vertex scratch (4 * 12 bytes)
.L_render_budget:
    .4byte  sym_0608A52C                ! -> ptr to camera 3x3 rotation matrix
.L_vertex_output_y:
    .4byte  sym_06094EEC                ! -> depth clamp output (4 * int16)
.L_vertex_accum_a:
    .4byte  sym_06094F24                ! -> normal transform scratch (12 bytes)
.L_vertex_2:
    ! ---- Transform vertex B (face.vtx_idx[1]) ----
    mov.w @(18, r8), r0                 ! face.vtx_idx[1] -- vertex B index
    mov #0x6, r1                        ! sizeof(vertex_xyz)
    extu.w r0, r4                       ! zero-extend index
    mul.l r1, r4                        ! byte offset
    sts macl, r4
    add r14, r4                         ! r4 -> vertex B position
    mov.w @r4+, r0                      ! load vtx B X
    mov.w @r4+, r1                      ! load vtx B Y
    mov.w @r4+, r2                      ! load vtx B Z
    mov.l   .L_vertex_output_a2, r4     ! r4 -> temp vertex output
    shll8 r0                            ! X << 11 = int16 -> 16.16 fp
    shll2 r0
    shll r0
    mov.l r0, @r4                       ! store X fp
    shll8 r1                            ! Y << 11
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)                  ! store Y fp
    shll8 r2                            ! Z << 11
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)                  ! store Z fp
    mov.l   .L_vertex_scratch2, r5      ! r5 -> scratch slot 1
    add #0xC, r5                        ! offset to vertex B slot (12 bytes in)
    mov.l   .L_render_budget2, r0
    mov #0x24, r7                       ! offset to translation vector
    mov.l @r0, r6                       ! r6 -> camera matrix
    add r6, r7                          ! r7 -> translation vector
    clrmac                              ! --- row 0: dot(vtxB, mat_row0) + trans.X ---
    mac.l @r4+, @r6+                    ! MAC += vtx.X * mat[0][0]
    mac.l @r4+, @r6+                    ! MAC += vtx.Y * mat[0][1]
    mov.l @r7+, r2                      ! r2 = translation.X
    mac.l @r4+, @r6+                    ! MAC += vtx.Z * mat[0][2]
    add #-0xC, r4                       ! rewind
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 1 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed X
    add r2, r1                          ! + translation.X
    mac.l @r4+, @r6+
    mov.l r1, @r5                       ! store vtx B transformed X
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! r2 = translation.Y
    add #-0xC, r4                       ! rewind
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 2 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed Y
    add r2, r1                          ! + translation.Y
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)                  ! store vtx B transformed Y
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! r2 = translation.Z
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                        ! transformed Z
    add r2, r1                          ! + translation.Z
    mov.l r1, @(8, r5)                  ! store vtx B transformed Z
    mov.l @(8, r5), r0                  ! reload vtx B depth
    cmp/ge r0, r10                      ! Z >= far clip?
    .word 0x0029 /* movt r9 -- store clip flag */
    mov.w r0, @(2, r11)                 ! store vtx B clamped depth
    ! ---- Transform vertex C (face.vtx_idx[2]) ----
    mov.w @(20, r8), r0                 ! face.vtx_idx[2] -- vertex C index
    mov #0x6, r1                        ! sizeof(vertex_xyz)
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4                         ! r4 -> vertex C position
    mov.w @r4+, r0                      ! load vtx C X
    mov.w @r4+, r1                      ! load vtx C Y
    mov.w @r4+, r2                      ! load vtx C Z
    mov.l   .L_vertex_output_a2, r4
    shll8 r0                            ! X << 11
    shll2 r0
    shll r0
    mov.l r0, @r4                       ! store X fp
    shll8 r1                            ! Y << 11
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)                  ! store Y fp
    mov.l   .L_vertex_y_scratch, r5     ! save vtx C Y (used later in depth bias)
    mov.l r1, @r5                       ! store vtx C Y fp for later use
    shll8 r2                            ! Z << 11
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)                  ! store Z fp
    mov.l   .L_vertex_scratch2, r5      ! r5 -> scratch slot 2
    add #0x18, r5                       ! offset to vertex C slot (24 bytes in)
    mov.l   .L_render_budget2, r0
    mov #0x24, r7                       ! offset to translation vector
    mov.l @r0, r6                       ! r6 -> camera matrix
    add r6, r7                          ! r7 -> translation vector
    clrmac                              ! --- row 0 ---
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.X
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 1 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed X
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5                       ! store vtx C transformed X
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.Y
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 2 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed Y
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)                  ! store vtx C transformed Y
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.Z
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                        ! transformed Z
    add r2, r1
    mov.l r1, @(8, r5)                  ! store vtx C transformed Z
    mov.l @(8, r5), r0                  ! reload vtx C depth
    cmp/ge r0, r10                      ! Z >= far clip?
    .word 0x0029 /* movt r9 -- store clip flag */
    mov.w r0, @(4, r11)                 ! store vtx C clamped depth
    ! ---- Transform vertex D (face.vtx_idx[3]) ----
    mov.w @(22, r8), r0                 ! face.vtx_idx[3] -- vertex D index
    mov #0x6, r1                        ! sizeof(vertex_xyz)
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4                         ! r4 -> vertex D position
    mov.w @r4+, r0                      ! load vtx D X
    mov.w @r4+, r1                      ! load vtx D Y
    mov.w @r4+, r2                      ! load vtx D Z
    mov.l   .L_vertex_output_a2, r4
    shll8 r0                            ! X << 11
    shll2 r0
    shll r0
    mov.l r0, @r4                       ! store X fp
    shll8 r1                            ! Y << 11
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)                  ! store Y fp
    shll8 r2                            ! Z << 11
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)                  ! store Z fp
    mov.l   .L_vertex_scratch2, r5      ! r5 -> scratch slot 3
    add #0x24, r5                       ! offset to vertex D slot (36 bytes in)
    mov.l   .L_render_budget2, r0
    mov #0x24, r7                       ! offset to translation vector
    mov.l @r0, r6                       ! r6 -> camera matrix
    add r6, r7                          ! r7 -> translation vector
    clrmac                              ! --- row 0 ---
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.X
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 1 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed X
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5                       ! store vtx D transformed X
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.Y
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac                              ! --- row 2 ---
    mac.l @r4+, @r6+
    xtrct r0, r1                        ! transformed Y
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)                  ! store vtx D transformed Y
    mac.l @r4+, @r6+
    mov.l @r7+, r2                      ! translation.Z
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                        ! transformed Z
    add r2, r1
    mov.l r1, @(8, r5)                  ! store vtx D transformed Z
    mov.l @(8, r5), r0                  ! reload vtx D depth
    cmp/ge r0, r10                      ! Z >= far clip?
    .word 0x0029 /* movt r9 -- store clip flag */
    mov.w r0, @(6, r11)                 ! store vtx D clamped depth
    ! ---- Sum clip flags for all 4 vertices ----
    mov.w @r11+, r2                     ! vtx A clip flag
    mov.w @r11+, r3                     ! vtx B clip flag
    mov.w @r11+, r1                     ! vtx C clip flag
    add r2, r3                          ! A + B
    add r1, r0                          ! C + D (r0 still has vtx D flag)
    add r3, r0                          ! total = A + B + C + D
    cmp/eq #0x0, r0                     ! all inside? (no vertices clipped)
    bt      .L_post_clip_setup          ! yes: proceed to screen projection
    cmp/eq #0x4, r0                     ! all outside? (all 4 clipped)
    bf      .L_clip_dispatch            ! no: partial clip, dispatch handler
    bra     .L_next_poly                ! all clipped: skip polygon entirely
    nop
.L_vertex_output_a2:
    .4byte  sym_06094F74                ! -> temp vertex position buffer
.L_vertex_scratch2:
    .4byte  sym_06094EF4                ! -> transformed vertex scratch array
.L_render_budget2:
    .4byte  sym_0608A52C                ! -> ptr to camera matrix
.L_vertex_y_scratch:
    .4byte  sym_06094FA4                ! -> saved vtx C Y for depth bias
.L_clip_dispatch:
    ! ---- Dispatch to clip function based on clip count ----
    mov.l   .L_pipeline_a_table, r1     ! r1 -> pipeline A fn ptr table
    shll2 r0                            ! clip_count * 4 = table offset
    add r1, r0                          ! r0 -> fn ptr entry
    mov.l @r0, r0                       ! r0 = clip handler function
    mov.l   .L_vertex_scratch3, r4      ! r4 = transformed vertices
    mov.l   .L_vertex_output_y2, r5     ! r5 = depth clamp array
    jsr @r0                             ! call clip handler
    nop
.L_post_clip_setup:
    ! ---- Set up sprite data entry for this polygon ----
    mov.l   .L_frame_counter, r0
    mov #0x18, r1                       ! 0x18 = sizeof(sprite_entry)
    mov.l @r0, r0                       ! r0 = current sprite count
    mul.l r0, r1                        ! byte offset into sprite data table
    mov.l   .L_sprite_data_table, r2    ! r2 -> sprite data base
    mov.l   .L_vertex_accum_b, r11      ! r11 -> screen-space vertex output
    sts macl, r9                        ! r9 = sprite_count * sizeof(sprite_entry)
    add r2, r9                          ! r9 -> this polygon's sprite entry
    mov.l   .L_vertex_scratch3, r4      ! r4 -> transformed vertex A
    mov r11, r5                         ! r5 -> screen-space output
    ! ---- Perspective project vertex A ----
    mov.w   DAT_0602c0f0, r1            ! r1 = 0xFF00 (perspective divide params offset)
    mov.w   DAT_0602c0f2, r0            ! r0 = 0x00A0 (screen center X offset = 160)
    mov.l @(8, r4), r2                  ! r2 = vtx A transformed Z
    mov.l r0, @(16, r1)                 ! store screen center offset
    mov.l r2, @(0, r1)                  ! store Z for reciprocal lookup
    mov #0x0, r0
    mov.l r0, @(20, r1)                 ! clear extra field
    mov.l @(4, r4), r3                  ! r3 = vtx A transformed Y
    mov.l @r4, r2                       ! r2 = vtx A transformed X
    mov.l @(28, r1), r0                 ! r0 = 1/Z reciprocal (pre-computed)
    dmuls.l r2, r0                      ! screen_X = vtx_X * (1/Z) [64-bit]
    neg r3, r3                          ! negate Y (screen Y is inverted)
    sts mach, r1                        ! screen_X high word
    dmuls.l r3, r0                      ! screen_Y = -vtx_Y * (1/Z)
    mov.l r1, @r5                       ! store vtx A screen X
    sts mach, r2                        ! screen_Y high word
    mov.l r2, @(4, r5)                  ! store vtx A screen Y
    mov.l @r5, r1                       ! reload screen X
    mov.l @(4, r5), r2                  ! reload screen Y
    mov.l   .L_vertex_output_x, r12     ! r12 -> edge clip flags array
    mov #0x0, r0                        ! clear clip flag
    mov.w r0, @r12                      ! vtx A clip flag = 0 (inside)
    ! ---- Bounds check vtx A screen coords ----
    mov.w   .L_clip_bound_pos, r3       ! r3 = 0x0190 = +400 (right edge)
    cmp/gt r3, r1                       ! screen_X > +400?
    bf      .L_clip_check_neg_x         ! no: check left edge
    mov #0x1, r0                        ! yes: mark as clipped
    bra     .L_edge_test_1_done
    mov.w r0, @r12                      ! store clip flag (delay slot)

    .global DAT_0602c0f0
DAT_0602c0f0:
    .2byte  0xFF00                      ! perspective divide hardware offset

    .global DAT_0602c0f2
DAT_0602c0f2:
    .2byte  0x00A0                      ! screen center X offset (160)
.L_clip_bound_pos:
    .2byte  0x0190                      ! +400: right/top screen boundary
    .2byte  0x0000                      ! alignment padding
.L_pipeline_a_table:
    .4byte  sym_0602C450                ! -> pipeline A clip fn ptr table
.L_vertex_scratch3:
    .4byte  sym_06094EF4                ! -> transformed vertex scratch
.L_vertex_output_y2:
    .4byte  sym_06094EEC                ! -> depth clamp output array
.L_frame_counter:
    .4byte  sym_060620D4                ! -> current sprite/polygon count
.L_sprite_data_table:
    .4byte  sym_0608AC20                ! -> sprite data table base
.L_vertex_accum_b:
    .4byte  sym_06094F54                ! -> screen-space vertex accumulator
.L_vertex_output_x:
    .4byte  sym_06094EE4                ! -> per-vertex edge clip flags
.L_clip_check_neg_x:
    mov.w   DAT_0602c120, r3            ! r3 = 0xFE70 = -400 (left edge)
    cmp/gt r1, r3                       ! -400 > screen_X? (X < -400)
    bf      .L_clip_check_pos_y         ! no: check top edge
    mov #0x1, r0                        ! yes: mark as clipped
    bra     .L_edge_test_1_done
    mov.w r0, @r12                      ! store clip flag (delay slot)

    .global DAT_0602c120
DAT_0602c120:
    .2byte  0xFE70                      ! -400: left screen boundary
.L_clip_check_pos_y:
    mov.w   DAT_0602c12e, r3            ! r3 = 0x012C = +300 (bottom edge)
    cmp/gt r3, r2                       ! screen_Y > +300?
    bf      .L_clip_check_neg_y         ! no: check top edge
    mov #0x1, r0                        ! yes: mark as clipped
    bra     .L_edge_test_1_done
    mov.w r0, @r12                      ! store clip flag (delay slot)

    .global DAT_0602c12e
DAT_0602c12e:
    .2byte  0x012C                      ! +300: bottom screen boundary
.L_clip_check_neg_y:
    mov.w   DAT_0602c176, r3            ! r3 = 0xFE70 = -400 (top edge)
    cmp/gt r2, r3                       ! -400 > screen_Y? (Y < -400)
    bf      .L_edge_test_1_done         ! no: vertex A is fully inside
    mov #0x1, r0                        ! yes: mark as clipped
    mov.w r0, @r12                      ! store clip flag
.L_edge_test_1_done:
    ! ---- Perspective project & bounds check vertex B ----
    mov r11, r5                         ! r5 -> screen-space output
    add #0xC, r4                        ! advance to vtx B transformed coords
    add #0x8, r5                        ! advance to vtx B screen output slot
    mov.w   DAT_0602c178, r1            ! perspective divide params offset
    mov.w   DAT_0602c17a, r0            ! screen center offset
    mov.l @(8, r4), r2                  ! vtx B transformed Z
    mov.l r0, @(16, r1)                 ! set screen center
    mov.l r2, @(0, r1)                  ! set Z for reciprocal
    mov #0x0, r0
    mov.l r0, @(20, r1)                 ! clear extra
    mov.l @(4, r4), r3                  ! vtx B transformed Y
    mov.l @r4, r2                       ! vtx B transformed X
    mov.l @(28, r1), r0                 ! 1/Z reciprocal
    dmuls.l r2, r0                      ! screen_X = X * (1/Z)
    neg r3, r3                          ! negate Y
    sts mach, r1                        ! screen_X result
    dmuls.l r3, r0                      ! screen_Y = -Y * (1/Z)
    mov.l r1, @r5                       ! store vtx B screen X
    sts mach, r2                        ! screen_Y result
    mov.l r2, @(4, r5)                  ! store vtx B screen Y
    mov.l @r5, r1                       ! reload screen X
    mov.l @(4, r5), r2                  ! reload screen Y
    mov #0x0, r0                        ! clear clip flag
    mov.w r0, @(2, r12)                 ! vtx B clip flag = 0
    mov.w   DAT_0602c17c, r3            ! r3 = +400 (right edge)
    cmp/gt r3, r1                       ! screen_X > +400?
    bf      .L_v2_check_neg_x           ! no: check left
    mov #0x1, r0                        ! clipped right
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c176
DAT_0602c176:
    .2byte  0xFE70                      ! -400: screen boundary

    .global DAT_0602c178
DAT_0602c178:
    .2byte  0xFF00                      ! perspective divide hardware offset

    .global DAT_0602c17a
DAT_0602c17a:
    .2byte  0x00A0                      ! screen center X (160)

    .global DAT_0602c17c
DAT_0602c17c:
    .2byte  0x0190                      ! +400: right boundary
.L_v2_check_neg_x:
    mov.w   DAT_0602c18a, r3            ! r3 = -400 (left edge)
    cmp/gt r1, r3                       ! -400 > screen_X?
    bf      .L_v2_check_pos_y           ! no: check bottom
    mov #0x1, r0                        ! clipped left
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c18a
DAT_0602c18a:
    .2byte  0xFE70                      ! -400: left boundary
.L_v2_check_pos_y:
    mov.w   DAT_0602c198, r3            ! r3 = +300 (bottom edge)
    cmp/gt r3, r2                       ! screen_Y > +300?
    bf      .L_v2_check_neg_y           ! no: check top
    mov #0x1, r0                        ! clipped bottom
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c198
DAT_0602c198:
    .2byte  0x012C                      ! +300: bottom boundary
.L_v2_check_neg_y:
    mov.w   DAT_0602c1e0, r3            ! r3 = -400 (top edge)
    cmp/gt r2, r3                       ! -400 > screen_Y?
    bf      .L_edge_test_2_done         ! no: vtx B fully inside
    mov #0x1, r0                        ! clipped top
    mov.w r0, @(2, r12)                 ! store clip flag
.L_edge_test_2_done:
    ! ---- Perspective project & bounds check vertex C ----
    mov r11, r5                         ! r5 -> screen-space output
    add #0xC, r4                        ! advance to vtx C transformed coords
    add #0x10, r5                       ! advance to vtx C screen output slot
    mov.w   DAT_0602c1e2, r1            ! perspective divide params offset
    mov.w   DAT_0602c1e4, r0            ! screen center offset
    mov.l @(8, r4), r2                  ! vtx C transformed Z
    mov.l r0, @(16, r1)                 ! set screen center
    mov.l r2, @(0, r1)                  ! set Z for reciprocal
    mov #0x0, r0
    mov.l r0, @(20, r1)                 ! clear extra
    mov.l @(4, r4), r3                  ! vtx C transformed Y
    mov.l @r4, r2                       ! vtx C transformed X
    mov.l @(28, r1), r0                 ! 1/Z reciprocal
    dmuls.l r2, r0                      ! screen_X = X * (1/Z)
    neg r3, r3                          ! negate Y
    sts mach, r1                        ! screen_X result
    dmuls.l r3, r0                      ! screen_Y = -Y * (1/Z)
    mov.l r1, @r5                       ! store vtx C screen X
    sts mach, r2                        ! screen_Y result
    mov.l r2, @(4, r5)                  ! store vtx C screen Y
    mov.l @r5, r1                       ! reload screen X
    mov.l @(4, r5), r2                  ! reload screen Y
    mov #0x0, r0                        ! clear clip flag
    mov.w r0, @(4, r12)                 ! vtx C clip flag = 0
    mov.w   DAT_0602c1e6, r3            ! r3 = +400 (right edge)
    cmp/gt r3, r1                       ! screen_X > +400?
    bf      .L_v3_check_neg_x           ! no: check left
    mov #0x1, r0                        ! clipped right
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c1e0
DAT_0602c1e0:
    .2byte  0xFE70                      ! -400: screen boundary

    .global DAT_0602c1e2
DAT_0602c1e2:
    .2byte  0xFF00                      ! perspective divide hardware offset

    .global DAT_0602c1e4
DAT_0602c1e4:
    .2byte  0x00A0                      ! screen center X (160)

    .global DAT_0602c1e6
DAT_0602c1e6:
    .2byte  0x0190                      ! +400: right boundary
.L_v3_check_neg_x:
    mov.w   DAT_0602c1f4, r3            ! r3 = -400 (left edge)
    cmp/gt r1, r3                       ! -400 > screen_X?
    bf      .L_v3_check_pos_y           ! no: check bottom
    mov #0x1, r0                        ! clipped left
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c1f4
DAT_0602c1f4:
    .2byte  0xFE70                      ! -400: left boundary
.L_v3_check_pos_y:
    mov.w   DAT_0602c202, r3            ! r3 = +300 (bottom edge)
    cmp/gt r3, r2                       ! screen_Y > +300?
    bf      .L_v3_check_neg_y           ! no: check top
    mov #0x1, r0                        ! clipped bottom
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c202
DAT_0602c202:
    .2byte  0x012C                      ! +300: bottom boundary
.L_v3_check_neg_y:
    mov.w   DAT_0602c24a, r3            ! r3 = -400 (top edge)
    cmp/gt r2, r3                       ! -400 > screen_Y?
    bf      .L_edge_test_3_done         ! no: vtx C fully inside
    mov #0x1, r0                        ! clipped top
    mov.w r0, @(4, r12)                 ! store clip flag
.L_edge_test_3_done:
    ! ---- Perspective project & bounds check vertex D ----
    mov r11, r5                         ! r5 -> screen-space output
    add #0xC, r4                        ! advance to vtx D transformed coords
    add #0x18, r5                       ! advance to vtx D screen output slot
    mov.w   DAT_0602c24c, r1            ! perspective divide params offset
    mov.w   DAT_0602c24e, r0            ! screen center offset
    mov.l @(8, r4), r2                  ! vtx D transformed Z
    mov.l r0, @(16, r1)                 ! set screen center
    mov.l r2, @(0, r1)                  ! set Z for reciprocal
    mov #0x0, r0
    mov.l r0, @(20, r1)                 ! clear extra
    mov.l @(4, r4), r3                  ! vtx D transformed Y
    mov.l @r4, r2                       ! vtx D transformed X
    mov.l @(28, r1), r0                 ! 1/Z reciprocal
    dmuls.l r2, r0                      ! screen_X = X * (1/Z)
    neg r3, r3                          ! negate Y
    sts mach, r1                        ! screen_X result
    dmuls.l r3, r0                      ! screen_Y = -Y * (1/Z)
    mov.l r1, @r5                       ! store vtx D screen X
    sts mach, r2                        ! screen_Y result
    mov.l r2, @(4, r5)                  ! store vtx D screen Y
    mov.l @r5, r1                       ! reload screen X
    mov.l @(4, r5), r2                  ! reload screen Y
    mov #0x0, r0                        ! clear clip flag
    mov.w r0, @(6, r12)                 ! vtx D clip flag = 0
    mov.w   DAT_0602c250, r3            ! r3 = +400 (right edge)
    cmp/gt r3, r1                       ! screen_X > +400?
    bf      .L_v4_check_neg_x           ! no: check left
    mov #0x1, r0                        ! clipped right
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c24a
DAT_0602c24a:
    .2byte  0xFE70                      ! -400: screen boundary

    .global DAT_0602c24c
DAT_0602c24c:
    .2byte  0xFF00                      ! perspective divide hardware offset

    .global DAT_0602c24e
DAT_0602c24e:
    .2byte  0x00A0                      ! screen center X (160)

    .global DAT_0602c250
DAT_0602c250:
    .2byte  0x0190                      ! +400: right boundary
.L_v4_check_neg_x:
    mov.w   DAT_0602c25e, r3            ! r3 = -400 (left edge)
    cmp/gt r1, r3                       ! -400 > screen_X?
    bf      .L_v4_check_pos_y           ! no: check bottom
    mov #0x1, r0                        ! clipped left
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c25e
DAT_0602c25e:
    .2byte  0xFE70                      ! -400: left boundary
.L_v4_check_pos_y:
    mov.w   DAT_0602c26c, r3            ! r3 = +300 (bottom edge)
    cmp/gt r3, r2                       ! screen_Y > +300?
    bf      .L_v4_check_neg_y           ! no: check top
    mov #0x1, r0                        ! clipped bottom
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)                 ! store clip flag (delay slot)

    .global DAT_0602c26c
DAT_0602c26c:
    .2byte  0x012C                      ! +300: bottom boundary
.L_v4_check_neg_y:
    mov.w   DAT_0602c29c, r3            ! r3 = -400 (top edge)
    cmp/gt r2, r3                       ! -400 > screen_Y?
    bf      .L_edge_test_4_done         ! no: vtx D fully inside
    mov #0x1, r0                        ! clipped top
    mov.w r0, @(6, r12)                 ! store clip flag
.L_edge_test_4_done:
    ! ---- 4-plane frustum cull: reject if ALL verts outside same edge ----
    mov.l   .L_frustum_left, r4         ! r4 = 0xFFFFFF50 = left frustum bound
    mov.l   .L_frustum_right, r5        ! r5 = 0xB0 = right frustum bound
    mov.l   .L_frustum_top, r6          ! r6 = 0xFFFFFF81 = top frustum bound
    mov.l   .L_frustum_bottom, r7       ! r7 = 0x51 = bottom frustum bound
    ! -- Check left edge: if all 4 X < left, cull --
    mov.l @r11, r0                      ! vtx A screen X
    cmp/gt r0, r4                       ! left > X? (vertex left of frustum)
    bf      .L_frustum_check_right      ! at least one inside: skip
    mov.l @(8, r11), r0                 ! vtx B screen X
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    mov.l @(16, r11), r0                ! vtx C screen X
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    mov.l @(24, r11), r0                ! vtx D screen X
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    bra     .L_next_poly                ! all 4 outside left: cull
    nop

    .global DAT_0602c29c
DAT_0602c29c:
    .2byte  0xFE70                      ! -400: screen boundary
    .2byte  0x0000                      ! alignment padding
.L_frustum_left:
    .4byte  0xFFFFFF50                  ! left frustum bound (signed -0xB0)
.L_frustum_right:
    .4byte  0x000000B0                  ! right frustum bound (+0xB0)
.L_frustum_top:
    .4byte  0xFFFFFF81                  ! top frustum bound (signed -0x7F)
.L_frustum_bottom:
    .4byte  0x00000051                  ! bottom frustum bound (+0x51)
.L_frustum_check_right:
    ! -- Check right edge: if all 4 X > right, cull --
    mov.l @r11, r0                      ! vtx A screen X
    cmp/gt r0, r5                       ! right > X? (at least one inside)
    bt      .L_frustum_check_top        ! yes: at least one inside
    mov.l @(8, r11), r0                 ! vtx B screen X
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    mov.l @(16, r11), r0                ! vtx C screen X
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    mov.l @(24, r11), r0                ! vtx D screen X
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    bra     .L_next_poly                ! all 4 outside right: cull
    nop
.L_frustum_check_top:
    ! -- Check top edge: if all 4 Y < top, cull --
    mov.l @(4, r11), r0                 ! vtx A screen Y
    cmp/gt r0, r6                       ! top > Y? (vertex above frustum)
    bf      .L_frustum_check_bottom     ! at least one inside: skip
    mov.l @(12, r11), r0                ! vtx B screen Y
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    mov.l @(20, r11), r0                ! vtx C screen Y
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    mov.l @(28, r11), r0                ! vtx D screen Y
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    bra     .L_next_poly                ! all 4 outside top: cull
    nop
.L_frustum_check_bottom:
    ! -- Check bottom edge: if all 4 Y > bottom, cull --
    mov.l @(4, r11), r0                 ! vtx A screen Y
    cmp/gt r0, r7                       ! bottom > Y? (at least one inside)
    bt      .L_all_clipped_check        ! yes: at least one inside
    mov.l @(12, r11), r0                ! vtx B screen Y
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    mov.l @(20, r11), r0                ! vtx C screen Y
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    mov.l @(28, r11), r0                ! vtx D screen Y
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    bra     .L_next_poly                ! all 4 outside bottom: cull
    nop
.L_all_clipped_check:
    ! ---- Sum per-vertex edge clip flags ----
    mov.w @r12, r1                      ! vtx A edge clip flag
    mov.w @(2, r12), r0                 ! vtx B edge clip flag
    add r0, r1                          ! A + B
    mov.w @(4, r12), r0                 ! vtx C edge clip flag
    add r0, r1                          ! A + B + C
    mov.w @(6, r12), r0                 ! vtx D edge clip flag
    add r1, r0                          ! total = A + B + C + D
    cmp/eq #0x4, r0                     ! all 4 vertices clipped?
    bf      .L_partial_clip             ! no: handle partial clip
    bra     .L_next_poly                ! all clipped: skip polygon
    nop
.L_partial_clip:
    cmp/eq #0x0, r0                     ! no vertices clipped?
    bt      .L_store_vertices           ! yes: store directly, no clipping needed
    mov r11, r4                         ! r4 = screen-space vertices
    shll2 r0                            ! clip_count * 4 = table offset
    mov.l   .L_pipeline_b_table, r1     ! r1 -> pipeline B fn ptr table
    add r1, r0                          ! r0 -> fn ptr entry
    mov.l @r0, r0                       ! r0 = partial clip handler
    jsr @r0                             ! call clip handler
    mov r12, r5                         ! r5 = edge clip flags (delay slot)
.L_store_vertices:
    ! ---- Write final screen coords into sprite data entry ----
    mov.l @r11, r0                      ! vtx A screen X
    mov.w r0, @(8, r9)                  ! sprite.vtxA_x
    mov.l @(4, r11), r0                 ! vtx A screen Y
    mov.w r0, @(10, r9)                 ! sprite.vtxA_y
    mov.l @(8, r11), r0                 ! vtx B screen X
    mov.w r0, @(12, r9)                 ! sprite.vtxB_x
    mov.l @(12, r11), r0                ! vtx B screen Y
    mov.w r0, @(14, r9)                 ! sprite.vtxB_y
    mov.l @(16, r11), r0                ! vtx C screen X
    mov.w r0, @(16, r9)                 ! sprite.vtxC_x
    mov.l @(20, r11), r0                ! vtx C screen Y
    mov.w r0, @(18, r9)                 ! sprite.vtxC_y
    mov.l @(24, r11), r0                ! vtx D screen X
    mov.w r0, @(20, r9)                 ! sprite.vtxD_x
    mov.l @(28, r11), r0                ! vtx D screen Y
    mov.w r0, @(22, r9)                 ! sprite.vtxD_y
    mov.w @(14, r8), r0                 ! face.texture_id
    mov.w r0, @(6, r9)                  ! sprite.texture_id
    mov.w @(12, r8), r0                 ! face.flags
    shlr2 r0                            ! >> 4 to extract render mode nibble
    shlr2 r0
    and #0xF, r0                        ! isolate 4-bit render mode field
    mov.b r0, @(4, r9)                  ! sprite.render_mode
    mov r13, r0                         ! r13 = polygon group index
    mov.b r0, @(5, r9)                  ! sprite.group_index
    ! ---- Dispatch to Z-sort depth strategy ----
    mov.w @(12, r8), r0                 ! face.flags
    mov.l   .L_zsort_dispatch, r1       ! r1 -> Z-sort dispatch table
    and #0x7, r0                        ! isolate 3-bit depth strategy field
    shll2 r0                            ! strategy * 4 = table offset
    mov.l @(r0, r1), r0                 ! r0 = depth strategy handler address
    mov.l   .L_vertex_scratch4, r1      ! r1 -> transformed vertex scratch
    mov.l @(8, r1), r3                  ! r3 = vtx A depth (Z at offset 8)
    mov.l @(20, r1), r4                 ! r4 = vtx B depth (Z at offset 20)
    mov.l @(32, r1), r5                 ! r5 = vtx C depth (Z at offset 32)
    jmp @r0                             ! jump to depth strategy handler
    mov.l @(44, r1), r6                 ! r6 = vtx D depth (Z at offset 44, delay slot)
.L_pipeline_b_table:
    .4byte  sym_0602C460                ! -> pipeline B partial clip fn ptr table
.L_zsort_dispatch:
    .4byte  sym_0602C470                ! -> Z-sort dispatch table (5 strategies)
.L_vertex_scratch4:
    .4byte  sym_06094EF4                ! -> transformed vertex scratch array

! ===========================================================================
! Z-sort depth strategy handlers
! Called with: r3=depthA, r4=depthB, r5=depthC, r6=depthD
! Must produce final depth key in r3, then fall through to .L_zsort_finalize
! ===========================================================================

    .global loc_0602C380
loc_0602C380:
    ! ---- Strategy 0: Average depth (sum >> 2) ----
    add r4, r3                          ! r3 = A + B
    add r5, r6                          ! r6 = C + D
    add r6, r3                          ! r3 = A + B + C + D
    shlr2 r3                            ! r3 = sum / 4
    bra     .L_zsort_finalize
    nop

    .global loc_0602C38C
loc_0602C38C:
    ! ---- Strategy 1: Minimum (nearest) depth ----
    cmp/ge r3, r4                       ! B >= A?
    bt      .L_minz_skip_v2             ! yes: keep A as min
    mov r4, r3                          ! no: B is nearer
.L_minz_skip_v2:
    cmp/ge r3, r5                       ! C >= current min?
    bt      .L_minz_skip_v3             ! yes: keep current
    mov r5, r3                          ! no: C is nearer
.L_minz_skip_v3:
    cmp/ge r3, r6                       ! D >= current min?
    bt      .L_minz_skip_v4             ! yes: keep current
    mov r6, r3                          ! no: D is nearer
.L_minz_skip_v4:
    bra     .L_zsort_finalize
    nop

    .global loc_0602C3A2
loc_0602C3A2:
    ! ---- Strategy 2: Maximum (farthest) depth ----
    cmp/gt r3, r4                       ! B > A?
    bf      .L_maxz_skip_v2             ! no: keep A as max
    mov r4, r3                          ! yes: B is farther
.L_maxz_skip_v2:
    cmp/gt r3, r5                       ! C > current max?
    bf      .L_maxz_skip_v3             ! no: keep current
    mov r5, r3                          ! yes: C is farther
.L_maxz_skip_v3:
    cmp/gt r3, r6                       ! D > current max?
    bf      .L_maxz_skip_v4             ! no: keep current
    mov r6, r3                          ! yes: D is farther
.L_maxz_skip_v4:
    bra     .L_zsort_finalize
    nop

    .global loc_0602C3B8
loc_0602C3B8:
    ! ---- Strategy 4: Maximum depth + 0xB8000 bias (11.5 in 16.16 fp) ----
    mov.l   .L_fp_depth_bias_a, r0      ! r0 = 0x000B8000 depth bias
    cmp/gt r3, r4                       ! B > A?
    bf      .L_maxz_bias_skip_v2        ! no: keep A
    mov r4, r3                          ! yes: use B
.L_maxz_bias_skip_v2:
    cmp/gt r3, r5                       ! C > current max?
    bf      .L_maxz_bias_skip_v3        ! no: keep current
    mov r5, r3                          ! yes: use C
.L_maxz_bias_skip_v3:
    cmp/gt r3, r6                       ! D > current max?
    bf      .L_maxz_bias_skip_v4        ! no: keep current
    mov r6, r3                          ! yes: use D
.L_maxz_bias_skip_v4:
    bra     .L_zsort_finalize
    add r0, r3                          ! add depth bias (delay slot)
.L_fp_depth_bias_a:
    .4byte  0x000B8000                  ! 11.5 in 16.16 fixed-point

    .global loc_0602C3D4
loc_0602C3D4:
    ! ---- Strategy 3: Maximum depth + 1.0 bias ----
    mov.l   .L_fp_one, r0              ! r0 = 0x00010000 = 1.0 (16.16 fp)
    cmp/gt r3, r4                       ! B > A?
    bf      .L_maxz_far_skip_v2         ! no: keep A
    mov r4, r3                          ! yes: use B
.L_maxz_far_skip_v2:
    cmp/gt r3, r5                       ! C > current max?
    bf      .L_maxz_far_skip_v3         ! no: keep current
    mov r5, r3                          ! yes: use C
.L_maxz_far_skip_v3:
    cmp/gt r3, r6                       ! D > current max?
    bf      .L_maxz_far_skip_v4         ! no: keep current
    mov r6, r3                          ! yes: use D
.L_maxz_far_skip_v4:
    add r0, r3                          ! add +1.0 depth bias
.L_zsort_finalize:
    ! ---- Apply distance-dependent depth offset and store Z-sort key ----
    mov.l   .L_vertex_y_scratch2, r1
    mov.l @r1, r1                       ! r1 = saved vtx C Y (from earlier)
    mov.l   .L_depth_sort_state, r0
    mov.l @r0, r0                       ! r0 = depth sort threshold
    mov.l   .L_fp_two, r2              ! r2 = 2.0 (16.16 fp)
    add r2, r1                          ! r1 = vtxC_Y + 2.0
    cmp/gt r1, r0                       ! threshold > (vtxC_Y + 2.0)?
    bf      .L_zsort_store              ! no: skip extra bias
    mov.l   .L_fp_depth_bias_b, r2      ! r2 = 0x000A0000 = 10.0 (16.16 fp)
    add r2, r3                          ! add extra depth bias for distant polys
.L_zsort_store:
    mov.l   .L_frame_counter2, r2       ! r2 -> sprite count
    neg r3, r3                          ! negate depth (farther = smaller key for BTF)
    mov.l   .L_sprite_index_table, r1   ! r1 -> Z-sort key table
    shlr8 r3                            ! convert 16.16 fp depth to 15-bit key
    mov.l @r2, r0                       ! r0 = current sprite count
    shlr2 r3                            ! >> 12 total (8+2+2)
    shlr2 r3
    shll r0                             ! sprite_count * 2 = byte offset in table
    mov.w r3, @(r0, r1)                 ! store Z-sort key for this polygon
    shar r0                             ! restore sprite_count
    add #0x1, r0                        ! increment sprite count
    mov.l r0, @r2                       ! write back new count
.L_next_poly:
    ! ---- Loop to next polygon ----
    mov.l @r15+, r7                     ! pop remaining face count
    dt r7                               ! decrement and test
    bt      .L_return                   ! done: return
    bra     .L_vertex_loop              ! process next polygon
    nop
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_vertex_y_scratch2:
    .4byte  sym_06094FA4                ! -> saved vtx C Y value
.L_depth_sort_state:
    .4byte  sym_06063F54                ! -> depth sort threshold state
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fp_depth_bias_b:
    .4byte  0x000A0000                  /* 10.0 (16.16 fixed-point) -- distance bias */
.L_frame_counter2:
    .4byte  sym_060620D4                ! -> sprite/polygon count
.L_sprite_index_table:
    .4byte  sym_0606A4F8                ! -> Z-sort key table (int16 per polygon)
.L_return:
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r14                    ! restore callee-saved regs
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts                                 ! return to caller
    mov.l @r15+, r8                     ! (delay slot) restore r8
    .2byte  0x0009                      ! alignment padding (nop encoding)

! ===========================================================================
! Data tables
! ===========================================================================

    .global sym_0602C450
sym_0602C450:
    ! Pipeline A fn ptrs -- clip dispatch by clip vertex count
    .word 0x0000 /* UNKNOWN */          ! entry 0: unused (0 clipped = no dispatch)
    .word 0x0000 /* UNKNOWN */          ! entry 1: unused
    .4byte  spring_damper               ! entry 2: 2-vertex clip handler
    .4byte  transform_pipeline          ! entry 3: 3-vertex clip handler
    .4byte  mega_render_func            ! entry 4: full-quad clip handler

    .global sym_0602C460
sym_0602C460:
    ! Pipeline B fn ptrs -- partial screen clip handlers
    .word 0x0000 /* UNKNOWN */          ! entry 0: unused
    .word 0x0000 /* UNKNOWN */          ! entry 1: unused
    .4byte  vblank_frame_handler        ! entry 2: 2-vertex screen clip
    .4byte  render_list_builder         ! entry 3: 3-vertex screen clip
    .4byte  render_obj_processor        ! entry 4: 4-vertex screen clip

    .global sym_0602C470
sym_0602C470:
    ! Z-sort dispatch table + sort buffer configuration
    .4byte  loc_0602C380                ! strategy 0: average depth
    .4byte  loc_0602C38C                ! strategy 1: minimum (nearest) depth
    .4byte  loc_0602C3A2                ! strategy 2: maximum (farthest) depth
    .4byte  loc_0602C3D4                ! strategy 3: max + 1.0 bias
    .4byte  loc_0602C3B8                ! strategy 4: max + 11.5 bias
    .4byte  sym_060A2468                ! -> bucket count array (zeroed between passes)
    .4byte  0x06400009                  ! sort buffer size config
    .4byte  sym_060A2428                ! -> bucket index array
    .4byte  sym_06094FA8                ! -> sort working buffer

! ===========================================================================
! sym_0602C494 -- Radix bucket sort (3-pass LSB-first, 32 buckets per pass)
!
! Sorts polygon indices by their 15-bit Z-sort key for back-to-front rendering.
! Each pass extracts a 5-bit slice of the key (bits 0-4, bits 5-9, bits 10-14)
! and distributes elements into 32 buckets, then gathers them back in order.
!
! Args: r4 = element count, r5 = index array ptr
! ===========================================================================

    .global sym_0602C494
sym_0602C494:
    mov.l r8, @-r15                     ! save callee-saved regs
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15                     ! save return address
    mov r4, r8                          ! r8 = element count
    mov r5, r9                          ! r9 = index array base
    mov.l   .L_bucket_counts_init, r1   ! r1 -> bucket count array ptr storage
    mov.l   .L_sort_buffer_b, r11       ! r11 = sort buffer base
    mov.l r11, @r1                      ! initialize bucket count ptr
    ! ---- Copy sort keys from index array to working buffer ----
    mov.l   .L_sort_input, r3           ! r3 -> sort key input buffer
    mov r9, r1                          ! r1 = source index array
    mov #0x0, r2                        ! r2 = copy counter
.L_copy_input_loop:
    mov.w @r1+, r11                     ! read index from source
    add #0x1, r2                        ! increment counter
    cmp/hs r8, r2                       ! counter >= count?
    mov.w r11, @r3                      ! write to sort key buffer
    bf/s    .L_copy_input_loop          ! loop if more
    add #0x2, r3                        ! advance dest ptr (delay slot)
    ! ---- Zero 32 bucket counts (16 longs = 64 bytes) ----
    mov.l   .L_bucket_counts, r1        ! r1 -> end of bucket count array
    mov #0x0, r2                        ! zero value
    mov.l r2, @-r1                      ! clear bucket[31..16]
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1                      ! clear bucket[15..0]
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    ! ---- Pass 1: distribute by bits 0-4 (LSB) ----
    mov.l   .L_sort_input, r6           ! r6 -> sort keys
    mov #0x0, r7                        ! r7 = element index
    mov.l   .L_bucket_indices_b, r10    ! r10 -> bucket index array
    mov.w   .L_bucket_stride_b, r4      ! r4 = 0x0640 = bucket stride (1600 bytes)
    mov.l   .L_sort_buffer_b, r5        ! r5 -> sort working buffer
.L_bucket_pass_1:
    mov.w @r6+, r0                      ! r0 = sort key
    mov r10, r2                         ! r2 -> bucket indices
    and #0x1F, r0                       ! extract bits 0-4 (bucket index)
    add r0, r2                          ! r2 -> this bucket's count (word ptr)
    add r0, r2                          ! (add twice for word addressing)
    mov.w @r2, r1                       ! r1 = current count in this bucket
    mul.l r4, r0                        ! bucket_offset = bucket_idx * stride
    extu.w r1, r0                       ! zero-extend count (into r0 for slot calc)
    add #0x1, r1                        ! increment bucket count
    mov.w r1, @r2                       ! write back new count
    sts macl, r1                        ! r1 = bucket_offset from mul
    shll r0                             ! count * 2 = byte offset within bucket
    add r1, r0                          ! r0 = bucket_base + slot_offset
    mov.w r7, @(r0, r5)                 ! store element index in bucket slot
    add #0x1, r7                        ! next element
    cmp/hs r8, r7                       ! done?
    bf      .L_bucket_pass_1            ! loop if more elements
    ! ---- Gather pass 1: collect from buckets in order ----
    mov r9, r4                          ! r4 = output index array
    mov.l r8, @-r15                     ! save element count (r8 reused in inner loop)
    mov.l   .L_bucket_indices, r3       ! r3 -> bucket count/index array
    mov.l   .L_sort_buffer, r6          ! r6 -> sort working buffer
    mov #0x0, r7                        ! r7 = bucket index
    mov.w   .L_bucket_stride, r0        ! r0 = bucket stride
    mov #0x1F, r5                       ! r5 = 31 (max bucket index)
.L_gather_pass_1:
    mov.w @r3+, r1                      ! r1 = count for this bucket
    mov r6, r2                          ! r2 -> start of this bucket's data
    extu.w r1, r1                       ! zero-extend count
    cmp/pl r1                           ! count > 0?
    bf/s    .L_gather_next_1            ! no: skip to next bucket
    add r0, r6                          ! advance to next bucket base (delay slot)
.L_gather_inner_1:
    mov.w @r2+, r8                      ! read element index from bucket
    add #-0x1, r1                       ! decrement remaining
    cmp/pl r1                           ! more in this bucket?
    mov.w r8, @r4                       ! write to output array
    bt/s    .L_gather_inner_1           ! loop if more
    add #0x2, r4                        ! advance output ptr (delay slot)
.L_gather_next_1:
    add #0x1, r7                        ! next bucket
    cmp/gt r5, r7                       ! past bucket 31?
    bf      .L_gather_pass_1            ! loop if more buckets
    mov.l @r15+, r8                     ! restore element count
    ! ---- Zero 32 bucket counts for pass 2 ----
    mov.l   .L_bucket_counts, r1
    mov #0x0, r2
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    ! ---- Pass 2: distribute by bits 5-9 ----
    mov #0x0, r6                        ! r6 = element index
    mov r9, r7                          ! r7 -> index array (from pass 1 output)
.L_bucket_pass_2:
    mov.w @r7, r1                       ! r1 = element index from sorted array
    extu.w r1, r0                       ! zero-extend
    shll r0                             ! index * 2 = byte offset into sort keys
    mov.l   .L_sort_input, r1           ! r1 -> sort key buffer
    mov.w @(r0, r1), r1                 ! r1 = sort key for this element
    extu.w r1, r0                       ! zero-extend sort key
    shlr2 r0                            ! >> 5 to extract bits 5-9
    shlr2 r0
    shlr r0
    and #0x1F, r0                       ! isolate 5-bit bucket index
    mov r0, r2                          ! r2 = bucket index
    add r0, r2                          ! r2 *= 2 (word addressing)
    mov.l   .L_bucket_indices_b, r1     ! r1 -> bucket index array
    add r1, r2                          ! r2 -> this bucket's count
    mov.w @r2, r3                       ! r3 = current bucket count
    mov r3, r1                          ! save count
    add #0x1, r1                        ! increment count
    mov.w r1, @r2                       ! write back
    mov.w   .L_bucket_stride_b, r1      ! r1 = bucket stride
    mul.l r1, r0                        ! bucket_offset = idx * stride
    extu.w r3, r3                       ! zero-extend old count
    shll r3                             ! count * 2 = slot offset
    sts macl, r1                        ! r1 = bucket_offset
    lds r3, macl                        ! save slot offset via macl
    add #0x1, r6                        ! next element
    sts macl, r0                        ! r0 = slot offset
    add r1, r0                          ! r0 = bucket_base + slot_offset
    mov.l   .L_sort_buffer_b, r1        ! r1 -> sort buffer
    mov.w @r7+, r11                     ! read original index again
    cmp/hs r8, r6                       ! done?
    bf/s    .L_bucket_pass_2            ! loop if more
    mov.w r11, @(r0, r1)               ! store in bucket (delay slot)
    ! ---- Gather pass 2 ----
    mov r9, r4                          ! r4 = output array
    mov.l r8, @-r15                     ! save count
    mov.l   .L_bucket_indices, r3       ! r3 -> bucket counts
    mov.l   .L_sort_buffer, r6          ! r6 -> sort buffer
    mov #0x0, r7                        ! r7 = bucket index
    mov.w   .L_bucket_stride, r0        ! r0 = bucket stride
    mov #0x1F, r5                       ! r5 = 31
.L_gather_pass_2:
    mov.w @r3+, r1                      ! bucket count
    mov r6, r2                          ! bucket start
    extu.w r1, r1
    cmp/pl r1                           ! count > 0?
    bf/s    .L_gather_next_2            ! no: skip
    add r0, r6                          ! advance (delay slot)
.L_gather_inner_2:
    mov.w @r2+, r8                      ! read from bucket
    add #-0x1, r1                       ! decrement
    cmp/pl r1                           ! more?
    mov.w r8, @r4                       ! write to output
    bt/s    .L_gather_inner_2           ! loop
    add #0x2, r4                        ! advance (delay slot)
.L_gather_next_2:
    add #0x1, r7                        ! next bucket
    cmp/gt r5, r7                       ! past 31?
    bf      .L_gather_pass_2            ! loop
    mov.l @r15+, r8                     ! restore count
    ! ---- Zero 32 bucket counts for pass 3 ----
    mov.l   .L_bucket_counts, r1
    mov #0x0, r2
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    mov.l r2, @-r1
    ! ---- Pass 3: distribute by bits 10-14 (MSB) ----
    mov #0x0, r6                        ! r6 = element index
    mov r9, r7                          ! r7 -> index array
.L_bucket_pass_3:
    mov.w @r7, r1                       ! r1 = element index
    extu.w r1, r1                       ! zero-extend
    mov r1, r0                          ! copy
    add r1, r0                          ! index * 2 = byte offset
    mov.l   .L_sort_input, r1           ! r1 -> sort key buffer
    mov.b @(r0, r1), r0                 ! r0 = HIGH byte of sort key (bits 8-15)
    shlr2 r0                            ! >> 2 to align bits 10-14 into 0-4
    and #0x1F, r0                       ! extract 5-bit bucket index
    mov r0, r2                          ! r2 = bucket index
    add r0, r2                          ! r2 *= 2
    mov.l   .L_bucket_indices_b, r1     ! r1 -> bucket index array
    add r1, r2                          ! r2 -> bucket count
    mov.w @r2, r3                       ! r3 = current count
    mov r3, r1
    add #0x1, r1                        ! increment
    mov.w r1, @r2                       ! write back
    mov.w   .L_bucket_stride_b, r1      ! bucket stride
    mul.l r1, r0                        ! bucket_offset = idx * stride
    extu.w r3, r3                       ! zero-extend old count
    shll r3                             ! count * 2 = slot offset
    sts macl, r1                        ! bucket_offset
    lds r3, macl                        ! save slot offset
    add #0x1, r6                        ! next element
    sts macl, r0                        ! slot offset
    add r1, r0                          ! bucket_base + slot_offset
    mov.l   .L_sort_buffer_b, r1        ! sort buffer
    mov.w @r7+, r11                     ! read original index
    cmp/hs r8, r6                       ! done?
    bf/s    .L_bucket_pass_3            ! loop
    mov.w r11, @(r0, r1)               ! store (delay slot)
    ! ---- Gather pass 3 (final) ----
    mov r9, r4                          ! output array
    mov.l r8, @-r15                     ! save count
    mov.l   .L_bucket_indices, r3       ! bucket counts
    mov.l   .L_sort_buffer, r6          ! sort buffer
    mov #0x0, r7                        ! bucket index
    mov.w   .L_bucket_stride, r0        ! bucket stride
    mov #0x1F, r5                       ! max bucket
.L_gather_pass_3:
    mov.w @r3+, r1                      ! bucket count
    mov r6, r2                          ! bucket start
    extu.w r1, r1
    cmp/pl r1                           ! count > 0?
    bf/s    .L_gather_next_3            ! no: skip
    add r0, r6                          ! advance (delay slot)
.L_gather_inner_3:
    mov.w @r2+, r8                      ! read from bucket
    add #-0x1, r1                       ! decrement
    cmp/pl r1                           ! more?
    mov.w r8, @r4                       ! write to output
    bt/s    .L_gather_inner_3           ! loop
    add #0x2, r4                        ! advance (delay slot)
.L_gather_next_3:
    add #0x1, r7                        ! next bucket
    cmp/gt r5, r7                       ! past 31?
    bf      .L_gather_pass_3            ! loop
    mov.l @r15+, r8                     ! restore count
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r11                    ! restore callee-saved regs
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts                                 ! return to caller
    mov.l @r15+, r8                     ! (delay slot) restore r8
.L_bucket_stride:
    .2byte  0x0640                      ! 1600 = bucket stride (max 800 entries * 2)
    .2byte  0x0000                      ! alignment padding
.L_bucket_counts:
    .4byte  sym_060A2468                ! -> bucket count array (32 words)
.L_bucket_indices:
    .4byte  sym_060A2428                ! -> bucket index array (32 words)
.L_sort_buffer:
    .4byte  sym_06094FA8                ! -> sort working buffer
.L_bucket_stride_b:
    .2byte  0x0640                      ! 1600 = bucket stride (duplicate for PC reach)
    .2byte  0x0009                      ! unused / padding
.L_bucket_counts_init:
    .4byte  sym_060A2468                ! -> bucket count array ptr (duplicate)
.L_sort_buffer_b:
    .4byte  sym_06094FA8                ! -> sort buffer base (duplicate)
.L_sort_input:
    .4byte  sym_060A17A8                ! -> sort key input buffer
.L_bucket_indices_b:
    .4byte  sym_060A2428                ! -> bucket index array (duplicate)
