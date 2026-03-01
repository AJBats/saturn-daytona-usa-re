
    .section .text.FUN_0600C170


    .global race_utility_calc
    .type race_utility_calc, @function
race_utility_calc:
    sts.l pr, @-r15
    mov.l   .L_ptr_render_finalize, r3
    jsr @r3
    nop
    mov.l   .L_ptr_race_active_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_track_camera_path
    .byte   0xB8, 0xDE    /* bsr 0x0600B340 (external) */  ! call scene_render_coord (car-relative camera)
    nop
    bra     .L_camera_done
    nop
    .4byte  race_utility_calc
    .4byte  sym_06063574
    .4byte  0x0000FFFF
    .4byte  0x21000000
    .4byte  0x02800008
    .4byte  frame_dispatch
    .4byte  scene_post_render
    .4byte  0x02000000
    .4byte  replay_playback_engine
    .4byte  sym_0607EA98
.L_ptr_render_finalize:
    .4byte  sym_0603C000
.L_ptr_race_active_flag:
    .4byte  sym_06083255
.L_track_camera_path:
    mov.l   .L_ptr_camera_track_setup, r3
    jsr @r3
    nop
.L_camera_done:
    .byte   0xBB, 0xA9    /* bsr 0x0600B914 (external) */  ! call render_scene_loop (render all scene objects)
    nop
    mov.l   .L_ptr_grid_param_a, r0
    mov.l   .L_ptr_grid_param_b, r3
    mov.l @r0, r0
    mov.l @r3, r3
    add r3, r0
    cmp/eq #0x8, r0
    bf      .L_use_path_b
    mov.l   .L_ptr_scene_path_a, r3
    jsr @r3
    nop
    bra     .L_grid_dispatch_done
    nop
.L_use_path_b:
    mov.l   .L_ptr_scene_path_b, r3
    jsr @r3
    nop
.L_grid_dispatch_done:
    mov.l   .L_ptr_frame_tick, r2
    mov.l   .L_ptr_frame_tick_snapshot, r3
    mov.l @r2, r2
    mov.l r2, @r3
    mov.l   .L_mask_low16, r2
    mov.l   .L_ptr_vdp2_special_fn_reg, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_ptr_camera_track_setup:
    .4byte  camera_track_setup
.L_ptr_grid_param_a:
    .4byte  sym_06063E1C
.L_ptr_grid_param_b:
    .4byte  sym_06063E20
.L_ptr_scene_path_a:
    .4byte  scene_path_a
.L_ptr_scene_path_b:
    .4byte  scene_path_b
.L_ptr_frame_tick:
    .4byte  sym_06059F40
.L_ptr_frame_tick_snapshot:
    .4byte  sym_06059F4C
.L_mask_low16:
    .4byte  0x0000FFFF
.L_ptr_vdp2_special_fn_reg:
    .4byte  0x21800000
