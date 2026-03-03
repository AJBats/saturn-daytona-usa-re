	.text
    .global render_stage_1
render_stage_1:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x0, r13
    add #-0x4, r15
    mov.l   .L_0601CA44, r14
    mov.l   .L_0601CA48, r3
    mov.l r13, @r3
    mov.l   .L_0601CA4C, r3
    mov.b r13, @r3
    mov.w   DAT_0601ca3a, r1
    mov.l   .L_0601CA50, r3
    jsr @r3
    mov.w r1, @r14
    mov.l   .L_0601CA54, r3
    jsr @r3
    nop
    mov.l   .L_0601CA58, r3
    jsr @r3
    nop
    mov.l   .L_0601CA5C, r3
    mov.l r13, @r3
    mov.l   .L_0601CA60, r3
    jsr @r3
    nop
    mov.w   DAT_0601ca3c, r2
    mov.l   .L_0601CA64, r3
    mov.l r2, @r3
    mov.l   .L_0601CA68, r3
    mov.l r13, @r3
    mov.l   .L_0601CA6C, r3
    mov.l r13, @r3
    mov.l   .L_0601CA70, r5
    mov #0x20, r4
.L_0601C9BC:
    mov.w @r14, r3
    add #-0x2, r4
    mov.w r3, @r5
    add #0x2, r5
    mov.w @r14, r3
    mov r5, r2
    add #0x2, r5
    tst r4, r4
    bf.s    .L_0601C9BC
    mov.w r3, @r2
    mov.l   .L_0601CA74, r5
    mov #0x20, r4
.L_0601C9D4:
    mov.w @r14, r2
    add #-0x2, r4
    mov.w r2, @r5
    add #0x2, r5
    mov.w @r14, r2
    mov r5, r3
    add #0x2, r5
    tst r4, r4
    bf.s    .L_0601C9D4
    mov.w r2, @r3
    mov.l   .L_0601CA78, r5
    mov.l   .L_0601CA7C, r4
    mov.l   .L_0601CA80, r3
    jsr @r3
    mov #0x40, r6
    mov #0x9, r7
    mov.l   .L_0601CA84, r5
    mov.l   .L_0601CA88, r4
    mov.l   .L_0601CA8C, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_0601CA90, r5
    mov.l   .L_0601CA94, r4
    mov.l   .L_0601CA8C, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_0601CA98, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601CA3E, r6
    mov.l   .L_0601CA9C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    mov.l   .L_0601CAA0, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601CA3E, r6
    mov.l   .L_0601CA9C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x0, r4
    mov.l   .L_0601CAA4, r13
    mov.w   .L_0601CA40, r4
    bra     .L_0601CAA8
    mov #0x0, r5

    .global DAT_0601ca3a
DAT_0601ca3a:
    .short  0x77BD

    .global DAT_0601ca3c
DAT_0601ca3c:
    .short  0x012C
.L_0601CA3E:
    .short  0x0518
.L_0601CA40:
    .short  0x0100
    .short  0xFFFF
.L_0601CA44:
    .long  sym_06086028
.L_0601CA48:
    .long  sym_0608602C
.L_0601CA4C:
    .long  sym_06086030
.L_0601CA50:
    .long  sym_060149E0
.L_0601CA54:
    .long  display_channels_clear
.L_0601CA58:
    .long  sym_06026CE0
.L_0601CA5C:
    .long  sym_06059F44
.L_0601CA60:
    .long  audio_display_init
.L_0601CA64:
    .long  sym_0608601C
.L_0601CA68:
    .long  sym_06086020
.L_0601CA6C:
    .long  sym_06086024
.L_0601CA70:
    .long  0x25F00200
.L_0601CA74:
    .long  0x25F00400
.L_0601CA78:
    .long  sym_0604880C
.L_0601CA7C:
    .long  0x25F00000
.L_0601CA80:
    .long  dma_transfer
.L_0601CA84:
    .long  0x00014000
.L_0601CA88:
    .long  0x25E70E40
.L_0601CA8C:
    .long  sym_0600511E
.L_0601CA90:
    .long  0x00016BC0
.L_0601CA94:
    .long  0x25E7B168
.L_0601CA98:
    .long  sym_06063958
.L_0601CA9C:
    .long  sym_06028400
.L_0601CAA0:
    .long  sym_06063960
.L_0601CAA4:
    .long  channel_nibble_config
.L_0601CAA8:
    jsr @r13
    nop
    mov #0x1, r5
    jsr @r13
    mov #0x4, r4
    mov #0x2, r5
    jsr @r13
    mov #0x8, r4
    mov #0x0, r5
    jsr @r13
    mov #0x10, r4
    mov #0x0, r5
    jsr @r13
    mov #0x20, r4
    .byte   0xD6, 0x21    /* mov.l r6, sym_06086028 */
    .byte   0xD4, 0x22    /* mov.l r4, 0x25F00FFE */
    .byte   0xD3, 0x22    /* mov.l r3, tilemap_dma_update */
    jsr @r3
    mov #0x1, r5
    .byte   0xD4, 0x22    /* mov.l r4, sym_0605B6D8 */
    .byte   0xD2, 0x22    /* mov.l r2, 0x40000000 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    .byte   0xD3, 0x21    /* mov.l r3, sym_06026CE0 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x20    /* mov.l r3, sym_06059F44 */
    mov.l r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
