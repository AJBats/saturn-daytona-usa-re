
    .section .text.FUN_0603950C


    .global scene_state_process
    .type scene_state_process, @function
scene_state_process:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x10, r15
    mov.l   .L_060395B8, r8
    mov.l   .L_060395BC, r9
    mov.l   .L_060395C0, r10
    mov.l   .L_060395C4, r11
    mov #0x0, r12
    mov.l   .L_060395C8, r13
    mov.l   .L_060395CC, r14
    mov r4, r0
    mov.b r0, @(12, r15)
    mov r5, r0
    mov.w r0, @(8, r15)
    mov.b r6, @r15
    mov r7, r0
    mov.b r0, @(4, r15)
    mov.l   .L_060395D0, r2
    mov.b r12, @r2
    add #0x2, r2
    mov.b r12, @r2
    add #0x4, r2
    mov.b r12, @r2
    extu.b r12, r3
    add #-0x2, r2
    mov.b r3, @r2
    mov.l   .L_060395D4, r3
    mov.l   .L_060395D8, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x47, r4
    mov.l   .L_060395DC, r2
    mov.w   .L_060395B6, r4
    mov.l @r2, r2
    jsr @r2
    mov r12, r5
    mov.l   .L_060395E0, r6
    mov.b @(12, r15), r0
    mov r0, r3
    mov.b r3, @r6
    mov #0x8, r5
    mov #0x1, r4
    mov.b @r6, r0
    bra     .L_060395F0
    extu.b r0, r0
.L_06039574:
    extu.b r4, r4
    mov.b r4, @r10
    extu.b r12, r0
    mov.b r0, @(1, r10)
    mov.l   .L_060395E4, r2
    mov.b r12, @r2
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060395E8, r2
    jmp @r2
    mov.l @r15+, r14
.L_06039598:
    mov.b r12, @r10
    extu.b r5, r5
    mov r5, r0
    bra     .L_060395FC
    mov.b r0, @(1, r10)
.L_060395A2:
    extu.b r4, r4
    mov.b r4, @r10
    extu.b r5, r5
    mov r5, r0
    mov.b r0, @(1, r10)
    extu.b r12, r3
    mov.l   .L_060395EC, r2
    mov.b r3, @r2
    bra     .L_060395FC
    nop
.L_060395B6:
    .2byte  0xFF7F
.L_060395B8:
    .4byte  sym_060A4CAE
.L_060395BC:
    .4byte  sym_060A4CBC
.L_060395C0:
    .4byte  sym_06063602
.L_060395C4:
    .4byte  sym_060A4CC0
.L_060395C8:
    .4byte  sym_060A4CAC
.L_060395CC:
    .4byte  sym_060A4CB0
.L_060395D0:
    .4byte  0x20100079
.L_060395D4:
    .4byte  sym_06000300
.L_060395D8:
    .4byte  master_menu_render
.L_060395DC:
    .4byte  sym_06000344
.L_060395E0:
    .4byte  sym_060A4CAA
.L_060395E4:
    .4byte  sym_060A4CA8
.L_060395E8:
    .4byte  smpc_intback_send
.L_060395EC:
    .4byte  sym_060A4CD8
.L_060395F0:
    cmp/eq #0x0, r0
    bt      .L_06039574
    cmp/eq #0x1, r0
    bt      .L_06039598
    cmp/eq #0x2, r0
    bt      .L_060395A2
.L_060395FC:
    mov.b @(4, r15), r0
    mov r0, r3
    mov.b r3, @r8
    mov.w @(8, r15), r0
    mov r0, r3
    mov #0x3B, r0
    mov.w r3, @r13
    mov.b @(r0, r15), r3
    mov.l   .L_060396F0, r2
    mov.b r3, @r2
    mov.b @r15, r3
    mov.l   .L_060396F4, r2
    mov.b r3, @r2
    mov.l @(52, r15), r3
    mov.l r3, @r14
    mov.l   .L_060396F8, r3
    mov.l r12, @r3
    mov #0xF, r3
    mov.b @r8, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bt      .L_0603962C
    bra     .L_06039632
    nop
.L_0603962C:
    mov.b @(1, r10), r0
    or #0x50, r0
    mov.b r0, @(1, r10)
.L_06039632:
    mov.l   .L_060396FC, r4
    mov.l   .L_06039700, r3
    mov.l r4, @r3
    add #0x7, r4
    mov.l   .L_06039704, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l r2, @r9
    mov.l   .L_06039708, r4
    mov.l   .L_060396F4, r0
    mov.b @r0, r0
    bra     .L_0603978A
    extu.b r0, r0
.L_0603964C:
    mov.b @r8, r5
    mov.w @r13, r3
    mov.l @r14, r2
    extu.b r5, r5
    extu.w r3, r3
    add #0x1, r5
    mul.l r3, r5
    sts macl, r5
    add r5, r2
    mov.l r2, @r11
    shll r5
    mov.l @r14, r3
    add r3, r5
    bra     .L_060397B8
    mov.l r5, @r4
.L_0603966A:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_06039694:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_060396C2:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_060396F0:
    .4byte  sym_060A4CAB
.L_060396F4:
    .4byte  sym_060A4CAF
.L_060396F8:
    .4byte  sym_060A4CB8
.L_060396FC:
    .4byte  sym_060A4CD9
.L_06039700:
    .4byte  sym_060A4CE8
.L_06039704:
    .4byte  sym_060A4C98
.L_06039708:
    .4byte  sym_060A4CC8
.L_0603970C:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_0603973A:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_06039760:
    mov.w @r13, r2
    mov.l @r14, r1
    extu.w r2, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l r2, @r11
    mov.w @r13, r3
    extu.w r3, r3
    shll r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l @r14, r1
    add r1, r3
    mov.l r3, @r4
    bra     .L_060397B8
    nop
.L_0603978A:
    cmp/eq #0x0, r0
    bf      .L_06039792
    bra     .L_0603966A
    nop
.L_06039792:
    cmp/eq #0x10, r0
    bf      .L_0603979A
    bra     .L_06039694
    nop
.L_0603979A:
    cmp/eq #0x20, r0
    bt      .L_060396C2
    cmp/eq #0x30, r0
    bt      .L_0603970C
    mov.w   DAT_060397f4, r1
    cmp/eq r1, r0
    bt      .L_0603973A
    mov.w   DAT_060397f6, r1
    cmp/eq r1, r0
    bt      .L_06039760
    mov.w   DAT_060397f8, r1
    cmp/eq r1, r0
    bf      .L_060397B8
    bra     .L_0603964C
    nop
.L_060397B8:
    mov.l   .L_060397FC, r3
    mov.l r12, @r3
    mov.l   .L_06039800, r3
    jsr @r3
    nop
    mov.l   .L_06039804, r4
    mov.l @r11, r2
    mov.l r2, @r4
    mov.l @r9, r3
    mov.l r3, @r11
    mov.l @r4, r2
    mov.l r2, @r9
    mov.l   .L_060397FC, r3
    mov.l r12, @r3
    mov.l   .L_06039800, r3
    jsr @r3
    nop
    bsr     .L_0603A6C0
    nop
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     smpc_intback_send
    mov.l @r15+, r14

    .global DAT_060397f4
DAT_060397f4:
    .2byte  0x00E1

    .global DAT_060397f6
DAT_060397f6:
    .2byte  0x00E2

    .global DAT_060397f8
DAT_060397f8:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_060397FC:
    .4byte  sym_060A4CB4
.L_06039800:
    .4byte  display_channel_iter
.L_06039804:
    .4byte  sym_060A4CC4

    .global smpc_data_manage
    .type smpc_data_manage, @function
