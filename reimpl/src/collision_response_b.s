
    .section .text.FUN_0602F270


    .global collision_response_b
    .type collision_response_b, @function
collision_response_b:
    sts.l pr, @-r15
    mov.w   .L_off_gear_rotation, r1
    mov.l @(r0, r1), r3
    tst r3, r3
    bt      .L_check_zone
    cmp/pz r3
    bf      .L_state_negative
    add #-0x1, r3
    bra     .L_check_zone
    mov.l r3, @(r0, r1)
.L_off_gear_rotation:
    .2byte  0x00D8                   /* car+0xD8: gear_rotation state */
.L_state_negative:
    add #0x1, r3
    mov.l r3, @(r0, r1)
    mov.w   .L_off_vel_rate, r2
    mov.w   .L_off_drive_speed_a, r1
    mov.l @(r0, r2), r3
    mov.l r3, @(r0, r1)
    mov.w   .L_off_force_aux, r4
    sub r4, r3
    mov.l r3, @(r0, r2)
.L_check_zone:
    mov.w   .L_off_zone_timer, r1
    mov.w @(r0, r1), r2
    mov.w   .L_off_zone_target, r5
    mov.w @(r0, r5), r6
    cmp/eq r2, r6
    bt      .L_clamp_and_store
    cmp/gt r2, r6
    bt      .L_target_higher
    bra     .L_target_lower
    nop
.L_off_vel_rate:
    .2byte  0x00C4                   /* car+0xC4: velocity rate */
.L_off_drive_speed_a:
    .2byte  0x00E0                   /* car+0xE0: drive wheel speed */
.L_off_force_aux:
    .2byte  0x00FA                   /* car+0xFA: force auxiliary */
.L_off_zone_timer:
    .2byte  0x00DC                   /* car+0xDC: zone timer (16-bit) */
.L_off_zone_target:
    .2byte  0x00DE                   /* car+0xDE: zone target (16-bit) */
.L_target_higher:
    mov #0x3, r3
    cmp/eq r3, r2
    bt      .L_clamp_and_store
    mov.w r6, @(r0, r1)
    mov.w   .L_off_drive_speed_b, r3
    mov.l @(r0, r3), r4
    shll16 r4
    mov r2, r5
    mov.l   .L_gear_ratio_table, r8
    mov r8, r9
    shll2 r5
    add r5, r8
    mov.l @r8, r7
    mov r6, r5
    dmuls.l r7, r4
    shll2 r5
    add r5, r9
    sts mach, r7
    sts macl, r4
    mov.l @r9, r5
    xtrct r7, r4
    mov.l   .L_fn_fpdiv_a, r0
    jsr @r0
    nop
    mov.w   .L_off_drive_speed_b, r3
    shlr16 r0
    mov r0, r4
    mov r14, r0
    mov.l r4, @(r0, r3)
    mov #0x5, r5
    mov.w   .L_off_gear_rotation_b, r1
    bra     .L_clamp_and_store
    mov.l r5, @(r0, r1)
.L_off_drive_speed_b:
    .2byte  0x00E0                   /* car+0xE0: drive_speed (duplicate pool) */
.L_off_gear_rotation_b:
    .2byte  0x00D8                   /* car+0xD8: gear_rotation (duplicate pool) */
.L_gear_ratio_table:
    .4byte  sym_060477BC             /* gear ratio lookup table */
.L_fn_fpdiv_a:
    .4byte  fpdiv_setup              /* 16.16 fixed-point divide */
