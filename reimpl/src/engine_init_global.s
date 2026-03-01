
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
    mov.l   .L_06004ACC, r8
    mov.l   .L_06004AD0, r9
    mov.l   .L_06004AD4, r10
    mov.l   .L_06004AD8, r12
    mov.w   .L_06004AC8, r5
    mov.l @r8, r3
    jsr @r3
    mov #-0x1, r4

    mov.l   .L_06004ADC, r5
    mov.l   .L_06004AE0, r4
    bra     .L_06004AF2
    nop
.L_06004AC8:
    .2byte  0x0083                          /* interrupt config: enable vblank */
    .2byte  0xFFFF
.L_06004ACC:
    .4byte  sym_06000344                    /* → interrupt controller function */
.L_06004AD0:
    .4byte  vdp1_polygon_build              /* VDP1 polygon/pattern builder */
.L_06004AD4:
    .4byte  0x25FE00A4                      /* SCU IST — interrupt status */
.L_06004AD8:
    .4byte  sym_06087C84                    /* pattern table config structure */
.L_06004ADC:
    .4byte  0x25E00000                      /* VDP2 VRAM +0x00000 */
.L_06004AE0:
    .4byte  0x00020000                      /* 2.0 (16.16 fixed-point) / 128K count */
.L_06004AE4:
    mov r5, r2
    add #0x4, r5
    mov.l r14, @r2
    mov r5, r3
    add #0x4, r5
    mov.l r14, @r3
    add #-0x2, r4
.L_06004AF2:
    tst r4, r4
    bf      .L_06004AE4

    mov.l   .L_06004BC4, r3
    jsr @r3
    nop
    mov #0x1, r6
    mov #0x0, r5
    mov.l   .L_06004BC8, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_06004BCC, r3
    jsr @r3
    mov #0x1, r4

    mov.l   .L_06004BD0, r2
    mov.l   .L_06004BD4, r3
    mov.w r2, @r3
    mov r3, r6
    mov.l   .L_06004BD8, r4
    mov.l   .L_06004BDC, r3
    jsr @r3
    mov #0x1, r5

    mov.l r11, @r10
.L_06004B1E:
    mov.l @r10, r2
    and r11, r2
    cmp/eq r11, r2
    bt      .L_06004B2A
    bra     .L_06004CBA
    nop

.L_06004B2A:
    mov.l   .L_06004BE0, r3
    mov.l   .L_06004BE4, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x40, r4
    mov.l   .L_06004BE0, r2
    mov.l   .L_06004BE8, r5
    mov.l @r2, r2
    jsr @r2
    mov #0x41, r4

    extu.b r14, r3
    mov #0x5, r7
    mov #0x10, r6
    mov #0x2, r5
    mov.l r3, @-r15
    mov.l   .L_06004BEC, r2
    mov.l r2, @-r15
    mov.l   .L_06004BF0, r3
    jsr @r3
    mov r5, r4
    add #0x8, r15

    mov.l   .L_06004BF4, r3
    jsr @r3
    mov #0x1, r4
    mov.l   .L_06004BF8, r4
    mov.l   .L_06004BFC, r3
    mov.l r4, @r3
    mov.l   .L_06004C00, r3
    mov.l r4, @r3

    mov.l   .L_06004C04, r3
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
    mov.l   .L_06004C00, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.w   .L_06004BC0, r4
    mov.l   .L_06004C00, r3
    mov.l @r3, r3
    add r4, r3
    mov.l r3, @(16, r15)
    mov.l   .L_06004C00, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_06004C00, r3
    mov.l @r3, r3
    mov r15, r5
    add r3, r4
    mov.l r4, @(24, r15)
    jsr @r9
    mov #0x4, r4
    mov.l   .L_06004C08, r3
    mov.l   .L_06004C0C, r2
    mov.w r2, @r3
    bra     .L_06004C10
    mov #0x4, r4
