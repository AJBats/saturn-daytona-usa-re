
    .section .text.FUN_0600F990


    .global FUN_0600F990
    .type FUN_0600F990, @function
FUN_0600F990:
    sts.l pr, @-r15
    .byte   0xDE, 0x1D    /* mov.l .L_pool_0600FA08, r14 */
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0600FA0C, r3 */
    mov.l @r14, r2
    add r3, r2
    mov r2, r5
    mov.l r2, @r14
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600FA10, r3 */
    jsr @r3
    mov #0x10, r4
    .byte   0xD4, 0x1B    /* mov.l .L_pool_0600FA14, r4 */
    .byte   0xD3, 0x1B    /* mov.l .L_pool_0600FA14, r3 */
    mov.w @r4, r4
    add #0x2, r4
    mov.w r4, @r3
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600FA18, r3 */
    jsr @r3
    nop
    mov.l @r14, r0
    tst r0, r0
    bf      .L_0600F9C0
    mov #0x8, r3
    .byte   0xD2, 0x17    /* mov.l .L_pool_0600FA1C, r2 */
    mov.b r3, @r2
.L_0600F9C0:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0600F9C6
    .type FUN_0600F9C6, @function
FUN_0600F9C6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600FA20, r5
    mov.l   .L_0600FA24, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_0600FA28, r3
    jsr @r3
    mov #0xC, r4
    mov.w   .L_0600FA04, r6
    mov.l   .L_0600FA2C, r5
    mov.l   .L_0600FA30, r4
    mov.l   .L_0600FA34, r3
    jsr @r3
    nop
    mov.l   .L_0600FA38, r3
    jsr @r3
    nop
    mov.l   .L_0600FA3C, r2
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_0600FA40
    mov #0x25, r14
    bra     .L_0600FA44
    mov #0x23, r13
.L_0600FA04:
    .2byte  0x0080
    .2byte  0xFFFF
    .4byte  sym_0607885C
    .4byte  0x00100000
    .4byte  FUN_06014884
    .4byte  sym_0607886E
    .4byte  FUN_0601155E
    .4byte  sym_0607887F
.L_0600FA20:
    .4byte  0xAE0003FF
.L_0600FA24:
    .4byte  FUN_0601D5F4              /* sound command dispatcher */
.L_0600FA28:
    .4byte  sym_0602853E
.L_0600FA2C:
    .4byte  sym_0605CA9C
.L_0600FA30:
    .4byte  0x25F00460
.L_0600FA34:
    .4byte  FUN_0602761E
.L_0600FA38:
    .4byte  sym_0601209E
.L_0600FA3C:
    .4byte  g_pad_state
.L_0600FA40:
    mov #0x28, r14
    mov #0x27, r13
.L_0600FA44:
    mov.l   .L_0600FB1C, r11
    mov r14, r7
    mov.l   .L_0600FB20, r12
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_0600FB24, r3
    mov.w   .L_0600FB0C, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov r13, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_0600FB24, r3
    mov.w   .L_0600FB0E, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.w   .L_0600FB10, r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0600FB12, r3
    mov.w   .L_0600FB14, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.l   .L_0600FB28, r5
    mov.l   .L_0600FB2C, r3
    jsr @r3
    mov #0x0, r4
    mov #0x9, r2
    mov.l   .L_0600FB30, r3
    mov #0x0, r4
    mov.b r2, @r3
    mov r4, r2
    mov.l   .L_0600FB34, r3
    mov.l r4, @r3
    mov.l   .L_0600FB38, r3
    mov.l r4, @r3
    mov.l   .L_0600FB3C, r3
    mov.l r2, @r3
    mov.l   .L_0600FB40, r3
    mov.l r2, @r3
    mov #0x1, r2
    mov.l   .L_0600FB44, r3
    mov.l r2, @r3
    mov.l   .L_0600FB48, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600FAE2
    mov.l   .L_0600FB4C, r3
    mov.l r4, @r3
    mov.l   .L_0600FB50, r2
    mov.l   .L_0600FB54, r3
    mov.l r2, @r3
    mov.l   .L_0600FB58, r3
    mov.l r4, @r3
    extu.b r4, r4
    mov.l   .L_0600FB5C, r3
    mov.b r4, @r3
    mov.l   .L_0600FB60, r7
    mov.w   .L_0600FB16, r6
    mov.w   .L_0600FB18, r5
    mov.l   .L_0600FB64, r3
    jsr @r3
    mov #0xC, r4
.L_0600FAE2:
    mov.l   .L_0600FB48, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FAF6
    mov.l   .L_0600FB68, r3
    jsr @r3
    mov #0x1, r4
    mov.l   .L_0600FB6C, r3
    jsr @r3
    mov #0x1, r4
.L_0600FAF6:
    mov.l   .L_0600FB70, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0600FB74, r3
    jmp @r3
    mov.l @r15+, r14
.L_0600FB0C:
    .2byte  0x0B04
.L_0600FB0E:
    .2byte  0x0B38
.L_0600FB10:
    .2byte  0x0170
.L_0600FB12:
    .2byte  0x4000
.L_0600FB14:
    .2byte  0x0C26
.L_0600FB16:
    .2byte  0x0090
.L_0600FB18:
    .2byte  0x07A2
    .2byte  0xFFFF
.L_0600FB1C:
    .4byte  sym_06063750
.L_0600FB20:
    .4byte  sym_06028400
.L_0600FB24:
    .4byte  0x00009000
.L_0600FB28:
    .4byte  0xAB1104FF
.L_0600FB2C:
    .4byte  FUN_0601D5F4              /* sound command dispatcher */
.L_0600FB30:
    .4byte  sym_0607887F
.L_0600FB34:
    .4byte  sym_0607EADC
.L_0600FB38:
    .4byte  sym_0607EAB8
.L_0600FB3C:
    .4byte  sym_06078868
.L_0600FB40:
    .4byte  sym_060788A0
.L_0600FB44:
    .4byte  sym_060788A4
.L_0600FB48:
    .4byte  sym_06085FF4
.L_0600FB4C:
    .4byte  sym_06078894
.L_0600FB50:
    .4byte  0x000C0000
.L_0600FB54:
    .4byte  sym_06078898
.L_0600FB58:
    .4byte  sym_0607889C
.L_0600FB5C:
    .4byte  sym_060788A8
.L_0600FB60:
    .4byte  sym_0605ACE4
.L_0600FB64:
    .4byte  sym_060284AE
.L_0600FB68:
    .4byte  sym_06011494
.L_0600FB6C:
    .4byte  FUN_060114AC
.L_0600FB70:
    .4byte  FUN_06010BC4
.L_0600FB74:
    .4byte  sym_06011EB4
