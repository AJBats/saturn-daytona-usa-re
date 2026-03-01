
    .section .text.FUN_0602C8E2


    .global vdp1_color_setup
    .type vdp1_color_setup, @function
vdp1_color_setup:
    sts.l pr, @-r15
    mov #0x0, r12
    mov #0x0, r6
    mov.w   .L_off_obj_data, r1
    mov.w   .L_off_lateral_vel, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    xor r3, r4
    cmp/pz r4
    bf      .L_drift_mag_done
    mov r3, r6
    cmp/pz r6
    bt      .L_drift_mag_done
    neg r6, r6
.L_drift_mag_done:
    mov.l @(8, r0), r1
    mov #0x46, r7
    cmp/ge r1, r7
    bt      .L_skip_spin_detect
    mov.w   .L_off_angular_vel_a, r2
    mov.w   .L_off_angular_vel_b, r3
    mov.l @(r0, r2), r4
    mov.l @(r0, r3), r5
    xor r4, r5
    cmp/pz r5
    bt      .L_skip_spin_detect
    mov.w   .L_off_yaw_deflect, r2
    mov.w   .L_yaw_threshold, r4
    mov.l @(r0, r2), r3
    cmp/ge r4, r3
    bt      .L_set_spin_mode
    neg r4, r4
    cmp/ge r3, r4
    bt      .L_skip_spin_detect
.L_set_spin_mode:
    mov.w   .L_off_render_mode, r2
    mov #0xA, r3
    mov.w r3, @(r0, r2)
.L_skip_spin_detect:
    mov #0x64, r2
    mov.w   .L_drift_threshold, r3
    cmp/gt r1, r2
    bt      .L_no_color_boost
    cmp/gt r6, r3
    bt      .L_no_color_boost
    mov #0x1, r12
.L_no_color_boost:
    mov.w   .L_off_mode_timer, r3
    mov.w @(r0, r3), r2
    tst r2, r2
    bt      .L_skip_secondary_mode
    mov.w   .L_off_secondary_mode, r3
    mov #0x10, r2
    mov.w r2, @(r0, r3)
.L_skip_secondary_mode:
    mov.l @(28, r0), r3
    mov.w   .L_vert_threshold, r2
    cmp/ge r3, r2
    bt      .L_skip_airborne_mode
    mov.w   .L_off_activate_a, r2
    mov #0x4, r3
    mov.l @(r0, r2), r1
    add #0x4, r2
    tst r1, r3
    bt      .L_check_flags_b
    mov.w   .L_off_obj_data, r3
    mov.l @(r0, r3), r1
    cmp/pz r1
    bf      .L_set_airborne_mode
.L_check_flags_b:
    mov #0x4, r3
    mov.l @(r0, r2), r1
    tst r1, r3
    bt      .L_skip_airborne_mode
    mov.w   .L_off_obj_data, r3
    mov.l @(r0, r3), r1
    cmp/pz r1
    bf      .L_skip_airborne_mode
.L_set_airborne_mode:
    mov.w   .L_off_render_mode, r3
    mov #0x14, r2
    mov.w r2, @(r0, r3)
.L_skip_airborne_mode:
    mov.w   .L_off_color_timer, r8
    mov.w @(r0, r8), r2
    tst r12, r12
    bt      .L_no_boost_inc
    add #0x1, r2
.L_no_boost_inc:
    cmp/pz r2
    bf      .L_phase2_timers
    add #-0x1, r2
    mov.w r2, @(r0, r8)
    mov.w   .L_off_intensity, r3
    mov.w   .L_off_angular_vel_b, r2
    mov.l @(r0, r3), r6
    mov.w   .L_off_decel_coeff, r1
    dmuls.l r6, r6
    mov.l @(r0, r2), r5
    mov.l @(r0, r1), r4
    sts mach, r6
    dmuls.l r5, r5
    sts mach, r0
    dmuls.l r4, r4
    .byte   0xDD, 0x12    /* mov.l .L_fn_hw_divide, r13 */
    sts mach, r1
    jsr @r13
    add r6, r0
    shll16 r0
    mov r0, r3
    mov.w   .L_off_decel_coeff, r1
    mov r14, r0
    mov.l @(r0, r1), r5
    dmuls.l r3, r5
    mov #0x0, r4
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    cmp/pz r3
    bt      .L_color_positive
    mov r4, r3