smpc_data_manage:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_060398A8, r4
    mov.b @r4, r4
    extu.b r4, r4
    mov r4, r0
    cmp/eq #0x1, r0
    bt/s    .L_0603982E
    mov #0x0, r13
    mov r4, r0
    cmp/eq #0x2, r0
    bt      .L_0603982E
    mov.l @r15, r3
    mov.l r13, @r3
    bra     .L_06039904
    mov #0x1, r0
.L_0603982E:
    mov #0x10, r6
    mov.l   .L_060398AC, r5
    mov.l   .L_060398B0, r4
    mov.l   .L_060398B4, r3
    mov.b @r3, r3
    extu.b r3, r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_0603985A
    mov.l @r4, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r4
    mov #0x3, r3
    cmp/ge r3, r2
    bf      .L_06039860
    mov #0x1, r3
    mov.b r3, @r5
    mov.l @r4, r2
    add #-0x1, r2
    bra     .L_06039860
    mov.l r2, @r4
.L_0603985A:
    extu.b r13, r2
    mov.b r2, @r5
    mov.l r13, @r4
.L_06039860:
    mov.l   .L_060398B8, r4
    mov.l   .L_060398BC, r3
    mov.l @r4, r2
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r3, r2
    bt      .L_06039878
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    bra     .L_06039904
    mov #0x0, r0
.L_06039878:
    mov.l r13, @r4
    mov.l   .L_060398C0, r14
    mov.l   .L_060398C4, r3
    mov.l   .L_060398C8, r2
    mov.w @r3, r3
    mov.l @r2, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_060398CC
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    mov #0x3, r2
    mov.b @r14, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_060398D0
    bsr     display_channel_iter
    nop
    mov.b @r14, r2
    add #-0x1, r2
    bra     .L_060398D0
    mov.b r2, @r14
    .2byte  0xFFFF
.L_060398A8:
    .4byte  sym_060A4CAA
.L_060398AC:
    .4byte  sym_06063601
.L_060398B0:
    .4byte  sym_06063608
.L_060398B4:
    .4byte  0x20100061
.L_060398B8:
    .4byte  sym_060A4CB8
.L_060398BC:
    .4byte  sym_060A4CAB
.L_060398C0:
    .4byte  sym_06063600
.L_060398C4:
    .4byte  sym_060A4CAC
.L_060398C8:
    .4byte  sym_060A4CB4
.L_060398CC:
    extu.b r13, r2
    mov.b r2, @r14
.L_060398D0:
    mov.l   .L_06039950, r5
    mov.l   .L_06039954, r4
    mov.l @r5, r3
    mov.l r3, @r4
    mov.l   .L_06039958, r6
    mov.l @r6, r2
    mov.l r2, @r5
    mov.l @r4, r3
    mov.l r3, @r6
    mov.l   .L_0603995C, r6
    mov.l @r6, r2
    mov.l r2, @r4
    mov.l   .L_06039960, r5
    mov.l @r5, r3
    mov.l r3, @r6
    mov.l @r4, r2
    mov.l r2, @r5
    mov.l @r15, r3
    mov.l r2, @r3
    bsr     .L_0603A6C0
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     smpc_intback_send
    mov.l @r15+, r14
.L_06039904:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global master_menu_render
    .type master_menu_render, @function
master_menu_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   .L_0603994A, r8
    mov #0x0, r9
    mov.l   .L_06039964, r10
    mov.l   .L_06039968, r11
    mov.l   .L_0603996C, r12
    mov #0x1, r13
    mov.l   .L_06039970, r14
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.l r0, @r15
    stc sr, r0
    mov.w   .L_0603994C, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    mov.l   .L_06039974, r0
    mov.b @r0, r0
    bra     .L_06039F26
    extu.b r0, r0
.L_0603994A:
    .2byte  0x00F0
.L_0603994C:
    .2byte  0xFF0F
    .2byte  0xFFFF
.L_06039950:
    .4byte  sym_060A4CE8
.L_06039954:
    .4byte  sym_060A4CC4
.L_06039958:
    .4byte  sym_060A4C98
.L_0603995C:
    .4byte  sym_060A4CC0
.L_06039960:
    .4byte  sym_060A4CBC
.L_06039964:
    .4byte  0x20100061
.L_06039968:
    .4byte  sym_060A4CF4
.L_0603996C:
    .4byte  sym_060A4D04
.L_06039970:
    .4byte  sym_060A4CEC
.L_06039974:
    .4byte  sym_060A4CAA
.L_06039978:
    mov.l   .L_06039A5C, r2
    mov.l   .L_06039A60, r3
    mov.b @r3, r3
    mov.b r3, @r2
    mov.l   .L_06039A64, r3
    mov.b @r3, r0
    mov.b r0, @(1, r2)
    mov.l   .L_06039A5C, r3
    mov.l   .L_06039A68, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll8 r2
    mov.l   .L_06039A6C, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(2, r3)
    mov.l   .L_06039A70, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll16 r2
    shll8 r2
    mov.l   .L_06039A74, r1
    mov.b @r1, r1
    extu.b r1, r1
    shll16 r1
    or r1, r2
    mov.l   .L_06039A78, r0
    mov.b @r0, r0
    extu.b r0, r0
    shll8 r0
    or r0, r2
    mov.l   .L_06039A7C, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    mov.l r2, @(4, r3)
    mov.l   .L_06039A80, r2
    mov.b @r2, r0
    mov.b r0, @(8, r3)
    mov.l   .L_06039A84, r2
    mov.b r13, @r2
    mov.l @r15, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r1
    mov.w   .L_06039A58, r2
    and r2, r1
    or r1, r0
    ldc r0, sr
    bra     .L_06039F9A
    nop
.L_060399E4:
    mov.l   .L_06039A88, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_06039A14
    mov r9, r4
.L_060399F0:
    mov.l   .L_06039A8C, r3
    mov #0x7, r2
    mov.l   .L_06039A80, r0
    mov.l @r3, r3
    sub r4, r2
    add r4, r3
    shll r2
    add #0x1, r4
    mov.b @(r0, r2), r1
    mov.b r1, @r3
    mov #0x7, r3
    cmp/hs r3, r4
    bf      .L_060399F0
    mov.l   .L_06039A88, r2
    mov.b r13, @r2
    mov #0x2, r1
    bra     .L_06039F3E
    mov.b r1, @r11
.L_06039A14:
    extu.b r9, r2
    mov.b r2, @r11
    mov.l   .L_06039A80, r3
    mov.l r3, @r14
    bra     .L_06039F14
    nop
.L_06039A20:
    mov.l   .L_06039A90, r2
    mov.l @r2, r2
    cmp/pl r2
    bf      .L_06039A2C
    bra     .L_06039EF2
    nop
.L_06039A2C:
    mov.l @r14, r0
    mov.l   .L_06039A90, r3
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    tst r0, r0
    bf/s    .L_06039AD2
    mov.l r0, @r3
    mov.l @r14, r3
    mov.b @r3, r2
    extu.b r2, r2
    and r8, r2
    cmp/eq r8, r2
    bf      .L_06039A98
    mov.w   .L_06039A5A, r4
    mov.l   .L_06039A94, r3
    jsr @r3
    nop
    bsr     vdp1_sprite_draw_main
    nop
    bra     .L_06039A9E
    nop
.L_06039A58:
    .2byte  0xFF0F
.L_06039A5A:
    .2byte  0x00FF
.L_06039A5C:
    .4byte  sym_060A4C9C
.L_06039A60:
    .4byte  0x20100031
.L_06039A64:
    .4byte  0x20100033
.L_06039A68:
    .4byte  0x20100035
.L_06039A6C:
    .4byte  0x20100037
.L_06039A70:
    .4byte  0x20100039
.L_06039A74:
    .4byte  0x2010003B
.L_06039A78:
    .4byte  0x2010003D
