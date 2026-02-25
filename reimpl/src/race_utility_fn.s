/* race_utility_fn -- Race frame utility & end-sequence handler
 * Translation unit: 0x0600C286 - 0x0600C4F8
 *
 * Two entry points:
 *
 * 1. race_utility_fn (0x0600C286):
 *    Per-frame race utility called during race state updates.
 *    Calls render_finalize (sym_0603C000) and camera_track_setup, then
 *    dispatches to scene_path_a or scene_path_b depending on the
 *    render_state_byte (sym_06082A26). Finishes by writing the low-16
 *    mask (0x0000FFFF) to the VDP2 scroll register (0x21800000).
 *
 * 2. sym_0600C302 (race end handler):
 *    Called from state_race_main when race_end_flag is set.
 *    Operates on the player car struct (via sym_0607E944):
 *      - Reads car heading at +0x68, expands by <<5, stores to +0x7C
 *      - Decrements 18-frame countdown timers at +0x172 and +0x174
 *      - Checks zone_timer (+0xDC): if nonzero, returns early
 *      - Checks speed (+0x68) vs threshold 0xE6: if >= threshold,
 *        resets countdown timers to 0x12 and 0x00
 *      - Checks ext_check (+0x84) vs 0x8C: conditionally stores
 *        timer values for speed-range cars
 *
 * Calls: sym_0603C000 (render_finalize), camera_track_setup,
 *        scene_path_a, scene_path_b
 *
 * Car struct offsets used:
 *   +0x68 = CAR_HEADING_EXP (heading, expanded <<5)
 *   +0x7C = heading expanded store
 *   +0x78 = heading expanded store (duplicate)
 *   +0x84 = CAR_EXT_CHECK (extended check value)
 *   +0xDC = CAR_ZONE_TIMER (zone countdown timer)
 *   +0x172 = CAR_TIMER_172 (18-frame countdown timer 1)
 *   +0x174 = CAR_TIMER_174 (18-frame countdown timer 2)
 */

    .section .text.FUN_0600C286


    .global race_utility_fn
    .type race_utility_fn, @function
race_utility_fn:
    sts.l pr, @-r15                      ! save return address
    .byte   0xD3, 0x14    /* mov.l .L_fn_render_finalize, r3 */
    jsr @r3                              ! call render_finalize (sym_0603C000)
    nop                                  ! delay slot
    .byte   0xD3, 0x14    /* mov.l .L_fn_camera_track_setup, r3 */
    jsr @r3                              ! call camera_track_setup
    nop                                  ! delay slot
    .byte   0xD4, 0x13    /* mov.l .L_ptr_render_state_byte, r4 */
    mov.b @r4, r2                        ! r2 = render_state_byte (sym_06082A26)
    tst r2, r2                           ! test if render state == 0
    bf      .L_check_state_1             ! nonzero: check if state == 1
    .byte   0xD3, 0x12    /* mov.l .L_fn_scene_path_b, r3 */
    jsr @r3                              ! state==0: call scene_path_b
    nop                                  ! delay slot
    bra     .L_write_scroll_exit         ! skip to VDP2 scroll write
    nop                                  ! delay slot
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
    mov.b @r4, r0                        ! r0 = render_state_byte (re-read)
    cmp/eq #0x1, r0                      ! state == 1?
    bf      .L_write_scroll_exit         ! no: skip scene_path_a, go to exit
    .byte   0xD3, 0x21    /* mov.l .L_fn_scene_path_a, r3 */
    jsr @r3                              ! state==1: call scene_path_a
    nop                                  ! delay slot
.L_write_scroll_exit:
    .byte   0xD2, 0x20    /* mov.l .L_mask_low16, r2 */
    .byte   0xD3, 0x21    /* mov.l .L_vdp2_scroll_reg, r3 */
    lds.l @r15+, pr                      ! restore return address
    rts                                  ! return
    mov.w r2, @r3                        ! (delay slot) VDP2_scroll_reg = 0xFFFF

    .global sym_0600C302
