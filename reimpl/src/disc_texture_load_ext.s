
    .section .text.FUN_0601B7F4


    .global disc_texture_load_ext
    .type disc_texture_load_ext, @function
disc_texture_load_ext:
    mov.l r14, @-r15
    mov #0x4, r14
    mov.l r13, @-r15
    mov #0x3, r13
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x24, r15
    mov.l   .L_car_obj_table, r8
    mov r15, r10
    mov r15, r1
    mov.l   .L_tex_param_src_a, r2
    mov.l   .L_fn_memcpy_byte, r3
    add #0x10, r10
    add #0x20, r1
    jsr @r3
    mov #0x2, r0
    mov r15, r1
    mov.l   .L_tex_param_src_b, r2
    mov.l   .L_fn_memcpy_long, r3
    add #0x14, r1
    jsr @r3
    mov #0xC, r0
    mov r15, r1
    mov.l   .L_tex_param_src_c, r2
    mov.l   .L_fn_memcpy_byte, r3
    add #0x10, r1
    jsr @r3
    mov r13, r0
    mov r15, r5
    mov r15, r1
    mov.l   .L_tex_param_src_d, r2
    mov.l   .L_fn_memcpy_byte, r3
    add #0xC, r5
    add #0xC, r1
    jsr @r3
    mov r13, r0
    mov.l   .L_cd_status_base, r6
    mov.l   .L_disc_type_flag, r4
    mov.w   DAT_0601b87e, r3
    mov.w @(2, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_scroll_up
    mov.b @r4, r3
    mov.l   .L_scroll_param_a, r2
    add r2, r3
    mov.b @r3, r1
    add #-0x1, r1
    mov.b r1, @r3
    exts.b r1, r1
    cmp/pz r1
    bt      .L_scroll_done
    mov.b @r4, r6
    mov.l   .L_scroll_param_a, r2
    add r6, r2
    add r6, r5
    mov.b @r5, r3
    add #-0x1, r3
    exts.b r3, r3
    mov.b r3, @r2
    bra     .L_scroll_done
    nop

    .global DAT_0601b87e
DAT_0601b87e:
    .2byte  0x4000                          /* bit 14 mask -- scroll-down flag */
.L_car_obj_table:
    .4byte  sym_06063750
.L_tex_param_src_a:
    .4byte  sym_0605DF26
.L_fn_memcpy_byte:
    .4byte  sym_06035228
.L_tex_param_src_b:
    .4byte  sym_0605DF28
.L_fn_memcpy_long:
    .4byte  sym_06035168
.L_tex_param_src_c:
    .4byte  sym_0605DF34
.L_tex_param_src_d:
    .4byte  sym_0605DF37
.L_cd_status_base:
    .4byte  g_pad_state
.L_disc_type_flag:
    .4byte  sym_0608600E
.L_scroll_param_a:
    .4byte  sym_0605D4F4
.L_check_scroll_up:
    mov.w @(2, r6), r0
    mov.l   .L_fp_half, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_scroll_done
    mov.b @r4, r3
    mov.l   .L_scroll_param_a_2, r2
    add r2, r3
    mov.b @r3, r1
    add #0x1, r1
    mov.b r1, @r3
    exts.b r1, r1
    mov.b @r4, r0
    mov.b @(r0, r5), r3
    cmp/ge r3, r1
    bf      .L_scroll_done
    mov.b @r4, r3
    mov.l   .L_scroll_param_a_2, r2
    add r2, r3
    mov #0x0, r1
    mov.b r1, @r3
.L_scroll_done:
    mov #0x0, r12
    mov.l   .L_scroll_param_a_2, r3
    mov.l r3, @r15
    mov r15, r3
    add #0x20, r3
    mov.l r3, @(8, r15)
.L_loop1_top:
    extu.b r12, r2
    mov.l @r15, r3
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_loop1_not_active
    bra     .L_loop1_setup_dma
    mov #0x1, r9
.L_loop1_not_active:
    extu.b r14, r9
.L_loop1_setup_dma:
    extu.b r12, r2
    extu.b r9, r9
    extu.b r12, r4
    mov.l r2, @(4, r15)
    shll2 r4
    add r9, r2
    mov.w   .L_slot_base_offset, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_fp_one, r2
    mov.l r2, @-r15
    mov.l   .L_fp_half, r3
    mov.l r3, @-r15
    mov.l   .L_fp_x_offset, r7
    mov r15, r3
    mov.l   .L_fn_rigid_body_transform, r2
    mov.l   .L_fp_y_offset, r6
    mov.l   .L_fp_z_offset, r5
    add #0x20, r3
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    add #0xC, r15
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_loop1_skip_check
    mov.l   .L_tex_load_flags, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r11, r2
    tst r2, r2
    bf      .L_loop1_use_3_slots
    mov.l   .L_disc_type_flag_2, r3
    mov.b @r3, r3
    tst r3, r3
    bt      .L_loop1_use_4_slots
.L_loop1_use_3_slots:
    bra     .L_loop1_compute_vram
    extu.b r13, r9
.L_loop1_use_4_slots:
    bra     .L_loop1_compute_vram
    extu.b r14, r9
.L_slot_base_offset:
    .2byte  0x0100
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_scroll_param_a_2:
    .4byte  sym_0605D4F4
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fp_x_offset:
    .4byte  0x001C0000
.L_fp_y_offset:
    .4byte  0x002F0000
.L_fp_z_offset:
    .4byte  0xFFD40000
.L_fn_rigid_body_transform:
    .4byte  rigid_body_transform
.L_tex_load_flags:
    .4byte  sym_0605D4F8
.L_disc_type_flag_2:
    .4byte  sym_0608600E
.L_loop1_skip_check:
    extu.b r14, r9
.L_loop1_compute_vram:
    extu.b r9, r7
    extu.b r12, r2
    extu.b r12, r0
    shll8 r7
    add #0x30, r2
    shll2 r7
    mov r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r3, r2
    add r8, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.b @(r0, r10), r6
    mov.l @(4, r15), r5
    add r3, r7
    extu.b r6, r6
    mov.l @r5, r5
    mov.l @(8, r15), r3
    mov.b @r3, r3
    extu.b r3, r2
    shll2 r2
    mov.l   .L_fn_dlist_loader, r3
    shll2 r2
    shll2 r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0x8, r4
    add #0x1, r12
    extu.b r12, r2
    cmp/ge r13, r2
    bf      .L_loop1_top
    mov #0x0, r12
    mov.l   .L_scroll_param_b, r2
    mov.l r2, @(8, r15)
    mov r15, r3
    add #0x21, r3
    mov.l r3, @r15
.L_loop2_top:
    extu.b r12, r2
    mov.l @(8, r15), r3
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_loop2_skip_check
    mov.l   .L_tex_load_flags_2, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r11, r2
    tst r2, r2
    bf      .L_loop2_use_3_slots
    mov.l   .L_disc_type_flag_3, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt      .L_loop2_use_4_slots
.L_loop2_use_3_slots:
    bra     .L_loop2_compute_vram
    extu.b r13, r9
.L_loop2_use_4_slots:
    bra     .L_loop2_compute_vram
    extu.b r14, r9
.L_loop2_skip_check:
    extu.b r14, r9
.L_loop2_compute_vram:
    extu.b r9, r7
    extu.b r12, r2
    extu.b r12, r0
    shll8 r7
    add #0x33, r2
    shll2 r7
    mov r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r3, r2
    add r8, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.b @(r0, r10), r6
    mov.l @(4, r15), r5
    add r3, r7
    extu.b r6, r6
    mov.l @r5, r5
    mov.l @r15, r3
    mov.b @r3, r3
    extu.b r3, r2
    shll2 r2
    mov.l   .L_fn_dlist_loader, r3
    shll2 r2
    shll2 r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0x8, r4
    add #0x1, r12
    extu.b r12, r2
    cmp/ge r13, r2
    bf      .L_loop2_top
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_dlist_loader:
    .4byte  sym_06028400
.L_scroll_param_b:
    .4byte  sym_0605D4F5
.L_tex_load_flags_2:
    .4byte  sym_0605D4F8
.L_disc_type_flag_3:
    .4byte  sym_0608600E
