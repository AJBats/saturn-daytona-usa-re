
    .section .text.FUN_0600FFD0


    .global FUN_0600FFD0
    .type FUN_0600FFD0, @function
FUN_0600FFD0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_06010042, r9
    mov #0x3, r10
    mov.l   .L_pool_06010048, r11
    mov #0x4, r12
    mov.l   .L_pool_0601004C, r14
    mov #0x0, r13
.L_0600FFEA:
    mov.b @r14, r3
    extu.b r3, r3
    cmp/ge r12, r3
    bsr     FUN_060100A4
    mov r13, r4
    add #0x1, r13
    extu.b r13, r2
    cmp/ge r10, r2
    bf      .L_0600FFEA
    mov.l   .L_pool_06010050, r4
    mov.l   .L_pool_06010054, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0601005C
    mov.l @r4, r0
    tst r0, r0
    bt      .L_06010012
    mov.l @r4, r3
    add #-0x1, r3
    mov.l r3, @r4
.L_06010012:
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r12, r4
    bf      .L_06010020
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_06010094
.L_06010020:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_06010032
    mov.l   .L_pool_06010058, r7
    mov r9, r6
    mov.w   DAT_06010044, r5
    bra     .L_0601003A
    mov #0xC, r4
.L_06010032:
    mov.l   .L_pool_06010058, r7
    mov r9, r6
    mov.w   DAT_06010046, r5
    mov #0x8, r4
.L_0601003A:
    jsr @r11
    nop
    bra     .L_06010094
    nop
.L_wpool_06010042:
    .2byte  0x0090

    .global DAT_06010044
DAT_06010044:
    .2byte  0x06A2

    .global DAT_06010046
DAT_06010046:
    .2byte  0x0B22
.L_pool_06010048:
    .4byte  sym_060284AE
.L_pool_0601004C:
    .4byte  sym_0607887F
.L_pool_06010050:
    .4byte  sym_0605AA98
.L_pool_06010054:
    .4byte  sym_06078663
.L_pool_06010058:
    .4byte  sym_0605ACE4
.L_0601005C:
    mov.l @r4, r0
    cmp/eq #0xC, r0
    bt      .L_06010068
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_06010068:
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r12, r4
    bf      .L_06010076
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_06010094
.L_06010076:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_06010088
    .byte   0xD7, 0x1F    /* mov.l .L_pool_060100FC, r7 */
    mov r9, r6
    .byte   0x95, 0x36    /* mov.w .L_wpool_060100F2, r5 */
    bra     .L_06010090
    mov #0xC, r4
.L_06010088:
    .byte   0xD7, 0x1C    /* mov.l .L_pool_060100FC, r7 */
    mov r9, r6
    .byte   0x95, 0x32    /* mov.w .L_wpool_060100F4, r5 */
    mov #0x8, r4
.L_06010090:
    jsr @r11
    nop
.L_06010094:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_060100A4
    .type FUN_060100A4, @function
FUN_060100A4:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r3
    extu.b r14, r4
    extu.b r14, r1
    mov.l r12, @-r15
    shll2 r4
    mov.l r11, @-r15
    shll2 r4
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l r3, @r15
    mov.w   DAT_060100f6, r2
    add r2, r3
    extu.w r3, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_06010100, r2
    mov.w   DAT_060100f8, r12
    mov.l   .L_06010104, r13
    mov.l   .L_06010108, r0
    add r2, r4
    mov.l @r0, r0
    mov.l @r4, r10
    cmp/eq r0, r1
    bt/s    .L_06010110
    mov.l @(4, r4), r11
    mov.l @r15, r5
    add #0x3, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_0601010C, r3
    add r3, r5
    bra     .L_0601011E
    mov #0x20, r6

    .global DAT_060100f2
DAT_060100f2:
    .word 0x06A2

    .global DAT_060100f4
DAT_060100f4:
    stc vbr, r11

    .global DAT_060100f6
DAT_060100f6:
    .2byte  0x0101
    .global DAT_060100f8
DAT_060100f8:
    .2byte  0x8000
    .2byte  0xFFFF
    .4byte  sym_0605AB19
.L_06010100:
    .4byte  sym_060447C8
.L_06010104:
    .4byte  0x00010000
.L_06010108:
    .4byte  sym_0607EAD8
.L_0601010C:
    .4byte  sym_0605D0BC
.L_06010110:
    mov #0x20, r6
    extu.b r14, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_060101B4, r3
    add r3, r5
