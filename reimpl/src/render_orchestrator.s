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
    mov.l   .L_0602EF00, r13
    jsr @r13
    nop
    mov.l   .L_0602EF04, r13
    jsr @r13
    nop
    mov.l   .L_0602EF08, r1
    mov #0x0, r2
    mov.l r2, @r1
    mov.w   .L_0602EEFA, r1
    mov.w @(r0, r1), r2
    add #0x2, r1
    mov.w r2, @(r0, r1)
    mov.l   .L_0602EF0C, r13
    jsr @r13
    nop
    mov.l   .L_0602EF10, r13
    jsr @r13
    nop
    mov.l   .L_0602EF14, r13
    jsr @r13
    nop
    mov.w   .L_0602EEFC, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_0602EF1C
    mov.l   .L_0602EF18, r13
    jsr @r13
    nop
    bra     .L_0602EF22
    nop
.L_0602EEFA:
    .2byte  0x0250
.L_0602EEFC:
    .2byte  0x009C
    .2byte  0x0000
.L_0602EF00:
    .4byte  sym_0602FDA4
.L_0602EF04:
    .4byte  render_camera_compute
.L_0602EF08:
    .4byte  sym_0607EAC8
.L_0602EF0C:
    .4byte  sym_0602F3EC
.L_0602EF10:
    .4byte  sym_0602F7BC
.L_0602EF14:
    .4byte  sym_0602F0E8
.L_0602EF18:
    .4byte  collision_response_b
.L_0602EF1C:
    mov.l   .L_0602EF64, r13
    jsr @r13
    nop
.L_0602EF22:
    mov.l   .L_0602EF68, r13
    jsr @r13
    nop
    mov.l   .L_0602EF6C, r13
    jsr @r13
    nop
    mov.l   .L_0602EF70, r13
    jsr @r13
    nop
    mov.l   .L_0602EF74, r13
    jsr @r13
    nop
    mov.l   .L_0602EF78, r13
    jsr @r13
    nop
    mov.l   .L_0602EF7C, r13
    jsr @r13
    nop
    mov.l   .L_0602EF80, r13
    jsr @r13
    nop
    mov.w   .L_0602EF60, r1
    mov.l   .L_0602EF84, r12
    mov.w @(r0, r1), r2
    mov.l   .L_0602EF88, r13
    tst r2, r2
    bt      .L_0602EF8C
    jsr @r12
    nop
    bra     .L_0602EF90
    nop
.L_0602EF60:
    .2byte  0x009E
    .2byte  0x0000
.L_0602EF64:
    .4byte  sym_0602F17C
.L_0602EF68:
    .4byte  sym_0602F474
.L_0602EF6C:
    .4byte  sym_0602F4B4
.L_0602EF70:
    .4byte  color_material_blend
.L_0602EF74:
    .4byte  sym_0602EFCC
.L_0602EF78:
    .4byte  vdp1_display_list_setup
.L_0602EF7C:
    .4byte  vdp1_color_setup
.L_0602EF80:
    .4byte  vdp1_coord_setup
.L_0602EF84:
    .4byte  vdp1_sprite_cmd
.L_0602EF88:
    .4byte  vdp1_display_submit
.L_0602EF8C:
    jsr @r13
    nop
.L_0602EF90:
    mov.l   .L_0602EFBC, r13
    jsr @r13
    nop
    mov.l   .L_0602EFC0, r13
    jsr @r13
    nop
    mov.l   .L_0602EFC4, r13
    jsr @r13
    nop
    mov.l @(0, r0), r2
    mov.l   .L_0602EFC8, r3
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
.L_0602EFBC:
    .4byte  vdp1_cmd_list_mgr
.L_0602EFC0:
    .4byte  sym_0602D814
.L_0602EFC4:
    .4byte  sym_0602D8BC
.L_0602EFC8:
    .4byte  0xFFFFFC3F

    .global sym_0602EFCC
sym_0602EFCC:
    mov.l @(36, r0), r4
    .byte   0x95, 0x0A    /* mov.w DAT_0602efe6, r5 */
    .byte   0x96, 0x0A    /* mov.w DAT_0602efe8, r6 */
    add r0, r5
    add r0, r6
    mov r0, r14
    .byte   0xDC, 0x04    /* mov.l .L_sincos_pair, r12 */
