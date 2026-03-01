
    .section .text.FUN_06034F08


    .global slave_main_loop
    .type slave_main_loop, @function
slave_main_loop:
    sts.l pr, @-r15
    add #-0x8, r15
    mov #0x1, r3
    mov.l r3, @(4, r15)
    mov #0x0, r3
    mov.l r3, @r15
    stc sr, r0
    mov.w   .L_06034F62, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    mov #0x0, r2
    mov.w   .L_06034F64, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.w   .L_06034F66, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.w   .L_06034F68, r3
    mov.b r2, @r3
    bra     .L_06034F5E
    nop
.L_06034F34:
    mov.w   .L_06034F6A, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    mov.w   .L_06034F6C, r3
    cmp/eq r3, r0
    bf      .L_06034F5E
    mov #0x0, r3
    mov.w   .L_06034F6A, r2
    mov.b r3, @r2
    mov.l   .L_06034F70, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06034F58
    mov.l   .L_06034F74, r3
    mov.l @r3, r2
    jsr @r2
    nop
.L_06034F58:
    mov #0x0, r3
    mov.l   .L_06034F70, r2
    mov.l r3, @r2
.L_06034F5E:
    bra     .L_06034F34
    nop
.L_06034F62:
    .2byte  0xFF0F
.L_06034F64:
    .2byte  0xFEE2
.L_06034F66:
    .2byte  0xFE60
.L_06034F68:
    .2byte  0xFE10
.L_06034F6A:
    .2byte  0xFE11
.L_06034F6C:
    .2byte  0x0080
    .2byte  0xFFFF
.L_06034F70:
    .4byte  sym_06063574
.L_06034F74:
    .4byte  sym_06063574 + 0x20000000

    .global sym_06034F78
sym_06034F78:
    mov.l r1, @-r15
    mov.l r3, @-r15
    swap.b r1, r3
    extu.b r1, r1
    mov.l r4, @-r15
    extu.b r3, r3
    mov.l r5, @-r15
    mov r1, r4
    mov.l r6, @-r15
    mov #0x0, r5
    mov #-0x1, r6
.L_06034F8E:
    shll r5
    shll r6
    add #-0x1, r4
    add #0x1, r5
    cmp/pl r4
    bf      .L_06034FA6
    shll r5
    shll r6
    add #-0x1, r4
    add #0x1, r5
    cmp/pl r4
    bt      .L_06034F8E
.L_06034FA6:
    and r5, r0
    mov #0x20, r4
    sub r1, r4
    sub r3, r4
    mov r0, r5
    tst r4, r4
    bt      .L_06034FCC
.L_06034FB4:
    shll r6
    shll r5
    add #-0x1, r4
    add #0x1, r6
    cmp/pl r4
    bf      .L_06034FCC
    shll r6
    shll r5
    add #-0x1, r4
    add #0x1, r6
    cmp/pl r4
    bt      .L_06034FB4
.L_06034FCC:
    mov.l @r2, r4
    and r4, r6
    or r6, r5
    mov.l r5, @r2
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r3
    rts
    mov.l @r15+, r1

    .global sym_06034FE0
sym_06034FE0:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.w   .L_06034FFA, r3
    mov #0x0, r2
    mov.l r0, @r3
    add #0x8, r3
    mov.l r2, @r3
    mov.l r1, @-r3
    add #0x10, r3
    mov.l @r3, r0
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_06034FFA:
    .2byte  0xFF00

    .global sym_06034FFC
sym_06034FFC:
    tst r0, r0
    mov.l r2, @-r15
    bt      .L_0603509A
    mov.l r3, @-r15
    mov #0x0, r2
    div0s r2, r1
    subc r3, r3
    subc r2, r1
    div0s r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    addc r2, r1
    mov r1, r0
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_0603509A:
    mov.l   .L_060350A8, r1
    mov.l   .L_060350AC, r2
    mov #0x0, r0
    mov.l r2, @r1
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_060350A8:
    .4byte  sym_060A246C
.L_060350AC:
    .4byte  0x0000044E

    .global sym_060350B0
