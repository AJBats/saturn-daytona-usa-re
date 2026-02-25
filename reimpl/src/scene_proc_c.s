/* scene_proc_c -- face projection, backface cull & z-sort for 3D scene pipeline
 * Translation unit: 0x0602AF48 - 0x0602B334
 *
 * One of several parallel scene processing variants (B/C/D/E) in the render
 * pipeline. For each polygon face in a 24-byte entry list (iterated backwards):
 *
 *   1. Look up vertex cache (16-byte entries at sym_06094620). If the vertex
 *      index was already projected, reuse the cached result.
 *   2. Scale 16-bit vertex coords to 16.16 fixed-point (shift left 11).
 *   3. Transform through 3x3 rotation matrix + translation via 32x32->64
 *      MAC.L dot products (fixed-point 16.16).
 *   4. Backface cull: dot(position, face_normal). Skip face if dot <= 0.
 *   5. Perspective project and screen-space bounds check against clip limits.
 *   6. Bounds-check all 4 projected vertices (X and Y) against screen edges.
 *      Reject if fully off-screen in any direction.
 *   7. Combine face depths using one of 5 strategies selected by polygon type
 *      bits (average, min, max, max+small_bias, max+large_bias).
 *   8. Convert depth to sort key and write into z-sort buffer for draw ordering.
 *
 * Called from scene graph walk with:
 *   r4 = face data array base        r5 = vertex table ptr
 *   r6 = rotation matrix ptr          r7 = face count
 *
 * Internal subroutines:
 *   transform_vertex   — scale + 3x3 matrix multiply + backface test
 *   project_and_clip   — perspective project, screen bounds check, store output
 *   cache_lookup        — vertex cache hit test, skip transform on hit
 *
 * Data:
 *   sym_0602B2C8   — scratch: projected depth output (8 words, 4 faces x XY)
 *   sym_0602B2E8   — scratch: transformed position (xyz + extra)
 *   sym_0602B2F8   — scratch: matrix multiply intermediate (3 words)
 *   sym_0602B304   — scratch: scaled vertex coords (3 words)
 *   sym_0602B310   — scratch: dot product result (1 word)
 *   sym_0602B314   — depth strategy dispatch table (5 entries)
 */

    .section .text.FUN_0602AF48


    .global scene_proc_c
    .type scene_proc_c, @function
scene_proc_c:
    mov.l r14, @-r15                    ! save r14
    sts.l pr, @-r15                     ! save return address
    mov r4, r8                          ! r8 = face data array base
    mov r5, r14                         ! r14 = vertex table ptr
    mov r6, r13                         ! r13 = polygon group index
    mov.l   .L_ptr_cache_base, r12      ! r12 -> vertex cache (64 x 16-byte entries)
    mov #0x40, r4                       ! 64 cache slots to clear
    mov #-0x1, r0                       ! -1 = invalid cache tag
.L_clear_cache_loop:
    mov.l r0, @r12                      ! cache[i].tag = -1 (invalidate)
    dt r4                               ! decrement counter
    bf/s    .L_clear_cache_loop         ! loop until all 64 cleared
    add #0x10, r12                      ! advance to next 16-byte cache entry
    mov.l   .L_ptr_clip_dist, r10       ! r10 -> ptr to max clip distance
    mov.l @r10, r10                     ! r10 = max clip distance value
    mov #0x18, r0                       ! 0x18 = sizeof(face_entry)
    mul.l r7, r0                        ! face_count * sizeof(face_entry)
    sts macl, r0                        ! r0 = total byte offset
    add r0, r8                          ! r8 -> past last face (iterate backwards)
