
    .section .text.FUN_0602382C


    .global scene_setup_master
    .type scene_setup_master, @function
scene_setup_master:
    sts.l pr, @-r15
    mov #0x0, r2
    add #-0x8, r15
    mov.l   .L_scene_state_flags, r3
    mov.w r2, @r3
    mov r2, r3
    mov r3, r0
    mov r3, r6
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_fn_handler_slot01, r7
    mov.w   .L_size_slot01, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov.w   .L_size_slot02, r5
    mov.l   .L_fn_handler_slot02, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_fn_handler_slot03, r7
    mov #0x0, r6
    mov.w   DAT_060238fe, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov.w   DAT_06023900, r5
    mov.l   .L_fn_handler_slot04, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_fn_handler_slot05, r7
    mov #0x0, r6
    mov.w   .L_size_slot05, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov.w   DAT_06023904, r5
    mov.l   .L_fn_handler_slot06, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_fn_handler_slot07, r7
    mov #0x4, r6
    mov.w   .L_size_slot07, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov.w   .L_size_slot07, r5
    mov.l   .L_fn_handler_slot08, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov.l   .L_fn_handler_slot09, r7
    mov #0x0, r6
    mov.w   .L_size_slot09, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov.w   .L_size_slot0A, r5
    mov.l   .L_fn_handler_slot0A, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_fn_handler_phase1_last, r7
    bra     .L_register_phase2
    nop
.L_size_slot01:
    .2byte  0x0108
.L_size_slot02:
    .2byte  0x0810

    .global DAT_060238fe
DAT_060238fe:
    .2byte  0x0512

    .global DAT_06023900
DAT_06023900:
    .2byte  0x083C
.L_size_slot05:
    .2byte  0x0519

    .global DAT_06023904
DAT_06023904:
    .2byte  0x080F
.L_size_slot07:
    .2byte  0x0738
.L_size_slot09:
    .2byte  0x0208
.L_size_slot0A:
    .2byte  0x0A28
.L_scene_state_flags:
    .4byte  sym_06089E44
.L_fn_handler_slot01:
    .4byte  0x002A299B
.L_fn_vdp1_sprite_render:
    .4byte  vdp1_sprite_render
.L_fn_handler_slot02:
    .4byte  0x002A29A3
.L_fn_handler_slot03:
    .4byte  0x002A2A53
.L_fn_handler_slot04:
    .4byte  0x002A2B27
.L_fn_handler_slot05:
    .4byte  0x002A2E73
.L_fn_handler_slot06:
    .4byte  0x002A2F93
.L_fn_handler_slot07:
    .4byte  0x002A3027
.L_fn_handler_slot08:
    .4byte  0x002A325B
.L_fn_handler_slot09:
    .4byte  0x002A3433
.L_fn_handler_slot0A:
    .4byte  0x002A3457
.L_fn_handler_phase1_last:
    .4byte  0x002A0640
.L_register_phase2:
    mov.w @(4, r15), r0
    mov.w   .L_size_slot10_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_fn_handler_slot10_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot11_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov.l   .L_fn_handler_slot11_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot12_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_fn_handler_slot12_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot13_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_fn_handler_slot13_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot14_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov.l   .L_fn_handler_slot14_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot14_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov.l   .L_fn_handler_slot15_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot16_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x16, r4
    mov.l   .L_fn_handler_slot16_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot17_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov.l   .L_fn_handler_slot17_b, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023a62, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov.l   .L_fn_handler_slot18_b, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot19_b, r5
    mov.l   .L_fn_vdp1_sprite_render_2, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov.l   .L_fn_handler_slot19_b, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x4, r6
    shll2 r6
    mov.w   .L_size_slot19_b, r5
    bra     .L_register_phase3
    nop
.L_size_slot10_b:
    .2byte  0x0228
.L_size_slot11_b:
    .2byte  0x0428
.L_size_slot12_b:
    .2byte  0x0418
.L_size_slot13_b:
    .2byte  0x0820
.L_size_slot14_b:
    .2byte  0x0518
.L_size_slot16_b:
    .2byte  0x0508
.L_size_slot17_b:
    .2byte  0x0D10

    .global DAT_06023a62
DAT_06023a62:
    .2byte  0x041C
.L_size_slot19_b:
    .2byte  0x0348
    .2byte  0xFFFF
.L_fn_vdp1_sprite_render_2:
    .4byte  vdp1_sprite_render
.L_fn_handler_slot10_b:
    .4byte  0x002A06AC
.L_fn_handler_slot11_b:
    .4byte  0x002A074C
.L_fn_handler_slot12_b:
    .4byte  0x002A07E4
.L_fn_handler_slot13_b:
    .4byte  0x002A09B4
