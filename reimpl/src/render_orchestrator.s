/* VERIFIED: calls clip_region_test and vdp1_display_submit sub-functions during racing
 * Method: watchpoint on car struct fields caught PR=render_orchestrator+0xE4 and +0xEA
 *   as the caller of functions that write car[+0x0C], car[+0x10], car[+0x38]
 *   Confirms this orchestrates per-car rendering pipeline including position writes.
 * Date: 2026-02-28
 */

    .section .text.FUN_0602EEB8


    .global render_orchestrator
    .type render_orchestrator, @function
render_orchestrator:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pipeline_prologue, r13
    jsr @r13
    nop
    mov.l   .L_render_camera_compute, r13
    jsr @r13
    nop
    mov.l   .L_render_state_scratch, r1
    mov #0x0, r2
    mov.l r2, @r1
    mov.w   .L_off_collision_state, r1
    mov.w @(r0, r1), r2
    add #0x2, r1
    mov.w r2, @(r0, r1)
    mov.l   .L_damage_mac_core, r13
    jsr @r13
    nop
    mov.l   .L_timer_tick, r13
    jsr @r13
    nop
    mov.l   .L_perspective_project, r13
    jsr @r13
    nop
    mov.w   .L_off_collision_flag, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_collision_path_a
    mov.l   .L_collision_response_b, r13
    jsr @r13
    nop
    bra     .L_after_collision
    nop
.L_off_collision_state:
    .2byte  0x0250
.L_off_collision_flag:
    .2byte  0x009C
    .2byte  0x0000
.L_pipeline_prologue:
    .4byte  sym_0602FDA4
.L_render_camera_compute:
    .4byte  render_camera_compute
.L_render_state_scratch:
    .4byte  sym_0607EAC8
.L_damage_mac_core:
    .4byte  sym_0602F3EC
.L_timer_tick:
    .4byte  sym_0602F7BC
.L_perspective_project:
    .4byte  sym_0602F0E8
.L_collision_response_b:
    .4byte  collision_response_b
.L_collision_path_a:
    mov.l   .L_collision_response_a, r13
    jsr @r13
    nop
.L_after_collision:
    mov.l   .L_lighting_select, r13
    jsr @r13
    nop
    mov.l   .L_distance_fog, r13
    jsr @r13
    nop
    mov.l   .L_color_material_blend, r13
    jsr @r13
    nop
    mov.l   .L_orientation_sincos, r13
    jsr @r13
    nop
    mov.l   .L_vdp1_display_list_setup, r13
    jsr @r13
    nop
    mov.l   .L_vdp1_color_setup, r13
    jsr @r13
    nop
    mov.l   .L_vdp1_coord_setup, r13
    jsr @r13
    nop
    mov.w   .L_off_display_flag, r1
    mov.l   .L_vdp1_sprite_cmd, r12
    mov.w @(r0, r1), r2
    mov.l   .L_vdp1_display_submit, r13
    tst r2, r2
    bt      .L_submit_list_path
    jsr @r12
    nop
    bra     .L_after_display_submit
    nop
.L_off_display_flag:
    .2byte  0x009E
    .2byte  0x0000
.L_collision_response_a:
    .4byte  sym_0602F17C
.L_lighting_select:
    .4byte  sym_0602F474
.L_distance_fog:
    .4byte  sym_0602F4B4
.L_color_material_blend:
    .4byte  color_material_blend
.L_orientation_sincos:
    .4byte  sym_0602EFCC
.L_vdp1_display_list_setup:
    .4byte  vdp1_display_list_setup
.L_vdp1_color_setup:
    .4byte  vdp1_color_setup
.L_vdp1_coord_setup:
    .4byte  vdp1_coord_setup
.L_vdp1_sprite_cmd:
    .4byte  vdp1_sprite_cmd
.L_vdp1_display_submit:
    .4byte  vdp1_display_submit
.L_submit_list_path:
    jsr @r13
    nop
.L_after_display_submit:
    mov.l   .L_vdp1_cmd_list_mgr, r13
    jsr @r13
    nop
    mov.l   .L_render_state_cleanup, r13
    jsr @r13
    nop
    mov.l   .L_final_cleanup, r13
    jsr @r13
    nop
    mov.l @(0, r0), r2
    mov.l   .L_flag_mask, r3
    and r3, r2
    mov.l r2, @(0, r0)
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_vdp1_cmd_list_mgr:
    .4byte  vdp1_cmd_list_mgr
.L_render_state_cleanup:
    .4byte  sym_0602D814
.L_final_cleanup:
    .4byte  sym_0602D8BC
.L_flag_mask:
    .4byte  0xFFFFFC3F

    .global sym_0602EFCC
sym_0602EFCC:
    mov.l @(36, r0), r4
    .byte   0x95, 0x0A    /* mov.w DAT_0602efe6, r5 — offset to sin dest */
    .byte   0x96, 0x0A    /* mov.w DAT_0602efe8, r6 — offset to cos dest */
    add r0, r5
    add r0, r6
    mov r0, r14
    .byte   0xDC, 0x04    /* mov.l .L_sincos_pair, r12 — sincos function ptr */
