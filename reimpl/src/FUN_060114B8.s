
    .section .text.FUN_060114B8


    .global FUN_060114B8
    .type FUN_060114B8, @function

FUN_060114B8:
    sts.l pr, @-r15
    shll2 r0
    mov.l   .L_06011504, r14
    mov.l   .L_060114FC, r3
    mov.l   .L_06011500, r2
    shll2 r0
    mov.l @r2, r2
    add r3, r0
    shll2 r2
    mov.l @(r0, r2), r1
    mov.l @r14, r2
    mov #0x0, r0
    sub r2, r1
    cmp/gt r1, r0
    addc r0, r1
    shar r1
    add r1, r2
    mov.l r2, @r14
    mov.l   .L_06011508, r4
    mov.b @r4, r4
    extu.b r4, r4
    mov r4, r0
    cmp/eq #0x3, r0
    bt      .L_060114EE
    mov r4, r0
    cmp/eq #0xB, r0
    bf      .L_06011510
.L_060114EE:
    mov.l   .L_0601150C, r0
    mov.l @r0, r0
    tst #0x1, r0
    bt      .L_06011510
    bra     .L_06011552
    nop
    .2byte  0xFFFF
.L_060114FC:
    .4byte  sym_060447A8
.L_06011500:
    .4byte  sym_0607EADC
.L_06011504:
    .4byte  sym_06078860
.L_06011508:
    .4byte  sym_0607887F
.L_0601150C:
    .4byte  sym_0607EBC8

.L_06011510:
    extu.w r13, r12
    extu.w r13, r11
    .byte   0xD3, 0x2C    /* mov.l @(+0x02 cross-TU pool), r3 */
    shll r12
    shll2 r11
    add r3, r12
    shll2 r11
    mov.w @r12, r2
    mov.l r2, @-r15
    .byte   0xD7, 0x2A    /* mov.l @(+0x06 cross-TU pool), r7 */
    mov.w   DAT_060115c6, r6
    .byte   0xD2, 0x2A    /* mov.l @(+0x0A cross-TU pool), r2 */
    add r2, r11
    add #0xC, r11
    mov.l @r11, r5
    .reloc ., R_SH_IND12W, FUN_060116A8 - 4
    .2byte 0xB000    /* bsr FUN_060116A8 (linker-resolved) */
    mov.l @r14, r4
    add #0x4, r15
    mov.w @r12, r7
    mov.l @r11, r6
    .byte   0xD4, 0x26    /* mov.l @(+0x0E cross-TU pool), r4 */
    .reloc ., R_SH_IND12W, FUN_06011978 - 4
    .2byte 0xB000    /* bsr FUN_06011978 (linker-resolved) */
    mov.l @r14, r5
    mov.w @r12, r7
    mov.l @r11, r6
    mov.l @r14, r5
    .byte   0xD4, 0x24    /* mov.l @(+0x12 cross-TU pool), r4 */
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_06011978 - 4
    .2byte 0xA000    /* bra FUN_06011978 (linker-resolved) */
    mov.l @r15+, r14

.L_06011552:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601155E
    .type FUN_0601155E, @function

FUN_0601155E:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov #0x1C, r14
    mov.l r12, @-r15
    mov #0x2C, r13
    sts.l macl, @-r15
    add #-0x4, r15
    mov.w r4, @r15
    mov #0x0, r4
    mov.w @r15, r1
    mov.l   .L_060115DC, r12
    mov.l   .L_060115E0, r7
    extu.w r1, r1
    mov.l @r12, r12
    add #0x4, r12
    shll r1

.L_0601157E:
    extu.w r4, r5
    extu.w r4, r6
    shll r5
    mul.l r13, r6
    add #0x1, r4
    shll r5
    sts macl, r6
    add r7, r5
    shll r6
    add r1, r6
    add r12, r6
    mov.w @r6, r3
    mov.w r3, @r5
    mov.w @(2, r6), r0
    extu.w r4, r3
    cmp/ge r14, r3
    bf/s    .L_0601157E
    mov.w r0, @(2, r5)

    mov.l   .L_060115DC, r7
    mov.l   .L_060115E4, r3
    mov.w @r15, r0
    mov.l @(4, r7), r7
    extu.w r0, r0
    add r3, r7
    and #0x3F, r0
    mov r0, r6
    shll r6
    mov.l   .L_060115E8, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, macl
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060115EC, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_060115c6
DAT_060115c6:
    mov.b r0, @(0, r0)
    .4byte  sym_060447A4
    .4byte  0x00010000
    .4byte  sym_060447A8
    .4byte  sym_06044764
    .4byte  sym_06044784
.L_060115DC:
    .4byte  sym_06063788
.L_060115E0:
    .4byte  sym_0605AAA6
.L_060115E4:
    .4byte  0x0000F000
.L_060115E8:
    .4byte  sym_0605AAA2
.L_060115EC:
    .4byte  sym_06028400
