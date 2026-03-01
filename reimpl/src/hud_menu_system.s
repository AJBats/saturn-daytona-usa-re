
    .section .text.FUN_0603C1A8


    .global hud_menu_system
    .type hud_menu_system, @function
hud_menu_system:
    mov.l r14, @-r15
    mov #0x1, r7
    mov.l r13, @-r15
    mov r7, r0
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x20, r11
    mov.l r9, @-r15
    mov #0x40, r9
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_mask_byte1, r8
    mov.l   .L_scroll_cfg_a, r10
    mov.l   .L_mask_clear_bit6, r12
    mov.l   .L_scroll_cfg_b, r13
    mov.l   .L_config_byte_ptr, r14
    mov.l   .L_reg_block_base, r6
    mov.l   .L_fn_channel_commit_a, r3
    mov r14, r2
    jsr @r3
    mov r7, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit9, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r14, r2
    mov r7, r0
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r7, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
    mov.w   .L_chan_mask_bit8, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch1
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch0_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_a, r1
    mov.l   .L_fn_channel_commit_a, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    bra     .L_check_ch1
    mov.w r2, @r13
.L_chan_mask_bit8:
    .2byte  0x0100
.L_chan_id_0301_a:
    .2byte  0x0301
    .4byte  sym_060A4DA6
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_scroll_cfg_a:
    .4byte  sym_060A4D3E
.L_mask_clear_bit6:
    .4byte  0x0000FFBF
.L_scroll_cfg_b:
    .4byte  sym_060A4D36
.L_config_byte_ptr:
    .4byte  sym_060A4D58
.L_reg_block_base:
    .4byte  sym_060A4D18
.L_fn_channel_commit_a:
    .4byte  sym_06034F78
.L_mask_clear_bit9:
    .4byte  0x0000FDFF
.L_mask_clear_bit8:
    .4byte  0x0000FEFF
.L_ch0_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch1:
    mov.w   .L_chan_mask_bit9, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch2
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch1_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_b, r1
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_ch2
    mov.w r0, @r13
.L_ch1_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch2:
    mov.w   .L_chan_mask_bit10, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch3
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch2_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_b, r1
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    bra     .L_check_ch3
    mov.w r0, @(2, r13)
.L_ch2_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch3:
    mov.w   .L_chan_mask_bit11, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch4
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch3_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_b, r1
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r13), r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_ch4
    mov.w r0, @(2, r13)
.L_chan_mask_bit9:
    .2byte  0x0200
.L_chan_id_0301_b:
    .2byte  0x0301
.L_chan_mask_bit10:
    .2byte  0x0400
.L_chan_mask_bit11:
    .2byte  0x0800
.L_fn_channel_commit_b:
    .4byte  sym_06034F78
