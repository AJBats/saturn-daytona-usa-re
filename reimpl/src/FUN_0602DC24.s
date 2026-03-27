
    .section .text.FUN_0602DC24


    .global FUN_0602DC24
    .type FUN_0602DC24, @function
FUN_0602DC24:
    mov.l r14, @-r15
    .global FUN_0602DC26
FUN_0602DC26:
    mov.l   .L_pool_0602DC3C, r0
    mov.l @r0, r0
    shll2 r0
    mov.l   .L_pool_0602DC40, r1
    mov.l @(r0, r1), r0


    .global FUN_0602DC30
    .type FUN_0602DC30, @function
FUN_0602DC30:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    bra     FUN_0602E16C
    nop
.L_pool_0602DC3C:
    .4byte  sym_06082A30
.L_pool_0602DC40:
    .4byte  sym_0602DC44

    .global sym_0602DC44
sym_0602DC44:
    .4byte  FUN_0602DC58
    .4byte  FUN_0602DD10
    .4byte  FUN_0602DE60
    .4byte  FUN_0602E078
    .4byte  FUN_0602E108

    .global FUN_0602DC58
FUN_0602DC58:
    mov.l   .L_pool_0602DC9C, r1
    mov.l @r1, r3
    add #0x1, r3
    mov.l r3, @r1
    mov.l   .L_pool_0602DCA0, r4
    cmp/eq r3, r4
    .byte   0x8B, 0x08    /* bf 0x0602DC78 (external) */
    mov.l   .L_pool_0602DCA4, r13

    .global FUN_0602DC68
    .type FUN_0602DC68, @function
FUN_0602DC68:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602DCA8, r1
    mov.l   .L_0602DCAC, r0
    mov.b r0, @r1
    mov.l   .L_0602DCB0, r1
    mov.l   .L_0602DCB4, r2
    add r2, r1
    mov.l @r1, r2
    mov.l   .L_0602DCB8, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0602DCBC, r0
    mov.l @(r0, r3), r0
    cmp/gt r2, r0
    bf      .L_0602DCC4
    mov.l   .L_0602DCC0, r3
    add r3, r2
    cmp/gt r2, r0
    bf      .L_0602DCC4
    mov.l r2, @r1
    bra     .L_0602DCC6
    nop
.L_pool_0602DC9C:
    .4byte  sym_06082A2C
.L_pool_0602DCA0:
    .4byte  0x00000028
.L_pool_0602DCA4:
    .4byte  FUN_060321C0
.L_0602DCA8:
    .4byte  sym_06082A26
.L_0602DCAC:
    .4byte  0x00000001
.L_0602DCB0:
    .4byte  sym_06063EEC
.L_0602DCB4:
    .4byte  0x00000004
.L_0602DCB8:
    .4byte  sym_0607EAD8
.L_0602DCBC:
    .4byte  sym_0602ECAC
.L_0602DCC0:
    .4byte  0x00000100
.L_0602DCC4:
    mov.l r0, @r1
.L_0602DCC6:
    mov.l   .L_0602DCEC, r0
    mov.l @r0, r0
    mov.l   .L_0602DCF0, r1
    mov.l @(r0, r1), r4
    mov.l   .L_0602DCF4, r1
    cmp/eq r1, r4
    bf      .L_0602DCE6
    mov.l   .L_0602DCF8, r4
    mov.l   .L_0602DCFC, r1
    mov.b r1, @r4
    mov.l   .L_0602DD00, r4
    mov.l   .L_0602DD04, r1
    mov.b r1, @r4
    mov.l   .L_0602DD08, r4
    mov.l   .L_0602DD0C, r1
    mov.l r1, @r4
.L_0602DCE6:
    rts
    nop
    .2byte  0x0000
.L_0602DCEC:
    .4byte  sym_0607E940
.L_0602DCF0:
    .4byte  0x00000008
.L_0602DCF4:
    .4byte  0x00000000
.L_0602DCF8:
    .4byte  sym_06082A24
.L_0602DCFC:
    .4byte  0xFFFFFFFF
.L_0602DD00:
    .4byte  sym_06082A26
.L_0602DD04:
    .4byte  0x00000002
.L_0602DD08:
    .4byte  sym_06082A30
.L_0602DD0C:
    .4byte  0x00000001
    .global FUN_0602DD10
FUN_0602DD10:

    .global FUN_0602DD10
FUN_0602DD10:
    mov.l   .L_0602DD40, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0602DD44, r0
    mov.l @(r0, r3), r1
    mov.l   .L_0602DD48, r0
    mov.l @r0, r0
    shll2 r0
    shll2 r0
    shll r0
    add r0, r1
    mov.l @r1+, r3
    mov.l   .L_0602DD4C, r0
    cmp/eq r0, r3
    bf      .L_0602DD5C
    mov.l   .L_0602DD48, r1
    mov.l   .L_0602DD50, r0
    mov.l r0, @r1
    mov.l   .L_0602DD54, r0
    mov.l   .L_0602DD58, r1
    mov.l r1, @r0
    rts
    nop
    .2byte  0x0000
