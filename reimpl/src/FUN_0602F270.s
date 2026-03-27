
    .section .text.FUN_0602F270


    .global FUN_0602F270
    .type FUN_0602F270, @function
FUN_0602F270:
    sts.l pr, @-r15
    mov.w   .L_0602F284, r1
    mov.l @(r0, r1), r3
    tst r3, r3
    bt      .L_0602F298
    cmp/pz r3
    bf      .L_0602F286
    add #-0x1, r3
    bra     .L_0602F298
    mov.l r3, @(r0, r1)
.L_0602F284:
    .2byte  0x00D8
.L_0602F286:
    add #0x1, r3
    mov.l r3, @(r0, r1)
    mov.w   .L_0602F2AC, r2
    mov.w   .L_0602F2AE, r1
    mov.l @(r0, r2), r3
    mov.l r3, @(r0, r1)
    mov.w   .L_0602F2B0, r4
    sub r4, r3
    mov.l r3, @(r0, r2)
.L_0602F298:
    mov.w   .L_0602F2B2, r1
    mov.w @(r0, r1), r2
    mov.w   .L_0602F2B4, r5
    mov.w @(r0, r5), r6
    cmp/eq r2, r6
    bt      .L_0602F34C
    cmp/gt r2, r6
    bt      .L_0602F2B6
    bra     .L_0602F304
    nop
.L_0602F2AC:
    .2byte  0x00C4
.L_0602F2AE:
    .2byte  0x00E0
.L_0602F2B0:
    .2byte  0x00FA
.L_0602F2B2:
    .2byte  0x00DC
.L_0602F2B4:
    .2byte  0x00DE
.L_0602F2B6:
    mov #0x3, r3
    cmp/eq r3, r2
    bt      .L_0602F34C
    mov.w r6, @(r0, r1)
    mov.w   .L_0602F2F8, r3
    mov.l @(r0, r3), r4
    shll16 r4
    mov r2, r5
    mov.l   .L_0602F2FC, r8
    mov r8, r9
    shll2 r5
    add r5, r8
    mov.l @r8, r7
    mov r6, r5
    dmuls.l r7, r4
    shll2 r5
    add r5, r9
    sts mach, r7
    sts macl, r4
    mov.l @r9, r5
    xtrct r7, r4
    mov.l   .L_0602F300, r0
    jsr @r0
    nop
    mov.w   .L_0602F2F8, r3
    shlr16 r0
    mov r0, r4
    mov r14, r0
    mov.l r4, @(r0, r3)
    mov #0x5, r5
    mov.w   .L_0602F2FA, r1
    bra     .L_0602F34C
    mov.l r5, @(r0, r1)
.L_0602F2F8:
    .2byte  0x00E0
.L_0602F2FA:
    .2byte  0x00D8
.L_0602F2FC:
    .4byte  sym_060477BC
.L_0602F300:
    .4byte  FUN_0602755C
.L_0602F304:
    tst r2, r2
    bt      .L_0602F34C
    mov.w r6, @(r0, r1)
    mov.w   .L_0602F388, r3
    mov.l @(r0, r3), r4
    shll16 r4
    mov r2, r5
    mov.l   .L_0602F39C, r8
    mov r8, r9
    shll2 r5
    add r5, r8
    mov.l @r8, r7
    mov r6, r5
    dmuls.l r7, r4
    shll2 r5
    add r5, r9
    sts mach, r7
    sts macl, r4
    mov.l @r9, r5
    xtrct r7, r4
    mov.l   .L_0602F3A0, r0
    jsr @r0
    nop
    mov.w   .L_0602F388, r3
    shlr16 r0
    mov r0, r4
    mov r14, r0
    mov.l r4, @(r0, r3)
    mov.w   .L_0602F38A, r5
    mov.w   .L_0602F38C, r1
    add r5, r4
    mov.l r4, @(r0, r1)
    mov #0x5, r4
    neg r4, r4
    mov.w   .L_0602F38E, r3
    mov.l r4, @(r0, r3)