sym_0600C302:                            ! --- race end sequence handler ---
    mov #0x68, r0                        ! r0 = 0x68 (CAR_HEADING_EXP offset)
    .byte   0xD4, 0x1F    /* mov.l .L_ptr_car_array_base, r4 */
    mov.l @r4, r4                        ! r4 = *car_array_base (car struct ptr)
    mov.l @(r0, r4), r3                  ! r3 = car[+0x68] (heading value)
    add #0x7C, r0                        ! r0 = 0x7C (heading expanded store B)
    shll2 r3                             ! r3 <<= 2
    shll2 r3                             ! r3 <<= 2 (total <<4)
    shll r3                              ! r3 <<= 1 (total <<5)
    mov.l r3, @(r0, r4)                  ! car[+0x7C] = heading << 5
    add #-0x4, r0                        ! r0 = 0x78 (heading expanded store A)
    mov.l r3, @(r0, r4)                  ! car[+0x78] = heading << 5 (duplicate)
    mov.w   DAT_0600c36a, r0             ! r0 = 0x0172 (CAR_TIMER_172 offset)
    mov.w @(r0, r4), r3                  ! r3 = car[+0x172] (countdown timer 1)
    cmp/pl r3                            ! timer_172 > 0?
    bf      .L_check_timer_174           ! no: skip decrement
    mov.w   DAT_0600c36a, r0             ! r0 = 0x0172 (reload offset)
    mov.w @(r0, r4), r2                  ! r2 = car[+0x172]
    add #-0x1, r2                        ! r2-- (decrement timer)
    mov.w r2, @(r0, r4)                  ! car[+0x172] = decremented value
.L_check_timer_174:
    mov.w   DAT_0600c36c, r0             ! r0 = 0x0174 (CAR_TIMER_174 offset)
    mov.w @(r0, r4), r3                  ! r3 = car[+0x174] (countdown timer 2)
    cmp/pl r3                            ! timer_174 > 0?
    bf      .L_check_zone_timer          ! no: skip decrement
    mov.w   DAT_0600c36c, r0             ! r0 = 0x0174 (reload offset)
    mov.w @(r0, r4), r2                  ! r2 = car[+0x174]
    add #-0x1, r2                        ! r2-- (decrement timer)
    mov.w r2, @(r0, r4)                  ! car[+0x174] = decremented value
.L_check_zone_timer:
    mov.w   DAT_0600c36e, r0             ! r0 = 0x00DC (CAR_ZONE_TIMER offset)
    mov.w @(r0, r4), r0                  ! r0 = car[+0xDC] (zone timer)
    tst r0, r0                           ! zone_timer == 0?
    bt      .L_zone_timer_zero           ! yes: proceed to speed check
    rts                                  ! no: early return (zone active)
    nop                                  ! delay slot
.L_zone_timer_zero:
    mov #0x12, r7                        ! r7 = 0x12 (18 = timer reset value)
    mov #0x68, r0                        ! r0 = 0x68 (CAR_HEADING_EXP offset)
    mov.w   DAT_0600c370, r2             ! r2 = 0x00E6 (speed threshold)
    mov.l @(r0, r4), r3                  ! r3 = car[+0x68] (heading / speed value)
    cmp/ge r2, r3                        ! speed >= 0xE6?
    bf/s    .L_check_ext_value           ! no: check ext_check instead
    mov #0x0, r6                         ! (delay slot) r6 = 0 (timer clear value)
    mov.w   DAT_0600c36a, r0             ! r0 = 0x0172 (CAR_TIMER_172 offset)
    mov.w r7, @(r0, r4)                  ! car[+0x172] = 0x12 (reset timer 1 to 18)
    add #0x2, r0                         ! r0 = 0x0174 (CAR_TIMER_174 offset)
    rts                                  ! return
    mov.w r6, @(r0, r4)                  ! (delay slot) car[+0x174] = 0 (clear timer 2)
.L_check_ext_value:
    mov.w   DAT_0600c372, r0
    mov.w   .L_wpool_ext_threshold, r2
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
.L_wpool_ext_threshold:
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
    mov.w   .L_wpool_speed_low, r3
    mov.l @(r0, r4), r5
    cmp/gt r3, r5
    bf      .L_speed_range_exit
    mov.w   DAT_0600c418, r3
    cmp/ge r3, r5
    bt      .L_speed_range_exit
    exts.w r6, r6
    mov.w   .L_wpool_timer_172_off, r0
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
.L_wpool_speed_low:
    .2byte  0x009B

    .global DAT_0600c418
DAT_0600c418:
    .2byte  0x00E6
.L_wpool_timer_172_off:
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
