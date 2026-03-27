
    .section .text.FUN_0601AAE8


    .global FUN_0601AAE8
    .type FUN_0601AAE8, @function
FUN_0601AAE8:
    sts.l pr, @-r15
    mov.l   .L_0601AB50, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_0601AB4E, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601AB48
    mov #0x1E, r3
    mov.l   .L_0601AB54, r2
    mov #0x1, r5
    mov #0x0, r4
    mov.l r3, @r2
    exts.b r4, r0
    extu.b r5, r3
    mov.l   .L_0601AB58, r2
    exts.b r5, r5
    mov.b r3, @r2
    mov.l   .L_0601AB5C, r2
    mov.b r4, @r2
    mov.l   .L_0601AB60, r2
    mov.b r0, @r2
    mov.l   .L_0601AB64, r3
    mov.b r5, @r3
    mov.l   .L_0601AB68, r3
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_0601AB6C, r3
    mov.b r4, @r3
    mov.l   .L_0601AB70, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0601AB74, r4
    mov.l   .L_0601AB78, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov.l   .L_0601AB7C, r3
    jsr @r3
    nop
    mov.l   .L_0601AB80, r5
    mov.l   .L_0601AB84, r3
    jsr @r3
    mov #0xF, r4
    mov.l   .L_0601AB88, r3
    jmp @r3
    lds.l @r15+, pr
.L_0601AB48:
    lds.l @r15+, pr
    rts
    nop
.L_0601AB4E:
    .2byte  0x0700
.L_0601AB50:
    .4byte  sym_06063D9A
.L_0601AB54:
    .4byte  FUN_0605ACC4
.L_0601AB58:
    .4byte  sym_0605E0A2
.L_0601AB5C:
    .4byte  sym_06085FF0
.L_0601AB60:
    .4byte  sym_0605D245
.L_0601AB64:
    .4byte  sym_06085FF1
.L_0601AB68:
    .4byte  sym_06085FF2
.L_0601AB6C:
    .4byte  sym_06085FF3
.L_0601AB70:
    .4byte  sym_0602853E
.L_0601AB74:
    .4byte  sym_0605B6D8
.L_0601AB78:
    .4byte  sym_06028560
.L_0601AB7C:
    .4byte  FUN_0601950C
.L_0601AB80:
    .4byte  0xAE0001FF
.L_0601AB84:
    .4byte  FUN_0601D5F4         /* sound command dispatcher */
.L_0601AB88:
    .4byte  FUN_06018E70

    .global sym_0601AB8C
sym_0601AB8C:
    mov.l   .L_0601AC14, r4
    mov.l   .L_0601AC18, r2
    mov.l @r4, r0
    exts.b r0, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    exts.b r0, r0
    mov.l   .L_0601AC1C, r3
    add r2, r0
    mov.l @r3, r3
    shll2 r3
    mov.l @(r0, r3), r1
    mov.l   .L_0601AC20, r3
    mov.l r1, @r3
    mov.l @r4, r0
    mov.l   .L_0601AC24, r3
    mov.l   .L_0601AC28, r2
    shll r0
    mov.l @r3, r3
    add r3, r0
    shll2 r0
    mov.l @(r0, r2), r4
    mov.l @(4, r4), r1
    mov.l   .L_0601AC2C, r0
    rts
    mov.l r1, @r0

    .global sym_0601ABC6
sym_0601ABC6:
    mov #0x0, r4


    .global FUN_0601ABC8
    .type FUN_0601ABC8, @function
FUN_0601ABC8:
    sts.l pr, @-r15
    extu.b r4, r3
    mov.l   .L_0601AC30, r2
    mov.b r3, @r2
    mov.l   .L_0601AC34, r2
    mov.b r4, @r2
    mov.l   .L_0601AC38, r2
    mov.l r4, @r2
    mov.l   .L_0601AC3C, r2
    mov.l r4, @r2
    bsr     FUN_0601ADB0
    nop
    mov.l   .L_0601AC14, r4
    mov.l   .L_0601AC28, r3
    mov.l   .L_0601AC40, r5
    mov.l @r4, r4
    mov.l @r5, r2
    shll r4
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    mov.l @(4, r4), r3
    cmp/ge r3, r2
    bt      .L_0601AC04
    mov.l @r5, r3
    cmp/pl r3
    bf      .L_0601AC04
    mov #0x1, r3
    mov.l   .L_0601AC34, r2
    mov.b r3, @r2
