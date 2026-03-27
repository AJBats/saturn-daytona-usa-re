
    .section .text.FUN_060414D0


    .global FUN_060414D0
    .type FUN_060414D0, @function
FUN_060414D0:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06041560, r14
    mov.w   DAT_0604155c, r0
    mov.w   DAT_0604155e, r7
    mov.l @r14, r1
    cmp/eq r7, r4
    bt/s    .L_060414F4
    mov.l @(r0, r1), r1
    mov r4, r0
    cmp/eq #-0x2, r0
    bt      .L_060414F4
    cmp/pz r4
    bf      .L_06041512
    mov #0x18, r2
    cmp/ge r2, r4
    bt      .L_06041512
.L_060414F4:
    cmp/pz r5
    bf      .L_06041512
    mov #0x18, r3
    cmp/ge r3, r5
    bt      .L_06041512
    cmp/eq r7, r6
    bt      .L_0604151C
    mov r6, r0
    cmp/eq #-0x2, r0
    bt      .L_0604151C
    cmp/pz r6
    bf      .L_06041512
    mov #0x18, r2
    cmp/ge r2, r6
    bf      .L_0604151C
.L_06041512:
    mov #-0x6, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0604151C:
    cmp/eq r7, r4
    bt      .L_06041532
    mov r4, r0
    cmp/eq #-0x2, r0
    bt      .L_06041532
    mov.l   .L_pool_06041560, r0
    mov.l @r0, r0
    add #0x18, r0
    mov.b @(r0, r4), r0
    cmp/eq #0x1, r0
    bf      .L_06041552
.L_06041532:
    cmp/eq r7, r6
    bt      .L_06041548
    mov r6, r0
    cmp/eq #-0x2, r0
    bt      .L_06041548
    mov.l   .L_pool_06041560, r0
    mov.l @r0, r0
    add #0x18, r0
    mov.b @(r0, r6), r0
    cmp/eq #0x1, r0
    bf      .L_06041552
.L_06041548:
    mov.l   .L_pool_06041560, r0
    mov.l @r0, r0
    mov.b @(r0, r5), r0
    cmp/eq #0x1, r0
    bt      .L_06041564
.L_06041552:
    mov #-0x7, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0604155c
DAT_0604155c:
    .2byte  0x01DC

    .global DAT_0604155e
DAT_0604155e:
    .2byte  0x00FF
.L_pool_06041560:
    .4byte  sym_060A5400
.L_06041564:
    mov #0x18, r2
    cmp/ge r2, r1
    bf      .L_06041574
    mov #-0x8, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06041574:
    mov.l @r14, r2
    .byte   0x90, 0x39    /* mov.w .L_wpool_060415EC, r0 */
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_06041586
    mov.l @r14, r3
    mov #0x1, r2
    .byte   0x90, 0x33    /* mov.w .L_wpool_060415EC, r0 */
    mov.l r2, @(r0, r3)
