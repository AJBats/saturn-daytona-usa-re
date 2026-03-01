
    .section .text.FUN_06027EDE


    .global scene_render_alt
    .type scene_render_alt, @function
scene_render_alt:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l r6, @-r15
    mov r5, r13
    mov.l @r5, r14
    mov.l @(8, r5), r12
    .byte   0xDB, 0x07    /* mov.l .L_tile_index_table, r11 */
    .byte   0xDA, 0x08    /* mov.l .L_tile_data_base, r10 */
    .byte   0xD0, 0x08    /* mov.l .L_race_mode_ptr, r0 */
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bt      .L_mode2_car_lookup
    mov r4, r0
    shll r0
    add #0x1, r0
    shll r0
    mov.w @(r0, r11), r9
    mov r4, r0
    shll2 r0
    mov.w @(r0, r11), r8
    bra     .L_start_plane_loop
    shlr r8
.L_tile_index_table:
    .4byte  sym_060C2000
.L_tile_data_base:
    .4byte  sym_060BF000
.L_race_mode_ptr:
    .4byte  sym_0607EAD8
.L_mode2_car_lookup:
    .byte   0xD1, 0x04    /* mov.l .L_car_id_list, r1 */
    xor r9, r9
.L_scan_car_list:
    mov.w @r1+, r0
    tst r0, r0
    bt      .L_car_not_found
    cmp/eq r0, r4
    bt      .L_car_id_found
    bra     .L_scan_car_list
    add #0x2, r9
    .2byte  0x0000
.L_car_id_list:
    .4byte  sym_06061270
.L_car_id_found:
    .byte   0xD1, 0x07    /* mov.l .L_car_struct_ptr, r1 */
    mov.l @r1, r1
    mov.w   DAT_06027f56, r0
    mov.l @(r0, r1), r1
    mov #0x46, r0
    cmp/gt r0, r1
    bt      .L_car_not_found
    shll r9
    .byte   0xD0, 0x04    /* mov.l .L_car_render_table, r0 */
    add r9, r0
    .byte   0xD1, 0x04    /* mov.l .L_active_cmd_slot, r1 */
    mov.w @r0+, r2
    mov.w @r0, r9
    bra     .L_check_override
    mov.w r2, @r1

    .global DAT_06027f56
DAT_06027f56:
    .2byte  0x01EC
.L_car_struct_ptr:
    .4byte  sym_0607E940
.L_car_render_table:
    .4byte  sym_06061240
.L_active_cmd_slot:
    .4byte  sym_06063F50
.L_car_not_found:
    xor r9, r9
.L_check_override:
    tst r9, r9
    bf      .L_use_override_entry
    mov r4, r0
    shll r0
    add #0x1, r0
    shll r0
    mov.w @(r0, r11), r9
    mov r4, r0
    shll2 r0
    mov.w @(r0, r11), r8
    bra     .L_start_plane_loop
    shlr r8
.L_use_override_entry:
    .byte   0xD0, 0x11    /* mov.l .L_active_cmd_slot_b, r0 */
    mov.w @r0, r8
    shlr r8
.L_start_plane_loop:
    xor r7, r7
