
    .section .text.FUN_06019EF0


    .global pre_race_camera
    .type pre_race_camera, @function
pre_race_camera:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_pool_06019F4C, r13
    mov.l   .L_pool_06019F50, r14
    mov.w @r13, r0
    extu.w r0, r0
    tst #0x1, r0
    bt/s    .L_wide_range
    mov #0x0, r12
    bra     .L_check_new_up
    mov #0x6, r5
.L_wide_range:
    mov #0x19, r5
.L_check_new_up:
    mov.l   .L_fp_half, r7
    mov.l   .L_pool_06019F58, r4
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_check_new_down
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp_upper
    mov.b r2, @r4
.L_check_new_down:
    mov.w   .L_wpool_06019F40, r6
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_check_held_up
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp_upper
    mov.b r2, @r4
.L_wpool_06019F40:
    .2byte  0x4000                  /* Down button mask (16-bit) */
    .2byte  0xFFFF                  /* padding */
    .4byte  sym_06063750            /* car object table base (unused here, pool alignment) */
    .4byte  sym_06049B18            /* course 1 dlist offset table (unused here, pool alignment) */
.L_pool_06019F4C:
    .4byte  g_pad_state            /* &input_state struct (word[0]=held, word[+2]=new_press) */
.L_pool_06019F50:
    .4byte  sym_0605AD0C            /* &camera_angle_index for course 1 (32-bit) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_06019F58:
    .4byte  sym_0605D243            /* &anim_timer / mode variant byte (reset on angle change) */
.L_check_held_up:
    mov.w @r13, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_check_held_down
    mov.b @r4, r3
    extu.b r5, r5
    cmp/eq r5, r3
    bf      .L_clamp_upper
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp_upper
    mov.b r2, @r4
.L_check_held_down:
    mov.w @r13, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_clamp_upper
    extu.b r5, r5
    mov.b @r4, r3
    cmp/eq r5, r3
    bf      .L_clamp_upper
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    mov.b r2, @r4
.L_clamp_upper:
    mov #0x5, r2
    mov.l @r14, r3
    cmp/ge r2, r3
    bf      .L_clamp_lower
    mov #0x4, r2
    mov.l r2, @r14
.L_clamp_lower:
    mov.l @r14, r3
    cmp/pz r3
    bt      .L_done
    mov.l r12, @r14
.L_done:
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xAF, 0x03    /* bra 0x06019DB8 (external) */
    mov.l @r15+, r14
