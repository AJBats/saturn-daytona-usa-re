/* scene_graph_walk -- Scene Graph Walker / Frustum Culler
 * Translation unit: 0x0602B9EC - 0x0602BDCC
 *
 * Walks the scene graph hierarchy and processes visible nodes for
 * one course's 3D geometry. For each node, performs view-space
 * transform via MAC (multiply-accumulate) dot products against the
 * view matrix, then applies frustum culling on X/Y/Z extents.
 * Visible nodes are written into the sort buffer at sym_0608AC20
 * with a depth sort key for back-to-front rendering.
 *
 * Functions:
 *   scene_graph_walk  -- Main loop: iterates scene nodes in reverse,
 *                        transforms bounding extents, frustum-culls,
 *                        and dispatches sort key computation.
 *   vdp1_cmd_emit     -- Transforms a node's 3x int16 position via
 *                        the 3x3 view matrix, computes Z depth,
 *                        and stores the result in a scratch buffer.
 *
 * Internal subroutines:
 *   cache_lookup       -- Checks the 64-entry transform cache for a
 *                        previously computed node; on hit, copies
 *                        cached values and jumps to the next stage.
 *   depth_clip_test    -- Scales X/Y by perspective Z, clips against
 *                        screen bounds, and early-exits if off-screen.
 *
 * Sort key strategies (jump table at sym_0602BDB8):
 *   sort_avg_depth     -- Average of 4 Z values (>> 2)
 *   sort_min_depth_ge  -- Minimum Z (cmp/ge, nearest face)
 *   sort_max_depth_gt  -- Maximum Z (cmp/gt, farthest face)
 *   sort_max_plus_64k  -- Maximum Z + 0x10000 (1.0 fixed-point bias)
 *   sort_max_plus_biased -- Maximum Z + 0x000B8000 (large bias)
 *
 * Data (BSS-like, initialized to 0xFFFF at runtime):
 *   sym_0602BD6C  -- Scratch transform cache (16 words)
 *   sym_0602BD8C  -- Cached X/Y/Z output triplet
 *   sym_0602BD9C  -- Rotated matrix row result (3 words)
 *   sym_0602BDA8  -- VDP1 cmd emit scratch (3 words)
 *   sym_0602BDB4  -- Current Z accumulator
 *   sym_0602BDB8  -- Sort strategy jump table (5 entries)
 *
 * Key external symbols:
 *   sym_06094AE4  -- Transform cache array (64 x 16 bytes)
 *   sym_06063F08  -- Pointer to current view matrix (3x3 + translation)
 *   sym_0608A52C  -- Pointer to world-space scene matrix
 *   sym_0608AC20  -- Sort buffer base (node entries, 0x18 bytes each)
 *   sym_060620D4  -- Sort buffer write index
 *   sym_0606A4F8  -- Sort key output array (16-bit per entry)
 *   sym_06063F54  -- Scene depth parameter (for bias decision)
 */

    .section .text.FUN_0602B9EC


    .global scene_graph_walk
    .type scene_graph_walk, @function
