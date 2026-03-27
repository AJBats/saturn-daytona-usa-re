
    .section .text.FUN_0601C978


    .global FUN_0601C978
    .type FUN_0601C978, @function
FUN_0601C978:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x0, r13
    add #-0x4, r15
    mov.l   .L_0601CA44, r14
    mov.l   .L_0601CA48, r3
    mov.l r13, @r3
    mov.l   .L_0601CA4C, r3
    mov.b r13, @r3
    mov.w   DAT_0601ca3a, r1
    mov.l   .L_0601CA50, r3
    jsr @r3
    mov.w r1, @r14
    mov.l   .L_0601CA54, r3
    jsr @r3
    nop
    mov.l   .L_0601CA58, r3
    jsr @r3
    nop
    mov.l   .L_0601CA5C, r3
    mov.l r13, @r3
    mov.l   .L_0601CA60, r3
    jsr @r3
    nop
    mov.w   DAT_0601ca3c, r2
    mov.l   .L_0601CA64, r3
    mov.l r2, @r3
    mov.l   .L_0601CA68, r3
    mov.l r13, @r3
    mov.l   .L_0601CA6C, r3
    mov.l r13, @r3
    mov.l   .L_0601CA70, r5
    mov #0x20, r4
.L_0601C9BC:
    mov.w @r14, r3
    add #-0x2, r4
    mov.w r3, @r5
    add #0x2, r5
    mov.w @r14, r3
    mov r5, r2
    add #0x2, r5
    tst r4, r4
    bf/s    .L_0601C9BC
    mov.w r3, @r2
    mov.l   .L_0601CA74, r5
    mov #0x20, r4
.L_0601C9D4:
    mov.w @r14, r2
    add #-0x2, r4
    mov.w r2, @r5
    add #0x2, r5
    mov.w @r14, r2
    mov r5, r3
    add #0x2, r5
    tst r4, r4
    bf/s    .L_0601C9D4
    mov.w r2, @r3
    mov.l   .L_0601CA78, r5
    mov.l   .L_0601CA7C, r4
    mov.l   .L_0601CA80, r3
    jsr @r3
    mov #0x40, r6
    mov #0x9, r7
    mov.l   .L_0601CA84, r5
    mov.l   .L_0601CA88, r4
    mov.l   .L_0601CA8C, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_0601CA90, r5
    mov.l   .L_0601CA94, r4
    mov.l   .L_0601CA8C, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_0601CA98, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601CA3E, r6
    mov.l   .L_0601CA9C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    mov.l   .L_0601CAA0, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601CA3E, r6
    mov.l   .L_0601CA9C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x0, r4
    mov.l   .L_0601CAA4, r13
    mov.w   .L_0601CA40, r4
    bra     .L_0601CAA8
    mov #0x0, r5

    .global DAT_0601ca3a
DAT_0601ca3a:
    .2byte  0x77BD

    .global DAT_0601ca3c
DAT_0601ca3c:
    .2byte  0x012C
.L_0601CA3E:
    .2byte  0x0518
.L_0601CA40:
    .2byte  0x0100
    .2byte  0xFFFF
.L_0601CA44:
    .4byte  sym_06086028
.L_0601CA48:
    .4byte  sym_0608602C
.L_0601CA4C:
    .4byte  sym_06086030
.L_0601CA50:
    .4byte  sym_060149E0
.L_0601CA54:
    .4byte  FUN_060148FC
.L_0601CA58:
    .4byte  sym_06026CE0
.L_0601CA5C:
    .4byte  sym_06059F44
.L_0601CA60:
    .4byte  FUN_0600A026
.L_0601CA64:
    .4byte  sym_0608601C
.L_0601CA68:
    .4byte  sym_06086020
.L_0601CA6C:
    .4byte  sym_06086024
.L_0601CA70:
    .4byte  0x25F00200
.L_0601CA74:
    .4byte  0x25F00400
.L_0601CA78:
    .4byte  sym_0604880C
.L_0601CA7C:
    .4byte  0x25F00000
.L_0601CA80:
    .4byte  FUN_0602766C
.L_0601CA84:
    .4byte  0x00014000
.L_0601CA88:
    .4byte  0x25E70E40
.L_0601CA8C:
    .4byte  sym_0600511E
.L_0601CA90:
    .4byte  0x00016BC0
.L_0601CA94:
    .4byte  0x25E7B168
.L_0601CA98:
    .4byte  sym_06063958
.L_0601CA9C:
    .4byte  sym_06028400
