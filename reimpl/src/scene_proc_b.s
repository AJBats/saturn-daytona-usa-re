
    .section .text.FUN_0602ABC4


    .global scene_proc_b
    .type scene_proc_b, @function
scene_proc_b:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov r5, r14
    mov r6, r13
    mov.l   .L_0602AC04, r12
    mov #0x40, r4
    mov #-0x1, r0
.L_0602ABD4:
    mov.l r0, @r12
    dt r4
    bf/s    .L_0602ABD4
    add #0x10, r12
    mov.l   .L_0602AC08, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    sts macl, r0
    add r0, r8
.L_0602ABE8:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_0602AC0C, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0
    bt      .L_0602AC10
    mov.w @(14, r8), r0
    mov.w   .L_0602AC00, r1
    cmp/eq r0, r1
    bf      .L_0602AC10
    bra     .L_0602ADF8
    nop
.L_0602AC00:
    .2byte  0x0097
    .2byte  0x0000
.L_0602AC04:
    .4byte  sym_06094220
.L_0602AC08:
    .4byte  sym_06063F08
.L_0602AC0C:
    .4byte  sym_0605BE36
.L_0602AC10:
    mov.l   .L_0602AC80, r11
    mov.l   .L_0602AC84, r5
    mov.l   .L_0602AC88, r0
    mov.l @r0, r6
    mov.w @(16, r8), r0
    mov r0, r9
    bsr     .L_0602AE24
    nop
    mov.l r1, @r5
    mov.l r2, @(4, r5)
    mov.l r3, @(8, r5)
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_0602AC90
    mov.l   .L_0602AC8C, r7
    mov r8, r4
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @r7
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @(4, r7)
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0x24, r6
    sts mach, r0
    sts macl, r9
    xtrct r0, r9
    mov.l r9, @(8, r7)
    clrmac
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    add #-0xC, r5
    sts mach, r9
    sts macl, r0
    xtrct r9, r0
    cmp/pl r0
    bt      .L_0602AC90
    bra     .L_0602ADF8
    nop
    .2byte  0x0000
.L_0602AC80:
    .4byte  sym_0602AEEC
.L_0602AC84:
    .4byte  sym_0602AF0C
.L_0602AC88:
    .4byte  sym_0608A52C
.L_0602AC8C:
    .4byte  sym_0602AF1C
.L_0602AC90:
    mov.w @(16, r8), r0
    mov.l   .L_0602AD04, r7
    bsr     .L_0602AEBE
    mov r0, r9
    mov.l r3, @r5
    bsr     .L_0602AE84
    add #0x4, r5

    .global sym_0602AC9E
sym_0602AC9E:
    mov.w @(18, r8), r0
    mov.l   .L_0602AD08, r7
    bsr     .L_0602AEBE
    mov r0, r9
    bsr     .L_0602AE24
    nop
    mov.l r3, @r5
    bsr     .L_0602AE84
    add #0x4, r5

    .global sym_0602ACB0
sym_0602ACB0:
    mov.w @(20, r8), r0
    mov.l   .L_0602AD0C, r7
    bsr     .L_0602AEBE
    mov r0, r9
    bsr     .L_0602AE24
    nop
    mov.l r3, @r5
    bsr     .L_0602AE84
    add #0x4, r5

    .global sym_0602ACC2
sym_0602ACC2:
    mov.w @(22, r8), r0
    mov.l   .L_0602AD10, r7
    bsr     .L_0602AEBE
    mov r0, r9
    bsr     .L_0602AE24
    nop
    mov.l r3, @r5
    bsr     .L_0602AE84
    add #0x4, r5

    .global sym_0602ACD4
sym_0602ACD4:
    mov.l   .L_0602AD14, r0
    mov #0x18, r1
    mov.l @r0, r0
    mulu.w r0, r1
    mov.l   .L_0602AD18, r2
    sts macl, r9
    add r2, r9
    add #-0x20, r11
    mov.w   DAT_0602ad02, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_0602AD1C
    cmp/gt r2, r12
    bf      .L_0602AD1C
    cmp/gt r4, r12
    bf      .L_0602AD1C
    cmp/gt r6, r12
    bf      .L_0602AD1C
    bra     .L_0602ADF8
    nop

    .global DAT_0602ad02
DAT_0602ad02:
    .2byte  0xFF50
.L_0602AD04:
    .4byte  sym_0602AC9E
.L_0602AD08:
    .4byte  sym_0602ACB0
.L_0602AD0C:
    .4byte  sym_0602ACC2
.L_0602AD10:
    .4byte  sym_0602ACD4
.L_0602AD14:
    .4byte  sym_060620D4
.L_0602AD18:
    .4byte  sym_0608AC20
.L_0602AD1C:
    mov.w   DAT_0602ad96, r12
    cmp/gt r0, r12
    bt      .L_0602AD2E
    cmp/gt r2, r12
    bt      .L_0602AD2E
    cmp/gt r4, r12
    bt      .L_0602AD2E
    cmp/gt r6, r12
    bt      .L_0602ADF8
.L_0602AD2E:
    mov.w   DAT_0602ad98, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_0602AD48
    cmp/gt r3, r12
    bf      .L_0602AD48
    cmp/gt r5, r12
    bf      .L_0602AD48
    cmp/gt r7, r12
    bt      .L_0602ADF8
.L_0602AD48:
    mov.w   DAT_0602ad9a, r12
    cmp/gt r1, r12
    bt      .L_0602AD5A
    cmp/gt r3, r12
    bt      .L_0602AD5A
    cmp/gt r5, r12
    bt      .L_0602AD5A
    cmp/gt r7, r12
    bf      .L_0602ADF8
