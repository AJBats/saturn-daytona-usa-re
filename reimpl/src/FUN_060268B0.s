
    .section .text.FUN_060268B0


    .global FUN_060268B0
    .type FUN_060268B0, @function
FUN_060268B0:
    mov.l r14, @-r15
    exts.w r4, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.w   DAT_06026922, r8
    mov.l   .L_06026924, r9
    mov.l   .L_06026928, r10
    mov.l   .L_0602692C, r11
    mov.l   .L_06026930, r13
    mov.l   .L_06026934, r14
    tst r4, r4
    bt/s    .L_060268E6
    mov #0x0, r12
    mov.w r12, @r10
    exts.w r12, r2
    mov.w r2, @r13
    mov.w r2, @r14
    mov.l   .L_06026938, r2
    mov.w r12, @r2
    bra     .L_06026C70
    mov.l r12, @r11
.L_060268E6:
    mov.l   .L_0602693C, r0
    bra     .L_06026C48
    mov.l @r0, r0
.L_060268EC:
    mov.w @r14, r2
    mov #0x36, r3
    cmp/ge r3, r2
    bt      .L_0602694C
    mov.w @r14, r3
    mov.l   .L_06026940, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_06026982
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_06026944, r7
    mov.l   .L_06026948, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_06026982
    mov.w r2, @r10

    .global DAT_06026922
DAT_06026922:
    .2byte  0x0C04
.L_06026924:
    .4byte  sym_060283E0              /* display command writer function */
.L_06026928:
    .4byte  sym_0606123C
.L_0602692C:
    .4byte  sym_0607864C
.L_06026930:
    .4byte  sym_0606123A
.L_06026934:
    .4byte  sym_06061238
.L_06026938:
    .4byte  sym_0606123E
.L_0602693C:
    .4byte  sym_0607EAD8
.L_06026940:
    .4byte  sym_060597B8
.L_06026944:
    .4byte  sym_06059826
.L_06026948:
    .4byte  0x0000F000
.L_0602694C:
    mov.w @r14, r0
    cmp/eq #0x36, r0
    bf      .L_06026982
    mov.w @r14, r2
    mov.l   .L_06026B1C, r3
    mov.l   .L_06026B20, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_06026982
    mov r8, r5
    mov.l   .L_06026B24, r7
    mov.l   .L_06026B28, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_06026B2C, r2
    mov.w r3, @r2
.L_06026982:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_060269A2
    mov r8, r5
    mov.w @r14, r7
    mov.l   .L_06026B30, r3
    mov.l   .L_06026B34, r2
    mov.l   .L_06026B28, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_060269A2:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bt      .L_060269B0
    bra     .L_06026C60
    nop
.L_060269B0:
    bra     .L_060269DC
    nop
.L_060269B4:
    mov.w @r13, r2
    mov #0x20, r3
    cmp/ge r3, r2
    bf      .L_060269C0
    bra     .L_06026A10
    nop
.L_060269C0:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_06026B30, r3
    mov.l   .L_06026B34, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     FUN_06026CA4
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_060269DC:
    mov.w @r14, r0
    mov.l   .L_06026B30, r3
    mov.l   .L_06026B38, r2
    mov.w @r13, r4
    mov.w @r14, r1
    add #-0x1, r0
    add #-0x1, r1
    mov.b @(r0, r3), r0
    shll r1
    shll2 r0
    shll2 r0
    shll r0
    add r2, r0
    mov.b @(r0, r4), r4
    mov.l   .L_06026B1C, r0
    mov.w @(r0, r1), r3
    add r4, r3
    mov r3, r1
    shll r3
    add r1, r3
    mov.l @r11, r1
    cmp/hs r3, r1
    bf      .L_06026A10
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_060269B4
.L_06026A10:
    bra     .L_06026C60
    nop
.L_06026A14:
    mov.w @r14, r2
    mov #0x3A, r3
    cmp/ge r3, r2
    bt      .L_06026A4A
    mov.w @r14, r3
    mov.l   .L_06026B3C, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_06026A80
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_06026B24, r7
    mov.l   .L_06026B28, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_06026A80
    mov.w r2, @r10
.L_06026A4A:
    mov.w @r14, r0
    cmp/eq #0x3A, r0
    bf      .L_06026A80
    mov.w @r14, r2
    mov.l   .L_06026B3C, r3
    mov.l   .L_06026B20, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_06026A80
    mov.l   .L_06026B24, r7
    mov r8, r5
    mov.l   .L_06026B28, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_06026B2C, r2
    mov.w r3, @r2
.L_06026A80:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_06026AA0
    mov.w @r14, r7
    mov r8, r5
    mov.l   .L_06026B40, r3
    mov.l   .L_06026B44, r2
    mov.l   .L_06026B28, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_06026AA0:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bt      .L_06026AAE
    bra     .L_06026C60
    nop
.L_06026AAE:
    bra     .L_06026ADA
    nop
.L_06026AB2:
    mov #0x24, r3
    mov.w @r13, r2
    cmp/ge r3, r2
    bf      .L_06026ABE
    bra     .L_06026B16
    nop
.L_06026ABE:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_06026B40, r3
    mov.l   .L_06026B44, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     FUN_06026CA4
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_06026ADA:
    mov.w @r14, r0
    mov.l   .L_06026B40, r3
    mov.l   .L_06026B48, r1
    mov.w @r13, r4
    add #-0x1, r0
    mov.b @(r0, r3), r0
    mov r0, r2
    shll2 r0
    shll2 r2
    shll2 r2
    shll r2
    add r2, r0
    exts.w r0, r0
    mov.w @r14, r2
    add r1, r0
    add #-0x1, r2
    mov.b @(r0, r4), r4
    shll r2
    mov.l   .L_06026B3C, r0
    mov.w @(r0, r2), r3
    add r4, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r11, r2
    cmp/hs r3, r2
    bf      .L_06026B16
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_06026AB2
.L_06026B16:
    bra     .L_06026C60
    nop
    .2byte  0xFFFF
