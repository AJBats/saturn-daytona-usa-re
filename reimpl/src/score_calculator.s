
    .section .text.FUN_06013948


    .global score_calculator
    .type score_calculator, @function
score_calculator:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_06013A30, r8
    mov.l   .L_06013A34, r11
    mov.l   .L_06013A38, r12
    mov.w   .L_06013A28, r14
    mov.w @r11, r3
    add #-0x1, r3
    mov.w r3, @r11
    extu.w r3, r3
    tst r3, r3
    bf      .L_06013976
    mov #0x2, r3
    mov.l   .L_06013A3C, r2
    mov.b r3, @r2
.L_06013976:
    mov.l   .L_06013A40, r3
    jsr @r3
    nop
    mov #0x0, r4
    mov r4, r9
    mov.l   .L_06013A44, r5
    mov r5, r13
    add r4, r13
    mov.w   .L_06013A2A, r2
    add r2, r5
    mov.l r5, @(4, r15)
    mov.l   .L_06013A48, r3
    mov.l r3, @r15
.L_06013990:
    mov.l   .L_06013A4C, r3
    jsr @r3
    mov r13, r10
    mov r12, r6
    mov.w   .L_06013A2C, r5
    jsr @r8
    mov #0x0, r4
    mov.w @(24, r10), r0
    mov.l   .L_06013A50, r3
    jsr @r3
    mov r0, r4
    mov.w   .L_06013A2E, r5
    mov.w @r11, r4
    mov.l   .L_06013A54, r3
    extu.w r4, r4
    mul.l r12, r4
    jsr @r3
    sts macl, r4
    mov.l @r10, r5
    mov #0x0, r4
    add r0, r5
    jsr @r8
    mov r4, r6
    mov.w @(24, r10), r0
    mov.l   .L_06013A50, r3
    mov r0, r4
    jsr @r3
    neg r4, r4
    mov.w @r11, r4
    mov.l   .L_06013A58, r3
    extu.w r4, r4
    shll8 r4
    shll2 r4
    jsr @r3
    shll r4
    mov r14, r6
    mov r14, r5
    mov.l   .L_06013A5C, r3
    jsr @r3
    mov r14, r4
    mov #0x4, r5
    mov r9, r10
    mov.l   .L_06013A60, r4
    mov.l   .L_06013A64, r3
    add r9, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   .L_06013A68, r4
    mov.l   .L_06013A6C, r3
    mov.w @r5, r5
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    add #0x20, r13
    mov.l   .L_06013A70, r2
    mov.l   .L_06013A70, r3
    mov.l @r2, r2
    add #-0x30, r2
    mov.l r2, @r3
    mov.l @(4, r15), r1
    cmp/hs r1, r13
    bf/s    .L_06013990
    add #0x4, r9
    add #0x8, r15
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
.L_06013A28:
    .2byte  0x4CCC                      /* ~0.3 uniform scale factor (16.16) */
.L_06013A2A:
    .2byte  0x03A0                      /* total animation entry array size */
.L_06013A2C:
    .2byte  0x8000                      /* 180° base Z rotation angle */
.L_06013A2E:
    .2byte  0x07AE                      /* Y angle scale factor */
.L_06013A30:
    .4byte  sym_06026E2E               /* transform dispatch function */
.L_06013A34:
    .4byte  sym_06084AF4               /* animation timer (16-bit, decrements each frame) */
.L_06013A38:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_06013A3C:
    .4byte  sym_06084AF2               /* animation state: 2 = complete (byte) */
.L_06013A40:
    .4byte  sym_06026E0C               /* pre-animation setup */
.L_06013A44:
    .4byte  sym_0605AD5C               /* animation entry array (0x20 bytes each) */
.L_06013A48:
    .4byte  sym_06089E4A               /* display table base pointer */
.L_06013A4C:
    .4byte  sym_06026DBC               /* per-object pre-transform setup */
.L_06013A50:
    .4byte  mat_rot_z                  /* Z-axis rotation */
.L_06013A54:
    .4byte  fpmul                      /* fixed-point multiply */
.L_06013A58:
    .4byte  mat_rot_y                  /* Y-axis rotation */
.L_06013A5C:
    .4byte  mat_scale_columns          /* uniform column scale */
.L_06013A60:
    .4byte  sym_06062338               /* object transform table A */
.L_06013A64:
    .4byte  sym_06031D8C               /* transform chain dispatch A */
.L_06013A68:
    .4byte  sym_060622C0               /* display transform table B */
.L_06013A6C:
    .4byte  sym_06031A28               /* transform chain dispatch B */
.L_06013A70:
    .4byte  sym_06089EDC               /* global animation counter (dec by 0x30/iter) */