sym_060350B0:
    tst r0, r0
    bt      .L_06035150
    mov.l r3, @-r15
    mov #0x0, r3
    mov.l r4, @-r15
    mov r0, r4
    div0u
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    bf      .L_06035148
    mov r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_06035148:
    add r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_06035150:
    mov.l r2, @-r15
    mov.l   .L_06035160, r1
    mov.l   .L_06035164, r2
    mov #0x0, r0
    mov.l r2, @r1
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_06035160:
    .4byte  sym_060A246C
.L_06035164:
    .4byte  0x0000044E

    .global sym_06035168
sym_06035168:
    mov.l r3, @-r15
    mov #0x40, r3
    cmp/hs r0, r3
    bf      .L_06035208
    mov.l   .L_06035178, r3
    mov.l @(r0, r3), r3
    jmp @r3
    nop
.L_06035178:
    .4byte  sym_060351C4
    .2byte  0x0009
    .global loc_0603517E
loc_0603517E:
    mov.l @(60, r2), r0
    mov.l r0, @(60, r1)

    .global loc_06035182
loc_06035182:
    mov.l @(56, r2), r0
    mov.l r0, @(56, r1)

    .global loc_06035186
loc_06035186:
    mov.l @(52, r2), r0
    mov.l r0, @(52, r1)

    .global loc_0603518A
loc_0603518A:
    mov.l @(48, r2), r0
    mov.l r0, @(48, r1)

    .global loc_0603518E
loc_0603518E:
    mov.l @(44, r2), r0
    mov.l r0, @(44, r1)

    .global loc_06035192
loc_06035192:
    mov.l @(40, r2), r0
    mov.l r0, @(40, r1)

    .global loc_06035196
loc_06035196:
    mov.l @(36, r2), r0
    mov.l r0, @(36, r1)

    .global loc_0603519A
loc_0603519A:
    mov.l @(32, r2), r0
    mov.l r0, @(32, r1)

    .global loc_0603519E
loc_0603519E:
    mov.l @(28, r2), r0
    mov.l r0, @(28, r1)

    .global loc_060351A2
loc_060351A2:
    mov.l @(24, r2), r0
    mov.l r0, @(24, r1)

    .global loc_060351A6
loc_060351A6:
    mov.l @(20, r2), r0
    mov.l r0, @(20, r1)

    .global loc_060351AA
loc_060351AA:
    mov.l @(16, r2), r0
    mov.l r0, @(16, r1)

    .global loc_060351AE
loc_060351AE:
    mov.l @(12, r2), r0
    mov.l r0, @(12, r1)

    .global loc_060351B2
loc_060351B2:
    mov.l @(8, r2), r0
    mov.l r0, @(8, r1)

    .global loc_060351B6
loc_060351B6:
    mov.l @(4, r2), r0
    mov.l r0, @(4, r1)

    .global loc_060351BA
loc_060351BA:
    mov.l @r2, r0
    mov.l r0, @r1

    .global loc_060351BE
loc_060351BE:
    rts
    mov.l @r15+, r3
    .2byte  0x0009

    .global sym_060351C4
sym_060351C4:
    .4byte  loc_060351BE
    .4byte  loc_060351BA
    .4byte  loc_060351B6
    .4byte  loc_060351B2
    .4byte  loc_060351AE
    .4byte  loc_060351AA
    .4byte  loc_060351A6
    .4byte  loc_060351A2
    .4byte  loc_0603519E
    .4byte  loc_0603519A
    .4byte  loc_06035196
    .4byte  loc_06035192
    .4byte  loc_0603518E
    .4byte  loc_0603518A
    .4byte  loc_06035186
    .4byte  loc_06035182
    .4byte  loc_0603517E
.L_06035208:
    mov.l r2, @-r15
    mov r2, r3
    add r0, r3
.L_0603520E:
    mov.l @r2+, r0
    cmp/hs r2, r3
    bf      .L_06035222
    mov.l r0, @r1
    mov.l @r2+, r0
    cmp/hs r2, r3
    bf      .L_06035222
    mov.l r0, @(4, r1)
    bra     .L_0603520E
    add #0x8, r1
.L_06035222:
    mov.l @r15+, r2
    rts
    mov.l @r15+, r3

    .global sym_06035228
sym_06035228:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r4, @-r15
    cmp/eq #0x0, r0
    bt      .L_06035258
    mov r2, r4
    add r0, r4
