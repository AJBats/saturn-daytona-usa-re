
    .section .text.FUN_0603D9EC


    .global scene_invalidate_a
    .type scene_invalidate_a, @function
scene_invalidate_a:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603DA60, r3
    and r14, r3
    tst r3, r3
    bt/s    .L_0603DA04
    mov #0x0, r12
    mov #0x1, r12
    neg r14, r14
.L_0603DA04:
    mov.l   .L_0603DA64, r0
    mov.l   .L_0603DA68, r3
    jsr @r3
    mov r14, r1
    mov r0, r14
    mov.l   .L_0603DA6C, r13
    mov.l   .L_0603DA70, r2
    cmp/ge r2, r14
    bf      .L_0603DA20
    mov.l   .L_0603DA64, r4
    jsr @r13
    sub r14, r4
    bra     .L_0603DA44
    neg r0, r4
.L_0603DA20:
    mov.l   .L_0603DA74, r2
    cmp/ge r2, r14
    bf      .L_0603DA30
    mov.l   .L_0603DA78, r4
    jsr @r13
    add r14, r4
    bra     .L_0603DA44
    neg r0, r4
.L_0603DA30:
    mov.l   .L_0603DA7C, r2
    cmp/ge r2, r14
    bf      .L_0603DA3C
    mov.l   .L_0603DA74, r4
    bra     .L_0603DA3E
    sub r14, r4
.L_0603DA3C:
    mov r14, r4
.L_0603DA3E:
    jsr @r13
    nop
    mov r0, r4
.L_0603DA44:
    mov.l   .L_0603DA80, r2
    cmp/eq r2, r4
    bf      .L_0603DA4C
    mov.l   .L_0603DA84, r4
.L_0603DA4C:
    extu.w r12, r12
    tst r12, r12
    bt      .L_0603DA54
    neg r4, r4
.L_0603DA54:
    mov r4, r0
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603DA60:
    .4byte  0x80000000
.L_0603DA64:
    .4byte  0x01680000
.L_0603DA68:
    .4byte  sym_06036BE4
.L_0603DA6C:
    .4byte  sym_060424A2
.L_0603DA70:
    .4byte  0x010E0000
.L_0603DA74:
    .4byte  0x00B40000
.L_0603DA78:
    .4byte  0xFF4C0000
.L_0603DA7C:
    .4byte  0x005A0000
.L_0603DA80:
    .4byte  0x0000FFFF
.L_0603DA84:
    .4byte  0x00010000

    .global scene_invalidate_b
    .type scene_invalidate_b, @function
scene_invalidate_b:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603DB00, r3
    and r14, r3
    tst r3, r3
    bt      .L_0603DA9C
    neg r14, r14
.L_0603DA9C:
    mov.l   .L_0603DB04, r0
    mov.l   .L_0603DB08, r3
    jsr @r3
    mov r14, r1
    mov r0, r14
    tst r14, r14
    bf      .L_0603DAB0
    mov.l   .L_0603DB0C, r0
    bra     .L_0603DAF4
    nop
.L_0603DAB0:
    mov.l   .L_0603DB10, r13
    mov.l   .L_0603DB14, r3
    cmp/ge r3, r14
    bf      .L_0603DAC2
    mov.l   .L_0603DB04, r4
    jsr @r13
    sub r14, r4
    bra     .L_0603DAF2
    mov r0, r4
.L_0603DAC2:
    mov.l   .L_0603DB18, r12
    cmp/gt r12, r14
    bf      .L_0603DAD2
    mov.l   .L_0603DB1C, r4
    jsr @r13
    add r14, r4
    bra     .L_0603DAF2
    neg r0, r4
.L_0603DAD2:
    cmp/eq r12, r14
    bf      .L_0603DADC
    mov.l   .L_0603DB20, r4
    bra     .L_0603DAF2
    nop
.L_0603DADC:
    mov.l   .L_0603DB24, r2
    cmp/ge r2, r14
    bf      .L_0603DAEC
    mov r12, r4
    jsr @r13
    sub r14, r4
    bra     .L_0603DAF2
    neg r0, r4
.L_0603DAEC:
    jsr @r13
    mov r14, r4
    mov r0, r4
.L_0603DAF2:
    mov r4, r0
.L_0603DAF4:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0603DB00:
    .4byte  0x80000000
.L_0603DB04:
    .4byte  0x01680000
.L_0603DB08:
    .4byte  sym_06036BE4
.L_0603DB0C:
    .4byte  0x00010000
.L_0603DB10:
    .4byte  sym_0604249C
.L_0603DB14:
    .4byte  0x010E0000
.L_0603DB18:
    .4byte  0x00B40000
.L_0603DB1C:
    .4byte  0xFF4C0000
.L_0603DB20:
    .4byte  0xFFFF0000
.L_0603DB24:
    .4byte  0x005A0000

    .global controller_config
    .type controller_config, @function
controller_config:
    mov.l r14, @-r15
    mov r5, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_0603DBA0, r10
    mov.l r4, @r15
    mov.w r0, @(4, r15)
    mov r6, r0
    cmp/eq #0x1, r0
    bt/s    .L_0603DB5E
    mov #0x0, r13
    tst r6, r6
    bt      .L_0603DB5E
    mov.w   .L_0603DB9E, r3
    cmp/eq r3, r6
    bf      .L_0603DB5A
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_0603DB5E
.L_0603DB5A:
    bra     .L_0603DDD6
    mov #0x2, r0
.L_0603DB5E:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_0603DB72
    mov r7, r0
    cmp/eq #0x2, r0
    bt      .L_0603DB72
    tst r7, r7
    bt      .L_0603DB72
    bra     .L_0603DDD6
    mov #0x2, r0
.L_0603DB72:
    extu.b r6, r3
    mov.l   .L_0603DBA4, r2
    extu.b r7, r1
    mov r6, r0
    mov.b r3, @r2
    mov.l   .L_0603DBA8, r2
    cmp/eq #0x1, r0
    bf/s    .L_0603DB90
    mov.b r1, @r2
    mov r7, r0
    cmp/eq #0x1, r0
    bf      .L_0603DB90
    mov #0x2, r2
    bra     .L_0603DBB0
    mov.w r2, @r10
.L_0603DB90:
    tst r6, r6
    bf      .L_0603DBAC
    mov r7, r0
    cmp/eq #0x1, r0
    bf      .L_0603DBAC
    bra     .L_0603DBAE
    mov #0x1, r2
.L_0603DB9E:
    .2byte  0x0100
.L_0603DBA0:
    .4byte  sym_060A4C80
.L_0603DBA4:
    .4byte  sym_060A4C58
.L_0603DBA8:
    .4byte  sym_060A4C59
.L_0603DBAC:
    extu.w r13, r2
.L_0603DBAE:
    mov.w r2, @r10
