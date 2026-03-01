
    .section .text.FUN_06013C58


    .global lap_time_display
    .type lap_time_display, @function
lap_time_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_06013CD8, r13
    mov.l   .L_pool_06013CDC, r14
    mov.l   .L_pool_06013CE0, r3
    mov.l r3, @(4, r15)
    mov.l   .L_pool_06013CE4, r12
    jsr @r12
    mov #0x4, r4
    jsr @r12
    mov #0xC, r4
    mov.l   .L_pool_06013CE8, r3
    jsr @r3
    nop
    mov.w   .L_06013CCA, r7
    mov #0x0, r6
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    jsr @r12
    mov #0x4, r4
    mov #0x18, r6
    mov.w   .L_06013CCC, r12
    mov.w   .L_06013CCE, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.w   .L_06013CD0, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_wpool_06013CD2, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_pool_06013CEC, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_06013CF0
    mov.w   .L_wpool_06013CD4, r7
    bra     .L_06013CF2
    nop

    .global DAT_06013cca
.L_06013CCA:
DAT_06013cca:
    .2byte  0x00F0                           /* minutes dlist entry offset in car obj table */

    .global DAT_06013ccc
.L_06013CCC:
DAT_06013ccc:
    .2byte  0x7000                           /* VRAM destination offset for digit textures */

    .global DAT_06013cce
.L_06013CCE:
DAT_06013cce:
    .2byte  0x0228                           /* seconds tens dlist entry offset */

    .global DAT_06013cd0
.L_06013CD0:
DAT_06013cd0:
    .2byte  0x0230                           /* seconds ones dlist entry offset */
.L_wpool_06013CD2:
    .2byte  0x0CB0                           /* hundredths display slot value */
.L_wpool_06013CD4:
    .2byte  0x0238                           /* 1P colon separator dlist offset */
    .2byte  0xFFFF                           /* alignment padding */
.L_pool_06013CD8:
    .4byte  sym_06028400                     /* display_list_loader function */
.L_pool_06013CDC:
    .4byte  sym_06063750                     /* car object table base (display list entries) */
.L_pool_06013CE0:
    .4byte  sym_06078900                     /* car data array base (stride 0x268) */
.L_pool_06013CE4:
    .4byte  sym_0602853E                     /* display_layer_config function */
.L_pool_06013CE8:
    .4byte  sym_06028560                     /* render_state_commit function */
.L_pool_06013CEC:
    .4byte  sym_06085FF4                     /* two_player_flag (byte, 0=1P) */
.L_06013CF0:
    mov.w   .L_06013DC6, r7
.L_06013CF2:
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_06013DC8, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_pool_06013DD8, r12
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r12
    mov #0x20, r4
    mov.l   .L_pool_06013DDC, r12
    mov.l @(4, r15), r4
    mov.w   .L_06013DCA, r0
    jsr @r12
    mov.l @(r0, r4), r4
    mov r0, r7
    mov.w   .L_06013DCC, r6
    mov.w   .L_06013DCE, r5
    mov.l   .L_pool_06013DE0, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_pool_06013DE4, r2
    mov.l   .L_pool_06013DE8, r3
    mov.l @r2, r2
    cmp/hi r3, r2
    bf      .L_06013D44
    mov.l   .L_pool_06013DE8, r4
    bra     .L_06013D48
    nop
.L_06013D44:
    mov.l   .L_pool_06013DE4, r4
    mov.l @r4, r4
.L_06013D48:
    jsr @r12
    nop
    mov r0, r7
    mov.w   .L_06013DCC, r6
    mov.w   .L_wpool_06013DD0, r5
    mov.l   .L_pool_06013DE0, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_pool_06013DEC, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06013DAE
    mov.l   .L_pool_06013DF0, r7
    mov #0x30, r6
    mov.w   .L_06013DD2, r5
    mov.l   .L_pool_06013DF4, r3
    mov.b @r7, r7
    extu.b r7, r7
    add #0x1, r7
    jsr @r3
    mov #0xC, r4
    mov #0x3, r11
    mov.l   .L_pool_06013DF0, r12
    mov.b @r12, r12
    extu.b r12, r12
    cmp/ge r11, r12
    bt      .L_06013D84
    bra     .L_06013D86
    mov r12, r7
.L_06013D84:
    mov r11, r7
.L_06013D86:
    add #0x48, r7
    mov.w   .L_06013DD4, r6
    shll2 r7
    shll r7
    add r14, r7
    cmp/ge r11, r12
    bt/s    .L_06013D9A
    mov.l @(4, r7), r7
    bra     .L_06013D9C
    mov r12, r5
.L_06013D9A:
    mov r11, r5
.L_06013D9C:
    add #0x48, r5
    shll2 r5
    shll r5
    add r14, r5
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_06013E04
    nop
.L_06013DAE:
    mov.l   .L_pool_06013DF8, r7
    mov.l   .L_pool_06013DFC, r6
    mov.w   .L_06013DD6, r5
    mov #0xC, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_06013E00, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06013dc6
.L_06013DC6:
DAT_06013dc6:
    .2byte  0x0588                           /* 2P colon separator dlist offset in car obj table */

    .global DAT_06013dc8
.L_06013DC8:
DAT_06013dc8:
    .2byte  0x0C84                           /* separator display slot */

    .global DAT_06013dca
.L_06013DCA:
DAT_06013dca:
    .2byte  0x0240                           /* car struct offset: current frame field */

    .global DAT_06013dcc
.L_06013DCC:
DAT_06013dcc:
    .2byte  0x009C                           /* time digit display slot A */

    .global DAT_06013dce
.L_06013DCE:
DAT_06013dce:
    .2byte  0x0CC4                           /* time digit display slot B */
.L_wpool_06013DD0:
    .2byte  0x0C98                           /* time digit display slot C */

    .global DAT_06013dd2
.L_06013DD2:
DAT_06013dd2:
    .2byte  0x0104                           /* lap number display slot */

    .global DAT_06013dd4
.L_06013DD4:
DAT_06013dd4:
    .2byte  0x010C                           /* lap element display slot */

    .global DAT_06013dd6
.L_06013DD6:
DAT_06013dd6:
    .2byte  0x0102                           /* "FASTEST LAP" text display slot */
.L_pool_06013DD8:
    .4byte  display_channel_b                /* display channel setup wrapper */
.L_pool_06013DDC:
    .4byte  anim_frame_transform             /* frame-to-time conversion function */
.L_pool_06013DE0:
    .4byte  sym_060284AE                     /* display_element_renderer function */
.L_pool_06013DE4:
    .4byte  sym_060786A4                     /* frame_counter (32-bit race frame) */
.L_pool_06013DE8:
    .4byte  0x000927BF                       /* 599,999 = max frame index (~10 min at 60fps) */
.L_pool_06013DEC:
    .4byte  sym_06085FF8                     /* pause_replay_flag (byte) */
.L_pool_06013DF0:
    .4byte  sym_06086012                     /* current_lap_index (byte, 0-based) */
.L_pool_06013DF4:
    .4byte  sym_06028430                     /* display_list_cmd_writer function */
.L_pool_06013DF8:
    .4byte  sym_06044A58                     /* "FASTEST LAP" string (ROM data) */
.L_pool_06013DFC:
    .4byte  0x0000F000                       /* nibble 3 mask (palette/color selector) */
.L_pool_06013E00:
    .4byte  sym_060283E0                     /* geom_render_dispatch (text renderer) */
.L_06013E04:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