.L_0601CAA0:
    .4byte  sym_06063960
.L_0601CAA4:
    .4byte  FUN_06038BD4
.L_0601CAA8:
    jsr @r13
    nop
    mov #0x1, r5
    jsr @r13
    mov #0x4, r4
    mov #0x2, r5
    jsr @r13
    mov #0x8, r4
    mov #0x0, r5
    jsr @r13
    mov #0x10, r4
    mov #0x0, r5
    jsr @r13
    mov #0x20, r4
    .byte   0xD6, 0x21    /* mov.l r6, sym_06086028 */
    .byte   0xD4, 0x22    /* mov.l r4, 0x25F00FFE */
    .byte   0xD3, 0x22    /* mov.l r3, FUN_06036E90 */
    jsr @r3
    mov #0x1, r5
    .byte   0xD4, 0x22    /* mov.l r4, sym_0605B6D8 */
    .byte   0xD2, 0x22    /* mov.l r2, 0x40000000 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    .byte   0xD3, 0x21    /* mov.l r3, sym_06026CE0 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x20    /* mov.l r3, sym_06059F44 */
    mov.l r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601CAEE
    .type FUN_0601CAEE, @function
FUN_0601CAEE:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601CB68, r8
    mov.l   .L_0601CB6C, r9
    mov.l   .L_0601CB70, r10
    mov.l   .L_0601CB74, r12
    mov.l   .L_0601CB78, r13
    mov.l   .L_0601CB7C, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.l   .L_0601CB80, r2
    mov.w @r2, r3
    mov.w   DAT_0601cb48, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_0601CBB6
    mov #0x0, r11
    mov.l   .L_0601CB78, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601CBB6
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CB84, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0601CB88, r2
    mov.l   .L_0601CB8C, r3
    jsr @r3
    mov.l r2, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CB90
    mov #0x1, r2
    bra     .L_0601CBB6
    mov.l r2, @r13

    .global DAT_0601cb48
DAT_0601cb48:
    .2byte  0x0800
    .2byte  0xFFFF
    .4byte  sym_06086028
    .4byte  0x25F00FFE
    .4byte  FUN_06036E90
    .4byte  sym_0605B6D8
    .4byte  0x40000000
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
.L_0601CB68:
    .4byte  sym_06086020
.L_0601CB6C:
    .4byte  0x25F00200
.L_0601CB70:
    .4byte  0x25F00400
.L_0601CB74:
    .4byte  FUN_0602766C
.L_0601CB78:
    .4byte  sym_06086024
.L_0601CB7C:
    .4byte  sym_0608601C
.L_0601CB80:
    .4byte  g_pad_state
.L_0601CB84:
    .4byte  sym_060358EC
.L_0601CB88:
    .4byte  0x40680000
.L_0601CB8C:
    .4byte  sym_06035844
.L_0601CB90:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD38, r3
    mov.l   .L_0601CD3C, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CBB2
    mov #0x2, r3
    mov.l r3, @r13
    bra     .L_0601CBB6
    nop
.L_0601CBB2:
    mov #0x3, r2
    mov.l r2, @r13
.L_0601CBB6:
    bsr     FUN_0601D12C
    nop
    mov.l @r13, r0
    tst r0, r0
    bt      .L_0601CBC4
    bra     .L_0601CD58
    nop
.L_0601CBC4:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0601CD40, r2
    mov.l   .L_0601CD3C, r3
    jsr @r3
    mov.l r2, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CBE2
    bra     .L_0601CDA4
    nop
.L_0601CBE2:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD44, r3
    mov.l   .L_0601CD3C, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CC04
    bsr     FUN_0601CDC0
    nop
    bra     .L_0601CDA4
    nop
.L_0601CC04:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD44, r3
    mov.l   .L_0601CD48, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bf      .L_0601CC20
    mov.l r11, @r8
.L_0601CC20:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0601CD4C, r2
    mov.l   .L_0601CD3C, r3
    jsr @r3
    mov.l r2, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CC42
    bsr     FUN_0601CEFC
    nop
    bra     .L_0601CDA4
    nop
.L_0601CC42:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD4C, r3
    mov.l   .L_0601CD48, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bf      .L_0601CC64
    bsr     FUN_0601D014
    nop
    bra     .L_0601CDA4
    nop
.L_0601CC64:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD50, r3
    mov.l   .L_0601CD3C, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CC86
    bsr     FUN_0601CDC0
    nop
    bra     .L_0601CDA4
    nop
