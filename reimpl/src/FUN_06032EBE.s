
    .section .text.FUN_06032EBE


    .global FUN_06032EBE
    .type FUN_06032EBE, @function
FUN_06032EBE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x48    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FEC, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF0, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF4, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF8, r0 */
