
    .section .text.FUN_06027CA4


    .global FUN_06027CA4
    .type FUN_06027CA4, @function
FUN_06027CA4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l r5, @-r15
    mov.l @r4, r1
    mov.l   .L_pool_06027CF8, r2
    add r2, r1
    shlr16 r1
    shlr2 r1
    shlr2 r1
    shlr r1
    mov.l @(8, r4), r2
    mov.l   .L_pool_06027CFC, r3
    sub r2, r3
    shlr16 r3
    shlr2 r3
    shlr2 r3
    shlr r3
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r1
    mov.l   .L_pool_06027D00, r2
    mov.l @r2, r0
    cmp/eq #0x2, r0
    bf      .L_06027D40
    mov.l r1, @-r15
    mov r1, r10
    mov.l   .L_pool_06027D04, r1
    xor r12, r12
.L_06027CEA:
    mov.w @r1+, r0
    tst r0, r0
    bt      .L_06027D34
    cmp/eq r0, r10
    bt      .L_06027D08
    bra     .L_06027CEA
    add #0x2, r12
.L_pool_06027CF8:
    .4byte  0x04000000
.L_pool_06027CFC:
    .4byte  0x03FFFFFF
.L_pool_06027D00:
    .4byte  sym_0607EAD8
.L_pool_06027D04:
    .4byte  sym_06061270
.L_06027D08:
    mov.l   .L_pool_06027D28, r1
    mov.l @r1, r1
    mov.w   DAT_06027d26, r0
    mov.l @(r0, r1), r1
    mov #0x46, r0
    cmp/gt r0, r1
    bt      .L_06027D34
    shll r12
    mov.l   .L_pool_06027D2C, r0
    add r12, r0
    mov.l   .L_pool_06027D30, r1
    mov.w @r0+, r2
    mov.w @r0, r12
    bra     .L_06027D36
    mov.w r2, @r1

    .global DAT_06027d26
DAT_06027d26:
    .2byte  0x01EC
.L_pool_06027D28:
    .4byte  sym_0607E940
.L_pool_06027D2C:
    .4byte  sym_06061240
.L_pool_06027D30:
    .4byte  sym_06063F50
.L_06027D34:
    xor r12, r12
.L_06027D36:
    mov.l @r15+, r1
    tst r12, r12
    bt      .L_06027D40
    bra     .L_06027D50
    mov r2, r13
.L_06027D40:
    mov r1, r2
    shll2 r2
    mov.l   .L_pool_06027D5C, r0
    add r0, r2
    mov.w @r2, r13
    extu.w r13, r13
    mov.w @(2, r2), r0
    mov r0, r12
.L_06027D50:
    cmp/pl r12
    bt      .L_06027D60
    mov #0x0, r0
    mov r0, r3
    bra     .L_06027E6A
    mov #0x0, r6
.L_pool_06027D5C:
    .4byte  sym_060C2000
.L_06027D60:
    mov.l   .L_pool_06027DA4, r0
    mov.w @(r0, r13), r5
    mov #0x34, r6
    mov.l   .L_pool_06027DA8, r0
    muls.w r6, r5
    sts macl, r5
    add r5, r0
    mov.l @r0, r6
    add #0x10, r0
    mov #0x1, r14
    mov.l @r0+, r7
    shll16 r14
    mov.l @r4, r2
    shll8 r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027D90
    add r10, r3
.L_06027D90:
    mov.w   .L_wpool_06027DA0, r11
    tst r11, r6
    bt      .L_06027DAC
    cmp/pl r3
    bf      .L_06027DB6
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_wpool_06027DA0:
    .2byte  0x0100
    .2byte  0x0000
.L_pool_06027DA4:
    .4byte  sym_060BF000
.L_pool_06027DA8:
    .4byte  sym_060A6000
.L_06027DAC:
    cmp/pz r3
    bt      .L_06027DB6
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027DB6:
    mov r4, r1
    mov.l @r0+, r7
    mov.l @r1, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027DD2
    add r10, r3
.L_06027DD2:
    mov.w   .L_wpool_06027DE2, r11
    tst r11, r6
    bt      .L_06027DE4
    cmp/pl r3
    bf      .L_06027DEE
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_wpool_06027DE2:
    .2byte  0x0200
.L_06027DE4:
    cmp/pz r3
    bt      .L_06027DEE
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027DEE:
    mov.l @r0+, r7
    mov.l @r4, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027E08
    add r10, r3