.L_06041586:
    exts.w r1, r7
    mov.l @r14, r3
    mov r7, r2
    shll2 r7
    shll2 r2
    shll r2
    add r2, r7
    exts.w r7, r7
    mov.w   DAT_060415ee, r2
    add r2, r3
    add r7, r3
    mov.l r4, @r3
    mov.l @r14, r3
    add r3, r2
    add r7, r2
    mov.l r5, @(4, r2)
    mov.l @r14, r3
    mov.w   DAT_060415ee, r2
    add r3, r2
    add r2, r7
    mov.l r6, @(8, r7)
    mov.l @r14, r3
    .byte   0x90, 0x1D    /* mov.w .L_wpool_060415F0, r0 */
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    .reloc ., R_SH_IND12W, FUN_06042134 - 4
    .2byte 0xB000    /* bsr FUN_06042134 (linker-resolved) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_060415C8
    .type FUN_060415C8, @function
FUN_060415C8:
    sts.l pr, @-r15
    add #-0x20, r15
    mov.l r4, @(8, r15)
    mov r15, r6
    mov.l r5, @(16, r15)
    add #0xC, r6
    mov r15, r5
    mov.l   .L_pool_060415F4, r3
    add #0x4, r5
    jsr @r3
    mov r15, r4
    mov r0, r4
    tst r4, r4
    bt      .L_060415F8
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
    .2byte  0x01E0

    .global DAT_060415ee
DAT_060415ee:
    mov.b r14, @(r0, r1)
    mov.b @(r0, r13), r1
    .word 0xFFFF
.L_pool_060415F4:
    .4byte  FUN_06036A98
.L_060415F8:
    mov.l @r15, r0
    cmp/eq #0x2, r0
    bf      .L_0604160A
    mov.l @r15, r2
    mov.l @(4, r15), r3
    mov.l @(8, r15), r1
    add r3, r2
    cmp/ge r2, r1
    bf      .L_06041612
.L_0604160A:
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
.L_06041612:
    mov.l @(16, r15), r5
    .byte   0xD3, 0x14    /* mov.l .L_pool_06041668, r3 */
    jsr @r3
    mov.l @(8, r15), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041628
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
.L_06041628:
    mov r15, r4
    .byte   0xD3, 0x10    /* mov.l .L_pool_0604166C, r3 */
    jsr @r3
    add #0x14, r4
    .byte   0xD2, 0x0F    /* mov.l .L_pool_06041670, r2 */
    mov.l @r2, r2
    mov r15, r3
    add #0x14, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0x20, r15
    lds.l @r15+, pr
    rts
    nop

    .global FUN_06041648
    .type FUN_06041648, @function
FUN_06041648:
    sts.l pr, @-r15
    add #-0x18, r15
    mov r15, r6
    mov r15, r5
    mov r15, r4
    mov.l   .L_06041674, r3
    add #0x8, r5
    jsr @r3
    add #0x4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041678
    add #0x18, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
    .4byte  FUN_06036AF2
    .4byte  FUN_060349B6
    .4byte  sym_060A5400
.L_06041674:
    .4byte  FUN_06036518
.L_06041678:
    mov r15, r4
    .byte   0xD3, 0x2C    /* mov.l .L_pool_0604172C, r3 */
    jsr @r3
    add #0xC, r4
    mov.l   .L_06041730, r2
    mov.l @r2, r2
    mov r15, r3
    add #0xC, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r15, r0
    add #0x18, r15
    lds.l @r15+, pr
    rts
    nop

    .global FUN_06041698
    .type FUN_06041698, @function
FUN_06041698:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov #0x1E, r10

    .global FUN_060416A8
    .type FUN_060416A8, @function
FUN_060416A8:
    sts.l pr, @-r15
    mov #0x0, r9
    add #-0x14, r15
    mov.l   .L_06041730, r13
    mov.l r9, @r15
    mov.l @r13, r3
    mov.l @(60, r3), r0
    tst r0, r0
    bt/s    .L_060416D0
    mov r9, r12
    mov.l @r13, r3
    mov.l @(60, r3), r2
    add #-0x1, r2
    mov.l r2, @(60, r3)
    cmp/pl r2
    bt      .L_060416D0
    .reloc ., R_SH_IND12W, FUN_0604231E - 4
    .2byte 0xB000    /* bsr FUN_0604231E (linker-resolved) */
    nop
    bra     .L_06041796
    mov #0x3, r0
.L_060416D0:
    mov.w   .L_0604172A, r2
    mov.l   .L_06041734, r3
    jsr @r3
    mov.l r2, @(4, r15)
    mov r0, r4
    mov.l @(4, r15), r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_060416E8
    bra     .L_060416EA
    mov #0x1, r5
.L_060416E8:
    mov #0x0, r5