.L_target_lower:
    tst r2, r2
    bt      .L_clamp_and_store
    mov.w r6, @(r0, r1)
    mov.w   .L_off_drive_speed_c, r3
    mov.l @(r0, r3), r4
    shll16 r4
    mov r2, r5
    mov.l   .L_gear_ratio_table_b, r8
    mov r8, r9
    shll2 r5
    add r5, r8
    mov.l @r8, r7
    mov r6, r5
    dmuls.l r7, r4
    shll2 r5
    add r5, r9
    sts mach, r7
    sts macl, r4
    mov.l @r9, r5
    xtrct r7, r4
    mov.l   .L_fn_fpdiv_b, r0
    jsr @r0
    nop
    mov.w   .L_off_drive_speed_c, r3
    shlr16 r0
    mov r0, r4
    mov r14, r0
    mov.l r4, @(r0, r3)
    mov.w   .L_off_extended_speed, r5
    mov.w   .L_off_vel_rate_c, r1
    add r5, r4
    mov.l r4, @(r0, r1)
    mov #0x5, r4
    neg r4, r4
    mov.w   .L_off_gear_rotation_c, r3
    mov.l r4, @(r0, r3)
.L_clamp_and_store:
    mov.w   .L_max_drive_speed, r3
    mov.w   .L_off_drive_speed_c, r1
    mov.l @(r0, r1), r4
    cmp/gt r4, r3
    bt      .L_compute_delta
    mov #-0x1, r4
    extu.b r4, r4
    mov.w   .L_off_ext_check, r5
    mov.l r3, @(r0, r1)
    mov.l r4, @(r0, r5)
.L_compute_delta:
    mov.w   .L_off_projected_b, r6
    mov.w   .L_off_drag_flag, r2
    mov.l @(r0, r6), r3
    mov.l @(r0, r1), r4
    mov.l @(r0, r2), r5
    add r5, r4
    sub r3, r4
    mov.w   .L_off_zone_timer_b, r1
    mov.l   .L_clamp_limit_table, r7
    mov.w @(r0, r1), r2
    shll2 r2
    shll r2
    add r2, r7
    mov.l @r7, r8
    mov.l @(4, r7), r9
    cmp/gt r8, r4
    bt      .L_check_upper_bound
    mov r8, r4
    bra     .L_apply_delta
    nop
.L_off_drive_speed_c:
    .2byte  0x00E0                   /* car+0xE0: drive_speed (duplicate pool) */
.L_off_extended_speed:
    .2byte  0x04E2                   /* extended speed bias constant */
.L_off_vel_rate_c:
    .2byte  0x00C4                   /* car+0xC4: vel_rate (duplicate pool) */
.L_off_gear_rotation_c:
    .2byte  0x00D8                   /* car+0xD8: gear_rotation (duplicate pool) */
.L_max_drive_speed:
    .2byte  0x2134                   /* maximum drive wheel speed */
.L_off_ext_check:
    .2byte  0x0084                   /* car+0x84: ext_check / overflow flag */
.L_off_projected_b:
    .2byte  0x00E4                   /* car+0xE4: projected value B */
.L_off_drag_flag:
    .2byte  0x00C0                   /* car+0xC0: drag override flag */
.L_off_zone_timer_b:
    .2byte  0x00DC                   /* car+0xDC: zone_timer (duplicate pool) */
    .2byte  0x0000                   /* alignment padding */
.L_gear_ratio_table_b:
    .4byte  sym_060477BC             /* gear ratio table (duplicate pool) */
.L_fn_fpdiv_b:
    .4byte  fpdiv_setup              /* 16.16 fixed-point divide (duplicate pool) */
.L_clamp_limit_table:
    .4byte  sym_0602F3CC             /* collision clamp limit table */
.L_check_upper_bound:
    cmp/ge r4, r9
    bt      .L_apply_delta
    mov r9, r4
.L_apply_delta:
    add r4, r3
    mov #0x0, r8
    mov.w   .L_max_drive_speed_b, r9
    cmp/gt r8, r3
    bt      .L_check_max_clamp
    mov r8, r3
    bra     .L_store_and_return
    nop
.L_max_drive_speed_b:
    .2byte  0x2134                   /* max drive speed (duplicate pool) */
.L_check_max_clamp:
    cmp/ge r3, r9
    bt      .L_store_and_return
    mov r9, r3