.L_ch3_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch4:
    mov.w   DAT_0603c496, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch5
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch4_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_c, r1
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r14, r2
    mov.w @(4, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    bra     .L_check_ch5
    mov.w r0, @(4, r13)
.L_ch4_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch5:
    mov.w   DAT_0603c49a, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch6
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch5_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_c, r1
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r14, r2
    mov.w @(4, r13), r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_ch6
    mov.w r0, @(4, r13)
.L_ch5_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch6:
    mov.w   DAT_0603c49c, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_ch7
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch6_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_c, r1
    mov.l   .L_fn_channel_commit_c, r3
    jsr @r3
    mov r14, r2
    mov.w @(6, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    bra     .L_check_ch7
    mov.w r0, @(6, r13)

    .global DAT_0603c496
DAT_0603c496:
    .2byte  0x1000
.L_chan_id_0301_c:
    .2byte  0x0301

    .global DAT_0603c49a
DAT_0603c49a:
    .2byte  0x2000

    .global DAT_0603c49c
DAT_0603c49c:
    .2byte  0x4000
    .2byte  0xFFFF
.L_fn_channel_commit_c:
    .4byte  sym_06034F78
.L_ch6_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_ch7:
    mov.l   .L_fp_half, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_scroll_ab
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_ch7_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r9, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0301_d, r1
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r14, r2
    mov.w @(6, r13), r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_scroll_ab
    mov.w r0, @(6, r13)
.L_ch7_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_scroll_ab:
    mov #0x4, r3
    and r4, r3
    tst r3, r3
    bf      .L_scroll_ab_enable
    mov #0x2, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_scroll_cd
.L_scroll_ab_enable:
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_scroll_ab_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit0, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    or r7, r2
    extu.w r2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0401_a, r1
    mov.l   .L_fn_channel_commit_d, r3
    jsr @r3
    mov r14, r2
    mov.w @r10, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    bra     .L_check_scroll_cd
    mov.w r2, @r10
.L_chan_id_0301_d:
    .2byte  0x0301
.L_chan_id_0401_a:
    .2byte  0x0401
.L_fn_channel_commit_d:
    .4byte  sym_06034F78
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_mask_clear_bit0:
    .4byte  0x0000FFFE
.L_scroll_ab_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.l   .L_mask_clear_bit0_b, r3
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_scroll_cd:
    mov #0x8, r3
    and r4, r3
    tst r3, r3
    bf      .L_scroll_cd_enable
    mov.w   .L_chan_mask_bit7, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_priority
.L_scroll_cd_enable:
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_scroll_cd_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit1, r3
    extu.w r0, r0
    and r3, r0
    or #0x2, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0401_b, r1
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov r14, r2
    mov.w @r10, r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_priority
    mov.w r0, @r10
.L_scroll_cd_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.l   .L_mask_clear_bit1, r3
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_priority:
    mov #0x10, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_colorcalc
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_priority_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit2, r3
    extu.w r0, r0
    and r3, r0
    or #0x4, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0401_b, r1
    mov.l   .L_fn_channel_commit_e, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r10), r0
    mov r0, r2
    extu.w r2, r2
    and r8, r2
    extu.b r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    bra     .L_check_colorcalc
    mov.w r0, @(2, r10)
.L_chan_mask_bit7:
    .2byte  0x0080
.L_chan_id_0401_b:
    .2byte  0x0401
    .2byte  0xFFFF
.L_fn_channel_commit_e:
    .4byte  sym_06034F78
.L_mask_clear_bit0_b:
    .4byte  0x0000FFFE
.L_mask_clear_bit1:
    .4byte  0x0000FFFD
.L_mask_clear_bit2:
    .4byte  0x0000FFFB
.L_priority_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.l   .L_mask_clear_bit2_b, r3
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_colorcalc:
    mov r4, r3
    and r11, r3
    tst r3, r3
    bt      .L_check_special_fn
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_colorcalc_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov.l   .L_mask_clear_bit3, r3
    extu.w r0, r0
    and r3, r0
    or #0x8, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0401_c, r1
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r10), r0
    extu.w r0, r0
    and #0xFF, r0
    extu.b r5, r3
    shll8 r3
    or r3, r0
    extu.w r0, r0
    bra     .L_check_special_fn
    mov.w r0, @(2, r10)
.L_colorcalc_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.l   .L_mask_clear_bit3, r3
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_check_special_fn:
    and r7, r4
    tst r4, r4
    bt      .L_menu_cfg_return
    mov.l   .L_mask_clear_bit4, r4
    extu.b r5, r3
    cmp/ge r11, r3
    bt      .L_special_fn_disable
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    extu.w r0, r0
    and r4, r0
    or #0x10, r0
    mov.w r0, @(12, r6)
    mov r7, r0
    mov.w   .L_chan_id_0401_c, r1
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov r14, r2
    extu.b r5, r5
    mov r5, r0
    bra     .L_menu_cfg_return
    mov.w r0, @(4, r10)
.L_special_fn_disable:
    mov r7, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit_f, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(12, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r4, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r6)
.L_menu_cfg_return:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_chan_id_0401_c:
    .2byte  0x0401