.L_06035236:
    mov.b @r2+, r0
    mov.b r0, @r1
    cmp/hi r2, r4
    bf      .L_06035258
    mov.b @r2+, r0
    mov.b r0, @(1, r1)
    cmp/hi r2, r4
    bf      .L_06035258
    mov.b @r2+, r0
    mov.b r0, @(2, r1)
    cmp/hi r2, r4
    bf      .L_06035258
    mov.b @r2+, r0
    mov.b r0, @(3, r1)
    cmp/hi r2, r4
    add #0x4, r1
    bt      .L_06035236
.L_06035258:
    mov.l @r15+, r4
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2

    .global sym_06035260
sym_06035260:
    mov.b @(r0, r0), r14
    .word 0x0A08
    .4byte  loc_06040200
    .4byte  0x201E1C1A
    .4byte  0x18161412
    .4byte  0x3432302E
    .4byte  0x2C2A2826
    .4byte  0x403E3C3A
    .4byte  0x4856626C

    .global sym_06035280
sym_06035280:
    mov.l r2, @-r15
    cmp/pz r1
    bf/s    .L_060352B8
    mov #0x20, r2
    cmp/ge r2, r1
    bt      .L_060352A4
    mov.l   .L_060352A0, r2
    add r1, r2
    mov.b @r2, r2
    mov.l   .L_0603529C, r1
    add r2, r1
    jmp @r1
    nop
    .2byte  0x0009
.L_0603529C:
    .4byte  sym_060352AA
.L_060352A0:
    .4byte  sym_06035260
.L_060352A4:
    mov #0x0, r0
    rts
    mov.l @r15+, r2

    .global sym_060352AA
sym_060352AA:
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
.L_060352B8:
    rts
    mov.l @r15+, r2
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004018
    .4byte  0x000B62F6
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004028
    .4byte  0x000B62F6
    .4byte  0x40004000
    .4byte  0x40004018
    .4byte  0x4028000B
    .4byte  0x62F6C90F
    .4byte  0x40054005
    .4byte  0x40054005
    .4byte  0x000B62F6
    .4byte  0xC9074005
    .4byte  0x40054005
    .4byte  0x000B62F6
    .4byte  0xC9034005
    .4byte  0x4005000B
    .4byte  0x62F6C901
    .4byte  0x4005000B
    .4byte  0x62F60000
    .4byte  0xFCFAF8F6
    .4byte  0xF4F2F0EE
    .4byte  0xECEAE8E6
    .4byte  0xE4E2E0DE
    .4byte  0xDCDAD8D6
    .4byte  0xD4D2D0CE

    .global sym_06035338
sym_06035338:
    mov.b @(r0, r0), r0
    mov.l r3, @-r2
    .word 0x4858
    mov.l @r7, r6

    .global sym_06035340
sym_06035340:
    mov.l r2, @-r15
    cmp/pz r1
    bf/s    .L_060353BA
    mov #0x20, r2
    cmp/ge r2, r1
    bt      .L_0603537C
    mov r0, r2
    rotl r2
    bf      .L_06035362
.L_06035352:
    mov.l   .L_06035370, r2
    add #-0x18, r1
    add r2, r1
    mov.b @r1, r2
    mov.l   .L_06035374, r1
    add r2, r1
    jmp @r1
    nop
.L_06035362:
    mov #0x8, r2
    cmp/gt r2, r1
    bf      .L_06035352
    mov.l   .L_06035378, r2
    jmp @r2
    nop
    .2byte  0x0009
.L_06035370:
    .4byte  sym_06035338
.L_06035374:
    .4byte  sym_060353BE
.L_06035378:
    .4byte  sym_06036068
.L_0603537C:
    shll r0
    bt      .L_06035386
    mov #0x0, r0
    rts
    mov.l @r15+, r2
.L_06035386:
    mov #-0x1, r0
    rts
    mov.l @r15+, r2
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .2byte  0x4021
.L_060353BA:
    rts
    mov.l @r15+, r2

    .global sym_060353BE
