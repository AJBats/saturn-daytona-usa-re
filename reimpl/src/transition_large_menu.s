
    .section .text.FUN_0600F9C6


    .global transition_large_menu
    .type transition_large_menu, @function
transition_large_menu:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD5, 0x13    /* mov.l .L_0600FA20, r5 */
    .byte   0xD3, 0x13    /* mov.l .L_0600FA24, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x13    /* mov.l .L_0600FA28, r3 */
    jsr @r3
    mov #0xC, r4
    mov.w   .L_0600FA04, r6
    .byte   0xD5, 0x12    /* mov.l .L_0600FA2C, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_0600FA30, r4 */
    .byte   0xD3, 0x13    /* mov.l .L_0600FA34, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x12    /* mov.l .L_0600FA38, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x12    /* mov.l .L_0600FA3C, r2 */
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_0600FA40
    mov #0x25, r14
    bra     .L_0600FA44
    mov #0x23, r13
.L_0600FA04:
    .2byte  0x0080                          /* palette copy size (128 bytes) */
    .2byte  0xFFFF                          /* alignment padding */
    .4byte  sym_0607885C                    /* (cross-TU pool) display slot ptr */
    .4byte  0x00100000                      /* (cross-TU pool) scroll param */
    .4byte  display_channel_b               /* (cross-TU pool) */
    .4byte  sym_0607886E                    /* (cross-TU pool) display slot */
    .4byte  sprite_batch_renderer           /* (cross-TU pool) */
    .4byte  sym_0607887F                    /* (cross-TU pool) game mode byte */
.L_0600FA20:
    .4byte  0xAE0003FF                      /* sound command: menu music */
.L_0600FA24:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher */
.L_0600FA28:
    .4byte  sym_0602853E                    /* display channel configure */
.L_0600FA2C:
    .4byte  sym_0605CA9C                    /* menu palette source data */
.L_0600FA30:
    .4byte  0x25F00460                      /* VDP2 color RAM +0x460 */
.L_0600FA34:
    .4byte  memcpy_word_idx                 /* word-indexed memory copy */
.L_0600FA38:
    .4byte  sym_0601209E                    /* scroll/display setup helper */
.L_0600FA3C:
    .4byte  g_pad_state                    /* game status word (16-bit array) */
.L_0600FA40:
    mov #0x28, r14
    mov #0x27, r13
.L_0600FA44:
    .byte   0xDB, 0x35    /* mov.l .L_0600FB1C, r11 */
    mov r14, r7
    .byte   0xDC, 0x35    /* mov.l .L_0600FB20, r12 */
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x33    /* mov.l .L_0600FB24, r3 */
    mov.w   .L_0600FB0C, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r13, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x2D    /* mov.l .L_0600FB24, r3 */
    mov.w   .L_0600FB0E, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.w   .L_0600FB10, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0600FB12, r3
    mov.w   .L_0600FB14, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    .byte   0xD5, 0x25    /* mov.l .L_0600FB28, r5 */
    .byte   0xD3, 0x25    /* mov.l .L_0600FB2C, r3 */
    jsr @r3
    mov #0x0, r4
    mov #0x9, r2
    .byte   0xD3, 0x24    /* mov.l .L_0600FB30, r3 */
    mov #0x0, r4
    mov.b r2, @r3
    mov r4, r2
    .byte   0xD3, 0x23    /* mov.l .L_0600FB34, r3 */
    mov.l r4, @r3
    .byte   0xD3, 0x23    /* mov.l .L_0600FB38, r3 */
    mov.l r4, @r3
    .byte   0xD3, 0x23    /* mov.l .L_0600FB3C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x23    /* mov.l .L_0600FB40, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x23    /* mov.l .L_0600FB44, r3 */
    mov.l r2, @r3
    .byte   0xD0, 0x23    /* mov.l .L_0600FB48, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600FAE2
    .byte   0xD3, 0x22    /* mov.l .L_0600FB4C, r3 */
    mov.l r4, @r3
    .byte   0xD2, 0x22    /* mov.l .L_0600FB50, r2 */
    .byte   0xD3, 0x22    /* mov.l .L_0600FB54, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x22    /* mov.l .L_0600FB58, r3 */
    mov.l r4, @r3
    extu.b r4, r4
    .byte   0xD3, 0x22    /* mov.l .L_0600FB5C, r3 */
    mov.b r4, @r3
    .byte   0xD7, 0x22    /* mov.l .L_0600FB60, r7 */
    mov.w   .L_0600FB16, r6
    mov.w   .L_0600FB18, r5
    .byte   0xD3, 0x21    /* mov.l .L_0600FB64, r3 */
    jsr @r3
    mov #0xC, r4
