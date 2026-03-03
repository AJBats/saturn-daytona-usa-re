
    .section .text.FUN_06032ED8


    .global hud_map_elem_00
    .type hud_map_elem_00, @function
hud_map_elem_00:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x46    /* mov.l .L_pool_06032FFC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x46    /* mov.l .L_pool_06033000, r0 */