.L_store_and_return:
    lds.l @r15+, pr
    rts
    mov.l r3, @(r0, r6)

    .global sym_0602F3CC
sym_0602F3CC:
    .word 0xFFFF
    .word 0xFB50
    .word 0x0000
    .word 0x04B0
    .word 0xFFFF
    .word 0xFDA8
    .word 0x0000
    .word 0x0258
    .word 0xFFFF
    .word 0xFED4
    .word 0x0000
    mov.b @(r0, r2), r1
    .word 0xFFFF
    .word 0xFED4
    .word 0x0000
    mov.b @(r0, r2), r1

    .global sym_0602F3EC
sym_0602F3EC:
    mov.l @(12, r0), r2
    mov.l   .L_damage_scale_factor, r3
    dmuls.l r2, r3
    mov.l   .L_max_raw_damage, r4
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    shlr16 r2
    exts.w r2, r2
    mov #0x0, r3
    cmp/gt r3, r2
    bt      .L_check_max_raw
    mov r3, r2
    bra     .L_store_and_attenuate
    nop
    .2byte  0x0000                   /* alignment padding */
.L_damage_scale_factor:
    .4byte  0x00480000               /* damage scale: 72.0 in 16.16 */
.L_max_raw_damage:
    .4byte  0x00000158               /* max raw damage = 344 */
.L_check_max_raw:
    cmp/gt r2, r4
    bt      .L_store_and_attenuate
    mov r4, r2
.L_store_and_attenuate:
    mov.l r2, @(8, r0)
    shll8 r2
    shlr2 r2
    mov.l   .L_attn_floor, r4
    cmp/ge r4, r2
    bt      .L_check_mid_clamp
    bra     .L_apply_attenuation
    mov r4, r2
    .2byte  0x0000                   /* alignment padding */
.L_attn_floor:
    .4byte  0x00000000               /* attenuation floor = 0 */
.L_check_mid_clamp:
    mov.l   .L_attn_mid_max, r4
    cmp/ge r2, r4
    bt      .L_check_fine_clamp
    bra     .L_apply_attenuation
    mov r4, r2
    .2byte  0x0000                   /* alignment padding */
.L_attn_mid_max:
    .4byte  0x00002AAA               /* mid-stage max = 10922 (1/3 of 0x7FFF) */
.L_check_fine_clamp:
    mov.l   .L_attn_fine_max, r4
    cmp/ge r2, r4
    bt      .L_apply_attenuation
    mov r4, r2
.L_apply_attenuation:
    mov.w   DAT_0602f464, r3
    mov.l @(r0, r3), r4
    sub r2, r4
    mov.l r4, @(r0, r3)
    mov.w   DAT_0602f466, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_apply_speed_copy
    mov.l   .L_drag_attn_boost, r2
.L_apply_speed_copy:
    mov.w   .L_off_speed_copy, r1
    mov.l @(r0, r1), r4
    sub r2, r4
    rts
    mov.l r4, @(r0, r1)

    .global DAT_0602f464
DAT_0602f464:
    .2byte  0x0048                   /* car+0x48: collision friction speed */

    .global DAT_0602f466
DAT_0602f466:
    .2byte  0x00C0                   /* car+0xC0: drag override flag */
.L_off_speed_copy:
    .2byte  0x0050                   /* car+0x50: speed copy */
    .2byte  0x0000                   /* alignment padding */
.L_attn_fine_max:
    .4byte  0x00000AAA               /* fine-stage max = 2730 (1/10 of 0x7FFF) */
.L_drag_attn_boost:
    .4byte  0x00002AAA               /* boosted attn when drag active */

    .global sym_0602F474
sym_0602F474:
    mov r14, r0
    mov #0x0, r5
    mov.w   DAT_0602f4aa, r1
    mov.w @(r0, r1), r3
    tst r3, r3
    bt      .L_lookup_intensity
    mov #0x1, r6
    sub r6, r3
    mov.w r3, @(r0, r1)
    cmp/eq r5, r3
    bt      .L_level_1
    cmp/eq r6, r3
    bt      .L_level_2
    mov #0x2, r7
    cmp/eq r7, r3
    bt      .L_level_3
    add #0x1, r5
