
    .section .text.FUN_0603CD5C


    .global hud_display_large
    .type hud_display_large, @function
hud_display_large:
    mov.l r14, @-r15
    mov #0x1, r6
    mov.l r13, @-r15
    mov r6, r0
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0603ce8e, r11
    mov.l   .L_config_byte_ptr, r5
    mov.l   .L_vdp2_reg_block, r4
    mov.l   .L_fn_channel_commit_a, r3
    mov r5, r2
    jsr @r3
    mov r6, r1
    mov r6, r0
    mov.w @r4, r2
    mov.w   DAT_0603ce90, r3
    extu.w r2, r2
    and r11, r2
    or r3, r2
    mov.w r2, @r4
    mov r5, r2
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bit6_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov.l   .L_mask_clear_bit5, r7
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov r5, r2
    mov.w @r4, r0
    extu.w r0, r0
    and r7, r0
    or #0x20, r0
    mov.w r0, @r4
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    mov.l   .L_mask_clear_bit4_a, r14
    jsr @r3
    mov r6, r1
    mov.w @r4, r2
    mov r6, r0
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov r5, r2
    mov.l   .L_fn_channel_commit_a, r3
    mov.l   .L_mask_clear_lo_nib, r13
    jsr @r3
    mov r6, r1
    mov.w @r4, r0
    mov r5, r2
    extu.w r0, r0
    and r13, r0
    or #0x7, r0
    mov.w r0, @r4
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    mov.l   .L_mask_clear_mid_nib, r12
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov.l   .L_mask_clear_hi_nib_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    bra     .L_cfg_scroll_regs
    nop

    .global DAT_0603ce8e
DAT_0603ce8e:
    .2byte  0x0FFF

    .global DAT_0603ce90
DAT_0603ce90:
    .2byte  0x3000
    .2byte  0xFFFF
.L_config_byte_ptr:
    .4byte  sym_060A4D58
.L_vdp2_reg_block:
    .4byte  sym_060A4D18
.L_fn_channel_commit_a:
    .4byte  sym_06034F78
.L_mask_clear_bit6_a:
    .4byte  0x0000FFBF
.L_mask_clear_bit5:
    .4byte  0x0000FFDF
.L_mask_clear_bit4_a:
    .4byte  0x0000FFEF
.L_mask_clear_lo_nib:
    .4byte  0x0000FFF0
.L_mask_clear_mid_nib:
    .4byte  0x0000FF0F
.L_mask_clear_hi_nib_a:
    .4byte  0x0000F0FF
.L_cfg_scroll_regs:
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov.l   .L_mask_clear_hi_nib_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r5, r2
    mov.l   .L_mask_clear_bit0, r11
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov.l   .L_mask_clear_bit1, r12
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov.l   .L_mask_clear_bit2, r10
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    add #0x7, r13
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(8, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(8, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_mask_clear_bits01, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_mask_clear_bits23_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_mask_clear_bits45_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_mask_clear_bits67_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_mask_clear_bits89_a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    mov.w   DAT_0603d034, r3
    bra     .L_cfg_priority_regs
    nop

    .global DAT_0603d034
DAT_0603d034:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_fn_channel_commit_b:
    .4byte  sym_06034F78
.L_mask_clear_hi_nib_b:
    .4byte  0x0000F0FF
.L_mask_clear_bit0:
    .4byte  0x0000FFFE
.L_mask_clear_bit1:
    .4byte  0x0000FFFD
.L_mask_clear_bit2:
    .4byte  0x0000FFFB
.L_mask_clear_bits01:
    .4byte  0x0000FFFC
.L_mask_clear_bits23_a:
    .4byte  0x0000FFF3
.L_mask_clear_bits45_a:
    .4byte  0x0000FFCF
.L_mask_clear_bits67_a:
    .4byte  0x0000FF3F
.L_mask_clear_bits89_a:
    .4byte  0x0000FCFF
.L_cfg_priority_regs:
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bits12_14, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bit10, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bit9, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bit8_a, r3
    mov.w   DAT_0603d1c2, r1
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_mask_clear_bit6_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_mask_clear_bits01_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_mask_clear_bits23_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_mask_clear_bits45_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov r0, r2
    extu.w r2, r2
    bra     .L_cfg_colorcalc_regs
    nop

    .global DAT_0603d1c2
DAT_0603d1c2:
    .2byte  0x0100
.L_fn_channel_commit_c:
    .4byte  sym_06034F78
.L_mask_clear_bits12_14:
    .4byte  0x00008FFF
.L_mask_clear_bit10:
    .4byte  0x0000FBFF
.L_mask_clear_bit9:
    .4byte  0x0000FDFF
.L_mask_clear_bit8_a:
    .4byte  0x0000FEFF
.L_mask_clear_bit6_b:
    .4byte  0x0000FFBF
.L_mask_clear_bits01_b:
    .4byte  0x0000FFFC
.L_mask_clear_bits23_b:
    .4byte  0x0000FFF3
.L_mask_clear_bits45_b:
    .4byte  0x0000FFCF
.L_cfg_colorcalc_regs:
    mov.l   .L_mask_clear_bits67_b, r3
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(14, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_mask_clear_bits89_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(14, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov.l   .L_mask_clear_bit8_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r6, r1
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_mask_clear_bits67_b:
    .4byte  0x0000FF3F
.L_fn_channel_commit_d:
    .4byte  sym_06034F78
.L_mask_clear_bits89_b:
    .4byte  0x0000FCFF
.L_mask_clear_bit8_b:
    .4byte  0x0000FEFF