.L_06026B1C:
    .4byte  sym_060597B8
.L_06026B20:
    .4byte  sym_0607864C
.L_06026B24:
    .4byte  sym_06059826
.L_06026B28:
    .4byte  0x0000F000
.L_06026B2C:
    .4byte  sym_0606123E
.L_06026B30:
    .4byte  sym_060591BA
.L_06026B34:
    .4byte  sym_060611FC
.L_06026B38:
    .4byte  sym_060595D8
.L_06026B3C:
    .4byte  sym_060591F0
.L_06026B40:
    .4byte  sym_0605914C
.L_06026B44:
    .4byte  sym_0606119C
.L_06026B48:
    .4byte  sym_06059266
.L_06026B4C:
    mov.w @r14, r2
    mov #0x34, r3
    cmp/ge r3, r2
    bt      .L_06026B82
    mov.w @r14, r3
    mov.l   .L_06026C84, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_06026BB8
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_06026C88, r7
    mov.l   .L_06026C8C, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_06026BB8
    mov.w r2, @r10
.L_06026B82:
    mov.w @r14, r0
    cmp/eq #0x34, r0
    bf      .L_06026BB8
    mov.w @r14, r2
    mov.l   .L_06026C84, r3
    mov.l   .L_06026C90, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_06026BB8
    mov.l   .L_06026C88, r7
    mov r8, r5
    mov.l   .L_06026C8C, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_06026C94, r2
    mov.w r3, @r2
.L_06026BB8:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_06026BD8
    mov.w @r14, r7
    mov r8, r5
    mov.l   .L_06026C98, r3
    mov.l   .L_06026C9C, r2
    mov.l   .L_06026C8C, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_06026BD8:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bf      .L_06026C60
    bra     .L_06026C0E
    nop
.L_06026BE6:
    mov #0x19, r3
    mov.w @r13, r2
    cmp/ge r3, r2
    bf      .L_06026BF2
    bra     .L_06026C44
    nop
.L_06026BF2:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_06026C98, r3
    mov.l   .L_06026C9C, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     FUN_06026CA4
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_06026C0E:
    mov #0x19, r2
    mov.l   .L_06026CA0, r1
    mov.w @r14, r0
    mov.l   .L_06026C98, r3
    mov.w @r13, r4
    add #-0x1, r0
    mov.b @(r0, r3), r0
    mulu.w r2, r0
    mov.w @r14, r2
    sts macl, r0
    add #-0x1, r2
    extu.b r0, r0
    shll r2
    add r1, r0
    mov.b @(r0, r4), r4
    mov.l   .L_06026C84, r0
    mov.w @(r0, r2), r3
    add r4, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r11, r2
    cmp/hs r3, r2
    bf      .L_06026C44
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_06026BE6
.L_06026C44:
    bra     .L_06026C60
    nop
.L_06026C48:
    cmp/eq #0x0, r0
    bf      .L_06026C50
    bra     .L_060268EC
    nop
.L_06026C50:
    cmp/eq #0x1, r0
    bf      .L_06026C58
    bra     .L_06026A14
    nop
.L_06026C58:
    cmp/eq #0x2, r0
    bf      .L_06026C60
    bra     .L_06026B4C
    nop
.L_06026C60:
    mov.l   .L_06026C94, r0
    mov.w @r0, r0
    tst r0, r0
    bt      .L_06026C70
    mov.l r12, @r11
    exts.w r12, r3
    mov.l   .L_06026C94, r2
    mov.w r3, @r2
.L_06026C70:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06026C84:
    .4byte  sym_0605956E
.L_06026C88:
    .4byte  sym_06059826
.L_06026C8C:
    .4byte  0x0000F000
.L_06026C90:
    .4byte  sym_0607864C
.L_06026C94:
    .4byte  sym_0606123E
.L_06026C98:
    .4byte  sym_06059186
.L_06026C9C:
    .4byte  sym_060611DC
.L_06026CA0:
    .4byte  sym_060594A6

    .global FUN_06026CA4
    .type FUN_06026CA4, @function
FUN_06026CA4:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov r15, r14
    mov.w r5, @r15
    add #0x4, r14
    mov.w @r15, r0
    mov r14, r7
    mov.b @(r0, r4), r3
    mov #0x0, r0
    mov.b r3, @r14
    mov.b r0, @(1, r14)
    mov.l   .L_06026CD8, r6
    mov.w @r15, r5
    mov.w   .L_06026CD4, r3
    add r3, r5
    shll r5
    mov.l   .L_06026CDC, r3
    jsr @r3
    mov #0xC, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06026CD4:
    .2byte  0x0602
    .2byte  0xFFFF
.L_06026CD8:
    .4byte  0x0000E000
.L_06026CDC:
    .4byte  sym_060283E0              /* display command writer (dup) */

    .global sym_06026CE0
sym_06026CE0:
    mov.l   .L_06026D24, r1
    mov #0x1, r2
    mov.l   .L_06026D28, r3
    mov #0x0, r4
    mov.l r2, @r1
    nop
.L_06026CEC:
    mov.l @r1, r0
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    dt r0
    bt/s    .L_06026CEC
    add #0x1, r4
    rts
    mov.l r4, @r3
    .2byte  0x0009                    /* alignment padding (nop) */
.L_06026D24:
    .4byte  sym_060635C4
