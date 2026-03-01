
    .section .text.FUN_0601A3F4


    .global car_physics_final
    .type car_physics_final, @function
car_physics_final:
    mov.l r14, @-r15
    mov #0x3, r6
    extu.w r5, r5
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_render_table_b, r8
    mov.l   .L_fn_render_dispatch, r11
    mov.l   .L_render_params, r12
    mov.w   .L_mode_a_id, r3
    cmp/eq r3, r5
    bf/s    .L_mode_b_path
    mov #0x2, r4
    extu.w r14, r3
    mov.l   .L_start_table_a, r2
    add r2, r3
    mov.b @r3, r1
    mov r1, r0
    mov.b r0, @(8, r15)
    bra     .L_mode_a_classify
    extu.w r14, r0
.L_mode_a_class2:
    bra     .L_mode_a_loop_setup
    extu.b r4, r10
.L_mode_a_class3:
    extu.b r6, r10
.L_mode_a_loop_setup:
    mov #0x0, r13
    extu.w r14, r2
    mov.l   .L_count_table_a, r3
    add r3, r2
    mov.l r2, @(4, r15)
    extu.b r10, r1
    shll2 r1
    bra     .L_mode_a_loop_cond
    mov.l r1, @r15
.L_mode_a_classify:
    cmp/eq #0x1, r0
    bt      .L_mode_a_class2
    cmp/eq #0x4, r0
    bt      .L_mode_a_class2
    bra     .L_mode_a_class3
    nop
.L_mode_a_loop_body:
    mov r12, r7
    mov #0x0, r6
    extu.b r13, r3
    mov.l   .L_lookup_table_a, r2
    mov.b @(8, r15), r0
    mov r0, r9
    extu.b r9, r9
    add r3, r9
    shll r9
    add r2, r9
    mov.b @(1, r9), r0
    mov.b @r9, r3
    mov r0, r5
    extu.b r3, r3
    extu.b r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r11
    mov.l @r15, r4
    add #0x1, r13
.L_mode_a_loop_cond:
    extu.b r13, r3
    mov.l @(4, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r3
    bf      .L_mode_a_loop_body
    extu.w r14, r5
    mov.l   .L_final_params_a, r7
    shll r5
    mov.l   .L_final_offset_a, r3
    add r3, r5
    bra     .L_final_dispatch_shared
    mov #0x60, r6
.L_mode_b_path:
    extu.w r14, r2
    mov.l   .L_start_table_b, r3
    add r3, r2
    mov.b @r2, r1
    mov.b r1, @r15
    bra     .L_mode_b_classify
    extu.w r14, r0
.L_mode_b_class2:
    bra     .L_mode_b_loop_setup
    extu.b r4, r10
.L_mode_a_id:
    .2byte  0x00A8                        /* mode A identifier value */
    .2byte  0xFFFF
.L_render_table_b:
    .4byte  sym_06049B36               /* mode B lookup table base */
.L_fn_render_dispatch:
    .4byte  sym_060283E0               /* geometry render dispatch function */
.L_render_params:
    .4byte  sym_06049E54               /* render parameter table */
.L_start_table_a:
    .4byte  sym_06049CD4               /* mode A start offset table (per slot) */
.L_count_table_a:
    .4byte  sym_06049CCC               /* mode A iteration count table (per slot) */
.L_lookup_table_a:
    .4byte  sym_06049C28               /* mode A byte-pair lookup table */
.L_final_params_a:
    .4byte  sym_06049E58               /* mode A final render parameters */
.L_final_offset_a:
    .4byte  sym_06059084               /* mode A final byte-pair offset base */
.L_start_table_b:
    .4byte  sym_06049C1E               /* mode B start offset table (per slot) */
.L_mode_b_class3:
    extu.b r6, r10
.L_mode_b_loop_setup:
    mov #0x0, r13
    extu.w r14, r2
    mov.l   .L_count_table_b, r3
    add r3, r2
    mov.l r2, @(4, r15)
    extu.b r10, r1
    shll2 r1
    bra     .L_mode_b_loop_cond
    mov.l r1, @(8, r15)
.L_mode_b_classify:
    cmp/eq #0x5, r0
    bt      .L_mode_b_class2
    cmp/eq #0x8, r0
    bt      .L_mode_b_class2
    bra     .L_mode_b_class3
    nop
.L_mode_b_loop_body:
    mov r12, r7
    mov #0x0, r6
    mov.b @r15, r9
    extu.b r13, r3
    extu.b r9, r9
    add r3, r9
    shll r9
    add r8, r9
    mov.b @(1, r9), r0
    mov.b @r9, r3
    mov r0, r5
    extu.b r3, r3
    extu.b r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r11
    mov.l @(8, r15), r4
    add #0x1, r13
.L_mode_b_loop_cond:
    extu.b r13, r3
    mov.l @(4, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r3
    bf      .L_mode_b_loop_body
    mov.l   .L_final_params_b, r7
    mov #0x60, r6
    extu.w r14, r5
    shll r5
    mov.l   .L_final_offset_b, r3
    add r3, r5
.L_final_dispatch_shared:
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r2
    mov r0, r5
    mov.b @r2, r2
    extu.b r5, r5
    extu.b r2, r2
    shll2 r5
    shll2 r5
    shll2 r5
    add r2, r5
    shll r5
    extu.b r10, r4
    shll2 r4
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_final_dispatch, r2
    jmp @r2
    mov.l @r15+, r14
.L_count_table_b:
    .4byte  sym_06049C14               /* mode B iteration count table (per slot) */
.L_final_params_b:
    .4byte  sym_06049E58               /* mode B final render parameters */
.L_final_offset_b:
    .4byte  sym_06059060               /* mode B final byte-pair offset base */
.L_fn_final_dispatch:
    .4byte  sym_060284AE               /* final geometry dispatch (tail call) */