.L_0602DD40:
    .4byte  sym_0607EAD8
.L_0602DD44:
    .4byte  sym_0602ECBC
.L_0602DD48:
    .4byte  sym_06082A38
.L_0602DD4C:
    .4byte  0xFFFFFFFF
.L_0602DD50:
    .4byte  0x00000000
.L_0602DD54:
    .4byte  sym_06082A30
.L_0602DD58:
    .4byte  0x00000003
.L_0602DD5C:
    mov.l   .L_pool_0602DE78, r0
    mov.l   .L_pool_0602DE7C, r2
    mov.l r2, @r0
    mov.l   .L_pool_0602DE80, r2
    mov.l r3, @r2
    mov.l @r1+, r4
    mov.l   .L_0602DE84, r2
    mov.l r4, @r2
    mov.l @r1+, r0
    mov.l   .L_pool_0602DE88, r2
    mov.l r0, @r2
    mov.l @r1+, r0
    mov.l   .L_pool_0602DE8C, r2
    mov.l r0, @r2
    mov.l @r1+, r0
    mov.l   .L_pool_0602DE90, r2
    mov.l r0, @r2
    mov.l @r1+, r0
    mov.l   .L_pool_0602DE94, r2
    mov.l r0, @r2
    mov.l @r1+, r0
    mov.l   .L_pool_0602DE98, r2
    mov.l r0, @r2
    mov r3, r0
    mov.l   .L_pool_0602DE9C, r1
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DDB4 (external) */
    mov.l   .L_pool_0602DE88, r1
    mov.l @r1, r1
    mov.l   .L_pool_0602DEA0, r0
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    mov.l   .L_pool_0602DEA4, r12

    .global FUN_0602DDA0
    .type FUN_0602DDA0, @function
FUN_0602DDA0:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602DEA8, r0
    cmp/ge r0, r1
    bt      .L_0602DDB0
    neg r1, r1
.L_0602DDB0:
    mov.l   .L_pool_0602DEAC, r0
    mov.l r1, @r0
    mov r3, r0
    mov.l   .L_pool_0602DEB0, r1
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DDDE (external) */
    mov.l   .L_pool_0602DE8C, r1
    mov.l @r1, r1
    mov.l   .L_pool_0602DEB4, r0
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    mov.l   .L_pool_0602DEA4, r12


    .global FUN_0602DDCA
    .type FUN_0602DDCA, @function
FUN_0602DDCA:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602DEA8, r0
    cmp/ge r0, r1
    bt      .L_0602DDDA
    neg r1, r1
.L_0602DDDA:
    mov.l   .L_pool_0602DEB8, r0
    mov.l r1, @r0
    mov r3, r0
    mov.l   .L_pool_0602DEBC, r1
    tst r1, r0
    .byte   0x89, 0x12    /* bt 0x0602DE0C (external) */
    mov.l   .L_pool_0602DE90, r1
    mov.l @r1, r1
    mov.l   .L_pool_0602DEC0, r2
    mov.l @r2, r0
    extu.w r0, r0
    mov.l r0, @r2
    sub r0, r1
    mov r4, r0
    mov.l   .L_pool_0602DEA4, r12

    .global FUN_0602DDF8
    .type FUN_0602DDF8, @function
FUN_0602DDF8:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602DEA8, r0
    cmp/ge r0, r1
    bt      .L_0602DE08
    neg r1, r1
.L_0602DE08:
    mov.l   .L_pool_0602DEC4, r0
    mov.l r1, @r0
    mov r3, r0
    mov.l   .L_pool_0602DE7C, r1
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DE36 (external) */
    mov.l   .L_pool_0602DE94, r1
    mov.l @r1, r1
    mov.l   .L_pool_0602DEC8, r0
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    mov.l   .L_pool_0602DEA4, r12


    .global FUN_0602DE22
    .type FUN_0602DE22, @function
FUN_0602DE22:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602DEA8, r0
    cmp/ge r0, r1
    bt      .L_0602DE32
    neg r1, r1
.L_0602DE32:
    mov.l   .L_pool_0602DECC, r0
    mov.l r1, @r0
    mov r3, r0
    mov.l   .L_pool_0602DED0, r1
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DE60 (external) */
    mov.l   .L_pool_0602DE98, r1
    mov.l @r1, r1
    mov.l   .L_pool_0602DED4, r0
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    mov.l   .L_pool_0602DEA4, r12

    .global FUN_0602DE4C
    .type FUN_0602DE4C, @function
FUN_0602DE4C:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602DEA8, r0
    cmp/ge r0, r1
    bt      .L_0602DE5C
    neg r1, r1
.L_0602DE5C:
    mov.l   .L_pool_0602DED8, r0
    mov.l r1, @r0

    .global FUN_0602DE60
FUN_0602DE60:
    mov.l   .L_pool_0602DEDC, r13


    .global FUN_0602DE62
    .type FUN_0602DE62, @function