.L_fn_handler_slot14_b:
    .4byte  0x002A0A34
.L_fn_handler_slot15_b:
    .4byte  0x002A0AA4
.L_fn_handler_slot16_b:
    .4byte  0x002A0AD8
.L_fn_handler_slot17_b:
    .4byte  0x002A0C14
.L_fn_handler_slot18_b:
    .4byte  0x002A0D7C
.L_fn_handler_slot19_b:
    .4byte  0x002A0F58
.L_register_phase3:
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov.l   .L_fn_handler_slot1A_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1A_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov.l   .L_fn_handler_slot1B_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1B_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov.l   .L_fn_handler_slot1C_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1C_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov.l   .L_fn_handler_slot1D_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1D_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x6, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1E, r4
    mov.l   .L_fn_handler_slot1E_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1E_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x6, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1F, r4
    mov.l   .L_fn_handler_slot1F_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1F_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x20, r4
    mov.l   .L_fn_handler_slot20_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot20_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x21, r4
    mov.l   .L_fn_handler_slot21_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1F_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x22, r4
    mov.l   .L_fn_handler_slot22_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot1F_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x23, r4
    mov.l   .L_fn_handler_slot23_c, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot20_c, r5
    mov.l   .L_fn_vdp1_sprite_render_3, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x24, r4
    bra     .L_register_phase4
    nop
.L_size_slot1A_c:
    .2byte  0x0348
.L_size_slot1B_c:
    .2byte  0x0630
.L_size_slot1C_c:
    .2byte  0x0A28
.L_size_slot1D_c:
    .2byte  0x0C08
.L_size_slot1E_c:
    .2byte  0x0C10
.L_size_slot1F_c:
    .2byte  0x0308
.L_size_slot20_c:
    .2byte  0x0410
    .2byte  0xFFFF
.L_fn_vdp1_sprite_render_3:
    .4byte  vdp1_sprite_render
.L_fn_handler_slot1A_c:
    .4byte  0x002A1140
.L_fn_handler_slot1B_c:
    .4byte  0x002A12F8
.L_fn_handler_slot1C_c:
    .4byte  0x002A1484
.L_fn_handler_slot1D_c:
    .4byte  0x002A1890
.L_fn_handler_slot1E_c:
    .4byte  0x002A1908
.L_fn_handler_slot1F_c:
    .4byte  0x002A1AC4
.L_fn_handler_slot20_c:
    .4byte  0x002A1B04
.L_fn_handler_slot21_c:
    .4byte  0x002A1B9C
.L_fn_handler_slot22_c:
    .4byte  0x002A1BC8
.L_fn_handler_slot23_c:
    .4byte  0x002A1C04
.L_register_phase4:
    mov.l   .L_fn_handler_slot25_d, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023cf8, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x25, r4
    mov.l   .L_fn_handler_slot26_d, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023cf8, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x26, r4
    mov.l   .L_fn_handler_slot27_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot27_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x27, r4
    mov.l   .L_fn_handler_slot28_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot28_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x28, r4
    mov.l   .L_fn_handler_slot29_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot29_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x29, r4
    mov.l   .L_fn_handler_slot2A_d, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023d00, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2A, r4
    mov.l   .L_fn_handler_slot2B_d, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023d02, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2B, r4
    mov.l   .L_fn_handler_slot2C_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot2C_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2C, r4
    mov.l   .L_fn_handler_slot2D_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot2C_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2D, r4
    mov.l   .L_fn_handler_slot2E_d, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot28_d, r5
    mov.l   .L_fn_vdp1_sprite_render_4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2E, r4
    mov.l   .L_fn_handler_slot2F_d, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x5, r6
    shll2 r6
    bra     .L_register_phase5
    nop

    .global DAT_06023cf8
DAT_06023cf8:
    .2byte  0x060C
.L_size_slot27_d:
    .2byte  0x0610
.L_size_slot28_d:
    .2byte  0x0510
.L_size_slot29_d:
    .2byte  0x0310

    .global DAT_06023d00
DAT_06023d00:
    .2byte  0x090C

    .global DAT_06023d02
DAT_06023d02:
    .2byte  0x080C
.L_size_slot2C_d:
    .2byte  0x0110
    .2byte  0xFFFF
.L_fn_handler_slot25_d:
    .4byte  0x002A1CC8
.L_fn_vdp1_sprite_render_4:
    .4byte  vdp1_sprite_render
.L_fn_handler_slot26_d:
    .4byte  0x002A1D2C
.L_fn_handler_slot27_d:
    .4byte  0x002A1D84
.L_fn_handler_slot28_d:
    .4byte  0x002A1E20
.L_fn_handler_slot29_d:
    .4byte  0x002A1E8C
.L_fn_handler_slot2A_d:
    .4byte  0x002A1EFC
