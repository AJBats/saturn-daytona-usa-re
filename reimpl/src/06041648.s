
    .section .text.FUN_06041648


    .global track_surface_check
    .type track_surface_check, @function
track_surface_check:
    sts.l pr, @-r15
    add #-0x18, r15
    mov r15, r6
    mov r15, r5
    mov r15, r4
    mov.l   .L_06041674, r3
    add #0x8, r5
    jsr @r3
    add #0x4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041678
    add #0x18, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
    .4byte  track_shadow_shape
    .4byte  ai_checkpoint_validate
    .4byte  sym_060A5400
.L_06041674:
    .4byte  track_surface_type_b
.L_06041678:
    mov r15, r4
    .byte   0xD3, 0x2C    /* mov.l .L_pool_0604172C, r3 */
    jsr @r3
    add #0xC, r4
    .byte   0xD2, 0x2B    /* mov.l .L_pool_06041730, r2 */
    mov.l @r2, r2
    mov r15, r3
    add #0xC, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r15, r0
    add #0x18, r15
    lds.l @r15+, pr
    rts
    nop
