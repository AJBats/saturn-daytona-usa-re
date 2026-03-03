
    .section .text.FUN_06032F20


    .global hud_map_elem_04
    .type hud_map_elem_04, @function
hud_map_elem_04:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x39    /* mov.l .L_pool_06033010, r0 */
