
    .section .text.FUN_06005AE8


    .global display_compositor
    .type display_compositor, @function
display_compositor:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   _pool_2p_mode_flag, r8
    mov.l   _pool_effect_timer_ptr, r9
    mov.l   _pool_overlay_counter, r11
    mov.l   _pool_fade_timer, r12
    mov.l   _pool_dlist_cmd_writer, r13
    mov.l   _pool_car_state_ptr, r14
    mov.w   DAT_06005b7c, r0
    mov.l   _pool_max_frame_count, r3
    mov.l @r14, r14
    mov.l @r3, r3
    mov.l @(r0, r14), r7
    add #0x1, r7
    cmp/hi r3, r7
    bt/s    .L_06005B20
    mov #0x8, r10
    mov #0xC, r6
    mov.w   _wpool_x_pos_frame, r5
    jsr @r13
    mov #0x8, r4
.L_06005B20:
    mov.b @r8, r0
    tst r0, r0
    bt      .L_06005B2C
    mov.w   DAT_06005b80, r5
    bra     .L_06005B2E
    nop
.L_06005B2C:
    mov.w   DAT_06005b82, r5
.L_06005B2E:
    mov.l   _pool_scale_mode_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06005B3A
    bra     .L_06005B44
    mov.l @(8, r14), r7
.L_06005B3A:
    mov.l @(8, r14), r7
    mov.l   _pool_perspective_scale, r3
    mul.l r3, r7
    sts macl, r7
    shlr16 r7
.L_06005B44:
    mov #0x24, r6
    jsr @r13
    mov #0x8, r4
    mov.l   _pool_extra_layer_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06005B60
    mov.w   DAT_06005b84, r0
    mov #0x30, r6
    mov.w   _wpool_x_pos_z, r5
    mov.l @(r0, r14), r7
    add #0x1, r7
    jsr @r13
    mov #0x8, r4
.L_06005B60:
    mov.b @r8, r0
    tst r0, r0
    bt      .L_06005B6C
    mov.w   DAT_06005b88, r5
    bra     .L_06005B6E
    nop
.L_06005B6C:
    mov.w   DAT_06005b8a, r5
.L_06005B6E:
    mov.l   _pool_alt_offset_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06005BBC
    mov.w   _wpool_alt_field_offset, r0
    bra     .L_06005BBE
    nop

    .global DAT_06005b7c
DAT_06005b7c:
    .2byte  0x021C
_wpool_x_pos_frame:
    .2byte  0x0108

    .global DAT_06005b80
DAT_06005b80:
    .2byte  0x0220

    .global DAT_06005b82
DAT_06005b82:
    .2byte  0x0320

    .global DAT_06005b84
DAT_06005b84:
    .2byte  0x0224
_wpool_x_pos_z:
    .2byte  0x0142

    .global DAT_06005b88
DAT_06005b88:
    .2byte  0x0236

    .global DAT_06005b8a
DAT_06005b8a:
    .2byte  0x0336
_wpool_alt_field_offset:
    .2byte  0x00DE
    .2byte  0xFFFF
_pool_2p_mode_flag:
    .4byte  sym_06085FF4
_pool_effect_timer_ptr:
    .4byte  sym_0607EAAC
_pool_overlay_counter:
    .4byte  sym_06063E10
_pool_fade_timer:
    .4byte  sym_06063E0C
_pool_dlist_cmd_writer:
    .4byte  sym_06028430
_pool_car_state_ptr:
    .4byte  sym_0607E944
_pool_max_frame_count:
    .4byte  sym_06063F28
_pool_scale_mode_flag:
    .4byte  sym_06078644
_pool_perspective_scale:
    .4byte  0x00009F1A
_pool_extra_layer_flag:
    .4byte  sym_0607EAE0
_pool_alt_offset_flag:
    .4byte  sym_0607EAB8
.L_06005BBC:
    mov.w   DAT_06005c74, r0
.L_06005BBE:
    mov #0x6C, r6
    mov.w @(r0, r14), r7
    add #0x1, r7
    jsr @r13
    mov #0x8, r4
    mov.b @r8, r0
    tst r0, r0
    bf      .L_06005C60
    mov.l   _pool_game_state_bitmask, r3
    mov.l   .L_06005C80, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_06005C1E
    mov #0x1, r4
    mov.l @r9, r0
    cmp/eq #0x78, r0
    bf      .L_06005BE8
    mov #0x3C, r2
    mov.l r2, @r12
    mov.l r10, @r11
.L_06005BE8:
    mov.l @r9, r3
    .2byte  0xE278
    .4byte  0x33238916
    .4byte  0x62B272FF
    .4byte  0x22288F12
    .4byte  0x2B22D522
    .4byte  0xD322430B
    .4byte  0xE40062C2
    .4byte  0x72FD2C22
    .4byte  0x632333A3
    .4byte  0x89002CA2
    .4byte  0x63C24321
    .4byte  0x43214321
    .4byte  0x73012B32
    .2byte  0xE400
.L_06005C1E:
    tst r4, r4
    bt      .L_06005C40
    mov.l @r9, r1
    mov.l   _pool_geometry_transform, r3
    jsr @r3
    mov #0x14, r0
    mov r0, r7
    mov.w   DAT_06005c76, r4
    cmp/gt r4, r7
    bf      .L_06005C34
    mov r4, r7
.L_06005C34:
    mov #0x18, r6
    mov.w   _wpool_x_pos_overlay, r5
    jsr @r13
    mov #0x8, r4
    bra     .L_06005C60
    nop
.L_06005C40:
    mov.l   _pool_static_text_data, r7
    mov #0x60, r6
    mov r6, r5
    add #0x46, r5
    mov #0x8, r4
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   _pool_geom_dispatch_final, r3
    jmp @r3
    mov.l @r15+, r14
.L_06005C60:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06005c74
DAT_06005c74:
    .2byte  0x00DC

    .global DAT_06005c76
DAT_06005c76:
    .2byte  0x03E7
_wpool_x_pos_overlay:
    .2byte  0x00A6
    .2byte  0xFFFF
_pool_game_state_bitmask:
    .4byte  sym_0607EBC4
.L_06005C80:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
    .4byte  0xAE1114FF
    .4byte  sound_cmd_dispatch
_pool_geometry_transform:
    .4byte  sym_06034FE0
_pool_static_text_data:
    .4byte  sym_0605ACF3
_pool_geom_dispatch_final:
    .4byte  sym_060284AE
