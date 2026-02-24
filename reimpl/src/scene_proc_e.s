/* scene_proc_e -- 3D vertex transform and depth sort pipeline
 * Translation unit: 0x0602BDD8 - 0x0602C690
 *
 * Functions:
 *   scene_proc_e   (0x0602BDD8) — Per-polygon vertex transform: MAC.L 3×3 matrix
 *                    multiply, backface culling, clipping, Z-sort dispatch
 *   sym_0602C494   (0x0602C494) — Radix/bucket sort for depth ordering. Three passes
 *                    with different bit extraction; uses 32 buckets (5-bit key).
 *                    Bucket data at sym_060A2468 (zeroed between passes).
 *
 * Data tables:
 *   sym_0602C450   — Pipeline A fn ptrs: (skip, skip, spring_damper, transform_pipeline, mega_render_func)
 *   sym_0602C460   — Pipeline B fn ptrs: (skip, skip, vblank_frame_handler, render_list_builder, render_obj_processor)
 *   sym_0602C470   — Z-sort dispatch table: 5 depth strategies + sort buffer pointers
 */

    .section .text.FUN_0602BDD8


    .global scene_proc_e
    .type scene_proc_e, @function
scene_proc_e:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov.l   .L_clip_threshold_ptr, r10
    mov.l @r10, r10                     ! r10 = far-plane clip threshold
    mov #0x18, r0
    mul.l r7, r0
    mov r5, r3
    mov r6, r13
    mov r3, r14
    sts macl, r0
    add r0, r8
.L_vertex_loop:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.w @(16, r8), r0
    extu.w r0, r4
    mov #0x6, r1
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_vertex_output_a, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_vertex_scratch, r5
    mov.l   .L_render_budget, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac                              ! 3x3 matrix multiply (vertex x camera matrix)
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10                      ! Z >= far clip?
    mov.l   .L_vertex_output_y, r11
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0                        ! backface cull flag
    bf      .L_vertex_2
    mov.l   .L_vertex_accum_a, r5
    mov r8, r4
    mov.l   .L_render_budget, r0
    clrmac
    mov.l @r0, r2
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r2+
    xtrct r0, r1
    mov.l r1, @r5
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r2+
    xtrct r0, r1
    mov.l r1, @(4, r5)
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @(8, r5)
    mov.l   .L_vertex_scratch, r4      ! dot product for backface cull
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0                           ! facing camera? (dot > 0)
    bt      .L_vertex_2
    bra     .L_next_poly
    nop
    .2byte  0x0000
.L_clip_threshold_ptr:
    .4byte  sym_06063F08
.L_vertex_output_a:
    .4byte  sym_06094F74
.L_vertex_scratch:
    .4byte  sym_06094EF4
.L_render_budget:
    .4byte  sym_0608A52C
.L_vertex_output_y:
    .4byte  sym_06094EEC
.L_vertex_accum_a:
    .4byte  sym_06094F24
