
    .section .text.FUN_06026110


    .global scene_dual_finalize
    .type scene_dual_finalize, @function
scene_dual_finalize:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    extu.b r14, r3
    extu.b r14, r1
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov #0x8, r8
    mov.l   .L_scene_output_table_a, r9
    mov.l   .L_scene_output_table_b, r10
    mov.l   .L_slot_element_table, r11
    mov.l   .L_scene_data_table_a, r12
    mov.l   .L_render_phase_byte, r2
    mov.b r3, @r2
    mov.l   .L_variant_active_byte, r2
    mov.b r1, @r2
    mov.l   .L_dual_finalize_flag, r4
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_first_pass_init
    mov #0xE, r13
    bra     .L_epilogue
    nop
.L_first_pass_init:
    mov #0x1, r3
    mov.b r3, @r4
    extu.w r14, r4
.L_slot_init_loop:
    extu.b r4, r5
    mov r5, r3
    add #0x1, r4
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    extu.b r5, r5
    extu.w r14, r3
    add r11, r5
    mov.l @r5, r2
    mov.w r14, @r2
    mov.l @(4, r5), r2
    mov.w r3, @r2
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_slot_init_loop
    extu.w r14, r4
.L_scan_data_a_priority:
    extu.w r4, r2
    shll2 r2
    shll r2
    add r12, r2
    mov.l @r2, r3
    mov.w @r3, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_scan_data_a_next
    bra     .L_scan_data_a_found
    nop
.L_scan_data_a_next:
    add #0x1, r4
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_scan_data_a_priority
.L_scan_data_a_found:
    extu.w r4, r4
    cmp/ge r13, r4
    bt      .L_skip_to_pass2
    mov.l   .L_fn_scene_finalize_a, r3
    jsr @r3
    nop
    bra     .L_merge_pass1_start
    nop
.L_skip_to_pass2:
    bra     .L_pass2_outer_loop_check
    extu.w r14, r5
.L_scene_output_table_a:
    .4byte  sym_06060F2C                /* scene output table A (8-byte stride) */
.L_scene_output_table_b:
    .4byte  sym_0606107C                /* scene output table B (8-byte stride) */
.L_slot_element_table:
    .4byte  sym_060610BC                /* slot element table (12-byte stride) */
.L_scene_data_table_a:
    .4byte  sym_06060D7C                /* scene data table A (8-byte stride) */
.L_render_phase_byte:
    .4byte  sym_06061198                /* render phase state byte */
.L_variant_active_byte:
    .4byte  sym_06061199                /* variant active flag byte */
.L_dual_finalize_flag:
    .4byte  sym_06060D78                /* dual finalize active flag byte */
.L_fn_scene_finalize_a:
    .4byte  scene_finalize_a            /* rebuilds scene output from data table A */
.L_pass1_outer_body:
    extu.w r14, r4
    extu.b r5, r7
    extu.w r5, r6
    mov r7, r3
    shll2 r6
    shll2 r7
    shll2 r3
    shll r3
    add r3, r7
    extu.b r7, r7
    add r11, r7
    shll r6
    add r12, r6
.L_pass1_inner_loop:
    extu.w r4, r3
    shll2 r3
    shll r3
    add r9, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @(8, r7), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r3, r2
    bf      .L_pass1_no_match
    mov.l @r6, r2
    extu.w r4, r3
    shll2 r3
    shll r3
    add r9, r3
    mov.w @(4, r3), r0
    mov r0, r1
    mov.w r1, @r2
.L_pass1_no_match:
    add #0x1, r4
    mov #0xA, r2
    extu.w r4, r3
    cmp/ge r2, r3
    bf      .L_pass1_inner_loop
    add #0x1, r5
.L_pass2_outer_loop_check:
    extu.w r5, r2
    cmp/ge r13, r2
    bf      .L_pass1_outer_body
.L_merge_pass1_start:
    extu.w r14, r4
.L_scan_data_a_count:
    extu.w r4, r2
    shll2 r2
    shll r2
    add r12, r2
    mov.l @(4, r2), r3
    mov.w @r3, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_scan_data_a_count_next
    bra     .L_scan_data_a_count_found
    nop
.L_scan_data_a_count_next:
    add #0x1, r4
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_scan_data_a_count
.L_scan_data_a_count_found:
    extu.w r4, r4
    cmp/ge r13, r4
    bt      .L_all_counts_zero
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_scene_finalize_b, r3
    jmp @r3
    mov.l @r15+, r14
.L_all_counts_zero:
    bra     .L_pass2_outer_check
    extu.w r14, r5
.L_pass2_outer_body:
    extu.w r14, r4
    extu.b r5, r7
    extu.w r5, r6
    mov r7, r3
    shll2 r6
    shll2 r7
    shll2 r3
    shll r3
    add r3, r7
    extu.b r7, r7
    add r11, r7
    shll r6
    add r12, r6
    add #0x4, r6
.L_pass2_inner_loop:
    extu.w r4, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @(8, r7), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r3, r2
    bf      .L_pass2_no_match
    mov.l @r6, r2
    extu.w r4, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.w @(4, r3), r0
    mov r0, r1
    mov.w r1, @r2
.L_pass2_no_match:
    add #0x1, r4
    extu.w r4, r3
    cmp/ge r8, r3
    bf      .L_pass2_inner_loop
    add #0x1, r5
.L_pass2_outer_check:
    extu.w r5, r3
    cmp/ge r13, r3
    bf      .L_pass2_outer_body
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_fn_scene_finalize_b:
    .4byte  scene_finalize_b            /* rebuilds scene output from data table B */