.L_level_3:
    add #0x1, r5
.L_level_2:
    add #0x1, r5
.L_level_1:
    add #0x1, r5
.L_lookup_intensity:
    mov.l   .L_intensity_table, r6
    shll2 r5
    add r5, r6
    mov.l @r6, r3
    mov.w   .L_off_light_output, r1
    rts
    mov.l r3, @(r0, r1)

    .global DAT_0602f4aa
DAT_0602f4aa:
    .2byte  0x00D4                   /* car+0xD4: mode field (countdown timer) */
.L_off_light_output:
    .2byte  0x0114                   /* car+0x114: lighting output value */
    .2byte  0x0000                   /* alignment padding */
.L_intensity_table:
    .4byte  sym_060477D8             /* 4-entry intensity lookup table */

    .global sym_0602F4B4
sym_0602F4B4:
    mov.l   .L_demo_mode_flag, r1
    mov.l @r1, r3
    mov #0x1, r6
    tst r3, r3
    bt      .L_fog_active
    rts
    nop
    .2byte  0x0000                   /* alignment padding */
.L_demo_mode_flag:
    .4byte  sym_0607EAE0             /* demo_mode_flag (nonzero = skip) */
.L_fog_active:
    mov.w   DAT_0602f51a, r1
    mov.w @(r0, r1), r3
    cmp/pl r3
    bf      .L_load_car_positions
    sub r6, r3
    mov.w r3, @(r0, r1)
.L_load_car_positions:
    mov.l   .L_car_iteration_base, r5
    mov.l @r5, r5
    mov.l   .L_car_ptr_target, r3
    mov.l @r3, r6
    mov.w   DAT_0602f51c, r2
    mov.w   DAT_0602f51e, r4
    mov.l @(r0, r2), r7
    mov.l @(r0, r4), r8
    mov.w   DAT_0602f51c, r2
    mov.w   DAT_0602f51e, r4
    mov r2, r9
    add r6, r9
    mov.l @r9, r9
    mov r4, r10
    add r6, r10
    mov.l @r10, r10
    mov.l r0, @-r15
    mov.l r1, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov r7, r1
    sub r9, r1
    cmp/pl r1
    bt      .L_dx_positive
    neg r1, r1
.L_dx_positive:
    mov r8, r4
    sub r10, r4
    cmp/pl r4
    bt      .L_dz_positive
    neg r4, r4
.L_dz_positive:
    cmp/ge r4, r1
    bt      .L_dx_dominant
    shar r1
    bra     .L_distance_computed
    add r1, r4

    .global DAT_0602f51a
DAT_0602f51a:
    .2byte  0x00D6                   /* car+0xD6: fog countdown timer */

    .global DAT_0602f51c
DAT_0602f51c:
    .2byte  0x0010                   /* car+0x10: X position */

    .global DAT_0602f51e
DAT_0602f51e:
    .2byte  0x0018                   /* car+0x18: Z position */
.L_car_iteration_base:
    .4byte  sym_0607EA98             /* half car count for iteration */
.L_car_ptr_target:
    .4byte  sym_0607E948             /* target car struct pointer */
.L_dx_dominant:
    shar r4
    add r1, r4
.L_distance_computed:
    mov r4, r2
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r1
    mov.l @r15+, r0
    .byte   0xDC, 0x10    /* mov.l .L_pool_0602F578, r12 — fog threshold */
    cmp/ge r12, r2
    .byte   0x89, 0x35    /* bt 0x0602F5A8 — skip fog if far enough (external) */
    mov.l r1, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l r0, @-r15
    mov r9, r4
    sub r7, r4
    mov r10, r5
    sub r8, r5
    .byte   0xD0, 0x0B    /* mov.l .L_pool_0602F57C, r0 — continues in next TU */