scene_graph_walk:
    mov.l r14, @-r15              ! save r14
    sts.l pr, @-r15               ! save pr (+ pushes r8-r13 via prologue convention)
    mov r4, r8                    ! r8 = node_array base pointer
    mov r5, r14                   ! r14 = vertex_data base pointer
    mov r6, r13                   ! r13 = node_group_id
    mov.l   .L_cache_array_base, r12  ! r12 = transform cache base (sym_06094AE4)
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
    mov.l   .L_scratch_xy_buf, r11  ! r11 = scratch XY buffer ptr
    mov.l   .L_cached_xyz_out, r5  ! r5 = cached XYZ output ptr
    mov.l   .L_scene_matrix_ptr, r0  ! load scene matrix pointer address
    mov.l @r0, r6                 ! r6 = scene matrix base (deref)
    mov.w @(16, r8), r0           ! r0 = node[i].child_id_0 (halfword at +0x10)
    extu.w r0, r4                 ! r4 = zero-extended child ID
    bsr     vdp1_cmd_emit         ! transform child_0 position -> (r1,r2,r3)
    mov #0x6, r9                  ! delay slot: r9 = vertex stride (6 bytes)
    mov.l r1, @r5                 ! store transformed X
    mov.l r2, @(4, r5)            ! store transformed Y
    mov.l r3, @(8, r5)            ! store transformed Z
    mov.l   .L_z_accum_ptr, r7    ! r7 = z accumulator ptr
    mov.l r2, @r7                 ! store Y as initial Z accumulator
    mov.w @(12, r8), r0           ! r0 = node[i].flags (halfword at +0xC)
    tst #0x8, r0                  ! test bit 3: has local transform?
    bf      .L_skip_matrix_mul    ! if set, skip matrix multiply
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
    bt      .L_skip_matrix_mul   ! if positive, node faces camera — continue
    bra     .L_next_node          ! else backface cull — skip this node
    nop                           ! delay slot
    .2byte  0x0000                ! alignment padding
.L_cache_array_base:
    .4byte  sym_06094AE4              ! transform cache (64 x 16-byte entries)
.L_view_matrix_ptr:
    .4byte  sym_06063F08              ! ptr to current view matrix
.L_scratch_xy_buf:
    .4byte  sym_0602BD6C              ! scratch XY buffer (16 words)
.L_cached_xyz_out:
    .4byte  sym_0602BD8C              ! cached XYZ output triplet
.L_scene_matrix_ptr:
    .4byte  sym_0608A52C              ! ptr to world-space scene matrix
.L_z_accum_ptr:
    .4byte  sym_0602BDB4              ! Z accumulator (current node)
.L_rotated_row_buf:
    .4byte  sym_0602BD9C              ! rotated matrix row buffer (3 words)
.L_skip_matrix_mul:
    ! -- Process child node 0 --
    mov.w @(16, r8), r0           ! r0 = node[i].child_id_0
    mov.l   .L_stage_child_1, r7  ! r7 = continuation addr (sym_0602BAB6)
    bsr     .L_cache_lookup       ! check cache for child_0 transform
    mov r0, r4                    ! delay slot: r4 = child_id_0
    mov.l r3, @r5                 ! store Z result at output ptr
    add #0x4, r5                  ! advance output ptr
    mov.w @(16, r8), r0           ! reload child_id_0 for clip test
    bsr     .L_depth_clip_test    ! perspective clip test on child_0
    nop                           ! delay slot

    .global sym_0602BAB6
sym_0602BAB6:
    ! -- Process child node 1 --
    mov.w @(18, r8), r0           ! r0 = node[i].child_id_1 (halfword at +0x12)
    mov.l   .L_stage_child_2, r7  ! r7 = continuation addr (sym_0602BACC)
    bsr     .L_cache_lookup       ! check cache for child_1 transform
    mov r0, r4                    ! delay slot: r4 = child_id_1
    bsr     vdp1_cmd_emit         ! transform child_1 position
    mov #0x6, r9                  ! delay slot: r9 = vertex stride
    mov.l r3, @r5                 ! store Z result at output ptr
    add #0x4, r5                  ! advance output ptr
    mov.w @(18, r8), r0           ! reload child_id_1
    bsr     .L_depth_clip_test    ! perspective clip test on child_1
    nop                           ! delay slot

    .global sym_0602BACC
