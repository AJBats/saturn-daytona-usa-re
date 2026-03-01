
    .section .text.FUN_0602B9EC


    .global scene_graph_walk
    .type scene_graph_walk, @function
scene_graph_walk:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov r5, r14
    mov r6, r13
    mov.l   .L_cache_array_base, r12
    mov #0x40, r4
    mov #-0x1, r0
.L_cache_clear_loop:
    mov.l r0, @r12
    dt r4
    bf/s    .L_cache_clear_loop
    add #0x10, r12
    mov.l   .L_view_matrix_ptr, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    sts macl, r0
    add r0, r8
.L_node_loop_top:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_scratch_xy_buf, r11
    mov.l   .L_cached_xyz_out, r5
    mov.l   .L_scene_matrix_ptr, r0
    mov.l @r0, r6
    mov.w @(16, r8), r0
    extu.w r0, r4
    bsr     vdp1_cmd_emit
    mov #0x6, r9
    mov.l r1, @r5
    mov.l r2, @(4, r5)
    mov.l r3, @(8, r5)
    mov.l   .L_z_accum_ptr, r7
    mov.l r2, @r7
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_skip_matrix_mul
    mov.l   .L_rotated_row_buf, r7
    mov r8, r4
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @r7
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @(4, r7)
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0x24, r6
    sts mach, r0
    sts macl, r9
    xtrct r0, r9
    mov.l r9, @(8, r7)
    clrmac
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    add #-0xC, r5
    sts mach, r9
    sts macl, r0
    xtrct r9, r0
    cmp/pl r0
    bt      .L_skip_matrix_mul
    bra     .L_next_node
    nop
    .2byte  0x0000
.L_cache_array_base:
    .4byte  sym_06094AE4
.L_view_matrix_ptr:
    .4byte  sym_06063F08
.L_scratch_xy_buf:
    .4byte  sym_0602BD6C
.L_cached_xyz_out:
    .4byte  sym_0602BD8C
.L_scene_matrix_ptr:
    .4byte  sym_0608A52C
.L_z_accum_ptr:
    .4byte  sym_0602BDB4
.L_rotated_row_buf:
    .4byte  sym_0602BD9C
.L_skip_matrix_mul:
    mov.w @(16, r8), r0
    mov.l   .L_stage_child_1, r7
    bsr     .L_cache_lookup
    mov r0, r4
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(16, r8), r0
    bsr     .L_depth_clip_test
    nop

    .global sym_0602BAB6
sym_0602BAB6:
    mov.w @(18, r8), r0
    mov.l   .L_stage_child_2, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     vdp1_cmd_emit
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(18, r8), r0
    bsr     .L_depth_clip_test
    nop

    .global sym_0602BACC
sym_0602BACC:
    mov.w @(20, r8), r0
    mov.l   .L_stage_child_3, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     vdp1_cmd_emit
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(20, r8), r0
    bsr     .L_depth_clip_test
    nop

    .global sym_0602BAE2
sym_0602BAE2:
    mov.w @(22, r8), r0
    mov.l   .L_stage_frustum, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     vdp1_cmd_emit
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(22, r8), r0
    bsr     .L_depth_clip_test
    nop

    .global sym_0602BAF8
sym_0602BAF8:
    mov.l   .L_sort_write_idx_ptr, r0
    mov #0x18, r1
    mov.l @r0, r0
    mulu.w r0, r1
    mov.l   .L_sort_buf_base, r2
    sts macl, r9
    add r2, r9
    add #-0x20, r11
    mov.w   DAT_0602bb26, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_z_not_all_behind
    cmp/gt r2, r12
    bf      .L_z_not_all_behind
    cmp/gt r4, r12
    bf      .L_z_not_all_behind
    cmp/gt r6, r12
    bf      .L_z_not_all_behind
    bra     .L_next_node
    nop

    .global DAT_0602bb26
DAT_0602bb26:
    .2byte  0xFF50
.L_stage_child_1:
    .4byte  sym_0602BAB6
.L_stage_child_2:
    .4byte  sym_0602BACC
.L_stage_child_3:
    .4byte  sym_0602BAE2
.L_stage_frustum:
    .4byte  sym_0602BAF8
.L_sort_write_idx_ptr:
    .4byte  sym_060620D4
