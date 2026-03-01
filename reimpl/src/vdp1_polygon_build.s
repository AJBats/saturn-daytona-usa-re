
    .section .text.FUN_06037660


    .global vdp1_polygon_build
    .type vdp1_polygon_build, @function
vdp1_polygon_build:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x18, r15
    mov.l   .L_fp_half, r8
    mov.l   .L_coord_limit, r9
    mov.w   DAT_060376a4, r10
    mov.w   DAT_060376a6, r12
    mov #0x3F, r14
    mov.l   .L_vdp1_cmd_template, r7
    mov.l   .L_vdp1_output_buf, r6
    mov #0x0, r3
    mov.l r3, @(12, r15)
    mov.b @(8, r5), r0
    mov r0, r3
    extu.b r3, r3
    mov.w r3, @r15
    mov.w @r15, r11
    extu.w r11, r11
    shll8 r11
    shll2 r11
    shll2 r11
    shll2 r11
    mov.w   DAT_060376a8, r2
    and r2, r11
    extu.w r11, r11
    mov.l   .L_vdp1_cmd_list, r13
    bra     .L_type_dispatch
    extu.w r4, r0

    .global DAT_060376a4
DAT_060376a4:
    .2byte  0x7FFF                  /* max positive 15-bit (clip threshold) */

    .global DAT_060376a6
DAT_060376a6:
    .2byte  0x3F00                  /* color bank mask (bits 13:8) */

    .global DAT_060376a8
DAT_060376a8:
    .2byte  0x4000                  /* bit 14 isolate (color bank select) */
    .2byte  0xFFFF
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_coord_limit:
    .4byte  0x0000BFFF              /* 48K-1 coordinate range limit */
.L_vdp1_cmd_template:
    .4byte  0xDA200000              /* VDP1 distorted sprite + draw mode bits */
.L_vdp1_output_buf:
    .4byte  sym_060A3DB0            /* polygon output buffer base */
.L_vdp1_cmd_list:
    .4byte  sym_060A3D88            /* VDP1 command list write pointer */
