
    .section .text.FUN_0601424C


    .global camera_angle_interp
    .type camera_angle_interp, @function
camera_angle_interp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601430C, r3
    jsr @r3
    nop
    mov.l   .L_06014310, r3
    jsr @r3
    nop
    mov.l   .L_06014314, r6
    mov.w   DAT_06014306, r5
    mov.l   .L_06014318, r3
    jsr @r3
    mov #0x0, r4
    mov #0x0, r1
    mov.l   .L_0601431C, r12
    mov.l   .L_06014320, r3
    mov.l   .L_06014324, r14
    mov.l @r12, r12
    shll2 r12
    shll2 r12
    shll r12
    add r3, r12
    mov.w @(24, r12), r0
    mov.w @r14, r3
    mov r0, r2
    sub r3, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.w r3, @r14
    mov.l   .L_06014328, r3
    jsr @r3
    mov.w @r14, r4
    mov.l   .L_0601432C, r13
    mov.l   .L_06014330, r5
    mov.l @r12, r4
    mov.w   .L_06014308, r2
    mov.l @r13, r3
    sub r3, r4
    mov.l   .L_06014334, r3
    jsr @r3
    add r2, r4
    mov #0x0, r6
    mov.l @r13, r2
    add r0, r2
    mov.l r2, @r13
    mov r2, r5
    mov.l   .L_06014318, r3
    jsr @r3
    mov r6, r4
    mov.w @r14, r4
    mov.l   .L_06014328, r3
    jsr @r3
    neg r4, r4
    mov.l   .L_06014338, r0
    mov.l   .L_0601433C, r3
    mov.l @r0, r0
    and #0x1F, r0
    mov r0, r4
    shll8 r4
    shll2 r4
    jsr @r3
    shll r4
    mov.l   .L_06014340, r14
    mov.l   .L_06014344, r3
    mov r14, r6
    mov r14, r5
    jsr @r3
    mov r14, r4
    mov #0x4, r5
    mov.l   .L_06014348, r4
    mov.l   .L_0601434C, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l   .L_06014350, r5
    mov.l   .L_06014354, r4
    mov.l   .L_06014358, r3
    mov.w @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_0601435C, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014306
DAT_06014306:
    .2byte  0x8000
.L_06014308:
    .2byte  0x020C
    .2byte  0xFFFF
.L_0601430C:
    .4byte  sym_06026E0C
.L_06014310:
    .4byte  sym_06026DBC
.L_06014314:
    .4byte  0x000108F5
.L_06014318:
    .4byte  sym_06026E2E
.L_0601431C:
    .4byte  sym_06084B08
.L_06014320:
    .4byte  sym_0605AD5C
.L_06014324:
    .4byte  sym_06084AF8
.L_06014328:
    .4byte  mat_rot_z
.L_0601432C:
    .4byte  sym_06084AFC
.L_06014330:
    .4byte  0x00008000
.L_06014334:
    .4byte  fpmul
.L_06014338:
    .4byte  sym_0607EBC8
.L_0601433C:
    .4byte  mat_rot_y
.L_06014340:
    .4byte  0x00010000
.L_06014344:
    .4byte  mat_scale_columns
.L_06014348:
    .4byte  sym_060623AC
.L_0601434C:
    .4byte  sym_06031D8C
.L_06014350:
    .4byte  sym_06089E4A
.L_06014354:
    .4byte  sym_06062334
.L_06014358:
    .4byte  sym_06031A28
.L_0601435C:
    .4byte  sym_06089EDC
