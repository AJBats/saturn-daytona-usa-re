
    .section .text.FUN_0600E7C8


    .global per_frame_race_update
    .type per_frame_race_update, @function
per_frame_race_update:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15

    mov.l   .L_car_struct_ptr, r14
    mov.l   .L_fn_gear_shift, r3
    jsr @r3
    mov.l @r14, r14
    mov.l   .L_fn_engine_force, r3
    jsr @r3
    nop
    mov.l   .L_fn_friction, r3
    jsr @r3
    nop
    mov.l   .L_fn_accel_response, r3
    jsr @r3
    nop
    mov.l   .L_fn_demo_collision, r3
    jsr @r3
    nop

    mov.l   .L_steering_mode_byte, r0
    bra     .L_steer_mode_dispatch
    mov.b @r0, r0

.L_steer_mode1_fast:
    mov.l @(40, r14), r4
    mov.w   DAT_0600e86c, r0
    mov.l @(r0, r14), r2
    sub r4, r2
    shll16 r2
    shar r2
    shar r2
    shlr16 r2
    exts.w r2, r2
    add r4, r2
    exts.w r2, r4
    exts.w r4, r5
    mov.l r5, @(48, r14)
    bra     .L_post_steering
    mov.l r5, @(40, r14)

.L_steer_mode2_smooth:
    mov.l @(40, r14), r4
    mov.w   DAT_0600e86c, r0
    mov.l   .L_rounding_half, r3
    mov.l @(r0, r14), r2
    add #-0x54, r0
    sub r4, r2
    add r3, r2
    shll16 r2
    shar r2
    shlr16 r2
    exts.w r2, r2
    add r4, r2
    exts.w r2, r4
    exts.w r4, r5
    mov.l r5, @(48, r14)
    mov.l r5, @(40, r14)

    mov.l @(r0, r14), r0
    tst r0, r0
    bt      .L_post_steering
    mov.w   DAT_0600e86e, r0
    mov.l @(r0, r14), r3
    add #-0x1, r3
    mov.l r3, @(r0, r14)
    tst r3, r3
    bf      .L_surface_timer_done

    mov.w   DAT_0600e870, r0
    mov.l @(r0, r14), r4
    mov r4, r3
    shll2 r4
    shll r4
    shll2 r3
    shll2 r3
    add r3, r4
    add #-0x4, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   .L_off_surface_type, r0
    mov.l r3, @(r0, r14)
    mov.w   .L_surface_reset_val, r3
    add #0xC, r0
    mov.l r3, @(r0, r14)

.L_surface_timer_done:
    bra     .L_post_steering
    nop

    .global DAT_0600e86c
DAT_0600e86c:
    .2byte  0x025C                        /* car offset: target steering angle */

    .global DAT_0600e86e
DAT_0600e86e:
    .2byte  0x0208                        /* car offset: surface change timer */

    .global DAT_0600e870
DAT_0600e870:
    .2byte  0x01E4                        /* car offset: surface slot index */
.L_off_surface_type:
    .2byte  0x01F8                        /* car offset: surface type */
.L_surface_reset_val:
    .2byte  0x0400                        /* surface timer reset constant */
    .2byte  0xFFFF
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* pointer to current car struct */
.L_fn_gear_shift:
    .4byte  gear_shift_handler         /* step 1: manual gear shift */
.L_fn_engine_force:
    .4byte  sym_06008640               /* step 2: engine torque/force */
.L_fn_friction:
    .4byte  friction_stub              /* step 3: surface friction */
.L_fn_accel_response:
    .4byte  accel_response             /* step 4: acceleration curve */
.L_fn_demo_collision:
    .4byte  sym_0602D88E               /* step 5: demo/attract collision handler */
.L_steering_mode_byte:
    .4byte  sym_06083261               /* steering interpolation mode (1=fast, 2=smooth) */
.L_rounding_half:
    .4byte  0x00008000                  /* 0.5 rounding bias for mode 2 interpolation */

.L_steer_mode_dispatch:
    cmp/eq #0x1, r0
    bt      .L_steer_mode1_fast
    cmp/eq #0x2, r0
    bt      .L_steer_mode2_smooth

.L_post_steering:
    .byte   0xD3, 0x21    /* mov.l .L_pool_0600E928, r3 — track_segment_advance (cross-TU) */
    jsr @r3
    nop

    .byte   0x90, 0x3A    /* mov.w .L_wpool_0600E91E, r0 — offset +0x228 (speed, cross-TU) */
    .byte   0xD3, 0x20    /* mov.l .L_pool_0600E92C, r3 — speed_coeff ptr (cross-TU) */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)

    add #-0x10, r0
    mov.l @(r0, r14), r4
    add #-0x4, r0
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    .byte   0x90, 0x23    /* mov.w .L_wpool_0600E920, r0 — +0x1F8 (cross-TU) */
    mov.l r3, @(r0, r14)

    .byte   0xD3, 0x15    /* mov.l .L_pool_0600E930, r3 — game_state_flags ptr (cross-TU) */
    .byte   0xD2, 0x15    /* mov.l .L_pool_0600E934, r2 — 0x00200000 bitmask (cross-TU) */
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_epilogue

    .byte   0xD5, 0x14    /* mov.l .L_pool_0600E938, r5 — display_speed_coeff (cross-TU) */
    .byte   0xD3, 0x14    /* mov.l .L_pool_0600E93C, r3 — fpmul function ptr (cross-TU) */
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    .byte   0x91, 0x16    /* mov.w .L_wpool_0600E922, r1 — +0x1F8 display speed A (cross-TU) */
    add r14, r1
    mov.l r0, @r1
    .byte   0x91, 0x14    /* mov.w .L_wpool_0600E924, r1 — +0xE0 display speed B (cross-TU) */
    add r14, r1
    mov.l r0, @r1

.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
