
    .section .text.FUN_0602CA84


    .global vdp1_coord_setup
    .type vdp1_coord_setup, @function
vdp1_coord_setup:
    sts.l pr, @-r15
    mov.w   DAT_0602cb04, r1
    mov.l @(r0, r1), r2
    neg r2, r2
    mov.w   DAT_0602cb06, r1
    mov.l   .L_pool_0602CB14, r4
    mov.l @(r0, r1), r5
    neg r5, r5
    dmuls.l r4, r5
    mov r0, r14
    sts mach, r4
    sts macl, r6
    xtrct r4, r6
    mov.l   .L_pool_0602CB18, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r7
    xtrct r4, r7
    mov.w   DAT_0602cb08, r1
    mov.l @(r0, r1), r4
    dmuls.l r4, r2
    mov.w   DAT_0602cb0a, r3
    mov.l @(r0, r3), r8
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    dmuls.l r8, r2
    mov r5, r12
    xor r6, r12
    cmp/pz r12
    bf      .L_0602CAC4
    neg r6, r6
.L_0602CAC4:
    add r5, r6
    mov.l r6, @-r15
    sts mach, r8
    sts macl, r2
    xtrct r8, r2
    mov r2, r12
    xor r7, r12
    cmp/pz r12
    bf      .L_0602CAD8
    neg r7, r7
.L_0602CAD8:
    add r2, r7
    mov.w   DAT_0602cb0c, r1
    mov.l r7, @(r0, r1)
    mov.w   DAT_0602cb0e, r1
    mov.w   .L_wpool_0602CB10, r2
    mov.l @(r0, r1), r3
    mov r3, r8
    mov.l @(r0, r2), r4
    mov r4, r9
    sub r4, r3
    cmp/pz r3
    bt      .L_0602CAF2
    neg r3, r3
.L_0602CAF2:
    cmp/pz r6
    bt      .L_0602CAF8
    neg r6, r6
.L_0602CAF8:
    cmp/ge r6, r3
    bt      .L_0602CB1C
    shar r3
    shar r3
    bra     .L_0602CB22
    add r3, r6

    .global DAT_0602cb04
DAT_0602cb04:
    .2byte  0x0104                      /* car+0x104: vel_state_y (longword, 16.16 FP) */

    .global DAT_0602cb06
DAT_0602cb06:
    .2byte  0x0100                      /* car+0x100: vel_state_x (longword, 16.16 FP) */

    .global DAT_0602cb08
DAT_0602cb08:
    .2byte  0x0060                      /* car+0x60: angular_vel_a (longword) */

    .global DAT_0602cb0a
DAT_0602cb0a:
    .2byte  0x0064                      /* car+0x64: angular_vel_b (longword) */

    .global DAT_0602cb0c
DAT_0602cb0c:
    .2byte  0x0148                      /* car+0x148: coord_y_output (longword) */

    .global DAT_0602cb0e
DAT_0602cb0e:
    .2byte  0x00EC                      /* car+0xEC: blend_result_a (longword, 70% blend) */
.L_wpool_0602CB10:
    .2byte  0x00F8                      /* car+0xF8: final_blend output (longword) */
    .2byte  0x0000                      /* alignment padding */
.L_pool_0602CB14:
    .4byte  0x03700000                  /* ~880.0 FP16.16 (horizontal scale factor) */
.L_pool_0602CB18:
    .4byte  0x02D00000                  /* ~720.0 FP16.16 (vertical scale factor) */
.L_0602CB1C:
    shar r6
    shar r6
    add r3, r6
.L_0602CB22:
    mov.l   .L_0602CB7C, r10
    mov.w   DAT_0602cb72, r1
    mov.l @(r0, r1), r4
    cmp/gt r6, r4
    bt      .L_0602CB36
    mov.l   .L_0602CB80, r0
    jsr @r0
    mov r6, r5
    mov r0, r10
    mov r14, r0
.L_0602CB36:
    mov.w   DAT_0602cb74, r1
    mov.l r10, @(r0, r1)
    neg r8, r8
    mov.w   DAT_0602cb76, r1
    mov.l @(r0, r1), r2
    add r9, r2
    sub r2, r8
    mov.l @r15+, r6
    mov.l r8, @-r15
    mov.l r2, @-r15
    mov.w   DAT_0602cb78, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602cb7a, r2
    mov.l @(r0, r2), r4
    sub r4, r3
    mov r3, r6
    mov #0x0, r10
    cmp/pz r7
    bt      .L_0602CB5E
    neg r7, r7
