
    .section .text.FUN_06032A14


    .global speed_unit_select
    .type speed_unit_select, @function
speed_unit_select:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x2F    /* mov.l .L_pool_06032ADC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032A90, r0 */
