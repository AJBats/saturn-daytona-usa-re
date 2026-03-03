
    .section .text.FUN_06008B04


    .global state_course_select_init
    .type state_course_select_init, @function
state_course_select_init:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_06008B54, r3 */
    jsr @r3
    nop
    mov #0x7, r2
    .byte   0xD3, 0x12    /* mov.l .L_pool_06008B58, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x12    /* mov.l .L_pool_06008B5C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_06008B60, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_06008B64, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_06008B68, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06008B6C, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
