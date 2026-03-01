
    .section .text.FUN_060116BC


    .global hud_main_draw
    .type hud_main_draw, @function
hud_main_draw:
    sts.l pr, @-r15
    mov r4, r8
    add #-0xC, r15
    mov r15, r6
    mov r15, r5
    mov.w r0, @(8, r15)
    add #0x4, r6
    mov.w @(8, r15), r0
    mov.l   .L_060117DC, r3
    jsr @r3
    mov r0, r4

    mov.l   .L_060117E0, r11
    mov.l   .L_060117E4, r12
    mov.l   .L_060117E8, r13
    mov.l   .L_060117EC, r14

    mov.w @r12, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    mov #0x8, r3
    add r11, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_060117F0, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l r0, @-r15
    mov.l   .L_060117F4, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l @r15+, r4
    sub r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r8, r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    exts.w r0, r0
    mov.w r0, @r2

    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov #0xA, r2
    add r11, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_060117F0, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov.l r0, @-r15
    mov.l   .L_060117F4, r4
    jsr @r14
    mov.l @(12, r15), r5
    mov.l @r15+, r4
    add r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r9, r4
    mov.l @r15+, r3
    add r3, r0
    exts.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3

    mov.w @r12, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    mov #0xC, r3
    add r11, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_060117F8, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l r0, @-r15
    mov.l   .L_060117F4, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l @r15+, r4
    sub r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r8, r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    exts.w r0, r0
    mov.w r0, @r2

    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov #0xE, r2
    add r11, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_060117F8, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov.l r0, @-r15
    mov.l   .L_060117F4, r4
    jsr @r14
    mov.l @(12, r15), r5
    mov.l @r15+, r4
    add r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r9, r4
    bra     .L_060117FC
    nop

.L_060117DC:
    .4byte  sincos_pair                 /* sin/cos lookup function */
.L_060117E0:
    .4byte  sym_060786CC                /* HUD record array base address */
.L_060117E4:
    .4byte  sym_0605AAA0                /* HUD record count/index (16-bit) */
.L_060117E8:
    .4byte  swap_sign_ext               /* extract int16 from 16.16 fixed-point */
.L_060117EC:
    .4byte  fpmul                       /* 16.16 fixed-point multiply */
.L_060117F0:
    .4byte  0xFFC80000                  /* -56.0 in 16.16 fixed-point */
.L_060117F4:
    .4byte  0x001E0000                  /* +30.0 in 16.16 fixed-point */
.L_060117F8:
    .4byte  0x00380000                  /* +56.0 in 16.16 fixed-point */

.L_060117FC:
    mov.l @r15+, r3
    add r3, r0
    exts.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3

    mov.w @r12, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    mov #0x10, r3
    add r11, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_0601196C, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l r0, @-r15
    mov.l   .L_06011970, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l @r15+, r4
    sub r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r8, r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    exts.w r0, r0
    mov.w r0, @r2

    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov #0x12, r2
    add r11, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_0601196C, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov.l r0, @-r15
    mov.l   .L_06011970, r4
    jsr @r14
    mov.l @(12, r15), r5
    mov.l @r15+, r4
    add r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r9, r4
    mov.l @r15+, r3
    add r3, r0
    exts.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3

    mov.w @r12, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    mov #0x14, r3
    add r11, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_06011974, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l r0, @-r15
    mov.l   .L_06011970, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l @r15+, r4
    sub r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r8, r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    exts.w r0, r0
    mov.w r0, @r2

    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov #0x16, r2
    add r11, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_06011974, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov.l r0, @-r15
    mov.l   .L_06011970, r4
    jsr @r14
    mov.l @(12, r15), r5
    mov.l @r15+, r4
    add r0, r4
    jsr @r14
    mov r10, r5
    jsr @r13
    mov r0, r4
    mov.l r0, @-r15
    jsr @r13
    mov r9, r4
    mov.l @r15+, r3
    add r3, r0
    exts.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3


    mov #0x2E, r0
    mov.w @r12, r2
    mov.w @(r0, r15), r0
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r11, r2
    mov.w r0, @(6, r2)

    mov #0x0, r0
    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r11, r3
    mov.b r0, @(4, r3)

    mov.w @r12, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    mov #0x1, r0
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r11, r3
    mov.b r0, @(5, r3)

    mov.w @r12, r3
    add #0x1, r3
    mov.w r3, @r12
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

.L_0601196C:
    .4byte  0x00380000                  /* +56.0 in 16.16 fixed-point */
.L_06011970:
    .4byte  0xFFE20000                  /* -30.0 in 16.16 fixed-point */
.L_06011974:
    .4byte  0xFFC80000                  /* -56.0 in 16.16 fixed-point */
