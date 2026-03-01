
    .section .text.FUN_06010994


    .global hud_coord_calc
    .type hud_coord_calc, @function
hud_coord_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06010A2C, r12
    mov.l   .L_pool_06010A30, r13
    mov.l   .L_pool_06010A34, r14
    mov.l   .L_pool_06010A38, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060109E0
    mov #0x20, r6
    mov.l   .L_pool_06010A3C, r5
    mov.l   .L_pool_06010A40, r3
    mov.l   .L_pool_06010A44, r4
    mov.l   .L_pool_06010A48, r2
    mov.l   .L_pool_06010A4C, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r13, r1
    bra     .L_060109FA
    add r1, r4
.L_060109E0:
    mov.w   DAT_06010a2a, r6

    .global loc_060109E2
loc_060109E2:
    mov.l   .L_pool_06010A50, r5
    mov.l   .L_pool_06010A54, r3
    mov.l @r12, r4
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r13, r2
    add r2, r4
    add #0x40, r4
.L_060109FA:
    jsr @r14
    nop
    mov.w   DAT_06010a2a, r6
    mov.l   .L_pool_06010A58, r5
    mov.l   .L_pool_06010A54, r3
    mov.l @r12, r4
    mov.l @r13, r2
    mov r6, r1
    mov.b @r5, r5
    shll2 r4
    add #0x40, r1
    extu.b r5, r5
    shll r4
    shll2 r5
    add r2, r4
    add r3, r5
    mov.l @r5, r5
    jsr @r14
    add r1, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06010a2a
DAT_06010a2a:
    .2byte  0x00C0
.L_pool_06010A2C:
    .4byte  sym_06059FFC
.L_pool_06010A30:
    .4byte  sym_06063F5C
.L_pool_06010A34:
    .4byte  memcpy_word_idx
.L_pool_06010A38:
    .4byte  sym_06083255
.L_pool_06010A3C:
    .4byte  sym_0607EAB8
.L_pool_06010A40:
    .4byte  sym_0605D0AC
.L_pool_06010A44:
    .4byte  sym_0607EAD8
.L_pool_06010A48:
    .4byte  sym_060448B5
.L_pool_06010A4C:
    .4byte  sym_0607886C
.L_pool_06010A50:
    .4byte  sym_06078868
.L_pool_06010A54:
    .4byte  sym_0605D05C
.L_pool_06010A58:
    .4byte  sym_0607ED91