.L_06039A7C:
    .4byte  0x2010003F
.L_06039A80:
    .4byte  0x20100021
.L_06039A84:
    .4byte  sym_060A4CA8
.L_06039A88:
    .4byte  sym_060A4CD8
.L_06039A8C:
    .4byte  sym_060A4CE8
.L_06039A90:
    .4byte  sym_060A4CF8
.L_06039A94:
    .4byte  sym_0603AB46
.L_06039A98:
    mov.l   .L_06039B64, r3
    jsr @r3
    extu.b r8, r4
.L_06039A9E:
    mov.l   .L_06039B68, r2
    mov.l   .L_06039B68, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_06039B6C, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_06039AB6
    extu.b r13, r2
    mov.b r2, @r11
.L_06039AB6:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039AC2
    bra     .L_06039F3E
    nop
.L_06039AC2:
    bsr     .L_06039FE8
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039AD8
    bra     .L_06039F3E
    nop
.L_06039AD2:
    extu.b r13, r2
    mov.l   .L_06039B70, r3
    mov.b r2, @r3
.L_06039AD8:
    mov.l @r14, r2
    add #0x2, r2
    bra     .L_06039EF2
    mov.l r2, @r14
.L_06039AE0:
    mov.l   .L_06039B70, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_06039AEE
    bra     .L_06039C4C
    nop
.L_06039AEE:
    extu.b r9, r2
    mov.l   .L_06039B70, r3
    mov.b r2, @r3
    mov.w   .L_06039B60, r1
    mov.l   .L_06039B74, r3
    mov.b r1, @r3
    mov.l @r14, r1
    mov.b @r1, r3
    extu.b r3, r3
    and r8, r3
    cmp/eq r8, r3
    bf      .L_06039B7C
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    cmp/eq #0xF, r0
    bf      .L_06039B1E
    mov.w   .L_06039B60, r4
    mov.l   .L_06039B64, r3
    jsr @r3
    nop
    bra     .L_06039B24
    nop
.L_06039B1E:
    mov.l   .L_06039B64, r3
    jsr @r3
    extu.b r8, r4
.L_06039B24:
    bsr     vdp1_sprite_draw_main
    nop
    mov.l   .L_06039B68, r2
    mov.l   .L_06039B68, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_06039B6C, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_06039B40
    extu.b r13, r2
    mov.b r2, @r11
.L_06039B40:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039B4C
    bra     .L_06039EFE
    nop
.L_06039B4C:
    extu.b r13, r2
    mov.l   .L_06039B70, r3
    mov.b r2, @r3
    mov.l   .L_06039B78, r1
    mov.l @r1, r1
    add #-0x1, r1
    mov.l   .L_06039B78, r3
    mov.l r1, @r3
    bra     .L_06039C1E
    nop
.L_06039B60:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_06039B64:
    .4byte  sym_0603AB46
.L_06039B68:
    .4byte  sym_060A4CB4
.L_06039B6C:
    .4byte  sym_060A4CAC
.L_06039B70:
    .4byte  sym_060A4D0C
.L_06039B74:
    .4byte  sym_060A4CFC
.L_06039B78:
    .4byte  sym_060A4CF8
.L_06039B7C:
    mov.l @r14, r2
    mov.b @r2, r3
    mov.w   .L_06039C32, r2
    extu.b r3, r3
    and r8, r3
    cmp/eq r2, r3
    bf      .L_06039BAE
    mov.l @r14, r2
    mov.b @r2, r3
    mov.w   .L_06039C34, r2
    extu.b r3, r3
    cmp/eq r2, r3
    bf      .L_06039BA4
    bsr     sym_0603AB46
    mov #0x20, r4
    mov #0x20, r2
    mov.l   .L_06039C38, r3
    mov.b r2, @r3
    bra     .L_06039BC8
    nop
.L_06039BA4:
    mov.l @r14, r4
    bsr     sym_0603AB46
    mov.b @r4, r4
    bra     .L_06039BC8
    nop
.L_06039BAE:
    mov.l @r14, r4
    mov.b @r4, r4
    extu.b r4, r4
    and r8, r4
    bsr     sym_0603AB46
    extu.b r4, r4
    mov.l @r14, r2
    mov.b @r2, r3
    extu.b r3, r3
    and r8, r3
    extu.b r3, r3
    mov.l   .L_06039C38, r2
    mov.b r3, @r2
.L_06039BC8:
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst #0xF, r0
    bf      .L_06039BDC
    extu.b r13, r3
    mov.l   .L_06039C3C, r2
    mov.b r3, @r2
    bra     .L_06039BE6
    nop
.L_06039BDC:
    mov.l @r14, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0xF, r0
    mov.l r0, @r12
.L_06039BE6:
    mov.l   .L_06039C38, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_06039C18
    mov.l   .L_06039C40, r2
    mov.l   .L_06039C44, r3
    mov.b @r2, r2
    mov.b r2, @r3
    mov #0x5, r3
    mov.l   .L_06039C40, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_06039C0E
    mov #0x3, r3
    mov.l   .L_06039C40, r2
    mov.b r3, @r2
    bra     .L_06039C18
    nop
.L_06039C0E:
    mov.l   .L_06039C40, r2
    mov.b @r2, r2
    add #-0x2, r2
    mov.l   .L_06039C40, r3
    mov.b r2, @r3
.L_06039C18:
    extu.b r13, r2
    mov.l   .L_06039C48, r3
    mov.b r2, @r3
.L_06039C1E:
    mov.l @r14, r2
    add #0x2, r2
    bsr     .L_06039FE8
    mov.l r2, @r14
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039C4C
    bra     .L_06039EFE
    nop
.L_06039C32:
    .2byte  0x00E0
.L_06039C34:
    .2byte  0x00E3
    .2byte  0xFFFF
.L_06039C38:
    .4byte  sym_060A4CFC
.L_06039C3C:
    .4byte  sym_060A4D0D
.L_06039C40:
    .4byte  sym_060A4CAE
.L_06039C44:
    .4byte  sym_060A4D02
.L_06039C48:
    .4byte  sym_060A4D0E
.L_06039C4C:
    mov.l   .L_06039E30, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039C76
    mov.l   .L_06039E30, r3
    mov.b r9, @r3
    mov.l @r14, r1
    mov.b @r1, r3
    extu.b r3, r3
    mov.l r3, @r12
    mov.l @r14, r2
    add #0x2, r2
    bsr     .L_06039FE8
    mov.l r2, @r14
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039C76
    bra     .L_06039EFE
    nop
.L_06039C76:
    mov.l   .L_06039E34, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_06039C84
    bra     .L_06039D90
    nop
.L_06039C84:
    extu.b r9, r2
    mov.l   .L_06039E34, r3
    mov.b r2, @r3
    mov.l   .L_06039E38, r1
    mov.l @r12, r3
    mov.b @r1, r1
    extu.b r1, r1
    cmp/ge r1, r3
    bf      .L_06039D50
    mov.l @r12, r3
    mov.l @r14, r2
    shll r3
    add r2, r3
    cmp/hi r10, r3
    bf      .L_06039D12
    extu.b r13, r2
    mov.l   .L_06039E3C, r3
    mov.b r2, @r3
    mov.l   .L_06039E38, r1
    mov.l @r14, r3
    mov.b @r1, r1
    extu.b r1, r1
    shll r1
    add r3, r1
    cmp/hi r10, r1
    bf      .L_06039CE4
    mov.l   .L_06039E40, r2
    mov.b r13, @r2
    mov.l   .L_06039E38, r4
    mov.l @r12, r1
    mov.l   .L_06039E44, r2
    mov.b @r4, r4
    extu.b r4, r4
    sub r4, r1
    mov.l r1, @r2
    mov.l @r14, r0
    mov r10, r2
    sub r0, r2
    mov #0x0, r0
    cmp/gt r2, r0
    addc r0, r2
    shar r2
    sub r2, r4
    mov.l r4, @r12
    bsr     data_table_copy
    mov r10, r4
    bra     .L_06039D78
    nop
