
    .section .text.FUN_06038794


    .global scene_color_intensity
    .type scene_color_intensity, @function
scene_color_intensity:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_clamp_max, r9
    mov.l   .L_fn_fpdiv, r10
    mov.w   DAT_0603881a, r11
    mov.l   .L_fp_one, r12
    mov r4, r14
    mov r5, r13
    mov.l   .L_cmd_slot_ptr, r0
    bra     .L_clamp_dispatch
    mov.l @r0, r0
.L_clamp_intensity_x:
    cmp/gt r9, r14
    bf      .L_check_x_min
    bra     .L_clamp_intensity_y
    mov r9, r14
.L_check_x_min:
    cmp/ge r11, r14
    bt      .L_check_x_zero
    bra     .L_clamp_intensity_y
    mov r11, r14
.L_check_x_zero:
    tst r14, r14
    bf      .L_clamp_intensity_y
    mov r12, r14
.L_clamp_intensity_y:
    cmp/gt r9, r13
    bf      .L_check_y_min
    bra     .L_color_process
    mov r9, r13
.L_check_y_min:
    cmp/ge r11, r13
    bt      .L_check_y_zero
    bra     .L_color_process
    mov r11, r13
.L_check_y_zero:
    tst r13, r13
    bf      .L_color_process
    mov r12, r13
.L_color_process:
    mov r14, r5
    jsr @r10
    mov r12, r4
    mov r0, r14
    mov r13, r5
    jsr @r10
    mov r12, r4
    bra     .L_store_setup
    mov r0, r13
.L_clamp_dispatch:
    cmp/eq #0x1, r0
    bt      .L_color_process
    cmp/eq #0x2, r0
    bt      .L_color_process
    cmp/eq #0x4, r0
    bt      .L_clamp_intensity_x
    cmp/eq #0x8, r0
    bt      .L_clamp_intensity_x
.L_store_setup:
    mov.l   .L_enable_flags_ptr, r6
    mov.l   .L_scene_view_a_ptr, r5
    mov.l   .L_scene_transform_ptr, r4
    mov.l   .L_cmd_slot_ptr, r0
    bra     .L_store_dispatch
    mov.l @r0, r0
.L_store_ch4:
    mov.l r14, @(8, r4)
    bra     .L_epilogue
    mov.l r13, @(12, r4)
.L_store_ch8:
    mov.l r14, @(24, r4)
    bra     .L_epilogue
    mov.l r13, @(28, r4)

    .global DAT_0603881a
DAT_0603881a:
    .2byte  0x4000                              /* 0.25 in 16.16 fixed-point (clamp floor) */
.L_clamp_max:
    .4byte  0x00FF0000                          /* 255.0 in 16.16 fp (clamp ceiling) */
.L_fn_fpdiv:
    .4byte  sym_0603C0A0                        /* fpdiv: fixed-point divide r4/r5 */
.L_fp_one:
    .4byte  0x00010000                          /* 1.0 (16.16 fixed-point) */
.L_cmd_slot_ptr:
    .4byte  sym_060635A8                        /* display cmd queue slot (channel ID) */
.L_enable_flags_ptr:
    .4byte  sym_060A3E38                        /* scene enable flags (render dirty bits) */
.L_scene_view_a_ptr:
    .4byte  sym_060A3E68                        /* scene view struct A (viewport A) */
.L_scene_transform_ptr:
    .4byte  sym_060A3DF8                        /* scene transform struct (color slots) */
.L_store_ch1:
    mov r5, r4
    mov #0x4C, r0
    mov.l r14, @(r0, r4)
    mov #0x50, r0
    mov.l r13, @(r0, r4)
    mov.w @(4, r6), r0
    extu.w r0, r0
    tst #0xFF, r0
    bt      .L_epilogue
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_scene_color_matrix, r3
    jmp @r3
    mov.l @r15+, r14
.L_store_ch2:
    mov #0x4C, r0
    mov.w   .L_scene_b_offset, r4
    add r5, r4
    mov.l r14, @(r0, r4)
    mov #0x50, r0
    mov.l r13, @(r0, r4)
    mov.w @(4, r6), r0
    mov.l   .L_scene_b_enable_mask, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_epilogue
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_scene_color_matrix, r3
    jmp @r3
    mov.l @r15+, r14
.L_store_dispatch:
    cmp/eq #0x1, r0
    bt      .L_store_ch1
    cmp/eq #0x2, r0
    bt      .L_store_ch2
    cmp/eq #0x4, r0
    bt      .L_store_ch4
    cmp/eq #0x8, r0
    bt      .L_store_ch8
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_scene_b_offset:
    .2byte  0x0080                              /* 128-byte offset: scene_view_B = view_A + 0x80 */
    .2byte  0xFFFF                              /* padding (unused) */
.L_fn_scene_color_matrix:
    .4byte  scene_color_matrix                  /* scene color matrix setup + render trigger */
.L_scene_b_enable_mask:
    .4byte  0x0000FF00                          /* high byte mask for scene B enable bits */
