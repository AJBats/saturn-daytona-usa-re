
    .section .text.FUN_06010F04


    .global race_position_track
    .type race_position_track, @function
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
    .4byte  sym_0607884C               /* channel index pointer */
.L_06010F34:
    .4byte  sym_0603C000               /* position display initialization */
.L_06010F38:
    .4byte  sym_060788A4               /* active position display count */
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
    .4byte  sym_060270F2               /* fixed-point divide */
.L_06011020:
    .4byte  sym_06078858               /* position Z array (ptr) */
.L_06011024:
    .4byte  sym_06078854               /* position Y array (ptr) */
.L_06011028:
    .4byte  sym_06078850               /* position X array (ptr) */
.L_0601102C:
    .4byte  sym_06078878               /* rotation angle (16-bit) */
.L_06011030:
    .4byte  mat_rot_xy_b               /* XY plane rotation matrix */
.L_06011034:
    .4byte  sym_0606212C               /* matrix destination array (4 slots) */
.L_06011038:
    .4byte  sym_060621D8               /* matrix source array (4 slots) */
.L_0601103C:
    .4byte  sym_06032158               /* vector matrix transform */
.L_06011040:
    .4byte  sym_06031DF4               /* scaled vector transform */
.L_06011044:
    .4byte  sym_06062180               /* rotation data array (ptr) */
.L_06011048:
    .4byte  sym_06089E44               /* per-channel scale factor table */
.L_0601104C:
    .4byte  sym_060620D8               /* output vector array (ptr) */
.L_06011050:
    .4byte  sym_06027080               /* fixed-point multiply */
.L_06011054:
    .4byte  sym_06044640               /* channel 1 position parameters (X/Y/Z) */
.L_06011058:
    .4byte  sym_06062184               /* channel 1 rotation data (ptr) */
.L_0601105C:
    .4byte  sym_060620DC               /* channel 1 output vector (ptr) */
.L_06011060:
    .4byte  sym_0608A52C               /* position counter (decremented by 0x30) */
.L_06011064:
    .4byte  sym_06044654               /* channel 2 Z parameter (ptr) */
.L_06011068:
    .4byte  sym_06044650               /* channel 2 Y parameter (ptr) */
.L_0601106C:
    .4byte  sym_0604464C               /* channel 2 X parameter (ptr) */
.L_06011070:
    .4byte  sym_06062188               /* channel 2 rotation data (ptr) */
.L_06011074:
    .4byte  sym_060620E0               /* channel 2 output vector (ptr) */
.L_06011078:
    .4byte  sym_06044678               /* channel 3 Z parameter (ptr) */
.L_0601107C:
    .4byte  sym_06044674               /* channel 3 Y parameter (ptr) */
.L_06011080:
    .4byte  sym_06044670               /* channel 3 X parameter (ptr) */
.L_06011084:
    .4byte  sym_0606218C               /* channel 3 rotation data (ptr) */
.L_06011088:
    .4byte  sym_060620E4               /* channel 3 output vector (ptr) */
.L_0601108C:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_06011090:
    .4byte  0x21800000                  /* VDP2 scroll position register (cache-through) */
