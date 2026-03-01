
    .section .text.FUN_0600F898


    .global transition_minimal
    .type transition_minimal, @function
transition_minimal:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_0600F8E8, r3 */
    jsr @r3
    nop
    .byte   0x92, 0x18    /* mov.w .L_wpool_0600F8D4, r2 */
    .byte   0xD3, 0x12    /* mov.l .L_pool_0600F8EC, r3 */
    mov.l r2, @r3
    mov #0x14, r2
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0600F8E0, r3 */
    mov.w r2, @r3
    mov #0x0, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_0600F8F0, r3 */
    mov.w r2, @r3
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0600F8E4, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4
