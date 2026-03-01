
   .section .text.FUN_0600E4F2


   .global car_frame_update
   .type car_frame_update, @function
car_frame_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    .byte   0xDD, 0x1C    /* mov.l .L_physics_counter, r13 — scripted movement counter */
    .byte   0xD3, 0x1C    /* mov.l .L_timing_word_src, r3 — timing word source */
    .byte   0xD1, 0x1D    /* mov.l .L_timing_word_dst, r1 — timing word destination */
    mov.w @r3, r2
    mov.w r2, @r1
    .byte   0xDE, 0x06    /* mov.l .L_car_array_base, r14 — car array base ptr */
    .byte   0xD3, 0x07    /* mov.l .L_car_struct_ptr, r3 — current car ptr */
    mov.l @r14, r14
    mov.l r14, @r3
    .byte   0xD4, 0x1A    /* mov.l .L_car_array_start, r4 — first car address */
    mov.w   DAT_0600e522, r2
    .byte   0xD3, 0x1A    /* mov.l .L_car_array_end, r3 — end marker store */
    add r4, r2
    cmp/eq r4, r14
    bf/s    .L_set_ai_flag
    mov.l r2, @r3
    bra     .L_physics_pipeline
    mov #0x0, r12

    .global DAT_0600e522
DAT_0600e522:
    .2byte  0x0268                        /* car struct stride (616 bytes) */
.L_car_array_base:
    .4byte  sym_0607E944               /* car array base pointer */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* current car struct pointer */
    .4byte  sym_0600A8BC               /* (adjacent pool: collision setup fn) */
    .4byte  gas_force_apply            /* (adjacent pool: gas force) */
    .4byte  brake_force_apply          /* (adjacent pool: brake force) */
    .4byte  sym_06030A06               /* (adjacent pool: physics fn A) */
    .4byte  sym_06030EE0               /* (adjacent pool: physics fn B) */
    .4byte  sym_06006838               /* (adjacent pool: atan2 function) */
    .4byte  sym_060786B8               /* (adjacent pool: atan2 result store) */
    .4byte  segment_position_track     /* (adjacent pool: segment tracker) */
    .4byte  scene_3d_processor         /* (adjacent pool: 3D scene processor) */
    .4byte  sym_06063EB0               /* (adjacent pool: geom channel 0) */
    .4byte  sym_06063E9C               /* (adjacent pool: geom channel 1) */
    .4byte  sym_06063ED8               /* (adjacent pool: geom channel 2) */
    .4byte  sym_06063EC4               /* (adjacent pool: geom channel 3) */
    .4byte  finish_proximity           /* (adjacent pool: finish line proximity) */
    .4byte  collision_detect_main      /* (adjacent pool: collision main) */
    .4byte  sym_0603053C               /* (adjacent pool: collision handler) */
    .4byte  checkpoint_detect          /* (adjacent pool: checkpoint detect) */
.L_physics_counter:
    .4byte  sym_060786BC               /* scripted movement frame counter */
.L_timing_word_src:
    .4byte  sym_06063D9E               /* timing word source register */
.L_timing_word_dst:
    .4byte  sym_06063F44               /* timing word destination */
.L_car_array_start:
    .4byte  sym_06078900               /* car array start address */
.L_car_array_end:
    .4byte  sym_0607E948               /* car array end marker */
.L_set_ai_flag:
    mov #0x1, r12
.L_physics_pipeline:
    .byte   0xD3, 0x46    /* mov.l .L_fn_gas_force, r3 — gas force */
    jsr @r3
    nop
    .byte   0xD3, 0x45    /* mov.l .L_fn_brake_force, r3 — brake force */
    jsr @r3
    nop
    .byte   0xD3, 0x45    /* mov.l .L_fn_physics_a, r3 — physics step A */
    jsr @r3
    nop
    .byte   0xD3, 0x44    /* mov.l .L_fn_physics_b, r3 — physics step B */
    jsr @r3
    nop
    mov.l @r13, r2
    cmp/pl r2
    bf      .L_normal_physics
    .byte   0xD0, 0x42    /* mov.l .L_race_result_byte, r0 — race result */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_normal_physics
    mov.l @r13, r3
    add #-0x1, r3
    mov.l r3, @r13
    .byte   0xD2, 0x3F    /* mov.l .L_pos_offset_x, r2 — X position offset */
    mov.l @(16, r14), r3
    mov.l @r2, r2
    add r2, r3
    mov.l r3, @(16, r14)
    .byte   0xD2, 0x3E    /* mov.l .L_pos_offset_z, r2 — Z position offset */
    mov.l @(24, r14), r3
    mov.l @r2, r2
    add r2, r3
    mov.l r3, @(24, r14)
    .byte   0xD2, 0x3C    /* mov.l .L_angle_offset, r2 — yaw angle offset */
    mov.l @(32, r14), r3
    mov.w @r2, r2
    add r2, r3
    mov.l r3, @(32, r14)
    mov r3, r2
    mov.l r3, @(48, r14)
    mov.l r2, @(40, r14)
    .byte   0xD3, 0x39    /* mov.l .L_yaw_store, r3 — global yaw store */
    mov.l r2, @r3
    mov.l @(24, r14), r5
    .byte   0xD3, 0x39    /* mov.l .L_fn_atan2, r3 — atan2 function */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x38    /* mov.l .L_atan2_result, r3 — result store */
    mov.l r0, @r3
    .byte   0xD3, 0x38    /* mov.l .L_fn_seg_track, r3 — segment tracker */
    jsr @r3
    nop
    bra     .L_post_physics
    nop
