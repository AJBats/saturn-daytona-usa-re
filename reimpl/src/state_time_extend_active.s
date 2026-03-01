
    .section .text.FUN_06009788


    .global state_time_extend_active
    .type state_time_extend_active, @function
state_time_extend_active:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_060097E4, r8
    mov.l   .L_060097E8, r10
    mov.l   .L_060097EC, r11
    mov.l   .L_060097F0, r12
    mov.l   .L_060097F4, r4
    mov.w @(2, r4), r0
    mov r0, r3
    mov.w r3, @r15
    mov.w @r4, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_060097F8, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060097BE
    mov.l   .L_060097FC, r3
    jsr @r3
    mov #0x0, r4
.L_060097BE:
    mov.l   .L_06009800, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600983E
    mov.w @r15, r3
    mov.l   .L_06009804, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06009808
    mov #0x63, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_06009824
    mov.b @r12, r2
    add #0x1, r2
    bra     .L_06009824
    mov.b r2, @r12
.L_060097E4:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_060097E8:
    .4byte  sym_0605B6D8               /* render mode flags (32-bit) */
.L_060097EC:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_060097F0:
    .4byte  sym_06078649               /* time extend value (byte, 0-99) */
.L_060097F4:
    .4byte  g_pad_state               /* input data (pressed + held) */
.L_060097F8:
    .4byte  sym_0605AB18               /* overlay active flag (byte) */
.L_060097FC:
    .4byte  menu_overlay_render        /* menu overlay render function */
.L_06009800:
    .4byte  sym_0607864A               /* time extend mode flag (byte) */
.L_06009804:
    .4byte  0x00008000                  /* Up button mask */
.L_06009808:
    mov.w @r15, r2
    mov.w   .L_060098D4, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06009824
    mov #0x1, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_06009824
    mov.b @r12, r2
    add #-0x1, r2
    mov.b r2, @r12
.L_06009824:
    mov.b @r12, r7
    mov r8, r6
    mov.w   .L_060098D6, r5
    mov.l   .L_060098E4, r3
    extu.b r7, r7
    jsr @r3
    mov #0x8, r4
    mov r8, r6
    mov.w   .L_060098D8, r5
    mov.l   .L_060098E8, r7
    mov.l   .L_060098EC, r3
    jsr @r3
    mov #0x8, r4
.L_0600983E:
    mov.w   .L_060098DA, r9
    mov.w   .L_060098DC, r13
    mov.l   .L_060098F0, r14
    mov.w @r15, r2
    mov.w   .L_060098DE, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06009920
    mov #0x14, r2
    mov.l   .L_060098F4, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/ge r2, r3
    bf      .L_06009920
    mov.l   .L_060098F8, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt      .L_06009920
    mov.l   .L_060098FC, r5
    mov.l   .L_06009900, r3
    jsr @r3
    mov #0x0, r4
    mov r13, r6
    mov.l   .L_06009904, r2
    mov.l r2, @r15
    mov r2, r7
    mov.w   .L_060098E0, r5
    add #0x3B, r7
    jsr @r14
    mov #0x8, r4
    mov r13, r6
    mov r9, r5
    mov.l @r15, r7
    add #0x28, r7
    jsr @r14
    mov #0x8, r4
    mov r13, r6
    mov.w   .L_060098E2, r5
    mov.l @r15, r7
    add #0x2E, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_06009908, r3
    mov.l   .L_0600990C, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov.l   .L_06009910, r3
    mov.l   .L_06009914, r2
    mov.b @r3, r3
    mov.b r3, @r2
    mov.l   .L_060098F8, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_060098B0
    bra     .L_060099F4
    nop
.L_060098B0:
    mov #0x0, r3
    mov #0xF, r6
    mov.l   .L_060098F8, r2
    mov.b r3, @r2
    mov.b @r12, r5
    extu.b r5, r5
    mov.l r5, @r15
    mov.l   .L_06009918, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_0600991C, r7
    mov r8, r6
    mov.w   .L_060098D8, r5
    mov.l   .L_060098EC, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_060099F4
    nop
.L_060098D4:
    .2byte  0x4000                        /* Down button mask */
.L_060098D6:
    .2byte  0x0CCC                        /* HUD sprite parameter A */
.L_060098D8:
    .2byte  0x0CB8                        /* HUD sprite parameter B */
.L_060098DA:
    .2byte  0x0694                        /* HUD coordinate A */
.L_060098DC:
    .2byte  0x0090                        /* HUD coordinate B */
.L_060098DE:
    .2byte  0x0800                        /* Start button mask */
.L_060098E0:
    .2byte  0x0526                        /* text sprite parameter A */
.L_060098E2:
    .2byte  0x079C                        /* text sprite parameter B */
.L_060098E4:
    .4byte  hud_number_display         /* HUD number display function */
.L_060098E8:
    .4byte  sym_060446E0               /* time extend graphics data A */
.L_060098EC:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_060098F0:
    .4byte  sym_060284AE               /* geometry element render */
.L_060098F4:
    .4byte  sym_06078650               /* time extend timer (16-bit) */
