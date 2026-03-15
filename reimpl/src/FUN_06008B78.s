
    .section .text.FUN_06008B78


    .global FUN_06008B78
    .type FUN_06008B78, @function
FUN_06008B78:
    sts.l pr, @-r15
    mov #0x9, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_06008BBC, r2 */
    mov.l r3, @r2
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06008BC0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06008BC4, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x0E    /* mov.l .L_pool_06008BC8, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0D    /* mov.l .L_pool_06008BCC, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