.L_060416EA:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_06041748
    mov.l   .L_06041738, r4
    mov.l   .L_0604173C, r3
    jsr @r3
    nop
    mov r15, r4
    mov.l   .L_06041740, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov.l   .L_06041744, r3
    mov.l @r13, r1
    add #0x8, r2
    add #0x40, r1
    jsr @r3
    mov #0xC, r0
    mov.l @r13, r2
    mov #0x4C, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_06041764
    mov.l @r13, r3
    mov #0x4C, r0
    mov r3, r4
    mov.l @(r0, r3), r2
    mov #0x50, r0
    jsr @r2
    mov.l @(r0, r4), r4
    bra     .L_06041764
    nop
.L_0604172A:
    .2byte  0x0400
    .4byte  FUN_060349B6
.L_06041730:
    .4byte  sym_060A5400
.L_06041734:
    .4byte  sym_06035C4E
.L_06041738:
    .4byte  0x0000FBFF
.L_0604173C:
    .4byte  FUN_06035C54
.L_06041740:
    .4byte  FUN_06034984
.L_06041744:
    .4byte  sym_06035168
.L_06041748:
    mov r15, r4
    mov.l   .L_060417E4, r3
    jsr @r3
    add #0x8, r4
    mov r0, r4
    tst r4, r4
    bf      .L_06041764
    mov.l @r13, r1
    mov r15, r2
    mov.l   .L_060417E8, r3
    add #0x40, r1
    add #0x8, r2
    jsr @r3
    mov #0xC, r0
.L_06041764:
    bra     .L_06041788
    mov r9, r14
.L_06041768:
    bsr     .L_060417A8
    mov r14, r4
    tst r0, r0
    bt      .L_06041774
    bra     .L_06041786
    nop
.L_06041774:
    mov r15, r5
    bsr     FUN_06041826
    mov r14, r4
    add r0, r12
    mov.l @r15, r2
    cmp/gt r10, r2
    bf      .L_06041786
    bra     .L_06041796
    mov #0x1, r0
.L_06041786:
    add #0x1, r14
.L_06041788:
    cmp/ge r11, r14
    bf      .L_06041768
    cmp/pl r12
    bf      .L_06041794
    bra     .L_06041796
    mov #0x1, r0
.L_06041794:
    mov #0x0, r0
.L_06041796:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_060417A8:
    mov.l   .L_060417EC, r5
    bra     .L_060417F8
    mov r4, r0
.L_060417AE:
    mov.l @r5, r4
    bra     .L_060417F4
    mov #0x58, r0
.L_060417B4:
    mov.w   DAT_060417d8, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417BA:
    mov.w   DAT_060417da, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417C0:
    mov.w   .L_060417DC, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417C6:
    mov.w   .L_060417DE, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417CC:
    mov.w   .L_060417E0, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417D2:
    mov.w   .L_060417E2, r0
    bra     .L_060417F4
    mov.l @r5, r4

    .global DAT_060417d8
DAT_060417d8:
    .2byte  0x0304

    .global DAT_060417da
DAT_060417da:
    .2byte  0x030C
.L_060417DC:
    .2byte  0x0328
.L_060417DE:
    .2byte  0x0338
.L_060417E0:
    .2byte  0x0348
.L_060417E2:
    .2byte  0x01E0
.L_060417E4:
    .4byte  FUN_060349C4
.L_060417E8:
    .4byte  sym_06035168
.L_060417EC:
    .4byte  sym_060A5400
.L_060417F0:
    mov.l @r5, r4
    .byte   0x90, 0x34    /* mov.w .L_wpool_0604185E, r0 */
.L_060417F4:
    bra     .L_06041818
    mov.l @(r0, r4), r4
.L_060417F8:
    cmp/eq #0x0, r0
    bt      .L_060417AE
    cmp/eq #0x1, r0
    bt      .L_060417B4
    cmp/eq #0x2, r0
    bt      .L_060417BA
    cmp/eq #0x3, r0
    bt      .L_060417C0
    cmp/eq #0x4, r0
    bt      .L_060417C6
    cmp/eq #0x5, r0
    bt      .L_060417CC
    cmp/eq #0x6, r0
    bt      .L_060417D2
    cmp/eq #0x7, r0
    bt      .L_060417F0