.L_060098F8:
    .4byte  sym_0607864A               /* time extend trigger flag (byte) */
.L_060098FC:
    .4byte  0xAE0004FF                  /* sound command: time extend */
.L_06009900:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_06009904:
    .4byte  sym_0605AC9C               /* time extend text/sprite data */
.L_06009908:
    .4byte  sym_0607EACC               /* countdown timer (32-bit) */
.L_0600990C:
    .4byte  g_game_state               /* game state dispatch value */
.L_06009910:
    .4byte  sym_06078652               /* extend mode lap byte */
.L_06009914:
    .4byte  sym_06078654               /* current lap count */
.L_06009918:
    .4byte  handler_dispatch           /* handler dispatch function */
.L_0600991C:
    .4byte  sym_060446EC               /* time extend graphics data B */
.L_06009920:
    mov #0x70, r4
    mov.w @(4, r15), r0
    mov r0, r2
    extu.w r2, r2
    and r4, r2
    cmp/eq r4, r2
    bf      .L_06009972
    .byte   0xB4, 0x43    /* bsr 0x0600A1B8 (external: end extend helper) */
    nop
    mov.l   .L_060099B8, r2
    mov.l @r10, r3
    or r2, r3
    mov.l r3, @r10
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06009962
    mov #0x1, r3
    mov.l   .L_060099BC, r2
    mov.l r3, @r2
    mov #0x2, r3
    mov #0x18, r2
    mov.w r3, @r11
    mov.l   .L_060099C0, r3
    mov.l r2, @r3
    mov.l   .L_060099C4, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_060099C8, r3
    mov.l r2, @r3
    bra     .L_060099F4
    nop
.L_06009962:
    mov #0x1, r2
    mov.l   .L_060099CC, r3
    mov.l r2, @r3
    mov #0xE, r2
    mov.l   .L_060099C0, r3
    mov.l r2, @r3
    bra     .L_060099F4
    nop
.L_06009972:
    mov.l   .L_060099D0, r4
    mov.w @r4, r0
    add #0x1, r0
    mov.w r0, @r4
    extu.w r0, r0
    tst #0x10, r0
    bt      .L_0600999C
    mov r13, r6
    mov r9, r5
    mov.l   .L_060099D4, r3
    mov.l r3, @r15
    mov r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l @r15, r7
    mov r13, r6
    mov.w   .L_060099B4, r5
    jsr @r14
    mov #0x8, r4
    bra     .L_060099F4
    nop
.L_0600999C:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060099E0
    mov r13, r6
    mov r9, r5
    mov.l   .L_060099D8, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_060099DC, r7
    bra     .L_060099EC
    nop
.L_060099B4:
    .2byte  0x0794                        /* text sprite parameter C */
    .2byte  0xFFFF
.L_060099B8:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_060099BC:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_060099C0:
    .4byte  g_game_state               /* game state dispatch value */
.L_060099C4:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_060099C8:
    .4byte  sym_06059F44               /* animation state (32-bit) */
.L_060099CC:
    .4byte  sym_0605AD08               /* game sub-state (32-bit) */
.L_060099D0:
    .4byte  sym_06078650               /* time extend timer (16-bit) */
.L_060099D4:
    .4byte  sym_0605ACC4               /* extend text/sprite data */
.L_060099D8:
    .4byte  sym_060446FC               /* extend special graphics */
.L_060099DC:
    .4byte  sym_06044718               /* extend alt graphics A */
.L_060099E0:
    mov.l   .L_06009A40, r7
    mov r13, r6
    mov r9, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_06009A44, r7
.L_060099EC:
    mov r13, r6
    mov.w   .L_06009A3C, r5
    jsr @r14
    mov #0x8, r4
.L_060099F4:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06009A02
    mov.l   .L_06009A48, r3
    jsr @r3
    nop
.L_06009A02:
    mov.l   .L_06009A4C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009A18
    mov r8, r6
    mov.w   .L_06009A3E, r5
    mov.l   .L_06009A50, r7
    mov.l   .L_06009A54, r3
    jsr @r3
    mov #0x8, r4
.L_06009A18:
    mov.l @r10, r0
    mov.l   .L_06009A58, r3
    or #0x4, r0
    jsr @r3
    mov.l r0, @r10
    mov #0x0, r2
    mov.l   .L_06009A5C, r3
    mov.l r2, @r3
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06009A3C:
    .2byte  0x079C                        /* sprite parameter D */
.L_06009A3E:
    .2byte  0x0082                        /* geometry tile size parameter */
.L_06009A40:
    .4byte  sym_060446FC               /* extend normal graphics */
.L_06009A44:
    .4byte  sym_0604472C               /* extend alt graphics B */
.L_06009A48:
    .4byte  sym_060033E6               /* special render function */
.L_06009A4C:
    .4byte  sym_06086030               /* geometry render enable (byte) */
.L_06009A50:
    .4byte  sym_0605A1C8               /* geometry data pointer */
.L_06009A54:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_06009A58:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_06009A5C:
    .4byte  sym_06059F44               /* animation state (32-bit) */