.L_fn_handler_slot2B_d:
    .4byte  0x002A1FC8
.L_fn_handler_slot2C_d:
    .4byte  0x002A2060
.L_fn_handler_slot2D_d:
    .4byte  0x002A2080
.L_fn_handler_slot2E_d:
    .4byte  0x002A20A0
.L_fn_handler_slot2F_d:
    .4byte  0x002A211C
.L_register_phase5:
    mov.w   .L_size_slot2F_e, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2F, r4
    mov.l   .L_fn_handler_slot30_e, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023e50, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x30, r4
    mov.l   .L_fn_handler_slot31_e, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023e52, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x31, r4
    mov.l   .L_fn_handler_slot32_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x32, r4
    mov.l   .L_fn_handler_slot33_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x33, r4
    mov.l   .L_fn_handler_slot34_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x34, r4
    mov.l   .L_fn_handler_slot35_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x35, r4
    mov.l   .L_fn_handler_slot36_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x36, r4
    mov.l   .L_fn_handler_slot37_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x37, r4
    mov.l   .L_fn_handler_slot38_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x38, r4
    mov.l   .L_fn_handler_slot39_e, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_slot32_e, r5
    mov.l   .L_fn_vdp1_sprite_render_5, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x39, r4
    bra     .L_init_second_table
    nop
.L_size_slot2F_e:
    .2byte  0x0310

    .global DAT_06023e50
DAT_06023e50:
    .2byte  0x090C

    .global DAT_06023e52
DAT_06023e52:
    .2byte  0x080C
.L_size_slot32_e:
    .2byte  0x0108
    .2byte  0xFFFF
.L_fn_vdp1_sprite_render_5:
    .4byte  vdp1_sprite_render
.L_fn_handler_slot30_e:
    .4byte  0x002A2194
.L_fn_handler_slot31_e:
    .4byte  0x002A225C
.L_fn_handler_slot32_e:
    .4byte  0x002A22F4
.L_fn_handler_slot33_e:
    .4byte  0x002A22FC
.L_fn_handler_slot34_e:
    .4byte  0x002A2304
.L_fn_handler_slot35_e:
    .4byte  0x002A230C
.L_fn_handler_slot36_e:
    .4byte  0x002A2314
.L_fn_handler_slot37_e:
    .4byte  0x002A231C
.L_fn_handler_slot38_e:
    .4byte  0x002A2324
.L_fn_handler_slot39_e:
    .4byte  0x002A232C
.L_init_second_table:
    mov.l   .L_scene_table_idx, r2
    mov #0x1, r3
    mov #0x0, r6
    mov r3, r5
    mov.w r3, @r2
    mov #0x40, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov #0x0, r6
    mov #0x3, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov #0x4, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov #0x0, r6
    mov #0x5, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov #0x6, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x4, r6
    mov #0x7, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov #0x8, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov #0x0, r6
    mov #0x9, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov #0xA, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov #0x20, r6
    mov #0x10, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov #0x20, r6
    mov #0x11, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov #0x20, r6
    mov #0x12, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov #0x20, r6
    mov #0x13, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov #0x20, r6
    mov #0x14, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov #0x20, r6
    mov #0x15, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov #0x24, r6
    mov #0x16, r5
    mov.w @(6, r15), r0
    mov r0, r4
    extu.w r4, r4
    bra     .L_register_second_table
    add #0x16, r4
    .2byte  0xFFFF
.L_scene_table_idx:
    .4byte  sym_06089E46
.L_fn_register_handler:
    .4byte  sym_06007540
.L_register_second_table:
    mov.l   .L_fn_register_handler_2, r3
    jsr @r3
    nop
    mov #0x20, r6
    mov #0x17, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov #0x34, r6
    mov #0x18, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov #0x28, r6
    mov #0x19, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov #0x28, r6
    mov #0x1A, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov #0x28, r6
    mov #0x1B, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov #0x34, r6
    mov #0x1C, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov #0x28, r6
    mov #0x1D, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov #0x30, r6
    mov #0x1E, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1E, r4
    mov #0x30, r6
    mov #0x1F, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1F, r4
    mov #0x24, r6
    mov #0x20, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x20, r4
    mov #0x24, r6
    mov #0x21, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x21, r4
    mov #0x24, r6
    mov #0x22, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x22, r4
    mov #0x24, r6
    mov #0x23, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x23, r4
    mov #0x24, r6
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r6, r5
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x24, r4
    mov #0x2C, r6
    mov #0x25, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x25, r4
    mov #0x2C, r6
    mov #0x26, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x26, r4
    mov #0x24, r6
    mov #0x27, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_2, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x27, r4
    mov #0x2C, r6
    mov #0x28, r5
    bra     .L_register_second_cont
    nop
    .2byte  0xFFFF
