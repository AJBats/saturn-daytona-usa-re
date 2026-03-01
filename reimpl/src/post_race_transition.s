
    .section .text.FUN_0600F650


    .global post_race_transition
    .type post_race_transition, @function
post_race_transition:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_fn_layer_setup, r13
    mov.l   .L_fn_audio_init, r3
    jsr @r3
    mov #0x0, r14
    mov.l   .L_snd_cmd_results, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov r14, r4
    mov.l   .L_fn_sound_init_race, r3
    jsr @r3
    nop
    mov.l   .L_display_slots, r4
    extu.w r14, r0
    mov.w r0, @(6, r4)
    mov.w r0, @(4, r4)
    mov.w r0, @(2, r4)
    mov.w r0, @r4
    mov.w   .L_palette_size, r6
    mov.l   .L_palette_src, r5
    mov.l   .L_vdp2_cram_0x460, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    nop
    mov.l   .L_tile_src, r2
    mov.l r2, @r15
    mov.l   .L_vdp2_vram_0x75DDC, r4
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov r2, r5
    mov.l   .L_layer_mask, r7
    mov r14, r6
    mov.l @r15, r5
    jsr @r13
    mov #0xC, r4
    mov.l   .L_fn_scroll_config, r3
    jsr @r3
    nop
    mov.l   .L_snd_cmd_secondary, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov r14, r4
    mov.l   .L_fn_ui_setup, r3
    jsr @r3
    extu.w r14, r4
    mov.l   .L_fn_anim_transition, r3
    jsr @r3
    extu.w r14, r4
    mov.l   .L_fn_hud_course, r3
    jsr @r3
    nop
    mov.l   .L_status_word, r2
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_0600F724
    mov #0x24, r10
    bra     .L_0600F728
    mov #0x22, r12
.L_palette_size:
    .2byte  0x00C0                        /* palette copy size (192 bytes) */
    .2byte  0xFFFF
.L_fn_layer_setup:
    .4byte  sym_06028400               /* display layer setup function */
.L_fn_audio_init:
    .4byte  audio_display_init         /* audio display initialization */
.L_snd_cmd_results:
    .4byte  0xAE0003FF                  /* sound command: results music */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_fn_sound_init_race:
    .4byte  sound_init_race            /* race sound state initialization */
.L_display_slots:
    .4byte  sym_06078870               /* display slot array (4×16-bit) */
.L_palette_src:
    .4byte  sym_060484EC               /* results palette source data */
.L_vdp2_cram_0x460:
    .4byte  0x25F00460                  /* VDP2 color RAM +0x460 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx            /* word-indexed memory copy */
.L_tile_src:
    .4byte  sym_06094FA8               /* results tile source data */
.L_vdp2_vram_0x75DDC:
    .4byte  0x25E75DDC                  /* VDP2 VRAM +0x75DDC */
.L_fn_dma_transfer:
    .4byte  dma_memory_transfer        /* DMA memory transfer */
.L_layer_mask:
    .4byte  0x0000E000                  /* display layer priority mask */
.L_fn_scroll_config:
    .4byte  sym_0601143E               /* scroll layer configuration */
.L_snd_cmd_secondary:
    .4byte  0xAB1103FF                  /* sound command: secondary trigger */
.L_fn_ui_setup:
    .4byte  sym_06011494               /* UI element setup */
.L_fn_anim_transition:
    .4byte  anim_ui_transition         /* animated UI transition */
.L_fn_hud_course:
    .4byte  hud_course_render          /* course HUD element renderer */
.L_status_word:
    .4byte  g_pad_state               /* game status word (16-bit array) */
.L_0600F724:
    mov #0x29, r10
    mov #0x26, r12
.L_0600F728:
    .byte   0xDB, 0x28    /* mov.l .L_tile_table, r11 */
    mov r10, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x26    /* mov.l .L_tile_offset_a, r3 */
    .byte   0x96, 0x43    /* mov.w .L_tile_size_a, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    mov r12, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x1F    /* mov.l .L_tile_offset_a, r3 */
    .byte   0x96, 0x37    /* mov.w .L_tile_size_b, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    .byte   0x97, 0x32    /* mov.w .L_tile_index_c, r7 */
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x1B    /* mov.l .L_tile_offset_c, r3 */
    .byte   0x96, 0x2E    /* mov.w .L_tile_size_c, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    .byte   0xD3, 0x18    /* mov.l .L_transition_state, r3 */
    mov.l r14, @r3
    .byte   0x92, 0x27    /* mov.w .L_countdown_value, r2 */
    .byte   0xD3, 0x18    /* mov.l .L_countdown_timer, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x17    /* mov.l .L_transition_active, r3 */
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