.L_06027E08:
    mov.w   .L_wpool_06027E18, r10
    tst r10, r6
    bt      .L_06027E1A
    cmp/pl r3
    bf      .L_06027E24
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_wpool_06027E18:
    .2byte  0x0400
.L_06027E1A:
    cmp/pz r3
    bt      .L_06027E24
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027E24:
    mov.l @r0+, r7
    mov.l @r4, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027E3E
    add r10, r3
.L_06027E3E:
    mov.l   .L_pool_06027E50, r10
    tst r10, r6
    bt      .L_06027E54
    cmp/pl r3
    bf      .L_06027E5E
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
    .2byte  0x0000
.L_pool_06027E50:
    .4byte  0x00000800
.L_06027E54:
    cmp/pz r3
    bt      .L_06027E5E
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027E5E:
    mov.l   .L_pool_06027E9C, r1
    add r5, r1
    mov.l @r1, r3
    mov.w   DAT_06027e98, r6
    and r6, r3
    mov r3, r0
.L_06027E6A:
    mov.w r0, @(12, r4)
    mov #0x0, r0
    cmp/eq r0, r6
    bt      .L_06027EA8
    add #0x30, r1
    mov.w @r1, r0
    mov.l r0, @(16, r4)
    mov r0, r8
    mov r5, r1
    mov #0x34, r0
    mov.l   .L_pool_06027EA0, r12
    jsr @r12
    mov.l r3, @-r15
    mov.l @r15+, r3
    mov.w r0, @(14, r4)
    mov.l   .L_pool_06027EA4, r6
    mov.l @r6, r0
    mov.l @r15+, r5
    cmp/pl r5
    bt      .L_06027EAE
    mov.w   DAT_06027e9a, r1
    bra     .L_06027EAE
    mov.l r8, @(r0, r1)

    .global DAT_06027e98
DAT_06027e98:
    .2byte  0x00FF

    .global DAT_06027e9a
DAT_06027e9a:
    .2byte  0x025C
.L_pool_06027E9C:
    .4byte  sym_060A6000
.L_pool_06027EA0:
    .4byte  sym_0602ECCC
.L_pool_06027EA4:
    .4byte  sym_0607E940
.L_06027EA8:
    mov.l   .L_pool_06027ECC, r6
    mov.l @r6, r0
    mov.l @r15+, r5
.L_06027EAE:
    shll r5
    mov.l   .L_pool_06027ED0, r2
    add r5, r2
    mov.w @r2, r2
    extu.w r2, r2
    mov.l r3, @(r0, r2)
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_06027ECC:
    .4byte  sym_0607E940
.L_pool_06027ED0:
    .4byte  sym_0606128A
    .4byte  0x00093600
    .4byte  0x89FCAFD5
    .2byte  0x0009


    .global FUN_06027EDE
    .type FUN_06027EDE, @function
FUN_06027EDE:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l r6, @-r15
    mov r5, r13
    mov.l @r5, r14
    mov.l @(8, r5), r12
    mov.l   .L_06027F14, r11
    mov.l   .L_06027F18, r10
    mov.l   .L_06027F1C, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bt      .L_06027F20
    mov r4, r0
    shll r0
    add #0x1, r0
    shll r0
    mov.w @(r0, r11), r9
    mov r4, r0
    shll2 r0
    mov.w @(r0, r11), r8
    bra     .L_06027F84
    shlr r8
.L_06027F14:
    .4byte  sym_060C2000
.L_06027F18:
    .4byte  sym_060BF000
.L_06027F1C:
    .4byte  sym_0607EAD8
.L_06027F20:
    mov.l   .L_06027F34, r1
    xor r9, r9
.L_06027F24:
    mov.w @r1+, r0
    tst r0, r0
    bt      .L_06027F64
    cmp/eq r0, r4
    bt      .L_06027F38
    bra     .L_06027F24
    add #0x2, r9
    .2byte  0x0000
.L_06027F34:
    .4byte  sym_06061270
.L_06027F38:
    mov.l   .L_06027F58, r1
    mov.l @r1, r1
    mov.w   DAT_06027f56, r0
    mov.l @(r0, r1), r1
    mov #0x46, r0
    cmp/gt r0, r1
    bt      .L_06027F64
    shll r9
    mov.l   .L_06027F5C, r0
    add r9, r0
    mov.l   .L_06027F60, r1
    mov.w @r0+, r2
    mov.w @r0, r9
    bra     .L_06027F66
    mov.w r2, @r1

    .global DAT_06027f56
