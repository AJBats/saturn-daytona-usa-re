
    .section .text.FUN_06030540


    .global FUN_06030540
    .type FUN_06030540, @function
FUN_06030540:
    mov.l r14, @-r15
    .byte   0xDE, 0x0B    /* mov.l .L_pool_06030570, r14 */
    mov.w r4, @r14
    .byte   0xDE, 0x0B    /* mov.l .L_pool_06030574, r14 */