sym_060353BE:
    swap.w r0, r1
    swap.b r1, r0
    mov #-0x80, r1
    or r1, r0
    rts
    mov.l @r15+, r2
    .2byte  0x4004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0xE1C0201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0xE1E0201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x4004E1F0
    .4byte  0x201B000B
    .4byte  0x62F64004
    .4byte  0x40044004
    .4byte  0x4004E1F8
    .4byte  0x201B000B
    .4byte  0x62F64004
    .4byte  0x40044004
    .4byte  0xE1FC201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0xE1FE201B
    .4byte  0x000B62F6
    .4byte  0xE0FF000B
    .4byte  0x62F60000

    .global sym_06035438
sym_06035438:
    cmp/pl r4
    bf      .L_06035440
    bra     .L_06035442
    mov r4, r0
.L_06035440:
    neg r4, r0
.L_06035442:
    rts
    nop
    .2byte  0x0000
    .4byte  0x2F062F46
    .4byte  0x2F562F66
    .4byte  0x2F7654F6
    .4byte  0x55F756F8
    .4byte  0x57F9D0B4
    .4byte  0xA061260A

    .global sym_06035460
sym_06035460:
    mov.l r0, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(24, r15), r6
    mov.l @(28, r15), r7
    mov.l @(32, r15), r4
    mov.l @(36, r15), r5
    mov.l   .L_0603572C, r0
    bra     .L_06035522
    xor r0, r6
.L_06035478:
    tst r4, r4
    bf      .L_0603548C
    tst r5, r5
    bf      .L_0603548C
    cmp/eq r3, r9
    bf      .L_06035494
    tst r7, r7
    bf      .L_0603548C
    div0s r10, r11
    bf      .L_06035494
.L_0603548C:
    mov #0x0, r10
    mov #0x0, r4
    bra     .L_060356CA
    mov #0x8, r5
.L_06035494:
    bra     .L_060356CA
    nop
.L_06035498:
    tst r8, r8
    bf      .L_060354AC
    tst r4, r4
    bf      .L_060354B8
    tst r5, r5
    bf      .L_060354B8
    tst r7, r7
    bf      .L_060354C4
    bra     .L_060356CA
    and r11, r10
.L_060354AC:
    tst r6, r6
    bf      .L_060354EE
    tst r7, r7
    bf      .L_060354EE
    bra     .L_060354CC
    nop
.L_060354B8:
    tst r6, r6
    bf      .L_060354DA
    tst r7, r7
    bf      .L_060354DA
    bra     .L_060354CC
    nop
.L_060354C4:
    mov r6, r4
    mov r7, r5
    mov r9, r8
    mov r11, r10
.L_060354CC:
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r5
    bra     .L_060356CA
    rotcl r4
.L_060354DA:
    mov.l   .L_06035728, r3
    shll r5
    rotcl r4
    cmp/ge r3, r4
    bt      .L_060354EE
.L_060354E4:
    shll r5
    rotcl r4
    cmp/ge r3, r4
    bf/s    .L_060354E4
    add #-0x1, r8
.L_060354EE:
    mov.l   .L_06035728, r3
    shll r7
    rotcl r6
    cmp/ge r3, r6
    bt      .L_06035502
.L_060354F8:
    shll r7
    rotcl r6
    cmp/ge r3, r6
    bf/s    .L_060354F8
    add #-0x1, r9
.L_06035502:
    bra     .L_0603556E
    nop
    .2byte  0xE800
    .4byte  0xE400A0DE
    .4byte  0xE5000009
    .4byte  0x2F062F46
    .4byte  0x2F562F66
    .4byte  0x2F7654F6
    .4byte  0x55F756F8
    .2byte  0x57F9
.L_06035522:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    rotl r4
    rotl r6
    cmp/hs r6, r4
    bt      .L_06035542
    mov r4, r2
    mov r6, r4
    mov r2, r6
    mov r5, r2
    mov r7, r5
    mov r2, r7
.L_06035542:
    rotr r4
    rotr r6
    mov.l   .L_06035714, r3
    mov.l   .L_06035718, r0
    mov r4, r10
    mov r6, r11
    mov r4, r8
    shlr16 r8
    shlr2 r8
    shlr2 r8
    and r3, r8
    mov r6, r9
    shlr16 r9
    shlr2 r9
    shlr2 r9
    and r3, r9
    and r0, r4
    and r0, r6
    cmp/eq r3, r8
    bt      .L_06035478
    tst r9, r9
    bt      .L_06035498