.L_fn_register_handler_2:
    .4byte  sym_06007540
.L_register_second_cont:
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x28, r4
    mov #0x2C, r6
    mov #0x29, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x29, r4
    mov #0x2C, r6
    mov #0x2A, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2A, r4
    mov #0x2C, r6
    mov #0x2B, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2B, r4
    mov #0x24, r6
    mov #0x2C, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2C, r4
    mov #0x24, r6
    mov #0x2D, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2D, r4
    mov #0x2C, r6
    mov #0x2E, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2E, r4
    mov #0x2C, r6
    mov #0x2F, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2F, r4
    mov #0x2C, r6
    mov #0x30, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x30, r4
    mov #0x2C, r6
    mov #0x31, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x31, r4
    mov #0x2C, r6
    mov #0x32, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x32, r4
    mov #0x2C, r6
    mov #0x33, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x33, r4
    mov #0x2C, r6
    mov #0x34, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x34, r4
    mov #0x2C, r6
    mov #0x35, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x35, r4
    mov #0x28, r6
    mov #0x36, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x36, r4
    mov #0x34, r6
    mov #0x37, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x37, r4
    mov #0x20, r6
    mov #0x38, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_3, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x38, r4
    mov #0x28, r6
    mov #0x39, r5
    mov.w @(6, r15), r0
    mov r0, r4
    extu.w r4, r4
    bra     .L_init_obj_layer
    add #0x39, r4
    .2byte  0xFFFF
.L_fn_register_handler_3:
    .4byte  sym_06007540
.L_init_obj_layer:
    mov.l   .L_fn_register_handler_4, r3
    jsr @r3
    nop
    mov #0x38, r3
    mov #0x40, r6
    mov.l   .L_obj_layer_table_base, r2
    mov.w r3, @r2
    mov #0x0, r3
    mov.w   DAT_060242e0, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_fn_obj_handler_slot10, r7
    mov.w   .L_size_obj_slot, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_fn_obj_handler_slot11, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_obj_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov.l   .L_fn_obj_handler_slot12, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_obj_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_fn_obj_handler_slot13, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_obj_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_obj_layer_idx, r2
    mov #0x3A, r3
    mov.w r3, @r2
    mov #0xE, r3
    mov.w   DAT_060242e4, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_game_variant_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_variant_flag_zero
    mov.l   .L_fn_variant_handler_0, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_variant_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    jsr @r3
    extu.w r4, r4
    mov.l   .L_fn_variant_handler_1, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_variant_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov.l   .L_fn_variant_handler_2, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_variant_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_fn_variant_handler_3, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_variant_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_6, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    bra     .L_check_multiplayer
    nop

    .global DAT_060242e0
DAT_060242e0:
    .2byte  0x0E00
.L_size_obj_slot:
    .2byte  0x0630

    .global DAT_060242e4
DAT_060242e4:
    .2byte  0x0E82
.L_size_variant_slot:
    .2byte  0x0210
.L_fn_register_handler_4:
    .4byte  sym_06007540
.L_obj_layer_table_base:
    .4byte  sym_06089E9C
.L_fn_obj_handler_slot10:
    .4byte  0x002A3987
.L_fn_vdp1_sprite_render_6:
    .4byte  vdp1_sprite_render
.L_fn_obj_handler_slot11:
    .4byte  0x002A3C2F
.L_fn_obj_handler_slot12:
    .4byte  0x002A3D23
.L_fn_obj_handler_slot13:
    .4byte  0x002A3E23
.L_obj_layer_idx:
    .4byte  sym_06089EA0
.L_game_variant_flag:
    .4byte  sym_0607EAB8
.L_fn_variant_handler_0:
    .4byte  0x002A43A6
.L_fn_variant_handler_1:
    .4byte  0x002A43D8
.L_fn_variant_handler_2:
    .4byte  0x002A4450
.L_fn_variant_handler_3:
    .4byte  0x002A44BF
.L_variant_flag_zero:
    mov.l   .L_fn_fallback_handler_0, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    jsr @r3
    extu.w r4, r4
    mov.l   .L_fn_fallback_handler_1, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov.l   .L_fn_fallback_handler_2, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_fn_fallback_handler_3, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
.L_check_multiplayer:
    mov.l   .L_multiplayer_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_single_player_path
    mov.l   .L_fn_multi_handler_4, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_fn_multi_handler_5, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov.l   .L_fn_multi_handler_6, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_fn_multi_handler_7, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_fallback_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_7, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    bra     .L_after_mode_handlers
    nop
.L_size_fallback_slot:
    .2byte  0x0210
    .2byte  0xFFFF
.L_fn_fallback_handler_0:
    .4byte  0x002A452A
.L_fn_vdp1_sprite_render_7:
    .4byte  vdp1_sprite_render
