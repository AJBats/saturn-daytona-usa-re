
    .section .text.FUN_06032EE6


    .global hud_map_elem_01
    .type hud_map_elem_01, @function
hud_map_elem_01:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x45    /* mov.l .L_pool_06033004, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06032FF0, r0 */
    tst r0, r1
    .byte   0x89, 0x24    /* bt 0x06032F42 (external) */
    mov.l r1, @-r15
    .byte   0xD0, 0x3A    /* mov.l .L_pool_06032FE4, r0 */
