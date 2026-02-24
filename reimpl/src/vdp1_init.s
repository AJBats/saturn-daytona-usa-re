/* vdp1_init.s -- VDP1 initialization and framebuffer resolution config
 * Translation unit: 0x0600A140 - 0x0600A392
 *
 * Function catalog:
 *   vdp1_init       — Clears VDP1 command table and both framebuffer planes.
 *   sym_0600A1F6    — Sets framebuffer resolution mode based on course/display config.
 *   sym_0600A33C    — Sets framebuffer resolution mode based on game mode (0-3).
 *
 * VDP1 memory layout:
 *   0x25C00000 (512KB) — VRAM: command tables, character patterns, gouraud tables
 *   0x25C80000 (256KB) — Framebuffer: double-buffered draw/display planes
 *
 * Initialization sequence:
 *   1. Write 0x80000000 to VRAM[0] — VDP1 end-of-list command (bit15 = END flag)
 *   2. Clear framebuffer plane A (256KB = 0x10000 longs, 8 bytes/iteration)
 *   3. Trigger buffer swap
 *   4. Clear framebuffer plane B (same)
 *   5. Trigger buffer swap again
 * Both planes are zeroed to prevent stale graphics on first frame.
 */

    .section .text.FUN_0600A140


    .global vdp1_init
    .type vdp1_init, @function
vdp1_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14                      /* r14 = 0 (clear value) */

    /* Write end-of-list command to VRAM[0] */
    mov.l   .L_vdp1_end_cmd, r3       /* 0x80000000 = END flag in command word */
    mov.l   .L_vdp1_vram, r2          /* 0x25C00000 = VDP1 VRAM base */
    mov.l r3, @r2

    /* Clear framebuffer plane A: 256KB = 0x10000 longs */
    mov.l   .L_vdp1_fb, r5            /* 0x25C80000 = framebuffer base */
    mov.l   .L_fb_clear_count, r4     /* 0x10000 = 64K (loop decrements by 2) */
.L_0600A150:
    mov r5, r3
    add #-0x2, r4                      /* count -= 2 */
    add #0x4, r5
    mov.l r14, @r3                     /* write 0 to [addr] */
    mov r5, r2
    add #0x4, r5
    tst r4, r4
    bf/s    .L_0600A150
    mov.l r14, @r2                     /* write 0 to [addr+4] */

    /* Trigger buffer swap so we can clear the other plane */
    mov.l   .L_fb_swap_flag, r3
    mov.l r14, @r3                     /* clear swap flag */
    mov.l   .L_fn_vdp2_loop_ctrl, r3
    jsr @r3                            /* execute buffer swap */
    nop
    mov.l   .L_vblank_phase, r3
    mov.l r14, @r3                     /* reset vblank phase */

    /* Clear framebuffer plane B (same procedure) */
    mov.l   .L_vdp1_fb, r5
    mov.l   .L_fb_clear_count, r4
.L_0600A174:
    mov r5, r2
    add #-0x2, r4
    add #0x4, r5
    mov.l r14, @r2
    mov r5, r3
    add #0x4, r5
    tst r4, r4
    bf/s    .L_0600A174
    mov.l r14, @r3

    /* Trigger second buffer swap to restore original state */
    mov.l   .L_fb_swap_flag, r3
    mov.l r14, @r3
    mov.l   .L_fn_vdp2_loop_ctrl, r3
    jsr @r3
    nop
    mov.l   .L_vblank_phase, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF

/* Long pool — vdp1_init */
.L_vdp1_end_cmd:
    .4byte  0x80000000                  /* VDP1 end-of-list command (bit15=END) */
.L_vdp1_vram:
    .4byte  0x25C00000                  /* VDP1 VRAM base (cache-through) */
.L_vdp1_fb:
    .4byte  0x25C80000                  /* VDP1 framebuffer base (cache-through) */
.L_fb_clear_count:
    .4byte  0x00010000                  /* 64K iterations × 8 bytes = 256KB */
.L_fb_swap_flag:
    .4byte  sym_0605A00C               /* framebuffer swap request flag */
.L_fn_vdp2_loop_ctrl:
    .4byte  sym_06026CE0               /* VDP2 loop control (triggers buffer swap) */
.L_vblank_phase:
    .4byte  sym_06059F44               /* VBlank phase flag */
    .4byte  0xD01B6000
    .4byte  0x600C2008
    .4byte  0x8B08D01A
    .4byte  0x6001600D
    .4byte  0x20088B12
    .4byte  0xD0186002
    .4byte  0x20088B0E
    .4byte  0xD417D318
    .4byte  0x6331633C
    .4byte  0x2430D217
    .4byte  0x6222622C
    .4byte  0x60238041
    .4byte  0xD3156332
    .4byte  0x633C6033
    .4byte  0x8042000B
    .2byte  0x0009

    .global sym_0600A1F6
