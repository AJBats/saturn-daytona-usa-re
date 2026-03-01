
    .section .text.FUN_06020814


    .global obj_culling_pass
    .type obj_culling_pass, @function
obj_culling_pass:
    mov.l r14, @-r15
    mov r4, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    mov.b r0, @(4, r15)
    mov.l   .L_fn_gameover_channel, r3
    jsr @r3
    nop
    mov.l   .L_pal_src_cram200, r5
    mov.l   .L_vdp2_cram_0x200, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_obj_struct_base, r13
    mov.l   .L_fn_display_list_copy, r14
    mov.w   .L_off_struct_0x560, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_copy_len_0x294, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x0, r4
    mov #0x0, r11
    mov.l   .L_display_flags, r12
    mov.l   .L_collision_update_bit, r3
    mov.l @r12, r2
    or r3, r2
    mov.l r2, @r12
    mov #0x1, r3
    mov.l   .L_display_timer, r2
    mov.w r3, @r2
    mov.l   .L_frame_ready_flag, r3
    mov.l r11, @r3
    mov.l   .L_fn_display_update, r3
    jsr @r3
    nop
    mov.l   .L_collision_update_bit, r2
    mov.l @r12, r3
    or r2, r3
    mov.l r3, @r12
    mov #0x3, r2
    mov.l   .L_display_timer, r3
    mov.w r2, @r3
    mov.l   .L_frame_ready_flag, r3
    mov.l r11, @r3
    mov.l   .L_fn_display_update, r3
    jsr @r3
    nop
    mov.w   .L_off_struct_0x550, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_size_adj_0x6000, r3
    mov.w   .L_copy_len_0x82, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_display_list_addr_a, r7
    mov.w   .L_copy_len_0x61A, r6
    mov.l   .L_display_list_src_fixed, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_off_struct_0x368, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_size_adj_0x3000, r3
    mov.w   .L_copy_len_0x898, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_off_struct_0x378, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_size_adj_0x4000, r3
    mov.w   .L_copy_len_0x8B0, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.l   .L_fn_display_layer_cfg, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_obj_anim_mode_word, r3
    mov.w r11, @r3
    mov.b @(4, r15), r0
    mov r0, r4
    extu.b r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    bra     .L_epilogue
    nop
.L_off_struct_0x560:
    .2byte  0x0560                          /* struct offset: display list B ptr */
.L_copy_len_0x294:
    .2byte  0x0294                          /* copy length for list B */
.L_off_struct_0x550:
    .2byte  0x0550                          /* struct offset: display list C ptr */
.L_size_adj_0x6000:
    .2byte  0x6000                          /* size adjustment for list C */
.L_copy_len_0x82:
    .2byte  0x0082                          /* copy length for list C */
.L_display_list_addr_a:
    .2byte  0x7C5A                          /* fixed display list address */
.L_copy_len_0x61A:
    .2byte  0x061A                          /* copy length for fixed list */
.L_off_struct_0x368:
    .2byte  0x0368                          /* struct offset: display list D ptr */
.L_size_adj_0x3000:
    .2byte  0x3000                          /* size adjustment for list D */
.L_copy_len_0x898:
    .2byte  0x0898                          /* copy length for list D */
.L_off_struct_0x378:
    .2byte  0x0378                          /* struct offset: display list E ptr */
.L_size_adj_0x4000:
    .2byte  0x4000                          /* size adjustment for list E */
.L_copy_len_0x8B0:
    .2byte  0x08B0                          /* copy length for list E */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit / clear */
.L_fn_gameover_channel:
    .4byte  gameover_channel_setup          /* game-over display channel setup */
.L_pal_src_cram200:
    .4byte  sym_060489CC                    /* palette source for CRAM +0x200 */
.L_vdp2_cram_0x200:
    .4byte  0x25F00200                      /* VDP2 color RAM +0x200 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                 /* word-indexed memcpy */
.L_obj_struct_base:
    .4byte  sym_06063750                    /* obj/replay struct base ptr */
.L_fn_display_list_copy:
    .4byte  sym_06028400                    /* display list copy function */
.L_display_flags:
    .4byte  sym_0605B6D8                    /* display/event flags (32-bit) */
.L_collision_update_bit:
    .4byte  0x04000000                      /* bit 26 mask — collision update trigger */
.L_display_timer:
    .4byte  sym_0608780C                    /* display timer (16-bit word) */
.L_frame_ready_flag:
    .4byte  sym_0605A00C                    /* frame-ready flag (0 = not ready) */
.L_fn_display_update:
    .4byte  sym_06026CE0                    /* display update / render commit */
.L_display_list_src_fixed:
    .4byte  sym_0604BBCC                    /* fixed display list source data */
.L_fn_display_layer_cfg:
    .4byte  sym_0602853E                    /* display layer fill config */
.L_obj_anim_mode_word:
    .4byte  sym_06087828                    /* obj animation mode (16-bit word) */
.L_epilogue:
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA2, 0x54    /* bra 0x06020DEE (external) — tail-jump to obj_anim_clear */
    mov.l @r15+, r14
