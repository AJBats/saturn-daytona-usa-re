
   .section .text.FUN_06038AC8


   .global display_mode_config
   .type display_mode_config, @function
display_mode_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_config_byte, r14
    mov.l   .L_fn_hud_display, r3
    jsr @r3
    mov #0x0, r13

    mov r14, r0
    mov.b @r0, r0
    tst #0x80, r0
    bt      .L_check_ch1
    mov #0x10, r6
    mov.l   .L_ch0_src, r5
    mov.l   .L_ch0_dst_ptr, r4
    .byte   0xBF, 0xB0    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov r14, r2
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov #0x1, r1

.L_check_ch1:
    mov r14, r0
    mov.b @r0, r0
    tst #0x40, r0
    bt      .L_check_ch2
    mov #0x8, r6
    mov.l   .L_ch1_src, r5
    mov.l   .L_ch1_dst_ptr, r4
    .byte   0xBF, 0xA2    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_ch1_id, r1
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov r14, r2

.L_check_ch2:
    mov r14, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_check_ch3
    mov #0x6, r6
    mov.l   .L_ch2_src, r5
    mov.l   .L_ch2_dst_ptr, r4
    .byte   0xBF, 0x94    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_ch2_id, r1
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov r14, r2

.L_check_ch3:
    mov r14, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt      .L_check_ch4
    mov #0x8, r6
    mov.l   .L_ch3_src, r5
    mov.l   .L_ch3_dst_ptr, r4
    .byte   0xBF, 0x86    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_ch3_id, r1
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov r14, r2

.L_check_ch4:
    mov r14, r0
    mov.b @r0, r0
    tst #0x8, r0
    bt      .L_check_ch5
    mov #0x8, r6
    mov.l   .L_ch4_src, r5
    mov.l   .L_ch4_dst_ptr, r4
    .byte   0xBF, 0x78    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_ch4_id, r1
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov r14, r2

.L_check_ch5:
    mov r14, r0
    mov.b @r0, r0
    tst #0x4, r0
    bt      .L_epilogue
    mov #0x10, r6
    mov.l   .L_ch5_src, r5
    mov.l   .L_ch5_dst_ptr, r4
    bra     .L_ch5_load
    mov.l @r4, r4

.L_ch1_id:
    .2byte  0x0101                            /* channel 1 ID */
.L_ch2_id:
    .2byte  0x0201                            /* channel 2 ID */
.L_ch3_id:
    .2byte  0x0301                            /* channel 3 ID */
.L_ch4_id:
    .2byte  0x0401                            /* channel 4 ID */
.L_config_byte:
    .4byte  sym_060A4D58               /* display config byte (bitmask) */
.L_fn_hud_display:
    .4byte  hud_display_ext            /* HUD extended display setup */
.L_ch0_src:
    .4byte  sym_060A4D18               /* channel 0 source data */
.L_ch0_dst_ptr:
    .4byte  sym_0606360C               /* channel 0 dest pointer */
.L_fn_channel_commit:
    .4byte  sym_06034F78               /* channel data commit */
.L_ch1_src:
    .4byte  sym_060A4D28               /* channel 1 source data */
.L_ch1_dst_ptr:
    .4byte  sym_06063610               /* channel 1 dest pointer */
.L_ch2_src:
    .4byte  sym_060A4D30               /* channel 2 source data */
.L_ch2_dst_ptr:
    .4byte  sym_06063614               /* channel 2 dest pointer */
.L_ch3_src:
    .4byte  sym_060A4D36               /* channel 3 source data */
.L_ch3_dst_ptr:
    .4byte  sym_06063618               /* channel 3 dest pointer */
.L_ch4_src:
    .4byte  sym_060A4D3E               /* channel 4 source data */
.L_ch4_dst_ptr:
    .4byte  sym_0606361C               /* channel 4 dest pointer */
.L_ch5_src:
    .4byte  sym_060A4D46               /* channel 5 source data */
.L_ch5_dst_ptr:
    .4byte  sym_06063620               /* channel 5 dest pointer */

.L_ch5_load:
    .byte   0xBF, 0x46    /* bsr 0x06038A48 (data_loader) */
    nop
    mov r13, r0
    mov.w   .L_ch5_id, r1
    mov.l   .L_fn_channel_commit_b, r3
    jsr @r3
    mov r14, r2

.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_ch5_id:
    .2byte  0x0501                        /* channel 5 ID */
.L_fn_channel_commit_b:
    .4byte  sym_06034F78               /* channel data commit (same fn) */