.L_face_loop:
    mov.l r7, @-r15                     ! push remaining face count
    add #-0x18, r8                      ! step to previous face entry
    mov.l   .L_ptr_depth_output, r11    ! r11 -> depth output scratch
    mov.l   .L_ptr_xform_result, r5    ! r5 -> transformed position output
    mov.l   .L_ptr_matrix_base, r0     ! r0 -> ptr to rotation matrix ptr
    mov.l @r0, r6                       ! r6 -> 3x3 rotation matrix base
    mov.w @(16, r8), r0                 ! face.vtx_idx[0] (vertex 0 index)
    extu.w r0, r4                       ! zero-extend to 32-bit
    bsr     .L_transform_vertex         ! transform vertex 0
    mov #0x6, r9                        ! r9 = sizeof(vertex_xyz) = 6 (delay slot)
    mov.l r1, @r5                       ! store xform result X
    mov.l r2, @(4, r5)                  ! store xform result Y
    mov.l r3, @(8, r5)                  ! store xform result Z
    mov.l   .L_ptr_dot_result, r7      ! r7 -> dot product scratch
    mov.l r2, @r7                       ! store Y component for backface test
    mov.w @(12, r8), r0                 ! face.flags
    tst #0x8, r0                        ! test bit 3: skip backface cull?
    bf      .L_backface_pass            ! bit set: skip cull, proceed directly
    mov.l   .L_ptr_mat_intermediate, r7 ! r7 -> matrix intermediate scratch
    mov r8, r4                          ! r4 -> face normal data (first 12 bytes)
    clrmac                              ! --- dot(normal, matrix_row0) ---
    mac.l @r4+, @r6+                    ! normal.x * m[0][0]
    mac.l @r4+, @r6+                    ! normal.y * m[0][1]
    mac.l @r4+, @r6+                    ! normal.z * m[0][2]
    add #-0xC, r4                       ! rewind normal ptr
    sts mach, r0                        ! get high 32 bits of MAC result
    sts macl, r9                        ! get low 32 bits
    clrmac                              ! --- dot(normal, matrix_row1) ---
    mac.l @r4+, @r6+                    ! normal.x * m[1][0]
    xtrct r0, r9                        ! combine hi:lo -> 16.16 fixed result
    mov.l r9, @r7                       ! store xformed normal.x
    mac.l @r4+, @r6+                    ! normal.y * m[1][1]
    mac.l @r4+, @r6+                    ! normal.z * m[1][2]
    add #-0xC, r4                       ! rewind normal ptr
    sts mach, r0                        ! high 32 bits
    sts macl, r9                        ! low 32 bits
    clrmac                              ! --- dot(normal, matrix_row2) ---
    mac.l @r4+, @r6+                    ! normal.x * m[2][0]
    xtrct r0, r9                        ! combine -> 16.16 fixed
    mov.l r9, @(4, r7)                  ! store xformed normal.y
    mac.l @r4+, @r6+                    ! normal.y * m[2][1]
    mac.l @r4+, @r6+                    ! normal.z * m[2][2]
    add #-0x24, r6                      ! rewind matrix ptr to start (3x3 = 36 bytes)
    sts mach, r0                        ! high 32 bits
    sts macl, r9                        ! low 32 bits
    xtrct r0, r9                        ! combine -> 16.16 fixed
    mov.l r9, @(8, r7)                  ! store xformed normal.z
    clrmac                              ! --- dot(position, xformed_normal) ---
    mac.l @r5+, @r7+                    ! pos.x * norm.x
    mac.l @r5+, @r7+                    ! pos.y * norm.y
    mac.l @r5+, @r7+                    ! pos.z * norm.z
    add #-0xC, r5                       ! rewind position ptr
    sts mach, r9                        ! high 32 bits of dot product
    sts macl, r0                        ! low 32 bits
    xtrct r9, r0                        ! combine -> 16.16 fixed
    cmp/pl r0                           ! dot > 0? (facing camera)
    bt      .L_backface_pass            ! yes: face is visible, continue
    bra     .L_next_face                ! no: backface, skip this polygon
    nop
    .2byte  0x0000                      ! alignment padding
.L_ptr_cache_base:
    .4byte  sym_06094620                ! vertex cache array (64 x 16 bytes)
.L_ptr_clip_dist:
    .4byte  sym_06063F08                ! ptr to max clip distance
.L_ptr_depth_output:
    .4byte  sym_0602B2C8                ! projected depth output (4 faces x XY)
.L_ptr_xform_result:
    .4byte  sym_0602B2E8                ! transformed position (xyz + extra)
.L_ptr_matrix_base:
    .4byte  sym_06089EDC                ! ptr to ptr to 3x3 rotation matrix
.L_ptr_dot_result:
    .4byte  sym_0602B310                ! dot product result scratch
.L_ptr_mat_intermediate:
    .4byte  sym_0602B2F8                ! matrix multiply intermediate (3 words)
.L_backface_pass:                           ! --- process vertex 0 (cache lookup + project) ---
    mov.w @(16, r8), r0                 ! face.vtx_idx[0]
    mov.l   .L_ptr_face1_cont, r7      ! r7 = continuation addr if cache hit
    bsr     .L_cache_lookup             ! check vertex cache for vtx 0
    mov r0, r4                          ! r4 = vertex index (delay slot)
    mov.l r3, @r5                       ! store Z to xform result
    add #0x4, r5                        ! advance xform result ptr
    mov.w @(16, r8), r0                 ! reload vtx_idx[0] for projection
    bsr     .L_project_and_clip         ! perspective project + bounds check
    nop

    .global sym_0602B012
