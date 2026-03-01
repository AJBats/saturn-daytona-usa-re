
    .section .text.FUN_0602F9A6


    .global track_render_pipeline
    .type track_render_pipeline, @function
track_render_pipeline:
    sts.l pr, @-r15
    mov.l @r14, r14
    .byte   0xDC, 0x18    /* mov.l .L_fn_sound_cmd_dispatch, r12 */  ! r12 = sound_cmd_dispatch (persists)
    mov r14, r0
    .byte   0xDD, 0x18    /* mov.l .L_channel_countdown_base, r13 */  ! r13 → countdown bytes [0..2]
    mov.b @r13, r0
    tst r0, r0
    bt      .L_check_channel_b
    add #-0x1, r0
    cmp/eq #0x2, r0
    bf/s    .L_check_channel_b
    mov.b r0, @r13
    .byte   0xD5, 0x15    /* mov.l .L_snd_channel_a_cmd, r5 */  ! r5 = 0xAE1103FF
    jsr @r12
    mov #0x0, r4
.L_check_channel_b:
    mov.b @(1, r13), r0
    tst r0, r0
    bt      .L_check_channel_c
    add #-0x1, r0
    cmp/eq #0x2, r0
    bf/s    .L_check_channel_c
    mov.b r0, @(1, r13)
    .byte   0xD5, 0x11    /* mov.l .L_snd_channel_b_cmd, r5 */  ! r5 = 0xAE1104FF
    jsr @r12
    mov #0x0, r4
.L_check_channel_c:
    mov.b @(2, r13), r0
    tst r0, r0
    bt      .L_check_front_speaker_a
    add #-0x1, r0
    cmp/eq #0x2, r0
    bf/s    .L_check_front_speaker_a
    mov.b r0, @(2, r13)
    .byte   0xD5, 0x0C    /* mov.l .L_snd_channel_b_cmd, r5 */  ! r5 = 0xAE1104FF (same cmd)
    jsr @r12
    mov #0x0, r4
.L_check_front_speaker_a:
    .byte   0xDD, 0x0B    /* mov.l .L_front_speaker_countdown_base, r13 */  ! r13 → front speaker bytes [0..2]
    mov.b @r13, r0
    tst r0, r0
    bt      .L_check_front_speaker_b
    add #-0x1, r0
    cmp/eq #0x4, r0
    .byte   0xD5, 0x09    /* mov.l .L_snd_front_a_expire, r5 */
    bt/s    .L_dispatch_front_sound
    mov.b r0, @r13
    cmp/eq #0x0, r0
    .byte   0xD5, 0x08    /* mov.l .L_snd_front_a_zero, r5 */
    bt      .L_dispatch_front_sound
    bra     .L_check_ambient_state
    nop
    .4byte  sym_0607E944
.L_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_channel_countdown_base:
    .4byte  sym_0602FD98
.L_snd_channel_a_cmd:
    .4byte  0xAE1103FF
.L_snd_channel_b_cmd:
    .4byte  0xAE1104FF
.L_front_speaker_countdown_base:
    .4byte  sym_0602FD9B
.L_snd_front_a_expire:
    .4byte  0xAE1110FF
.L_snd_front_a_zero:
    .4byte  0xAE1111FF
.L_check_front_speaker_b:
    mov.b @(1, r13), r0
    tst r0, r0
    bt      .L_check_ambient_state
    add #-0x1, r0
    cmp/eq #0x4, r0
    .byte   0xD5, 0x0C    /* mov.l .L_snd_front_b_expire, r5 */
    bt/s    .L_dispatch_front_sound
    mov.b r0, @(1, r13)
    cmp/eq #0x0, r0
    .byte   0xD5, 0x0B    /* mov.l .L_snd_front_b_zero, r5 */
    bf      .L_check_ambient_state
.L_dispatch_front_sound:
    jsr @r12
    mov #0x0, r4
.L_check_ambient_state:
    .byte   0xD5, 0x0A    /* mov.l .L_attract_cycle_counter, r5 */
    mov.w   .L_car_segment_offset, r4
    mov.l @r5, r0
    add r14, r4
    tst r0, r0
    mov.l @r4, r4
    bf      .L_check_cooldown_timer
    .byte   0xDD, 0x07    /* mov.l .L_ambient_state_bytes, r13 */  ! r13 → [active_flag, countdown]
    mov #0x1E, r5
    mov.b @r13, r1
    mov.b @(1, r13), r0
    cmp/pl r0
    bf      .L_ambient_countdown_zero
    bra     .L_store_ambient_state
    add #-0x1, r0
