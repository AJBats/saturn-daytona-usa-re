/* scene_proc_b -- Scene Graph Walker B / Frustum Culler (Course Variant)
 * Translation unit: 0x0602ABC4 - 0x0602AF48
 *
 * Parallel instance of the scene graph walker (see scene_graph_walk.s for
 * the primary version at 0x0602B9EC). Walks a scene node array in reverse,
 * transforms each node's 4 child vertices through the 3x3 view matrix via
 * MAC dot products, performs 3-axis frustum culling (near/far Z, top/bottom Y),
 * and writes surviving nodes into a sort buffer with a depth-based sort key.
 *
 * Uses its own transform cache at sym_06094220 (64 x 16-byte entries,
 * invalidated to 0xFFFFFFFF each call). The cache avoids redundant
 * matrix-vector multiplies when the same vertex ID appears in multiple nodes.
 *
 * Functions:
 *   scene_proc_b        -- Main entry: clears cache, iterates nodes in
 *                          reverse, transforms 4 children per node, frustum
 *                          culls, dispatches sort key computation via jump
 *                          table, writes sort buffer entries.
 *
 * Internal subroutines:
 *   view_transform       -- Transforms a child vertex (int16 x3) through the
 *                          view matrix, producing clip-space X/Y/Z. Returns
 *                          early if Z is behind the camera.
 *   depth_scale_store    -- Scales X/Y by perspective Z, clips to screen
 *                          bounds, and stores into the scratch XY buffer.
 *                          On out-of-range, skips to next node.
 *   cache_lookup         -- Checks the 64-entry cache for a previously
 *                          computed transform; on hit, copies cached values
 *                          and jumps to the continuation address in r7.
 *
 * Sort key strategies (jump table at sym_0602AF28, 5 entries):
 *   loc_0602ADA0  [0] sort_avg_depth     -- Average of 4 Z values (>> 2)
 *   loc_0602ADAA  [1] sort_min_depth     -- Minimum Z (nearest face)
 *   loc_0602ADC0  [2] sort_zero_bias     -- Max Z + 0 bias
 *   loc_0602ADC4  [3] sort_64k_bias      -- Max Z + 0x10000 (1.0 FP bias)
 *   loc_0602ADCA  [4] sort_large_bias    -- Max Z + 0x000B8000 (11.5 FP bias)
 *
 * Data (BSS-like, initialized to 0xFFFF at runtime):
 *   sym_0602AEEC  -- Scratch transform buffer (16 words, 4 XY pairs)
 *   sym_0602AF0C  -- Cached XYZ output triplet (3 longwords)
 *   sym_0602AF1C  -- Rotated matrix row result (3 longwords)
 *   sym_0602AF28  -- Sort strategy jump table (5 entries)
 *
 * Key external symbols:
 *   sym_06094220  -- Transform cache array (64 x 16 bytes)
 *   sym_06063F08  -- Pointer to current view matrix (3x3 + translation)
 *   sym_0608A52C  -- Pointer to world-space scene matrix
 *   sym_0608AC20  -- Sort buffer base (node entries, 0x18 bytes each)
 *   sym_060620D4  -- Sort buffer write index
 *   sym_0606A4F8  -- Sort key output array (16-bit per entry)
 *   sym_0605BE36  -- Scene active flag (nonzero = processing enabled)
 */

    .section .text.FUN_0602ABC4


    .global scene_proc_b
    .type scene_proc_b, @function
scene_proc_b:
    mov.l r14, @-r15              ! save r14
    sts.l pr, @-r15               ! save pr (+ pushes r8-r13 via prologue at sym_0602AF3C)
    mov r4, r8                    ! r8 = node_array base pointer
    mov r5, r14                   ! r14 = vertex_data base pointer
    mov r6, r13                   ! r13 = node_group_id
    mov.l   .L_cache_array_base, r12  ! r12 = transform cache base (sym_06094220)
    mov #0x40, r4                 ! 64 cache entries to clear
    mov #-0x1, r0                 ! invalidation marker = 0xFFFFFFFF
.L_cache_clear_loop:
    mov.l r0, @r12                ! cache[i].tag = -1 (invalid)
    dt r4                         ! decrement counter, set T if zero
    bf/s    .L_cache_clear_loop   ! loop until all 64 entries cleared
    add #0x10, r12                ! advance to next cache entry (16 bytes each)
    mov.l   .L_view_matrix_ptr, r10  ! r10 = ptr to view matrix pointer
    mov.l @r10, r10               ! r10 = view matrix base (deref)
    mov #0x18, r0                 ! node struct size = 0x18 bytes
    mul.l r7, r0                  ! r7 = node_count; result = count * 0x18
    sts macl, r0                  ! r0 = total byte offset
    add r0, r8                    ! r8 = pointer past last node (walk backwards)