.L_0602F34C:
    mov.w   .L_0602F390, r3
    mov.w   .L_0602F388, r1
    mov.l @(r0, r1), r4
    cmp/gt r4, r3
    bt      .L_0602F360
    mov #-0x1, r4
    extu.b r4, r4
    mov.w   .L_0602F392, r5
    mov.l r3, @(r0, r1)
    mov.l r4, @(r0, r5)
.L_0602F360:
    mov.w   .L_0602F394, r6
    mov.w   .L_0602F396, r2
    mov.l @(r0, r6), r3
    mov.l @(r0, r1), r4
    mov.l @(r0, r2), r5
    add r5, r4
    sub r3, r4
    mov.w   .L_0602F398, r1
    mov.l   .L_0602F3A4, r7
    mov.w @(r0, r1), r2
    shll2 r2
    shll r2
    add r2, r7
    mov.l @r7, r8
    mov.l @(4, r7), r9
    cmp/gt r8, r4
    bt      .L_0602F3A8
    mov r8, r4
    bra     .L_0602F3AE
    nop
.L_0602F388:
    .2byte  0x00E0
.L_0602F38A:
    .2byte  0x04E2
.L_0602F38C:
    .2byte  0x00C4
.L_0602F38E:
    .2byte  0x00D8
.L_0602F390:
    .2byte  0x2134
.L_0602F392:
    .2byte  0x0084
.L_0602F394:
    .2byte  0x00E4
.L_0602F396:
    .2byte  0x00C0
.L_0602F398:
    .2byte  0x00DC
    .2byte  0x0000
.L_0602F39C:
    .4byte  sym_060477BC
.L_0602F3A0:
    .4byte  FUN_0602755C
.L_0602F3A4:
    .4byte  sym_0602F3CC
.L_0602F3A8:
    cmp/ge r4, r9
    bt      .L_0602F3AE
    mov r9, r4
.L_0602F3AE:
    add r4, r3
    mov #0x0, r8
    mov.w   .L_0602F3BE, r9
    cmp/gt r8, r3
    bt      .L_0602F3C0
    mov r8, r3
    bra     .L_0602F3C6
    nop
.L_0602F3BE:
    .2byte  0x2134
.L_0602F3C0:
    cmp/ge r3, r9
    bt      .L_0602F3C6
    mov r9, r3
.L_0602F3C6:
    lds.l @r15+, pr
    rts
    mov.l r3, @(r0, r6)

    .global sym_0602F3CC
sym_0602F3CC:
    .word 0xFFFF
    .word 0xFB50
    .word 0x0000
    .word 0x04B0
    .word 0xFFFF
    .word 0xFDA8
    .word 0x0000
    .word 0x0258
    .word 0xFFFF
    .word 0xFED4
    .word 0x0000
    mov.b @(r0, r2), r1
    .word 0xFFFF
    .word 0xFED4
    .word 0x0000
    mov.b @(r0, r2), r1

    .global sym_0602F3EC
sym_0602F3EC:
    mov.l @(12, r0), r2
    mov.l   .L_0602F40C, r3
    dmuls.l r2, r3
    mov.l   .L_0602F410, r4
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    shlr16 r2
    exts.w r2, r2
    mov #0x0, r3
    cmp/gt r3, r2
    bt      .L_0602F414
    mov r3, r2
    bra     .L_0602F41A
    nop
    .2byte  0x0000
.L_0602F40C:
    .4byte  0x00480000
.L_0602F410:
    .4byte  0x00000158
.L_0602F414:
    cmp/gt r2, r4
    bt      .L_0602F41A
    mov r4, r2
.L_0602F41A:
    mov.l r2, @(8, r0)
    shll8 r2
    shlr2 r2
    mov.l   .L_0602F42C, r4
    cmp/ge r4, r2
    bt      .L_0602F430
    bra     .L_0602F448
    mov r4, r2
    .2byte  0x0000
.L_0602F42C:
    .4byte  0x00000000