.L_0601AC04:
    mov.l   .L_0601AC44, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601AC48
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
.L_0601AC14:
    .4byte  sym_0607EAD8
.L_0601AC18:
    .4byte  sym_0605DE40
.L_0601AC1C:
    .4byte  sym_0605AD00
.L_0601AC20:
    .4byte  sym_06086004
.L_0601AC24:
    .4byte  sym_0607EAE0
.L_0601AC28:
    .4byte  sym_0605DE24
.L_0601AC2C:
    .4byte  sym_06086008
.L_0601AC30:
    .4byte  sym_06085FF8
.L_0601AC34:
    .4byte  sym_06085FF9
.L_0601AC38:
    .4byte  sym_06085FFC
.L_0601AC3C:
    .4byte  sym_06086000
.L_0601AC40:
    .4byte  sym_06078638
.L_0601AC44:
    .4byte  sym_0607EBF4
.L_0601AC48:
    mov.l   .L_0601ACE8, r4
    mov.l   .L_0601ACEC, r2
    mov.w   .L_0601ACE4, r0
    mov.l @r4, r4
    mov.l @r2, r2
    mov r4, r3
    shll r2
    shll r4
    shll2 r3
    add r3, r4
    add r2, r4
    mov.l   .L_0601ACF0, r3
    shll2 r4
    mov.l   .L_0601ACF4, r2
    add r3, r4
    mov.l @r2, r2
    mov.l @r4, r4
    mov.l @(r0, r4), r3
    cmp/hs r3, r2
    bt      .L_0601AC76
    mov #0x1, r2
    .byte   0xD3, 0x21    /* mov.l .L_pool_0601ACF8, r3 */
    mov.b r2, @r3
.L_0601AC76:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_0601AC7C
    .type FUN_0601AC7C, @function
FUN_0601AC7C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x0, r10

    .global FUN_0601AC88
    .type FUN_0601AC88, @function
FUN_0601AC88:
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
    .2byte  0x00E8
    .2byte  0xFFFF
.L_0601ACE8:
    .4byte  sym_0607EAD8
.L_0601ACEC:
    .4byte  sym_0605AD00
.L_0601ACF0:
    .4byte  sym_0605DD6C
.L_0601ACF4:
    .4byte  sym_060786A4
    .4byte  sym_06085FF8
.L_0601ACFC:
    .4byte  sym_0605DE24
.L_0601AD00:
    .4byte  sym_0607EBF4
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
    .4byte  sym_06035168
.L_0601AD98:
    .4byte  sym_0605DE3C
.L_0601AD9C:
    .4byte  sym_0607EAE0
.L_0601ADA0:
    .4byte  sym_06085FFC
.L_0601ADA4:
    .4byte  sym_06086012
.L_0601ADA8:
    .4byte  sym_06086000
.L_0601ADAC:
    .4byte  sym_06078638
    .global FUN_0601ADB0
FUN_0601ADB0:
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
    .2byte  0x0240
    .4byte  sym_0607EAD8
    .4byte  sym_0607EAE0
    .4byte  sym_0605DE24
    .4byte  sym_06078638
    .4byte  sym_06078900
    .4byte  sym_060786A4
    .4byte  sym_0605AD00
    .4byte  sym_0605DE40
    .4byte  sym_0607EBF4
.L_0601AE64:
    .4byte  sym_06083255
.L_0601AE68:
    .4byte  sym_0607EAB8
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

    .global FUN_0601AE80
    .type FUN_0601AE80, @function
