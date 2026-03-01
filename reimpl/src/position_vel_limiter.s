
    .section .text.FUN_060122F4


    .global position_vel_limiter
    .type position_vel_limiter, @function

position_vel_limiter:
    mov.l   .L_ptr_position_vec, r4
    mov.w   .L_const_y_vel_decrement, r3
    mov.l @(4, r4), r2
    sub r3, r2
    mov.l r2, @(4, r4)
    mov.w   .L_const_z_vel_decrement, r3
    mov.l @(8, r4), r2
    sub r3, r2
    mov.l r2, @(8, r4)
    mov.l   .L_min_y_position, r5
    mov.l @(4, r4), r3
    cmp/ge r5, r3
    bt      .L_y_above_floor
    mov.l r5, @(4, r4)
.L_y_above_floor:
    mov.l   .L_min_z_position, r5
    mov.l @(8, r4), r3
    cmp/ge r5, r3
    bt      .L_z_above_floor
    mov.l r5, @(8, r4)
.L_z_above_floor:
    mov.l   .L_ptr_rotation_angle, r5
    mov.w   .L_const_rot_increment, r3
    mov.w @r5, r2
    add r3, r2
    rts
    mov.w r2, @r5
.L_const_y_vel_decrement:
    .2byte  0x2999                      /* [HIGH] Y velocity decrement per frame (16.16 fixed ~0.163) */
.L_const_z_vel_decrement:
    .2byte  0x4000                      /* [HIGH] Z velocity decrement per frame (16.16 fixed = 0.25) */
.L_const_rot_increment:
    .2byte  0x1800                      /* [HIGH] rotation angle increment per frame (0x1800 = ~33.75 deg) */
.L_ptr_game_state:
    .4byte  g_game_state                /* [HIGH] game state variable (0-31 state machine index) — unreferenced in this TU */
.L_ptr_display_mode:
    .4byte  sym_06078636                /* [HIGH] display mode byte (controls car display) — unreferenced in this TU */
.L_ptr_position_vec:
    .4byte  sym_060788B4                /* [HIGH] position vector base (XYZ triplet, 16.16 fixed-point) */
.L_min_y_position:
    .4byte  0x00020000                  /* [HIGH] 2.0 (16.16 fixed-point) — Y position floor */
.L_min_z_position:
    .4byte  0x0004CCCC                  /* [HIGH] ~4.8 (16.16 fixed-point) — Z position floor */
.L_ptr_rotation_angle:
    .4byte  sym_060788B2                /* [HIGH] Z rotation angle state (16-bit, WRAM High) */