.L_fn_fallback_handler_1:
    .4byte  0x002A455C
.L_fn_fallback_handler_2:
    .4byte  0x002A45CD
.L_fn_fallback_handler_3:
    .4byte  0x002A463C
.L_multiplayer_flag:
    .4byte  sym_06078635
.L_fn_multi_handler_4:
    .4byte  0x002A46AC
.L_fn_multi_handler_5:
    .4byte  0x002A46DE
.L_fn_multi_handler_6:
    .4byte  0x002A4753
.L_fn_multi_handler_7:
    .4byte  0x002A47C4
.L_single_player_path:
    mov.l   .L_fn_single_handler_4, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_fn_single_handler_5, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov.l   .L_fn_single_handler_6, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_fn_single_handler_7, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov.l   .L_fn_single_handler_8, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov.l   .L_fn_single_handler_9, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov.l   .L_fn_single_handler_A, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_fn_single_handler_B, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_single_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xB, r4
.L_after_mode_handlers:
    mov.l   .L_course_type_flag, r0
    bra     .L_course_type_switch
    mov.l @r0, r0
.L_course_type_0:
    mov #0x38, r6
    mov.w   .L_size_course_slot, r5
    mov.l   .L_fn_course0_handler_C, r7
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_register_entities
    nop
.L_course_type_1:
    mov.l   .L_fn_course1_handler_C, r7
    mov #0x38, r6
    mov.w   .L_size_course_slot, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_register_entities
    nop
.L_size_single_slot:
    .2byte  0x0210
.L_size_course_slot:
    .2byte  0x0940
    .2byte  0xFFFF
.L_fn_single_handler_4:
    .4byte  0x002A4836
.L_fn_vdp1_sprite_render_8:
    .4byte  vdp1_sprite_render
.L_fn_single_handler_5:
    .4byte  0x002A4862
.L_fn_single_handler_6:
    .4byte  0x002A48CF
.L_fn_single_handler_7:
    .4byte  0x002A4946
.L_fn_single_handler_8:
    .4byte  0x002A49B3
.L_fn_single_handler_9:
    .4byte  0x002A49F0
.L_fn_single_handler_A:
    .4byte  0x002A4A61
.L_fn_single_handler_B:
    .4byte  0x002A4AD7
.L_course_type_flag:
    .4byte  sym_0607EAD8
.L_fn_course0_handler_C:
    .4byte  0x002A3F1F
.L_fn_course1_handler_C:
    .4byte  0x002A405A
.L_course_type_2:
    mov.l   .L_fn_course2_handler_C, r7
    mov #0x38, r6
    mov.w   .L_size_course2_slot, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_9, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_register_entities
    nop
.L_size_course2_slot:
    .2byte  0x0C40
.L_fn_course2_handler_C:
    .4byte  0x002A41C5
.L_fn_vdp1_sprite_render_9:
    .4byte  vdp1_sprite_render
.L_course_type_switch:
    cmp/eq #0x0, r0
    bt      .L_course_type_0
    cmp/eq #0x1, r0
    bt      .L_course_type_1
    cmp/eq #0x2, r0
    bt      .L_course_type_2
.L_register_entities:
    mov.l   .L_fn_entity_handler_0, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   DAT_0602461e, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_entity_callback_src, r2
    mov.l   .L_entity_callback_dst, r3
    mov.l @r2, r2
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    add #-0x1, r2
    mov.l r2, @r3
    mov.l   .L_fn_entity_handler_1, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   .L_entity_id_98, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_2, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   .L_entity_id_99, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_3, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   DAT_06024624, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_4, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   .L_entity_id_9B, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_5, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   DAT_06024628, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov #0x50, r6
    mov.w   DAT_06024624, r5
    mov.l   .L_fn_register_handler_5, r3
    mov r5, r4
    jsr @r3
    add #0x3, r4
    mov.l   .L_fn_entity_handler_6, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   DAT_0602462a, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_7, r7
    mov.w   .L_size_entity_slot, r5
    mov.w   DAT_0602462c, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_fn_entity_handler_8, r7
    mov.w   .L_size_entity_sm, r5
    mov.w   .L_entity_id_90, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x44, r6
    mov.l   .L_fn_entity_handler_9, r7
    mov.w   .L_size_entity_md, r5
    mov.w   .L_entity_id_91, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x44, r6
    mov.l   .L_fn_entity_handler_A, r7
    mov.w   .L_size_entity_lg, r5
    mov.w   DAT_06024638, r4
    mov.l   .L_fn_vdp1_sprite_render_10, r3
    jsr @r3
    mov #0x48, r6
    mov #0x4C, r6
    mov.w   DAT_06024638, r5
    mov.l   .L_fn_register_handler_5, r3
    mov r5, r4
    jsr @r3
    add #0x1, r4
    mov #0x50, r6
    mov.w   DAT_06024638, r5
    bra     .L_register_final_table
    nop
