
    .section .text.FUN_06010BC4


    .global graphics_mode_setup
    .type graphics_mode_setup, @function
graphics_mode_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov #0x1, r9
    mov.l   .L_06010C60, r10
    mov.l   .L_06010C64, r11
    mov.l   .L_06010C68, r12
    mov.w   .L_06010C4C, r13
    mov.w   DAT_06010c4e, r14
    mov.w   .L_06010C50, r6
    mov.l   .L_06010C6C, r5
    mov.l   .L_06010C70, r0
    mov.b @r0, r0
    tst r0, r0
    bf/s    .L_06010BF0
    mov #0x0, r4
    bra     .L_06010CE2
    nop
.L_06010BF0:
    mov.w @r5, r3
    add r6, r3
    mov.w r3, @r5
    mov.l   .L_06010C74, r5
    mov.l @r10, r2
    mov.l @r5, r3
    add r3, r2
    mov.l r2, @r10
    mov.l @r11, r2
    mov.l @r5, r3
    add r3, r2
    mov.l r2, @r11
    mov.l   .L_06010C78, r6
    mov.l @r5, r2
    cmp/pz r2
    bf      .L_06010C3A
    mov.b @r6, r0
    bra     .L_06010C2E
    extu.b r0, r0
.L_06010C16:
    mov.l @r10, r2
    cmp/pz r2
    bf      .L_06010C90
    mov.l r4, @r10
    bra     .L_06010C90
    mov.l r4, @r5
.L_06010C22:
    mov.l @r11, r2
    cmp/pz r2
    bf      .L_06010C90
    mov.l r4, @r11
    bra     .L_06010C90
    mov.l r4, @r5
.L_06010C2E:
    cmp/eq #0x0, r0
    bt      .L_06010C16
    cmp/eq #0x1, r0
    bt      .L_06010C22
    bra     .L_06010C90
    nop
.L_06010C3A:
    mov.b @r6, r0
    bra     .L_06010C88
    extu.b r0, r0
.L_06010C40:
    mov.l @r10, r2
    cmp/pl r2
    bt      .L_06010C90
    mov.l r4, @r10
    bra     .L_06010C90
    mov.l r4, @r5
.L_06010C4C:
    .2byte  0xFE11                       /* hw status register addr low 16 bits */

    .global DAT_06010c4e
DAT_06010c4e:
    .2byte  0x0080                       /* bit 7 poll mask for hw status */
.L_06010C50:
    .2byte  0x0100                       /* rotation angle step per frame */
    .2byte  0xFFFF                       /* padding */
    .4byte  0xAB110BFF                   /* unreferenced pool data */
    .4byte  sym_0607EAB8                 /* unreferenced pool ptr */
    .4byte  sym_0604483C                 /* hw status register full addr */
.L_06010C60:
    .4byte  sym_06078894                 /* scroll X position accumulator */
.L_06010C64:
    .4byte  sym_06078898                 /* scroll Y position accumulator */
.L_06010C68:
    .4byte  sym_0608A52C                 /* render budget counter */
.L_06010C6C:
    .4byte  sym_06078878                 /* current Y rotation angle (16-bit) */
.L_06010C70:
    .4byte  sym_06085FF4                 /* display active flag (byte) */
.L_06010C74:
    .4byte  sym_0607889C                 /* per-frame scroll delta */
.L_06010C78:
    .4byte  sym_060788A8                 /* scroll direction / split-screen flag */
.L_06010C7C:
    mov.l @r11, r2
    cmp/pl r2
    bt      .L_06010C90
    mov.l r4, @r11
    bra     .L_06010C90
    mov.l r4, @r5
.L_06010C88:
    cmp/eq #0x0, r0
    bt      .L_06010C40
    cmp/eq #0x1, r0
    bt      .L_06010C7C