.L_fn_channel_commit_f:
    .4byte  sym_06034F78
.L_mask_clear_bit2_b:
    .4byte  0x0000FFFB
.L_mask_clear_bit3:
    .4byte  0x0000FFF7
.L_mask_clear_bit4:
    .4byte  0x0000FFEF

    .global hud_display_ext
    .type hud_display_ext, @function
hud_display_ext:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x20, r15
    mov #0x0, r8
    mov.l   .L_dirty_flag_ptr, r9
    mov.l   .L_transition_ctr, r10
    mov.w   .L_field_stride_5, r11
    mov.w   .L_field_stride_3, r12
    mov #0x1, r13
    mov.w   DAT_0603c7ea, r14
    mov r15, r3
    add #0x1C, r3
    mov.l r3, @(4, r15)
    mov.l   .L_state_ptr, r4
    mov.b @r9, r0
    bra     .L_state_dispatch
    extu.b r0, r0
.L_state1_entry:
    mov.l @r4, r2
    mov.l   .L_max_frame_ptr, r3
    mov.l @r3, r3
    cmp/hi r3, r2
    bf      .L_state1_begin
    mov.l   .L_max_frame_ptr, r3
    mov.l @r3, r3
    add #0x1, r3
    mov.l   .L_max_frame_ptr, r2
    mov.l r3, @r2
    bra     .L_ext_return
    nop
.L_state1_begin:
    mov.b r8, @r9
    mov r8, r4
    mov.l   .L_chan_data_array, r2
    mov r2, r5
    bra     .L_interp_loop_check
    mov.l r5, @r15
.L_interp_loop_body:
    mov.l @r15, r5
    add r4, r5
    mov r5, r2
    mov.b @r5, r3
    add r12, r2
    extu.b r3, r3
    mov.b @r2, r1
    extu.b r1, r1
    cmp/gt r1, r3
    bf      .L_field3_check_dec
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r12), r3
    add #0x1, r3
    mov.b r3, @(r0, r12)
    extu.b r13, r2
    bra     .L_check_field1
    mov.b r2, @r9
.L_field3_check_dec:
    mov.l @r15, r5
    add r4, r5
    mov r5, r2
    mov.b @r5, r3
    add r12, r2
    extu.b r3, r3
    mov.b @r2, r1
    extu.b r1, r1
    cmp/ge r1, r3
    bt      .L_check_field1
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r12), r3
    add #-0x1, r3
    mov.b r3, @(r0, r12)
    extu.b r13, r2
    mov.b r2, @r9
.L_check_field1:
    mov.l @r15, r5
    mov.w   .L_field_stride_1, r0
    add r4, r5
    mov r5, r2
    mov.b @(r0, r5), r3
    add r14, r2
    extu.b r3, r3
    mov.b @r2, r1
    extu.b r1, r1
    cmp/gt r1, r3
    bf      .L_field1_check_dec
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r14), r3
    add #0x1, r3
    mov.b r3, @(r0, r14)
    extu.b r13, r2
    bra     .L_check_field5
    mov.b r2, @r9
.L_field_stride_5:
    .2byte  0x0500
.L_field_stride_3:
    .2byte  0x0300

    .global DAT_0603c7ea
DAT_0603c7ea:
    .2byte  0x0400
.L_field_stride_1:
    .2byte  0x0100
    .2byte  0xFFFF
.L_dirty_flag_ptr:
    .4byte  sym_060A4DA6
.L_transition_ctr:
    .4byte  sym_060A4DA4
.L_state_ptr:
    .4byte  sym_060A4D88
.L_max_frame_ptr:
    .4byte  sym_060A4D8C
.L_chan_data_array:
    .4byte  sym_060A4DA8
.L_field1_check_dec:
    mov.l @r15, r5
    mov.w   .L_field_stride_1b, r0
    add r4, r5
    mov r5, r2
    mov.b @(r0, r5), r3
    add r14, r2
    extu.b r3, r3
    mov.b @r2, r1
    extu.b r1, r1
    cmp/ge r1, r3
    bt      .L_check_field5
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r14), r3
    add #-0x1, r3
    mov.b r3, @(r0, r14)
    extu.b r13, r2
    mov.b r2, @r9
