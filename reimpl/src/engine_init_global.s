
    .section .text.FUN_06004A98


    .global engine_init_global
    .type engine_init_global, @function
engine_init_global:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    mov #0x1, r13
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x2, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x5C, r15
    mov.l   .L_interrupt_ctrl_ptr, r8
    mov.l   .L_fn_vdp1_poly_build, r9
    mov.l   .L_scu_ist, r10
    mov.l   .L_pattern_config_base, r12
    mov.w   .L_irq_mask_init, r5
    mov.l @r8, r3
    jsr @r3
    mov #-0x1, r4

    mov.l   .L_vdp2_vram_0x00000, r5
    mov.l   .L_fp_two, r4
    bra     .L_vram_clear_test
    nop
.L_irq_mask_init:
    .2byte  0x0083                          /* interrupt config: enable vblank */
    .2byte  0xFFFF
.L_interrupt_ctrl_ptr:
    .4byte  sym_06000344                    /* → interrupt controller function */
.L_fn_vdp1_poly_build:
    .4byte  vdp1_polygon_build              /* VDP1 polygon/pattern builder */
.L_scu_ist:
    .4byte  0x25FE00A4                      /* SCU IST — interrupt status */
.L_pattern_config_base:
    .4byte  sym_06087C84                    /* pattern table config structure */
.L_vdp2_vram_0x00000:
    .4byte  0x25E00000                      /* VDP2 VRAM +0x00000 */
.L_fp_two:
    .4byte  0x00020000                      /* 2.0 (16.16 fixed-point) / 128K count */
.L_vram_clear_body:
    mov r5, r2
    add #0x4, r5
    mov.l r14, @r2
    mov r5, r3
    add #0x4, r5
    mov.l r14, @r3
    add #-0x2, r4
.L_vram_clear_test:
    tst r4, r4
    bf      .L_vram_clear_body

    mov.l   .L_fn_display_hw_init, r3
    jsr @r3
    nop
    mov #0x1, r6
    mov #0x0, r5
    mov.l   .L_fn_vdp_init_master, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_fn_display_extra, r3
    jsr @r3
    mov #0x1, r4

    mov.l   .L_fp_half, r2
    mov.l   .L_palette_intensity, r3
    mov.w r2, @r3
    mov r3, r6
    mov.l   .L_vdp2_cram_0xFFE, r4
    mov.l   .L_fn_tilemap_dma, r3
    jsr @r3
    mov #0x1, r5

    mov.l r11, @r10
.L_vblank_wait_check:
    mov.l @r10, r2
    and r11, r2
    cmp/eq r11, r2
    bt      .L_vblank_done
    bra     .L_vblank_wait_retry
    nop

