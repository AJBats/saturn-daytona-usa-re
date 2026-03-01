
    .section .text.FUN_0601B170


    .global disc_load_mgr
    .type disc_load_mgr, @function
disc_load_mgr:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_0601B268, r3
    mov.l r8, @r3
    mov.w   DAT_0601b246, r2
    mov.l   .L_0601B26C, r3
    mov.l r2, @r3
    mov.l   .L_0601B270, r4
    mov.l   .L_0601B274, r3
    jsr @r3
    nop
    mov r8, r6
    mov r8, r5
    mov.w   DAT_0601b248, r2
    mov.l r2, @-r15
    mov.w   DAT_0601b24a, r7
    mov.l   .L_0601B278, r3
    jsr @r3
    mov r8, r4
    mov.l   .L_0601B27C, r3
    mov.l r8, @r3
    mov.l   .L_0601B270, r2
    mov.l   .L_0601B280, r3
    mov.l @r2, r2
    mov.w r3, @r2
    mov.l   .L_0601B284, r3
    jsr @r3
    nop
    mov.w   .L_0601B24C, r6
    mov.l   .L_0601B288, r14
    mov.l   .L_0601B28C, r4
    mov.l   .L_0601B270, r3
    mov.l   .L_0601B290, r2
    mov r14, r5
    mov.l @r4, r4
    mov.l @r3, r3
    shll2 r4
    shll r4
    jsr @r2
    add r3, r4
    mov.w   .L_0601B24E, r10
    mov #0x78, r6
    mov.l   .L_0601B294, r12
    mov.w   .L_0601B250, r13
    mov.w   .L_0601B252, r7
    mov r13, r5
    add r14, r7
    mov.l r7, @(12, r15)
    jsr @r12
    mov r10, r4
    mov.w   DAT_0601b254, r11
    mov #0x7C, r6
    mov r13, r5
    mov.w   DAT_0601b256, r7
    add r14, r7
    mov.l r7, @(4, r15)
    jsr @r12
    mov r11, r4
    mov.w   .L_0601B258, r9
    mov r13, r5
    mov.w   DAT_0601b25a, r7
    add r14, r7
    mov.l r7, @(8, r15)
    mov.w   .L_0601B25C, r6
    jsr @r12
    mov r9, r4
    mov.l   .L_0601B298, r14
    mov.w   DAT_0601b25e, r6
    mov.w   DAT_0601b260, r4
    jsr @r14
    mov r10, r5
    mov r11, r5
    mov.w   DAT_0601b262, r6
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    mov.w   .L_0601B264, r6
    mov r9, r5
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov #0x78, r6
    mov r13, r5
    mov.l @(12, r15), r7
    jsr @r12
    mov r10, r4
    mov.l @(4, r15), r7
    mov #0x7C, r6
    mov r13, r5
    jsr @r12
    mov r11, r4
    mov r13, r5
    mov.l @(8, r15), r7
    mov.w   .L_0601B25C, r6
    jsr @r12
    mov r9, r4
    mov.w   DAT_0601b25e, r6
    mov.w   DAT_0601b260, r4
    jsr @r14
    mov r10, r5
    mov.w   DAT_0601b262, r6
    mov r11, r5
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    bra     .L_0601B29C
    nop

    .global DAT_0601b246
DAT_0601b246:
    .2byte  0x20D8                          /* timing init constant (8408 decimal) */

    .global DAT_0601b248
DAT_0601b248:
    .2byte  0x00DF                          /* screen height - 1 (223) */

    .global DAT_0601b24a
DAT_0601b24a:
    .2byte  0x015F                          /* screen width - 1 (351) */
.L_0601B24C:
    .2byte  0x0640                          /* memcpy byte count (1600) */
.L_0601B24E:
    .2byte  0x0101                          /* VDP1 sprite slot A */
.L_0601B250:
    .2byte  0x0B40                          /* sprite dimension param */
.L_0601B252:
    .2byte  0x4B46                          /* CD-ROM data offset for sprite A */

    .global DAT_0601b254
DAT_0601b254:
    .2byte  0x0102                          /* VDP1 sprite slot B */

    .global DAT_0601b256
DAT_0601b256:
    .2byte  0x5313                          /* CD-ROM data offset for sprite B */
.L_0601B258:
    .2byte  0x0103                          /* VDP1 sprite slot C */

    .global DAT_0601b25a