.L_0602CB5E:
    sub r9, r3
    cmp/pz r3
    bf      .L_0602CB8C
    cmp/ge r7, r3
    bf      .L_0602CB84
    mov #0x1, r10
    shar r7
    shar r7
    bra     .L_0602CBA0
    add r7, r3

    .global DAT_0602cb72
DAT_0602cb72:
    .2byte  0x0140                      /* car+0x140: display_scale_x (longword, 16.16 FP) */

    .global DAT_0602cb74
DAT_0602cb74:
    .2byte  0x0108                      /* car+0x108: coord_scale_x (longword, 16.16 FP) */

    .global DAT_0602cb76
DAT_0602cb76:
    .2byte  0x00F4                      /* car+0xF4: force_aux (heading contribution) */

    .global DAT_0602cb78
DAT_0602cb78:
    .2byte  0x00F0                      /* car+0xF0: blend_result_b (longword, 50% blend) */

    .global DAT_0602cb7a
DAT_0602cb7a:
    .2byte  0x011C                      /* car+0x11C: decel_coeff (longword, 16.16 FP) */
.L_0602CB7C:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_0602CB80:
    .4byte  fpdiv_setup                 /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_0602CB84:
    shar r3
    shar r3
    bra     .L_0602CBA0
    add r7, r3
.L_0602CB8C:
    neg r3, r3
    cmp/ge r7, r3
    bt      .L_0602CB9A
    shar r3
    shar r3
    bra     .L_0602CBA0
    add r7, r3
.L_0602CB9A:
    shar r7
    shar r7
    add r7, r3
.L_0602CBA0:
    mov #0x1, r11
    mov.w   DAT_0602cc9c, r1
    shll16 r11
    mov.l @(r0, r1), r4
    cmp/ge r3, r4
    bt      .L_0602CBB6
    mov.l   .L_0602CCBC, r0
    jsr @r0
    mov r3, r5
    mov r0, r11
    mov r14, r0
.L_0602CBB6:
    mov.w   DAT_0602cc9e, r1
    mov.l r11, @(r0, r1)
    tst r10, r10
    bt      .L_0602CBD2
    mov.l   .L_pool_0602CCC0, r2
    cmp/gt r2, r11
    bt      .L_0602CBD2
    mov.w   DAT_0602cca0, r1
    mov.l @(r0, r1), r2
    cmp/pl r2
    bt      .L_0602CBD2
    bsr     sym_0602CCD0
    nop
    mov r14, r0
.L_0602CBD2:
    neg r6, r6
    mov.l @r15+, r2
    sub r2, r6
    mov.l r6, @-r15
    mov.w   DAT_0602cca2, r1
    mov.l @(r0, r1), r2
    neg r2, r2
    shar r2
    mov.w   DAT_0602cca4, r1
    shar r2
    shar r2
    mov.l r2, @(r0, r1)
    mov.w   DAT_0602cca6, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_0602CC1C
    mov.w   DAT_0602cca8, r1
    mov.w   DAT_0602ccaa, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    mov r3, r7
    sub r4, r3
    sub r7, r3
    neg r4, r11
    shar r3
    shar r11
    shar r3
    shar r11
    add r3, r7
    add r4, r11
    mov.l r7, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov #0x0, r11
    mov.w   DAT_0602ccac, r1
    mov.w   DAT_0602ccae, r2
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
.L_0602CC1C:
    mov.w   DAT_0602ccb0, r1
    mov #0x0, r11
    mov.w @(r0, r1), r4
    tst r4, r4
    bt      .L_0602CC40
    mov.w   DAT_0602cca4, r1
    mov.w   DAT_0602cca8, r2
    mov.w   DAT_0602ccaa, r3
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov.l r11, @(r0, r3)
    mov.w   DAT_0602ccac, r1
    mov.w   DAT_0602ccae, r2
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov.l   .L_0602CCC4, r2
    mov.w   DAT_0602ccb2, r1
    mov.l r2, @(r0, r1)
