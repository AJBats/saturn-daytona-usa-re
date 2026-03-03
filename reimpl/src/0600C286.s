	.text
    .global race_utility_fn
race_utility_fn:
    sts.l pr, @-r15
    .byte   0xD3, 0x14    /* mov.l .L_0600C2DC, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x14    /* mov.l .L_0600C2E0, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x13    /* mov.l .L_0600C2E4, r4 */
    mov.b @r4, r2
    tst r2, r2
    bf      .L_0600C2EC
    .byte   0xD3, 0x12    /* mov.l .L_0600C2E8, r3 */
    jsr @r3
    nop
    bra     .L_0600C2F8
    nop
    .short  0xFE11
    .long  0x0080FFFF
    .long  sym_0608A52C
    .long  sym_06089EDC
    .long  memcpy_long_idx
    .long  physics_calc_dispatch
    .long  race_utility_fn
    .long  sym_06063574
    .long  0x0000FFFF
    .long  0x21000000
    .long  frame_dispatch
    .long  scene_post_render
    .long  replay_playback_engine
    .long  sym_06059FF8
.L_0600C2DC:
    .long  sym_0603C000
.L_0600C2E0:
    .long  camera_track_setup
.L_0600C2E4:
    .long  sym_06082A26
.L_0600C2E8:
    .long  scene_path_b
.L_0600C2EC:
    mov.b @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600C2F8
    .byte   0xD3, 0x21    /* mov.l .L_0600C378, r3 */
    jsr @r3
    nop
.L_0600C2F8:
    .byte   0xD2, 0x20    /* mov.l .L_0600C37C, r2 */
    .byte   0xD3, 0x21    /* mov.l .L_0600C380, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3

    .global sym_0600C302
sym_0600C302:
    mov #0x68, r0
    .byte   0xD4, 0x1F    /* mov.l .L_0600C384, r4 */
    mov.l @r4, r4
    mov.l @(r0, r4), r3
    add #0x7C, r0
    shll2 r3
    shll2 r3
    shll r3
    mov.l r3, @(r0, r4)
    add #-0x4, r0
    mov.l r3, @(r0, r4)
    mov.w   DAT_0600c36a, r0
    mov.w @(r0, r4), r3
    cmp/pl r3
    bf      .L_0600C328
    mov.w   DAT_0600c36a, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_0600C328:
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r3
    cmp/pl r3
    bf      .L_0600C338
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_0600C338:
    mov.w   DAT_0600c36e, r0
    mov.w @(r0, r4), r0
    tst r0, r0
    bt      .L_0600C344
    rts
    nop
.L_0600C344:
    mov #0x12, r7
    mov #0x68, r0
    mov.w   DAT_0600c370, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bf.s    .L_0600C35C
    mov #0x0, r6
    mov.w   DAT_0600c36a, r0
    mov.w r7, @(r0, r4)
    add #0x2, r0
    rts
    mov.w r6, @(r0, r4)
.L_0600C35C:
    mov.w   DAT_0600c372, r0
    mov.w   .L_wpool_0600C37C, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bt      .L_0600C388
    rts
    nop

    .global DAT_0600c36a
DAT_0600c36a:
    .short  0x0172

    .global DAT_0600c36c
DAT_0600c36c:
    .short  0x0174

    .global DAT_0600c36e
DAT_0600c36e:
    .short  0x00DC

    .global DAT_0600c370
DAT_0600c370:
    .short  0x00E6

    .global DAT_0600c372
DAT_0600c372:
    .short  0x0084
.L_wpool_0600C37C:
    .short  0x008C
    .short  0xFFFF
.L_0600C378:
    .long  scene_path_a
.L_0600C37C:
    .long  0x0000FFFF
.L_0600C380:
    .long  0x21800000
.L_0600C384:
    .long  sym_0607E944
.L_0600C388:
    mov #0x68, r0
    mov.w   .L_wpool_0600C41E, r3
    mov.l @(r0, r4), r5
    cmp/gt r3, r5
    bf      .L_0600C3A4
    mov.w   DAT_0600c418, r3
    cmp/ge r3, r5
    bt      .L_0600C3A4
    exts.w r6, r6
    mov.w   .L_wpool_0600C422, r0
    mov.w r6, @(r0, r4)
    exts.w r7, r7
    add #0x2, r0
    mov.w r7, @(r0, r4)
.L_0600C3A4:
    rts
    nop
    .long  0xD51CD61D
    .long  0xD31DD21E
    .long  0x6331633D
    .long  0x33208F41
    .long  0xE703624D
    .long  0xD31B6331
    .long  0x633D2239
    .long  0x22288903
    .long  0xE3002532
    .long  0xA06C0009
    .long  0x624DD317
    .long  0x6331633D
    .long  0x22392228
    .long  0x89066060
    .long  0x20088B16
    .long  0xE3012532
    .long  0xA0130009
    .long  0x624DD311
    .long  0x6331633D
    .long  0x22392228
    .long  0x8903E302
    .long  0x2532A008
    .long  0x0009644D
    .long  0xD20C6221
    .long  0x622D2429
    .long  0x24488900
    .long  0x2572A049
    .short  0x0009
.L_wpool_0600C41E:
    .short  0x009B

    .global DAT_0600c418
DAT_0600c418:
    .short  0x00E6
.L_wpool_0600C422:
    .short  0x0172
    .long  sym_06063E20
    .long  sym_06083255
    .long  sym_0607865E
    .long  0x00008000
    .long  sym_06078656
    .long  sym_06078658
    .long  sym_0607865A
    .long  sym_0607865C
    .long  0x624DD326
    .long  0x6331633D
    .long  0x22392228
    .long  0x8912D324
    .long  0xE2006332
    .long  0x33268B0D
    .long  0x60602008
    .long  0x8903D020
    .long  0x60028802
    .long  0x89026252
    .long  0xA00272FF
    .long  0x625272FE
    .long  0xA01C2522
    .long  0x644DD21B
    .long  0x6221622D
    .long  0x24292448
    .long  0x8914D319
    .long  0xD2166330
    .long  0x62223232
    .long  0x890E6060
    .long  0x20088903
    .long  0xD0126002
    .long  0x20088904
    .long  0x63527301
    .long  0x2532A003
    .long  0x00096252
    .long  0x72022522
    .long  0xD00F6000
    .long  0x600C2008
    .long  0x8B10D00E
    .long  0x6001600D
    .long  0x2008890B
    .long  0xD40CE106
    .long  0xD30C6252
    .long  0x6332332C
    .long  0x33168B01
    .long  0xA001627F
    .long  0xE2042421
    .long  0x000B0009
    .long  sym_0607865E
    .long  sym_06063E20
    .long  sym_06078660
    .long  sym_06078662
    .long  sym_06078635
    .long  sym_0607ED8C
    .long  sym_0605A016
    .long  sym_06063E1C
