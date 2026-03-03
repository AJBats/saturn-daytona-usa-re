
    .section .text.FUN_06025BF4


    .global scene_physics_variant
    .type scene_physics_variant, @function
scene_physics_variant:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x20, r15
    mov.l   .L_06025C74, r8
    mov.w   .L_06025C6E, r9
    mov.l   .L_06025C78, r10
    mov.l   .L_06025C7C, r13
    mov.l   .L_06025C80, r14
    mov.l   .L_06025C84, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt/s    .L_06025C20
    mov #0x8, r12
    bra     .L_06025D54
    nop
.L_06025C20:
    mov.l   .L_06025C88, r1
    mov.l   .L_06025C8C, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_06025C48
    mov #0x0, r11
.L_06025C34:
    extu.w r9, r5
    mov.l   .L_06025C90, r3
    jsr @r3
    mov r11, r4
    add #0x1, r11
    extu.w r11, r2
    cmp/ge r12, r2
    bf      .L_06025C34
    bra     .L_06025D3C
    nop
.L_06025C48:
    mov #0x0, r11
.L_06025C4A:
    extu.w r9, r5
    mov.l   .L_06025C90, r3
    jsr @r3
    mov r11, r4
    extu.w r11, r3
    shll2 r3
    shll r3
    mov.l r3, @(16, r15)
    add r10, r3
    mov.l r3, @(20, r15)
    mov.w @(6, r3), r0
    mov.w   .L_06025C70, r2
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_06025C94
    bra     .L_06025C96
    mov #0x8, r2

    .global DAT_06025c6e
.L_06025C6E:
DAT_06025c6e:
    .2byte  0x00A8
.L_06025C70:
    .2byte  0x00B4
    .2byte  0xFFFF
.L_06025C74:
    .4byte  sym_06028400
.L_06025C78:
    .4byte  sym_0606107C
.L_06025C7C:
    .4byte  sym_06089ECC
.L_06025C80:
    .4byte  sym_06089ED0
.L_06025C84:
    .4byte  sym_06061199
.L_06025C88:
    .4byte  sym_06089EC6
.L_06025C8C:
    .4byte  sym_06035C2C
.L_06025C90:
    .4byte  car_physics_final
.L_06025C94:
    mov #0x9, r2
