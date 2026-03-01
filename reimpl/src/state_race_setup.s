
    .section .text.FUN_06008EBC


    .global state_race_setup
    .type state_race_setup, @function
state_race_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x3, r13
    mov.l   .L_06008F3C, r3
    jsr @r3
    mov #0x0, r14
    extu.b r14, r2
    mov.l   .L_06008F40, r3
    mov #0x1, r6
    mov #0x8, r0
    mov.b r2, @r3
    extu.b r6, r1
    mov.l   .L_06008F44, r3
    mov.b r1, @r3
    mov.l   .L_06008F48, r3
    mov.l r0, @r3
    mov.l   .L_06008F4C, r0
    mov.l   .L_06008F50, r3
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq r3, r0
    bf      .L_06008F82
    mov.l   .L_06008F54, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06008F82
    mov.l   .L_06008F58, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_06008F82
    mov.l   .L_06008F5C, r4
    mov.l   .L_06008F60, r5
    mov.l   .L_06008F64, r2
    mov.w @r4, r4
    mov.w @r2, r2
    exts.w r4, r3
    extu.w r2, r2
    and r2, r3
    tst r3, r3
    bt      .L_06008F12
    bra     .L_06008F82
    mov.b r14, @r5
.L_06008F12:
    exts.w r4, r2
    mov.l   .L_06008F68, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_06008F26
    exts.b r6, r6
    bra     .L_06008F82
    mov.b r6, @r5
.L_06008F26:
    exts.w r4, r2
    mov.l   .L_06008F6C, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_06008F70
    mov #0x2, r3
    mov.b r3, @r5
    bra     .L_06008F82
    nop
.L_06008F3C:
    .4byte  race_resource_init         /* course/car resource loader */
.L_06008F40:
    .4byte  sym_06078635               /* race result (0=in progress) */
.L_06008F44:
    .4byte  sym_06078634               /* race active flag (1=active) */
.L_06008F48:
    .4byte  sym_0607ED88               /* physics warmup frame counter */
.L_06008F4C:
    .4byte  sym_0607865E               /* game mode selector (16-bit) */
.L_06008F50:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_06008F54:
    .4byte  sym_0605AD08               /* special game mode flag */
.L_06008F58:
    .4byte  sym_0605AB18               /* menu overlay active flag (byte) */
.L_06008F5C:
    .4byte  g_pad_state               /* input/status register (16-bit) */
.L_06008F60:
    .4byte  sym_06078648               /* current course index (byte) */
.L_06008F64:
    .4byte  sym_06078656               /* course 0 selection bit mask */
.L_06008F68:
    .4byte  sym_06078658               /* course 1 selection bit mask */
.L_06008F6C:
    .4byte  sym_0607865A               /* course 2 selection bit mask */
.L_06008F70:
    exts.w r4, r4
    mov.l   .L_0600902C, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r2, r4
    tst r4, r4
    bt      .L_06008F82
    exts.b r13, r3
    mov.b r3, @r5
.L_06008F82:
    mov.l   .L_06009030, r3
    jsr @r3
    nop
    mov.l   .L_06009034, r3
    jsr @r3
    nop
    exts.b r13, r2
    mov.l   .L_06009038, r4
    mov.b r2, @r4
    mov.l   .L_0600903C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06008FAC
    mov.l   .L_06009040, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06008FAC
    mov #0x4, r3
    mov.b r3, @r4
.L_06008FAC:
    mov.l   .L_06009044, r3
    jsr @r3
    nop
    mov.l   .L_06009048, r4
    mov.l   .L_0600904C, r3
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov.l   .L_06009050, r3
    jsr @r3
    nop
    mov.l   .L_06009054, r3
    jsr @r3
    nop
    mov.w   .L_06009028, r2
    mov.l   .L_06009058, r3
    mov.l r2, @r3
    mov.l   .L_0600905C, r4
    mov.l   .L_06009060, r3
    mov.l   .L_06009064, r2
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_06009068, r3
    jsr @r3
    nop
    mov.l   .L_0600906C, r3
    jsr @r3
    nop
    mov.l   .L_06009070, r3
    jsr @r3
    nop
    mov.l   .L_06009074, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06008FFE
    mov.l   .L_06009078, r3
    jsr @r3
    mov #0x1, r4
.L_06008FFE:
    mov #0xF, r2
    mov.l   .L_0600907C, r3
    mov.l r2, @r3
    mov.l   .L_06009080, r4
    mov.l   .L_06009084, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_06009088, r3
    jsr @r3
    nop
    mov.l   .L_0600908C, r3
    mov.l r14, @r3
    mov.l   .L_06009090, r3
    mov.w r13, @r3
    mov.l   .L_06009094, r3
    mov.b r14, @r3
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06009028:
    .2byte  0x0096                        /* 150 frames countdown */
    .2byte  0xFFFF                        /* padding for 4-byte alignment */
.L_0600902C:
    .4byte  sym_0607865C               /* course 3 selection bit mask */
.L_06009030:
    .4byte  vdp2_config_extended       /* VDP2 extended configuration */
.L_06009034:
    .4byte  geom_output_finalize       /* geometry output finalization */
.L_06009038:
    .4byte  sym_06078662               /* sound mode (3=normal, 4=enhanced) */
.L_0600903C:
    .4byte  sym_06078635               /* race result byte (dup for reach) */
.L_06009040:
    .4byte  sym_0607ED8C               /* mode register (16-bit) */
.L_06009044:
    .4byte  race_init_master           /* race state machine initialization */
.L_06009048:
    .4byte  sym_0607ED91               /* HUD variant index (byte) */
.L_0600904C:
    .4byte  hud_post_update            /* HUD post-update handler */
.L_06009050:
    .4byte  hud_subsystem_init         /* HUD subsystem initialization */
.L_06009054:
    .4byte  disp_init_setup            /* display initialization */
.L_06009058:
    .4byte  sym_0607EBCC               /* race countdown timer */
.L_0600905C:
    .4byte  sym_0607EAD8               /* race end state (dispatch index) */
.L_06009060:
    .4byte  sym_0605E158               /* race variant function table */
.L_06009064:
    .4byte  sym_060054EA               /* variant setup dispatch function */
.L_06009068:
    .4byte  race_start_init            /* race start sequence initialization */
.L_0600906C:
    .4byte  bg_layer_init              /* background layer initialization */
.L_06009070:
    .4byte  geom_matrix_setup          /* geometry matrix initialization */
.L_06009074:
    .4byte  sym_0605AB18               /* overlay active flag (dup for reach) */
.L_06009078:
    .4byte  menu_overlay_render        /* menu overlay renderer */
.L_0600907C:
    .4byte  g_game_state               /* game phase state */
.L_06009080:
    .4byte  sym_0605B6D8               /* global render flags */
.L_06009084:
    .4byte  0x40000000                  /* bit 30: race render enable */
.L_06009088:
    .4byte  sym_06026CE0               /* initialization finalization */
.L_0600908C:
    .4byte  sym_06059F44               /* camera follow mode flag */
.L_06009090:
    .4byte  sym_0605A016               /* game state word (16-bit) */
.L_06009094:
    .4byte  sym_0607864A               /* course loaded flag (byte) */