.L_0602AD5A:
    mov r9, r12
    add #0x18, r12
    mov.w r7, @-r12
    mov.w r6, @-r12
    mov.w r5, @-r12
    mov.w r4, @-r12
    mov.w r3, @-r12
    mov.w r2, @-r12
    mov.w r1, @-r12
    mov.w r0, @-r12
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)
    mov.w @(12, r8), r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.b r0, @(4, r9)
    mov r13, r0
    mov.b r0, @(5, r9)
    mov.w @(12, r8), r0
    mov.l   .L_0602AD9C, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r2
    .word 0xC760
    mov.l @r0, r3
    mov.l @(4, r0), r4
    mov.l @(8, r0), r5
    jmp @r2
    mov.l @(12, r0), r6

    .global DAT_0602ad96
DAT_0602ad96:
    .2byte  0x00B0

    .global DAT_0602ad98
DAT_0602ad98:
    .2byte  0xFF81

    .global DAT_0602ad9a
DAT_0602ad9a:
    .2byte  0x0051
.L_0602AD9C:
    .4byte  sym_0602AF28

    .global loc_0602ADA0
loc_0602ADA0:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_0602ADE0
    shlr2 r3

    .global loc_0602ADAA
loc_0602ADAA:
    cmp/ge r3, r4
    bt      .L_0602ADB0
    mov r4, r3
.L_0602ADB0:
    cmp/ge r3, r5
    bt      .L_0602ADB6
    mov r5, r3
.L_0602ADB6:
    cmp/ge r3, r6
    bt      .L_0602ADBC
    mov r6, r3
.L_0602ADBC:
    bra     .L_0602ADE0
    nop

    .global loc_0602ADC0
loc_0602ADC0:
    bra     .L_0602ADCC
    mov #0x0, r0

    .global loc_0602ADC4
loc_0602ADC4:
    mov #0x1, r0
    bra     .L_0602ADCC
    shll16 r0

    .global loc_0602ADCA
loc_0602ADCA:
    mov.l   .L_0602AE04, r0
.L_0602ADCC:
    cmp/gt r3, r4
    bf      .L_0602ADD2
    mov r4, r3
.L_0602ADD2:
    cmp/gt r3, r5
    bf      .L_0602ADD8
    mov r5, r3
.L_0602ADD8:
    cmp/gt r3, r6
    bf      .L_0602ADDE
    mov r6, r3
.L_0602ADDE:
    add r0, r3
.L_0602ADE0:
    mov.l   .L_0602AE08, r2
    neg r3, r3
    mov.l   .L_0602AE0C, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_0602ADF8:
    mov.l @r15+, r7
    dt r7
    bt      .L_0602AE10
    bra     .L_0602ABE8
    nop
    .2byte  0x0000
.L_0602AE04:
    .4byte  0x000B8000
.L_0602AE08:
    .4byte  sym_060620D4
.L_0602AE0C:
    .4byte  sym_0606A4F8
.L_0602AE10:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
    .2byte  0x0009
.L_0602AE24:
    mov #0xC, r0
    mul.l r0, r9
    mov #0x18, r7
    add r6, r7
    sts macl, r4
    add r14, r4
    clrmac
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    add #-0xC, r4
    mov.l @(8, r7), r2
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    cmp/gt r10, r3
    bf      .L_0602ADF8
    mov.w   .L_0602AE7E, r2
    mov.w   .L_0602AE80, r0
    mov.l r0, @(16, r2)
    mov.l r3, @(0, r2)
    mov #0x0, r0
    mov.l r0, @(20, r2)
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r7
    add #-0x18, r6
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    rts
    add r7, r2
.L_0602AE7E:
    .2byte  0xFF00
.L_0602AE80:
    .2byte  0x00A0
    .2byte  0x0009
.L_0602AE84:
    mov.w   DAT_0602aeba, r0
    mov.l @(28, r0), r4
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r11
    sts mach, r2
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.w   DAT_0602aebc, r7
    cmp/gt r7, r1
    bt      .L_0602ADF8
    neg r7, r0
    cmp/gt r1, r0
    bt      .L_0602ADF8
    cmp/gt r2, r0
    bt      .L_0602ADF8
    shlr r7
    cmp/gt r7, r2
    bt      .L_0602ADF8
    mov.l r9, @r12
    mov.l r1, @(4, r12)
    mov.l r2, @(8, r12)
    mov.l r3, @(12, r12)
    rts
    nop

    .global DAT_0602aeba
DAT_0602aeba:
    .2byte  0xFF00

    .global DAT_0602aebc
DAT_0602aebc:
    .2byte  0x0190
.L_0602AEBE:
    and #0x3F, r0
    mov.l   .L_0602AEE4, r12
    shll2 r0
    shll2 r0
    add r0, r12
    mov.l @r12, r0
    cmp/pz r0
    bf      .L_0602AEE8
    cmp/eq r0, r9
    bf      .L_0602AEE8
    mov.l @(4, r12), r1
    mov.l @(8, r12), r2
    mov.l @(12, r12), r3
    mov.l r1, @r11
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.l r3, @r5
    jmp @r7
    add #0x4, r5
.L_0602AEE4:
    .4byte  sym_06094220
.L_0602AEE8:
    rts
    nop


    .global sym_0602AEEC
sym_0602AEEC:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF0C
sym_0602AF0C:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af10
DAT_0602af10:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af14
DAT_0602af14:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602af18
DAT_0602af18:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF1C
sym_0602AF1C:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AF28
sym_0602AF28:
    .4byte  loc_0602ADA0
    .4byte  loc_0602ADAA
    .4byte  loc_0602ADC0
    .4byte  loc_0602ADC4
    .4byte  loc_0602ADCA

    .global sym_0602AF3C
sym_0602AF3C:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