DAT_06027f56:
    .2byte  0x01EC
.L_06027F58:
    .4byte  sym_0607E940
.L_06027F5C:
    .4byte  sym_06061240
.L_06027F60:
    .4byte  sym_06063F50
.L_06027F64:
    xor r9, r9
.L_06027F66:
    tst r9, r9
    bf      .L_06027F7E
    mov r4, r0
    shll r0
    add #0x1, r0
    shll r0
    mov.w @(r0, r11), r9
    mov r4, r0
    shll2 r0
    mov.w @(r0, r11), r8
    bra     .L_06027F84
    shlr r8
.L_06027F7E:
    mov.l   .L_06027FC4, r0
    mov.w @r0, r8
    shlr r8
.L_06027F84:
    xor r7, r7
.L_06027F86:
    mov r8, r0
    shll r0
    mov.w @(r0, r10), r1
    mov.l   .L_06027FC8, r0
    mulu.w r0, r1
    sts macl, r5
    mov.l   .L_06027FCC, r0
    add r0, r5
    mov r5, r0
    mov.l @(0, r0), r4
    mov.l @(16, r0), r6
    mov.l @(20, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    mov.l   .L_06027FD0, r0
    tst r4, r0
    bf      .L_06027FB0
    add r12, r3
.L_06027FB0:
    mov.w   .L_06027FC0, r0
    tst r0, r4
    bt      .L_06027FB8
    neg r3, r3
.L_06027FB8:
    cmp/pz r3
    bt      .L_06027FD4
    bra     .L_06028064
    nop
.L_06027FC0:
    .2byte  0x0100
    .2byte  0x0000
.L_06027FC4:
    .4byte  sym_06063F50
.L_06027FC8:
    .4byte  0x00000034
.L_06027FCC:
    .4byte  sym_060A6000
.L_06027FD0:
    .4byte  0x01000000
.L_06027FD4:
    mov r5, r0
    mov.l @(24, r0), r6
    mov.l @(28, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    mov.l   .L_06028000, r0
    tst r0, r4
    bf      .L_06027FEC
    add r12, r3
.L_06027FEC:
    mov.w   .L_06027FFC, r0
    tst r0, r4
    bt      .L_06027FF4
    neg r3, r3
.L_06027FF4:
    cmp/pz r3
    bt      .L_06028004
    bra     .L_06028064
    nop
.L_06027FFC:
    .2byte  0x0200
    .2byte  0x0000
.L_06028000:
    .4byte  0x02000000
.L_06028004:
    mov r5, r0
    mov.l @(32, r0), r6
    mov.l @(36, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    mov.l   .L_06028030, r0
    tst r0, r4
    bf      .L_0602801C
    add r12, r3
.L_0602801C:
    mov.w   .L_0602802C, r0
    tst r0, r4
    bt      .L_06028024
    neg r3, r3
.L_06028024:
    cmp/pz r3
    bt      .L_06028034
    bra     .L_06028064
    nop
.L_0602802C:
    .2byte  0x0400
    .2byte  0x0000
.L_06028030:
    .4byte  0x04000000
.L_06028034:
    mov r5, r0
    mov.l @(40, r0), r6
    mov.l @(44, r0), r2
    dmuls.l r14, r6
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    mov.l   .L_06028060, r0
    tst r0, r4
    bf      .L_0602804C
    add r12, r3
.L_0602804C:
    mov.w   DAT_0602805c, r0
    tst r0, r4
    bt      .L_06028054
    neg r3, r3
.L_06028054:
    cmp/pz r3
    bf      .L_06028064
    bra     .L_06028070
    mov #0x1, r6

    .global DAT_0602805c
DAT_0602805c:
    .2byte  0x0800
    .2byte  0x0000
.L_06028060:
    .4byte  0x08000000
.L_06028064:
    add #0x1, r7
    add #0x1, r8
    cmp/ge r9, r7
    bt      .L_06028070
    bra     .L_06027F86
    nop
.L_06028070:
    mov.l @r15+, r6
    tst r6, r6
    bt      .L_060280A6
    cmp/eq r7, r9
    bt      .L_060280A6
    mov.l   .L_060280B8, r0
    mov.l @(r0, r5), r1
    dmuls.l r14, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l   .L_060280BC, r0
    mov.l @(r0, r5), r2
    dmuls.l r12, r2
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l   .L_060280C0, r0
    mov.l @(r0, r5), r3
    add r2, r1
    add r3, r1
    mov r13, r0
    mov.l r1, @(4, r0)
    mov r8, r0
    shll r0
    mov.w @(r0, r10), r1
    mov.w r1, @r6
.L_060280A6:
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
.L_060280B8:
    .4byte  0x00000004
.L_060280BC:
    .4byte  0x00000008
.L_060280C0:
    .4byte  0x0000000C

    .global sym_060280C4
sym_060280C4:
    mov.l   .L_060280F0, r3
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w @(r0, r2), r4
    mov #0x6, r0
    mov.w r4, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_060280F0:
    .4byte  sym_060280F4

    .global sym_060280F4
sym_060280F4:
    mov.b r0, @(r0, r0)
    mov.l r12, @(0, r4)

    .global sym_060280F8
sym_060280F8:
    mov #0x5, r0
    mov.b @(r0, r4), r6
    mov.l   .L_06028160, r1
    extu.b r6, r6
    shll8 r6
    shlr2 r6
    mov.w @(6, r4), r0
    mov #0x8, r2
    add r6, r0
    shll r0
    mov.w @(r0, r1), r7
    mulu.w r2, r7
    mov.l   .L_06028164, r1
    mov #0x6, r0
    sts macl, r2
    add r2, r1
    mov.w @(r0, r1), r6
    mov.l   .L_06028168, r3
    mov.b @(4, r4), r0
    and #0xC, r0
    add r0, r3
    mov.l @r3, r0
    mov.w r0, @(0, r5)
    mov.b @(4, r4), r0
    mov.l   .L_0602816C, r2
    and #0x1, r0
    shll r0
    add r2, r0
    mov.w @r0, r0
    mov.w r0, @(4, r5)
    mov.l   .L_06028170, r3
    mov.l @r3, r0
    mov #0x8, r3
    mulu.w r3, r7
    add r6, r0
    mov.w r0, @(6, r5)
    mov.l   .L_06028164, r2
    sts macl, r3
    add r3, r2
    mov.l @(0, r2), r0
    mov.l @(20, r4), r1
    mov.w r0, @(8, r5)
    mov.w @(4, r2), r0
    mov.l @(16, r4), r3
    mov.w r0, @(10, r5)
    mov.l @(8, r4), r0
    mov.l @(12, r4), r2
    mov.l r0, @(12, r5)
    mov.l r2, @(16, r5)
    mov.l r3, @(20, r5)
    rts
    mov.l r1, @(24, r5)
.L_06028160:
    .4byte  sym_060684EC
.L_06028164:
    .4byte  sym_06063F64
.L_06028168:
    .4byte  sym_06028178
.L_0602816C:
    .4byte  sym_06028174
.L_06028170:
    .4byte  sym_06059FFC

    .global sym_06028174
sym_06028174:
    mov.l r12, @(32, r4)
    mov.l r8, @(32, r4)

    .global sym_06028178
sym_06028178:
    .word 0x0000
    stc sr, r0
    .word 0x0000
    stc vbr, r0
    .word 0x0000
    stc gbr, r0
    .word 0x0000
    .word 0x0032
    mov.l   .L_060281B0, r3
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_060281B0:
    .4byte  sym_060281B4

    .global sym_060281B4
sym_060281B4:
    mov.w r0, @(r0, r0)
    mov.l r12, @(0, r4)

    .global sym_060281B8
sym_060281B8:
    mov.l   .L_060281E0, r3
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_060281E0:
    .4byte  sym_060281E4

    .global sym_060281E4
sym_060281E4:
    mov.b r0, @(r0, r0)
    .word 0x05C0
    mov.l   .L_06028210, r3
    mov r4, r2
    mov.w @r3+, r4
    mov r5, r1
    mov.w r4, @r1
    mov #0x4, r0
    mov.w @r3, r4
    mov.w r4, @(r0, r1)
    mov #0x6, r0
    mov.w r6, @(r0, r1)
    mov.l @(8, r2), r0
    mov.l r0, @(12, r1)
    mov.l @(12, r2), r0
    mov.l r0, @(16, r1)
    mov.l @(16, r2), r0
    mov.l r0, @(20, r1)
    mov.l @(20, r2), r0
    rts
    mov.l r0, @(24, r1)
    .2byte  0x0000
.L_06028210:
    .4byte  sym_06028214

    .global sym_06028214
sym_06028214:
    mov.b r0, @(r0, r0)
    .word 0x04C2

    .global sym_06028218
sym_06028218:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    mov.l   .L_060282B0, r6
    bra     .L_0602825E
    mov #0x9, r4

    .global sym_06028230
sym_06028230:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    mov.l   .L_060282B8, r6
    bra     .L_0602825E
    mov #0xC, r4

    .global sym_06028248
sym_06028248:
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    mov.l   .L_060282BC, r6
    mov #0x9, r4
.L_0602825E:
    mov.w   .L_060282AC, r0
    mov #0x1, r5
    .reloc ., R_SH_IND12W, FUN_06028600 - 4
    .2byte 0xB000    /* bsr FUN_06028600 (linker-resolved) */
    ldc r0, sr
    mov.l   .L_060282B4, r6
    mov #0xD, r4
    .reloc ., R_SH_IND12W, FUN_06028600 - 4
    .2byte 0xB000    /* bsr FUN_06028600 (linker-resolved) */
    mov #0x2, r5
    mov #0x13, r4
    mov #0x2, r5
    .reloc ., R_SH_IND12W, FUN_060285E0 - 4
    .2byte 0xB000    /* bsr FUN_060285E0 (linker-resolved) */
    mov.l @(36, r15), r6
    mov.l   .L_060282A0, r4
    mov.l   .L_060282A4, r5
    mov.w   .L_0602829C, r6
    mov.l   .L_060282A8, r7
    jsr @r7
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r0
    mov.l @r15+, r1
    mov.l @r15+, r2
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov.l @r15+, r5
    mov.l @r15+, r6
    mov.l @r15+, r7
    sett
.L_06028296:
    bt      .L_06028296
    rte
    nop
.L_0602829C:
    .2byte  0x0180
    .2byte  0x0000
.L_060282A0:
    .4byte  sym_060612B8
.L_060282A4:
    .4byte  sym_060612C4
.L_060282A8:
    .4byte  FUN_0602761E
.L_060282AC:
    .2byte  0x00F0
    .2byte  0x0009
.L_060282B0:
    .4byte  sym_06059C5C
.L_060282B4:
    .4byte  sym_06059C74
.L_060282B8:
    .4byte  sym_06059C7B
.L_060282BC:
    .4byte  sym_06059C8C
    .global FUN_060282C0
FUN_060282C0:
    .4byte  0xD20ED00F
    .4byte  0x12001201
    .4byte  0x1202E000
    .2byte 0x802B
    .2byte 0x4411
    .4byte  0x8D02E720
    .4byte  0x644BE72D
    .4byte  0x72029113
    .4byte  0xE00A1100
    .4byte  0x24488906
    .4byte  0x11410009
    .4byte  0x53164010
    .4byte  0x02348FF7
    .4byte  0x541772FE
    .4byte  0x0274000B
    .4byte  0x60230009
    .4byte  sym_060620C4
    .4byte  0x20202020
    .2byte  0xFF00
    .global FUN_06028306
FUN_06028306:
    .2byte  0xD20E
    .4byte  0xD00E1200
    .4byte  0x12011202
    .4byte  0xE000802B
    .4byte  0x44118D02
    .4byte  0xE70A644B
    .4byte  0xE72D7202
    .4byte  0x9112E00A
    .4byte  0x11002448
    .4byte  0x89061141
    .4byte  0x00095316
    .4byte  0x40100234
    .4byte  0x8FF75417
    .4byte  0x72FE0274
    .4byte  0x000B6023
    .4byte  sym_060620C4
    .4byte  0x0A0A0A0A
    .2byte  0xFF00

    .global FUN_0602834A
    .type FUN_0602834A, @function
FUN_0602834A:
    sts.l pr, @-r15
    mov.l   .L_06028364, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r2, r5
    bsr     FUN_060282C0
    mov r7, r4
    mov r0, r1
    mov #0x6, r7
    add #0x8, r1
    .reloc ., R_SH_IND12W, FUN_06028398 - 4
    .2byte 0xA000    /* bra FUN_06028398 (linker-resolved) */
    mov #0x0, r0
    .2byte  0x0000
.L_06028364:
    .4byte  sym_06028614