sym_0600A1F6:
    mov #0x3, r7
    mov.l   .L_pool_0600A244, r5
    mov.l   .L_pool_0600A248, r4
    mov.l   .L_pool_0600A24C, r0
    mov.l @r0, r0
    tst r0, r0
    bf/s    .L_0600A250
    mov #0x4, r6
    mov.l @r5, r3
    mov.w   DAT_0600a224, r2
    cmp/eq r2, r3
    bf      .L_0600A214
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A214:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A226, r3
    cmp/eq r3, r2
    bf      .L_0600A220
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A220:
    bra     .L_0600A290
    nop

    .global DAT_0600a224
DAT_0600a224:
    .2byte  0x00C4
.L_wpool_0600A226:
    .2byte  0x00A8
    .4byte  sym_06078635
    .4byte  sym_0607ED8C
    .4byte  sym_0605AD00
    .4byte  sym_0607ED90
    .4byte  sym_06063F44
    .4byte  sym_06078868
    .4byte  sym_0607EAB8
.L_pool_0600A244:
    .4byte  sym_0607EBCC
.L_pool_0600A248:
    .4byte  sym_0605A016
.L_pool_0600A24C:
    .4byte  sym_0607EAD8
.L_0600A250:
    mov.l   .L_pool_0600A2E8, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600A276
    mov.l @r5, r3
    mov.w   DAT_0600a2d8, r2
    cmp/eq r2, r3
    bf      .L_0600A266
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A266:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A2DA, r3
    cmp/eq r3, r2
    bf      .L_0600A272
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A272:
    bra     .L_0600A290
    nop
.L_0600A276:
    mov.l @r5, r2
    mov.w   DAT_0600a2dc, r3
    cmp/eq r3, r2
    bf      .L_0600A284
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A284:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A2DE, r3
    cmp/eq r3, r2
    bf      .L_0600A290
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A290:
    rts
    nop
    .4byte  0xE703D515
    .4byte  0xD415D013
    .4byte  0x60028801
    .4byte  0x8F0FE604
    .4byte  0x6252931B
    .4byte  0x32308B02
    .4byte  0x677FA043
    .4byte  0x24716252
    .4byte  0x93153230
    .4byte  0x8B01666F
    .4byte  0x2461A03B
    .4byte  0x0009D009
    .4byte  0x60028802
    .4byte  0x8B366352
    .4byte  0x920A3320
    .4byte  0x8B10677F
    .4byte  0xA0302471

    .global DAT_0600a2d8
DAT_0600a2d8:
    .2byte  0x0287
.L_wpool_0600A2DA:
    .2byte  0x0271

    .global DAT_0600a2dc
DAT_0600a2dc:
    .2byte  0x01AE
.L_wpool_0600A2DE:
    .2byte  0x0190
    .4byte  0x03710352
    .4byte  0x03ABFFFF
.L_pool_0600A2E8:
    .4byte  sym_0607EAD8
    .4byte  sym_0607EBCC
    .4byte  sym_0605A016
    .4byte  0x62529338
    .4byte  0x32308B02
    .4byte  0x666FA01B
    .4byte  0x24616252
    .4byte  0x93323230
    .4byte  0x8B02677F
    .4byte  0xA0142471
    .4byte  0x6252932C
    .4byte  0x32308B02
    .4byte  0x666FA00D
    .4byte  0x24616252
    .4byte  0x93263230
    .4byte  0x8B02677F
    .4byte  0xA0062471
    .4byte  0x62529320
    .4byte  0x32308B01
    .4byte  0x666F2461
    .4byte  0x000B0009

    .global sym_0600A33C
sym_0600A33C:
    mov.l   .L_pool_0600A374, r5
    mov.l   .L_pool_0600A378, r4
    mov.l @r4, r0
    tst r0, r0
    bf      .L_0600A34E
    mov #0x5, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
.L_0600A34E:
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600A35C
    mov #0x6, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
.L_0600A35C:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_0600A37C
    mov #0x7, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
    .2byte  0x0398

    .global DAT_0600a36c
DAT_0600a36c:
    .2byte  0x036D

    .global DAT_0600a36e
DAT_0600a36e:
    .2byte  0x0336

    .global DAT_0600a370
DAT_0600a370:
    .2byte  0x021A

    .global DAT_0600a372
DAT_0600a372:
    .2byte  0x01B4
.L_pool_0600A374:
    .4byte  sym_0605A016
.L_pool_0600A378:
    .4byte  sym_06063E1C
.L_0600A37C:
    mov.l @r4, r0
    cmp/eq #0x3, r0
    bf      .L_0600A386
    mov #0x8, r3
    mov.w r3, @r5
.L_0600A386:
    rts
    nop
    .2byte  0xE300
    .4byte  0xD213000B
    .2byte  0x2232
