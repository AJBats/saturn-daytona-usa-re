
    .section .text.FUN_0600893C


    .global attract_init_body
    .type attract_init_body, @function
attract_init_body:
    sts.l pr, @-r15
    mov #0x0, r14
    mov.l   .L_060089C4, r2
    extu.b r14, r0
    mov.b r3, @r2
    mov.l   .L_060089C8, r2
    mov.b r14, @r2
    mov.l   .L_060089CC, r2
    mov.w r14, @r2
    mov.l   .L_060089D0, r2
    mov.l   .L_060089D4, r3
    jsr @r3
    mov.b r0, @r2
    mov.l   .L_060089D8, r3
    jsr @r3
    nop
    mov.l   .L_060089DC, r3
    jsr @r3
    nop
    mov.l   .L_060089E0, r3
    jsr @r3
    nop
    mov.l   .L_060089E4, r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_06008978
    mov.l   .L_060089E8, r3
    jsr @r3
    nop
.L_06008978:
    extu.w r14, r2
    mov.l   .L_060089EC, r3
    mov.w r2, @r3
    mov.l   .L_060089F0, r4
    mov.w   .L_060089C2, r1
    mov.l r1, @r4
    mov.l   .L_060089F4, r3
    mov.l r14, @r3
    mov.l   .L_060089F8, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06008996
    mov.l @r4, r3
    add #-0x3C, r3
    mov.l r3, @r4
.L_06008996:
    mov.l   .L_060089FC, r3
    jsr @r3
    nop
    mov.l   .L_06008A00, r4
    mov.l   .L_06008A04, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov #0x3, r2
    mov.l   .L_06008A08, r3
    mov.l r2, @r3
    mov.l   .L_06008A0C, r3
    jsr @r3
    nop
    mov #0x4, r2
    mov.l   .L_06008A10, r3
    mov.l r14, @r3
    mov.l   .L_06008A14, r3
    mov.w r2, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060089C2:
    .2byte  0x0398
.L_060089C4:
    .4byte  sym_06078634
.L_060089C8:
    .4byte  sym_06078635
.L_060089CC:
    .4byte  sym_0607ED8C
.L_060089D0:
    .4byte  sym_0607864B
.L_060089D4:
    .4byte  vdp2_config_extended
.L_060089D8:
    .4byte  race_init_master
.L_060089DC:
    .4byte  hud_subsystem_init
.L_060089E0:
    .4byte  vdp1_init
.L_060089E4:
    .4byte  sym_06063DA0
.L_060089E8:
    .4byte  vdp_init_advanced
.L_060089EC:
    .4byte  sym_06087804
.L_060089F0:
    .4byte  sym_0607EBCC
.L_060089F4:
    .4byte  sym_0607EAE0
.L_060089F8:
    .4byte  sym_0607EAD8
.L_060089FC:
    .4byte  course_data_handler
.L_06008A00:
    .4byte  sym_0605B6D8
.L_06008A04:
    .4byte  0x40000000
.L_06008A08:
    .4byte  g_game_state
.L_06008A0C:
    .4byte  sym_06026CE0
.L_06008A10:
    .4byte  sym_06059F44
.L_06008A14:
    .4byte  sym_0605A016