.L_0600FAE2:
    .byte   0xD0, 0x19    /* mov.l .L_0600FB48, r0 */
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FAF6
    .byte   0xD3, 0x1F    /* mov.l .L_0600FB68, r3 */
    jsr @r3
    mov #0x1, r4
    .byte   0xD3, 0x1E    /* mov.l .L_0600FB6C, r3 */
    jsr @r3
    mov #0x1, r4
.L_0600FAF6:
    .byte   0xD3, 0x1E    /* mov.l .L_0600FB70, r3 */
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x1B    /* mov.l .L_0600FB74, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_0600FB0C:
    .2byte  0x0B04                          /* layer A tile size */
.L_0600FB0E:
    .2byte  0x0B38                          /* layer B tile size */
.L_0600FB10:
    .2byte  0x0170                          /* layer C table offset (0x170 = entry 0x2E) */
.L_0600FB12:
    .2byte  0x4000                          /* layer C data offset */
.L_0600FB14:
    .2byte  0x0C26                          /* layer C tile size */
.L_0600FB16:
    .2byte  0x0090                          /* split-screen tile size */
.L_0600FB18:
    .2byte  0x07A2                          /* split-screen tile data offset */
    .2byte  0xFFFF                          /* alignment padding */
.L_0600FB1C:
    .4byte  sym_06063750                    /* tile table base array */
.L_0600FB20:
    .4byte  sym_06028400                    /* display layer tile writer */
.L_0600FB24:
    .4byte  0x00009000                      /* tile data offset (+0x9000) */
.L_0600FB28:
    .4byte  0xAB1104FF                      /* sound command: secondary trigger */
.L_0600FB2C:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher */
.L_0600FB30:
    .4byte  sym_0607887F                    /* game mode byte (9 = menu) */
.L_0600FB34:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_0600FB38:
    .4byte  sym_0607EAB8                    /* game variant flag */
.L_0600FB3C:
    .4byte  sym_06078868                    /* display slot A */
.L_0600FB40:
    .4byte  sym_060788A0                    /* display slot B */
.L_0600FB44:
    .4byte  sym_060788A4                    /* transition active flag */
.L_0600FB48:
    .4byte  sym_06085FF4                    /* 2-player mode flag (byte) */
.L_0600FB4C:
    .4byte  sym_06078894                    /* split-screen transition state */
.L_0600FB50:
    .4byte  0x000C0000                      /* split-screen scroll Y offset */
.L_0600FB54:
    .4byte  sym_06078898                    /* split-screen scroll position ptr */
.L_0600FB58:
    .4byte  sym_0607889C                    /* split-screen display slot */
.L_0600FB5C:
    .4byte  sym_060788A8                    /* split-screen active byte */
.L_0600FB60:
    .4byte  sym_0605ACE4                    /* split-screen tile data source */
.L_0600FB64:
    .4byte  sym_060284AE                    /* split-screen tile writer */
.L_0600FB68:
    .4byte  sym_06011494                    /* UI element setup */
.L_0600FB6C:
    .4byte  anim_ui_transition              /* animated UI transition */
.L_0600FB70:
    .4byte  graphics_mode_setup             /* graphics mode configuration */
.L_0600FB74:
    .4byte  sym_06011EB4                    /* dual HUD render dispatcher */