sym_0602B012:                               ! --- process vertex 1 ---
    mov.w @(18, r8), r0                 ! face.vtx_idx[1]
    mov.l   .L_ptr_face2_cont, r7      ! continuation addr if cache hit
    bsr     .L_cache_lookup             ! check vertex cache for vtx 1
    mov r0, r4                          ! r4 = vertex index (delay slot)
    bsr     .L_transform_vertex         ! transform vertex 1
    mov #0x6, r9                        ! r9 = sizeof(vertex_xyz) (delay slot)
    mov.l r3, @r5                       ! store Z to xform result
    add #0x4, r5                        ! advance xform result ptr
    mov.w @(18, r8), r0                 ! reload vtx_idx[1]
    bsr     .L_project_and_clip         ! perspective project + bounds check
    nop

    .global sym_0602B028
sym_0602B028:                               ! --- process vertex 2 ---
    mov.w @(20, r8), r0                 ! face.vtx_idx[2]
    mov.l   .L_ptr_face3_cont, r7      ! continuation addr if cache hit
    bsr     .L_cache_lookup             ! check vertex cache for vtx 2
    mov r0, r4                          ! r4 = vertex index (delay slot)
    bsr     .L_transform_vertex         ! transform vertex 2
    mov #0x6, r9                        ! r9 = sizeof(vertex_xyz) (delay slot)
    mov.l r3, @r5                       ! store Z to xform result
    add #0x4, r5                        ! advance xform result ptr
    mov.w @(20, r8), r0                 ! reload vtx_idx[2]
    bsr     .L_project_and_clip         ! perspective project + bounds check
    nop

    .global sym_0602B03E
sym_0602B03E:                               ! --- process vertex 3 ---
    mov.w @(22, r8), r0                 ! face.vtx_idx[3]
    mov.l   .L_ptr_face4_cont, r7      ! continuation addr if cache hit
    bsr     .L_cache_lookup             ! check vertex cache for vtx 3
    mov r0, r4                          ! r4 = vertex index (delay slot)
    bsr     .L_transform_vertex         ! transform vertex 3
    mov #0x6, r9                        ! r9 = sizeof(vertex_xyz) (delay slot)
    mov.l r3, @r5                       ! store Z to xform result
    add #0x4, r5                        ! advance xform result ptr
    mov.w @(22, r8), r0                 ! reload vtx_idx[3]
    bsr     .L_project_and_clip         ! perspective project + bounds check
    nop

    .global sym_0602B054
sym_0602B054:                               ! --- all 4 vertices projected, now bounds-check ---
    mov.l   .L_ptr_sort_index, r0      ! r0 -> sort write index
    mov #0x18, r1                       ! 0x18 = sizeof(sprite_entry)
    mov.l @r0, r0                       ! r0 = current sort index
    mulu.w r0, r1                       ! index * sizeof(sprite_entry)
    mov.l   .L_ptr_sprite_table, r2    ! r2 = sprite table base
    sts macl, r9                        ! r9 = byte offset into sprite table
    add r2, r9                          ! r9 -> current sprite entry slot
    add #-0x20, r11                     ! rewind r11 to start of depth output (4 faces x 8 bytes)
    mov.w   DAT_0602b082, r12           ! r12 = X low bound (0xFF50 = -176)
    mov.l @(0, r11), r0                 ! r0 = face0.projected_x
    mov.l @(8, r11), r2                 ! r2 = face1.projected_x
    mov.l @(16, r11), r4                ! r4 = face2.projected_x
    mov.l @(24, r11), r6                ! r6 = face3.projected_x
    cmp/gt r0, r12                      ! all X < x_lo_bound?
    bf      .L_check_x_hi_bounds        ! no: at least one on screen
    cmp/gt r2, r12                      ! check face1
    bf      .L_check_x_hi_bounds
    cmp/gt r4, r12                      ! check face2
    bf      .L_check_x_hi_bounds
    cmp/gt r6, r12                      ! check face3
    bf      .L_check_x_hi_bounds
    bra     .L_next_face                ! all 4 off-screen left: skip
    nop

    .global DAT_0602b082
DAT_0602b082:
    .2byte  0xFF50                      ! X low bound: -176
.L_ptr_face1_cont:
    .4byte  sym_0602B012                ! continuation: process vertex 1
.L_ptr_face2_cont:
    .4byte  sym_0602B028                ! continuation: process vertex 2
.L_ptr_face3_cont:
    .4byte  sym_0602B03E                ! continuation: process vertex 3
.L_ptr_face4_cont:
    .4byte  sym_0602B054                ! continuation: bounds check + sort
.L_ptr_sort_index:
    .4byte  sym_060620D0                ! sort write index (shared global)
.L_ptr_sprite_table:
    .4byte  sym_0608AC20                ! sprite data table (24-byte entries)
