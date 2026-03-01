
    .section .text.FUN_06032F62


    .global hud_map_elem_08
    .type hud_map_elem_08, @function
hud_map_elem_08:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x27    /* mov.l .L_pool_06033008, r0 */
    mov.l @(28, r0), r4
    .byte   0xD0, 0x27    /* mov.l .L_pool_0603300C, r0 */
