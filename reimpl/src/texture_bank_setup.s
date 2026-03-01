
    .section .text.FUN_060370E4


    .global texture_bank_setup
    .type texture_bank_setup, @function
texture_bank_setup:
    mov.l r14, @-r15
    mov #0x0, r3
    mov.l r13, @-r15
    mov r3, r2
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov r4, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_mask_byte1, r9
    mov.l   .L_vram_addr_out, r10
    mov.l   .L_disp_ctrl_reg, r12
    mov.l   .L_scene_flags, r13
    mov.l   .L_vram_base_in, r14
    mov.l r3, @r10
    mov.l r3, @(4, r10)
    mov.l @r11, r3
    mov.l r3, @r14
    mov.l @(4, r11), r2
    mov.l r2, @(4, r14)
    mov.w   DAT_06037154, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(8, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_nbg0_not_bit8
    mov.w   DAT_06037156, r2
    mov.w @(14, r12), r0
    mov r0, r3
    or r2, r3
    mov r3, r0
    bra     .L_nbg0_bit8_done
    nop
.L_nbg0_not_bit8:
    mov.l   .L_mask_clear_bit8, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_nbg0_bit8_done:
    mov.w r0, @(14, r12)
    mov.b @(9, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_nbg0_not_bit9
    mov.w   .L_bit9_set, r2
    mov.w @(14, r12), r0
    mov r0, r3
    or r2, r3
    mov r3, r0
    bra     .L_nbg0_bit9_done
    nop

    .global DAT_06037154
DAT_06037154:
    .2byte  0x7FFF

    .global DAT_06037156
DAT_06037156:
    .2byte  0x0100
.L_bit9_set:
    .2byte  0x0200
    .2byte  0xFFFF
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_vram_addr_out:
    .4byte  sym_060A4C44
.L_disp_ctrl_reg:
    .4byte  sym_060A3D88
.L_scene_flags:
    .4byte  sym_060A3E38
.L_vram_base_in:
    .4byte  sym_060A4C4C
.L_mask_clear_bit8:
    .4byte  0x0000FEFF
.L_nbg0_not_bit9:
    mov.l   .L_mask_clear_bit9, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_nbg0_bit9_done:
    mov #0x0, r5
    mov #0x4, r2
    mov.w r0, @(14, r12)
    extu.b r5, r4
    mov.b @(10, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt/s    .L_bank0_ge4
    extu.b r5, r8
    mov.w @(14, r12), r0
    mov.l   .L_mask_clear_bank0, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(10, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(10, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_after_bank0
    mov.l @r14, r0
    tst r0, r0
    bt      .L_bank0_base_zero
    mov.l   .L_mask_clear_bank0, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_bank0_after_base
    mov.w r0, @(14, r12)
.L_bank0_base_zero:
    mov #0x1, r8
.L_bank0_after_base:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_vdp2_vram_0x00000, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_after_bank0
    mov #0x1, r4
.L_bank0_ge4:
    mov.b @(10, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_after_bank0
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x00000, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_after_bank0:
    mov.b @(11, r11), r0
    mov #0x4, r2
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_bank1_ge4
    mov.w @(14, r12), r0
    mov.l   .L_mask_clear_bank1, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(11, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(11, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_after_bank1
    extu.b r4, r2
    tst r2, r2
    bf      .L_bank1_secondary
    mov.l @r14, r0
    tst r0, r0
    bt      .L_bank1_base_zero
    mov.l   .L_mask_clear_bank1, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_bank1_after_base
    mov.w r0, @(14, r12)
.L_bank1_base_zero:
    mov #0x2, r8
.L_bank1_after_base:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x1, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_vdp2_vram_0x20000, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_bank1_done
    mov #0x1, r4
.L_bank1_secondary:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_bank1_sec_base_ok
    mov.l   .L_mask_clear_bank1, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_bank1_sec_base_ok:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_0603728e, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x20000, r2
    add r2, r3
    mov.l r3, @(4, r10)
    add #0x1, r4
.L_bank1_done:
    bra     .L_after_bank1
    nop

    .global DAT_0603728e
DAT_0603728e:
    .2byte  0x0100
.L_mask_clear_bit9:
    .4byte  0x0000FDFF
.L_mask_clear_bank0:
    .4byte  0x0000FFFC
.L_vdp2_vram_0x00000:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_mask_clear_bank1:
    .4byte  0x0000FFF3
.L_vdp2_vram_0x20000:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_bank1_ge4:
    mov.b @(11, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_after_bank1
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_06037362, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x20000_b, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_after_bank1:
    mov #0x4, r2
    mov.b @(12, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_bank2_ge4
    mov.w @(14, r12), r0
    mov.l   .L_mask_clear_bank2, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(12, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(12, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_after_bank2
    extu.b r4, r2
    tst r2, r2
    bf      .L_bank2_secondary
    mov.l @r14, r0
    tst r0, r0
    bt      .L_bank2_base_zero
    mov.l   .L_mask_clear_bank2, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_bank2_after_base
    mov.w r0, @(14, r12)
.L_bank2_base_zero:
    mov #0x3, r8
.L_bank2_after_base:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x2, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_vdp2_vram_0x40000, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_bank2_done
    mov #0x1, r4
.L_bank2_secondary:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_bank2_sec_base_ok
    mov.l   .L_mask_clear_bank2, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_bank2_sec_base_ok:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   .L_bank2_byte_hi, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    add #0x1, r4
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x40000, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_bank2_done:
    bra     .L_after_bank2
    nop

    .global DAT_06037362
DAT_06037362:
    .2byte  0x0100
.L_bank2_byte_hi:
    .2byte  0x0200
    .2byte  0xFFFF
.L_vdp2_vram_0x20000_b:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_mask_clear_bank2:
    .4byte  0x0000FFCF
.L_vdp2_vram_0x40000:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_bank2_ge4:
    mov.b @(12, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_after_bank2
    mov.l   .L_secondary_enable, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_after_bank2
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_0603743a, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x40000_b, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_after_bank2:
    mov #0x4, r2
    mov.b @(13, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_bank3_ge4
    mov.w @(14, r12), r0
    mov.l   .L_mask_clear_bank3, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(13, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    shll2 r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(13, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_after_bank3
    extu.b r4, r4
    tst r4, r4
    bf      .L_bank3_secondary
    mov.l @r14, r0
    tst r0, r0
    bt      .L_bank3_base_zero
    mov.l   .L_mask_clear_bank3, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_bank3_after_base
    mov.w r0, @(14, r12)
.L_bank3_base_zero:
    mov #0x4, r8
.L_bank3_after_base:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x3, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_vdp2_vram_0x60000, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_bank3_done
    nop
.L_bank3_secondary:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_bank3_sec_base_ok
    mov.l   .L_mask_clear_bank3, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_bank3_sec_base_ok:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   .L_bank3_byte_hi, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x60000, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_bank3_done:
    bra     .L_after_bank3
    nop

    .global DAT_0603743a
DAT_0603743a:
    .2byte  0x0200
.L_bank3_byte_hi:
    .2byte  0x0300
    .2byte  0xFFFF
.L_secondary_enable:
    .4byte  sym_060A4C50
.L_vdp2_vram_0x40000_b:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_mask_clear_bank3:
    .4byte  0x0000FF3F
.L_vdp2_vram_0x60000:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_bank3_ge4:
    mov.b @(13, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_after_bank3
    mov.l   .L_secondary_enable_b, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_after_bank3
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_06037532, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_vdp2_vram_0x60000_b, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_after_bank3:
    mov.l @(4, r10), r0
    tst r0, r0
    bt      .L_no_secondary_addr
    bra     .L_epilogue
    nop
.L_no_secondary_addr:
    mov.b @(14, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_after_vis_check
    mov.l   .L_vram_addr_out_b, r2
    mov.l @r2, r0
    tst r0, r0
    bf      .L_after_vis_check
    mov.l   .L_fn_visibility_check, r3
    jsr @r3
    nop
    cmp/eq #0x1, r0
    bf      .L_after_vis_check
    mov.l   .L_fp_half, r3
    mov.w @(14, r12), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.l   .L_vdp2_cram_0x800, r3
    mov.l r3, @r10
    bra     .L_epilogue
    nop
.L_after_vis_check:
    mov.l @r10, r0
    tst r0, r0
    bt      .L_both_addr_zero
    mov.l   .L_secondary_active, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_both_addr_zero
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_after_offset_calc
    mov.l @r14, r3
    mov.w   .L_vram_offset_0x400, r2
    add r2, r3
    mov.l r3, @(4, r14)
.L_after_offset_calc:
    mov.l @r14, r0
    tst r0, r0
    bf      .L_ensure_base_nonzero
    mov #-0x1, r3
    mov.l r3, @r14
.L_ensure_base_nonzero:
    mov.l @(4, r14), r2
    mov.l @r10, r3
    add r3, r2
    mov.l r2, @(4, r10)
    mov.w @(6, r13), r0
    mov r0, r4
    extu.w r4, r4
    mov.w   DAT_06037536, r3
    and r4, r3
    mov r4, r2
    shll8 r2
    or r2, r3
    extu.w r3, r0
    mov.w r0, @(6, r13)
    bra     .L_dispatch_switch
    extu.b r8, r0
.L_dispatch_bank0:
    mov.l   .L_mask_clear_bank0_b, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_dispatch_writeback
    nop
.L_dispatch_bank1:
    mov.l   .L_mask_clear_bank1_b, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_dispatch_writeback
    nop
.L_dispatch_bank2:
    mov.l   .L_mask_clear_bank2_b, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_dispatch_writeback
    nop
.L_dispatch_bank3:
    mov.l   .L_mask_clear_bank3_b, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_dispatch_writeback:
    bra     .L_epilogue
    mov.w r0, @(14, r12)

    .global DAT_06037532
DAT_06037532:
    .2byte  0x0300
.L_vram_offset_0x400:
    .2byte  0x0400

    .global DAT_06037536
DAT_06037536:
    .2byte  0x00FF
.L_secondary_enable_b:
    .4byte  sym_060A4C50
.L_vdp2_vram_0x60000_b:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_vram_addr_out_b:
    .4byte  sym_060A4C44
.L_fn_visibility_check:
    .4byte  sym_0603C156
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_vdp2_cram_0x800:
    .4byte  0x25F00800                  /* VDP2 color RAM +0x800 */
.L_secondary_active:
    .4byte  sym_060A4C59
.L_mask_clear_bank0_b:
    .4byte  0x0000FFFC
.L_mask_clear_bank1_b:
    .4byte  0x0000FFF3
.L_mask_clear_bank2_b:
    .4byte  0x0000FFCF
.L_mask_clear_bank3_b:
    .4byte  0x0000FF3F
.L_dispatch_switch:
    cmp/eq #0x1, r0
    bt      .L_dispatch_bank0
    cmp/eq #0x2, r0
    bt      .L_dispatch_bank1
    cmp/eq #0x3, r0
    bt      .L_dispatch_bank2
    cmp/eq #0x4, r0
    bt      .L_dispatch_bank3
    bra     .L_epilogue
    nop
.L_both_addr_zero:
    mov.l @r10, r0
    tst r0, r0
    bf      .L_epilogue
    mov.l @r14, r0
    tst r0, r0
    bt      .L_after_primary_path
    mov.l   .L_primary_active, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_after_primary_path
    mov.w @(6, r13), r0
    mov r14, r4
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(6, r13)
    mov.l   .L_fp_two, r0
    mov.l   .L_fn_bank_select, r3
    jsr @r3
    mov.l @r4, r1
    extu.w r0, r0
    mov #0x6, r2
    add r13, r2
    mov.w @r2, r2
    or r0, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r4, r3
    mov.l   .L_vdp2_vram_0x00000_b, r2
    add r2, r3
    mov.l r3, @r10
.L_after_primary_path:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_secondary_active_b, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_epilogue
    mov.w @(6, r13), r0
    mov r14, r4
    and #0xFF, r0
    add #0x4, r4
    mov.w r0, @(6, r13)
    mov.l   .L_fp_two, r0
    mov.l   .L_fn_bank_select, r3
    jsr @r3
    mov.l @r4, r1
    extu.w r0, r0
    shll8 r0
    mov #0x6, r2
    add r13, r2
    mov.w @r2, r2
    or r0, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r4, r3
    mov.l   .L_vdp2_vram_0x00000_b, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_primary_active:
    .4byte  sym_060A4C58
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fn_bank_select:
    .4byte  sym_06034FFC
.L_vdp2_vram_0x00000_b:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_secondary_active_b:
    .4byte  sym_060A4C59

    .global sym_06037618
sym_06037618:
    mov #0x10, r7
    mov #0x0, r5
    mov.b r5, @r4
    extu.b r5, r2
    mov r2, r0
    mov.b r0, @(1, r4)
    extu.b r5, r0
    mov.b r0, @(2, r4)
    extu.b r5, r0
    mov.b r0, @(3, r4)
    extu.b r5, r0
    mov.b r0, @(4, r4)
    extu.b r5, r0
    mov.b r0, @(5, r4)
    extu.b r5, r0
    mov.b r0, @(6, r4)
    extu.b r5, r0
    mov.b r0, @(8, r4)
    extu.b r5, r0
    mov.b r0, @(7, r4)
    extu.w r5, r3
    mov r3, r0
    mov.w r0, @(10, r4)
    extu.b r5, r6
.L_zero_loop:
    extu.b r6, r3
    mov r4, r2
    shll2 r3
    add #0x1, r6
    add #0xC, r2
    add r2, r3
    mov.l r5, @r3
    extu.b r6, r3
    cmp/ge r7, r3
    bf      .L_zero_loop
    rts
    nop
