
    .section .text.FUN_06032F70


    .global hud_map_elem_09
    .type hud_map_elem_09, @function
hud_map_elem_09:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x25    /* mov.l .L_pool_06033010, r0 */