.L_0602CC40:
    .byte   0xB0, 0x54    /* bsr 0x0602CCEC (external) */
    nop
    mov.l @r15+, r9
    mov.l @r15+, r5
    mov.w   DAT_0602ccb4, r1
    mov.l @(r0, r1), r4
    mov.w   DAT_0602cc9e, r1
    mov.l @(r0, r1), r2
    mov.w   DAT_0602ccb6, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602CCC8, r1
    mov.w   DAT_0602ccb8, r10
    mov.w @(r0, r10), r10
    mov #0x4, r6
    cmp/eq r6, r10
    bt      .L_0602CC68
    mov #0x5, r6
    cmp/eq r6, r10
    bt      .L_0602CC68
    mov.l   .L_pool_0602CCCC, r1
.L_0602CC68:
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r6
    xtrct r4, r6
    dmuls.l r9, r2
    sts mach, r9
    sts macl, r2
    xtrct r9, r2
    add r2, r6
    sub r3, r6
    dmuls.l r6, r1
    mov.w   DAT_0602ccba, r4
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    lds.l @r15+, pr
    rts
    mov.l r3, @(r0, r4)

    .global DAT_0602cc9c
DAT_0602cc9c:
    .2byte  0x0144                      /* car+0x144: display_scale_y (longword, 16.16 FP) */

    .global DAT_0602cc9e
DAT_0602cc9e:
    .2byte  0x010C                      /* car+0x10C: coord_scale_y (longword, 16.16 FP) */

    .global DAT_0602cca0
DAT_0602cca0:
    .2byte  0x00D8                      /* car+0xD8: gear_rotation state (longword) */

    .global DAT_0602cca2
DAT_0602cca2:
    .2byte  0x00D0                      /* car+0xD0: yaw_deflection (longword) */

    .global DAT_0602cca4
DAT_0602cca4:
    .2byte  0x0040                      /* car+0x40: obj_data pointer (longword) */

    .global DAT_0602cca6
DAT_0602cca6:
    .2byte  0x0150                      /* car+0x150: clip_flags (word) */

    .global DAT_0602cca8
DAT_0602cca8:
    .2byte  0x0058                      /* car+0x58: render_param_a (longword) */

    .global DAT_0602ccaa
DAT_0602ccaa:
    .2byte  0x005C                      /* car+0x5C: render_param_b (longword) */

    .global DAT_0602ccac
DAT_0602ccac:
    .2byte  0x0060                      /* car+0x60: angular_vel_a (longword) */

    .global DAT_0602ccae
DAT_0602ccae:
    .2byte  0x0064                      /* car+0x64: angular_vel_b (longword) */

    .global DAT_0602ccb0
DAT_0602ccb0:
    .2byte  0x0250                      /* car+0x250: collision_state (word) */

    .global DAT_0602ccb2
DAT_0602ccb2:
    .2byte  0x0110                      /* car+0x110: depth_offset (longword, 16.16 FP) */

    .global DAT_0602ccb4
DAT_0602ccb4:
    .2byte  0x0108                      /* car+0x108: coord_scale_x (longword, 16.16 FP) */

    .global DAT_0602ccb6
DAT_0602ccb6:
    .2byte  0x0114                      /* car+0x114: lighting_output (longword) */

    .global DAT_0602ccb8
DAT_0602ccb8:
    .2byte  0x007C                      /* car+0x7C: render_type (word) */

    .global DAT_0602ccba
DAT_0602ccba:
    .2byte  0x00FC                      /* car+0xFC: accel_delta / speed_delta (longword) */
.L_0602CCBC:
    .4byte  fpdiv_setup                 /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_pool_0602CCC0:
    .4byte  0x0000CCCC                  /* ~0.8 in 16.16 FP (min Y scale threshold) */
.L_0602CCC4:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_pool_0602CCC8:
    .4byte  0x00000140                  /* 320 = screen width conversion factor */
.L_pool_0602CCCC:
    .4byte  0x00000100                  /* 256 = alternate screen width factor */

    .global sym_0602CCD0
sym_0602CCD0:
    mov.w   .L_wpool_0602CCEA, r7
    mov.w @(r0, r7), r3
    mov #0x4, r4
    cmp/gt r4, r3
    bt      .L_0602CCE6
    mov.l @(8, r0), r3
    mov #0x14, r4
    cmp/ge r3, r4
    bt      .L_0602CCE6
    mov #0xA, r4
    mov.w r4, @(r0, r7)
.L_0602CCE6:
    rts
    nop
.L_wpool_0602CCEA:
    .2byte  0x0152                      /* car+0x152: timer_b effect duration (word) */
