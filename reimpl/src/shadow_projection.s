
    .section .text.FUN_06036A24


    .global shadow_projection
    .type shadow_projection, @function
shadow_projection:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_06036A90, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x70, r3
    extu.b r13, r13
    mov.b r3, @r2
    mov r13, r0
    mov r15, r2
    mov r15, r3
    mov.l r14, @(4, r2)
    mov.b r0, @(4, r3)
    .byte   0x94, 0x24    /* mov.w .L_wpool_06036A8C, r4 */
    .byte   0xD3, 0x14    /* mov.l .L_pool_06036A94, r3 */
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