.L_06026D28:
    .4byte  sym_0605A010
    .4byte  0xD217E000
    .4byte  0xE1010215
    .4byte  0xE002E100
    .4byte  0x0215E006
    .4byte  0xE1000215
    .4byte  0xE00CE100
    .4byte  0x0215E00E
    .4byte  0x911C0215
    .4byte  0xE020E100
    .4byte  0x0215E028
    .4byte  0xE1000215
    .4byte  0xE02A9114
    .4byte  0x0215E030
    .4byte  0x91120215
    .4byte  0xE032910F
    .4byte  0x0215E034
    .4byte  0x910C0215
    .4byte  0xE0369109
    .4byte  0x0215E038
    .4byte  0xE1000215
    .4byte  0xE03AE100
    .4byte  0x000B0215
    .4byte  0x13631022
    .4byte  0xC0000000
    .4byte  0x25F80000
    .4byte  0xE100D006
    .4byte  0xD2064010
    .4byte  0x8FFD2216
    .4byte  0xD005D206
    .4byte  0x40108FFD
    .4byte  0x2216000B
    .4byte  0x00090000
    .4byte  0x00060000
    .4byte  0x25F80000
    .4byte  0x00030000
    .4byte  0x25CC0000

    .global sym_06026DBC
sym_06026DBC:
    mov.l   .L_pool_06027068, r3
    mov.l @r3, r0
    mov #0x30, r1
    add r0, r1
    mov.l r1, @r3
    mov.l @(0, r0), r2
    mov.l @(4, r0), r3
    mov.l r2, @(0, r1)
    mov.l r3, @(4, r1)
    mov.l @(8, r0), r2
    mov.l @(12, r0), r3
    mov.l r2, @(8, r1)
    mov.l r3, @(12, r1)
    mov.l @(16, r0), r2
    mov.l @(20, r0), r3
    mov.l r2, @(16, r1)
    mov.l r3, @(20, r1)
    mov.l @(24, r0), r2
    mov.l @(28, r0), r3
    mov.l r2, @(24, r1)
    mov.l r3, @(28, r1)
    mov.l @(32, r0), r2
    mov.l @(36, r0), r3
    mov.l r2, @(32, r1)
    mov.l r3, @(36, r1)
    mov.l @(40, r0), r2
    mov.l @(44, r0), r3
    mov.l r2, @(40, r1)
    rts
    mov.l r3, @(44, r1)

    .global sym_06026DF8
sym_06026DF8:
    mov.l   .L_pool_06027068, r1
    mov.l @r1, r0
    add #-0x30, r0
    rts
    mov.l r0, @r1

    .global sym_06026E02
sym_06026E02:
    mov.l   .L_pool_0602706C, r0
    mov.l   .L_pool_06027068, r1
    mov #0x0, r2
    bra     .L_06026E12
    mov.l r0, @r1

    .global sym_06026E0C
sym_06026E0C:
    mov.l   .L_pool_06027068, r0
    mov #0x0, r2
    mov.l @r0, r0
.L_06026E12:
    mov.l   .L_pool_0602707C, r1
    mov.l r2, @(4, r0)
    mov.l r1, @(0, r0)
    mov.l r2, @(8, r0)
    mov.l r2, @(12, r0)
    mov.l r1, @(16, r0)
    mov.l r2, @(20, r0)
    mov.l r2, @(24, r0)
    mov.l r2, @(28, r0)
    mov.l r1, @(32, r0)
    mov.l r2, @(36, r0)
    mov.l r2, @(40, r0)
    rts
    mov.l r2, @(44, r0)

    .global sym_06026E2E
sym_06026E2E:
    mov.l   .L_pool_06027070, r0
    mov.l   .L_pool_06027068, r1
    mov.l r4, @(0, r0)
    mov.l r5, @(4, r0)
    mov.l r6, @(8, r0)
    mov.l @r1, r4
    mov #0x3, r3
    mov r4, r5
    add #0x24, r5
.L_06026E40:
    clrmac
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mov.l @r5, r6
    add #-0xC, r0
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    add r6, r2
    mov.l r2, @r5
    bf/s    .L_06026E40
    add #0x4, r5
    rts
    nop


    .global FUN_06026E60
    .type FUN_06026E60, @function
FUN_06026E60:
    mov.l   .L_pool_06027068, r0
    mov.l @r0, r7
    mov #0x3, r3