DAT_0601b25a:
    .2byte  0x5B86                          /* CD-ROM data offset for sprite C */
.L_0601B25C:
    .2byte  0x0080                          /* small sprite type flags */

    .global DAT_0601b25e
DAT_0601b25e:
    .2byte  0x0084                          /* object flags for slot A */

    .global DAT_0601b260
DAT_0601b260:
    .2byte  0x0104                          /* object slot ID for A registration */

    .global DAT_0601b262
DAT_0601b262:
    .2byte  0x0088                          /* object flags for slot B */
.L_0601B264:
    .2byte  0x008C                          /* object flags for slot C */
    .2byte  0xFFFF                          /* alignment padding */
.L_0601B268:
    .4byte  sym_0606A4F4                    /* race state config parameter (32-bit) */
.L_0601B26C:
    .4byte  sym_0606A4EC                    /* timing register (32-bit) */
.L_0601B270:
    .4byte  sym_06063F5C                    /* car struct array base pointer */
.L_0601B274:
    .4byte  vdp2_scroll_update              /* scroll plane setup function */
.L_0601B278:
    .4byte  sym_060393FC                    /* screen coordinate bounds setup */
.L_0601B27C:
    .4byte  sym_0605A008                    /* DMA configuration state word */
.L_0601B280:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_0601B284:
    .4byte  sym_06012E00                    /* CD texture loader entry point */
.L_0601B288:
    .4byte  0x002A0000                      /* CD-ROM memory-mapped base address */
.L_0601B28C:
    .4byte  sym_06059FFC                    /* current game state index */
.L_0601B290:
    .4byte  memcpy_word_idx                 /* word-indexed memory copy */
.L_0601B294:
    .4byte  vdp1_sprite_render              /* VDP1 sprite registration */
.L_0601B298:
    .4byte  sym_06007540                    /* game object registration */
.L_0601B29C:
    mov.w   DAT_0601b38a, r6
    mov r9, r5
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov #0x78, r6
    mov r13, r5
    mov.l @(12, r15), r7
    jsr @r12
    mov r10, r4
    mov.l @(4, r15), r7
    mov #0x7C, r6
    mov r13, r5
    jsr @r12
    mov r11, r4
    mov r13, r5
    mov.l @(8, r15), r7
    mov.w   DAT_0601b38c, r6
    jsr @r12
    mov r9, r4
    mov.w   DAT_0601b38e, r6
    mov.w   DAT_0601b390, r4
    jsr @r14
    mov r10, r5
    mov.w   DAT_0601b392, r6
    mov r11, r5
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    mov r9, r5
    mov.w   DAT_0601b38a, r6
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov r8, r3
    mov.l   .L_0601B398, r2
    mov.w r3, @r2
    mov.l   .L_0601B39C, r13
    mov.l   .L_0601B3A0, r3
    mov.l @r13, r2
    or r3, r2
    mov.l   .L_0601B3A4, r3
    jsr @r3
    mov.l r2, @r13
    mov.l   .L_0601B3A4, r3
    jsr @r3
    nop
    mov.l   .L_0601B3A8, r5
    mov.l   .L_0601B3AC, r4
    mov.l   .L_0601B3B0, r3
    jsr @r3
    mov #0x40, r6
    mov.l   .L_0601B3B4, r5
    mov.l   .L_0601B3B8, r4
    mov.l   .L_0601B3B0, r3
    jsr @r3
    mov #0x20, r6
    mov #0x9, r7
    mov.l   .L_0601B3BC, r5
    mov.l   .L_0601B3C0, r4
    mov.l   .L_0601B3C4, r3
    jsr @r3
    mov r8, r6
    mov.l   .L_0601B3C8, r5
    mov.l   .L_0601B3CC, r4
    mov.l   .L_0601B3D0, r3
    add r8, r5
    jsr @r3
    mov.l r5, @(4, r15)
    mov r8, r6
    mov.l @(4, r15), r5
    mov.l   .L_0601B3D4, r7
    mov.l   .L_0601B3D8, r3
    jsr @r3
    mov #0x4, r4
    mov r8, r6
    mov r8, r5
    mov.l   .L_0601B3DC, r3
    jsr @r3
    mov #0x10, r4
    mov r8, r6
    mov r8, r5
    mov.l   .L_0601B3DC, r3
    jsr @r3
    mov #0x20, r4
    mov.l   .L_0601B3E0, r14
    mov.w   .L_0601B394, r4
    jsr @r14
    mov #0x7, r5
    mov r8, r5
    jsr @r14
    mov #0x4, r4
    mov #0x1, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x5, r5
    jsr @r14
    mov #0x20, r4
    mov r8, r5
    jsr @r14
    mov #0x1, r4
    mov.l   .L_0601B3E4, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0601B3E8, r3
    jsr @r3
    nop
    mov.l   .L_0601B3EC, r2
    mov.l @r13, r3
    or r2, r3
    mov.l r3, @r13
    mov r8, r2
    mov.l   .L_0601B3F0, r3
    mov.b r2, @r3
    bra     .L_0601B3F4
    nop

    .global DAT_0601b38a
