
    .section .text.FUN_06032F4C


    .global hud_map_elem_07
    .type hud_map_elem_07, @function
hud_map_elem_07:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x24    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x2B    /* mov.l .L_pool_06033008, r0 */
    mov.l @(16, r0), r4
    mov.l @(20, r0), r5
    mov.l @(24, r0), r6
    .byte   0xD0, 0x25    /* mov.l .L_pool_06032FF8, r0 */