.L_06041818:
    tst r4, r4
    bf      .L_06041820
    bra     .L_06041822
    mov #0x1, r0
.L_06041820:
    mov #0x0, r0
.L_06041822:
    rts
    nop


    .global FUN_06041826
    .type FUN_06041826, @function
FUN_06041826:
    mov.l r14, @-r15
    mov r5, r14
    bra     .L_06041860
    mov r4, r0
.L_0604182E:
    mov r14, r4
    bra     FUN_060418BE
    mov.l @r15+, r14
.L_06041834:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041AA0 - 4
    .2byte 0xA000    /* bra FUN_06041AA0 (linker-resolved) */
    mov.l @r15+, r14
.L_0604183A:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041B3C - 4
    .2byte 0xA000    /* bra FUN_06041B3C (linker-resolved) */
    mov.l @r15+, r14
.L_06041840:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041CC8 - 4
    .2byte 0xA000    /* bra FUN_06041CC8 (linker-resolved) */
    mov.l @r15+, r14
.L_06041846:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041D6C - 4
    .2byte 0xA000    /* bra FUN_06041D6C (linker-resolved) */
    mov.l @r15+, r14
.L_0604184C:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041EE8 - 4
    .2byte 0xA000    /* bra FUN_06041EE8 (linker-resolved) */
    mov.l @r15+, r14
.L_06041852:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06042134 - 4
    .2byte 0xA000    /* bra FUN_06042134 (linker-resolved) */
    mov.l @r15+, r14
