
    .section .text.FUN_0600BB94


    .global camera_system
    .type camera_system, @function
camera_system:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600BC34, r8
    mov.l   .L_0600BC38, r9
    mov.l   .L_0600BC3C, r10
    mov.l   .L_0600BC40, r11
    mov.l   .L_0600BC44, r12
    mov.l   .L_0600BC48, r14
    mov.l @r14, r14
    mov.l   .L_0600BC4C, r7
    mov #0x2, r6
    mov.w   DAT_0600bc2c, r5
    mov #0x1, r4
    mov.l   .L_0600BC50, r13
    mov.l   .L_0600BC54, r0
    mov.b @r0, r0
    bra     .L_0600BD7A
    extu.b r0, r0
.L_0600BBC6:
    mov.l   .L_0600BC58, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600BBD2
    bra     .L_0600BD96
    nop
.L_0600BBD2:
    mov.l @r7, r3
    cmp/hi r4, r3
    bt      .L_0600BBE2
    mov.l @(32, r14), r3
    mov.w   DAT_0600bc2e, r0
    mov.l @(r0, r14), r2
    add r2, r3
    mov.l r3, @(4, r12)
.L_0600BBE2:
    mov.l   .L_0600BC5C, r4
    .byte   0xB3, 0xE0    /* bsr 0x0600C3A8 (external) */
    mov.w @r4, r4
    bra     .L_0600BD96
    nop
.L_0600BBEC:
    mov.w   .L_0600BC30, r0
    mov #0x30, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BBFA
    bra     .L_0600BC98
    nop
.L_0600BBFA:
    mov #0x28, r3
    mov.w   .L_0600BC30, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BC0C
    mov.l @r13, r2
    sub r5, r2
    bra     .L_0600BC98
    mov.l r2, @r13
.L_0600BC0C:
    mov.w   .L_0600BC30, r0
    mov #0x10, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BC1A
    bra     .L_0600BC98
    nop
.L_0600BC1A:
    mov #0x8, r3
    mov.w   .L_0600BC30, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BC60
    mov.l @r13, r2
    add r5, r2
    bra     .L_0600BC98
    mov.l r2, @r13

    .global DAT_0600bc2c
DAT_0600bc2c:
    .2byte  0x2C00

    .global DAT_0600bc2e
DAT_0600bc2e:
    .2byte  0x01D8
.L_0600BC30:
    .2byte  0x01BC
    .2byte  0xFFFF
.L_0600BC34:
    .4byte  sym_06038520
.L_0600BC38:
    .4byte  sym_06063E28
.L_0600BC3C:
    .4byte  sym_06063E30
.L_0600BC40:
    .4byte  sym_06063EF8
.L_0600BC44:
    .4byte  sym_06063EEC
.L_0600BC48:
    .4byte  sym_0607E944
.L_0600BC4C:
    .4byte  sym_06063E20
.L_0600BC50:
    .4byte  sym_06063E24
.L_0600BC54:
    .4byte  sym_06078654
.L_0600BC58:
    .4byte  sym_0605A1C4
.L_0600BC5C:
    .4byte  sym_06063D9A
.L_0600BC60:
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r5
    mov r5, r0
    cmp/eq #0x8, r0
    bt      .L_0600BC70
    mov r5, r0
    cmp/eq #0x7, r0
    bf      .L_0600BC98
.L_0600BC70:
    mov.l   .L_0600BCF0, r3
    mov #0x0, r5
    mov.l r6, @r3
    mov.l   .L_0600BCF4, r3
    mov.l r4, @r3
    mov.l   .L_0600BCF8, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_0600BCFC, r2
    mov.l r2, @r13
    mov.l   .L_0600BD00, r3
    mov.l   .L_0600BD04, r2
    mov.l r3, @r2
    mov.l   .L_0600BD08, r3
    mov.l r3, @r9
    mov.l   .L_0600BD0C, r2
    mov.l   .L_0600BD10, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l r2, @r10
