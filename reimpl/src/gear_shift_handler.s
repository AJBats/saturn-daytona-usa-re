/* VERIFIED: called every physics frame during racing (part of player_physics_main pipeline)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   117 calls during LEFT (baseline 39, +78) — same delta as player_physics_main
 * Date: 2026-02-28
 */

   .section .text.FUN_06008318


   .global gear_shift_handler
   .type gear_shift_handler, @function
gear_shift_handler:
    sts.l pr, @-r15
    mov.l   .L_car_struct_ptr, r4
    mov.w   .L_off_shift_timer, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_check_new_shift
    mov.l @r4, r3
    mov.w   .L_off_shift_timer, r0
    mov.l @(r0, r3), r2
    add #-0x1, r2
    mov.l r2, @(r0, r3)
    mov.l @r4, r5
    mov.l   .L_gear_ratio_table, r3
    mov.l @r4, r2
    mov.l @(r0, r5), r5
    mov r2, r1
    shll r5
    mov.w   DAT_0600835a, r0
    add r3, r5
    mov.l @(r0, r1), r3
    cmp/pl r3
    bf/s    .L_negate_ratio
    mov.w @r5, r5
    bra     .L_store_gear_value
    exts.w r5, r3
.L_negate_ratio:
    exts.w r5, r1
    neg r1, r3
.L_store_gear_value:
    mov.w   .L_off_gear_interp, r0
    mov.l r3, @(r0, r2)
    bra     .L_exit_update_display
    nop
.L_off_shift_timer:
    .2byte  0x00B8

    .global DAT_0600835a
DAT_0600835a:
    .2byte  0x01DC
    .4byte  0x03010201
.L_off_gear_interp:
    .2byte  0x01D8
    .2byte  0xFFFF
    .4byte  0xAE111BFF
    .4byte  sound_cmd_dispatch
    .4byte  sym_06034F78
.L_car_struct_ptr:
    .4byte  sym_0607E940
.L_gear_ratio_table:
    .4byte  sym_060453CC
.L_check_new_shift:
    mov.l   .L_rpm_value, r2
    mov.w   .L_rpm_threshold, r3
    mov.l @r2, r2
    cmp/gt r3, r2
    bf      .L_exit_update_display
    mov.l   .L_car_struct_ptr_2, r3
    mov.w   DAT_060083fc, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_exit_update_display
    mov #0x28, r6
    mov.l @r4, r2
    mov.l   .L_shift_car_ptr, r7
    mov r2, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt/s    .L_check_shift_up
    mov #0x20, r5
    mov.l @r4, r3
    mov.w   .L_off_shift_timer_2, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #-0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    bra     .L_exit_update_display
    mov.w r6, @(r0, r2)
.L_check_shift_up:
    mov.l @r4, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_exit_update_display
    mov.l @r4, r3
    mov.w   .L_off_shift_timer_2, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    mov.w r6, @(r0, r2)
.L_exit_update_display:
    mov #0x0, r5
    mov.l @r4, r2
    mov.w   .L_gear_mode_a, r1
    mov.l   .L_fn_gear_helper, r3
    jsr @r3
    mov r5, r0
    mov.l @r4, r2
    mov.w   .L_gear_mode_b, r1
    mov.l   .L_fn_gear_helper, r3
    jsr @r3
    mov r5, r0
    lds.l @r15+, pr
    rts
    nop
.L_rpm_threshold:
    .2byte  0x0258

    .global DAT_060083fc
DAT_060083fc:
    .2byte  0x00BC
.L_off_shift_timer_2:
    .2byte  0x00B8

    .global DAT_06008400
DAT_06008400:
    .2byte  0x01DC

    .global DAT_06008402
DAT_06008402:
    .2byte  0x00D4
.L_gear_mode_a:
    .2byte  0x0301
.L_gear_mode_b:
    .2byte  0x0201
.L_rpm_value:
    .4byte  sym_0607EBD0
.L_car_struct_ptr_2:
    .4byte  sym_0607E940
.L_shift_car_ptr:
    .4byte  sym_0607EBE0
.L_fn_gear_helper:
    .4byte  sym_06034F78