.L_node_loop_top:
    mov.l r7, @-r15               ! push remaining node count
    add #-0x18, r8                ! r8 = current node (walk backwards)
    mov.l   .L_scene_active_flag, r12  ! r12 = scene active flag address
    mov.w @r12, r0                ! r0 = scene active flag value
    cmp/eq #0x0, r0               ! is scene inactive?
    bt      .L_process_node       ! if inactive (0), process normally
    mov.w @(14, r8), r0           ! r0 = node[i].texture_id (halfword at +0xE)
    mov.w   .L_texture_id_match, r1  ! r1 = 0x0097 (special skip texture ID)
    cmp/eq r0, r1                 ! does texture match the skip ID?
    bf      .L_process_node       ! if not, process normally
    bra     .L_next_node          ! skip this node (special texture during active scene)
    nop
.L_texture_id_match:
    .2byte  0x0097                    ! special texture ID to skip when scene active
    .2byte  0x0000                    ! alignment padding
.L_cache_array_base:
    .4byte  sym_06094220              ! transform cache (64 x 16-byte entries)
.L_view_matrix_ptr:
    .4byte  sym_06063F08              ! ptr to current view matrix
.L_scene_active_flag:
    .4byte  sym_0605BE36              ! scene active flag (word)
.L_process_node:
    mov.l   .L_scratch_xy_buf, r11  ! r11 = scratch XY buffer ptr
    mov.l   .L_cached_xyz_out, r5  ! r5 = cached XYZ output ptr
    mov.l   .L_scene_matrix_ptr, r0  ! load scene matrix pointer address
    mov.l @r0, r6                 ! r6 = scene matrix base (deref)
    mov.w @(16, r8), r0           ! r0 = node[i].child_id_0 (halfword at +0x10)
    mov r0, r9                    ! r9 = child_id_0
    bsr     .L_view_transform     ! transform child_0 position -> (r1,r2,r3)
    nop
    mov.l r1, @r5                 ! store transformed X
    mov.l r2, @(4, r5)            ! store transformed Y
    mov.l r3, @(8, r5)            ! store transformed Z
    mov.w @(12, r8), r0           ! r0 = node[i].flags (halfword at +0xC)
    tst #0x8, r0                  ! test bit 3: has local transform?
    bf      .L_skip_matrix_mul    ! if set, skip matrix multiply
    ! -- Backface cull: compute dot product of node normal with view direction --
    mov.l   .L_rotated_row_buf, r7  ! r7 = rotated row output buffer
    mov r8, r4                    ! r4 = node base (source vector)
    clrmac                        ! clear MAC for dot product
    mac.l @r4+, @r6+             ! row0: accumulate node[0]*matrix[0]
    mac.l @r4+, @r6+             ! row0: accumulate node[1]*matrix[1]
    mac.l @r4+, @r6+             ! row0: accumulate node[2]*matrix[2]
    add #-0xC, r4                ! rewind node pointer
    sts mach, r0                 ! r0 = dot product high word
    sts macl, r9                 ! r9 = dot product low word
    clrmac                        ! clear MAC for next row
    mac.l @r4+, @r6+             ! row1: start accumulate
    xtrct r0, r9                 ! r9 = (mach:macl) >> 16 (32.32 -> 16.16)
    mov.l r9, @r7                ! store rotated row[0]
    mac.l @r4+, @r6+             ! row1: accumulate
    mac.l @r4+, @r6+             ! row1: accumulate
    add #-0xC, r4                ! rewind node pointer
    sts mach, r0                 ! r0 = row1 dot high
    sts macl, r9                 ! r9 = row1 dot low
    clrmac                        ! clear MAC for row2
    mac.l @r4+, @r6+             ! row2: start accumulate
    xtrct r0, r9                 ! r9 = row1 result (16.16)
    mov.l r9, @(4, r7)           ! store rotated row[1]
    mac.l @r4+, @r6+             ! row2: accumulate
    mac.l @r4+, @r6+             ! row2: accumulate
    add #-0x24, r6               ! rewind matrix pointer (3 rows * 12 = 0x24)
    sts mach, r0                 ! r0 = row2 dot high
    sts macl, r9                 ! r9 = row2 dot low
    xtrct r0, r9                 ! r9 = row2 result (16.16)
    mov.l r9, @(8, r7)           ! store rotated row[2]
    clrmac                        ! clear MAC for final dot product
    mac.l @r5+, @r7+             ! final: cached_xyz[0] * rotated[0]
    mac.l @r5+, @r7+             ! final: cached_xyz[1] * rotated[1]
    mac.l @r5+, @r7+             ! final: cached_xyz[2] * rotated[2]
    add #-0xC, r5                ! rewind cached_xyz pointer
    sts mach, r9                 ! r9 = final dot high
    sts macl, r0                 ! r0 = final dot low
    xtrct r9, r0                 ! r0 = visibility dot product (16.16)
    cmp/pl r0                    ! is result > 0? (facing camera)
    bt      .L_skip_matrix_mul   ! if positive, node faces camera -- continue
    bra     .L_next_node          ! else backface cull -- skip this node
    nop
    .2byte  0x0000                ! alignment padding
