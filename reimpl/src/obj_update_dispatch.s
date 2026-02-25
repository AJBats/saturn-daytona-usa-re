/* obj_update_dispatch -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0602070C - 0x06020814
 *
 * Scene transition zoom/fade dispatcher. Each frame, decrements the X/Y/Z
 * object scale values by 0.5 (16.16 fixed-point). While scale_z > 1.0,
 * recomputes viewport draw coordinates from scale via fpmul(176/112) / fpdiv,
 * then writes them through scene_data_write_add. Once scale_z drops to 1.0
 * or below, clears draw coordinates and zeros the stored values. After the
 * coordinate pass, calls cmd_queue_commit, then checks scale_x: if still
 * above 1.0, tail-jumps to obj_anim_clear to continue the transition;
 * otherwise returns (transition complete).
 *
 * Called with r4 = obj index (byte). Uses display channel 8.
 */

    .section .text.FUN_0602070C


    .global obj_update_dispatch
    .type obj_update_dispatch, @function
obj_update_dispatch:
    mov.l r14, @-r15                            ! save r14 (callee-saved)
    mov.l r13, @-r15                            ! save r13 (callee-saved)
    mov.l r12, @-r15                            ! save r12 (callee-saved)
    mov.l r11, @-r15                            ! save r11 (callee-saved)
    sts.l pr, @-r15                             ! save return address
    add #-0x4, r15                              ! allocate 4 bytes on stack for obj index
    mov.l   .L_obj_scale_x, r13                 ! r13 = &obj_scale_x (kept across calls)
    mov.b r4, @r15                              ! save obj index (byte) on stack
    mov.l   .L_fn_cmd_queue_init, r3            ! r3 = cmd_queue_init
    jsr @r3                                     ! cmd_queue_init(0x8) — select display channel 8
    mov #0x8, r4                                ! (delay) r4 = channel 8
    mov.l   .L_fp_half, r12                     ! r12 = 0.5 (16.16 fp decrement)
    mov.l @r13, r2                              ! r2 = scale_x
    sub r12, r2                                 ! r2 = scale_x - 0.5
    mov.l r2, @r13                              ! scale_x -= 0.5
    mov.l   .L_obj_scale_y, r14                 ! r14 = &obj_scale_y
    mov.l @r14, r3                              ! r3 = scale_y
    sub r12, r3                                 ! r3 = scale_y - 0.5
    mov.l r3, @r14                              ! scale_y -= 0.5
    mov r3, r5                                  ! r5 = new scale_y (arg2)
    mov.l   .L_fn_color_intensity, r3           ! r3 = scene_color_intensity
    jsr @r3                                     ! scene_color_intensity(scale_x, scale_y)
    mov.l @r13, r4                              ! (delay) r4 = new scale_x (arg1)
    mov.l   .L_obj_scale_z, r14                 ! r14 = &obj_scale_z
    mov.l @r14, r2                              ! r2 = scale_z
    sub r12, r2                                 ! r2 = scale_z - 0.5
    mov.l r2, @r14                              ! scale_z -= 0.5
    mov r2, r3                                  ! r3 = new scale_z (for comparison)
    mov.l   .L_obj_draw_x, r11                  ! r11 = &obj_draw_x (kept across branches)
    mov.l   .L_fp_one, r2                       ! r2 = 1.0
    cmp/gt r2, r3                               ! scale_z > 1.0 ?
    bf      .L_scale_z_done                     ! if scale_z <= 1.0, skip viewport calc
    ! --- scale_z > 1.0: recompute viewport draw coords ---
    mov.l @r14, r5                              ! r5 = scale_z
    mov.l   .L_fp_neg_one, r2                   ! r2 = -1.0
    mov.l   .L_fp_176, r4                       ! r4 = 176.0 (half screen width)
    mov.l   .L_fn_fpmul, r3                     ! r3 = fpmul
    jsr @r3                                     ! r0 = fpmul(176.0, scale_z - 1.0)
    add r2, r5                                  ! (delay) r5 = scale_z - 1.0
    mov r0, r4                                  ! r4 = 176.0 * (scale_z - 1.0)
    mov.l   .L_fn_fpdiv, r3                     ! r3 = fpdiv_setup
    jsr @r3                                     ! r0 = fpdiv(176*(sz-1), scale_z) = new draw_x
    mov.l @r14, r5                              ! (delay) r5 = scale_z (divisor)
    mov r0, r12                                 ! r12 = new_draw_x (save for later)
    mov.l @r14, r5                              ! r5 = scale_z
    mov.l   .L_fp_neg_one, r2                   ! r2 = -1.0
    mov.l   .L_fp_112, r4                       ! r4 = 112.0 (half screen height)
    mov.l   .L_fn_fpmul, r3                     ! r3 = fpmul
    jsr @r3                                     ! r0 = fpmul(112.0, scale_z - 1.0)
    add r2, r5                                  ! (delay) r5 = scale_z - 1.0
    mov r0, r4                                  ! r4 = 112.0 * (scale_z - 1.0)
    mov.l   .L_fn_fpdiv, r3                     ! r3 = fpdiv_setup
    jsr @r3                                     ! r0 = fpdiv(112*(sz-1), scale_z) = new draw_y
    mov.l @r14, r5                              ! (delay) r5 = scale_z (divisor)
    mov r0, r6                                  ! r6 = new_draw_y (save temporarily)
    mov r12, r4                                 ! r4 = new_draw_x
    mov.l   .L_obj_draw_y, r7                   ! r7 = &obj_draw_y
    mov r0, r5                                  ! r5 = new_draw_y
    mov.l @r11, r2                              ! r2 = old_draw_x
    mov.l @r7, r3                               ! r3 = old_draw_y
    sub r2, r4                                  ! r4 = new_draw_x - old_draw_x (delta_x)
    sub r3, r5                                  ! r5 = new_draw_y - old_draw_y (delta_y)
    mov.l r12, @r11                             ! obj_draw_x = new_draw_x
    mov.l r6, @r7                               ! obj_draw_y = new_draw_y
    mov.l   .L_fn_scene_write_add, r3           ! r3 = scene_data_write_add
    jsr @r3                                     ! scene_data_write_add(delta_x, delta_y, 0)
    mov #0x0, r6                                ! (delay) r6 = 0 (z delta)
    bra     .L_after_draw_update                ! skip the clear path
    nop