.L_check_field5:
    mov.l @r15, r5
    mov.w   .L_field_stride_2, r0
    add r4, r5
    mov r5, r2
    mov.b @(r0, r5), r3
    add r11, r2
    extu.b r3, r3
    mov.b @r2, r1
    extu.b r1, r1
    cmp/gt r1, r3
    bf      .L_field5_check_dec
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r11), r3
    add #0x1, r3
    mov.b r3, @(r0, r11)
    extu.b r13, r2
    bra     .L_interp_next_chan
    mov.b r2, @r9
.L_field5_check_dec:
    mov.l @r15, r5
    mov.w   .L_field_stride_2, r0
    add r4, r5
    mov.b @(r0, r5), r3
    mov r5, r2
    extu.b r3, r3
    add r11, r2
    mov.b @r2, r1
    extu.b r1, r1
    cmp/ge r1, r3
    bt      .L_interp_next_chan
    mov.l @r15, r0
    add r4, r0
    mov.b @(r0, r11), r3
    add #-0x1, r3
    mov.b r3, @(r0, r11)
    extu.b r13, r2
    mov.b r2, @r9
.L_interp_next_chan:
    add #0x1, r4
.L_interp_loop_check:
    mov.l   .L_num_channels_ptr, r3
    mov.l @r3, r3
    cmp/hs r3, r4
    bt      .L_interp_done
    bra     .L_interp_loop_body
    nop
.L_interp_done:
    mov.l   .L_max_frame_reset, r3
    mov.l r8, @r3
    mov.l   .L_display_mode_reg, r4
    mov.w   DAT_0603c8d4, r3
    mov.w @r4, r4
    extu.w r4, r4
    and r3, r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .L_mode_not2_pack
    mov.l r8, @r15
    mov.l @(4, r15), r4
    mov r4, r3
    add #0x1, r3
    mov.l r3, @(20, r15)
    mov.l   .L_chan_data_array_b, r2
    mov.l r2, @(24, r15)
    mov r4, r2
    add #0x2, r2
    mov.l r2, @(8, r15)
    mov r4, r1
    add #0x3, r1
    mov.l r1, @(16, r15)
    mov r15, r3
    add #0x1C, r3
    add r8, r3
    bra     .L_mode2_copy_check
    mov.l r3, @(12, r15)
.L_field_stride_1b:
    .2byte  0x0100
.L_field_stride_2:
    .2byte  0x0200

    .global DAT_0603c8d4
DAT_0603c8d4:
    .2byte  0x3000
    .2byte  0xFFFF
.L_num_channels_ptr:
    .4byte  sym_060A4D94
.L_max_frame_reset:
    .4byte  sym_060A4D8C
.L_display_mode_reg:
    .4byte  sym_060A3D96
.L_chan_data_array_b:
    .4byte  sym_060A4DA8
.L_mode2_copy_loop:
    mov.l @(4, r15), r3
    mov #0x1, r6
    mov.b r8, @r3
    mov.l @(20, r15), r3
    mov.l @(24, r15), r4
    mov.l @r15, r2
    add r2, r4
    mov r4, r1
    mov r4, r2
    add r12, r1
    add r14, r2
    add r11, r4
    mov.b @r1, r0
    mov.b r0, @r3
    mov.l @(8, r15), r3
    mov.b @r2, r1
    mov.b r1, @r3
    mov.l @(16, r15), r3
    mov.b @r4, r2
    mov.b r2, @r3
    mov.l @(12, r15), r7
    mov.l   .L_palette_src_ptr, r5
    mov.l @r15, r3
    mov.l   .L_palette_mask_ptr, r4
    mov.l   .L_fn_palette_effect, r2
    mov.l @r5, r5
    add r3, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @r15, r3
    add #0x1, r3
    mov.l r3, @r15