.L_0601CC86:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD50, r3
    mov.l   .L_0601CD48, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bf      .L_0601CCA2
    mov.l r11, @r8
.L_0601CCA2:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_0601CD38, r2
    mov.l   .L_0601CD3C, r3
    jsr @r3
    mov.l r2, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CCC4
    bsr     FUN_0601CEFC
    nop
    bra     .L_0601CDA4
    nop
.L_0601CCC4:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD38, r3
    mov.l   .L_0601CD48, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bf      .L_0601CCE6
    bsr     FUN_0601D074
    nop
    bra     .L_0601CDA4
    nop
.L_0601CCE6:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD54, r3
    mov.l   .L_0601CD3C, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bt      .L_0601CD08
    bsr     FUN_0601CDC0
    nop
    bra     .L_0601CDA4
    nop
.L_0601CD08:
    mov.l @r14, r0
    add #-0x8, r15
    mov.l   .L_0601CD34, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_0601CD54, r3
    mov.l   .L_0601CD48, r2
    jsr @r2
    mov.l r3, @-r15
    cmp/eq #0x0, r0
    bf      .L_0601CD24
    mov.l r11, @r8
.L_0601CD24:
    mov.l @r14, r3
    cmp/pl r3
    bf      .L_0601CD9E
    bsr     FUN_0601CEFC
    nop
    bra     .L_0601CDA4
    nop
    .2byte  0xFFFF
.L_0601CD34:
    .4byte  sym_060358EC
.L_0601CD38:
    .4byte  0x40568000
.L_0601CD3C:
    .4byte  sym_06035844
.L_0601CD40:
    .4byte  0x40726000
.L_0601CD44:
    .4byte  0x406D4000
.L_0601CD48:
    .4byte  sym_06035B34
.L_0601CD4C:
    .4byte  0x40680000
.L_0601CD50:
    .4byte  0x40608000
.L_0601CD54:
    .4byte  0x403E0000
.L_0601CD58:
    mov.l @r13, r0
    cmp/eq #0x1, r0
    bf      .L_0601CD6E
    mov #0x20, r6
    mov.l   .L_0601CDFC, r5
    jsr @r12
    mov r9, r4
    mov #0x20, r6
    mov.l   .L_0601CE00, r5
    jsr @r12
    mov r10, r4
.L_0601CD6E:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bf      .L_0601CD88
    bsr     FUN_0601D014
    nop
    mov #0x20, r6
    mov.l   .L_0601CE04, r5
    jsr @r12
    mov r9, r4
    mov #0x20, r6
    mov.l   .L_0601CE08, r5
    jsr @r12
    mov r10, r4
.L_0601CD88:
    mov.l @r13, r0
    cmp/eq #0x3, r0
    bf      .L_0601CD9E
    mov #0x20, r6
    mov.l   .L_0601CE0C, r5
    jsr @r12
    mov r9, r4
    mov #0x20, r6
    mov.l   .L_0601CE10, r5
    jsr @r12
    mov r10, r4
.L_0601CD9E:
    mov #0x2, r3
    mov.l   .L_0601CE14, r2
    mov.l r3, @r2
.L_0601CDA4:
    mov.l   .L_0601CE18, r3
    jsr @r3
    nop
    mov.l   .L_0601CE1C, r3
    mov.l r11, @r3
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global FUN_0601CDC0
    .type FUN_0601CDC0, @function
FUN_0601CDC0:
    mov.l r14, @-r15
    mov #0x12, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x54, r15
    mov r15, r10
    mov.l   .L_0601CE20, r12
    add #0x14, r10
    mov.l @r12, r3
    cmp/ge r2, r3
    bt/s    .L_0601CED0
    mov #0x64, r13
    mov.l @r12, r11
    shll r11
    mov.l   .L_0601CE24, r3
    add r3, r11
    mov.w @r11, r11
    mov r13, r14
    sub r11, r14
    mov.l   .L_0601CE28, r2
    mov.l r2, @(12, r15)
    mov r10, r2
    mov.l r2, @(16, r15)
    bra     .L_0601CEB4
    mov #0x0, r9
.L_0601CDFC:
    .4byte  sym_0604880C
.L_0601CE00:
    .4byte  sym_0604882C
.L_0601CE04:
    .4byte  sym_0604884C
.L_0601CE08:
    .4byte  sym_0604886C
.L_0601CE0C:
    .4byte  sym_0605D17C