.L_06026E66:
    mov.l @(0, r7), r0
    dmuls.l r0, r4
    mov.l @(12, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r5
    mov.l r2, @(0, r7)
    mov.l @(24, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r6
    mov.l r2, @(12, r7)
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    mov.l r2, @(24, r7)
    bf/s    .L_06026E66
    add #0x4, r7
    rts
    nop

/* FUN_06026E94 -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06026E94 - 0x06026EDE
 * Auto-generated by tools/generate_l3_tu.py
 *
 * VERIFIED: X-axis rotation (YZ plane). Same structure as FUN_06026EDE / FUN_06026F2A.
 * Method: code audit — calls sincos with r5=#0x8 (X offset), applies 2x2 rotation
 *         to matrix columns 1,2. Only 38 instructions, trivially verifiable.
 * Date: 2026-02-28
 */



    .global FUN_06026E94
    .type FUN_06026E94, @function
FUN_06026E94:
    sts.l pr, @-r15
    mov.l   .L_pool_06027070, r6
    mov #0x8, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    mov.l   .L_pool_06027068, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
    add #0x4, r4
.L_06026EB2:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    add #-0x8, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf/s    .L_06026EB2
    add #0xC, r4
    rts
    nop


    .global FUN_06026EDE
    .type FUN_06026EDE, @function
FUN_06026EDE:
    sts.l pr, @-r15
    mov.l   .L_pool_06027070, r6
    mov #0x4, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(8, r6)
    mov.l   .L_pool_06027068, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_06026EFA:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    add #-0xC, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(8, r4)
    bf/s    .L_06026EFA
    add #0xC, r4
    rts
    nop

    .global FUN_06026F2A
    .type FUN_06026F2A, @function
FUN_06026F2A:
    sts.l pr, @-r15
    mov.l   .L_pool_06027070, r6
    mov #0x8, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    mov.l   .L_pool_06027068, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_06026F46:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf/s    .L_06026F46
    add #0xC, r4
    rts
    nop

    .global sym_06026F72
sym_06026F72:
    mov.l   .L_pool_06027068, r0
    mov.l   .L_pool_06027074, r6
    mov.l @r0, r5
    mov #0x3, r3
.L_06026F7A:
    mov #0x3, r2
.L_06026F7C:
    clrmac
    mac.l @r4+, @r5+
    add #0x8, r4
    mac.l @r4+, @r5+
    add #0x8, r4
    dt r2
    mac.l @r4+, @r5+
    add #-0x18, r4
    add #-0xC, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @r6
    bf/s    .L_06026F7C
    add #0x4, r6
    add #-0xC, r4
    dt r3
    bf/s    .L_06026F7A
    add #0xC, r5
    mov r5, r7
    add #-0x24, r5
    add #0x24, r4
    mov #0x3, r3
.L_06026FAA:
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    dt r3
    mac.l @r4+, @r5+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l @r7+, r0
    add r0, r1
    mov.l r1, @r6
    bf/s    .L_06026FAA
    add #0x4, r6
    add #-0x30, r6
    add #-0x30, r7
    mov.l @(0, r6), r0
    mov.l @(4, r6), r1
    mov.l @(8, r6), r2
    mov.l @(12, r6), r3
    mov.l @(16, r6), r4
    mov.l @(20, r6), r5
    mov.l r0, @(0, r7)
    mov.l r1, @(4, r7)
    mov.l r2, @(8, r7)
    mov.l r3, @(12, r7)
    mov.l r4, @(16, r7)
    mov.l r5, @(20, r7)
    mov.l @(24, r6), r0
    mov.l @(28, r6), r1
    mov.l @(32, r6), r2
    mov.l @(36, r6), r3
    mov.l @(40, r6), r4
    mov.l @(44, r6), r5
    mov.l r0, @(24, r7)
    mov.l r1, @(28, r7)
    mov.l r2, @(32, r7)
    mov.l r3, @(36, r7)
    mov.l r4, @(40, r7)
    rts
    mov.l r5, @(44, r7)

    .global FUN_06026FFC
    .type FUN_06026FFC, @function
FUN_06026FFC:
    mov.l r14, @-r15
    mov.l   .L_pool_06027068, r0
    mov #0x24, r7
    mov.l @r0, r6
    mov.l   .L_pool_06027078, r14
    add r6, r7
    mov #0x3, r3
.L_0602700A:
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    dt r3
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @r14
    bf/s    .L_0602700A
    add #0x4, r14
    add #-0xC, r14
    mov.l @r14+, r0
    mov.l @r14+, r1
    mov.l @r14+, r2
    mov.l r0, @r5
    mov.l r1, @(4, r5)
    mov.l r2, @(8, r5)
    rts
    mov.l @r15+, r14

    .4byte  0xD00BD60F
    .4byte  0x6202E303
    .4byte  0x0028024F
    .4byte  0x024F024F
    .4byte  0x431074F4
    .4byte  0x000A011A
    .4byte  0x210D2612
    .4byte  0x8FF47604
    .4byte  0x76F46062
    .4byte  0x51615262
    .4byte  0x25021511
    .4byte  0x000B1522
.L_pool_06027068:
    .4byte  sym_06089EDC
.L_pool_0602706C:
    .4byte  sym_06089EE0
.L_pool_06027070:
    .4byte  sym_0608A4E0
.L_pool_06027074:
    .4byte  sym_0608A4F0
.L_pool_06027078:
    .4byte  sym_0608A520
.L_pool_0602707C:
    .4byte  0x00010000

    .global sym_06027080
sym_06027080:
    mov.l   .L_pool_0602732C, r3
    mov.l @r3, r0
    mov #0x30, r1
    add r0, r1
    mov.l r1, @r3
    mov.l @(0, r0), r2
    mov.l @(4, r0), r3
    mov.l r2, @(0, r1)
    mov.l r3, @(4, r1)
    mov.l @(8, r0), r2
    mov.l @(12, r0), r3
    mov.l r2, @(8, r1)
    mov.l r3, @(12, r1)
    mov.l @(16, r0), r2
    mov.l @(20, r0), r3
    mov.l r2, @(16, r1)
    mov.l r3, @(20, r1)
    mov.l @(24, r0), r2
    mov.l @(28, r0), r3
    mov.l r2, @(24, r1)
    mov.l r3, @(28, r1)
    mov.l @(32, r0), r2
    mov.l @(36, r0), r3
    mov.l r2, @(32, r1)
    mov.l r3, @(36, r1)
    mov.l @(40, r0), r2
    mov.l @(44, r0), r3
    mov.l r2, @(40, r1)
    rts
    mov.l r3, @(44, r1)

    .4byte  0xD19B6012
    .4byte  0x70D0000B
    .2byte  0x2102

    .global sym_060270C6
sym_060270C6:
    .byte   0xD0, 0x9A    /* mov.l .L_pool_06027330, r0 */
    mov.l   .L_pool_0602732C, r1
    mov #0x0, r2
    bra     .L_060270D6
    mov.l r0, @r1

    .global sym_060270D0
sym_060270D0:
    mov.l   .L_pool_0602732C, r0
    mov #0x0, r2
    mov.l @r0, r0
.L_060270D6:
    .byte   0xD1, 0x9A    /* mov.l .L_pool_06027340, r1 */
    mov.l r2, @(4, r0)
    mov.l r1, @(0, r0)
    mov.l r2, @(8, r0)
    mov.l r2, @(12, r0)
    mov.l r1, @(16, r0)
    mov.l r2, @(20, r0)
    mov.l r2, @(24, r0)
    mov.l r2, @(28, r0)
    mov.l r1, @(32, r0)
    mov.l r2, @(36, r0)
    mov.l r2, @(40, r0)
    rts
    mov.l r2, @(44, r0)

    .global sym_060270F2
sym_060270F2:
    .byte   0xD0, 0x90    /* mov.l .L_pool_06027334, r0 */
    mov.l   .L_pool_0602732C, r1
    mov.l r4, @(0, r0)
    mov.l r5, @(4, r0)
    mov.l r6, @(8, r0)
    mov.l @r1, r4
    mov #0x3, r3
    mov r4, r5
    add #0x24, r5
.L_06027104:
    clrmac
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mov.l @r5, r6
    add #-0xC, r0
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    add r6, r2
    mov.l r2, @r5
    bf/s    .L_06027104
    add #0x4, r5
    rts
    nop

    .global FUN_06027124
    .type FUN_06027124, @function
FUN_06027124:
    mov.l   .L_pool_0602732C, r0
    mov.l @r0, r7
    mov #0x3, r3
.L_0602712A:
    mov.l @(0, r7), r0
    dmuls.l r0, r4
    mov.l @(12, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r5
    mov.l r2, @(0, r7)
    mov.l @(24, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r6
    mov.l r2, @(12, r7)
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    mov.l r2, @(24, r7)
    bf/s    .L_0602712A
    add #0x4, r7
    rts
    nop

    .global FUN_06027158
    .type FUN_06027158, @function
FUN_06027158:
    sts.l pr, @-r15
    .byte   0xD6, 0x76    /* mov.l .L_pool_06027334, r6 */
    mov #0x8, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    mov.l   .L_pool_0602732C, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
    add #0x4, r4
.L_06027176:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    add #-0x8, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf/s    .L_06027176
    add #0xC, r4
    rts
    nop


    .global FUN_060271A2
    .type FUN_060271A2, @function
FUN_060271A2:
    sts.l pr, @-r15
    .byte   0xD6, 0x63    /* mov.l .L_pool_06027334, r6 */
    mov #0x4, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(8, r6)
    mov.l   .L_pool_0602732C, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_060271BE:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    add #-0xC, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(8, r4)
    bf/s    .L_060271BE
    add #0xC, r4
    rts
    nop

    .global FUN_060271EE
    .type FUN_060271EE, @function
FUN_060271EE:
    sts.l pr, @-r15
    .byte   0xD6, 0x50    /* mov.l .L_pool_06027334, r6 */
    mov #0x8, r5
    bsr     FUN_06027358
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    mov.l   .L_pool_0602732C, r0
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_0602720A:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf/s    .L_0602720A
    add #0xC, r4
    rts
    nop
    .2byte  0xD03D
    .4byte  0xD63F6502
    .4byte  0xE303E203
    .4byte  0x0028054F
    .4byte  0x7408054F
    .4byte  0x74084210
    .4byte  0x054F74E8
    .4byte  0x75F4000A
    .4byte  0x011A210D
    .4byte  0x26128FF1
    .4byte  0x760474F4
    .4byte  0x43108FEC
    .4byte  0x750C6753
    .4byte  0x75DC7424
    .4byte  0xE3030028
    .4byte  0x054F054F
    .4byte  0x4310054F
    .4byte  0x74F4000A
    .4byte  0x011A210D
    .4byte  0x6076310C
    .4byte  0x26128FF2
    .4byte  0x760476D0
    .4byte  0x77D05060
    .4byte  0x51615262
    .4byte  0x53635464
    .4byte  0x55651700
    .4byte  0x17111722
    .4byte  0x17331744
    .4byte  0x17555066
    .4byte  0x51675268
    .4byte  0x5369546A
    .4byte  0x556B1706
    .4byte  0x17171728
    .4byte  0x1739174A
    .4byte  0x000B175B

    .global FUN_060272C0
    .type FUN_060272C0, @function
FUN_060272C0:
    mov.l r14, @-r15
    mov.l   .L_pool_0602732C, r0
    mov #0x24, r7
    mov.l @r0, r6
    mov.l   .L_pool_0602733C, r14
    add r6, r7
    mov #0x3, r3
.L_060272CE:
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    dt r3
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @r14
    bf/s    .L_060272CE
    add #0x4, r14
    add #-0xC, r14
    mov.l @r14+, r0
    mov.l @r14+, r1
    mov.l @r14+, r2
    mov.l r0, @r5
    mov.l r1, @(4, r5)
    mov.l r2, @(8, r5)
    rts
    mov.l @r15+, r14

    .4byte  0xD00BD60F
    .4byte  0x6202E303
    .4byte  0x0028024F
    .4byte  0x024F024F
    .4byte  0x431074F4
    .4byte  0x000A011A
    .4byte  0x210D2612
    .4byte  0x8FF47604
    .4byte  0x76F46062
    .4byte  0x51615262
    .4byte  0x25021511
    .4byte  0x000B1522
.L_pool_0602732C:
    .4byte  sym_0608A52C
    .4byte  sym_0608A530
    .4byte  sym_0608A6B0
    .4byte  sym_0608A6C0
.L_pool_0602733C:
    .4byte  sym_0608A6F0
    .4byte  0x00010000

    .global FUN_06027344
FUN_06027344:
    .byte   0x90, 0xDA    /* mov.w .L_wpool_060274FC, r0 ! r0 = 0x4000 (90 deg phase) */
    add r0, r4

    .global FUN_06027348
FUN_06027348:
    .byte   0x90, 0xD9    /* mov.w .L_wpool_060274FE, r0 ! r0 = 0x3FFC (table mask) */
    shlr2 r4
    add #0x2, r4
    and r0, r4
    .byte   0xD0, 0x66    /* mov.l .L_pool_060274EC, r0 ! r0 = 0x002F2F20 (ROM table) */
    rts
    mov.l @(r0, r4), r0
    .2byte  0x0009
    .global FUN_06027358
FUN_06027358:

    .global FUN_06027358
FUN_06027358:
    .byte   0x93, 0xD0    /* mov.w .L_wpool_060274FC, r3 ! r3 = 0x4000 (cos phase) */
    add #0x8, r4
    .byte   0x91, 0xCF    /* mov.w .L_wpool_060274FE, r1 ! r1 = 0x3FFC (table mask) */
    add r4, r3
    .byte   0xD0, 0x62    /* mov.l .L_pool_060274EC, r0 ! r0 = 0x002F2F20 (table base) */
    shlr2 r4
    and r1, r4
    shlr2 r3
    mov.l @(r0, r4), r2
    and r1, r3
    mov.l r2, @r5
    nop
    mov.l @(r0, r3), r1
    rts
    mov.l r1, @r6
    .2byte  0x0009
    .global FUN_06027378
FUN_06027378:

    .global FUN_06027378
FUN_06027378:
    cmp/pz r4
    bt/s    .L_06027380
    .word 0x0629
    neg r4, r4
.L_06027380:
    mov #0x10, r0
    shll16 r0
    add #0x40, r4
    add #0x40, r4
    cmp/hi r4, r0
    bf      .L_0602739C
    .byte   0xD0, 0x58    /* mov.l .L_pool_060274F0, r0 ! r0 = 0x002F0000 (atan ROM table) */
    shlr8 r4
    shll r4
    tst r6, r6
    mov.w @(r0, r4), r0
    bf      .L_0602743E
    rts
    neg r0, r0
.L_0602739C:
    .byte   0x90, 0xBB    /* mov.w .L_wpool_06027516, r0 ! r0 = 0x03E8 (1000) */
    swap.w r4, r5
    extu.w r5, r5
    cmp/hi r5, r0
    bf      .L_06027442
    .byte   0x90, 0xBB    /* mov.w .L_wpool_06027520, r0 ! r0 = 100 (0x0064) */
    cmp/hi r5, r0
    bt      .L_060273E6
    .byte   0x90, 0xBA    /* mov.w .L_wpool_06027524, r0 ! r0 = 250 (0x00FA) */
    cmp/hi r5, r0
    bt      .L_060273CC
    .byte   0x90, 0xB8    /* mov.w .L_wpool_06027526, r0 ! r0 = 500 (0x01F4) */
    cmp/hi r5, r0
    bt      .L_060273C2
    .byte   0x93, 0xB5    /* mov.w .L_wpool_06027526, r3 ! r3 = 500 (segment base) */
    .byte   0xD1, 0x5B    /* mov.l .L_pool_06027528, r1 ! r1 = slope for 500..1000 */
    .byte   0x92, 0xA2    /* mov.w .L_wpool_06027504, r2 ! r2 = intercept */
    bra     .L_0602742E
    swap.w r3, r3
.L_060273C2:
    .byte   0x93, 0xAF    /* mov.w .L_wpool_06027524, r3 ! r3 = 250 (segment base) */
    .byte   0xD1, 0x59    /* mov.l .L_pool_0602752C, r1 ! r1 = slope for 250..500 */
    .byte   0x92, 0x9E    /* mov.w .L_wpool_06027506, r2 ! r2 = intercept */
    bra     .L_0602742E
    swap.w r3, r3
.L_060273CC:
    .byte   0x90, 0xA9    /* mov.w .L_wpool_06027522, r0 ! r0 = 150 (0x0096) */
    cmp/hi r5, r0
    bt      .L_060273DC
    .byte   0x93, 0xA6    /* mov.w .L_wpool_06027522, r3 ! r3 = 150 (segment base) */
    .byte   0xD1, 0x56    /* mov.l .L_pool_06027530, r1 ! r1 = slope for 150..250 */
    .byte   0x92, 0x97    /* mov.w .L_wpool_06027508, r2 ! r2 = intercept */
    bra     .L_0602742E
    swap.w r3, r3
.L_060273DC:
    .byte   0xD1, 0x55    /* mov.l .L_pool_06027534, r1 ! r1 = slope for 100..150 */
    .byte   0x92, 0x94    /* mov.w .L_wpool_0602750A, r2 ! r2 = intercept */
    mov #0x64, r3
    bra     .L_0602742E
    swap.w r3, r3
.L_060273E6:
    .byte   0x90, 0x99    /* mov.w .L_wpool_0602751C, r0 ! r0 = 50 (0x0032) */
    cmp/hi r5, r0
    bt      .L_06027406
    .byte   0x90, 0x97    /* mov.w .L_wpool_0602751E, r0 ! r0 = 70 (0x0046) */
    cmp/hi r5, r0
    bt      .L_060273FC
    .byte   0xD1, 0x51    /* mov.l .L_pool_06027538, r1 ! r1 = slope for 70..100 */
    .byte   0x92, 0x8A    /* mov.w .L_wpool_0602750C, r2 ! r2 = intercept */
    mov #0x46, r3
    bra     .L_0602742E
    swap.w r3, r3
.L_060273FC:
    .byte   0xD1, 0x4F    /* mov.l .L_pool_0602753C, r1 ! r1 = slope for 50..70 */
    .byte   0x92, 0x86    /* mov.w .L_wpool_0602750E, r2 ! r2 = intercept */
    mov #0x32, r3
    bra     .L_0602742E
    swap.w r3, r3
.L_06027406:
    .byte   0x90, 0x87    /* mov.w .L_wpool_06027518, r0 ! r0 = 30 (0x001E) */
    cmp/hi r5, r0
    bt      .L_06027426
    .byte   0x90, 0x85    /* mov.w .L_wpool_0602751A, r0 ! r0 = 40 (0x0028) */
    cmp/hi r5, r0
    bt      .L_0602741C
    .byte   0xD1, 0x4B    /* mov.l .L_pool_06027540, r1 ! r1 = slope for 40..50 */
    .byte   0x92, 0x7C    /* mov.w .L_wpool_06027510, r2 ! r2 = intercept */
    mov #0x28, r3
    bra     .L_0602742E
    swap.w r3, r3
.L_0602741C:
    .byte   0xD1, 0x49    /* mov.l .L_pool_06027544, r1 ! r1 = slope for 30..40 */
    .byte   0x92, 0x78    /* mov.w .L_wpool_06027512, r2 ! r2 = intercept */
    mov #0x1E, r3
    bra     .L_0602742E
    swap.w r3, r3
.L_06027426:
    .byte   0xD1, 0x48    /* mov.l .L_pool_06027548, r1 ! r1 = slope for 16..30 */
    .byte   0x92, 0x74    /* mov.w .L_wpool_06027514, r2 ! r2 = intercept */
    mov #0x10, r3
    swap.w r3, r3
.L_0602742E:
    sub r3, r4
    dmuls.l r4, r1
    sts mach, r0
    exts.w r0, r0
    tst r6, r6
    bf/s    .L_0602743E
    add r2, r0
    neg r0, r0
.L_0602743E:
    rts
    nop
.L_06027442:
    .byte   0x90, 0x5B    /* mov.w .L_wpool_060274FC, r0 ! r0 = 0x4000 (max atan = 90 deg) */
    tst r6, r6
    bf      .L_0602743E
    rts
    neg r0, r0

    .global FUN_0602744C
FUN_0602744C:
    tst r5, r5
    .byte   0x8B, 0x05    /* bf 0x0602745C */
    .byte   0x90, 0x54    /* mov.w .L_wpool_060274FC, r0 ! r0 = 0x4000 (90 degrees) */
    cmp/pz r4
    bt      .L_06027458
    neg r0, r0
.L_06027458:
    rts
    nop

    .global FUN_0602745C
    .type FUN_0602745C, @function
FUN_0602745C:
    sts.l pr, @-r15
    cmp/pz r5
    bsr     FUN_0602755C
    .word 0x0729
    bsr     FUN_06027378
    mov r0, r4
    lds.l @r15+, pr
    tst r7, r7
    bf      .L_06027472
    .byte   0xD2, 0x21    /* mov.l .L_pool_060274F4, r2 ! r2 = 0x8000 (180 degrees) */
    add r2, r0
.L_06027472:
    rts
    exts.w r0, r0

    .global FUN_06027476
FUN_06027476:
    .global FUN_06027476
FUN_06027476:
    cmp/pl r4
    bf/s    .L_06027494
    mov #0x0, r0
    .byte   0xD2, 0x1D    /* mov.l .L_pool_060274F4, r2 ! r2 = 0x8000 (initial bit = MSB) */
.L_0602747E:
    add r2, r0
    mul.l r0, r0
    sts macl, r3
    cmp/eq r4, r3
    bt      .L_06027494
    cmp/hi r4, r3
    bf      .L_0602748E
    sub r2, r0
.L_0602748E:
    shlr r2
    cmp/pl r2
    bt      .L_0602747E
.L_06027494:
    rts
    shll8 r0

    .global FUN_06027498
    .type FUN_06027498, @function
FUN_06027498:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    bsr     .L_060274DA
    mov r4, r5
    bsr     FUN_06027476
    mov r0, r4
    cmp/pl r0
    bf      .L_060274D4
    mov.l   .L_060274F8, r4
    bsr     FUN_0602755C
    mov r0, r5
    mov.l @(0, r14), r1
    mov.l @(4, r14), r2
    dmuls.l r0, r1
    mov.l @(8, r14), r3
    sts mach, r4
    sts macl, r1
    xtrct r4, r1
    dmuls.l r0, r2
    mov.l r1, @(0, r14)
    sts mach, r4
    sts macl, r2
    xtrct r4, r2
    dmuls.l r0, r3
    mov.l r2, @(4, r14)
    sts mach, r4
    sts macl, r3
    xtrct r4, r3
    mov.l r3, @(8, r14)
.L_060274D4:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060274DA:
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    rts
    xtrct r1, r0
    .2byte  0x0009
    .4byte  0x002F2F20
    .4byte  0x002F0000
    .4byte  0x00008000
.L_060274F8:
    .4byte  0x00010000
    .4byte  0x40003FFC
    .4byte  0x0FFC4000
    .4byte  0x3FEB3FD6
    .4byte  0x3FBA3F97
    .4byte  0x3F6A3F2F
    .4byte  0x3EFB3EA4
    .4byte  0x3D7403E8
    .4byte  0x001E0028
    .4byte  0x00320046
    .4byte  0x00640096
    .4byte  0x00FA01F4
    .4byte  0x00000AC0
    .4byte  0x00001581
    .4byte  0x000047AE
    .4byte  0x0000B333
    .4byte  0x00018000
    .4byte  0x0002F333
    .4byte  0x00053333
    .4byte  0x0008B333
    .4byte  0x0015B6DB

    .global FUN_0602754C
FUN_0602754C:
    swap.w r4, r0
    rts
    exts.w r0, r0


    .global FUN_06027552
    .type FUN_06027552, @function
FUN_06027552:
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    rts
    xtrct r4, r0
    .global FUN_0602755C
FUN_0602755C:

    .global FUN_0602755C
FUN_0602755C:
    mov.w   .L_06027570, r2
    mov r4, r3
    mov.l r5, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    rts
    mov.l @(28, r2), r0
.L_06027570:
    .2byte  0xFF00
    .2byte  0x0000

    .global FUN_06027574
FUN_06027574:
    cmp/eq r4, r5
    bt      .L_06027592
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_06027592
    cmp/hi r4, r5
    bt      .L_06027596
    add r6, r5
    add r6, r4
    add #-0x1, r5
.L_06027588:
    mov.b @r5, r7
    dt r6
    mov.b r7, @-r4
    bf/s    .L_06027588
    add #-0x1, r5
.L_06027592:
    rts
    nop
.L_06027596:
    mov.b @r5+, r7
    dt r6
    mov.b r7, @r4
    bf/s    .L_06027596
    add #0x1, r4
    rts
    nop

    .global FUN_060275A4
FUN_060275A4:
    cmp/eq r4, r5
    bt      .L_060275C6
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275C6
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .L_060275CA
    shlr r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.L_060275BC:
    mov.w @r5, r7
    dt r6
    mov.w r7, @-r4
    bf/s    .L_060275BC
    add #-0x2, r5
.L_060275C6:
    rts
    nop
.L_060275CA:
    mov.w @r5+, r7
    dt r6
    mov.w r7, @r4
    bf/s    .L_060275CA
    add #0x2, r4
    rts
    nop

    .global FUN_060275D8
FUN_060275D8:
    cmp/eq r4, r5
    bt      .L_060275FA
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275FA
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .L_060275FE
    shlr2 r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.L_060275F0:
    mov.l @r5, r7
    dt r6
    mov.l r7, @-r4
    bf/s    .L_060275F0
    add #-0x4, r5
.L_060275FA:
    rts
    nop
.L_060275FE:
    mov.l @r5+, r7
    dt r6
    mov.l r7, @r4
    bf/s    .L_060275FE
    add #0x4, r4
    rts
    nop

    .global FUN_0602760C
FUN_0602760C:
    mov #0x0, r0
    add #-0x1, r6
.L_06027610:
    mov.b @(r0, r5), r1
    cmp/gt r0, r6
    mov.b r1, @(r0, r4)
    bt/s    .L_06027610
    add #0x1, r0
    rts
    add #0x1, r6

    .global FUN_0602761E
FUN_0602761E:
    mov #0x0, r0
    add #-0x2, r6
.L_06027622:
    mov.w @(r0, r5), r1
    cmp/gt r0, r6
    mov.w r1, @(r0, r4)
    bt/s    .L_06027622
    add #0x2, r0
    rts
    add #0x2, r6

    .global FUN_06027630
FUN_06027630:
    mov #0x0, r0
    add #-0x4, r6
.L_06027634:
    mov.l @(r0, r5), r1
    cmp/gt r0, r6
    mov.l r1, @(r0, r4)
    bt/s    .L_06027634
    add #0x4, r0
    rts
    add #0x4, r6

    .global FUN_06027642
FUN_06027642:
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(0, r4)
    mov.l r1, @(4, r4)
    mov.l r2, @(8, r4)
    mov.l r3, @(12, r4)
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(16, r4)
    mov.l r1, @(20, r4)
    mov.l r2, @(24, r4)
    mov.l r3, @(28, r4)
    dt r6
    bf/s    FUN_06027642
    add #0x20, r4
    rts
    nop

    .global FUN_0602766C
FUN_0602766C:
    mov.l   .L_0602768C, r0
    mov.l @r0, r0
    mov.l   .L_06027690, r1
    tst r1, r0
    bf      FUN_0602766C
    mov.l   .L_06027694, r1
    mov.w   .L_0602768A, r2
    mov.l r4, @(4, r1)
    mov.l r5, @(0, r1)
    mov.l r6, @(8, r1)
    mov.l r2, @(12, r1)
    mov #0x7, r0
    mov.l r0, @(20, r1)
    rts
    mov.l r2, @(16, r1)
.L_0602768A:
    .2byte  0x0101
.L_0602768C:
    .4byte  0x25FE007C
.L_06027690:
    .4byte  0x0000272E
.L_06027694:
    .4byte  0x25FE0000
    .4byte  0x00090000

    .global FUN_0602769C
FUN_0602769C:
    mov.w   .L_060276C0, r1
    mov.w   .L_060276CA, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r0
    mov.l @r4, r2
    neg r0, r0
    mov.l @(28, r1), r4
    dmuls.l r2, r4
    sts mach, r2
    dmuls.l r0, r4
    mov.w r2, @r5
    sts mach, r0
    rts
    mov.w r0, @(2, r5)
.L_060276C0:
    .2byte  0xFF00
    .2byte  0x0009
    .4byte  0x00010000
    .2byte  0xFF00
.L_060276CA:
    .2byte  0x00A0
