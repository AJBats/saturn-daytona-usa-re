
    .section .text.FUN_0600C286


    .global race_utility_fn
    .type race_utility_fn, @function
race_utility_fn:
    sts.l pr, @-r15
    .byte   0xD3, 0x14    /* mov.l .L_fn_render_finalize, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x14    /* mov.l .L_fn_camera_track_setup, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x13    /* mov.l .L_ptr_render_state_byte, r4 */
    mov.b @r4, r2
    tst r2, r2
    bf      .L_check_state_1
    .byte   0xD3, 0x12    /* mov.l .L_fn_scene_path_b, r3 */
    jsr @r3
    nop
    bra     .L_write_scroll_exit
    nop
    .2byte  0xFE11                       /* alignment / padding */
    .4byte  0x0080FFFF                   /* (unreachable pool) bitmask constant */
    .4byte  sym_0608A52C                 /* (unreachable pool) obj state secondary */
    .4byte  sym_06089EDC                 /* (unreachable pool) obj state primary */
    .4byte  memcpy_long_idx              /* (unreachable pool) fn ptr: memcpy_long_idx */
    .4byte  physics_calc_dispatch        /* (unreachable pool) fn ptr: physics_calc_dispatch */
    .4byte  race_utility_fn              /* (unreachable pool) fn ptr: self */
    .4byte  sym_06063574                 /* (unreachable pool) secondary SH-2 callback ptr */
    .4byte  0x0000FFFF                   /* (unreachable pool) low 16-bit mask */
    .4byte  0x21000000                   /* (unreachable pool) VDP2 VRAM base (cache-through) */
    .4byte  frame_dispatch               /* (unreachable pool) fn ptr: frame_dispatch */
    .4byte  scene_post_render            /* (unreachable pool) fn ptr: scene_post_render */
    .4byte  replay_playback_engine       /* (unreachable pool) fn ptr: replay_playback_engine */
    .4byte  sym_06059FF8                 /* (unreachable pool) timing variable */
.L_fn_render_finalize:
    .4byte  sym_0603C000                 /* pool: &render_finalize function */
.L_fn_camera_track_setup:
    .4byte  camera_track_setup           /* pool: &camera_track_setup function */
.L_ptr_render_state_byte:
    .4byte  sym_06082A26                 /* pool: &render_state_byte */
.L_fn_scene_path_b:
    .4byte  scene_path_b                 /* pool: &scene_path_b function */
.L_check_state_1:
    mov.b @r4, r0
    cmp/eq #0x1, r0
    bf      .L_write_scroll_exit
    .byte   0xD3, 0x21    /* mov.l .L_fn_scene_path_a, r3 */
    jsr @r3
    nop
.L_write_scroll_exit:
    .byte   0xD2, 0x20    /* mov.l .L_mask_low16, r2 */
    .byte   0xD3, 0x21    /* mov.l .L_vdp2_scroll_reg, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3

    .global sym_0600C302
sym_0600C302:
    mov #0x68, r0
    .byte   0xD4, 0x1F    /* mov.l .L_ptr_car_array_base, r4 */
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
    bf      .L_check_timer_174
    mov.w   DAT_0600c36a, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_check_timer_174:
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r3
    cmp/pl r3
    bf      .L_check_zone_timer
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_check_zone_timer:
    mov.w   DAT_0600c36e, r0
    mov.w @(r0, r4), r0
    tst r0, r0
    bt      .L_zone_timer_zero
    rts
    nop
.L_zone_timer_zero:
    mov #0x12, r7
    mov #0x68, r0
    mov.w   DAT_0600c370, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bf/s    .L_check_ext_value
    mov #0x0, r6
    mov.w   DAT_0600c36a, r0
    mov.w r7, @(r0, r4)
    add #0x2, r0
    rts
    mov.w r6, @(r0, r4)
.L_check_ext_value:
    mov.w   DAT_0600c372, r0
    mov.w   .L_wpool_0600C37C, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bt      .L_ext_above_threshold
    rts
    nop

    .global DAT_0600c36a