.L_0600BC98:
    mov.l   .L_0600BD14, r4
    .byte   0xB3, 0x85    /* bsr 0x0600C3A8 (external) */
    mov.w @r4, r4
    bra     .L_0600BD96
    nop
.L_0600BCA2:
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_0600BCAE
    bra     .L_0600BD50
    mov.l r6, @r7
.L_0600BCAE:
    mov #0x30, r3
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BCBC
    bra     .L_0600BD50
    nop
.L_0600BCBC:
    mov.w   DAT_0600bcee, r0
    mov #0x28, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BCCE
    mov.l @r13, r2
    sub r5, r2
    bra     .L_0600BD50
    mov.l r2, @r13
.L_0600BCCE:
    mov #0x10, r3
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BCDC
    bra     .L_0600BD50
    nop
.L_0600BCDC:
    mov.w   DAT_0600bcee, r0
    mov #0x8, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_0600BD18
    mov.l @r13, r2
    add r5, r2
    bra     .L_0600BD50
    mov.l r2, @r13

    .global DAT_0600bcee
DAT_0600bcee:
    .2byte  0x01BC
.L_0600BCF0:
    .4byte  sym_06063E1C
.L_0600BCF4:
    .4byte  sym_06059F30
.L_0600BCF8:
    .4byte  channel_nibble_config
.L_0600BCFC:
    .4byte  0x00058000
.L_0600BD00:
    .4byte  0x0000F300
.L_0600BD04:
    .4byte  sym_06063E34
.L_0600BD08:
    .4byte  0x006E0000
.L_0600BD0C:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_0600BD10:
    .4byte  sym_06063E2C
.L_0600BD14:
    .4byte  sym_06063D9A
.L_0600BD18:
    mov.w   DAT_0600bdac, r0
    mov.l @(r0, r14), r5
    mov r5, r0
    cmp/eq #0x8, r0
    bt      .L_0600BD28
    mov r5, r0
    cmp/eq #0x7, r0
    bf      .L_0600BD50
.L_0600BD28:
    mov.l   .L_0600BDB0, r3
    mov #0x0, r5
    mov.l r6, @r3
    mov.l   .L_0600BDB4, r3
    mov.l r4, @r3
    mov.l   .L_0600BDB8, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_0600BDBC, r2
    mov.l r2, @r13
    mov.l   .L_0600BDC0, r3
    mov.l   .L_0600BDC4, r2
    mov.l r3, @r2
    mov.l   .L_0600BDC8, r3
    mov.l r3, @r9
    mov.l   .L_0600BDCC, r2
    mov.l   .L_0600BDD0, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l r2, @r10
.L_0600BD50:
    mov.l @(32, r14), r3
    mov.w   DAT_0600bdae, r0
    mov.l @(r0, r14), r2
    sub r2, r3
    mov.l r3, @(4, r12)
    mov.l @(r0, r14), r3
    mov.l   .L_0600BDD4, r2
    neg r3, r3
    add r2, r3
    shar r3
    shar r3
    shar r3
    shar r3
    mov.l @(r0, r14), r1
    add r3, r1
    bra     .L_0600BD96
    mov.l r1, @(r0, r14)
.L_0600BD72:
    mov #0x3, r2
    mov.l r2, @r7
.L_0600BD76:
    bra     .L_0600BD96
    nop
.L_0600BD7A:
    cmp/eq #0x0, r0
    bt      .L_0600BD76
    cmp/eq #0x1, r0
    bf      .L_0600BD86
    bra     .L_0600BBC6
    nop
.L_0600BD86:
    cmp/eq #0x4, r0
    bt      .L_0600BCA2
    cmp/eq #0x6, r0
    bt      .L_0600BD72
    cmp/eq #0x7, r0
    bf      .L_0600BD96
    bra     .L_0600BBEC
    nop