.L_mode2_copy_check:
    mov.l @r15, r3
    mov.l   .L_num_channels_ptr_b, r2
    mov.l @r2, r2
    cmp/hs r2, r3
    bf      .L_mode2_copy_loop
    bra     .L_state1_exit
    nop
.L_mode_not2_pack:
    mov.l r8, @(4, r15)
    mov r15, r3
    add #0x1C, r3
    add r8, r3
    mov.l r3, @r15
    mov.l   .L_chan_data_array_c, r2
    mov.l r2, @(8, r15)
    bra     .L_pack_loop_check
    nop
.L_pack_loop_body:
    mov.l @r15, r3
    mov.l @(8, r15), r4
    mov.l @(4, r15), r2
    add r2, r4
    mov r4, r1
    mov r4, r2
    add r12, r1
    add r14, r2
    add r11, r4
    mov.b @r1, r0
    extu.b r0, r0
    mov.l r0, @r3
    mov.l @r15, r3
    mov.b @r2, r1
    mov r3, r2
    extu.b r1, r1
    mov.l @r2, r2
    shll2 r2
    shll2 r2
    shll r2
    or r2, r1
    mov.l r1, @r3
    mov.l @r15, r3
    mov.b @r4, r2
    mov r3, r1
    extu.b r2, r2
    mov.l @r1, r1
    shll2 r1
    shll2 r1
    shll r1
    or r1, r2
    mov.l r2, @r3
    mov #0x1, r6
    mov.l @r15, r7
    mov.l   .L_palette_src_ptr, r5
    mov.l @(4, r15), r3
    mov.l   .L_palette_mask_ptr, r4
    mov.l   .L_fn_palette_effect, r2
    mov.l @r5, r5
    add r3, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(4, r15), r3
    add #0x1, r3
    mov.l r3, @(4, r15)
.L_pack_loop_check:
    mov.l @(4, r15), r3
    mov.l   .L_num_channels_ptr_b, r2
    mov.l @r2, r2
    cmp/hs r2, r3
    bf      .L_pack_loop_body
.L_state1_exit:
    bra     .L_ext_return
    nop
.L_palette_src_ptr:
    .4byte  sym_060A4D90
.L_palette_mask_ptr:
    .4byte  sym_060A4D84
.L_fn_palette_effect:
    .4byte  color_palette_effect
.L_num_channels_ptr_b:
    .4byte  sym_060A4D94
.L_chan_data_array_c:
    .4byte  sym_060A4DA8
.L_state2_entry:
    mov.l @r4, r2
    mov.l   .L_max_frame_ptr_b, r3
    mov.l @r3, r3
    cmp/hi r3, r2
    bf      .L_state2_begin
    mov.l   .L_max_frame_ptr_b, r3
    mov.l @r3, r3
    add #0x1, r3
    mov.l   .L_max_frame_ptr_b, r2
    mov.l r3, @r2
    bra     .L_ext_return
    nop
.L_state2_begin:
    mov.l   .L_anim_limit_ptr, r4
    mov.l   .L_anim_dir_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_anim_decrement
    mov.b @r10, r3
    add #0x1, r3
    mov.b r3, @r10
    mov.b @r10, r2
    mov.b @r4, r3
    extu.b r2, r2
    extu.b r3, r3
    cmp/ge r3, r2
    bf      .L_dispatch_channels
    mov.b @r4, r3
    mov.b r3, @r10
    extu.b r8, r2
    bra     .L_dispatch_channels
    mov.b r2, @r9
.L_max_frame_ptr_b:
    .4byte  sym_060A4D8C
.L_anim_limit_ptr:
    .4byte  sym_060A4DA5
.L_anim_dir_flag:
    .4byte  sym_060A4DA7