.L_0601CE10:
    .4byte  sym_0605D19C
.L_0601CE14:
    .4byte  FUN_0605ACC4
.L_0601CE18:
    .4byte  sym_06026CE0
.L_0601CE1C:
    .4byte  sym_06059F44
.L_0601CE20:
    .4byte  sym_06086020
.L_0601CE24:
    .4byte  sym_0605DF58
.L_0601CE28:
    .4byte  0x25F00000
.L_0601CE2C:
    mov r15, r7
    mov r15, r6
    mov r15, r5
    mov.l @(12, r15), r4
    add #0x8, r7
    add #0x4, r6
    add #0x2, r4
    mov.l r4, @(12, r15)
    add #-0x2, r4
    mov.w @r4, r4
    bsr     .L_0601D0BC
    extu.w r4, r4
    mov.w @r15, r1
    mov #0x1D, r4
    mov.l   .L_0601CEEC, r3
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    mul.l r4, r11
    sts macl, r4
    add r4, r1
    jsr @r3
    mov r13, r0
    extu.w r0, r0
    mov.w r0, @r15
    mov.w @(4, r15), r0
    mov.l   .L_0601CEEC, r3
    mov r0, r1
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    add r4, r1
    jsr @r3
    mov r13, r0
    extu.w r0, r0
    mov.w r0, @(4, r15)
    mov.w @(8, r15), r0
    mov.l   .L_0601CEEC, r3
    mov r0, r1
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    add r4, r1
    jsr @r3
    mov r13, r0
    extu.w r0, r0
    mov.w r0, @(8, r15)
    mov r0, r7
    mov.w @r15, r4
    extu.w r7, r5
    mov.w @(4, r15), r0
    shll8 r5
    mov r0, r6
    shll2 r5
    extu.w r6, r3
    shll2 r3
    shll2 r3
    shll r3
    add r3, r5
    extu.w r4, r2
    add r2, r5
    extu.w r5, r5
    mov.l @(16, r15), r2
    add #0x2, r2
    mov.l r2, @(16, r15)
    add #-0x2, r2
    mov.w r5, @r2
    add #0x1, r9
.L_0601CEB4:
    mov #0x20, r3
    cmp/ge r3, r9
    bf      .L_0601CE2C
    mov #0x20, r6
    mov.l   .L_0601CEF0, r4
    mov.l   .L_0601CEF4, r3
    jsr @r3
    mov r10, r5
    mov #0x20, r6
    mov r10, r5
    mov.l   .L_0601CEF8, r4
    mov.l   .L_0601CEF4, r3
    jsr @r3
    add #0x20, r5
.L_0601CED0:
    mov.l @r12, r2
    add #0x1, r2
    mov.l r2, @r12
    add #0x54, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601CEEC:
    .4byte  sym_06034FE0
.L_0601CEF0:
    .4byte  0x25F00200
.L_0601CEF4:
    .4byte  FUN_0602766C
.L_0601CEF8:
    .4byte  0x25F00400

    .global FUN_0601CEFC
    .type FUN_0601CEFC, @function
FUN_0601CEFC:
    mov.l r14, @-r15
    mov #0x12, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x58, r15
    mov r15, r10
    mov.l   .L_0601CF38, r13
    add #0x18, r10
    mov.l @r13, r3
    cmp/ge r2, r3
    bt/s    .L_0601CFEA
    mov #0x64, r12
    mov.l @r13, r14
    shll r14
    mov.l   .L_0601CF3C, r3
    add r3, r14
    mov.w @r14, r14
    mov r12, r2
    sub r14, r2
    mov.l r2, @(16, r15)
    mov.l   .L_0601CF40, r1
    mov.l r1, @(12, r15)
    mov r10, r1
    mov.l r1, @(20, r15)
    bra     .L_0601CFCE
    mov #0x0, r11
.L_0601CF38:
    .4byte  sym_06086020
.L_0601CF3C:
    .4byte  sym_0605DF58
.L_0601CF40:
    .4byte  0x25F00000