DAT_0600c36a:
    .2byte  0x0172

    .global DAT_0600c36c
DAT_0600c36c:
    .2byte  0x0174

    .global DAT_0600c36e
DAT_0600c36e:
    .2byte  0x00DC

    .global DAT_0600c370
DAT_0600c370:
    .2byte  0x00E6

    .global DAT_0600c372
DAT_0600c372:
    .2byte  0x0084
.L_wpool_0600C37C:
    .2byte  0x008C
    .2byte  0xFFFF
.L_fn_scene_path_a:
    .4byte  scene_path_a
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_vdp2_scroll_reg:
    .4byte  0x21800000
.L_ptr_car_array_base:
    .4byte  sym_0607E944
.L_ext_above_threshold:
    mov #0x68, r0
    mov.w   .L_wpool_0600C41E, r3
    mov.l @(r0, r4), r5
    cmp/gt r3, r5
    bf      .L_speed_range_exit
    mov.w   DAT_0600c418, r3
    cmp/ge r3, r5
    bt      .L_speed_range_exit
    exts.w r6, r6
    mov.w   .L_wpool_0600C422, r0
    mov.w r6, @(r0, r4)
    exts.w r7, r7
    add #0x2, r0
    mov.w r7, @(r0, r4)
.L_speed_range_exit:
    rts
    nop
    .4byte  0xD51CD61D
    .4byte  0xD31DD21E
    .4byte  0x6331633D
    .4byte  0x33208F41
    .4byte  0xE703624D
    .4byte  0xD31B6331
    .4byte  0x633D2239
    .4byte  0x22288903
    .4byte  0xE3002532
    .4byte  0xA06C0009
    .4byte  0x624DD317
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x89066060
    .4byte  0x20088B16
    .4byte  0xE3012532
    .4byte  0xA0130009
    .4byte  0x624DD311
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x8903E302
    .4byte  0x2532A008
    .4byte  0x0009644D
    .4byte  0xD20C6221
    .4byte  0x622D2429
    .4byte  0x24488900
    .4byte  0x2572A049
    .2byte  0x0009
.L_wpool_0600C41E:
    .2byte  0x009B

    .global DAT_0600c418
DAT_0600c418:
    .2byte  0x00E6
.L_wpool_0600C422:
    .2byte  0x0172
    .4byte  sym_06063E20
    .4byte  sym_06083255
    .4byte  sym_0607865E
    .4byte  0x00008000
    .4byte  sym_06078656
    .4byte  sym_06078658
    .4byte  sym_0607865A
    .4byte  sym_0607865C
    .4byte  0x624DD326
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x8912D324
    .4byte  0xE2006332
    .4byte  0x33268B0D
    .4byte  0x60602008
    .4byte  0x8903D020
    .4byte  0x60028802
    .4byte  0x89026252
    .4byte  0xA00272FF
    .4byte  0x625272FE
    .4byte  0xA01C2522
    .4byte  0x644DD21B
    .4byte  0x6221622D
    .4byte  0x24292448
    .4byte  0x8914D319
    .4byte  0xD2166330
    .4byte  0x62223232
    .4byte  0x890E6060
    .4byte  0x20088903
    .4byte  0xD0126002
    .4byte  0x20088904
    .4byte  0x63527301
    .4byte  0x2532A003
    .4byte  0x00096252
    .4byte  0x72022522
    .4byte  0xD00F6000
    .4byte  0x600C2008
    .4byte  0x8B10D00E
    .4byte  0x6001600D
    .4byte  0x2008890B
    .4byte  0xD40CE106
    .4byte  0xD30C6252
    .4byte  0x6332332C
    .4byte  0x33168B01
    .4byte  0xA001627F
    .4byte  0xE2042421
    .4byte  0x000B0009
    .4byte  sym_0607865E
    .4byte  sym_06063E20
    .4byte  sym_06078660
    .4byte  sym_06078662
    .4byte  sym_06078635
    .4byte  sym_0607ED8C
    .4byte  sym_0605A016
    .4byte  sym_06063E1C
