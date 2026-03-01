
    .section .text.FUN_0602052C


    .global obj_visibility_test
    .type obj_visibility_test, @function
obj_visibility_test:
    mov.l r14, @-r15
    mov r4, r0
    mov #0x3, r3
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.b r0, @(4, r15)
    mov.l   .L_display_timer, r2
    mov.w r3, @r2
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    nop
    mov.l   .L_fn_gameover_channel, r3
    jsr @r3
    nop
    mov.l   .L_fn_display_layer_cfg, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_fn_display_layer_cfg, r3
    jsr @r3
    mov #0x4, r4
    mov.l   .L_fn_memcpy_word, r14
    mov.l   .L_pal_src_cram6E0, r5
    mov.l   .L_vdp2_cram_0x6E0, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_src_cram300, r5
    mov.l   .L_vdp2_cram_0x300, r4
    jsr @r14
    mov #0x20, r6
    mov #0x20, r6
    mov.l   .L_pal_src_cram400, r2
    mov.l r2, @r15
    mov.l   .L_vdp2_cram_0x400, r4
    jsr @r14
    mov r2, r5
    mov #0x20, r6
    mov.l   .L_vdp2_cram_0x060, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_obj_struct_base, r13
    mov #0x0, r6
    mov.l   .L_fn_display_list_copy, r14
    mov.w   .L_off_struct_0x558, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_fp_half, r3
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov r6, r4
    mov.w   .L_off_struct_0x560, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_copy_len_0x294, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_off_struct_0x550, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_fp_adj_0x6000, r3
    mov.w   .L_copy_len_0x82, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0xC, r4
    mov #0x0, r6
    mov.l   .L_fn_display_channel_b, r14
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x4, r4
    mov.l   .L_fn_channel_nibble, r14
    mov.w   .L_chan_id_0x100, r4
    jsr @r14
    mov #0x0, r5
    mov #0x4, r5
    jsr @r14
    mov r5, r4
    mov #0x5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    bra     .L_channel_setup_cont
    mov #0x10, r4
.L_off_struct_0x558:
    .2byte  0x0558                          /* struct offset: display list A ptr */
.L_off_struct_0x560:
    .2byte  0x0560                          /* struct offset: display list B ptr */
.L_copy_len_0x294:
    .2byte  0x0294                          /* copy length for list B */
.L_off_struct_0x550:
    .2byte  0x0550                          /* struct offset: display list C ptr */
.L_fp_adj_0x6000:
    .2byte  0x6000                          /* size adjustment for list C */
.L_copy_len_0x82:
    .2byte  0x0082                          /* copy length for list C */
.L_chan_id_0x100:
    .2byte  0x0100                          /* channel ID for nibble config */
.L_display_timer:
    .4byte  sym_06087804                    /* display timer (16-bit word) */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit / clear */
.L_fn_gameover_channel:
    .4byte  gameover_channel_setup          /* game-over channel setup */
.L_fn_display_layer_cfg:
    .4byte  sym_0602853E                    /* display layer fill config */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                 /* word-indexed memcpy */
.L_pal_src_cram6E0:
    .4byte  sym_0604898C                    /* palette source for CRAM +0x6E0 */
.L_vdp2_cram_0x6E0:
    .4byte  0x25F006E0                      /* VDP2 color RAM +0x6E0 */
.L_pal_src_cram300:
    .4byte  sym_060489AC                    /* palette source for CRAM +0x300 */
.L_vdp2_cram_0x300:
    .4byte  0x25F00300                      /* VDP2 color RAM +0x300 */
.L_pal_src_cram400:
    .4byte  sym_060489CC                    /* palette source for CRAM +0x400 */
.L_vdp2_cram_0x400:
    .4byte  0x25F00400                      /* VDP2 color RAM +0x400 */
.L_vdp2_cram_0x060:
    .4byte  0x25F00060                      /* VDP2 color RAM +0x060 */
.L_obj_struct_base:
    .4byte  sym_06063750                    /* obj/replay struct base ptr */
.L_fn_display_list_copy:
    .4byte  sym_06028400                    /* display list copy function */
.L_fp_half:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_fn_display_channel_b:
    .4byte  display_channel_b               /* display channel enable */
.L_fn_channel_nibble:
    .4byte  channel_nibble_config           /* channel nibble configuration */
.L_channel_setup_cont:
    jsr @r14
    nop
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x1, r2
    mov.l   .L_obj_mode_flag, r3
    mov.b r2, @r3
    mov.b @(4, r15), r0
    mov r0, r4
    .byte   0xB3, 0xC9    /* bsr 0x06020DEE (external) */
    extu.b r4, r4
    mov.l   .L_obj_scale_z, r14
    mov.l   .L_fp_four, r2
    mov.l r2, @r14
    mov r2, r3
    mov.l   .L_obj_scale_x, r2
    mov.l r3, @r2
    mov.l @r14, r3
    mov.l   .L_obj_scale_y, r2
    mov.l r3, @r2
    mov.l   .L_fp_three, r5
    mov.l   .L_fp_176, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    nop
    mov r0, r4
    mov.l   .L_fn_fpdiv, r3
    jsr @r3
    mov.l @r14, r5
    mov.l   .L_obj_draw_x, r3
    mov.l r0, @r3
    mov.l @r14, r5
    mov.l   .L_fp_neg_one, r2
    mov.l   .L_fp_112, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_fn_fpdiv, r3
    jsr @r3
    mov.l @r14, r5
    mov.l   .L_obj_draw_y, r3
    mov.l r0, @r3
    mov.l   .L_fn_cmd_queue_init, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_obj_scale_y, r5
    mov.l   .L_obj_scale_x, r4
    mov.l   .L_fn_color_intensity, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.l   .L_obj_draw_y, r5
    mov.l   .L_obj_draw_x, r4
    mov.l   .L_fn_scene_write_add, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_fn_cmd_queue_commit, r3
    jmp @r3
    mov.l @r15+, r14
.L_obj_mode_flag:
    .4byte  sym_06059F6F                    /* obj visibility mode flag (byte) */
.L_obj_scale_z:
    .4byte  sym_06087820                    /* obj scale Z (16.16 fp) */
.L_fp_four:
    .4byte  0x00040000                      /* 4.0 (16.16 fixed-point) */
.L_obj_scale_x:
    .4byte  sym_06087818                    /* obj scale X (16.16 fp) */
.L_obj_scale_y:
    .4byte  sym_0608781C                    /* obj scale Y (16.16 fp) */
.L_fp_three:
    .4byte  0x00030000                      /* 3.0 (16.16 fixed-point) */
.L_fp_176:
    .4byte  0x00B00000                      /* 176.0 (16.16 fp) — half screen width */
.L_fn_fpmul:
    .4byte  fpmul                           /* fixed-point multiply */
.L_fn_fpdiv:
    .4byte  fpdiv_setup                     /* fixed-point divide */
.L_obj_draw_x:
    .4byte  sym_06087810                    /* obj draw X coordinate (16.16 fp) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                      /* -1.0 (16.16 fixed-point) */
.L_fp_112:
    .4byte  0x00700000                      /* 112.0 (16.16 fp) — half screen height */
.L_obj_draw_y:
    .4byte  sym_06087814                    /* obj draw Y coordinate (16.16 fp) */
.L_fn_cmd_queue_init:
    .4byte  sym_0603850C                    /* display cmd queue: init */
.L_fn_color_intensity:
    .4byte  scene_color_intensity           /* scene color intensity */
.L_fn_scene_write_add:
    .4byte  scene_data_write_add            /* scene data write (additive) */
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520                    /* display cmd queue: commit */