.L_06039CE4:
    mov.l   .L_06039E48, r3
    mov.b r13, @r3
    mov.l @r14, r1
    mov r10, r3
    mov.l @r12, r0
    sub r1, r3
    mov #0x0, r1
    cmp/gt r3, r1
    addc r1, r3
    shar r3
    sub r3, r0
    mov.l   .L_06039E44, r3
    mov.l r0, @r3
    mov.l   .L_06039E38, r4
    mov.l @r14, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    bra     .L_06039D90
    mov.l r10, @r14
.L_06039D12:
    mov.l   .L_06039E4C, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_06039D30
    mov.l   .L_06039E38, r4
    mov.l @r14, r3
    mov.b @r4, r4
    extu.b r4, r4
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    bra     .L_06039D46
    mov.l r9, @r12
.L_06039D30:
    mov #0x2, r2
    mov.l   .L_06039E50, r3
    mov.b r2, @r3
    mov.l @r14, r2
    mov.l   .L_06039E54, r3
    mov.l r2, @r3
    mov.l @r12, r2
    shll r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
.L_06039D46:
    extu.b r13, r2
    mov.l   .L_06039E48, r3
    mov.b r2, @r3
    bra     .L_06039D90
    nop
.L_06039D50:
    mov.l @r12, r2
    mov.l @r14, r3
    shll r2
    add r3, r2
    cmp/hi r10, r2
    bf      .L_06039D7E
    mov.l   .L_06039E40, r2
    mov.b r13, @r2
    mov r10, r2
    mov.l @r12, r0
    mov.l @r14, r1
    sub r1, r2
    mov #0x0, r1
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    sub r2, r0
    mov.l r0, @r12
    bsr     data_table_copy
    mov r10, r4
.L_06039D78:
    mov #0x2, r2
    bra     .L_06039EFE
    mov.b r2, @r11
.L_06039D7E:
    mov.l   .L_06039E48, r3
    mov.b r13, @r3
    mov.l @r12, r4
    mov.l @r14, r3
    shll r4
    add r3, r4
    bsr     data_table_copy
    nop
    mov.l r9, @r12
.L_06039D90:
    mov.l   .L_06039E40, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039DF8
    extu.b r9, r2
    mov.l   .L_06039E40, r3
    mov.b r2, @r3
    mov #0x20, r3
    mov.l @r12, r1
    cmp/ge r3, r1
    bf      .L_06039DB6
    mov.l   .L_06039E40, r2
    mov.b r13, @r2
    mov r10, r4
    mov.l @r12, r1
    add #-0x20, r1
    bra     .L_06039DE2
    mov.l r1, @r12
.L_06039DB6:
    extu.b r13, r2
    mov.l   .L_06039E48, r3
    mov.b r2, @r3
    mov.l @r12, r4
    shll r4
    mov.l   .L_06039E58, r3
    add r3, r4
    bra     .L_06039DE2
    mov.l r9, @r12
.L_06039DC8:
    mov.l   .L_06039E5C, r2
    mov.l @r2, r2
    mov.l @r14, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l   .L_06039E5C, r3
    mov.l @r3, r3
    add #0x1, r3
    mov.l   .L_06039E5C, r2
    mov.l r3, @r2
    mov.l @r14, r1
    add #0x2, r1
    mov.l r1, @r14
.L_06039DE2:
    mov.l @r14, r3
    cmp/hs r4, r3
    bf      .L_06039DC8
    bsr     .L_06039FE8
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039DF8
    bra     .L_06039EFE
    nop
.L_06039DF8:
    mov.l   .L_06039E48, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039E92
    mov.l   .L_06039E48, r3
    mov.b r9, @r3
    bsr     game_logic_main
    nop
    mov.l   .L_06039E60, r2
    mov.l   .L_06039E60, r3
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l   .L_06039E64, r1
    mov.w @r1, r1
    extu.w r1, r1
    cmp/ge r1, r2
    bf      .L_06039E22
    extu.b r13, r2
    mov.b r2, @r11
.L_06039E22:
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039E68
    bra     .L_06039EFE
    nop
    .2byte  0xFFFF
.L_06039E30:
    .4byte  sym_060A4D0D
.L_06039E34:
    .4byte  sym_060A4D0E
.L_06039E38:
    .4byte  sym_060A4CAE
.L_06039E3C:
    .4byte  sym_060A4D11
.L_06039E40:
    .4byte  sym_060A4D0F
.L_06039E44:
    .4byte  sym_060A4D08
.L_06039E48:
    .4byte  sym_060A4D10
.L_06039E4C:
    .4byte  sym_060A4CFC
.L_06039E50:
    .4byte  sym_060A4CCC
.L_06039E54:
    .4byte  sym_060A4CD0
.L_06039E58:
    .4byte  0x20100021
.L_06039E5C:
    .4byte  sym_060A4CD4
.L_06039E60:
    .4byte  sym_060A4CB4
.L_06039E64:
    .4byte  sym_060A4CAC
.L_06039E68:
    mov.l   .L_06039FB0, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_06039E82
    mov.l   .L_06039FB4, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.l   .L_06039FB4, r2
    mov.l r3, @r2
    extu.b r13, r1
    mov.l   .L_06039FB8, r2
    mov.b r1, @r2
.L_06039E82:
    bsr     .L_06039FE8
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039E92
    bra     .L_06039EFE
    nop
.L_06039E92:
    mov.l   .L_06039FB0, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039EF2
    extu.b r9, r2
    mov.l   .L_06039FB0, r3
    mov.b r2, @r3
    mov.l   .L_06039FBC, r1
    mov #0x20, r3
    mov.l @r1, r1
    cmp/gt r3, r1
    bf      .L_06039EC2
    extu.b r13, r3
    mov.l   .L_06039FC0, r2
    mov.b r3, @r2
    mov.l r10, @r14
    mov.l   .L_06039FBC, r3
    mov.l @r3, r3
    add #-0x20, r3
    mov.l   .L_06039FBC, r2
    mov.l r3, @r2
    bra     .L_06039EE2
    nop
.L_06039EC2:
    mov.l   .L_06039FBC, r3
    mov.l @r3, r3
    shll r3
    mov.l @r14, r2
    add r3, r2
    mov.l r2, @r14
    extu.b r13, r3
    mov.l   .L_06039FB8, r2
    mov.b r3, @r2
    mov.l   .L_06039FB4, r1
    mov.l @r1, r1
    add #-0x1, r1
    mov.l   .L_06039FB4, r2
    mov.l r1, @r2
    mov.l   .L_06039FBC, r2
    mov.l r9, @r2
.L_06039EE2:
    bsr     .L_06039FE8
    nop
    mov.b @r11, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06039EF2
    bra     .L_06039EFE
    nop
.L_06039EF2:
    mov.l   .L_06039FB4, r2
    mov.l @r2, r2
    cmp/pl r2
    bf      .L_06039EFE
    bra     .L_06039AE0
    nop
.L_06039EFE:
    mov.b @r11, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_06039F0A
    bra     .L_06039F3E
    nop
.L_06039F0A:
    mov.l   .L_06039FC4, r2
    mov.l @r2, r2
    add #0x1, r2
    mov.l   .L_06039FC4, r3
    mov.l r2, @r3
.L_06039F14:
    mov.l   .L_06039FC4, r2
    mov #0x2, r3
    mov.l @r2, r2
    cmp/ge r3, r2
    bt      .L_06039F22
    bra     .L_06039A20
    nop
