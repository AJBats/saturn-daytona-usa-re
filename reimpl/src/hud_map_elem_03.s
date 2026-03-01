
    .section .text.FUN_06032F12


    .global hud_map_elem_03
    .type hud_map_elem_03, @function
hud_map_elem_03:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3B    /* mov.l .L_pool_06033008, r0 */
    mov.l @(12, r0), r4
    .byte   0xD0, 0x3B    /* mov.l .L_pool_0603300C, r0 */