.L_color_positive:
    cmp/gt r4, r5
    bt      .L_clamp_upper
    mov r4, r5
    bra     .L_store_color
    nop

    .global DAT_0602c9cc
.L_off_obj_data:
DAT_0602c9cc:
    .2byte  0x0040

    .global DAT_0602c9ce
.L_off_lateral_vel:
DAT_0602c9ce:
    .2byte  0x005C

    .global DAT_0602c9d0
.L_off_angular_vel_a:
DAT_0602c9d0:
    .2byte  0x0060

    .global DAT_0602c9d2
.L_off_angular_vel_b:
DAT_0602c9d2:
    .2byte  0x0064

    .global DAT_0602c9d4
.L_off_yaw_deflect:
DAT_0602c9d4:
    .2byte  0x00D0

    .global DAT_0602c9d6
.L_yaw_threshold:
DAT_0602c9d6:
    .2byte  0x1000

    .global DAT_0602c9d8
.L_off_render_mode:
DAT_0602c9d8:
    .2byte  0x016C
.L_drift_threshold:
    .2byte  0x0E00

    .global DAT_0602c9dc
.L_off_mode_timer:
DAT_0602c9dc:
    .2byte  0x00D4

    .global DAT_0602c9de
.L_off_secondary_mode:
DAT_0602c9de:
    .2byte  0x0170
.L_vert_threshold:
    .2byte  0x0500

    .global DAT_0602c9e2
.L_off_activate_a:
DAT_0602c9e2:
    .2byte  0x0128
.L_off_color_timer:
    .2byte  0x016A

    .global DAT_0602c9e6
.L_off_intensity:
DAT_0602c9e6:
    .2byte  0x0144
.L_off_decel_coeff:
    .2byte  0x011C
    .2byte  0x0000
.L_fn_hw_divide:
    .4byte  sym_0602ECCC
.L_clamp_upper:
    cmp/ge r5, r3
    bt      .L_store_color
    mov r3, r5
.L_store_color:
    mov.l r5, @(r0, r1)
.L_phase2_timers:
    add #0x2, r8
    mov.w @(r0, r8), r2
    cmp/pz r2
    bf      .L_timer_b
    add #-0x1, r2
    mov.w r2, @(r0, r8)
    mov.w   .L_off_draw_count, r3
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_timer_b:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_timer_c
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_off_intensity_b, r2
    .byte   0xD4, 0x18    /* mov.l .L_decay_factor, r4 */
    mov.l @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w r4, @(r0, r2)
.L_timer_c:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_timer_d
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_off_intensity_b, r2
    .byte   0xD3, 0x12    /* mov.l .L_full_bright, r3 */
    mov.l r3, @(r0, r2)
.L_timer_d:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_timer_e
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_off_intensity_b, r1
    mov.l @(r0, r1), r2
    shar r2
    mov.l r2, @(r0, r1)
    mov.w   .L_off_force_aux, r5
    mov #0x0, r3
    mov.l r3, @(r0, r5)
.L_timer_e:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_return
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_off_decel_coeff_b, r1
    mov.l @(r0, r1), r3
    cmp/pz r3
    bf      .L_return
    neg r3, r3
    mov.w   .L_off_force_aux, r1
    mov.l r3, @(r0, r1)
.L_return:
    lds.l @r15+, pr
    rts
    mov #0x0, r1

    .global DAT_0602ca72
.L_off_draw_count:
DAT_0602ca72:
    .2byte  0x0168

    .global DAT_0602ca74
.L_off_intensity_b:
DAT_0602ca74:
    .2byte  0x0144

    .global DAT_0602ca76
.L_off_force_aux:
DAT_0602ca76:
    .2byte  0x00F4
.L_off_decel_coeff_b:
    .2byte  0x011C
    .2byte  0x0000
.L_decay_factor:
    .4byte  0x00011999
.L_full_bright:
    .4byte  0x09D80000
