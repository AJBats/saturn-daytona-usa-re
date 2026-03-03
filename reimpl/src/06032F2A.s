
    .section .text.FUN_06032F2A


    .global hud_map_elem_05
    .type hud_map_elem_05, @function
hud_map_elem_05:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x38    /* mov.l .L_pool_06033014, r0 */