.L_0603DBB0:
    mov.w @r10, r3
    mov.l   .L_0603DCBC, r2
    mov.w r3, @r2
    mov.l   .L_0603DCC0, r4
    mov.l r13, @r4
    mov.l r13, @(4, r4)
    mov.l   .L_0603DCC4, r5
    mov.l r13, @r5
    mov.l   .L_0603DCC8, r4
    mov.l r13, @r4
    mov.l r13, @(4, r5)
    mov.l r13, @(4, r4)
    mov.l   .L_0603DCCC, r4
    mov.l   .L_0603DCD0, r0
    mov r4, r11
    mov.w @r0, r0
    add #-0x10, r15
    extu.w r0, r0
    mov.l   .L_0603DCD4, r3
    shlr r0
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0603DCD8, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_0603DCDC, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_0603DCE0, r3
    jsr @r3
    nop
    mov.l r0, @r11
    mov.l   .L_0603DCE4, r5
    mov.l   .L_0603DCE8, r9
    mov r5, r12
    mov.w @r9, r0
    extu.w r0, r0
    add #-0x10, r15
    shlr r0
    mov.l   .L_0603DCD4, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0603DCD8, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_0603DCDC, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_0603DCE0, r3
    jsr @r3
    nop
    mov.l r0, @r12
    mov.l @r11, r2
    mov.l r2, @(4, r4)
    mov.l @r12, r3
    mov.l r3, @(4, r5)
    mov.l @r15, r2
    mov.l   .L_0603DCEC, r3
    mov.l r2, @r3
    mov.w @(4, r15), r0
    mov.l   .L_0603DCF0, r3
    mov r0, r2
    mov.w r2, @r3
    mov.l   .L_0603DCF4, r8
    mov.l   .L_0603DCF8, r14
    mov.l @r11, r2
    mov.l r2, @(8, r15)
    bsr     scene_invalidate_b
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @(8, r15), r5
    mov.l @(8, r15), r3
    sub r0, r3
    mov.l r3, @-r15
    bsr     scene_invalidate_a
    mov r13, r4
    neg r0, r4
    jsr @r8
    mov.l @r12, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @r14
    bsr     scene_invalidate_a
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @r11, r5
    mov.l @r12, r2
    sub r0, r2
    mov.l r2, @-r15
    bsr     scene_invalidate_b
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @r12, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @(4, r14)
    mov.l r13, @(8, r14)
    bsr     scene_invalidate_a
    mov r13, r4
    neg r0, r0
    mov.l r0, @(12, r14)
    bsr     scene_invalidate_b
    mov r13, r4
    mov.l r0, @(16, r14)
    bsr     scene_invalidate_b
    mov r13, r4
    mov.l r0, @(20, r14)
    bsr     scene_invalidate_a
    mov r13, r4
    mov.l r0, @(24, r14)
    mov.l   .L_0603DCFC, r4
    mov.l r4, @(28, r14)
    mov.l r13, @(32, r14)
    mov.l r13, @(36, r14)
    mov.l r13, @(40, r14)
    mov.l r4, @(44, r14)
    mov.l r13, @(48, r14)
    mov.l   .L_0603DCD0, r2
    mov.w @r2, r2
    extu.w r2, r2
    shlr r2
    exts.w r2, r2
    bra     .L_0603DD00
    nop
    .2byte  0xFFFF
.L_0603DCBC:
    .4byte  sym_060A3E38
.L_0603DCC0:
    .4byte  sym_060A4C70
.L_0603DCC4:
    .4byte  sym_060A4C60
.L_0603DCC8:
    .4byte  sym_060A4C68
.L_0603DCCC:
    .4byte  sym_060A53A8
.L_0603DCD0:
    .4byte  sym_060635AE
.L_0603DCD4:
    .4byte  sym_060358EC
.L_0603DCD8:
    .4byte  0x40F00000
.L_0603DCDC:
    .4byte  sym_060359E4
.L_0603DCE0:
    .4byte  sym_060357B8
.L_0603DCE4:
    .4byte  sym_060A53B0
.L_0603DCE8:
    .4byte  sym_060635B0
.L_0603DCEC:
    .4byte  sym_060A4C5C
.L_0603DCF0:
    .4byte  sym_060635B2
.L_0603DCF4:
    .4byte  display_scene_update
.L_0603DCF8:
    .4byte  sym_060A3E68
.L_0603DCFC:
    .4byte  0x00010000
.L_0603DD00:
    mov #0x34, r0
    mov.w r2, @(r0, r14)
    mov.w @r9, r3
    mov #0x36, r0
    extu.w r3, r3
    shlr r3
    exts.w r3, r3
    mov.w r3, @(r0, r14)
    mov.w   .L_0603DDEA, r3
    mov #0x38, r0
    mov.w r3, @(r0, r14)
    mov #0x3C, r0
    mov.l   .L_0603DDEC, r3
    mov.w @r3, r3
    extu.w r3, r3
    shlr r3
    mov.w r3, @(r0, r14)
    mov.w @r9, r3
    extu.w r3, r3
    shlr r3
    mov #0x3E, r0
    mov.w r3, @(r0, r14)
    exts.w r13, r3
    mov #0x40, r0
    mov.w r3, @(r0, r14)
    mov #0x44, r0
    mov.l r13, @(r0, r14)
    mov #0x48, r0
    mov.l r13, @(r0, r14)
    mov #0x4C, r0
    mov.l r4, @(r0, r14)
    mov #0x50, r0
    mov.l r4, @(r0, r14)
    mov.w @(4, r15), r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_0603DDC0
    mov.l   .L_0603DDF0, r4
    mov r4, r5
    add #-0x80, r5
    mov.l @r5, r2
    mov.l r2, @r4
    mov.l @(4, r5), r3
    mov.l r3, @(4, r4)
    mov.l @(8, r5), r2
    mov.l r2, @(8, r4)
    mov.l @(12, r5), r3
    mov.l r3, @(12, r4)
    mov.l @(16, r5), r2
    mov.l r2, @(16, r4)
    mov.l @(20, r5), r3
    mov.l r3, @(20, r4)
    mov.l @(24, r5), r2
    mov.l r2, @(24, r4)
    mov.l @(28, r5), r3
    mov.l r3, @(28, r4)
    mov.l @(32, r5), r2
    mov.l r2, @(32, r4)
    mov.l @(36, r5), r3
    mov.l r3, @(36, r4)
    mov.l @(40, r5), r2
    mov.l r2, @(40, r4)
    mov.l @(44, r5), r3
    mov.l r3, @(44, r4)
    mov.l @(48, r5), r2
    mov.l r2, @(48, r4)
    mov #0x34, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x36, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x38, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x3C, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x3E, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x40, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x44, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x48, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x4C, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x50, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
.L_0603DDC0:
    mov.l @r15, r4
    mov.l   .L_0603DDF4, r3
    and r3, r4
    shlr r4
    mov.l @r15, r0
    and #0x3E, r0
    shlr2 r0
    add r0, r4
    mov.l   .L_0603DDF8, r3
    mov.l r4, @r3
    mov #0x0, r0
.L_0603DDD6:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603DDEA:
    .2byte  0x0190
.L_0603DDEC:
    .4byte  sym_060635AE
.L_0603DDF0:
    .4byte  sym_060A3EE8
.L_0603DDF4:
    .4byte  0x0007FF80
.L_0603DDF8:
    .4byte  sym_060A3E44

    .global scene_color_matrix
    .type scene_color_matrix, @function
