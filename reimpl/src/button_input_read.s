/* VERIFIED: called during mode select C press transition (part of every-frame dispatch)
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on mode select
 *   12 calls during C (baseline 10, +2) — called every frame, extra frames from transition
 * Date: 2026-02-28
 */

    .section .text.FUN_06006F3C


    .global button_input_read
    .type button_input_read, @function
button_input_read:
    mov.l r14, @-r15
    mov #0x1, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_disp_channel_b, r8
    mov.l   .L_fn_disp_channel_a, r9
    mov.l   .L_fn_scene_dispatch, r10
    mov.l   .L_game_state_flag, r11
    mov.l   .L_frame_counter, r13
    mov.l   .L_input_state_ptr, r14
    mov.l   .L_tick_counter, r4
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
    mov.l   .L_run_flag, r3
    mov.l r2, @r3
    mov.l   .L_skip_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt/s    .L_vdp_mode_entry
    mov #0x0, r12
    bra     .L_exit_epilogue
    nop

.L_vdp_mode_entry:
    mov.l   .L_display_mode, r3
    mov.l r12, @r3
    mov.l   .L_vdp_mode, r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_vdp_check_mode3
    mov.l @r11, r0
    tst r0, r0
    bt      .L_button_dispatch
    jsr @r10
    nop
    mov #0x2, r3
    mov.l   .L_display_mode, r2
    mov.l r3, @r2
    bra     .L_button_dispatch
    nop
.L_vdp_check_mode3:
    mov.l   .L_vdp1_fbcr, r6
    mov.l   .L_fbcr_state, r5
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bf      .L_vdp_check_mode0
    mov.l @r11, r0
    tst r0, r0
    bt      .L_button_dispatch
    mov.l   .L_tvmr_state, r0
    mov.l   .L_vdp1_tvmr, r3
    mov.w @r0, r0
    extu.w r0, r0
    or #0x8, r0
    mov.w r0, @r3
    mov.w @r5, r0
    extu.w r0, r0
    or #0x3, r0
    jsr @r10
    mov.w r0, @r6
    mov #0x3, r3
    mov.l   .L_display_mode, r2
    mov.l r3, @r2
    bra     .L_button_dispatch
    nop
.L_vdp_check_mode0:
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_vdp_mode1_fbswap
    jsr @r10
    nop
    bra     .L_button_dispatch
    mov.l r12, @r11
    .2byte  0xFFFF

.L_fn_disp_channel_b:
    .4byte  display_channel_b
.L_fn_disp_channel_a:
    .4byte  display_channel_a
.L_fn_scene_dispatch:
    .4byte  scene_data_dispatch
.L_game_state_flag:
    .4byte  sym_060635C4
.L_frame_counter:
    .4byte  sym_060635C0
.L_input_state_ptr:
    .4byte  sym_0605B6D8
.L_tick_counter:
    .4byte  sym_0607864C
.L_run_flag:
    .4byte  sym_06059F54
.L_skip_flag:
    .4byte  sym_0605A00C
.L_display_mode:
    .4byte  sym_06063F58
.L_vdp_mode:
    .4byte  sym_060635B4
.L_vdp1_fbcr:
    .4byte  0x25D00002
.L_fbcr_state:
    .4byte  sym_060A4C92
.L_tvmr_state:
    .4byte  sym_060A4C90
.L_vdp1_tvmr:
    .4byte  0x25D00000

.L_vdp_mode1_fbswap:
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l   .L_fb_swap_enable, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_fbswap_check_delay
    mov.l   .L_fb_swap_delay, r2
    mov.l @r13, r3
    mov.l @r2, r2
    add #-0x1, r2
    cmp/gt r3, r2
    bt      .L_fbswap_check_delay
    mov.w @r5, r0
    extu.w r0, r0
    or #0x2, r0
    extu.w r0, r0
    mov.w r0, @r6
.L_fbswap_check_delay:
    mov.l   .L_fb_swap_delay, r3
    mov.l @r13, r2
    mov.l @r3, r3
    cmp/gt r2, r3
    bt      .L_button_dispatch
    mov.l @r11, r0
    tst r0, r0
    bt      .L_fbswap_reset_counter
    jsr @r10
    nop
    mov #0x1, r3
    mov.l   .L_display_mode_b, r2
    mov.l r3, @r2
.L_fbswap_reset_counter:
    mov.l r12, @r13

.L_button_dispatch:
    mov.l   .L_car_array_idx, r3
    mov.l   .L_car_select, r1
    mov.l @r3, r3
    mov.l @r1, r1
    shlr2 r3
    shlr r1
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l   .L_car_base, r2
    add r2, r3
    mov.l   .L_current_car, r2
    mov.l r3, @r2

    mov.l @r14, r1
    mov.l   .L_bit29_dma, r2
    and r2, r1
    tst r1, r1
    bt      .L_check_dpad_right
    mov.w   .L_dma_size_a, r6
    mov.l   .L_current_car, r5
    mov.l   .L_dma_dst_a, r4
    mov.l   .L_fn_dma_transfer, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4

.L_check_dpad_right:
    mov.l @r14, r0
    tst #0x4, r0
    bt      .L_check_dpad_left
    mov.w   .L_dma_size_b, r6
    mov.l   .L_dma_src_b, r5
    mov.l   .L_dma_dst_b, r4
    mov.l   .L_fn_dma_transfer, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4

.L_check_dpad_left:
    mov.l @r14, r0
    tst #0x10, r0
    bt      .L_check_start
    mov.l   .L_btn_left_a, r6
    mov.l   .L_btn_left_b, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x4, r4

.L_check_start:
    mov.l @r14, r0
    tst #0x20, r0
    bt      .L_check_btn_a
    mov.l   .L_btn_start_a, r6
    mov.l   .L_btn_start_b, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x8, r4

