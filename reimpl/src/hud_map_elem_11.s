
    .section .text.FUN_06032F84


    .global hud_map_elem_11
    .type hud_map_elem_11, @function
hud_map_elem_11:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x16    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    mov.l @r15+, r1
    .byte   0xD0, 0x21    /* mov.l .L_pool_06033018, r0 */
    tst r0, r1
    .byte   0x89, 0x1C    /* bt 0x06032FD2 (external) */
    .byte   0xD0, 0x12    /* mov.l .L_pool_06032FE4, r0 */