FUN_0602DE62:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602DE84, r2
    mov.l @r2, r0
    tst r0, r0
    bf      .L_0602DEE0
    bra     .L_0602E05A
    nop
.L_pool_0602DE78:
    .4byte  sym_06082A30
.L_pool_0602DE7C:
    .4byte  0x00000002
.L_pool_0602DE80:
    .4byte  sym_06082A3C
.L_0602DE84:
    .4byte  sym_06082A40
.L_pool_0602DE88:
    .4byte  sym_06082A54
.L_pool_0602DE8C:
    .4byte  sym_06082A58
.L_pool_0602DE90:
    .4byte  sym_06082A44
.L_pool_0602DE94:
    .4byte  sym_06082A48
.L_pool_0602DE98:
    .4byte  sym_06082A50
.L_pool_0602DE9C:
    .4byte  0x00000010
.L_pool_0602DEA0:
    .4byte  sym_06082A70
.L_pool_0602DEA4:
    .4byte  sym_06034FFC
.L_pool_0602DEA8:
    .4byte  0x00000000
.L_pool_0602DEAC:
    .4byte  sym_06082A6C
.L_pool_0602DEB0:
    .4byte  0x00000008
.L_pool_0602DEB4:
    .4byte  sym_06082A78
.L_pool_0602DEB8:
    .4byte  sym_06082A74
.L_pool_0602DEBC:
    .4byte  0x00000004
.L_pool_0602DEC0:
    .4byte  sym_06063EEC
.L_pool_0602DEC4:
    .4byte  sym_06082A5C
.L_pool_0602DEC8:
    .4byte  sym_06063EF0
.L_pool_0602DECC:
    .4byte  sym_06082A60
.L_pool_0602DED0:
    .4byte  0x00000001
.L_pool_0602DED4:
    .4byte  sym_06063E24
.L_pool_0602DED8:
    .4byte  sym_06082A68
.L_pool_0602DEDC:
    .4byte  FUN_06012AFA
.L_0602DEE0:
    add #-0x1, r0
    mov.l r0, @r2
    mov.l   .L_0602DF0C, r2
    mov.l @r2, r4
    mov r4, r0
    mov.l   .L_0602DF10, r1
    tst r1, r0
    bt      .L_0602DF36
    mov.l   .L_0602DF14, r0
    mov.l @r0, r3
    mov.l   .L_0602DF18, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF20
    mov.l   .L_0602DF1C, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF34
    bra     .L_0602DF2A
    nop
    .2byte  0x0000
.L_0602DF0C:
    .4byte  sym_06082A3C
.L_0602DF10:
    .4byte  0x00000010
.L_0602DF14:
    .4byte  sym_06082A54
.L_0602DF18:
    .4byte  sym_06082A70
.L_0602DF1C:
    .4byte  sym_06082A6C
.L_0602DF20:
    mov.l   .L_0602DF30, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF34
.L_0602DF2A:
    mov.l r3, @r1
    bra     .L_0602DF36
    nop
.L_0602DF30:
    .4byte  sym_06082A6C
.L_0602DF34:
    mov.l r2, @r1
.L_0602DF36:
    mov r4, r0
    mov.l   .L_0602DF58, r1
    tst r1, r0
    bt      .L_0602DF7E
    mov.l   .L_0602DF5C, r0
    mov.l @r0, r3
    mov.l   .L_0602DF60, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF68
    mov.l   .L_0602DF64, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF7C
    bra     .L_0602DF72
    nop
.L_0602DF58:
    .4byte  0x00000008
.L_0602DF5C:
    .4byte  sym_06082A58
.L_0602DF60:
    .4byte  sym_06082A78
.L_0602DF64:
    .4byte  sym_06082A74
.L_0602DF68:
    mov.l   .L_0602DF78, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF7C
.L_0602DF72:
    mov.l r3, @r1
    bra     .L_0602DF7E
    nop
.L_0602DF78:
    .4byte  sym_06082A74
.L_0602DF7C:
    mov.l r2, @r1
.L_0602DF7E:
    mov r4, r0
    mov.l   .L_0602DFA0, r1
    tst r1, r0
    bt      .L_0602DFC6
    mov.l   .L_0602DFA4, r0
    mov.l @r0, r3
    mov.l   .L_0602DFA8, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFB0
    mov.l   .L_0602DFAC, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DFC4
    bra     .L_0602DFBA
    nop
.L_0602DFA0:
    .4byte  0x00000004
.L_0602DFA4:
    .4byte  sym_06082A44
.L_0602DFA8:
    .4byte  sym_06063EEC
.L_0602DFAC:
    .4byte  sym_06082A5C
.L_0602DFB0:
    mov.l   .L_0602DFC0, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DFC4
.L_0602DFBA:
    mov.l r3, @r1
    bra     .L_0602DFC6
    nop
.L_0602DFC0:
    .4byte  sym_06082A5C