.L_normal_physics:
    .byte   0xD3, 0x37    /* mov.l .L_fn_normal_physics, r3 — normal physics */
    jsr @r3
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x32    /* mov.l .L_fn_atan2, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x31    /* mov.l .L_atan2_result, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x31    /* mov.l .L_fn_seg_track, r3 */
    jsr @r3
    nop
    .byte   0xDB, 0x32    /* mov.l .L_fn_scene_3d, r11 — 3D scene processor */
    .byte   0xD4, 0x32    /* mov.l .L_geom_channel_0, r4 */
    jsr @r11
    mov #0x0, r5
    .byte   0xD4, 0x32    /* mov.l .L_geom_channel_1, r4 */
    jsr @r11
    mov #0x1, r5
    .byte   0xD4, 0x31    /* mov.l .L_geom_channel_2, r4 */
    jsr @r11
    mov #0x2, r5
    .byte   0xD4, 0x31    /* mov.l .L_geom_channel_3, r4 */
    jsr @r11
    mov #0x3, r5
.L_post_physics:
    mov.l @(32, r14), r2
    mov.w   DAT_0600e69c, r0
    mov.l r2, @(r0, r14)
    tst r12, r12
    bf      .L_collision_pipeline
    .byte   0xD3, 0x2E    /* mov.l .L_fn_player_update, r3 — player-specific update */
    jsr @r3
    nop
.L_collision_pipeline:
    .byte   0xD3, 0x2D    /* mov.l .L_fn_finish_prox, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x2D    /* mov.l .L_fn_collision_main, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x2C    /* mov.l .L_fn_collision_handler, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x2C    /* mov.l .L_fn_checkpoint, r3 */
    jsr @r3
    mov r12, r4
    mov.w   .L_off_crossing_counter, r0
    .byte   0xD3, 0x2B    /* mov.l .L_section_count, r3 — section count */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    .byte   0xD3, 0x27    /* mov.l .L_fn_track_pos_calc, r3 */
    jsr @r3
    mov.l r2, @(r0, r14)
    mov.l @r13, r2
    cmp/pl r2
    bt      .L_terrain_check
    .byte   0xD0, 0x10    /* mov.l .L_race_result_byte, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_terrain_check
    .byte   0xB1, 0xCF    /* bsr 0x0600EA18 (external) — position override handler */
    mov r14, r4
.L_terrain_check:
    .byte   0xD0, 0x0D    /* mov.l .L_race_result_byte, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_normal_exit
    .byte   0xD3, 0x1F    /* mov.l .L_terrain_mode, r3 */
    mov.b @r3, r3
    tst r3, r3
    bf      .L_normal_exit
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x1C    /* mov.l .L_fn_terrain_update, r3 — tail-call terrain */
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0600e69c
DAT_0600e69c:
    .2byte  0x01B0                        /* car offset: yaw angle copy */
.L_off_crossing_counter:
    .2byte  0x0228                        /* car offset: crossing counter */
.L_fn_gas_force:
    .4byte  gas_force_apply            /* throttle force application */
.L_fn_brake_force:
    .4byte  brake_force_apply          /* brake force application */
.L_fn_physics_a:
    .4byte  sym_06030A06               /* physics integration step A */
.L_fn_physics_b:
    .4byte  sym_06030EE0               /* physics integration step B */
.L_race_result_byte:
    .4byte  sym_06078635               /* race result (0=in progress) */
.L_pos_offset_x:
    .4byte  sym_060786C0               /* scripted X position offset */
.L_pos_offset_z:
    .4byte  sym_060786C4               /* scripted Z position offset */
.L_angle_offset:
    .4byte  sym_060786C8               /* scripted yaw angle offset (16-bit) */
.L_yaw_store:
    .4byte  sym_06063EF0               /* global yaw angle store */
.L_fn_atan2:
    .4byte  sym_06006838               /* atan2(X, Z) function */
.L_atan2_result:
    .4byte  sym_060786B8               /* atan2 result store */
.L_fn_seg_track:
    .4byte  segment_position_track     /* segment position tracker */
.L_fn_normal_physics:
    .4byte  sym_0602ECF2               /* normal physics integration */
.L_fn_scene_3d:
    .4byte  scene_3d_processor         /* 3D scene geometry processor */
.L_geom_channel_0:
    .4byte  sym_06063EB0               /* geometry channel 0 data */
.L_geom_channel_1:
    .4byte  sym_06063E9C               /* geometry channel 1 data */
.L_geom_channel_2:
    .4byte  sym_06063ED8               /* geometry channel 2 data */
.L_geom_channel_3:
    .4byte  sym_06063EC4               /* geometry channel 3 data */
.L_fn_player_update:
    .4byte  sym_0600DB64               /* player-specific per-frame update */
.L_fn_finish_prox:
    .4byte  finish_proximity           /* finish line proximity check */
.L_fn_collision_main:
    .4byte  collision_detect_main      /* collision detection main */
.L_fn_collision_handler:
    .4byte  sym_0603053C               /* collision response handler */
.L_fn_checkpoint:
    .4byte  checkpoint_detect          /* checkpoint crossing detection */
.L_section_count:
    .4byte  sym_0607EA9C               /* track section count */
.L_fn_track_pos_calc:
    .4byte  track_position_calc        /* track position calculation */
.L_terrain_mode:
    .4byte  sym_06083255               /* terrain rendering mode flag */
.L_fn_terrain_update:
    .4byte  sym_0602D9F0               /* terrain physics update */
.L_normal_exit:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
