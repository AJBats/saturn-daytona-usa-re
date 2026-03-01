
    .section .text.FUN_06038642


    .global scene_data_write_add
    .type scene_data_write_add, @function
scene_data_write_add:
    mov.l r14, @-r15
    .byte   0xDE, 0x19    /* mov.l .L_pool_060386AF, r14 */
    .byte   0xD7, 0x1A    /* mov.l .L_pool_060386B3, r7 */
    .byte   0xD0, 0x1A    /* mov.l .L_pool_060386B7, r0 */
    bra     .L_dispatch_mode
    mov.l @r0, r0
.L_mode_04_add_pos_xy:
    mov.l @r7, r2
    add r4, r2
    mov.l r2, @r7
    mov.l @(4, r7), r3
    add r5, r3
    mov.l r3, @(4, r7)
    bra     .L_return
    nop
.L_mode_08_add_scale_xy:
    mov.l @(16, r7), r2
    add r4, r2
    mov.l r2, @(16, r7)
    mov.l @(20, r7), r3
    add r5, r3
    mov.l r3, @(20, r7)
    bra     .L_return
    nop
.L_mode_10_add_hi16_xy_a:
    shlr16 r4
    exts.w r4, r4
    mov #0x20, r0
    mov.w @(r0, r7), r2
    add r4, r2
    mov.w r2, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    mov #0x22, r0
    mov.w @(r0, r7), r3
    add r5, r3
    mov.w r3, @(r0, r7)
    bra     .L_return
    nop
.L_mode_20_add_hi16_xy_b:
    shlr16 r4
    exts.w r4, r4
    mov #0x24, r0
    mov.w @(r0, r7), r2
    add r4, r2
    mov.w r2, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    mov #0x26, r0
    mov.w @(r0, r7), r3
    add r5, r3
    mov.w r3, @(r0, r7)
    bra     .L_return
    nop
    .2byte  0xFFFF
    .4byte  scene_color_matrix
.L_pool_060386AF:
    .4byte  sym_060A4C78
.L_pool_060386B3:
    .4byte  sym_060A3DF8
.L_pool_060386B7:
    .4byte  sym_060635A8
.L_mode_01_add_view_chan1:
    .byte   0xD7, 0x2D    /* mov.l .L_pool_0603877D, r7 */
    mov #0x44, r0
    mov.l @(r0, r7), r2
    add r4, r2
    mov.l r2, @(r0, r7)
    mov #0x48, r0
    mov.l @(r0, r7), r3
    add r5, r3
    mov.l r3, @(r0, r7)
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06038781, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch1_clear_accum
    .byte   0xD3, 0x29    /* mov.l .L_pool_06038785, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch1_accum_color
    .byte   0xD3, 0x28    /* mov.l .L_pool_06038789, r3 */
    mov.l @r3, r0
    tst r0, r0
    bf      .L_ch1_clear_accum
.L_ch1_accum_color:
    mov.l @r14, r3
    add r6, r3
    mov.l r3, @r14
    bra     .L_ch1_check_tailcall
    nop
.L_ch1_clear_accum:
    mov #0x0, r2
    mov.l r2, @r14
.L_ch1_check_tailcall:
    mov.l @r14, r0
    tst r0, r0
    bt      .L_return
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603878D, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_mode_02_add_view_chan2:
    mov #0x44, r0
    .byte   0xD7, 0x1F    /* mov.l .L_pool_06038791, r7 */
    mov.l @(r0, r7), r2
    add r4, r2
    mov.l r2, @(r0, r7)
    mov #0x48, r0
    mov.l @(r0, r7), r3
    add r5, r3
    mov.l r3, @(r0, r7)
    .byte   0xD3, 0x1C    /* mov.l .L_pool_06038795, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch2_clear_accum
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06038799, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch2_accum_color
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0603879D, r3 */
    mov.l @r3, r0
    tst r0, r0
    bf      .L_ch2_clear_accum
.L_ch2_accum_color:
    mov.l @(4, r14), r3
    add r6, r3
    mov.l r3, @(4, r14)
    bra     .L_ch2_check_tailcall
    nop
.L_ch2_clear_accum:
    mov #0x0, r2
    mov.l r2, @(4, r14)
.L_ch2_check_tailcall:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_return
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    .byte   0xD3, 0x0E    /* mov.l .L_pool_0603878D, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_dispatch_mode:
    cmp/eq #0x1, r0
    bt      .L_mode_01_add_view_chan1
    cmp/eq #0x2, r0
    bt      .L_mode_02_add_view_chan2
    cmp/eq #0x4, r0
    bf      .L_check_mode_08
    bra     .L_mode_04_add_pos_xy
    nop
.L_check_mode_08:
    cmp/eq #0x8, r0
    bf      .L_check_mode_10
    bra     .L_mode_08_add_scale_xy
    nop
.L_check_mode_10:
    cmp/eq #0x10, r0
    bt      .L_mode_10_add_hi16_xy_a
    cmp/eq #0x20, r0
    bt      .L_mode_20_add_hi16_xy_b
.L_return:
    rts
    mov.l @r15+, r14
.L_pool_0603877D:
    .4byte  sym_060A3E68
.L_pool_06038781:
    .4byte  sym_060A4C44
.L_pool_06038785:
    .4byte  sym_060A4C4C
.L_pool_06038789:
    .4byte  sym_060A4C70
.L_pool_0603878D:
    .4byte  scene_color_matrix
.L_pool_06038791:
    .4byte  sym_060A3EE8
.L_pool_06038795:
    .4byte  sym_060A4C48
.L_pool_06038799:
    .4byte  sym_060A4C50
.L_pool_0603879D:
    .4byte  sym_060A4C74