.L_type_04_handler:
    mov.b @r5, r4
    extu.b r4, r4
    mov #0x1, r2
    and r2, r4
    mov.l   .L_mask_bit0_clr, r3
    mov #0x20, r0
    mov.w @(r0, r13), r2
    and r3, r2
    mov.w r2, @(r0, r13)
    extu.w r4, r4
    mov.w @(r0, r13), r3
    or r4, r3
    mov.w r3, @(r0, r13)
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    mov #0x1, r3
    and r3, r4
    mov.l   .L_mask_bit0_clr, r2
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    extu.w r4, r4
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.w @(10, r5), r0
    mov.w r0, @(8, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(8, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    mov.w @(8, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    mov.w @(8, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    extu.w r11, r11
    mov.w @(8, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    .4byte  0x84536403
    .4byte  0x644CE303
    .4byte  0x2439D223
    .4byte  0x85696303
    .4byte  0x23296033
    .4byte  0x8169644D
    .4byte  0x85696303
    .4byte  0x234B6033
    .4byte  0x81698454
    .4byte  0x6403644C
    .4byte  0x604D4008
    .4byte  0xC90C640D
    .4byte  0xD31A6261
    .4byte  0x22392621
    .4byte  0x6361234B
    .4byte  0x26318455
    .4byte  0x6403644C
    .4byte  0x604D4008
    .4byte  0xD3156261
    .4byte  0x40082239
    .4byte  0xC9702621
    .4byte  0x640D6361
    .4byte  0x234B2631
    .4byte  0x84566403
    .4byte  0x644C604D
    .4byte  0x4000C902
    .4byte  0x640DD30E
    .4byte  0x62612239
    .4byte  0x26216361
    .4byte  0x234B2631
    .4byte  0xD20B856A
    .4byte  0x63032329
    .4byte  0x6033816A
    .4byte  0x64637414
    .4byte  0xE3002F31
    .4byte  0x6B63A1A1
    .4byte  0x7B18FFFF
.L_mask_bit0_clr:
    .4byte  0x0000FFFE
    .4byte  0x0000FFFC
    .4byte  0x0000FFF3
    .4byte  0x0000FF8F
    .4byte  0x0000FFFD
    .4byte  0x0000FFF0
.L_type_08_handler:
    mov.l   .L_mask_pmod_ctrl_clr, r2
    mov #0x20, r0
    mov.w @(r0, r13), r3
    and r2, r3
    mov.w r3, @(r0, r13)
    mov.w   DAT_060378f8, r3
    mov.w @(r0, r13), r2
    or r3, r2
    mov.w r2, @(r0, r13)
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    mov.w   DAT_060378fa, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_bit0_clr, r2
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.w @(10, r5), r0
    mov.w r0, @(10, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(10, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(10, r6)
    mov.w @(10, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(10, r6)
    mov.w @(10, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(10, r6)
    extu.w r11, r11
    mov.w @(10, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(10, r6)
    mov.b @(3, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    and #0xC, r0
    extu.w r0, r4
    mov.l   .L_mask_dir_field_clr, r3
    mov.w @(18, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(18, r6)
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(4, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    mov.w   DAT_060378fc, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_hi_a_clr, r2
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.b @(5, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    mov.w   DAT_060378fe, r3
    mov.l   .L_mask_colr_hi_b_clr, r2
    shll8 r4
    shll2 r4
    shll2 r4
    and r3, r4
    extu.w r4, r4
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.b @(6, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll r4
    mov.w   .L_wmask_bit9, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_bit1_clr, r2
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.l   .L_mask_size_field_clr, r3
    mov.w @(20, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(20, r6)
    mov r6, r4
    add #0x14, r4
    mov #0x4, r3
    mov.w r3, @r15
    mov r6, r11
    bra     .L_setup_vtx_iter
    add #0x1C, r11

    .global DAT_060378f8
DAT_060378f8:
    .2byte  0x0202

    .global DAT_060378fa
DAT_060378fa:
    .2byte  0x0100

    .global DAT_060378fc
DAT_060378fc:
    .2byte  0x0C00

    .global DAT_060378fe
DAT_060378fe:
    .2byte  0x3000
.L_wmask_bit9:
    .2byte  0x0200
    .2byte  0xFFFF
.L_mask_pmod_ctrl_clr:
    .4byte  0x0000FDFD
.L_mask_colr_bit0_clr:
    .4byte  0x0000FEFF
.L_mask_dir_field_clr:
    .4byte  0x0000FFF3
.L_mask_colr_hi_a_clr:
    .4byte  0x0000F3FF
.L_mask_colr_hi_b_clr:
    .4byte  0x0000CFFF
.L_mask_colr_bit1_clr:
    .4byte  0x0000FDFF
.L_mask_size_field_clr:
    .4byte  0x0000FF0F
.L_type_10_handler:
    mov.b @r5, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    and #0x4, r0
    extu.w r0, r4
    mov.l   .L_mask_pmod_bit2_clr, r3
    mov #0x20, r0
    mov.w @(r0, r13), r2
    and r3, r2
    mov.w r2, @(r0, r13)
    mov.w @(r0, r13), r3
    or r4, r3
    mov.w r3, @(r0, r13)
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    and #0x1, r0
    extu.w r0, r4
    mov.l   .L_mask_colr_bit0_clr_b, r3
    mov.w @(2, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(10, r5), r0
    mov.w r0, @(12, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(12, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(12, r6)
    mov.w @(12, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(12, r6)
    mov.w @(12, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(12, r6)
    extu.w r11, r11
    mov.w @(12, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(12, r6)
    mov.b @(3, r5), r0
    mov.l   .L_mask_dir_54_clr, r3
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    and #0x30, r0
    extu.w r0, r4
    mov.w @(18, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(18, r6)
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(5, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll r0
    and #0x2, r0
    extu.w r0, r4
    mov.l   .L_mask_colr_bit1_clr_b, r3
    mov.w @(2, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.l   .L_mask_size_nibble_clr, r3
    mov.w @(20, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(20, r6)
    mov r6, r4
    add #0x14, r4
    mov #0x8, r3
    mov.w r3, @r15
    mov r6, r11
    bra     .L_setup_vtx_iter
    add #0x20, r11
    .2byte  0xFFFF
.L_mask_pmod_bit2_clr:
    .4byte  0x0000FFFB
.L_mask_colr_bit0_clr_b:
    .4byte  0x0000FFFE
.L_mask_dir_54_clr:
    .4byte  0x0000FFCF
.L_mask_colr_bit1_clr_b:
    .4byte  0x0000FFFD
.L_mask_size_nibble_clr:
    .4byte  0x0000F0FF
.L_type_20_handler:
    mov.b @r5, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll r0
    and #0x8, r0
    extu.w r0, r4
    mov.l   .L_mask_pmod_bit3_clr, r3
    mov #0x20, r0
    mov.w @(r0, r13), r2
    and r3, r2
    mov.w r2, @(r0, r13)
    mov.w @(r0, r13), r3
    or r4, r3
    mov.w r3, @(r0, r13)
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    and #0x10, r0
    extu.w r0, r4
    mov.l   .L_mask_colr_bit4_clr, r3
    mov.w @(2, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(10, r5), r0
    mov.w r0, @(14, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(14, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(14, r6)
    mov.w @(14, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(14, r6)
    mov.w @(14, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(14, r6)
    extu.w r11, r11
    mov.w @(14, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(14, r6)
    mov.b @(3, r5), r0
    mov.l   .L_mask_dir_76_clr, r3
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    shll2 r0
    and #0xC0, r0
    extu.w r0, r4
    mov.w @(18, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(18, r6)
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(5, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    shll r0
    and #0x20, r0
    extu.w r0, r4
    mov.l   .L_mask_colr_bit5_clr, r3
    mov.w @(2, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w   DAT_06037b10, r3
    mov.w @(20, r6), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(20, r6)
    mov r6, r4
    add #0x14, r4
    mov #0xC, r3
    mov.w r3, @r15
    mov r6, r11
    add #0x24, r11
.L_setup_vtx_iter:
    bra     .L_build_vertex_coords
    mov #0x2, r13

    .global DAT_06037b10
DAT_06037b10:
    .2byte  0x0FFF
    .2byte  0xFFFF
.L_mask_pmod_bit3_clr:
    .4byte  0x0000FFF7
.L_mask_colr_bit4_clr:
    .4byte  0x0000FFEF
.L_mask_dir_76_clr:
    .4byte  0x0000FF3F
.L_mask_colr_bit5_clr:
    .4byte  0x0000FFDF
.L_type_01_handler:
    mov.b @r5, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    and #0x10, r0
    extu.w r0, r4
    mov.l   .L_mask_pmod_bit4_clr, r3
    mov #0x20, r0
    mov.w @(r0, r13), r2
    and r3, r2
    mov.w r2, @(r0, r13)
    mov.w @(r0, r13), r3
    or r4, r3
    mov.w r3, @(r0, r13)
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    mov.w   DAT_06037c8e, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_bit8_clr, r2
    mov.w @(2, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(10, r5), r0
    mov.w r0, @(16, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(16, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(16, r6)
    mov.w @(16, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(16, r6)
    mov.w @(16, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(16, r6)
    extu.w r11, r11
    mov.w @(16, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(16, r6)
    mov.b @(3, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    mov.w   DAT_06037c90, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_dir_98_clr, r2
    mov.w @(18, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(7, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    mov.w   DAT_06037c92, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_dir_ba_clr, r2
    mov.w @(18, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(4, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    mov.w   DAT_06037c94, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_bit10_clr, r2
    mov.w @(2, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.b @(5, r5), r0
    mov.w   DAT_06037c96, r3
    mov.l   .L_mask_colr_hi_cde_clr, r2
    mov r0, r4
    extu.b r4, r4
    mov.w @(2, r6), r0
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    and r3, r4
    extu.w r4, r4
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.b @(6, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll r4
    mov.w   .L_wmask_bit9_b, r3
    and r3, r4
    extu.w r4, r4
    mov.l   .L_mask_colr_bit9_clr, r2
    mov.w @(2, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.w @(2, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(2, r6)
    mov.l   .L_poly_flag_a, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf/s    .L_flag_b_not_set
    mov #0x8, r13
    mov.l   .L_poly_flag_b, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_flag_b_not_set
    bra     .L_both_flags_set
    nop

    .global DAT_06037c8e
DAT_06037c8e:
    .2byte  0x0100

    .global DAT_06037c90
DAT_06037c90:
    .2byte  0x0300

    .global DAT_06037c92
DAT_06037c92:
    .2byte  0x0C00

    .global DAT_06037c94
DAT_06037c94:
    .2byte  0x0400

    .global DAT_06037c96
DAT_06037c96:
    .2byte  0x7000
.L_wmask_bit9_b:
    .2byte  0x0200
    .2byte  0xFFFF
.L_mask_pmod_bit4_clr:
    .4byte  0x0000FFEF
.L_mask_colr_bit8_clr:
    .4byte  0x0000FEFF
.L_mask_dir_98_clr:
    .4byte  0x0000FCFF
.L_mask_dir_ba_clr:
    .4byte  0x0000F3FF
.L_mask_colr_bit10_clr:
    .4byte  0x0000FBFF
.L_mask_colr_hi_cde_clr:
    .4byte  0x00008FFF
.L_mask_colr_bit9_clr:
    .4byte  0x0000FDFF
.L_poly_flag_a:
    .4byte  sym_060A4C58
.L_poly_flag_b:
    .4byte  sym_060A4C59
.L_both_flags_set:
    mov.l   .L_mask_size_lo_clr, r2
    mov.w @(22, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(22, r6)
    mov r6, r4
    add #0x16, r4
    mov #0x0, r3
    mov.w r3, @r15
    mov r6, r3
    add #0x28, r3
    mov.l r3, @(4, r15)
    mov r3, r11
    add #0x10, r3
    bra     .L_build_vertex_coords
    mov.l r3, @(12, r15)
.L_flag_b_not_set:
    mov.l   .L_poly_flag_a_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_flag_b_only
    mov.l   .L_mask_size_lo_clr, r2
    mov.w @(22, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(22, r6)
    mov r6, r4
    add #0x16, r4
    mov #0x0, r3
    mov.w r3, @r15
    mov r6, r11
    bra     .L_flag_check_done
    add #0x28, r11
.L_check_flag_b_only:
    mov.l   .L_poly_flag_b_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_flag_check_done
    mov.l   .L_mask_size_hi_clr, r2
    mov.w @(22, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(22, r6)
    mov r6, r4
    add #0x16, r4
    mov #0x4, r3
    mov.w r3, @r15
    mov r6, r11
    add #0x38, r11
.L_flag_check_done:
    bra     .L_build_vertex_coords
    nop
.L_mask_size_lo_clr:
    .4byte  0x0000FFF0
.L_poly_flag_a_2:
    .4byte  sym_060A4C58
.L_poly_flag_b_2:
    .4byte  sym_060A4C59
.L_mask_size_hi_clr:
    .4byte  0x0000FF0F
.L_type_02_handler:
    mov.l   .L_poly_flag_a_3, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_type2_check_flag_b
    bra     .L_build_vertex_coords
    nop
.L_type2_check_flag_b:
    mov.l   .L_poly_flag_b_3, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bt      .L_type2_build_cmd
    bra     .L_build_vertex_coords
    nop
.L_type2_build_cmd:
    mov.l   .L_mask_pmod_bit5_clr, r2
    mov #0x20, r0
    mov.w @(r0, r13), r3
    and r2, r3
    mov.w r3, @(r0, r13)
    mov.b @r5, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_type2_skip_or_bit
    mov #0x20, r0
    mov.w @(r0, r13), r0
    or #0x20, r0
    mov #0x20, r1
    add r13, r1
    mov.w r0, @r1
.L_type2_skip_or_bit:
    mov #0x1, r3
    mov.l   .L_mask_colr_bit0_clr_c, r2
    mov.b @(1, r5), r0
    mov r0, r4
    extu.b r4, r4
    and r3, r4
    extu.w r4, r4
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov.w @r6, r2
    or r4, r2
    mov.w r2, @r6
    mov.w @(10, r5), r0
    mov.w r0, @(8, r6)
    mov.b @(2, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r4
    shll8 r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    and r8, r4
    extu.w r4, r4
    mov.w @(8, r6), r0
    mov r0, r3
    and r10, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    mov.w @(8, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    mov.w @(8, r6), r0
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    extu.w r11, r11
    mov.w @(8, r6), r0
    mov r0, r3
    or r11, r3
    mov r3, r0
    mov.w r0, @(8, r6)
    mov.b @(3, r5), r0
    mov r0, r4
    extu.b r4, r4
    mov #0x3, r3
    and r3, r4
    mov.l   .L_mask_dir_10_clr, r2
    mov.w @(18, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    extu.w r4, r4
    mov.w @(18, r6), r0
    mov r0, r3
    or r4, r3
    mov r3, r0
    mov.w r0, @(18, r6)
    mov.b @(5, r5), r0
    mov r0, r4
    extu.b r4, r4
    extu.w r4, r0
    shll2 r0
    shll2 r0
    and #0x70, r0
    extu.w r0, r4
    mov.l   .L_mask_colr_hi_456_clr, r3
    mov.w @r6, r2
    and r3, r2
    mov.w r2, @r6
    mov.w @r6, r3
    or r4, r3
    mov.w r3, @r6
    mov.l   .L_mask_colr_bit1_clr_c, r2
    mov.w @r6, r3
    and r2, r3
    mov.w r3, @r6
    mov #0x8, r13
    mov.l   .L_mask_size_lo_clr_b, r2
    mov.w @(22, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(22, r6)
    mov r6, r4
    add #0x16, r4
    mov #0x4, r3
    mov.w r3, @r15
    mov r6, r11
    bra     .L_build_vertex_coords
    add #0x38, r11
.L_poly_flag_a_3:
    .4byte  sym_060A4C58
.L_poly_flag_b_3:
    .4byte  sym_060A4C59
.L_mask_pmod_bit5_clr:
    .4byte  0x0000FFDF
.L_mask_colr_bit0_clr_c:
    .4byte  0x0000FFFE
.L_mask_dir_10_clr:
    .4byte  0x0000FFFC
.L_mask_colr_hi_456_clr:
    .4byte  0x0000FF8F
.L_mask_colr_bit1_clr_c:
    .4byte  0x0000FFFD
.L_mask_size_lo_clr_b:
    .4byte  0x0000FF0F
.L_type_dispatch:
    cmp/eq #0x1, r0
    bf      .L_try_type_02
    bra     .L_type_01_handler
    nop
.L_try_type_02:
    cmp/eq #0x2, r0
    bf      .L_try_type_04
    bra     .L_type_02_handler
    nop
.L_try_type_04:
    cmp/eq #0x4, r0
    bf      .L_try_type_08
    bra     .L_type_04_handler
    nop
.L_try_type_08:
    cmp/eq #0x8, r0
    bf      .L_try_type_10
    bra     .L_type_08_handler
    nop
.L_try_type_10:
    cmp/eq #0x10, r0
    bf      .L_try_type_20
    bra     .L_type_10_handler
    nop
.L_try_type_20:
    cmp/eq #0x20, r0
    bf      .L_build_vertex_coords
    bra     .L_type_20_handler
    nop
.L_build_vertex_coords:
    mov.b @(6, r5), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_color_calc_normal
    mov.l @(12, r5), r0
    add r7, r0
    shlr16 r0
    shlr r0
    and #0x7, r0
    extu.w r0, r0
    mov.w r0, @(4, r15)
    mov.w @(4, r15), r0
    mov.w @r15, r1
    mov.l   .L_fn_color_lookup, r3
    extu.w r0, r0
    jsr @r3
    extu.w r1, r1
    bra     .L_color_write
    nop
.L_color_calc_normal:
    mov.b @(2, r5), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_no_tex_flag
    mov.b @(1, r5), r0
    mov r0, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_tex_nonzero
    mov.w   .L_tex_size_8k, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    bra     .L_color_lookup_entry
    nop
.L_tex_nonzero:
    mov.w   .L_tex_size_2k, r2
    mov r2, r0
    bra     .L_color_lookup_entry
    mov.w r0, @(4, r15)
.L_no_tex_flag:
    mov.b @(1, r5), r0
    mov r0, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_tex_default_nonzero
    mov.w   .L_tex_size_16k, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    bra     .L_color_lookup_entry
    nop
.L_tex_size_8k:
    .2byte  0x2000                  /* texture size 8K */
.L_tex_size_2k:
    .2byte  0x0800                  /* texture size 2K */
.L_tex_size_16k:
    .2byte  0x4000                  /* texture size 16K */
.L_fn_color_lookup:
    .4byte  sym_06035280            /* color lookup function */
.L_tex_default_nonzero:
    mov.w   .L_tex_size_4k, r2
    mov r2, r0
    mov.w r0, @(4, r15)
.L_color_lookup_entry:
    mov.l @(12, r5), r1
    mov.w @(4, r15), r0
    mov.l   .L_fn_input_proc, r3
    add r7, r1
    jsr @r3
    extu.w r0, r0
    mov.w   .L_color_field_mask, r2
    and r2, r0
    shlr2 r0
    shlr2 r0
    shlr2 r0
    extu.w r0, r0
    mov.w r0, @(8, r15)
    mov.w @(8, r15), r0
    mov.w @r15, r1
    mov.l   .L_fn_color_lookup_b, r3
    extu.w r0, r0
    jsr @r3
    extu.w r1, r1
.L_color_write:
    mov.w @r4, r2
    mov #0x0, r3
    or r0, r2
    mov.w r2, @r4
    mov.w r3, @r15
    extu.w r13, r3
    cmp/pl r3
    bf      .L_vtx_loop_done
.L_vtx_loop:
    mov.w @r15, r3
    mov r5, r2
    extu.w r3, r3
    add #0xC, r2
    shll r3
    add r11, r3
    mov.l r3, @(16, r15)
    mov.w @r15, r1
    extu.w r1, r1
    shll r1
    shll2 r1
    mov.l r1, @(8, r15)
    add r2, r1
    mov.w @(4, r15), r0
    mov.l @r1, r1
    extu.w r0, r0
    mov.l r0, @(20, r15)
    mov.l   .L_fn_input_proc, r2
    jsr @r2
    add r7, r1
    and r14, r0
    mov r5, r1
    extu.w r0, r0
    add #0xC, r1
    mov.w r0, @r3
    mov.l @(8, r15), r3
    mov.l   .L_fn_input_proc, r2
    add r3, r1
    mov.l @(4, r1), r1
    add r7, r1
    jsr @r2
    mov.l @(20, r15), r0
    and r14, r0
    shll8 r0
    extu.w r0, r0
    mov.w r0, @(8, r15)
    mov.l @(16, r15), r2
    mov.w @(8, r15), r0
    mov r0, r1
    extu.w r1, r1
    mov.w @r2, r0
    and r12, r1
    or r1, r0
    mov.w r0, @r2
    mov.w @r15, r3
    extu.w r13, r2
    add #0x1, r3
    mov.w r3, @r15
    extu.w r3, r3
    cmp/ge r2, r3
    bf      .L_vtx_loop
.L_vtx_loop_done:
    mov.l @(12, r15), r0
    tst r0, r0
    bt      .L_set_dirty_and_exit
    mov.w @r4, r0
    and #0xF, r0
    mov.w r0, @r4
    mov.w @r4, r3
    mov.w @r4, r2
    extu.w r3, r3
    shll2 r3
    shll2 r3
    or r3, r2
    mov.w r2, @r4
    extu.w r13, r3
    cmp/pl r3
    bf/s    .L_set_dirty_and_exit
    mov #0x0, r4
.L_vtx_loop_secondary:
    extu.w r4, r11
    extu.w r4, r1
    mov.l @(12, r15), r3
    shll r11
    shll r1
    add r3, r11
    shll2 r1
    mov r5, r3
    mov.l r1, @(8, r15)
    add #0xC, r3
    mov.w @(4, r15), r0
    add r3, r1
    extu.w r0, r0
    mov.l @r1, r1
    mov.l   .L_fn_input_proc, r3
    add r7, r1
    jsr @r3
    mov.l r0, @r15
    and r14, r0
    mov r5, r1
    extu.w r0, r0
    add #0xC, r1
    mov.w r0, @r11
    mov.l @(8, r15), r3
    mov.l   .L_fn_input_proc, r2
    add r3, r1
    mov.l @(4, r1), r1
    add r7, r1
    jsr @r2
    mov.l @r15, r0
    bra     .L_vtx_secondary_color
    nop
.L_tex_size_4k:
    .2byte  0x1000                  /* texture size 4K */
.L_color_field_mask:
    .2byte  0x01C0                  /* bits 8:6 — color field extract mask */
.L_fn_input_proc:
    .4byte  input_proc_complete     /* coordinate transform function */
.L_fn_color_lookup_b:
    .4byte  sym_06035280            /* color lookup function (2nd ref) */
.L_vtx_secondary_color:
    and r14, r0
    add #0x1, r4
    shll8 r0
    extu.w r4, r3
    extu.w r0, r0
    mov.w r0, @r15
    mov.w @r15, r2
    mov.w @r11, r1
    extu.w r2, r2
    and r12, r2
    or r2, r1
    extu.w r13, r2
    cmp/ge r2, r3
    bf/s    .L_vtx_loop_secondary
    mov.w r1, @r11
.L_set_dirty_and_exit:
    mov.l   .L_vdp1_dirty_flag, r4
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_epilogue
    mov #0x1, r3
    mov.w r3, @r4
.L_epilogue:
    add #0x18, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_vdp1_dirty_flag:
    .4byte  sym_060635AC            /* VDP1 command list dirty flag */

    .global sym_06038044
sym_06038044:
    mov.l   .L_cmd_list_base, r0
    mov #0x8, r7
    mov #0x0, r5
.L_copy_loop:
    extu.w r5, r6
    mov r0, r3
    shll r6
    add #0x1, r5
    add #0x10, r3
    mov r6, r2
    add r6, r3
    add r4, r2
    mov.w @r2, r1
    mov.w r1, @r3
    extu.w r5, r3
    cmp/ge r7, r3
    bf      .L_copy_loop
    rts
    nop
.L_cmd_list_base:
    .4byte  sym_060A3D88            /* VDP1 command list base pointer */