.L_0600BD96:
    mov.l   .L_0600BDD8, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600BDE0
    mov.l @(4, r12), r13
    shll8 r13
    shll2 r13
    mov.l   .L_0600BDDC, r3
    add r3, r13
    bra     .L_0600BDEC
    nop

    .global DAT_0600bdac
DAT_0600bdac:
    .2byte  0x01BC

    .global DAT_0600bdae
DAT_0600bdae:
    .2byte  0x0244
.L_0600BDB0:
    .4byte  sym_06063E1C
.L_0600BDB4:
    .4byte  sym_06059F30
.L_0600BDB8:
    .4byte  channel_nibble_config
.L_0600BDBC:
    .4byte  0x00058000
.L_0600BDC0:
    .4byte  0x0000F300
.L_0600BDC4:
    .4byte  sym_06063E34
.L_0600BDC8:
    .4byte  0x006E0000
.L_0600BDCC:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_0600BDD0:
    .4byte  sym_06063E2C
.L_0600BDD4:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_0600BDD8:
    .4byte  sym_06078663
.L_0600BDDC:
    .4byte  0x01A00000
.L_0600BDE0:
    mov.l @(4, r12), r13
    shll8 r13
    shll2 r13
    neg r13, r13
    mov.l   .L_0600BE50, r3
    add r3, r13
.L_0600BDEC:
    mov.l   .L_0600BE54, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600BE3A
    mov.l   .L_0600BE58, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l @r9, r5
    mov.l   .L_0600BE5C, r3
    jsr @r3
    mov r13, r4
    jsr @r8
    nop
    mov r15, r6
    mov r15, r5
    mov.l   .L_0600BE60, r3
    add #0x4, r6
    jsr @r3
    mov.l @(4, r12), r4
    mov.l @(16, r14), r2
    mov.l @r15, r3
    sub r3, r2
    mov.l   .L_0600BE64, r1
    mov.l @r1, r1
    add r1, r2
    mov.l r2, @r11
    mov.l @(20, r14), r3
    mov.l @r10, r2
    add r2, r3
    mov.l r3, @(4, r11)
    mov.l @(24, r14), r3
    mov.l @(4, r15), r2
    add r2, r3
    mov.l   .L_0600BE68, r1
    mov.l @r1, r1
    add r1, r3
    bra     .L_0600BF28
    mov.l r3, @(8, r11)
.L_0600BE3A:
    mov.w   .L_0600BE4C, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_0600BE70
    mov.l   .L_0600BE6C, r3
    jsr @r3
    nop
    bra     .L_0600BE7A
    nop
.L_0600BE4C:
    .2byte  0x01BC
    .2byte  0xFFFF
.L_0600BE50:
    .4byte  0xFFA00000
.L_0600BE54:
    .4byte  sym_06082A30
.L_0600BE58:
    .4byte  sym_0603850C
.L_0600BE5C:
    .4byte  scene_data_write_abs
.L_0600BE60:
    .4byte  sincos_pair
.L_0600BE64:
    .4byte  sym_06082A70
.L_0600BE68:
    .4byte  sym_06082A78
.L_0600BE6C:
    .4byte  scene_fallback_render
.L_0600BE70:
    mov.w   DAT_0600bf3c, r4
    mov.l   .L_0600BF40, r3
    mov.l r4, @r3
    mov.l   .L_0600BF44, r3
    mov.l r4, @r3
.L_0600BE7A:
    mov.l   .L_0600BF48, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l @r9, r5
    mov.l   .L_0600BF4C, r3
    jsr @r3
    mov r13, r4
    jsr @r8
    nop
    mov.l @(28, r14), r13
    shll8 r13
    cmp/pz r13
    bt      .L_0600BE98
    shll r13