.L_size_entity_slot:
    .2byte  0x0418

    .global DAT_0602461e
DAT_0602461e:
    .2byte  0x0E97
.L_entity_id_98:
    .2byte  0x0E98
.L_entity_id_99:
    .2byte  0x0E99

    .global DAT_06024624
DAT_06024624:
    .2byte  0x0E9A
.L_entity_id_9B:
    .2byte  0x0E9B

    .global DAT_06024628
DAT_06024628:
    .2byte  0x0E9C

    .global DAT_0602462a
DAT_0602462a:
    .2byte  0x0E9E

    .global DAT_0602462c
DAT_0602462c:
    .2byte  0x0E9F
.L_size_entity_sm:
    .2byte  0x0110
.L_entity_id_90:
    .2byte  0x0E90
.L_size_entity_md:
    .2byte  0x0210
.L_entity_id_91:
    .2byte  0x0E91
.L_size_entity_lg:
    .2byte  0x0420

    .global DAT_06024638
DAT_06024638:
    .2byte  0x0E92
    .2byte  0xFFFF
.L_fn_entity_handler_0:
    .4byte  0x002A7A5E
.L_fn_vdp1_sprite_render_10:
    .4byte  vdp1_sprite_render
.L_entity_callback_src:
    .4byte  sym_0606A4F4
.L_entity_callback_dst:
    .4byte  sym_06085F98
.L_fn_entity_handler_1:
    .4byte  0x002A7AC5
.L_fn_entity_handler_2:
    .4byte  0x002A7B1F
.L_fn_entity_handler_3:
    .4byte  0x002A7BA0
.L_fn_entity_handler_4:
    .4byte  0x002A7BE9
.L_fn_entity_handler_5:
    .4byte  0x002A7C3B
.L_fn_register_handler_5:
    .4byte  sym_06007540
.L_fn_entity_handler_6:
    .4byte  0x002A7CA5
.L_fn_entity_handler_7:
    .4byte  0x002A7CFA
.L_fn_entity_handler_8:
    .4byte  0x002A8B47
.L_fn_entity_handler_9:
    .4byte  0x002A8B7E
.L_fn_entity_handler_A:
    .4byte  0x002A8BBB
.L_register_final_table:
    mov r5, r4
    mov.l   .L_fn_register_handler_6, r3
    jsr @r3
    add #0x2, r4
    mov #0x54, r6
    mov.w   DAT_06024782, r5
    mov.l   .L_fn_register_handler_6, r3
    mov r5, r4
    jsr @r3
    add #0x3, r4
    mov.l   .L_fn_scene_anim_handler, r7
    mov.w   DAT_06024784, r5
    mov.w   DAT_06024786, r4
    mov.l   .L_fn_vdp1_sprite_render_11, r3
    jsr @r3
    mov #0x58, r6
    mov.l   .L_final_table_idx, r2
    mov #0x39, r3
    mov #0x0, r6
    mov #0x1, r5
    mov.w r3, @r2
    mov #0x18, r3
    mov.w   DAT_06024788, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov #0x0, r6
    mov #0x3, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov #0x4, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov #0x0, r6
    mov #0x5, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov #0x6, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x4, r6
    mov #0x7, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov #0x8, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov #0x0, r6
    mov #0x9, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov #0xA, r5
    mov.w @(6, r15), r0
    mov.l   .L_fn_register_handler_6, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_fn_final_handler_10, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_final_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_11, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_fn_final_handler_11, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_final_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_11, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    bra     .L_register_render_layer
    nop

    .global DAT_06024782
DAT_06024782:
    .2byte  0x0E92

    .global DAT_06024784
DAT_06024784:
    .2byte  0x1020

    .global DAT_06024786
DAT_06024786:
    .2byte  0x0E96

    .global DAT_06024788
DAT_06024788:
    .2byte  0x0E40
.L_size_final_slot:
    .2byte  0x0108
.L_fn_register_handler_6:
    .4byte  sym_06007540
.L_fn_scene_anim_handler:
    .4byte  0x002A92CB
.L_fn_vdp1_sprite_render_11:
    .4byte  vdp1_sprite_render
.L_final_table_idx:
    .4byte  sym_06089E9E
.L_fn_final_handler_10:
    .4byte  0x002A7D76
.L_fn_final_handler_11:
    .4byte  0x002A7D8E
