
    .section .text.FUN_0602070C


    .global obj_update_dispatch
    .type obj_update_dispatch, @function
obj_update_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_obj_scale_x, r13
    mov.b r4, @r15
    mov.l   .L_fn_cmd_queue_init, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_fp_half, r12
    mov.l @r13, r2
    sub r12, r2
    mov.l r2, @r13
    mov.l   .L_obj_scale_y, r14
    mov.l @r14, r3
    sub r12, r3
    mov.l r3, @r14
    mov r3, r5
    mov.l   .L_fn_color_intensity, r3
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_obj_scale_z, r14
    mov.l @r14, r2
    sub r12, r2
    mov.l r2, @r14
    mov r2, r3
    mov.l   .L_obj_draw_x, r11
    mov.l   .L_fp_one, r2
    cmp/gt r2, r3
    bf      .L_scale_z_done
    mov.l @r14, r5
    mov.l   .L_fp_neg_one, r2
    mov.l   .L_fp_176, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_fn_fpdiv, r3
    jsr @r3
    mov.l @r14, r5
    mov r0, r12
    mov.l @r14, r5
    mov.l   .L_fp_neg_one, r2
    mov.l   .L_fp_112, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_fn_fpdiv, r3
    jsr @r3
    mov.l @r14, r5
    mov r0, r6
    mov r12, r4
    mov.l   .L_obj_draw_y, r7
    mov r0, r5
    mov.l @r11, r2
    mov.l @r7, r3
    sub r2, r4
    sub r3, r5
    mov.l r12, @r11
    mov.l r6, @r7
    mov.l   .L_fn_scene_write_add, r3
    jsr @r3
    mov #0x0, r6
    bra     .L_after_draw_update
    nop
.L_scale_z_done:
    mov #0x0, r6
    mov.l   .L_fn_display_channel_b, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    mov #0x0, r2
    mov.l r2, @r11
.L_after_draw_update:
    mov.l   .L_fn_cmd_queue_commit, r3
    jsr @r3
    nop
    mov.l @r13, r2
    mov.l   .L_fp_one, r3
    cmp/gt r3, r2
    bt      .L_transition_done
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA3, 0x16    /* bra 0x06020DEE (external) — tail-jump to obj_anim_clear */
    mov.l @r15+, r14
.L_transition_done:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
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