.L_0603556E:
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r7
    rotcl r6
    shll r7
    rotcl r6
    shll r7
    rotcl r6
    mov.l   .L_0603571C, r0
    or r0, r4
    or r0, r6
    mov r8, r2
    sub r9, r2
    tst r2, r2
    bt      .L_060355E8
    mov #0x3, r3
    cmp/ge r2, r3
    bt      .L_060355E0
    mov #0x36, r3
    cmp/gt r3, r2
    bt      .L_060355DA
    mov #0x20, r3
    cmp/gt r3, r2
    bf/s    .L_060355B4
    mov #0x1, r9
    sub r3, r2
    tst r7, r7
    bt      .L_060355B0
    or r9, r6
.L_060355B0:
    mov r6, r7
    mov #0x0, r6
.L_060355B4:
    sts.l mach, @-r15
    .word 0xC75F
    sts.l macl, @-r15
    shll2 r2
    add r2, r0
    mov.l @r0, r0
    dmulu.l r0, r7
    sts mach, r7
    sts macl, r2
    dmulu.l r0, r6
    sts mach, r6
    sts macl, r3
    lds.l @r15+, macl
    tst r2, r2
    lds.l @r15+, mach
    bt/s    .L_060355E8
    or r3, r7
    bra     .L_060355E8
    or r9, r7
.L_060355DA:
    mov #0x0, r6
    bra     .L_060355E8
    mov #0x1, r7
.L_060355E0:
    shlr r6
    rotcr r7
    dt r2
    bf      .L_060355E0
.L_060355E8:
    div0s r10, r11
    bt      .L_0603560C
    addc r7, r5
    addc r6, r4
    mov.l   .L_06035724, r3
    cmp/gt r4, r3
    bt      .L_0603569C
    shlr r4
    rotcr r5
    .word 0x0229
    or r2, r5
    add #0x1, r8
    mov.l   .L_06035714, r3
    cmp/eq r3, r8
    bf      .L_0603569C
    mov #0x0, r5
    bra     .L_060356CA
    mov #0x0, r4
.L_0603560C:
    cmp/eq r4, r6
    bf      .L_06035614
    cmp/eq r5, r7
    bt      .L_06035708
.L_06035614:
    subc r7, r5
    subc r6, r4
    bf      .L_06035622
    clrt
    negc r5, r5
    negc r4, r4
    mov r11, r10
.L_06035622:
    tst r4, r4
    bf      .L_0603562C
    mov r5, r4
    mov #0x0, r5
    add #-0x20, r8
.L_0603562C:
    mov.l   .L_06035730, r3
    tst r4, r3
    bf      .L_0603563C
    mov r5, r3
    xtrct r4, r3
    mov r3, r4
    shll16 r5
    add #-0x10, r8
.L_0603563C:
    mov.l   .L_06035724, r3
    cmp/hi r4, r3
    bt      .L_0603566E
.L_06035642:
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_0603569C
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_0603569C
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_0603569C
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_0603569C
    add #0x1, r8
    bra     .L_06035642
    nop
.L_0603566E:
    mov.l   .L_0603571C, r3
    .4byte  0x34338913
    .4byte  0x45004424
    .4byte  0x34338D0F
    .4byte  0x78FF4500
    .4byte  0x44243433
    .4byte  0x8D0A78FF
    .4byte  0x45004424
    .4byte  0x34338D05
    .4byte  0x78FF4500
    .4byte  0x44243433
    .4byte  0x8FEC78FF
.L_0603569C:
    .4byte  0x48158905
    .4byte  0x688B7801
    .4byte  0x44014525
    .4byte  0x48108BFB
    .4byte  0x6053C804
    .4byte  0x890BC80B
    .4byte  0x8909E008
    .4byte  0x350EE000
    .4byte  0x340ED019
    .4byte  0x30478902
    .4byte  0x44014525
    .2byte  0x7801
.L_060356CA:
    shlr r4
    rotcr r5
    shlr r4
    rotcr r5
    shlr r4
    rotcr r5
    mov.l   .L_06035718, r0
    and r0, r4
    shll16 r8
    shll2 r8
    shll2 r8
    or r8, r4
    shll r4
    shll r10
    rotcr r4
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @(20, r15), r6
    mov.l r4, @r6
    mov.l r5, @(4, r6)
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r0
    rts
    add #0x14, r15