.L_check_x_hi_bounds:                       ! --- check if all X > x_hi_bound ---
    mov.w   DAT_0602b116, r12           ! r12 = X high bound (0x00B0 = 176)
    cmp/gt r0, r12                      ! any X within right edge?
    bt      .L_check_y_lo_bounds        ! yes: at least one visible
    cmp/gt r2, r12                      ! check face1
    bt      .L_check_y_lo_bounds
    cmp/gt r4, r12                      ! check face2
    bt      .L_check_y_lo_bounds
    cmp/gt r6, r12                      ! check face3
    bt      .L_next_face                ! all 4 off-screen right: skip
.L_check_y_lo_bounds:                       ! --- check Y low bounds ---
    mov.w   DAT_0602b118, r12           ! r12 = Y low bound (0xFF81 = -127)
    mov.l @(4, r11), r1                 ! r1 = face0.projected_y
    mov.l @(12, r11), r3                ! r3 = face1.projected_y
    mov.l @(20, r11), r5                ! r5 = face2.projected_y
    mov.l @(28, r11), r7                ! r7 = face3.projected_y
    cmp/gt r1, r12                      ! all Y < y_lo_bound?
    bf      .L_check_y_hi_bounds        ! no: at least one on screen
    cmp/gt r3, r12                      ! check face1
    bf      .L_check_y_hi_bounds
    cmp/gt r5, r12                      ! check face2
    bf      .L_check_y_hi_bounds
    cmp/gt r7, r12                      ! check face3
    bt      .L_next_face                ! all 4 off-screen bottom: skip
.L_check_y_hi_bounds:                       ! --- check Y high bounds ---
    mov.w   DAT_0602b11a, r12           ! r12 = Y high bound (0x0051 = 81)
    cmp/gt r1, r12                      ! any Y within top edge?
    bt      .L_build_sort_entry         ! yes: polygon is visible
    cmp/gt r3, r12                      ! check face1
    bt      .L_build_sort_entry
    cmp/gt r5, r12                      ! check face2
    bt      .L_build_sort_entry
    cmp/gt r7, r12                      ! check face3
    bf      .L_next_face                ! all 4 off-screen top: skip
.L_build_sort_entry:                        ! --- write sprite entry to sort table ---
    mov r9, r12                         ! r12 = sprite entry base
    add #0x18, r12                      ! r12 -> past end of entry (write backwards)
    mov.w r7, @-r12                     ! store face3.y (truncated to 16-bit)
    mov.w r6, @-r12                     ! store face3.x
    mov.w r5, @-r12                     ! store face2.y
    mov.w r4, @-r12                     ! store face2.x
    mov.w r3, @-r12                     ! store face1.y
    mov.w r2, @-r12                     ! store face1.x
    mov.w r1, @-r12                     ! store face0.y
    mov.w r0, @-r12                     ! store face0.x
    mov.w @(14, r8), r0                 ! face.texture_id
    mov.w r0, @(6, r9)                  ! sprite.texture_id = face.texture_id
    mov.w @(12, r8), r0                 ! face.flags
    shlr2 r0                            ! shift right 4 to extract color bits
    shlr2 r0
    and #0xF, r0                        ! mask to 4-bit color palette index
    mov.b r0, @(4, r9)                  ! sprite.color_idx = palette index
    mov r13, r0                         ! r13 = polygon group index
    mov.b r0, @(5, r9)                  ! sprite.group_idx = group index
    mov.w @(12, r8), r0                 ! face.flags again
    mov.l   .L_ptr_depth_dispatch, r1  ! r1 -> depth strategy dispatch table
    and #0x7, r0                        ! mask low 3 bits = depth strategy type
    shll2 r0                            ! type * 4 = byte offset into dispatch table
    mov.l @(r0, r1), r2                 ! r2 = depth strategy handler address
    .word 0xC777 /* mova @(0x1DC, PC), r0 — load addr of depth values */
    mov.l @r0, r3                       ! r3 = depth[0] (vertex 0 Z)
    mov.l @(4, r0), r4                  ! r4 = depth[1] (vertex 1 Z)
    mov.l @(8, r0), r5                  ! r5 = depth[2] (vertex 2 Z)
    jmp @r2                             ! jump to depth strategy handler
    mov.l @(12, r0), r6                 ! r6 = depth[3] (vertex 3 Z) (delay slot)

    .global DAT_0602b116
DAT_0602b116:
    .2byte  0x00B0                      ! X high bound: +176

    .global DAT_0602b118
DAT_0602b118:
    .2byte  0xFF81                      ! Y low bound: -127

    .global DAT_0602b11a
DAT_0602b11a:
    .2byte  0x0051                      ! Y high bound: +81
.L_ptr_depth_dispatch:
    .4byte  sym_0602B314                ! depth strategy dispatch table (5 fn ptrs)

    .global loc_0602B120