.L_06041858:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06042088 - 4
    .2byte 0xA000    /* bra FUN_06042088 (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0x0360
.L_06041860:
    cmp/eq #0x0, r0
    bt      .L_0604182E
    cmp/eq #0x1, r0
    bt      .L_06041834
    cmp/eq #0x2, r0
    bt      .L_0604183A
    cmp/eq #0x3, r0
    bt      .L_06041840
    cmp/eq #0x4, r0
    bt      .L_06041846
    cmp/eq #0x5, r0
    bt      .L_0604184C
    cmp/eq #0x6, r0
    bt      .L_06041852
    cmp/eq #0x7, r0
    bt      .L_06041858
    rts
    mov.l @r15+, r14

    .global sym_06041884
sym_06041884:
    mov.l   .L_pool_060418A8, r3
    mov.l @r3, r3
    rts
    mov.l r4, @(60, r3)

    .global FUN_0604188C
    .type FUN_0604188C, @function
FUN_0604188C:
    sts.l pr, @-r15
    mov.l   .L_pool_060418AC, r4
    mov.l   .L_pool_060418A8, r3
    mov.l @r3, r3
    mov.l r4, @(60, r3)
.L_06041896:
    bsr     FUN_06041698
    nop
    cmp/eq #0x1, r0
    bt/s    .L_060418A4
    mov r0, r4
    bra     .L_060418B0
    nop
.L_060418A4:
    bra     .L_06041896
    nop
.L_pool_060418A8:
    .4byte  sym_060A5400
.L_pool_060418AC:
    .4byte  0x00008000
.L_060418B0:
    mov #0x0, r5
    mov.l   .L_0604195C, r2
    mov.l @r2, r2
    mov.l r5, @(60, r2)
    lds.l @r15+, pr
    rts
    mov r4, r0


    .global FUN_060418BE
    .type FUN_060418BE, @function
FUN_060418BE:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov #0x3, r8
    mov #0x0, r9
    mov #0x1, r11
    mov.l   .L_06041960, r12
    mov.l   .L_0604195C, r14
    mov r4, r10
    bra     .L_060419F6
    mov r9, r13
.L_060418E0:
    mov.l @r14, r0
    mov #0x58, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_0604192E
    mov.l @r14, r5
    mov r13, r3
    add #0x5C, r5
    shll2 r3
    shll2 r3
    add r3, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r4
    mov.l   .L_06041964, r3
    mov r0, r5
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0604190E
    bra     .L_06041A04
    nop
.L_0604190E:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov #0x2, r3
    mov #0x58, r0
    mov.l r3, @(r0, r2)
.L_0604192E:
    mov #0x58, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_060419A6
    mov r13, r3
    mov.l @r14, r5
    shll2 r3
    add #0x5C, r5
    shll2 r3
    add r3, r5
    mov.l r5, @r15
    add #0x2, r5
    mov.l @r15, r4
    mov.l   .L_06041968, r3
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0604196C
    bra     .L_06041A04
    nop
    .2byte  0xFFFF
.L_0604195C:
    .4byte  sym_060A5400
.L_06041960:
    .4byte  FUN_060349B6
.L_06041964:
    .4byte  FUN_06036380
.L_06041968:
    .4byte  FUN_060362A8
.L_0604196C:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov r15, r3
    mov #0x40, r0
    mov.l @r14, r2
    add #0x4, r3
    mov.b @r3, r1
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov r13, r3
    add #0x5C, r2
    shll2 r3
    shll2 r3
    add r2, r3
    mov.l @(12, r3), r0
    tst r0, r0
    bt      .L_060419A0
    mov.l @r14, r3
    mov #0x58, r0
    mov.l r8, @(r0, r3)
    bra     .L_060419A6
    nop
.L_060419A0:
    mov.l @r14, r2
    mov #0x58, r0
    mov.l r11, @(r0, r2)
.L_060419A6:
    mov #0x58, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_060419F4
    mov r13, r3
    mov.l @r14, r6
    shll2 r3
    add #0x5C, r6
    shll2 r3
    add r3, r6
    mov.l r6, @r15
    mov.l @(12, r6), r6
    mov.l @r15, r5
    mov.l @r15, r4
    mov.l   .L_06041A64, r3
    mov.l @(8, r5), r5
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_060419D6
    bra     .L_06041A04
    nop
.L_060419D6:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov #0x58, r0
    mov.l r11, @(r0, r2)
.L_060419F4:
    add #0x1, r13
.L_060419F6:
    mov #0x54, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r2
    cmp/ge r2, r13
    bt      .L_06041A04
    bra     .L_060418E0
    nop
.L_06041A04:
    mov.l @r14, r2
    mov #0x54, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .L_06041A16
    mov.l @r14, r2
    mov #0x54, r0
    bra     .L_06041A48
    mov.l r9, @(r0, r2)
.L_06041A16:
    bra     .L_06041A38
    mov r9, r4
.L_06041A1A:
    mov r4, r1
    mov r13, r2
    mov.l @r14, r5
    mov.l   .L_06041A68, r3
    shll2 r1
    shll2 r2
    add #0x5C, r5
    shll2 r1
    shll2 r2
    add r5, r1
    add r5, r2
    jsr @r3
    mov #0x10, r0
    add #0x1, r13
    add #0x1, r4
.L_06041A38:
    mov.l @r14, r2
    mov #0x54, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .L_06041A1A
    mov.l @r14, r2
    mov #0x54, r0
    mov.l r4, @(r0, r2)
.L_06041A48:
    mov #0x40, r3
    mov.l r3, @r15
    mov.l   .L_06041A6C, r3
    jsr @r3
    nop
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_06041A70
    bra     .L_06041A72
    mov #0x1, r4
    .2byte  0xFFFF
.L_06041A64:
    .4byte  FUN_060361FC
.L_06041A68:
    .4byte  sym_06035168
.L_06041A6C:
    .4byte  sym_06035C4E
.L_06041A70:
    mov #0x0, r4
.L_06041A72:
    tst r4, r4
    bt      .L_06041A86
    mov.l @r14, r3
    mov #0x54, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_06041A86
    mov.l @r14, r3
    mov #0x58, r0
    mov.l r9, @(r0, r3)
.L_06041A86:
    mov #0x54, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