.L_anim_decrement:
    mov.b @r10, r2
    add #-0x1, r2
    mov.b r2, @r10
    mov.b @r10, r3
    mov.b @r4, r2
    extu.b r3, r3
    extu.b r2, r2
    cmp/gt r2, r3
    bt      .L_dispatch_channels
    mov.b @r4, r2
    mov.b r2, @r10
    extu.b r8, r3
    mov.b r3, @r9
.L_dispatch_channels:
    mov.l   .L_chan_enable_mask, r2
    mov.w   .L_chan_mask_0100, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch1
    mov.w   .L_chan_mask_0100, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch1:
    mov.l   .L_chan_enable_mask, r2
    mov.w   .L_chan_mask_0200, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch2
    mov.w   .L_chan_mask_0200, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch2:
    mov.l   .L_chan_enable_mask, r2
    mov.l @r2, r2
    and r14, r2
    tst r2, r2
    bt      .L_dispatch_ch3
    mov.b @r10, r5
    bsr     hud_menu_system
    mov r14, r4
.L_dispatch_ch3:
    mov.l   .L_chan_enable_mask, r2
    mov.w   .L_chan_mask_0800, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch4
    mov.w   .L_chan_mask_0800, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch4:
    mov.l   .L_chan_enable_mask, r2
    mov.w   DAT_0603cade, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch5
    mov.w   DAT_0603cade, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch5:
    mov.l   .L_chan_enable_mask, r2
    mov.w   DAT_0603cae0, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch6
    mov.w   DAT_0603cae0, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch6:
    mov.l   .L_chan_enable_mask, r2
    mov.w   DAT_0603cae2, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch7
    mov.w   DAT_0603cae2, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch7:
    mov.l   .L_chan_enable_mask, r2
    mov.l   .L_chan_mask_8000, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_dispatch_ch8
    mov.l   .L_chan_mask_8000, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_dispatch_ch8:
    mov.l   .L_chan_enable_mask, r0
    mov.l @r0, r0
    tst #0x4, r0
    bt      .L_dispatch_ch9
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x4, r4
.L_dispatch_ch9:
    mov.l   .L_chan_enable_mask, r0
    mov.l @r0, r0
    tst #0x8, r0
    bt      .L_dispatch_done
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x8, r4
.L_dispatch_done:
    bra     .L_dispatch_ext
    nop
.L_chan_mask_0100:
    .2byte  0x0100
.L_chan_mask_0200:
    .2byte  0x0200
.L_chan_mask_0800:
    .2byte  0x0800

    .global DAT_0603cade
DAT_0603cade:
    .2byte  0x1000

    .global DAT_0603cae0
DAT_0603cae0:
    .2byte  0x2000

    .global DAT_0603cae2
DAT_0603cae2:
    .2byte  0x4000
.L_chan_enable_mask:
    .4byte  sym_060A4D84
.L_chan_mask_8000:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_dispatch_ext:
    mov.l   .L_chan_enable_mask_b, r0
    mov.l @r0, r0
    tst #0x10, r0
    bt      .L_dispatch_ch_0x20
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x10, r4
.L_dispatch_ch_0x20:
    mov.l   .L_chan_enable_mask_b, r0
    mov.l @r0, r0
    tst #0x20, r0
    bt      .L_dispatch_ch_0x01
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x20, r4
.L_dispatch_ch_0x01:
    mov.l   .L_chan_enable_mask_b, r2
    mov.l @r2, r2
    and r13, r2
    tst r2, r2
    bt      .L_dispatch_ch_0x02
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x1, r4
.L_dispatch_ch_0x02:
    mov.l   .L_chan_enable_mask_b, r0
    mov.l @r0, r0
    tst #0x2, r0
    bt      .L_dispatch_ch_0x80
    mov.b @r10, r5
    bsr     hud_menu_system
    mov #0x2, r4
.L_dispatch_ch_0x80:
    mov.l   .L_chan_enable_mask_b, r0
    mov.l @r0, r0
    tst #0x80, r0
    bt      .L_state2_complete
    mov.w   .L_chan_mask_0080, r4
    bsr     hud_menu_system
    mov.b @r10, r5