loc_0602B120:                               ! --- depth strategy 0: average of 4 depths ---
    add r4, r3                          ! r3 = depth[0] + depth[1]
    add r5, r6                          ! r6 = depth[2] + depth[3]
    add r6, r3                          ! r3 = sum of all 4
    bra     .L_write_sort_key           ! go write sort key
    shlr2 r3                            ! r3 = sum / 4 (delay slot)

    .global loc_0602B12A
loc_0602B12A:                               ! --- depth strategy 1: minimum depth ---
    cmp/ge r3, r4                       ! depth[1] >= depth[0]?
    bt      .L_min_check_v1             ! yes: keep r3
    mov r4, r3                          ! no: r3 = depth[1] (smaller)
.L_min_check_v1:
    cmp/ge r3, r5                       ! depth[2] >= current min?
    bt      .L_min_check_v2             ! yes: keep r3
    mov r5, r3                          ! no: r3 = depth[2]
.L_min_check_v2:
    cmp/ge r3, r6                       ! depth[3] >= current min?
    bt      .L_min_done                 ! yes: keep r3
    mov r6, r3                          ! no: r3 = depth[3]
.L_min_done:
    bra     .L_write_sort_key           ! go write sort key
    nop

    .global loc_0602B140
loc_0602B140:                               ! --- depth strategy 2: maximum depth ---
    cmp/gt r3, r4                       ! depth[1] > depth[0]?
    bf      .L_max_check_v1             ! no: keep r3
    mov r4, r3                          ! yes: r3 = depth[1] (larger)
.L_max_check_v1:
    cmp/gt r3, r5                       ! depth[2] > current max?
    bf      .L_max_check_v2             ! no: keep r3
    mov r5, r3                          ! yes: r3 = depth[2]
.L_max_check_v2:
    cmp/gt r3, r6                       ! depth[3] > current max?
    bf      .L_max_done                 ! no: keep r3
    mov r6, r3                          ! yes: r3 = depth[3]
.L_max_done:
    bra     .L_write_sort_key           ! go write sort key
    nop

    .global loc_0602B156
loc_0602B156:                               ! --- depth strategy 3: max + small bias (0x10000) ---
    mov #0x1, r0                        ! r0 = 1
    bra     .L_max_bias_find            ! find max, then add bias
    shll16 r0                           ! r0 = 0x10000 (1.0 in 16.16) (delay slot)

    .global loc_0602B15C
loc_0602B15C:                               ! --- depth strategy 4: max + large bias (0xB8000) ---
    mov.l   .L_depth_bias_large, r0     ! r0 = 0x000B8000 (11.5 in 16.16)
.L_max_bias_find:                           ! --- find max of 4 depths, then add bias ---
    cmp/gt r3, r4                       ! depth[1] > depth[0]?
    bf      .L_max_bias_v1              ! no: keep r3
    mov r4, r3                          ! yes: r3 = depth[1]
.L_max_bias_v1:
    cmp/gt r3, r5                       ! depth[2] > current max?
    bf      .L_max_bias_v2              ! no: keep r3
    mov r5, r3                          ! yes: r3 = depth[2]
.L_max_bias_v2:
    cmp/gt r3, r6                       ! depth[3] > current max?
    bf      .L_max_bias_done            ! no: keep r3
    mov r6, r3                          ! yes: r3 = depth[3]
.L_max_bias_done:
    add r0, r3                          ! add depth bias to max
.L_write_sort_key:                          ! --- convert depth to sort key ---
    mov.l   .L_ptr_dot_result_b, r1    ! r1 -> dot product result (Y component)
    mov.l @r1, r1                       ! r1 = dot product Y
    mov.l   .L_ptr_scene_param, r0     ! r0 -> scene depth parameter
    mov.l @r0, r0                       ! r0 = scene depth param
    mov.l   .L_fp_two, r2             ! r2 = 2.0 (16.16 fixed-point)
    add r2, r1                          ! r1 = dot_y + 2.0
    cmp/gt r1, r0                       ! scene_param > (dot_y + 2.0)?
    bf      .L_store_sort_key           ! no: skip extra bias
    mov.l   .L_depth_bias_extra, r2    ! yes: add extra bias (10.0)
    add r2, r3                          ! r3 = depth + 0xA0000
.L_store_sort_key:                          ! --- write final sort key to buffer ---
    mov.l   .L_ptr_sort_count, r2      ! r2 -> sort count variable
    neg r3, r3                          ! negate depth (far = low sort key)
    mov.l   .L_ptr_sort_buffer, r1     ! r1 -> sort key buffer
    shlr8 r3                            ! shift right 12 total (>>8 + >>2 + >>2)
    mov.l @r2, r0                       ! r0 = current sort count
    shlr2 r3                            ! continue shifting
    shlr2 r3                            ! r3 = depth >> 12 (16-bit sort key)
    shll r0                             ! sort_count * 2 (word index to byte offset)
    mov.w r3, @(r0, r1)                 ! sort_buffer[count] = sort_key
    shar r0                             ! restore sort count from byte offset
    add #0x1, r0                        ! increment sort count
    mov.l r0, @r2                       ! store updated sort count