.L_vertex_2:
    mov.w @(18, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_vertex_output_a2, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_vertex_scratch2, r5
    add #0xC, r5
    mov.l   .L_render_budget2, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_vertex_output_a2, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    mov.l   .L_vertex_y_scratch, r5
    mov.l r1, @r5
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_vertex_scratch2, r5
    add #0x18, r5
    mov.l   .L_render_budget2, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_vertex_output_a2, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_vertex_scratch2, r5
    add #0x24, r5
    mov.l   .L_render_budget2, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0
    add r3, r0
    cmp/eq #0x0, r0
    bt      .L_post_clip_setup
    cmp/eq #0x4, r0
    bf      .L_clip_dispatch
    bra     .L_next_poly
    nop
.L_vertex_output_a2:
    .4byte  sym_06094F74
.L_vertex_scratch2:
    .4byte  sym_06094EF4
.L_render_budget2:
    .4byte  sym_0608A52C
.L_vertex_y_scratch:
    .4byte  sym_06094FA4
.L_clip_dispatch:
    mov.l   .L_pipeline_a_table, r1
    shll2 r0
    add r1, r0
    mov.l @r0, r0
    mov.l   .L_vertex_scratch3, r4
    mov.l   .L_vertex_output_y2, r5
    jsr @r0
    nop
.L_post_clip_setup:
    mov.l   .L_frame_counter, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_sprite_data_table, r2
    mov.l   .L_vertex_accum_b, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_vertex_scratch3, r4
    mov r11, r5
    mov.w   DAT_0602c0f0, r1
    mov.w   DAT_0602c0f2, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov.l   .L_vertex_output_x, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_clip_bound_pos, r3
    cmp/gt r3, r1
    bf      .L_clip_check_neg_x
    mov #0x1, r0
    bra     .L_edge_test_1_done
    mov.w r0, @r12

    .global DAT_0602c0f0
DAT_0602c0f0:
    .2byte  0xFF00

    .global DAT_0602c0f2
DAT_0602c0f2:
    .2byte  0x00A0
.L_clip_bound_pos:
    .2byte  0x0190
    .2byte  0x0000
.L_pipeline_a_table:
    .4byte  sym_0602C450
.L_vertex_scratch3:
    .4byte  sym_06094EF4
.L_vertex_output_y2:
    .4byte  sym_06094EEC
.L_frame_counter:
    .4byte  sym_060620D4
.L_sprite_data_table:
    .4byte  sym_0608AC20
.L_vertex_accum_b:
    .4byte  sym_06094F54
.L_vertex_output_x:
    .4byte  sym_06094EE4
.L_clip_check_neg_x:
    mov.w   DAT_0602c120, r3
    cmp/gt r1, r3
    bf      .L_clip_check_pos_y
    mov #0x1, r0
    bra     .L_edge_test_1_done
    mov.w r0, @r12

    .global DAT_0602c120
DAT_0602c120:
    .2byte  0xFE70
.L_clip_check_pos_y:
    mov.w   DAT_0602c12e, r3
    cmp/gt r3, r2
    bf      .L_clip_check_neg_y
    mov #0x1, r0
    bra     .L_edge_test_1_done
    mov.w r0, @r12

    .global DAT_0602c12e
DAT_0602c12e:
    .2byte  0x012C
.L_clip_check_neg_y:
    mov.w   DAT_0602c176, r3
    cmp/gt r2, r3
    bf      .L_edge_test_1_done
    mov #0x1, r0
    mov.w r0, @r12
.L_edge_test_1_done:
    mov r11, r5
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_0602c178, r1
    mov.w   DAT_0602c17a, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(2, r12)
    mov.w   DAT_0602c17c, r3
    cmp/gt r3, r1
    bf      .L_0602C17E
    mov #0x1, r0
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)

    .global DAT_0602c176
DAT_0602c176:
    .2byte  0xFE70

    .global DAT_0602c178
DAT_0602c178:
    .2byte  0xFF00

    .global DAT_0602c17a
DAT_0602c17a:
    .2byte  0x00A0

    .global DAT_0602c17c
DAT_0602c17c:
    .2byte  0x0190
.L_0602C17E:
    mov.w   DAT_0602c18a, r3
    cmp/gt r1, r3
    bf      .L_0602C18C
    mov #0x1, r0
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)

    .global DAT_0602c18a
DAT_0602c18a:
    .2byte  0xFE70
.L_0602C18C:
    mov.w   DAT_0602c198, r3
    cmp/gt r3, r2
    bf      .L_0602C19A
    mov #0x1, r0
    bra     .L_edge_test_2_done
    mov.w r0, @(2, r12)

    .global DAT_0602c198
DAT_0602c198:
    .2byte  0x012C
.L_0602C19A:
    mov.w   DAT_0602c1e0, r3
    cmp/gt r2, r3
    bf      .L_edge_test_2_done
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_edge_test_2_done:
    mov r11, r5
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_0602c1e2, r1
    mov.w   DAT_0602c1e4, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(4, r12)
    mov.w   DAT_0602c1e6, r3
    cmp/gt r3, r1
    bf      .L_0602C1E8
    mov #0x1, r0
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)

    .global DAT_0602c1e0
