	.text
    .global race_position_track
race_position_track:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_06010F30, r3
    mov.l @r3, r3
    mov.l r3, @r15
    mov.l   .L_06010F34, r3
    jsr @r3
    nop
    mov #0xA, r3
    mov.l   .L_06010F38, r2
    mov.l @r2, r2
    cmp/hs r3, r2
    bf      .L_06010F3C
    bra     .L_06011002
    nop
.L_06010F30:
    .long  sym_0607884C
.L_06010F34:
    .long  sym_0603C000
.L_06010F38:
    .long  sym_060788A4
.L_06010F3C:
    mov.l   .L_0601101C, r12
    mov.l   .L_06011020, r6
    mov.l   .L_06011024, r5
    mov.l   .L_06011028, r4
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l   .L_0601102C, r4
    mov.l   .L_06011030, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_06011034, r9
    mov.l   .L_06011038, r10
    mov.l   .L_0601103C, r11
    mov.l @r10, r5
    jsr @r11
    mov.l @r9, r4
    mov.l   .L_06011040, r8
    mov.l   .L_06011044, r6
    mov.l @r15, r13
    mov.l   .L_06011048, r3
    mov.l   .L_0601104C, r4
    mov.l @r6, r6
    shll r13
    add r3, r13
    mov.w @r13, r5
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_06011050, r3
    jsr @r3
    nop
    mov.l   .L_06011054, r14
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    jsr @r12
    mov.l @r14, r4
    mov.l @(4, r10), r5
    jsr @r11
    mov.l @(4, r9), r4
    mov.l   .L_06011058, r6
    mov.w @r13, r5
    mov.l   .L_0601105C, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_06011060, r14
    mov.l   .L_06011050, r3
    mov.l @r14, r2
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_06011064, r6
    mov.l   .L_06011068, r5
    mov.l   .L_0601106C, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r12
    mov.l @r4, r4
    mov.l @(8, r10), r5
    jsr @r11
    mov.l @(8, r9), r4
    mov.l   .L_06011070, r6
    mov.w @r13, r5
    mov.l   .L_06011074, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l @r14, r2
    mov.l   .L_06011050, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_06011078, r6
    mov.l   .L_0601107C, r5
    mov.l   .L_06011080, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r12
    mov.l @r4, r4
    mov.l @(12, r10), r5
    jsr @r11
    mov.l @(12, r9), r4
    mov.l   .L_06011084, r6
    mov.w @r13, r5
    mov.l   .L_06011088, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
.L_06011002:
    mov.l   .L_0601108C, r3
    mov.l   .L_06011090, r2
    mov.w r3, @r2
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
.L_0601101C:
    .long  sym_060270F2
.L_06011020:
    .long  sym_06078858
.L_06011024:
    .long  sym_06078854
.L_06011028:
    .long  sym_06078850
.L_0601102C:
    .long  sym_06078878
.L_06011030:
    .long  mat_rot_xz_b    /* RE_TEST 4H: X-axis tumble (was mat_rot_xy_b = Y turntable) */
.L_06011034:
    .long  sym_0606212C
.L_06011038:
    .long  sym_060621D8
.L_0601103C:
    .long  sym_06032158
.L_06011040:
    .long  sym_06031DF4
.L_06011044:
    .long  sym_06062180
.L_06011048:
    .long  sym_06089E44
.L_0601104C:
    .long  sym_060620D8
.L_06011050:
    .long  sym_06027080
.L_06011054:
    .long  sym_06044640
.L_06011058:
    .long  sym_06062184
.L_0601105C:
    .long  sym_060620DC
.L_06011060:
    .long  sym_0608A52C
.L_06011064:
    .long  sym_06044654
.L_06011068:
    .long  sym_06044650
.L_0601106C:
    .long  sym_0604464C
.L_06011070:
    .long  sym_06062188
.L_06011074:
    .long  sym_060620E0
.L_06011078:
    .long  sym_06044678
.L_0601107C:
    .long  sym_06044674
.L_06011080:
    .long  sym_06044670
.L_06011084:
    .long  sym_0606218C
.L_06011088:
    .long  sym_060620E4
.L_0601108C:
    .long  0x0000FFFF
.L_06011090:
    .long  0x21800000
