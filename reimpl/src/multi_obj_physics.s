
    .section .text.FUN_06014360


    .global multi_obj_physics
    .type multi_obj_physics, @function
multi_obj_physics:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_0601440e, r8
    mov.l   .L_06014414, r9
    mov.l   .L_06014418, r10
    mov.l   .L_0601441C, r11
    mov.w   .L_06014410, r14
    mov.l   .L_06014420, r3
    jsr @r3
    nop
    mov #0x0, r13
    mov.l   .L_06014424, r2
    mov.l r2, @r15
.L_06014388:
    mov r13, r12
    mov.l   .L_06014428, r3
    mov.l   .L_0601442C, r2
    shll2 r12
    shll2 r12
    shll r12
    jsr @r2
    add r3, r12
    mov.l   .L_06014430, r6
    mov r8, r5
    jsr @r10
    mov #0x0, r4
    mov.w @(24, r12), r0
    jsr @r9
    mov r0, r4
    mov #0x0, r6
    mov.l @r12, r5
    jsr @r10
    mov r6, r4
    mov.w @(24, r12), r0
    mov r0, r4
    jsr @r9
    neg r4, r4
    mov.l   .L_06014434, r3
    mov.l @r3, r3
    cmp/eq r13, r3
    bf      .L_060143C2
    .byte   0xBD, 0x28    /* bsr 0x06013E12 (external) */
    nop
.L_060143C2:
    mov r14, r6
    mov r14, r5
    mov.l   .L_06014438, r3
    jsr @r3
    mov r14, r4
    mov #0x4, r5
    mov r13, r12
    mov.l   .L_0601443C, r4
    mov.l   .L_06014440, r3
    shll2 r12
    add r12, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   .L_06014444, r4
    mov.l   .L_06014448, r3
    mov.w @r5, r5
    add r12, r4
    jsr @r3
    mov.l @r4, r4
    mov.l @r11, r2
    add #0x1, r13
    mov #0x1D, r3
    add #-0x30, r2
    mov.l r2, @r11
    cmp/hs r3, r13
    bf      .L_06014388
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601440e
DAT_0601440e:
    .2byte  0x8000
.L_06014410:
    .2byte  0x4CCC
    .2byte  0xFFFF
.L_06014414:
    .4byte  mat_rot_z
.L_06014418:
    .4byte  sym_06026E2E
.L_0601441C:
    .4byte  sym_06089EDC
.L_06014420:
    .4byte  sym_06026E0C
.L_06014424:
    .4byte  sym_06089E4A
.L_06014428:
    .4byte  sym_0605AD5C
.L_0601442C:
    .4byte  sym_06026DBC
.L_06014430:
    .4byte  0x00010000
.L_06014434:
    .4byte  sym_06084B08
.L_06014438:
    .4byte  mat_scale_columns
.L_0601443C:
    .4byte  sym_06062338
.L_06014440:
    .4byte  sym_06031D8C
.L_06014444:
    .4byte  sym_060622C0
.L_06014448:
    .4byte  sym_06031A28