DAT_0602c1e0:
    .2byte  0xFE70

    .global DAT_0602c1e2
DAT_0602c1e2:
    .2byte  0xFF00

    .global DAT_0602c1e4
DAT_0602c1e4:
    .2byte  0x00A0

    .global DAT_0602c1e6
DAT_0602c1e6:
    .2byte  0x0190
.L_0602C1E8:
    mov.w   DAT_0602c1f4, r3
    cmp/gt r1, r3
    bf      .L_0602C1F6
    mov #0x1, r0
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)

    .global DAT_0602c1f4
DAT_0602c1f4:
    .2byte  0xFE70
.L_0602C1F6:
    mov.w   DAT_0602c202, r3
    cmp/gt r3, r2
    bf      .L_0602C204
    mov #0x1, r0
    bra     .L_edge_test_3_done
    mov.w r0, @(4, r12)

    .global DAT_0602c202
DAT_0602c202:
    .2byte  0x012C
.L_0602C204:
    mov.w   DAT_0602c24a, r3
    cmp/gt r2, r3
    bf      .L_edge_test_3_done
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_edge_test_3_done:
    mov r11, r5
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602c24c, r1
    mov.w   DAT_0602c24e, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(6, r12)
    mov.w   DAT_0602c250, r3
    cmp/gt r3, r1
    bf      .L_0602C252
    mov #0x1, r0
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)

    .global DAT_0602c24a
DAT_0602c24a:
    .2byte  0xFE70

    .global DAT_0602c24c
DAT_0602c24c:
    .2byte  0xFF00

    .global DAT_0602c24e
DAT_0602c24e:
    .2byte  0x00A0

    .global DAT_0602c250
DAT_0602c250:
    .2byte  0x0190
.L_0602C252:
    mov.w   DAT_0602c25e, r3
    cmp/gt r1, r3
    bf      .L_0602C260
    mov #0x1, r0
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)

    .global DAT_0602c25e
DAT_0602c25e:
    .2byte  0xFE70
.L_0602C260:
    mov.w   DAT_0602c26c, r3
    cmp/gt r3, r2
    bf      .L_0602C26E
    mov #0x1, r0
    bra     .L_edge_test_4_done
    mov.w r0, @(6, r12)

    .global DAT_0602c26c
DAT_0602c26c:
    .2byte  0x012C
.L_0602C26E:
    mov.w   DAT_0602c29c, r3
    cmp/gt r2, r3
    bf      .L_edge_test_4_done
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_edge_test_4_done:
    mov.l   .L_sh2_periph_0x150, r4
    mov.l   .L_scale_factor, r5
    mov.l   .L_sh2_periph_0x181, r6
    mov.l   .L_poly_limit, r7
    mov.l @r11, r0
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    mov.l @(8, r11), r0
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    mov.l @(16, r11), r0
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    mov.l @(24, r11), r0
    cmp/gt r0, r4
    bf      .L_frustum_check_right
    bra     .L_next_poly
    nop

    .global DAT_0602c29c
DAT_0602c29c:
    .2byte  0xFE70
    .2byte  0x0000
.L_sh2_periph_0x150:
    .4byte  0xFFFFFF50                  /* SH-2 peripheral +0x150 */
.L_scale_factor:
    .4byte  0x000000B0
.L_sh2_periph_0x181:
    .4byte  0xFFFFFF81                  /* SH-2 peripheral +0x181 */
.L_poly_limit:
    .4byte  0x00000051
.L_frustum_check_right:
    mov.l @r11, r0
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    mov.l @(8, r11), r0
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    mov.l @(16, r11), r0
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    mov.l @(24, r11), r0
    cmp/gt r0, r5
    bt      .L_frustum_check_top
    bra     .L_next_poly
    nop
.L_frustum_check_top:
    mov.l @(4, r11), r0
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    mov.l @(12, r11), r0
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    mov.l @(20, r11), r0
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    mov.l @(28, r11), r0
    cmp/gt r0, r6
    bf      .L_frustum_check_bottom
    bra     .L_next_poly
    nop