.L_state2_complete:
    mov.l   .L_max_frame_ptr_c, r3
    mov.l r8, @r3
    bra     .L_ext_return
    nop
.L_state3_entry:
    mov.l @r4, r2
    mov.l   .L_max_frame_ptr_c, r3
    mov.l @r3, r3
    cmp/hi r3, r2
    bf      .L_state3_begin
    mov.l   .L_max_frame_ptr_c, r3
    mov.l @r3, r3
    add #0x1, r3
    mov.l   .L_max_frame_ptr_c, r2
    mov.l r3, @r2
    bra     .L_ext_return
    nop
.L_state3_begin:
    mov.l   .L_delta_r_ptr, r7
    mov.l   .L_delta_g_ptr, r6
    mov.l   .L_delta_b_ptr, r5
    mov.l   .L_chan_enable_mask_b, r4
    mov.w @r7, r7
    mov.w @r6, r6
    mov.w @r5, r5
    bsr     display_palette_calc
    mov.l @r4, r4
    mov.l   .L_accum_b_ptr, r4
    mov.l   .L_delta_b_ptr, r5
    mov.w @r4, r2
    mov.w @r5, r5
    sub r5, r2
    mov.w r2, @r4
    mov.l   .L_delta_g_ptr, r3
    mov.l   .L_accum_g_ptr, r2
    mov.w @r3, r3
    mov.w @r2, r2
    sub r3, r2
    mov.l   .L_accum_g_ptr, r3
    mov.w r2, @r3
    mov.l   .L_delta_r_ptr, r1
    mov.l   .L_accum_r_ptr, r3
    mov.w @r1, r1
    mov.w @r3, r3
    sub r1, r3
    mov.l   .L_accum_r_ptr, r1
    cmp/pl r5
    bf/s    .L_clamp_b_neg
    mov.w r3, @r1
    mov.w @r4, r3
    cmp/pl r3
    bt      .L_clamp_g
    exts.w r8, r3
    mov.l   .L_delta_b_ptr, r2
    mov.w r3, @r2
    bra     .L_clamp_g
    nop
.L_chan_mask_0080:
    .2byte  0x0080
.L_chan_enable_mask_b:
    .4byte  sym_060A4D84
.L_max_frame_ptr_c:
    .4byte  sym_060A4D8C
.L_delta_r_ptr:
    .4byte  sym_060A4D9C
.L_delta_g_ptr:
    .4byte  sym_060A4D9A
.L_delta_b_ptr:
    .4byte  sym_060A4D98
.L_accum_b_ptr:
    .4byte  sym_060A4D9E
.L_accum_g_ptr:
    .4byte  sym_060A4DA0
.L_accum_r_ptr:
    .4byte  sym_060A4DA2
.L_clamp_b_neg:
    mov.w @r4, r2
    cmp/pz r2
    bf      .L_clamp_g
    exts.w r8, r2
    mov.l   .L_delta_b_ptr_b, r3
    mov.w r2, @r3
.L_clamp_g:
    mov.l   .L_delta_g_ptr_b, r2
    mov.w @r2, r2
    cmp/pl r2
    bf      .L_clamp_g_neg
    mov.l   .L_accum_g_ptr_b, r2
    mov.w @r2, r2
    cmp/pl r2
    bt      .L_clamp_r
    exts.w r8, r2
    mov.l   .L_delta_g_ptr_b, r3
    mov.w r2, @r3
    bra     .L_clamp_r
    nop
.L_clamp_g_neg:
    mov.l   .L_accum_g_ptr_b, r2
    mov.w @r2, r2
    cmp/pz r2
    bf      .L_clamp_r
    exts.w r8, r2
    mov.l   .L_delta_g_ptr_b, r3
    mov.w r2, @r3
