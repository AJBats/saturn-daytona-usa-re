	.text
    .global vtx_transform_full
vtx_transform_full:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov r14, r0
    mov.l @(0, r0), r10
    mov.l   .L_0602D958, r11
    tst r10, r11
    bt      .L_0602D95C
    add r1, r5
    bra     .L_0602D95E
    nop
    .short  0x024C
    .long  0x0000000F
    .long  sym_0602ECCC
.L_0602D958:
    .long  0x00000300
.L_0602D95C:
    sub r1, r5
.L_0602D95E:
    mov.l r5, @(48, r0)
    mov.l r5, @(32, r0)
    mov.w   .L_0602D9D0, r1
    mov.l @(r0, r1), r4
    mov.l r4, @(40, r0)
    neg r4, r4
    mov.w   .L_0602D9D2, r1
    mov.w @(r0, r1), r2
    mov.l   .L_0602D9D4, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r5
    mov.l @(12, r0), r2
    dmuls.l r2, r5
    mov.l @(8, r0), r7
    sts mach, r2
    sts macl, r5
    xtrct r2, r5
    mov.l r5, @(12, r0)
    mov #0x28, r2
    cmp/gt r2, r7
    bt      .L_0602D98C
    mov.l   .L_0602D9D8, r5
.L_0602D98C:
    mov.l @(16, r0), r6
    mov.l @(24, r0), r7
    mov.l r6, @(56, r0)
    mov.l r7, @(60, r0)
    mov r4, r9
    mov r5, r1
    mov.l   .L_0602D9DC, r0
    jsr @r0
    nop
    mov r0, r8
    mov r9, r4
    mov.l   .L_0602D9E0, r0
    jsr @r0
    nop
    dmuls.l r0, r5
    mov r14, r0
    mov.l   .L_0602D9E4, r10
    sts mach, r11
    sts macl, r5
    xtrct r11, r5
    mov.l r5, @(r0, r10)
    add r5, r6
    mov.l r6, @(16, r0)
    dmuls.l r8, r1
    mov.l   .L_0602D9E8, r10
    sts mach, r8
    sts macl, r1
    xtrct r8, r1
    mov.l r1, @(r0, r10)
    add r1, r7
    mov.l r7, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
.L_0602D9D0:
    .short  0x0248
.L_0602D9D2:
    .short  0x0250
.L_0602D9D4:
    .long  sym_0602E8B8
.L_0602D9D8:
    .long  0x00006AAA
.L_0602D9DC:
    .long  cos_lookup
.L_0602D9E0:
    .long  sin_lookup
.L_0602D9E4:
    .long  0x0000018C
.L_0602D9E8:
    .long  0x00000190
    .long  0x000B0009

    .global sym_0602D9F0
sym_0602D9F0:
    mov.l   .L_0602DAB0, r0
    mov.l @r0, r0
    mov.l   .L_0602DAB4, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.l   .L_0602DAB8, r4
    mov.l @(r0, r4), r4
    cmp/ge r3, r4
    bt      .L_0602DA8E
    mov.l   .L_0602DABC, r3
    mov.l @r3, r3
    mov.l   .L_0602DAC0, r4
    cmp/eq r4, r3
    bf      .L_0602DA16
    mov.l   .L_0602DAC4, r1
    mov.l @(r0, r1), r3
    mov.l   .L_0602DAC8, r4
    cmp/ge r4, r3
    bt      .L_0602DA8E
.L_0602DA16:
    mov.l   .L_0602DACC, r1
    mov.l @(r0, r1), r1
    mov.l   .L_0602DAD0, r3
    cmp/eq r3, r1
    bf      .L_0602DA8E
    mov.w   .L_0602DA98, r1
    mov.w @(r0, r1), r3
    mov.w   .L_0602DA9A, r1
    mov.w @(r0, r1), r4
    mov.w   .L_0602DA9C, r1
    mov.l @(r0, r1), r5
    or r3, r4
    or r4, r5
    tst r5, r5
    bf      .L_0602DA8E
    mov.w   .L_0602DA9E, r1
    add r0, r1
    mov.l @(0, r1), r2
    mov.l @(4, r1), r3
    mov.l @(8, r1), r4
    mov.l @(12, r1), r5
    mov.w   .L_0602DAA0, r6
    and r2, r3
    and r4, r5
    and r3, r5
    cmp/eq r5, r6
    bf      .L_0602DA8E
    mov.l   .L_0602DAD4, r0
    mov.l @r0, r0
    mov.w   .L_0602DAA2, r1
    mov.l @(r0, r1), r4
    mov.l @(40, r0), r3
    sub r4, r3
    exts.w r3, r3
    mov.w   .L_0602DAA4, r5
    add r5, r3
    mov.w   .L_0602DAA6, r5
    cmp/ge r3, r5
    bt      .L_0602DA8E
    mov.w   .L_0602DAA8, r5
    cmp/ge r3, r5
    bf      .L_0602DA8E
    mov.l @(0, r0), r2
    mov.l   .L_0602DAD8, r3
    tst r3, r2
    bf      .L_0602DAEC
    mov.l   .L_0602DADC, r1
    mov.b @r1, r1
    tst r1, r1
    bf      .L_0602DAEC
    mov.l @(0, r0), r2
    mov.l   .L_0602DAE0, r3
    or r3, r2
    mov.l r2, @(0, r0)
    mov.l   .L_0602DAE4, r1
    mov.w   .L_0602DAAA, r2
    mov.l r2, @r1
    mov.l   .L_0602DAE8, r1
    mov.w   .L_0602DAAC, r2
    mov.l r2, @r1
.L_0602DA8E:
    mov.l   .L_0602DADC, r1
    mov.l   .L_0602DAD0, r2
    mov.b r2, @r1
    rts
    nop
.L_0602DA98:
    .short  0x0150
.L_0602DA9A:
    .short  0x0250
.L_0602DA9C:
    .short  0x00B8
.L_0602DA9E:
    .short  0x0120
.L_0602DAA0:
    .short  0x0041
.L_0602DAA2:
    .short  0x025C
.L_0602DAA4:
    .short  0x3FFF
.L_0602DAA6:
    .short  0x2800
.L_0602DAA8:
    .short  0x47FF
.L_0602DAAA:
    .short  0x003C
.L_0602DAAC:
    .short  0x0001
    .short  0x0000
.L_0602DAB0:
    .long  sym_0607E944
.L_0602DAB4:
    .long  sym_06063F28
.L_0602DAB8:
    .long  0x00000228
.L_0602DABC:
    .long  sym_0607EAD8
.L_0602DAC0:
    .long  0x00000001
.L_0602DAC4:
    .long  0x00000018
.L_0602DAC8:
    .long  0xFF000000
.L_0602DACC:
    .long  0x000001BC
.L_0602DAD0:
    .long  0x00000000
.L_0602DAD4:
    .long  sym_0607E940
.L_0602DAD8:
    .long  0x00000008
.L_0602DADC:
    .long  sym_06083260
.L_0602DAE0:
    .long  0x00020000
.L_0602DAE4:
    .long  sym_0607EAC8
.L_0602DAE8:
    .long  sym_0605A1C4
.L_0602DAEC:
    mov.l   .L_0602DAF8, r1
    mov.l   .L_0602DAFC, r2
    mov.b r2, @r1
    rts
    nop
    .short  0x0000
.L_0602DAF8:
    .long  sym_06083260
.L_0602DAFC:
    .long  0xFFFFFFFF

    .global sym_0602DB00
sym_0602DB00:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