.L_car_segment_offset:
    .2byte  0x01EC
    .2byte  0x0000
.L_snd_front_b_expire:
    .4byte  0xAE1112FF
.L_snd_front_b_zero:
    .4byte  0xAE1113FF
.L_attract_cycle_counter:
    .4byte  sym_0607EAD8
.L_ambient_state_bytes:
    .4byte  sym_0602FD9D
.L_ambient_countdown_zero:
    tst r4, r4
    bt      .L_check_ambient_active
    cmp/ge r4, r5
    bf      .L_check_ambient_active
    .byte   0xD5, 0x02    /* mov.l .L_snd_ambient_trigger, r5 */  ! r5 = 0xAE1119FF
    jsr @r12
    mov #0x0, r4
    mov #0x14, r0
    bra     .L_store_ambient_state
    mov #0x1, r1
.L_snd_ambient_trigger:
    .4byte  0xAE1119FF
.L_check_ambient_active:
    tst r1, r1
    bt      .L_store_ambient_state
    .byte   0xD4, 0x08    /* mov.l .L_two_player_flag, r4 */
    mov.b @r4, r4
    .byte   0xD5, 0x08    /* mov.l .L_snd_ambient_single, r5 */  ! single-player: 0xAE111AFF
    tst r4, r4
    bt      .L_dispatch_ambient_sound
    .byte   0xD5, 0x08    /* mov.l .L_snd_ambient_split, r5 */  ! split-screen: 0xAE113EFF
.L_dispatch_ambient_sound:
    jsr @r12
    mov #0x0, r4
    mov #0x0, r1
.L_store_ambient_state:
    mov.b r1, @r13
    mov.b r0, @(1, r13)
.L_check_cooldown_timer:
    .byte   0xDD, 0x06    /* mov.l .L_sound_cooldown_timer, r13 */  ! r13 → cooldown timer (word)
    mov.w @r13, r1
    tst r1, r1
    bt      .L_cooldown_expired
    add #-0x1, r1
    bra     .L_return
    mov.w r1, @r13
.L_two_player_flag:
    .4byte  sym_0605D241
.L_snd_ambient_single:
    .4byte  0xAE111AFF
.L_snd_ambient_split:
    .4byte  0xAE113EFF
.L_sound_cooldown_timer:
    .4byte  sym_06086054
.L_cooldown_expired:
    mov.l @(0, r14), r0
    mov #0x8, r1
    tst r0, r1
    bt      .L_begin_car_scan
    bra     .L_return
    nop
.L_begin_car_scan:
    .byte   0xD1, 0x10    /* mov.l .L_obj_scan_complete_flag, r1 */
    mov.l @r1, r4
    tst r4, r4
    bf      .L_check_pit_entry
    .byte   0xD1, 0x0F    /* mov.l .L_car_object_count, r1 */
    .byte   0xD4, 0x10    /* mov.l .L_car_object_array_base, r4 */
    mov.l @r1, r5
    add #-0x1, r5
    mov.l @r4, r4
    mov #0x0, r0
    mov #0x0, r6
.L_car_scan_loop:
    .byte   0xD3, 0x0E    /* mov.l .L_sinit, r3 */  ! r3 = 0x01800000 (SINIT mask)
    mov.l @(0, r4), r1
    and r3, r1
    cmp/eq r1, r3
    bt      .L_status_match_found
    .byte   0xD3, 0x0C    /* mov.l .L_status_mask_collision, r3 */  ! r3 = 0x01400000
    mov.l @(0, r4), r1
    and r3, r1
    cmp/eq r1, r3
    bt      .L_status_match_found
    .byte   0xD3, 0x0B    /* mov.l .L_status_mask_offtrack, r3 */  ! r3 = 0x02C00000
    mov.l @(0, r4), r1
    and r3, r1
    cmp/eq r1, r3
    bf      .L_car_scan_next
    add #0x1, r6
