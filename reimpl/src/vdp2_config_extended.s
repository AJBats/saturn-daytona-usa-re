
    .section .text.FUN_06018A3C


    .global vdp2_config_extended
    .type vdp2_config_extended, @function
vdp2_config_extended:
    mov.l r14, @-r15
    mov #0xA, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x1, r12
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x1C, r15
    mov.l   .L_06018A90, r13
    mov.l   .L_06018A94, r5
    mov.l   .L_06018A98, r4
    mov.l @r5, r3
    cmp/ge r2, r3
    bf/s    .L_06018A78
    mov #0x0, r14
    mov #0xC, r3
    mov.l @r5, r2
    cmp/ge r3, r2
    bf      .L_06018A6A
    bra     .L_06018A6E
    mov.b r12, @r4
.L_06018A6A:
    extu.b r14, r2
    mov.b r2, @r4
.L_06018A6E:
    exts.b r12, r3
    mov.l   .L_06018A9C, r2
    mov.b r3, @r2
    bra     .L_06018A82
    nop
.L_06018A78:
    extu.b r14, r3
    mov.b r3, @r4
    exts.b r14, r2
    mov.l   .L_06018A9C, r3
    mov.b r2, @r3
.L_06018A82:
    mov.l   .L_06018AA0, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06018AA4
    bra     .L_06018AE4
    nop
    .2byte  0xFFFF
.L_06018A90:
    .4byte  sym_0607EAD8                        /* → course ID word */
.L_06018A94:
    .4byte  sym_06078868                        /* loading progress counter */
.L_06018A98:
    .4byte  sym_0607867C                        /* 1 when progress >= 12 */
.L_06018A9C:
    .4byte  sym_06083255                        /* 1 enables secondary CPU rendering */
.L_06018AA0:
    .4byte  sym_0605AD08                        /* nonzero = init already done */

.L_06018AA4:
    mov.l   .L_06018B90, r3
    jsr @r3
    nop
    mov.l   .L_06018B94, r3
    jsr @r3
    mov.l @r13, r4
    mov.l @r13, r2
    mov.l   .L_06018B98, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    mov.l   .L_06018B9C, r3
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_06018BA0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06018AD4
    mov.l   .L_06018BA4, r3
    jsr @r3
    nop
.L_06018AD4:
    mov.l   .L_06018BA8, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_06018AE4
    mov.l   .L_06018BAC, r3
    jsr @r3
    nop

.L_06018AE4:
    mov.l   .L_06018BA8, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06018AF4
    mov.l   .L_06018BAC, r3
    jsr @r3
    nop

.L_06018AF4:
    mov.l   .L_06018BB0, r10
    mov.l   .L_06018BB4, r2
    mov.w   DAT_06018b8e, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06018BD0
    mov.l   .L_06018BB8, r11
    mov.l   .L_06018BBC, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06018B20
    mov.b @r11, r3
    extu.b r3, r3
    mov.l   .L_06018BC0, r2
    add r2, r3
    mov.b @r3, r1
    mov.b r1, @r15
    mov #0xF, r6
    mov.b @r15, r5
    bra     .L_06018BD4
    mov.l r5, @(4, r15)
.L_06018B20:
    mov.l   .L_06018BC4, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06018B7C
    mov.b @r11, r4
    mov.l   .L_06018BC8, r3
    extu.b r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x2, r4
    mov r15, r2
    add #0x8, r2
    mov.l r4, @r2
    mov r15, r3
    add #0x8, r3
    mov #0x6, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    add #0x8, r3
    extu.b r12, r2
    mov r2, r0
    mov.b r0, @(5, r3)
    mov r15, r3
    add #0x8, r3
    mov.l r4, @(8, r3)
    mov r15, r2
    add #0x8, r2
    mov #0x9, r3
    mov r3, r0
    mov.b r0, @(12, r2)
    mov r15, r3
    add #0x8, r3
    mov #0x63, r2
    mov r2, r0
    mov.b r0, @(13, r3)
    mov r15, r3
    add #0x8, r3
    add #0x2C, r2
    mov #0x10, r0
    mov.b r2, @(r0, r3)
    mov r15, r4
    mov.l   .L_06018BCC, r3
    jsr @r3
    add #0x8, r4
    bra     .L_06018B8A
    nop
.L_06018B7C:
    mov #0xF, r6
    mov.b @r11, r5
    extu.b r5, r5
    add #0x6, r5
    mov.l r5, @r15
    jsr @r10
    mov r5, r4
.L_06018B8A:
    bra     .L_06018BD8
    nop

    .global DAT_06018b8e
DAT_06018b8e:
    .2byte  0x4000                              /* game state bit 14 mask */
.L_06018B90:
    .4byte  render_obj_stub                     /* clear render object list */
.L_06018B94:
    .4byte  cd_texture_loader                   /* load course textures from CD */
.L_06018B98:
    .4byte  sym_0605D1BC                        /* course-specific init jump table */
.L_06018B9C:
    .4byte  cd_course_loader                    /* load course data from CD */