.L_06035708:
    mov #0x0, r10
    mov #0x0, r8
    mov #0x0, r4
    bra     .L_060356CA
    mov #0x0, r5
    .2byte  0x0009
.L_06035714:
    .4byte  0x000007FF
.L_06035718:
    .4byte  0x000FFFFF
.L_0603571C:
    .4byte  0x00800000
    .4byte  0x0000FFFF
.L_06035724:
    .4byte  0x01000000
.L_06035728:
    .4byte  0x00100000
.L_0603572C:
    .4byte  0x80000000
.L_06035730:
    .4byte  0xFFFF0000

    .global DAT_06035734
DAT_06035734:
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, r0)
    .word 0x0000
    shll r0
    .word 0x0000
    mov.b r0, @r0
    .word 0x0000
    mov.l r0, @(0, r0)
    .word 0x0000
    .word 0x0800
    .word 0x0000
    .word 0x0400
    .word 0x0000
    .word 0x0200
    .word 0x0000
    .word 0x0100
    .word 0x0000
    .word 0x0080
    .word 0x0000
    .word 0x0040
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0010
    .word 0x0000
    clrt
    .word 0x0000
    mov.b r0, @(r0, r0)
    .word 0x0000
    stc sr, r0
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, r0)
    .word 0x0000
    shll r0
    .word 0x0000
    mov.b r0, @r0
    .word 0x0000
    mov.l r0, @(0, r0)
    .word 0x0000
    .word 0x0800
    .word 0x0000
    .word 0x0400
    .word 0x0000
    .word 0x0200
    .word 0x0000
    .word 0x0100
    .word 0x0000
    .word 0x0080
    .word 0x0000
    .word 0x0040
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0010
    .word 0x0000
    clrt
    .word 0x0000
    mov.b r0, @(r0, r0)
    .word 0x0000
    stc sr, r0
    .word 0x0000
    .word 0x0001

    .global sym_060357B8
sym_060357B8:
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l @(20, r15), r0
    mov.l @(24, r15), r1
    mov.l   .L_06035834, r4
    mov.l   .L_06035838, r5
    mov r0, r3
    mov r0, r2
    shlr16 r2
    shlr2 r2
    shlr2 r2
    and r4, r2
    and r5, r0
    mov.l   .L_06035840, r4
    sub r4, r2
    cmp/pz r2
    bf      .L_06035830
    mov #0x53, r4
    cmp/gt r4, r2
    bt      .L_06035830
    mov.l   .L_0603583C, r4
    or r4, r0
    add #-0x14, r2
    cmp/pz r2
    bf      .L_06035814
    mov #0x20, r4
    cmp/ge r4, r2
    bt      .L_06035802
    add #0x1, r2
.L_060357F8:
    dt r2
    bt      .L_0603581C
    shll r1
    bra     .L_060357F8
    rotcl r0
.L_06035802:
    mov r1, r0
    add #-0x20, r2
    tst r2, r2
    bt      .L_0603581C
.L_0603580A:
    dt r2
    bf/s    .L_0603580A
    shll r0
    bra     .L_0603581C
    nop
.L_06035814:
    neg r2, r2
.L_06035816:
    dt r2
    bf/s    .L_06035816
    shlr r0
.L_0603581C:
    shll r3
    bf      .L_06035822
    neg r0, r0
.L_06035822:
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    rts
    add #0x8, r15
.L_06035830:
    bra     .L_06035822
    mov #0x0, r0
.L_06035834:
    .4byte  0x000007FF
.L_06035838:
    .4byte  0x000FFFFF
.L_0603583C:
    .4byte  0x00100000
.L_06035840:
    .4byte  0x000003FF

    .global sym_06035844
sym_06035844:
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(24, r15), r4
    mov.l @(28, r15), r5
    mov.l @(16, r15), r6
    mov.l @(20, r15), r7
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l   .L_060358E4, r0
    mov r4, r10
    mov r6, r11
    mov r4, r8
    and r0, r8
    mov r6, r9
    and r0, r9
    mov.l   .L_060358E8, r0
    and r0, r4
    and r0, r6
    mov.l   .L_060358E4, r0
    cmp/eq r0, r8
    bt      .L_060358B0
