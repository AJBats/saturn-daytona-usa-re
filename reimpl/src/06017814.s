
    .section .text.FUN_06017814


    .global track_geometry_proc
    .type track_geometry_proc, @function
track_geometry_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060178B0, r8
    mov.l   .L_060178B4, r9
    mov.l   .L_060178B8, r10
    mov.l   .L_060178BC, r12
    mov.l   .L_060178C0, r13
    mov.l   .L_060178C4, r14
    mov.l   .L_060178C8, r3
    jsr @r3
    mov #0x0, r11
    mov.w   .L_060178AA, r2
    mov.l   .L_060178CC, r3
    mov.l @r3, r3
    sub r2, r3
    mov.l   .L_060178CC, r2
    mov.l r3, @r2
    mov.l   .L_060178D0, r6
    mov.l   .L_060178D4, r5
    mov.l   .L_060178D8, r4
    mov.l   .L_060178DC, r3
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_060178CC, r4
    mov.l   .L_060178E0, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x8, r5
    mov.l   .L_060178E4, r2
    mov.l   .L_060178E8, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_060178EC, r3
    jsr @r3
    mov.l r2, @r15
    mov #0x6, r6
    mov.l @r15, r2
    mov.l   .L_060178F0, r3
    add r3, r2
    mov.l r2, @r15
    mov.l   .L_060178F4, r5
    mov.l   .L_060178F8, r3
    mov.w @r5, r5
    jsr @r3
    mov r2, r4
    mov.l   .L_060178FC, r3
    jsr @r3
    nop
    mov.l   .L_060178C8, r3
    jsr @r3
    nop
    mov.w @r8, r0
    extu.w r0, r0
    cmp/eq #0xA, r0
    bf      .L_06017904
    extu.w r11, r2
    mov.w r2, @r8
    mov.w   DAT_060178ac, r3
    mov.l   .L_06017900, r2
    mov.l @r2, r2
    sub r3, r2
    mov.l   .L_06017900, r3
    mov.l r2, @r3
    bra     .L_06017910
    nop
.L_060178AA:
    .2byte  0x0333

    .global DAT_060178ac
DAT_060178ac:
    .2byte  0x1CCB
    .2byte  0xFFFF
.L_060178B0:
    .4byte  sym_0605BE18
.L_060178B4:
    .4byte  sym_0605BE24
.L_060178B8:
    .4byte  sym_0605BE1A
.L_060178BC:
    .4byte  sym_0605BE26
.L_060178C0:
    .4byte  sym_0605BE22
.L_060178C4:
    .4byte  sym_0605BE20
.L_060178C8:
    .4byte  sym_06026DBC
.L_060178CC:
    .4byte  sym_06085FAC
.L_060178D0:
    .4byte  sym_06048130
.L_060178D4:
    .4byte  sym_0604812C
.L_060178D8:
    .4byte  sym_06048128
.L_060178DC:
    .4byte  sym_06026E2E
.L_060178E0:
    .4byte  mat_rot_y
.L_060178E4:
    .4byte  0x00200000
.L_060178E8:
    .4byte  0x00037D88
.L_060178EC:
    .4byte  sym_06031D8C
.L_060178F0:
    .4byte  0x00037DE8
.L_060178F4:
    .4byte  sym_06089E98
.L_060178F8:
    .4byte  sym_06031A28
.L_060178FC:
    .4byte  sym_06026DF8
.L_06017900:
    .4byte  sym_06085FBC
.L_06017904:
    mov.w   .L_060179B6, r2
    mov.l   .L_060179BC, r3
    mov.l @r3, r3
    add r2, r3
    mov.l   .L_060179BC, r2
    mov.l r3, @r2