.L_06018BA0:
    .4byte  sym_06078635                        /* nonzero = demo/attract mode */
.L_06018BA4:
    .4byte  sym_06012E7C                        /* normal (non-demo) race init */
.L_06018BA8:
    .4byte  sym_0607ED8C                        /* nonzero = replay playback mode */
.L_06018BAC:
    .4byte  race_state_pair_1                   /* race state setup */
.L_06018BB0:
    .4byte  handler_dispatch                    /* handler mode dispatcher */
.L_06018BB4:
    .4byte  sym_0607EBC4                        /* game state bitmask */
.L_06018BB8:
    .4byte  sym_06078648                        /* course selection index (byte) */
.L_06018BBC:
    .4byte  sym_0605AB18                        /* nonzero = menu overlay active */
.L_06018BC0:
    .4byte  sym_0605D23C                        /* handler offset lookup table */
.L_06018BC4:
    .4byte  sym_0605AD00                        /* course variant (0/1/2) */
.L_06018BC8:
    .4byte  sym_06018E1E                        /* TU-local variant helper */
.L_06018BCC:
    .4byte  ai_throttle_modulate                /* AI throttle config dispatch */

.L_06018BD0:
    mov #0x0, r6
    mov #0x3, r5
.L_06018BD4:
    jsr @r10
    mov r5, r4

.L_06018BD8:
    mov.l   .L_06018CC8, r3
    mov.l r14, @r3
    mov.l @r13, r4
    mov.l   .L_06018CCC, r2
    shll r4
    add r4, r2
    mov.w @r2, r3
    extu.w r3, r3
    mov.l   .L_06018CD0, r2
    mov.l r3, @r2
    mov.l   .L_06018CD4, r1
    mov.l   .L_06018CD8, r2
    mov.l r1, @r2
    mov.l   .L_06018CDC, r1
    mov.l   .L_06018CE0, r2
    mov.l r1, @r2
    mov.l   .L_06018CE4, r5
    mov.l @r13, r1
    mov.l   .L_06018CE8, r2
    shll2 r1
    shll r1
    add r2, r1
    mov.l r1, @r5
    mov.l @r1, r1
    mov.l   .L_06018CEC, r3
    add #0x1, r1
    jsr @r3
    mov r12, r0
    add #-0x1, r0
    mov #0x1, r2
    mov.l   .L_06018CF0, r3
    mov.l r0, @r3
    mov.l   .L_06018CF4, r3
    mov.l r14, @r3
    mov.l   .L_06018CF8, r3
    mov.l r2, @r3
    mov.l   .L_06018CFC, r3
    mov.l r14, @r3
    mov.l   .L_06018D00, r3
    mov.l r14, @r3
    mov.l   .L_06018D04, r3
    mov.l r14, @r3

    mov.l   .L_06018D08, r7
    mov.l   .L_06018D0C, r6
    mov.l @r6, r6
    exts.b r6, r6
    mov r6, r3
    shll r6
    shll2 r3
    add r3, r6
    exts.b r6, r6
    mov.l   .L_06018D10, r0
    add r6, r0
    mov.w @(r0, r4), r3
    extu.w r3, r3
    mov.l r3, @r7

    mov.l   .L_06018D14, r2
    add r4, r2
    mov.w @r2, r3
    extu.w r3, r3
    mov.l   .L_06018D18, r2
    mov.l r3, @r2

    mov.l   .L_06018D1C, r1
    add r4, r1
    mov.w @r1, r2
    extu.w r2, r2
    mov.l   .L_06018D20, r1
    mov.l r2, @r1

    mov.l   .L_06018D24, r5
    mov.l   .L_06018D28, r0
    add r6, r0
    mov.w @(r0, r4), r1
    extu.w r1, r1
    mov.l r1, @r5

    mov.l   .L_06018D2C, r0
    mov.l @r0, r0
    exts.b r0, r0
    mov r0, r3
    shll r0
    shll2 r3
    add r3, r0
    exts.b r0, r0
    mov.l   .L_06018D30, r2
    add r2, r0
    mov.w @(r0, r4), r3
    extu.w r3, r3
    mov.l @r7, r1
    mul.l r1, r3
    sts macl, r3
    mov.l @r5, r0
    add r3, r0
    mov.l r0, @r5

    mov.w   .L_06018CC6, r6
    mov.l   .L_06018D34, r5
    mov.l   .L_06018D38, r4
    mov.l   .L_06018D3C, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_06018D40, r3
    jsr @r3
    nop

    mov.l   .L_06018D44, r3
    jsr @r3
    nop
    mov.l   .L_06018D48, r3
    jsr @r3
    nop
    mov.l   .L_06018D4C, r3
    jsr @r3
    nop
    mov.l   .L_06018D50, r3
    mov.l r14, @r3
    mov.l   .L_06018D54, r3
    jsr @r3
    nop
    bra     .L_06018D58
    nop
.L_06018CC6:
    .2byte  0x00A0                              /* 160 bytes to copy */
.L_06018CC8:
    .4byte  sym_0607EBE4                        /* 0 = rendering disabled */