.L_06025C96:
    extu.w r2, r2
    extu.w r11, r6
    mov r2, r0
    mov.w r0, @(8, r15)
    mov.l @(16, r15), r7
    mov.l   .L_06025D64, r3
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    mov.l   .L_06025D68, r1
    shll2 r7
    shll r7
    add r1, r7
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7
    mov.l   .L_06025D6C, r3
    add r3, r7
    shll r6
    mov.l r6, @(24, r15)
    mov.l   .L_06025D70, r3
    add r3, r6
    mov.l r6, @(28, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(28, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    shll r6
    mov.l @r5, r5
    add #0x4, r4
    mov.l r4, @(12, r15)
    mov.l @r4, r4
    jsr @r8
    shll2 r4
    mov.w @(8, r15), r0
    mov.l @(20, r15), r3
    mov.l   .L_06025D68, r2
    mov r0, r7
    extu.w r7, r7
    mov.w @(6, r3), r0
    shll8 r7
    mov r0, r3
    shll2 r7
    extu.w r3, r3
    shll2 r7
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(24, r15), r6
    add r3, r7
    mov.l   .L_06025D74, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @(12, r15), r4
    mov.l @r5, r5
    mov.l @r4, r4
    jsr @r8
    shll2 r4
    add #0x1, r11
    extu.w r11, r3
    cmp/ge r12, r3
    bf      .L_06025C4A
.L_06025D3C:
    mov.l   .L_06025D78, r5
    mov.w @r5, r5
    extu.w r5, r4
    tst r4, r4
    bt      .L_06025D54
    mov.l   .L_06025D7C, r3
    and r4, r3
    tst r3, r3
    bf      .L_06025D54
    mov #0x1, r3
    mov.l   .L_06025D80, r2
    mov.b r3, @r2
.L_06025D54:
    mov.l   .L_06025D80, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_06025D84
    bra     .L_060260E2
    nop
    .2byte  0xFFFF
.L_06025D64:
    .4byte  sym_0605900C
.L_06025D68:
    .4byte  sym_06063750
.L_06025D6C:
    .4byte  0x00008000
.L_06025D70:
    .4byte  sym_06059074
.L_06025D74:
    .4byte  sym_06059084
.L_06025D78:
    .4byte  sym_06063D9A
.L_06025D7C:
    .4byte  0x0000C088
.L_06025D80:
    .4byte  sym_06061199
.L_06025D84:
    mov.l   .L_06025E98, r4
    mov.w @r4, r4
    extu.w r4, r3
    tst r3, r3
    bf      .L_06025D92
    bra     .L_06025FA2
    nop
.L_06025D92:
    extu.w r4, r3
    mov.l   .L_06025E9C, r2
    and r2, r3
    tst r3, r3
    bf      .L_06025DA0
    bra     .L_06025EB0
    nop
.L_06025DA0:
    extu.w r4, r3
    mov.l   .L_06025EA0, r2
    and r2, r3
    tst r3, r3
    bt      .L_06025E1E
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov #0xE, r3
    cmp/gt r3, r2
    bf      .L_06025DBC
    mov #0x0, r3
    mov.l r3, @r14
.L_06025DBC:
    mov.l   .L_06025EA4, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025DD0
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x4, r0
    bf      .L_06025DD0
    mov.l r12, @r14
.L_06025DD0:
    mov.l   .L_06025EA4, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025DE6
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025DE6
    mov #0x4, r3
    mov.l r3, @r14
.L_06025DE6:
    mov.l   .L_06025EAC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025DFC
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0xA, r0
    bf      .L_06025DFC
    mov #0xE, r3
    mov.l r3, @r14
.L_06025DFC:
    mov.l   .L_06025EAC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bt      .L_06025E0A
    bra     .L_06025F4A
    nop
.L_06025E0A:
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x8, r0
    bt      .L_06025E16
    bra     .L_06025F4A
    nop
.L_06025E16:
    mov #0xA, r3
    mov.l r3, @r14
    bra     .L_06025F4A
    nop
.L_06025E1E:
    extu.w r4, r4
    mov.w   .L_06025E94, r2
    and r2, r4
    tst r4, r4
    bt      .L_06025E90
    mov.l @r14, r3
    add #-0x1, r3
    mov r3, r2
    mov.l r3, @r14
    cmp/pz r2
    bt      .L_06025E38
    mov #0xE, r2
    mov.l r2, @r14
.L_06025E38:
    mov.l   .L_06025EAC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025E4E
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bf      .L_06025E4E
    mov #0x9, r3
    mov.l r3, @r14
.L_06025E4E:
    mov.l   .L_06025EAC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025E64
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x9, r0
    bf      .L_06025E64
    mov #0x7, r3
    mov.l r3, @r14
.L_06025E64:
    mov.l   .L_06025EA4, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025E7A
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x7, r0
    bf      .L_06025E7A
    mov #0x3, r3
    mov.l r3, @r14
.L_06025E7A:
    mov.l   .L_06025EA4, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025E90
    mov.l   .L_06025EA8, r0
    mov.l @r0, r0
    cmp/eq #0x3, r0
    bf      .L_06025E90
    mov #0x1, r3
    mov.l r3, @r14
.L_06025E90:
    bra     .L_06025F4A
    nop

    .global DAT_06025e94
.L_06025E94:
DAT_06025e94:
    .2byte  0x4008
    .2byte  0xFFFF
.L_06025E98:
    .4byte  sym_06063D9A
.L_06025E9C:
    .4byte  0x0000C088
.L_06025EA0:
    .4byte  0x00008080
.L_06025EA4:
    .4byte  sym_06089ED6
.L_06025EA8:
    .4byte  sym_06089ED0
.L_06025EAC:
    .4byte  sym_06089ED4
.L_06025EB0:
    extu.w r4, r2
    mov.w   .L_06025FAC, r3
    and r3, r2
    tst r2, r2
    bt      .L_06025EE2
    mov #0x5, r3
    mov.l   .L_06025FB0, r2
    mov.b r3, @r2
    mov #0x12, r3
    mov.l   .L_06025FB4, r2
    mov.w r3, @r2
    mov #0x0, r3
    mov.l   .L_06025FB8, r2
    mov.b r3, @r2
    mov #0x4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xAA, 0xCB    /* bra 0x06025478 (state_transition */
    mov.l @r15+, r14
.L_06025EE2:
    mov #0x0, r5
.L_06025EE4:
    extu.w r5, r2
    extu.w r4, r1
    mov.l   .L_06025FBC, r3
    shll r2
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r1, r2
    tst r2, r2
    bt      .L_06025EFC
    bra     .L_06025F04
    nop
.L_06025EFC:
    add #0x1, r5
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_06025EE4
.L_06025F04:
    extu.w r5, r5
    mov.l r5, @r13
    .byte   0xB2, 0x70    /* bsr 0x060263EC (slot_select */
    mov r5, r4
    mov #0x0, r4
.L_06025F0E:
    extu.b r4, r2
    mov.l   .L_06025FC0, r1
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    extu.b r2, r2
    add r1, r2
    mov.w @(8, r2), r0
    mov r0, r3
    mov.l @r13, r2
    extu.w r3, r3
    shll2 r2
    shll r2
    add r10, r2
    mov.w @(6, r2), r0
    mov r0, r1
    extu.w r1, r1
    cmp/eq r1, r3
    bf      .L_06025F3C
    bra     .L_06025F46
    nop
.L_06025F3C:
    add #0x1, r4
    mov #0xE, r3
    extu.w r4, r2
    cmp/ge r3, r2
    bf      .L_06025F0E
.L_06025F46:
    extu.w r4, r4
    mov.l r4, @r14
.L_06025F4A:
    mov.l @r13, r3
    mov.l @r14, r2
    mov.l   .L_06025FC0, r0
    shll2 r3
    extu.b r2, r2
    shll r3
    mov r2, r1
    add r10, r3
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.l @(4, r2), r1
    mov.l r1, @r3
    mov.l @r13, r3
    mov.l @r13, r2
    mov.l   .L_06025FBC, r1
    shll2 r3
    shll r2
    shll r3
    add r1, r2
    add r10, r3
    mov.w @r2, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.l @r14, r2
    extu.b r2, r2
    mov.l   .L_06025FC0, r0
    mov r2, r1
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.w @(8, r2), r0
    mov.w r0, @(6, r3)
    .byte   0xBA, 0x6B    /* bsr 0x06025478 (state_transition */
    mov #0x4, r4
.L_06025FA2:
    mov.l @r13, r2
    cmp/pz r2
    bt      .L_06025FC4
    bra     .L_060260E2
    nop

    .global DAT_06025fac
.L_06025FAC:
DAT_06025fac:
    .2byte  0x0800
    .2byte  0xFFFF
.L_06025FB0:
    .4byte  sym_06061198
.L_06025FB4:
    .4byte  sym_06089EDA
.L_06025FB8:
    .4byte  sym_06061199
.L_06025FBC:
    .4byte  sym_060590A8
.L_06025FC0:
    .4byte  sym_060610BC
.L_06025FC4:
    mov.l   .L_06026018, r1
    mov.l   .L_0602601C, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_06025FF2
    extu.w r9, r5
    mov.l @r13, r4
    extu.w r4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06026020, r3
    jmp @r3
    mov.l @r15+, r14
.L_06025FF2:
    mov.l @r14, r3
    mov.l   .L_06026024, r1
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    extu.b r3, r3
    mov.w   .L_06026016, r2
    add r1, r3
    mov.w @(8, r3), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_06026028
    bra     .L_0602602A
    mov #0x8, r2

    .global DAT_06026016
.L_06026016:
DAT_06026016:
    .2byte  0x00B4
.L_06026018:
    .4byte  sym_06089EC6
.L_0602601C:
    .4byte  sym_06035C2C
.L_06026020:
    .4byte  car_physics_final
.L_06026024:
    .4byte  sym_060610BC
.L_06026028:
    mov #0x9, r2
.L_0602602A:
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.l @r13, r7
    mov.l   .L_060260F8, r3
    shll2 r7
    shll r7
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    mov.l   .L_060260FC, r1
    shll2 r7
    shll r7
    add r1, r7
    mov.l r7, @(8, r15)
    mov.l @(4, r7), r7
    mov.l   .L_06026100, r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_06026104, r3
    add r3, r6
    mov.l r6, @(12, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(12, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    mov.l @(8, r15), r5
    mov.l @r15, r4
    add r2, r6
    mov.l @r5, r5
    mov.l @(4, r4), r4
    shll r6
    jsr @r8
    shll2 r4
    mov.w @(4, r15), r0
    mov.l @r14, r3
    mov r0, r7
    extu.b r3, r3
    extu.w r7, r7
    mov r3, r2
    shll8 r7
    shll2 r2
    shll2 r3
    shll2 r7
    shll r3
    shll2 r7
    add r3, r2
    extu.b r2, r2
    mov.l   .L_06026108, r3
    add r2, r3
    mov.w @(8, r3), r0
    mov r0, r2
    extu.w r2, r3
    shll2 r3
    mov.l   .L_060260FC, r2
    shll r3
    add r3, r2
    mov.l r2, @r15
    mov.l @(4, r2), r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_0602610C, r3
    add r3, r6
    mov.l r6, @(8, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    mov.l @(8, r15), r2
    mov.l @r15, r5
    mov.l @r13, r4
    mov.l   .L_060260F8, r3
    extu.b r6, r6
    mov.b @r2, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r6
    extu.b r2, r2
    shll r4
    shll2 r6
    add r3, r4
    shll2 r6
    mov.l @(4, r4), r4
    add r2, r6
    shll r6
    jsr @r8
    shll2 r4
.L_060260E2:
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_060260F8:
    .4byte  sym_0605900C
.L_060260FC:
    .4byte  sym_06063750
.L_06026100:
    .4byte  0x00008000
.L_06026104:
    .4byte  sym_06059074
.L_06026108:
    .4byte  sym_060610BC
.L_0602610C:
    .4byte  sym_06059084