.L_0602DFC4:
    mov.l r2, @r1
.L_0602DFC6:
    mov r4, r0
    mov.l   .L_0602DFE8, r1
    tst r1, r0
    bt      .L_0602E00E
    mov.l   .L_0602DFEC, r0
    mov.l @r0, r3
    mov.l   .L_0602DFF0, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFF8
    mov.l   .L_0602DFF4, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E00C
    bra     .L_0602E002
    nop
.L_0602DFE8:
    .4byte  0x00000002
.L_0602DFEC:
    .4byte  sym_06082A48
.L_0602DFF0:
    .4byte  sym_06063EF0
.L_0602DFF4:
    .4byte  sym_06082A60
.L_0602DFF8:
    mov.l   .L_0602E008, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E00C
.L_0602E002:
    mov.l r3, @r1
    bra     .L_0602E00E
    nop
.L_0602E008:
    .4byte  sym_06082A60
.L_0602E00C:
    mov.l r2, @r1
.L_0602E00E:
    mov r4, r0
    mov.l   .L_0602E030, r1
    tst r1, r0
    bt      .L_0602E056
    mov.l   .L_0602E034, r0
    mov.l @r0, r3
    mov.l   .L_0602E038, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602E040
    mov.l   .L_0602E03C, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E054
    bra     .L_0602E04A
    nop
.L_0602E030:
    .4byte  0x00000001
.L_0602E034:
    .4byte  sym_06082A50
.L_0602E038:
    .4byte  sym_06063E24
.L_0602E03C:
    .4byte  sym_06082A68
.L_0602E040:
    mov.l   .L_0602E050, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E054
.L_0602E04A:
    mov.l r3, @r1
    bra     .L_0602E056
    nop
.L_0602E050:
    .4byte  sym_06082A68
.L_0602E054:
    mov.l r2, @r1
.L_0602E056:
    rts
    nop
.L_0602E05A:
    mov.l   .L_0602E06C, r1
    mov.l @r1, r0
    add #0x1, r0
    mov.l r0, @r1
    mov.l   .L_0602E070, r1
    mov.l   .L_0602E074, r0
    mov.l r0, @r1
    bra     FUN_0602DD10
    nop
.L_0602E06C:
    .4byte  sym_06082A38
.L_0602E070:
    .4byte  sym_06082A30
.L_0602E074:
    .4byte  0x00000001

    .global FUN_0602E078
FUN_0602E078:
    mov.l   .L_pool_0602E0C4, r13

    .global FUN_0602E07A
    .type FUN_0602E07A, @function
FUN_0602E07A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602E0C8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0CC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0D0, r4
    mov.l @r4, r3
    mov.l   .L_0602E0D4, r4
    mov.l r3, @r4
    mov.l   .L_0602E0D8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0DC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0E0, r4
    mov.l @r4, r3
    exts.w r3, r3
    mov.l   .L_0602E0E4, r4
    mov.l r3, @r4
    mov.l   .L_0602E0E8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0EC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0F0, r0
    mov.l   .L_0602E0F4, r1
    mov.l r1, @r0
    mov.l   .L_0602E0F8, r4
    mov.l   .L_0602E0FC, r3
    mov.l r3, @r4
    mov.l   .L_0602E100, r4
    mov.l   .L_0602E104, r3
    mov.l r3, @r4
    rts
    nop
.L_pool_0602E0C4:
    .4byte  FUN_06012AC4
.L_0602E0C8:
    .4byte  sym_06082A54
.L_0602E0CC:
    .4byte  sym_06082A70
.L_0602E0D0:
    .4byte  sym_06082A58
.L_0602E0D4:
    .4byte  sym_06082A78
.L_0602E0D8:
    .4byte  sym_06082A44
.L_0602E0DC:
    .4byte  sym_06063EEC
.L_0602E0E0:
    .4byte  sym_06082A48
.L_0602E0E4:
    .4byte  sym_06063EF0
.L_0602E0E8:
    .4byte  sym_06082A50
.L_0602E0EC:
    .4byte  sym_06063E24
.L_0602E0F0:
    .4byte  sym_06082A30
.L_0602E0F4:
    .4byte  0x00000004
.L_0602E0F8:
    .4byte  sym_06063E34
.L_0602E0FC:
    .4byte  0x0000F300
.L_0602E100:
    .4byte  sym_06063E28
.L_0602E104:
    .4byte  0x006E0000

    .global FUN_0602E108
FUN_0602E108:
    mov.l   .L_0602E148, r1
    mov.w   .L_0602E13E, r3
    mov.l r3, @r1
    mov.l   .L_0602E14C, r1
    mov.l   .L_0602E150, r3
    mov.l r3, @r1
    mov.l   .L_0602E154, r1
    mov.l @r1, r2
    mov.l   .L_0602E158, r1
    mov.l r2, @r1
    mov.l   .L_0602E15C, r1
    mov.l   .L_0602E160, r2
    mov.l r2, @r1
    mov.w   .L_0602E140, r3
    mov.l   .L_0602E164, r1
    mov.l r3, @r1
    mov.l   .L_0602E168, r0
    mov.l @r0, r0
    mov.w   .L_0602E13E, r3
    mov.w   .L_0602E142, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_0602E144, r1
    mov.w r3, @(r0, r1)
    mov.w   .L_0602E146, r1
    mov.w r3, @(r0, r1)
    rts
    nop
