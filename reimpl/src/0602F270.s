	.text
    .global collision_response_b
collision_response_b:
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
    .short  0x00D8
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
    .short  0x00C4
.L_0602F2AE:
    .short  0x00E0
.L_0602F2B0:
    .short  0x00FA
.L_0602F2B2:
    .short  0x00DC
.L_0602F2B4:
    .short  0x00DE
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
    .short  0x00E0
.L_0602F2FA:
    .short  0x00D8
.L_0602F2FC:
    .long  sym_060477BC
.L_0602F300:
    .long  fpdiv_setup
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
    .short  0x00E0
.L_0602F38A:
    .short  0x04E2
.L_0602F38C:
    .short  0x00C4
.L_0602F38E:
    .short  0x00D8
.L_0602F390:
    .short  0x2134
.L_0602F392:
    .short  0x0084
.L_0602F394:
    .short  0x00E4
.L_0602F396:
    .short  0x00C0
.L_0602F398:
    .short  0x00DC
    .short  0x0000
.L_0602F39C:
    .long  sym_060477BC
.L_0602F3A0:
    .long  fpdiv_setup
.L_0602F3A4:
    .long  sym_0602F3CC
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
    .short  0x2134
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
    .short  0x0000
.L_0602F40C:
    .long  0x00480000
.L_0602F410:
    .long  0x00000158
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
    .short  0x0000
.L_0602F42C:
    .long  0x00000000
.L_0602F430:
    mov.l   .L_0602F43C, r4
    cmp/ge r2, r4
    bt      .L_0602F440
    bra     .L_0602F448
    mov r4, r2
    .short  0x0000
.L_0602F43C:
    .long  0x00002AAA
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
    .short  0x0048

    .global DAT_0602f466
DAT_0602f466:
    .short  0x00C0
.L_0602F468:
    .short  0x0050
    .short  0x0000
.L_0602F46C:
    .long  0x00000AAA
.L_0602F470:
    .long  0x00002AAA

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
    .short  0x00D4
.L_0602F4AC:
    .short  0x0114
    .short  0x0000
.L_0602F4B0:
    .long  sym_060477D8

    .global sym_0602F4B4
sym_0602F4B4:
    mov.l   .L_0602F4C4, r1
    mov.l @r1, r3
    mov #0x1, r6
    tst r3, r3
    bt      .L_0602F4C8
    rts
    nop
    .short  0x0000
.L_0602F4C4:
    .long  sym_0607EAE0
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
    .short  0x00D6

    .global DAT_0602f51c
DAT_0602f51c:
    .short  0x0010

    .global DAT_0602f51e
DAT_0602f51e:
    .short  0x0018
.L_0602F520:
    .long  sym_0607EA98
.L_0602F524:
    .long  sym_0607E948
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