.L_car_scan_next:
    dt r5
    mov.w   .L_car_struct_stride, r3
    bt      .L_car_scan_done
    bra     .L_car_scan_loop
    add r3, r4
.L_car_struct_stride:
    .2byte  0x0268
    .2byte  0x0000
.L_obj_scan_complete_flag:
    .4byte  sym_0607EAE0
.L_car_object_count:
    .4byte  sym_0607EA98
.L_car_object_array_base:
    .4byte  sym_0607E948
.L_sinit:
    .4byte  0x01800000
.L_status_mask_collision:
    .4byte  0x01400000
.L_status_mask_offtrack:
    .4byte  0x02C00000
.L_status_match_found:
    add #0x1, r0
    cmp/eq #0x2, r0
    bt      .L_two_matches_found
    dt r5
    mov.w   .L_car_struct_stride_2, r3
    bt      .L_car_scan_done
    bra     .L_car_scan_loop
    add r3, r4
.L_car_struct_stride_2:
    .2byte  0x0268
.L_two_matches_found:
    .byte   0xD3, 0x03    /* mov.l .L_sinit_cooldown_byte, r3 */
    mov.b @r3, r5
    tst r5, r5
    bt      .L_sinit_cooldown_ready
    add #-0x1, r5
    bra     .L_check_pit_entry
    mov.b r5, @r3
.L_sinit_cooldown_byte:
    .4byte  sym_0602FDA1
.L_sinit_cooldown_ready:
    mov.l @(12, r4), r5
    mov.l @(12, r14), r0
    cmp/ge r5, r0
    bf      .L_check_pit_entry
    mov #0xA, r5
    mov.b r5, @r3
    .byte   0xD5, 0x02    /* mov.l .L_snd_sinit_distance, r5 */  ! r5 = 0xAE1135FF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13
.L_snd_sinit_distance:
    .4byte  0xAE1135FF
.L_car_scan_done:
    cmp/pl r6
    bf      .L_check_pit_entry
    .byte   0xD3, 0x03    /* mov.l .L_offtrack_cooldown_byte, r3 */
    mov.b @r3, r5
    tst r5, r5
    bt      .L_check_offtrack_distance
    add #-0x1, r5
    bra     .L_check_pit_entry
    mov.b r5, @r3
    .2byte  0x0000
.L_offtrack_cooldown_byte:
    .4byte  sym_0602FDA0
.L_check_offtrack_distance:
    mov.l @(12, r4), r0
    mov.l @(12, r14), r5
    sub r5, r0
    mov.w   DAT_0602fba8, r5
    cmp/pz r0
    extu.w r5, r5
    bf      .L_check_pit_entry
    cmp/gt r0, r5
    .byte   0xD5, 0x05    /* mov.l .L_snd_offtrack_near, r5 */  ! near: 0xAE113AFF
    bt      .L_dispatch_offtrack_sound
    .byte   0xD5, 0x05    /* mov.l .L_snd_offtrack_far, r5 */  ! far: 0xAE1130FF
.L_dispatch_offtrack_sound:
    mov #0x3, r0
    mov.b r0, @r3
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13

    .global DAT_0602fba8
DAT_0602fba8:
    .2byte  0x8E38
    .2byte  0x0000
.L_snd_offtrack_near:
    .4byte  0xAE113AFF
.L_snd_offtrack_far:
    .4byte  0xAE1130FF
.L_check_pit_entry:
    mov.w   DAT_0602fbca, r0
    mov #0x1, r3
    mov.l @(r0, r14), r1
    cmp/eq r1, r3
    bf      .L_check_stereo_crossfade
    .byte   0xD5, 0x03    /* mov.l .L_snd_pit_entry, r5 */  ! r5 = 0xAE1132FF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13

    .global DAT_0602fbca
DAT_0602fbca:
    .2byte  0x01BC
.L_snd_pit_entry:
    .4byte  0xAE1132FF
.L_check_stereo_crossfade:
    .byte   0xD3, 0x05    /* mov.l .L_front_speaker_state_pair, r3 */
    mov.b @r3+, r0
    mov.b @r3, r5
    add r5, r0
    cmp/eq #0x1, r0
    bf      .L_segment_trigger_scan
    .byte   0xD5, 0x03    /* mov.l .L_snd_stereo_crossfade, r5 */  ! r5 = 0xAE1137FF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13
