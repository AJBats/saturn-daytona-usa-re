
    .section .text.FUN_06029740


    .global mega_render_func
    .type mega_render_func, @function
mega_render_func:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_fp_interp_high, r1
    mov.l   .L_fp_interp_low, r2
    mov.l   .L_clip_threshold_ptr, r14
    mov.l @r14, r14
    mov r5, r12
    mov.w @(2, r12), r0
    mov.w r0, @(2, r15)
    mov.w @(4, r12), r0
    mov.w r0, @(4, r15)
    mov.w @(6, r12), r0
    mov.w r0, @(6, r15)
    mov.w @r12, r0
    mov.w r0, @r15
.L_interp_loop:
    cmp/eq #0x0, r0
    bt      .L_mode_a_dispatch
    bra     .L_modeB_dispatch
    mov.w @(2, r15), r0
.L_fp_interp_high:
    .4byte  0x0000E666
.L_fp_interp_low:
    .4byte  0x00001999
.L_clip_threshold_ptr:
    .4byte  sym_06063F08
.L_mode_a_dispatch:
    mov.w @(2, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeA_axis1_done
    mov.l @(0, r4), r7
    dmuls.l r7, r2
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/gt r14, r9
    bf      .L_modeA_axis1_done
    mov.w r0, @(2, r12)
.L_modeA_axis1_done:
    mov.w @(4, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeA_axis2_done
    mov.l @(0, r4), r7
    dmuls.l r7, r2
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/gt r14, r9
    bf      .L_modeA_axis2_done
    mov.w r0, @(4, r12)
.L_modeA_axis2_done:
    mov.w @(6, r12), r0
    cmp/eq #0x0, r0
    bf      .L_modeA_blend_axis3
    bra     .L_interp_done
    nop
.L_modeA_blend_axis3:
    mov.l @(0, r4), r7
    dmuls.l r7, r2
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/gt r14, r9
    bt      .L_modeA_axis3_converged
    bra     .L_interp_done
    nop
.L_modeA_axis3_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)
    bra     .L_interp_done
    nop
.L_modeB_dispatch:
    cmp/eq #0x0, r0
    bt      .L_modeB_entry
    bra     .L_modeC_dispatch
    mov.w @(4, r15), r0
.L_modeB_entry:
    mov.w @(0, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeB_axis0_done
    mov.l @(12, r4), r7
    dmuls.l r7, r2
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/gt r14, r9
    bf      .L_modeB_axis0_done
    mov.w r0, @(0, r12)
.L_modeB_axis0_done:
    mov.w @(4, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeB_axis1_done
    mov.l @(12, r4), r7
    dmuls.l r7, r2
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/gt r14, r9
    bf      .L_modeB_axis1_done
    mov.w r0, @(4, r12)
.L_modeB_axis1_done:
    mov.w @(6, r12), r0
    cmp/eq #0x0, r0
    bf      .L_modeB_blend_axis2
    bra     .L_interp_done
    nop
.L_modeB_blend_axis2:
    mov.l @(12, r4), r7
    dmuls.l r7, r2
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/gt r14, r9
    bt      .L_modeB_axis2_converged
    bra     .L_interp_done
    nop
.L_modeB_axis2_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)
    bra     .L_interp_done
    nop
.L_modeC_dispatch:
    cmp/eq #0x0, r0
    bt      .L_modeC_entry
    bra     .L_modeD_entry
    mov.w @(0, r12), r0
.L_modeC_entry:
    mov.w @(0, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeC_axis0_done
    mov.l @(24, r4), r7
    dmuls.l r7, r2
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/gt r14, r9
    bf      .L_modeC_axis0_done
    mov.w r0, @(0, r12)
.L_modeC_axis0_done:
    mov.w @(2, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeC_axis1_done
    mov.l @(24, r4), r7
    dmuls.l r7, r2
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/gt r14, r9
    bf      .L_modeC_axis1_done
    mov.w r0, @(2, r12)
.L_modeC_axis1_done:
    mov.w @(6, r12), r0
    cmp/eq #0x0, r0
    bf      .L_modeC_blend_axis2
    bra     .L_interp_done
    nop
.L_modeC_blend_axis2:
    mov.l @(24, r4), r7
    dmuls.l r7, r2
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/gt r14, r9
    bt      .L_modeC_axis2_converged
    bra     .L_interp_done
    nop
.L_modeC_axis2_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)
    bra     .L_interp_done
    nop
.L_modeD_entry:
    cmp/eq #0x0, r0
    bt      .L_modeD_axis0_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/gt r14, r9
    bf      .L_modeD_axis0_done
    mov.w r0, @(0, r12)
.L_modeD_axis0_done:
    mov.w @(2, r12), r0
    cmp/eq #0x0, r0
    bt      .L_modeD_axis1_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/gt r14, r9
    bf      .L_modeD_axis1_done
    mov.w r0, @(2, r12)
.L_modeD_axis1_done:
    mov.w @(4, r12), r0
    cmp/eq #0x0, r0
    bt      .L_interp_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r2
    add r8, r9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1
    xtrct r7, r8
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/gt r14, r9
    bf      .L_interp_done
    mov.w r0, @(4, r12)
.L_interp_done:
    mov.w @r12, r7
    mov.w @(2, r12), r0
    add r0, r7
    mov.w @(4, r12), r0
    add r0, r7
    mov.w @(6, r12), r0
    add r7, r0
    cmp/eq #0x0, r0
    bt      .L_return_interp
    bra     .L_interp_loop
    mov.w @r15, r0
.L_return_interp:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14

    .global sym_06029BF4
sym_06029BF4:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov.l   .L_clip_threshold_a, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    mov r5, r3
    mov r6, r13
    sts macl, r0
    add r0, r8
.L_transform_loop_a:
    mov.l r3, @-r15
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_render_enable_flag, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0
    bt      .L_begin_transform_a
    mov.w @(14, r8), r0
    mov.w   DAT_06029c2e, r1
    cmp/eq r0, r1
    bf      .L_begin_transform_a
    bra     .L_skip_polygon_a
    nop

    .global DAT_06029c2e
DAT_06029c2e:
    .2byte  0x0097
.L_clip_threshold_a:
    .4byte  sym_06063F08
.L_render_enable_flag:
    .4byte  sym_0605BE36
.L_begin_transform_a:
    mov.w @(16, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_a, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_camera_matrix, r0
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
    mov.l   .L_depth_result_a, r11
    .word 0x0029
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_passA_backface_ok
    mov.l   .L_backface_scratch_a, r5
    mov r8, r4
    mov.l   .L_camera_matrix, r0
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
    mov.l   .L_vertex_out_a, r4
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0
    bt      .L_passA_backface_ok
    bra     .L_skip_polygon_a
    nop
    .2byte  0x0000
.L_vertex_out_a:
    .4byte  sym_0608A70C
.L_camera_matrix:
    .4byte  sym_06089EDC
.L_depth_result_a:
    .4byte  sym_0608A704
.L_backface_scratch_a:
    .4byte  sym_0608A73C
.L_passA_backface_ok:
    mov.w @(18, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_b, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_camera_matrix_b, r0
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
    .word 0x0029
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_c, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_camera_matrix_b, r0
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
    .word 0x0029
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_d, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_camera_matrix_b, r0
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
    .word 0x0029
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0
    add r3, r0
    cmp/eq #0x0, r0
    bt      .L_passA_write_sprite
    cmp/eq #0x4, r0
    bf      .L_passA_clip_dispatch
    bra     .L_skip_polygon_a
    nop
    .2byte  0x0000
.L_vertex_out_b:
    .4byte  sym_0608A718
.L_camera_matrix_b:
    .4byte  sym_06089EDC
.L_vertex_out_c:
    .4byte  sym_0608A724
.L_vertex_out_d:
    .4byte  sym_0608A730
.L_passA_clip_dispatch:
    mov.l   .L_pipeline_a_table, r1
    shll2 r0
    add r1, r0
    mov.l @r0, r0
    mov.l   .L_vertex_data_a, r4
    mov.l   .L_depth_data_a, r5
    jsr @r0
    nop
.L_passA_write_sprite:
    mov.l   .L_commit_count, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_sprite_data_table, r2
    mov.l   .L_poly_params_a, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_vertex_data_a, r4
    mov r11, r5
    mov.w   DAT_06029ea4, r1
    mov.w   DAT_06029ea6, r0
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
    mov.l   .L_render_state_a, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_screen_width_a, r3
    cmp/gt r3, r1
    bf      .L_passA_v0_chk_left
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ea4
DAT_06029ea4:
    .2byte  0xFF00

    .global DAT_06029ea6
DAT_06029ea6:
    .2byte  0x00A0
.L_screen_width_a:
    .2byte  0x0190
    .2byte  0x0000
.L_pipeline_a_table:
    .4byte  sym_0602A1E0
.L_vertex_data_a:
    .4byte  sym_0608A70C
.L_depth_data_a:
    .4byte  sym_0608A704
.L_commit_count:
    .4byte  sym_060620D0
.L_sprite_data_table:
    .4byte  sym_0608AC20
.L_poly_params_a:
    .4byte  sym_0608A76C
.L_render_state_a:
    .4byte  sym_0608A6FC
.L_passA_v0_chk_left:
    mov.w   DAT_06029ed4, r3
    cmp/gt r1, r3
    bf      .L_passA_v0_chk_top
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ed4
DAT_06029ed4:
    .2byte  0xFE70
.L_passA_v0_chk_top:
    mov.w   DAT_06029ee2, r3
    cmp/gt r3, r2
    bf      .L_passA_v0_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ee2
DAT_06029ee2:
    .2byte  0x012C
.L_passA_v0_chk_bottom:
    mov.w   DAT_06029f2a, r3
    cmp/gt r2, r3
    bf      .L_passA_v0_bounds_done
    mov #0x1, r0
    mov.w r0, @r12
.L_passA_v0_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_06029f2c, r1
    mov.w   DAT_06029f2e, r0
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
    mov.w   DAT_06029f30, r3
    cmp/gt r3, r1
    bf      .L_passA_v1_chk_left
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f2a
DAT_06029f2a:
    .2byte  0xFE70

    .global DAT_06029f2c
DAT_06029f2c:
    .2byte  0xFF00

    .global DAT_06029f2e
DAT_06029f2e:
    .2byte  0x00A0

    .global DAT_06029f30
DAT_06029f30:
    .2byte  0x0190
.L_passA_v1_chk_left:
    mov.w   DAT_06029f3e, r3
    cmp/gt r1, r3
    bf      .L_passA_v1_chk_top
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f3e
DAT_06029f3e:
    .2byte  0xFE70
.L_passA_v1_chk_top:
    mov.w   DAT_06029f4c, r3
    cmp/gt r3, r2
    bf      .L_passA_v1_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f4c
DAT_06029f4c:
    .2byte  0x012C
.L_passA_v1_chk_bottom:
    mov.w   DAT_06029f94, r3
    cmp/gt r2, r3
    bf      .L_passA_v1_bounds_done
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_passA_v1_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_06029f96, r1
    mov.w   DAT_06029f98, r0
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
    mov.w   DAT_06029f9a, r3
    cmp/gt r3, r1
    bf      .L_passA_v2_chk_left
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029f94
DAT_06029f94:
    .2byte  0xFE70

    .global DAT_06029f96
DAT_06029f96:
    .2byte  0xFF00

    .global DAT_06029f98
DAT_06029f98:
    .2byte  0x00A0

    .global DAT_06029f9a
DAT_06029f9a:
    .2byte  0x0190
.L_passA_v2_chk_left:
    mov.w   DAT_06029fa8, r3
    cmp/gt r1, r3
    bf      .L_passA_v2_chk_top
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029fa8
DAT_06029fa8:
    .2byte  0xFE70
.L_passA_v2_chk_top:
    mov.w   DAT_06029fb6, r3
    cmp/gt r3, r2
    bf      .L_passA_v2_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029fb6
DAT_06029fb6:
    .2byte  0x012C
.L_passA_v2_chk_bottom:
    mov.w   DAT_06029ffe, r3
    cmp/gt r2, r3
    bf      .L_passA_v2_bounds_done
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_passA_v2_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602a000, r1
    mov.w   DAT_0602a002, r0
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
    mov.w   DAT_0602a004, r3
    cmp/gt r3, r1
    bf      .L_passA_v3_chk_left
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_06029ffe
DAT_06029ffe:
    .2byte  0xFE70

    .global DAT_0602a000
DAT_0602a000:
    .2byte  0xFF00

    .global DAT_0602a002
DAT_0602a002:
    .2byte  0x00A0

    .global DAT_0602a004
DAT_0602a004:
    .2byte  0x0190
.L_passA_v3_chk_left:
    mov.w   DAT_0602a012, r3
    cmp/gt r1, r3
    bf      .L_passA_v3_chk_top
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a012
DAT_0602a012:
    .2byte  0xFE70
.L_passA_v3_chk_top:
    mov.w   DAT_0602a020, r3
    cmp/gt r3, r2
    bf      .L_passA_v3_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a020
DAT_0602a020:
    .2byte  0x012C
.L_passA_v3_chk_bottom:
    mov.w   DAT_0602a050, r3
    cmp/gt r2, r3
    bf      .L_passA_v3_bounds_done
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_passA_v3_bounds_done:
    mov.l   .L_sh2_periph_0x150, r4
    mov.l   .L_scale_constant_a, r5
    mov.l   .L_sh2_periph_0x181, r6
    mov.l   .L_poly_limit_a, r7
    mov.l @r11, r0
    cmp/gt r0, r4
    bf      .L_passA_frustum_right
    mov.l @(8, r11), r0
    cmp/gt r0, r4
    bf      .L_passA_frustum_right
    mov.l @(16, r11), r0
    cmp/gt r0, r4
    bf      .L_passA_frustum_right
    mov.l @(24, r11), r0
    cmp/gt r0, r4
    bf      .L_passA_frustum_right
    bra     .L_skip_polygon_a
    nop

    .global DAT_0602a050
DAT_0602a050:
    .2byte  0xFE70
    .2byte  0x0000
.L_sh2_periph_0x150:
    .4byte  0xFFFFFF50                  /* SH-2 peripheral +0x150 */
.L_scale_constant_a:
    .4byte  0x000000B0
.L_sh2_periph_0x181:
    .4byte  0xFFFFFF81                  /* SH-2 peripheral +0x181 */
.L_poly_limit_a:
    .4byte  0x00000051
.L_passA_frustum_right:
    mov.l @r11, r0
    cmp/gt r0, r5
    bt      .L_passA_frustum_top
    mov.l @(8, r11), r0
    cmp/gt r0, r5
    bt      .L_passA_frustum_top
    mov.l @(16, r11), r0
    cmp/gt r0, r5
    bt      .L_passA_frustum_top
    mov.l @(24, r11), r0
    cmp/gt r0, r5
    bt      .L_passA_frustum_top
    bra     .L_skip_polygon_a
    nop
.L_passA_frustum_top:
    mov.l @(4, r11), r0
    cmp/gt r0, r6
    bf      .L_passA_frustum_bottom
    mov.l @(12, r11), r0
    cmp/gt r0, r6
    bf      .L_passA_frustum_bottom
    mov.l @(20, r11), r0
    cmp/gt r0, r6
    bf      .L_passA_frustum_bottom
    mov.l @(28, r11), r0
    cmp/gt r0, r6
    bf      .L_passA_frustum_bottom
    bra     .L_skip_polygon_a
    nop
.L_passA_frustum_bottom:
    mov.l @(4, r11), r0
    cmp/gt r0, r7
    bt      .L_passA_frustum_pass
    mov.l @(12, r11), r0
    cmp/gt r0, r7
    bt      .L_passA_frustum_pass
    mov.l @(20, r11), r0
    cmp/gt r0, r7
    bt      .L_passA_frustum_pass
    mov.l @(28, r11), r0
    cmp/gt r0, r7
    bt      .L_passA_frustum_pass
    bra     .L_skip_polygon_a
    nop
.L_passA_frustum_pass:
    mov.w @r12, r1
    mov.w @(2, r12), r0
    add r0, r1
    mov.w @(4, r12), r0
    add r0, r1
    mov.w @(6, r12), r0
    add r1, r0
    cmp/eq #0x4, r0
    bf      .L_passA_partial_clip
    bra     .L_skip_polygon_a
    nop
.L_passA_partial_clip:
    cmp/eq #0x0, r0
    bt      .L_passA_emit_quad
    mov r11, r4
    shll2 r0
    mov.l   .L_pipeline_a_sub, r1
    add r1, r0
    mov.l @r0, r0
    jsr @r0
    mov r12, r5
.L_passA_emit_quad:
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
    mov.l   .L_pipeline_a_sub2, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l   .L_vertex_data_a2, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0
    mov.l @(44, r1), r6
.L_pipeline_a_sub:
    .4byte  sym_0602A1F0
.L_pipeline_a_sub2:
    .4byte  sym_0602A200
.L_vertex_data_a2:
    .4byte  sym_0608A70C

    .global loc_0602A134
loc_0602A134:
    add r4, r3
    add r5, r6
    add r6, r3
    shlr2 r3
    bra     .L_passA_zsort_commit
    nop

    .global loc_0602A140
loc_0602A140:
    cmp/ge r3, r4
    bt      .L_depthA_min_ge_1
    mov r4, r3
.L_depthA_min_ge_1:
    cmp/ge r3, r5
    bt      .L_depthA_min_ge_2
    mov r5, r3
.L_depthA_min_ge_2:
    cmp/ge r3, r6
    bt      .L_depthA_min_ge_done
    mov r6, r3
.L_depthA_min_ge_done:
    bra     .L_passA_zsort_commit
    nop

    .global loc_0602A156
loc_0602A156:
    cmp/gt r3, r4
    bf      .L_depthA_min_gt_1
    mov r4, r3
.L_depthA_min_gt_1:
    cmp/gt r3, r5
    bf      .L_depthA_min_gt_2
    mov r5, r3
.L_depthA_min_gt_2:
    cmp/gt r3, r6
    bf      .L_depthA_min_gt_done
    mov r6, r3
.L_depthA_min_gt_done:
    bra     .L_passA_zsort_commit
    nop

    .global loc_0602A16C
loc_0602A16C:
    mov.l   .L_fp_depth_bias_a, r0
    cmp/gt r3, r4
    bf      .L_depthA_bias_min_1
    mov r4, r3
.L_depthA_bias_min_1:
    cmp/gt r3, r5
    bf      .L_depthA_bias_min_2
    mov r5, r3
.L_depthA_bias_min_2:
    cmp/gt r3, r6
    bf      .L_depthA_bias_min_done
    mov r6, r3
.L_depthA_bias_min_done:
    bra     .L_passA_zsort_commit
    add r0, r3
.L_fp_depth_bias_a:
    .4byte  0x000B8000

    .global loc_0602A188
loc_0602A188:
    mov.l   .L_fp_one, r0
    cmp/gt r3, r4
    bf      .L_depthA_offset_min_1
    mov r4, r3
.L_depthA_offset_min_1:
    cmp/gt r3, r5
    bf      .L_depthA_offset_min_2
    mov r5, r3
.L_depthA_offset_min_2:
    cmp/gt r3, r6
    bf      .L_depthA_offset_min_done
    mov r6, r3
.L_depthA_offset_min_done:
    add r0, r3
.L_passA_zsort_commit:
    mov.l   .L_commit_count_2, r2
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
.L_skip_polygon_a:
    mov.l @r15+, r7
    mov.l @r15+, r3
    dt r7
    bt      .L_passA_epilogue
    bra     .L_transform_loop_a
    nop
    .2byte  0x0000
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_commit_count_2:
    .4byte  sym_060620D0
.L_sprite_index_table:
    .4byte  sym_0606A4F8
.L_passA_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8

    .global sym_0602A1E0
sym_0602A1E0:
    .word 0x0000
    .word 0x0000
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602A1F0
sym_0602A1F0:
    .word 0x0000
    .word 0x0000
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602A200
sym_0602A200:
    .4byte  loc_0602A134
    .4byte  loc_0602A140
    .4byte  loc_0602A156
    .4byte  loc_0602A188
    .4byte  loc_0602A16C

    .global sym_0602A214
sym_0602A214:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov.l   .L_clip_threshold_b, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    mov r5, r3
    mov r6, r13
    sts macl, r0
    add r0, r8
.L_transform_loop_b:
    mov.l r3, @-r15
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_render_enable_b, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0
    bt      .L_passB_begin_transform
    mov.w @(14, r8), r0
    mov.w   DAT_0602a24e, r1
    cmp/eq r0, r1
    bf      .L_passB_begin_transform
    bra     .L_skip_polygon_b
    nop

    .global DAT_0602a24e
DAT_0602a24e:
    .2byte  0x0097
.L_clip_threshold_b:
    .4byte  sym_06063F08
.L_render_enable_b:
    .4byte  sym_0605BE36
.L_passB_begin_transform:
    mov.w @(16, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_e, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_render_budget_a, r0
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
    mov.l   .L_depth_result_b, r11
    .word 0x0029
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_passB_backface_ok
    mov.l   .L_backface_scratch_b, r5
    mov r8, r4
    mov.l   .L_render_budget_a, r0
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
    mov.l   .L_vertex_out_e, r4
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0
    bt      .L_passB_backface_ok
    bra     .L_skip_polygon_b
    nop
    .2byte  0x0000
.L_vertex_out_e:
    .4byte  sym_0608A7A0
.L_render_budget_a:
    .4byte  sym_0608A52C
.L_depth_result_b:
    .4byte  sym_0608A798
.L_backface_scratch_b:
    .4byte  sym_0608A7D0
.L_passB_backface_ok:
    mov.w @(18, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_f, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_render_budget_b, r0
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
    .word 0x0029
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_g, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_render_budget_b, r0
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
    .word 0x0029
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0xC, r1
    extu.w r0, r4
    mul.l r1, r4
    mov.l   .L_vertex_out_h, r5
    sts macl, r4
    add r3, r4
    mov.l   .L_render_budget_b, r0
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
    .word 0x0029
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0
    add r3, r0
    cmp/eq #0x0, r0
    bt      .L_passB_write_sprite
    cmp/eq #0x4, r0
    bf      .L_passB_clip_dispatch
    bra     .L_skip_polygon_b
    nop
    .2byte  0x0000
.L_vertex_out_f:
    .4byte  sym_0608A7AC
.L_render_budget_b:
    .4byte  sym_0608A52C
.L_vertex_out_g:
    .4byte  sym_0608A7B8
.L_vertex_out_h:
    .4byte  sym_0608A7C4
.L_passB_clip_dispatch:
    mov.l   .L_pipeline_b_table, r1
    shll2 r0
    add r1, r0
    mov.l @r0, r0
    mov.l   .L_vertex_data_e, r4
    mov.l   .L_depth_data_b, r5
    jsr @r0
    nop
.L_passB_write_sprite:
    mov.l   .L_frame_counter, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_sprite_data_b, r2
    mov.l   .L_poly_params_b, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_vertex_data_e, r4
    mov r11, r5
    mov.w   DAT_0602a4c4, r1
    mov.w   DAT_0602a4c6, r0
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
    mov.l   .L_render_state_b, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_screen_width_b, r3
    cmp/gt r3, r1
    bf      .L_passB_v0_chk_left
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a4c4
DAT_0602a4c4:
    .2byte  0xFF00

    .global DAT_0602a4c6
DAT_0602a4c6:
    .2byte  0x00A0
.L_screen_width_b:
    .2byte  0x0190
    .2byte  0x0000
.L_pipeline_b_table:
    .4byte  sym_0602A800
.L_vertex_data_e:
    .4byte  sym_0608A7A0
.L_depth_data_b:
    .4byte  sym_0608A798
.L_frame_counter:
    .4byte  sym_060620D4
.L_sprite_data_b:
    .4byte  sym_0608AC20
.L_poly_params_b:
    .4byte  sym_0608A800
.L_render_state_b:
    .4byte  sym_0608A790
.L_passB_v0_chk_left:
    mov.w   DAT_0602a4f4, r3
    cmp/gt r1, r3
    bf      .L_passB_v0_chk_top
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a4f4
DAT_0602a4f4:
    .2byte  0xFE70
.L_passB_v0_chk_top:
    mov.w   DAT_0602a502, r3
    cmp/gt r3, r2
    bf      .L_passB_v0_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a502
DAT_0602a502:
    .2byte  0x012C
.L_passB_v0_chk_bottom:
    mov.w   DAT_0602a54a, r3
    cmp/gt r2, r3
    bf      .L_passB_v0_bounds_done
    mov #0x1, r0
    mov.w r0, @r12
.L_passB_v0_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_0602a54c, r1
    mov.w   DAT_0602a54e, r0
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
    mov.w   DAT_0602a550, r3
    cmp/gt r3, r1
    bf      .L_passB_v1_chk_left
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a54a
DAT_0602a54a:
    .2byte  0xFE70

    .global DAT_0602a54c
DAT_0602a54c:
    .2byte  0xFF00

    .global DAT_0602a54e
DAT_0602a54e:
    .2byte  0x00A0

    .global DAT_0602a550
DAT_0602a550:
    .2byte  0x0190
.L_passB_v1_chk_left:
    mov.w   DAT_0602a55e, r3
    cmp/gt r1, r3
    bf      .L_passB_v1_chk_top
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a55e
DAT_0602a55e:
    .2byte  0xFE70
.L_passB_v1_chk_top:
    mov.w   DAT_0602a56c, r3
    cmp/gt r3, r2
    bf      .L_passB_v1_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a56c
DAT_0602a56c:
    .2byte  0x012C
.L_passB_v1_chk_bottom:
    mov.w   DAT_0602a5b4, r3
    cmp/gt r2, r3
    bf      .L_passB_v1_bounds_done
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_passB_v1_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_0602a5b6, r1
    mov.w   DAT_0602a5b8, r0
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
    mov.w   DAT_0602a5ba, r3
    cmp/gt r3, r1
    bf      .L_passB_v2_chk_left
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5b4
DAT_0602a5b4:
    .2byte  0xFE70

    .global DAT_0602a5b6
DAT_0602a5b6:
    .2byte  0xFF00

    .global DAT_0602a5b8
DAT_0602a5b8:
    .2byte  0x00A0

    .global DAT_0602a5ba
DAT_0602a5ba:
    .2byte  0x0190
.L_passB_v2_chk_left:
    mov.w   DAT_0602a5c8, r3
    cmp/gt r1, r3
    bf      .L_passB_v2_chk_top
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5c8
DAT_0602a5c8:
    .2byte  0xFE70
.L_passB_v2_chk_top:
    mov.w   DAT_0602a5d6, r3
    cmp/gt r3, r2
    bf      .L_passB_v2_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5d6
DAT_0602a5d6:
    .2byte  0x012C
.L_passB_v2_chk_bottom:
    mov.w   DAT_0602a61e, r3
    cmp/gt r2, r3
    bf      .L_passB_v2_bounds_done
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_passB_v2_bounds_done:
    mov r11, r5
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602a620, r1
    mov.w   DAT_0602a622, r0
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
    mov.w   DAT_0602a624, r3
    cmp/gt r3, r1
    bf      .L_passB_v3_chk_left
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a61e
DAT_0602a61e:
    .2byte  0xFE70

    .global DAT_0602a620
DAT_0602a620:
    .2byte  0xFF00

    .global DAT_0602a622
DAT_0602a622:
    .2byte  0x00A0

    .global DAT_0602a624
DAT_0602a624:
    .2byte  0x0190
.L_passB_v3_chk_left:
    mov.w   DAT_0602a632, r3
    cmp/gt r1, r3
    bf      .L_passB_v3_chk_top
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a632
DAT_0602a632:
    .2byte  0xFE70
.L_passB_v3_chk_top:
    mov.w   DAT_0602a640, r3
    cmp/gt r3, r2
    bf      .L_passB_v3_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a640
DAT_0602a640:
    .2byte  0x012C
.L_passB_v3_chk_bottom:
    mov.w   DAT_0602a670, r3
    cmp/gt r2, r3
    bf      .L_passB_v3_bounds_done
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_passB_v3_bounds_done:
    mov.l   .L_sh2_periph_0x150_0602A674, r4
    mov.l   .L_scale_constant_b, r5
    mov.l   .L_sh2_periph_0x181_0602A67C, r6
    mov.l   .L_poly_limit_b, r7
    mov.l @r11, r0
    cmp/gt r0, r4
    bf      .L_passB_frustum_right
    mov.l @(8, r11), r0
    cmp/gt r0, r4
    bf      .L_passB_frustum_right
    mov.l @(16, r11), r0
    cmp/gt r0, r4
    bf      .L_passB_frustum_right
    mov.l @(24, r11), r0
    cmp/gt r0, r4
    bf      .L_passB_frustum_right
    bra     .L_skip_polygon_b
    nop

    .global DAT_0602a670
DAT_0602a670:
    .2byte  0xFE70
    .2byte  0x0000
.L_sh2_periph_0x150_0602A674:
    .4byte  0xFFFFFF50                  /* SH-2 peripheral +0x150 */
.L_scale_constant_b:
    .4byte  0x000000B0
.L_sh2_periph_0x181_0602A67C:
    .4byte  0xFFFFFF81                  /* SH-2 peripheral +0x181 */
.L_poly_limit_b:
    .4byte  0x00000051
.L_passB_frustum_right:
    mov.l @r11, r0
    cmp/gt r0, r5
    bt      .L_passB_frustum_top
    mov.l @(8, r11), r0
    cmp/gt r0, r5
    bt      .L_passB_frustum_top
    mov.l @(16, r11), r0
    cmp/gt r0, r5
    bt      .L_passB_frustum_top
    mov.l @(24, r11), r0
    cmp/gt r0, r5
    bt      .L_passB_frustum_top
    bra     .L_skip_polygon_b
    nop
.L_passB_frustum_top:
    mov.l @(4, r11), r0
    cmp/gt r0, r6
    bf      .L_passB_frustum_bottom
    mov.l @(12, r11), r0
    cmp/gt r0, r6
    bf      .L_passB_frustum_bottom
    mov.l @(20, r11), r0
    cmp/gt r0, r6
    bf      .L_passB_frustum_bottom
    mov.l @(28, r11), r0
    cmp/gt r0, r6
    bf      .L_passB_frustum_bottom
    bra     .L_skip_polygon_b
    nop
.L_passB_frustum_bottom:
    mov.l @(4, r11), r0
    cmp/gt r0, r7
    bt      .L_passB_frustum_pass
    mov.l @(12, r11), r0
    cmp/gt r0, r7
    bt      .L_passB_frustum_pass
    mov.l @(20, r11), r0
    cmp/gt r0, r7
    bt      .L_passB_frustum_pass
    mov.l @(28, r11), r0
    cmp/gt r0, r7
    bt      .L_passB_frustum_pass
    bra     .L_skip_polygon_b
    nop
.L_passB_frustum_pass:
    mov.w @r12, r1
    mov.w @(2, r12), r0
    add r0, r1
    mov.w @(4, r12), r0
    add r0, r1
    mov.w @(6, r12), r0
    add r1, r0
    cmp/eq #0x4, r0
    bf      .L_passB_partial_clip
    bra     .L_skip_polygon_b
    nop
.L_passB_partial_clip:
    cmp/eq #0x0, r0
    bt      .L_passB_emit_quad
    mov r11, r4
    shll2 r0
    mov.l   .L_pipeline_b_sub, r1
    add r1, r0
    mov.l @r0, r0
    jsr @r0
    mov r12, r5
.L_passB_emit_quad:
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
    mov.l   .L_pipeline_b_sub2, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l   .L_vertex_data_e2, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0
    mov.l @(44, r1), r6
.L_pipeline_b_sub:
    .4byte  sym_0602A810
.L_pipeline_b_sub2:
    .4byte  sym_0602A820
.L_vertex_data_e2:
    .4byte  sym_0608A7A0

    .global loc_0602A754
loc_0602A754:
    add r4, r3
    add r5, r6
    add r6, r3
    shlr2 r3
    bra     .L_passB_zsort_commit
    nop

    .global loc_0602A760
loc_0602A760:
    cmp/ge r3, r4
    bt      .L_depthB_min_ge_1
    mov r4, r3
.L_depthB_min_ge_1:
    cmp/ge r3, r5
    bt      .L_depthB_min_ge_2
    mov r5, r3
.L_depthB_min_ge_2:
    cmp/ge r3, r6
    bt      .L_depthB_min_ge_done
    mov r6, r3
.L_depthB_min_ge_done:
    bra     .L_passB_zsort_commit
    nop

    .global loc_0602A776
loc_0602A776:
    cmp/gt r3, r4
    bf      .L_depthB_min_gt_1
    mov r4, r3
.L_depthB_min_gt_1:
    cmp/gt r3, r5
    bf      .L_depthB_min_gt_2
    mov r5, r3
.L_depthB_min_gt_2:
    cmp/gt r3, r6
    bf      .L_depthB_min_gt_done
    mov r6, r3
.L_depthB_min_gt_done:
    bra     .L_passB_zsort_commit
    nop

    .global loc_0602A78C
loc_0602A78C:
    mov.l   .L_fp_depth_bias_b, r0
    cmp/gt r3, r4
    bf      .L_depthB_bias_min_1
    mov r4, r3
.L_depthB_bias_min_1:
    cmp/gt r3, r5
    bf      .L_depthB_bias_min_2
    mov r5, r3
.L_depthB_bias_min_2:
    cmp/gt r3, r6
    bf      .L_depthB_bias_min_done
    mov r6, r3
.L_depthB_bias_min_done:
    bra     .L_passB_zsort_commit
    add r0, r3
.L_fp_depth_bias_b:
    .4byte  0x000B8000

    .global loc_0602A7A8
loc_0602A7A8:
    mov.l   .L_fp_one_0602A7E4, r0
    cmp/gt r3, r4
    bf      .L_depthB_offset_min_1
    mov r4, r3
.L_depthB_offset_min_1:
    cmp/gt r3, r5
    bf      .L_depthB_offset_min_2
    mov r5, r3
.L_depthB_offset_min_2:
    cmp/gt r3, r6
    bf      .L_depthB_offset_min_done
    mov r6, r3
.L_depthB_offset_min_done:
    add r0, r3
.L_passB_zsort_commit:
    mov.l   .L_frame_counter_2, r2
    neg r3, r3
    mov.l   .L_sprite_idx_b, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_skip_polygon_b:
    mov.l @r15+, r7
    mov.l @r15+, r3
    dt r7
    bt      .L_return_transform
    bra     .L_transform_loop_b
    nop
    .2byte  0x0000
.L_fp_one_0602A7E4:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_frame_counter_2:
    .4byte  sym_060620D4
.L_sprite_idx_b:
    .4byte  sym_0606A4F8
.L_return_transform:
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8

    .global sym_0602A800
sym_0602A800:
    .word 0x0000
    .word 0x0000
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602A810
sym_0602A810:
    .word 0x0000
    .word 0x0000
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602A820
sym_0602A820:
    .4byte  loc_0602A754
    .4byte  loc_0602A760
    .4byte  loc_0602A776
    .4byte  loc_0602A7A8
    .4byte  loc_0602A78C

    .global sym_0602A834
sym_0602A834:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