.L_06017910:
    mov.l   .L_060179C0, r6
    mov.l   .L_060179C4, r5
    mov.l   .L_060179C8, r4
    mov.l   .L_060179CC, r3
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_060179BC, r4
    mov.l   .L_060179D0, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x4, r5
    mov.l   .L_060179D4, r2
    mov.l   .L_060179D8, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_060179DC, r3
    jsr @r3
    mov.l r2, @r15
    mov #0x1, r6
    mov.l   .L_060179E0, r5
    mov.l @r15, r4
    mov.l   .L_060179E4, r2
    mov.l   .L_060179E8, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    mov.l   .L_060179EC, r3
    jsr @r3
    nop
    mov.w @r8, r2
    mov.l   .L_060179F0, r3
    add #0x1, r2
    jsr @r3
    mov.w r2, @r8
    mov #0x4, r5
    mov.l @r15, r4
    mov.l   .L_060179F4, r2
    mov.l   .L_060179DC, r3
    jsr @r3
    add r2, r4
    mov #0x1, r6
    mov.w @r8, r0
    mov.l   .L_060179F8, r3
    mov.l @r15, r4
    mov.l   .L_060179FC, r2
    extu.w r0, r0
    add r2, r4
    and #0x4, r0
    mov.l   .L_060179E8, r2
    shar r0
    shar r0
    mov r0, r5
    add #0x2A, r5
    shll r5
    add r3, r5
    jsr @r2
    mov.w @r5, r5
    mov.l   .L_060179EC, r3
    jsr @r3
    nop
    mov.l   .L_06017A00, r2
    mov.l   .L_06017A04, r3
    mov.w   .L_060179B8, r0
    mov.l @r2, r2
    mov.l @r3, r3
    mov.l @(r0, r2), r2
    add #-0x1, r3
    cmp/hs r3, r2
    bf      .L_060179A6
    mov #0x2, r2
    bra     .L_06017A10
    mov.w r2, @r10
.L_060179A6:
    mov.l   .L_06017A08, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06017A0C
    extu.w r11, r3
    mov.w r3, @r10
    bra     .L_06017A10
    nop
.L_060179B6:
    .2byte  0x0333
.L_060179B8:
    .2byte  0x021C
    .2byte  0xFFFF
.L_060179BC:
    .4byte  sym_06085FBC
.L_060179C0:
    .4byte  sym_0604813C
.L_060179C4:
    .4byte  sym_06048138
.L_060179C8:
    .4byte  sym_06048134
.L_060179CC:
    .4byte  sym_06026E2E
.L_060179D0:
    .4byte  mat_rot_z
.L_060179D4:
    .4byte  0x00200000
.L_060179D8:
    .4byte  0x00037E78
.L_060179DC:
    .4byte  sym_06031D8C
.L_060179E0:
    .4byte  sym_06089E98
.L_060179E4:
    .4byte  0x00037EA8
.L_060179E8:
    .4byte  sym_06031A28
.L_060179EC:
    .4byte  sym_06026DF8
.L_060179F0:
    .4byte  sym_06026DBC
.L_060179F4:
    .4byte  0x00037EC0
.L_060179F8:
    .4byte  sym_06089E44
.L_060179FC:
    .4byte  0x00037EF0
.L_06017A00:
    .4byte  sym_0607E940
.L_06017A04:
    .4byte  sym_06063F28
.L_06017A08:
    .4byte  sym_06078636
.L_06017A0C:
    mov #0x1, r2
    mov.w r2, @r10
.L_06017A10:
    mov.l   .L_06017ACC, r3
    jsr @r3
    nop
    mov.w @r10, r5
    extu.w r5, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_06017AD0, r3
    mov.l @r15, r4
    mov.l   .L_06017AD4, r2
    mov.l   .L_06017AD8, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.w @r10, r6
    extu.w r6, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_06017ADC, r3
    mov.l   .L_06017AE0, r5
    mov.l @r15, r4
    mov.l   .L_06017AE4, r2
    mov.l   .L_06017AE8, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l   .L_06017AEC, r3
    jsr @r3
    nop
    mov.l   .L_06017AF0, r4
    mov.l   .L_06017AF4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06017A92
    mov.l   .L_06017AF8, r3
    mov.l   .L_06017AFC, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06017A92
    mov.l   .L_06017B00, r5
    mov.w @r5, r5
    extu.w r5, r0
    tst #0x40, r0
    bt      .L_06017A8C
    mov.w @r4, r0
    tst r0, r0
    bf      .L_06017AA0
    mov #0x1, r3
    mov.w r3, @r4
    mov.w @r12, r2
    add #0x1, r2
    mov.w r2, @r12
    mov.w @r12, r0
    and #0x3, r0
    bra     .L_06017AA0
    mov.w r0, @r12
.L_06017A8C:
    exts.w r11, r2
    bra     .L_06017AA0
    mov.w r2, @r4
.L_06017A92:
    exts.w r11, r2
    mov.l   .L_06017B04, r3
    mov.w r2, @r3
    exts.w r11, r1
    mov.w r1, @r12
    exts.w r11, r3
    mov.w r3, @r4
.L_06017AA0:
    bra     .L_06017B3E
    mov.w @r12, r0
