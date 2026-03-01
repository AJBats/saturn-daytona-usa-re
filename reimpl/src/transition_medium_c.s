
    .section .text.FUN_0600FED0


    .global transition_medium_c
    .type transition_medium_c, @function
transition_medium_c:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600FF60, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov r3, r2
    mov.l r3, @r14
    mov.w   .L_wpool_0600FF5C, r3
    cmp/gt r3, r2
    bf      .L_0600FEFA
    mov.l   .L_pool_0600FF64, r5
    mov.l   .L_pool_0600FF68, r3
    mov r5, r4
    jsr @r3
    add #-0x20, r4
.L_0600FEFA:
    mov.l @r14, r2
    mov.w   .L_wpool_0600FF5C, r3
    cmp/eq r3, r2
    bf      .L_0600FFB4
    mov.l   .L_pool_0600FF6C, r8
    mov.l   .L_pool_0600FF70, r9
    mov.l   .L_pool_0600FF74, r10
    mov.l   .L_pool_0600FF78, r11
    mov.l   .L_pool_0600FF7C, r12
    mov.w   .L_wpool_0600FF5E, r13
    mov.l   .L_pool_0600FF80, r0
    bra     .L_0600FFA8
    mov.l @r0, r0
.L_0600FF14:
    mov #0x20, r6
    mov.l   .L_pool_0600FF84, r5
    jsr @r11
    mov r8, r4
    mov.l   .L_pool_0600FF88, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov.l   .L_pool_0600FF8C, r5
    bra     .L_0600FF54
    mov #0x0, r6
.L_0600FF2A:
    mov #0x20, r6
    mov.l   .L_pool_0600FF90, r5
    jsr @r11
    mov r8, r4
    mov.l   .L_pool_0600FF94, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov.l   .L_pool_0600FF98, r5
    bra     .L_0600FF54
    mov #0x0, r6
.L_0600FF40:
    mov #0x20, r6
    mov.l   .L_pool_0600FF9C, r5
    jsr @r11
    mov r8, r4
    mov.l   .L_pool_0600FFA0, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov #0x0, r6
    mov.l   .L_pool_0600FFA4, r5
.L_0600FF54:
    jsr @r9
    mov #0x4, r4
    bra     .L_0600FFB4
    nop
.L_wpool_0600FF5C:
    .2byte  0x0099                 /* countdown threshold: 153 (fade → asset load boundary) */
.L_wpool_0600FF5E:
    .2byte  0x5A00                 /* tilemap copy size: 23040 bytes */
.L_pool_0600FF60:
    .4byte  sym_0607EBCC           /* &countdown_timer (attract mode countdown, 32-bit) */
.L_pool_0600FF64:
    .4byte  0x25F00540             /* VDP2 color RAM +0x540 (fade destination palette) */
.L_pool_0600FF68:
    .4byte  throttle_input_proc    /* palette color interpolation function */
.L_pool_0600FF6C:
    .4byte  0x25F004A0             /* VDP2 color RAM +0x4A0 (course palette destination) */
.L_pool_0600FF70:
    .4byte  sym_06028400           /* tile_writer / display list loader */
.L_pool_0600FF74:
    .4byte  dma_memory_transfer    /* DMA memory-to-memory transfer */
.L_pool_0600FF78:
    .4byte  memcpy_word_idx        /* word-indexed memory copy */
.L_pool_0600FF7C:
    .4byte  0x25E34000             /* VDP2 VRAM +0x34000 (tilemap destination) */
.L_pool_0600FF80:
    .4byte  sym_0607EAD8           /* &course_index (0=Beginner, 1=Advanced, 2=Expert) */
.L_pool_0600FF84:
    .4byte  sym_0604872C           /* course 0 palette data (16 colors, 32 bytes) */
.L_pool_0600FF88:
    .4byte  0x25E61CEC             /* VDP2 VRAM +0x61CEC (course 0 tilemap source) */
.L_pool_0600FF8C:
    .4byte  0x25E60000             /* VDP2 VRAM +0x60000 (course 0 tile destination) */
.L_pool_0600FF90:
    .4byte  sym_0604874C           /* course 1 palette data (16 colors, 32 bytes) */
.L_pool_0600FF94:
    .4byte  0x25E665D4             /* VDP2 VRAM +0x665D4 (course 1 tilemap source) */
.L_pool_0600FF98:
    .4byte  0x25E609A4             /* VDP2 VRAM +0x609A4 (course 1 tile destination) */
.L_pool_0600FF9C:
    .4byte  sym_0604876C           /* course 2 palette data (16 colors, 32 bytes) */
.L_pool_0600FFA0:
    .4byte  0x25E6A9CC             /* VDP2 VRAM +0x6A9CC (course 2 tilemap source) */
.L_pool_0600FFA4:
    .4byte  0x25E61348             /* VDP2 VRAM +0x61348 (course 2 tile destination) */
.L_0600FFA8:
    cmp/eq #0x0, r0
    bt      .L_0600FF14
    cmp/eq #0x1, r0
    bt      .L_0600FF2A
    cmp/eq #0x2, r0
    bt      .L_0600FF40
.L_0600FFB4:
    mov.l @r14, r0
    cmp/eq #0x78, r0
    bf      .L_0600FFBE
    mov #0x0, r3
    mov.l r3, @r14
.L_0600FFBE:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
