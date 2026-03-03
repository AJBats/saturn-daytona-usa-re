	.text
    .global graphics_mode_setup
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
    bf.s    .L_06010BF0
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
    .short  0xFE11

    .global DAT_06010c4e
DAT_06010c4e:
    .short  0x0080
.L_06010C50:
    .short  0x0100  /* RE_TEST 4H: normal spin speed, X-axis tumble via rotation swap */
    .short  0xFFFF
    .long  0xAB110BFF
    .long  sym_0607EAB8
    .long  sym_0604483C
.L_06010C60:
    .long  sym_06078894
.L_06010C64:
    .long  sym_06078898
.L_06010C68:
    .long  sym_0608A52C
.L_06010C6C:
    .long  sym_06078878
.L_06010C70:
    .long  sym_06085FF4
.L_06010C74:
    .long  sym_0607889C
.L_06010C78:
    .long  sym_060788A8
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
    .short  0xFFFF
.L_06010D50:
    .long  sym_060270D0
.L_06010D54:
    .long  sym_0607884C
.L_06010D58:
    .long  sym_06078850
.L_06010D5C:
    .long  0xFFFF3334
.L_06010D60:
    .long  sym_06078854
.L_06010D64:
    .long  0x00063333
.L_06010D68:
    .long  sym_06078858
.L_06010D6C:
    .long  race_position_track
.L_06010D70:
    .long  sym_06063574
.L_06010D74:
    .long  0x0000FFFF
.L_06010D78:
    .long  0x21000000
.L_06010D7C:
    .long  sym_0603C000
.L_06010D80:
    .long  sym_060788A0
.L_06010D84:
    .long  0x00038000  /* RE_TEST 4H: camera X (vanilla value) */
.L_06010D88:
    .long  0xFFFF0000  /* RE_TEST 4H: camera Y (vanilla value) */
.L_06010D8C:
    .long  0x0006B333  /* RE_TEST 4H: camera Z (vanilla value) */
.L_06010D90:
    .long  0xFFFC8000  /* RE_TEST 4H: camera X alt (vanilla value) */