sym_0602BACC:
    ! -- Process child node 2 --
    mov.w @(20, r8), r0           ! r0 = node[i].child_id_2 (halfword at +0x14)
    mov.l   .L_stage_child_3, r7  ! r7 = continuation addr (sym_0602BAE2)
    bsr     .L_cache_lookup       ! check cache for child_2 transform
    mov r0, r4                    ! delay slot: r4 = child_id_2
    bsr     vdp1_cmd_emit         ! transform child_2 position
    mov #0x6, r9                  ! delay slot: r9 = vertex stride
    mov.l r3, @r5                 ! store Z result at output ptr
    add #0x4, r5                  ! advance output ptr
    mov.w @(20, r8), r0           ! reload child_id_2
    bsr     .L_depth_clip_test    ! perspective clip test on child_2
    nop                           ! delay slot

    .global sym_0602BAE2
sym_0602BAE2:
    ! -- Process child node 3 --
    mov.w @(22, r8), r0           ! r0 = node[i].child_id_3 (halfword at +0x16)
    mov.l   .L_stage_frustum, r7  ! r7 = continuation addr (sym_0602BAF8 — frustum test)
    bsr     .L_cache_lookup       ! check cache for child_3 transform
    mov r0, r4                    ! delay slot: r4 = child_id_3
    bsr     vdp1_cmd_emit         ! transform child_3 position
    mov #0x6, r9                  ! delay slot: r9 = vertex stride
    mov.l r3, @r5                 ! store Z result at output ptr
    add #0x4, r5                  ! advance output ptr
    mov.w @(22, r8), r0           ! reload child_id_3
    bsr     .L_depth_clip_test    ! perspective clip test on child_3
    nop                           ! delay slot

    .global sym_0602BAF8
sym_0602BAF8:
    ! -- All 4 children processed; begin frustum cull --
    mov.l   .L_sort_write_idx_ptr, r0  ! load sort buffer write index ptr
    mov #0x18, r1                 ! sort entry size = 0x18 bytes
    mov.l @r0, r0                 ! r0 = current write index
    mulu.w r0, r1                 ! result = index * 0x18
    mov.l   .L_sort_buf_base, r2  ! r2 = sort buffer base (sym_0608AC20)
    sts macl, r9                  ! r9 = byte offset into sort buffer
    add r2, r9                    ! r9 = address of next sort entry
    add #-0x20, r11               ! r11 -= 0x20: point to start of 4 XY pairs
    mov.w   DAT_0602bb26, r12     ! r12 = near Z clip threshold (0xFF50 = -176)
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
    bra     .L_next_node          ! all behind near plane — cull entire node
    nop                           ! delay slot

    .global DAT_0602bb26
DAT_0602bb26:
    .2byte  0xFF50                    ! near Z clip threshold (-176 signed)
.L_stage_child_1:
    .4byte  sym_0602BAB6              ! continuation: process child 1
.L_stage_child_2:
    .4byte  sym_0602BACC              ! continuation: process child 2
.L_stage_child_3:
    .4byte  sym_0602BAE2              ! continuation: process child 3
.L_stage_frustum:
    .4byte  sym_0602BAF8              ! continuation: frustum cull stage
.L_sort_write_idx_ptr:
    .4byte  sym_060620D4              ! sort buffer write index
.L_sort_buf_base:
    .4byte  sym_0608AC20              ! sort buffer base address
.L_z_not_all_behind:
    ! -- Far Z clip test (all 4 children) --
    mov.w   DAT_0602bbba, r12     ! r12 = far Z clip threshold (0x00B0 = +176)
    cmp/gt r0, r12                ! is far_Z > child_0.x?
    bt      .L_z_partly_visible   ! if yes, child_0 is in front of far plane
    cmp/gt r2, r12                ! is far_Z > child_1.x?
    bt      .L_z_partly_visible
    cmp/gt r4, r12                ! is far_Z > child_2.x?
    bt      .L_z_partly_visible
    cmp/gt r6, r12                ! is far_Z > child_3.x?
    bt      .L_next_node          ! all beyond far plane — cull
