
    .section .text.FUN_06016DD8


    .global track_vtx_builder
    .type track_vtx_builder, @function
track_vtx_builder:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x4, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_06016EDA, r0
    add r0, r15
    mov r15, r8
    mov r15, r9
    mov r15, r10
    mov.l   .L_pool_06016EDC, r14
    mov r4, r0
    add #0x1C, r8
    add #0x4C, r9
    add #0x3C, r10
    mov #0x10, r4
    mov.b r0, @(12, r15)
    mov.l   .L_pool_06016EE0, r0
    mov.l @r0, r0
    cmp/eq #0x15, r0
    bf/s    .L_extents_ready
    mov #0xC, r5
    mov #0x20, r4
    mov #0x18, r5
.L_extents_ready:
    exts.w r4, r2
    neg r2, r2
    exts.w r2, r2
    mov #0x24, r0
    mov.w r2, @(r0, r15)
    mov #0x26, r0
    mov.w r4, @(r0, r15)
    mov #0x28, r0
    mov.w r4, @(r0, r15)
    exts.w r4, r4
    neg r4, r4
    exts.w r4, r4
    mov #0x2A, r0
    mov.w r4, @(r0, r15)
    exts.w r5, r3
    neg r3, r3
    mov.w r3, @r8
    exts.w r5, r2
    neg r2, r2
    exts.w r2, r0
    mov.w r0, @(2, r8)
    mov r5, r0
    mov.w r0, @(4, r8)
    mov.w r0, @(6, r8)
    mov r15, r6
    add #0x4, r6
    mov r15, r5
    mov.b @(12, r15), r0
    mov r0, r4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    mov.l   .L_pool_06016EE4, r2
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l   .L_pool_06016EE8, r3
    add r2, r4
    jsr @r3
    mov.l @(48, r4), r4
    mov #0x0, r12
.L_corner_loop_top:
    extu.b r12, r11
    mov r15, r3
    extu.b r12, r4
    shll2 r11
    add #0x7C, r3
    shll r4
    add r11, r3
    mov.l r3, @-r15
    mov r15, r3
    mov.l @(8, r15), r5
    add #0x28, r3
    mov.l r4, @(12, r15)
    add r3, r4
    mov.l r4, @(20, r15)
    mov.w @r4, r4
    jsr @r14
    shll16 r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    mov.l @(16, r15), r4
    add r8, r4
    mov.l r4, @(28, r15)
    mov.w @r4, r4
    jsr @r14
    shll16 r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov r15, r3
    add #0x6C, r3
    add r11, r3
    mov.l r3, @-r15
    mov.l @(8, r15), r5
    mov.l @(24, r15), r4
    mov.w @r4, r4
    jsr @r14
    shll16 r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    mov.l @(24, r15), r4
    mov.w @r4, r4
    jsr @r14
    shll16 r4
    add #0x1, r12
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov r15, r3
    mov #0x0, r2
    add #0x5C, r3
    add r3, r11
    mov.l r2, @r11
    extu.b r12, r3
    cmp/ge r13, r3
    bra     .L_corner_loop_check
    nop
.L_wpool_06016EDA:
    .2byte  0xFF74                     /* -140: stack frame allocation size */
.L_pool_06016EDC:
    .4byte  fpmul                      /* 16.16 fixed-point multiply */
.L_pool_06016EE0:
    .4byte  g_game_state               /* game state variable (0-31) */
.L_pool_06016EE4:
    .4byte  sym_06084FC8               /* per-car slot data array base */
.L_pool_06016EE8:
    .4byte  sincos_pair                /* sincos_pair(angle, &sin, &cos) */
.L_corner_loop_check:
    bf      .L_corner_loop_top
    mov.b @(12, r15), r0
    mov.l   .L_pool_06016FFC, r1
    mov r0, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r1, r3
    mov.l @(44, r3), r2
    mov.l r2, @(24, r15)
    mov.l   .L_pool_06017000, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_no_angle_bias
    mov.b @(12, r15), r0
    mov r0, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_06016FFC, r1
    add r1, r3
    mov.l   .L_fp_half, r2
    mov.l @(44, r3), r1
    add r2, r1
    mov.l r1, @(44, r3)
.L_no_angle_bias:
    mov r15, r6
    mov r15, r5
    mov.b @(12, r15), r0
    mov.l   .L_pool_06016FFC, r2
    add #0x4, r6
    mov r0, r4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l   .L_pool_06017008, r3
    add r2, r4
    jsr @r3
    mov.l @(44, r4), r4
    mov #0x0, r11
