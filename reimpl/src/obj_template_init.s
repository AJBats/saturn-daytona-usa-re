/* obj_template_init -- Initialize object template descriptor table
 *
 * Populates an array of 12-byte object template entries at sym_06063690.
 * Each entry describes a tile-grid object with:
 *   +0x00: .4byte  pointer to palette/tile index data
 *   +0x04: .2byte  display mode flags (VDP1 draw mode)
 *   +0x06: .byte   width  (tile columns)
 *   +0x07: .byte   height (tile rows)
 *   +0x08: .byte   stride = width * height * 2  (total tile data size)
 *   +0x09: .byte   depth  (z-layer count)
 *   +0x0A: .2byte  offset = (0x40 - width * depth) * 2  (VRAM row offset)
 *
 * 13 templates are written (indices 0-12), covering car body panels,
 * wheel assemblies, shadow sprites, and track-side scenery objects.
 *
 * Register plan (persistent across all templates):
 *   r4  = 1 (constant: width=1 or height=1 or depth=1)
 *   r5  = 2 (constant: width=2 or height=2 or depth=2)
 *   r6  = next template index (incremented after each)
 *   r7  = base address of template table (sym_06063690)
 *   r11 = 3 (constant: height=3 or depth=3, loaded at template 2)
 *   r13 = current entry pointer (recomputed per template)
 *   r14 = 0 (constant: depth=0 for shadow/flat templates)
 *   r1  = draw mode 0x1080 (loaded at template 2, reused through template 10)
 *   r15 scratch slot = cached tile data pointer for reuse
 *
 * Called once during engine_init_global startup sequence.
 * Translation unit: 0x06004670 - 0x06004A98
 */

    .section .text.FUN_06004670


    .global obj_template_init
    .type obj_template_init, @function
obj_template_init:
    mov.l r14, @-r15                  ! save r14
    mov #0x0, r14                     ! r14 = 0 (constant: depth=0 / zero)
    mov.l r13, @-r15                  ! save r13
    mov r14, r6                       ! r6 = 0 (starting template index)
    mov r14, r3                       ! r3 = 0
    mov r14, r13                      ! r13 = 0
    mov.l r11, @-r15                  ! save r11
    add #0x1, r6                      ! r6 = 1 (next index after template 0)
    shll2 r3                          ! r3 = idx * 4
    shll2 r13                         ! r13 = idx * 4
    sts.l macl, @-r15                 ! save macl
    add #-0x4, r15                    ! allocate 4 bytes scratch on stack
    mov.l   _pool_template_table, r7  ! r7 = template table base (sym_06063690)
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12 (= idx*8 + idx*4)
    add r7, r13                       ! r13 = &template[0]
    /* --- template 0: w=1, h=2, d=1, mode=0x2080 --- */
    mov.l   _pool_tile_data_0, r2     ! r2 = tile data pointer for template 0
    mov.l r2, @r15                    ! cache tile data ptr on stack (reused by template 1)
    mov r2, r3                        ! r3 = tile data ptr (unused copy)
    mov.l r2, @r13                    ! entry[0].tile_ptr = tile_data_0
    mov.w   DAT_060047d2, r0          ! r0 = 0x2080 (draw mode flags)
    mov.w r0, @(4, r13)              ! entry[0].mode = 0x2080
    mov #0x1, r4                      ! r4 = 1 (constant for width/height/depth)
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[0].width = 1
    mov #0x2, r5                      ! r5 = 2 (constant for width/height/depth)
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[0].height = 2
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(9, r13)              ! entry[0].depth = 1
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - width * depth) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[0].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = width * height * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[0].stride = w * h * 2
    /* --- advance to template 1 --- */
    mov r6, r13                       ! r13 = index 1
    add #0x1, r6                      ! r6 = 2 (next index)
    mov r13, r3                       ! r3 = index 1
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[1]
    /* --- template 1: w=1, h=2, d=2, mode=0x2080 (same tile data as 0) --- */
    mov.l @r15, r2                    ! r2 = cached tile_data_0 from stack
    mov.l r2, @r13                    ! entry[1].tile_ptr = tile_data_0
    mov.w   DAT_060047d2, r0          ! r0 = 0x2080 (draw mode flags)
    mov.w r0, @(4, r13)              ! entry[1].mode = 0x2080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[1].width = 1
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[1].height = 2
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(9, r13)              ! entry[1].depth = 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[1].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[1].stride = w * h * 2
    /* --- advance to template 2 --- */
    mov r6, r13                       ! r13 = index 2
    add #0x1, r6                      ! r6 = 3 (next index)
    mov r13, r3                       ! r3 = index 2
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[2]
    /* --- template 2: w=2, h=2, d=3, mode=0x1080 --- */
    mov #0x3, r11                     ! r11 = 3 (constant for height/depth)
    mov.l   _pool_tile_data_2, r2     ! r2 = tile data pointer for template 2
    mov.l r2, @r13                    ! entry[2].tile_ptr = tile_data_2
    mov.w   DAT_060047d4, r1          ! r1 = 0x1080 (draw mode, kept for later templates)
    exts.w r1, r0                     ! sign-extend mode flags
    mov.w r0, @(4, r13)              ! entry[2].mode = 0x1080
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(6, r13)              ! entry[2].width = 2
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[2].height = 2
    exts.b r11, r0                    ! r0 = 3
    mov.b r0, @(9, r13)              ! entry[2].depth = 3
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[2].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[2].stride = w * h * 2
    /* --- advance to template 3 --- */
    mov r6, r13                       ! r13 = index 3
    exts.w r1, r0                     ! r0 = 0x1080 (preload mode for template 3)
    mov.l   _pool_tile_data_3, r2     ! r2 = tile data pointer for template 3
    add #0x1, r6                      ! r6 = 4 (next index)
    mov r13, r3                       ! r3 = index 3
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[3]
    /* --- template 3: w=2, h=2, d=3, mode=0x1080 --- */
    mov.l r2, @r13                    ! entry[3].tile_ptr = tile_data_3
    mov.w r0, @(4, r13)              ! entry[3].mode = 0x1080
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(6, r13)              ! entry[3].width = 2
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[3].height = 2
    exts.b r11, r0                    ! r0 = 3
    mov.b r0, @(9, r13)              ! entry[3].depth = 3
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[3].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[3].stride = w * h * 2
    /* --- advance to template 4 --- */
    mov r6, r13                       ! r13 = index 4
    add #0x1, r6                      ! r6 = 5 (next index)
    mov r13, r3                       ! r3 = index 4
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[4]
    mov.l   _pool_tile_data_4, r2     ! r2 = tile data pointer for template 4
    bra     .L_fill_template_4        ! jump past pool island 1
    nop                               ! delay slot

    .global DAT_060047d2