.L_06039F22:
    bra     .L_06039F3E
    nop
.L_06039F26:
    cmp/eq #0x0, r0
    bf      .L_06039F2E
    bra     .L_06039978
    nop
.L_06039F2E:
    cmp/eq #0x1, r0
    bf      .L_06039F36
    bra     .L_06039A14
    nop
.L_06039F36:
    cmp/eq #0x2, r0
    bf      .L_06039F3E
    bra     .L_060399E4
    nop
.L_06039F3E:
    mov.b @r11, r0
    bra     .L_06039F7C
    extu.b r0, r0
.L_06039F44:
    bsr     display_channel_iter
    nop
.L_06039F48:
    mov.l   .L_06039FC8, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    or #0x40, r0
    extu.b r0, r0
    mov.l   .L_06039FCC, r3
    mov.b r0, @r3
    bra     .L_06039F88
    nop
.L_06039F5C:
    mov.l   .L_06039FC8, r2
    mov.b @r2, r2
    extu.b r2, r2
    not r2, r2
    extu.b r2, r2
    mov.l   .L_06039FC8, r3
    mov.b r2, @r3
    mov r3, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    extu.b r0, r0
    mov.l   .L_06039FCC, r3
    mov.b r0, @r3
    bra     .L_06039F88
    nop
.L_06039F7C:
    cmp/eq #0x0, r0
    bt      .L_06039F44
    cmp/eq #0x1, r0
    bt      .L_06039F48
    cmp/eq #0x2, r0
    bt      .L_06039F5C
.L_06039F88:
    mov.l @r15, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r2
    mov.w   .L_06039FAE, r3
    and r3, r2
    or r2, r0
    ldc r0, sr
.L_06039F9A:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06039FAE:
    .2byte  0xFF0F
.L_06039FB0:
    .4byte  sym_060A4D11
.L_06039FB4:
    .4byte  sym_060A4CF8
.L_06039FB8:
    .4byte  sym_060A4D0C
.L_06039FBC:
    .4byte  sym_060A4D08
.L_06039FC0:
    .4byte  sym_060A4D0F
.L_06039FC4:
    .4byte  sym_060A4CF0
.L_06039FC8:
    .4byte  sym_060A4CA9
.L_06039FCC:
    .4byte  0x20100001
    .4byte  0xD30DD20E
    .4byte  0x63316222
    .4byte  0x633D3233
    .4byte  0x8B02E201
    .4byte  0xD30B2320
    .4byte  0x000B0009
.L_06039FE8:
    mov.l   .L_0603A014, r5
    mov.l   .L_0603A018, r3
    mov.l @r3, r3
    cmp/hs r5, r3
    bf      .L_0603A004
    mov #0x20, r4
    mov.b @r5, r3
    extu.b r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_0603A004
    mov #0x2, r3
    mov.l   .L_0603A010, r2
    mov.b r3, @r2
.L_0603A004:
    rts
    nop
    .4byte  sym_060A4CAC
    .4byte  sym_060A4CB4
.L_0603A010:
    .4byte  sym_060A4CF4
.L_0603A014:
    .4byte  0x20100061
.L_0603A018:
    .4byte  sym_060A4CEC

    .global data_table_copy
    .type data_table_copy, @function
data_table_copy:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0603A090, r13
    mov.l   .L_0603A094, r14
    bsr     menu_anim_system
    mov.l r4, @r15
    mov.l   .L_0603A098, r5
    mov.l   .L_0603A09C, r4
    mov.l @r5, r2
    mov.l r2, @r4
    mov.l @r5, r3
    mov #0x1, r2
    mov.l r3, @r14
    mov.l   .L_0603A0A0, r3
    mov.b r2, @r3
    mov.l   .L_0603A0A4, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bf      .L_0603A07E
    mov #0x5, r3
    mov.l   .L_0603A0A8, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_0603A060
    mov.l   .L_0603A0AC, r5
    mov r5, r3
    mov.l r5, @r4
    add #0x2, r5
    bra     .L_0603A066
    mov.l r5, @r14
.L_0603A060:
    mov.l @r14, r2
    add #0x2, r2
    mov.l r2, @r14
.L_0603A066:
    bra     .L_0603A07E
    nop
.L_0603A06A:
    mov.l @r14, r2
    mov.l @r13, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.l @r13, r2
    add #0x2, r2
    mov.l r2, @r13
.L_0603A07E:
    mov.l @r13, r3
    mov.l @r15, r2
    cmp/hs r2, r3
    bf      .L_0603A06A
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603A090:
    .4byte  sym_060A4CEC
.L_0603A094:
    .4byte  sym_060A4CD4
.L_0603A098:
    .4byte  sym_060A4CC8
.L_0603A09C:
    .4byte  sym_060A4CD0
.L_0603A0A0:
    .4byte  sym_060A4CCC
.L_0603A0A4:
    .4byte  sym_060A4CFC
.L_0603A0A8:
    .4byte  sym_060A4D02
.L_0603A0AC:
    .4byte  sym_060A4CFD

    .global game_logic_main
    .type game_logic_main, @function
game_logic_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l macl, @-r15
    mov #0x10, r11
    add #-0x8, r15
    mov.l   .L_0603A1A8, r13
    mov.l   .L_0603A1AC, r7
    mov.l   .L_0603A1B0, r6
    mov.l   .L_0603A1B4, r5
    mov.l   .L_0603A1B8, r4
    mov.l   .L_0603A1BC, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x20, r0
    bt/s    .L_0603A0D8
    mov #0x20, r12
    bra     .L_0603A288
    nop
.L_0603A0D8:
    mov.l @r4, r2
    mov.w   DAT_0603a1a2, r3
    mov.b r3, @r2
    mov.b @r5, r0
    mov.l @r4, r3
    mov.w   DAT_0603a1a2, r2
    extu.b r0, r0
    add r3, r0
    mov.b r2, @r0
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    mov.w   .L_0603A1A4, r3
    extu.b r0, r0
    and #0x80, r0
    cmp/eq r3, r0
    bf      .L_0603A12E
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf      .L_0603A120
    mov.l @r4, r3
    mov #-0x21, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A16E
    nop
.L_0603A120:
    mov.l @r4, r3
    mov #-0x11, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A16E
    nop
.L_0603A12E:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll2 r0
    add r3, r0
    mov.b @r0, r2
    mov #0xA, r3
    extu.b r2, r2
    cmp/gt r3, r2
    bf      .L_0603A16E
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf      .L_0603A164
    mov.l @r4, r3
    mov #-0x21, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A16E
    nop
.L_0603A164:
    mov.l @r4, r3
    mov #-0x11, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A16E:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x40, r0
    cmp/eq #0x40, r0
    bf      .L_0603A1CE
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r11, r2
    cmp/eq r11, r2
    bf      .L_0603A1C0
    mov.l @r4, r3
    mov #-0x41, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A212
    nop

    .global DAT_0603a1a2
DAT_0603a1a2:
    .2byte  0x00FF
.L_0603A1A4:
    .2byte  0x0080
    .2byte  0xFFFF
.L_0603A1A8:
    .4byte  sym_060A4CAE
.L_0603A1AC:
    .4byte  sym_060A4CB4
.L_0603A1B0:
    .4byte  sym_060A4CC0
.L_0603A1B4:
    .4byte  sym_060A4CCC
.L_0603A1B8:
    .4byte  sym_060A4CD0
.L_0603A1BC:
    .4byte  sym_060A4CFC
.L_0603A1C0:
    mov.l @r4, r3
    mov.w   DAT_0603a2ca, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A212
    nop