.L_06035876:
    cmp/eq r0, r9
    bt      .L_060358BC
.L_0603587A:
    tst r8, r8
    bt      .L_060358C8
.L_0603587E:
    div0s r10, r11
    bt      .L_06035898
    cmp/pz r10
    bf      .L_06035890
    clrt
    subc r5, r7
    subc r10, r11
    bra     .L_0603589C
    .word 0x0029
.L_06035890:
    subc r7, r5
    subc r11, r10
    bra     .L_0603589C
    .word 0x0029
.L_06035898:
    cmp/pz r10
    .word 0x0029
.L_0603589C:
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    rts
    add #0x10, r15
.L_060358B0:
    tst r4, r4
    bf      .L_060358E0
    tst r5, r5
    bf      .L_060358E0
    bra     .L_06035876
    nop
.L_060358BC:
    tst r6, r6
    bf      .L_060358E0
    tst r7, r7
    bf      .L_060358E0
    bra     .L_0603587A
    nop
.L_060358C8:
    tst r9, r9
    bf      .L_0603587E
    tst r4, r4
    bf      .L_0603587E
    tst r5, r5
    bf      .L_0603587E
    tst r6, r6
    bf      .L_0603587E
    tst r7, r7
    bf      .L_0603587E
    bra     .L_0603589C
    mov #0x0, r0
.L_060358E0:
    bra     .L_0603589C
    mov #0x0, r0
.L_060358E4:
    .4byte  0x7FF00000
.L_060358E8:
    .4byte  0x000FFFFF

    .global sym_060358EC
sym_060358EC:
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    tst r0, r0
    bt      .L_06035934
    mov #0x0, r3
    cmp/pz r0
    bt      .L_06035900
    mov #0x1, r3
    neg r0, r0
.L_06035900:
    mov.l   .L_0603593C, r1
.L_06035902:
    shll r0
    bf/s    .L_06035902
    add #-0x1, r1
    mov r0, r2
    shll16 r2
    shll2 r2
    shll2 r2
    shlr8 r0
    shlr2 r0
    shlr2 r0
    shll16 r1
    shll2 r1
    shll2 r1
    or r1, r0
    shll r0
    shlr r3
    rotcr r0
.L_06035924:
    mov.l @(12, r15), r1
    mov.l r0, @r1
    mov.l r2, @(4, r1)
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    rts
    add #0x4, r15
.L_06035934:
    mov #0x0, r2
    bra     .L_06035924
    mov #0x0, r0
    .2byte  0x0009
.L_0603593C:
    .4byte  0x0000041F
    .4byte  0x24488B4A
    .4byte  0x25588B48
    .4byte  0x39308907
    .4byte  0x29988B40
    .4byte  0x26688B3E
    .4byte  0x27788B3C
    .4byte  0xA03F0009
    .4byte  0x26688B3C
    .4byte  0x27788B3A
    .4byte  0xA0350009
    .4byte  0x26688B36
    .4byte  0x27788B34
    .4byte  0x28888B2E
    .4byte  0x24488B2C
    .4byte  0x25588B2A
    .4byte  0xA02D0009
    .4byte  0x24488B03
    .4byte  0x25588B01
    .4byte  0xA01E0009
    .4byte  0xD0664500
    .4byte  0x44243403
    .4byte  0x89044500
    .4byte  0x44243403
    .4byte  0x8FFB78FF
    .4byte  0xA04B0009
    .4byte  0x26688B03
    .4byte  0x27788B01
    .4byte  0xA00C0009
    .4byte  0xD05D4700
    .4byte  0x46243603
    .4byte  0x89044700
    .4byte  0x46243603
    .4byte  0x8FFB79FF
    .4byte  0xA03B0009
    .4byte  0x4A000129
    .4byte  0xE000A091
    .4byte  0x4105D853
    .4byte  0xE100A07E
    .4byte  0xE000EA00
    .4byte  0xD850E100
    .4byte  0xA079E008

    .global sym_060359E4
sym_060359E4:
    mov.l r0, @-r15
    mov.l r1, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(28, r15), r4
    mov.l @(32, r15), r5
    mov.l @(36, r15), r6
    mov.l @(40, r15), r7
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