.L_06010C90:
    .byte   0xB2, 0xA7    /* bsr 0x060111E2 */
    nop
    mov.l @r12, r2
    mov.l   .L_06010D50, r3
    add #0x30, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_06010D54, r3
    mov.l r9, @r3
    mov.l @r11, r2
    mov.l   .L_06010D58, r3
    mov.l r2, @r3
    mov.l   .L_06010D5C, r2
    mov.l   .L_06010D60, r3
    mov.l r2, @r3
    mov.l   .L_06010D64, r2
    mov.l   .L_06010D68, r3
    mov.l r2, @r3
    mov.l   .L_06010D6C, r2
    mov.l   .L_06010D70, r3
    mov.l r2, @r3
    mov.l   .L_06010D74, r2
    mov.l   .L_06010D78, r3
    mov.w r2, @r3
    mov.l   .L_06010D64, r7
    mov.l   .L_06010D5C, r6
    mov.l @r10, r5
    .byte   0xB0, 0x65    /* bsr 0x06010D94 */
    mov #0x0, r4
.L_06010CCA:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_06010CCA
    mov.b @r13, r0
    mov.l   .L_06010D7C, r3
    and #0xF, r0
    jsr @r3
    mov.b r0, @r13
    bra     .L_06010D38
    nop
.L_06010CE2:
    mov.l   .L_06010D80, r7
    mov.l r9, @r7
    mov.w @r5, r2
    add r6, r2
    .byte   0xB3, 0x11    /* bsr 0x06011310 */
    mov.w r2, @r5
    mov.l @r12, r2
    mov.l   .L_06010D50, r3
    add #0x30, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_06010D54, r3
    mov.l r9, @r3
    mov.l   .L_06010D84, r2
    mov.l   .L_06010D58, r3
    mov.l r2, @r3
    mov.l   .L_06010D88, r2
    mov.l   .L_06010D60, r3
    mov.l r2, @r3
    mov.l   .L_06010D8C, r2
    mov.l   .L_06010D68, r3
    mov.l r2, @r3
    mov.l   .L_06010D6C, r2
    mov.l   .L_06010D70, r3
    mov.l r2, @r3
    mov.l   .L_06010D74, r2
    mov.l   .L_06010D78, r3
    mov.w r2, @r3
    mov.l   .L_06010D8C, r7
    mov.l   .L_06010D88, r6
    mov.l   .L_06010D90, r5
    .byte   0xB0, 0x38    /* bsr 0x06010D94 */
    mov #0x0, r4
.L_06010D24:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_06010D24
    mov.b @r13, r0
    mov.l   .L_06010D7C, r3
    and #0xF, r0
    jsr @r3
    mov.b r0, @r13
.L_06010D38:
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF                       /* padding */
.L_06010D50:
    .4byte  sym_060270D0                 /* mat_vec_transform function */
.L_06010D54:
    .4byte  sym_0607884C                 /* rendering active flag */
.L_06010D58:
    .4byte  sym_06078850                 /* scroll Y parameter output */
.L_06010D5C:
    .4byte  0xFFFF3334                   /* -0.8 (16.16 fixed-point Z position) */
.L_06010D60:
    .4byte  sym_06078854                 /* config Z position output */
.L_06010D64:
    .4byte  0x00063333                   /* 6.2 (16.16 fixed-point X position) */
.L_06010D68:
    .4byte  sym_06078858                 /* config X position output */
.L_06010D6C:
    .4byte  race_position_track          /* secondary SH-2 callback function */
.L_06010D70:
    .4byte  sym_06063574                 /* secondary SH-2 callback pointer */
.L_06010D74:
    .4byte  0x0000FFFF                   /* low 16-bit mask (0xFFFF for VDP2) */
.L_06010D78:
    .4byte  0x21000000                   /* VDP2 TVMD register (cache-through) */
.L_06010D7C:
    .4byte  sym_0603C000                 /* render finalize function */
.L_06010D80:
    .4byte  sym_060788A0                 /* game state counter */
.L_06010D84:
    .4byte  0x00038000                   /* 3.5 (16.16 fixed-point Y, path B) */
.L_06010D88:
    .4byte  0xFFFF0000                   /* -1.0 (16.16 fixed-point Z, path B) */
.L_06010D8C:
    .4byte  0x0006B333                   /* 6.7 (16.16 fixed-point X, path B) */
.L_06010D90:
    .4byte  0xFFFC8000                   /* -3.5 (16.16 fixed-point Y, path B) */