.L_next_face:                               ! --- loop/exit ---
    mov.l @r15+, r7                     ! pop remaining face count
    dt r7                               ! decrement and test
    bt      .L_epilogue                 ! zero: done, exit
    bra     .L_face_loop                ! non-zero: process next face
    nop
.L_depth_bias_large:
    .4byte  0x000B8000                  ! 11.5 in 16.16 fixed-point (large depth bias)
.L_ptr_dot_result_b:
    .4byte  sym_0602B310                ! dot product result scratch (reused)
.L_ptr_scene_param:
    .4byte  sym_06063F54                ! scene depth parameter for bias decision
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_depth_bias_extra:
    .4byte  0x000A0000                  ! 10.0 in 16.16 fixed-point (extra depth bias)
.L_ptr_sort_count:
    .4byte  sym_060620D0                ! sort write index / count
.L_ptr_sort_buffer:
    .4byte  sym_0606A4F8                ! sort key buffer (array of 16-bit keys)
.L_epilogue:                                ! --- function epilogue ---
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r14                    ! restore callee-saved regs
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts                                 ! return to caller
    mov.l @r15+, r8                     ! restore r8 (delay slot)
.L_transform_vertex:                        ! --- subroutine: scale + 3x3 transform + clip test ---
    mul.l r9, r4                        ! vtx_index * sizeof(vertex_xyz)
    mov.l   .L_ptr_vtx_scratch, r4    ! r4 -> scaled vertex scratch buffer
    sts macl, r0                        ! r0 = byte offset into vertex table
    add r14, r0                         ! r0 -> vertex data (3 x int16 XYZ)
    mov.w @r0+, r1                      ! r1 = vertex X (16-bit)
    mov.w @r0+, r2                      ! r2 = vertex Y (16-bit)
    mov.w @r0+, r3                      ! r3 = vertex Z (16-bit)
    shll8 r1                            ! X <<= 11 (scale to 16.16 fixed-point)
    shll2 r1
    shll r1
    mov.l r1, @r4                       ! scratch[0] = scaled X
    shll8 r2                            ! Y <<= 11
    shll2 r2
    shll r2
    mov.l r2, @(4, r4)                  ! scratch[1] = scaled Y
    shll8 r3                            ! Z <<= 11
    shll2 r3
    shll r3
    mov.l r3, @(8, r4)                  ! scratch[2] = scaled Z
    mov #0x18, r7                       ! 0x18 = offset to translation vector
    add r6, r7                          ! r7 -> translation vector (past 3x3 matrix)
    clrmac                              ! --- result.z = vtx . matrix_row2 + tz ---
    mac.l @r4+, @r7+                    ! vtx.x * m[2][0]
    mac.l @r4+, @r7+                    ! vtx.y * m[2][1]
    mac.l @r4+, @r7+                    ! vtx.z * m[2][2]
    add #-0xC, r4                       ! rewind vertex ptr
    mov.l @(8, r7), r9                  ! r9 = translation.z
    sts mach, r0                        ! high 32 bits of dot product
    sts macl, r3                        ! low 32 bits
    xtrct r0, r3                        ! combine -> 16.16 fixed result
    add r9, r3                          ! r3 = result.z + translation.z
    cmp/gt r10, r3                      ! result.z > clip distance?
    bf      .L_next_face                ! no: behind clip plane, skip face
    mov.w   .L_cache_slot_offset, r9   ! r9 = cache slot offset (signed 0xFF00)
    mov.w   .L_backface_threshold, r0  ! r0 = backface threshold (0x00A0)
    mov.l r0, @(16, r9)                 ! cache[slot].threshold = 0xA0
    mov.l r3, @(0, r9)                  ! cache[slot].depth_z = result.z
    mov #0x0, r0                        ! zero
    mov.l r0, @(20, r9)                 ! cache[slot].reserved = 0
    clrmac                              ! --- result.x = vtx . matrix_row0 + tx ---
    mac.l @r4+, @r6+                    ! vtx.x * m[0][0]
    mac.l @r4+, @r6+                    ! vtx.y * m[0][1]
    mac.l @r4+, @r6+                    ! vtx.z * m[0][2]
    add #-0xC, r4                       ! rewind vertex ptr
    mov.l @r7+, r9                      ! r9 = translation.x
    sts mach, r0                        ! high 32 bits
    sts macl, r1                        ! low 32 bits
    clrmac                              ! --- result.y = vtx . matrix_row1 + ty ---
    mac.l @r4+, @r6+                    ! vtx.x * m[1][0]
    xtrct r0, r1                        ! combine -> 16.16 fixed result.x
    add r9, r1                          ! r1 = result.x + translation.x
    mac.l @r4+, @r6+                    ! vtx.y * m[1][1]
    mac.l @r4+, @r6+                    ! vtx.z * m[1][2]
    mov.l @r7+, r9                      ! r9 = translation.y
    sts mach, r0                        ! high 32 bits
    sts macl, r2                        ! low 32 bits
    xtrct r0, r2                        ! combine -> 16.16 fixed result.y
    add r9, r2                          ! r2 = result.y + translation.y
    rts                                 ! return: r1=X, r2=Y, r3=Z
    add #-0x18, r6                      ! rewind matrix ptr (delay slot)
