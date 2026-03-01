
    .section .text.FUN_060410CA


    .global vblank_int_ext
    .type vblank_int_ext, @function
vblank_int_ext:
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r4, @r15
    mov.l r6, @(4, r15)
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06041102, r3 */
    jsr @r3
    mov.l @r15, r4
    mov r0, r4
    tst r4, r4
    bt      .L_060410E6
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
.L_060410E6:
    mov.l @(4, r15), r5
    .byte   0xD3, 0x06    /* mov.l .L_pool_06041106, r3 */
    jsr @r3
    mov.l @r15, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041108
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
    .4byte  sym_06035228                     /* pool: memcpy_byte function (cross-TU ref) */
.L_pool_06041102:
    .4byte  track_road_edge_b                /* pool: road edge detection function */
.L_pool_06041106:
    .4byte  track_road_width_stub            /* pool: road width validation function */
.L_06041108:
    mov r15, r4
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06041178, r3 */
    jsr @r3
    add #0x8, r4
    .byte   0xD2, 0x1A    /* mov.l .L_pool_0604117C, r2 */
    mov.l @r2, r2
    mov r15, r3
    add #0x8, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0x14, r15
    lds.l @r15+, pr
    rts
    nop