.L_scale_z_done:
    ! --- scale_z <= 1.0: clear channel and zero draw coords ---
    mov #0x0, r6                                ! r6 = 0
    mov.l   .L_fn_display_channel_b, r3         ! r3 = display_channel_b
    mov r6, r5                                  ! r5 = 0
    jsr @r3                                     ! display_channel_b(0x8, 0, 0) — disable channel
    mov #0x8, r4                                ! (delay) r4 = channel 8
    mov #0x0, r2                                ! r2 = 0
    mov.l r2, @r11                              ! obj_draw_x = 0
.L_after_draw_update:
    ! --- commit display command queue ---
    mov.l   .L_fn_cmd_queue_commit, r3          ! r3 = cmd_queue_commit
    jsr @r3                                     ! cmd_queue_commit()
    nop
    ! --- check if transition continues ---
    mov.l @r13, r2                              ! r2 = scale_x (current)
    mov.l   .L_fp_one, r3                       ! r3 = 1.0
    cmp/gt r3, r2                               ! scale_x > 1.0 ?
    bt      .L_transition_done                  ! if still zooming, return (called again next frame)
    ! --- scale_x <= 1.0: transition finished, tail-jump to clear anim ---
    mov.b @r15, r4                              ! r4 = obj index (from stack)
    extu.b r4, r4                               ! zero-extend to 32-bit
    add #0x4, r15                               ! free stack local
    lds.l @r15+, pr                             ! restore return address
    mov.l @r15+, r11                            ! restore r11
    mov.l @r15+, r12                            ! restore r12
    mov.l @r15+, r13                            ! restore r13
    .byte   0xA3, 0x16    /* bra 0x06020DEE (external) — tail-jump to obj_anim_clear */
    mov.l @r15+, r14                            ! (delay) restore r14
.L_transition_done:
    ! --- scale_x > 1.0: still zooming, return (will be called again) ---
    add #0x4, r15                               ! free stack local
    lds.l @r15+, pr                             ! restore return address
    mov.l @r15+, r11                            ! restore r11
    mov.l @r15+, r12                            ! restore r12
    mov.l @r15+, r13                            ! restore r13
    rts                                         ! return to caller
    mov.l @r15+, r14                            ! (delay) restore r14
    ! --- constant pool ---
.L_obj_scale_x:
    .4byte  sym_06087818                        /* obj scale X (16.16 fp) */
.L_fn_cmd_queue_init:
    .4byte  sym_0603850C                        /* display cmd queue: select channel */
.L_fp_half:
    .4byte  0x00008000                          /* 0.5 (16.16 fixed-point) */
.L_obj_scale_y:
    .4byte  sym_0608781C                        /* obj scale Y (16.16 fp) */
.L_fn_color_intensity:
    .4byte  scene_color_intensity               /* scene color intensity */
.L_obj_scale_z:
    .4byte  sym_06087820                        /* obj scale Z (16.16 fp) */
.L_obj_draw_x:
    .4byte  sym_06087810                        /* obj draw X coordinate (16.16 fp) */
.L_fp_one:
    .4byte  0x00010000                          /* 1.0 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                          /* -1.0 (16.16 fixed-point) */
.L_fp_176:
    .4byte  0x00B00000                          /* 176.0 (16.16 fp) — half screen width */
.L_fn_fpmul:
    .4byte  fpmul                               /* fixed-point multiply */
.L_fn_fpdiv:
    .4byte  fpdiv_setup                         /* fixed-point divide */
.L_fp_112:
    .4byte  0x00700000                          /* 112.0 (16.16 fp) — half screen height */
.L_obj_draw_y:
    .4byte  sym_06087814                        /* obj draw Y coordinate (16.16 fp) */
.L_fn_scene_write_add:
    .4byte  scene_data_write_add                /* scene data write (additive) */
.L_fn_display_channel_b:
    .4byte  display_channel_b                   /* display channel enable */
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520                        /* display cmd queue: commit */