.L_cache_slot_offset:
    .2byte  0xFF00                      ! signed offset to cache slot (-256)
.L_backface_threshold:
    .2byte  0x00A0                      ! backface cull threshold (160)
    .2byte  0x0000                      ! alignment padding
.L_ptr_vtx_scratch:
    .4byte  sym_0602B304                ! scaled vertex scratch (3 x 32-bit XYZ)
.L_project_and_clip:                        ! --- subroutine: perspective project + clip ---
    mov.w   .L_project_base_offset, r9 ! r9 = base offset (signed 0xFF00 = -256)
    mov.l @(28, r9), r7                 ! r7 = perspective scale factor (from base+28)
    dmuls.l r1, r7                      ! projected_x = result.x * scale
    neg r2, r2                          ! negate Y (screen Y is inverted)
    sts mach, r1                        ! r1 = projected X (high word of 64-bit result)
    dmuls.l r2, r7                      ! projected_y = -result.y * scale
    mov.l r1, @r11                      ! store projected X to depth output
    sts mach, r2                        ! r2 = projected Y
    mov.l r2, @(4, r11)                 ! store projected Y to depth output
    add #0x8, r11                       ! advance depth output ptr (8 bytes per face)
    mov.w   DAT_0602b292, r7            ! r7 = clip X max (0x0190 = 400)
    cmp/gt r7, r1                       ! projected X > 400?
    bt      .L_next_face                ! yes: off-screen right, skip
    mov.w   DAT_0602b294, r7            ! r7 = clip X/Y min (0xFE70 = -400)
    cmp/gt r1, r7                       ! -400 > projected X?
    bt      .L_next_face                ! yes: off-screen left, skip
    mov.w   DAT_0602b296, r7            ! r7 = clip Y max (0x00C8 = 200)
    cmp/gt r7, r2                       ! projected Y > 200?
    bt      .L_next_face                ! yes: off-screen bottom, skip
    mov.w   DAT_0602b294, r7            ! r7 = clip Y min (-400)
    cmp/gt r2, r7                       ! -400 > projected Y?
    bt      .L_next_face                ! yes: off-screen top, skip
    mov.l r0, @r12                      ! cache[slot].vtx_index = original vtx index
    mov.l r1, @(4, r12)                 ! cache[slot].projected_x = r1
    mov.l r2, @(8, r12)                 ! cache[slot].projected_y = r2
    mov.l r3, @(12, r12)               ! cache[slot].depth_z = r3
    rts                                 ! return to caller
    nop
.L_project_base_offset:
    .2byte  0xFF00                      ! signed offset to projection params (-256)

    .global DAT_0602b292
DAT_0602b292:
    .2byte  0x0190                      ! clip X max: 400

    .global DAT_0602b294
DAT_0602b294:
    .2byte  0xFE70                      ! clip X/Y min: -400

    .global DAT_0602b296
DAT_0602b296:
    .2byte  0x00C8                      ! clip Y max: 200
.L_cache_lookup:                            ! --- subroutine: vertex cache lookup ---
    and #0x3F, r0                       ! hash: vtx_index & 0x3F (64-entry cache)
    mov.l   .L_ptr_cache_array, r12    ! r12 -> cache array base
    shll2 r0                            ! hash * 16 (each cache entry = 16 bytes)
    shll2 r0
    add r0, r12                         ! r12 -> cache[hash]
    mov.l @r12, r0                      ! r0 = cache[hash].tag
    cmp/pz r0                           ! tag >= 0? (not invalidated)
    bf      .L_cache_miss               ! negative tag = empty slot
    cmp/eq r0, r4                       ! tag == vertex index?
    bf      .L_cache_miss               ! no: hash collision, miss
    mov.l @(4, r12), r1                 ! cache hit: r1 = cached projected X
    mov.l @(8, r12), r2                 ! r2 = cached projected Y
    mov.l @(12, r12), r3               ! r3 = cached depth Z
    mov.l r1, @r11                      ! copy projected X to depth output
    mov.l r2, @(4, r11)                 ! copy projected Y to depth output
    add #0x8, r11                       ! advance depth output ptr
    mov.l r3, @r5                       ! copy depth Z to xform result
    jmp @r7                             ! jump to continuation (skip transform)
    add #0x4, r5                        ! advance xform result ptr (delay slot)
    .2byte  0x0000                      ! alignment padding