.L_z_partly_visible:
    ! -- Y clip test: check if all above screen --
    mov.w   DAT_0602bbbc, r12     ! r12 = top Y clip threshold (0xFF81 = -127)
    mov.l @(4, r11), r1           ! r1 = child_0 clip-space Y
    mov.l @(12, r11), r3          ! r3 = child_1 clip-space Y
    mov.l @(20, r11), r5          ! r5 = child_2 clip-space Y
    mov.l @(28, r11), r7          ! r7 = child_3 clip-space Y
    cmp/gt r1, r12                ! is top_Y > child_0.y?
    bf      .L_y_not_all_below    ! if not, child_0 is below top edge
    cmp/gt r3, r12                ! is top_Y > child_1.y?
    bf      .L_y_not_all_below
    cmp/gt r5, r12                ! is top_Y > child_2.y?
    bf      .L_y_not_all_below
    cmp/gt r7, r12                ! is top_Y > child_3.y?
    bt      .L_next_node          ! all above screen top — cull
.L_y_not_all_below:
    ! -- Y clip test: check if all below screen --
    mov.w   DAT_0602bbbe, r12     ! r12 = bottom Y clip threshold (0x0051 = +81)
    cmp/gt r1, r12                ! is bottom_Y > child_0.y?
    bt      .L_y_partly_visible   ! if yes, child_0 is above bottom edge
    cmp/gt r3, r12                ! is bottom_Y > child_1.y?
    bt      .L_y_partly_visible
    cmp/gt r5, r12                ! is bottom_Y > child_2.y?
    bt      .L_y_partly_visible
    cmp/gt r7, r12                ! is bottom_Y > child_3.y?
    bf      .L_next_node          ! all below screen bottom — cull
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
    .word 0xC777                  ! mova @(0x1DC, PC), r0 — loads scratch XY data addr
    mov.l @r0, r3                 ! r3 = scratch[0] (child_0 depth)
    mov.l @(4, r0), r4            ! r4 = scratch[1] (child_1 depth)
    mov.l @(8, r0), r5            ! r5 = scratch[2] (child_2 depth)
    jmp @r2                       ! jump to sort strategy handler
    mov.l @(12, r0), r6           ! delay slot: r6 = scratch[3] (child_3 depth)

    .global DAT_0602bbba
DAT_0602bbba:
    .2byte  0x00B0                    ! far Z clip threshold (+176)

    .global DAT_0602bbbc
DAT_0602bbbc:
    .2byte  0xFF81                    ! top Y clip threshold (-127)

    .global DAT_0602bbbe
DAT_0602bbbe:
    .2byte  0x0051                    ! bottom Y clip threshold (+81)
.L_sort_jump_table:
    .4byte  sym_0602BDB8              ! sort strategy jump table (5 entries)

    .global loc_0602BBC4
loc_0602BBC4:
    ! -- Sort strategy 0: average depth (sum of 4, >> 2) --
    add r4, r3                    ! r3 += child_1 depth
    add r5, r6                    ! r6 = child_2 + child_3
    add r6, r3                    ! r3 = sum of all 4 depths
    bra     .L_store_sort_key     ! go store sort key
    shlr2 r3                      ! delay slot: r3 >>= 2 (average)

    .global loc_0602BBCE
loc_0602BBCE:
    ! -- Sort strategy 1: minimum depth (cmp/ge — nearest face) --
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
    nop                           ! delay slot

    .global loc_0602BBE4
loc_0602BBE4:
    ! -- Sort strategy 2: maximum depth (cmp/gt — farthest face) --
    cmp/gt r3, r4                 ! is r4 > r3?
    bf      .L_max_skip_r4        ! if not, keep r3
    mov r4, r3                    ! r4 > r3, so r3 = r4 (new maximum)
.L_max_skip_r4:
    cmp/gt r3, r5                 ! is r5 > r3?
    bf      .L_max_skip_r5        ! if not, keep r3
    mov r5, r3                    ! r5 > r3, so r3 = r5