.L_scratch_xy_buf:
    .4byte  sym_0602AEEC              ! scratch XY buffer (4 XY pairs, 32 bytes)
.L_cached_xyz_out:
    .4byte  sym_0602AF0C              ! cached XYZ output triplet (3 longwords)
.L_scene_matrix_ptr:
    .4byte  sym_0608A52C              ! ptr to world-space scene matrix
.L_rotated_row_buf:
    .4byte  sym_0602AF1C              ! rotated matrix row buffer (3 longwords)
.L_skip_matrix_mul:
    ! -- Process child node 0 --
    mov.w @(16, r8), r0           ! r0 = node[i].child_id_0
    mov.l   .L_stage_child_1, r7  ! r7 = continuation addr (sym_0602AC9E)
    bsr     .L_cache_lookup       ! check cache for child_0 transform
    mov r0, r9                    ! delay slot: r9 = child_id_0
    mov.l r3, @r5                 ! store Z result at output ptr
    bsr     .L_depth_scale_store  ! perspective scale + screen clip test
    add #0x4, r5                  ! delay slot: advance output ptr

    .global sym_0602AC9E
sym_0602AC9E:
    ! -- Process child node 1 --
    mov.w @(18, r8), r0           ! r0 = node[i].child_id_1 (halfword at +0x12)
    mov.l   .L_stage_child_2, r7  ! r7 = continuation addr (sym_0602ACB0)
    bsr     .L_cache_lookup       ! check cache for child_1 transform
    mov r0, r9                    ! delay slot: r9 = child_id_1
    bsr     .L_view_transform     ! transform child_1 position
    nop
    mov.l r3, @r5                 ! store Z result at output ptr
    bsr     .L_depth_scale_store  ! perspective scale + screen clip test
    add #0x4, r5                  ! delay slot: advance output ptr

    .global sym_0602ACB0
sym_0602ACB0:
    ! -- Process child node 2 --
    mov.w @(20, r8), r0           ! r0 = node[i].child_id_2 (halfword at +0x14)
    mov.l   .L_stage_child_3, r7  ! r7 = continuation addr (sym_0602ACC2)
    bsr     .L_cache_lookup       ! check cache for child_2 transform
    mov r0, r9                    ! delay slot: r9 = child_id_2
    bsr     .L_view_transform     ! transform child_2 position
    nop
    mov.l r3, @r5                 ! store Z result at output ptr
    bsr     .L_depth_scale_store  ! perspective scale + screen clip test
    add #0x4, r5                  ! delay slot: advance output ptr

    .global sym_0602ACC2
sym_0602ACC2:
    ! -- Process child node 3 --
    mov.w @(22, r8), r0           ! r0 = node[i].child_id_3 (halfword at +0x16)
    mov.l   .L_stage_frustum, r7  ! r7 = continuation addr (sym_0602ACD4 -- frustum test)
    bsr     .L_cache_lookup       ! check cache for child_3 transform
    mov r0, r9                    ! delay slot: r9 = child_id_3
    bsr     .L_view_transform     ! transform child_3 position
    nop
    mov.l r3, @r5                 ! store Z result at output ptr
    bsr     .L_depth_scale_store  ! perspective scale + screen clip test
    add #0x4, r5                  ! delay slot: advance output ptr

    .global sym_0602ACD4