DAT_060047d2:
    .2byte  0x2080                    ! draw mode: textured, VDP1 mesh off

    .global DAT_060047d4
DAT_060047d4:
    .2byte  0x1080                    ! draw mode: textured, alternate mode
    .2byte  0xFFFF                    ! padding / alignment
_pool_template_table:
    .4byte  sym_06063690              ! base address of template descriptor array
_pool_tile_data_0:
    .4byte  sym_06042CEE              ! tile data for templates 0, 1
_pool_tile_data_2:
    .4byte  sym_06042D72              ! tile data for template 2
_pool_tile_data_3:
    .4byte  sym_06042D1A              ! tile data for template 3
_pool_tile_data_4:
    .4byte  sym_06042DCA              ! tile data for template 4
.L_fill_template_4:
    /* --- template 4: w=2, h=3, d=2, mode=0x1080 --- */
    mov.l r2, @r13                    ! entry[4].tile_ptr = tile_data_4
    exts.w r1, r0                     ! r0 = 0x1080
    mov.w r0, @(4, r13)              ! entry[4].mode = 0x1080
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(6, r13)              ! entry[4].width = 2
    exts.b r11, r0                    ! r0 = 3
    mov.b r0, @(7, r13)              ! entry[4].height = 3
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(9, r13)              ! entry[4].depth = 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[4].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[4].stride = w * h * 2
    /* --- advance to template 5 --- */
    mov r6, r13                       ! r13 = index 5
    add #0x1, r6                      ! r6 = 6 (next index)
    mov r13, r3                       ! r3 = index 5
    mov.l   _pool_tile_data_5, r11    ! r11 = tile data ptr for template 5 (also reused for 9, 11)
    exts.w r1, r0                     ! r0 = 0x1080
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[5]
    /* --- template 5: w=1, h=1, d=2, mode=0x1080 --- */
    mov.l r11, @r13                   ! entry[5].tile_ptr = tile_data_5
    mov.w r0, @(4, r13)              ! entry[5].mode = 0x1080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[5].width = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(7, r13)              ! entry[5].height = 1
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(9, r13)              ! entry[5].depth = 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[5].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[5].stride = w * h * 2
    /* --- advance to template 6 --- */
    mov r6, r13                       ! r13 = index 6
    add #0x1, r6                      ! r6 = 7 (next index)
    mov r13, r3                       ! r3 = index 6
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[6]
    /* --- template 6: w=1, h=1, d=0, mode=0x1080 (flat/shadow) --- */
    mov.l   _pool_tile_data_6, r2     ! r2 = tile data pointer for template 6
    mov.l r2, @r15                    ! cache tile data ptr on stack (reused by template 7)
    mov r2, r3                        ! r3 = tile data ptr (unused copy)
    mov.l r2, @r13                    ! entry[6].tile_ptr = tile_data_6
    exts.w r1, r0                     ! r0 = 0x1080
    mov.w r0, @(4, r13)              ! entry[6].mode = 0x1080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[6].width = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(7, r13)              ! entry[6].height = 1
    exts.b r14, r0                    ! r0 = 0 (r14 = 0)
    mov.b r0, @(9, r13)              ! entry[6].depth = 0
    exts.w r14, r0                    ! r0 = 0
    mov.w r0, @(10, r13)             ! entry[6].offset = 0 (flat: no VRAM row skip)
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[6].stride = w * h * 2
    /* --- advance to template 7 --- */
    mov r6, r13                       ! r13 = index 7
    mov.l @r15, r2                    ! r2 = cached tile_data_6 from stack
    add #0x1, r6                      ! r6 = 8 (next index)
    mov r13, r3                       ! r3 = index 7
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[7]
    /* --- template 7: w=1, h=1, d=0, mode=0x0080 (same tile data as 6) --- */
    mov.l r2, @r13                    ! entry[7].tile_ptr = tile_data_6
    mov.w   DAT_0600498a, r0          ! r0 = 0x0080 (draw mode: untextured)
    mov.w r0, @(4, r13)              ! entry[7].mode = 0x0080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[7].width = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(7, r13)              ! entry[7].height = 1
    exts.b r14, r0                    ! r0 = 0
    mov.b r0, @(9, r13)              ! entry[7].depth = 0
    exts.w r14, r0                    ! r0 = 0
    mov.w r0, @(10, r13)             ! entry[7].offset = 0 (flat)
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[7].stride = w * h * 2
    /* --- advance to template 8 --- */
    mov r6, r13                       ! r13 = index 8
    mov.l   _pool_tile_data_8, r2     ! r2 = tile data pointer for template 8
    add #0x1, r6                      ! r6 = 9 (next index)
    mov r13, r3                       ! r3 = index 8
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[8]
    /* --- template 8: w=2, h=2, d=0x20, mode=0xD116 --- */
    mov.l r2, @r13                    ! entry[8].tile_ptr = tile_data_8
    mov.w   DAT_0600498c, r0          ! r0 = 0xD116 (draw mode: special)
    mov.w r0, @(4, r13)              ! entry[8].mode = 0xD116
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(6, r13)              ! entry[8].width = 2
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[8].height = 2
    mov #0x20, r0                     ! r0 = 32
    mov.b r0, @(9, r13)              ! entry[8].depth = 32 (large z-layer count)
    exts.w r14, r0                    ! r0 = 0
    mov.w r0, @(10, r13)             ! entry[8].offset = 0 (flat)
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[8].stride = w * h * 2
    /* --- advance to template 9 --- */
    mov r6, r13                       ! r13 = index 9
    add #0x1, r6                      ! r6 = 10 (next index)
    mov r13, r3                       ! r3 = index 9
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[9]
    /* --- template 9: w=1, h=1, d=1, mode=0x7080 --- */
    mov.l r11, @r13                   ! entry[9].tile_ptr = tile_data_5 (r11 still holds it)
    mov.w   DAT_0600498e, r0          ! r0 = 0x7080 (draw mode)
    mov.w r0, @(4, r13)              ! entry[9].mode = 0x7080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[9].width = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(7, r13)              ! entry[9].height = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(9, r13)              ! entry[9].depth = 1
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(9, r13), r0              ! r0 = depth
    mov r0, r2                        ! r2 = depth
    muls.w r2, r3                     ! macl = width * depth
    sts macl, r3                      ! r3 = width * depth
    neg r3, r3                        ! r3 = -(width * depth)
    add #0x40, r3                     ! r3 = 0x40 - width * depth
    shll r3                           ! r3 = (0x40 - w*d) * 2
    exts.w r3, r0                     ! sign-extend to word
    mov.w r0, @(10, r13)             ! entry[9].offset = (0x40 - w*d) * 2
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[9].stride = w * h * 2
    /* --- advance to template 10 --- */
    mov r6, r13                       ! r13 = index 10
    add #0x1, r6                      ! r6 = 11 (next index)
    mov r13, r3                       ! r3 = index 10
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[10]
    mov.l   _pool_tile_data_10, r2    ! r2 = tile data pointer for template 10
    mov.l r2, @r13                    ! entry[10].tile_ptr = tile_data_10
    mov.w   DAT_0600498c, r0          ! r0 = 0xD116 (draw mode: special)
    mov.w r0, @(4, r13)              ! entry[10].mode = 0xD116
    bra     .L_fill_template_10       ! jump past pool island 2
    nop                               ! delay slot

    .global DAT_0600498a