.L_0601011E:
    extu.b r14, r4
    mov.l   .L_060101B8, r2
    mov.l   .L_060101BC, r1
    shll2 r4
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l   .L_060101C0, r3
    mov #0x4, r2
    mov.b @r3, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_060101EE
    extu.b r14, r2
    mov.l   .L_060101C8, r3
    mov.l   .L_060101C4, r5
    mov.l @r3, r3
    cmp/eq r3, r2
    bf/s    .L_060101A2
    mov #0x1E, r4
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_06010160
    extu.b r14, r0
    shll r0
    mov #0x20, r3
    mov.w r3, @(r0, r5)
    mov r3, r4
    bra     .L_0601016A
    nop
.L_06010160:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
.L_0601016A:
    mov r14, r5
    mov r14, r3
    mov.l   .L_060101CC, r2
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    exts.b r5, r5
    extu.w r4, r3
    add r2, r5
    mov.l @r5, r1
    mul.l r3, r1
    mov.l @(4, r5), r1
    sts macl, r3
    add r3, r10
    extu.w r4, r3
    mul.l r3, r1
    sts macl, r3
    add r3, r11
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   DAT_060101b2, r1
    bra     .L_060101EA
    mul.l r1, r4
.L_060101A2:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_060101D0
    bra     .L_06010226
    nop

    .global DAT_060101b2
DAT_060101b2:
    .2byte  0x020C
.L_060101B4:
    .4byte  sym_0605D0BC
.L_060101B8:
    .4byte  sym_06078888
.L_060101BC:
    .4byte  FUN_0602766C
.L_060101C0:
    .4byte  sym_0607887F
.L_060101C4:
    .4byte  sym_06078870
.L_060101C8:
    .4byte  sym_0607EAD8
.L_060101CC:
    .4byte  sym_060447F8
.L_060101D0:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   .L_06010274, r2
    mul.l r2, r4
.L_060101EA:
    sts macl, r4
    sub r4, r13
.L_060101EE:
    mov #0xC, r2
    mov.l   .L_0601027C, r3
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_060101FC
    mov.l   .L_06010280, r11
.L_060101FC:
    mov.l   .L_06010284, r2
    mov r11, r5
    mov.l   .L_06010288, r3
    mov.l @r2, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r1
    mov.l r1, @r15
    mov.w @(4, r15), r0
    mov r0, r2
    mov.l r2, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_0601028C, r7
    mov.l @(12, r15), r6
    mov.l   .L_06010290, r2
    shlr r6
    shll16 r6
    jsr @r2
    mov r10, r4
    add #0xC, r15
.L_06010226:
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .global FUN_06010238
FUN_06010238:
    .2byte 0xD416
    .2byte 0xE200
    .4byte  0xD016D317
    .4byte  0x6001600D
    .4byte  0x2422203A
    .4byte  0x9215C9FF
    .4byte  0x650D3527
    .4byte  0x8B026242
    .4byte  0x72012422
    .4byte  0x655D930D
    .4byte  0x35378B02
    .4byte  0x63427301
    .4byte  0x24326242
    .4byte  0xD30D2320
    .4byte  0x6142D30D
    .4byte  0x000B2312
.L_06010274:
    .2byte  0x072B
    .2byte  0x0080
    .4byte  0x00C0FFFF
.L_0601027C:
    .4byte  sym_0607887F
.L_06010280:
    .4byte  0x00960000
.L_06010284:
    .4byte  sym_0605AA98
.L_06010288:
    .4byte  sym_06044844
.L_0601028C:
    .4byte  0x00200000
.L_06010290:
    .4byte  FUN_06011AF4
    .4byte  sym_0607EADC
    .4byte  sym_06063D9C
    .4byte  0x0000FFFF
    .4byte  sym_0607887E
    .4byte  sym_0607EAD8
    .global FUN_060102A8
FUN_060102A8:
    .2byte 0xD519
    .2byte 0x634D
    .4byte  0xD2192329
    .4byte  0x23388907
    .4byte  0xE202D316
    .4byte  0x63323323
    .4byte  0x89026252
    .4byte  0x72012522
    .4byte  0x644D9320
    .4byte  0x24392448
    .4byte  0x8906D310
    .4byte  0x63324315
    .4byte  0x8B026352
    .4byte  0x73FF2532
    .4byte  0x6252D30E
    .4byte  0x23206152
    .4byte  0xD30D000B
    .2byte 0x2312
    .global FUN_060102EA
FUN_060102EA:
    .2byte 0x624D