.L_0603A1CE:
    mov.b @r5, r0
    mov.l @r4, r2
    extu.b r0, r0
    mov r0, r3
    shll r0
    add r3, r0
    add r2, r0
    mov.b @r0, r3
    mov #0xA, r2
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_0603A212
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    add r3, r0
    mov.b @r0, r2
    extu.b r2, r2
    and r11, r2
    cmp/eq r11, r2
    bf      .L_0603A208
    mov.l @r4, r3
    mov #-0x41, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
    bra     .L_0603A212
    nop
.L_0603A208:
    mov.l @r4, r3
    mov.w   DAT_0603a2ca, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A212:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x1, r0
    cmp/eq #0x1, r0
    bf      .L_0603A22E
    mov.l @r4, r3
    mov #-0x5, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A22E:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x4, r0
    cmp/eq #0x4, r0
    bf      .L_0603A24A
    mov.l @r4, r3
    mov #-0x2, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A24A:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x2, r0
    cmp/eq #0x2, r0
    bf      .L_0603A266
    mov.l @r4, r3
    mov #-0x3, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A266:
    mov.b @r5, r0
    mov.l @r4, r3
    extu.b r0, r0
    shll r0
    mov.b @(r0, r3), r0
    extu.b r0, r0
    and #0x8, r0
    cmp/eq #0x8, r0
    bf      .L_0603A282
    mov.l @r4, r3
    mov #-0x9, r2
    mov.b @r3, r1
    and r2, r1
    mov.b r1, @r3
.L_0603A282:
    mov.l   .L_0603A2CC, r3
    mov.b @r3, r3
    mov.b r3, @r13
.L_0603A288:
    mov.l   .L_0603A2D0, r14
    mov.l   .L_0603A2D4, r0
    mov.b @r0, r0
    bra     .L_0603A67C
    extu.b r0, r0
.L_0603A292:
    bra     .L_0603A2BE
    mov #0x0, r14
.L_0603A296:
    mov.b @r13, r2
    extu.b r2, r2
    add #0x1, r2
    mov.l @r7, r3
    mul.l r3, r2
    sts macl, r2
    mov.l @r6, r1
    add r1, r2
    add r14, r2
    mov.b @r5, r0
    extu.b r0, r0
    mul.l r14, r0
    sts macl, r0
    mov.l @r4, r3
    add r3, r0
    mov.b @r0, r1
    mov #0x1, r3
    add r2, r3
    mov.b r1, @r3
    add #0x1, r14
.L_0603A2BE:
    mov.b @r13, r2
    extu.b r2, r2
    cmp/hs r2, r14
    bf      .L_0603A296
    bra     .L_0603A6B2
    nop

    .global DAT_0603a2ca
DAT_0603a2ca:
    .2byte  0xFF7F
.L_0603A2CC:
    .4byte  sym_060A4D02
.L_0603A2D0:
    .4byte  sym_060A4CBC
.L_0603A2D4:
    .4byte  sym_060A4CAF
.L_0603A2D8:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    extu.b r1, r1
    mov.b @r3, r0
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r3)
    bra     .L_0603A6B2
    nop