sym_0602ACD4:
    ! -- All 4 children processed; begin frustum cull --
    mov.l   .L_sort_write_idx_ptr, r0  ! load sort buffer write index ptr
    mov #0x18, r1                 ! sort entry size = 0x18 bytes
    mov.l @r0, r0                 ! r0 = current write index
    mulu.w r0, r1                 ! result = index * 0x18
    mov.l   .L_sort_buf_base, r2  ! r2 = sort buffer base (sym_0608AC20)
    sts macl, r9                  ! r9 = byte offset into sort buffer
    add r2, r9                    ! r9 = address of next sort entry
    add #-0x20, r11               ! r11 -= 0x20: point to start of 4 XY pairs
    mov.w   DAT_0602ad02, r12     ! r12 = near Z clip threshold (0xFF50 = -176)
    mov.l @(0, r11), r0           ! r0 = child_0 clip-space X
    mov.l @(8, r11), r2           ! r2 = child_1 clip-space X
    mov.l @(16, r11), r4          ! r4 = child_2 clip-space X
    mov.l @(24, r11), r6          ! r6 = child_3 clip-space X
    cmp/gt r0, r12                ! is near_Z > child_0.x?
    bf      .L_z_not_all_behind   ! if not, at least one vertex in front
    cmp/gt r2, r12                ! is near_Z > child_1.x?
    bf      .L_z_not_all_behind
    cmp/gt r4, r12                ! is near_Z > child_2.x?
    bf      .L_z_not_all_behind
    cmp/gt r6, r12                ! is near_Z > child_3.x?
    bf      .L_z_not_all_behind
    bra     .L_next_node          ! all behind near plane -- cull entire node
    nop

    .global DAT_0602ad02
DAT_0602ad02:
    .2byte  0xFF50                    ! near Z clip threshold (-176 signed)
.L_stage_child_1:
    .4byte  sym_0602AC9E              ! continuation: process child 1
.L_stage_child_2:
    .4byte  sym_0602ACB0              ! continuation: process child 2
.L_stage_child_3:
    .4byte  sym_0602ACC2              ! continuation: process child 3
.L_stage_frustum:
    .4byte  sym_0602ACD4              ! continuation: frustum cull stage
.L_sort_write_idx_ptr:
    .4byte  sym_060620D4              ! sort buffer write index
.L_sort_buf_base:
    .4byte  sym_0608AC20              ! sort buffer base address
.L_z_not_all_behind:
    ! -- Far Z clip test (all 4 children) --
    mov.w   DAT_0602ad96, r12     ! r12 = far Z clip threshold (0x00B0 = +176)
    cmp/gt r0, r12                ! is far_Z > child_0.x?
    bt      .L_z_partly_visible   ! if yes, child_0 is in front of far plane
    cmp/gt r2, r12                ! is far_Z > child_1.x?
    bt      .L_z_partly_visible
    cmp/gt r4, r12                ! is far_Z > child_2.x?
    bt      .L_z_partly_visible
    cmp/gt r6, r12                ! is far_Z > child_3.x?
    bt      .L_next_node          ! all beyond far plane -- cull
.L_z_partly_visible:
    ! -- Y clip test: check if all above screen --
    mov.w   DAT_0602ad98, r12     ! r12 = top Y clip threshold (0xFF81 = -127)
    mov.l @(4, r11), r1           ! r1 = child_0 clip-space Y
    mov.l @(12, r11), r3          ! r3 = child_1 clip-space Y
    mov.l @(20, r11), r5          ! r5 = child_2 clip-space Y
    mov.l @(28, r11), r7          ! r7 = child_3 clip-space Y
    cmp/gt r1, r12                ! is top_Y > child_0.y?
    bf      .L_y_not_all_above    ! if not, child_0 is below top edge
    cmp/gt r3, r12                ! is top_Y > child_1.y?
    bf      .L_y_not_all_above
    cmp/gt r5, r12                ! is top_Y > child_2.y?
    bf      .L_y_not_all_above
    cmp/gt r7, r12                ! is top_Y > child_3.y?
    bt      .L_next_node          ! all above screen top -- cull
.L_y_not_all_above:
    ! -- Y clip test: check if all below screen --
    mov.w   DAT_0602ad9a, r12     ! r12 = bottom Y clip threshold (0x0051 = +81)
    cmp/gt r1, r12                ! is bottom_Y > child_0.y?
    bt      .L_y_partly_visible   ! if yes, child_0 is above bottom edge
    cmp/gt r3, r12                ! is bottom_Y > child_1.y?
    bt      .L_y_partly_visible
    cmp/gt r5, r12                ! is bottom_Y > child_2.y?
    bt      .L_y_partly_visible
    cmp/gt r7, r12                ! is bottom_Y > child_3.y?
    bf      .L_next_node          ! all below screen bottom -- cull