.L_06004BC0:
    .2byte  0x2000                          /* 8KB VRAM page size */
    .2byte  0xFFFF
.L_06004BC4:
    .4byte  display_hw_init                 /* display hardware init */
.L_06004BC8:
    .4byte  vdp_init_master                 /* VDP master init */
.L_06004BCC:
    .4byte  display_extra_config            /* extra display configuration */
.L_06004BD0:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_06004BD4:
    .4byte  sym_06086028                    /* palette intensity (word) */
.L_06004BD8:
    .4byte  0x25F00FFE                      /* VDP2 color RAM +0xFFE */
.L_06004BDC:
    .4byte  tilemap_dma_update              /* tilemap DMA transfer */
.L_06004BE0:
    .4byte  sym_06000300                    /* → callback registration fn */
.L_06004BE4:
    .4byte  button_input_read               /* button input handler */
.L_06004BE8:
    .4byte  vblank_out_handler              /* VBlank-OUT handler */
.L_06004BEC:
    .4byte  sym_06063DA8                    /* scene state config data */
.L_06004BF0:
    .4byte  scene_state_process             /* scene state processor */
.L_06004BF4:
    .4byte  display_param_set               /* display parameter config */
.L_06004BF8:
    .4byte  0x25E58000                      /* VDP2 VRAM +0x58000 */
.L_06004BFC:
    .4byte  sym_06061294                    /* VRAM dest for channel 4 */
.L_06004C00:
    .4byte  sym_060612AC                    /* VRAM config for channel 4 */
.L_06004C04:
    .4byte  sym_06037618                    /* pattern table init */
.L_06004C08:
    .4byte  sym_060A3DB8                    /* VDP2 control register ch4 */
.L_06004C0C:
    .4byte  0x0000C024                      /* ch4 control value */

.L_06004C10:
    mov.l   .L_06004CC0, r3
    jsr @r3
    nop
    mov.l   .L_06004CC4, r5
    mov.l   .L_06004CC8, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_06004CCC, r3
    jsr @r3
    nop
    mov.l   .L_06004CD0, r4
    mov.l   .L_06004CD4, r3
    mov.l r4, @r3
    mov.l   .L_06004CD8, r3
    mov.l r4, @r3
    mov.l   .L_06004CDC, r3
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
    mov.l   .L_06004CD8, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_06004CD8, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_06004CD8, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_06004CD8, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    mov r15, r5
    jsr @r9
    mov #0x8, r4
    mov.l   .L_06004CE0, r3
    mov.l   .L_06004CE4, r2
    mov.w r2, @r3
    mov.l   .L_06004CC0, r3
    jsr @r3
    mov #0x8, r4

    mov.l   .L_06004CE8, r4
    mov.l   .L_06004CEC, r3
    jsr @r3
    nop
    mov.l   .L_06004CCC, r3
    jsr @r3
    nop
    mov.l   .L_06004CC0, r3
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
    mov.l   .L_06004CF0, r3
    mov.l r3, @(8, r12)
    mov.l   .L_06004CF4, r2
    mov.l r2, @(12, r12)
    bra     .L_06004D0C
    mov #0x0, r4

.L_06004CBA:
    bra     .L_06004B1E
    nop
    .2byte  0xFFFF
.L_06004CC0:
    .4byte  sym_0603850C                    /* display cmd queue: select channel */
.L_06004CC4:
    .4byte  0x00010000                      /* 1.0 (16.16 fixed-point) */
.L_06004CC8:
    .4byte  scene_color_intensity           /* scene color intensity */
.L_06004CCC:
    .4byte  sym_06038520                    /* display cmd queue: commit */
.L_06004CD0:
    .4byte  0x25E5C000                      /* VDP2 VRAM +0x5C000 */
.L_06004CD4:
    .4byte  sym_06061298                    /* VRAM dest for channel 8 */
