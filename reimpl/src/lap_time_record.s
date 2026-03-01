
    .section .text.FUN_0600D92C


    .global lap_time_record
    .type lap_time_record, @function
lap_time_record:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_car_struct_ptr, r14
    mov.l   .L_max_laps, r3
    mov.w   DAT_0600d996, r0
    mov.l @r14, r14
    mov.l @r3, r3
    mov.l @(r0, r14), r2
    add #-0x1, r3
    cmp/hi r3, r2
    bf      .L_set_countdown
    mov #0x3, r2
    mov.l   .L_race_complete_flag, r3
    mov.l r2, @r3
    mov.w   DAT_0600d998, r0
    mov.l @(r0, r14), r2
    add #0x1, r2
    mov.l r2, @(r0, r14)
.L_set_countdown:
    mov #0x28, r3
    mov.l   .L_countdown_timer, r2
    mov.l r3, @r2
    .byte   0xB1, 0xB7
    nop
    mov.l   .L_global_timer, r5
    mov.w   DAT_0600d99a, r0
    mov.l @r5, r4
    mov.l @r5, r3
    mov.l @(r0, r14), r2
    mov.l r3, @(r0, r14)
    sub r2, r4
    mov.l @(r0, r14), r3
    mov.l   .L_prev_lap_store, r2
    add #-0xC, r0
    mov.l r3, @r2
    mov.l r4, @(r0, r14)
    add #-0x4, r0
    mov.l   .L_lap_times_array, r2
    mov.l @(r0, r14), r3
    add #0x24, r0
    add #-0x1, r3
    shll2 r3
    add r2, r3
    mov.l r4, @r3
    mov.l @(r0, r14), r5
    cmp/ge r5, r4
    bf      .L_update_best
    tst r5, r5
    bf      .L_return
.L_update_best:
    mov.w   .L_off_best_lap, r0
    mov.l r4, @(r0, r14)
.L_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600d996
DAT_0600d996:
    .2byte  0x021C                        /* car offset: current lap counter */

    .global DAT_0600d998
DAT_0600d998:
    .2byte  0x0230                        /* car offset: completed laps counter */

    .global DAT_0600d99a
DAT_0600d99a:
    .2byte  0x022C                        /* car offset: lap start timestamp */
.L_off_best_lap:
    .2byte  0x0240                        /* car offset: best lap time */
    .2byte  0xFFFF                       /* alignment padding */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* pointer to current car struct */
.L_max_laps:
    .4byte  sym_06063F28               /* maximum lap count for current race */
.L_race_complete_flag:
    .4byte  sym_0607EBF4               /* race complete flag (3 = finished) */
.L_countdown_timer:
    .4byte  sym_0607EAC0               /* countdown timer (set to 40 on lap complete) */
.L_global_timer:
    .4byte  sym_060786B0               /* global race timer */
.L_prev_lap_store:
    .4byte  sym_060786A4               /* external lap time storage */
.L_lap_times_array:
    .4byte  sym_0607EBF8               /* per-lap time array (4 bytes per lap) */