.L_y_partly_visible:
    ! -- Node passed frustum; write sort buffer entry --
    mov r9, r12                   ! r12 = sort entry base
    add #0x18, r12                ! point past end of entry (write backwards)
    mov.w r7, @-r12               ! store child_3.y (16-bit, truncated)
    mov.w r6, @-r12               ! store child_3.x
    mov.w r5, @-r12               ! store child_2.y
    mov.w r4, @-r12               ! store child_2.x
    mov.w r3, @-r12               ! store child_1.y
    mov.w r2, @-r12               ! store child_1.x
    mov.w r1, @-r12               ! store child_0.y
    mov.w r0, @-r12               ! store child_0.x
    mov.w @(14, r8), r0           ! r0 = node[i].texture_id (halfword at +0xE)
    mov.w r0, @(6, r9)            ! sort_entry.texture_id = r0
    mov.w @(12, r8), r0           ! r0 = node[i].flags
    shlr2 r0                      ! shift right by 4 total (extract bits 4-7)
    shlr2 r0                      !   ...continued
    and #0xF, r0                  ! r0 = (flags >> 4) & 0xF = draw priority
    mov.b r0, @(4, r9)            ! sort_entry.priority = draw priority
    mov r13, r0                   ! r0 = node_group_id
    mov.b r0, @(5, r9)            ! sort_entry.group_id = node_group_id
    mov.w @(12, r8), r0           ! r0 = node[i].flags (reload)
    mov.l   .L_sort_jump_table, r1  ! r1 = sort strategy jump table ptr
    and #0x7, r0                  ! r0 = flags & 0x7 = sort strategy index
    shll2 r0                      ! r0 *= 4 (index to offset)
    mov.l @(r0, r1), r2           ! r2 = jump target for sort strategy
    .word 0xC760                  ! mova @(0x180, PC), r0 -- loads scratch XY data addr
    mov.l @r0, r3                 ! r3 = scratch[0] (child_0 depth)
    mov.l @(4, r0), r4            ! r4 = scratch[1] (child_1 depth)
    mov.l @(8, r0), r5            ! r5 = scratch[2] (child_2 depth)
    jmp @r2                       ! jump to sort strategy handler
    mov.l @(12, r0), r6           ! delay slot: r6 = scratch[3] (child_3 depth)

    .global DAT_0602ad96
DAT_0602ad96:
    .2byte  0x00B0                    ! far Z clip threshold (+176)

    .global DAT_0602ad98
DAT_0602ad98:
    .2byte  0xFF81                    ! top Y clip threshold (-127)

    .global DAT_0602ad9a
DAT_0602ad9a:
    .2byte  0x0051                    ! bottom Y clip threshold (+81)
.L_sort_jump_table:
    .4byte  sym_0602AF28              ! sort strategy jump table (5 entries)

    .global loc_0602ADA0
loc_0602ADA0:
    ! -- Sort strategy 0: average depth (sum of 4, >> 2) --
    add r4, r3                    ! r3 += child_1 depth
    add r5, r6                    ! r6 = child_2 + child_3
    add r6, r3                    ! r3 = sum of all 4 depths
    bra     .L_store_sort_key     ! go store sort key
    shlr2 r3                      ! delay slot: r3 >>= 2 (average)

    .global loc_0602ADAA
loc_0602ADAA:
    ! -- Sort strategy 1: minimum depth (cmp/ge -- nearest face) --
    cmp/ge r3, r4                 ! is r4 >= r3? (r4 not smaller)
    bt      .L_min_skip_r4        ! if so, keep r3
    mov r4, r3                    ! r4 < r3, so r3 = r4 (new minimum)
.L_min_skip_r4:
    cmp/ge r3, r5                 ! is r5 >= r3?
    bt      .L_min_skip_r5        ! if so, keep r3
    mov r5, r3                    ! r5 < r3, so r3 = r5
.L_min_skip_r5:
    cmp/ge r3, r6                 ! is r6 >= r3?
    bt      .L_min_done           ! if so, keep r3
    mov r6, r3                    ! r6 < r3, so r3 = r6
.L_min_done:
    bra     .L_store_sort_key     ! go store sort key
    nop

    .global loc_0602ADC0