.L_register_render_layer:
    mov.l   .L_fn_render_handler_12, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_fn_render_handler_13, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_fn_render_handler_14, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov.l   .L_fn_render_handler_15, r7
    mov.w @(4, r15), r0
    mov.w   DAT_060248bc, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov.l   .L_fn_render_handler_16, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x16, r4
    mov.l   .L_fn_render_handler_17, r7
    mov.w @(4, r15), r0
    mov.w   DAT_060248be, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov.l   .L_fn_render_handler_18, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov.l   .L_fn_render_handler_19, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov.l   .L_fn_render_handler_1A, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot_lg, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov.l   .L_fn_render_handler_1B, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_render_slot, r5
    mov.l   .L_fn_vdp1_sprite_render_12, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov.l   .L_fn_render_handler_1C, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x3, r6
    shll2 r6
    mov.w   .L_size_render_slot, r5
    bra     .L_register_final_batch
    nop
.L_size_render_slot:
    .2byte  0x0108

    .global DAT_060248bc
DAT_060248bc:
    .2byte  0x010C

    .global DAT_060248be
DAT_060248be:
    .2byte  0x040C
.L_size_render_slot_lg:
    .2byte  0x0208
    .2byte  0xFFFF
.L_fn_render_handler_12:
    .4byte  0x002A7DA6
.L_fn_vdp1_sprite_render_12:
    .4byte  vdp1_sprite_render
.L_fn_render_handler_13:
    .4byte  0x002A7DC6
.L_fn_render_handler_14:
    .4byte  0x002A7DE6
.L_fn_render_handler_15:
    .4byte  0x002A7DF2
.L_fn_render_handler_16:
    .4byte  0x002A7E0A
.L_fn_render_handler_17:
    .4byte  0x002A7E16
.L_fn_render_handler_18:
    .4byte  0x002A7E9E
.L_fn_render_handler_19:
    .4byte  0x002A7EB6
.L_fn_render_handler_1A:
    .4byte  0x002A7ECA
.L_fn_render_handler_1B:
    .4byte  0x002A7EFE
.L_fn_render_handler_1C:
    .4byte  0x002A7F0A
.L_register_final_batch:
    mov.w @(6, r15), r0
    mov.l   .L_fn_vdp1_sprite_render_13, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov.l   .L_fn_final_batch_1D, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_final_batch, r5
    mov.l   .L_fn_vdp1_sprite_render_13, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov.l   .L_fn_final_batch_1E, r7
    mov.w @(4, r15), r0
    mov.w   .L_size_final_batch, r5
    mov.l   .L_fn_vdp1_sprite_render_13, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    .4byte  0x4608644D
    .4byte  0x430B741E
    .4byte  0xD73985F2
    .4byte  0x9566D335
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x741FD734
    .4byte  0x85F2955A
    .4byte  0xD32E6603
    .4byte  0x666D85F3
    .4byte  0x76016403
    .4byte  0x4608644D
    .4byte  0x430B7420
    .4byte  0xD72E85F2
    .4byte  0x954ED328
    .4byte  0x6603666D
    .4byte  0x85F37603
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x7421D729
    .4byte  0x85F29542
    .4byte  0xD3216603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7422D724
    .4byte  0x85F29536
    .4byte  0xD31B6603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7423D71F
    .4byte  0x85F2952A
    .4byte  0xD3156603
    .4byte  0x666D85F3
    .4byte  0x76026403
    .4byte  0x4608644D
    .4byte  0x430B7424
    .4byte  0xD71985F2
    .4byte  0x9519D30F
    .4byte  0x6603666D
    .4byte  0x85F37603
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x7425D714
    .4byte  0x85F2950C
    .4byte  0xD3086603
    .4byte  0x666D85F3
    .4byte  0x76036403
    .4byte  0x4608644D
    .4byte  0x430B7426
    .4byte  0xD70EA01D
    .2byte  0x0009
.L_size_final_batch:
    .2byte  0x0108

    .global DAT_06024a08
DAT_06024a08:
    .2byte  0x011C

    .global DAT_06024a0a
DAT_06024a0a:
    .2byte  0x021C
    .4byte  0x05080210
.L_fn_vdp1_sprite_render_13:
    .4byte  vdp1_sprite_render
.L_fn_final_batch_1D:
    .4byte  0x002A7F12