.L_max_skip_r5:
    cmp/gt r3, r6                 ! is r6 > r3?
    bf      .L_max_done           ! if not, keep r3
    mov r6, r3                    ! r6 > r3, so r3 = r6
.L_max_done:
    bra     .L_store_sort_key     ! go store sort key
    nop                           ! delay slot

    .global loc_0602BBFA
loc_0602BBFA:
    ! -- Sort strategy 3: max depth + 0x10000 (1.0 fixed-point bias) --
    mov #0x1, r0                  ! r0 = 1
    bra     .L_bias_max_loop      ! go to biased max loop
    shll16 r0                     ! delay slot: r0 = 0x10000 (1.0 in 16.16)

    .global loc_0602BC00
loc_0602BC00:
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
    mov.l   .L_z_accum_val_ptr, r1  ! r1 = ptr to Z accumulator value
    mov.l @r1, r1                 ! r1 = Z accumulator value
    mov.l   .L_scene_depth_param, r0  ! r0 = ptr to scene depth param
    mov.l @r0, r0                 ! r0 = scene depth param value
    mov.l   .L_fp_two, r2         ! r2 = 2.0 (16.16 fixed-point)
    add r2, r1                    ! r1 = z_accum + 2.0
    cmp/gt r1, r0                 ! is scene_depth > (z_accum + 2.0)?
    bf      .L_no_depth_bias      ! if not, skip bias
    mov.l   .L_depth_bias_10, r2  ! r2 = 0x000A0000 (10.0 in 16.16)
    add r2, r3                    ! add 10.0 depth bias to sort key
.L_no_depth_bias:
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
    nop                           ! delay slot
.L_large_depth_bias:
    .4byte  0x000B8000                ! 11.5 in 16.16 fixed-point
.L_z_accum_val_ptr:
    .4byte  sym_0602BDB4              ! Z accumulator value
.L_scene_depth_param:
    .4byte  sym_06063F54              ! scene depth parameter
.L_fp_two:
    .4byte  0x00020000                ! 2.0 in 16.16 fixed-point
.L_depth_bias_10:
    .4byte  0x000A0000                ! 10.0 in 16.16 fixed-point
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

    .global vdp1_cmd_emit
    .type vdp1_cmd_emit, @function