.L_sort_buf_base:
    .4byte  sym_0608AC20
.L_z_not_all_behind:
    mov.w   DAT_0602bbba, r12
    cmp/gt r0, r12
    bt      .L_z_partly_visible
    cmp/gt r2, r12
    bt      .L_z_partly_visible
    cmp/gt r4, r12
    bt      .L_z_partly_visible
    cmp/gt r6, r12
    bt      .L_next_node
.L_z_partly_visible:
    mov.w   DAT_0602bbbc, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_y_not_all_below
    cmp/gt r3, r12
    bf      .L_y_not_all_below
    cmp/gt r5, r12
    bf      .L_y_not_all_below
    cmp/gt r7, r12
    bt      .L_next_node
.L_y_not_all_below:
    mov.w   DAT_0602bbbe, r12
    cmp/gt r1, r12
    bt      .L_y_partly_visible
    cmp/gt r3, r12
    bt      .L_y_partly_visible
    cmp/gt r5, r12
    bt      .L_y_partly_visible
    cmp/gt r7, r12
    bf      .L_next_node
.L_y_partly_visible:
    mov r9, r12
    add #0x18, r12
    mov.w r7, @-r12
    mov.w r6, @-r12
    mov.w r5, @-r12
    mov.w r4, @-r12
    mov.w r3, @-r12
    mov.w r2, @-r12
    mov.w r1, @-r12
    mov.w r0, @-r12
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
    mov.l   .L_sort_jump_table, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r2
    .word 0xC777
    mov.l @r0, r3
    mov.l @(4, r0), r4
    mov.l @(8, r0), r5
    jmp @r2
    mov.l @(12, r0), r6

    .global DAT_0602bbba
DAT_0602bbba:
    .2byte  0x00B0

    .global DAT_0602bbbc
DAT_0602bbbc:
    .2byte  0xFF81

    .global DAT_0602bbbe
DAT_0602bbbe:
    .2byte  0x0051
.L_sort_jump_table:
    .4byte  sym_0602BDB8

    .global loc_0602BBC4
loc_0602BBC4:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_store_sort_key
    shlr2 r3

    .global loc_0602BBCE
loc_0602BBCE:
    cmp/ge r3, r4
    bt      .L_min_skip_r4
    mov r4, r3
.L_min_skip_r4:
    cmp/ge r3, r5
    bt      .L_min_skip_r5
    mov r5, r3
.L_min_skip_r5:
    cmp/ge r3, r6
    bt      .L_min_done
    mov r6, r3
.L_min_done:
    bra     .L_store_sort_key
    nop

    .global loc_0602BBE4
loc_0602BBE4:
    cmp/gt r3, r4
    bf      .L_max_skip_r4
    mov r4, r3
.L_max_skip_r4:
    cmp/gt r3, r5
    bf      .L_max_skip_r5
    mov r5, r3
.L_max_skip_r5:
    cmp/gt r3, r6
    bf      .L_max_done
    mov r6, r3
.L_max_done:
    bra     .L_store_sort_key
    nop

    .global loc_0602BBFA
loc_0602BBFA:
    mov #0x1, r0
    bra     .L_bias_max_loop
    shll16 r0

    .global loc_0602BC00
loc_0602BC00:
    mov.l   .L_large_depth_bias, r0
.L_bias_max_loop:
    cmp/gt r3, r4
    bf      .L_bias_skip_r4
    mov r4, r3
.L_bias_skip_r4:
    cmp/gt r3, r5
    bf      .L_bias_skip_r5
    mov r5, r3
.L_bias_skip_r5:
    cmp/gt r3, r6
    bf      .L_bias_done
    mov r6, r3
.L_bias_done:
    add r0, r3
.L_store_sort_key:
    mov.l   .L_z_accum_val_ptr, r1
    mov.l @r1, r1
    mov.l   .L_scene_depth_param, r0
    mov.l @r0, r0
    mov.l   .L_fp_two, r2
    add r2, r1
    cmp/gt r1, r0
    bf      .L_no_depth_bias
    mov.l   .L_depth_bias_10, r2
    add r2, r3
.L_no_depth_bias:
    mov.l   .L_sort_idx_ptr, r2
    neg r3, r3
    mov.l   .L_sort_key_array, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_node:
    mov.l @r15+, r7
    dt r7
    bt      .L_all_nodes_done
    bra     .L_node_loop_top
    nop