.L_frustum_check_bottom:
    mov.l @(4, r11), r0
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    mov.l @(12, r11), r0
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    mov.l @(20, r11), r0
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    mov.l @(28, r11), r0
    cmp/gt r0, r7
    bt      .L_all_clipped_check
    bra     .L_next_poly
    nop
.L_all_clipped_check:
    mov.w @r12, r1
    mov.w @(2, r12), r0
    add r0, r1
    mov.w @(4, r12), r0
    add r0, r1
    mov.w @(6, r12), r0
    add r1, r0
    cmp/eq #0x4, r0
    bf      .L_partial_clip
    bra     .L_next_poly
    nop
.L_partial_clip:
    cmp/eq #0x0, r0
    bt      .L_store_vertices
    mov r11, r4
    shll2 r0
    mov.l   .L_pipeline_b_table, r1
    add r1, r0
    mov.l @r0, r0
    jsr @r0
    mov r12, r5
.L_store_vertices:
    mov.l @r11, r0
    mov.w r0, @(8, r9)
    mov.l @(4, r11), r0
    mov.w r0, @(10, r9)
    mov.l @(8, r11), r0
    mov.w r0, @(12, r9)
    mov.l @(12, r11), r0
    mov.w r0, @(14, r9)
    mov.l @(16, r11), r0
    mov.w r0, @(16, r9)
    mov.l @(20, r11), r0
    mov.w r0, @(18, r9)
    mov.l @(24, r11), r0
    mov.w r0, @(20, r9)
    mov.l @(28, r11), r0
    mov.w r0, @(22, r9)
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)
    mov.w @(12, r8), r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.b r0, @(4, r9)
    mov r13, r0
    mov.b r0, @(5, r9)
    mov.w @(12, r8), r0
    mov.l   .L_zsort_dispatch, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l   .L_vertex_scratch4, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0
    mov.l @(44, r1), r6
.L_pipeline_b_table:
    .4byte  sym_0602C460
.L_zsort_dispatch:
    .4byte  sym_0602C470
.L_vertex_scratch4:
    .4byte  sym_06094EF4

    .global loc_0602C380
loc_0602C380:
    add r4, r3
    add r5, r6
    add r6, r3
    shlr2 r3
    bra     .L_zsort_finalize
    nop

    .global loc_0602C38C
loc_0602C38C:
    cmp/ge r3, r4
    bt      .L_0602C392
    mov r4, r3
.L_0602C392:
    cmp/ge r3, r5
    bt      .L_0602C398
    mov r5, r3
.L_0602C398:
    cmp/ge r3, r6
    bt      .L_0602C39E
    mov r6, r3
.L_0602C39E:
    bra     .L_zsort_finalize
    nop

    .global loc_0602C3A2
loc_0602C3A2:
    cmp/gt r3, r4
    bf      .L_0602C3A8
    mov r4, r3
.L_0602C3A8:
    cmp/gt r3, r5
    bf      .L_0602C3AE
    mov r5, r3
.L_0602C3AE:
    cmp/gt r3, r6
    bf      .L_0602C3B4
    mov r6, r3
.L_0602C3B4:
    bra     .L_zsort_finalize
    nop

    .global loc_0602C3B8
loc_0602C3B8:
    mov.l   .L_fp_depth_bias_a, r0
    cmp/gt r3, r4
    bf      .L_0602C3C0
    mov r4, r3
.L_0602C3C0:
    cmp/gt r3, r5
    bf      .L_0602C3C6
    mov r5, r3
.L_0602C3C6:
    cmp/gt r3, r6
    bf      .L_0602C3CC
    mov r6, r3
.L_0602C3CC:
    bra     .L_zsort_finalize
    add r0, r3
.L_fp_depth_bias_a:
    .4byte  0x000B8000

    .global loc_0602C3D4
loc_0602C3D4:
    mov.l   .L_fp_one, r0
    cmp/gt r3, r4
    bf      .L_0602C3DC
    mov r4, r3
.L_0602C3DC:
    cmp/gt r3, r5
    bf      .L_0602C3E2
    mov r5, r3
