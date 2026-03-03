
    .section .text.FUN_060415C8


    .global track_shadow_test
    .type track_shadow_test, @function
track_shadow_test:
    sts.l pr, @-r15
    add #-0x20, r15
    mov.l r4, @(8, r15)
    mov r15, r6
    mov.l r5, @(16, r15)
    add #0xC, r6
    mov r15, r5
    mov.l   .L_pool_060415F4, r3
    add #0x4, r5
    jsr @r3
    mov r15, r4
    mov r0, r4
    tst r4, r4
    bt      .L_060415F8
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
    .2byte  0x01E0

    .global DAT_060415ee
DAT_060415ee:
    mov.b r14, @(r0, r1)
    mov.b @(r0, r13), r1
    .word 0xFFFF
.L_pool_060415F4:
    .4byte  track_shadow_ground
.L_060415F8:
    mov.l @r15, r0
    cmp/eq #0x2, r0
    bf      .L_0604160A
    mov.l @r15, r2
    mov.l @(4, r15), r3
    mov.l @(8, r15), r1
    add r3, r2
    cmp/ge r2, r1
    bf      .L_06041612
.L_0604160A:
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
.L_06041612:
    mov.l @(16, r15), r5
    .byte   0xD3, 0x14    /* mov.l .L_pool_06041668, r3 */
    jsr @r3
    mov.l @(8, r15), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041628
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov #-0xB, r0
.L_06041628:
    mov r15, r4
    .byte   0xD3, 0x10    /* mov.l .L_pool_0604166C, r3 */
    jsr @r3
    add #0x14, r4
    .byte   0xD2, 0x0F    /* mov.l .L_pool_06041670, r2 */
    mov.l @r2, r2
    mov r15, r3
    add #0x14, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0x20, r15
    lds.l @r15+, pr
    rts
    nop
