
    .section .text.FUN_06022AE0


    .global render_obj_processor
    .type render_obj_processor, @function
render_obj_processor:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x2C, r15
    mov #0x0, r7
    mov.w   _wpool_coord_lower_bound, r6
    mov r15, r14
    add #0x24, r14
    mov r14, r3
    mov.l r3, @(20, r15)
    mov.w @r5, r2
    mov.w r2, @r3
    add #0x2, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2, r2
    mov.l r2, @(28, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    mov r14, r3
    add #0x4, r3
    mov.l r3, @(8, r15)
    mov r5, r2
    add #0x4, r2
    mov.l r2, @(24, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    add #0x6, r14
    mov.l r14, @(16, r15)
    mov r5, r3
    add #0x6, r3
    mov.l r3, @(32, r15)
    mov.w @r3, r2
    mov.w r2, @r14
    mov r4, r14
    add #0x8, r14
    mov r4, r9
    add #0xC, r9
    mov r4, r11
    add #0x4, r11
    mov r4, r8
    add #0x10, r8
    mov r4, r10
    add #0x14, r10
    mov r4, r12
    add #0x18, r12
    mov r4, r13
    add #0x1C, r13
.L_clip_loop:
    mov.w @r5, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_pathA_vtx0_anchor
    bra     .L_pathB_check
    nop
.L_pathA_vtx0_anchor:
    mov.l @(12, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_pathA_edge01_done
    mov.l @r14, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathA_edge01_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_A, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge01_done
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathA_edge01_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_A, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge01_done
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathA_edge01_done:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_pathA_test_vis2
    nop
_wpool_coord_lower_bound:
    .2byte  0xFE6B
_wpool_x_upper_A:
    .2byte  0x0195
_wpool_y_upper_A:
    .2byte  0x0131
.L_pathA_test_vis2:
    bt      .L_pathA_edge02_done
    mov.l @r8, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r10, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathA_edge02_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_B, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge02_done
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathA_edge02_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_B, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge02_done
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathA_edge02_done:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bf      .L_pathA_nudge_vtx3
    bra     .L_check_convergence
    nop
.L_pathA_nudge_vtx3:
    mov.l @r12, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r13, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathA_edge03_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_B, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge03_done
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathA_edge03_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_B, r3
    cmp/gt r3, r2
    bt      .L_pathA_edge03_done
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathA_edge03_done:
    bra     .L_check_convergence
    nop
_wpool_x_upper_B:
    .2byte  0x0195
_wpool_y_upper_B:
    .2byte  0x0131
.L_pathB_check:
    mov.l @(28, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_pathB_vtx1_anchor
    bra     .L_pathC_check
    nop
.L_pathB_vtx1_anchor:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_pathB_edge10_done
    mov.l @r4, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r11, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathB_edge10_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_C, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge10_done
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathB_edge10_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_C, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge10_done
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathB_edge10_done:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_pathB_edge12_done
    mov.l @r8, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r10, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathB_edge12_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_C, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge12_done
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathB_edge12_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_C, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge12_done
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathB_edge12_done:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_pathB_test_vis3
    nop
_wpool_x_upper_C:
    .2byte  0x0195
_wpool_y_upper_C:
    .2byte  0x0131
.L_pathB_test_vis3:
    bf      .L_pathB_nudge_vtx3
    bra     .L_check_convergence
    nop
.L_pathB_nudge_vtx3:
    mov.l @r12, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r13, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathB_edge13_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_D, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge13_done
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathB_edge13_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_D, r3
    cmp/gt r3, r2
    bt      .L_pathB_edge13_done
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathB_edge13_done:
    bra     .L_check_convergence
    nop
_wpool_x_upper_D:
    .2byte  0x0195
_wpool_y_upper_D:
    .2byte  0x0131
.L_pathC_check:
    mov.l @(24, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_pathC_vtx2_anchor
    bra     .L_pathD_check
    nop
.L_pathC_vtx2_anchor:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_pathC_edge20_done
    mov.l @r4, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r11, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathC_edge20_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_E, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge20_done
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathC_edge20_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_E, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge20_done
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathC_edge20_done:
    mov.l @(12, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_pathC_edge21_done
    mov.l @r14, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r9, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathC_edge21_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_E, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge21_done
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathC_edge21_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_E, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge21_done
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathC_edge21_done:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_pathC_test_vis3
    nop
_wpool_x_upper_E:
    .2byte  0x0195
_wpool_y_upper_E:
    .2byte  0x0131
.L_pathC_test_vis3:
    bf      .L_pathC_nudge_vtx3
    bra     .L_check_convergence
    nop
.L_pathC_nudge_vtx3:
    mov.l @r12, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r13, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathC_edge23_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_F, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge23_done
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathC_edge23_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_F, r3
    cmp/gt r3, r2
    bt      .L_pathC_edge23_done
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathC_edge23_done:
    bra     .L_check_convergence
    nop
_wpool_x_upper_F:
    .2byte  0x0195
_wpool_y_upper_F:
    .2byte  0x0131
.L_pathD_check:
    mov.l @(32, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_pathD_vtx3_anchor
    bra     .L_check_convergence
    nop
.L_pathD_vtx3_anchor:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_pathD_edge30_done
    mov.l @r4, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r11, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathD_edge30_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_G, r3
    cmp/gt r3, r2
    bt      .L_pathD_edge30_done
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathD_edge30_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_G, r3
    cmp/gt r3, r2
    bt      .L_pathD_edge30_done
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathD_edge30_done:
    mov.l @(12, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_pathD_edge31_done
    mov.l @r14, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_pathD_edge31_done
    mov.l @r15, r2
    mov.w   _wpool_x_upper_G, r3
    cmp/gt r3, r2
    bt      .L_pathD_edge31_done
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_pathD_edge31_done
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_G, r3
    cmp/gt r3, r2
    bt      .L_pathD_edge31_done
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_pathD_edge31_done:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_pathD_test_vis2
    nop
_wpool_x_upper_G:
    .2byte  0x0195
_wpool_y_upper_G:
    .2byte  0x0131
.L_pathD_test_vis2:
    bt      .L_check_convergence
    mov.l @r8, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r10, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_check_convergence
    mov.l @r15, r2
    mov.w   _wpool_x_upper_H, r3
    cmp/gt r3, r2
    bt      .L_check_convergence
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_check_convergence
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   _wpool_y_upper_H, r3
    cmp/gt r3, r2
    bt      .L_check_convergence
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_check_convergence:
    mov.l @(20, r15), r2
    mov.l @(8, r15), r1
    mov.w @r2, r3
    mov.l @(12, r15), r2
    mov.w @r2, r2
    or r2, r3
    mov.w @r1, r2
    or r2, r3
    mov.l @(16, r15), r1
    mov.w @r1, r2
    or r2, r3
    tst r3, r3
    bf      .L_not_converged
    bra     .L_epilogue
    nop
.L_not_converged:
    bra     .L_clip_loop
    nop
.L_epilogue:
    add #0x2C, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_wpool_x_upper_H:
    .2byte  0x0195
_wpool_y_upper_H:
    .2byte  0x0131
