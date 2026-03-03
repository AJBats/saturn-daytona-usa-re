	.text
    .global transition_large_menu
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
    .short  0x0080
    .short  0xFFFF
    .long  sym_0607885C
    .long  0x00100000
    .long  display_channel_b
    .long  sym_0607886E
    .long  sprite_batch_renderer
    .long  sym_0607887F
.L_0600FA20:
    .long  0xAE0003FF
.L_0600FA24:
    .long  sound_cmd_dispatch              /* sound command dispatcher */
.L_0600FA28:
    .long  sym_0602853E
.L_0600FA2C:
    .long  sym_0605CA9C
.L_0600FA30:
    .long  0x25F00460
.L_0600FA34:
    .long  memcpy_word_idx
.L_0600FA38:
    .long  sym_0601209E
.L_0600FA3C:
    .long  g_pad_state
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
    .short  0x0B04
.L_0600FB0E:
    .short  0x0B38
.L_0600FB10:
    .short  0x0170
.L_0600FB12:
    .short  0x4000
.L_0600FB14:
    .short  0x0C26
.L_0600FB16:
    .short  0x0090
.L_0600FB18:
    .short  0x07A2
    .short  0xFFFF
.L_0600FB1C:
    .long  sym_06063750
.L_0600FB20:
    .long  sym_06028400
.L_0600FB24:
    .long  0x00009000
.L_0600FB28:
    .long  0xAB1104FF
.L_0600FB2C:
    .long  sound_cmd_dispatch              /* sound command dispatcher */
.L_0600FB30:
    .long  sym_0607887F
.L_0600FB34:
    .long  sym_0607EADC
.L_0600FB38:
    .long  sym_0607EAB8
.L_0600FB3C:
    .long  sym_06078868
.L_0600FB40:
    .long  sym_060788A0
.L_0600FB44:
    .long  sym_060788A4
.L_0600FB48:
    .long  sym_06085FF4
.L_0600FB4C:
    .long  sym_06078894
.L_0600FB50:
    .long  0x000C0000
.L_0600FB54:
    .long  sym_06078898
.L_0600FB58:
    .long  sym_0607889C
.L_0600FB5C:
    .long  sym_060788A8
.L_0600FB60:
    .long  sym_0605ACE4
.L_0600FB64:
    .long  sym_060284AE
.L_0600FB68:
    .long  sym_06011494
.L_0600FB6C:
    .long  anim_ui_transition
.L_0600FB70:
    .long  graphics_mode_setup
.L_0600FB74:
    .long  sym_06011EB4
