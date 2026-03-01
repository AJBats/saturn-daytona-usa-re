
    .section .text.FUN_06021128


    .global obj_render_cleanup
    .type obj_render_cleanup, @function
obj_render_cleanup:
    sts.l pr, @-r15
    mov.l   .L_fn_cmd_slot_write, r3
    jsr @r3
    mov #0x8, r4
    mov #0x1, r2
    mov.l   .L_channel_flag_d, r3
    mov.b r2, @r3
    mov.l   .L_scene_config_base, r4
    mov.l   .L_fn_scene_buffer_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_cmd_queue_commit, r3
    jsr @r3
    nop
    mov #0x0, r4
    mov.l   .L_render_timer, r3
    mov.b r4, @r3
    mov.l   .L_render_trigger, r3
    mov.b r4, @r3
    mov.l   .L_car_state_store, r3
    lds.l @r15+, pr
    rts
    mov.l r4, @r3
    .2byte  0xFFFF                         /* padding to align constant pool */
.L_fn_cmd_slot_write:
    .4byte  sym_0603850C
.L_channel_flag_d:
    .4byte  sym_06087C87
.L_scene_config_base:
    .4byte  sym_06087C84
.L_fn_scene_buffer_init:
    .4byte  scene_buffer_init
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520
.L_render_timer:
    .4byte  sym_06089594
.L_render_trigger:
    .4byte  sym_06089595
.L_car_state_store:
    .4byte  sym_06089598