.L_front_speaker_state_pair:
    .4byte  sym_0602FD9B
.L_snd_stereo_crossfade:
    .4byte  0xAE1137FF
.L_segment_trigger_scan:
    .byte   0xD1, 0x09    /* mov.l .L_attract_cycle_counter_2, r1 */
    .byte   0xD4, 0x0A    /* mov.l .L_seg_table_header, r4 */
    mov.l @r1, r2
    shll2 r2
    add r2, r4
    mov.w   .L_car_segment_offset_2, r0
    mov.w @r4, r3
    mov.l @(r0, r14), r5
    mov.w @(2, r4), r0
    .byte   0xD6, 0x07    /* mov.l .L_seg_entry_table, r6 */
    add r0, r6
.L_seg_scan_loop:
    mov.w @r6+, r7
    cmp/eq r7, r5
    bt      .L_seg_match_found
    dt r3
    bt      .L_check_time_warning
    bra     .L_seg_scan_loop
    add #0x2, r6
.L_car_segment_offset_2:
    .2byte  0x01EC
    .2byte  0x0000
.L_attract_cycle_counter_2:
    .4byte  sym_0607EAD8
.L_seg_table_header:
    .4byte  sym_0602FD54
.L_seg_entry_table:
    .4byte  sym_0602FD60
.L_seg_match_found:
    mov.w @r6, r0
    cmp/eq #0x2, r0
    bt      .L_seg_type_speed_check
    cmp/eq #0x3, r0
    bt      .L_seg_type_distance_check
    mov.w   DAT_0602fc6e, r1
    mov.w   DAT_0602fc70, r2
    mov.w   DAT_0602fc72, r3
    mov.w   DAT_0602fc74, r4
    add r14, r1
    add r14, r2
    add r14, r3
    add r14, r4
    mov.w @r1, r1
    mov.w @r2, r2
    mov.l @r3, r3
    mov.l @r4, r4
    add r1, r2
    add r2, r3
    add r3, r4
    tst r4, r4
    bf      .L_check_time_warning
    .byte   0xD1, 0x09    /* mov.l .L_sound_id_lookup_table, r1 */
    mov.w   DAT_0602fc76, r11
    add r14, r11
    mov.l @r11, r11
    mov #0x1, r5
    tst r11, r5
    bt      .L_check_time_warning
    shll2 r0
    add r0, r1
    mov.l @r1, r5
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13

    .global DAT_0602fc6e
DAT_0602fc6e:
    .2byte  0x0250

    .global DAT_0602fc70
DAT_0602fc70:
    .2byte  0x0150

    .global DAT_0602fc72
DAT_0602fc72:
    .2byte  0x01BC

    .global DAT_0602fc74
DAT_0602fc74:
    .2byte  0x00B8

    .global DAT_0602fc76
DAT_0602fc76:
    .2byte  0x0228
.L_sound_id_lookup_table:
    .4byte  sym_0602FD30
.L_seg_type_speed_check:
    mov.w   DAT_0602fc9c, r2
    mov.l @(8, r14), r3
    cmp/gt r3, r2
    bt      .L_check_time_warning
    mov.w   DAT_0602fc9e, r0
    mov #0x18, r5
    mov.l @(r0, r14), r1
    shll8 r5
    cmp/gt r1, r5
    bt      .L_check_time_warning
    .byte   0xD5, 0x03    /* mov.l .L_snd_speed_threshold, r5 */  ! r5 = 0xAE1136FF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13

    .global DAT_0602fc9c
DAT_0602fc9c:
    .2byte  0x00C8

    .global DAT_0602fc9e
DAT_0602fc9e:
    .2byte  0x005C
.L_snd_speed_threshold:
    .4byte  0xAE1136FF
.L_seg_type_distance_check:
    mov.w   .L_distance_threshold_b, r2
    mov.l @(8, r14), r3
    cmp/gt r3, r2
    bt      .L_check_time_warning
    .byte   0xD5, 0x03    /* mov.l .L_snd_distance_trigger, r5 */  ! r5 = 0xAE112CFF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13
.L_distance_threshold_b:
    .2byte  0x00F0
    .2byte  0x0000