.L_0603A32A:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    extu.b r1, r1
    mov.b @r3, r0
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r0
    mov.w r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov r0, r2
    mov.l @r4, r1
    shll r0
    add r2, r0
    mov.b @(r0, r1), r2
    extu.b r2, r0
    mov.w r0, @(4, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r6, r1
    add r1, r3
    mov.b @r5, r0
    extu.b r0, r0
    shll2 r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r0
    mov.w r0, @(6, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov r3, r1
    mov.w @r2, r2
    mov.w @r1, r1
    extu.w r2, r2
    extu.w r1, r1
    not r2, r2
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(8, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(2, r2), r0
    mov r3, r1
    mov r0, r2
    mov.w @(2, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r0
    mov.w r0, @(10, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(4, r2), r0
    mov r0, r2
    mov r3, r1
    mov.w @(4, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r0
    mov.w r0, @(12, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @(6, r2), r0
    mov r0, r2
    mov r3, r1
    mov.w @(6, r1), r0
    mov r0, r1
    sub r1, r2
    exts.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r3)
    bra     .L_0603A6B2
    nop
.L_0603A45C:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r1
    not r1, r1
    extu.w r1, r0
    mov.w r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.b @r5, r0
    mov.l @r4, r1
    extu.b r0, r0
    mov r0, r2
    shll r0
    add r2, r0
    mov.b @(r0, r1), r2
    mov r3, r0
    mov #0x2, r1
    mov.w @(r0, r1), r1
    extu.w r1, r1
    and r11, r1
    cmp/eq r11, r1
    bf/s    .L_0603A4D6
    extu.b r2, r2
    bra     .L_0603A4D8
    mov #0x1, r1
.L_0603A4D6:
    mov #-0x1, r1
.L_0603A4D8:
    mul.l r1, r2
    sts macl, r2
    exts.w r2, r0
    mov.w r0, @(4, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.b @r5, r0
    mov.l @r4, r2
    extu.b r0, r0
    shll2 r0
    mov.b @(r0, r2), r1
    mov r3, r0
    mov #0x2, r2
    mov.w @(r0, r2), r2
    extu.w r2, r2
    and r12, r2
    cmp/eq r12, r2
    bf/s    .L_0603A510
    extu.b r1, r1
    bra     .L_0603A512
    mov #0x1, r2
.L_0603A510:
    mov #-0x1, r2
.L_0603A512:
    mul.l r2, r1
    sts macl, r1
    exts.w r1, r0
    mov.w r0, @(6, r3)
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(8, r3)
    bra     .L_0603A6B2
    nop
.L_0603A54C:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    shll r0
    mov.l @r4, r2
    mov.b @(r0, r2), r1
    extu.b r1, r1
    not r1, r1
    extu.b r1, r0
    mov.b r0, @(2, r3)
    mov.l @r7, r3
    mov.l @r6, r1
    mov.b @r5, r0
    mov r3, r2
    extu.b r0, r0
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    mov r0, r2
    mov.l @r4, r1
    shll r0
    add r2, r0
    add r1, r0
    mov.b @r0, r2
    mov #0x3, r1
    add r3, r1
    mov.b r2, @r1
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @r15
    mov.l @(4, r15), r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r3)
    bra     .L_0603A6B2
    nop
.L_0603A5EA:
    mov.l @r7, r2
    mov.l @r6, r1
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @r3, r1
    mov.b r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.b @r2, r2
    extu.b r2, r2
    not r2, r2
    mov r3, r1
    mov.b @r1, r1
    extu.b r1, r1
    or r1, r2
    extu.b r2, r2
    mov r2, r0
    mov.b r0, @(1, r3)
    bra     .L_0603A6B2
    nop
.L_0603A62A:
    mov.l @r7, r2
    mov.l @r6, r1
    mov.b @r5, r0
    mov r2, r3
    extu.b r0, r0
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    mov.l @r4, r3
    mov.b @(r0, r3), r1
    mov.b @r3, r0
    extu.b r1, r1
    extu.b r0, r0
    shll8 r0
    or r0, r1
    mov.w r1, @r2
    mov.l @r7, r3
    mov r3, r2
    shll r3
    shll2 r2
    add r2, r3
    mov.l r3, @r15
    mov.l @r6, r2
    add r2, r3
    mov.l r3, @(4, r15)
    mov.l @r15, r2
    mov.l @r14, r1
    add r1, r2
    mov.w @r2, r2
    extu.w r2, r2
    not r2, r2
    mov r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r3)
    bra     .L_0603A6B2
    nop
.L_0603A67C:
    cmp/eq #0x0, r0
    bf      .L_0603A684
    bra     .L_0603A2D8
    nop
.L_0603A684:
    cmp/eq #0x10, r0
    bf      .L_0603A68C
    bra     .L_0603A32A
    nop
.L_0603A68C:
    cmp/eq #0x20, r0
    bf      .L_0603A694
    bra     .L_0603A45C
    nop
.L_0603A694:
    cmp/eq #0x30, r0
    bf      .L_0603A69C
    bra     .L_0603A54C
    nop
.L_0603A69C:
    mov.w   .L_0603A6FA, r1
    cmp/eq r1, r0
    bt      .L_0603A5EA
    mov.w   .L_0603A6FC, r1
    cmp/eq r1, r0
    bt      .L_0603A62A
    mov.w   DAT_0603a6fe, r1
    cmp/eq r1, r0
    bf      .L_0603A6B2
    bra     .L_0603A292
    nop
.L_0603A6B2:
    add #0x8, r15
    lds.l @r15+, macl
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603A6C0:
    mov #0x1, r3
    mov #0x0, r4
    mov.l   .L_0603A700, r2
    extu.b r4, r0
    mov.b r3, @r2
    extu.b r4, r3
    mov.l   .L_0603A704, r2
    mov.b r3, @r2
    mov.l   .L_0603A708, r2
    extu.b r4, r3
    mov.b r4, @r2
    mov.l   .L_0603A70C, r2
    mov.b r0, @r2
    extu.b r4, r0
    mov.l   .L_0603A710, r2
    mov.b r3, @r2
    mov.l   .L_0603A714, r2
    mov.b r4, @r2
    mov.l   .L_0603A718, r2
    mov.b r0, @r2
    mov.l   .L_0603A71C, r3
    mov.l r4, @r3
    mov.l   .L_0603A720, r3
    mov.l r4, @r3
    mov.l   .L_0603A724, r3
    mov.l r4, @r3
    mov.l   .L_0603A728, r3
    rts
    mov.b r4, @r3
.L_0603A6FA:
    .2byte  0x00E1
.L_0603A6FC:
    .2byte  0x00E2

    .global DAT_0603a6fe
DAT_0603a6fe:
    .2byte  0x00FF
.L_0603A700:
    .4byte  sym_060A4D0C
.L_0603A704:
    .4byte  sym_060A4D0D
.L_0603A708:
    .4byte  sym_060A4D0E
.L_0603A70C:
    .4byte  sym_060A4D0F
.L_0603A710:
    .4byte  sym_060A4D10
.L_0603A714:
    .4byte  sym_060A4D11
.L_0603A718:
    .4byte  sym_060A4CD8
.L_0603A71C:
    .4byte  sym_060A4CB4
.L_0603A720:
    .4byte  sym_060A4CF0
.L_0603A724:
    .4byte  sym_060A4CF8
.L_0603A728:
    .4byte  sym_060A4CA9

    .global smpc_intback_send
smpc_intback_send:
    mov.l   .L_0603A79C, r5
    mov #0x1, r4
    mov.b @r5, r3
    extu.b r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_0603A73E
    rts
    mov #0x1, r0
.L_0603A73E:
    extu.b r4, r4
    mov.b r4, @r5
    mov.l   .L_0603A7A0, r4
    mov.b @r4, r3
    mov.l   .L_0603A7A4, r2
    mov.b r3, @r2
    mov.b @(1, r4), r0
    mov r0, r3
    add #0x2, r2
    mov.b r3, @r2
    mov.b @(2, r4), r0
    mov r0, r3
    add #0x2, r2
    mov.b r3, @r2
    mov #0x10, r3
    add #0x1A, r2
    mov.b r3, @r2
    mov #0x0, r0
    rts
    nop

    .global display_channel_iter
    .type display_channel_iter, @function
display_channel_iter:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603A7A8, r12
    mov.w   .L_0603A79A, r13
    mov.l   .L_0603A7AC, r14
    bra     .L_0603A786
    nop
.L_0603A778:
    bsr     sym_0603AB46
    extu.b r13, r4
    bsr     vdp1_sprite_draw_main
    nop
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_0603A786:
    mov.w @r12, r3
    mov.l @r14, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bf      .L_0603A778
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603A79A:
    .2byte  0x00FF
.L_0603A79C:
    .4byte  0x20100063
.L_0603A7A0:
    .4byte  sym_06063602
.L_0603A7A4:
    .4byte  0x20100001
.L_0603A7A8:
    .4byte  sym_060A4CAC
.L_0603A7AC:
    .4byte  sym_060A4CB4

    .global vdp1_sprite_draw_main
    .type vdp1_sprite_draw_main, @function
vdp1_sprite_draw_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l macl, @-r15
    mov.l   .L_0603A8C0, r13
    mov.w   DAT_0603a8bc, r14
    mov.l   .L_0603A8C4, r5
    mov.l   .L_0603A8C8, r4
    mov #0x0, r7
    mov.l   .L_0603A8CC, r6
    mov.l   .L_0603A8D0, r0
    mov.b @r0, r0
    bra     .L_0603AA42
    extu.b r0, r0
.L_0603A7CA:
    bra     .L_0603A7E8
    mov r7, r6
.L_0603A7CE:
    mov.b @r13, r2
    extu.b r2, r2
    add #0x1, r2
    mov.l @r5, r3
    mul.l r3, r2
    sts macl, r2
    mov.l @r4, r1
    add r1, r2
    add r6, r2
    extu.b r14, r3
    mov r3, r0
    mov.b r0, @(1, r2)
    add #0x1, r6
.L_0603A7E8:
    mov.b @r13, r3
    extu.b r3, r3
    cmp/hs r3, r6
    bf      .L_0603A7CE
    bra     .L_0603AA74
    nop
.L_0603A7F4:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    bra     .L_0603AA36
    nop
.L_0603A814:
    mov.l @r5, r2
    exts.w r7, r0
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.w r0, @(2, r2)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    mov r3, r2
    mov.l @r4, r1
    exts.w r7, r0
    extu.w r6, r6
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(6, r3)
    mov r6, r0
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(8, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(10, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    mov.l @r4, r1
    exts.w r7, r0
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(12, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r7
    mov r7, r0
    mov.w r0, @(14, r3)
    bra     .L_0603AA74
    nop

    .global DAT_0603a8bc
DAT_0603a8bc:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_0603A8C0:
    .4byte  sym_060A4CAE
.L_0603A8C4:
    .4byte  sym_060A4CB4
.L_0603A8C8:
    .4byte  sym_060A4CC0
.L_0603A8CC:
    .4byte  0x0000FFFF
.L_0603A8D0:
    .4byte  sym_060A4CAF
.L_0603A8D4:
    mov.l @r5, r2
    extu.w r6, r0
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    add r1, r2
    mov.w r0, @(2, r2)
    mov.l @r5, r3
    exts.w r7, r0
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    exts.w r7, r0
    mov.w r0, @(6, r3)
    mov.l @r5, r3
    mov r3, r2
    mov.l @r4, r1
    extu.w r6, r0
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r6, @r3
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(10, r3)
    exts.w r7, r0
    mov.l @r5, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.w r0, @(12, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    exts.w r7, r7
    mov.l @r4, r1
    add r2, r3
    mov r7, r0
    add r1, r3
    mov.w r0, @(14, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.w r6, r6
    mov r6, r0
    mov.w r0, @(8, r3)
    bra     .L_0603AA74
    nop
.L_0603A97A:
    extu.b r14, r0
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    add r1, r2
    mov.b r0, @(2, r2)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.b r14, r0
    mov.b r0, @(3, r3)
    mov.l @r5, r3
    mov r3, r2
    extu.w r6, r6
    mov.l @r4, r1
    shll r3
    shll2 r2
    mov r6, r0
    shll r2
    add r2, r3
    add r1, r3
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    extu.b r14, r0
    mov.l @r4, r1
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    add r1, r3
    mov.b r0, @(6, r3)
    mov.l @r5, r3
    mov r3, r2
    shll r3
    shll2 r2
    shll r2
    add r2, r3
    mov.l @r4, r1
    add r1, r3
    extu.b r14, r2
    mov r2, r0
    mov.b r0, @(7, r3)
    bra     .L_0603AA74
    nop
.L_0603A9FA:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    add r3, r2
    add r1, r2
    mov.b r14, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    add r3, r2
    mov.l @r4, r1
    add r1, r2
    extu.b r14, r0
    bra     .L_0603AA74
    mov.b r0, @(1, r2)
.L_0603AA1A:
    mov.l @r5, r2
    mov.l @r4, r1
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    add r1, r2
    extu.w r6, r3
    mov.w r3, @r2
    mov.l @r5, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
.L_0603AA36:
    mov.l @r4, r1
    add r1, r2
    extu.w r6, r6
    mov r6, r0
    bra     .L_0603AA74
    mov.w r0, @(2, r2)
.L_0603AA42:
    cmp/eq #0x0, r0
    bf      .L_0603AA4A
    bra     .L_0603A7F4
    nop
.L_0603AA4A:
    cmp/eq #0x10, r0
    bf      .L_0603AA52
    bra     .L_0603A814
    nop
.L_0603AA52:
    cmp/eq #0x20, r0
    bf      .L_0603AA5A
    bra     .L_0603A8D4
    nop
.L_0603AA5A:
    cmp/eq #0x30, r0
    bt      .L_0603A97A
    mov.w   .L_0603AA7C, r1
    cmp/eq r1, r0
    bt      .L_0603A9FA
    mov.w   .L_0603AA7E, r1
    cmp/eq r1, r0
    bt      .L_0603AA1A
    mov.w   .L_0603AA80, r1
    cmp/eq r1, r0
    bf      .L_0603AA74
    bra     .L_0603A7CA
    nop
.L_0603AA74:
    lds.l @r15+, macl
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603AA7C:
    .2byte  0x00E1
.L_0603AA7E:
    .2byte  0x00E2
.L_0603AA80:
    .2byte  0x00FF

    .global menu_anim_system
    .type menu_anim_system, @function
menu_anim_system:
    mov.l r14, @-r15
    mov.l   .L_0603AB14, r14
    mov.w   .L_0603AB12, r5
    mov.l   .L_0603AB18, r4
    mov #0x0, r6
    mov.l   .L_0603AB1C, r0
    mov.b @r0, r0
    bra     .L_0603AB20
    extu.b r0, r0
.L_0603AA94:
    bra     .L_0603AAA2
    mov r6, r7
.L_0603AA98:
    mov.l @r4, r2
    add r7, r2
    extu.b r5, r3
    mov.b r3, @r2
    add #0x1, r7
.L_0603AAA2:
    mov.b @r14, r2
    extu.b r2, r2
    cmp/hs r2, r7
    bf      .L_0603AA98
    bra     .L_0603AB42
    nop
.L_0603AAAE:
    bra     .L_0603AB06
    nop
.L_0603AAB2:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x2, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x3, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    bra     .L_0603AAFC
    add #0x4, r2
.L_0603AAD2:
    mov.l @r4, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x1, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    bra     .L_0603AAFC
    add #0x2, r2
.L_0603AAE6:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x2, r2
    extu.b r6, r3
    mov.b r3, @r2
    mov.l @r4, r2
    add #0x3, r2
.L_0603AAFC:
    extu.b r6, r6
    bra     .L_0603AB42
    mov.b r6, @r2
.L_0603AB02:
    bra     .L_0603AB0E
    mov.l @r4, r2
.L_0603AB06:
    mov.l @r4, r2
    mov.b r5, @r2
    mov.l @r4, r2
    add #0x1, r2
.L_0603AB0E:
    bra     .L_0603AB42
    mov.b r5, @r2
.L_0603AB12:
    .2byte  0x00FF
.L_0603AB14:
    .4byte  sym_060A4CAE
.L_0603AB18:
    .4byte  sym_060A4CC8
.L_0603AB1C:
    .4byte  sym_060A4CAF
.L_0603AB20:
    cmp/eq #0x0, r0
    bt      .L_0603AAAE
    cmp/eq #0x10, r0
    bt      .L_0603AAB2
    cmp/eq #0x20, r0
    bt      .L_0603AAD2
    cmp/eq #0x30, r0
    bt      .L_0603AAE6
    mov.w   .L_0603ABC6, r1
    cmp/eq r1, r0
    bt      .L_0603AB02
    mov.w   .L_0603ABC8, r1
    cmp/eq r1, r0
    bt      .L_0603AB06
    mov.w   .L_0603ABCA, r1
    cmp/eq r1, r0
    bt      .L_0603AA94
.L_0603AB42:
    rts
    mov.l @r15+, r14

    .global sym_0603AB46
sym_0603AB46:
    sts.l macl, @-r15
    mov.l   .L_0603ABCC, r6
    mov.l   .L_0603ABD0, r5
    mov.l   .L_0603ABD4, r0
    mov.b @r0, r0
    bra     .L_0603ABF0
    extu.b r0, r0
.L_0603AB54:
    mov.l   .L_0603ABD8, r0
    mov.b @r0, r0
    extu.b r0, r0
    add #0x1, r0
    mov.l @r6, r3
    mul.l r3, r0
    sts macl, r0
    mov.l @r5, r2
    add r2, r0
    bra     .L_0603AC12
    mov.b r4, @r0
.L_0603AB6A:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
    bra     .L_0603ABE6
    nop
.L_0603AB78:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    bra     .L_0603AB94
    nop
.L_0603AB88:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
.L_0603AB94:
    mov.l @r5, r1
    add r1, r2
    mov #0x10, r0
    bra     .L_0603AC12
    mov.b r4, @(r0, r2)
.L_0603AB9E:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    shll r3
    add r3, r2
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_0603AC12
    mov.b r0, @(8, r2)
.L_0603ABB4:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    add r3, r2
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_0603AC12
    mov.b r0, @(2, r2)
.L_0603ABC6:
    .2byte  0x00E1
.L_0603ABC8:
    .2byte  0x00E2
.L_0603ABCA:
    .2byte  0x00FF
.L_0603ABCC:
    .4byte  sym_060A4CB4
.L_0603ABD0:
    .4byte  sym_060A4CC0
.L_0603ABD4:
    .4byte  sym_060A4CAF
.L_0603ABD8:
    .4byte  sym_060A4CAE
.L_0603ABDC:
    mov.l @r6, r2
    mov r2, r3
    shll r2
    shll2 r3
    add r3, r2
.L_0603ABE6:
    mov.l @r5, r1
    add r1, r2
    mov r4, r0
    bra     .L_0603AC12
    mov.b r0, @(4, r2)
.L_0603ABF0:
    cmp/eq #0x0, r0
    bt      .L_0603AB6A
    cmp/eq #0x10, r0
    bt      .L_0603AB78
    cmp/eq #0x20, r0
    bt      .L_0603AB88
    cmp/eq #0x30, r0
    bt      .L_0603AB9E
    mov.w   DAT_0603ac16, r1
    cmp/eq r1, r0
    bt      .L_0603ABB4
    mov.w   DAT_0603ac18, r1
    cmp/eq r1, r0
    bt      .L_0603ABDC
    mov.w   DAT_0603ac1a, r1
    cmp/eq r1, r0
    bt      .L_0603AB54
.L_0603AC12:
    rts
    lds.l @r15+, macl

    .global DAT_0603ac16
DAT_0603ac16:
    .2byte  0x00E1

    .global DAT_0603ac18
DAT_0603ac18:
    .2byte  0x00E2

    .global DAT_0603ac1a
DAT_0603ac1a:
    .2byte  0x00FF
