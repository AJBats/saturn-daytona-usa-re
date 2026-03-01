
    .section .text.FUN_06011310


    .global position_ranking_display
    .type position_ranking_display, @function
position_ranking_display:
    mov.l r14, @-r15
    mov #0x3, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060113B8, r5
    mov.l   .L_060113BC, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0xB, r0
    bf/s    .L_0601133E
    mov r4, r12
    mov.l @r5, r0
    tst #0x1, r0
    bt      .L_0601133A
    bra     .L_0601134E
    mov r12, r11
.L_0601133A:
    bra     .L_0601134E
    mov #0x4, r11
.L_0601133E:
    mov #0x2, r3
    mov.l @r5, r11
    and r4, r11
    cmp/ge r3, r11
    bt      .L_0601134C
    bra     .L_0601134E
    mov r12, r11
.L_0601134C:
    mov #0x4, r11
.L_0601134E:
    mov.l   .L_060113C0, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0601135A
    bra     .L_0601135C
    mov.l r12, @r15
.L_0601135A:
    mov.l r11, @r15
.L_0601135C:
    mov.l   .L_060113C4, r13
    mov.l   .L_060113C8, r14
    mov.l @r15, r9
    mov.w   .L_060113B2, r6
    mov.l   .L_060113CC, r5
    mov.l @(4, r14), r7
    shll8 r9
    shll2 r9
    shll2 r9
    add r9, r7
    jsr @r13
    mov #0x4, r4
    mov.l   .L_060113D0, r10
    mov.l @(4, r14), r7
    mov.w   DAT_060113b4, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_06011388
    add r9, r7
    mov.l   .L_060113D4, r5
    bra     .L_0601138A
    nop
.L_06011388:
    mov.l   .L_060113D8, r5
.L_0601138A:
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   .L_060113B6, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_060113A0
    add r9, r7
    mov.l   .L_060113DC, r5
    bra     .L_060113A2
    nop
.L_060113A0:
    mov.l   .L_060113E0, r5
.L_060113A2:
    jsr @r13
    mov #0x4, r4
    mov.l   .L_060113C0, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bt      .L_060113E4
    bra     .L_060113E6
    mov.l r12, @r15
.L_060113B2:
    .2byte  0x0288                          /* VDP1 cmd offset: position elem 1 */

    .global DAT_060113b4
DAT_060113b4:
    .2byte  0x051C                          /* VDP1 cmd offset: position elem 2 */
.L_060113B6:
    .2byte  0x0518                          /* VDP1 cmd offset: position elem 3 */
.L_060113B8:
    .4byte  sym_0607EBC8                    /* mode configuration flags (32-bit) */
.L_060113BC:
    .4byte  sym_0607887F                    /* game mode byte (0xB = variant) */
.L_060113C0:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_060113C4:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_060113C8:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_060113CC:
    .4byte  sym_0605A7FC                    /* position sprite data (group 1) */
.L_060113D0:
    .4byte  sym_06078644                    /* transmission type flag (nonzero = AT) */
.L_060113D4:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 2) */
.L_060113D8:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 2) */
.L_060113DC:
    .4byte  sym_0605A998                    /* active state sprite (AT, elem 3) */
.L_060113E0:
    .4byte  sym_0605A978                    /* inactive state sprite (MT, elem 3) */
.L_060113E4:
    mov.l r11, @r15
.L_060113E6:
    mov.l @r15, r12
    mov.l @(4, r14), r7
    mov.w   DAT_06011462, r6
    mov.l   .L_06011468, r5
    add #0x2, r12
    shll8 r12
    shll2 r12
    shll2 r12
    add r12, r7
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   .L_06011464, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_0601140E
    add r12, r7
    mov.l   .L_0601146C, r5
    bra     .L_06011410
    nop
.L_0601140E:
    mov.l   .L_06011470, r5
.L_06011410:
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   DAT_06011466, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_06011426
    add r12, r7
    mov.l   .L_06011474, r5
    bra     .L_06011428
    nop
.L_06011426:
    mov.l   .L_06011478, r5
.L_06011428:
    jsr @r13
    mov #0x4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0601143E
sym_0601143E:
    mov.l   .L_0601147C, r7
    mov.l @(4, r7), r7
    mov.l   .L_06011480, r3
    add r3, r7
    mov #0xE, r6
    mov.l   .L_06011484, r5
    mov.l   .L_06011488, r3
    jmp @r3
    mov #0x4, r4

    .global sym_06011450
sym_06011450:
    mov.l   .L_0601147C, r7
    mov.l @(4, r7), r7
    mov.l   .L_0601148C, r3
    add r3, r7
    mov #0x10, r6
    mov.l   .L_06011490, r5
    mov.l   .L_06011488, r3
    jmp @r3
    mov #0x4, r4

    .global DAT_06011462
DAT_06011462:
    .2byte  0x02B6                          /* VDP1 cmd offset: position elem 4 */
.L_06011464:
    .2byte  0x054A                          /* VDP1 cmd offset: position elem 5 */

    .global DAT_06011466
DAT_06011466:
    .2byte  0x0546                          /* VDP1 cmd offset: position elem 6 */
.L_06011468:
    .4byte  sym_0605A8B6                    /* position sprite data (group 2) */
.L_0601146C:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 5) */
.L_06011470:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 5) */
.L_06011474:
    .4byte  sym_0605A9A0                    /* active state sprite (AT, elem 6) */
.L_06011478:
    .4byte  sym_0605A980                    /* inactive state sprite (MT, elem 6) */
.L_0601147C:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_06011480:
    .4byte  0x0000D000                      /* VDP1 display offset for 14px elem */
.L_06011484:
    .4byte  sym_0605A634                    /* sprite data for 14-pixel position icon */
.L_06011488:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_0601148C:
    .4byte  0x0000E000                      /* VDP1 display offset for 16px elem */
.L_06011490:
    .4byte  sym_0605A718                    /* sprite data for 16-pixel position icon */

    .global sym_06011494
sym_06011494:
    extu.w r4, r0
    mov #0x0, r2
    .byte   0xD1, 0x19    /* mov.l [transition_state_ptr], r1 */
    .byte   0xD3, 0x18    /* mov.l [ranking_config_table], r3 */
    shll2 r0
    mov.l r2, @r1
    shll2 r0
    .byte   0xD1, 0x18    /* mov.l [active_display_slot], r1 */
    add r3, r0
    mov.l @r0, r2
    rts
    mov.l r2, @r1
