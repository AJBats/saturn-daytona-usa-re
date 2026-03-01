
    .section .text.FUN_0601450C


    .global camera_track_update
    .type camera_track_update, @function
camera_track_update:
    mov.l r14, @-r15
    mov.l   .L_06014598, r14
    mov.l   .L_0601459C, r4
    mov.l   .L_060145A0, r0
    mov.w @r4, r4
    mov.l @r0, r0
    tst #0x3, r0
    bf/s    .L_06014550
    mov.l @r14, r5
    extu.w r4, r3
    mov.w   DAT_06014594, r2
    and r2, r3
    tst r3, r3
    bt      .L_06014538
    mov #0x0, r2
    mov.l @r14, r3
    cmp/hi r2, r3
    bf      .L_06014550
    mov.l @r14, r2
    add #-0x1, r2
    bra     .L_06014550
    mov.l r2, @r14
.L_06014538:
    extu.w r4, r4
    mov.l   .L_060145A4, r2
    and r2, r4
    tst r4, r4
    bt      .L_06014550
    mov.l @r14, r3
    mov #0x1C, r2
    cmp/hs r2, r3
    bt      .L_06014550
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_06014550:
    mov.l   .L_060145A8, r3
    mov #0x3, r2
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_06014572
    mov #0x1B, r4
    mov.l @r14, r2
    cmp/hs r4, r2
    bt      .L_06014566
    bra     .L_06014572
    mov.l r4, @r14
.L_06014566:
    mov #0x1C, r3
    mov.l @r14, r2
    cmp/hi r3, r2
    bf      .L_06014572
    mov #0x1C, r3
    mov.l r3, @r14
.L_06014572:
    mov.l @r14, r2
    mov.l   .L_060145AC, r3
    mov.l   .L_060145B0, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    mov.l r2, @r1
    mov.l @r14, r0
    cmp/eq r0, r5
    bt      .L_06014590
    mov.l   .L_060145B4, r5
    mov #0x0, r4
    mov.l   .L_060145B8, r3
    jmp @r3
    mov.l @r15+, r14
.L_06014590:
    rts
    mov.l @r15+, r14

    .global DAT_06014594
DAT_06014594:
    .2byte  0x4000
    .2byte  0xFFFF
.L_06014598:
    .4byte  sym_06084B08
.L_0601459C:
    .4byte  g_pad_state
.L_060145A0:
    .4byte  sym_0607EBC8
.L_060145A4:
    .4byte  0x00008000
.L_060145A8:
    .4byte  sym_06084B18
.L_060145AC:
    .4byte  sym_0605AD2C
.L_060145B0:
    .4byte  sym_06084B20
.L_060145B4:
    .4byte  0xAB111DFF
.L_060145B8:
    .4byte  sound_cmd_dispatch
