
    .section .text.FUN_060197F4


    .global car_select_state
    .type car_select_state, @function
car_select_state:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_pool_06019874, r3
    mov.w @r3, r2
    mov.w   .L_wpool_06019866, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601989C
    mov #0x0, r5
    mov.l   .L_pool_06019878, r3
    mov.l r5, @r3
    mov.l   .L_pool_0601987C, r3
    mov.b r5, @r3
    mov.l   .L_pool_06019880, r3
    mov.l r4, @r3
    mov.l   .L_pool_06019884, r7
    mov.b @r7, r7
    shll r7
    mov.l r7, @(8, r15)
    mov.l   .L_pool_06019888, r3
    add r3, r7
    mov.w @r7, r7
    extu.w r7, r7
    shll2 r7
    shll r7
    mov.l   .L_pool_0601988C, r2
    add r2, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_wpool_06019868, r3
    add r3, r7
    mov.l @(8, r15), r6
    mov.l   .L_pool_06019890, r3
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(4, r15), r2
    mov.l @r15, r5
    mov.l   .L_pool_06019894, r3
    mov.b @r2, r2
    mov.l @r5, r5
    extu.b r2, r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0xC, r4
    add #0xC, r15
    mov.l   .L_pool_06019898, r3
    jmp @r3
    lds.l @r15+, pr

    .global DAT_06019864
DAT_06019864:
    mov.l r0, @(0, r0)
.L_wpool_06019866:
    .2byte  0x0600
.L_wpool_06019868:
    .2byte  0x4000
    .2byte  0xFFFF
    .4byte  sym_0605D243
    .4byte  sym_0605D250
.L_pool_06019874:
    .4byte  sym_06063D9A
.L_pool_06019878:
    .4byte  sym_06059F44
.L_pool_0601987C:
    .4byte  sym_0605D242
.L_pool_06019880:
    .4byte  g_game_state
.L_pool_06019884:
    .4byte  sym_0605D244
.L_pool_06019888:
    .4byte  sym_06049AF4
.L_pool_0601988C:
    .4byte  sym_06063750
.L_pool_06019890:
    .4byte  sym_06049AEC
.L_pool_06019894:
    .4byte  sym_06028400
.L_pool_06019898:
    .4byte  sym_06026CE0
.L_0601989C:
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_060198A4
loc_060198A4:
    mov #0x0, r4
    mov.l   .L_pool_060198D4, r2
    mov.b r4, @r2
    mov.l   .L_pool_060198D8, r2
    mov.l r4, @r2
    exts.b r4, r4
    mov.l   .L_pool_060198DC, r2
    mov.b r4, @r2
    bra     car_select_state
    mov #0xC, r4

    .global loc_060198B8
loc_060198B8:
    mov #0x0, r4
    mov.l   .L_pool_060198D4, r2
    mov.b r4, @r2
    mov.l   .L_pool_060198D8, r2
    mov.l r4, @r2
    mov #0x1, r1
    mov.l   .L_pool_060198DC, r2
    mov.b r1, @r2
    bra     car_select_state
    mov #0xC, r4

    .global loc_060198CC
loc_060198CC:
    bra     car_select_state
    mov #0x8, r4

    .global loc_060198D0
loc_060198D0:
    bra     car_select_state
    mov #0xA, r4
.L_pool_060198D4:
    .4byte  sym_06078663
.L_pool_060198D8:
    .4byte  sym_0605AA98
.L_pool_060198DC:
    .4byte  sym_06085FF4
