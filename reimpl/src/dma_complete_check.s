
    .section .text.FUN_060409C8


    .global dma_complete_check
    .type dma_complete_check, @function
dma_complete_check:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    .byte   0xD6, 0x15    /* mov.l .L_pool_06040A24, r6 */
    .byte   0xD3, 0x15    /* mov.l .L_pool_06040A28, r3 */
    jsr @r3
    mov.l @(4, r4), r4
    add #0x4, r15
    .byte   0xD3, 0x14    /* mov.l .L_pool_06040A2C, r3 */
    jmp @r3
    lds.l @r15+, pr

    .global sym_060409DE
sym_060409DE:
    mov.l @(8, r4), r0
    mov.l @(16, r4), r3
    rts
    add r3, r0
