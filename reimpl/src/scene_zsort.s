
    .section .text.FUN_0602E07A


    .global scene_zsort
    .type scene_zsort, @function
scene_zsort:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD4, 0x10    /* mov.l .L_scene_src_a, r4 — scene source A */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_scene_dst_a, r4 — scene dest A */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_scene_src_b, r4 — scene source B */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_scene_dst_b, r4 — scene dest B */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_scene_src_c, r4 — scene source C */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_camera_pitch, r4 — camera pitch dest */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_scene_src_d, r4 — scene source D */
    mov.l @r4, r3
    exts.w r3, r3
    .byte   0xD4, 0x10    /* mov.l .L_camera_pitch_ext, r4 — extended pitch */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_scene_src_e, r4 — scene source E */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_camera_yaw, r4 — camera yaw dest */
    mov.l r3, @r4
    .byte   0xD0, 0x10    /* mov.l .L_physics_state, r0 — physics state */
    .byte   0xD1, 0x10    /* mov.l .L_val_4, r1 — value 4 */
    mov.l r1, @r0
    .byte   0xD4, 0x10    /* mov.l .L_z_near_clip, r4 — z-sort near plane */
    .byte   0xD3, 0x11    /* mov.l .L_val_near, r3 — 0xF300 */
    mov.l r3, @r4
    .byte   0xD4, 0x11    /* mov.l .L_z_far_clip, r4 — z-sort far plane */
    .byte   0xD3, 0x11    /* mov.l .L_val_far, r3 — 0x6E0000 */
    mov.l r3, @r4
    rts
    nop
    .4byte  course_table_lookup        /* (adjacent pool: caller's function) */
.L_scene_src_a:
    .4byte  sym_06082A54               /* scene parameter source A */
.L_scene_dst_a:
    .4byte  sym_06082A70               /* scene parameter dest A */
.L_scene_src_b:
    .4byte  sym_06082A58               /* scene parameter source B */
.L_scene_dst_b:
    .4byte  sym_06082A78               /* scene parameter dest B */
.L_scene_src_c:
    .4byte  sym_06082A44               /* scene parameter source C */
.L_camera_pitch:
    .4byte  sym_06063EEC               /* camera pitch (32-bit) */
.L_scene_src_d:
    .4byte  sym_06082A48               /* scene parameter source D (16-bit) */
.L_camera_pitch_ext:
    .4byte  sym_06063EF0               /* camera pitch extended (sign-extended) */
.L_scene_src_e:
    .4byte  sym_06082A50               /* scene parameter source E */
.L_camera_yaw:
    .4byte  sym_06063E24               /* camera yaw (32-bit) */
.L_physics_state:
    .4byte  sym_06082A30               /* physics/render state */
.L_val_4:
    .4byte  0x00000004                  /* physics_state initial value */
.L_z_near_clip:
    .4byte  sym_06063E34               /* z-sort near clipping distance */
.L_val_near:
    .4byte  0x0000F300                  /* near clip = 0xF300 */
.L_z_far_clip:
    .4byte  sym_06063E28               /* z-sort far clipping distance */
.L_val_far:
    .4byte  0x006E0000                  /* far clip = 0x6E0000 */

    .global loc_0602E108
loc_0602E108:
    .byte   0xD1, 0x0F    /* mov.l .L_race_complete_flag, r1 */
    mov.w   .L_zero, r3
    mov.l r3, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_depth_scale, r1 */
    .byte   0xD3, 0x0F    /* mov.l .L_fp_one, r3 — 1.0 (16.16) */
    mov.l r3, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_scene_param_src, r1 — scene param */
    mov.l @r1, r2
    .byte   0xD1, 0x0F    /* mov.l .L_camera_param_dst, r1 — camera param */
    mov.l r2, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_physics_state_2, r1 — physics state */
    .byte   0xD2, 0x10    /* mov.l .L_val_zero, r2 — 0 */
    mov.l r2, @r1
    mov.w   .L_one, r3
    .byte   0xD1, 0x0F    /* mov.l .L_checkpoint_counter, r1 */
    mov.l r3, @r1
    .byte   0xD0, 0x0F    /* mov.l .L_car_state_ptr, r0 — car state */
    mov.l @r0, r0
    mov.w   .L_zero, r3
    mov.w   .L_off_collision_cooldown, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_off_display_a, r1
    mov.w r3, @(r0, r1)
    mov.w   .L_off_display_b, r1
    mov.w r3, @(r0, r1)
    rts
    nop
.L_zero:
    .2byte  0x0000                      /* 0 */
.L_one:
    .2byte  0x0001                      /* 1 */
.L_off_collision_cooldown:
    .2byte  0x01B4                        /* car struct: collision cooldown offset */
.L_off_display_a:
    .2byte  0x00DC                        /* car struct: display param A (word) */
.L_off_display_b:
    .2byte  0x00DE                        /* car struct: display param B (word) */
.L_race_complete_flag:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
.L_depth_scale:
    .4byte  sym_0605A1D0               /* depth scale factor (16.16) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_scene_param_src:
    .4byte  sym_06082A34               /* scene parameter source */
.L_camera_param_dst:
    .4byte  sym_06063E20               /* camera parameter destination */
.L_physics_state_2:
    .4byte  sym_06082A30               /* physics/render state */
.L_val_zero:
    .4byte  0x00000000                  /* zero constant */
.L_checkpoint_counter:
    .4byte  sym_0607EAC8               /* checkpoint counter (32-bit) */
.L_car_state_ptr:
    .4byte  sym_0607E940               /* car state base pointer */
    .4byte  0xD10E6312                  /* (embedded sub-fn: raw bytes) */
    .4byte  0x23388907                  /* clear scene params */
    .4byte  0x6033D20D
    .4byte  0x4008022E
    .4byte  0xD00C2022
    .4byte  0x73FF2132
    .4byte  0xD00B6002
    .2byte  0xDD0B