vdp1_cmd_emit:
    ! Transforms a node's 3x int16 position through the 3x3 view matrix.
    ! Input: r4=node_id, r9=stride(6), r14=vertex_data_base, r6=scene_matrix
    ! Output: r1=view_X, r2=view_Y, r3=view_Z
    mul.l r9, r4                  ! r4 * 6 = byte offset into vertex data
    mov.l   .L_emit_scratch, r4   ! r4 = scratch buffer (sym_0602BDA8)
    sts macl, r0                  ! r0 = vertex byte offset
    add r14, r0                   ! r0 = vertex_data_base + offset
    mov.w @r0+, r1                ! r1 = vertex X (int16)
    mov.w @r0+, r2                ! r2 = vertex Y (int16)
    mov.w @r0+, r3                ! r3 = vertex Z (int16)
    shll8 r1                      ! r1 <<= 11 (scale int16 to 16.16)
    shll2 r1                      !   ...continued
    shll r1                       !   ...total <<11
    mov.l r1, @r4                 ! scratch[0] = scaled X
    shll8 r2                      ! r2 <<= 11
    shll2 r2                      !   ...continued
    shll r2                       !   ...total <<11
    mov.l r2, @(4, r4)            ! scratch[1] = scaled Y
    shll8 r3                      ! r3 <<= 11
    shll2 r3                      !   ...continued
    shll r3                       !   ...total <<11
    mov.l r3, @(8, r4)            ! scratch[2] = scaled Z
    mov #0x18, r7                 ! r7 = 0x18 offset into scene matrix
    add r6, r7                    ! r7 = &scene_matrix[0x18] (translation row)
    clrmac                        ! clear MAC for Z dot product
    mac.l @r4+, @r7+             ! Z dot: accumulate X * matrix_col0
    mac.l @r4+, @r7+             ! Z dot: accumulate Y * matrix_col1
    mac.l @r4+, @r7+             ! Z dot: accumulate Z * matrix_col2
    add #-0xC, r4                ! rewind scratch pointer
    mov.l @(8, r7), r9           ! r9 = matrix translation Z component
    sts mach, r0                 ! r0 = Z dot product high
    sts macl, r3                 ! r3 = Z dot product low
    xtrct r0, r3                 ! r3 = Z result (16.16 fixed-point)
    add r9, r3                   ! r3 += translation Z
    cmp/gt r10, r3               ! is Z > min_depth (r10 from view matrix)?
    bf      .L_next_node          ! if behind camera, skip this node entirely
    mov.w   .L_emit_cache_offset, r9  ! r9 = cache write offset (0xFF00)
    mov.w   .L_emit_z_threshold, r0   ! r0 = Z threshold marker (0x00A0 = 160)
    mov.l r0, @(16, r9)          ! cache[offset+16] = Z threshold
    mov.l r3, @(0, r9)           ! cache[offset+0] = computed Z
    mov #0x0, r0                 ! r0 = 0
    mov.l r0, @(20, r9)          ! cache[offset+20] = 0 (clear padding)
    clrmac                        ! clear MAC for X dot product
    mac.l @r4+, @r6+             ! X dot: accumulate X * matrix_col0
    mac.l @r4+, @r6+             ! X dot: accumulate Y * matrix_col1
    mac.l @r4+, @r6+             ! X dot: accumulate Z * matrix_col2
    add #-0xC, r4                ! rewind scratch pointer
    mov.l @r7+, r9               ! r9 = matrix translation X component
    sts mach, r0                 ! r0 = X dot product high
    sts macl, r1                 ! r1 = X dot product low
    clrmac                        ! clear MAC for Y dot product
    mac.l @r4+, @r6+             ! Y dot: start accumulate
    xtrct r0, r1                 ! r1 = X result (16.16 fixed-point)
    add r9, r1                   ! r1 += translation X
    mac.l @r4+, @r6+             ! Y dot: accumulate
    mac.l @r4+, @r6+             ! Y dot: accumulate
    mov.l @r7+, r9               ! r9 = matrix translation Y component
    sts mach, r0                 ! r0 = Y dot product high
    sts macl, r2                 ! r2 = Y dot product low
    xtrct r0, r2                 ! r2 = Y result (16.16 fixed-point)
    add r9, r2                   ! r2 += translation Y
    rts                           ! return (r1=X, r2=Y, r3=Z)
    add #-0x18, r6               ! delay slot: rewind scene matrix pointer
.L_emit_cache_offset:
    .2byte  0xFF00                    ! cache write offset (-256 signed)
.L_emit_z_threshold:
    .2byte  0x00A0                    ! Z threshold marker (160)
    .2byte  0x0000                    ! alignment padding
.L_emit_scratch:
    .4byte  sym_0602BDA8              ! scratch buffer for scaled vertex data