.L_0600BE98:
    mov.l   .L_0600BF48, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r6
    mov.l   .L_0600BF50, r0
    mov.l   .L_0600BF54, r3
    mov.l   .L_0600BF58, r2
    mov.w @r0, r0
    mov.l @r2, r2
    extu.w r0, r0
    add r13, r2
    and #0xC, r0
    mov r0, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll8 r5
    shll r5
    add r2, r5
    mov.l   .L_0600BF4C, r2
    jsr @r2
    mov r6, r4
    jsr @r8
    nop
    mov.l   .L_0600BF5C, r3
    jsr @r3
    nop
    mov r15, r6
    mov r15, r5
    mov.l   .L_0600BF60, r3
    add #0x4, r6
    jsr @r3
    mov.l @(4, r12), r4
    mov.l @(16, r14), r2
    mov.l @r15, r3
    sub r3, r2
    mov.l r2, @r11
    mov.l @(20, r14), r3
    mov.l @r10, r2
    add r2, r3
    mov.l r3, @(4, r11)
    mov.l @(24, r14), r3
    mov.l @(4, r15), r2
    add r2, r3
    mov.l r3, @(8, r11)
    bsr     .L_0600BF70
    nop
    mov.l @(4, r12), r4
    mov.l @(32, r14), r2
    mov.l   .L_0600BF64, r3
    jsr @r3
    sub r2, r4
    mov r0, r5
    mov r0, r2
    mov.l   .L_0600BF68, r3
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    neg r2, r2
    mov.l r2, @r3
    mov.l   .L_0600BF6C, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov r0, r4
    mov.l @(8, r12), r2
    add r2, r4
    shar r4
    mov.l r4, @(8, r12)
.L_0600BF28:
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

    .global DAT_0600bf3c
DAT_0600bf3c:
    .2byte  0x6666
    .2byte  0xFFFF
.L_0600BF40:
    .4byte  sym_06063F04
.L_0600BF44:
    .4byte  sym_06063F08
.L_0600BF48:
    .4byte  sym_0603850C
.L_0600BF4C:
    .4byte  scene_data_write_abs
.L_0600BF50:
    .4byte  sym_06063F46
.L_0600BF54:
    .4byte  sym_0605BDCC
.L_0600BF58:
    .4byte  sym_06063E2C
.L_0600BF5C:
    .4byte  obj_state_manager
.L_0600BF60:
    .4byte  sincos_pair
.L_0600BF64:
    .4byte  cos_lookup
.L_0600BF68:
    .4byte  sym_06078668
.L_0600BF6C:
    .4byte  fpmul
.L_0600BF70:
    sts.l macl, @-r15
    mov.l   .L_0600BFE8, r4
    mov.w   DAT_0600bfe2, r3
    mov.l   .L_0600BFEC, r2
    mov.l   .L_0600BFF0, r5
    mov.l @r4, r4
    mov.l @r2, r2
    mov.l @(28, r4), r4
    exts.w r4, r4
    mul.l r3, r4
    exts.w r2, r3
    sts macl, r4
    mov.l   .L_0600BFF4, r2
    shar r4
    mov.l @r2, r2
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    mov.l   .L_0600BFF8, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf/s    .L_0600BFDA
    exts.w r4, r4
    mov.l @r5, r3
    exts.w r4, r4
    mov.w   .L_0600BFE6, r1
    mov.w   .L_0600BFE4, r2
    exts.w r3, r3
    mul.l r2, r3
    sts macl, r3
    mul.l r1, r4
    sts macl, r4
    add r4, r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    mov.l r3, @r5
    bra     .L_0600BFDE
    nop
.L_0600BFDA:
    exts.w r4, r4
    mov.l r4, @r5
.L_0600BFDE:
    rts
    lds.l @r15+, macl

    .global DAT_0600bfe2
DAT_0600bfe2:
    .2byte  0x0384
.L_0600BFE4:
    .2byte  0x0320
.L_0600BFE6:
    .2byte  0x00E0
.L_0600BFE8:
    .4byte  sym_0607E944
.L_0600BFEC:
    .4byte  sym_06063E34
.L_0600BFF0:
    .4byte  sym_06063EEC
.L_0600BFF4:
    .4byte  sym_06063E1C
.L_0600BFF8:
    .4byte  sym_06063E20