.L_0602F430:
    mov.l   .L_0602F43C, r4
    cmp/ge r2, r4
    bt      .L_0602F440
    bra     .L_0602F448
    mov r4, r2
    .2byte  0x0000
.L_0602F43C:
    .4byte  0x00002AAA
.L_0602F440:
    mov.l   .L_0602F46C, r4
    cmp/ge r2, r4
    bt      .L_0602F448
    mov r4, r2
.L_0602F448:
    mov.w   DAT_0602f464, r3
    mov.l @(r0, r3), r4
    sub r2, r4
    mov.l r4, @(r0, r3)
    mov.w   DAT_0602f466, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_0602F45A
    mov.l   .L_0602F470, r2
.L_0602F45A:
    mov.w   .L_0602F468, r1
    mov.l @(r0, r1), r4
    sub r2, r4
    rts
    mov.l r4, @(r0, r1)

    .global DAT_0602f464
DAT_0602f464:
    .2byte  0x0048

    .global DAT_0602f466
DAT_0602f466:
    .2byte  0x00C0
.L_0602F468:
    .2byte  0x0050
    .2byte  0x0000
.L_0602F46C:
    .4byte  0x00000AAA
.L_0602F470:
    .4byte  0x00002AAA

    .global sym_0602F474
sym_0602F474:
    mov r14, r0
    mov #0x0, r5
    mov.w   DAT_0602f4aa, r1
    mov.w @(r0, r1), r3
    tst r3, r3
    bt      .L_0602F49C
    mov #0x1, r6
    sub r6, r3
    mov.w r3, @(r0, r1)
    cmp/eq r5, r3
    bt      .L_0602F49A
    cmp/eq r6, r3
    bt      .L_0602F498
    mov #0x2, r7
    cmp/eq r7, r3
    bt      .L_0602F496
    add #0x1, r5
.L_0602F496:
    add #0x1, r5
.L_0602F498:
    add #0x1, r5
.L_0602F49A:
    add #0x1, r5
.L_0602F49C:
    mov.l   .L_0602F4B0, r6
    shll2 r5
    add r5, r6
    mov.l @r6, r3
    mov.w   .L_0602F4AC, r1
    rts
    mov.l r3, @(r0, r1)

    .global DAT_0602f4aa
DAT_0602f4aa:
    .2byte  0x00D4
.L_0602F4AC:
    .2byte  0x0114
    .2byte  0x0000
.L_0602F4B0:
    .4byte  sym_060477D8

    .global sym_0602F4B4
sym_0602F4B4:
    mov.l   .L_0602F4C4, r1
    mov.l @r1, r3
    mov #0x1, r6
    tst r3, r3
    bt      .L_0602F4C8
    rts
    nop
    .2byte  0x0000
.L_0602F4C4:
    .4byte  sym_0607EAE0
.L_0602F4C8:
    mov.w   DAT_0602f51a, r1
    mov.w @(r0, r1), r3
    cmp/pl r3
    bf      .L_0602F4D4
    sub r6, r3
    mov.w r3, @(r0, r1)
.L_0602F4D4:
    mov.l   .L_0602F520, r5
    mov.l @r5, r5
    mov.l   .L_0602F524, r3
    mov.l @r3, r6
    mov.w   DAT_0602f51c, r2
    mov.w   DAT_0602f51e, r4
    mov.l @(r0, r2), r7
    mov.l @(r0, r4), r8
    mov.w   DAT_0602f51c, r2
    mov.w   DAT_0602f51e, r4
    mov r2, r9
    add r6, r9
    mov.l @r9, r9
    mov r4, r10
    add r6, r10
    mov.l @r10, r10
    mov.l r0, @-r15
    mov.l r1, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov r7, r1
    sub r9, r1
    cmp/pl r1
    bt      .L_0602F506
    neg r1, r1
.L_0602F506:
    mov r8, r4
    sub r10, r4
    cmp/pl r4
    bt      .L_0602F510
    neg r4, r4