.L_0602E13E:
    .2byte  0x0000
.L_0602E140:
    .2byte  0x0001
.L_0602E142:
    .2byte  0x01B4
.L_0602E144:
    .2byte  0x00DC
.L_0602E146:
    .2byte  0x00DE
.L_0602E148:
    .4byte  sym_0605A1C4
.L_0602E14C:
    .4byte  sym_0605A1D0
.L_0602E150:
    .4byte  0x00010000
.L_0602E154:
    .4byte  sym_06082A34
.L_0602E158:
    .4byte  sym_06063E20
.L_0602E15C:
    .4byte  sym_06082A30
.L_0602E160:
    .4byte  0x00000000
.L_0602E164:
    .4byte  sym_0607EAC8
.L_0602E168:
    .4byte  sym_0607E940
    .global FUN_0602E16C
FUN_0602E16C:
    .4byte  0xD10E6312
    .4byte  0x23388907
    .4byte  0x6033D20D
    .4byte  0x4008022E
    .4byte  0xD00C2022
    .4byte  0x73FF2132
    .4byte  0xD00B6002
    .2byte  0xDD0B

    .global FUN_0602E18A
    .type FUN_0602E18A, @function
FUN_0602E18A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E1B4, r0
    mov.l @r0, r0
    mov.l   .L_pool_0602E1BC, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E1C0, r1
    cmp/ge r1, r3
    bf      .L_0602E1C4
    bra     FUN_0602E3A0
    nop
    .2byte  0x0000
    .4byte  sym_0608325C
    .4byte  sym_0602EC54
    .4byte  sym_06083258
.L_pool_0602E1B4:
    .4byte  sym_0607E940
    .4byte  sym_0600DB64
.L_pool_0602E1BC:
    .4byte  0x00000244
.L_pool_0602E1C0:
    .4byte  0x00000007
.L_0602E1C4:
    mov.l   .L_pool_0602E298, r3
    mov.l @r3, r3
    mov.l   .L_pool_0602E29C, r1
    sub r1, r3
    mov.l   .L_pool_0602E2A0, r4
    cmp/eq r3, r4
    bf      .L_0602E1F8
    mov.w   DAT_0602e284, r1
    mov.l @(r0, r1), r3
    mov.w   .L_pool_0602E286, r2
    not r2, r2
    and r2, r3
    mov.w   DAT_0602e288, r2
    not r2, r2
    and r2, r3
    mov.w   DAT_0602e28a, r2
    not r2, r2
    and r2, r3
    mov.w   .L_pool_0602E28C, r2
    not r2, r2
    and r2, r3
    mov.l r3, @(r0, r1)
    mov.l   .L_pool_0602E298, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E29C, r2
    sub r2, r3
.L_0602E1F8:
    mov.l   .L_pool_0602E298, r1
    mov.l r3, @r1
    mov.w   DAT_0602e28e, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E2A4, r2
    cmp/eq r2, r3
    bt      .L_0602E20C
    mov.l   .L_pool_0602E29C, r2
    sub r2, r3
    mov.l r3, @(r0, r1)
.L_0602E20C:
    mov.l   .L_pool_0602E2A4, r3
    mov.l   .L_pool_0602E2A8, r1
    mov.l r3, @(r0, r1)
    mov.l   .L_pool_0602E2AC, r13

    .global FUN_0602E214
    .type FUN_0602E214, @function
FUN_0602E214:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E2B0, r13

    .global FUN_0602E220
    .type FUN_0602E220, @function
FUN_0602E220:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E2B4, r13

    .global FUN_0602E22C
    .type FUN_0602E22C, @function
FUN_0602E22C:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E2B8, r13


    .global FUN_0602E236
    .type FUN_0602E236, @function
FUN_0602E236:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E2BC, r13

    .global FUN_0602E240
    .type FUN_0602E240, @function
FUN_0602E240:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E2C0, r13


    .global FUN_0602E24A
    .type FUN_0602E24A, @function
FUN_0602E24A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602E2C4, r0
    mov.l @r0, r0
    mov.l   .L_pool_0602E2C8, r13

    .global FUN_0602E25A
    .type FUN_0602E25A, @function
FUN_0602E25A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E2CC, r13

    .global FUN_0602E264
    .type FUN_0602E264, @function
FUN_0602E264:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_0602E2C4, r0
    mov.l @r0, r0
    mov.w   .L_0602E290, r5
    add r0, r5
    mov.w   .L_0602E292, r3
    mov.l @r5, r1
    mov.w   .L_0602E294, r4
    cmp/gt r3, r1
    bt      .L_0602E2D0
    mov r3, r1
    bra     .L_0602E2D6
    nop

    .global DAT_0602e284
