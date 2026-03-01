
    .section .text.FUN_06032586


    .global digit_separator
    .type digit_separator, @function
digit_separator:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x0F    /* mov.l .L_pool_060325CC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D0, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D4, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D8, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325DC, r0 */