.L_06017AA4:
    mov.w @r9, r2
    add #-0x1, r2
    mov.w r2, @r9
    mov.w @r13, r3
    add #-0x2, r3
    mov.w r3, @r13
    bra     .L_06017B20
    nop
.L_06017AB4:
    mov.l   .L_06017B08, r4
    bsr     track_state_handler
    nop
    mov.l   .L_06017B04, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_06017B4E
    bsr     .L_06017BF4
    nop
    bra     .L_06017B4E
    nop
    .2byte  0xFFFF
.L_06017ACC:
    .4byte  sym_06026DBC
.L_06017AD0:
    .4byte  sym_060622B4
.L_06017AD4:
    .4byte  sym_06062290
.L_06017AD8:
    .4byte  sym_06031D8C
.L_06017ADC:
    .4byte  sym_060622A8
.L_06017AE0:
    .4byte  sym_06089E98
.L_06017AE4:
    .4byte  sym_0606229C
.L_06017AE8:
    .4byte  sym_06031A28
.L_06017AEC:
    .4byte  sym_06026DF8
.L_06017AF0:
    .4byte  sym_0605BE2A
.L_06017AF4:
    .4byte  sym_0607EAD0
.L_06017AF8:
    .4byte  sym_0607EBC4
.L_06017AFC:
    .4byte  0x000A0000
.L_06017B00:
    .4byte  g_pad_state
.L_06017B04:
    .4byte  sym_0605BE28
.L_06017B08:
    .4byte  sym_0605BE20
.L_06017B0C:
    mov.l   .L_06017BDC, r4
    bsr     track_state_handler
    nop
    mov.l   .L_06017BE0, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_06017B20
    bsr     .L_06017C78
    nop
.L_06017B20:
    mov.w @r14, r2
    add #-0x3, r2
    bra     .L_06017B4E
    mov.w r2, @r14
.L_06017B28:
    mov.l   .L_06017BE4, r4
    bsr     track_state_handler
    nop
    mov.w @r13, r2
    add #-0x2, r2
    mov.w r2, @r13
    mov.w @r14, r3
    add #-0x3, r3
    mov.w r3, @r14
    bra     .L_06017B4E
    nop
.L_06017B3E:
    cmp/eq #0x0, r0
    bt      .L_06017AA4
    cmp/eq #0x1, r0
    bt      .L_06017B28
    cmp/eq #0x2, r0
    bt      .L_06017B0C
    cmp/eq #0x3, r0
    bt      .L_06017AB4
.L_06017B4E:
    mov.w @r9, r2
    cmp/pl r2
    bt      .L_06017B58
    mov #0x30, r2
    mov.w r2, @r9
.L_06017B58:
    mov.w @r14, r3
    cmp/pl r3
    bt      .L_06017B62
    mov #0x30, r3
    mov.w r3, @r14
.L_06017B62:
    mov.w @r13, r2
    cmp/pl r2
    bt      .L_06017B6C
    mov #0x30, r2
    mov.w r2, @r13
.L_06017B6C:
    mov.l   .L_06017BE8, r6
    mov.l   .L_06017BEC, r5
    mov.l   .L_06017BF0, r4
    mov.w   DAT_06017bd4, r0
    mov.w @r9, r2
    mov.w @(r0, r5), r3
    mov r2, r1
    extu.w r3, r3
    mov.l @r6, r0
    shll r2
    shll2 r3
    add r1, r2
    shll r3
    add r0, r2
    add r4, r3
    mov.l r2, @r3
    mov.w   DAT_06017bd6, r0
    mov.w @r13, r2
    mov.w @(r0, r5), r3
    mov r2, r1
    extu.w r3, r3
    shll2 r3
    shll r3
    add r4, r3
    shll r2
    add r1, r2
    mov.l @r6, r0
    add r0, r2
    mov.l r2, @r3
    mov.w   DAT_06017bd8, r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    mov.w @r14, r2
    mov.l @r6, r0
    shll2 r3
    mov r2, r1
    shll r3
    shll r2
    add r4, r3
    add r1, r2
    add r0, r2
    mov.l r2, @r3
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

    .global DAT_06017bd4
DAT_06017bd4:
    .2byte  0x151A

    .global DAT_06017bd6
DAT_06017bd6:
    .2byte  0x151C

    .global DAT_06017bd8
DAT_06017bd8:
    .2byte  0x151E
    .2byte  0xFFFF
.L_06017BDC:
    .4byte  sym_0605BE22
