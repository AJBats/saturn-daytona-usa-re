
    .section .text.FUN_0600F990


    .global transition_small_b
    .type transition_small_b, @function
transition_small_b:
    sts.l pr, @-r15
    .byte   0xDE, 0x1D    /* mov.l .L_pool_0600FA08, r14 */
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0600FA0C, r3 */
    mov.l @r14, r2
    add r3, r2
    mov r2, r5
    mov.l r2, @r14
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600FA10, r3 */
    jsr @r3
    mov #0x10, r4
    .byte   0xD4, 0x1B    /* mov.l .L_pool_0600FA14, r4 */
    .byte   0xD3, 0x1B    /* mov.l .L_pool_0600FA14, r3 */
    mov.w @r4, r4
    add #0x2, r4
    mov.w r4, @r3
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600FA18, r3 */
    jsr @r3
    nop
    mov.l @r14, r0
    tst r0, r0
    bf      .L_0600F9C0
    mov #0x8, r3
    .byte   0xD2, 0x17    /* mov.l .L_pool_0600FA1C, r2 */
    mov.b r3, @r2
.L_0600F9C0:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