.L_large_depth_bias:
    .4byte  0x000B8000
.L_z_accum_val_ptr:
    .4byte  sym_0602BDB4
.L_scene_depth_param:
    .4byte  sym_06063F54
.L_fp_two:
    .4byte  0x00020000
.L_depth_bias_10:
    .4byte  0x000A0000
.L_sort_idx_ptr:
    .4byte  sym_060620D4
.L_sort_key_array:
    .4byte  sym_0606A4F8
.L_all_nodes_done:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8

    .global vdp1_cmd_emit
    .type vdp1_cmd_emit, @function
vdp1_cmd_emit:
    mul.l r9, r4
    mov.l   .L_emit_scratch, r4
    sts macl, r0
    add r14, r0
    mov.w @r0+, r1
    mov.w @r0+, r2
    mov.w @r0+, r3
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @r4
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(4, r4)
    shll8 r3
    shll2 r3
    shll r3
    mov.l r3, @(8, r4)
    mov #0x18, r7
    add r6, r7
    clrmac
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    add #-0xC, r4
    mov.l @(8, r7), r9
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r9, r3
    cmp/gt r10, r3
    bf      .L_next_node
    mov.w   .L_emit_cache_offset, r9
    mov.w   .L_emit_z_threshold, r0
    mov.l r0, @(16, r9)
    mov.l r3, @(0, r9)
    mov #0x0, r0
    mov.l r0, @(20, r9)
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    mov.l @r7+, r9
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r9, r1
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r9
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    add r9, r2
    rts
    add #-0x18, r6
.L_emit_cache_offset:
    .2byte  0xFF00
.L_emit_z_threshold:
    .2byte  0x00A0
    .2byte  0x0000
.L_emit_scratch:
    .4byte  sym_0602BDA8
.L_depth_clip_test:
    mov.w   .L_clip_cache_offset, r9
    mov.l @(28, r9), r7
    dmuls.l r1, r7
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r7
    mov.l r1, @r11
    sts mach, r2
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.w   DAT_0602bd36, r7
    cmp/gt r7, r1
    bt      .L_next_node
    mov.w   DAT_0602bd38, r7
    cmp/gt r1, r7
    bt      .L_next_node
    mov.w   DAT_0602bd3a, r7
    cmp/gt r7, r2
    bt      .L_next_node
    mov.w   DAT_0602bd38, r7
    cmp/gt r2, r7
    bt      .L_next_node
    mov.l r0, @r12
    mov.l r1, @(4, r12)
    mov.l r2, @(8, r12)
    mov.l r3, @(12, r12)
    rts
    nop
.L_clip_cache_offset:
    .2byte  0xFF00

    .global DAT_0602bd36
DAT_0602bd36:
    .2byte  0x0190

    .global DAT_0602bd38
DAT_0602bd38:
    .2byte  0xFE70

    .global DAT_0602bd3a
DAT_0602bd3a:
    .2byte  0x00C8
.L_cache_lookup:
    and #0x3F, r0
    mov.l   .L_cache_base_lookup, r12
    shll2 r0
    shll2 r0
    add r0, r12
    mov.l @r12, r0
    cmp/pz r0
    bf      .L_cache_miss
    cmp/eq r0, r4
    bf      .L_cache_miss
    mov.l @(4, r12), r1
    mov.l @(8, r12), r2
    mov.l @(12, r12), r3
    mov.l r1, @r11
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.l r3, @r5
    jmp @r7
    add #0x4, r5
    .2byte  0x0000
.L_cache_base_lookup:
    .4byte  sym_06094AE4
.L_cache_miss:
    rts
    nop


    .global sym_0602BD6C
sym_0602BD6C:
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

    .global sym_0602BD8C
sym_0602BD8C:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602bd90
DAT_0602bd90:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602bd94
DAT_0602bd94:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602bd98
DAT_0602bd98:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602BD9C
sym_0602BD9C:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602BDA8
sym_0602BDA8:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602BDB4
sym_0602BDB4:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602BDB8
sym_0602BDB8:
    .4byte  loc_0602BBC4
    .4byte  loc_0602BBCE
    .4byte  loc_0602BBE4
    .4byte  loc_0602BBFA
    .4byte  loc_0602BC00