.L_0602F510:
    cmp/ge r4, r1
    bt      .L_0602F528
    shar r1
    bra     .L_0602F52C
    add r1, r4

    .global DAT_0602f51a
DAT_0602f51a:
    .2byte  0x00D6

    .global DAT_0602f51c
DAT_0602f51c:
    .2byte  0x0010

    .global DAT_0602f51e
DAT_0602f51e:
    .2byte  0x0018
.L_0602F520:
    .4byte  sym_0607EA98
.L_0602F524:
    .4byte  sym_0607E948
.L_0602F528:
    shar r4
    add r1, r4
.L_0602F52C:
    mov r4, r2
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r1
    mov.l @r15+, r0
    .byte   0xDC, 0x10    /* mov.l .L_pool_0602F578, r12 */
    cmp/ge r12, r2
    .byte   0x89, 0x35    /* bt 0x0602F5A8 */
    mov.l r1, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l r0, @-r15
    mov r9, r4
    sub r7, r4
    mov r10, r5
    sub r8, r5
    .byte   0xD0, 0x0B    /* mov.l .L_pool_0602F57C, r0 */


    .global FUN_0602F550
    .type FUN_0602F550, @function
FUN_0602F550:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r11
    exts.w r11, r11
    mov.l @r15+, r0
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r1
    mov.l @(40, r0), r12
    sub r12, r11
    mov.l   .L_pool_0602F580, r10
    tst r10, r11
    bt      .L_0602F588
    mov.l   .L_pool_0602F584, r10
    bra     .L_0602F58C
    or r10, r11
    .2byte  0x0000
    .4byte  0x001E0000
    .4byte  FUN_0602744C
.L_pool_0602F580:
    .4byte  0x00008000
.L_pool_0602F584:
    .4byte  0xFFFF0000
.L_0602F588:
    mov.l   .L_pool_0602F5A0, r10
    and r10, r11
.L_0602F58C:
    cmp/pz r11
    bt      .L_0602F592
    neg r11, r11
.L_0602F592:
    mov.l   .L_pool_0602F5A4, r10
    cmp/ge r10, r11
    bt      .L_0602F5A8
    mov #0x14, r12
    bra     .L_0602F5B0
    mov.w r12, @(r0, r1)
    .2byte  0x0000
.L_pool_0602F5A0:
    .4byte  0x0000FFFF
.L_pool_0602F5A4:
    .4byte  0x0000071C
.L_0602F5A8:
    mov.w   DAT_0602f5b4, r11
    add r11, r6
    dt r5
    .byte   0x8B, 0x99    /* bf 0x0602F4E4 (external) */
.L_0602F5B0:
    rts
    nop

    .global DAT_0602f5b4
DAT_0602f5b4:
    .2byte  0x0268


    .global FUN_0602F5B6
    .type FUN_0602F5B6, @function
FUN_0602F5B6:
    sts.l pr, @-r15
    mov r0, r14
    mov.w   DAT_0602f5e8, r1
    mov.l @(r0, r1), r2
    mov.l   .L_pool_0602F5EC, r3
    shll2 r2
    mov.l   .L_pool_0602F5F0, r4
    add r2, r3
    mov.l @r3, r5
    dmuls.l r4, r5
    mov.l   .L_pool_0602F5F4, r1
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    sub r1, r5
    mov r5, r1
    mov.w   DAT_0602f5ea, r11
    mov.l @(r0, r11), r5
    mov.l   .L_pool_0602F5F8, r3
    mov.l   .L_pool_0602F5FC, r4
    cmp/gt r3, r5
    bt      .L_0602F600
    mov r3, r5
    bra     .L_0602F606
    nop

    .global DAT_0602f5e8
DAT_0602f5e8:
    .2byte  0x0068

    .global DAT_0602f5ea
DAT_0602f5ea:
    .2byte  0x00E0
.L_pool_0602F5EC:
    .4byte  sym_06045AEC
.L_pool_0602F5F0:
    .4byte  0x00016666
