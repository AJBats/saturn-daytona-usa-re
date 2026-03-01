
    .section .text.FUN_06009C48


    .global state_post_race_cleanup
    .type state_post_race_cleanup, @function
state_post_race_cleanup:
    sts.l pr, @-r15
    mov.l   .L_06009CB8, r3
    jsr @r3
    nop
    mov.l   .L_06009CBC, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009C6C
    mov.l   .L_06009CC0, r3
    jsr @r3
    nop
    mov.l   .L_06009CC4, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009C6C
    mov.l   .L_06009CC8, r3
    jsr @r3
    nop
.L_06009C6C:
    mov.l   .L_06009CCC, r3
    jsr @r3
    nop
    mov.l   .L_06009CD0, r3
    jsr @r3
    nop
    mov.l   .L_06009CD4, r3
    jsr @r3
    nop
    mov.l   .L_06009CD8, r6
    mov.l   .L_06009CDC, r5
    mov.l   .L_06009CE0, r4
    mov.l   .L_06009CE4, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_06009CE8, r3
    jsr @r3
    nop
    mov.l   .L_06009CEC, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06009CA0
    mov.l   .L_06009CF0, r3
    jsr @r3
    nop
.L_06009CA0:
    mov.l   .L_06009CF4, r2
    mov.w   .L_06009CB6, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_06009CB0
    .byte   0xB1, 0xEA    /* bsr 0x0600A084 (replay_record */
    nop
.L_06009CB0:
    mov.l   .L_06009CF8, r3
    jmp @r3
    lds.l @r15+, pr
.L_06009CB6:
    .2byte  0x00BC                           /* car struct replay data offset */
.L_06009CB8:
    .4byte  util_wrapper                     /* per-frame utility wrapper */
.L_06009CBC:
    .4byte  sym_0607EAE0                     /* camera active flag (dword) */
.L_06009CC0:
    .4byte  camera_special_mode              /* post-race camera flyover */
.L_06009CC4:
    .4byte  sym_0607EAD8                     /* race end state (0/1/2) */
.L_06009CC8:
    .4byte  replay_camera_ctrl               /* replay camera controller */
.L_06009CCC:
    .4byte  update_mode_dispatch             /* mode-specific update dispatch */
.L_06009CD0:
    .4byte  car_proximity_check              /* car proximity/collision detect */
.L_06009CD4:
    .4byte  camera_system                    /* main camera pipeline */
.L_06009CD8:
    .4byte  sym_06063E24                     /* camera eye position (ptr to vec3) */
.L_06009CDC:
    .4byte  sym_06063EEC                     /* camera look-at target vector */
.L_06009CE0:
    .4byte  sym_06063EF8                     /* camera up vector */
.L_06009CE4:
    .4byte  camera_orient_calc               /* camera orientation matrix calc */
.L_06009CE8:
    .4byte  scene_master                     /* master scene render pipeline */
.L_06009CEC:
    .4byte  sym_0607ED8C                     /* extended display enable (16-bit) */
.L_06009CF0:
    .4byte  sym_060033E6                     /* extended display handler */
.L_06009CF4:
    .4byte  sym_0607E944                     /* player car struct pointer */
.L_06009CF8:
    .4byte  frame_end_commit                 /* frame end commit (tail-call) */