loc_0602ADC0:
    ! -- Sort strategy 2: maximum depth + 0 bias --
    bra     .L_bias_max_loop      ! go to biased max loop
    mov #0x0, r0                  ! delay slot: r0 = 0 (no bias)

    .global loc_0602ADC4
loc_0602ADC4:
    ! -- Sort strategy 3: max depth + 0x10000 (1.0 fixed-point bias) --
    mov #0x1, r0                  ! r0 = 1
    bra     .L_bias_max_loop      ! go to biased max loop
    shll16 r0                     ! delay slot: r0 = 0x10000 (1.0 in 16.16)

    .global loc_0602ADCA
loc_0602ADCA:
    ! -- Sort strategy 4: max depth + 0x000B8000 (large bias) --
    mov.l   .L_large_depth_bias, r0  ! r0 = 0x000B8000 (11.5 in 16.16)
.L_bias_max_loop:
    cmp/gt r3, r4                 ! is r4 > r3?
    bf      .L_bias_skip_r4       ! if not, keep r3
    mov r4, r3                    ! r4 > r3, so r3 = r4
.L_bias_skip_r4:
    cmp/gt r3, r5                 ! is r5 > r3?
    bf      .L_bias_skip_r5       ! if not, keep r3
    mov r5, r3                    ! r5 > r3, so r3 = r5
.L_bias_skip_r5:
    cmp/gt r3, r6                 ! is r6 > r3?
    bf      .L_bias_done          ! if not, keep r3
    mov r6, r3                    ! r6 > r3, so r3 = r6
.L_bias_done:
    add r0, r3                    ! r3 += depth bias
.L_store_sort_key:
    ! -- Compute and store final sort key --
    mov.l   .L_sort_idx_ptr, r2   ! r2 = ptr to sort buffer write index
    neg r3, r3                    ! negate depth (farther = larger sort key)
    mov.l   .L_sort_key_array, r1  ! r1 = sort key array base
    shlr8 r3                      ! r3 >>= 12 total (convert to 16-bit key)
    mov.l @r2, r0                 ! r0 = current write index
    shlr2 r3                      !   ...shift right 2 more
    shlr2 r3                      !   ...shift right 2 more (total >>12)
    shll r0                       ! r0 *= 2 (16-bit array index to byte offset)
    mov.w r3, @(r0, r1)           ! sort_key[index] = truncated depth key
    shar r0                       ! r0 /= 2 (restore index)
    add #0x1, r0                  ! increment write index
    mov.l r0, @r2                 ! store updated write index
.L_next_node:
    mov.l @r15+, r7               ! pop remaining node count
    dt r7                         ! decrement, set T if zero
    bt      .L_all_nodes_done     ! if zero, all nodes processed
    bra     .L_node_loop_top      ! else loop to next node
    nop
    .2byte  0x0000                ! alignment padding
.L_large_depth_bias:
    .4byte  0x000B8000                ! 11.5 in 16.16 fixed-point
.L_sort_idx_ptr:
    .4byte  sym_060620D4              ! sort buffer write index
.L_sort_key_array:
    .4byte  sym_0606A4F8              ! sort key output array (16-bit per entry)
.L_all_nodes_done:
    lds.l @r15+, pr               ! restore pr
    mov.l @r15+, r14              ! restore r14
    mov.l @r15+, r13              ! restore r13
    mov.l @r15+, r12              ! restore r12
    mov.l @r15+, r11              ! restore r11
    mov.l @r15+, r10              ! restore r10
    mov.l @r15+, r9               ! restore r9
    rts                           ! return
    mov.l @r15+, r8               ! delay slot: restore r8
    .2byte  0x0009                ! alignment padding (nop encoding)
