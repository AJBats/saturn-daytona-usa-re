
    .section .text.FUN_0601AF8C


    .global replay_init_stub
    .type replay_init_stub, @function
replay_init_stub:
    sts.l pr, @-r15
    .byte   0xB0, 0xA3    /* bsr 0x0601B0D8 (external) */
    nop
    mov #0x14, r2
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0601AFC8, r3 */
    mov.b r2, @r3
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0601AFCC, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4