scene_color_matrix:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0603DEB4, r10
    mov.l   .L_0603DEB8, r11
    mov.l   .L_0603DEBC, r12
    mov #0x0, r13
    mov.l r6, @r15
    mov.l   .L_0603DEC0, r0
    bra     .L_0603DE26
    mov.l @r0, r0
.L_0603DE1A:
    bra     .L_0603DE32
    extu.w r13, r14
.L_0603DE1E:
    bra     .L_0603DE32
    mov #0x1, r14
.L_0603DE22:
    bra     .L_0603E02A
    nop
.L_0603DE26:
    cmp/eq #0x1, r0
    bt      .L_0603DE1A
    cmp/eq #0x2, r0
    bt      .L_0603DE1E
    bra     .L_0603DE22
    nop
.L_0603DE32:
    exts.b r14, r6
    extu.w r14, r2
    mov.l   .L_0603DEC4, r7
    mov r6, r3
    shll2 r2
    shll2 r6
    shll2 r3
    shll2 r3
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    mov.l r7, @r6
    mov.l r13, @(4, r6)
    mov.l r13, @(8, r6)
    mov.l r13, @(12, r6)
    mov.l r7, @(16, r6)
    mov.l r13, @(20, r6)
    mov.l r13, @(24, r6)
    mov.l r13, @(28, r6)
    mov.l r7, @(32, r6)
    mov.l   .L_0603DEC8, r3
    add r3, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_0603DE74
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r3
    add r4, r3
    mov.l r3, @(r0, r12)
    bra     .L_0603DE7A
    nop
.L_0603DE74:
    extu.w r14, r0
    shll2 r0
    mov.l r13, @(r0, r12)
.L_0603DE7A:
    extu.w r14, r6
    shll2 r6
    mov r6, r3
    add r11, r3
    add r12, r6
    mov.l @r3, r2
    add r5, r2
    mov.l r2, @r3
    mov.l @r6, r0
    tst r0, r0
    bf      .L_0603DEDC
    tst r4, r4
    bt      .L_0603DEDC
    mov.l   .L_0603DECC, r4
    mov.l   .L_0603DEC0, r0
    bra     .L_0603DED4
    mov.l @r0, r0
.L_0603DE9C:
    mov.l   .L_0603DED0, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_0603DEAE
    nop
.L_0603DEAA:
    mov.w @(4, r4), r0
    and #0xFF, r0
.L_0603DEAE:
    bra     .L_0603DEDC
    mov.w r0, @(4, r4)
    .2byte  0xFFFF
.L_0603DEB4:
    .4byte  sym_060A53B8
.L_0603DEB8:
    .4byte  sym_060A4C68
.L_0603DEBC:
    .4byte  sym_060A4C60
.L_0603DEC0:
    .4byte  sym_060635A8
.L_0603DEC4:
    .4byte  0x00010000
.L_0603DEC8:
    .4byte  sym_060A4C44
.L_0603DECC:
    .4byte  sym_060A3E38
.L_0603DED0:
    .4byte  0x0000FF00
.L_0603DED4:
    cmp/eq #0x1, r0
    bt      .L_0603DE9C
    cmp/eq #0x2, r0
    bt      .L_0603DEAA
.L_0603DEDC:
    mov.l @r15, r0
    tst r0, r0
    bt      .L_0603DEE6
    bsr     hud_update_main
    mov.l @r15, r4
.L_0603DEE6:
    extu.w r14, r4
    mov.l   .L_0603DF4C, r3
    shll2 r4
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603DF04
    mov.l   .L_0603DF50, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603DF04
    extu.w r14, r0
    shll2 r0
    mov.l r13, @(r0, r12)
.L_0603DF04:
    mov.l   .L_0603DF54, r5
    extu.w r14, r4
    shll2 r4
    mov r4, r3
    add r12, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_0603DF1E
    mov.l   .L_0603DF58, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603DF5C
.L_0603DF1E:
    exts.b r14, r6
    extu.w r14, r4
    mov r6, r3
    shll2 r4
    shll2 r6
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    shll r4
    add r5, r4
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @r6
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(16, r6)
    bra     .L_0603DFB6
    nop
.L_0603DF4C:
    .4byte  sym_060A4C4C
.L_0603DF50:
    .4byte  sym_060A4C70
.L_0603DF54:
    .4byte  sym_060A3E68
.L_0603DF58:
    .4byte  sym_060A4C78
.L_0603DF5C:
    extu.w r14, r4
    tst r4, r4
    bf      .L_0603DF6C
    mov.l   .L_0603E03C, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0xFF, r0
    bf      .L_0603DF80
.L_0603DF6C:
    mov r4, r0
    cmp/eq #0x1, r0
    bf      .L_0603DFB6
    mov.l   .L_0603E03C, r2
    mov.l   .L_0603E040, r3
    mov.w @r2, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0603DFB6
.L_0603DF80:
    exts.b r14, r6
    extu.w r14, r4
    mov r6, r3
    shll2 r4
    shll2 r6
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    shll r4
    add r5, r4
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @r6
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(16, r6)
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(28, r4)
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(44, r4)
.L_0603DFB6:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r11), r3
    tst r3, r3
    bt      .L_0603DFC8
    extu.w r14, r0
    shll2 r0
    bsr     display_channel_handler
    mov.l @(r0, r11), r4
.L_0603DFC8:
    extu.w r14, r4
    shll2 r4
    mov r4, r3
    add r12, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_0603DFE0
    mov.l   .L_0603E044, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603E02A
.L_0603DFE0:
    extu.w r14, r3
    mov.l   .L_0603E048, r2
    shll r3
    add r2, r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_0603DFFE
    extu.w r14, r3
    mov.l   .L_0603E04C, r2
    shll2 r3
    add r2, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603E014
.L_0603DFFE:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     sound_test_player
    mov.l @r15+, r14
.L_0603E014:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     options_render
    mov.l @r15+, r14
.L_0603E02A:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0603E03C:
    .4byte  sym_060A3E3C
.L_0603E040:
    .4byte  0x0000FF00
.L_0603E044:
    .4byte  sym_060A4C78
.L_0603E048:
    .4byte  sym_060A4C54
.L_0603E04C:
    .4byte  sym_060A4C4C

    .global sound_test_player
    .type sound_test_player, @function
sound_test_player:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x38, r15
    mov.w   .L_0603E0B0, r8
    mov.l   .L_0603E0B4, r9
    mov.l   .L_0603E0B8, r12
    mov.l   .L_0603E0BC, r13
    mov.l r4, @(8, r15)
    mov.l   .L_0603E0C0, r4
    mov.l   .L_0603E0C4, r0
    bra     .L_0603E0A4
    mov.l @r0, r0
.L_0603E076:
    mov #0x0, r14
    mov.l   .L_0603E0C8, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(4, r4)
    mov.w @(4, r4), r0
    bra     .L_0603E09C
    or #0x3, r0
.L_0603E08A:
    mov #0x1, r14
    mov.w @(4, r4), r0
    and #0xFF, r0
    mov.w r0, @(4, r4)
    mov.w   DAT_0603e0b2, r3
    mov.w @(4, r4), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
