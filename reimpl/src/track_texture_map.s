
    .section .text.FUN_0602F7F2


    .global track_texture_map
    .type track_texture_map, @function
track_texture_map:
    sts.l pr, @-r15
    mov.l @r14, r14
    .byte   0xDC, 0x15    /* mov.l .L_fn_sound_cmd_dispatch, r12 */  ! r12 = sound_cmd_dispatch (persists)
    mov r14, r0
    .byte   0xD5, 0x15    /* mov.l .L_player_mode_ptr, r5 */  ! r5 = &player_mode (0x0607EAD8)
    mov.w   DAT_0602f842, r4
    mov.l @r5, r0
    add r14, r4
    .byte   0xD1, 0x14    /* mov.l .L_seg_range_table, r1 */  ! r1 = seg_range_table base
    mov.l @r4, r4
    shll2 r0
    add r0, r1
    mov.w @r1, r5
    tst r5, r5
    bt      .L_volume_calc
    .byte   0xD3, 0x11    /* mov.l .L_seg_entry_table, r3 */  ! r3 = seg_entry_table base
    mov.w @(2, r1), r0
    add r0, r3
.L_zone_scan_loop:
    mov.w @r3, r1
    cmp/gt r4, r1
    bt      .L_zone_next_entry
    mov.w @(2, r3), r0
    cmp/gt r0, r4
    bt      .L_zone_next_entry
    mov #0x10, r0
    mov.l @(20, r14), r1
    shll16 r0
    cmp/ge r1, r0
    bt      .L_volume_calc
    mov.l @(0, r14), r1
    mov.w   DAT_0602f844, r3
    tst r3, r1
    bf      .L_volume_calc
    or r3, r1
    mov.l r1, @(0, r14)
    .byte   0xD5, 0x08    /* mov.l .L_snd_zone_enter, r5 */  ! r5 = 0xAE0601FF (BGM zone enter)
    jsr @r12
    mov #0x4, r4
    bra     .L_volume_calc
    nop

    .global DAT_0602f842
DAT_0602f842:
    .2byte  0x01EC

    .global DAT_0602f844
DAT_0602f844:
    .2byte  0x4000
    .2byte  0x0000
    .4byte  sym_0607E944
.L_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_player_mode_ptr:
    .4byte  sym_0607EAD8
.L_seg_range_table:
    .4byte  sym_0602FD3C
.L_seg_entry_table:
    .4byte  sym_0602FD48
.L_snd_zone_enter:
    .4byte  0xAE0601FF
.L_zone_next_entry:
    add #-0x1, r5
    tst r5, r5
    add #0x4, r3
    bf      .L_zone_scan_loop
    mov.l @(0, r14), r1
    mov.w   DAT_0602f890, r3
    tst r3, r1
    bt      .L_volume_calc
    not r3, r3
    and r3, r1
    mov.l r1, @(0, r14)
    .byte   0xD5, 0x08    /* mov.l .L_snd_zone_exit, r5 */  ! r5 = 0xAE0600FF (BGM start/zone exit)
    jsr @r12
    mov #0x4, r4
.L_volume_calc:
    mov.w   .L_off_scaled_speed, r5
    add r14, r5
    mov.w   .L_speed_range_min, r3
    mov.l @r5, r1
    mov.w   .L_speed_range_max, r4
    cmp/gt r3, r1
    bt      .L_clamp_speed_high
    mov r3, r1
    bra     .L_speed_clamped
    nop

    .global DAT_0602f890
DAT_0602f890:
    .2byte  0x4000
.L_off_scaled_speed:
    .2byte  0x00E4
.L_speed_range_min:
    .2byte  0x0708
.L_speed_range_max:
    .2byte  0x2134
.L_snd_zone_exit:
    .4byte  0xAE0600FF
.L_clamp_speed_high:
    cmp/gt r1, r4
    bt      .L_speed_clamped
    mov r4, r1
.L_speed_clamped:
    sub r3, r1
    shll8 r1
    mov.w   .L_divisor_speed_range, r0
    .byte   0xBA, 0x10    /* bsr 0x0602ECCC (external) */  ! hw_divide(r0=divisor, r1=dividend)
    shlr r1
    mov #0x7F, r4
    mov #0x1, r3
    cmp/gt r3, r0
    bt      .L_vol_above_min
    mov r3, r0
    bra     .L_vol_clamped
    nop
.L_divisor_speed_range:
    .2byte  0x14B4
.L_vol_above_min:
    cmp/gt r0, r4
    bt      .L_vol_clamped
    mov r4, r0
