
    .section .text.FUN_060114B8


    .global hud_layer_composite
    .type hud_layer_composite, @function

hud_layer_composite:
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
    .4byte  sym_060447A8                    /* target position table (8 dwords) */
.L_06011500:
    .4byte  sym_0607EADC                    /* animation frame index (dword) */
.L_06011504:
    .4byte  sym_06078860                    /* current interpolated position (dword) */
.L_06011508:
    .4byte  sym_0607887F                    /* game state byte (0x3=race, 0xB=replay) */
.L_0601150C:
    .4byte  sym_0607EBC8                    /* mode config flags (bit 0 = suppress HUD) */

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
    .byte   0x96, 0x4F    /* mov.w @(+0x00 cross-TU pool), r6 */
    .byte   0xD2, 0x2A    /* mov.l @(+0x0A cross-TU pool), r2 */
    add r2, r11
    add #0xC, r11
    mov.l @r11, r5
    .byte   0xB0, 0xBB    /* bsr 0x060116A8 (external) */
    mov.l @r14, r4
    add #0x4, r15
    mov.w @r12, r7
    mov.l @r11, r6
    .byte   0xD4, 0x26    /* mov.l @(+0x0E cross-TU pool), r4 */
    .byte   0xB2, 0x1D    /* bsr 0x06011978 (external) */
    mov.l @r14, r5
    mov.w @r12, r7
    mov.l @r11, r6
    mov.l @r14, r5
    .byte   0xD4, 0x24    /* mov.l @(+0x12 cross-TU pool), r4 */
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA2, 0x13    /* bra 0x06011978 (external) */
    mov.l @r15+, r14

.L_06011552:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
