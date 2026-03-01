
    .section .text.FUN_060209AC


    .global obj_anim_driver
    .type obj_anim_driver, @function
obj_anim_driver:
    mov.l r14, @-r15
    mov r4, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_p_init_once_flag, r9
    mov.w   .L_w_loop_count, r13
    mov.l   .L_p_anim_frame_counter, r14
    mov.b r0, @(4, r15)
    mov.l   .L_wram_low, r12
    mov.b @r9, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_init_done
    mov.l   .L_p_sound_id, r5
    mov.l   .L_p_sound_cmd_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov #0x1, r2
    mov.b r2, @r9
.L_init_done:
    mov.l   .L_p_coeff_table_base, r3
    mov.l   .L_vdp2_reg_0x0A4, r2
    mov.l r3, @r2
    mov.w   .L_w_scroll_mode, r3
    add #-0xA, r2
    mov.w r3, @r2
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    mov.l   .L_vdp2_vram_0x5F800, r5
    mov #0x0, r4
.L_coeff_loop:
    extu.w r4, r0
    extu.w r4, r1
    mov.l   .L_p_mem_store_helper, r3
    shll2 r0
    mov r0, r8
    add r5, r8
    jsr @r3
    mov #0x2, r0
    tst r0, r0
    bt      .L_use_neg_scale
    bra     .L_store_coeff
    mov r12, r3
.L_w_loop_count:
    .2byte  0x0100                      /* 256 coefficient entries */
.L_w_scroll_mode:
    .2byte  0x0200                      /* VDP2 rotation scroll mode */
    .2byte  0xFFFF                      /* pool alignment padding */
.L_p_init_once_flag:
    .4byte  sym_0605F586                /* &init_once_flag (byte) */
.L_p_anim_frame_counter:
    .4byte  sym_06087828                /* &anim_frame_counter (word) */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_p_sound_id:
    .4byte  0xAB1129FF                  /* sound command ID */
.L_p_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch          /* sound command dispatch function */
.L_p_coeff_table_base:
    .4byte  0x12F2FC00                  /* VDP2 coefficient table base value */
.L_vdp2_reg_0x0A4:
    .4byte  0x25F800A4                  /* VDP2 KTCTL register (+0x0A4) */
.L_vdp2_vram_0x5F800:
    .4byte  0x25E5F800                  /* VDP2 VRAM +0x5F800 (coeff dest) */
.L_p_mem_store_helper:
    .4byte  sym_06035C2C                /* mem_store_helper function */
.L_use_neg_scale:
    mov.l   .L_p_neg_scale, r3
.L_store_coeff:
    add #0x1, r4
    mov.w @r14, r1
    extu.w r1, r1
    mul.l r1, r3
    sts macl, r3
    mov.l r3, @r8
    extu.w r4, r3
    cmp/ge r13, r3
    bf      .L_coeff_loop
    mov #0xA, r2
    mov.w @r14, r3
    extu.w r3, r3
    cmp/ge r2, r3
    bf      .L_early_exit
    mov.l   .L_p_race_state, r0
    mov.l @r0, r0
    cmp/eq #0x4, r0
    .word 0x0029
    mov.l   .L_p_demo_flag, r3
    mov.b @r3, r3
    tst r3, r3
    .word 0x0129
    and r1, r0
    mov.l   .L_p_anim_state_b, r3
    mov.l   .L_p_display_flags, r2
    mov.b @r3, r3
    mov.b @r2, r2
    and r3, r0
    and r2, r0
    tst r0, r0
    bt      .L_skip_list_copy
    mov.w   .L_w_vram_offset, r10
    mov.l   .L_p_course_obj_table, r11
    mov.l   .L_p_display_list_copy, r12
    mov.w   .L_w_list_offset_a, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_w_size_a, r6
    mov.l @r15, r5
    add r10, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov.w   .L_w_list_offset_b, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_w_size_b, r6
    mov.l @r15, r5
    add r10, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov.w   .L_w_list_offset_c, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_w_size_c, r6
    mov.l @r15, r5
    add r10, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
.L_skip_list_copy:
    .byte   0xBF, 0x44    /* bsr obj_lod_level (0x06020946) */
    nop
    mov #0x0, r2
    mov.b r2, @r9
    mov.b @(4, r15), r0
    mov r0, r4
    extu.b r4, r4
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA1, 0x88    /* bra obj_anim_clear (0x06020DEE) */
    mov.l @r15+, r14
.L_early_exit:
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_w_vram_offset:
    .2byte  0x3000                      /* VRAM destination offset */
.L_w_list_offset_a:
    .2byte  0x0568                      /* course struct offset A */
.L_w_size_a:
    .2byte  0x0498                      /* copy size A (bytes) */
.L_w_list_offset_b:
    .2byte  0x0570                      /* course struct offset B */
.L_w_size_b:
    .2byte  0x069C                      /* copy size B (bytes) */
.L_w_list_offset_c:
    .2byte  0x0578                      /* course struct offset C */
.L_w_size_c:
    .2byte  0x0B1E                      /* copy size C (bytes) */
    .2byte  0xFFFF                      /* pool alignment padding */
.L_p_neg_scale:
    .4byte  0xFFE00000                  /* negative scale (-2M, 14.18 fixed) */
.L_p_race_state:
    .4byte  sym_0605AD04                /* &race_state variable */
.L_p_demo_flag:
    .4byte  sym_06078637                /* &demo_flag byte */
.L_p_anim_state_b:
    .4byte  sym_06087824                /* &anim_state_b byte */
.L_p_display_flags:
    .4byte  sym_06085FF4                /* &display_flags byte */
.L_p_course_obj_table:
    .4byte  sym_06063750                /* &course_obj_table base */
.L_p_display_list_copy:
    .4byte  sym_06028400                /* display_list_copy function */
    .4byte  0x9611E500                  /* mov.w @(0x22,PC),r6 / mov #0x0,r5 */
    .4byte  0xD709D30A                  /* mov.l @(0x24,PC),r7 / mov.l @(0x28,PC),r3 */
    .4byte  0xD20A2232                  /* mov.l @(0x28,PC),r2 / mov.l r3,@r2 */
    .4byte  0x930C72F6                  /* mov.w @(0x18,PC),r3 / add #-0xA,r2 */
    .4byte  0x2231645D                  /* mov.w r3,@r2 / mov.b @r5,r4 (loop) */
    .4byte  0x604D4008                  /* extu.b r4,r0 / shll2 r0 */
    .4byte  0x7401634D                  /* add #0x1,r4 / extu.b r4,r3 */
    .4byte  0x33638FF9                  /* cmp/ge r6,r3 / bf loop */
    .4byte  0x0756000B                  /* div0s r5,r7 / rts */
    .4byte  0x00090100                  /* nop / 0x0100 (loop count) */
    .4byte  0x0200FFFF                  /* 0x0200 (scroll mode) / padding */
    .4byte  0x25E5F800                  /* VDP2 VRAM +0x5F800 */
    .4byte  0x12F2FC00                  /* coefficient table base */
    .4byte  0x25F800A4                  /* VDP2 KTCTL register (+0x0A4) */