.L_0601CF44:
    mov r15, r7
    mov r15, r6
    mov r15, r5
    mov.l @(12, r15), r4
    add #0x8, r7
    add #0x4, r6
    add #0x2, r4
    mov.l r4, @(12, r15)
    add #-0x2, r4
    mov.w @r4, r4
    bsr     .L_0601D0BC
    extu.w r4, r4
    mov.w @r15, r1
    mov #0x1D, r3
    mov.l @(16, r15), r4
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    mul.l r3, r4
    mov.l   .L_0601D004, r3
    sts macl, r4
    add r4, r1
    jsr @r3
    mov r12, r0
    extu.w r0, r0
    mov.w r0, @r15
    mov.w @(4, r15), r0
    mov.l   .L_0601D004, r3
    mov r0, r1
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    add r4, r1
    jsr @r3
    mov r12, r0
    extu.w r0, r0
    mov.w r0, @(4, r15)
    mov.w @(8, r15), r0
    mov.l   .L_0601D004, r3
    mov r0, r1
    extu.w r1, r1
    mul.l r14, r1
    sts macl, r1
    add r4, r1
    jsr @r3
    mov r12, r0
    extu.w r0, r0
    mov r0, r7
    mov.w r0, @(8, r15)
    extu.w r7, r6
    mov.w @(4, r15), r0
    mov.w @r15, r5
    shll8 r6
    mov r0, r4
    shll2 r6
    extu.w r4, r3
    shll2 r3
    shll2 r3
    shll r3
    add r3, r6
    extu.w r5, r2
    add r2, r6
    extu.w r6, r6
    mov.l @(20, r15), r2
    add #0x2, r2
    mov.l r2, @(20, r15)
    add #-0x2, r2
    mov.w r6, @r2
    add #0x1, r11
.L_0601CFCE:
    mov #0x20, r3
    cmp/ge r3, r11
    bf      .L_0601CF44
    mov #0x20, r6
    mov.l   .L_0601D008, r4
    mov.l   .L_0601D00C, r3
    jsr @r3
    mov r10, r5
    mov #0x20, r6
    mov r10, r5
    mov.l   .L_0601D010, r4
    mov.l   .L_0601D00C, r3
    jsr @r3
    add #0x20, r5
.L_0601CFEA:
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    add #0x58, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601D004:
    .4byte  sym_06034FE0
.L_0601D008:
    .4byte  0x25F00200
.L_0601D00C:
    .4byte  FUN_0602766C
.L_0601D010:
    .4byte  0x25F00400

    .global FUN_0601D014
    .type FUN_0601D014, @function
FUN_0601D014:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601D058, r5
    mov.l   .L_0601D05C, r4
    mov.l   .L_0601D060, r3
    jsr @r3
    mov #0x40, r6
    mov.l   .L_0601D064, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601D056, r6
    mov.l   .L_0601D068, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    mov.l   .L_0601D06C, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601D056, r6
    mov.l   .L_0601D068, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x0, r4
    mov #0x0, r2
    mov.l   .L_0601D070, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_0601D056:
    .2byte  0x0518
.L_0601D058:
    .4byte  sym_0604884C
.L_0601D05C:
    .4byte  0x25F00000
.L_0601D060:
    .4byte  FUN_0602766C
.L_0601D064:
    .4byte  sym_06063968
.L_0601D068:
    .4byte  sym_06028400
.L_0601D06C:
    .4byte  sym_06063970
.L_0601D070:
    .4byte  sym_06086020

    .global FUN_0601D074
    .type FUN_0601D074, @function
FUN_0601D074:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601D0F4, r3
    jsr @r3
    mov #0x4, r4
    mov.l   .L_0601D0F8, r5
    mov.l   .L_0601D0FC, r4
    mov.l   .L_0601D100, r3
    jsr @r3
    mov #0x40, r6
    mov.l   .L_0601D104, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601D0F2, r6
    mov.l   .L_0601D108, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    mov.l   .L_0601D10C, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601D0F2, r6
    mov.l   .L_0601D108, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x0, r4
    mov #0x0, r2
    mov.l   .L_0601D110, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_0601D0BC:
    mov #0x1F, r1
    extu.w r4, r0
    mov r0, r3
    mov r0, r2
    and r1, r3
    shar r2
    shar r0
    mov.w r3, @r5
    shar r2
    shar r0
    shar r2
    shar r0
    shar r2
    shar r0
    shar r2
    shar r0
    and r1, r2
    shar r0
    mov.w r2, @r6
    shar r0
    shar r0
    shar r0
    shar r0
    and r1, r0
    extu.w r0, r0
    rts
    mov.w r0, @r7
.L_0601D0F2:
    .2byte  0x0518
.L_0601D0F4:
    .4byte  sym_0602853E
.L_0601D0F8:
    .4byte  sym_0605D17C
.L_0601D0FC:
    .4byte  0x25F00000
.L_0601D100:
    .4byte  FUN_0602766C