.L_view_transform:
    ! Transforms a child vertex (int16 x3) through the view matrix.
    ! Input: r9=vertex_id, r14=vertex_data_base, r6=scene_matrix, r10=min_depth
    ! Output: r1=view_X, r2=view_Y, r3=view_Z
    mov #0xC, r0                  ! vertex struct size = 12 bytes
    mul.l r0, r9                  ! r9 * 12 = byte offset into vertex data
    mov #0x18, r7                 ! r7 = 0x18 offset into scene matrix
    add r6, r7                    ! r7 = &scene_matrix[0x18] (translation row)
    sts macl, r4                  ! r4 = vertex byte offset
    add r14, r4                   ! r4 = vertex_data_base + offset
    clrmac                        ! clear MAC for Z dot product
    mac.l @r4+, @r7+             ! Z dot: accumulate vtx[0] * matrix_col0
    mac.l @r4+, @r7+             ! Z dot: accumulate vtx[1] * matrix_col1
    mac.l @r4+, @r7+             ! Z dot: accumulate vtx[2] * matrix_col2
    add #-0xC, r4                ! rewind vertex pointer
    mov.l @(8, r7), r2           ! r2 = matrix translation Z component
    sts mach, r0                 ! r0 = Z dot product high
    sts macl, r3                 ! r3 = Z dot product low
    xtrct r0, r3                 ! r3 = Z result (16.16 fixed-point)
    add r2, r3                   ! r3 += translation Z
    cmp/gt r10, r3               ! is Z > min_depth (r10 from view matrix)?
    bf      .L_next_node          ! if behind camera, skip this node entirely
    mov.w   .L_emit_cache_offset, r2  ! r2 = cache write offset (0xFF00)
    mov.w   .L_emit_init_marker, r0  ! r0 = init marker (0x00A0)
    mov.l r0, @(16, r2)          ! cache_entry.marker = 0x00A0
    mov.l r3, @(0, r2)           ! cache_entry.z = r3
    mov #0x0, r0                 ! r0 = 0
    mov.l r0, @(20, r2)          ! cache_entry.extra = 0
    clrmac                        ! clear MAC for X dot product
    mac.l @r4+, @r6+             ! X dot: accumulate vtx[0] * matrix_col0
    mac.l @r4+, @r6+             ! X dot: accumulate vtx[1] * matrix_col1
    mac.l @r4+, @r6+             ! X dot: accumulate vtx[2] * matrix_col2
    add #-0xC, r4                ! rewind vertex pointer
    mov.l @r7+, r2               ! r2 = matrix translation X component
    sts mach, r0                 ! r0 = X dot product high
    sts macl, r1                 ! r1 = X dot product low
    clrmac                        ! clear MAC for Y dot product
    mac.l @r4+, @r6+             ! Y dot: accumulate vtx[0] * matrix_col0
    xtrct r0, r1                 ! r1 = X result (16.16 fixed-point)
    add r2, r1                   ! r1 += translation X
    mac.l @r4+, @r6+             ! Y dot: accumulate vtx[1] * matrix_col1
    mac.l @r4+, @r6+             ! Y dot: accumulate vtx[2] * matrix_col2
    mov.l @r7+, r7               ! r7 = matrix translation Y component
    add #-0x18, r6               ! rewind scene matrix ptr (2 rows * 12 = 0x18)
    sts mach, r0                 ! r0 = Y dot product high
    sts macl, r2                 ! r2 = Y dot product low
    xtrct r0, r2                 ! r2 = Y result (16.16 fixed-point)
    rts                           ! return (r1=X, r2=Y, r3=Z)
    add r7, r2                   ! delay slot: r2 += translation Y
.L_emit_cache_offset:
    .2byte  0xFF00                    ! cache write offset into scratch buffer
.L_emit_init_marker:
    .2byte  0x00A0                    ! cache initialization marker value
    .2byte  0x0009                    ! alignment padding (nop encoding)
.L_depth_scale_store:
    ! Scales X/Y by perspective Z, clips to screen bounds, stores in scratch buf.
    ! Input: r1=view_X, r2=view_Y, r3=view_Z, r9=vertex_id, r11=scratch ptr, r12=cache ptr
    ! On out-of-range, skips to next node.
    mov.w   DAT_0602aeba, r0     ! r0 = perspective scale base addr (0xFF00)
    mov.l @(28, r0), r4          ! r4 = perspective scale factor (from table at offset 0x1C)
    dmuls.l r1, r4               ! scale X by perspective factor (64-bit result)
    neg r2, r2                   ! negate Y (screen coords are inverted)
    sts mach, r1                 ! r1 = scaled X (high 32 bits of 64-bit product)
    dmuls.l r2, r4               ! scale negated Y by perspective factor
    mov.l r1, @r11               ! store scaled X in scratch buffer
    sts mach, r2                 ! r2 = scaled Y (high 32 bits)
    mov.l r2, @(4, r11)          ! store scaled Y in scratch buffer
    add #0x8, r11                ! advance scratch pointer by 8
    mov.w   DAT_0602aebc, r7     ! r7 = screen clip bound (0x0190 = +400)
    cmp/gt r7, r1                ! is scaled_X > +400?
    bt      .L_next_node          ! if so, off-screen right -- skip
    neg r7, r0                   ! r0 = -400
    cmp/gt r1, r0                ! is -400 > scaled_X?
    bt      .L_next_node          ! if so, off-screen left -- skip
    cmp/gt r2, r0                ! is -400 > scaled_Y?
    bt      .L_next_node          ! if so, off-screen top -- skip
    shlr r7                      ! r7 = 200 (half-height bound)
    cmp/gt r7, r2                ! is scaled_Y > +200?
    bt      .L_next_node          ! if so, off-screen bottom -- skip
    ! -- Node passed clip; write to cache --
    mov.l r9, @r12               ! cache[i].tag = vertex_id
    mov.l r1, @(4, r12)          ! cache[i].scaled_x = r1
    mov.l r2, @(8, r12)          ! cache[i].scaled_y = r2
    mov.l r3, @(12, r12)         ! cache[i].depth_z = r3
    rts                           ! return to caller
    nop

    .global DAT_0602aeba