.L_vol_clamped:
    mov r0, r5
    jsr @r12
    mov #0x1, r4
    .byte   0xD4, 0x0A    /* mov.l .L_course_type_byte, r4 */  ! r4 = &course_type_byte
    mov.b @r4, r4
    mov.w   DAT_0602f8f0, r1
    add r14, r1
    mov.l @r1, r0
    tst r0, r0
    bf      .L_check_road_type
    mov.w   DAT_0602f8f2, r1
    add r14, r1
    mov.w @r1, r0
    tst r0, r0
    bt      .L_check_road_type
    cmp/eq #0xA, r0
    bf      .L_check_surface_b
    .byte   0xD5, 0x04    /* mov.l .L_snd_surface_a_default, r5 */  ! r5 = 0xAE111EFF
    tst r4, r4
    bt      .L_dispatch_surface_snd
    .byte   0xD5, 0x04    /* mov.l .L_snd_surface_a_alt, r5 */  ! r5 = 0xAE1142FF (alt course)
    bra     .L_dispatch_surface_snd
    nop

    .global DAT_0602f8f0
DAT_0602f8f0:
    .2byte  0x01BC

    .global DAT_0602f8f2
DAT_0602f8f2:
    .2byte  0x0166
.L_course_type_byte:
    .4byte  sym_0605D241
.L_snd_surface_a_default:
    .4byte  0xAE111EFF
.L_snd_surface_a_alt:
    .4byte  0xAE1142FF
.L_check_surface_b:
    cmp/eq #0x3, r0
    .byte   0xD5, 0x20    /* mov.l .L_snd_surface_b_default, r5 */  ! r5 = 0xAE111CFF (preload)
    bf      .L_check_road_type
    tst r4, r4
    bt      .L_dispatch_surface_snd
    .byte   0xD5, 0x1F    /* mov.l .L_snd_surface_b_alt, r5 */  ! r5 = 0xAE1140FF (alt course)
.L_dispatch_surface_snd:
    jsr @r12
    mov #0x0, r4
.L_check_road_type:
    .byte   0xD4, 0x1E    /* mov.l .L_course_type_byte_2, r4 */  ! r4 = &course_type_byte
    mov.b @r4, r1
    mov.w   .L_off_collision_timer, r3
    add r14, r3
    mov #0x2C, r5
    mov.l @r3, r4
    cmp/eq r4, r5
    bf      .L_check_screech
    tst r1, r1
    .byte   0xD5, 0x1B    /* mov.l .L_snd_road_type_default, r5 */  ! r5 = 0xAE111BFF
    bt      .L_dispatch_road_snd
    .byte   0xD5, 0x1B    /* mov.l .L_snd_road_type_alt, r5 */  ! r5 = 0xAE113FFF (alt course)
.L_dispatch_road_snd:
    jsr @r12
    mov #0x0, r4
.L_check_screech:
    .byte   0xD3, 0x1A    /* mov.l .L_screech_countdown_ptr, r3 */  ! r3 = &screech_countdown
    mov.b @r3, r0
    tst r0, r0
    bt      .L_no_active_screech
    cmp/eq #0x1, r0
    add #-0x1, r0
    mov #0x0, r5
    bt/s    .L_dispatch_screech_snd
    mov.b r0, @r3
.L_no_active_screech:
    mov.l @(12, r14), r0
    tst r0, r0
    bt      .L_engine_pitch_calc
    mov.w   DAT_0602f980, r0
    mov #-0x38, r4
    mov.l @(r0, r14), r5
    extu.b r4, r4
    cmp/ge r5, r4
    bt      .L_engine_pitch_calc
    mov #0xA, r4
    mov.b r4, @r3
    mov #0x1, r5
.L_dispatch_screech_snd:
    jsr @r12
    mov #0x3, r4
.L_engine_pitch_calc:
    mov.w   DAT_0602f982, r0
    mov.l @(r0, r14), r5
    cmp/pz r5
    bt      .L_lat_vel_positive
    neg r5, r5
.L_lat_vel_positive:
    shlr8 r5
    mov #0x7, r3
    shlr2 r5
    cmp/ge r5, r3
    bt      .L_pitch_clamped
    mov #0x7, r5
.L_pitch_clamped:
    jsr @r12
    mov #0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_off_collision_timer:
    .2byte  0x00B8

    .global DAT_0602f980
DAT_0602f980:
    .2byte  0x0084

    .global DAT_0602f982
DAT_0602f982:
    .2byte  0x005C
.L_snd_surface_b_default:
    .4byte  0xAE111CFF
.L_snd_surface_b_alt:
    .4byte  0xAE1140FF
.L_course_type_byte_2:
    .4byte  sym_0605D241
.L_snd_road_type_default:
    .4byte  0xAE111BFF
.L_snd_road_type_alt:
    .4byte  0xAE113FFF
.L_screech_countdown_ptr:
    .4byte  sym_0602FD9F