.L_fn_final_batch_1E:
    .4byte  0x002A7F1A
    .4byte  0x002A7F3A
    .4byte  0x002A7FB6
    .4byte  0x002A8072
    .4byte  0x002A80FA
    .4byte  0x002A8172
    .4byte  0x002A81F6
    .4byte  0x002A8276
    .4byte  0x002A8292
    .4byte  0x002A829A
    .4byte  0x85F29586
    .4byte  0xD3456603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7427D742
    .4byte  0x85F2957A
    .4byte  0xD33F6603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7428D73D
    .4byte  0x85F2956E
    .4byte  0xD3396603
    .4byte  0x666D85F3
    .4byte  0x76036403
    .4byte  0x4608644D
    .4byte  0x430B7429
    .4byte  0xD73785F2
    .4byte  0x9561D333
    .4byte  0x6603666D
    .4byte  0x85F37603
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x742AD732
    .4byte  0x85F29555
    .4byte  0xD32C6603
    .4byte  0x666D85F3
    .4byte  0x76016403
    .4byte  0x4608644D
    .4byte  0x430B742B
    .4byte  0xD72C85F2
    .4byte  0x9549D326
    .4byte  0x6603666D
    .4byte  0x85F37603
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x742CD727
    .4byte  0x85F2953D
    .4byte  0xD31F6603
    .4byte  0x666D85F3
    .4byte  0x76036403
    .4byte  0x4608644D
    .4byte  0x430B742D
    .4byte  0xD72185F2
    .4byte  0x952DD319
    .4byte  0x6603666D
    .4byte  0x85F37603
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x742ED71C
    .4byte  0x85F29524
    .4byte  0xD3126603
    .4byte  0x666D85F3
    .4byte  0x76036403
    .4byte  0x4608644D
    .4byte  0x430B742F
    .4byte  0xD71685F2
    .4byte  0x9515D30C
    .4byte  0x6603666D
    .4byte  0x85F34608
    .4byte  0x6403644D
    .4byte  0x430B7430
    .4byte  0xD71185F2
    .4byte  0x6603666D
    .4byte  0x46089508
    .4byte  0x85F36403
    .4byte  0x644DA01B
    .4byte  0x74310108

    .global DAT_06024b54
DAT_06024b54:
    .4byte  0x021C0320
    .4byte  0x01200308
    .4byte  vdp1_sprite_render
    .4byte  0x002A82A2
    .4byte  0x002A82B2
    .4byte  0x002A82BA
    .4byte  0x002A82CE
    .4byte  0x002A8372
    .4byte  0x002A84BE
    .4byte  0x002A854A
    .4byte  0x002A8572
    .4byte  0x002A85C6
    .4byte  0x002A86EE
    .4byte  0xD347430B
    .4byte  0x0009D747
    .4byte  0x85F29583
    .4byte  0xD3446603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7432D742
    .4byte  0x85F29577
    .4byte  0xD33E6603
    .4byte  0x666D85F3
    .4byte  0x46086403
    .4byte  0x644D430B
    .4byte  0x7433D73D
    .4byte  0x85F2956B
    .4byte  0xD3386603
    .4byte  0x666D85F3
    .4byte  0x76026403
    .4byte  0x4608644D
    .4byte  0x430B7434
    .4byte  0xD73785F2
    .4byte  0x955FD332
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x7439D732
    .4byte  0x85F29552
    .4byte  0xD32B6603
    .4byte  0x666D85F3
    .4byte  0x76016403
    .4byte  0x4608644D
    .4byte  0x430B743A
    .4byte  0xD72C85F2
    .4byte  0x9546D325
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x743BD727
    .4byte  0x85F2953A
    .4byte  0xD31E6603
    .4byte  0x666D85F3
    .4byte  0x76016403
    .4byte  0x4608644D
    .4byte  0x430B7435
    .4byte  0xD72185F2
    .4byte  0x952ED318
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x7436D71C
    .4byte  0x85F29520
    .4byte  0xD3116603
    .4byte  0x666D85F3
    .4byte  0x76016403
    .4byte  0x4608644D
    .4byte  0x430B7437
    .4byte  0xD71685F2
    .4byte  0x9514D30B
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x7438D711
    .4byte  0x85F26603
    .4byte  0x666D7601
    .4byte  0xA01E0009
    .2byte  0x0110

    .global DAT_06024c9e
DAT_06024c9e:
    .2byte  0x0116

    .global DAT_06024ca0
DAT_06024ca0:
    .2byte  0x0216

    .global DAT_06024ca2
DAT_06024ca2:
    .2byte  0x020A
    .4byte  0x020CFFFF
    .4byte  vdp1_sprite_render
    .4byte  0x002A873E
    .4byte  0x002A878A
    .4byte  0x002A87C6
    .4byte  0x002A8812
    .4byte  0x002A8852
    .4byte  0x002A8896
    .4byte  0x002A8906
    .4byte  0x002A8926
    .4byte  0x002A897E
    .4byte  0x002A89A6
    .4byte  0x002A89F6
    .4byte  0x46089516
    .4byte  0x85F3D30B
    .4byte  0x6403644D
    .4byte  0x430B743C
    .4byte  0xD70985F2
    .4byte  0x950DD307
    .4byte  0x6603666D
    .4byte  0x85F37601
    .4byte  0x64034608
    .4byte  0x644D430B
    .4byte  0x743D7F08
    .4byte  0x4F26000B
    .4byte  0x00090108
    .4byte  vdp1_sprite_render
    .4byte  0x002A8A06