DAT_0602e284:
    mov.b r1, @(r0, r2)
.L_pool_0602E286:
    .word 0x0088

    .global DAT_0602e288
DAT_0602e288:
    mov.b r4, @(r0, r0)

    .global DAT_0602e28a
DAT_0602e28a:
    stc vbr, r0
.L_pool_0602E28C:
    .word 0x0011

    .global DAT_0602e28e
DAT_0602e28e:
    .word 0x0208
.L_0602E290:
    .2byte  0x00E4
.L_0602E292:
    .2byte  0x0708
.L_0602E294:
    .2byte  0x2134
    .2byte  0x0000
.L_pool_0602E298:
    .4byte  sym_0607EAC8
.L_pool_0602E29C:
    .4byte  0x00000001
.L_pool_0602E2A0:
    .4byte  0x00000028
.L_pool_0602E2A4:
    .4byte  0x00000000
.L_pool_0602E2A8:
    .4byte  0x000000C0
.L_pool_0602E2AC:
    .4byte  sym_0602F3EC
.L_pool_0602E2B0:
    .4byte  sym_0602F7BC
.L_pool_0602E2B4:
    .4byte  sym_06030A06
.L_pool_0602E2B8:
    .4byte  sym_06030EE0
.L_pool_0602E2BC:
    .4byte  FUN_060085B8
.L_pool_0602E2C0:
    .4byte  FUN_0600C4F8
.L_0602E2C4:
    .4byte  sym_0607E940
.L_pool_0602E2C8:
    .4byte  sym_0602D82A
.L_pool_0602E2CC:
    .4byte  sym_0602F17C
.L_0602E2D0:
    cmp/gt r1, r4
    bt      .L_0602E2D6
    mov r4, r1
.L_0602E2D6:
    sub r3, r1
    shll8 r1
    mov.w   .L_pool_0602E2F8, r0
    shlr r1
    mov.l   .L_pool_0602E2FC, r12

    .global FUN_0602E2E0
    .type FUN_0602E2E0, @function
FUN_0602E2E0:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    nop
    mov #0x7F, r4
    mov #0x1, r3
    cmp/gt r3, r0
    bt      .L_0602E300
    mov r3, r0
    bra     .L_0602E306
    nop
.L_pool_0602E2F8:
    .4byte  0x14B40000
.L_pool_0602E2FC:
    .4byte  sym_0602ECCC
.L_0602E300:
    cmp/gt r0, r4
    bt      .L_0602E306
    mov r4, r0
.L_0602E306:
    mov r0, r5
    mov #0x1, r4
    mov.l   .L_pool_0602E37C, r12

    .global FUN_0602E30C
    .type FUN_0602E30C, @function
FUN_0602E30C:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E380, r0
    mov.l @r0, r0
    mov.w   DAT_0602e372, r1
    mov.l @(r0, r1), r4
    mov.l   .L_pool_0602E384, r13

    .global FUN_0602E320
    .type FUN_0602E320, @function
FUN_0602E320:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E388, r13

    .global FUN_0602E32C
    .type FUN_0602E32C, @function
FUN_0602E32C:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E38C, r13

    .global FUN_0602E338
    .type FUN_0602E338, @function
FUN_0602E338:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E390, r4
    mov.l   .L_pool_0602E394, r13

    .global FUN_0602E344
    .type FUN_0602E344, @function
FUN_0602E344:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E390, r4
    mov.l   .L_pool_0602E398, r13

    .global FUN_0602E350
    .type FUN_0602E350, @function
FUN_0602E350:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E380, r0
    mov.l @r0, r0
    mov.w   .L_wpool_0602E374, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602e376, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_wpool_0602E378, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E39C, r4
    cmp/gt r3, r4
    bt      .L_0602E36E
.L_0602E36E:
    bra     .L_0602E3F4
    nop

    .global DAT_0602e372
DAT_0602e372:
    clrmac
.L_wpool_0602E374:
    .2byte  0x0030

    .global DAT_0602e376
DAT_0602e376:
    .2byte  0x0020
.L_wpool_0602E378:
    .2byte  0x0008
    .2byte  0x0000
.L_pool_0602E37C:
    .4byte  FUN_0601D5F4
.L_pool_0602E380:
    .4byte  sym_0607E940
.L_pool_0602E384:
    .4byte  sym_0602E450
.L_pool_0602E388:
    .4byte  sym_0602E4BC
.L_pool_0602E38C:
    .4byte  FUN_0600CE66
.L_pool_0602E390:
    .4byte  0x00000000
.L_pool_0602E394:
    .4byte  sym_0603053C
.L_pool_0602E398:
    .4byte  FUN_0600D780
.L_pool_0602E39C:
    .4byte  0x00000096
    .global FUN_0602E3A0
