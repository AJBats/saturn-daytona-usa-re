
    .section .text.FUN_06013B04


    .global ranking_pts_calc
    .type ranking_pts_calc, @function
ranking_pts_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06013BA8, r11
    mov.l   .L_pool_06013BAC, r12
    mov.l   .L_pool_06013BB0, r14
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    .byte   0xB1, 0x8F    /* bsr obj_render_loop_3d */
    nop
    .byte   0xB3, 0x25    /* bsr race_variant_setup_a */
    nop
    mov.w @r14, r4
    extu.w r4, r4
    add #-0x1F, r4
    cmp/pz r4
    bt      .L_06013B2E
    mov #0x0, r4
.L_06013B2E:
    mov r4, r3
    mov #0x4, r2
    shlr2 r3
    shlr2 r3
    shlr r3
    cmp/hs r2, r3
    bt      .L_06013C04
    mov #0x1F, r0
    and r4, r0
    cmp/eq #0x1F, r0
    bf      .L_06013C04
    mov r4, r0
    shlr2 r0
    shlr2 r0
    shlr r0
    cmp/eq #0x3, r0
    bf      .L_06013BD0
    mov.l   .L_pool_06013BB4, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06013BD0
    mov.l   .L_pool_06013BB8, r3
    jsr @r3
    nop
    mov.l   .L_pool_06013BBC, r13
    mov #0x25, r3
    mov.l @r12, r2
    cmp/hs r3, r2
    bt      .L_06013B74
    mov.l   .L_pool_06013BC0, r3
    jsr @r3
    nop
    bra     .L_06013B8E
    mov r13, r14
.L_06013B74:
    mov.l @r12, r2
    mov #0x44, r3
    cmp/hs r3, r2
    bt      .L_06013B86
    mov.l   .L_pool_06013BC4, r3
    jsr @r3
    nop
    bra     .L_06013B8C
    nop
.L_06013B86:
    mov.l   .L_pool_06013BC8, r3
    jsr @r3
    nop
.L_06013B8C:
    mov r13, r14
.L_06013B8E:
    mov.l @r12, r5
    mov.l   .L_pool_06013BCC, r3
    add #-0x1, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll8 r5
    add r14, r5
    jsr @r11
    mov #0x0, r4
    bra     .L_06013C04
    nop
    .2byte  0xFFFF
.L_pool_06013BA8:
    .4byte  sound_cmd_dispatch
.L_pool_06013BAC:
    .4byte  sym_06084FB4
.L_pool_06013BB0:
    .4byte  sym_06084AF6
.L_pool_06013BB4:
    .4byte  sym_06084FB8
.L_pool_06013BB8:
    .4byte  handler_init_reset
.L_pool_06013BBC:
    .4byte  0xAE1000FF
.L_pool_06013BC0:
    .4byte  race_variant_b
.L_pool_06013BC4:
    .4byte  race_variant_c
.L_pool_06013BC8:
    .4byte  race_variant_d
.L_pool_06013BCC:
    .4byte  sym_0605B294
.L_06013BD0:
    mov r4, r2
    mov #0x3, r3
    shlr2 r2
    shlr2 r2
    shlr r2
    cmp/hs r3, r2
    bt      .L_06013C04
    shlr2 r4
    .byte   0xDE, 0x18    /* mov.l .L_pool_06013C44, r14 */
    shlr2 r4
    shlr r4
    add r4, r14
    mov.b @r14, r14
    extu.b r14, r14
    add #-0x41, r14
    cmp/pz r14
    bf      .L_06013BFE
    mov r14, r5
    shll2 r5
    .byte   0xD3, 0x14    /* mov.l .L_pool_06013C48, r3 */
    add r3, r5
    bra     .L_06013C00
    mov.l @r5, r5
.L_06013BFE:
    .byte   0xD5, 0x13    /* mov.l .L_pool_06013C4C, r5 */
.L_06013C00:
    jsr @r11
    mov #0x0, r4
.L_06013C04:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_06013C10
loc_06013C10:
    mov #0x7, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_06013C50, r2 */
    mov.b r3, @r2
    mov #0x0, r3
    .byte   0xD2, 0x0E    /* mov.l .L_pool_06013C54, r2 */
    mov.w r3, @r2
    .byte   0xA0, 0x00    /* bra bonus_multiplier (falls through) */
    nop