.L_y_delta_loop_top:
    extu.b r11, r12
    mov r15, r3
    shll2 r12
    add #0x2C, r3
    add r12, r3
    mov.l r3, @(8, r15)
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    mov.w   DAT_06016ffa, r4
    add r15, r4
    add r12, r4
    mov.l r4, @(24, r15)
    jsr @r14
    mov.l @r4, r4
    mov.l r0, @-r15
    mov r15, r4
    mov.l @(12, r15), r5
    add #0x64, r4
    add r12, r4
    mov.l r4, @(24, r15)
    jsr @r14
    mov.l @r4, r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov r12, r3
    mov.l r0, @r2
    add r9, r3
    mov.l r3, @-r15
    mov.l @(8, r15), r5
    mov.l @(24, r15), r4
    jsr @r14
    mov.l @r4, r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    mov.l @(24, r15), r4
    jsr @r14
    mov.l @r4, r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov r12, r3
    mov r15, r2
    add r10, r3
    add #0x6C, r2
    add r12, r2
    mov.l @r2, r1
    mov.l r1, @r3
    mov.l @(8, r15), r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_y_delta_next
    extu.b r11, r12
    shll2 r12
    mov r12, r3
    add r9, r3
    mov.l r3, @(20, r15)
    mov.l r3, @-r15
    mov.l @r3, r2
    mov r15, r5
    mov.l r2, @(12, r15)
    add #0x30, r5
    add r12, r5
    mov.l r5, @(20, r15)
    mov.l @(12, r15), r4
    mov.l   .L_pool_0601700C, r2
    jsr @r2
    mov.l @r5, r5
    mov.l @(12, r15), r3
    add r3, r0
    mov.l @r15+, r3
    mov.l r0, @r3
    add r10, r12
    mov.l r12, @(20, r15)
    mov r12, r3
    mov.l @r3, r2
    mov.l r2, @(8, r15)
    mov.l @(16, r15), r5
    bra     .L_adjust_y_delta
    nop

    .global DAT_06016ffa
DAT_06016ffa:
    .2byte  0x0080                     /* 128: stack offset to X result area */
.L_pool_06016FFC:
    .4byte  sym_06084FC8               /* per-car slot data array base (dup) */
.L_pool_06017000:
    .4byte  sym_06078663               /* direction flip flag (byte) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_06017008:
    .4byte  sincos_pair                /* sincos_pair (dup pool entry) */
.L_pool_0601700C:
    .4byte  fpdiv_setup                /* 16.16 fixed-point divide */
.L_adjust_y_delta:
    mov.l @r5, r5
    mov.l   .L_pool_060170E8, r3
    jsr @r3
    mov r2, r4
    mov r0, r1
    mov.l   .L_pool_060170EC, r2
    jsr @r2
    mov #0x6, r0
    mov.l @(8, r15), r3
    sub r0, r3
    mov.l r3, @r12
.L_y_delta_next:
    add #0x1, r11
    extu.b r11, r3
    cmp/ge r13, r3
    bf      .L_y_delta_loop_top
    mov.b @(12, r15), r0
    mov.l   .L_pool_060170F0, r1
    mov r0, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l @(24, r15), r2
    add r1, r3
    mov.l r2, @(44, r3)
    mov.b @(12, r15), r0
    mov r0, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_060170F4, r1
    add r1, r3
    add #0x8, r3
    mov.l r3, @(16, r15)
    mov #0x0, r11
    mov.b @(12, r15), r0
    mov r0, r12
    extu.b r12, r12
    mov r12, r2
    shll2 r12
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r12
    exts.w r12, r12
    mov.l   .L_pool_060170F0, r1
    add r1, r12
.L_screen_vtx_loop_top:
    extu.b r11, r3
    extu.b r11, r0
    mov.l @(16, r15), r2
    shll r3
    shll2 r0
    shll r3
    add r2, r3
    mov.l r3, @(12, r15)
    mov.l r3, @-r15
    mov.l @(12, r12), r5
    mov.l r0, @(12, r15)
    jsr @r14
    mov.l @(r0, r9), r4
    mov.l @(4, r12), r4
    mov.l   .L_pool_060170F8, r3
    jsr @r3
    add r0, r4
    exts.w r0, r0
    mov.l @r15+, r2
    mov.w r0, @r2
    mov.l @(12, r15), r3
    add #0x2, r3
    mov.l r3, @-r15
    mov.l @(12, r12), r5
    mov.l @(12, r15), r4
    add r10, r4
    jsr @r14
    mov.l @r4, r4
    mov.l @(8, r12), r4
    mov.l   .L_pool_060170F8, r3
    jsr @r3
    add r0, r4
    exts.w r0, r0
    add #0x1, r11
    mov.l @r15+, r2
    extu.b r11, r3
    mov.w r0, @r2
    cmp/ge r13, r3
    bf      .L_screen_vtx_loop_top
    mov.w   .L_wpool_060170E4, r1
    add r1, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_060170E4:
    .2byte  0x008C                     /* +140: stack frame deallocation size */
    .2byte  0xFFFF                     /* padding to 4-byte alignment */
.L_pool_060170E8:
    .4byte  fpdiv_setup                /* 16.16 fixed-point divide (dup) */
.L_pool_060170EC:
    .4byte  sym_06034FE0               /* geometry transform helper */
.L_pool_060170F0:
    .4byte  sym_06084FC8               /* per-car slot data array base (dup) */
.L_pool_060170F4:
    .4byte  sym_06085490               /* per-car vertex output table */
.L_pool_060170F8:
    .4byte  swap_sign_ext              /* swap.w + exts.w (>>16 with sign) */