.L_pool_0602F5F4:
    .4byte  0x00006666
.L_pool_0602F5F8:
    .4byte  0x00000000
.L_pool_0602F5FC:
    .4byte  0x00002134
.L_0602F600:
    cmp/gt r5, r4
    bt      .L_0602F606
    mov r4, r5
.L_0602F606:
    shlr2 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov.w   DAT_0602f6e0, r2
    mov.w @(r0, r2), r4
    mov.w   DAT_0602f6e2, r2
    mov.l @(r0, r2), r6
    shll2 r5
    mov.l   .L_pool_0602F6F8, r7
    shll2 r4
    add r5, r6
    add r4, r7
    mov.l @r6, r5
    mov.l @r7, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    dmuls.l r0, r1
    sts mach, r4
    sts macl, r2
    xtrct r4, r2
    mov r14, r0
    mov.w   DAT_0602f6e4, r1
    mov.l   .L_pool_0602F6FC, r5
    mov.l @(r0, r1), r4
    shll16 r4
    mov.l   .L_pool_0602F700, r0
    jsr @r0
    mov.l r2, @-r15
    mov r0, r4
    mov.l @r15+, r2
    mov r14, r0
    mov.w   DAT_0602f6e6, r1
    sub r4, r2
    mov.l r2, @(r0, r1)
    mov.w   DAT_0602f6e8, r1
    mov.l @(r0, r1), r2
    mov.l   .L_pool_0602F704, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    mov.l   .L_pool_0602F708, r7
    mov.l   .L_pool_0602F70C, r8
    mov r4, r5
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    mov r0, r10
    mov r0, r4
    mov r7, r5
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    mov r10, r4
    mov r0, r10
    dmuls.l r4, r8
    sts mach, r8
    sts macl, r4
    xtrct r8, r4
    mov r14, r0
    mov.w   DAT_0602f6ea, r1
    mov.l r10, @(r0, r1)
    mov.w   DAT_0602f6ec, r2
    mov.l r4, @(r0, r2)
    mov #0x0, r10
    mov.w   DAT_0602f6ee, r1
    mov.l @(r0, r1), r4
    cmp/ge r4, r10
    bt      .L_0602F69A
    shar r4
.L_0602F69A:
    mov.l   .L_pool_0602F710, r5
    mov.l   .L_pool_0602F714, r0
    jsr @r0
    nop
    dmuls.l r0, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    shar r0
    mov r0, r8
    mov.w   DAT_0602f6f0, r1
    mov r14, r0
    mov.l r8, @(r0, r1)
    mov.l @(8, r0), r3
    mov.l   .L_pool_0602F718, r1
    shll2 r3
    add r3, r1
    mov.l @r1, r5
    mov.w   DAT_0602f6f2, r2
    mov.w @(r0, r2), r3
    cmp/pl r3
    bf      .L_0602F6D0
    mov.w   DAT_0602f6f4, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
.L_0602F6D0:
    bsr     .L_0602F71C
    nop
    add r4, r5
    shar r5
    mov.w   DAT_0602f6f6, r1
    lds.l @r15+, pr
    rts
    mov.l r5, @(r0, r1)

    .global DAT_0602f6e0
DAT_0602f6e0:
    .2byte  0x00DC

    .global DAT_0602f6e2
DAT_0602f6e2:
    .2byte  0x00C8

    .global DAT_0602f6e4
DAT_0602f6e4:
    .2byte  0x00E8

    .global DAT_0602f6e6
DAT_0602f6e6:
    .2byte  0x011C

    .global DAT_0602f6e8
DAT_0602f6e8:
    .2byte  0x0084

    .global DAT_0602f6ea
DAT_0602f6ea:
    .2byte  0x00EC

    .global DAT_0602f6ec
DAT_0602f6ec:
    .2byte  0x00F0

    .global DAT_0602f6ee
DAT_0602f6ee:
    .2byte  0x001C

    .global DAT_0602f6f0