.L_06017BE0:
    .4byte  sym_06085FCC
.L_06017BE4:
    .4byte  sym_0605BE24
.L_06017BE8:
    .4byte  sym_0606A4F0
.L_06017BEC:
    .4byte  sym_060684EC
.L_06017BF0:
    .4byte  sym_06063F64
.L_06017BF4:
    mov.l   .L_06017C54, r3
    mov.l   .L_06017C58, r2
    mov.l @r3, r3
    cmp/eq r2, r3
    bt      .L_06017C02
    rts
    nop
.L_06017C02:
    mov.l   .L_06017C5C, r5
    mov.l   .L_06017C60, r2
    mov.w @r5, r4
    mov.w @r2, r2
    cmp/eq r2, r4
    bf      .L_06017C4E
    mov.l   .L_06017C64, r2
    mov.w @r2, r2
    cmp/eq r2, r4
    bf      .L_06017C4E
    mov.l   .L_06017C68, r7
    mov.l   .L_06017C6C, r4
    mov.w @r5, r0
    cmp/eq #0x2A, r0
    bf/s    .L_06017C36
    mov #0x1, r6
    mov.w   DAT_06017c52, r2
    mov.l @r4, r3
    add r2, r3
    mov.l r3, @r4
    exts.w r6, r6
    mov.w r6, @r7
    mov.l   .L_06017C70, r5
    mov.l   .L_06017C74, r3
    jmp @r3
    mov #0x0, r4
.L_06017C36:
    mov.w @r5, r0
    cmp/eq #0x12, r0
    bf      .L_06017C4E
    mov.l @r4, r2
    add #0x64, r2
    mov.l r2, @r4
    exts.w r6, r6
    mov.w r6, @r7
    mov.l   .L_06017C70, r5
    mov.l   .L_06017C74, r3
    jmp @r3
    mov #0x0, r4
.L_06017C4E:
    rts
    nop

    .global DAT_06017c52
DAT_06017c52:
    .2byte  0x008C
.L_06017C54:
    .4byte  sym_0607EBC4
.L_06017C58:
    .4byte  0x00020000
.L_06017C5C:
    .4byte  sym_0605BE24
.L_06017C60:
    .4byte  sym_0605BE22
.L_06017C64:
    .4byte  sym_0605BE20
.L_06017C68:
    .4byte  sym_0605BE28
.L_06017C6C:
    .4byte  sym_0607EAAC
.L_06017C70:
    .4byte  0xAE1117FF
.L_06017C74:
    .4byte  sound_cmd_dispatch
.L_06017C78:
    mov.l   .L_06017CD4, r4
    mov.l   .L_06017CD8, r2
    mov.w @r4, r3
    mov.w @r2, r2
    cmp/eq r2, r3
    bf      .L_06017C98
    mov.w @r4, r0
    cmp/eq #0x2A, r0
    bf      .L_06017C98
    mov #0x1, r2
    mov.l   .L_06017CDC, r3
    mov.b r2, @r3
    mov.l   .L_06017CE0, r5
    mov.l   .L_06017CE4, r3
    jmp @r3
    mov #0x0, r4
.L_06017C98:
    rts
    nop

    .global track_state_handler
    .type track_state_handler, @function
track_state_handler:
    sts.l pr, @-r15
    mov.w @r4, r1
    mov.l   .L_06017CE8, r3
    extu.w r1, r1
    jsr @r3
    mov #0x6, r0
    extu.w r0, r5
    mov #0x4, r3
    cmp/ge r3, r5
    bt      .L_06017CC0
    mov.w @r4, r3
    extu.w r3, r3
    extu.w r5, r5
    sub r5, r3
    extu.w r3, r3
    mov.w r3, @r4
    bra     .L_06017CCE
    nop
.L_06017CC0:
    mov.w @r4, r2
    extu.w r2, r2
    extu.w r5, r5
    sub r5, r2
    add #0x6, r2
    extu.w r2, r2
    mov.w r2, @r4
.L_06017CCE:
    lds.l @r15+, pr
    rts
    nop
.L_06017CD4:
    .4byte  sym_0605BE24
.L_06017CD8:
    .4byte  sym_0605BE22
.L_06017CDC:
    .4byte  sym_06085FCC
.L_06017CE0:
    .4byte  0xAE1118FF
.L_06017CE4:
    .4byte  sound_cmd_dispatch
.L_06017CE8:
    .4byte  sym_06035C2C
