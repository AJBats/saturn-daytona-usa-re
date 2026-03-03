
    .section .text.FUN_06008BD8


    .global state_loading_init
    .type state_loading_init, @function
state_loading_init:
    sts.l pr, @-r15
    mov #0xB, r3
    .byte   0xD2, 0x16    /* mov.l .L_pool_06008C38, r2 */
    mov.l r3, @r2
    .byte   0xD3, 0x16    /* mov.l .L_pool_06008C3C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x16    /* mov.l .L_pool_06008C40, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x15    /* mov.l .L_pool_06008C44, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x14    /* mov.l .L_pool_06008C48, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