.L_vblank_done:
    mov.l   .L_vector_table_ptr, r3
    mov.l   .L_fn_button_input, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x40, r4
    mov.l   .L_vector_table_ptr, r2
    mov.l   .L_fn_vblank_out, r5
    mov.l @r2, r2
    jsr @r2
    mov #0x41, r4

    extu.b r14, r3
    mov #0x5, r7
    mov #0x10, r6
    mov #0x2, r5
    mov.l r3, @-r15
    mov.l   .L_scene_state_param, r2
    mov.l r2, @-r15
    mov.l   .L_fn_scene_state, r3
    jsr @r3
    mov r5, r4
    add #0x8, r15

    mov.l   .L_fn_display_param, r3
    jsr @r3
    mov #0x1, r4
    mov.l   .L_vdp2_vram_0x58000, r4
    mov.l   .L_vram_dest_ch4, r3
    mov.l r4, @r3
    mov.l   .L_vram_cfg_ch4, r3
    mov.l r4, @r3

    mov.l   .L_fn_pattern_tbl_init, r3
    jsr @r3
    mov r15, r4
    extu.b r13, r2
    mov.b r2, @r15
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(2, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(3, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(5, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(6, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.l   .L_vram_cfg_ch4, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.w   .L_vram_page_size, r4
    mov.l   .L_vram_cfg_ch4, r3
    mov.l @r3, r3
    add r4, r3
    mov.l r3, @(16, r15)
    mov.l   .L_vram_cfg_ch4, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_vram_cfg_ch4, r3
    mov.l @r3, r3
    mov r15, r5
    add r3, r4
    mov.l r4, @(24, r15)
    jsr @r9
    mov #0x4, r4
    mov.l   .L_vdp2_ctrl_ch4, r3
    mov.l   .L_vdp2_ctrl_val_ch4, r2
    mov.w r2, @r3
    bra     .L_ch8_setup
    mov #0x4, r4
.L_vram_page_size:
    .2byte  0x2000                          /* 8KB VRAM page size */
    .2byte  0xFFFF
.L_fn_display_hw_init:
    .4byte  display_hw_init                 /* display hardware init */
.L_fn_vdp_init_master:
    .4byte  vdp_init_master                 /* VDP master init */
.L_fn_display_extra:
    .4byte  display_extra_config            /* extra display configuration */
.L_fp_half:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_palette_intensity:
    .4byte  sym_06086028                    /* palette intensity (word) */
.L_vdp2_cram_0xFFE:
    .4byte  0x25F00FFE                      /* VDP2 color RAM +0xFFE */
.L_fn_tilemap_dma:
    .4byte  tilemap_dma_update              /* tilemap DMA transfer */
.L_vector_table_ptr:
    .4byte  sym_06000300                    /* → callback registration fn */
.L_fn_button_input:
    .4byte  button_input_read               /* button input handler */
.L_fn_vblank_out:
    .4byte  vblank_out_handler              /* VBlank-OUT handler */
.L_scene_state_param:
    .4byte  sym_06063DA8                    /* scene state config data */
.L_fn_scene_state:
    .4byte  scene_state_process             /* scene state processor */
.L_fn_display_param:
    .4byte  display_param_set               /* display parameter config */
.L_vdp2_vram_0x58000:
    .4byte  0x25E58000                      /* VDP2 VRAM +0x58000 */
.L_vram_dest_ch4:
    .4byte  sym_06061294                    /* VRAM dest for channel 4 */
.L_vram_cfg_ch4:
    .4byte  sym_060612AC                    /* VRAM config for channel 4 */
.L_fn_pattern_tbl_init:
    .4byte  sym_06037618                    /* pattern table init */
.L_vdp2_ctrl_ch4:
    .4byte  sym_060A3DB8                    /* VDP2 control register ch4 */
.L_vdp2_ctrl_val_ch4:
    .4byte  0x0000C024                      /* ch4 control value */

.L_ch8_setup:
    mov.l   .L_fn_cmd_queue_write, r3
    jsr @r3
    nop
    mov.l   .L_fp_one, r5
    mov.l   .L_fn_color_intensity, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_fn_cmd_queue_commit, r3
    jsr @r3
    nop
    mov.l   .L_vdp2_vram_0x5C000, r4
    mov.l   .L_vram_dest_ch8, r3
    mov.l r4, @r3
    mov.l   .L_vram_cfg_ch8, r3
    mov.l r4, @r3
    mov.l   .L_fn_pattern_tbl_init_ch8, r3
    jsr @r3
    mov r15, r4
    extu.b r13, r2
    mov.b r2, @r15
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(2, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(3, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(5, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(6, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.l   .L_vram_cfg_ch8, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_vram_cfg_ch8, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_vram_cfg_ch8, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_vram_cfg_ch8, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    mov r15, r5
    jsr @r9
    mov #0x8, r4
    mov.l   .L_vdp2_ctrl_ch8, r3
    mov.l   .L_vdp2_ctrl_val_ch8, r2
    mov.w r2, @r3
    mov.l   .L_fn_cmd_queue_write, r3
    jsr @r3
    mov #0x8, r4

    mov.l   .L_display_enable_arg, r4
    mov.l   .L_fn_display_enable, r3
    jsr @r3
    nop
    mov.l   .L_fn_cmd_queue_commit, r3
    jsr @r3
    nop
    mov.l   .L_fn_cmd_queue_write, r3
    jsr @r3
    mov #0x8, r4

    extu.b r14, r2
    mov.b r2, @r12
    extu.b r14, r0
    mov.b r0, @(1, r12)
    extu.b r14, r0
    mov.b r0, @(2, r12)
    extu.b r13, r0
    mov.b r0, @(3, r12)
    extu.b r14, r0
    mov.b r0, @(4, r12)
    mov.l   .L_vdp2_vram_0x5FE80, r3
    mov.l r3, @(8, r12)
    mov.l   .L_vdp2_vram_0x5FF00, r2
    mov.l r2, @(12, r12)
    bra     .L_pattern_clear_test
    mov #0x0, r4

.L_vblank_wait_retry:
    bra     .L_vblank_wait_check
    nop
    .2byte  0xFFFF
.L_fn_cmd_queue_write:
    .4byte  sym_0603850C                    /* display cmd queue: select channel */
.L_fp_one:
    .4byte  0x00010000                      /* 1.0 (16.16 fixed-point) */
.L_fn_color_intensity:
    .4byte  scene_color_intensity           /* scene color intensity */
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520                    /* display cmd queue: commit */
.L_vdp2_vram_0x5C000:
    .4byte  0x25E5C000                      /* VDP2 VRAM +0x5C000 */
.L_vram_dest_ch8:
    .4byte  sym_06061298                    /* VRAM dest for channel 8 */
.L_vram_cfg_ch8:
    .4byte  sym_060612B0                    /* VRAM config for channel 8 */
.L_fn_pattern_tbl_init_ch8:
    .4byte  sym_06037618                    /* pattern table init (ch8) */
.L_vdp2_ctrl_ch8:
    .4byte  sym_060A3DBA                    /* VDP2 control register ch8 */
.L_vdp2_ctrl_val_ch8:
    .4byte  0x0000C044                      /* ch8 control value */
.L_display_enable_arg:
    .4byte  sym_06087C84                    /* pattern config base (for enable) */
.L_fn_display_enable:
    .4byte  display_enable_ctrl             /* display enable control */
.L_vdp2_vram_0x5FE80:
    .4byte  0x25E5FE80                      /* VDP2 VRAM +0x5FE80 */
.L_vdp2_vram_0x5FF00:
    .4byte  0x25E5FF00                      /* VDP2 VRAM +0x5FF00 */

.L_pattern_clear_body:
    mov.w   .L_pattern_buf_offset, r2
    add r12, r2
    add r4, r2
    mov.l r14, @r2
    add #0x4, r4
    mov.w   .L_pattern_buf_offset, r3
    add r12, r3
    add r4, r3
    mov.l r14, @r3
    add #0x4, r4
.L_pattern_clear_test:
    mov.w   .L_pattern_buf_size, r2
    cmp/hs r2, r4
    bf      .L_pattern_clear_body

    mov.l   .L_scene_buf_init_arg, r4
    mov.l   .L_fn_scene_buf_init, r3
    jsr @r3
    nop
    mov.l   .L_fp_one_ch16, r5
    mov.l   .L_fn_color_intensity_ch16, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_fn_cmd_commit_ch16, r3
    jsr @r3
    nop
    mov.l   .L_vram_link_src, r2
    mov.l   .L_vram_link_dst, r3
    mov.l r2, @r3
    mov.l   .L_vdp2_vram_0x5E000, r2
    mov.l   .L_vram_cfg_ch16, r3
    mov.l r2, @r3
    mov.l   .L_fn_pattern_tbl_init_ch16, r3
    jsr @r3
    mov r15, r4
    extu.b r13, r2
    mov.b r2, @r15
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(2, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(3, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(5, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(6, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.l   .L_vram_cfg_ch16, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_vram_cfg_ch16, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_vram_cfg_ch16, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_vram_cfg_ch16, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    mov r15, r5
    jsr @r9
    mov #0x10, r4
    mov.l   .L_vdp2_ctrl_ch16, r3
    mov.l   .L_vdp2_ctrl_val_ch16, r2
    mov.w r2, @r3

    mov.l   .L_vdp2_vram_0x7E000, r4
    mov.l   .L_vram_dest_ch32, r3
    mov.l r4, @r3
    mov.l   .L_vram_cfg_ch32, r3
    mov.l r4, @r3
    mov.l   .L_fn_pattern_tbl_init_ch16, r3
    jsr @r3
    mov r15, r4
    extu.b r13, r2
    mov.b r2, @r15
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(2, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(3, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(5, r15)
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(6, r15)
    extu.b r13, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.l   .L_vram_cfg_ch32, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_vram_cfg_ch32, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_vram_cfg_ch32, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_vram_cfg_ch32, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    bra     .L_ch32_poly_build
    nop
.L_pattern_buf_offset:
    .2byte  0x1810                          /* offset into pattern config buffer */
.L_pattern_buf_size:
    .2byte  0x0100                          /* 256 bytes to clear */
    .2byte  0xFFFF
.L_scene_buf_init_arg:
    .4byte  sym_06087C84                    /* pattern config base (for scene init) */
.L_fn_scene_buf_init:
    .4byte  scene_buffer_init               /* scene buffer initialization */
.L_fp_one_ch16:
    .4byte  0x00010000                      /* 1.0 (16.16 fixed-point) */
.L_fn_color_intensity_ch16:
    .4byte  scene_color_intensity           /* scene color intensity (ch16) */
.L_fn_cmd_commit_ch16:
    .4byte  sym_06038520                    /* cmd queue commit (ch16) */
.L_vram_link_src:
    .4byte  sym_060612C4                    /* VRAM config link source */
.L_vram_link_dst:
    .4byte  sym_0606129C                    /* VRAM config link destination */
.L_vdp2_vram_0x5E000:
    .4byte  0x25E5E000                      /* VDP2 VRAM +0x5E000 */
.L_vram_cfg_ch16:
    .4byte  sym_060612B4                    /* VRAM config for channel 16 */
.L_fn_pattern_tbl_init_ch16:
    .4byte  sym_06037618                    /* pattern table init (ch16/32) */
.L_vdp2_ctrl_ch16:
    .4byte  sym_060A3DBC                    /* VDP2 control register ch16 */
.L_vdp2_ctrl_val_ch16:
    .4byte  0x0000C000                      /* ch16 control value */
.L_vdp2_vram_0x7E000:
    .4byte  0x25E7E000                      /* VDP2 VRAM +0x7E000 */
.L_vram_dest_ch32:
    .4byte  sym_060612A0                    /* VRAM dest for channel 32 */
.L_vram_cfg_ch32:
    .4byte  sym_060612B8                    /* VRAM config for channel 32 */

.L_ch32_poly_build:
    mov r15, r5
    jsr @r9
    mov #0x20, r4
    mov r15, r4
    mov.l   .L_vdp2_ctrl_ch32, r3
    mov.l   .L_vdp2_ctrl_val_ch32, r2
    mov.w r2, @r3

    mov.l   .L_fn_vdp_init_dispatch, r3
    jsr @r3
    add #0x4C, r4
    extu.b r13, r2
    mov #0x54, r0
    extu.b r13, r3
    mov r15, r4
    mov.b r2, @(r0, r15)
    mov #0x55, r0
    mov.b r3, @(r0, r15)
    extu.b r14, r3
    mov #0x56, r0
    mov.b r3, @(r0, r15)
    extu.b r14, r3
    mov #0x57, r0
    mov.b r3, @(r0, r15)
    extu.b r14, r3
    mov #0x58, r0
    mov.b r3, @(r0, r15)
    extu.b r14, r3
    mov #0x59, r0
    mov.b r3, @(r0, r15)
    mov.l   .L_fn_texture_bank_setup, r3
    jsr @r3
    add #0x4C, r4

    mov.l   .L_vdp1_init_param, r4
    mov.l   .L_fn_vdp1_poly_commit, r3
    jsr @r3
    nop
    mov.l   .L_fn_channels_clear, r3
    jsr @r3
    nop
    mov.l   .L_fn_display_init, r3
    jsr @r3
    nop

    mov.l @r8, r2
    mov.w   .L_irq_mask_subsys, r4
    jsr @r2
    mov #0x0, r5
    mov.l   .L_fn_render_update, r3
    jsr @r3
    nop

    mov.l @r8, r2
    mov.w   .L_irq_mask_restore, r5
    jsr @r2
    mov #-0x1, r4

    mov.l   .L_fn_sound_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_vdp2_reg_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_master_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_obj_template, r3
    jsr @r3
    nop
    mov.l   .L_fn_audio_init, r3
    jsr @r3
    nop

    mov #0xF, r2
    mov.l   .L_display_state_flags, r3
    mov.w r2, @r3
    mov.l   .L_cmd_queue_ready, r3
    mov.w r13, @r3

    mov.l @r8, r1
    mov.w   .L_irq_mask_subsys, r4
    jsr @r1
    mov #0x0, r5
    mov.l   .L_fn_render_update, r3
    jsr @r3
    nop

    add #0x5C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_irq_mask_subsys:
    .2byte  0xFF7C                          /* mask: disable most interrupts */
.L_irq_mask_restore:
    .2byte  0x0083                          /* restore: enable standard interrupts */
.L_vdp2_ctrl_ch32:
    .4byte  sym_060A3DBE                    /* VDP2 control register ch32 */
.L_vdp2_ctrl_val_ch32:
    .4byte  0x0000C060                      /* ch32 control value */
.L_fn_vdp_init_dispatch:
    .4byte  sym_060370C0                    /* VDP init dispatcher */
.L_fn_texture_bank_setup:
    .4byte  texture_bank_setup              /* texture bank configuration */
.L_vdp1_init_param:
    .4byte  sym_06059F20                    /* VDP1 init parameter block */
.L_fn_vdp1_poly_commit:
    .4byte  sym_06038044                    /* VDP1 polygon list commit */
.L_fn_channels_clear:
    .4byte  display_channels_clear          /* clear display channels */
.L_fn_display_init:
    .4byte  sym_060149E0                    /* display hardware init (final) */
.L_fn_render_update:
    .4byte  sym_06026CE0                    /* render/display update */
.L_fn_sound_init:
    .4byte  sym_06012E62                    /* sound subsystem init */
.L_fn_vdp2_reg_init:
    .4byte  vdp2_register_init              /* VDP2 register initialization */
.L_fn_master_init:
    .4byte  master_init_dispatch            /* master init dispatch */
.L_fn_obj_template:
    .4byte  obj_template_init               /* object template init */
.L_fn_audio_init:
    .4byte  audio_display_init              /* audio display init */
.L_display_state_flags:
    .4byte  sym_060A3DA8                    /* display state flags (0xF = ready) */
.L_cmd_queue_ready:
    .4byte  sym_060635AC                    /* cmd queue ready flag */