FUN_0602E3A0:
    .4byte  0xD10BD30C
    .4byte  0x2132D10C
    .4byte  0x6212D10C
    .4byte  0x2122D10C
    .4byte  0xD20C2122
    .4byte  0xD10C9308
    .4byte  0x2132D30C
    .4byte  0xD10C0136
    .4byte  0x93039103
    .4byte  0x0136AF19
    .4byte  0x00090000
    .4byte  0x01B40000
    .4byte  sym_0605A1D0
    .4byte  0x00010000
    .4byte  sym_06082A34
    .4byte  sym_06063E20
    .4byte  sym_06082A30
    .4byte  0x00000000
    .4byte  sym_0605A1C4
    .4byte  0x00000001
    .4byte  sym_0607EAC8
.L_0602E3F4:
    mov.l   .L_pool_0602E414, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E418, r4
    cmp/gt r3, r4
    .byte   0x89, 0x1C    /* bt 0x0602E438 (external) */
    mov.l   .L_pool_0602E41C, r2
    mov.b @r2, r2
    mov.l   .L_pool_0602E420, r1
    and r1, r2
    tst r2, r2
    bt      .L_0602E42C
    mov.l   .L_pool_0602E424, r0
    mov.l   .L_pool_0602E428, r1
    mov.b r1, @r0
    bra     FUN_0602E438
    nop
.L_pool_0602E414:
    .4byte  sym_06082A2C
.L_pool_0602E418:
    .4byte  0x00000028
.L_pool_0602E41C:
    .4byte  sym_06082A25
.L_pool_0602E420:
    .4byte  0x00000004
.L_pool_0602E424:
    .4byte  sym_06082A26
.L_pool_0602E428:
    .4byte  0x00000000
.L_0602E42C:
    mov.l   .L_pool_0602E44C, r13


    .global FUN_0602E42E
    .type FUN_0602E42E, @function
FUN_0602E42E:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .global FUN_0602E438
FUN_0602E438:
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .2byte  0x0000
.L_pool_0602E44C:
    .4byte  FUN_0603226C

    .global sym_0602E450
sym_0602E450:
    mov r0, r14
    mov.w   DAT_0602e460, r1
    mov.w @(r0, r1), r2
    mov #0x0, r1
    cmp/eq r1, r2
    .byte   0x89, 0x02    /* bt 0x0602E462 (external) */
    .reloc ., R_SH_IND12W, FUN_0602D924 - 4
    .2byte 0xA000    /* bra FUN_0602D924 (linker-resolved) */
    nop

    .global DAT_0602e460
DAT_0602e460:
    .2byte  0x0250

    .global FUN_0602E462
    .type FUN_0602E462, @function
FUN_0602E462:
    sts.l pr, @-r15
    neg r4, r4
    mov r4, r7
    mov.l @(12, r0), r3
    mov r3, r9
    mov.l @(16, r0), r5
    mov.l @(24, r0), r6
    mov.l r5, @(56, r0)
    mov.l r6, @(60, r0)
    mov.l   .L_pool_0602E4B0, r0
    jsr @r0
    nop
    mov r0, r8
    mov r7, r4
    mov.l   .L_pool_0602E4B4, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    mov r14, r0
    mov.l   .L_pool_0602E4B8, r10
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    mov.l r3, @(r0, r10)
    add r3, r5
    mov.l r5, @(16, r0)
    dmuls.l r8, r9
    mov.l   .L_pool_0602E4BC, r10
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    mov.l r9, @(r0, r10)
    add r9, r6
    mov.l r6, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
.L_pool_0602E4B0:
    .4byte  FUN_06027344
.L_pool_0602E4B4:
    .4byte  FUN_06027348
.L_pool_0602E4B8:
    .4byte  0x0000018C
.L_pool_0602E4BC:
    .4byte  0x00000190

    .global sym_0602E4BC
sym_0602E4BC:
    mov.w   DAT_0602e51a, r1
    mov.l @(r0, r1), r9
    shll2 r9
    mov.l   .L_pool_0602E528, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E52C, r4
    shll2 r3
    add r3, r4
    mov.l @r4, r4
    shll2 r9
    add r9, r4
    mov r4, r10
    mov.w   DAT_0602e51c, r1
    add r10, r1
    mov.l @r1, r5
    mov.w   DAT_0602e51e, r1
    add r10, r1
    mov.l @r1, r6
    mov.w   DAT_0602e520, r1
    mov.l @(r0, r1), r7
    mov.w   DAT_0602e522, r1
    mov.l @(r0, r1), r8
    mov.l r0, @-r15
    mov r5, r4
    sub r7, r4
    mov r6, r5
    sub r8, r5
    mov.l   .L_pool_0602E530, r0

    .global FUN_0602E4F4
    .type FUN_0602E4F4, @function
FUN_0602E4F4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r5
    exts.w r5, r5
    mov.l @r15+, r0
    exts.w r5, r5
    mov.w   .L_0602E524, r1
    mov.l @(r0, r1), r4
    exts.w r4, r4
    mov r5, r6
    sub r4, r6
    exts.w r6, r6
    mov.l   .L_pool_0602E534, r1
    cmp/gt r1, r6
    bt      .L_0602E538
    bra     .L_0602E53E
    nop

    .global DAT_0602e51a