.L_0602C3E2:
    cmp/gt r3, r6
    bf      .L_0602C3E8
    mov r6, r3
.L_0602C3E8:
    add r0, r3
.L_zsort_finalize:
    mov.l   .L_vertex_y_scratch2, r1
    mov.l @r1, r1
    mov.l   .L_depth_sort_state, r0
    mov.l @r0, r0
    mov.l   .L_fp_two, r2
    add r2, r1
    cmp/gt r1, r0
    bf      .L_zsort_store
    mov.l   .L_fp_depth_bias_b, r2
    add r2, r3
.L_zsort_store:
    mov.l   .L_frame_counter2, r2
    neg r3, r3
    mov.l   .L_sprite_index_table, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_poly:
    mov.l @r15+, r7
    dt r7
    bt      .L_return
    bra     .L_vertex_loop
    nop
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_vertex_y_scratch2:
    .4byte  sym_06094FA4
.L_depth_sort_state:
    .4byte  sym_06063F54
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fp_depth_bias_b:
    .4byte  0x000A0000
.L_frame_counter2:
    .4byte  sym_060620D4
.L_sprite_index_table:
    .4byte  sym_0606A4F8
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
    .2byte  0x0009

    .global sym_0602C450
sym_0602C450:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602C460
sym_0602C460:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602C470
sym_0602C470:
    .4byte  loc_0602C380
    .4byte  loc_0602C38C
    .4byte  loc_0602C3A2
    .4byte  loc_0602C3D4
    .4byte  loc_0602C3B8
    .4byte  sym_060A2468
    .4byte  0x06400009
    .4byte  sym_060A2428
    .4byte  sym_06094FA8

    .global sym_0602C494
sym_0602C494:                           ! radix bucket sort -- 3 passes, 5-bit bucket key
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov r5, r9
    mov.l   .L_bucket_counts_init, r1
    mov.l   .L_sort_buffer_b, r11
    mov.l r11, @r1
    mov.l   .L_sort_input, r3
    mov r9, r1
    mov #0x0, r2
.L_copy_input_loop:
    mov.w @r1+, r11
    add #0x1, r2
    cmp/hs r8, r2
    mov.w r11, @r3
    bf/s    .L_copy_input_loop
    add #0x2, r3
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
    mov.l   .L_sort_input, r6
    mov #0x0, r7
    mov.l   .L_bucket_indices_b, r10
    mov.w   .L_bucket_stride_b, r4
    mov.l   .L_sort_buffer_b, r5
.L_bucket_pass_1:
    mov.w @r6+, r0
    mov r10, r2
    and #0x1F, r0
    add r0, r2
    add r0, r2
    mov.w @r2, r1
    mul.l r4, r0
    extu.w r1, r0
    add #0x1, r1
    mov.w r1, @r2
    sts macl, r1
    shll r0
    add r1, r0
    mov.w r7, @(r0, r5)
    add #0x1, r7
    cmp/hs r8, r7
    bf      .L_bucket_pass_1
    mov r9, r4
    mov.l r8, @-r15
    mov.l   .L_bucket_indices, r3
    mov.l   .L_sort_buffer, r6
    mov #0x0, r7
    mov.w   .L_bucket_stride, r0
    mov #0x1F, r5
.L_gather_pass_1:
    mov.w @r3+, r1
    mov r6, r2
    extu.w r1, r1
    cmp/pl r1
    bf/s    .L_gather_next_1
    add r0, r6
.L_gather_inner_1:
    mov.w @r2+, r8
    add #-0x1, r1
    cmp/pl r1
    mov.w r8, @r4
    bt/s    .L_gather_inner_1
    add #0x2, r4
.L_gather_next_1:
    add #0x1, r7
    cmp/gt r5, r7
    bf      .L_gather_pass_1
    mov.l @r15+, r8
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
    mov #0x0, r6
    mov r9, r7