DAT_0602f6f0:
    .2byte  0x00F4

    .global DAT_0602f6f2
DAT_0602f6f2:
    .2byte  0x00D6

    .global DAT_0602f6f4
DAT_0602f6f4:
    .2byte  0x7333

    .global DAT_0602f6f6
DAT_0602f6f6:
    .2byte  0x00F8
.L_pool_0602F6F8:
    .4byte  sym_060477BC
.L_pool_0602F6FC:
    .4byte  0x00019999
.L_pool_0602F700:
    .4byte  FUN_0602755C
.L_pool_0602F704:
    .4byte  sym_06045AEC
.L_pool_0602F708:
    .4byte  0x0B400000
.L_pool_0602F70C:
    .4byte  0x07800000
.L_pool_0602F710:
    .4byte  0x06400000
.L_pool_0602F714:
    .4byte  FUN_06027348
.L_pool_0602F718:
    .4byte  sym_060454CC
.L_0602F71C:
    mov #0x0, r4
    mov.w   .L_wpool_0602F786, r3
    mov.w   .L_wpool_0602F788, r1
    add r0, r1
    mov.l @r1, r2
    tst r3, r2
    mov r2, r12
    bt      .L_0602F72E
    add #0x1, r4
.L_0602F72E:
    mov.l @(4, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_0602F738
    add #0x1, r4
.L_0602F738:
    mov.l @(8, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_0602F742
    add #0x1, r4
.L_0602F742:
    mov.l @(12, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_0602F74C
    add #0x1, r4
.L_0602F74C:
    tst r4, r4
    bt      .L_0602F79A
    mov #0x10, r1
    tst r1, r12
    bf      .L_0602F7A4
    mov.w   .L_wpool_0602F78A, r1
    mov.w @(r0, r1), r2
    mov #0xA, r1
    cmp/ge r1, r2
    bt      .L_0602F7A4
    mov #0x8, r1
    cmp/ge r1, r2
    bt      .L_0602F7A8
    mov #0x4, r1
    cmp/eq r1, r2
    bt      .L_0602F7A4
    mov #0x5, r1
    cmp/eq r1, r2
    bt      .L_0602F7A4
    mov #0x2, r7
    cmp/ge r4, r7
    bt      .L_0602F790
    mov.l @(8, r0), r2
    mov.l   .L_pool_0602F78C, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    rts
    shar r4
.L_wpool_0602F786:
    .2byte  0x0004
.L_wpool_0602F788:
    .2byte  0x0120
.L_wpool_0602F78A:
    .2byte  0x007C
.L_pool_0602F78C:
    .4byte  sym_0604679C
.L_0602F790:
    mov.l @(8, r0), r2
    mov.l   .L_pool_0602F7A0, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r4
.L_0602F79A:
    rts
    shar r4
    .2byte  0x0000
.L_pool_0602F7A0:
    .4byte  sym_06046F9C
.L_0602F7A4:
    rts
    mov #0x0, r4
.L_0602F7A8:
    mov.l @(8, r0), r2
    mov.l   .L_pool_0602F7B8, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    rts
    shll r4
    .2byte  0x0000
.L_pool_0602F7B8:
    .4byte  sym_0604679C

    .global sym_0602F7BC
sym_0602F7BC:
    mov.w   DAT_0602f7e4, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_0602F7C8
    add #-0x1, r2
    mov.w r2, @(r0, r1)
.L_0602F7C8:
    mov.w   DAT_0602f7e6, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_0602F7D4
    add #-0x1, r2
    mov.w r2, @(r0, r1)
.L_0602F7D4:
    mov.w   DAT_0602f7e8, r1
    mov.l @(r0, r1), r2
    tst r2, r2
    bt      .L_0602F7E0
    add #-0x1, r2
    mov.l r2, @(r0, r1)
.L_0602F7E0:
    rts
    nop

    .global DAT_0602f7e4
DAT_0602f7e4:
    .2byte  0x0166

    .global DAT_0602f7e6
DAT_0602f7e6:
    .2byte  0x0152

    .global DAT_0602f7e8
DAT_0602f7e8:
    .2byte  0x0208

    .global FUN_0602F7EA
    .type FUN_0602F7EA, @function
FUN_0602F7EA:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .byte   0xDE, 0x15    /* mov.l .L_pool_0602F848, r14 */

    .global FUN_0602F7F2
    .type FUN_0602F7F2, @function
FUN_0602F7F2:
    sts.l pr, @-r15
    mov.l @r14, r14
    mov.l   .L_0602F84C, r12
    mov r14, r0
    mov.l   .L_0602F850, r5
    mov.w   DAT_0602f842, r4
    mov.l @r5, r0
    add r14, r4
    mov.l   .L_0602F854, r1
    mov.l @r4, r4
    shll2 r0
    add r0, r1
    mov.w @r1, r5
    tst r5, r5
    bt      .L_0602F87C
    mov.l   .L_0602F858, r3
    mov.w @(2, r1), r0
    add r0, r3
.L_0602F816:
    mov.w @r3, r1
    cmp/gt r4, r1
    bt      .L_0602F860
    mov.w @(2, r3), r0
    cmp/gt r0, r4
    bt      .L_0602F860
    mov #0x10, r0
    mov.l @(20, r14), r1
    shll16 r0
    cmp/ge r1, r0
    bt      .L_0602F87C
    mov.l @(0, r14), r1
    mov.w   DAT_0602f844, r3
    tst r3, r1
    bf      .L_0602F87C
    or r3, r1
    mov.l r1, @(0, r14)
    mov.l   .L_0602F85C, r5
    jsr @r12
    mov #0x4, r4
    bra     .L_0602F87C
    nop

    .global DAT_0602f842
DAT_0602f842:
    .2byte  0x01EC

    .global DAT_0602f844
DAT_0602f844:
    .2byte  0x4000
    .2byte  0x0000
    .4byte  sym_0607E944
.L_0602F84C:
    .4byte  FUN_0601D5F4
.L_0602F850:
    .4byte  sym_0607EAD8
.L_0602F854:
    .4byte  sym_0602FD3C
.L_0602F858:
    .4byte  sym_0602FD48
.L_0602F85C:
    .4byte  0xAE0601FF
.L_0602F860:
    add #-0x1, r5
    tst r5, r5
    add #0x4, r3
    bf      .L_0602F816
    mov.l @(0, r14), r1
    mov.w   DAT_0602f890, r3
    tst r3, r1
    bt      .L_0602F87C
    not r3, r3
    and r3, r1
    mov.l r1, @(0, r14)
    mov.l   .L_0602F898, r5
    jsr @r12
    mov #0x4, r4
.L_0602F87C:
    mov.w   .L_0602F892, r5
    add r14, r5
    mov.w   .L_0602F894, r3
    mov.l @r5, r1
    mov.w   .L_0602F896, r4
    cmp/gt r3, r1
    bt      .L_0602F89C
    mov r3, r1
    bra     .L_0602F8A2
    nop

    .global DAT_0602f890
DAT_0602f890:
    .2byte  0x4000
.L_0602F892:
    .2byte  0x00E4
.L_0602F894:
    .2byte  0x0708
.L_0602F896:
    .2byte  0x2134
.L_0602F898:
    .4byte  0xAE0600FF
.L_0602F89C:
    cmp/gt r1, r4
    bt      .L_0602F8A2
    mov r4, r1
.L_0602F8A2:
    sub r3, r1
    shll8 r1
    mov.w   .L_0602F8BA, r0
    .reloc ., R_SH_IND12W, FUN_0602ECCC - 4
    .2byte 0xB000    /* bsr FUN_0602ECCC (linker-resolved) */
    shlr r1
    mov #0x7F, r4
    mov #0x1, r3
    cmp/gt r3, r0
    bt      .L_0602F8BC
    mov r3, r0
    bra     .L_0602F8C2
    nop
.L_0602F8BA:
    .2byte  0x14B4
.L_0602F8BC:
    cmp/gt r0, r4
    bt      .L_0602F8C2
    mov r4, r0
.L_0602F8C2:
    mov r0, r5
    jsr @r12
    mov #0x1, r4
    mov.l   .L_0602F8F4, r4
    mov.b @r4, r4
    mov.w   DAT_0602f8f0, r1
    add r14, r1
    mov.l @r1, r0
    tst r0, r0
    bf      .L_0602F910
    mov.w   DAT_0602f8f2, r1
    add r14, r1
    mov.w @r1, r0
    tst r0, r0
    bt      .L_0602F910
    cmp/eq #0xA, r0
    bf      .L_0602F900
    mov.l   .L_0602F8F8, r5
    tst r4, r4
    bt      .L_0602F90C
    mov.l   .L_0602F8FC, r5
    bra     .L_0602F90C
    nop

    .global DAT_0602f8f0
DAT_0602f8f0:
    .2byte  0x01BC

    .global DAT_0602f8f2
DAT_0602f8f2:
    .2byte  0x0166
.L_0602F8F4:
    .4byte  sym_0605D241
.L_0602F8F8:
    .4byte  0xAE111EFF
.L_0602F8FC:
    .4byte  0xAE1142FF
.L_0602F900:
    cmp/eq #0x3, r0
    mov.l   .L_0602F984, r5
    bf      .L_0602F910
    tst r4, r4
    bt      .L_0602F90C
    mov.l   .L_0602F988, r5
.L_0602F90C:
    jsr @r12
    mov #0x0, r4
.L_0602F910:
    mov.l   .L_0602F98C, r4
    mov.b @r4, r1
    mov.w   .L_0602F97E, r3
    add r14, r3
    mov #0x2C, r5
    mov.l @r3, r4
    cmp/eq r4, r5
    bf      .L_0602F92C
    tst r1, r1
    mov.l   .L_0602F990, r5
    bt      .L_0602F928
    mov.l   .L_0602F994, r5
.L_0602F928:
    jsr @r12
    mov #0x0, r4
.L_0602F92C:
    mov.l   .L_0602F998, r3
    mov.b @r3, r0
    tst r0, r0
    bt      .L_0602F93E
    cmp/eq #0x1, r0
    add #-0x1, r0
    mov #0x0, r5
    bt/s    .L_0602F956
    mov.b r0, @r3
.L_0602F93E:
    mov.l @(12, r14), r0
    tst r0, r0
    bt      .L_0602F95A
    mov.w   DAT_0602f980, r0
    mov #-0x38, r4
    mov.l @(r0, r14), r5
    extu.b r4, r4
    cmp/ge r5, r4
    bt      .L_0602F95A
    mov #0xA, r4
    mov.b r4, @r3
    mov #0x1, r5
    .global FUN_0602F956
FUN_0602F956:
.L_0602F956:
    jsr @r12
    mov #0x3, r4
.L_0602F95A:
    mov.w   DAT_0602f982, r0
    mov.l @(r0, r14), r5
    cmp/pz r5
    bt      .L_0602F964
    neg r5, r5
.L_0602F964:
    shlr8 r5
    mov #0x7, r3
    shlr2 r5
    cmp/ge r5, r3
    bt      .L_0602F970
    mov #0x7, r5
.L_0602F970:
    jsr @r12
    mov #0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0602F97E:
    .2byte  0x00B8

    .global DAT_0602f980
DAT_0602f980:
    .2byte  0x0084

    .global DAT_0602f982
DAT_0602f982:
    .2byte  0x005C
.L_0602F984:
    .4byte  0xAE111CFF
.L_0602F988:
    .4byte  0xAE1140FF
.L_0602F98C:
    .4byte  sym_0605D241
.L_0602F990:
    .4byte  0xAE111BFF
.L_0602F994:
    .4byte  0xAE113FFF
.L_0602F998:
    .4byte  sym_0602FD9F