DAT_0602aeba:
    .2byte  0xFF00                    ! perspective scale table base offset

    .global DAT_0602aebc
DAT_0602aebc:
    .2byte  0x0190                    ! screen clip bound (+400)
.L_cache_lookup:
    ! Checks the 64-entry transform cache for a previously computed result.
    ! Input: r0=vertex_id, r9=expected_id, r7=continuation_addr, r11=scratch_ptr, r5=out_ptr
    ! On hit: copies cached values, jumps to r7. On miss: returns to caller.
    and #0x3F, r0                ! r0 = vertex_id & 0x3F (cache index, 64 entries)
    mov.l   .L_cache_base_lookup, r12  ! r12 = cache base (sym_06094220)
    shll2 r0                      ! r0 *= 16 (cache entry size)
    shll2 r0                      !   ...continued
    add r0, r12                   ! r12 = &cache[vertex_id & 0x3F]
    mov.l @r12, r0                ! r0 = cache[i].tag
    cmp/pz r0                     ! is tag >= 0? (valid entry, not 0xFFFFFFFF)
    bf      .L_cache_miss         ! if negative, entry is invalid -- miss
    cmp/eq r0, r9                 ! does tag match expected vertex_id?
    bf      .L_cache_miss         ! if not, hash collision -- miss
    ! -- Cache hit: copy cached transform and jump to continuation --
    mov.l @(4, r12), r1           ! r1 = cached scaled_x
    mov.l @(8, r12), r2           ! r2 = cached scaled_y
    mov.l @(12, r12), r3          ! r3 = cached depth_z
    mov.l r1, @r11                ! scratch[n].x = scaled_x
    mov.l r2, @(4, r11)           ! scratch[n].y = scaled_y
    add #0x8, r11                 ! advance scratch pointer
    mov.l r3, @r5                 ! output Z value
    jmp @r7                       ! jump to continuation address
    add #0x4, r5                  ! delay slot: advance output pointer
.L_cache_base_lookup:
    .4byte  sym_06094220              ! transform cache (64 x 16-byte entries)
.L_cache_miss:
    rts                           ! return to caller (will compute transform)
    nop

    ! -- BSS-like scratch data (initialized to 0xFFFF at load) --

    .global sym_0602AEEC
sym_0602AEEC:                         ! scratch XY buffer (4 XY pairs = 32 bytes)
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF0C
sym_0602AF0C:                         ! cached XYZ output: X component
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af10
DAT_0602af10:                         ! cached XYZ output: Y component
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af14
DAT_0602af14:                         ! cached XYZ output: Z component
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af18
DAT_0602af18:                         ! (unused padding)
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF1C
sym_0602AF1C:                         ! rotated matrix row result (3 longwords)
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF28
sym_0602AF28:                         ! sort strategy jump table (5 entries)
    .4byte  loc_0602ADA0              ! [0] sort_avg_depth
    .4byte  loc_0602ADAA              ! [1] sort_min_depth
    .4byte  loc_0602ADC0              ! [2] sort_zero_bias
    .4byte  loc_0602ADC4              ! [3] sort_64k_bias
    .4byte  loc_0602ADCA              ! [4] sort_large_bias

    .global sym_0602AF3C
sym_0602AF3C:                         ! prologue: push callee-saved registers
    mov.l r8, @-r15               ! save r8
    mov.l r9, @-r15               ! save r9
    mov.l r10, @-r15              ! save r10
    mov.l r11, @-r15              ! save r11
    mov.l r12, @-r15              ! save r12
    mov.l r13, @-r15              ! save r13