.L_0601D104:
    .4byte  sym_06063CF8
.L_0601D108:
    .4byte  sym_06028400
.L_0601D10C:
    .4byte  sym_06063D00
.L_0601D110:
    .4byte  sym_06086020
    .4byte  0x606D635D
    .4byte  0x624D4018
    .4byte  0x43084008
    .4byte  0x43084300
    .4byte  0x303C302C
    .4byte  0x000B600D

    .global FUN_0601D12C
    .type FUN_0601D12C, @function
FUN_0601D12C:
    mov.l r14, @-r15
    mov.l   .L_0601D190, r14
    mov.l @r14, r4
    mov r4, r0
    tst r0, r0
    bf      .L_0601D150
    mov.l   .L_0601D194, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d18c, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D150
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D150:
    mov.l @r14, r0
    cmp/eq #0x1, r0
    bf      .L_0601D16E
    mov.l   .L_0601D194, r3
    mov.w @r3, r2
    mov.w   DAT_0601d18c, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D16E
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D16E:
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bf      .L_0601D198
    mov.l   .L_0601D194, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d18e, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D198
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop

    .global DAT_0601d18c
DAT_0601d18c:
    .2byte  0x1000

    .global DAT_0601d18e
DAT_0601d18e:
    .2byte  0x2000
.L_0601D190:
    .4byte  sym_0608602C
.L_0601D194:
    .4byte  sym_06063D9A
.L_0601D198:
    mov.l @r14, r0
    cmp/eq #0x3, r0
    bf      .L_0601D1B6
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    mov.w   DAT_0601d24c, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D1B6
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D1B6:
    mov.l @r14, r0
    cmp/eq #0x4, r0
    bf      .L_0601D1D4
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d24e, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D1D4
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D1D4:
    mov.l @r14, r0
    cmp/eq #0x5, r0
    bf      .L_0601D1F2
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    mov.l   .L_0601D258, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D1F2
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D1F2:
    mov.l @r14, r0
    cmp/eq #0x6, r0
    bf      .L_0601D210
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d24e, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D210
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D210:
    mov.l @r14, r0
    cmp/eq #0x7, r0
    bf      .L_0601D22E
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    mov.l   .L_0601D258, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D22E
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D22E:
    mov.l @r14, r0
    cmp/eq #0x8, r0
    bf      .L_0601D25C
    mov.l   .L_0601D254, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_0601D250, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D25C
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop

    .global DAT_0601d24c
DAT_0601d24c:
    .2byte  0x2000

    .global DAT_0601d24e
DAT_0601d24e:
    .2byte  0x4000
.L_0601D250:
    .2byte  0x0400
    .2byte  0xFFFF
.L_0601D254:
    .4byte  sym_06063D9A
.L_0601D258:
    .4byte  0x00008000
.L_0601D25C:
    mov.l @r14, r0
    cmp/eq #0x9, r0
    bf      .L_0601D27A
    mov.l   .L_0601D2CC, r3
    mov.w @r3, r2
    mov.w   DAT_0601d2c6, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D27A
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_0601D294
    nop
.L_0601D27A:
    mov.l @r14, r0
    cmp/eq #0xA, r0
    bf      .L_0601D294
    mov.l   .L_0601D2CC, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_0601D2C8, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601D294
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
.L_0601D294:
    mov.l @r14, r2
    cmp/eq r4, r2
    bf      .L_0601D2A8
    mov.l   .L_0601D2CC, r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0601D2A8
    mov #0x0, r3
    mov.l r3, @r14
.L_0601D2A8:
    mov.l @r14, r0
    cmp/eq #0xB, r0
    bf      .L_0601D2C2
    mov #0x1, r3
    mov.l   .L_0601D2D0, r2
    mov.b r3, @r2
    mov #0x0, r3
    mov.l r3, @r14
    mov.l   .L_0601D2D4, r5
    mov r3, r4
    mov.l   .L_0601D2D8, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601D2C2:
    rts
    mov.l @r15+, r14

    .global DAT_0601d2c6
DAT_0601d2c6:
    .2byte  0x0100
.L_0601D2C8:
    .2byte  0x0200
    .2byte  0xFFFF
.L_0601D2CC:
    .4byte  sym_06063D9A
.L_0601D2D0:
    .4byte  sym_06086030
.L_0601D2D4:
    .4byte  0xAE1146FF
.L_0601D2D8:
    .4byte  FUN_0601D5F4              /* sound command dispatch function */