.L_06018CCC:
    .4byte  sym_0604806C                        /* word table: sprites per course */
.L_06018CD0:
    .4byte  sym_0607EA9C                        /* stored VDP1 sprite count */
.L_06018CD4:
    .4byte  sym_060D5840                        /* texture bank A base address */
.L_06018CD8:
    .4byte  sym_0607EB84                        /* → texture bank A pointer */
.L_06018CDC:
    .4byte  sym_060C6000                        /* texture bank B base address */
.L_06018CE0:
    .4byte  sym_0607EB88                        /* → texture bank B pointer */
.L_06018CE4:
    .4byte  sym_06063F3C                        /* → current course data entry */
.L_06018CE8:
    .4byte  sym_0604800C                        /* course table, 8-byte stride */
.L_06018CEC:
    .4byte  sym_06035280                        /* track segment initialization */
.L_06018CF0:
    .4byte  sym_06063F18                        /* segment count (result - 1) */
.L_06018CF4:
    .4byte  sym_060786AC                        /* physics init state */
.L_06018CF8:
    .4byte  sym_06063F1C                        /* 1 = segments ready */
.L_06018CFC:
    .4byte  sym_06063F20                        /* current segment index A */
.L_06018D00:
    .4byte  sym_06063F24                        /* current segment index B */
.L_06018D04:
    .4byte  sym_06086034                        /* checkpoint counter */
.L_06018D08:
    .4byte  sym_06063F28                        /* track width result */
.L_06018D0C:
    .4byte  sym_0605AD00                        /* course variant A (byte) */
.L_06018D10:
    .4byte  sym_0604805A                        /* width table A [variant×6+course×2] */
.L_06018D14:
    .4byte  sym_06048072                        /* elevation table [course×2] */
.L_06018D18:
    .4byte  sym_0607EA98                        /* track elevation result */
.L_06018D1C:
    .4byte  sym_06048024                        /* segment count table [course×2] */
.L_06018D20:
    .4byte  sym_0607EAA0                        /* segment count B result */
.L_06018D24:
    .4byte  sym_0607EAAC                        /* track length result */
.L_06018D28:
    .4byte  sym_0604802A                        /* length table [variant×6+course×2] */
.L_06018D2C:
    .4byte  sym_0605AD0C                        /* course variant B (byte) */
.L_06018D30:
    .4byte  sym_0604803C                        /* width table B [variant×6+course×2] */
.L_06018D34:
    .4byte  sym_0605CDDC                        /* VDP1 sprite source data */
.L_06018D38:
    .4byte  sym_06059FFC                        /* sprite bank index */
.L_06018D3C:
    .4byte  0x25C00220                          /* VDP1 VRAM +0x00220 */
.L_06018D40:
    .4byte  memcpy_word_idx                     /* word-indexed memcpy */
.L_06018D44:
    .4byte  sym_060149E0                        /* display hardware init */
.L_06018D48:
    .4byte  display_channels_clear              /* clear all display channels */
.L_06018D4C:
    .4byte  sym_06026CE0                        /* render/display update */
.L_06018D50:
    .4byte  sym_06059F44                        /* audio enable flag (cleared) */
.L_06018D54:
    .4byte  audio_display_init                  /* audio subsystem init */

.L_06018D58:
    mov.l   .L_06018DB0, r3
    mov.l r14, @r3
    mov.l   .L_06018DB4, r2
    mov.l   .L_06018DB8, r3
    add r14, r2
    mov.l r2, @r3
    mov.l   .L_06018DBC, r3
    jsr @r3
    nop
    mov.l   .L_06018DC0, r3
    jsr @r3
    nop
    mov.l   .L_06018DC4, r3
    jsr @r3
    nop
    mov.l @r13, r2
    mov.l   .L_06018DC8, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    mov.l   .L_06018DCC, r3
    jsr @r3
    nop
    mov.l   .L_06018DD0, r3
    jsr @r3
    nop
    mov.l   .L_06018DD4, r3
    jsr @r3
    nop
    mov.l   .L_06018DD8, r3
    jsr @r3
    nop
    add #0x1C, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_06018DB0:
    .4byte  sym_0605AD08                        /* init_done flag (cleared on exit) */
.L_06018DB4:
    .4byte  sym_06078900                        /* car struct array base */
.L_06018DB8:
    .4byte  sym_0607E944                        /* → active player car pointer */
.L_06018DBC:
    .4byte  hud_coord_calc                      /* HUD coordinate calculation */
.L_06018DC0:
    .4byte  dma_vram_init                       /* DMA VRAM initialization */
.L_06018DC4:
    .4byte  dma_config_dispatch                 /* DMA configuration dispatch */
.L_06018DC8:
    .4byte  sym_0605D1CC                        /* course post-init jump table */
.L_06018DCC:
    .4byte  gameover_channel_setup              /* game-over display channel */
.L_06018DD0:
    .4byte  sym_06003430                        /* system cleanup / finalize */
.L_06018DD4:
    .4byte  channel_config_b                    /* display channel config */
.L_06018DD8:
    .4byte  obj_render_cleanup                  /* object render cleanup */