.L_0603E09C:
    bra     .L_0603E0CC
    mov.w r0, @(4, r4)
.L_0603E0A0:
    bra     .L_0603E5A6
    nop
.L_0603E0A4:
    cmp/eq #0x1, r0
    bt      .L_0603E076
    cmp/eq #0x2, r0
    bt      .L_0603E08A
    bra     .L_0603E0A0
    nop
.L_0603E0B0:
    .2byte  0x0100

    .global DAT_0603e0b2
DAT_0603e0b2:
    .2byte  0x0300
.L_0603E0B4:
    .4byte  0x00040000
.L_0603E0B8:
    .4byte  0x00008000
.L_0603E0BC:
    .4byte  sym_0603C0A0
.L_0603E0C0:
    .4byte  sym_060A3E38
.L_0603E0C4:
    .4byte  sym_060635A8
.L_0603E0C8:
    .4byte  0x0000FF00
.L_0603E0CC:
    bsr     scene_invalidate_a
    mov.l @(8, r15), r4
    mov.l r0, @r15
    bsr     scene_invalidate_b
    mov.l @(8, r15), r4
    exts.b r14, r10
    mov.l r0, @(8, r15)
    mov r10, r3
    shll2 r10
    shll2 r3
    shll2 r3
    shll r3
    add r3, r10
    exts.b r10, r10
    mov.l   .L_0603E1A8, r2
    add r2, r10
    mov r10, r3
    add #0x4, r3
    mov.l r3, @(48, r15)
    mov.l @r3, r1
    mov.l r1, @(12, r15)
    mov r10, r1
    add #0x8, r1
    mov.l r1, @(44, r15)
    mov.l @r1, r3
    mov.l r3, @(52, r15)
    mov r10, r3
    add #0x10, r3
    mov.l r3, @(40, r15)
    mov.l @r3, r2
    mov.l r2, @(36, r15)
    mov r10, r2
    add #0x14, r2
    mov.l r2, @(28, r15)
    mov.l @r2, r1
    mov.l r1, @(32, r15)
    mov r10, r1
    add #0x1C, r1
    mov.l r1, @(20, r15)
    mov.l @r1, r3
    mov.l r3, @(24, r15)
    mov r10, r3
    add #0x20, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r2
    mov.l r2, @(16, r15)
    mov.l   .L_0603E1AC, r11
    mov.l @(48, r15), r2
    mov.l r2, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(60, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(44, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(60, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(40, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(28, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    bra     .L_0603E1B0
    mov.l @(24, r15), r4
.L_0603E1A8:
    .4byte  sym_060A53B8
.L_0603E1AC:
    .4byte  display_scene_update
.L_0603E1B0:
    jsr @r11
    nop
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(4, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(28, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(24, r15), r4
    mov.l @r15+, r3
    extu.w r14, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_0603E2BC, r3
    add r3, r4
    mov.l @r10, r2
    mov.l r2, @(28, r4)
    mov.l @(48, r15), r3
    mov.l @r3, r2
    mov.l r2, @(32, r4)
    mov.l @(44, r15), r3
    mov.l @r3, r2
    mov.l r2, @(36, r4)
    mov.l @(40, r15), r3
    mov.l @r3, r2
    mov.l r2, @(44, r4)
    mov.l @(28, r15), r3
    mov.l @r3, r2
    mov.l r2, @(48, r4)
    mov.l @(24, r10), r7
    mov #0x34, r0
    mov.w @(r0, r4), r6
    mov #0x3C, r0
    mov.w @(r0, r4), r3
    mov r6, r11
    sub r3, r11
    mul.l r11, r7
    mov.l @(20, r15), r3
    mov #0x36, r0
    sts macl, r11
    mov.l @r3, r3
    mov.w @(r0, r4), r2
    mov #0x3E, r0
    mov.w @(r0, r4), r1
    mov #0x38, r0
    sub r1, r2
    mul.l r2, r3
    mov.l @(4, r15), r2
    sts macl, r3
    add r3, r11
    mov.l @r2, r3
    mov.l r3, @(8, r15)
    mov.w @(r0, r4), r3
    mov #0x40, r0
    mov.l r3, @r15
    mov.w @(r0, r4), r5
    mov.l @(8, r15), r1
    sub r5, r3
    mov r5, r0
    add #-0x10, r15
    mul.l r3, r1
    exts.w r0, r0
    sts macl, r1
    mov.l   .L_0603E2C0, r3
    add r1, r11
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0603E2C4, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_0603E2C8, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_0603E2CC, r3
    jsr @r3
    nop
    add r0, r11
    extu.w r14, r3
    mul.l r7, r6
    shll2 r3
    sts macl, r6
    mov.l r3, @(12, r15)
    neg r6, r6
    mov.l   .L_0603E2D0, r2
    add r3, r2
    mov.l @r2, r1
    mov.l @r15, r2
    add r1, r11
    mov.l @(8, r15), r1
    mul.l r1, r2
    sts macl, r2
    sub r2, r6
    mov.l r6, @(8, r15)
    mov.l @(12, r15), r2
    mov.l   .L_0603E2D4, r0
    mov.l @(r0, r2), r2
    tst r2, r2
    bf      .L_0603E296
    bra     .L_0603E3EE
    nop
.L_0603E296:
    extu.w r14, r10
    shll2 r10
    shll2 r10
    shll2 r10
    shll r10
    mov.l   .L_0603E2BC, r3
    add r3, r10
    mov.l @(4, r10), r2
    mov.l   .L_0603E2D8, r3
    add r3, r2
    mov #0x54, r0
    mov.l r2, @(r0, r10)
    extu.w r14, r4
    shll2 r4
    mov.l r4, @r15
    mov.l   .L_0603E2D4, r3
    add r3, r4
    bra     .L_0603E2DC
    nop
.L_0603E2BC:
    .4byte  sym_060A3E68
.L_0603E2C0:
    .4byte  sym_060358EC
.L_0603E2C4:
    .4byte  0x40F00000
.L_0603E2C8:
    .4byte  sym_060359E4
.L_0603E2CC:
    .4byte  sym_060357B8
.L_0603E2D0:
    .4byte  sym_060A4C78
.L_0603E2D4:
    .4byte  sym_060A4C70
.L_0603E2D8:
    .4byte  0x012C0000
.L_0603E2DC:
    mov.l r4, @(4, r15)
    bsr     scene_invalidate_b
    mov.l @r4, r4
    mov #0x58, r1
    add r10, r1
    mov.l r0, @r1
    mov.l @(4, r15), r4
    bsr     scene_invalidate_a
    mov.l @r4, r4
    mov #0x5C, r1
    add r10, r1
    mov #0x0, r10
    mov.l r0, @r1
    mov.l @r15, r3
    mov.l   .L_0603E3C0, r2
    mov.w   DAT_0603e3b6, r1
    add r2, r3
    mov.l r1, @r3
    extu.w r14, r3
    exts.b r14, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(12, r15)
    shll2 r0
    extu.w r14, r3
    shll r0
    shll2 r3
    add r0, r1
    shll2 r3
    exts.b r1, r1
    mov.l   .L_0603E3C4, r0
    shll2 r3
    add r0, r1
    add #0x1C, r1
    mov.l r1, @(16, r15)
    shll r3
    mov.l   .L_0603E3C8, r0
    add r0, r3
    mov.l r3, @(20, r15)
    mov.w   DAT_0603e3b8, r2
    muls.w r2, r14
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_0603E3CC, r0
    add r0, r2
    bra     .L_0603E3E2
    mov.l r2, @(4, r15)
.L_0603E340:
    mov.l @(16, r15), r2
    mov #0x36, r0
    mov r10, r1
    mov.l @(20, r15), r3
    mov.l @r2, r2
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.w   DAT_0603e3ba, r3
    add r3, r1
    mul.l r1, r2
    mov.l @(8, r15), r3
    sts macl, r1
    add r3, r1
    mov.l r1, @r15
    mov.l   .L_0603E3D0, r2
    jsr @r2
    mov r8, r0
    tst r0, r0
    bt      .L_0603E3D4
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/gt r9, r0
    bt      .L_0603E37E
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    bt      .L_0603E38A
.L_0603E37E:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_0603E3DC
    nop
.L_0603E38A:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    mov.w   DAT_0603e3bc, r3
    and r3, r0
    extu.w r0, r0
    mov.l @r15+, r2
    bra     .L_0603E3E0
    mov.w r0, @r2

    .global DAT_0603e3b6
DAT_0603e3b6:
    .2byte  0x0333

    .global DAT_0603e3b8
DAT_0603e3b8:
    .2byte  0x0668

    .global DAT_0603e3ba
DAT_0603e3ba:
    .2byte  0xFED4

    .global DAT_0603e3bc
DAT_0603e3bc:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_0603E3C0:
    .4byte  sym_060A4C38
.L_0603E3C4:
    .4byte  sym_060A53B8
.L_0603E3C8:
    .4byte  sym_060A3E68
.L_0603E3CC:
    .4byte  sym_060A3F68
.L_0603E3D0:
    .4byte  sym_06034FFC
.L_0603E3D4:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_0603E3DC:
    extu.w r12, r2
    mov.w r2, @r0
.L_0603E3E0:
    add #0x1, r10
.L_0603E3E2:
    mov.l @(12, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_0603E340
    bra     .L_0603E59A
    nop
.L_0603E3EE:
    extu.w r14, r0
    mov.l   .L_0603E448, r5
    shll2 r0
    mov.l @(r0, r5), r4
    mov r4, r0
    cmp/eq #-0x1, r0
    bt      .L_0603E460
    tst r4, r4
    bt      .L_0603E460
    extu.w r14, r4
    extu.w r14, r0
    mov.l   .L_0603E44C, r3
    shll2 r4
    shll2 r0
    shll2 r4
    mov.l @(r0, r5), r0
    shll2 r4
    add #-0x10, r15
    shll r4
    mov.l   .L_0603E450, r2
    add r3, r4
    mov #0x0, r3
    cmp/gt r0, r3
    addc r3, r0
    shar r0
    jsr @r2
    mov.l r15, @-r15
    mov.l r3, @-r15
    mov.l   .L_0603E454, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_0603E458, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_0603E45C, r2
    jsr @r2
    nop
    mov.l @(4, r4), r3
    add r3, r0
    mov #0x54, r1
    add r4, r1
    bra     .L_0603E474
    mov.l r0, @r1
    .2byte  0xFFFF
.L_0603E448:
    .4byte  sym_060A4C4C
.L_0603E44C:
    .4byte  sym_060A3E68
.L_0603E450:
    .4byte  sym_060358EC
.L_0603E454:
    .4byte  0x40F00000
.L_0603E458:
    .4byte  sym_060359E4
.L_0603E45C:
    .4byte  sym_060357B8
.L_0603E460:
    extu.w r14, r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_0603E540, r3
    add r3, r4
    mov.l @(4, r4), r2
    mov #0x54, r0
    mov.l r2, @(r0, r4)
.L_0603E474:
    extu.w r14, r3
    mov.l   .L_0603E540, r2
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    add r2, r3
    mov #0x58, r2
    mov.l r3, @r15
    add r3, r2
    mov.l r2, @-r15
    bsr     scene_invalidate_b
    mov #0x0, r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov #0x5C, r3
    mov.l @r15, r2
    add r2, r3
    mov.l r3, @-r15
    bsr     scene_invalidate_a
    mov #0x0, r4
    extu.w r14, r3
    mov #0x0, r10
    mov.l @r15+, r2
    shll2 r3
    mov.l r0, @r2
    mov.l   .L_0603E544, r2
    mov.l   .L_0603E548, r1
    add r2, r3
    mov.w @r1, r1
    extu.w r1, r1
    add #-0x1, r1
    mov.l r1, @r3
    extu.w r14, r3
    exts.b r14, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(16, r15)
    shll2 r0
    shll r0
    add r0, r1
    exts.b r1, r1
    mov.l   .L_0603E54C, r0
    add r0, r1
    add #0x1C, r1
    mov.l r1, @(12, r15)
    extu.w r14, r3
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    mov.l   .L_0603E540, r0
    add r0, r3
    mov.l r3, @(20, r15)
    mov.w   .L_0603E53C, r2
    muls.w r2, r14
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_0603E550, r0
    add r0, r2
    bra     .L_0603E592
    mov.l r2, @(4, r15)
.L_0603E4F6:
    mov #0x36, r0
    mov r10, r1
    mov.l @(12, r15), r2
    mov.l @(20, r15), r3
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.l @r2, r3
    mov.l @(8, r15), r2
    mul.l r1, r3
    sts macl, r1
    add r2, r1
    mov.l r1, @r15
    mov.l   .L_0603E554, r3
    jsr @r3
    mov r8, r0
    tst r0, r0
    bt      .L_0603E584
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/gt r9, r0
    bt      .L_0603E530
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    bt      .L_0603E558
.L_0603E530:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_0603E58C
    nop
.L_0603E53C:
    .2byte  0x0668
    .2byte  0xFFFF
.L_0603E540:
    .4byte  sym_060A3E68
.L_0603E544:
    .4byte  sym_060A4C38
.L_0603E548:
    .4byte  sym_060635B0
.L_0603E54C:
    .4byte  sym_060A53B8
.L_0603E550:
    .4byte  sym_060A3F68
.L_0603E554:
    .4byte  sym_06034FFC
.L_0603E558:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    mov.w   DAT_0603e61e, r3
    and r3, r0
    extu.w r0, r0
    mov.l @r15+, r2
    bra     .L_0603E590
    mov.w r0, @r2
.L_0603E584:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_0603E58C:
    extu.w r12, r2
    mov.w r2, @r0
.L_0603E590:
    add #0x1, r10
.L_0603E592:
    mov.l @(16, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_0603E4F6
.L_0603E59A:
    extu.w r14, r14
    shll r14
    mov.l   .L_0603E624, r3
    add r3, r14
    mov #0x1, r2
    mov.w r2, @r14
.L_0603E5A6:
    add #0x38, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global options_render
    .type options_render, @function
options_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x34, r15
    mov.l   .L_0603E628, r8
    mov.w   DAT_0603e61e, r9
    mov r9, r12
    add #0x1, r12
    mov.l   .L_0603E62C, r14
    mov.l r4, @(8, r15)
    mov.l   .L_0603E630, r4
    mov.l   .L_0603E634, r0
    bra     .L_0603E612
    mov.l @r0, r0
.L_0603E5E4:
    mov #0x0, r13
    mov.l   .L_0603E638, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(4, r4)
    mov.w @(4, r4), r0
    bra     .L_0603E60A
    or #0x3, r0
.L_0603E5F8:
    mov #0x1, r13
    mov.w @(4, r4), r0
    and #0xFF, r0
    mov.w r0, @(4, r4)
    mov.w   .L_0603E620, r3
    mov.w @(4, r4), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
.L_0603E60A:
    bra     .L_0603E63C
    mov.w r0, @(4, r4)
.L_0603E60E:
    bra     .L_0603EAB6
    nop
.L_0603E612:
    cmp/eq #0x1, r0
    bt      .L_0603E5E4
    cmp/eq #0x2, r0
    bt      .L_0603E5F8
    bra     .L_0603E60E
    nop

    .global DAT_0603e61e
DAT_0603e61e:
    .2byte  0x7FFF
.L_0603E620:
    .2byte  0x0300
    .2byte  0xFFFF
.L_0603E624:
    .4byte  sym_060A4C40
.L_0603E628:
    .4byte  0x00040000
.L_0603E62C:
    .4byte  sym_0603C0A0
.L_0603E630:
    .4byte  sym_060A3E38
.L_0603E634:
    .4byte  sym_060635A8
.L_0603E638:
    .4byte  0x0000FF00
.L_0603E63C:
    bsr     scene_invalidate_a
    mov.l @(8, r15), r4
    mov.l r0, @r15
    bsr     scene_invalidate_b
    mov.l @(8, r15), r4
    exts.b r13, r10
    mov.l r0, @(8, r15)
    mov r10, r3
    shll2 r10
    shll2 r3
    shll2 r3
    shll r3
    add r3, r10
    exts.b r10, r10
    mov.l   .L_0603E71C, r2
    add r2, r10
    mov.l @r10, r3
    mov.l r3, @(40, r15)
    mov r10, r3
    add #0x8, r3
    mov.l r3, @(24, r15)
    mov.l @r3, r1
    mov.l r1, @(16, r15)
    mov r10, r1
    add #0xC, r1
    mov.l r1, @(32, r15)
    mov.l @r1, r2
    mov.l r2, @(12, r15)
    mov r10, r2
    add #0x14, r2
    mov.l r2, @(28, r15)
    mov.l @r2, r3
    mov.l r3, @(44, r15)
    mov r10, r3
    add #0x18, r3
    mov.l r3, @(20, r15)
    mov.l @r3, r1
    mov.l r1, @(48, r15)
    mov r10, r1
    add #0x20, r1
    mov.l r1, @(4, r15)
    mov.l @r1, r2
    mov.l r2, @(36, r15)
    mov.l   .L_0603E720, r11
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(20, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @r10
    mov.l @(24, r15), r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(24, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(32, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov.l @(4, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    bra     .L_0603E724
    mov.l @(52, r15), r4
    .2byte  0xFFFF
.L_0603E71C:
    .4byte  sym_060A53B8
.L_0603E720:
    .4byte  display_scene_update
.L_0603E724:
    jsr @r11
    nop
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l @r15+, r3
    extu.w r13, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_0603E838, r3
    add r3, r4
    mov.l @r10, r2
    mov.l r2, @(28, r4)
    mov.l @(24, r15), r3
    mov.l @r3, r2
    mov.l r2, @(36, r4)
    mov.l @(32, r15), r3
    mov.l @r3, r2
    mov.l r2, @(40, r4)
    mov.l @(16, r10), r3
    mov.l r3, @(44, r4)
    mov.l @(28, r15), r2
    mov.l @r2, r3
    mov.l r3, @(48, r4)
    mov.l @(20, r15), r11
    mov #0x34, r0
    mov.w @(r0, r4), r3
    mov #0x3C, r0
    mov.w @(r0, r4), r2
    sub r2, r3
    mov.l @r11, r11
    mul.l r3, r11
    sts macl, r11
    mov.l @(28, r10), r3
    mov.l r3, @r15
    mov #0x36, r0
    mov.w @(r0, r4), r3
    mov.l r3, @(8, r15)
    mov #0x3E, r0
    mov.w @(r0, r4), r2
    sub r2, r3
    mov.l @r15, r2
    mul.l r3, r2
    sts macl, r2
    add r2, r11
    mov.l @(4, r15), r6
    mov.l @r6, r6
    mov #0x38, r0
    mov.w @(r0, r4), r7
    mov #0x40, r0
    mov.w @(r0, r4), r3
    mov r3, r0
    mov.w r0, @(12, r15)
    mov.w @(12, r15), r0
    mov r0, r3
    mov r7, r2
    sub r3, r2
    mul.l r2, r6
    sts macl, r3
    add r3, r11
    add #-0x8, r15
    mov.w @(20, r15), r0
    add #-0x8, r15
    mov.l   .L_0603E83C, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0603E840, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_0603E844, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_0603E848, r2
    jsr @r2
    nop
    add r0, r11
    extu.w r13, r5
    mov.l   .L_0603E84C, r3
    shll2 r5
    add r5, r3
    mov.l @r3, r2
    mov.l @(8, r15), r3
    add r2, r11
    mov.l @r15, r2
    mul.l r2, r3
    sts macl, r3
    neg r3, r3
    mul.l r6, r7
    sts macl, r7
    sub r7, r3
    mov.l r3, @(8, r15)
    mov.l   .L_0603E850, r1
    add r1, r5
    mov.l @r5, r0
    tst r0, r0
    bf      .L_0603E7FA
    bra     .L_0603E976
    nop
.L_0603E7FA:
    extu.w r13, r10
    mov.l   .L_0603E838, r3
    mov #0x54, r0
    extu.w r13, r4
    shll2 r10
    shll2 r4
    shll2 r10
    shll2 r10
    shll r10
    add r3, r10
    mov.l @r10, r2
    mov.l   .L_0603E854, r3
    add r3, r2
    mov.l r2, @(r0, r10)
    mov.l r4, @(4, r15)
    mov.l   .L_0603E850, r3
    add r3, r4
    mov.l r4, @r15
    mov.l @r4, r4
    mov.l   .L_0603E858, r2
    add r2, r4
    bsr     scene_invalidate_b
    nop
    mov #0x58, r1
    add r10, r1
    mov.l r0, @r1
    mov.l @r15, r4
    mov.l @r4, r4
    bra     .L_0603E85C
    nop
    .2byte  0xFFFF
.L_0603E838:
    .4byte  sym_060A3E68
.L_0603E83C:
    .4byte  sym_060358EC
.L_0603E840:
    .4byte  0x40F00000
.L_0603E844:
    .4byte  sym_060359E4
.L_0603E848:
    .4byte  sym_060357B8
.L_0603E84C:
    .4byte  sym_060A4C78
.L_0603E850:
    .4byte  sym_060A4C70
.L_0603E854:
    .4byte  0x012C0000
.L_0603E858:
    .4byte  0x005A0000
.L_0603E85C:
    mov.l   .L_0603E944, r3
    add r3, r4
    bsr     scene_invalidate_a
    nop
    mov #0x5C, r1
    add r10, r1
    mov.l r0, @r1
    mov #0x0, r10
    mov.l @(4, r15), r3
    mov.l   .L_0603E948, r2
    mov.w   DAT_0603e93a, r1
    add r2, r3
    mov.l r1, @r3
    extu.w r13, r3
    exts.b r13, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(20, r15)
    shll2 r0
    extu.w r13, r3
    shll r0
    shll2 r3
    add r0, r1
    shll2 r3
    exts.b r1, r1
    mov.l   .L_0603E94C, r0
    shll2 r3
    add r0, r1
    add #0x18, r1
    mov.l r1, @(16, r15)
    shll r3
    mov.l   .L_0603E950, r0
    add r0, r3
    mov.l r3, @(12, r15)
    mov.w   DAT_0603e93c, r2
    muls.w r2, r13
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_0603E954, r0
    add r0, r2
    bra     .L_0603E96A
    mov.l r2, @(4, r15)
.L_0603E8B6:
    mov #0x34, r0
    mov r10, r1
    mov.l @(16, r15), r2
    mov.l @(12, r15), r3
    mov.l @r2, r2
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.w   DAT_0603e93e, r3
    add r3, r1
    mul.l r1, r2
    mov.l @(8, r15), r3
    sts macl, r1
    add r3, r1
    mov.l r1, @r15
    mov.w   .L_0603E940, r0
    mov.l   .L_0603E958, r2
    jsr @r2
    nop
    tst r0, r0
    bt      .L_0603E95C
    mov.l @r15, r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/gt r8, r0
    .word 0x0029
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    .word 0x0029
    xor #0x1, r0
    mov.l @r15+, r3
    or r3, r0
    tst r0, r0
    bt      .L_0603E90E
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_0603E964
    nop
.L_0603E90E:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    and r9, r0
    extu.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3
    bra     .L_0603E968
    nop

    .global DAT_0603e93a
DAT_0603e93a:
    .2byte  0x0333

    .global DAT_0603e93c
DAT_0603e93c:
    .2byte  0x0668

    .global DAT_0603e93e
DAT_0603e93e:
    .2byte  0xFED4
.L_0603E940:
    .2byte  0x0100
    .2byte  0xFFFF
.L_0603E944:
    .4byte  0x005A0000
.L_0603E948:
    .4byte  sym_060A4C38
.L_0603E94C:
    .4byte  sym_060A53B8
.L_0603E950:
    .4byte  sym_060A3E68
.L_0603E954:
    .4byte  sym_060A3F68
.L_0603E958:
    .4byte  sym_06034FFC
.L_0603E95C:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_0603E964:
    extu.w r12, r2
    mov.w r2, @r0
.L_0603E968:
    add #0x1, r10
.L_0603E96A:
    mov.l @(20, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_0603E8B6
    bra     .L_0603EAAA
    nop
.L_0603E976:
    extu.w r13, r10
    mov.l   .L_0603EA4C, r3
    mov #0x54, r0
    mov.l   .L_0603EA50, r4
    shll2 r10
    shll2 r10
    shll2 r10
    shll r10
    add r3, r10
    mov.l @r10, r2
    bsr     scene_invalidate_b
    mov.l r2, @(r0, r10)
    mov #0x58, r1
    mov.l   .L_0603EA50, r4
    add r10, r1
    bsr     scene_invalidate_a
    mov.l r0, @r1
    mov #0x5C, r1
    extu.w r13, r3
    add r10, r1
    shll2 r3
    mov.l r0, @r1
    mov #0x0, r10
    mov.l   .L_0603EA54, r2
    mov.l   .L_0603EA58, r1
    add r2, r3
    mov.w @r1, r1
    extu.w r1, r1
    add #-0x1, r1
    mov.l r1, @r3
    extu.w r13, r3
    exts.b r13, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(20, r15)
    shll2 r0
    shll r0
    add r0, r1
    exts.b r1, r1
    mov.l   .L_0603EA5C, r0
    add r0, r1
    add #0x18, r1
    mov.l r1, @(16, r15)
    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    mov.l   .L_0603EA4C, r0
    add r0, r3
    mov.l r3, @(12, r15)
    mov.w   DAT_0603ea46, r2
    muls.w r2, r13
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_0603EA60, r0
    add r0, r2
    bra     .L_0603EAA2
    mov.l r2, @(4, r15)
.L_0603E9F2:
    mov #0x34, r0
    mov r10, r1
    mov.l @(16, r15), r2
    mov.l @(12, r15), r3
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.l @r2, r3
    mov.l @(8, r15), r2
    mul.l r1, r3
    sts macl, r1
    add r2, r1
    mov.l r1, @r15
    mov.w   .L_0603EA48, r0
    mov.l   .L_0603EA64, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_0603EA94
    mov.l @r15, r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/gt r8, r0
    .word 0x0029
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    .word 0x0029
    xor #0x1, r0
    mov.l @r15+, r3
    or r3, r0
    tst r0, r0
    bt      .L_0603EA68
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_0603EA9C
    nop

    .global DAT_0603ea46
DAT_0603ea46:
    .2byte  0x0668
.L_0603EA48:
    .2byte  0x0100
    .2byte  0xFFFF
.L_0603EA4C:
    .4byte  sym_060A3E68
.L_0603EA50:
    .4byte  0x005A0000
.L_0603EA54:
    .4byte  sym_060A4C38
.L_0603EA58:
    .4byte  sym_060635AE
.L_0603EA5C:
    .4byte  sym_060A53B8
.L_0603EA60:
    .4byte  sym_060A3F68
.L_0603EA64:
    .4byte  sym_06034FFC
.L_0603EA68:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    and r9, r0
    extu.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3
    bra     .L_0603EAA0
    nop
.L_0603EA94:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_0603EA9C:
    extu.w r12, r2
    mov.w r2, @r0
.L_0603EAA0:
    add #0x1, r10
.L_0603EAA2:
    mov.l @(20, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_0603E9F2
.L_0603EAAA:
    extu.w r13, r13
    shll r13
    mov.l   .L_0603EB00, r3
    add r3, r13
    mov #0x1, r2
    mov.w r2, @r13
.L_0603EAB6:
    add #0x34, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global display_channel_handler
    .type display_channel_handler, @function
display_channel_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x24, r15
    mov.l r4, @r15
    mov.l   .L_0603EB04, r0
    bra     .L_0603EAF2
    mov.l @r0, r0
.L_0603EAE6:
    bra     .L_0603EB08
    mov #0x0, r10
.L_0603EAEA:
    bra     .L_0603EB08
    mov #0x1, r10
.L_0603EAEE:
    bra     .L_0603EC18
    nop
.L_0603EAF2:
    cmp/eq #0x1, r0
    bt      .L_0603EAE6
    cmp/eq #0x2, r0
    bt      .L_0603EAEA
    bra     .L_0603EAEE
    nop
    .2byte  0xFFFF
.L_0603EB00:
    .4byte  sym_060A4C40
.L_0603EB04:
    .4byte  sym_060635A8
.L_0603EB08:
    mov.l   .L_0603EC2C, r3
    jsr @r3
    mov.l @r15, r4
    mov r0, r13
    mov.l   .L_0603EC30, r3
    jsr @r3
    mov.l @r15, r4
    mov r0, r11
    exts.b r10, r12
    mov r12, r3
    shll2 r12
    shll2 r3
    shll2 r3
    shll r3
    add r3, r12
    exts.b r12, r12
    mov.l   .L_0603EC34, r2
    add r2, r12
    mov.l @r12, r9
    mov r12, r8
    add #0x4, r8
    mov.l @r8, r3
    mov.l r3, @(12, r15)
    mov r12, r3
    add #0xC, r3
    mov.l r3, @r15
    mov.l @r3, r1
    mov.l r1, @(24, r15)
    mov r12, r1
    add #0x10, r1
    mov.l r1, @(16, r15)
    mov.l @r1, r2
    mov.l r2, @(20, r15)
    mov r12, r2
    add #0x18, r2
    mov.l r2, @(32, r15)
    mov.l @r2, r3
    mov.l r3, @(8, r15)
    mov r12, r3
    add #0x1C, r3
    mov r11, r5
    mov.l r3, @(28, r15)
    mov.l @r3, r1
    mov.l r1, @(4, r15)
    mov.l   .L_0603EC38, r14
    jsr @r14
    mov r9, r4
    mov.l r0, @-r15
    mov r13, r5
    jsr @r14
    mov.l @(16, r15), r4
    mov.l @r15+, r3
    mov r13, r5
    add r3, r0
    mov.l r0, @r12
    jsr @r14
    mov r9, r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(16, r15), r4
    mov r11, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l r0, @r8
    mov.l @r15, r2
    mov.l r2, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r13, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r13, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(16, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r11, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(32, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    mov.l r0, @-r15
    mov r13, r5
    jsr @r14
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    mov r13, r5
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    extu.w r10, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_0603EC3C, r3
    add r3, r4
    mov.l @r12, r2
    mov.l r2, @(28, r4)
    mov.l @r8, r3
    mov.l r3, @(32, r4)
    mov.l @r15, r2
    mov.l @r2, r3
    mov.l r3, @(40, r4)
    mov.l @(16, r15), r2
    mov.l @r2, r3
    mov.l r3, @(44, r4)
.L_0603EC18:
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603EC2C:
    .4byte  scene_invalidate_a
.L_0603EC30:
    .4byte  scene_invalidate_b
.L_0603EC34:
    .4byte  sym_060A53B8
.L_0603EC38:
    .4byte  display_scene_update
.L_0603EC3C:
    .4byte  sym_060A3E68

    .global hud_update_main
    .type hud_update_main, @function
hud_update_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov #0x0, r8
    mov.l   .L_0603ECA0, r11
    mov.l   .L_0603ECA4, r0
    bra     .L_0603EC68
    mov.l @r0, r0
.L_0603EC5C:
    bra     .L_0603EC74
    extu.w r8, r14
.L_0603EC60:
    bra     .L_0603EC74
    mov #0x1, r14
.L_0603EC64:
    bra     .L_0603ED94
    nop
.L_0603EC68:
    cmp/eq #0x1, r0
    bt      .L_0603EC5C
    cmp/eq #0x2, r0
    bt      .L_0603EC60
    bra     .L_0603EC64
    nop
.L_0603EC74:
    extu.w r14, r5
    mov.l   .L_0603ECA8, r3
    shll2 r5
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603ECB4
    mov.l   .L_0603ECAC, r3
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_0603EC96
    mov.l   .L_0603ECB0, r3
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603ECB4
.L_0603EC96:
    extu.w r14, r0
    shll2 r0
    bra     .L_0603ED94
    mov.l r8, @(r0, r11)
    .2byte  0xFFFF
.L_0603ECA0:
    .4byte  sym_060A4C70
.L_0603ECA4:
    .4byte  sym_060635A8
.L_0603ECA8:
    .4byte  sym_060A4C4C
.L_0603ECAC:
    .4byte  sym_060A4C60
.L_0603ECB0:
    .4byte  sym_060A4C78
.L_0603ECB4:
    extu.w r14, r5
    shll2 r5
    add r11, r5
    mov.l @r5, r3
    add r4, r3
    mov r3, r2
    mov.l r3, @r5
    mov.l   .L_0603EDA8, r3
    cmp/ge r3, r2
    bf      .L_0603ECD4
    extu.w r14, r0
    shll2 r0
    mov.l   .L_0603EDA8, r3
    mov.l @(r0, r11), r2
    sub r3, r2
    mov.l r2, @(r0, r11)
.L_0603ECD4:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r11), r3
    cmp/pz r3
    bt      .L_0603ECEA
    extu.w r14, r0
    shll2 r0
    mov.l   .L_0603EDA8, r3
    mov.l @(r0, r11), r2
    add r3, r2
    mov.l r2, @(r0, r11)
.L_0603ECEA:
    extu.w r14, r12
    mov.l   .L_0603EDB0, r3
    extu.w r14, r9
    mov.l   .L_0603EDAC, r10
    shll2 r12
    shll2 r9
    shll2 r12
    mov r9, r13
    shll2 r12
    add r11, r13
    shll r12
    add r3, r12
    mov.l   .L_0603EDB4, r3
    add r9, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r2
    mov.l r2, @(8, r15)
    mov.l   .L_0603EDB8, r2
    jsr @r2
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @(8, r15), r5
    mov.l @(8, r15), r3
    sub r0, r3
    mov.l r3, @-r15
    mov.l   .L_0603EDBC, r3
    add r9, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r1
    mov.l r1, @-r15
    mov.l   .L_0603EDC0, r2
    jsr @r2
    mov.l @r13, r4
    neg r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @r12
    mov.l @r15, r2
    mov.l @r2, r3
    mov.l r3, @-r15
    mov.l @(8, r15), r5
    mov.l @r5, r1
    mov.l r1, @-r15
    mov.l   .L_0603EDC0, r3
    jsr @r3
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    mov.l @r5, r1
    mov.l r1, @-r15
    mov.l   .L_0603EDB8, r3
    jsr @r3
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @(4, r12)
    mov.l r8, @(8, r12)
    mov.l   .L_0603EDC0, r3
    jsr @r3
    mov.l @r13, r4
    neg r0, r0
    mov.l r0, @(12, r12)
    mov.l   .L_0603EDB8, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(16, r12)
    mov.l   .L_0603EDB8, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(20, r12)
    mov.l   .L_0603EDC0, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(24, r12)
.L_0603ED94:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603EDA8:
    .4byte  0x01680000
.L_0603EDAC:
    .4byte  display_scene_update
.L_0603EDB0:
    .4byte  sym_060A3E68
.L_0603EDB4:
    .4byte  sym_060A53A8
.L_0603EDB8:
    .4byte  scene_invalidate_b
.L_0603EDBC:
    .4byte  sym_060A53B0
.L_0603EDC0:
    .4byte  scene_invalidate_a
