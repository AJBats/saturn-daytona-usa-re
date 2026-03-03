
    .section .text.FUN_06036148


    .global seg_boundary_check
    .type seg_boundary_check, @function
seg_boundary_check:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x17    /* mov.l .L_pool_060361AC, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x30, r3
    extu.b r14, r14
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov.b r0, @(4, r2)
    .byte   0xD3, 0x13    /* mov.l .L_pool_060361B0, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