.L_plane_loop_top:
    mov r8, r0
    shll r0
    mov.w @(r0, r10), r1
    .byte   0xD0, 0x0E    /* mov.l .L_obj_struct_size, r0 */
    mulu.w r0, r1
    sts macl, r5
    .byte   0xD0, 0x0E    /* mov.l .L_obj_array_base, r0 */
    add r0, r5
    mov r5, r0
    mov.l @(0, r0), r4
    mov.l @(16, r0), r6
    mov.l @(20, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    .byte   0xD0, 0x09    /* mov.l .L_minit, r0 */
    tst r4, r0
    bf      .L_plane_x_no_offset
    add r12, r3
.L_plane_x_no_offset:
    mov.w   .L_flag_negate_x, r0
    tst r0, r4
    bt      .L_plane_x_check_neg
    neg r3, r3
.L_plane_x_check_neg:
    cmp/pz r3
    bt      .L_test_plane_y
    bra     .L_plane_culled
    nop
.L_flag_negate_x:
    .2byte  0x0100
    .2byte  0x0000
.L_active_cmd_slot_b:
    .4byte  sym_06063F50
.L_obj_struct_size:
    .4byte  0x00000034
.L_obj_array_base:
    .4byte  sym_060A6000
.L_minit:
    .4byte  0x01000000                  /* MINIT — primary SH-2 init comm */
.L_test_plane_y:
    mov r5, r0
    mov.l @(24, r0), r6
    mov.l @(28, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    .byte   0xD0, 0x06    /* mov.l .L_flag_plane_y, r0 */
    tst r0, r4
    bf      .L_plane_y_no_offset
    add r12, r3
.L_plane_y_no_offset:
    mov.w   .L_flag_negate_y, r0
    tst r0, r4
    bt      .L_plane_y_check_neg
    neg r3, r3
.L_plane_y_check_neg:
    cmp/pz r3
    bt      .L_test_plane_z
    bra     .L_plane_culled
    nop
.L_flag_negate_y:
    .2byte  0x0200
    .2byte  0x0000
.L_flag_plane_y:
    .4byte  0x02000000
.L_test_plane_z:
    mov r5, r0
    mov.l @(32, r0), r6
    mov.l @(36, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    .byte   0xD0, 0x06    /* mov.l .L_flag_plane_z, r0 */
    tst r0, r4
    bf      .L_plane_z_no_offset
    add r12, r3
.L_plane_z_no_offset:
    mov.w   .L_flag_negate_z, r0
    tst r0, r4
    bt      .L_plane_z_check_neg
    neg r3, r3
.L_plane_z_check_neg:
    cmp/pz r3
    bt      .L_test_plane_w
    bra     .L_plane_culled
    nop
.L_flag_negate_z:
    .2byte  0x0400
    .2byte  0x0000
.L_flag_plane_z:
    .4byte  0x04000000
.L_test_plane_w:
    mov r5, r0
    mov.l @(40, r0), r6
    mov.l @(44, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    .byte   0xD0, 0x06    /* mov.l .L_flag_plane_w, r0 */
    tst r0, r4
    bf      .L_plane_w_no_offset
    add r12, r3
.L_plane_w_no_offset:
    mov.w   DAT_0602805c, r0
    tst r0, r4
    bt      .L_plane_w_check_neg
    neg r3, r3
.L_plane_w_check_neg:
    cmp/pz r3
    bf      .L_plane_culled
    bra     .L_all_planes_passed
    mov #0x1, r6

    .global DAT_0602805c
DAT_0602805c:
    .2byte  0x0800
    .2byte  0x0000
.L_flag_plane_w:
    .4byte  0x08000000
.L_plane_culled:
    add #0x1, r7
    add #0x1, r8
    cmp/ge r9, r7
    bt      .L_all_planes_passed
    bra     .L_plane_loop_top
    nop
.L_all_planes_passed:
    mov.l @r15+, r6
    tst r6, r6
    bt      .L_epilogue
    cmp/eq r7, r9
    bt      .L_epilogue
    .byte   0xD0, 0x0F    /* mov.l .L_off_field_x, r0 */
    mov.l @(r0, r5), r1
    dmuls.l r14, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    .byte   0xD0, 0x0D    /* mov.l .L_off_field_y, r0 */
    mov.l @(r0, r5), r2
    dmuls.l r12, r2
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    .byte   0xD0, 0x0B    /* mov.l .L_off_field_z, r0 */
    mov.l @(r0, r5), r3
    add r2, r1
    add r3, r1
    mov r13, r0
    mov.l r1, @(4, r0)
    mov r8, r0
    shll r0
    mov.w @(r0, r10), r1
    mov.w r1, @r6
.L_epilogue:
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
.L_off_field_x:
    .4byte  0x00000004
.L_off_field_y:
    .4byte  0x00000008
.L_off_field_z:
    .4byte  0x0000000C

    .global sym_060280C4
sym_060280C4:
    .byte   0xD3, 0x0A    /* mov.l .L_vdp1_cmd_template_a, r3 */
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w @(r0, r2), r4
    mov #0x6, r0
    mov.w r4, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_vdp1_cmd_template_a:
    .4byte  sym_060280F4

    .global sym_060280F4
sym_060280F4:
    mov.b r0, @(r0, r0)
    mov.l r12, @(0, r4)

    .global sym_060280F8
sym_060280F8:
    mov #0x5, r0
    mov.b @(r0, r4), r6
    .byte   0xD1, 0x18    /* mov.l .L_tex_index_table, r1 */
    extu.b r6, r6
    shll8 r6
    shlr2 r6
    mov.w @(6, r4), r0
    mov #0x8, r2
    add r6, r0
    shll r0
    mov.w @(r0, r1), r7
    mulu.w r2, r7
    .byte   0xD1, 0x14    /* mov.l .L_slot_data_base, r1 */
    mov #0x6, r0
    sts macl, r2
    add r2, r1
    mov.w @(r0, r1), r6
    .byte   0xD3, 0x13    /* mov.l .L_draw_mode_table, r3 */
    mov.b @(4, r4), r0
    and #0xC, r0
    add r0, r3
    mov.l @r3, r0
    mov.w r0, @(0, r5)
    mov.b @(4, r4), r0
    .byte   0xD2, 0x10    /* mov.l .L_color_mode_table, r2 */
    and #0x1, r0
    shll r0
    add r2, r0
    mov.w @r0, r0
    mov.w r0, @(4, r5)
    .byte   0xD3, 0x0E    /* mov.l .L_tex_base_addr, r3 */
    mov.l @r3, r0
    mov #0x8, r3
    mulu.w r3, r7
    add r6, r0
    mov.w r0, @(6, r5)
    .byte   0xD2, 0x08    /* mov.l .L_slot_data_base, r2 */
    sts macl, r3
    add r3, r2
    mov.l @(0, r2), r0
    mov.l @(20, r4), r1
    mov.w r0, @(8, r5)
    mov.w @(4, r2), r0
    mov.l @(16, r4), r3
    mov.w r0, @(10, r5)
    mov.l @(8, r4), r0
    mov.l @(12, r4), r2
    mov.l r0, @(12, r5)
    mov.l r2, @(16, r5)
    mov.l r3, @(20, r5)
    rts
    mov.l r1, @(24, r5)
.L_tex_index_table:
    .4byte  sym_060684EC
.L_slot_data_base:
    .4byte  sym_06063F64
.L_draw_mode_table:
    .4byte  sym_06028178
.L_color_mode_table:
    .4byte  sym_06028174
.L_tex_base_addr:
    .4byte  sym_06059FFC

    .global sym_06028174
sym_06028174:
    mov.l r12, @(32, r4)
    mov.l r8, @(32, r4)

    .global sym_06028178
sym_06028178:
    .word 0x0000
    stc sr, r0
    .word 0x0000
    stc vbr, r0
    .word 0x0000
    stc gbr, r0
    .word 0x0000
    .word 0x0032
    .byte   0xD3, 0x09    /* mov.l .L_vdp1_cmd_template_b, r3 */
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_vdp1_cmd_template_b:
    .4byte  sym_060281B4

    .global sym_060281B4
sym_060281B4:
    mov.w r0, @(r0, r0)
    mov.l r12, @(0, r4)

    .global sym_060281B8
sym_060281B8:
    .byte   0xD3, 0x09    /* mov.l .L_vdp1_cmd_template_c, r3 */
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_vdp1_cmd_template_c:
    .4byte  sym_060281E4

    .global sym_060281E4
sym_060281E4:
    mov.b r0, @(r0, r0)
    .word 0x05C0
    .byte   0xD3, 0x09    /* mov.l .L_vdp1_cmd_template_d, r3 */
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_vdp1_cmd_template_d:
    .4byte  sym_06028214

    .global sym_06028214
sym_06028214:
    mov.b r0, @(r0, r0)
    .word 0x04C2

    .global sym_06028218
sym_06028218:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    .byte   0xD6, 0x21    /* mov.l .L_dlist_data_a, r6 */
    bra     .L_int_build_dlist
    mov #0x9, r4

    .global sym_06028230
sym_06028230:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    .byte   0xD6, 0x1D    /* mov.l .L_dlist_data_c, r6 */
    bra     .L_int_build_dlist
    mov #0xC, r4

    .global sym_06028248
sym_06028248:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    .byte   0xD6, 0x18    /* mov.l .L_dlist_data_d, r6 */
    mov #0x9, r4
.L_int_build_dlist:
    mov.w   .L_sr_irq_mask, r0
    mov #0x1, r5
    .byte   0xB1, 0xCD    /* bsr 0x06028600 (external) */
    ldc r0, sr
    .byte   0xD6, 0x13    /* mov.l .L_dlist_data_b, r6 */
    mov #0xD, r4
    .byte   0xB1, 0xC9    /* bsr 0x06028600 (external) */
    mov #0x2, r5
    mov #0x13, r4
    mov #0x2, r5
    .byte   0xB1, 0xB5    /* bsr 0x060285E0 (external) */
    mov.l @(36, r15), r6
    .byte   0xD4, 0x0A    /* mov.l .L_vram_cfg_src, r4 */
    .byte   0xD5, 0x0A    /* mov.l .L_vram_cfg_dst, r5 */
    mov.w   .L_copy_word_count, r6
    .byte   0xD7, 0x0A    /* mov.l .L_fn_memcpy_word, r7 */
    jsr @r7
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r0
    mov.l @r15+, r1
    mov.l @r15+, r2
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov.l @r15+, r5
    mov.l @r15+, r6
    mov.l @r15+, r7
    sett
.L_halt_loop:
    bt      .L_halt_loop
    rte
    nop
.L_copy_word_count:
    .2byte  0x0180
    .2byte  0x0000
.L_vram_cfg_src:
    .4byte  sym_060612B8
.L_vram_cfg_dst:
    .4byte  sym_060612C4
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_sr_irq_mask:
    .2byte  0x00F0
    .2byte  0x0009
.L_dlist_data_a:
    .4byte  sym_06059C5C
.L_dlist_data_b:
    .4byte  sym_06059C74
.L_dlist_data_c:
    .4byte  sym_06059C7B
.L_dlist_data_d:
    .4byte  sym_06059C8C
    .4byte  0xD20ED00F
    .4byte  0x12001201
    .4byte  0x1202E000
    .4byte  0x802B4411
    .4byte  0x8D02E720
    .4byte  0x644BE72D
    .4byte  0x72029113
    .4byte  0xE00A1100
    .4byte  0x24488906
    .4byte  0x11410009
    .4byte  0x53164010
    .4byte  0x02348FF7
    .4byte  0x541772FE
    .4byte  0x0274000B
    .4byte  0x60230009
    .4byte  sym_060620C4
    .4byte  0x20202020
    .4byte  0xFF00D20E
    .4byte  0xD00E1200
    .4byte  0x12011202
    .4byte  0xE000802B
    .4byte  0x44118D02
    .4byte  0xE70A644B
    .4byte  0xE72D7202
    .4byte  0x9112E00A
    .4byte  0x11002448
    .4byte  0x89061141
    .4byte  0x00095316
    .4byte  0x40100234
    .4byte  0x8FF75417
    .4byte  0x72FE0274
    .4byte  0x000B6023
    .4byte  sym_060620C4
    .4byte  0x0A0A0A0A
    .2byte  0xFF00