DAT_0601b38a:
    .2byte  0x008C                          /* object flags for slot C (second pass) */

    .global DAT_0601b38c
DAT_0601b38c:
    .2byte  0x0080                          /* sprite flags small (second pass) */

    .global DAT_0601b38e
DAT_0601b38e:
    .2byte  0x0084                          /* object flags for slot A (second pass) */

    .global DAT_0601b390
DAT_0601b390:
    .2byte  0x0104                          /* object slot ID A (second pass) */

    .global DAT_0601b392
DAT_0601b392:
    .2byte  0x0088                          /* object flags for slot B (second pass) */
.L_0601B394:
    .2byte  0x0100                          /* display channel group ID */
    .2byte  0xFFFF                          /* alignment padding */
.L_0601B398:
    .4byte  sym_0605AAA0                    /* VDP2 scroll position state (16-bit) */
.L_0601B39C:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit bitmask) */
.L_0601B3A0:
    .4byte  0x80000000                      /* sign bit (bit 31) */
.L_0601B3A4:
    .4byte  sym_06026CE0                    /* display update / camera state finalization */
.L_0601B3A8:
    .4byte  sym_0604842C                    /* palette data source A (WRAM) */
.L_0601B3AC:
    .4byte  0x25F00540                      /* VDP2 color RAM +0x540 */
.L_0601B3B0:
    .4byte  dma_transfer                    /* DMA transfer routine */
.L_0601B3B4:
    .4byte  sym_060487EC                    /* palette data source B (WRAM) */
.L_0601B3B8:
    .4byte  0x25F001A0                      /* VDP2 color RAM +0x1A0 */
.L_0601B3BC:
    .4byte  0x00017700                      /* tile data size (96000 bytes) */
.L_0601B3C0:
    .4byte  0x25E6F9C4                      /* VDP2 VRAM tile destination A */
.L_0601B3C4:
    .4byte  sym_0600511E                    /* VRAM tile data copy routine */
.L_0601B3C8:
    .4byte  sym_06094FA8                    /* tilemap source data (WRAM) */
.L_0601B3CC:
    .4byte  0x25E75DDC                      /* VDP2 VRAM tilemap destination B */
.L_0601B3D0:
    .4byte  dma_memory_transfer             /* DMA memory-to-memory transfer */
.L_0601B3D4:
    .4byte  0x0000B000                      /* DMA block size (45056 bytes) */
.L_0601B3D8:
    .4byte  sym_06028400                    /* display list loader */
.L_0601B3DC:
    .4byte  display_channel_b               /* display channel B setup */
.L_0601B3E0:
    .4byte  channel_nibble_config           /* channel priority nibble configuration */
.L_0601B3E4:
    .4byte  sym_0602853E                    /* display layer configuration */
.L_0601B3E8:
    .4byte  sym_06028560                    /* render state commit / flush */
.L_0601B3EC:
    .4byte  0x40000000                      /* bit 30 — "ready" flag */
.L_0601B3F0:
    .4byte  sym_0608600D                    /* disc error code (byte: 0=none) */
.L_0601B3F4:
    .byte   0xD3, 0x19    /* mov.l r3, sym_0608600C */
    mov.b r2, @r3
    .byte   0xD3, 0x19    /* mov.l r3, sym_0608600E */
    mov.b r2, @r3
    mov #0xF, r6
    mov #0x4, r5
    mov r5, r4
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x14    /* mov.l r3, handler_dispatch */
    jmp @r3
    mov.l @r15+, r14