.L_06004CD8:
    .4byte  sym_060612B0                    /* VRAM config for channel 8 */
.L_06004CDC:
    .4byte  sym_06037618                    /* pattern table init (ch8) */
.L_06004CE0:
    .4byte  sym_060A3DBA                    /* VDP2 control register ch8 */
.L_06004CE4:
    .4byte  0x0000C044                      /* ch8 control value */
.L_06004CE8:
    .4byte  sym_06087C84                    /* pattern config base (for enable) */
.L_06004CEC:
    .4byte  display_enable_ctrl             /* display enable control */
.L_06004CF0:
    .4byte  0x25E5FE80                      /* VDP2 VRAM +0x5FE80 */
.L_06004CF4:
    .4byte  0x25E5FF00                      /* VDP2 VRAM +0x5FF00 */

.L_06004CF8:
    mov.w   .L_06004DDA, r2
    add r12, r2
    add r4, r2
    mov.l r14, @r2
    add #0x4, r4
    mov.w   .L_06004DDA, r3
    add r12, r3
    add r4, r3
    mov.l r14, @r3
    add #0x4, r4
.L_06004D0C:
    mov.w   .L_06004DDC, r2
    cmp/hs r2, r4
    bf      .L_06004CF8

    mov.l   .L_06004DE0, r4
    mov.l   .L_06004DE4, r3
    jsr @r3
    nop
    mov.l   .L_06004DE8, r5
    mov.l   .L_06004DEC, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_06004DF0, r3
    jsr @r3
    nop
    mov.l   .L_06004DF4, r2
    mov.l   .L_06004DF8, r3
    mov.l r2, @r3
    mov.l   .L_06004DFC, r2
    mov.l   .L_06004E00, r3
    mov.l r2, @r3
    mov.l   .L_06004E04, r3
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
    mov.l   .L_06004E00, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_06004E00, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_06004E00, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_06004E00, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    mov r15, r5
    jsr @r9
    mov #0x10, r4
    mov.l   .L_06004E08, r3
    mov.l   .L_06004E0C, r2
    mov.w r2, @r3

    mov.l   .L_06004E10, r4
    mov.l   .L_06004E14, r3
    mov.l r4, @r3
    mov.l   .L_06004E18, r3
    mov.l r4, @r3
    mov.l   .L_06004E04, r3
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
    mov.l   .L_06004E18, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l   .L_06004E18, r3
    mov.l @r3, r3
    mov.l r3, @(16, r15)
    mov.l   .L_06004E18, r3
    mov.l @r3, r3
    mov.l r3, @(20, r15)
    mov.l   .L_06004E18, r3
    mov.l @r3, r3
    mov.l r3, @(24, r15)
    bra     .L_06004E1C
    nop
.L_06004DDA:
    .2byte  0x1810                          /* offset into pattern config buffer */
.L_06004DDC:
    .2byte  0x0100                          /* 256 bytes to clear */
    .2byte  0xFFFF
.L_06004DE0:
    .4byte  sym_06087C84                    /* pattern config base (for scene init) */
.L_06004DE4:
    .4byte  scene_buffer_init               /* scene buffer initialization */
.L_06004DE8:
    .4byte  0x00010000                      /* 1.0 (16.16 fixed-point) */
.L_06004DEC:
    .4byte  scene_color_intensity           /* scene color intensity (ch16) */
.L_06004DF0:
    .4byte  sym_06038520                    /* cmd queue commit (ch16) */
.L_06004DF4:
    .4byte  sym_060612C4                    /* VRAM config link source */
.L_06004DF8:
    .4byte  sym_0606129C                    /* VRAM config link destination */
.L_06004DFC:
    .4byte  0x25E5E000                      /* VDP2 VRAM +0x5E000 */
.L_06004E00:
    .4byte  sym_060612B4                    /* VRAM config for channel 16 */
.L_06004E04:
    .4byte  sym_06037618                    /* pattern table init (ch16/32) */
