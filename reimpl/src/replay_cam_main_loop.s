
    .section .text.FUN_0601AC88


    .global replay_cam_main_loop
    .type replay_cam_main_loop, @function
replay_cam_main_loop:
    sts.l pr, @-r15
    mov.l   .L_0601ACF4, r13
    mov.l   .L_0601ACE8, r5
    mov.l   .L_0601ACEC, r2
    mov.l @r5, r4
    mov.l @r5, r11
    mov.l @r2, r2
    mov r4, r3
    shll r2
    shll r4
    shll2 r3
    add r3, r4
    add r2, r4
    mov.l   .L_0601ACF0, r3
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    shll r11
    shll2 r11
    mov.l   .L_0601ACFC, r2
    add r2, r11
    mov.l @r11, r11
    mov.l @r13, r3
    mov.w   .L_0601ACE4, r0
    mov.l @(r0, r4), r2
    cmp/hs r2, r3
    bt/s    .L_0601AD66
    mov #0x13, r14
    mov.l   .L_0601AD00, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0601AD66
.L_0601ACC8:
    extu.b r14, r3
    mov.l @r13, r1
    add #-0x1, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    add r4, r3
    mov.l @(4, r3), r3
    cmp/hs r3, r1
    bf      .L_0601AD04
    bra     .L_0601AD30
    nop
.L_0601ACE4:
    .2byte  0x00E8                          /* 0xE8 = 232 = 0x13 * 0xC + 4 (last entry frame offset) */
    .2byte  0xFFFF                          /* alignment padding */
.L_0601ACE8:
    .4byte  sym_0607EAD8                    /* race end state (0/1/2 = attract cycle) */
.L_0601ACEC:
    .4byte  sym_0605AD00                    /* render state variable */
.L_0601ACF0:
    .4byte  sym_0605DD6C                    /* camera target array base */
.L_0601ACF4:
    .4byte  sym_060786A4                    /* replay frame counter (32-bit) */
    .4byte  sym_06085FF8                    /* fastest lap flag (byte) -- unused pool slot */
.L_0601ACFC:
    .4byte  sym_0605DE24                    /* camera target position array */
.L_0601AD00:
    .4byte  sym_0607EBF4                    /* race event bitfield (bit 0 = complete) */
.L_0601AD04:
    extu.b r14, r1
    extu.b r14, r2
    mov r1, r3
    add #-0x1, r2
    shll2 r1
    shll2 r3
    shll r3
    add r3, r1
    add r4, r1
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    add r4, r2
    mov.l   .L_0601AD94, r3
    jsr @r3
    mov #0xC, r0
    add #-0x1, r14
    extu.b r14, r2
    cmp/pl r2
    bt      .L_0601ACC8
.L_0601AD30:
    extu.b r14, r12
    mov.l @r13, r2
    mov r12, r3
    shll2 r12
    shll2 r3
    shll r3
    add r3, r12
    add r4, r12
    bsr     .L_0601AE2C
    mov.l r2, @(4, r12)
    mov.b r0, @(8, r12)
    mov.l   .L_0601AD98, r2
    mov.b @r2, r2
    mov r2, r0
    mov.b r0, @(9, r12)
    mov.l   .L_0601AD9C, r3
    mov.l @r3, r3
    extu.b r3, r0
    mov.b r0, @(10, r12)
    extu.b r10, r3
    mov.b r3, @r12
    mov.l   .L_0601ADA0, r3
    mov.l r12, @r3
    mov.l   .L_0601ADA4, r3
    mov.b r14, @r3
    bra     .L_0601AD6A
    nop
.L_0601AD66:
    mov.l   .L_0601ADA0, r3
    mov.l r10, @r3
.L_0601AD6A:
    mov.l   .L_0601ADA8, r5
    mov.l   .L_0601ADAC, r4
    mov.l @(4, r11), r3
    mov.l @r4, r2
    cmp/ge r3, r2
    bt      .L_0601AD84
    mov.l @r4, r3
    cmp/pl r3
    bf      .L_0601AD84
    mov.l @r4, r3
    mov.l r3, @(4, r11)
    bra     .L_0601AD86
    mov.l r11, @r5
.L_0601AD84:
    mov.l r10, @r5
.L_0601AD86:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601AD94:
    .4byte  sym_06035168                    /* memcpy_long (unrolled longword copy) */
.L_0601AD98:
    .4byte  sym_0605DE3C                    /* crossing direction flag (byte) */
.L_0601AD9C:
    .4byte  sym_0607EAE0                    /* attract timer (32-bit) */
.L_0601ADA0:
    .4byte  sym_06085FFC                    /* active camera cut-point entry pointer */
.L_0601ADA4:
    .4byte  sym_06086012                    /* camera cut-point index (byte) */
.L_0601ADA8:
    .4byte  sym_06086000                    /* camera override pointer */
.L_0601ADAC:
    .4byte  sym_06078638                    /* race time storage (32-bit) */
    .4byte  0xD523D624
    .4byte  0xD2246452
    .4byte  0x63624400
    .4byte  0x6033343C
    .4byte  0x4408342C
    .4byte  0x20088D2F
    .4byte  0x6442D620
    .4byte  0x52416362
    .4byte  0x33238906
    .4byte  0x62624215
    .4byte  0x8B03D21D
    .4byte  0x902F032E
    .4byte  0x1431D71C
    .4byte  0xD61CD41D
    .4byte  0x60526262
    .4byte  0x600E4208
    .4byte  0x63034008
    .4byte  0x43084300
    .4byte  0x303C600E
    .4byte  0x304C032E
    .4byte  0x62723232
    .4byte  0x8910D016
    .4byte  0x60022008
    .4byte  0x890C6052
    .4byte  0x600E6303
    .4byte  0x40084308
    .4byte  0x4300303C
    .4byte  0x600E304C
    .4byte  0x62624208
    .4byte  0x63720236
    .4byte  0x000B0009
.L_0601AE2C:
    mov.l   .L_0601AE64, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0601AE6C
    mov.l   .L_0601AE68, r4
    mov.l @r4, r4
    extu.b r4, r4
    bra     .L_0601AE70
    add #0xA, r4

    .global DAT_0601ae3e
DAT_0601ae3e:
    .2byte  0x0240                          /* constant: car struct offset 0x240 */
    .4byte  sym_0607EAD8                    /* race end state (0/1/2) */
    .4byte  sym_0607EAE0                    /* attract timer (32-bit) */
    .4byte  sym_0605DE24                    /* camera target position array */
    .4byte  sym_06078638                    /* race time storage */
    .4byte  sym_06078900                    /* car array base */
    .4byte  sym_060786A4                    /* replay frame counter */
    .4byte  sym_0605AD00                    /* render state variable */
    .4byte  sym_0605DE40                    /* coordinate extent table */
    .4byte  sym_0607EBF4                    /* race event bitfield */
.L_0601AE64:
    .4byte  sym_06083255                    /* secondary SH-2 processing flag (byte) */
.L_0601AE68:
    .4byte  sym_0607EAB8                    /* frame output (odd/even selector) */
.L_0601AE6C:
    .byte   0xD4, 0x17    /* mov.l .L_pool_0601AECC, r4 */
    mov.l @r4, r4
.L_0601AE70:
    .byte   0xD0, 0x17    /* mov.l .L_pool_0601AED0, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0601AE7C
    extu.b r4, r4
    add #0xC, r4
.L_0601AE7C:
    rts
    mov r4, r0