.L_depth_clip_test:
    ! Perspective-scale X/Y by Z, then clip against screen bounds.
    ! Input: r1=view_X, r2=view_Y, r0=node_id, r3=view_Z
    ! Writes clip-space XY to scratch buffer; stores to cache on pass.
    mov.w   .L_clip_cache_offset, r9  ! r9 = cache offset (0xFF00)
    mov.l @(28, r9), r7           ! r7 = perspective scale factor (1/Z)
    dmuls.l r1, r7                ! 64-bit: X * perspective_scale
    neg r2, r2                    ! negate Y (screen Y is inverted)
    sts mach, r1                  ! r1 = clip-space X (high 32 bits)
    dmuls.l r2, r7                ! 64-bit: -Y * perspective_scale
    mov.l r1, @r11                ! store clip X to scratch buffer
    sts mach, r2                  ! r2 = clip-space Y (high 32 bits)
    mov.l r2, @(4, r11)           ! store clip Y to scratch buffer
    add #0x8, r11                 ! advance scratch pointer (8 bytes per child)
    mov.w   DAT_0602bd36, r7      ! r7 = right screen bound (0x0190 = +400)
    cmp/gt r7, r1                 ! is clip_X > right bound?
    bt      .L_next_node          ! if so, off-screen right — cull
    mov.w   DAT_0602bd38, r7      ! r7 = left screen bound (0xFE70 = -400)
    cmp/gt r1, r7                 ! is left_bound > clip_X?
    bt      .L_next_node          ! if so, off-screen left — cull
    mov.w   DAT_0602bd3a, r7      ! r7 = upper screen bound (0x00C8 = +200)
    cmp/gt r7, r2                 ! is clip_Y > upper bound?
    bt      .L_next_node          ! if so, off-screen top — cull
    mov.w   DAT_0602bd38, r7      ! r7 = lower screen bound (0xFE70 = -400)
    cmp/gt r2, r7                 ! is lower_bound > clip_Y?
    bt      .L_next_node          ! if so, off-screen bottom — cull
    ! -- Passed all clip tests; write to transform cache --
    mov.l r0, @r12                ! cache[slot].tag = node_id
    mov.l r1, @(4, r12)           ! cache[slot].clip_x = r1
    mov.l r2, @(8, r12)           ! cache[slot].clip_y = r2
    mov.l r3, @(12, r12)          ! cache[slot].view_z = r3
    rts                           ! return (node passes clip)
    nop                           ! delay slot
.L_clip_cache_offset:
    .2byte  0xFF00                    ! cache offset (-256 signed)

    .global DAT_0602bd36
DAT_0602bd36:
    .2byte  0x0190                    ! right screen clip bound (+400)

    .global DAT_0602bd38
DAT_0602bd38:
    .2byte  0xFE70                    ! left/bottom screen clip bound (-400)

    .global DAT_0602bd3a
DAT_0602bd3a:
    .2byte  0x00C8                    ! upper screen clip bound (+200)
.L_cache_lookup:
    ! Check transform cache for previously computed node.
    ! Input: r0=node_id, r4=expected_tag, r7=continuation_addr
    ! On hit: copies cached values to output buffers and jumps to r7.
    ! On miss: returns to caller (who will compute the transform).
    and #0x3F, r0                 ! r0 = node_id & 0x3F (cache slot, 64 entries)
    mov.l   .L_cache_base_lookup, r12  ! r12 = cache array base
    shll2 r0                      ! r0 *= 16 (each cache entry is 16 bytes)
    shll2 r0                      !   ...continued (4*4 = 16)
    add r0, r12                   ! r12 = &cache[slot]
    mov.l @r12, r0                ! r0 = cache[slot].tag
    cmp/pz r0                    ! is tag >= 0? (valid entry)
    bf      .L_cache_miss         ! if negative (0xFFFFFFFF), slot is empty
    cmp/eq r0, r4                ! does tag match expected node_id?
    bf      .L_cache_miss         ! if not, cache miss
    ! -- Cache hit: copy cached transform values --
    mov.l @(4, r12), r1           ! r1 = cached clip_x
    mov.l @(8, r12), r2           ! r2 = cached clip_y
    mov.l @(12, r12), r3          ! r3 = cached view_z
    mov.l r1, @r11                ! write clip_x to scratch buffer
    mov.l r2, @(4, r11)           ! write clip_y to scratch buffer
    add #0x8, r11                 ! advance scratch pointer
    mov.l r3, @r5                 ! write view_z to output buffer
    jmp @r7                       ! jump to continuation (next child stage)
    add #0x4, r5                  ! delay slot: advance output pointer
    .2byte  0x0000                ! alignment padding