.L_06004E08:
    .4byte  sym_060A3DBC                    /* VDP2 control register ch16 */
.L_06004E0C:
    .4byte  0x0000C000                      /* ch16 control value */
.L_06004E10:
    .4byte  0x25E7E000                      /* VDP2 VRAM +0x7E000 */
.L_06004E14:
    .4byte  sym_060612A0                    /* VRAM dest for channel 32 */
.L_06004E18:
    .4byte  sym_060612B8                    /* VRAM config for channel 32 */

.L_06004E1C:
    mov r15, r5
    jsr @r9
    mov #0x20, r4
    mov r15, r4
    mov.l   .L_06004ED4, r3
    mov.l   .L_06004ED8, r2
    mov.w r2, @r3

    mov.l   .L_06004EDC, r3
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
    mov.l   .L_06004EE0, r3
    jsr @r3
    add #0x4C, r4

    mov.l   .L_06004EE4, r4
    mov.l   .L_06004EE8, r3
    jsr @r3
    nop
    mov.l   .L_06004EEC, r3
    jsr @r3
    nop
    mov.l   .L_06004EF0, r3
    jsr @r3
    nop

    mov.l @r8, r2
    mov.w   .L_06004ED0, r4
    jsr @r2
    mov #0x0, r5
    mov.l   .L_06004EF4, r3
    jsr @r3
    nop

    mov.l @r8, r2
    mov.w   .L_06004ED2, r5
    jsr @r2
    mov #-0x1, r4

    mov.l   .L_06004EF8, r3
    jsr @r3
    nop
    mov.l   .L_06004EFC, r3
    jsr @r3
    nop
    mov.l   .L_06004F00, r3
    jsr @r3
    nop
    mov.l   .L_06004F04, r3
    jsr @r3
    nop
    mov.l   .L_06004F08, r3
    jsr @r3
    nop

    mov #0xF, r2
    mov.l   .L_06004F0C, r3
    mov.w r2, @r3
    mov.l   .L_06004F10, r3
    mov.w r13, @r3

    mov.l @r8, r1
    mov.w   .L_06004ED0, r4
    jsr @r1
    mov #0x0, r5
    mov.l   .L_06004EF4, r3
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
.L_06004ED0:
    .2byte  0xFF7C                          /* mask: disable most interrupts */
.L_06004ED2:
    .2byte  0x0083                          /* restore: enable standard interrupts */
.L_06004ED4:
    .4byte  sym_060A3DBE                    /* VDP2 control register ch32 */
.L_06004ED8:
    .4byte  0x0000C060                      /* ch32 control value */
.L_06004EDC:
    .4byte  sym_060370C0                    /* VDP init dispatcher */
.L_06004EE0:
    .4byte  texture_bank_setup              /* texture bank configuration */
.L_06004EE4:
    .4byte  sym_06059F20                    /* VDP1 init parameter block */
.L_06004EE8:
    .4byte  sym_06038044                    /* VDP1 polygon list commit */
.L_06004EEC:
    .4byte  display_channels_clear          /* clear display channels */
.L_06004EF0:
    .4byte  sym_060149E0                    /* display hardware init (final) */
.L_06004EF4:
    .4byte  sym_06026CE0                    /* render/display update */
.L_06004EF8:
    .4byte  sym_06012E62                    /* sound subsystem init */
.L_06004EFC:
    .4byte  vdp2_register_init              /* VDP2 register initialization */
.L_06004F00:
    .4byte  master_init_dispatch            /* master init dispatch */
.L_06004F04:
    .4byte  obj_template_init               /* object template init */
.L_06004F08:
    .4byte  audio_display_init              /* audio display init */
.L_06004F0C:
    .4byte  sym_060A3DA8                    /* display state flags (0xF = ready) */
.L_06004F10:
    .4byte  sym_060635AC                    /* cmd queue ready flag */
