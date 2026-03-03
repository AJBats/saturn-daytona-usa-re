	.text
   .global track_utility_misc
track_utility_misc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_06018668, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x3, r0
    bf      .L_0601862C
    mov.l   .L_0601866C, r3
    jsr @r3
    nop
    mov.l   .L_06018670, r14
    mov.l   .L_06018674, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    jsr @r3
    mov.l @r14, r4
    mov.w   DAT_06018660, r4
    mov.l   .L_06018678, r3
    jsr @r3
    nop
    mov.w   .L_06018662, r5
    mov.l   .L_0601867C, r2
    mov.l   .L_06018680, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_06018684, r3
    jsr @r3
    mov.l r2, @r15
    mov.w   .L_06018664, r6
    mov.l   .L_06018688, r5
    mov.l @r15, r4
    mov.l   .L_0601868C, r2
    mov.l   .L_06018690, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_06018694, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601862C:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_06018634
sym_06018634:
    mov.l   .L_06018698, r6
    mov.l   .L_0601869C, r5
    mov #0x0, r4
    mov.l   .L_060186A0, r0
    bra     .L_060186AC
    mov.l @r0, r0
.L_06018640:
    bra     .L_060186BC
    nop
.L_06018644:
    extu.w r4, r2
    mov.l   .L_060186A4, r3
    mov.w r2, @r3
    extu.w r4, r1
    mov.l   .L_060186A8, r3
    mov.w r1, @r3
    extu.w r4, r0
    bra     .L_0601865A
    mov.w r0, @r5
.L_06018656:
    extu.w r4, r2
    mov.w r2, @r5
.L_0601865A:
    extu.w r4, r4
    bra     .L_060186B8
    mov.w r4, @r6

    .global DAT_06018660
DAT_06018660:
    .short  0x38E3
.L_06018662:
    .short  0x0178
.L_06018664:
    .short  0x0145
    .short  0xFFFF
.L_06018668:
    .long  sym_06083254
.L_0601866C:
    .long  sym_06026DBC
.L_06018670:
    .long  sym_06048140
.L_06018674:
    .long  sym_06026E2E
.L_06018678:
    .long  mat_rot_y
.L_0601867C:
    .long  0x00200000
.L_06018680:
    .long  0x000BABE0
.L_06018684:
    .long  sym_06031D8C
.L_06018688:
    .long  sym_06089E98
.L_0601868C:
    .long  0x000BBD80
.L_06018690:
    .long  sym_06031A28
.L_06018694:
    .long  sym_06026DF8
.L_06018698:
    .long  sym_0605BE38
.L_0601869C:
    .long  sym_0605BE36
.L_060186A0:
    .long  sym_0607EAD8
.L_060186A4:
    .long  sym_0605BE1C
.L_060186A8:
    .long  sym_0605BE1E
.L_060186AC:
    cmp/eq #0x0, r0
    bt      .L_06018640
    cmp/eq #0x1, r0
    bt      .L_06018644
    cmp/eq #0x2, r0
    bt      .L_06018656
.L_060186B8:
    rts
    nop
.L_060186BC:
    mov #0x0, r4
    mov.l   .L_060186FC, r2
    exts.w r4, r0
    mov.w r4, @r2
    mov.l   .L_06018700, r2
    mov.w r4, @r2
    mov.l   .L_06018704, r2
    mov.w r0, @r2
    mov.l   .L_06018708, r2
    exts.w r4, r0
    mov.w r4, @r2
    mov.l   .L_0601870C, r2
    mov.w r4, @r2
    mov.l   .L_06018710, r2
    mov.w r0, @r2
    mov.l   .L_06018714, r2
    mov.w r4, @r2
    mov.l   .L_06018718, r2
    rts
    mov.w r4, @r2
    .long  0xE400D20D
    .long  0x634D604D
    .long  0x2231D20C
    .long  0x2241D208
    .long  0x2201D308
    .long  0x000B2341
.L_060186FC:
    .long  sym_0605BE24
.L_06018700:
    .long  sym_0605BE22
.L_06018704:
    .long  sym_0605BE20
.L_06018708:
    .long  sym_0605BE2A
.L_0601870C:
    .long  sym_0605BE26
.L_06018710:
    .long  sym_0605BE28
.L_06018714:
    .long  sym_0605BE36
.L_06018718:
    .long  sym_0605BE38
    .long  sym_0605BE1C
    .long  sym_0605BE1E
    .long  0xE400D202
    .long  0x2241D202
    .long  0x000B2241
    .long  sym_0605BE36
    .long  sym_0605BE38