DAT_0602e51a:
    mov.b r4, @(r0, r2)

    .global DAT_0602e51c
DAT_0602e51c:
    .word 0x0000

    .global DAT_0602e51e
DAT_0602e51e:
    mov.b r0, @(r0, r0)

    .global DAT_0602e520
DAT_0602e520:
    .word 0x0010

    .global DAT_0602e522
DAT_0602e522:
    sett
.L_0602E524:
    .2byte  0x0028
    .2byte  0x0000
.L_pool_0602E528:
    .4byte  sym_0607EAD8
.L_pool_0602E52C:
    .4byte  sym_0602E8AC
.L_pool_0602E530:
    .4byte  FUN_0602744C
.L_pool_0602E534:
    .4byte  0xFFFFFF00
.L_0602E538:
    mov.l   .L_pool_0602E5AC, r1
    cmp/gt r1, r6
    bf      .L_0602E540
.L_0602E53E:
    mov r1, r6
.L_0602E540:
    mov r6, r3
    add r4, r3
    exts.w r3, r3
    mov.l   .L_pool_0602E5B0, r1
    mov.l r3, @(r0, r1)
    mov.l   .L_pool_0602E5B4, r1
    mov.l r3, @(r0, r1)
    mov.l   .L_pool_0602E5B8, r1
    add r10, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E5BC, r6
    dmuls.l r6, r3
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    mov.w   DAT_0602e5a2, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602e5a4, r1
    mov.l @(r0, r1), r4
    cmp/gt r3, r4
    .byte   0x8B, 0x0B    /* bf 0x0602E582 (external) */
    mov.l   .L_pool_0602E5C0, r1
    mov.l @r1, r3
    tst r3, r3
    .byte   0x8B, 0x07    /* bf 0x0602E582 (external) */
    mov.w   .L_pool_0602E5A6, r3
    mov.l r3, @r1
    mov.l   .L_pool_0602E5C4, r13

    .global FUN_0602E578
    .type FUN_0602E578, @function
FUN_0602E578:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.w   .L_wpool_0602E5A8, r1
    mov.l @(r0, r1), r4
    exts.w r4, r4
    mov r5, r3
    sub r4, r3
    mov.l   .L_pool_0602E5C8, r6
    add r6, r3
    exts.w r3, r3
    mov.l   .L_pool_0602E5CC, r1
    cmp/ge r1, r3
    bf      .L_0602E5D4
    mov.l   .L_pool_0602E5D0, r6
    cmp/gt r6, r3
    bt      .L_0602E5D4
    rts
    nop

    .global DAT_0602e5a2
DAT_0602e5a2:
    mov.b r9, @(r0, r1)

    .global DAT_0602e5a4
DAT_0602e5a4:
    mov.b @(r0, r0), r0
.L_pool_0602E5A6:
    .word 0x0010
.L_wpool_0602E5A8:
    .2byte  0x025C
    .2byte  0x0000
.L_pool_0602E5AC:
    .4byte  0x00000100
.L_pool_0602E5B0:
    .4byte  0x00000030
.L_pool_0602E5B4:
    .4byte  0x00000028
.L_pool_0602E5B8:
    .4byte  0x00000008
.L_pool_0602E5BC:
    .4byte  0x0000038E
.L_pool_0602E5C0:
    .4byte  sym_0608325C
.L_pool_0602E5C4:
    .4byte  sym_0602CCD0
.L_pool_0602E5C8:
    .4byte  0x00003FFF
.L_pool_0602E5CC:
    .4byte  0x00000000
.L_pool_0602E5D0:
    .4byte  0x00007FFF
.L_0602E5D4:
    mov.l   .L_pool_0602E5E0, r1
    mov.l @(r0, r1), r3
    add #0x1, r3
    mov.l r3, @(r0, r1)
    rts
    nop
.L_pool_0602E5E0:
    .4byte  0x00000244

    .global sym_0602E5E4
sym_0602E5E4:
    mov.l   .L_pool_0602E5FC, r2
    mov.l @r2, r2
    mov.l   .L_pool_0602E600, r0
    mov.l @(r0, r2), r1
    mov.l   .L_pool_0602E604, r0
    mov.l r1, @r0
    mov.l   .L_pool_0602E608, r0
    mov.l @(r0, r2), r1
    mov.l   .L_pool_0602E60C, r0
    mov.l r1, @r0
    rts
    nop
.L_pool_0602E5FC:
    .4byte  sym_0607E944
.L_pool_0602E600:
    .4byte  0x00000238
.L_pool_0602E604:
    .4byte  DAT_06083264
.L_pool_0602E608:
    .4byte  0x0000023C
.L_pool_0602E60C:
    .4byte  DAT_06083268

    .global sym_0602E610
sym_0602E610:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