.L_cache_base_lookup:
    .4byte  sym_06094AE4              ! transform cache array base
.L_cache_miss:
    rts                           ! return to caller (cache miss)
    nop                           ! delay slot

    ! =========================================================================
    ! Data Section — scratch buffers and jump table
    ! All 0xFFFF words are BSS-like: overwritten at runtime before use.
    ! =========================================================================

    .global sym_0602BD6C
sym_0602BD6C:
    ! Scratch XY buffer — 4 children x (clip_x, clip_y) = 8 longs = 16 words
    .word 0xFFFF                  ! child_0 clip_x high
    .word 0xFFFF                  ! child_0 clip_x low
    .word 0xFFFF                  ! child_0 clip_y high
    .word 0xFFFF                  ! child_0 clip_y low
    .word 0xFFFF                  ! child_1 clip_x high
    .word 0xFFFF                  ! child_1 clip_x low
    .word 0xFFFF                  ! child_1 clip_y high
    .word 0xFFFF                  ! child_1 clip_y low
    .word 0xFFFF                  ! child_2 clip_x high
    .word 0xFFFF                  ! child_2 clip_x low
    .word 0xFFFF                  ! child_2 clip_y high
    .word 0xFFFF                  ! child_2 clip_y low
    .word 0xFFFF                  ! child_3 clip_x high
    .word 0xFFFF                  ! child_3 clip_x low
    .word 0xFFFF                  ! child_3 clip_y high
    .word 0xFFFF                  ! child_3 clip_y low

    .global sym_0602BD8C
sym_0602BD8C:
    ! Cached XYZ output — transformed X, Y, Z from vdp1_cmd_emit
    .word 0xFFFF                  ! cached X high
    .word 0xFFFF                  ! cached X low

    .global DAT_0602bd90
DAT_0602bd90:
    .word 0xFFFF                  ! cached Y high
    .word 0xFFFF                  ! cached Y low

    .global DAT_0602bd94
DAT_0602bd94:
    .word 0xFFFF                  ! cached Z high
    .word 0xFFFF                  ! cached Z low

    .global DAT_0602bd98
DAT_0602bd98:
    .word 0xFFFF                  ! (padding / overflow)
    .word 0xFFFF

    .global sym_0602BD9C
sym_0602BD9C:
    ! Rotated matrix row results — 3 x 32-bit dot products
    .word 0xFFFF                  ! row[0] high
    .word 0xFFFF                  ! row[0] low
    .word 0xFFFF                  ! row[1] high
    .word 0xFFFF                  ! row[1] low
    .word 0xFFFF                  ! row[2] high
    .word 0xFFFF                  ! row[2] low

    .global sym_0602BDA8
sym_0602BDA8:
    ! VDP1 cmd emit scratch — scaled vertex X/Y/Z (3 x 32-bit)
    .word 0xFFFF                  ! scaled X high
    .word 0xFFFF                  ! scaled X low
    .word 0xFFFF                  ! scaled Y high
    .word 0xFFFF                  ! scaled Y low
    .word 0xFFFF                  ! scaled Z high
    .word 0xFFFF                  ! scaled Z low

    .global sym_0602BDB4
sym_0602BDB4:
    ! Z accumulator — current node's Y/Z depth value
    .word 0xFFFF                  ! Z accum high
    .word 0xFFFF                  ! Z accum low

    .global sym_0602BDB8
sym_0602BDB8:
    ! Sort strategy jump table — 5 entries indexed by (flags & 0x7)
    .4byte  loc_0602BBC4              ! [0] sort_avg_depth
    .4byte  loc_0602BBCE              ! [1] sort_min_depth_ge
    .4byte  loc_0602BBE4              ! [2] sort_max_depth_gt
    .4byte  loc_0602BBFA              ! [3] sort_max_plus_64k
    .4byte  loc_0602BC00              ! [4] sort_max_plus_biased