.L_snd_distance_trigger:
    .4byte  0xAE112CFF
.L_check_time_warning:
    mov.w   .L_race_mode_offset, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x1, r0
    bf      .L_check_final_lap
    .byte   0xD2, 0x05    /* mov.l .L_time_threshold, r2 */  ! r2 = 0x00028000 (time limit)
    mov.l @(12, r14), r1
    cmp/ge r1, r2
    bt      .L_check_final_lap
    .byte   0xD5, 0x04    /* mov.l .L_snd_time_warning, r5 */  ! r5 = 0xAE1131FF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13
.L_race_mode_offset:
    .2byte  0x00B8
    .2byte  0x0000
.L_time_threshold:
    .4byte  0x00028000
.L_snd_time_warning:
    .4byte  0xAE1131FF
.L_check_final_lap:
    .byte   0xD5, 0x0C    /* mov.l .L_attract_cycle_counter_3, r5 */
    mov.w   DAT_0602fd1a, r4
    mov.l @r5, r0
    add r14, r4
    cmp/eq #0x1, r0
    bf      .L_return
    mov #-0x20, r1
    mov.l @r4, r4
    extu.b r1, r1
    cmp/eq r1, r4
    bt      .L_final_lap_speed_check
    add #0x1, r1
    cmp/eq r1, r4
    bf      .L_return
.L_final_lap_speed_check:
    mov #0xA, r1
    mov.l @(20, r14), r0
    shll16 r1
    cmp/ge r0, r1
    bt      .L_return
    .byte   0xD5, 0x04    /* mov.l .L_snd_final_lap_alert, r5 */  ! r5 = 0xAE112EFF
    jsr @r12
    mov #0x0, r4
    mov #0x3C, r4
    bra     .L_return
    mov.w r4, @r13

    .global DAT_0602fd1a
DAT_0602fd1a:
    .2byte  0x01EC
.L_attract_cycle_counter_3:
    .4byte  sym_0607EAD8
.L_snd_final_lap_alert:
    .4byte  0xAE112EFF
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0602FD30
sym_0602FD30:
    .byte   0xAE, 0x11    /* bra 0x0602F956 (external) */
    addv r15, r1
    .4byte  0xAE112FFF
    .4byte  0xAE1136FF

    .global sym_0602FD3C
sym_0602FD3C:
    .word 0x0000
    .word 0x0000
    stc sr, r0
    .word 0x0000
    .word 0x0001
    clrt

    .global sym_0602FD48
sym_0602FD48:
    .word 0x0058
    mov.w r7, @(r0, r0)
    .word 0x00E0
    .word 0x00E1
    mov.l r6, @(r0, r0)
    mov.w @(r0, r6), r0

    .global sym_0602FD54
sym_0602FD54:
    bsrf r0
    .word 0x0000
    mov.l r0, @(r0, r0)
    mov.b @(r0, r0), r0
    mov.w r0, @(r0, r0)
    mov.b r2, @(r0, r0)

    .global sym_0602FD60
sym_0602FD60:
    sleep
    stc sr, r0
    .word 0x003A
    .word 0x0001
    mov.w @(r0, r4), r0
    stc sr, r0
    .word 0x0052
    stc sr, r0
    .word 0x006A
    .word 0x0001
    .word 0x0082
    stc sr, r0
    mov.w @(r0, r9), r0
    stc sr, r0
    mov.b r11, @(r0, r0)
    stc sr, r0
    mov.b @(r0, r13), r0
    stc sr, r0
    .word 0x0078
    bsrf r0
    mov.w @(r0, r9), r0
    stc sr, r0
    mov.b r13, @(r0, r0)
    bsrf r0
    .word 0x0190
    .word 0x0001
    mov.l @(r0, r12), r1
    stc sr, r0

    .global sym_0602FD98
sym_0602FD98:
    .word 0x0000

    .global sym_0602FD9A
sym_0602FD9A:
    .word 0x0000

    .global sym_0602FD9C
sym_0602FD9C:
    .word 0x0000
    .word 0x0000

    .global sym_0602FDA0
sym_0602FDA0:
    .word 0x0000
    .word 0x0000

    .global sym_0602FDA4
sym_0602FDA4:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
