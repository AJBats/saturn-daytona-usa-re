
    .section .text.FUN_060321DC


    .global display_init_helper
    .type display_init_helper, @function
display_init_helper:
    sts.l pr, @-r15
    .byte   0xB5, 0xD7    /* bsr 0x06032D90 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x17    /* mov.l .L_pool_06032244, r1 */
    .byte   0xD0, 0x18    /* mov.l .L_pool_06032248, r0 */
    mov.w r1, @(r0, r14)
    mov.l r7, @-r15
    .byte   0xD4, 0x17    /* mov.l .L_pool_0603224C, r4 */
