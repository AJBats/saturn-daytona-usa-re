
    .section .text.FUN_0602CCEC


    .global vdp1_attr_setup
    .type vdp1_attr_setup, @function
vdp1_attr_setup:
    sts.l pr, @-r15
    mov #0x0, r7
    mov.l @(8, r14), r3
    cmp/pl r3
    bf      .L_0602CD9A
    mov.w   .L_0602CDB6, r5
    mov.w   .L_0602CDB8, r1
    shll16 r5
    mov.l @(r0, r1), r3
    shll16 r3
    mov r5, r4
    sub r3, r4
    mov.w   .L_0602CDBA, r2
    mov.l   .L_0602CDCC, r13
    jsr @r13
    mov.l @(r0, r2), r6
    dmuls.l r0, r6
    mov.w   .L_0602CDBC, r1
    mov.w   .L_0602CDBE, r2
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    add r14, r1
    add r14, r2
    mov.l @r1, r5
    mov.l @r2, r6
    dmuls.l r6, r5
    sts mach, r6
    sts macl, r5
    xtrct r6, r5
    mov.w   .L_0602CDC0, r1
    add r14, r1
    jsr @r13
    mov.w @r1, r7
    mov.w   .L_0602CDC2, r4
    mov.l   .L_0602CDD0, r1
    add r14, r4
    mov.w @r4, r4
    mov #0xA, r5
    cmp/ge r5, r4
    bt      .L_0602CD4A
    mov #0x2, r5
    cmp/eq r5, r4
    bt      .L_0602CD4A
    add #0x1, r5
    cmp/eq r5, r4
    bf      .L_0602CD50
.L_0602CD4A:
    mov #0x2, r5
    cmp/ge r7, r5
    bt      .L_0602CD9A
.L_0602CD50:
    shll2 r4
    shll r7
    shll r4
    add r1, r7
    add r4, r7
    mov.w @r7, r4
    mov #0x0, r7
    extu.w r4, r4
    mov r0, r5
    mov.l r4, @-r15
    jsr @r13
    mov.l r5, @-r15
    mov.w   .L_0602CDC4, r1
    add r14, r1
    mov.l r0, @r1
    mov.l @r15+, r5
    mov.l @r15+, r4
    cmp/gt r5, r4
    bt      .L_0602CD9A
    .byte   0xB5, 0x35    /* bsr 0x0602D7E4 (external) */
    mov r14, r0
    mov.w   .L_0602CDC6, r1
    add r14, r1
    mov.w @r1, r2
    cmp/pl r2
    bt      .L_0602CD9A
    mov.w   .L_0602CDB8, r1
    add r14, r1
    mov.l @r1, r7
    mov r7, r4
    mov.l   .L_0602CDD4, r5
    shll r7
    shll16 r4
    mov.w   .L_0602CDC8, r6
    jsr @r13
    add r14, r6
    mov.l r0, @r6
.L_0602CD9A:
    mov r14, r0
    mov.w   .L_0602CDBC, r1
    mov.w   .L_0602CDC8, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    sub r4, r3
    mov #0x1, r5
    mov.w   .L_0602CDCA, r6
    shll16 r5
    cmp/gt r6, r3
    bt      .L_0602CDD8
    mov r6, r3
    bra     .L_0602CDDE
    nop
.L_0602CDB6:
    .2byte  0x2134
.L_0602CDB8:
    .2byte  0x00E0
.L_0602CDBA:
    .2byte  0x011C
.L_0602CDBC:
    .2byte  0x010C
.L_0602CDBE:
    .2byte  0x0144
.L_0602CDC0:
    .2byte  0x00DC
.L_0602CDC2:
    .2byte  0x007C
.L_0602CDC4:
    .2byte  0x0264
.L_0602CDC6:
    .2byte  0x016C
.L_0602CDC8:
    .2byte  0x0110
.L_0602CDCA:
    .2byte  0x2B85
.L_0602CDCC:
    .4byte  fpdiv_setup
.L_0602CDD0:
    .4byte  sym_0602E938
.L_0602CDD4:
    .4byte  0x23280000
.L_0602CDD8:
    cmp/ge r3, r5
    bt      .L_0602CDDE
    mov r5, r3
.L_0602CDDE:
    cmp/pz r4
    bf      .L_0602CDE8
    mov.w   .L_0602CDF2, r5
    sub r5, r4
    mov.l r4, @(r0, r2)
.L_0602CDE8:
    mov.l r3, @(r0, r1)
    mov.w   .L_0602CDF4, r2
    lds.l @r15+, pr
    rts
    mov.l r7, @(r0, r2)
.L_0602CDF2:
    .2byte  0x05C2
.L_0602CDF4:
    .2byte  0x00C0
