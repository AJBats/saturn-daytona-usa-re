
    .section .text.FUN_0600955E


    .global state_results_screen
    .type state_results_screen, @function
state_results_screen:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x0D    /* mov.l .L_0600959C, r14 */
    .byte   0xD3, 0x18    /* mov.l .L_060095C8, r3 */
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_06009596, r3
    and r3, r2
    tst r2, r2
    bt      .L_0600957E
    mov #0x1D, r3
    .byte   0xD2, 0x15    /* mov.l .L_060095CC, r2 */
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r14
.L_0600957E:
    .byte   0xD4, 0x06    /* mov.l .L_06009598, r4 */
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_060095D0
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r14
    bra     .L_060095E0
    nop
.L_06009596:
    .2byte  0x0800                        /* start button bit mask */
.L_06009598:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_0600959C:
    .4byte  g_game_state               /* current game state dispatch pointer */
    .4byte  sym_0607EAD0               /* (adjacent pool: race timer) */
    .4byte  sym_0607EBD0               /* (adjacent pool: frame counter) */
    .4byte  race_update_abort          /* (adjacent pool: abort handler) */
    .4byte  camera_system              /* (adjacent pool: camera system) */
    .4byte  sym_06063E24               /* (adjacent pool: camera yaw ptr) */
    .4byte  sym_06063EEC               /* (adjacent pool: camera pitch ptr) */
    .4byte  sym_06063EF8               /* (adjacent pool: camera params ptr) */
    .4byte  camera_orient_calc         /* (adjacent pool: camera orient fn) */
    .4byte  scene_update               /* (adjacent pool: scene update) */
    .4byte  frame_end_commit           /* (adjacent pool: frame commit) */
.L_060095C8:
    .4byte  sym_06063D9A               /* input status word (16-bit) */
.L_060095CC:
    .4byte  sym_0607EACC               /* countdown timer target (32-bit) */
.L_060095D0:
    .byte   0xD0, 0x2C    /* mov.l .L_06009684, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_060095E0
    .byte   0xD4, 0x2B    /* mov.l .L_06009688, r4 */
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_060095E0:
    .byte   0xD0, 0x2A    /* mov.l .L_0600968C, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060095EE
    .byte   0xD3, 0x29    /* mov.l .L_06009690, r3 */
    jsr @r3
    mov #0x0, r4
.L_060095EE:
    .byte   0xD3, 0x29    /* mov.l .L_06009694, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_06009698, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x28    /* mov.l .L_0600969C, r6 */
    .byte   0xD5, 0x28    /* mov.l .L_060096A0, r5 */
    .byte   0xD4, 0x29    /* mov.l .L_060096A4, r4 */
    .byte   0xD3, 0x29    /* mov.l .L_060096A8, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x29    /* mov.l .L_060096AC, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x28    /* mov.l .L_060096B0, r0 */
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0600961C
    .byte   0xD3, 0x27    /* mov.l .L_060096B4, r3 */
    jsr @r3
    nop
.L_0600961C:
    .byte   0xD0, 0x26    /* mov.l .L_060096B8, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009632
    .byte   0xD7, 0x25    /* mov.l .L_060096BC, r7 */
    .byte   0xD6, 0x25    /* mov.l .L_060096C0, r6 */
    mov.w   .L_0600967C, r5
    .byte   0xD3, 0x25    /* mov.l .L_060096C4, r3 */
    jsr @r3
    mov #0x8, r4
.L_06009632:
    .byte   0xD2, 0x25    /* mov.l .L_060096C8, r2 */
    mov.w   .L_0600967E, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_06009642
    .byte   0xB5, 0x21    /* bsr 0x0600A084 (external sub-function) */
    nop
.L_06009642:
    .byte   0xD3, 0x22    /* mov.l .L_060096CC, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1F    /* mov.l .L_060096C8, r0 */
    mov.w   .L_06009680, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0xCC, r0
    bf      .L_06009668
    .byte   0xD3, 0x1E    /* mov.l .L_060096D0, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov r3, r5
    mov.w   .L_06009682, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    .byte   0xD3, 0x1C    /* mov.l .L_060096D4, r3 */
    jsr @r3
    mov #0x4, r4
.L_06009668:
    .byte   0xD0, 0x1B    /* mov.l .L_060096D8, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009674
    mov #0x11, r3
    mov.l r3, @r14
.L_06009674:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0600967C:
    .2byte  0x0082                        /* geometry tile size parameter */
.L_0600967E:
    .2byte  0x00BC                        /* car struct offset: timer value */
.L_06009680:
    .2byte  0x0214                        /* car struct offset: flags word */
.L_06009682:
    .2byte  0x0900                        /* display layer priority value */
.L_06009684:
    .4byte  sym_0607EAD0               /* race timer (32-bit) */
.L_06009688:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_0600968C:
    .4byte  sym_0605AB18               /* overlay active flag (byte) */
.L_06009690:
    .4byte  menu_overlay_render        /* menu overlay render function */
.L_06009694:
    .4byte  race_update_ending         /* race ending update */
.L_06009698:
    .4byte  camera_system              /* camera system update */
.L_0600969C:
    .4byte  sym_06063E24               /* camera yaw data pointer */
.L_060096A0:
    .4byte  sym_06063EEC               /* camera pitch data pointer */
.L_060096A4:
    .4byte  sym_06063EF8               /* camera parameters pointer */
.L_060096A8:
    .4byte  camera_orient_calc         /* camera orientation calculation */
.L_060096AC:
    .4byte  scene_update               /* 3D scene update */
.L_060096B0:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_060096B4:
    .4byte  sym_060033E6               /* special render function */
.L_060096B8:
    .4byte  sym_06086030               /* geometry render enable (byte) */
.L_060096BC:
    .4byte  sym_0605A1C8               /* geometry data pointer */
.L_060096C0:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_060096C4:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_060096C8:
    .4byte  sym_0607E944               /* car state base pointer */
.L_060096CC:
    .4byte  frame_end_commit           /* frame end commit */
.L_060096D0:
    .4byte  sym_06063798               /* display layer parameters */
.L_060096D4:
    .4byte  sym_06028400               /* display layer setup */
.L_060096D8:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
