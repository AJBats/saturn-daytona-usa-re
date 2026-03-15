
    .section .text.FUN_06032EFC


    .global FUN_06032EFC
    .type FUN_06032EFC, @function
FUN_06032EFC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x38    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06033008, r0 */
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0, r6
    .byte   0xD0, 0x39    /* mov.l .L_pool_06032FF8, r0 */