.L_check_btn_a:
    mov.l @r14, r0
    tst #0x40, r0
    bt      .L_check_btn_b
    mov.l   .L_btn_a_src, r6
    mov.l   .L_btn_a_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x10, r4

.L_check_btn_b:
    mov.l @r14, r0
    tst #0x80, r0
    bt      .L_check_chan_a0
    mov.l   .L_btn_b_src, r6
    bra     .L_btn_b_handler
    nop

.L_dma_size_a:
    .2byte  0x0640
.L_dma_size_b:
    .2byte  0x0E00
    .2byte  0xFFFF

.L_fb_swap_enable:
    .4byte  sym_060635B8
.L_fb_swap_delay:
    .4byte  sym_060635BC
.L_display_mode_b:
    .4byte  sym_06063F58
.L_car_array_idx:
    .4byte  sym_06059F3C
.L_car_select:
    .4byte  sym_06059F38
.L_car_base:
    .4byte  sym_0606B178
.L_current_car:
    .4byte  sym_06059F34
.L_bit29_dma:
    .4byte  0x20000000
.L_dma_dst_a:
    .4byte  sym_06063F60
.L_fn_dma_transfer:
    .4byte  dma_transfer
.L_dma_src_b:
    .4byte  sym_0606129C
.L_dma_dst_b:
    .4byte  sym_060612B4
.L_btn_left_a:
    .4byte  sym_0605B700
.L_btn_left_b:
    .4byte  sym_0605B6FC
.L_btn_start_a:
    .4byte  sym_0605B708
.L_btn_start_b:
    .4byte  sym_0605B704
.L_btn_a_src:
    .4byte  sym_0605B710
.L_btn_a_dst:
    .4byte  sym_0605B70C
.L_btn_b_src:
    .4byte  sym_0605B718

.L_btn_b_handler:
    mov.l @r6, r6
    mov.l   .L_btn_b_dst, r5
    mov.l @r5, r5
    jsr @r8
    mov #0x20, r4


.L_check_chan_a0:
    mov.l @r14, r3
    mov.l   .L_evt_bit16, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_chan_a1
    mov.l   .L_chan_a0_src, r6
    mov.l   .L_chan_a0_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x4, r4

.L_check_chan_a1:
    mov.l @r14, r3
    mov.l   .L_evt_bit17, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_chan_a2
    mov.l   .L_chan_a1_src, r6
    mov.l   .L_chan_a1_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x8, r4

.L_check_chan_a2:
    mov.l @r14, r3
    mov.l   .L_evt_bit18, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_chan_a3
    mov.l   .L_chan_a2_src, r6
    mov.l   .L_chan_a2_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x10, r4

.L_check_chan_a3:
    mov.l @r14, r3
    mov.l   .L_evt_bit19, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_handler_a
    mov.l   .L_chan_a3_src, r6
    mov.l   .L_chan_a3_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x20, r4


.L_check_handler_a:
    mov.l @r14, r3
    mov.l   .L_evt_bit31, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_handler_b
    mov.l   .L_fn_handler_a, r3
    jsr @r3
    nop

.L_check_handler_b:
    mov.l @r14, r2
    mov.l   .L_evt_bit30, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_channels_reload
    mov.l   .L_fn_handler_b, r3
    jsr @r3
    nop

.L_check_channels_reload:
    mov.l @r14, r2
    mov.l   .L_evt_bit20, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_collision
    mov.l   .L_fn_channels_load, r3
    jsr @r3
    nop

.L_check_collision:
    mov.l @r14, r2
    mov.l   .L_evt_bit26, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_physics
    mov.l   .L_fn_collision, r3
    jsr @r3
    nop

.L_check_physics:
    mov.l @r14, r2
    mov.l   .L_evt_bit27, r3
    and r3, r2
    tst r2, r2
    bt      .L_clear_input
    mov.l   .L_fn_physics, r3
    jsr @r3
    nop

.L_clear_input:
    mov.l r12, @r14
.L_exit_epilogue:
    mov #0x2, r2
    mov.l   .L_run_flag_exit, r3
    mov.l r2, @r3
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_btn_b_dst:
    .4byte  sym_0605B714
.L_evt_bit16:
    .4byte  0x00010000
.L_chan_a0_src:
    .4byte  sym_0605B6E0
.L_chan_a0_dst:
    .4byte  sym_0605B6DC
.L_evt_bit17:
    .4byte  0x00020000
.L_chan_a1_src:
    .4byte  sym_0605B6E8
.L_chan_a1_dst:
    .4byte  sym_0605B6E4
.L_evt_bit18:
    .4byte  0x00040000
.L_chan_a2_src:
    .4byte  sym_0605B6F0
.L_chan_a2_dst:
    .4byte  sym_0605B6EC
.L_evt_bit19:
    .4byte  0x00080000
.L_chan_a3_src:
    .4byte  sym_0605B6F8
.L_chan_a3_dst:
    .4byte  sym_0605B6F4
.L_evt_bit31:
    .4byte  0x80000000
.L_fn_handler_a:
    .4byte  sym_060149E0
.L_evt_bit30:
    .4byte  0x40000000
.L_fn_handler_b:
    .4byte  sym_060149CC
.L_evt_bit20:
    .4byte  0x00100000
.L_fn_channels_load:
    .4byte  display_channels_load
.L_evt_bit26:
    .4byte  0x04000000
.L_fn_collision:
    .4byte  obj_collision_update
.L_evt_bit27:
    .4byte  0x08000000
.L_fn_physics:
    .4byte  sym_06033354
.L_run_flag_exit:
    .4byte  sym_06059F54