DAT_0600498a:
    .2byte  0x0080                    ! draw mode: untextured sprite

    .global DAT_0600498c
DAT_0600498c:
    .2byte  0xD116                    ! draw mode: special blended sprite

    .global DAT_0600498e
DAT_0600498e:
    .2byte  0x7080                    ! draw mode: gouraud shading + texture
_pool_tile_data_5:
    .4byte  sym_06042CBC              ! tile data for templates 5, 9, 11
_pool_tile_data_6:
    .4byte  sym_06042CD2              ! tile data for templates 6, 7
_pool_tile_data_8:
    .4byte  sym_06042E4E              ! tile data for template 8
_pool_tile_data_10:
    .4byte  sym_0604304E              ! tile data for template 10
.L_fill_template_10:
    /* --- template 10: w=2, h=2, d=0, mode=0xD116 (shadow) --- */
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(6, r13)              ! entry[10].width = 2
    exts.b r5, r0                     ! r0 = 2
    mov.b r0, @(7, r13)              ! entry[10].height = 2
    exts.b r14, r0                    ! r0 = 0
    mov.b r0, @(9, r13)              ! entry[10].depth = 0
    exts.w r14, r0                    ! r0 = 0
    mov.w r0, @(10, r13)             ! entry[10].offset = 0 (flat)
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    mov.b @(7, r13), r0              ! r0 = height
    mov r0, r2                        ! r2 = height
    muls.w r2, r3                     ! macl = width * height
    sts macl, r3                      ! r3 = width * height
    shll r3                           ! r3 = w * h * 2
    exts.b r3, r0                     ! truncate to byte
    mov.b r0, @(8, r13)              ! entry[10].stride = w * h * 2
    /* --- advance to template 11 --- */
    mov r6, r13                       ! r13 = index 11
    add #0x1, r6                      ! r6 = 12 (next index)
    mov r13, r3                       ! r3 = index 11
    shll2 r13                         ! r13 = idx * 4
    shll2 r3                          ! r3 = idx * 4
    shll r3                           ! r3 = idx * 8
    add r3, r13                       ! r13 = idx * 12
    add r7, r13                       ! r13 = &template[11]
    /* --- template 11: w=1, h=1, d=1, mode=0x0080 --- */
    mov.l r11, @r13                   ! entry[11].tile_ptr = tile_data_5 (r11)
    mov.w   DAT_06004a88, r0          ! r0 = 0x0080 (draw mode: untextured)
    mov.w r0, @(4, r13)              ! entry[11].mode = 0x0080
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(6, r13)              ! entry[11].width = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(7, r13)              ! entry[11].height = 1
    exts.b r4, r0                     ! r0 = 1
    mov.b r0, @(9, r13)              ! entry[11].depth = 1
    mov.b @(6, r13), r0              ! r0 = width
    mov r0, r3                        ! r3 = width
    /* --- templates 12 + epilogue (encoded as .4byte blob, not yet elevated to L3) --- */
    .4byte  0x84D96203
    .4byte  0x232F031A
    .4byte  0x633B7340
    .4byte  0x4300603F
    .4byte  0x81D584D6
    .4byte  0x630384D7
    .4byte  0x6203232F
    .4byte  0x031A4300
    .4byte  0x603E80D8
    .4byte  0x6D637601
    .4byte  0x63D34D08
    .4byte  0x43084300
    .4byte  0x3D3C3D7C
    .4byte  0xD21C2D22
    .4byte  0x903381D2
    .4byte  0x604E80D6
    .4byte  0x605E80D7
    .4byte  0xE02080D9
    .4byte  0x60EF81D5
    .4byte  0x84D66303
    .4byte  0x84D76203
    .4byte  0x232F031A
    .4byte  0x4300603E
    .4byte  0x636380D8
    .4byte  0x46084308
    .4byte  0x4300363C
    .4byte  0x367CD210
    .4byte  0x26229019
    .4byte  0x8162604E
    .4byte  0x8066605E
    .4byte  0x806760EE
    .4byte  0x806960EF
    .4byte  0x81658466
    .4byte  0x63038467
    .4byte  0x6203232F
    .4byte  0x031A4300
    .4byte  0x603E8068
    .4byte  0x7F044F16
    .4byte  0x6BF66DF6
    .4byte  0x000B6EF6

    .global DAT_06004a88
DAT_06004a88:
    .2byte  0x0080                    ! draw mode: untextured sprite

    .global DAT_06004a8a
DAT_06004a8a:
    .2byte  0x01F7                    ! inline constant (used by .4byte blob above)

    .global DAT_06004a8c
DAT_06004a8c:
    .4byte  0x91F7FFFF               ! inline constant (used by .4byte blob above)
    .4byte  sym_06059CC0              ! pool: data reference A
    .4byte  sym_06059DC0              ! pool: data reference B
