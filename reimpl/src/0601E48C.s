
    .section .text.FUN_0601E48C


    .global mat_identity_set
    .type mat_identity_set, @function
mat_identity_set:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w r4, @r15
    .byte   0xD3, 0x22    /* mov.l .L_pool_0601E51C, r3 */
    mov.w @r15, r14
    mov.l @r3, r3
    extu.w r14, r14
    mov.l @(4, r3), r2
    shll2 r14
    .byte   0xD3, 0x20    /* mov.l .L_pool_0601E520, r3 */
    shll2 r14
    shll r14
    add r3, r14
    mov.w @(28, r14), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    .byte   0xD0, 0x1B    /* mov.l .L_pool_0601E51C, r0 */
    mov.l @r0, r0
    mov.l @(12, r0), r0
    mov r14, r6
    .byte   0xD5, 0x1B    /* mov.l .L_pool_0601E524, r5 */
    mov.b @r5, r5
    extu.b r5, r5
    shll2 r5
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0601E528, r3 */
    add r3, r5
    mov.l @r5, r5
    mov #0x1C, r4
    add r14, r4
    mov.w @r4, r4
    extu.w r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    jmp @r0
    mov.l @r15+, r14