.L_clamp_r:
    mov.l   .L_delta_r_ptr_b, r2
    mov.w @r2, r2
    cmp/pl r2
    bf      .L_clamp_r_neg
    mov.l   .L_accum_r_ptr_b, r2
    mov.w @r2, r2
    cmp/pl r2
    bt      .L_check_all_zero
    exts.w r8, r2
    mov.l   .L_delta_r_ptr_b, r3
    mov.w r2, @r3
    bra     .L_check_all_zero
    nop
.L_clamp_r_neg:
    mov.l   .L_accum_r_ptr_b, r2
    mov.w @r2, r2
    cmp/pz r2
    bf      .L_check_all_zero
    exts.w r8, r2
    mov.l   .L_delta_r_ptr_b, r3
    mov.w r2, @r3
.L_check_all_zero:
    mov.l   .L_delta_b_ptr_b, r2
    mov.w @r2, r2
    tst r2, r2
    bf      .L_state3_finalize
    mov.l   .L_delta_g_ptr_b, r3
    mov.w @r3, r3
    tst r3, r3
    bf      .L_state3_finalize
    mov.l   .L_delta_r_ptr_b, r3
    mov.w @r3, r3
    tst r3, r3
    bf      .L_state3_finalize
    extu.b r8, r3
    mov.b r3, @r9
.L_state3_finalize:
    mov.l   .L_max_frame_ptr_d, r3
    mov.l r8, @r3
    bra     .L_ext_return
    nop
.L_state_dispatch:
    cmp/eq #0x1, r0
    bf      .L_not_state1
    bra     .L_state1_entry
    nop
.L_not_state1:
    cmp/eq #0x2, r0
    bf      .L_not_state2
    bra     .L_state2_entry
    nop
.L_not_state2:
    cmp/eq #0x3, r0
    bf      .L_ext_return
    bra     .L_state3_entry
    nop
.L_ext_return:
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_delta_b_ptr_b:
    .4byte  sym_060A4D98
.L_delta_g_ptr_b:
    .4byte  sym_060A4D9A
.L_accum_g_ptr_b:
    .4byte  sym_060A4DA0
.L_delta_r_ptr_b:
    .4byte  sym_060A4D9C
.L_accum_r_ptr_b:
    .4byte  sym_060A4DA2
.L_max_frame_ptr_d:
    .4byte  sym_060A4D8C

    .global display_palette_calc
    .type display_palette_calc, @function
display_palette_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_config_byte_ptr_b, r11
    mov.w   DAT_0603cd4c, r13
    mov.l   .L_color_offset_regs, r14
    tst r4, r4
    bf/s    .L_apply_screen_b
    mov #0x1, r12
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    mov.w @(4, r14), r0
    exts.w r5, r5
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    add r5, r2
    extu.w r2, r0
    mov.w r0, @(4, r14)
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    exts.w r6, r6
    mov.w @(6, r14), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    add r6, r2
    extu.w r2, r0
    mov.w r0, @(6, r14)
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    mov.w @(8, r14), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    exts.w r7, r7
    add r7, r2
    extu.w r2, r2
    mov r2, r0
    bra     .L_palette_calc_return
    mov.w r0, @(8, r14)
.L_apply_screen_b:
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    exts.w r5, r5
    mov.w @(10, r14), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    add r5, r2
    extu.w r2, r0
    mov.w r0, @(10, r14)
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    mov.w @(12, r14), r0
    exts.w r6, r6
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    add r6, r2
    extu.w r2, r0
    mov.w r0, @(12, r14)
    mov r12, r0
    mov.w   .L_chan_id_0501, r1
    mov.l   .L_fn_channel_commit_g, r3
    jsr @r3
    mov r11, r2
    mov.w @(14, r14), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    exts.w r7, r7
    add r7, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r14)
.L_palette_calc_return:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0603cd4c
DAT_0603cd4c:
    .2byte  0x01FF
.L_chan_id_0501:
    .2byte  0x0501
.L_config_byte_ptr_b:
    .4byte  sym_060A4D58
.L_color_offset_regs:
    .4byte  sym_060A4D46
.L_fn_channel_commit_g:
    .4byte  sym_06034F78