.L_bucket_pass_2:
    mov.w @r7, r1
    extu.w r1, r0
    shll r0
    mov.l   .L_sort_input, r1
    mov.w @(r0, r1), r1
    extu.w r1, r0
    shlr2 r0
    shlr2 r0
    shlr r0
    and #0x1F, r0
    mov r0, r2
    add r0, r2
    mov.l   .L_bucket_indices_b, r1
    add r1, r2
    mov.w @r2, r3
    mov r3, r1
    add #0x1, r1
    mov.w r1, @r2
    mov.w   .L_bucket_stride_b, r1
    mul.l r1, r0
    extu.w r3, r3
    shll r3
    sts macl, r1
    lds r3, macl
    add #0x1, r6
    sts macl, r0
    add r1, r0
    mov.l   .L_sort_buffer_b, r1
    mov.w @r7+, r11
    cmp/hs r8, r6
    bf/s    .L_bucket_pass_2
    mov.w r11, @(r0, r1)
    mov r9, r4
    mov.l r8, @-r15
    mov.l   .L_bucket_indices, r3
    mov.l   .L_sort_buffer, r6
    mov #0x0, r7
    mov.w   .L_bucket_stride, r0
    mov #0x1F, r5
.L_gather_pass_2:
    mov.w @r3+, r1
    mov r6, r2
    extu.w r1, r1
    cmp/pl r1
    bf/s    .L_gather_next_2
    add r0, r6
.L_gather_inner_2:
    mov.w @r2+, r8
    add #-0x1, r1
    cmp/pl r1
    mov.w r8, @r4
    bt/s    .L_gather_inner_2
    add #0x2, r4
.L_gather_next_2:
    add #0x1, r7
    cmp/gt r5, r7
    bf      .L_gather_pass_2
    mov.l @r15+, r8
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
    mov #0x0, r6
    mov r9, r7
.L_bucket_pass_3:
    mov.w @r7, r1
    extu.w r1, r1
    mov r1, r0
    add r1, r0
    mov.l   .L_sort_input, r1
    mov.b @(r0, r1), r0
    shlr2 r0
    and #0x1F, r0
    mov r0, r2
    add r0, r2
    mov.l   .L_bucket_indices_b, r1
    add r1, r2
    mov.w @r2, r3
    mov r3, r1
    add #0x1, r1
    mov.w r1, @r2
    mov.w   .L_bucket_stride_b, r1
    mul.l r1, r0
    extu.w r3, r3
    shll r3
    sts macl, r1
    lds r3, macl
    add #0x1, r6
    sts macl, r0
    add r1, r0
    mov.l   .L_sort_buffer_b, r1
    mov.w @r7+, r11
    cmp/hs r8, r6
    bf/s    .L_bucket_pass_3
    mov.w r11, @(r0, r1)
    mov r9, r4
    mov.l r8, @-r15
    mov.l   .L_bucket_indices, r3
    mov.l   .L_sort_buffer, r6
    mov #0x0, r7
    mov.w   .L_bucket_stride, r0
    mov #0x1F, r5
.L_gather_pass_3:
    mov.w @r3+, r1
    mov r6, r2
    extu.w r1, r1
    cmp/pl r1
    bf/s    .L_gather_next_3
    add r0, r6
.L_gather_inner_3:
    mov.w @r2+, r8
    add #-0x1, r1
    cmp/pl r1
    mov.w r8, @r4
    bt/s    .L_gather_inner_3
    add #0x2, r4
.L_gather_next_3:
    add #0x1, r7
    cmp/gt r5, r7
    bf      .L_gather_pass_3
    mov.l @r15+, r8
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_bucket_stride:
    .2byte  0x0640
    .2byte  0x0000
.L_bucket_counts:
    .4byte  sym_060A2468
.L_bucket_indices:
    .4byte  sym_060A2428
.L_sort_buffer:
    .4byte  sym_06094FA8
.L_bucket_stride_b:
    .2byte  0x0640
    .2byte  0x0009
.L_bucket_counts_init:
    .4byte  sym_060A2468
.L_sort_buffer_b:
    .4byte  sym_06094FA8
.L_sort_input:
    .4byte  sym_060A17A8
.L_bucket_indices_b:
    .4byte  sym_060A2428
