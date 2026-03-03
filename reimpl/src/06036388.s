
    .section .text.FUN_06036388


    .global track_road_edge_a
    .type track_road_edge_a, @function
track_road_edge_a:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06036408, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x44, r3
    extu.b r14, r14
    extu.b r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r13, r0
    mov.b r0, @(4, r3)
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603640C, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
