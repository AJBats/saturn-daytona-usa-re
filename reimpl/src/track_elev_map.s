
    .section .text.FUN_060146D4


    .global track_elev_map
    .type track_elev_map, @function
track_elev_map:
    sts.l pr, @-r15
    mov.l   .L_060146F8, r2
    mov.l r3, @r2
    mov.l   .L_060146FC, r4
    .byte   0xB0, 0x46    /* bsr perspective_proj_3d (file ID search) */
    nop
    exts.b r0, r0
    tst r0, r0
    bt      .L_06014704
    mov #0x6, r3
    mov.l   .L_06014700, r2
    mov.b r3, @r2
    bra     .L_0601470A
    nop
    .4byte  sym_06084B18                /* active car count (32-bit) — prev TU pool */
    .4byte  sym_06084AF0                /* frame timer base (16-bit) — prev TU pool */
.L_060146F8:
    .4byte  sym_0607EBCC                /* countdown timer (32-bit, in frames) */
.L_060146FC:
    .4byte  sym_06084FB4                /* car count output parameter */
.L_06014700:
    .4byte  sym_06084AF2                /* phase byte (results state machine) */
.L_06014704:
    mov #0x4, r2
    mov.l   .L_06014758, r3
    mov.b r2, @r3
.L_0601470A:
    mov.l   .L_0601475C, r0
    mov.l @r0, r0
    tst #0x1, r0
    bf      .L_06014752
    mov.l   .L_06014760, r4
    mov.l @r4, r4
    tst r4, r4
    bt      .L_06014732
    mov.l   .L_06014764, r5
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5, r3
    mov.b r3, @r4
.L_06014732:
    mov.l   .L_06014768, r4
    mov.l @r4, r4
    tst r4, r4
    bt      .L_06014752
    mov.l   .L_06014764, r5
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5, r3
    mov.b r3, @r4
.L_06014752:
    lds.l @r15+, pr
    rts
    nop
.L_06014758:
    .4byte  sym_06084AF2                /* phase byte (results state machine) */
.L_0601475C:
    .4byte  sym_06084B10                /* status flags (bit 0 = skip variant copy) */
.L_06014760:
    .4byte  sym_06085FFC                /* active camera cut-point entry pointer */
.L_06014764:
    .4byte  sym_06084B14                /* variant char buffer (4 bytes) */
.L_06014768:
    .4byte  sym_06086000                /* camera override pointer */