FUN_0601AE80:
    sts.l pr, @-r15
    mov #0x0, r4
    mov #0x28, r1
    mov.l   .L_pool_0601AED4, r2
    extu.b r4, r3
    extu.b r4, r4
    mov.b r3, @r2
    mov.l   .L_pool_0601AED8, r2
    mov.b r1, @r2
    mov.l   .L_pool_0601AEDC, r2
    mov.b r4, @r2
    mov.l   .L_pool_0601AEE0, r5
    mov.l   .L_pool_0601AEE4, r4
    mov.l   .L_pool_0601AEE8, r2
    jsr @r2
    mov #0x60, r6
    mov.l   .L_pool_0601AEEC, r5
    mov.l   .L_pool_0601AEF0, r4
    mov.l   .L_pool_0601AEE8, r3
    jsr @r3
    mov #0x20, r6
    mov.w   .L_wpool_0601AEC8, r6
    mov.l   .L_pool_0601AEF4, r5
    mov.l   .L_pool_0601AEF8, r4
    mov.l   .L_pool_0601AEFC, r3
    jmp @r3
    lds.l @r15+, pr

    .global sym_0601AEB6
sym_0601AEB6:
    mov.l   .L_pool_0601AEDC, r3
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_0601AF00, r2
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop
.L_wpool_0601AEC8:
    .2byte  0x0180
    .2byte  0xFFFF
    .4byte  sym_06078868
    .4byte  sym_06078663
.L_pool_0601AED4:
    .4byte  sym_06086010
.L_pool_0601AED8:
    .4byte  sym_0608600F
.L_pool_0601AEDC:
    .4byte  sym_06086011
.L_pool_0601AEE0:
    .4byte  sym_0604866C
.L_pool_0601AEE4:
    .4byte  0x25F006C0
.L_pool_0601AEE8:
    .4byte  FUN_0602761E
.L_pool_0601AEEC:
    .4byte  sym_060485CC
.L_pool_0601AEF0:
    .4byte  0x25F00180
.L_pool_0601AEF4:
    .4byte  sym_0604996C
.L_pool_0601AEF8:
    .4byte  0x25F00000
.L_pool_0601AEFC:
    .4byte  FUN_0602766C
.L_pool_0601AF00:
    .4byte  sym_0605DEC8

    .global FUN_0601AF04
FUN_0601AF04:
    mov.l   .L_0601AF6C, r4
    mov.b @r4, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601AF16
    mov.l   .L_0601AF70, r5
    mov.b @r5, r3
    add #0x1, r3
    mov.b r3, @r5
.L_0601AF16:
    mov.b @r4, r2
    add #-0x1, r2
    rts
    mov.b r2, @r4


    .global FUN_0601AF1E
    .type FUN_0601AF1E, @function
FUN_0601AF1E:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601AF74, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_0601AF6A, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.l   .L_0601AF78, r3
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0601AF7C, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_0601AF80, r14
    mov.l   .L_0601AF84, r5
    mov.l   .L_0601AF88, r4
    mov.b @r14, r6
    mov.l @r5, r5
    mov.l @r4, r4
    exts.b r5, r5
    .reloc ., R_SH_IND12W, FUN_0601B09A - 4
    .2byte 0xB000    /* bsr FUN_0601B09A (linker-resolved) */
    exts.b r4, r4
    mov #0xA, r3
    mov.b @r14, r2
    add #0x5, r2
    mov.b r2, @r14
    mov.l   .L_0601AF6C, r2
    mov.b r3, @r2
    mov.l   .L_0601AF70, r4
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601AF6A:
    .2byte  0x0096
.L_0601AF6C:
    .4byte  sym_0608600F
.L_0601AF70:
    .4byte  sym_06086011
.L_0601AF74:
    .4byte  sym_060638C8
.L_0601AF78:
    .4byte  0x0000C000
.L_0601AF7C:
    .4byte  sym_06028400
.L_0601AF80:
    .4byte  sym_06086010
.L_0601AF84:
    .4byte  sym_0605AD00
.L_0601AF88:
    .4byte  sym_0607EAD8