.L_ptr_cache_array:
    .4byte  sym_06094620                ! vertex cache array (64 x 16 bytes)
.L_cache_miss:                              ! cache miss: return to caller for full transform
    rts                                 ! return (caller will call transform_vertex)
    nop

! ============================================================================
! Scratch data and dispatch tables
! ============================================================================

    .global sym_0602B2C8
sym_0602B2C8:                               ! depth output: 4 faces x (projected_x, projected_y)
    .word 0xFFFF                        ! face0.projected_x (high)
    .word 0xFFFF                        ! face0.projected_x (low)
    .word 0xFFFF                        ! face0.projected_y (high)
    .word 0xFFFF                        ! face0.projected_y (low)
    .word 0xFFFF                        ! face1.projected_x (high)
    .word 0xFFFF                        ! face1.projected_x (low)
    .word 0xFFFF                        ! face1.projected_y (high)
    .word 0xFFFF                        ! face1.projected_y (low)
    .word 0xFFFF                        ! face2.projected_x (high)
    .word 0xFFFF                        ! face2.projected_x (low)
    .word 0xFFFF                        ! face2.projected_y (high)
    .word 0xFFFF                        ! face2.projected_y (low)
    .word 0xFFFF                        ! face3.projected_x (high)
    .word 0xFFFF                        ! face3.projected_x (low)
    .word 0xFFFF                        ! face3.projected_y (high)
    .word 0xFFFF                        ! face3.projected_y (low)

    .global sym_0602B2E8
sym_0602B2E8:                               ! transformed position: vertex 0 result (xyz)
    .word 0xFFFF                        ! xform_result.x (high)
    .word 0xFFFF                        ! xform_result.x (low)

    .global DAT_0602b2ec
DAT_0602b2ec:
    .word 0xFFFF                        ! xform_result.y (high)
    .word 0xFFFF                        ! xform_result.y (low)

    .global DAT_0602b2f0
DAT_0602b2f0:
    .word 0xFFFF                        ! xform_result.z (high)
    .word 0xFFFF                        ! xform_result.z (low)

    .global DAT_0602b2f4
DAT_0602b2f4:
    .word 0xFFFF                        ! xform_result extra (high)
    .word 0xFFFF                        ! xform_result extra (low)

    .global sym_0602B2F8
sym_0602B2F8:                               ! matrix multiply intermediate (xformed normal)
    .word 0xFFFF                        ! xformed_normal.x (high)
    .word 0xFFFF                        ! xformed_normal.x (low)
    .word 0xFFFF                        ! xformed_normal.y (high)
    .word 0xFFFF                        ! xformed_normal.y (low)
    .word 0xFFFF                        ! xformed_normal.z (high)
    .word 0xFFFF                        ! xformed_normal.z (low)

    .global sym_0602B304
sym_0602B304:                               ! scaled vertex scratch (16.16 fixed-point XYZ)
    .word 0xFFFF                        ! scaled_vtx.x (high)
    .word 0xFFFF                        ! scaled_vtx.x (low)
    .word 0xFFFF                        ! scaled_vtx.y (high)
    .word 0xFFFF                        ! scaled_vtx.y (low)
    .word 0xFFFF                        ! scaled_vtx.z (high)
    .word 0xFFFF                        ! scaled_vtx.z (low)

    .global sym_0602B310
sym_0602B310:                               ! dot product result / Y component scratch
    .word 0xFFFF                        ! dot_result (high)
    .word 0xFFFF                        ! dot_result (low)

    .global sym_0602B314
sym_0602B314:                               ! depth strategy dispatch table (5 entries)
    .4byte  loc_0602B120                ! strategy 0: average of 4 depths
    .4byte  loc_0602B12A                ! strategy 1: minimum depth
    .4byte  loc_0602B140                ! strategy 2: maximum depth
    .4byte  loc_0602B156                ! strategy 3: max + small bias (1.0)
    .4byte  loc_0602B15C                ! strategy 4: max + large bias (11.5)

    .global sym_0602B328
sym_0602B328:                               ! prologue fragment (shared with next TU)
    mov.l r8, @-r15                     ! save callee-saved regs for next function
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
